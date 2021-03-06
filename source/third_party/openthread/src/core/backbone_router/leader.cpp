/*
 *  Copyright (c) 2019, The OpenThread Authors.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  3. Neither the name of the copyright holder nor the
 *     names of its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file
 *   This file implements Primary Backbone Router service management in the Thread Network.
 */

#include "leader.hpp"

#if (OPENTHREAD_CONFIG_THREAD_VERSION >= OT_THREAD_VERSION_1_2)

#include "common/instance.hpp"
#include "common/locator-getters.hpp"
#include "common/logging.hpp"

namespace ot {
namespace BackboneRouter {

Leader::Leader(Instance &aInstance)
    : InstanceLocator(aInstance)
{
    Reset();
}

void Leader::Reset(void)
{
    // Invalid server short address indicates no available Backbone Router service in the Thread Network.
    mConfig.mServer16 = Mac::kShortAddrInvalid;

    // Domain Prefix Length 0 indicates no available Domain Prefix in the Thread network.
    mDomainPrefix.mLength = 0;
}

otError Leader::GetConfig(BackboneRouterConfig &aConfig) const
{
    otError error = OT_ERROR_NONE;

    VerifyOrExit(HasPrimary(), error = OT_ERROR_NOT_FOUND);

    aConfig = mConfig;

exit:
    return error;
}

otError Leader::GetServiceId(uint8_t &aServiceId) const
{
    otError error       = OT_ERROR_NONE;
    uint8_t serviceData = NetworkData::ServiceTlv::kServiceDataBackboneRouter;

    VerifyOrExit(HasPrimary(), error = OT_ERROR_NOT_FOUND);

    error = Get<NetworkData::Leader>().GetServiceId(NetworkData::ServiceTlv::kThreadEnterpriseNumber, &serviceData,
                                                    sizeof(serviceData), true, aServiceId);

exit:
    return error;
}

#if (OPENTHREAD_CONFIG_LOG_LEVEL >= OT_LOG_LEVEL_INFO) && (OPENTHREAD_CONFIG_LOG_BBR == 1)
void Leader::LogBackboneRouterPrimary(State aState, const BackboneRouterConfig &aConfig) const
{
    OT_UNUSED_VARIABLE(aConfig);

    otLogInfoBbr("PBBR state: %s", StateToString(aState));

    if (aState != kStateRemoved && aState != kStateNone)
    {
        otLogInfoBbr("Rloc16: 0x%4X, seqno: %d, delay: %d, timeout %d", aConfig.mServer16, aConfig.mSequenceNumber,
                     aConfig.mReregistrationDelay, aConfig.mMlrTimeout);
    }
}

void Leader::LogDomainPrefix(DomainPrefixState aState, const otIp6Prefix &aPrefix) const
{
    otLogInfoBbr("Domain Prefix: %s/%d, state: %s",
                 aPrefix.mLength == 0 ? ""
                                      : static_cast<const Ip6::Address *>(&aPrefix.mPrefix)->ToString().AsCString(),
                 aPrefix.mLength, DomainPrefixStateToString(aState));
}

const char *Leader::StateToString(State aState)
{
    const char *logString = "Unknown";

    switch (aState)
    {
    case kStateNone:
        logString = "None";
        break;

    case kStateAdded:
        logString = "Added";
        break;

    case kStateRemoved:
        logString = "Removed";
        break;

    case kStateToTriggerRereg:
        logString = "Rereg triggered";
        break;

    case kStateRefreshed:
        logString = "Refreshed";
        break;

    case kStateUnchanged:
        logString = "Unchanged";
        break;

    default:
        break;
    }

    return logString;
}

const char *Leader::DomainPrefixStateToString(DomainPrefixState aState)
{
    const char *logString = "Unknown";

    switch (aState)
    {
    case kDomainPrefixNone:
        logString = "None";
        break;

    case kDomainPrefixAdded:
        logString = "Added";
        break;

    case kDomainPrefixRemoved:
        logString = "Removed";
        break;

    case kDomainPrefixRefreshed:
        logString = "Refreshed";
        break;

    case kDomainPrefixUnchanged:
        logString = "Unchanged";
        break;
    }

    return logString;
}
#endif

void Leader::Update(void)
{
    UpdateBackboneRouterPrimary();
    UpdateDomainPrefixConfig();
}

void Leader::UpdateBackboneRouterPrimary(void)
{
    BackboneRouterConfig config;
    State                state;

    Get<NetworkData::Leader>().GetBackboneRouterPrimary(config);

    if (config.mServer16 != mConfig.mServer16)
    {
        if (config.mServer16 == Mac::kShortAddrInvalid)
        {
            state = kStateRemoved;
        }
        else if (mConfig.mServer16 == Mac::kShortAddrInvalid)
        {
            state = kStateAdded;
        }
        else
        {
            // Short Address of PBBR changes.
            state = kStateToTriggerRereg;
        }
    }
    else if (config.mServer16 == Mac::kShortAddrInvalid)
    {
        // If no Primary all the time.
        state = kStateNone;
    }
    else if (config.mSequenceNumber != mConfig.mSequenceNumber)
    {
        state = kStateToTriggerRereg;
    }
    else if (config.mReregistrationDelay != mConfig.mReregistrationDelay || config.mMlrTimeout != mConfig.mMlrTimeout)
    {
        state = kStateRefreshed;
    }
    else
    {
        state = kStateUnchanged;
    }

    mConfig = config;
    LogBackboneRouterPrimary(state, mConfig);

#if OPENTHREAD_FTD && OPENTHREAD_CONFIG_BACKBONE_ROUTER_ENABLE
    Get<BackboneRouter::Local>().UpdateBackboneRouterPrimary(state, mConfig);
#endif
}

void Leader::UpdateDomainPrefixConfig(void)
{
    NetworkData::Iterator           iterator = NetworkData::kIteratorInit;
    NetworkData::OnMeshPrefixConfig config;
    DomainPrefixState               state;
    bool                            found = false;

    while (Get<NetworkData::Leader>().GetNextOnMeshPrefix(iterator, config) == OT_ERROR_NONE)
    {
        if (config.mDp)
        {
            found = true;
            break;
        }
    }

    if (!found)
    {
        if (mDomainPrefix.mLength != 0)
        {
            // Domain Prefix does not exist any more.
            mDomainPrefix.mLength = 0;
            state                 = kDomainPrefixRemoved;
        }
        else
        {
            state = kDomainPrefixNone;
        }
    }
    else if (config.mPrefix.mLength == mDomainPrefix.mLength &&
             Ip6::Address::PrefixMatch(mDomainPrefix.mPrefix.mFields.m8, config.mPrefix.mPrefix.mFields.m8,
                                       BitVectorBytes(mDomainPrefix.mLength)) >= mDomainPrefix.mLength)
    {
        state = kDomainPrefixUnchanged;
    }
    else
    {
        if (mDomainPrefix.mLength == 0)
        {
            state = kDomainPrefixAdded;
        }
        else
        {
            state = kDomainPrefixRefreshed;
        }

        mDomainPrefix = config.mPrefix;
    }

    LogDomainPrefix(state, mDomainPrefix);

#if OPENTHREAD_FTD && OPENTHREAD_CONFIG_BACKBONE_ROUTER_ENABLE
    Get<Local>().UpdateAllDomainBackboneRouters(state);
#endif

#if OPENTHREAD_CONFIG_DUA_ENABLE
    Get<DuaManager>().UpdateDomainUnicastAddress(state);
#endif
}

} // namespace BackboneRouter
} // namespace ot

#endif // (OPENTHREAD_CONFIG_THREAD_VERSION >= OT_THREAD_VERSION_1_2)

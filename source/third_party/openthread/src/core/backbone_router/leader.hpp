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
 *   This file includes definitions for Primary Backbone Router service management in the Thread Network.
 */

#ifndef BACKBONE_ROUTER_LEADER_HPP_
#define BACKBONE_ROUTER_LEADER_HPP_

#include "openthread-core-config.h"

#if (OPENTHREAD_CONFIG_THREAD_VERSION >= OT_THREAD_VERSION_1_2)
#include <openthread/backbone_router.h>
#include <openthread/ip6.h>

#include "common/locator.hpp"
#include "net/ip6_address.hpp"

namespace ot {

namespace BackboneRouter {

typedef otBackboneRouterConfig BackboneRouterConfig;

/**
 * This class implements the basic Primary Backbone Router service operations.
 *
 */
class Leader : public InstanceLocator
{
public:
    // Primary Backbone Router Service state or state change.
    enum State
    {
        kStateNone = 0,       ///< Not exist (trigger Backbone Router register its service).
        kStateAdded,          ///< Newly added.
        kStateRemoved,        ///< Newly removed (trigger Backbone Router register its service).
        kStateToTriggerRereg, ///< Short address or sequence number changes (trigger re-registration).
                              ///< May also have ReregistrationDelay or MlrTimeout update.
        kStateRefreshed,      ///< Only ReregistrationDelay or MlrTimeout changes.
        kStateUnchanged,      ///< No change on Primary Backbone Router information (only for logging).
    };

    // Domain Prefix state or state change.
    enum DomainPrefixState
    {
        kDomainPrefixNone = 0,  ///< Not available.
        kDomainPrefixAdded,     ///< Added.
        kDomainPrefixRemoved,   ///< Removed.
        kDomainPrefixRefreshed, ///< Changed.
        kDomainPrefixUnchanged, ///< Nothing changed.
    };

    /**
     * This constructor initializes the `Leader`.
     *
     * @param[in] aInstance  A reference to the OpenThread instance.
     *
     */
    explicit Leader(Instance &aInstance);

    /**
     * This method resets the cached Primary Backbone Router.
     *
     */
    void Reset(void);

    /**
     * This method updates the cached Primary Backbone Router if any when new network data is available.
     *
     */
    void Update(void);

    /**
     * This method gets the Primary Backbone Router in the Thread Network.
     *
     * @param[out]  aConfig        The Primary Backbone Router information.
     *
     * @retval OT_ERROR_NONE       Successfully got the Primary Backbone Router information.
     * @retval OT_ERROR_NOT_FOUND  No Backbone Router in the Thread Network.
     *
     */
    otError GetConfig(BackboneRouterConfig &aConfig) const;

    /**
     * This method gets the Backbone Router Service ID.
     *
     * @param[out]  aServiceId     The reference whether to put the Backbone Router Service ID.
     *
     * @retval OT_ERROR_NONE       Successfully got the Backbone Router Service ID.
     * @retval OT_ERROR_NOT_FOUND  Backbone Router service doesn't exist.
     *
     */
    otError GetServiceId(uint8_t &aServiceId) const;

    /**
     * This method gets the short address of the Primary Backbone Router.
     *
     * @returns short address of Primary Backbone Router, or Mac::kShortAddrInvalid if no Primary Backbone Router.
     *
     */
    uint16_t GetServer16(void) const { return mConfig.mServer16; }

    /**
     * This method indicates whether or not there is Primary Backbone Router.
     *
     * @retval TRUE if there is Primary Backbone Router, FALSE otherwise.
     *
     */
    bool HasPrimary(void) const { return mConfig.mServer16 != Mac::kShortAddrInvalid; }

    /**
     * This method gets the Domain Prefix in the Thread Network.
     *
     * @retval A pointer to the Domain Prefix or NULL if there is no Domain Prefix.
     *
     */
    const otIp6Prefix *GetDomainPrefix(void) const { return (mDomainPrefix.mLength == 0) ? NULL : &mDomainPrefix; }

    /**
     * This method indicates whether or not the Domain Prefix is available in the Thread Network.
     *
     * @retval TRUE if there is Domain Prefix, FALSE otherwise.
     *
     */
    bool HasDomainPrefix(void) const { return (mDomainPrefix.mLength > 0); }

private:
    void UpdateBackboneRouterPrimary(void);
    void UpdateDomainPrefixConfig(void);
#if (OPENTHREAD_CONFIG_LOG_LEVEL >= OT_LOG_LEVEL_INFO) && (OPENTHREAD_CONFIG_LOG_BBR == 1)
    void               LogBackboneRouterPrimary(State aState, const BackboneRouterConfig &aConfig) const;
    void               LogDomainPrefix(DomainPrefixState aState, const otIp6Prefix &aPrefix) const;
    static const char *StateToString(State aState);
    static const char *DomainPrefixStateToString(DomainPrefixState aState);
#else
    void LogBackboneRouterPrimary(State, const BackboneRouterConfig &) const {}
    void LogDomainPrefix(DomainPrefixState, const otIp6Prefix &) const {}
#endif

    BackboneRouterConfig mConfig;       ///< Primary Backbone Router information.
    otIp6Prefix          mDomainPrefix; ///< Domain Prefix on the Thread Network.
};

} // namespace BackboneRouter

/**
 * @}
 */

} // namespace ot

#endif // (OPENTHREAD_CONFIG_THREAD_VERSION >= OT_THREAD_VERSION_1_2)

#endif // BACKBONE_ROUTER_LEADER_HPP_

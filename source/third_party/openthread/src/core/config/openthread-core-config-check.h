/*
 *  Copyright (c) 2018, The OpenThread Authors.
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
 *   Checking for configuration options. Removed or replaced OPENTHREAD_CONFIG options.
 *
 * The checks below verify that none of the older configuration definition are
 * still defined and being used. The list below is not necessarily complete and
 * the error message is only intended to give a hint of what the possible new
 * configuration name may be. Please check the documentation of the new
 * configuration parameter for details about behavior of each option before use.
 *
 */

#ifndef OPENTHREAD_CORE_CONFIG_CHECK_H_
#define OPENTHREAD_CORE_CONFIG_CHECK_H_

#if defined(OPENTHREAD_CONFIG_DISABLE_CCA_ON_LAST_ATTEMPT) ||     \
    defined(OPENTHREAD_CONFIG_DISABLE_CSMA_CA_ON_LAST_ATTEMPT) || \
    defined(OPENTHREAD_CONFIG_MAC_DISABLE_CSMA_CA_ON_LAST_ATTEMPT)
#error \
    "OPENTHREAD_CONFIG_DISABLE_CCA_ON_LAST_ATTEMPT, OPENTHREAD_CONFIG_DISABLE_CSMA_CA_ON_LAST_ATTEMPT and OPENTHREAD_CONFIG_MAC_DISABLE_CSMA_CA_ON_LAST_ATTEMPT were removed."
#endif

#ifdef OPENTHREAD_CONFIG_MAX_TX_ATTEMPTS_DIRECT
#error "OPENTHREAD_CONFIG_MAX_TX_ATTEMPTS_DIRECT was replaced by OPENTHREAD_CONFIG_MAC_MAX_FRAME_RETRIES_DIRECT."
#endif

#ifdef OPENTHREAD_CONFIG_MAX_TX_ATTEMPTS_INDIRECT_PER_POLL
#error \
    "OPENTHREAD_CONFIG_MAX_TX_ATTEMPTS_INDIRECT_PER_POLL was replaced by OPENTHREAD_CONFIG_MAC_MAX_FRAME_RETRIES_INDIRECT."
#endif

#ifdef OPENTHREAD_CONFIG_MAX_SERVER_ALOCS
#error "OPENTHREAD_CONFIG_MAX_SERVER_ALOCS was replaced by OPENTHREAD_CONFIG_TMF_NETDATA_SERVICE_MAX_ALOCS."
#endif

#ifdef OPENTHREAD_CONFIG_ENABLE_AUTO_START_SUPPORT
#error "OPENTHREAD_CONFIG_ENABLE_AUTO_START_SUPPORT was removed."
#endif

#ifdef OPENTHREAD_ENABLE_CERT_LOG
#error "OPENTHREAD_ENABLE_CERT_LOG was replaced by OPENTHREAD_CONFIG_REFERENCE_DEVICE_ENABLE."
#endif

#ifdef OPENTHREAD_ENABLE_MULTIPLE_INSTANCES
#error "OPENTHREAD_ENABLE_MULTIPLE_INSTANCES was replaced by OPENTHREAD_CONFIG_MULTIPLE_INSTANCE_ENABLE."
#endif

#ifdef OPENTHREAD_CONFIG_NCP_UART_ENABLE
#error "OPENTHREAD_CONFIG_NCP_UART_ENABLE was replaced by OPENTHREAD_CONFIG_NCP_HDLC_ENABLE."
#endif

#ifdef OPENTHREAD_ENABLE_NCP_UART
#error "OPENTHREAD_ENABLE_NCP_UART was replaced by OPENTHREAD_CONFIG_NCP_HDLC_ENABLE."
#endif

#ifdef OPENTHREAD_ENABLE_NCP_SPI
#error "OPENTHREAD_ENABLE_NCP_SPI was replaced by OPENTHREAD_CONFIG_NCP_SPI_ENABLE."
#endif

#ifdef OPENTHREAD_ENABLE_UDP_FORWARD
#error "OPENTHREAD_ENABLE_UDP_FORWARD was replaced by OPENTHREAD_CONFIG_UDP_FORWARD_ENABLE."
#endif

#ifdef OPENTHREAD_ENABLE_BORDER_AGENT
#error "OPENTHREAD_ENABLE_BORDER_AGENT was replaced by OPENTHREAD_CONFIG_BORDER_AGENT_ENABLE."
#endif

#ifdef OPENTHREAD_ENABLE_MTD_NETWORK_DIAGNOSTIC
#error "OPENTHREAD_ENABLE_MTD_NETWORK_DIAGNOSTIC was replaces by OPENTHREAD_CONFIG_TMF_NETWORK_DIAG_MTD_ENABLE."
#endif

#ifdef OPENTHREAD_ENABLE_APPLICATION_COAP_SECURE
#error "OPENTHREAD_ENABLE_APPLICATION_COAP_SECURE was replaced by OPENTHREAD_CONFIG_COAP_SECURE_API_ENABLE."
#endif

#ifdef OPENTHREAD_ENABLE_PLATFORM_UDP
#error "OPENTHREAD_ENABLE_PLATFORM_UDP was replaced by OPENTHREAD_CONFIG_PLATFORM_UDP_ENABLE."
#endif

#ifdef OPENTHREAD_ENABLE_PLATFORM_NETIF
#error "OPENTHREAD_ENABLE_PLATFORM_NETIF was replaced by OPENTHREAD_CONFIG_PLATFORM_NETIF_ENABLE."
#endif

#ifdef OPENTHREAD_ENABLE_COMMISSIONER
#error "OPENTHREAD_ENABLE_COMMISSIONER was replaced by OPENTHREAD_CONFIG_COMMISSIONER_ENABLE."
#endif

#ifdef OPENTHREAD_ENABLE_JOINER
#error "OPENTHREAD_ENABLE_JOINER was replaced by OPENTHREAD_CONFIG_JOINER_ENABLE."
#endif

#ifdef OPENTHREAD_ENABLE_DTLS
#error "OPENTHREAD_ENABLE_DTLS was replaced by OPENTHREAD_CONFIG_DTLS_ENABLE."
#endif

#ifdef OPENTHREAD_ENABLE_JAM_DETECTION
#error "OPENTHREAD_ENABLE_JAM_DETECTION was replaced by OPENTHREAD_CONFIG_JAM_DETECTION_ENABLE."
#endif

#ifdef OPENTHREAD_ENABLE_CHANNEL_MONITOR
#error "OPENTHREAD_ENABLE_CHANNEL_MONITOR was replaced by OPENTHREAD_CONFIG_CHANNEL_MONITOR_ENABLE."
#endif

#ifdef OPENTHREAD_ENABLE_CHANNEL_MANAGER
#error "OPENTHREAD_ENABLE_CHANNEL_MANAGER was replaced by OPENTHREAD_CONFIG_CHANNEL_MANAGER_ENABLE."
#endif

#ifdef OPENTHREAD_ENABLE_MAC_FILTER
#error "OPENTHREAD_ENABLE_MAC_FILTER was replaced by OPENTHREAD_CONFIG_MAC_FILTER_ENABLE."
#endif

#ifdef OPENTHREAD_ENABLE_DIAG
#error "OPENTHREAD_ENABLE_DIAG was replaced by OPENTHREAD_CONFIG_DIAG_ENABLE."
#endif

#ifdef OPENTHREAD_ENABLE_LEGACY
#error "OPENTHREAD_ENABLE_LEGACY was replaced by OPENTHREAD_CONFIG_LEGACY_ENABLE."
#endif

#ifdef OPENTHREAD_ENABLE_CHILD_SUPERVISION
#error "OPENTHREAD_ENABLE_CHILD_SUPERVISION was replaced by OPENTHREAD_CONFIG_CHILD_SUPERVISION_ENABLE."
#endif

#ifdef OPENTHREAD_ENABLE_DHCP6_SERVER
#error "OPENTHREAD_ENABLE_DHCP6_SERVER was replaced by OPENTHREAD_CONFIG_DHCP6_SERVER_ENABLE."
#endif

#ifdef OPENTHREAD_ENABLE_DNS_CLIENT
#error "OPENTHREAD_ENABLE_DNS_CLIENT was replaced by OPENTHREAD_CONFIG_DNS_CLIENT_ENABLE."
#endif

#ifdef OPENTHREAD_ENABLE_SNTP_CLIENT
#error "OPENTHREAD_ENABLE_SNTP_CLIENT was replaced by OPENTHREAD_CONFIG_SNTP_CLIENT_ENABLE."
#endif

#ifdef OPENTHREAD_ENABLE_APPLICATION_COAP
#error "OPENTHREAD_ENABLE_APPLICATION_COAP was replaced by OPENTHREAD_CONFIG_COAP_API_ENABLE."
#endif

#ifdef OPENTHREAD_ENABLE_RAW_LINK_API
#error "OPENTHREAD_ENABLE_RAW_LINK_API was replaced by OPENTHREAD_CONFIG_LINK_RAW_ENABLE."
#endif

#ifdef OPENTHREAD_ENABLE_BORDER_ROUTER
#error "OPENTHREAD_ENABLE_BORDER_ROUTER was replaced by OPENTHREAD_CONFIG_BORDER_ROUTER_ENABLE."
#endif

#ifdef OPENTHREAD_ENABLE_SERVICE
#error "OPENTHREAD_ENABLE_SERVICE was replaced by OPENTHREAD_CONFIG_TMF_NETDATA_SERVICE_ENABLE."
#endif

#ifdef OPENTHREAD_ENABLE_ECDSA
#error "OPENTHREAD_ENABLE_ECDSA was replaced by OPENTHREAD_CONFIG_ECDSA_ENABLE."
#endif

#ifdef OPENTHREAD_CONFIG_ENABLE_TIME_SYNC
#error "OPENTHREAD_CONFIG_ENABLE_TIME_SYNC was replaced by OPENTHREAD_CONFIG_TIME_SYNC_ENABLE."
#endif

#ifdef OPENTHREAD_ENABLE_REFERENCE_DEVICE
#error "OPENTHREAD_ENABLE_REFERENCE_DEVICE was replaced by OPENTHREAD_CONFIG_REFERENCE_DEVICE_ENABLE."
#endif

#ifdef OPENTHREAD_ENABLE_DHCP6_CLIENT
#error "OPENTHREAD_ENABLE_DHCP6_CLIENT was replaced by OPENTHREAD_CONFIG_DHCP6_CLIENT_ENABLE."
#endif

#ifdef OPENTHREAD_ENABLE_SPINEL_VENDOR_SUPPORT
#error "OPENTHREAD_ENABLE_SPINEL_VENDOR_SUPPORT was replaced by OPENTHREAD_ENABLE_NCP_VENDOR_HOOK."
#endif

#ifdef OPENTHREAD_CONFIG_MAX_TX_ATTEMPTS_INDIRECT_POLLS
#error \
    "OPENTHREAD_CONFIG_MAX_TX_ATTEMPTS_INDIRECT_POLLS was replaced by OPENTHREAD_CONFIG_MAC_MAX_TX_ATTEMPTS_INDIRECT_POLLS."
#endif

#ifdef OPENTHREAD_CONFIG_TX_NUM_BCAST
#error "OPENTHREAD_CONFIG_TX_NUM_BCAST was replaced by OPENTHREAD_CONFIG_MAC_TX_NUM_BCAST."
#endif

#ifdef OPENTHREAD_CONFIG_ATTACH_DATA_POLL_PERIOD
#error "OPENTHREAD_CONFIG_ATTACH_DATA_POLL_PERIOD was replaced by OPENTHREAD_CONFIG_MAC_ATTACH_DATA_POLL_PERIOD."
#endif

#ifdef OPENTHREAD_CONFIG_ADDRESS_CACHE_ENTRIES
#error "OPENTHREAD_CONFIG_ADDRESS_CACHE_ENTRIES was replaced by OPENTHREAD_CONFIG_TMF_ADDRESS_CACHE_ENTRIES."
#endif

#ifdef OPENTHREAD_CONFIG_ADDRESS_QUERY_TIMEOUT
#error "OPENTHREAD_CONFIG_ADDRESS_QUERY_TIMEOUT was replaced by OPENTHREAD_CONFIG_TMF_ADDRESS_QUERY_TIMEOUT."
#endif

#ifdef OPENTHREAD_CONFIG_ADDRESS_QUERY_INITIAL_RETRY_DELAY
#error \
    "OPENTHREAD_CONFIG_ADDRESS_QUERY_INITIAL_RETRY_DELAY was replaced by OPENTHREAD_CONFIG_TMF_ADDRESS_QUERY_INITIAL_RETRY_DELAY."
#endif

#ifdef OPENTHREAD_CONFIG_ADDRESS_QUERY_MAX_RETRY_DELAY
#error \
    "OPENTHREAD_CONFIG_ADDRESS_QUERY_MAX_RETRY_DELAY was replaced by OPENTHREAD_CONFIG_TMF_ADDRESS_QUERY_MAX_RETRY_DELAY."
#endif

#ifdef OPENTHREAD_CONFIG_MAX_ROUTERS
#error "OPENTHREAD_CONFIG_MAX_ROUTERS was replaced by OPENTHREAD_CONFIG_MLE_MAX_ROUTERS."
#endif

#ifdef OPENTHREAD_CONFIG_MAX_CHILDREN
#error "OPENTHREAD_CONFIG_MAX_CHILDREN was replaced by OPENTHREAD_CONFIG_MLE_MAX_CHILDREN."
#endif

#ifdef OPENTHREAD_CONFIG_DEFAULT_CHILD_TIMEOUT
#error "OPENTHREAD_CONFIG_DEFAULT_CHILD_TIMEOUT was replaced by OPENTHREAD_CONFIG_MLE_CHILD_TIMEOUT_DEFAULT."
#endif

#ifdef OPENTHREAD_CONFIG_IP_ADDRS_PER_CHILD
#error "OPENTHREAD_CONFIG_IP_ADDRS_PER_CHILD was replaced by OPENTHREAD_CONFIG_MLE_IP_ADDRS_PER_CHILD."
#endif

#ifdef OPENTHREAD_CONFIG_IP_ADDRS_TO_REGISTER
#error "OPENTHREAD_CONFIG_IP_ADDRS_TO_REGISTER was replaced by OPENTHREAD_CONFIG_MLE_IP_ADDRS_TO_REGISTER."
#endif

#ifdef OPENTHREAD_CONFIG_MAX_EXT_IP_ADDRS
#error "OPENTHREAD_CONFIG_MAX_EXT_IP_ADDRS was replaced by OPENTHREAD_CONFIG_IP6_MAX_EXT_UCAST_ADDRS."
#endif

#ifdef OPENTHREAD_CONFIG_MAX_EXT_MULTICAST_IP_ADDRS
#error "OPENTHREAD_CONFIG_MAX_EXT_MULTICAST_IP_ADDRS was replaced by OPENTHREAD_CONFIG_IP6_MAX_EXT_MCAST_ADDRS."
#endif

#ifdef OPENTHREAD_CONFIG_MAX_SERVICE_ALOCS
#error "OPENTHREAD_CONFIG_MAX_SERVICE_ALOCS was replaced by OPENTHREAD_CONFIG_TMF_NETDATA_SERVICE_MAX_ALOCS."
#endif

#ifdef OPENTHREAD_CONFIG_MAX_ENERGY_RESULTS
#error "OPENTHREAD_CONFIG_MAX_ENERGY_RESULTS was replaced by OPENTHREAD_CONFIG_TMF_ENERGY_SCAN_MAX_RESULTS."
#endif

#ifdef OPENTHREAD_CONFIG_MAX_JOINER_ROUTER_ENTRIES
#error "OPENTHREAD_CONFIG_MAX_JOINER_ROUTER_ENTRIES was replaced by OPENTHREAD_CONFIG_JOINER_MAX_CANDIDATES."
#endif

#ifdef OPENTHREAD_CONFIG_SNTP_RESPONSE_TIMEOUT
#error "OPENTHREAD_CONFIG_SNTP_RESPONSE_TIMEOUT was replaced by OPENTHREAD_CONFIG_SNTP_CLIENT_RESPONSE_TIMEOUT."
#endif

#ifdef OPENTHREAD_CONFIG_SNTP_MAX_RETRANSMIT
#error "OPENTHREAD_CONFIG_SNTP_MAX_RETRANSMIT was replaced by OPENTHREAD_CONFIG_SNTP_CLIENT_MAX_RETRANSMIT."
#endif

#ifdef OPENTHREAD_CONFIG_JOIN_BEACON_VERSION
#error "OPENTHREAD_CONFIG_JOIN_BEACON_VERSION was replaced by OPENTHREAD_CONFIG_MAC_JOIN_BEACON_VERSION."
#endif

#ifdef OPENTHREAD_CONFIG_MESHCOP_PENDING_DATASET_MINIMUM_DELAY
#error \
    "OPENTHREAD_CONFIG_MESHCOP_PENDING_DATASET_MINIMUM_DELAY was replaced by OPENTHREAD_CONFIG_TMF_PENDING_DATASET_MINIMUM_DELAY."
#endif

#ifdef OPENTHREAD_CONFIG_MESHCOP_PENDING_DATASET_DEFAULT_DELAY
#error \
    "OPENTHREAD_CONFIG_MESHCOP_PENDING_DATASET_DEFAULT_DELAY was replaced by OPENTHREAD_CONFIG_TMF_PENDING_DATASET_DEFAULT_DELAY."
#endif

#ifdef OPENTHREAD_CONFIG_ENABLE_SLAAC
#error "OPENTHREAD_CONFIG_ENABLE_SLAAC was replaced by OPENTHREAD_CONFIG_IP6_SLAAC_ENABLE."
#endif

#ifdef OPENTHREAD_CONFIG_NUM_SLAAC_ADDRESSES
#error "OPENTHREAD_CONFIG_NUM_SLAAC_ADDRESSES was replaced by OPENTHREAD_CONFIG_IP6_SLAAC_NUM_ADDRESSES."
#endif

#ifdef OPENTHREAD_CONFIG_ENABLE_SOFTWARE_ACK_TIMEOUT
#error \
    "OPENTHREAD_CONFIG_ENABLE_SOFTWARE_ACK_TIMEOUT was replaced by OPENTHREAD_CONFIG_MAC_SOFTWARE_ACK_TIMEOUT_ENABLE."
#endif

#ifdef OPENTHREAD_CONFIG_SOFTWARE_ACK_TIMEOUT_ENABLE
#error \
    "OPENTHREAD_CONFIG_SOFTWARE_ACK_TIMEOUT_ENABLE was replaced by OPENTHREAD_CONFIG_MAC_SOFTWARE_ACK_TIMEOUT_ENABLE."
#endif

#ifdef OPENTHREAD_CONFIG_ENABLE_SOFTWARE_RETRANSMIT
#error "OPENTHREAD_CONFIG_ENABLE_SOFTWARE_RETRANSMIT was replaced by OPENTHREAD_CONFIG_MAC_SOFTWARE_RETRANSMIT_ENABLE."
#endif

#ifdef OPENTHREAD_CONFIG_SOFTWARE_RETRANSMIT_ENABLE
#error "OPENTHREAD_CONFIG_SOFTWARE_RETRANSMIT_ENABLE was replaced by OPENTHREAD_CONFIG_MAC_SOFTWARE_RETRANSMIT_ENABLE."
#endif

#ifdef OPENTHREAD_CONFIG_ENABLE_SOFTWARE_CSMA_BACKOFF
#error \
    "OPENTHREAD_CONFIG_ENABLE_SOFTWARE_CSMA_BACKOFF was replaced by OPENTHREAD_CONFIG_MAC_SOFTWARE_CSMA_BACKOFF_ENABLE."
#endif

#ifdef OPENTHREAD_CONFIG_SOFTWARE_CSMA_BACKOFF_ENABLE
#error \
    "OPENTHREAD_CONFIG_SOFTWARE_CSMA_BACKOFF_ENABLE was replaced by OPENTHREAD_CONFIG_MAC_SOFTWARE_CSMA_BACKOFF_ENABLE."
#endif

#ifdef OPENTHREAD_CONFIG_ENABLE_SOFTWARE_ENERGY_SCAN
#error \
    "OPENTHREAD_CONFIG_ENABLE_SOFTWARE_ENERGY_SCAN was replaced by OPENTHREAD_CONFIG_MAC_SOFTWARE_ENERGY_SCAN_ENABLE."
#endif

#ifdef OPENTHREAD_CONFIG_SOFTWARE_ENERGY_SCAN_ENABLE
#error \
    "OPENTHREAD_CONFIG_SOFTWARE_ENERGY_SCAN_ENABLE was replaced by OPENTHREAD_CONFIG_MAC_SOFTWARE_ENERGY_SCAN_ENABLE."
#endif

#ifdef OPENTHREAD_CONFIG_ENABLE_PLATFORM_USEC_TIMER
#error "OPENTHREAD_CONFIG_ENABLE_PLATFORM_USEC_TIMER was replaced by OPENTHREAD_CONFIG_PLATFORM_USEC_TIMER_ENABLE."
#endif

#ifdef OPENTHREAD_CONFIG_ENABLE_BEACON_RSP_WHEN_JOINABLE
#error \
    "OPENTHREAD_CONFIG_ENABLE_BEACON_RSP_WHEN_JOINABLE was replaced by OPENTHREAD_CONFIG_MAC_BEACON_RSP_WHEN_JOINABLE_ENABLE."
#endif

#ifdef OPENTHREAD_CONFIG_ENABLE_STEERING_DATA_SET_OOB
#error \
    "OPENTHREAD_CONFIG_ENABLE_STEERING_DATA_SET_OOB was replaced by OPENTHREAD_CONFIG_MLE_STEERING_DATA_SET_OOB_ENABLE."
#endif

#ifdef OPENTHREAD_CONFIG_SUPERVISION_CHECK_TIMEOUT
#error "OPENTHREAD_CONFIG_SUPERVISION_CHECK_TIMEOUT was replaced by OPENTHREAD_CONFIG_CHILD_SUPERVISION_CHECK_TIMEOUT."
#endif

#ifdef OPENTHREAD_CONFIG_SUPERVISION_MSG_NO_ACK_REQUEST
#error \
    "OPENTHREAD_CONFIG_SUPERVISION_MSG_NO_ACK_REQUEST was replaced by OPENTHREAD_CONFIG_CHILD_SUPERVISION_MSG_NO_ACK_REQUEST."
#endif

#ifdef OPENTHREAD_CONFIG_ENABLE_PERIODIC_PARENT_SEARCH
#error "OPENTHREAD_CONFIG_ENABLE_PERIODIC_PARENT_SEARCH was replaced by OPENTHREAD_CONFIG_PARENT_SEARCH_ENABLE."
#endif

#ifdef OPENTHREAD_CONFIG_ENABLE_ATTACH_BACKOFF
#error "OPENTHREAD_CONFIG_ENABLE_ATTACH_BACKOFF was replaced by OPENTHREAD_CONFIG_MLE_ATTACH_BACKOFF_ENABLE."
#endif

#ifdef OPENTHREAD_CONFIG_ATTACH_BACKOFF_MINIMUM_INTERVAL
#error \
    "OPENTHREAD_CONFIG_ATTACH_BACKOFF_MINIMUM_INTERVAL was replaced by OPENTHREAD_CONFIG_MLE_ATTACH_BACKOFF_MINIMUM_INTERVAL."
#endif

#ifdef OPENTHREAD_CONFIG_ATTACH_BACKOFF_MAXIMUM_INTERVAL
#error \
    "OPENTHREAD_CONFIG_ATTACH_BACKOFF_MAXIMUM_INTERVAL was replaced by OPENTHREAD_CONFIG_MLE_ATTACH_BACKOFF_MAXIMUM_INTERVAL."
#endif

#ifdef OPENTHREAD_CONFIG_ATTACH_BACKOFF_JITTER_INTERVAL
#error \
    "OPENTHREAD_CONFIG_ATTACH_BACKOFF_JITTER_INTERVAL was replaced by OPENTHREAD_CONFIG_MLE_ATTACH_BACKOFF_JITTER_INTERVAL."
#endif

#ifdef OPENTHREAD_CONFIG_SEND_UNICAST_ANNOUNCE_RESPONSE
#error \
    "OPENTHREAD_CONFIG_SEND_UNICAST_ANNOUNCE_RESPONSE was replaced by OPENTHREAD_CONFIG_MLE_SEND_UNICAST_ANNOUNCE_RESPONSE."
#endif

#ifdef OPENTHREAD_CONFIG_ENABLE_ANNOUNCE_SENDER
#error "OPENTHREAD_CONFIG_ENABLE_ANNOUNCE_SENDER was replaced by OPENTHREAD_CONFIG_ANNOUNCE_SENDER_ENABLE."
#endif

#ifdef OPENTHREAD_CONFIG_STAY_AWAKE_BETWEEN_FRAGMENTS
#error \
    "OPENTHREAD_CONFIG_STAY_AWAKE_BETWEEN_FRAGMENTS was replaced by OPENTHREAD_CONFIG_MAC_STAY_AWAKE_BETWEEN_FRAGMENTS."
#endif

#ifdef OPENTHREAD_CONFIG_ENABLE_DYNAMIC_MPL_INTERVAL
#error "OPENTHREAD_CONFIG_ENABLE_DYNAMIC_MPL_INTERVAL was replaced by OPENTHREAD_CONFIG_MPL_DYNAMIC_INTERVAL_ENABLE."
#endif

#ifdef OPENTHREAD_CONFIG_ENABLE_LONG_ROUTES
#error "OPENTHREAD_CONFIG_ENABLE_LONG_ROUTES was replaced by OPENTHREAD_CONFIG_MLE_LONG_ROUTES_ENABLE."
#endif

#ifdef OPENTHREAD_CONFIG_MINIMUM_POLL_PERIOD
#error "OPENTHREAD_CONFIG_MINIMUM_POLL_PERIOD was replaced by OPENTHREAD_CONFIG_MAC_MINIMUM_POLL_PERIOD."
#endif

#ifdef OPENTHREAD_CONFIG_RETX_POLL_PERIOD
#error "OPENTHREAD_CONFIG_RETX_POLL_PERIOD was replaced by OPENTHREAD_CONFIG_MAC_RETX_POLL_PERIOD."
#endif

#ifdef OPENTHREAD_CONFIG_IPV6_DEFAULT_HOP_LIMIT
#error "OPENTHREAD_CONFIG_IPV6_DEFAULT_HOP_LIMIT was replaced by OPENTHREAD_CONFIG_IP6_HOP_LIMIT_DEFAULT."
#endif

#ifdef OPENTHREAD_CONFIG_IPV6_DEFAULT_MAX_DATAGRAM
#error "OPENTHREAD_CONFIG_IPV6_DEFAULT_MAX_DATAGRAM was replaced by OPENTHREAD_CONFIG_IP6_MAX_DATAGRAM_LENGTH."
#endif

#ifdef OPENTHREAD_CONFIG_HEADER_IE_SUPPORT
#error "OPENTHREAD_CONFIG_HEADER_IE_SUPPORT was replaced by OPENTHREAD_CONFIG_MAC_HEADER_IE_SUPPORT."
#endif

#ifdef OPENTHREAD_CONFIG_MAX_JOINER_ENTRIES
#error "OPENTHREAD_CONFIG_MAX_JOINER_ENTRIES was replaced by OPENTHREAD_CONFIG_COMMISSIONER_MAX_JOINER_ENTRIES."
#endif

#ifdef OPENTHREAD_CONFIG_NUM_DHCP_PREFIXES
#error "OPENTHREAD_CONFIG_NUM_DHCP_PREFIXES was replaced by OPENTHREAD_CONFIG_DHCP6_SERVER_NUM_PREFIXES."
#endif

#ifdef OPENTHREAD_CONFIG_INFORM_PREVIOUS_PARENT_ON_REATTACH
#error \
    "OPENTHREAD_CONFIG_INFORM_PREVIOUS_PARENT_ON_REATTACH was replaced by OPENTHREAD_CONFIG_MLE_INFORM_PREVIOUS_PARENT_ON_REATTACH."
#endif

#ifdef OPENTHREAD_CONFIG_PLATFORM_RADIO_COEX_METRICS_ENABLE
#error \
    "OPENTHREAD_CONFIG_PLATFORM_RADIO_COEX_METRICS_ENABLE was replaced by OPENTHREAD_CONFIG_PLATFORM_RADIO_COEX_ENABLE."
#endif

#ifdef OPENTHREAD_CONFIG_MAC_MAX_FRAME_RETRIES_DIRECT
#error \
    "OPENTHREAD_CONFIG_MAC_MAX_FRAME_RETRIES_DIRECT was replaced by OPENTHREAD_CONFIG_MAC_DEFAULT_MAX_FRAME_RETRIES_DIRECT."
#endif

#ifdef OPENTHREAD_CONFIG_MAC_MAX_FRAME_RETRIES_INDIRECT
#error \
    "OPENTHREAD_CONFIG_MAC_MAX_FRAME_RETRIES_INDIRECT was replaced by OPENTHREAD_CONFIG_MAC_DEFAULT_MAX_FRAME_RETRIES_INDIRECT."
#endif

#ifdef OPENTHREAD_CONFIG_ENABLE_TX_ERROR_RATE_TRACKING
#error "OPENTHREAD_CONFIG_ENABLE_TX_ERROR_RATE_TRACKING was removed."
#endif

#ifdef OPENTHREAD_CONFIG_ENABLE_DYNAMIC_LOG_LEVEL
#error "OPENTHREAD_CONFIG_ENABLE_DYNAMIC_LOG_LEVEL was replaced by OPENTHREAD_CONFIG_LOG_LEVEL_DYNAMIC_ENABLE."
#endif

#ifdef OPENTHREAD_CONFIG_INITIAL_LOG_LEVEL
#error "OPENTHREAD_CONFIG_INITIAL_LOG_LEVEL was replaced by OPENTHREAD_CONFIG_LOG_LEVEL_INIT."
#endif

#ifdef OPENTHREAD_CONFIG_COAP_ACK_TIMEOUT
#error \
    "OPENTHREAD_CONFIG_COAP_ACK_TIMEOUT was removed. Use otCoapSendRequestWithParameters to configure CoAP transmission parameters."
#endif

#ifdef OPENTHREAD_CONFIG_COAP_ACK_TIMEOUT_MILLIS
#error \
    "OPENTHREAD_CONFIG_COAP_ACK_TIMEOUT_MILLIS was removed. Use otCoapSendRequestWithParameters to configure CoAP transmission parameters."
#endif

#ifdef OPENTHREAD_CONFIG_LOG_OUTPUT_NCP_SPINEL
#error "OPENTHREAD_CONFIG_LOG_OUTPUT_NCP_SPINEL is removed, use OPENTHREAD_CONFIG_LOG_OUTPUT_APP instead"
#endif

#ifdef OPENTHREAD_CONFIG_DNS_RESPONSE_TIMEOUT
#error "OPENTHREAD_CONFIG_DNS_RESPONSE_TIMEOUT was replaced by OPENTHREAD_CONFIG_DNS_CLIENT_DEFAULT_RESPONSE_TIMEOUT"
#endif

#ifdef OPENTHREAD_CONFIG_DNS_MAX_RETRANSMIT
#error "OPENTHREAD_CONFIG_DNS_MAX_RETRANSMIT was replaced by OPENTHREAD_CONFIG_DNS_CLIENT_DEFAULT_MAX_TX_ATTEMPTS"
#endif

#ifdef OPENTHREAD_CONFIG_SRP_CLIENT_BUFFERS_MAX_HOST_ADDRSSES
#error "OPENTHREAD_CONFIG_SRP_CLIENT_BUFFERS_MAX_HOST_ADDRSSES was replaced by "\
       "OPENTHREAD_CONFIG_SRP_CLIENT_BUFFERS_MAX_HOST_ADDRESSES"
#endif

#ifdef OPENTHREAD_CONFIG_ANNOUNCE_SENDER_INTERVAL_ROUTER
#error "OPENTHREAD_CONFIG_ANNOUNCE_SENDER_INTERVAL_ROUTER was replaced by OPENTHREAD_CONFIG_ANNOUNCE_SENDER_INTERVAL"
#endif

#ifdef OPENTHREAD_CONFIG_ANNOUNCE_SENDER_INTERVAL_REED
#error "OPENTHREAD_CONFIG_ANNOUNCE_SENDER_INTERVAL_REED was replaced by OPENTHREAD_CONFIG_ANNOUNCE_SENDER_INTERVAL"
#endif

#ifdef OPENTHREAD_CONFIG_SRP_SERVER_SERVICE_NUMBER
#error "OPENTHREAD_CONFIG_SRP_SERVER_SERVICE_NUMBER was removed. "\
       "Service numbers are defined in `network_data_servcie.hpp` per spec"
#endif

#ifdef OPENTHREAD_CONFIG_SRP_SERVER_UDP_PORT
#error "OPENTHREAD_CONFIG_SRP_SERVER_UDP_PORT was removed. "\
       "You can make OPENTHREAD_CONFIG_SRP_SERVER_UDP_PORT_MIN = OPENTHREAD_CONFIG_SRP_SERVER_UDP_PORT_MAX to specify a static UDP port. "
#endif

#ifdef OPENTHREAD_CONFIG_MLE_LINK_METRICS_ENABLE
#error "OPENTHREAD_CONFIG_MLE_LINK_METRICS_ENABLE was replaced by OPENTHREAD_CONFIG_MLE_LINK_METRICS_INITIATOR_ENABLE" \
       " and OPENTHREAD_CONFIG_MLE_LINK_METRICS_SUBJECT_ENABLE"
#endif

#ifdef OPENTHREAD_CONFIG_LOG_DEFINE_AS_MACRO_ONLY
#error "OPENTHREAD_CONFIG_LOG_DEFINE_AS_MACRO_ONLY was removed and no longer supported"
#endif

#ifdef OPENTHREAD_CONFIG_PLAT_LOG_MACRO_NAME
#error "OPENTHREAD_CONFIG_PLAT_LOG_MACRO_NAME was removed and no longer supported"
#endif

#ifdef OPENTHREAD_CONFIG_PLAT_LOG_FUNCTION
#error "OPENTHREAD_CONFIG_PLAT_LOG_FUNCTION was removed and no longer supported"
#endif

#ifdef OPENTHREAD_CONFIG_UNSECURE_TRAFFIC_MANAGED_BY_STACK_ENABLE
#error "OPENTHREAD_CONFIG_UNSECURE_TRAFFIC_MANAGED_BY_STACK_ENABLE was removed and no longer supported"
#endif

#ifdef OPENTHREAD_CONFIG_LOG_API
#error "OPENTHREAD_CONFIG_LOG_API was removed and no longer supported"
#endif

#ifdef OPENTHREAD_CONFIG_LOG_MLE
#error "OPENTHREAD_CONFIG_LOG_MLE was removed and no longer supported"
#endif

#ifdef OPENTHREAD_CONFIG_LOG_MESHCOP
#error "OPENTHREAD_CONFIG_LOG_MESHCOP was removed and no longer supported"
#endif

#ifdef OPENTHREAD_CONFIG_LOG_ARP
#error "OPENTHREAD_CONFIG_LOG_ARP was removed and no longer supported"
#endif

#ifdef OPENTHREAD_CONFIG_LOG_NETDATA
#error "OPENTHREAD_CONFIG_LOG_NETDATA was removed and no longer supported"
#endif

#ifdef OPENTHREAD_CONFIG_LOG_ICMP
#error "OPENTHREAD_CONFIG_LOG_ICMP was removed and no longer supported"
#endif

#ifdef OPENTHREAD_CONFIG_LOG_IP6
#error "OPENTHREAD_CONFIG_LOG_IP6 was removed and no longer supported"
#endif

#ifdef OPENTHREAD_CONFIG_LOG_TCP
#error "OPENTHREAD_CONFIG_LOG_TCP was removed and no longer supported"
#endif

#ifdef OPENTHREAD_CONFIG_LOG_MAC
#error "OPENTHREAD_CONFIG_LOG_MAC was removed and no longer supported"
#endif

#ifdef OPENTHREAD_CONFIG_LOG_MEM
#error "OPENTHREAD_CONFIG_LOG_MEM was removed and no longer supported"
#endif

#ifdef OPENTHREAD_CONFIG_LOG_NETDIAG
#error "OPENTHREAD_CONFIG_LOG_NETDIAG was removed and no longer supported"
#endif

#ifdef OPENTHREAD_CONFIG_LOG_COAP
#error "OPENTHREAD_CONFIG_LOG_COAP was removed and no longer supported"
#endif

#ifdef OPENTHREAD_CONFIG_LOG_CORE
#error "OPENTHREAD_CONFIG_LOG_CORE was removed and no longer supported"
#endif

#ifdef OPENTHREAD_CONFIG_LOG_UTIL
#error "OPENTHREAD_CONFIG_LOG_UTIL was removed and no longer supported"
#endif

#ifdef OPENTHREAD_CONFIG_LOG_BBR
#error "OPENTHREAD_CONFIG_LOG_BBR was removed and no longer supported"
#endif

#ifdef OPENTHREAD_CONFIG_LOG_MLR
#error "OPENTHREAD_CONFIG_LOG_MLR was removed and no longer supported"
#endif

#ifdef OPENTHREAD_CONFIG_LOG_DUA
#error "OPENTHREAD_CONFIG_LOG_DUA was removed and no longer supported"
#endif

#ifdef OPENTHREAD_CONFIG_LOG_BR
#error "OPENTHREAD_CONFIG_LOG_BR was removed and no longer supported"
#endif

#ifdef OPENTHREAD_CONFIG_LOG_SRP
#error "OPENTHREAD_CONFIG_LOG_SRP was removed and no longer supported"
#endif

#ifdef OPENTHREAD_CONFIG_LOG_DNS
#error "OPENTHREAD_CONFIG_LOG_DNS was removed and no longer supported"
#endif

#ifdef OPENTHREAD_CONFIG_LOG_PREPEND_REGION
#error "OPENTHREAD_CONFIG_LOG_PREPEND_REGION was removed and not longer supported"
#endif

#ifdef OPENTHREAD_CONFIG_SRP_SERVER_MAX_ADDRESSES_NUM
#error "OPENTHREAD_CONFIG_SRP_SERVER_MAX_ADDRESSES_NUM was removed. "\
       "SRP host uses dynamic heap array to store addresses so no need for config on max number of addresses".
#endif

#endif // OPENTHREAD_CORE_CONFIG_CHECK_H_

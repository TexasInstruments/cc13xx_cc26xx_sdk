/*
 * Copyright (c) 2021, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/** ============================================================================
 *  @file       AESCMACCC26XX.h
 *
 *  @brief      AESCMAC driver implementation for the CC26XX family
 *
 * This file should only be included in the board file to fill the
 * AESCMAC_config struct.
 *
 * # Hardware Accelerator #
 * The CC26XX family has a dedicated hardware crypto accelerator. It is capable
 * of multiple AES block cipher modes of operation including CBC-MAC. Only one
 * operation can be carried out on the accelerator at a time. Mutual exclusion
 * is implemented at the driver level and coordinated between all drivers
 * relying on the accelerator. It is transparent to the application and only
 * noted to ensure sensible access timeouts are set.
 *
 * # Key Store #
 * The CC26XX' crypto module contains a key store. The only way to load a key
 * into the AES accelerator is to first load it into the key store. To guarantee
 * availability of open key locations in the key store for AES operations, the
 * last two key locations (6 and 7) are reserved for ad-hoc operations. The key
 * is loaded into the key store, the AES operation is carried out, and the key
 * is deleted from the key store. Since the key store does not have retention
 * and the keys can not survive going into standby, the key store is only used
 * to load keys into the AES accelerator rather than store keys. Support for
 * pre-loading keys into the key store and using them in an AES operation is not
 * supported in this driver.
 *
 * # Implementation Limitations
 * - Only plaintext CryptoKeys are supported by this implementation.
 *
 * # Runtime Parameter Validation #
 * The driver implementation does not perform runtime checks for most input
 * parameters. Only values that are likely to have a stochastic element to them
 * are checked (such as whether a driver is already open). Higher input
 * parameter validation coverage is achieved by turning on assertions when
 * compiling the driver.
 */

#ifndef ti_drivers_aescmac_AESCMACCC26XX__include
#define ti_drivers_aescmac_AESCMACCC26XX__include

#include <stdint.h>
#include <stdbool.h>

#include <ti/drivers/AESCMAC.h>

#include <ti/drivers/dpl/SwiP.h>

#include <ti/devices/DeviceFamily.h>
#include DeviceFamily_constructPath(driverlib/aes.h)

#ifdef __cplusplus
extern "C" {
#endif

/*!
 *  @brief      AESCMACCC26XX Hardware Attributes
 *
 *  AESCMAC26XX hardware attributes should be included in the board file
 *  and pointed to by the AESCMAC_config struct.
 */
typedef struct {
    /*! @brief Crypto Peripheral's interrupt priority.

        The CC26XX uses three of the priority bits, meaning ~0 has the same
        effect as (7 << 5).

        (7 << 5) will apply the lowest priority.

        (1 << 5) will apply the highest priority.

        Setting the priority to 0 is not supported by this driver.

        HWI's with priority 0 ignore the HWI dispatcher to support zero-latency
        interrupts, thus invalidating the critical sections in this driver.
    */
    uint8_t  intPriority;
} AESCMACCC26XX_HWAttrs;

/*!
 *  @brief      AESCMACCC26XX Object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct {
    uint32_t                 intermediateTag[AES_TAG_LENGTH_BYTES / 4];
    uint32_t                 buffer[AES_BLOCK_SIZE / 4];
    uint32_t                 semaphoreTimeout;
    AESCMAC_CallbackFxn      callbackFxn;
    AESCMAC_Operation        *operation;
    CryptoKey                key;
    volatile int_fast16_t    returnStatus;
    AESCMAC_ReturnBehavior   returnBehavior;
    AESCMAC_OperationType    operationType;
    AESCMAC_OperationalMode  operationalMode;
    bool                     isOpen;
    bool                     threadSafe;
    volatile bool            cryptoResourceLocked;
    volatile bool            hwBusy;
    volatile bool            operationInProgress;
} AESCMACCC26XX_Object;

/*!
 *  @cond NODOC
 *  @brief   Internal functions which may be called by other drivers to handle
 *           thread safety directly.
 */
bool AESCMAC_acquireLock(AESCMAC_Handle handle, uint32_t timeout);
void AESCMAC_releaseLock(AESCMAC_Handle handle);
void AESCMAC_enableThreadSafety(AESCMAC_Handle handle);
void AESCMAC_disableThreadSafety(AESCMAC_Handle handle);
/*! @endcond */

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_aescmac_AESCMACCC26XX__include */

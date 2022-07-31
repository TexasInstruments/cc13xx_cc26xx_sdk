/*
 * Copyright (c) 2017-2022, Texas Instruments Incorporated
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

#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include <ti/drivers/dpl/DebugP.h>
#include <ti/drivers/dpl/HwiP.h>
#include <ti/drivers/dpl/SemaphoreP.h>
#include <ti/drivers/dpl/DebugP.h>

#include <ti/drivers/Power.h>
#include <ti/drivers/power/PowerCC26X2.h>
#include <ti/drivers/ECDH.h>
#include <ti/drivers/ecdh/ECDHCC26X2.h>
#include <ti/drivers/cryptoutils/ecc/ECCParams.h>
#include <ti/drivers/cryptoutils/utils/CryptoUtils.h>
#include <ti/drivers/cryptoutils/sharedresources/PKAResourceCC26XX.h>

#include <ti/devices/DeviceFamily.h>
#include DeviceFamily_constructPath(inc/hw_memmap.h)
#include DeviceFamily_constructPath(inc/hw_ints.h)
#include DeviceFamily_constructPath(inc/hw_types.h)
#include DeviceFamily_constructPath(inc/hw_crypto.h)
#include DeviceFamily_constructPath(driverlib/aes.h)
#include DeviceFamily_constructPath(driverlib/cpu.h)
#include DeviceFamily_constructPath(driverlib/interrupt.h)
#include DeviceFamily_constructPath(driverlib/sys_ctrl.h)
#include DeviceFamily_constructPath(driverlib/smph.h)

/* Forward declarations */
static void ECDHCC26X2_hwiFxn(uintptr_t arg0);
#if (SPE_ENABLED == 0)
static void ECDHCC26X2_internalCallbackFxn(ECDH_Handle handle,
                                           int_fast16_t returnStatus,
                                           ECDH_Operation operation,
                                           ECDH_OperationType operationType);
#endif
static int_fast16_t ECDHCC26X2_waitForAccess(ECDH_Handle handle);
static int_fast16_t ECDHCC26X2_waitForResult(ECDH_Handle handle);
static int_fast16_t ECDHCC26X2_runFSM(ECDH_Handle handle);
static int_fast16_t ECDHCC26X2_convertReturnValue(uint32_t pkaResult);

/* Static globals */
static bool isInitialized = false;
static uint32_t resultAddress;

/* Defines */

/* We need several scratch buffers as the private and public keys are provided
 * in octet string form and thus the components are big-endian. We need to feed
 * the PKA with little-endian integers. That means moving them to some scratch
 * memory and reversing them. The only exception is X25519 that can either be
 * sent in octet string form or x-only little-endian form.
 * We are storing them in bytes 512 to 512 + 3 x SCRATCH_BUFFER_SIZE.
 * Byte 1024 to 1024 + 66 and 1536 to 1536 + 66 are used by the public key
 * validation routine in driverlib.
 */
#define SCRATCH_BUFFER_OFFSET 512
#define SCRATCH_BUFFER_SIZE   96

#define SCRATCH_PRIVATE_KEY ((uint32_t *)(PKA_RAM_BASE + SCRATCH_BUFFER_OFFSET))
#define SCRATCH_PUBLIC_X    ((uint32_t *)(PKA_RAM_BASE + SCRATCH_BUFFER_OFFSET + SCRATCH_BUFFER_SIZE))
#define SCRATCH_PUBLIC_Y    ((uint32_t *)(PKA_RAM_BASE + SCRATCH_BUFFER_OFFSET + 2 * SCRATCH_BUFFER_SIZE))

/* Octet string format requires an extra byte at the start of the public key */
#define OCTET_STRING_OFFSET 1

#if (SPE_ENABLED == 0)
/*
 *  ======== ECDHCC26X2_internalCallbackFxn ========
 */
static void ECDHCC26X2_internalCallbackFxn(ECDH_Handle handle,
                                           int_fast16_t returnStatus,
                                           ECDH_Operation operation,
                                           ECDH_OperationType operationType)
{
    ECDHCC26X2_Object *object = handle->object;

    /*
     * This function is only registered when in ECDH_RETURN_BEHAVIOR_BLOCKING
     * or ECDH_RETURN_BEHAVIOR_POLLING.
     */
    if (object->returnBehavior == ECDH_RETURN_BEHAVIOR_BLOCKING)
    {
        SemaphoreP_post(&PKAResourceCC26XX_operationSemaphore);
    }
    else
    {
        PKAResourceCC26XX_pollingFlag = 1;
    }
}
#endif

static uint32_t ECDHCC26X2_getPublicKeyResult(CryptoKey *publicKey,
                                              const ECCParams_CurveParams *curve,
                                              ECDH_KeyMaterialEndianness keyMaterialEndianness,
                                              uint32_t resultPKAMemAddr)
{
    uint32_t pkaResult;

    if (keyMaterialEndianness == ECDH_BIG_ENDIAN_KEY)
    {
        /* Get X and Y coordinates with OCTET_STRING_OFFSET for big-endian keys */
        pkaResult = PKAEccMultiplyGetResult(publicKey->u.plaintext.keyMaterial + OCTET_STRING_OFFSET,
                                            publicKey->u.plaintext.keyMaterial + curve->length + OCTET_STRING_OFFSET,
                                            resultPKAMemAddr,
                                            curve->length);
        /*
         * Set first byte of output public key to 0x04 to indicate x,y
         * big-endian coordinates in octet string format
         */
        publicKey->u.plaintext.keyMaterial[0] = 0x04;

        /* Byte-reverse integer X coordinate for octet string format */
        CryptoUtils_reverseBufferBytewise(publicKey->u.plaintext.keyMaterial + OCTET_STRING_OFFSET, curve->length);

        /* Byte-reverse integer Y coordinate for octet string format */
        CryptoUtils_reverseBufferBytewise(publicKey->u.plaintext.keyMaterial + curve->length + OCTET_STRING_OFFSET,
                                          curve->length);
    }
    else
    {
        /*
         * Get X and Y coordinates  without byte-reverse and
         * without OCTET_STRING_OFFSET for little-endian keys
         */
        pkaResult = PKAEccMultiplyGetResult(publicKey->u.plaintext.keyMaterial,
                                            publicKey->u.plaintext.keyMaterial + curve->length,
                                            resultPKAMemAddr,
                                            curve->length);
    }

    return pkaResult;
}

static uint32_t ECDHCC26X2_getPublicKeyResultMontgomery(CryptoKey *publicKey,
                                                        const ECCParams_CurveParams *curve,
                                                        uint32_t resultPKAMemAddr)
{
    uint32_t pkaResult;

    /* Montgomery curves use X-only little-endian public keys */
    pkaResult = PKAEccMultiplyGetResult(publicKey->u.plaintext.keyMaterial,
                                        NULL, /* No Y-Coordinate */
                                        resultPKAMemAddr,
                                        curve->length);
    return pkaResult;
}

/*
 *  ======== ECDHCC26X2_formatCurve25519PrivateKeyScratch ========
 */
static void ECDHCC26X2_formatCurve25519PrivateKeyScratch(uint32_t *myPrivateKey)
{
    /*
     * As per RFC 7748, the private key of Curve25519 is pruned so that
     * the three LSB's are cleared, bit 255 is cleared, and bit 254 is
     * set.
     */
    /* Clear bit 0, 1, and 2 */
    myPrivateKey[0] &= 0xFFFFFFF8UL;
    /* Clear bit 255 */
    myPrivateKey[7] &= 0x7FFFFFFFUL;
    /* Set bit 254 */
    myPrivateKey[7] |= 0x40000000UL;
}

/*
 *  ======== ECDHCC26X2_hwiFxn ========
 */
static void ECDHCC26X2_hwiFxn(uintptr_t arg0)
{
    ECDHCC26X2_Object *object = ((ECDH_Handle)arg0)->object;
    int_fast16_t operationStatus;
    ECDH_Operation operation;
    ECDH_OperationType operationType;
    uint32_t key;

    /* Disable interrupt again. It may be reenabled in the FSM function. */
    IntDisable(INT_PKA_IRQ);

    /* Execute next states */
    do
    {
        object->operationStatus = ECDHCC26X2_runFSM((ECDH_Handle)arg0);
        object->fsmState++;
    } while (object->operationStatus == ECDHCC26X2_STATUS_FSM_RUN_FSM);

    /*
     * We need a critical section here in case the operation is canceled
     * asynchronously.
     */
    key = HwiP_disable();

    if (object->operationCanceled)
    {
        /* Set function register to 0. This should stop the current operation */
        HWREG(PKA_BASE + PKA_O_FUNCTION) = 0;

        object->operationStatus = ECDH_STATUS_CANCELED;
    }

    switch (object->operationStatus)
    {
        case ECDHCC26X2_STATUS_FSM_RUN_PKA_OP:

            HwiP_restore(key);

            /* Do nothing. The PKA or TRNG hardware
             * will execute in the background and post
             * this SWI when it is done.
             */
            break;
        case ECDH_STATUS_SUCCESS:
            /* Intentional fall through */
        case ECDH_STATUS_ERROR:
            /* Intentional fall through */
        case ECDH_STATUS_CANCELED:
            /* Intentional fall through */
        default:

            /* Mark this operation as complete */
            object->operationInProgress = false;

            /* Clear any pending interrupt in case a transaction kicked off
             * above already finished
             */
            IntDisable(INT_PKA_IRQ);
            IntPendClear(INT_PKA_IRQ);

            /* We can end the critical section since the operation may no
             * longer be canceled
             */
            HwiP_restore(key);

            /* Make sure there is no keying material remaining in PKA RAM */
            PKAClearPkaRam();

            /* Save all inputs to the callbackFxn on the stack
             * in case a higher priority hwi comes in and
             * starts a new operation after we have released the
             * access semaphore.
             */
            operationStatus = object->operationStatus;
            operation       = object->operation;
            operationType   = object->operationType;

            Power_releaseConstraint(PowerCC26XX_DISALLOW_STANDBY);

            /*  Grant access for other threads to use the crypto module.
             *  The semaphore must be posted before the callbackFxn to allow the chaining
             *  of operations. This does have the drawback that another hwi
             *  can come in and start an operation before the original
             *  on finished completely. This should be prevented by
             *  customers only starting operations with the same
             *  handle from a single context and waiting for
             *  the callback of the original operation to
             *  be executed in callback return mode.
             */
            SemaphoreP_post(&PKAResourceCC26XX_accessSemaphore);

            object->callbackFxn((ECDH_Handle)arg0, operationStatus, operation, operationType);
    }
}

static int_fast16_t ECDHCC26X2_runFSM(ECDH_Handle handle)
{
    ECDHCC26X2_Object *object = handle->object;
    uint32_t pkaResult;

    switch (object->fsmState)
    {
        case ECDHCC26X2_FSM_GEN_PUB_KEY_MULT_PRIVATE_KEY_BY_GENERATOR:

            /* Perform an elliptic curve multiplication on a short Weierstrass curve */
            PKAEccMultiplyStart((uint8_t *)SCRATCH_PRIVATE_KEY,
                                object->operation.generatePublicKey->curve->generatorX,
                                object->operation.generatePublicKey->curve->generatorY,
                                object->operation.generatePublicKey->curve->prime,
                                object->operation.generatePublicKey->curve->a,
                                object->operation.generatePublicKey->curve->b,
                                object->operation.generatePublicKey->curve->length,
                                &resultAddress);
            break;

        case ECDHCC26X2_FSM_GEN_PUB_KEY_MULT_PRIVATE_KEY_BY_GENERATOR_RESULT:

            pkaResult = ECDHCC26X2_getPublicKeyResult(object->operation.generatePublicKey->myPublicKey,
                                                      object->operation.generatePublicKey->curve,
                                                      object->operation.generatePublicKey->keyMaterialEndianness,
                                                      resultAddress);

            return ECDHCC26X2_convertReturnValue(pkaResult);

        case ECDHCC26X2_FSM_GEN_PUB_KEY_MULT_PRIVATE_KEY_BY_GENERATOR_MONTGOMERY:

            /*
             * As per RFC 7748, the private key of Curve25519 is pruned so that
             * the three LSB's are cleared, bit 255 is cleared, and bit 254 is
             * set.
             */
            if (object->operation.generatePublicKey->curve->length == ECCParams_CURVE25519_LENGTH)
            {
                ECDHCC26X2_formatCurve25519PrivateKeyScratch(SCRATCH_PRIVATE_KEY);
            }

            /* Perform an elliptic curve multiplication on a Montgomery curve. Likely Curve25519. */
            PKAEccMontgomeryMultiplyStart((uint8_t *)SCRATCH_PRIVATE_KEY,
                                          object->operation.generatePublicKey->curve->generatorX,
                                          object->operation.generatePublicKey->curve->prime,
                                          object->operation.generatePublicKey->curve->a,
                                          object->operation.generatePublicKey->curve->length,
                                          &resultAddress);

            break;

        case ECDHCC26X2_FSM_GEN_PUB_KEY_MULT_PRIVATE_KEY_BY_GENERATOR_RESULT_MONTGOMERY:

            if ((object->operation.generatePublicKey->keyMaterialEndianness == ECDH_LITTLE_ENDIAN_KEY) &&
                (object->operation.generatePublicKey->curve->curveType == ECCParams_CURVE_TYPE_MONTGOMERY))
            {
                pkaResult = ECDHCC26X2_getPublicKeyResultMontgomery(object->operation.generatePublicKey->myPublicKey,
                                                                    object->operation.generatePublicKey->curve,
                                                                    resultAddress);
            }
            else
            {
                pkaResult = ECDHCC26X2_getPublicKeyResult(object->operation.generatePublicKey->myPublicKey,
                                                          object->operation.generatePublicKey->curve,
                                                          object->operation.generatePublicKey->keyMaterialEndianness,
                                                          resultAddress);
                /* Zero-out the Y coordinate */
                memset(object->operation.generatePublicKey->myPublicKey->u.plaintext.keyMaterial +
                           object->operation.generatePublicKey->curve->length + OCTET_STRING_OFFSET,
                       0x00,
                       object->operation.generatePublicKey->curve->length);
            }

            return ECDHCC26X2_convertReturnValue(pkaResult);

        case ECDHCC26X2_FSM_COMPUTE_SHARED_SECRET_MULT_PRIVATE_KEY_BY_PUB_KEY:
            /* If we are using a short Weierstrass curve, we need to validate the public key */
            pkaResult = PKAEccVerifyPublicKeyWeierstrassStart((uint8_t *)SCRATCH_PUBLIC_X,
                                                              (uint8_t *)SCRATCH_PUBLIC_Y,
                                                              object->operation.computeSharedSecret->curve->prime,
                                                              object->operation.computeSharedSecret->curve->a,
                                                              object->operation.computeSharedSecret->curve->b,
                                                              object->operation.computeSharedSecret->curve->order,
                                                              object->operation.computeSharedSecret->curve->length);

            if (pkaResult != PKA_STATUS_SUCCESS)
            {
                return ECDH_STATUS_PUBLIC_KEY_NOT_ON_CURVE;
            }

            /* Perform an elliptic curve multiplication on a short Weierstrass curve */
            PKAEccMultiplyStart((uint8_t *)SCRATCH_PRIVATE_KEY,
                                (uint8_t *)SCRATCH_PUBLIC_X,
                                (uint8_t *)SCRATCH_PUBLIC_Y,
                                object->operation.computeSharedSecret->curve->prime,
                                object->operation.computeSharedSecret->curve->a,
                                object->operation.computeSharedSecret->curve->b,
                                object->operation.computeSharedSecret->curve->length,
                                &resultAddress);

            break;

        case ECDHCC26X2_FSM_COMPUTE_SHARED_SECRET_MULT_PRIVATE_KEY_BY_PUB_KEY_RESULT:

            pkaResult = ECDHCC26X2_getPublicKeyResult(object->operation.computeSharedSecret->sharedSecret,
                                                      object->operation.computeSharedSecret->curve,
                                                      object->operation.computeSharedSecret->keyMaterialEndianness,
                                                      resultAddress);

            return ECDHCC26X2_convertReturnValue(pkaResult);

        case ECDHCC26X2_FSM_COMPUTE_SHARED_SECRET_MULT_PRIVATE_KEY_BY_PUB_KEY_MONTGOMERY:

            /*
             * As per RFC 7748, Curve25519 will mask the most significant bit
             * of the final byte for received u-coordinates. The curve length
             * of the Montgomery curve is used as an identifier here.
             *
             * Furthermore, the private key of Curve25519 is pruned so that
             * the three LSB's are cleared, bit 255 is cleared, and bit 254 is
             * set.
             */
            if (object->operation.computeSharedSecret->curve->length == ECCParams_CURVE25519_LENGTH)
            {
                /* Since PKA RAM can only be accessed by word, compute the most
                 * significant word of the received Curve25519 public key and
                 * mask its MSB.
                 */
                uint32_t *curve25519PubKeyWord = SCRATCH_PUBLIC_X;
                curve25519PubKeyWord[(ECCParams_CURVE25519_LENGTH / sizeof(uint32_t)) - 1U] &= 0x7FFFFFFF;

                /* Prune the private key */
                ECDHCC26X2_formatCurve25519PrivateKeyScratch(SCRATCH_PRIVATE_KEY);
            }

            /* Perform an elliptic curve multiplication on a Montgomery curve. Likely Curve25519. */
            PKAEccMontgomeryMultiplyStart((uint8_t *)SCRATCH_PRIVATE_KEY,
                                          (uint8_t *)SCRATCH_PUBLIC_X,
                                          object->operation.computeSharedSecret->curve->prime,
                                          object->operation.computeSharedSecret->curve->a,
                                          object->operation.computeSharedSecret->curve->length,
                                          &resultAddress);

            break;

        case ECDHCC26X2_FSM_COMPUTE_SHARED_SECRET_MULT_PRIVATE_KEY_BY_PUB_KEY_RESULT_MONTGOMERY:

            if ((object->operation.computeSharedSecret->keyMaterialEndianness == ECDH_LITTLE_ENDIAN_KEY) &&
                (object->operation.computeSharedSecret->curve->curveType == ECCParams_CURVE_TYPE_MONTGOMERY))
            {
                pkaResult = ECDHCC26X2_getPublicKeyResultMontgomery(object->operation.computeSharedSecret->sharedSecret,
                                                                    object->operation.computeSharedSecret->curve,
                                                                    resultAddress);
            }
            else
            {
                pkaResult = ECDHCC26X2_getPublicKeyResult(object->operation.computeSharedSecret->sharedSecret,
                                                          object->operation.computeSharedSecret->curve,
                                                          object->operation.computeSharedSecret->keyMaterialEndianness,
                                                          resultAddress);

                /* Zero-out the Y coordinate */
                memset(object->operation.computeSharedSecret->sharedSecret->u.plaintext.keyMaterial +
                           object->operation.computeSharedSecret->curve->length + OCTET_STRING_OFFSET,
                       0x00,
                       object->operation.computeSharedSecret->curve->length);
            }

            return ECDHCC26X2_convertReturnValue(pkaResult);

        case ECDHCC26X2_FSM_GEN_PUB_KEY_RETURN:
        case ECDHCC26X2_FSM_GEN_PUB_KEY_RETURN_MONTGOMERY:
            /* Mark the public key CryptoKey as non-empty */
            object->operation.generatePublicKey->myPublicKey->encoding = CryptoKey_PLAINTEXT;
            return ECDH_STATUS_SUCCESS;

        case ECDHCC26X2_FSM_COMPUTE_SHARED_SECRET_RETURN:
        case ECDHCC26X2_FSM_COMPUTE_SHARED_SECRET_RETURN_MONTGOMERY:
            /* Mark the shared secret key CryptoKey as non-empty */
            object->operation.computeSharedSecret->sharedSecret->encoding = CryptoKey_PLAINTEXT;
            return ECDH_STATUS_SUCCESS;

        default:
            return ECDH_STATUS_ERROR;
    }

    // If we get to this point, we want to perform another PKA operation
    IntPendClear(INT_PKA_IRQ);
    IntEnable(INT_PKA_IRQ);

    return ECDHCC26X2_STATUS_FSM_RUN_PKA_OP;
}

/*
 *  ======== ECDHCC26X2_convertReturnValue ========
 */
static int_fast16_t ECDHCC26X2_convertReturnValue(uint32_t pkaResult)
{
    switch (pkaResult)
    {
        case PKA_STATUS_SUCCESS:
            /* A less than B only comes up when checking private
             * key values. It indicates a key within the correct range.
             */
            return ECDHCC26X2_STATUS_FSM_RUN_FSM;

        case PKA_STATUS_X_ZERO:
        case PKA_STATUS_Y_ZERO:
        case PKA_STATUS_RESULT_0:
            /* Theoretically, PKA_STATUS_RESULT_0 might be caused by other
             * operations failing but the only one that really should yield
             * 0 is ECC multiplication with invalid inputs that can yield the
             * point at infinity.
             */
            return ECDH_STATUS_PRIVATE_KEY_ZERO;

        case PKA_STATUS_X_LARGER_THAN_PRIME:
        case PKA_STATUS_Y_LARGER_THAN_PRIME:
            return ECDH_STATUS_PUBLIC_KEY_LARGER_THAN_PRIME;

        case PKA_STATUS_POINT_NOT_ON_CURVE:
            return ECDH_STATUS_PUBLIC_KEY_NOT_ON_CURVE;

        case PKA_STATUS_POINT_AT_INFINITY:
            return ECDH_STATUS_POINT_AT_INFINITY;

        default:
            return ECDH_STATUS_ERROR;
    }
}

/*
 *  ======== ECDH_init ========
 */
void ECDH_init(void)
{
    PKAResourceCC26XX_constructRTOSObjects();

    isInitialized = true;
}

/*
 *  ======== ECDH_Params_init ========
 */
void ECDH_Params_init(ECDH_Params *params)
{
    *params = ECDH_defaultParams;
}

/*
 *  ======== ECDH_construct ========
 */
ECDH_Handle ECDH_construct(ECDH_Config *config, const ECDH_Params *params)
{
    ECDH_Handle handle;
    ECDHCC26X2_Object *object;
    uint_fast8_t key;

    handle = (ECDH_Handle)config;
    object = handle->object;

    key = HwiP_disable();

    if (!isInitialized || object->isOpen)
    {
        HwiP_restore(key);
        return NULL;
    }

    object->isOpen = true;

    HwiP_restore(key);

    // If params are NULL, use defaults
    if (params == NULL)
    {
        params = (ECDH_Params *)&ECDH_defaultParams;
    }

    DebugP_assert((params->returnBehavior == ECDH_RETURN_BEHAVIOR_CALLBACK) ? params->callbackFxn : true);

    object->returnBehavior = params->returnBehavior;
#if (SPE_ENABLED == 1)
    /* Always use the secure callback function */
    object->callbackFxn = params->callbackFxn;
#else
    object->callbackFxn = (params->returnBehavior == ECDH_RETURN_BEHAVIOR_CALLBACK) ? params->callbackFxn
                                                                                    : ECDHCC26X2_internalCallbackFxn;
#endif
    object->semaphoreTimeout = params->timeout;

    // Set power dependency - i.e. power up and enable clock for PKA (PKAResourceCC26XX) module.
    Power_setDependency(PowerCC26X2_PERIPH_PKA);

    return handle;
}

/*
 *  ======== ECDH_close ========
 */
void ECDH_close(ECDH_Handle handle)
{
    ECDHCC26X2_Object *object;

    DebugP_assert(handle);

    // Get the pointer to the object
    object = handle->object;

    // Mark the module as available
    object->isOpen = false;

    // Release power dependency on PKA Module.
    Power_releaseDependency(PowerCC26X2_PERIPH_PKA);
}

/*
 *  ======== ECDHCC26X2_waitForAccess ========
 */
static int_fast16_t ECDHCC26X2_waitForAccess(ECDH_Handle handle)
{
    ECDHCC26X2_Object *object = handle->object;
    uint32_t timeout;

    // Set to SemaphoreP_NO_WAIT to start operations from SWI or HWI context
    timeout = object->returnBehavior == ECDH_RETURN_BEHAVIOR_BLOCKING ? object->semaphoreTimeout : SemaphoreP_NO_WAIT;

    return SemaphoreP_pend(&PKAResourceCC26XX_accessSemaphore, timeout);
}

/*
 *  ======== ECDHCC26X2_waitForResult ========
 */
static int_fast16_t ECDHCC26X2_waitForResult(ECDH_Handle handle)
{
    ECDHCC26X2_Object *object = handle->object;

    object->operationInProgress = true;

    switch (object->returnBehavior)
    {
        case ECDH_RETURN_BEHAVIOR_POLLING:
            while (!PKAResourceCC26XX_pollingFlag)
                ;
            return object->operationStatus;
        case ECDH_RETURN_BEHAVIOR_BLOCKING:
            SemaphoreP_pend(&PKAResourceCC26XX_operationSemaphore, SemaphoreP_WAIT_FOREVER);
            return object->operationStatus;
        case ECDH_RETURN_BEHAVIOR_CALLBACK:
            return ECDH_STATUS_SUCCESS;
        default:
            return ECDH_STATUS_ERROR;
    }
}

/*
 *  ======== ECDH_generatePublicKey ========
 */
int_fast16_t ECDH_generatePublicKey(ECDH_Handle handle, ECDH_OperationGeneratePublicKey *operation)
{
    ECDHCC26X2_Object *object         = handle->object;
    ECDHCC26X2_HWAttrs const *hwAttrs = handle->hwAttrs;

    /*
     * Validate public key sizes to ensure X-only public key format if using Montgomery curves
     * with little endian key representation. Other cases use both coordinates with additional
     * octet string format byte when using big endian representation
     */
    if (operation->keyMaterialEndianness == ECDH_LITTLE_ENDIAN_KEY)
    {
        if (operation->curve->curveType == ECCParams_CURVE_TYPE_MONTGOMERY)
        {
            /* X-only public key for Montgomery curves */
            if ((operation->myPrivateKey->u.plaintext.keyLength != operation->curve->length) ||
                (operation->myPublicKey->u.plaintext.keyLength != operation->curve->length))
            {
                return ECDH_STATUS_INVALID_KEY_SIZE;
            }
        }
        else /* Little-endian keys for other curves */
        {
            if ((operation->myPrivateKey->u.plaintext.keyLength != operation->curve->length) ||
                (operation->myPublicKey->u.plaintext.keyLength != 2 * operation->curve->length))
            {
                return ECDH_STATUS_INVALID_KEY_SIZE;
            }
        }
    }
    else /* Validate key sizes to make sure octet string format is used */
    {
        if ((operation->myPrivateKey->u.plaintext.keyLength != operation->curve->length) ||
            (operation->myPublicKey->u.plaintext.keyLength != 2 * operation->curve->length + OCTET_STRING_OFFSET))
        {
            return ECDH_STATUS_INVALID_KEY_SIZE;
        }
    }

    /* Verify that private key is non-zero for short Weierstrass curves */
    if ((operation->curve->curveType == ECCParams_CURVE_TYPE_SHORT_WEIERSTRASS_AN3) &&
        PKAArrayAllZeros(operation->myPrivateKey->u.plaintext.keyMaterial, operation->curve->length))
    {
        return ECDH_STATUS_PRIVATE_KEY_ZERO;
    }

    if (ECDHCC26X2_waitForAccess(handle) != SemaphoreP_OK)
    {
        return ECDH_STATUS_RESOURCE_UNAVAILABLE;
    }

    /*
     * Since we are receiving the private keys in octet string format,
     * we need to convert them to little-endian form for use with the PKA
     * If the private key is already in little-endian form, skip this conversion
     * and directly copy the key.
     */
    if (operation->keyMaterialEndianness == ECDH_BIG_ENDIAN_KEY)
    {
        CryptoUtils_reverseCopyPad(operation->myPrivateKey->u.plaintext.keyMaterial,
                                   SCRATCH_PRIVATE_KEY,
                                   operation->curve->length);
    }
    else
    {
        CryptoUtils_copyPad(operation->myPrivateKey->u.plaintext.keyMaterial,
                            SCRATCH_PRIVATE_KEY,
                            operation->curve->length);
    }

    /* Verify that private key is [1, n] for arbitrary short Weierstrass curves */
    if (operation->curve->curveType == ECCParams_CURVE_TYPE_SHORT_WEIERSTRASS_AN3)
    {
        PKABigNumCmpStart((uint8_t *)SCRATCH_PRIVATE_KEY, operation->curve->order, operation->curve->length);

        while (PKAGetOpsStatus() == PKA_STATUS_OPERATION_BUSY)
            ;

        if (PKABigNumCmpGetResult() != PKA_STATUS_A_LESS_THAN_B)
        {
            SemaphoreP_post(&PKAResourceCC26XX_accessSemaphore);
            return ECDH_STATUS_PRIVATE_KEY_LARGER_EQUAL_ORDER;
        }
    }

    /*
     * Copy over all parameters we will need access to in the FSM.
     * The FSM runs in SWI context and thus needs to keep track of
     * all of them somehow.
     */
    object->operationStatus             = ECDHCC26X2_STATUS_FSM_RUN_FSM;
    object->operation.generatePublicKey = operation;
    object->operationType               = ECDH_OPERATION_TYPE_GENERATE_PUBLIC_KEY;
    object->operationCanceled           = false;

    /* Use the correct state chain for the curve type */
    if (operation->curve->curveType == ECCParams_CURVE_TYPE_SHORT_WEIERSTRASS_AN3)
    {
        object->fsmState = ECDHCC26X2_FSM_GEN_PUB_KEY_MULT_PRIVATE_KEY_BY_GENERATOR;
    }
    else
    {
        object->fsmState = ECDHCC26X2_FSM_GEN_PUB_KEY_MULT_PRIVATE_KEY_BY_GENERATOR_MONTGOMERY;
    }

    /*
     * We need to set the HWI function and priority since the same physical interrupt is shared by multiple
     * drivers and they all need to coexist. Whenever a driver starts an operation, it
     * registers its HWI callback with the OS.
     */
    HwiP_setFunc(&PKAResourceCC26XX_hwi, ECDHCC26X2_hwiFxn, (uintptr_t)handle);
    HwiP_setPriority(INT_PKA_IRQ, hwAttrs->intPriority);

    PKAResourceCC26XX_pollingFlag = 0;

    Power_setConstraint(PowerCC26XX_DISALLOW_STANDBY);

    /*
     * Start running FSM to generate public key. The PKA interrupt is level triggered and
     * will run immediately once enabled
     */
    IntEnable(INT_PKA_IRQ);

    return ECDHCC26X2_waitForResult(handle);
}

/*
 *  ======== ECDH_computeSharedSecret ========
 */
int_fast16_t ECDH_computeSharedSecret(ECDH_Handle handle, ECDH_OperationComputeSharedSecret *operation)
{
    ECDHCC26X2_Object *object         = handle->object;
    ECDHCC26X2_HWAttrs const *hwAttrs = handle->hwAttrs;

    /*
     * Validate public key sizes to ensure X-only public key format if using Montgomery curves
     * with little endian key representation. Other cases use both coordinates with additional
     * octet string offset byte when using big endian representation
     */
    if (operation->keyMaterialEndianness == ECDH_LITTLE_ENDIAN_KEY)
    {
        /* X-only public key for Montgomery curves */
        if (operation->curve->curveType == ECCParams_CURVE_TYPE_MONTGOMERY)
        {
            if ((operation->myPrivateKey->u.plaintext.keyLength != operation->curve->length) ||
                (operation->theirPublicKey->u.plaintext.keyLength != operation->curve->length) ||
                (operation->sharedSecret->u.plaintext.keyLength != operation->curve->length))
            {
                return ECDH_STATUS_INVALID_KEY_SIZE;
            }
        }
        else /* Little-endian keys for other curves */
        {
            if ((operation->myPrivateKey->u.plaintext.keyLength != operation->curve->length) ||
                (operation->theirPublicKey->u.plaintext.keyLength != 2 * operation->curve->length) ||
                (operation->sharedSecret->u.plaintext.keyLength != 2 * operation->curve->length))
            {
                return ECDH_STATUS_INVALID_KEY_SIZE;
            }
        }
    }
    else /* Validate key sizes to make sure octet string format is used for short Weierstrass curves */
    {
        if ((operation->myPrivateKey->u.plaintext.keyLength != operation->curve->length) ||
            (operation->theirPublicKey->u.plaintext.keyLength != 2 * operation->curve->length + OCTET_STRING_OFFSET) ||
            (operation->theirPublicKey->u.plaintext.keyMaterial[0] != 0x04) ||
            (operation->sharedSecret->u.plaintext.keyLength != 2 * operation->curve->length + OCTET_STRING_OFFSET))
        {
            return ECDH_STATUS_INVALID_KEY_SIZE;
        }
    }

    if (ECDHCC26X2_waitForAccess(handle) != SemaphoreP_OK)
    {
        return ECDH_STATUS_RESOURCE_UNAVAILABLE;
    }

    /*
     * Copy over all parameters we will need access to in the FSM.
     * The FSM runs in SWI context and thus needs to keep track of
     * all of them somehow.
     */
    object->operationStatus               = ECDHCC26X2_STATUS_FSM_RUN_FSM;
    object->operation.computeSharedSecret = operation;
    object->operationType                 = ECDH_OPERATION_TYPE_COMPUTE_SHARED_SECRET;
    object->operationCanceled             = false;

    /*
     * Convert keys in octet string format to little-endian form for use with the PKA
     * If the keys is already in little-endian form, skip this conversion
     * and directly copy the key.
     */
    if (operation->keyMaterialEndianness == ECDH_BIG_ENDIAN_KEY)
    {
        CryptoUtils_reverseCopyPad(operation->myPrivateKey->u.plaintext.keyMaterial,
                                   SCRATCH_PRIVATE_KEY,
                                   operation->curve->length);

        CryptoUtils_reverseCopyPad(operation->theirPublicKey->u.plaintext.keyMaterial + OCTET_STRING_OFFSET,
                                   SCRATCH_PUBLIC_X,
                                   operation->curve->length);

        CryptoUtils_reverseCopyPad(operation->theirPublicKey->u.plaintext.keyMaterial + OCTET_STRING_OFFSET +
                                       operation->curve->length,
                                   SCRATCH_PUBLIC_Y,
                                   operation->curve->length);
    }
    else
    {
        CryptoUtils_copyPad(operation->myPrivateKey->u.plaintext.keyMaterial,
                            SCRATCH_PRIVATE_KEY,
                            operation->curve->length);

        CryptoUtils_copyPad(operation->theirPublicKey->u.plaintext.keyMaterial,
                            SCRATCH_PUBLIC_X,
                            operation->curve->length);

        /* Montgomery curves in Little-Endian have X-only public keys */
        if (operation->curve->curveType != ECCParams_CURVE_TYPE_MONTGOMERY)
        {
            CryptoUtils_copyPad(operation->theirPublicKey->u.plaintext.keyMaterial + operation->curve->length,
                                SCRATCH_PUBLIC_Y,
                                operation->curve->length);
        }
    }

    /* Use the correct state chain for the curve type */
    if (operation->curve->curveType == ECCParams_CURVE_TYPE_SHORT_WEIERSTRASS_AN3)
    {
        object->fsmState = ECDHCC26X2_FSM_COMPUTE_SHARED_SECRET_MULT_PRIVATE_KEY_BY_PUB_KEY;
    }
    else
    {
        object->fsmState = ECDHCC26X2_FSM_COMPUTE_SHARED_SECRET_MULT_PRIVATE_KEY_BY_PUB_KEY_MONTGOMERY;
    }

    /*
     * We need to set the HWI function and priority since the same physical interrupt is shared by multiple
     * drivers and they all need to coexist. Whenever a driver starts an operation, it
     * registers its HWI callback with the OS.
     */
    HwiP_setFunc(&PKAResourceCC26XX_hwi, ECDHCC26X2_hwiFxn, (uintptr_t)handle);
    HwiP_setPriority(INT_PKA_IRQ, hwAttrs->intPriority);

    PKAResourceCC26XX_pollingFlag = 0;

    Power_setConstraint(PowerCC26XX_DISALLOW_STANDBY);

    /*
     * Start running FSM to generate PMSN. The PKA interrupt is level triggered and
     * will run imediately once enabled
     */
    IntEnable(INT_PKA_IRQ);

    return ECDHCC26X2_waitForResult(handle);
}

/*
 *  ======== ECDH_cancelOperation ========
 */
int_fast16_t ECDH_cancelOperation(ECDH_Handle handle)
{
    ECDHCC26X2_Object *object = handle->object;

    if (!object->operationInProgress)
    {
        return ECDH_STATUS_ERROR;
    }

    object->operationCanceled = true;

    /* Post hwi as if operation finished for cleanup */
    IntEnable(INT_PKA_IRQ);
    HwiP_post(INT_PKA_IRQ);

    return ECDH_STATUS_SUCCESS;
}

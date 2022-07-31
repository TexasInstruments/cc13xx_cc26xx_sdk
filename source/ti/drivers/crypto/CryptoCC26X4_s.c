/*
 * Copyright (c) 2022 Texas Instruments Incorporated - http://www.ti.com
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

#include "CryptoCC26X4_s.h"
#include <crypto_sp/psa_manifest/crypto_sp.h> /* Auto-generated header */
#include <third_party/tfm/interface/include/psa/service.h>

#include <ti/drivers/aescbc/AESCBCCC26X4_s.h>
#include <ti/drivers/aesccm/AESCCMCC26X4_s.h>
#include <ti/drivers/aescmac/AESCMACCC26X4_s.h>
#include <ti/drivers/aesctr/AESCTRCC26X4_s.h>
#include <ti/drivers/aesctrdrbg/AESCTRDRBGX4_s.h>
#include <ti/drivers/aesecb/AESECBCC26X4_s.h>
#include <ti/drivers/aesgcm/AESGCMCC26X4_s.h>
#include <ti/drivers/ecdh/ECDHCC26X4_s.h>
//#include <ti/drivers/ecdsa/ECDSACC26X4_s.h>
//#include <ti/drivers/eddsa/EDDSACC26X4_s.h>
//#include <ti/drivers/ecjpake/ECJPAKECC26X4_s.h>
#include <ti/drivers/sha2/SHA2CC26X4_s.h>
#include <ti/drivers/trng/TRNGCC26X4_s.h>

#include <ti/drivers/dpl/HwiP.h>

#include <ti/devices/DeviceFamily.h>
#include DeviceFamily_constructPath(inc/hw_ints.h)

/*
 *  ======== Crypto_s_handlePsaMsg ========
 */
static psa_status_t Crypto_s_handlePsaMsg(psa_msg_t *msg)
{
    int32_t msgTypeIndex;
    psa_status_t status = PSA_ERROR_PROGRAMMER_ERROR;

    msgTypeIndex = GET_CRYPTO_S_MSG_TYPE_INDEX(msg->type);

    switch (msgTypeIndex)
    {
        case CRYPTO_S_MSG_TYPE_INDEX_AESCBC:
            status = AESCBC_s_handlePsaMsg(msg);
            break;

        case CRYPTO_S_MSG_TYPE_INDEX_AESCCM:
            status = AESCCM_s_handlePsaMsg(msg);
            break;

        case CRYPTO_S_MSG_TYPE_INDEX_AESCMAC:
            status = AESCMAC_s_handlePsaMsg(msg);
            break;

        case CRYPTO_S_MSG_TYPE_INDEX_AESCTR:
            status = AESCTR_s_handlePsaMsg(msg);
            break;

        case CRYPTO_S_MSG_TYPE_INDEX_AESECB:
            status = AESECB_s_handlePsaMsg(msg);
            break;

        case CRYPTO_S_MSG_TYPE_INDEX_AESGCM:
            status = AESGCM_s_handlePsaMsg(msg);
            break;

        case CRYPTO_S_MSG_TYPE_INDEX_AESCTRDRBG:
            status = AESCTRDRBG_s_handlePsaMsg(msg);
            break;

        case CRYPTO_S_MSG_TYPE_INDEX_ECDH:
            status = ECDH_s_handlePsaMsg(msg);
            break;

            //        case CRYPTO_S_MSG_TYPE_INDEX_ECDSA:
            //            status = ECDSA_s_handlePsaMsg(msg);
            //            break;

            //        case CRYPTO_S_MSG_TYPE_INDEX_ECJPAKE:
            //            status = ECJPAKE_s_handlePsaMsg(msg);
            //            break;

            //        case CRYPTO_S_MSG_TYPE_INDEX_EDDSA:
            //            status = EDDSA_s_handlePsaMsg(msg);
            //            break;

        case CRYPTO_S_MSG_TYPE_INDEX_SHA2:
            status = SHA2_s_handlePsaMsg(msg);
            break;

        case CRYPTO_S_MSG_TYPE_INDEX_TRNG:
            status = TRNG_s_handlePsaMsg(msg);
            break;

        default:
            /* Unknown msg type - do nothing */
            break;
    }

    return status;
}

#define HWREG(x) (*((volatile unsigned long *)(x))) // BQ - temp code

/*
 *  ======== Crypto_sp_main ========
 *  Crypto Secure Partition entry point
 */
void Crypto_sp_main(void *param)
{
    uint32_t signals;
    psa_msg_t msg;

    // BQ - temporary code to force power and clocks on.
    // Periph power
    HWREG(0x5808212C) |= 0x00000004;
    // Force PKA, TRNG, and Crypto clocks
    HWREG(0x5808203C) |= 0x00070000;
    // Load clocks
    HWREG(0x58082028) = 0x00000001;

    /* Initialize all secure crypto drivers */
    AESCBC_s_init();
    AESCCM_s_init();
    AESCMAC_s_init();
    AESCTR_s_init();
    AESECB_s_init();
    AESGCM_s_init();

    AESCTRDRBG_s_init();

    ECDH_s_init();
    //    ECDSA_s_init();
    //    EDDSA_s_init();
    //    ECJPAKE_s_init();

    SHA2_s_init();
    TRNG_s_init();

    while (1)
    {
        signals = psa_wait(PSA_WAIT_ANY, PSA_BLOCK);

        /*
         * Signals corresponding to interrupts are defined in the
         * secure partition's YAML file.
         */
        if (signals & CryptoResultAvail_IRQn_SIGNAL)
        {
            HwiP_dispatchInterrupt(INT_CRYPTO_RESULT_AVAIL_IRQ);
            psa_eoi(CryptoResultAvail_IRQn_SIGNAL);
        }
        else if (signals & PKA_IRQn_SIGNAL)
        {
            HwiP_dispatchInterrupt(INT_PKA_IRQ);
            psa_eoi_no_irq_en(PKA_IRQn_SIGNAL);
        }
        else if (signals & TRNG_IRQn_SIGNAL)
        {
            HwiP_dispatchInterrupt(INT_TRNG_IRQ);
            psa_eoi(TRNG_IRQn_SIGNAL);
        }
        else if (signals & CRYPTO_SP_SERVICE_SIGNAL)
        {
            psa_get(CRYPTO_SP_SERVICE_SIGNAL, &msg);

            switch (msg.type)
            {
                case PSA_IPC_CONNECT:
                    /* This partition supports multiple simultaneous connections */
                    psa_reply(msg.handle, PSA_SUCCESS);
                    break;

                case PSA_IPC_DISCONNECT:
                    psa_reply(msg.handle, PSA_SUCCESS);
                    break;

                default:
                    if (msg.type >= 0)
                    {
                        psa_reply(msg.handle, Crypto_s_handlePsaMsg(&msg));
                    }
                    else
                    {
                        psa_reply(msg.handle, PSA_ERROR_PROGRAMMER_ERROR);
                    }
                    break;
            }
        }
    }

    return;
}

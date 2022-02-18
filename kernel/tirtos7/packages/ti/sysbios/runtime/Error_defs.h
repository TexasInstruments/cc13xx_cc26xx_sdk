/*
 * Copyright (c) 2020, Texas Instruments Incorporated
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

/*
 * ======== Error_defs.h ========
 */

/* @cond LONG_NAMES */

#ifdef ti_sysbios_runtime_Error_long_names

#define Error_Block ti_sysbios_runtime_Error_Block
#define Error_HookFxn ti_sysbios_runtime_Error_HookFxn
#define Error_ignore ti_sysbios_runtime_Error_ignore
#define Error_check ti_sysbios_runtime_Error_check
#define Error_init ti_sysbios_runtime_Error_init
#define Error_print ti_sysbios_runtime_Error_print
#define Error_raiseX ti_sysbios_runtime_Error_raiseX
#define Error_raiseHook ti_sysbios_runtime_Error_raiseHook

#endif

#if defined(ti_sysbios_runtime_Error__nolocalnames) && !defined(ti_sysbios_runtime_Error_long_names)

#undef Error_Block
#undef Error_HookFxn
#undef Error_ignore
#undef Error_check
#undef Error_init
#undef Error_print
#undef Error_raiseX
#undef Error_raiseHook

#endif

/* @endcond */

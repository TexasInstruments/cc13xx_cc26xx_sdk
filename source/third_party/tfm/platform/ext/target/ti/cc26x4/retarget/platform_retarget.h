/*
 * Copyright (c) 2019-2020 Texas Instruments Incorporated
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * \file platform_retarget.h
 * \brief This file defines all the peripheral base addresses for CC26X4 platform.
 */

#ifndef __CC26X4_RETARGET_H__
#define __CC26X4_RETARGET_H__

#include "cmsis.h"
#include "flash_layout.h"
/* TI CC13x4/CC26x4 SDK include(s) */
#include "ti/devices/cc13x4_cc26x4/inc/hw_memmap.h"

/* ======= Defines peripherals memory map addresses ======= */
/* Non-secure memory map addresses */
#define UART0_BASE_NS          UART0_BASE
#define UART0_BASE_S           UART0_BASE

#endif  /* __CC26X4_RETARGET_H__ */

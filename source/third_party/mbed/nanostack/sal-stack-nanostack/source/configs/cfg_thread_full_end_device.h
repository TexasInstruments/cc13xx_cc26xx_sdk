/*
 * Copyright (c) 2016, 2018, Arm Limited and affiliates.
 * SPDX-License-Identifier: Apache-2.0
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

#include "base/cfg_thread_full_end_device.h"

/* Code optimization for Router advertisement */
#define NO_RADV_TX

/* Full end device needs parts from the router code to make links*/
#define HAVE_THREAD_ROUTER

/* Code optimization - removing TCP */
#define NO_TCP

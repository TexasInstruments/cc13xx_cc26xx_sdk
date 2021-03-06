/*
 * Copyright (c) 2016, Texas Instruments Incorporated
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
 *
 *                          @@@@@@@@@@@@@@@@@@@@@@@
 *                          @@@@@@@@@@@@@@@@@@@@@@@
 *                          @@@@@@@@@@@@@@@@@@@@@@@
 *                          @@@@@@@@@@@@@@@@@@@@@@@
 *                          @@@@@@@@@@@@@@@@@@@@@@@
 *                          @@@@@@@@@@@@@@@@@@@@@@@             @@@@@@@@@
 *                          @@@@@@@@@@@@@@@@@@@@@@@             @@@@@@@@@
 *                          @@@@@@@@@@@@@@@@@@@@@@@             @@@@@@@@@
 *                          @@@@@@@@@@@@@@@@@@@@@@@            @@@@@@@@@@
 *                          @@@@@@@@@@@@@@@@@@@@@@@            @@@@@@@@@@
 *                          @@@@@@@@@@@@@@@@@@@@@@@            @@@@@@@@@
 *                          @@@@@@@@@@@@@@@@@@@@@@@            @@@@@@@@@
 *                          @@@@@@@@@@@@@@@@@@@@@@@            @@@@@@@@@
 *                          @@@@@@@@@@@@@@@@@@@@@@@           @@@@@@@@@@
 *                          @@@@@@@@@@@@@@@@@@@@@@@
 *                          @@@@@@@@@@@@@@@@@@@@@@@
 *                          @@@@@@@@@@@@@@@@@@@@@@@
 *                          @@@@@@@@@@@@@@@@@@@@@@@
 *                          @@@@@@@@@@@@@@@@@@@@@@@@@@@@@     @@@@@@@@@    @@@@@@@@@@@@@@@@@@@
 *                          @@@@@@@@@@@@@@@@@@@@@@@@@@@@@    @@@@@@@@@@    @@@@@@@@@@@@@@@@@@@
 *                          @@@@@@@@@@@@@@@@@@@@@@@@@@@@@    @@@@@@@@@    @@@@@@@@@@@@@@@@@@@@
 *                          @@@@@@@@@@@@@@@@@@@@@@@@@@@@@    @@@@@@@@@    @@@@@@@@@@@@@@@@@@@@
 *                          @@@@@@@@@@@@@@@@@@@@@@@@@@@@@    @@@@@@@@@    @@@@@@@@@@@@@@@@@@@@
 *                          @@@@@@@@@@@@@@@@@@@@@@@@@@@@     @@@@@@@@@    @@@@@@@@@@@@@@@@@@@@
 *                          @@@@@@@@@@@@@@@@@@@@@@@@@@@@    @@@@@@@@@@    @@@@@@@@@@@@@@@@@@@@
 *                          @@@@@@@@@@@@@@@@@@@@@@@@@@@@    @@@@@@@@@    @@@@@@@@@@@@@@@@@@@@@
 *                          @@@@@@@@@@@@@@@@@@@@@@@@@@@@    @@@@@@@@@    @@@@@@@@@@@@@@@@@@@@@
 *                          @@@@@@@@@@@@@@@@@@@@@@@@@@@     @@@@@@@@@    @@@@@@@@@@@@@@@@@@@@@
 *                          @@@@@@@@@@@@@@@@@@@@@@@@@@@    @@@@@@@@@@    @@@@@@@@@@@@@@@@@@@@@
 *                          @@@@@@@@@@@@@@@@@@@@@@@@@@@    @@@@@@@@@@    @@@@@@@@@@@@@@@@@@@@@
 *                          @@@@@@@@@@@@@@@@@@@@           @@@@@@@@@@          @@@@@@@@@@@@@@@
 *                          @@@@@@@@@@@@@@@@@@@@           @@@@@@@@@           @@@@@@@@@@@@@@@
 *                          @@@@@@@@@@@@@@@@@@@@           @@@@@@@@@           @@@@@@@@@@@@@@@
 *                          @@@@@@@@@@@@@@@@@@@@          @@@@@@@@@@           @@@@@@@@@@@@@@@@
 *                          @@@@@@@@@@@@@@@@@@@@          @@@@@@@@@@           @@@@@@@@@@@@@@@@
 *                          @@@@@@@@@@@@@@@@@@@           @@@@@@@@@@          @@@@@@@@@@@@@@@@@
 *                          @@@@@@@@@@@@@@@@@@@           @@@@@@@@@           @@@@@@@@@@@@@@@@@@
 * @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@           @@@@@@@@@           @@@@@@@@@@@@@@@@@@
 * @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@           @@@@@@@@@           @@@@@@@@@@@@@@@@@@@
 * @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@           @@@@@@@@@@           @@@@@@@@@@@@@@@@@@@@
 * @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@           @@@@@@@@@           @@@@@@@@@@@@@@@@@@@@@@
 * @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    @@@@@@@@@    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 * @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@     @@@@@@@@@    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 * @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@     @@@@@@@@@    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 * @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    @@@@@@@@@@    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 *  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    @@@@@@@@@    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 *   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    @@@@@@@@@    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 *    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@     @@@@@@@@@    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 *     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    @@@@@@@@@@    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 *       @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    @@@@@@@@@@    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 *        @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    @@@@@@@@@@    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 *        @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    @@@@@@@@@    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 *         @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    @@@@@@@@@    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 *          @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@     @@@@@@@@@    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 *           @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    @@@@@@@@@@    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 *           @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    @@@@@@@@@    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 *            @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    @@@@@@@@@    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 *            @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    @@@@@@@@@    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 *            @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@     @@@@@@@@@     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 *             @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                         @@@@@@@@@@@@@@@@@@@@@@@@@
 *             @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                        @@@@@@@@@@@@@@@@@@@@@@@@@@
 *              @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                        @@@@@@@@@@@@@@@@@@@@@@@
 *              @@@@@@@@@@@@@@@      @@@@@@@@@@@                         @@@@@@@@@@@@@@@@@@@@
 *               @@@@@@@@@@@@         @@@@@@@@@@                         @@@@@@@@@@@@@@@@@
 *               @@@@@@@@@@@           @@@@@@@@@                        @@@@@@@@@@@@@@@@
 *                @@@@@@@@@@           @@@@@@@@@                        @@@@@@@@@@@@@@
 *                 @@@@@@@@             @@@@@@@@@                       @@@@@@@@@@@@
 *                   @@@@                @@@@@@@@                       @@@@@@@@@@@
 *                                       @@@@@@@@@                      @@@@@@@@@@
 *                                        @@@@@@@@@                     @@@@@@@@
 *                                        @@@@@@@@@@@@@                @@@@@@@@
 *                                         @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 *                                         @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 *                                          @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 *                                          @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 *                                           @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 *                                           @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 *                                           @@@@@@@@@@@@@@@@@@@@@@@@@@@@
 *                                            @@@@@@@@@@@@@@@@@@@@@@@@@@@
 *                                             @@@@@@@@@@@@@@@@@@@@@@@@@
 *                                             @@@@@@@@@@@@@@@@@@@@@@@@@
 *                                              @@@@@@@@@@@@@@@@@@@@@@@@
 *                                              @@@@@@@@@@@@@@@@@@@@@@@
 *                                               @@@@@@@@@@@@@@@@@@@@@@
 *                                               @@@@@@@@@@@@@@@@@@@@@@
 *                                                @@@@@@@@@@@@@@@@@@@@@
 *                                                 @@@@@@@@@@@@@@@@@@@@
 *                                                 @@@@@@@@@@@@@@@@@@@@
 *                                                  @@@@@@@@@@@@@@@@@@@
 *                                                   @@@@@@@@@@@@@@@@@@
 *                                                    @@@@@@@@@@@@@@@@@@
 *                                                     @@@@@@@@@@@@@@@@@
 *                                                      @@@@@@@@@@@@@@@@
 *                                                        @@@@@@@@@@@@@@
 *                                                          @@@@@@@@@@@@@
 *                                                            @@@@@@@@@
 */

#include <ti/grlib/grlib.h>

uint32_t imgPalette[] = {0, 0xFFFFFF};

const uint8_t imgData[402] = {
    0x33, 0x2C, 0x91, 0x2C, 0x91, 0x2C, 0x91, 0x2C, 0x91, 0x2C, 0x91, 0x2C, 0x19, 0x10, 0x65, 0x2C, 0x19, 0x10, 0x65,
    0x2C, 0x19, 0x10, 0x65, 0x2C, 0x17, 0x12, 0x65, 0x2C, 0x17, 0x12, 0x65, 0x2C, 0x17, 0x10, 0x67, 0x2C, 0x17, 0x10,
    0x67, 0x2C, 0x17, 0x10, 0x67, 0x2C, 0x15, 0x12, 0x67, 0x2C, 0x91, 0x2C, 0x91, 0x2C, 0x91, 0x2C, 0x91, 0x38, 0x09,
    0x10, 0x07, 0x24, 0x3B, 0x38, 0x07, 0x12, 0x07, 0x24, 0x3B, 0x38, 0x07, 0x10, 0x07, 0x26, 0x3B, 0x38, 0x07, 0x10,
    0x07, 0x26, 0x3B, 0x38, 0x07, 0x10, 0x07, 0x26, 0x3B, 0x36, 0x09, 0x10, 0x07, 0x26, 0x3B, 0x36, 0x07, 0x12, 0x07,
    0x26, 0x3B, 0x36, 0x07, 0x10, 0x07, 0x28, 0x3B, 0x36, 0x07, 0x10, 0x07, 0x28, 0x3B, 0x34, 0x09, 0x10, 0x07, 0x28,
    0x3B, 0x34, 0x07, 0x12, 0x07, 0x28, 0x3B, 0x34, 0x07, 0x12, 0x07, 0x28, 0x3B, 0x26, 0x15, 0x12, 0x13, 0x1C, 0x3B,
    0x26, 0x15, 0x10, 0x15, 0x1C, 0x3B, 0x26, 0x15, 0x10, 0x15, 0x1C, 0x3B, 0x26, 0x13, 0x12, 0x15, 0x1E, 0x39, 0x26,
    0x13, 0x12, 0x15, 0x1E, 0x39, 0x24, 0x15, 0x12, 0x13, 0x20, 0x39, 0x24, 0x15, 0x10, 0x15, 0x22, 0x05, 0x56, 0x15,
    0x10, 0x15, 0x22, 0x05, 0x56, 0x15, 0x10, 0x15, 0x24, 0x03, 0x54, 0x15, 0x12, 0x15, 0x26, 0x01, 0x54, 0x15, 0x10,
    0x15, 0x8E, 0x07, 0x10, 0x07, 0x9A, 0x09, 0x10, 0x07, 0x9A, 0x09, 0x10, 0x07, 0x9A, 0x07, 0x12, 0x07, 0x38, 0x01,
    0x5E, 0x07, 0x10, 0x07, 0x3A, 0x03, 0x5C, 0x07, 0x10, 0x07, 0x3A, 0x05, 0x58, 0x09, 0x10, 0x07, 0x3A, 0x07, 0x56,
    0x07, 0x12, 0x07, 0x3A, 0x0B, 0x52, 0x07, 0x12, 0x07, 0x3A, 0x0D, 0x50, 0x07, 0x12, 0x07, 0x3A, 0x0D, 0x50, 0x07,
    0x10, 0x07, 0x3C, 0x0F, 0x4E, 0x07, 0x10, 0x07, 0x3C, 0x11, 0x4A, 0x09, 0x10, 0x07, 0x3C, 0x13, 0x48, 0x07, 0x12,
    0x07, 0x3C, 0x13, 0x48, 0x07, 0x10, 0x07, 0x3E, 0x15, 0x46, 0x07, 0x10, 0x07, 0x3E, 0x15, 0x46, 0x07, 0x10, 0x07,
    0x3E, 0x15, 0x44, 0x09, 0x10, 0x09, 0x3C, 0x17, 0x42, 0x31, 0x30, 0x17, 0x42, 0x2F, 0x32, 0x19, 0x40, 0x2F, 0x2C,
    0x1F, 0x1C, 0x0B, 0x14, 0x31, 0x26, 0x27, 0x16, 0x11, 0x12, 0x31, 0x20, 0x2D, 0x14, 0x15, 0x10, 0x2F, 0x1E, 0x33,
    0x12, 0x15, 0x10, 0x2F, 0x1A, 0x39, 0x0E, 0x19, 0x10, 0x2D, 0x16, 0x41, 0x06, 0x1F, 0x0E, 0x2D, 0x14, 0x6B, 0x10,
    0x2B, 0x12, 0x6F, 0x10, 0x29, 0x0E, 0x73, 0x18, 0x1F, 0x0E, 0x77, 0x44, 0x79, 0x42, 0x7D, 0x3E, 0x7F, 0x3C, 0x83,
    0x3A, 0x83, 0x38, 0x85, 0x36, 0x89, 0x34, 0x8B, 0x30, 0x8D, 0x30, 0x8F, 0x2E, 0x8F, 0x2C, 0x93, 0x2A, 0x93, 0x2A,
    0x95, 0x28, 0x97, 0x26, 0x97, 0x26, 0x99, 0x24, 0x9B, 0x22, 0x9D, 0x22, 0x9D, 0x20, 0x9F, 0x1E, 0xA3, 0x1A, 0xA7,
    0x18, 0xA9, 0x10,
};

const Graphics_Image splashImage = {.bPP       = IMAGE_FMT_1BPP_COMP_RLE7,
                                    .numColors = 2,
                                    .xSize     = 96,
                                    .ySize     = 96,
                                    .pPalette  = imgPalette,
                                    .pPixel    = imgData};

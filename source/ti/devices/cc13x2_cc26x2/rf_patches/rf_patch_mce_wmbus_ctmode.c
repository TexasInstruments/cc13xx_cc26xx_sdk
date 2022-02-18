/******************************************************************************
*  Filename:       rf_patch_mce_wmbus_ctmode.h
*
*  Description: RF core patch for CC13x2 WMBUS C- and T-Mode
*
*  Copyright (c) 2015-2020, Texas Instruments Incorporated
*  All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions are met:
*
*  1) Redistributions of source code must retain the above copyright notice,
*     this list of conditions and the following disclaimer.
*
*  2) Redistributions in binary form must reproduce the above copyright notice,
*     this list of conditions and the following disclaimer in the documentation
*     and/or other materials provided with the distribution.
*
*  3) Neither the name of the ORGANIZATION nor the names of its contributors may
*     be used to endorse or promote products derived from this software without
*     specific prior written permission.
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
*
******************************************************************************/

#include <stdint.h>
#include "rf_patch_mce_wmbus_ctmode.h"
#include <ti/devices/DeviceFamily.h>
#include DeviceFamily_constructPath(inc/hw_types.h)

#ifndef MCE_PATCH_TYPE
#define MCE_PATCH_TYPE static const uint32_t
#endif

#ifndef PATCH_FUN_SPEC
#define PATCH_FUN_SPEC
#endif

#ifndef RFC_MCERAM_BASE
#define RFC_MCERAM_BASE 0x21008000
#endif

#ifndef MCE_PATCH_MODE
#define MCE_PATCH_MODE 0
#endif

MCE_PATCH_TYPE patchWmbusCtmodeMce[500] = {
   0x2fcf60af,
   0xed0c3f9d,
   0x0acc0666,
   0x00ffabc2,
   0x003f0fff,
   0x05105555,
   0x002a0514,
   0x00042abc,
   0x00310018,
   0x00610047,
   0x0092007a,
   0x00ba00a8,
   0x00d000c7,
   0x00d600d4,
   0x001f0045,
   0x00e800f8,
   0x00c000d0,
   0x008800a8,
   0x00600078,
   0x00440057,
   0x00180031,
   0x00250004,
   0x05b205a2,
   0x05d305c3,
   0x05f405e3,
   0x06140604,
   0x06350625,
   0x06560646,
   0x06770666,
   0x06980687,
   0x06b806a8,
   0x06c906b8,
   0x06e906d9,
   0x070a06fa,
   0x0016071b,
   0x001c002c,
   0x000e0034,
   0x001a0026,
   0x000d0032,
   0x00190025,
   0x000b0031,
   0x00130023,
   0x00060029,
   0x0006000e,
   0x0002000e,
   0x00040008,
   0x0006000e,
   0x0006000a,
   0x0002000c,
   0x00040008,
   0x0006000c,
   0x0006000e,
   0x0002000e,
   0x0000000e,
   0x0006000e,
   0x0006000a,
   0x0002000e,
   0x0006000a,
   0x0007000e,
   0x0007000f,
   0x0003000d,
   0x00050009,
   0x0001000d,
   0x0007000f,
   0x0001000f,
   0x0005000f,
   0x0007000f,
   0x0007000b,
   0x0003000b,
   0x0007000b,
   0x0007000b,
   0x0007000f,
   0x0003000f,
   0x0007000f,
   0x0003000f,
   0x3d1f0007,
   0x00000000,
   0x000f0400,
   0x03840000,
   0x00f4000b,
   0x80000043,
   0x00280001,
   0x00000670,
   0x0514091e,
   0x00000004,
   0x44110200,
   0x0000006b,
   0x7223842f,
   0xa35d7263,
   0x7303a4e5,
   0x72037305,
   0x73067304,
   0x73917204,
   0xb0087291,
   0x9010ffc0,
   0x720da008,
   0x720f720e,
   0xb0d07210,
   0xb1107100,
   0x721ba0d0,
   0x10208162,
   0x06703952,
   0x16300020,
   0x14011101,
   0x60e36c01,
   0x614f60e4,
   0x60e361a3,
   0x60e360e3,
   0x121060e3,
   0x73117223,
   0x73137312,
   0x001081b1,
   0xb07091b0,
   0x60d960c3,
   0xc2b2c951,
   0x1820c440,
   0x6e236f13,
   0x16121611,
   0xc4f268e8,
   0x1820c750,
   0x120340f5,
   0x16126e23,
   0x72ca68f2,
   0x95c078e0,
   0x819060d9,
   0x81709640,
   0x2a703980,
   0x16111001,
   0x84b484a2,
   0xc0f5c0f3,
   0x1c01c200,
   0xc100411d,
   0x41131c10,
   0x10134d15,
   0x18301803,
   0x1a101a13,
   0x69103912,
   0x13f3611d,
   0x13f3611d,
   0xc1001015,
   0x1a151850,
   0x39141a10,
   0xb0e8691b,
   0xb1287100,
   0xb230a0e8,
   0xb003b630,
   0xb002b013,
   0x722cb012,
   0x7100b0e0,
   0x8170b120,
   0x710092c0,
   0x8170b120,
   0x452d22f0,
   0x1c0313f0,
   0x92c34139,
   0x71009642,
   0x92c5b120,
   0x71009644,
   0xb0e0b120,
   0x7000a630,
   0xc030a0e1,
   0xc0409910,
   0xb1119930,
   0x7100b0d1,
   0xa0d1b111,
   0xa0037291,
   0xa230a002,
   0x73117000,
   0x8ca17312,
   0x39613981,
   0xd0300611,
   0x67e29a11,
   0x91f0c100,
   0x8ca064f9,
   0x458422e0,
   0xb113b633,
   0xb634b0d3,
   0x91f0c030,
   0xb0e1b121,
   0x22d58ca5,
   0x12f5416a,
   0x22308090,
   0x81d0457f,
   0xc4510850,
   0x6f121401,
   0x2252c063,
   0x12114177,
   0x13f16178,
   0xb12192f1,
   0x31127100,
   0x45731a13,
   0xa0e1616a,
   0xa0d3b121,
   0x60d96540,
   0xb630b0e0,
   0x92c0c070,
   0x964078d0,
   0x7100b120,
   0xa0e0b120,
   0xb633a630,
   0xb0d3b113,
   0xa0d37100,
   0x60d96540,
   0xd04087c1,
   0x67e29a11,
   0x72917391,
   0x72067263,
   0x72047202,
   0x73067305,
   0x123060d9,
   0x78c091e0,
   0xb35d93d0,
   0x7830b63c,
   0xb1189310,
   0xb016b006,
   0xb014b004,
   0xb012b002,
   0x90307810,
   0x78209050,
   0x90609040,
   0x7293b445,
   0x72707291,
   0x93308cb0,
   0x93f0c030,
   0xb064b069,
   0xb116b089,
   0xb111a0d6,
   0xb112a0d1,
   0xb636b0d2,
   0x78ac786e,
   0xc00a67d3,
   0x13fb13ff,
   0x9930c1b0,
   0x9910c020,
   0x78ad7888,
   0xc024048d,
   0xc006c005,
   0xb112b235,
   0xba3d7100,
   0x46151e2a,
   0x39708cc0,
   0x140b311b,
   0x1ccb8240,
   0x222045e9,
   0x22204624,
   0xb91041ed,
   0xa91061ef,
   0x8ce0b111,
   0x08018cf1,
   0x41f82271,
   0x31163315,
   0x61dbc00a,
   0x41f41e3a,
   0x61db161a,
   0x22208240,
   0xb9104201,
   0xa9106203,
   0x8ce0b111,
   0x08018cf1,
   0x42112271,
   0x460d1e0a,
   0x33163115,
   0x3115620f,
   0xc00a3116,
   0x1e3a61db,
   0x161a420f,
   0x809061db,
   0x41fc2210,
   0x22c08ca0,
   0x10b14624,
   0x08d10481,
   0x89819971,
   0x4e031c41,
   0x67e2c050,
   0x72917293,
   0xb111a0d1,
   0xb231b3f2,
   0x99753135,
   0x3136898a,
   0x89899976,
   0x97aa189a,
   0x8af0ba39,
   0x3d803180,
   0x3d201620,
   0x1c80c0b8,
   0x12014fde,
   0x1c101881,
   0x8cb84be0,
   0xc1501808,
   0x1e4187a1,
   0xc0614a47,
   0xc00b1810,
   0x6727c00c,
   0x79da79c9,
   0xc10010a8,
   0x87a11808,
   0x4e5b1e11,
   0x46641e01,
   0x4e6418b9,
   0x10c510b5,
   0x4a641ca5,
   0x1a89626d,
   0x18b9108a,
   0x10b54e7d,
   0x1ca518c5,
   0x626d4a7d,
   0x18c07ab0,
   0x10c54e7d,
   0xc00018b5,
   0x4a7d1c05,
   0xc0fc6275,
   0x670ac0d0,
   0x1ac510d5,
   0x185d120d,
   0x10cb627f,
   0xc0d0c1ec,
   0x10d5670a,
   0x185d120d,
   0xc00d627f,
   0xa636627f,
   0x67b4a790,
   0xc00ac00b,
   0xc007c006,
   0x8ca0c009,
   0x468b22d0,
   0x78787899,
   0x78ad048e,
   0xc010048d,
   0xb9149930,
   0x9910c2b0,
   0xb111b116,
   0xb089b069,
   0x7100b112,
   0x1e2aba3d,
   0x8cc046a5,
   0x311b3970,
   0x048b140b,
   0x42c91ceb,
   0x809062b5,
   0x46ab2260,
   0x46c02210,
   0xc03062b1,
   0xb1169910,
   0xc1c0b111,
   0x1cdb9930,
   0xa91046b5,
   0x8ce0b910,
   0x08018cf1,
   0x42bc2271,
   0x62bf120a,
   0x42ba1e3a,
   0x6298161a,
   0xc0607223,
   0x7100b112,
   0x87b16ac2,
   0x97b11611,
   0xba3961b8,
   0x161a7291,
   0xc00b78d4,
   0xb074c00e,
   0xb112b133,
   0xba3d7100,
   0x46e21e2a,
   0x39708cc0,
   0x140b311b,
   0x1e6e161e,
   0x1c4b46f7,
   0xc0164342,
   0x62f7c00e,
   0x42ec1066,
   0x089bc550,
   0x6f0114b0,
   0xc00691c1,
   0x62f7c017,
   0x42f71077,
   0xc00b164f,
   0x8180c007,
   0x42f71e00,
   0x4ef71cf0,
   0x8ce06302,
   0x08018cf1,
   0x42fe2271,
   0x62d1c00a,
   0x42fc1e3a,
   0x62d1161a,
   0xa0d2a235,
   0xa0d1b112,
   0xb133b111,
   0x619667d3,
   0xc0011a10,
   0x6fcdc0c2,
   0x10b3161c,
   0x1051671f,
   0x6fcd1a10,
   0x671f161c,
   0x4b1a1c15,
   0x631d6b13,
   0x10021051,
   0x102d6b13,
   0x1cd37000,
   0x10354b24,
   0x700018d5,
   0x183510d5,
   0xb1127000,
   0xba3e7100,
   0x10128ac1,
   0x12014f2f,
   0x31311821,
   0x4f331c1b,
   0x8ad1101b,
   0x4f381012,
   0x18211201,
   0x1c1c3131,
   0x101c4f3c,
   0x1c20c172,
   0x93384f40,
   0x70006b27,
   0x7291b133,
   0x9930c070,
   0x78b09910,
   0x67d393d0,
   0x7100b112,
   0x223080b0,
   0x80904753,
   0x47532210,
   0xb073634a,
   0xa932a910,
   0x727cb910,
   0x1a11c001,
   0x435f1c1f,
   0x1cf0c040,
   0xb0114b60,
   0x31808af0,
   0x97003d80,
   0x8c618c50,
   0xa637a638,
   0x1801c022,
   0x4f741c21,
   0x4b721412,
   0x1c016375,
   0x4f744375,
   0x6375b637,
   0xa04eb638,
   0xb061b041,
   0xb133b790,
   0x223080b0,
   0xb0d14779,
   0xa0d2b111,
   0xb133b112,
   0xb04e7100,
   0xc090a910,
   0x99303120,
   0x91e01300,
   0xb111b910,
   0x72917100,
   0xb0d6b116,
   0xa0d1b111,
   0x1a101200,
   0xc3809930,
   0xc2809910,
   0x80909910,
   0x44c32200,
   0x1e048184,
   0x99344399,
   0x8940b116,
   0x1c018931,
   0x18014bb1,
   0x4baf1ef1,
   0x1af18931,
   0x71009931,
   0x16f1b116,
   0xa2359931,
   0xb1167100,
   0x6196a0d6,
   0xc2c197cd,
   0x141d16c1,
   0x101d6fd1,
   0x83103151,
   0xc1f23980,
   0x14010420,
   0x836298d1,
   0x06711021,
   0x06323952,
   0x16311421,
   0x3010c1b0,
   0xc07098e0,
   0x930d6bcc,
   0x965088f0,
   0x96608900,
   0x89907000,
   0x47d81e00,
   0x99908650,
   0x78409650,
   0x78509300,
   0x70009660,
   0x623f1080,
   0x623f1010,
   0x89f09a00,
   0x47e32200,
   0x7000b9e0
};

PATCH_FUN_SPEC void rf_patch_mce_wmbus_ctmode(void)
{
#ifdef __PATCH_NO_UNROLLING
   uint32_t i;
   for (i = 0; i < 500; i++) {
      HWREG(RFC_MCERAM_BASE + 4 * i) = patchWmbusCtmodeMce[i];
   }
#else
   const uint32_t *pS = patchWmbusCtmodeMce;
   volatile unsigned long *pD = &HWREG(RFC_MCERAM_BASE);
   uint32_t t1, t2, t3, t4, t5, t6, t7, t8;
   uint32_t nIterations = 62;

   do {
      t1 = *pS++;
      t2 = *pS++;
      t3 = *pS++;
      t4 = *pS++;
      t5 = *pS++;
      t6 = *pS++;
      t7 = *pS++;
      t8 = *pS++;
      *pD++ = t1;
      *pD++ = t2;
      *pD++ = t3;
      *pD++ = t4;
      *pD++ = t5;
      *pD++ = t6;
      *pD++ = t7;
      *pD++ = t8;
   } while (--nIterations);

   t1 = *pS++;
   t2 = *pS++;
   t3 = *pS++;
   t4 = *pS++;
   *pD++ = t1;
   *pD++ = t2;
   *pD++ = t3;
   *pD++ = t4;
#endif
}

/******************************************************************************
*  Filename:       rf_patch_cpe_multi_bt5_coex.c
*
*  Description: RF core patch for coexistence support for Bluetooth 5 ("BLE" and "BLE5" API command sets) in CC13x2 and CC26x2
*
*  Copyright (c) 2015-2021, Texas Instruments Incorporated
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
//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include <string.h>

#include "rf_patch_cpe_multi_bt5_coex.h"

#ifndef CPE_PATCH_TYPE
#define CPE_PATCH_TYPE static const uint32_t
#endif

#ifndef SYS_PATCH_TYPE
#define SYS_PATCH_TYPE static const uint32_t
#endif

#ifndef PATCH_FUN_SPEC
#define PATCH_FUN_SPEC static
#endif

#ifndef _APPLY_PATCH_TAB
#define _APPLY_PATCH_TAB
#endif


CPE_PATCH_TYPE patchImageMultiBt5Coex[] = {
   0x210044b1,
   0x210040a5,
   0x210040c1,
   0x2100412b,
   0x210040ed,
   0x21004525,
   0x21004561,
   0x2100415d,
   0x21004169,
   0x21004175,
   0x21004191,
   0x2100460b,
   0x210041d9,
   0x210041f1,
   0x210047c3,
   0x21004865,
   0x21004afb,
   0x2100508b,
   0x2100541d,
   0x21004b49,
   0x21004215,
   0x21005617,
   0xd00507db,
   0xf803f000,
   0x70084902,
   0xb570bd70,
   0x47284d01,
   0x210004e0,
   0x0002241d,
   0x79654c07,
   0xf809f000,
   0x40697961,
   0xd5030749,
   0x4a042101,
   0x60110389,
   0xb570bd70,
   0x47084902,
   0x21000380,
   0x40041108,
   0x0000592d,
   0xf819f000,
   0x296cb2e1,
   0x2804d00b,
   0x2806d001,
   0x4910d107,
   0x07c97809,
   0x7821d103,
   0xd4000709,
   0x490d2002,
   0x210c780a,
   0xd0024211,
   0x2280490b,
   0xb003600a,
   0xb5f0bdf0,
   0x4909b083,
   0x20004708,
   0x47884908,
   0x78014804,
   0x43912240,
   0x48067001,
   0x00004700,
   0x210000c8,
   0x21000133,
   0xe000e200,
   0x00031641,
   0x000063f7,
   0x00031b23,
   0x4700b570,
   0xfa28f000,
   0x47004800,
   0x00007f57,
   0xfa28f000,
   0x47004800,
   0x0000881b,
   0x0a889905,
   0xd1052880,
   0x78884913,
   0x0f800780,
   0xfa32f000,
   0x47004800,
   0x00006ed9,
   0x480fb40f,
   0x290088c1,
   0x4610d002,
   0xfa26f000,
   0x0a9b9b07,
   0x2b834d08,
   0x4c08d108,
   0x069b8923,
   0xf000d504,
   0x2800f805,
   0x3542d000,
   0x4728bc0f,
   0x4804b570,
   0x00004700,
   0x00020b1f,
   0x21000160,
   0x21000380,
   0x000209eb,
   0x781a4b09,
   0x43a22408,
   0xd0002800,
   0x701a4322,
   0x47104a00,
   0x00008e83,
   0x78084903,
   0xd4010700,
   0x47004802,
   0x00004770,
   0x21000380,
   0x00007e5f,
   0xb081b5f3,
   0xb5f84710,
   0x00004700,
   0x20284a04,
   0x48044790,
   0x60412101,
   0x4a044803,
   0x47106041,
   0x0000424f,
   0x40045000,
   0x40046000,
   0x00004285,
   0x4d1fb570,
   0xb2c47828,
   0x4780481e,
   0x28037828,
   0x2c03d134,
   0x481cd032,
   0x0d406880,
   0x481a07c2,
   0x31604601,
   0x2a003080,
   0x241fd003,
   0x8845570c,
   0x241ee002,
   0x8805570c,
   0xd01f2c00,
   0x4a154813,
   0x79006941,
   0x10484341,
   0x69494911,
   0x49101840,
   0x7f493940,
   0x05404790,
   0x42691540,
   0xdb0d4288,
   0xdc0b42a8,
   0x69994b0c,
   0x4602b288,
   0x43620c09,
   0x12520409,
   0xb2801880,
   0x61984308,
   0x0000bd70,
   0x210002e4,
   0x00004179,
   0x21000028,
   0x21000380,
   0x21000300,
   0x000081cb,
   0x40044040,
   0x4c86b510,
   0x31404621,
   0x28017d08,
   0x4884d134,
   0x08407dc0,
   0xd02f07c0,
   0x30604620,
   0x08527942,
   0xd02907d2,
   0x0b808940,
   0xd1252801,
   0x09417e08,
   0xd00c07c9,
   0x07006fa1,
   0x0fc08809,
   0x04090240,
   0x66604308,
   0x1c806fa0,
   0xf9b8f001,
   0x4874e013,
   0x69803020,
   0x28006840,
   0x4a72d00e,
   0x78012300,
   0x1a5956d3,
   0x00c9d408,
   0x78411808,
   0xd00307c9,
   0x66616801,
   0x66a06840,
   0x4780486b,
   0xb5f8bd10,
   0x496a4c66,
   0x36204626,
   0x46257b70,
   0x90003540,
   0x00b8792f,
   0x68801840,
   0x28004780,
   0x4960d128,
   0x09097dc9,
   0xd02307c9,
   0x32644622,
   0xd0202f15,
   0x23007e29,
   0x07ff094f,
   0x7d6dd003,
   0xd0002d00,
   0x9f002301,
   0x43bb6fa5,
   0x7b73d012,
   0xd00f2b00,
   0x065b7d23,
   0x88d2d50c,
   0x2a010b92,
   0x08c9d108,
   0xd00507c9,
   0x0b8988a9,
   0xd1012901,
   0x73712100,
   0x7eabbdf8,
   0x2b017de9,
   0x2300d0e3,
   0xb570e7e1,
   0x46254c46,
   0x35806a60,
   0xd11d2800,
   0x5d002054,
   0x28002200,
   0x2064d017,
   0x08805d00,
   0xd01207c0,
   0x888868a9,
   0x28010b80,
   0x483dd10d,
   0x08407dc0,
   0xd00807c0,
   0x3020483a,
   0x68006980,
   0xd0022800,
   0x60a86229,
   0x622ae000,
   0x47804839,
   0x29006a61,
   0x6a29d103,
   0xd0002900,
   0xbd7060a9,
   0x4c2fb5f8,
   0x46204934,
   0x7d023040,
   0xd02f2a00,
   0x46257e80,
   0x28033580,
   0x2804d002,
   0xe027d003,
   0x75e82001,
   0x2064e024,
   0x08805d00,
   0xd01f07c0,
   0x888068a8,
   0x28010b80,
   0x4822d11a,
   0x7dc07dea,
   0xd0132a00,
   0x07c008c0,
   0x4626d012,
   0x7b773620,
   0x46014788,
   0xd1084339,
   0x06097d21,
   0x8869d505,
   0x29010b89,
   0x2100d101,
   0xbdf87371,
   0xe7ea0880,
   0xbdf84788,
   0x30804812,
   0x75c12100,
   0x47004817,
   0x3140490f,
   0x28267108,
   0xdc06d014,
   0xd0132815,
   0xd00b281b,
   0xd104281f,
   0x283de00a,
   0x2847d00e,
   0x490bd00a,
   0x18400080,
   0x47706880,
   0x4770480c,
   0x4770480c,
   0x4770480c,
   0x4770480c,
   0x4770480c,
   0x21000160,
   0x210000c8,
   0x210004e0,
   0x00024959,
   0x00025500,
   0x00023d8f,
   0x00023075,
   0x00022a15,
   0x210044a5,
   0x21004431,
   0x210043d3,
   0x21004353,
   0x210042d5,
   0x490cb510,
   0x4a0c4788,
   0x5e512106,
   0xd0072900,
   0xd0052902,
   0xd0032909,
   0xd0012910,
   0xd1072911,
   0x43c92177,
   0xdd014288,
   0xdd012800,
   0x43c0207f,
   0x0000bd10,
   0x000065a9,
   0x21000380,
   0x4810b510,
   0x481088c1,
   0xd0182905,
   0x68214c0f,
   0x0052084a,
   0x6ba26022,
   0x00520852,
   0x602163a2,
   0xfdeaf7ff,
   0x07006ba0,
   0x2001d408,
   0x60606020,
   0x1c402000,
   0xdbfc280c,
   0x62202014,
   0xf7ffbd10,
   0xbd10fddb,
   0x21000380,
   0x00005b3f,
   0x40046000,
   0x490c6b80,
   0x0f000700,
   0x47707148,
   0x490a4a09,
   0x79502318,
   0x7e4956cb,
   0x428118c0,
   0x4608dd01,
   0x280fe002,
   0x200fdd00,
   0x090989d1,
   0x43010109,
   0x477081d1,
   0x210002e0,
   0x21000088,
   0x79c94908,
   0x07d208ca,
   0x40c1d008,
   0x07c94806,
   0x4906d001,
   0x4906e000,
   0x60c11c49,
   0x20004770,
   0x00004770,
   0x210000e8,
   0x21000028,
   0x00000188,
   0x00000150,
   0x22ff0783,
   0x409a0edb,
   0x0e090789,
   0x28004099,
   0x0700da0b,
   0x38080f00,
   0x009b0883,
   0x181848ff,
   0x439369c3,
   0x61c3430b,
   0x08834770,
   0x009b48fc,
   0x68031818,
   0x430b4393,
   0x47706003,
   0x4694b5f0,
   0x7bd24af8,
   0xd0702a00,
   0x69234cf7,
   0xd06c2b00,
   0x07ea781d,
   0xd0680fd2,
   0xd07f2b00,
   0x2704785e,
   0xd0072e00,
   0x2e012205,
   0x2e02d006,
   0x2e03d006,
   0xe006d109,
   0xe00271e7,
   0xe00371e7,
   0x71a771e2,
   0x71e2e001,
   0x791a71a2,
   0xd0022800,
   0x43322601,
   0x0852e001,
   0x711a0052,
   0x07d208ea,
   0x4ee3d04a,
   0x4ae44fe3,
   0xd0414201,
   0x29007a61,
   0x8859d039,
   0x04894662,
   0x2a000c09,
   0x79a2d001,
   0x79e2e000,
   0xd0232a05,
   0xd0272900,
   0x220569b1,
   0x021243b9,
   0x61b11889,
   0x468c6871,
   0x220f6971,
   0x43910212,
   0x31ff31ff,
   0x61713102,
   0x21014ad0,
   0x60913240,
   0x43b969b1,
   0x31ff31ff,
   0x61b13102,
   0x008a8859,
   0x18514661,
   0x32804ac9,
   0xe0056091,
   0x79a269b1,
   0x021243b9,
   0x61b14311,
   0x21017862,
   0x7062430a,
   0x69b1e008,
   0x188943b9,
   0xe017e7f5,
   0x43b969b1,
   0x61b11889,
   0x07c90869,
   0x49bfd010,
   0x28002208,
   0xd0056948,
   0x61484310,
   0x21027860,
   0xe0044308,
   0x61484390,
   0x21fd7860,
   0x70604008,
   0x4bb2bdf0,
   0x7a9ab510,
   0x46144619,
   0x43847889,
   0x791bd002,
   0xd014430b,
   0xd0122a00,
   0xd1104381,
   0x49af2001,
   0x60c803c0,
   0x384048ad,
   0x04006ac0,
   0x207ed504,
   0xff7ef000,
   0xbd102000,
   0xf0002083,
   0x2001ff79,
   0xb5f3bd10,
   0xb0814ca0,
   0x460e2500,
   0x27017225,
   0x047f48a3,
   0xb6626007,
   0x20114629,
   0xff20f7ff,
   0x600748a0,
   0x22014899,
   0x61423040,
   0x68404897,
   0x30a04996,
   0x61483180,
   0x38804899,
   0x48916007,
   0x28007bc0,
   0x6921d028,
   0xd0252900,
   0x07c37808,
   0xd0210fdb,
   0xd01f2900,
   0x73660881,
   0xd00107c9,
   0xe00072a2,
   0x084172a5,
   0xd00807c9,
   0xd0022e00,
   0x732272e2,
   0x7921e005,
   0x732172e1,
   0x72e5e001,
   0x08c17325,
   0xd10007c9,
   0x09007325,
   0xd00307c0,
   0x07c07860,
   0x7325d000,
   0x46314a83,
   0xf7ff9801,
   0xbdfefcd3,
   0x2001b510,
   0x0440497d,
   0x48766008,
   0x7b017b42,
   0xf7ff7ac0,
   0x2101fef1,
   0xf7ff2011,
   0xbd10fecf,
   0xb5104971,
   0x31404878,
   0x486f6048,
   0x220268c1,
   0x60c14311,
   0x03144872,
   0x21006004,
   0xf7ff200d,
   0x4968febd,
   0x72082001,
   0x6ac14870,
   0x431100a2,
   0x486a62c1,
   0x60043880,
   0xb570bd10,
   0x7a204c61,
   0x28002501,
   0x4e60d005,
   0x68703640,
   0x28170a00,
   0x4867d006,
   0x48677d06,
   0x2e014780,
   0xe04dd03d,
   0xbf002000,
   0x28221c40,
   0x4863dbfb,
   0x15426801,
   0x60014311,
   0x69c14861,
   0x04090c09,
   0x208161c1,
   0xfed4f000,
   0x20074959,
   0x62083980,
   0x20034952,
   0x60483940,
   0x20004950,
   0x62c863c8,
   0x78924a58,
   0x618a0212,
   0x7025bf00,
   0x49507220,
   0x04526aca,
   0x62ca0c52,
   0x21016070,
   0xf7ff200d,
   0x2001fe6f,
   0x03404946,
   0x10c16008,
   0x30804844,
   0x48416001,
   0x22026941,
   0x61414391,
   0x7920bd70,
   0xd1fb2800,
   0x28007960,
   0x7860d1f8,
   0x07c02201,
   0x1c4917c1,
   0xf7ff4610,
   0x7860fe71,
   0x70604328,
   0xd1eb2e06,
   0x28007aa0,
   0x7820d0e8,
   0xd1e52800,
   0xff78f7ff,
   0xb5f8bd70,
   0x38804835,
   0x4f3a6ac0,
   0x4e294d28,
   0xd00107c1,
   0xe0832403,
   0x0f840700,
   0xd0042c01,
   0xd1072c02,
   0x28007fb8,
   0x2001d176,
   0xfeddf7ff,
   0xd0042800,
   0xd0292c01,
   0xd0242c02,
   0x4c27e069,
   0x3c802001,
   0x46016060,
   0x38924823,
   0xfe6cf000,
   0x210120a1,
   0xf0000100,
   0x20c3fe67,
   0x01002101,
   0xfe68f000,
   0x62202007,
   0x24032001,
   0x20007030,
   0x481a7230,
   0x04496ac1,
   0x62c10c49,
   0x49132001,
   0x60080340,
   0x7fb8e04c,
   0xd1452800,
   0xf0002001,
   0x7ae8fe57,
   0x07c00840,
   0x7870d039,
   0xd03107c0,
   0x69884905,
   0xe0284a05,
   0xe000ed00,
   0xe000e400,
   0x210000a8,
   0x210057bc,
   0x40043000,
   0x00000700,
   0x00000400,
   0x40041100,
   0x40045040,
   0xe000e180,
   0xe000e280,
   0x00020be7,
   0x00001702,
   0x40046080,
   0x210002c0,
   0x000074f5,
   0x40040000,
   0x40044040,
   0x21000380,
   0x210002a0,
   0x4390e00e,
   0x021279b2,
   0x61884310,
   0x694148ff,
   0x43112202,
   0x2c026141,
   0x2c03d002,
   0xe024d004,
   0xf0002001,
   0xe020fe17,
   0x72302000,
   0x6ac148f8,
   0x0c490449,
   0x210162c1,
   0xf7ff200d,
   0x49f5fdab,
   0x60482000,
   0x4ef42001,
   0x60300340,
   0xf0002000,
   0x2001fe01,
   0x60300280,
   0x08407ae8,
   0xd00407c0,
   0x694148ea,
   0x43912202,
   0x77bc6141,
   0xb570bdf8,
   0x25004cea,
   0x48e67225,
   0x04496ac1,
   0x62c10c49,
   0xf7ff4628,
   0x2800fe36,
   0x7860d010,
   0xd00907c0,
   0x394049e0,
   0x22076988,
   0x43900212,
   0x021279e2,
   0x61884310,
   0xf7ff48de,
   0xbd70fb6c,
   0x70202001,
   0x388048d7,
   0xbd706205,
   0x470048da,
   0x48d5b5f7,
   0x38402500,
   0xb0846840,
   0x90024616,
   0xd0012a00,
   0xe0004cd5,
   0x22004cd5,
   0x48d56262,
   0xd0032e00,
   0x6a5b4bd2,
   0xe0046003,
   0x6a5b4bcf,
   0xd1002b00,
   0x4bd06002,
   0x07c77d58,
   0x0780d004,
   0x42b00fc0,
   0x755ad100,
   0x20004ac3,
   0x20016010,
   0x03004ac2,
   0x29026010,
   0x2900d03b,
   0x2001d001,
   0x2000e000,
   0x7b526822,
   0x0f1b0713,
   0xfdf4f000,
   0x06310406,
   0x200d0b08,
   0xe00d2701,
   0x40502201,
   0xd1262800,
   0x2301e7f8,
   0x28004058,
   0x0610d0f4,
   0xd0100f07,
   0xdd272f00,
   0x29036820,
   0x6845d00d,
   0xf0004628,
   0x2800fd7f,
   0x48b4d009,
   0xe0109004,
   0x1e8048b2,
   0x6825e7fa,
   0x6905e016,
   0x2001e7f0,
   0x6868e00f,
   0xf0009001,
   0x2800fd6d,
   0x48abd004,
   0x27008068,
   0xe00743ff,
   0x80682003,
   0x9d019800,
   0x90001c40,
   0xdbec42b8,
   0x68219804,
   0x80482e00,
   0xd0014897,
   0xe0002104,
   0x60812101,
   0xda192f00,
   0xd0022e00,
   0x60812108,
   0x2102e00b,
   0x22006081,
   0x46104611,
   0xfcfef7ff,
   0x78414891,
   0x00490849,
   0x21007041,
   0x30204620,
   0x602172c1,
   0x728121fc,
   0xbdf0b007,
   0x27008828,
   0x0f800500,
   0xd0022803,
   0xd0022802,
   0x4889e02b,
   0x4889e000,
   0x42a09000,
   0x6800d004,
   0xd0122800,
   0x1cbf4f88,
   0x30209800,
   0x22837ac1,
   0x72c14011,
   0x46284985,
   0x28824788,
   0x4984d015,
   0xd1154288,
   0x1cbf4f80,
   0x222ce03a,
   0x98004621,
   0xfd14f000,
   0x46202100,
   0x72c13020,
   0x21fc6021,
   0x20017281,
   0x9c004046,
   0x4f77e7de,
   0xe0271c7f,
   0xd0062801,
   0xf0002090,
   0x4977fcdd,
   0x60484875,
   0x2f00e7fe,
   0x68a0d11c,
   0x980260e0,
   0x60256160,
   0x7b406820,
   0x0f000700,
   0xd9022805,
   0x1ebf4f6a,
   0x2080e00e,
   0xfcf0f000,
   0x68204605,
   0x46312200,
   0xfcf0f000,
   0x46284607,
   0xfcf2f000,
   0xd09d2f00,
   0x21024632,
   0xf7ff4638,
   0xe797ff01,
   0x485bb5fe,
   0x30202500,
   0x7ac04c61,
   0x07804626,
   0x27023640,
   0xda032800,
   0x80f0485e,
   0x25037237,
   0x78c0485d,
   0xd0032800,
   0x80f0485c,
   0x25037237,
   0x7800484b,
   0xd0072800,
   0x20004949,
   0x48577208,
   0x80f01d00,
   0x25037237,
   0x300120ff,
   0xfcb6f000,
   0x4843e00e,
   0x28007800,
   0x4950d007,
   0x1d094620,
   0x80c13040,
   0x25037207,
   0x6c20e004,
   0x46054780,
   0xd0ee2d00,
   0x78404848,
   0xd0172800,
   0x68404848,
   0xd50a0741,
   0x39804935,
   0x07096809,
   0x208cd505,
   0xfc6af000,
   0x1c804841,
   0x0680e009,
   0x7931d506,
   0xf000208a,
   0x483dfc9d,
   0xe0001c40,
   0x90002000,
   0xd0082800,
   0xf0002088,
   0x4620fc57,
   0x99003040,
   0x720780c1,
   0x49262503,
   0x28007808,
   0x4a33d007,
   0x1d124620,
   0x80c23040,
   0x25037207,
   0x2d03e003,
   0x2d02d001,
   0x491ed170,
   0x72082000,
   0x2700482d,
   0x90007bc0,
   0xd0072800,
   0x69004608,
   0xd0032800,
   0x07f87807,
   0x90000fc0,
   0xd1032d03,
   0xfc6ef000,
   0xfc72f000,
   0x28009800,
   0x4811d07e,
   0x78c07801,
   0xd1024381,
   0x07c00938,
   0x2200d109,
   0x46104611,
   0xfbf0f7ff,
   0x7841480a,
   0x00490849,
   0x20487041,
   0x490b5d02,
   0xd0652a02,
   0xd02d2a00,
   0xe02c2001,
   0x40041100,
   0x40046080,
   0x40043040,
   0xe000e180,
   0x210057bc,
   0x00005a8b,
   0x000200ab,
   0x21000134,
   0x21000108,
   0x210002a8,
   0x21000280,
   0x00000804,
   0x00000657,
   0x0000ffff,
   0x80000000,
   0xe000ed00,
   0x21000160,
   0x00001407,
   0x21000380,
   0x00001804,
   0x40045080,
   0x210000a8,
   0x680b2000,
   0x073b7b5f,
   0xf0000f1b,
   0x1206fc51,
   0x0a06042f,
   0x23012f0c,
   0x28004058,
   0xe008d126,
   0x2301e09e,
   0x28004058,
   0x093fd003,
   0xdc012f00,
   0x2701e01a,
   0x2a036808,
   0x6840d006,
   0xf0009000,
   0x2800fbdd,
   0xe001d112,
   0xe7f76900,
   0xe0082001,
   0x68409800,
   0xf0009000,
   0x2800fbd1,
   0x9801d106,
   0x90011c40,
   0xdbf342b8,
   0xda0b2f00,
   0xe0002200,
   0x4611e008,
   0xf7ff4610,
   0x48fcfb79,
   0x08497841,
   0x70410049,
   0xd11e2d03,
   0x28006aa0,
   0x6b60d004,
   0xfbe4f000,
   0x62a02000,
   0x49f58920,
   0xd0094288,
   0x42881c49,
   0x49f2d006,
   0x42883120,
   0x1c49d002,
   0xd1084288,
   0x6ea84def,
   0xd0042800,
   0xf0006e68,
   0x2000fbcd,
   0xf00066a8,
   0x2000fbcf,
   0xfbd2f000,
   0xf0002001,
   0x2002fbcf,
   0xfbccf000,
   0x892049e4,
   0x42881dc9,
   0x49e2d003,
   0x42883127,
   0xf000d102,
   0xe02ffbc7,
   0x312649de,
   0xd1204288,
   0x206549dd,
   0x09025c40,
   0xd02507d2,
   0xd02307c0,
   0x30804608,
   0x2a006902,
   0x7942d01e,
   0x0f5b0653,
   0xdb192b02,
   0x4ed588f5,
   0xd01542b5,
   0x2b04258f,
   0x402ad005,
   0x71423210,
   0x730a6809,
   0x402ae00c,
   0x49cce7f9,
   0x42883109,
   0x7f31d106,
   0x290048ca,
   0x49cbd002,
   0x60086e00,
   0x7a213440,
   0x220088e0,
   0xfd7cf7ff,
   0x300120ff,
   0xfb62f000,
   0x4ac6bdfe,
   0x203749c4,
   0x4ac44710,
   0x203149c2,
   0x4ac24710,
   0x201949c0,
   0x4ac04710,
   0x203c49be,
   0x4abe4710,
   0x200a49bc,
   0x4abc4710,
   0x200049ba,
   0xb5f04710,
   0x21004fb3,
   0x71797039,
   0x4cb88801,
   0x0f93050a,
   0x0f92d005,
   0xd0022a01,
   0xd03a2a02,
   0x4ab4e1b6,
   0xd17e1889,
   0x78856821,
   0x684378c2,
   0xb6726880,
   0xd0212900,
   0x34204cad,
   0x57a6260a,
   0xd11b1cb6,
   0x0b24880c,
   0xd1172c01,
   0x42816909,
   0x4ca2d114,
   0x31404621,
   0x3e0b790e,
   0xd80d2e03,
   0x7d36460e,
   0xd0022d00,
   0xd1022e00,
   0x2e00e008,
   0x2001d109,
   0x764a7608,
   0xe00a65e3,
   0xd0022d00,
   0x60c371c2,
   0x7182e001,
   0x20016083,
   0x02c0499a,
   0xb6626088,
   0x4899e176,
   0x46064d8f,
   0x36803520,
   0x1b4b30c0,
   0x69c07bf2,
   0xd02442a9,
   0x4d94dc19,
   0x42a91b4b,
   0xdc07d047,
   0x18cb4b92,
   0xfb2cf000,
   0x431b1b05,
   0x00334343,
   0xd07b2b03,
   0x2b01dc04,
   0x2b02d079,
   0xe0c0d127,
   0xd0752b04,
   0xd1222b1a,
   0xf000e152,
   0x200efb19,
   0x20575708,
   0xdeba8120,
   0x30303071,
   0x2a002030,
   0x6138d021,
   0xd01e2800,
   0x79417982,
   0x0fdb0753,
   0x790570bb,
   0x403526fd,
   0x431d005b,
   0x07107105,
   0x70f80fc0,
   0x07c00888,
   0x0708d002,
   0xe133e001,
   0x0fc00790,
   0x07c87138,
   0x0788d002,
   0xe0010fc0,
   0x0fc007d0,
   0x207c7278,
   0x48718520,
   0x2a00e11d,
   0x6138d020,
   0xd01d2800,
   0x794179c2,
   0x0fdb0753,
   0x790570bb,
   0x403526fd,
   0x431d005b,
   0x07107105,
   0x70f80fc0,
   0x07c00888,
   0x0708d001,
   0x0790e000,
   0x71380fc0,
   0xd00207c8,
   0x0fc00788,
   0x07d0e001,
   0x72780fc0,
   0x85202080,
   0xe0f6485e,
   0xd0232a00,
   0x28006138,
   0x79c2d020,
   0x07537941,
   0x70bb0fdb,
   0x26fd7905,
   0x005b4035,
   0x7105431d,
   0x0fc00710,
   0x088870f8,
   0xd00407c0,
   0xe0030708,
   0xe00fe06d,
   0x0790e0b5,
   0x71380fc0,
   0xd00207c8,
   0x0fc00788,
   0x07d0e001,
   0x72780fc0,
   0x8520208c,
   0xe0cc484a,
   0xd0322a00,
   0x28006138,
   0x7a03d02f,
   0x075d7942,
   0x70bd0fed,
   0x4e4046ac,
   0x1c764d36,
   0x42b1682d,
   0x4e3dd003,
   0x42b13621,
   0x7969d105,
   0x07c90849,
   0x2101d101,
   0x79017179,
   0x402925fd,
   0x006d4665,
   0x71014329,
   0x0fc00718,
   0x089070f8,
   0xd00107c0,
   0xe0000710,
   0x0fc00798,
   0x07d07138,
   0xbf00d002,
   0xe0240790,
   0x0fc007d8,
   0x20a8e025,
   0x482f8520,
   0x2a00e093,
   0x6138d0f9,
   0xd0f62800,
   0x79417a42,
   0x0fdb0753,
   0x790570bb,
   0x403526fd,
   0x431d005b,
   0x07107105,
   0x70f80fc0,
   0x07c00888,
   0x0708d001,
   0x0790e000,
   0x71380fc0,
   0xd00207c8,
   0x0fc00788,
   0x07d0e001,
   0x72780fc0,
   0x2a00e7d7,
   0x6138d043,
   0xd0402800,
   0x79417a82,
   0x0fdb0753,
   0x790570bb,
   0x403526fd,
   0x431d005b,
   0x07107105,
   0x70f80fc0,
   0x07c00888,
   0x0708d024,
   0x0000e023,
   0x210057bc,
   0x00001801,
   0x21000160,
   0x00001409,
   0x40042000,
   0x21004d49,
   0x000205a9,
   0x21000108,
   0xffffefff,
   0x40041100,
   0x21000028,
   0x00001806,
   0xffffe7ff,
   0x21005083,
   0x2100507b,
   0x21005073,
   0x2100506b,
   0x0fc00790,
   0x07c87138,
   0x0788d002,
   0xe0010fc0,
   0x0fc007d0,
   0x20547278,
   0x486e8520,
   0x2a00e025,
   0x6138d020,
   0xd01d2800,
   0x79417ac2,
   0x0fdb0753,
   0x790570bb,
   0x403526fd,
   0x431d005b,
   0x07107105,
   0x70f80fc0,
   0x07c00888,
   0x0708d001,
   0x0790e000,
   0x71380fc0,
   0xd00207c8,
   0x0fc00788,
   0x07d0e001,
   0x72780fc0,
   0x85202068,
   0x6260485b,
   0xbdf02001,
   0x8520200a,
   0xe7f84859,
   0xbdf02082,
   0x4d58b5f3,
   0x7be8b081,
   0xd0142800,
   0x69014856,
   0xd0102900,
   0x07c27808,
   0xd00c0fd2,
   0xd00a2900,
   0x07c008c0,
   0x4851d007,
   0x22076981,
   0x43910212,
   0x18891502,
   0x98016181,
   0x27004c4d,
   0x28004e4d,
   0x7a70d016,
   0x42887a31,
   0x2181d00b,
   0xd0024208,
   0xf0002010,
   0x7a70f949,
   0x484506c1,
   0x30400ec9,
   0x20036141,
   0x48426060,
   0x63c73040,
   0xe01062c7,
   0x60602002,
   0x60a02001,
   0x60a76027,
   0x38404839,
   0x0a818800,
   0xd00407c9,
   0x07c00900,
   0xf000d001,
   0x4837f967,
   0x694130c0,
   0x03522201,
   0x61414391,
   0x6b814835,
   0x43912220,
   0x60e76381,
   0x48336127,
   0x61a06160,
   0x28007b28,
   0xf000d001,
   0x4c30f957,
   0x07c06ae0,
   0x7ae8d0fc,
   0x07c14d2e,
   0x6969d003,
   0x00490849,
   0x08c06169,
   0xd00907c0,
   0x69414823,
   0x431122f0,
   0x69816141,
   0x43912270,
   0x61813140,
   0x6841481e,
   0xf000207d,
   0x4924f93f,
   0x60084822,
   0x20024923,
   0x63287008,
   0x28009801,
   0x7af0d017,
   0x42887ab1,
   0x2181d009,
   0xd0024208,
   0xf0002040,
   0x7af0f8e3,
   0x0ec006c0,
   0x200161e0,
   0x49196060,
   0x47889802,
   0x70702003,
   0x47804817,
   0x2001bdfe,
   0x602760a0,
   0x480e60a7,
   0x60073040,
   0x20787077,
   0xf8d6f000,
   0x0000bdfe,
   0x21005063,
   0x2100505b,
   0x21004b45,
   0x210000a8,
   0x210057bc,
   0x40043000,
   0x40045000,
   0x21000380,
   0x40045100,
   0x0000ffff,
   0x40046000,
   0x40041100,
   0x00000914,
   0xe000e180,
   0x21000018,
   0x0000729f,
   0x000057bf,
   0x4b272201,
   0x48252102,
   0xb5104718,
   0x47804825,
   0x6a404825,
   0xd10d2800,
   0x200a4924,
   0x28005608,
   0x1c40da09,
   0x4608d007,
   0x6a403820,
   0x42884920,
   0x4780d100,
   0xf7ffbd10,
   0xbd10ffe3,
   0x4b1e2100,
   0x46084a1c,
   0x20014718,
   0x0240491c,
   0x481c6008,
   0x780122fb,
   0x70014011,
   0x38ec4812,
   0xb5104700,
   0x47884918,
   0x39204911,
   0xd0072801,
   0xd5040402,
   0x85082000,
   0x62484814,
   0xbd102001,
   0x4b096a4a,
   0x429a3bec,
   0x4a11d101,
   0x4907e005,
   0x4b106a4a,
   0xd1f2429a,
   0x624a4a0f,
   0x0000bd10,
   0x00000806,
   0x0000069f,
   0x000292a1,
   0x21000108,
   0x21000154,
   0x00029263,
   0x210055c3,
   0x0002b4b5,
   0xe000e180,
   0x21000380,
   0x000296f7,
   0x210055b9,
   0x210055ff,
   0x00029569,
   0x210055f5,
   0x07810882,
   0x0ec90092,
   0x78c0ca0c,
   0x424940ca,
   0x408b3120,
   0x0211431a,
   0x06000a09,
   0x47704308,
   0x4801b403,
   0xbd019001,
   0x00003cc3,
   0x4801b403,
   0xbd019001,
   0x00004e75,
   0x4801b403,
   0xbd019001,
   0x00004e4f,
   0x4801b403,
   0xbd019001,
   0x000085bd,
   0x4801b403,
   0xbd019001,
   0x0000900f,
   0x4801b403,
   0xbd019001,
   0x00003f9d,
   0x4801b403,
   0xbd019001,
   0x000002f9,
   0x4801b403,
   0xbd019001,
   0x0000424f,
   0x4801b403,
   0xbd019001,
   0x000004bf,
   0x4801b403,
   0xbd019001,
   0x0000423d,
   0x4801b403,
   0xbd019001,
   0x00003ca9,
   0x4801b403,
   0xbd019001,
   0x00007d65,
   0x4801b403,
   0xbd019001,
   0x00005d1b,
   0x4801b403,
   0xbd019001,
   0x000035f1,
   0x4801b403,
   0xbd019001,
   0x00005e9d,
   0x4801b403,
   0xbd019001,
   0x00000fc1,
   0x4801b403,
   0xbd019001,
   0x0002035d,
   0x4801b403,
   0xbd019001,
   0x000090fd,
   0x4801b403,
   0xbd019001,
   0x00005bbb,
   0x4801b403,
   0xbd019001,
   0x00003c8f,
   0x4674b430,
   0x78251e64,
   0x42ab1c64,
   0x461dd200,
   0x005b5d63,
   0xbc3018e3,
   0x00004718,
   0x00000000,
   0x04050001,
   0x00000000,
   0x00000000,
   0x00000000,
   0x00000000,
};
#define _NWORD_PATCHIMAGE_MULTI_BT5_COEX 1506

CPE_PATCH_TYPE patchCpeHd[] = {
   0x00000000,
};
#define _NWORD_PATCHCPEHD_MULTI_BT5_COEX 1

#define _NWORD_PATCHSYS_MULTI_BT5_COEX 0

#define _IRQ_PATCH_0 0x21004239
#define _IRQ_PATCH_1 0x210048bf
#define _IRQ_PATCH_2 0x21004997


#ifndef _MULTI_BT5_COEX_SYSRAM_START
#define _MULTI_BT5_COEX_SYSRAM_START 0x20000000
#endif

#ifndef _MULTI_BT5_COEX_CPERAM_START
#define _MULTI_BT5_COEX_CPERAM_START 0x21000000
#endif

#define _MULTI_BT5_COEX_SYS_PATCH_FIXED_ADDR 0x20000000

#define _MULTI_BT5_COEX_PATCH_VEC_ADDR_OFFSET 0x03D0
#define _MULTI_BT5_COEX_PATCH_TAB_OFFSET 0x03D4
#define _MULTI_BT5_COEX_IRQPATCH_OFFSET 0x0480
#define _MULTI_BT5_COEX_PATCH_VEC_OFFSET 0x404C

#define _MULTI_BT5_COEX_PATCH_CPEHD_OFFSET 0x04E0

#ifndef _MULTI_BT5_COEX_NO_PROG_STATE_VAR
static uint8_t bMultiBt5CoexPatchEntered = 0;
#endif

PATCH_FUN_SPEC void enterMultiBt5CoexCpePatch(void)
{
#if (_NWORD_PATCHIMAGE_MULTI_BT5_COEX > 0)
   uint32_t *pPatchVec = (uint32_t *) (_MULTI_BT5_COEX_CPERAM_START + _MULTI_BT5_COEX_PATCH_VEC_OFFSET);

   memcpy(pPatchVec, patchImageMultiBt5Coex, sizeof(patchImageMultiBt5Coex));
#endif
}

PATCH_FUN_SPEC void enterMultiBt5CoexCpeHdPatch(void)
{
#if (_NWORD_PATCHCPEHD_MULTI_BT5_COEX > 0)
   uint32_t *pPatchCpeHd = (uint32_t *) (_MULTI_BT5_COEX_CPERAM_START + _MULTI_BT5_COEX_PATCH_CPEHD_OFFSET);

   memcpy(pPatchCpeHd, patchCpeHd, sizeof(patchCpeHd));
#endif
}

PATCH_FUN_SPEC void enterMultiBt5CoexSysPatch(void)
{
}

PATCH_FUN_SPEC void configureMultiBt5CoexPatch(void)
{
   uint8_t *pPatchTab = (uint8_t *) (_MULTI_BT5_COEX_CPERAM_START + _MULTI_BT5_COEX_PATCH_TAB_OFFSET);
   uint32_t *pIrqPatch = (uint32_t *) (_MULTI_BT5_COEX_CPERAM_START + _MULTI_BT5_COEX_IRQPATCH_OFFSET);


   pPatchTab[1] = 0;
   pPatchTab[21] = 1;
   pPatchTab[76] = 2;
   pPatchTab[62] = 3;
   pPatchTab[64] = 4;
   pPatchTab[91] = 5;
   pPatchTab[79] = 6;
   pPatchTab[140] = 7;
   pPatchTab[150] = 8;
   pPatchTab[107] = 9;
   pPatchTab[13] = 10;
   pPatchTab[31] = 11;
   pPatchTab[152] = 12;
   pPatchTab[151] = 13;
   pPatchTab[12] = 14;
   pPatchTab[139] = 15;
   pPatchTab[78] = 16;
   pPatchTab[163] = 17;
   pPatchTab[81] = 18;
   pPatchTab[40] = 19;
   pPatchTab[73] = 20;
   pPatchTab[164] = 21;

   pIrqPatch[1] = _IRQ_PATCH_0;
   pIrqPatch[17] = _IRQ_PATCH_1;
   pIrqPatch[21] = _IRQ_PATCH_2;
}

PATCH_FUN_SPEC void applyMultiBt5CoexPatch(void)
{
#ifdef _MULTI_BT5_COEX_NO_PROG_STATE_VAR
   enterMultiBt5CoexSysPatch();
   enterMultiBt5CoexCpePatch();
#else
   if (!bMultiBt5CoexPatchEntered)
   {
      enterMultiBt5CoexSysPatch();
      enterMultiBt5CoexCpePatch();
      bMultiBt5CoexPatchEntered = 1;
   }
#endif
   enterMultiBt5CoexCpeHdPatch();
   configureMultiBt5CoexPatch();
}

void refreshMultiBt5CoexPatch(void)
{
   enterMultiBt5CoexCpeHdPatch();
   configureMultiBt5CoexPatch();
}

void cleanMultiBt5CoexPatch(void)
{
#ifndef _MULTI_BT5_COEX_NO_PROG_STATE_VAR
   bMultiBt5CoexPatchEntered = 0;
#endif
}

void rf_patch_cpe_multi_bt5_coex(void)
{
   applyMultiBt5CoexPatch();
}

#undef _IRQ_PATCH_0
#undef _IRQ_PATCH_1
#undef _IRQ_PATCH_2

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif



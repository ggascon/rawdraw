/*
Copyright (c) 2010-2020 <>< Charles Lohr

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE X CONSORTIUM BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef _CNFG_C
#define _CNFG_C

#include "CNFG.h"


int CNFGPenX, CNFGPenY;
uint32_t CNFGBGColor;
uint32_t CNFGLastColor;
uint32_t CNFGDialogColor; //background for boxes

// The following two arrays are generated by Fonter/fonter.cpp
const unsigned short RawdrawFontCharMap[256] = {
	65535, 0, 8, 16, 24, 31, 41, 50, 51, 65535, 65535, 57, 66, 65535, 75, 83,
	92, 96, 100, 108, 114, 123, 132, 137, 147, 152, 158, 163, 169, 172, 178, 182, 
	65535, 186, 189, 193, 201, 209, 217, 226, 228, 232, 236, 244, 248, 250, 252, 253, 
	255, 261, 266, 272, 278, 283, 289, 295, 300, 309, 316, 318, 321, 324, 328, 331, 
	337, 345, 352, 362, 368, 375, 382, 388, 396, 402, 408, 413, 422, 425, 430, 435, 
	442, 449, 458, 466, 472, 476, 480, 485, 492, 500, 507, 512, 516, 518, 522, 525, 
	527, 529, 536, 541, 546, 551, 557, 564, 572, 578, 581, 586, 593, 595, 604, 610, 
	615, 621, 627, 632, 638, 642, 648, 653, 660, 664, 670, 674, 680, 684, 690, 694, 
	65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 
	65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 
	700, 703, 711, 718, 731, 740, 744, 754, 756, 760, 766, 772, 775, 777, 785, 787, 
	792, 798, 803, 811, 813, 820, 827, 828, 831, 833, 838, 844, 853, 862, 874, 880, 
	889, 898, 908, 919, 928, 939, 951, 960, 969, 978, 988, 997, 1005, 1013, 1022, 1030,
	1039, 1047, 1054, 1061, 1070, 1079, 1086, 1090, 1099, 1105, 1111, 1118, 1124, 1133, 1140, 1150,
	1159, 1168, 1178, 1189, 1198, 1209, 1222, 1231, 1239, 1247, 1256, 1264, 1268, 1272, 1277, 1281,
	1290, 1300, 1307, 1314, 1322, 1331, 1338, 1342, 1349, 1357, 1365, 1374, 1382, 1390, 1397, 65535, };

const unsigned char RawdrawFontCharData[1405] = {
	0x00, 0x09, 0x20, 0x29, 0x03, 0x23, 0x14, 0x8b, 0x00, 0x09, 0x20, 0x29, 0x04, 0x24, 0x13, 0x8c, 
	0x01, 0x21, 0x23, 0x14, 0x03, 0x09, 0x11, 0x9a, 0x11, 0x22, 0x23, 0x14, 0x03, 0x02, 0x99, 0x01, 
	0x21, 0x23, 0x09, 0x03, 0x29, 0x03, 0x09, 0x12, 0x9c, 0x03, 0x2b, 0x13, 0x1c, 0x23, 0x22, 0x11, 
	0x02, 0x8b, 0x9a, 0x1a, 0x01, 0x21, 0x23, 0x03, 0x89, 0x03, 0x21, 0x2a, 0x21, 0x19, 0x03, 0x14, 
	0x23, 0x9a, 0x01, 0x10, 0x21, 0x12, 0x09, 0x12, 0x1c, 0x03, 0xab, 0x02, 0x03, 0x1b, 0x02, 0x1a, 
	0x13, 0x10, 0xa9, 0x01, 0x2b, 0x03, 0x29, 0x02, 0x11, 0x22, 0x13, 0x8a, 0x00, 0x22, 0x04, 0x88, 
	0x20, 0x02, 0x24, 0xa8, 0x01, 0x10, 0x29, 0x10, 0x14, 0x0b, 0x14, 0xab, 0x00, 0x0b, 0x0c, 0x20, 
	0x2b, 0xac, 0x00, 0x28, 0x00, 0x02, 0x2a, 0x10, 0x1c, 0x20, 0xac, 0x01, 0x21, 0x23, 0x03, 0x09, 
	0x20, 0x10, 0x14, 0x8c, 0x03, 0x23, 0x24, 0x04, 0x8b, 0x01, 0x10, 0x29, 0x10, 0x14, 0x0b, 0x14, 
	0x2b, 0x04, 0xac, 0x01, 0x18, 0x21, 0x10, 0x9c, 0x03, 0x1c, 0x23, 0x1c, 0x10, 0x9c, 0x02, 0x22, 
	0x19, 0x22, 0x9b, 0x02, 0x2a, 0x02, 0x19, 0x02, 0x9b, 0x01, 0x02, 0xaa, 0x02, 0x22, 0x11, 0x02, 
	0x13, 0xaa, 0x11, 0x22, 0x02, 0x99, 0x02, 0x13, 0x22, 0x8a, 0x10, 0x1b, 0x9c, 0x10, 0x09, 0x20, 
	0x99, 0x10, 0x1c, 0x20, 0x2c, 0x01, 0x29, 0x03, 0xab, 0x21, 0x10, 0x01, 0x23, 0x14, 0x0b, 0x10, 
	0x9c, 0x00, 0x09, 0x23, 0x2c, 0x04, 0x03, 0x21, 0xa8, 0x21, 0x10, 0x01, 0x12, 0x03, 0x14, 0x2b, 
	0x02, 0xac, 0x10, 0x99, 0x10, 0x01, 0x03, 0x9c, 0x10, 0x21, 0x23, 0x9c, 0x01, 0x2b, 0x11, 0x1b, 
	0x21, 0x0b, 0x02, 0xaa, 0x02, 0x2a, 0x11, 0x9b, 0x04, 0x9b, 0x02, 0xaa, 0x9c, 0x03, 0xa9, 0x00, 
	0x20, 0x24, 0x04, 0x08, 0x9a, 0x01, 0x10, 0x1c, 0x04, 0xac, 0x01, 0x10, 0x21, 0x22, 0x04, 0xac, 
	0x00, 0x20, 0x24, 0x0c, 0x12, 0xaa, 0x00, 0x02, 0x2a, 0x20, 0xac, 0x20, 0x00, 0x02, 0x22, 0x24, 
	0x8c, 0x20, 0x02, 0x22, 0x24, 0x04, 0x8a, 0x00, 0x20, 0x21, 0x12, 0x9c, 0x00, 0x0c, 0x00, 0x20, 
	0x2c, 0x04, 0x2c, 0x02, 0xaa, 0x00, 0x02, 0x22, 0x20, 0x08, 0x22, 0x8c, 0x19, 0x9b, 0x19, 0x13, 
	0x8c, 0x20, 0x02, 0xac, 0x01, 0x29, 0x03, 0xab, 0x00, 0x22, 0x8c, 0x01, 0x10, 0x21, 0x12, 0x1b, 
	0x9c, 0x21, 0x01, 0x04, 0x24, 0x22, 0x12, 0x13, 0xab, 0x04, 0x01, 0x10, 0x21, 0x2c, 0x02, 0xaa, 
	0x00, 0x04, 0x14, 0x23, 0x12, 0x0a, 0x12, 0x21, 0x10, 0x88, 0x23, 0x14, 0x03, 0x01, 0x10, 0xa9, 
	0x00, 0x10, 0x21, 0x23, 0x14, 0x04, 0x88, 0x00, 0x04, 0x2c, 0x00, 0x28, 0x02, 0x9a, 0x00, 0x0c, 
	0x00, 0x28, 0x02, 0x9a, 0x21, 0x10, 0x01, 0x03, 0x14, 0x23, 0x22, 0x9a, 0x00, 0x0c, 0x20, 0x2c, 
	0x02, 0xaa, 0x00, 0x28, 0x10, 0x1c, 0x04, 0xac, 0x00, 0x20, 0x23, 0x14, 0x8b, 0x00, 0x0c, 0x02, 
	0x12, 0x21, 0x28, 0x12, 0x23, 0xac, 0x00, 0x04, 0xac, 0x04, 0x00, 0x11, 0x20, 0xac, 0x04, 0x00, 
	0x2a, 0x20, 0xac, 0x01, 0x10, 0x21, 0x23, 0x14, 0x03, 0x89, 0x00, 0x0c, 0x00, 0x10, 0x21, 0x12, 
	0x8a, 0x01, 0x10, 0x21, 0x23, 0x14, 0x03, 0x09, 0x04, 0x9b, 0x00, 0x0c, 0x00, 0x10, 0x21, 0x12, 
	0x02, 0xac, 0x21, 0x10, 0x01, 0x23, 0x14, 0x8b, 0x00, 0x28, 0x10, 0x9c, 0x00, 0x04, 0x24, 0xa8, 
	0x00, 0x03, 0x14, 0x23, 0xa8, 0x00, 0x04, 0x2c, 0x14, 0x1b, 0x24, 0xa8, 0x00, 0x01, 0x23, 0x2c, 
	0x04, 0x03, 0x21, 0xa8, 0x00, 0x01, 0x12, 0x1c, 0x12, 0x21, 0xa8, 0x00, 0x20, 0x02, 0x04, 0xac, 
	0x10, 0x00, 0x04, 0x9c, 0x01, 0xab, 0x10, 0x20, 0x24, 0x9c, 0x01, 0x10, 0xa9, 0x04, 0xac, 0x00, 
	0x99, 0x02, 0x04, 0x24, 0x2a, 0x23, 0x12, 0x8a, 0x00, 0x04, 0x24, 0x22, 0x8a, 0x24, 0x04, 0x03, 
	0x12, 0xaa, 0x20, 0x24, 0x04, 0x02, 0xaa, 0x24, 0x04, 0x02, 0x22, 0x23, 0x9b, 0x04, 0x09, 0x02, 
	0x1a, 0x01, 0x10, 0xa9, 0x23, 0x12, 0x03, 0x14, 0x23, 0x24, 0x15, 0x8c, 0x00, 0x0c, 0x03, 0x12, 
	0x23, 0xac, 0x19, 0x12, 0x9c, 0x2a, 0x23, 0x24, 0x15, 0x8c, 0x00, 0x0c, 0x03, 0x13, 0x2a, 0x13, 
	0xac, 0x10, 0x9c, 0x02, 0x0c, 0x02, 0x1b, 0x12, 0x1c, 0x12, 0x23, 0xac, 0x02, 0x0c, 0x03, 0x12, 
	0x23, 0xac, 0x02, 0x22, 0x24, 0x04, 0x8a, 0x02, 0x0d, 0x04, 0x24, 0x22, 0x8a, 0x02, 0x04, 0x2c, 
	0x25, 0x22, 0x8a, 0x02, 0x0c, 0x03, 0x12, 0xaa, 0x22, 0x02, 0x03, 0x23, 0x24, 0x8c, 0x11, 0x1c, 
	0x02, 0xaa, 0x02, 0x04, 0x14, 0x2b, 0x24, 0xaa, 0x02, 0x03, 0x14, 0x23, 0xaa, 0x02, 0x03, 0x14, 
	0x1a, 0x13, 0x24, 0xaa, 0x02, 0x2c, 0x04, 0xaa, 0x02, 0x03, 0x1c, 0x22, 0x23, 0x8d, 0x02, 0x22, 
	0x04, 0xac, 0x20, 0x10, 0x14, 0x2c, 0x12, 0x8a, 0x10, 0x19, 0x13, 0x9c, 0x00, 0x10, 0x14, 0x0c, 
	0x12, 0xaa, 0x01, 0x10, 0x11, 0xa8, 0x03, 0x04, 0x24, 0x23, 0x12, 0x8b, 0x18, 0x11, 0x9c, 0x21, 
	0x10, 0x01, 0x02, 0x13, 0x2a, 0x10, 0x9b, 0x11, 0x00, 0x04, 0x24, 0x2b, 0x02, 0x9a, 0x01, 0x0a, 
	0x11, 0x29, 0x22, 0x2b, 0x03, 0x1b, 0x02, 0x11, 0x22, 0x13, 0x8a, 0x00, 0x11, 0x28, 0x11, 0x1c, 
	0x02, 0x2a, 0x03, 0xab, 0x10, 0x1a, 0x13, 0x9d, 0x20, 0x00, 0x02, 0x11, 0x2a, 0x02, 0x13, 0x22, 
	0x24, 0x8c, 0x08, 0xa8, 0x20, 0x10, 0x11, 0xa9, 0x10, 0x29, 0x20, 0x21, 0x11, 0x98, 0x11, 0x02, 
	0x1b, 0x21, 0x12, 0xab, 0x01, 0x21, 0xaa, 0x12, 0xaa, 0x10, 0x20, 0x21, 0x19, 0x12, 0x18, 0x11, 
	0xaa, 0x00, 0xa8, 0x01, 0x10, 0x21, 0x12, 0x89, 0x02, 0x2a, 0x11, 0x1b, 0x03, 0xab, 0x01, 0x10, 
	0x21, 0x03, 0xab, 0x01, 0x10, 0x21, 0x12, 0x0a, 0x12, 0x23, 0x8b, 0x11, 0xa8, 0x02, 0x0d, 0x04, 
	0x14, 0x2b, 0x22, 0xac, 0x14, 0x10, 0x01, 0x1a, 0x10, 0x20, 0xac, 0x9a, 0x14, 0x15, 0x8d, 0x20, 
	0xa9, 0x10, 0x20, 0x21, 0x11, 0x98, 0x01, 0x12, 0x0b, 0x11, 0x22, 0x9b, 0x00, 0x09, 0x02, 0x28, 
	0x12, 0x13, 0x2b, 0x22, 0xac, 0x00, 0x09, 0x02, 0x28, 0x12, 0x22, 0x13, 0x14, 0xac, 0x00, 0x10, 
	0x11, 0x09, 0x11, 0x02, 0x28, 0x12, 0x13, 0x2b, 0x22, 0xac, 0x18, 0x11, 0x12, 0x03, 0x14, 0xab, 
	0x04, 0x02, 0x11, 0x22, 0x2c, 0x03, 0x2b, 0x10, 0xa9, 0x04, 0x02, 0x11, 0x22, 0x2c, 0x03, 0x2b, 
	0x01, 0x98, 0x04, 0x02, 0x11, 0x22, 0x2c, 0x03, 0x2b, 0x01, 0x10, 0xa9, 0x04, 0x02, 0x11, 0x22, 
	0x2c, 0x03, 0x2b, 0x01, 0x10, 0x11, 0xa8, 0x04, 0x02, 0x11, 0x22, 0x2c, 0x03, 0x2b, 0x08, 0xa8, 
	0x04, 0x02, 0x11, 0x22, 0x2c, 0x03, 0x2b, 0x00, 0x20, 0x11, 0x88, 0x00, 0x0c, 0x02, 0x2a, 0x00, 
	0x19, 0x10, 0x1c, 0x10, 0x28, 0x14, 0xac, 0x23, 0x14, 0x03, 0x01, 0x10, 0x29, 0x14, 0x15, 0x8d, 
	0x02, 0x2a, 0x02, 0x04, 0x2c, 0x03, 0x1b, 0x00, 0x99, 0x02, 0x2a, 0x02, 0x04, 0x2c, 0x03, 0x1b, 
	0x11, 0xa8, 0x02, 0x2a, 0x02, 0x04, 0x2c, 0x03, 0x1b, 0x01, 0x10, 0xa9, 0x02, 0x2a, 0x02, 0x04, 
	0x2c, 0x03, 0x1b, 0x08, 0xa8, 0x02, 0x2a, 0x12, 0x1c, 0x04, 0x2c, 0x00, 0x99, 0x02, 0x2a, 0x12, 
	0x1c, 0x04, 0x2c, 0x11, 0xa8, 0x02, 0x2a, 0x12, 0x1c, 0x04, 0x2c, 0x01, 0x10, 0xa9, 0x02, 0x2a, 
	0x12, 0x1c, 0x04, 0x2c, 0x28, 0x88, 0x00, 0x10, 0x21, 0x23, 0x14, 0x04, 0x08, 0x02, 0x9a, 0x04, 
	0x02, 0x24, 0x2a, 0x01, 0x10, 0x11, 0xa8, 0x02, 0x22, 0x24, 0x04, 0x0a, 0x00, 0x99, 0x02, 0x22, 
	0x24, 0x04, 0x0a, 0x11, 0xa8, 0x02, 0x22, 0x24, 0x04, 0x0a, 0x11, 0x28, 0x00, 0x99, 0x02, 0x22, 
	0x24, 0x04, 0x0a, 0x01, 0x10, 0x11, 0xa8, 0x01, 0x21, 0x24, 0x04, 0x09, 0x08, 0xa8, 0x01, 0x2b, 
	0x03, 0xa9, 0x01, 0x10, 0x21, 0x23, 0x14, 0x03, 0x09, 0x03, 0xa9, 0x01, 0x04, 0x24, 0x29, 0x11, 
	0xa8, 0x01, 0x04, 0x24, 0x29, 0x00, 0x99, 0x02, 0x04, 0x24, 0x2a, 0x01, 0x10, 0xa9, 0x01, 0x04, 
	0x24, 0x29, 0x08, 0xa8, 0x01, 0x02, 0x13, 0x1c, 0x13, 0x22, 0x29, 0x11, 0xa8, 0x00, 0x0c, 0x01, 
	0x11, 0x22, 0x13, 0x8b, 0x00, 0x0d, 0x00, 0x10, 0x21, 0x1a, 0x02, 0x22, 0x24, 0x8c, 0x02, 0x04, 
	0x24, 0x2a, 0x23, 0x12, 0x0a, 0x00, 0x99, 0x02, 0x04, 0x24, 0x2a, 0x23, 0x12, 0x0a, 0x11, 0xa8, 
	0x02, 0x04, 0x24, 0x2a, 0x23, 0x12, 0x0a, 0x01, 0x10, 0xa9, 0x02, 0x04, 0x24, 0x2a, 0x23, 0x12, 
	0x0a, 0x01, 0x10, 0x11, 0xa8, 0x02, 0x04, 0x24, 0x2a, 0x23, 0x12, 0x0a, 0x09, 0xa9, 0x02, 0x04, 
	0x24, 0x2a, 0x23, 0x12, 0x0a, 0x01, 0x10, 0x21, 0x89, 0x02, 0x1b, 0x02, 0x04, 0x2c, 0x12, 0x1c, 
	0x12, 0x2a, 0x13, 0x2b, 0x22, 0xab, 0x03, 0x04, 0x2c, 0x03, 0x12, 0x2a, 0x14, 0x15, 0x8d, 0x24, 
	0x04, 0x02, 0x22, 0x23, 0x1b, 0x00, 0x99, 0x24, 0x04, 0x02, 0x22, 0x23, 0x1b, 0x11, 0xa8, 0x24, 
	0x04, 0x02, 0x22, 0x23, 0x1b, 0x01, 0x10, 0xa9, 0x24, 0x04, 0x02, 0x22, 0x23, 0x1b, 0x09, 0xa9, 
	0x12, 0x1c, 0x00, 0x99, 0x12, 0x1c, 0x11, 0xa8, 0x12, 0x1c, 0x01, 0x10, 0xa9, 0x12, 0x1c, 0x09, 
	0xa9, 0x00, 0x2a, 0x11, 0x28, 0x02, 0x22, 0x24, 0x04, 0x8a, 0x02, 0x0c, 0x03, 0x12, 0x23, 0x2c, 
	0x01, 0x10, 0x11, 0xa8, 0x02, 0x04, 0x24, 0x22, 0x0a, 0x00, 0x99, 0x02, 0x04, 0x24, 0x22, 0x0a, 
	0x11, 0xa8, 0x02, 0x04, 0x24, 0x22, 0x0a, 0x01, 0x10, 0xa9, 0x02, 0x04, 0x24, 0x22, 0x0a, 0x01, 
	0x10, 0x11, 0xa8, 0x02, 0x04, 0x24, 0x22, 0x0a, 0x09, 0xa9, 0x19, 0x02, 0x2a, 0x9b, 0x02, 0x04, 
	0x24, 0x22, 0x0a, 0x04, 0xaa, 0x02, 0x04, 0x14, 0x2b, 0x24, 0x2a, 0x00, 0x99, 0x02, 0x04, 0x14, 
	0x2b, 0x24, 0x2a, 0x11, 0xa8, 0x02, 0x04, 0x14, 0x2b, 0x24, 0x2a, 0x01, 0x10, 0xa9, 0x02, 0x04, 
	0x14, 0x2b, 0x24, 0x2a, 0x09, 0xa9, 0x02, 0x03, 0x1c, 0x22, 0x23, 0x0d, 0x11, 0xa8, 0x00, 0x0c, 
	0x02, 0x11, 0x22, 0x13, 0x8a, 0x02, 0x03, 0x1c, 0x22, 0x23, 0x0d, 0x09, 0xa9, };



//Set this if you are only using CNFG to create an OpenGL context.
#ifndef CNFGCONTEXTONLY


void CNFGDrawText( const char * text, short scale )
{
	const unsigned char * lmap;
	float iox = (float)CNFGPenX; //x offset
	float ioy = (float)CNFGPenY; //y offset

	int place = 0;
	unsigned short index;
	int bQuit = 0;
	while( text[place] )
	{
		unsigned char c = text[place];
		switch( c )
		{
		case 9: // tab
			iox += 12 * scale;
			break;
		case 10: // linefeed
			iox = (float)CNFGPenX;
			ioy += 6 * scale;
			break;
		default:
			index = RawdrawFontCharMap[c];
			if( index == 65535 )
			{
				iox += 3 * scale;
				break;
			}

			lmap = &RawdrawFontCharData[index];
			short penx, peny;
			unsigned char start_seg = 1;
			do
			{
				unsigned char data = (*(lmap++));
				short x1 = (short)(((data >> 4) & 0x07)*scale + iox);
				short y1 = (short)((data        & 0x07)*scale + ioy);
				if( start_seg )
				{
					penx = x1;
					peny = y1;
					start_seg = 0;
					if( data & 0x08 )
						CNFGTackPixel( x1, y1 );
				}
				else
				{
					CNFGTackSegment( penx, peny, x1, y1 );
					penx = x1;
					peny = y1;
				}
				if( data & 0x08 ) start_seg = 1;
				bQuit = data & 0x80;
			} while( !bQuit );

			iox += 3 * scale;
		}
		place++;
	}
}


void CNFGDrawBox( short x1, short y1, short x2, short y2 )
{
	unsigned lc = CNFGLastColor;
	CNFGColor( CNFGDialogColor );
	CNFGTackRectangle( x1, y1, x2, y2 );
	CNFGColor( lc );
	CNFGTackSegment( x1, y1, x2, y1 );
	CNFGTackSegment( x2, y1, x2, y2 );
	CNFGTackSegment( x2, y2, x1, y2 );
	CNFGTackSegment( x1, y2, x1, y1 );
}

void CNFGGetTextExtents( const char * text, int * w, int * h, int textsize )
{
	int charsx = 0;
	int charsy = 1;
	int charsline = 0;
	const char * s;

	for( s = text; *s; s++ )
	{
		if( *s == '\n' )
		{
			charsline = 0;
			if( *(s+1) )
				charsy++;
		}
		else
		{
			charsline++;
			if( charsline > charsx )
				charsx = charsline;
		}
	}

	*w = charsx * textsize * 3 + textsize;
	*h = charsy * textsize * 6;
}

void CNFGDrawTextbox( int x, int y, const char * text, int textsize )
{
	int w;
	int h;

	CNFGGetTextExtents( text, &w, &h, textsize );
	
	CNFGDrawBox( (short)x, (short)y, (short)(x + w), (short)(y + h) );
	CNFGPenX = x + textsize;
	CNFGPenY = y + textsize;
	CNFGDrawText( text, textsize );
}


#if defined( CNFGOGL ) && !defined( HAS_XSHAPE )

#ifdef _MSC_VER
#include <windows.h>
#pragma comment( lib, "OpenGL32.lib" )
#endif
#include <GL/gl.h>

uint32_t CNFGColor( uint32_t RGB )
{
	unsigned char red = RGB & 0xFF;
	unsigned char grn = ( RGB >> 8 ) & 0xFF;
	unsigned char blu = ( RGB >> 16 ) & 0xFF;
	glColor3ub( red, grn, blu );
	return RGB;
}

void CNFGClearFrame()
{
	short w, h;
	unsigned char red = CNFGBGColor & 0xFF;
	unsigned char grn = ( CNFGBGColor >> 8 ) & 0xFF;
	unsigned char blu = ( CNFGBGColor >> 16 ) & 0xFF;
	glClearColor( red/255.0, grn/255.0, blu/255.0, 1.0 );
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	CNFGGetDimensions( &w, &h );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glViewport( 0, 0, w, h );
	glOrtho( 0, w, h, 0, 1, -1 );
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
}


void CNFGTackSegment( short x1, short y1, short x2, short y2 )
{
	if( x1 == x2 && y1 == y2 )
	{
		glBegin( GL_POINTS );
		glVertex2f( x1+.5, y1+.5 );
		glEnd();
	}
	else
	{
		// GL_LINE misses the last pixel if the line is not continued
		// due to the Diamond-exit rule so we use GL_LINE_LOOP which
		// draws the line back and forth catching all the pixels.
		glBegin( GL_LINE_LOOP );
		glVertex2f( x1+.5, y1+.5 );
		glVertex2f( x2+.5, y2+.5 );
		glEnd();
	}
}

void CNFGTackPixel( short x1, short y1 )
{
	glBegin( GL_POINTS );
	glVertex2f( x1, y1 );
	glEnd();
}

void CNFGTackRectangle( short x1, short y1, short x2, short y2 )
{
	glBegin( GL_QUADS );
	glVertex2f( x1, y1 );
	glVertex2f( x2, y1 );
	glVertex2f( x2, y2 );
	glVertex2f( x1, y2 );
	glEnd();
}

void CNFGTackPoly( RDPoint * points, int verts )
{
	int i;
	glBegin( GL_TRIANGLE_FAN );
	glVertex2f( points[0].x, points[0].y );
	for( i = 1; i < verts; i++ )
	{
		glVertex2f( points[i].x, points[i].y );
	}
	glEnd();
}

void CNFGInternalResize( short x, short y ) { }


void CNFGSetLineWidth( short width )
{
	glLineWidth( width );
}

#endif

#endif

#endif //_CNFG_C

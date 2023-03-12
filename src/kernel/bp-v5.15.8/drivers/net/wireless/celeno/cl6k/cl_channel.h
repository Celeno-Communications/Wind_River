/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_CHANNEL_H
#define CL_CHANNEL_H

#include <linux/types.h>

enum chan_idx_6g {
	b6g_ch1,
	b6g_ch2,
	b6g_ch5,
	b6g_ch9,
	b6g_ch13,
	b6g_ch17,
	b6g_ch21,
	b6g_ch25,
	b6g_ch29,
	b6g_ch33,
	b6g_ch37,
	b6g_ch41,
	b6g_ch45,
	b6g_ch49,
	b6g_ch53,
	b6g_ch57,
	b6g_ch61,
	b6g_ch65,
	b6g_ch69,
	b6g_ch73,
	b6g_ch77,
	b6g_ch81,
	b6g_ch85,
	b6g_ch89,
	b6g_ch93,
	b6g_ch97,
	b6g_ch101,
	b6g_ch105,
	b6g_ch109,
	b6g_ch113,
	b6g_ch117,
	b6g_ch121,
	b6g_ch125,
	b6g_ch129,
	b6g_ch133,
	b6g_ch137,
	b6g_ch141,
	b6g_ch145,
	b6g_ch149,
	b6g_ch153,
	b6g_ch157,
	b6g_ch161,
	b6g_ch165,
	b6g_ch169,
	b6g_ch173,
	b6g_ch177,
	b6g_ch181,
	b6g_ch185,
	b6g_ch189,
	b6g_ch193,
	b6g_ch197,
	b6g_ch201,
	b6g_ch205,
	b6g_ch209,
	b6g_ch213,
	b6g_ch217,
	b6g_ch221,
	b6g_ch225,
	b6g_ch229,
	b6g_ch233,

	NUM_CHANNELS_6G
};

enum chan_idx_5g {
	b5g_ch36,
	b5g_ch40,
	b5g_ch44,
	b5g_ch48,
	b5g_ch52,
	b5g_ch56,
	b5g_ch60,
	b5g_ch64,
	b5g_ch100,
	b5g_ch104,
	b5g_ch108,
	b5g_ch112,
	b5g_ch116,
	b5g_ch120,
	b5g_ch124,
	b5g_ch128,
	b5g_ch132,
	b5g_ch136,
	b5g_ch140,
	b5g_ch144,
	b5g_ch149,
	b5g_ch153,
	b5g_ch157,
	b5g_ch161,
	b5g_ch165,

	NUM_CHANNELS_5G
};

enum chan_idx_24g {
	b24g_ch1,
	b24g_ch2,
	b24g_ch3,
	b24g_ch4,
	b24g_ch5,
	b24g_ch6,
	b24g_ch7,
	b24g_ch8,
	b24g_ch9,
	b24g_ch10,
	b24g_ch11,
	b24g_ch12,
	b24g_ch13,
	b24g_ch14,

	NUM_CHANNELS_24G
};

/* 6g band has the largest list */
#define MAX_CHANNELS NUM_CHANNELS_6G

#define START_CHAN_IDX_6G 1

/* 1 ==> 5955 */
#define FREQ6G(_chan) ((_chan) == 2 ? 5935 : 5950 + 5 * (_chan))
/* 36 ==> 5180 */
#define FREQ5G(_chan) (5000 + 5 * (_chan))
/* 1 ==> 2412 */
#define FREQ2G(_chan) ((_chan) == 14 ? 2484 : 2407 + (_chan) *  5)

/* 6G channels - UNII-5 */
#define START_CHAN_IDX_UNII5 1
#define END_CHAN_IDX_UNII5   85
/* 6G channels - UNII-6 */
#define START_CHAN_IDX_UNII6 89
#define END_CHAN_IDX_UNII6   109
/* 6G channels - UNII-7 */
#define START_CHAN_IDX_UNII7 113
#define END_CHAN_IDX_UNII7   165
/* 6G channels - UNII-8 */
#define START_CHAN_IDX_UNII8 169
#define END_CHAN_IDX_UNII8   233

#define INVALID_CHAN_IDX 0xff

/* 2.4G channel 1 freq 2.412 */
#define CHANNEL_LOW_IDX_24G     0
/* 2.4G channel 6 freq 2.437 */
#define CHANNEL_CENTER_IDX_24G  5
/* 2.4G channel 11 freq 2.462 */
#define CHANNEL_HIGH_IDX_24G    10
/* 5G channel 36 freq 5180 */
#define CHANNEL_LOW_IDX_5G        0
/* 5G channel 64 freq 5230 */
#define CHANNEL_CENTER1_IDX_5G    7
/* 5G channel 100 freq 5500 */
#define CHANNEL_CENTER2_IDX_5G    8
/* 5G channel 120 freq 5600 */
#define CHANNEL_CENTER3_IDX_5G    13
/* 5G channel 140 freq 5700 */
#define CHANNEL_CENTER4_IDX_5G    18
/* 5G channel 165 freq 5825 */
#define CHANNEL_HIGH_IDX_5G       24
/* 6G channel 9 freq 5995 */
#define CHANNEL_LOW_IDX_6G        3
/* 6G channel 41 freq 6155 */
#define CHANNEL_CENTER1_IDX_6G    11
/* 6G channel 97 freq 6435 */
#define CHANNEL_CENTER2_IDX_6G    25
/* 6G channel 137 freq 6635 */
#define CHANNEL_CENTER3_IDX_6G    35
/* 6G channel 173 freq 6815 */
#define CHANNEL_CENTER4_IDX_6G    44
/* 6G channel 209 freq 6995 */
#define CHANNEL_HIGH_IDX_6G       53

struct cl_hw;

u32 cl_ch_idx_to_channel(struct cl_hw *cl_hw, u8 ch_idx);
u8 cl_channel_to_index(struct cl_hw *cl_hw, u32 channel);
u16 cl_channel_idx_to_freq(struct cl_hw *cl_hw, u8 index);
bool cl_channel_is_valid(struct cl_hw *cl_hw, u8 channel);
u32 cl_channel_num(struct cl_hw *cl_hw);

#endif /* CL_CHANNEL_H */

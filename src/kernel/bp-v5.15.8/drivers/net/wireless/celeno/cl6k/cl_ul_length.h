/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_UL_LENGTH_H
#define CL_UL_LENGTH_H

#include <linux/types.h>
#include "def.h"

#define UL_LEN_DEFAULT_VAL 0x1072
#define UL_LEN_IDX_FACTOR  5 /* 2 ^ 5 = 32us */
#define UL_LEN_TABLE_ROWS  167
#define UL_LEN_MAX_IDX     (UL_LEN_TABLE_ROWS - 1)

struct cl_hw;

u16 cl_ul_length_get(u8 idx, u8 nss, u8 gi_ltf);
u16 cl_ul_length_get_duration(u32 bytes, u8 bw, u8 nss, u8 mcs, u8 gi);
void cl_ul_length_table_init(void);
void cl_ul_length_set_manual(struct cl_hw *cl_hw, u8 sta_idx, u8 ac, u32 bytes);

#endif /* CL_UL_LENGTH_H */

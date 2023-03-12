/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_POWER_H
#define CL_POWER_H

#include "cl_hw.h"

#define POWER_MAX_DB 30
#define POWER_MIN_DB -10

/*
 * Power offset is the user input in 0.25 dB resolution which represent -10 - 20 [dB]
 * and write to e2p/otp in PDI - Power Difference Index (valid values are 1 - 121 [0.25dBm])
 */
#define POWER_OFFSET_MIN_VAL -40
#define POWER_OFFSET_MAX_VAL 80

#define POWER_MIN_DB_Q1 (POWER_MIN_DB << 1)
#define POWER_MIN_DB_Q8 (POWER_MIN_DB << 8)

#define POWER_OFFSET_RES 4

#define POWER_OFFSET_MAX_Q2 (16 << 2)  /* +16dB * 4 */
#define POWER_OFFSET_MIN_Q2 (-16 << 2) /* -16dB * 4 */

u8 cl_power_tx_ant(struct cl_hw *cl_hw, enum cl_wrs_mode mode);
s32 cl_power_antenna_gain_q8(struct cl_hw *cl_hw);
s32 cl_power_antenna_gain_q1(struct cl_hw *cl_hw);
s32 cl_power_array_gain_q8(struct cl_hw *cl_hw, u8 tx_ant);
s8 cl_power_array_gain_q2(struct cl_hw *cl_hw, u8 tx_ant);
s32 cl_power_array_gain_q1(struct cl_hw *cl_hw, u8 tx_ant);
s32 cl_power_bf_gain_q1(struct cl_hw *cl_hw, u8 nss);
s32 cl_power_min_ant_q1(struct cl_hw *cl_hw);
s8 cl_power_bw_factor_q2(struct cl_hw *cl_hw, u8 bw);
s32 cl_power_average_calib_q1(struct cl_hw *cl_hw, u8 ant_num);
s32 cl_power_total_q1(struct cl_hw *cl_hw, s8 pwr_offset_q1, u8 tx_ant, u8 nss,
		      enum cl_wrs_mode mode, bool is_auto_resp);
s8 cl_power_offset_q1(struct cl_hw *cl_hw, u8 mode, u8 bw, u8 mcs);
s8 cl_power_offset_check_margin(struct cl_hw *cl_hw, u8 bw, u8 ant_idx, s8 offset_q2);
void cl_power_tables_update(struct cl_hw *cl_hw, struct cl_pwr_tables *pwr_tables);
s32 cl_power_get_max(struct cl_hw *cl_hw);

#endif /* CL_POWER_H */

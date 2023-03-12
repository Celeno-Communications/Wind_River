/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_ENHANCED_TIM_H
#define CL_ENHANCED_TIM_H

#include "cl_hw.h"
#include "cl_sta.h"

bool cl_enhanced_tim_is_ac_clear(struct cl_hw *cl_hw, u8 ac);
void cl_enhanced_tim_reset(struct cl_hw *cl_hw);
void cl_enhanced_tim_clear_tx_agg(struct cl_hw *cl_hw, u32 ipc_queue_idx,
				  u8 ac, struct cl_sta *cl_sta, u8 tid);
void cl_enhanced_tim_clear_tx_single(struct cl_hw *cl_hw, u32 ipc_queue_idx, u8 ac,
				     bool no_ps_buffer, struct cl_sta *cl_sta, u8 tid);
void cl_enhanced_tim_set_tx_agg(struct cl_hw *cl_hw, u32 ipc_queue_idx, u8 ac,
				bool no_ps_buffer, struct cl_sta *cl_sta, u8 tid);
void cl_enhanced_tim_set_tx_single(struct cl_hw *cl_hw, u32 ipc_queue_idx, u8 ac,
				   bool no_ps_buffer, struct cl_sta *cl_sta, u8 tid);
void cl_enhanced_tim_clear_rx(struct cl_hw *cl_hw, u8 ac, u8 sta_idx);
void cl_enhanced_tim_set_rx(struct cl_hw *cl_hw, u8 ac, u8 sta_idx);
void cl_enhanced_tim_clear_rx_sta(struct cl_hw *cl_hw, u8 sta_idx);
int cl_enhanced_tim_cli(struct cl_hw *cl_hw, struct cli_params *cli_params);

#endif /* CL_ENHANCED_TIM_H */

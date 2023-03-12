/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_AGG_CFM_H
#define CL_AGG_CFM_H

#include "cl_tx_queue.h"
#include "cl_ipc_shared.h"

void cl_agg_cfm_init(struct cl_hw *cl_hw);
void cl_agg_cfm_add(struct cl_hw *cl_hw, struct cl_sw_txhdr *sw_txhdr, u8 agg_idx);
int cl_agg_cfm_handle(struct cl_hw *cl_hw,
		      u16 new_ssn, u8 ba_queue_idx);
void cl_agg_cfm_flush_all(struct cl_hw *cl_hw);
void cl_agg_cfm_poll_empty(struct cl_hw *cl_hw, u8 agg_idx, bool flush);
void cl_agg_cfm_poll_empty_sta(struct cl_hw *cl_hw, struct cl_sta *cl_sta);
void cl_agg_cfm_clear_tim_bit_sta(struct cl_hw *cl_hw, struct cl_sta *cl_sta);
void cl_agg_cfm_set_ssn(struct cl_hw *cl_hw, u16 ssn, u8 idx);
void cl_agg_cfm_set_tx_queue(struct cl_hw *cl_hw, struct cl_tx_queue *tx_queue, u8 idx);

#endif /* CL_AGG_CFM_H */

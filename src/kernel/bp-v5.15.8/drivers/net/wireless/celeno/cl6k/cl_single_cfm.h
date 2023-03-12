/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_SINGLE_CFM_H
#define CL_SINGLE_CFM_H

#include "cl_tx.h"

void cl_single_cfm_init(struct cl_hw *cl_hw);
void cl_single_cfm_add(struct cl_hw *cl_hw,
		       struct cl_sw_txhdr *sw_txhdr,
		       u32 queue_idx);
void cl_single_cfm_handler(struct cl_hw *cl_hw, u32 cfm_status,
			   u32 dma_addr, u32 single_queue_idx);
void cl_single_cfm_flush_all(struct cl_hw *cl_hw);
void cl_single_cfm_poll_empty(struct cl_hw *cl_hw, u32 queue_idx);
void cl_single_cfm_poll_empty_sta(struct cl_hw *cl_hw, u8 sta_idx);
void cl_single_cfm_clear_tim_bit_sta(struct cl_hw *cl_hw, u8 sta_idx);

#endif /* CL_SINGLE_CFM_H */

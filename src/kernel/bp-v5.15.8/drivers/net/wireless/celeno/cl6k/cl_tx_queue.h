/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_TX_QUEUE_H
#define CL_TX_QUEUE_H

#include "cl_hw.h"
#include "cl_tx.h"

enum cl_queue_type {
	QUEUE_TYPE_SINGLE,
	QUEUE_TYPE_AGG,
	QUEUE_TYPE_BCMC,

	QUEUE_TYPE_MAX
};

#define QUEUE_IDX(sta, ac)  ((sta) + (ac) * FW_MAX_NUM_STA)
/* USB agg queue index incase single queue mode enabled */
#define CL_USB_AGG_QUEUE_IDX CL_HWQ_BE

void cl_txq_init(struct cl_hw *cl_hw);
void cl_txq_stop(struct cl_hw *cl_hw);
struct cl_tx_queue *cl_txq_get(struct cl_hw *cl_hw, struct cl_sw_txhdr *sw_txhdr);
void cl_txq_push(struct cl_hw *cl_hw, struct cl_sw_txhdr *sw_txhdr);
void cl_txq_sched(struct cl_hw *cl_hw, struct cl_tx_queue *tx_queue);
void cl_txq_agg_alloc(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
		      struct mm_ba_add_cfm *ba_add_cfm, u16 buf_size);
void cl_txq_agg_free(struct cl_hw *cl_hw, struct cl_tx_queue *tx_queue,
		     struct cl_sta *cl_sta, u8 tid);
void cl_txq_agg_stop(struct cl_sta *cl_sta, u8 tid);
u32 cl_txq_get_free_space(struct cl_hw *cl_hw, struct cl_sta *cl_sta, u8 tid);
void cl_txq_sta_add(struct cl_hw *cl_hw, struct cl_sta *cl_sta);
void cl_txq_sta_remove(struct cl_hw *cl_hw, u8 sta_idx);
void cl_txq_transfer_agg_to_single(struct cl_hw *cl_hw, struct cl_tx_queue *agg_queue);
void cl_txq_flush_agg(struct cl_hw *cl_hw, struct cl_tx_queue *tx_queue, bool lock);
void cl_txq_flush_single(struct cl_hw *cl_hw, u16 idx);
void cl_txq_flush_all_agg(struct cl_hw *cl_hw);
void cl_txq_flush_all_single(struct cl_hw *cl_hw);
void cl_txq_flush_sta(struct cl_hw *cl_hw, struct cl_sta *cl_sta);
void cl_txq_agg_request_add(struct cl_hw *cl_hw, u8 sta_idx, u8 tid);
void cl_txq_agg_request_del(struct cl_hw *cl_hw, u8 sta_idx, u8 tid);
bool cl_txq_is_agg_available(struct cl_hw *cl_hw);
bool cl_txq_single_is_full(struct cl_hw *cl_hw, u16 idx);
void cl_txq_single_sched(struct cl_hw *cl_hw, u16 idx);
bool cl_txq_agg_is_full(struct cl_hw *cl_hw, u16 idx);
bool cl_txq_is_fw_empty(struct cl_tx_queue *tx_queue);
bool cl_txq_is_fw_full(struct cl_tx_queue *tx_queue);
u16 cl_txq_desc_in_fw(struct cl_tx_queue *tx_queue);
bool cl_txq_frames_pending(struct cl_hw *cl_hw);
int cl_txq_cli(struct cl_hw *cl_hw, struct cli_params *cli_params);

#endif /* CL_TX_QUEUE_H */

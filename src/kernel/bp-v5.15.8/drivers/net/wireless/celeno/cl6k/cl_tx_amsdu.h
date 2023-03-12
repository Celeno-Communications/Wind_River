/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_TX_AMSDU_H
#define CL_TX_AMSDU_H

#include "cl_sta.h"

enum cl_amsdu_result {
	CL_AMSDU_ANCHOR_SET,
	CL_AMSDU_SUB_FRAME_SET,
	CL_AMSDU_SKIP,
	CL_AMSDU_FAILED
};

/* Max size of 802.11 WLAN header */
#define CL_WLAN_HEADER_MAX_SIZE 36
#define CL_AMSDU_MIN_AGG_SIZE 4

#define CL_AMSDU_CONST_LEN    256

#define CL_TX_AMSDU_MIN_LEN_X2 650
#define CL_TX_AMSDU_MIN_LEN_X3 1800

struct cl_amsdu_txhdr {
	struct list_head list;
	struct list_head list_pool;
	struct sk_buff *skb;
	dma_addr_t dma_addr;
};

void cl_tx_amsdu_anchor_init(struct cl_amsdu_ctrl *amsdu_anchor);
void cl_tx_amsdu_anchor_reset(struct cl_amsdu_ctrl *amsdu_anchor);
void cl_tx_amsdu_set_max_len(struct cl_hw *cl_hw, struct cl_sta *cl_sta, u8 tid);
void cl_tx_amsdu_first_sub_frame(struct cl_sw_txhdr *sw_txhdr, struct cl_sta *cl_sta,
				 struct sk_buff *skb, u8 tid);
void cl_tx_amsdu_flush_sub_frames(struct cl_hw *cl_hw, struct cl_sw_txhdr *sw_txhdr);
void cl_tx_amsdu_transfer_single(struct cl_hw *cl_hw, struct cl_sw_txhdr *sw_txhdr);
int cl_tx_amsdu_set(struct cl_hw *cl_hw, struct cl_sta *cl_sta, struct sk_buff *skb, u8 tid);
void cl_tx_amsdu_unset(struct cl_sw_txhdr *sw_txhdr);

int cl_tx_amsdu_txhdr_init(struct cl_hw *cl_hw);
void cl_tx_amsdu_txhdr_deinit(struct cl_hw *cl_hw);
void cl_tx_amsdu_txhdr_free(struct cl_hw *cl_hw, struct cl_amsdu_txhdr *amsdu_txhdr);

#endif /* CL_TX_AMSDU_H */

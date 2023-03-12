/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_SW_TXHDR_H
#define CL_SW_TXHDR_H

#include "cl_utils.h"
#include "cl_tx_amsdu.h"

struct cl_sw_txhdr {
	struct list_head list_pool;
	struct list_head tx_queue_list;
	struct list_head cfm_list;
	struct ieee80211_hdr *hdr80211;
	struct cl_tx_queue *tx_queue;
	struct cl_sta *cl_sta;
	struct cl_vif *cl_vif;
	struct cl_amsdu_txhdr amsdu_txhdr;
	u8 hw_queue            : 3,
	   is_bcn              : 1,
	   tid                 : 4;
	u8 ac                  : 2,
	   is_sw_amsdu         : 1,
	   sw_amsdu_packet_cnt : 4,
	   rsv                 : 1;
	/*
	 * singles queue index used to push the txdesc to the ipc layer
	 * this issue solve race condition in which we
	 * CFM of packet that associated with disconnected STA and has invalid
	 * cl_sta pointerinside this struct
	 */
	u8 sta_idx;
	__le16 fc;
	struct sk_buff *skb;
	struct txdesc txdesc;
	size_t map_len;
	u16 total_pkt_len;
};

int cl_sw_txhdr_init(struct cl_hw *cl_hw);
void cl_sw_txhdr_deinit(struct cl_hw *cl_hw);
struct cl_sw_txhdr *cl_sw_txhdr_alloc(struct cl_hw *cl_hw);
void cl_sw_txhdr_free(struct cl_hw *cl_hw, struct cl_sw_txhdr *sw_txhdr);

#endif /* CL_SW_TXHDR_H */

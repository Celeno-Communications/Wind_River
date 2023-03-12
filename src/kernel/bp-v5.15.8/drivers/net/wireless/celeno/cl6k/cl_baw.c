// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_baw.h"
#include "cl_tx.h"

void cl_baw_init(struct cl_sta *cl_sta)
{
	u8 tid;

	for (tid = 0; tid < IEEE80211_NUM_TIDS; tid++)
		__skb_queue_head_init(&cl_sta->baws[tid].pending);
}

void cl_baw_start(struct cl_baw *baw, u16 ssn)
{
	baw->ssn = ssn;
	baw->action_start = true;
}

void cl_baw_operational(struct cl_hw *cl_hw, struct cl_baw *baw,
			u8 fw_agg_idx, bool amsdu_supported)
{
	baw->fw_agg_idx = fw_agg_idx;
	baw->tid_seq = IEEE80211_SN_TO_SEQ(baw->ssn);
	baw->amsdu = (cl_hw->txamsdu_en && amsdu_supported);
}

void cl_baw_stop(struct cl_baw *baw)
{
	baw->action_start = false;
}

void cl_baw_tx_inject(struct cl_hw *cl_hw,
		      struct cl_baw *baw,
		      u8 fw_agg_idx)
{
	baw->ssn = 0;
	baw->fw_agg_idx = fw_agg_idx;
	baw->tid_seq = IEEE80211_SN_TO_SEQ(0);
	baw->amsdu = cl_hw->txamsdu_en;
}

void cl_baw_pending_to_agg(struct cl_hw *cl_hw,
			   struct cl_sta *cl_sta,
			   u8 tid)
{
	struct cl_baw *baw = &cl_sta->baws[tid];
	struct sk_buff *skb;

	while (!skb_queue_empty(&baw->pending)) {
		skb = __skb_dequeue(&baw->pending);
		cl_tx_fast_agg(cl_hw, cl_sta, skb, false);
	}
}

void cl_baw_pending_to_single(struct cl_hw *cl_hw,
			      struct cl_sta *cl_sta,
			      struct cl_baw *baw)
{
	struct sk_buff *skb;

	while (!skb_queue_empty(&baw->pending)) {
		skb = __skb_dequeue(&baw->pending);
		cl_tx_fast_single(cl_hw, cl_sta, skb, false);
	}
}

void cl_baw_pending_purge(struct cl_baw *baw)
{
	if (!skb_queue_empty(&baw->pending))
		__skb_queue_purge(&baw->pending);
}

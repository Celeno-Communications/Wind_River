/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_RX_AMSDU_H
#define CL_RX_AMSDU_H

#include "cl_hw.h"
#include "cl_rx.h"

enum rx_amsdu_error {
	RX_AMSDU_ERR_CORRUPTED = BIT(0),
	RX_AMSDU_ERR_LENGTH = BIT(1),
	RX_AMSDU_ERR_NOT_SUCCESS = BIT(2),
	RX_AMSDU_ERR_UNENCRYPTED = BIT(3),
	RX_AMSDU_ERR_DECRYPT_FAIL = BIT(4),
	RX_AMSDU_ERR_INVALID_TAILROOM = BIT(5),
	RX_AMSDU_ERR_INVALID_PN_TSC = BIT(6),
};

void cl_rx_amsdu_first(struct cl_hw *cl_hw, struct sk_buff *skb,
		       struct hw_rxhdr *rxhdr, struct cl_rx_w2e_hdr *w2e_hdr,
		       u8 sta_idx, u8 tid, u8 encrypt_len);
bool cl_rx_amsdu_sub(struct cl_hw *cl_hw, struct sk_buff *skb);
void cl_rx_amsdu_first_corrupted(struct cl_hw *cl_hw, struct sk_buff *skb,
				 struct hw_rxhdr *rxhdr);
void cl_rx_amsdu_sub_error(struct cl_hw *cl_hw, struct sk_buff *skb);
void cl_rx_amsdu_set_state_error(struct cl_hw *cl_hw,
				 struct hw_rxhdr *rxhdr,
				 enum rx_amsdu_error err);
void cl_rx_amsdu_reset(struct cl_hw *cl_hw);
void cl_rx_amsdu_stats(struct cl_hw *cl_hw, u8 msdu_cnt);
void cl_rx_amsdu_hw_en(struct ieee80211_hw *hw, bool rxamsdu_en);

#endif /* CL_RX_AMSDU_H */

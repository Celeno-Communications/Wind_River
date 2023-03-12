/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_RX_REORDER_H
#define CL_RX_REORDER_H

#include "cl_hw.h"
#include "cl_sta.h"

int cl_rx_reorder_ampdu(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
			struct cl_tid_ampdu_rx *tid_agg_rx,
			struct cl_rx_w2e_hdr *w2e_hdr,
			struct hw_rxhdr *rxhdr,
			struct sk_buff_head *skb_list,
			struct sk_buff_head *ordered_mpdu);
void cl_rx_reorder_close(struct cl_sta *cl_sta, u8 tid);
void cl_rx_reorder_init(struct cl_hw *cl_hw, struct cl_sta *cl_sta, u8 tid, u16 buf_size);

#endif /* CL_RX_REORDER_H */

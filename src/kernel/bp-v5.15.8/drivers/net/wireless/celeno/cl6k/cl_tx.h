/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_TX_H
#define CL_TX_H

#include "cl_hw.h"
#include "cl_sta.h"
#include "cl_vif.h"
#include "cl_debugfs.h"
#include "cl_ipc_shared.h"
#include "cl_sw_txhdr.h"

#define INC_SN(sn) (((sn) + 0x10) & IEEE80211_SCTL_SEQ)
#define DEC_SN(sn) (((sn) - 0x10) & IEEE80211_SCTL_SEQ)

#define CL_TX_LIFETIME_MS 4000

#define CL_SKB_DATA_ALIGN_SZ      4
#define CL_SKB_DATA_ALIGN_MSK     (CL_SKB_DATA_ALIGN_SZ - 1)
#define CL_SKB_DATA_ALIGN_PADS(x) \
	((CL_SKB_DATA_ALIGN_SZ - ((ptrdiff_t)(x) & CL_SKB_DATA_ALIGN_MSK)) & CL_SKB_DATA_ALIGN_MSK)

#define CL_TX_MAX_FRAME_LEN_SINGLE 4096
#define CL_TX_MAX_FRAME_LEN_AGG 2000

struct cl_hw_tx_status {
	u32 mcs_index          : 7; /* [6:0] */
	u32 is_bcmc            : 1; /* [7] */
	u32 num_mpdu_retries   : 4; /* [11:8] */
	u32 rsv                : 4; /* [15:12] */
	u32 format_mod         : 4; /* [19:16] */
	u32 bw_requested       : 2; /* [21:20] */
	u32 bf                 : 1; /* [22] */
	u32 frm_successful     : 1; /* [23] */
	u32 bw_transmitted     : 2; /* [25:24] */
	u32 freespace_inc_skip : 1; /* [26] */
	u32 keep_skb           : 1; /* [27] */
	u32 gi                 : 2; /* [29:28] */
	u32 descriptor_done_sw : 1; /* [30] */
	u32 descriptor_done_hw : 1; /* [31] */
};

enum cl_tx_single_frame_type {
	CL_TX_SINGLE_FRAME_TYPE_QOS_DATA,
	CL_TX_SINGLE_FRAME_TYPE_QOS_NULL,
	CL_TX_SINGLE_FRAME_TYPE_MANAGEMENT,
	CL_TX_SINGLE_FRAME_TYPE_OTHER
};

void cl_tx_handle_tx_path_idle(struct cl_hw *cl_hw, u8 bitmap);
void cl_tx_check_start_ba_session(struct cl_hw *cl_hw,
				  struct sta_info *stainfo,
				  struct sk_buff *skb);
void cl_tx_bcns(struct cl_hw *cl_hw);
void cl_tx_single_free_skb(struct cl_hw *cl_hw, struct sk_buff *skb);
void cl_tx_single(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
		  struct sk_buff *skb, bool is_vns, bool lock);
void cl_tx_fast_single(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
		       struct sk_buff *skb, bool lock);
void cl_tx_agg_prep(struct cl_hw *cl_hw, struct cl_sw_txhdr *sw_txhdr,
		    u16 frame_len, u8 hdr_pads, bool hdr_conv);
void cl_tx_agg(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
	       struct sk_buff *skb, bool hdr_conv, bool lock);
void cl_tx_fast_agg(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
		    struct sk_buff *skb, bool lock);
u16 cl_tx_prepare_wlan_hdr(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
			   struct sk_buff *skb, struct ieee80211_hdr *hdr);
void cl_tx_wlan_to_8023(struct sk_buff *skb);
int cl_tx_8023_to_wlan(struct cl_hw *cl_hw, struct sk_buff *skb, struct cl_sta *cl_sta, u8 tid);
void cl_tx_push(struct cl_hw *cl_hw, struct cl_sw_txhdr *sw_txhdr, struct cl_tx_queue *tx_queue);
void cl_tx_bcn_mesh_task(unsigned long data);
void cl_tx_en(struct cl_hw *cl_hw, u8 reason, bool enable);
void cl_tx_off(struct cl_hw *cl_hw);
void cl_tx_drop_skb(struct sk_buff *skb);
netdev_tx_t ___cl_tx_start(struct cl_hw *cl_hw, struct sk_buff *skb, struct net_device *dev);
netdev_tx_t __cl_tx_start(struct cl_hw *cl_hw, struct sk_buff *skb, struct net_device *dev);
netdev_tx_t _cl_tx_start(struct cl_hw *cl_hw, struct sk_buff *skb, struct net_device *dev);
netdev_tx_t cl_tx_start(struct sk_buff *skb, struct net_device *dev);
int cl_tx_cli(struct cl_hw *cl_hw, struct cli_params *cli_params);

static inline bool cl_tx_ctrl_is_amsdu(struct ieee80211_tx_info *tx_info)
{
	return !!(tx_info->control.flags & IEEE80211_TX_CTRL_AMSDU);
}

static inline bool cl_tx_ctrl_is_eapol(struct ieee80211_tx_info *tx_info)
{
	return !!(tx_info->control.flags & IEEE80211_TX_CTRL_PORT_CTRL_PROTO);
}

static inline bool cl_tx_ctrl_is_inject(struct ieee80211_tx_info *tx_info)
{
	/*
	 * Check that IEEE80211_TX_CTL_INJECTED is set and that
	 * IEEE80211_TX_INTFL_NL80211_FRAME_TX isn't to distinguish between
	 * TX-inject packets that Celeno driver generates and TX-inject packets
	 * that mac80211 generates in ieee80211_tx_control_port().
	 */
	return ((tx_info->flags & IEEE80211_TX_CTL_INJECTED) &&
		!(tx_info->flags & IEEE80211_TX_INTFL_NL80211_FRAME_TX));
}

#endif /* CL_TX_H */

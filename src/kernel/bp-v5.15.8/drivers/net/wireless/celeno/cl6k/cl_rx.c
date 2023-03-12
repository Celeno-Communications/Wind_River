// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_tx.h"
#include "cl_rx.h"
#include "cl_rx_amsdu.h"
#include "cl_stats.h"
#include "cl_rate_ctrl.h"
#include "cl_rssi.h"
#include "cl_age_out.h"
#include "cl_band.h"
#include "cl_bw_sig.h"
#include "cl_utils.h"
#include "cl_vns.h"
#include "cl_wrs_api.h"
#include "cl_twt.h"
#include "cl_cma.h"
#include "cl_m2u.h"
#include "cl_bss_color.h"
#include "cl_bsrp.h"
#include "cl_recovery.h"
#include "cl_fw_dbg.h"
#include "cl_tf.h"
#include "def.h"
#include "cl_rx_reorder.h"
#include "cl_msg_tx.h"
#include "cl_key.h"
#include "cl_rx_pci.h"
#ifdef TRACE_SUPPORT
#include "cl_trace.h"
#endif

/* Must correspond to FW definition of MM_SEC_DEFAULT_KEY_COUNT */
#define MM_SEC_DEFAULT_KEY_COUNT 64

#define VHT_MCS_MASK 0x0F
#define VHT_MCS_OFT  0

/* Number of entries in HW legacy rate conversion table */
#define LEGACY_RATE_MAX 16

static const s8 legacy_rates_lut[LEGACY_RATE_MAX] = {
	0,      /* 0: 1 Mbps   */
	1,      /* 1: 2 Mbps   */
	2,      /* 2: 5.5 Mbps */
	3,      /* 3: 11 Mbps  */
	-1,     /* 4: Invalid  */
	-1,     /* 5: Invalid  */
	-1,     /* 6: Invalid  */
	-1,     /* 7: Invalid  */
	10,     /* 8: 48 Mbps  */
	8,      /* 9: 24 Mbps  */
	6,      /* 10: 12 Mbps */
	4,      /* 11: 6 Mbps  */
	11,     /* 12: 54 Mbps */
	9,      /* 13: 36 Mbps */
	7,      /* 14: 18 Mbps */
	5       /* 15: 9 Mbps  */
};

/*
 * rx_skb_cnt is an atomic counter that tracks the total number of skbs in
 * the entire host.
 * The counter is incremented when skb is allocated, and freed when the skb
 * is freed (=destructor function called).
 * Therefore the counter is global (and not part of cl_hw or cl_chip).
 *
 * rx_skb_max is the configured to:
 * max(chip0->conf->ci_rx_skb_max, chip1->conf->ci_rx_skb_max)
 */
static atomic_t rx_skb_cnt = ATOMIC_INIT(0);
static u32 rx_skb_max;

static void cl_rx_skb_destructor(struct sk_buff *skb)
{
	atomic_dec(&rx_skb_cnt);
}

static void cl_rx_update_stats(struct net_device *dev,
			       u32 rx_packets, u32 rx_bytes)
{
	struct pcpu_sw_netstats *tstats = this_cpu_ptr(dev->tstats);

	u64_stats_update_begin(&tstats->syncp);
	tstats->rx_bytes += rx_bytes;
	tstats->rx_packets += rx_packets;
	u64_stats_update_end(&tstats->syncp);
}

static void cl_rx_skb_success(struct cl_hw *cl_hw,
			      struct cl_vif *cl_vif,
			      struct sk_buff *skb,
			      struct cl_rx_w2e_hdr *w2e_hdr,
			      u32 rx_packets, u32 rx_bytes)
{
	if (w2e_hdr)
		cl_hw->rx_info.w2e_done += rx_packets;

	if (cl_vif) {
		u8 ac = cl_get_skb_ac(cl_vif->cl_hw, skb, w2e_hdr);

		cl_vif->trfc_cntrs[ac].rx_packets += rx_packets;
		cl_vif->trfc_cntrs[ac].rx_bytes += rx_bytes;
		cl_rx_update_stats(cl_vif->dev, rx_packets, rx_bytes);
	}
}

static void cl_rx_skb_drop(struct cl_vif *cl_vif, struct sk_buff *skb,
			   struct cl_rx_w2e_hdr *w2e_hdr, u8 cnt)
{
	if (cl_vif) {
		u8 ac = cl_get_skb_ac(cl_vif->cl_hw, skb, w2e_hdr);

		cl_vif->trfc_cntrs[ac].rx_dropped += cnt;
	}
}

static int cl_rx_check_err(struct cl_hw *cl_hw, struct sk_buff *skb, struct hw_rxhdr *rxhdr)
{
	if (rxhdr->frm_successful_rx)
		return 0;

	/* Ignore phy errors and do not drop the packet */
	if (rxhdr->phy_err) {
		cl_hw->radio_stats[CL_RADIO_PHY_ERROR]++;
		cl_dbg_err(cl_hw, "phy_err\n");
		return 0;
	}

	/* From this point and on, drop the erroneous packets */
	if (rxhdr->fcs_err) {
		cl_hw->radio_stats[CL_RADIO_FCS_ERROR]++;
		cl_dbg_err(cl_hw, "fcs_err\n");
	}

	if (rxhdr->rx_fifo_oflow) {
		cl_hw->radio_stats[CL_RADIO_RX_FIFO_OVERFLOW]++;
		cl_dbg_err(cl_hw, "rx_fifo_oflow\n");
	}

	if (rxhdr->undef_err) {
		cl_hw->radio_stats[CL_RADIO_UNDEFINED_ERROR]++;
		cl_dbg_err(cl_hw, "undef_err\n");
	}

	if (rxhdr->addr_mismatch) {
		cl_hw->radio_stats[CL_RADIO_ADDRESS_MISMATCH]++;
		cl_dbg_err(cl_hw, "addr_mismatch\n");
	}

	if (rxhdr->amsdu_present && rxhdr->msdu_cnt > 1)
		cl_rx_amsdu_set_state_error(cl_hw, rxhdr, RX_AMSDU_ERR_NOT_SUCCESS);

	cl_hw->rx_info.pkt_drop_not_success++;
	cl_rx_skb_error(cl_hw);
	kfree_skb(skb);

	return -1;
}

static u8 chnl_bw_to_rate_info_bw[CHNL_BW_MAX] = {
	[CHNL_BW_20] = RATE_INFO_BW_20,
	[CHNL_BW_40] = RATE_INFO_BW_40,
	[CHNL_BW_80] = RATE_INFO_BW_80,
	[CHNL_BW_160] = RATE_INFO_BW_160,
};

static u8 chnl_bw_factor[CHNL_BW_MAX] = {
	[CHNL_BW_20] = 0,
	[CHNL_BW_40] = 3,
	[CHNL_BW_80] = 6,
	[CHNL_BW_160] = 9,
};

static int cl_rx_fill_status(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
			     struct sk_buff *skb, struct hw_rxhdr *rxhdr,
			     u8 *encrypt_len, __le16 fc,
			     struct cl_tid_ampdu_rx *tid_agg_rx)
{
	s8 rssi[MAX_ANTENNAS] = RX_HDR_RSSI(rxhdr);
	struct ieee80211_rx_status *status = IEEE80211_SKB_RXCB(skb);
	u8 factor = chnl_bw_factor[rxhdr->ch_bw];

	memset(status, 0, sizeof(struct ieee80211_rx_status));

	status->mactime = ((u64)le32_to_cpu((rxhdr->tsf_hi)) << 32) | le32_to_cpu(rxhdr->tsf_lo);
	status->flag |= RX_FLAG_MACTIME_END;

	if (cl_sta && tid_agg_rx)
		status->flag |= RX_FLAG_DUP_VALIDATED;

	status->antenna = rxhdr->antenna_set;
	status->band = cl_band_from_fw_idx(rxhdr->phy_band);

	if (rxhdr->format_mod >= FORMATMOD_HE_SU) {
		status->encoding = RX_ENC_HE;
		status->rate_idx = (rxhdr->mcs & VHT_MCS_MASK) >> VHT_MCS_OFT;
		status->nss = rxhdr->n_sts + 1;

		/* he_gi expectes to get values according to enum nl80211_he_gi */
		status->he_gi = convert_gi_format_wrs_to_fw(WRS_MODE_HE, rxhdr->gi_type);
	} else if (rxhdr->format_mod == FORMATMOD_VHT) {
		status->encoding = RX_ENC_VHT;
		status->rate_idx = (rxhdr->mcs & VHT_MCS_MASK) >> VHT_MCS_OFT;
		status->nss = rxhdr->n_sts + 1;

		if (rxhdr->gi_type)
			status->enc_flags |= RX_ENC_FLAG_SHORT_GI;
	} else if (rxhdr->format_mod == FORMATMOD_HT_GF) {
		status->encoding = RX_ENC_HT;
		status->enc_flags |= RX_ENC_FLAG_HT_GF;
		status->rate_idx = rxhdr->mcs;

		if (rxhdr->gi_type)
			status->enc_flags |= RX_ENC_FLAG_SHORT_GI;

	} else if (rxhdr->format_mod == FORMATMOD_HT_MF) {
		status->encoding = RX_ENC_HT;
		status->rate_idx = rxhdr->mcs;

		if (rxhdr->gi_type)
			status->enc_flags |= RX_ENC_FLAG_SHORT_GI;
	} else {
		if (legacy_rates_lut[rxhdr->leg_rate] != -1)
			status->rate_idx = legacy_rates_lut[rxhdr->leg_rate];
		if (status->band != NL80211_BAND_2GHZ)
			status->rate_idx -= RATE_CTRL_OFFSET_OFDM;
		if (!rxhdr->pre_type)
			status->enc_flags |= RX_ENC_FLAG_SHORTPRE;
	}

	if (rxhdr->aggregation) {
		status->flag |= RX_FLAG_AMPDU_DETAILS;
		status->ampdu_reference = rxhdr->ampdu_cnt;
	}

	/* Set bw field */
	status->bw = chnl_bw_to_rate_info_bw[rxhdr->ch_bw];
	cl_rssi_bw_adjust(cl_hw, rxhdr, factor);

	/*
	 * Todo check if when a frame is received on 40MHz or more bandwidth,
	 * we need to take the center1_freq instead of the prim20_freq
	 */
	status->freq = Q2_TO_FREQ(rxhdr->phy_prim20_freq);

	status->signal = cl_rssi_calc_equivalent(cl_hw, rssi);

	switch (rxhdr->decr_status) {
	case CL_RX_HD_DECR_UNENC:
		if (ieee80211_has_protected(fc)) {
			cl_dbg_warn(cl_hw, "Protected frame unencrypted\n");
			cl_hw->rx_info.pkt_drop_unencrypted++;
			if (rxhdr->amsdu_present && rxhdr->msdu_cnt > 1)
				cl_rx_amsdu_set_state_error(cl_hw, rxhdr,
							    RX_AMSDU_ERR_UNENCRYPTED);
			return -1;
		}
		break;
	case CL_RX_HD_DECR_ICVFAIL:
	case CL_RX_HD_DECR_AMSDUDISCARD:
	case CL_RX_HD_DECR_NULLKEY:
	case CL_RX_HD_DECR_CCMPFAIL:
		cl_dbg_warn(cl_hw, "Decryption failed (%u)\n", rxhdr->decr_status);
		cl_hw->rx_info.pkt_drop_decrypt_fail++;
		*encrypt_len = 0;
		if (rxhdr->amsdu_present && rxhdr->msdu_cnt > 1)
			cl_rx_amsdu_set_state_error(cl_hw, rxhdr, RX_AMSDU_ERR_DECRYPT_FAIL);
		return -1;
	case CL_RX_HD_DECR_WEPSUCCESS:
	case CL_RX_HD_DECR_TKIPSUCCESS:
		*encrypt_len = IEEE80211_WEP_ICV_LEN;
		status->flag |= (RX_FLAG_DECRYPTED | RX_FLAG_ICV_STRIPPED);
		break;
	case CL_RX_HD_DECR_CCMPSUCCESS:
		*encrypt_len = IEEE80211_CCMP_HDR_LEN;
		status->flag |= (RX_FLAG_DECRYPTED | RX_FLAG_MIC_STRIPPED);
		break;
	}

	return 0;
}

static void cl_rx_action_twt_setup(struct cl_hw *cl_hw, struct cl_ieee80211_mgmt *mgmt,
				   int len, struct cl_sta *cl_sta)
{
	u32 min_size = 0;
	u8 negotiation_type =
		mgmt->u.action.u.twt_individual_setup.twt_elem.control.fields.negotiation_type;

	/* Individual TWT */
	if ((negotiation_type & 0x2) == 0) {
		/* Verify min size */
		min_size = IEEE80211_MIN_ACTION_SIZE  + 4 +
			sizeof(mgmt->u.action.u.twt_individual_setup.twt_elem);

		if (len < min_size) {
			cl_dbg_err(cl_hw, "TWT: Individual setup action frame length error\n");
			return;
		}

		/* Regular individual TWT */
		if (negotiation_type == 0)
			cl_twt_handle_individual_setup_request(cl_hw, cl_sta, mgmt);
	} else { /* Broadcast TWT */
		/* Verify min size */
		min_size = IEEE80211_MIN_ACTION_SIZE  + 4 +
			sizeof(mgmt->u.action.u.twt_broadcast_setup.twt_elem);

		if (len < min_size) {
			cl_dbg_err(cl_hw, "TWT: Broadcast setup action frame length error\n");
			return;
		}
	}
}

static void cl_rx_action_twt_teardown(struct cl_hw *cl_hw, struct cl_ieee80211_mgmt *mgmt,
				      int len, struct cl_sta *cl_sta)
{
	u8 negotiation_type;

	if (len < IEEE80211_MIN_ACTION_SIZE + 2) {
		cl_dbg_err(cl_hw, "Invalid length of TWT teardown action frame\n");
		return;
	}

	negotiation_type = mgmt->u.action.u.twt_individual_teardown.negotiation_type;

	if (negotiation_type <= 1)
		cl_twt_handle_individual_teardown_request(cl_hw, cl_sta, mgmt);
}

static void cl_rx_action_frame_handler(struct cl_hw *cl_hw, struct cl_ieee80211_mgmt *mgmt,
				       int len, struct cl_sta *cl_sta)
{
	/* Verify action code is present */
	if (len < IEEE80211_MIN_ACTION_SIZE + 1)
		return;

	switch (mgmt->u.action.category) {
	case WLAN_CATEGORY_S1G:
		if (!cl_twt_is_enabled(cl_hw))
			break;

		if (cl_sta->cl_vif->vif->type != NL80211_IFTYPE_AP)
			break;

		switch (mgmt->u.action.u.twt_individual_setup.action_code) {
		case WLAN_UNPROT_S1G_ACTION_TWT_SETUP:
			cl_rx_action_twt_setup(cl_hw, mgmt, len, cl_sta);
			break;
		case WLAN_UNPROT_S1G_ACTION_TWT_TEARDOWN:
			cl_rx_action_twt_teardown(cl_hw, mgmt, len, cl_sta);
			break;
		default:
			break;
		}
		break;
	case WLAN_CATEGORY_WNM:
		if (cl_sta)
			cl_bss_color_check_action(cl_sta->cl_vif, (struct ieee80211_mgmt *)mgmt);
		break;
	default:
		break;
	}
}

static void cl_rx_check_color_change(struct cl_hw *cl_hw,
				     struct ieee802_11_elems *elems,
				     struct cl_vif *cl_vif)
{
	struct ieee80211_bss_conf *bss_conf = &cl_vif->vif->bss_conf;
	struct cfg80211_he_bss_color he_bss_color = {0};

	he_bss_color.color = le32_get_bits(elems->he_operation->he_oper_params,
					   IEEE80211_HE_OPERATION_BSS_COLOR_MASK);
	he_bss_color.partial = le32_get_bits(elems->he_operation->he_oper_params,
					     IEEE80211_HE_OPERATION_PARTIAL_BSS_COLOR);
	he_bss_color.enabled = !le32_get_bits(elems->he_operation->he_oper_params,
					      IEEE80211_HE_OPERATION_BSS_COLOR_DISABLED);

	if (he_bss_color.color != bss_conf->he_bss_color.color ||
	    he_bss_color.partial !=  bss_conf->he_bss_color.partial ||
	    he_bss_color.enabled != bss_conf->he_bss_color.enabled) {
		cl_dbg_verbose(cl_hw, "BSS color info changed\n");
		memcpy(&bss_conf->he_bss_color, &he_bss_color,
		       sizeof(struct cfg80211_he_bss_color));
		cl_msg_tx_set_bss_color(cl_vif, &he_bss_color);
	}
}

static struct ieee80211_he_6ghz_oper *
cl_rx_get_he_6ghz_oper(const struct ieee80211_he_operation *he_oper)
{
	const u8 *ret = (void *)&he_oper->optional;
	u32 he_oper_params;

	he_oper_params = le32_to_cpu(he_oper->he_oper_params);

	if (!(he_oper_params & IEEE80211_HE_OPERATION_6GHZ_OP_INFO))
		return NULL;
	if (he_oper_params & IEEE80211_HE_OPERATION_VHT_OPER_INFO)
		ret += 3;
	if (he_oper_params & IEEE80211_HE_OPERATION_CO_HOSTED_BSS)
		ret++;

	return (void *)ret;
}

static void
cl_rx_check_he_minrate_change(struct cl_sta *cl_sta,
			      const struct ieee80211_he_operation *he_oper)
{
	struct ieee80211_he_6ghz_oper *
		he_6ghz_oper = cl_rx_get_he_6ghz_oper(he_oper);

	if (!he_6ghz_oper)
		return;

	if (he_6ghz_oper->minrate != cl_sta->wrs_sta.he_minrate)
		cl_wrs_api_he_minrate_changed(cl_sta, he_6ghz_oper->minrate);
}

static void cl_rx_handle_beacon(struct cl_hw *cl_hw,
				struct sk_buff *skb,
				struct cl_sta *cl_sta)
{
	struct ieee802_11_elems elems;
	struct cl_vif *cl_vif = cl_sta->cl_vif;
	struct ieee80211_mgmt *mgmt = (struct ieee80211_mgmt *)skb->data;
	size_t baselen = offsetof(struct ieee80211_mgmt, u.beacon.variable);
	struct ieee80211_bss_conf *bss_conf = &cl_vif->vif->bss_conf;

	if (cl_vif->vif->type != NL80211_IFTYPE_STATION)
		return;

	ieee802_11_parse_elems(mgmt->u.beacon.variable, skb->len - baselen,
			       false, &elems, mgmt->bssid, NULL);

	if (!elems.parse_error && elems.he_operation && bss_conf->he_support) {
		cl_rx_check_color_change(cl_hw, &elems, cl_vif);
		cl_rx_check_he_minrate_change(cl_sta, elems.he_operation);
	}
}

static void cl_rx_mgmt_check(struct cl_hw *cl_hw, struct sk_buff *skb,
			     struct cl_sta *cl_sta, struct hw_rxhdr *rxhdr)
{
	struct ieee80211_mgmt *mgmt = (struct ieee80211_mgmt *)skb->data;
	__le16 fc = mgmt->frame_control;

	if (cl_sta) {
		if (ieee80211_is_beacon(fc))
			cl_rx_handle_beacon(cl_hw, skb, cl_sta);
		else if (ieee80211_is_action(fc))
			cl_rx_action_frame_handler(cl_hw, (struct cl_ieee80211_mgmt *)mgmt,
						   skb->len, cl_sta);
	} else {
		s8 rssi[MAX_ANTENNAS] = RX_HDR_RSSI(rxhdr);

		cl_vns_mgmt_handler(cl_hw, mgmt->sa, rssi);

		if (ieee80211_is_assoc_req(fc) || ieee80211_is_assoc_resp(fc))
			cl_rssi_assoc_handle(cl_hw, mgmt->sa, rxhdr);
	}
}

static void cl_rx_ctl_check(struct cl_hw *cl_hw, struct sk_buff *skb,
			    struct cl_sta *cl_sta, struct hw_rxhdr *rxhdr)
{
	struct ieee80211_hdr *hdr = (struct ieee80211_hdr *)skb->data;
	__le16 fc = hdr->frame_control;

	/* Note: "num_extn_ss" field has 2 uses: chBWInNonHT/numExtnSS */
	if (cl_sta && ieee80211_is_pspoll(fc) &&
	    cl_hw->bw_sig_debug_mode == CL_BW_SIG_DEBUG_PS_POLL) {
		cl_dbg_verbose(cl_hw,
			       "RX PS-POLL from %pM, BW=%u, KSR_ID=%u, KSR_V=%u\n",
			       hdr->addr2, rxhdr->num_extn_ss, rxhdr->key_sram_index,
			       rxhdr->key_sram_v);
	}

	if (ieee80211_is_cts(fc) &&
	    cl_hw->bw_sig_debug_mode == CL_BW_SIG_DEBUG_RTS)
		cl_dbg_verbose(cl_hw, "RX CTS with BW=%u\n",
			       rxhdr->num_extn_ss);
	else if (ieee80211_is_ack(fc) &&
		 cl_hw->bw_sig_debug_mode == CL_BW_SIG_DEBUG_PS_POLL)
		cl_dbg_verbose(cl_hw, "RX ACK with BW=%u\n",
			       rxhdr->num_extn_ss);
}

static void cl_rx_data_check(struct cl_hw *cl_hw, struct sk_buff *skb,
			     struct cl_sta *cl_sta, u32 packet_len, struct hw_rxhdr *rxhdr)
{
	if (cl_sta) {
		cl_traffic_rx_handler(cl_hw, cl_sta, packet_len);
		cl_age_out_reset_counter(cl_hw, cl_sta);
	}
}

static bool cl_rx_skb_done(struct cl_hw *cl_hw, struct sk_buff *skb,
			   struct cl_sta *cl_sta, struct hw_rxhdr *rxhdr,
			   __le16 fc, struct cl_rx_w2e_hdr *w2e_hdr)
{
	struct ieee80211_rx_status *status = IEEE80211_SKB_RXCB(skb);
	struct cl_vif *cl_vif = NULL;

	/* Update trigger base statistics */
	cl_fw_dbg_trigger_based_update(cl_hw, rxhdr, fc);

	if (cl_hw->tf_params.enable && rxhdr->format_mod == FORMATMOD_HE_TRIG)
		cl_tf_handle_response(cl_hw);

	if (cl_sta) {
		cl_vif = cl_sta->cl_vif;
		skb->dev = cl_vif->dev;

		cl_bsrp_data_pending_dec(cl_hw, cl_sta, skb,
					 w2e_hdr, skb->len);
		cl_bsrp_parse_bsr(cl_hw, skb, cl_sta, w2e_hdr);
		cl_tf_handler(cl_hw, skb, cl_sta, w2e_hdr);
		cl_stats_update_rx_rate(cl_hw, cl_sta, rxhdr);

		if (!rxhdr->aggregation || (rxhdr->aggregation && rxhdr->mpdu_cnt == 0))
			cl_rssi_rx_handler(cl_hw, cl_sta, rxhdr, status->signal);
	} else {
		cl_vif = cl_vif_get_by_mac(cl_hw, cl_get_da_addr(cl_hw, skb,
								 w2e_hdr));
		skb->dev = cl_vif ? cl_vif->dev : NULL;

		if (cl_hw->chip->conf->ce_production_mode)
			cl_stats_update_rx_rate_production(cl_hw, rxhdr);
	}

	/* DATA */
	if (ieee80211_is_data(fc)) {
		cl_rx_data_check(cl_hw, skb, cl_sta, skb->len, rxhdr);
		goto out;
	}

	/* MGMT */
	if (ieee80211_is_mgmt(fc))
		cl_rx_mgmt_check(cl_hw, skb, cl_sta, rxhdr);

	/* CTL */
	if (ieee80211_is_ctl(fc))
		cl_rx_ctl_check(cl_hw, skb, cl_sta, rxhdr);

out:
	if (rx_skb_max &&
	    atomic_read(&rx_skb_cnt) >= rx_skb_max) {
		cl_hw->rx_info.pkt_drop_host_limit++;
		cl_rx_skb_drop(cl_vif, skb, w2e_hdr, 1);
		kfree_skb(skb);
		return false;
	}

	cl_rx_skb_success(cl_hw, cl_vif, skb, w2e_hdr, 1, skb->len);

	return true;
}

static void cl_rx_amsdu_to_8023(struct cl_hw *cl_hw, struct sk_buff *skb)
{
	cl_rx_strip_llc(cl_hw, skb);
	skb->protocol = eth_type_trans(skb, skb->dev);
}

static void cl_rx_amsdu_done_reorder(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
				     struct sk_buff_head *frames,
				     struct cl_tid_ampdu_rx *tid_agg_rx,
				     struct cl_rx_w2e_hdr *w2e_hdr,
				     struct hw_rxhdr *rxhdr)
{
	struct sk_buff_head reorder_buf;
	struct sk_buff *skb;

	/* Init the reorder buffer */
	skb_queue_head_init(&reorder_buf);
	if (cl_rx_reorder_ampdu(cl_hw, cl_sta, tid_agg_rx, w2e_hdr,
				rxhdr, frames, &reorder_buf)) {
		while ((skb = skb_dequeue(&reorder_buf)))
			cl_rx_finish(cl_hw, skb, &cl_sta->stainfo->sta);
	} else {
		if (!w2e_hdr)
			cl_rx_wlan_to_8023(cl_hw, cl_sta, frames);
		while ((skb = skb_dequeue(frames)))
			cl_rx_finish(cl_hw, skb, &cl_sta->stainfo->sta);
	}
}

static void cl_rx_amsdu_done(struct cl_hw *cl_hw, struct cl_amsdu_rx_state *amsdu_rx_state)
{
	struct sk_buff_head *frames = &amsdu_rx_state->frames;
	struct sk_buff *first_skb = amsdu_rx_state->first_skb;
	struct sk_buff *skb = __skb_peek(frames);
	struct ieee80211_rx_status *status = IEEE80211_SKB_RXCB(skb);
	struct cl_sta *cl_sta;
	struct cl_vif *cl_vif;
	struct hw_rxhdr *rxhdr = amsdu_rx_state->rxhdr;
	struct cl_rx_w2e_hdr *w2e_hdr = amsdu_rx_state->w2e_hdr;
	u32 packet_len = amsdu_rx_state->packet_len;
	struct ieee80211_sta *sta;
	u8 tid = amsdu_rx_state->tid;
	__le16 fc = cl_get_frame_ctrl(cl_hw, first_skb, w2e_hdr);

	/* START - cl_sta protected block */
	cl_sta_lock(cl_hw);
	cl_sta = cl_sta_get(cl_hw, amsdu_rx_state->sta_idx);

	if (!cl_sta) {
		cl_sta_unlock(cl_hw);
		cl_hw->rx_info.pkt_drop_sta_null += amsdu_rx_state->msdu_cnt;
		__skb_queue_purge(frames);
		return;
	}

	sta = &cl_sta->stainfo->sta;
	cl_vif = cl_sta->cl_vif;
	skb->dev = cl_vif->dev;

	cl_rx_data_check(cl_hw, skb, cl_sta, packet_len, rxhdr);
	cl_bsrp_data_pending_dec(cl_hw, cl_sta, skb, w2e_hdr, packet_len);
	cl_bsrp_parse_bsr(cl_hw, skb, cl_sta, w2e_hdr);
	cl_tf_handler(cl_hw, skb, cl_sta, w2e_hdr);
	cl_stats_update_rx_rate(cl_hw, cl_sta, rxhdr);
	cl_fw_dbg_trigger_based_update(cl_hw, rxhdr, fc);

	if (!rxhdr->aggregation || (rxhdr->aggregation && rxhdr->mpdu_cnt == 0))
		cl_rssi_rx_handler(cl_hw, cl_sta, rxhdr, status->signal);

	cl_sta_unlock(cl_hw);
	/* END - cl_sta protected block */

	if (rx_skb_max &&
	    (atomic_read(&rx_skb_cnt) + amsdu_rx_state->msdu_cnt) >= rx_skb_max) {
		cl_hw->rx_info.pkt_drop_host_limit += amsdu_rx_state->msdu_cnt;
		cl_rx_skb_drop(cl_vif, skb, w2e_hdr, amsdu_rx_state->msdu_cnt);
		__skb_queue_purge(frames);
		return;
	}

	cl_rx_skb_success(cl_hw, cl_vif, skb, w2e_hdr,
			  rxhdr->msdu_cnt, packet_len);
	if (cl_sta->tid_agg_rx[tid]) {
		cl_rx_amsdu_done_reorder(cl_hw, cl_sta, frames,
					 cl_sta->tid_agg_rx[tid],
					 w2e_hdr, rxhdr);
	} else {
		if (!w2e_hdr)
			cl_rx_wlan_to_8023(cl_hw, cl_sta, frames);
		while ((skb = skb_dequeue(frames)))
			cl_rx_finish(cl_hw, skb, sta);
	}
}

static void cl_rx_invalid_tailroom(struct cl_hw *cl_hw, struct hw_rxhdr *rxhdr,
				   struct sk_buff *skb, u32 len)
{
	cl_dbg_err(cl_hw, "Invalid RX header length - tailroom=%d, len=%u\n",
		   skb_tailroom(skb), len);

	if (rxhdr->amsdu_present && rxhdr->msdu_cnt > 1)
		cl_rx_amsdu_set_state_error(cl_hw, rxhdr, RX_AMSDU_ERR_INVALID_TAILROOM);

	cl_hw->rx_info.pkt_drop_tailroom_error++;
	cl_rx_skb_error(cl_hw);
	kfree_skb(skb);
}

static void cl_rx_invalid_pattern(struct cl_hw *cl_hw, struct sk_buff *skb, u32 pattern)
{
	cl_dbg_err(cl_hw, "WRONG PATTERN - 0x%x\n", pattern);
	cl_hw->rx_info.pkt_drop_wrong_pattern++;
	cl_rx_skb_error(cl_hw);
	kfree_skb(skb);
}

static int cl_rx_get_sta_idx(struct cl_hw *cl_hw, struct hw_rxhdr *rxhdr)
{
	int sta_idx = rxhdr->key_sram_index - MM_SEC_DEFAULT_KEY_COUNT;

	if (sta_idx >= 0 && sta_idx < CL_MAX_NUM_STA)
		return sta_idx;

	cl_dbg_err(cl_hw, "invalid sta_idx %d, key_sram_index=%d\n",
		   sta_idx, rxhdr->key_sram_index);

	return -1;
}

static void cl_rx_handle_first_amsdu(struct cl_hw *cl_hw, struct sk_buff *skb,
				     struct cl_amsdu_rx_state *amsdu_rx_state,
				     struct hw_rxhdr *rxhdr,
				     struct cl_rx_w2e_hdr *w2e_hdr,
				     u8 sta_idx, u8 tid,
				     u8 encrypt_len)
{
	cl_rx_amsdu_stats(cl_hw, rxhdr->msdu_cnt);

	if (rxhdr->corrupted_amsdu) {
		cl_rx_amsdu_first_corrupted(cl_hw, skb, rxhdr);
	} else {
		cl_rx_amsdu_first(cl_hw, skb, rxhdr, w2e_hdr,
				  sta_idx, tid, encrypt_len);

		/* If there are more MSDU's, hold on with the update
		 * to the upper layer until A-MSDU is complete
		 */
		if (amsdu_rx_state->msdu_remaining_cnt == 0)
			cl_rx_amsdu_done(cl_hw, amsdu_rx_state);
	}
}

static void cl_rx_handle_sub_amsdu(struct cl_hw *cl_hw, struct sk_buff *skb,
				   struct cl_amsdu_rx_state *amsdu_rx_state)
{
	/* Update the remaining MSDU counter */
	amsdu_rx_state->msdu_remaining_cnt--;

	/* Free MSDU with error */
	if (amsdu_rx_state->amsdu_error) {
		cl_rx_amsdu_sub_error(cl_hw, skb);
		return;
	}

	/* Add the sub-MSDU to the existing ones */
	if (!cl_rx_amsdu_sub(cl_hw, skb))
		return;

	/* This is the last MSDU, A-MSDU is complete, push to upper layer */
	if (amsdu_rx_state->msdu_remaining_cnt == 0)
		cl_rx_amsdu_done(cl_hw, amsdu_rx_state);
}

static void cl_rx_handle_ps(struct cl_hw *cl_hw, struct cl_sta *cl_sta, __le16 fc)
{
	struct ieee80211_sta *sta = &cl_sta->stainfo->sta;
	bool is_ps;

	if (ieee80211_is_pspoll(fc) ||
	    ieee80211_has_morefrags(fc) ||
	    !(ieee80211_is_mgmt(fc) ||
	      ieee80211_is_data(fc)))
		return;

	is_ps = ieee80211_has_pm(fc);

	cl_sta_ps_notify(cl_hw, cl_sta, is_ps);
	ieee80211_sta_ps_transition(sta, is_ps);
}

static void cl_rx_handle_skb(struct cl_hw *cl_hw, struct sk_buff *skb)
{
	u8 encrypt_len = 0;
	u8 tid = 0;
	u32 mpdu_offset = 0;
	u16 mpdu_len = 0;
	int sta_idx = -1;
	bool skb_done = false;
	struct cl_sta *cl_sta = NULL;
	struct ieee80211_sta *sta = NULL;
	struct hw_rxhdr *rxhdr = NULL;
	struct cl_rx_w2e_hdr *w2e_hdr = NULL;
	u8 w2e_hdr_size = sizeof(struct cl_rx_w2e_hdr);
	struct cl_tid_ampdu_rx *tid_agg_rx = NULL;
	struct cl_amsdu_rx_state *amsdu_rx_state = &cl_hw->amsdu_rx_state;
	__le16 fc = 0;
	bool padding = false;

	if (amsdu_rx_state->msdu_remaining_cnt > 0) {
		cl_rx_handle_sub_amsdu(cl_hw, skb, amsdu_rx_state);
		return;
	}

	rxhdr = (struct hw_rxhdr *)skb->data;
	mpdu_offset = sizeof(struct hw_rxhdr);
	padding = rxhdr->w2e_done ? rxhdr->w2e_padding : rxhdr->rx_padding_done;

	if (padding)
		mpdu_offset += CL_PADDING_IN_BYTES;

	/*
	 * Sanity check - the embedded layer is responsible to validate the pattern correctness.
	 * If pattern is invalid then it is likely that the embedded layer did some thing wrong.
	 */
	if (le32_to_cpu(rxhdr->pattern) != IPC_RX_DMA_OVER_PATTERN) {
		cl_rx_invalid_pattern(cl_hw, skb, le32_to_cpu(rxhdr->pattern));
		return;
	}

	if (rxhdr->w2e_done) {
		w2e_hdr = (struct cl_rx_w2e_hdr *)(skb->data + mpdu_offset);
		if (ieee80211_has_order(w2e_hdr->frame_ctrl)) {
			w2e_hdr_size += IEEE80211_HT_CTL_LEN;
			if (cl_key_has_pn_tsc(cl_hw, rxhdr))
				w2e_hdr_size += CL_CCMP_GCMP_PN_SIZE;
		} else if (cl_key_has_pn_tsc(cl_hw, rxhdr)) {
			w2e_hdr_size += CL_CCMP_GCMP_PN_SIZE;
		}
		mpdu_offset += w2e_hdr_size;
	} else {
		mpdu_len = rxhdr->len;
	}

	skb_reserve(skb, mpdu_offset);

	fc = cl_get_frame_ctrl(cl_hw, skb, w2e_hdr);

	if (cl_rx_check_err(cl_hw, skb, rxhdr))
		return;

	/* Convert gi from firmware format to driver format */
	rxhdr->gi_type = convert_gi_format_fw_to_wrs(rxhdr->format_mod, rxhdr->gi_type);

	if (cl_hw->rssi_simulate)
		cl_rssi_simulate(cl_hw, rxhdr);

	if (rxhdr->key_sram_v)
		sta_idx = cl_rx_get_sta_idx(cl_hw, rxhdr);

	cl_sta_lock(cl_hw);

	if (sta_idx != -1) {
		cl_sta = cl_sta_get(cl_hw, sta_idx);

		if (cl_sta) {
			sta = &cl_sta->stainfo->sta;
			cl_rssi_raw_rx_handler(cl_hw, cl_sta, rxhdr);

			if (cl_hw->conf->ci_offload_reorder_mode == RX_REORDER_BY_DRIVER) {
				if (ieee80211_is_data_qos(fc)) {
					tid = cl_get_tid(cl_hw, skb, w2e_hdr);
					tid_agg_rx = cl_sta->tid_agg_rx[tid];
				}
			}

			if (cl_hw->conf->ci_offload_reorder_mode != RX_REORDER_BY_MAC80211)
				cl_rx_handle_ps(cl_hw, cl_sta, fc);
		}
	}

	if (unlikely(cl_rx_fill_status(cl_hw, cl_sta, skb, rxhdr,
				       &encrypt_len, fc, tid_agg_rx))) {
		cl_sta_unlock(cl_hw);
		cl_rx_skb_error(cl_hw);
		kfree_skb(skb);
		return;
	}

	/* Is A-MSDU frame? */
	if (rxhdr->amsdu_present) {
		if (cl_sta) {
			skb->dev = cl_sta->cl_vif->dev;
			cl_rx_handle_first_amsdu(cl_hw, skb, amsdu_rx_state,
						 rxhdr, w2e_hdr, sta_idx, tid,
						 encrypt_len);
		} else {
			kfree_skb(skb);
		}
		cl_sta_unlock(cl_hw);
		return;
	}

	if (w2e_hdr) {
		mpdu_len = le16_to_cpu(*(__le16 *)skb->data);
		skb_reserve(skb, 2);
	}

	if (skb_tailroom(skb) >= mpdu_len) {
		/* Push the WLAN HDR + MPDU payload to the skb data */
		skb_put(skb, mpdu_len);
		cl_hw->rx_info.non_amsdu++;
	} else {
		cl_sta_unlock(cl_hw);
		cl_rx_invalid_tailroom(cl_hw, rxhdr, skb, mpdu_len);
		return;
	}

	skb_done = cl_rx_skb_done(cl_hw, skb, cl_sta, rxhdr, fc, w2e_hdr);

	cl_sta_unlock(cl_hw);

	if (!skb_done)
		return;

	if (w2e_hdr) {
		u16 ethertype = (skb->data[12] << 8) | skb->data[13];

		/* If no strip was done (length instead of ET) - strip */
		if (ethertype < ETH_P_IP)
			cl_rx_strip_llc(cl_hw, skb);
		skb->protocol = eth_type_trans(skb, skb->dev);
	}

	if (tid_agg_rx) {
		struct sk_buff_head reorder_buf;
		struct sk_buff_head skb_list;

		/* Init the reorder buffer */
		skb_queue_head_init(&reorder_buf);
		skb_queue_head_init(&skb_list);
		skb_queue_tail(&skb_list, skb);
		if (cl_rx_reorder_ampdu(cl_hw, cl_sta, tid_agg_rx, w2e_hdr,
					rxhdr, &skb_list, &reorder_buf)) {
			while ((skb = skb_dequeue(&reorder_buf)))
				cl_rx_finish(cl_hw, skb, sta);
		} else {
			skb_unlink(skb, &skb_list);
			if (w2e_hdr)
				cl_rx_finish(cl_hw, skb, sta);
			else
				ieee80211_rx_napi(cl_hw->hw, sta, skb, NULL);
		}
	} else {
		if (cl_sta && cl_key_validate_pn_tsc(cl_hw, skb, cl_sta,
					   tid, rxhdr)) {
			if (rxhdr->amsdu_present && rxhdr->msdu_cnt > 1)
				cl_rx_amsdu_set_state_error(cl_hw, rxhdr,
							    RX_AMSDU_ERR_INVALID_PN_TSC);
			kfree_skb(skb);
			return;
		}

		if (w2e_hdr)
			cl_rx_finish(cl_hw, skb, sta);
		else
			ieee80211_rx_napi(cl_hw->hw, sta, skb, NULL);
	}
}

static void cl_rx_tasklet(unsigned long data)
{
	struct cl_hw *cl_hw = (struct cl_hw *)data;
	struct sk_buff *skb = NULL;
	u16 pkt_cnt = 0;

	if (cl_recovery_in_progress(cl_hw))
		return;

#ifdef TRACE_SUPPORT
	trace_cl_trace_rx_tasklet_start(cl_hw->idx);
#endif

	while ((skb = skb_dequeue(&cl_hw->rx_skb_queue))) {
		cl_rx_handle_skb(cl_hw, skb);

		if (++pkt_cnt > cl_hw->conf->ce_rx_pkts_budget) {
			if (cl_hw->chip->conf->ci_rx_resched_tasklet)
				tasklet_schedule(&cl_hw->rx_resched_tasklet);
			else
				tasklet_schedule(&cl_hw->rx_tasklet);

			cl_hw->rx_info.exceed_pkt_budget++;
			return;
		}
	}

#ifdef TRACE_SUPPORT
	trace_cl_trace_rx_tasklet_end(cl_hw->idx, pkt_cnt);
#endif
}

static void cl_rx_resched_tasklet(unsigned long data)
{
	struct cl_hw *cl_hw = (struct cl_hw *)data;

	tasklet_schedule(&cl_hw->rx_tasklet);
}

void cl_rx_init(struct cl_hw *cl_hw)
{
	/* Set rx_skb_max to be the maximum of ci_rx_skb_max configured for each chip */
	rx_skb_max = max(cl_hw->chip->conf->ci_rx_skb_max, rx_skb_max);

	skb_queue_head_init(&cl_hw->rx_skb_queue);
	__skb_queue_head_init(&cl_hw->amsdu_rx_state.frames);

	tasklet_init(&cl_hw->rx_tasklet, cl_rx_tasklet, (unsigned long)cl_hw);
	tasklet_init(&cl_hw->rx_resched_tasklet, cl_rx_resched_tasklet, (unsigned long)cl_hw);

	if (IS_PCI_BUS_TYPE(cl_hw->chip))
		cl_rx_pci_init(cl_hw);
}

void cl_rx_off(struct cl_hw *cl_hw)
{
	tasklet_kill(&cl_hw->rx_tasklet);
	tasklet_kill(&cl_hw->rx_resched_tasklet);
	skb_queue_purge(&cl_hw->rx_skb_queue);

	cl_rx_amsdu_reset(cl_hw);
	if (IS_PCI_BUS_TYPE(cl_hw->chip))
		cl_rx_pci_deinit(cl_hw);
}

void cl_rx_remote_tasklet_sched(void *t)
{
	tasklet_schedule((struct tasklet_struct *)t);
}

void cl_rx_remote_cpu_info(struct cl_hw *cl_hw)
{
	u32 processor_id = smp_processor_id();

	if (processor_id < CPU_MAX_NUM)
		cl_hw->rx_info.remote_cpu[processor_id]++;
}

void cl_rx_push_queue(struct cl_hw *cl_hw, struct sk_buff *skb)
{
	skb_queue_tail(&cl_hw->rx_skb_queue, skb);
	tasklet_schedule(&cl_hw->rx_tasklet);
}

void cl_rx_skb_alloc_handler(struct sk_buff *skb)
{
	skb->destructor = cl_rx_skb_destructor;
	atomic_inc(&rx_skb_cnt);
}

void cl_rx_skb_error(struct cl_hw *cl_hw)
{
	/*
	 * When there is an error with the received packet we can't
	 * know the interface and the AC.
	 * So just use the first interface and BE.
	 */
	struct cl_vif *cl_vif = cl_vif_get_first(cl_hw);

	if (!cl_vif) {
		cl_dbg_err(cl_hw, "Couldn't find vif\n");
		return;
	}

	cl_vif->trfc_cntrs[AC_BE].rx_errors++;
}

void cl_rx_post_recovery(struct cl_hw *cl_hw)
{
	if (!skb_queue_empty(&cl_hw->rx_skb_queue))
		tasklet_schedule(&cl_hw->rx_tasklet);
}

void cl_rx_info_reset(struct cl_hw *cl_hw)
{
	pr_debug("Reset uplink stats\n");
	memset(&cl_hw->rx_info, 0, sizeof(struct cl_rx_path_info));
}

int cl_rx_info_print(struct cl_hw *cl_hw)
{
	struct cl_rx_path_info *rx_info = &cl_hw->rx_info;
	struct ieee80211_local *local = hw_to_local(cl_hw->hw);
	int i;
	bool uplink_amsdu = false;
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;

	for (i = 0; i < RX_MAX_MSDU_IN_AMSDU; i++)
		if (rx_info->amsdu_cnt[i] > 0) {
			uplink_amsdu = true;
			break;
		}

	cl_snprintf(&buf, &len, &buf_size,
		    "RX desc counters\n"
		    "-----------------------------------\n");
	cl_snprintf(&buf, &len, &buf_size,
		    "rx_desc[RXM]             = %u\n",
		    rx_info->rx_desc[CL_RX_BUF_RXM]);
	cl_snprintf(&buf, &len, &buf_size,
		    "rx_desc[FW]              = %u\n",
		    rx_info->rx_desc[CL_RX_BUF_FW]);
	cl_snprintf(&buf, &len, &buf_size,
		    "elem_alloc_fail          = %u\n",
		    rx_info->elem_alloc_fail);
	cl_snprintf(&buf, &len, &buf_size,
		    "skb_null                 = %u\n",
		    rx_info->skb_null);
	cl_snprintf(&buf, &len, &buf_size,
		    "w2e_done                 = %u\n",
		    rx_info->w2e_done);
	cl_snprintf(&buf, &len, &buf_size,
		    "\nNetwork interface\n"
		    "-----------------------------------\n");
	cl_snprintf(&buf, &len, &buf_size,
		    "netif_rx                 = %u\n",
		    rx_info->netif_rx);

	cl_snprintf(&buf, &len, &buf_size,
		    "\nDrop counters\n"
		    "-----------------------------------\n");
	cl_snprintf(&buf, &len, &buf_size,
		    "amsdu_corrupted          = %u\n",
		    rx_info->pkt_drop_amsdu_corrupted);
	cl_snprintf(&buf, &len, &buf_size,
		    "sub_amsdu_corrupted      = %u\n",
		    rx_info->pkt_drop_sub_amsdu_corrupted);
	cl_snprintf(&buf, &len, &buf_size,
		    "amsdu_len_error          = %u\n",
		    rx_info->pkt_drop_amsdu_len_error);
	cl_snprintf(&buf, &len, &buf_size,
		    "sub_amsdu_len_error      = %u\n",
		    rx_info->pkt_drop_sub_amsdu_len_error);
	cl_snprintf(&buf, &len, &buf_size,
		    "wrong_pattern            = %u\n",
		    rx_info->pkt_drop_wrong_pattern);
	cl_snprintf(&buf, &len, &buf_size,
		    "not_success              = %u\n",
		    rx_info->pkt_drop_not_success);
	cl_snprintf(&buf, &len, &buf_size,
		    "sub_amsdu_not_success    = %u\n",
		    rx_info->pkt_drop_sub_amsdu_not_success);
	cl_snprintf(&buf, &len, &buf_size,
		    "unencrypted              = %u\n",
		    rx_info->pkt_drop_unencrypted);
	cl_snprintf(&buf, &len, &buf_size,
		    "sub_amsdu_unencrypted    = %u\n",
		    rx_info->pkt_drop_sub_amsdu_unencrypted);
	cl_snprintf(&buf, &len, &buf_size,
		    "decrypt_fail             = %u\n",
		    rx_info->pkt_drop_decrypt_fail);
	cl_snprintf(&buf, &len, &buf_size,
		    "sub_amsdu_decrypt_fail   = %u\n",
		    rx_info->pkt_drop_sub_amsdu_decrypt_fail);
	cl_snprintf(&buf, &len, &buf_size,
		    "tailroom_error           = %u\n",
		    rx_info->pkt_drop_tailroom_error);
	cl_snprintf(&buf, &len, &buf_size,
		    "sub_amsdu_tailroom_error = %u\n",
		    rx_info->pkt_drop_sub_amsdu_tailroom_error);
	cl_snprintf(&buf, &len, &buf_size,
		    "sta_null                 = %u\n",
		    rx_info->pkt_drop_sta_null);
	cl_snprintf(&buf, &len, &buf_size,
		    "host_limit               = %u\n",
		    rx_info->pkt_drop_host_limit);
	cl_snprintf(&buf, &len, &buf_size,
		    "invalid_pn_tsc           = %u\n",
		    rx_info->pkt_drop_invalid_pn_tsc);
	cl_snprintf(&buf, &len, &buf_size,
		    "\nQueue length\n"
		    "-----------------------------------\n");
	cl_snprintf(&buf, &len, &buf_size,
		    "rx_skb_queue             = %u\n",
		    skb_queue_len(&cl_hw->rx_skb_queue));
	cl_snprintf(&buf, &len, &buf_size,
		    "local_skb_queue          = %u\n",
		    skb_queue_len(&local->skb_queue));

	cl_snprintf(&buf, &len, &buf_size,
		    "\nSKB count\n"
		    "-----------------------------------\n");
	cl_snprintf(&buf, &len, &buf_size,
		    "rx_skb_max               = %u\n",
		    rx_skb_max);
	cl_snprintf(&buf, &len, &buf_size,
		    "rx_skb_cnt               = %u\n",
		    atomic_read(&rx_skb_cnt));

	cl_snprintf(&buf, &len, &buf_size,
		    "\nBuffer processing\n"
		    "-----------------------------------\n");
	cl_snprintf(&buf, &len, &buf_size,
		    "IRQ                      = %u\n",
		    rx_info->buffer_process_irq);
	cl_snprintf(&buf, &len, &buf_size,
		    "Tasklet                  = %u\n",
		    rx_info->buffer_process_tasklet);

	cl_snprintf(&buf, &len, &buf_size,
		    "\nUplink Non AMSDU\n"
		    "-----------------------------------\n"
		    "NON AMSDU = %u\n", rx_info->non_amsdu);

	if (uplink_amsdu) {
		cl_snprintf(&buf, &len, &buf_size,
			    "\nUplink AMSDU\n"
			    "-----------------------------------\n");

		for (i = 0; i < RX_MAX_MSDU_IN_AMSDU; i++)
			if (rx_info->amsdu_cnt[i] > 0)
				cl_snprintf(&buf, &len, &buf_size,
					    "AMSDU[%d] = %u\n", i + 1, rx_info->amsdu_cnt[i]);
	}

	if (cl_hw->conf->ci_rx_remote_cpu_drv != -1) {
		cl_snprintf(&buf, &len, &buf_size,
			    "\nRemote CPU\n"
			    "-----------------------------------\n");

		for (i = 0; i < CPU_MAX_NUM; i++) {
			if (rx_info->remote_cpu[i] == 0)
				continue;

			cl_snprintf(&buf, &len, &buf_size, "cpu #%u: %u\n",
				    i, rx_info->remote_cpu[i]);
		}
	}

	cl_snprintf(&buf, &len, &buf_size,
		    "\nUplink schedule\n"
		    "-----------------------------------\n"
		    "exceed_pkt_budget = %u\n",
		    rx_info->exceed_pkt_budget);

	cl_snprintf(&buf, &len, &buf_size,
		    "\nUplink buckets RXM\n"
		    "-----------------------------------\n");

	for (i = 0; i < IPC_RXBUF_NUM_BUCKETS_RXM; i++) {
		if (rx_info->pkt_handle_bucket_rxm[i] == 0)
			continue;

		cl_snprintf(&buf, &len, &buf_size,
			    "Bucket [%lu -> %lu]: %u\n",
			    i * IPC_RXBUF_BUCKET_SIZE,
			    (i + 1) * IPC_RXBUF_BUCKET_SIZE - 1,
			    rx_info->pkt_handle_bucket_rxm[i]);
	}

	cl_snprintf(&buf, &len, &buf_size,
		    "\nUplink buckets FW\n"
		    "-----------------------------------\n");

	for (i = 0; i < IPC_RXBUF_NUM_BUCKETS_FW; i++) {
		if (rx_info->pkt_handle_bucket_fw[i] == 0)
			continue;

		cl_snprintf(&buf, &len, &buf_size,
			    "Bucket [%lu -> %lu]: %u\n",
			    i * IPC_RXBUF_BUCKET_SIZE,
			    (i + 1) * IPC_RXBUF_BUCKET_SIZE - 1,
			    rx_info->pkt_handle_bucket_fw[i]);
	}

	if (IS_USB_BUS_TYPE(cl_hw->chip)) {
		for (i = 0; i < MSDU_SPLIT_MAX; i++) {
			cl_snprintf(&buf, &len, &buf_size,
				    "\nMSDU split count\n"
				    "------------------------\n"
				    "msdu_split_cnt[%d] = %u\n", i,
				    rx_info->msdu_split_cnt[i]);
		}
	}

	err = cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);

	return err;
}

void cl_rx_netif(struct cl_hw *cl_hw, struct cl_vif *cl_vif, struct sk_buff *skb)
{
#ifdef TRACE_SUPPORT
	trace_cl_trace_netif_rx_start(cl_hw->idx);
#endif
	cl_hw->rx_info.netif_rx++;
	skb_reset_network_header(skb);
	netif_receive_skb(skb);
#ifdef TRACE_SUPPORT
	trace_cl_trace_netif_rx_end(cl_hw->idx);
#endif
}

void cl_rx_finish(struct cl_hw *cl_hw, struct sk_buff *skb, struct ieee80211_sta *sta)
{
	struct ethhdr *ehdr = eth_hdr(skb);
	struct cl_vif *cl_vif = NETDEV_TO_CL_VIF(skb->dev);
	bool is_repeater = test_bit(CL_DEV_REPEATER, &cl_hw->drv_flags);

	if (sta) {
		/* Monitor traffic type (TCP/UDP) and size */
		struct cl_sta *cl_sta = IEEE80211_STA_TO_CL_STA(sta);

		cl_traffic_mon_rx(cl_sta, skb);
	}

	if (cl_vif->vif->type == NL80211_IFTYPE_STATION || is_repeater) {
		if (!(ehdr->h_source[0] & 0x01)) {
			if (skb->protocol == htons(ETH_P_IP))
				cl_cma_ip_rx(cl_hw, skb);
			else if (skb->protocol == htons(ETH_P_ARP))
				cl_cma_arp_rx(cl_hw, skb);
		}

		/* EAPOL's should not be redirected */
		if (is_repeater &&
		    skb->protocol != htons(ETH_P_PAE) &&
		    !IS_REAL_PHY(cl_hw->chip)) {
			struct cl_vif *cl_vif_tmp, *tmp;

			list_for_each_entry_safe(cl_vif_tmp, tmp, &cl_hw->vif_db.head, list) {
				if (cl_vif != cl_vif_tmp) {
					skb_push(skb, ETH_HLEN);
					_cl_tx_start(cl_hw, skb, cl_vif_tmp->dev);
					return;
				}
			}
		}
	}

	/* Check if this is a multicast IGMP uplink packet */
	if (cl_hw->conf->ce_m2u_enable &&
	    is_multicast_ether_addr(ehdr->h_dest) &&
	    !is_broadcast_ether_addr(ehdr->h_dest))
		cl_m2u_uplink_multicast_snooping(cl_hw, cl_vif, skb);

	if (unlikely(skb->protocol == htons(ETH_P_PAE))) {
		struct ieee80211_rx_status *status = IEEE80211_SKB_RXCB(skb);
		bool encrypted = status->flag & RX_FLAG_DECRYPTED;

		cfg80211_rx_control_port(skb->dev, skb, !encrypted);
		dev_kfree_skb(skb);

		return;
	}

	memset(skb->cb, 0, sizeof(skb->cb));
	cl_rx_netif(cl_hw, cl_vif, skb);
}

void cl_rx_strip_llc(struct cl_hw *cl_hw, struct sk_buff *skb)
{
	struct ethhdr ehdr;
	u16 ethertype;

	memcpy(&ehdr, skb->data, ETH_HLEN);
	skb_pull(skb, ETH_HLEN + sizeof(rfc1042_header));
	ethertype = (skb->data[0] << 8) | skb->data[1];
	ehdr.h_proto = htons(ethertype);
	skb_pull(skb, 2);
	memcpy(skb_push(skb, sizeof(ehdr)), &ehdr, sizeof(ehdr));
}

void cl_rx_wlan_to_8023(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
			struct sk_buff_head *skb_list)
{
	struct sk_buff *skb = skb_peek(skb_list);
	struct sk_buff *xmit_skb = NULL;
	struct ieee80211_hdr *hdr = (struct ieee80211_hdr *)skb->data;
	u8 tid = 0;
	bool is_amsdu = false;
	int hdrlen = ieee80211_hdrlen(hdr->frame_control);
	int payload_offs = hdrlen;
	struct net_device *dev = cl_sta->cl_vif->dev;
	struct ethhdr ehdr;

	if (ieee80211_is_data_qos(hdr->frame_control)) {
		u8 *qc = ieee80211_get_qos_ctl(hdr);

		tid = *qc & IEEE80211_QOS_CTL_TID_MASK;
		if (*qc & IEEE80211_QOS_CTL_A_MSDU_PRESENT)
			is_amsdu = true;
	}

	/* GCMP header length is the same. what about WEP? */
	if (cl_sta->key_conf)
		payload_offs += IEEE80211_CCMP_HDR_LEN;

	skb->priority = (tid > 7) ? 0 : tid;
	skb->dev = dev;
	skb_pull(skb, payload_offs);

	if (is_amsdu) {
		skb_queue_walk(skb_list, skb) {
			skb->dev = dev;
			cl_rx_amsdu_to_8023(cl_hw, skb);
		}
	} else {
		memcpy(ehdr.h_dest, ieee80211_get_DA(hdr), ETH_ALEN);
		memcpy(ehdr.h_source, ieee80211_get_SA(hdr), ETH_ALEN);
		if (likely(!memcmp(skb->data, rfc1042_header,
				   sizeof(rfc1042_header))))
			skb_pull(skb, sizeof(rfc1042_header));
		memcpy(skb_push(skb, sizeof(ehdr) - 2), &ehdr, sizeof(ehdr) - 2);
		skb->protocol = eth_type_trans(skb, skb->dev);

		if (is_multicast_ether_addr(ehdr.h_dest)) {
			xmit_skb = skb_copy(skb, GFP_ATOMIC);
		} else if (!ether_addr_equal(ehdr.h_dest, ehdr.h_source) &&
				cl_sta_get_by_addr(cl_hw, ehdr.h_dest)) {
			xmit_skb = skb;
			__skb_unlink(skb, skb_list);
		}

		if (xmit_skb) {
			xmit_skb = skb_copy(skb, GFP_ATOMIC);
			xmit_skb->priority += 256;
			xmit_skb->protocol = htons(ETH_P_802_3);
			skb_reset_network_header(xmit_skb);
			skb_reset_mac_header(xmit_skb);
			dev_queue_xmit(xmit_skb);
		}
	}
}

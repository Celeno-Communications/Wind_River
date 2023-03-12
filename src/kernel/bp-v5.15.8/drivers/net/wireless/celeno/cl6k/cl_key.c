// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_key.h"
#include "cl_msg_tx.h"
#include "cl_fw_msg.h"
#include "cl_sta.h"
#include "cl_rx.h"
#include "cl_single_cfm.h"
#include "cl_agg_cfm.h"
#include "cl_tx_queue.h"
#include "cl_enhanced_tim.h"

static int cmd_set_key(struct cl_hw *cl_hw,
		       struct ieee80211_vif *vif,
		       struct ieee80211_sta *sta,
		       struct ieee80211_key_conf *key)
{
	int error = 0;
	struct mm_key_add_cfm *key_add_cfm;
	u8 cipher_suite = 0;

	/* Retrieve the cipher suite selector */
	switch (key->cipher) {
	case WLAN_CIPHER_SUITE_WEP40:
		cipher_suite = MAC_CIPHER_SUITE_WEP40;
		break;
	case WLAN_CIPHER_SUITE_WEP104:
		cipher_suite = MAC_CIPHER_SUITE_WEP104;
		break;
	case WLAN_CIPHER_SUITE_TKIP:
		cipher_suite = MAC_CIPHER_SUITE_TKIP;
		break;
	case WLAN_CIPHER_SUITE_CCMP:
		cipher_suite = MAC_CIPHER_SUITE_CCMP;
		break;
	case WLAN_CIPHER_SUITE_GCMP:
	case WLAN_CIPHER_SUITE_GCMP_256:
		cipher_suite = MAC_CIPHER_SUITE_GCMP;
		break;
	case WLAN_CIPHER_SUITE_AES_CMAC:
		return -EOPNOTSUPP;
	default:
		return -EINVAL;
	}

	error = cl_msg_tx_key_add(cl_hw, vif, sta, key, cipher_suite);
	if (error)
		return error;

	key_add_cfm = (struct mm_key_add_cfm *)(cl_hw->msg_cfm_params[MM_KEY_ADD_CFM]);

	if (key_add_cfm->status != 0) {
		cl_dbg_verbose(cl_hw, "Status Error (%u)\n", key_add_cfm->status);
		cl_msg_tx_free_cfm_params(cl_hw, MM_KEY_ADD_CFM);
		return -EIO;
	}

	/* Save the index retrieved from firmware */
	key->hw_key_idx = key_add_cfm->hw_key_idx;

	cl_msg_tx_free_cfm_params(cl_hw, MM_KEY_ADD_CFM);

	/*
	 * Now inform mac80211 about our choices regarding header fields generation:
	 * we let mac80211 take care of all generations
	 */
	key->flags |= IEEE80211_KEY_FLAG_GENERATE_IV;
	if (key->cipher == WLAN_CIPHER_SUITE_TKIP)
		key->flags |= IEEE80211_KEY_FLAG_GENERATE_MMIC;

	if (sta) {
		struct cl_sta *cl_sta = (struct cl_sta *)sta->drv_priv;

		cl_sta->key_conf = key;
	} else {
		struct cl_vif *cl_vif = (struct cl_vif *)vif->drv_priv;

		cl_vif->key_conf = key;
	}

	return error;
}

static int cmd_disable_key(struct cl_hw *cl_hw,
			   struct ieee80211_vif *vif,
			   struct ieee80211_sta *sta,
			   struct ieee80211_key_conf *key)
{
	int ret = 0;
	struct cl_sta *cl_sta = NULL;
	struct cl_tx_queue *tx_queue = &cl_hw->tx_queues->single[HIGH_PRIORITY_QUEUE];

	if (sta) {
		cl_sta = (struct cl_sta *)sta->drv_priv;

		cl_sta->key_conf = NULL;
		cl_sta->key_disable = true;

		/*
		 * Make sure there aren't any packets in firmware before deleting the key,
		 * otherwise they will be transmitted without encryption.
		 */
		cl_sta->stop_tx = true;
		cl_single_cfm_clear_tim_bit_sta(cl_hw, cl_sta->sta_idx);
		cl_agg_cfm_clear_tim_bit_sta(cl_hw, cl_sta);
		cl_txq_flush_sta(cl_hw, cl_sta);
		cl_single_cfm_poll_empty_sta(cl_hw, cl_sta->sta_idx);
		cl_agg_cfm_poll_empty_sta(cl_hw, cl_sta);

		if (!list_empty(&tx_queue->hdrs)) {
			spin_lock_bh(&cl_hw->tx_lock_single);
			cl_enhanced_tim_set_tx_single(cl_hw,
						      HIGH_PRIORITY_QUEUE,
						      tx_queue->hw_index,
						      false, tx_queue->cl_sta,
						      tx_queue->tid);
			spin_unlock_bh(&cl_hw->tx_lock_single);
		}
	} else {
		struct cl_vif *cl_vif = (struct cl_vif *)vif->drv_priv;

		cl_vif->key_conf = NULL;
	}

	ret = cl_msg_tx_key_del(cl_hw, key->hw_key_idx);

	if (cl_sta)
		cl_sta->stop_tx = false;

	return ret;
}

static int cl_key_validate_tsc(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
			       u8 *tsc_hdr, u8 tid)
{
	u32 iv32 = get_unaligned_le32(tsc_hdr + 2);
	u16 iv16 = get_unaligned_le16(tsc_hdr);

	if (iv32 < cl_sta->iv32[tid] || iv16 == cl_sta->iv16[tid] ||
	    (iv16 < cl_sta->iv16[tid] && iv32 == cl_sta->iv32[tid])) {
		cl_hw->rx_info.pkt_drop_invalid_pn_tsc++;
		if (iv32 < cl_sta->iv32[tid])
			cl_dbg_err(cl_hw, "Invalid TSC\n");

		return -1;
	}

	cl_sta->iv32[tid] = iv32;
	cl_sta->iv16[tid] = iv16;

	return 0;
}

static int cl_key_validate_pn(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
			      u8 *pn_hdr, u8 tid)
{
	int res;

	res = memcmp(pn_hdr, cl_sta->rx_pn[tid], IEEE80211_CCMP_PN_LEN);
	if (res <= 0) {
		cl_hw->rx_info.pkt_drop_invalid_pn_tsc++;
		if (res < 0)
			cl_dbg_err(cl_hw, "Invalid PN\n");

		return -1;
	}

	memcpy(cl_sta->rx_pn[tid], pn_hdr, IEEE80211_CCMP_PN_LEN);

	return 0;
}

bool cl_key_has_pn_tsc(struct cl_hw *cl_hw, struct hw_rxhdr *rxhdr)
{
	if (rxhdr->decr_status == CL_RX_HD_DECR_TKIPSUCCESS ||
	    rxhdr->decr_status == CL_RX_HD_DECR_CCMPSUCCESS)
		return true;

	return false;
}

int cl_key_validate_pn_tsc(struct cl_hw *cl_hw, struct sk_buff *skb,
			   struct cl_sta *cl_sta, u8 tid,
			   struct hw_rxhdr *rxhdr)
{
	u8 *pn_tsc = NULL;
	struct cl_rx_w2e_hdr *w2e_hdr = NULL;
	u32 mpdu_offset = sizeof(struct hw_rxhdr);
	bool padding = rxhdr->w2e_done ? rxhdr->w2e_padding :
		       rxhdr->rx_padding_done;

	if (padding)
		mpdu_offset += CL_PADDING_IN_BYTES;

	if (rxhdr->w2e_done) {
		w2e_hdr = (struct cl_rx_w2e_hdr *)((u8 *)rxhdr + mpdu_offset);
		if (ieee80211_has_order(w2e_hdr->frame_ctrl)) {
			if (cl_key_has_pn_tsc(cl_hw, rxhdr))
				pn_tsc = &w2e_hdr->optional[IEEE80211_HT_CTL_LEN];
		} else if (cl_key_has_pn_tsc(cl_hw, rxhdr)) {
			pn_tsc = w2e_hdr->optional;
		}
	}

	if (!pn_tsc)
		return 0;

	if (rxhdr->decr_status == CL_RX_HD_DECR_TKIPSUCCESS)
		return cl_key_validate_tsc(cl_hw, cl_sta, pn_tsc, tid);
	else if (rxhdr->decr_status == CL_RX_HD_DECR_CCMPSUCCESS)
		return cl_key_validate_pn(cl_hw, cl_sta, pn_tsc, tid);

	/* Should never happen */
	cl_dbg_err(cl_hw, "rxhdr->decr_status=0x%x !!!\n", rxhdr->decr_status);

	return 0;
}

int cl_key_set(struct cl_hw *cl_hw,
	       enum set_key_cmd cmd,
	       struct ieee80211_vif *vif,
	       struct ieee80211_sta *sta,
	       struct ieee80211_key_conf *key)
{
	int error = 0;

	switch (cmd) {
	case SET_KEY:
		error = cmd_set_key(cl_hw, vif, sta, key);
		break;

	case DISABLE_KEY:
		error = cmd_disable_key(cl_hw, vif, sta, key);
		break;

	default:
		error = -EINVAL;
		break;
	}

	return error;
}

struct ieee80211_key_conf *cl_key_get(struct cl_sta *cl_sta)
{
	if (cl_sta->key_conf)
		return cl_sta->key_conf;

	if (cl_sta->cl_vif->key_conf)
		return cl_sta->cl_vif->key_conf;

	return NULL;
}

bool cl_key_is_cipher_wep_or_wpa(struct ieee80211_key_conf *keyconf)
{
	u32 cipher;

	if (!keyconf)
		return false;

	cipher = keyconf->cipher;

	return ((cipher == WLAN_CIPHER_SUITE_WEP104) ||
		(cipher == WLAN_CIPHER_SUITE_WEP40) ||
		(cipher == WLAN_CIPHER_SUITE_TKIP));
}

bool cl_key_is_cipher_ccmp_gcmp(struct ieee80211_key_conf *keyconf)
{
	u32 cipher;

	if (!keyconf)
		return false;

	cipher = keyconf->cipher;

	return ((cipher == WLAN_CIPHER_SUITE_CCMP) ||
		(cipher == WLAN_CIPHER_SUITE_GCMP) ||
		(cipher == WLAN_CIPHER_SUITE_GCMP_256));
}

void cl_key_ccmp_gcmp_pn_to_hdr(u8 *hdr, u64 pn, int key_id)
{
	hdr[0] = pn;
	hdr[1] = pn >> 8;
	hdr[2] = 0;
	hdr[3] = 0x20 | (key_id << 6);
	hdr[4] = pn >> 16;
	hdr[5] = pn >> 24;
	hdr[6] = pn >> 32;
	hdr[7] = pn >> 40;
}

u8 cl_key_get_cipher_len(struct sk_buff *skb)
{
	struct ieee80211_tx_info *tx_info = IEEE80211_SKB_CB(skb);
	struct ieee80211_key_conf *key_conf = tx_info->control.hw_key;

	if (key_conf) {
		switch (key_conf->cipher) {
		case WLAN_CIPHER_SUITE_WEP40:
		case WLAN_CIPHER_SUITE_WEP104:
			return IEEE80211_WEP_IV_LEN;
		case WLAN_CIPHER_SUITE_TKIP:
			return  IEEE80211_TKIP_IV_LEN;
		case WLAN_CIPHER_SUITE_CCMP:
			return  IEEE80211_CCMP_HDR_LEN;
		case WLAN_CIPHER_SUITE_CCMP_256:
			return  IEEE80211_CCMP_256_HDR_LEN;
		case WLAN_CIPHER_SUITE_GCMP:
		case WLAN_CIPHER_SUITE_GCMP_256:
			return  IEEE80211_GCMP_HDR_LEN;
		}
	}

	return 0;
}

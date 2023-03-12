// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_rx_amsdu.h"

struct msduhdr {
	u8 dest[ETH_ALEN];
	u8 source[ETH_ALEN];
	__be16 len;
} __packed;

static void cl_rx_amsdu_set_state(struct cl_hw *cl_hw, struct sk_buff *skb,
				  struct hw_rxhdr *rxhdr,
				  struct cl_rx_w2e_hdr *w2e_hdr,
				  u8 sta_idx,
				  u8 tid, u32 packet_len, u8 encrypt_len)
{
	struct cl_amsdu_rx_state *amsdu_rx_state = &cl_hw->amsdu_rx_state;

	amsdu_rx_state->msdu_cnt = rxhdr->msdu_cnt;
	amsdu_rx_state->msdu_remaining_cnt = rxhdr->msdu_cnt - 1;
	amsdu_rx_state->msdu_dma_align = rxhdr->msdu_dma_align;
	amsdu_rx_state->amsdu_error = 0;
	amsdu_rx_state->encrypt_len = encrypt_len;
	amsdu_rx_state->packet_len = packet_len;
	amsdu_rx_state->rxhdr = rxhdr;
	amsdu_rx_state->w2e_hdr = w2e_hdr;
	amsdu_rx_state->first_skb = skb;
	amsdu_rx_state->sta_idx = sta_idx;
	amsdu_rx_state->tid = tid;

	__skb_queue_head(&cl_hw->amsdu_rx_state.frames, skb);
}

static void cl_rx_amsdu_first_length_error(struct cl_hw *cl_hw, struct sk_buff *skb,
					   struct hw_rxhdr *rxhdr, u32 len)
{
	cl_dbg_err(cl_hw, "RX-AMSDU length error (1/%u) - tailroom=%d, len=%u\n",
		   rxhdr->msdu_cnt, skb_tailroom(skb), len);

	cl_rx_amsdu_set_state_error(cl_hw, rxhdr, RX_AMSDU_ERR_LENGTH);

	cl_hw->rx_info.pkt_drop_amsdu_len_error++;
	cl_rx_skb_error(cl_hw);
	kfree_skb(skb);
}

static void cl_rx_amsdu_sub_length_error(struct cl_hw *cl_hw, struct sk_buff *skb, u32 len)
{
	struct cl_amsdu_rx_state *amsdu_rx_state = &cl_hw->amsdu_rx_state;
	struct sk_buff *skb_tail;
	u8 sub_cnt = amsdu_rx_state->msdu_cnt - amsdu_rx_state->msdu_remaining_cnt;

	cl_dbg_err(cl_hw, "RX-AMSDU length error (%u/%u) - tailroom=%d, len=%u\n",
		   sub_cnt, amsdu_rx_state->msdu_cnt, skb_tailroom(skb), len);

	/* All remaining skbs in the AMSDU will be treated as errors */
	amsdu_rx_state->amsdu_error = RX_AMSDU_ERR_LENGTH;
	skb_tail = skb_peek_tail(&amsdu_rx_state->frames);
	cl_hw->rx_info.pkt_drop_sub_amsdu_len_error++;
	cl_rx_skb_error(cl_hw);
	kfree_skb(skb);
}

void cl_rx_amsdu_first(struct cl_hw *cl_hw, struct sk_buff *skb,
		       struct hw_rxhdr *rxhdr, struct cl_rx_w2e_hdr *w2e_hdr,
		       u8 sta_idx, u8 tid, u8 encrypt_len)
{
	u32 packet_len;

	if (w2e_hdr) {
		packet_len = le16_to_cpu(*(__le16 *)skb->data);
		skb->data += 2;
	} else {
		/*
		 * First MSDU recived frame:
		 * ------------------------------------------
		 * || WLAN_HDR || MSDU HDR || MSDU PAYLOAD ||
		 * ------------------------------------------
		 */
		struct ieee80211_hdr *hdr = (struct ieee80211_hdr *)(skb->data);
		u32 hdr_len = ieee80211_hdrlen(hdr->frame_control);
		struct msduhdr *msdu_hdr = (struct msduhdr *)(skb->data +
						hdr_len + encrypt_len);

		packet_len = hdr_len + encrypt_len +
			     sizeof(struct msduhdr) + ntohs(msdu_hdr->len);
	}

	if (skb_tailroom(skb) < packet_len) {
		cl_rx_amsdu_first_length_error(cl_hw, skb, rxhdr, packet_len);
		return;
	}

	/* Put the WLAN header + MSDU header + payload in the skb data */
	skb_put(skb, packet_len);

	cl_rx_amsdu_set_state(cl_hw, skb, rxhdr, w2e_hdr, sta_idx,
			      tid, packet_len, encrypt_len);

	if (w2e_hdr) {
		u16 ethertype = (skb->data[12] << 8) | skb->data[13];

		/* No strip was done (length instead of ET) - strip */
		if (ethertype < ETH_P_IP)
			cl_rx_strip_llc(cl_hw, skb);
		skb->protocol = eth_type_trans(skb, skb->dev);
	}
}

bool cl_rx_amsdu_sub(struct cl_hw *cl_hw, struct sk_buff *skb)
{
	/*
	 * ----------------------------------------------------------
	 * | DMA padding 4 byte alignment | MSDU HDR | MSDU PAYLOAD |
	 *  ---------------------------------------------------------
	 */
	struct cl_amsdu_rx_state *amsdu_rx_state = &cl_hw->amsdu_rx_state;
	struct sk_buff *first_skb = amsdu_rx_state->first_skb;
	struct cl_rx_w2e_hdr *w2e_hdr = amsdu_rx_state->w2e_hdr;
	u32 packet_len;

	/*
	 * Push the dma alignment to the reserved area, so that skb->data will
	 * point to the MSDU header
	 */
	skb_reserve(skb, amsdu_rx_state->msdu_dma_align);

	if (w2e_hdr) {
		packet_len = le16_to_cpu(*(__le16 *)skb->data);
		skb->data += 2;
	} else {
		struct msduhdr *msdu_hdr = (struct msduhdr *)(skb->data);

		packet_len = sizeof(struct msduhdr) + ntohs(msdu_hdr->len);
	}

	if (skb_tailroom(skb) < packet_len) {
		cl_rx_amsdu_sub_length_error(cl_hw, skb, packet_len);
		return false;
	}

	skb_put(skb, packet_len);

	if (w2e_hdr) {
		u16 ethertype = (skb->data[12] << 8) | skb->data[13];

		/* No strip was done (length instead of ET) - strip */
		if (ethertype < ETH_P_IP)
			cl_rx_strip_llc(cl_hw, skb);
		skb->protocol = eth_type_trans(skb, first_skb->dev);
	}

	amsdu_rx_state->packet_len += packet_len;

	__skb_queue_tail(&amsdu_rx_state->frames, skb);

	return true;
}

void cl_rx_amsdu_first_corrupted(struct cl_hw *cl_hw, struct sk_buff *skb,
				 struct hw_rxhdr *rxhdr)
{
	cl_dbg_verbose(cl_hw, "Corrupted RX-AMSDU (1/%u)\n", rxhdr->msdu_cnt);

	cl_rx_amsdu_set_state_error(cl_hw, rxhdr, RX_AMSDU_ERR_CORRUPTED);

	cl_hw->rx_info.pkt_drop_amsdu_corrupted++;
	cl_rx_skb_error(cl_hw);
	kfree_skb(skb);
}

void cl_rx_amsdu_sub_error(struct cl_hw *cl_hw, struct sk_buff *skb)
{
	struct cl_amsdu_rx_state *amsdu_rx_state = &cl_hw->amsdu_rx_state;
	u8 sub_cnt = amsdu_rx_state->msdu_cnt - amsdu_rx_state->msdu_remaining_cnt;

	if (amsdu_rx_state->amsdu_error & RX_AMSDU_ERR_CORRUPTED) {
		cl_hw->rx_info.pkt_drop_sub_amsdu_corrupted++;

		cl_dbg_verbose(cl_hw, "Corrupted RX-AMSDU (%u/%u)\n",
			       sub_cnt, amsdu_rx_state->msdu_cnt);
	} else if (amsdu_rx_state->amsdu_error & RX_AMSDU_ERR_LENGTH) {
		cl_hw->rx_info.pkt_drop_sub_amsdu_len_error++;

		cl_dbg_verbose(cl_hw, "RX-AMSDU length error (%u/%u)\n",
			       sub_cnt, amsdu_rx_state->msdu_cnt);
	} else if (amsdu_rx_state->amsdu_error & RX_AMSDU_ERR_NOT_SUCCESS) {
		cl_hw->rx_info.pkt_drop_sub_amsdu_not_success++;

		cl_dbg_verbose(cl_hw, "RX-AMSDU not success (%u/%u)\n",
			       sub_cnt, amsdu_rx_state->msdu_cnt);
	} else if (amsdu_rx_state->amsdu_error & RX_AMSDU_ERR_UNENCRYPTED) {
		cl_hw->rx_info.pkt_drop_sub_amsdu_unencrypted++;

		cl_dbg_verbose(cl_hw, "Protected frame unencrypted (%u/%u)\n",
			       sub_cnt, amsdu_rx_state->msdu_cnt);
	} else if (amsdu_rx_state->amsdu_error & RX_AMSDU_ERR_DECRYPT_FAIL) {
		cl_hw->rx_info.pkt_drop_sub_amsdu_decrypt_fail++;

		cl_dbg_verbose(cl_hw, "Decryption failed (%u/%u)\n",
			       sub_cnt, amsdu_rx_state->msdu_cnt);
	} else if (amsdu_rx_state->amsdu_error & RX_AMSDU_ERR_INVALID_TAILROOM) {
		cl_hw->rx_info.pkt_drop_sub_amsdu_tailroom_error++;

		cl_dbg_verbose(cl_hw, "Invalid tailroom (%u/%u)\n",
			       sub_cnt, amsdu_rx_state->msdu_cnt);
	} else if (amsdu_rx_state->amsdu_error & RX_AMSDU_ERR_INVALID_PN_TSC) {
		cl_hw->rx_info.pkt_drop_invalid_pn_tsc++;
	}

	cl_rx_skb_error(cl_hw);
	kfree_skb(skb);
}

void cl_rx_amsdu_set_state_error(struct cl_hw *cl_hw,
				 struct hw_rxhdr *rxhdr,
				 enum rx_amsdu_error err)
{
	struct cl_amsdu_rx_state *amsdu_rx_state = &cl_hw->amsdu_rx_state;

	amsdu_rx_state->msdu_cnt = rxhdr->msdu_cnt;
	amsdu_rx_state->msdu_remaining_cnt = rxhdr->msdu_cnt - 1;
	amsdu_rx_state->amsdu_error = err;
}

void cl_rx_amsdu_reset(struct cl_hw *cl_hw)
{
	/* Free pending frames */
	__skb_queue_purge(&cl_hw->amsdu_rx_state.frames);

	/* Reset RX A-MSDU state */
	memset(&cl_hw->amsdu_rx_state, 0, sizeof(struct cl_amsdu_rx_state));

	__skb_queue_head_init(&cl_hw->amsdu_rx_state.frames);
}

void cl_rx_amsdu_stats(struct cl_hw *cl_hw, u8 msdu_cnt)
{
	/*
	 * Update A-MSDU statistics
	 * msdu_cnt 1 - 16 is mapped to 0 - 15.
	 */
	if (msdu_cnt <= RX_MAX_MSDU_IN_AMSDU)
		cl_hw->rx_info.amsdu_cnt[msdu_cnt - 1]++;
	else
		cl_dbg_err(cl_hw, "Invalid msdu_cnt [%u]\n", msdu_cnt);
}

/* Only ieee80211_hw_set() is defined in mac80211.h */
static inline void _ieee80211_hw_clear(struct ieee80211_hw *hw,
				       enum ieee80211_hw_flags flg)
{
	return __clear_bit(flg, hw->flags);
}

#define ieee80211_hw_clear(hw, flg) _ieee80211_hw_clear(hw, IEEE80211_HW_##flg)

void cl_rx_amsdu_hw_en(struct ieee80211_hw *hw, bool rxamsdu_en)
{
	if (rxamsdu_en)
		ieee80211_hw_set(hw, SUPPORTS_AMSDU_IN_AMPDU);
	else
		ieee80211_hw_clear(hw, SUPPORTS_AMSDU_IN_AMPDU);
}

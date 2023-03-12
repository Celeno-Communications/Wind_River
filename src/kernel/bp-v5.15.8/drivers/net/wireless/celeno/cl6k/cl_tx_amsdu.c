// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_tx_amsdu.h"
#include "cl_tx.h"
#include "cl_math.h"
#include "chip.h"
#include "cl_usb.h"
#include "cl_tx_queue.h"
#include "cl_bsr.h"
#include "cl_band.h"
#include "def.h"
#include "cl_key.h"
#include "cl_ip.h"
#include "cl_wrs_api.h"

#define CL_AMSDU_HDR_LEN 14

static bool cl_tx_amsdu_is_sw(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
			      struct sk_buff *skb, u16 pkt_len)
{
	bool syn_rst_push = false;
	bool tcp_ack = false;

	if (cl_hw->conf->ci_tx_sw_amsdu_max_packets <= 1)
		return false;

	tcp_ack = is_tcp_ack(skb, &syn_rst_push);

	if (!tcp_ack || syn_rst_push)
		return false;

	if ((cl_wrs_api_get_tx_sta_data_rate(cl_sta) * cl_sta->ampdu_min_spacing) <=
	    (pkt_len << 3))
		return false;

	return true;
}

static int cl_tx_amsdu_anchor_set(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
				  struct sk_buff *skb, u8 tid)
{
	/*
	 * Packet length calculation in HW -
	 * Add 802.11 header (maximum possible size) instead if 802.3
	 * Add AMSDU header
	 * Add RFC1042 header (according to ether-type)
	 * Add IV and ICV (if there is encryption)
	 */
	struct cl_amsdu_ctrl *amsdu_anchor = &cl_sta->amsdu_anchor[tid];
	struct ieee80211_tx_info *tx_info = IEEE80211_SKB_CB(skb);
	struct ieee80211_key_conf *key_conf = tx_info->control.hw_key;
	u16 ethertype = (skb->data[12] << 8) | skb->data[13];
	u16 pkt_len = skb->len + CL_WLAN_HEADER_MAX_SIZE;

	if (key_conf)
		pkt_len += (key_conf->iv_len + key_conf->icv_len);

	if (ethertype >= ETH_P_802_3_MIN)
		pkt_len += sizeof(rfc1042_header);

	amsdu_anchor->rem_len = amsdu_anchor->max_len - pkt_len;
	amsdu_anchor->packet_cnt = 1;
	amsdu_anchor->is_sw_amsdu = cl_tx_amsdu_is_sw(cl_hw, cl_sta, skb, pkt_len);

	return CL_AMSDU_ANCHOR_SET;
}

static void cl_tx_amsdu_anchor_umacdesc_update(struct txdesc *txdesc, u8 idx,
					       u16 len, u32 addr,
					       bool is_padding)
{
	struct lmacapi *umacdesc = &txdesc->umacdesc;

	umacdesc->agg_info.packet_len[idx] = cpu_to_le16(len);
	umacdesc->agg_info.packet_addr[idx] = cpu_to_le32(addr);
	txdesc->host_info.packet_cnt++;

	/* Update padding bit of current msdu sub-frame */
	if (is_padding)
		txdesc->host_info.host_padding |= BIT(idx);
}

static struct cl_amsdu_txhdr *cl_tx_amsdu_txhdr_alloc(struct cl_hw *cl_hw)
{
	if (cl_hw->conf->ci_amsdu_txhdr_pool) {
		struct cl_amsdu_txhdr *amsdu_txhdr =
			list_first_entry_or_null(&cl_hw->head_amsdu_txhdr_pool,
						 struct cl_amsdu_txhdr,
						 list_pool);

		if (amsdu_txhdr) {
			list_del(&amsdu_txhdr->list_pool);
			return amsdu_txhdr;
		}

		return NULL;
	} else {
		return kmem_cache_alloc(cl_hw->amsdu_txhdr_cache, GFP_ATOMIC);
	}
}

static void _cl_tx_amsdu_transfer_single(struct cl_hw *cl_hw,
					 struct sk_buff *skb,
					 struct cl_sta *cl_sta,
					 u8 tid)
{
	struct ieee80211_tx_info *tx_info;

	tx_info = IEEE80211_SKB_CB(skb);
	tx_info->flags &= ~IEEE80211_TX_CTL_AMPDU;
	tx_info->control.flags &= ~IEEE80211_TX_CTRL_AMSDU;

	if (cl_tx_8023_to_wlan(cl_hw, skb, cl_sta, tid) == 0) {
		cl_hw->tx_packet_cntr.transfer.agg_to_single++;
		cl_tx_single(cl_hw, cl_sta, skb, false, false);
	}
}

static void cl_tx_amsdu_set_sw_sub_amsdu_hdr(struct sk_buff *skb)
{
	u16 ethertype = (skb->data[12] << 8) | skb->data[13];
	int rfc1042_len = 0;
	void *data;
	struct ethhdr *amsdu_hdr;

	if (ethertype >= ETH_P_802_3_MIN)
		rfc1042_len = sizeof(rfc1042_header);

	data = skb_push(skb, rfc1042_len + 2);
	memmove(data, data + rfc1042_len + 2, 2 * ETH_ALEN);

	amsdu_hdr = (struct ethhdr *)data;
	amsdu_hdr->h_proto = cpu_to_be16(skb->len - ETH_HLEN);

	memcpy(data + ETH_HLEN, rfc1042_header, rfc1042_len);
}

static int cl_tx_amsdu_add_sw_amsdu_hdr(struct cl_hw *cl_hw,
					struct cl_amsdu_ctrl *amsdu_anchor)
{
	struct cl_sw_txhdr *anchor_sw_txhdr = amsdu_anchor->sw_txhdr;
	struct sk_buff *skb = anchor_sw_txhdr->skb;
	struct cl_sta *cl_sta = anchor_sw_txhdr->cl_sta;
	struct ieee80211_hdr hdr;
	u16 ethertype = (skb->data[12] << 8) | skb->data[13];
	u16 hdrlen = cl_tx_prepare_wlan_hdr(cl_hw, cl_sta, skb, &hdr);
	int rfc1042_len = 0;
	int head_need = 0;
	u8 enc_len = cl_key_get_cipher_len(skb);
	u16 qos_ctrl = anchor_sw_txhdr->tid | IEEE80211_QOS_CTL_A_MSDU_PRESENT;

	if (!hdrlen)
		return -EINVAL;

	if (ethertype >= ETH_P_802_3_MIN)
		rfc1042_len = sizeof(rfc1042_header);

	amsdu_anchor->hdrlen = hdrlen;
	head_need = hdrlen + enc_len + rfc1042_len - skb_headroom(skb);
	if (head_need > 0) {
		head_need = ((head_need + 3) & ~3);
		if (pskb_expand_head(skb, head_need, 0, GFP_ATOMIC))
			return -ENOMEM;
	}

	cl_tx_amsdu_set_sw_sub_amsdu_hdr(skb);

	skb_push(skb, hdrlen + enc_len);
	memcpy(skb->data, &hdr, hdrlen - 2);
	memcpy(skb->data + hdrlen - 2, &qos_ctrl, 2);
	skb_reset_mac_header(skb);
	anchor_sw_txhdr->txdesc.e2w_natt_param.hdr_conv_enable = false;
	anchor_sw_txhdr->hdr80211 = (struct ieee80211_hdr *)skb->data;

	return 0;
}

static int cl_tx_amsdu_sw_aggregate(struct cl_hw *cl_hw,
				    struct cl_amsdu_ctrl *amsdu_anchor,
				    struct sk_buff *skb)
{
	struct cl_sw_txhdr *anchor_sw_txhdr = amsdu_anchor->sw_txhdr;
	struct sk_buff *anchor_skb = anchor_sw_txhdr->skb;
	struct ieee80211_tx_info *tx_info = IEEE80211_SKB_CB(anchor_skb);
	struct ieee80211_key_conf *key_conf = tx_info->control.hw_key;
	u16 total_frame_len = 0;
	u16 anchor_skb_len = anchor_skb->len;
	struct cl_tx_queue *tx_queue = anchor_sw_txhdr->tx_queue;
	int head_pad = 0;
	int sub_pad = 0;
	bool syn_rst_push = false;
	bool tcp_ack = is_tcp_ack(skb, &syn_rst_push);

	/* Worst case: rfc1042(6) + ET(2) + pad(2) = 10 */
	if (!tcp_ack ||
	    (skb_tailroom(anchor_skb) < (skb->len + 10))) {
		if (tx_queue->num_packets == 1)
			cl_txq_sched(cl_hw, tx_queue);
		cl_tx_amsdu_anchor_init(amsdu_anchor);
		return cl_tx_amsdu_anchor_set(cl_hw, anchor_sw_txhdr->cl_sta,
					      skb, anchor_sw_txhdr->tid);
	}

	if (amsdu_anchor->packet_cnt == 1 &&
	    cl_tx_amsdu_add_sw_amsdu_hdr(cl_hw, amsdu_anchor))
		return CL_AMSDU_FAILED;

	cl_tx_amsdu_set_sw_sub_amsdu_hdr(skb);
	sub_pad = CL_SKB_DATA_ALIGN_PADS(anchor_skb->len -
					 amsdu_anchor->hdrlen);
	memset(skb_push(skb, sub_pad), 0, sub_pad);
	memcpy(skb_put(anchor_skb, skb->len), skb->data, skb->len);

	kfree_skb(skb);
	amsdu_anchor->packet_cnt++;
	anchor_sw_txhdr->sw_amsdu_packet_cnt++;
	head_pad = CL_SKB_DATA_ALIGN_PADS(anchor_skb->data);

	if (head_pad) {
		anchor_sw_txhdr->map_len = anchor_skb->len + head_pad;
		anchor_sw_txhdr->txdesc.host_info.host_padding |= BIT(0);
	} else {
		anchor_sw_txhdr->map_len = anchor_skb->len;
		anchor_sw_txhdr->txdesc.host_info.host_padding = 0;
	}

	total_frame_len = anchor_skb->len;
	if (key_conf)
		total_frame_len += key_conf->icv_len;

	anchor_sw_txhdr->txdesc.umacdesc.agg_info.packet_len[0] = cpu_to_le16(total_frame_len);

	/* Update BSR data counters */
	cl_bsr_counters_inc(cl_hw, anchor_sw_txhdr, anchor_skb->len - anchor_skb_len);

	if (amsdu_anchor->packet_cnt == cl_hw->conf->ci_tx_sw_amsdu_max_packets ||
	    syn_rst_push) {
		if (tx_queue->num_packets == 1)
			cl_txq_sched(cl_hw, tx_queue);
		cl_tx_amsdu_anchor_init(amsdu_anchor);
	}

	return CL_AMSDU_SUB_FRAME_SET;
}

void cl_tx_amsdu_anchor_init(struct cl_amsdu_ctrl *amsdu_anchor)
{
	amsdu_anchor->rem_len = amsdu_anchor->max_len;
	amsdu_anchor->sw_txhdr = NULL;
	amsdu_anchor->packet_cnt = 0;
	amsdu_anchor->is_sw_amsdu = false;
}

void cl_tx_amsdu_anchor_reset(struct cl_amsdu_ctrl *amsdu_anchor)
{
	amsdu_anchor->sw_txhdr = NULL;
	amsdu_anchor->rem_len = 0;
	amsdu_anchor->max_len = 0;
	amsdu_anchor->packet_cnt = 0;
	amsdu_anchor->is_sw_amsdu = false;
}

void cl_tx_amsdu_set_max_len(struct cl_hw *cl_hw, struct cl_sta *cl_sta, u8 tid)
{
	struct ieee80211_sta_vht_cap *vht_cap = &cl_sta->stainfo->sta.vht_cap;
	struct cl_amsdu_ctrl *amsdu_anchor = &cl_sta->amsdu_anchor[tid];
	u32 length = U32_MAX;

	amsdu_anchor->max_len = 3839;

	if (cl_band_is_6g(cl_hw)) {
		u16 capa = le16_to_cpu(cl_sta->stainfo->sta.he_6ghz_capa.capa);

		length = (capa & IEEE80211_HE_6GHZ_CAP_MAX_MPDU_LEN) >>
			HE_6GHZ_CAP_MAX_MPDU_LEN_OFFSET;
	} else if (vht_cap->vht_supported) {
		length = vht_cap->cap & IEEE80211_VHT_CAP_MAX_MPDU_MASK;
	}

	switch (length) {
	case IEEE80211_VHT_CAP_MAX_MPDU_LENGTH_3895:
		amsdu_anchor->max_len = 3895;
		break;
	case IEEE80211_VHT_CAP_MAX_MPDU_LENGTH_7991:
		amsdu_anchor->max_len = 7991;
		break;
	case IEEE80211_VHT_CAP_MAX_MPDU_LENGTH_11454:
		amsdu_anchor->max_len = 11454;
		break;
	default:
		break;
	}

	amsdu_anchor->rem_len = amsdu_anchor->max_len;

	cl_dbg_trace(cl_hw, "AMSDU supported - sta_idx=%u, max_len=%d\n",
		     cl_sta->sta_idx, amsdu_anchor->max_len);
}

void cl_tx_amsdu_first_sub_frame(struct cl_sw_txhdr *sw_txhdr, struct cl_sta *cl_sta,
				 struct sk_buff *skb, u8 tid)
{
	/* Set the anchor sw_txhdr */
	cl_sta->amsdu_anchor[tid].sw_txhdr = sw_txhdr;

	INIT_LIST_HEAD(&sw_txhdr->amsdu_txhdr.list);
	sw_txhdr->amsdu_txhdr.skb = skb;
}

void cl_tx_amsdu_flush_sub_frames(struct cl_hw *cl_hw, struct cl_sw_txhdr *sw_txhdr)
{
	struct cl_chip *chip = cl_hw->chip;
	struct cl_amsdu_txhdr *amsdu_txhdr = NULL, *tmp = NULL;
	struct sk_buff *sub_skb = NULL;

	/* Free mid & last AMSDU sub frames */
	list_for_each_entry_safe(amsdu_txhdr, tmp, &sw_txhdr->amsdu_txhdr.list, list) {
		sub_skb = amsdu_txhdr->skb;
		list_del(&amsdu_txhdr->list);

		if (IS_PCI_BUS_TYPE(chip))
			dma_unmap_single(chip->dev, amsdu_txhdr->dma_addr,
					 (size_t)sub_skb->len, DMA_TO_DEVICE);
		kfree_skb(sub_skb);
		cl_tx_amsdu_txhdr_free(cl_hw, amsdu_txhdr);
		cl_hw->tx_packet_cntr.drop.queue_flush++;
		sw_txhdr->cl_vif->trfc_cntrs[sw_txhdr->ac].tx_dropped++;
	}

	/* Free first AMSDU sub frame */
	kfree_skb(sw_txhdr->skb);
	cl_sw_txhdr_free(cl_hw, sw_txhdr);
}

void cl_tx_amsdu_transfer_single(struct cl_hw *cl_hw, struct cl_sw_txhdr *sw_txhdr)
{
	/*
	 * Transfer all skbs in sw_txhdr to a temporary list, free sw_txhdr,
	 * and then push the temporary list to the single path.
	 */
	struct cl_amsdu_txhdr *amsdu_txhdr, *tmp;
	struct sk_buff *skb;
	struct cl_sta *cl_sta = sw_txhdr->cl_sta;
	struct cl_chip *chip = cl_hw->chip;
	u8 tid = sw_txhdr->tid;

	/* Transfer first AMSDU sub frame */
	_cl_tx_amsdu_transfer_single(cl_hw, sw_txhdr->skb, cl_sta, tid);

	/* Transfer mid & last AMSDU sub frames */
	list_for_each_entry_safe(amsdu_txhdr, tmp, &sw_txhdr->amsdu_txhdr.list, list) {
		skb = amsdu_txhdr->skb;

		list_del(&amsdu_txhdr->list);
		if (IS_PCI_BUS_TYPE(chip))
			dma_unmap_single(chip->dev, amsdu_txhdr->dma_addr,
					 (size_t)skb->len, DMA_TO_DEVICE);
		cl_tx_amsdu_txhdr_free(cl_hw, amsdu_txhdr);

		_cl_tx_amsdu_transfer_single(cl_hw, skb, cl_sta, tid);
	}
}

int cl_tx_amsdu_set(struct cl_hw *cl_hw, struct cl_sta *cl_sta, struct sk_buff *skb, u8 tid)
{
	struct cl_chip *chip = cl_hw->chip;
	struct cl_amsdu_ctrl *amsdu_anchor = &cl_sta->amsdu_anchor[tid];
	struct cl_sw_txhdr *anchor_sw_txhdr = amsdu_anchor->sw_txhdr;
	u16 packet_len = skb->len;
	u32 packet_addr = CL_USB_PKT_ADDR_AMSDU_PATTERN;
	u8 packet_cnt;
	bool is_mesh = ieee80211_vif_is_mesh(cl_sta->cl_vif->vif);

	/* Check if anchor exist */
	if (!anchor_sw_txhdr) {
		/* Sanity check - skb len < amsdu_max_len */
		if (unlikely(packet_len > amsdu_anchor->max_len) || is_mesh)
			return CL_AMSDU_SKIP;
		else
			return cl_tx_amsdu_anchor_set(cl_hw, cl_sta, skb, tid);
	}

	if (amsdu_anchor->is_sw_amsdu)
		return cl_tx_amsdu_sw_aggregate(cl_hw, amsdu_anchor, skb);

	/*
	 * 1. Check if there is enough space in AMSDU
	 * 2. Check if A-MSDU packet count is less than maximum.
	 */
	packet_cnt = amsdu_anchor->packet_cnt;

	if (amsdu_anchor->rem_len > packet_len &&
	    packet_cnt < cl_hw->txamsdu_en &&
	    !is_mesh) {
		struct cl_amsdu_txhdr *amsdu_txhdr = NULL;
		u8 hdr_pads = CL_SKB_DATA_ALIGN_PADS(skb->data);
		u16 ethertype = (skb->data[12] << 8) | skb->data[13];
		u16 total_packet_len = packet_len + hdr_pads;
		u16 curr_amsdu_len = amsdu_anchor->max_len - amsdu_anchor->rem_len;
		dma_addr_t dma_addr;

		if (ethertype >= ETH_P_802_3_MIN)
			total_packet_len += sizeof(rfc1042_header);

		/*
		 * High number of MSDUs in AMSDU can cause underrun in the
		 * E2W module.
		 * Therefore, host is required to set Num MSDU in AMSDU using
		 * the following rules
		 *
		 * AMSDU Length      AMSDU agg size
		 * len  < 4*256      4 or less
		 * len >= 4*256      4 or less
		 * len >= 5*256      5 or less
		 * len >= 6*256      6 or less
		 * len >= 7*256      7 or less
		 * len >= 8*256      8 or less
		 */
		u16 new_amsdu_len = curr_amsdu_len + packet_len;

		if (packet_cnt >= CL_AMSDU_MIN_AGG_SIZE)
			if (new_amsdu_len < ((packet_cnt + 1) * CL_AMSDU_CONST_LEN))
				return cl_tx_amsdu_anchor_set(cl_hw, cl_sta, skb, tid);

		amsdu_txhdr = cl_tx_amsdu_txhdr_alloc(cl_hw);
		if (unlikely(!amsdu_txhdr)) {
			kfree_skb(skb);
			cl_dbg_err(cl_hw, "AMSDU FAILED to alloc amsdu txhdr\n");
			cl_hw->tx_packet_cntr.drop.amsdu_alloc_fail++;
			cl_sta->cl_vif->trfc_cntrs[anchor_sw_txhdr->ac].tx_errors++;
			return CL_AMSDU_FAILED;
		}

		amsdu_txhdr->skb = skb;
		list_add_tail(&amsdu_txhdr->list, &anchor_sw_txhdr->amsdu_txhdr.list);

		/* Update anchor fields */
		amsdu_anchor->rem_len -= total_packet_len;
		amsdu_anchor->packet_cnt++;

		if (IS_PCI_BUS_TYPE(chip)) {
			/* Get DMA address for skb */
			dma_addr = dma_map_single(chip->dev, (u8 *)skb->data - hdr_pads,
						  packet_len + hdr_pads, DMA_TO_DEVICE);
			if (WARN_ON(dma_mapping_error(chip->dev, dma_addr))) {
				kfree_skb(skb);
				cl_tx_amsdu_txhdr_free(cl_hw, amsdu_txhdr);
				cl_dbg_err(cl_hw, "dma_mapping_error\n");
				cl_hw->tx_packet_cntr.drop.amsdu_dma_map_err++;
				cl_sta->cl_vif->trfc_cntrs[anchor_sw_txhdr->ac].tx_errors++;
				return CL_AMSDU_FAILED;
			}

			amsdu_txhdr->dma_addr = dma_addr;
			packet_addr = (u32)dma_addr;
		}

		/* Add AMSDU HDR len of the first packet */
		if (amsdu_anchor->packet_cnt == 2)
			total_packet_len += CL_AMSDU_HDR_LEN;

		/* Update BSR data counters */
		cl_bsr_counters_inc(cl_hw, anchor_sw_txhdr, total_packet_len);

		/* Update sw_txhdr packet_len, packet_addr, packet_cnt fields */
		cl_tx_amsdu_anchor_umacdesc_update(&anchor_sw_txhdr->txdesc, packet_cnt,
						   packet_len, packet_addr, hdr_pads);

		/* If we reached max AMSDU payload count, mark anchor as NULL */
		if (amsdu_anchor->packet_cnt >= cl_hw->txamsdu_en)
			cl_tx_amsdu_anchor_init(amsdu_anchor);

		return CL_AMSDU_SUB_FRAME_SET;
	}
	/* Not enough space remain, set new anchor length is ok */
	if (unlikely(packet_len > amsdu_anchor->max_len) || is_mesh) {
		cl_tx_amsdu_anchor_init(amsdu_anchor);
		return CL_AMSDU_SKIP;
	} else {
		return cl_tx_amsdu_anchor_set(cl_hw, cl_sta, skb, tid);
	}
}

void cl_tx_amsdu_unset(struct cl_sw_txhdr *sw_txhdr)
{
	struct ieee80211_tx_info *tx_info = IEEE80211_SKB_CB(sw_txhdr->skb);

	tx_info->control.flags &= ~IEEE80211_TX_CTRL_AMSDU;

	sw_txhdr->txdesc.e2w_txhdr_param.qos_ctrl &=
				~cpu_to_le16(IEEE80211_QOS_CTL_A_MSDU_PRESENT);
}

/*
 * Two options for allocating cl_amsdu_txhdr:
 * 1) pool
 * 2) cache
 */

static int cl_tx_amsdu_txhdr_init_pool(struct cl_hw *cl_hw)
{
	u16 amsdu_txhdr_pool = cl_hw->conf->ci_amsdu_txhdr_pool;
	u32 i = 0;
	u32 amsdu_txhdr_pool_size = amsdu_txhdr_pool * sizeof(struct cl_amsdu_txhdr);
	struct cl_amsdu_txhdr *amsdu_txhdr;

	INIT_LIST_HEAD(&cl_hw->head_amsdu_txhdr_pool);

	for (i = 0; i < amsdu_txhdr_pool; i++) {
		amsdu_txhdr = kzalloc(sizeof(*amsdu_txhdr), GFP_ATOMIC);

		if (unlikely(!amsdu_txhdr)) {
			cl_dbg_err(cl_hw, "amsdu_txhdr NULL\n");
			return -1;
		}

		list_add(&amsdu_txhdr->list_pool, &cl_hw->head_amsdu_txhdr_pool);
	}

	cl_dbg_verbose(cl_hw, " - pool %u, size %u\n",
		       amsdu_txhdr_pool, amsdu_txhdr_pool_size);

	return 0;
}

static int cl_tx_amsdu_txhdr_init_cache(struct cl_hw *cl_hw)
{
	char amsdu_txhdr_cache_name[MODULE_NAME_LEN + 32] = {0};

	snprintf(amsdu_txhdr_cache_name, sizeof(amsdu_txhdr_cache_name),
		 "%s_amsdu_txhdr_cache", THIS_MODULE->name);

	cl_hw->amsdu_txhdr_cache = kmem_cache_create(amsdu_txhdr_cache_name,
						     sizeof(struct cl_amsdu_txhdr),
						     0,
						     (SLAB_HWCACHE_ALIGN | SLAB_PANIC),
						     NULL);

	if (!cl_hw->amsdu_txhdr_cache) {
		cl_dbg_err(cl_hw, "amsdu_txhdr_cache NULL\n");
		return -1;
	}

	return 0;
}

int cl_tx_amsdu_txhdr_init(struct cl_hw *cl_hw)
{
	if (cl_hw->conf->ci_amsdu_txhdr_pool)
		return cl_tx_amsdu_txhdr_init_pool(cl_hw);
	else
		return cl_tx_amsdu_txhdr_init_cache(cl_hw);
}

static void cl_tx_amsdu_txhdr_deinit_pool(struct cl_hw *cl_hw)
{
	struct cl_amsdu_txhdr *amsdu_txhdr, *tmp;

	list_for_each_entry_safe(amsdu_txhdr, tmp, &cl_hw->head_amsdu_txhdr_pool, list_pool) {
		list_del(&amsdu_txhdr->list_pool);
		kfree(amsdu_txhdr);
	}
}

static void cl_tx_amsdu_txhdr_deinit_cache(struct cl_hw *cl_hw)
{
	kmem_cache_destroy(cl_hw->amsdu_txhdr_cache);
}

void cl_tx_amsdu_txhdr_deinit(struct cl_hw *cl_hw)
{
	if (cl_hw->conf->ci_amsdu_txhdr_pool)
		cl_tx_amsdu_txhdr_deinit_pool(cl_hw);
	else
		cl_tx_amsdu_txhdr_deinit_cache(cl_hw);
}

void cl_tx_amsdu_txhdr_free(struct cl_hw *cl_hw, struct cl_amsdu_txhdr *amsdu_txhdr)
{
	if (cl_hw->conf->ci_amsdu_txhdr_pool)
		list_add_tail(&amsdu_txhdr->list_pool, &cl_hw->head_amsdu_txhdr_pool);
	else
		kmem_cache_free(cl_hw->amsdu_txhdr_cache, amsdu_txhdr);
}

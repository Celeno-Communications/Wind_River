// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "chip.h"
#include "cl_ipc.h"
#include "cl_tx.h"
#include "cl_agg_cfm.h"
#include "cl_single_cfm.h"
#include "cl_bcmc_cfm.h"
#include "cl_tx_queue.h"
#include "cl_msg_tx.h"
#include "cl_rate_ctrl.h"
#include "cl_tx_amsdu.h"
#include "cl_traffic.h"
#include "cl_band.h"
#include "cl_vns.h"
#include "cl_utils.h"
#include "cl_enhanced_tim.h"
#include "cl_mac_addr.h"
#include "cl_key.h"
#include "cl_cma.h"
#include "cl_m2u.h"
#include "cl_ip.h"
#include "cl_radio.h"
#include "cl_recovery.h"
#include "cl_vlan_dscp.h"
#include "cl_wrs_api.h"
#include "cl_bsr.h"
#include "cl_mac80211.h"
#include "cl_usb.h"
#ifdef TRACE_SUPPORT
#include "cl_trace.h"
#endif

/* Expected Acknowledgment */
#define EXPECTED_NO_ACK 0
#define EXPECTED_ACK    1

static void cl_tx_cpu_single(struct cl_hw *cl_hw)
{
	u32 processor_id = smp_processor_id();

	if (processor_id < CPU_MAX_NUM)
		cl_hw->cpu_cntr.tx_single[processor_id]++;
}

static void cl_tx_cpu_agg(struct cl_hw *cl_hw)
{
	u32 processor_id = smp_processor_id();

	if (processor_id < CPU_MAX_NUM)
		cl_hw->cpu_cntr.tx_agg[processor_id]++;
}

static inline void cl_tx_update_stats(struct sk_buff *skb, struct cl_sta *cl_sta, u16 ac, u8 tid)
{
	struct sta_info *stainfo = cl_sta->stainfo;
	struct net_device *dev = skb->dev;
	struct pcpu_sw_netstats *tstats = this_cpu_ptr(dev->tstats);

	u64_stats_update_begin(&tstats->syncp);
	tstats->tx_packets++;
	tstats->tx_bytes += skb->len;
	u64_stats_update_end(&tstats->syncp);

	stainfo->tx_stats.bytes[ac] += skb->len;
	stainfo->tx_stats.packets[ac]++;
	stainfo->tx_stats.msdu[tid]++;
}

static char cl_tx_ctrl_single_frame_type(__le16 fc)
{
	if (ieee80211_is_data_qos(fc))
		return CL_TX_SINGLE_FRAME_TYPE_QOS_DATA;
	else if (ieee80211_is_qos_nullfunc(fc))
		return CL_TX_SINGLE_FRAME_TYPE_QOS_NULL;
	else if (ieee80211_is_mgmt(fc))
		return CL_TX_SINGLE_FRAME_TYPE_MANAGEMENT;
	else
		return CL_TX_SINGLE_FRAME_TYPE_OTHER;
}

static void cl_tx_single_prep(struct cl_hw *cl_hw, struct cl_sw_txhdr *sw_txhdr,
			      u16 frame_len, u8 hdr_pads, bool is_vns)
{
	struct ieee80211_tx_info *tx_info = IEEE80211_SKB_CB(sw_txhdr->skb);
	struct ieee80211_key_conf *key_conf = tx_info->control.hw_key;
	struct txdesc *txdesc = &sw_txhdr->txdesc;
	struct tx_host_info *host_info = &txdesc->host_info;

	/* Reset txdesc */
	memset(txdesc, 0, sizeof(struct txdesc));

	/* Vif_index must be filled in even without header conversion */
	if (!cl_tx_ctrl_is_inject(tx_info)) {
		struct cl_vif *cl_vif = (struct cl_vif *)tx_info->control.vif->drv_priv;

		host_info->vif_index = cl_vif->vif_index;
	}

	if (hdr_pads)
		host_info->host_padding |= BIT(0);

	txdesc->umacdesc.sngl_info.single_frm_flags.is_bcn = sw_txhdr->is_bcn;
	host_info->expected_ack = (tx_info->flags & IEEE80211_TX_CTL_NO_ACK) ?
		EXPECTED_NO_ACK : EXPECTED_ACK;

	/* Beware when prot and sta is unknown */
	if (key_conf) {
		frame_len += key_conf->icv_len;
		host_info->is_protected = true;
		txdesc->e2w_result.hw_key_idx = key_conf->hw_key_idx;
	}

	host_info->packet_cnt = 1;
	host_info->is_vns = is_vns;

	txdesc->umacdesc.sngl_info.packet_len = cpu_to_le16(frame_len);
	txdesc->umacdesc.sngl_info.single_frm_flags.bcmc = (sw_txhdr->sta_idx == STA_IDX_INVALID);
	txdesc->umacdesc.sngl_info.single_frm_flags.single_type =
	 cl_tx_ctrl_single_frame_type(sw_txhdr->fc);

	txdesc->e2w_result.tid = sw_txhdr->tid;
	txdesc->e2w_result.is_txinject = cl_tx_ctrl_is_inject(tx_info);
	txdesc->e2w_result.single_valid_sta__agg_e2w_tx_done = sw_txhdr->cl_sta ? 1 : 0;
	txdesc->e2w_natt_param.sta_index = sw_txhdr->sta_idx;
	txdesc->e2w_txhdr_param.frame_ctrl = sw_txhdr->fc;

	/* Set rate control */
	cl_rate_ctrl_update_desc_single(cl_hw, host_info, sw_txhdr);
}

static void cl_tx_sub_frame_set(struct cl_sta *cl_sta, u8 tid)
{
	struct cl_tx_queue *tx_queue = cl_sta->agg_tx_queues[tid];

	if (tx_queue)
		tx_queue->total_packets++;
}

static void cl_tx_send(struct cl_hw *cl_hw, struct cl_sw_txhdr *sw_txhdr,
		       struct cl_amsdu_ctrl *amsdu_anchor)
{
	struct cl_tx_queue *tx_queue = sw_txhdr->tx_queue;

	tx_queue->total_packets++;

	if (cl_txq_is_fw_full(tx_queue)) {
		/* If firmware is full push the packet to the queue */
		cl_txq_push(cl_hw, sw_txhdr);
	} else if (amsdu_anchor && amsdu_anchor->is_sw_amsdu) {
		cl_txq_push(cl_hw, sw_txhdr);
		tasklet_schedule(&cl_hw->tx_task);
	} else if (!list_empty(&tx_queue->hdrs) || cl_hw->tx_db.force_amsdu) {
		/*
		 * If queue in driver is not empty push the packet to the queue,
		 * and call cl_txq_sched() to transfer packets from the queue to firmware
		 */
		cl_txq_push(cl_hw, sw_txhdr);
		cl_txq_sched(cl_hw, tx_queue);
	} else {
		/* Push the packet directly to firmware */
		cl_tx_push(cl_hw, sw_txhdr, tx_queue);
	}
}

static void cl_tx_ipc_txdesc_populate(struct cl_hw *cl_hw, struct txdesc *txdesc,
				      u8 queue_type, u32 ipc_queue_idx)
{
	/*
	 * 1) Request allocation of txdesc associated with queue type and index from the ipc layer.
	 * 2) Populate ipc-txdesc with the received txdesc.
	 * 3) Increase write index - (must be last action since FW fetch WR idx first).
	 */
	__le32 *write_idx_ptr = NULL;
	struct txdesc *ipc_txdesc = NULL;
	struct cl_txdesc_write_idx *txdesc_write_idx = cl_hw->ipc_write_idx.txdesc_write_idx;
	u32 write_idx = 0;
	u32 masked_write_idx = 0;

	switch (queue_type) {
	case QUEUE_TYPE_AGG:
		ipc_txdesc = cl_hw->ipc_tx_queues.ipc_txdesc_agg[ipc_queue_idx];
		write_idx = le32_to_cpu(txdesc_write_idx->agg[ipc_queue_idx]);
		write_idx_ptr = &txdesc_write_idx->agg[ipc_queue_idx];
		masked_write_idx = write_idx & (TXDESC_AGG_Q_SIZE_MAX - 1);
		break;
	case QUEUE_TYPE_SINGLE:
		ipc_txdesc = cl_hw->ipc_tx_queues.ipc_txdesc_single[ipc_queue_idx];
		write_idx = le32_to_cpu(txdesc_write_idx->single[ipc_queue_idx]);
		write_idx_ptr = &txdesc_write_idx->single[ipc_queue_idx];
		masked_write_idx = write_idx & (IPC_TXDESC_CNT_SINGLE - 1);
		break;
	case QUEUE_TYPE_BCMC:
		ipc_txdesc = cl_hw->ipc_tx_queues.ipc_txdesc_bcmc;
		write_idx = le32_to_cpu(txdesc_write_idx->bcmc);
		write_idx_ptr = &txdesc_write_idx->bcmc;
		masked_write_idx = write_idx & (IPC_TXDESC_CNT_BCMC - 1);
		break;
	default:
		cl_dbg_verbose(cl_hw, "undefined queue type %u\n", queue_type);
		WARN_ON(true);
	}

	ipc_txdesc += masked_write_idx;

	memcpy(ipc_txdesc, txdesc, sizeof(struct txdesc));

	/*
	 * Update write pointer only after new txdesc copy is done since FW
	 * fetch WR pointer first, if not, FW might read and old txdesc since
	 * WR index indicate txdesc is valid.
	 */
	*write_idx_ptr = cpu_to_le32(write_idx + 1);
}

static void cl_tx_fw_send(struct cl_hw *cl_hw,
			  struct cl_sw_txhdr *sw_txhdr,
			  struct cl_tx_queue *tx_queue)
{
	struct cl_chip *chip = cl_hw->chip;
	struct ieee80211_tx_info *tx_info = IEEE80211_SKB_CB(sw_txhdr->skb);
	struct txdesc *txdesc = &sw_txhdr->txdesc;
	struct tx_host_info *host_info = &txdesc->host_info;
	struct cl_sta *cl_sta = sw_txhdr->cl_sta;
	struct cl_vif *cl_vif = sw_txhdr->cl_vif;
	u8 hw_queue = sw_txhdr->hw_queue;
	u16 a2e_trigger_bit_pos;
	u8 tid = sw_txhdr->tid;
	u8 queue_type = tx_queue->type;
	bool no_ps_buffer = !!(tx_info->flags & IEEE80211_TX_CTL_NO_PS_BUFFER);
	u16 ipc_queue_idx = tx_queue->index;
	bool is_mgmt = ieee80211_is_mgmt(sw_txhdr->fc);
	u8 i = 0;
	bool should_trigger = true;
	u8 *cpu_addr = (u8 *)sw_txhdr->skb->data -
		       ((host_info->host_padding & 1) * 2);
	dma_addr_t dma_addr;

	if (IS_PCI_BUS_TYPE(chip)) {
		dma_addr = dma_map_single(chip->dev, cpu_addr,
					  sw_txhdr->map_len, DMA_TO_DEVICE);

		if (WARN_ON(dma_mapping_error(chip->dev, dma_addr))) {
			tx_queue->dump_dma_map_fail++;
			if (queue_type == QUEUE_TYPE_SINGLE) {
				if (!is_mgmt)
					cl_vif->sequence_number = DEC_SN(cl_vif->sequence_number);
				cl_tx_single_free_skb(cl_hw, sw_txhdr->skb);
			} else {
				if (queue_type == QUEUE_TYPE_AGG) {
					struct cl_baw *baw = &cl_sta->baws[tid];

					baw->tid_seq = DEC_SN(baw->tid_seq);
				}
				dev_kfree_skb_any(sw_txhdr->skb);
			}
			cl_sw_txhdr_free(cl_hw, sw_txhdr);

			return;
		}

		txdesc->umacdesc.agg_info.packet_addr[0] = cpu_to_le32(dma_addr);
	} else {
		if (queue_type == QUEUE_TYPE_AGG) {
			struct cl_baw *baw = &cl_sta->baws[tid];
			/* Not used for AGG - set for future debug */
			txdesc->umacdesc.agg_info.packet_addr[0] = cpu_to_le32(baw->tid_seq);
		} else {
			u16 idx = cl_usb_get_single_addr_idx(chip);

			txdesc->umacdesc.agg_info.packet_addr[0] = cpu_to_le32(idx);
		}
	}

	cl_tx_ipc_txdesc_populate(cl_hw, txdesc, queue_type, ipc_queue_idx);

	/* make sure memory is written before push to HW */
	wmb();

	/*
	 * 1) Notify firmware on new buffered traffic by updating the enhanced tim.
	 * 2) Push sw_txhdr to confirmation list
	 */
	if (queue_type == QUEUE_TYPE_AGG) {
		a2e_trigger_bit_pos = IPC_IRQ_A2E_TXDESC_AGG_MAP(hw_queue);
		cl_agg_cfm_add(cl_hw, sw_txhdr, ipc_queue_idx);
		cl_enhanced_tim_set_tx_agg(cl_hw, ipc_queue_idx, hw_queue,
					   no_ps_buffer, cl_sta, tid);
		if (IS_USB_BUS_TYPE(chip)) {
			if (!cl_hw->tx_db.ac_idle[hw_queue])
				should_trigger = false;
			else
				cl_hw->tx_db.ac_idle[hw_queue] = false;
		}
	} else if (queue_type == QUEUE_TYPE_SINGLE) {
		a2e_trigger_bit_pos = IPC_IRQ_A2E_TXDESC_SINGLE_MAP(hw_queue);
		cl_single_cfm_add(cl_hw, sw_txhdr, ipc_queue_idx);
		cl_enhanced_tim_set_tx_single(cl_hw, ipc_queue_idx, hw_queue,
					      no_ps_buffer, cl_sta, tid);
	} else {
		a2e_trigger_bit_pos = IPC_IRQ_A2E_TXDESC_SINGLE_MAP(hw_queue);
		cl_bcmc_cfm_add(cl_hw, sw_txhdr);
	}

	/* Tx_queue counters */
	tx_queue->fw_free_space--;
	tx_queue->total_fw_push_desc++;
	tx_queue->total_fw_push_skb += host_info->packet_cnt;

	/* VIF statistics */
	cl_vif->trfc_cntrs[sw_txhdr->ac].tx_packets += host_info->packet_cnt;

	for (i = 0; i < host_info->packet_cnt; i++)
		cl_vif->trfc_cntrs[sw_txhdr->ac].tx_bytes +=
				le16_to_cpu(txdesc->umacdesc.agg_info.packet_len[i]);
#ifdef TRACE_SUPPORT
	trace_cl_trace_tx_push(cl_hw->idx, sw_txhdr->skb, host_info->packet_cnt,
			       txdesc->e2w_txhdr_param.seq_ctrl, tid);
#endif

	/* Trigger interrupt to firmware so that it will know that a new descriptor is ready */
	if (should_trigger)
		cl_hw->ipc_host2xmac_trigger_set(chip, BIT(a2e_trigger_bit_pos));
}

void cl_tx_push(struct cl_hw *cl_hw, struct cl_sw_txhdr *sw_txhdr, struct cl_tx_queue *tx_queue)
{
	struct ieee80211_tx_info *tx_info = IEEE80211_SKB_CB(sw_txhdr->skb);
	struct ieee80211_key_conf *keyconf = tx_info->control.hw_key;
	struct cl_sta *cl_sta = sw_txhdr->cl_sta;
	struct cl_vif *cl_vif = sw_txhdr->cl_vif;
	u8 tid = sw_txhdr->tid;
	struct txdesc *txdesc = &sw_txhdr->txdesc;
	struct tx_host_info *host_info = &txdesc->host_info;
	struct cl_e2w_txhdr_param *e2w_txhdr_param = &txdesc->e2w_txhdr_param;
	struct ieee80211_hdr *hdr80211 = sw_txhdr->hdr80211;
	u8 queue_type = tx_queue->type;
	bool is_mgmt = ieee80211_is_mgmt(sw_txhdr->fc);
	struct cl_baw *baw;

	if (cl_key_is_cipher_ccmp_gcmp(keyconf)) {
		/*
		 * In case of CCMP or GCMP encryption we need to inc pn.
		 * In case of amsdu/header_conversion we need to pass it to firmware as well
		 */
		u64 pn = atomic64_inc_return(&keyconf->tx_pn);

		if (txdesc->e2w_natt_param.hdr_conv_enable) {
			memcpy(&e2w_txhdr_param->encrypt_pn, &pn, CL_CCMP_GCMP_PN_SIZE);
		} else {
			u8 hdrlen = ieee80211_hdrlen(sw_txhdr->fc);

			cl_key_ccmp_gcmp_pn_to_hdr((u8 *)hdr80211 + hdrlen, pn, keyconf->keyidx);
		}
	}

	if (queue_type == QUEUE_TYPE_AGG) {
		baw = &cl_sta->baws[tid];
		if (cl_tx_ctrl_is_amsdu(tx_info)) {
			struct cl_amsdu_ctrl *amsdu_anchor = &cl_sta->amsdu_anchor[tid];

			if (sw_txhdr->is_sw_amsdu) {
				u8 pkt_cnt = sw_txhdr->sw_amsdu_packet_cnt;

				if (pkt_cnt == 1)
					cl_tx_amsdu_unset(sw_txhdr); /* Clear AMSDU bit. */

				if (hdr80211)
					hdr80211->seq_ctrl = cpu_to_le16(baw->tid_seq);

				tx_queue->stats_sw_amsdu_cnt[pkt_cnt - 1]++;
			} else {
				u8 pkt_cnt = host_info->packet_cnt;

				if (pkt_cnt == 1)
					cl_tx_amsdu_unset(sw_txhdr); /* Clear AMSDU bit. */

				tx_queue->stats_hw_amsdu_cnt[pkt_cnt - 1]++;
			}

			/* Reset anchor if needed */
			if (amsdu_anchor->sw_txhdr == sw_txhdr)
				cl_tx_amsdu_anchor_init(amsdu_anchor);
		}

		/* Update sequence number and increase it */
		e2w_txhdr_param->seq_ctrl = cpu_to_le16(baw->tid_seq);
		baw->tid_seq = INC_SN(baw->tid_seq);
	} else {
		/*
		 * Update sequence number and increase it
		 * Management sequence number is set by firmware.
		 */
		if (!is_mgmt) {
			hdr80211->seq_ctrl |= cpu_to_le16(cl_vif->sequence_number);
			cl_vif->sequence_number = INC_SN(cl_vif->sequence_number);
		}
	}

	cl_tx_fw_send(cl_hw, sw_txhdr, tx_queue);
}

void cl_tx_single_free_skb(struct cl_hw *cl_hw, struct sk_buff *skb)
{
	if (IEEE80211_SKB_CB(skb)->ack_frame_id)
		ieee80211_tx_status(cl_hw->hw, skb);
	else
		dev_kfree_skb_any(skb);
}

void cl_tx_single(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
		  struct sk_buff *skb, bool is_vns, bool lock)
{
	struct cl_tx_queue *tx_queue;
	struct cl_sw_txhdr *sw_txhdr;
	struct ieee80211_tx_info *tx_info = IEEE80211_SKB_CB(skb);
	struct cl_vif *cl_vif = (struct cl_vif *)tx_info->control.vif->drv_priv;
	struct ieee80211_hdr *hdr80211 = (struct ieee80211_hdr *)skb->data;
	u8 hdr_pads = CL_SKB_DATA_ALIGN_PADS(hdr80211);
	__le16 fc = hdr80211->frame_control;
	u16 frame_len = (u16)skb->len;
	u8 tid = ieee80211_is_data_qos(fc) ? ieee80211_get_tid(hdr80211) : 0;
	int ac = cl_tid_to_ac(tid);
	bool is_beacon = ieee80211_is_beacon(fc);

	cl_tx_cpu_single(cl_hw);

	if (unlikely(!test_bit(CL_DEV_STARTED, &cl_hw->drv_flags) ||
		     test_bit(CL_DEV_HW_RESTART, &cl_hw->drv_flags) ||
		     test_bit(CL_DEV_FW_ERROR, &cl_hw->drv_flags))) {
		cl_tx_single_free_skb(cl_hw, skb);
		cl_hw->tx_packet_cntr.drop.dev_flags++;
		cl_vif->trfc_cntrs[ac].tx_dropped++;
		return;
	}

	if (unlikely(!cl_vif->tx_en || cl_hw->tx_disable_flags)) {
		cl_tx_single_free_skb(cl_hw, skb);
		cl_hw->tx_packet_cntr.drop.tx_disable++;
		cl_vif->trfc_cntrs[ac].tx_dropped++;
		return;
	}

	/* Check if packet length exceeds max size */
	if (unlikely(frame_len > CL_TX_MAX_FRAME_LEN_SINGLE)) {
		cl_tx_single_free_skb(cl_hw, skb);
		cl_dbg_err(cl_hw, "frame_len (%u) exceeds max size\n", frame_len);
		cl_hw->tx_packet_cntr.drop.length_limit++;
		cl_vif->trfc_cntrs[ac].tx_errors++;
		return;
	}

	if (cl_sta && cl_sta->key_disable) {
		cl_tx_single_free_skb(cl_hw, skb);
		cl_hw->tx_packet_cntr.drop.key_disable++;
		cl_vif->trfc_cntrs[ac].tx_dropped++;
		return;
	}

	/* Allocate sw_txhdr */
	sw_txhdr = cl_sw_txhdr_alloc(cl_hw);

	if (unlikely(!sw_txhdr)) {
		cl_tx_single_free_skb(cl_hw, skb);
		cl_dbg_verbose(cl_hw, "sw_txhdr alloc failed\n");
		cl_hw->tx_packet_cntr.drop.txhdr_alloc_fail++;
		cl_vif->trfc_cntrs[ac].tx_errors++;
		return;
	}

	/* Prepare sw_txhdr */
	sw_txhdr->hdr80211 = hdr80211;
	sw_txhdr->hw_queue = tx_info->hw_queue;
	sw_txhdr->is_bcn = is_beacon;
	sw_txhdr->skb = skb;
	sw_txhdr->map_len = frame_len + hdr_pads;
	sw_txhdr->fc = fc;
	sw_txhdr->cl_vif = cl_vif;
	sw_txhdr->tid = tid;
	sw_txhdr->ac = ac;

	if (cl_sta) {
		sw_txhdr->cl_sta = cl_sta;
		sw_txhdr->sta_idx = cl_sta->sta_idx;
		cl_bsr_counters_inc(cl_hw, sw_txhdr, frame_len);
	} else {
		sw_txhdr->cl_sta = NULL;
		sw_txhdr->sta_idx = STA_IDX_INVALID;
	}

	/* Prepare txdesc */
	cl_tx_single_prep(cl_hw, sw_txhdr, frame_len, hdr_pads, is_vns);

	/*
	 * Fetch the driver queue.
	 * IEEE80211_TX_CTL_AMPDU is not set in tx_info->flags, otherwise cl_tx_agg()
	 * would have been called and not cl_tx_single().
	 * Therefore there is no need to check if tx_queue is NULL or if queue type
	 * is QUEUE_TYPE_AGG.
	 */
	tx_queue = cl_txq_get(cl_hw, sw_txhdr);
	sw_txhdr->tx_queue = tx_queue;

	if (lock) {
		if (tx_queue->type == QUEUE_TYPE_BCMC) {
			/*
			 * There is no need to take spin_lock_irqsave() because bcmb queue
			 * will be called only from interrupt context - cl_irq_status_tbtt().
			 * All other broadcast/multicast packets are buffered in
			 * ieee80211_tx_h_multicast_ps_buf() and will follow the beacon.
			 */
			spin_lock(&cl_hw->tx_lock_bcmc);
			cl_tx_send(cl_hw, sw_txhdr, NULL);
			spin_unlock(&cl_hw->tx_lock_bcmc);
		} else {
			spin_lock_bh(&cl_hw->tx_lock_single);
			cl_tx_send(cl_hw, sw_txhdr, NULL);
			spin_unlock_bh(&cl_hw->tx_lock_single);
		}
	} else {
		cl_tx_send(cl_hw, sw_txhdr, NULL);
	}
}

void cl_tx_fast_single(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
		       struct sk_buff *skb, bool lock)
{
	struct ieee80211_tx_info *tx_info = IEEE80211_SKB_CB(skb);
	u8 tid = skb->priority & IEEE80211_QOS_CTL_TAG1D_MASK;

	/* hw_key must be set before calling cl_tx_8023_to_wlan() */
	tx_info->control.hw_key = cl_key_get(cl_sta);

	/* Convert 802.3 to 802.11 header */
	if (cl_tx_8023_to_wlan(cl_hw, skb, cl_sta, tid) == 0) {
		bool is_vns = cl_vns_is_very_near(cl_hw, cl_sta, skb);
		int ac = cl_tid_to_ac(tid);

		tx_info->hw_queue = ac;
		tx_info->control.vif = cl_sta->cl_vif->vif;

		cl_tx_update_stats(skb, cl_sta, ac, tid);

		cl_hw->tx_packet_cntr.forward.drv_fast_single++;

		cl_tx_single(cl_hw, cl_sta, skb, is_vns, lock);
	}
}

void cl_tx_agg_prep(struct cl_hw *cl_hw, struct cl_sw_txhdr *sw_txhdr,
		    u16 frame_len, u8 hdr_pads, bool hdr_conv)
{
	struct ieee80211_tx_info *tx_info = IEEE80211_SKB_CB(sw_txhdr->skb);
	struct ieee80211_key_conf *key_conf = tx_info->control.hw_key;
	struct txdesc *txdesc = &sw_txhdr->txdesc;
	struct lmacapi *umacdesc = &txdesc->umacdesc;
	struct tx_host_info *host_info = &txdesc->host_info;
	u16 qos_ctrl = sw_txhdr->tid;

	/* Reset txdesc */
	memset(txdesc, 0, sizeof(struct txdesc));

	txdesc->e2w_result.tid = sw_txhdr->tid;
	txdesc->e2w_result.is_txinject = cl_tx_ctrl_is_inject(tx_info);
	txdesc->e2w_natt_param.sta_index = sw_txhdr->sta_idx;
	txdesc->e2w_natt_param.ampdu = true;
	txdesc->e2w_natt_param.hdr_conv_enable = hdr_conv;

	if (hdr_conv) {
		if (cl_tx_ctrl_is_amsdu(tx_info))
			qos_ctrl |= IEEE80211_QOS_CTL_A_MSDU_PRESENT;

		txdesc->e2w_txhdr_param.frame_ctrl = sw_txhdr->fc;
		txdesc->e2w_txhdr_param.qos_ctrl = cpu_to_le16(qos_ctrl);
	}

	if (hdr_pads)
		host_info->host_padding |= BIT(0);

	/* Vif_index must be filled in even without header conversion */
	host_info->vif_index = sw_txhdr->cl_sta->cl_vif->vif_index;

	/* Set the expected_ack flag */
	host_info->expected_ack = (tx_info->flags & IEEE80211_TX_CTL_NO_ACK) ?
		EXPECTED_NO_ACK : EXPECTED_ACK;

	if (key_conf) {
		host_info->is_protected = true;
		txdesc->e2w_result.hw_key_idx = key_conf->hw_key_idx;

		if (!hdr_conv)
			frame_len += key_conf->icv_len;
	}

	host_info->packet_cnt = 1;
	umacdesc->agg_info.packet_len[0] = cpu_to_le16(frame_len);

	/* Set rate control */
	cl_rate_ctrl_update_desc_agg(cl_hw, host_info);
}

static __le16 cl_tx_agg_frame_control(struct cl_vif *cl_vif,
				      struct ieee80211_key_conf *key_conf,
				      u8 *hdrlen)
{
	struct ieee80211_vif *vif = cl_vif->vif;
	struct ieee80211_sub_if_data *sdata = vif_to_sdata(vif);
	enum nl80211_iftype type = vif->type;
	__le16 fc = cpu_to_le16(IEEE80211_FTYPE_DATA | IEEE80211_STYPE_QOS_DATA);

	if (type == NL80211_IFTYPE_AP) {
		fc |= cpu_to_le16(IEEE80211_FCTL_FROMDS);
		*hdrlen = 26;
	} else if (type == NL80211_IFTYPE_STATION) {
		fc |= cpu_to_le16(IEEE80211_FCTL_TODS);

		if (sdata->u.mgd.use_4addr) {
			fc |= cpu_to_le16(IEEE80211_FCTL_FROMDS);
			*hdrlen = 32;
		} else {
			*hdrlen = 26;
		}
	}

	if (key_conf)
		fc |= cpu_to_le16(IEEE80211_FCTL_PROTECTED);

	return fc;
}

static void _cl_tx_agg(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
		       struct sk_buff *skb, bool hdr_conv)
{
	struct ieee80211_tx_info *tx_info = IEEE80211_SKB_CB(skb);
	struct ieee80211_key_conf *key_conf = tx_info->control.hw_key;
	struct cl_sw_txhdr *sw_txhdr = NULL;
	struct cl_tx_queue *tx_queue = NULL;
	struct cl_vif *cl_vif = cl_sta->cl_vif;
	u16 frame_len = (u16)skb->len;
	u16 total_frame_len = 0;
	u8 hdr_pads = CL_SKB_DATA_ALIGN_PADS(skb->data);
	u8 is_amsdu = cl_tx_ctrl_is_amsdu(tx_info);
	u8 tid = skb->priority & IEEE80211_QOS_CTL_TAG1D_MASK;
	int ac = cl_tid_to_ac(tid);
	u8 hdrlen = 0;

	cl_tx_cpu_agg(cl_hw);

	if (unlikely(!test_bit(CL_DEV_STARTED, &cl_hw->drv_flags) ||
		     test_bit(CL_DEV_FW_ERROR, &cl_hw->drv_flags))) {
		kfree_skb(skb);
		cl_hw->tx_packet_cntr.drop.dev_flags++;
		cl_vif->trfc_cntrs[ac].tx_dropped++;
		return;
	}

	if (unlikely(!cl_vif->tx_en || cl_hw->tx_disable_flags)) {
		kfree_skb(skb);
		cl_hw->tx_packet_cntr.drop.tx_disable++;
		cl_vif->trfc_cntrs[ac].tx_dropped++;
		return;
	}

	/* Check if packet length exceeds max size */
	if (unlikely(frame_len > CL_TX_MAX_FRAME_LEN_AGG)) {
		kfree_skb(skb);
		cl_dbg_err(cl_hw, "frame_len exceeds max size %d\n", frame_len);
		cl_hw->tx_packet_cntr.drop.length_limit++;
		cl_vif->trfc_cntrs[ac].tx_errors++;
		return;
	}

	if (cl_sta->key_disable) {
		kfree_skb(skb);
		cl_hw->tx_packet_cntr.drop.key_disable++;
		cl_vif->trfc_cntrs[ac].tx_dropped++;
		return;
	}

	/* Check if amsdu is enable for current skb */
	if (is_amsdu) {
		enum cl_amsdu_result amsdu_res = cl_tx_amsdu_set(cl_hw, cl_sta, skb, tid);

		switch (amsdu_res) {
		case CL_AMSDU_SKIP:
			is_amsdu = false;
			tx_info->control.flags &= ~IEEE80211_TX_CTRL_AMSDU;
		case CL_AMSDU_ANCHOR_SET:
			/*
			 * If new anchor was set, or AMSDU is
			 * skipped continue building sw_txhdr
			 */
			break;
		case CL_AMSDU_SUB_FRAME_SET:
			cl_tx_sub_frame_set(cl_sta, tid);
			fallthrough;
		case CL_AMSDU_FAILED:
		default:
			return;
		}
	} else {
		/*
		 * If not amsdu & anchor exist. reset current anchor
		 * in order to avoid reordring packets.
		 */
		if (cl_sta->amsdu_anchor[tid].sw_txhdr)
			cl_tx_amsdu_anchor_init(&cl_sta->amsdu_anchor[tid]);
	}

	/* Allocate sw_txhdr */
	sw_txhdr = cl_sw_txhdr_alloc(cl_hw);
	if (unlikely(!sw_txhdr)) {
		kfree_skb(skb);
		cl_dbg_err(cl_hw, "sw_txhdr alloc failed\n");
		cl_hw->tx_packet_cntr.drop.txhdr_alloc_fail++;
		cl_vif->trfc_cntrs[ac].tx_errors++;
		return;
	}

	/* Fill sw_txhdr */
	sw_txhdr->tid = tid;
	sw_txhdr->ac = ac;
	sw_txhdr->cl_sta = cl_sta;
	sw_txhdr->sta_idx = cl_sta->sta_idx;
	sw_txhdr->is_bcn = 0;
	sw_txhdr->skb = skb;
	sw_txhdr->map_len = frame_len + hdr_pads;
	sw_txhdr->cl_vif = cl_vif;

	if (cl_sta->amsdu_anchor[tid].is_sw_amsdu) {
		sw_txhdr->is_sw_amsdu = true;
		sw_txhdr->sw_amsdu_packet_cnt = 1;
	} else {
		sw_txhdr->is_sw_amsdu = false;
	}

	if (hdr_conv) {
		sw_txhdr->hdr80211 = NULL;
		sw_txhdr->fc = cl_tx_agg_frame_control(cl_vif, key_conf, &hdrlen);
	} else {
		struct ieee80211_hdr *hdr80211 = (struct ieee80211_hdr *)skb->data;
		__le16 fc = hdr80211->frame_control;

		sw_txhdr->hdr80211 = hdr80211;
		sw_txhdr->fc = fc;
		hdrlen = ieee80211_hdrlen(fc);
	}

	/* Fetch the relevant agg queue */
	tx_queue = cl_sta->agg_tx_queues[tid];

	if (unlikely(!tx_queue)) {
		kfree_skb(skb);
		cl_sw_txhdr_free(cl_hw, sw_txhdr);
		cl_dbg_err(cl_hw, "tx_queue is NULL [sta_idx = %u] [tid = %u]\n",
			   cl_sta->sta_idx, tid);
		cl_hw->tx_packet_cntr.drop.queue_null++;
		cl_vif->trfc_cntrs[ac].tx_dropped++;
		return;
	}

	sw_txhdr->tx_queue = tx_queue;
	/* Due to USB single queue mode use txqueue hw index */
	sw_txhdr->hw_queue = tx_queue->hw_index;

	total_frame_len = frame_len + hdrlen - sizeof(struct ethhdr);

	if (key_conf)
		total_frame_len += key_conf->icv_len;

	cl_bsr_counters_inc(cl_hw, sw_txhdr, total_frame_len);

	/* Prepare txdesc */
	cl_tx_agg_prep(cl_hw, sw_txhdr, frame_len, hdr_pads, hdr_conv);

	/*
	 * AMSDU - first sub frame
	 * !!! Must be done after calling cl_tx_agg_prep() !!!
	 */
	if (is_amsdu)
		cl_tx_amsdu_first_sub_frame(sw_txhdr, cl_sta, skb, tid);

	cl_tx_send(cl_hw, sw_txhdr, &cl_sta->amsdu_anchor[tid]);
}

void cl_tx_agg(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
	       struct sk_buff *skb, bool hdr_conv, bool lock)
{
	if (lock) {
		spin_lock_bh(&cl_hw->tx_lock_agg);
		_cl_tx_agg(cl_hw, cl_sta, skb, hdr_conv);
		spin_unlock_bh(&cl_hw->tx_lock_agg);
	} else {
		_cl_tx_agg(cl_hw, cl_sta, skb, hdr_conv);
	}
}

static bool cl_tx_check_agg(struct ieee80211_sub_if_data *sdata, struct sk_buff *skb)
{
	u16 ethertype = (skb->data[12] << 8) | skb->data[13];

	/* Control port protocol needs a lot of special handling */
	if (cpu_to_be16(ethertype) == sdata->control_port_protocol)
		return false;

	/* Only RFC 1042 SNAP */
	if (ethertype < ETH_P_802_3_MIN)
		return false;

	/* Don't handle TX status request here either */
	if (skb->sk && skb_shinfo(skb)->tx_flags & SKBTX_WIFI_STATUS)
		return false;

	return true;
}

static void cl_tx_reset_session_timer(struct sta_info *stainfo, u8 tid)
{
	struct tid_ampdu_tx *tid_tx = NULL;

	tid_tx = rcu_dereference(stainfo->ampdu_mlme.tid_tx[tid]);

	if (tid_tx && tid_tx->timeout)
		tid_tx->last_tx = jiffies;
}

void cl_tx_fast_agg(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
		    struct sk_buff *skb, bool lock)
{
	struct ieee80211_tx_info *tx_info = IEEE80211_SKB_CB(skb);
	struct ieee80211_vif *vif = cl_sta->cl_vif->vif;
	u16 ac = skb_get_queue_mapping(skb);
	u8 tid = skb->priority & IEEE80211_QOS_CTL_TAG1D_MASK;

	tx_info->control.vif = vif;
	tx_info->control.hw_key = cl_key_get(cl_sta);
	tx_info->hw_queue = vif->hw_queue[ac];
	tx_info->flags |= IEEE80211_TX_CTL_AMPDU;

	if (cl_sta->baws[tid].amsdu &&
	    (cl_wrs_api_get_tx_sta_data_rate(cl_sta) > cl_hw->conf->ci_tx_amsdu_min_data_rate))
		tx_info->control.flags |= IEEE80211_TX_CTRL_AMSDU;

	cl_tx_update_stats(skb, cl_sta, ac, tid);
	cl_tx_agg(cl_hw, cl_sta, skb, true, lock);
	cl_tx_reset_session_timer(cl_sta->stainfo, tid);
	cl_hw->tx_packet_cntr.forward.drv_fast_agg++;
}

void cl_tx_wlan_to_8023(struct sk_buff *skb)
{
	struct ieee80211_hdr *hdr = (struct ieee80211_hdr *)skb->data;
	struct ethhdr tmp_eth;
	struct ethhdr *ehdr;
	struct {
		u8 hdr[ETH_ALEN]__aligned(2);
		__be16 proto;
	} payload;
	u16 hdrlen = ieee80211_hdrlen(hdr->frame_control);
	u8 enc_len = cl_key_get_cipher_len(skb);

	cl_mac_addr_copy(tmp_eth.h_dest, ieee80211_get_DA(hdr));
	cl_mac_addr_copy(tmp_eth.h_source, ieee80211_get_SA(hdr));
	skb_copy_bits(skb, hdrlen, &payload, sizeof(payload));
	tmp_eth.h_proto = payload.proto;

	if (enc_len) {
		memcpy(skb->data + hdrlen,
		       skb->data + hdrlen + enc_len,
		       skb->len - hdrlen - enc_len);
		skb_trim(skb, skb->len - enc_len);
	}

	if (likely((ether_addr_equal(payload.hdr, rfc1042_header) &&
		    tmp_eth.h_proto != htons(ETH_P_AARP) &&
		    tmp_eth.h_proto != htons(ETH_P_IPX)) ||
		   ether_addr_equal(payload.hdr, bridge_tunnel_header)))
		/* Remove RFC1042 or Bridge-Tunnel encapsulation and replace ether_type */
		hdrlen += ETH_ALEN + 2;
	else
		tmp_eth.h_proto = htons(skb->len - hdrlen);

	skb_pull(skb, hdrlen);
	ehdr = skb_push(skb, sizeof(struct ethhdr));
	memcpy(ehdr, &tmp_eth, sizeof(tmp_eth));
}

u16 cl_tx_prepare_wlan_hdr(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
			   struct sk_buff *skb, struct ieee80211_hdr *hdr)
{
	struct ieee80211_sub_if_data *sdata = IEEE80211_DEV_TO_SUB_IF(skb->dev);
	struct ieee80211_tx_info *tx_info = IEEE80211_SKB_CB(skb);
	u16 hdrlen = 0;
	__le16 fc = cpu_to_le16(IEEE80211_FTYPE_DATA | IEEE80211_STYPE_DATA);

	if (tx_info->control.hw_key)
		fc |= cpu_to_le16(IEEE80211_FCTL_PROTECTED);

	switch (sdata->vif.type) {
	case NL80211_IFTYPE_AP:
		fc |= cpu_to_le16(IEEE80211_FCTL_FROMDS);
		/* DA BSSID SA */
		memcpy(hdr->addr1, skb->data, ETH_ALEN);
		memcpy(hdr->addr2, sdata->vif.addr, ETH_ALEN);
		memcpy(hdr->addr3, skb->data + ETH_ALEN, ETH_ALEN);
		hdrlen = 24;
		break;
	case NL80211_IFTYPE_STATION:
		if (sdata->u.mgd.use_4addr) {
			fc |= cpu_to_le16(IEEE80211_FCTL_FROMDS |
					  IEEE80211_FCTL_TODS);
			/* RA TA DA SA */
			memcpy(hdr->addr1, sdata->u.mgd.bssid, ETH_ALEN);
			memcpy(hdr->addr2, sdata->vif.addr, ETH_ALEN);
			memcpy(hdr->addr3, skb->data, ETH_ALEN);
			memcpy(hdr->addr4, skb->data + ETH_ALEN, ETH_ALEN);
			hdrlen = 30;
		} else {
			fc |= cpu_to_le16(IEEE80211_FCTL_TODS);
			/* BSSID SA DA */
			memcpy(hdr->addr1, sdata->u.mgd.bssid, ETH_ALEN);
			memcpy(hdr->addr2, skb->data + ETH_ALEN, ETH_ALEN);
			memcpy(hdr->addr3, skb->data, ETH_ALEN);
			hdrlen = 24;
		}
		break;
	default:
		cl_dbg_err(cl_hw, "Unknown vif type %d !!!\n", sdata->vif.type);
		return 0;
	}

	if (cl_sta->stainfo->sta.wme) {
		fc |= cpu_to_le16(IEEE80211_STYPE_QOS_DATA);
		hdrlen += 2;
	}

	hdr->frame_control = fc;
	hdr->duration_id = 0;
	hdr->seq_ctrl = 0;

	return hdrlen;
}

int cl_tx_8023_to_wlan(struct cl_hw *cl_hw, struct sk_buff *skb, struct cl_sta *cl_sta, u8 tid)
{
	struct ieee80211_hdr hdr;
	int head_need, ret = 0;
	u16 ethertype, hdrlen;
	const u8 *encaps_data = NULL;
	int encaps_len = 0, skip_header_bytes = ETH_HLEN;
	u8 enc_len = cl_key_get_cipher_len(skb);

	/* Convert Ethernet header to proper 802.11 header */
	ethertype = (skb->data[12] << 8) | skb->data[13];

	hdrlen = cl_tx_prepare_wlan_hdr(cl_hw, cl_sta, skb, &hdr);
	if (!hdrlen) {
		ret = -EINVAL;
		goto free;
	}

	if (ethertype >= ETH_P_802_3_MIN) {
		encaps_data = rfc1042_header;
		encaps_len = sizeof(rfc1042_header);
		skip_header_bytes -= 2;
	}

	skb_pull(skb, skip_header_bytes);
	head_need = hdrlen + enc_len + encaps_len - skb_headroom(skb);

	if (head_need > 0) {
		head_need = ((head_need + 3) & ~3);
		if (pskb_expand_head(skb, head_need, 0, GFP_ATOMIC)) {
			ret = -ENOMEM;
			goto free;
		}
	}

	if (encaps_data)
		memcpy(skb_push(skb, encaps_len), encaps_data, encaps_len);

	skb_push(skb, hdrlen + enc_len);

	if (cl_sta->stainfo->sta.wme) {
		u16 qos_ctrl = tid;

		memcpy(skb->data, &hdr, hdrlen - 2);
		memcpy(skb->data + hdrlen - 2, &qos_ctrl, 2);
	} else {
		memcpy(skb->data, &hdr, hdrlen);
	}

	skb_reset_mac_header(skb);

	return ret;
free:
	cl_hw->tx_packet_cntr.drop.build_hdr_fail++;
	cl_sta->cl_vif->trfc_cntrs[cl_tid_to_ac(tid)].tx_errors++;
	kfree_skb(skb);
	skb = NULL;

	return ret;
}

void cl_tx_handle_tx_path_idle(struct cl_hw *cl_hw, u8 bitmap)
{
	int i;
	u16 a2e_trigger_bit_pos;

	for (i = 0; i < IEEE80211_NUM_ACS; i++) {
		if (cl_hw->tx_db.ac_idle[i] || !(bitmap & BIT(i)))
			continue;

		if (cl_enhanced_tim_is_ac_clear(cl_hw, i)) {
			cl_hw->tx_db.ac_idle[i] = true;
			continue;
		}

		a2e_trigger_bit_pos = IPC_IRQ_A2E_TXDESC_AGG_MAP(i);
		cl_hw->ipc_host2xmac_trigger_set(cl_hw->chip,
						 BIT(a2e_trigger_bit_pos));
	}
}

void cl_tx_check_start_ba_session(struct cl_hw *cl_hw,
				  struct sta_info *stainfo,
				  struct sk_buff *skb)
{
	struct ieee80211_hdr *hdr = (struct ieee80211_hdr *)skb->data;
	struct ieee80211_sta *sta = &stainfo->sta;
	struct ieee80211_tx_info *tx_info = IEEE80211_SKB_CB(skb);
	u8 tid;

	if (!sta->ht_cap.ht_supported &&
	    !sta->vht_cap.vht_supported &&
	    !cl_band_is_6g(cl_hw))
		return;

	if (test_sta_flag(stainfo, WLAN_STA_PS_STA))
		return;

	if ((tx_info->flags & IEEE80211_TX_CTL_AMPDU) &&
	    !(tx_info->flags & IEEE80211_TX_STAT_AMPDU))
		return;

	if (cl_tx_ctrl_is_eapol(tx_info))
		return;

	if (unlikely(!ieee80211_is_data_qos(hdr->frame_control)))
		return;

	if (unlikely(skb->protocol == cpu_to_be16(ETH_P_PAE)))
		return;

	tid = ieee80211_get_tid(hdr);

	if (likely(stainfo->ampdu_mlme.tid_tx[tid]))
		return;

	ieee80211_start_tx_ba_session(sta, tid, cl_hw->conf->ce_tx_ba_session_timeout);
}

static struct sk_buff *cl_tx_beacon_get(struct ieee80211_hw *hw,
					struct ieee80211_vif *vif)
{
	struct ieee80211_local *local = hw_to_local(hw);
	struct sk_buff *skb;

	local->tim_in_locked_section = true;
	skb = ieee80211_beacon_get(hw, vif);
	local->tim_in_locked_section = false;

	return skb;
}

static void cl_tx_mc(struct cl_vif *cl_vif, int *mc_fw_free)
{
	struct cl_hw *cl_hw = cl_vif->cl_hw;
	struct ieee80211_vif *vif = cl_vif->vif;
	struct sk_buff *skb = NULL;
	struct ieee80211_tx_info *tx_info;

	if (unlikely(!vif))
		return;

	while (((*mc_fw_free) > 0) &&
	       (skb = ieee80211_get_buffered_bc(cl_hw->hw, vif))) {
		/* Route this MCBC frame to the BCN ipc queue */
		tx_info = IEEE80211_SKB_CB(skb);
		tx_info->hw_queue = CL_HWQ_BCN;

		(*mc_fw_free)--;

		/* Clear more data bit if this is the last frame in this SP */
		if (*mc_fw_free == 0) {
			struct ieee80211_hdr *hdr =
					(struct ieee80211_hdr *)skb->data;
			hdr->frame_control &=
					cpu_to_le16(~IEEE80211_FCTL_MOREDATA);
		}

		cl_tx_single(cl_hw, NULL, skb, false, true);
	}
}

void cl_tx_bcn_mesh_task(unsigned long data)
{
	struct cl_vif *cl_vif = (struct cl_vif *)data;
	struct cl_hw *cl_hw = cl_vif->cl_hw;
	struct ieee80211_tx_info *tx_info;
	struct sk_buff *skb;
	int mc_fw_free;

	if (!cl_hw || cl_radio_is_off(cl_hw) ||
	    cl_recovery_in_progress(cl_hw) ||
	    !test_bit(CL_DEV_STARTED, &cl_hw->drv_flags) ||
	    test_bit(CL_DEV_FW_ERROR, &cl_hw->drv_flags) ||
	    cl_hw->tx_disable_flags)
		return;

	skb = cl_tx_beacon_get(cl_hw->hw, cl_vif->vif);
	if (!skb)
		return;

	/* Route this BCN to the BCN ipc queue */
	tx_info = IEEE80211_SKB_CB(skb);
	tx_info->hw_queue = CL_HWQ_BCN;

	cl_tx_single(cl_hw, NULL, skb, false, true);

	mc_fw_free = cl_hw->tx_queues->bcmc.fw_free_space;
	cl_tx_mc(cl_vif, &mc_fw_free);
}

static void cl_tx_bcn(struct cl_vif *cl_vif)
{
	struct cl_hw *cl_hw = cl_vif->cl_hw;
	struct ieee80211_vif *vif = cl_vif->vif;
	struct ieee80211_tx_info *tx_info;
	struct sk_buff *skb;
	struct ieee80211_sub_if_data *sdata = NULL;

	if (!vif || vif->type != NL80211_IFTYPE_AP)
		return;

	sdata = vif_to_sdata(vif);
	if (IS_PCI_BUS_TYPE(cl_hw->chip)) {
		u8 vif_index = cl_vif->vif_index;
		struct cl_ipc_ring_indices_elem
			*indices_elem =	cl_hw->ipc_env->ring_indices_elem;
		sdata->u.ap.ps.dtim_count =
			(u8)__le32_to_cpu(indices_elem->indices->dtim_count[vif_index]);
	}

	skb = cl_tx_beacon_get(cl_hw->hw, vif);
	if (!skb)
		return;

	/* Route this BCN to the BCN ipc queue */
	tx_info = IEEE80211_SKB_CB(skb);
	tx_info->hw_queue = CL_HWQ_BCN;

	cl_tx_single(cl_hw, NULL, skb, false, true);
}

/* Cl_tx_bcns - generate BCNs and TX buffered MC frames each BCN DTIM interval
 *
 * Beacons are sent first followed by cyclic MC for fairness between VIF's
 * the FW buffer is restricted to "IPC_TXDESC_CNT_BCMC" buffer size.
 */
void cl_tx_bcns(struct cl_hw *cl_hw)
{
	struct cl_vif *cl_vif = NULL, *tmp;
	int mc_fw_free = 0;
	unsigned long tbtt_diff_msec = jiffies_to_msecs(jiffies - cl_hw->last_tbtt_irq);

	cl_hw->last_tbtt_irq = jiffies;
	cl_hw->tbtt_cnt++;

	/*
	 * Send beacon only if radio is on, there is at least one AP interface
	 * up, we aren't in the middle of recovery, and user didn't disable them.
	 */
	if (cl_radio_is_off(cl_hw) ||
	    cl_hw->vif_db.num_iface_bcn == 0 ||
	    cl_recovery_in_progress(cl_hw) ||
	    cl_hw->tx_db.block_bcn ||
	    cl_hw->tx_disable_flags ||
	    !test_bit(CL_DEV_STARTED, &cl_hw->drv_flags) ||
	    test_bit(CL_DEV_FW_ERROR, &cl_hw->drv_flags))
		return;

	if (cl_hw->iface_conf == CL_IFCONF_MESH_ONLY ||
	    (cl_hw->mesh_tbtt_div > 1 &&
	     ((cl_hw->tbtt_cnt % cl_hw->mesh_tbtt_div) == 0))) {
		tasklet_hi_schedule(&cl_hw->tx_mesh_bcn_task);
	} else if (IS_REAL_PHY(cl_hw->chip)) {
		/*
		 * More than 2 times the beacon interval passed between beacons - WARNING
		 * More than 3 times the beacon interval passed between beacons - ERROR
		 */
		if (tbtt_diff_msec > (cl_hw->conf->ha_beacon_int * 3))
			cl_dbg_err(cl_hw, "last_tbtt_irq=%lu, curr_time=%lu, diff=%lu\n",
				   cl_hw->last_tbtt_irq, jiffies, tbtt_diff_msec);
		else if (tbtt_diff_msec > (cl_hw->conf->ha_beacon_int * 2))
			cl_dbg_warn(cl_hw, "last_tbtt_irq=%lu, curr_time=%lu, diff=%lu\n",
				    cl_hw->last_tbtt_irq, jiffies, tbtt_diff_msec);
	}

	list_for_each_entry_safe(cl_vif, tmp, &cl_hw->vif_db.head, list)
		cl_tx_bcn(cl_vif);

	cl_vif = cl_hw->mc_vif;
	mc_fw_free = cl_hw->tx_queues->bcmc.fw_free_space;

	do {
		cl_tx_mc(cl_vif, &mc_fw_free);
		/* Cl_vif_get_next() is cyclic */
		cl_vif = cl_vif_get_next(cl_hw, cl_vif);
	} while ((cl_vif != cl_hw->mc_vif) && mc_fw_free);

	cl_hw->mc_vif = cl_vif_get_next(cl_hw, cl_hw->mc_vif);
}

void cl_tx_en(struct cl_hw *cl_hw, u8 reason, bool enable)
{
	unsigned long tx_disable_flags_prev = cl_hw->tx_disable_flags;

	if (enable) {
		clear_bit(reason, &cl_hw->tx_disable_flags);

		if (tx_disable_flags_prev != 0 && cl_hw->tx_disable_flags == 0)
			if (cl_hw->conf->ci_backup_bcn_en)
				cl_msg_tx_backup_bcn_en(cl_hw, true);
	} else {
		set_bit(reason, &cl_hw->tx_disable_flags);

		if (tx_disable_flags_prev == 0)
			if (cl_hw->conf->ci_backup_bcn_en)
				cl_msg_tx_backup_bcn_en(cl_hw, false);
	}
}

static void cl_tx_flush(struct cl_hw *cl_hw)
{
	unsigned long flags;

	/* Flush bcmc */
	spin_lock_irqsave(&cl_hw->tx_lock_bcmc, flags);
	cl_bcmc_cfm_flush_queue(cl_hw, NULL);
	spin_unlock_irqrestore(&cl_hw->tx_lock_bcmc, flags);

	/* Flush single */
	spin_lock_bh(&cl_hw->tx_lock_single);
	cl_txq_flush_all_single(cl_hw);
	cl_single_cfm_flush_all(cl_hw);
	spin_unlock_bh(&cl_hw->tx_lock_single);

	/* Flush agg */
	spin_lock_bh(&cl_hw->tx_lock_agg);
	cl_txq_flush_all_agg(cl_hw);
	cl_agg_cfm_flush_all(cl_hw);
	spin_unlock_bh(&cl_hw->tx_lock_agg);
}

void cl_tx_off(struct cl_hw *cl_hw)
{
	cl_txq_stop(cl_hw);
	cl_tx_flush(cl_hw);
}

static void cl_tx_set_mapping(struct cl_hw *cl_hw, struct sk_buff *skb, struct net_device *dev)
{
	struct cl_vif *cl_vif = NETDEV_TO_CL_VIF(dev);
	u8 vif_index = cl_vif->vif_index;
	u8 tid;

	if (!cl_hw->conf->ha_wmm_enabled[vif_index]) {
		skb->priority = 0;
		goto set_queue_mapping;
	}

	if (cl_vlan_dscp_is_enabled(cl_hw, cl_vif)) {
		skb->priority = cl_vlan_dscp_check_ether_type(cl_hw, skb, vif_index);
	} else {
		u8 dscp_to_up[TID_MAX] = {0, 8, 16, 24, 32, 40, 48, 56};
		u8 i = 0, dcsp_val = 0, *src_buf = NULL;
		u16 ether_type = (skb->data[12] << 8) | skb->data[13];

		/* Patch until IPv6 will be supported - set priority to 0 */
		if (ether_type != ETH_P_IP) {
			skb->priority = 0;
			goto set_queue_mapping;
		}

		src_buf = skb->data;
		src_buf += ETH_HLEN;
		dcsp_val = (*(src_buf + 1) & 0xec) >> 2;

		for (i = 0; i < TID_MAX; i++)
			if (dscp_to_up[i] == dcsp_val) {
				skb->priority = i;
				break;
			}
	}

set_queue_mapping:
	tid = skb->priority & IEEE80211_QOS_CTL_TAG1D_MASK;
	skb_set_queue_mapping(skb, ieee802_1d_to_ac[tid]);
}

static bool cl_tx_packet_limit(struct cl_hw *cl_hw, struct sk_buff *skb)
{
	if (cl_hw->conf->ci_tx_packet_limit > 0)
		return (atomic_read(&cl_hw->tx_packet_count) >= cl_hw->conf->ci_tx_packet_limit);

	return false;
}

static void cl_tx_destructor(struct sk_buff *skb)
{
	struct ieee80211_sub_if_data *sdata = IEEE80211_DEV_TO_SUB_IF(skb->dev);
	struct cl_hw *cl_hw = sdata->local->hw.priv;

	atomic_dec(&cl_hw->tx_packet_count);
}

void cl_tx_drop_skb(struct sk_buff *skb)
{
	skb->dev->stats.rx_dropped++;
	kfree_skb(skb);
}

static netdev_tx_t ____cl_tx_start(struct cl_hw *cl_hw, struct sk_buff *skb,
				   struct net_device *dev, struct cl_sta *cl_sta)
{
	struct ieee80211_sub_if_data *sdata = IEEE80211_DEV_TO_SUB_IF(dev);
	struct ieee80211_vif *vif = &sdata->vif;
	struct cl_vif *cl_vif = (struct cl_vif *)vif->drv_priv;
	struct ieee80211_tx_info *tx_info = NULL;
	int buffer_cnt = 0;
	u8 hw_queue = vif->hw_queue[skb_get_queue_mapping(skb)];

	cl_hw->tx_packet_cntr.forward.tx_start++;

	if (cl_hw->wd_restart_drv) {
		cl_hw->tx_packet_cntr.drop.wd_restart++;
		cl_vif->trfc_cntrs[hw_queue].tx_dropped++;
		cl_tx_drop_skb(skb);
		return NETDEV_TX_OK;
	}

	if (cl_radio_is_off(cl_hw)) {
		cl_hw->tx_packet_cntr.drop.radio_off++;
		cl_vif->trfc_cntrs[hw_queue].tx_dropped++;
		cl_tx_drop_skb(skb);
		return NETDEV_TX_OK;
	}

	if (cl_recovery_in_progress(cl_hw)) {
		cl_hw->tx_packet_cntr.drop.in_recovery++;
		cl_vif->trfc_cntrs[hw_queue].tx_dropped++;
		cl_tx_drop_skb(skb);
		return NETDEV_TX_OK;
	}

	if (skb->len < ETH_HLEN) {
		cl_hw->tx_packet_cntr.drop.short_length++;
		cl_vif->trfc_cntrs[hw_queue].tx_errors++;
		cl_tx_drop_skb(skb);
		return NETDEV_TX_OK;
	}

	skb = skb_unshare(skb, GFP_ATOMIC);
	if (!skb) {
		net_info_ratelimited("%s: failed to unshare skb ", __func__);
		return false;
	}

	if (skb_queue_len(&sdata->local->pending[hw_queue]) >=
	    cl_hw->conf->ci_pending_queue_size) {
		cl_hw->tx_packet_cntr.drop.pending_full++;
		cl_vif->trfc_cntrs[hw_queue].tx_dropped++;
		cl_tx_drop_skb(skb);
		tasklet_schedule(&sdata->local->tx_pending_tasklet);
		return NETDEV_TX_OK;
	}

	/* Limit total packets for TX */
	if (cl_tx_packet_limit(cl_hw, skb)) {
		cl_hw->tx_packet_cntr.drop.packet_limit++;
		cl_vif->trfc_cntrs[hw_queue].tx_dropped++;
		cl_tx_drop_skb(skb);
		return NETDEV_TX_OK;
	}

	if (!skb->destructor) {
		skb->destructor = cl_tx_destructor;
		buffer_cnt = atomic_inc_return(&cl_hw->tx_packet_count);
	}

	tx_info = IEEE80211_SKB_CB(skb);
	memset(tx_info, 0, sizeof(struct ieee80211_tx_info));

#ifdef TRACE_SUPPORT
	trace_cl_tracl_tx_start(cl_hw->idx, skb, buffer_cnt);
#endif

	if (vif->type == NL80211_IFTYPE_STATION ||
	    test_bit(CL_DEV_REPEATER, &cl_hw->drv_flags)) {
		u16 ethertype = (skb->data[12] << 8) | skb->data[13];

		if (ethertype == ETH_P_IP) {
			cl_cma_ip_tx(cl_vif, skb);
		} else if (ethertype == ETH_P_ARP) {
			cl_cma_table_maintenance(cl_hw);
			cl_cma_arp_tx(cl_vif, skb);
		}
	}

	if (cl_sta && cl_sta->stainfo &&
	    (test_sta_flag(cl_sta->stainfo, WLAN_STA_AUTHORIZED))) {
		u8 tid = skb->priority & IEEE80211_QOS_CTL_TAG1D_MASK;
		bool is_agg = cl_tx_check_agg(sdata, skb);

		cl_traffic_tx_handler(cl_hw, cl_sta, skb->len);
		cl_traffic_mon_tx(cl_sta, skb);

		if (!ieee80211_vif_is_mesh(&sdata->vif)) {
			/* Check if pings should be forced to be sent as single */
			if (cl_hw->conf->ci_force_icmp_single) {
				if (is_icmp_packet(skb)) {
					cl_tx_fast_single(cl_hw, cl_sta, skb, true);
					return NETDEV_TX_OK;
				}
			}
			if (is_agg && cl_sta->agg_tx_queues[tid])
				cl_tx_fast_agg(cl_hw, cl_sta, skb, true);
			else if (is_agg && cl_sta->baws[tid].action_start)
				__skb_queue_tail(&cl_sta->baws[tid].pending, skb);
			else if (cl_key_is_cipher_wep_or_wpa(cl_key_get(cl_sta)))
				goto mac80211;
			else
				cl_tx_fast_single(cl_hw, cl_sta, skb, true);

			return NETDEV_TX_OK;
		}
	}

mac80211:
	cl_hw->tx_packet_cntr.forward.to_mac++;
	cl_vif->orig_dev_ops->ndo_start_xmit(skb, dev);

	return NETDEV_TX_OK;
}

netdev_tx_t ___cl_tx_start(struct cl_hw *cl_hw, struct sk_buff *skb,
			   struct net_device *dev)
{
	struct ieee80211_sub_if_data *sdata = IEEE80211_DEV_TO_SUB_IF(dev);
	struct cl_sta *cl_sta;

	cl_sta_lock(cl_hw);

	if (sdata->vif.type == NL80211_IFTYPE_STATION)
		cl_sta = cl_sta_get_by_addr(cl_hw, sdata->u.mgd.bssid);
	else
		cl_sta = cl_sta_get_by_addr(cl_hw, skb->data);

	cl_sta_unlock(cl_hw);

	if (cl_sta && cl_sta->stop_tx) {
		kfree_skb(skb);
		cl_hw->tx_packet_cntr.drop.sta_stop_tx++;
	} else {
		return ____cl_tx_start(cl_hw, skb, dev, cl_sta);
	}

	return NETDEV_TX_OK;
}

netdev_tx_t __cl_tx_start(struct cl_hw *cl_hw, struct sk_buff *skb,
			  struct net_device *dev)
{
	skb->dev = dev;
	cl_tx_set_mapping(cl_hw, skb, dev);

	return ___cl_tx_start(cl_hw, skb, dev);
}

netdev_tx_t _cl_tx_start(struct cl_hw *cl_hw, struct sk_buff *skb, struct net_device *dev)
{
	if (!skb_mac_header_was_set(skb))
		skb_reset_mac_header(skb);

	/* Multicast --> Unicast */
	if (cl_hw->conf->ce_m2u_enable && cl_m2u_should_not_send_as_multicast(skb)) {
		cl_m2u_downlink_multicast_snooping(cl_hw, skb, dev);
		return NETDEV_TX_OK;
	}

	return __cl_tx_start(cl_hw, skb, dev);
}

netdev_tx_t cl_tx_start(struct sk_buff *skb, struct net_device *dev)
{
	struct ieee80211_sub_if_data *sdata = IEEE80211_DEV_TO_SUB_IF(dev);
	struct cl_hw *cl_hw = sdata->local->hw.priv;

	return _cl_tx_start(cl_hw, skb, dev);
}

static int cl_tx_cli_print_conf(struct cl_hw *cl_hw)
{
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;

	cl_snprintf(&buf, &len, &buf_size, "block_bcn = %s\n",
		    cl_hw->tx_db.block_bcn ? "true" : "false");
	cl_snprintf(&buf, &len, &buf_size, "block_prob_resp = %s\n",
		    cl_hw->tx_db.block_prob_resp ? "true" : "false");

	err = cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);

	return err;
}

static int cl_tx_cli_help(struct cl_hw *cl_hw)
{
	char *buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!buf)
		return -ENOMEM;

	snprintf(buf, PAGE_SIZE,
		 "tx usage:\n"
		 "-a : force amsdu [0/1]\n"
		 "-b : block beacons [0/1]\n"
		 "-c : print configuration\n"
		 "-p : block probe response [0/1]\n");

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

int cl_tx_cli(struct cl_hw *cl_hw, struct cli_params *cli_params)
{
	u32 expected_params = 0;
	bool force_amsdu = false;
	bool block_bcn = false;
	bool print_conf = false;
	bool block_prob_resp = false;

	switch (cli_params->option) {
	case 'a':
		force_amsdu = true;
		expected_params = 1;
		break;
	case 'b':
		block_bcn = true;
		expected_params = 1;
		break;
	case 'c':
		print_conf = true;
		expected_params = 0;
		break;
	case 'p':
		block_prob_resp = true;
		expected_params = 1;
		break;
	case '?':
		return cl_tx_cli_help(cl_hw);
	default:
		cl_dbg_err(cl_hw, "Illegal option (%c) - try '?' for help\n", cli_params->option);
		goto out_err;
	}

	if (expected_params != cli_params->num_params) {
		cl_dbg_err(cl_hw, "Wrong number of arguments (expected %u) (actual %u)\n",
			   expected_params, cli_params->num_params);
		goto out_err;
	}

	if (force_amsdu) {
		cl_hw->tx_db.force_amsdu = (bool)cli_params->params[0];
		pr_debug("force_amsdu = %s\n", cl_hw->tx_db.force_amsdu ? "true" : "false");
		return 0;
	}

	if (block_bcn) {
		cl_hw->tx_db.block_bcn = (bool)cli_params->params[0];
		pr_debug("block_bcn = %s\n", cl_hw->tx_db.block_bcn ? "true" : "false");

		if (cl_hw->conf->ci_backup_bcn_en) {
			if (cl_hw->tx_db.block_bcn) {
				if (cl_hw->tx_disable_flags == 0)
					cl_msg_tx_backup_bcn_en(cl_hw, false);
			} else {
				cl_msg_tx_backup_bcn_en(cl_hw, true);
			}
		}

		return 0;
	}

	if (print_conf)
		return cl_tx_cli_print_conf(cl_hw);

	if (block_prob_resp) {
		cl_hw->tx_db.block_prob_resp = (bool)cli_params->params[0];
		pr_debug("block_prob_resp = %s\n",
			 cl_hw->tx_db.block_prob_resp ? "true" : "false");
		return 0;
	}

out_err:
	return -EIO;
}


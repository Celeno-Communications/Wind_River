// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include <linux/module.h>
#include "chip.h"
#include "cl_usb.h"
#include "cl_tx_usb.h"
#include "cl_tx.h"
#include "cl_single_cfm.h"

static void cl_tx_usb_submit_skb_complete(struct urb *urb)
{
	kfree(urb->sg);
	kfree(urb->transfer_buffer);
	usb_free_urb(urb);
}

static void ep_last_packet_chunks_init(struct cl_usb_endpoint *ep)
{
	ep->last_packet_chunks = 0;
	ep->last_packet_size = 0;
}

static void ep_last_packet_chunks_update(struct cl_usb_endpoint *ep, int added_size)
{
	int new_size = ep->last_packet_size + added_size;

	if (new_size == ep->max_packet_size) {
		ep->last_packet_chunks = 0;
		ep->last_packet_size = 0;
	} else if (new_size > ep->max_packet_size) {
		ep->last_packet_chunks = 1;
		ep->last_packet_size = new_size & (ep->max_packet_size - 1);
	} else {
		ep->last_packet_chunks++;
		ep->last_packet_size += added_size;
	}
}

static struct urb *cl_tx_usb_urb_alloc(struct cl_hw *cl_hw,
				       struct cl_usb_endpoint *ep)
{
	struct cl_chip *chip = cl_hw->chip;
	struct cl_chip_usb *chip_usb = cl_chip_usb_priv(chip);
	struct urb *urb = usb_alloc_urb(0, GFP_ATOMIC);

	if (!urb) {
		cl_dbg_err(cl_hw, "urb alloc failed\n");
		return NULL;
	}

	if (chip_usb->sg_en) {
		urb->sg = kcalloc(chip_usb->umac_ds_aggr_count[ep->lli_channel],
				  sizeof(struct scatterlist), GFP_ATOMIC);
		if (!urb->sg)
			goto err;
	} else {
		urb->transfer_buffer = kzalloc(CL_USB_BUF_SIZE *
					       chip_usb->umac_ds_aggr_count[ep->lli_channel],
					       GFP_ATOMIC);
		if (!urb->transfer_buffer)
			goto err;
	}

	ep_last_packet_chunks_init(ep);

	return urb;

 err:
	usb_free_urb(urb);

	return NULL;
}

static bool cl_tx_usb_is_buffered_mode(struct cl_chip *chip, u8 lli_channel)
{
	return (chip->conf->ci_tx_usb_mode[lli_channel] ==
		USB_TX_MODE_BUFFERED ||
		chip->conf->ci_tx_usb_mode[lli_channel] ==
		USB_TX_MODE_BUFFERED_TCI_SPLIT ||
		chip->conf->ci_tx_usb_mode[lli_channel] ==
		USB_TX_MODE_BUFFERED_TCI_ETH_NONSTD);
}

static int cl_tx_usb_finalize_urb(struct cl_hw *cl_hw,
				  struct urb *urb,
				  struct cl_usb_endpoint *ep,
				  int total_len,
				  u8 num_sgs)
{
	struct cl_chip *chip = cl_hw->chip;
	struct cl_chip_usb *chip_usb = cl_chip_usb_priv(chip);
	int err = 0;

	if (cl_tx_usb_is_buffered_mode(chip, ep->lli_channel))
		urb->transfer_flags |= URB_ZERO_PACKET;

	urb->transfer_buffer_length = total_len;
	if (chip_usb->sg_en) {
		urb->num_sgs = num_sgs;
		sg_init_marker(urb->sg, urb->num_sgs);
	}

	cl_usb_fill_bulk_urb(chip, urb, ep, NULL,
			     cl_tx_usb_submit_skb_complete);
	usb_anchor_urb(urb, &ep->submitted);
	err = usb_submit_urb(urb, GFP_ATOMIC);
	if (err)
		cl_dbg_verbose(cl_hw, "usb_submit_urb failed\n");

	return err;
}

static bool cl_tx_usb_bitmap_en(int loop_cnt, __le32 *bitmap_arr)
{
	u8 bitmap_idx = loop_cnt / 32;
	u8 bit_index = loop_cnt % 32;
	u32 bitmap = le32_to_cpu(bitmap_arr[bitmap_idx]);

	if ((bitmap >> bit_index) & 0x1)
		return true;

	return false;
}

static u8 *cl_tx_usb_get_cpu_addr(struct cl_hw *cl_hw,
				  struct cl_sw_txhdr *sw_txhdr, int idx)
{
	struct cl_amsdu_txhdr *amsdu_txhdr = NULL, *tmp = NULL;
	int i = 1;

	if (idx == 0)
		return sw_txhdr->skb->data;

	/* AMSDU Case */
	list_for_each_entry_safe(amsdu_txhdr, tmp, &sw_txhdr->amsdu_txhdr.list, list) {
		if (i == idx)
			return amsdu_txhdr->skb->data;
		i++;
	}

	cl_dbg_err(cl_hw, "no AMSDU for idx %d !!!\n", idx);

	return NULL;
}

static void cl_tx_req_error_prints(struct cl_hw *cl_hw, __le32 *bitmap, u8 txdesc_cnt,
				   u16 msdu_cnt, u8 submitted_desc, u16 submitted_msdu)
{
	int i;

	cl_dbg_err(cl_hw, "Error req mismatch !!!\n");
	cl_dbg_err(cl_hw, "txdesc req_cnt %d submit cnt %d\n", txdesc_cnt, submitted_desc);
	cl_dbg_err(cl_hw, "MSDU req_cnt %d submit cnt %d txdesc cnt %d\n",
		   msdu_cnt, submitted_msdu, txdesc_cnt);

	if (!bitmap)
		return;

	for (i = 0; i < CL_USB_AGG_PKT_REQ_BITMAP_SIZE; i++) {
		u32 bitmap_u32 = le32_to_cpu(bitmap[i]);

		cl_dbg_err(cl_hw, "bitmap[%d] 0x%x:\n", i, bitmap_u32);
	}
}

static struct cl_sw_txhdr *cl_sw_txhdr_next_sn_get(struct cl_hw *cl_hw,
						   u16 next_valid_sn, u16 requested_ssn,
						   struct cl_sw_txhdr *first_sw_txhdr)
{
	int i = 0;
	struct cl_sw_txhdr *sw_txhdr = first_sw_txhdr;

	while (sw_txhdr) {
		u16 sn = le16_to_cpu(sw_txhdr->txdesc.e2w_txhdr_param.seq_ctrl);

		if (next_valid_sn == IEEE80211_SEQ_TO_SN(sn))
			return sw_txhdr;

		sw_txhdr = list_next_entry(sw_txhdr, cfm_list);
		i++;
		if (i > TXDESC_AGG_Q_SIZE_USB) {
			cl_dbg_err(cl_hw, "Error!! did not find SN %d requested %d !!!\n",
				   next_valid_sn, requested_ssn);
			return NULL;
		}
	}

	return NULL;
}

static int cl_tx_usb_submit(struct cl_hw *cl_hw, struct cl_sw_txhdr *sw_txhdr,
			    u8 txdesc_cnt, struct cl_usb_endpoint *ep,
			    __le32 *bitmap, u32 msdu_cnt, u16 requested_ssn)
{
	struct cl_chip *chip = cl_hw->chip;
	struct cl_chip_usb *chip_usb = cl_chip_usb_priv(chip);
	struct urb *urb = NULL;
	u8 packet_cnt;
	u16 packet_len;
	u8 pad;
	u8 *cpu_addr;
	u8 *buf = NULL;
	int loop_cnt = 0;
	u8 submitted_skb = 0;
	u8 submitted_desc = 0;
	int total_len = 0;
	int i = 0;
	int ret = 0;
	u16 submitted_msdu = 0;
	u16 next_valid_sn;

	for (loop_cnt = 0; loop_cnt < TXDESC_AGG_Q_SIZE_USB; loop_cnt++) {
		if (bitmap && !cl_tx_usb_bitmap_en(loop_cnt, bitmap)) {
			continue;
		}

		if (bitmap) {
			next_valid_sn = (requested_ssn + loop_cnt) & IEEE80211_SN_MASK;
			sw_txhdr = cl_sw_txhdr_next_sn_get(cl_hw, next_valid_sn, requested_ssn,
							   sw_txhdr);

			if (!sw_txhdr) {
				cl_tx_req_error_prints(cl_hw, bitmap, txdesc_cnt, msdu_cnt,
						       submitted_desc, submitted_msdu);
				return -ENOMEM;
			}
		}

		packet_cnt = sw_txhdr->txdesc.host_info.packet_cnt;
		for (i = 0; i < packet_cnt; i++) {
			pad = 0;
			packet_len = le16_to_cpu(sw_txhdr->txdesc.umacdesc.agg_info.packet_len[i]);
			cpu_addr = cl_tx_usb_get_cpu_addr(cl_hw, sw_txhdr, i);

			if (sw_txhdr->txdesc.host_info.host_padding & BIT(i)) {
				pad = 2;
				/* Move CPU address to keep alignment & improve performance */
				cpu_addr -= pad;
			}

			pad += CL_USB_ALIGN_PADS(packet_len + pad);
			packet_len += pad;

			if (chip->conf->ci_tx_usb_mode[ep->lli_channel] ==
			    USB_TX_MODE_PAD_PDMAS) {
				u16 tail_pad_size = 0;
				u16 rem_len = packet_len % ep->max_packet_size;

				if (rem_len)
					tail_pad_size = (ep->max_packet_size -
							 rem_len);
				if (tail_pad_size &&
				    pskb_expand_head(sw_txhdr->skb, 0,
						     tail_pad_size,
						     GFP_ATOMIC))
					return -ENOMEM;

				packet_len += tail_pad_size;
			}

			if (!urb) {
				urb = cl_tx_usb_urb_alloc(cl_hw, ep);
				if (!urb)
					return -ENOMEM;
				if (!chip_usb->sg_en)
					buf = urb->transfer_buffer;
			}

			if (chip_usb->sg_en)
				sg_set_buf(&urb->sg[submitted_skb], cpu_addr, packet_len);
			else
				memcpy(&buf[total_len], cpu_addr, packet_len);
			total_len += packet_len;
			submitted_skb++;
			submitted_msdu++;

			if (chip->conf->ci_tx_usb_mode[ep->lli_channel] ==
			    USB_TX_MODE_NO_XFER_SPLIT) {
				ep_last_packet_chunks_update(ep, packet_len);
				if (ep->last_packet_chunks >= ep->max_chain_size) {
					ret = cl_tx_usb_finalize_urb(cl_hw, urb, ep,
								     total_len, submitted_skb);
					submitted_skb = 0;
					total_len = 0;
					urb = NULL;
				}
			}

			if (urb &&
			    submitted_skb ==
			    chip_usb->umac_ds_aggr_count[ep->lli_channel]) {
				ret = cl_tx_usb_finalize_urb(cl_hw, urb, ep,
							     total_len, submitted_skb);
				submitted_skb = 0;
				total_len = 0;
				urb = NULL;
			}
		}

		submitted_desc++;
		if (submitted_desc == txdesc_cnt) {

			if (msdu_cnt != submitted_msdu) {
				cl_tx_req_error_prints(cl_hw, bitmap, txdesc_cnt, msdu_cnt,
						       submitted_desc, submitted_msdu);
			}

			if (urb)
				return cl_tx_usb_finalize_urb(cl_hw, urb, ep,
						      total_len, submitted_skb);

			return ret;
		}
		sw_txhdr = list_next_entry(sw_txhdr, cfm_list);
	}

	if (submitted_desc != txdesc_cnt ||
	    msdu_cnt != submitted_msdu)  {
		cl_tx_req_error_prints(cl_hw, bitmap, txdesc_cnt, msdu_cnt,
				       submitted_desc, submitted_msdu);
	}

	return ret;
}

int cl_tx_usb_single_packets_send(struct cl_hw *cl_hw, u8 num_packets,
				  u8 ep_idx, u16 queue_idx,
				  u32 first_dma_addr)
{
	struct cl_chip *chip = cl_hw->chip;
	struct cl_chip_usb *chip_usb = cl_chip_usb_priv(chip);
	struct cl_sw_txhdr *sw_txhdr = NULL;
	struct cl_sw_txhdr *tmp = NULL;
	struct cl_usb_endpoint *ep = &chip_usb->eps[ep_idx];
	struct cl_single_cfm_queue *cfm_queue;
	int ret = 0;
	u32 dma_addr;

	if (!ep->address) {
		cl_dbg_err(cl_hw, "empty EP %d\n", ep_idx);
		return -EINVAL;
	}

	if (queue_idx == MAX_SINGLE_QUEUES) {
		cfm_queue = &cl_hw->bcmc_cfm_queue;
		spin_lock(&cl_hw->tx_lock_bcmc);
	} else {
		cfm_queue = &cl_hw->single_cfm_queues[queue_idx];
		spin_lock(&cl_hw->tx_lock_single);
	}

	list_for_each_entry_safe(sw_txhdr, tmp, &cfm_queue->head, cfm_list) {
		dma_addr = le32_to_cpu(sw_txhdr->txdesc.umacdesc.sngl_info.packet_addr);

		if (dma_addr == first_dma_addr)
			break;
	}

	ret = cl_tx_usb_submit(cl_hw, sw_txhdr, num_packets, ep, NULL, 1, 0);

	if (queue_idx == MAX_SINGLE_QUEUES)
		spin_unlock(&cl_hw->tx_lock_bcmc);
	else
		spin_unlock(&cl_hw->tx_lock_single);

	return ret;
}

static int cl_tx_usb_agg_packets_send(struct cl_hw *cl_hw, struct cl_usb_agg_pkt_req_msg *msg)
{
	struct cl_chip *chip = cl_hw->chip;
	struct cl_chip_usb *chip_usb = cl_chip_usb_priv(chip);
	struct cl_sw_txhdr *sw_txhdr;
	struct cl_agg_cfm_queue *cfm_queue = NULL;
	u8 ep_idx = msg->ep_idx;
	struct cl_usb_endpoint *ep = &chip_usb->eps[ep_idx];
	int ret = 0;
	u8 session_idx = msg->session_idx;

	if (!ep->address) {
		cl_dbg_err(cl_hw, "empty EP %d\n", ep_idx);
		return -EINVAL;
	}

	if (session_idx >= IPC_MAX_BA_SESSIONS) {
		cl_dbg_err(cl_hw, "corrupted session_idx %d\n", session_idx);
		return -EINVAL;
	}

	cfm_queue = &cl_hw->agg_cfm_queues[session_idx];
	if (list_empty(&cfm_queue->head))
		return -EINVAL;

	spin_lock(&cl_hw->tx_lock_cfm_agg);

	sw_txhdr = list_first_entry(&cfm_queue->head, struct cl_sw_txhdr, cfm_list);
	ret = cl_tx_usb_submit(cl_hw, sw_txhdr, msg->txdesc_cnt, ep, msg->bitmap,
			       msg->msdu_cnt, msg->start_sn);

	spin_unlock(&cl_hw->tx_lock_cfm_agg);

	return ret;
}

void cl_tx_usb_single_cfm_tasklet(unsigned long data)
{
	struct cl_hw *cl_hw = (struct cl_hw *)data;
	struct cl_ipc_cfm_msg *msg = NULL;

	msg = (struct cl_ipc_cfm_msg *)(cl_hw->single_cfm_virt_base_addr) +
		(cl_hw->single_cfm_read_idx % IPC_CFM_CNT);

	while (cl_hw->single_cfm_read_idx != cl_hw->single_cfm_write_idx) {
		if (unlikely(!msg->dma_addr)) {
			cl_dbg_err(cl_hw,
				   "dma_addr is 0 read_idx=%d write_idx=%d\n",
				   cl_hw->single_cfm_read_idx,
				   cl_hw->single_cfm_write_idx);
			return;
		}

		cl_single_cfm_handler(cl_hw,
				      le32_to_cpu(msg->status),
				      le32_to_cpu(msg->dma_addr),
				      le32_to_cpu(msg->single_queue_idx));
		msg->dma_addr = 0;
		cl_hw->single_cfm_read_idx++;
		msg = (struct cl_ipc_cfm_msg *)(cl_hw->single_cfm_virt_base_addr) +
			(cl_hw->single_cfm_read_idx % IPC_CFM_CNT);
	}
}

static struct cl_single_pkt_req_msg *
cl_single_req_msg_get_first(struct cl_hw *cl_hw)
{
	struct cl_single_pkt_req_msg *msg;
	unsigned long flags;

	spin_lock_irqsave(&cl_hw->single_pkt_req_msg_lock, flags);
	msg = list_first_entry_or_null(&cl_hw->single_pkt_req_msg_head,
				       struct cl_single_pkt_req_msg, list);

	if (msg)
		list_del(&msg->list);

	spin_unlock_irqrestore(&cl_hw->single_pkt_req_msg_lock, flags);

	return msg;
}

void cl_tx_usb_single_pkt_req_tasklet(unsigned long data)
{
	struct cl_hw *cl_hw = (struct cl_hw *)data;
	struct cl_single_pkt_req_msg *msg;

	while ((msg = cl_single_req_msg_get_first(cl_hw))) {
		u32 first_dma_addr = le32_to_cpu(msg->msg.first_txdesc_packet_addr);

		cl_tx_usb_single_packets_send(cl_hw, msg->msg.num_packets,
					      msg->msg.ep_idx,
					      msg->msg.single_queue_idx,
					      first_dma_addr);
		kfree(msg);
	}
}

static struct cl_agg_pkt_req_msg *
cl_agg_req_msg_get_first(struct cl_hw *cl_hw)
{
	struct cl_agg_pkt_req_msg *msg;
	unsigned long flags;

	spin_lock_irqsave(&cl_hw->agg_pkt_req_msg_lock, flags);
	msg = list_first_entry_or_null(&cl_hw->agg_pkt_req_msg_head,
				       struct cl_agg_pkt_req_msg, list);

	if (msg)
		list_del(&msg->list);

	spin_unlock_irqrestore(&cl_hw->agg_pkt_req_msg_lock, flags);

	return msg;
}

void cl_tx_usb_agg_pkt_req_tasklet(unsigned long data)
{
	struct cl_hw *cl_hw = (struct cl_hw *)data;
	struct cl_agg_pkt_req_msg *msg;

	while ((msg = cl_agg_req_msg_get_first(cl_hw))) {
		cl_tx_usb_agg_packets_send(cl_hw, &msg->msg);
		kfree(msg);
	}
}


// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "chip.h"
#include "cl_usb.h"
#include "cl_rx.h"
#include "cl_rx_usb.h"

static int cl_rx_usb_build_sgs(struct cl_hw *cl_hw,
			       struct cl_rx_usb_elem *elem)
{
	u8 num_sgs = USB_RX_CONT_MAX;
	struct sk_buff *skb = NULL;
	int i = 0;
	struct urb *urb = elem->urb;

	if (urb->sg)
		goto skb_alloc;

	urb->sg = kcalloc(num_sgs, sizeof(struct scatterlist), GFP_KERNEL);
	if (!urb->sg) {
		cl_dbg_verbose(cl_hw, "urb->sg alloc failed\n");
		return -ENOMEM;
	}
	urb->num_sgs = num_sgs;
	sg_init_table(urb->sg, num_sgs);
	urb->transfer_buffer_length = (num_sgs * CL_USB_BUF_SIZE);
skb_alloc:
	for (i = 0; i < num_sgs; i++) {
		// already assigned - reuse
		if (elem->submitted_skb_arr[i])
			continue;

		skb = dev_alloc_skb(CL_USB_BUF_SIZE +
				    sizeof(struct hw_rxhdr));
		if (unlikely(!skb)) {
			cl_dbg_verbose(cl_hw, "skb alloc failed\n");
			kfree(urb->sg);
			return -ENOMEM;
		}
		skb_reserve(skb, sizeof(struct hw_rxhdr));
		elem->submitted_skb_arr[i] = skb;
		sg_set_buf(&urb->sg[i], skb->data, CL_USB_BUF_SIZE);
	}

	return 0;
}

static u8 cl_rx_usb_get_meta_desc_num(u8 *data)
{
	return (u8)(*(data + CL_USB_BUF_SIZE - sizeof(u32)));
}

static struct cl_rx_usb_metadata_desc *cl_rx_usb_get_meta_desc(u8 *data,
							       u8 idx)
{
	return (struct cl_rx_usb_metadata_desc *)(data + CL_USB_BUF_SIZE -
		sizeof(u32) - ((idx + 1) *
		sizeof(struct cl_rx_usb_metadata_desc)));
}

static u8 cl_rx_usb_get_first_skb_idx(struct cl_rx_usb_sorted_pdma_elem *pdmas,
				      u8 rxv_idx)
{
	u8 ret_idx = rxv_idx - 1;

	while (pdmas[ret_idx].ptr)
		ret_idx--;

	/* Return the non NULL index */
	return ret_idx + 1;
}

static void cl_rx_usb_process_sorted_pdmas(struct cl_hw *cl_hw,
					   struct cl_usb_endpoint *ep,
					   u8 idx)
{
	struct cl_rx_usb_sorted_pdma_elem *pdmas = ep->pdmas;
	struct hw_rxhdr *rxhdr = (struct hw_rxhdr *)pdmas[idx].ptr;
	struct sk_buff_head frames;
	struct sk_buff *skb;
	struct sk_buff *first_skb = NULL;
	u8 first_skb_idx;
	u16 first_skb_size;
	enum rx_buf_type type = CL_RX_BUF_RXM;
	u8 i = 0;

	__skb_queue_head_init(&frames);

	if (ep->address == CL_USB_EP_ADDR_RX_DATA_IN)
		type = CL_RX_BUF_FW;

	first_skb_idx = cl_rx_usb_get_first_skb_idx(pdmas, idx);
	first_skb = (struct sk_buff *)pdmas[first_skb_idx].ptr;
	for (i = first_skb_idx; i != idx; i++) {
		skb = (struct sk_buff *)pdmas[i].ptr;
		if (unlikely(!skb)) {
			cl_dbg_verbose(cl_hw, "skb is NULL i=%d!!!\n", i);
			return;
		}

		cl_hw->rx_info.msdu_split_cnt[pdmas[i].msdu_split]++;
		if (pdmas[i].msdu_split) {
			if (pdmas[i].msdu_split == MSDU_FIRST_PART)
				continue;
			if (!first_skb) {
				first_skb_idx = cl_rx_usb_get_first_skb_idx(pdmas, idx);
				first_skb = (struct sk_buff *)pdmas[first_skb_idx].ptr;
			}
			first_skb_size = pdmas[first_skb_idx].size;
			memcpy(first_skb->data + first_skb_size,
			       skb->data, pdmas[i].size);
			pdmas[first_skb_idx].size += pdmas[i].size;
			kfree_skb(skb);
			skb = NULL;
			if (pdmas[i].msdu_split == MSDU_LAST_PART) {
				skb = first_skb;
				pdmas[first_skb_idx].ptr = NULL;
			}
		}

		pdmas[i].ptr = NULL;
		if (skb) {
			first_skb = NULL;
			__skb_queue_tail(&frames, skb);
		}
	}

	skb = __skb_peek(&frames);
	skb->data -= sizeof(struct hw_rxhdr);
	memcpy(skb->data, rxhdr, sizeof(struct hw_rxhdr));
	pdmas[idx].ptr = NULL;
	cl_hw->rx_info.rx_desc[type] += skb_queue_len(&frames);
	skb_queue_splice_tail_init(&frames, &cl_hw->rx_skb_queue);
	tasklet_schedule(&cl_hw->rx_tasklet);
}

static bool cl_rx_usb_process_meta_desc(struct cl_hw *cl_hw,
					struct cl_usb_endpoint *ep,
					struct sk_buff *skb,
					u8 **ptr, u8 md_idx)
{
	struct cl_rx_usb_metadata_desc *meta_desc = NULL;
	struct cl_rx_usb_sorted_pdma_elem *pdmas = ep->pdmas;
	struct sk_buff *new_skb;
	u8 idx = 0;
	u16 size = 0;

	meta_desc = cl_rx_usb_get_meta_desc(skb->data, md_idx);
	idx = meta_desc->index;
	size = meta_desc->size;
	if (unlikely(pdmas[idx].ptr)) {
		cl_dbg_verbose(cl_hw, "pdma[%d].ptr is not NULL !!!\n", idx);
		return true;
	}

	if (meta_desc->copy_policy == SINGLE_PACKET) {
		if (meta_desc->type == DATA_PACKET) {
			pdmas[idx].ptr = skb;
			pdmas[idx].type = DATA_PACKET;
			pdmas[idx].msdu_split = meta_desc->msdu_split;
			pdmas[idx].size = size;
		}

		return false;
	}

	if (meta_desc->copy_policy == MULTI_PACKET) {
		if (meta_desc->type == DATA_PACKET) {
			new_skb = dev_alloc_skb(CL_USB_BUF_SIZE +
						sizeof(struct hw_rxhdr));
			if (unlikely(!new_skb)) {
				cl_dbg_verbose(cl_hw, "new_skb alloc failed\n");
				return false;
			}
			skb_reserve(new_skb, sizeof(struct hw_rxhdr));
			memcpy(new_skb->data, *ptr, size);
			pdmas[idx].ptr = new_skb;
			pdmas[idx].type = DATA_PACKET;
			pdmas[idx].msdu_split = meta_desc->msdu_split;
			pdmas[idx].size = size;
			*ptr += size;
		} else if (meta_desc->type == RXV) {
			pdmas[idx].ptr = *ptr;
			pdmas[idx].type = RXV;
			*ptr += size;
			cl_rx_usb_process_sorted_pdmas(cl_hw, ep, idx);
		}

		return true;
	}

	return false;
}

static void cl_rx_usb_process_md(struct cl_hw *cl_hw,
				 struct cl_rx_usb_elem *elem,
				 struct sk_buff *skb)
{
	u8 meta_desc_num = cl_rx_usb_get_meta_desc_num(skb->data);
	u8 *ptr = skb->data;
	u8 md_idx = 0;
	bool is_multi = false;

	for (md_idx = 0; md_idx < meta_desc_num; md_idx++)
		is_multi = cl_rx_usb_process_meta_desc(cl_hw, elem->ep, skb,
						       &ptr, md_idx);
	/* Free the multi-packet SKB */
	if (is_multi)
		kfree_skb(skb);
}

static void cl_rx_usb_process_sgs(struct cl_hw *cl_hw,
				  struct cl_rx_usb_elem *elem)
{
	struct urb *urb = elem->urb;
	struct sk_buff *skb = NULL;
	u8 sg_idx = 0;
	u8 used_sg_num = (urb->actual_length / CL_USB_BUF_SIZE);

	for (sg_idx = 0; sg_idx < used_sg_num; sg_idx++) {
		skb = elem->submitted_skb_arr[sg_idx];
		if (unlikely(!skb)) {
			cl_dbg_verbose(cl_hw, "submitted_skb_arr[%d] NULL\n",
				       sg_idx);
			return;
		}

		cl_rx_usb_process_md(cl_hw, elem, skb);
		elem->submitted_skb_arr[sg_idx] = NULL;
	}
}

static void cl_rx_usb_process_single_buf(struct cl_hw *cl_hw,
					 struct cl_rx_usb_elem *elem)
{
	struct urb *urb = elem->urb;
	u8 *buf = urb->transfer_buffer;
	u8 buffers_num = (urb->actual_length / CL_USB_BUF_SIZE);
	u8 buf_idx = 0;
	u8 *data = buf;
	struct sk_buff *skb = NULL;

	if (!buf) {
		cl_dbg_err(cl_hw, "buf is NULL\n");
		return;
	}

	for (buf_idx = 0; buf_idx < buffers_num; buf_idx++) {
		skb = dev_alloc_skb(CL_USB_BUF_SIZE +
				    sizeof(struct hw_rxhdr));
		if (unlikely(!skb)) {
			cl_dbg_verbose(cl_hw, "skb alloc failed\n");
			return;
		}
		skb_reserve(skb, sizeof(struct hw_rxhdr));
		memcpy(skb->data, data, CL_USB_BUF_SIZE);
		cl_rx_usb_process_md(cl_hw, elem, skb);
		data += CL_USB_BUF_SIZE;
	}
}

static void cl_rx_usb_free_sgs(struct urb *urb)
{
	int i;
	struct cl_rx_usb_elem *elem = (struct cl_rx_usb_elem *)urb->context;

	for (i = 0; i < USB_RX_CONT_MAX; i++)
		kfree_skb(elem->submitted_skb_arr[i]);

	kfree(urb->sg);
}

static void cl_rx_usb_free_pdmas(struct cl_rx_usb_sorted_pdma_elem *pdmas)
{
	int i = 0;

	for (i = 0; i < CL_RX_USB_MAX_PDMA_INDEX; i++)
		kfree_skb(pdmas[i].ptr);
}

static void cl_rx_usb_urb_dealloc(struct cl_hw *cl_hw,
				  struct cl_rx_usb_elem *elem)
{
	struct urb *urb = elem->urb;
	struct cl_chip *chip = cl_hw->chip;
	struct cl_chip_usb *chip_usb = cl_chip_usb_priv(chip);

	if (chip_usb->sg_en) {
		cl_rx_usb_free_sgs(urb);
	} else {
		if (urb->transfer_buffer)
			chip_ops_free_coherent(chip,
					       urb->transfer_buffer_length,
					       urb->transfer_buffer,
					       elem->dma_addr);
	}

	usb_free_urb(urb);
}

void cl_rx_usb_rx_data_complete(struct urb *urb)
{
	struct cl_rx_usb_elem *elem = (struct cl_rx_usb_elem *)urb->context;
	struct cl_hw *cl_hw = elem->cl_hw;
	struct cl_chip *chip = cl_hw->chip;
	struct cl_chip_usb *chip_usb = cl_chip_usb_priv(chip);

	if (urb->status == -ESHUTDOWN ||
	    urb->status == -ENOENT ||
	    urb->status == -EPROTO ||
	    urb->status == -ECONNRESET) {
		cl_rx_usb_urb_dealloc(cl_hw, elem);
		cl_rx_usb_elem_dealloc(elem);
		return;
	}

	if (chip_usb->sg_en && urb->sg)
		cl_rx_usb_process_sgs(cl_hw, elem);
	else
		cl_rx_usb_process_single_buf(cl_hw, elem);

	if (!cl_rx_usb_urb_build(cl_hw, elem))
		cl_usb_urb_submit(cl_hw, (struct cl_usb_elem *)elem,
				  cl_rx_usb_rx_data_complete);
}

void cl_rx_usb_elem_dealloc(struct cl_rx_usb_elem *elem)
{
	struct cl_usb_endpoint *ep = elem->ep;

	if (ep->pdmas) {
		cl_rx_usb_free_pdmas(ep->pdmas);
		kfree(ep->pdmas);
		ep->pdmas = NULL;
	}
	kfree(elem);
}

struct cl_rx_usb_elem *cl_rx_usb_elem_urb_alloc(struct cl_hw *cl_hw)
{
	struct cl_rx_usb_elem *elem = kzalloc(sizeof(*elem), GFP_KERNEL);
	struct urb *urb = NULL;

	if (!elem)
		return NULL;

	urb = usb_alloc_urb(0, GFP_KERNEL);
	if (!urb)
		goto fail;

	elem->cl_hw = cl_hw;
	elem->urb = urb;

	return elem;
 fail:
	kfree(elem);

	return NULL;
}

int cl_rx_usb_urb_build(struct cl_hw *cl_hw, struct cl_rx_usb_elem *elem)
{
	struct cl_chip *chip = cl_hw->chip;
	struct cl_chip_usb *chip_usb = cl_chip_usb_priv(chip);

	if (chip_usb->sg_en) {
		if (cl_rx_usb_build_sgs(cl_hw, elem))
			return -ENOMEM;
	} else {
		u8 *buf = NULL;
		struct urb *urb = elem->urb;
		u32 buf_size = elem->container_num * CL_USB_BUF_SIZE;

		if (urb->transfer_buffer) {
			memset(urb->transfer_buffer, 0, buf_size);
			return 0;
		}

		buf = chip_ops_alloc_coherent(cl_hw->chip, buf_size,
					      GFP_ATOMIC, &elem->dma_addr);

		if (!buf) {
			cl_dbg_verbose(cl_hw,
				       "chip_ops_alloc_coherent failed\n");
			return -ENOMEM;
		}

		memset(buf, 0, buf_size);

		urb->transfer_buffer_length = buf_size;
		urb->transfer_buffer = buf;
		urb->transfer_dma = elem->dma_addr;
		urb->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;
	}

	return 0;
}


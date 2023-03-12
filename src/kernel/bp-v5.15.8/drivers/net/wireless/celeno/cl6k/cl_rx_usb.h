/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_RX_USB_H
#define CL_RX_USB_H

#include <linux/usb.h>
#include "cl_usb.h"

/*
 * 1500[eth max] - 12[hdr frame] + 14[msdu frame] + 8[llc snap] + 4[MSDU Padding] = 1514
 * MSDU + WLAN HDR = 1514[MSDU MAX] + 36[MAX WLAN HDR] = 1550
 * 32 bytes is being PADDED by SKB alloc for alignment.
 * 18 byte encryption
 */
#define CL_RX_USB_MAX_PDMA_INDEX 256

enum cl_rx_usb_copy_policy {
	SINGLE_PACKET = 0,
	MULTI_PACKET = 1
};

enum cl_rx_usb_packet_type {
	DATA_PACKET = 0,
	RXV = 1
};

struct cl_rx_usb_metadata_desc {
#ifdef __LITTLE_ENDIAN_BITFIELD
	u32 size          : 16, /* [15:0]  */
	    index         : 8,  /* [23:16] */
	    copy_policy   : 2,  /* [25:24] */
	    type          : 1,  /* [26]    */
	    amsdu_present : 2,  /* [28:27] */
	    msdu_split    : 2,  /* [30:29] */
	    rsv           : 1;  /* [31]    */
#else /* __BIG_ENDIAN_BITFIELD */
	u32 rsv           : 1,  /* [0]     */
	    msdu_split    : 2,  /* [2:1]   */
	    amsdu_present : 2,  /* [4:3]   */
	    type          : 1,  /* [5]     */
	    copy_policy   : 2,  /* [7:6]   */
	    index         : 8,  /* [15:8]  */
	    size          : 16; /* [31:16] */
#endif
};

struct cl_rx_usb_elem {
	struct cl_hw *cl_hw;
	struct urb *urb;
	struct cl_usb_endpoint *ep;
	struct sk_buff *submitted_skb_arr[USB_RX_CONT_MAX];
	u16 container_num;
	dma_addr_t dma_addr;
};

void cl_rx_usb_rx_data_complete(struct urb *urb);
int cl_rx_usb_urb_build(struct cl_hw *cl_hw, struct cl_rx_usb_elem *elem);
struct cl_rx_usb_elem *cl_rx_usb_elem_urb_alloc(struct cl_hw *cl_hw);
void cl_rx_usb_elem_dealloc(struct cl_rx_usb_elem *elem);
#endif /* CL_RX_USB_H */

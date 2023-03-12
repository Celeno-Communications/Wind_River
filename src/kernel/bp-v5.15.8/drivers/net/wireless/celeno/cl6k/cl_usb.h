/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_USB_H
#define CL_USB_H

#include <linux/usb.h>
#include "cl_hw.h"
#include "usb.h"

/* USB IN endpoint addresses */
#define CL_USB_EP_ADDR_MSG_DBG_IN         0x82
#define CL_USB_EP_ADDR_SENSING_ONLINE_IN  0x83
#define CL_USB_EP_ADDR_SENSING_OFFLINE_IN 0x84
#define CL_USB_EP_ADDR_RX_DATA_IN         0x85
#define CL_USB_EP_ADDR_RXM_DATA_IN        0x86

/* USB OUT endpoint addresses */
#define CL_USB_EP_ADDR_TX_DATA_AC0_OUT     0x02
#define CL_USB_EP_ADDR_TX_DATA_AC1_OUT     0x03
#define CL_USB_EP_ADDR_TX_DATA_AC2_OUT     0x04
#define CL_USB_EP_ADDR_TX_DATA_AC3_OUT     0x05
#define CL_USB_EP_ADDR_TX_BCAST_OUT        0x06
#define CL_USB_EP_ADDR_TX_HTP_OUT          0x07
#define CL_USB_EP_ADDR_TX_DATA_SENSING_OUT 0x08
#define CL_USB_EP_ADDR_READ_RSP            0x09

#define CL_USB_PKT_ADDR_AMSDU_PATTERN 0xAA33AA33

#define CL_USB_ALIGN_SIZE      4
#define CL_USB_ALIGN_MSK     (CL_USB_ALIGN_SIZE - 1)
#define CL_USB_ALIGN_PADS(x) ((CL_USB_ALIGN_SIZE - ((x) & CL_USB_ALIGN_MSK)) & CL_USB_ALIGN_MSK)

#define CL_USB_BUF_SIZE 1600

struct cl_usb_elem {
	struct cl_hw *cl_hw;
	struct urb *urb;
	struct cl_usb_endpoint *ep;
};

int cl_usb_dbginfobuf_push(struct cl_hw *cl_hw);
void cl_usb_fill_bulk_urb(struct cl_chip *chip,
			  struct urb *urb,
			  struct cl_usb_endpoint *ep,
			  void *context,
			  usb_complete_t complete_fn);
struct cl_usb_elem *cl_usb_elem_urb_alloc(struct cl_hw *cl_hw,
					  struct cl_usb_endpoint *ep);
void cl_usb_urb_submit(struct cl_hw *cl_hw,
		       struct cl_usb_elem *elem,
		       usb_complete_t complete_fn);
u16 cl_usb_get_single_addr_idx(struct cl_chip *chip);
int cl_usb_main_init(struct cl_hw *cl_hw);
void cl_usb_main_deinit(struct cl_hw *cl_hw);

#endif /* CL_USB_H */

/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_MSG_USB_H
#define CL_MSG_USB_H

#include <linux/usb.h>
#include "cl_hw.h"
#include "cl_ipc_shared.h"

#define CL_MSG_DBG_URB_NUM 128
#define CL_MSG_DBG_BUF_SIZE PAGE_SIZE
#define CL_MSG_DBG_MAGIC 0xaaaabbbb

struct cl_msg_usb_e2a_msg {
	struct cl_usb_msg_hdr hdr;
	struct cl_ipc_e2a_msg msg;
};

enum cl_msg_usb_msg_type {
	CL_MSG_USB_TYPE_HOSTMSG_RX,
	CL_MSG_USB_TYPE_DUMP,
	CL_MSG_USB_TYPE_LCU,
	CL_MSG_USB_TYPE_BT_DEBUG,
	CL_MSG_USB_TYPE_CFMSINGLE_TX,
	CL_MSG_USB_TYPE_CFMAGG_TX,
	CL_MSG_USB_TYPE_READ_REQ,
	CL_MSG_USB_TYPE_WRITE_REQ,
	CL_MSG_USB_TYPE_DS_AGG_PKT_REQ,
	CL_MSG_USB_TYPE_DS_SINGLE_PKT_REQ,
	CL_MSG_USB_TYPE_E2A_IRQ,

	CL_MSG_USB_TYPE_MAX
};

void cl_msg_usb_in_complete(struct urb *urb);
int cl_msg_usb_msg_fw_send(struct cl_hw *cl_hw, const void *msg_params,
			   bool background);
#endif /* CL_MSG_USB_H */

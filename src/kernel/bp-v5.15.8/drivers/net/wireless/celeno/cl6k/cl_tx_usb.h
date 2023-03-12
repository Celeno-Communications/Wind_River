/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_TX_USB_H
#define CL_TX_USB_H

#include "cl_hw.h"

int cl_tx_usb_single_packets_send(struct cl_hw *cl_hw, u8 num_packets,
				  u8 ep_idx, u16 queue_idx,
				  u32 first_dma_addr);

void cl_tx_usb_single_cfm_tasklet(unsigned long data);
void cl_tx_usb_single_pkt_req_tasklet(unsigned long data);
void cl_tx_usb_agg_pkt_req_tasklet(unsigned long data);
#endif /* CL_TX_USB_H */

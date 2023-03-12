/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_MSG_RX_H
#define CL_MSG_RX_H

struct cl_msg_rx_work {
	struct work_struct ws;
	/* Background message info */
	struct cl_hw *cl_hw;
	u16 file_len;
};

void cl_msg_rx_tasklet(unsigned long data);
void cl_msg_rx_flush_all(struct cl_hw *cl_hw);

#endif /* CL_MSG_RX_H */

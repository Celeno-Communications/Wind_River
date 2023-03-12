/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_TRAFFIC_MON_H
#define CL_TRAFFIC_MON_H

#include "cl_hw.h"

enum cl_traffic_mon_protocol {
	CL_TRFC_MON_PROT_TCP,
	CL_TRFC_MON_PROT_UDP,
	CL_TRFC_MON_PROT_MAX,
};

enum cl_traffic_mon_direction {
	CL_TRFC_MON_DIR_DL,
	CL_TRFC_MON_DIR_UL,
	CL_TRFC_MON_DIR_MAX,
};

struct cl_traffic_mon {
	u32 bytes_per_sec;
	u32 bytes;
};

void cl_traffic_mon_tx(struct cl_sta *cl_sta, struct sk_buff *skb);
void cl_traffic_mon_rx(struct cl_sta *cl_sta, struct sk_buff *skb);
void cl_traffic_mon_sta_maintenance(struct cl_hw *cl_hw, struct cl_sta *cl_sta);
int cl_traffic_mon_print(struct cl_hw *cl_hw);

#endif /* CL_TRAFFIC_MON_H */

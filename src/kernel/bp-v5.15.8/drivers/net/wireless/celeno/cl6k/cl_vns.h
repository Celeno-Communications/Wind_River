/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_VNS_H
#define CL_VNS_H

#include "cl_hw.h"

#define VNS_MODE_DATA       0x1
#define VNS_MODE_AUTO_REPLY 0x2
#define VNS_MODE_ALL        (VNS_MODE_DATA | VNS_MODE_AUTO_REPLY)

void cl_vns_init(struct cl_hw *cl_hw);
void cl_vns_close(struct cl_hw *cl_hw);
void cl_vns_maintenance(struct cl_hw *cl_hw);
void cl_vns_mgmt_handler(struct cl_hw *cl_hw, u8 *addr, s8 rssi[MAX_ANTENNAS]);
bool cl_vns_is_very_near(struct cl_hw *cl_hw, struct cl_sta *cl_sta, struct sk_buff *skb);
void cl_vns_sta_add(struct cl_hw *cl_hw, struct cl_sta *cl_sta);
void cl_vns_handle_rssi(struct cl_hw *cl_hw, struct cl_sta *cl_sta, s8 rssi[MAX_ANTENNAS]);
void cl_vns_recovery(struct cl_hw *cl_hw);
int cl_vns_cli(struct cl_hw *cl_hw, struct cli_params *cli_params);

#endif /* CL_VNS_H */

/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_VLAN_DSCP_H
#define CL_VLAN_DSCP_H

#include <linux/ip.h>

/* Version field value of IP header */
#define IP_V_IPV4 0x40
#define IP_V_IPV6 0x60

#define CL_UP_BY_L3 3
#define CL_UP_BY_L2 2

struct cl_hw;
struct cl_vif;

void cl_vlan_dscp_init(struct cl_hw *cl_hw);
bool cl_vlan_dscp_is_enabled(struct cl_hw *cl_hw,
			     struct cl_vif *cl_vif);
u8 cl_vlan_dscp_check_ether_type(struct cl_hw *cl_hw,
				 struct sk_buff *skb,
				 u8 ap_idx);
int cl_vlan_dscp_cli(struct cl_hw *cl_hw,
		     struct cl_vif *cl_vif,
		     char *data);

#endif /* CL_VLAN_DSCP_H */

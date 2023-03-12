/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_M2U_H
#define CL_M2U_H

#include "cl_hw.h"
#include "cl_vif.h"

bool cl_m2u_should_not_send_as_multicast(struct sk_buff *skb);
void cl_m2u_downlink_multicast_snooping(struct cl_hw *cl_hw, struct sk_buff *skb,
					struct net_device *dev);
void cl_m2u_uplink_multicast_snooping(struct cl_hw *cl_hw, struct cl_vif *cl_vif,
				      struct sk_buff *skb);

#endif /* CL_M2U_H */

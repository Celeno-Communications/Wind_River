/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_CMA_H
#define CL_CMA_H

#include <linux/skbuff.h>
#include "cl_hw.h"

#define CL_CMA_IP_HASH(addr) \
	((((addr) >> 24) & 0xff) ^ \
	 (((addr) >> 16) & 0xff) ^ \
	 (((addr) >> 8) & 0xff) ^ \
	 ((addr) & 0xff))

#define CL_CMA_IP_HASH_INDEX(addr) (CL_CMA_IP_HASH(addr) % CL_CMA_MAX_IP_HASH)
#define CL_CMA_TABLE_AGEOUT        300000 /* 5 minutes */
#define IS_MULTICAST_IP(ip)        (((ip) & 0xf0000000) == 0xe0000000)

int cl_cma_arp_tx(struct cl_vif *cl_vif, struct sk_buff *skb);
int cl_cma_arp_rx(struct cl_hw *cl_hw, struct sk_buff *skb);
int cl_cma_ip_tx(struct cl_vif *cl_vif, struct sk_buff *skb);
int cl_cma_ip_rx(struct cl_hw *cl_hw, struct sk_buff *skb);
void cl_cma_table_maintenance(struct cl_hw *cl_hw);
void cl_cma_table_init(struct cl_hw *cl_hw);
int cl_cma_cli(struct cl_hw *cl_hw, char *data);

#endif

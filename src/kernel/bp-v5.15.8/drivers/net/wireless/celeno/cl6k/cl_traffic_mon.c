// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include <linux/ip.h>
#include <linux/ipv6.h>
#include "cl_ip.h"
#include "cl_traffic_mon.h"
#include "cl_sta.h"
#include "cl_utils.h"

static void cl_traffic_mon_print_sta(struct cl_hw *cl_hw,
				     struct cl_sta *cl_sta,
				     char *buf,
				     int *len)
{
	u8 i, j;
	u32 bps;

	*len += snprintf(buf + *len, PAGE_SIZE - *len, "|%3u", cl_sta->sta_idx);

	for (i = 0; i < CL_TRFC_MON_PROT_MAX; i++)
		for (j = 0; j < CL_TRFC_MON_DIR_MAX; j++) {
			bps = CL_BYTES_TO_BITS(cl_sta->traffic_mon[i][j].bytes_per_sec);

			if (bps < 1000)
				*len += snprintf(buf + *len, PAGE_SIZE - *len, "|%4ubps ",
						 bps);
			else if (bps < 1000000)
				*len += snprintf(buf + *len, PAGE_SIZE - *len, "|%4uKbps",
						 bps / 1000);
			else
				*len += snprintf(buf + *len, PAGE_SIZE - *len, "|%4uMbps",
						 bps / 1000000);
		}

	*len += snprintf(buf + *len, PAGE_SIZE - *len, "|\n");
}

static void cl_traffic_mon_ipv4(struct sk_buff *skb, struct cl_sta *cl_sta,
				enum cl_traffic_mon_direction direction)
{
	struct iphdr *iphdr = ip_hdr(skb);

	if (iphdr->protocol == IPPROTO_UDP)
		cl_sta->traffic_mon[CL_TRFC_MON_PROT_UDP][direction].bytes +=
			ntohs(iphdr->tot_len) - IPV4_HDR_LEN(iphdr->ihl) - sizeof(struct udphdr);
	else if (iphdr->protocol == IPPROTO_TCP)
		cl_sta->traffic_mon[CL_TRFC_MON_PROT_TCP][direction].bytes +=
			ntohs(iphdr->tot_len) - IPV4_HDR_LEN(iphdr->ihl) - sizeof(struct tcphdr);
}

static void cl_traffic_mon_ipv6(struct sk_buff *skb, struct cl_sta *cl_sta,
				enum cl_traffic_mon_direction direction)
{
	struct ipv6hdr *ipv6hdr = ipv6_hdr(skb);

	if (ipv6hdr->nexthdr == IPPROTO_UDP)
		cl_sta->traffic_mon[CL_TRFC_MON_PROT_UDP][direction].bytes +=
			ntohs(ipv6hdr->payload_len) - sizeof(struct udphdr);
	else if (ipv6hdr->nexthdr == IPPROTO_TCP)
		cl_sta->traffic_mon[CL_TRFC_MON_PROT_TCP][direction].bytes +=
			ntohs(ipv6hdr->payload_len) - sizeof(struct tcphdr);
}

static void cl_traffic_mon_calc(struct sk_buff *skb, struct cl_sta *cl_sta,
				enum cl_traffic_mon_direction direction)
{
	if (set_network_header_if_proto(skb, ETH_P_IP))
		cl_traffic_mon_ipv4(skb, cl_sta, direction);
	else if (set_network_header_if_proto(skb, ETH_P_IPV6))
		cl_traffic_mon_ipv6(skb, cl_sta, direction);
}

void cl_traffic_mon_tx(struct cl_sta *cl_sta, struct sk_buff *skb)
{
	struct cl_hw *cl_hw = cl_sta->cl_vif->cl_hw;

	if (cl_hw->conf->ci_traffic_mon_en)
		cl_traffic_mon_calc(skb, cl_sta, CL_TRFC_MON_DIR_DL);
}

void cl_traffic_mon_rx(struct cl_sta *cl_sta, struct sk_buff *skb)
{
	struct cl_hw *cl_hw = cl_sta->cl_vif->cl_hw;

	if (cl_hw->conf->ci_traffic_mon_en)
		cl_traffic_mon_calc(skb, cl_sta, CL_TRFC_MON_DIR_UL);
}

void cl_traffic_mon_sta_maintenance(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	u8 i, j;

	for (i = 0; i < CL_TRFC_MON_PROT_MAX; i++)
		for (j = 0; j < CL_TRFC_MON_DIR_MAX; j++) {
			cl_sta->traffic_mon[i][j].bytes_per_sec = cl_sta->traffic_mon[i][j].bytes;
			cl_sta->traffic_mon[i][j].bytes = 0;
		}
}

int cl_traffic_mon_print(struct cl_hw *cl_hw)
{
	struct cl_sta *cl_sta = NULL;
	char *buf = NULL;
	int len = 0;
	int err = 0;

	buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	if (!buf)
		return -ENOMEM;

	len = snprintf(buf, PAGE_SIZE,
		       "-----------------------------------------\n"
		       "|STA| TCP DL | TCP UL | UDP DL | UDP UL |\n"
		       "|---+--------+--------+--------+--------|\n");

	/* Go over all stations - use bottom-half lock */
	read_lock_bh(&cl_hw->cl_sta_db.lock);

	list_for_each_entry(cl_sta, &cl_hw->cl_sta_db.head, list)
		cl_traffic_mon_print_sta(cl_hw, cl_sta, buf, &len);

	read_unlock_bh(&cl_hw->cl_sta_db.lock);

	len += snprintf(buf + len, PAGE_SIZE - len,
			"-----------------------------------------\n");

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

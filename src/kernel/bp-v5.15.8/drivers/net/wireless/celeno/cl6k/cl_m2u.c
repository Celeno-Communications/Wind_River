// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include <linux/igmp.h>
#include <linux/ipv6.h>
#include <net/mld.h>
#include <net/addrconf.h>
#include "cl_m2u.h"
#include "cl_igmp.h"
#include "cl_utils.h"
#include "cl_tx.h"
#include "cl_mac_addr.h"
#include "cl_ip.h"

static inline void mcast_ip_to_mac(u8 *ip_addr, u8 *mac_addr)
{
	mac_addr[0] = 0x01;
	mac_addr[1] = 0x00;
	mac_addr[2] = 0x5e;
	mac_addr[3] = ip_addr[1] & 0x7f;
	mac_addr[4] = ip_addr[2];
	mac_addr[5] = ip_addr[3];
}

static void cl_uplink_ipv4_mcast_membership_report_v1_v2(struct cl_hw *cl_hw,
							 struct mcast_table *mcast_table,
							 struct igmphdr *igmp_header,
							 u8 *src_mac_addr)
{
	u8 group_mac_addr[ETH_ALEN] = {0};
	u8 *group_ip_addr = (u8 *)&igmp_header->group;

	mcast_ip_to_mac(group_ip_addr, group_mac_addr);
	cl_igmp_mcast_table_insert_entry(cl_hw, mcast_table, group_mac_addr, src_mac_addr);
}

static void cl_uplink_ipv4_mcast_leave_message(struct cl_hw *cl_hw,
					       struct mcast_table *mcast_table,
					       struct igmphdr *igmp_header,
					       u8 *src_mac_addr)
{
	u8 group_mac_addr[ETH_ALEN] = {0};
	u8 *group_ip_addr = (u8 *)&igmp_header->group;

	mcast_ip_to_mac(group_ip_addr, group_mac_addr);
	cl_igmp_mcast_table_delete_entry(cl_hw, mcast_table, group_mac_addr, src_mac_addr);
}

static void cl_uplink_ipv4_mcast_membership_report_v3(struct cl_hw *cl_hw,
						      struct mcast_table *mcast_table,
						      struct sk_buff *skb,
						      u8 *src_mac_addr)
{
	u8 group_mac_addr[ETH_ALEN] = {0};
	int i = 0;
	struct igmpv3_report *igmpv3_hdr;
	struct igmpv3_grec *group;
	int len = 0;

	igmpv3_hdr = igmpv3_report_hdr(skb);
	len = skb_transport_offset(skb) + sizeof(*igmpv3_hdr);

	for (i = 0; i < ntohs(igmpv3_hdr->ngrec); i++) {
		len += sizeof(*group);

		if (!pskb_may_pull(skb, len))
			return;

		group = (void *)(skb->data + len - sizeof(*group));
		u8 *group_ip_addr = (u8 *)&group->grec_mca;
		u8 group_type = group->grec_type;
		u16 num_of_sources = ntohs(group->grec_nsrcs);
		len += num_of_sources * 4;

		if (!pskb_may_pull(skb, len))
			return;

		mcast_ip_to_mac(group_ip_addr, group_mac_addr);
		igmp_pr_trace("group_ip_addr=%pI4, group_mac_addr=%pM, group_type=%d\n",
			      group_ip_addr, group_mac_addr, group_type);

		if (group_type == IGMPV3_MODE_IS_EXCLUDE ||
		    group_type == IGMPV3_CHANGE_TO_EXCLUDE ||
		    group_type == IGMPV3_ALLOW_NEW_SOURCES) {
			cl_igmp_mcast_table_insert_entry(cl_hw, mcast_table,
							 group_mac_addr, src_mac_addr);
			break;
		}

		if (group_type == IGMPV3_BLOCK_OLD_SOURCES) {
			cl_igmp_mcast_table_delete_entry(cl_hw, mcast_table,
							 group_mac_addr, src_mac_addr);
			break;
		}

		if (group_type == IGMPV3_CHANGE_TO_INCLUDE ||
		    group_type == IGMPV3_MODE_IS_INCLUDE) {
			if (num_of_sources == 0)
				cl_igmp_mcast_table_delete_entry(cl_hw,
								 mcast_table,
								 group_mac_addr,
								 src_mac_addr);
			else
				cl_igmp_mcast_table_insert_entry(cl_hw,
								 mcast_table,
								 group_mac_addr,
								 src_mac_addr);

			break;
		}
	}
}

static void cl_uplink_ipv4_multicast_snooping(struct cl_hw *cl_hw,
					      struct mcast_table *mcast_table,
					      struct sk_buff *skb)
{
	struct ethhdr *ethhdr = eth_hdr(skb);
	struct igmphdr *igmp_header;
	u8 igmp_type;
	u8 *src_mac_addr = ethhdr->h_source;

#if LINUX_VERSION_IS_GEQ(5, 1, 0)
	if (ip_mc_check_igmp(skb))
		return;
#else
	if (ip_mc_check_igmp(skb, NULL))
		return;
#endif

	igmp_header = igmp_hdr(skb);
	igmp_type = igmp_header->type;

	igmp_pr_trace("igmp_type=%d, src_mac_addr=%pM\n", igmp_type, src_mac_addr);

	switch (igmp_type) {
	case IGMP_HOST_MEMBERSHIP_REPORT:   /* IGMP version 1 membership report. */
	case IGMPV2_HOST_MEMBERSHIP_REPORT: /* IGMP version 2 membership report. */
		cl_uplink_ipv4_mcast_membership_report_v1_v2(cl_hw, mcast_table,
							     igmp_header, src_mac_addr);
		break;

	case IGMP_HOST_LEAVE_MESSAGE:       /* IGMP version 1 and version 2 leave group. */
		cl_uplink_ipv4_mcast_leave_message(cl_hw, mcast_table, igmp_header, src_mac_addr);
		break;

	case IGMPV3_HOST_MEMBERSHIP_REPORT: /* IGMP version 3 membership report. */
		cl_uplink_ipv4_mcast_membership_report_v3(cl_hw, mcast_table,
							  skb, src_mac_addr);
		break;
	default:
		igmp_pr_err("unknown IGMP Type=%d\n", igmp_type);
		break;
	}
}

static void cl_uplink_ipv6_mcast_mgm_report(struct cl_hw *cl_hw,
					    struct mcast_table *mcast_table,
					    u8 *src_mac_addr,
					    struct mld_msg *mld)
{
	u8 group_mac_addr[ETH_ALEN] = {0};

	ipv6_eth_mc_map(&mld->mld_mca, group_mac_addr);
	cl_igmp_mcast_table_insert_entry(cl_hw, mcast_table, group_mac_addr, src_mac_addr);
}

static void cl_uplink_ipv6_mcast_mgm_reduction(struct cl_hw *cl_hw,
					       struct mcast_table *mcast_table,
					       u8 *src_mac_addr,
					       struct mld_msg *mld)
{
	u8 group_mac_addr[ETH_ALEN] = {0};

	ipv6_eth_mc_map(&mld->mld_mca, group_mac_addr);
	cl_igmp_mcast_table_delete_entry(cl_hw, mcast_table, group_mac_addr, src_mac_addr);
}

static void cl_uplink_ipv6_mcast_mld2_report(struct cl_hw *cl_hw,
					     struct mcast_table *mcast_table,
					     u8 *src_mac_addr,
					     struct sk_buff *skb)
{
	u8 group_mac_addr[ETH_ALEN] = {0};
	struct mld2_grec *grec;
	struct icmp6hdr *icmp6h;
	int i = 0;
	int len;
	int num;

	if (!pskb_may_pull(skb, sizeof(*icmp6h)))
		return;

	icmp6h = icmp6_hdr(skb);
	num = ntohs(icmp6h->icmp6_dataun.un_data16[1]);
	len = skb_transport_offset(skb) + sizeof(*icmp6h);
	igmp_pr_trace("parse MLD2 report: num=%d, len=%d, skb->len=%d\n", num, len, skb->len);

	for (i = 0; i < num; i++) {
		__be16 *nsrcs, _nsrcs;
		u32 nsrcs_offset = len + offsetof(struct mld2_grec, grec_nsrcs);

		nsrcs = skb_header_pointer(skb, nsrcs_offset, sizeof(_nsrcs), &_nsrcs);

		if (!nsrcs)
			return;

		if (!pskb_may_pull(skb,
				   len + sizeof(*grec) + sizeof(struct in6_addr) * ntohs(*nsrcs)))
			return;

		grec = (struct mld2_grec *)(skb->data + len);
		len += sizeof(*grec) + sizeof(struct in6_addr) * ntohs(*nsrcs);
		ipv6_eth_mc_map(&grec->grec_mca, group_mac_addr);
		igmp_pr_trace("parse MLD2: grec_mca=%pI6, group_mac_addr=%pM, grec_type=%d\n",
			      &grec->grec_mca, group_mac_addr, grec->grec_type);

		if ((grec->grec_type == MLD2_CHANGE_TO_INCLUDE ||
		     grec->grec_type == MLD2_MODE_IS_INCLUDE) && ntohs(*nsrcs) == 0)
			cl_igmp_mcast_table_delete_entry(cl_hw, mcast_table,
							 group_mac_addr, src_mac_addr);
		else
			cl_igmp_mcast_table_insert_entry(cl_hw, mcast_table,
							 group_mac_addr, src_mac_addr);
	}
}

static void cl_uplink_ipv6_multicast_snooping(struct cl_hw *cl_hw,
					      struct mcast_table *mcast_table,
					      struct sk_buff *skb)
{
	struct mld_msg *mld = (struct mld_msg *)skb_transport_header(skb);
	struct ethhdr *ethhdr = eth_hdr(skb);
	u8 *src_mac_addr = ethhdr->h_source;

	igmp_pr_trace("mld->mld_type=%d, src_mac_addr=%pM\n", mld->mld_type, src_mac_addr);

	switch (mld->mld_type) {
	case ICMPV6_MGM_REPORT:
		cl_uplink_ipv6_mcast_mgm_report(cl_hw, mcast_table,
						src_mac_addr, mld);
		break;

	case ICMPV6_MGM_REDUCTION:
		cl_uplink_ipv6_mcast_mgm_reduction(cl_hw, mcast_table,
						   src_mac_addr, mld);
		break;

	case ICMPV6_MLD2_REPORT:
		cl_uplink_ipv6_mcast_mld2_report(cl_hw, mcast_table,
						 src_mac_addr, skb);
		break;
	}
}

static void cl_handle_downlink_igmp(struct cl_hw *cl_hw, struct sk_buff *skb,
				    struct cl_vif *cl_vif)
{
	struct igmphdr *igmp_header;
	struct mcast_table_entry *group_entry = NULL;
	struct mcast_table *mcast_table = cl_vif->mcast_table;
	struct mcast_member_entry *member_entry = NULL;
	bool orig_skb_transmitted = false;
	u8 igmp_type;

#if LINUX_VERSION_IS_GEQ(5, 1, 0)
	if (ip_mc_check_igmp(skb))
		return;
#else
	if (ip_mc_check_igmp(skb, NULL))
		return;
#endif
	igmp_header = igmp_hdr(skb);
	igmp_type = igmp_header->type;

	if (igmp_type == IGMP_HOST_MEMBERSHIP_REPORT ||
	    igmp_type == IGMPV2_HOST_MEMBERSHIP_REPORT ||
	    igmp_type == IGMPV3_HOST_MEMBERSHIP_REPORT ||
	    igmp_type == IGMP_HOST_LEAVE_MESSAGE) {
		kfree_skb(skb);
		return;
	}

	/* Send this IGMP query to all registered IGMP clients */
	for (group_entry = mcast_table->content; group_entry; group_entry = group_entry->next) {
		if (group_entry->member_list.size == 0)
			continue;

		for (member_entry = (struct mcast_member_entry *)group_entry->member_list.head;
		     member_entry;
		     member_entry = member_entry->next) {
			struct sk_buff *clone = (member_entry->next || group_entry->next) ?
				skb_copy(skb, GFP_ATOMIC) : skb;
			struct ethhdr *ethhdr = eth_hdr(clone);

			cl_mac_addr_copy(ethhdr->h_dest, member_entry->mac_addr);
			skb->pkt_type = PACKET_OTHERHOST;

			if (clone == skb)
				orig_skb_transmitted = true;

			__cl_tx_start(cl_hw, clone, clone->dev);
		}
	}

	if (!orig_skb_transmitted)
		kfree_skb(skb);
}

static void cl_downlink_multicast_to_unicast(struct cl_hw *cl_hw, struct sk_buff *skb,
					     struct mcast_table_entry *group_entry)
{
	struct mcast_member_entry *member_entry = NULL;
	bool orig_skb_transmitted = false;

	if (group_entry->member_list.size == 0) {
		/* Drop this multicast packet */
		kfree_skb(skb);
		return;
	}

	for (member_entry = (struct mcast_member_entry *)group_entry->member_list.head;
	     member_entry;
	     member_entry = member_entry->next) {
		struct sk_buff *clone = member_entry->next ? skb_copy(skb, GFP_ATOMIC) : skb;
		struct ethhdr *ethhdr = eth_hdr(clone);

		cl_mac_addr_copy(ethhdr->h_dest, member_entry->mac_addr);
		skb->pkt_type = PACKET_OTHERHOST;

		if (clone == skb)
			orig_skb_transmitted = true;

		__cl_tx_start(cl_hw, clone, clone->dev);
	}

	if (!orig_skb_transmitted)
		kfree_skb(skb);
}

bool cl_m2u_should_not_send_as_multicast(struct sk_buff *skb)
{
	/*
	 * This function checks a packet and decides if we should
	 * send multicast traffic via wireless
	 */
	const u8 *dest = eth_hdr(skb)->h_dest;

	if (!is_multicast_ether_addr(dest) || is_broadcast_ether_addr(dest))
		return false;

	if (is_ipv4_packet(skb)) {
		if (is_ipv4_service_multicast_packet(skb))
			return false;
		else if (!is_mdns_packet(dest) && !is_ssdp_packet(skb))
			return true;
	} else if (is_ipv6_packet(skb)) {
		if (is_ipv6_service_multicast_packet(skb))
			return false;
		else
			return true; /* Do M2U on any non IPV6 service multicast packet */
	}

	return false;
}

void cl_m2u_downlink_multicast_snooping(struct cl_hw *cl_hw, struct sk_buff *skb,
					struct net_device *dev)
{
	struct cl_vif *cl_vif = NETDEV_TO_CL_VIF(dev);

	skb->dev = dev;

	if (is_ipv4_packet(skb) && is_igmp_packet(skb)) {
		cl_handle_downlink_igmp(cl_hw, skb, cl_vif);
	} else {
		struct ethhdr *ethhdr = eth_hdr(skb);
		struct mcast_table *mcast_table = cl_vif->mcast_table;
		struct mcast_table_entry *group_entry =
			cl_igmp_mcast_table_lookup(cl_hw, mcast_table, ethhdr->h_dest);

		if (group_entry)
			/* Multicast group found - do M2U */
			cl_downlink_multicast_to_unicast(cl_hw, skb, group_entry);
		else
			/* Multicast group not found - drop the packet */
			kfree_skb(skb);
	}
}

void cl_m2u_uplink_multicast_snooping(struct cl_hw *cl_hw, struct cl_vif *cl_vif,
				      struct sk_buff *skb)
{
	if (is_ipv4_packet(skb) && is_igmp_packet(skb))
		cl_uplink_ipv4_multicast_snooping(cl_hw, cl_vif->mcast_table, skb);
	else if (is_ipv6_packet(skb) && (ipv6_mc_check_mld(skb) == 0))
		cl_uplink_ipv6_multicast_snooping(cl_hw, cl_vif->mcast_table, skb);
}


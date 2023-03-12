/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_IP_H
#define CL_IP_H

#include <linux/version.h>
#include <linux/skbuff.h>
#include <linux/ip.h>
#include <linux/ipv6.h>
#include <linux/if_vlan.h>
#include <linux/netdevice.h>
#include <linux/igmp.h>
#include <asm/unaligned.h>

/* Check if a packet has specific LLC fields e.g. DSAP, SSAP and Control */
#define PKT_HAS_LLC_HDR(a) ((a[0] == 0xAA) && (a[1] == 0xAA) && (a[2] == 0x03))
#define LENGTH_LLC 3
#define LENGTH_SSNAP 5

/* Multiply by 4 because IHL is number of 32-bit words */
#define IPV4_HDR_LEN(ihl) ((ihl) << 2)
#define TCP_ACK_MAX_LEN 100

bool set_network_header_if_proto(struct sk_buff *skb, u16 protocol);
bool is_ipv4_packet(struct sk_buff *skb);
bool is_ipv6_packet(struct sk_buff *skb);
bool is_icmp_packet(struct sk_buff *skb);
bool is_igmp_packet(struct sk_buff *skb);
bool is_ssdp_packet(struct sk_buff *skb);
bool is_mdns_packet(const u8 *dest_mac);
bool is_ipv4_service_multicast_packet(struct sk_buff *skb);
bool is_ipv6_service_multicast_packet(struct sk_buff *skb);
bool is_tcp_ack(struct sk_buff *skb, bool *syn_rst_push);

static inline bool cl_ip_addr_parse_str(const u8 *str, u8 *addr)
{
	return (sscanf(str,
		       "%hhd.%hhd.%hhd.%hhd",
		       &addr[0],
		       &addr[1],
		       &addr[2],
		       &addr[3]) == 4);
}

#endif /* CL_IP_H */

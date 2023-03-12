// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_ip.h"

/* Chromecast" 239.255.255.250 */
#define MCAST_CHROMECAST_ADDR htonl(0xEFFFFFFAL)

/*
 * Local-group multicast address | internetwork multicast address =
 *   = 224.0.0.0/24 | 224.0.1.0/24 = 224.0.0.0/23
 */
#define MCAST_IP_SERVICE_MASK __constant_htonl(0xFFFFFE00UL)

static __be16 get_eth_proto(struct sk_buff *skb)
{
	if (!skb->mac_header)
		skb_reset_mac_header(skb);

	if (eth_hdr(skb)->h_proto == htons(ETH_P_8021Q))
		return vlan_eth_hdr(skb)->h_vlan_encapsulated_proto;
	else
		return eth_hdr(skb)->h_proto;
}

bool set_network_header_if_proto(struct sk_buff *skb, u16 protocol)
{
	if (get_eth_proto(skb) == htons(protocol)) {
		const bool has_vlan_header = eth_hdr(skb)->h_proto == htons(ETH_P_8021Q);
		const size_t h_offset =
			(eth_hdr(skb) == (struct ethhdr *)(skb->data)) ? ETH_HLEN : 0;

		skb_set_network_header(skb, h_offset + ((has_vlan_header) ? VLAN_HLEN : 0));

		return true;
	}

	return false;
}

bool is_ipv4_packet(struct sk_buff *skb)
{
	return set_network_header_if_proto(skb, ETH_P_IP) &&
	       (ip_hdr(skb)->ihl >= 5) &&
	       (ip_hdr(skb)->version == IPVERSION);
}

bool is_ipv6_packet(struct sk_buff *skb)
{
	return set_network_header_if_proto(skb, ETH_P_IPV6) &&
	       (ipv6_hdr(skb)->version == 6);
}

bool is_icmp_packet(struct sk_buff *skb)
{
	if (is_ipv4_packet(skb))
		return (ip_hdr(skb)->protocol == IPPROTO_ICMP);
	else if (is_ipv6_packet(skb))
		return (ipv6_hdr(skb)->nexthdr == IPPROTO_ICMP);

	return false;
}

bool is_igmp_packet(struct sk_buff *skb)
{
	return (ip_hdr(skb)->protocol == IPPROTO_IGMP);
}

bool is_ssdp_packet(struct sk_buff *skb)
{
	bool status = false;

	if (ip_hdr(skb)->daddr == MCAST_CHROMECAST_ADDR)
		status = true;

	return status;
}

bool is_mdns_packet(const u8 *dest_mac)
{
	/*
	 * Multicast DNS packets should be sent as multicast, since no IGMP
	 * registration is performed on them
	 */
	u8 mdns_mac[] = {0x01, 0x00, 0x5e, 0x00, 0x00};

	if (!memcmp(dest_mac, mdns_mac, 5) && (dest_mac[5] == 0xfb || dest_mac[5] == 0xfc))
		return true;

	return false;
}

bool is_ipv4_service_multicast_packet(struct sk_buff *skb)
{
	/* Check if sk_buff contains IGMP packet, addressed to 224.0.0.0/23 */
	return ((IGMP_LOCAL_GROUP == (ip_hdr(skb)->daddr & MCAST_IP_SERVICE_MASK)) &&
		(IPPROTO_IGMP != ip_hdr(skb)->protocol || IGMP_ALL_HOSTS == ip_hdr(skb)->daddr));
}

bool is_ipv6_service_multicast_packet(struct sk_buff *skb)
{
	/* Check if sk_buff contains ICMP packet, or addressed to ff02::/16 */
	const struct ipv6hdr *ip6h = ipv6_hdr(skb);
	u8 protocol = ip6h->nexthdr;

	/* If hop-by-hop option header, get the first u8 field from this header */
	if (protocol == IPPROTO_HOPOPTS)
		protocol = ((const struct ipv6_hopopt_hdr *)(ip6h + 1))->nexthdr;

	return (((ip6h->daddr.s6_addr[0] == 0xff) &&
		 (ip6h->daddr.s6_addr[1] == 0x02)) ||
		(protocol == IPPROTO_ICMPV6));
}

bool is_tcp_ack(struct sk_buff *skb, bool *syn_rst_push)
{
	if (skb->len > TCP_ACK_MAX_LEN)
		goto out;

	if (is_ipv4_packet(skb)) {
		struct iphdr *iphdr = ip_hdr(skb);

		if (iphdr->protocol == IPPROTO_TCP) {
			struct tcphdr *tcp_hdr = (struct tcphdr *)
						 ((char *)iphdr +
						  IPV4_HDR_LEN(iphdr->ihl));
			u16 data_size = ntohs(iphdr->tot_len) -
					IPV4_HDR_LEN(iphdr->ihl) -
					(tcp_hdr->doff * 4);

			*syn_rst_push = tcp_hdr->syn || tcp_hdr->rst || tcp_hdr->psh;

			return (data_size == 0);
		}
	} else if (is_ipv6_packet(skb)) {
		struct ipv6hdr *ipv6hdr = ipv6_hdr(skb);

		if (ipv6hdr->nexthdr == IPPROTO_TCP) {
			struct tcphdr *tcp_hdr = (struct tcphdr *)
						 ((char *)ipv6hdr +
						 sizeof(struct ipv6hdr));
			u16 data_size = ntohs(ipv6hdr->payload_len) -
					(tcp_hdr->doff * 4);

			*syn_rst_push = tcp_hdr->syn || tcp_hdr->rst || tcp_hdr->psh;

			return (data_size == 0);
		}
	}

out:
	*syn_rst_push = false;
	return false;
}


// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include <linux/if_arp.h>
#include "cl_cma.h"
#include "cl_utils.h"
#include "cl_mac_addr.h"
#include "cl_ip.h"

static u8 DHCP_MAGIC[] = {0x63, 0x82, 0x53, 0x63};

static void mcast_ip_to_mac(u8 *ip_addr, u8 **mac_addr)
{
	if (!ip_addr || !mac_addr || !(*mac_addr))
		return;

	*(*mac_addr) = 0x01;
	*(*mac_addr + 1) = 0x00;
	*(*mac_addr + 2) = 0x5e;
	*(*mac_addr + 3) = ip_addr[1] & 0x7f;
	*(*mac_addr + 4) = ip_addr[2];
	*(*mac_addr + 5) = ip_addr[3];
}

static u8 *cma_table_lookup(struct cl_hw *cl_hw, __be32 ip_addr)
{
	u32 ip_idx, ip;
	u8 *mac_addr = NULL;
	struct cma_table_entry *cma_entry = NULL;

	/* If multicast ip, convert the multicast group address to mac address */
	ip = ntohl(ip_addr);
	if (IS_MULTICAST_IP(ip)) {
		mac_addr = (u8 *)(&cl_hw->cma_table.cur_mcast_addr);
		mcast_ip_to_mac((u8 *)&ip_addr, (u8 **)(&mac_addr));
		return cl_hw->cma_table.cur_mcast_addr;
	}

	ip_idx = CL_CMA_IP_HASH_INDEX(be32_to_cpu(ip_addr));
	cma_entry = cl_hw->cma_table.hash[ip_idx];

	while (cma_entry) {
		if (cma_entry->ip_addr == be32_to_cpu(ip_addr)) {
			cma_entry->last_time = jiffies_to_msecs(jiffies);
			return cma_entry->mac_addr;
		}

		cma_entry = cma_entry->next;
	}

	/* No Matching Mac address - return NULL */
	return mac_addr;
}

static void cl_cma_delete_entry(struct cl_hw *cl_hw, u8 idx)
{
	struct cma_table_entry *cma_entry = NULL;

	if (idx < CL_CMA_MAX_IP_HASH)
		cma_entry = cl_hw->cma_table.hash[idx];

	if (cma_entry) {
		cl_hw->cma_table.hash[idx] = cma_entry->next;
		kfree(cma_entry);
		cl_hw->cma_table.size--;
	} else {
		cl_dbg_err(cl_hw, "no entry for idx %u\n", idx);
	}
}

static void cl_cma_add_entry(struct cl_hw *cl_hw, u8 *mac_addr, u32 ip_addr)
{
	struct cma_table_entry *cma_entry = NULL;
	int idx = CL_CMA_IP_HASH_INDEX(ip_addr);

	cma_entry = kzalloc(sizeof(*cma_entry), GFP_ATOMIC);
	if (!cma_entry)
		return;

	cma_entry->ip_addr = ip_addr;
	cl_mac_addr_move(cma_entry->mac_addr, mac_addr);
	cma_entry->next = NULL;
	cma_entry->last_time = jiffies_to_msecs(jiffies);

	if (!cl_hw->cma_table.hash[idx]) {
		cl_hw->cma_table.hash[idx] = cma_entry;
	} else {
		cma_entry->next = cl_hw->cma_table.hash[idx];
		cl_hw->cma_table.hash[idx] = cma_entry;
	}

	cl_hw->cma_table.size++;
}

static void cl_cma_table_update(struct cl_hw *cl_hw, u8 *mac_addr, u32 ip_addr)
{
	struct cma_table_entry *cma_entry = NULL;
	int ip_idx = CL_CMA_IP_HASH_INDEX(ip_addr);

	cma_entry = cl_hw->cma_table.hash[ip_idx];

	while (cma_entry) {
		/* Find IP-MAC Mapping entry */
		if (ip_addr == cma_entry->ip_addr) {
			/* Update the mac address and timestamp */
			cl_mac_addr_move(cma_entry->mac_addr, mac_addr);
			cma_entry->last_time = jiffies_to_msecs(jiffies);
			return;
		}
		cma_entry = cma_entry->next;
	}

	cl_cma_add_entry(cl_hw, mac_addr, ip_addr);
}

static int cl_cma_cli_help(struct cl_hw *cl_hw)
{
	char *buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!buf)
		return -ENOMEM;

	snprintf(buf, PAGE_SIZE,
		 "cma usage:\n"
		 "-a : Add entry to CMA table [MAC][IP]\n"
		 "-d : Delete entry from CMA table [idx]\n"
		 "-s : Display CMA table\n");

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

static int cl_display_cma_table(struct cl_hw *cl_hw)
{
	struct cl_cma_table *cma_table = &cl_hw->cma_table;
	struct cma_table_entry *entry = NULL;
	int entry_idx = 0;
	unsigned long current_time = jiffies_to_msecs(jiffies);
	char *buf = NULL;
	int err = 0;
	int len = 0;

	if (cma_table->size == 0)
		return 0;

	buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	if (!buf)
		return -ENOMEM;

	len += snprintf(buf + len, PAGE_SIZE - len,
			"CMA Table:\n"
			"===================================================\n"
			"idx |     MAC Addr    |    IP Addr    |   AgeOut  |\n"
			"    |                 |               |   (msec)  |\n"
			"===================================================\n");

	for (entry_idx = 0; entry_idx < CL_CMA_MAX_IP_HASH; entry_idx++) {
		entry = cma_table->hash[entry_idx];
		while (entry) {
			u8 *addr = (u8 *)&entry->ip_addr;

			len += snprintf(buf + len, PAGE_SIZE - len,
					" %2d |%pM|%3u.%3u.%3u.%3u| %7lu   |\n",
					entry_idx, entry->mac_addr, addr[0],
					addr[1], addr[2], addr[3],
					CL_TIME_DIFF(current_time,
						     entry->last_time));
			entry = entry->next;
		}
	}

	len += snprintf(buf + len, PAGE_SIZE - len,
			"===================================================\n");

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

void cl_cma_table_init(struct cl_hw *cl_hw)
{
	memset(&cl_hw->cma_table, 0, sizeof(struct cl_cma_table));
}

int cl_cma_arp_tx(struct cl_vif *cl_vif, struct sk_buff *skb)
{
	u8 *arp_hdr = (skb->data + ETH_HLEN);
	u8 *sender_mac = (u8 *)(arp_hdr + sizeof(struct arphdr));
	u8 *sender_ip = (u8 *)(sender_mac + ETH_ALEN);
	bool is_unicast_src = !(is_multicast_ether_addr(sender_mac) ||
				is_zero_ether_addr(sender_mac));

	if (is_unicast_src && get_unaligned_le32(sender_ip) != 0)
		cl_cma_table_update(cl_vif->cl_hw, sender_mac,
				    get_unaligned_le32(sender_ip));

	if (is_unicast_src) {
		cl_mac_addr_move(sender_mac, cl_vif->vif->addr);
		cl_mac_addr_move((skb->data + ETH_ALEN), cl_vif->vif->addr);
	}

	return 0;
}

void cl_cma_table_maintenance(struct cl_hw *cl_hw)
{
	struct cma_table_entry *cma_entry = NULL;
	unsigned long current_time = jiffies_to_msecs(jiffies);
	int i;

	for (i = 0; i < CL_CMA_MAX_IP_HASH; i++) {
		cma_entry = cl_hw->cma_table.hash[i];
		while (cma_entry) {
			/* Check AgeOut */
			if (CL_TIME_DIFF(current_time, cma_entry->last_time) >=
			    CL_CMA_TABLE_AGEOUT) {
				cl_cma_delete_entry(cl_hw, (u8)i);
				cma_entry = cl_hw->cma_table.hash[i];
			} else {
				cma_entry = cma_entry->next;
			}
		}
	}
}

int cl_cma_arp_rx(struct cl_hw *cl_hw, struct sk_buff *skb)
{
	u8 *dst_mac = (u8 *)(skb->data + 18);
	u8 *dst_ip = (u8 *)(dst_mac + ETH_ALEN);
	u8 *real_mac = NULL;
	bool is_unicast = (!(is_multicast_ether_addr(dst_mac) ||
			  is_zero_ether_addr(dst_mac)));
	struct ethhdr *ehdr = eth_hdr(skb);

	if (is_unicast && (get_unaligned_le32(dst_ip) != 0))
		real_mac = cma_table_lookup(cl_hw, *(__be32 *)dst_ip);

	/* If Mac address was found in Cma Table - assign it */
	if (is_unicast && real_mac) {
		cl_mac_addr_move(dst_mac, real_mac);
		cl_mac_addr_move(ehdr->h_dest, real_mac);
	}
	/* If Mac address was not found in Cma Table - assign broadcast MAC */
	if (!real_mac)
		eth_broadcast_addr(ehdr->h_dest);

	return 0;
}

int cl_cma_ip_tx(struct cl_vif *cl_vif, struct sk_buff *skb)
{
	struct iphdr *ip_hdr = (struct iphdr *)(skb->data + ETH_HLEN);
	u8 *src_mac = (u8 *)(skb->data + ETH_ALEN);
	bool is_unicast_src = (!(is_multicast_ether_addr(src_mac) ||
				is_zero_ether_addr(src_mac)));

	if (is_unicast_src && ip_hdr->saddr != 0)
		cl_cma_table_update(cl_vif->cl_hw, src_mac,
				    be32_to_cpu(ip_hdr->saddr));

	/* If UDP packet */
	if (ip_hdr->protocol == IPPROTO_UDP) {
		u8 *udp_hdr = ((u8 *)ip_hdr + sizeof(struct iphdr));
		u16 src_port = get_unaligned((u16 *)(udp_hdr));
		u16 dst_port = get_unaligned((u16 *)(udp_hdr + 2));

		/* If DHCP packet */
		if (src_port == 68 && dst_port == 67) {
			u16 bootp_flag = get_unaligned((u16 *)(udp_hdr + 18));

			/* If not already set to broadcast */
			if (bootp_flag != 0x8000) {
				u8 *dhcp_hdr = udp_hdr + 244;

				if (!memcmp(dhcp_hdr, DHCP_MAGIC, 4)) {
					/* Set broadcast */
					bootp_flag = 0x8000;
					memmove((udp_hdr + 18), &bootp_flag, 2);
					/*reset UDP checksum */
					memset(udp_hdr + 6, 0, 2);
				}
			}
		}
	}

	if (is_unicast_src)
		cl_mac_addr_move(src_mac, cl_vif->vif->addr);

	return 0;
}

int cl_cma_ip_rx(struct cl_hw *cl_hw, struct sk_buff *skb)
{
	u8 *dst_ip = NULL;
	u8 *real_mac = NULL;
	struct ethhdr *ehdr = eth_hdr(skb);
	u32 ip_addr = 0;
	u8 *tmp_ip_addr = (u8 *)&ip_addr;

	dst_ip = (u8 *)(skb->data + 16);

	*tmp_ip_addr = *dst_ip;
	*(++tmp_ip_addr) = *(++dst_ip);
	*(++tmp_ip_addr) = *(++dst_ip);
	*(++tmp_ip_addr) = *(++dst_ip);

	real_mac = cma_table_lookup(cl_hw, cpu_to_be32(ip_addr));

	if (real_mac)
		cl_mac_addr_move(ehdr->h_dest, real_mac);
	else
		eth_broadcast_addr(ehdr->h_dest);

	return 0;
}

int cl_cma_cli(struct cl_hw *cl_hw, char *data)
{
	u8 mac_addr[ETH_ALEN] = {0};
	u8 ip_addr[4] = {0};

	if (!(data && strlen(data))) {
		cl_dbg_err(cl_hw, "Empty data\n");
		return cl_cma_cli_help(cl_hw);
	}

	if (!strncmp(data, "-a.", 3)) {
		if (!cl_mac_addr_parse_str(data + 3, mac_addr)) {
			cl_dbg_err(cl_hw, "Wrong MAC format\n");
			return 0;
		}
		/* Skip "-a.xx:xx:xx:xx:xx:xx." */
		if (!cl_ip_addr_parse_str(data + 21, ip_addr)) {
			cl_dbg_err(cl_hw, "Wrong IP format\n");
			return 0;
		}
		cl_cma_table_update(cl_hw, mac_addr,
				    get_unaligned_le32(ip_addr));

		return 0;
	} else if (!strncmp(data, "-d.", 3)) {
		u8 idx = 0;

		if (kstrtou8(data + 3, 0, &idx) == 0)
			cl_cma_delete_entry(cl_hw, idx);
		else
			cl_dbg_err(cl_hw, "Illegal data %s\n", data + 3);

		return 0;
	} else if (!strncmp(data, "-s", 2)) {
		return cl_display_cma_table(cl_hw);
	}

	cl_dbg_err(cl_hw, "Illegal data %s\n", data);
	return cl_cma_cli_help(cl_hw);
}


/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_MAC_ADDR_H
#define CL_MAC_ADDR_H

#include "cl_hw.h"

int cl_mac_addr_set(struct cl_hw *cl_hw);

static inline void cl_mac_addr_copy(u8 *dest_addr, const u8 *src_addr)
{
	memcpy(dest_addr, src_addr, ETH_ALEN);
}

static inline void cl_mac_addr_move(u8 *dest_addr, const u8 *src_addr)
{
	memmove(dest_addr, src_addr, ETH_ALEN);
}

static inline bool cl_mac_addr_compare(const u8 *addr1, const u8 *addr2)
{
	return !memcmp(addr1, addr2, ETH_ALEN);
}

static inline bool cl_mac_addr_is_zero(const u8 *addr)
{
	const u8 addr_zero[ETH_ALEN] = {0};

	return !memcmp(addr, addr_zero, ETH_ALEN);
}

static inline bool cl_mac_addr_is_broadcast(const u8 *addr)
{
	const u8 addr_bcast[ETH_ALEN] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};

	return !memcmp(addr, addr_bcast, ETH_ALEN);
}

static inline bool cl_mac_addr_parse_str(const u8 *str, u8 *addr)
{
	return (sscanf(str,
		       "%02hhx:%02hhx:%02hhx:%02hhx:%02hhx:%02hhx",
		       &addr[0],
		       &addr[1],
		       &addr[2],
		       &addr[3],
		       &addr[4],
		       &addr[5]) == ETH_ALEN);
}

static inline void cl_mac_addr_array_to_nxmac(u8 *array, u32 *low, u32 *high)
{
	/* Convert mac address (in a form of array) to a C nxmac form.
	 * Input: array - MAC address
	 * Output: low - array[0..3], high - array[4..5]
	 */
	u8 i;

	for (i = 0; i < 4; i++)
		*low |= (u32)(((u32)array[i]) << (i * 8));

	for (i = 0; i < 2; i++)
		*high |= (u32)(((u32)array[i + 4]) << (i * 8));
}

#endif /* CL_MAC_ADDR_H */

/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_IGMP_H
#define CL_IGMP_H

#include <linux/types.h>
#include "cl_hw.h"
#include "cl_vif.h"
#include "cl_vendor_cmd.h"

#define igmp_pr(format, level, ...) \
	do { \
		if ((level) <= cl_hw->igmp_debug_level) \
			pr_debug("[%s][%d] " format, __func__, __LINE__, ##__VA_ARGS__); \
	} while (0)

#define igmp_pr_verbose(...)       pr_debug(__VA_ARGS__)
#define igmp_pr_err(format, ...)   igmp_pr(format, DBG_LVL_ERROR, ##__VA_ARGS__)
#define igmp_pr_warn(format, ...)  igmp_pr(format, DBG_LVL_WARNING, ##__VA_ARGS__)
#define igmp_pr_trace(format, ...) igmp_pr(format, DBG_LVL_TRACE, ##__VA_ARGS__)
#define igmp_pr_info(format, ...)  igmp_pr(format, DBG_LVL_INFO, ##__VA_ARGS__)
#define igmp_pr_max(format, ...)   igmp_pr(format, DBG_LVL_MAX, ##__VA_ARGS__)

#define MCAST_FILTER_TABLE_MAX_LEN      64
#define MCAST_FILTER_HASH_TABLE_MAX_LEN (MCAST_FILTER_TABLE_MAX_LEN * 2)

#define MCAST_ADDR_HASH_KEY(addr) \
	(addr[0] ^ addr[1] ^ addr[2] ^ addr[3] ^ addr[4] ^ addr[5])
#define MCAST_ADDR_HASH_IDX(addr) \
	(MCAST_ADDR_HASH_KEY(addr) & (MCAST_FILTER_HASH_TABLE_MAX_LEN - 1))

#define IGMP_MAC_TABLE_ENTRY_AGEOUT_TIME (300 * HZ)

struct mcast_list_entry {
	struct mcast_list_entry *next;
};

struct mcast_member_list {
	struct mcast_list_entry *head;
	struct mcast_list_entry *tail;
	u8 size;
};

struct mcast_member_entry {
	struct mcast_member_entry *next;
	u8 mac_addr[ETH_ALEN];
	u32 last_time;
};

struct mcast_table_entry {
	unsigned long last_time;
	struct mcast_member_list member_list;
	struct mcast_table_entry *next;
	bool valid;
	u8 mac_addr[ETH_ALEN];
};

struct mcast_table {
	u8 size;
	struct mcast_table_entry *hash[MCAST_FILTER_HASH_TABLE_MAX_LEN];
	struct mcast_table_entry content[MCAST_FILTER_TABLE_MAX_LEN];
	spinlock_t lock;
	struct kmem_cache *members_cache;
};

void cl_igmp_mcast_table_init(struct cl_hw *cl_hw, struct cl_vif *cl_vif);
void cl_igmp_mcast_table_deinit(struct cl_hw *cl_hw, struct cl_vif *cl_vif);
struct mcast_table_entry *cl_igmp_mcast_table_lookup(struct cl_hw *cl_hw,
						     struct mcast_table *mcast_table,
						     u8 *mac_addr);
bool cl_igmp_mcast_table_insert_entry(struct cl_hw *cl_hw, struct mcast_table *mcast_table,
				      u8 *group_mac_addr, u8 *member_mac_addr);
void cl_igmp_mcast_table_delete_entry(struct cl_hw *cl_hw, struct mcast_table *mcast_table,
				      u8 *group_mac_addr, u8 *member_mac_addr);
int cl_igmp_cli(struct cl_hw *cl_hw, struct cl_vif *cl_vif, struct cli_params *cli_params);

#endif /* CL_IGMP_H */

// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_igmp.h"
#include "cl_mac_addr.h"
#include "cl_utils.h"

static inline void init_list(struct mcast_member_list *list)
{
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}

static inline void insert_tail_list(struct mcast_member_list *list,
				    struct mcast_list_entry *entry)
{
	entry->next = NULL;

	if (list->tail)
		list->tail->next = entry;
	else
		list->head = entry;

	list->tail = entry;
	list->size++;
}

static inline int get_list_size(struct mcast_member_list *list)
{
	return list->size;
}

static inline struct mcast_list_entry *del_list_entry(struct mcast_member_list *list,
						      struct mcast_list_entry *entry)
{
	struct mcast_list_entry *cur_entry;
	struct mcast_list_entry *prev_entry;

	if (!list->head)
		return NULL;

	if (entry == list->head) {
		cur_entry = list->head;
		list->head = cur_entry->next;

		if (!list->head)
			list->tail = NULL;

		list->size--;
		return cur_entry;
	}

	prev_entry = list->head;
	cur_entry = prev_entry->next;

	while (cur_entry) {
		if (entry == cur_entry) {
			prev_entry->next = cur_entry->next;

			if (entry == list->tail)
				list->tail = prev_entry;

			list->size--;
			break;
		}
		prev_entry = cur_entry;
		cur_entry = prev_entry->next;
	}

	return cur_entry;
}

static struct mcast_member_entry *insert_igmp_member(struct cl_hw *cl_hw,
						     struct mcast_table *mcast_table,
						     struct mcast_member_list *list,
						     u8 *member_mac_addr)
{
	struct mcast_member_entry *member_entry;

	if (!list) {
		igmp_pr_err("member list doesn't exist !!!\n");
		return NULL;
	}

	if (!member_mac_addr) {
		igmp_pr_err("invalid member !!!\n");

		return NULL;
	}

	member_entry = kmem_cache_alloc(mcast_table->members_cache, GFP_ATOMIC);
	if (member_entry) {
		memset(member_entry, 0, sizeof(struct mcast_member_entry));
		cl_mac_addr_copy(member_entry->mac_addr, member_mac_addr);

		insert_tail_list(list, (struct mcast_list_entry *)member_entry);
		igmp_pr_trace("add member %pM\n", member_entry->mac_addr);
	} else {
		igmp_pr_err("member allocation failed !!!\n");
	}

	return member_entry;
}

static bool delete_igmp_member(struct cl_hw *cl_hw, struct mcast_table *mcast_table,
			       struct mcast_member_list *list, u8 *member_mac_addr)
{
	struct mcast_member_entry *cur_entry;

	bool entry_deleted = false;

	if (!list) {
		igmp_pr_err("member list doesn't exist !!!\n");
		return true;
	}

	if (!list->head)
		return true;

	if (!member_mac_addr) {
		igmp_pr_err("invalid member !!!\n");
		return true;
	}

	cur_entry = (struct mcast_member_entry *)list->head;
	while (cur_entry) {
		struct mcast_member_entry *cur_entry_next = cur_entry->next;

		if (cl_mac_addr_compare(member_mac_addr, cur_entry->mac_addr)) {
			del_list_entry(list, (struct mcast_list_entry *)cur_entry);
			kmem_cache_free(mcast_table->members_cache, cur_entry);

			igmp_pr_trace("delete member %pM\n", member_mac_addr);
			entry_deleted = true;
			break;
		}
		cur_entry = cur_entry_next;
	}

	return entry_deleted;
}

static void delete_igmp_member_list(struct cl_hw *cl_hw,
				    struct mcast_table *mcast_table,
				    struct mcast_member_list *list)
{
	struct mcast_member_entry *cur_entry;
	struct mcast_member_entry *prev_entry;

	if (!list) {
		igmp_pr_err("member list doesn't exist !!!\n");
		return;
	}

	if (!list->head)
		return;

	cur_entry = (struct mcast_member_entry *)list->head;
	prev_entry = cur_entry;

	while (cur_entry) {
		del_list_entry(list, (struct mcast_list_entry *)cur_entry);
		prev_entry = cur_entry;
		cur_entry = cur_entry->next;
		kmem_cache_free(mcast_table->members_cache, prev_entry);
	}

	init_list(list);
}

static u8 igmp_member_cnt(struct cl_hw *cl_hw, struct mcast_member_list *list)
{
	if (!list) {
		igmp_pr_err("member list doesn't exist !!!\n");
		return 0;
	}

	return get_list_size(list);
}

static void mcast_table_cleanup(struct cl_hw *cl_hw, struct mcast_table *mcast_table)
{
	/* Delete all entries in IGMP table associated with net device */
	int i;

	if (!mcast_table)
		return;

	for (i = 0; i < MCAST_FILTER_TABLE_MAX_LEN; i++) {
		struct mcast_table_entry *entry = &mcast_table->content[i];

		if (entry->valid) {
			struct mcast_member_entry *cur_entry =
				(struct mcast_member_entry *)entry->member_list.head;

			while (cur_entry) {
				struct mcast_member_entry *cur_entry_next = cur_entry->next;

				cl_igmp_mcast_table_delete_entry(cl_hw,
								 mcast_table,
								 entry->mac_addr,
								 cur_entry->mac_addr);
				cur_entry = cur_entry_next;
			}
		}
	}
}

static int display_igmp_table(struct cl_hw *cl_hw, struct cl_vif *cl_vif)
{
	struct mcast_table *mcast_table = cl_vif->mcast_table;
	struct mcast_table_entry *entry = NULL;
	u32 entry_idx = 0;
	u32 row_idx = 0;
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;

	if (!mcast_table) {
		igmp_pr_err("Multicast filter table is not ready !!!\n");
		return 0;
	}

	if (mcast_table->size == 0)
		return 0;

	cl_snprintf(&buf, &len, &buf_size,
		    "Igmp Snoop Table:\n"
		    "==================================================\n"
		    "|     Mcast Addr    | Member |    STA Mac Addr   |\n"
		    "|                   | Count  |                   |\n"
		    "==================================================\n");

	spin_lock_bh(&mcast_table->lock);

	for (entry_idx = 0; entry_idx < MCAST_FILTER_TABLE_MAX_LEN; entry_idx++) {
		row_idx = 0;
		if (mcast_table->content[entry_idx].valid) {
			struct mcast_member_entry *member_entry = NULL;

			entry = &mcast_table->content[entry_idx];
			member_entry = (struct mcast_member_entry *)entry->member_list.head;

			cl_snprintf(&buf, &len, &buf_size,
				    "| %pM |%8u|", entry->mac_addr,
				    igmp_member_cnt(cl_hw, &entry->member_list));

			while (member_entry) {
				if (row_idx == 0)
					cl_snprintf(&buf, &len, &buf_size,
						    " %pM |\n", member_entry->mac_addr);
				else
					cl_snprintf(&buf, &len, &buf_size,
						    "|                            | %pM |\n",
						    member_entry->mac_addr);

				row_idx++;
				member_entry = member_entry->next;
			}
		}
	}

	cl_snprintf(&buf, &len, &buf_size,
		    "==================================================\n");
	spin_unlock_bh(&mcast_table->lock);

	err = cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);

	return err;
}

static int cl_igmp_cli_help(struct cl_hw *cl_hw)
{
	char *buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!buf)
		return -ENOMEM;

	snprintf(buf, PAGE_SIZE,
		 "igmp usage:\n"
		 "-d : Set debug level verbosity [level (default 1)]\n"
		 "-e : Disable/Enable M2U [0/1]\n"
		 "-s : Display IGMP table\n");

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

void cl_igmp_mcast_table_init(struct cl_hw *cl_hw, struct cl_vif *cl_vif)
{
	char members_cache_name[MODULE_NAME_LEN + 32] = {0};
	struct mcast_table *mcast_table = NULL;

	cl_vif->mcast_table = kzalloc(sizeof(*cl_vif->mcast_table), GFP_KERNEL);

	if (!cl_vif->mcast_table)
		return;

	mcast_table = cl_vif->mcast_table;
	spin_lock_init(&mcast_table->lock);
	snprintf(members_cache_name, sizeof(members_cache_name),
		 "%s_members_cache", THIS_MODULE->name);

	mcast_table->members_cache = kmem_cache_create(members_cache_name,
						       sizeof(struct mcast_member_entry),
						       0,
						       (SLAB_HWCACHE_ALIGN | SLAB_PANIC),
						       NULL);

	if (!mcast_table->members_cache) {
		igmp_pr_err("members_cache allocation failed !!!\n");
		return;
	}

	igmp_pr_trace("Allocate mcast_table for %s\n", cl_vif->dev->name);
}

void cl_igmp_mcast_table_deinit(struct cl_hw *cl_hw, struct cl_vif *cl_vif)
{
	struct mcast_table *mcast_table = cl_vif->mcast_table;

	if (mcast_table) {
		igmp_pr_trace("Free mcast_table for %s\n", cl_vif->dev->name);
		mcast_table_cleanup(cl_hw, mcast_table);
		kmem_cache_destroy(mcast_table->members_cache);
		kfree(mcast_table);
		cl_vif->mcast_table = NULL;
	}
}

struct mcast_table_entry *cl_igmp_mcast_table_lookup(struct cl_hw *cl_hw,
						     struct mcast_table *mcast_table,
						     u8 *mac_addr)
{
	/*
	 * Look up the Multicast Group MAC address in the IGMP table.
	 * Return NULL if not found.
	 */
	u8 hash_idx;
	struct mcast_table_entry *entry = NULL, *prev_entry = NULL;

	if (!mcast_table) {
		igmp_pr_err("mcast_table is NULL !!!\n");
		return NULL;
	}

	spin_lock_bh(&mcast_table->lock);

	hash_idx = MCAST_ADDR_HASH_IDX(mac_addr);
	entry = mcast_table->hash[hash_idx];
	prev_entry = entry;

	while (entry && entry->valid) {
		if (cl_mac_addr_compare(entry->mac_addr, mac_addr)) {
			entry->last_time = jiffies;
			break;
		}

		prev_entry = entry;
		entry = entry->next;
	}

	spin_unlock_bh(&mcast_table->lock);

	return entry;
}

bool cl_igmp_mcast_table_insert_entry(struct cl_hw *cl_hw, struct mcast_table *mcast_table,
				      u8 *group_mac_addr, u8 *member_mac_addr)
{
	/* Add and new entry into MAC table */
	u8 hash_idx;
	int i;
	struct mcast_table_entry *group_entry = NULL, *curr_entry, *prev_entry;
	struct mcast_member_entry *member_entry;

	if (!mcast_table) {
		igmp_pr_err("Multicast filter table is not ready !!!\n");
		return false;
	}

	/* If FULL, return */
	if (mcast_table->size >= MCAST_FILTER_TABLE_MAX_LEN) {
		igmp_pr_err("Multicast filter table is full. max-entries = %d\n",
			    MCAST_FILTER_TABLE_MAX_LEN);
		return false;
	}

	/* Check if the mcast group is in the table already or not. */
	group_entry = cl_igmp_mcast_table_lookup(cl_hw, mcast_table, group_mac_addr);
	if (group_entry) {
		/* Doesn't indicate member mac address. */
		if (!member_mac_addr)
			return false;

		member_entry = (struct mcast_member_entry *)group_entry->member_list.head;

		while (member_entry) {
			if (cl_mac_addr_compare(member_mac_addr, member_entry->mac_addr)) {
				igmp_pr_trace("member_mac_addr %pM found in mcast group %pM - "
					      "update last_time\n",
					      member_mac_addr, group_mac_addr);

				/*
				 * Update the current timestamp - this is the last time
				 * there was an indication this member is alive.
				 */
				member_entry->last_time = jiffies;
				return true;
			}
			member_entry = member_entry->next;
		}
	}

	spin_lock_bh(&mcast_table->lock);

	/* The multicast entry already exist but doesn't include the member yet. */
	if (group_entry && member_mac_addr) {
		member_entry = insert_igmp_member(cl_hw, mcast_table,
						  &group_entry->member_list,
						  member_mac_addr);
		spin_unlock_bh(&mcast_table->lock);
		group_entry->last_time = jiffies;
		return true;
	}

	/* Allocate one MAC entry */
	for (i = 0; i < MCAST_FILTER_TABLE_MAX_LEN; i++) {
		/* Pick up the first available vacancy */
		group_entry = &mcast_table->content[i];

		if (group_entry->valid &&
		    ((jiffies - group_entry->last_time) > IGMP_MAC_TABLE_ENTRY_AGEOUT_TIME)) {
			struct mcast_table_entry *hash_entry;

			hash_idx = MCAST_ADDR_HASH_IDX(group_entry->mac_addr);
			hash_entry = mcast_table->hash[hash_idx];

			if (cl_mac_addr_compare(group_entry->mac_addr, hash_entry->mac_addr)) {
				mcast_table->hash[hash_idx] = hash_entry->next;
				mcast_table->size--;
				igmp_pr_trace("group_entry %pM aged out\n", group_entry->mac_addr);
			} else {
				while (hash_entry->next) {
					prev_entry = hash_entry;
					hash_entry = hash_entry->next;
					if (cl_mac_addr_compare(group_entry->mac_addr,
								hash_entry->mac_addr)) {
						prev_entry->next = hash_entry->next;
						mcast_table->size--;
						igmp_pr_trace("group_entry %pM aged out\n",
							      group_entry->mac_addr);
						break;
					}
				}
			}
			group_entry->valid = false;
			delete_igmp_member_list(cl_hw, mcast_table, &group_entry->member_list);
		}

		if (!group_entry->valid) {
			memset(group_entry, 0, sizeof(struct mcast_table_entry));
			group_entry->valid = true;
			cl_mac_addr_copy(group_entry->mac_addr, group_mac_addr);
			group_entry->last_time = jiffies;
			init_list(&group_entry->member_list);
			if (member_mac_addr) {
				insert_igmp_member(cl_hw, mcast_table,
						   &group_entry->member_list, member_mac_addr);
				mcast_table->size++;
				igmp_pr_trace("add new group %pM mcast_table->size=%u\n",
					      group_entry->mac_addr, mcast_table->size);
			}
			break;
		}
	}

	/* Add this MAC entry into HASH table */
	if (group_entry) {
		hash_idx = MCAST_ADDR_HASH_IDX(group_mac_addr);
		if (!mcast_table->hash[hash_idx]) {
			mcast_table->hash[hash_idx] = group_entry;
		} else {
			curr_entry = mcast_table->hash[hash_idx];
			while (curr_entry->next)
				curr_entry = curr_entry->next;

			curr_entry->next = group_entry;
		}
	}

	spin_unlock_bh(&mcast_table->lock);
	return true;
}

void cl_igmp_mcast_table_delete_entry(struct cl_hw *cl_hw,
				      struct mcast_table *mcast_table,
				      u8 *group_mac_addr,
				      u8 *member_mac_addr)
{
	/* Delete a specified client from MAC table */
	u8 hash_idx;
	struct mcast_table_entry *entry, *prev_entry;
	bool delete_member = true;

	if (!mcast_table) {
		igmp_pr_err("Multicast filter table is not ready !!!\n");
		return;
	}

	spin_lock_bh(&mcast_table->lock);

	hash_idx = MCAST_ADDR_HASH_IDX(group_mac_addr);
	entry = mcast_table->hash[hash_idx];
	prev_entry = entry;

	while (entry && entry->valid) {
		if (cl_mac_addr_compare(entry->mac_addr, group_mac_addr))
			break;

		prev_entry = entry;
		entry = entry->next;
	}

	/* Check if the mcast group is in the table already or not. */
	if (entry && member_mac_addr) {
		delete_member = delete_igmp_member(cl_hw,
						   mcast_table,
						   &entry->member_list,
						   member_mac_addr);

		if (igmp_member_cnt(cl_hw, &entry->member_list) > 0) {
			spin_unlock_bh(&mcast_table->lock);
			return;
		}
	}

	if (entry && delete_member) {
		if (entry == mcast_table->hash[hash_idx]) {
			mcast_table->hash[hash_idx] = entry->next;
			delete_igmp_member_list(cl_hw, mcast_table, &entry->member_list);
			memset(entry, 0, sizeof(struct mcast_table_entry));
			mcast_table->size--;
			igmp_pr_trace("member_mac_addr %pM found in mcast group %pM - delete it\n",
				      member_mac_addr, group_mac_addr);
		} else {
			prev_entry->next = entry->next;
			delete_igmp_member_list(cl_hw, mcast_table, &entry->member_list);
			memset(entry, 0, sizeof(struct mcast_table_entry));
			mcast_table->size--;
			igmp_pr_trace("member_mac_addr %pM found in mcast group %pM - delete it\n",
				      member_mac_addr, group_mac_addr);
		}
	} else {
		igmp_pr_trace("mcast group %pM doesn't exist\n", group_mac_addr);
	}

	spin_unlock_bh(&mcast_table->lock);
}

int cl_igmp_cli(struct cl_hw *cl_hw, struct cl_vif *cl_vif,
		struct cli_params *cli_params)
{
	s32 *params = cli_params->params;

	switch (cli_params->option) {
	case 'd':
		if (cli_params->num_params != 1)
			goto err_num_of_arg;

		cl_hw->igmp_debug_level = params[0];
		igmp_pr_err("igmp_debug_level = %u", cl_hw->igmp_debug_level);
		return 0;
	case 'e':
		if (cli_params->num_params != 1)
			goto err_num_of_arg;

		cl_hw->conf->ce_m2u_enable = params[0];
		igmp_pr_err("ce_m2u_enable = %u", cl_hw->conf->ce_m2u_enable);
		return 0;
	case 's':
		return display_igmp_table(cl_hw, cl_vif);
	case '?':
		return cl_igmp_cli_help(cl_hw);
	default:
		igmp_pr_err("Illegal option (%c) - try '?' for help\n",
			    cli_params->option);
		return 0;
	}

err_num_of_arg:
	igmp_pr_err("Wrong number of arguments\n");

	return 0;
}


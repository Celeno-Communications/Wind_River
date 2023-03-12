// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_sw_txhdr.h"
#include "cl_bsr.h"

static int cl_sw_txhdr_init_pool(struct cl_hw *cl_hw, u16 sw_txhdr_pool)
{
	u16 i = 0;
	u32 sw_txhdr_pool_size = sw_txhdr_pool * sizeof(struct cl_sw_txhdr);
	struct cl_sw_txhdr *sw_txhdr;

	INIT_LIST_HEAD(&cl_hw->head_sw_txhdr_pool);
	spin_lock_init(&cl_hw->lock_sw_txhdr_pool);

	for (i = 0; i < sw_txhdr_pool; i++) {
		sw_txhdr = kzalloc(sizeof(*sw_txhdr), GFP_ATOMIC);

		if (unlikely(!sw_txhdr)) {
			cl_dbg_verbose(cl_hw, "sw_txhdr NULL\n");
			return -1;
		}

		list_add(&sw_txhdr->list_pool, &cl_hw->head_sw_txhdr_pool);
	}

	cl_dbg_verbose(cl_hw, " - pool %u, size %u\n", sw_txhdr_pool, sw_txhdr_pool_size);

	return 0;
}

static int cl_sw_txhdr_init_cache(struct cl_hw *cl_hw)
{
	char sw_txhdr_cache_name[MODULE_NAME_LEN + 32] = {0};

	snprintf(sw_txhdr_cache_name, sizeof(sw_txhdr_cache_name),
		 "%s_sw_txhdr_cache", THIS_MODULE->name);

	cl_hw->sw_txhdr_cache = kmem_cache_create(sw_txhdr_cache_name,
						  sizeof(struct cl_sw_txhdr),
						  0,
						  (SLAB_HWCACHE_ALIGN | SLAB_PANIC),
						  NULL);

	if (!cl_hw->sw_txhdr_cache) {
		cl_dbg_verbose(cl_hw, "sw_txhdr_cache NULL\n");
		return -1;
	}

	return 0;
}

int cl_sw_txhdr_init(struct cl_hw *cl_hw)
{
	u16 sw_txhdr_pool = cl_hw->conf->ci_sw_txhdr_pool;

	if (sw_txhdr_pool)
		return cl_sw_txhdr_init_pool(cl_hw, sw_txhdr_pool);
	else
		return cl_sw_txhdr_init_cache(cl_hw);
}

static void cl_sw_txhdr_deinit_pool(struct cl_hw *cl_hw)
{
	struct cl_sw_txhdr *sw_txhdr, *tmp;

	list_for_each_entry_safe(sw_txhdr, tmp, &cl_hw->head_sw_txhdr_pool, list_pool) {
		list_del(&sw_txhdr->list_pool);
		kfree(sw_txhdr);
	}
}

static void cl_sw_txhdr_deinit_cache(struct cl_hw *cl_hw)
{
	kmem_cache_destroy(cl_hw->sw_txhdr_cache);
}

void cl_sw_txhdr_deinit(struct cl_hw *cl_hw)
{
	if (cl_hw->conf->ci_sw_txhdr_pool)
		cl_sw_txhdr_deinit_pool(cl_hw);
	else
		cl_sw_txhdr_deinit_cache(cl_hw);
}

static inline struct cl_sw_txhdr *cl_sw_txhdr_alloc_pool(struct cl_hw *cl_hw)
{
	unsigned long flags;
	struct cl_sw_txhdr *sw_txhdr = NULL;

	spin_lock_irqsave(&cl_hw->lock_sw_txhdr_pool, flags);
	sw_txhdr = list_first_entry_or_null(&cl_hw->head_sw_txhdr_pool,
					    struct cl_sw_txhdr, list_pool);

	if (sw_txhdr) {
		list_del(&sw_txhdr->list_pool);
		spin_unlock_irqrestore(&cl_hw->lock_sw_txhdr_pool, flags);
		return sw_txhdr;
	}

	spin_unlock_irqrestore(&cl_hw->lock_sw_txhdr_pool, flags);
	return NULL;
}

static inline struct cl_sw_txhdr *cl_sw_txhdr_alloc_cache(struct cl_hw *cl_hw)
{
	return kmem_cache_alloc(cl_hw->sw_txhdr_cache, GFP_ATOMIC);
}

struct cl_sw_txhdr *cl_sw_txhdr_alloc(struct cl_hw *cl_hw)
{
	if (cl_hw->conf->ci_sw_txhdr_pool)
		return cl_sw_txhdr_alloc_pool(cl_hw);
	else
		return cl_sw_txhdr_alloc_cache(cl_hw);
}

static inline void cl_sw_txhdr_free_pool(struct cl_hw *cl_hw, struct cl_sw_txhdr *sw_txhdr)
{
	unsigned long flags;

	spin_lock_irqsave(&cl_hw->lock_sw_txhdr_pool, flags);
	list_add_tail(&sw_txhdr->list_pool, &cl_hw->head_sw_txhdr_pool);
	spin_unlock_irqrestore(&cl_hw->lock_sw_txhdr_pool, flags);
}

static inline void cl_sw_txhdr_free_cache(struct cl_hw *cl_hw, struct cl_sw_txhdr *sw_txhdr)
{
	kmem_cache_free(cl_hw->sw_txhdr_cache, sw_txhdr);
}

void cl_sw_txhdr_free(struct cl_hw *cl_hw, struct cl_sw_txhdr *sw_txhdr)
{
	cl_bsr_counters_dec(cl_hw, sw_txhdr);

	if (cl_hw->conf->ci_sw_txhdr_pool)
		cl_sw_txhdr_free_pool(cl_hw, sw_txhdr);
	else
		cl_sw_txhdr_free_cache(cl_hw, sw_txhdr);
}

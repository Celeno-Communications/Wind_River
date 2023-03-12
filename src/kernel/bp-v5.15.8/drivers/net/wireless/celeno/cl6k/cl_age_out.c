// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_age_out.h"
#include "cl_vif.h"
#include "cl_sta.h"
#include "cl_mac_addr.h"
#include "cl_netlink.h"

struct cl_ageout_work {
	struct work_struct ws;
	struct cl_hw *cl_hw;
	struct net_device *dev;
	u8 mac_addr[ETH_ALEN];
	u8 bss_addr[ETH_ALEN];
};

static void cl_age_out_handler(struct work_struct *ws)
{
	struct cl_ageout_work *ageout_work = container_of(ws, struct cl_ageout_work, ws);
	struct cl_hw *cl_hw = ageout_work->cl_hw;
	struct cl_vif *cl_vif, *tmp;

	if (!test_bit(CL_DEV_STARTED, &cl_hw->drv_flags) ||
	    test_bit(CL_DEV_HW_RESTART, &cl_hw->drv_flags) ||
	    test_bit(CL_DEV_SW_RESTART, &cl_hw->drv_flags))
		goto free_wk;

	pr_debug("BSS %pM - Station %pM ageout! Sending disassoc!\n",
		 ageout_work->bss_addr, ageout_work->mac_addr);

	list_for_each_entry_safe(cl_vif, tmp, &cl_hw->vif_db.head, list) {
		if (ether_addr_equal(cl_vif->vif->addr, ageout_work->bss_addr)) {
			cl_netlink_send_event_disassoc(cl_vif, ageout_work->mac_addr);
			break;
		}
	}

free_wk:
	kfree((void *)ageout_work);
}

static void cl_age_out_maintenance_sta(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	if (cl_sta->is_dummy)
		return;

	if (cl_sta->cl_vif->vif->type == NL80211_IFTYPE_STATION)
		return;

	/* Ageout */
	cl_sta->age_out_counter++;

	/* Disassoc sta in case its inactive for X seconds. (NVRAM parameter: ce_sta_age_out) */
	if (cl_sta->age_out_counter > cl_hw->conf->ce_sta_age_out) {
		struct cl_ageout_work *ageout_work =
			kzalloc(sizeof(*ageout_work), GFP_KERNEL);

		if (!ageout_work)
			return;

		INIT_WORK(&ageout_work->ws, cl_age_out_handler);
		ageout_work->cl_hw = cl_hw;
		ageout_work->dev = cl_sta->cl_vif->dev;
		cl_mac_addr_copy(ageout_work->mac_addr, cl_sta->addr);
		cl_mac_addr_copy(ageout_work->bss_addr, cl_sta->cl_vif->vif->addr);

		/* Reset counter so that work queue will be scheduled once */
		cl_sta->age_out_counter = 0;

		/* Schedule work queue to sends disassoc to all stations */
		queue_work(cl_hw->ageout_workqueue, (struct work_struct *)(&ageout_work->ws));
	}
}

void cl_age_out_init(struct cl_hw *cl_hw)
{
	cl_hw->ageout_workqueue = create_workqueue("ageout_workqueue");
}

void cl_age_out_close(struct cl_hw *cl_hw)
{
	if (cl_hw->ageout_workqueue) {
		destroy_workqueue(cl_hw->ageout_workqueue);
		cl_hw->ageout_workqueue = NULL;
	}
}

void cl_age_out_reset_counter(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	cl_sta->age_out_counter = 0;
}

void cl_age_out_maintenance(struct cl_hw *cl_hw)
{
	cl_sta_loop_safe(cl_hw, cl_age_out_maintenance_sta);
}

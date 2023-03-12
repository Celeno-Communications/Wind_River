// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include <linux/kthread.h>
#include <linux/jiffies.h>
#include "cl_radio.h"
#include "cl_vendor_cmd.h"
#include "cl_msg_tx.h"
#include "cl_vif.h"
#include "cl_sta.h"

static int cl_radio_off_kthread(void *arg)
{
	struct cl_hw *cl_hw = (struct cl_hw *)arg;
	struct cl_vif *cl_vif, *tmp;

	cl_sta_disassociate_all(cl_hw);

	cl_dbg_verbose(cl_hw, "Waiting for stations to disconnect\n");

	if (wait_event_timeout(cl_hw->radio_wait_queue,
			       cl_sta_num_bh(cl_hw) == 0,
			       msecs_to_jiffies(5000)) == 0) {
		cl_dbg_verbose(cl_hw,
			       "Failed to disconnect stations. %u stations still remaining\n",
			       cl_sta_num_bh(cl_hw));
		return 1;
	}

	cl_dbg_trace(cl_hw, "Stopping queues ...\n");

	list_for_each_entry_safe(cl_vif, tmp, &cl_hw->vif_db.head, list) {
		cl_vif->tx_en = false;
		cl_dbg_verbose(cl_hw, "Radio OFF vif_index = %u\n",
			       cl_vif->vif_index);
	}

	cl_msg_tx_set_idle(cl_hw, MAC_IDLE_SYNC);

	cl_dbg_trace(cl_hw, "Radio shut down successfully\n");

	cl_hw->radio_status = RADIO_STATUS_OFF;
	atomic_set(&cl_hw->radio_lock, 0);

	return 0;
}

static int cl_radio_off(struct cl_hw *cl_hw)
{
	struct task_struct *k;

	if (cl_hw->radio_status != RADIO_STATUS_ON ||
	    atomic_xchg(&cl_hw->radio_lock, 1))
		return 1;

	cl_hw->radio_status = RADIO_STATUS_GOING_DOWN;

	/* Relegate the job to a kthread to free the system call. */
	k = kthread_run(cl_radio_off_kthread, cl_hw, "cl_radio_off_kthread");
	if (IS_ERR(k))
		cl_dbg_verbose(cl_hw,
			       "Error: failed to run cl_radio_off_kthread\n");
	return 0;
}

static void _cl_radio_on(struct cl_hw *cl_hw)
{
	struct cl_vif *cl_vif, *tmp;

	list_for_each_entry_safe(cl_vif, tmp, &cl_hw->vif_db.head, list) {
		if (cl_vif->vif->type == NL80211_IFTYPE_AP) {
			if (cl_hw->iface_conf == CL_IFCONF_REPEATER &&
			    !test_bit(CL_DEV_REPEATER, &cl_hw->drv_flags))
				continue;
			if (cl_hw->iface_conf == CL_IFCONF_MESH_AP &&
			    !test_bit(CL_DEV_MESH_AP, &cl_hw->drv_flags))
				continue;
		}

		cl_vif->tx_en = true;
		cl_dbg_verbose(cl_hw, "Radio ON vif=%u\n", cl_vif->vif_index);
	}

	cl_msg_tx_set_idle(cl_hw, MAC_ACTIVE);

	cl_dbg_verbose(cl_hw, "Radio has been started\n");

	cl_hw->radio_status = RADIO_STATUS_ON;
	atomic_set(&cl_hw->radio_lock, 0);
}

int cl_radio_on(struct cl_hw *cl_hw)
{
	if (cl_hw->radio_status != RADIO_STATUS_OFF ||
	    atomic_xchg(&cl_hw->radio_lock, 1))
		return 1;

	_cl_radio_on(cl_hw);

	return 0;
}

void cl_radio_off_chip(struct cl_chip *chip)
{
	if (cl_chip_is_tcv0_enabled(chip))
		cl_radio_off(chip->cl_hw_tcv0);
}

void cl_radio_on_chip(struct cl_chip *chip)
{
	if (cl_chip_is_tcv0_enabled(chip))
		cl_radio_on(chip->cl_hw_tcv0);
}

bool cl_radio_is_off(struct cl_hw *cl_hw)
{
	return cl_hw->radio_status == RADIO_STATUS_OFF;
}

bool cl_radio_is_on(struct cl_hw *cl_hw)
{
	return cl_hw->radio_status == RADIO_STATUS_ON;
}

bool cl_radio_is_going_down(struct cl_hw *cl_hw)
{
	return cl_hw->radio_status == RADIO_STATUS_GOING_DOWN;
}

int cl_radio_cli(struct cl_hw *cl_hw, bool radio_on)
{
	if (radio_on)
		cl_radio_on(cl_hw);
	else
		cl_radio_off(cl_hw);

	return 0;
}

void cl_radio_off_wake_up(struct cl_hw *cl_hw)
{
	wake_up(&cl_hw->radio_wait_queue);
}

// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "file.h"
#include "phy.h"
#include "cl_recovery.h"
#include "cl_rx_amsdu.h"
#include "cl_main.h"
#include "cl_phy.h"
#include "cl_vif.h"
#include "cl_maintenance.h"
#include "cl_temperature.h"
#include "cl_tx_inject.h"
#include "cl_dyn_mcast_rate.h"
#include "cl_dyn_bcast_rate.h"
#include "cl_vns.h"
#include "cl_radio.h"
#include "cl_wrs_api.h"
#include "cl_config.h"
#include "cl_msg_tx.h"
#include "cl_irq.h"
#include "chip_ops.h"
#include "cl_usb.h"

struct cl_recovery_work {
	struct work_struct ws;
	struct cl_hw *cl_hw;
	int reason;
};

static void cl_recovery_ce_host_reload(struct cl_hw *cl_hw, int reason)
{
	char cfg_dir_env[CL_PATH_MAX];
	char install_dir_env[CL_PATH_MAX];
	char cmd[U8_MAX];
	char *argv[4] = { "/bin/sh", "-c", cmd, NULL };
	char *envp[5] = { "HOME=/", "PATH=/home:/sbin:/bin:/usr/sbin:/usr/bin",
		cfg_dir_env, install_dir_env, NULL };

	cl_hw->wd_restart_drv = true;

	snprintf(install_dir_env, sizeof(install_dir_env), "cl_install_dir=%s", cl_install_dir);
	snprintf(cfg_dir_env, sizeof(cfg_dir_env), "cl_cfg_dir=%s", cl_config_dir);
	snprintf(cmd, sizeof(cmd), "%s/scripts/ce_host.sh reload > /dev/null 2>&1",
		 cl_install_dir);
	cl_dbg_verbose(cl_hw, "%s\n", cmd);

	call_usermodehelper(argv[0], argv, envp, UMH_NO_WAIT);
	/*
	 * DON'T REMOVE THIS LINE.
	 */
	cl_dbg_verbose(cl_hw, "\n");
}

#define RECOVERY_POLL_TIMEOUT 6

static void cl_recovery_poll_completion(struct cl_hw *cl_hw)
{
	u8 cntr = 0;

	while (test_bit(CL_DEV_SW_RESTART, &cl_hw->drv_flags)) {
		msleep(1000);

		if (++cntr == RECOVERY_POLL_TIMEOUT) {
			cl_recovery_ce_host_reload(cl_hw, RECOVERY_DRV_FAILED);
			break;
		}
	}
}

static void cl_recovery_start_hw(struct cl_hw *cl_hw)
{
	clear_bit(CL_DEV_STOP_HW, &cl_hw->drv_flags);

	/* Restart MAC firmware... */
	if (cl_main_on(cl_hw)) {
		cl_dbg_err(cl_hw, "Couldn't turn platform on .. aborting\n");
		return;
	}

	if (cl_msg_tx_reset(cl_hw)) {
		cl_dbg_err(cl_hw, "Failed to send firmware reset .. aborting\n");
		return;
	}

	set_bit(CL_DEV_SW_RESTART, &cl_hw->drv_flags);
	clear_bit(CL_DEV_HW_RESTART, &cl_hw->drv_flags);

	/* Hand over to mac80211 from here */
	ieee80211_restart_hw(cl_hw->hw);

	cl_recovery_poll_completion(cl_hw);
}

static void cl_recovery_stop_hw(struct cl_hw *cl_hw)
{
	struct cl_chip *chip = cl_hw->chip;
	/* Start recovery process */
	cl_hw->recovery_db.in_recovery = true;

	clear_bit(CL_DEV_STARTED, &cl_hw->drv_flags);
	set_bit(CL_DEV_HW_RESTART, &cl_hw->drv_flags);
	set_bit(CL_DEV_STOP_HW, &cl_hw->drv_flags);
	/* Disable interrupts */
	if (IS_PCI_BUS_TYPE(chip)) {
		cl_irq_disable(cl_hw, cl_hw->ipc_e2a_irq.all);
	} else {
		usb_deinit_app_eps(chip);
		chip_ops_usb_set_alternate(chip, USB_WIFI_IF_NUM, ALT_STOP);
	}
	cl_tx_inject_stop_in_recovery(cl_hw);
	cl_maintenance_deinit(cl_hw);

	ieee80211_stop_queues(cl_hw->hw);

	mutex_lock(&cl_hw->dbginfo.mutex);

	cl_main_off(cl_hw);

	cl_hw->fw_active = false;
	cl_hw->fw_send_start = false;

	cl_hw->debugfs.trace_prst = false;
	mutex_unlock(&cl_hw->dbginfo.mutex);

	/* Reset it so MM_SET_FILTER_REQ will be called during the recovery */
	cl_hw->rx_filter = 0;

	/*
	 * Reset channel/frequency parameters so that cl_msg_tx_set_channel()
	 * will not be skipped in cl_ops_config()
	 */
	cl_hw->channel = 0;
	cl_hw->primary_freq = 0;
	cl_hw->center_freq = 0;
}

static void cl_recovery_process(struct cl_hw *cl_hw)
{
	int ret;
	struct cl_chip *chip = cl_hw->chip;

	cl_dbg_verbose(cl_hw, "Start\n");

	cl_recovery_stop_hw(cl_hw);

	if (chip->conf->ci_phy_dev != PHY_DEV_DUMMY) {
		cl_phy_reset(chip);

		ret = cl_phy_load_recovery(cl_hw);
		if (ret) {
			cl_dbg_err(cl_hw, "cl_phy_load_recovery failed %d\n", ret);
			return;
		}
	}

	cl_recovery_start_hw(cl_hw);
}

static void cl_recovery_handler(struct cl_hw *cl_hw, int reason)
{
	unsigned long recovery_diff = jiffies_to_msecs(jiffies - cl_hw->recovery_db.last_restart);

	cl_hw->recovery_db.restart_cnt++;

	if (recovery_diff > cl_hw->conf->ce_fw_watchdog_limit_time) {
		cl_hw->recovery_db.restart_cnt = 1;
	} else if (cl_hw->recovery_db.restart_cnt > cl_hw->conf->ce_fw_watchdog_limit_count) {
		cl_dbg_verbose(cl_hw, "Too many failures... aborting\n");
		cl_hw->conf->ce_fw_watchdog_mode = FW_WD_DISABLE;
		return;
	}

	cl_hw->recovery_db.last_restart = jiffies;

	/* Count recovery attempts for statistics */
	cl_hw->fw_recovery_cntr++;
	cl_dbg_trace(cl_hw, "Recovering from firmware failure, attempt #%i\n",
		     cl_hw->fw_recovery_cntr);

	cl_recovery_process(cl_hw);
}

static void cl_recovery_work_do(struct work_struct *ws)
{
	/* Worker for restarting hw. */
	struct cl_recovery_work *recovery_work = container_of(ws, struct cl_recovery_work, ws);

	recovery_work->cl_hw->assert_info.restart_sched = false;
	cl_recovery_handler(recovery_work->cl_hw, recovery_work->reason);
	kfree(recovery_work);
}

static void cl_recovery_work_sched(struct cl_hw *cl_hw, int reason)
{
	/*
	 * Schedule work to restart device and firmware
	 * This is scheduled when driver detects hw assert storm.
	 */
	struct cl_recovery_work *recovery_work;

	if (cl_hw->is_stop_context) {
		cl_dbg_warn(cl_hw, "Skip recovery - Running down!\n");
		return;
	}

	/* If restart is already scheduled - exit */
	if (cl_hw->assert_info.restart_sched)
		return;

	cl_hw->assert_info.restart_sched = true;

	/* Recovery_work will be freed by cl_recovery_work_do */
	recovery_work = kzalloc(sizeof(*recovery_work), GFP_ATOMIC);

	if (!recovery_work)
		return;

	INIT_WORK(&recovery_work->ws, cl_recovery_work_do);
	recovery_work->cl_hw = cl_hw;
	recovery_work->reason = reason;

	queue_work(cl_hw->drv_workqueue, &recovery_work->ws);
}

bool cl_recovery_in_progress(struct cl_hw *cl_hw)
{
	return cl_hw->recovery_db.in_recovery;
}

void cl_recovery_reconfig_complete(struct cl_hw *cl_hw)
{
	clear_bit(CL_DEV_SW_RESTART, &cl_hw->drv_flags);

	/* Multicast/Broadcast rate recovery */
	cl_dyn_mcast_rate_recovery(cl_hw);
	cl_dyn_bcast_rate_recovery(cl_hw);

	/* VNS recovery */
	cl_vns_recovery(cl_hw);

	/* Restore EDCA configuration */
	cl_edca_recovery(cl_hw);

	/* Temperature  recovery */
	cl_temperature_recovery(cl_hw);

	/* Sounding recovery */
	cl_sounding_recovery(cl_hw);

	/*
	 * Update Tx params for all connected stations to sync firmware after the
	 * recovery process.
	 */
	cl_wrs_api_recovery(cl_hw);

	/* Enable maintenance timers back */
	cl_maintenance_start(cl_hw);

	if (cl_radio_is_on(cl_hw)) {
		/*
		 * Rearm last_tbtt_ind so that error message will
		 * not be printed in cl_irq_status_tbtt()
		 */
		cl_hw->last_tbtt_irq = jiffies;

		cl_msg_tx_set_idle(cl_hw, MAC_ACTIVE);
	}

	cl_hw->recovery_db.in_recovery = false;

	pr_debug("cl_recovery: complete\n");

	cl_rx_post_recovery(cl_hw);
}

void cl_recovery_start(struct cl_hw *cl_hw, int reason)
{
	/* Prevent new messages to be sent until firmware has recovered */
	set_bit(CL_DEV_FW_ERROR, &cl_hw->drv_flags);

	switch (cl_hw->conf->ce_fw_watchdog_mode) {
	case FW_WD_DISABLE:
		cl_dbg_info(cl_hw, "Skip recovery - Watchdog is off!\n");
		break;

	case FW_WD_INTERNAL_RECOVERY:
		cl_recovery_work_sched(cl_hw, reason);
		break;

	case FW_WD_DRV_RELOAD:
		cl_recovery_ce_host_reload(cl_hw, reason);
		break;

	default:
		break;
	}
}

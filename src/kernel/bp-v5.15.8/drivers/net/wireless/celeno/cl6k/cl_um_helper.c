// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_um_helper.h"
#include "cl_recovery.h"
#include "cl_mib.h"
#include "cl_lcu.h"
#include "chip.h"
#include "file.h"
#include "cl_config.h"
#include "cl_ipc.h"
#include "cl_usb.h"

static int cl_um_helper_call(struct cl_debugfs *debugfs, const char *cmd)
{
	char ce_env_install[CL_PATH_MAX];
	char ce_env_cfg[CL_PATH_MAX];
	char *envp[] = {"PATH=/sbin:/usr/sbin:/bin:/usr/bin", ce_env_install, ce_env_cfg, NULL};
	char **argv;
	int argc, ret;

	snprintf(ce_env_install, sizeof(ce_env_install), "cl_install_dir=%s", cl_install_dir);
	snprintf(ce_env_cfg, sizeof(ce_env_cfg), "cl_cfg_dir=%s", cl_config_dir);

	if (!debugfs->dir)
		return 0;

	cmd = cmd ?: debugfs->helper_cmd;
	if (!strlen(cmd))
		return 0;

	argv = argv_split(in_interrupt() ? GFP_ATOMIC : GFP_KERNEL, cmd, &argc);
	if (!argc)
		return PTR_ERR(argv);

	ret = call_usermodehelper(argv[0], argv, envp, UMH_WAIT_PROC | UMH_KILLABLE);
	if (ret)
		argv_free(argv);

	return ret;
}

static void cl_um_helper_done(struct cl_hw *cl_hw)
{
	/* Function called once UMH script execution is finished */

	if (!test_bit(CL_DEV_STARTED, &cl_hw->drv_flags))
		return;

	/*
	 * Assuming firmware cannot request next dump before we release the host buffer
	 *  so no need to sync the following against error_ind()
	 */
	cl_hw->debugfs.trace_prst = false;
	if (IS_PCI_BUS_TYPE(cl_hw->chip))
		cl_ipc_dbginfobuf_push(cl_hw->ipc_env, cl_hw->dbginfo.dma_addr);
	else
		cl_usb_dbginfobuf_push(cl_hw);
	if (cl_hw->dbginfo.buf->u.dump.general_data.error_type == DBG_ERROR_FATAL ||
	    cl_hw->assert_info.restart_needed) {
		cl_dbg_err(cl_hw, "Starting recovery due to unrecoverable assert\n");
		cl_recovery_start(cl_hw, RECOVERY_UNRECOVERABLE_ASSERT);
	}
}

static void cl_um_helper_work(struct work_struct *ws)
{
	struct cl_debugfs *debugfs = container_of(ws, struct cl_debugfs, helper_work);
	struct cl_hw *cl_hw = container_of(debugfs, struct cl_hw, debugfs);
	unsigned long flags;

	cl_hw->umh_last_call_timestamp = jiffies;

	if (cl_lcu_ela_is_on(cl_hw->chip)) {
		cl_lcu_bt_config_get(cl_hw);
		cl_lcu_usbc_config_get(cl_hw);
	}

	cl_um_helper_call(debugfs, NULL);

	if (cl_lcu_ela_is_on(cl_hw->chip)) {
		cl_lcu_stop(cl_hw->chip);
		cl_lcu_apply_config(cl_hw->chip);
	}

	/*
	 * Print MIB counters only if watchdog is disabled,
	 * otherwise the dump of prints effects the recovery
	 * relevant only for B2B platform.
	 */
	if (cl_hw->conf->ce_fw_watchdog_mode == FW_WD_DISABLE)
		if (cl_hw->chip->conf->ci_phy_dev == PHY_DEV_FRU ||
		    IS_REAL_PHY(cl_hw->chip))
			cl_mib_cntrs_dump(cl_hw);

	spin_lock_irqsave(&debugfs->umh_lock, flags);
	if (!debugfs->unregistering)
		cl_um_helper_done(cl_hw);
	debugfs->helper_scheduled = false;
	spin_unlock_irqrestore(&debugfs->umh_lock, flags);
}

int cl_um_helper_trigger(struct cl_hw *cl_hw)
{
	struct cl_debugfs *debugfs = &cl_hw->debugfs;
	unsigned long flags;
	unsigned long curr_time = jiffies;
	unsigned int diff_time = jiffies_to_msecs(curr_time - cl_hw->umh_last_call_timestamp);

	if (diff_time < cl_hw->conf->ci_umh_diff_time_ms) {
		if (IS_PCI_BUS_TYPE(cl_hw->chip))
			cl_ipc_dbginfobuf_push(cl_hw->ipc_env,
					       cl_hw->dbginfo.dma_addr);
		else
			cl_usb_dbginfobuf_push(cl_hw);
		cl_dbg_verbose(cl_hw, "Skip cl_umh.sh - time from previous call=%u m-sec\n",
			       diff_time);
		return -1;
	}

	spin_lock_irqsave(&debugfs->umh_lock, flags);
	if (debugfs->helper_scheduled) {
		spin_unlock_irqrestore(&debugfs->umh_lock, flags);
		cl_dbg_verbose(cl_hw, ": Already scheduled\n");
		return -EBUSY;
	}

	if (debugfs->unregistering) {
		spin_unlock_irqrestore(&debugfs->umh_lock, flags);
		cl_dbg_verbose(cl_hw, ": unregistering\n");
		return -ENOENT;
	}

	debugfs->helper_scheduled = true;
	debugfs->trace_prst = true;
	schedule_work(&debugfs->helper_work);
	spin_unlock_irqrestore(&debugfs->umh_lock, flags);

	return 0;
}

void cl_um_helper_init(struct cl_hw *cl_hw, struct dentry *dir_drv)
{
	struct cl_debugfs *debugfs = &cl_hw->debugfs;

	BUILD_BUG_ON(sizeof(CONFIG_CL_UM_HELPER_DFLT) >= sizeof(debugfs->helper_cmd));

	debugfs->dir = dir_drv;
	debugfs->unregistering = false;
	debugfs->trace_prst = false;
	debugfs->helper_scheduled = false;

	snprintf(debugfs->helper_cmd, sizeof(debugfs->helper_cmd), "%s/scripts/cl_umh.sh %u %u",
		 cl_install_dir, cl_hw->chip->idx, cl_hw->tcv_idx);

	INIT_WORK(&debugfs->helper_work, cl_um_helper_work);

	spin_lock_init(&debugfs->umh_lock);
}

void cl_um_helper_close(struct cl_hw *cl_hw)
{
	struct cl_debugfs *debugfs = &cl_hw->debugfs;

	if (!debugfs->dir)
		return;

	debugfs->unregistering = true;
	flush_work(&debugfs->helper_work);
	debugfs_remove_recursive(debugfs->dir);
	debugfs->dir = NULL;
}

ssize_t cl_um_helper_read(struct cl_hw *cl_hw,
			  char __user *user_buf,
			  size_t count,
			  loff_t *ppos)
{
	struct cl_debugfs *debugfs = &cl_hw->debugfs;
	char buf[sizeof(debugfs->helper_cmd)];
	int ret;

	ret = scnprintf(buf, min_t(size_t, sizeof(buf) - 1, count),
			"%s", debugfs->helper_cmd);

	return simple_read_from_buffer(user_buf, count, ppos, buf, ret);
}

ssize_t cl_um_helper_write(struct cl_hw *cl_hw,
			   const char __user *user_buf,
			   size_t count,
			   loff_t *ppos)
{
	struct cl_debugfs *debugfs = &cl_hw->debugfs;
	int eobuf = min_t(size_t, sizeof(debugfs->helper_cmd) - 1, count);

	debugfs->helper_cmd[eobuf] = '\0';
	if (copy_from_user(debugfs->helper_cmd, user_buf, eobuf))
		return -EFAULT;

	return count;
}

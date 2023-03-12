// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/kmod.h>
#include <linux/debugfs.h>
#include <linux/string.h>
#include <linux/list.h>

#include "cl_debugfs.h"
#include "chip.h"
#include "cl_msg_tx.h"
#include "cl_msg_cfm.h"
#include "cl_tx.h"
#include "cl_rate_ctrl.h"
#include "cl_sounding.h"
#include "cl_utils.h"
#include "cl_um_helper.h"
#include "cl_fw_dbg.h"
#include "cl_dbgfile.h"

#define DEBUGFS_ADD_FILE(name, parent, mode)                                          \
do {                                                                                  \
	if (!debugfs_create_file(#name, mode, parent, cl_hw, &cl_dbgfs_##name##_ops)) \
		goto err;                                                             \
} while (0)

/* File operation */
#define DEBUGFS_READ_FUNC(name)                                  \
	static ssize_t cl_dbgfs_##name##_read(struct file *file, \
			char __user *user_buf,                   \
			size_t count, loff_t *ppos)

#define DEBUGFS_WRITE_FUNC(name)                                  \
	static ssize_t cl_dbgfs_##name##_write(struct file *file, \
			const char __user *user_buf,              \
			size_t count, loff_t *ppos)

#define DEBUGFS_READ_FILE_OPS(name)                                   \
	DEBUGFS_READ_FUNC(name);                                      \
	static const struct file_operations cl_dbgfs_##name##_ops = { \
		.read   = cl_dbgfs_##name##_read,                     \
		.open   = simple_open,                                \
		.llseek = generic_file_llseek,                        \
	}

#define DEBUGFS_WRITE_FILE_OPS(name)                                  \
	DEBUGFS_WRITE_FUNC(name);                                     \
	static const struct file_operations cl_dbgfs_##name##_ops = { \
		.write  = cl_dbgfs_##name##_write,                    \
		.open   = simple_open,                                \
		.llseek = generic_file_llseek,                        \
	}

#define DEBUGFS_READ_WRITE_FILE_OPS(name)                             \
	DEBUGFS_READ_FUNC(name);                                      \
	DEBUGFS_WRITE_FUNC(name);                                     \
	static const struct file_operations cl_dbgfs_##name##_ops = { \
		.write  = cl_dbgfs_##name##_write,                    \
		.read   = cl_dbgfs_##name##_read,                     \
		.open   = simple_open,                                \
		.llseek = generic_file_llseek,                        \
	}

static ssize_t cl_dbgfs_benson_write(struct file *file,
				     const char __user *user_buf,
				     size_t count,
				     loff_t *ppos)
{
	struct cl_hw *cl_hw = file->private_data;
	char buf[32];
	unsigned long long result;
	int ret;
	int eobuf = min_t(size_t, sizeof(buf) - 1, count);

	buf[eobuf] = '\0';
	if (copy_from_user(&buf, user_buf, eobuf))
		return -EFAULT;

	ret = kstrtoull(buf, 0, &result);
	if (ret)
		return ret;

	cl_dbg_trace(cl_hw, "result=%llu\n", result);

	switch (result) {
	case 0:
		cl_msg_tx_set_idle(cl_hw, MAC_ACTIVE);
		break;
	case 1:
		cl_msg_tx_set_idle(cl_hw, MAC_IDLE_SYNC);
		break;
	case 2:
		cl_msg_tx_reset(cl_hw);
		break;
	case 3:
		cl_msg_tx_start(cl_hw);
		break;
	case 4:
		cl_msg_tx_goto_power_reduction(cl_hw, 1);
		break;
	case 5:
		cl_msg_tx_goto_power_reduction(cl_hw, 0);
		break;
	case 6:
		cl_msg_tx_backup_bcn_en(cl_hw, 1);
		break;
	case 7:
		cl_msg_tx_backup_bcn_en(cl_hw, 0);
		break;
	case 8:
		cl_msg_tx_start_periodic_tx_time(cl_hw, 150, 50);
		break;
	case 9:
		cl_msg_tx_start_periodic_tx_time(cl_hw, 0, 20);
		break;
	case 10:
		cl_msg_tx_phy_reset(cl_hw);
		break;
	default:
		break;
	}

	return count;
}

DEBUGFS_WRITE_FILE_OPS(benson);

static ssize_t cl_dbgfs_set_debug_write(struct file *file,
					const char __user *user_buf,
					size_t count,
					loff_t *ppos)
{
	struct cl_hw *cl_hw = file->private_data;
	struct cl_tcv_conf *conf = cl_hw->conf;
	char buf[32];
	char *usage_str = "Usage:\n"
			  "echo [mod_filter] > set_debug\n";
	unsigned long long mod_filter;
	int ret;
	int eobuf = min_t(size_t, sizeof(buf) - 1, count);

	buf[eobuf] = '\0';
	if (copy_from_user(&buf, user_buf, eobuf))
		return -EFAULT;

	ret = kstrtoull(buf, 0, &mod_filter);
	if (ret) {
		cl_dbg_verbose(cl_hw, "%s", usage_str);
		return ret;
	}

	cl_dbg_verbose(cl_hw, "Send to FW: dbg_module=0x%x, dbg_severity=%u, mod_filter=0x%x\n",
		       conf->ci_fw_dbg_module, conf->ci_fw_dbg_severity, (u32)mod_filter);

	ret = cl_msg_tx_dbg_set_ce_mod_filter(cl_hw, conf->ci_fw_dbg_module);
	if (ret)
		return ret;

	ret = cl_msg_tx_dbg_set_sev_filter(cl_hw, conf->ci_fw_dbg_severity);
	if (ret)
		return ret;

	ret = cl_msg_tx_dbg_set_mod_filter(cl_hw, mod_filter);
	if (ret)
		return ret;

	return 0;
}

DEBUGFS_WRITE_FILE_OPS(set_debug);

enum cl_beamform_cmd {
	CL_BF_CMD_TX_NDPA_HT,
	CL_BF_CMD_TX_NDPA_NDP_HT,
	CL_BF_CMD_TX_NDPA_NOACK_NDP_HT,
	CL_BF_CMD_TX_NDPA_VHT,
	CL_BF_CMD_TX_NDPA_NDP_VHT,
	CL_BF_CMD_TX_NDPA_NDP_VHT_MU,
	CL_BF_CMD_TX_NDPA_NDP_BRP,
	CL_BF_CMD_TX_NDPA_NDP_VHT_PERIODIC,
	CL_BF_CMD_TX_NDP_RATE_SET,
	CL_BF_CMD_TX_NDPA_RATE_SET,

	/* This argument is passed to firmware and is represented as 4bit. 2^4=16 */
	CE_BEAMFORM_CMD_MAX = 16
};

/* Generation param for cmd assoicated with periodical beamform */
static int beamform_pgen(struct cl_hw *cl_hw, char **sptr,
			 enum cl_beamform_cmd bf_cmd,
			 struct dbg_fs_bf_args *bf_args)
{
	char *token;
	u8 is_mu = 0;
	unsigned long sta_idx, ant_map = 0xff;

	if (bf_cmd == CL_BF_CMD_TX_NDPA_NDP_VHT_MU)
		is_mu = 1;

	do {
		/* 1st param - sta index */
		token = strsep(sptr, " ");
		if (!token)
			break;
		if (kstrtoul(token, 0, &sta_idx) || sta_idx >= CL_MAX_NUM_STA)
			break;

		/* 2nd param - antennas bitmap, 8 bit (default 0xff). decimal or hex. */
		token = strsep(sptr, " ");
		if (token) {
			cl_dbg_err(cl_hw, "token=%s\n", token);
			if (kstrtoul(token, 0, &ant_map) || ant_map > 0xff)
				break;
		}

		/* Pack all to u32: byte0=bf_cmd, byte1=sta_idx, byte2=ant_map */
		bf_args->cmd = bf_cmd;
		bf_args->sta_idx = sta_idx;
		bf_args->antenna_set = ant_map;
		bf_args->is_mu = is_mu;
		bf_args->is_enable = false;
		bf_args->interval = 0;

		return 0;
	} while (0);

	cl_dbg_err(cl_hw, "Error in beamform_cmd parameters.\n");
	cl_dbg_err(cl_hw, "   <STA_INDEX: 0-max>, [ANTENNAS_SET: bimap (0xFF=all)]\n");

	return 1;
}

static int beamform_periodical_pgen(struct cl_hw *cl_hw, char **sptr,
				    enum cl_beamform_cmd bf_cmd,
				    struct dbg_fs_bf_args *bf_args)
{
	/* Generation param for cmd assoicated with periodical beamform */
	char *token;
	u8 is_mu = 0;
	bool is_enable;
	unsigned long sta_idx, ant_map = 0xff, interval = 0;

	do {
		/* 1st param - enable, if set then periodic beamform cmd is set else, disabled */
		token = strsep(sptr, " ");
		if (!token)
			break;

		cl_dbg_err(cl_hw, "token=%s\n", token);

		if (!strncasecmp(token, "enable", strlen("enable")))
			is_enable = true;
		else if (!strncasecmp(token, "disable", strlen("disable")))
			is_enable = false;
		else
			break;

		/* 2nd param - sta index */
		token = strsep(sptr, " ");
		if (!token)
			break;

		if (kstrtoul(token, 0, &sta_idx) || sta_idx > 127)
			break;

		/* 3rd param - interval, 8 bit. decimal. */
		if (is_enable) {
			token = strsep(sptr, " ");
			if (!token)
				break;
			cl_dbg_err(cl_hw, "token=%s\n", token);
			if (kstrtoul(token, 0, &interval) || interval > 1024)
				break;

			/* 4th param - ant_map [optional] */
			token = strsep(sptr, " ");
			if (token) {
				cl_dbg_err(cl_hw, "token=%s\n", token);
				if (kstrtoul(token, 0, &ant_map) || ant_map > 0xff)
					break;
			}
		}

		/* Pack all to u32: byte0=bf_cmd, byte1=sta_idx, byte2=ant_map */
		bf_args->cmd = bf_cmd;
		bf_args->sta_idx = sta_idx;
		bf_args->antenna_set = ant_map;
		bf_args->is_mu = is_mu;
		bf_args->is_enable = is_enable;
		bf_args->interval = interval;

		return 0;
	} while (0);

	cl_dbg_err(cl_hw, "Error in beamform_cmd parameters.\n");
	cl_dbg_err(cl_hw, "   <IS_ENABLED: enable|disable>, <STA_INDEX: 0-max>, "
			  "<INTERVAL: must be positive>, [ANTENNAS_SET: bimap (0xFF=all)]\n");

	return 1;
}

static ssize_t cl_dbgfs_beamform_cmd_write(struct file *file,
					   const char __user *user_buf,
					   size_t count,
					   loff_t *ppos)
{
	struct cl_hw *cl_hw = file->private_data;
	char buf[64];
	struct dbg_fs_bf_args bf_args;
	int ret = 0;
	char *sptr, *token;
	int eobuf = min_t(size_t, sizeof(buf) - 1, count);

	if (copy_from_user(&buf, user_buf, eobuf))
		return -EFAULT;

	buf[eobuf] = '\0';
	sptr = buf;

	token = strsep(&sptr, " ");
	if (!token)
		return -EINVAL;

	cl_dbg_trace(cl_hw, "Token=%s\n", token);

	if (!strncasecmp(token, "ndpa-ht", strlen(token))) {
		cl_dbg_trace(cl_hw, "debugfs: Transmit NDPA-HT sequence.\n");
		if (beamform_pgen(cl_hw, &sptr, CL_BF_CMD_TX_NDPA_HT, &bf_args))
			return -EINVAL;
	} else if (!strncasecmp(token, "ndpa-ndp-ht", strlen(token))) {
		cl_dbg_trace(cl_hw, "debugfs: Transmit NDPA-NDP-HT sequence.\n");
		if (beamform_pgen(cl_hw, &sptr, CL_BF_CMD_TX_NDPA_NDP_HT, &bf_args))
			return -EINVAL;
	} else if (!strncasecmp(token, "ndpa-noack-ndp-ht", strlen(token))) {
		cl_dbg_trace(cl_hw, "debugfs: Transmit NDPA-NOACK-NDP-HT sequence.\n");
		if (beamform_pgen(cl_hw, &sptr, CL_BF_CMD_TX_NDPA_NOACK_NDP_HT, &bf_args))
			return -EINVAL;
	} else if (!strncasecmp(token, "ndpa-vht", strlen(token))) {
		cl_dbg_trace(cl_hw, "debugfs: Transmit NDPA-VHT sequence.\n");
		if (beamform_pgen(cl_hw, &sptr, CL_BF_CMD_TX_NDPA_VHT, &bf_args))
			return -EINVAL;
	} else if (!strncasecmp(token, "ndpa-ndp-vht", strlen(token))) {
		cl_dbg_trace(cl_hw, "debugfs: Transmit NDPA-NDP-VHT sequence.\n");
		if (beamform_pgen(cl_hw, &sptr, CL_BF_CMD_TX_NDPA_NDP_VHT, &bf_args))
			return -EINVAL;
	} else if (!strncasecmp(token, "ndpa-ndp-vht-periodic", strlen(token))) {
		cl_dbg_trace(cl_hw, "debugfs: Transmit NDPA-NDP-VHT-PERIODIC sequence.\n");
		if (beamform_periodical_pgen(cl_hw, &sptr, CL_BF_CMD_TX_NDPA_NDP_VHT_PERIODIC,
					     &bf_args))
			return -EINVAL;
	} else if (!strncasecmp(token, "ndpa-ndp-vht-mu", strlen(token))) {
		cl_dbg_trace(cl_hw, "debugfs: Transmit NDPA-NDP-VHT MU sequence.\n");
		if (beamform_pgen(cl_hw, &sptr, CL_BF_CMD_TX_NDPA_NDP_VHT_MU, &bf_args))
			return -EINVAL;
	} else {
		cl_dbg_err(cl_hw, "Error unrecognized beamform_cmd command.\n");
		return -EINVAL;
	}

	ret = cl_msg_tx_dbg_beamforming_tx(cl_hw, *((u32 *)&bf_args));
	if (ret)
		cl_dbg_err(cl_hw, "cl_msg_tx_dbg_beamforming_tx failed! ret=%d\n", ret);

	return count;
}

DEBUGFS_WRITE_FILE_OPS(beamform_cmd);

static ssize_t cl_dbgfs_stat_print_write(struct file *file,
					 const char __user *user_buf,
					 size_t count,
					 loff_t *ppos)
{
	struct cl_hw *cl_hw = file->private_data;
	char buf[32];
	int ret;
	char *usage_str = "Usage:\n"
			  "echo [bitmap] [param1 (opt)] > stat_print\n";
	unsigned long long stat_bitmap, param0 = 0xff, param1 = 0xff, param2 = 0xff, param3 = 0xff;
	char *sptr, *token1, *token2, *token3, *token4, *token5;

	int eobuf = min_t(size_t, sizeof(buf) - 1, count);

	buf[eobuf] = '\0';
	if (copy_from_user(&buf, user_buf, eobuf)) {
		cl_dbg_err(cl_hw, "illegal input\n %s", usage_str);
		return -EFAULT;
	}

	sptr = buf;

	token1 = strsep(&sptr, " ");
	if (!token1) {
		cl_dbg_err(cl_hw, "Token1 illegal\n %s", usage_str);
		return -EINVAL;
	}

	ret = kstrtoull(token1, 0, &stat_bitmap);
	if (ret) {
		cl_dbg_err(cl_hw, "Token1 %s illegal convert\n %s", token1, usage_str);
		return ret;
	}

	token2 = strsep(&sptr, " ");
	if (token2) {
		ret = kstrtoull(token2, 0, &param0);
		if (ret) {
			cl_dbg_err(cl_hw, "Token2 %s illegal convert\n %s", token2, usage_str);
			return ret;
		}
	}

	token3 = strsep(&sptr, " ");
	if (token3) {
		ret = kstrtoull(token3, 0, &param1);
		if (ret) {
			cl_dbg_err(cl_hw, "Token3 %s illegal convert\n %s", token3, usage_str);
			return ret;
		}
	}

	token4 = strsep(&sptr, " ");
	if (token4) {
		ret = kstrtoull(token4, 0, &param2);
		if (ret) {
			cl_dbg_err(cl_hw, "Token4 %s illegal convert\n %s", token4, usage_str);
			return ret;
		}
	}

	token5 = strsep(&sptr, " ");
	if (token5) {
		ret = kstrtoull(token5, 0, &param3);
		if (ret) {
			cl_dbg_err(cl_hw, "Token5 %s illegal convert\n %s", token5, usage_str);
			return ret;
		}
	}

	if (!token2 && !token3 && !token4 && !token5)
		cl_dbg_trace(cl_hw, "stat_bitmap = %llu\n",
			     stat_bitmap);
	else if (!token3 && !token4 && !token5)
		cl_dbg_trace(cl_hw, "stat_bitmap = %llu, param = %llu\n",
			     stat_bitmap, param0);
	else if (!token4 && !token5)
		cl_dbg_trace(cl_hw, "stat_bitmap = %llu, param = %llu, %llu\n",
			     stat_bitmap, param0, param1);
	else if (!token5)
		cl_dbg_trace(cl_hw, "stat_bitmap = %llu, param = %llu, %llu, %llu\n",
			     stat_bitmap, param0, param1, param2);
	else
		cl_dbg_trace(cl_hw, "stat_bitmap = %llu, param = %llu, %llu, %llu, %llu\n",
			     stat_bitmap, param0, param1, param2, param3);

	if (stat_bitmap == DBG_PRINT_RESET)
		cl_fw_dbg_trigger_based_reset(cl_hw);

	ret = cl_msg_tx_dbg_print_stats(cl_hw, (u32)stat_bitmap, (u32)param0,
					(u32)param1, (u32)param2, (u32)param3);

	return count;
}

DEBUGFS_WRITE_FILE_OPS(stat_print);

static ssize_t cl_dbgfs_ba_session_write(struct file *file,
					 const char __user *user_buf,
					 size_t count,
					 loff_t *ppos)
{
	struct cl_hw *cl_hw = file->private_data;
	char buf[32];
	int ret;
	char *usage_str = "Usage:\n"
			  "echo [sta_idx] [tid] [option - 0: stop, 1:start] > ba_session\n";
	unsigned long long sta_idx = 0, tid = 0, option = 0;
	char *sptr, *token1, *token2, *token3;
	struct cl_sta *cl_sta;
	struct ieee80211_sta *sta = NULL;
	int eobuf = min_t(size_t, sizeof(buf) - 1, count);

	buf[eobuf] = '\0';
	if (copy_from_user(&buf, user_buf, eobuf)) {
		cl_dbg_err(cl_hw, "illegal input\n %s", usage_str);
		return -EFAULT;
	}

	sptr = buf;

	token1 = strsep(&sptr, " ");
	if (!token1) {
		cl_dbg_err(cl_hw, "Token1 illegal\n %s", usage_str);
		return -EINVAL;
	}

	ret = kstrtoull(token1, 0, &sta_idx);
	if (ret) {
		cl_dbg_err(cl_hw, "Token1 %s illegal convert\n %s", token1, usage_str);
		return ret;
	}

	token2 = strsep(&sptr, " ");
	if (!token2) {
		cl_dbg_err(cl_hw, "Token2 illegal\n %s", usage_str);
		return -EINVAL;
	}

	ret = kstrtoull(token2, 0, &tid);
	if (ret) {
		cl_dbg_err(cl_hw, "Token2 %s illegal convert\n %s", token2, usage_str);
		return ret;
	}

	token3 = strsep(&sptr, " ");
	if (!token3) {
		cl_dbg_err(cl_hw, "Token3 illegal\n %s", usage_str);
		return -EINVAL;
	}

	ret = kstrtoull(token3, 0, &option);
	if (ret) {
		cl_dbg_err(cl_hw, "Token3 %s illegal convert\n %s", token3, usage_str);
		return ret;
	}

	cl_sta_lock_bh(cl_hw);
	cl_sta = cl_sta_get(cl_hw, sta_idx);

	if (cl_sta && tid < 8 && option < 2) {
		if (option == 0) {
			if (!cl_sta->agg_tx_queues[tid]) {
				pr_err("session already stopped [sta_idx = %llu][tid = %llu]\n",
				       sta_idx, tid);
				cl_sta_unlock_bh(cl_hw);
				goto out;
			}
		} else {
			if (cl_sta->agg_tx_queues[tid]) {
				pr_err("session already started [sta_idx = %llu][tid = %llu]\n",
				       sta_idx, tid);
				cl_sta_unlock_bh(cl_hw);
				goto out;
			}
		}

		sta = &cl_sta->stainfo->sta;
	} else {
		cl_sta_unlock_bh(cl_hw);
		pr_err("Invalid input [sta_idx = %llu][tid = %llu][option = %llu]\n",
		       sta_idx, tid, option);
		goto out;
	}

	cl_sta_unlock_bh(cl_hw);

	if (option == 0) {
		pr_debug("stop tx ba session [sta_idx = %llu][tid = %llu]\n", sta_idx, tid);
		ieee80211_stop_tx_ba_session(sta, tid);
	} else {
		pr_debug("start tx ba session [sta_idx = %llu][tid = %llu]\n", sta_idx, tid);
		ieee80211_start_tx_ba_session(sta, tid, cl_hw->conf->ce_tx_ba_session_timeout);
	}

out:
	return count;
}

DEBUGFS_WRITE_FILE_OPS(ba_session);

static ssize_t cl_dbgfs_tx_trace_debug_flag_write(struct file *file,
						  const char __user *user_buf,
						  size_t count,
						  loff_t *ppos)
{
	struct cl_hw *cl_hw = file->private_data;
	char buf[32];
	int ret;
	unsigned long long result;
	u8 read_write_cmd;
	char *sptr, *token;
	char *usage_str = "Usage: echo  [w\\r] [value] > tx_trace_debug_flag\n";
	int eobuf = min_t(size_t, sizeof(buf) - 1, count);

	buf[eobuf] = '\0';
	if (copy_from_user(&buf, user_buf, eobuf)) {
		cl_dbg_err(cl_hw, "illegal input\n %s", usage_str);
		return -EFAULT;
	}
	sptr = buf;
	token = strsep(&sptr, " ");
	if (!token) {
		cl_dbg_err(cl_hw, "illegal input\n %s", usage_str);
		return -EINVAL;
	}

	if (!strncasecmp(token, "w", strlen("w"))) {
		read_write_cmd = 1;
		ret = kstrtoull(sptr, 0, &result);
		if (ret) {
			cl_dbg_err(cl_hw, "illegal input\n %s", usage_str);
			return ret;
		}
		cl_dbg_trace(cl_hw, "(write value=0x%x)\n", (u32)result);
	} else if (!strncasecmp(token, "r", strlen("r"))) {
		read_write_cmd = 0;
		result = 0;
		cl_dbg_trace(cl_hw, "(read)\n");
	} else {
		cl_dbg_err(cl_hw, "illegal input\n %s", usage_str);
		return -EFAULT;
	}

	ret = cl_msg_tx_dbg_tx_trace_debug_flag(cl_hw, (u32)result, (u8)read_write_cmd);

	return count;
}

DEBUGFS_WRITE_FILE_OPS(tx_trace_debug_flag);

static ssize_t cl_dbgfs_test_mode_write(struct file *file,
					const char __user *user_buf,
					size_t count,
					loff_t *ppos)
{
	struct cl_hw *cl_hw = file->private_data;
	char buf[32];
	int ret;
	unsigned long long params[TEST_MODE_PARAM_MAX + 1] = {0};
	u32 test_params[TEST_MODE_PARAM_MAX + 1] = {0};
	char *usage_str = "Usage:\n"
			  "debugfsh <chip> <tcv> test_mode <command> <params> <params> ..\n";
	char *token, *sptr;
	int eobuf = min_t(size_t, sizeof(buf) - 1, count);
	int i = 0;

	buf[eobuf] = '\0';
	if (copy_from_user(&buf, user_buf, eobuf)) {
		cl_dbg_err(cl_hw, "string %s count %zu eobuf %d\n", buf, count, eobuf);
		return -EFAULT;
	}
	sptr = buf;
	token = strsep(&sptr, " ");

	for (i = 0; i < TEST_MODE_PARAM_MAX + 1; i++) {
		if (token) {
			ret = kstrtoull(token, 0, &params[i]);
			if (ret) {
				cl_dbg_trace(cl_hw, "Token %s illegal convert %s\n",
					     token, usage_str);
				return ret;
			}
			test_params[i] = (u32)params[i];
			cl_dbg_trace(cl_hw, "param[%d]=%llu\n", i, params[i]);
		} else {
			break;
		}
		token = strsep(&sptr, " ");
	}

	ret = cl_msg_tx_dbg_test_mode(cl_hw, test_params);

	return count;
}

DEBUGFS_WRITE_FILE_OPS(test_mode);

static ssize_t cl_dbgfs_fixed_rate_write(struct file *file,
					 const char __user *user_buf,
					 size_t count,
					 loff_t *ppos)
{
	struct cl_hw *cl_hw = file->private_data;
	char buf[32];
	int ret;
	unsigned long long mcs = 0, bw = 0, gi = 0, format = 0, ltf_field = 0,
		pre_type_or_stbc = 0, sta_idx = 0xff, ru_alloc = 0xff, ru_band = 0xff,
		ru_type = 0xff, ru_index = 0xff;
	char *sptr, *token1, *token2, *token3, *token4, *token5, *token6, *token7,
		*token8, *token9, *token10, *token11;
	char *usage_str = "Usage:\n"
			  "echo [mcs] [bw] [gi] [format] [ltf_field] [pre_type_or_stbc(opt)] "
			  "[sta_idx(opt)] [ru_alloc(opt)] [ru_band(opt)] [ru_type(opt)] "
			  "[ru_index(opt)] > fixed_rate\n";
	u8 gid = 0, op_mode = RATE_OP_MODE_FIXED;
	int eobuf = min_t(size_t, sizeof(buf) - 1, count);
	union cl_rate_ctrl_info rate_ctrl;
	union cl_rate_ctrl_info_he rate_ctrl_he;

	buf[eobuf] = '\0';
	if (copy_from_user(&buf, user_buf, eobuf)) {
		cl_dbg_err(cl_hw, "illegal input\n %s", usage_str);
		return -EFAULT;
	}

	sptr = buf;

	/* Token1 - mcs */
	token1 = strsep(&sptr, " ");
	if (!token1) {
		cl_dbg_err(cl_hw, "token1 illegal %s\n", usage_str);
		return -EINVAL;
	}

	ret = kstrtoull(token1, 0, &mcs);
	if (ret) {
		cl_dbg_err(cl_hw, "token1 %s illegal convert %s\n", token1, usage_str);
		return ret;
	}

	/* Token2 - bw */
	token2 = strsep(&sptr, " ");
	if (!token2) {
		cl_dbg_err(cl_hw, "token2 illegal %s\n", usage_str);
		return -EINVAL;
	}

	ret = kstrtoull(token2, 0, &bw);
	if (ret) {
		cl_dbg_err(cl_hw, "token2 %s illegal convert %s\n", token2, usage_str);
		return ret;
	}

	/* Token3 - gi */
	token3 = strsep(&sptr, " ");
	if (!token3) {
		cl_dbg_err(cl_hw, "token3 illegal %s\n", usage_str);
		return -EINVAL;
	}

	ret = kstrtoull(token3, 0, &gi);
	if (ret) {
		cl_dbg_err(cl_hw, "token3 %s illegal convert %s\n", token3, usage_str);
		return ret;
	}

	/* Token4 - format */
	token4 = strsep(&sptr, " ");
	if (!token4) {
		cl_dbg_err(cl_hw, "token4 illegal %s\n", usage_str);
		return -EINVAL;
	}

	ret = kstrtoull(token4, 0, &format);
	if (ret) {
		cl_dbg_err(cl_hw, "token4 %s illegal convert %s\n", token4, usage_str);
		return ret;
	}

	/* Token5 - ltf_field */
	token5 = strsep(&sptr, " ");
	if (!token5) {
		cl_dbg_err(cl_hw, "token5 illegal %s\n", usage_str);
		return -EINVAL;
	}

	ret = kstrtoull(token5, 0, &ltf_field);
	if (ret) {
		cl_dbg_err(cl_hw, "token5 %s illegal convert %s\n", token5, usage_str);
		return ret;
	}

	/* Token6 - pre_type_or_stbc (optional) */
	token6 = strsep(&sptr, " ");
	if (token6) {
		ret = kstrtoull(token6, 0, &pre_type_or_stbc);
		if (ret) {
			cl_dbg_err(cl_hw, "token6 %s illegal convert %s\n", token6, usage_str);
			return ret;
		}
	}

	/* Token7 - sta_idx (optional) */
	token7 = strsep(&sptr, " ");
	if (token7) {
		ret = kstrtoull(token7, 0, &sta_idx);
		if (ret) {
			cl_dbg_err(cl_hw, "token7 %s illegal convert %s\n", token7, usage_str);
			return ret;
		}
	}

	/* Token8 - ru_alloc (optional) */
	token8 = strsep(&sptr, " ");
	if (token8) {
		ret = kstrtoull(token8, 0, &ru_alloc);
		if (ret) {
			cl_dbg_err(cl_hw, "token8 %s illegal convert %s\n", token8, usage_str);
			return ret;
		}
	}

	/* Token9 - ru_band (optional) */
	token9 = strsep(&sptr, " ");
	if (token9) {
		ret = kstrtoull(token9, 0, &ru_band);
		if (ret) {
			cl_dbg_err(cl_hw, "token9 %s illegal convert %s\n", token9, usage_str);
			return ret;
		}
	}

	/* Token10 - ru_type (optional) */
	token10 = strsep(&sptr, " ");
	if (token10) {
		ret = kstrtoull(token10, 0, &ru_type);
		if (ret) {
			cl_dbg_err(cl_hw, "token10 %s illegal convert %s\n", token10, usage_str);
			return ret;
		}
	}

	/* Token11 - ru_index (optional) */
	token11 = strsep(&sptr, " ");
	if (token11) {
		ret = kstrtoull(token11, 0, &ru_index);
		if (ret) {
			cl_dbg_err(cl_hw, "token11 %s illegal convert %s\n", token11, usage_str);
			return ret;
		}
	}

	/* Sanity tests */
	if (sta_idx != STA_IDX_INVALID && !cl_sta_is_assoc(cl_hw, sta_idx)) {
		cl_dbg_err(cl_hw, "Invalid station index [%llu]\n", sta_idx);
		return -EINVAL;
	}

	if (format < FORMATMOD_HE_SU)
		ltf_field = 0;

	if (ru_band != 0xff && ru_band > 1) {
		cl_dbg_err(cl_hw, "Invalid ru_band [%llu], valid values are 0 or 1\n", ru_band);
		return -EFAULT;
	}

	if ((format != FORMATMOD_HE_MU && format != FORMATMOD_HE_TRIG) && ru_band == 1) {
		cl_dbg_err(cl_hw, "ru_band must be 0 when not transmitting in HE_MU/HE_TRIG\n");
		ru_band = 0;
	}

	if (ru_type != 0xff && (ru_type > 7 || ru_type == 0)) {
		cl_dbg_err(cl_hw, "Invalid ru_type [%llu], valid values are 1 to 7\n", ru_type);
		return -EFAULT;
	}

	/* Build rate_ctrl and rate_ctrl_he */
	if (mcs == 0xff || bw == 0xff || gi == 0xff || format == 0xff) {
		cl_hw->entry_fixed_rate = false;
		cl_dbg_trace(cl_hw, "Fixed rate turned off\n");
	} else {
		rate_ctrl.word = 0;
		rate_ctrl.field.mcs_index = mcs;
		rate_ctrl.field.bw = bw;
		rate_ctrl.field.gi = gi;
		rate_ctrl.field.format_mod = format;

		if (rate_ctrl.field.format_mod != FORMATMOD_NON_HT)
			rate_ctrl.field.pre_type_or_stbc = pre_type_or_stbc;

		/* rate_ctrl_he is relevant only for HE formate mode. */
		if (format > FORMATMOD_VHT) {
			rate_ctrl_he.field.spatial_conf = RATE_CNTRL_HE_SPATIAL_CONF_DEF;

			if (format > FORMATMOD_HE_SU) {
				rate_ctrl_he.field.ru_alloc = ru_alloc;
				rate_ctrl_he.field.ru_band = ru_band;
				rate_ctrl_he.field.ru_type = ru_type;
				rate_ctrl_he.field.ru_index = ru_index;
			}
		} else {
			rate_ctrl_he.word = 0;
		}

		cl_dbg_trace(cl_hw, "mcs=%llu bw=%llu gi=%llu format=%llu --> rate_ctrl 0x%x\n",
			     mcs, bw, gi, format, rate_ctrl.word);
		cl_dbg_trace(cl_hw, "ltf_field=%llu ru_alloc=%llu ru_band=%llu ru_type=%llu, "
				    "ru_index=%llu --> rate_ctrl_he 0x%x\n",
			     ltf_field, ru_alloc, ru_band, ru_type, ru_index, rate_ctrl_he.word);

		/* Set entry_fixed_rate to true only if there is no specific station */
		cl_hw->entry_fixed_rate = (sta_idx == 0xff);

		if (format == FORMATMOD_HE_MU &&
		    ru_alloc != 0xff &&
		    ru_band != 0xff &&
		    ru_type != 0xff &&
		    ru_index != 0xff) {
			op_mode = RATE_OP_MODE_STA_MU;
			gid = 1;
		}

		if (!cl_rate_ctrl_set_dbgfs(cl_hw, sta_idx, rate_ctrl.word, rate_ctrl_he.word,
					    op_mode, bw, gid, ltf_field))
			return -EFAULT;
	}

	return count;
}

DEBUGFS_WRITE_FILE_OPS(fixed_rate);

enum {
	CL_SOUNDING_CMD_HELP = 0,
	CL_SOUNDING_CMD_TX_NDPA_VHT = 1,
	CL_SOUNDING_CMD_TX_NDPA_NDP_VHT = 2,
	CL_SOUNDING_CMD_TX_NDPA_NDP_VHT_MU = 3,
	CL_SOUNDING_CMD_TX_NDPA_NDP_BRP = 4,
	CL_SOUNDING_CMD_TX_NDPA_NDP_VHT_PERIODIC = 5,
	CL_SOUNDING_CMD_TX_NDPA_NDP_HE = 6,
	CL_SOUNDING_CMD_TX_NDPA_NDP_BFRTR_HE = 7,
	CL_SOUNDING_CMD_TX_NDPA_NDP_PHY_FAILURE = 8,
	CL_SOUNDING_CMD_TX_NDPA_NO_NDP = 9,
	CL_SOUNDING_CMD_TX_NDPA_NDP_NO_BFRP = 10,
	CL_SOUNDING_CMD_TX_BFR_STA_ADD = 11,
	CL_SOUNDING_CMD_TX_BFR_STA_REMOVE = 12,
	CL_SOUNDING_CMD_TX_BFR_STA_GET = 13,
	CL_SOUNDING_CMD_MAX
};

static u32 sounding_cmd_param_num[CL_SOUNDING_CMD_MAX] = {
	[CL_SOUNDING_CMD_HELP] = 0,
	[CL_SOUNDING_CMD_TX_NDPA_VHT] = 2,
	[CL_SOUNDING_CMD_TX_NDPA_NDP_VHT] = 2,
	[CL_SOUNDING_CMD_TX_NDPA_NDP_VHT_MU] = 2,
	[CL_SOUNDING_CMD_TX_NDPA_NDP_BRP] = 2,
	[CL_SOUNDING_CMD_TX_NDPA_NDP_VHT_PERIODIC] = 2,
	[CL_SOUNDING_CMD_TX_NDPA_NDP_HE] = 2,
	[CL_SOUNDING_CMD_TX_NDPA_NDP_BFRTR_HE] = 2 + 6 + MAX_NUM_OF_SIMULTANEUS_UL_STREAMS * 2,
	[CL_SOUNDING_CMD_TX_NDPA_NDP_PHY_FAILURE] = 2,
	[CL_SOUNDING_CMD_TX_NDPA_NO_NDP] = 2,
	[CL_SOUNDING_CMD_TX_NDPA_NDP_NO_BFRP] = 2,
	[CL_SOUNDING_CMD_TX_BFR_STA_ADD] = 2,
	[CL_SOUNDING_CMD_TX_BFR_STA_REMOVE] = 2,
	[CL_SOUNDING_CMD_TX_BFR_STA_GET] = 0,
};

static ssize_t cl_dbgfs_sounding_cmd_write(struct file *file,
					   const char __user *user_buf,
					   size_t count, loff_t *ppos)
{
	struct cl_hw *cl_hw = file->private_data;
	char buf[100];
	int ret;
	u32 i = 0;
	unsigned long long test_index = 0;
	unsigned long long param[SOUNDING_CMD_MAX_PARAMS] = {0};
	char *sptr, *token[SOUNDING_CMD_MAX_PARAMS + 1];
	char *usage_str = "Usage:\n"
			  "scripts/debugfsh <chip> <tcv> sounding_cmd [sounding_cmd_index] "
			  "[param1] [param2] ...\n";
	struct dbg_sounding_cmd_param sounding_cmd_parameters;
	int eobuf = min_t(size_t, sizeof(buf) - 1, count);

	buf[eobuf] = '\0';

	if (copy_from_user(&buf, user_buf, eobuf)) {
		cl_dbg_err(cl_hw, "illegal input\n %s", usage_str);
		return -EFAULT;
	}

	sptr = buf;
	token[SOUNDING_CMD_MAX_PARAMS] = strsep(&sptr, " ");

	if (!token[SOUNDING_CMD_MAX_PARAMS]) {
		cl_dbg_err(cl_hw, "sounding cmd index illegal %s\n", usage_str);
		return -EINVAL;
	}

	ret = kstrtoull(token[SOUNDING_CMD_MAX_PARAMS], 0, &test_index);
	if (ret) {
		cl_dbg_err(cl_hw, "Token1 %s illegal convert %s\n",
			   token[SOUNDING_CMD_MAX_PARAMS], usage_str);
		return ret;
	}

	sounding_cmd_parameters.sounding_cmd_index = cpu_to_le32(test_index);
	if (test_index >= CL_SOUNDING_CMD_MAX) {
		cl_dbg_err(cl_hw, "sounding cmd index illegal - %llu %s\n",
			   test_index, usage_str);
		return -EINVAL;
	}

	cl_dbg_err(cl_hw, "sounding cmd index %llu, num_of_params = %u\n",
		   test_index, sounding_cmd_param_num[test_index]);

	for (i = 0; i < sounding_cmd_param_num[test_index]; i++) {
		token[i] = strsep(&sptr, " ");
		if (!token[i]) {
			cl_dbg_err(cl_hw, "Token %u illegal\n %s ", i + 1, usage_str);
			return -EINVAL;
		}

		ret = kstrtoull(token[i], 0, &param[i]);
		if (ret) {
			cl_dbg_err(cl_hw, "Token %u %s illegal convert\n %s",
				   i, token[i], usage_str);
			return ret;
		}
		sounding_cmd_parameters.param[i] = cpu_to_le32(param[i]);
		cl_dbg_err(cl_hw, "Parameter %u value 0x%x\n",
			   i, sounding_cmd_parameters.param[i]);
	}

	if (cl_msg_tx_dbg_sounding_cmd(cl_hw, &sounding_cmd_parameters)) {
		cl_dbg_err(cl_hw, "%s: Failed to execute sounding cmd\n", __func__);
		return -EFAULT;
	}
	return count;
}

DEBUGFS_WRITE_FILE_OPS(sounding_cmd);

static ssize_t cl_dbgfs_ndp_rate_write(struct file *file,
				       const char __user *user_buf,
				       size_t count,
				       loff_t *ppos)
{
	const char *usage_str = "Usage:\n"
				"echo [mcs] [bw] [gi] [PreTypeTxRCX] [format] > ndp(a)_rate\n";
	const u8 field_widths[5] = {
		7, /* Mcs[6:0] */
		2, /* Bw[7:8] */
		1, /* Gi[9] */
		1, /* PreTypeTxRCX[10] */
		3, /* Fmt[11:13] */
	};
	u8 fields[5] = {0, 0, 0, 0, 0};
	bool ndpa = (ppos == ((loff_t *)~0)); /* If this is reused for NDPA */
	struct cl_hw *cl_hw = file->private_data;
	char buf[32], *sptr, *token;
	int iparam = -1;
	int ret = -1;
	struct dbg_frame_rate ndp_rate = {0};

	size_t eobuf = min_t(size_t, sizeof(buf) - 1, count);

	if (eobuf < count || eobuf < 1)
		goto err_param;

	if (copy_from_user(&buf, user_buf, eobuf))
		goto err;

	buf[eobuf] = '\0';
	sptr = buf;

	for (iparam = 0; iparam < ARRAY_SIZE(fields); iparam++) {
		unsigned long ulv;

		token = strsep(&sptr, " ");
		if (!token)
			goto err_param;

		if (kstrtoul(token, 16, &ulv) || ulv >= (1U << field_widths[iparam]))
			goto err_param;
		fields[iparam] = (u8)ulv;
	}

	/*
	 * Pack all fields into uint32; actually used are 16 lower bits,
	 * 8 high bits select ndpa or ndp.
	 */
	ndp_rate.mcs = fields[0];
	ndp_rate.bw = fields[1];
	ndp_rate.gi = fields[2];
	ndp_rate.pretypetxrcx = fields[3];
	ndp_rate.format = fields[4];
	ndp_rate.cmd = ndpa ? CL_BF_CMD_TX_NDPA_RATE_SET : CL_BF_CMD_TX_NDP_RATE_SET;

	cl_dbg_trace(cl_hw,
		     "Tokens: mcs=%u bw=%u gi=%u pretypetxrcx=%u format=%u cmd=%u--> "
		     "NDP(A) fixed_rate 0x%x\n",
		     ndp_rate.mcs, ndp_rate.bw, ndp_rate.gi, ndp_rate.pretypetxrcx,
		     ndp_rate.format, ndp_rate.cmd, *((u32 *)&ndp_rate));

	ret = cl_msg_tx_dbg_beamforming_tx(cl_hw, *((u32 *)&ndp_rate));

	if (ret != 0)
		goto err;

	return count;

err:
	cl_dbg_err(cl_hw, "ERROR! %d", ret);
	return -EFAULT;

err_param:
	if (iparam >= 0)
		cl_dbg_err(cl_hw, "\nError in param #%d\n", iparam + 1);
	cl_dbg_err(cl_hw, "%s", usage_str);
	return -EFAULT;
}

DEBUGFS_WRITE_FILE_OPS(ndp_rate);

static ssize_t cl_dbgfs_ndpa_rate_write(struct file *file,
					const char __user *user_buf,
					size_t count,
					loff_t *ppos)
{
	return cl_dbgfs_ndp_rate_write(file, user_buf, count, (loff_t *)~0);
}

DEBUGFS_WRITE_FILE_OPS(ndpa_rate);

static ssize_t cl_dbgfs_errsim_write(struct file *file,
				     const char __user *user_buf,
				     size_t count,
				     loff_t *ppos)
{
	struct cl_hw *cl_hw = file->private_data;
	char buf[32];
	int eobuf = min_t(size_t, sizeof(buf) - 1, count);

	buf[eobuf] = '\0';
	if (copy_from_user(&buf, user_buf, eobuf))
		return -EFAULT;

	if (!strncasecmp(buf, "wait4cfm", strlen("wait4cfm"))) {
		if (IS_PCI_BUS_TYPE(cl_hw->chip))
			cl_msg_cfm_simulate_timeout(cl_hw);
	} else if (!strncasecmp(buf, "ASSERT_ERR", strlen("ASSERT_ERR"))) {
		/* Send a faulty key index that will cause an ASSERT in FW */
		cl_dbg_err(cl_hw, "Send faulty del key request to FW to deliberately cause "
				  "ASSERT_ERR\n");
		cl_msg_tx_key_del(cl_hw, 0xFF);
	} else if (!strncasecmp(buf, "no-wait4cfm-ASSERT_ERR", strlen("no-wait4cfm-ASSERT_ERR"))) {
		/* Send a faulty key index that will cause an ASSERT in FW */
		cl_dbg_err(cl_hw, "Send faulty del key request to FW to deliberately cause "
				  "ASSERT_ERR with no wait4cfm\n");
		cl_msg_tx_key_del(cl_hw, 0xFF);
	} else {
		cl_dbg_err(cl_hw, "Unknown error request: %s\n", buf);
	}

	return count;
}

static ssize_t cl_dbgfs_errsim_read(struct file *file,
				    char __user *user_buf,
				    size_t count,
				    loff_t *ppos)
{
	static char buf[] = {
		"hwRestart0 - HW restart will be skipped when cl_restart_hw() is called "
		"(e.g. following wait4cfm timeout)\n"
		"hwRestart1 - HW restart will be executed if needed "
		"(e.g. following wait4cfm timeout)\n"
		"wait4cfm - simulate host wait4cfm. HW will restart\n"
		"ASSERT_ERR - simulate firmware assert followed by host wait4cmf and HW restart\n"
		"no-wait4cfm-ASSERT_ERR - simulate firmware assertion without Host wait4cfm\n "
	};
	int ret = 0;

	ret += snprintf(buf + ret, min_t(size_t, sizeof(buf) - ret, count),
			buf);

	buf[sizeof(buf) - 1] = '\0';

	return simple_read_from_buffer(user_buf, count, ppos, buf, ret);
}

DEBUGFS_READ_WRITE_FILE_OPS(errsim);

static ssize_t cl_dbgfs_rateidx_read(struct file *file,
				     char __user *user_buf,
				     size_t count,
				     loff_t *ppos)
{
	struct cl_hw *cl_hw = file->private_data;
	char buf[32];
	int ret;

	ret = snprintf(buf, min_t(size_t, sizeof(buf), count),
		       "%016llx\n", cl_hw->debugfs.rateidx);

	return simple_read_from_buffer(user_buf, count, ppos, buf, ret);
}

static ssize_t cl_dbgfs_rateidx_write(struct file *file,
				      const char __user *user_buf,
				      size_t count,
				      loff_t *ppos)
{
	struct cl_hw *cl_hw = file->private_data;
	char buf[32];
	unsigned long long result;
	int ret;
	int eobuf = min_t(size_t, sizeof(buf) - 1, count);

	buf[eobuf] = '\0';
	if (copy_from_user(&buf, user_buf, eobuf))
		return -EFAULT;

	ret = kstrtoull(buf, 16, &result);
	if (ret)
		return ret;

	cl_hw->debugfs.rateidx = result;

	return count;
}

DEBUGFS_READ_WRITE_FILE_OPS(rateidx);

static ssize_t cl_dbgfs_mactrace_read(struct file *file,
				      char __user *user_buf,
				      size_t count,
				      loff_t *ppos)
{
	struct cl_hw *cl_hw = file->private_data;
	ssize_t read;

	mutex_lock(&cl_hw->dbginfo.mutex);
	if (cl_hw->debugfs.trace_prst) {
		read = simple_read_from_buffer(user_buf, count, ppos,
					       &cl_hw->dbginfo.buf->u.dump.la_mem[0], LA_MEM_LEN);
	} else {
		pr_debug("No dump!\n");
		read = 0;
	}
	mutex_unlock(&cl_hw->dbginfo.mutex);

	return read;
}

static ssize_t cl_dbgfs_mactrace_write(struct file *file,
				       const char __user *user_buf,
				       size_t count,
				       loff_t *ppos)
{
	/* Write "1" to diags/mactrace triggers dump, type 0 (recoverable). */
	struct cl_hw *cl_hw = file->private_data;
	char buf[32];
	unsigned long v;
	int eobuf = min_t(size_t, sizeof(buf) - 1, count);

	if (cl_hw->debugfs.unregistering)
		return -EFAULT;

	if (copy_from_user(&buf, user_buf, eobuf))
		return -EFAULT;

	buf[eobuf] = '\0';
	if (kstrtoul(buf, 0, &v) || v != 1) {
		pr_debug("Usage: echo 1 > mactrace : trigger firmware dump\n");
		return -EFAULT;
	}

	mutex_lock(&cl_hw->dbginfo.mutex);
	if (cl_hw->debugfs.trace_prst) {
		pr_debug("Dump already waiting\n");
		mutex_unlock(&cl_hw->dbginfo.mutex);
		return -EFAULT;
	}

	scnprintf(buf, sizeof(buf), "Force trigger\n");
	cl_msg_tx_dbg_trigger(cl_hw, buf);
	mutex_unlock(&cl_hw->dbginfo.mutex);

	return count;
}

DEBUGFS_READ_WRITE_FILE_OPS(mactrace);

static ssize_t cl_dbgfs_phytrace_read(struct file *file,
				      char __user *user_buf,
				      size_t count,
				      loff_t *ppos)
{
#if LA_CNT < 2
	return -EFAULT; /* La_mem[1] does not exist */
#else
	struct cl_hw *cl_hw = file->private_data;
	ssize_t read;

	mutex_lock(&cl_hw->dbginfo.mutex);
	if (!cl_hw->debugfs.trace_prst) {
		mutex_unlock(&cl_hw->dbginfo.mutex);
		return 0;
	}

	read = simple_read_from_buffer(user_buf, count, ppos,
				       &cl_hw->dbginfo.buf->u.dump.la_mem[1], LA_MEM_LEN);
	mutex_unlock(&cl_hw->dbginfo.mutex);
	return read;
#endif
}

DEBUGFS_READ_FILE_OPS(phytrace);

static ssize_t cl_dbgfs_macdiags_read(struct file *file,
				      char __user *user_buf,
				      size_t count,
				      loff_t *ppos)
{
	struct cl_hw *cl_hw = file->private_data;
	ssize_t read;

	mutex_lock(&cl_hw->dbginfo.mutex);
	if (!cl_hw->debugfs.trace_prst) {
		mutex_unlock(&cl_hw->dbginfo.mutex);
		return 0;
	}

	read = simple_read_from_buffer(user_buf, count, ppos,
				       cl_hw->dbginfo.buf->u.dump.general_data.diags_mac,
				       DBG_DIAGS_MAC_MAX * 2);
	mutex_unlock(&cl_hw->dbginfo.mutex);

	return read;
}

DEBUGFS_READ_FILE_OPS(macdiags);

static ssize_t cl_dbgfs_dbg_dump_read(struct file *file,
				      char __user *user_buf,
				      size_t count,
				      loff_t *ppos)
{
	struct cl_hw *cl_hw = file->private_data;

	mutex_lock(&cl_hw->dbginfo.mutex);
	if (cl_hw->debugfs.trace_prst)
		cl_fw_dbg_dump_file(cl_hw);
	mutex_unlock(&cl_hw->dbginfo.mutex);

	return 0;
}

DEBUGFS_READ_FILE_OPS(dbg_dump);

static ssize_t cl_dbgfs_hwdiags_read(struct file *file,
				     char __user *user_buf,
				     size_t count,
				     loff_t *ppos)
{
	struct cl_hw *cl_hw = file->private_data;
	char buf[16];
	int ret;

	mutex_lock(&cl_hw->dbginfo.mutex);
	if (!cl_hw->debugfs.trace_prst) {
		mutex_unlock(&cl_hw->dbginfo.mutex);
		return 0;
	}

	ret = scnprintf(buf, min_t(size_t, sizeof(buf) - 1, count),
			"%08X\n", cl_hw->dbginfo.buf->u.dump.general_data.hw_diag);

	mutex_unlock(&cl_hw->dbginfo.mutex);
	return simple_read_from_buffer(user_buf, count, ppos, buf, ret);
}

DEBUGFS_READ_FILE_OPS(hwdiags);

static ssize_t cl_dbgfs_swdiags_read(struct file *file,
				     char __user *user_buf,
				     size_t count,
				     loff_t *ppos)
{
	struct cl_hw *cl_hw = file->private_data;
	ssize_t read;

	mutex_lock(&cl_hw->dbginfo.mutex);
	if (!cl_hw->debugfs.trace_prst) {
		mutex_unlock(&cl_hw->dbginfo.mutex);
		return 0;
	}

	read = simple_read_from_buffer(user_buf, count, ppos,
				       &cl_hw->dbginfo.buf->u.dump.general_data.sw_diag,
				       cl_hw->dbginfo.buf->u.dump.general_data.sw_diag_len);

	mutex_unlock(&cl_hw->dbginfo.mutex);
	return read;
}

DEBUGFS_READ_FILE_OPS(swdiags);

static ssize_t cl_dbgfs_lamacconf_read(struct file *file,
				       char __user *user_buf,
				       size_t count,
				       loff_t *ppos)
{
	struct cl_hw *cl_hw = file->private_data;
	ssize_t read;

	mutex_lock(&cl_hw->dbginfo.mutex);
	if (!cl_hw->debugfs.trace_prst) {
		mutex_unlock(&cl_hw->dbginfo.mutex);
		return 0;
	}

	read = simple_read_from_buffer(user_buf, count, ppos,
				       &cl_hw->dbginfo.buf->u.dump.general_data.la_conf[0],
				       sizeof(struct la_conf_tag));

	mutex_unlock(&cl_hw->dbginfo.mutex);
	return read;
}

DEBUGFS_READ_FILE_OPS(lamacconf);

static ssize_t cl_dbgfs_laphyconf_read(struct file *file,
				       char __user *user_buf,
				       size_t count,
				       loff_t *ppos)
{
	struct cl_hw *cl_hw = file->private_data;
	ssize_t read;

	mutex_lock(&cl_hw->dbginfo.mutex);
	if (!cl_hw->debugfs.trace_prst) {
		mutex_unlock(&cl_hw->dbginfo.mutex);
		return 0;
	}

	read = simple_read_from_buffer(user_buf, count, ppos,
				       &cl_hw->dbginfo.buf->u.dump.general_data.la_conf[1],
				       sizeof(struct la_conf_tag));

	mutex_unlock(&cl_hw->dbginfo.mutex);
	return read;
}

DEBUGFS_READ_FILE_OPS(laphyconf);

static ssize_t cl_dbgfs_chaninfo_read(struct file *file,
				      char __user *user_buf,
				      size_t count,
				      loff_t *ppos)
{
	struct cl_hw *cl_hw = file->private_data;
	struct phy_channel_info *chan_info = &cl_hw->dbginfo.buf->u.dump.general_data.chan_info;
	char buf[4 * 32];
	int ret;

	mutex_lock(&cl_hw->dbginfo.mutex);
	if (!cl_hw->debugfs.trace_prst) {
		mutex_unlock(&cl_hw->dbginfo.mutex);
		return 0;
	}

	ret = scnprintf(buf, min_t(size_t, sizeof(buf) - 1, count),
			"type:         %u\n"
			"prim20_freq:  %u MHz\n"
			"center1_freq: %u MHz\n"
			"center2_freq: %u MHz\n",
			(chan_info->info1 >> 8) & 0xFF,
			(chan_info->info1 >> 16) & 0xFFFF,
			(chan_info->info2 >> 0) & 0xFFFF,
			(chan_info->info2 >> 16) & 0xFFFF);

	mutex_unlock(&cl_hw->dbginfo.mutex);
	return simple_read_from_buffer(user_buf, count, ppos, buf, ret);
}

DEBUGFS_READ_FILE_OPS(chaninfo);

#define MAX_BUF_SIZE 512

static ssize_t cl_dbgfs_error_read(struct file *file,
				   char __user *user_buf,
				   size_t count,
				   loff_t *ppos)
{
	struct cl_hw *cl_hw = file->private_data;
	struct dbg_print_ind *ind =
		&cl_hw->dbginfo.buf->u.dump.fw_dump.common_info.error_info;
	ssize_t read;

	mutex_lock(&cl_hw->dbginfo.mutex);
	if (!cl_hw->debugfs.trace_prst) {
		mutex_unlock(&cl_hw->dbginfo.mutex);
		return 0;
	}

	/* If an assert message, search for assert string */
	if (ind->file_id && ind->line) {
		u16 file_id = le16_to_cpu(ind->file_id);
		u16 line = le16_to_cpu(ind->line);
		const char *assert_string = cl_dbgfile_get_msg_txt(&cl_hw->dbg_data, file_id, line);

		/* If string not found. use FW error string. */
		if (!assert_string)
			assert_string = cl_hw->dbginfo.buf->u.dump.general_data.error;

		read = simple_read_from_buffer(user_buf, count, ppos, assert_string,
					       strnlen(assert_string, MAX_BUF_SIZE));
	} else {
		char *error = cl_hw->dbginfo.buf->u.dump.general_data.error;

		read = simple_read_from_buffer(user_buf, count, ppos, error,
					       strnlen(error, DBG_ERROR_TRACE_SIZE));
	}

	mutex_unlock(&cl_hw->dbginfo.mutex);
	return read;
}

DEBUGFS_READ_FILE_OPS(error);

static ssize_t cl_dbgfs_um_helper_read(struct file *file,
				       char __user *user_buf,
				       size_t count,
				       loff_t *ppos)
{
	struct cl_hw *cl_hw = file->private_data;

	return cl_um_helper_read(cl_hw, user_buf, count, ppos);
}

static ssize_t cl_dbgfs_um_helper_write(struct file *file,
					const char __user *user_buf,
					size_t count,
					loff_t *ppos)
{
	struct cl_hw *cl_hw = file->private_data;

	return cl_um_helper_write(cl_hw, user_buf, count, ppos);
}

DEBUGFS_READ_WRITE_FILE_OPS(um_helper);

static ssize_t cl_dbgfs_mpifmask_write(struct file *file,
				       const char __user *user_buf,
				       size_t count,
				       loff_t *ppos)
{
	struct cl_hw *cl_hw = file->private_data;
	char buf[32];
	int ret;
	int eobuf = min_t(size_t, sizeof(buf) - 1, count);
	unsigned long long result;

	buf[eobuf] = '\0';
	if (copy_from_user(&buf, user_buf, eobuf))
		return -EFAULT;

	ret = kstrtoull(buf, 0, &result);
	if (ret)
		return ret;

	cl_dbg_trace(cl_hw, "Set LA mpif mask = 0x%08x\n", (u32)result);

	cl_msg_tx_dbg_set_la_mpif_mask(cl_hw, result);

	return count;
}

DEBUGFS_WRITE_FILE_OPS(mpifmask);

static ssize_t cl_dbgfs_trigpoint_write(struct file *file,
					const char __user *user_buf,
					size_t count,
					loff_t *ppos)
{
	struct cl_hw *cl_hw = file->private_data;
	char buf[32];
	int ret;
	int eobuf = min_t(size_t, sizeof(buf) - 1, count);
	unsigned long long result;

	buf[eobuf] = '\0';
	if (copy_from_user(&buf, user_buf, eobuf))
		return -EFAULT;

	ret = kstrtoull(buf, 0, &result);
	if (ret)
		return ret;

	cl_dbg_trace(cl_hw, "Set LA trigger point = 0x%x\n", (u32)result);

	cl_msg_tx_dbg_set_la_trig_point(cl_hw, result);

	return count;
}

DEBUGFS_WRITE_FILE_OPS(trigpoint);

enum {
	CL_LA_MPIF_DEBUG_MODE_GEN, /* Generic MPIF sampling mask */
	CL_LA_MPIF_DEBUG_MODE_TX,  /* Tx oriented MPIF sampling mask */
	CL_LA_MPIF_DEBUG_MODE_RX,  /* Rx oriented MPIF sampling mask */

	CL_LA_MPIF_DEBUG_MODE_NUM
};

static const char *ce_la_mpif_debug_mode_str[CL_LA_MPIF_DEBUG_MODE_NUM] = {
	[CL_LA_MPIF_DEBUG_MODE_GEN] = "LA_MPIF_DEBUG_MODE_GEN",
	[CL_LA_MPIF_DEBUG_MODE_TX]  = "LA_MPIF_DEBUG_MODE_TX",
	[CL_LA_MPIF_DEBUG_MODE_RX]  = "LA_MPIF_DEBUG_MODE_RX"
};

static ssize_t cl_dbgfs_mpif_debug_mode_write(struct file *file,
					      const char __user *user_buf,
					      size_t count,
					      loff_t *ppos)
{
	struct cl_hw *cl_hw = file->private_data;
	char buf[32];
	int ret;
	int eobuf = min_t(size_t, sizeof(buf) - 1, count);
	unsigned long long result;
	u8 mode;

	buf[eobuf] = '\0';
	if (copy_from_user(&buf, user_buf, eobuf))
		return -EFAULT;

	ret = kstrtoull(buf, 0, &result);
	if (ret)
		return ret;

	mode = (u8)result;
	if (mode >= CL_LA_MPIF_DEBUG_MODE_NUM)
		return -EINVAL;

	cl_dbg_trace(cl_hw, "Set LA MPIF mode = %u (%s)\n", mode, ce_la_mpif_debug_mode_str[mode]);

	cl_msg_tx_dbg_set_la_mpif_debug_mode(cl_hw, result);

	return count;
}

DEBUGFS_WRITE_FILE_OPS(mpif_debug_mode);

static char *la_trig_oper_str[LA_TRIG_OPER_MAX] = {
	[LA_TRIG_OPER_EQ] = "eq",
	[LA_TRIG_OPER_NOT_EQ] = "neq",
	[LA_TRIG_OPER_GT] = "gt",
	[LA_TRIG_OPER_GT_EQ] = "gte",
	[LA_TRIG_OPER_LT] = "lt",
	[LA_TRIG_OPER_LT_EQ] = "lte"
};

static ssize_t cl_dbgfs_trig_rule_write(struct file *file,
					const char __user *user_buf,
					size_t count,
					loff_t *ppos)
{
	struct cl_hw *cl_hw = file->private_data;
	char buf[100];
	int ret = 0;
	int eobuf = min_t(size_t, sizeof(buf) - 1, count);
	char *sptr = NULL, *token = NULL;
	unsigned long val;
	u32 address = 0, value = 0, mask = 0, duration = 0;
	u8 idx = 0, oper = 0;
	bool enable = false;
	char *usage_str = "Usage:\n"
			  "echo  <rule-idx> <enable {1|0}> <address> <oper {eq|neq|gt|gte|lt|lte}>"
			  " <value> <mask> [duration] > trig_rule\n";

	buf[eobuf] = '\0';
	if (copy_from_user(&buf, user_buf, eobuf))
		return -EFAULT;

	sptr = buf;

	token = strsep(&sptr, " ");
	if (!token) {
		pr_err("Illegal token.\n%s", usage_str);
		return -EINVAL;
	}

	ret = kstrtoul(token, 0, &val);
	if (ret) {
		pr_err("<rule-idx> illegal value (%s)\n%s", token, usage_str);
		return -EINVAL;
	}

	idx = (u8)val;

	token = strsep(&sptr, " ");
	if (!token) {
		pr_err("Illegal token.\n%s", usage_str);
		return -EINVAL;
	}

	ret = kstrtoul(token, 0, &val);
	if (ret) {
		pr_err("<enable> illegal value (%s)\n%s", token, usage_str);
		return -EINVAL;
	}

	enable = (bool)val;

	if (enable) {
		/* Address token */
		token = strsep(&sptr, " ");
		if (!token) {
			pr_err("Illegal token.\n%s", usage_str);
			return -EINVAL;
		}

		ret = kstrtoul(token, 0, &val);
		if (ret) {
			pr_err("<address> illegal value (%s)\n%s", token, usage_str);
			return -EINVAL;
		}

		address = val;

		/* Comparison Operator token */
		token = strsep(&sptr, " ");
		if (!token) {
			pr_err("Illegal token.\n%s", usage_str);
			return -EINVAL;
		}

		for (oper = LA_TRIG_OPER_EQ; oper < LA_TRIG_OPER_MAX; ++oper)
			if (!strcmp(token, la_trig_oper_str[oper]))
				break;

		if (oper == LA_TRIG_OPER_MAX) {
			pr_err("<oper> illegal value (%s)\n%s", token, usage_str);
			return -EINVAL;
		}

		/* Value token */
		token = strsep(&sptr, " ");
		if (!token) {
			pr_err("Illegal token.\n%s", usage_str);
			return -EINVAL;
		}

		ret = kstrtoul(token, 0, &val);
		if (ret) {
			pr_err("<value> illegal value (%s)\n%s", token, usage_str);
			return -EINVAL;
		}

		value = val;

		/* Mask token */
		token = strsep(&sptr, " ");
		if (!token) {
			pr_err("Illegal token.\n%s", usage_str);
			return -EINVAL;
		}

		ret = kstrtoul(token, 0, &val);
		if (ret) {
			pr_err("<mask> illegal value (%s)\n%s", token, usage_str);
			return -EINVAL;
		}

		mask = val;

		/* Duration token (optional) */
		token = strsep(&sptr, " ");
		if (token) {
			ret = kstrtoul(token, 0, &val);
			if (ret) {
				pr_err("<duration> illegal value (%s)\n%s", token, usage_str);
				return -EINVAL;
			}

			duration = val;
		}
	}

	if (enable)
		pr_debug("Set trigger rule: idx=%u, addr=0x%08x, oper=%s, value=0x%08x, "
			 "mask=0x%08x, duration=%u\n",
			 idx, address, la_trig_oper_str[oper], value, mask, duration);
	else
		pr_debug("Disable trigger rule: idx=%u\n", idx);

	if (cl_msg_tx_dbg_set_la_trig_rule(cl_hw, idx, enable, address, oper,
					   value, mask, duration))
		return -EFAULT;

	return count;
}

DEBUGFS_WRITE_FILE_OPS(trig_rule);

static ssize_t cl_dbgfs_sounding_req_write(struct file *file,
					   const char __user *user_buf,
					   size_t count,
					   loff_t *ppos)
{
	struct mm_sounding_cfm *sounding_cfm = NULL;
	struct cl_hw *cl_hw = file->private_data;
	char buf[32], *sptr, *token;
	int i;
	int ret = 0;
	u32 fields[] = {-1, -1, -1, -1, -1, -1, -1};
	struct mm_sounding_req sounding_req = {{{0}}};
	const u8 field_widths[] = {
		8,  /* Sta_idx */
		1,  /* Start - if set we start the periodic BF */
		3,  /* Sounding type - e.g. SOUNDING_TYPE_VHT_SU = 1*/
		2,  /* Requested txbw for sounding sequence */
		2,  /* Ndp nss - NDP (NSS -1) */
		10, /* Sounding interval */
		12  /* BFR lifetime */
	};

	size_t eobuf = min_t(size_t, sizeof(buf) - 1, count);

	if (eobuf < count || eobuf < 1)
		goto err_param;

	if (copy_from_user(&buf, user_buf, eobuf))
		goto err_param;

	buf[eobuf] = '\0';
	sptr = buf;

	for (i = 0; i < ARRAY_SIZE(fields); i++) {
		unsigned long ulv;

		token = strsep(&sptr, " ");
		if (!token) {
			cl_dbg_err(cl_hw, "param idx - %d value invalid\n", i);
			goto err_param;
		}

		if (kstrtoul(token, 16, &ulv) || (ulv >= (1U << field_widths[i]))) {
			cl_dbg_err(cl_hw, "param idx - %d value invalid\n", i);
			goto err_param;
		}
		fields[i] = ulv;
	}

	if (!cl_sta_is_assoc(cl_hw, fields[0])) {
		cl_dbg_err(cl_hw, "error, station with index %u does not exit\n", fields[0]);
		goto err_param;
	}

	sounding_req.info_per_sta[0].sta_idx = fields[0];
	sounding_req.start = fields[1];
	sounding_req.sounding_type = fields[2];
	sounding_req.req_txbw = fields[3];
	sounding_req.ndp_nsts = fields[4];
	sounding_req.interval = fields[5];
	sounding_req.lifetime = fields[6];

	cl_dbg_trace(cl_hw, "sounding req configuration: <bfr_lifetime: %u>, <interval: %u>, "
		     "<req_txbw: %u>, <ndp_nsts: %u>, <start: %u>, <sounding_type: %u>\n",
		     sounding_req.lifetime, sounding_req.interval, sounding_req.req_txbw,
		     sounding_req.ndp_nsts, sounding_req.start, sounding_req.sounding_type);

	/* Trigger synchronious sounding req without call back function and with response param */
	ret = cl_msg_tx_sounding(cl_hw, &sounding_req);

	sounding_cfm = (struct mm_sounding_cfm *)cl_hw->msg_cfm_params[MM_SOUNDING_CFM];

	if (!sounding_cfm)
		goto err_param;

	switch (sounding_cfm->param_err) {
	case CL_SOUNDING_RSP_OK:
		cl_dbg_err(cl_hw, "param OK!\n");
		return count;
	case CL_SOUNDING_RSP_ERR_RLIMIT:
		cl_dbg_err(cl_hw, "error, resource limit reached\n");
		break;
	case CL_SOUNDING_RSP_ERR_BW:
		cl_dbg_err(cl_hw, "error, unsupported BW tx requested\n");
		break;
	case CL_SOUNDING_RSP_ERR_NSS:
		cl_dbg_err(cl_hw, "error, unsupported ndp NSS tx requested\n");
		break;
	case CL_SOUNDING_RSP_ERR_INTERVAL:
		cl_dbg_err(cl_hw, "error, interval value is invalid\n");
		break;
	case CL_SOUNDING_RSP_ERR_ALREADY:
		cl_dbg_err(cl_hw, "error, station sounding already associated/disassociated\n");
		break;
	case CL_SOUNDING_RSP_ERR_STA:
		cl_dbg_err(cl_hw, "error, station is inactive/active\n");
		break;
	case CL_SOUNDING_RSP_ERR_TYPE:
		cl_dbg_err(cl_hw, "error, invalid sounding type\n");
		break;
	default:
		cl_dbg_err(cl_hw, "error status unknown, BUG\n");
		break;
	}

	cl_msg_tx_free_cfm_params(cl_hw, MM_SOUNDING_CFM);

	return -EFAULT;

err_param:
	cl_dbg_err(cl_hw, "Usage: echo  [sta_idx] [start] [sounding_type] [requested_txbw] "
		   "[ndp_nss] [interval] [bfr_lifetime] > sounding_req\n");
	cl_dbg_err(cl_hw, "[sta_idx - %u] [start - %u] [sounding_type - %u] [requested_txbw - %u] "
		   "[ndp_nss - %u] [interval - %u] [bfr_lifetime - %u]\n",
		   fields[0], fields[1], fields[2], fields[3], fields[4], fields[5], fields[6]);

	return -EFAULT;
}

DEBUGFS_WRITE_FILE_OPS(sounding_req);

#ifdef NATT_DBG
static ssize_t cl_dbgfs_natt_test_write(struct file *file,
					const char __user *user_buf,
					size_t count,
					loff_t *ppos)
{
	struct cl_hw *cl_hw = file->private_data;
	char buf[32];
	int ret;
	unsigned long long max_num_valid_mpdu = 0;
	unsigned long long non_valid_mpdu_rate = 0;
	unsigned long long force_min_spacing_mode = 0;
	unsigned long long min_spacing = 0;
	unsigned long long non_data1_len = 0;
	unsigned long long non_data1_num = 0;
	unsigned long long non_data1_padding = 0;
	unsigned long long non_data2_len = 0;
	unsigned long long non_data2_num = 0;
	unsigned long long non_data2_padding = 0;
	unsigned long long airtime_limit = 0;
	unsigned long long last_desc_set = 0;
	char *sptr, *token1, *token2, *token3, *token4, *token5, *token6, *token7, *token8,
		*token9, *token10, *token11, *token12;
	char *usage_str = "Usage:\n"
			  "echo [max_num_valid_mpdu] [non_valid_mpdu_rate] [force_min_spacing_mode]"
			  " [min_spacing] [non_data1_len] [non_data1_num] [non_data1_padding]"
			  " [non_data2_len] [non_data2_num] [non_data2_padding] [airtime_limit]"
			  " [last_desc_set] > natt_test\n";

	struct natt_testing_param natt_params;

	int eobuf = min_t(size_t, sizeof(buf) - 1, count);

	buf[eobuf] = '\0';
	if (copy_from_user(&buf, user_buf, eobuf)) {
		cl_dbg_err(cl_hw, "illegal input\n %s", usage_str);
		return -EFAULT;
	}

	sptr = buf;

	token1 = strsep(&sptr, " ");
	if (!token1) {
		cl_dbg_err(cl_hw, "Token1 illegal\n %s", usage_str);
		return -EINVAL;
	}

	ret = kstrtoull(token1, 0, &max_num_valid_mpdu);
	if (ret) {
		cl_dbg_err(cl_hw, "Token1 %s illegal convert\n %s", token1, usage_str);
		return ret;
	}

	token2 = strsep(&sptr, " ");
	if (!token2) {
		cl_dbg_err(cl_hw, "Token2 illegal\n %s ", usage_str);
		return -EINVAL;
	}

	ret = kstrtoull(token2, 0, &non_valid_mpdu_rate);
	if (ret) {
		cl_dbg_err(cl_hw, "Token2 %s illegal convert\n %s", token2, usage_str);
		return ret;
	}

	token3 = strsep(&sptr, " ");
	if (!token3) {
		cl_dbg_err(cl_hw, "Token3 illegal\n %s ", usage_str);
		return -EINVAL;
	}

	ret = kstrtoull(token3, 0, &force_min_spacing_mode);
	if (ret) {
		cl_dbg_err(cl_hw, "Token3 %s illegal convert\n %s", token3, usage_str);
		return ret;
	}

	token4 = strsep(&sptr, " ");
	if (!token4) {
		cl_dbg_err(cl_hw, "Token4 illegal\n %s ", usage_str);
		return -EINVAL;
	}

	ret = kstrtoull(token4, 0, &min_spacing);
	if (ret) {
		cl_dbg_err(cl_hw, "Token4 %s illegal convert\n %s", token4, usage_str);
		return ret;
	}

	token5 = strsep(&sptr, " ");
	if (!token5) {
		cl_dbg_err(cl_hw, "Token5 illegal\n %s ", usage_str);
		return -EINVAL;
	}

	ret = kstrtoull(token5, 0, &non_data1_len);
	if (ret) {
		cl_dbg_err(cl_hw, "Token5 %s illegal convert\n %s", token5, usage_str);
		return ret;
	}

	token6 = strsep(&sptr, " ");
	if (!token6) {
		cl_dbg_err(cl_hw, "Token6 illegal\n %s ", usage_str);
		return -EINVAL;
	}

	ret = kstrtoull(token6, 0, &non_data1_num);
	if (ret) {
		cl_dbg_err(cl_hw, "Token6 %s illegal convert\n %s", token6, usage_str);
		return ret;
	}

	token7 = strsep(&sptr, " ");
	if (!token7) {
		cl_dbg_err(cl_hw, "Token7 illegal\n %s ", usage_str);
		return -EINVAL;
	}

	ret = kstrtoull(token7, 0, &non_data1_padding);
	if (ret) {
		cl_dbg_err(cl_hw, "Token7 %s illegal convert\n %s", token7, usage_str);
		return ret;
	}

	token8 = strsep(&sptr, " ");
	if (!token8) {
		cl_dbg_err(cl_hw, "Token8 illegal\n %s ", usage_str);
		return -EINVAL;
	}

	ret = kstrtoull(token8, 0, &non_data2_len);
	if (ret) {
		cl_dbg_err(cl_hw, "Token8 %s illegal convert\n %s", token8, usage_str);
		return ret;
	}

	token9 = strsep(&sptr, " ");
	if (!token9) {
		cl_dbg_err(cl_hw, "Token9 illegal\n %s ", usage_str);
		return -EINVAL;
	}

	ret = kstrtoull(token9, 0, &non_data2_num);
	if (ret) {
		cl_dbg_err(cl_hw, "Token9 %s illegal convert\n %s", token9, usage_str);
		return ret;
	}

	token10 = strsep(&sptr, " ");
	if (!token10) {
		cl_dbg_err(cl_hw, "Token10 illegal\n %s ", usage_str);
		return -EINVAL;
	}

	ret = kstrtoull(token10, 0, &non_data2_padding);
	if (ret) {
		cl_dbg_err(cl_hw, "Token10 %s illegal convert\n %s", token10, usage_str);
		return ret;
	}

	token11 = strsep(&sptr, " ");
	if (!token11) {
		cl_dbg_err(cl_hw, "Token11 illegal\n %s ", usage_str);
		return -EINVAL;
	}

	ret = kstrtoull(token11, 0, &airtime_limit);
	if (ret) {
		cl_dbg_err(cl_hw, "Token11 %s illegal convert\n %s", token11, usage_str);
		return ret;
	}

	token12 = strsep(&sptr, " ");
	if (!token12) {
		cl_dbg_err(cl_hw, "Token12 illegal\n %s ", usage_str);
		return -EINVAL;
	}

	ret = kstrtoull(token12, 0, &last_desc_set);
	if (ret) {
		cl_dbg_err(cl_hw, "Token12 %s illegal convert\n %s", token12, usage_str);
		return ret;
	}

	natt_params.max_num_valid_mpdu = max_num_valid_mpdu;
	natt_params.non_valid_mpdu_rate = non_valid_mpdu_rate;
	natt_params.force_min_spacing_mode = force_min_spacing_mode;
	natt_params.min_spacing = min_spacing;
	natt_params.non_data1_len = non_data1_len;
	natt_params.non_data1_num = non_data1_num;
	natt_params.non_data1_padding = non_data1_padding;
	natt_params.non_data2_len = non_data2_len;
	natt_params.non_data2_num = non_data2_num;
	natt_params.non_data2_padding = non_data2_padding;
	natt_params.airtime_limit = airtime_limit;
	natt_params.last_desc_set = last_desc_set;

	cl_dbg_err(cl_hw, "%u %u %u %u %u %u %u %u %u %u %u %u\n",
		   natt_params.max_num_valid_mpdu,
		   natt_params.non_valid_mpdu_rate,
		   natt_params.force_min_spacing_mode,
		   natt_params.min_spacing,
		   natt_params.non_data1_len,
		   natt_params.non_data1_num,
		   natt_params.non_data1_padding,
		   natt_params.non_data2_len,
		   natt_params.non_data2_num,
		   natt_params.non_data2_padding,
		   natt_params.airtime_limit,
		   natt_params.last_desc_set);

	if (cl_msg_tx_natt_test(cl_hw, &natt_params)) {
		cl_dbg_error(cl_hw, "Failed to execute natt testing\n");
		return -EFAULT;
	}

	return count;
}

DEBUGFS_WRITE_FILE_OPS(natt_test);
#endif /* NATT_DBG */

#ifdef PRESILICON_TESTING
enum {
	CL_PRESILICON_TEST_HELP = 0,
	CL_PRESILICON_TEST_24G = 1,
	CL_PRESILICON_TEST_ELA = 2,
	CL_PRESILICON_TEST_BASIC_TRIGGER = 3,
	CL_PRESILICON_TEST_TX_POWER = 4,
	CL_PRESILICON_TEST_UORA_BASIC_TRIGGER = 5,
	CL_PRESILICON_TEST_UORA_SET_UPLINK_BSSID = 6,
	CL_PRESILICON_TEST_TXVECTOR_ERROR = 7,
	CL_PRESILICON_TEST_MAX
};

static u32 presilicon_testing_param_num[CL_PRESILICON_TEST_MAX] = {
	[CL_PRESILICON_TEST_HELP] = 0,
	[CL_PRESILICON_TEST_24G] = 4,
	[CL_PRESILICON_TEST_ELA] = 1,
	[CL_PRESILICON_TEST_BASIC_TRIGGER] = 7 + MAX_NUM_OF_SIMULTANEUS_UL_STREAMS * 2,
	[CL_PRESILICON_TEST_TX_POWER] = 4,
	[CL_PRESILICON_TEST_UORA_BASIC_TRIGGER] = 6 + MAX_NUM_OF_SIMULTANEUS_UL_STREAMS * 2,
	[CL_PRESILICON_TEST_UORA_SET_UPLINK_BSSID] = 2,
	[CL_PRESILICON_TEST_TXVECTOR_ERROR] = 3,
};

static ssize_t cl_dbgfs_presilicon_test_write(struct file *file,
					      const char __user *user_buf,
					      size_t count,
					      loff_t *ppos)
{
	struct cl_hw *cl_hw = file->private_data;
	char buf[100];
	int ret;
	u32 i = 0;
	struct presilicon_testing_param presilicon_testing_parameters;
	unsigned long long test_index = 0;
	unsigned long long param[PRESILICON_TEST_MAX_PARAMS] = {0};
	char *sptr, *token[PRESILICON_TEST_MAX_PARAMS + 1];
	char *usage_str = "Usage:\n"
			  "scripts/debugfsh <chip> <tcv> presilicon_test [presilicon_test_index] "
			  "[param1] [param2] ...\n";
	int eobuf = min_t(size_t, sizeof(buf) - 1, count);

	buf[eobuf] = '\0';
	if (copy_from_user(&buf, user_buf, eobuf)) {
		cl_dbg_err(cl_hw, "illegal input\n %s", usage_str);
		return -EFAULT;
	}

	sptr = buf;
	token[PRESILICON_TEST_MAX_PARAMS] = strsep(&sptr, " ");

	if (!token[PRESILICON_TEST_MAX_PARAMS]) {
		cl_dbg_err(cl_hw, "presilicon test index illegal %s\n", usage_str);
		return -EINVAL;
	}

	ret = kstrtoull(token[PRESILICON_TEST_MAX_PARAMS], 0, &test_index);
	if (ret) {
		cl_dbg_err(cl_hw, "Token1 %s illegal convert %s\n",
			   token[PRESILICON_TEST_MAX_PARAMS], usage_str);
		return ret;
	}

	if (test_index >= CL_PRESILICON_TEST_MAX) {
		cl_dbg_err(cl_hw, "presilicon test index illegal - %llu %s\n",
			   test_index, usage_str);
		return -EINVAL;
	}

	presilicon_testing_parameters.presilicon_test_index = cpu_to_le32(test_index);

	cl_dbg_err(cl_hw, "presilicon test index %llu, num_of_params = %u\n",
		   test_index, presilicon_testing_param_num[test_index]);

	for (i = 0; i < presilicon_testing_param_num[test_index]; i++) {
		token[i] = strsep(&sptr, " ");
		if (!token[i]) {
			cl_dbg_err(cl_hw, "Token %u illegal\n %s ",
				   i + 1, usage_str);
			return -EINVAL;
		}

		ret = kstrtoull(token[i], 0, &param[i]);
		if (ret) {
			cl_dbg_err(cl_hw, "Token %u %s illegal convert\n %s",
				   i, token[i], usage_str);
			return ret;
		}

		presilicon_testing_parameters.param[i] = cpu_to_le32(param[i]);
		cl_dbg_err(cl_hw, "Parameter %u value 0x%x\n",
			   i, presilicon_testing_parameters.param[i]);
	}

	if (cl_msg_tx_dbg_presilicon_test(cl_hw, &presilicon_testing_parameters)) {
		cl_dbg_err(cl_hw, "%s: Failed to execute presilicon testing\n", __func__);
		return -EFAULT;
	}

	return count;
}

DEBUGFS_WRITE_FILE_OPS(presilicon_test);
#endif /* PRESILICON_TESTING */

int cl_dbgfs_register(struct cl_hw *cl_hw, const char *name)
{
	struct dentry *phyd = cl_hw->hw->wiphy->debugfsdir;
	struct cl_debugfs *debugfs = &cl_hw->debugfs;
	struct dentry *dir_drv, *dir_diags, *dir_cl;

	cl_dbg_trace(cl_hw, "/sys/kernel/debug/%s/%s/%s\n",
		     phyd->d_parent->d_name.name, phyd->d_name.name, name);

	dir_drv = debugfs_create_dir(name, phyd);
	if (!dir_drv)
		return -ENOMEM;

	dir_diags = debugfs_create_dir("diags", dir_drv);
	if (!dir_diags)
		goto err;

	dir_cl = debugfs_create_dir("cl6k", dir_drv);
	if (!dir_cl) {
		cl_dbg_err(cl_hw, "%s\n", name);
		goto err;
	}

	cl_um_helper_init(cl_hw, dir_drv);

	debugfs_create_x64("rateidx", 0600, dir_drv, &debugfs->rateidx);

	DEBUGFS_ADD_FILE(um_helper,           dir_drv,   0600);
	DEBUGFS_ADD_FILE(dbg_dump,            dir_diags, 0400);
	DEBUGFS_ADD_FILE(mactrace,            dir_diags, 0400);
	DEBUGFS_ADD_FILE(phytrace,            dir_diags, 0400);
	DEBUGFS_ADD_FILE(macdiags,            dir_diags, 0400);
	DEBUGFS_ADD_FILE(hwdiags,             dir_diags, 0400);
	DEBUGFS_ADD_FILE(swdiags,             dir_diags, 0400);
	DEBUGFS_ADD_FILE(error,               dir_diags, 0400);
	DEBUGFS_ADD_FILE(lamacconf,           dir_diags, 0400);
	DEBUGFS_ADD_FILE(laphyconf,           dir_diags, 0400);
	DEBUGFS_ADD_FILE(chaninfo,            dir_diags, 0400);
	DEBUGFS_ADD_FILE(trigpoint,           dir_diags, 0200);
	DEBUGFS_ADD_FILE(mpifmask,            dir_diags, 0200);
	DEBUGFS_ADD_FILE(mpif_debug_mode,     dir_diags, 0200);
	DEBUGFS_ADD_FILE(benson,              dir_cl,    0200);
	DEBUGFS_ADD_FILE(set_debug,           dir_cl,    0200);
	DEBUGFS_ADD_FILE(beamform_cmd,        dir_cl,    0200);
	DEBUGFS_ADD_FILE(stat_print,          dir_cl,    0200);
	DEBUGFS_ADD_FILE(ba_session,          dir_cl,    0200);
	DEBUGFS_ADD_FILE(test_mode,           dir_cl,    0200);
	DEBUGFS_ADD_FILE(fixed_rate,          dir_cl,    0200);
	DEBUGFS_ADD_FILE(tx_trace_debug_flag, dir_cl,    0200);
	DEBUGFS_ADD_FILE(errsim,              dir_cl,    0600);
	DEBUGFS_ADD_FILE(ndp_rate,            dir_cl,    0200);
	DEBUGFS_ADD_FILE(ndpa_rate,           dir_cl,    0200);
	DEBUGFS_ADD_FILE(trig_rule,           dir_cl,    0200);
	DEBUGFS_ADD_FILE(sounding_req,        dir_cl,    0200);
	DEBUGFS_ADD_FILE(sounding_cmd,        dir_cl,    0200);
#ifdef NATT_DBG
	DEBUGFS_ADD_FILE(natt_test,           dir_cl,    0200);
#endif
#ifdef PRESILICON_TESTING
	DEBUGFS_ADD_FILE(presilicon_test,     dir_cl,    0200);
#endif

	return 0;

err:
	cl_dbgfs_unregister(cl_hw);
	return -ENOMEM;
}

void cl_dbgfs_unregister(struct cl_hw *cl_hw)
{
	cl_um_helper_close(cl_hw);
}

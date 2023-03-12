// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include <linux/delay.h>
#include "lcu.h"
#include "core_debug.h"
#include "file.h"
#include "reg_lcu_common.h"
#include "reg_lcu_phy.h"

static int __must_check get_lcu_cmd_type(char *cmd, int *expected_tokens_cnt)
{
	if (!strncmp(CL_LCU_MEM_WRITE_CMD_STR, cmd, CL_LCU_MEM_WRITE_CMD_SZ)) {
		*expected_tokens_cnt = CL_LCU_MEM_WRITE_TOKENS_CNT;
		return CL_LCU_CMD_TYPE_MEM_WRITE;
	} else if (!strncmp(CL_LCU_MEM_RMW_CMD_STR, cmd, CL_LCU_MEM_RMW_CMD_SZ)) {
		*expected_tokens_cnt = CL_LCU_MEM_RMW_TOKENS_CNT;
		return CL_LCU_CMD_TYPE_MEM_RMW;
	}

	return CL_LCU_CMD_TYPE_UNKNOWN;
}

static int add_lcu_cmd(struct cl_lcu_db *lcu, u32 type, u32 offset, u32 param1,
		       u32 param2, u32 param3)
{
	struct cl_lcu_cmd *cmd = NULL;

	cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
	if (!cmd)
		return -ENOMEM;

	cmd->type = type;
	cmd->offset = offset;

	switch (type) {
	case CL_LCU_CMD_TYPE_MEM_WRITE:
		cmd->mask = 0xFFFFFFFF;
		cmd->lsb = 0;
		cmd->value = param1;
		break;
	case CL_LCU_CMD_TYPE_MEM_RMW:
		cmd->mask = param1;
		cmd->lsb = param2;
		cmd->value = param3;
		break;
	}

	list_add_tail(&cmd->cmd_list, &lcu->cmd_head);

	return 0;
}

static void remove_lcu_cmd(struct cl_lcu_cmd *cmd)
{
	list_del(&cmd->cmd_list);
	kfree(cmd);
}

static int load_cmds_from_buf(struct cl_chip *chip, char *buf, size_t size)
{
	struct cl_lcu_db *lcu = &chip->lcu_db;
	char *line = buf;
	char cmd[STR_LEN_256B];
	u32 type = CL_LCU_CMD_TYPE_UNKNOWN;
	u32 offset = 0;
	u32 param1 = 0, param2 = 0, param3 = 0;
	int tokens_cnt = 0;
	int expected_tokens_cnt = 0;
	int ret = 0;

	while (line && strlen(line) && (line != (buf + size))) {
		if ((*line == '#') || (*line == '\n')) {
			/* Skip comment or blank line */
			line = strstr(line, "\n") + 1;
		} else if (*line) {
			tokens_cnt = sscanf(line, "%s %x %x %x %x\n",
					    cmd, &offset, &param1, &param2, &param3);
			cl_dbg_chip_trace(chip,
					  "tokens(%d):cmd(%s), offset(%#X), param1(%#X), param2(%#X), param3(%#X)\n",
					  tokens_cnt, cmd, offset, param1, param2, param3);

			type = get_lcu_cmd_type(cmd, &expected_tokens_cnt);
			if (type == CL_LCU_CMD_TYPE_UNKNOWN) {
				cl_dbg_chip_trace(chip, "Detected extra token, skipping\n");
				goto newline;
			}
			if (tokens_cnt != expected_tokens_cnt) {
				cl_dbg_chip_err(chip,
						"Tokens count is wrong! (%d != %d)\n",
						expected_tokens_cnt,
						tokens_cnt);
				ret = -EBADMSG;
				goto exit;
			}

			ret = add_lcu_cmd(lcu, type, offset, param1, param2, param3);
			if (ret)
				goto exit;

newline:
			line = strstr(line, "\n") + 1;
		}
	}

exit:
	return ret;
}

static bool cl_lcu_ela_is_default(struct cl_chip *chip)
{
	return !strncmp(CL_LCU_MODE_DFLT_ALIAS, chip->conf->ce_ela_mode,
			sizeof(chip->conf->ce_ela_mode));
}

static char *cl_lcu_config_name(struct cl_chip *chip)
{
	if (!cl_lcu_ela_is_on(chip))
		return CL_LCU_MODE_DFLT_OFF;

	if (cl_lcu_ela_is_default(chip))
		return CL_LCU_MODE_DFLT_SYMB_LINK;

	return chip->conf->ce_ela_mode;
}

static int cl_lcu_config_read_from_file(struct cl_chip *chip)
{
	struct cl_lcu_db *lcu = &chip->lcu_db;
	char filename[CL_FILENAME_MAX] = {0};
	size_t size = 0;
	int ret = 0;

	snprintf(filename, sizeof(filename), "%s", cl_lcu_config_name(chip));
	size = cl_file_open_and_read(chip, filename, &lcu->raw_lcu_config);
	if (!lcu->raw_lcu_config) {
		ret = -ENODATA;
		goto exit;
	}

	ret = load_cmds_from_buf(chip, lcu->raw_lcu_config, size);
exit:
	lcu->error_state = ret;
	return ret;
}

bool cl_lcu_ela_is_on(struct cl_chip *chip)
{
	return !!strncmp(CL_LCU_MODE_DFLT_OFF, chip->conf->ce_ela_mode,
			 sizeof(chip->conf->ce_ela_mode));
}
EXPORT_SYMBOL(cl_lcu_ela_is_on);

void cl_lcu_stop(struct cl_chip *chip)
{
	/* LCU_COMMON_REC_CMD  STOP */
	lcu_common_rec_cmd_pack(chip, 1, 0, 0);

	/* LCU_BT_START_EN, stop all triggers */
	lcu_common_lcu_bt_start_en_set(chip, 0);

	/* LCU_BT_STOP_EN, stop all triggers */
	lcu_common_lcu_bt_stop_en_set(chip, 0);

	/* LCU_COMMON_LCU_BT_EN  STOP*/
	lcu_common_lcu_bt_en_set(chip, 0x0);
}
EXPORT_SYMBOL(cl_lcu_stop);

void cl_lcu_apply_config(struct cl_chip *chip)
{
	struct cl_lcu_db *lcu = &chip->lcu_db;
	struct cl_lcu_cmd *cmd = NULL;

	if (lcu->error_state) {
		cl_dbg_chip_err(chip, "Active ELA LCU config is not valid\n");
		return;
	}

	/* Call a hardware reset of LCU unit first */
	lcu_common_sw_rst_set(chip, 0x1);
	lcu_phy_lcu_sw_rst_set(chip, 0x1);

	/* Need to wait at least 6 of 320 MHz clocks until sw_rst bit clears
	 * There is no way to read sw_rst bit from hardware
	 */
	msleep(1);

	list_for_each_entry(cmd, &lcu->cmd_head, cmd_list) {
		u32 read_value = 0;
		u32 write_value = 0;

		switch (cmd->type) {
		case CL_LCU_CMD_TYPE_MEM_WRITE:
			write_value = cmd->value;
			break;
		case CL_LCU_CMD_TYPE_MEM_RMW:
			read_value = cl_reg_read(chip, cmd->offset);
			write_value = (read_value & ~cmd->mask) | (cmd->value << cmd->lsb);
			break;
		default:
			continue;
		}

		cl_dbg_chip_trace(chip, "Writing cmd (%#X, %#X)\n",
				  cmd->offset, write_value);
		cl_reg_write(chip, cmd->offset, write_value);
	}
}
EXPORT_SYMBOL(cl_lcu_apply_config);

int cl_lcu_init(struct cl_chip *chip)
{
	struct cl_lcu_db *lcu = &chip->lcu_db;
	int ret = 0;

	if (!cl_lcu_ela_is_on(chip))
		return 0;

	INIT_LIST_HEAD(&lcu->cmd_head);
	ret = cl_lcu_config_read_from_file(chip);
	if (ret == 0) {
		cl_lcu_stop(chip);
		cl_lcu_apply_config(chip);
	}

	return ret;
}

void cl_lcu_deinit(struct cl_chip *chip)
{
	struct cl_lcu_db *lcu = &chip->lcu_db;
	struct cl_lcu_cmd *cmd = NULL, *cmd_tmp = NULL;

	if (!lcu->raw_lcu_config)
		return;

	kfree(lcu->raw_lcu_config);
	lcu->raw_lcu_config = NULL;

	list_for_each_entry_safe(cmd, cmd_tmp, &lcu->cmd_head, cmd_list)
		remove_lcu_cmd(cmd);
}


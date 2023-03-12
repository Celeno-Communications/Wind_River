// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_hw_assert.h"
#include "cl_recovery.h"
#include "cl_dbgfile.h"
#include "reg_access.h"

#define ASSERT_PATTERN 0xC0DEDEAD

/*
 * Function will take time stamp for each hw error indication.
 * when time diff between each error is less than ce_hw_assert_time_max
 * cl_hw_restart work will be scheduled
 */
static bool cl_hw_assert_storm_detect(struct cl_hw *cl_hw)
{
	struct cl_hw_asserts_info *assert_info = &cl_hw->assert_info;
	u8 idx = assert_info->index % CL_MIN_ASSERT_CNT;
	/* Get the oldest assert timestamp. */
	u8 prev_idx = (assert_info->index + 1) % CL_MIN_ASSERT_CNT;
	bool is_hw_restarted = false;

	if (assert_info->restart_sched) {
		is_hw_restarted = true;
	} else {
		/* Take time stamp of the assert */
		assert_info->timestamp[idx] = jiffies;
		assert_info->index++;
		/* In case hw assert time diff is less than CL_HW_ASSERT_TIME_MAX, restart hw. */
		if (assert_info->index > CL_MIN_ASSERT_CNT) {
			unsigned long time_diff_jiffies =
				assert_info->timestamp[idx] - assert_info->timestamp[prev_idx];
			unsigned int time_diff_msecs = jiffies_to_msecs(time_diff_jiffies);

			if (time_diff_msecs < cl_hw->conf->ce_hw_assert_time_max) {
				assert_info->index = 0;

				cl_dbg_err(cl_hw, "Assert storm detect (time_diff = %u)\n",
					   time_diff_msecs);
				cl_recovery_start(cl_hw, RECOVERY_ASSERT_STORM_DETECT);

				is_hw_restarted = true;
			}
		}
	}

	return is_hw_restarted;
}

void cl_hw_assert_info_init(struct cl_hw *cl_hw)
{
	memset(&cl_hw->assert_info, 0, sizeof(cl_hw->assert_info));
}

void cl_hw_assert_print(struct cl_hw *cl_hw, struct cl_ipc_e2a_msg *msg)
{
	struct dbg_print_ind *ind = (struct dbg_print_ind *)msg->param;
	const char *assert_string;
	u16 file_id = le16_to_cpu(ind->file_id);
	u16 line = le16_to_cpu(ind->line);
	u16 has_param = le16_to_cpu(ind->has_param);
	u32 param = le32_to_cpu(ind->param);
	int ret = 0;

	/* If ce_hw_assert_time_max is 0, HW assert storm detection is disabled */
	if (cl_hw->conf->ce_hw_assert_time_max)
		if (cl_hw_assert_storm_detect(cl_hw))
			return;

	/* Print ASSERT message with file_id, line, [parameter] */
	if (has_param)
		cl_dbg_err(cl_hw, "ASSERT_TCV%u @ FILE=%u LINE=%u param=0x%08X\n",
			   cl_hw->idx, file_id, line, param);
	else
		cl_dbg_err(cl_hw, "ASSERT_TCV%u @ file=%u line=%u\n",
			   cl_hw->idx, file_id, line);

	assert_string = cl_dbgfile_get_msg_txt(&cl_hw->dbg_data, file_id, line);

	if (!assert_string)
		assert_string = "ASSERT STRING NOT FOUND";

	cl_dbg_err(cl_hw, "%.500s\n", assert_string);

	/* Reset ASSERT pattern (in order to prevent assert prints loop) */
	ret = chip_ops_write32(cl_hw->chip,
			       SHARED_RAM_START_ADDR +
			       offsetof(struct cl_ipc_shared_env,
					assert_pattern), 0);
	if (ret) {
		cl_dbg_err(cl_hw, "chip_ops_write32 failed ret=%d\n", ret);

		return;
	}

	if (ind->err_no_dump) {
		unsigned long flags;

		spin_lock_irqsave(&cl_hw->debugfs.umh_lock, flags);

		if (cl_hw->debugfs.helper_scheduled) {
			cl_hw->assert_info.restart_needed = true;
		} else {
			cl_dbg_trace(cl_hw, "Starting recovery due to assert no dump\n");
			cl_recovery_start(cl_hw, RECOVERY_UNRECOVERABLE_ASSERT_NO_DUMP);
		}

		spin_unlock_irqrestore(&cl_hw->debugfs.umh_lock, flags);
	} else {
		cl_hw->assert_info.restart_needed = false;
	}
}

void cl_hw_assert_check(struct cl_hw *cl_hw)
{
	int ret;
	u32 assert_pattern;
	const char *assert_string;
	u16 line;
	u16 file_id;
	u32 param;
	struct cl_chip *chip = cl_hw->chip;
	struct assert {
		__le32 pattern;
		__le16 file_id;
		__le16 line_num;
		__le32 param;
	} *assert;

	assert = kzalloc(sizeof(*assert), GFP_ATOMIC);
	if (!assert)
		return;

	ret = chip_ops_read_bulk(chip,
				 SHARED_RAM_START_ADDR +
				 offsetof(struct cl_ipc_shared_env,
					  assert_pattern),
				 sizeof(struct assert),
				 (u8 *)assert);

	if (ret) {
		cl_dbg_err(cl_hw, "failed to read assert\n");

		goto out;
	}

	if (IS_USB_BUS_TYPE(chip)) {
		assert_pattern = le32_to_cpu(assert->pattern);
		line = le16_to_cpu(assert->line_num);
		file_id = le16_to_cpu(assert->file_id);
		param = le32_to_cpu(assert->param);
	} else {
		assert_pattern = (__force u32)assert->pattern;
		line = (__force u16)assert->line_num;
		file_id = (__force u16)assert->file_id;
		param = (__force u32)assert->param;
	}

	if (assert_pattern != ASSERT_PATTERN)
		goto out;

	assert_string = cl_dbgfile_get_msg_txt(&cl_hw->dbg_data, file_id, line);

	/* Print 1st ASSERT message with file_id, line, [parameter] */
	cl_dbg_err(cl_hw, "ASSERT_lmac @ FILE=%u LINE=%u param=0x%08X\n",
		   file_id, line, param);

	if (!assert_string)
		assert_string = "ASSERT STRING NOT FOUND";

	cl_dbg_err(cl_hw, "%.500s\n", assert_string);

	/* Reset ASSERT pattern in order to prevent assert prints loop */
	ret = chip_ops_write32(cl_hw->chip, SHARED_RAM_START_ADDR +
			       offsetof(struct cl_ipc_shared_env,
					assert_pattern), 0);
	if (ret)
		cl_dbg_err(cl_hw, "failed to write assert_pattern\n");

 out:
	kfree(assert);
}


/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_RECOVERY_H
#define CL_RECOVERY_H

#include "cl_hw.h"

enum recovery_reason {
	RECOVERY_WAIT4CFM,
	RECOVERY_UNRECOVERABLE_ASSERT,
	RECOVERY_UNRECOVERABLE_ASSERT_NO_DUMP,
	RECOVERY_ASSERT_STORM_DETECT,
	RECOVERY_DRV_FAILED,
};

enum cl_fw_wd_mode {
	FW_WD_DISABLE,
	FW_WD_INTERNAL_RECOVERY,
	FW_WD_DRV_RELOAD,
};

bool cl_recovery_in_progress(struct cl_hw *cl_hw);
void cl_recovery_reconfig_complete(struct cl_hw *cl_hw);
void cl_recovery_start(struct cl_hw *cl_hw, int reason);

#endif /* CL_RECOVERY_H */

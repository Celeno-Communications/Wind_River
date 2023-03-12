/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_DEBUGFS_H
#define CL_DEBUGFS_H

#include "cl_debugfs_defs.h"
#include "cl_hw.h"

#ifdef CONFIG_CL_DEBUGFS

int cl_dbgfs_register(struct cl_hw *cl_hw, const char *name);
void cl_dbgfs_unregister(struct cl_hw *cl_hw);

#else

static inline int cl_dbgfs_register(struct cl_hw *cl_hw, const char *name)
{
	return 0;
}

static inline void cl_dbgfs_unregister(struct cl_hw *cl_hw)
{
}

#endif /* CONFIG_CL_DEBUGFS */

#endif /* CL_DEBUGFS_H */

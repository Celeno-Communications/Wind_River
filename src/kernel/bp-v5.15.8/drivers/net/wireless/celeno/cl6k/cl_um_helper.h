/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_UM_HELPER_H
#define CL_UM_HELPER_H

#include "cl_hw.h"

#ifdef CONFIG_CL_DEBUGFS

int cl_um_helper_trigger(struct cl_hw *cl_hw);

void cl_um_helper_init(struct cl_hw *cl_hw, struct dentry *dir_drv);

void cl_um_helper_close(struct cl_hw *cl_hw);

ssize_t cl_um_helper_read(struct cl_hw *cl_hw,
			  char __user *user_buf,
			  size_t count,
			  loff_t *ppos);

ssize_t cl_um_helper_write(struct cl_hw *cl_hw,
			   const char __user *user_buf,
			   size_t count,
			   loff_t *ppos);

#else

static inline int cl_um_helper_trigger(struct cl_hw *cl_hw)
{
	return 0;
}

static inline void cl_um_helper_init(struct cl_hw *cl_hw, struct dentry *dir_drv)
{}

static inline void cl_um_helper_close(struct cl_hw *cl_hw)
{}

static inline ssize_t cl_um_helper_read(struct cl_hw *cl_hw,
					char __user *user_buf,
					size_t count,
					loff_t *ppos)
{
	return 0;
}

static inline ssize_t cl_um_helper_write(struct cl_hw *cl_hw,
					 const char __user *user_buf,
					 size_t count,
					 loff_t *ppos)
{
	return 0;
}

#endif /* CONFIG_CL_DEBUGFS */

#endif /* CL_UM_HELPER_H */

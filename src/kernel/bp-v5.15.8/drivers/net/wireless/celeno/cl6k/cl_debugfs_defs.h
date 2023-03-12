/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_DEBUGFS_DEFS_H
#define CL_DEBUGFS_DEFS_H

#ifdef CONFIG_CL_DEBUGFS

#include <linux/workqueue.h>
#include <linux/interrupt.h>

/* Min HW assert before testing asserts time-stamp */
#define CL_MIN_ASSERT_CNT 10

/* Define max time between hw asserts in msec */
#define CL_HW_ASSERT_TIME_MAX 5000

struct cl_debugfs {
	unsigned long long rateidx;
	struct dentry *dir;
	bool trace_prst;
	char helper_cmd[128];
	struct work_struct helper_work;
	bool helper_scheduled;
	spinlock_t umh_lock;
	bool unregistering;
};

#else

struct cl_debugfs {
};

#endif /* CONFIG_CL_DEBUGFS */

#endif /* CL_DEBUGFS_DEFS_H */

/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_TIMER_H
#define CL_TIMER_H

#include <linux/timer.h>

struct cl_timer {
	struct timer_list obj;
	void (*f)(unsigned long data);
	unsigned long data;
	atomic_t period;
	bool periodic;
	bool enable;
};

void cl_timer_init(struct cl_timer *timer,
		   void (*f)(unsigned long data),
		   unsigned long data,
		   unsigned long period,
		   bool periodic);
void cl_timer_period_set(struct cl_timer *timer, unsigned long period);
void cl_timer_enable(struct cl_timer *timer);
void cl_timer_disable(struct cl_timer *timer);
void cl_timer_disable_sync(struct cl_timer *timer);
void cl_timer_rearm(struct cl_timer *timer);
int cl_timer_rearm_offset(struct cl_timer *timer, unsigned long time_offset);

#endif /* CL_TIMER_H */

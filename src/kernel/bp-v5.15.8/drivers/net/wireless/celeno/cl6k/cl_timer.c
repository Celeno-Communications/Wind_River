// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_timer.h"

static void cl_timer_func(struct timer_list *t)
{
	struct cl_timer *timer = from_timer(timer, t, obj);

	timer->f(timer->data);
	if (timer->enable && timer->periodic)
		cl_timer_enable(timer);
}

void cl_timer_init(struct cl_timer *timer,
		   void (*f)(unsigned long),
		   unsigned long data,
		   unsigned long period,
		   bool periodic)
{
	timer_setup(&timer->obj, cl_timer_func, 0);
	cl_timer_period_set(timer, period);
	timer->data = data;
	timer->f = f;
	timer->periodic = periodic;
	timer->enable = false;
}

void cl_timer_period_set(struct cl_timer *timer, unsigned long period)
{
	atomic_set(&timer->period, msecs_to_jiffies(period));
}

void cl_timer_enable(struct cl_timer *timer)
{
	if (timer_pending(&timer->obj))
		return;

	timer->obj.expires = jiffies + atomic_read(&timer->period);
	timer->enable = true;
	add_timer(&timer->obj);
}

void cl_timer_disable(struct cl_timer *timer)
{
	if (timer->enable) {
		timer->enable = false;
		del_timer(&timer->obj);
	}
}

void cl_timer_disable_sync(struct cl_timer *timer)
{
	if (timer->enable) {
		timer->enable = false;
		del_timer_sync(&timer->obj);
	}
}

void cl_timer_rearm(struct cl_timer *timer)
{
	timer->enable = true;

	mod_timer(&timer->obj, jiffies + atomic_read(&timer->period));
}

int cl_timer_rearm_offset(struct cl_timer *timer, unsigned long time_offset)
{
	timer->enable = true;

	return mod_timer(&timer->obj, time_offset + atomic_read(&timer->period));
}

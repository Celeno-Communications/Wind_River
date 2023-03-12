/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_MATH_H
#define CL_MATH_H

#include <linux/types.h>
#include <linux/math64.h>

#define IS_POWER2(x) ((x) && !((x) & ((x) - 1)))

static inline void cl_div64_decimal(u64 dividend, u64 divisor, u32 *a, u32 *b)
{
	u64 remainder = 0;

	*a = (u32)div64_u64_rem(dividend, divisor, &remainder);
	*b = (u32)div64_u64(100 * remainder, divisor);
}

#endif /* CL_MATH_H */

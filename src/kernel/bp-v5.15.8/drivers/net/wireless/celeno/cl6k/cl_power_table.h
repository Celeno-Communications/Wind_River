/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_POWER_TABLE_H
#define CL_POWER_TABLE_H

#include <linux/types.h>

#define NUM_POWER_WORDS 256

struct cl_power_table_data {
	u8 conv_table[NUM_POWER_WORDS];
};

struct cl_power_table_info {
	struct cl_power_table_data *data;
	u32 dma_addr;
};

struct cl_hw;

int cl_power_table_alloc(struct cl_hw *cl_hw);
void cl_power_table_free(struct cl_hw *cl_hw);

#endif /* CL_POWER_TABLE_H */

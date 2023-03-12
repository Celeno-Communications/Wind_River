/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_BSR_H
#define CL_BSR_H

#include <linux/types.h>
#include "def.h"

struct cl_hw;
struct cl_sw_txhdr;
struct cli_params;

struct cl_bsr_data {
	u32 bsr_byte_cnt[TID_MAX];
};

struct cl_bsr_info {
	struct cl_bsr_data *data;
	dma_addr_t dma_addr;
};

int cl_bsr_alloc(struct cl_hw *cl_hw);
void cl_bsr_free(struct cl_hw *cl_hw);
int cl_bsr_cli(struct cl_hw *cl_hw, struct cli_params *cli_params);
void cl_bsr_counters_dec(struct cl_hw *cl_hw, struct cl_sw_txhdr *sw_txhdr);
void cl_bsr_counters_inc(struct cl_hw *cl_hw, struct cl_sw_txhdr *sw_txhdr, u16 bytes);
void cl_bsr_counters_reset(struct cl_hw *cl_hw);

#endif /* CL_BSR_H */

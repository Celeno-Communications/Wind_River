/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_FW_FILE_H
#define CL_FW_FILE_H

#include "chip.h"
#include "cl_hw.h"

#define FW_START_MAGIC           "CEFWHDRSTART"
#define FW_END_MAGIC             "CEFWHDREND"
#define FW_OFFLOAD_MEM_BASE_ADDR 0x70000000 /* Defined in fw link script */
#define FW_SECTION_SIZE_MASK     0x7FFFF    /* Mask for max. size of a section */
#define FW_REMOTE_ROM_BASE_ADDR  0x80000000 /* Defined in fw link script */
#define FW_REMOTE_ROM_MAX        150000

/* Location (offset) where FW codes must be taken from */
#define IRAM_SECTION_SIZE_MASK  0x000FFFFF /* Mask for max. size of IRAM */
#define IRAM_RUN_BASE_ADDR      0x40080000 /* Defined in fw link script */
#define LMAC_DST_IRAM_OFFSET    0x40000

struct cl_fw_file_params {
	u32 dram_addr;
	int dram_size;
	u32 iram_addr;
	int iram_size;
};

int cl_fw_file_load(struct cl_hw *cl_hw);
void cl_fw_file_cleanup(struct cl_hw *cl_hw);
void cl_fw_file_release_cached_fw(struct cl_cached_fw *cached_fw);
void cl_fw_file_release(struct cl_hw *cl_hw);
#endif /* CL_FW_FILE_H */

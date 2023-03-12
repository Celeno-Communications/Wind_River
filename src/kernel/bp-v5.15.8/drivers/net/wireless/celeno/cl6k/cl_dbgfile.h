/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_DBGFILE_H
#define CL_DBGFILE_H

#include "cl_hw.h"

#define DBG_FILE_MAX_ASSERT_LEN 256
#define DBG_FILE_MAX_PRINT_LEN  350

void cl_dbgfile_parse(struct cl_hw *cl_hw, void *edata, u32 esize);
void cl_dbgfile_release_mem(struct cl_dbg_data *dbg_data,
			    struct cl_str_offload_env *str_offload_env);
void cl_dbgfile_print_fw_str(struct cl_hw *cl_hw, u8 *str, int max_size);
int cl_dbgfile_store_offload_data(struct cl_chip *chip, struct cl_hw *cl_hw,
				  void *data1, u32 size1, u32 base1,
				  void *data2, u32 size2, u32 base2,
				  void *data3, u32 size3, u32 base3);
const char *cl_dbgfile_get_msg_txt(struct cl_dbg_data *dbg_data, u16 file_id, u16 line);

#endif /* CL_DBGFILE_H */

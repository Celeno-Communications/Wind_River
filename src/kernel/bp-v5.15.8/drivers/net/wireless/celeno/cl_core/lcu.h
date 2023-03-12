/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef LCU_H
#define LCU_H

#include "chip.h"

#define CL_LCU_MODE_DFLT_ALIAS "default"
#define CL_LCU_MODE_DFLT_SYMB_LINK "lcu_default.conf"
#define CL_LCU_MODE_DFLT_OFF "OFF"
#define CL_LCU_MEM_WRITE_TOKENS_CNT 3 /* cmd addr val */
#define CL_LCU_MEM_RMW_TOKENS_CNT 5 /* cmd addr mask lsb val */
#define CL_LCU_MEM_WRITE_CMD_STR "mem_write"
#define CL_LCU_MEM_RMW_CMD_STR "mem_rmw"
#define CL_LCU_MEM_WRITE_CMD_SZ sizeof(CL_LCU_MEM_WRITE_CMD_STR)
#define CL_LCU_MEM_RMW_CMD_SZ sizeof(CL_LCU_MEM_RMW_CMD_STR)
#define CL_LCU_UNKNOWN_CMD_STR "unknown"

enum cl_lcu_cmd_type {
	CL_LCU_CMD_TYPE_UNKNOWN,
	CL_LCU_CMD_TYPE_MEM_WRITE,
	CL_LCU_CMD_TYPE_MEM_RMW
};

struct cl_lcu_cmd {
	u32 type;
	u32 offset;
	u32 value;
	u32 mask;
	u32 lsb;
	struct list_head cmd_list;
};

bool cl_lcu_ela_is_on(struct cl_chip *chip);
void cl_lcu_stop(struct cl_chip *chip);
void cl_lcu_apply_config(struct cl_chip *chip);
int cl_lcu_init(struct cl_chip *chip);
void cl_lcu_deinit(struct cl_chip *chip);

#endif /* LCU_H */

/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_FW_DBG_H
#define CL_FW_DBG_H

#include "cl_hw.h"

enum {
	DBG_INFO_DUMP = 1,
	DBG_INFO_TX_STATS,
	DBG_INFO_BCN_STATS,
	DBG_INFO_RX_STATS,
	DBG_INFO_DYN_CAL_STATS,
	DBG_INFO_RATE_FALLBACK_STATS,
	DBG_INFO_BF,
	DBG_INFO_TRIGGER_FLOW,
	DBG_INFO_PTA_STATS,
	DBG_INFO_MAX,
	DBG_INFO_UNSET = DBG_INFO_MAX
};

enum cl_dbg_txl_frame_type {
	CL_DBG_FRAME_TYPE_INVALID = 0,
	CL_DBG_FRAME_TYPE_SINGLE,
	CL_DBG_FRAME_TYPE_BEACON,
	CL_DBG_FRAME_TYPE_BACKUP_BEACON,
	CL_DBG_FRAME_TYPE_AGG,
	CL_DBG_FRAME_TYPE_AGG_NEXT_IN_TXOP,
	CL_DBG_FRAME_TYPE_AGG_MU,
	CL_DBG_FRAME_TYPE_TF_AGG,
	CL_DBG_FRAME_TYPE_TB_QOS_NULL,
	CL_DBG_FRAME_TYPE_TB_SINGLE,
	CL_DBG_FRAME_TYPE_TB_AGG,
	CL_DBG_FRAME_TYPE_PS_DATA_NULL,
	CL_DBG_FRAME_TYPE_PS_QOS_NULL,
	CL_DBG_FRAME_TYPE_RTS,
	CL_DBG_FRAME_TYPE_CTS,
	CL_DBG_FRAME_TYPE_CFEND,
	CL_DBG_FRAME_TYPE_TF_BASIC,
	CL_DBG_FRAME_TYPE_TF_BSRP,
	CL_DBG_FRAME_TYPE_TF_BFRP,
	CL_DBG_FRAME_TYPE_TF_MU_BAR,
	CL_DBG_FRAME_TYPE_BFR_POLL,
	CL_DBG_FRAME_TYPE_BF_NDPA,
	CL_DBG_FRAME_TYPE_BF_NDP,
	CL_DBG_FRAME_TYPE_SENSING_NDP,
	CL_DBG_FRAME_TYPE_MAX,
};

void cl_fw_dbg_handler(struct cl_hw *cl_hw);
int cl_fw_dbg_cli(struct cl_hw *cl_hw, struct cli_params *cli_params);
void cl_fw_dbg_dump_file(struct cl_hw *cl_hw);
void cl_fw_dbg_trigger_based_init(struct cl_hw *cl_hw);
void cl_fw_dbg_trigger_based_update(struct cl_hw *cl_hw,
				    struct hw_rxhdr *rxhdr, __le16 fc);
void cl_fw_dbg_trigger_based_reset(struct cl_hw *cl_hw);

#endif /* CL_FW_DBG_H */

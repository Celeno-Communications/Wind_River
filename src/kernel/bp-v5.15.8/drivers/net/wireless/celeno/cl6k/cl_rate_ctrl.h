/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_RATE_CTRL_H
#define CL_RATE_CTRL_H

#include <linux/types.h>
#include "cl_ipc_shared.h"

#define RATE_CTRL_OFFSET_OFDM          4
#define RATE_CNTRL_HE_SPATIAL_CONF_DEF 0xF

/* Op_mode field in mm_update_rate_dl_req structure */
enum cl_op_mode {
	RATE_OP_MODE_FIXED,
	RATE_OP_MODE_DEFAULT_HE,
	RATE_OP_MODE_DEFAULT_OFDM,
	RATE_OP_MODE_DEFAULT_CCK,
	RATE_OP_MODE_STA_SU,
	RATE_OP_MODE_STA_MU,
	RATE_OP_MODE_MCAST,
	RATE_OP_MODE_BCAST
};

/* Value to be set in tx_host_info */
enum cl_rate_ctrl_entry {
	RATE_CTRL_ENTRY_NA = 0,

	RATE_CTRL_ENTRY_STA,
	RATE_CTRL_ENTRY_FIXED_RATE,
	RATE_CTRL_ENTRY_MIN_HE,
	RATE_CTRL_ENTRY_MIN_OFDM,
	RATE_CTRL_ENTRY_MIN_CCK,
	RATE_CTRL_ENTRY_MCAST,
	RATE_CTRL_ENTRY_BCAST,

	/* Entry size in firmware is represented by 3 bits */
	RATE_CTRL_ENTRY_MAX = 8
};

/*
 * sw_ctrl includes eights bits (16 - 23) to be used by software.
 * Bit 16 is used by driver to indicate tx_bf.
 * Bit 17 is used by driver to indicate fallback.
 * Bit 18 - 23 are still free.
 */
struct cl_rate_ctrl_info_fields {
	u32 mcs_index        : 7;   /* [6:0] */
	u32 bw               : 2;   /* [8:7] */
	u32 gi               : 2;   /* [10:9] */
	u32 pre_type_or_stbc : 1;   /* [11] */
	u32 format_mod       : 4;   /* [15:12] */
	u32 tx_bf            : 1;   /* [16] */
	u32 fallback         : 1;   /* [17] */
	u32 sw_ctrl          : 6;   /* [23:18] */
	u32 tx_chains        : 8;   /* [31:24] */
};

union cl_rate_ctrl_info {
	struct cl_rate_ctrl_info_fields field;
	u32 word;
};

struct cl_rate_ctrl_info_he_fields {
	u32 spatial_conf    : 4;   /* [3:0] */
	u32 starting_sts    : 3;   /* [6:4] */
	u32 ru_index        : 6;   /* [12:7] */
	u32 ru_type         : 3;   /* [15:13] */
	u32 ru_band         : 1;   /* [16] */
	u32 mu_usr_pos      : 2;   /* [18:17] */
	u32 dcm_data        : 1;   /* [19] */
	u32 num_usrs_mu_dl  : 4;   /* [23:20] */
	u32 ru_alloc        : 8;   /* [31:24] */
};

union cl_rate_ctrl_info_he {
	struct cl_rate_ctrl_info_he_fields field;
	u32 word;
};

struct cl_hw;
struct cl_sta;
struct cl_sw_txhdr;

u32 cl_rate_ctrl_generate(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
			  u8 mode, u8 bw, u8 nss, u8 mcs, u8 gi,
			  bool fallback_en);
void cl_rate_ctrl_convert(union cl_rate_ctrl_info *rate_ctrl_info);
void cl_rate_ctrl_parse(union cl_rate_ctrl_info *rate_ctrl_info, u8 *nss, u8 *mcs);

void cl_rate_ctrl_set_default(struct cl_hw *cl_hw);

void cl_rate_ctrl_set_default_per_he_minrate(struct cl_hw *cl_hw, u8 bw,
					     u8 nss, u8 mcs, u8 gi);
bool cl_rate_ctrl_set_mcast(struct cl_hw *cl_hw, u8 mode, u8 mcs);
bool cl_rate_ctrl_set_fixed(struct cl_hw *cl_hw, u32 rate_ctrl_he, u8 mode, u8 mcs, u8 nss,
			    u8 bw, u8 gi, u8 gid, u8 ltf_field);
bool cl_rate_ctrl_set_dbgfs(struct cl_hw *cl_hw, u8 sta_idx, u32 rate_ctrl, u32 rate_ctrl_he,
			    u8 op_mode, u8 bw, u8 gid, u8 ltf_field);
void cl_rate_ctrl_set_ate_agg(struct cl_hw *cl_hw, struct cl_sta *cl_sta);

void cl_rate_ctrl_update_desc_single(struct cl_hw *cl_hw, struct tx_host_info *info,
				     struct cl_sw_txhdr *sw_txhdr);
void cl_rate_ctrl_update_desc_agg(struct cl_hw *cl_hw, struct tx_host_info *info);

#endif /* CL_RATE_CTRL_H */

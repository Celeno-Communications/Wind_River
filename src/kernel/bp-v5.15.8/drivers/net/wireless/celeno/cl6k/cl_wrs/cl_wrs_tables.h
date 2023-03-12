/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_WRS_TABLES_H
#define CL_WRS_TABLES_H

#include <linux/types.h>

/* Rate Table Size */
#define WRS_HE_RATE_TABLE_SIZE     (WRS_MCS_MAX_HE * WRS_SS_MAX * CHNL_BW_MAX * WRS_GI_MAX_HE)
#define WRS_HT_VHT_RATE_TABLE_SIZE (WRS_MCS_MAX_VHT * WRS_SS_MAX * CHNL_BW_MAX * WRS_GI_MAX_VHT)

/* Initial Thresholds */
#define WRS_INIT_MSEC_WEIGHT_DOWN  (WRS_MAINTENANCE_PERIOD_MS * 3) /* Msec */
#define WRS_INIT_MSEC_WEIGHT_UP    (WRS_MAINTENANCE_PERIOD_MS * 3) /* Msec */

#define WRS_MSEC_WEIGHT_MIN        (WRS_MAINTENANCE_PERIOD_MS * 2) /* Msec */
#define WRS_MSEC_WEIGHT_MAX_UP     30000 /* Msec */
#define WRS_MSEC_WEIGHT_MAX_DOWN   4000  /* Msec */
#define WRS_MSEC_STEP_DOWN         5000  /* Msec */
#define WRS_MSEC_STEP_UP_SAME      1000  /* Msec */
#define WRS_INVALID_RATE           ((u16)(~0))

enum cl_wrs_table_node_up {
	WRS_TABLE_NODE_UP_MCS,
	WRS_TABLE_NODE_UP_BW,
	WRS_TABLE_NODE_UP_NSS,
	WRS_TABLE_NODE_UP_BF,
	WRS_TABLE_NODE_UP_GI,

	WRS_TABLE_NODE_UP_MAX
};

struct cl_wrs_table_validity {
	bool is_valid;
	u16 new_rate_idx;
};

struct cl_wrs_table_node {
	u16 rate_idx;
	u16 time_th;
	bool quick_up_check;
};

struct cl_wrs_rate {
	u16 mcs : 4,
	    nss : 3,
	    bw  : 2,
	    gi  : 2,
	    rsv : 2;
};

struct cl_wrs_table {
	struct cl_wrs_rate rate;
	struct cl_wrs_table_node rate_down;
	struct cl_wrs_table_node rate_up[WRS_TABLE_NODE_UP_MAX];
	u32 frames_total;
	u32 ba_not_rcv_total;
	u64 epr_acc;
};

struct cl_hw;
struct cl_wrs_db;
struct cl_wrs_sta;
struct cl_wrs_params;

void cl_wrs_tables_global_build(void);
void cl_wrs_tables_print(struct cl_hw *cl_hw, struct cl_wrs_params *wrs_params);
void cl_wrs_tables_reset(struct cl_wrs_db *wrs_db, struct cl_wrs_sta *wrs_sta,
			 struct cl_wrs_params *wrs_params);
void cl_wrs_tables_build(struct cl_hw *cl_hw, struct cl_wrs_sta *wrs_sta,
			 struct cl_wrs_params *wrs_params);
u16 cl_wrs_tables_find_rate_idx(struct cl_wrs_params *wrs_params,
				u8 bw, u8 nss, u8 mcs, u8 gi);

#endif /* CL_WRS_TABLES_H */

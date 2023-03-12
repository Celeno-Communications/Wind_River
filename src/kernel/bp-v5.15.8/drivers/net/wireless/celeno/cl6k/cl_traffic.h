/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_TRAFFIC_H
#define CL_TRAFFIC_H

#include "cl_vendor_cmd.h"

enum cl_traffic_direction {
	TRAFFIC_DIRECTION_TX,
	TRAFFIC_DIRECTION_RX,

	TRAFFIC_DIRECTION_MAX
};

enum cl_traffic_level {
	TRAFFIC_LEVEL_DRV,
	TRAFFIC_LEVEL_BF,
	TRAFFIC_LEVEL_EDCA,

	TRAFFIC_LEVEL_MAX
};

struct cl_traffic_activity {
	u8 cntr_active;
	u8 cntr_idle;
	bool is_active;
};

struct cl_traffic_sta {
	struct cl_traffic_activity activity_db[TRAFFIC_LEVEL_MAX];
	u32 num_bytes;
};

struct cl_traffic_main {
	u32 num_active_sta[TRAFFIC_LEVEL_MAX];
	u32 num_active_sta_dir[TRAFFIC_DIRECTION_MAX][TRAFFIC_LEVEL_MAX];
	u32 active_bytes_thr[TRAFFIC_LEVEL_MAX];
	bool dynamic_cts;
};

struct cl_hw;
struct cl_sta;

void cl_traffic_init(struct cl_hw *cl_hw);
void cl_traffic_tx_handler(struct cl_hw *cl_hw, struct cl_sta *cl_sta, u32 num_bytes);
void cl_traffic_rx_handler(struct cl_hw *cl_hw, struct cl_sta *cl_sta, u32 num_bytes);
void cl_traffic_maintenance(struct cl_hw *cl_hw);
void cl_traffic_sta_remove(struct cl_hw *cl_hw, struct cl_sta *cl_sta);
bool cl_traffic_is_sta_active(struct cl_hw *cl_hw, struct cl_sta *cl_sta);
bool cl_traffic_is_sta_active_tx(struct cl_hw *cl_hw, struct cl_sta *cl_sta);
u32 cl_traffic_num_active_sta(struct cl_hw *cl_hw);
int cl_traffic_cli(struct cl_hw *cl_hw, struct cli_params *cli_params);

#endif /* CL_TRAFFIC_H */

/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_RX_SENS_H
#define CL_RX_SENS_H

#include "cl_vendor_cmd.h"

enum {
	RX_SENS_VAL_NEAR,
	RX_SENS_VAL_MID,
	RX_SENS_VAL_FAR,
	RX_SENS_VAL_VERY_FAR,

	RX_SENS_VAL_MAX
};

enum {
	RX_SENS_THR_1,
	RX_SENS_THR_2,
	RX_SENS_THR_3,

	RX_SENS_THR_MAX
};

#define CL_RX_SENS_PRINT(...) \
	do { \
		if (unlikely(cl_hw->rx_sens_db.debug)) \
			pr_debug(__VA_ARGS__); \
	} while (0)

struct cl_rx_sens_db {
	/* Configuration */
	bool debug;
	u32 period;
	s8 rssi_hyst;

	/* Run time parameters */
	u32 maintenance;
	s8 rx_sens_curr[MAX_ANTENNAS];
};

/* Station information */
struct cl_rx_sens_info {
	bool first_decision;
	s8 value;
	s32 rssi_samples;
	s32 rssi_sum[MAX_ANTENNAS];
};

struct cl_hw;
struct cl_sta;

void cl_rx_sens_init(struct cl_hw *cl_hw);
void cl_rx_sens_maintenance(struct cl_hw *cl_hw);
void cl_rx_sens_sta_active(struct cl_hw *cl_hw, struct cl_sta *cl_sta);
void cl_rx_sens_sta_not_active(struct cl_hw *cl_hw, struct cl_sta *cl_sta);
void cl_rx_sens_handle_rssi(struct cl_hw *cl_hw, struct cl_sta *cl_sta, s8 rssi[MAX_ANTENNAS]);
int cl_rx_sens_cli(struct cl_hw *cl_hw, struct cli_params *cli_params);

#endif /* CL_RX_SENS_H */

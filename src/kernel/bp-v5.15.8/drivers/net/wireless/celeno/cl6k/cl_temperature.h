/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_TEMPERATURE_H
#define CL_TEMPERATURE_H

#include <net/mac80211.h>
#include "cl_hw.h"
#include "cl_vendor_cmd.h"

#define CL_TEMP_PROTECT_INTERVAL_MS       40000
#define CL_TEMP_PROTECT_RADIO_OFF_HYST    10

#define CL_TEMP_COMP_ITERATIONS           4

#define CL_TEMPERATURE_TIMER_INTERVAL_MS  4000
#define CL_TEMPERATURE_UPDATE_INTERVAL_MS (CL_TEMPERATURE_TIMER_INTERVAL_MS - 100)

enum cl_temp_mode {
	TEMP_MODE_INTERNAL,
	TEMP_MODE_EXTERNAL
};

void cl_temperature_init(struct cl_hw *cl_hw);
void cl_temperature_close(struct cl_hw *cl_hw);
s16 cl_temperature_get_internal(struct cl_hw *cl_hw);
s8 cl_temperature_read(struct cl_hw *cl_hw, enum cl_temp_mode mode);
int cl_temperature_cli(struct cl_hw *cl_hw, struct cli_params *cli_params);
void cl_temperature_recovery(struct cl_hw *cl_hw);
bool cl_temperature_protect_did_reduce_duty_cycle(struct cl_hw *cl_hw);
s16 cl_temperature_calib_calc(struct cl_hw *cl_hw, u16 raw_bits);
void cl_temperature_comp_update_calib(struct cl_hw *cl_hw);

#endif /* CL_TEMPERATURE_H */

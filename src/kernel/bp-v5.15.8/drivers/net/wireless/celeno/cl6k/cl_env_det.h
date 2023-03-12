/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_ENV_DET_H
#define CL_ENV_DET_H

#include "cl_vendor_cmd.h"

#define MAX_CCA_CLEAN_DEF   20000
#define MAX_CCA_AVERAGE_DEF 300000
#define MAX_CCA_NOISY_DEF   850000
#define MIN_CCA_CLEAN_DEF   20000
#define MIN_CCA_AVERAGE_DEF 100000
#define MIN_CCA_NOISY_DEF   400000

#define CL_ENV_DET_ARRAY_SIZE          5
#define CL_ENV_DET_MAX_TIME_VERY_NOISY 180

#define CL_ENV_TYPE_2_STR(type) \
	(((type) == CL_ENV_TYPE_CLEAN) ? "Clean" : \
	(((type) == CL_ENV_TYPE_AVERAGE) ? "Average" : \
	(((type) == CL_ENV_TYPE_NOISY) ? "Noisy" : \
	(((type) == CL_ENV_TYPE_VERY_NOISY) ? "VeryNoisy" : "?"))))

#define CL_ENV_DBG_2_STR(dbg) \
	(((dbg) == CL_ENV_DBG_OFF) ? "Off" : \
	(((dbg) == CL_ENV_DBG_LOW) ? "Low" : \
	(((dbg) == CL_ENV_DBG_HIGH) ? "High" : "?")))

enum cl_env_type {
	CL_ENV_TYPE_CLEAN,
	CL_ENV_TYPE_AVERAGE,
	CL_ENV_TYPE_NOISY,
	CL_ENV_TYPE_VERY_NOISY,

	CL_ENV_TYPE_MAX
};

enum cl_env_dbg {
	CL_ENV_DBG_OFF,
	CL_ENV_DBG_LOW,
	CL_ENV_DBG_HIGH,

	CL_ENV_DBG_MAX
};

enum cl_env_flag {
	CL_ENV_FLAG_RXAMSDU  = BIT(0),
	CL_ENV_FLAG_TXAMSDU  = BIT(1),
	CL_ENV_FLAG_AGCRAMP  = BIT(2),
	CL_ENV_FLAG_PROTMODE = BIT(3),
	CL_ENV_FLAG_CCA      = BIT(4),
};

struct cl_env_det {
	/* Debug */
	u8 debug;
	/* Max CCA thresholds */
	u32 max_cca_clean;
	u32 max_cca_average;
	u32 max_cca_noisy;
	/* Min CCA thresholds */
	u32 min_cca_clean;
	u32 min_cca_average;
	u32 min_cca_noisy;
	/* Max time in very-noisy */
	u32 max_time_very_noisy;
	/* Run time parameters */
	bool enable;
	enum cl_env_type type;
	enum cl_env_type prev_type;
	enum cl_env_type array_type[CL_ENV_DET_ARRAY_SIZE];
	u8 array_idx;
	u8 array_cntr[CL_ENV_DET_ARRAY_SIZE];
	u32 edca_cca_busy_old;
	/* Histogram statistics */
	u32 histogram_cntr[CL_ENV_TYPE_MAX];
	u32 histogram_time[CL_ENV_TYPE_MAX];
	/* Parameters used to calculate CCA delta */
	u32 edca_cca_busy_prev[CL_ENV_DET_ARRAY_SIZE];
	u32 edca_cca_busy_avg_prev_type;
	u32 maintenance_cntr;
	/* Dynamic thresholds according to configured thresholds and delta */
	u32 max_cca_delta;
	u32 max_cca_clean_dynamic;
	u32 max_cca_average_dynamic;
	u32 max_cca_noisy_dynamic;
	/* Default parameters */
	u32 agc_ramp_default;
};

struct cl_hw;

void cl_env_det_init(struct cl_hw *cl_hw);
void cl_env_det_enable(struct cl_hw *cl_hw);
void cl_env_det_disable(struct cl_hw *cl_hw);
void cl_env_det_maintenance(struct cl_hw *cl_hw);
bool cl_env_det_is_clean(struct cl_hw *cl_hw);
bool cl_env_det_is_noisy_or_very_noisy(struct cl_hw *cl_hw);
int cl_env_det_cli(struct cl_hw *cl_hw, struct cli_params *cli_params);

#endif /* CL_ENV_DET_H */

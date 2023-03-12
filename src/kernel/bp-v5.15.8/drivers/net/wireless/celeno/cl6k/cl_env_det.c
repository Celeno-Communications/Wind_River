// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_env_det.h"
#include "reg_access.h"
#include "cl_prot_mode.h"
#include "cl_radio.h"
#include "cl_maintenance.h"
#include "cl_traffic.h"
#include "cl_math.h"
#include "cl_tx_amsdu.h"
#include "cl_rx_amsdu.h"
#include "reg_riu.h"
#include "reg_mac_hw.h"
#include "cl_utils.h"
#include "cl_msg_tx.h"

/*
 * Flag                     | Clean      | Average    | Noisy      | VeryNoisy
 * ----------------------------------------------------------------------------
 * 0x0001 =   1 : RX-AMSDU  | Enable     | Disable    | Disable    | Disable
 * 0x0002 =   2 : TX-AMSDU  | Enable     | Enable     | Disable    | Disable
 * 0x0004 =   4 : AGC-RAMP  | 0x05200710 | 0x05200710 | 0x05200720 | 0x05200720
 * 0x0008 =   8 : PROT-MODE | None       | RTS        | RTS        | RTS
 * 0x0010 =  16 : CCA       | Enable     | Enable     | Enable     | Disable
 */

static u32 cl_env_det_read_edca_cca_busy(struct cl_hw *cl_hw)
{
	/*
	 * This feature is enabled only when no stations are sending traffic.
	 * Therefore we read only EDCA_CCA_BUSY and not TX_MINE_TIME.
	 */
	struct cl_env_det *env_det = &cl_hw->env_det;
	u32 edca_cca_busy_new = mac_hw_edca_cca_busy_get(cl_hw->chip);
	u32 edca_cca_busy_diff = edca_cca_busy_new - env_det->edca_cca_busy_old;

	env_det->edca_cca_busy_old = edca_cca_busy_new;

	return edca_cca_busy_diff;
}

static u32 cl_env_det_calc_avg_cca(struct cl_hw *cl_hw)
{
	u8 i = 0;
	u32 edca_cca_busy_total = 0;
	struct cl_env_det *env_det = &cl_hw->env_det;

	for (i = 0; i < CL_ENV_DET_ARRAY_SIZE; i++)
		edca_cca_busy_total += env_det->edca_cca_busy_prev[i];

	return edca_cca_busy_total / CL_ENV_DET_ARRAY_SIZE;
}

static void cl_env_det_dynamic_cca_thr_reset(struct cl_hw *cl_hw)
{
	struct cl_env_det *env_det = &cl_hw->env_det;

	/* Return to default thresholds */
	env_det->max_cca_delta = 0;

	env_det->max_cca_clean_dynamic = env_det->max_cca_clean;
	env_det->max_cca_average_dynamic = env_det->max_cca_average;
	env_det->max_cca_noisy_dynamic = env_det->max_cca_noisy;
}

static void cl_env_det_dynamic_cca_thr_calc(struct cl_hw *cl_hw, u32 delta)
{
	struct cl_env_det *env_det = &cl_hw->env_det;

	/* Calculate new dynamic thresholds */
	env_det->max_cca_delta = delta;

	if (env_det->max_cca_clean > delta)
		env_det->max_cca_clean_dynamic = max(env_det->max_cca_clean - delta,
						     env_det->min_cca_clean);
	else
		env_det->max_cca_clean_dynamic = env_det->min_cca_clean;

	if (env_det->max_cca_average > delta)
		env_det->max_cca_average_dynamic = max(env_det->max_cca_average - delta,
						       env_det->min_cca_average);
	else
		env_det->max_cca_average_dynamic = env_det->min_cca_average;

	if (env_det->max_cca_noisy > delta)
		env_det->max_cca_noisy_dynamic = max(env_det->max_cca_noisy - delta,
						     env_det->min_cca_noisy);
	else
		env_det->max_cca_noisy_dynamic = env_det->min_cca_noisy;
}

static void cl_env_det_clean(struct cl_hw *cl_hw, u16 flags)
{
	/* In clean environment enable Rx amsdu */
	if (flags & CL_ENV_FLAG_RXAMSDU)
		cl_rx_amsdu_hw_en(cl_hw->hw, true);

	/* In clean environment enable Tx amsdu */
	if (flags & CL_ENV_FLAG_TXAMSDU)
		cl_hw->txamsdu_en = cl_hw->conf->ce_txamsdu_en;

	/* In clean environment set 4dB AGC-RAMP */
	if (flags & CL_ENV_FLAG_AGCRAMP)
		riu_rwnxagcramp_rampupgapqdb_setf(cl_hw->chip, 0x10);

	/* In clean environment disable RTS */
	if (flags & CL_ENV_FLAG_PROTMODE)
		cl_prot_mode_disable(cl_hw);

	/* In clean environment enable CCA */
	if (flags & CL_ENV_FLAG_CCA)
		cl_msg_tx_config_cca(cl_hw, cl_hw->conf->ci_cca_src);
}

static void cl_env_det_average(struct cl_hw *cl_hw, u16 flags)
{
	/* In average environment disable Rx amsdu */
	if (flags & CL_ENV_FLAG_RXAMSDU)
		cl_rx_amsdu_hw_en(cl_hw->hw, false);

	/* In average environment enable Tx amsdu */
	if (flags & CL_ENV_FLAG_TXAMSDU)
		cl_hw->txamsdu_en = cl_hw->conf->ce_txamsdu_en;

	/* In average environment set 4dB AGC-RAMP */
	if (flags & CL_ENV_FLAG_AGCRAMP)
		riu_rwnxagcramp_rampupgapqdb_setf(cl_hw->chip, 0x10);

	/* In average environment enable RTS or CTS */
	if (flags & CL_ENV_FLAG_PROTMODE)
		cl_prot_mode_enable(cl_hw);

	/* In average environment enable CCA */
	if (flags & CL_ENV_FLAG_CCA)
		cl_msg_tx_config_cca(cl_hw, cl_hw->conf->ci_cca_src);
}

static void cl_env_det_noisy(struct cl_hw *cl_hw, u16 flags)
{
	/* In noisy environment disable Rx amsdu */
	if (flags & CL_ENV_FLAG_RXAMSDU)
		cl_rx_amsdu_hw_en(cl_hw->hw, false);

	/* In noisy environment disable Tx amsdu */
	if (flags & CL_ENV_FLAG_TXAMSDU)
		cl_hw->txamsdu_en = 0;

	/* In noisy environment set 8dB AGC-RAMP */
	if (flags & CL_ENV_FLAG_AGCRAMP)
		riu_rwnxagcramp_rampupgapqdb_setf(cl_hw->chip, 0x20);

	/* In noisy environment enable RTS or CTS */
	if (flags & CL_ENV_FLAG_PROTMODE)
		cl_prot_mode_enable(cl_hw);

	/* In noisy environment enable CCA */
	if (flags & CL_ENV_FLAG_CCA)
		cl_msg_tx_config_cca(cl_hw, cl_hw->conf->ci_cca_src);
}

static void cl_env_det_very_noisy(struct cl_hw *cl_hw, u16 flags)
{
	/* In very-noisy environment disable Rx amsdu */
	if (flags & CL_ENV_FLAG_RXAMSDU)
		cl_rx_amsdu_hw_en(cl_hw->hw, false);

	/* In noisy environment disable Tx amsdu */
	if (flags & CL_ENV_FLAG_TXAMSDU)
		cl_hw->txamsdu_en = 0;

	/* In very-noisy environment set 8dB AGC-RAMP */
	if (flags & CL_ENV_FLAG_AGCRAMP)
		riu_rwnxagcramp_rampupgapqdb_setf(cl_hw->chip, 0x20);

	/* In very-noisy environment enable RTS or CTS */
	if (flags & CL_ENV_FLAG_PROTMODE)
		cl_prot_mode_enable(cl_hw);

	/* In very-noisy environment disable CCA */
	if (flags & CL_ENV_FLAG_CCA)
		cl_msg_tx_config_cca(cl_hw, 0);
}

static void cl_env_det_default(struct cl_hw *cl_hw, u16 flags)
{
	/* Return to default values */
	if (flags & CL_ENV_FLAG_RXAMSDU)
		cl_rx_amsdu_hw_en(cl_hw->hw, cl_hw->conf->ce_rxamsdu_en);

	if (flags & CL_ENV_FLAG_TXAMSDU)
		cl_hw->txamsdu_en = cl_hw->conf->ce_txamsdu_en;

	if (flags & CL_ENV_FLAG_AGCRAMP)
		riu_rwnxagcramp_rampupgapqdb_setf(cl_hw->chip, cl_hw->env_det.agc_ramp_default);

	if (flags & CL_ENV_FLAG_PROTMODE)
		cl_prot_mode_restore_default(cl_hw);

	if (flags & CL_ENV_FLAG_CCA)
		cl_msg_tx_config_cca(cl_hw, cl_hw->conf->ci_cca_src);
}

static void cl_env_det_switch_type(struct cl_hw *cl_hw)
{
	switch (cl_hw->env_det.type) {
	case CL_ENV_TYPE_CLEAN:
		cl_env_det_clean(cl_hw, cl_hw->conf->ci_env_det_flags);
		break;
	case CL_ENV_TYPE_AVERAGE:
		cl_env_det_average(cl_hw, cl_hw->conf->ci_env_det_flags);
		break;
	case CL_ENV_TYPE_NOISY:
		cl_env_det_noisy(cl_hw, cl_hw->conf->ci_env_det_flags);
		break;
	case CL_ENV_TYPE_VERY_NOISY:
		cl_env_det_very_noisy(cl_hw, cl_hw->conf->ci_env_det_flags);
		break;
	default:
		break;
	}
}

static void cl_env_det_set_new_type(struct cl_hw *cl_hw,
				    enum cl_env_type type_new,
				    u32 edca_cca_busy_avg)
{
	struct cl_env_det *env_det = &cl_hw->env_det;

	/* Set new type, update histogram, set CCA average and reset counters */
	env_det->prev_type = env_det->type;
	env_det->type = type_new;
	env_det->histogram_cntr[type_new]++;
	env_det->edca_cca_busy_avg_prev_type = edca_cca_busy_avg;
	env_det->maintenance_cntr = 0;

	/* Return to default thresholds */
	cl_env_det_dynamic_cca_thr_reset(cl_hw);

	cl_env_det_switch_type(cl_hw);

	/* Print new state */
	if (env_det->debug == CL_ENV_DBG_LOW)
		pr_debug("ENV_DET: New state - %s\n", CL_ENV_TYPE_2_STR(type_new));
}

static void cl_env_det_insert_array(struct cl_hw *cl_hw, enum cl_env_type type_new)
{
	struct cl_env_det *env_det = &cl_hw->env_det;
	enum cl_env_type type_old = env_det->array_type[env_det->array_idx];

	if (type_old == type_new)
		goto inc_arr_idx;

	/* Decrease array counter according to old type */
	if (type_old < CL_ENV_TYPE_MAX)
		env_det->array_cntr[type_old]--;

	/* Increase array counter according to new type */
	if (type_new < CL_ENV_TYPE_MAX)
		env_det->array_cntr[type_new]++;

	/* Insert new type to array */
	env_det->array_type[env_det->array_idx] = type_new;

inc_arr_idx:
	/* Increase array index */
	if ((CL_ENV_DET_ARRAY_SIZE - 1) == env_det->array_idx)
		env_det->array_idx = 0;
	else
		env_det->array_idx++;
}

static enum cl_env_type cl_env_det_find_type_min(struct cl_hw *cl_hw)
{
	u8 i = 0;
	enum cl_env_type type_min = CL_ENV_TYPE_MAX;
	struct cl_env_det *env_det = &cl_hw->env_det;

	for (i = 0; i < CL_ENV_DET_ARRAY_SIZE; i++)
		if (env_det->array_type[i] < type_min)
			type_min = env_det->array_type[i];

	return type_min;
}

static enum cl_env_type cl_env_det_find_type_max(struct cl_hw *cl_hw)
{
	u8 i = 0;
	enum cl_env_type type_max = CL_ENV_TYPE_CLEAN;
	struct cl_env_det *env_det = &cl_hw->env_det;

	for (i = 0; i < CL_ENV_DET_ARRAY_SIZE; i++)
		if (env_det->array_type[i] > type_max)
			type_max = env_det->array_type[i];

	return type_max;
}

static enum cl_env_type cl_env_det_find_new_type(struct cl_hw *cl_hw)
{
	u8 i = 0;
	struct cl_env_det *env_det = &cl_hw->env_det;

	/* Type can't change if array consists the current type */
	for (i = 0; i < CL_ENV_DET_ARRAY_SIZE; i++)
		if (env_det->type == env_det->array_type[i])
			return env_det->type;

	if (env_det->array_cntr[CL_ENV_TYPE_CLEAN] == CL_ENV_DET_ARRAY_SIZE)
		return CL_ENV_TYPE_CLEAN;
	else if (env_det->array_cntr[CL_ENV_TYPE_AVERAGE] == CL_ENV_DET_ARRAY_SIZE)
		return CL_ENV_TYPE_AVERAGE;
	else if (env_det->array_cntr[CL_ENV_TYPE_NOISY] == CL_ENV_DET_ARRAY_SIZE)
		return CL_ENV_TYPE_NOISY;
	else if (env_det->array_cntr[CL_ENV_TYPE_VERY_NOISY] == CL_ENV_DET_ARRAY_SIZE)
		return CL_ENV_TYPE_VERY_NOISY;

	/*
	 * This logic is a bit compilcated. I will explain it with some examples.
	 * Example #1:
	 *   Current type: CLEAN
	 *   Array: AVERAGE, NOISY, AVERAGE, AVERAGE, NOISY
	 *   New type: AVERAGE (min value in array).
	 * Example #2:
	 *   Current type: VERY_NOISY
	 *   Array: AVERAGE, NOISY, AVERAGE, AVERAGE, NOISY
	 *   New type: NOISY (max value in array).
	 * If current type is AVERAGE then find_type_min() will always return NOISY
	 * If current type is NOISY then find_type_max() will always return AVERAGE
	 */
	switch (env_det->type) {
	case CL_ENV_TYPE_CLEAN:
		return cl_env_det_find_type_min(cl_hw);
	case CL_ENV_TYPE_AVERAGE:
		return CL_ENV_TYPE_NOISY;
	case CL_ENV_TYPE_NOISY:
		return CL_ENV_TYPE_AVERAGE;
	case CL_ENV_TYPE_VERY_NOISY:
		return cl_env_det_find_type_max(cl_hw);
	default:
		return CL_ENV_TYPE_MAX;
	}
}

static void cl_env_update_flags(struct cl_hw *cl_hw)
{
	cl_env_det_default(cl_hw, cl_hw->conf->ci_env_det_flags);

	if (cl_hw->conf->ci_env_det_flags == 0) {
		cl_env_det_disable(cl_hw);
	} else {
		cl_env_det_switch_type(cl_hw);

		if (!cl_hw->env_det.enable && (cl_traffic_num_active_sta(cl_hw) == 0))
			cl_env_det_enable(cl_hw);
	}
}

static void cl_env_det_cli_change_type(struct cl_hw *cl_hw, u32 type)
{
	/* Manually change type */
	if (type < CL_ENV_TYPE_MAX) {
		u8 i = 0;

		for (i = 0; i < CL_ENV_DET_ARRAY_SIZE; i++)
			cl_env_det_insert_array(cl_hw, type);

		pr_debug("ENV_DET: Change type = %s\n", CL_ENV_TYPE_2_STR(type));
		cl_env_det_set_new_type(cl_hw, type, 0xFFFFFFFF);
	} else {
		pr_err("ENV_DET: Invalid type [%u]\n", type);
	}
}

static int cl_env_det_cli_configuration(struct cl_hw *cl_hw)
{
	struct cl_env_det *env_det = &cl_hw->env_det;
	u16 env_det_flags = cl_hw->conf->ci_env_det_flags;
	bool rx_amsdu = (env_det_flags & CL_ENV_FLAG_RXAMSDU) ? true : false;
	bool tx_amsdu = (env_det_flags & CL_ENV_FLAG_TXAMSDU) ? true : false;
	bool agc_ramp = (env_det_flags & CL_ENV_FLAG_AGCRAMP) ? true : false;
	bool prot_mode = (env_det_flags & CL_ENV_FLAG_PROTMODE) ? true : false;
	bool cca = (env_det_flags & CL_ENV_FLAG_CCA) ? true : false;
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;

	cl_snprintf(&buf, &len, &buf_size,
		    "ENV_DET STATE\n"
		    "-------------\n");
	cl_snprintf(&buf, &len, &buf_size,
		    "Previos State = %s\n",
		    CL_ENV_TYPE_2_STR(env_det->prev_type));
	cl_snprintf(&buf, &len, &buf_size,
		    "Current State = %s\n",
		    CL_ENV_TYPE_2_STR(env_det->type));

	cl_snprintf(&buf, &len, &buf_size,
		    "ENV_DET CONIGURATION\n"
		    "--------------------\n");
	cl_snprintf(&buf, &len, &buf_size,
		    "Debug                     = %s\n",
		    CL_ENV_DBG_2_STR(env_det->debug));
	cl_snprintf(&buf, &len, &buf_size,
		    "Enable                    = %s\n",
		    env_det->enable ? "True" : "False");
	cl_snprintf(&buf, &len, &buf_size,
		    "Max time very noisy [sec] = %u\n",
		    env_det->max_time_very_noisy);
	cl_snprintf(&buf, &len, &buf_size,
		    "Max CCA delta             = %u%%\n",
		    env_det->max_cca_delta / 10000);
	cl_snprintf(&buf, &len, &buf_size,
		    "Configured min thresholds:\n");
	cl_snprintf(&buf, &len, &buf_size,
		    "  Min CCA clean           = %u%%\n",
		    env_det->min_cca_clean / 10000);
	cl_snprintf(&buf, &len, &buf_size,
		    "  Min CCA average         = %u%%\n",
		    env_det->min_cca_average / 10000);
	cl_snprintf(&buf, &len, &buf_size,
		    "  Min CCA noisy           = %u%%\n",
		    env_det->min_cca_noisy / 10000);
	cl_snprintf(&buf, &len, &buf_size,
		    "Configured max thresholds:\n");
	cl_snprintf(&buf, &len, &buf_size,
		    "  Max CCA clean           = %u%%\n",
		    env_det->max_cca_clean / 10000);
	cl_snprintf(&buf, &len, &buf_size,
		    "  Max CCA average         = %u%%\n",
		    env_det->max_cca_average / 10000);
	cl_snprintf(&buf, &len, &buf_size,
		    "  Max CCA noisy           = %u%%\n",
		    env_det->max_cca_noisy / 10000);
	cl_snprintf(&buf, &len, &buf_size,
		    "Dynamic max thresholds:\n");
	cl_snprintf(&buf, &len, &buf_size,
		    "  Max CCA clean dynamic   = %u%%\n",
		    env_det->max_cca_clean_dynamic / 10000);
	cl_snprintf(&buf, &len, &buf_size,
		    "  Max CCA average dynamic = %u%%\n",
		    env_det->max_cca_average_dynamic / 10000);
	cl_snprintf(&buf, &len, &buf_size,
		    "  Max CCA noisy dynamic   = %u%%\n",
		    env_det->max_cca_noisy_dynamic / 10000);
	cl_snprintf(&buf, &len, &buf_size,
		    "Flag %-3u                 | Clean      | Average    |"
		    " Noisy      | VeryNoisy  | State |\n", env_det_flags);
	cl_snprintf(&buf, &len, &buf_size,
		    "----------------------------------------------------"
		    "---------------------------------|\n");
	cl_snprintf(&buf, &len, &buf_size,
		    "0x0001 =   1 : RX-AMSDU  | Enable     | Disable    | "
		    "Disable    | Disable    | %-3s   |\n", rx_amsdu ?
		    "ON" : "OFF");
	cl_snprintf(&buf, &len, &buf_size,
		    "0x0002 =   2 : TX-AMSDU  | Enable     | Enable     | "
		    "Disable    | Disable    | %-3s   |\n", tx_amsdu ?
		    "ON" : "OFF");
	cl_snprintf(&buf, &len, &buf_size,
		    "0x0004 =   4 : AGC-RAMP  | 0x05200710 | 0x05200710 | "
		    "0x05200720 | 0x05200720 | %-3s   |\n", agc_ramp ?
		    "ON" : "OFF");
	cl_snprintf(&buf, &len, &buf_size,
		    "0x0008 =   8 : PROT-MODE | None       | RTS        | "
		    "RTS        | RTS        | %-3s   |\n", prot_mode ?
		    "ON" : "OFF");
	cl_snprintf(&buf, &len, &buf_size,
		    "0x0010 =  16 : CCA       | Enable     | Enable     | "
		    "Enable     | Disable    | %-3s   |\n", cca ?
		    "ON" : "OFF");

	err = cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);

	return err;
}

static void cl_env_det_cli_debug(struct cl_hw *cl_hw, u8 debug)
{
	if (debug < CL_ENV_DBG_MAX) {
		cl_hw->env_det.debug = debug;
		pr_debug("ENV_DET: Debug = %s\n", CL_ENV_DBG_2_STR(debug));
	} else {
		pr_err("ENV_DET: Invalid debug [%u]\n", debug);
	}
}

static void cl_env_det_cli_flags(struct cl_hw *cl_hw, u16 flags)
{
	if (cl_hw->conf->ci_env_det_flags == flags) {
		pr_debug("ENV_DET: Flags value did not change [%u]\n", flags);
	} else {
		pr_debug("ENV_DET: Flags = %u\n", flags);
		cl_hw->conf->ci_env_det_flags = flags;
		cl_env_update_flags(cl_hw);
	}
}

static int cl_env_det_cli_hitogram(struct cl_hw *cl_hw)
{
	enum cl_env_type type = CL_ENV_TYPE_MAX;
	struct cl_env_det *env_det = &cl_hw->env_det;
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;

	cl_snprintf(&buf, &len, &buf_size,
		    "ENV_DET HISTOGRAM\n"
		    "=================\n");
	cl_snprintf(&buf, &len, &buf_size,
		    "Current = %s\n", CL_ENV_TYPE_2_STR(env_det->type));
	cl_snprintf(&buf, &len, &buf_size,
		    "---------------------------------------\n");
	cl_snprintf(&buf, &len, &buf_size,
		    "| Type      | Counter    | Time (sec) |\n");
	cl_snprintf(&buf, &len, &buf_size,
		    "|-----------+------------+------------|\n");

	for (type = 0; type < CL_ENV_TYPE_MAX; type++) {
		cl_snprintf(&buf, &len, &buf_size,
			    "| %-9s | %10u | %10u |\n",
			    CL_ENV_TYPE_2_STR(type),
			    env_det->histogram_cntr[type],
			    env_det->histogram_time[type]);
	}

	cl_snprintf(&buf, &len, &buf_size,
		    "---------------------------------------\n\n");

	err = cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);

	return err;
}

static void cl_env_det_cli_max_time(struct cl_hw *cl_hw, u32 max_time)
{
	cl_hw->env_det.max_time_very_noisy = max_time;
	pr_debug("ENV_DET: Max time very noisy = %u\n", max_time);
}

static void cl_env_det_cli_reset(struct cl_hw *cl_hw)
{
	struct cl_env_det *env_det = &cl_hw->env_det;

	pr_debug("ENV_DET: Reset histgoram\n");
	memset(env_det->histogram_cntr, 0, sizeof(u32) * CL_ENV_TYPE_MAX);
	memset(env_det->histogram_time, 0, sizeof(u32) * CL_ENV_TYPE_MAX);

	/* After reset set counter of currnet type to 1 */
	env_det->histogram_cntr[env_det->type] = 1;
}

static void cl_env_det_cli_thresholds(struct cl_hw *cl_hw,
				      u32 max_cca_clean, u32 max_cca_average, u32 max_cca_noisy,
				      u32 min_cca_clean, u32 min_cca_average, u32 min_cca_noisy)
{
	struct cl_env_det *env_det = &cl_hw->env_det;

	if (max_cca_clean <= 100 &&
	    max_cca_average <= 100 &&
	    max_cca_noisy <= 100 &&
	    min_cca_clean <= max_cca_clean &&
	    min_cca_average <= max_cca_average &&
	    min_cca_noisy <= max_cca_noisy &&
	    max_cca_clean <= max_cca_average &&
	    max_cca_average <= max_cca_noisy &&
	    min_cca_clean <= min_cca_average &&
	    min_cca_average <= min_cca_noisy) {
		env_det->max_cca_clean = max_cca_clean * 10000;
		env_det->max_cca_average = max_cca_average * 10000;
		env_det->max_cca_noisy = max_cca_noisy * 10000;
		env_det->min_cca_clean = min_cca_clean * 10000;
		env_det->min_cca_average = min_cca_average * 10000;
		env_det->min_cca_noisy = min_cca_noisy * 10000;

		cl_env_det_dynamic_cca_thr_reset(cl_hw);

		pr_debug("ENV_DET: Max CCA - Clean = %u%%, Average = %u%%, Noisy = %u%%\n",
			 max_cca_clean, max_cca_average, max_cca_noisy);
		pr_debug("ENV_DET: Min CCA - Clean = %u%%, Average = %u%%, Noisy = %u%%\n",
			 min_cca_clean, min_cca_average, min_cca_noisy);
	} else {
		pr_err("ENV_DET: Invalid thresholds [%u][%u][%u][%u][%u][%u]\n",
		       max_cca_clean, max_cca_average, max_cca_noisy,
		       min_cca_clean, min_cca_average, min_cca_noisy);
	}
}

static int cl_env_det_cli_help(struct cl_hw *cl_hw)
{
	char *buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!buf)
		return -ENOMEM;

	snprintf(buf, PAGE_SIZE,
		 "envdet usage:\n"
		 "-a : Change type [0-Clean/1-Average/2-Noisy/3-VeryNoisy]\n"
		 "-c : Print configuration and state\n"
		 "-d : Set debug [0=off/1=low/2=high]\n"
		 "-f : Set flags [0-255]\n"
		 "-h : Print histogram\n"
		 "-m : Max time in very noisy [sec]\n"
		 "-r : Reset histogram\n"
		 "-t : Set thresholds (0-100) [MaxClean].[MaxAverage]."
			"[MaxNoisy].[MinClean].[MinAverage].[MinNoisy]\n");

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

static void cl_env_det_very_noisy_escape(struct cl_hw *cl_hw, struct cl_env_det *env_det)
{
	/*
	 * We do not allow to be in very-noisy type for too much time
	 * If very-noisy time expired drop to noisy.
	 */
	if (env_det->type != CL_ENV_TYPE_VERY_NOISY)
		return;

	if (env_det->maintenance_cntr >= env_det->max_time_very_noisy) {
		u8 i = 0;

		for (i = 0; i < CL_ENV_DET_ARRAY_SIZE; i++)
			cl_env_det_insert_array(cl_hw, CL_ENV_TYPE_NOISY);

		/* Debug print */
		if (env_det->debug == CL_ENV_DBG_HIGH)
			pr_debug("ENV_DET: Reached max time in VeryNoisy, dropping to Noisy.\n");

		/*
		 * Set Noisy type (send max value for average cca
		 * so next delta that will be calculated is 0)
		 */
		cl_env_det_set_new_type(cl_hw, CL_ENV_TYPE_NOISY, 0xFFFFFFFF);
	}
}

static void cl_env_det_dynamic_threshold(struct cl_hw *cl_hw, struct cl_env_det *env_det)
{
	/* Calculate the delta and make sure it is not bigger from the threshold */
	u32 edca_cca_busy_avg_new_type = cl_env_det_calc_avg_cca(cl_hw);
	u32 delta;

	if (edca_cca_busy_avg_new_type >= env_det->edca_cca_busy_avg_prev_type)
		return;

	delta = env_det->edca_cca_busy_avg_prev_type - edca_cca_busy_avg_new_type;

	if (env_det->debug == CL_ENV_DBG_HIGH)
		pr_debug("ENV_DET: Average CCA - prev = %u, new = %u, Delta = %u\n",
			 env_det->edca_cca_busy_avg_prev_type, edca_cca_busy_avg_new_type, delta);

	cl_env_det_dynamic_cca_thr_calc(cl_hw, delta);
}

void cl_env_det_init(struct cl_hw *cl_hw)
{
	u8 i = 0;
	struct cl_env_det *env_det = &cl_hw->env_det;

	/* Init type */
	for (i = 0; i < CL_ENV_DET_ARRAY_SIZE; i++)
		env_det->array_type[i] = CL_ENV_TYPE_MAX;

	env_det->type = CL_ENV_TYPE_MAX;
	env_det->prev_type = CL_ENV_TYPE_MAX;

	/* Max/Min CCA thresholds */
	env_det->max_cca_clean = cl_hw->conf->ci_env_det_thr[0];
	env_det->max_cca_average = cl_hw->conf->ci_env_det_thr[1];
	env_det->max_cca_noisy = cl_hw->conf->ci_env_det_thr[2];
	env_det->min_cca_clean = cl_hw->conf->ci_env_det_thr[3];
	env_det->min_cca_average = cl_hw->conf->ci_env_det_thr[4];
	env_det->min_cca_noisy = cl_hw->conf->ci_env_det_thr[5];

	cl_env_det_dynamic_cca_thr_reset(cl_hw);

	/* Max time in very noisy type */
	env_det->max_time_very_noisy = CL_ENV_DET_MAX_TIME_VERY_NOISY;

	/* Read RIU_RWNXAGCRAMP_ADDR default value */
	env_det->agc_ramp_default = riu_rwnxagcramp_rampupgapqdb_getf(cl_hw->chip);

	cl_env_update_flags(cl_hw);
}

void cl_env_det_enable(struct cl_hw *cl_hw)
{
	if (cl_hw->conf->ci_env_det_flags) {
		struct cl_env_det *env_det = &cl_hw->env_det;

		/* Reset EDCA_CCA_BUSY value */
		cl_env_det_read_edca_cca_busy(cl_hw);

		env_det->enable = true;

		if (env_det->debug == CL_ENV_DBG_HIGH)
			pr_debug("ENV_DET: Enable\n");
	}
}

void cl_env_det_disable(struct cl_hw *cl_hw)
{
	struct cl_env_det *env_det = &cl_hw->env_det;

	if (env_det->enable) {
		env_det->enable = false;

		if (env_det->debug == CL_ENV_DBG_HIGH)
			pr_debug("ENV_DET: Disable\n");
	}
}

void cl_env_det_maintenance(struct cl_hw *cl_hw)
{
	struct cl_env_det *env_det = &cl_hw->env_det;
	u32 edca_cca_busy = 0;
	enum cl_env_type type_new = CL_ENV_TYPE_MAX;

	if (cl_radio_is_off(cl_hw) || !env_det->enable)
		return;

	/* Count how many time we were in each type */
	if (cl_hw->conf->ci_env_det_flags && env_det->type < CL_ENV_TYPE_MAX)
		env_det->histogram_time[env_det->type]++;

	edca_cca_busy = cl_env_det_read_edca_cca_busy(cl_hw);

	/* Store new CCA value and increase maintenance counter for current state */
	env_det->edca_cca_busy_prev[env_det->array_idx] = edca_cca_busy;
	env_det->maintenance_cntr++;

	/*
	 * When moving from clean/average to noisy CCA goes down because AGC-RAMP is increased.
	 * When moving to very-noisy CCA goes down because CCA is disabled.
	 * Therefore we must dynamically modify the CCA thresholds.
	 */
	if ((env_det->prev_type <= CL_ENV_TYPE_AVERAGE && env_det->type == CL_ENV_TYPE_NOISY) ||
	    env_det->type == CL_ENV_TYPE_VERY_NOISY) {
		/*
		 * In first (CL_ENV_DET_ARRAY_SIZE + 1) seconds after new type was selected
		 * do not insert into the array a different type.
		 * We need to calculate the CCA delta between previous type and new type.
		 * CCA delta is calculated after (CL_ENV_DET_ARRAY_SIZE + 1) and not after
		 * CL_ENV_DET_ARRAY_SIZE because first read after changing to new type is
		 * not stable.
		 */
		if (env_det->maintenance_cntr < (CL_ENV_DET_ARRAY_SIZE + 1)) {
			cl_env_det_insert_array(cl_hw, env_det->type);
			goto find_new_type;
		} else if ((CL_ENV_DET_ARRAY_SIZE + 1) == env_det->maintenance_cntr) {
			cl_env_det_dynamic_threshold(cl_hw, env_det);
		}
	}

	/* Compare CCA busy value to max CCA thresholds, and insert new value to cyclic array */
	if (edca_cca_busy < env_det->max_cca_clean_dynamic)
		cl_env_det_insert_array(cl_hw, CL_ENV_TYPE_CLEAN);
	else if (edca_cca_busy < env_det->max_cca_average_dynamic)
		cl_env_det_insert_array(cl_hw, CL_ENV_TYPE_AVERAGE);
	else if (edca_cca_busy < env_det->max_cca_noisy_dynamic)
		cl_env_det_insert_array(cl_hw, CL_ENV_TYPE_NOISY);
	else
		cl_env_det_insert_array(cl_hw, CL_ENV_TYPE_VERY_NOISY);

find_new_type:
	type_new = cl_env_det_find_new_type(cl_hw);

	/* Ptint CCA level */
	if (env_det->debug == CL_ENV_DBG_HIGH)
		pr_debug("ENV_DET: Edca CCA Busy = %u = %u%% (%s)\n",
			 edca_cca_busy,
			 edca_cca_busy / (CL_MAINTENANCE_PERIOD_SLOW_MS * 10),
			 CL_ENV_TYPE_2_STR(type_new));

	if (type_new != env_det->type) {
		/* Calculate average CCA value just before changing to new type */
		u32 avg = cl_env_det_calc_avg_cca(cl_hw);

		/* Set new type */
		cl_env_det_set_new_type(cl_hw, type_new, avg);
	} else {
		cl_env_det_very_noisy_escape(cl_hw, env_det);
	}
}

bool cl_env_det_is_clean(struct cl_hw *cl_hw)
{
	return (cl_hw->env_det.type == CL_ENV_TYPE_CLEAN) ? true : false;
}

bool cl_env_det_is_noisy_or_very_noisy(struct cl_hw *cl_hw)
{
	return (cl_hw->env_det.type >= CL_ENV_TYPE_NOISY) ? true : false;
}

int cl_env_det_cli(struct cl_hw *cl_hw, struct cli_params *cli_params)
{
	u32 expected_params = 0;
	bool type_change = false;
	bool configuration_print = false;
	bool debug_set = false;
	bool flags_set = false;
	bool histogram_print = false;
	bool max_time_set = false;
	bool histogram_reset = false;
	bool thresholds_set = false;

	switch (cli_params->option) {
	case 'a':
		type_change = true;
		expected_params = 1;
		break;
	case 'c':
		configuration_print = true;
		expected_params = 0;
		break;
	case 'd':
		debug_set = true;
		expected_params = 1;
		break;
	case 'f':
		flags_set = true;
		expected_params = 1;
		break;
	case 'h':
		histogram_print = true;
		expected_params = 0;
		break;
	case 'm':
		max_time_set = true;
		expected_params = 1;
		break;
	case 'r':
		histogram_reset = true;
		expected_params = 0;
		break;
	case 't':
		thresholds_set = true;
		expected_params = 6;
		break;
	case '?':
		return cl_env_det_cli_help(cl_hw);
	default:
		cl_dbg_err(cl_hw, "Illegal option (%c) - try '?' for help\n", cli_params->option);
		goto out_err;
	}

	if (expected_params != cli_params->num_params) {
		cl_dbg_err(cl_hw, "Wrong number of arguments (expected %u) (actual %u)\n",
			   expected_params, cli_params->num_params);
		goto out_err;
	}

	if (type_change)
		cl_env_det_cli_change_type(cl_hw, cli_params->params[0]);
	else if (configuration_print)
		return cl_env_det_cli_configuration(cl_hw);
	else if (debug_set)
		cl_env_det_cli_debug(cl_hw, cli_params->params[0]);
	else if (flags_set)
		cl_env_det_cli_flags(cl_hw, cli_params->params[0]);
	else if (histogram_print)
		return cl_env_det_cli_hitogram(cl_hw);
	else if (max_time_set)
		cl_env_det_cli_max_time(cl_hw, cli_params->params[0]);
	else if (histogram_reset)
		cl_env_det_cli_reset(cl_hw);
	else if (thresholds_set)
		cl_env_det_cli_thresholds(cl_hw,
					  cli_params->params[0], cli_params->params[1],
					  cli_params->params[2], cli_params->params[3],
					  cli_params->params[4], cli_params->params[5]);

out_err:
	return -EIO;
}

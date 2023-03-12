// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include <linux/kthread.h>
#include "cl_temperature.h"
#include "cl_radio.h"
#include "cl_math.h"
#include "cl_utils.h"
#include "cl_calibration.h"
#include "cl_channel.h"
#include "cl_power.h"
#include "cl_msg_tx.h"

#define TEMP_PROTECT_STATE_STR(delta) \
	((delta) == TEMP_PROTECT_OFF ? "DISABLE" : \
	((delta) == TEMP_PROTECT_INTERNAL ? "INTERNAL" : \
	((delta) == TEMP_PROTECT_EXTERNAL ? "EXTERNAL" : \
	((delta) == TEMP_PROTECT_DIFF ? "DIFF" : "UNKNOWN"))))

#define TEMP_FACTOR        100
#define TEMP_FACTOR_POWER2 (TEMP_FACTOR * TEMP_FACTOR)
#define TEMP_FACTOR_POWER3 (TEMP_FACTOR * TEMP_FACTOR * TEMP_FACTOR)

#define TEMP_DIFF_INVALID 0x7F

#define TEMPERATURE_MIN 0
#define TEMPERATURE_MAX 127

#define DUTY_CYCLE_MAX  100
#define DUTY_CYCLE_MIN  20
#define DUTY_CYCLE_STEP 20

static int cl_temperature_read_fw(struct cl_hw *cl_hw, enum cl_temp_mode desired_temp_mode,
				  u16 *raw_bits)
{
	u8 retval = 0;
	struct mm_anamon_read_cfm *cfm;

	if (cl_msg_tx_anamon_read(cl_hw, ANAMON_MODE_TEMPERATURE, desired_temp_mode, 0) != 0) {
		cl_dbg_err(cl_hw, "cl_msg_tx_anamon_read failed\n");
		cl_msg_tx_free_cfm_params(cl_hw, MM_ANAMON_READ_CFM);
		return -1;
	}

	cfm = (struct mm_anamon_read_cfm *)(cl_hw->msg_cfm_params[MM_ANAMON_READ_CFM]);

	if (!cfm)
		return -1;

	retval = cfm->retval;
	*raw_bits = ((le16_to_cpu(cfm->raw_bits_data_0) + le16_to_cpu(cfm->raw_bits_data_1)) / 2);
	cl_msg_tx_free_cfm_params(cl_hw, MM_ANAMON_READ_CFM);

	return retval ? 0 : -1;
}

static s16 cl_raw_bits_to_temperature(s16 x, enum cl_temp_mode desired_temp_mode)
{
	/* Calculation of external thermistor */
	if (desired_temp_mode == TEMP_MODE_EXTERNAL) {
		const s64 coeff[] = {
			-27,
			101 * TEMP_FACTOR,
			-172 * TEMP_FACTOR_POWER2,
			139 * TEMP_FACTOR_POWER3
		};
		s64 ext_temprature = 0;
		s16 adcv = ((x * 180) >> 12);
		/* Polynom calc: y = -27 * adcv ^ 3 + 101 * adcv ^ 2 -172 * adcv ^ 1 + 139 */
		ext_temprature = div_s64((coeff[0] * adcv * adcv * adcv) +
					 (coeff[1] * adcv * adcv) +
					 (coeff[2] * adcv) + coeff[3],
					 TEMP_FACTOR_POWER3);
		return (s16)ext_temprature;
	}

	if (desired_temp_mode == TEMP_MODE_INTERNAL)
		return (((cl_adc_to_mv(x) * 29) / 100) - 136);

	return 0;
}

static void cl_temperature_set_power_offset(struct cl_hw *cl_hw,
					    s8 power_offset)
{
	s8 total_pwr_offset[MAX_ANTENNAS] = {0};
	u8 chan_idx = cl_channel_to_index(cl_hw, cl_hw->channel);
	int i = 0;

	cl_hw->temp_comp_db.power_offset = power_offset;

	if (chan_idx == INVALID_CHAN_IDX)
		goto out;

	for (i = 0; i < cl_hw->num_antennas; i++)
		total_pwr_offset[i] = (cl_hw->tx_pow_info[chan_idx][i][0].offset +
				       POWER_OFFSET_RES * power_offset);

out:
	cl_msg_tx_set_ant_pwr_offset(cl_hw, total_pwr_offset);
}

static void cl_temperature_comp_tcv(struct cl_hw *cl_hw, s16 temp_internal)
{
	struct cl_temp_comp_db *temp_comp_db = &cl_hw->temp_comp_db;
	s8 new_power_offset = 0;

	/* Accumulate temperature delta */
	temp_comp_db->acc_temp_delta += (temp_internal - temp_comp_db->calib_temperature);

	/* Check if it is time to make a new decision */
	if ((cl_hw->temperature.comp_iterations % CL_TEMP_COMP_ITERATIONS) != 0)
		return;

	/* Average the temperature delta over the last CL_TEMP_COMP_ITERATIONS samples */
	temp_comp_db->avg_temp_delta = DIV_ROUND_CLOSEST(temp_comp_db->acc_temp_delta,
							 CL_TEMP_COMP_ITERATIONS);

	/* Reset accumulated temp delta */
	temp_comp_db->acc_temp_delta = 0;

	new_power_offset = (s8)DIV_ROUND_CLOSEST(temp_comp_db->avg_temp_delta *
						 cl_hw->conf->ce_temp_comp_slope, 100);

	if (temp_comp_db->power_offset == new_power_offset)
		return;

	cl_dbg_trace(cl_hw, "calib_temperature %d, avg_temp_delta %d, power_offset %d\n",
		     temp_comp_db->calib_temperature,
		     temp_comp_db->avg_temp_delta,
		     new_power_offset);

	cl_temperature_set_power_offset(cl_hw, new_power_offset);
}

static void cl_temperature_comp(struct cl_chip *chip, struct cl_hw *cl_hw)
{
	struct cl_temperature *temperature = &cl_hw->temperature;
	s16 temp_internal = 0;

	if (!chip->conf->ce_temp_comp_en)
		return;

	temp_internal = cl_temperature_read(cl_hw, TEMP_MODE_INTERNAL);
	temperature->comp_iterations++;

	cl_dbg_chip_trace(chip, "comp_iterations = %u, temp_internal = %d\n",
			  (temperature->comp_iterations % CL_TEMP_COMP_ITERATIONS), temp_internal);

	if (cl_chip_is_tcv0_enabled(chip))
		cl_temperature_comp_tcv(chip->cl_hw_tcv0, temp_internal);
}

static void cl_temperature_tx_duty_cycle(struct cl_chip *chip, u8 duty_cycle)
{
	u16 periodic_tx_time_on = chip->conf->ce_temp_protect_tx_period_ms * duty_cycle / 100;
	u16 periodic_tx_time_off = chip->conf->ce_temp_protect_tx_period_ms - periodic_tx_time_on;

	if (cl_chip_is_tcv0_enabled(chip))
		cl_msg_tx_start_periodic_tx_time(chip->cl_hw_tcv0,
						 periodic_tx_time_off, periodic_tx_time_on);
}

static void cl_temperature_protect_radio_off(struct cl_hw *cl_hw, s16 temp_avg)
{
	struct cl_temp_protect_db *temp_protect_db = &cl_hw->temperature.protect_db;
	struct cl_chip *chip = cl_hw->chip;
	struct cl_chip_conf *conf = chip->conf;

	if (temp_protect_db->force_radio_off)
		return;

	cl_radio_off_chip(chip);
	temp_protect_db->force_radio_off = true;
	cl_dbg_chip_verbose(chip, "temperature [%d] >= radio off threshold [%d] --> radio off!\n",
			    temp_avg, conf->ce_temp_protect_radio_off_th);
}

static void cl_temperature_protect_radio_on(struct cl_hw *cl_hw, s16 temp_avg)
{
	struct cl_temp_protect_db *temp_protect_db = &cl_hw->temperature.protect_db;
	struct cl_chip *chip = cl_hw->chip;
	struct cl_chip_conf *conf = chip->conf;
	s16 temp_thr = conf->ce_temp_protect_radio_off_th - CL_TEMP_PROTECT_RADIO_OFF_HYST;

	if (temp_avg >= temp_thr)
		return;

	cl_radio_on_chip(chip);
	temp_protect_db->force_radio_off = false;
	cl_dbg_chip_verbose(chip, "temperature [%d] < radio off threshold - hysteresis [%d] "
				  "--> radio on!\n",
			    temp_avg, temp_thr);
}

static void cl_temperature_protect_dec_duty_cycle(struct cl_hw *cl_hw, s16 temp_avg)
{
	struct cl_temp_protect_db *temp_protect_db = &cl_hw->temperature.protect_db;
	struct cl_chip *chip = cl_hw->chip;
	struct cl_chip_conf *conf = chip->conf;

	if (temp_protect_db->duty_cycle == DUTY_CYCLE_MIN)
		return;

	temp_protect_db->duty_cycle -= DUTY_CYCLE_STEP;
	cl_temperature_tx_duty_cycle(chip, temp_protect_db->duty_cycle);
	cl_dbg_chip_warn(chip,
			 "temperature [%d] > protect_th_max [%d] --> decrease duty cycle [%u]!\n",
			 temp_avg, conf->ce_temp_protect_th_max, temp_protect_db->duty_cycle);
}

static void cl_temperature_protect_inc_duty_cycle(struct cl_hw *cl_hw, s16 temp_avg)
{
	struct cl_temp_protect_db *temp_protect_db = &cl_hw->temperature.protect_db;
	struct cl_chip *chip = cl_hw->chip;
	struct cl_chip_conf *conf = chip->conf;

	if (temp_protect_db->duty_cycle == DUTY_CYCLE_MAX)
		return;

	temp_protect_db->duty_cycle += DUTY_CYCLE_STEP;
	cl_temperature_tx_duty_cycle(chip, temp_protect_db->duty_cycle);
	cl_dbg_chip_warn(chip,
			 "temperature [%d] < protect_th_min [%d] --> increase duty cycle [%u]!\n",
			 temp_avg, conf->ce_temp_protect_th_min, temp_protect_db->duty_cycle);
}

static void cl_temperature_protect_decision(struct cl_hw *cl_hw, s16 temp_avg)
{
	struct cl_temp_protect_db *temp_protect_db = &cl_hw->temperature.protect_db;
	struct cl_chip *chip = cl_hw->chip;
	struct cl_chip_conf *conf = chip->conf;

	/* Test mode - force test_mode_duty_cycle */
	if (unlikely(temp_protect_db->test_mode_duty_cycle != DUTY_CYCLE_MAX)) {
		cl_temperature_tx_duty_cycle(chip, temp_protect_db->test_mode_duty_cycle);
		return;
	}

	/* Temperature protection logic:
	 *
	 * If the temperature is greater or equal to the radio off threshold
	 * then set the radio off.
	 * If the temperature is below the (radio off threshold - hysteresis [10])
	 * then set the radio on again.
	 *
	 * Any time the temperature is greater than the max threshold then we
	 * decrease the duty cycle.
	 * Any time the temperature is below the min threshold then we increase
	 * the duty cycle.
	 */
	if (temp_avg >= conf->ce_temp_protect_radio_off_th) {
		cl_temperature_protect_radio_off(cl_hw, temp_avg);
		return;
	}

	if (temp_protect_db->force_radio_off) {
		cl_temperature_protect_radio_on(cl_hw, temp_avg);
		return;
	}

	if (temp_avg > conf->ce_temp_protect_th_max) {
		cl_temperature_protect_dec_duty_cycle(cl_hw, temp_avg);
		return;
	}

	if (temp_avg < chip->conf->ce_temp_protect_th_min) {
		cl_temperature_protect_inc_duty_cycle(cl_hw, temp_avg);
		return;
	}
}

static s16 cl_temperature_avg_protect(struct cl_temp_protect_db *temp_protect_db)
{
	/* Calculate average of last_samples */
	u8 i;
	s32 temp_avg = 0;

	for (i = 0; i < CL_TEMP_PROTECT_NUM_SAMPLES; i++)
		temp_avg += temp_protect_db->last_samples[i];

	return (s16)(temp_avg / CL_TEMP_PROTECT_NUM_SAMPLES);
}

static void cl_temperature_protect_handle_read(struct cl_hw *cl_hw, s16 temp)
{
	struct cl_temp_protect_db *temp_protect_db = &cl_hw->temperature.protect_db;
	unsigned long curr_time = jiffies_to_msecs(jiffies);
	unsigned long delta_time = CL_TIME_DIFF(curr_time, temp_protect_db->last_timestamp);

	/* Add current read */
	temp_protect_db->last_samples[temp_protect_db->curr_idx] = temp;
	temp_protect_db->curr_idx = (temp_protect_db->curr_idx + 1) % CL_TEMP_PROTECT_NUM_SAMPLES;

	if (delta_time >= CL_TEMP_PROTECT_INTERVAL_MS) {
		s16 temp_avg = cl_temperature_avg_protect(temp_protect_db);

		cl_dbg_trace(cl_hw, "temp_avg = %d, delta_time = %lu\n", temp_avg, delta_time);
		cl_temperature_protect_decision(cl_hw, temp_avg);
		temp_protect_db->last_timestamp = curr_time;
	}
}

static void cl_temperature_protect(struct cl_chip *chip, struct cl_hw *cl_hw)
{
	s16 protect_temp = 0;
	struct cl_chip_conf *conf = chip->conf;

	switch (conf->ce_temp_protect_en) {
	case TEMP_PROTECT_OFF:
		return;
	case TEMP_PROTECT_INTERNAL:
		protect_temp = cl_temperature_read(cl_hw, TEMP_MODE_INTERNAL) +
			conf->ce_temp_protect_delta;
		break;
	case TEMP_PROTECT_EXTERNAL:
		protect_temp = cl_temperature_read(cl_hw, TEMP_MODE_EXTERNAL) +
			conf->ce_temp_protect_delta;
		break;
	case TEMP_PROTECT_DIFF:
		protect_temp = cl_temperature_read(cl_hw, TEMP_MODE_INTERNAL) -
			cl_hw->temperature.diff_internal_external + conf->ce_temp_protect_delta;
		break;
	}

	cl_temperature_protect_handle_read(cl_hw, protect_temp);
}

static int cl_temperature_cli_help(struct cl_hw *cl_hw)
{
	char *buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!buf)
		return -ENOMEM;

	snprintf(buf, PAGE_SIZE,
		 "temp usage:\n"
		 "Temperature compensation:\n"
		 "-a : Print the temperature compensation configuration\n"
		 "-b : Set temperature compensation on/off [0:Dis,1:En]\n"
		 "-c : Set temperature compensation slope "
			"[3 digit number without a point] "
			"example: '109'=>1.09, '76'=>0.76\n"
		 "Temperature protect:\n"
		 "-k : Print temperature protection configuration\n"
		 "-l : Print temperature protect current status\n"
		 "-m : Set test mode [0 - 100, 100 = disable]\n"
		 "Temperature general:\n"
		 "-v : Read temperature [0:internal, 1:external, "
			"2:internal+delta, 3=external+delta, "
			"4=internal-diff+delta]\n");

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

static int cl_temperature_protect_print_config(struct cl_hw *cl_hw)
{
	struct cl_chip_conf *conf = cl_hw->chip->conf;
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;

	cl_snprintf(&buf, &len, &buf_size,
		    "Temperature protect configuration:\n");
	cl_snprintf(&buf, &len, &buf_size,
		    "ce_temp_protect_en           : %s\n",
		    TEMP_PROTECT_STATE_STR(conf->ce_temp_protect_en));
	cl_snprintf(&buf, &len, &buf_size,
		    "ce_temp_protect_delta        : %3d [Celsius]\n",
		    conf->ce_temp_protect_delta);
	cl_snprintf(&buf, &len, &buf_size,
		    "ce_temp_protect_th_max       : %3d [Celsius]\n",
		    conf->ce_temp_protect_th_max);
	cl_snprintf(&buf, &len, &buf_size,
		    "ce_temp_protect_th_min       : %3d [Celsius]\n",
		    conf->ce_temp_protect_th_min);
	cl_snprintf(&buf, &len, &buf_size,
		    "ce_temp_protect_radio_off_th : %3d [Celsius]\n",
		    conf->ce_temp_protect_radio_off_th);
	cl_snprintf(&buf, &len, &buf_size,
		    "ce_temp_protect_tx_period_ms : %5u [ms]\n",
		    conf->ce_temp_protect_tx_period_ms);

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

static int cl_temperature_protect_print_status(struct cl_hw *cl_hw)
{
	struct cl_temp_protect_db *protect_db =	&cl_hw->temperature.protect_db;
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;

	cl_snprintf(&buf, &len, &buf_size,
		    "Temperature protect status:\n"
		    "Force radio off      = %u\n",
		    protect_db->force_radio_off);
	cl_snprintf(&buf, &len, &buf_size,
		    "Duty cycle           = %u\n",
		    protect_db->duty_cycle);
	cl_snprintf(&buf, &len, &buf_size,
		    "Test mode duty cycle = %u\n",
		    protect_db->test_mode_duty_cycle);

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

static void cl_temperature_protect_test_mode_set(struct cl_hw *cl_hw, u8 duty_cycle)
{
	cl_hw->temperature.protect_db.test_mode_duty_cycle = duty_cycle;

	if (duty_cycle == DUTY_CYCLE_MAX)
		pr_debug("Disable temp protection test mode\n");
	else
		pr_debug("Enable temp protection test mode [%u]\n", duty_cycle);
}

static void cl_temperature_comp_comp_slope_set(struct cl_hw *cl_hw, s8 slope)
{
	cl_hw->conf->ce_temp_comp_slope = slope;

	pr_debug("Temperature compensation slope: %d.%02d\n", slope / 100, slope % 100);
}

static void cl_temperature_comp_enable(struct cl_hw *cl_hw, s32 enable)
{
	struct cl_temperature *temperature = &cl_hw->temperature;
	struct cl_chip *chip = cl_hw->chip;

	if (enable) {
		cl_dbg_chip_verbose(chip, "enable\n");
		chip->conf->ce_temp_comp_en = true;
		if (!temperature->kthread)
			cl_temperature_init(cl_hw);
	} else {
		cl_dbg_chip_verbose(chip, "disable\n");
		chip->conf->ce_temp_comp_en = false;

		if (cl_chip_is_tcv0_enabled(chip))
			cl_temperature_set_power_offset(chip->cl_hw_tcv0, 0);
	}
}

static int cl_temperature_kthread(void *arg)
{
	struct cl_chip *chip = (struct cl_chip *)arg;
	struct cl_hw *cl_hw = NULL;
	unsigned long timeout = msecs_to_jiffies(CL_TEMPERATURE_TIMER_INTERVAL_MS);

	while (true) {
		cl_hw = chip->cl_hw_tcv0;

		if (cl_hw &&
		    !chip->fw_test &&
		    !chip->conf->ce_production_mode &&
		    test_bit(CL_DEV_STARTED, &cl_hw->drv_flags)) {
			cl_temperature_comp(chip, cl_hw);
			cl_temperature_protect(chip, cl_hw);
		}

		if (wait_event_timeout(cl_hw->temperature.wait_q, kthread_should_stop(), timeout)) {
			cl_dbg_chip_trace(chip, "exit temperature kthread\n");
			return 0;
		}
	}
}

static void cl_temperature_recovery_protect(struct cl_hw *cl_hw)
{
	struct cl_chip *chip = cl_hw->chip;

	if (chip->conf->ce_temp_protect_en != TEMP_PROTECT_OFF) {
		u8 duty_cycle = cl_hw->temperature.protect_db.duty_cycle;

		if (duty_cycle < DUTY_CYCLE_MAX) {
			u16 periodic_tx_time_on =
				chip->conf->ce_temp_protect_tx_period_ms * duty_cycle / 100;
			u16 periodic_tx_time_off =
				chip->conf->ce_temp_protect_tx_period_ms - periodic_tx_time_on;

			cl_msg_tx_start_periodic_tx_time(cl_hw, periodic_tx_time_off,
							 periodic_tx_time_on);
		}
	}
}

static void cl_temperature_recovery_comp(struct cl_hw *cl_hw)
{
	struct cl_chip *chip = cl_hw->chip;
	s8 power_offset = cl_hw->temp_comp_db.power_offset;

	if (!chip->conf->ce_temp_comp_en)
		return;

	if (power_offset)
		cl_temperature_set_power_offset(cl_hw, power_offset);
}

void cl_temperature_init(struct cl_hw *cl_hw)
{
	struct cl_temperature *temperature = &cl_hw->temperature;
	struct cl_temp_protect_db *temp_protect_db = &temperature->protect_db;
	unsigned long curr_time_ms = jiffies_to_msecs(jiffies);
	struct cl_chip *chip = cl_hw->chip;

	if (!chip->conf->ce_temp_comp_en &&
	    chip->conf->ce_temp_protect_en == TEMP_PROTECT_OFF)
		return;

	temperature->kthread = kthread_run(cl_temperature_kthread,
					   chip,
					   "cl_temperature_kthread_%u",
					   chip->idx);
	if (IS_ERR(temperature->kthread)) {
		cl_dbg_chip_err(chip, "Failed to create temperature kthread\n");
		temperature->kthread = NULL;
	}

	init_waitqueue_head(&temperature->wait_q);

	mutex_init(&temperature->mutex);
	temperature->internal_last = UNCALIBRATED_TEMPERATURE;
	temperature->internal_read_timestamp = curr_time_ms;
	temperature->external_last = UNCALIBRATED_TEMPERATURE;
	temperature->external_read_timestamp = curr_time_ms;

	/* Temp_protect_db init */
	temp_protect_db->duty_cycle = DUTY_CYCLE_MAX;
	temp_protect_db->test_mode_duty_cycle = DUTY_CYCLE_MAX;
	temp_protect_db->last_timestamp = curr_time_ms;
}

void cl_temperature_close(struct cl_hw *cl_hw)
{
	struct cl_temperature *temperature = &cl_hw->temperature;

	if (temperature->kthread) {
		cl_dbg_trace(cl_hw, "stopping temperature kthread\n");
		if (kthread_stop(temperature->kthread) != -EINTR)
			wake_up(&temperature->wait_q);

		temperature->kthread = NULL;
	}
}

s16 cl_temperature_get_internal(struct cl_hw *cl_hw)
{
	return cl_hw->temperature.internal_last;
}

s8 cl_temperature_read(struct cl_hw *cl_hw, enum cl_temp_mode mode)
{
	u16 raw_bits = 0;
	s16 temp_val = 0;
	unsigned long curr_time = jiffies_to_msecs(jiffies);
	unsigned long diff_time = 0;
	struct cl_chip *chip = cl_hw->chip;
	struct cl_temperature *temperature = &cl_hw->temperature;

	if (!IS_REAL_PHY(chip))
		return UNCALIBRATED_TEMPERATURE;

	mutex_lock(&temperature->mutex);

	switch (mode) {
	case TEMP_MODE_INTERNAL:
		diff_time = CL_TIME_DIFF(curr_time, temperature->internal_read_timestamp);
		if (diff_time <= CL_TEMPERATURE_UPDATE_INTERVAL_MS) {
			temp_val = temperature->internal_last;
			cl_dbg_chip_trace(chip, "Return last internal temperature %d\n", temp_val);
			goto read_out;
		}
		break;
	case TEMP_MODE_EXTERNAL:
		diff_time = CL_TIME_DIFF(curr_time, temperature->external_read_timestamp);
		if (diff_time <= CL_TEMPERATURE_UPDATE_INTERVAL_MS) {
			temp_val = temperature->external_last;
			cl_dbg_chip_trace(chip, "Return last external temperature %d\n", temp_val);
			goto read_out;
		}
		break;
	default:
		cl_dbg_chip_err(chip, "Invalid temperature mode %d\n", mode);
		goto read_err;
	}

	if (cl_temperature_read_fw(cl_hw, mode, &raw_bits)) {
		cl_dbg_chip_err(chip, "Temperature read failed\n");
		goto read_err;
	}

	temp_val = cl_raw_bits_to_temperature((s16)raw_bits, mode);

	if (temp_val > TEMPERATURE_MAX || temp_val < TEMPERATURE_MIN) {
		cl_dbg_chip_err(chip, "Invalid temperature value %d\n", temp_val);
		goto read_err;
	}

	/* Update temperature read db */
	if (mode == TEMP_MODE_INTERNAL) {
		temperature->internal_last = temp_val;
		temperature->internal_read_timestamp = jiffies_to_msecs(jiffies);
		cl_dbg_chip_trace(chip, "Read and save internal temperature %d\n", temp_val);
	} else {
		temperature->external_last = temp_val;
		temperature->external_read_timestamp = jiffies_to_msecs(jiffies);
		cl_dbg_chip_trace(chip, "Read and save external temperature %d\n", temp_val);
	}

read_out:
	mutex_unlock(&temperature->mutex);
	return temp_val;

read_err:
	/* If temperature read failed return the last valid value */
	mutex_unlock(&temperature->mutex);

	return (mode == TEMP_MODE_INTERNAL) ?
		temperature->internal_last : temperature->external_last;
}

static int cl_temperature_comp_print_config(struct cl_hw *cl_hw)
{
	struct cl_temp_comp_db *temp_comp_db = &cl_hw->temp_comp_db;
	s8 temp_comp_slope = cl_hw->conf->ce_temp_comp_slope;
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;

	cl_snprintf(&buf, &len, &buf_size,
		    "Internal temperature: %d\n",
		    cl_hw->temperature.internal_last);
	cl_snprintf(&buf, &len, &buf_size,
		    "Calib temperature:    %d\n",
		    temp_comp_db->calib_temperature);
	cl_snprintf(&buf, &len, &buf_size,
		    "Delta temperature:    %d\n",
		    temp_comp_db->avg_temp_delta);
	cl_snprintf(&buf, &len, &buf_size,
		    "Slope:                %d.%02d\n\n",
		    temp_comp_slope / 100, temp_comp_slope % 100);
	cl_snprintf(&buf, &len, &buf_size,
		    "Power offset:         %d\n",
		    temp_comp_db->power_offset);

	err = cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);

	return err;
}

static int cl_temperature_ret(struct cl_hw *cl_hw, u8 param)
{
	struct cl_chip *chip = cl_hw->chip;
	s8 curr_temp = 0;
	char reply_str[5] = {0};
	u16 reply_strlen = 0;

	switch (param) {
	case 0: /* Internal temp only */
		curr_temp = cl_temperature_read(cl_hw, TEMP_MODE_INTERNAL);
		cl_dbg_chip_trace(chip, "%d\n", curr_temp);
		break;
	case 1: /* External temp only */
		curr_temp = cl_temperature_read(cl_hw, TEMP_MODE_EXTERNAL);
		cl_dbg_chip_trace(chip, "%d\n", curr_temp);
		break;
	case 2: /* Internal temp + delta */
		curr_temp = cl_temperature_read(cl_hw, TEMP_MODE_INTERNAL) +
			chip->conf->ce_temp_protect_delta;
		cl_dbg_chip_trace(chip, "Internal + Delta = %d\n", curr_temp);
		break;
	case 3: /* External temp + delta */
		curr_temp = cl_temperature_read(cl_hw, TEMP_MODE_EXTERNAL) +
			chip->conf->ce_temp_protect_delta;
		cl_dbg_chip_trace(chip, "External + Delta = %d\n", curr_temp);
		break;
	case 4: /* Internal temp - temp_diff + delta */
		curr_temp = cl_temperature_read(cl_hw, TEMP_MODE_INTERNAL) -
			cl_hw->temperature.diff_internal_external +
			chip->conf->ce_temp_protect_delta;
		cl_dbg_chip_trace(chip, "Actual temperature: Internal - Diff + Delta = %d\n",
				  curr_temp);
		break;
	default:
		cl_dbg_chip_err(chip, "Invalid argument! must be between 0 and 4.\n");
		return 0;
	}

	reply_strlen = snprintf(&reply_str[0], sizeof(reply_str), "%d", curr_temp);
	return cl_vendor_reply(cl_hw, reply_str, reply_strlen);
}

int cl_temperature_cli(struct cl_hw *cl_hw, struct cli_params *cli_params)
{
	s32 *params = cli_params->params;

	switch (cli_params->option) {
		/* Temperature compenation */
	case 'a':
		if (cli_params->num_params != 0)
			goto err_num_params;

		return cl_temperature_comp_print_config(cl_hw);
	case 'b':
		if (cli_params->num_params != 1)
			goto err_num_params;

		cl_temperature_comp_enable(cl_hw, params[0]);
		break;
	case 'c':
		if (cli_params->num_params != 1)
			goto err_num_params;

		cl_temperature_comp_comp_slope_set(cl_hw, params[0]);
		break;
		/* Temperature protect */
	case 'k':
		return cl_temperature_protect_print_config(cl_hw);
	case 'l':
		return cl_temperature_protect_print_status(cl_hw);
	case 'm':
		if (cli_params->num_params != 1)
			goto err_num_params;

		cl_temperature_protect_test_mode_set(cl_hw, params[0]);
		break;
		/* Temperature general */
	case 'v':
		if (cli_params->num_params != 1)
			goto err_num_params;
		cl_temperature_ret(cl_hw, params[0]);
		break;
		/* Help */
	case '?':
		return cl_temperature_cli_help(cl_hw);
	default:
		cl_dbg_err(cl_hw, "Illegal option (%c) - try '?' for help\n", cli_params->option);
		break;
	}

	return 0;

err_num_params:
	cl_dbg_err(cl_hw, "Wrong number of arguments\n");
	return 0;
}

void cl_temperature_recovery(struct cl_hw *cl_hw)
{
	cl_temperature_recovery_protect(cl_hw);
	cl_temperature_recovery_comp(cl_hw);
}

bool cl_temperature_protect_did_reduce_duty_cycle(struct cl_hw *cl_hw)
{
	return cl_hw->temperature.protect_db.duty_cycle < DUTY_CYCLE_MAX;
}

s16 cl_temperature_calib_calc(struct cl_hw *cl_hw, u16 raw_bits)
{
	struct cl_chip *chip = cl_hw->chip;
	s16 temperature = cl_raw_bits_to_temperature(raw_bits, TEMP_MODE_INTERNAL) +
		chip->conf->ce_temp_protect_delta;

	if (temperature >= TEMPERATURE_MIN && temperature <= TEMPERATURE_MAX)
		return temperature;

	cl_dbg_chip_err(chip, "Invalid temperature = %d\n", temperature);

	return (cl_hw->temperature.internal_last + chip->conf->ce_temp_protect_delta);
}

void cl_temperature_comp_update_calib(struct cl_hw *cl_hw)
{
	u8 chan_idx = cl_channel_to_index(cl_hw, cl_hw->channel);
	u8 ant, power_level;
	s16 total_temp = 0;

	if (unlikely(chan_idx == INVALID_CHAN_IDX)) {
		cl_dbg_err(cl_hw, "Unsupported frequency %u\n", cl_hw->center_freq);
		return;
	}

	/* Sum up the temperature of all phys and power levels */
	for (ant = 0; ant < cl_hw->num_antennas; ant++)
		for (power_level = 0; power_level < MAX_POWER_LEVELS; power_level++)
			total_temp += cl_hw->tx_pow_info[chan_idx][ant][power_level].temperature;

	/* Average the total temperature and update chan_params */
	cl_hw->temp_comp_db.calib_temperature = DIV_ROUND_CLOSEST(total_temp, cl_hw->num_antennas *
								  MAX_POWER_LEVELS);
}

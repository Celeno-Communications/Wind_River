// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include <linux/string.h>
#include <linux/bitops.h>
#include <linux/workqueue.h>
#include <linux/delay.h>
#include <linux/fs.h>
#include <linux/buffer_head.h>

#include "cl_calibration.h"
#include "cl_temperature.h"
#include "cl_utils.h"
#include "cl_e2p.h"
#include "cl_otp.h"
#include "cl_channel.h"
#include "cl_power.h"

#define INVALID_ADDR 0xffff

static u8 ch_list_24g[NUM_OF_PIVOTS(NL80211_BAND_2GHZ)] = {
	CHANNEL_LOW_IDX_24G, CHANNEL_CENTER_IDX_24G, CHANNEL_HIGH_IDX_24G
};

static u8 ch_list_5g[NUM_OF_PIVOTS(NL80211_BAND_5GHZ)] = {
	CHANNEL_LOW_IDX_5G, CHANNEL_CENTER1_IDX_5G,
	CHANNEL_CENTER2_IDX_5G, CHANNEL_CENTER3_IDX_5G,
	CHANNEL_CENTER4_IDX_5G, CHANNEL_HIGH_IDX_5G
};

static u8 ch_list_6g[NUM_OF_PIVOTS(NL80211_BAND_6GHZ)] = {
	CHANNEL_LOW_IDX_6G, CHANNEL_CENTER1_IDX_6G,
	CHANNEL_CENTER2_IDX_6G, CHANNEL_CENTER3_IDX_6G,
	CHANNEL_CENTER4_IDX_6G, CHANNEL_HIGH_IDX_6G
};

static u8 idx_to_arr_offset(u8 idx)
{
	/* Divide by 8 for array index */
	return idx >> 3;
}

static u8 idx_to_bit_offset(u8 idx)
{
	/* Reminder is for bit index (assummed array of u8) */
	return idx & 0x07;
}

static u8 cl_calibration_bitmap_size(u8 band)
{
	if (band == NL80211_BAND_2GHZ)
		return 2;
	else if (band == NL80211_BAND_5GHZ)
		return 6;
	else
		return 8;
}

static u8 *cl_calibration_get_channel_list(u8 band)
{
	if (band == NL80211_BAND_2GHZ)
		return ch_list_24g;
	else if (band == NL80211_BAND_5GHZ)
		return ch_list_5g;
	else
		return ch_list_6g;
}

static bool is_vector_unset(const u8 *bitmap, u8 band)
{
	/* Check bitmap is unset i.e. all values are CURR_BMP_UNSET */
	u8 *empty_bitmap = kzalloc(cl_calibration_bitmap_size(band), GFP_KERNEL);
	u8 is_unset;

	if (!empty_bitmap)
		return -ENOMEM;

	is_unset = !memcmp(bitmap, empty_bitmap, cl_calibration_bitmap_size(band));
	kfree(empty_bitmap);

	return is_unset;
}

static int get_otp_idx_from_channel_idx(struct cl_hw *cl_hw, u8 ch_idx)
{
	/*
	 * Return the otp idx (0-low, 1-center1, 2-center2, 3-center3, 4-center4, 5-high)
	 * from channel idx, return -1 if the channel idx does not exist at the pivot list
	 */
	u8 *channel_list = cl_calibration_get_channel_list(cl_hw->nl_band);
	u8 i = 0;

	for (i = 0; i < NUM_OF_PIVOTS(cl_hw->nl_band); i++)
		if (channel_list[i] == ch_idx)
			return i;

	return -1;
}

static bool bitmap_test_bit_idx(struct cl_hw *cl_hw, const u8 *bitmap, u8 idx)
{
	/* Check bit at a given index is set i.e. 1 */
	u8 arr_idx = idx_to_arr_offset(idx), bit_idx = idx_to_bit_offset(idx);

	if (arr_idx >= cl_calibration_bitmap_size(cl_hw->nl_band)) {
		cl_dbg_err(cl_hw, "invalid arr_idx (%u), idx=%u\n", arr_idx, idx);
		return false;
	}

	/* Convert non-zero to true and zero to false */
	return !!(bitmap[arr_idx] & BIT(bit_idx));
}

static u16 bitmap_look_lsb_up(struct cl_hw *cl_hw, u8 *bitmap, u16 idx)
{
	/* Find closest ON(1) bit with index haigher than idx inside bitmap */
	u16 curr_idx = idx;
	u8 curr = 0;

	while (++curr_idx < cl_channel_num(cl_hw)) {
		curr = bitmap[idx_to_arr_offset(curr_idx)];
		if (curr & (1ULL << idx_to_bit_offset(curr_idx)))
			return curr_idx;
	}

	/* No matching bit found - return original index */
	return idx;
}

static u16 bitmap_look_msb_down(struct cl_hw *cl_hw, u8 *bitmap, u16 idx)
{
	/* Find closest ON(1) bit with index lower than idx inside bitmap */
	u16 curr_idx = idx;
	u8 curr = 0;

	if (idx >= cl_channel_num(cl_hw)) {
		cl_dbg_err(cl_hw, "Invalid channel index [%u]\n", idx);
		return idx;
	}

	while (curr_idx-- != 0) {
		curr = bitmap[idx_to_arr_offset(curr_idx)];
		if (curr & (1ULL << idx_to_bit_offset(curr_idx)))
			return curr_idx;
	}

	/* No matching bit found - return original index */
	return idx;
}

static bool bitmap_set_bit_idx(struct cl_hw *cl_hw, u8 *bitmap, u8 idx)
{
	/* Set bit at a given index */
	u8 arr_idx = idx_to_arr_offset(idx), bit_idx = idx_to_bit_offset(idx);

	if (arr_idx >= cl_calibration_bitmap_size(cl_hw->nl_band)) {
		cl_dbg_err(cl_hw, "invalid arr_idx (%u)\n", arr_idx);
		return false;
	}

	bitmap[arr_idx] |= BIT(bit_idx);

	return true;
}

static int read_validate_vector_bitmap(struct cl_hw *cl_hw, u8 *bitmap, bool is_set_calib)
{
	struct cl_chip *chip = cl_hw->chip;
	u8 *first_pl_data = kzalloc(NUM_OF_PIVOTS(cl_hw->nl_band), GFP_KERNEL);
	u8 idx_channel = 0;
	u8 idx = 0;
	u8 num_pivot = NUM_OF_PIVOTS(cl_hw->nl_band);
	u8 *channel_list = cl_calibration_get_channel_list(cl_hw->nl_band);

	if (!first_pl_data)
		return -ENOMEM;

	/* Read the first power level per band */
	if (chip->conf->ce_eeprom_en == E2P_MODE_ENABLED) {
		if (cl_e2p_read(chip, first_pl_data, NUM_OF_PIVOTS(cl_hw->nl_band),
				cl_calibration_start_addr(cl_hw->nl_band,
							  chip->conf->ce_eeprom_en))) {
			kfree(first_pl_data);

			return -1;
		}
	} else {
		if (cl_otp_read_bytes(chip, first_pl_data, NUM_OF_PIVOTS(cl_hw->nl_band),
				      cl_calibration_start_addr(cl_hw->nl_band,
								chip->conf->ce_eeprom_en))) {
			kfree(first_pl_data);

			return -1;
		}
	}

	while (num_pivot--) {
		idx_channel = channel_list[idx];

		if (first_pl_data[idx] && first_pl_data[idx] != UNCALIBRATED_PDI_E2P) {
			if (!bitmap_set_bit_idx(cl_hw, bitmap, idx_channel)) {
				cl_dbg_err(cl_hw, "Bad channel index %u", idx_channel);
				kfree(first_pl_data);

				return -EINVAL;
			}
		}

		idx++;
	}

	/* Test if otp/e2p was read successfully since it is not ALL EMPTY */
	if (!is_set_calib && is_vector_unset(bitmap, cl_hw->nl_band)) {
		cl_dbg_err(cl_hw, "Vector not ready\n");
		kfree(first_pl_data);

		return -EPERM;
	}

	kfree(first_pl_data);

	return 0;
}

static int point_idx_to_byte_address(struct cl_hw *cl_hw, u8 *bitmap, struct point *pt,
				     bool test_bitmap)
{
	/* Calculate byte address for a given idx and phy (initiated point) */
	pt->addr = INVALID_ADDR;

	if (test_bitmap && !bitmap_test_bit_idx(cl_hw, bitmap, pt->idx))
		return 0;

	if (pt->phy >= MAX_ANTENNAS) {
		cl_dbg_err(cl_hw, "Invalid phy number %u", pt->phy);

		return -EINVAL;
	}

	if (pt->power_level >= MAX_POWER_LEVELS) {
		cl_dbg_err(cl_hw, "Invalid power level (%d). Valid range (%d - %d)\n",
			   pt->power_level, 0, MAX_POWER_LEVELS - 1);

		return -EPERM;
	}

	pt->addr =
		  cl_calibration_start_addr(cl_hw->nl_band, cl_hw->chip->conf->ce_eeprom_en) +
					    NUM_OF_PIVOTS(cl_hw->nl_band) * pt->phy +
					    get_otp_idx_from_channel_idx(cl_hw, pt->idx);

	return 0;
}

static bool linear_equation_signed(struct cl_hw *cl_hw, const u16 x, s8 *y,
				   const u16 x0, const s8 y0, const u16 x1, const s8 y1)
{
	/* Calculate y given to points (x0,y0) and (x1,y1) and x */
	s32 numerator = (x - x0) * (y1 - y0);
	s32 denominator = x1 - x0;

	if (unlikely(!denominator)) {
		cl_dbg_err(cl_hw, "zero denominator\n");
		return false;
	}

	*y = (s8)(y0 + DIV_ROUND_CLOSEST(numerator, denominator));

	return true;
}

static bool calculate_calib(struct cl_hw *cl_hw, u8 *bitmap,
			    struct point *p0, struct point *p1, struct point *p2)
{
	/* Main interpolation/extrapolation function */
	bool calc_succsess = false;
	u16 freq0, freq1, freq2;

	if (unlikely(is_vector_unset(bitmap, cl_hw->nl_band)))
		return false;

	p1->idx = bitmap_look_lsb_up(cl_hw, bitmap, p0->idx);
	p2->idx = bitmap_look_msb_down(cl_hw, bitmap, p0->idx);

	p1->chan = cl_ch_idx_to_channel(cl_hw, p1->idx);
	p2->chan = cl_ch_idx_to_channel(cl_hw, p2->idx);

	/* Invalid case */
	if (p1->idx == p0->idx && p2->idx == p0->idx) {
		cl_dbg_err(cl_hw, "Invalid index %u or bad bit map\n", p0->idx);
		return false;
	}

	/* Extrapolation case */
	if (p1->idx == p0->idx)
		p1->idx = bitmap_look_msb_down(cl_hw, bitmap, p2->idx);
	if (p2->idx == p0->idx)
		p2->idx = bitmap_look_lsb_up(cl_hw, bitmap, p1->idx);

	/* Address from index */
	if (point_idx_to_byte_address(cl_hw, bitmap, p1, true) || p1->addr == INVALID_ADDR) {
		cl_dbg_err(cl_hw, "Point calculation failed\n");
		return false;
	}

	if (point_idx_to_byte_address(cl_hw, bitmap, p2, true) || p2->addr == INVALID_ADDR) {
		cl_dbg_err(cl_hw, "Point calculation failed\n");
		return false;
	}

	/* Read from otp/e2p */
	if (cl_hw->chip->conf->ce_eeprom_en == E2P_MODE_ENABLED) {
		if (cl_e2p_read(cl_hw->chip, (u8 *)&p1->calib.pdi, 1, p1->addr))
			return false;

		if (cl_e2p_read(cl_hw->chip, (u8 *)&p1->calib.temp, 1,
				p1->addr + SIZE_DELTA_CALIB_TO_TEMP))
			return false;

	} else {
		if (cl_otp_read_bytes(cl_hw->chip, (u8 *)&p1->calib.pdi, 1, p1->addr))
			return false;
	}

	/* No interpolation required */
	if (p1->addr == p2->addr) {
		p0->calib = p1->calib;

		return true;
	}

	/* Interpolation or extrapolation is required - read from otp/e2p */
	if (cl_hw->chip->conf->ce_eeprom_en == E2P_MODE_ENABLED) {
		if (cl_e2p_read(cl_hw->chip, (u8 *)&p2->calib.pdi, 1, p2->addr))
			return false;

		if (cl_e2p_read(cl_hw->chip, (u8 *)&p2->calib.temp, 1,
				p2->addr + SIZE_DELTA_CALIB_TO_TEMP))
			return false;
	} else {
		if (cl_otp_read_bytes(cl_hw->chip, (u8 *)&p2->calib.pdi, 1, p2->addr))
			return false;
	}

	freq0 = cl_channel_idx_to_freq(cl_hw, p0->idx);
	freq1 = cl_channel_idx_to_freq(cl_hw, p1->idx);
	freq2 = cl_channel_idx_to_freq(cl_hw, p2->idx);

	/* Interpolate/extrapolate pdi */
	calc_succsess = linear_equation_signed(cl_hw,
					       freq0, &p0->calib.pdi,
					       freq1, p1->calib.pdi,
					       freq2, p2->calib.pdi);

	if (cl_hw->chip->conf->ce_eeprom_en == E2P_MODE_ENABLED)
		/* Interpolate/extrapolate calibration temperature */
		calc_succsess = calc_succsess && linear_equation_signed(cl_hw,
									freq0, &p0->calib.temp,
									freq1, p1->calib.temp,
									freq2, p2->calib.temp);

	if (unlikely(!calc_succsess)) {
		cl_dbg_err(cl_hw,
			   "Calc failed: freq0 %u idx0 %u, freq1 %u idx1 %u, freq2 %u idx2 %u\n",
			   freq0, p0->idx, freq1, p1->idx, freq2, p2->idx);
		return false;
	}

	return true;
}

static int otp_e2p_prepare(struct cl_hw *cl_hw, struct point *data, u8 *bitmap, bool is_set)
{
	int ret = read_validate_vector_bitmap(cl_hw, bitmap, is_set);

	if (ret) {
		cl_dbg_err(cl_hw, "read_validate_vector_bitmap failed\n");
		return ret;
	}

	/*
	 * If is_set is true data->chan is (0-low, 1-center1, 2-center2, 3-center3, 4-center4,
	 * 5-high). If is_set is false data->chan is real channel number
	 */
	if (is_set) {
		data->idx = idx_chan_from_otp_idx(cl_hw, data->chan);
		data->chan = cl_ch_idx_to_channel(cl_hw, data->idx);
	} else {
		data->idx = cl_channel_to_index(cl_hw, data->chan);
	}

	if (data->idx == INVALID_CHAN_IDX)
		return 0;

	return point_idx_to_byte_address(cl_hw, bitmap, data, !is_set);
}

static int read_or_interpolate_point(struct cl_hw *cl_hw, u8 *bitmap, struct point *p0)
{
	struct point p1 = {.phy = p0->phy};
	struct point p2 = {.phy = p0->phy};
	struct point tmp_pt = *p0;

	/* Invalid address = no physical address was allocated to this channel */
	if (tmp_pt.addr != INVALID_ADDR) {
		if (cl_hw->chip->conf->ce_eeprom_en == E2P_MODE_ENABLED) {
			if (cl_e2p_read(cl_hw->chip, (u8 *)&tmp_pt.calib.pdi,
					1, tmp_pt.addr))

				return -1;

			if (cl_e2p_read(cl_hw->chip, (u8 *)&tmp_pt.calib.temp,
					1, tmp_pt.addr + SIZE_DELTA_CALIB_TO_TEMP))

				return -1;
		} else {
			if (cl_otp_read_bytes(cl_hw->chip, (u8 *)&tmp_pt.calib.pdi,
					      1, tmp_pt.addr))

				return -1;
		}
	} else {
		/* Interpolate */
		if (!calculate_calib(cl_hw, bitmap, &tmp_pt, &p1, &p2)) {
			cl_dbg_err(cl_hw, "Interpolation Error\n");
			return -EFAULT;
		}
	}

	if (tmp_pt.calib.pdi == (UNCALIBRATED_PDI_E2P || UNCALIBRATED_PDI_OTP) &&
	    tmp_pt.calib.temp == 0) {
		u16 freq = cl_channel_idx_to_freq(cl_hw, tmp_pt.idx);

		cl_dbg_err(cl_hw, "Verify calibration point: addr %x, idx %u, freq %u, phy %u\n",
			   tmp_pt.addr, tmp_pt.idx, freq, tmp_pt.phy);
		/* Uninitialized otp / eeprom value */
		return -EINVAL;
	}

	/* Now p0 will contain "Valid" calculations of calib" */
	p0->calib = tmp_pt.calib;

	return 0;
}

static int cl_calibration_power_offset_to_pdi(s8 power_offset)
{
	/*
	 * The input of set calib is power offset in 0.25 dB resolution (valid values are -40 - 80)
	 * but the write should be PDI - Power Difference Index (valid values are 1 - 121 [0.25dBm])
	 */
	return power_offset + 41;
}

s8 cl_calibration_pdi_to_power_offset(s8 pdi)
{
	/*
	 * Get calib read PDI - Power Difference Index (valid values are 1 - 121 [0.25dBm]),
	 * the user expect to get power offset in 0.25 dB resolution (valid values are -40 - 80),
	 * which represent -10 - 20 [dB].
	 */
	return pdi - 41;
}

u16 cl_calibration_start_addr(u8 band, bool is_e2p)
{
	u16 start_bitmap_addr;

	if (band == NL80211_BAND_2GHZ)
		start_bitmap_addr = is_e2p ? ADDR_CALIB_24G_E2P : ADDR_CALIB_24G_OTP;
	else if (band == NL80211_BAND_5GHZ)
		start_bitmap_addr = is_e2p ? ADDR_CALIB_5G_E2P : ADDR_CALIB_5G_OTP;
	else
		start_bitmap_addr = is_e2p ? ADDR_CALIB_6G_E2P : ADDR_CALIB_6G_OTP;

	return start_bitmap_addr;
}

int idx_chan_from_otp_idx(struct cl_hw *cl_hw, u8 otp_idx)
{
	/*
	 * Return the channel idx from otp idx
	 * (0-low, 1-center1, 2-center2, 3-center3, 4-center4, 5-high)
	 */
	u8 *channel_list = cl_calibration_get_channel_list(cl_hw->nl_band);

	if (otp_idx < NUM_OF_PIVOTS(cl_hw->nl_band))
		return channel_list[otp_idx];

	cl_dbg_err(cl_hw, "invalid otp_idx (%u), max value (%u)\n",
		   otp_idx, NUM_OF_PIVOTS(cl_hw->nl_band) - 1);

	return INVALID_CHAN_IDX;
}

int cl_calibration_get_calib(struct wiphy *wiphy, struct wireless_dev *wdev,
			     const void *data, int data_len, bool is_otp)
{
	/* Kernel space callback for handling E2P_GET_CALIB vendor subcmd */
	int ret;
	struct point *p0;
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	u8 *bitmap = kzalloc(cl_calibration_bitmap_size(cl_hw->nl_band), GFP_KERNEL);
	bool is_set = false;

	if (!bitmap)
		return -ENOMEM;

	if (!data) {
		cl_dbg_err(cl_hw, "data is null\n");
		kfree(bitmap);
		return -1;
	}

	if (is_otp && cl_hw->chip->conf->ce_eeprom_en == E2P_MODE_ENABLED) {
		cl_dbg_err(cl_hw, "No permition to use otp while ce_eeprom_en = 1\n");
		kfree(bitmap);
		return -EPERM;
	}

	p0 = (struct point *)data;

	ret = otp_e2p_prepare(cl_hw, p0, bitmap, is_set);
	if (ret) {
		cl_dbg_err(cl_hw, "Unable prepare otp /e2p\n");
		kfree(bitmap);
		return ret;
	}

	ret = read_or_interpolate_point(cl_hw, bitmap, p0);
	if (ret) {
		cl_dbg_trace(cl_hw, "read_or_interpolate_point error\n");
		kfree(bitmap);
		return ret;
	}

	p0->calib.power_offset = cl_calibration_pdi_to_power_offset(p0->calib.pdi);

	kfree(bitmap);

	return cl_vendor_reply(cl_hw, &p0->calib, sizeof(p0->calib));
}

int cl_calibration_set_calib(struct wiphy *wiphy, struct wireless_dev *wdev,
			     const void *data, int data_len, bool is_otp)
{
	/* Kernel space callback for handling E2P_SET_CALIB vendor subcmd */
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	struct point pt;
	int ret;
	u8 *bitmap;
	u8 ch_idx = 0;
	bool is_set = true;

	if (is_otp && cl_hw->chip->conf->ce_eeprom_en == E2P_MODE_ENABLED) {
		cl_dbg_err(cl_hw, "No permition to use otp while ce_eeprom_en = 1\n");
		return -EPERM;
	}

	if (!data) {
		cl_dbg_err(cl_hw, "data is null\n");
		return -1;
	}

	bitmap = kzalloc(cl_calibration_bitmap_size(cl_hw->nl_band), GFP_KERNEL);

	if (!bitmap)
		return -ENOMEM;

	pt = *(struct point *)data;

	ret = otp_e2p_prepare(cl_hw, &pt, bitmap, is_set);
	if (ret) {
		cl_dbg_err(cl_hw, "Unable prepare otp / e2p\n");
		kfree(bitmap);
		return ret;
	}

	if (pt.addr == INVALID_ADDR) {
		cl_dbg_err(cl_hw, "Invalid address - permission denied\n");
		kfree(bitmap);
		return -EPERM;
	}

	if (pt.calib.power_offset < POWER_OFFSET_MIN_VAL ||
	    pt.calib.power_offset > POWER_OFFSET_MAX_VAL) {
		cl_dbg_err(cl_hw, "Invalid power offset (%d). Valid range (%d - %d)\n",
			   pt.calib.power_offset, POWER_OFFSET_MIN_VAL, POWER_OFFSET_MAX_VAL);
		kfree(bitmap);
		return -EPERM;
	}

	pt.calib.pdi = cl_calibration_power_offset_to_pdi(pt.calib.power_offset);

	if (cl_hw->chip->conf->ce_eeprom_en == E2P_MODE_ENABLED) {
		/*
		 * Temperature is an optional argument for "e2p set calib" command.
		 * If value is 0x7f then temperature argument was not set, and it
		 * should be set by the driver.
		 */
		if (pt.calib.temp == S8_MAX)
			pt.calib.temp = cl_temperature_read(cl_hw, TEMP_MODE_INTERNAL);

		if (cl_e2p_write(cl_hw->chip, (u8 *)&pt.calib.pdi, sizeof(s8), pt.addr)) {
			kfree(bitmap);
			return -1;
		}

		if (cl_e2p_write(cl_hw->chip, (u8 *)&pt.calib.temp, sizeof(s8),
				 pt.addr + SIZE_DELTA_CALIB_TO_TEMP)) {
			kfree(bitmap);
			return -1;
		}
	} else {
		if (cl_hw->chip->conf->ce_otp_mode) {
			cl_dbg_err(cl_hw, "No permition to write directly to otp\n");
			kfree(bitmap);
			return -EPERM;
		}

		if (cl_otp_write_api(cl_hw->chip, (u8 *)&pt.calib.pdi, sizeof(s8), pt.addr)) {
			kfree(bitmap);
			return -1;
		}
	}

	if (pt.chan < NUM_OF_PIVOTS(cl_hw->nl_band) && pt.phy < MAX_ANTENNAS) {
		cl_hw->tx_pow_info[ch_idx][pt.phy][pt.power_level].offset = pt.calib.power_offset;
		cl_hw->set_calib = true;

		if (cl_hw->chip->conf->ce_eeprom_en == E2P_MODE_ENABLED)
			cl_hw->tx_pow_info[ch_idx][pt.phy][pt.power_level].temperature  =
			pt.calib.temp;
	}

	kfree(bitmap);

	return 0;
}

static void cl_calibration_power_reset(struct cl_hw *cl_hw)
{
	u8 ch_idx;
	u16 phy;
	u8 power_level;
	static const struct cl_tx_power_info default_info = {
		.offset      = UNCALIBRATED_POWER_OFFSET,
		.temperature = UNCALIBRATED_TEMPERATURE
	};

	/* Initiate tx_pdi to default value */
	for (ch_idx = 0; ch_idx < cl_channel_num(cl_hw); ch_idx++)
		for (phy = 0; phy < MAX_ANTENNAS; phy++)
			for (power_level = 0; power_level < MAX_POWER_LEVELS; power_level++)
				cl_hw->tx_pow_info[ch_idx][phy][power_level] = default_info;
}

void cl_calibration_power_read(struct cl_hw *cl_hw)
{
	int ret;
	u8 *bitmap = kzalloc(cl_calibration_bitmap_size(cl_hw->nl_band), GFP_KERNEL);
	struct point curr_point = {0};
	u8 *phy = &curr_point.phy;
	u8 *ch_idx = &curr_point.idx;
	u8 power_level;

	if (!bitmap)
		return;

	/* Initiate tx_pow_info struct to default values */
	cl_calibration_power_reset(cl_hw);

	/* Vector not initiated set table to default values */
	if (unlikely(read_validate_vector_bitmap(cl_hw, bitmap, false))) {
		cl_dbg_trace(cl_hw, "initiate to default values\n");
		kfree(bitmap);
		return;
	}

	/* Perform only on calibrated boards - read_validate_vector_bitmap succeeded (0) */
	for (*ch_idx = 0; *ch_idx < cl_channel_num(cl_hw); (*ch_idx)++)
		for (*phy = 0; *phy < cl_hw->num_antennas; (*phy)++) {
			for (power_level = 0; power_level < MAX_POWER_LEVELS; power_level++) {
				ret = point_idx_to_byte_address(cl_hw, bitmap, &curr_point, false);

				if (ret) {
					/* Don't overwrite default values */
					cl_dbg_err(cl_hw, "point idx to address failed\n");
					continue;
				}

				ret = read_or_interpolate_point(cl_hw, bitmap, &curr_point);

				/* Unable to calculate new val => DON'T overwrite default values */
				if (unlikely(ret))
					continue;

				cl_hw->tx_pow_info[*ch_idx][*phy][power_level].offset =
				cl_calibration_pdi_to_power_offset(curr_point.calib.pdi);

				if (cl_hw->chip->conf->ce_eeprom_en == E2P_MODE_ENABLED)
					cl_hw->tx_pow_info[*ch_idx][*phy][power_level].temperature =
					curr_point.calib.temp;
			}
		}

	cl_dbg_trace(cl_hw, "Created tx_pow_info\n");
	kfree(bitmap);
}

void cl_calibration_power_offset_fill(struct cl_hw *cl_hw, u8 channel,
				      u8 bw, u8 offset[MAX_ANTENNAS])
{
	u8 i;
	u8 chan_idx = cl_channel_to_index(cl_hw, channel);
	s8 signed_offset;
	struct cl_ate_db *ate_db = &cl_hw->ate_db;
	u8 power_level = 0;

	if (chan_idx == INVALID_CHAN_IDX)
		return;

	/* In ATE mode, use values of 'ATE power_offset' if it was set */
	if (ate_db->active && ate_db->tx_power_offset[0] != S8_MAX) {
		for (i = 0; i < MAX_ANTENNAS; i++) {
			s8 pow_offset = ate_db->tx_power_offset[i];

			signed_offset = cl_power_offset_check_margin(cl_hw, bw, i, pow_offset);
			offset[i] = cl_convert_signed_to_reg_value(signed_offset);
		}

		return;
	}

	for (i = 0; i < MAX_ANTENNAS; i++) {
		for (power_level = 0; power_level < MAX_POWER_LEVELS; power_level++) {
			s8 pow_offset = cl_hw->tx_pow_info[chan_idx][i][power_level].offset;

			signed_offset = cl_power_offset_check_margin(cl_hw, bw, i, pow_offset);
			offset[i] = cl_convert_signed_to_reg_value(signed_offset);
		}
	}
}

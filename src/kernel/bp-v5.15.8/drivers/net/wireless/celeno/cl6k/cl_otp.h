/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_OTP_H
#define CL_OTP_H

#include "chip.h"
#include "cl_hw.h"
#include "cl_vendor_cmd.h"

struct cl_otp_get_reply {
	u8 otp_mode;
	u8 otp_data[];
};

int cl_otp_set_addr(struct wiphy *wiphy, struct wireless_dev *wdev,
		    const void *data, int data_len);
int cl_otp_set_module_hw_type(struct wiphy *wiphy, struct wireless_dev *wdev,
			      const void *data, int data_len);
int cl_otp_get_addr(struct wiphy *wiphy, struct wireless_dev *wdev,
		    void *data, int data_len);
int cl_otp_help(struct wiphy *wiphy, struct wireless_dev *wdev,
		void *data, int data_len);
int cl_otp_read_api(struct cl_chip *chip, u32 *data, u16 size, u16 addr);
int cl_otp_write_api(struct cl_chip *chip, u8 *data, u16 size, u16 addr);
int cl_otp_init(struct cl_chip *chip);
int cl_otp_read_bytes(struct cl_chip *chip, u8 *data, u16 num_of_bytes, u16 byte_addr);
int cl_otp_cli(struct cl_hw *cl_hw, struct cli_params *cli_params);

enum {
	OTP_SIZE_WORD = sizeof(u32),
	ADDR_BOOTER_OTP = offsetof(struct otp, booter),
	ADDR_DEVICE_ID_OTP = ADDR_BOOTER_OTP + offsetof(struct otp_booter, data_device_id),
	ADDR_JTAG_MODE_OTP = ADDR_BOOTER_OTP + offsetof(struct otp_booter, address_jtag_mode),

	ADDR_MAC_ADDR_OTP = offsetof(struct otp, mac_address),
	ADDR_PADDING_OTP = offsetof(struct otp, mac_padding),
	ADDR_FREQ_OFFSET_OTP = offsetof(struct otp, freq_offset),
	ADDR_AMBIENT_TEMP_OTP = offsetof(struct otp, ambient_temperature),
	ADDR_CALIB_24G_OTP = offsetof(struct otp, wifi_tx_power_calib_offfset),
	ADDR_CALIB_5G_OTP = ADDR_CALIB_24G_OTP +
			    MAX_ANTENNAS * MAX_POWER_LEVELS *  NUM_OF_PIVOTS(NL80211_BAND_2GHZ),
	ADDR_CALIB_6G_OTP = ADDR_CALIB_5G_OTP +
			    MAX_ANTENNAS * MAX_POWER_LEVELS * NUM_OF_PIVOTS(NL80211_BAND_5GHZ),
	ADDR_WIFI_VAL_PL0_OTP = offsetof(struct otp, wifi_value_pl_idx),
	OTP_NUM_BYTES = sizeof(struct otp),

	SIZE_DEVICE_ID_OTP = ADDR_JTAG_MODE_OTP - ADDR_DEVICE_ID_OTP,

	SIZE_MAC_ADDR_OTP = ADDR_PADDING_OTP - ADDR_MAC_ADDR_OTP,
	SIZE_FREQ_OFFSET_OTP = ADDR_AMBIENT_TEMP_OTP - ADDR_FREQ_OFFSET_OTP,
};

enum cl_otp_cmd {
	CL_OTP_GET_MAC,
	CL_OTP_GET_POWER_LEVEL,
	CL_OTP_GET_FREQ_OFFSET,
	CL_OTP_GET_MODULE_HW_TYPE,
	CL_OTP_GET_MODULE_HW_REVID,
	CL_OTP_GET_RFIC_WIFI_VERSION_FOR_CALIB,
	CL_OTP_GET_RFIC_BT_VERSION_FOR_CALIB,
	CL_OTP_GET_RFIC_LUT_VERSION_FOR_CALIB,
	CL_OTP_GET_CALIB,

	CL_OTP_SET_ADDR,
	CL_OTP_SET_MAC,
	CL_OTP_SET_POWER_LEVEL,
	CL_OTP_SET_FREQ_OFFSET,
	CL_OTP_SET_MODULE_HW_REVID,
	CL_OTP_SET_RFIC_WIFI_VERSION_FOR_CALIB,
	CL_OTP_SET_RFIC_BT_VERSION_FOR_CALIB,
	CL_OTP_SET_RFIC_LUT_VERSION_FOR_CALIB,
	CL_OTP_SET_MODULE_HW_TYPE,
	CL_OTP_SET_CALIB,

	CL_OTP_MAX
};

#endif /* CL_OTP_H */

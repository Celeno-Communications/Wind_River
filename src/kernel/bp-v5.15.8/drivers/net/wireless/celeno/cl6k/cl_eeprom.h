/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_EEPROM_H
#define CL_EEPROM_H

#include <linux/kernel.h>
#include <linux/nl80211.h>
#include "def.h"

#define NUM_OF_PIVOTS(_band) ((_band) == 0 ? 3 : 6)

struct eeprom_wifi_tx_power_module_offset {
	u8 wifi_module_offset_ch0_2_4G;
	u8 wifi_module_offset_ch1_2_4G;
	u8 wifi_module_offset_ch0_5_7G;
	u8 wifi_module_offset_ch1_5_7G;
} __packed;

struct eeprom_bt_tx_power_module_offset {
	u8 BT_tx_power_module_offset;
	u8 BT_tx_power[3];
} __packed;

struct eeprom_module_hw {
	u8 module_hw_type;
	u8 module_hw_rev_id_major;
	u8 module_hw_rev_id_minor;
	u8 otp_eeprom_format;
} __packed;

struct eeprom_rfic_version {
	u8 rfic_wifi_version_calib[2];
	u8 rfic_bt_version_calib[2];
	u8 rfic_lut_version_calib;
	u8 rfic_spare_version_calib;
} __packed;

struct eeprom {
	u8 magic_num[2];
	u8 reserved[2];
	struct eeprom_wifi_tx_power_module_offset wifi_tx_power_module_offset;
	struct eeprom_bt_tx_power_module_offset bt_tx_power_module_offset;
	struct eeprom_module_hw module_hw;
	struct eeprom_rfic_version rfic_version;
	u8 spare_version[2];
	u16 freq_offset;
	u8 freq_offset_reserved[2];
	u8 ambient_temperature[4];
	u8 bt_tx_power_calib_offset[16];
	u8 wifi_tx_power_calib_offfset[120];
	u8 wifi_value_pl_idx[4];
	u8 bt_tx_power_calib_temperature[12];
	u8 wifi_tx_power_calib_temperature[120];
} __packed;

enum {
	ADDR_FREQ_OFFSET_E2P = offsetof(struct eeprom, freq_offset),
	ADDR_AMBIENT_TEMP_E2P = offsetof(struct eeprom, ambient_temperature),

	ADDR_CALIB_24G_E2P = offsetof(struct eeprom, wifi_tx_power_calib_offfset),
	ADDR_CALIB_5G_E2P = ADDR_CALIB_24G_E2P +
			    MAX_ANTENNAS * MAX_POWER_LEVELS *  NUM_OF_PIVOTS(NL80211_BAND_2GHZ),
	ADDR_CALIB_6G_E2P = ADDR_CALIB_5G_E2P +
			    MAX_ANTENNAS * MAX_POWER_LEVELS * NUM_OF_PIVOTS(NL80211_BAND_5GHZ),

	ADDR_TEMP_24G_E2P = offsetof(struct eeprom, wifi_tx_power_calib_temperature),
	ADDR_TEMP_5G_E2P = ADDR_TEMP_24G_E2P +
			    MAX_ANTENNAS * MAX_POWER_LEVELS *  NUM_OF_PIVOTS(NL80211_BAND_2GHZ),
	ADDR_TEMP_6G_E2P = ADDR_TEMP_5G_E2P +
			    MAX_ANTENNAS * MAX_POWER_LEVELS * NUM_OF_PIVOTS(NL80211_BAND_5GHZ),
	ADDR_WIFI_VAL_PL0_E2P = offsetof(struct eeprom, wifi_value_pl_idx),

	SIZE_FREQ_OFFSET_E2P = ADDR_AMBIENT_TEMP_E2P - ADDR_FREQ_OFFSET_E2P,
	SIZE_DELTA_CALIB_TO_TEMP = ADDR_TEMP_24G_E2P - ADDR_CALIB_24G_E2P,

	EEPROM_NUM_BYTES = sizeof(struct eeprom),
	EEPROM_LAST_BYTE = EEPROM_NUM_BYTES - 1,
};

#endif /* CL_EEPROM_H */

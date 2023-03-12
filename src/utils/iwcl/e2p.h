#ifndef __E2P_H
#define __E2P_H

#include "iwcl.h"

// All the below must be aligned with kernel

#define NUM_OF_PIVOTS(_band) ((_band) == 0 ? 3 : 6)
#define NUM_TOTAL_PIVOTS   15
#define MAX_POWER_LEVELS 4

struct cl_e2p_get_reply {
	uint8_t e2p_mode;
	uint8_t e2p_data[];
};

struct eeprom_wifi_tx_power_module_offset {
	uint8_t wifi_module_offset_ch0_2_4G;
	uint8_t wifi_module_offset_ch1_2_4G;
	uint8_t wifi_module_offset_ch0_5_7G;
	uint8_t wifi_module_offset_ch1_5_7G;
} __attribute__((__packed__));

struct eeprom_bt_tx_power_module_offset {
	uint8_t BT_tx_power_module_offset;
	uint8_t BT_tx_power[3];
} __attribute__((__packed__));

struct eeprom_module_hw {
	uint8_t module_hw_type;
	uint8_t module_hw_rev_id_major;
	uint8_t module_hw_rev_id_minor;
	uint8_t otp_eeprom_format;
} __attribute__((__packed__));

struct eeprom_rfic_version {
	uint8_t rfic_wifi_version_calib[2];
	uint8_t rfic_bt_version_calib[2];
	uint8_t rfic_lut_version_calib;
	uint8_t rfic_spare_version_calib;
} __attribute__((__packed__));


struct eeprom {
	uint8_t magic_num[2];
	uint8_t reserved[2];
	struct eeprom_wifi_tx_power_module_offset wifi_tx_power_module_offset;
	struct eeprom_bt_tx_power_module_offset bt_tx_power_module_offset;
	struct eeprom_module_hw module_hw;
	struct eeprom_rfic_version rfic_version;
	uint8_t spare_version[2];
	uint16_t freq_offset;
	uint8_t freq_offset_reserved[2];
	uint8_t ambient_temperature[4];
	uint8_t bt_tx_power_calib_offset[16];
	uint8_t wifi_tx_power_calib_offfset[120];
	uint8_t wifi_value_pl_idx[4];
	uint8_t bt_tx_power_calib_temperature[12];
	uint8_t wifi_tx_power_calib_temperature[120];
} __attribute__((__packed__));

struct phy_calib {
	int8_t power_offset;
	int8_t pdi;
	int8_t temp;
} __attribute__((__packed__));

struct point {
	uint8_t power_level;
	uint8_t chan;
	uint8_t phy;
	uint8_t idx;
	uint16_t addr;
	struct phy_calib calib;
} __attribute__((__packed__));

enum {
	ADDR_MODULE_HW_VERSION_E2P = offsetof(struct eeprom, module_hw),
	ADDR_MODULE_HW_TYPE_E2P = ADDR_MODULE_HW_VERSION_E2P + offsetof(struct eeprom_module_hw, module_hw_type),
	ADDR_MODULE_HW_REVID_E2P = ADDR_MODULE_HW_VERSION_E2P + offsetof(struct eeprom_module_hw, module_hw_rev_id_major),
	ADDR_OTP_E2P_FORMAT_VERSION_E2P = ADDR_MODULE_HW_VERSION_E2P + offsetof(struct eeprom_module_hw, otp_eeprom_format),

	ADDR_RFIC_VERSION_E2P = offsetof(struct eeprom, rfic_version),
	ADDR_RFIC_WIFI_VERSION_FOR_CALIB_E2P = ADDR_RFIC_VERSION_E2P + offsetof(struct eeprom_rfic_version, rfic_wifi_version_calib),
	ADDR_RFIC_BT_VERSION_FOR_CALIB_E2P = ADDR_RFIC_VERSION_E2P + offsetof(struct eeprom_rfic_version, rfic_bt_version_calib),
	ADDR_RFIC_LUT_VERSION_FOR_CALIB_E2P = ADDR_RFIC_VERSION_E2P + offsetof(struct eeprom_rfic_version, rfic_lut_version_calib),
	ADDR_RFIC_SPARE_VERSION_FOR_CALIB_E2P = ADDR_RFIC_VERSION_E2P + offsetof(struct eeprom_rfic_version, rfic_spare_version_calib),

	ADDR_FREQ_OFFSET_E2P = offsetof(struct eeprom, freq_offset),
	ADDR_AMBIENT_TEMP_E2P = offsetof(struct eeprom, ambient_temperature),

	ADDR_CALIB_24G_E2P = offsetof(struct eeprom, wifi_tx_power_calib_offfset),
	ADDR_CALIB_5G_E2P = ADDR_CALIB_24G_E2P +
			    MAX_ANTENNAS * MAX_POWER_LEVELS *  NUM_OF_PIVOTS(NL80211_BAND_2GHZ),
	ADDR_CALIB_6G_E2P = ADDR_CALIB_5G_E2P +
			    MAX_ANTENNAS * MAX_POWER_LEVELS * NUM_OF_PIVOTS(NL80211_BAND_5GHZ),
	ADDR_WIFI_VAL_PL0_E2P = offsetof(struct eeprom, wifi_value_pl_idx),

	ADDR_TEMP_24G_E2P = offsetof(struct eeprom, wifi_tx_power_calib_temperature),
	ADDR_TEMP_5G_E2P = ADDR_TEMP_24G_E2P +
			    MAX_ANTENNAS * MAX_POWER_LEVELS *  NUM_OF_PIVOTS(NL80211_BAND_2GHZ),
	ADDR_TEMP_6G_E2P = ADDR_TEMP_5G_E2P +
			    MAX_ANTENNAS * MAX_POWER_LEVELS * NUM_OF_PIVOTS(NL80211_BAND_5GHZ),


	SIZE_MODULE_HW_TYPE_E2P = ADDR_MODULE_HW_REVID_E2P - ADDR_MODULE_HW_TYPE_E2P,
	SIZE_MODULE_HW_REVID_E2P = ADDR_OTP_E2P_FORMAT_VERSION_E2P - ADDR_MODULE_HW_REVID_E2P,

	SIZE_RFIC_WIFI_VERSION_FOR_CALIB_E2P = ADDR_RFIC_BT_VERSION_FOR_CALIB_E2P - ADDR_RFIC_WIFI_VERSION_FOR_CALIB_E2P,
	SIZE_RFIC_BT_VERSION_FOR_CALIB_E2P = ADDR_RFIC_LUT_VERSION_FOR_CALIB_E2P - ADDR_RFIC_BT_VERSION_FOR_CALIB_E2P,
	SIZE_RFIC_LUT_VERSION_FOR_CALIB_E2P = ADDR_RFIC_SPARE_VERSION_FOR_CALIB_E2P - ADDR_RFIC_LUT_VERSION_FOR_CALIB_E2P,

	SIZE_FREQ_OFFSET_E2P = ADDR_AMBIENT_TEMP_E2P - ADDR_FREQ_OFFSET_E2P,
	SIZE_DELTA_CALIB_TO_TEMP = ADDR_TEMP_24G_E2P - ADDR_CALIB_24G_E2P,

	EEPROM_NUM_BYTES = sizeof(struct eeprom),
	EEPROM_LAST_BYTE = EEPROM_NUM_BYTES - 1,
};


enum cl_e2p_cmd {
	CL_E2P_GET_ADDR,
	CL_E2P_GET_POWER_LEVEL,
	CL_E2P_GET_FREQ_OFFSET,
	CL_E2P_GET_MODULE_HW_TYPE,
	CL_E2P_GET_MODULE_HW_REVID,
	CL_E2P_GET_RFIC_WIFI_VERSION_FOR_CALIB,
	CL_E2P_GET_RFIC_BT_VERSION_FOR_CALIB,
	CL_E2P_GET_RFIC_LUT_VERSION_FOR_CALIB,
	CL_E2P_GET_TABLE,
	CL_E2P_GET_CALIB,

	CL_E2P_SET_ADDR,
	CL_E2P_SET_POWER_LEVEL,
	CL_E2P_SET_FREQ_OFFSET,
	CL_E2P_SET_MODULE_HW_REVID,
	CL_E2P_SET_RFIC_WIFI_VERSION_FOR_CALIB,
	CL_E2P_SET_RFIC_BT_VERSION_FOR_CALIB,
	CL_E2P_SET_RFIC_LUT_VERSION_FOR_CALIB,
	CL_E2P_SET_MODULE_HW_TYPE,
	CL_E2P_SET_CALIB,

	CL_E2P_MAX
};
#endif // __E2P_H


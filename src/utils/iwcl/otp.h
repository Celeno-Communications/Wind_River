#ifndef __OTP_H
#define __OTP_H

#include "iwcl.h"

// All the below must be aligned with kernel

struct cl_otp_get_reply {
	uint8_t otp_mode;
	uint8_t otp_data[];
};

struct otp_booter {
	uint8_t start_pattern[2];
	uint8_t address[3];
	uint8_t data_vendor_id[2];
	uint8_t data_device_id[2];
	uint8_t address_jtag_mode[3];
	uint8_t jtag_mode_data[4];
	uint8_t address_combo_phy[3];
	uint8_t disable_ssc[4];
	uint8_t end_pattern[2];
	uint8_t reserved[39];
} __attribute__((__packed__));

struct otp_sw_mode {
	uint8_t version_id[4];
	uint8_t hw_metal_fix_id[4];
	uint8_t reserved[12];
} __attribute__((__packed__));

struct otp_security_configuration {
	uint8_t security_enabled[4];
	uint8_t security_AES_key_owner_bitmap[1];
	uint8_t security_ECC_key_owner_bitmap[1];
	uint8_t alignment[2];
} __attribute__((__packed__));

struct otp_security_keys {
	uint8_t aes_key0[32];
	uint8_t aes_key1[32];
	uint8_t aes_key2[32];
	uint8_t aes_key3[32];
	uint8_t ecc_key0[52];
	uint8_t ecc_key1[52];
	uint8_t ecc_key2[52];
	uint8_t ecc_key3[52];
} __attribute__((__packed__));

struct otp_security_keys_control {
	uint8_t aes_key0_revoke[4];
	uint8_t aes_key1_revoke[4];
	uint8_t aes_key2_revoke[4];
	uint8_t aes_key3_revoke[4];
	uint8_t ecc_key0_revoke[4];
	uint8_t ecc_key1_revoke[4];
	uint8_t ecc_key2_revoke[4];
	uint8_t ecc_key3_revoke[4];
} __attribute__((__packed__));

struct otp_security_min_version_enforcement {
	uint8_t min_fw_revision_0[4];
	uint8_t min_fw_revision_1[4];
	uint8_t min_fw_revision_2[4];
	uint8_t min_fw_revision_3[4];
} __attribute__((__packed__));

struct otp_wifi_tx_power_module_offset {
	uint8_t wifi_module_offset_ch0_2_4G;
	uint8_t wifi_module_offset_ch1_2_4G;
	uint8_t wifi_module_offset_ch0_5_7G;
	uint8_t wifi_module_offset_ch1_5_7G;
} __attribute__((__packed__));

struct otp_bt_tx_power_module_offset {
	uint8_t BT_tx_power_module_offset;
	uint8_t BT_tx_power[3];
} __attribute__((__packed__));

struct otp_module_hw {
	uint8_t module_hw_type;
	uint8_t module_hw_rev_id_major;
	uint8_t module_hw_rev_id_minor;
	uint8_t otp_eeprom_format;
} __attribute__((__packed__));

struct otp_rfic_version {
	uint8_t rfic_wifi_version_calib[2];
	uint8_t rfic_bt_version_calib[2];
	uint8_t rfic_lut_version_calib;
	uint8_t rfic_spare_version_calib;
} __attribute__((__packed__));

struct otp_die_id {
	uint8_t test_revision_minor[2];
	uint8_t test_revision_major[2];
	uint8_t column;
	uint8_t row;
	uint8_t wafer;
	uint8_t lot_character_5;
	uint8_t lot_character_4;
	uint8_t lot_character_3;
	uint8_t lot_character_2;
	uint8_t lot_character_1;
} __attribute__((__packed__));

struct otp {
	struct otp_booter booter;
	uint8_t pn[4];
	uint8_t mac_address[6];
	uint8_t mac_padding[2];
	uint8_t bd_address[6];
	uint8_t bd_padding[2];
	struct otp_sw_mode sw_mode;
	struct otp_security_configuration security_configuration;
	struct otp_security_keys security_keys;
	struct otp_security_keys_control security_keys_control;
	struct otp_security_min_version_enforcement security_min_version_enforcement;
	struct otp_wifi_tx_power_module_offset wifi_tx_power_module_offset;
	struct otp_bt_tx_power_module_offset bt_tx_power_module_offset;
	struct otp_module_hw module_hw;
	struct otp_rfic_version rfic_version;
	uint8_t reserved_version[2];
	uint16_t freq_offset;
	uint8_t reserved_freq_offset[2];
	uint8_t ambient_temperature[4];
	uint8_t bt_tx_power_calib_offset[16];
	uint8_t wifi_tx_power_calib_offfset[120];
	uint8_t wifi_value_pl_idx[4];
	uint8_t bt_power_calib_temp[6];
	uint8_t bt_reserved[2];
	uint8_t wifi_power_calib_temp[60];
	uint8_t reserved[24];
	struct otp_die_id die_id;
	uint8_t mbist[256];
} __attribute__((__packed__));


enum {
	ADDR_BOOTER_OTP = offsetof(struct otp, booter),
	ADDR_DEVICE_ID_OTP = ADDR_BOOTER_OTP + offsetof(struct otp_booter, data_device_id),
	ADDR_JTAG_MODE_OTP = ADDR_BOOTER_OTP + offsetof(struct otp_booter, address_jtag_mode),

	ADDR_MAC_ADDR_OTP = offsetof(struct otp, mac_address),
	ADDR_PADDING_OTP = offsetof(struct otp, mac_padding),

	ADDR_MODULE_HW_VERSION_OTP = offsetof(struct otp, module_hw),
	ADDR_MODULE_HW_TYPE_OTP = ADDR_MODULE_HW_VERSION_OTP + offsetof(struct otp_module_hw, module_hw_type),
	ADDR_MODULE_HW_REVID_OTP = ADDR_MODULE_HW_VERSION_OTP + offsetof(struct otp_module_hw, module_hw_rev_id_major),
	ADDR_OTP_E2P_FORMAT_VERSION_OTP = ADDR_MODULE_HW_VERSION_OTP + offsetof(struct otp_module_hw, otp_eeprom_format),

	ADDR_RFIC_VERSION_OTP = offsetof(struct otp, rfic_version),
	ADDR_RFIC_WIFI_VERSION_FOR_CALIB_OTP = ADDR_RFIC_VERSION_OTP + offsetof(struct otp_rfic_version, rfic_wifi_version_calib),
	ADDR_RFIC_BT_VERSION_FOR_CALIB_OTP = ADDR_RFIC_VERSION_OTP + offsetof(struct otp_rfic_version, rfic_bt_version_calib),
	ADDR_RFIC_LUT_VERSION_FOR_CALIB_OTP = ADDR_RFIC_VERSION_OTP + offsetof(struct otp_rfic_version, rfic_lut_version_calib),
	ADDR_RFIC_SPARE_VERSION_FOR_CALIB_OTP = ADDR_RFIC_VERSION_OTP + offsetof(struct otp_rfic_version, rfic_spare_version_calib),

	ADDR_FREQ_OFFSET_OTP = offsetof(struct otp, freq_offset),
	ADDR_AMBIENT_TEMP_OTP = offsetof(struct otp, ambient_temperature),
	ADDR_CALIB_24G_OTP = offsetof(struct otp, wifi_tx_power_calib_offfset),
	ADDR_WIFI_VAL_PL0_OTP = offsetof(struct otp, wifi_value_pl_idx),
	OTP_NUM_BYTES = sizeof(struct otp),
	OTP_LAST_BYTE = OTP_NUM_BYTES - 1,

	SIZE_DEVICE_ID_OTP = ADDR_JTAG_MODE_OTP - ADDR_DEVICE_ID_OTP,

	SIZE_MAC_ADDR_OTP = ADDR_PADDING_OTP - ADDR_MAC_ADDR_OTP,

	SIZE_MODULE_HW_TYPE_OTP = ADDR_MODULE_HW_REVID_OTP - ADDR_MODULE_HW_TYPE_OTP,
	SIZE_MODULE_HW_REVID_OTP = ADDR_OTP_E2P_FORMAT_VERSION_OTP - ADDR_MODULE_HW_REVID_OTP,

	SIZE_RFIC_WIFI_VERSION_FOR_CALIB_OTP = ADDR_RFIC_BT_VERSION_FOR_CALIB_OTP - ADDR_RFIC_WIFI_VERSION_FOR_CALIB_OTP,
	SIZE_RFIC_BT_VERSION_FOR_CALIB_OTP = ADDR_RFIC_LUT_VERSION_FOR_CALIB_OTP - ADDR_RFIC_BT_VERSION_FOR_CALIB_OTP,
	SIZE_RFIC_LUT_VERSION_FOR_CALIB_OTP = ADDR_RFIC_SPARE_VERSION_FOR_CALIB_OTP - ADDR_RFIC_LUT_VERSION_FOR_CALIB_OTP,

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

#endif // __OTP_H
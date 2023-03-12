/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_E2P_H
#define CL_E2P_H

#include <linux/types.h>
#include <net/cfg80211.h>
#include "chip.h"
#include "cl_eeprom.h"

struct cl_e2p_get_reply {
	u8 e2p_en;
	u8 e2p_data[];
};

int cl_e2p_init(struct cl_chip *chip);
int cl_e2p_write(struct cl_chip *chip, u8 *data, u16 size, u16 addr);
int cl_e2p_read(struct cl_chip *chip, u8 *data, u16 size, u16 addr);
int cl_e2p_get_addr(struct wiphy *wiphy, struct wireless_dev *wdev,
		    void *data, int data_len);
int cl_e2p_set_addr(struct wiphy *wiphy, struct wireless_dev *wdev,
		    const void *data, int data_len);
int cl_e2p_set_module_hw_type(struct wiphy *wiphy, struct wireless_dev *wdev,
			      const void *data, int data_len);
int cl_e2p_help(struct wiphy *wiphy, struct wireless_dev *wdev,
		void *data, int data_len);

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

#endif /* CL_E2P_H */

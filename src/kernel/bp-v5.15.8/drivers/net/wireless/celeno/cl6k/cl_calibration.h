/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_CALIBRATION_H
#define CL_CALIBRATION_H

#include "cl_hw.h"

#define UNCALIBRATED_TEMPERATURE   35
#define UNCALIBRATED_PDI_E2P       0xFF
#define UNCALIBRATED_PDI_OTP       0
#define UNCALIBRATED_POWER_OFFSET  0

enum calib_dc_type {
	DC_IP,
	DC_IN,
	DC_QP,
	DC_QN,
	DC_TYPE_MAX,
};

int idx_chan_from_otp_idx(struct cl_hw *cl_hw, u8 otp_idx);
s8 cl_calibration_pdi_to_power_offset(s8 pdi);
u16 cl_calibration_start_addr(u8 band, bool is_e2p);
int cl_calibration_get_calib(struct wiphy *wiphy, struct wireless_dev *wdev,
			     const void *data, int data_len, bool is_otp);
int cl_calibration_set_calib(struct wiphy *wiphy, struct wireless_dev *wdev,
			     const void *data, int data_len, bool is_otp);

void cl_calibration_power_read(struct cl_hw *cl_hw);
void cl_calibration_power_offset_fill(struct cl_hw *cl_hw, u8 channel,
				      u8 bw, u8 offset[MAX_ANTENNAS]);


#endif /* CL_CALIBRATION_H */

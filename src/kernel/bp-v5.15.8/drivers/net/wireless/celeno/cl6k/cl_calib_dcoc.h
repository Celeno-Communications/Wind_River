/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_CALIB_DCOC_H
#define CL_CALIB_DCOC_H

#define VERSION_ID_DCOC 2

#define CALIB_CHAN_5G_PLAN 6
#define CALIB_CHAN_6G_PLAN 15

extern const u8 calib_channels_24g[CALIB_CHAN_24G_MAX];
extern const u8 calib_channels_5g_plan[CALIB_CHAN_5G_PLAN];
extern const u8 calib_channels_6g_plan[CALIB_CHAN_6G_PLAN];

void cl_calib_dcoc_init_calibration(struct cl_hw *cl_hw);
int cl_calib_dcoc_post_read_actions(struct cl_chip *chip, char *buf);
void cl_calib_dcoc_parse_str(struct cl_chip *chip, char *str, enum calib_files_idx file_idx);
void cl_calib_bt_dcoc_parse_str(struct cl_chip *chip, char *str,
				enum calib_files_idx file_idx);
u8 cl_calib_dcoc_channel_bw_to_idx(struct cl_hw *cl_hw, u8 channel, u8 bw);
void cl_calib_dcoc_fill_data(struct cl_hw *cl_hw, struct cl_iq_dcoc_info *iq_dcoc_db,
			     bool is_calib);
u8 cl_calib_dcoc_tcv_channel_to_idx(struct cl_chip *chip, u8 band, u8 channel, u8 bw);
void cl_calib_wifi_dcoc_handle_set_calib_cfm(struct cl_hw *cl_hw);
void cl_calib_bt_dcoc_handle_set_calib_cfm(struct cl_hw *cl_hw);
int cl_calib_dcoc_write_version(struct cl_hw *cl_hw);
int cl_calib_bt_dcoc_write_version(struct cl_hw *cl_hw);
int cl_calib_dcoc_report_write_version(struct cl_hw *cl_hw);
int cl_calib_bt_dcoc_report_write_version(struct cl_hw *cl_hw);
int cl_calib_dcoc_write_file(struct cl_hw *cl_hw, s32 *params);
int cl_calib_bt_dcoc_write_file(struct cl_hw *cl_hw, s32 *params);
int cl_calib_bt_dcoc_report_write_file(struct cl_hw *cl_hw, s32 *params);
int cl_calib_dcoc_report_write_file(struct cl_hw *cl_hw, s32 *params);
int cl_calib_dcoc_init_calibration_channel(struct cl_hw *cl_hw);

#endif /* CL_CALIB_DCOC_H */

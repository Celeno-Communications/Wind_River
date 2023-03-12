/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_CALIB_COMMON_API_H
#define CL_CALIB_COMMON_API_H

#include "def.h"
#include "cl_math.h"
#include "cl_vendor_cmd.h"

struct cl_hw;
struct cl_chip;
struct mm_set_phy_data_req;

/* should be the exact define wifi_calib_mode_bmp_e
 * as in rfic_calib_api.h and phy.h
 */
#define WIFI_CALIB_MODE_NONE        0
#define WIFI_CALIB_MODE_RX_DCOC     0x01
#define WIFI_CALIB_MODE_TX_LO       0x02
#define WIFI_CALIB_MODE_RX_GAIN     0x04
#define WIFI_CALIB_MODE_TX_IQ       0x08
#define WIFI_CALIB_MODE_RX_IQ       0x10
#define WIFI_CALIB_MODE_RX_GAIN_DPD 0x20
#define WIFI_CALIB_MODE_RX_IQ_DPD   0x40
#define WIFI_CALIB_MODE_TX_IQ_DPD   0x80

#define BT_CALIB_MODE_NONE        0
#define BT_CALIB_MODE_RX_DCOC       0x1
#define BT_CALIB_MODE_TX_LO         0x2
#define BT_CALIB_MODE_RX_GAIN       0x4
#define BT_CALIB_MODE_TX_IQ         0x8
#define BT_CALIB_MODE_RX_IQ         0x10

#define SET_CALIB_MODE  (WIFI_CALIB_MODE_RX_DCOC |   \
				WIFI_CALIB_MODE_TX_LO |   \
				WIFI_CALIB_MODE_RX_GAIN | \
				WIFI_CALIB_MODE_TX_IQ |  \
				WIFI_CALIB_MODE_RX_IQ |  \
				WIFI_CALIB_MODE_RX_GAIN_DPD |  \
				WIFI_CALIB_MODE_RX_IQ_DPD |  \
				WIFI_CALIB_MODE_TX_IQ_DPD)

#define SET_CALIB_MODE_BT  (BT_CALIB_MODE_RX_DCOC | \
			    BT_CALIB_MODE_TX_LO   | \
			    BT_CALIB_MODE_RX_GAIN | \
			    BT_CALIB_MODE_TX_IQ   | \
			    BT_CALIB_MODE_RX_IQ)

#define SET_CALIB_MODE_IQ_ALL (WIFI_CALIB_MODE_TX_IQ | \
			       WIFI_CALIB_MODE_RX_IQ)

#define SET_CALIB_MODE_TX_ALL (WIFI_CALIB_MODE_TX_IQ | \
			       WIFI_CALIB_MODE_TX_IQ_DPD | \
			       WIFI_CALIB_MODE_TX_LO | \
				   WIFI_CALIB_MODE_RX_GAIN)

#define SET_CALIB_MODE_RX_ALL (WIFI_CALIB_MODE_RX_IQ | \
			       WIFI_CALIB_MODE_RX_IQ_DPD | \
			       WIFI_CALIB_MODE_RX_GAIN_DPD)
/* DCOC/IQ Calibration related defines */
#define CALIB_SUCCESS 0x00
#define CALIB_FAIL    0x01

#define BT_FILTER_BW_MHZ_TO_IDX(mhz) ((mhz) - 1)
#define BT_FILTER_BW_IDX_TO_MHZ(idx) ((idx) + 1)

enum calib_type_index {
	WIFI_RX_CALIBRATION_TYPE_DCOC_CH0_CH1_SX0_IDX = 0,
	WIFI_RX_CALIBRATION_TYPE_DCOC_CH0_CH1_SX1_IDX,
	WIFI_TX_CALIBRATION_TYPE_GAIN_LO_IQ_CH0_IDX,
	WIFI_TX_CALIBRATION_TYPE_GAIN_LO_IQ_CH1_IDX,
	WIFI_RX_CALIBRATION_TYPE_GAIN_IQ_CH0_IDX,
	WIFI_RX_CALIBRATION_TYPE_GAIN_IQ_CH1_IDX,
	WIFI_TX_CALIBRATION_TYPE_GAIN_DPD_IQ_DPD_DPD_CH0_IDX,
	WIFI_TX_CALIBRATION_TYPE_GAIN_DPD_IQ_DPD_DPD_CH1_IDX,
	WIFI_CALIBRATION_MAX_TYPE_NUM,
	BT_CALIBRATION_START_IDX = WIFI_CALIBRATION_MAX_TYPE_NUM,
	BT_RX_CALIBRATION_TYPE_DCOC_CH2_IDX = BT_CALIBRATION_START_IDX,
	BT_TX_CALIBRATION_TYPE_GAIN_LO_IQ_CH2_IDX,
	BT_RX_CALIBRATION_TYPE_GAIN_IQ_CH2_IDX,
	BT_CALIBRATION_MAX_TYPE_NUM,
	CALIBRATION_MAX_TYPE_NUM = BT_CALIBRATION_MAX_TYPE_NUM,
};

enum cl_calib_flags {
	CALIB_FLAG_CREATE = 1 << 0,
	CALIB_FLAG_VERSION = 1 << 1,
	CALIB_FLAG_TITLE = 1 << 2,
	CALIB_FLAG_HEADER_TCV0 = 1 << 3,

	CALIB_FLAG_ALL_REPORT = (CALIB_FLAG_CREATE |
				 CALIB_FLAG_VERSION |
				 CALIB_FLAG_TITLE),
	CALIB_FLAG_ALL = (CALIB_FLAG_CREATE |
			  CALIB_FLAG_VERSION |
			  CALIB_FLAG_TITLE |
			  CALIB_FLAG_HEADER_TCV0)
};

int cl_calib_db_alloc(struct cl_hw *cl_hw);
void cl_calib_db_free(struct cl_hw *cl_hw);
void cl_calib_common_start_work(struct cl_hw *cl_hw);
int cl_calib_common_write_error(struct cl_hw *cl_hw, char *file_prefix, u16 num_errors);
void cl_calib_common_fill_phy_data(struct cl_hw *cl_hw, struct cl_iq_dcoc_info *iq_dcoc_db,
				   u8 flags, bool is_calib);
char *cl_calib_common_non_empty_strsep(char **str, const char *delims);
int cl_calib_common_tables_alloc(struct cl_hw *cl_hw);
void cl_calib_common_tables_free(struct cl_hw *cl_hw);
int cl_calib_common_read_files(struct cl_chip *chip);
int cl_calib_common_write_version(struct cl_hw *cl_hw, u8 *calib_flags, char *file_prefix,
				  char *title, u32 version_id);
int cl_calib_common_handle_set_channel_cfm(struct cl_hw *cl_hw,
					   struct cl_calib_params calib_params);
int cl_calib_common_handle_set_calib_cfm(struct cl_hw *cl_hw);
void cl_calib_common_handle_matlab_calib_req(struct cl_hw *cl_hw, u16 file_len);
void cl_calib_common_remove_tcv_entries(struct cl_hw *cl_hw, enum calib_files_idx file_idx,
					u8 num_calib_ant);
int cl_calib_common_check_errors(struct cl_hw *cl_hw);
int cl_calib_common_cli(struct cl_hw *cl_hw, struct cli_params *cli_params);
void cl_calib_common_write_hr_factor(struct cl_hw *cl_hw, char *buf, int *len, int size);
s16 cl_calib_common_get_temperature(struct cl_hw *cl_hw, u8 cfm_type);
void cl_calib_params_fill(struct cl_calib_params *params,
			  u8 wifi_mode_bitmap,
			  u8 bt_mode_bitmap,
			  u8 band,
			  u8 channel,
			  u8 wifi_bw,
			  bool first_channel,
			  s8 sx_freq_off,
			  u8 wifi_chain_bitmap,
			  u8 dcoc_sx_bmp,
			  bool is_matlab,
			  u8 bt_bw_bitmap,
			  bool is_sys_flow);
#endif /* CL_CALIB_COMMON_API_H */

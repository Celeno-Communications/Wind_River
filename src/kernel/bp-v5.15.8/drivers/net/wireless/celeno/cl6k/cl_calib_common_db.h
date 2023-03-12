/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_CALIB_COMMON_DB_H
#define CL_CALIB_COMMON_DB_H

#include "def.h"
#include "cl_math.h"
#include "calib_db.h"

#define CALIB_MAX_BUF           256
#define CALIB_MAX_HEADER_FOOTER 64
#define CALIB_MAX_HR_FACTOR_LEN 10

#define CL_MAX_TEMPERATURE    120
#define MAX_CALIB_LINE_LENGTH 256
#define IQ_NUM_TONES_REQ      8
#define IQ_NUM_TONES_CFM      (2 * IQ_NUM_TONES_REQ)
#define SINGLETONS_MAX_NUM    1
#define LOOPS_MAX_NUM         (2 + SINGLETONS_MAX_NUM)

#define SX_FREQ_OFFSET_Q2 5

#define ETH_IP_ADDR_CHAR_LEN 16

enum calib_platform {
	CALIB_PLATFORM_WIFI,
	CALIB_PLATFORM_BT,
	CALIB_PLATFORM_MAX
};

enum calib_cfm_id_type {
	CALIB_CFM_WIFI_DCOC,
	CALIB_CFM_WIFI_IQ,
	CALIB_CFM_BT_DCOC,
	CALIB_CFM_BT_IQ,
	CALIB_CFM_MAX
};

enum params_dcoc_type {
	DCOC_CHANNEL,
	DCOC_BW,
	DCOC_CHAIN,
	DCOC_BAND,
	DCOC_LNA,
	DCOC_TEMPERATURE,
	DCOC_I,
	DCOC_Q,
	DCOC_PARAM_MAX,
};

enum params_dcoc_report_type {
	DCOC_REPORT_CHANNEL,
	DCOC_REPORT_BW,
	DCOC_REPORT_CHAIN,
	DCOC_REPORT_BAND,
	DCOC_REPORT_LNA,
	DCOC_REPORT_TEMPERATURE,
	DCOC_REPORT_I_MV,
	DCOC_REPORT_I_ITERATIONS,
	DCOC_REPORT_Q_MV,
	DCOC_REPORT_Q_ITERATIONS,
	DCOC_REPORT_PARAM_MAX,
};

enum params_lolc_type {
	LOLC_CHANNEL,
	LOLC_BW,
	LOLC_ANTENNA,
	LOLC_BAND,
	LOLC_TEMPERATURE,
	LOLC_I,
	LOLC_Q,
	LOLC_PARAM_MAX,
};

enum params_matlab_calib_req {
	MATLAB_PLATFORM,
	MATLAB_CHANNEL,
	MATLAB_BW,
	MATLAB_CALIB_MODE,
	MATLAB_SX_OFFSET,
	MATLAB_CHAIN_BITMAP,
	MATLAB_DCOC_SX_BITMAP,
	MATLAB_CALIB_REQ_PARAM_MAX,
};

enum params_dpd_matlab_calib_req {
	DPD_MATLAB_FRAME_TYPE,
	DPD_MATLAB_FRAME_BW,
	DPD_MATLAB_FRAME_MCS,
	DPD_MATLAB_TX_CHAIN_IDX,
	DPD_MATLAB_CALIB_REQ_PARAM_MAX,
};

enum params_matlab_calib_res {
	MATLAB_LEN,
	MATLAB_CALIB_RES_PARAM_MAX,
};

#define MAX_MATLAB_CALIB_DATA_LEN 512

enum mm_matlab_calib_command {
	MM_MATLAB_CALIB_RES_LEN_IDX,
	/* MM_MATLAB_CALIB_RES_DATA_IDX is the index of the first
	 * data value in Matlab response msg which been read from response file
	 */
	MM_MATLAB_CALIB_RES_DATA_IDX = (MM_MATLAB_CALIB_RES_LEN_IDX + 4),
};

struct mm_matlab_calib_res {
	u8 data[MAX_MATLAB_CALIB_DATA_LEN];
};

struct mm_riu_loopback_config_req {
	u8 rx_chain_id;
	u8 tx_chain_id;
	u8 bw;
};

struct cl_matlab_calib_params {
	u8 data[MAX_MATLAB_CALIB_DATA_LEN];
};

struct mm_matlab_calib_req {
	u16 file_len;
};

enum params_lolc_report_type {
	LOLC_REPORT_CHANNEL,
	LOLC_REPORT_BW,
	LOLC_REPORT_ANTENNA,
	LOLC_REPORT_BAND,
	LOLC_REPORT_TEMPERATURE,
	LOLC_REPORT_ITERATIONS,
	LOLC_REPORT_QUAL_DB,
	LOLC_REPORT_PARAM_MAX,
};

enum calib_files_idx {
	WIFI_DCOC_FILE,
	BT_DCOC_FILE,
	LOLC_FILE,
	IQ_TX_FILE,
	IQ_RX_FILE,
	DCOC_REPORT_FILE,
	BT_DCOC_REPORT_FILE,
	LOLC_REPORT_FILE,
	IQ_TX_REPORT_FILE,
	IQ_RX_REPORT_FILE,
	RGC_REPORT_FILE,
	CALIB_IQ_PLAN,
};

struct cl_dcoc_report {
	__le16 i_dc;
	__le16 i_iterations;
	__le16 q_dc;
	__le16 q_iterations;
};

struct cl_iq_report {
	u8 status;
	s8 ir_db[LOOPS_MAX_NUM][IQ_NUM_TONES_CFM];
	s16 ir_db_avg_pre;
	s8 ir_db_avg_post;
};

struct cl_lolc_report {
	u8 status;
	u8 n_iter;
	__le16 lolc_qual;
};

struct cl_gain_report {
	u8 status;
	__le16 rx_gain;
	u8 tx_gain;
	u8 gain_quality;
	__le16 final_p2p;
	__le16 initial_p2p;
};

/* Must be the same as the MAC struct dcoc_iq_info */
struct cl_iq_dcoc_info {
	struct cl_dcoc_calib dcoc[DCOC_LNA_GAIN_NUM][MAX_ANTENNAS];
	struct cl_dcoc_calib bt_dcoc[MAX_NUM_BT_CHANNELS_CALIB]
				    [BT_FILTER_BW_MAX][BT_DCOC_LNA_GAIN_NUM];
	struct cl_iq_calib iq_tx[MAX_ANTENNAS];
	__le32 iq_tx_lolc[MAX_ANTENNAS];
	struct cl_iq_calib iq_rx[MAX_ANTENNAS];
};

struct cl_iq_dcoc_report {
	struct cl_dcoc_report dcoc[DCOC_LNA_GAIN_NUM][MAX_ANTENNAS];
	struct cl_dcoc_report bt_dcoc[MAX_NUM_BT_CHANNELS_CALIB]
				     [BT_FILTER_BW_MAX][BT_DCOC_LNA_GAIN_NUM];
	struct cl_gain_report gain_tx[MAX_ANTENNAS];
	struct cl_gain_report gain_rx[MAX_ANTENNAS];
	struct cl_lolc_report lolc_report[MAX_ANTENNAS];
	struct cl_iq_report iq_tx[MAX_ANTENNAS];
	struct cl_iq_report iq_rx[MAX_ANTENNAS];
};

struct calib_cfm {
	u8 status;
	__le16 raw_bits_data_0;
	__le16 raw_bits_data_1;
};

/* Identicle to drivers cl_iq_dcoc_data MAC structure iq_and_dcoc_data */
struct cl_iq_dcoc_data {
	struct calib_cfm dcoc_iq_cfm[CALIB_CFM_MAX];
	struct cl_iq_dcoc_report report;
	struct cl_iq_dcoc_info iq_dcoc_db;
	struct cl_matlab_calib_params matlab_params;
};

struct cl_iq_dcoc_data_info {
	struct cl_iq_dcoc_data *iq_dcoc_data;
	u32 dma_addr;
};

/* Input calib params */
struct cl_calib_params {
	u8 wifi_mode_bmp;
	u8 bt_mode_bmp;
	u8 channel;
	u8 band;
	u8 wifi_bw;
	u8 bt_bw_bmp;
	bool first_channel;
	s8 sx_freq_offset_mhz;
	u8 wifi_chain_bmp;
	u8 dcoc_sx_bmp;
	bool is_matlab;
	bool is_sys_flow;
};

struct cl_calib_chain {
	u8 pair;
	u8 initial_tx_gain;
	u8 initial_rx_gain;
};

struct cl_calib_iq_plan_chain {
	bool occupy;
	struct cl_calib_chain calib_chain;
};

struct cl_calib_iq_plan {
	struct list_head list;
	u32 channel;
	s8 sx_diff;
	struct cl_calib_iq_plan_chain tx_chain[MAX_ANTENNAS];
	struct cl_calib_iq_plan_chain rx_chain[MAX_ANTENNAS];
};

#define SET_PHY_DATA_FLAGS_DCOC       0x1 /* Set DCOC calibration data.*/
#define SET_PHY_DATA_FLAGS_IQ_TX      0x2 /* Set IQ Tx calibration data.*/
#define SET_PHY_DATA_FLAGS_IQ_RX      0x4 /* Set IQ Rx calibration data.*/
#define SET_PHY_DATA_FLAGS_IQ_TX_LOLC 0x8 /* Set IQ Tx LOLC calibration data.*/
#define SET_PHY_DATA_FLAGS_ALL ( \
	SET_PHY_DATA_FLAGS_DCOC | \
	SET_PHY_DATA_FLAGS_IQ_TX | \
	SET_PHY_DATA_FLAGS_IQ_RX | \
	SET_PHY_DATA_FLAGS_IQ_TX_LOLC)
#define SET_PHY_DATA_FLAGS_LISTENER ( \
	SET_PHY_DATA_FLAGS_DCOC | \
	SET_PHY_DATA_FLAGS_IQ_RX)

#define CL_CALIB_PARAMS_DEFAULT_STRUCT \
	((struct cl_calib_params){0, 0, 0, 0, 0, 0, 0, false})

#define riu_chain_for_each(_chain) \
	for (_chain = cl_hw->first_riu_chain; _chain <= cl_hw->last_riu_chain; _chain++)

#endif

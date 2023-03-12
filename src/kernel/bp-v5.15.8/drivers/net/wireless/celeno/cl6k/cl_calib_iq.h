/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_CALIB_IQ_H
#define CL_CALIB_IQ_H

#define CALIB_TX_GAIN_DEFAULT        (0x75)
#define GAIN_SLEEVE_TRSHLD_DEFAULT   (2)
#define CALIB_NCO_AMP_DEFAULT        (-10)
/* 5M/312.5K for LO & RGC */
#define CALIB_NCO_FREQ_DEFAULT       (16)
#define LO_P_THRESH                  (1000000)
#define N_SAMPLES_EXP_LOLC           (13)
#define N_SAMPLES_EXP_IQC            (13)
#define N_BIT_FIR_SCALE              (11)
#define N_BIT_AMP_SCALE              (10)
#define N_BIT_PHASE_SCALE            (10)
/* Represents 0.2 degree in Q(16,16): 0.2*(pi/180) */
#define GP_RAD_TRSHLD_DEFAULT        (229)
/* Represents 0.05 db in Q(16,16): 10^( 0.05/20)*2^16 */
#define GA_LIN_UPPER_TRSHLD_DEFAULT  (65915)
/* Represents -0.05 db in Q(16,16): 10^(-0.05/20)*2^16 */
#define GA_LIN_LOWER_TRSHLD_DEFAULT  (65160)
#define COMP_FILTER_LEN_DEFAULT      (11)
/* Set to SINGLETONS_MAX_NUM for now */
#define SINGLETONS_NUM_DEFAULT       (10)
#define IQ_PRE_IDX                   (0)
#define IQ_SINGLETON_IDX             (1)
#define IQ_POST_IDX                  (LOOPS_MAX_NUM - 1)
#define RAMPUP_TIME                  (50)
#define LO_COARSE_STEP               (20)
#define LO_FINE_STEP                 (1)

#define DCOC_MAX_VGA                      0x14
#define CALIB_RX_GAIN_DEFAULT             0x83
#define CALIB_RX_GAIN_UPPER_LIMIT         0x14
#define CALIB_RX_GAIN_LOWER_LIMIT         0x0
#define DCOC_MAX_VGA_ATHOS                0x1E
#define CALIB_RX_GAIN_DEFAULT_ATHOS       0x8D
#define CALIB_RX_GAIN_UPPER_LIMIT_ATHOS   0x1E
#define CALIB_RX_GAIN_LOWER_LIMIT_ATHOS   0x0A
#define DCOC_MAX_VGA_ATHOS_B              0x14
#define CALIB_RX_GAIN_DEFAULT_ATHOS_B     0x81
#define CALIB_RX_GAIN_UPPER_LIMIT_ATHOS_B 0x14
#define CALIB_RX_GAIN_LOWER_LIMIT_ATHOS_B 0x0

#define INVALID_CALIB_RX_GAIN 0xff

struct cl_calib_iq_restore {
	u8 bw;
	u32 primary;
	u32 center;
	u8 channel;
};

bool cl_calib_iq_calibration_needed(struct cl_hw *cl_hw);
void cl_calib_iq_file_flags_clear(struct cl_chip *chip);
void cl_calib_iq_file_flags_set(struct cl_chip *chip);
int cl_calib_iq_post_read_actions(struct cl_chip *chip, char *buf);
void cl_calib_iq_init_calibration(struct cl_hw *cl_hw);
int cl_calib_iq_init_calibration_channel(struct cl_hw *cl_hw);
void cl_calib_iq_fill_data(struct cl_hw *cl_hw, struct cl_iq_calib *iq_data,
			   struct cl_iq_calib *iq_chip_data);
void cl_calib_iq_lolc_fill_data(struct cl_hw *cl_hw, __le32 *iq_lolc, bool is_calib);
void cl_calib_iq_parse_str(struct cl_chip *chip, char *str, enum calib_files_idx file_idx);
void cl_calib_iq_lolc_parse_str(struct cl_chip *chip, char *str, enum calib_files_idx file_idx);
void cl_calib_iq_plan_init(struct cl_chip *chip);
void cl_calib_iq_plan_deinit(struct cl_chip *chip);
void cl_calib_iq_plan_parse_str(struct cl_chip *chip, char *str, enum calib_files_idx file_idx);
void cl_calib_iq_tx_and_lolc_write_registers_to_file(struct cl_hw *cl_hw);
void cl_calib_iq_write_registers_to_file(struct cl_hw *cl_hw, enum calib_files_idx files_idx);
void cl_calib_iq_write_single_line_to_file(struct cl_hw *cl_hw, u8 iq_direction, u16 channel,
					   u8 bw, u8 ant, u8 sx, s16 temperature);
int cl_calib_iq_tx_write_version(struct cl_hw *cl_hw);
int cl_calib_iq_tx_report_write_version(struct cl_hw *cl_hw);
int cl_calib_iq_rx_write_version(struct cl_hw *cl_hw);
int cl_calib_iq_rx_report_write_version(struct cl_hw *cl_hw);
int cl_calib_iq_rx_gain_report_write_version(struct cl_hw *cl_hw);
void cl_calib_iq_rx_gain_write_report_file(struct cl_hw *cl_hw,
					   struct cl_calib_params *calib_params);
void cl_calib_iq_handle_set_calib_cfm(struct cl_hw *cl_hw, u8 plan_bitmap);
void cl_calib_iq_lolc_handle_set_channel_cfm(struct cl_hw *cl_hw, u8 plan_bitmap);
int cl_calib_iq_lolc_write_version(struct cl_hw *cl_hw);
int cl_calib_iq_lolc_report_write_version(struct cl_hw *cl_hw);
int cl_calib_iq_lolc_write_file(struct cl_hw *cl_hw, s32 *params);
int cl_calib_iq_lolc_report_write_file(struct cl_hw *cl_hw, s32 *params);
void cl_calib_iq_get_tone_vector(struct cl_hw *cl_hw, __le16 *tone_vector);
void cl_calib_iq_init_production(struct cl_hw *cl_hw);
int cl_calib_iq_set_idle(struct cl_hw *cl_hw, bool idle);
void cl_calib_restore_channel(struct cl_hw *cl_hw, struct cl_calib_iq_restore *iq_restore);
void cl_calib_save_channel(struct cl_hw *cl_hw, struct cl_calib_iq_restore *iq_restore);

#endif /* CL_CALIB_IQ_H */

/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_LCU_H
#define CL_LCU_H

#include <linux/types.h>
#include "lcu.h"

#define CAPTURE_MODE_END_BUFFER		0
#define CAPTURE_MODE_CYCLIC		1
#define LCU_CH0_CONF_SAMPLE_SIZE_NARROW	0
#define LCU_CH0_CONF_SAMPLE_SIZE_WIDE	1
#define CL_LCU_BUFFER_START_ADDRESS	0x60040000
#define CL_LCU_BUFFER_END_ADDRESS	0x60060000
#define CL_LCU_BUFFER_SIZE (CL_LCU_BUFFER_END_ADDRESS - CL_LCU_BUFFER_START_ADDRESS)

#define CONSECUTIVE_EQUAL_TH 3
#define FULL_BUFFER_HYST 100

enum cl_lcu_bt_mode {
	CL_LCU_TX_IQ_SAMPLES,
	CL_LCU_RX_IQ_SAMPLES_WO_CALIB,
	CL_LCU_RX_IQ_SAMPLES_WT_CALIB,
	CL_LCU_BT_MODE_MAX
};

enum cl_lcu_bt_trigger_mode {
	CL_LCU_EN_END_IW_CMD,
	CL_LCU_EN_RXTX_EN,
	CL_LCU_EN_RX_ADC_TX_PA_EN,
	CL_LCU_BT_TRIGGER_MAX
};

struct cl_lcu_bt_conf {
	u32 cont_modem_subch_en;
	u32 cont_subch_index_reg[2];
	u32 modem_subch_index_reg[2];
	u32 cont_ch_mask_index;
	u32 cont_ch_mask_reg[3];
	u32 modem_ch_mask_index;
	u32 modem_ch_mask_reg[3];
};

struct cl_hw;
struct cl_chip;
struct cli_params;

void cl_lcu_stop(struct cl_chip *chip);
void cl_lcu_apply_config(struct cl_chip *chip);
int cl_lcu_init(struct cl_chip *chip);
void cl_lcu_deinit(struct cl_chip *chip);
void cl_lcu_bt_config_get(struct cl_hw *cl_hw);
void cl_lcu_usbc_config_get(struct cl_hw *cl_hw);
int cl_lcu_cli(struct cl_hw *cl_hw, struct cli_params *cli_params,
	       char *ret_buf, u16 *ret_buf_len);

#endif /* CL_LCU_H */

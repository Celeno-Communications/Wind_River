/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_RFIC_H
#define CL_RFIC_H

#include "cl_hw.h"
#include "cl_vendor_cmd.h"

#define RX_BB_DCOC_MAX_VAL (BIT(5) - 1)
#define IQDC_TX_FIR_COEFF  BIT(9)
#define IQDC_TX_PHASE_GAIN BIT(11)
#define IQDC_TX_AMP_GAIN   BIT(11)
#define IQDC_TX_DC         BIT(12)

/*
 * Macros are used to generate function names
 * reg_coeff = _fir_coeff / 3
 * chain is antenna bitmap (2 bits)
 * freq is 1MHZ/ 2MHZ
 */

#define SET_IQDC_M_COEFF_TX(freq, reg_coeff, fir_coeff) \
rfic_wrap_iqdc_tx_ ## freq ## _m_coeff_ ## reg_coeff ## _iqdc_tx_fir_coeff_ ## fir_coeff ## _setf

#define GET_IQDC_M_COEFF_TX(freq, reg_coeff, fir_coeff) \
rfic_wrap_iqdc_tx_ ## freq ## _m_coeff_ ## reg_coeff ## _iqdc_tx_fir_coeff_ ## fir_coeff ## _getf

#define GET_IQDC_TX(chain, reg_coeff, _fir_coeff) \
riu_iqdc_tx_## chain ##_coef_## reg_coeff ##_iqdc_tx_ ## chain ##_fir_coeff_## _fir_coeff ##_getf

#define SET_IQDC_TX(chain, reg_coeff, _fir_coeff) \
riu_iqdc_tx_## chain ##_coef_## reg_coeff ##_iqdc_tx_## chain ##_fir_coeff_## _fir_coeff ##_setf

#define GET_IQDC_RX(chain, reg_coeff, _fir_coeff, set_rx) \
riu_iqdc_rx_## chain ##_coef_## reg_coeff ##_set_## set_rx ##_iqdc_rx_## chain ##_fir_coeff_## \
_fir_coeff ##_getf

#define SET_IQDC_RX(chain, reg_coeff, _fir_coeff, set_rx) \
riu_iqdc_rx_## chain ##_coef_## reg_coeff ##_set_## set_rx ##_iqdc_rx_## chain ##_fir_coeff_## \
_fir_coeff ##_setf

#define GET_QDC_RX(chain, reg_coeff, _fir_coeff, set_rx) \
riu_iqdc_rx_## chain ##_coef_## reg_coeff ##_set_## set_rx ##_qdc_rx_## chain ##_fir_coeff_## \
_fir_coeff ##_getf

#define SET_QDC_RX(chain, reg_coeff, _fir_coeff, set_rx) \
riu_iqdc_rx_## chain ##_coef_## reg_coeff ##_set_## set_rx ##_qdc_rx_## chain ##_fir_coeff_## \
_fir_coeff ##_setf

enum rf_overwrite_cmd {
	OVERWRITE_DONE,
	SPI_RD_CMD,
	SPI_WR_CMD,
	GCU_WR_CMD,
	RIU_WR_CMD,
	UDELAY_CMD,
	GEN_WR_CMD,
	RF_REGS_RD_CMD,
	RF_REGS_WR_CMD,
	RF_WRAP_RD_CMD,
	RF_WRAP_WR_CMD,
	RF_OVERWRITE_CMD_MAX = OVERWRITE_DONE
};

enum rf_overwrite_file_id {
	RF_OVERWRITE_INIT,
	RF_OVERWRITE_SET_CHANNEL_TCV0,
	RF_OVERWRITE_SET_CHANNEL_TCV1,
	RF_OVERWRITE_FILE_ID_MAX
};

enum cl_rfic_chain {
	CL_RFIC_CH_0,
	CL_RFIC_CH_1
};

enum cl_iq_direction {
	CL_IQ_DIRECTION_RX,
	CL_IQ_DIRECTION_TX,
	CL_IQ_DIRECTION_MAX
};

enum cl_iq_tx_dc_type {
	CL_IQ_TX_DC_TYPE_I,
	CL_IQ_TX_DC_TYPE_Q,
	CL_IQ_TX_DC_TYPE_COMBINATION,
	CL_IQ_TX_DC_TYPE_MAX
};

enum cl_iq_set_tx {
	CL_IQ_SET_TX_1 = 1,
	CL_IQ_SET_TX_MAX
};

enum cl_iq_set_rx {
	CL_IQ_SET_RX_1 = 1,
	CL_IQ_SET_RX_2,
	CL_IQ_SET_RX_3,
	CL_IQ_SET_RX_MAX
};

enum cl_fir_coeff_rx {
	CL_FIR_COEFF_RX_0,
	CL_FIR_COEFF_RX_1,
	CL_FIR_COEFF_RX_2,
	CL_FIR_COEFF_RX_3,
	CL_FIR_COEFF_RX_4,
	CL_FIR_COEFF_RX_5,
	CL_FIR_COEFF_RX_6,
	CL_FIR_COEFF_RX_7,
	CL_FIR_COEFF_RX_8,
	CL_FIR_COEFF_RX_9,
	CL_FIR_COEFF_RX_10,
	CL_FIR_COEFF_RX_11,
	CL_FIR_COEFF_RX_12,
	CL_FIR_COEFF_RX_13,
	CL_FIR_COEFF_RX_14,
	CL_FIR_COEFF_RX_15,
	CL_FIR_COEFF_RX_16,
	CL_FIR_COEFF_RX_17,
	CL_FIR_COEFF_RX_18,
	CL_FIR_COEFF_RX_19,
	CL_FIR_COEFF_RX_20,
	CL_FIR_COEFF_RX_MAX
};

enum cl_fir_coeff_tx {
	CL_FIR_COEFF_TX_0,
	CL_FIR_COEFF_TX_1,
	CL_FIR_COEFF_TX_2,
	CL_FIR_COEFF_TX_3,
	CL_FIR_COEFF_TX_4,
	CL_FIR_COEFF_TX_5,
	CL_FIR_COEFF_TX_6,
	CL_FIR_COEFF_TX_7,
	CL_FIR_COEFF_TX_8,
	CL_FIR_COEFF_TX_9,
	CL_FIR_COEFF_TX_10,
	CL_FIR_COEFF_TX_11,
	CL_FIR_COEFF_TX_12,
	CL_FIR_COEFF_TX_13,
	CL_FIR_COEFF_TX_14,
	CL_FIR_COEFF_TX_15,
	CL_FIR_COEFF_TX_16,
	CL_FIR_COEFF_TX_17,
	CL_FIR_COEFF_TX_18,
	CL_FIR_COEFF_TX_19,
	CL_FIR_COEFF_TX_20,
	CL_FIR_COEFF_TX_MAX
};

struct iqdc_tx_coeff {
	enum cl_fir_coeff_tx fir_coeff;
	void (*set_iqdc_tx_coeff)(struct cl_chip *chip, u16 val);
	u16 (*get_iqdc_tx_coeff)(struct cl_chip *chip);
};

struct iqdc_rx_coeff {
	enum cl_fir_coeff_rx fir_coeff;
	enum cl_iq_set_rx set_rx;
	void (*set_iqdc_rx_coeff)(struct cl_chip *chip, u16 val);
	u16 (*get_iqdc_rx_coeff)(struct cl_chip *chip);
};

enum cl_rfic_lna {
	CL_RFIC_LNA_0,
	CL_RFIC_LNA_1,
	CL_RFIC_LNA_2,
	CL_RFIC_LNA_3,
	CL_RFIC_LNA_4,
	CL_RFIC_LNA_5,
	CL_RFIC_LNA_6,
	CL_RFIC_LNA_7,
	CL_RFIC_LNA_8,
	CL_RFIC_LNA_9,
	CL_RFIC_LNA_10,
	CL_RFIC_LNA_11,
	CL_RFIC_LNA_12,
	CL_RFIC_LNA_13,
	CL_RFIC_LNA_14,
	CL_RFIC_LNA_15
};

enum cl_iq_gain_type {
	CL_IQ_GAIN_TYPE_AMP,
	CL_IQ_GAIN_TYPE_PHASE,
	CL_IQ_GAIN_TYPE_COMBINATION,
	CL_IQ_GAIN_TYPE_MAX
};

enum cl_iq_dc_type {
	CL_IQ_DC_TYPE_I,
	CL_IQ_DC_TYPE_Q,
	CL_IQ_DC_TYPE_MAX
};

enum cl_iqdc_freq {
	CL_FREQ_1MHZ,
	CL_FREQ_2MHZ,

	CL_FREQ_MAX
};

enum iqdc_fir_m_coeff {
	IQDC_FIR_M_COEFF0,
	IQDC_FIR_M_COEFF1,
	IQDC_FIR_M_COEFF2,
	IQDC_FIR_M_COEFF3,
	IQDC_FIR_M_COEFF4,
	IQDC_FIR_M_COEFF5,
	IQDC_FIR_M_COEFF6,
	IQDC_FIR_M_COEFF7,
	IQDC_FIR_M_COEFF8,
	IQDC_FIR_M_COEFF9,
	IQDC_FIR_M_COEFF10,
	IQDC_FIR_M_COEFF_MAX
};

struct iqdc_tx_m_coeff {
	enum iqdc_fir_m_coeff coeff;
	void (*set_iqdc_m_coeff_tx)(struct cl_chip *chip, u16 val);
	u16 (*get_iqdc_m_coeff_tx)(struct cl_chip *chip);
};

enum rfic_type {
	RFIC_TYPE_WIFI,
	RFIC_TYPE_BT,
	RFIC_TYPE_MAX
};

enum cl_rfic_wifi_fsm_state {
	RFIC_WIFI_FSM_3W_4W,
	RFIC_WIFI_FSM_4W_5W,
	RFIC_WIFI_FSM_5W_6W,
	RFIC_WIFI_FSM_6W_7W,
	RFIC_WIFI_FSM_7W_8W,
	RFIC_WIFI_FSM_8W_9W,
	RFIC_WIFI_FSM_8W_10W,
	RFIC_WIFI_FSM_9W_8W,
	RFIC_WIFI_FSM_10W_8W,
	RFIC_WIFI_FSM_8W_8W,
	RFIC_WIFI_FSM_ALL_3W,
	RFIC_WIFI_FSM_MAX
};

enum cl_rfic_bt_fsm_transitions {
	RFIC_FSM_BT_3B_4B,
	RFIC_FSM_BT_4B_5B,
	RFIC_FSM_BT_5B_6B,
	RFIC_FSM_BT_6B_8B,
	RFIC_FSM_BT_8B_9B,
	RFIC_FSM_BT_8B_10B,
	RFIC_FSM_BT_9B_6B,
	RFIC_FSM_BT_10B_6B,
	RFIC_FSM_BT_ALL_3B,
	RFIC_FSM_BT_MAX,
};

int cl_rfic_read_overwrite_file(struct cl_hw *cl_hw, struct cl_rf_reg_overwrite_info *info,
				bool init);
int cl_rfic_cli(struct cl_hw *cl_hw, struct cli_params *cli_params);
int cl_rfic_get_iq_gain(struct cl_hw *cl_hw, u8 ant, enum cl_iq_direction direction,
			enum cl_iq_gain_type gain_type, s32 *val);
int cl_rfic_get_iq_dc(struct cl_hw *cl_hw, u8 ant, enum cl_iq_tx_dc_type dc_type, s32 *val);
#endif /* CL_RFIC_H */

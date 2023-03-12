// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "file.h"
#include "cl_utils.h"
#include "cl_rfic.h"
#include "cl_fw_msg.h"
#include "reg_riu.h"
#include "cl_calibration.h"
#include "reg_rfic_wrap.h"
#include "cl_msg_tx.h"
#include "def.h"
#include <linux/namei.h>

struct iqdc_tx_coeff tx_0_coeff[] = {
	{CL_FIR_COEFF_TX_0, SET_IQDC_TX(0, 0, 0), GET_IQDC_TX(0, 0, 0)},
	{CL_FIR_COEFF_TX_1, SET_IQDC_TX(0, 0, 1), GET_IQDC_TX(0, 0, 1)},
	{CL_FIR_COEFF_TX_2, SET_IQDC_TX(0, 0, 2), GET_IQDC_TX(0, 0, 2)},
	{CL_FIR_COEFF_TX_3, SET_IQDC_TX(0, 1, 3), GET_IQDC_TX(0, 1, 3)},
	{CL_FIR_COEFF_TX_4, SET_IQDC_TX(0, 1, 4), GET_IQDC_TX(0, 1, 4)},
	{CL_FIR_COEFF_TX_5, SET_IQDC_TX(0, 1, 5), GET_IQDC_TX(0, 1, 5)},
	{CL_FIR_COEFF_TX_6, SET_IQDC_TX(0, 2, 6), GET_IQDC_TX(0, 2, 6)},
	{CL_FIR_COEFF_TX_7, SET_IQDC_TX(0, 2, 7), GET_IQDC_TX(0, 2, 7)},
	{CL_FIR_COEFF_TX_8, SET_IQDC_TX(0, 2, 8), GET_IQDC_TX(0, 2, 8)},
	{CL_FIR_COEFF_TX_9, SET_IQDC_TX(0, 3, 9), GET_IQDC_TX(0, 3, 9)},
	{CL_FIR_COEFF_TX_10, SET_IQDC_TX(0, 3, 10), GET_IQDC_TX(0, 3, 10)},
	{CL_FIR_COEFF_TX_11, SET_IQDC_TX(0, 3, 11), GET_IQDC_TX(0, 3, 11)},
	{CL_FIR_COEFF_TX_12, SET_IQDC_TX(0, 4, 12), GET_IQDC_TX(0, 4, 12)},
	{CL_FIR_COEFF_TX_13, SET_IQDC_TX(0, 4, 13), GET_IQDC_TX(0, 4, 13)},
	{CL_FIR_COEFF_TX_14, SET_IQDC_TX(0, 4, 14), GET_IQDC_TX(0, 4, 14)},
	{CL_FIR_COEFF_TX_15, SET_IQDC_TX(0, 5, 15), GET_IQDC_TX(0, 5, 15)},
	{CL_FIR_COEFF_TX_16, SET_IQDC_TX(0, 5, 16), GET_IQDC_TX(0, 5, 16)},
	{CL_FIR_COEFF_TX_17, SET_IQDC_TX(0, 5, 17), GET_IQDC_TX(0, 5, 17)},
	{CL_FIR_COEFF_TX_18, SET_IQDC_TX(0, 6, 18), GET_IQDC_TX(0, 6, 18)},
	{CL_FIR_COEFF_TX_19, SET_IQDC_TX(0, 6, 19), GET_IQDC_TX(0, 6, 19)},
	{CL_FIR_COEFF_TX_20, SET_IQDC_TX(0, 6, 20), GET_IQDC_TX(0, 6, 20)},
};

struct iqdc_tx_coeff tx_1_coeff[] = {
	{CL_FIR_COEFF_TX_0, SET_IQDC_TX(1, 0, 0), GET_IQDC_TX(1, 0, 0)},
	{CL_FIR_COEFF_TX_1, SET_IQDC_TX(1, 0, 1), GET_IQDC_TX(1, 0, 1)},
	{CL_FIR_COEFF_TX_2, SET_IQDC_TX(1, 0, 2), GET_IQDC_TX(1, 0, 2)},
	{CL_FIR_COEFF_TX_3, SET_IQDC_TX(1, 1, 3), GET_IQDC_TX(1, 1, 3)},
	{CL_FIR_COEFF_TX_4, SET_IQDC_TX(1, 1, 4), GET_IQDC_TX(1, 1, 4)},
	{CL_FIR_COEFF_TX_5, SET_IQDC_TX(1, 1, 5), GET_IQDC_TX(1, 1, 5)},
	{CL_FIR_COEFF_TX_6, SET_IQDC_TX(1, 2, 6), GET_IQDC_TX(1, 2, 6)},
	{CL_FIR_COEFF_TX_7, SET_IQDC_TX(1, 2, 7), GET_IQDC_TX(1, 2, 7)},
	{CL_FIR_COEFF_TX_8, SET_IQDC_TX(1, 2, 8), GET_IQDC_TX(1, 2, 8)},
	{CL_FIR_COEFF_TX_9, SET_IQDC_TX(1, 3, 9), GET_IQDC_TX(1, 3, 9)},
	{CL_FIR_COEFF_TX_10, SET_IQDC_TX(1, 3, 10), GET_IQDC_TX(1, 3, 10)},
	{CL_FIR_COEFF_TX_11, SET_IQDC_TX(1, 3, 11), GET_IQDC_TX(1, 3, 11)},
	{CL_FIR_COEFF_TX_12, SET_IQDC_TX(1, 4, 12), GET_IQDC_TX(1, 4, 12)},
	{CL_FIR_COEFF_TX_13, SET_IQDC_TX(1, 4, 13), GET_IQDC_TX(1, 4, 13)},
	{CL_FIR_COEFF_TX_14, SET_IQDC_TX(1, 4, 14), GET_IQDC_TX(1, 4, 14)},
	{CL_FIR_COEFF_TX_15, SET_IQDC_TX(1, 5, 15), GET_IQDC_TX(1, 5, 15)},
	{CL_FIR_COEFF_TX_16, SET_IQDC_TX(1, 5, 16), GET_IQDC_TX(1, 5, 16)},
	{CL_FIR_COEFF_TX_17, SET_IQDC_TX(1, 5, 17), GET_IQDC_TX(1, 5, 17)},
	{CL_FIR_COEFF_TX_18, SET_IQDC_TX(1, 6, 18), GET_IQDC_TX(1, 6, 18)},
	{CL_FIR_COEFF_TX_19, SET_IQDC_TX(1, 6, 19), GET_IQDC_TX(1, 6, 19)},
	{CL_FIR_COEFF_TX_20, SET_IQDC_TX(1, 6, 20), GET_IQDC_TX(1, 6, 20)},
};

struct iqdc_rx_coeff rx_0_coeff[] = {
	{CL_FIR_COEFF_RX_0, CL_IQ_SET_RX_1, SET_IQDC_RX(0, 0, 0, 1), GET_IQDC_RX(0, 0, 0, 1)},
	{CL_FIR_COEFF_RX_1, CL_IQ_SET_RX_1, SET_IQDC_RX(0, 0, 1, 1), GET_IQDC_RX(0, 0, 1, 1)},
	{CL_FIR_COEFF_RX_2, CL_IQ_SET_RX_1, SET_IQDC_RX(0, 0, 2, 1), GET_IQDC_RX(0, 0, 2, 1)},
	{CL_FIR_COEFF_RX_3, CL_IQ_SET_RX_1, SET_IQDC_RX(0, 1, 3, 1), GET_IQDC_RX(0, 1, 3, 1)},
	{CL_FIR_COEFF_RX_4, CL_IQ_SET_RX_1, SET_IQDC_RX(0, 1, 4, 1), GET_IQDC_RX(0, 1, 4, 1)},
	{CL_FIR_COEFF_RX_5, CL_IQ_SET_RX_1, SET_IQDC_RX(0, 1, 5, 1), GET_IQDC_RX(0, 1, 5, 1)},
	{CL_FIR_COEFF_RX_6, CL_IQ_SET_RX_1, SET_IQDC_RX(0, 2, 6, 1), GET_IQDC_RX(0, 2, 6, 1)},
	{CL_FIR_COEFF_RX_7, CL_IQ_SET_RX_1, SET_IQDC_RX(0, 2, 7, 1), GET_IQDC_RX(0, 2, 7, 1)},
	{CL_FIR_COEFF_RX_8, CL_IQ_SET_RX_1, SET_IQDC_RX(0, 2, 8, 1), GET_IQDC_RX(0, 2, 8, 1)},
	{CL_FIR_COEFF_RX_9, CL_IQ_SET_RX_1, SET_IQDC_RX(0, 3, 9, 1), GET_IQDC_RX(0, 3, 9, 1)},
	{CL_FIR_COEFF_RX_10, CL_IQ_SET_RX_1, SET_IQDC_RX(0, 3, 10, 1), GET_IQDC_RX(0, 3, 10, 1)},
	{CL_FIR_COEFF_RX_11, CL_IQ_SET_RX_1, SET_IQDC_RX(0, 3, 11, 1), GET_IQDC_RX(0, 3, 11, 1)},
	{CL_FIR_COEFF_RX_12, CL_IQ_SET_RX_1, SET_IQDC_RX(0, 4, 12, 1), GET_IQDC_RX(0, 4, 12, 1)},
	{CL_FIR_COEFF_RX_13, CL_IQ_SET_RX_1, SET_IQDC_RX(0, 4, 13, 1), GET_IQDC_RX(0, 4, 13, 1)},
	{CL_FIR_COEFF_RX_14, CL_IQ_SET_RX_1, SET_IQDC_RX(0, 4, 14, 1), GET_IQDC_RX(0, 4, 14, 1)},
	{CL_FIR_COEFF_RX_15, CL_IQ_SET_RX_1, SET_IQDC_RX(0, 5, 15, 1), GET_IQDC_RX(0, 5, 15, 1)},
	{CL_FIR_COEFF_RX_16, CL_IQ_SET_RX_1, SET_IQDC_RX(0, 5, 16, 1), GET_IQDC_RX(0, 5, 16, 1)},
	{CL_FIR_COEFF_RX_17, CL_IQ_SET_RX_1, SET_IQDC_RX(0, 5, 17, 1), GET_IQDC_RX(0, 5, 17, 1)},
	{CL_FIR_COEFF_RX_18, CL_IQ_SET_RX_1, SET_IQDC_RX(0, 6, 18, 1), GET_IQDC_RX(0, 6, 18, 1)},
	{CL_FIR_COEFF_RX_19, CL_IQ_SET_RX_1, SET_IQDC_RX(0, 6, 19, 1), GET_IQDC_RX(0, 6, 19, 1)},
	{CL_FIR_COEFF_RX_20, CL_IQ_SET_RX_1, SET_IQDC_RX(0, 6, 20, 1), GET_IQDC_RX(0, 6, 20, 1)},

	{CL_FIR_COEFF_RX_0, CL_IQ_SET_RX_2, SET_IQDC_RX(0, 0, 0, 2), GET_IQDC_RX(0, 0, 0, 2)},
	{CL_FIR_COEFF_RX_1, CL_IQ_SET_RX_2, SET_IQDC_RX(0, 0, 1, 2), GET_IQDC_RX(0, 0, 1, 2)},
	{CL_FIR_COEFF_RX_2, CL_IQ_SET_RX_2, SET_IQDC_RX(0, 0, 2, 2), GET_IQDC_RX(0, 0, 2, 2)},
	{CL_FIR_COEFF_RX_3, CL_IQ_SET_RX_2, SET_IQDC_RX(0, 1, 3, 2), GET_IQDC_RX(0, 1, 3, 2)},
	{CL_FIR_COEFF_RX_4, CL_IQ_SET_RX_2, SET_IQDC_RX(0, 1, 4, 2), GET_IQDC_RX(0, 1, 4, 2)},
	{CL_FIR_COEFF_RX_5, CL_IQ_SET_RX_2, SET_IQDC_RX(0, 1, 5, 2), GET_IQDC_RX(0, 1, 5, 2)},
	{CL_FIR_COEFF_RX_6, CL_IQ_SET_RX_2, SET_IQDC_RX(0, 2, 6, 2), GET_IQDC_RX(0, 2, 6, 2)},
	{CL_FIR_COEFF_RX_7, CL_IQ_SET_RX_2, SET_IQDC_RX(0, 2, 7, 2), GET_IQDC_RX(0, 2, 7, 2)},
	{CL_FIR_COEFF_RX_8, CL_IQ_SET_RX_2, SET_IQDC_RX(0, 2, 8, 2), GET_IQDC_RX(0, 2, 8, 2)},
	{CL_FIR_COEFF_RX_9, CL_IQ_SET_RX_2, SET_IQDC_RX(0, 3, 9, 2), GET_IQDC_RX(0, 3, 9, 2)},
	{CL_FIR_COEFF_RX_10, CL_IQ_SET_RX_2, SET_IQDC_RX(0, 3, 10, 2), GET_IQDC_RX(0, 3, 10, 2)},
	{CL_FIR_COEFF_RX_11, CL_IQ_SET_RX_2, SET_IQDC_RX(0, 3, 11, 2), GET_IQDC_RX(0, 3, 11, 2)},
	{CL_FIR_COEFF_RX_12, CL_IQ_SET_RX_2, SET_IQDC_RX(0, 4, 12, 2), GET_IQDC_RX(0, 4, 12, 2)},
	{CL_FIR_COEFF_RX_13, CL_IQ_SET_RX_2, SET_IQDC_RX(0, 4, 13, 2), GET_IQDC_RX(0, 4, 13, 2)},
	{CL_FIR_COEFF_RX_14, CL_IQ_SET_RX_2, SET_IQDC_RX(0, 4, 14, 2), GET_IQDC_RX(0, 4, 14, 2)},
	{CL_FIR_COEFF_RX_15, CL_IQ_SET_RX_2, SET_IQDC_RX(0, 5, 15, 2), GET_IQDC_RX(0, 5, 15, 2)},
	{CL_FIR_COEFF_RX_16, CL_IQ_SET_RX_2, SET_IQDC_RX(0, 5, 16, 2), GET_IQDC_RX(0, 5, 16, 2)},
	{CL_FIR_COEFF_RX_17, CL_IQ_SET_RX_2, SET_IQDC_RX(0, 5, 17, 2), GET_IQDC_RX(0, 5, 17, 2)},
	{CL_FIR_COEFF_RX_18, CL_IQ_SET_RX_2, SET_IQDC_RX(0, 6, 18, 2), GET_IQDC_RX(0, 6, 18, 2)},
	{CL_FIR_COEFF_RX_19, CL_IQ_SET_RX_2, SET_IQDC_RX(0, 6, 19, 2), GET_IQDC_RX(0, 6, 19, 2)},
	{CL_FIR_COEFF_RX_20, CL_IQ_SET_RX_2, SET_IQDC_RX(0, 6, 20, 2), GET_IQDC_RX(0, 6, 20, 2)},

	{CL_FIR_COEFF_RX_0, CL_IQ_SET_RX_3, SET_IQDC_RX(0, 0, 0, 3), GET_IQDC_RX(0, 0, 0, 3)},
	{CL_FIR_COEFF_RX_1, CL_IQ_SET_RX_3, SET_IQDC_RX(0, 0, 1, 3), GET_IQDC_RX(0, 0, 1, 3)},
	{CL_FIR_COEFF_RX_2, CL_IQ_SET_RX_3, SET_IQDC_RX(0, 0, 2, 3), GET_IQDC_RX(0, 0, 2, 3)},
	{CL_FIR_COEFF_RX_3, CL_IQ_SET_RX_3, SET_IQDC_RX(0, 1, 3, 3), GET_IQDC_RX(0, 1, 3, 3)},
	{CL_FIR_COEFF_RX_4, CL_IQ_SET_RX_3, SET_IQDC_RX(0, 1, 4, 3), GET_IQDC_RX(0, 1, 4, 3)},
	{CL_FIR_COEFF_RX_5, CL_IQ_SET_RX_3, SET_IQDC_RX(0, 1, 5, 3), GET_IQDC_RX(0, 1, 5, 3)},
	{CL_FIR_COEFF_RX_6, CL_IQ_SET_RX_3, SET_IQDC_RX(0, 2, 6, 3), GET_IQDC_RX(0, 2, 6, 3)},
	{CL_FIR_COEFF_RX_7, CL_IQ_SET_RX_3, SET_IQDC_RX(0, 2, 7, 3), GET_IQDC_RX(0, 2, 7, 3)},
	{CL_FIR_COEFF_RX_8, CL_IQ_SET_RX_3, SET_IQDC_RX(0, 2, 8, 3), GET_IQDC_RX(0, 2, 8, 3)},
	{CL_FIR_COEFF_RX_9, CL_IQ_SET_RX_3, SET_IQDC_RX(0, 3, 9, 3), GET_IQDC_RX(0, 3, 9, 3)},
	{CL_FIR_COEFF_RX_10, CL_IQ_SET_RX_3, SET_IQDC_RX(0, 3, 10, 3), GET_IQDC_RX(0, 3, 10, 3)},
	{CL_FIR_COEFF_RX_11, CL_IQ_SET_RX_3, SET_IQDC_RX(0, 3, 11, 3), GET_IQDC_RX(0, 3, 11, 3)},
	{CL_FIR_COEFF_RX_12, CL_IQ_SET_RX_3, SET_IQDC_RX(0, 4, 12, 3), GET_IQDC_RX(0, 4, 12, 3)},
	{CL_FIR_COEFF_RX_13, CL_IQ_SET_RX_3, SET_IQDC_RX(0, 4, 13, 3), GET_IQDC_RX(0, 4, 13, 3)},
	{CL_FIR_COEFF_RX_14, CL_IQ_SET_RX_3, SET_IQDC_RX(0, 4, 14, 3), GET_IQDC_RX(0, 4, 14, 3)},
	{CL_FIR_COEFF_RX_15, CL_IQ_SET_RX_3, SET_IQDC_RX(0, 5, 15, 3), GET_IQDC_RX(0, 5, 15, 3)},
	{CL_FIR_COEFF_RX_16, CL_IQ_SET_RX_3, SET_IQDC_RX(0, 5, 16, 3), GET_IQDC_RX(0, 5, 16, 3)},
	{CL_FIR_COEFF_RX_17, CL_IQ_SET_RX_3, SET_IQDC_RX(0, 5, 17, 3), GET_IQDC_RX(0, 5, 17, 3)},
	{CL_FIR_COEFF_RX_18, CL_IQ_SET_RX_3, SET_IQDC_RX(0, 6, 18, 3), GET_IQDC_RX(0, 6, 18, 3)},
	{CL_FIR_COEFF_RX_19, CL_IQ_SET_RX_3, SET_IQDC_RX(0, 6, 19, 3), GET_IQDC_RX(0, 6, 19, 3)},
	{CL_FIR_COEFF_RX_20, CL_IQ_SET_RX_3, SET_IQDC_RX(0, 6, 20, 3), GET_IQDC_RX(0, 6, 20, 3)}
};

struct iqdc_rx_coeff rx_1_coeff[] = {
	{CL_FIR_COEFF_RX_0, CL_IQ_SET_RX_1, SET_QDC_RX(1, 0, 0, 1), GET_QDC_RX(1, 0, 0, 1)},
	{CL_FIR_COEFF_RX_1, CL_IQ_SET_RX_1, SET_QDC_RX(1, 0, 1, 1), GET_QDC_RX(1, 0, 1, 1)},
	{CL_FIR_COEFF_RX_2, CL_IQ_SET_RX_1, SET_QDC_RX(1, 0, 2, 1), GET_QDC_RX(1, 0, 2, 1)},
	{CL_FIR_COEFF_RX_3, CL_IQ_SET_RX_1, SET_IQDC_RX(1, 1, 3, 1), GET_IQDC_RX(1, 1, 3, 1)},
	{CL_FIR_COEFF_RX_4, CL_IQ_SET_RX_1, SET_IQDC_RX(1, 1, 4, 1), GET_IQDC_RX(1, 1, 4, 1)},
	{CL_FIR_COEFF_RX_5, CL_IQ_SET_RX_1, SET_IQDC_RX(1, 1, 5, 1), GET_IQDC_RX(1, 1, 5, 1)},
	{CL_FIR_COEFF_RX_6, CL_IQ_SET_RX_1, SET_IQDC_RX(1, 2, 6, 1), GET_IQDC_RX(1, 2, 6, 1)},
	{CL_FIR_COEFF_RX_7, CL_IQ_SET_RX_1, SET_IQDC_RX(1, 2, 7, 1), GET_IQDC_RX(1, 2, 7, 1)},
	{CL_FIR_COEFF_RX_8, CL_IQ_SET_RX_1, SET_IQDC_RX(1, 2, 8, 1), GET_IQDC_RX(1, 2, 8, 1)},
	{CL_FIR_COEFF_RX_9, CL_IQ_SET_RX_1, SET_IQDC_RX(1, 3, 9, 1), GET_IQDC_RX(1, 3, 9, 1)},
	{CL_FIR_COEFF_RX_10, CL_IQ_SET_RX_1, SET_IQDC_RX(1, 3, 10, 1), GET_IQDC_RX(1, 3, 10, 1)},
	{CL_FIR_COEFF_RX_11, CL_IQ_SET_RX_1, SET_IQDC_RX(1, 3, 11, 1), GET_IQDC_RX(1, 3, 11, 1)},
	{CL_FIR_COEFF_RX_12, CL_IQ_SET_RX_1, SET_IQDC_RX(1, 4, 12, 1), GET_IQDC_RX(1, 4, 12, 1)},
	{CL_FIR_COEFF_RX_13, CL_IQ_SET_RX_1, SET_IQDC_RX(1, 4, 13, 1), GET_IQDC_RX(1, 4, 13, 1)},
	{CL_FIR_COEFF_RX_14, CL_IQ_SET_RX_1, SET_IQDC_RX(1, 4, 14, 1), GET_IQDC_RX(1, 4, 14, 1)},
	{CL_FIR_COEFF_RX_15, CL_IQ_SET_RX_1, SET_IQDC_RX(1, 5, 15, 1), GET_IQDC_RX(1, 5, 15, 1)},
	{CL_FIR_COEFF_RX_16, CL_IQ_SET_RX_1, SET_IQDC_RX(1, 5, 16, 1), GET_IQDC_RX(1, 5, 16, 1)},
	{CL_FIR_COEFF_RX_17, CL_IQ_SET_RX_1, SET_IQDC_RX(1, 5, 17, 1), GET_IQDC_RX(1, 5, 17, 1)},
	{CL_FIR_COEFF_RX_18, CL_IQ_SET_RX_1, SET_IQDC_RX(1, 6, 18, 1), GET_IQDC_RX(1, 6, 18, 1)},
	{CL_FIR_COEFF_RX_19, CL_IQ_SET_RX_1, SET_IQDC_RX(1, 6, 19, 1), GET_IQDC_RX(1, 6, 19, 1)},
	{CL_FIR_COEFF_RX_20, CL_IQ_SET_RX_1, SET_IQDC_RX(1, 6, 20, 1), GET_IQDC_RX(1, 6, 20, 1)},

	{CL_FIR_COEFF_RX_0, CL_IQ_SET_RX_2, SET_IQDC_RX(1, 0, 0, 2), GET_IQDC_RX(1, 0, 0, 2)},
	{CL_FIR_COEFF_RX_1, CL_IQ_SET_RX_2, SET_IQDC_RX(1, 0, 1, 2), GET_IQDC_RX(1, 0, 1, 2)},
	{CL_FIR_COEFF_RX_2, CL_IQ_SET_RX_2, SET_IQDC_RX(1, 0, 2, 2), GET_IQDC_RX(1, 0, 2, 2)},
	{CL_FIR_COEFF_RX_3, CL_IQ_SET_RX_2, SET_IQDC_RX(1, 1, 3, 2), GET_IQDC_RX(1, 1, 3, 2)},
	{CL_FIR_COEFF_RX_4, CL_IQ_SET_RX_2, SET_IQDC_RX(1, 1, 4, 2), GET_IQDC_RX(1, 1, 4, 2)},
	{CL_FIR_COEFF_RX_5, CL_IQ_SET_RX_2, SET_IQDC_RX(1, 1, 5, 2), GET_IQDC_RX(1, 1, 5, 2)},
	{CL_FIR_COEFF_RX_6, CL_IQ_SET_RX_2, SET_IQDC_RX(1, 2, 6, 2), GET_IQDC_RX(1, 2, 6, 2)},
	{CL_FIR_COEFF_RX_7, CL_IQ_SET_RX_2, SET_IQDC_RX(1, 2, 7, 2), GET_IQDC_RX(1, 2, 7, 2)},
	{CL_FIR_COEFF_RX_8, CL_IQ_SET_RX_2, SET_IQDC_RX(1, 2, 8, 2), GET_IQDC_RX(1, 2, 8, 2)},
	{CL_FIR_COEFF_RX_9, CL_IQ_SET_RX_2, SET_IQDC_RX(1, 3, 9, 2), GET_IQDC_RX(1, 3, 9, 2)},
	{CL_FIR_COEFF_RX_10, CL_IQ_SET_RX_2, SET_IQDC_RX(1, 3, 10, 2), GET_IQDC_RX(1, 3, 10, 2)},
	{CL_FIR_COEFF_RX_11, CL_IQ_SET_RX_2, SET_IQDC_RX(1, 3, 11, 2), GET_IQDC_RX(1, 3, 11, 2)},
	{CL_FIR_COEFF_RX_12, CL_IQ_SET_RX_2, SET_IQDC_RX(1, 4, 12, 2), GET_IQDC_RX(1, 4, 12, 2)},
	{CL_FIR_COEFF_RX_13, CL_IQ_SET_RX_2, SET_IQDC_RX(1, 4, 13, 2), GET_IQDC_RX(1, 4, 13, 2)},
	{CL_FIR_COEFF_RX_14, CL_IQ_SET_RX_2, SET_IQDC_RX(1, 4, 14, 2), GET_IQDC_RX(1, 4, 14, 2)},
	{CL_FIR_COEFF_RX_15, CL_IQ_SET_RX_2, SET_IQDC_RX(1, 5, 15, 2), GET_IQDC_RX(1, 5, 15, 2)},
	{CL_FIR_COEFF_RX_16, CL_IQ_SET_RX_2, SET_IQDC_RX(1, 5, 16, 2), GET_IQDC_RX(1, 5, 16, 2)},
	{CL_FIR_COEFF_RX_17, CL_IQ_SET_RX_2, SET_IQDC_RX(1, 5, 17, 2), GET_IQDC_RX(1, 5, 17, 2)},
	{CL_FIR_COEFF_RX_18, CL_IQ_SET_RX_2, SET_IQDC_RX(1, 6, 18, 2), GET_IQDC_RX(1, 6, 18, 2)},
	{CL_FIR_COEFF_RX_19, CL_IQ_SET_RX_2, SET_IQDC_RX(1, 6, 19, 2), GET_IQDC_RX(1, 6, 19, 2)},
	{CL_FIR_COEFF_RX_20, CL_IQ_SET_RX_2, SET_IQDC_RX(1, 6, 20, 2), GET_IQDC_RX(1, 6, 20, 2)},

	{CL_FIR_COEFF_RX_0, CL_IQ_SET_RX_3, SET_IQDC_RX(1, 0, 0, 3), GET_IQDC_RX(1, 0, 0, 3)},
	{CL_FIR_COEFF_RX_1, CL_IQ_SET_RX_3, SET_IQDC_RX(1, 0, 1, 3), GET_IQDC_RX(1, 0, 1, 3)},
	{CL_FIR_COEFF_RX_2, CL_IQ_SET_RX_3, SET_IQDC_RX(1, 0, 2, 3), GET_IQDC_RX(1, 0, 2, 3)},
	{CL_FIR_COEFF_RX_3, CL_IQ_SET_RX_3, SET_IQDC_RX(1, 1, 3, 3), GET_IQDC_RX(1, 1, 3, 3)},
	{CL_FIR_COEFF_RX_4, CL_IQ_SET_RX_3, SET_IQDC_RX(1, 1, 4, 3), GET_IQDC_RX(1, 1, 4, 3)},
	{CL_FIR_COEFF_RX_5, CL_IQ_SET_RX_3, SET_IQDC_RX(1, 1, 5, 3), GET_IQDC_RX(1, 1, 5, 3)},
	{CL_FIR_COEFF_RX_6, CL_IQ_SET_RX_3, SET_IQDC_RX(1, 2, 6, 3), GET_IQDC_RX(1, 2, 6, 3)},
	{CL_FIR_COEFF_RX_7, CL_IQ_SET_RX_3, SET_IQDC_RX(1, 2, 7, 3), GET_IQDC_RX(1, 2, 7, 3)},
	{CL_FIR_COEFF_RX_8, CL_IQ_SET_RX_3, SET_IQDC_RX(1, 2, 8, 3), GET_IQDC_RX(1, 2, 8, 3)},
	{CL_FIR_COEFF_RX_9, CL_IQ_SET_RX_3, SET_IQDC_RX(1, 3, 9, 3), GET_IQDC_RX(1, 3, 9, 3)},
	{CL_FIR_COEFF_RX_10, CL_IQ_SET_RX_3, SET_IQDC_RX(1, 3, 10, 3), GET_IQDC_RX(1, 3, 10, 3)},
	{CL_FIR_COEFF_RX_11, CL_IQ_SET_RX_3, SET_IQDC_RX(1, 3, 11, 3), GET_IQDC_RX(1, 3, 11, 3)},
	{CL_FIR_COEFF_RX_12, CL_IQ_SET_RX_3, SET_IQDC_RX(1, 4, 12, 3), GET_IQDC_RX(1, 4, 12, 3)},
	{CL_FIR_COEFF_RX_13, CL_IQ_SET_RX_3, SET_IQDC_RX(1, 4, 13, 3), GET_IQDC_RX(1, 4, 13, 3)},
	{CL_FIR_COEFF_RX_14, CL_IQ_SET_RX_3, SET_IQDC_RX(1, 4, 14, 3), GET_IQDC_RX(1, 4, 14, 3)},
	{CL_FIR_COEFF_RX_15, CL_IQ_SET_RX_3, SET_IQDC_RX(1, 5, 15, 3), GET_IQDC_RX(1, 5, 15, 3)},
	{CL_FIR_COEFF_RX_16, CL_IQ_SET_RX_3, SET_IQDC_RX(1, 5, 16, 3), GET_IQDC_RX(1, 5, 16, 3)},
	{CL_FIR_COEFF_RX_17, CL_IQ_SET_RX_3, SET_IQDC_RX(1, 5, 17, 3), GET_IQDC_RX(1, 5, 17, 3)},
	{CL_FIR_COEFF_RX_18, CL_IQ_SET_RX_3, SET_IQDC_RX(1, 6, 18, 3), GET_IQDC_RX(1, 6, 18, 3)},
	{CL_FIR_COEFF_RX_19, CL_IQ_SET_RX_3, SET_IQDC_RX(1, 6, 19, 3), GET_IQDC_RX(1, 6, 19, 3)},
	{CL_FIR_COEFF_RX_20, CL_IQ_SET_RX_3, SET_IQDC_RX(1, 6, 20, 3), GET_IQDC_RX(1, 6, 20, 3)}
};

struct iqdc_tx_m_coeff tx_1_m_coeff[] = {
	{IQDC_FIR_M_COEFF0, SET_IQDC_M_COEFF_TX(1, 0, 0), GET_IQDC_M_COEFF_TX(1, 0, 0)},
	{IQDC_FIR_M_COEFF1, SET_IQDC_M_COEFF_TX(1, 0, 1), GET_IQDC_M_COEFF_TX(1, 0, 1)},
	{IQDC_FIR_M_COEFF2, SET_IQDC_M_COEFF_TX(1, 0, 2), GET_IQDC_M_COEFF_TX(1, 0, 2)},
	{IQDC_FIR_M_COEFF3, SET_IQDC_M_COEFF_TX(1, 1, 3), GET_IQDC_M_COEFF_TX(1, 1, 3)},
	{IQDC_FIR_M_COEFF4, SET_IQDC_M_COEFF_TX(1, 1, 4), GET_IQDC_M_COEFF_TX(1, 1, 4)},
	{IQDC_FIR_M_COEFF5, SET_IQDC_M_COEFF_TX(1, 1, 5), GET_IQDC_M_COEFF_TX(1, 1, 5)},
	{IQDC_FIR_M_COEFF6, SET_IQDC_M_COEFF_TX(1, 2, 6), GET_IQDC_M_COEFF_TX(1, 2, 6)},
	{IQDC_FIR_M_COEFF7, SET_IQDC_M_COEFF_TX(1, 2, 7), GET_IQDC_M_COEFF_TX(1, 2, 7)},
	{IQDC_FIR_M_COEFF8, SET_IQDC_M_COEFF_TX(1, 2, 8), GET_IQDC_M_COEFF_TX(1, 2, 8)},
	{IQDC_FIR_M_COEFF9, SET_IQDC_M_COEFF_TX(1, 3, 9), GET_IQDC_M_COEFF_TX(1, 3, 9)},
	{IQDC_FIR_M_COEFF10, SET_IQDC_M_COEFF_TX(1, 3, 10), GET_IQDC_M_COEFF_TX(1, 3, 10)},
};

struct iqdc_tx_m_coeff tx_2_m_coeff[] = {
	{IQDC_FIR_M_COEFF0, SET_IQDC_M_COEFF_TX(2, 0, 0), GET_IQDC_M_COEFF_TX(2, 0, 0)},
	{IQDC_FIR_M_COEFF1, SET_IQDC_M_COEFF_TX(2, 0, 1), GET_IQDC_M_COEFF_TX(2, 0, 1)},
	{IQDC_FIR_M_COEFF2, SET_IQDC_M_COEFF_TX(2, 0, 2), GET_IQDC_M_COEFF_TX(2, 0, 2)},
	{IQDC_FIR_M_COEFF3, SET_IQDC_M_COEFF_TX(2, 1, 3), GET_IQDC_M_COEFF_TX(2, 1, 3)},
	{IQDC_FIR_M_COEFF4, SET_IQDC_M_COEFF_TX(2, 1, 4), GET_IQDC_M_COEFF_TX(2, 1, 4)},
	{IQDC_FIR_M_COEFF5, SET_IQDC_M_COEFF_TX(2, 1, 5), GET_IQDC_M_COEFF_TX(2, 1, 5)},
	{IQDC_FIR_M_COEFF6, SET_IQDC_M_COEFF_TX(2, 2, 6), GET_IQDC_M_COEFF_TX(2, 2, 6)},
	{IQDC_FIR_M_COEFF7, SET_IQDC_M_COEFF_TX(2, 2, 7), GET_IQDC_M_COEFF_TX(2, 2, 7)},
	{IQDC_FIR_M_COEFF8, SET_IQDC_M_COEFF_TX(2, 2, 8), GET_IQDC_M_COEFF_TX(2, 2, 8)},
	{IQDC_FIR_M_COEFF9, SET_IQDC_M_COEFF_TX(2, 3, 9), GET_IQDC_M_COEFF_TX(2, 3, 9)},
	{IQDC_FIR_M_COEFF10, SET_IQDC_M_COEFF_TX(2, 3, 10), GET_IQDC_M_COEFF_TX(2, 3, 10)},
};

static u8 str_to_cmd(struct cl_hw *cl_hw, char *str)
{
	if (!strcmp(str, "DONE"))
		return OVERWRITE_DONE;
	else if (!strcmp(str, "SPI_R"))
		return SPI_RD_CMD;
	else if (!strcmp(str, "SPI_W"))
		return SPI_WR_CMD;
	else if (!strcmp(str, "GCU_W"))
		return GCU_WR_CMD;
	else if (!strcmp(str, "RIU_W"))
		return RIU_WR_CMD;
	else if (!strcmp(str, "GEN_W"))
		return GEN_WR_CMD;
	else if (!strcmp(str, "DELAY"))
		return UDELAY_CMD;
	else if (!strcmp(str, "RF_REG_R"))
		return RF_REGS_RD_CMD;
	else if (!strcmp(str, "RF_REG_W"))
		return RF_REGS_WR_CMD;
	else if (!strcmp(str, "RF_WRAP_R"))
		return RF_WRAP_RD_CMD;
	else if (!strcmp(str, "RF_WRAP_W"))
		return RF_WRAP_WR_CMD;

	cl_dbg_err(cl_hw, "unknown command %s\n", str);
	return OVERWRITE_DONE;
}

static void parse_rf_command(struct cl_hw *cl_hw, char *str,
			     struct cl_rf_reg_overwrite_info *info)
{
	int i = 0;
	char *ptr = NULL;
	u32 res = 0;

	while ((ptr = strsep(&str, " ")) && (*ptr != '\n')) {
		if (i == 0) {
			info->cmd = str_to_cmd(cl_hw, ptr);
		} else {
			if (kstrtou32(ptr, 16, &res) != 0) {
				pr_err("%s: invalid data - %s\n", __func__, ptr);
				return;
			}
			info->data[i - 1] = cpu_to_le32(res);
			res = 0;
		}
		i++;
	}
}

#define RF_CMD_MAX_LEN 64

static void parse_rf_commands_from_buf(struct cl_hw *cl_hw, char *buf,
				       loff_t size,
				       struct cl_rf_reg_overwrite_info *info)
{
	int i = 0;
	char *line = buf;
	char str[RF_CMD_MAX_LEN];
	char *end;
	int line_length = 0;

	while (line && (line != (buf + size))) {
		if ((*line == '#') || (*line == '\n')) {
			/* Skip comment or blank line */
			line = strstr(line, "\n") + 1;
		} else if (*line) {
			end = strstr(line, "\n") + 1;
			line_length = end - line;

			if (line_length >= RF_CMD_MAX_LEN) {
				cl_dbg_err(cl_hw, "Command too long (%u)\n", line_length);
				return;
			}

			snprintf(str, line_length, "%s", line);
			parse_rf_command(cl_hw, str, &info[i++]);
			line += line_length;
		}
	}
}

int cl_rfic_read_overwrite_file(struct cl_hw *cl_hw,
				struct cl_rf_reg_overwrite_info *info,
				bool init)
{
	char *buf = NULL;
	size_t size = 0;
	char filename[CL_FILENAME_MAX] = {0};
	char path_name[CL_PATH_MAX] = {0};
	struct path path;

	if (init)
		snprintf(filename, sizeof(filename), "rf_init_overwrite.txt");
	else
		snprintf(filename, sizeof(filename), "rf_tcv%d_overwrite.txt", cl_hw->tcv_idx);

	snprintf(path_name, sizeof(path_name), "/lib/firmware/cl6k/%s", filename);
	if (kern_path(path_name, LOOKUP_FOLLOW, &path) < 0)
		return 0;

	size = cl_file_open_and_read(cl_hw->chip, filename, &buf);

	if (!buf)
		return 0;

	cl_dbg_trace(cl_hw, "parsing %s !!!\n", filename);
	parse_rf_commands_from_buf(cl_hw, buf, size, info);
	kfree(buf);
	return 0;
}

static int cl_rfic_get_iqdc_set_rx_0_coeff(struct cl_hw *cl_hw, enum cl_iq_set_rx set,
					   enum cl_fir_coeff_rx coeff, u16 *val)
{
	int i;
	struct cl_chip *chip = cl_hw->chip;
	int sz = ARRAY_SIZE(rx_0_coeff);

	for (i = 0; i < sz; i++) {
		if (coeff == rx_0_coeff[i].fir_coeff && set == rx_0_coeff[i].set_rx) {
			*val = rx_0_coeff[i].get_iqdc_rx_coeff(chip);
			break;
		}
	}

	return 0;
}

static int cl_rfic_get_iqdc_set_rx_1_coeff(struct cl_hw *cl_hw, enum cl_iq_set_rx set,
					   enum  cl_fir_coeff_rx coeff, u16 *val)
{
	int i;
	struct cl_chip *chip = cl_hw->chip;
	int sz = ARRAY_SIZE(rx_1_coeff);

	for (i = 0; i < sz; i++) {
		if (coeff == rx_1_coeff[i].fir_coeff && set == rx_1_coeff[i].set_rx) {
			*val = rx_1_coeff[i].get_iqdc_rx_coeff(chip);
			break;
		}
	}

	return 0;
}

static int cl_rfic_iqdc_gain_set_rx(struct cl_hw *cl_hw, enum cl_rfic_chain ant,
				    enum cl_iq_set_rx set, enum cl_iq_gain_type gain_type,
				    u32 val)
{
	struct cl_chip *chip = cl_hw->chip;

	switch (ant) {
	case CL_RFIC_CH_0:
		switch (gain_type) {
		case CL_IQ_GAIN_TYPE_AMP:
			switch (set) {
			case CL_IQ_SET_RX_1:
				riu_iqdc_rx_0_gain_set_1_iqdc_rx_0_amp_gain_setf(chip, val);
				break;
			case CL_IQ_SET_RX_2:
				riu_iqdc_rx_0_gain_set_2_iqdc_rx_0_amp_gain_setf(chip, val);
				break;
			case CL_IQ_SET_RX_3:
				riu_iqdc_rx_0_gain_set_3_iqdc_rx_0_amp_gain_setf(chip, val);
				break;
			default:
				cl_dbg_err(cl_hw, "wrong set argument = %d\n", set);
				return -EINVAL;
			}
			break;
		case CL_IQ_GAIN_TYPE_PHASE:
			switch (set) {
			case CL_IQ_SET_RX_1:
				riu_iqdc_rx_0_gain_set_1_iqdc_rx_0_phase_gain_setf(chip, val);
				break;
			case CL_IQ_SET_RX_2:
				riu_iqdc_rx_0_gain_set_2_iqdc_rx_0_phase_gain_setf(chip, val);
				break;
			case CL_IQ_SET_RX_3:
				riu_iqdc_rx_0_gain_set_3_iqdc_rx_0_phase_gain_setf(chip, val);
				break;
			default:
				cl_dbg_err(cl_hw, "wrong set argument = %d\n", set);
				return -EINVAL;
			}
			break;
		default:
			cl_dbg_err(cl_hw, "wrong gain_type argument = %d\n", gain_type);
			return -EINVAL;
		}
		break;
	case CL_RFIC_CH_1:
		switch (gain_type) {
		case CL_IQ_GAIN_TYPE_AMP:
			switch (set) {
			case CL_IQ_SET_RX_1:
				riu_iqdc_rx_1_gain_set_1_iqdc_rx_1_amp_gain_setf(chip, val);
				break;
			case CL_IQ_SET_RX_2:
				riu_iqdc_rx_1_gain_set_2_iqdc_rx_1_amp_gain_setf(chip, val);
				break;
			case CL_IQ_SET_RX_3:
				riu_iqdc_rx_1_gain_set_3_iqdc_rx_1_amp_gain_setf(chip, val);
				break;
			default:
				cl_dbg_err(cl_hw, "wrong set argument = %d\n", set);
				return -EINVAL;
			}
			break;
		case CL_IQ_GAIN_TYPE_PHASE:
			switch (set) {
			case CL_IQ_SET_RX_1:
				riu_iqdc_rx_1_gain_set_1_iqdc_rx_1_phase_gain_setf(chip, val);
				break;
			case CL_IQ_SET_RX_2:
				riu_iqdc_rx_1_gain_set_2_iqdc_rx_1_phase_gain_setf(chip, val);
				break;
			case CL_IQ_SET_RX_3:
				riu_iqdc_rx_1_gain_set_3_iqdc_rx_1_phase_gain_setf(chip, val);
				break;
			default:
				cl_dbg_err(cl_hw, "wrong set argument = %d\n", set);
				return -EINVAL;
			}
			break;
		default:
			cl_dbg_err(cl_hw, "wrong gain_type argument = %d\n", gain_type);
			return -EINVAL;
		}
		break;
	default:
		cl_dbg_err(cl_hw, "wrong ant argument = %d\n", ant);
		return -EINVAL;
	}

	return 0;
}

static int cl_rfic_get_iqdc_set_tx_0_coeff(struct cl_hw *cl_hw, enum  cl_fir_coeff_tx coeff,
					   u16 *val)
{
	int i;
	struct cl_chip *chip = cl_hw->chip;
	int sz = ARRAY_SIZE(tx_0_coeff);

	for (i = 0; i < sz; i++) {
		if (coeff == tx_0_coeff[i].fir_coeff) {
			*val = tx_0_coeff[i].get_iqdc_tx_coeff(chip);
			break;
		}
	}

	return 0;
}

static int cl_rfic_get_iqdc_set_tx_1_coeff(struct cl_hw *cl_hw, enum  cl_fir_coeff_tx coeff,
					   u16 *val)
{
	int i;
	struct cl_chip *chip = cl_hw->chip;
	int sz = ARRAY_SIZE(tx_1_coeff);

	for (i = 0; i < sz; i++) {
		if (coeff == tx_1_coeff[i].fir_coeff) {
			*val = tx_1_coeff[i].get_iqdc_tx_coeff(chip);
			break;
		}
	}

	return 0;
}

static int cl_rfic_wrap_dcoc_set(struct cl_hw *cl_hw, enum cl_rfic_chain ant,
				 enum cl_rfic_lna lna, enum calib_dc_type dc_type, u8 value)
{
	struct cl_chip *chip = cl_hw->chip;

	switch (ant) {
	case CL_RFIC_CH_0:
		switch (lna) {
		case CL_RFIC_LNA_0:
			switch (dc_type) {
			case DC_IP:
				rfic_wrap_wifi_rf_rx_ch_0_lna_0_dcoc_bb_dcoc_ip_setf(chip, value);
				break;
			case DC_IN:
				rfic_wrap_wifi_rf_rx_ch_0_lna_0_dcoc_bb_dcoc_in_setf(chip, value);
				break;
			case DC_QP:
				rfic_wrap_wifi_rf_rx_ch_0_lna_0_dcoc_bb_dcoc_qp_setf(chip, value);
				break;
			case DC_QN:
				rfic_wrap_wifi_rf_rx_ch_0_lna_0_dcoc_bb_dcoc_qn_setf(chip, value);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_1:
			switch (dc_type) {
			case DC_IP:
				rfic_wrap_wifi_rf_rx_ch_0_lna_1_dcoc_bb_dcoc_ip_setf(chip, value);
				break;
			case DC_IN:
				rfic_wrap_wifi_rf_rx_ch_0_lna_1_dcoc_bb_dcoc_in_setf(chip, value);
				break;
			case DC_QP:
				rfic_wrap_wifi_rf_rx_ch_0_lna_1_dcoc_bb_dcoc_qp_setf(chip, value);
				break;
			case DC_QN:
				rfic_wrap_wifi_rf_rx_ch_0_lna_1_dcoc_bb_dcoc_qn_setf(chip, value);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_2:
			switch (dc_type) {
			case DC_IP:
				rfic_wrap_wifi_rf_rx_ch_0_lna_2_dcoc_bb_dcoc_ip_setf(chip, value);
				break;
			case DC_IN:
				rfic_wrap_wifi_rf_rx_ch_0_lna_2_dcoc_bb_dcoc_in_setf(chip, value);
				break;
			case DC_QP:
				rfic_wrap_wifi_rf_rx_ch_0_lna_2_dcoc_bb_dcoc_qp_setf(chip, value);
				break;
			case DC_QN:
				rfic_wrap_wifi_rf_rx_ch_0_lna_2_dcoc_bb_dcoc_qn_setf(chip, value);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_3:
			switch (dc_type) {
			case DC_IP:
				rfic_wrap_wifi_rf_rx_ch_0_lna_3_dcoc_bb_dcoc_ip_setf(chip, value);
				break;
			case DC_IN:
				rfic_wrap_wifi_rf_rx_ch_0_lna_3_dcoc_bb_dcoc_in_setf(chip, value);
				break;
			case DC_QP:
				rfic_wrap_wifi_rf_rx_ch_0_lna_3_dcoc_bb_dcoc_qp_setf(chip, value);
				break;
			case DC_QN:
				rfic_wrap_wifi_rf_rx_ch_0_lna_3_dcoc_bb_dcoc_qn_setf(chip, value);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_4:
			switch (dc_type) {
			case DC_IP:
				rfic_wrap_wifi_rf_rx_ch_0_lna_4_dcoc_bb_dcoc_ip_setf(chip, value);
				break;
			case DC_IN:
				rfic_wrap_wifi_rf_rx_ch_0_lna_4_dcoc_bb_dcoc_in_setf(chip, value);
				break;
			case DC_QP:
				rfic_wrap_wifi_rf_rx_ch_0_lna_4_dcoc_bb_dcoc_qp_setf(chip, value);
				break;
			case DC_QN:
				rfic_wrap_wifi_rf_rx_ch_0_lna_4_dcoc_bb_dcoc_qn_setf(chip, value);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_5:
			switch (dc_type) {
			case DC_IP:
				rfic_wrap_wifi_rf_rx_ch_0_lna_5_dcoc_bb_dcoc_ip_setf(chip, value);
				break;
			case DC_IN:
				rfic_wrap_wifi_rf_rx_ch_0_lna_5_dcoc_bb_dcoc_in_setf(chip, value);
				break;
			case DC_QP:
				rfic_wrap_wifi_rf_rx_ch_0_lna_5_dcoc_bb_dcoc_qp_setf(chip, value);
				break;
			case DC_QN:
				rfic_wrap_wifi_rf_rx_ch_0_lna_5_dcoc_bb_dcoc_qn_setf(chip, value);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_6:
			switch (dc_type) {
			case DC_IP:
				rfic_wrap_wifi_rf_rx_ch_0_lna_6_dcoc_bb_dcoc_ip_setf(chip, value);
				break;
			case DC_IN:
				rfic_wrap_wifi_rf_rx_ch_0_lna_6_dcoc_bb_dcoc_in_setf(chip, value);
				break;
			case DC_QP:
				rfic_wrap_wifi_rf_rx_ch_0_lna_6_dcoc_bb_dcoc_qp_setf(chip, value);
				break;
			case DC_QN:
				rfic_wrap_wifi_rf_rx_ch_0_lna_6_dcoc_bb_dcoc_qn_setf(chip, value);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_7:
			switch (dc_type) {
			case DC_IP:
				rfic_wrap_wifi_rf_rx_ch_0_lna_7_dcoc_bb_dcoc_ip_setf(chip, value);
				break;
			case DC_IN:
				rfic_wrap_wifi_rf_rx_ch_0_lna_7_dcoc_bb_dcoc_in_setf(chip, value);
				break;
			case DC_QP:
				rfic_wrap_wifi_rf_rx_ch_0_lna_7_dcoc_bb_dcoc_qp_setf(chip, value);
				break;
			case DC_QN:
				rfic_wrap_wifi_rf_rx_ch_0_lna_7_dcoc_bb_dcoc_qn_setf(chip, value);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_8:
			switch (dc_type) {
			case DC_IP:
				rfic_wrap_wifi_rf_rx_ch_0_lna_8_dcoc_bb_dcoc_ip_setf(chip, value);
				break;
			case DC_IN:
				rfic_wrap_wifi_rf_rx_ch_0_lna_8_dcoc_bb_dcoc_in_setf(chip, value);
				break;
			case DC_QP:
				rfic_wrap_wifi_rf_rx_ch_0_lna_8_dcoc_bb_dcoc_qp_setf(chip, value);
				break;
			case DC_QN:
				rfic_wrap_wifi_rf_rx_ch_0_lna_8_dcoc_bb_dcoc_qn_setf(chip, value);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_9:
			switch (dc_type) {
			case DC_IP:
				rfic_wrap_wifi_rf_rx_ch_0_lna_9_dcoc_bb_dcoc_ip_setf(chip, value);
				break;
			case DC_IN:
				rfic_wrap_wifi_rf_rx_ch_0_lna_9_dcoc_bb_dcoc_in_setf(chip, value);
				break;
			case DC_QP:
				rfic_wrap_wifi_rf_rx_ch_0_lna_9_dcoc_bb_dcoc_qp_setf(chip, value);
				break;
			case DC_QN:
				rfic_wrap_wifi_rf_rx_ch_0_lna_9_dcoc_bb_dcoc_qn_setf(chip, value);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_10:
			switch (dc_type) {
			case DC_IP:
				rfic_wrap_wifi_rf_rx_ch_0_lna_10_dcoc_bb_dcoc_ip_setf(chip, value);
				break;
			case DC_IN:
				rfic_wrap_wifi_rf_rx_ch_0_lna_10_dcoc_bb_dcoc_in_setf(chip, value);
				break;
			case DC_QP:
				rfic_wrap_wifi_rf_rx_ch_0_lna_10_dcoc_bb_dcoc_qp_setf(chip, value);
				break;
			case DC_QN:
				rfic_wrap_wifi_rf_rx_ch_0_lna_10_dcoc_bb_dcoc_qn_setf(chip, value);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_11:
			switch (dc_type) {
			case DC_IP:
				rfic_wrap_wifi_rf_rx_ch_0_lna_11_dcoc_bb_dcoc_ip_setf(chip, value);
				break;
			case DC_IN:
				rfic_wrap_wifi_rf_rx_ch_0_lna_11_dcoc_bb_dcoc_in_setf(chip, value);
				break;
			case DC_QP:
				rfic_wrap_wifi_rf_rx_ch_0_lna_11_dcoc_bb_dcoc_qp_setf(chip, value);
				break;
			case DC_QN:
				rfic_wrap_wifi_rf_rx_ch_0_lna_11_dcoc_bb_dcoc_qn_setf(chip, value);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_12:
			switch (dc_type) {
			case DC_IP:
				rfic_wrap_wifi_rf_rx_ch_0_lna_12_dcoc_bb_dcoc_ip_setf(chip, value);
				break;
			case DC_IN:
				rfic_wrap_wifi_rf_rx_ch_0_lna_12_dcoc_bb_dcoc_in_setf(chip, value);
				break;
			case DC_QP:
				rfic_wrap_wifi_rf_rx_ch_0_lna_12_dcoc_bb_dcoc_qp_setf(chip, value);
				break;
			case DC_QN:
				rfic_wrap_wifi_rf_rx_ch_0_lna_12_dcoc_bb_dcoc_qn_setf(chip, value);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_13:
			switch (dc_type) {
			case DC_IP:
				rfic_wrap_wifi_rf_rx_ch_0_lna_13_dcoc_bb_dcoc_ip_setf(chip, value);
				break;
			case DC_IN:
				rfic_wrap_wifi_rf_rx_ch_0_lna_13_dcoc_bb_dcoc_in_setf(chip, value);
				break;
			case DC_QP:
				rfic_wrap_wifi_rf_rx_ch_0_lna_13_dcoc_bb_dcoc_qp_setf(chip, value);
				break;
			case DC_QN:
				rfic_wrap_wifi_rf_rx_ch_0_lna_13_dcoc_bb_dcoc_qn_setf(chip, value);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_14:
			switch (dc_type) {
			case DC_IP:
				rfic_wrap_wifi_rf_rx_ch_0_lna_14_dcoc_bb_dcoc_ip_setf(chip, value);
				break;
			case DC_IN:
				rfic_wrap_wifi_rf_rx_ch_0_lna_14_dcoc_bb_dcoc_in_setf(chip, value);
				break;
			case DC_QP:
				rfic_wrap_wifi_rf_rx_ch_0_lna_14_dcoc_bb_dcoc_qp_setf(chip, value);
				break;
			case DC_QN:
				rfic_wrap_wifi_rf_rx_ch_0_lna_14_dcoc_bb_dcoc_qn_setf(chip, value);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_15:
			switch (dc_type) {
			case DC_IP:
				rfic_wrap_wifi_rf_rx_ch_0_lna_15_dcoc_bb_dcoc_ip_setf(chip, value);
				break;
			case DC_IN:
				rfic_wrap_wifi_rf_rx_ch_0_lna_15_dcoc_bb_dcoc_in_setf(chip, value);
				break;
			case DC_QP:
				rfic_wrap_wifi_rf_rx_ch_0_lna_15_dcoc_bb_dcoc_qp_setf(chip, value);
				break;
			case DC_QN:
				rfic_wrap_wifi_rf_rx_ch_0_lna_15_dcoc_bb_dcoc_qn_setf(chip, value);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		default:
			cl_dbg_err(cl_hw, "Wrong input lna argument %d\n", lna);
			return -EINVAL;
		}
		break;
	case CL_RFIC_CH_1:
		switch (lna) {
		case CL_RFIC_LNA_0:
			switch (dc_type) {
			case DC_IP:
				rfic_wrap_wifi_rf_rx_ch_1_lna_0_dcoc_bb_dcoc_ip_setf(chip, value);
				break;
			case DC_IN:
				rfic_wrap_wifi_rf_rx_ch_1_lna_0_dcoc_bb_dcoc_in_setf(chip, value);
				break;
			case DC_QP:
				rfic_wrap_wifi_rf_rx_ch_1_lna_0_dcoc_bb_dcoc_qp_setf(chip, value);
				break;
			case DC_QN:
				rfic_wrap_wifi_rf_rx_ch_1_lna_0_dcoc_bb_dcoc_qn_setf(chip, value);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_1:
			switch (dc_type) {
			case DC_IP:
				rfic_wrap_wifi_rf_rx_ch_1_lna_1_dcoc_bb_dcoc_ip_setf(chip, value);
				break;
			case DC_IN:
				rfic_wrap_wifi_rf_rx_ch_1_lna_1_dcoc_bb_dcoc_in_setf(chip, value);
				break;
			case DC_QP:
				rfic_wrap_wifi_rf_rx_ch_1_lna_1_dcoc_bb_dcoc_qp_setf(chip, value);
				break;
			case DC_QN:
				rfic_wrap_wifi_rf_rx_ch_1_lna_1_dcoc_bb_dcoc_qn_setf(chip, value);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_2:
			switch (dc_type) {
			case DC_IP:
				rfic_wrap_wifi_rf_rx_ch_1_lna_2_dcoc_bb_dcoc_ip_setf(chip, value);
				break;
			case DC_IN:
				rfic_wrap_wifi_rf_rx_ch_1_lna_2_dcoc_bb_dcoc_in_setf(chip, value);
				break;
			case DC_QP:
				rfic_wrap_wifi_rf_rx_ch_1_lna_2_dcoc_bb_dcoc_qp_setf(chip, value);
				break;
			case DC_QN:
				rfic_wrap_wifi_rf_rx_ch_1_lna_2_dcoc_bb_dcoc_qn_setf(chip, value);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_3:
			switch (dc_type) {
			case DC_IP:
				rfic_wrap_wifi_rf_rx_ch_1_lna_3_dcoc_bb_dcoc_ip_setf(chip, value);
				break;
			case DC_IN:
				rfic_wrap_wifi_rf_rx_ch_1_lna_3_dcoc_bb_dcoc_in_setf(chip, value);
				break;
			case DC_QP:
				rfic_wrap_wifi_rf_rx_ch_1_lna_3_dcoc_bb_dcoc_qp_setf(chip, value);
				break;
			case DC_QN:
				rfic_wrap_wifi_rf_rx_ch_1_lna_3_dcoc_bb_dcoc_qn_setf(chip, value);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_4:
			switch (dc_type) {
			case DC_IP:
				rfic_wrap_wifi_rf_rx_ch_1_lna_4_dcoc_bb_dcoc_ip_setf(chip, value);
				break;
			case DC_IN:
				rfic_wrap_wifi_rf_rx_ch_1_lna_4_dcoc_bb_dcoc_in_setf(chip, value);
				break;
			case DC_QP:
				rfic_wrap_wifi_rf_rx_ch_1_lna_4_dcoc_bb_dcoc_qp_setf(chip, value);
				break;
			case DC_QN:
				rfic_wrap_wifi_rf_rx_ch_1_lna_4_dcoc_bb_dcoc_qn_setf(chip, value);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_5:
			switch (dc_type) {
			case DC_IP:
				rfic_wrap_wifi_rf_rx_ch_1_lna_5_dcoc_bb_dcoc_ip_setf(chip, value);
				break;
			case DC_IN:
				rfic_wrap_wifi_rf_rx_ch_1_lna_5_dcoc_bb_dcoc_in_setf(chip, value);
				break;
			case DC_QP:
				rfic_wrap_wifi_rf_rx_ch_1_lna_5_dcoc_bb_dcoc_qp_setf(chip, value);
				break;
			case DC_QN:
				rfic_wrap_wifi_rf_rx_ch_1_lna_5_dcoc_bb_dcoc_qn_setf(chip, value);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_6:
			switch (dc_type) {
			case DC_IP:
				rfic_wrap_wifi_rf_rx_ch_1_lna_6_dcoc_bb_dcoc_ip_setf(chip, value);
				break;
			case DC_IN:
				rfic_wrap_wifi_rf_rx_ch_1_lna_6_dcoc_bb_dcoc_in_setf(chip, value);
				break;
			case DC_QP:
				rfic_wrap_wifi_rf_rx_ch_1_lna_6_dcoc_bb_dcoc_qp_setf(chip, value);
				break;
			case DC_QN:
				rfic_wrap_wifi_rf_rx_ch_1_lna_6_dcoc_bb_dcoc_qn_setf(chip, value);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_7:
			switch (dc_type) {
			case DC_IP:
				rfic_wrap_wifi_rf_rx_ch_1_lna_7_dcoc_bb_dcoc_ip_setf(chip, value);
				break;
			case DC_IN:
				rfic_wrap_wifi_rf_rx_ch_1_lna_7_dcoc_bb_dcoc_in_setf(chip, value);
				break;
			case DC_QP:
				rfic_wrap_wifi_rf_rx_ch_1_lna_7_dcoc_bb_dcoc_qp_setf(chip, value);
				break;
			case DC_QN:
				rfic_wrap_wifi_rf_rx_ch_1_lna_7_dcoc_bb_dcoc_qn_setf(chip, value);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_8:
			switch (dc_type) {
			case DC_IP:
				rfic_wrap_wifi_rf_rx_ch_1_lna_8_dcoc_bb_dcoc_ip_setf(chip, value);
				break;
			case DC_IN:
				rfic_wrap_wifi_rf_rx_ch_1_lna_8_dcoc_bb_dcoc_in_setf(chip, value);
				break;
			case DC_QP:
				rfic_wrap_wifi_rf_rx_ch_1_lna_8_dcoc_bb_dcoc_qp_setf(chip, value);
				break;
			case DC_QN:
				rfic_wrap_wifi_rf_rx_ch_1_lna_8_dcoc_bb_dcoc_qn_setf(chip, value);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_9:
			switch (dc_type) {
			case DC_IP:
				rfic_wrap_wifi_rf_rx_ch_1_lna_9_dcoc_bb_dcoc_ip_setf(chip, value);
				break;
			case DC_IN:
				rfic_wrap_wifi_rf_rx_ch_1_lna_9_dcoc_bb_dcoc_in_setf(chip, value);
				break;
			case DC_QP:
				rfic_wrap_wifi_rf_rx_ch_1_lna_9_dcoc_bb_dcoc_qp_setf(chip, value);
				break;
			case DC_QN:
				rfic_wrap_wifi_rf_rx_ch_1_lna_9_dcoc_bb_dcoc_qn_setf(chip, value);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_10:
			switch (dc_type) {
			case DC_IP:
				rfic_wrap_wifi_rf_rx_ch_1_lna_10_dcoc_bb_dcoc_ip_setf(chip, value);
				break;
			case DC_IN:
				rfic_wrap_wifi_rf_rx_ch_1_lna_10_dcoc_bb_dcoc_in_setf(chip, value);
				break;
			case DC_QP:
				rfic_wrap_wifi_rf_rx_ch_1_lna_10_dcoc_bb_dcoc_qp_setf(chip, value);
				break;
			case DC_QN:
				rfic_wrap_wifi_rf_rx_ch_1_lna_10_dcoc_bb_dcoc_qn_setf(chip, value);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_11:
			switch (dc_type) {
			case DC_IP:
				rfic_wrap_wifi_rf_rx_ch_1_lna_11_dcoc_bb_dcoc_ip_setf(chip, value);
				break;
			case DC_IN:
				rfic_wrap_wifi_rf_rx_ch_1_lna_11_dcoc_bb_dcoc_in_setf(chip, value);
				break;
			case DC_QP:
				rfic_wrap_wifi_rf_rx_ch_1_lna_11_dcoc_bb_dcoc_qp_setf(chip, value);
				break;
			case DC_QN:
				rfic_wrap_wifi_rf_rx_ch_1_lna_11_dcoc_bb_dcoc_qn_setf(chip, value);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_12:
			switch (dc_type) {
			case DC_IP:
				rfic_wrap_wifi_rf_rx_ch_1_lna_12_dcoc_bb_dcoc_ip_setf(chip, value);
				break;
			case DC_IN:
				rfic_wrap_wifi_rf_rx_ch_1_lna_12_dcoc_bb_dcoc_in_setf(chip, value);
				break;
			case DC_QP:
				rfic_wrap_wifi_rf_rx_ch_1_lna_12_dcoc_bb_dcoc_qp_setf(chip, value);
				break;
			case DC_QN:
				rfic_wrap_wifi_rf_rx_ch_1_lna_12_dcoc_bb_dcoc_qn_setf(chip, value);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_13:
			switch (dc_type) {
			case DC_IP:
				rfic_wrap_wifi_rf_rx_ch_1_lna_13_dcoc_bb_dcoc_ip_setf(chip, value);
				break;
			case DC_IN:
				rfic_wrap_wifi_rf_rx_ch_1_lna_13_dcoc_bb_dcoc_in_setf(chip, value);
				break;
			case DC_QP:
				rfic_wrap_wifi_rf_rx_ch_1_lna_13_dcoc_bb_dcoc_qp_setf(chip, value);
				break;
			case DC_QN:
				rfic_wrap_wifi_rf_rx_ch_1_lna_13_dcoc_bb_dcoc_qn_setf(chip, value);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_14:
			switch (dc_type) {
			case DC_IP:
				rfic_wrap_wifi_rf_rx_ch_1_lna_14_dcoc_bb_dcoc_ip_setf(chip, value);
				break;
			case DC_IN:
				rfic_wrap_wifi_rf_rx_ch_1_lna_14_dcoc_bb_dcoc_in_setf(chip, value);
				break;
			case DC_QP:
				rfic_wrap_wifi_rf_rx_ch_1_lna_14_dcoc_bb_dcoc_qp_setf(chip, value);
				break;
			case DC_QN:
				rfic_wrap_wifi_rf_rx_ch_1_lna_14_dcoc_bb_dcoc_qn_setf(chip, value);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_15:
			switch (dc_type) {
			case DC_IP:
				rfic_wrap_wifi_rf_rx_ch_1_lna_15_dcoc_bb_dcoc_ip_setf(chip, value);
				break;
			case DC_IN:
				rfic_wrap_wifi_rf_rx_ch_1_lna_15_dcoc_bb_dcoc_in_setf(chip, value);
				break;
			case DC_QP:
				rfic_wrap_wifi_rf_rx_ch_1_lna_15_dcoc_bb_dcoc_qp_setf(chip, value);
				break;
			case DC_QN:
				rfic_wrap_wifi_rf_rx_ch_1_lna_15_dcoc_bb_dcoc_qn_setf(chip, value);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		default:
			cl_dbg_err(cl_hw, "Wrong input lna argument=%d\n", lna);
			return -EINVAL;
		}
		break;
	default:
		cl_dbg_err(cl_hw, "Wrong input chain argument=%d\n", ant);
		return -EINVAL;
	}

	return 0;
}

static int cl_rfic_iqdc_gain_set_tx(struct cl_hw *cl_hw, enum cl_rfic_chain ant,
				    enum cl_iq_set_tx set, enum cl_iq_gain_type gain_type,
				    u32 val)
{
	struct cl_chip *chip = cl_hw->chip;

	switch (ant) {
	case CL_RFIC_CH_0:
		switch (gain_type) {
		case CL_IQ_GAIN_TYPE_AMP:
			switch (set) {
			case CL_IQ_SET_TX_1:
				riu_iqdc_tx_0_gain_iqdc_tx_0_amp_gain_setf(chip, val);
				break;
			default:
				cl_dbg_err(cl_hw, "wrong set argument = %d\n", set);
				return -EINVAL;
			}
			break;
		case CL_IQ_GAIN_TYPE_PHASE:
			switch (set) {
			case CL_IQ_SET_TX_1:
				riu_iqdc_tx_0_gain_iqdc_tx_0_phase_gain_setf(chip, val);
				break;
			default:
				cl_dbg_err(cl_hw, "wrong set argument = %d\n", set);
				return -EINVAL;
			}
			break;
		default:
			cl_dbg_err(cl_hw, "wrong gain_type argument = %d\n", gain_type);
			break;
		}
		break;
	case CL_RFIC_CH_1:
		switch (gain_type) {
		case CL_IQ_GAIN_TYPE_AMP:
			switch (set) {
			case CL_IQ_SET_TX_1:
				riu_iqdc_tx_1_gain_iqdc_tx_1_amp_gain_setf(chip, val);
				break;
			default:
				cl_dbg_err(cl_hw, "wrong set argument = %d\n", set);
				return -EINVAL;
			}
			break;
		case CL_IQ_GAIN_TYPE_PHASE:
			switch (set) {
			case CL_IQ_SET_TX_1:
				riu_iqdc_tx_1_gain_iqdc_tx_1_phase_gain_setf(chip, val);
				break;
			default:
				cl_dbg_err(cl_hw, "wrong set argument = %d\n", set);
				return -EINVAL;
			}
			break;
		default:
			cl_dbg_err(cl_hw, "wrong gain_type argument = %d\n", gain_type);
			return -EINVAL;
		}
		break;
	default:
		cl_dbg_err(cl_hw, "wrong ant argument = %d\n", ant);
		return -EINVAL;
	}

	return 0;
}

int cl_rfic_get_iq_coeff(struct cl_hw *cl_hw, s32 *params, u16 *val)
{
	int ret = 0;
	u8 ant = (u8)params[0];
	enum cl_iq_direction dir = (enum cl_iq_direction)params[1];
	enum cl_iq_set_rx set_rx;
	enum cl_iq_set_tx set_tx;
	enum cl_fir_coeff_rx coeff_rx;
	enum cl_fir_coeff_tx coeff_tx;

	if (ant >= MAX_ANTENNAS) {
		cl_dbg_err(cl_hw, "Invalid ant=%d\n", ant);
		return -EINVAL;
	}

	if (dir >= CL_IQ_DIRECTION_MAX) {
		cl_dbg_err(cl_hw, "Invalid direction=%d\n", dir);
		return -EINVAL;
	}

	if (dir == CL_IQ_DIRECTION_RX) {
		set_rx = (enum cl_iq_set_rx)params[2];
		coeff_rx = (enum cl_fir_coeff_rx)params[3];

		if (set_rx >= CL_IQ_SET_RX_MAX) {
			cl_dbg_err(cl_hw, "Invalid set_rx=%d\n", set_rx);
			return -EINVAL;
		}

		if (coeff_rx >= CL_FIR_COEFF_RX_MAX) {
			cl_dbg_err(cl_hw, "Invalid coeff_rx=%d\n", coeff_rx);
			return -EINVAL;
		}

		if (ant == 0)
			ret = cl_rfic_get_iqdc_set_rx_0_coeff(cl_hw, set_rx, coeff_rx, val);
		else
			ret = cl_rfic_get_iqdc_set_rx_1_coeff(cl_hw, set_rx, coeff_rx, val);
	} else {
		set_tx = (enum cl_iq_set_tx)params[2];
		coeff_tx = (enum cl_fir_coeff_tx)params[3];

		if (set_tx >= CL_IQ_SET_TX_MAX) {
			cl_dbg_err(cl_hw, "Invalid set_tx=%d\n", set_tx);
			return -EINVAL;
		}

		if (coeff_tx >= CL_FIR_COEFF_TX_MAX) {
			cl_dbg_err(cl_hw, "Invalid coeff_tx=%d\n", coeff_tx);
			return -EINVAL;
		}

		if (ant == 0)
			ret = cl_rfic_get_iqdc_set_tx_0_coeff(cl_hw, coeff_tx, val);
		else
			ret = cl_rfic_get_iqdc_set_tx_1_coeff(cl_hw, coeff_tx, val);
	}

	return ret;
}

static int cl_rfic_set_iq_gain(struct cl_hw *cl_hw, enum cl_rfic_chain ant,
			       enum cl_iq_direction direction, u8 set,
			       enum cl_iq_gain_type gain_type, u32 val)
{
	enum cl_iq_set_rx set_rx;
	enum cl_iq_set_tx set_tx;
	int ret = 0;

	if (ant >= MAX_ANTENNAS) {
		cl_dbg_err(cl_hw, "Invalid ant=%d\n", ant);
		return -EINVAL;
	}

	if (direction >= CL_IQ_DIRECTION_MAX) {
		cl_dbg_err(cl_hw, "Invalid direction=%d - should be 0:rx|1:tx\n", direction);
		return -EINVAL;
	}

	if (gain_type >= CL_IQ_GAIN_TYPE_MAX) {
		cl_dbg_err(cl_hw,
			   "Invalid gain type=%d - should be 0:amp|1:phase\n",
			   gain_type);
		return -EINVAL;
	}

	if (direction == CL_IQ_DIRECTION_RX) {
		if (set >= CL_IQ_SET_RX_MAX) {
			cl_dbg_err(cl_hw, "Invalid set=%u - should be 1-3\n", set);
			return -EINVAL;
		}

		set_rx = (enum cl_iq_set_rx)set;
		ret = cl_rfic_iqdc_gain_set_rx(cl_hw, ant, set_rx, gain_type, val);
	} else {
		if (set >= CL_IQ_SET_TX_MAX) {
			cl_dbg_err(cl_hw, "Invalid set=%u - should be 1\n", set);
			return -EINVAL;
		}

		set_tx = (enum cl_iq_set_tx)set;
		ret = cl_rfic_iqdc_gain_set_tx(cl_hw, ant, set_tx, gain_type, val);
	}

	return ret;
}

static int cl_rfic_get_iq_coeff_cli(struct cl_hw *cl_hw, s32 *params)
{
	char reply_str[STR_LEN_32B] = {0};
	int ret;
	u16 val;

	ret = cl_rfic_get_iq_coeff(cl_hw, params, &val);
	if (ret < 0)
		return ret;

	snprintf(&reply_str[0], sizeof(reply_str), "0x%x", val);

	return cl_vendor_reply(cl_hw, reply_str, sizeof(reply_str));
}

static int cl_rfic_set_iqdc_set_rx_0_coeff(struct cl_hw *cl_hw, enum cl_iq_set_rx set,
					   enum  cl_fir_coeff_rx coeff, u16 val)
{
	int i;
	struct cl_chip *chip = cl_hw->chip;
	int sz = ARRAY_SIZE(rx_0_coeff);

	for (i = 0; i < sz; i++) {
		if (coeff == rx_0_coeff[i].fir_coeff && set == rx_0_coeff[i].set_rx) {
			rx_0_coeff[i].set_iqdc_rx_coeff(chip, val);
			break;
		}
	}

	return 0;
}

static int cl_rfic_set_iqdc_set_rx_1_coeff(struct cl_hw *cl_hw, enum cl_iq_set_rx set,
					   enum  cl_fir_coeff_rx coeff, u16 val)
{
	int i;
	struct cl_chip *chip = cl_hw->chip;
	int sz = ARRAY_SIZE(rx_1_coeff);

	for (i = 0; i < sz; i++) {
		if (coeff == rx_1_coeff[i].fir_coeff && set == rx_1_coeff[i].set_rx) {
			rx_1_coeff[i].set_iqdc_rx_coeff(chip, val);
			break;
		}
	}

	return 0;
}

static int cl_rfic_iqdc_gain_get_rx(struct cl_hw *cl_hw, enum cl_rfic_chain ant,
				    enum cl_iq_set_rx set, enum cl_iq_gain_type gain_type,
				    int *val)
{
	struct cl_chip *chip = cl_hw->chip;

	switch (ant) {
	case CL_RFIC_CH_0:
		switch (gain_type) {
		case CL_IQ_GAIN_TYPE_AMP:
			switch (set) {
			case CL_IQ_SET_RX_1:
				*val = riu_iqdc_rx_0_gain_set_1_iqdc_rx_0_amp_gain_getf(chip);
				break;
			case CL_IQ_SET_RX_2:
				*val = riu_iqdc_rx_0_gain_set_2_iqdc_rx_0_amp_gain_getf(chip);
				break;
			case CL_IQ_SET_RX_3:
				*val = riu_iqdc_rx_0_gain_set_3_iqdc_rx_0_amp_gain_getf(chip);
				break;
			default:
				cl_dbg_err(cl_hw, "wrong set argument = %d\n", set);
				return -EINVAL;
			}
			break;
		case CL_IQ_GAIN_TYPE_PHASE:
			switch (set) {
			case CL_IQ_SET_RX_1:
				*val = riu_iqdc_rx_0_gain_set_1_iqdc_rx_0_phase_gain_getf(chip);
				break;
			case CL_IQ_SET_RX_2:
				*val = riu_iqdc_rx_0_gain_set_2_iqdc_rx_0_phase_gain_getf(chip);
				break;
			case CL_IQ_SET_RX_3:
				*val = riu_iqdc_rx_0_gain_set_3_iqdc_rx_0_phase_gain_getf(chip);
				break;
			default:
				cl_dbg_err(cl_hw, "wrong set argument = %d\n", set);
				return -EINVAL;
			}
			break;
		default:
			cl_dbg_err(cl_hw, "wrong gain_type argument = %d\n", gain_type);
			return -EINVAL;
		}
		break;
	case CL_RFIC_CH_1:
		switch (gain_type) {
		case CL_IQ_GAIN_TYPE_AMP:
			switch (set) {
			case CL_IQ_SET_RX_1:
				*val = riu_iqdc_rx_1_gain_set_1_iqdc_rx_1_amp_gain_getf(chip);
				break;
			case CL_IQ_SET_RX_2:
				*val = riu_iqdc_rx_1_gain_set_2_iqdc_rx_1_amp_gain_getf(chip);
				break;
			case CL_IQ_SET_RX_3:
				*val = riu_iqdc_rx_1_gain_set_3_iqdc_rx_1_amp_gain_getf(chip);
				break;
			default:
				cl_dbg_err(cl_hw, "wrong set argument = %d\n", set);
				return -EINVAL;
			}
			break;
		case CL_IQ_GAIN_TYPE_PHASE:
			switch (set) {
			case CL_IQ_SET_RX_1:
				*val = riu_iqdc_rx_1_gain_set_1_iqdc_rx_1_phase_gain_getf(chip);
				break;
			case CL_IQ_SET_RX_2:
				*val = riu_iqdc_rx_1_gain_set_2_iqdc_rx_1_phase_gain_getf(chip);
				break;
			case CL_IQ_SET_RX_3:
				*val = riu_iqdc_rx_1_gain_set_3_iqdc_rx_1_phase_gain_getf(chip);
				break;
			default:
				cl_dbg_err(cl_hw, "wrong set argument = %d\n", set);
				return -EINVAL;
			}
			break;
		default:
			cl_dbg_err(cl_hw, "wrong gain_type argument = %d\n", gain_type);
			return -EINVAL;
		}
		break;
	default:
		cl_dbg_err(cl_hw, "wrong ant argument = %d\n", ant);
		return -EINVAL;
	}

	return 0;
}

static int cl_rfic_set_iqdc_set_tx_0_coeff(struct cl_hw *cl_hw, enum  cl_fir_coeff_tx coeff,
					   u16 val)
{
	int i;
	struct cl_chip *chip = cl_hw->chip;
	int sz = ARRAY_SIZE(tx_0_coeff);

	for (i = 0; i < sz; i++) {
		if (coeff == tx_0_coeff[i].fir_coeff) {
			tx_0_coeff[i].set_iqdc_tx_coeff(chip, val);
			break;
		}
	}

	return 0;
}

static int cl_rfic_set_iqdc_set_tx_1_coeff(struct cl_hw *cl_hw, enum  cl_fir_coeff_tx coeff,
					   u16 val)
{
	int i;
	struct cl_chip *chip = cl_hw->chip;
	int sz = ARRAY_SIZE(tx_1_coeff);

	for (i = 0; i < sz; i++) {
		if (coeff == tx_1_coeff[i].fir_coeff) {
			tx_1_coeff[i].set_iqdc_tx_coeff(chip, val);
			break;
		}
	}

	return 0;
}

static int cl_rfic_set_dcoc(struct cl_hw *cl_hw, enum cl_rfic_chain ant, enum cl_rfic_lna lna,
			    enum calib_dc_type dc_type, u8 value)
{
	int ret = 0;

	if (ant >= MAX_ANTENNAS) {
		cl_dbg_err(cl_hw, "Invalid ant %d\n", ant);
		return -EINVAL;
	}

	if (lna > DCOC_LNA_GAIN_NUM) {
		cl_dbg_err(cl_hw, "Invalid lna %d\n", lna);
		return -EINVAL;
	}

	if (dc_type >= DC_TYPE_MAX) {
		cl_dbg_err(cl_hw, "Invalid dc type %d\n", dc_type);
		return -EINVAL;
	}

	if (value > RX_BB_DCOC_MAX_VAL) {
		cl_dbg_err(cl_hw, "Invalid value %u\n", value);
		return -EINVAL;
	}

	ret = cl_rfic_wrap_dcoc_set(cl_hw, ant, lna, dc_type, value);

	return ret;
}

static int cl_rfic_wrap_dcoc_get(struct cl_hw *cl_hw, enum cl_rfic_chain ant,
				 enum cl_rfic_lna lna, enum calib_dc_type dc_type, u8 *val)
{
	struct cl_chip *chip = cl_hw->chip;

	switch (ant) {
	case CL_RFIC_CH_0:
		switch (lna) {
		case CL_RFIC_LNA_0:
			switch (dc_type) {
			case DC_IP:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_0_dcoc_bb_dcoc_ip_getf(chip);
				break;
			case DC_IN:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_0_dcoc_bb_dcoc_in_getf(chip);
				break;
			case DC_QP:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_0_dcoc_bb_dcoc_qp_getf(chip);
				break;
			case DC_QN:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_0_dcoc_bb_dcoc_qn_getf(chip);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_1:
			switch (dc_type) {
			case DC_IP:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_1_dcoc_bb_dcoc_ip_getf(chip);
				break;
			case DC_IN:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_1_dcoc_bb_dcoc_in_getf(chip);
				break;
			case DC_QP:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_1_dcoc_bb_dcoc_qp_getf(chip);
				break;
			case DC_QN:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_1_dcoc_bb_dcoc_qn_getf(chip);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_2:
			switch (dc_type) {
			case DC_IP:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_2_dcoc_bb_dcoc_ip_getf(chip);
				break;
			case DC_IN:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_2_dcoc_bb_dcoc_in_getf(chip);
				break;
			case DC_QP:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_2_dcoc_bb_dcoc_qp_getf(chip);
				break;
			case DC_QN:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_2_dcoc_bb_dcoc_qn_getf(chip);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_3:
			switch (dc_type) {
			case DC_IP:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_3_dcoc_bb_dcoc_ip_getf(chip);
				break;
			case DC_IN:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_3_dcoc_bb_dcoc_in_getf(chip);
				break;
			case DC_QP:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_3_dcoc_bb_dcoc_qp_getf(chip);
				break;
			case DC_QN:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_3_dcoc_bb_dcoc_qn_getf(chip);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_4:
			switch (dc_type) {
			case DC_IP:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_4_dcoc_bb_dcoc_ip_getf(chip);
				break;
			case DC_IN:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_4_dcoc_bb_dcoc_in_getf(chip);
				break;
			case DC_QP:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_4_dcoc_bb_dcoc_qp_getf(chip);
				break;
			case DC_QN:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_4_dcoc_bb_dcoc_qn_getf(chip);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_5:
			switch (dc_type) {
			case DC_IP:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_5_dcoc_bb_dcoc_ip_getf(chip);
				break;
			case DC_IN:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_5_dcoc_bb_dcoc_in_getf(chip);
				break;
			case DC_QP:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_5_dcoc_bb_dcoc_qp_getf(chip);
				break;
			case DC_QN:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_5_dcoc_bb_dcoc_qn_getf(chip);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_6:
			switch (dc_type) {
			case DC_IP:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_6_dcoc_bb_dcoc_ip_getf(chip);
				break;
			case DC_IN:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_6_dcoc_bb_dcoc_in_getf(chip);
				break;
			case DC_QP:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_6_dcoc_bb_dcoc_qp_getf(chip);
				break;
			case DC_QN:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_6_dcoc_bb_dcoc_qn_getf(chip);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_7:
			switch (dc_type) {
			case DC_IP:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_7_dcoc_bb_dcoc_ip_getf(chip);
				break;
			case DC_IN:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_7_dcoc_bb_dcoc_in_getf(chip);
				break;
			case DC_QP:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_7_dcoc_bb_dcoc_qp_getf(chip);
				break;
			case DC_QN:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_7_dcoc_bb_dcoc_qn_getf(chip);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_8:
			switch (dc_type) {
			case DC_IP:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_8_dcoc_bb_dcoc_ip_getf(chip);
				break;
			case DC_IN:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_8_dcoc_bb_dcoc_in_getf(chip);
				break;
			case DC_QP:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_8_dcoc_bb_dcoc_qp_getf(chip);
				break;
			case DC_QN:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_8_dcoc_bb_dcoc_qn_getf(chip);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_9:
			switch (dc_type) {
			case DC_IP:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_9_dcoc_bb_dcoc_ip_getf(chip);
				break;
			case DC_IN:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_9_dcoc_bb_dcoc_in_getf(chip);
				break;
			case DC_QP:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_9_dcoc_bb_dcoc_qp_getf(chip);
				break;
			case DC_QN:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_9_dcoc_bb_dcoc_qn_getf(chip);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_10:
			switch (dc_type) {
			case DC_IP:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_10_dcoc_bb_dcoc_ip_getf(chip);
				break;
			case DC_IN:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_10_dcoc_bb_dcoc_in_getf(chip);
				break;
			case DC_QP:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_10_dcoc_bb_dcoc_qp_getf(chip);
				break;
			case DC_QN:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_10_dcoc_bb_dcoc_qn_getf(chip);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_11:
			switch (dc_type) {
			case DC_IP:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_11_dcoc_bb_dcoc_ip_getf(chip);
				break;
			case DC_IN:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_11_dcoc_bb_dcoc_in_getf(chip);
				break;
			case DC_QP:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_11_dcoc_bb_dcoc_qp_getf(chip);
				break;
			case DC_QN:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_11_dcoc_bb_dcoc_qn_getf(chip);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_12:
			switch (dc_type) {
			case DC_IP:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_12_dcoc_bb_dcoc_ip_getf(chip);
				break;
			case DC_IN:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_12_dcoc_bb_dcoc_in_getf(chip);
				break;
			case DC_QP:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_12_dcoc_bb_dcoc_qp_getf(chip);
				break;
			case DC_QN:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_12_dcoc_bb_dcoc_qn_getf(chip);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_13:
			switch (dc_type) {
			case DC_IP:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_13_dcoc_bb_dcoc_ip_getf(chip);
				break;
			case DC_IN:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_13_dcoc_bb_dcoc_in_getf(chip);
				break;
			case DC_QP:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_13_dcoc_bb_dcoc_qp_getf(chip);
				break;
			case DC_QN:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_13_dcoc_bb_dcoc_qn_getf(chip);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_14:
			switch (dc_type) {
			case DC_IP:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_14_dcoc_bb_dcoc_ip_getf(chip);
				break;
			case DC_IN:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_14_dcoc_bb_dcoc_in_getf(chip);
				break;
			case DC_QP:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_14_dcoc_bb_dcoc_qp_getf(chip);
				break;
			case DC_QN:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_14_dcoc_bb_dcoc_qn_getf(chip);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_15:
			switch (dc_type) {
			case DC_IP:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_15_dcoc_bb_dcoc_ip_getf(chip);
				break;
			case DC_IN:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_15_dcoc_bb_dcoc_in_getf(chip);
				break;
			case DC_QP:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_15_dcoc_bb_dcoc_qp_getf(chip);
				break;
			case DC_QN:
				*val = rfic_wrap_wifi_rf_rx_ch_0_lna_15_dcoc_bb_dcoc_qn_getf(chip);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		default:
			cl_dbg_err(cl_hw, "Wrong input lna argument=%d\n", lna);
			break;
		}
		break;
	case CL_RFIC_CH_1:
		switch (lna) {
		case CL_RFIC_LNA_0:
			switch (dc_type) {
			case DC_IP:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_0_dcoc_bb_dcoc_ip_getf(chip);
				break;
			case DC_IN:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_0_dcoc_bb_dcoc_in_getf(chip);
				break;
			case DC_QP:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_0_dcoc_bb_dcoc_qp_getf(chip);
				break;
			case DC_QN:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_0_dcoc_bb_dcoc_qn_getf(chip);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_1:
			switch (dc_type) {
			case DC_IP:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_1_dcoc_bb_dcoc_ip_getf(chip);
				break;
			case DC_IN:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_1_dcoc_bb_dcoc_in_getf(chip);
				break;
			case DC_QP:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_1_dcoc_bb_dcoc_qp_getf(chip);
				break;
			case DC_QN:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_1_dcoc_bb_dcoc_qn_getf(chip);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_2:
			switch (dc_type) {
			case DC_IP:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_2_dcoc_bb_dcoc_ip_getf(chip);
				break;
			case DC_IN:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_2_dcoc_bb_dcoc_in_getf(chip);
				break;
			case DC_QP:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_2_dcoc_bb_dcoc_qp_getf(chip);
				break;
			case DC_QN:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_2_dcoc_bb_dcoc_qn_getf(chip);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_3:
			switch (dc_type) {
			case DC_IP:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_3_dcoc_bb_dcoc_ip_getf(chip);
				break;
			case DC_IN:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_3_dcoc_bb_dcoc_in_getf(chip);
				break;
			case DC_QP:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_3_dcoc_bb_dcoc_qp_getf(chip);
				break;
			case DC_QN:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_3_dcoc_bb_dcoc_qn_getf(chip);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_4:
			switch (dc_type) {
			case DC_IP:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_4_dcoc_bb_dcoc_ip_getf(chip);
				break;
			case DC_IN:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_4_dcoc_bb_dcoc_in_getf(chip);
				break;
			case DC_QP:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_4_dcoc_bb_dcoc_qp_getf(chip);
				break;
			case DC_QN:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_4_dcoc_bb_dcoc_qn_getf(chip);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_5:
			switch (dc_type) {
			case DC_IP:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_5_dcoc_bb_dcoc_ip_getf(chip);
				break;
			case DC_IN:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_5_dcoc_bb_dcoc_in_getf(chip);
				break;
			case DC_QP:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_5_dcoc_bb_dcoc_qp_getf(chip);
				break;
			case DC_QN:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_5_dcoc_bb_dcoc_qn_getf(chip);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_6:
			switch (dc_type) {
			case DC_IP:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_6_dcoc_bb_dcoc_ip_getf(chip);
				break;
			case DC_IN:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_6_dcoc_bb_dcoc_in_getf(chip);
				break;
			case DC_QP:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_6_dcoc_bb_dcoc_qp_getf(chip);
				break;
			case DC_QN:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_6_dcoc_bb_dcoc_qn_getf(chip);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_7:
			switch (dc_type) {
			case DC_IP:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_7_dcoc_bb_dcoc_ip_getf(chip);
				break;
			case DC_IN:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_7_dcoc_bb_dcoc_in_getf(chip);
				break;
			case DC_QP:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_7_dcoc_bb_dcoc_qp_getf(chip);
				break;
			case DC_QN:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_7_dcoc_bb_dcoc_qn_getf(chip);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_8:
			switch (dc_type) {
			case DC_IP:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_8_dcoc_bb_dcoc_ip_getf(chip);
				break;
			case DC_IN:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_8_dcoc_bb_dcoc_in_getf(chip);
				break;
			case DC_QP:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_8_dcoc_bb_dcoc_qp_getf(chip);
				break;
			case DC_QN:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_8_dcoc_bb_dcoc_qn_getf(chip);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_9:
			switch (dc_type) {
			case DC_IP:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_9_dcoc_bb_dcoc_ip_getf(chip);
				break;
			case DC_IN:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_9_dcoc_bb_dcoc_in_getf(chip);
				break;
			case DC_QP:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_9_dcoc_bb_dcoc_qp_getf(chip);
				break;
			case DC_QN:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_9_dcoc_bb_dcoc_qn_getf(chip);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_10:
			switch (dc_type) {
			case DC_IP:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_10_dcoc_bb_dcoc_ip_getf(chip);
				break;
			case DC_IN:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_10_dcoc_bb_dcoc_in_getf(chip);
				break;
			case DC_QP:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_10_dcoc_bb_dcoc_qp_getf(chip);
				break;
			case DC_QN:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_10_dcoc_bb_dcoc_qn_getf(chip);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_11:
			switch (dc_type) {
			case DC_IP:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_11_dcoc_bb_dcoc_ip_getf(chip);
				break;
			case DC_IN:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_11_dcoc_bb_dcoc_in_getf(chip);
				break;
			case DC_QP:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_11_dcoc_bb_dcoc_qp_getf(chip);
				break;
			case DC_QN:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_11_dcoc_bb_dcoc_qn_getf(chip);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_12:
			switch (dc_type) {
			case DC_IP:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_12_dcoc_bb_dcoc_ip_getf(chip);
				break;
			case DC_IN:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_12_dcoc_bb_dcoc_in_getf(chip);
				break;
			case DC_QP:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_12_dcoc_bb_dcoc_qp_getf(chip);
				break;
			case DC_QN:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_12_dcoc_bb_dcoc_qn_getf(chip);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_13:
			switch (dc_type) {
			case DC_IP:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_13_dcoc_bb_dcoc_ip_getf(chip);
				break;
			case DC_IN:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_13_dcoc_bb_dcoc_in_getf(chip);
				break;
			case DC_QP:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_13_dcoc_bb_dcoc_qp_getf(chip);
				break;
			case DC_QN:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_13_dcoc_bb_dcoc_qn_getf(chip);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_14:
			switch (dc_type) {
			case DC_IP:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_14_dcoc_bb_dcoc_ip_getf(chip);
				break;
			case DC_IN:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_14_dcoc_bb_dcoc_in_getf(chip);
				break;
			case DC_QP:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_14_dcoc_bb_dcoc_qp_getf(chip);
				break;
			case DC_QN:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_14_dcoc_bb_dcoc_qn_getf(chip);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		case CL_RFIC_LNA_15:
			switch (dc_type) {
			case DC_IP:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_15_dcoc_bb_dcoc_ip_getf(chip);
				break;
			case DC_IN:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_15_dcoc_bb_dcoc_in_getf(chip);
				break;
			case DC_QP:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_15_dcoc_bb_dcoc_qp_getf(chip);
				break;
			case DC_QN:
				*val = rfic_wrap_wifi_rf_rx_ch_1_lna_15_dcoc_bb_dcoc_qn_getf(chip);
				break;
			default:
				cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
				return -EINVAL;
			}
			break;
		default:
			cl_dbg_err(cl_hw, "Wrong input lna argument=%d\n", lna);
			return -EINVAL;
		}
		break;
	default:
		cl_dbg_err(cl_hw, "Wrong input chain argument=%d\n", ant);
		return -EINVAL;
	}

	return 0;
}

static int cl_rfic_iqdc_gain_get_tx(struct cl_hw *cl_hw, enum cl_rfic_chain ant,
				    enum cl_iq_set_tx set, enum cl_iq_gain_type gain_type,
				    int *val)
{
	struct cl_chip *chip = cl_hw->chip;

	switch (ant) {
	case CL_RFIC_CH_0:
		switch (gain_type) {
		case CL_IQ_GAIN_TYPE_AMP:
			switch (set) {
			case CL_IQ_SET_TX_1:
				*val = riu_iqdc_tx_0_gain_iqdc_tx_0_amp_gain_getf(chip);
				break;
			default:
				cl_dbg_err(cl_hw, "wrong set argument = %d\n", set);
				return -EINVAL;
			}
			break;
		case CL_IQ_GAIN_TYPE_PHASE:
			switch (set) {
			case CL_IQ_SET_TX_1:
				*val = riu_iqdc_tx_0_gain_iqdc_tx_0_phase_gain_getf(chip);
				break;
			default:
				cl_dbg_err(cl_hw, "wrong set argument = %d\n", set);
				return -EINVAL;
			}
			break;
		default:
			cl_dbg_err(cl_hw, "wrong gain_type argument = %d\n", gain_type);
			return -EINVAL;
		}
		break;
	case CL_RFIC_CH_1:
		switch (gain_type) {
		case CL_IQ_GAIN_TYPE_AMP:
			switch (set) {
			case CL_IQ_SET_TX_1:
				*val = riu_iqdc_tx_1_gain_iqdc_tx_1_amp_gain_getf(chip);
				break;
			default:
				cl_dbg_err(cl_hw, "wrong set argument = %d\n", set);
				return -EINVAL;
			}
			break;
		case CL_IQ_GAIN_TYPE_PHASE:
			switch (set) {
			case CL_IQ_SET_TX_1:
				*val = riu_iqdc_tx_1_gain_iqdc_tx_1_phase_gain_getf(chip);
				break;
			default:
				cl_dbg_err(cl_hw, "wrong set argument = %d\n", set);
				return -EINVAL;
			}
			break;
		default:
			cl_dbg_err(cl_hw, "wrong gain_type argument = %d\n", gain_type);
			return -EINVAL;
		}
		break;
	default:
		cl_dbg_err(cl_hw, "wrong ant argument = %d\n", ant);
		return -EINVAL;
	}

	return 0;
}

int cl_rfic_set_iq_coeff_cli(struct cl_hw *cl_hw, s32 *params)
{
	int ret = 0;
	u8 ant = (u8)params[0];
	enum cl_iq_direction dir = (enum cl_iq_direction)params[1];
	enum cl_iq_set_rx set_rx;
	enum cl_iq_set_tx set_tx;
	enum cl_fir_coeff_rx coeff_rx;
	enum cl_fir_coeff_tx coeff_tx;
	u16 val = (u16)params[4];

	if (ant >= MAX_ANTENNAS) {
		cl_dbg_err(cl_hw, "Invalid ant %u\n", ant);
		return -EINVAL;
	}

	if (dir >= CL_IQ_DIRECTION_MAX) {
		cl_dbg_err(cl_hw, "Invalid direction %u\n", dir);
		return -EINVAL;
	}

	if (dir == CL_IQ_DIRECTION_RX) {
		set_rx = (enum cl_iq_set_rx)params[2];
		coeff_rx = (enum cl_fir_coeff_rx)params[3];

		if (set_rx >= CL_IQ_SET_RX_MAX) {
			cl_dbg_err(cl_hw, "Invalid set_rx=%d\n", set_rx);
			return -EINVAL;
		}

		if (coeff_rx >= CL_FIR_COEFF_RX_MAX) {
			cl_dbg_err(cl_hw, "Invalid coeff_rx=%d\n", coeff_rx);
			return -EINVAL;
		}

		if (ant == 0)
			ret = cl_rfic_set_iqdc_set_rx_0_coeff(cl_hw, set_rx, coeff_rx, val);
		else
			ret = cl_rfic_set_iqdc_set_rx_1_coeff(cl_hw, set_rx, coeff_rx, val);
	} else {
		set_tx = (enum cl_iq_set_tx)params[2];
		coeff_tx = (enum cl_fir_coeff_tx)params[3];

		if (set_tx >= CL_IQ_SET_TX_MAX) {
			cl_dbg_err(cl_hw, "Invalid set_tx=%d\n", set_tx);
			return -EINVAL;
		}

		if (coeff_tx >= CL_FIR_COEFF_TX_MAX) {
			cl_dbg_err(cl_hw, "Invalid coeff_tx=%d\n", coeff_tx);
			return -EINVAL;
		}

		if (ant == 0)
			ret = cl_rfic_set_iqdc_set_tx_0_coeff(cl_hw, coeff_tx, val);
		else
			ret = cl_rfic_set_iqdc_set_tx_1_coeff(cl_hw, coeff_tx, val);
	}

	return ret;
}

static int cl_rfic_read_dcoc(struct cl_hw *cl_hw, enum cl_rfic_chain ant, enum cl_rfic_lna lna,
			     enum calib_dc_type dc_type)
{
	int ret = 0;
	u8 val = 0;
	char reply_str[STR_LEN_32B] = {0};

	if (ant >= MAX_ANTENNAS) {
		cl_dbg_err(cl_hw, "Invalid ant %d\n", ant);
		return -EINVAL;
	}

	if (lna > DCOC_LNA_GAIN_NUM) {
		cl_dbg_err(cl_hw, "Invalid lna %d\n", lna);
		return -EINVAL;
	}

	if (dc_type >= DC_TYPE_MAX) {
		cl_dbg_err(cl_hw, "Invalid dc type %d\n", dc_type);
		return -EINVAL;
	}

	ret = cl_rfic_wrap_dcoc_get(cl_hw, ant, lna, dc_type, &val);
	if (ret < 0)
		return ret;

	snprintf(&reply_str[0], sizeof(reply_str), "0x%x", val);

	return cl_vendor_reply(cl_hw, reply_str, sizeof(reply_str));
}

static int cl_rfic_get_iq_gain_cli(struct cl_hw *cl_hw, s32 *params)
{
	char reply_str[STR_LEN_32B] = {0};
	s32 val = 0;
	enum cl_iq_set_rx set_rx;
	enum cl_iq_set_tx set_tx;
	enum cl_rfic_chain ant = (enum cl_rfic_chain)params[0];
	enum cl_iq_direction direction = (enum cl_iq_direction)params[1];
	u8 set = (u8)params[2];
	enum cl_iq_gain_type gain_type = (enum cl_iq_gain_type)params[3];
	int ret = 0;

	if (ant >= MAX_ANTENNAS) {
		cl_dbg_err(cl_hw, "Invalid ant=%d\n", ant);
		return -EINVAL;
	}

	if (direction >= CL_IQ_DIRECTION_MAX) {
		cl_dbg_err(cl_hw, "Invalid direction=%d - should be 0:rx|1:tx\n", direction);
		return -EINVAL;
	}

	if (gain_type >= CL_IQ_GAIN_TYPE_MAX) {
		cl_dbg_err(cl_hw, "Invalid gain type=%d - should be 0:amp|1:phase\n", gain_type);
		return -EINVAL;
	}

	if (direction == CL_IQ_DIRECTION_RX) {
		if (set >= CL_IQ_SET_RX_MAX) {
			cl_dbg_err(cl_hw, "Invalid set=%u - should be 1-3\n", set);
			return -EINVAL;
		}

		set_rx = (enum cl_iq_set_rx)set;
		ret = cl_rfic_iqdc_gain_get_rx(cl_hw, ant, set_rx, gain_type, &val);
	} else {
		if (set >= CL_IQ_SET_TX_MAX) {
			cl_dbg_err(cl_hw, "Invalid set=%u - should be 1\n", set);
			return -EINVAL;
		}

		set_tx = (enum cl_iq_set_tx)set;
		ret = cl_rfic_iqdc_gain_get_tx(cl_hw, ant, set_tx, gain_type, &val);
	}

	if (ret < 0)
		return ret;

	snprintf(&reply_str[0], sizeof(reply_str), "0x%x", val);

	return cl_vendor_reply(cl_hw, reply_str, sizeof(reply_str));
}

static int cl_rfic_set_iqdc(struct cl_hw *cl_hw, enum cl_rfic_chain ant,
			    enum cl_iq_dc_type dc_type, s32 val)
{
	struct cl_chip *chip = cl_hw->chip;

	switch (ant) {
	case CL_RFIC_CH_0:
		switch (dc_type) {
		case CL_IQ_DC_TYPE_I:
			riu_iqdc_tx_0_dc_iqdc_tx_0_dci_setf(chip, val);
			break;
		case CL_IQ_DC_TYPE_Q:
			riu_iqdc_tx_0_dc_iqdc_tx_0_dcq_setf(chip, val);
			break;
		default:
			cl_dbg_err(cl_hw, "Invalid dc type %u\n", dc_type);
			return -EINVAL;
		}
		break;
	case CL_RFIC_CH_1:
		switch (dc_type) {
		case CL_IQ_DC_TYPE_I:
			riu_iqdc_tx_1_dc_iqdc_tx_1_dci_setf(chip, val);
			break;
		case CL_IQ_DC_TYPE_Q:
			riu_iqdc_tx_1_dc_iqdc_tx_1_dcq_setf(chip, val);
			break;
		default:
			cl_dbg_err(cl_hw, "Invalid dc type %u\n", dc_type);
			return -EINVAL;
		}
		break;
	default:
		cl_dbg_err(cl_hw, "Invalid chain type %u\n", ant);
		return -EINVAL;
	}

	return 0;
}

static int cl_rfic_set_iqdc_cli(struct cl_hw *cl_hw, s32 *params)
{
	int ret = 0;
	u8 ant = (enum cl_rfic_chain)params[0];
	u8 dc_type = (enum cl_iq_dc_type)params[1];
	s32 val = (s32)params[2];

	if (ant >= MAX_ANTENNAS) {
		cl_dbg_err(cl_hw, "Invalid ant=%d\n", ant);
		return -EINVAL;
	}

	if (dc_type >= CL_IQ_DC_TYPE_MAX) {
		cl_dbg_err(cl_hw, "Invalid dc type=%d\n", dc_type);
		return -EINVAL;
	}

	ret = cl_rfic_set_iqdc(cl_hw, ant, dc_type, val);

	return ret;
}

static int cl_rfic_get_iqdc(struct cl_hw *cl_hw, enum cl_rfic_chain ant,
			    enum cl_iq_dc_type dc_type, s32 *val)
{
	struct cl_chip *chip = cl_hw->chip;

	switch (ant) {
	case CL_RFIC_CH_0:
		switch (dc_type) {
		case CL_IQ_DC_TYPE_I:
			*val = riu_iqdc_tx_0_dc_iqdc_tx_0_dci_getf(chip);
			break;
		case CL_IQ_DC_TYPE_Q:
			*val = riu_iqdc_tx_0_dc_iqdc_tx_0_dcq_getf(chip);
			break;
		default:
			cl_dbg_err(cl_hw, "Invalid dc type %u\n", dc_type);
			return -EINVAL;
		}
		break;
	case CL_RFIC_CH_1:
		switch (dc_type) {
		case CL_IQ_DC_TYPE_I:
			*val = riu_iqdc_tx_1_dc_iqdc_tx_1_dci_getf(chip);
			break;
		case CL_IQ_DC_TYPE_Q:
			*val = riu_iqdc_tx_1_dc_iqdc_tx_1_dcq_getf(chip);
			break;
		default:
			cl_dbg_err(cl_hw, "Invalid dc type %u\n", dc_type);
			return -EINVAL;
		}
		break;
	default:
		cl_dbg_err(cl_hw, "Invalid chain type %u\n", ant);
		return -EINVAL;
	}

	return 0;
}

int cl_rfic_get_iqdc_cli(struct cl_hw *cl_hw, s32 *params)
{
	char reply_str[STR_LEN_32B] = {0};
	int ret = 0;
	s32 val;
	u8 ant = (enum cl_rfic_chain)params[0];
	u8 dc_type = (enum cl_iq_dc_type)params[1];

	if (ant >= MAX_ANTENNAS) {
		cl_dbg_err(cl_hw, "Invalid ant=%d\n", ant);
		return -EINVAL;
	}

	if (dc_type >= CL_IQ_DC_TYPE_MAX) {
		cl_dbg_err(cl_hw, "Invalid dc type=%d\n", dc_type);
		return -EINVAL;
	}

	ret = cl_rfic_get_iqdc(cl_hw, ant, dc_type, &val);
	if (ret < 0)
		return ret;

	snprintf(&reply_str[0], sizeof(reply_str), "0x%x", val);

	return cl_vendor_reply(cl_hw, reply_str, sizeof(reply_str));
}

static int cl_rfic_set_iqdc_tx_2_m_coeff(struct cl_hw *cl_hw, enum iqdc_fir_m_coeff coeff,
					 u16 val)
{
	int i;
	struct cl_chip *chip = cl_hw->chip;
	int sz = ARRAY_SIZE(tx_2_m_coeff);

	for (i = 0; i < sz; i++) {
		if (coeff == tx_2_m_coeff[i].coeff) {
			tx_2_m_coeff[i].set_iqdc_m_coeff_tx(chip, val);
			break;
		}
	}

	return 0;
}

static int cl_rfic_set_iqdc_tx_1_m_coeff(struct cl_hw *cl_hw, enum iqdc_fir_m_coeff coeff,
					 u16 val)
{
	int i;
	struct cl_chip *chip = cl_hw->chip;
	int sz = ARRAY_SIZE(tx_1_m_coeff);

	for (i = 0; i < sz; i++) {
		if (coeff == tx_1_m_coeff[i].coeff) {
			tx_1_m_coeff[i].set_iqdc_m_coeff_tx(chip, val);
			break;
		}
	}

	return 0;
}

static int cl_rfic_bt_set_iqdc_m_coeff_cli(struct cl_hw *cl_hw, enum cl_iqdc_freq freq,
					   enum iqdc_fir_m_coeff coeff, u16 val)
{
	int ret = 0;

	if (freq >= CL_FREQ_MAX) {
		cl_dbg_err(cl_hw, "Invalid freq=%d\n", freq);
		return -EINVAL;
	}

	if (coeff >= IQDC_FIR_M_COEFF_MAX) {
		cl_dbg_err(cl_hw, "Invalid coeff=%d\n", coeff);
		return -EINVAL;
	}

	if (val >= IQDC_TX_FIR_COEFF) {
		cl_dbg_err(cl_hw, "Invalid value %u\n", val);
		return -EINVAL;
	}

	if (freq)
		ret = cl_rfic_set_iqdc_tx_2_m_coeff(cl_hw, coeff, val);
	else
		ret = cl_rfic_set_iqdc_tx_1_m_coeff(cl_hw, coeff, val);

	return ret;
}

static int cl_rfic_get_iqdc_tx_2_m_coeff(struct cl_hw *cl_hw, enum iqdc_fir_m_coeff coeff,
					 u16 *val)
{
	int i;
	struct cl_chip *chip = cl_hw->chip;
	int sz = ARRAY_SIZE(tx_2_m_coeff);

	for (i = 0; i < sz; i++) {
		if (coeff == tx_2_m_coeff[i].coeff) {
			*val = tx_2_m_coeff[i].get_iqdc_m_coeff_tx(chip);
			break;
		}
	}

	return 0;
}

static int cl_rfic_get_iqdc_tx_1_m_coeff(struct cl_hw *cl_hw, enum iqdc_fir_m_coeff coeff,
					 u16 *val)
{
	int i;
	struct cl_chip *chip = cl_hw->chip;
	int sz = ARRAY_SIZE(tx_1_m_coeff);

	for (i = 0; i < sz; i++) {
		if (coeff == tx_1_m_coeff[i].coeff) {
			*val = tx_1_m_coeff[i].get_iqdc_m_coeff_tx(chip);
			break;
		}
	}

	return 0;
}

static int cl_rfic_bt_get_iqdc_m_coeff_cli(struct cl_hw *cl_hw, enum cl_iqdc_freq freq,
					   enum iqdc_fir_m_coeff coeff)
{
	int ret = 0;
	u16 val = 0;
	char reply_str[STR_LEN_32B] = {0};

	if (freq >= CL_FREQ_MAX) {
		cl_dbg_err(cl_hw, "Invalid freq=%d\n", freq);
		return -EINVAL;
	}

	if (coeff >= IQDC_FIR_M_COEFF_MAX) {
		cl_dbg_err(cl_hw, "Invalid coeff=%d\n", coeff);
		return -EINVAL;
	}

	if (freq)
		ret = cl_rfic_get_iqdc_tx_2_m_coeff(cl_hw, coeff, &val);
	else
		ret = cl_rfic_get_iqdc_tx_1_m_coeff(cl_hw, coeff, &val);

	if (ret < 0)
		return ret;

	snprintf(&reply_str[0], sizeof(reply_str), "0x%x", val);

	return cl_vendor_reply(cl_hw, reply_str, sizeof(reply_str));
}

static int cl_rfic_bt_set_iqdc_m_gain(struct cl_hw *cl_hw, enum cl_iqdc_freq mhz,
				      enum cl_iq_gain_type gain, u16 val)
{
	struct cl_chip *chip = cl_hw->chip;

	switch (mhz) {
	case CL_FREQ_1MHZ:
		switch (gain) {
		case CL_IQ_GAIN_TYPE_AMP:
			rfic_wrap_iqdc_tx_1_m_gain_iqdc_tx_amp_gain_setf(chip, val);
			break;
		case CL_IQ_GAIN_TYPE_PHASE:
			rfic_wrap_iqdc_tx_1_m_gain_iqdc_tx_phase_gain_setf(chip, val);
			break;
		default:
			cl_dbg_err(cl_hw, "Wrong input gain argument %d\n", gain);
			return -EINVAL;
		}
		break;
	case CL_FREQ_2MHZ:
		switch (gain) {
		case CL_IQ_GAIN_TYPE_AMP:
			rfic_wrap_iqdc_tx_2_m_gain_iqdc_tx_amp_gain_setf(chip, val);
			break;
		case CL_IQ_GAIN_TYPE_PHASE:
			rfic_wrap_iqdc_tx_2_m_gain_iqdc_tx_phase_gain_setf(chip, val);
			break;
		default:
			cl_dbg_err(cl_hw, "Wrong input gain argument %d\n", gain);
			return -EINVAL;
		}
		break;
	default:
		cl_dbg_err(cl_hw, "Wrong input mhz argument %d\n", mhz);
		return -EINVAL;
	}

	return 0;
}

static int cl_rfic_bt_set_iqdc_m_gain_cli(struct cl_hw *cl_hw, enum cl_iqdc_freq mhz,
					  enum cl_iq_gain_type gain, u16 val)
{
	int ret = 0;

	if (mhz >= CL_FREQ_MAX) {
		cl_dbg_err(cl_hw, "Invalid mhz=%d\n", mhz);
		return -EINVAL;
	}

	if (gain >= CL_IQ_GAIN_TYPE_MAX) {
		cl_dbg_err(cl_hw, "Invalid gain=%d\n", gain);
		return -EINVAL;
	}

	if (gain && val >= IQDC_TX_PHASE_GAIN) {
		cl_dbg_err(cl_hw, "Invalid value %u\n", val);
		return -EINVAL;
	} else if (!gain && val >= IQDC_TX_AMP_GAIN) {
		cl_dbg_err(cl_hw, "Invalid value %u\n", val);
		return -EINVAL;
	}

	ret = cl_rfic_bt_set_iqdc_m_gain(cl_hw, mhz, gain, val);

	return ret;
}

static int cl_rfic_bt_get_iqdc_m_gain(struct cl_hw *cl_hw, enum cl_iqdc_freq mhz,
				      enum cl_iq_gain_type gain, u16 *val)
{
	struct cl_chip *chip = cl_hw->chip;

	switch (mhz) {
	case CL_FREQ_1MHZ:
		switch (gain) {
		case CL_IQ_GAIN_TYPE_AMP:
			*val = rfic_wrap_iqdc_tx_1_m_gain_iqdc_tx_amp_gain_getf(chip);
			break;
		case CL_IQ_GAIN_TYPE_PHASE:
			*val = rfic_wrap_iqdc_tx_1_m_gain_iqdc_tx_phase_gain_getf(chip);
			break;
		default:
			cl_dbg_err(cl_hw, "Wrong input gain argument %d\n", gain);
			return -EINVAL;
		}
		break;
	case CL_FREQ_2MHZ:
		switch (gain) {
		case CL_IQ_GAIN_TYPE_AMP:
			*val = rfic_wrap_iqdc_tx_2_m_gain_iqdc_tx_amp_gain_getf(chip);
			break;
		case CL_IQ_GAIN_TYPE_PHASE:
			*val = rfic_wrap_iqdc_tx_2_m_gain_iqdc_tx_phase_gain_getf(chip);
			break;
		default:
			cl_dbg_err(cl_hw, "Wrong input gain argument %d\n", gain);
			return -EINVAL;
		}
		break;
	default:
		cl_dbg_err(cl_hw, "Wrong input mhz argument %d\n", mhz);
		return -EINVAL;
	}

	return 0;
}

static int cl_rfic_bt_get_iqdc_m_gain_cli(struct cl_hw *cl_hw, enum cl_iqdc_freq mhz,
					  enum cl_iq_gain_type gain)
{
	int ret = 0;
	u16 val = 0;
	char reply_str[STR_LEN_32B] = {0};

	if (mhz >= CL_FREQ_MAX) {
		cl_dbg_err(cl_hw, "Invalid mhz=%d\n", mhz);
		return -EINVAL;
	}

	if (gain >= CL_IQ_GAIN_TYPE_MAX) {
		cl_dbg_err(cl_hw, "Invalid gain=%d\n", gain);
		return -EINVAL;
	}

	ret = cl_rfic_bt_get_iqdc_m_gain(cl_hw, mhz, gain, &val);
	if (ret < 0)
		return ret;

	snprintf(&reply_str[0], sizeof(reply_str), "0x%x", val);

	return cl_vendor_reply(cl_hw, reply_str, sizeof(reply_str));
}

static int cl_rfic_bt_set_iqdc_m_dc(struct cl_hw *cl_hw, enum cl_iqdc_freq mhz,
				    enum cl_iq_dc_type dc_type, u16 val)
{
	struct cl_chip *chip = cl_hw->chip;

	switch (mhz) {
	case CL_FREQ_1MHZ:
		switch (dc_type) {
		case CL_IQ_DC_TYPE_I:
			rfic_wrap_iqdc_tx_1_m_dc_iqdc_tx_dci_setf(chip, val);
			break;
		case CL_IQ_DC_TYPE_Q:
			rfic_wrap_iqdc_tx_1_m_dc_iqdc_tx_dcq_setf(chip, val);
			break;
		default:
			cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
			return -EINVAL;
		}
		break;
	case CL_FREQ_2MHZ:
		switch (dc_type) {
		case CL_IQ_DC_TYPE_I:
			rfic_wrap_iqdc_tx_2_m_dc_iqdc_tx_dci_setf(chip, val);
			break;
		case CL_IQ_DC_TYPE_Q:
			rfic_wrap_iqdc_tx_2_m_dc_iqdc_tx_dcq_setf(chip, val);
			break;
		default:
			cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
			return -EINVAL;
		}
		break;
	default:
		cl_dbg_err(cl_hw, "Wrong input mhz argument %d\n", mhz);
		return -EINVAL;
	}

	return 0;
}

static int cl_rfic_bt_set_iqdc_m_dc_cli(struct cl_hw *cl_hw, enum cl_iqdc_freq mhz,
					enum cl_iq_dc_type dc_type, u16 val)
{
	int ret = 0;

	if (mhz >= CL_FREQ_MAX) {
		cl_dbg_err(cl_hw, "Invalid mhz=%d\n", mhz);
		return -EINVAL;
	}

	if (dc_type >= CL_IQ_DC_TYPE_MAX) {
		cl_dbg_err(cl_hw, "Invalid dc_type=%d\n", dc_type);
		return -EINVAL;
	}

	if (val >= IQDC_TX_DC) {
		cl_dbg_err(cl_hw, "Invalid value %u\n", val);
		return -EINVAL;
	}

	ret = cl_rfic_bt_set_iqdc_m_dc(cl_hw, mhz, dc_type, val);

	return ret;
}

static int cl_rfic_bt_get_iqdc_m_dc(struct cl_hw *cl_hw, enum cl_iqdc_freq mhz,
				    enum cl_iq_dc_type dc_type, u16 *val)
{
	struct cl_chip *chip = cl_hw->chip;

	switch (mhz) {
	case CL_FREQ_1MHZ:
		switch (dc_type) {
		case CL_IQ_DC_TYPE_I:
			*val = rfic_wrap_iqdc_tx_1_m_dc_iqdc_tx_dci_getf(chip);
			break;
		case CL_IQ_DC_TYPE_Q:
			*val = rfic_wrap_iqdc_tx_1_m_dc_iqdc_tx_dcq_getf(chip);
			break;
		default:
			cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
			return -EINVAL;
		}
		break;
	case CL_FREQ_2MHZ:
		switch (dc_type) {
		case CL_IQ_DC_TYPE_I:
			*val = rfic_wrap_iqdc_tx_2_m_dc_iqdc_tx_dci_getf(chip);
			break;
		case CL_IQ_DC_TYPE_Q:
			*val = rfic_wrap_iqdc_tx_2_m_dc_iqdc_tx_dcq_getf(chip);
			break;
		default:
			cl_dbg_err(cl_hw, "Wrong input dc_type argument %d\n", dc_type);
			return -EINVAL;
		}
		break;
	default:
		cl_dbg_err(cl_hw, "Wrong input mhz argument %d\n", mhz);
		return -EINVAL;
	}

	return 0;
}

static int cl_rfic_bt_get_iqdc_m_dc_cli(struct cl_hw *cl_hw, enum cl_iqdc_freq mhz,
					enum cl_iq_dc_type dc_type)
{
	int ret = 0;
	u16 val = 0;
	char reply_str[STR_LEN_32B] = {0};

	if (mhz >= CL_FREQ_MAX) {
		cl_dbg_err(cl_hw, "Invalid mhz=%d\n", mhz);
		return -EINVAL;
	}

	if (dc_type >= CL_IQ_DC_TYPE_MAX) {
		cl_dbg_err(cl_hw, "Invalid dc_type=%d\n", dc_type);
		return -EINVAL;
	}

	ret = cl_rfic_bt_get_iqdc_m_dc(cl_hw, mhz, dc_type, &val);
	if (ret < 0)
		return ret;

	snprintf(&reply_str[0], sizeof(reply_str), "0x%x", val);

	return cl_vendor_reply(cl_hw, reply_str, sizeof(reply_str));
}

static int cl_rfic_get_hr_factor(struct cl_hw *cl_hw, s32 *params)
{
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	s32 len = 0;
	enum cl_channel_bw bw = (enum cl_channel_bw)params[0];

	if (bw >= CHNL_BW_MAX) {
		cl_dbg_err(cl_hw, "Invalid channel bandwidth = %u\n", bw);
		return -EINVAL;
	}

	cl_snprintf(&buf, &len, &buf_size, "HR factor = %u\n",
		    cl_hw->conf->ci_hr_factor[bw]);

	err = cl_vendor_reply(cl_hw, buf, len);

	return err;
}

static int cl_rfic_read_anamon(struct cl_hw *cl_hw, u8 mode, u8 selection, u8 offset)
{
	char reply_str[10] = {0};
	u16 raw_bits_data_0 = 0;
	u16 raw_bits_data_1 = 0;
	u16 raw_bits_data = 0;
	u16 val_mv = 0;
	struct mm_anamon_read_cfm *cfm;

	if (mode == 0) {
		if (selection > 1) {
			cl_dbg_err(cl_hw,
				   "Invalid selection %u. Valid: 0:Internal|1:External\n",
				   selection);
			return -1;
		}
	} else if (mode > 2) {
		cl_dbg_err(cl_hw, "Invalid mode %u. Valid: 0:Temperature|1:Chains|2:SX\n", mode);
		return -1;
	}

	if (cl_msg_tx_anamon_read(cl_hw, mode, selection, offset) != 0) {
		cl_dbg_err(cl_hw, "cl_msg_tx_anamon_read failed\n");
		cl_msg_tx_free_cfm_params(cl_hw, MM_ANAMON_READ_CFM);
		return -1;
	}

	cfm = (struct mm_anamon_read_cfm *)(cl_hw->msg_cfm_params[MM_ANAMON_READ_CFM]);

	if (!cfm) {
		cl_dbg_err(cl_hw, "cfm is NULL !!!\n");
		return -1;
	}

	raw_bits_data_0 = le16_to_cpu(cfm->raw_bits_data_0);
	raw_bits_data_1 = le16_to_cpu(cfm->raw_bits_data_1);
	raw_bits_data = (raw_bits_data_0 + raw_bits_data_1) / 2;
	val_mv = cl_adc_to_mv(raw_bits_data);
	cl_msg_tx_free_cfm_params(cl_hw, MM_ANAMON_READ_CFM);

	snprintf(&reply_str[0], sizeof(reply_str), "%umV", val_mv);

	return cl_vendor_reply(cl_hw, reply_str, sizeof(reply_str));
}

static int cl_rfic_set_wifi_rf_fsm_state(struct cl_hw *cl_hw, s32 *params)
{
	int ret = 0;
	u32 test_params[TEST_MODE_PARAM_MAX + 1] = {0};

	/* Dbg_test_mode command */
	test_params[0] = DBG_TEST_MODE_RFIC_FSM;
	/* WiFi FSM state*/
	test_params[1] = (u32)params[0];
	/* Transition number */
	test_params[2] = (u32)params[1];

	if (test_params[2] >= RFIC_WIFI_FSM_MAX) {
		cl_dbg_err(cl_hw, "Invalid transition number = %u\n", test_params[2]);
		return -EINVAL;
	}

	switch (test_params[2]) {
	case RFIC_WIFI_FSM_3W_4W:
		/* Bgr enable bitmap */
		test_params[3] = (u32)params[2];

		if (test_params[3] > 3) {
			cl_dbg_err(cl_hw, "Invalid bgr enable bitmap %u\n", test_params[3]);
			return -EINVAL;
		}

		break;
	case RFIC_WIFI_FSM_4W_5W:
		/* Calibration mode */
		test_params[3] = (u32)params[2];

		if (test_params[3] > 2) {
			cl_dbg_err(cl_hw, "Invalid calibration mode %u\n", test_params[3]);
			return -EINVAL;
		}

		break;
	case RFIC_WIFI_FSM_5W_6W:
		/* Calibration mode */
		test_params[3] = (u32)params[2];
		/* HR factor */
		test_params[4] = (u32)params[3];
		/* CH BW */
		test_params[5] = (u32)params[4];

		if (test_params[3] > 2) {
			cl_dbg_err(cl_hw, "Invalid calibration mode %u\n", test_params[3]);
			return -EINVAL;
		}

		if (test_params[4] > 1) {
			cl_dbg_err(cl_hw, "Invalid hr factor %u\n", test_params[4]);
			return -EINVAL;
		}

		if (test_params[5] > 3) {
			cl_dbg_err(cl_hw, "Invalid CH BW %u\n", test_params[5]);
			return -EINVAL;
		}

		break;
	case RFIC_WIFI_FSM_6W_7W:
		/* Calibration mode */
		test_params[3] = (u32)params[2];

		if (test_params[3] > 2) {
			cl_dbg_err(cl_hw, "Invalid calibration mode %u\n", test_params[3]);
			return -EINVAL;
		}

		break;
	case RFIC_WIFI_FSM_7W_8W:
		/* System mode */
		test_params[3] = (u32)params[2];
		/* Loopback config type */
		test_params[4] = (u32)params[3];
		/* CH BW */
		test_params[5] = (u32)params[4];
		/* CH0 SX */
		test_params[6] = (u32)params[5];
		/* CH1 SX */
		test_params[7] = (u32)params[6];
		/* SX0 PLL freq (MHz) */
		test_params[8] = (u32)params[7];
		/* SX1 PLL freq (MHz) */
		test_params[9] = (u32)params[8];
		/* RF band select */
		test_params[10] = (u32)params[9];

		if (test_params[3] > 6) {
			cl_dbg_err(cl_hw, "Invalid system mode %u\n", test_params[3]);
			return -EINVAL;
		}

		if (test_params[4] > 19) {
			cl_dbg_err(cl_hw, "Invalid loopback config type %u\n", test_params[4]);
			return -EINVAL;
		}

		if (test_params[5] > 3) {
			cl_dbg_err(cl_hw, "Invalid CH BW %u\n", test_params[5]);
			return -EINVAL;
		}

		if (test_params[6] > 1) {
			cl_dbg_err(cl_hw, "Invalid CH0 SX %u\n", test_params[6]);
			return -EINVAL;
		}

		if (test_params[7] > 1) {
			cl_dbg_err(cl_hw, "Invalid CH1 SX %u\n", test_params[7]);
			return -EINVAL;
		}

		if (test_params[10] > 23) {
			cl_dbg_err(cl_hw, "Invalid RF band select %u\n", test_params[10]);
			return -EINVAL;
		}

		break;
	case RFIC_WIFI_FSM_8W_9W:
		/* System mode */
		test_params[3] = (u32)params[2];
		/* Loopback config type */
		test_params[4] = (u32)params[3];
		/* Rx gain */
		test_params[5] = (u32)params[4];

		if (test_params[3] > 6) {
			cl_dbg_err(cl_hw, "Invalid system mode %u\n", test_params[3]);
			return -EINVAL;
		}

		if (test_params[4] > 19) {
			cl_dbg_err(cl_hw, "Invalid loopback config type %u\n", test_params[4]);
			return -EINVAL;
		}

		break;
	case RFIC_WIFI_FSM_8W_10W:
		/* System mode */
		test_params[3] = (u32)params[2];
		/* Loopback config type */
		test_params[4] = (u32)params[3];
		/* Tx gain */
		test_params[5] = (u32)params[4];

		if (test_params[3] > 6) {
			cl_dbg_err(cl_hw, "Invalid system mode %u\n", test_params[3]);
			return -EINVAL;
		}

		if (test_params[4] > 19) {
			cl_dbg_err(cl_hw, "Invalid loopback config type %u\n", test_params[4]);
			return -EINVAL;
		}

		break;
	case RFIC_WIFI_FSM_9W_8W:
		/* System mode */
		test_params[3] = (u32)params[2];

		if (test_params[3] > 6) {
			cl_dbg_err(cl_hw, "Invalid system mode %u\n", test_params[3]);
			return -EINVAL;
		}

		break;
	case RFIC_WIFI_FSM_10W_8W:
		/* System mode */
		test_params[3] = (u32)params[2];

		if (test_params[3] > 6) {
			cl_dbg_err(cl_hw, "Invalid system mode %u\n", test_params[3]);
			return -EINVAL;
		}

		break;
	case RFIC_WIFI_FSM_8W_8W:
		/* SX0 PLL freq MHz */
		test_params[3] = (u32)params[2];
		/* HR factor */
		test_params[4] = (u32)params[3];
		/* CH BW */
		test_params[5] = (u32)params[4];
		/* System mode */
		test_params[6] = (u32)params[5];
		/* Production Loopback */
		test_params[7] = (u32)params[6];
		/* Production SX to chain allocation */
		test_params[8] = (u32)params[7];
		/* Production SX1 to PLL frequency */
		test_params[9] = (u32)params[8];

		if (test_params[4] > 1) {
			cl_dbg_err(cl_hw, "Invalid hr factor %u\n", test_params[4]);
			return -EINVAL;
		}

		if (test_params[5] > 3) {
			cl_dbg_err(cl_hw, "Invalid CH BW %u\n", test_params[5]);
			return -EINVAL;
		}

		if (test_params[6] > 6) {
			cl_dbg_err(cl_hw, "Invalid system mode %u\n", test_params[6]);
			return -EINVAL;
		}

		if (test_params[7] > 12) {
			cl_dbg_err(cl_hw, "Invalid Production Loopback %u\n", test_params[7]);
			return -EINVAL;
		}

		if (test_params[8] > 3) {
			cl_dbg_err(cl_hw, "Invalid Production SX to chain allocation %u\n", test_params[8]);
			return -EINVAL;
		}

		break;
	case RFIC_WIFI_FSM_ALL_3W:
		cl_dbg_verbose(cl_hw, "Transitioning to 3W (reset state)\n");
		break;
	default:
		cl_dbg_err(cl_hw, "Invalid transition number = %u\n", test_params[2]);
		return -EINVAL;
	}

	ret = cl_msg_tx_dbg_test_mode(cl_hw, test_params);
	if (ret)
		cl_dbg_err(cl_hw, "cl_send_dbg_test_mode failed\n");

	return ret;
}

static int cl_rfic_set_bt_rf_fsm_state(struct cl_hw *cl_hw, s32 *params)
{
	int ret = 0;
	u32 test_params[TEST_MODE_PARAM_MAX + 1] = {0};

	/* Dbg_test_mode command */
	test_params[0] = DBG_TEST_MODE_RFIC_FSM;
	/* BT FSM state*/
	test_params[1] = (u32)params[0];
	/* Transition number */
	test_params[2] = (u32)params[1];

	if (test_params[2] >= RFIC_FSM_BT_MAX) {
		cl_dbg_err(cl_hw, "Invalid transition number = %u\n", test_params[2]);
		return -EINVAL;
	}

	switch (test_params[2]) {
	case RFIC_FSM_BT_3B_4B:
		/* Bgr enable bitmap */
		test_params[3] = (u32)params[2];

		if (test_params[3] > 3) {
			cl_dbg_err(cl_hw, "Invalid bgr enable bitmap %u\n", test_params[3]);
			return -EINVAL;
		}

		break;
	case RFIC_FSM_BT_4B_5B:
		cl_dbg_verbose(cl_hw, "Transitioning from 4B --> 5B\n");
		break;
	case RFIC_FSM_BT_5B_6B:
		/* BT System mode */
		test_params[3] = (u32)params[2];
		/* Loopback config type */
		test_params[4] = (u32)params[3];
		/* Zero IF mode */
		test_params[5] = (u32)params[4];

		if (test_params[3] > 3) {
			cl_dbg_err(cl_hw, "Invalid BT System mode %u\n", test_params[3]);
			return -EINVAL;
		}

		if (test_params[4] > 15) {
			cl_dbg_err(cl_hw, "Invalid Loopback config type %u\n", test_params[4]);
			return -EINVAL;
		}

		if (test_params[5] > 1) {
			cl_dbg_err(cl_hw, "Invalid Zero IF mode %u\n", test_params[5]);
			return -EINVAL;
		}

		break;
	case RFIC_FSM_BT_6B_8B:
		/* BT System mode */
		test_params[3] = (u32)params[2];
		/* Loopback config type */
		test_params[4] = (u32)params[3];
		/* Channel index */
		test_params[5] = (u32)params[4];
		/* Mod select */
		test_params[6] = (u32)params[5];
		/* Filter BW */
		test_params[7] = (u32)params[6];

		if (test_params[3] > 3) {
			cl_dbg_err(cl_hw, "Invalid BT System mode %u\n", test_params[3]);
			return -EINVAL;
		}

		if (test_params[4] > 15) {
			cl_dbg_err(cl_hw, "Invalid Loopback config type %u\n", test_params[4]);
			return -EINVAL;
		}

		if (test_params[5] > 78) {
			cl_dbg_err(cl_hw, "Invalid Channel index %u\n", test_params[5]);
			return -EINVAL;
		}

		if (test_params[6] > 7) {
			cl_dbg_err(cl_hw, "Invalid Mod select %u\n", test_params[6]);
			return -EINVAL;
		}

		if (test_params[7] > 3) {
			cl_dbg_err(cl_hw, "Invalid Filter BW %u\n", test_params[7]);
			return -EINVAL;
		}

		break;
	case RFIC_FSM_BT_8B_9B:
		/* BT System mode */
		test_params[3] = (u32)params[2];
		/* Loopback config type */
		test_params[4] = (u32)params[3];
		/* Rx gain */
		test_params[5] = (u32)params[4];

		if (test_params[3] > 3) {
			cl_dbg_err(cl_hw, "Invalid BT system mode %u\n", test_params[3]);
			return -EINVAL;
		}

		if (test_params[4] > 15) {
			cl_dbg_err(cl_hw, "Invalid loopback config type %u\n", test_params[4]);
			return -EINVAL;
		}

		break;
	case RFIC_FSM_BT_8B_10B:
		/* BT System mode */
		test_params[3] = (u32)params[2];
		/* Loopback config type */
		test_params[4] = (u32)params[3];
		/* Tx gain */
		test_params[5] = (u32)params[4];

		if (test_params[3] > 3) {
			cl_dbg_err(cl_hw, "Invalid BT system mode %u\n", test_params[3]);
			return -EINVAL;
		}

		if (test_params[4] > 15) {
			cl_dbg_err(cl_hw, "Invalid loopback config type %u\n", test_params[4]);
			return -EINVAL;
		}

		break;
	case RFIC_FSM_BT_9B_6B:
		/* BT System mode */
		test_params[3] = (u32)params[2];

		if (test_params[3] > 3) {
			cl_dbg_err(cl_hw, "Invalid BT system mode %u\n", test_params[3]);
			return -EINVAL;
		}

		break;
	case RFIC_FSM_BT_10B_6B:
		/* BT System mode */
		test_params[3] = (u32)params[2];

		if (test_params[3] > 3) {
			cl_dbg_err(cl_hw, "Invalid BT system mode %u\n", test_params[3]);
			return -EINVAL;
		}

		break;
	case RFIC_FSM_BT_ALL_3B:
		cl_dbg_verbose(cl_hw, "Transitioning to 3B (reset state)\n");
		break;

	default:
		cl_dbg_err(cl_hw, "Invalid transition number = %u\n", test_params[2]);
		return -EINVAL;
	}

	ret = cl_msg_tx_dbg_test_mode(cl_hw, test_params);
	if (ret)
		cl_dbg_err(cl_hw, "cl_send_dbg_test_mode failed\n");

	return ret;
}

static int cl_rfic_set_rf_fsm_state(struct cl_hw *cl_hw, s32 *params)
{
	int ret = 0;

	if (params[0] >= RFIC_TYPE_MAX) {
		cl_dbg_err(cl_hw, "Invalid rfic_type = %d", params[0]);
		return -EINVAL;
	}

	if (params[0] == RFIC_TYPE_WIFI)
		ret = cl_rfic_set_wifi_rf_fsm_state(cl_hw, params);
	else if (params[0] == RFIC_TYPE_BT)
		ret = cl_rfic_set_bt_rf_fsm_state(cl_hw, params);

	return ret;

}

static int cl_rfic_cli_help(struct cl_hw *cl_hw)
{
	char *buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!buf)
		return -ENOMEM;

	snprintf(buf, PAGE_SIZE,
		 "rfic usage:\n"
		 "-a : set single DCOC register - [ant].[lna]."
			"[0:ip|1:in|2:qp|3:qn].[value]\n"
		 "-b : read single DCOC register - [ant].[lna]."
			"[0:ip|1:in|2:qp|3:qn]\n"
		 "-c: Set RFIC FSM state [0:WiFi|1:BT].[trans_num].[params..]\n"
		 "-f : get hr_factor for given BW [BW]\n"
		 "-g : set iq coeff - [ant].[0:rx|1:tx].[set].[coeff].[value]\n"
		 "-h : get iq coeff - [ant].[0:rx|1:tx].[set].[coeff]\n"
		 "-i : set iq gain - [ant].[0:rx|1:tx].[Rx:set1-set3 | Tx:set1]."
			"[0:amp gain|1:phase gain].[value]\n"
		 "-j : get iq gain - [ant].[0:rx|1:tx].[Rx:set1-set3 | Tx:set1]."
			"[0:amp gain|1:phase gain]\n"
		 "-k : set iq DC - [ant].[0:dci|1:dcq].[value]\n"
		 "-l : get iq DC - [ant].[0:dci|1:dcq]\n"
		 "-m : read single ANAMON value - [0:Temp|1:Ch|2:SX]."
			"[selection].[offset]\n"
		 "-I : set BT iq coeff - [0:1MHZ|1:2MHZ].[coeff:0-10]\n"
		 "-J : get BT iq coeff - [0:1MHZ|1:2MHZ].[coeff:0-10].[value]\n"
		 "-O : set BT iq gain - [0:1MHZ|1:2MHZ].[0:AMP|1:PHASE]\n"
		 "-P : get BT iq gain - [0:1MHZ|1:2MHZ].[0:AMP|1:PHASE].[value]\n"
		 "-Q : set BT iq dc - [0:1MHZ|1:2MHZ].[0:dci|1:dcq]\n"
		 "-R : get BT iq dc - [0:1MHZ|1:2MHZ].[0:dci|1:dcq].[value]\n");

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

int cl_rfic_cli(struct cl_hw *cl_hw, struct cli_params *cli_params)
{
	s32 *params = cli_params->params;

	switch (cli_params->option) {
	case 'a':
		if (cli_params->num_params != 4)
			goto err_num_of_arg;

		return cl_rfic_set_dcoc(cl_hw, (enum cl_rfic_chain)params[0],
					(enum cl_rfic_lna)params[1],
					(enum calib_dc_type)params[2], (u8)params[3]);
	case 'b':
		if (cli_params->num_params != 3)
			goto err_num_of_arg;

		return cl_rfic_read_dcoc(cl_hw, (enum cl_rfic_chain)params[0],
					 (enum cl_rfic_lna)params[1],
					 (enum calib_dc_type)params[2]);
	case 'c':
		return cl_rfic_set_rf_fsm_state(cl_hw, params);
	case 'f':
		if (cli_params->num_params != 1)
			goto err_num_of_arg;

		return cl_rfic_get_hr_factor(cl_hw, params);
	case 'g':
		if (cli_params->num_params != 5)
			goto err_num_of_arg;

		return cl_rfic_set_iq_coeff_cli(cl_hw, params);
	case 'h':
		if (cli_params->num_params != 4)
			goto err_num_of_arg;

		return cl_rfic_get_iq_coeff_cli(cl_hw, params);
	case 'i':
		if (cli_params->num_params != 5)
			goto err_num_of_arg;

		return cl_rfic_set_iq_gain(cl_hw, (enum cl_rfic_chain)params[0],
					   (enum cl_iq_direction)params[1],
					   (u8)params[2],
					   (enum cl_iq_gain_type)params[3],
					   (u32)params[4]);
	case 'j':
		if (cli_params->num_params != 4)
			goto err_num_of_arg;

		return cl_rfic_get_iq_gain_cli(cl_hw, params);
	case 'k':
		if (cli_params->num_params != 3)
			goto err_num_of_arg;

		return cl_rfic_set_iqdc_cli(cl_hw, params);
	case 'l':
		if (cli_params->num_params != 2)
			goto err_num_of_arg;

		return cl_rfic_get_iqdc_cli(cl_hw, params);
	case 'm':
		if (cli_params->num_params != 3)
			goto err_num_of_arg;

		return cl_rfic_read_anamon(cl_hw, (u8)params[0], (u8)params[1], (u8)params[2]);
	case 'I':
		if (cli_params->num_params != 3)
			goto err_num_of_arg;

		return cl_rfic_bt_set_iqdc_m_coeff_cli(cl_hw, (enum cl_iqdc_freq)params[0],
						       (enum iqdc_fir_m_coeff)params[1],
						       (u16)params[2]);
	case 'J':
		if (cli_params->num_params != 2)
			goto err_num_of_arg;

		return cl_rfic_bt_get_iqdc_m_coeff_cli(cl_hw, (enum cl_iqdc_freq)params[0],
						       (enum iqdc_fir_m_coeff)params[1]);
	case 'O':
		if (cli_params->num_params != 3)
			goto err_num_of_arg;

		return cl_rfic_bt_set_iqdc_m_gain_cli(cl_hw, (enum cl_iqdc_freq)params[0],
						      (enum cl_iq_gain_type)params[1],
						      (u16)params[2]);
	case 'P':
		if (cli_params->num_params != 2)
			goto err_num_of_arg;

		return cl_rfic_bt_get_iqdc_m_gain_cli(cl_hw, (enum cl_iqdc_freq)params[0],
						      (enum cl_iq_gain_type)params[1]);
	case 'Q':
		if (cli_params->num_params != 3)
			goto err_num_of_arg;

		return cl_rfic_bt_set_iqdc_m_dc_cli(cl_hw, (enum cl_iqdc_freq)params[0],
						    (enum cl_iq_dc_type)params[1],
						    (u16)params[2]);
	case 'R':
		if (cli_params->num_params != 2)
			goto err_num_of_arg;

		return cl_rfic_bt_get_iqdc_m_dc_cli(cl_hw, (enum cl_iqdc_freq)params[0],
						    (enum cl_iq_dc_type)params[1]);
	case '?':
		return cl_rfic_cli_help(cl_hw);
	default:
		cl_dbg_err(cl_hw, "Illegal option (%c) - try '?' for help\n", cli_params->option);
		return -EINVAL;
	}

err_num_of_arg:
	cl_dbg_err(cl_hw, "Wrong number of arguments\n");

	return -EINVAL;
}

int cl_rfic_get_iq_gain(struct cl_hw *cl_hw, u8 ant, enum cl_iq_direction direction,
			enum cl_iq_gain_type gain_type, s32 *val)
{
	u32 reg = 0;

	if (ant >= MAX_ANTENNAS) {
		cl_dbg_err(cl_hw, "Invalid ant %u\n", ant);
		return -1;
	}

	if (direction >= CL_IQ_DIRECTION_MAX) {
		cl_dbg_err(cl_hw, "Invalid direction %d - should be 0:rx|1:tx\n", direction);
		return -1;
	}

	if (gain_type >= CL_IQ_GAIN_TYPE_MAX) {
		cl_dbg_err(cl_hw,
			   "Invalid gain type %d - should be 0:amp|1:phase|2:amp&phase combo\n",
			   gain_type);
		return -1;
	}

	if (gain_type == CL_IQ_GAIN_TYPE_AMP)
		*val = ((cl_reg_read(cl_hw->chip, reg) & ((u32)0x000007FF)) >> 0);
	else if (gain_type == CL_IQ_GAIN_TYPE_PHASE)
		*val = ((cl_reg_read(cl_hw->chip, reg) & ((u32)0x0FFF0000)) >> 16);
	else if (gain_type == CL_IQ_GAIN_TYPE_COMBINATION)
		*val = ((cl_reg_read(cl_hw->chip, reg) & ((u32)0x0FFF07FF)) >> 0);

	return 0;
}

int cl_rfic_get_iq_dc(struct cl_hw *cl_hw, u8 ant, enum cl_iq_tx_dc_type dc_type, s32 *val)
{
	u32 reg = 0;

	if (ant >= MAX_ANTENNAS) {
		cl_dbg_err(cl_hw, "Invalid ant %u\n", ant);
		return -1;
	}

	if (dc_type >= CL_IQ_TX_DC_TYPE_MAX) {
		cl_dbg_err(cl_hw, "Invalid dc type %d - should be 0:dci|1:dcq|2:dci&dcq combo\n",
			   dc_type);
		return -1;
	}

	reg = RIU_IQDC_TX_0_DC_ADDR + (ant * 0x20);

	if (dc_type == CL_IQ_TX_DC_TYPE_I)
		*val = ((cl_reg_read(cl_hw->chip, reg) & ((u32)0x00000FFF)) >> 0);
	else if (dc_type == CL_IQ_TX_DC_TYPE_Q)
		*val = ((cl_reg_read(cl_hw->chip, reg) & ((u32)0x0FFF0000)) >> 16);
	else if (dc_type == CL_IQ_TX_DC_TYPE_COMBINATION)
		*val = ((cl_reg_read(cl_hw->chip, reg) & ((u32)0x0FFF0FFF)) >> 0);

	return 0;
}


/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_PROF_H
#define CL_PROF_H

#include "cl_fw_msg.h"
#include "cl_debugfs_defs.h"
#include "reg_access.h"

enum {
	SW_PROF_HOSTBUF_IDX = 12,
	/* IPC IRQs related signals */
	SW_PROF_IRQ_E2A_RXDESC = 16, /* Let 16 bits available for firmware */
	SW_PROF_IRQ_E2A_TXCFM,
	SW_PROF_IRQ_E2A_TBTT,
	SW_PROF_IRQ_E2A_DBG,
	SW_PROF_IRQ_E2A_MSG,
	SW_PROF_IRQ_E2A_RADAR,
	SW_PROF_IRQ_E2A_TXDESC_IND,

	/* Driver functions related signals */
	SW_PROF_IPC_MSG_PUSH,
	SW_PROF_WAIT_QUEUE,
	SW_PROF_RX_DATA_IND,
	SW_PROF_IEEE80211RX,

	SW_PROF_MAX
};

#ifdef CONFIG_CL_SW_PROFILING
/* Macros for SW profiling registers access */
#define PROF_REG_SW_SET(cl_hw, bit) \
	( \
		mac_hw_sw_set_profiling_set(cl_hw, BIT(bit)); \
	)

#define PROF_REG_SW_CLR(cl_hw, bit) \
	( \
		mac_hw_sw_clear_profiling_set(cl_hw, BIT(bit)); \
	)
#else
#define PROF_REG_SW_SET(cl_hw, value) do {} while (0)
#define PROF_REG_SW_CLR(cl_hw, value) do {} while (0)
#endif

#endif /* CL_PROF_H */

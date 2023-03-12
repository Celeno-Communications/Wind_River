/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_MSG_CFM_H
#define CL_MSG_CFM_H

#include "cl_hw.h"
#include "cl_fw_msg.h"

/* Timeout waiting for firmware confirmation */
#define CL_MSG_CFM_TIMEOUT_MS            5000

#define CL_MSG_CFM_TIMEOUT_JIFFIES       msecs_to_jiffies(CL_MSG_CFM_TIMEOUT_MS)

#define CL_MSG_CFM_TIMEOUT_DUMMY_MS      7000
#define CL_MSG_CFM_TIMEOUT_DUMMY_JIFFIES msecs_to_jiffies(CL_MSG_CFM_TIMEOUT_DUMMY_MS)

#define CL_MSG_CFM_TIMEOUT_FRU_MS        35000
#define CL_MSG_CFM_TIMEOUT_FRU_JIFFIES   msecs_to_jiffies(CL_MSG_CFM_TIMEOUT_FRU_MS)

#define CL_MSG_CFM_TIMEOUT_CALIB_MS        12000000
#define CL_MSG_CFM_TIMEOUT_CALIB_JIFFIES   msecs_to_jiffies(CL_MSG_CFM_TIMEOUT_CALIB_MS)

#define CFM_CLEAR_BIT(bit, cfm_flags) \
	clear_bit((bit) & 0x1f, *(cfm_flags) + ((bit) >> 5))

#define CFM_SET_BIT(bit, cfm_flags) \
	set_bit((bit) & 0x1f, *(cfm_flags) + ((bit) >> 5))

#define CFM_TEST_BIT(bit, cfm_flags) \
	test_bit((bit) & 0x1f, *(cfm_flags) + ((bit) >> 5))

#define CFM_TEST_AND_CLEAR_BIT(bit, cfm_flags) \
	test_and_clear_bit((bit) & 0x1f, *(cfm_flags) + ((bit) >> 5))

u16 cl_msg_cfm_set_bit(u16 req);
void cl_msg_cfm_assign_and_clear(struct cl_hw *cl_hw, struct cl_ipc_e2a_msg *msg);
void cl_msg_cfm_clear(struct cl_hw *cl_hw, struct cl_ipc_e2a_msg *msg);
void cl_msg_cfm_check_exception(struct cl_hw *cl_hw);
void cl_msg_cfm_simulate_timeout(struct cl_hw *cl_hw);

#endif /* CL_MSG_CFM_H */

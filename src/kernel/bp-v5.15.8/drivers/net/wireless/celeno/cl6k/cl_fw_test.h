/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_FW_TEST_H
#define CL_FW_TEST_H

#define PCIE_WRAP_LLI_MAX   32
#define BRU_MAX_DESC_IN_LLI 50

#define FW_TEST_PREFIX "FW_TEST [%s][%d]: "
#define TEST_INFO(fmt, args...) \
	cl_dbg_verbose(cl_hw, FW_TEST_PREFIX fmt, __func__, __LINE__, ##args)

void cl_fw_test_pre(struct cl_hw *cl_hw, char *lmac_fw_name,
		    char *umac_fw_name, char *smac_fw_name);
void cl_fw_test_apre(struct cl_hw *cl_hw, char *lmac_fw_name,
		     char *umac_fw_name, char *smac_fw_name);
bool cl_fw_test_is_dsp_required(char *test_name);

#endif /* _CL_FW_TEST_H */

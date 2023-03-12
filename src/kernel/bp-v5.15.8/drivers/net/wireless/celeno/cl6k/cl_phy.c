// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "chip_ops.h"
#include "cl_phy.h"
#include "rf_boot.h"
#include "cl_dsp_load.h"

int cl_phy_load_recovery(struct cl_hw *cl_hw)
{
	int ret = cl_rf_boot_recovery(cl_hw->chip,
				      cl_hw->conf->ce_channel_bandwidth);

	if (ret) {
		cl_dbg_err(cl_hw, "cl_rf_boot_recovery failed %d\n", ret);
		return ret;
	}

	/* Load DSP */
	ret = cl_dsp_load_recovery(cl_hw);
	if (ret) {
		cl_dbg_err(cl_hw, "cl_dsp_load_recovery failed %d\n", ret);
		return ret;
	}

	msleep(500);
	return 0;
}

int cl_phy_data_alloc(struct cl_hw *cl_hw)
{
	struct cl_phy_data *buf = NULL;
	u32 len = (u32)PAGE_SIZE;
	dma_addr_t phys_dma_addr;

	buf = chip_ops_alloc_coherent(cl_hw->chip, len, GFP_KERNEL, &phys_dma_addr);

	if (!buf)
		return -1;

	cl_hw->phy_data_info.data = buf;
	cl_hw->phy_data_info.dma_addr = phys_dma_addr;

	return 0;
}

void cl_phy_data_free(struct cl_hw *cl_hw)
{
	dma_addr_t phys_dma_addr = cl_hw->phy_data_info.dma_addr;

	if (!cl_hw->phy_data_info.data)
		return;

	chip_ops_free_coherent(cl_hw->chip, PAGE_SIZE,
			       (void *)cl_hw->phy_data_info.data,
			       phys_dma_addr);
	cl_hw->phy_data_info.data = NULL;
}


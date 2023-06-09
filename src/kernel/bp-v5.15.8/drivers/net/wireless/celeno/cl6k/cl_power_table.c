// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_power_table.h"
#include "cl_e2p.h"
#include "cl_band.h"
#include "chip_ops.h"

static const u8 power_to_powerword_conv_table_id_0[NUM_POWER_WORDS] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0 - 7 */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 8 - 15 */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 16 - 23 */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 24 - 31 */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 32 - 39 */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 40 - 47 */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 48 - 55 */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 56 - 63 */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 64 - 71 */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 72 - 79 */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 80 - 87 */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 88 - 95 */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x03, /* 96 - 103 */
	0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, /* 104 - 111 */
	0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, /* 112 - 119 */
	0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, /* 120 - 127 */
	0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23, /* 128 - 135 */
	0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, /* 136 - 143 */
	0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, /* 144 - 151 */
	0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, /* 152 - 159 */
	0x3c, 0x3d, 0x3e, 0x3f, 0x40, 0x41, 0x42, 0x43, /* 160 - 167 */
	0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, /* 168 - 175 */
	0x4c, 0x4d, 0x4e, 0x4f, 0x4f, 0x50, 0x50, 0x50, /* 176 - 183 */
	0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, /* 184 - 191 */
	0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, /* 192 - 199 */
	0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, /* 200 - 207 */
	0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, /* 208 - 215 */
	0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, /* 216 - 223 */
	0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, /* 224 - 231 */
	0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, /* 232 - 239 */
	0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, /* 240 - 247 */
	0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50  /* 248 - 255 */
};

static const u8 power_to_powerword_conv_table_id_1[NUM_POWER_WORDS] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0 - 7 */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 8 - 15 */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 16 - 23 */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 24 - 31 */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 32 - 39 */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 40 - 47 */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 48 - 55 */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 56 - 63 */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 64 - 71 */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 72 - 79 */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 80 - 87 */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 88 - 95 */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x03, /* 96 - 103 */
	0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, /* 104 - 111 */
	0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, /* 112 - 119 */
	0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, /* 120 - 127 */
	0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23, /* 128 - 135 */
	0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, /* 136 - 143 */
	0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, /* 144 - 151 */
	0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, /* 152 - 159 */
	0x3c, 0x3d, 0x3e, 0x3f, 0x40, 0x41, 0x42, 0x43, /* 160 - 167 */
	0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, /* 168 - 175 */
	0x4c, 0x4d, 0x4e, 0x4f, 0x4f, 0x50, 0x50, 0x50, /* 176 - 183 */
	0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, /* 184 - 191 */
	0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, /* 192 - 199 */
	0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, /* 200 - 207 */
	0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, /* 208 - 215 */
	0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, /* 216 - 223 */
	0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, /* 224 - 231 */
	0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, /* 232 - 239 */
	0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, /* 240 - 247 */
	0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50  /* 248 - 255 */
};

static const u8 power_to_powerword_conv_table_id_2[NUM_POWER_WORDS] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0 - 7 */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 8 - 15 */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 16 - 23 */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 24 - 31 */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 32 - 39 */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 40 - 47 */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 48 - 55 */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 56 - 63 */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 64 - 71 */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 72 - 79 */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 80 - 87 */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 88 - 95 */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x03, /* 96 - 103 */
	0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, /* 104 - 111 */
	0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, /* 112 - 119 */
	0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, /* 120 - 127 */
	0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23, /* 128 - 135 */
	0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, /* 136 - 143 */
	0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, /* 144 - 151 */
	0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, /* 152 - 159 */
	0x3c, 0x3d, 0x3e, 0x3f, 0x40, 0x41, 0x42, 0x43, /* 160 - 167 */
	0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, /* 168 - 175 */
	0x4c, 0x4d, 0x4e, 0x4f, 0x4f, 0x50, 0x50, 0x50, /* 176 - 183 */
	0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, /* 184 - 191 */
	0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, /* 192 - 199 */
	0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, /* 200 - 207 */
	0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, /* 208 - 215 */
	0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, /* 216 - 223 */
	0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, /* 224 - 231 */
	0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, /* 232 - 239 */
	0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, /* 240 - 247 */
	0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50  /* 248 - 255 */
};

static int cl_power_table_fill(struct cl_hw *cl_hw)
{
	if (cl_band_is_5g(cl_hw)) {
		memcpy(cl_hw->power_table_info.data->conv_table,
		       power_to_powerword_conv_table_id_0, NUM_POWER_WORDS);
		cl_hw->tx_power_version = 5;
	} else if (cl_band_is_24g(cl_hw)) {
		memcpy(cl_hw->power_table_info.data->conv_table,
		       power_to_powerword_conv_table_id_1, NUM_POWER_WORDS);
		cl_hw->tx_power_version = 23;
	} else if (cl_band_is_6g(cl_hw)) {
		memcpy(cl_hw->power_table_info.data->conv_table,
		       power_to_powerword_conv_table_id_2, NUM_POWER_WORDS);
		cl_hw->tx_power_version = 1;
	} else {
		return -1;
	}

	return 0;
}

int cl_power_table_alloc(struct cl_hw *cl_hw)
{
	struct cl_power_table_data *buf = NULL;
	u32 len = sizeof(struct cl_power_table_data);
	dma_addr_t phys_dma_addr;

	buf = chip_ops_alloc_coherent(cl_hw->chip, len, GFP_KERNEL, &phys_dma_addr);

	if (!buf)
		return -1;

	cl_hw->power_table_info.data = buf;
	cl_hw->power_table_info.dma_addr = phys_dma_addr;

	return cl_power_table_fill(cl_hw);
}

void cl_power_table_free(struct cl_hw *cl_hw)
{
	struct cl_power_table_info *power_table_info = &cl_hw->power_table_info;
	u32 len = sizeof(struct cl_power_table_data);
	dma_addr_t phys_dma_addr = power_table_info->dma_addr;

	if (!
	    power_table_info->data)
		return;

	chip_ops_free_coherent(cl_hw->chip, len,
			       (void *)power_table_info->data,
			       phys_dma_addr);
	power_table_info->data = NULL;
}

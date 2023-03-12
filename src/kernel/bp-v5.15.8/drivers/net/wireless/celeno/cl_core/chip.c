// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include <linux/delay.h>
#include "chip.h"
#include "lcu.h"
#include "rf_boot.h"
#include "core_debug.h"
#include "reg_macsys_gcu.h"

struct cl_chip *chip_db[CHIP_MAX];

static struct cl_chip *cl_chip_alloc(size_t priv_size, u8 chip_idx)
{
	struct cl_chip *chip = kzalloc(sizeof(*chip) + priv_size, GFP_KERNEL);

	if (!chip)
		return NULL;

	chip_db[chip_idx] = chip;
	chip->idx = chip_idx;

	return chip;
}

int cl_chip_alloc_all(size_t priv_size)
{
	int chip_idx = 0;
	struct cl_chip *chip = NULL;

	for (chip_idx = 0; chip_idx < CHIP_MAX; chip_idx++) {
		chip = cl_chip_alloc(priv_size, chip_idx);
		if (!chip)
			return -ENOMEM;
	}

	return 0;
}

struct cl_chip *cl_chip_get(u8 chip_idx)
{
	if (chip_idx >= CHIP_MAX) {
		pr_err("wrong chip_idx %d\n", chip_idx);

		return NULL;
	}

	return chip_db[chip_idx];
}
EXPORT_SYMBOL(cl_chip_get);

void cl_chip_dealloc(struct cl_chip *chip)
{
	if (!chip)
		return;

	chip_db[chip->idx] = NULL;
	cl_chip_config_dealloc(chip);
	kfree(chip->eeprom_cache);
	kfree(chip->otp_cache);
	kfree(chip);
}
EXPORT_SYMBOL(cl_chip_dealloc);

void cl_chip_dealloc_all(void)
{
	int chip_idx = 0;

	for (chip_idx = 0; chip_idx < CHIP_MAX; chip_idx++) {
		if (chip_db[chip_idx])
			cl_chip_dealloc(chip_db[chip_idx]);
	}
}

int fw_file_get_params(struct cl_chip *chip,
		       enum cl_fw_file_type type,
		       struct fw_file_params *params)
{
	if (type == CL_FW_FILE_LMAC) {
		params->dram_addr = LMAC_DRAM_FW_ADDR;
		params->dram_size = LMAC_DRAM_SIZE;
		params->iram_addr = LMAC_IRAM_FW_ADDR;
		params->iram_size = LMAC_IRAM_SIZE;
	} else if (type == CL_FW_FILE_SMAC) {
		params->dram_addr = SMAC_DRAM_FW_ADDR;
		params->dram_size = SMAC_DRAM_SIZE;
		params->iram_addr = SMAC_IRAM_FW_ADDR;
		params->iram_size = SMAC_IRAM_SIZE;
	} else if (type == CL_FW_FILE_UMAC) {
		if (IS_PCI_BUS_TYPE(chip)) {
			params->dram_addr = UMAC_DRAM_FW_ADDR;
			params->dram_size = cl_chip_umac_dram_size(chip);
			params->iram_addr = cl_chip_umac_iram_fw_addr(chip);
			params->iram_size = cl_chip_umac_iram_size(chip);
		} else {
			params->dram_addr = LOCAL_UMAC_DRAM_FW_ADDR;
			params->dram_size = cl_chip_umac_dram_size(chip);
			params->iram_addr = LOCAL_UMAC_IRAM_FW_ADDR;
			params->iram_size = cl_chip_umac_iram_size(chip);
		}
	} else {
		cl_dbg_chip_err(chip, "Unknown type %d\n", type);

		return -EINVAL;
	}

	return 0;
}

int cl_core_chip_init(struct cl_chip *chip)
{
	int ret;
	struct cl_chip_conf *conf = chip->conf;
	u8 step_val = 0;

	if (!conf->ci_phy_load_bootdrv &&
	    conf->ci_phy_dev != PHY_DEV_DUMMY) {
		ret = cl_rf_boot(chip);
		if (ret) {
			cl_dbg_chip_err(chip, "cl_rf_boot failed %d\n", ret);
			return ret;
		}
	}

	if (cl_lcu_init(chip))
		cl_dbg_chip_err(chip, "Non-critical: cl_lcu_init failed\n");

	step_val = macsys_gcu_chip_version_step_id_getf(chip);

	switch (step_val) {
	case CL_STEP_HW_REG_STEP_A:
		chip->step_id = CL_STEP_ID_STEP_A;
		break;
	case CL_STEP_HW_REG_STEP_B:
		chip->step_id = CL_STEP_ID_STEP_B;
		break;
	default:
		chip->step_id = CL_STEP_ID_UNDEF;
	}

	return 0;
}

void cl_core_chip_deinit(struct cl_chip *chip)
{
	cl_lcu_deinit(chip);
}

void chip_reset(struct cl_chip *chip,
		u32 ocd_halt_on_reset,
		u32 dreset,
		u32 run_stall,
		u32 breset,
		u32 debug_enable)
{
	/* Release TRST & BReset to enable JTAG connection to FPGA A */
	u32 regval;

	/* 1. return to reset value */
	regval = macsys_gcu_xt_control_get(chip);
	cl_dbg_chip_info(chip, "0. XT_CTRL=0x%X.\n", regval);
	regval |= ocd_halt_on_reset;
	regval &= ~(dreset | run_stall | breset);
	macsys_gcu_xt_control_set(chip, regval);

	regval = macsys_gcu_xt_control_get(chip);
	regval |= dreset;
	macsys_gcu_xt_control_set(chip, regval);

	/* 2. stall xtensa & release ocd */
	regval = macsys_gcu_xt_control_get(chip);
	cl_dbg_chip_info(chip, "1. XT_CTRL=0x%X.\n", regval);
	regval |= run_stall;
	regval &= ~ocd_halt_on_reset;
	macsys_gcu_xt_control_set(chip, regval);

	/* 3. breset release & debug enable */
	regval = macsys_gcu_xt_control_get(chip);
	cl_dbg_chip_info(chip, "2. XT_CTRL=0x%X.\n", regval);
	regval |= (debug_enable | breset);
	macsys_gcu_xt_control_set(chip, regval);

	regval = macsys_gcu_xt_control_get(chip);
	cl_dbg_chip_info(chip, "3. XT_CTRL=0x%X.\n", regval);

	msleep(100);
}
EXPORT_SYMBOL(chip_reset);


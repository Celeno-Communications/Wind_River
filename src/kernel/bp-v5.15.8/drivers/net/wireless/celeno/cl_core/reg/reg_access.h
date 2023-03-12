/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef REG_ACCESS_H
#define REG_ACCESS_H

#include "def.h"
#include "chip.h"
#include "core_debug.h"
#include "chip_ops.h"

#define CL_REG_DBG_CHIP(...) \
	do { \
		if (chip->reg_dbg) \
			cl_dbg_chip_verbose(__VA_ARGS__); \
	} while (0)

#define XTENSA_PIF_BASE_ADDR     0x60000000

#define DEFAULT_IDMA_ALLOCATION_VALUE 0x00100F20

/*
 * SHARED_RAM Address.
 * Actually the PCI BAR4 window will be configured such as SHARED RAM
 * is accessed with offset 0 (within the AHB Bridge main window)
 */
#define SHARED_RAM_START_ADDR    0x00000000
#define REG_MAC_HW_SMAC_OFFSET   0x80000
#define REG_PHY_SMAC_OFFSET      0x100000

#define REG_MACDSP_API_BASE_ADDR    0x00400000
#define REG_MAC_HW_BASE_ADDR        0x00600000
#define REG_RIU_BASE_ADDR           0x004A6000
#define REG_BT_CONTROLLER_BASE_ADDR 0x00390000
#define REG_USBC_BASE_ADDR          0x00380000
#define REG_RFIC_WRAP_BASE_ADDR     0x004B4000

#define APB_REGS_BASE_ADDR       0x007C0000
#define I2C_REG_BASE_ADDR        (APB_REGS_BASE_ADDR + 0x3000)
#define IPC_REG_BASE_ADDR        (APB_REGS_BASE_ADDR + 0x4000)

/* MACSYS_GCU_XT_CONTROL fields */
#define SMAC_DEBUG_ENABLE      BIT(21)
#define SMAC_BREAKPOINT        BIT(20)
#define SMAC_OCD_HALT_ON_RESET BIT(19)
#define SMAC_RUN_STALL         BIT(18)
#define SMAC_DRESET            BIT(17)
#define SMAC_BRESET            BIT(16)
#define UMAC_DEBUG_ENABLE      BIT(13)
#define UMAC_BREAKPOINT        BIT(11)
#define UMAC_OCD_HALT_ON_RESET BIT(11)
#define UMAC_RUN_STALL         BIT(10)
#define UMAC_DRESET            BIT(9)
#define UMAC_BRESET            BIT(8)
#define LMAC_DEBUG_ENABLE      BIT(5)
#define LMAC_BREAKPOINT        BIT(4)
#define LMAC_OCD_HALT_ON_RESET BIT(3)
#define LMAC_RUN_STALL         BIT(2)
#define LMAC_DRESET            BIT(1)
#define LMAC_BRESET            BIT(0)

#define CMU_GLOBAL_RESET_KEY1 0x1e00ef11
#define CMU_GLOBAL_RESET_KEY2 0xaf1ebebe

#define XMAC_BRESET \
	(LMAC_BRESET | SMAC_BRESET)
#define XMAC_DRESET \
	(LMAC_DRESET | SMAC_DRESET)
#define XMAC_RUN_STALL \
	(LMAC_RUN_STALL | SMAC_RUN_STALL)
#define XMAC_OCD_HALT_ON_RESET \
	(LMAC_OCD_HALT_ON_RESET | SMAC_OCD_HALT_ON_RESET)
#define XMAC_DEBUG_ENABLE \
	(LMAC_DEBUG_ENABLE | SMAC_DEBUG_ENABLE)

static inline u32 get_actual_reg(struct cl_chip *chip, u32 reg)
{
	if ((reg & 0x00f00000) == REG_MACDSP_API_BASE_ADDR)
		if (chip->conf->ci_phy_dev == PHY_DEV_DUMMY)
			return -1;

	return reg;
}

static inline u32 cl_reg_read(struct cl_chip *chip, u32 reg)
{
	int ret = 0;
	u32 actual_reg = get_actual_reg(chip, reg);
	u32 val = 0;

	if (actual_reg == (u32)(-1))
		return 0xff;

	ret = chip_ops_read32(chip, actual_reg, &val);
	if (ret)
		cl_dbg_chip_err(chip, "failed to read 0x%x ret=%d\n",
				actual_reg, ret);
	CL_REG_DBG_CHIP(chip, "reg=0x%x, val=0x%x\n", actual_reg, val);

	return val;
}

static inline int cl_reg_write(struct cl_chip *chip, u32 reg, u32 val)
{
	int ret = 0;
	u32 actual_reg = get_actual_reg(chip, reg);

	if (actual_reg == (u32)(-1))
		return -1;

	ret = chip_ops_write32(chip, actual_reg, val);
	if (ret)
		cl_dbg_chip_err(chip, "failed to write 0x%x=0x%x ret=%d\n",
				actual_reg, val, ret);

	CL_REG_DBG_CHIP(chip, "reg=0x%x, val=0x%x\n", actual_reg, val);

	return ret;
}

static inline int cl_reg_write_mask(struct cl_chip *chip, u32 reg,
				    u32 val, u32 mask, bool resp)
{
	int ret = 0;
	u32 actual_reg = get_actual_reg(chip, reg);

	if (actual_reg == (u32)(-1))
		return -1;

	ret = chip_ops_mask_write32(chip, actual_reg, val, mask, resp);
	if (ret)
		cl_dbg_chip_err(chip,
				"failed to write 0x%x=0x%x mask=0x%x ret=%d\n",
				actual_reg, val, mask, ret);

	CL_REG_DBG_CHIP(chip, "reg=0x%x, val=0x%x mask=0x%x\n",
			actual_reg, val, mask);

	return ret;
}

#endif /* REG_ACCESS_H */

// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include <linux/delay.h>
#include "cl_spi.h"
#include "reg_access.h"
#include "reg_riu_rc.h"

#define PHY_RF_PAGE_ADDRESS 0x03

#define READ_REQ  1
#define WRITE_REQ 0

#define MORE0 0
#define MORE1 1

#define MAX_LOOPS 15

static int spi_read(struct cl_hw *cl_hw, u8 more, u8 addr, u8 *val)
{
	int loops = MAX_LOOPS;

	riu_rc_sw_ctrl_pack(cl_hw, 1, more, 0, 0, 1, 1, 1, 1, 2, READ_REQ, addr, 0xFF);

	while (riu_rc_sw_ctrl_start_done_getf(cl_hw) && --loops)
		;

	if (!loops) {
		cl_dbg_verbose(cl_hw, "Read error - addr [0x%02x]\n", addr);
		return -1;
	}

	*val = riu_rc_sw_ctrl_data_getf(cl_hw);

	CL_REG_DBG(cl_hw, "more=%d, addr=0x%x, *val=0x%x\n", more, addr, *val);

	return 0;
}

static int spi_write(struct cl_hw *cl_hw, u8 more, u8 addr, u8 val)
{
	int loops = MAX_LOOPS;

	CL_REG_DBG(cl_hw, "more=%d, addr=0x%x, val=0x%x\n", more, addr, val);

	riu_rc_sw_ctrl_pack(cl_hw, 1, more, 0, 0, 1, 1, 1, 1, 2, WRITE_REQ, addr, val);

	while (riu_rc_sw_ctrl_start_done_getf(cl_hw) && --loops)
		;

	if (!loops) {
		cl_dbg_verbose(cl_hw, "Write error - addr [0x%02x] val [0x%02x]\n", addr, val);
		return -1;
	}

	return 0;
}

u8 cl_spi_read(struct cl_hw *cl_hw, u8 addr)
{
	u8 val = 0;

	if (spi_read(cl_hw, MORE0, addr, &val) == 0)
		return val;

	return 0;
}

int cl_spi_read_byte(struct cl_hw *cl_hw, u8 page, u8 addr, u8 *val)
{
	int ret = 0;

	spin_lock_bh(&cl_hw->chip->isr_lock);

	ret = spi_write(cl_hw, MORE1, PHY_RF_PAGE_ADDRESS, page);
	if (ret)
		goto read_exit;

	ret = spi_read(cl_hw, MORE0, addr, val);
	if (ret)
		goto read_exit;

read_exit:
	spin_unlock_bh(&cl_hw->chip->isr_lock);

	return ret;
}

int cl_spi_read_u16(struct cl_hw *cl_hw, u8 page, u8 addr, u16 *val)
{
	int ret = 0;
	u8 val_msb = 0, val_lsb = 0;

	spin_lock_bh(&cl_hw->chip->isr_lock);

	ret = spi_write(cl_hw, MORE1, PHY_RF_PAGE_ADDRESS, page);
	if (ret)
		goto read_exit;

	ret = spi_read(cl_hw, MORE0, addr, &val_msb);
	if (ret)
		goto read_exit;

	ret = spi_read(cl_hw, MORE0, addr + 1, &val_lsb);
	if (ret)
		goto read_exit;

read_exit:
	spin_unlock_bh(&cl_hw->chip->isr_lock);

	*val = (u16)val_lsb | ((u16)val_msb << 8);
	return ret;
}

int cl_spi_write(struct cl_hw *cl_hw, u8 addr, u8 val)
{
	return spi_write(cl_hw, MORE0, addr, val);
}

int cl_spi_write_mask(struct cl_hw *cl_hw, u8 addr, u8 val, u8 mask)
{
	u8 orig;
	int ret;

	spin_lock_bh(&cl_hw->chip->isr_lock);

	ret = spi_read(cl_hw, MORE0, addr, &orig);
	if (ret)
		goto write_exit;

	ret = spi_write(cl_hw, MORE0, addr, (orig & ~mask) | (val & mask));
	if (ret)
		goto write_exit;

write_exit:

	spin_unlock_bh(&cl_hw->chip->isr_lock);
	return ret;
}

int cl_spi_write_byte(struct cl_hw *cl_hw, u8 page, u8 addr, u8 val)
{
	int ret = 0;

	spin_lock_bh(&cl_hw->chip->isr_lock);

	ret = spi_write(cl_hw, MORE1, PHY_RF_PAGE_ADDRESS, page);
	if (ret)
		goto write_exit;

	ret = spi_write(cl_hw, MORE0, addr, val);
	if (ret)
		goto write_exit;

write_exit:
	spin_unlock_bh(&cl_hw->chip->isr_lock);

	return ret;
}

int cl_spi_write_u16(struct cl_hw *cl_hw, u8 page, u8 addr, u16 val)
{
	int ret = 0;

	spin_lock_bh(&cl_hw->chip->isr_lock);

	ret = spi_write(cl_hw, MORE1, PHY_RF_PAGE_ADDRESS, page);
	if (ret)
		goto write_exit;

	ret = spi_write(cl_hw, MORE0, addr, (u8)(val >> 8) & 0xFF);
	if (ret)
		goto write_exit;

	ret = spi_write(cl_hw, MORE0, addr + 1, (u8)val & 0xFF);
	if (ret)
		goto write_exit;

write_exit:
	spin_unlock_bh(&cl_hw->chip->isr_lock);

	return ret;
}

int cl_spi_write_byte_mask(struct cl_hw *cl_hw, u8 page, u8 addr, u8 val, u8 mask)
{
	int ret = 0;
	u8 orig = 0;

	spin_lock_bh(&cl_hw->chip->isr_lock);

	ret = spi_write(cl_hw, MORE1, PHY_RF_PAGE_ADDRESS, page);
	if (ret)
		goto write_exit;

	ret = spi_read(cl_hw, MORE0, addr, &orig);
	if (ret)
		goto write_exit;

	ret = spi_write(cl_hw, MORE0, addr, (orig & ~mask) | (val & mask));
	if (ret)
		goto write_exit;

write_exit:

	spin_unlock_bh(&cl_hw->chip->isr_lock);

	return ret;
}

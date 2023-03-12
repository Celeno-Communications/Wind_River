// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_reg_cli.h"
#include "cl_utils.h"
#include "reg_access.h"
#include "reg_modem_gcu.h"
#include "chip_ops.h"

/*
 * iwcl command to read registers and write to registers:
 * iwcl <iface> cecli reg.-r.<reg_addr>
 * iwcl <iface> cecli reg.-w.<reg_addr>.<reg_value>
 * iwcl <iface> cecli reg.-m.<reg_addr>.<reg_value>.<reg_mask>
 * iwcl <iface> cecli reg.-x.<type>.<offset>.<value>
 * iwcl <iface> cecli reg.-y.<type>.<offset>
 * iwcl <iface> cecli reg.-z.<type>.<offset>.<value>.<mask>
 * reg_value should not include PCI base address
 * The advantage of using iwcl command instead of mem command is
 * that with using the iwcl command the relevant registers will
 * be added to the recovery procedure.
 */

static int cl_reg_cli_write_mask(struct cl_hw *cl_hw, u32 address, u32 value, u32 mask)
{
	char reply_str[7] = {0};
	u16 reply_strlen = 0;
	int ret = cl_reg_write_mask(cl_hw->chip, address, value, mask, false);

	cl_dbg_verbose(cl_hw, "WRITE: Address = 0x%x, Value = 0x%x, Mask = 0x%x\n",
		       address, value, mask);
	reply_strlen = snprintf(&reply_str[0], sizeof(reply_str), "ret=%d", ret);

	return cl_vendor_reply(cl_hw, reply_str, reply_strlen);
}

static int cl_reg_cli_read(struct cl_hw *cl_hw, u32 address)
{
	u32 value = cl_reg_read(cl_hw->chip, address);
	char reply_str[11] = {0};
	u16 reply_strlen = 0;

	reply_strlen = snprintf(&reply_str[0], sizeof(reply_str), "0x%08x", value);

	return cl_vendor_reply(cl_hw, reply_str, reply_strlen);
}

static int cl_reg_cli_read_mask(struct cl_hw *cl_hw, u32 address, u32 mask)
{
	u32 value = cl_reg_read(cl_hw->chip, address);
	char reply_str[11] = {0};
	u16 reply_strlen = 0;

	value &= mask;

	reply_strlen = snprintf(&reply_str[0], sizeof(reply_str), "0x%08x", value);

	return cl_vendor_reply(cl_hw, reply_str, reply_strlen);
}

static int cl_reg_cli_read_block(struct cl_hw *cl_hw, u32 addr, u32 length)
{
	u32 value;
	int i = 0;
	__le32 *data = NULL;
	int ret = 0;
	struct cl_chip *chip = cl_hw->chip;
	char *buf = NULL;
	ssize_t buf_size;
	int len = 0;

	if ((addr & 0x3) != 0) {
		pr_err("Invalid addr - 0x%x\n", addr);
		return -EINVAL;
	}

	if (IS_USB_BUS_TYPE(chip)) {
		data = kzalloc(length, GFP_KERNEL);

		if (!data)
			return -ENOMEM;

		ret = chip_ops_read_bulk(chip, addr, length, (u8 *)data);
		if (ret) {
			cl_dbg_err(cl_hw, "read %d bytes from addr 0x%x failed\n",
				   length, addr);
			goto out;
		}
	}

	cl_snprintf(&buf, &len, &buf_size, "\n---------------------------\n");
	cl_snprintf(&buf, &len, &buf_size, "|   Address  |   Value    |\n");
	cl_snprintf(&buf, &len, &buf_size, "|------------+------------|\n");

	for (i = 0; (i * sizeof(u32)) < length; i++, addr += sizeof(u32)) {
		if (IS_USB_BUS_TYPE(chip))
			value = le32_to_cpu(data[i]);
		else
			value = cl_reg_read(chip, addr);

		cl_snprintf(&buf, &len, &buf_size, "| 0x%08x | 0x%08x |\n", addr, value);
	}
	cl_snprintf(&buf, &len, &buf_size, "---------------------------\n");

	cl_vendor_reply(cl_hw, buf, len);
 out:
	kvfree(buf);
	kfree(data);

	return ret;
}

static int cl_reg_cli_write(struct cl_hw *cl_hw, u32 address, u32 value)
{
	char reply_str[7] = {0};
	u16 reply_strlen = 0;
	int ret = cl_reg_write(cl_hw->chip, address, value);

	cl_dbg_verbose(cl_hw, "WRITE: Address = 0x%x, Value = 0x%x\n", address, value);
	reply_strlen = snprintf(&reply_str[0], sizeof(reply_str), "ret=%d", ret);

	return cl_vendor_reply(cl_hw, reply_str, reply_strlen);
}

static int cl_reg_cli_write_type(struct cl_hw *cl_hw, enum cl_reg_type type, u32 offset, u32 value)
{
	if (type == GCU_REG) {
		cl_reg_cli_write(cl_hw, REG_MODEM_GCU_BASE_ADDR + offset, value);
	} else if (type == RIU_REG) {
		cl_reg_cli_write(cl_hw, REG_RIU_BASE_ADDR + offset, value);
	} else if (type == RFIC_WRAP_REG) {
		cl_reg_cli_write(cl_hw, REG_RFIC_WRAP_BASE_ADDR + offset, value);
	} else {
		cl_dbg_err(cl_hw, "Invalid reg_type = %d\n", type);
		return -EINVAL;
	}

	return 0;
}

static int cl_reg_cli_read_type(struct cl_hw *cl_hw, enum cl_reg_type type, u32 offset)
{
	u32 base;

	switch (type) {
	case GCU_REG:
		base = REG_MODEM_GCU_BASE_ADDR;
		break;
	case RIU_REG:
		base = REG_RIU_BASE_ADDR;
		break;
	case RFIC_WRAP_REG:
		base = REG_RFIC_WRAP_BASE_ADDR;
		break;
	default:
		cl_dbg_err(cl_hw, "Invalid reg_type\n");
		return -EINVAL;
	}

	return cl_reg_cli_read(cl_hw, base + offset);
}

static int cl_reg_cli_read_type_mask(struct cl_hw *cl_hw, enum cl_reg_type type, u32 offset,
				     u32 mask)
{
	u32 base;

	switch (type) {
	case GCU_REG:
		base = REG_MODEM_GCU_BASE_ADDR;
		break;
	case RIU_REG:
		base = REG_RIU_BASE_ADDR;
		break;
	case RFIC_WRAP_REG:
		base = REG_RFIC_WRAP_BASE_ADDR;
		break;
	default:
		cl_dbg_err(cl_hw, "Invalid reg_type\n");
		return -EINVAL;
	}

	return cl_reg_cli_read_mask(cl_hw, base + offset, mask);
}

static int cl_reg_cli_write_type_mask(struct cl_hw *cl_hw, enum cl_reg_type type, u32 offset,
				      u32 value, u32 mask)
{
	if (type == GCU_REG) {
		cl_reg_write_mask(cl_hw->chip, REG_MODEM_GCU_BASE_ADDR + offset, value, mask,
				  false);
	} else if (type == RIU_REG) {
		cl_reg_write_mask(cl_hw->chip, REG_RIU_BASE_ADDR + offset, value, mask, false);
	} else if (type == RFIC_WRAP_REG) {
		cl_reg_write_mask(cl_hw->chip, REG_RFIC_WRAP_BASE_ADDR + offset, value, mask,
				  false);
	} else {
		cl_dbg_err(cl_hw, "Invalid reg_type = %d\n", type);
		return -EINVAL;
	}

	return 0;
}

static int cl_reg_cli_bt_write(struct cl_hw *cl_hw, enum cl_bt_reg_type type, u32 address,
			       u32 value)
{
	if (type == BT_REG_CONTROLLER) {
		cl_reg_cli_write(cl_hw, address, value);
	} else if (type == BT_REG_MODEM) {
		cl_reg_cli_write(cl_hw, address, value);
	} else {
		cl_dbg_err(cl_hw, "Invalid cl_bt_reg_type = %d\n", type);
		return -EINVAL;
	}

	return 0;
}

static int cl_reg_cli_bt_read(struct cl_hw *cl_hw, enum cl_bt_reg_type type, u32 address)
{
	if (type == BT_REG_CONTROLLER) {
		cl_reg_cli_read(cl_hw, address);
	} else if (type == BT_REG_MODEM) {
		cl_reg_cli_read(cl_hw, address);
	} else {
		cl_dbg_err(cl_hw, "Invalid cl_bt_reg_type = %d\n", type);
		return -EINVAL;
	}

	return 0;
}

static int cl_reg_cli_set_debug(struct cl_hw *cl_hw, bool enable)
{
	if (enable) {
		cl_hw->reg_dbg = true;
		cl_hw->chip->reg_dbg |= (1 << cl_hw->tcv_idx);
	} else {
		cl_hw->reg_dbg = false;
		cl_hw->chip->reg_dbg &= ~(1 << cl_hw->tcv_idx);
	}

	return 0;
}

static int cl_reg_cli_help(struct cl_hw *cl_hw)
{
	char *buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!buf)
		return -ENOMEM;

	snprintf(buf, PAGE_SIZE,
		 "reg usage:\n"
		 "-a : write BT register[0:controller|1:modem].[address].[value]\n"
		 "-b : read BT register[0:controller|1:modem].[address]\n"
		 "-d : Set debug [0:Disable|1:Enable]\n"
		 "-m : Write masked value to address [address].[value].[mask]\n"
		 "-q : Read type masked value [0:GCU|1:RIU|2:RFIC Wrapper].[offset].[mask]\n"
		 "-r : Read address [address]\n"
		 "-s : Read block [first address].[length in hex bytes]\n"
		 "-w : Write value to address [address].[value]\n"
		 "-x : Write type [0:GCU|1:RIU|2:RFIC Wrapper].[offset].[value]\n"
		 "-y : Read type [0:GCU|1:RIU|2:RFIC Wrapper].[offset]\n"
		 "-z : Write type mask [0:GCU|1:RIU|2:RFIC Wrapper].[offset].[value].[mask]\n");

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

int cl_reg_cli(struct cl_hw *cl_hw, struct cli_params *cli_params)
{
	u32 expected_params = 0;
	bool set_debug = false;
	bool reg_write_mask = false;
	bool reg_read = false;
	bool reg_read_block = false;
	bool reg_write = false;
	bool reg_write_type = false;
	bool reg_read_type = false;
	bool reg_write_type_mask = false;
	bool reg_read_type_mask = false;
	bool reg_bt_write = false;
	bool reg_bt_read = false;

	switch (cli_params->option) {
	case 'a':
		reg_bt_write = true;
		expected_params = 3;
		break;
	case 'b':
		reg_bt_read = true;
		expected_params = 2;
		break;
	case 'd':
		set_debug = true;
		expected_params = 1;
		break;
	case 'm':
		reg_write_mask = true;
		expected_params = 3;
		break;
	case 'q':
		reg_read_type_mask = true;
		expected_params = 3;
		break;
	case 'r':
		reg_read = true;
		expected_params = 1;
		break;
	case 's':
		reg_read_block = true;
		expected_params = 2;
		break;
	case 'w':
		reg_write = true;
		expected_params = 2;
		break;
	case 'x':
		reg_write_type = true;
		expected_params = 3;
		break;
	case 'y':
		reg_read_type = true;
		expected_params = 2;
		break;
	case 'z':
		reg_write_type_mask = true;
		expected_params = 4;
		break;
	case '?':
		return cl_reg_cli_help(cl_hw);
	default:
		cl_dbg_err(cl_hw, "Illegal option (%c) - try '?' for help\n", cli_params->option);
		goto out_err;
	}

	if (expected_params != cli_params->num_params) {
		cl_dbg_err(cl_hw, "Wrong number of arguments (expected %u) (actual %u)\n",
			   expected_params, cli_params->num_params);
		goto out_err;
	}

	if (set_debug) {
		u32 enable = cli_params->params[0];

		return cl_reg_cli_set_debug(cl_hw, enable);
	}

	if (reg_write_mask) {
		u32 address = cli_params->params[0];
		u32 value = cli_params->params[1];
		u32 mask = cli_params->params[2];

		return cl_reg_cli_write_mask(cl_hw, address, value, mask);
	}

	if (reg_read) {
		u32 address = cli_params->params[0];

		return cl_reg_cli_read(cl_hw, address);
	}

	if (reg_read_block) {
		u32 addr = cli_params->params[0];
		u32 length = cli_params->params[1];

		return cl_reg_cli_read_block(cl_hw, addr, length);
	}

	if (reg_write) {
		u32 address = cli_params->params[0];
		u32 value = cli_params->params[1];

		return cl_reg_cli_write(cl_hw, address, value);
	}

	if (reg_write_type) {
		enum cl_reg_type type = (enum cl_reg_type)cli_params->params[0];
		u32 offset = cli_params->params[1];
		u32 value = cli_params->params[2];

		return cl_reg_cli_write_type(cl_hw, type, offset, value);
	}

	if (reg_read_type) {
		enum cl_reg_type type = (enum cl_reg_type)cli_params->params[0];
		u32 offset = cli_params->params[1];

		return cl_reg_cli_read_type(cl_hw, type, offset);
	}

	if (reg_write_type_mask) {
		enum cl_reg_type type = (enum cl_reg_type)cli_params->params[0];
		u32 offset = cli_params->params[1];
		u32 value = cli_params->params[2];
		u32 mask = cli_params->params[3];

		return cl_reg_cli_write_type_mask(cl_hw, type, offset, value, mask);
	}

	if (reg_read_type_mask) {
		enum cl_reg_type type = (enum cl_reg_type)cli_params->params[0];
		u32 offset = cli_params->params[1];
		u32 mask = cli_params->params[2];

		return cl_reg_cli_read_type_mask(cl_hw, type, offset, mask);
	}

	if (reg_bt_write) {
		enum cl_bt_reg_type type = (enum cl_bt_reg_type)cli_params->params[0];
		u32 address = cli_params->params[1];
		u32 value = cli_params->params[2];

		return cl_reg_cli_bt_write(cl_hw, type, address, value);
	}

	if (reg_bt_read) {
		enum cl_bt_reg_type type = (enum cl_bt_reg_type)cli_params->params[0];
		u32 address = cli_params->params[1];

		return cl_reg_cli_bt_read(cl_hw, type, address);
	}

out_err:
	return -EIO;
}

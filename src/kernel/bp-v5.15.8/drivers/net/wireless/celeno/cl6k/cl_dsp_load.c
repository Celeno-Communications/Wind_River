// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "reg_modem_gcu.h"
#include "reg_macdsp_api.h"
#include "reg_cmu.h"
#include "cl_dsp_load.h"
#include "reg_access.h"
#include "reg_macsys_gcu.h"
#include "cl_hw.h"
#include "file.h"
#include <linux/firmware.h>
#include "cl_fw_test.h"
#include "cl_sec_load.h"

enum {
	CL_SEC_DSP_CODE = 1,
	CL_SEC_DSP_DATA,
	CL_SEC_DSP_XDATA,
};

#define BUSY_WAIT_LIMIT 10000

static int cl_dsp_hex_load(struct cl_hw *cl_hw, const u8 *buf,
			   u32 addr, size_t size, size_t buf_size)
{
	struct cl_chip *chip = cl_hw->chip;
	u8 single_buf[4] = {0};
	u32 bin_data = 0;
	u32 *write_buf = NULL;
	u8 next_byte;
	u8 byte_num = 0;
	int ret = 0;
	u32 offset = 0;
	ssize_t oft = 0;
	size_t real_size = min(size * 3, buf_size);

	if (buf_size % 3) {
		cl_dbg_err(cl_hw, "DSP size %zu must be divided by 3 !!!\n",
			   buf_size);
		return -EINVAL;
	}

	if (!real_size)
		return 0;

	write_buf = kzalloc(size, GFP_KERNEL);
	if (!write_buf)
		return -ENOMEM;

	while (oft < real_size) {
		memcpy(single_buf, buf + oft, 3);
		/* Each line contains 2 hex digits + a line feed, i.e. 3 bytes */
		ret = kstrtou8(single_buf, 16, &next_byte);
		if (ret < 0) {
			cl_dbg_err(cl_hw,
				   "ret = %d, oft = %zu,"
				   "single_buf = 0x%x 0x%x 0x%x 0x%x\n",
				   ret, oft, single_buf[0], single_buf[1],
				   single_buf[2], single_buf[3]);
			goto out;
		}

		/* Little-endian order. */
		bin_data += next_byte << (8 * byte_num);
		byte_num = (byte_num + 1) % 4;

		/* Read 4 lines from the file, and then write. */
		if (byte_num == 0) {
			write_buf[offset] = bin_data;
			offset++;
			bin_data = 0;
		}

		memset(&single_buf, 0, sizeof(single_buf));
		oft += 3;
	}

	ret = chip_ops_write_bulk(chip, addr, (u8 *)write_buf, size);
 out:
	kfree(write_buf);

	return ret;
}

static void print_phy_core_info(struct cl_hw *cl_hw)
{
	cl_dbg_trace(cl_hw, "PHY_CORE_VERSION_ADDR=0x%X.\n",
		     cl_reg_read(cl_hw->chip, CL_SEC_PHY_CORE_VERSION_ADDR));
	cl_dbg_trace(cl_hw, "PHY_CORE_ID_ADDR=0x%X.\n",
		     cl_reg_read(cl_hw->chip, CL_SEC_PHY_CORE_ID_ADDR));
}

static int cl_dsp_load_lmac(struct cl_chip *chip, char *fw_name)
{
	const struct firmware *fw;
	int rc;
	char path_name[CL_PATH_MAX] = {0};

	snprintf(path_name, sizeof(path_name), "cl6k/%s", fw_name);
	rc = request_firmware(&fw, path_name, chip->dev);

	if (rc) {
		cl_dbg_chip_err(chip, "# Failed to get %s, with error: %x!\n",
				path_name, rc);
		goto out;
	}

	rc = chip_ops_fw_upload(chip, CL_FW_FILE_LMAC, (u8 *)fw->data, fw->size);

out:
	release_firmware(fw);

	return rc;
}

static struct cl_dsp_loading_entry_s {

	u32 dsp_type;
	u32 file_offset;
	u32 max_size;
	u32 dl_address;
} cl_dsp_loading_table[] = {

	/* First record is absent */
	{0, 0, 0, 0},
	/* Should be fwC.hex */
	{CL_SEC_DSP_CODE, 0, CL_SEC_MAX_BINARY_SIZE, CL_SEC_DSP_INTERNAL_MEM},
	{CL_SEC_DSP_CODE, CL_SEC_MAX_BINARY_SIZE, CL_SEC_MAX_BINARY_SIZE,
		CL_SEC_DSP_INTERNAL_MEM + CL_SEC_MAX_BINARY_SIZE},
	/* Should be fwD.hex */
	{CL_SEC_DSP_DATA, 0, CL_SEC_MAX_BINARY_SIZE, CL_PHY_DMEM_BASE},
	{CL_SEC_DSP_DATA, CL_SEC_MAX_BINARY_SIZE, CL_PHY_DMEM_SIZE - CL_SEC_MAX_BINARY_SIZE,
		CL_PHY_DMEM_BASE + CL_SEC_MAX_BINARY_SIZE},
	/* Should be fwD.ext.hex */
	{CL_SEC_DSP_XDATA, 0, CL_PHY_XMEM_SIZE, CL_PHY_XMEM_BASE},
};

static int cl_dsp_load_mem(struct cl_hw *cl_hw, u32 dst_address, u32 file_id,
			   u32 *ret_size, u32 *ret_download_addr)
{
	struct cl_chip *chip = cl_hw->chip;
	const struct firmware *fw;
	int rc;
	char path_name[CL_PATH_MAX] = {0};
	u32 size;
	u32 max_size = CL_SEC_MAX_BINARY_SIZE;
	u32 skip = 0;
	u32 dl_address = 0;
	int file_index = CL_SEC_GET_FILE_INDEX(file_id);
	int dsp_type = 0;

	if (file_index < ARRAY_SIZE(cl_dsp_loading_table)) {
		dsp_type = cl_dsp_loading_table[file_index].dsp_type;
		skip = cl_dsp_loading_table[file_index].file_offset;
		max_size = cl_dsp_loading_table[file_index].max_size;
		dl_address = cl_dsp_loading_table[file_index].dl_address;
	}

	if (!dl_address) {
		cl_dbg_chip_err(chip, "Download address is zero. Non-existing file_id 0x%x ?\n",
				file_id);
		return -EIO;
	}

	switch (dsp_type) {

	case CL_SEC_DSP_CODE:
		snprintf(path_name, sizeof(path_name), "cl6k/%s",
			 cl_hw->conf->ce_dsp_code);
		break;

	case CL_SEC_DSP_DATA:
		snprintf(path_name, sizeof(path_name), "cl6k/%s",
			 cl_hw->conf->ce_dsp_data);
		break;

	case CL_SEC_DSP_XDATA:
		snprintf(path_name, sizeof(path_name), "cl6k/%s",
			 cl_hw->conf->ce_dsp_external_data);
		break;

	default:
		cl_dbg_chip_err(chip, "Wrong dsp_type %d\n",
				dsp_type);
		return -EIO;
	}

	cl_dbg_verbose(cl_hw, "file_id 0x%x from %s\n", file_id, path_name);

	rc = request_firmware(&fw, path_name, chip->dev);

	if (rc) {
		cl_dbg_chip_err(chip, "# Failed to get %s, with error: %x!\n",
				path_name, rc);
		goto out;
	}

	size = fw->size - skip * 3;
	if (size > max_size * 3)
		size = max_size * 3;

	rc = cl_dsp_hex_load(cl_hw, fw->data + (skip * 3), dst_address, max_size, size);

	if (ret_size)
		*ret_size = size / 3;
	if (ret_download_addr)
		*ret_download_addr = dl_address;

out:
	release_firmware(fw);

	return rc;
}

static inline void cl_dsp_unstall_mac_chip(struct cl_chip *chip, u32 stall)
{
	u32 regval;

	regval = macsys_gcu_xt_control_get(chip);
	regval &= ~stall;
	macsys_gcu_xt_control_set(chip, regval);
}

static inline void cl_dsp_stall_mac_chip(struct cl_chip *chip, u32 stall)
{
	u32 regval;

	regval = macsys_gcu_xt_control_get(chip);
	regval |= stall;
	macsys_gcu_xt_control_set(chip, regval);
}

static inline int cl_dsp_wait_sec_complete(struct cl_chip *chip)
{
	u32 owner;
	u32 magic;
	u32 busy_wait = 0;

	do {
		msleep(20);
		magic = cl_reg_read(chip, CL_SEC_CONTROL_MAGIC_ADDR);
		if (++busy_wait > BUSY_WAIT_LIMIT / 20)
			return -EIO;
	} while (magic != CL_SEC_CONTROL_MAGIC_VAL);

	do {
		msleep(20);
		owner = cl_reg_read(chip, CL_SEC_CONTROL_OWNER0_ADDR);
		if (++busy_wait > BUSY_WAIT_LIMIT / 20)
			return -EIO;
	} while (owner == 0);

	return 0;
}

static int _cl_dsp_load(struct cl_hw *cl_hw)
{
	int ret = 0;
	struct cl_chip *chip = cl_hw->chip;
	u32 file_id;
	u32 fw_fsm;
	u32 host_fsm;
	u32 size = 0;
	u32 dl_address = 0;

	chip_reset(chip,
		   LMAC_OCD_HALT_ON_RESET,
		   LMAC_DRESET,
		   LMAC_RUN_STALL,
		   LMAC_BRESET,
		   LMAC_DEBUG_ENABLE);

	cl_dsp_load_lmac(chip, CL_SEC_LOADER_NON_SECURE_NAME);
	cl_reg_write(chip, CL_SEC_CONTROL_OWNER0_ADDR, 0);
	cl_reg_write(chip, CL_SEC_OTP_ADDR_SECURITY_ENABLE, CL_SEC_OTP_VAL_SECURITY_SIM);

	if (!cl_hw->chip->fw_test) {
		host_fsm = CL_SEC_DL_FSM_PROCESS_FILE;
	} else if (cl_fw_test_is_dsp_required((char *)cl_hw->chip->conf->ce_lmac)) {
		cl_dbg_err(cl_hw, "DSPMBX: enable DSP\n");
		host_fsm = CL_SEC_DL_FSM_TEST;
	} else {
		cl_dbg_info(cl_hw, "FW test - skip DSP enable\n");
		host_fsm = CL_SEC_DL_FSM_ERROR;
	}

	cl_dsp_unstall_mac_chip(chip, LMAC_RUN_STALL);

	while (true) {
		ret = cl_dsp_wait_sec_complete(chip);
		if (ret) {
			cl_dbg_err(cl_hw, "Timeout waiting of DSP code loader %d\n", ret);
			return ret;
		}

		fw_fsm = cl_reg_read(chip, CL_SEC_CONTROL_FW_FSM_ADDR);
		if (fw_fsm == CL_SEC_DL_FSM_DONE)
			break;

		file_id = cl_reg_read(chip, CL_SEC_CONTROL_FILE_ID_ADDR);
		ret = cl_dsp_load_mem(cl_hw, CL_SEC_ENCRYPTED_BIN_ADDR, file_id,
				      &size, &dl_address);
		if (ret) {
			cl_dbg_err(cl_hw, "Failed to load DSP code %d\n", ret);
			return ret;
		}

		file_id = CL_SEC_PACK_FILE_ID(CL_SEC_GET_FILE_CHUNK(file_id),
					      ARRAY_SIZE(cl_dsp_loading_table) - 1,
					      CL_SEC_GET_FILE_INDEX(file_id));
		cl_reg_write(chip, CL_SEC_CONTROL_FILE_SIZE_ADDR, size);
		cl_reg_write(chip, CL_SEC_CONTROL_FILE_ID_ADDR, file_id);
		cl_reg_write(chip, CL_SEC_CONTROL_DOWNLOAD_ADDR, dl_address);
		cl_reg_write(chip, CL_SEC_CONTROL_HOST_FSM_ADDR, host_fsm);

		/* Last thing - set owner - is a trigger for fw to process structure */
		cl_reg_write(chip, CL_SEC_CONTROL_OWNER0_ADDR, 0);
	}

	print_phy_core_info(cl_hw);

	chip_reset(chip,
		   LMAC_OCD_HALT_ON_RESET,
		   LMAC_DRESET,
		   LMAC_RUN_STALL,
		   LMAC_BRESET,
		   LMAC_DEBUG_ENABLE);

	return ret;
}

int cl_dsp_load(struct cl_chip *chip)
{
	if (cl_chip_is_tcv0_enabled(chip))
		return _cl_dsp_load(chip->cl_hw_tcv0);

	return 0;
}

int cl_dsp_load_recovery(struct cl_hw *cl_hw)
{
	return _cl_dsp_load(cl_hw);
}

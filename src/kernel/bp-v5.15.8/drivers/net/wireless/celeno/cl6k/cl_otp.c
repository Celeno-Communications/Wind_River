// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "chip.h"
#include "cl_otp.h"
#include "reg/reg_otp.h"
#include "file.h"
#include "cl_config.h"
#include "cl_utils.h"
#include "cl_calibration.h"

#define OTP_KEY_VAL1        0xA6EE17BF
#define OTP_KEY_VAL2        0x827532CD
#define OTP_WRITE_CMD       0x1
#define OTP_READ_CMD        0x2
#define OTP_MAX_POLLS       10
#define OTP_INIT_DELAY      32

#define OTP_BROKEN_BITMAP_ELEM_BITS_NUM   5
#define OTP_BROKEN_BITMAP_ELEM_SIZE       BIT(OTP_BROKEN_BITMAP_ELEM_BITS_NUM)

static int cl_otp_cli_help(struct cl_hw *cl_hw)
{
	char *buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!buf)
		return -ENOMEM;

	snprintf(buf, PAGE_SIZE,
		 "otp usage:\n"
		 "-b : Read block directly from otp [word_addr].[num_of_words]\n"
		 "-c : Read word from cache [word_addr].[num_of_words]\n"
		 "-d : Set device id directly to otp[0x6000/0x6010/0x6020]\n"
		 "-f : Write file otpX.bin to otp [word_addr].[num_of_words]\n"
		 "-r : Read word directly from otp [word_addr]\n"
		 "-t : Print table\n");

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));

	return err;
}

static int _cl_otp_read(struct cl_chip *chip, u32 addr, u32 *data)
{
	unsigned long delay = OTP_INIT_DELAY;
	int cnt = OTP_MAX_POLLS;

	/* Wait for OTP_READY */
	while (!otp_otp_stat_otp_ready_getf(chip) && cnt--) {
		udelay(delay);
		delay <<= 1;
	}

	if (!cnt && !otp_otp_stat_otp_ready_getf(chip)) {
		cl_dbg_chip_err(chip, "OTP device busy\n");
		return -1;
	}

	/* Define addr of the fuse */
	otp_otp_addr_set(chip, addr);

	/* Write READ_CMD to OPT_CMD */
	otp_otp_cmd_otp_cmd_setf(chip, OTP_READ_CMD);

	while (!otp_otp_stat_otp_ready_getf(chip) && cnt--) {
		udelay(delay);
		delay <<= 1;
	}

	if (!cnt && !otp_otp_stat_otp_ready_getf(chip)) {
		cl_dbg_chip_err(chip, "OTP device busy\n");
		return -1;
	}

	if (otp_otp_stat_otp_rd_ded_getf(chip))
		return -1;

	*data = otp_otp_read_val_get(chip);

	return 0;
}

static int cl_otp_read_block(struct cl_chip *chip, u32 addr, u32 *data, u16 num_of_words)
{
	u16 words_left_to_read = num_of_words;

	if (!data)
		return -EFAULT;

	if (addr + num_of_words * OTP_SIZE_WORD > OTP_NUM_BYTES)
		return -ENXIO;

	do {
		if (_cl_otp_read(chip, addr, data)) {
			cl_dbg_chip_err(chip, "Error reading address %u\n",
					addr);

			/* Read OTP_SIZE_WORD failed */
			return words_left_to_read;
		}

		words_left_to_read--;
		addr++;
		data++;
	} while (words_left_to_read);

	return words_left_to_read;
}

static int cl_otp_init_blow(struct cl_chip *chip) // phase a+b
{
	unsigned long delay = OTP_INIT_DELAY;
	int cnt = OTP_MAX_POLLS;

	/* Open OTP module */
	otp_otp_key_set(chip, OTP_KEY_VAL1);
	otp_otp_key_set(chip, OTP_KEY_VAL2);

	/* Wait for OTP_READY */
	while (!otp_otp_stat_otp_ready_getf(chip) && cnt--) {
		udelay(delay);
		delay <<= 1;
	}

	if (!cnt && !otp_otp_stat_otp_ready_getf(chip)) {
		cl_dbg_chip_err(chip, "OTP device busy\n");
		return -1;
	}

	return 0;
}

static inline void cl_otp_end_blow(struct cl_chip *chip) //phase i
{
	otp_otp_key_set(chip, 0x00);
}

static int _cl_otp_write(struct cl_chip *chip, u32 addr, u32 val) //phase c +d+e
{
	unsigned long delay = OTP_INIT_DELAY;
	int cnt = OTP_MAX_POLLS;

	otp_otp_addr_set(chip, addr);

	otp_otp_write_val_set(chip, val);

	otp_otp_cmd_set(chip, OTP_WRITE_CMD);

	/* Wait for OTP_READY */
	while (!otp_otp_stat_otp_ready_getf(chip) && cnt--) {
		udelay(delay);
		delay <<= 1;
	}

	if (!cnt && !otp_otp_stat_otp_ready_getf(chip)) {
		cl_dbg_chip_err(chip, "OTP device busy\n");
		return -1;
	}

	if (otp_otp_stat_otp_write_failed_getf(chip)) {
		cl_dbg_chip_err(chip, "OTP write error\n");
		return -1;
	}

	return 0;
}

static int cl_otp_write_word(struct cl_chip *chip, u32 addr, u32 val)
{
	void *write_block = NULL;
	u32 read_data = 0;

	if (!cl_otp_read_block(chip, addr, &read_data, 1)) {
		if (read_data) {
			cl_dbg_chip_err(chip,
					"Error : word %u already have value\n",
					addr);
			return -EPERM;
		}
	}

	if (cl_otp_init_blow(chip))
		return -1;

	if (_cl_otp_write(chip, addr, val))
		return -1;

	cl_otp_end_blow(chip);

	write_block = (u32 *)chip->otp_cache + addr;
	memcpy(write_block, &val, OTP_SIZE_WORD);

	return 0;
}

static int cl_otp_set_device_id(struct cl_chip *chip, u16 device_id)
{
	if (device_id != 0x6000 &&
	    device_id != 0x6010 &&
	    device_id != 0x6020) {
		cl_dbg_chip_err(chip, "Invalid device id [0x%x]\n", device_id);
		return -EPERM;
	}

	if (chip->conf->ce_otp_mode == OTP_MODE) {
		cl_dbg_chip_err(chip, "No permition to write directly to otp\n");
		return -EPERM;
	}

	return cl_otp_write_api(chip, (u8 *)(&(device_id)), SIZE_DEVICE_ID_OTP, ADDR_DEVICE_ID_OTP);
}

static int otp_load_from_otp(struct cl_chip *chip)
{
	u32 *cache = (u32 *)chip->otp_cache;
	u32 *bitmap = chip->bitmap_broken_otp_addr;
	u16 i;

	for (i = 0; i < OTP_NUM_BYTES / OTP_SIZE_WORD; i++)
		if (_cl_otp_read(chip, i, &cache[i]) == -1) {
			bitmap[i / OTP_BROKEN_BITMAP_ELEM_SIZE] |=
			BIT(i % OTP_BROKEN_BITMAP_ELEM_SIZE);
			cl_dbg_chip_err(chip, "OTP Read: addr 0x%x is broken\n", i);
		}

	return 0;
}

static bool otp_test_bitmap_broken_addr(const u32 *bitmap, u16 addr)
{
	u8 arr_idx = addr >> OTP_BROKEN_BITMAP_ELEM_BITS_NUM;
	u8 bit_idx = addr % OTP_BROKEN_BITMAP_ELEM_SIZE;

	/* Convert non-zero to true and zero to false */
	return !!(bitmap[arr_idx] & BIT(bit_idx));
}

static int otp_bin_read_block(struct cl_chip *chip, u16 addr, u16 num_of_words, u32 *data)
{
	void *read_block = NULL;

	if (!data)
		return -EFAULT;

	if (addr + num_of_words * OTP_SIZE_WORD > OTP_NUM_BYTES)
		return -ENXIO;

	read_block = (u32 *)chip->otp_cache + addr;
	memcpy(data, read_block, num_of_words * OTP_SIZE_WORD);

	return num_of_words;
}

static int otp_read_block(struct cl_chip *chip, u16 addr, u16 num_of_words, u32 *data)
{
	void *read_block = NULL;
	u16 i;

	if (!data)
		return -EFAULT;

	if (addr + num_of_words * OTP_SIZE_WORD > OTP_NUM_BYTES)
		return -ENXIO;

	read_block = ((u32 *)chip->otp_cache) + addr;
	memcpy(data, read_block, num_of_words * OTP_SIZE_WORD);

	for (i = 0; i < num_of_words; i++)
		if (otp_test_bitmap_broken_addr(chip->bitmap_broken_otp_addr, i + addr))
			cl_dbg_chip_err(chip, "OTP Read: addr 0x%x is broken\n", i + addr);

	return num_of_words;
}

static int otp_write_block(struct cl_chip *chip, u16 addr, u16 num_of_words, u8 *data)
{
	u16 words_left_to_write = num_of_words;
	u32 *full_data = (u32 *)data;

	if (!data)
		return -EFAULT;

	if (addr + num_of_words * OTP_SIZE_WORD > OTP_NUM_BYTES)
		return -ENXIO;

	do {
		if (cl_otp_write_word(chip, addr, *full_data)) {
			cl_dbg_chip_err(chip, "Error writing address %u\n",
					addr);

			/* Written less bytes than num_of_words */
			return 0;
		}
		words_left_to_write -= 1;
		addr += 1;
		full_data += 1;
	} while (words_left_to_write);

	return num_of_words - words_left_to_write;
}

static int otp_load_from_bin(struct cl_chip *chip)
{
	char filename[CL_FILENAME_MAX];
	size_t size = 0;

	snprintf(filename, sizeof(filename), "otp%u.bin", chip->idx);

	size = cl_file_open_and_read(chip, filename,
				     (char **)&chip->otp_cache);
	if (size != OTP_NUM_BYTES) {
		cl_dbg_chip_err(chip,
				"Invalid OTP size - %s (actual %zu) (expected %d)\n",
				filename, size, OTP_NUM_BYTES);
		return -1;
	}

	return 0;
}

static int otp_write_to_bin(struct cl_chip *chip)
{
	char filename[CL_PATH_MAX];

	snprintf(filename, sizeof(filename),
		 "%s/otp/otp%u.bin",
		 cl_config_dir, chip->idx);

	return cl_file_open_and_write(filename, O_WRONLY | O_CREAT,
				      (char *)chip->otp_cache, OTP_NUM_BYTES);
}

static int otp_bin_write_block(struct cl_chip *chip, u16 addr, u16 num_of_bytes, u8 *data)
{
	u8 *base;
	u16 *offset_addr;

	if (!data)
		return -EFAULT;

	if (addr + num_of_bytes > OTP_NUM_BYTES)
		return -ENXIO;

	base = (u8 *)chip->otp_cache;
	offset_addr = (u16 *)(base + addr);
	memmove(offset_addr, data, num_of_bytes);

	if (otp_write_to_bin(chip))
		return -1;

	return num_of_bytes;
}

static int cl_otp_init_bin(struct cl_chip *chip)
{
	if (otp_load_from_bin(chip))
		return -1;

	chip->otp_read_block = otp_bin_read_block;
	chip->otp_write_block = otp_bin_write_block;

	return 0;
}

static int cl_otp_init_otp(struct cl_chip *chip)
{
	chip->otp_cache = kzalloc(OTP_NUM_BYTES, GFP_KERNEL);

	if (!chip->otp_cache)
		return -ENOMEM;

	memset(chip->bitmap_broken_otp_addr, 0, sizeof(u32) * 8);

	if (!chip->otp_cache)
		return -1;

	if (otp_load_from_otp(chip))
		return -1;

	chip->otp_read_block = otp_read_block;
	chip->otp_write_block = otp_write_block;

	return 0;
}

static int cl_otp_read_byte(struct cl_chip *chip, u8 *data, u16 byte_addr)
{
	u16 addr = byte_addr / OTP_SIZE_WORD;
	u32 single_word = 0;
	u8 offset = byte_addr % OTP_SIZE_WORD;
	u8 *single_byte;

	if (cl_otp_read_api(chip, &single_word, 1, addr))
		return -1;

	single_byte = (u8 *)&single_word;

	memcpy(data, single_byte + offset, 1);

	return 0;
}

static int cl_otp_print_table(struct cl_hw *cl_hw)
{
	int err = 0;
	int otp_idx, phy_idx, pl_idx;
	int size = NUM_OF_PIVOTS(cl_hw->nl_band) * MAX_ANTENNAS * MAX_POWER_LEVELS;
	u8 *cache_read_data = kzalloc(size, GFP_KERNEL);

	if (!cache_read_data)
		return -ENOMEM;

	if (!cl_otp_read_bytes(cl_hw->chip, cache_read_data, size,
			       cl_calibration_start_addr(cl_hw->nl_band, 0))) {
		char *buf = NULL;
		ssize_t buf_size;
		int len = 0, i = 0;

		cl_snprintf(&buf, &len, &buf_size,
			    "----------------------------------------------\n"
			    "| chan  |  phy  |   pl  | power offset (pdi) |\n"
			    "----------------------------------------------\n");

		for (pl_idx = 0; pl_idx < MAX_POWER_LEVELS; pl_idx++)
			for (phy_idx = 0; phy_idx < MAX_ANTENNAS; phy_idx++)
				for (otp_idx = 0; otp_idx < NUM_OF_PIVOTS(cl_hw->nl_band);
				     otp_idx++) {
					u8 channel_idx = idx_chan_from_otp_idx(cl_hw, otp_idx);
					int pdi = cache_read_data[i];

					cl_snprintf(&buf, &len, &buf_size,
						    "| %5d | %5d | %5d | %9d (%5d) |\n",
						    cl_ch_idx_to_channel(cl_hw, channel_idx),
						    phy_idx, pl_idx,
						    cl_calibration_pdi_to_power_offset(pdi), pdi);
						    cl_snprintf(&buf, &len, &buf_size,
								"-----------------------------"
								"-----------------\n");

					i++;
				}

		err = cl_vendor_reply(cl_hw, buf, strlen(buf));
		kfree(buf);
	}

	kfree(cache_read_data);

	return err;
}

int cl_otp_set_addr(struct wiphy *wiphy, struct wireless_dev *wdev,
		    const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	u16 addr = *(u16 *)data;
	u16 len = *((u16 *)data + 1);
	u8 *otp_data = (u8 *)((u16 *)data + 2);
	u32 otp_memory_end = OTP_NUM_BYTES;

	cl_dbg_trace(cl_hw, "addr %u len %u\n", addr, len);

	if (otp_memory_end < (addr + len)) {
		cl_dbg_err(cl_hw, "Invalid otp addr 0x%x, valid are: 0 - %u\n",
			   addr, otp_memory_end);
		return -EINVAL;
	}

	if (cl_hw->chip->conf->ce_otp_mode == OTP_MODE) {
		cl_dbg_err(cl_hw, "No permition to write directly to otp\n");
		return -EPERM;
	}

	return cl_otp_write_api(cl_hw->chip, otp_data, len, addr);
}

int cl_otp_set_module_hw_type(struct wiphy *wiphy, struct wireless_dev *wdev,
			      const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	u8 module_hw_type = *(u8 *)((u16 *)data + 2);

	if (module_hw_type >= MODULE_HW_MODE_MAX) {
		cl_dbg_err(cl_hw, "Invalid module hw type = %d\n", module_hw_type);
		return -EINVAL;
	}

	return cl_otp_set_addr(wiphy, wdev, data, data_len);
}

int cl_otp_get_addr(struct wiphy *wiphy, struct wireless_dev *wdev,
		    void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	u16 addr = *(u16 *)data;
	u16 len = *((u16 *)data + 1);
	int reply_len;
	struct cl_otp_get_reply *reply = NULL;
	struct cl_chip *chip = cl_hw->chip;
	int ret = 0;
	u32 otp_memory_end = OTP_NUM_BYTES;
	u8 otp_mode = chip->conf->ce_otp_mode;

	reply_len = sizeof(struct cl_otp_get_reply) + len;
	reply = kzalloc(reply_len, GFP_KERNEL);

	if (!reply)
		return -ENOMEM;

	reply->otp_mode = otp_mode;

	cl_dbg_trace(cl_hw, "addr %u len %u\n", addr, len);

	if (otp_memory_end < (addr + len)) {
		cl_dbg_err(cl_hw,
			   "size check failed: last addr = 0x%x, otp memory end"
			   " = 0x%x, otp_mode = %u\n", (addr + len),
			   otp_memory_end, otp_mode);
		ret = -EINVAL;
		goto otp_fail;
	}

	if (cl_otp_read_bytes(chip, reply->otp_data, len, addr)) {
		cl_dbg_err(cl_hw, "Error reading otp addr 0x%x: len %u\n",
			   addr, len);
		ret = -EXDEV;
		goto otp_fail;
	}

	ret = cl_vendor_reply(cl_hw, (void *)reply, reply_len);

otp_fail:
	kfree(reply);

	return ret;
}

int cl_otp_help(struct wiphy *wiphy, struct wireless_dev *wdev,
		void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	char *ret_buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!ret_buf)
		return -ENOMEM;

	snprintf(ret_buf, PAGE_SIZE,
		 "usage:\n"
		 "get mac - Read MAC address from otp\n"
		 "get power_level <power_level> - read power level wifi value\n"
		 "get freq_offset - Read frequency offset from otp\n"
		 "get module_hw_type - Read module hw type (0-python, 1-python-pick)\n"
		 "get module_hw_rev_id - Read module hw Rev ID (major:minor)\n"
		 "get rfic_wifi_version - Read rfic wifi version for calib\n"
		 "get rfic_bt_version - Read rfic bt version for calib\n"
		 "get rfic_lut_version - Read rfic lut version for calib\n"
		 "get calib <power_level> <ant> <ch> - get calibrated power offset for a given"
		 " antenna and channel\n"
		 "set addr <byte_addr> <value> write byte to otp.bin,"
		 " valid only for ce_otp_mode=0\n"
		 "set mac <macaddr> - Set MAC addr to current device"
		 " valid only for ce_otp_mode=0\n"
		 "set power_level <power_level> <val> - write power level wifi value,"
		 " valid only for ce_otp_mode=0\n"
		 "set freq_offset <0 - 959> - Write frequency offset to otp,"
		 " valid only for ce_otp_mode=0\n"
		 "set module_hw_type <0-python, 1-python-pick> - Set module hw type,"
		 " valid only for ce_otp_mode=0\n"
		 "set module_hw_rev_id <major:minor> - Set module hw Rev ID,"
		 " valid only for ce_otp_mode=0\n"
		 "set rfic_wifi_version - Set rfic wifi version for calib,"
		 " valid only for ce_otp_mode=0\n"
		 "set rfic_bt_version - Set rfic bt version for calib,"
		 " valid only for ce_otp_mode=0\n"
		 "set rfic_lut_version - Set rfic lut version for calib,"
		 " valid only for ce_otp_mode=0\n"
		 "set calib <power_level> <antenna> <channel: 0-low, 1-center1, 2-center2,"
		 " 3-center3, 4-center4, 5-high> <power_offset> - set calibrated power offset for a"
		 " given power_level, antenna and channel, valid only for ce_otp_mode=0\n");

	err = cl_vendor_reply(cl_hw, ret_buf, strlen(ret_buf));
	kfree(ret_buf);

	return err;
}

int cl_otp_read_api(struct cl_chip *chip, u32 *data, u16 size, u16 addr)
{
	if (size != chip->otp_read_block(chip, addr, size, data)) {
		cl_dbg_chip_err(chip, "Error reading otp word 0x%x\n", addr);
		return -1;
	}

	return 0;
}

int cl_otp_write_api(struct cl_chip *chip, u8 *data, u16 size, u16 addr)
{
	if (size != chip->otp_write_block(chip, addr, size, data)) {
		cl_dbg_chip_err(chip, "Error writing otp addr 0x%x\n", addr);
		return -1;
	}

	return 0;
}

int cl_otp_init(struct cl_chip *chip)
{
	u8 otp_mode = chip->conf->ce_otp_mode;

	if (otp_mode == OTP_MODE_BIN)
		return cl_otp_init_bin(chip);
	else if (otp_mode == OTP_MODE)
		return cl_otp_init_otp(chip);

	return -1;
}

int cl_otp_read_bytes(struct cl_chip *chip, u8 *data, u16 num_of_bytes, u16 byte_addr)
{
	u16 num_of_left_bytes = num_of_bytes;
	u16 tmp = OTP_SIZE_WORD - (byte_addr % OTP_SIZE_WORD);
	u16 num_of_start_bytes = min(tmp, num_of_bytes);
	u8 i;
	u16 num_of_words = 0;

	for (i = 0; i < num_of_start_bytes; i++) {
		if (cl_otp_read_byte(chip, data, byte_addr))
			return -1;

		data++;
		byte_addr++;
	}

	num_of_left_bytes -= num_of_start_bytes;

	if (num_of_left_bytes >= OTP_SIZE_WORD && !(byte_addr % OTP_SIZE_WORD)) {
		num_of_words = num_of_left_bytes / OTP_SIZE_WORD;
		u16 addr = byte_addr / OTP_SIZE_WORD;

		if (cl_otp_read_api(chip, (u32 *)data, num_of_words, addr))
			return -1;

		num_of_left_bytes -= num_of_words * OTP_SIZE_WORD;
	}

	byte_addr += num_of_words * OTP_SIZE_WORD;
	data += num_of_words * OTP_SIZE_WORD;

	for (i = 0; i < num_of_left_bytes; i++) {
		if (cl_otp_read_byte(chip, data, byte_addr))
			return -1;

		data++;
		byte_addr++;
	}

	return 0;
}

int cl_otp_cli(struct cl_hw *cl_hw, struct cli_params *cli_params)
{
	struct cl_chip *chip = cl_hw->chip;
	bool read_block = false;
	bool cache_read_word = false;
	bool set_device_id = false;
	bool write_file = false;
	bool read_word = false;
	bool print_table = false;
	u32 expected_params = -1;
	u32 read_data = 0;
	char ret_buf[STR_LEN_64B] = { 0 };

	switch (cli_params->option) {
	case 'b':
		read_block = true;
		expected_params = 2;
		break;
	case 'c':
		cache_read_word = true;
		expected_params = 2;
		break;
	case 'd':
		set_device_id = true;
		expected_params = 1;
		break;
	case 'f':
		write_file = true;
		expected_params = 2;
		break;
	case 'r':
		read_word = true;
		expected_params = 1;
		break;
	case 't':
		print_table = true;
		expected_params = 0;
		break;
	case '?':
		return cl_otp_cli_help(cl_hw);
	default:
		cl_dbg_err(cl_hw, "Illegal option (%c) - try '?' for help\n", cli_params->option);
		goto out_err;
	}

	if (expected_params != cli_params->num_params) {
		cl_dbg_err(cl_hw, "Wrong number of arguments (expected %u) (actual %u)\n",
			   expected_params, cli_params->num_params);
		goto out_err;
	}

	if (read_block) {
		u32 addr = (u32)cli_params->params[0];
		u16 num_of_words = (u16)cli_params->params[1];
		u32 *cache_read_data = kzalloc(num_of_words, GFP_KERNEL);
		int err = 0;

		if (!cache_read_data)
			return -ENOMEM;

		if (!cl_otp_read_block(chip, addr, cache_read_data, num_of_words)) {
			int i;
			char *buf = NULL;
			ssize_t buf_size;
			int len = 0;

			for (i = 0; i < num_of_words; i++)
				cl_snprintf(&buf, &len, &buf_size,
					    "OTP Read: addr 0x%x = 0x%x\n",
					    addr + i, cache_read_data[i]);

			err = cl_vendor_reply(cl_hw, buf, strlen(buf));
		}

		kfree(cache_read_data);

		return err;
	}

	if (cache_read_word) {
		u16 addr = (u16)cli_params->params[0];
		u16 num_of_words = (u16)cli_params->params[1];
		u32 *cache_read_data = kzalloc(num_of_words, GFP_KERNEL);

		if (!cache_read_data)
			return -ENOMEM;

		if (!cl_otp_read_api(chip, cache_read_data, num_of_words, addr)) {
			int i;
			char *buf = NULL;
			ssize_t buf_size;
			int len = 0;
			int err = 0;

			for (i = 0; i < num_of_words; i++)
				cl_snprintf(&buf, &len, &buf_size,
					    "OTP Read: word 0x%x = 0x%x\n",
					    addr + i, cache_read_data[i]);

			err = cl_vendor_reply(cl_hw, buf, strlen(buf));
		}

		kfree(cache_read_data);

		return 0;
	}

	if (set_device_id) {
		u16 device_id = (u16)cli_params->params[0];

		return cl_otp_set_device_id(chip, device_id);
	}

	if (write_file) {
		int addr = cli_params->params[0];
		u16 num_of_words = cli_params->params[1];
		size_t size = 0;
		char *file = NULL;
		char filename[CL_FILENAME_MAX];
		int num_wrote_words = 0;

		snprintf(filename, sizeof(filename), "otp%u.bin", chip->idx);

		size = cl_file_open_and_read(chip, filename, &file);

		if (!file)
			return -ENOMEM;

		if (size != OTP_NUM_BYTES) {
			cl_dbg_chip_err(chip,
					"Invalid OTP size - %s (actual %zu) (expected %d)\n",
					filename, size, OTP_NUM_BYTES);

			kfree(file);
			return -1;
		}

		num_wrote_words = otp_write_block(chip, addr, num_of_words,
						  file + addr * OTP_SIZE_WORD);
		if (num_wrote_words <= 0)
			cl_dbg_chip_err(chip, "OTP write error!\n");
		else
			cl_dbg_err(cl_hw, "num words write is (%d)\n", num_wrote_words);

		kfree(file);
		return 0;

	}

	if (read_word) {
		u32 addr = (u32)cli_params->params[0];

		if (!_cl_otp_read(chip, addr, &read_data)) {
			snprintf(ret_buf, sizeof(ret_buf),
				 "OTP Read: addr 0x%x = 0x%x\n", addr, read_data);
			cl_vendor_reply(cl_hw, ret_buf, strlen(ret_buf));
		} else
			cl_dbg_chip_err(chip, "Error reading otp word 0x%x\n", addr);
	}

	if (print_table) {
		cl_otp_print_table(cl_hw);
		return 0;
	}

out_err:
	return -EIO;
}

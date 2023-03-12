// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include <linux/delay.h>
#include <linux/kernel.h>
#include "cl_e2p.h"
#include "cl_utils.h"
#include "file.h"
#include "chip.h"
#include "reg_access.h"

#define EEPROM_VERSION 1

/* EEPROM Parameters - Suitable for ATMEL AT24C16BN */
#define E2P_SIZE       0x800               /* 2KB = 16Kbit */
#define E2P_PAGE_SIZE  0x10                /* 16 Bytes */
#define E2P_PAGE_MASK  (E2P_PAGE_SIZE - 1) /* 0xF */
#define E2P_PAGE_SHIFT 0x4

#define PAGE_NUM(addr) ((addr) >> E2P_PAGE_SHIFT)
#define PAGE_OFF(addr) ((addr) & E2P_PAGE_MASK)

enum bit_num {
	BIT0,
	BIT1,
	BIT2,
	BIT3,
	BIT4,
	BIT5,
	BIT6,
	BIT7,
	BIT8,
	BIT9,
	BIT10,
	BIT11,
	BIT12,
	BIT13,
	BIT14,
	BIT15,
	BIT16,
	BIT17,
	BIT18,
	BIT19,
	BIT20,
	BIT21,
	BIT22,
	BIT23,
	BIT24,
	BIT25,
	BIT26,
	BIT27,
	BIT28,
	BIT29,
	BIT30,
	BIT31
};

/*
 * MACSYS_I2C:: PRERLO (0x0) - Clock Prescale register lo-byte
 * Width: 8, Access: RW, Reset: 0xff.
 */
#define I2C_PRERLO (I2C_REG_BASE_ADDR + 0x0)

/*
 * MACSYS_I2C:: PRERHI (0x4) - Clock Prescale register lo-byte
 * Width: 8, Access: RW, Reset: 0xff.
 */
#define I2C_PRERHI (I2C_REG_BASE_ADDR + 0x4)

/*
 * MACSYS_I2C:: CTR (0x8) - Control Register
 * Width: 8, Access: RW, Reset: 0x00.
 */
#define I2C_CTR (I2C_REG_BASE_ADDR + 0x8)

#define EN (BIT7) /* ‘1’ the core is enabled. */

/*
 * MACSYS_I2C:: TXR_RXR (0xC) - Transmit Register - Data
 * Width: 8, Access: W, Reset: 0x00.
 */
#define I2C_TXD (I2C_REG_BASE_ADDR + 0xC)

/* 7:0 TXD */
#define TXD (BIT0) /* Next byte to transmit via I2C */

#define TXD_MASK (0xFF << TXD)

/*
 * MACSYS_I2C:: TXR_RXR (0xC) - Transmit Register - Address
 * Width: 8, Access: W, Reset: 0x00.
 */
#define I2C_TXADDR (I2C_REG_BASE_ADDR + 0xC)

/*
 * 7:1 TXADDR
 * 0 RDWR
 */
#define TXADDR (BIT1) /* I2C Slave Address */
#define RDWR   (BIT0) /* ‘1’ = reading from slave. ‘0’ = writing to slave. */

#define TXADDR_MASK (0x7F << TXADDR)

/*
 * MACSYS_I2C:: TXR_RXR (0xC) - Receive Register
 * Width: 8, Access: R, Reset: 0x00.
 */
#define I2C_RXD (I2C_REG_BASE_ADDR + 0xC)

/* 7:0 RXD */
#define RXD (BIT0) /* Last byte received via I2C. */
#define RXD_MASK (0xFF << RXD)

/*
 * MACSYS_I2C:: CR_SR (0x10) - Command Register
 * Width: 8, Access: WC, Reset: 0x00.
 */
#define I2C_CR (I2C_REG_BASE_ADDR + 0x10)

/*
 * 7 STA
 * 6 STO
 * 5 RD
 * 4 WR
 * 3 ACK
 * 2:1 RES
 * 0 IACK
 */
#define STA  (BIT7) /* Generate (repeated) start condition. */
#define STO  (BIT6) /* Generate stop condition. */
#define RD   (BIT5) /* Read from slave. */
#define WR   (BIT4) /* Write to slave. */
#define ACK  (BIT3) /* When a receiver, sent ACK (ACK = ‘0’) or NACK (NACK = ‘1’). */
#define IACK (BIT0) /* Interrupt acknowledge, When set, clears a pending interrupt. */

/*
 * MACSYS_I2C:: CR_SR (0x10) - Status Register
 * Width: 8, Access: R, Reset: 0x00.
 */
#define I2C_SR (I2C_REG_BASE_ADDR + 0x10)

/*
 * 7 RX_ACK - Received acknowledge from slave - ‘1’ = No acknowledge received.
 * 6 BUSY - I2C bus busy - ‘1’ after START signal detected. ‘0’ after STOP signal detected.
 * 5 AL - Arbitration lost - This bit is set when the core lost arbitration.
 * 4:2 RES
 * 1 TIP - Transfer in progress. ‘1’ when transferring data. ‘0’ when transfer complete.
 * 0 IF - Set when interrupt is pending, cause a processor interrupt if the IEN bit is set.
 */
#define RX_ACK (BIT7)
#define BUSY   (BIT6)
#define AL     (BIT5)
#define TIP    (BIT1)
#define IF     (BIT0)

#define I2C_EEPROM_ADDR(page) (0xA0 | (((page) >> 3) & 0xE)) /* [1-0-1-0-P2-P1-P0-0] */

/* E2P_MAX_POLLS should not exceed 12 iterations (attemts) */
#define E2P_MAX_POLLS 10
#define E2P_INITIAL_DELAY 32

static int i2c_poll_xfer_acked(struct cl_chip *chip)
{
	u32 val = cl_reg_read(chip, I2C_SR);
	int cnt = E2P_MAX_POLLS;
	unsigned long delay = E2P_INITIAL_DELAY;

	while ((val & BIT(TIP)) && cnt--) {
		udelay(delay);
		val = cl_reg_read(chip, I2C_SR);
		delay <<= 1;
	}
	++cnt;

	while ((val & BIT(RX_ACK)) && cnt--) {
		udelay(delay);
		val = cl_reg_read(chip, I2C_SR);
		delay <<= 1;
	}

	if (cnt >= 0)
		return 0;

	cl_dbg_chip_err(chip, "ACK FAILED\n");
	cl_dbg_chip_trace(chip, "I2C_POLL_XFER_ACKED: val=%Xh, cnt=%d.\n", val, cnt);

	return -1;
}

static int i2c_poll_xfer_no_acked(struct cl_chip *chip)
{
	u32 val = cl_reg_read(chip, I2C_SR);
	int cnt = E2P_MAX_POLLS;
	unsigned long delay = E2P_INITIAL_DELAY;

	while ((val & BIT(TIP)) && cnt--) {
		udelay(delay);
		val = cl_reg_read(chip, I2C_SR);
		delay <<= 1;
	}

	++cnt;

	while (!(val & BIT(RX_ACK)) && cnt--) {
		udelay(delay);
		val = cl_reg_read(chip, I2C_SR);
		delay <<= 1;
	}

	if (cnt >= 0)
		return 0;

	cl_dbg_chip_err(chip, "NO ACK FAILED\n");
	cl_dbg_chip_trace(chip, "I2C_POLL_XFER_NO_ACKED: val=%Xh, cnt=%d.\n", val, cnt);

	return -1;
}

static void i2c_write_start(struct cl_chip *chip, u16 page)
{
	u32 addr = I2C_EEPROM_ADDR(page) & TXADDR_MASK;

	cl_reg_write(chip, I2C_TXADDR, addr);
	cl_reg_write(chip, I2C_CR, BIT(STA) | BIT(WR));
}

static void i2c_write(struct cl_chip *chip, u8 data)
{
	cl_reg_write(chip, I2C_TXD, data & TXD_MASK);
	cl_reg_write(chip, I2C_CR, BIT(WR));
}

static void i2c_write_stop(struct cl_chip *chip, u8 data)
{
	cl_reg_write(chip, I2C_TXD, data & TXD_MASK);
	cl_reg_write(chip, I2C_CR, BIT(STO) | BIT(WR));
}

static void i2c_read_start(struct cl_chip *chip, u16 page)
{
	u32 addr = (I2C_EEPROM_ADDR(page) & TXADDR_MASK) | BIT(RDWR);

	cl_reg_write(chip, I2C_TXADDR, addr);
	cl_reg_write(chip, I2C_CR, BIT(STA) | BIT(WR));
}

static int i2c_read_stop(struct cl_chip *chip, u8 *data)
{
	cl_reg_write(chip, I2C_CR, BIT(STO) | BIT(RD) | BIT(ACK));
	if (i2c_poll_xfer_no_acked(chip) == -1)
		return -1;
	*data = cl_reg_read(chip, I2C_RXD) & RXD_MASK;
	return 0;
}

static void e2p_reg_set_bit(struct cl_chip *chip, u32 reg, u32 bit)
{
	u32 regval = cl_reg_read(chip, reg);

	regval |= bit;
	cl_reg_write(chip, reg, regval);
}

static void e2p_reg_clear_bit(struct cl_chip *chip, u32 reg, u32 bit)
{
	u32 regval = cl_reg_read(chip, reg);

	regval &= ~bit;
	cl_reg_write(chip, reg, regval);
}

static void e2p_enable(struct cl_chip *chip)
{
	/* Disable I2C Core */
	e2p_reg_clear_bit(chip, I2C_CTR, BIT(EN));

	/*
	 * Set Pre-Scaler LO
	 * pclk = 240MHz, desired SCL = 400KHz.
	 * Prescale = [240e6 / (5*400e3) ] – 1 = 120 -1 = 119 = 77h
	 */
	cl_reg_write(chip, I2C_PRERLO, 0x77);

	/* Set Pre-Scaler HI */
	cl_reg_write(chip, I2C_PRERHI, 0x0);

	/* Enable I2C Core */
	e2p_reg_set_bit(chip, I2C_CTR, BIT(EN));
}

static int e2p_read_byte(struct cl_chip *chip, u16 addr, u8 *pbyte)
{
	if (addr > E2P_SIZE) {
		cl_dbg_chip_err(chip, "Wrong addr or len\n");
		return -1;
	}

	/* Clock in the address to read from. */
	i2c_write_start(chip, PAGE_NUM(addr));
	if (i2c_poll_xfer_acked(chip) == -1)
		return -1;

	/* Addr 8 lsbits are 4 bits page lsbits or`ed with 4 bits page offset */
	i2c_write(chip, addr);
	if (i2c_poll_xfer_acked(chip) == -1)
		return -1;

	/* Read single byte */
	i2c_read_start(chip, PAGE_NUM(addr));
	if (i2c_poll_xfer_acked(chip) == -1)
		return -1;

	return i2c_read_stop(chip, pbyte);
}

static int e2p_write_page(struct cl_chip *chip, u16 addr, u8 *val, u16 num_of_bytes)
{
	/* This is a write page (up to 16 bytes) operation indicating the offset to write to. */
	int i;

	if (num_of_bytes > E2P_PAGE_SIZE)
		return -1;

	/* Clock in the address to write to. */
	i2c_write_start(chip, PAGE_NUM(addr));
	if (i2c_poll_xfer_acked(chip) == -1)
		return -1;

	/* Addr 8 lsbits are 4 bits page lsbits or`ed with 4 bits page offset */
	i2c_write(chip, addr);
	if (i2c_poll_xfer_acked(chip) == -1)
		return -1;

	/* Clock in the data to write. */
	for (i = 0; i < (num_of_bytes - 1); i++, val++) {
		i2c_write(chip, *val);
		if (i2c_poll_xfer_acked(chip) == -1)
			return -1;
	}

	/* Clock in the last data byte to write */
	i2c_write_stop(chip, *val);
	if (i2c_poll_xfer_acked(chip) == -1)
		return -1;

	/* Make sure to wait before moving to another page */
	mdelay(4);

	return 0;
}

static int e2p_write_block(struct cl_chip *chip, u16 addr, u16 num_of_bytes, u8 *val)
{
	u16 bytes_on_curr_page = 0, bytes_left_to_write = num_of_bytes;

	do {
		bytes_on_curr_page = E2P_PAGE_SIZE - PAGE_OFF(addr);
		bytes_on_curr_page = min(bytes_left_to_write, bytes_on_curr_page);
		bytes_left_to_write -= bytes_on_curr_page;

		if (e2p_write_page(chip, addr, val, bytes_on_curr_page) == -1) {
			cl_dbg_chip_err(chip, "Error writing page %u offset %u\n",
					PAGE_NUM(addr), PAGE_OFF(addr));
			/* Written less bytes than num_of_bytes */
			return 0;
		}

		addr += bytes_on_curr_page;
		val += bytes_on_curr_page;
	} while (bytes_left_to_write);

	return num_of_bytes - bytes_left_to_write;
}

static int e2p_load_from_eeprom(struct cl_chip *chip)
{
	u8 *cache = (u8 *)chip->eeprom_cache;
	u16 i;

	for (i = 0; i < EEPROM_NUM_BYTES; i++)
		if (e2p_read_byte(chip, i, &cache[i]) == -1)
			return -1;

	return 0;
}

static int e2p_eeprom_read_block(struct cl_chip *chip, u16 addr, u16 num_of_bytes, u8 *val)
{
	void *read_block = NULL;

	if (!val)
		return -EFAULT;

	if (addr + num_of_bytes > EEPROM_NUM_BYTES)
		return -ENXIO;

	read_block = (u8 *)chip->eeprom_cache + addr;
	memcpy(val, read_block, num_of_bytes);

	return num_of_bytes;
}

static int e2p_eeprom_write_block(struct cl_chip *chip, u16 addr, u16 num_of_bytes, u8 *val)
{
	int bytes_written = -EIO;
	void *write_block = NULL;

	if (!val)
		return -EFAULT;

	if (addr + num_of_bytes > EEPROM_NUM_BYTES)
		return -ENXIO;

	bytes_written = e2p_write_block(chip, addr, num_of_bytes, val);
	write_block = (u8 *)chip->eeprom_cache + addr;
	memcpy(write_block, val, num_of_bytes);

	return bytes_written;
}

static int cl_e2p_init_eeprom(struct cl_chip *chip)
{
	chip->eeprom_cache = kzalloc(EEPROM_NUM_BYTES, GFP_KERNEL);

	if (!chip->eeprom_cache)
		return -1;

	e2p_enable(chip);

	if (e2p_load_from_eeprom(chip))
		return -1;

	chip->eeprom_read_block = e2p_eeprom_read_block;
	chip->eeprom_write_block = e2p_eeprom_write_block;

	return 0;
}

int cl_e2p_init(struct cl_chip *chip)
{
	u8 eeprom_en = chip->conf->ce_eeprom_en;

	if (eeprom_en == E2P_MODE_DISABLED)
		return 0;
	else if (eeprom_en == E2P_MODE_ENABLED)
		return cl_e2p_init_eeprom(chip);

	return -1;
}

int cl_e2p_write(struct cl_chip *chip, u8 *data, u16 size, u16 addr)
{
	if (size != chip->eeprom_write_block(chip, addr, size, data)) {
		cl_dbg_chip_err(chip, "Error writing eeprom addr 0x%x\n", addr);
		return -1;
	}

	return 0;
}

int cl_e2p_read(struct cl_chip *chip, u8 *data, u16 size, u16 addr)
{
	if (size != chip->eeprom_read_block(chip, addr, size, data)) {
		cl_dbg_chip_err(chip, "Error reading eeprom addr 0x%x\n", addr);
		return -1;
	}

	return 0;
}

int cl_e2p_get_addr(struct wiphy *wiphy, struct wireless_dev *wdev,
		    void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	u16 addr = *(u16 *)data;
	u16 len = *((u16 *)data + 1);
	int reply_len;
	struct cl_e2p_get_reply *reply = NULL;
	struct cl_chip *chip = cl_hw->chip;
	int ret = 0;
	u32 eeprom_memory_end = EEPROM_NUM_BYTES;
	u8 eeprom_en = chip->conf->ce_eeprom_en;

	reply_len = sizeof(struct cl_e2p_get_reply) + len;
	reply = kzalloc(reply_len, GFP_KERNEL);

	if (!reply)
		return -ENOMEM;

	reply->e2p_en = eeprom_en;

	cl_dbg_trace(cl_hw, "addr %u len %u\n", addr, len);

	if (eeprom_memory_end < (addr + len)) {
		cl_dbg_err(cl_hw,
			   "size check failed: last addr = 0x%x, eeprom memory end"
			   " = 0x%x, eeprom_en = %u\n", (addr + len),
			   eeprom_memory_end, eeprom_en);
		ret = -EINVAL;
		goto e2p_fail;
	}

	if (len != chip->eeprom_read_block(chip, addr, len, reply->e2p_data)) {
		cl_dbg_err(cl_hw, "Error reading eeprom addr 0x%x: len %u\n",
			   addr, len);
		ret = -EXDEV;
		goto e2p_fail;
	}

	ret = cl_vendor_reply(cl_hw, (void *)reply, reply_len);

e2p_fail:
	kfree(reply);

	return ret;
}

int cl_e2p_set_addr(struct wiphy *wiphy, struct wireless_dev *wdev,
		    const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	u16 addr = *(u16 *)data;
	u16 len = *((u16 *)data + 1);
	u8 *e2p_data = (u8 *)((u16 *)data + 2);
	u32 eeprom_memory_end = EEPROM_NUM_BYTES;

	cl_dbg_trace(cl_hw, "addr %u len %u\n", addr, len);

	if (eeprom_memory_end < (addr + len)) {
		cl_dbg_err(cl_hw, "Invalid E2P addr 0x%x, valid are: 0 - %u\n",
			   addr, eeprom_memory_end);
		return -EINVAL;
	}

	return cl_e2p_write(cl_hw->chip, e2p_data, len, addr);
}

int cl_e2p_set_module_hw_type(struct wiphy *wiphy, struct wireless_dev *wdev,
			      const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	u8 module_hw_type = *(u8 *)((u16 *)data + 2);

	if (module_hw_type >= MODULE_HW_MODE_MAX) {
		cl_dbg_err(cl_hw, "Invalid module hw type = %d\n", module_hw_type);
		return -EINVAL;
	}

	return cl_e2p_set_addr(wiphy, wdev, data, data_len);
}

int cl_e2p_help(struct wiphy *wiphy, struct wireless_dev *wdev,
		void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	char *ret_buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!ret_buf)
		return -ENOMEM;

	snprintf(ret_buf, PAGE_SIZE,
		 "usage:\n"
		 "get addr <address> - Read value from specified addr on eeprom\n"
		 "get power_level <power_level> - read power level wifi value\n"
		 "get freq_offset - Read frequency offset from eeprom\n"
		 "get module_hw_type - Read module hw type (0-python, 1-python-peak)\n"
		 "get module_hw_rev_id - Read module hw Rev ID (major.minor)\n"
		 "get rfic_wifi_version - Read rfic wifi version for calib\n"
		 "get rfic_bt_version - Read rfic bt version for calib\n"
		 "get rfic_lut_version - Read rfic lut version for calib\n"
		 "get table - Read table from eeprom\n"
		 "get calib <power_level> <ant> <ch> - get calibrated power offset for a given"
		 " antenna and channel\n"
		 "set addr <address> <value> - Write value to specified address on eeprom\n"
		 "set power_level <power_level> <val> - write power level wifi value\n"
		 "set freq_offset <0 - 959> - Write frequency offset to eeprom\n"
		 "set module_hw_type <0-python, 1-python-peak> - Set module hw type\n"
		 "set module_hw_rev_id <major.minor> - Set module hw Rev ID\n"
		 "set rfic_wifi_version - Set rfic wifi version for calib\n"
		 "set rfic_bt_version - Set rfic bt version for calib\n"
		 "set rfic_lut_version - Set rfic lut version for calib\n"
		 "set calib <power_level> <antenna> <channel: 0-low, 1-center1, 2-center2,"
		 " 3-center3, 4-center4, 5-high> <power_offset> <temperature (optional)> -"
		 " set calibrated power offset for a given antenna and channel\n");

	err = cl_vendor_reply(cl_hw, ret_buf, strlen(ret_buf));
	kfree(ret_buf);

	return err;
}


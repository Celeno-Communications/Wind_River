/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef REG_IO_CTRL_H
#define REG_IO_CTRL_H

#include "reg_access.h"
#include "chip.h"

#define REG_IO_CTRL_BASE_ADDR 0x007C7000

/**
 * @brief SCL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    13    GPIO_IN                   1
 *    12    GPIO_OUT                  0
 *    11    GPIO_OE                   0
 *    10    GPIO_ENABLE               0
 *    09    input_enable              1
 *    07:06 DRIVER_PULL_STATE         0x2
 *    05:03 OUTPUT_PAD_STRENGTH       0x2
 *    02:00 MUX_SELECT                0x0
 * </pre>
 */
#define IO_CTRL_SCL_ADDR        (REG_IO_CTRL_BASE_ADDR + 0x00000004)
#define IO_CTRL_SCL_OFFSET      0x00000004
#define IO_CTRL_SCL_INDEX       0x00000001
#define IO_CTRL_SCL_RESET       0x000008C8

static inline u32 io_ctrl_scl_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, IO_CTRL_SCL_ADDR);
}

static inline void io_ctrl_scl_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, IO_CTRL_SCL_ADDR, value);
}

/* Field definitions */
#define IO_CTRL_SCL_GPIO_IN_BIT             ((u32)0x00002000)
#define IO_CTRL_SCL_GPIO_IN_POS             13
#define IO_CTRL_SCL_GPIO_OUT_BIT            ((u32)0x00001000)
#define IO_CTRL_SCL_GPIO_OUT_POS            12
#define IO_CTRL_SCL_GPIO_OE_BIT             ((u32)0x00000800)
#define IO_CTRL_SCL_GPIO_OE_POS             11
#define IO_CTRL_SCL_GPIO_ENABLE_BIT         ((u32)0x00000400)
#define IO_CTRL_SCL_GPIO_ENABLE_POS         10
#define IO_CTRL_SCL_INPUT_ENABLE_BIT        ((u32)0x00000200)
#define IO_CTRL_SCL_INPUT_ENABLE_POS        9
#define IO_CTRL_SCL_DRIVER_PULL_STATE_MASK    ((u32)0x000000C0)
#define IO_CTRL_SCL_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_SCL_DRIVER_PULL_STATE_WIDTH    ((u32)0x00000002)
#define IO_CTRL_SCL_OUTPUT_PAD_STRENGTH_MASK    ((u32)0x00000038)
#define IO_CTRL_SCL_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_SCL_OUTPUT_PAD_STRENGTH_WIDTH    ((u32)0x00000003)
#define IO_CTRL_SCL_MUX_SELECT_MASK         ((u32)0x00000007)
#define IO_CTRL_SCL_MUX_SELECT_LSB          0
#define IO_CTRL_SCL_MUX_SELECT_WIDTH        ((u32)0x00000003)

#define IO_CTRL_SCL_GPIO_IN_RST             0x1
#define IO_CTRL_SCL_GPIO_OUT_RST            0x0
#define IO_CTRL_SCL_GPIO_OE_RST             0x0
#define IO_CTRL_SCL_GPIO_ENABLE_RST         0x0
#define IO_CTRL_SCL_INPUT_ENABLE_RST        0x1
#define IO_CTRL_SCL_DRIVER_PULL_STATE_RST    0x2
#define IO_CTRL_SCL_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_SCL_MUX_SELECT_RST          0x0

static inline void io_ctrl_scl_pack(struct cl_chip *chip, u8 gpio_in, u8 gpio_out, u8 gpio_oe, u8 gpio_enable, u8 input_enable, u8 driver_pull_state, u8 output_pad_strength, u8 mux_select)
{
	ASSERT_ERR_CHIP((((u32)gpio_in << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_out << 12) & ~((u32)0x00001000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_oe << 11) & ~((u32)0x00000800)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_enable << 10) & ~((u32)0x00000400)) == 0);
	ASSERT_ERR_CHIP((((u32)input_enable << 9) & ~((u32)0x00000200)) == 0);
	ASSERT_ERR_CHIP((((u32)driver_pull_state << 6) & ~((u32)0x000000C0)) == 0);
	ASSERT_ERR_CHIP((((u32)output_pad_strength << 3) & ~((u32)0x00000038)) == 0);
	ASSERT_ERR_CHIP((((u32)mux_select << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_SCL_ADDR, ((u32)gpio_in << 13) | ((u32)gpio_out << 12) | ((u32)gpio_oe << 11) | ((u32)gpio_enable << 10) | ((u32)input_enable << 9) | ((u32)driver_pull_state << 6) | ((u32)output_pad_strength << 3) | ((u32)mux_select << 0));
}

static inline void io_ctrl_scl_unpack(struct cl_chip *chip, u8 *gpio_in, u8 *gpio_out, u8 *gpio_oe, u8 *gpio_enable, u8 *input_enable, u8 *driver_pull_state, u8 *output_pad_strength, u8 *mux_select)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_SCL_ADDR);

	*gpio_in = (local_val & ((u32)0x00002000)) >> 13;
	*gpio_out = (local_val & ((u32)0x00001000)) >> 12;
	*gpio_oe = (local_val & ((u32)0x00000800)) >> 11;
	*gpio_enable = (local_val & ((u32)0x00000400)) >> 10;
	*input_enable = (local_val & ((u32)0x00000200)) >> 9;
	*driver_pull_state = (local_val & ((u32)0x000000C0)) >> 6;
	*output_pad_strength = (local_val & ((u32)0x00000038)) >> 3;
	*mux_select = (local_val & ((u32)0x00000007)) >> 0;
}

static inline u8 io_ctrl_scl_gpio_in_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_SCL_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline u8 io_ctrl_scl_gpio_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_SCL_ADDR);

	return (u8)((local_val & ((u32)0x00001000)) >> 12);
}

static inline void io_ctrl_scl_gpio_out_setf(struct cl_chip *chip, u8 gpioout)
{
	ASSERT_ERR_CHIP((((u32)gpioout << 12) & ~((u32)0x00001000)) == 0);
	cl_reg_write(chip, IO_CTRL_SCL_ADDR, (cl_reg_read(chip, IO_CTRL_SCL_ADDR) & ~((u32)0x00001000)) | ((u32)gpioout << 12));
}

static inline u8 io_ctrl_scl_gpio_oe_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_SCL_ADDR);

	return (u8)((local_val & ((u32)0x00000800)) >> 11);
}

static inline void io_ctrl_scl_gpio_oe_setf(struct cl_chip *chip, u8 gpiooe)
{
	ASSERT_ERR_CHIP((((u32)gpiooe << 11) & ~((u32)0x00000800)) == 0);
	cl_reg_write(chip, IO_CTRL_SCL_ADDR, (cl_reg_read(chip, IO_CTRL_SCL_ADDR) & ~((u32)0x00000800)) | ((u32)gpiooe << 11));
}

static inline u8 io_ctrl_scl_gpio_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_SCL_ADDR);

	return (u8)((local_val & ((u32)0x00000400)) >> 10);
}

static inline void io_ctrl_scl_gpio_enable_setf(struct cl_chip *chip, u8 gpioenable)
{
	ASSERT_ERR_CHIP((((u32)gpioenable << 10) & ~((u32)0x00000400)) == 0);
	cl_reg_write(chip, IO_CTRL_SCL_ADDR, (cl_reg_read(chip, IO_CTRL_SCL_ADDR) & ~((u32)0x00000400)) | ((u32)gpioenable << 10));
}

static inline u8 io_ctrl_scl_input_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_SCL_ADDR);

	return (u8)((local_val & ((u32)0x00000200)) >> 9);
}

static inline void io_ctrl_scl_input_enable_setf(struct cl_chip *chip, u8 inputenable)
{
	ASSERT_ERR_CHIP((((u32)inputenable << 9) & ~((u32)0x00000200)) == 0);
	cl_reg_write(chip, IO_CTRL_SCL_ADDR, (cl_reg_read(chip, IO_CTRL_SCL_ADDR) & ~((u32)0x00000200)) | ((u32)inputenable << 9));
}

static inline u8 io_ctrl_scl_driver_pull_state_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_SCL_ADDR);

	return (u8)((local_val & ((u32)0x000000C0)) >> 6);
}

static inline void io_ctrl_scl_driver_pull_state_setf(struct cl_chip *chip, u8 driverpullstate)
{
	ASSERT_ERR_CHIP((((u32)driverpullstate << 6) & ~((u32)0x000000C0)) == 0);
	cl_reg_write(chip, IO_CTRL_SCL_ADDR, (cl_reg_read(chip, IO_CTRL_SCL_ADDR) & ~((u32)0x000000C0)) | ((u32)driverpullstate << 6));
}

static inline u8 io_ctrl_scl_output_pad_strength_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_SCL_ADDR);

	return (u8)((local_val & ((u32)0x00000038)) >> 3);
}

static inline void io_ctrl_scl_output_pad_strength_setf(struct cl_chip *chip, u8 outputpadstrength)
{
	ASSERT_ERR_CHIP((((u32)outputpadstrength << 3) & ~((u32)0x00000038)) == 0);
	cl_reg_write(chip, IO_CTRL_SCL_ADDR, (cl_reg_read(chip, IO_CTRL_SCL_ADDR) & ~((u32)0x00000038)) | ((u32)outputpadstrength << 3));
}

static inline u8 io_ctrl_scl_mux_select_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_SCL_ADDR);

	return (u8)((local_val & ((u32)0x00000007)) >> 0);
}

static inline void io_ctrl_scl_mux_select_setf(struct cl_chip *chip, u8 muxselect)
{
	ASSERT_ERR_CHIP((((u32)muxselect << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_SCL_ADDR, (cl_reg_read(chip, IO_CTRL_SCL_ADDR) & ~((u32)0x00000007)) | ((u32)muxselect << 0));
}

/**
 * @brief SDA register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    13    GPIO_IN                   1
 *    12    GPIO_OUT                  0
 *    11    GPIO_OE                   0
 *    10    GPIO_ENABLE               0
 *    09    input_enable              1
 *    07:06 DRIVER_PULL_STATE         0x2
 *    05:03 OUTPUT_PAD_STRENGTH       0x2
 *    02:00 MUX_SELECT                0x0
 * </pre>
 */
#define IO_CTRL_SDA_ADDR        (REG_IO_CTRL_BASE_ADDR + 0x00000008)
#define IO_CTRL_SDA_OFFSET      0x00000008
#define IO_CTRL_SDA_INDEX       0x00000002
#define IO_CTRL_SDA_RESET       0x000008C8

static inline u32 io_ctrl_sda_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, IO_CTRL_SDA_ADDR);
}

static inline void io_ctrl_sda_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, IO_CTRL_SDA_ADDR, value);
}

/* Field definitions */
#define IO_CTRL_SDA_GPIO_IN_BIT             ((u32)0x00002000)
#define IO_CTRL_SDA_GPIO_IN_POS             13
#define IO_CTRL_SDA_GPIO_OUT_BIT            ((u32)0x00001000)
#define IO_CTRL_SDA_GPIO_OUT_POS            12
#define IO_CTRL_SDA_GPIO_OE_BIT             ((u32)0x00000800)
#define IO_CTRL_SDA_GPIO_OE_POS             11
#define IO_CTRL_SDA_GPIO_ENABLE_BIT         ((u32)0x00000400)
#define IO_CTRL_SDA_GPIO_ENABLE_POS         10
#define IO_CTRL_SDA_INPUT_ENABLE_BIT        ((u32)0x00000200)
#define IO_CTRL_SDA_INPUT_ENABLE_POS        9
#define IO_CTRL_SDA_DRIVER_PULL_STATE_MASK    ((u32)0x000000C0)
#define IO_CTRL_SDA_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_SDA_DRIVER_PULL_STATE_WIDTH    ((u32)0x00000002)
#define IO_CTRL_SDA_OUTPUT_PAD_STRENGTH_MASK    ((u32)0x00000038)
#define IO_CTRL_SDA_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_SDA_OUTPUT_PAD_STRENGTH_WIDTH    ((u32)0x00000003)
#define IO_CTRL_SDA_MUX_SELECT_MASK         ((u32)0x00000007)
#define IO_CTRL_SDA_MUX_SELECT_LSB          0
#define IO_CTRL_SDA_MUX_SELECT_WIDTH        ((u32)0x00000003)

#define IO_CTRL_SDA_GPIO_IN_RST             0x1
#define IO_CTRL_SDA_GPIO_OUT_RST            0x0
#define IO_CTRL_SDA_GPIO_OE_RST             0x0
#define IO_CTRL_SDA_GPIO_ENABLE_RST         0x0
#define IO_CTRL_SDA_INPUT_ENABLE_RST        0x1
#define IO_CTRL_SDA_DRIVER_PULL_STATE_RST    0x2
#define IO_CTRL_SDA_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_SDA_MUX_SELECT_RST          0x0

static inline void io_ctrl_sda_pack(struct cl_chip *chip, u8 gpio_in, u8 gpio_out, u8 gpio_oe, u8 gpio_enable, u8 input_enable, u8 driver_pull_state, u8 output_pad_strength, u8 mux_select)
{
	ASSERT_ERR_CHIP((((u32)gpio_in << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_out << 12) & ~((u32)0x00001000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_oe << 11) & ~((u32)0x00000800)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_enable << 10) & ~((u32)0x00000400)) == 0);
	ASSERT_ERR_CHIP((((u32)input_enable << 9) & ~((u32)0x00000200)) == 0);
	ASSERT_ERR_CHIP((((u32)driver_pull_state << 6) & ~((u32)0x000000C0)) == 0);
	ASSERT_ERR_CHIP((((u32)output_pad_strength << 3) & ~((u32)0x00000038)) == 0);
	ASSERT_ERR_CHIP((((u32)mux_select << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_SDA_ADDR,  ((u32)gpio_in << 13) | ((u32)gpio_out << 12) | ((u32)gpio_oe << 11) | ((u32)gpio_enable << 10) | ((u32)input_enable << 9) | ((u32)driver_pull_state << 6) | ((u32)output_pad_strength << 3) | ((u32)mux_select << 0));
}

static inline void io_ctrl_sda_unpack(struct cl_chip *chip, u8 *gpio_in, u8 *gpio_out, u8 *gpio_oe, u8 *gpio_enable, u8 *input_enable, u8 *driver_pull_state, u8 *output_pad_strength, u8 *mux_select)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_SDA_ADDR);

	*gpio_in = (local_val & ((u32)0x00002000)) >> 13;
	*gpio_out = (local_val & ((u32)0x00001000)) >> 12;
	*gpio_oe = (local_val & ((u32)0x00000800)) >> 11;
	*gpio_enable = (local_val & ((u32)0x00000400)) >> 10;
	*input_enable = (local_val & ((u32)0x00000200)) >> 9;
	*driver_pull_state = (local_val & ((u32)0x000000C0)) >> 6;
	*output_pad_strength = (local_val & ((u32)0x00000038)) >> 3;
	*mux_select = (local_val & ((u32)0x00000007)) >> 0;
}

static inline u8 io_ctrl_sda_gpio_in_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_SDA_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline u8 io_ctrl_sda_gpio_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_SDA_ADDR);

	return (u8)((local_val & ((u32)0x00001000)) >> 12);
}

static inline void io_ctrl_sda_gpio_out_setf(struct cl_chip *chip, u8 gpioout)
{
	ASSERT_ERR_CHIP((((u32)gpioout << 12) & ~((u32)0x00001000)) == 0);
	cl_reg_write(chip, IO_CTRL_SDA_ADDR, (cl_reg_read(chip, IO_CTRL_SDA_ADDR) & ~((u32)0x00001000)) | ((u32)gpioout << 12));
}

static inline u8 io_ctrl_sda_gpio_oe_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_SDA_ADDR);

	return (u8)((local_val & ((u32)0x00000800)) >> 11);
}

static inline void io_ctrl_sda_gpio_oe_setf(struct cl_chip *chip, u8 gpiooe)
{
	ASSERT_ERR_CHIP((((u32)gpiooe << 11) & ~((u32)0x00000800)) == 0);
	cl_reg_write(chip, IO_CTRL_SDA_ADDR, (cl_reg_read(chip, IO_CTRL_SDA_ADDR) & ~((u32)0x00000800)) | ((u32)gpiooe << 11));
}

static inline u8 io_ctrl_sda_gpio_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_SDA_ADDR);

	return (u8)((local_val & ((u32)0x00000400)) >> 10);
}

static inline void io_ctrl_sda_gpio_enable_setf(struct cl_chip *chip, u8 gpioenable)
{
	ASSERT_ERR_CHIP((((u32)gpioenable << 10) & ~((u32)0x00000400)) == 0);
	cl_reg_write(chip, IO_CTRL_SDA_ADDR, (cl_reg_read(chip, IO_CTRL_SDA_ADDR) & ~((u32)0x00000400)) | ((u32)gpioenable << 10));
}

static inline u8 io_ctrl_sda_input_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_SDA_ADDR);

	return (u8)((local_val & ((u32)0x00000200)) >> 9);
}

static inline void io_ctrl_sda_input_enable_setf(struct cl_chip *chip, u8 inputenable)
{
	ASSERT_ERR_CHIP((((u32)inputenable << 9) & ~((u32)0x00000200)) == 0);
	cl_reg_write(chip, IO_CTRL_SDA_ADDR, (cl_reg_read(chip, IO_CTRL_SDA_ADDR) & ~((u32)0x00000200)) | ((u32)inputenable << 9));
}

static inline u8 io_ctrl_sda_driver_pull_state_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_SDA_ADDR);

	return (u8)((local_val & ((u32)0x000000C0)) >> 6);
}

static inline void io_ctrl_sda_driver_pull_state_setf(struct cl_chip *chip, u8 driverpullstate)
{
	ASSERT_ERR_CHIP((((u32)driverpullstate << 6) & ~((u32)0x000000C0)) == 0);
	cl_reg_write(chip, IO_CTRL_SDA_ADDR, (cl_reg_read(chip, IO_CTRL_SDA_ADDR) & ~((u32)0x000000C0)) | ((u32)driverpullstate << 6));
}

static inline u8 io_ctrl_sda_output_pad_strength_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_SDA_ADDR);

	return (u8)((local_val & ((u32)0x00000038)) >> 3);
}

static inline void io_ctrl_sda_output_pad_strength_setf(struct cl_chip *chip, u8 outputpadstrength)
{
	ASSERT_ERR_CHIP((((u32)outputpadstrength << 3) & ~((u32)0x00000038)) == 0);
	cl_reg_write(chip, IO_CTRL_SDA_ADDR, (cl_reg_read(chip, IO_CTRL_SDA_ADDR) & ~((u32)0x00000038)) | ((u32)outputpadstrength << 3));
}

static inline u8 io_ctrl_sda_mux_select_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_SDA_ADDR);

	return (u8)((local_val & ((u32)0x00000007)) >> 0);
}

static inline void io_ctrl_sda_mux_select_setf(struct cl_chip *chip, u8 muxselect)
{
	ASSERT_ERR_CHIP((((u32)muxselect << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_SDA_ADDR, (cl_reg_read(chip, IO_CTRL_SDA_ADDR) & ~((u32)0x00000007)) | ((u32)muxselect << 0));
}

/**
 * @brief GPIO_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    13    GPIO_IN                   1
 *    12    GPIO_OUT                  0
 *    11    GPIO_OE                   0
 *    10    GPIO_ENABLE               1
 *    09    input_enable              1
 *    07:06 DRIVER_PULL_STATE         0x2
 *    05:03 OUTPUT_PAD_STRENGTH       0x2
 *    02:00 MUX_SELECT                0x0
 * </pre>
 */
#define IO_CTRL_GPIO_1_ADDR        (REG_IO_CTRL_BASE_ADDR + 0x0000000C)
#define IO_CTRL_GPIO_1_OFFSET      0x0000000C
#define IO_CTRL_GPIO_1_INDEX       0x00000003
#define IO_CTRL_GPIO_1_RESET       0x000009C8

static inline u32 io_ctrl_gpio_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, IO_CTRL_GPIO_1_ADDR);
}

static inline void io_ctrl_gpio_1_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, IO_CTRL_GPIO_1_ADDR, value);
}

/* Field definitions */
#define IO_CTRL_GPIO_1_GPIO_IN_BIT          ((u32)0x00002000)
#define IO_CTRL_GPIO_1_GPIO_IN_POS          13
#define IO_CTRL_GPIO_1_GPIO_OUT_BIT         ((u32)0x00001000)
#define IO_CTRL_GPIO_1_GPIO_OUT_POS         12
#define IO_CTRL_GPIO_1_GPIO_OE_BIT          ((u32)0x00000800)
#define IO_CTRL_GPIO_1_GPIO_OE_POS          11
#define IO_CTRL_GPIO_1_GPIO_ENABLE_BIT      ((u32)0x00000400)
#define IO_CTRL_GPIO_1_GPIO_ENABLE_POS      10
#define IO_CTRL_GPIO_1_INPUT_ENABLE_BIT     ((u32)0x00000200)
#define IO_CTRL_GPIO_1_INPUT_ENABLE_POS     9
#define IO_CTRL_GPIO_1_DRIVER_PULL_STATE_MASK    ((u32)0x000000C0)
#define IO_CTRL_GPIO_1_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_GPIO_1_DRIVER_PULL_STATE_WIDTH    ((u32)0x00000002)
#define IO_CTRL_GPIO_1_OUTPUT_PAD_STRENGTH_MASK    ((u32)0x00000038)
#define IO_CTRL_GPIO_1_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_GPIO_1_OUTPUT_PAD_STRENGTH_WIDTH    ((u32)0x00000003)
#define IO_CTRL_GPIO_1_MUX_SELECT_MASK      ((u32)0x00000007)
#define IO_CTRL_GPIO_1_MUX_SELECT_LSB       0
#define IO_CTRL_GPIO_1_MUX_SELECT_WIDTH     ((u32)0x00000003)

#define IO_CTRL_GPIO_1_GPIO_IN_RST          0x1
#define IO_CTRL_GPIO_1_GPIO_OUT_RST         0x0
#define IO_CTRL_GPIO_1_GPIO_OE_RST          0x0
#define IO_CTRL_GPIO_1_GPIO_ENABLE_RST      0x1
#define IO_CTRL_GPIO_1_INPUT_ENABLE_RST     0x1
#define IO_CTRL_GPIO_1_DRIVER_PULL_STATE_RST    0x2
#define IO_CTRL_GPIO_1_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_GPIO_1_MUX_SELECT_RST       0x0

static inline void io_ctrl_gpio_1_pack(struct cl_chip *chip, u8 gpio_in, u8 gpio_out, u8 gpio_oe, u8 gpio_enable, u8 input_enable, u8 driver_pull_state, u8 output_pad_strength, u8 mux_select)
{
	ASSERT_ERR_CHIP((((u32)gpio_in << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_out << 12) & ~((u32)0x00001000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_oe << 11) & ~((u32)0x00000800)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_enable << 10) & ~((u32)0x00000400)) == 0);
	ASSERT_ERR_CHIP((((u32)input_enable << 9) & ~((u32)0x00000200)) == 0);
	ASSERT_ERR_CHIP((((u32)driver_pull_state << 6) & ~((u32)0x000000C0)) == 0);
	ASSERT_ERR_CHIP((((u32)output_pad_strength << 3) & ~((u32)0x00000038)) == 0);
	ASSERT_ERR_CHIP((((u32)mux_select << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_GPIO_1_ADDR,  ((u32)gpio_in << 13) | ((u32)gpio_out << 12) | ((u32)gpio_oe << 11) | ((u32)gpio_enable << 10) | ((u32)input_enable << 9) | ((u32)driver_pull_state << 6) | ((u32)output_pad_strength << 3) | ((u32)mux_select << 0));
}

static inline void io_ctrl_gpio_1_unpack(struct cl_chip *chip, u8 *gpio_in, u8 *gpio_out, u8 *gpio_oe, u8 *gpio_enable, u8 *input_enable, u8 *driver_pull_state, u8 *output_pad_strength, u8 *mux_select)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_GPIO_1_ADDR);

	*gpio_in = (local_val & ((u32)0x00002000)) >> 13;
	*gpio_out = (local_val & ((u32)0x00001000)) >> 12;
	*gpio_oe = (local_val & ((u32)0x00000800)) >> 11;
	*gpio_enable = (local_val & ((u32)0x00000400)) >> 10;
	*input_enable = (local_val & ((u32)0x00000200)) >> 9;
	*driver_pull_state = (local_val & ((u32)0x000000C0)) >> 6;
	*output_pad_strength = (local_val & ((u32)0x00000038)) >> 3;
	*mux_select = (local_val & ((u32)0x00000007)) >> 0;
}

static inline u8 io_ctrl_gpio_1_gpio_in_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_GPIO_1_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline u8 io_ctrl_gpio_1_gpio_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_GPIO_1_ADDR);

	return (u8)((local_val & ((u32)0x00001000)) >> 12);
}

static inline void io_ctrl_gpio_1_gpio_out_setf(struct cl_chip *chip, u8 gpioout)
{
	ASSERT_ERR_CHIP((((u32)gpioout << 12) & ~((u32)0x00001000)) == 0);
	cl_reg_write(chip, IO_CTRL_GPIO_1_ADDR, (cl_reg_read(chip, IO_CTRL_GPIO_1_ADDR) & ~((u32)0x00001000)) | ((u32)gpioout << 12));
}

static inline u8 io_ctrl_gpio_1_gpio_oe_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_GPIO_1_ADDR);

	return (u8)((local_val & ((u32)0x00000800)) >> 11);
}

static inline void io_ctrl_gpio_1_gpio_oe_setf(struct cl_chip *chip, u8 gpiooe)
{
	ASSERT_ERR_CHIP((((u32)gpiooe << 11) & ~((u32)0x00000800)) == 0);
	cl_reg_write(chip, IO_CTRL_GPIO_1_ADDR, (cl_reg_read(chip, IO_CTRL_GPIO_1_ADDR) & ~((u32)0x00000800)) | ((u32)gpiooe << 11));
}

static inline u8 io_ctrl_gpio_1_gpio_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_GPIO_1_ADDR);

	return (u8)((local_val & ((u32)0x00000400)) >> 10);
}

static inline void io_ctrl_gpio_1_gpio_enable_setf(struct cl_chip *chip, u8 gpioenable)
{
	ASSERT_ERR_CHIP((((u32)gpioenable << 10) & ~((u32)0x00000400)) == 0);
	cl_reg_write(chip, IO_CTRL_GPIO_1_ADDR, (cl_reg_read(chip, IO_CTRL_GPIO_1_ADDR) & ~((u32)0x00000400)) | ((u32)gpioenable << 10));
}

static inline u8 io_ctrl_gpio_1_input_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_GPIO_1_ADDR);

	return (u8)((local_val & ((u32)0x00000200)) >> 9);
}

static inline void io_ctrl_gpio_1_input_enable_setf(struct cl_chip *chip, u8 inputenable)
{
	ASSERT_ERR_CHIP((((u32)inputenable << 9) & ~((u32)0x00000200)) == 0);
	cl_reg_write(chip, IO_CTRL_GPIO_1_ADDR, (cl_reg_read(chip, IO_CTRL_GPIO_1_ADDR) & ~((u32)0x00000200)) | ((u32)inputenable << 9));
}

static inline u8 io_ctrl_gpio_1_driver_pull_state_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_GPIO_1_ADDR);

	return (u8)((local_val & ((u32)0x000000C0)) >> 6);
}

static inline void io_ctrl_gpio_1_driver_pull_state_setf(struct cl_chip *chip, u8 driverpullstate)
{
	ASSERT_ERR_CHIP((((u32)driverpullstate << 6) & ~((u32)0x000000C0)) == 0);
	cl_reg_write(chip, IO_CTRL_GPIO_1_ADDR, (cl_reg_read(chip, IO_CTRL_GPIO_1_ADDR) & ~((u32)0x000000C0)) | ((u32)driverpullstate << 6));
}

static inline u8 io_ctrl_gpio_1_output_pad_strength_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_GPIO_1_ADDR);

	return (u8)((local_val & ((u32)0x00000038)) >> 3);
}

static inline void io_ctrl_gpio_1_output_pad_strength_setf(struct cl_chip *chip, u8 outputpadstrength)
{
	ASSERT_ERR_CHIP((((u32)outputpadstrength << 3) & ~((u32)0x00000038)) == 0);
	cl_reg_write(chip, IO_CTRL_GPIO_1_ADDR, (cl_reg_read(chip, IO_CTRL_GPIO_1_ADDR) & ~((u32)0x00000038)) | ((u32)outputpadstrength << 3));
}

static inline u8 io_ctrl_gpio_1_mux_select_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_GPIO_1_ADDR);

	return (u8)((local_val & ((u32)0x00000007)) >> 0);
}

static inline void io_ctrl_gpio_1_mux_select_setf(struct cl_chip *chip, u8 muxselect)
{
	ASSERT_ERR_CHIP((((u32)muxselect << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_GPIO_1_ADDR, (cl_reg_read(chip, IO_CTRL_GPIO_1_ADDR) & ~((u32)0x00000007)) | ((u32)muxselect << 0));
}

/**
 * @brief TRST_N register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    13    GPIO_IN                   1
 *    12    GPIO_OUT                  0
 *    11    GPIO_OE                   0
 *    10    GPIO_ENABLE               0
 *    09    input_enable              1
 *    07:06 DRIVER_PULL_STATE         0x2
 *    05:03 OUTPUT_PAD_STRENGTH       0x2
 *    02:00 MUX_SELECT                0x0
 * </pre>
 */
#define IO_CTRL_TRST_N_ADDR        (REG_IO_CTRL_BASE_ADDR + 0x00000010)
#define IO_CTRL_TRST_N_OFFSET      0x00000010
#define IO_CTRL_TRST_N_INDEX       0x00000004
#define IO_CTRL_TRST_N_RESET       0x000008C8

static inline u32 io_ctrl_trst_n_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, IO_CTRL_TRST_N_ADDR);
}

static inline void io_ctrl_trst_n_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, IO_CTRL_TRST_N_ADDR, value);
}

/* Field definitions */
#define IO_CTRL_TRST_N_GPIO_IN_BIT          ((u32)0x00002000)
#define IO_CTRL_TRST_N_GPIO_IN_POS          13
#define IO_CTRL_TRST_N_GPIO_OUT_BIT         ((u32)0x00001000)
#define IO_CTRL_TRST_N_GPIO_OUT_POS         12
#define IO_CTRL_TRST_N_GPIO_OE_BIT          ((u32)0x00000800)
#define IO_CTRL_TRST_N_GPIO_OE_POS          11
#define IO_CTRL_TRST_N_GPIO_ENABLE_BIT      ((u32)0x00000400)
#define IO_CTRL_TRST_N_GPIO_ENABLE_POS      10
#define IO_CTRL_TRST_N_INPUT_ENABLE_BIT     ((u32)0x00000200)
#define IO_CTRL_TRST_N_INPUT_ENABLE_POS     9
#define IO_CTRL_TRST_N_DRIVER_PULL_STATE_MASK    ((u32)0x000000C0)
#define IO_CTRL_TRST_N_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_TRST_N_DRIVER_PULL_STATE_WIDTH    ((u32)0x00000002)
#define IO_CTRL_TRST_N_OUTPUT_PAD_STRENGTH_MASK    ((u32)0x00000038)
#define IO_CTRL_TRST_N_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_TRST_N_OUTPUT_PAD_STRENGTH_WIDTH    ((u32)0x00000003)
#define IO_CTRL_TRST_N_MUX_SELECT_MASK      ((u32)0x00000007)
#define IO_CTRL_TRST_N_MUX_SELECT_LSB       0
#define IO_CTRL_TRST_N_MUX_SELECT_WIDTH     ((u32)0x00000003)

#define IO_CTRL_TRST_N_GPIO_IN_RST          0x1
#define IO_CTRL_TRST_N_GPIO_OUT_RST         0x0
#define IO_CTRL_TRST_N_GPIO_OE_RST          0x0
#define IO_CTRL_TRST_N_GPIO_ENABLE_RST      0x0
#define IO_CTRL_TRST_N_INPUT_ENABLE_RST     0x1
#define IO_CTRL_TRST_N_DRIVER_PULL_STATE_RST    0x2
#define IO_CTRL_TRST_N_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_TRST_N_MUX_SELECT_RST       0x0

static inline void io_ctrl_trst_n_pack(struct cl_chip *chip, u8 gpio_in, u8 gpio_out, u8 gpio_oe, u8 gpio_enable, u8 input_enable, u8 driver_pull_state, u8 output_pad_strength, u8 mux_select)
{
	ASSERT_ERR_CHIP((((u32)gpio_in << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_out << 12) & ~((u32)0x00001000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_oe << 11) & ~((u32)0x00000800)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_enable << 10) & ~((u32)0x00000400)) == 0);
	ASSERT_ERR_CHIP((((u32)input_enable << 9) & ~((u32)0x00000200)) == 0);
	ASSERT_ERR_CHIP((((u32)driver_pull_state << 6) & ~((u32)0x000000C0)) == 0);
	ASSERT_ERR_CHIP((((u32)output_pad_strength << 3) & ~((u32)0x00000038)) == 0);
	ASSERT_ERR_CHIP((((u32)mux_select << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_TRST_N_ADDR,  ((u32)gpio_in << 13) | ((u32)gpio_out << 12) | ((u32)gpio_oe << 11) | ((u32)gpio_enable << 10) | ((u32)input_enable << 9) | ((u32)driver_pull_state << 6) | ((u32)output_pad_strength << 3) | ((u32)mux_select << 0));
}

static inline void io_ctrl_trst_n_unpack(struct cl_chip *chip, u8 *gpio_in, u8 *gpio_out, u8 *gpio_oe, u8 *gpio_enable, u8 *input_enable, u8 *driver_pull_state, u8 *output_pad_strength, u8 *mux_select)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TRST_N_ADDR);

	*gpio_in = (local_val & ((u32)0x00002000)) >> 13;
	*gpio_out = (local_val & ((u32)0x00001000)) >> 12;
	*gpio_oe = (local_val & ((u32)0x00000800)) >> 11;
	*gpio_enable = (local_val & ((u32)0x00000400)) >> 10;
	*input_enable = (local_val & ((u32)0x00000200)) >> 9;
	*driver_pull_state = (local_val & ((u32)0x000000C0)) >> 6;
	*output_pad_strength = (local_val & ((u32)0x00000038)) >> 3;
	*mux_select = (local_val & ((u32)0x00000007)) >> 0;
}

static inline u8 io_ctrl_trst_n_gpio_in_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TRST_N_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline u8 io_ctrl_trst_n_gpio_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TRST_N_ADDR);

	return (u8)((local_val & ((u32)0x00001000)) >> 12);
}

static inline void io_ctrl_trst_n_gpio_out_setf(struct cl_chip *chip, u8 gpioout)
{
	ASSERT_ERR_CHIP((((u32)gpioout << 12) & ~((u32)0x00001000)) == 0);
	cl_reg_write(chip, IO_CTRL_TRST_N_ADDR, (cl_reg_read(chip, IO_CTRL_TRST_N_ADDR) & ~((u32)0x00001000)) | ((u32)gpioout << 12));
}

static inline u8 io_ctrl_trst_n_gpio_oe_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TRST_N_ADDR);

	return (u8)((local_val & ((u32)0x00000800)) >> 11);
}

static inline void io_ctrl_trst_n_gpio_oe_setf(struct cl_chip *chip, u8 gpiooe)
{
	ASSERT_ERR_CHIP((((u32)gpiooe << 11) & ~((u32)0x00000800)) == 0);
	cl_reg_write(chip, IO_CTRL_TRST_N_ADDR, (cl_reg_read(chip, IO_CTRL_TRST_N_ADDR) & ~((u32)0x00000800)) | ((u32)gpiooe << 11));
}

static inline u8 io_ctrl_trst_n_gpio_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TRST_N_ADDR);

	return (u8)((local_val & ((u32)0x00000400)) >> 10);
}

static inline void io_ctrl_trst_n_gpio_enable_setf(struct cl_chip *chip, u8 gpioenable)
{
	ASSERT_ERR_CHIP((((u32)gpioenable << 10) & ~((u32)0x00000400)) == 0);
	cl_reg_write(chip, IO_CTRL_TRST_N_ADDR, (cl_reg_read(chip, IO_CTRL_TRST_N_ADDR) & ~((u32)0x00000400)) | ((u32)gpioenable << 10));
}

static inline u8 io_ctrl_trst_n_input_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TRST_N_ADDR);

	return (u8)((local_val & ((u32)0x00000200)) >> 9);
}

static inline void io_ctrl_trst_n_input_enable_setf(struct cl_chip *chip, u8 inputenable)
{
	ASSERT_ERR_CHIP((((u32)inputenable << 9) & ~((u32)0x00000200)) == 0);
	cl_reg_write(chip, IO_CTRL_TRST_N_ADDR, (cl_reg_read(chip, IO_CTRL_TRST_N_ADDR) & ~((u32)0x00000200)) | ((u32)inputenable << 9));
}

static inline u8 io_ctrl_trst_n_driver_pull_state_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TRST_N_ADDR);

	return (u8)((local_val & ((u32)0x000000C0)) >> 6);
}

static inline void io_ctrl_trst_n_driver_pull_state_setf(struct cl_chip *chip, u8 driverpullstate)
{
	ASSERT_ERR_CHIP((((u32)driverpullstate << 6) & ~((u32)0x000000C0)) == 0);
	cl_reg_write(chip, IO_CTRL_TRST_N_ADDR, (cl_reg_read(chip, IO_CTRL_TRST_N_ADDR) & ~((u32)0x000000C0)) | ((u32)driverpullstate << 6));
}

static inline u8 io_ctrl_trst_n_output_pad_strength_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TRST_N_ADDR);

	return (u8)((local_val & ((u32)0x00000038)) >> 3);
}

static inline void io_ctrl_trst_n_output_pad_strength_setf(struct cl_chip *chip, u8 outputpadstrength)
{
	ASSERT_ERR_CHIP((((u32)outputpadstrength << 3) & ~((u32)0x00000038)) == 0);
	cl_reg_write(chip, IO_CTRL_TRST_N_ADDR, (cl_reg_read(chip, IO_CTRL_TRST_N_ADDR) & ~((u32)0x00000038)) | ((u32)outputpadstrength << 3));
}

static inline u8 io_ctrl_trst_n_mux_select_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TRST_N_ADDR);

	return (u8)((local_val & ((u32)0x00000007)) >> 0);
}

static inline void io_ctrl_trst_n_mux_select_setf(struct cl_chip *chip, u8 muxselect)
{
	ASSERT_ERR_CHIP((((u32)muxselect << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_TRST_N_ADDR, (cl_reg_read(chip, IO_CTRL_TRST_N_ADDR) & ~((u32)0x00000007)) | ((u32)muxselect << 0));
}

/**
 * @brief TDI register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    13    GPIO_IN                   1
 *    12    GPIO_OUT                  0
 *    11    GPIO_OE                   0
 *    10    GPIO_ENABLE               0
 *    09    input_enable              1
 *    07:06 DRIVER_PULL_STATE         0x2
 *    05:03 OUTPUT_PAD_STRENGTH       0x2
 *    02:00 MUX_SELECT                0x0
 * </pre>
 */
#define IO_CTRL_TDI_ADDR        (REG_IO_CTRL_BASE_ADDR + 0x00000014)
#define IO_CTRL_TDI_OFFSET      0x00000014
#define IO_CTRL_TDI_INDEX       0x00000005
#define IO_CTRL_TDI_RESET       0x000008C8

static inline u32 io_ctrl_tdi_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, IO_CTRL_TDI_ADDR);
}

static inline void io_ctrl_tdi_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, IO_CTRL_TDI_ADDR, value);
}

/* Field definitions */
#define IO_CTRL_TDI_GPIO_IN_BIT             ((u32)0x00002000)
#define IO_CTRL_TDI_GPIO_IN_POS             13
#define IO_CTRL_TDI_GPIO_OUT_BIT            ((u32)0x00001000)
#define IO_CTRL_TDI_GPIO_OUT_POS            12
#define IO_CTRL_TDI_GPIO_OE_BIT             ((u32)0x00000800)
#define IO_CTRL_TDI_GPIO_OE_POS             11
#define IO_CTRL_TDI_GPIO_ENABLE_BIT         ((u32)0x00000400)
#define IO_CTRL_TDI_GPIO_ENABLE_POS         10
#define IO_CTRL_TDI_INPUT_ENABLE_BIT        ((u32)0x00000200)
#define IO_CTRL_TDI_INPUT_ENABLE_POS        9
#define IO_CTRL_TDI_DRIVER_PULL_STATE_MASK    ((u32)0x000000C0)
#define IO_CTRL_TDI_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_TDI_DRIVER_PULL_STATE_WIDTH    ((u32)0x00000002)
#define IO_CTRL_TDI_OUTPUT_PAD_STRENGTH_MASK    ((u32)0x00000038)
#define IO_CTRL_TDI_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_TDI_OUTPUT_PAD_STRENGTH_WIDTH    ((u32)0x00000003)
#define IO_CTRL_TDI_MUX_SELECT_MASK         ((u32)0x00000007)
#define IO_CTRL_TDI_MUX_SELECT_LSB          0
#define IO_CTRL_TDI_MUX_SELECT_WIDTH        ((u32)0x00000003)

#define IO_CTRL_TDI_GPIO_IN_RST             0x1
#define IO_CTRL_TDI_GPIO_OUT_RST            0x0
#define IO_CTRL_TDI_GPIO_OE_RST             0x0
#define IO_CTRL_TDI_GPIO_ENABLE_RST         0x0
#define IO_CTRL_TDI_INPUT_ENABLE_RST        0x1
#define IO_CTRL_TDI_DRIVER_PULL_STATE_RST    0x2
#define IO_CTRL_TDI_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_TDI_MUX_SELECT_RST          0x0

static inline void io_ctrl_tdi_pack(struct cl_chip *chip, u8 gpio_in, u8 gpio_out, u8 gpio_oe, u8 gpio_enable, u8 input_enable, u8 driver_pull_state, u8 output_pad_strength, u8 mux_select)
{
	ASSERT_ERR_CHIP((((u32)gpio_in << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_out << 12) & ~((u32)0x00001000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_oe << 11) & ~((u32)0x00000800)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_enable << 10) & ~((u32)0x00000400)) == 0);
	ASSERT_ERR_CHIP((((u32)input_enable << 9) & ~((u32)0x00000200)) == 0);
	ASSERT_ERR_CHIP((((u32)driver_pull_state << 6) & ~((u32)0x000000C0)) == 0);
	ASSERT_ERR_CHIP((((u32)output_pad_strength << 3) & ~((u32)0x00000038)) == 0);
	ASSERT_ERR_CHIP((((u32)mux_select << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_TDI_ADDR,  ((u32)gpio_in << 13) | ((u32)gpio_out << 12) | ((u32)gpio_oe << 11) | ((u32)gpio_enable << 10) | ((u32)input_enable << 9) | ((u32)driver_pull_state << 6) | ((u32)output_pad_strength << 3) | ((u32)mux_select << 0));
}

static inline void io_ctrl_tdi_unpack(struct cl_chip *chip, u8 *gpio_in, u8 *gpio_out, u8 *gpio_oe, u8 *gpio_enable, u8 *input_enable, u8 *driver_pull_state, u8 *output_pad_strength, u8 *mux_select)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TDI_ADDR);

	*gpio_in = (local_val & ((u32)0x00002000)) >> 13;
	*gpio_out = (local_val & ((u32)0x00001000)) >> 12;
	*gpio_oe = (local_val & ((u32)0x00000800)) >> 11;
	*gpio_enable = (local_val & ((u32)0x00000400)) >> 10;
	*input_enable = (local_val & ((u32)0x00000200)) >> 9;
	*driver_pull_state = (local_val & ((u32)0x000000C0)) >> 6;
	*output_pad_strength = (local_val & ((u32)0x00000038)) >> 3;
	*mux_select = (local_val & ((u32)0x00000007)) >> 0;
}

static inline u8 io_ctrl_tdi_gpio_in_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TDI_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline u8 io_ctrl_tdi_gpio_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TDI_ADDR);

	return (u8)((local_val & ((u32)0x00001000)) >> 12);
}

static inline void io_ctrl_tdi_gpio_out_setf(struct cl_chip *chip, u8 gpioout)
{
	ASSERT_ERR_CHIP((((u32)gpioout << 12) & ~((u32)0x00001000)) == 0);
	cl_reg_write(chip, IO_CTRL_TDI_ADDR, (cl_reg_read(chip, IO_CTRL_TDI_ADDR) & ~((u32)0x00001000)) | ((u32)gpioout << 12));
}

static inline u8 io_ctrl_tdi_gpio_oe_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TDI_ADDR);

	return (u8)((local_val & ((u32)0x00000800)) >> 11);
}

static inline void io_ctrl_tdi_gpio_oe_setf(struct cl_chip *chip, u8 gpiooe)
{
	ASSERT_ERR_CHIP((((u32)gpiooe << 11) & ~((u32)0x00000800)) == 0);
	cl_reg_write(chip, IO_CTRL_TDI_ADDR, (cl_reg_read(chip, IO_CTRL_TDI_ADDR) & ~((u32)0x00000800)) | ((u32)gpiooe << 11));
}

static inline u8 io_ctrl_tdi_gpio_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TDI_ADDR);

	return (u8)((local_val & ((u32)0x00000400)) >> 10);
}

static inline void io_ctrl_tdi_gpio_enable_setf(struct cl_chip *chip, u8 gpioenable)
{
	ASSERT_ERR_CHIP((((u32)gpioenable << 10) & ~((u32)0x00000400)) == 0);
	cl_reg_write(chip, IO_CTRL_TDI_ADDR, (cl_reg_read(chip, IO_CTRL_TDI_ADDR) & ~((u32)0x00000400)) | ((u32)gpioenable << 10));
}

static inline u8 io_ctrl_tdi_input_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TDI_ADDR);

	return (u8)((local_val & ((u32)0x00000200)) >> 9);
}

static inline void io_ctrl_tdi_input_enable_setf(struct cl_chip *chip, u8 inputenable)
{
	ASSERT_ERR_CHIP((((u32)inputenable << 9) & ~((u32)0x00000200)) == 0);
	cl_reg_write(chip, IO_CTRL_TDI_ADDR, (cl_reg_read(chip, IO_CTRL_TDI_ADDR) & ~((u32)0x00000200)) | ((u32)inputenable << 9));
}

static inline u8 io_ctrl_tdi_driver_pull_state_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TDI_ADDR);

	return (u8)((local_val & ((u32)0x000000C0)) >> 6);
}

static inline void io_ctrl_tdi_driver_pull_state_setf(struct cl_chip *chip, u8 driverpullstate)
{
	ASSERT_ERR_CHIP((((u32)driverpullstate << 6) & ~((u32)0x000000C0)) == 0);
	cl_reg_write(chip, IO_CTRL_TDI_ADDR, (cl_reg_read(chip, IO_CTRL_TDI_ADDR) & ~((u32)0x000000C0)) | ((u32)driverpullstate << 6));
}

static inline u8 io_ctrl_tdi_output_pad_strength_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TDI_ADDR);

	return (u8)((local_val & ((u32)0x00000038)) >> 3);
}

static inline void io_ctrl_tdi_output_pad_strength_setf(struct cl_chip *chip, u8 outputpadstrength)
{
	ASSERT_ERR_CHIP((((u32)outputpadstrength << 3) & ~((u32)0x00000038)) == 0);
	cl_reg_write(chip, IO_CTRL_TDI_ADDR, (cl_reg_read(chip, IO_CTRL_TDI_ADDR) & ~((u32)0x00000038)) | ((u32)outputpadstrength << 3));
}

static inline u8 io_ctrl_tdi_mux_select_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TDI_ADDR);

	return (u8)((local_val & ((u32)0x00000007)) >> 0);
}

static inline void io_ctrl_tdi_mux_select_setf(struct cl_chip *chip, u8 muxselect)
{
	ASSERT_ERR_CHIP((((u32)muxselect << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_TDI_ADDR, (cl_reg_read(chip, IO_CTRL_TDI_ADDR) & ~((u32)0x00000007)) | ((u32)muxselect << 0));
}

/**
 * @brief TDO register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    13    GPIO_IN                   1
 *    12    GPIO_OUT                  0
 *    11    GPIO_OE                   0
 *    10    GPIO_ENABLE               0
 *    09    input_enable              1
 *    07:06 DRIVER_PULL_STATE         0x2
 *    05:03 OUTPUT_PAD_STRENGTH       0x2
 *    02:00 MUX_SELECT                0x0
 * </pre>
 */
#define IO_CTRL_TDO_ADDR        (REG_IO_CTRL_BASE_ADDR + 0x00000018)
#define IO_CTRL_TDO_OFFSET      0x00000018
#define IO_CTRL_TDO_INDEX       0x00000006
#define IO_CTRL_TDO_RESET       0x000008C8

static inline u32 io_ctrl_tdo_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, IO_CTRL_TDO_ADDR);
}

static inline void io_ctrl_tdo_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, IO_CTRL_TDO_ADDR, value);
}

/* Field definitions */
#define IO_CTRL_TDO_GPIO_IN_BIT             ((u32)0x00002000)
#define IO_CTRL_TDO_GPIO_IN_POS             13
#define IO_CTRL_TDO_GPIO_OUT_BIT            ((u32)0x00001000)
#define IO_CTRL_TDO_GPIO_OUT_POS            12
#define IO_CTRL_TDO_GPIO_OE_BIT             ((u32)0x00000800)
#define IO_CTRL_TDO_GPIO_OE_POS             11
#define IO_CTRL_TDO_GPIO_ENABLE_BIT         ((u32)0x00000400)
#define IO_CTRL_TDO_GPIO_ENABLE_POS         10
#define IO_CTRL_TDO_INPUT_ENABLE_BIT        ((u32)0x00000200)
#define IO_CTRL_TDO_INPUT_ENABLE_POS        9
#define IO_CTRL_TDO_DRIVER_PULL_STATE_MASK    ((u32)0x000000C0)
#define IO_CTRL_TDO_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_TDO_DRIVER_PULL_STATE_WIDTH    ((u32)0x00000002)
#define IO_CTRL_TDO_OUTPUT_PAD_STRENGTH_MASK    ((u32)0x00000038)
#define IO_CTRL_TDO_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_TDO_OUTPUT_PAD_STRENGTH_WIDTH    ((u32)0x00000003)
#define IO_CTRL_TDO_MUX_SELECT_MASK         ((u32)0x00000007)
#define IO_CTRL_TDO_MUX_SELECT_LSB          0
#define IO_CTRL_TDO_MUX_SELECT_WIDTH        ((u32)0x00000003)

#define IO_CTRL_TDO_GPIO_IN_RST             0x1
#define IO_CTRL_TDO_GPIO_OUT_RST            0x0
#define IO_CTRL_TDO_GPIO_OE_RST             0x0
#define IO_CTRL_TDO_GPIO_ENABLE_RST         0x0
#define IO_CTRL_TDO_INPUT_ENABLE_RST        0x1
#define IO_CTRL_TDO_DRIVER_PULL_STATE_RST    0x2
#define IO_CTRL_TDO_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_TDO_MUX_SELECT_RST          0x0

static inline void io_ctrl_tdo_pack(struct cl_chip *chip, u8 gpio_in, u8 gpio_out, u8 gpio_oe, u8 gpio_enable, u8 input_enable, u8 driver_pull_state, u8 output_pad_strength, u8 mux_select)
{
	ASSERT_ERR_CHIP((((u32)gpio_in << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_out << 12) & ~((u32)0x00001000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_oe << 11) & ~((u32)0x00000800)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_enable << 10) & ~((u32)0x00000400)) == 0);
	ASSERT_ERR_CHIP((((u32)input_enable << 9) & ~((u32)0x00000200)) == 0);
	ASSERT_ERR_CHIP((((u32)driver_pull_state << 6) & ~((u32)0x000000C0)) == 0);
	ASSERT_ERR_CHIP((((u32)output_pad_strength << 3) & ~((u32)0x00000038)) == 0);
	ASSERT_ERR_CHIP((((u32)mux_select << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_TDO_ADDR,  ((u32)gpio_in << 13) | ((u32)gpio_out << 12) | ((u32)gpio_oe << 11) | ((u32)gpio_enable << 10) | ((u32)input_enable << 9) | ((u32)driver_pull_state << 6) | ((u32)output_pad_strength << 3) | ((u32)mux_select << 0));
}

static inline void io_ctrl_tdo_unpack(struct cl_chip *chip, u8 *gpio_in, u8 *gpio_out, u8 *gpio_oe, u8 *gpio_enable, u8 *input_enable, u8 *driver_pull_state, u8 *output_pad_strength, u8 *mux_select)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TDO_ADDR);

	*gpio_in = (local_val & ((u32)0x00002000)) >> 13;
	*gpio_out = (local_val & ((u32)0x00001000)) >> 12;
	*gpio_oe = (local_val & ((u32)0x00000800)) >> 11;
	*gpio_enable = (local_val & ((u32)0x00000400)) >> 10;
	*input_enable = (local_val & ((u32)0x00000200)) >> 9;
	*driver_pull_state = (local_val & ((u32)0x000000C0)) >> 6;
	*output_pad_strength = (local_val & ((u32)0x00000038)) >> 3;
	*mux_select = (local_val & ((u32)0x00000007)) >> 0;
}

static inline u8 io_ctrl_tdo_gpio_in_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TDO_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline u8 io_ctrl_tdo_gpio_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TDO_ADDR);

	return (u8)((local_val & ((u32)0x00001000)) >> 12);
}

static inline void io_ctrl_tdo_gpio_out_setf(struct cl_chip *chip, u8 gpioout)
{
	ASSERT_ERR_CHIP((((u32)gpioout << 12) & ~((u32)0x00001000)) == 0);
	cl_reg_write(chip, IO_CTRL_TDO_ADDR, (cl_reg_read(chip, IO_CTRL_TDO_ADDR) & ~((u32)0x00001000)) | ((u32)gpioout << 12));
}

static inline u8 io_ctrl_tdo_gpio_oe_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TDO_ADDR);

	return (u8)((local_val & ((u32)0x00000800)) >> 11);
}

static inline void io_ctrl_tdo_gpio_oe_setf(struct cl_chip *chip, u8 gpiooe)
{
	ASSERT_ERR_CHIP((((u32)gpiooe << 11) & ~((u32)0x00000800)) == 0);
	cl_reg_write(chip, IO_CTRL_TDO_ADDR, (cl_reg_read(chip, IO_CTRL_TDO_ADDR) & ~((u32)0x00000800)) | ((u32)gpiooe << 11));
}

static inline u8 io_ctrl_tdo_gpio_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TDO_ADDR);

	return (u8)((local_val & ((u32)0x00000400)) >> 10);
}

static inline void io_ctrl_tdo_gpio_enable_setf(struct cl_chip *chip, u8 gpioenable)
{
	ASSERT_ERR_CHIP((((u32)gpioenable << 10) & ~((u32)0x00000400)) == 0);
	cl_reg_write(chip, IO_CTRL_TDO_ADDR, (cl_reg_read(chip, IO_CTRL_TDO_ADDR) & ~((u32)0x00000400)) | ((u32)gpioenable << 10));
}

static inline u8 io_ctrl_tdo_input_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TDO_ADDR);

	return (u8)((local_val & ((u32)0x00000200)) >> 9);
}

static inline void io_ctrl_tdo_input_enable_setf(struct cl_chip *chip, u8 inputenable)
{
	ASSERT_ERR_CHIP((((u32)inputenable << 9) & ~((u32)0x00000200)) == 0);
	cl_reg_write(chip, IO_CTRL_TDO_ADDR, (cl_reg_read(chip, IO_CTRL_TDO_ADDR) & ~((u32)0x00000200)) | ((u32)inputenable << 9));
}

static inline u8 io_ctrl_tdo_driver_pull_state_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TDO_ADDR);

	return (u8)((local_val & ((u32)0x000000C0)) >> 6);
}

static inline void io_ctrl_tdo_driver_pull_state_setf(struct cl_chip *chip, u8 driverpullstate)
{
	ASSERT_ERR_CHIP((((u32)driverpullstate << 6) & ~((u32)0x000000C0)) == 0);
	cl_reg_write(chip, IO_CTRL_TDO_ADDR, (cl_reg_read(chip, IO_CTRL_TDO_ADDR) & ~((u32)0x000000C0)) | ((u32)driverpullstate << 6));
}

static inline u8 io_ctrl_tdo_output_pad_strength_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TDO_ADDR);

	return (u8)((local_val & ((u32)0x00000038)) >> 3);
}

static inline void io_ctrl_tdo_output_pad_strength_setf(struct cl_chip *chip, u8 outputpadstrength)
{
	ASSERT_ERR_CHIP((((u32)outputpadstrength << 3) & ~((u32)0x00000038)) == 0);
	cl_reg_write(chip, IO_CTRL_TDO_ADDR, (cl_reg_read(chip, IO_CTRL_TDO_ADDR) & ~((u32)0x00000038)) | ((u32)outputpadstrength << 3));
}

static inline u8 io_ctrl_tdo_mux_select_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TDO_ADDR);

	return (u8)((local_val & ((u32)0x00000007)) >> 0);
}

static inline void io_ctrl_tdo_mux_select_setf(struct cl_chip *chip, u8 muxselect)
{
	ASSERT_ERR_CHIP((((u32)muxselect << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_TDO_ADDR, (cl_reg_read(chip, IO_CTRL_TDO_ADDR) & ~((u32)0x00000007)) | ((u32)muxselect << 0));
}

/**
 * @brief TCK register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    13    GPIO_IN                   1
 *    12    GPIO_OUT                  0
 *    11    GPIO_OE                   0
 *    10    GPIO_ENABLE               0
 *    09    input_enable              1
 *    07:06 DRIVER_PULL_STATE         0x2
 *    05:03 OUTPUT_PAD_STRENGTH       0x2
 *    02:00 MUX_SELECT                0x0
 * </pre>
 */
#define IO_CTRL_TCK_ADDR        (REG_IO_CTRL_BASE_ADDR + 0x0000001C)
#define IO_CTRL_TCK_OFFSET      0x0000001C
#define IO_CTRL_TCK_INDEX       0x00000007
#define IO_CTRL_TCK_RESET       0x000008C8

static inline u32 io_ctrl_tck_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, IO_CTRL_TCK_ADDR);
}

static inline void io_ctrl_tck_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, IO_CTRL_TCK_ADDR, value);
}

/* Field definitions */
#define IO_CTRL_TCK_GPIO_IN_BIT             ((u32)0x00002000)
#define IO_CTRL_TCK_GPIO_IN_POS             13
#define IO_CTRL_TCK_GPIO_OUT_BIT            ((u32)0x00001000)
#define IO_CTRL_TCK_GPIO_OUT_POS            12
#define IO_CTRL_TCK_GPIO_OE_BIT             ((u32)0x00000800)
#define IO_CTRL_TCK_GPIO_OE_POS             11
#define IO_CTRL_TCK_GPIO_ENABLE_BIT         ((u32)0x00000400)
#define IO_CTRL_TCK_GPIO_ENABLE_POS         10
#define IO_CTRL_TCK_INPUT_ENABLE_BIT        ((u32)0x00000200)
#define IO_CTRL_TCK_INPUT_ENABLE_POS        9
#define IO_CTRL_TCK_DRIVER_PULL_STATE_MASK    ((u32)0x000000C0)
#define IO_CTRL_TCK_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_TCK_DRIVER_PULL_STATE_WIDTH    ((u32)0x00000002)
#define IO_CTRL_TCK_OUTPUT_PAD_STRENGTH_MASK    ((u32)0x00000038)
#define IO_CTRL_TCK_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_TCK_OUTPUT_PAD_STRENGTH_WIDTH    ((u32)0x00000003)
#define IO_CTRL_TCK_MUX_SELECT_MASK         ((u32)0x00000007)
#define IO_CTRL_TCK_MUX_SELECT_LSB          0
#define IO_CTRL_TCK_MUX_SELECT_WIDTH        ((u32)0x00000003)

#define IO_CTRL_TCK_GPIO_IN_RST             0x1
#define IO_CTRL_TCK_GPIO_OUT_RST            0x0
#define IO_CTRL_TCK_GPIO_OE_RST             0x0
#define IO_CTRL_TCK_GPIO_ENABLE_RST         0x0
#define IO_CTRL_TCK_INPUT_ENABLE_RST        0x1
#define IO_CTRL_TCK_DRIVER_PULL_STATE_RST    0x2
#define IO_CTRL_TCK_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_TCK_MUX_SELECT_RST          0x0

static inline void io_ctrl_tck_pack(struct cl_chip *chip, u8 gpio_in, u8 gpio_out, u8 gpio_oe, u8 gpio_enable, u8 input_enable, u8 driver_pull_state, u8 output_pad_strength, u8 mux_select)
{
	ASSERT_ERR_CHIP((((u32)gpio_in << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_out << 12) & ~((u32)0x00001000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_oe << 11) & ~((u32)0x00000800)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_enable << 10) & ~((u32)0x00000400)) == 0);
	ASSERT_ERR_CHIP((((u32)input_enable << 9) & ~((u32)0x00000200)) == 0);
	ASSERT_ERR_CHIP((((u32)driver_pull_state << 6) & ~((u32)0x000000C0)) == 0);
	ASSERT_ERR_CHIP((((u32)output_pad_strength << 3) & ~((u32)0x00000038)) == 0);
	ASSERT_ERR_CHIP((((u32)mux_select << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_TCK_ADDR,  ((u32)gpio_in << 13) | ((u32)gpio_out << 12) | ((u32)gpio_oe << 11) | ((u32)gpio_enable << 10) | ((u32)input_enable << 9) | ((u32)driver_pull_state << 6) | ((u32)output_pad_strength << 3) | ((u32)mux_select << 0));
}

static inline void io_ctrl_tck_unpack(struct cl_chip *chip, u8 *gpio_in, u8 *gpio_out, u8 *gpio_oe, u8 *gpio_enable, u8 *input_enable, u8 *driver_pull_state, u8 *output_pad_strength, u8 *mux_select)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TCK_ADDR);

	*gpio_in = (local_val & ((u32)0x00002000)) >> 13;
	*gpio_out = (local_val & ((u32)0x00001000)) >> 12;
	*gpio_oe = (local_val & ((u32)0x00000800)) >> 11;
	*gpio_enable = (local_val & ((u32)0x00000400)) >> 10;
	*input_enable = (local_val & ((u32)0x00000200)) >> 9;
	*driver_pull_state = (local_val & ((u32)0x000000C0)) >> 6;
	*output_pad_strength = (local_val & ((u32)0x00000038)) >> 3;
	*mux_select = (local_val & ((u32)0x00000007)) >> 0;
}

static inline u8 io_ctrl_tck_gpio_in_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TCK_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline u8 io_ctrl_tck_gpio_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TCK_ADDR);

	return (u8)((local_val & ((u32)0x00001000)) >> 12);
}

static inline void io_ctrl_tck_gpio_out_setf(struct cl_chip *chip, u8 gpioout)
{
	ASSERT_ERR_CHIP((((u32)gpioout << 12) & ~((u32)0x00001000)) == 0);
	cl_reg_write(chip, IO_CTRL_TCK_ADDR, (cl_reg_read(chip, IO_CTRL_TCK_ADDR) & ~((u32)0x00001000)) | ((u32)gpioout << 12));
}

static inline u8 io_ctrl_tck_gpio_oe_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TCK_ADDR);

	return (u8)((local_val & ((u32)0x00000800)) >> 11);
}

static inline void io_ctrl_tck_gpio_oe_setf(struct cl_chip *chip, u8 gpiooe)
{
	ASSERT_ERR_CHIP((((u32)gpiooe << 11) & ~((u32)0x00000800)) == 0);
	cl_reg_write(chip, IO_CTRL_TCK_ADDR, (cl_reg_read(chip, IO_CTRL_TCK_ADDR) & ~((u32)0x00000800)) | ((u32)gpiooe << 11));
}

static inline u8 io_ctrl_tck_gpio_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TCK_ADDR);

	return (u8)((local_val & ((u32)0x00000400)) >> 10);
}

static inline void io_ctrl_tck_gpio_enable_setf(struct cl_chip *chip, u8 gpioenable)
{
	ASSERT_ERR_CHIP((((u32)gpioenable << 10) & ~((u32)0x00000400)) == 0);
	cl_reg_write(chip, IO_CTRL_TCK_ADDR, (cl_reg_read(chip, IO_CTRL_TCK_ADDR) & ~((u32)0x00000400)) | ((u32)gpioenable << 10));
}

static inline u8 io_ctrl_tck_input_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TCK_ADDR);

	return (u8)((local_val & ((u32)0x00000200)) >> 9);
}

static inline void io_ctrl_tck_input_enable_setf(struct cl_chip *chip, u8 inputenable)
{
	ASSERT_ERR_CHIP((((u32)inputenable << 9) & ~((u32)0x00000200)) == 0);
	cl_reg_write(chip, IO_CTRL_TCK_ADDR, (cl_reg_read(chip, IO_CTRL_TCK_ADDR) & ~((u32)0x00000200)) | ((u32)inputenable << 9));
}

static inline u8 io_ctrl_tck_driver_pull_state_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TCK_ADDR);

	return (u8)((local_val & ((u32)0x000000C0)) >> 6);
}

static inline void io_ctrl_tck_driver_pull_state_setf(struct cl_chip *chip, u8 driverpullstate)
{
	ASSERT_ERR_CHIP((((u32)driverpullstate << 6) & ~((u32)0x000000C0)) == 0);
	cl_reg_write(chip, IO_CTRL_TCK_ADDR, (cl_reg_read(chip, IO_CTRL_TCK_ADDR) & ~((u32)0x000000C0)) | ((u32)driverpullstate << 6));
}

static inline u8 io_ctrl_tck_output_pad_strength_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TCK_ADDR);

	return (u8)((local_val & ((u32)0x00000038)) >> 3);
}

static inline void io_ctrl_tck_output_pad_strength_setf(struct cl_chip *chip, u8 outputpadstrength)
{
	ASSERT_ERR_CHIP((((u32)outputpadstrength << 3) & ~((u32)0x00000038)) == 0);
	cl_reg_write(chip, IO_CTRL_TCK_ADDR, (cl_reg_read(chip, IO_CTRL_TCK_ADDR) & ~((u32)0x00000038)) | ((u32)outputpadstrength << 3));
}

static inline u8 io_ctrl_tck_mux_select_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TCK_ADDR);

	return (u8)((local_val & ((u32)0x00000007)) >> 0);
}

static inline void io_ctrl_tck_mux_select_setf(struct cl_chip *chip, u8 muxselect)
{
	ASSERT_ERR_CHIP((((u32)muxselect << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_TCK_ADDR, (cl_reg_read(chip, IO_CTRL_TCK_ADDR) & ~((u32)0x00000007)) | ((u32)muxselect << 0));
}

/**
 * @brief TMS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    13    GPIO_IN                   1
 *    12    GPIO_OUT                  0
 *    11    GPIO_OE                   0
 *    10    GPIO_ENABLE               0
 *    09    input_enable              1
 *    07:06 DRIVER_PULL_STATE         0x2
 *    05:03 OUTPUT_PAD_STRENGTH       0x2
 *    02:00 MUX_SELECT                0x0
 * </pre>
 */
#define IO_CTRL_TMS_ADDR        (REG_IO_CTRL_BASE_ADDR + 0x00000020)
#define IO_CTRL_TMS_OFFSET      0x00000020
#define IO_CTRL_TMS_INDEX       0x00000008
#define IO_CTRL_TMS_RESET       0x000008C8

static inline u32 io_ctrl_tms_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, IO_CTRL_TMS_ADDR);
}

static inline void io_ctrl_tms_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, IO_CTRL_TMS_ADDR, value);
}

/* Field definitions */
#define IO_CTRL_TMS_GPIO_IN_BIT             ((u32)0x00002000)
#define IO_CTRL_TMS_GPIO_IN_POS             13
#define IO_CTRL_TMS_GPIO_OUT_BIT            ((u32)0x00001000)
#define IO_CTRL_TMS_GPIO_OUT_POS            12
#define IO_CTRL_TMS_GPIO_OE_BIT             ((u32)0x00000800)
#define IO_CTRL_TMS_GPIO_OE_POS             11
#define IO_CTRL_TMS_GPIO_ENABLE_BIT         ((u32)0x00000400)
#define IO_CTRL_TMS_GPIO_ENABLE_POS         10
#define IO_CTRL_TMS_INPUT_ENABLE_BIT        ((u32)0x00000200)
#define IO_CTRL_TMS_INPUT_ENABLE_POS        9
#define IO_CTRL_TMS_DRIVER_PULL_STATE_MASK    ((u32)0x000000C0)
#define IO_CTRL_TMS_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_TMS_DRIVER_PULL_STATE_WIDTH    ((u32)0x00000002)
#define IO_CTRL_TMS_OUTPUT_PAD_STRENGTH_MASK    ((u32)0x00000038)
#define IO_CTRL_TMS_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_TMS_OUTPUT_PAD_STRENGTH_WIDTH    ((u32)0x00000003)
#define IO_CTRL_TMS_MUX_SELECT_MASK         ((u32)0x00000007)
#define IO_CTRL_TMS_MUX_SELECT_LSB          0
#define IO_CTRL_TMS_MUX_SELECT_WIDTH        ((u32)0x00000003)

#define IO_CTRL_TMS_GPIO_IN_RST             0x1
#define IO_CTRL_TMS_GPIO_OUT_RST            0x0
#define IO_CTRL_TMS_GPIO_OE_RST             0x0
#define IO_CTRL_TMS_GPIO_ENABLE_RST         0x0
#define IO_CTRL_TMS_INPUT_ENABLE_RST        0x1
#define IO_CTRL_TMS_DRIVER_PULL_STATE_RST    0x2
#define IO_CTRL_TMS_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_TMS_MUX_SELECT_RST          0x0

static inline void io_ctrl_tms_pack(struct cl_chip *chip, u8 gpio_in, u8 gpio_out, u8 gpio_oe, u8 gpio_enable, u8 input_enable, u8 driver_pull_state, u8 output_pad_strength, u8 mux_select)
{
	ASSERT_ERR_CHIP((((u32)gpio_in << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_out << 12) & ~((u32)0x00001000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_oe << 11) & ~((u32)0x00000800)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_enable << 10) & ~((u32)0x00000400)) == 0);
	ASSERT_ERR_CHIP((((u32)input_enable << 9) & ~((u32)0x00000200)) == 0);
	ASSERT_ERR_CHIP((((u32)driver_pull_state << 6) & ~((u32)0x000000C0)) == 0);
	ASSERT_ERR_CHIP((((u32)output_pad_strength << 3) & ~((u32)0x00000038)) == 0);
	ASSERT_ERR_CHIP((((u32)mux_select << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_TMS_ADDR,  ((u32)gpio_in << 13) | ((u32)gpio_out << 12) | ((u32)gpio_oe << 11) | ((u32)gpio_enable << 10) | ((u32)input_enable << 9) | ((u32)driver_pull_state << 6) | ((u32)output_pad_strength << 3) | ((u32)mux_select << 0));
}

static inline void io_ctrl_tms_unpack(struct cl_chip *chip, u8 *gpio_in, u8 *gpio_out, u8 *gpio_oe, u8 *gpio_enable, u8 *input_enable, u8 *driver_pull_state, u8 *output_pad_strength, u8 *mux_select)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TMS_ADDR);

	*gpio_in = (local_val & ((u32)0x00002000)) >> 13;
	*gpio_out = (local_val & ((u32)0x00001000)) >> 12;
	*gpio_oe = (local_val & ((u32)0x00000800)) >> 11;
	*gpio_enable = (local_val & ((u32)0x00000400)) >> 10;
	*input_enable = (local_val & ((u32)0x00000200)) >> 9;
	*driver_pull_state = (local_val & ((u32)0x000000C0)) >> 6;
	*output_pad_strength = (local_val & ((u32)0x00000038)) >> 3;
	*mux_select = (local_val & ((u32)0x00000007)) >> 0;
}

static inline u8 io_ctrl_tms_gpio_in_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TMS_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline u8 io_ctrl_tms_gpio_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TMS_ADDR);

	return (u8)((local_val & ((u32)0x00001000)) >> 12);
}

static inline void io_ctrl_tms_gpio_out_setf(struct cl_chip *chip, u8 gpioout)
{
	ASSERT_ERR_CHIP((((u32)gpioout << 12) & ~((u32)0x00001000)) == 0);
	cl_reg_write(chip, IO_CTRL_TMS_ADDR, (cl_reg_read(chip, IO_CTRL_TMS_ADDR) & ~((u32)0x00001000)) | ((u32)gpioout << 12));
}

static inline u8 io_ctrl_tms_gpio_oe_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TMS_ADDR);

	return (u8)((local_val & ((u32)0x00000800)) >> 11);
}

static inline void io_ctrl_tms_gpio_oe_setf(struct cl_chip *chip, u8 gpiooe)
{
	ASSERT_ERR_CHIP((((u32)gpiooe << 11) & ~((u32)0x00000800)) == 0);
	cl_reg_write(chip, IO_CTRL_TMS_ADDR, (cl_reg_read(chip, IO_CTRL_TMS_ADDR) & ~((u32)0x00000800)) | ((u32)gpiooe << 11));
}

static inline u8 io_ctrl_tms_gpio_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TMS_ADDR);

	return (u8)((local_val & ((u32)0x00000400)) >> 10);
}

static inline void io_ctrl_tms_gpio_enable_setf(struct cl_chip *chip, u8 gpioenable)
{
	ASSERT_ERR_CHIP((((u32)gpioenable << 10) & ~((u32)0x00000400)) == 0);
	cl_reg_write(chip, IO_CTRL_TMS_ADDR, (cl_reg_read(chip, IO_CTRL_TMS_ADDR) & ~((u32)0x00000400)) | ((u32)gpioenable << 10));
}

static inline u8 io_ctrl_tms_input_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TMS_ADDR);

	return (u8)((local_val & ((u32)0x00000200)) >> 9);
}

static inline void io_ctrl_tms_input_enable_setf(struct cl_chip *chip, u8 inputenable)
{
	ASSERT_ERR_CHIP((((u32)inputenable << 9) & ~((u32)0x00000200)) == 0);
	cl_reg_write(chip, IO_CTRL_TMS_ADDR, (cl_reg_read(chip, IO_CTRL_TMS_ADDR) & ~((u32)0x00000200)) | ((u32)inputenable << 9));
}

static inline u8 io_ctrl_tms_driver_pull_state_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TMS_ADDR);

	return (u8)((local_val & ((u32)0x000000C0)) >> 6);
}

static inline void io_ctrl_tms_driver_pull_state_setf(struct cl_chip *chip, u8 driverpullstate)
{
	ASSERT_ERR_CHIP((((u32)driverpullstate << 6) & ~((u32)0x000000C0)) == 0);
	cl_reg_write(chip, IO_CTRL_TMS_ADDR, (cl_reg_read(chip, IO_CTRL_TMS_ADDR) & ~((u32)0x000000C0)) | ((u32)driverpullstate << 6));
}

static inline u8 io_ctrl_tms_output_pad_strength_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TMS_ADDR);

	return (u8)((local_val & ((u32)0x00000038)) >> 3);
}

static inline void io_ctrl_tms_output_pad_strength_setf(struct cl_chip *chip, u8 outputpadstrength)
{
	ASSERT_ERR_CHIP((((u32)outputpadstrength << 3) & ~((u32)0x00000038)) == 0);
	cl_reg_write(chip, IO_CTRL_TMS_ADDR, (cl_reg_read(chip, IO_CTRL_TMS_ADDR) & ~((u32)0x00000038)) | ((u32)outputpadstrength << 3));
}

static inline u8 io_ctrl_tms_mux_select_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TMS_ADDR);

	return (u8)((local_val & ((u32)0x00000007)) >> 0);
}

static inline void io_ctrl_tms_mux_select_setf(struct cl_chip *chip, u8 muxselect)
{
	ASSERT_ERR_CHIP((((u32)muxselect << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_TMS_ADDR, (cl_reg_read(chip, IO_CTRL_TMS_ADDR) & ~((u32)0x00000007)) | ((u32)muxselect << 0));
}

/**
 * @brief PTA_PRI_U_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    13    GPIO_IN                   0
 *    12    GPIO_OUT                  0
 *    11    GPIO_OE                   0
 *    10    GPIO_ENABLE               1
 *    09    input_enable              1
 *    07:06 DRIVER_PULL_STATE         0x1
 *    05:03 OUTPUT_PAD_STRENGTH       0x2
 *    02:00 MUX_SELECT                0x0
 * </pre>
 */
#define IO_CTRL_PTA_PRI_U_2_ADDR        (REG_IO_CTRL_BASE_ADDR + 0x00000024)
#define IO_CTRL_PTA_PRI_U_2_OFFSET      0x00000024
#define IO_CTRL_PTA_PRI_U_2_INDEX       0x00000009
#define IO_CTRL_PTA_PRI_U_2_RESET       0x000001A8

static inline u32 io_ctrl_pta_pri_u_2_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, IO_CTRL_PTA_PRI_U_2_ADDR);
}

static inline void io_ctrl_pta_pri_u_2_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, IO_CTRL_PTA_PRI_U_2_ADDR, value);
}

/* Field definitions */
#define IO_CTRL_PTA_PRI_U_2_GPIO_IN_BIT     ((u32)0x00002000)
#define IO_CTRL_PTA_PRI_U_2_GPIO_IN_POS     13
#define IO_CTRL_PTA_PRI_U_2_GPIO_OUT_BIT    ((u32)0x00001000)
#define IO_CTRL_PTA_PRI_U_2_GPIO_OUT_POS    12
#define IO_CTRL_PTA_PRI_U_2_GPIO_OE_BIT     ((u32)0x00000800)
#define IO_CTRL_PTA_PRI_U_2_GPIO_OE_POS     11
#define IO_CTRL_PTA_PRI_U_2_GPIO_ENABLE_BIT    ((u32)0x00000400)
#define IO_CTRL_PTA_PRI_U_2_GPIO_ENABLE_POS    10
#define IO_CTRL_PTA_PRI_U_2_INPUT_ENABLE_BIT    ((u32)0x00000200)
#define IO_CTRL_PTA_PRI_U_2_INPUT_ENABLE_POS    9
#define IO_CTRL_PTA_PRI_U_2_DRIVER_PULL_STATE_MASK    ((u32)0x000000C0)
#define IO_CTRL_PTA_PRI_U_2_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_PTA_PRI_U_2_DRIVER_PULL_STATE_WIDTH    ((u32)0x00000002)
#define IO_CTRL_PTA_PRI_U_2_OUTPUT_PAD_STRENGTH_MASK    ((u32)0x00000038)
#define IO_CTRL_PTA_PRI_U_2_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_PTA_PRI_U_2_OUTPUT_PAD_STRENGTH_WIDTH    ((u32)0x00000003)
#define IO_CTRL_PTA_PRI_U_2_MUX_SELECT_MASK    ((u32)0x00000007)
#define IO_CTRL_PTA_PRI_U_2_MUX_SELECT_LSB    0
#define IO_CTRL_PTA_PRI_U_2_MUX_SELECT_WIDTH    ((u32)0x00000003)

#define IO_CTRL_PTA_PRI_U_2_GPIO_IN_RST     0x0
#define IO_CTRL_PTA_PRI_U_2_GPIO_OUT_RST    0x0
#define IO_CTRL_PTA_PRI_U_2_GPIO_OE_RST     0x0
#define IO_CTRL_PTA_PRI_U_2_GPIO_ENABLE_RST    0x1
#define IO_CTRL_PTA_PRI_U_2_INPUT_ENABLE_RST    0x1
#define IO_CTRL_PTA_PRI_U_2_DRIVER_PULL_STATE_RST    0x1
#define IO_CTRL_PTA_PRI_U_2_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_PTA_PRI_U_2_MUX_SELECT_RST    0x0

static inline void io_ctrl_pta_pri_u_2_pack(struct cl_chip *chip, u8 gpio_in, u8 gpio_out, u8 gpio_oe, u8 gpio_enable, u8 input_enable, u8 driver_pull_state, u8 output_pad_strength, u8 mux_select)
{
	ASSERT_ERR_CHIP((((u32)gpio_in << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_out << 12) & ~((u32)0x00001000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_oe << 11) & ~((u32)0x00000800)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_enable << 10) & ~((u32)0x00000400)) == 0);
	ASSERT_ERR_CHIP((((u32)input_enable << 9) & ~((u32)0x00000200)) == 0);
	ASSERT_ERR_CHIP((((u32)driver_pull_state << 6) & ~((u32)0x000000C0)) == 0);
	ASSERT_ERR_CHIP((((u32)output_pad_strength << 3) & ~((u32)0x00000038)) == 0);
	ASSERT_ERR_CHIP((((u32)mux_select << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_PTA_PRI_U_2_ADDR,  ((u32)gpio_in << 13) | ((u32)gpio_out << 12) | ((u32)gpio_oe << 11) | ((u32)gpio_enable << 10) | ((u32)input_enable << 9) | ((u32)driver_pull_state << 6) | ((u32)output_pad_strength << 3) | ((u32)mux_select << 0));
}

static inline void io_ctrl_pta_pri_u_2_unpack(struct cl_chip *chip, u8 *gpio_in, u8 *gpio_out, u8 *gpio_oe, u8 *gpio_enable, u8 *input_enable, u8 *driver_pull_state, u8 *output_pad_strength, u8 *mux_select)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_PTA_PRI_U_2_ADDR);

	*gpio_in = (local_val & ((u32)0x00002000)) >> 13;
	*gpio_out = (local_val & ((u32)0x00001000)) >> 12;
	*gpio_oe = (local_val & ((u32)0x00000800)) >> 11;
	*gpio_enable = (local_val & ((u32)0x00000400)) >> 10;
	*input_enable = (local_val & ((u32)0x00000200)) >> 9;
	*driver_pull_state = (local_val & ((u32)0x000000C0)) >> 6;
	*output_pad_strength = (local_val & ((u32)0x00000038)) >> 3;
	*mux_select = (local_val & ((u32)0x00000007)) >> 0;
}

static inline u8 io_ctrl_pta_pri_u_2_gpio_in_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_PTA_PRI_U_2_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline u8 io_ctrl_pta_pri_u_2_gpio_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_PTA_PRI_U_2_ADDR);

	return (u8)((local_val & ((u32)0x00001000)) >> 12);
}

static inline void io_ctrl_pta_pri_u_2_gpio_out_setf(struct cl_chip *chip, u8 gpioout)
{
	ASSERT_ERR_CHIP((((u32)gpioout << 12) & ~((u32)0x00001000)) == 0);
	cl_reg_write(chip, IO_CTRL_PTA_PRI_U_2_ADDR, (cl_reg_read(chip, IO_CTRL_PTA_PRI_U_2_ADDR) & ~((u32)0x00001000)) | ((u32)gpioout << 12));
}

static inline u8 io_ctrl_pta_pri_u_2_gpio_oe_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_PTA_PRI_U_2_ADDR);

	return (u8)((local_val & ((u32)0x00000800)) >> 11);
}

static inline void io_ctrl_pta_pri_u_2_gpio_oe_setf(struct cl_chip *chip, u8 gpiooe)
{
	ASSERT_ERR_CHIP((((u32)gpiooe << 11) & ~((u32)0x00000800)) == 0);
	cl_reg_write(chip, IO_CTRL_PTA_PRI_U_2_ADDR, (cl_reg_read(chip, IO_CTRL_PTA_PRI_U_2_ADDR) & ~((u32)0x00000800)) | ((u32)gpiooe << 11));
}

static inline u8 io_ctrl_pta_pri_u_2_gpio_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_PTA_PRI_U_2_ADDR);

	return (u8)((local_val & ((u32)0x00000400)) >> 10);
}

static inline void io_ctrl_pta_pri_u_2_gpio_enable_setf(struct cl_chip *chip, u8 gpioenable)
{
	ASSERT_ERR_CHIP((((u32)gpioenable << 10) & ~((u32)0x00000400)) == 0);
	cl_reg_write(chip, IO_CTRL_PTA_PRI_U_2_ADDR, (cl_reg_read(chip, IO_CTRL_PTA_PRI_U_2_ADDR) & ~((u32)0x00000400)) | ((u32)gpioenable << 10));
}

static inline u8 io_ctrl_pta_pri_u_2_input_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_PTA_PRI_U_2_ADDR);

	return (u8)((local_val & ((u32)0x00000200)) >> 9);
}

static inline void io_ctrl_pta_pri_u_2_input_enable_setf(struct cl_chip *chip, u8 inputenable)
{
	ASSERT_ERR_CHIP((((u32)inputenable << 9) & ~((u32)0x00000200)) == 0);
	cl_reg_write(chip, IO_CTRL_PTA_PRI_U_2_ADDR, (cl_reg_read(chip, IO_CTRL_PTA_PRI_U_2_ADDR) & ~((u32)0x00000200)) | ((u32)inputenable << 9));
}

static inline u8 io_ctrl_pta_pri_u_2_driver_pull_state_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_PTA_PRI_U_2_ADDR);

	return (u8)((local_val & ((u32)0x000000C0)) >> 6);
}

static inline void io_ctrl_pta_pri_u_2_driver_pull_state_setf(struct cl_chip *chip, u8 driverpullstate)
{
	ASSERT_ERR_CHIP((((u32)driverpullstate << 6) & ~((u32)0x000000C0)) == 0);
	cl_reg_write(chip, IO_CTRL_PTA_PRI_U_2_ADDR, (cl_reg_read(chip, IO_CTRL_PTA_PRI_U_2_ADDR) & ~((u32)0x000000C0)) | ((u32)driverpullstate << 6));
}

static inline u8 io_ctrl_pta_pri_u_2_output_pad_strength_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_PTA_PRI_U_2_ADDR);

	return (u8)((local_val & ((u32)0x00000038)) >> 3);
}

static inline void io_ctrl_pta_pri_u_2_output_pad_strength_setf(struct cl_chip *chip, u8 outputpadstrength)
{
	ASSERT_ERR_CHIP((((u32)outputpadstrength << 3) & ~((u32)0x00000038)) == 0);
	cl_reg_write(chip, IO_CTRL_PTA_PRI_U_2_ADDR, (cl_reg_read(chip, IO_CTRL_PTA_PRI_U_2_ADDR) & ~((u32)0x00000038)) | ((u32)outputpadstrength << 3));
}

static inline u8 io_ctrl_pta_pri_u_2_mux_select_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_PTA_PRI_U_2_ADDR);

	return (u8)((local_val & ((u32)0x00000007)) >> 0);
}

static inline void io_ctrl_pta_pri_u_2_mux_select_setf(struct cl_chip *chip, u8 muxselect)
{
	ASSERT_ERR_CHIP((((u32)muxselect << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_PTA_PRI_U_2_ADDR, (cl_reg_read(chip, IO_CTRL_PTA_PRI_U_2_ADDR) & ~((u32)0x00000007)) | ((u32)muxselect << 0));
}

/**
 * @brief CIF_DIN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    13    GPIO_IN                   1
 *    12    GPIO_OUT                  0
 *    11    GPIO_OE                   0
 *    10    GPIO_ENABLE               1
 *    09    input_enable              1
 *    07:06 DRIVER_PULL_STATE         0x2
 *    05:03 OUTPUT_PAD_STRENGTH       0x2
 *    02:00 MUX_SELECT                0x0
 * </pre>
 */
#define IO_CTRL_CIF_DIN_ADDR        (REG_IO_CTRL_BASE_ADDR + 0x00000028)
#define IO_CTRL_CIF_DIN_OFFSET      0x00000028
#define IO_CTRL_CIF_DIN_INDEX       0x0000000A
#define IO_CTRL_CIF_DIN_RESET       0x000009C8

static inline u32 io_ctrl_cif_din_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, IO_CTRL_CIF_DIN_ADDR);
}

static inline void io_ctrl_cif_din_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, IO_CTRL_CIF_DIN_ADDR, value);
}

/* Field definitions */
#define IO_CTRL_CIF_DIN_GPIO_IN_BIT         ((u32)0x00002000)
#define IO_CTRL_CIF_DIN_GPIO_IN_POS         13
#define IO_CTRL_CIF_DIN_GPIO_OUT_BIT        ((u32)0x00001000)
#define IO_CTRL_CIF_DIN_GPIO_OUT_POS        12
#define IO_CTRL_CIF_DIN_GPIO_OE_BIT         ((u32)0x00000800)
#define IO_CTRL_CIF_DIN_GPIO_OE_POS         11
#define IO_CTRL_CIF_DIN_GPIO_ENABLE_BIT     ((u32)0x00000400)
#define IO_CTRL_CIF_DIN_GPIO_ENABLE_POS     10
#define IO_CTRL_CIF_DIN_INPUT_ENABLE_BIT    ((u32)0x00000200)
#define IO_CTRL_CIF_DIN_INPUT_ENABLE_POS    9
#define IO_CTRL_CIF_DIN_DRIVER_PULL_STATE_MASK    ((u32)0x000000C0)
#define IO_CTRL_CIF_DIN_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_CIF_DIN_DRIVER_PULL_STATE_WIDTH    ((u32)0x00000002)
#define IO_CTRL_CIF_DIN_OUTPUT_PAD_STRENGTH_MASK    ((u32)0x00000038)
#define IO_CTRL_CIF_DIN_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_CIF_DIN_OUTPUT_PAD_STRENGTH_WIDTH    ((u32)0x00000003)
#define IO_CTRL_CIF_DIN_MUX_SELECT_MASK     ((u32)0x00000007)
#define IO_CTRL_CIF_DIN_MUX_SELECT_LSB      0
#define IO_CTRL_CIF_DIN_MUX_SELECT_WIDTH    ((u32)0x00000003)

#define IO_CTRL_CIF_DIN_GPIO_IN_RST         0x1
#define IO_CTRL_CIF_DIN_GPIO_OUT_RST        0x0
#define IO_CTRL_CIF_DIN_GPIO_OE_RST         0x0
#define IO_CTRL_CIF_DIN_GPIO_ENABLE_RST     0x1
#define IO_CTRL_CIF_DIN_INPUT_ENABLE_RST    0x1
#define IO_CTRL_CIF_DIN_DRIVER_PULL_STATE_RST    0x2
#define IO_CTRL_CIF_DIN_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_CIF_DIN_MUX_SELECT_RST      0x0

static inline void io_ctrl_cif_din_pack(struct cl_chip *chip, u8 gpio_in, u8 gpio_out, u8 gpio_oe, u8 gpio_enable, u8 input_enable, u8 driver_pull_state, u8 output_pad_strength, u8 mux_select)
{
	ASSERT_ERR_CHIP((((u32)gpio_in << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_out << 12) & ~((u32)0x00001000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_oe << 11) & ~((u32)0x00000800)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_enable << 10) & ~((u32)0x00000400)) == 0);
	ASSERT_ERR_CHIP((((u32)input_enable << 9) & ~((u32)0x00000200)) == 0);
	ASSERT_ERR_CHIP((((u32)driver_pull_state << 6) & ~((u32)0x000000C0)) == 0);
	ASSERT_ERR_CHIP((((u32)output_pad_strength << 3) & ~((u32)0x00000038)) == 0);
	ASSERT_ERR_CHIP((((u32)mux_select << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_CIF_DIN_ADDR,  ((u32)gpio_in << 13) | ((u32)gpio_out << 12) | ((u32)gpio_oe << 11) | ((u32)gpio_enable << 10) | ((u32)input_enable << 9) | ((u32)driver_pull_state << 6) | ((u32)output_pad_strength << 3) | ((u32)mux_select << 0));
}

static inline void io_ctrl_cif_din_unpack(struct cl_chip *chip, u8 *gpio_in, u8 *gpio_out, u8 *gpio_oe, u8 *gpio_enable, u8 *input_enable, u8 *driver_pull_state, u8 *output_pad_strength, u8 *mux_select)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_DIN_ADDR);

	*gpio_in = (local_val & ((u32)0x00002000)) >> 13;
	*gpio_out = (local_val & ((u32)0x00001000)) >> 12;
	*gpio_oe = (local_val & ((u32)0x00000800)) >> 11;
	*gpio_enable = (local_val & ((u32)0x00000400)) >> 10;
	*input_enable = (local_val & ((u32)0x00000200)) >> 9;
	*driver_pull_state = (local_val & ((u32)0x000000C0)) >> 6;
	*output_pad_strength = (local_val & ((u32)0x00000038)) >> 3;
	*mux_select = (local_val & ((u32)0x00000007)) >> 0;
}

static inline u8 io_ctrl_cif_din_gpio_in_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_DIN_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline u8 io_ctrl_cif_din_gpio_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_DIN_ADDR);

	return (u8)((local_val & ((u32)0x00001000)) >> 12);
}

static inline void io_ctrl_cif_din_gpio_out_setf(struct cl_chip *chip, u8 gpioout)
{
	ASSERT_ERR_CHIP((((u32)gpioout << 12) & ~((u32)0x00001000)) == 0);
	cl_reg_write(chip, IO_CTRL_CIF_DIN_ADDR, (cl_reg_read(chip, IO_CTRL_CIF_DIN_ADDR) & ~((u32)0x00001000)) | ((u32)gpioout << 12));
}

static inline u8 io_ctrl_cif_din_gpio_oe_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_DIN_ADDR);

	return (u8)((local_val & ((u32)0x00000800)) >> 11);
}

static inline void io_ctrl_cif_din_gpio_oe_setf(struct cl_chip *chip, u8 gpiooe)
{
	ASSERT_ERR_CHIP((((u32)gpiooe << 11) & ~((u32)0x00000800)) == 0);
	cl_reg_write(chip, IO_CTRL_CIF_DIN_ADDR, (cl_reg_read(chip, IO_CTRL_CIF_DIN_ADDR) & ~((u32)0x00000800)) | ((u32)gpiooe << 11));
}

static inline u8 io_ctrl_cif_din_gpio_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_DIN_ADDR);

	return (u8)((local_val & ((u32)0x00000400)) >> 10);
}

static inline void io_ctrl_cif_din_gpio_enable_setf(struct cl_chip *chip, u8 gpioenable)
{
	ASSERT_ERR_CHIP((((u32)gpioenable << 10) & ~((u32)0x00000400)) == 0);
	cl_reg_write(chip, IO_CTRL_CIF_DIN_ADDR, (cl_reg_read(chip, IO_CTRL_CIF_DIN_ADDR) & ~((u32)0x00000400)) | ((u32)gpioenable << 10));
}

static inline u8 io_ctrl_cif_din_input_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_DIN_ADDR);

	return (u8)((local_val & ((u32)0x00000200)) >> 9);
}

static inline void io_ctrl_cif_din_input_enable_setf(struct cl_chip *chip, u8 inputenable)
{
	ASSERT_ERR_CHIP((((u32)inputenable << 9) & ~((u32)0x00000200)) == 0);
	cl_reg_write(chip, IO_CTRL_CIF_DIN_ADDR, (cl_reg_read(chip, IO_CTRL_CIF_DIN_ADDR) & ~((u32)0x00000200)) | ((u32)inputenable << 9));
}

static inline u8 io_ctrl_cif_din_driver_pull_state_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_DIN_ADDR);

	return (u8)((local_val & ((u32)0x000000C0)) >> 6);
}

static inline void io_ctrl_cif_din_driver_pull_state_setf(struct cl_chip *chip, u8 driverpullstate)
{
	ASSERT_ERR_CHIP((((u32)driverpullstate << 6) & ~((u32)0x000000C0)) == 0);
	cl_reg_write(chip, IO_CTRL_CIF_DIN_ADDR, (cl_reg_read(chip, IO_CTRL_CIF_DIN_ADDR) & ~((u32)0x000000C0)) | ((u32)driverpullstate << 6));
}

static inline u8 io_ctrl_cif_din_output_pad_strength_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_DIN_ADDR);

	return (u8)((local_val & ((u32)0x00000038)) >> 3);
}

static inline void io_ctrl_cif_din_output_pad_strength_setf(struct cl_chip *chip, u8 outputpadstrength)
{
	ASSERT_ERR_CHIP((((u32)outputpadstrength << 3) & ~((u32)0x00000038)) == 0);
	cl_reg_write(chip, IO_CTRL_CIF_DIN_ADDR, (cl_reg_read(chip, IO_CTRL_CIF_DIN_ADDR) & ~((u32)0x00000038)) | ((u32)outputpadstrength << 3));
}

static inline u8 io_ctrl_cif_din_mux_select_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_DIN_ADDR);

	return (u8)((local_val & ((u32)0x00000007)) >> 0);
}

static inline void io_ctrl_cif_din_mux_select_setf(struct cl_chip *chip, u8 muxselect)
{
	ASSERT_ERR_CHIP((((u32)muxselect << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_CIF_DIN_ADDR, (cl_reg_read(chip, IO_CTRL_CIF_DIN_ADDR) & ~((u32)0x00000007)) | ((u32)muxselect << 0));
}

/**
 * @brief CIF_DOUT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    13    GPIO_IN                   1
 *    12    GPIO_OUT                  0
 *    11    GPIO_OE                   0
 *    10    GPIO_ENABLE               1
 *    09    input_enable              1
 *    07:06 DRIVER_PULL_STATE         0x2
 *    05:03 OUTPUT_PAD_STRENGTH       0x2
 *    02:00 MUX_SELECT                0x0
 * </pre>
 */
#define IO_CTRL_CIF_DOUT_ADDR        (REG_IO_CTRL_BASE_ADDR + 0x0000002C)
#define IO_CTRL_CIF_DOUT_OFFSET      0x0000002C
#define IO_CTRL_CIF_DOUT_INDEX       0x0000000B
#define IO_CTRL_CIF_DOUT_RESET       0x000009C8

static inline u32 io_ctrl_cif_dout_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, IO_CTRL_CIF_DOUT_ADDR);
}

static inline void io_ctrl_cif_dout_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, IO_CTRL_CIF_DOUT_ADDR, value);
}

/* Field definitions */
#define IO_CTRL_CIF_DOUT_GPIO_IN_BIT        ((u32)0x00002000)
#define IO_CTRL_CIF_DOUT_GPIO_IN_POS        13
#define IO_CTRL_CIF_DOUT_GPIO_OUT_BIT       ((u32)0x00001000)
#define IO_CTRL_CIF_DOUT_GPIO_OUT_POS       12
#define IO_CTRL_CIF_DOUT_GPIO_OE_BIT        ((u32)0x00000800)
#define IO_CTRL_CIF_DOUT_GPIO_OE_POS        11
#define IO_CTRL_CIF_DOUT_GPIO_ENABLE_BIT    ((u32)0x00000400)
#define IO_CTRL_CIF_DOUT_GPIO_ENABLE_POS    10
#define IO_CTRL_CIF_DOUT_INPUT_ENABLE_BIT    ((u32)0x00000200)
#define IO_CTRL_CIF_DOUT_INPUT_ENABLE_POS    9
#define IO_CTRL_CIF_DOUT_DRIVER_PULL_STATE_MASK    ((u32)0x000000C0)
#define IO_CTRL_CIF_DOUT_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_CIF_DOUT_DRIVER_PULL_STATE_WIDTH    ((u32)0x00000002)
#define IO_CTRL_CIF_DOUT_OUTPUT_PAD_STRENGTH_MASK    ((u32)0x00000038)
#define IO_CTRL_CIF_DOUT_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_CIF_DOUT_OUTPUT_PAD_STRENGTH_WIDTH    ((u32)0x00000003)
#define IO_CTRL_CIF_DOUT_MUX_SELECT_MASK    ((u32)0x00000007)
#define IO_CTRL_CIF_DOUT_MUX_SELECT_LSB     0
#define IO_CTRL_CIF_DOUT_MUX_SELECT_WIDTH    ((u32)0x00000003)

#define IO_CTRL_CIF_DOUT_GPIO_IN_RST        0x1
#define IO_CTRL_CIF_DOUT_GPIO_OUT_RST       0x0
#define IO_CTRL_CIF_DOUT_GPIO_OE_RST        0x0
#define IO_CTRL_CIF_DOUT_GPIO_ENABLE_RST    0x1
#define IO_CTRL_CIF_DOUT_INPUT_ENABLE_RST    0x1
#define IO_CTRL_CIF_DOUT_DRIVER_PULL_STATE_RST    0x2
#define IO_CTRL_CIF_DOUT_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_CIF_DOUT_MUX_SELECT_RST     0x0

static inline void io_ctrl_cif_dout_pack(struct cl_chip *chip, u8 gpio_in, u8 gpio_out, u8 gpio_oe, u8 gpio_enable, u8 input_enable, u8 driver_pull_state, u8 output_pad_strength, u8 mux_select)
{
	ASSERT_ERR_CHIP((((u32)gpio_in << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_out << 12) & ~((u32)0x00001000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_oe << 11) & ~((u32)0x00000800)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_enable << 10) & ~((u32)0x00000400)) == 0);
	ASSERT_ERR_CHIP((((u32)input_enable << 9) & ~((u32)0x00000200)) == 0);
	ASSERT_ERR_CHIP((((u32)driver_pull_state << 6) & ~((u32)0x000000C0)) == 0);
	ASSERT_ERR_CHIP((((u32)output_pad_strength << 3) & ~((u32)0x00000038)) == 0);
	ASSERT_ERR_CHIP((((u32)mux_select << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_CIF_DOUT_ADDR,  ((u32)gpio_in << 13) | ((u32)gpio_out << 12) | ((u32)gpio_oe << 11) | ((u32)gpio_enable << 10) | ((u32)input_enable << 9) | ((u32)driver_pull_state << 6) | ((u32)output_pad_strength << 3) | ((u32)mux_select << 0));
}

static inline void io_ctrl_cif_dout_unpack(struct cl_chip *chip, u8 *gpio_in, u8 *gpio_out, u8 *gpio_oe, u8 *gpio_enable, u8 *input_enable, u8 *driver_pull_state, u8 *output_pad_strength, u8 *mux_select)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_DOUT_ADDR);

	*gpio_in = (local_val & ((u32)0x00002000)) >> 13;
	*gpio_out = (local_val & ((u32)0x00001000)) >> 12;
	*gpio_oe = (local_val & ((u32)0x00000800)) >> 11;
	*gpio_enable = (local_val & ((u32)0x00000400)) >> 10;
	*input_enable = (local_val & ((u32)0x00000200)) >> 9;
	*driver_pull_state = (local_val & ((u32)0x000000C0)) >> 6;
	*output_pad_strength = (local_val & ((u32)0x00000038)) >> 3;
	*mux_select = (local_val & ((u32)0x00000007)) >> 0;
}

static inline u8 io_ctrl_cif_dout_gpio_in_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_DOUT_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline u8 io_ctrl_cif_dout_gpio_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_DOUT_ADDR);

	return (u8)((local_val & ((u32)0x00001000)) >> 12);
}

static inline void io_ctrl_cif_dout_gpio_out_setf(struct cl_chip *chip, u8 gpioout)
{
	ASSERT_ERR_CHIP((((u32)gpioout << 12) & ~((u32)0x00001000)) == 0);
	cl_reg_write(chip, IO_CTRL_CIF_DOUT_ADDR, (cl_reg_read(chip, IO_CTRL_CIF_DOUT_ADDR) & ~((u32)0x00001000)) | ((u32)gpioout << 12));
}

static inline u8 io_ctrl_cif_dout_gpio_oe_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_DOUT_ADDR);

	return (u8)((local_val & ((u32)0x00000800)) >> 11);
}

static inline void io_ctrl_cif_dout_gpio_oe_setf(struct cl_chip *chip, u8 gpiooe)
{
	ASSERT_ERR_CHIP((((u32)gpiooe << 11) & ~((u32)0x00000800)) == 0);
	cl_reg_write(chip, IO_CTRL_CIF_DOUT_ADDR, (cl_reg_read(chip, IO_CTRL_CIF_DOUT_ADDR) & ~((u32)0x00000800)) | ((u32)gpiooe << 11));
}

static inline u8 io_ctrl_cif_dout_gpio_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_DOUT_ADDR);

	return (u8)((local_val & ((u32)0x00000400)) >> 10);
}

static inline void io_ctrl_cif_dout_gpio_enable_setf(struct cl_chip *chip, u8 gpioenable)
{
	ASSERT_ERR_CHIP((((u32)gpioenable << 10) & ~((u32)0x00000400)) == 0);
	cl_reg_write(chip, IO_CTRL_CIF_DOUT_ADDR, (cl_reg_read(chip, IO_CTRL_CIF_DOUT_ADDR) & ~((u32)0x00000400)) | ((u32)gpioenable << 10));
}

static inline u8 io_ctrl_cif_dout_input_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_DOUT_ADDR);

	return (u8)((local_val & ((u32)0x00000200)) >> 9);
}

static inline void io_ctrl_cif_dout_input_enable_setf(struct cl_chip *chip, u8 inputenable)
{
	ASSERT_ERR_CHIP((((u32)inputenable << 9) & ~((u32)0x00000200)) == 0);
	cl_reg_write(chip, IO_CTRL_CIF_DOUT_ADDR, (cl_reg_read(chip, IO_CTRL_CIF_DOUT_ADDR) & ~((u32)0x00000200)) | ((u32)inputenable << 9));
}

static inline u8 io_ctrl_cif_dout_driver_pull_state_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_DOUT_ADDR);

	return (u8)((local_val & ((u32)0x000000C0)) >> 6);
}

static inline void io_ctrl_cif_dout_driver_pull_state_setf(struct cl_chip *chip, u8 driverpullstate)
{
	ASSERT_ERR_CHIP((((u32)driverpullstate << 6) & ~((u32)0x000000C0)) == 0);
	cl_reg_write(chip, IO_CTRL_CIF_DOUT_ADDR, (cl_reg_read(chip, IO_CTRL_CIF_DOUT_ADDR) & ~((u32)0x000000C0)) | ((u32)driverpullstate << 6));
}

static inline u8 io_ctrl_cif_dout_output_pad_strength_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_DOUT_ADDR);

	return (u8)((local_val & ((u32)0x00000038)) >> 3);
}

static inline void io_ctrl_cif_dout_output_pad_strength_setf(struct cl_chip *chip, u8 outputpadstrength)
{
	ASSERT_ERR_CHIP((((u32)outputpadstrength << 3) & ~((u32)0x00000038)) == 0);
	cl_reg_write(chip, IO_CTRL_CIF_DOUT_ADDR, (cl_reg_read(chip, IO_CTRL_CIF_DOUT_ADDR) & ~((u32)0x00000038)) | ((u32)outputpadstrength << 3));
}

static inline u8 io_ctrl_cif_dout_mux_select_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_DOUT_ADDR);

	return (u8)((local_val & ((u32)0x00000007)) >> 0);
}

static inline void io_ctrl_cif_dout_mux_select_setf(struct cl_chip *chip, u8 muxselect)
{
	ASSERT_ERR_CHIP((((u32)muxselect << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_CIF_DOUT_ADDR, (cl_reg_read(chip, IO_CTRL_CIF_DOUT_ADDR) & ~((u32)0x00000007)) | ((u32)muxselect << 0));
}

/**
 * @brief CIF_FS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    13    GPIO_IN                   1
 *    12    GPIO_OUT                  0
 *    11    GPIO_OE                   0
 *    10    GPIO_ENABLE               1
 *    09    input_enable              1
 *    07:06 DRIVER_PULL_STATE         0x2
 *    05:03 OUTPUT_PAD_STRENGTH       0x2
 *    02:00 MUX_SELECT                0x0
 * </pre>
 */
#define IO_CTRL_CIF_FS_ADDR        (REG_IO_CTRL_BASE_ADDR + 0x00000030)
#define IO_CTRL_CIF_FS_OFFSET      0x00000030
#define IO_CTRL_CIF_FS_INDEX       0x0000000C
#define IO_CTRL_CIF_FS_RESET       0x000009C8

static inline u32 io_ctrl_cif_fs_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, IO_CTRL_CIF_FS_ADDR);
}

static inline void io_ctrl_cif_fs_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, IO_CTRL_CIF_FS_ADDR, value);
}

/* Field definitions */
#define IO_CTRL_CIF_FS_GPIO_IN_BIT          ((u32)0x00002000)
#define IO_CTRL_CIF_FS_GPIO_IN_POS          13
#define IO_CTRL_CIF_FS_GPIO_OUT_BIT         ((u32)0x00001000)
#define IO_CTRL_CIF_FS_GPIO_OUT_POS         12
#define IO_CTRL_CIF_FS_GPIO_OE_BIT          ((u32)0x00000800)
#define IO_CTRL_CIF_FS_GPIO_OE_POS          11
#define IO_CTRL_CIF_FS_GPIO_ENABLE_BIT      ((u32)0x00000400)
#define IO_CTRL_CIF_FS_GPIO_ENABLE_POS      10
#define IO_CTRL_CIF_FS_INPUT_ENABLE_BIT     ((u32)0x00000200)
#define IO_CTRL_CIF_FS_INPUT_ENABLE_POS     9
#define IO_CTRL_CIF_FS_DRIVER_PULL_STATE_MASK    ((u32)0x000000C0)
#define IO_CTRL_CIF_FS_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_CIF_FS_DRIVER_PULL_STATE_WIDTH    ((u32)0x00000002)
#define IO_CTRL_CIF_FS_OUTPUT_PAD_STRENGTH_MASK    ((u32)0x00000038)
#define IO_CTRL_CIF_FS_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_CIF_FS_OUTPUT_PAD_STRENGTH_WIDTH    ((u32)0x00000003)
#define IO_CTRL_CIF_FS_MUX_SELECT_MASK      ((u32)0x00000007)
#define IO_CTRL_CIF_FS_MUX_SELECT_LSB       0
#define IO_CTRL_CIF_FS_MUX_SELECT_WIDTH     ((u32)0x00000003)

#define IO_CTRL_CIF_FS_GPIO_IN_RST          0x1
#define IO_CTRL_CIF_FS_GPIO_OUT_RST         0x0
#define IO_CTRL_CIF_FS_GPIO_OE_RST          0x0
#define IO_CTRL_CIF_FS_GPIO_ENABLE_RST      0x1
#define IO_CTRL_CIF_FS_INPUT_ENABLE_RST     0x1
#define IO_CTRL_CIF_FS_DRIVER_PULL_STATE_RST    0x2
#define IO_CTRL_CIF_FS_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_CIF_FS_MUX_SELECT_RST       0x0

static inline void io_ctrl_cif_fs_pack(struct cl_chip *chip, u8 gpio_in, u8 gpio_out, u8 gpio_oe, u8 gpio_enable, u8 input_enable, u8 driver_pull_state, u8 output_pad_strength, u8 mux_select)
{
	ASSERT_ERR_CHIP((((u32)gpio_in << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_out << 12) & ~((u32)0x00001000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_oe << 11) & ~((u32)0x00000800)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_enable << 10) & ~((u32)0x00000400)) == 0);
	ASSERT_ERR_CHIP((((u32)input_enable << 9) & ~((u32)0x00000200)) == 0);
	ASSERT_ERR_CHIP((((u32)driver_pull_state << 6) & ~((u32)0x000000C0)) == 0);
	ASSERT_ERR_CHIP((((u32)output_pad_strength << 3) & ~((u32)0x00000038)) == 0);
	ASSERT_ERR_CHIP((((u32)mux_select << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_CIF_FS_ADDR,  ((u32)gpio_in << 13) | ((u32)gpio_out << 12) | ((u32)gpio_oe << 11) | ((u32)gpio_enable << 10) | ((u32)input_enable << 9) | ((u32)driver_pull_state << 6) | ((u32)output_pad_strength << 3) | ((u32)mux_select << 0));
}

static inline void io_ctrl_cif_fs_unpack(struct cl_chip *chip, u8 *gpio_in, u8 *gpio_out, u8 *gpio_oe, u8 *gpio_enable, u8 *input_enable, u8 *driver_pull_state, u8 *output_pad_strength, u8 *mux_select)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_FS_ADDR);

	*gpio_in = (local_val & ((u32)0x00002000)) >> 13;
	*gpio_out = (local_val & ((u32)0x00001000)) >> 12;
	*gpio_oe = (local_val & ((u32)0x00000800)) >> 11;
	*gpio_enable = (local_val & ((u32)0x00000400)) >> 10;
	*input_enable = (local_val & ((u32)0x00000200)) >> 9;
	*driver_pull_state = (local_val & ((u32)0x000000C0)) >> 6;
	*output_pad_strength = (local_val & ((u32)0x00000038)) >> 3;
	*mux_select = (local_val & ((u32)0x00000007)) >> 0;
}

static inline u8 io_ctrl_cif_fs_gpio_in_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_FS_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline u8 io_ctrl_cif_fs_gpio_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_FS_ADDR);

	return (u8)((local_val & ((u32)0x00001000)) >> 12);
}

static inline void io_ctrl_cif_fs_gpio_out_setf(struct cl_chip *chip, u8 gpioout)
{
	ASSERT_ERR_CHIP((((u32)gpioout << 12) & ~((u32)0x00001000)) == 0);
	cl_reg_write(chip, IO_CTRL_CIF_FS_ADDR, (cl_reg_read(chip, IO_CTRL_CIF_FS_ADDR) & ~((u32)0x00001000)) | ((u32)gpioout << 12));
}

static inline u8 io_ctrl_cif_fs_gpio_oe_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_FS_ADDR);

	return (u8)((local_val & ((u32)0x00000800)) >> 11);
}

static inline void io_ctrl_cif_fs_gpio_oe_setf(struct cl_chip *chip, u8 gpiooe)
{
	ASSERT_ERR_CHIP((((u32)gpiooe << 11) & ~((u32)0x00000800)) == 0);
	cl_reg_write(chip, IO_CTRL_CIF_FS_ADDR, (cl_reg_read(chip, IO_CTRL_CIF_FS_ADDR) & ~((u32)0x00000800)) | ((u32)gpiooe << 11));
}

static inline u8 io_ctrl_cif_fs_gpio_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_FS_ADDR);

	return (u8)((local_val & ((u32)0x00000400)) >> 10);
}

static inline void io_ctrl_cif_fs_gpio_enable_setf(struct cl_chip *chip, u8 gpioenable)
{
	ASSERT_ERR_CHIP((((u32)gpioenable << 10) & ~((u32)0x00000400)) == 0);
	cl_reg_write(chip, IO_CTRL_CIF_FS_ADDR, (cl_reg_read(chip, IO_CTRL_CIF_FS_ADDR) & ~((u32)0x00000400)) | ((u32)gpioenable << 10));
}

static inline u8 io_ctrl_cif_fs_input_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_FS_ADDR);

	return (u8)((local_val & ((u32)0x00000200)) >> 9);
}

static inline void io_ctrl_cif_fs_input_enable_setf(struct cl_chip *chip, u8 inputenable)
{
	ASSERT_ERR_CHIP((((u32)inputenable << 9) & ~((u32)0x00000200)) == 0);
	cl_reg_write(chip, IO_CTRL_CIF_FS_ADDR, (cl_reg_read(chip, IO_CTRL_CIF_FS_ADDR) & ~((u32)0x00000200)) | ((u32)inputenable << 9));
}

static inline u8 io_ctrl_cif_fs_driver_pull_state_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_FS_ADDR);

	return (u8)((local_val & ((u32)0x000000C0)) >> 6);
}

static inline void io_ctrl_cif_fs_driver_pull_state_setf(struct cl_chip *chip, u8 driverpullstate)
{
	ASSERT_ERR_CHIP((((u32)driverpullstate << 6) & ~((u32)0x000000C0)) == 0);
	cl_reg_write(chip, IO_CTRL_CIF_FS_ADDR, (cl_reg_read(chip, IO_CTRL_CIF_FS_ADDR) & ~((u32)0x000000C0)) | ((u32)driverpullstate << 6));
}

static inline u8 io_ctrl_cif_fs_output_pad_strength_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_FS_ADDR);

	return (u8)((local_val & ((u32)0x00000038)) >> 3);
}

static inline void io_ctrl_cif_fs_output_pad_strength_setf(struct cl_chip *chip, u8 outputpadstrength)
{
	ASSERT_ERR_CHIP((((u32)outputpadstrength << 3) & ~((u32)0x00000038)) == 0);
	cl_reg_write(chip, IO_CTRL_CIF_FS_ADDR, (cl_reg_read(chip, IO_CTRL_CIF_FS_ADDR) & ~((u32)0x00000038)) | ((u32)outputpadstrength << 3));
}

static inline u8 io_ctrl_cif_fs_mux_select_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_FS_ADDR);

	return (u8)((local_val & ((u32)0x00000007)) >> 0);
}

static inline void io_ctrl_cif_fs_mux_select_setf(struct cl_chip *chip, u8 muxselect)
{
	ASSERT_ERR_CHIP((((u32)muxselect << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_CIF_FS_ADDR, (cl_reg_read(chip, IO_CTRL_CIF_FS_ADDR) & ~((u32)0x00000007)) | ((u32)muxselect << 0));
}

/**
 * @brief CIF_BCLK register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    13    GPIO_IN                   1
 *    12    GPIO_OUT                  0
 *    11    GPIO_OE                   0
 *    10    GPIO_ENABLE               1
 *    09    input_enable              1
 *    07:06 DRIVER_PULL_STATE         0x2
 *    05:03 OUTPUT_PAD_STRENGTH       0x2
 *    02:00 MUX_SELECT                0x0
 * </pre>
 */
#define IO_CTRL_CIF_BCLK_ADDR        (REG_IO_CTRL_BASE_ADDR + 0x00000034)
#define IO_CTRL_CIF_BCLK_OFFSET      0x00000034
#define IO_CTRL_CIF_BCLK_INDEX       0x0000000D
#define IO_CTRL_CIF_BCLK_RESET       0x000009C8

static inline u32 io_ctrl_cif_bclk_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, IO_CTRL_CIF_BCLK_ADDR);
}

static inline void io_ctrl_cif_bclk_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, IO_CTRL_CIF_BCLK_ADDR, value);
}

/* Field definitions */
#define IO_CTRL_CIF_BCLK_GPIO_IN_BIT        ((u32)0x00002000)
#define IO_CTRL_CIF_BCLK_GPIO_IN_POS        13
#define IO_CTRL_CIF_BCLK_GPIO_OUT_BIT       ((u32)0x00001000)
#define IO_CTRL_CIF_BCLK_GPIO_OUT_POS       12
#define IO_CTRL_CIF_BCLK_GPIO_OE_BIT        ((u32)0x00000800)
#define IO_CTRL_CIF_BCLK_GPIO_OE_POS        11
#define IO_CTRL_CIF_BCLK_GPIO_ENABLE_BIT    ((u32)0x00000400)
#define IO_CTRL_CIF_BCLK_GPIO_ENABLE_POS    10
#define IO_CTRL_CIF_BCLK_INPUT_ENABLE_BIT    ((u32)0x00000200)
#define IO_CTRL_CIF_BCLK_INPUT_ENABLE_POS    9
#define IO_CTRL_CIF_BCLK_DRIVER_PULL_STATE_MASK    ((u32)0x000000C0)
#define IO_CTRL_CIF_BCLK_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_CIF_BCLK_DRIVER_PULL_STATE_WIDTH    ((u32)0x00000002)
#define IO_CTRL_CIF_BCLK_OUTPUT_PAD_STRENGTH_MASK    ((u32)0x00000038)
#define IO_CTRL_CIF_BCLK_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_CIF_BCLK_OUTPUT_PAD_STRENGTH_WIDTH    ((u32)0x00000003)
#define IO_CTRL_CIF_BCLK_MUX_SELECT_MASK    ((u32)0x00000007)
#define IO_CTRL_CIF_BCLK_MUX_SELECT_LSB     0
#define IO_CTRL_CIF_BCLK_MUX_SELECT_WIDTH    ((u32)0x00000003)

#define IO_CTRL_CIF_BCLK_GPIO_IN_RST        0x1
#define IO_CTRL_CIF_BCLK_GPIO_OUT_RST       0x0
#define IO_CTRL_CIF_BCLK_GPIO_OE_RST        0x0
#define IO_CTRL_CIF_BCLK_GPIO_ENABLE_RST    0x1
#define IO_CTRL_CIF_BCLK_INPUT_ENABLE_RST    0x1
#define IO_CTRL_CIF_BCLK_DRIVER_PULL_STATE_RST    0x2
#define IO_CTRL_CIF_BCLK_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_CIF_BCLK_MUX_SELECT_RST     0x0

static inline void io_ctrl_cif_bclk_pack(struct cl_chip *chip, u8 gpio_in, u8 gpio_out, u8 gpio_oe, u8 gpio_enable, u8 input_enable, u8 driver_pull_state, u8 output_pad_strength, u8 mux_select)
{
	ASSERT_ERR_CHIP((((u32)gpio_in << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_out << 12) & ~((u32)0x00001000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_oe << 11) & ~((u32)0x00000800)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_enable << 10) & ~((u32)0x00000400)) == 0);
	ASSERT_ERR_CHIP((((u32)input_enable << 9) & ~((u32)0x00000200)) == 0);
	ASSERT_ERR_CHIP((((u32)driver_pull_state << 6) & ~((u32)0x000000C0)) == 0);
	ASSERT_ERR_CHIP((((u32)output_pad_strength << 3) & ~((u32)0x00000038)) == 0);
	ASSERT_ERR_CHIP((((u32)mux_select << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_CIF_BCLK_ADDR,  ((u32)gpio_in << 13) | ((u32)gpio_out << 12) | ((u32)gpio_oe << 11) | ((u32)gpio_enable << 10) | ((u32)input_enable << 9) | ((u32)driver_pull_state << 6) | ((u32)output_pad_strength << 3) | ((u32)mux_select << 0));
}

static inline void io_ctrl_cif_bclk_unpack(struct cl_chip *chip, u8 *gpio_in, u8 *gpio_out, u8 *gpio_oe, u8 *gpio_enable, u8 *input_enable, u8 *driver_pull_state, u8 *output_pad_strength, u8 *mux_select)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_BCLK_ADDR);

	*gpio_in = (local_val & ((u32)0x00002000)) >> 13;
	*gpio_out = (local_val & ((u32)0x00001000)) >> 12;
	*gpio_oe = (local_val & ((u32)0x00000800)) >> 11;
	*gpio_enable = (local_val & ((u32)0x00000400)) >> 10;
	*input_enable = (local_val & ((u32)0x00000200)) >> 9;
	*driver_pull_state = (local_val & ((u32)0x000000C0)) >> 6;
	*output_pad_strength = (local_val & ((u32)0x00000038)) >> 3;
	*mux_select = (local_val & ((u32)0x00000007)) >> 0;
}

static inline u8 io_ctrl_cif_bclk_gpio_in_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_BCLK_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline u8 io_ctrl_cif_bclk_gpio_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_BCLK_ADDR);

	return (u8)((local_val & ((u32)0x00001000)) >> 12);
}

static inline void io_ctrl_cif_bclk_gpio_out_setf(struct cl_chip *chip, u8 gpioout)
{
	ASSERT_ERR_CHIP((((u32)gpioout << 12) & ~((u32)0x00001000)) == 0);
	cl_reg_write(chip, IO_CTRL_CIF_BCLK_ADDR, (cl_reg_read(chip, IO_CTRL_CIF_BCLK_ADDR) & ~((u32)0x00001000)) | ((u32)gpioout << 12));
}

static inline u8 io_ctrl_cif_bclk_gpio_oe_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_BCLK_ADDR);

	return (u8)((local_val & ((u32)0x00000800)) >> 11);
}

static inline void io_ctrl_cif_bclk_gpio_oe_setf(struct cl_chip *chip, u8 gpiooe)
{
	ASSERT_ERR_CHIP((((u32)gpiooe << 11) & ~((u32)0x00000800)) == 0);
	cl_reg_write(chip, IO_CTRL_CIF_BCLK_ADDR, (cl_reg_read(chip, IO_CTRL_CIF_BCLK_ADDR) & ~((u32)0x00000800)) | ((u32)gpiooe << 11));
}

static inline u8 io_ctrl_cif_bclk_gpio_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_BCLK_ADDR);

	return (u8)((local_val & ((u32)0x00000400)) >> 10);
}

static inline void io_ctrl_cif_bclk_gpio_enable_setf(struct cl_chip *chip, u8 gpioenable)
{
	ASSERT_ERR_CHIP((((u32)gpioenable << 10) & ~((u32)0x00000400)) == 0);
	cl_reg_write(chip, IO_CTRL_CIF_BCLK_ADDR, (cl_reg_read(chip, IO_CTRL_CIF_BCLK_ADDR) & ~((u32)0x00000400)) | ((u32)gpioenable << 10));
}

static inline u8 io_ctrl_cif_bclk_input_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_BCLK_ADDR);

	return (u8)((local_val & ((u32)0x00000200)) >> 9);
}

static inline void io_ctrl_cif_bclk_input_enable_setf(struct cl_chip *chip, u8 inputenable)
{
	ASSERT_ERR_CHIP((((u32)inputenable << 9) & ~((u32)0x00000200)) == 0);
	cl_reg_write(chip, IO_CTRL_CIF_BCLK_ADDR, (cl_reg_read(chip, IO_CTRL_CIF_BCLK_ADDR) & ~((u32)0x00000200)) | ((u32)inputenable << 9));
}

static inline u8 io_ctrl_cif_bclk_driver_pull_state_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_BCLK_ADDR);

	return (u8)((local_val & ((u32)0x000000C0)) >> 6);
}

static inline void io_ctrl_cif_bclk_driver_pull_state_setf(struct cl_chip *chip, u8 driverpullstate)
{
	ASSERT_ERR_CHIP((((u32)driverpullstate << 6) & ~((u32)0x000000C0)) == 0);
	cl_reg_write(chip, IO_CTRL_CIF_BCLK_ADDR, (cl_reg_read(chip, IO_CTRL_CIF_BCLK_ADDR) & ~((u32)0x000000C0)) | ((u32)driverpullstate << 6));
}

static inline u8 io_ctrl_cif_bclk_output_pad_strength_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_BCLK_ADDR);

	return (u8)((local_val & ((u32)0x00000038)) >> 3);
}

static inline void io_ctrl_cif_bclk_output_pad_strength_setf(struct cl_chip *chip, u8 outputpadstrength)
{
	ASSERT_ERR_CHIP((((u32)outputpadstrength << 3) & ~((u32)0x00000038)) == 0);
	cl_reg_write(chip, IO_CTRL_CIF_BCLK_ADDR, (cl_reg_read(chip, IO_CTRL_CIF_BCLK_ADDR) & ~((u32)0x00000038)) | ((u32)outputpadstrength << 3));
}

static inline u8 io_ctrl_cif_bclk_mux_select_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_BCLK_ADDR);

	return (u8)((local_val & ((u32)0x00000007)) >> 0);
}

static inline void io_ctrl_cif_bclk_mux_select_setf(struct cl_chip *chip, u8 muxselect)
{
	ASSERT_ERR_CHIP((((u32)muxselect << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_CIF_BCLK_ADDR, (cl_reg_read(chip, IO_CTRL_CIF_BCLK_ADDR) & ~((u32)0x00000007)) | ((u32)muxselect << 0));
}

/**
 * @brief CIF_MCLK register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    14    USB_SPEED                 1
 *    13    GPIO_IN                   1
 *    12    GPIO_OUT                  0
 *    11    GPIO_OE                   0
 *    10    GPIO_ENABLE               1
 *    09    input_enable              1
 *    07:06 DRIVER_PULL_STATE         0x2
 *    05:03 OUTPUT_PAD_STRENGTH       0x2
 *    02:00 MUX_SELECT                0x0
 * </pre>
 */
#define IO_CTRL_CIF_MCLK_ADDR        (REG_IO_CTRL_BASE_ADDR + 0x00000038)
#define IO_CTRL_CIF_MCLK_OFFSET      0x00000038
#define IO_CTRL_CIF_MCLK_INDEX       0x0000000E
#define IO_CTRL_CIF_MCLK_RESET       0x000019C8

static inline u32 io_ctrl_cif_mclk_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, IO_CTRL_CIF_MCLK_ADDR);
}

static inline void io_ctrl_cif_mclk_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, IO_CTRL_CIF_MCLK_ADDR, value);
}

/* Field definitions */
#define IO_CTRL_CIF_MCLK_USB_SPEED_BIT      ((u32)0x00004000)
#define IO_CTRL_CIF_MCLK_USB_SPEED_POS      14
#define IO_CTRL_CIF_MCLK_GPIO_IN_BIT        ((u32)0x00002000)
#define IO_CTRL_CIF_MCLK_GPIO_IN_POS        13
#define IO_CTRL_CIF_MCLK_GPIO_OUT_BIT       ((u32)0x00001000)
#define IO_CTRL_CIF_MCLK_GPIO_OUT_POS       12
#define IO_CTRL_CIF_MCLK_GPIO_OE_BIT        ((u32)0x00000800)
#define IO_CTRL_CIF_MCLK_GPIO_OE_POS        11
#define IO_CTRL_CIF_MCLK_GPIO_ENABLE_BIT    ((u32)0x00000400)
#define IO_CTRL_CIF_MCLK_GPIO_ENABLE_POS    10
#define IO_CTRL_CIF_MCLK_INPUT_ENABLE_BIT    ((u32)0x00000200)
#define IO_CTRL_CIF_MCLK_INPUT_ENABLE_POS    9
#define IO_CTRL_CIF_MCLK_DRIVER_PULL_STATE_MASK    ((u32)0x000000C0)
#define IO_CTRL_CIF_MCLK_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_CIF_MCLK_DRIVER_PULL_STATE_WIDTH    ((u32)0x00000002)
#define IO_CTRL_CIF_MCLK_OUTPUT_PAD_STRENGTH_MASK    ((u32)0x00000038)
#define IO_CTRL_CIF_MCLK_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_CIF_MCLK_OUTPUT_PAD_STRENGTH_WIDTH    ((u32)0x00000003)
#define IO_CTRL_CIF_MCLK_MUX_SELECT_MASK    ((u32)0x00000007)
#define IO_CTRL_CIF_MCLK_MUX_SELECT_LSB     0
#define IO_CTRL_CIF_MCLK_MUX_SELECT_WIDTH    ((u32)0x00000003)

#define IO_CTRL_CIF_MCLK_USB_SPEED_RST      0x1
#define IO_CTRL_CIF_MCLK_GPIO_IN_RST        0x1
#define IO_CTRL_CIF_MCLK_GPIO_OUT_RST       0x0
#define IO_CTRL_CIF_MCLK_GPIO_OE_RST        0x0
#define IO_CTRL_CIF_MCLK_GPIO_ENABLE_RST    0x1
#define IO_CTRL_CIF_MCLK_INPUT_ENABLE_RST    0x1
#define IO_CTRL_CIF_MCLK_DRIVER_PULL_STATE_RST    0x2
#define IO_CTRL_CIF_MCLK_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_CIF_MCLK_MUX_SELECT_RST     0x0

static inline void io_ctrl_cif_mclk_pack(struct cl_chip *chip, u8 usb_speed, u8 gpio_in, u8 gpio_out, u8 gpio_oe, u8 gpio_enable, u8 input_enable, u8 driver_pull_state, u8 output_pad_strength, u8 mux_select)
{
	ASSERT_ERR_CHIP((((u32)usb_speed << 14) & ~((u32)0x00004000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_in << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_out << 12) & ~((u32)0x00001000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_oe << 11) & ~((u32)0x00000800)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_enable << 10) & ~((u32)0x00000400)) == 0);
	ASSERT_ERR_CHIP((((u32)input_enable << 9) & ~((u32)0x00000200)) == 0);
	ASSERT_ERR_CHIP((((u32)driver_pull_state << 6) & ~((u32)0x000000C0)) == 0);
	ASSERT_ERR_CHIP((((u32)output_pad_strength << 3) & ~((u32)0x00000038)) == 0);
	ASSERT_ERR_CHIP((((u32)mux_select << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_CIF_MCLK_ADDR,  ((u32)usb_speed << 14) | ((u32)gpio_in << 13) | ((u32)gpio_out << 12) | ((u32)gpio_oe << 11) | ((u32)gpio_enable << 10) | ((u32)input_enable << 9) | ((u32)driver_pull_state << 6) | ((u32)output_pad_strength << 3) | ((u32)mux_select << 0));
}

static inline void io_ctrl_cif_mclk_unpack(struct cl_chip *chip, u8 *usb_speed, u8 *gpio_in, u8 *gpio_out, u8 *gpio_oe, u8 *gpio_enable, u8 *input_enable, u8 *driver_pull_state, u8 *output_pad_strength, u8 *mux_select)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_MCLK_ADDR);

	*usb_speed = (local_val & ((u32)0x00004000)) >> 14;
	*gpio_in = (local_val & ((u32)0x00002000)) >> 13;
	*gpio_out = (local_val & ((u32)0x00001000)) >> 12;
	*gpio_oe = (local_val & ((u32)0x00000800)) >> 11;
	*gpio_enable = (local_val & ((u32)0x00000400)) >> 10;
	*input_enable = (local_val & ((u32)0x00000200)) >> 9;
	*driver_pull_state = (local_val & ((u32)0x000000C0)) >> 6;
	*output_pad_strength = (local_val & ((u32)0x00000038)) >> 3;
	*mux_select = (local_val & ((u32)0x00000007)) >> 0;
}

static inline u8 io_ctrl_cif_mclk_usb_speed_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_MCLK_ADDR);

	return (u8)((local_val & ((u32)0x00004000)) >> 14);
}

static inline u8 io_ctrl_cif_mclk_gpio_in_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_MCLK_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline u8 io_ctrl_cif_mclk_gpio_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_MCLK_ADDR);

	return (u8)((local_val & ((u32)0x00001000)) >> 12);
}

static inline void io_ctrl_cif_mclk_gpio_out_setf(struct cl_chip *chip, u8 gpioout)
{
	ASSERT_ERR_CHIP((((u32)gpioout << 12) & ~((u32)0x00001000)) == 0);
	cl_reg_write(chip, IO_CTRL_CIF_MCLK_ADDR, (cl_reg_read(chip, IO_CTRL_CIF_MCLK_ADDR) & ~((u32)0x00001000)) | ((u32)gpioout << 12));
}

static inline u8 io_ctrl_cif_mclk_gpio_oe_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_MCLK_ADDR);

	return (u8)((local_val & ((u32)0x00000800)) >> 11);
}

static inline void io_ctrl_cif_mclk_gpio_oe_setf(struct cl_chip *chip, u8 gpiooe)
{
	ASSERT_ERR_CHIP((((u32)gpiooe << 11) & ~((u32)0x00000800)) == 0);
	cl_reg_write(chip, IO_CTRL_CIF_MCLK_ADDR, (cl_reg_read(chip, IO_CTRL_CIF_MCLK_ADDR) & ~((u32)0x00000800)) | ((u32)gpiooe << 11));
}

static inline u8 io_ctrl_cif_mclk_gpio_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_MCLK_ADDR);

	return (u8)((local_val & ((u32)0x00000400)) >> 10);
}

static inline void io_ctrl_cif_mclk_gpio_enable_setf(struct cl_chip *chip, u8 gpioenable)
{
	ASSERT_ERR_CHIP((((u32)gpioenable << 10) & ~((u32)0x00000400)) == 0);
	cl_reg_write(chip, IO_CTRL_CIF_MCLK_ADDR, (cl_reg_read(chip, IO_CTRL_CIF_MCLK_ADDR) & ~((u32)0x00000400)) | ((u32)gpioenable << 10));
}

static inline u8 io_ctrl_cif_mclk_input_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_MCLK_ADDR);

	return (u8)((local_val & ((u32)0x00000200)) >> 9);
}

static inline void io_ctrl_cif_mclk_input_enable_setf(struct cl_chip *chip, u8 inputenable)
{
	ASSERT_ERR_CHIP((((u32)inputenable << 9) & ~((u32)0x00000200)) == 0);
	cl_reg_write(chip, IO_CTRL_CIF_MCLK_ADDR, (cl_reg_read(chip, IO_CTRL_CIF_MCLK_ADDR) & ~((u32)0x00000200)) | ((u32)inputenable << 9));
}

static inline u8 io_ctrl_cif_mclk_driver_pull_state_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_MCLK_ADDR);

	return (u8)((local_val & ((u32)0x000000C0)) >> 6);
}

static inline void io_ctrl_cif_mclk_driver_pull_state_setf(struct cl_chip *chip, u8 driverpullstate)
{
	ASSERT_ERR_CHIP((((u32)driverpullstate << 6) & ~((u32)0x000000C0)) == 0);
	cl_reg_write(chip, IO_CTRL_CIF_MCLK_ADDR, (cl_reg_read(chip, IO_CTRL_CIF_MCLK_ADDR) & ~((u32)0x000000C0)) | ((u32)driverpullstate << 6));
}

static inline u8 io_ctrl_cif_mclk_output_pad_strength_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_MCLK_ADDR);

	return (u8)((local_val & ((u32)0x00000038)) >> 3);
}

static inline void io_ctrl_cif_mclk_output_pad_strength_setf(struct cl_chip *chip, u8 outputpadstrength)
{
	ASSERT_ERR_CHIP((((u32)outputpadstrength << 3) & ~((u32)0x00000038)) == 0);
	cl_reg_write(chip, IO_CTRL_CIF_MCLK_ADDR, (cl_reg_read(chip, IO_CTRL_CIF_MCLK_ADDR) & ~((u32)0x00000038)) | ((u32)outputpadstrength << 3));
}

static inline u8 io_ctrl_cif_mclk_mux_select_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CIF_MCLK_ADDR);

	return (u8)((local_val & ((u32)0x00000007)) >> 0);
}

static inline void io_ctrl_cif_mclk_mux_select_setf(struct cl_chip *chip, u8 muxselect)
{
	ASSERT_ERR_CHIP((((u32)muxselect << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_CIF_MCLK_ADDR, (cl_reg_read(chip, IO_CTRL_CIF_MCLK_ADDR) & ~((u32)0x00000007)) | ((u32)muxselect << 0));
}

/**
 * @brief RTS_N register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    13    GPIO_IN                   1
 *    12    GPIO_OUT                  0
 *    11    GPIO_OE                   0
 *    10    GPIO_ENABLE               1
 *    09    input_enable              1
 *    07:06 DRIVER_PULL_STATE         0x2
 *    05:03 OUTPUT_PAD_STRENGTH       0x2
 *    02:00 MUX_SELECT                0x0
 * </pre>
 */
#define IO_CTRL_RTS_N_ADDR        (REG_IO_CTRL_BASE_ADDR + 0x0000003C)
#define IO_CTRL_RTS_N_OFFSET      0x0000003C
#define IO_CTRL_RTS_N_INDEX       0x0000000F
#define IO_CTRL_RTS_N_RESET       0x000009C8

static inline u32 io_ctrl_rts_n_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, IO_CTRL_RTS_N_ADDR);
}

static inline void io_ctrl_rts_n_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, IO_CTRL_RTS_N_ADDR, value);
}

/* Field definitions */
#define IO_CTRL_RTS_N_GPIO_IN_BIT           ((u32)0x00002000)
#define IO_CTRL_RTS_N_GPIO_IN_POS           13
#define IO_CTRL_RTS_N_GPIO_OUT_BIT          ((u32)0x00001000)
#define IO_CTRL_RTS_N_GPIO_OUT_POS          12
#define IO_CTRL_RTS_N_GPIO_OE_BIT           ((u32)0x00000800)
#define IO_CTRL_RTS_N_GPIO_OE_POS           11
#define IO_CTRL_RTS_N_GPIO_ENABLE_BIT       ((u32)0x00000400)
#define IO_CTRL_RTS_N_GPIO_ENABLE_POS       10
#define IO_CTRL_RTS_N_INPUT_ENABLE_BIT      ((u32)0x00000200)
#define IO_CTRL_RTS_N_INPUT_ENABLE_POS      9
#define IO_CTRL_RTS_N_DRIVER_PULL_STATE_MASK    ((u32)0x000000C0)
#define IO_CTRL_RTS_N_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_RTS_N_DRIVER_PULL_STATE_WIDTH    ((u32)0x00000002)
#define IO_CTRL_RTS_N_OUTPUT_PAD_STRENGTH_MASK    ((u32)0x00000038)
#define IO_CTRL_RTS_N_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_RTS_N_OUTPUT_PAD_STRENGTH_WIDTH    ((u32)0x00000003)
#define IO_CTRL_RTS_N_MUX_SELECT_MASK       ((u32)0x00000007)
#define IO_CTRL_RTS_N_MUX_SELECT_LSB        0
#define IO_CTRL_RTS_N_MUX_SELECT_WIDTH      ((u32)0x00000003)

#define IO_CTRL_RTS_N_GPIO_IN_RST           0x1
#define IO_CTRL_RTS_N_GPIO_OUT_RST          0x0
#define IO_CTRL_RTS_N_GPIO_OE_RST           0x0
#define IO_CTRL_RTS_N_GPIO_ENABLE_RST       0x1
#define IO_CTRL_RTS_N_INPUT_ENABLE_RST      0x1
#define IO_CTRL_RTS_N_DRIVER_PULL_STATE_RST    0x2
#define IO_CTRL_RTS_N_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_RTS_N_MUX_SELECT_RST        0x0

static inline void io_ctrl_rts_n_pack(struct cl_chip *chip, u8 gpio_in, u8 gpio_out, u8 gpio_oe, u8 gpio_enable, u8 input_enable, u8 driver_pull_state, u8 output_pad_strength, u8 mux_select)
{
	ASSERT_ERR_CHIP((((u32)gpio_in << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_out << 12) & ~((u32)0x00001000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_oe << 11) & ~((u32)0x00000800)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_enable << 10) & ~((u32)0x00000400)) == 0);
	ASSERT_ERR_CHIP((((u32)input_enable << 9) & ~((u32)0x00000200)) == 0);
	ASSERT_ERR_CHIP((((u32)driver_pull_state << 6) & ~((u32)0x000000C0)) == 0);
	ASSERT_ERR_CHIP((((u32)output_pad_strength << 3) & ~((u32)0x00000038)) == 0);
	ASSERT_ERR_CHIP((((u32)mux_select << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_RTS_N_ADDR,  ((u32)gpio_in << 13) | ((u32)gpio_out << 12) | ((u32)gpio_oe << 11) | ((u32)gpio_enable << 10) | ((u32)input_enable << 9) | ((u32)driver_pull_state << 6) | ((u32)output_pad_strength << 3) | ((u32)mux_select << 0));
}

static inline void io_ctrl_rts_n_unpack(struct cl_chip *chip, u8 *gpio_in, u8 *gpio_out, u8 *gpio_oe, u8 *gpio_enable, u8 *input_enable, u8 *driver_pull_state, u8 *output_pad_strength, u8 *mux_select)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_RTS_N_ADDR);

	*gpio_in = (local_val & ((u32)0x00002000)) >> 13;
	*gpio_out = (local_val & ((u32)0x00001000)) >> 12;
	*gpio_oe = (local_val & ((u32)0x00000800)) >> 11;
	*gpio_enable = (local_val & ((u32)0x00000400)) >> 10;
	*input_enable = (local_val & ((u32)0x00000200)) >> 9;
	*driver_pull_state = (local_val & ((u32)0x000000C0)) >> 6;
	*output_pad_strength = (local_val & ((u32)0x00000038)) >> 3;
	*mux_select = (local_val & ((u32)0x00000007)) >> 0;
}

static inline u8 io_ctrl_rts_n_gpio_in_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_RTS_N_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline u8 io_ctrl_rts_n_gpio_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_RTS_N_ADDR);

	return (u8)((local_val & ((u32)0x00001000)) >> 12);
}

static inline void io_ctrl_rts_n_gpio_out_setf(struct cl_chip *chip, u8 gpioout)
{
	ASSERT_ERR_CHIP((((u32)gpioout << 12) & ~((u32)0x00001000)) == 0);
	cl_reg_write(chip, IO_CTRL_RTS_N_ADDR, (cl_reg_read(chip, IO_CTRL_RTS_N_ADDR) & ~((u32)0x00001000)) | ((u32)gpioout << 12));
}

static inline u8 io_ctrl_rts_n_gpio_oe_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_RTS_N_ADDR);

	return (u8)((local_val & ((u32)0x00000800)) >> 11);
}

static inline void io_ctrl_rts_n_gpio_oe_setf(struct cl_chip *chip, u8 gpiooe)
{
	ASSERT_ERR_CHIP((((u32)gpiooe << 11) & ~((u32)0x00000800)) == 0);
	cl_reg_write(chip, IO_CTRL_RTS_N_ADDR, (cl_reg_read(chip, IO_CTRL_RTS_N_ADDR) & ~((u32)0x00000800)) | ((u32)gpiooe << 11));
}

static inline u8 io_ctrl_rts_n_gpio_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_RTS_N_ADDR);

	return (u8)((local_val & ((u32)0x00000400)) >> 10);
}

static inline void io_ctrl_rts_n_gpio_enable_setf(struct cl_chip *chip, u8 gpioenable)
{
	ASSERT_ERR_CHIP((((u32)gpioenable << 10) & ~((u32)0x00000400)) == 0);
	cl_reg_write(chip, IO_CTRL_RTS_N_ADDR, (cl_reg_read(chip, IO_CTRL_RTS_N_ADDR) & ~((u32)0x00000400)) | ((u32)gpioenable << 10));
}

static inline u8 io_ctrl_rts_n_input_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_RTS_N_ADDR);

	return (u8)((local_val & ((u32)0x00000200)) >> 9);
}

static inline void io_ctrl_rts_n_input_enable_setf(struct cl_chip *chip, u8 inputenable)
{
	ASSERT_ERR_CHIP((((u32)inputenable << 9) & ~((u32)0x00000200)) == 0);
	cl_reg_write(chip, IO_CTRL_RTS_N_ADDR, (cl_reg_read(chip, IO_CTRL_RTS_N_ADDR) & ~((u32)0x00000200)) | ((u32)inputenable << 9));
}

static inline u8 io_ctrl_rts_n_driver_pull_state_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_RTS_N_ADDR);

	return (u8)((local_val & ((u32)0x000000C0)) >> 6);
}

static inline void io_ctrl_rts_n_driver_pull_state_setf(struct cl_chip *chip, u8 driverpullstate)
{
	ASSERT_ERR_CHIP((((u32)driverpullstate << 6) & ~((u32)0x000000C0)) == 0);
	cl_reg_write(chip, IO_CTRL_RTS_N_ADDR, (cl_reg_read(chip, IO_CTRL_RTS_N_ADDR) & ~((u32)0x000000C0)) | ((u32)driverpullstate << 6));
}

static inline u8 io_ctrl_rts_n_output_pad_strength_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_RTS_N_ADDR);

	return (u8)((local_val & ((u32)0x00000038)) >> 3);
}

static inline void io_ctrl_rts_n_output_pad_strength_setf(struct cl_chip *chip, u8 outputpadstrength)
{
	ASSERT_ERR_CHIP((((u32)outputpadstrength << 3) & ~((u32)0x00000038)) == 0);
	cl_reg_write(chip, IO_CTRL_RTS_N_ADDR, (cl_reg_read(chip, IO_CTRL_RTS_N_ADDR) & ~((u32)0x00000038)) | ((u32)outputpadstrength << 3));
}

static inline u8 io_ctrl_rts_n_mux_select_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_RTS_N_ADDR);

	return (u8)((local_val & ((u32)0x00000007)) >> 0);
}

static inline void io_ctrl_rts_n_mux_select_setf(struct cl_chip *chip, u8 muxselect)
{
	ASSERT_ERR_CHIP((((u32)muxselect << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_RTS_N_ADDR, (cl_reg_read(chip, IO_CTRL_RTS_N_ADDR) & ~((u32)0x00000007)) | ((u32)muxselect << 0));
}

/**
 * @brief CTS_N register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    13    GPIO_IN                   1
 *    12    GPIO_OUT                  0
 *    11    GPIO_OE                   0
 *    10    GPIO_ENABLE               1
 *    09    input_enable              1
 *    07:06 DRIVER_PULL_STATE         0x2
 *    05:03 OUTPUT_PAD_STRENGTH       0x2
 *    02:00 MUX_SELECT                0x0
 * </pre>
 */
#define IO_CTRL_CTS_N_ADDR        (REG_IO_CTRL_BASE_ADDR + 0x00000040)
#define IO_CTRL_CTS_N_OFFSET      0x00000040
#define IO_CTRL_CTS_N_INDEX       0x00000010
#define IO_CTRL_CTS_N_RESET       0x000009C8

static inline u32 io_ctrl_cts_n_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, IO_CTRL_CTS_N_ADDR);
}

static inline void io_ctrl_cts_n_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, IO_CTRL_CTS_N_ADDR, value);
}

/* Field definitions */
#define IO_CTRL_CTS_N_GPIO_IN_BIT           ((u32)0x00002000)
#define IO_CTRL_CTS_N_GPIO_IN_POS           13
#define IO_CTRL_CTS_N_GPIO_OUT_BIT          ((u32)0x00001000)
#define IO_CTRL_CTS_N_GPIO_OUT_POS          12
#define IO_CTRL_CTS_N_GPIO_OE_BIT           ((u32)0x00000800)
#define IO_CTRL_CTS_N_GPIO_OE_POS           11
#define IO_CTRL_CTS_N_GPIO_ENABLE_BIT       ((u32)0x00000400)
#define IO_CTRL_CTS_N_GPIO_ENABLE_POS       10
#define IO_CTRL_CTS_N_INPUT_ENABLE_BIT      ((u32)0x00000200)
#define IO_CTRL_CTS_N_INPUT_ENABLE_POS      9
#define IO_CTRL_CTS_N_DRIVER_PULL_STATE_MASK    ((u32)0x000000C0)
#define IO_CTRL_CTS_N_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_CTS_N_DRIVER_PULL_STATE_WIDTH    ((u32)0x00000002)
#define IO_CTRL_CTS_N_OUTPUT_PAD_STRENGTH_MASK    ((u32)0x00000038)
#define IO_CTRL_CTS_N_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_CTS_N_OUTPUT_PAD_STRENGTH_WIDTH    ((u32)0x00000003)
#define IO_CTRL_CTS_N_MUX_SELECT_MASK       ((u32)0x00000007)
#define IO_CTRL_CTS_N_MUX_SELECT_LSB        0
#define IO_CTRL_CTS_N_MUX_SELECT_WIDTH      ((u32)0x00000003)

#define IO_CTRL_CTS_N_GPIO_IN_RST           0x1
#define IO_CTRL_CTS_N_GPIO_OUT_RST          0x0
#define IO_CTRL_CTS_N_GPIO_OE_RST           0x0
#define IO_CTRL_CTS_N_GPIO_ENABLE_RST       0x1
#define IO_CTRL_CTS_N_INPUT_ENABLE_RST      0x1
#define IO_CTRL_CTS_N_DRIVER_PULL_STATE_RST    0x2
#define IO_CTRL_CTS_N_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_CTS_N_MUX_SELECT_RST        0x0

static inline void io_ctrl_cts_n_pack(struct cl_chip *chip, u8 gpio_in, u8 gpio_out, u8 gpio_oe, u8 gpio_enable, u8 input_enable, u8 driver_pull_state, u8 output_pad_strength, u8 mux_select)
{
	ASSERT_ERR_CHIP((((u32)gpio_in << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_out << 12) & ~((u32)0x00001000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_oe << 11) & ~((u32)0x00000800)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_enable << 10) & ~((u32)0x00000400)) == 0);
	ASSERT_ERR_CHIP((((u32)input_enable << 9) & ~((u32)0x00000200)) == 0);
	ASSERT_ERR_CHIP((((u32)driver_pull_state << 6) & ~((u32)0x000000C0)) == 0);
	ASSERT_ERR_CHIP((((u32)output_pad_strength << 3) & ~((u32)0x00000038)) == 0);
	ASSERT_ERR_CHIP((((u32)mux_select << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_CTS_N_ADDR,  ((u32)gpio_in << 13) | ((u32)gpio_out << 12) | ((u32)gpio_oe << 11) | ((u32)gpio_enable << 10) | ((u32)input_enable << 9) | ((u32)driver_pull_state << 6) | ((u32)output_pad_strength << 3) | ((u32)mux_select << 0));
}

static inline void io_ctrl_cts_n_unpack(struct cl_chip *chip, u8 *gpio_in, u8 *gpio_out, u8 *gpio_oe, u8 *gpio_enable, u8 *input_enable, u8 *driver_pull_state, u8 *output_pad_strength, u8 *mux_select)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CTS_N_ADDR);

	*gpio_in = (local_val & ((u32)0x00002000)) >> 13;
	*gpio_out = (local_val & ((u32)0x00001000)) >> 12;
	*gpio_oe = (local_val & ((u32)0x00000800)) >> 11;
	*gpio_enable = (local_val & ((u32)0x00000400)) >> 10;
	*input_enable = (local_val & ((u32)0x00000200)) >> 9;
	*driver_pull_state = (local_val & ((u32)0x000000C0)) >> 6;
	*output_pad_strength = (local_val & ((u32)0x00000038)) >> 3;
	*mux_select = (local_val & ((u32)0x00000007)) >> 0;
}

static inline u8 io_ctrl_cts_n_gpio_in_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CTS_N_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline u8 io_ctrl_cts_n_gpio_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CTS_N_ADDR);

	return (u8)((local_val & ((u32)0x00001000)) >> 12);
}

static inline void io_ctrl_cts_n_gpio_out_setf(struct cl_chip *chip, u8 gpioout)
{
	ASSERT_ERR_CHIP((((u32)gpioout << 12) & ~((u32)0x00001000)) == 0);
	cl_reg_write(chip, IO_CTRL_CTS_N_ADDR, (cl_reg_read(chip, IO_CTRL_CTS_N_ADDR) & ~((u32)0x00001000)) | ((u32)gpioout << 12));
}

static inline u8 io_ctrl_cts_n_gpio_oe_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CTS_N_ADDR);

	return (u8)((local_val & ((u32)0x00000800)) >> 11);
}

static inline void io_ctrl_cts_n_gpio_oe_setf(struct cl_chip *chip, u8 gpiooe)
{
	ASSERT_ERR_CHIP((((u32)gpiooe << 11) & ~((u32)0x00000800)) == 0);
	cl_reg_write(chip, IO_CTRL_CTS_N_ADDR, (cl_reg_read(chip, IO_CTRL_CTS_N_ADDR) & ~((u32)0x00000800)) | ((u32)gpiooe << 11));
}

static inline u8 io_ctrl_cts_n_gpio_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CTS_N_ADDR);

	return (u8)((local_val & ((u32)0x00000400)) >> 10);
}

static inline void io_ctrl_cts_n_gpio_enable_setf(struct cl_chip *chip, u8 gpioenable)
{
	ASSERT_ERR_CHIP((((u32)gpioenable << 10) & ~((u32)0x00000400)) == 0);
	cl_reg_write(chip, IO_CTRL_CTS_N_ADDR, (cl_reg_read(chip, IO_CTRL_CTS_N_ADDR) & ~((u32)0x00000400)) | ((u32)gpioenable << 10));
}

static inline u8 io_ctrl_cts_n_input_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CTS_N_ADDR);

	return (u8)((local_val & ((u32)0x00000200)) >> 9);
}

static inline void io_ctrl_cts_n_input_enable_setf(struct cl_chip *chip, u8 inputenable)
{
	ASSERT_ERR_CHIP((((u32)inputenable << 9) & ~((u32)0x00000200)) == 0);
	cl_reg_write(chip, IO_CTRL_CTS_N_ADDR, (cl_reg_read(chip, IO_CTRL_CTS_N_ADDR) & ~((u32)0x00000200)) | ((u32)inputenable << 9));
}

static inline u8 io_ctrl_cts_n_driver_pull_state_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CTS_N_ADDR);

	return (u8)((local_val & ((u32)0x000000C0)) >> 6);
}

static inline void io_ctrl_cts_n_driver_pull_state_setf(struct cl_chip *chip, u8 driverpullstate)
{
	ASSERT_ERR_CHIP((((u32)driverpullstate << 6) & ~((u32)0x000000C0)) == 0);
	cl_reg_write(chip, IO_CTRL_CTS_N_ADDR, (cl_reg_read(chip, IO_CTRL_CTS_N_ADDR) & ~((u32)0x000000C0)) | ((u32)driverpullstate << 6));
}

static inline u8 io_ctrl_cts_n_output_pad_strength_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CTS_N_ADDR);

	return (u8)((local_val & ((u32)0x00000038)) >> 3);
}

static inline void io_ctrl_cts_n_output_pad_strength_setf(struct cl_chip *chip, u8 outputpadstrength)
{
	ASSERT_ERR_CHIP((((u32)outputpadstrength << 3) & ~((u32)0x00000038)) == 0);
	cl_reg_write(chip, IO_CTRL_CTS_N_ADDR, (cl_reg_read(chip, IO_CTRL_CTS_N_ADDR) & ~((u32)0x00000038)) | ((u32)outputpadstrength << 3));
}

static inline u8 io_ctrl_cts_n_mux_select_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_CTS_N_ADDR);

	return (u8)((local_val & ((u32)0x00000007)) >> 0);
}

static inline void io_ctrl_cts_n_mux_select_setf(struct cl_chip *chip, u8 muxselect)
{
	ASSERT_ERR_CHIP((((u32)muxselect << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_CTS_N_ADDR, (cl_reg_read(chip, IO_CTRL_CTS_N_ADDR) & ~((u32)0x00000007)) | ((u32)muxselect << 0));
}

/**
 * @brief TXD register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    13    GPIO_IN                   0
 *    12    GPIO_OUT                  0
 *    11    GPIO_OE                   0
 *    10    GPIO_ENABLE               1
 *    09    input_enable              1
 *    07:06 DRIVER_PULL_STATE         0x1
 *    05:03 OUTPUT_PAD_STRENGTH       0x2
 *    02:00 MUX_SELECT                0x0
 * </pre>
 */
#define IO_CTRL_TXD_ADDR        (REG_IO_CTRL_BASE_ADDR + 0x00000044)
#define IO_CTRL_TXD_OFFSET      0x00000044
#define IO_CTRL_TXD_INDEX       0x00000011
#define IO_CTRL_TXD_RESET       0x000001A8

static inline u32 io_ctrl_txd_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, IO_CTRL_TXD_ADDR);
}

static inline void io_ctrl_txd_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, IO_CTRL_TXD_ADDR, value);
}

/* Field definitions */
#define IO_CTRL_TXD_GPIO_IN_BIT             ((u32)0x00002000)
#define IO_CTRL_TXD_GPIO_IN_POS             13
#define IO_CTRL_TXD_GPIO_OUT_BIT            ((u32)0x00001000)
#define IO_CTRL_TXD_GPIO_OUT_POS            12
#define IO_CTRL_TXD_GPIO_OE_BIT             ((u32)0x00000800)
#define IO_CTRL_TXD_GPIO_OE_POS             11
#define IO_CTRL_TXD_GPIO_ENABLE_BIT         ((u32)0x00000400)
#define IO_CTRL_TXD_GPIO_ENABLE_POS         10
#define IO_CTRL_TXD_INPUT_ENABLE_BIT        ((u32)0x00000200)
#define IO_CTRL_TXD_INPUT_ENABLE_POS        9
#define IO_CTRL_TXD_DRIVER_PULL_STATE_MASK    ((u32)0x000000C0)
#define IO_CTRL_TXD_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_TXD_DRIVER_PULL_STATE_WIDTH    ((u32)0x00000002)
#define IO_CTRL_TXD_OUTPUT_PAD_STRENGTH_MASK    ((u32)0x00000038)
#define IO_CTRL_TXD_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_TXD_OUTPUT_PAD_STRENGTH_WIDTH    ((u32)0x00000003)
#define IO_CTRL_TXD_MUX_SELECT_MASK         ((u32)0x00000007)
#define IO_CTRL_TXD_MUX_SELECT_LSB          0
#define IO_CTRL_TXD_MUX_SELECT_WIDTH        ((u32)0x00000003)

#define IO_CTRL_TXD_GPIO_IN_RST             0x0
#define IO_CTRL_TXD_GPIO_OUT_RST            0x0
#define IO_CTRL_TXD_GPIO_OE_RST             0x0
#define IO_CTRL_TXD_GPIO_ENABLE_RST         0x1
#define IO_CTRL_TXD_INPUT_ENABLE_RST        0x1
#define IO_CTRL_TXD_DRIVER_PULL_STATE_RST    0x1
#define IO_CTRL_TXD_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_TXD_MUX_SELECT_RST          0x0

static inline void io_ctrl_txd_pack(struct cl_chip *chip, u8 gpio_in, u8 gpio_out, u8 gpio_oe, u8 gpio_enable, u8 input_enable, u8 driver_pull_state, u8 output_pad_strength, u8 mux_select)
{
	ASSERT_ERR_CHIP((((u32)gpio_in << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_out << 12) & ~((u32)0x00001000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_oe << 11) & ~((u32)0x00000800)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_enable << 10) & ~((u32)0x00000400)) == 0);
	ASSERT_ERR_CHIP((((u32)input_enable << 9) & ~((u32)0x00000200)) == 0);
	ASSERT_ERR_CHIP((((u32)driver_pull_state << 6) & ~((u32)0x000000C0)) == 0);
	ASSERT_ERR_CHIP((((u32)output_pad_strength << 3) & ~((u32)0x00000038)) == 0);
	ASSERT_ERR_CHIP((((u32)mux_select << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_TXD_ADDR,  ((u32)gpio_in << 13) | ((u32)gpio_out << 12) | ((u32)gpio_oe << 11) | ((u32)gpio_enable << 10) | ((u32)input_enable << 9) | ((u32)driver_pull_state << 6) | ((u32)output_pad_strength << 3) | ((u32)mux_select << 0));
}

static inline void io_ctrl_txd_unpack(struct cl_chip *chip, u8 *gpio_in, u8 *gpio_out, u8 *gpio_oe, u8 *gpio_enable, u8 *input_enable, u8 *driver_pull_state, u8 *output_pad_strength, u8 *mux_select)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TXD_ADDR);

	*gpio_in = (local_val & ((u32)0x00002000)) >> 13;
	*gpio_out = (local_val & ((u32)0x00001000)) >> 12;
	*gpio_oe = (local_val & ((u32)0x00000800)) >> 11;
	*gpio_enable = (local_val & ((u32)0x00000400)) >> 10;
	*input_enable = (local_val & ((u32)0x00000200)) >> 9;
	*driver_pull_state = (local_val & ((u32)0x000000C0)) >> 6;
	*output_pad_strength = (local_val & ((u32)0x00000038)) >> 3;
	*mux_select = (local_val & ((u32)0x00000007)) >> 0;
}

static inline u8 io_ctrl_txd_gpio_in_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TXD_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline u8 io_ctrl_txd_gpio_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TXD_ADDR);

	return (u8)((local_val & ((u32)0x00001000)) >> 12);
}

static inline void io_ctrl_txd_gpio_out_setf(struct cl_chip *chip, u8 gpioout)
{
	ASSERT_ERR_CHIP((((u32)gpioout << 12) & ~((u32)0x00001000)) == 0);
	cl_reg_write(chip, IO_CTRL_TXD_ADDR, (cl_reg_read(chip, IO_CTRL_TXD_ADDR) & ~((u32)0x00001000)) | ((u32)gpioout << 12));
}

static inline u8 io_ctrl_txd_gpio_oe_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TXD_ADDR);

	return (u8)((local_val & ((u32)0x00000800)) >> 11);
}

static inline void io_ctrl_txd_gpio_oe_setf(struct cl_chip *chip, u8 gpiooe)
{
	ASSERT_ERR_CHIP((((u32)gpiooe << 11) & ~((u32)0x00000800)) == 0);
	cl_reg_write(chip, IO_CTRL_TXD_ADDR, (cl_reg_read(chip, IO_CTRL_TXD_ADDR) & ~((u32)0x00000800)) | ((u32)gpiooe << 11));
}

static inline u8 io_ctrl_txd_gpio_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TXD_ADDR);

	return (u8)((local_val & ((u32)0x00000400)) >> 10);
}

static inline void io_ctrl_txd_gpio_enable_setf(struct cl_chip *chip, u8 gpioenable)
{
	ASSERT_ERR_CHIP((((u32)gpioenable << 10) & ~((u32)0x00000400)) == 0);
	cl_reg_write(chip, IO_CTRL_TXD_ADDR, (cl_reg_read(chip, IO_CTRL_TXD_ADDR) & ~((u32)0x00000400)) | ((u32)gpioenable << 10));
}

static inline u8 io_ctrl_txd_input_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TXD_ADDR);

	return (u8)((local_val & ((u32)0x00000200)) >> 9);
}

static inline void io_ctrl_txd_input_enable_setf(struct cl_chip *chip, u8 inputenable)
{
	ASSERT_ERR_CHIP((((u32)inputenable << 9) & ~((u32)0x00000200)) == 0);
	cl_reg_write(chip, IO_CTRL_TXD_ADDR, (cl_reg_read(chip, IO_CTRL_TXD_ADDR) & ~((u32)0x00000200)) | ((u32)inputenable << 9));
}

static inline u8 io_ctrl_txd_driver_pull_state_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TXD_ADDR);

	return (u8)((local_val & ((u32)0x000000C0)) >> 6);
}

static inline void io_ctrl_txd_driver_pull_state_setf(struct cl_chip *chip, u8 driverpullstate)
{
	ASSERT_ERR_CHIP((((u32)driverpullstate << 6) & ~((u32)0x000000C0)) == 0);
	cl_reg_write(chip, IO_CTRL_TXD_ADDR, (cl_reg_read(chip, IO_CTRL_TXD_ADDR) & ~((u32)0x000000C0)) | ((u32)driverpullstate << 6));
}

static inline u8 io_ctrl_txd_output_pad_strength_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TXD_ADDR);

	return (u8)((local_val & ((u32)0x00000038)) >> 3);
}

static inline void io_ctrl_txd_output_pad_strength_setf(struct cl_chip *chip, u8 outputpadstrength)
{
	ASSERT_ERR_CHIP((((u32)outputpadstrength << 3) & ~((u32)0x00000038)) == 0);
	cl_reg_write(chip, IO_CTRL_TXD_ADDR, (cl_reg_read(chip, IO_CTRL_TXD_ADDR) & ~((u32)0x00000038)) | ((u32)outputpadstrength << 3));
}

static inline u8 io_ctrl_txd_mux_select_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_TXD_ADDR);

	return (u8)((local_val & ((u32)0x00000007)) >> 0);
}

static inline void io_ctrl_txd_mux_select_setf(struct cl_chip *chip, u8 muxselect)
{
	ASSERT_ERR_CHIP((((u32)muxselect << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_TXD_ADDR, (cl_reg_read(chip, IO_CTRL_TXD_ADDR) & ~((u32)0x00000007)) | ((u32)muxselect << 0));
}

/**
 * @brief RXD register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    13    GPIO_IN                   0
 *    12    GPIO_OUT                  0
 *    11    GPIO_OE                   0
 *    10    GPIO_ENABLE               1
 *    09    input_enable              1
 *    07:06 DRIVER_PULL_STATE         0x1
 *    05:03 OUTPUT_PAD_STRENGTH       0x2
 *    02:00 MUX_SELECT                0x0
 * </pre>
 */
#define IO_CTRL_RXD_ADDR        (REG_IO_CTRL_BASE_ADDR + 0x00000048)
#define IO_CTRL_RXD_OFFSET      0x00000048
#define IO_CTRL_RXD_INDEX       0x00000012
#define IO_CTRL_RXD_RESET       0x000001A8

static inline u32 io_ctrl_rxd_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, IO_CTRL_RXD_ADDR);
}

static inline void io_ctrl_rxd_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, IO_CTRL_RXD_ADDR, value);
}

/* Field definitions */
#define IO_CTRL_RXD_GPIO_IN_BIT             ((u32)0x00002000)
#define IO_CTRL_RXD_GPIO_IN_POS             13
#define IO_CTRL_RXD_GPIO_OUT_BIT            ((u32)0x00001000)
#define IO_CTRL_RXD_GPIO_OUT_POS            12
#define IO_CTRL_RXD_GPIO_OE_BIT             ((u32)0x00000800)
#define IO_CTRL_RXD_GPIO_OE_POS             11
#define IO_CTRL_RXD_GPIO_ENABLE_BIT         ((u32)0x00000400)
#define IO_CTRL_RXD_GPIO_ENABLE_POS         10
#define IO_CTRL_RXD_INPUT_ENABLE_BIT        ((u32)0x00000200)
#define IO_CTRL_RXD_INPUT_ENABLE_POS        9
#define IO_CTRL_RXD_DRIVER_PULL_STATE_MASK    ((u32)0x000000C0)
#define IO_CTRL_RXD_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_RXD_DRIVER_PULL_STATE_WIDTH    ((u32)0x00000002)
#define IO_CTRL_RXD_OUTPUT_PAD_STRENGTH_MASK    ((u32)0x00000038)
#define IO_CTRL_RXD_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_RXD_OUTPUT_PAD_STRENGTH_WIDTH    ((u32)0x00000003)
#define IO_CTRL_RXD_MUX_SELECT_MASK         ((u32)0x00000007)
#define IO_CTRL_RXD_MUX_SELECT_LSB          0
#define IO_CTRL_RXD_MUX_SELECT_WIDTH        ((u32)0x00000003)

#define IO_CTRL_RXD_GPIO_IN_RST             0x0
#define IO_CTRL_RXD_GPIO_OUT_RST            0x0
#define IO_CTRL_RXD_GPIO_OE_RST             0x0
#define IO_CTRL_RXD_GPIO_ENABLE_RST         0x1
#define IO_CTRL_RXD_INPUT_ENABLE_RST        0x1
#define IO_CTRL_RXD_DRIVER_PULL_STATE_RST    0x1
#define IO_CTRL_RXD_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_RXD_MUX_SELECT_RST          0x0

static inline void io_ctrl_rxd_pack(struct cl_chip *chip, u8 gpio_in, u8 gpio_out, u8 gpio_oe, u8 gpio_enable, u8 input_enable, u8 driver_pull_state, u8 output_pad_strength, u8 mux_select)
{
	ASSERT_ERR_CHIP((((u32)gpio_in << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_out << 12) & ~((u32)0x00001000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_oe << 11) & ~((u32)0x00000800)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_enable << 10) & ~((u32)0x00000400)) == 0);
	ASSERT_ERR_CHIP((((u32)input_enable << 9) & ~((u32)0x00000200)) == 0);
	ASSERT_ERR_CHIP((((u32)driver_pull_state << 6) & ~((u32)0x000000C0)) == 0);
	ASSERT_ERR_CHIP((((u32)output_pad_strength << 3) & ~((u32)0x00000038)) == 0);
	ASSERT_ERR_CHIP((((u32)mux_select << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_RXD_ADDR,  ((u32)gpio_in << 13) | ((u32)gpio_out << 12) | ((u32)gpio_oe << 11) | ((u32)gpio_enable << 10) | ((u32)input_enable << 9) | ((u32)driver_pull_state << 6) | ((u32)output_pad_strength << 3) | ((u32)mux_select << 0));
}

static inline void io_ctrl_rxd_unpack(struct cl_chip *chip, u8 *gpio_in, u8 *gpio_out, u8 *gpio_oe, u8 *gpio_enable, u8 *input_enable, u8 *driver_pull_state, u8 *output_pad_strength, u8 *mux_select)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_RXD_ADDR);

	*gpio_in = (local_val & ((u32)0x00002000)) >> 13;
	*gpio_out = (local_val & ((u32)0x00001000)) >> 12;
	*gpio_oe = (local_val & ((u32)0x00000800)) >> 11;
	*gpio_enable = (local_val & ((u32)0x00000400)) >> 10;
	*input_enable = (local_val & ((u32)0x00000200)) >> 9;
	*driver_pull_state = (local_val & ((u32)0x000000C0)) >> 6;
	*output_pad_strength = (local_val & ((u32)0x00000038)) >> 3;
	*mux_select = (local_val & ((u32)0x00000007)) >> 0;
}

static inline u8 io_ctrl_rxd_gpio_in_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_RXD_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline u8 io_ctrl_rxd_gpio_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_RXD_ADDR);

	return (u8)((local_val & ((u32)0x00001000)) >> 12);
}

static inline void io_ctrl_rxd_gpio_out_setf(struct cl_chip *chip, u8 gpioout)
{
	ASSERT_ERR_CHIP((((u32)gpioout << 12) & ~((u32)0x00001000)) == 0);
	cl_reg_write(chip, IO_CTRL_RXD_ADDR, (cl_reg_read(chip, IO_CTRL_RXD_ADDR) & ~((u32)0x00001000)) | ((u32)gpioout << 12));
}

static inline u8 io_ctrl_rxd_gpio_oe_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_RXD_ADDR);

	return (u8)((local_val & ((u32)0x00000800)) >> 11);
}

static inline void io_ctrl_rxd_gpio_oe_setf(struct cl_chip *chip, u8 gpiooe)
{
	ASSERT_ERR_CHIP((((u32)gpiooe << 11) & ~((u32)0x00000800)) == 0);
	cl_reg_write(chip, IO_CTRL_RXD_ADDR, (cl_reg_read(chip, IO_CTRL_RXD_ADDR) & ~((u32)0x00000800)) | ((u32)gpiooe << 11));
}

static inline u8 io_ctrl_rxd_gpio_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_RXD_ADDR);

	return (u8)((local_val & ((u32)0x00000400)) >> 10);
}

static inline void io_ctrl_rxd_gpio_enable_setf(struct cl_chip *chip, u8 gpioenable)
{
	ASSERT_ERR_CHIP((((u32)gpioenable << 10) & ~((u32)0x00000400)) == 0);
	cl_reg_write(chip, IO_CTRL_RXD_ADDR, (cl_reg_read(chip, IO_CTRL_RXD_ADDR) & ~((u32)0x00000400)) | ((u32)gpioenable << 10));
}

static inline u8 io_ctrl_rxd_input_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_RXD_ADDR);

	return (u8)((local_val & ((u32)0x00000200)) >> 9);
}

static inline void io_ctrl_rxd_input_enable_setf(struct cl_chip *chip, u8 inputenable)
{
	ASSERT_ERR_CHIP((((u32)inputenable << 9) & ~((u32)0x00000200)) == 0);
	cl_reg_write(chip, IO_CTRL_RXD_ADDR, (cl_reg_read(chip, IO_CTRL_RXD_ADDR) & ~((u32)0x00000200)) | ((u32)inputenable << 9));
}

static inline u8 io_ctrl_rxd_driver_pull_state_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_RXD_ADDR);

	return (u8)((local_val & ((u32)0x000000C0)) >> 6);
}

static inline void io_ctrl_rxd_driver_pull_state_setf(struct cl_chip *chip, u8 driverpullstate)
{
	ASSERT_ERR_CHIP((((u32)driverpullstate << 6) & ~((u32)0x000000C0)) == 0);
	cl_reg_write(chip, IO_CTRL_RXD_ADDR, (cl_reg_read(chip, IO_CTRL_RXD_ADDR) & ~((u32)0x000000C0)) | ((u32)driverpullstate << 6));
}

static inline u8 io_ctrl_rxd_output_pad_strength_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_RXD_ADDR);

	return (u8)((local_val & ((u32)0x00000038)) >> 3);
}

static inline void io_ctrl_rxd_output_pad_strength_setf(struct cl_chip *chip, u8 outputpadstrength)
{
	ASSERT_ERR_CHIP((((u32)outputpadstrength << 3) & ~((u32)0x00000038)) == 0);
	cl_reg_write(chip, IO_CTRL_RXD_ADDR, (cl_reg_read(chip, IO_CTRL_RXD_ADDR) & ~((u32)0x00000038)) | ((u32)outputpadstrength << 3));
}

static inline u8 io_ctrl_rxd_mux_select_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_RXD_ADDR);

	return (u8)((local_val & ((u32)0x00000007)) >> 0);
}

static inline void io_ctrl_rxd_mux_select_setf(struct cl_chip *chip, u8 muxselect)
{
	ASSERT_ERR_CHIP((((u32)muxselect << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_RXD_ADDR, (cl_reg_read(chip, IO_CTRL_RXD_ADDR) & ~((u32)0x00000007)) | ((u32)muxselect << 0));
}

/**
 * @brief GPIO_20 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    13    GPIO_IN                   0
 *    12    GPIO_OUT                  0
 *    11    GPIO_OE                   0
 *    10    GPIO_ENABLE               1
 *    09    input_enable              1
 *    07:06 DRIVER_PULL_STATE         0x1
 *    05:03 OUTPUT_PAD_STRENGTH       0x2
 *    02:00 MUX_SELECT                0x0
 * </pre>
 */
#define IO_CTRL_GPIO_20_ADDR        (REG_IO_CTRL_BASE_ADDR + 0x0000004C)
#define IO_CTRL_GPIO_20_OFFSET      0x0000004C
#define IO_CTRL_GPIO_20_INDEX       0x00000013
#define IO_CTRL_GPIO_20_RESET       0x000001A8

static inline u32 io_ctrl_gpio_20_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, IO_CTRL_GPIO_20_ADDR);
}

static inline void io_ctrl_gpio_20_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, IO_CTRL_GPIO_20_ADDR, value);
}

/* Field definitions */
#define IO_CTRL_GPIO_20_GPIO_IN_BIT         ((u32)0x00002000)
#define IO_CTRL_GPIO_20_GPIO_IN_POS         13
#define IO_CTRL_GPIO_20_GPIO_OUT_BIT        ((u32)0x00001000)
#define IO_CTRL_GPIO_20_GPIO_OUT_POS        12
#define IO_CTRL_GPIO_20_GPIO_OE_BIT         ((u32)0x00000800)
#define IO_CTRL_GPIO_20_GPIO_OE_POS         11
#define IO_CTRL_GPIO_20_GPIO_ENABLE_BIT     ((u32)0x00000400)
#define IO_CTRL_GPIO_20_GPIO_ENABLE_POS     10
#define IO_CTRL_GPIO_20_INPUT_ENABLE_BIT    ((u32)0x00000200)
#define IO_CTRL_GPIO_20_INPUT_ENABLE_POS    9
#define IO_CTRL_GPIO_20_DRIVER_PULL_STATE_MASK    ((u32)0x000000C0)
#define IO_CTRL_GPIO_20_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_GPIO_20_DRIVER_PULL_STATE_WIDTH    ((u32)0x00000002)
#define IO_CTRL_GPIO_20_OUTPUT_PAD_STRENGTH_MASK    ((u32)0x00000038)
#define IO_CTRL_GPIO_20_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_GPIO_20_OUTPUT_PAD_STRENGTH_WIDTH    ((u32)0x00000003)
#define IO_CTRL_GPIO_20_MUX_SELECT_MASK     ((u32)0x00000007)
#define IO_CTRL_GPIO_20_MUX_SELECT_LSB      0
#define IO_CTRL_GPIO_20_MUX_SELECT_WIDTH    ((u32)0x00000003)

#define IO_CTRL_GPIO_20_GPIO_IN_RST         0x0
#define IO_CTRL_GPIO_20_GPIO_OUT_RST        0x0
#define IO_CTRL_GPIO_20_GPIO_OE_RST         0x0
#define IO_CTRL_GPIO_20_GPIO_ENABLE_RST     0x1
#define IO_CTRL_GPIO_20_INPUT_ENABLE_RST    0x1
#define IO_CTRL_GPIO_20_DRIVER_PULL_STATE_RST    0x1
#define IO_CTRL_GPIO_20_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_GPIO_20_MUX_SELECT_RST      0x0

static inline void io_ctrl_gpio_20_pack(struct cl_chip *chip, u8 gpio_in, u8 gpio_out, u8 gpio_oe, u8 gpio_enable, u8 input_enable, u8 driver_pull_state, u8 output_pad_strength, u8 mux_select)
{
	ASSERT_ERR_CHIP((((u32)gpio_in << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_out << 12) & ~((u32)0x00001000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_oe << 11) & ~((u32)0x00000800)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_enable << 10) & ~((u32)0x00000400)) == 0);
	ASSERT_ERR_CHIP((((u32)input_enable << 9) & ~((u32)0x00000200)) == 0);
	ASSERT_ERR_CHIP((((u32)driver_pull_state << 6) & ~((u32)0x000000C0)) == 0);
	ASSERT_ERR_CHIP((((u32)output_pad_strength << 3) & ~((u32)0x00000038)) == 0);
	ASSERT_ERR_CHIP((((u32)mux_select << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_GPIO_20_ADDR,  ((u32)gpio_in << 13) | ((u32)gpio_out << 12) | ((u32)gpio_oe << 11) | ((u32)gpio_enable << 10) | ((u32)input_enable << 9) | ((u32)driver_pull_state << 6) | ((u32)output_pad_strength << 3) | ((u32)mux_select << 0));
}

static inline void io_ctrl_gpio_20_unpack(struct cl_chip *chip, u8 *gpio_in, u8 *gpio_out, u8 *gpio_oe, u8 *gpio_enable, u8 *input_enable, u8 *driver_pull_state, u8 *output_pad_strength, u8 *mux_select)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_GPIO_20_ADDR);

	*gpio_in = (local_val & ((u32)0x00002000)) >> 13;
	*gpio_out = (local_val & ((u32)0x00001000)) >> 12;
	*gpio_oe = (local_val & ((u32)0x00000800)) >> 11;
	*gpio_enable = (local_val & ((u32)0x00000400)) >> 10;
	*input_enable = (local_val & ((u32)0x00000200)) >> 9;
	*driver_pull_state = (local_val & ((u32)0x000000C0)) >> 6;
	*output_pad_strength = (local_val & ((u32)0x00000038)) >> 3;
	*mux_select = (local_val & ((u32)0x00000007)) >> 0;
}

static inline u8 io_ctrl_gpio_20_gpio_in_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_GPIO_20_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline u8 io_ctrl_gpio_20_gpio_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_GPIO_20_ADDR);

	return (u8)((local_val & ((u32)0x00001000)) >> 12);
}

static inline void io_ctrl_gpio_20_gpio_out_setf(struct cl_chip *chip, u8 gpioout)
{
	ASSERT_ERR_CHIP((((u32)gpioout << 12) & ~((u32)0x00001000)) == 0);
	cl_reg_write(chip, IO_CTRL_GPIO_20_ADDR, (cl_reg_read(chip, IO_CTRL_GPIO_20_ADDR) & ~((u32)0x00001000)) | ((u32)gpioout << 12));
}

static inline u8 io_ctrl_gpio_20_gpio_oe_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_GPIO_20_ADDR);

	return (u8)((local_val & ((u32)0x00000800)) >> 11);
}

static inline void io_ctrl_gpio_20_gpio_oe_setf(struct cl_chip *chip, u8 gpiooe)
{
	ASSERT_ERR_CHIP((((u32)gpiooe << 11) & ~((u32)0x00000800)) == 0);
	cl_reg_write(chip, IO_CTRL_GPIO_20_ADDR, (cl_reg_read(chip, IO_CTRL_GPIO_20_ADDR) & ~((u32)0x00000800)) | ((u32)gpiooe << 11));
}

static inline u8 io_ctrl_gpio_20_gpio_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_GPIO_20_ADDR);

	return (u8)((local_val & ((u32)0x00000400)) >> 10);
}

static inline void io_ctrl_gpio_20_gpio_enable_setf(struct cl_chip *chip, u8 gpioenable)
{
	ASSERT_ERR_CHIP((((u32)gpioenable << 10) & ~((u32)0x00000400)) == 0);
	cl_reg_write(chip, IO_CTRL_GPIO_20_ADDR, (cl_reg_read(chip, IO_CTRL_GPIO_20_ADDR) & ~((u32)0x00000400)) | ((u32)gpioenable << 10));
}

static inline u8 io_ctrl_gpio_20_input_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_GPIO_20_ADDR);

	return (u8)((local_val & ((u32)0x00000200)) >> 9);
}

static inline void io_ctrl_gpio_20_input_enable_setf(struct cl_chip *chip, u8 inputenable)
{
	ASSERT_ERR_CHIP((((u32)inputenable << 9) & ~((u32)0x00000200)) == 0);
	cl_reg_write(chip, IO_CTRL_GPIO_20_ADDR, (cl_reg_read(chip, IO_CTRL_GPIO_20_ADDR) & ~((u32)0x00000200)) | ((u32)inputenable << 9));
}

static inline u8 io_ctrl_gpio_20_driver_pull_state_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_GPIO_20_ADDR);

	return (u8)((local_val & ((u32)0x000000C0)) >> 6);
}

static inline void io_ctrl_gpio_20_driver_pull_state_setf(struct cl_chip *chip, u8 driverpullstate)
{
	ASSERT_ERR_CHIP((((u32)driverpullstate << 6) & ~((u32)0x000000C0)) == 0);
	cl_reg_write(chip, IO_CTRL_GPIO_20_ADDR, (cl_reg_read(chip, IO_CTRL_GPIO_20_ADDR) & ~((u32)0x000000C0)) | ((u32)driverpullstate << 6));
}

static inline u8 io_ctrl_gpio_20_output_pad_strength_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_GPIO_20_ADDR);

	return (u8)((local_val & ((u32)0x00000038)) >> 3);
}

static inline void io_ctrl_gpio_20_output_pad_strength_setf(struct cl_chip *chip, u8 outputpadstrength)
{
	ASSERT_ERR_CHIP((((u32)outputpadstrength << 3) & ~((u32)0x00000038)) == 0);
	cl_reg_write(chip, IO_CTRL_GPIO_20_ADDR, (cl_reg_read(chip, IO_CTRL_GPIO_20_ADDR) & ~((u32)0x00000038)) | ((u32)outputpadstrength << 3));
}

static inline u8 io_ctrl_gpio_20_mux_select_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_GPIO_20_ADDR);

	return (u8)((local_val & ((u32)0x00000007)) >> 0);
}

static inline void io_ctrl_gpio_20_mux_select_setf(struct cl_chip *chip, u8 muxselect)
{
	ASSERT_ERR_CHIP((((u32)muxselect << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_GPIO_20_ADDR, (cl_reg_read(chip, IO_CTRL_GPIO_20_ADDR) & ~((u32)0x00000007)) | ((u32)muxselect << 0));
}

/**
 * @brief ANT_SEL_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    13    GPIO_IN                   0
 *    12    GPIO_OUT                  0
 *    11    GPIO_OE                   0
 *    10    GPIO_ENABLE               1
 *    09    input_enable              1
 *    07:06 DRIVER_PULL_STATE         0x1
 *    05:03 OUTPUT_PAD_STRENGTH       0x2
 *    02:00 MUX_SELECT                0x0
 * </pre>
 */
#define IO_CTRL_ANT_SEL_1_ADDR        (REG_IO_CTRL_BASE_ADDR + 0x00000050)
#define IO_CTRL_ANT_SEL_1_OFFSET      0x00000050
#define IO_CTRL_ANT_SEL_1_INDEX       0x00000014
#define IO_CTRL_ANT_SEL_1_RESET       0x000001A8

static inline u32 io_ctrl_ant_sel_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, IO_CTRL_ANT_SEL_1_ADDR);
}

static inline void io_ctrl_ant_sel_1_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, IO_CTRL_ANT_SEL_1_ADDR, value);
}

/* Field definitions */
#define IO_CTRL_ANT_SEL_1_GPIO_IN_BIT       ((u32)0x00002000)
#define IO_CTRL_ANT_SEL_1_GPIO_IN_POS       13
#define IO_CTRL_ANT_SEL_1_GPIO_OUT_BIT      ((u32)0x00001000)
#define IO_CTRL_ANT_SEL_1_GPIO_OUT_POS      12
#define IO_CTRL_ANT_SEL_1_GPIO_OE_BIT       ((u32)0x00000800)
#define IO_CTRL_ANT_SEL_1_GPIO_OE_POS       11
#define IO_CTRL_ANT_SEL_1_GPIO_ENABLE_BIT    ((u32)0x00000400)
#define IO_CTRL_ANT_SEL_1_GPIO_ENABLE_POS    10
#define IO_CTRL_ANT_SEL_1_INPUT_ENABLE_BIT    ((u32)0x00000200)
#define IO_CTRL_ANT_SEL_1_INPUT_ENABLE_POS    9
#define IO_CTRL_ANT_SEL_1_DRIVER_PULL_STATE_MASK    ((u32)0x000000C0)
#define IO_CTRL_ANT_SEL_1_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_ANT_SEL_1_DRIVER_PULL_STATE_WIDTH    ((u32)0x00000002)
#define IO_CTRL_ANT_SEL_1_OUTPUT_PAD_STRENGTH_MASK    ((u32)0x00000038)
#define IO_CTRL_ANT_SEL_1_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_ANT_SEL_1_OUTPUT_PAD_STRENGTH_WIDTH    ((u32)0x00000003)
#define IO_CTRL_ANT_SEL_1_MUX_SELECT_MASK    ((u32)0x00000007)
#define IO_CTRL_ANT_SEL_1_MUX_SELECT_LSB    0
#define IO_CTRL_ANT_SEL_1_MUX_SELECT_WIDTH    ((u32)0x00000003)

#define IO_CTRL_ANT_SEL_1_GPIO_IN_RST       0x0
#define IO_CTRL_ANT_SEL_1_GPIO_OUT_RST      0x0
#define IO_CTRL_ANT_SEL_1_GPIO_OE_RST       0x0
#define IO_CTRL_ANT_SEL_1_GPIO_ENABLE_RST    0x1
#define IO_CTRL_ANT_SEL_1_INPUT_ENABLE_RST    0x1
#define IO_CTRL_ANT_SEL_1_DRIVER_PULL_STATE_RST    0x1
#define IO_CTRL_ANT_SEL_1_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_ANT_SEL_1_MUX_SELECT_RST    0x0

static inline void io_ctrl_ant_sel_1_pack(struct cl_chip *chip, u8 gpio_in, u8 gpio_out, u8 gpio_oe, u8 gpio_enable, u8 input_enable, u8 driver_pull_state, u8 output_pad_strength, u8 mux_select)
{
	ASSERT_ERR_CHIP((((u32)gpio_in << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_out << 12) & ~((u32)0x00001000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_oe << 11) & ~((u32)0x00000800)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_enable << 10) & ~((u32)0x00000400)) == 0);
	ASSERT_ERR_CHIP((((u32)input_enable << 9) & ~((u32)0x00000200)) == 0);
	ASSERT_ERR_CHIP((((u32)driver_pull_state << 6) & ~((u32)0x000000C0)) == 0);
	ASSERT_ERR_CHIP((((u32)output_pad_strength << 3) & ~((u32)0x00000038)) == 0);
	ASSERT_ERR_CHIP((((u32)mux_select << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_ANT_SEL_1_ADDR,  ((u32)gpio_in << 13) | ((u32)gpio_out << 12) | ((u32)gpio_oe << 11) | ((u32)gpio_enable << 10) | ((u32)input_enable << 9) | ((u32)driver_pull_state << 6) | ((u32)output_pad_strength << 3) | ((u32)mux_select << 0));
}

static inline void io_ctrl_ant_sel_1_unpack(struct cl_chip *chip, u8 *gpio_in, u8 *gpio_out, u8 *gpio_oe, u8 *gpio_enable, u8 *input_enable, u8 *driver_pull_state, u8 *output_pad_strength, u8 *mux_select)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_ANT_SEL_1_ADDR);

	*gpio_in = (local_val & ((u32)0x00002000)) >> 13;
	*gpio_out = (local_val & ((u32)0x00001000)) >> 12;
	*gpio_oe = (local_val & ((u32)0x00000800)) >> 11;
	*gpio_enable = (local_val & ((u32)0x00000400)) >> 10;
	*input_enable = (local_val & ((u32)0x00000200)) >> 9;
	*driver_pull_state = (local_val & ((u32)0x000000C0)) >> 6;
	*output_pad_strength = (local_val & ((u32)0x00000038)) >> 3;
	*mux_select = (local_val & ((u32)0x00000007)) >> 0;
}

static inline u8 io_ctrl_ant_sel_1_gpio_in_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_ANT_SEL_1_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline u8 io_ctrl_ant_sel_1_gpio_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_ANT_SEL_1_ADDR);

	return (u8)((local_val & ((u32)0x00001000)) >> 12);
}

static inline void io_ctrl_ant_sel_1_gpio_out_setf(struct cl_chip *chip, u8 gpioout)
{
	ASSERT_ERR_CHIP((((u32)gpioout << 12) & ~((u32)0x00001000)) == 0);
	cl_reg_write(chip, IO_CTRL_ANT_SEL_1_ADDR, (cl_reg_read(chip, IO_CTRL_ANT_SEL_1_ADDR) & ~((u32)0x00001000)) | ((u32)gpioout << 12));
}

static inline u8 io_ctrl_ant_sel_1_gpio_oe_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_ANT_SEL_1_ADDR);

	return (u8)((local_val & ((u32)0x00000800)) >> 11);
}

static inline void io_ctrl_ant_sel_1_gpio_oe_setf(struct cl_chip *chip, u8 gpiooe)
{
	ASSERT_ERR_CHIP((((u32)gpiooe << 11) & ~((u32)0x00000800)) == 0);
	cl_reg_write(chip, IO_CTRL_ANT_SEL_1_ADDR, (cl_reg_read(chip, IO_CTRL_ANT_SEL_1_ADDR) & ~((u32)0x00000800)) | ((u32)gpiooe << 11));
}

static inline u8 io_ctrl_ant_sel_1_gpio_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_ANT_SEL_1_ADDR);

	return (u8)((local_val & ((u32)0x00000400)) >> 10);
}

static inline void io_ctrl_ant_sel_1_gpio_enable_setf(struct cl_chip *chip, u8 gpioenable)
{
	ASSERT_ERR_CHIP((((u32)gpioenable << 10) & ~((u32)0x00000400)) == 0);
	cl_reg_write(chip, IO_CTRL_ANT_SEL_1_ADDR, (cl_reg_read(chip, IO_CTRL_ANT_SEL_1_ADDR) & ~((u32)0x00000400)) | ((u32)gpioenable << 10));
}

static inline u8 io_ctrl_ant_sel_1_input_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_ANT_SEL_1_ADDR);

	return (u8)((local_val & ((u32)0x00000200)) >> 9);
}

static inline void io_ctrl_ant_sel_1_input_enable_setf(struct cl_chip *chip, u8 inputenable)
{
	ASSERT_ERR_CHIP((((u32)inputenable << 9) & ~((u32)0x00000200)) == 0);
	cl_reg_write(chip, IO_CTRL_ANT_SEL_1_ADDR, (cl_reg_read(chip, IO_CTRL_ANT_SEL_1_ADDR) & ~((u32)0x00000200)) | ((u32)inputenable << 9));
}

static inline u8 io_ctrl_ant_sel_1_driver_pull_state_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_ANT_SEL_1_ADDR);

	return (u8)((local_val & ((u32)0x000000C0)) >> 6);
}

static inline void io_ctrl_ant_sel_1_driver_pull_state_setf(struct cl_chip *chip, u8 driverpullstate)
{
	ASSERT_ERR_CHIP((((u32)driverpullstate << 6) & ~((u32)0x000000C0)) == 0);
	cl_reg_write(chip, IO_CTRL_ANT_SEL_1_ADDR, (cl_reg_read(chip, IO_CTRL_ANT_SEL_1_ADDR) & ~((u32)0x000000C0)) | ((u32)driverpullstate << 6));
}

static inline u8 io_ctrl_ant_sel_1_output_pad_strength_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_ANT_SEL_1_ADDR);

	return (u8)((local_val & ((u32)0x00000038)) >> 3);
}

static inline void io_ctrl_ant_sel_1_output_pad_strength_setf(struct cl_chip *chip, u8 outputpadstrength)
{
	ASSERT_ERR_CHIP((((u32)outputpadstrength << 3) & ~((u32)0x00000038)) == 0);
	cl_reg_write(chip, IO_CTRL_ANT_SEL_1_ADDR, (cl_reg_read(chip, IO_CTRL_ANT_SEL_1_ADDR) & ~((u32)0x00000038)) | ((u32)outputpadstrength << 3));
}

static inline u8 io_ctrl_ant_sel_1_mux_select_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_ANT_SEL_1_ADDR);

	return (u8)((local_val & ((u32)0x00000007)) >> 0);
}

static inline void io_ctrl_ant_sel_1_mux_select_setf(struct cl_chip *chip, u8 muxselect)
{
	ASSERT_ERR_CHIP((((u32)muxselect << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_ANT_SEL_1_ADDR, (cl_reg_read(chip, IO_CTRL_ANT_SEL_1_ADDR) & ~((u32)0x00000007)) | ((u32)muxselect << 0));
}

/**
 * @brief ANT_SEL_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    13    GPIO_IN                   1
 *    12    GPIO_OUT                  0
 *    11    GPIO_OE                   0
 *    10    GPIO_ENABLE               1
 *    09    input_enable              1
 *    07:06 DRIVER_PULL_STATE         0x2
 *    05:03 OUTPUT_PAD_STRENGTH       0x2
 *    02:00 MUX_SELECT                0x0
 * </pre>
 */
#define IO_CTRL_ANT_SEL_2_ADDR        (REG_IO_CTRL_BASE_ADDR + 0x00000054)
#define IO_CTRL_ANT_SEL_2_OFFSET      0x00000054
#define IO_CTRL_ANT_SEL_2_INDEX       0x00000015
#define IO_CTRL_ANT_SEL_2_RESET       0x000009C8

static inline u32 io_ctrl_ant_sel_2_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, IO_CTRL_ANT_SEL_2_ADDR);
}

static inline void io_ctrl_ant_sel_2_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, IO_CTRL_ANT_SEL_2_ADDR, value);
}

/* Field definitions */
#define IO_CTRL_ANT_SEL_2_GPIO_IN_BIT       ((u32)0x00002000)
#define IO_CTRL_ANT_SEL_2_GPIO_IN_POS       13
#define IO_CTRL_ANT_SEL_2_GPIO_OUT_BIT      ((u32)0x00001000)
#define IO_CTRL_ANT_SEL_2_GPIO_OUT_POS      12
#define IO_CTRL_ANT_SEL_2_GPIO_OE_BIT       ((u32)0x00000800)
#define IO_CTRL_ANT_SEL_2_GPIO_OE_POS       11
#define IO_CTRL_ANT_SEL_2_GPIO_ENABLE_BIT    ((u32)0x00000400)
#define IO_CTRL_ANT_SEL_2_GPIO_ENABLE_POS    10
#define IO_CTRL_ANT_SEL_2_INPUT_ENABLE_BIT    ((u32)0x00000200)
#define IO_CTRL_ANT_SEL_2_INPUT_ENABLE_POS    9
#define IO_CTRL_ANT_SEL_2_DRIVER_PULL_STATE_MASK    ((u32)0x000000C0)
#define IO_CTRL_ANT_SEL_2_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_ANT_SEL_2_DRIVER_PULL_STATE_WIDTH    ((u32)0x00000002)
#define IO_CTRL_ANT_SEL_2_OUTPUT_PAD_STRENGTH_MASK    ((u32)0x00000038)
#define IO_CTRL_ANT_SEL_2_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_ANT_SEL_2_OUTPUT_PAD_STRENGTH_WIDTH    ((u32)0x00000003)
#define IO_CTRL_ANT_SEL_2_MUX_SELECT_MASK    ((u32)0x00000007)
#define IO_CTRL_ANT_SEL_2_MUX_SELECT_LSB    0
#define IO_CTRL_ANT_SEL_2_MUX_SELECT_WIDTH    ((u32)0x00000003)

#define IO_CTRL_ANT_SEL_2_GPIO_IN_RST       0x1
#define IO_CTRL_ANT_SEL_2_GPIO_OUT_RST      0x0
#define IO_CTRL_ANT_SEL_2_GPIO_OE_RST       0x0
#define IO_CTRL_ANT_SEL_2_GPIO_ENABLE_RST    0x1
#define IO_CTRL_ANT_SEL_2_INPUT_ENABLE_RST    0x1
#define IO_CTRL_ANT_SEL_2_DRIVER_PULL_STATE_RST    0x2
#define IO_CTRL_ANT_SEL_2_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_ANT_SEL_2_MUX_SELECT_RST    0x0

static inline void io_ctrl_ant_sel_2_pack(struct cl_chip *chip, u8 gpio_in, u8 gpio_out, u8 gpio_oe, u8 gpio_enable, u8 input_enable, u8 driver_pull_state, u8 output_pad_strength, u8 mux_select)
{
	ASSERT_ERR_CHIP((((u32)gpio_in << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_out << 12) & ~((u32)0x00001000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_oe << 11) & ~((u32)0x00000800)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_enable << 10) & ~((u32)0x00000400)) == 0);
	ASSERT_ERR_CHIP((((u32)input_enable << 9) & ~((u32)0x00000200)) == 0);
	ASSERT_ERR_CHIP((((u32)driver_pull_state << 6) & ~((u32)0x000000C0)) == 0);
	ASSERT_ERR_CHIP((((u32)output_pad_strength << 3) & ~((u32)0x00000038)) == 0);
	ASSERT_ERR_CHIP((((u32)mux_select << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_ANT_SEL_2_ADDR,  ((u32)gpio_in << 13) | ((u32)gpio_out << 12) | ((u32)gpio_oe << 11) | ((u32)gpio_enable << 10) | ((u32)input_enable << 9) | ((u32)driver_pull_state << 6) | ((u32)output_pad_strength << 3) | ((u32)mux_select << 0));
}

static inline void io_ctrl_ant_sel_2_unpack(struct cl_chip *chip, u8 *gpio_in, u8 *gpio_out, u8 *gpio_oe, u8 *gpio_enable, u8 *input_enable, u8 *driver_pull_state, u8 *output_pad_strength, u8 *mux_select)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_ANT_SEL_2_ADDR);

	*gpio_in = (local_val & ((u32)0x00002000)) >> 13;
	*gpio_out = (local_val & ((u32)0x00001000)) >> 12;
	*gpio_oe = (local_val & ((u32)0x00000800)) >> 11;
	*gpio_enable = (local_val & ((u32)0x00000400)) >> 10;
	*input_enable = (local_val & ((u32)0x00000200)) >> 9;
	*driver_pull_state = (local_val & ((u32)0x000000C0)) >> 6;
	*output_pad_strength = (local_val & ((u32)0x00000038)) >> 3;
	*mux_select = (local_val & ((u32)0x00000007)) >> 0;
}

static inline u8 io_ctrl_ant_sel_2_gpio_in_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_ANT_SEL_2_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline u8 io_ctrl_ant_sel_2_gpio_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_ANT_SEL_2_ADDR);

	return (u8)((local_val & ((u32)0x00001000)) >> 12);
}

static inline void io_ctrl_ant_sel_2_gpio_out_setf(struct cl_chip *chip, u8 gpioout)
{
	ASSERT_ERR_CHIP((((u32)gpioout << 12) & ~((u32)0x00001000)) == 0);
	cl_reg_write(chip, IO_CTRL_ANT_SEL_2_ADDR, (cl_reg_read(chip, IO_CTRL_ANT_SEL_2_ADDR) & ~((u32)0x00001000)) | ((u32)gpioout << 12));
}

static inline u8 io_ctrl_ant_sel_2_gpio_oe_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_ANT_SEL_2_ADDR);

	return (u8)((local_val & ((u32)0x00000800)) >> 11);
}

static inline void io_ctrl_ant_sel_2_gpio_oe_setf(struct cl_chip *chip, u8 gpiooe)
{
	ASSERT_ERR_CHIP((((u32)gpiooe << 11) & ~((u32)0x00000800)) == 0);
	cl_reg_write(chip, IO_CTRL_ANT_SEL_2_ADDR, (cl_reg_read(chip, IO_CTRL_ANT_SEL_2_ADDR) & ~((u32)0x00000800)) | ((u32)gpiooe << 11));
}

static inline u8 io_ctrl_ant_sel_2_gpio_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_ANT_SEL_2_ADDR);

	return (u8)((local_val & ((u32)0x00000400)) >> 10);
}

static inline void io_ctrl_ant_sel_2_gpio_enable_setf(struct cl_chip *chip, u8 gpioenable)
{
	ASSERT_ERR_CHIP((((u32)gpioenable << 10) & ~((u32)0x00000400)) == 0);
	cl_reg_write(chip, IO_CTRL_ANT_SEL_2_ADDR, (cl_reg_read(chip, IO_CTRL_ANT_SEL_2_ADDR) & ~((u32)0x00000400)) | ((u32)gpioenable << 10));
}

static inline u8 io_ctrl_ant_sel_2_input_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_ANT_SEL_2_ADDR);

	return (u8)((local_val & ((u32)0x00000200)) >> 9);
}

static inline void io_ctrl_ant_sel_2_input_enable_setf(struct cl_chip *chip, u8 inputenable)
{
	ASSERT_ERR_CHIP((((u32)inputenable << 9) & ~((u32)0x00000200)) == 0);
	cl_reg_write(chip, IO_CTRL_ANT_SEL_2_ADDR, (cl_reg_read(chip, IO_CTRL_ANT_SEL_2_ADDR) & ~((u32)0x00000200)) | ((u32)inputenable << 9));
}

static inline u8 io_ctrl_ant_sel_2_driver_pull_state_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_ANT_SEL_2_ADDR);

	return (u8)((local_val & ((u32)0x000000C0)) >> 6);
}

static inline void io_ctrl_ant_sel_2_driver_pull_state_setf(struct cl_chip *chip, u8 driverpullstate)
{
	ASSERT_ERR_CHIP((((u32)driverpullstate << 6) & ~((u32)0x000000C0)) == 0);
	cl_reg_write(chip, IO_CTRL_ANT_SEL_2_ADDR, (cl_reg_read(chip, IO_CTRL_ANT_SEL_2_ADDR) & ~((u32)0x000000C0)) | ((u32)driverpullstate << 6));
}

static inline u8 io_ctrl_ant_sel_2_output_pad_strength_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_ANT_SEL_2_ADDR);

	return (u8)((local_val & ((u32)0x00000038)) >> 3);
}

static inline void io_ctrl_ant_sel_2_output_pad_strength_setf(struct cl_chip *chip, u8 outputpadstrength)
{
	ASSERT_ERR_CHIP((((u32)outputpadstrength << 3) & ~((u32)0x00000038)) == 0);
	cl_reg_write(chip, IO_CTRL_ANT_SEL_2_ADDR, (cl_reg_read(chip, IO_CTRL_ANT_SEL_2_ADDR) & ~((u32)0x00000038)) | ((u32)outputpadstrength << 3));
}

static inline u8 io_ctrl_ant_sel_2_mux_select_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_ANT_SEL_2_ADDR);

	return (u8)((local_val & ((u32)0x00000007)) >> 0);
}

static inline void io_ctrl_ant_sel_2_mux_select_setf(struct cl_chip *chip, u8 muxselect)
{
	ASSERT_ERR_CHIP((((u32)muxselect << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_ANT_SEL_2_ADDR, (cl_reg_read(chip, IO_CTRL_ANT_SEL_2_ADDR) & ~((u32)0x00000007)) | ((u32)muxselect << 0));
}

/**
 * @brief ANT_SEL_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    13    GPIO_IN                   1
 *    12    GPIO_OUT                  0
 *    11    GPIO_OE                   0
 *    10    GPIO_ENABLE               1
 *    09    input_enable              1
 *    07:06 DRIVER_PULL_STATE         0x2
 *    05:03 OUTPUT_PAD_STRENGTH       0x2
 *    02:00 MUX_SELECT                0x0
 * </pre>
 */
#define IO_CTRL_ANT_SEL_3_ADDR        (REG_IO_CTRL_BASE_ADDR + 0x00000058)
#define IO_CTRL_ANT_SEL_3_OFFSET      0x00000058
#define IO_CTRL_ANT_SEL_3_INDEX       0x00000016
#define IO_CTRL_ANT_SEL_3_RESET       0x000009C8

static inline u32 io_ctrl_ant_sel_3_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, IO_CTRL_ANT_SEL_3_ADDR);
}

static inline void io_ctrl_ant_sel_3_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, IO_CTRL_ANT_SEL_3_ADDR, value);
}

/* Field definitions */
#define IO_CTRL_ANT_SEL_3_GPIO_IN_BIT       ((u32)0x00002000)
#define IO_CTRL_ANT_SEL_3_GPIO_IN_POS       13
#define IO_CTRL_ANT_SEL_3_GPIO_OUT_BIT      ((u32)0x00001000)
#define IO_CTRL_ANT_SEL_3_GPIO_OUT_POS      12
#define IO_CTRL_ANT_SEL_3_GPIO_OE_BIT       ((u32)0x00000800)
#define IO_CTRL_ANT_SEL_3_GPIO_OE_POS       11
#define IO_CTRL_ANT_SEL_3_GPIO_ENABLE_BIT    ((u32)0x00000400)
#define IO_CTRL_ANT_SEL_3_GPIO_ENABLE_POS    10
#define IO_CTRL_ANT_SEL_3_INPUT_ENABLE_BIT    ((u32)0x00000200)
#define IO_CTRL_ANT_SEL_3_INPUT_ENABLE_POS    9
#define IO_CTRL_ANT_SEL_3_DRIVER_PULL_STATE_MASK    ((u32)0x000000C0)
#define IO_CTRL_ANT_SEL_3_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_ANT_SEL_3_DRIVER_PULL_STATE_WIDTH    ((u32)0x00000002)
#define IO_CTRL_ANT_SEL_3_OUTPUT_PAD_STRENGTH_MASK    ((u32)0x00000038)
#define IO_CTRL_ANT_SEL_3_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_ANT_SEL_3_OUTPUT_PAD_STRENGTH_WIDTH    ((u32)0x00000003)
#define IO_CTRL_ANT_SEL_3_MUX_SELECT_MASK    ((u32)0x00000007)
#define IO_CTRL_ANT_SEL_3_MUX_SELECT_LSB    0
#define IO_CTRL_ANT_SEL_3_MUX_SELECT_WIDTH    ((u32)0x00000003)

#define IO_CTRL_ANT_SEL_3_GPIO_IN_RST       0x1
#define IO_CTRL_ANT_SEL_3_GPIO_OUT_RST      0x0
#define IO_CTRL_ANT_SEL_3_GPIO_OE_RST       0x0
#define IO_CTRL_ANT_SEL_3_GPIO_ENABLE_RST    0x1
#define IO_CTRL_ANT_SEL_3_INPUT_ENABLE_RST    0x1
#define IO_CTRL_ANT_SEL_3_DRIVER_PULL_STATE_RST    0x2
#define IO_CTRL_ANT_SEL_3_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_ANT_SEL_3_MUX_SELECT_RST    0x0

static inline void io_ctrl_ant_sel_3_pack(struct cl_chip *chip, u8 gpio_in, u8 gpio_out, u8 gpio_oe, u8 gpio_enable, u8 input_enable, u8 driver_pull_state, u8 output_pad_strength, u8 mux_select)
{
	ASSERT_ERR_CHIP((((u32)gpio_in << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_out << 12) & ~((u32)0x00001000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_oe << 11) & ~((u32)0x00000800)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_enable << 10) & ~((u32)0x00000400)) == 0);
	ASSERT_ERR_CHIP((((u32)input_enable << 9) & ~((u32)0x00000200)) == 0);
	ASSERT_ERR_CHIP((((u32)driver_pull_state << 6) & ~((u32)0x000000C0)) == 0);
	ASSERT_ERR_CHIP((((u32)output_pad_strength << 3) & ~((u32)0x00000038)) == 0);
	ASSERT_ERR_CHIP((((u32)mux_select << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_ANT_SEL_3_ADDR,  ((u32)gpio_in << 13) | ((u32)gpio_out << 12) | ((u32)gpio_oe << 11) | ((u32)gpio_enable << 10) | ((u32)input_enable << 9) | ((u32)driver_pull_state << 6) | ((u32)output_pad_strength << 3) | ((u32)mux_select << 0));
}

static inline void io_ctrl_ant_sel_3_unpack(struct cl_chip *chip, u8 *gpio_in, u8 *gpio_out, u8 *gpio_oe, u8 *gpio_enable, u8 *input_enable, u8 *driver_pull_state, u8 *output_pad_strength, u8 *mux_select)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_ANT_SEL_3_ADDR);

	*gpio_in = (local_val & ((u32)0x00002000)) >> 13;
	*gpio_out = (local_val & ((u32)0x00001000)) >> 12;
	*gpio_oe = (local_val & ((u32)0x00000800)) >> 11;
	*gpio_enable = (local_val & ((u32)0x00000400)) >> 10;
	*input_enable = (local_val & ((u32)0x00000200)) >> 9;
	*driver_pull_state = (local_val & ((u32)0x000000C0)) >> 6;
	*output_pad_strength = (local_val & ((u32)0x00000038)) >> 3;
	*mux_select = (local_val & ((u32)0x00000007)) >> 0;
}

static inline u8 io_ctrl_ant_sel_3_gpio_in_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_ANT_SEL_3_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline u8 io_ctrl_ant_sel_3_gpio_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_ANT_SEL_3_ADDR);

	return (u8)((local_val & ((u32)0x00001000)) >> 12);
}

static inline void io_ctrl_ant_sel_3_gpio_out_setf(struct cl_chip *chip, u8 gpioout)
{
	ASSERT_ERR_CHIP((((u32)gpioout << 12) & ~((u32)0x00001000)) == 0);
	cl_reg_write(chip, IO_CTRL_ANT_SEL_3_ADDR, (cl_reg_read(chip, IO_CTRL_ANT_SEL_3_ADDR) & ~((u32)0x00001000)) | ((u32)gpioout << 12));
}

static inline u8 io_ctrl_ant_sel_3_gpio_oe_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_ANT_SEL_3_ADDR);

	return (u8)((local_val & ((u32)0x00000800)) >> 11);
}

static inline void io_ctrl_ant_sel_3_gpio_oe_setf(struct cl_chip *chip, u8 gpiooe)
{
	ASSERT_ERR_CHIP((((u32)gpiooe << 11) & ~((u32)0x00000800)) == 0);
	cl_reg_write(chip, IO_CTRL_ANT_SEL_3_ADDR, (cl_reg_read(chip, IO_CTRL_ANT_SEL_3_ADDR) & ~((u32)0x00000800)) | ((u32)gpiooe << 11));
}

static inline u8 io_ctrl_ant_sel_3_gpio_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_ANT_SEL_3_ADDR);

	return (u8)((local_val & ((u32)0x00000400)) >> 10);
}

static inline void io_ctrl_ant_sel_3_gpio_enable_setf(struct cl_chip *chip, u8 gpioenable)
{
	ASSERT_ERR_CHIP((((u32)gpioenable << 10) & ~((u32)0x00000400)) == 0);
	cl_reg_write(chip, IO_CTRL_ANT_SEL_3_ADDR, (cl_reg_read(chip, IO_CTRL_ANT_SEL_3_ADDR) & ~((u32)0x00000400)) | ((u32)gpioenable << 10));
}

static inline u8 io_ctrl_ant_sel_3_input_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_ANT_SEL_3_ADDR);

	return (u8)((local_val & ((u32)0x00000200)) >> 9);
}

static inline void io_ctrl_ant_sel_3_input_enable_setf(struct cl_chip *chip, u8 inputenable)
{
	ASSERT_ERR_CHIP((((u32)inputenable << 9) & ~((u32)0x00000200)) == 0);
	cl_reg_write(chip, IO_CTRL_ANT_SEL_3_ADDR, (cl_reg_read(chip, IO_CTRL_ANT_SEL_3_ADDR) & ~((u32)0x00000200)) | ((u32)inputenable << 9));
}

static inline u8 io_ctrl_ant_sel_3_driver_pull_state_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_ANT_SEL_3_ADDR);

	return (u8)((local_val & ((u32)0x000000C0)) >> 6);
}

static inline void io_ctrl_ant_sel_3_driver_pull_state_setf(struct cl_chip *chip, u8 driverpullstate)
{
	ASSERT_ERR_CHIP((((u32)driverpullstate << 6) & ~((u32)0x000000C0)) == 0);
	cl_reg_write(chip, IO_CTRL_ANT_SEL_3_ADDR, (cl_reg_read(chip, IO_CTRL_ANT_SEL_3_ADDR) & ~((u32)0x000000C0)) | ((u32)driverpullstate << 6));
}

static inline u8 io_ctrl_ant_sel_3_output_pad_strength_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_ANT_SEL_3_ADDR);

	return (u8)((local_val & ((u32)0x00000038)) >> 3);
}

static inline void io_ctrl_ant_sel_3_output_pad_strength_setf(struct cl_chip *chip, u8 outputpadstrength)
{
	ASSERT_ERR_CHIP((((u32)outputpadstrength << 3) & ~((u32)0x00000038)) == 0);
	cl_reg_write(chip, IO_CTRL_ANT_SEL_3_ADDR, (cl_reg_read(chip, IO_CTRL_ANT_SEL_3_ADDR) & ~((u32)0x00000038)) | ((u32)outputpadstrength << 3));
}

static inline u8 io_ctrl_ant_sel_3_mux_select_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_ANT_SEL_3_ADDR);

	return (u8)((local_val & ((u32)0x00000007)) >> 0);
}

static inline void io_ctrl_ant_sel_3_mux_select_setf(struct cl_chip *chip, u8 muxselect)
{
	ASSERT_ERR_CHIP((((u32)muxselect << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_ANT_SEL_3_ADDR, (cl_reg_read(chip, IO_CTRL_ANT_SEL_3_ADDR) & ~((u32)0x00000007)) | ((u32)muxselect << 0));
}

/**
 * @brief GPIO_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    14    HOST_INTERFACE            1
 *    13    GPIO_IN                   1
 *    12    GPIO_OUT                  0
 *    11    GPIO_OE                   0
 *    10    GPIO_ENABLE               1
 *    09    input_enable              1
 *    07:06 DRIVER_PULL_STATE         0x2
 *    05:03 OUTPUT_PAD_STRENGTH       0x2
 *    02:00 MUX_SELECT                0x0
 * </pre>
 */
#define IO_CTRL_GPIO_2_ADDR        (REG_IO_CTRL_BASE_ADDR + 0x0000005C)
#define IO_CTRL_GPIO_2_OFFSET      0x0000005C
#define IO_CTRL_GPIO_2_INDEX       0x00000017
#define IO_CTRL_GPIO_2_RESET       0x000019C8

static inline u32 io_ctrl_gpio_2_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, IO_CTRL_GPIO_2_ADDR);
}

static inline void io_ctrl_gpio_2_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, IO_CTRL_GPIO_2_ADDR, value);
}

/* Field definitions */
#define IO_CTRL_GPIO_2_HOST_INTERFACE_BIT    ((u32)0x00004000)
#define IO_CTRL_GPIO_2_HOST_INTERFACE_POS    14
#define IO_CTRL_GPIO_2_GPIO_IN_BIT          ((u32)0x00002000)
#define IO_CTRL_GPIO_2_GPIO_IN_POS          13
#define IO_CTRL_GPIO_2_GPIO_OUT_BIT         ((u32)0x00001000)
#define IO_CTRL_GPIO_2_GPIO_OUT_POS         12
#define IO_CTRL_GPIO_2_GPIO_OE_BIT          ((u32)0x00000800)
#define IO_CTRL_GPIO_2_GPIO_OE_POS          11
#define IO_CTRL_GPIO_2_GPIO_ENABLE_BIT      ((u32)0x00000400)
#define IO_CTRL_GPIO_2_GPIO_ENABLE_POS      10
#define IO_CTRL_GPIO_2_INPUT_ENABLE_BIT     ((u32)0x00000200)
#define IO_CTRL_GPIO_2_INPUT_ENABLE_POS     9
#define IO_CTRL_GPIO_2_DRIVER_PULL_STATE_MASK    ((u32)0x000000C0)
#define IO_CTRL_GPIO_2_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_GPIO_2_DRIVER_PULL_STATE_WIDTH    ((u32)0x00000002)
#define IO_CTRL_GPIO_2_OUTPUT_PAD_STRENGTH_MASK    ((u32)0x00000038)
#define IO_CTRL_GPIO_2_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_GPIO_2_OUTPUT_PAD_STRENGTH_WIDTH    ((u32)0x00000003)
#define IO_CTRL_GPIO_2_MUX_SELECT_MASK      ((u32)0x00000007)
#define IO_CTRL_GPIO_2_MUX_SELECT_LSB       0
#define IO_CTRL_GPIO_2_MUX_SELECT_WIDTH     ((u32)0x00000003)

#define IO_CTRL_GPIO_2_HOST_INTERFACE_RST    0x1
#define IO_CTRL_GPIO_2_GPIO_IN_RST          0x1
#define IO_CTRL_GPIO_2_GPIO_OUT_RST         0x0
#define IO_CTRL_GPIO_2_GPIO_OE_RST          0x0
#define IO_CTRL_GPIO_2_GPIO_ENABLE_RST      0x1
#define IO_CTRL_GPIO_2_INPUT_ENABLE_RST     0x1
#define IO_CTRL_GPIO_2_DRIVER_PULL_STATE_RST    0x2
#define IO_CTRL_GPIO_2_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_GPIO_2_MUX_SELECT_RST       0x0

static inline void io_ctrl_gpio_2_pack(struct cl_chip *chip, u8 host_interface, u8 gpio_in, u8 gpio_out, u8 gpio_oe, u8 gpio_enable, u8 input_enable, u8 driver_pull_state, u8 output_pad_strength, u8 mux_select)
{
	ASSERT_ERR_CHIP((((u32)host_interface << 14) & ~((u32)0x00004000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_in << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_out << 12) & ~((u32)0x00001000)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_oe << 11) & ~((u32)0x00000800)) == 0);
	ASSERT_ERR_CHIP((((u32)gpio_enable << 10) & ~((u32)0x00000400)) == 0);
	ASSERT_ERR_CHIP((((u32)input_enable << 9) & ~((u32)0x00000200)) == 0);
	ASSERT_ERR_CHIP((((u32)driver_pull_state << 6) & ~((u32)0x000000C0)) == 0);
	ASSERT_ERR_CHIP((((u32)output_pad_strength << 3) & ~((u32)0x00000038)) == 0);
	ASSERT_ERR_CHIP((((u32)mux_select << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_GPIO_2_ADDR,  ((u32)host_interface << 14) | ((u32)gpio_in << 13) | ((u32)gpio_out << 12) | ((u32)gpio_oe << 11) | ((u32)gpio_enable << 10) | ((u32)input_enable << 9) | ((u32)driver_pull_state << 6) | ((u32)output_pad_strength << 3) | ((u32)mux_select << 0));
}

static inline void io_ctrl_gpio_2_unpack(struct cl_chip *chip, u8 *host_interface, u8 *gpio_in, u8 *gpio_out, u8 *gpio_oe, u8 *gpio_enable, u8 *input_enable, u8 *driver_pull_state, u8 *output_pad_strength, u8 *mux_select)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_GPIO_2_ADDR);

	*host_interface = (local_val & ((u32)0x00004000)) >> 14;
	*gpio_in = (local_val & ((u32)0x00002000)) >> 13;
	*gpio_out = (local_val & ((u32)0x00001000)) >> 12;
	*gpio_oe = (local_val & ((u32)0x00000800)) >> 11;
	*gpio_enable = (local_val & ((u32)0x00000400)) >> 10;
	*input_enable = (local_val & ((u32)0x00000200)) >> 9;
	*driver_pull_state = (local_val & ((u32)0x000000C0)) >> 6;
	*output_pad_strength = (local_val & ((u32)0x00000038)) >> 3;
	*mux_select = (local_val & ((u32)0x00000007)) >> 0;
}

static inline u8 io_ctrl_gpio_2_host_interface_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_GPIO_2_ADDR);

	return (u8)((local_val & ((u32)0x00004000)) >> 14);
}

static inline u8 io_ctrl_gpio_2_gpio_in_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_GPIO_2_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline u8 io_ctrl_gpio_2_gpio_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_GPIO_2_ADDR);

	return (u8)((local_val & ((u32)0x00001000)) >> 12);
}

static inline void io_ctrl_gpio_2_gpio_out_setf(struct cl_chip *chip, u8 gpioout)
{
	ASSERT_ERR_CHIP((((u32)gpioout << 12) & ~((u32)0x00001000)) == 0);
	cl_reg_write(chip, IO_CTRL_GPIO_2_ADDR, (cl_reg_read(chip, IO_CTRL_GPIO_2_ADDR) & ~((u32)0x00001000)) | ((u32)gpioout << 12));
}

static inline u8 io_ctrl_gpio_2_gpio_oe_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_GPIO_2_ADDR);

	return (u8)((local_val & ((u32)0x00000800)) >> 11);
}

static inline void io_ctrl_gpio_2_gpio_oe_setf(struct cl_chip *chip, u8 gpiooe)
{
	ASSERT_ERR_CHIP((((u32)gpiooe << 11) & ~((u32)0x00000800)) == 0);
	cl_reg_write(chip, IO_CTRL_GPIO_2_ADDR, (cl_reg_read(chip, IO_CTRL_GPIO_2_ADDR) & ~((u32)0x00000800)) | ((u32)gpiooe << 11));
}

static inline u8 io_ctrl_gpio_2_gpio_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_GPIO_2_ADDR);

	return (u8)((local_val & ((u32)0x00000400)) >> 10);
}

static inline void io_ctrl_gpio_2_gpio_enable_setf(struct cl_chip *chip, u8 gpioenable)
{
	ASSERT_ERR_CHIP((((u32)gpioenable << 10) & ~((u32)0x00000400)) == 0);
	cl_reg_write(chip, IO_CTRL_GPIO_2_ADDR, (cl_reg_read(chip, IO_CTRL_GPIO_2_ADDR) & ~((u32)0x00000400)) | ((u32)gpioenable << 10));
}

static inline u8 io_ctrl_gpio_2_input_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_GPIO_2_ADDR);

	return (u8)((local_val & ((u32)0x00000200)) >> 9);
}

static inline void io_ctrl_gpio_2_input_enable_setf(struct cl_chip *chip, u8 inputenable)
{
	ASSERT_ERR_CHIP((((u32)inputenable << 9) & ~((u32)0x00000200)) == 0);
	cl_reg_write(chip, IO_CTRL_GPIO_2_ADDR, (cl_reg_read(chip, IO_CTRL_GPIO_2_ADDR) & ~((u32)0x00000200)) | ((u32)inputenable << 9));
}

static inline u8 io_ctrl_gpio_2_driver_pull_state_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_GPIO_2_ADDR);

	return (u8)((local_val & ((u32)0x000000C0)) >> 6);
}

static inline void io_ctrl_gpio_2_driver_pull_state_setf(struct cl_chip *chip, u8 driverpullstate)
{
	ASSERT_ERR_CHIP((((u32)driverpullstate << 6) & ~((u32)0x000000C0)) == 0);
	cl_reg_write(chip, IO_CTRL_GPIO_2_ADDR, (cl_reg_read(chip, IO_CTRL_GPIO_2_ADDR) & ~((u32)0x000000C0)) | ((u32)driverpullstate << 6));
}

static inline u8 io_ctrl_gpio_2_output_pad_strength_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_GPIO_2_ADDR);

	return (u8)((local_val & ((u32)0x00000038)) >> 3);
}

static inline void io_ctrl_gpio_2_output_pad_strength_setf(struct cl_chip *chip, u8 outputpadstrength)
{
	ASSERT_ERR_CHIP((((u32)outputpadstrength << 3) & ~((u32)0x00000038)) == 0);
	cl_reg_write(chip, IO_CTRL_GPIO_2_ADDR, (cl_reg_read(chip, IO_CTRL_GPIO_2_ADDR) & ~((u32)0x00000038)) | ((u32)outputpadstrength << 3));
}

static inline u8 io_ctrl_gpio_2_mux_select_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, IO_CTRL_GPIO_2_ADDR);

	return (u8)((local_val & ((u32)0x00000007)) >> 0);
}

static inline void io_ctrl_gpio_2_mux_select_setf(struct cl_chip *chip, u8 muxselect)
{
	ASSERT_ERR_CHIP((((u32)muxselect << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, IO_CTRL_GPIO_2_ADDR, (cl_reg_read(chip, IO_CTRL_GPIO_2_ADDR) & ~((u32)0x00000007)) | ((u32)muxselect << 0));
}

#endif /* REG_IO_CTRL_H */

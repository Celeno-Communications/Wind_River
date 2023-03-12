#ifndef _REG_IO_CTRL_H_
#define _REG_IO_CTRL_H_

#include <stdint.h>
#include "_reg_io_ctrl.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define DBG_FILEID __REG_IO_CTRL__H__FILEID__

#define REG_IO_CTRL_COUNT  23


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
#define IO_CTRL_SCL_ADDR        (REG_IO_CTRL_BASE_ADDR+0x00000004)
#define IO_CTRL_SCL_OFFSET      0x00000004
#define IO_CTRL_SCL_INDEX       0x00000001
#define IO_CTRL_SCL_RESET       0x000008C8

__INLINE uint32_t  io_ctrl_scl_get(void)
{
	return REG_PL_RD(IO_CTRL_SCL_ADDR);
}

__INLINE void io_ctrl_scl_set(uint32_t value)
{
	REG_PL_WR(IO_CTRL_SCL_ADDR, value);
}

// field definitions
#define IO_CTRL_SCL_GPIO_IN_BIT             ((uint32_t)0x00002000)
#define IO_CTRL_SCL_GPIO_IN_POS             13
#define IO_CTRL_SCL_GPIO_OUT_BIT            ((uint32_t)0x00001000)
#define IO_CTRL_SCL_GPIO_OUT_POS            12
#define IO_CTRL_SCL_GPIO_OE_BIT             ((uint32_t)0x00000800)
#define IO_CTRL_SCL_GPIO_OE_POS             11
#define IO_CTRL_SCL_GPIO_ENABLE_BIT         ((uint32_t)0x00000400)
#define IO_CTRL_SCL_GPIO_ENABLE_POS         10
#define IO_CTRL_SCL_INPUT_ENABLE_BIT        ((uint32_t)0x00000200)
#define IO_CTRL_SCL_INPUT_ENABLE_POS        9
#define IO_CTRL_SCL_DRIVER_PULL_STATE_MASK    ((uint32_t)0x000000C0)
#define IO_CTRL_SCL_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_SCL_DRIVER_PULL_STATE_WIDTH    ((uint32_t)0x00000002)
#define IO_CTRL_SCL_OUTPUT_PAD_STRENGTH_MASK    ((uint32_t)0x00000038)
#define IO_CTRL_SCL_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_SCL_OUTPUT_PAD_STRENGTH_WIDTH    ((uint32_t)0x00000003)
#define IO_CTRL_SCL_MUX_SELECT_MASK         ((uint32_t)0x00000007)
#define IO_CTRL_SCL_MUX_SELECT_LSB          0
#define IO_CTRL_SCL_MUX_SELECT_WIDTH        ((uint32_t)0x00000003)

#define IO_CTRL_SCL_GPIO_IN_RST             0x1
#define IO_CTRL_SCL_GPIO_OUT_RST            0x0
#define IO_CTRL_SCL_GPIO_OE_RST             0x0
#define IO_CTRL_SCL_GPIO_ENABLE_RST         0x0
#define IO_CTRL_SCL_INPUT_ENABLE_RST        0x1
#define IO_CTRL_SCL_DRIVER_PULL_STATE_RST    0x2
#define IO_CTRL_SCL_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_SCL_MUX_SELECT_RST          0x0

__INLINE void io_ctrl_scl_pack(uint8_t gpio_in, uint8_t gpio_out, uint8_t gpio_oe, uint8_t gpio_enable, uint8_t input_enable, uint8_t driver_pull_state, uint8_t output_pad_strength, uint8_t mux_select)
{
	ASSERT_ERR((((uint32_t)gpio_in << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_out << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_oe << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)gpio_enable << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)input_enable << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)driver_pull_state << 6) & ~((uint32_t)0x000000C0)) == 0);
	ASSERT_ERR((((uint32_t)output_pad_strength << 3) & ~((uint32_t)0x00000038)) == 0);
	ASSERT_ERR((((uint32_t)mux_select << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_SCL_ADDR,  ((uint32_t)gpio_in << 13) |((uint32_t)gpio_out << 12) |((uint32_t)gpio_oe << 11) |((uint32_t)gpio_enable << 10) |((uint32_t)input_enable << 9) |((uint32_t)driver_pull_state << 6) |((uint32_t)output_pad_strength << 3) |((uint32_t)mux_select << 0));
}

__INLINE void io_ctrl_scl_unpack(uint8_t* gpio_in, uint8_t* gpio_out, uint8_t* gpio_oe, uint8_t* gpio_enable, uint8_t* input_enable, uint8_t* driver_pull_state, uint8_t* output_pad_strength, uint8_t* mux_select)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_SCL_ADDR);

	*gpio_in = (localVal & ((uint32_t)0x00002000)) >>  13;
	*gpio_out = (localVal & ((uint32_t)0x00001000)) >>  12;
	*gpio_oe = (localVal & ((uint32_t)0x00000800)) >>  11;
	*gpio_enable = (localVal & ((uint32_t)0x00000400)) >>  10;
	*input_enable = (localVal & ((uint32_t)0x00000200)) >>  9;
	*driver_pull_state = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*output_pad_strength = (localVal & ((uint32_t)0x00000038)) >>  3;
	*mux_select = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t io_ctrl_scl_gpio_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_SCL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE uint8_t io_ctrl_scl_gpio_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_SCL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void io_ctrl_scl_gpio_out_setf(uint8_t gpioout)
{
	ASSERT_ERR((((uint32_t)gpioout << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(IO_CTRL_SCL_ADDR, (REG_PL_RD(IO_CTRL_SCL_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)gpioout <<12));
}
__INLINE uint8_t io_ctrl_scl_gpio_oe_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_SCL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void io_ctrl_scl_gpio_oe_setf(uint8_t gpiooe)
{
	ASSERT_ERR((((uint32_t)gpiooe << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(IO_CTRL_SCL_ADDR, (REG_PL_RD(IO_CTRL_SCL_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)gpiooe <<11));
}
__INLINE uint8_t io_ctrl_scl_gpio_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_SCL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void io_ctrl_scl_gpio_enable_setf(uint8_t gpioenable)
{
	ASSERT_ERR((((uint32_t)gpioenable << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(IO_CTRL_SCL_ADDR, (REG_PL_RD(IO_CTRL_SCL_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)gpioenable <<10));
}
__INLINE uint8_t io_ctrl_scl_input_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_SCL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void io_ctrl_scl_input_enable_setf(uint8_t inputenable)
{
	ASSERT_ERR((((uint32_t)inputenable << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(IO_CTRL_SCL_ADDR, (REG_PL_RD(IO_CTRL_SCL_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)inputenable <<9));
}
__INLINE uint8_t io_ctrl_scl_driver_pull_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_SCL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE void io_ctrl_scl_driver_pull_state_setf(uint8_t driverpullstate)
{
	ASSERT_ERR((((uint32_t)driverpullstate << 6) & ~((uint32_t)0x000000C0)) == 0);
	REG_PL_WR(IO_CTRL_SCL_ADDR, (REG_PL_RD(IO_CTRL_SCL_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)driverpullstate <<6));
}
__INLINE uint8_t io_ctrl_scl_output_pad_strength_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_SCL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000038)) >> 3);
}
__INLINE void io_ctrl_scl_output_pad_strength_setf(uint8_t outputpadstrength)
{
	ASSERT_ERR((((uint32_t)outputpadstrength << 3) & ~((uint32_t)0x00000038)) == 0);
	REG_PL_WR(IO_CTRL_SCL_ADDR, (REG_PL_RD(IO_CTRL_SCL_ADDR) & ~((uint32_t)0x00000038)) | ((uint32_t)outputpadstrength <<3));
}
__INLINE uint8_t io_ctrl_scl_mux_select_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_SCL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void io_ctrl_scl_mux_select_setf(uint8_t muxselect)
{
	ASSERT_ERR((((uint32_t)muxselect << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_SCL_ADDR, (REG_PL_RD(IO_CTRL_SCL_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)muxselect <<0));
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
#define IO_CTRL_SDA_ADDR        (REG_IO_CTRL_BASE_ADDR+0x00000008)
#define IO_CTRL_SDA_OFFSET      0x00000008
#define IO_CTRL_SDA_INDEX       0x00000002
#define IO_CTRL_SDA_RESET       0x000008C8

__INLINE uint32_t  io_ctrl_sda_get(void)
{
	return REG_PL_RD(IO_CTRL_SDA_ADDR);
}

__INLINE void io_ctrl_sda_set(uint32_t value)
{
	REG_PL_WR(IO_CTRL_SDA_ADDR, value);
}

// field definitions
#define IO_CTRL_SDA_GPIO_IN_BIT             ((uint32_t)0x00002000)
#define IO_CTRL_SDA_GPIO_IN_POS             13
#define IO_CTRL_SDA_GPIO_OUT_BIT            ((uint32_t)0x00001000)
#define IO_CTRL_SDA_GPIO_OUT_POS            12
#define IO_CTRL_SDA_GPIO_OE_BIT             ((uint32_t)0x00000800)
#define IO_CTRL_SDA_GPIO_OE_POS             11
#define IO_CTRL_SDA_GPIO_ENABLE_BIT         ((uint32_t)0x00000400)
#define IO_CTRL_SDA_GPIO_ENABLE_POS         10
#define IO_CTRL_SDA_INPUT_ENABLE_BIT        ((uint32_t)0x00000200)
#define IO_CTRL_SDA_INPUT_ENABLE_POS        9
#define IO_CTRL_SDA_DRIVER_PULL_STATE_MASK    ((uint32_t)0x000000C0)
#define IO_CTRL_SDA_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_SDA_DRIVER_PULL_STATE_WIDTH    ((uint32_t)0x00000002)
#define IO_CTRL_SDA_OUTPUT_PAD_STRENGTH_MASK    ((uint32_t)0x00000038)
#define IO_CTRL_SDA_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_SDA_OUTPUT_PAD_STRENGTH_WIDTH    ((uint32_t)0x00000003)
#define IO_CTRL_SDA_MUX_SELECT_MASK         ((uint32_t)0x00000007)
#define IO_CTRL_SDA_MUX_SELECT_LSB          0
#define IO_CTRL_SDA_MUX_SELECT_WIDTH        ((uint32_t)0x00000003)

#define IO_CTRL_SDA_GPIO_IN_RST             0x1
#define IO_CTRL_SDA_GPIO_OUT_RST            0x0
#define IO_CTRL_SDA_GPIO_OE_RST             0x0
#define IO_CTRL_SDA_GPIO_ENABLE_RST         0x0
#define IO_CTRL_SDA_INPUT_ENABLE_RST        0x1
#define IO_CTRL_SDA_DRIVER_PULL_STATE_RST    0x2
#define IO_CTRL_SDA_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_SDA_MUX_SELECT_RST          0x0

__INLINE void io_ctrl_sda_pack(uint8_t gpio_in, uint8_t gpio_out, uint8_t gpio_oe, uint8_t gpio_enable, uint8_t input_enable, uint8_t driver_pull_state, uint8_t output_pad_strength, uint8_t mux_select)
{
	ASSERT_ERR((((uint32_t)gpio_in << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_out << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_oe << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)gpio_enable << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)input_enable << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)driver_pull_state << 6) & ~((uint32_t)0x000000C0)) == 0);
	ASSERT_ERR((((uint32_t)output_pad_strength << 3) & ~((uint32_t)0x00000038)) == 0);
	ASSERT_ERR((((uint32_t)mux_select << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_SDA_ADDR,  ((uint32_t)gpio_in << 13) |((uint32_t)gpio_out << 12) |((uint32_t)gpio_oe << 11) |((uint32_t)gpio_enable << 10) |((uint32_t)input_enable << 9) |((uint32_t)driver_pull_state << 6) |((uint32_t)output_pad_strength << 3) |((uint32_t)mux_select << 0));
}

__INLINE void io_ctrl_sda_unpack(uint8_t* gpio_in, uint8_t* gpio_out, uint8_t* gpio_oe, uint8_t* gpio_enable, uint8_t* input_enable, uint8_t* driver_pull_state, uint8_t* output_pad_strength, uint8_t* mux_select)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_SDA_ADDR);

	*gpio_in = (localVal & ((uint32_t)0x00002000)) >>  13;
	*gpio_out = (localVal & ((uint32_t)0x00001000)) >>  12;
	*gpio_oe = (localVal & ((uint32_t)0x00000800)) >>  11;
	*gpio_enable = (localVal & ((uint32_t)0x00000400)) >>  10;
	*input_enable = (localVal & ((uint32_t)0x00000200)) >>  9;
	*driver_pull_state = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*output_pad_strength = (localVal & ((uint32_t)0x00000038)) >>  3;
	*mux_select = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t io_ctrl_sda_gpio_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_SDA_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE uint8_t io_ctrl_sda_gpio_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_SDA_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void io_ctrl_sda_gpio_out_setf(uint8_t gpioout)
{
	ASSERT_ERR((((uint32_t)gpioout << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(IO_CTRL_SDA_ADDR, (REG_PL_RD(IO_CTRL_SDA_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)gpioout <<12));
}
__INLINE uint8_t io_ctrl_sda_gpio_oe_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_SDA_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void io_ctrl_sda_gpio_oe_setf(uint8_t gpiooe)
{
	ASSERT_ERR((((uint32_t)gpiooe << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(IO_CTRL_SDA_ADDR, (REG_PL_RD(IO_CTRL_SDA_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)gpiooe <<11));
}
__INLINE uint8_t io_ctrl_sda_gpio_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_SDA_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void io_ctrl_sda_gpio_enable_setf(uint8_t gpioenable)
{
	ASSERT_ERR((((uint32_t)gpioenable << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(IO_CTRL_SDA_ADDR, (REG_PL_RD(IO_CTRL_SDA_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)gpioenable <<10));
}
__INLINE uint8_t io_ctrl_sda_input_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_SDA_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void io_ctrl_sda_input_enable_setf(uint8_t inputenable)
{
	ASSERT_ERR((((uint32_t)inputenable << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(IO_CTRL_SDA_ADDR, (REG_PL_RD(IO_CTRL_SDA_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)inputenable <<9));
}
__INLINE uint8_t io_ctrl_sda_driver_pull_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_SDA_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE void io_ctrl_sda_driver_pull_state_setf(uint8_t driverpullstate)
{
	ASSERT_ERR((((uint32_t)driverpullstate << 6) & ~((uint32_t)0x000000C0)) == 0);
	REG_PL_WR(IO_CTRL_SDA_ADDR, (REG_PL_RD(IO_CTRL_SDA_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)driverpullstate <<6));
}
__INLINE uint8_t io_ctrl_sda_output_pad_strength_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_SDA_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000038)) >> 3);
}
__INLINE void io_ctrl_sda_output_pad_strength_setf(uint8_t outputpadstrength)
{
	ASSERT_ERR((((uint32_t)outputpadstrength << 3) & ~((uint32_t)0x00000038)) == 0);
	REG_PL_WR(IO_CTRL_SDA_ADDR, (REG_PL_RD(IO_CTRL_SDA_ADDR) & ~((uint32_t)0x00000038)) | ((uint32_t)outputpadstrength <<3));
}
__INLINE uint8_t io_ctrl_sda_mux_select_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_SDA_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void io_ctrl_sda_mux_select_setf(uint8_t muxselect)
{
	ASSERT_ERR((((uint32_t)muxselect << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_SDA_ADDR, (REG_PL_RD(IO_CTRL_SDA_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)muxselect <<0));
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
#define IO_CTRL_GPIO_1_ADDR        (REG_IO_CTRL_BASE_ADDR+0x0000000C)
#define IO_CTRL_GPIO_1_OFFSET      0x0000000C
#define IO_CTRL_GPIO_1_INDEX       0x00000003
#define IO_CTRL_GPIO_1_RESET       0x000009C8

__INLINE uint32_t  io_ctrl_gpio_1_get(void)
{
	return REG_PL_RD(IO_CTRL_GPIO_1_ADDR);
}

__INLINE void io_ctrl_gpio_1_set(uint32_t value)
{
	REG_PL_WR(IO_CTRL_GPIO_1_ADDR, value);
}

// field definitions
#define IO_CTRL_GPIO_1_GPIO_IN_BIT          ((uint32_t)0x00002000)
#define IO_CTRL_GPIO_1_GPIO_IN_POS          13
#define IO_CTRL_GPIO_1_GPIO_OUT_BIT         ((uint32_t)0x00001000)
#define IO_CTRL_GPIO_1_GPIO_OUT_POS         12
#define IO_CTRL_GPIO_1_GPIO_OE_BIT          ((uint32_t)0x00000800)
#define IO_CTRL_GPIO_1_GPIO_OE_POS          11
#define IO_CTRL_GPIO_1_GPIO_ENABLE_BIT      ((uint32_t)0x00000400)
#define IO_CTRL_GPIO_1_GPIO_ENABLE_POS      10
#define IO_CTRL_GPIO_1_INPUT_ENABLE_BIT     ((uint32_t)0x00000200)
#define IO_CTRL_GPIO_1_INPUT_ENABLE_POS     9
#define IO_CTRL_GPIO_1_DRIVER_PULL_STATE_MASK    ((uint32_t)0x000000C0)
#define IO_CTRL_GPIO_1_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_GPIO_1_DRIVER_PULL_STATE_WIDTH    ((uint32_t)0x00000002)
#define IO_CTRL_GPIO_1_OUTPUT_PAD_STRENGTH_MASK    ((uint32_t)0x00000038)
#define IO_CTRL_GPIO_1_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_GPIO_1_OUTPUT_PAD_STRENGTH_WIDTH    ((uint32_t)0x00000003)
#define IO_CTRL_GPIO_1_MUX_SELECT_MASK      ((uint32_t)0x00000007)
#define IO_CTRL_GPIO_1_MUX_SELECT_LSB       0
#define IO_CTRL_GPIO_1_MUX_SELECT_WIDTH     ((uint32_t)0x00000003)

#define IO_CTRL_GPIO_1_GPIO_IN_RST          0x1
#define IO_CTRL_GPIO_1_GPIO_OUT_RST         0x0
#define IO_CTRL_GPIO_1_GPIO_OE_RST          0x0
#define IO_CTRL_GPIO_1_GPIO_ENABLE_RST      0x1
#define IO_CTRL_GPIO_1_INPUT_ENABLE_RST     0x1
#define IO_CTRL_GPIO_1_DRIVER_PULL_STATE_RST    0x2
#define IO_CTRL_GPIO_1_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_GPIO_1_MUX_SELECT_RST       0x0

__INLINE void io_ctrl_gpio_1_pack(uint8_t gpio_in, uint8_t gpio_out, uint8_t gpio_oe, uint8_t gpio_enable, uint8_t input_enable, uint8_t driver_pull_state, uint8_t output_pad_strength, uint8_t mux_select)
{
	ASSERT_ERR((((uint32_t)gpio_in << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_out << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_oe << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)gpio_enable << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)input_enable << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)driver_pull_state << 6) & ~((uint32_t)0x000000C0)) == 0);
	ASSERT_ERR((((uint32_t)output_pad_strength << 3) & ~((uint32_t)0x00000038)) == 0);
	ASSERT_ERR((((uint32_t)mux_select << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_GPIO_1_ADDR,  ((uint32_t)gpio_in << 13) |((uint32_t)gpio_out << 12) |((uint32_t)gpio_oe << 11) |((uint32_t)gpio_enable << 10) |((uint32_t)input_enable << 9) |((uint32_t)driver_pull_state << 6) |((uint32_t)output_pad_strength << 3) |((uint32_t)mux_select << 0));
}

__INLINE void io_ctrl_gpio_1_unpack(uint8_t* gpio_in, uint8_t* gpio_out, uint8_t* gpio_oe, uint8_t* gpio_enable, uint8_t* input_enable, uint8_t* driver_pull_state, uint8_t* output_pad_strength, uint8_t* mux_select)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_GPIO_1_ADDR);

	*gpio_in = (localVal & ((uint32_t)0x00002000)) >>  13;
	*gpio_out = (localVal & ((uint32_t)0x00001000)) >>  12;
	*gpio_oe = (localVal & ((uint32_t)0x00000800)) >>  11;
	*gpio_enable = (localVal & ((uint32_t)0x00000400)) >>  10;
	*input_enable = (localVal & ((uint32_t)0x00000200)) >>  9;
	*driver_pull_state = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*output_pad_strength = (localVal & ((uint32_t)0x00000038)) >>  3;
	*mux_select = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t io_ctrl_gpio_1_gpio_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_GPIO_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE uint8_t io_ctrl_gpio_1_gpio_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_GPIO_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void io_ctrl_gpio_1_gpio_out_setf(uint8_t gpioout)
{
	ASSERT_ERR((((uint32_t)gpioout << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(IO_CTRL_GPIO_1_ADDR, (REG_PL_RD(IO_CTRL_GPIO_1_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)gpioout <<12));
}
__INLINE uint8_t io_ctrl_gpio_1_gpio_oe_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_GPIO_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void io_ctrl_gpio_1_gpio_oe_setf(uint8_t gpiooe)
{
	ASSERT_ERR((((uint32_t)gpiooe << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(IO_CTRL_GPIO_1_ADDR, (REG_PL_RD(IO_CTRL_GPIO_1_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)gpiooe <<11));
}
__INLINE uint8_t io_ctrl_gpio_1_gpio_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_GPIO_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void io_ctrl_gpio_1_gpio_enable_setf(uint8_t gpioenable)
{
	ASSERT_ERR((((uint32_t)gpioenable << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(IO_CTRL_GPIO_1_ADDR, (REG_PL_RD(IO_CTRL_GPIO_1_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)gpioenable <<10));
}
__INLINE uint8_t io_ctrl_gpio_1_input_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_GPIO_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void io_ctrl_gpio_1_input_enable_setf(uint8_t inputenable)
{
	ASSERT_ERR((((uint32_t)inputenable << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(IO_CTRL_GPIO_1_ADDR, (REG_PL_RD(IO_CTRL_GPIO_1_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)inputenable <<9));
}
__INLINE uint8_t io_ctrl_gpio_1_driver_pull_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_GPIO_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE void io_ctrl_gpio_1_driver_pull_state_setf(uint8_t driverpullstate)
{
	ASSERT_ERR((((uint32_t)driverpullstate << 6) & ~((uint32_t)0x000000C0)) == 0);
	REG_PL_WR(IO_CTRL_GPIO_1_ADDR, (REG_PL_RD(IO_CTRL_GPIO_1_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)driverpullstate <<6));
}
__INLINE uint8_t io_ctrl_gpio_1_output_pad_strength_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_GPIO_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000038)) >> 3);
}
__INLINE void io_ctrl_gpio_1_output_pad_strength_setf(uint8_t outputpadstrength)
{
	ASSERT_ERR((((uint32_t)outputpadstrength << 3) & ~((uint32_t)0x00000038)) == 0);
	REG_PL_WR(IO_CTRL_GPIO_1_ADDR, (REG_PL_RD(IO_CTRL_GPIO_1_ADDR) & ~((uint32_t)0x00000038)) | ((uint32_t)outputpadstrength <<3));
}
__INLINE uint8_t io_ctrl_gpio_1_mux_select_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_GPIO_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void io_ctrl_gpio_1_mux_select_setf(uint8_t muxselect)
{
	ASSERT_ERR((((uint32_t)muxselect << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_GPIO_1_ADDR, (REG_PL_RD(IO_CTRL_GPIO_1_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)muxselect <<0));
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
#define IO_CTRL_TRST_N_ADDR        (REG_IO_CTRL_BASE_ADDR+0x00000010)
#define IO_CTRL_TRST_N_OFFSET      0x00000010
#define IO_CTRL_TRST_N_INDEX       0x00000004
#define IO_CTRL_TRST_N_RESET       0x000008C8

__INLINE uint32_t  io_ctrl_trst_n_get(void)
{
	return REG_PL_RD(IO_CTRL_TRST_N_ADDR);
}

__INLINE void io_ctrl_trst_n_set(uint32_t value)
{
	REG_PL_WR(IO_CTRL_TRST_N_ADDR, value);
}

// field definitions
#define IO_CTRL_TRST_N_GPIO_IN_BIT          ((uint32_t)0x00002000)
#define IO_CTRL_TRST_N_GPIO_IN_POS          13
#define IO_CTRL_TRST_N_GPIO_OUT_BIT         ((uint32_t)0x00001000)
#define IO_CTRL_TRST_N_GPIO_OUT_POS         12
#define IO_CTRL_TRST_N_GPIO_OE_BIT          ((uint32_t)0x00000800)
#define IO_CTRL_TRST_N_GPIO_OE_POS          11
#define IO_CTRL_TRST_N_GPIO_ENABLE_BIT      ((uint32_t)0x00000400)
#define IO_CTRL_TRST_N_GPIO_ENABLE_POS      10
#define IO_CTRL_TRST_N_INPUT_ENABLE_BIT     ((uint32_t)0x00000200)
#define IO_CTRL_TRST_N_INPUT_ENABLE_POS     9
#define IO_CTRL_TRST_N_DRIVER_PULL_STATE_MASK    ((uint32_t)0x000000C0)
#define IO_CTRL_TRST_N_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_TRST_N_DRIVER_PULL_STATE_WIDTH    ((uint32_t)0x00000002)
#define IO_CTRL_TRST_N_OUTPUT_PAD_STRENGTH_MASK    ((uint32_t)0x00000038)
#define IO_CTRL_TRST_N_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_TRST_N_OUTPUT_PAD_STRENGTH_WIDTH    ((uint32_t)0x00000003)
#define IO_CTRL_TRST_N_MUX_SELECT_MASK      ((uint32_t)0x00000007)
#define IO_CTRL_TRST_N_MUX_SELECT_LSB       0
#define IO_CTRL_TRST_N_MUX_SELECT_WIDTH     ((uint32_t)0x00000003)

#define IO_CTRL_TRST_N_GPIO_IN_RST          0x1
#define IO_CTRL_TRST_N_GPIO_OUT_RST         0x0
#define IO_CTRL_TRST_N_GPIO_OE_RST          0x0
#define IO_CTRL_TRST_N_GPIO_ENABLE_RST      0x0
#define IO_CTRL_TRST_N_INPUT_ENABLE_RST     0x1
#define IO_CTRL_TRST_N_DRIVER_PULL_STATE_RST    0x2
#define IO_CTRL_TRST_N_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_TRST_N_MUX_SELECT_RST       0x0

__INLINE void io_ctrl_trst_n_pack(uint8_t gpio_in, uint8_t gpio_out, uint8_t gpio_oe, uint8_t gpio_enable, uint8_t input_enable, uint8_t driver_pull_state, uint8_t output_pad_strength, uint8_t mux_select)
{
	ASSERT_ERR((((uint32_t)gpio_in << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_out << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_oe << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)gpio_enable << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)input_enable << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)driver_pull_state << 6) & ~((uint32_t)0x000000C0)) == 0);
	ASSERT_ERR((((uint32_t)output_pad_strength << 3) & ~((uint32_t)0x00000038)) == 0);
	ASSERT_ERR((((uint32_t)mux_select << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_TRST_N_ADDR,  ((uint32_t)gpio_in << 13) |((uint32_t)gpio_out << 12) |((uint32_t)gpio_oe << 11) |((uint32_t)gpio_enable << 10) |((uint32_t)input_enable << 9) |((uint32_t)driver_pull_state << 6) |((uint32_t)output_pad_strength << 3) |((uint32_t)mux_select << 0));
}

__INLINE void io_ctrl_trst_n_unpack(uint8_t* gpio_in, uint8_t* gpio_out, uint8_t* gpio_oe, uint8_t* gpio_enable, uint8_t* input_enable, uint8_t* driver_pull_state, uint8_t* output_pad_strength, uint8_t* mux_select)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TRST_N_ADDR);

	*gpio_in = (localVal & ((uint32_t)0x00002000)) >>  13;
	*gpio_out = (localVal & ((uint32_t)0x00001000)) >>  12;
	*gpio_oe = (localVal & ((uint32_t)0x00000800)) >>  11;
	*gpio_enable = (localVal & ((uint32_t)0x00000400)) >>  10;
	*input_enable = (localVal & ((uint32_t)0x00000200)) >>  9;
	*driver_pull_state = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*output_pad_strength = (localVal & ((uint32_t)0x00000038)) >>  3;
	*mux_select = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t io_ctrl_trst_n_gpio_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TRST_N_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE uint8_t io_ctrl_trst_n_gpio_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TRST_N_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void io_ctrl_trst_n_gpio_out_setf(uint8_t gpioout)
{
	ASSERT_ERR((((uint32_t)gpioout << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(IO_CTRL_TRST_N_ADDR, (REG_PL_RD(IO_CTRL_TRST_N_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)gpioout <<12));
}
__INLINE uint8_t io_ctrl_trst_n_gpio_oe_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TRST_N_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void io_ctrl_trst_n_gpio_oe_setf(uint8_t gpiooe)
{
	ASSERT_ERR((((uint32_t)gpiooe << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(IO_CTRL_TRST_N_ADDR, (REG_PL_RD(IO_CTRL_TRST_N_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)gpiooe <<11));
}
__INLINE uint8_t io_ctrl_trst_n_gpio_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TRST_N_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void io_ctrl_trst_n_gpio_enable_setf(uint8_t gpioenable)
{
	ASSERT_ERR((((uint32_t)gpioenable << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(IO_CTRL_TRST_N_ADDR, (REG_PL_RD(IO_CTRL_TRST_N_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)gpioenable <<10));
}
__INLINE uint8_t io_ctrl_trst_n_input_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TRST_N_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void io_ctrl_trst_n_input_enable_setf(uint8_t inputenable)
{
	ASSERT_ERR((((uint32_t)inputenable << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(IO_CTRL_TRST_N_ADDR, (REG_PL_RD(IO_CTRL_TRST_N_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)inputenable <<9));
}
__INLINE uint8_t io_ctrl_trst_n_driver_pull_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TRST_N_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE void io_ctrl_trst_n_driver_pull_state_setf(uint8_t driverpullstate)
{
	ASSERT_ERR((((uint32_t)driverpullstate << 6) & ~((uint32_t)0x000000C0)) == 0);
	REG_PL_WR(IO_CTRL_TRST_N_ADDR, (REG_PL_RD(IO_CTRL_TRST_N_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)driverpullstate <<6));
}
__INLINE uint8_t io_ctrl_trst_n_output_pad_strength_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TRST_N_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000038)) >> 3);
}
__INLINE void io_ctrl_trst_n_output_pad_strength_setf(uint8_t outputpadstrength)
{
	ASSERT_ERR((((uint32_t)outputpadstrength << 3) & ~((uint32_t)0x00000038)) == 0);
	REG_PL_WR(IO_CTRL_TRST_N_ADDR, (REG_PL_RD(IO_CTRL_TRST_N_ADDR) & ~((uint32_t)0x00000038)) | ((uint32_t)outputpadstrength <<3));
}
__INLINE uint8_t io_ctrl_trst_n_mux_select_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TRST_N_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void io_ctrl_trst_n_mux_select_setf(uint8_t muxselect)
{
	ASSERT_ERR((((uint32_t)muxselect << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_TRST_N_ADDR, (REG_PL_RD(IO_CTRL_TRST_N_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)muxselect <<0));
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
#define IO_CTRL_TDI_ADDR        (REG_IO_CTRL_BASE_ADDR+0x00000014)
#define IO_CTRL_TDI_OFFSET      0x00000014
#define IO_CTRL_TDI_INDEX       0x00000005
#define IO_CTRL_TDI_RESET       0x000008C8

__INLINE uint32_t  io_ctrl_tdi_get(void)
{
	return REG_PL_RD(IO_CTRL_TDI_ADDR);
}

__INLINE void io_ctrl_tdi_set(uint32_t value)
{
	REG_PL_WR(IO_CTRL_TDI_ADDR, value);
}

// field definitions
#define IO_CTRL_TDI_GPIO_IN_BIT             ((uint32_t)0x00002000)
#define IO_CTRL_TDI_GPIO_IN_POS             13
#define IO_CTRL_TDI_GPIO_OUT_BIT            ((uint32_t)0x00001000)
#define IO_CTRL_TDI_GPIO_OUT_POS            12
#define IO_CTRL_TDI_GPIO_OE_BIT             ((uint32_t)0x00000800)
#define IO_CTRL_TDI_GPIO_OE_POS             11
#define IO_CTRL_TDI_GPIO_ENABLE_BIT         ((uint32_t)0x00000400)
#define IO_CTRL_TDI_GPIO_ENABLE_POS         10
#define IO_CTRL_TDI_INPUT_ENABLE_BIT        ((uint32_t)0x00000200)
#define IO_CTRL_TDI_INPUT_ENABLE_POS        9
#define IO_CTRL_TDI_DRIVER_PULL_STATE_MASK    ((uint32_t)0x000000C0)
#define IO_CTRL_TDI_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_TDI_DRIVER_PULL_STATE_WIDTH    ((uint32_t)0x00000002)
#define IO_CTRL_TDI_OUTPUT_PAD_STRENGTH_MASK    ((uint32_t)0x00000038)
#define IO_CTRL_TDI_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_TDI_OUTPUT_PAD_STRENGTH_WIDTH    ((uint32_t)0x00000003)
#define IO_CTRL_TDI_MUX_SELECT_MASK         ((uint32_t)0x00000007)
#define IO_CTRL_TDI_MUX_SELECT_LSB          0
#define IO_CTRL_TDI_MUX_SELECT_WIDTH        ((uint32_t)0x00000003)

#define IO_CTRL_TDI_GPIO_IN_RST             0x1
#define IO_CTRL_TDI_GPIO_OUT_RST            0x0
#define IO_CTRL_TDI_GPIO_OE_RST             0x0
#define IO_CTRL_TDI_GPIO_ENABLE_RST         0x0
#define IO_CTRL_TDI_INPUT_ENABLE_RST        0x1
#define IO_CTRL_TDI_DRIVER_PULL_STATE_RST    0x2
#define IO_CTRL_TDI_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_TDI_MUX_SELECT_RST          0x0

__INLINE void io_ctrl_tdi_pack(uint8_t gpio_in, uint8_t gpio_out, uint8_t gpio_oe, uint8_t gpio_enable, uint8_t input_enable, uint8_t driver_pull_state, uint8_t output_pad_strength, uint8_t mux_select)
{
	ASSERT_ERR((((uint32_t)gpio_in << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_out << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_oe << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)gpio_enable << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)input_enable << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)driver_pull_state << 6) & ~((uint32_t)0x000000C0)) == 0);
	ASSERT_ERR((((uint32_t)output_pad_strength << 3) & ~((uint32_t)0x00000038)) == 0);
	ASSERT_ERR((((uint32_t)mux_select << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_TDI_ADDR,  ((uint32_t)gpio_in << 13) |((uint32_t)gpio_out << 12) |((uint32_t)gpio_oe << 11) |((uint32_t)gpio_enable << 10) |((uint32_t)input_enable << 9) |((uint32_t)driver_pull_state << 6) |((uint32_t)output_pad_strength << 3) |((uint32_t)mux_select << 0));
}

__INLINE void io_ctrl_tdi_unpack(uint8_t* gpio_in, uint8_t* gpio_out, uint8_t* gpio_oe, uint8_t* gpio_enable, uint8_t* input_enable, uint8_t* driver_pull_state, uint8_t* output_pad_strength, uint8_t* mux_select)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TDI_ADDR);

	*gpio_in = (localVal & ((uint32_t)0x00002000)) >>  13;
	*gpio_out = (localVal & ((uint32_t)0x00001000)) >>  12;
	*gpio_oe = (localVal & ((uint32_t)0x00000800)) >>  11;
	*gpio_enable = (localVal & ((uint32_t)0x00000400)) >>  10;
	*input_enable = (localVal & ((uint32_t)0x00000200)) >>  9;
	*driver_pull_state = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*output_pad_strength = (localVal & ((uint32_t)0x00000038)) >>  3;
	*mux_select = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t io_ctrl_tdi_gpio_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TDI_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE uint8_t io_ctrl_tdi_gpio_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TDI_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void io_ctrl_tdi_gpio_out_setf(uint8_t gpioout)
{
	ASSERT_ERR((((uint32_t)gpioout << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(IO_CTRL_TDI_ADDR, (REG_PL_RD(IO_CTRL_TDI_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)gpioout <<12));
}
__INLINE uint8_t io_ctrl_tdi_gpio_oe_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TDI_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void io_ctrl_tdi_gpio_oe_setf(uint8_t gpiooe)
{
	ASSERT_ERR((((uint32_t)gpiooe << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(IO_CTRL_TDI_ADDR, (REG_PL_RD(IO_CTRL_TDI_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)gpiooe <<11));
}
__INLINE uint8_t io_ctrl_tdi_gpio_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TDI_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void io_ctrl_tdi_gpio_enable_setf(uint8_t gpioenable)
{
	ASSERT_ERR((((uint32_t)gpioenable << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(IO_CTRL_TDI_ADDR, (REG_PL_RD(IO_CTRL_TDI_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)gpioenable <<10));
}
__INLINE uint8_t io_ctrl_tdi_input_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TDI_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void io_ctrl_tdi_input_enable_setf(uint8_t inputenable)
{
	ASSERT_ERR((((uint32_t)inputenable << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(IO_CTRL_TDI_ADDR, (REG_PL_RD(IO_CTRL_TDI_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)inputenable <<9));
}
__INLINE uint8_t io_ctrl_tdi_driver_pull_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TDI_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE void io_ctrl_tdi_driver_pull_state_setf(uint8_t driverpullstate)
{
	ASSERT_ERR((((uint32_t)driverpullstate << 6) & ~((uint32_t)0x000000C0)) == 0);
	REG_PL_WR(IO_CTRL_TDI_ADDR, (REG_PL_RD(IO_CTRL_TDI_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)driverpullstate <<6));
}
__INLINE uint8_t io_ctrl_tdi_output_pad_strength_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TDI_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000038)) >> 3);
}
__INLINE void io_ctrl_tdi_output_pad_strength_setf(uint8_t outputpadstrength)
{
	ASSERT_ERR((((uint32_t)outputpadstrength << 3) & ~((uint32_t)0x00000038)) == 0);
	REG_PL_WR(IO_CTRL_TDI_ADDR, (REG_PL_RD(IO_CTRL_TDI_ADDR) & ~((uint32_t)0x00000038)) | ((uint32_t)outputpadstrength <<3));
}
__INLINE uint8_t io_ctrl_tdi_mux_select_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TDI_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void io_ctrl_tdi_mux_select_setf(uint8_t muxselect)
{
	ASSERT_ERR((((uint32_t)muxselect << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_TDI_ADDR, (REG_PL_RD(IO_CTRL_TDI_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)muxselect <<0));
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
#define IO_CTRL_TDO_ADDR        (REG_IO_CTRL_BASE_ADDR+0x00000018)
#define IO_CTRL_TDO_OFFSET      0x00000018
#define IO_CTRL_TDO_INDEX       0x00000006
#define IO_CTRL_TDO_RESET       0x000008C8

__INLINE uint32_t  io_ctrl_tdo_get(void)
{
	return REG_PL_RD(IO_CTRL_TDO_ADDR);
}

__INLINE void io_ctrl_tdo_set(uint32_t value)
{
	REG_PL_WR(IO_CTRL_TDO_ADDR, value);
}

// field definitions
#define IO_CTRL_TDO_GPIO_IN_BIT             ((uint32_t)0x00002000)
#define IO_CTRL_TDO_GPIO_IN_POS             13
#define IO_CTRL_TDO_GPIO_OUT_BIT            ((uint32_t)0x00001000)
#define IO_CTRL_TDO_GPIO_OUT_POS            12
#define IO_CTRL_TDO_GPIO_OE_BIT             ((uint32_t)0x00000800)
#define IO_CTRL_TDO_GPIO_OE_POS             11
#define IO_CTRL_TDO_GPIO_ENABLE_BIT         ((uint32_t)0x00000400)
#define IO_CTRL_TDO_GPIO_ENABLE_POS         10
#define IO_CTRL_TDO_INPUT_ENABLE_BIT        ((uint32_t)0x00000200)
#define IO_CTRL_TDO_INPUT_ENABLE_POS        9
#define IO_CTRL_TDO_DRIVER_PULL_STATE_MASK    ((uint32_t)0x000000C0)
#define IO_CTRL_TDO_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_TDO_DRIVER_PULL_STATE_WIDTH    ((uint32_t)0x00000002)
#define IO_CTRL_TDO_OUTPUT_PAD_STRENGTH_MASK    ((uint32_t)0x00000038)
#define IO_CTRL_TDO_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_TDO_OUTPUT_PAD_STRENGTH_WIDTH    ((uint32_t)0x00000003)
#define IO_CTRL_TDO_MUX_SELECT_MASK         ((uint32_t)0x00000007)
#define IO_CTRL_TDO_MUX_SELECT_LSB          0
#define IO_CTRL_TDO_MUX_SELECT_WIDTH        ((uint32_t)0x00000003)

#define IO_CTRL_TDO_GPIO_IN_RST             0x1
#define IO_CTRL_TDO_GPIO_OUT_RST            0x0
#define IO_CTRL_TDO_GPIO_OE_RST             0x0
#define IO_CTRL_TDO_GPIO_ENABLE_RST         0x0
#define IO_CTRL_TDO_INPUT_ENABLE_RST        0x1
#define IO_CTRL_TDO_DRIVER_PULL_STATE_RST    0x2
#define IO_CTRL_TDO_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_TDO_MUX_SELECT_RST          0x0

__INLINE void io_ctrl_tdo_pack(uint8_t gpio_in, uint8_t gpio_out, uint8_t gpio_oe, uint8_t gpio_enable, uint8_t input_enable, uint8_t driver_pull_state, uint8_t output_pad_strength, uint8_t mux_select)
{
	ASSERT_ERR((((uint32_t)gpio_in << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_out << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_oe << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)gpio_enable << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)input_enable << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)driver_pull_state << 6) & ~((uint32_t)0x000000C0)) == 0);
	ASSERT_ERR((((uint32_t)output_pad_strength << 3) & ~((uint32_t)0x00000038)) == 0);
	ASSERT_ERR((((uint32_t)mux_select << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_TDO_ADDR,  ((uint32_t)gpio_in << 13) |((uint32_t)gpio_out << 12) |((uint32_t)gpio_oe << 11) |((uint32_t)gpio_enable << 10) |((uint32_t)input_enable << 9) |((uint32_t)driver_pull_state << 6) |((uint32_t)output_pad_strength << 3) |((uint32_t)mux_select << 0));
}

__INLINE void io_ctrl_tdo_unpack(uint8_t* gpio_in, uint8_t* gpio_out, uint8_t* gpio_oe, uint8_t* gpio_enable, uint8_t* input_enable, uint8_t* driver_pull_state, uint8_t* output_pad_strength, uint8_t* mux_select)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TDO_ADDR);

	*gpio_in = (localVal & ((uint32_t)0x00002000)) >>  13;
	*gpio_out = (localVal & ((uint32_t)0x00001000)) >>  12;
	*gpio_oe = (localVal & ((uint32_t)0x00000800)) >>  11;
	*gpio_enable = (localVal & ((uint32_t)0x00000400)) >>  10;
	*input_enable = (localVal & ((uint32_t)0x00000200)) >>  9;
	*driver_pull_state = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*output_pad_strength = (localVal & ((uint32_t)0x00000038)) >>  3;
	*mux_select = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t io_ctrl_tdo_gpio_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TDO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE uint8_t io_ctrl_tdo_gpio_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TDO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void io_ctrl_tdo_gpio_out_setf(uint8_t gpioout)
{
	ASSERT_ERR((((uint32_t)gpioout << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(IO_CTRL_TDO_ADDR, (REG_PL_RD(IO_CTRL_TDO_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)gpioout <<12));
}
__INLINE uint8_t io_ctrl_tdo_gpio_oe_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TDO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void io_ctrl_tdo_gpio_oe_setf(uint8_t gpiooe)
{
	ASSERT_ERR((((uint32_t)gpiooe << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(IO_CTRL_TDO_ADDR, (REG_PL_RD(IO_CTRL_TDO_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)gpiooe <<11));
}
__INLINE uint8_t io_ctrl_tdo_gpio_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TDO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void io_ctrl_tdo_gpio_enable_setf(uint8_t gpioenable)
{
	ASSERT_ERR((((uint32_t)gpioenable << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(IO_CTRL_TDO_ADDR, (REG_PL_RD(IO_CTRL_TDO_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)gpioenable <<10));
}
__INLINE uint8_t io_ctrl_tdo_input_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TDO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void io_ctrl_tdo_input_enable_setf(uint8_t inputenable)
{
	ASSERT_ERR((((uint32_t)inputenable << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(IO_CTRL_TDO_ADDR, (REG_PL_RD(IO_CTRL_TDO_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)inputenable <<9));
}
__INLINE uint8_t io_ctrl_tdo_driver_pull_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TDO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE void io_ctrl_tdo_driver_pull_state_setf(uint8_t driverpullstate)
{
	ASSERT_ERR((((uint32_t)driverpullstate << 6) & ~((uint32_t)0x000000C0)) == 0);
	REG_PL_WR(IO_CTRL_TDO_ADDR, (REG_PL_RD(IO_CTRL_TDO_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)driverpullstate <<6));
}
__INLINE uint8_t io_ctrl_tdo_output_pad_strength_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TDO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000038)) >> 3);
}
__INLINE void io_ctrl_tdo_output_pad_strength_setf(uint8_t outputpadstrength)
{
	ASSERT_ERR((((uint32_t)outputpadstrength << 3) & ~((uint32_t)0x00000038)) == 0);
	REG_PL_WR(IO_CTRL_TDO_ADDR, (REG_PL_RD(IO_CTRL_TDO_ADDR) & ~((uint32_t)0x00000038)) | ((uint32_t)outputpadstrength <<3));
}
__INLINE uint8_t io_ctrl_tdo_mux_select_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TDO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void io_ctrl_tdo_mux_select_setf(uint8_t muxselect)
{
	ASSERT_ERR((((uint32_t)muxselect << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_TDO_ADDR, (REG_PL_RD(IO_CTRL_TDO_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)muxselect <<0));
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
#define IO_CTRL_TCK_ADDR        (REG_IO_CTRL_BASE_ADDR+0x0000001C)
#define IO_CTRL_TCK_OFFSET      0x0000001C
#define IO_CTRL_TCK_INDEX       0x00000007
#define IO_CTRL_TCK_RESET       0x000008C8

__INLINE uint32_t  io_ctrl_tck_get(void)
{
	return REG_PL_RD(IO_CTRL_TCK_ADDR);
}

__INLINE void io_ctrl_tck_set(uint32_t value)
{
	REG_PL_WR(IO_CTRL_TCK_ADDR, value);
}

// field definitions
#define IO_CTRL_TCK_GPIO_IN_BIT             ((uint32_t)0x00002000)
#define IO_CTRL_TCK_GPIO_IN_POS             13
#define IO_CTRL_TCK_GPIO_OUT_BIT            ((uint32_t)0x00001000)
#define IO_CTRL_TCK_GPIO_OUT_POS            12
#define IO_CTRL_TCK_GPIO_OE_BIT             ((uint32_t)0x00000800)
#define IO_CTRL_TCK_GPIO_OE_POS             11
#define IO_CTRL_TCK_GPIO_ENABLE_BIT         ((uint32_t)0x00000400)
#define IO_CTRL_TCK_GPIO_ENABLE_POS         10
#define IO_CTRL_TCK_INPUT_ENABLE_BIT        ((uint32_t)0x00000200)
#define IO_CTRL_TCK_INPUT_ENABLE_POS        9
#define IO_CTRL_TCK_DRIVER_PULL_STATE_MASK    ((uint32_t)0x000000C0)
#define IO_CTRL_TCK_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_TCK_DRIVER_PULL_STATE_WIDTH    ((uint32_t)0x00000002)
#define IO_CTRL_TCK_OUTPUT_PAD_STRENGTH_MASK    ((uint32_t)0x00000038)
#define IO_CTRL_TCK_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_TCK_OUTPUT_PAD_STRENGTH_WIDTH    ((uint32_t)0x00000003)
#define IO_CTRL_TCK_MUX_SELECT_MASK         ((uint32_t)0x00000007)
#define IO_CTRL_TCK_MUX_SELECT_LSB          0
#define IO_CTRL_TCK_MUX_SELECT_WIDTH        ((uint32_t)0x00000003)

#define IO_CTRL_TCK_GPIO_IN_RST             0x1
#define IO_CTRL_TCK_GPIO_OUT_RST            0x0
#define IO_CTRL_TCK_GPIO_OE_RST             0x0
#define IO_CTRL_TCK_GPIO_ENABLE_RST         0x0
#define IO_CTRL_TCK_INPUT_ENABLE_RST        0x1
#define IO_CTRL_TCK_DRIVER_PULL_STATE_RST    0x2
#define IO_CTRL_TCK_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_TCK_MUX_SELECT_RST          0x0

__INLINE void io_ctrl_tck_pack(uint8_t gpio_in, uint8_t gpio_out, uint8_t gpio_oe, uint8_t gpio_enable, uint8_t input_enable, uint8_t driver_pull_state, uint8_t output_pad_strength, uint8_t mux_select)
{
	ASSERT_ERR((((uint32_t)gpio_in << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_out << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_oe << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)gpio_enable << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)input_enable << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)driver_pull_state << 6) & ~((uint32_t)0x000000C0)) == 0);
	ASSERT_ERR((((uint32_t)output_pad_strength << 3) & ~((uint32_t)0x00000038)) == 0);
	ASSERT_ERR((((uint32_t)mux_select << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_TCK_ADDR,  ((uint32_t)gpio_in << 13) |((uint32_t)gpio_out << 12) |((uint32_t)gpio_oe << 11) |((uint32_t)gpio_enable << 10) |((uint32_t)input_enable << 9) |((uint32_t)driver_pull_state << 6) |((uint32_t)output_pad_strength << 3) |((uint32_t)mux_select << 0));
}

__INLINE void io_ctrl_tck_unpack(uint8_t* gpio_in, uint8_t* gpio_out, uint8_t* gpio_oe, uint8_t* gpio_enable, uint8_t* input_enable, uint8_t* driver_pull_state, uint8_t* output_pad_strength, uint8_t* mux_select)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TCK_ADDR);

	*gpio_in = (localVal & ((uint32_t)0x00002000)) >>  13;
	*gpio_out = (localVal & ((uint32_t)0x00001000)) >>  12;
	*gpio_oe = (localVal & ((uint32_t)0x00000800)) >>  11;
	*gpio_enable = (localVal & ((uint32_t)0x00000400)) >>  10;
	*input_enable = (localVal & ((uint32_t)0x00000200)) >>  9;
	*driver_pull_state = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*output_pad_strength = (localVal & ((uint32_t)0x00000038)) >>  3;
	*mux_select = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t io_ctrl_tck_gpio_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TCK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE uint8_t io_ctrl_tck_gpio_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TCK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void io_ctrl_tck_gpio_out_setf(uint8_t gpioout)
{
	ASSERT_ERR((((uint32_t)gpioout << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(IO_CTRL_TCK_ADDR, (REG_PL_RD(IO_CTRL_TCK_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)gpioout <<12));
}
__INLINE uint8_t io_ctrl_tck_gpio_oe_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TCK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void io_ctrl_tck_gpio_oe_setf(uint8_t gpiooe)
{
	ASSERT_ERR((((uint32_t)gpiooe << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(IO_CTRL_TCK_ADDR, (REG_PL_RD(IO_CTRL_TCK_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)gpiooe <<11));
}
__INLINE uint8_t io_ctrl_tck_gpio_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TCK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void io_ctrl_tck_gpio_enable_setf(uint8_t gpioenable)
{
	ASSERT_ERR((((uint32_t)gpioenable << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(IO_CTRL_TCK_ADDR, (REG_PL_RD(IO_CTRL_TCK_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)gpioenable <<10));
}
__INLINE uint8_t io_ctrl_tck_input_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TCK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void io_ctrl_tck_input_enable_setf(uint8_t inputenable)
{
	ASSERT_ERR((((uint32_t)inputenable << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(IO_CTRL_TCK_ADDR, (REG_PL_RD(IO_CTRL_TCK_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)inputenable <<9));
}
__INLINE uint8_t io_ctrl_tck_driver_pull_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TCK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE void io_ctrl_tck_driver_pull_state_setf(uint8_t driverpullstate)
{
	ASSERT_ERR((((uint32_t)driverpullstate << 6) & ~((uint32_t)0x000000C0)) == 0);
	REG_PL_WR(IO_CTRL_TCK_ADDR, (REG_PL_RD(IO_CTRL_TCK_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)driverpullstate <<6));
}
__INLINE uint8_t io_ctrl_tck_output_pad_strength_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TCK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000038)) >> 3);
}
__INLINE void io_ctrl_tck_output_pad_strength_setf(uint8_t outputpadstrength)
{
	ASSERT_ERR((((uint32_t)outputpadstrength << 3) & ~((uint32_t)0x00000038)) == 0);
	REG_PL_WR(IO_CTRL_TCK_ADDR, (REG_PL_RD(IO_CTRL_TCK_ADDR) & ~((uint32_t)0x00000038)) | ((uint32_t)outputpadstrength <<3));
}
__INLINE uint8_t io_ctrl_tck_mux_select_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TCK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void io_ctrl_tck_mux_select_setf(uint8_t muxselect)
{
	ASSERT_ERR((((uint32_t)muxselect << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_TCK_ADDR, (REG_PL_RD(IO_CTRL_TCK_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)muxselect <<0));
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
#define IO_CTRL_TMS_ADDR        (REG_IO_CTRL_BASE_ADDR+0x00000020)
#define IO_CTRL_TMS_OFFSET      0x00000020
#define IO_CTRL_TMS_INDEX       0x00000008
#define IO_CTRL_TMS_RESET       0x000008C8

__INLINE uint32_t  io_ctrl_tms_get(void)
{
	return REG_PL_RD(IO_CTRL_TMS_ADDR);
}

__INLINE void io_ctrl_tms_set(uint32_t value)
{
	REG_PL_WR(IO_CTRL_TMS_ADDR, value);
}

// field definitions
#define IO_CTRL_TMS_GPIO_IN_BIT             ((uint32_t)0x00002000)
#define IO_CTRL_TMS_GPIO_IN_POS             13
#define IO_CTRL_TMS_GPIO_OUT_BIT            ((uint32_t)0x00001000)
#define IO_CTRL_TMS_GPIO_OUT_POS            12
#define IO_CTRL_TMS_GPIO_OE_BIT             ((uint32_t)0x00000800)
#define IO_CTRL_TMS_GPIO_OE_POS             11
#define IO_CTRL_TMS_GPIO_ENABLE_BIT         ((uint32_t)0x00000400)
#define IO_CTRL_TMS_GPIO_ENABLE_POS         10
#define IO_CTRL_TMS_INPUT_ENABLE_BIT        ((uint32_t)0x00000200)
#define IO_CTRL_TMS_INPUT_ENABLE_POS        9
#define IO_CTRL_TMS_DRIVER_PULL_STATE_MASK    ((uint32_t)0x000000C0)
#define IO_CTRL_TMS_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_TMS_DRIVER_PULL_STATE_WIDTH    ((uint32_t)0x00000002)
#define IO_CTRL_TMS_OUTPUT_PAD_STRENGTH_MASK    ((uint32_t)0x00000038)
#define IO_CTRL_TMS_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_TMS_OUTPUT_PAD_STRENGTH_WIDTH    ((uint32_t)0x00000003)
#define IO_CTRL_TMS_MUX_SELECT_MASK         ((uint32_t)0x00000007)
#define IO_CTRL_TMS_MUX_SELECT_LSB          0
#define IO_CTRL_TMS_MUX_SELECT_WIDTH        ((uint32_t)0x00000003)

#define IO_CTRL_TMS_GPIO_IN_RST             0x1
#define IO_CTRL_TMS_GPIO_OUT_RST            0x0
#define IO_CTRL_TMS_GPIO_OE_RST             0x0
#define IO_CTRL_TMS_GPIO_ENABLE_RST         0x0
#define IO_CTRL_TMS_INPUT_ENABLE_RST        0x1
#define IO_CTRL_TMS_DRIVER_PULL_STATE_RST    0x2
#define IO_CTRL_TMS_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_TMS_MUX_SELECT_RST          0x0

__INLINE void io_ctrl_tms_pack(uint8_t gpio_in, uint8_t gpio_out, uint8_t gpio_oe, uint8_t gpio_enable, uint8_t input_enable, uint8_t driver_pull_state, uint8_t output_pad_strength, uint8_t mux_select)
{
	ASSERT_ERR((((uint32_t)gpio_in << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_out << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_oe << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)gpio_enable << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)input_enable << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)driver_pull_state << 6) & ~((uint32_t)0x000000C0)) == 0);
	ASSERT_ERR((((uint32_t)output_pad_strength << 3) & ~((uint32_t)0x00000038)) == 0);
	ASSERT_ERR((((uint32_t)mux_select << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_TMS_ADDR,  ((uint32_t)gpio_in << 13) |((uint32_t)gpio_out << 12) |((uint32_t)gpio_oe << 11) |((uint32_t)gpio_enable << 10) |((uint32_t)input_enable << 9) |((uint32_t)driver_pull_state << 6) |((uint32_t)output_pad_strength << 3) |((uint32_t)mux_select << 0));
}

__INLINE void io_ctrl_tms_unpack(uint8_t* gpio_in, uint8_t* gpio_out, uint8_t* gpio_oe, uint8_t* gpio_enable, uint8_t* input_enable, uint8_t* driver_pull_state, uint8_t* output_pad_strength, uint8_t* mux_select)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TMS_ADDR);

	*gpio_in = (localVal & ((uint32_t)0x00002000)) >>  13;
	*gpio_out = (localVal & ((uint32_t)0x00001000)) >>  12;
	*gpio_oe = (localVal & ((uint32_t)0x00000800)) >>  11;
	*gpio_enable = (localVal & ((uint32_t)0x00000400)) >>  10;
	*input_enable = (localVal & ((uint32_t)0x00000200)) >>  9;
	*driver_pull_state = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*output_pad_strength = (localVal & ((uint32_t)0x00000038)) >>  3;
	*mux_select = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t io_ctrl_tms_gpio_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TMS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE uint8_t io_ctrl_tms_gpio_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TMS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void io_ctrl_tms_gpio_out_setf(uint8_t gpioout)
{
	ASSERT_ERR((((uint32_t)gpioout << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(IO_CTRL_TMS_ADDR, (REG_PL_RD(IO_CTRL_TMS_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)gpioout <<12));
}
__INLINE uint8_t io_ctrl_tms_gpio_oe_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TMS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void io_ctrl_tms_gpio_oe_setf(uint8_t gpiooe)
{
	ASSERT_ERR((((uint32_t)gpiooe << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(IO_CTRL_TMS_ADDR, (REG_PL_RD(IO_CTRL_TMS_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)gpiooe <<11));
}
__INLINE uint8_t io_ctrl_tms_gpio_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TMS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void io_ctrl_tms_gpio_enable_setf(uint8_t gpioenable)
{
	ASSERT_ERR((((uint32_t)gpioenable << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(IO_CTRL_TMS_ADDR, (REG_PL_RD(IO_CTRL_TMS_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)gpioenable <<10));
}
__INLINE uint8_t io_ctrl_tms_input_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TMS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void io_ctrl_tms_input_enable_setf(uint8_t inputenable)
{
	ASSERT_ERR((((uint32_t)inputenable << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(IO_CTRL_TMS_ADDR, (REG_PL_RD(IO_CTRL_TMS_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)inputenable <<9));
}
__INLINE uint8_t io_ctrl_tms_driver_pull_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TMS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE void io_ctrl_tms_driver_pull_state_setf(uint8_t driverpullstate)
{
	ASSERT_ERR((((uint32_t)driverpullstate << 6) & ~((uint32_t)0x000000C0)) == 0);
	REG_PL_WR(IO_CTRL_TMS_ADDR, (REG_PL_RD(IO_CTRL_TMS_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)driverpullstate <<6));
}
__INLINE uint8_t io_ctrl_tms_output_pad_strength_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TMS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000038)) >> 3);
}
__INLINE void io_ctrl_tms_output_pad_strength_setf(uint8_t outputpadstrength)
{
	ASSERT_ERR((((uint32_t)outputpadstrength << 3) & ~((uint32_t)0x00000038)) == 0);
	REG_PL_WR(IO_CTRL_TMS_ADDR, (REG_PL_RD(IO_CTRL_TMS_ADDR) & ~((uint32_t)0x00000038)) | ((uint32_t)outputpadstrength <<3));
}
__INLINE uint8_t io_ctrl_tms_mux_select_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TMS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void io_ctrl_tms_mux_select_setf(uint8_t muxselect)
{
	ASSERT_ERR((((uint32_t)muxselect << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_TMS_ADDR, (REG_PL_RD(IO_CTRL_TMS_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)muxselect <<0));
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
#define IO_CTRL_PTA_PRI_U_2_ADDR        (REG_IO_CTRL_BASE_ADDR+0x00000024)
#define IO_CTRL_PTA_PRI_U_2_OFFSET      0x00000024
#define IO_CTRL_PTA_PRI_U_2_INDEX       0x00000009
#define IO_CTRL_PTA_PRI_U_2_RESET       0x000001A8

__INLINE uint32_t  io_ctrl_pta_pri_u_2_get(void)
{
	return REG_PL_RD(IO_CTRL_PTA_PRI_U_2_ADDR);
}

__INLINE void io_ctrl_pta_pri_u_2_set(uint32_t value)
{
	REG_PL_WR(IO_CTRL_PTA_PRI_U_2_ADDR, value);
}

// field definitions
#define IO_CTRL_PTA_PRI_U_2_GPIO_IN_BIT     ((uint32_t)0x00002000)
#define IO_CTRL_PTA_PRI_U_2_GPIO_IN_POS     13
#define IO_CTRL_PTA_PRI_U_2_GPIO_OUT_BIT    ((uint32_t)0x00001000)
#define IO_CTRL_PTA_PRI_U_2_GPIO_OUT_POS    12
#define IO_CTRL_PTA_PRI_U_2_GPIO_OE_BIT     ((uint32_t)0x00000800)
#define IO_CTRL_PTA_PRI_U_2_GPIO_OE_POS     11
#define IO_CTRL_PTA_PRI_U_2_GPIO_ENABLE_BIT    ((uint32_t)0x00000400)
#define IO_CTRL_PTA_PRI_U_2_GPIO_ENABLE_POS    10
#define IO_CTRL_PTA_PRI_U_2_INPUT_ENABLE_BIT    ((uint32_t)0x00000200)
#define IO_CTRL_PTA_PRI_U_2_INPUT_ENABLE_POS    9
#define IO_CTRL_PTA_PRI_U_2_DRIVER_PULL_STATE_MASK    ((uint32_t)0x000000C0)
#define IO_CTRL_PTA_PRI_U_2_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_PTA_PRI_U_2_DRIVER_PULL_STATE_WIDTH    ((uint32_t)0x00000002)
#define IO_CTRL_PTA_PRI_U_2_OUTPUT_PAD_STRENGTH_MASK    ((uint32_t)0x00000038)
#define IO_CTRL_PTA_PRI_U_2_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_PTA_PRI_U_2_OUTPUT_PAD_STRENGTH_WIDTH    ((uint32_t)0x00000003)
#define IO_CTRL_PTA_PRI_U_2_MUX_SELECT_MASK    ((uint32_t)0x00000007)
#define IO_CTRL_PTA_PRI_U_2_MUX_SELECT_LSB    0
#define IO_CTRL_PTA_PRI_U_2_MUX_SELECT_WIDTH    ((uint32_t)0x00000003)

#define IO_CTRL_PTA_PRI_U_2_GPIO_IN_RST     0x0
#define IO_CTRL_PTA_PRI_U_2_GPIO_OUT_RST    0x0
#define IO_CTRL_PTA_PRI_U_2_GPIO_OE_RST     0x0
#define IO_CTRL_PTA_PRI_U_2_GPIO_ENABLE_RST    0x1
#define IO_CTRL_PTA_PRI_U_2_INPUT_ENABLE_RST    0x1
#define IO_CTRL_PTA_PRI_U_2_DRIVER_PULL_STATE_RST    0x1
#define IO_CTRL_PTA_PRI_U_2_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_PTA_PRI_U_2_MUX_SELECT_RST    0x0

__INLINE void io_ctrl_pta_pri_u_2_pack(uint8_t gpio_in, uint8_t gpio_out, uint8_t gpio_oe, uint8_t gpio_enable, uint8_t input_enable, uint8_t driver_pull_state, uint8_t output_pad_strength, uint8_t mux_select)
{
	ASSERT_ERR((((uint32_t)gpio_in << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_out << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_oe << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)gpio_enable << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)input_enable << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)driver_pull_state << 6) & ~((uint32_t)0x000000C0)) == 0);
	ASSERT_ERR((((uint32_t)output_pad_strength << 3) & ~((uint32_t)0x00000038)) == 0);
	ASSERT_ERR((((uint32_t)mux_select << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_PTA_PRI_U_2_ADDR,  ((uint32_t)gpio_in << 13) |((uint32_t)gpio_out << 12) |((uint32_t)gpio_oe << 11) |((uint32_t)gpio_enable << 10) |((uint32_t)input_enable << 9) |((uint32_t)driver_pull_state << 6) |((uint32_t)output_pad_strength << 3) |((uint32_t)mux_select << 0));
}

__INLINE void io_ctrl_pta_pri_u_2_unpack(uint8_t* gpio_in, uint8_t* gpio_out, uint8_t* gpio_oe, uint8_t* gpio_enable, uint8_t* input_enable, uint8_t* driver_pull_state, uint8_t* output_pad_strength, uint8_t* mux_select)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_PTA_PRI_U_2_ADDR);

	*gpio_in = (localVal & ((uint32_t)0x00002000)) >>  13;
	*gpio_out = (localVal & ((uint32_t)0x00001000)) >>  12;
	*gpio_oe = (localVal & ((uint32_t)0x00000800)) >>  11;
	*gpio_enable = (localVal & ((uint32_t)0x00000400)) >>  10;
	*input_enable = (localVal & ((uint32_t)0x00000200)) >>  9;
	*driver_pull_state = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*output_pad_strength = (localVal & ((uint32_t)0x00000038)) >>  3;
	*mux_select = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t io_ctrl_pta_pri_u_2_gpio_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_PTA_PRI_U_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE uint8_t io_ctrl_pta_pri_u_2_gpio_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_PTA_PRI_U_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void io_ctrl_pta_pri_u_2_gpio_out_setf(uint8_t gpioout)
{
	ASSERT_ERR((((uint32_t)gpioout << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(IO_CTRL_PTA_PRI_U_2_ADDR, (REG_PL_RD(IO_CTRL_PTA_PRI_U_2_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)gpioout <<12));
}
__INLINE uint8_t io_ctrl_pta_pri_u_2_gpio_oe_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_PTA_PRI_U_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void io_ctrl_pta_pri_u_2_gpio_oe_setf(uint8_t gpiooe)
{
	ASSERT_ERR((((uint32_t)gpiooe << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(IO_CTRL_PTA_PRI_U_2_ADDR, (REG_PL_RD(IO_CTRL_PTA_PRI_U_2_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)gpiooe <<11));
}
__INLINE uint8_t io_ctrl_pta_pri_u_2_gpio_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_PTA_PRI_U_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void io_ctrl_pta_pri_u_2_gpio_enable_setf(uint8_t gpioenable)
{
	ASSERT_ERR((((uint32_t)gpioenable << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(IO_CTRL_PTA_PRI_U_2_ADDR, (REG_PL_RD(IO_CTRL_PTA_PRI_U_2_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)gpioenable <<10));
}
__INLINE uint8_t io_ctrl_pta_pri_u_2_input_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_PTA_PRI_U_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void io_ctrl_pta_pri_u_2_input_enable_setf(uint8_t inputenable)
{
	ASSERT_ERR((((uint32_t)inputenable << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(IO_CTRL_PTA_PRI_U_2_ADDR, (REG_PL_RD(IO_CTRL_PTA_PRI_U_2_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)inputenable <<9));
}
__INLINE uint8_t io_ctrl_pta_pri_u_2_driver_pull_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_PTA_PRI_U_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE void io_ctrl_pta_pri_u_2_driver_pull_state_setf(uint8_t driverpullstate)
{
	ASSERT_ERR((((uint32_t)driverpullstate << 6) & ~((uint32_t)0x000000C0)) == 0);
	REG_PL_WR(IO_CTRL_PTA_PRI_U_2_ADDR, (REG_PL_RD(IO_CTRL_PTA_PRI_U_2_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)driverpullstate <<6));
}
__INLINE uint8_t io_ctrl_pta_pri_u_2_output_pad_strength_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_PTA_PRI_U_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000038)) >> 3);
}
__INLINE void io_ctrl_pta_pri_u_2_output_pad_strength_setf(uint8_t outputpadstrength)
{
	ASSERT_ERR((((uint32_t)outputpadstrength << 3) & ~((uint32_t)0x00000038)) == 0);
	REG_PL_WR(IO_CTRL_PTA_PRI_U_2_ADDR, (REG_PL_RD(IO_CTRL_PTA_PRI_U_2_ADDR) & ~((uint32_t)0x00000038)) | ((uint32_t)outputpadstrength <<3));
}
__INLINE uint8_t io_ctrl_pta_pri_u_2_mux_select_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_PTA_PRI_U_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void io_ctrl_pta_pri_u_2_mux_select_setf(uint8_t muxselect)
{
	ASSERT_ERR((((uint32_t)muxselect << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_PTA_PRI_U_2_ADDR, (REG_PL_RD(IO_CTRL_PTA_PRI_U_2_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)muxselect <<0));
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
#define IO_CTRL_CIF_DIN_ADDR        (REG_IO_CTRL_BASE_ADDR+0x00000028)
#define IO_CTRL_CIF_DIN_OFFSET      0x00000028
#define IO_CTRL_CIF_DIN_INDEX       0x0000000A
#define IO_CTRL_CIF_DIN_RESET       0x000009C8

__INLINE uint32_t  io_ctrl_cif_din_get(void)
{
	return REG_PL_RD(IO_CTRL_CIF_DIN_ADDR);
}

__INLINE void io_ctrl_cif_din_set(uint32_t value)
{
	REG_PL_WR(IO_CTRL_CIF_DIN_ADDR, value);
}

// field definitions
#define IO_CTRL_CIF_DIN_GPIO_IN_BIT         ((uint32_t)0x00002000)
#define IO_CTRL_CIF_DIN_GPIO_IN_POS         13
#define IO_CTRL_CIF_DIN_GPIO_OUT_BIT        ((uint32_t)0x00001000)
#define IO_CTRL_CIF_DIN_GPIO_OUT_POS        12
#define IO_CTRL_CIF_DIN_GPIO_OE_BIT         ((uint32_t)0x00000800)
#define IO_CTRL_CIF_DIN_GPIO_OE_POS         11
#define IO_CTRL_CIF_DIN_GPIO_ENABLE_BIT     ((uint32_t)0x00000400)
#define IO_CTRL_CIF_DIN_GPIO_ENABLE_POS     10
#define IO_CTRL_CIF_DIN_INPUT_ENABLE_BIT    ((uint32_t)0x00000200)
#define IO_CTRL_CIF_DIN_INPUT_ENABLE_POS    9
#define IO_CTRL_CIF_DIN_DRIVER_PULL_STATE_MASK    ((uint32_t)0x000000C0)
#define IO_CTRL_CIF_DIN_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_CIF_DIN_DRIVER_PULL_STATE_WIDTH    ((uint32_t)0x00000002)
#define IO_CTRL_CIF_DIN_OUTPUT_PAD_STRENGTH_MASK    ((uint32_t)0x00000038)
#define IO_CTRL_CIF_DIN_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_CIF_DIN_OUTPUT_PAD_STRENGTH_WIDTH    ((uint32_t)0x00000003)
#define IO_CTRL_CIF_DIN_MUX_SELECT_MASK     ((uint32_t)0x00000007)
#define IO_CTRL_CIF_DIN_MUX_SELECT_LSB      0
#define IO_CTRL_CIF_DIN_MUX_SELECT_WIDTH    ((uint32_t)0x00000003)

#define IO_CTRL_CIF_DIN_GPIO_IN_RST         0x1
#define IO_CTRL_CIF_DIN_GPIO_OUT_RST        0x0
#define IO_CTRL_CIF_DIN_GPIO_OE_RST         0x0
#define IO_CTRL_CIF_DIN_GPIO_ENABLE_RST     0x1
#define IO_CTRL_CIF_DIN_INPUT_ENABLE_RST    0x1
#define IO_CTRL_CIF_DIN_DRIVER_PULL_STATE_RST    0x2
#define IO_CTRL_CIF_DIN_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_CIF_DIN_MUX_SELECT_RST      0x0

__INLINE void io_ctrl_cif_din_pack(uint8_t gpio_in, uint8_t gpio_out, uint8_t gpio_oe, uint8_t gpio_enable, uint8_t input_enable, uint8_t driver_pull_state, uint8_t output_pad_strength, uint8_t mux_select)
{
	ASSERT_ERR((((uint32_t)gpio_in << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_out << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_oe << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)gpio_enable << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)input_enable << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)driver_pull_state << 6) & ~((uint32_t)0x000000C0)) == 0);
	ASSERT_ERR((((uint32_t)output_pad_strength << 3) & ~((uint32_t)0x00000038)) == 0);
	ASSERT_ERR((((uint32_t)mux_select << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_CIF_DIN_ADDR,  ((uint32_t)gpio_in << 13) |((uint32_t)gpio_out << 12) |((uint32_t)gpio_oe << 11) |((uint32_t)gpio_enable << 10) |((uint32_t)input_enable << 9) |((uint32_t)driver_pull_state << 6) |((uint32_t)output_pad_strength << 3) |((uint32_t)mux_select << 0));
}

__INLINE void io_ctrl_cif_din_unpack(uint8_t* gpio_in, uint8_t* gpio_out, uint8_t* gpio_oe, uint8_t* gpio_enable, uint8_t* input_enable, uint8_t* driver_pull_state, uint8_t* output_pad_strength, uint8_t* mux_select)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_DIN_ADDR);

	*gpio_in = (localVal & ((uint32_t)0x00002000)) >>  13;
	*gpio_out = (localVal & ((uint32_t)0x00001000)) >>  12;
	*gpio_oe = (localVal & ((uint32_t)0x00000800)) >>  11;
	*gpio_enable = (localVal & ((uint32_t)0x00000400)) >>  10;
	*input_enable = (localVal & ((uint32_t)0x00000200)) >>  9;
	*driver_pull_state = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*output_pad_strength = (localVal & ((uint32_t)0x00000038)) >>  3;
	*mux_select = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t io_ctrl_cif_din_gpio_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_DIN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE uint8_t io_ctrl_cif_din_gpio_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_DIN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void io_ctrl_cif_din_gpio_out_setf(uint8_t gpioout)
{
	ASSERT_ERR((((uint32_t)gpioout << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(IO_CTRL_CIF_DIN_ADDR, (REG_PL_RD(IO_CTRL_CIF_DIN_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)gpioout <<12));
}
__INLINE uint8_t io_ctrl_cif_din_gpio_oe_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_DIN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void io_ctrl_cif_din_gpio_oe_setf(uint8_t gpiooe)
{
	ASSERT_ERR((((uint32_t)gpiooe << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(IO_CTRL_CIF_DIN_ADDR, (REG_PL_RD(IO_CTRL_CIF_DIN_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)gpiooe <<11));
}
__INLINE uint8_t io_ctrl_cif_din_gpio_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_DIN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void io_ctrl_cif_din_gpio_enable_setf(uint8_t gpioenable)
{
	ASSERT_ERR((((uint32_t)gpioenable << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(IO_CTRL_CIF_DIN_ADDR, (REG_PL_RD(IO_CTRL_CIF_DIN_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)gpioenable <<10));
}
__INLINE uint8_t io_ctrl_cif_din_input_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_DIN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void io_ctrl_cif_din_input_enable_setf(uint8_t inputenable)
{
	ASSERT_ERR((((uint32_t)inputenable << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(IO_CTRL_CIF_DIN_ADDR, (REG_PL_RD(IO_CTRL_CIF_DIN_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)inputenable <<9));
}
__INLINE uint8_t io_ctrl_cif_din_driver_pull_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_DIN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE void io_ctrl_cif_din_driver_pull_state_setf(uint8_t driverpullstate)
{
	ASSERT_ERR((((uint32_t)driverpullstate << 6) & ~((uint32_t)0x000000C0)) == 0);
	REG_PL_WR(IO_CTRL_CIF_DIN_ADDR, (REG_PL_RD(IO_CTRL_CIF_DIN_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)driverpullstate <<6));
}
__INLINE uint8_t io_ctrl_cif_din_output_pad_strength_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_DIN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000038)) >> 3);
}
__INLINE void io_ctrl_cif_din_output_pad_strength_setf(uint8_t outputpadstrength)
{
	ASSERT_ERR((((uint32_t)outputpadstrength << 3) & ~((uint32_t)0x00000038)) == 0);
	REG_PL_WR(IO_CTRL_CIF_DIN_ADDR, (REG_PL_RD(IO_CTRL_CIF_DIN_ADDR) & ~((uint32_t)0x00000038)) | ((uint32_t)outputpadstrength <<3));
}
__INLINE uint8_t io_ctrl_cif_din_mux_select_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_DIN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void io_ctrl_cif_din_mux_select_setf(uint8_t muxselect)
{
	ASSERT_ERR((((uint32_t)muxselect << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_CIF_DIN_ADDR, (REG_PL_RD(IO_CTRL_CIF_DIN_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)muxselect <<0));
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
#define IO_CTRL_CIF_DOUT_ADDR        (REG_IO_CTRL_BASE_ADDR+0x0000002C)
#define IO_CTRL_CIF_DOUT_OFFSET      0x0000002C
#define IO_CTRL_CIF_DOUT_INDEX       0x0000000B
#define IO_CTRL_CIF_DOUT_RESET       0x000009C8

__INLINE uint32_t  io_ctrl_cif_dout_get(void)
{
	return REG_PL_RD(IO_CTRL_CIF_DOUT_ADDR);
}

__INLINE void io_ctrl_cif_dout_set(uint32_t value)
{
	REG_PL_WR(IO_CTRL_CIF_DOUT_ADDR, value);
}

// field definitions
#define IO_CTRL_CIF_DOUT_GPIO_IN_BIT        ((uint32_t)0x00002000)
#define IO_CTRL_CIF_DOUT_GPIO_IN_POS        13
#define IO_CTRL_CIF_DOUT_GPIO_OUT_BIT       ((uint32_t)0x00001000)
#define IO_CTRL_CIF_DOUT_GPIO_OUT_POS       12
#define IO_CTRL_CIF_DOUT_GPIO_OE_BIT        ((uint32_t)0x00000800)
#define IO_CTRL_CIF_DOUT_GPIO_OE_POS        11
#define IO_CTRL_CIF_DOUT_GPIO_ENABLE_BIT    ((uint32_t)0x00000400)
#define IO_CTRL_CIF_DOUT_GPIO_ENABLE_POS    10
#define IO_CTRL_CIF_DOUT_INPUT_ENABLE_BIT    ((uint32_t)0x00000200)
#define IO_CTRL_CIF_DOUT_INPUT_ENABLE_POS    9
#define IO_CTRL_CIF_DOUT_DRIVER_PULL_STATE_MASK    ((uint32_t)0x000000C0)
#define IO_CTRL_CIF_DOUT_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_CIF_DOUT_DRIVER_PULL_STATE_WIDTH    ((uint32_t)0x00000002)
#define IO_CTRL_CIF_DOUT_OUTPUT_PAD_STRENGTH_MASK    ((uint32_t)0x00000038)
#define IO_CTRL_CIF_DOUT_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_CIF_DOUT_OUTPUT_PAD_STRENGTH_WIDTH    ((uint32_t)0x00000003)
#define IO_CTRL_CIF_DOUT_MUX_SELECT_MASK    ((uint32_t)0x00000007)
#define IO_CTRL_CIF_DOUT_MUX_SELECT_LSB     0
#define IO_CTRL_CIF_DOUT_MUX_SELECT_WIDTH    ((uint32_t)0x00000003)

#define IO_CTRL_CIF_DOUT_GPIO_IN_RST        0x1
#define IO_CTRL_CIF_DOUT_GPIO_OUT_RST       0x0
#define IO_CTRL_CIF_DOUT_GPIO_OE_RST        0x0
#define IO_CTRL_CIF_DOUT_GPIO_ENABLE_RST    0x1
#define IO_CTRL_CIF_DOUT_INPUT_ENABLE_RST    0x1
#define IO_CTRL_CIF_DOUT_DRIVER_PULL_STATE_RST    0x2
#define IO_CTRL_CIF_DOUT_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_CIF_DOUT_MUX_SELECT_RST     0x0

__INLINE void io_ctrl_cif_dout_pack(uint8_t gpio_in, uint8_t gpio_out, uint8_t gpio_oe, uint8_t gpio_enable, uint8_t input_enable, uint8_t driver_pull_state, uint8_t output_pad_strength, uint8_t mux_select)
{
	ASSERT_ERR((((uint32_t)gpio_in << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_out << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_oe << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)gpio_enable << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)input_enable << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)driver_pull_state << 6) & ~((uint32_t)0x000000C0)) == 0);
	ASSERT_ERR((((uint32_t)output_pad_strength << 3) & ~((uint32_t)0x00000038)) == 0);
	ASSERT_ERR((((uint32_t)mux_select << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_CIF_DOUT_ADDR,  ((uint32_t)gpio_in << 13) |((uint32_t)gpio_out << 12) |((uint32_t)gpio_oe << 11) |((uint32_t)gpio_enable << 10) |((uint32_t)input_enable << 9) |((uint32_t)driver_pull_state << 6) |((uint32_t)output_pad_strength << 3) |((uint32_t)mux_select << 0));
}

__INLINE void io_ctrl_cif_dout_unpack(uint8_t* gpio_in, uint8_t* gpio_out, uint8_t* gpio_oe, uint8_t* gpio_enable, uint8_t* input_enable, uint8_t* driver_pull_state, uint8_t* output_pad_strength, uint8_t* mux_select)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_DOUT_ADDR);

	*gpio_in = (localVal & ((uint32_t)0x00002000)) >>  13;
	*gpio_out = (localVal & ((uint32_t)0x00001000)) >>  12;
	*gpio_oe = (localVal & ((uint32_t)0x00000800)) >>  11;
	*gpio_enable = (localVal & ((uint32_t)0x00000400)) >>  10;
	*input_enable = (localVal & ((uint32_t)0x00000200)) >>  9;
	*driver_pull_state = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*output_pad_strength = (localVal & ((uint32_t)0x00000038)) >>  3;
	*mux_select = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t io_ctrl_cif_dout_gpio_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_DOUT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE uint8_t io_ctrl_cif_dout_gpio_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_DOUT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void io_ctrl_cif_dout_gpio_out_setf(uint8_t gpioout)
{
	ASSERT_ERR((((uint32_t)gpioout << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(IO_CTRL_CIF_DOUT_ADDR, (REG_PL_RD(IO_CTRL_CIF_DOUT_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)gpioout <<12));
}
__INLINE uint8_t io_ctrl_cif_dout_gpio_oe_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_DOUT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void io_ctrl_cif_dout_gpio_oe_setf(uint8_t gpiooe)
{
	ASSERT_ERR((((uint32_t)gpiooe << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(IO_CTRL_CIF_DOUT_ADDR, (REG_PL_RD(IO_CTRL_CIF_DOUT_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)gpiooe <<11));
}
__INLINE uint8_t io_ctrl_cif_dout_gpio_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_DOUT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void io_ctrl_cif_dout_gpio_enable_setf(uint8_t gpioenable)
{
	ASSERT_ERR((((uint32_t)gpioenable << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(IO_CTRL_CIF_DOUT_ADDR, (REG_PL_RD(IO_CTRL_CIF_DOUT_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)gpioenable <<10));
}
__INLINE uint8_t io_ctrl_cif_dout_input_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_DOUT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void io_ctrl_cif_dout_input_enable_setf(uint8_t inputenable)
{
	ASSERT_ERR((((uint32_t)inputenable << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(IO_CTRL_CIF_DOUT_ADDR, (REG_PL_RD(IO_CTRL_CIF_DOUT_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)inputenable <<9));
}
__INLINE uint8_t io_ctrl_cif_dout_driver_pull_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_DOUT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE void io_ctrl_cif_dout_driver_pull_state_setf(uint8_t driverpullstate)
{
	ASSERT_ERR((((uint32_t)driverpullstate << 6) & ~((uint32_t)0x000000C0)) == 0);
	REG_PL_WR(IO_CTRL_CIF_DOUT_ADDR, (REG_PL_RD(IO_CTRL_CIF_DOUT_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)driverpullstate <<6));
}
__INLINE uint8_t io_ctrl_cif_dout_output_pad_strength_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_DOUT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000038)) >> 3);
}
__INLINE void io_ctrl_cif_dout_output_pad_strength_setf(uint8_t outputpadstrength)
{
	ASSERT_ERR((((uint32_t)outputpadstrength << 3) & ~((uint32_t)0x00000038)) == 0);
	REG_PL_WR(IO_CTRL_CIF_DOUT_ADDR, (REG_PL_RD(IO_CTRL_CIF_DOUT_ADDR) & ~((uint32_t)0x00000038)) | ((uint32_t)outputpadstrength <<3));
}
__INLINE uint8_t io_ctrl_cif_dout_mux_select_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_DOUT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void io_ctrl_cif_dout_mux_select_setf(uint8_t muxselect)
{
	ASSERT_ERR((((uint32_t)muxselect << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_CIF_DOUT_ADDR, (REG_PL_RD(IO_CTRL_CIF_DOUT_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)muxselect <<0));
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
#define IO_CTRL_CIF_FS_ADDR        (REG_IO_CTRL_BASE_ADDR+0x00000030)
#define IO_CTRL_CIF_FS_OFFSET      0x00000030
#define IO_CTRL_CIF_FS_INDEX       0x0000000C
#define IO_CTRL_CIF_FS_RESET       0x000009C8

__INLINE uint32_t  io_ctrl_cif_fs_get(void)
{
	return REG_PL_RD(IO_CTRL_CIF_FS_ADDR);
}

__INLINE void io_ctrl_cif_fs_set(uint32_t value)
{
	REG_PL_WR(IO_CTRL_CIF_FS_ADDR, value);
}

// field definitions
#define IO_CTRL_CIF_FS_GPIO_IN_BIT          ((uint32_t)0x00002000)
#define IO_CTRL_CIF_FS_GPIO_IN_POS          13
#define IO_CTRL_CIF_FS_GPIO_OUT_BIT         ((uint32_t)0x00001000)
#define IO_CTRL_CIF_FS_GPIO_OUT_POS         12
#define IO_CTRL_CIF_FS_GPIO_OE_BIT          ((uint32_t)0x00000800)
#define IO_CTRL_CIF_FS_GPIO_OE_POS          11
#define IO_CTRL_CIF_FS_GPIO_ENABLE_BIT      ((uint32_t)0x00000400)
#define IO_CTRL_CIF_FS_GPIO_ENABLE_POS      10
#define IO_CTRL_CIF_FS_INPUT_ENABLE_BIT     ((uint32_t)0x00000200)
#define IO_CTRL_CIF_FS_INPUT_ENABLE_POS     9
#define IO_CTRL_CIF_FS_DRIVER_PULL_STATE_MASK    ((uint32_t)0x000000C0)
#define IO_CTRL_CIF_FS_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_CIF_FS_DRIVER_PULL_STATE_WIDTH    ((uint32_t)0x00000002)
#define IO_CTRL_CIF_FS_OUTPUT_PAD_STRENGTH_MASK    ((uint32_t)0x00000038)
#define IO_CTRL_CIF_FS_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_CIF_FS_OUTPUT_PAD_STRENGTH_WIDTH    ((uint32_t)0x00000003)
#define IO_CTRL_CIF_FS_MUX_SELECT_MASK      ((uint32_t)0x00000007)
#define IO_CTRL_CIF_FS_MUX_SELECT_LSB       0
#define IO_CTRL_CIF_FS_MUX_SELECT_WIDTH     ((uint32_t)0x00000003)

#define IO_CTRL_CIF_FS_GPIO_IN_RST          0x1
#define IO_CTRL_CIF_FS_GPIO_OUT_RST         0x0
#define IO_CTRL_CIF_FS_GPIO_OE_RST          0x0
#define IO_CTRL_CIF_FS_GPIO_ENABLE_RST      0x1
#define IO_CTRL_CIF_FS_INPUT_ENABLE_RST     0x1
#define IO_CTRL_CIF_FS_DRIVER_PULL_STATE_RST    0x2
#define IO_CTRL_CIF_FS_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_CIF_FS_MUX_SELECT_RST       0x0

__INLINE void io_ctrl_cif_fs_pack(uint8_t gpio_in, uint8_t gpio_out, uint8_t gpio_oe, uint8_t gpio_enable, uint8_t input_enable, uint8_t driver_pull_state, uint8_t output_pad_strength, uint8_t mux_select)
{
	ASSERT_ERR((((uint32_t)gpio_in << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_out << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_oe << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)gpio_enable << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)input_enable << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)driver_pull_state << 6) & ~((uint32_t)0x000000C0)) == 0);
	ASSERT_ERR((((uint32_t)output_pad_strength << 3) & ~((uint32_t)0x00000038)) == 0);
	ASSERT_ERR((((uint32_t)mux_select << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_CIF_FS_ADDR,  ((uint32_t)gpio_in << 13) |((uint32_t)gpio_out << 12) |((uint32_t)gpio_oe << 11) |((uint32_t)gpio_enable << 10) |((uint32_t)input_enable << 9) |((uint32_t)driver_pull_state << 6) |((uint32_t)output_pad_strength << 3) |((uint32_t)mux_select << 0));
}

__INLINE void io_ctrl_cif_fs_unpack(uint8_t* gpio_in, uint8_t* gpio_out, uint8_t* gpio_oe, uint8_t* gpio_enable, uint8_t* input_enable, uint8_t* driver_pull_state, uint8_t* output_pad_strength, uint8_t* mux_select)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_FS_ADDR);

	*gpio_in = (localVal & ((uint32_t)0x00002000)) >>  13;
	*gpio_out = (localVal & ((uint32_t)0x00001000)) >>  12;
	*gpio_oe = (localVal & ((uint32_t)0x00000800)) >>  11;
	*gpio_enable = (localVal & ((uint32_t)0x00000400)) >>  10;
	*input_enable = (localVal & ((uint32_t)0x00000200)) >>  9;
	*driver_pull_state = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*output_pad_strength = (localVal & ((uint32_t)0x00000038)) >>  3;
	*mux_select = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t io_ctrl_cif_fs_gpio_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_FS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE uint8_t io_ctrl_cif_fs_gpio_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_FS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void io_ctrl_cif_fs_gpio_out_setf(uint8_t gpioout)
{
	ASSERT_ERR((((uint32_t)gpioout << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(IO_CTRL_CIF_FS_ADDR, (REG_PL_RD(IO_CTRL_CIF_FS_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)gpioout <<12));
}
__INLINE uint8_t io_ctrl_cif_fs_gpio_oe_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_FS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void io_ctrl_cif_fs_gpio_oe_setf(uint8_t gpiooe)
{
	ASSERT_ERR((((uint32_t)gpiooe << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(IO_CTRL_CIF_FS_ADDR, (REG_PL_RD(IO_CTRL_CIF_FS_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)gpiooe <<11));
}
__INLINE uint8_t io_ctrl_cif_fs_gpio_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_FS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void io_ctrl_cif_fs_gpio_enable_setf(uint8_t gpioenable)
{
	ASSERT_ERR((((uint32_t)gpioenable << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(IO_CTRL_CIF_FS_ADDR, (REG_PL_RD(IO_CTRL_CIF_FS_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)gpioenable <<10));
}
__INLINE uint8_t io_ctrl_cif_fs_input_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_FS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void io_ctrl_cif_fs_input_enable_setf(uint8_t inputenable)
{
	ASSERT_ERR((((uint32_t)inputenable << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(IO_CTRL_CIF_FS_ADDR, (REG_PL_RD(IO_CTRL_CIF_FS_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)inputenable <<9));
}
__INLINE uint8_t io_ctrl_cif_fs_driver_pull_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_FS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE void io_ctrl_cif_fs_driver_pull_state_setf(uint8_t driverpullstate)
{
	ASSERT_ERR((((uint32_t)driverpullstate << 6) & ~((uint32_t)0x000000C0)) == 0);
	REG_PL_WR(IO_CTRL_CIF_FS_ADDR, (REG_PL_RD(IO_CTRL_CIF_FS_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)driverpullstate <<6));
}
__INLINE uint8_t io_ctrl_cif_fs_output_pad_strength_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_FS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000038)) >> 3);
}
__INLINE void io_ctrl_cif_fs_output_pad_strength_setf(uint8_t outputpadstrength)
{
	ASSERT_ERR((((uint32_t)outputpadstrength << 3) & ~((uint32_t)0x00000038)) == 0);
	REG_PL_WR(IO_CTRL_CIF_FS_ADDR, (REG_PL_RD(IO_CTRL_CIF_FS_ADDR) & ~((uint32_t)0x00000038)) | ((uint32_t)outputpadstrength <<3));
}
__INLINE uint8_t io_ctrl_cif_fs_mux_select_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_FS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void io_ctrl_cif_fs_mux_select_setf(uint8_t muxselect)
{
	ASSERT_ERR((((uint32_t)muxselect << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_CIF_FS_ADDR, (REG_PL_RD(IO_CTRL_CIF_FS_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)muxselect <<0));
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
#define IO_CTRL_CIF_BCLK_ADDR        (REG_IO_CTRL_BASE_ADDR+0x00000034)
#define IO_CTRL_CIF_BCLK_OFFSET      0x00000034
#define IO_CTRL_CIF_BCLK_INDEX       0x0000000D
#define IO_CTRL_CIF_BCLK_RESET       0x000009C8

__INLINE uint32_t  io_ctrl_cif_bclk_get(void)
{
	return REG_PL_RD(IO_CTRL_CIF_BCLK_ADDR);
}

__INLINE void io_ctrl_cif_bclk_set(uint32_t value)
{
	REG_PL_WR(IO_CTRL_CIF_BCLK_ADDR, value);
}

// field definitions
#define IO_CTRL_CIF_BCLK_GPIO_IN_BIT        ((uint32_t)0x00002000)
#define IO_CTRL_CIF_BCLK_GPIO_IN_POS        13
#define IO_CTRL_CIF_BCLK_GPIO_OUT_BIT       ((uint32_t)0x00001000)
#define IO_CTRL_CIF_BCLK_GPIO_OUT_POS       12
#define IO_CTRL_CIF_BCLK_GPIO_OE_BIT        ((uint32_t)0x00000800)
#define IO_CTRL_CIF_BCLK_GPIO_OE_POS        11
#define IO_CTRL_CIF_BCLK_GPIO_ENABLE_BIT    ((uint32_t)0x00000400)
#define IO_CTRL_CIF_BCLK_GPIO_ENABLE_POS    10
#define IO_CTRL_CIF_BCLK_INPUT_ENABLE_BIT    ((uint32_t)0x00000200)
#define IO_CTRL_CIF_BCLK_INPUT_ENABLE_POS    9
#define IO_CTRL_CIF_BCLK_DRIVER_PULL_STATE_MASK    ((uint32_t)0x000000C0)
#define IO_CTRL_CIF_BCLK_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_CIF_BCLK_DRIVER_PULL_STATE_WIDTH    ((uint32_t)0x00000002)
#define IO_CTRL_CIF_BCLK_OUTPUT_PAD_STRENGTH_MASK    ((uint32_t)0x00000038)
#define IO_CTRL_CIF_BCLK_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_CIF_BCLK_OUTPUT_PAD_STRENGTH_WIDTH    ((uint32_t)0x00000003)
#define IO_CTRL_CIF_BCLK_MUX_SELECT_MASK    ((uint32_t)0x00000007)
#define IO_CTRL_CIF_BCLK_MUX_SELECT_LSB     0
#define IO_CTRL_CIF_BCLK_MUX_SELECT_WIDTH    ((uint32_t)0x00000003)

#define IO_CTRL_CIF_BCLK_GPIO_IN_RST        0x1
#define IO_CTRL_CIF_BCLK_GPIO_OUT_RST       0x0
#define IO_CTRL_CIF_BCLK_GPIO_OE_RST        0x0
#define IO_CTRL_CIF_BCLK_GPIO_ENABLE_RST    0x1
#define IO_CTRL_CIF_BCLK_INPUT_ENABLE_RST    0x1
#define IO_CTRL_CIF_BCLK_DRIVER_PULL_STATE_RST    0x2
#define IO_CTRL_CIF_BCLK_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_CIF_BCLK_MUX_SELECT_RST     0x0

__INLINE void io_ctrl_cif_bclk_pack(uint8_t gpio_in, uint8_t gpio_out, uint8_t gpio_oe, uint8_t gpio_enable, uint8_t input_enable, uint8_t driver_pull_state, uint8_t output_pad_strength, uint8_t mux_select)
{
	ASSERT_ERR((((uint32_t)gpio_in << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_out << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_oe << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)gpio_enable << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)input_enable << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)driver_pull_state << 6) & ~((uint32_t)0x000000C0)) == 0);
	ASSERT_ERR((((uint32_t)output_pad_strength << 3) & ~((uint32_t)0x00000038)) == 0);
	ASSERT_ERR((((uint32_t)mux_select << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_CIF_BCLK_ADDR,  ((uint32_t)gpio_in << 13) |((uint32_t)gpio_out << 12) |((uint32_t)gpio_oe << 11) |((uint32_t)gpio_enable << 10) |((uint32_t)input_enable << 9) |((uint32_t)driver_pull_state << 6) |((uint32_t)output_pad_strength << 3) |((uint32_t)mux_select << 0));
}

__INLINE void io_ctrl_cif_bclk_unpack(uint8_t* gpio_in, uint8_t* gpio_out, uint8_t* gpio_oe, uint8_t* gpio_enable, uint8_t* input_enable, uint8_t* driver_pull_state, uint8_t* output_pad_strength, uint8_t* mux_select)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_BCLK_ADDR);

	*gpio_in = (localVal & ((uint32_t)0x00002000)) >>  13;
	*gpio_out = (localVal & ((uint32_t)0x00001000)) >>  12;
	*gpio_oe = (localVal & ((uint32_t)0x00000800)) >>  11;
	*gpio_enable = (localVal & ((uint32_t)0x00000400)) >>  10;
	*input_enable = (localVal & ((uint32_t)0x00000200)) >>  9;
	*driver_pull_state = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*output_pad_strength = (localVal & ((uint32_t)0x00000038)) >>  3;
	*mux_select = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t io_ctrl_cif_bclk_gpio_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_BCLK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE uint8_t io_ctrl_cif_bclk_gpio_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_BCLK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void io_ctrl_cif_bclk_gpio_out_setf(uint8_t gpioout)
{
	ASSERT_ERR((((uint32_t)gpioout << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(IO_CTRL_CIF_BCLK_ADDR, (REG_PL_RD(IO_CTRL_CIF_BCLK_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)gpioout <<12));
}
__INLINE uint8_t io_ctrl_cif_bclk_gpio_oe_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_BCLK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void io_ctrl_cif_bclk_gpio_oe_setf(uint8_t gpiooe)
{
	ASSERT_ERR((((uint32_t)gpiooe << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(IO_CTRL_CIF_BCLK_ADDR, (REG_PL_RD(IO_CTRL_CIF_BCLK_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)gpiooe <<11));
}
__INLINE uint8_t io_ctrl_cif_bclk_gpio_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_BCLK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void io_ctrl_cif_bclk_gpio_enable_setf(uint8_t gpioenable)
{
	ASSERT_ERR((((uint32_t)gpioenable << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(IO_CTRL_CIF_BCLK_ADDR, (REG_PL_RD(IO_CTRL_CIF_BCLK_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)gpioenable <<10));
}
__INLINE uint8_t io_ctrl_cif_bclk_input_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_BCLK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void io_ctrl_cif_bclk_input_enable_setf(uint8_t inputenable)
{
	ASSERT_ERR((((uint32_t)inputenable << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(IO_CTRL_CIF_BCLK_ADDR, (REG_PL_RD(IO_CTRL_CIF_BCLK_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)inputenable <<9));
}
__INLINE uint8_t io_ctrl_cif_bclk_driver_pull_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_BCLK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE void io_ctrl_cif_bclk_driver_pull_state_setf(uint8_t driverpullstate)
{
	ASSERT_ERR((((uint32_t)driverpullstate << 6) & ~((uint32_t)0x000000C0)) == 0);
	REG_PL_WR(IO_CTRL_CIF_BCLK_ADDR, (REG_PL_RD(IO_CTRL_CIF_BCLK_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)driverpullstate <<6));
}
__INLINE uint8_t io_ctrl_cif_bclk_output_pad_strength_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_BCLK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000038)) >> 3);
}
__INLINE void io_ctrl_cif_bclk_output_pad_strength_setf(uint8_t outputpadstrength)
{
	ASSERT_ERR((((uint32_t)outputpadstrength << 3) & ~((uint32_t)0x00000038)) == 0);
	REG_PL_WR(IO_CTRL_CIF_BCLK_ADDR, (REG_PL_RD(IO_CTRL_CIF_BCLK_ADDR) & ~((uint32_t)0x00000038)) | ((uint32_t)outputpadstrength <<3));
}
__INLINE uint8_t io_ctrl_cif_bclk_mux_select_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_BCLK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void io_ctrl_cif_bclk_mux_select_setf(uint8_t muxselect)
{
	ASSERT_ERR((((uint32_t)muxselect << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_CIF_BCLK_ADDR, (REG_PL_RD(IO_CTRL_CIF_BCLK_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)muxselect <<0));
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
#define IO_CTRL_CIF_MCLK_ADDR        (REG_IO_CTRL_BASE_ADDR+0x00000038)
#define IO_CTRL_CIF_MCLK_OFFSET      0x00000038
#define IO_CTRL_CIF_MCLK_INDEX       0x0000000E
#define IO_CTRL_CIF_MCLK_RESET       0x000019C8

__INLINE uint32_t  io_ctrl_cif_mclk_get(void)
{
	return REG_PL_RD(IO_CTRL_CIF_MCLK_ADDR);
}

__INLINE void io_ctrl_cif_mclk_set(uint32_t value)
{
	REG_PL_WR(IO_CTRL_CIF_MCLK_ADDR, value);
}

// field definitions
#define IO_CTRL_CIF_MCLK_USB_SPEED_BIT      ((uint32_t)0x00004000)
#define IO_CTRL_CIF_MCLK_USB_SPEED_POS      14
#define IO_CTRL_CIF_MCLK_GPIO_IN_BIT        ((uint32_t)0x00002000)
#define IO_CTRL_CIF_MCLK_GPIO_IN_POS        13
#define IO_CTRL_CIF_MCLK_GPIO_OUT_BIT       ((uint32_t)0x00001000)
#define IO_CTRL_CIF_MCLK_GPIO_OUT_POS       12
#define IO_CTRL_CIF_MCLK_GPIO_OE_BIT        ((uint32_t)0x00000800)
#define IO_CTRL_CIF_MCLK_GPIO_OE_POS        11
#define IO_CTRL_CIF_MCLK_GPIO_ENABLE_BIT    ((uint32_t)0x00000400)
#define IO_CTRL_CIF_MCLK_GPIO_ENABLE_POS    10
#define IO_CTRL_CIF_MCLK_INPUT_ENABLE_BIT    ((uint32_t)0x00000200)
#define IO_CTRL_CIF_MCLK_INPUT_ENABLE_POS    9
#define IO_CTRL_CIF_MCLK_DRIVER_PULL_STATE_MASK    ((uint32_t)0x000000C0)
#define IO_CTRL_CIF_MCLK_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_CIF_MCLK_DRIVER_PULL_STATE_WIDTH    ((uint32_t)0x00000002)
#define IO_CTRL_CIF_MCLK_OUTPUT_PAD_STRENGTH_MASK    ((uint32_t)0x00000038)
#define IO_CTRL_CIF_MCLK_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_CIF_MCLK_OUTPUT_PAD_STRENGTH_WIDTH    ((uint32_t)0x00000003)
#define IO_CTRL_CIF_MCLK_MUX_SELECT_MASK    ((uint32_t)0x00000007)
#define IO_CTRL_CIF_MCLK_MUX_SELECT_LSB     0
#define IO_CTRL_CIF_MCLK_MUX_SELECT_WIDTH    ((uint32_t)0x00000003)

#define IO_CTRL_CIF_MCLK_USB_SPEED_RST      0x1
#define IO_CTRL_CIF_MCLK_GPIO_IN_RST        0x1
#define IO_CTRL_CIF_MCLK_GPIO_OUT_RST       0x0
#define IO_CTRL_CIF_MCLK_GPIO_OE_RST        0x0
#define IO_CTRL_CIF_MCLK_GPIO_ENABLE_RST    0x1
#define IO_CTRL_CIF_MCLK_INPUT_ENABLE_RST    0x1
#define IO_CTRL_CIF_MCLK_DRIVER_PULL_STATE_RST    0x2
#define IO_CTRL_CIF_MCLK_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_CIF_MCLK_MUX_SELECT_RST     0x0

__INLINE void io_ctrl_cif_mclk_pack(uint8_t usb_speed, uint8_t gpio_in, uint8_t gpio_out, uint8_t gpio_oe, uint8_t gpio_enable, uint8_t input_enable, uint8_t driver_pull_state, uint8_t output_pad_strength, uint8_t mux_select)
{
	ASSERT_ERR((((uint32_t)usb_speed << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_in << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_out << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_oe << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)gpio_enable << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)input_enable << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)driver_pull_state << 6) & ~((uint32_t)0x000000C0)) == 0);
	ASSERT_ERR((((uint32_t)output_pad_strength << 3) & ~((uint32_t)0x00000038)) == 0);
	ASSERT_ERR((((uint32_t)mux_select << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_CIF_MCLK_ADDR,  ((uint32_t)usb_speed << 14) |((uint32_t)gpio_in << 13) |((uint32_t)gpio_out << 12) |((uint32_t)gpio_oe << 11) |((uint32_t)gpio_enable << 10) |((uint32_t)input_enable << 9) |((uint32_t)driver_pull_state << 6) |((uint32_t)output_pad_strength << 3) |((uint32_t)mux_select << 0));
}

__INLINE void io_ctrl_cif_mclk_unpack(uint8_t* usb_speed, uint8_t* gpio_in, uint8_t* gpio_out, uint8_t* gpio_oe, uint8_t* gpio_enable, uint8_t* input_enable, uint8_t* driver_pull_state, uint8_t* output_pad_strength, uint8_t* mux_select)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_MCLK_ADDR);

	*usb_speed = (localVal & ((uint32_t)0x00004000)) >>  14;
	*gpio_in = (localVal & ((uint32_t)0x00002000)) >>  13;
	*gpio_out = (localVal & ((uint32_t)0x00001000)) >>  12;
	*gpio_oe = (localVal & ((uint32_t)0x00000800)) >>  11;
	*gpio_enable = (localVal & ((uint32_t)0x00000400)) >>  10;
	*input_enable = (localVal & ((uint32_t)0x00000200)) >>  9;
	*driver_pull_state = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*output_pad_strength = (localVal & ((uint32_t)0x00000038)) >>  3;
	*mux_select = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t io_ctrl_cif_mclk_usb_speed_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_MCLK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE uint8_t io_ctrl_cif_mclk_gpio_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_MCLK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE uint8_t io_ctrl_cif_mclk_gpio_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_MCLK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void io_ctrl_cif_mclk_gpio_out_setf(uint8_t gpioout)
{
	ASSERT_ERR((((uint32_t)gpioout << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(IO_CTRL_CIF_MCLK_ADDR, (REG_PL_RD(IO_CTRL_CIF_MCLK_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)gpioout <<12));
}
__INLINE uint8_t io_ctrl_cif_mclk_gpio_oe_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_MCLK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void io_ctrl_cif_mclk_gpio_oe_setf(uint8_t gpiooe)
{
	ASSERT_ERR((((uint32_t)gpiooe << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(IO_CTRL_CIF_MCLK_ADDR, (REG_PL_RD(IO_CTRL_CIF_MCLK_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)gpiooe <<11));
}
__INLINE uint8_t io_ctrl_cif_mclk_gpio_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_MCLK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void io_ctrl_cif_mclk_gpio_enable_setf(uint8_t gpioenable)
{
	ASSERT_ERR((((uint32_t)gpioenable << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(IO_CTRL_CIF_MCLK_ADDR, (REG_PL_RD(IO_CTRL_CIF_MCLK_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)gpioenable <<10));
}
__INLINE uint8_t io_ctrl_cif_mclk_input_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_MCLK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void io_ctrl_cif_mclk_input_enable_setf(uint8_t inputenable)
{
	ASSERT_ERR((((uint32_t)inputenable << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(IO_CTRL_CIF_MCLK_ADDR, (REG_PL_RD(IO_CTRL_CIF_MCLK_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)inputenable <<9));
}
__INLINE uint8_t io_ctrl_cif_mclk_driver_pull_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_MCLK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE void io_ctrl_cif_mclk_driver_pull_state_setf(uint8_t driverpullstate)
{
	ASSERT_ERR((((uint32_t)driverpullstate << 6) & ~((uint32_t)0x000000C0)) == 0);
	REG_PL_WR(IO_CTRL_CIF_MCLK_ADDR, (REG_PL_RD(IO_CTRL_CIF_MCLK_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)driverpullstate <<6));
}
__INLINE uint8_t io_ctrl_cif_mclk_output_pad_strength_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_MCLK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000038)) >> 3);
}
__INLINE void io_ctrl_cif_mclk_output_pad_strength_setf(uint8_t outputpadstrength)
{
	ASSERT_ERR((((uint32_t)outputpadstrength << 3) & ~((uint32_t)0x00000038)) == 0);
	REG_PL_WR(IO_CTRL_CIF_MCLK_ADDR, (REG_PL_RD(IO_CTRL_CIF_MCLK_ADDR) & ~((uint32_t)0x00000038)) | ((uint32_t)outputpadstrength <<3));
}
__INLINE uint8_t io_ctrl_cif_mclk_mux_select_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CIF_MCLK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void io_ctrl_cif_mclk_mux_select_setf(uint8_t muxselect)
{
	ASSERT_ERR((((uint32_t)muxselect << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_CIF_MCLK_ADDR, (REG_PL_RD(IO_CTRL_CIF_MCLK_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)muxselect <<0));
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
#define IO_CTRL_RTS_N_ADDR        (REG_IO_CTRL_BASE_ADDR+0x0000003C)
#define IO_CTRL_RTS_N_OFFSET      0x0000003C
#define IO_CTRL_RTS_N_INDEX       0x0000000F
#define IO_CTRL_RTS_N_RESET       0x000009C8

__INLINE uint32_t  io_ctrl_rts_n_get(void)
{
	return REG_PL_RD(IO_CTRL_RTS_N_ADDR);
}

__INLINE void io_ctrl_rts_n_set(uint32_t value)
{
	REG_PL_WR(IO_CTRL_RTS_N_ADDR, value);
}

// field definitions
#define IO_CTRL_RTS_N_GPIO_IN_BIT           ((uint32_t)0x00002000)
#define IO_CTRL_RTS_N_GPIO_IN_POS           13
#define IO_CTRL_RTS_N_GPIO_OUT_BIT          ((uint32_t)0x00001000)
#define IO_CTRL_RTS_N_GPIO_OUT_POS          12
#define IO_CTRL_RTS_N_GPIO_OE_BIT           ((uint32_t)0x00000800)
#define IO_CTRL_RTS_N_GPIO_OE_POS           11
#define IO_CTRL_RTS_N_GPIO_ENABLE_BIT       ((uint32_t)0x00000400)
#define IO_CTRL_RTS_N_GPIO_ENABLE_POS       10
#define IO_CTRL_RTS_N_INPUT_ENABLE_BIT      ((uint32_t)0x00000200)
#define IO_CTRL_RTS_N_INPUT_ENABLE_POS      9
#define IO_CTRL_RTS_N_DRIVER_PULL_STATE_MASK    ((uint32_t)0x000000C0)
#define IO_CTRL_RTS_N_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_RTS_N_DRIVER_PULL_STATE_WIDTH    ((uint32_t)0x00000002)
#define IO_CTRL_RTS_N_OUTPUT_PAD_STRENGTH_MASK    ((uint32_t)0x00000038)
#define IO_CTRL_RTS_N_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_RTS_N_OUTPUT_PAD_STRENGTH_WIDTH    ((uint32_t)0x00000003)
#define IO_CTRL_RTS_N_MUX_SELECT_MASK       ((uint32_t)0x00000007)
#define IO_CTRL_RTS_N_MUX_SELECT_LSB        0
#define IO_CTRL_RTS_N_MUX_SELECT_WIDTH      ((uint32_t)0x00000003)

#define IO_CTRL_RTS_N_GPIO_IN_RST           0x1
#define IO_CTRL_RTS_N_GPIO_OUT_RST          0x0
#define IO_CTRL_RTS_N_GPIO_OE_RST           0x0
#define IO_CTRL_RTS_N_GPIO_ENABLE_RST       0x1
#define IO_CTRL_RTS_N_INPUT_ENABLE_RST      0x1
#define IO_CTRL_RTS_N_DRIVER_PULL_STATE_RST    0x2
#define IO_CTRL_RTS_N_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_RTS_N_MUX_SELECT_RST        0x0

__INLINE void io_ctrl_rts_n_pack(uint8_t gpio_in, uint8_t gpio_out, uint8_t gpio_oe, uint8_t gpio_enable, uint8_t input_enable, uint8_t driver_pull_state, uint8_t output_pad_strength, uint8_t mux_select)
{
	ASSERT_ERR((((uint32_t)gpio_in << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_out << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_oe << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)gpio_enable << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)input_enable << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)driver_pull_state << 6) & ~((uint32_t)0x000000C0)) == 0);
	ASSERT_ERR((((uint32_t)output_pad_strength << 3) & ~((uint32_t)0x00000038)) == 0);
	ASSERT_ERR((((uint32_t)mux_select << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_RTS_N_ADDR,  ((uint32_t)gpio_in << 13) |((uint32_t)gpio_out << 12) |((uint32_t)gpio_oe << 11) |((uint32_t)gpio_enable << 10) |((uint32_t)input_enable << 9) |((uint32_t)driver_pull_state << 6) |((uint32_t)output_pad_strength << 3) |((uint32_t)mux_select << 0));
}

__INLINE void io_ctrl_rts_n_unpack(uint8_t* gpio_in, uint8_t* gpio_out, uint8_t* gpio_oe, uint8_t* gpio_enable, uint8_t* input_enable, uint8_t* driver_pull_state, uint8_t* output_pad_strength, uint8_t* mux_select)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_RTS_N_ADDR);

	*gpio_in = (localVal & ((uint32_t)0x00002000)) >>  13;
	*gpio_out = (localVal & ((uint32_t)0x00001000)) >>  12;
	*gpio_oe = (localVal & ((uint32_t)0x00000800)) >>  11;
	*gpio_enable = (localVal & ((uint32_t)0x00000400)) >>  10;
	*input_enable = (localVal & ((uint32_t)0x00000200)) >>  9;
	*driver_pull_state = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*output_pad_strength = (localVal & ((uint32_t)0x00000038)) >>  3;
	*mux_select = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t io_ctrl_rts_n_gpio_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_RTS_N_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE uint8_t io_ctrl_rts_n_gpio_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_RTS_N_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void io_ctrl_rts_n_gpio_out_setf(uint8_t gpioout)
{
	ASSERT_ERR((((uint32_t)gpioout << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(IO_CTRL_RTS_N_ADDR, (REG_PL_RD(IO_CTRL_RTS_N_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)gpioout <<12));
}
__INLINE uint8_t io_ctrl_rts_n_gpio_oe_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_RTS_N_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void io_ctrl_rts_n_gpio_oe_setf(uint8_t gpiooe)
{
	ASSERT_ERR((((uint32_t)gpiooe << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(IO_CTRL_RTS_N_ADDR, (REG_PL_RD(IO_CTRL_RTS_N_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)gpiooe <<11));
}
__INLINE uint8_t io_ctrl_rts_n_gpio_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_RTS_N_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void io_ctrl_rts_n_gpio_enable_setf(uint8_t gpioenable)
{
	ASSERT_ERR((((uint32_t)gpioenable << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(IO_CTRL_RTS_N_ADDR, (REG_PL_RD(IO_CTRL_RTS_N_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)gpioenable <<10));
}
__INLINE uint8_t io_ctrl_rts_n_input_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_RTS_N_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void io_ctrl_rts_n_input_enable_setf(uint8_t inputenable)
{
	ASSERT_ERR((((uint32_t)inputenable << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(IO_CTRL_RTS_N_ADDR, (REG_PL_RD(IO_CTRL_RTS_N_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)inputenable <<9));
}
__INLINE uint8_t io_ctrl_rts_n_driver_pull_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_RTS_N_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE void io_ctrl_rts_n_driver_pull_state_setf(uint8_t driverpullstate)
{
	ASSERT_ERR((((uint32_t)driverpullstate << 6) & ~((uint32_t)0x000000C0)) == 0);
	REG_PL_WR(IO_CTRL_RTS_N_ADDR, (REG_PL_RD(IO_CTRL_RTS_N_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)driverpullstate <<6));
}
__INLINE uint8_t io_ctrl_rts_n_output_pad_strength_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_RTS_N_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000038)) >> 3);
}
__INLINE void io_ctrl_rts_n_output_pad_strength_setf(uint8_t outputpadstrength)
{
	ASSERT_ERR((((uint32_t)outputpadstrength << 3) & ~((uint32_t)0x00000038)) == 0);
	REG_PL_WR(IO_CTRL_RTS_N_ADDR, (REG_PL_RD(IO_CTRL_RTS_N_ADDR) & ~((uint32_t)0x00000038)) | ((uint32_t)outputpadstrength <<3));
}
__INLINE uint8_t io_ctrl_rts_n_mux_select_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_RTS_N_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void io_ctrl_rts_n_mux_select_setf(uint8_t muxselect)
{
	ASSERT_ERR((((uint32_t)muxselect << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_RTS_N_ADDR, (REG_PL_RD(IO_CTRL_RTS_N_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)muxselect <<0));
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
#define IO_CTRL_CTS_N_ADDR        (REG_IO_CTRL_BASE_ADDR+0x00000040)
#define IO_CTRL_CTS_N_OFFSET      0x00000040
#define IO_CTRL_CTS_N_INDEX       0x00000010
#define IO_CTRL_CTS_N_RESET       0x000009C8

__INLINE uint32_t  io_ctrl_cts_n_get(void)
{
	return REG_PL_RD(IO_CTRL_CTS_N_ADDR);
}

__INLINE void io_ctrl_cts_n_set(uint32_t value)
{
	REG_PL_WR(IO_CTRL_CTS_N_ADDR, value);
}

// field definitions
#define IO_CTRL_CTS_N_GPIO_IN_BIT           ((uint32_t)0x00002000)
#define IO_CTRL_CTS_N_GPIO_IN_POS           13
#define IO_CTRL_CTS_N_GPIO_OUT_BIT          ((uint32_t)0x00001000)
#define IO_CTRL_CTS_N_GPIO_OUT_POS          12
#define IO_CTRL_CTS_N_GPIO_OE_BIT           ((uint32_t)0x00000800)
#define IO_CTRL_CTS_N_GPIO_OE_POS           11
#define IO_CTRL_CTS_N_GPIO_ENABLE_BIT       ((uint32_t)0x00000400)
#define IO_CTRL_CTS_N_GPIO_ENABLE_POS       10
#define IO_CTRL_CTS_N_INPUT_ENABLE_BIT      ((uint32_t)0x00000200)
#define IO_CTRL_CTS_N_INPUT_ENABLE_POS      9
#define IO_CTRL_CTS_N_DRIVER_PULL_STATE_MASK    ((uint32_t)0x000000C0)
#define IO_CTRL_CTS_N_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_CTS_N_DRIVER_PULL_STATE_WIDTH    ((uint32_t)0x00000002)
#define IO_CTRL_CTS_N_OUTPUT_PAD_STRENGTH_MASK    ((uint32_t)0x00000038)
#define IO_CTRL_CTS_N_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_CTS_N_OUTPUT_PAD_STRENGTH_WIDTH    ((uint32_t)0x00000003)
#define IO_CTRL_CTS_N_MUX_SELECT_MASK       ((uint32_t)0x00000007)
#define IO_CTRL_CTS_N_MUX_SELECT_LSB        0
#define IO_CTRL_CTS_N_MUX_SELECT_WIDTH      ((uint32_t)0x00000003)

#define IO_CTRL_CTS_N_GPIO_IN_RST           0x1
#define IO_CTRL_CTS_N_GPIO_OUT_RST          0x0
#define IO_CTRL_CTS_N_GPIO_OE_RST           0x0
#define IO_CTRL_CTS_N_GPIO_ENABLE_RST       0x1
#define IO_CTRL_CTS_N_INPUT_ENABLE_RST      0x1
#define IO_CTRL_CTS_N_DRIVER_PULL_STATE_RST    0x2
#define IO_CTRL_CTS_N_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_CTS_N_MUX_SELECT_RST        0x0

__INLINE void io_ctrl_cts_n_pack(uint8_t gpio_in, uint8_t gpio_out, uint8_t gpio_oe, uint8_t gpio_enable, uint8_t input_enable, uint8_t driver_pull_state, uint8_t output_pad_strength, uint8_t mux_select)
{
	ASSERT_ERR((((uint32_t)gpio_in << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_out << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_oe << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)gpio_enable << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)input_enable << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)driver_pull_state << 6) & ~((uint32_t)0x000000C0)) == 0);
	ASSERT_ERR((((uint32_t)output_pad_strength << 3) & ~((uint32_t)0x00000038)) == 0);
	ASSERT_ERR((((uint32_t)mux_select << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_CTS_N_ADDR,  ((uint32_t)gpio_in << 13) |((uint32_t)gpio_out << 12) |((uint32_t)gpio_oe << 11) |((uint32_t)gpio_enable << 10) |((uint32_t)input_enable << 9) |((uint32_t)driver_pull_state << 6) |((uint32_t)output_pad_strength << 3) |((uint32_t)mux_select << 0));
}

__INLINE void io_ctrl_cts_n_unpack(uint8_t* gpio_in, uint8_t* gpio_out, uint8_t* gpio_oe, uint8_t* gpio_enable, uint8_t* input_enable, uint8_t* driver_pull_state, uint8_t* output_pad_strength, uint8_t* mux_select)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CTS_N_ADDR);

	*gpio_in = (localVal & ((uint32_t)0x00002000)) >>  13;
	*gpio_out = (localVal & ((uint32_t)0x00001000)) >>  12;
	*gpio_oe = (localVal & ((uint32_t)0x00000800)) >>  11;
	*gpio_enable = (localVal & ((uint32_t)0x00000400)) >>  10;
	*input_enable = (localVal & ((uint32_t)0x00000200)) >>  9;
	*driver_pull_state = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*output_pad_strength = (localVal & ((uint32_t)0x00000038)) >>  3;
	*mux_select = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t io_ctrl_cts_n_gpio_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CTS_N_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE uint8_t io_ctrl_cts_n_gpio_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CTS_N_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void io_ctrl_cts_n_gpio_out_setf(uint8_t gpioout)
{
	ASSERT_ERR((((uint32_t)gpioout << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(IO_CTRL_CTS_N_ADDR, (REG_PL_RD(IO_CTRL_CTS_N_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)gpioout <<12));
}
__INLINE uint8_t io_ctrl_cts_n_gpio_oe_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CTS_N_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void io_ctrl_cts_n_gpio_oe_setf(uint8_t gpiooe)
{
	ASSERT_ERR((((uint32_t)gpiooe << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(IO_CTRL_CTS_N_ADDR, (REG_PL_RD(IO_CTRL_CTS_N_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)gpiooe <<11));
}
__INLINE uint8_t io_ctrl_cts_n_gpio_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CTS_N_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void io_ctrl_cts_n_gpio_enable_setf(uint8_t gpioenable)
{
	ASSERT_ERR((((uint32_t)gpioenable << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(IO_CTRL_CTS_N_ADDR, (REG_PL_RD(IO_CTRL_CTS_N_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)gpioenable <<10));
}
__INLINE uint8_t io_ctrl_cts_n_input_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CTS_N_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void io_ctrl_cts_n_input_enable_setf(uint8_t inputenable)
{
	ASSERT_ERR((((uint32_t)inputenable << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(IO_CTRL_CTS_N_ADDR, (REG_PL_RD(IO_CTRL_CTS_N_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)inputenable <<9));
}
__INLINE uint8_t io_ctrl_cts_n_driver_pull_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CTS_N_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE void io_ctrl_cts_n_driver_pull_state_setf(uint8_t driverpullstate)
{
	ASSERT_ERR((((uint32_t)driverpullstate << 6) & ~((uint32_t)0x000000C0)) == 0);
	REG_PL_WR(IO_CTRL_CTS_N_ADDR, (REG_PL_RD(IO_CTRL_CTS_N_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)driverpullstate <<6));
}
__INLINE uint8_t io_ctrl_cts_n_output_pad_strength_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CTS_N_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000038)) >> 3);
}
__INLINE void io_ctrl_cts_n_output_pad_strength_setf(uint8_t outputpadstrength)
{
	ASSERT_ERR((((uint32_t)outputpadstrength << 3) & ~((uint32_t)0x00000038)) == 0);
	REG_PL_WR(IO_CTRL_CTS_N_ADDR, (REG_PL_RD(IO_CTRL_CTS_N_ADDR) & ~((uint32_t)0x00000038)) | ((uint32_t)outputpadstrength <<3));
}
__INLINE uint8_t io_ctrl_cts_n_mux_select_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_CTS_N_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void io_ctrl_cts_n_mux_select_setf(uint8_t muxselect)
{
	ASSERT_ERR((((uint32_t)muxselect << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_CTS_N_ADDR, (REG_PL_RD(IO_CTRL_CTS_N_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)muxselect <<0));
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
#define IO_CTRL_TXD_ADDR        (REG_IO_CTRL_BASE_ADDR+0x00000044)
#define IO_CTRL_TXD_OFFSET      0x00000044
#define IO_CTRL_TXD_INDEX       0x00000011
#define IO_CTRL_TXD_RESET       0x000001A8

__INLINE uint32_t  io_ctrl_txd_get(void)
{
	return REG_PL_RD(IO_CTRL_TXD_ADDR);
}

__INLINE void io_ctrl_txd_set(uint32_t value)
{
	REG_PL_WR(IO_CTRL_TXD_ADDR, value);
}

// field definitions
#define IO_CTRL_TXD_GPIO_IN_BIT             ((uint32_t)0x00002000)
#define IO_CTRL_TXD_GPIO_IN_POS             13
#define IO_CTRL_TXD_GPIO_OUT_BIT            ((uint32_t)0x00001000)
#define IO_CTRL_TXD_GPIO_OUT_POS            12
#define IO_CTRL_TXD_GPIO_OE_BIT             ((uint32_t)0x00000800)
#define IO_CTRL_TXD_GPIO_OE_POS             11
#define IO_CTRL_TXD_GPIO_ENABLE_BIT         ((uint32_t)0x00000400)
#define IO_CTRL_TXD_GPIO_ENABLE_POS         10
#define IO_CTRL_TXD_INPUT_ENABLE_BIT        ((uint32_t)0x00000200)
#define IO_CTRL_TXD_INPUT_ENABLE_POS        9
#define IO_CTRL_TXD_DRIVER_PULL_STATE_MASK    ((uint32_t)0x000000C0)
#define IO_CTRL_TXD_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_TXD_DRIVER_PULL_STATE_WIDTH    ((uint32_t)0x00000002)
#define IO_CTRL_TXD_OUTPUT_PAD_STRENGTH_MASK    ((uint32_t)0x00000038)
#define IO_CTRL_TXD_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_TXD_OUTPUT_PAD_STRENGTH_WIDTH    ((uint32_t)0x00000003)
#define IO_CTRL_TXD_MUX_SELECT_MASK         ((uint32_t)0x00000007)
#define IO_CTRL_TXD_MUX_SELECT_LSB          0
#define IO_CTRL_TXD_MUX_SELECT_WIDTH        ((uint32_t)0x00000003)

#define IO_CTRL_TXD_GPIO_IN_RST             0x0
#define IO_CTRL_TXD_GPIO_OUT_RST            0x0
#define IO_CTRL_TXD_GPIO_OE_RST             0x0
#define IO_CTRL_TXD_GPIO_ENABLE_RST         0x1
#define IO_CTRL_TXD_INPUT_ENABLE_RST        0x1
#define IO_CTRL_TXD_DRIVER_PULL_STATE_RST    0x1
#define IO_CTRL_TXD_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_TXD_MUX_SELECT_RST          0x0

__INLINE void io_ctrl_txd_pack(uint8_t gpio_in, uint8_t gpio_out, uint8_t gpio_oe, uint8_t gpio_enable, uint8_t input_enable, uint8_t driver_pull_state, uint8_t output_pad_strength, uint8_t mux_select)
{
	ASSERT_ERR((((uint32_t)gpio_in << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_out << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_oe << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)gpio_enable << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)input_enable << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)driver_pull_state << 6) & ~((uint32_t)0x000000C0)) == 0);
	ASSERT_ERR((((uint32_t)output_pad_strength << 3) & ~((uint32_t)0x00000038)) == 0);
	ASSERT_ERR((((uint32_t)mux_select << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_TXD_ADDR,  ((uint32_t)gpio_in << 13) |((uint32_t)gpio_out << 12) |((uint32_t)gpio_oe << 11) |((uint32_t)gpio_enable << 10) |((uint32_t)input_enable << 9) |((uint32_t)driver_pull_state << 6) |((uint32_t)output_pad_strength << 3) |((uint32_t)mux_select << 0));
}

__INLINE void io_ctrl_txd_unpack(uint8_t* gpio_in, uint8_t* gpio_out, uint8_t* gpio_oe, uint8_t* gpio_enable, uint8_t* input_enable, uint8_t* driver_pull_state, uint8_t* output_pad_strength, uint8_t* mux_select)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TXD_ADDR);

	*gpio_in = (localVal & ((uint32_t)0x00002000)) >>  13;
	*gpio_out = (localVal & ((uint32_t)0x00001000)) >>  12;
	*gpio_oe = (localVal & ((uint32_t)0x00000800)) >>  11;
	*gpio_enable = (localVal & ((uint32_t)0x00000400)) >>  10;
	*input_enable = (localVal & ((uint32_t)0x00000200)) >>  9;
	*driver_pull_state = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*output_pad_strength = (localVal & ((uint32_t)0x00000038)) >>  3;
	*mux_select = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t io_ctrl_txd_gpio_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TXD_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE uint8_t io_ctrl_txd_gpio_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TXD_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void io_ctrl_txd_gpio_out_setf(uint8_t gpioout)
{
	ASSERT_ERR((((uint32_t)gpioout << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(IO_CTRL_TXD_ADDR, (REG_PL_RD(IO_CTRL_TXD_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)gpioout <<12));
}
__INLINE uint8_t io_ctrl_txd_gpio_oe_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TXD_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void io_ctrl_txd_gpio_oe_setf(uint8_t gpiooe)
{
	ASSERT_ERR((((uint32_t)gpiooe << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(IO_CTRL_TXD_ADDR, (REG_PL_RD(IO_CTRL_TXD_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)gpiooe <<11));
}
__INLINE uint8_t io_ctrl_txd_gpio_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TXD_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void io_ctrl_txd_gpio_enable_setf(uint8_t gpioenable)
{
	ASSERT_ERR((((uint32_t)gpioenable << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(IO_CTRL_TXD_ADDR, (REG_PL_RD(IO_CTRL_TXD_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)gpioenable <<10));
}
__INLINE uint8_t io_ctrl_txd_input_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TXD_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void io_ctrl_txd_input_enable_setf(uint8_t inputenable)
{
	ASSERT_ERR((((uint32_t)inputenable << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(IO_CTRL_TXD_ADDR, (REG_PL_RD(IO_CTRL_TXD_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)inputenable <<9));
}
__INLINE uint8_t io_ctrl_txd_driver_pull_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TXD_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE void io_ctrl_txd_driver_pull_state_setf(uint8_t driverpullstate)
{
	ASSERT_ERR((((uint32_t)driverpullstate << 6) & ~((uint32_t)0x000000C0)) == 0);
	REG_PL_WR(IO_CTRL_TXD_ADDR, (REG_PL_RD(IO_CTRL_TXD_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)driverpullstate <<6));
}
__INLINE uint8_t io_ctrl_txd_output_pad_strength_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TXD_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000038)) >> 3);
}
__INLINE void io_ctrl_txd_output_pad_strength_setf(uint8_t outputpadstrength)
{
	ASSERT_ERR((((uint32_t)outputpadstrength << 3) & ~((uint32_t)0x00000038)) == 0);
	REG_PL_WR(IO_CTRL_TXD_ADDR, (REG_PL_RD(IO_CTRL_TXD_ADDR) & ~((uint32_t)0x00000038)) | ((uint32_t)outputpadstrength <<3));
}
__INLINE uint8_t io_ctrl_txd_mux_select_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_TXD_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void io_ctrl_txd_mux_select_setf(uint8_t muxselect)
{
	ASSERT_ERR((((uint32_t)muxselect << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_TXD_ADDR, (REG_PL_RD(IO_CTRL_TXD_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)muxselect <<0));
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
#define IO_CTRL_RXD_ADDR        (REG_IO_CTRL_BASE_ADDR+0x00000048)
#define IO_CTRL_RXD_OFFSET      0x00000048
#define IO_CTRL_RXD_INDEX       0x00000012
#define IO_CTRL_RXD_RESET       0x000001A8

__INLINE uint32_t  io_ctrl_rxd_get(void)
{
	return REG_PL_RD(IO_CTRL_RXD_ADDR);
}

__INLINE void io_ctrl_rxd_set(uint32_t value)
{
	REG_PL_WR(IO_CTRL_RXD_ADDR, value);
}

// field definitions
#define IO_CTRL_RXD_GPIO_IN_BIT             ((uint32_t)0x00002000)
#define IO_CTRL_RXD_GPIO_IN_POS             13
#define IO_CTRL_RXD_GPIO_OUT_BIT            ((uint32_t)0x00001000)
#define IO_CTRL_RXD_GPIO_OUT_POS            12
#define IO_CTRL_RXD_GPIO_OE_BIT             ((uint32_t)0x00000800)
#define IO_CTRL_RXD_GPIO_OE_POS             11
#define IO_CTRL_RXD_GPIO_ENABLE_BIT         ((uint32_t)0x00000400)
#define IO_CTRL_RXD_GPIO_ENABLE_POS         10
#define IO_CTRL_RXD_INPUT_ENABLE_BIT        ((uint32_t)0x00000200)
#define IO_CTRL_RXD_INPUT_ENABLE_POS        9
#define IO_CTRL_RXD_DRIVER_PULL_STATE_MASK    ((uint32_t)0x000000C0)
#define IO_CTRL_RXD_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_RXD_DRIVER_PULL_STATE_WIDTH    ((uint32_t)0x00000002)
#define IO_CTRL_RXD_OUTPUT_PAD_STRENGTH_MASK    ((uint32_t)0x00000038)
#define IO_CTRL_RXD_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_RXD_OUTPUT_PAD_STRENGTH_WIDTH    ((uint32_t)0x00000003)
#define IO_CTRL_RXD_MUX_SELECT_MASK         ((uint32_t)0x00000007)
#define IO_CTRL_RXD_MUX_SELECT_LSB          0
#define IO_CTRL_RXD_MUX_SELECT_WIDTH        ((uint32_t)0x00000003)

#define IO_CTRL_RXD_GPIO_IN_RST             0x0
#define IO_CTRL_RXD_GPIO_OUT_RST            0x0
#define IO_CTRL_RXD_GPIO_OE_RST             0x0
#define IO_CTRL_RXD_GPIO_ENABLE_RST         0x1
#define IO_CTRL_RXD_INPUT_ENABLE_RST        0x1
#define IO_CTRL_RXD_DRIVER_PULL_STATE_RST    0x1
#define IO_CTRL_RXD_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_RXD_MUX_SELECT_RST          0x0

__INLINE void io_ctrl_rxd_pack(uint8_t gpio_in, uint8_t gpio_out, uint8_t gpio_oe, uint8_t gpio_enable, uint8_t input_enable, uint8_t driver_pull_state, uint8_t output_pad_strength, uint8_t mux_select)
{
	ASSERT_ERR((((uint32_t)gpio_in << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_out << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_oe << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)gpio_enable << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)input_enable << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)driver_pull_state << 6) & ~((uint32_t)0x000000C0)) == 0);
	ASSERT_ERR((((uint32_t)output_pad_strength << 3) & ~((uint32_t)0x00000038)) == 0);
	ASSERT_ERR((((uint32_t)mux_select << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_RXD_ADDR,  ((uint32_t)gpio_in << 13) |((uint32_t)gpio_out << 12) |((uint32_t)gpio_oe << 11) |((uint32_t)gpio_enable << 10) |((uint32_t)input_enable << 9) |((uint32_t)driver_pull_state << 6) |((uint32_t)output_pad_strength << 3) |((uint32_t)mux_select << 0));
}

__INLINE void io_ctrl_rxd_unpack(uint8_t* gpio_in, uint8_t* gpio_out, uint8_t* gpio_oe, uint8_t* gpio_enable, uint8_t* input_enable, uint8_t* driver_pull_state, uint8_t* output_pad_strength, uint8_t* mux_select)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_RXD_ADDR);

	*gpio_in = (localVal & ((uint32_t)0x00002000)) >>  13;
	*gpio_out = (localVal & ((uint32_t)0x00001000)) >>  12;
	*gpio_oe = (localVal & ((uint32_t)0x00000800)) >>  11;
	*gpio_enable = (localVal & ((uint32_t)0x00000400)) >>  10;
	*input_enable = (localVal & ((uint32_t)0x00000200)) >>  9;
	*driver_pull_state = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*output_pad_strength = (localVal & ((uint32_t)0x00000038)) >>  3;
	*mux_select = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t io_ctrl_rxd_gpio_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_RXD_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE uint8_t io_ctrl_rxd_gpio_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_RXD_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void io_ctrl_rxd_gpio_out_setf(uint8_t gpioout)
{
	ASSERT_ERR((((uint32_t)gpioout << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(IO_CTRL_RXD_ADDR, (REG_PL_RD(IO_CTRL_RXD_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)gpioout <<12));
}
__INLINE uint8_t io_ctrl_rxd_gpio_oe_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_RXD_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void io_ctrl_rxd_gpio_oe_setf(uint8_t gpiooe)
{
	ASSERT_ERR((((uint32_t)gpiooe << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(IO_CTRL_RXD_ADDR, (REG_PL_RD(IO_CTRL_RXD_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)gpiooe <<11));
}
__INLINE uint8_t io_ctrl_rxd_gpio_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_RXD_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void io_ctrl_rxd_gpio_enable_setf(uint8_t gpioenable)
{
	ASSERT_ERR((((uint32_t)gpioenable << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(IO_CTRL_RXD_ADDR, (REG_PL_RD(IO_CTRL_RXD_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)gpioenable <<10));
}
__INLINE uint8_t io_ctrl_rxd_input_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_RXD_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void io_ctrl_rxd_input_enable_setf(uint8_t inputenable)
{
	ASSERT_ERR((((uint32_t)inputenable << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(IO_CTRL_RXD_ADDR, (REG_PL_RD(IO_CTRL_RXD_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)inputenable <<9));
}
__INLINE uint8_t io_ctrl_rxd_driver_pull_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_RXD_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE void io_ctrl_rxd_driver_pull_state_setf(uint8_t driverpullstate)
{
	ASSERT_ERR((((uint32_t)driverpullstate << 6) & ~((uint32_t)0x000000C0)) == 0);
	REG_PL_WR(IO_CTRL_RXD_ADDR, (REG_PL_RD(IO_CTRL_RXD_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)driverpullstate <<6));
}
__INLINE uint8_t io_ctrl_rxd_output_pad_strength_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_RXD_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000038)) >> 3);
}
__INLINE void io_ctrl_rxd_output_pad_strength_setf(uint8_t outputpadstrength)
{
	ASSERT_ERR((((uint32_t)outputpadstrength << 3) & ~((uint32_t)0x00000038)) == 0);
	REG_PL_WR(IO_CTRL_RXD_ADDR, (REG_PL_RD(IO_CTRL_RXD_ADDR) & ~((uint32_t)0x00000038)) | ((uint32_t)outputpadstrength <<3));
}
__INLINE uint8_t io_ctrl_rxd_mux_select_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_RXD_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void io_ctrl_rxd_mux_select_setf(uint8_t muxselect)
{
	ASSERT_ERR((((uint32_t)muxselect << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_RXD_ADDR, (REG_PL_RD(IO_CTRL_RXD_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)muxselect <<0));
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
#define IO_CTRL_GPIO_20_ADDR        (REG_IO_CTRL_BASE_ADDR+0x0000004C)
#define IO_CTRL_GPIO_20_OFFSET      0x0000004C
#define IO_CTRL_GPIO_20_INDEX       0x00000013
#define IO_CTRL_GPIO_20_RESET       0x000001A8

__INLINE uint32_t  io_ctrl_gpio_20_get(void)
{
	return REG_PL_RD(IO_CTRL_GPIO_20_ADDR);
}

__INLINE void io_ctrl_gpio_20_set(uint32_t value)
{
	REG_PL_WR(IO_CTRL_GPIO_20_ADDR, value);
}

// field definitions
#define IO_CTRL_GPIO_20_GPIO_IN_BIT         ((uint32_t)0x00002000)
#define IO_CTRL_GPIO_20_GPIO_IN_POS         13
#define IO_CTRL_GPIO_20_GPIO_OUT_BIT        ((uint32_t)0x00001000)
#define IO_CTRL_GPIO_20_GPIO_OUT_POS        12
#define IO_CTRL_GPIO_20_GPIO_OE_BIT         ((uint32_t)0x00000800)
#define IO_CTRL_GPIO_20_GPIO_OE_POS         11
#define IO_CTRL_GPIO_20_GPIO_ENABLE_BIT     ((uint32_t)0x00000400)
#define IO_CTRL_GPIO_20_GPIO_ENABLE_POS     10
#define IO_CTRL_GPIO_20_INPUT_ENABLE_BIT    ((uint32_t)0x00000200)
#define IO_CTRL_GPIO_20_INPUT_ENABLE_POS    9
#define IO_CTRL_GPIO_20_DRIVER_PULL_STATE_MASK    ((uint32_t)0x000000C0)
#define IO_CTRL_GPIO_20_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_GPIO_20_DRIVER_PULL_STATE_WIDTH    ((uint32_t)0x00000002)
#define IO_CTRL_GPIO_20_OUTPUT_PAD_STRENGTH_MASK    ((uint32_t)0x00000038)
#define IO_CTRL_GPIO_20_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_GPIO_20_OUTPUT_PAD_STRENGTH_WIDTH    ((uint32_t)0x00000003)
#define IO_CTRL_GPIO_20_MUX_SELECT_MASK     ((uint32_t)0x00000007)
#define IO_CTRL_GPIO_20_MUX_SELECT_LSB      0
#define IO_CTRL_GPIO_20_MUX_SELECT_WIDTH    ((uint32_t)0x00000003)

#define IO_CTRL_GPIO_20_GPIO_IN_RST         0x0
#define IO_CTRL_GPIO_20_GPIO_OUT_RST        0x0
#define IO_CTRL_GPIO_20_GPIO_OE_RST         0x0
#define IO_CTRL_GPIO_20_GPIO_ENABLE_RST     0x1
#define IO_CTRL_GPIO_20_INPUT_ENABLE_RST    0x1
#define IO_CTRL_GPIO_20_DRIVER_PULL_STATE_RST    0x1
#define IO_CTRL_GPIO_20_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_GPIO_20_MUX_SELECT_RST      0x0

__INLINE void io_ctrl_gpio_20_pack(uint8_t gpio_in, uint8_t gpio_out, uint8_t gpio_oe, uint8_t gpio_enable, uint8_t input_enable, uint8_t driver_pull_state, uint8_t output_pad_strength, uint8_t mux_select)
{
	ASSERT_ERR((((uint32_t)gpio_in << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_out << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_oe << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)gpio_enable << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)input_enable << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)driver_pull_state << 6) & ~((uint32_t)0x000000C0)) == 0);
	ASSERT_ERR((((uint32_t)output_pad_strength << 3) & ~((uint32_t)0x00000038)) == 0);
	ASSERT_ERR((((uint32_t)mux_select << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_GPIO_20_ADDR,  ((uint32_t)gpio_in << 13) |((uint32_t)gpio_out << 12) |((uint32_t)gpio_oe << 11) |((uint32_t)gpio_enable << 10) |((uint32_t)input_enable << 9) |((uint32_t)driver_pull_state << 6) |((uint32_t)output_pad_strength << 3) |((uint32_t)mux_select << 0));
}

__INLINE void io_ctrl_gpio_20_unpack(uint8_t* gpio_in, uint8_t* gpio_out, uint8_t* gpio_oe, uint8_t* gpio_enable, uint8_t* input_enable, uint8_t* driver_pull_state, uint8_t* output_pad_strength, uint8_t* mux_select)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_GPIO_20_ADDR);

	*gpio_in = (localVal & ((uint32_t)0x00002000)) >>  13;
	*gpio_out = (localVal & ((uint32_t)0x00001000)) >>  12;
	*gpio_oe = (localVal & ((uint32_t)0x00000800)) >>  11;
	*gpio_enable = (localVal & ((uint32_t)0x00000400)) >>  10;
	*input_enable = (localVal & ((uint32_t)0x00000200)) >>  9;
	*driver_pull_state = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*output_pad_strength = (localVal & ((uint32_t)0x00000038)) >>  3;
	*mux_select = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t io_ctrl_gpio_20_gpio_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_GPIO_20_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE uint8_t io_ctrl_gpio_20_gpio_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_GPIO_20_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void io_ctrl_gpio_20_gpio_out_setf(uint8_t gpioout)
{
	ASSERT_ERR((((uint32_t)gpioout << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(IO_CTRL_GPIO_20_ADDR, (REG_PL_RD(IO_CTRL_GPIO_20_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)gpioout <<12));
}
__INLINE uint8_t io_ctrl_gpio_20_gpio_oe_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_GPIO_20_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void io_ctrl_gpio_20_gpio_oe_setf(uint8_t gpiooe)
{
	ASSERT_ERR((((uint32_t)gpiooe << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(IO_CTRL_GPIO_20_ADDR, (REG_PL_RD(IO_CTRL_GPIO_20_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)gpiooe <<11));
}
__INLINE uint8_t io_ctrl_gpio_20_gpio_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_GPIO_20_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void io_ctrl_gpio_20_gpio_enable_setf(uint8_t gpioenable)
{
	ASSERT_ERR((((uint32_t)gpioenable << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(IO_CTRL_GPIO_20_ADDR, (REG_PL_RD(IO_CTRL_GPIO_20_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)gpioenable <<10));
}
__INLINE uint8_t io_ctrl_gpio_20_input_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_GPIO_20_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void io_ctrl_gpio_20_input_enable_setf(uint8_t inputenable)
{
	ASSERT_ERR((((uint32_t)inputenable << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(IO_CTRL_GPIO_20_ADDR, (REG_PL_RD(IO_CTRL_GPIO_20_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)inputenable <<9));
}
__INLINE uint8_t io_ctrl_gpio_20_driver_pull_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_GPIO_20_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE void io_ctrl_gpio_20_driver_pull_state_setf(uint8_t driverpullstate)
{
	ASSERT_ERR((((uint32_t)driverpullstate << 6) & ~((uint32_t)0x000000C0)) == 0);
	REG_PL_WR(IO_CTRL_GPIO_20_ADDR, (REG_PL_RD(IO_CTRL_GPIO_20_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)driverpullstate <<6));
}
__INLINE uint8_t io_ctrl_gpio_20_output_pad_strength_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_GPIO_20_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000038)) >> 3);
}
__INLINE void io_ctrl_gpio_20_output_pad_strength_setf(uint8_t outputpadstrength)
{
	ASSERT_ERR((((uint32_t)outputpadstrength << 3) & ~((uint32_t)0x00000038)) == 0);
	REG_PL_WR(IO_CTRL_GPIO_20_ADDR, (REG_PL_RD(IO_CTRL_GPIO_20_ADDR) & ~((uint32_t)0x00000038)) | ((uint32_t)outputpadstrength <<3));
}
__INLINE uint8_t io_ctrl_gpio_20_mux_select_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_GPIO_20_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void io_ctrl_gpio_20_mux_select_setf(uint8_t muxselect)
{
	ASSERT_ERR((((uint32_t)muxselect << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_GPIO_20_ADDR, (REG_PL_RD(IO_CTRL_GPIO_20_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)muxselect <<0));
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
#define IO_CTRL_ANT_SEL_1_ADDR        (REG_IO_CTRL_BASE_ADDR+0x00000050)
#define IO_CTRL_ANT_SEL_1_OFFSET      0x00000050
#define IO_CTRL_ANT_SEL_1_INDEX       0x00000014
#define IO_CTRL_ANT_SEL_1_RESET       0x000001A8

__INLINE uint32_t  io_ctrl_ant_sel_1_get(void)
{
	return REG_PL_RD(IO_CTRL_ANT_SEL_1_ADDR);
}

__INLINE void io_ctrl_ant_sel_1_set(uint32_t value)
{
	REG_PL_WR(IO_CTRL_ANT_SEL_1_ADDR, value);
}

// field definitions
#define IO_CTRL_ANT_SEL_1_GPIO_IN_BIT       ((uint32_t)0x00002000)
#define IO_CTRL_ANT_SEL_1_GPIO_IN_POS       13
#define IO_CTRL_ANT_SEL_1_GPIO_OUT_BIT      ((uint32_t)0x00001000)
#define IO_CTRL_ANT_SEL_1_GPIO_OUT_POS      12
#define IO_CTRL_ANT_SEL_1_GPIO_OE_BIT       ((uint32_t)0x00000800)
#define IO_CTRL_ANT_SEL_1_GPIO_OE_POS       11
#define IO_CTRL_ANT_SEL_1_GPIO_ENABLE_BIT    ((uint32_t)0x00000400)
#define IO_CTRL_ANT_SEL_1_GPIO_ENABLE_POS    10
#define IO_CTRL_ANT_SEL_1_INPUT_ENABLE_BIT    ((uint32_t)0x00000200)
#define IO_CTRL_ANT_SEL_1_INPUT_ENABLE_POS    9
#define IO_CTRL_ANT_SEL_1_DRIVER_PULL_STATE_MASK    ((uint32_t)0x000000C0)
#define IO_CTRL_ANT_SEL_1_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_ANT_SEL_1_DRIVER_PULL_STATE_WIDTH    ((uint32_t)0x00000002)
#define IO_CTRL_ANT_SEL_1_OUTPUT_PAD_STRENGTH_MASK    ((uint32_t)0x00000038)
#define IO_CTRL_ANT_SEL_1_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_ANT_SEL_1_OUTPUT_PAD_STRENGTH_WIDTH    ((uint32_t)0x00000003)
#define IO_CTRL_ANT_SEL_1_MUX_SELECT_MASK    ((uint32_t)0x00000007)
#define IO_CTRL_ANT_SEL_1_MUX_SELECT_LSB    0
#define IO_CTRL_ANT_SEL_1_MUX_SELECT_WIDTH    ((uint32_t)0x00000003)

#define IO_CTRL_ANT_SEL_1_GPIO_IN_RST       0x0
#define IO_CTRL_ANT_SEL_1_GPIO_OUT_RST      0x0
#define IO_CTRL_ANT_SEL_1_GPIO_OE_RST       0x0
#define IO_CTRL_ANT_SEL_1_GPIO_ENABLE_RST    0x1
#define IO_CTRL_ANT_SEL_1_INPUT_ENABLE_RST    0x1
#define IO_CTRL_ANT_SEL_1_DRIVER_PULL_STATE_RST    0x1
#define IO_CTRL_ANT_SEL_1_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_ANT_SEL_1_MUX_SELECT_RST    0x0

__INLINE void io_ctrl_ant_sel_1_pack(uint8_t gpio_in, uint8_t gpio_out, uint8_t gpio_oe, uint8_t gpio_enable, uint8_t input_enable, uint8_t driver_pull_state, uint8_t output_pad_strength, uint8_t mux_select)
{
	ASSERT_ERR((((uint32_t)gpio_in << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_out << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_oe << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)gpio_enable << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)input_enable << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)driver_pull_state << 6) & ~((uint32_t)0x000000C0)) == 0);
	ASSERT_ERR((((uint32_t)output_pad_strength << 3) & ~((uint32_t)0x00000038)) == 0);
	ASSERT_ERR((((uint32_t)mux_select << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_ANT_SEL_1_ADDR,  ((uint32_t)gpio_in << 13) |((uint32_t)gpio_out << 12) |((uint32_t)gpio_oe << 11) |((uint32_t)gpio_enable << 10) |((uint32_t)input_enable << 9) |((uint32_t)driver_pull_state << 6) |((uint32_t)output_pad_strength << 3) |((uint32_t)mux_select << 0));
}

__INLINE void io_ctrl_ant_sel_1_unpack(uint8_t* gpio_in, uint8_t* gpio_out, uint8_t* gpio_oe, uint8_t* gpio_enable, uint8_t* input_enable, uint8_t* driver_pull_state, uint8_t* output_pad_strength, uint8_t* mux_select)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_ANT_SEL_1_ADDR);

	*gpio_in = (localVal & ((uint32_t)0x00002000)) >>  13;
	*gpio_out = (localVal & ((uint32_t)0x00001000)) >>  12;
	*gpio_oe = (localVal & ((uint32_t)0x00000800)) >>  11;
	*gpio_enable = (localVal & ((uint32_t)0x00000400)) >>  10;
	*input_enable = (localVal & ((uint32_t)0x00000200)) >>  9;
	*driver_pull_state = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*output_pad_strength = (localVal & ((uint32_t)0x00000038)) >>  3;
	*mux_select = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t io_ctrl_ant_sel_1_gpio_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_ANT_SEL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE uint8_t io_ctrl_ant_sel_1_gpio_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_ANT_SEL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void io_ctrl_ant_sel_1_gpio_out_setf(uint8_t gpioout)
{
	ASSERT_ERR((((uint32_t)gpioout << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(IO_CTRL_ANT_SEL_1_ADDR, (REG_PL_RD(IO_CTRL_ANT_SEL_1_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)gpioout <<12));
}
__INLINE uint8_t io_ctrl_ant_sel_1_gpio_oe_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_ANT_SEL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void io_ctrl_ant_sel_1_gpio_oe_setf(uint8_t gpiooe)
{
	ASSERT_ERR((((uint32_t)gpiooe << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(IO_CTRL_ANT_SEL_1_ADDR, (REG_PL_RD(IO_CTRL_ANT_SEL_1_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)gpiooe <<11));
}
__INLINE uint8_t io_ctrl_ant_sel_1_gpio_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_ANT_SEL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void io_ctrl_ant_sel_1_gpio_enable_setf(uint8_t gpioenable)
{
	ASSERT_ERR((((uint32_t)gpioenable << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(IO_CTRL_ANT_SEL_1_ADDR, (REG_PL_RD(IO_CTRL_ANT_SEL_1_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)gpioenable <<10));
}
__INLINE uint8_t io_ctrl_ant_sel_1_input_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_ANT_SEL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void io_ctrl_ant_sel_1_input_enable_setf(uint8_t inputenable)
{
	ASSERT_ERR((((uint32_t)inputenable << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(IO_CTRL_ANT_SEL_1_ADDR, (REG_PL_RD(IO_CTRL_ANT_SEL_1_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)inputenable <<9));
}
__INLINE uint8_t io_ctrl_ant_sel_1_driver_pull_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_ANT_SEL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE void io_ctrl_ant_sel_1_driver_pull_state_setf(uint8_t driverpullstate)
{
	ASSERT_ERR((((uint32_t)driverpullstate << 6) & ~((uint32_t)0x000000C0)) == 0);
	REG_PL_WR(IO_CTRL_ANT_SEL_1_ADDR, (REG_PL_RD(IO_CTRL_ANT_SEL_1_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)driverpullstate <<6));
}
__INLINE uint8_t io_ctrl_ant_sel_1_output_pad_strength_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_ANT_SEL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000038)) >> 3);
}
__INLINE void io_ctrl_ant_sel_1_output_pad_strength_setf(uint8_t outputpadstrength)
{
	ASSERT_ERR((((uint32_t)outputpadstrength << 3) & ~((uint32_t)0x00000038)) == 0);
	REG_PL_WR(IO_CTRL_ANT_SEL_1_ADDR, (REG_PL_RD(IO_CTRL_ANT_SEL_1_ADDR) & ~((uint32_t)0x00000038)) | ((uint32_t)outputpadstrength <<3));
}
__INLINE uint8_t io_ctrl_ant_sel_1_mux_select_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_ANT_SEL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void io_ctrl_ant_sel_1_mux_select_setf(uint8_t muxselect)
{
	ASSERT_ERR((((uint32_t)muxselect << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_ANT_SEL_1_ADDR, (REG_PL_RD(IO_CTRL_ANT_SEL_1_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)muxselect <<0));
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
#define IO_CTRL_ANT_SEL_2_ADDR        (REG_IO_CTRL_BASE_ADDR+0x00000054)
#define IO_CTRL_ANT_SEL_2_OFFSET      0x00000054
#define IO_CTRL_ANT_SEL_2_INDEX       0x00000015
#define IO_CTRL_ANT_SEL_2_RESET       0x000009C8

__INLINE uint32_t  io_ctrl_ant_sel_2_get(void)
{
	return REG_PL_RD(IO_CTRL_ANT_SEL_2_ADDR);
}

__INLINE void io_ctrl_ant_sel_2_set(uint32_t value)
{
	REG_PL_WR(IO_CTRL_ANT_SEL_2_ADDR, value);
}

// field definitions
#define IO_CTRL_ANT_SEL_2_GPIO_IN_BIT       ((uint32_t)0x00002000)
#define IO_CTRL_ANT_SEL_2_GPIO_IN_POS       13
#define IO_CTRL_ANT_SEL_2_GPIO_OUT_BIT      ((uint32_t)0x00001000)
#define IO_CTRL_ANT_SEL_2_GPIO_OUT_POS      12
#define IO_CTRL_ANT_SEL_2_GPIO_OE_BIT       ((uint32_t)0x00000800)
#define IO_CTRL_ANT_SEL_2_GPIO_OE_POS       11
#define IO_CTRL_ANT_SEL_2_GPIO_ENABLE_BIT    ((uint32_t)0x00000400)
#define IO_CTRL_ANT_SEL_2_GPIO_ENABLE_POS    10
#define IO_CTRL_ANT_SEL_2_INPUT_ENABLE_BIT    ((uint32_t)0x00000200)
#define IO_CTRL_ANT_SEL_2_INPUT_ENABLE_POS    9
#define IO_CTRL_ANT_SEL_2_DRIVER_PULL_STATE_MASK    ((uint32_t)0x000000C0)
#define IO_CTRL_ANT_SEL_2_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_ANT_SEL_2_DRIVER_PULL_STATE_WIDTH    ((uint32_t)0x00000002)
#define IO_CTRL_ANT_SEL_2_OUTPUT_PAD_STRENGTH_MASK    ((uint32_t)0x00000038)
#define IO_CTRL_ANT_SEL_2_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_ANT_SEL_2_OUTPUT_PAD_STRENGTH_WIDTH    ((uint32_t)0x00000003)
#define IO_CTRL_ANT_SEL_2_MUX_SELECT_MASK    ((uint32_t)0x00000007)
#define IO_CTRL_ANT_SEL_2_MUX_SELECT_LSB    0
#define IO_CTRL_ANT_SEL_2_MUX_SELECT_WIDTH    ((uint32_t)0x00000003)

#define IO_CTRL_ANT_SEL_2_GPIO_IN_RST       0x1
#define IO_CTRL_ANT_SEL_2_GPIO_OUT_RST      0x0
#define IO_CTRL_ANT_SEL_2_GPIO_OE_RST       0x0
#define IO_CTRL_ANT_SEL_2_GPIO_ENABLE_RST    0x1
#define IO_CTRL_ANT_SEL_2_INPUT_ENABLE_RST    0x1
#define IO_CTRL_ANT_SEL_2_DRIVER_PULL_STATE_RST    0x2
#define IO_CTRL_ANT_SEL_2_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_ANT_SEL_2_MUX_SELECT_RST    0x0

__INLINE void io_ctrl_ant_sel_2_pack(uint8_t gpio_in, uint8_t gpio_out, uint8_t gpio_oe, uint8_t gpio_enable, uint8_t input_enable, uint8_t driver_pull_state, uint8_t output_pad_strength, uint8_t mux_select)
{
	ASSERT_ERR((((uint32_t)gpio_in << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_out << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_oe << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)gpio_enable << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)input_enable << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)driver_pull_state << 6) & ~((uint32_t)0x000000C0)) == 0);
	ASSERT_ERR((((uint32_t)output_pad_strength << 3) & ~((uint32_t)0x00000038)) == 0);
	ASSERT_ERR((((uint32_t)mux_select << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_ANT_SEL_2_ADDR,  ((uint32_t)gpio_in << 13) |((uint32_t)gpio_out << 12) |((uint32_t)gpio_oe << 11) |((uint32_t)gpio_enable << 10) |((uint32_t)input_enable << 9) |((uint32_t)driver_pull_state << 6) |((uint32_t)output_pad_strength << 3) |((uint32_t)mux_select << 0));
}

__INLINE void io_ctrl_ant_sel_2_unpack(uint8_t* gpio_in, uint8_t* gpio_out, uint8_t* gpio_oe, uint8_t* gpio_enable, uint8_t* input_enable, uint8_t* driver_pull_state, uint8_t* output_pad_strength, uint8_t* mux_select)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_ANT_SEL_2_ADDR);

	*gpio_in = (localVal & ((uint32_t)0x00002000)) >>  13;
	*gpio_out = (localVal & ((uint32_t)0x00001000)) >>  12;
	*gpio_oe = (localVal & ((uint32_t)0x00000800)) >>  11;
	*gpio_enable = (localVal & ((uint32_t)0x00000400)) >>  10;
	*input_enable = (localVal & ((uint32_t)0x00000200)) >>  9;
	*driver_pull_state = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*output_pad_strength = (localVal & ((uint32_t)0x00000038)) >>  3;
	*mux_select = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t io_ctrl_ant_sel_2_gpio_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_ANT_SEL_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE uint8_t io_ctrl_ant_sel_2_gpio_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_ANT_SEL_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void io_ctrl_ant_sel_2_gpio_out_setf(uint8_t gpioout)
{
	ASSERT_ERR((((uint32_t)gpioout << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(IO_CTRL_ANT_SEL_2_ADDR, (REG_PL_RD(IO_CTRL_ANT_SEL_2_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)gpioout <<12));
}
__INLINE uint8_t io_ctrl_ant_sel_2_gpio_oe_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_ANT_SEL_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void io_ctrl_ant_sel_2_gpio_oe_setf(uint8_t gpiooe)
{
	ASSERT_ERR((((uint32_t)gpiooe << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(IO_CTRL_ANT_SEL_2_ADDR, (REG_PL_RD(IO_CTRL_ANT_SEL_2_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)gpiooe <<11));
}
__INLINE uint8_t io_ctrl_ant_sel_2_gpio_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_ANT_SEL_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void io_ctrl_ant_sel_2_gpio_enable_setf(uint8_t gpioenable)
{
	ASSERT_ERR((((uint32_t)gpioenable << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(IO_CTRL_ANT_SEL_2_ADDR, (REG_PL_RD(IO_CTRL_ANT_SEL_2_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)gpioenable <<10));
}
__INLINE uint8_t io_ctrl_ant_sel_2_input_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_ANT_SEL_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void io_ctrl_ant_sel_2_input_enable_setf(uint8_t inputenable)
{
	ASSERT_ERR((((uint32_t)inputenable << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(IO_CTRL_ANT_SEL_2_ADDR, (REG_PL_RD(IO_CTRL_ANT_SEL_2_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)inputenable <<9));
}
__INLINE uint8_t io_ctrl_ant_sel_2_driver_pull_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_ANT_SEL_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE void io_ctrl_ant_sel_2_driver_pull_state_setf(uint8_t driverpullstate)
{
	ASSERT_ERR((((uint32_t)driverpullstate << 6) & ~((uint32_t)0x000000C0)) == 0);
	REG_PL_WR(IO_CTRL_ANT_SEL_2_ADDR, (REG_PL_RD(IO_CTRL_ANT_SEL_2_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)driverpullstate <<6));
}
__INLINE uint8_t io_ctrl_ant_sel_2_output_pad_strength_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_ANT_SEL_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000038)) >> 3);
}
__INLINE void io_ctrl_ant_sel_2_output_pad_strength_setf(uint8_t outputpadstrength)
{
	ASSERT_ERR((((uint32_t)outputpadstrength << 3) & ~((uint32_t)0x00000038)) == 0);
	REG_PL_WR(IO_CTRL_ANT_SEL_2_ADDR, (REG_PL_RD(IO_CTRL_ANT_SEL_2_ADDR) & ~((uint32_t)0x00000038)) | ((uint32_t)outputpadstrength <<3));
}
__INLINE uint8_t io_ctrl_ant_sel_2_mux_select_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_ANT_SEL_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void io_ctrl_ant_sel_2_mux_select_setf(uint8_t muxselect)
{
	ASSERT_ERR((((uint32_t)muxselect << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_ANT_SEL_2_ADDR, (REG_PL_RD(IO_CTRL_ANT_SEL_2_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)muxselect <<0));
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
#define IO_CTRL_ANT_SEL_3_ADDR        (REG_IO_CTRL_BASE_ADDR+0x00000058)
#define IO_CTRL_ANT_SEL_3_OFFSET      0x00000058
#define IO_CTRL_ANT_SEL_3_INDEX       0x00000016
#define IO_CTRL_ANT_SEL_3_RESET       0x000009C8

__INLINE uint32_t  io_ctrl_ant_sel_3_get(void)
{
	return REG_PL_RD(IO_CTRL_ANT_SEL_3_ADDR);
}

__INLINE void io_ctrl_ant_sel_3_set(uint32_t value)
{
	REG_PL_WR(IO_CTRL_ANT_SEL_3_ADDR, value);
}

// field definitions
#define IO_CTRL_ANT_SEL_3_GPIO_IN_BIT       ((uint32_t)0x00002000)
#define IO_CTRL_ANT_SEL_3_GPIO_IN_POS       13
#define IO_CTRL_ANT_SEL_3_GPIO_OUT_BIT      ((uint32_t)0x00001000)
#define IO_CTRL_ANT_SEL_3_GPIO_OUT_POS      12
#define IO_CTRL_ANT_SEL_3_GPIO_OE_BIT       ((uint32_t)0x00000800)
#define IO_CTRL_ANT_SEL_3_GPIO_OE_POS       11
#define IO_CTRL_ANT_SEL_3_GPIO_ENABLE_BIT    ((uint32_t)0x00000400)
#define IO_CTRL_ANT_SEL_3_GPIO_ENABLE_POS    10
#define IO_CTRL_ANT_SEL_3_INPUT_ENABLE_BIT    ((uint32_t)0x00000200)
#define IO_CTRL_ANT_SEL_3_INPUT_ENABLE_POS    9
#define IO_CTRL_ANT_SEL_3_DRIVER_PULL_STATE_MASK    ((uint32_t)0x000000C0)
#define IO_CTRL_ANT_SEL_3_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_ANT_SEL_3_DRIVER_PULL_STATE_WIDTH    ((uint32_t)0x00000002)
#define IO_CTRL_ANT_SEL_3_OUTPUT_PAD_STRENGTH_MASK    ((uint32_t)0x00000038)
#define IO_CTRL_ANT_SEL_3_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_ANT_SEL_3_OUTPUT_PAD_STRENGTH_WIDTH    ((uint32_t)0x00000003)
#define IO_CTRL_ANT_SEL_3_MUX_SELECT_MASK    ((uint32_t)0x00000007)
#define IO_CTRL_ANT_SEL_3_MUX_SELECT_LSB    0
#define IO_CTRL_ANT_SEL_3_MUX_SELECT_WIDTH    ((uint32_t)0x00000003)

#define IO_CTRL_ANT_SEL_3_GPIO_IN_RST       0x1
#define IO_CTRL_ANT_SEL_3_GPIO_OUT_RST      0x0
#define IO_CTRL_ANT_SEL_3_GPIO_OE_RST       0x0
#define IO_CTRL_ANT_SEL_3_GPIO_ENABLE_RST    0x1
#define IO_CTRL_ANT_SEL_3_INPUT_ENABLE_RST    0x1
#define IO_CTRL_ANT_SEL_3_DRIVER_PULL_STATE_RST    0x2
#define IO_CTRL_ANT_SEL_3_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_ANT_SEL_3_MUX_SELECT_RST    0x0

__INLINE void io_ctrl_ant_sel_3_pack(uint8_t gpio_in, uint8_t gpio_out, uint8_t gpio_oe, uint8_t gpio_enable, uint8_t input_enable, uint8_t driver_pull_state, uint8_t output_pad_strength, uint8_t mux_select)
{
	ASSERT_ERR((((uint32_t)gpio_in << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_out << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_oe << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)gpio_enable << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)input_enable << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)driver_pull_state << 6) & ~((uint32_t)0x000000C0)) == 0);
	ASSERT_ERR((((uint32_t)output_pad_strength << 3) & ~((uint32_t)0x00000038)) == 0);
	ASSERT_ERR((((uint32_t)mux_select << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_ANT_SEL_3_ADDR,  ((uint32_t)gpio_in << 13) |((uint32_t)gpio_out << 12) |((uint32_t)gpio_oe << 11) |((uint32_t)gpio_enable << 10) |((uint32_t)input_enable << 9) |((uint32_t)driver_pull_state << 6) |((uint32_t)output_pad_strength << 3) |((uint32_t)mux_select << 0));
}

__INLINE void io_ctrl_ant_sel_3_unpack(uint8_t* gpio_in, uint8_t* gpio_out, uint8_t* gpio_oe, uint8_t* gpio_enable, uint8_t* input_enable, uint8_t* driver_pull_state, uint8_t* output_pad_strength, uint8_t* mux_select)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_ANT_SEL_3_ADDR);

	*gpio_in = (localVal & ((uint32_t)0x00002000)) >>  13;
	*gpio_out = (localVal & ((uint32_t)0x00001000)) >>  12;
	*gpio_oe = (localVal & ((uint32_t)0x00000800)) >>  11;
	*gpio_enable = (localVal & ((uint32_t)0x00000400)) >>  10;
	*input_enable = (localVal & ((uint32_t)0x00000200)) >>  9;
	*driver_pull_state = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*output_pad_strength = (localVal & ((uint32_t)0x00000038)) >>  3;
	*mux_select = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t io_ctrl_ant_sel_3_gpio_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_ANT_SEL_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE uint8_t io_ctrl_ant_sel_3_gpio_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_ANT_SEL_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void io_ctrl_ant_sel_3_gpio_out_setf(uint8_t gpioout)
{
	ASSERT_ERR((((uint32_t)gpioout << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(IO_CTRL_ANT_SEL_3_ADDR, (REG_PL_RD(IO_CTRL_ANT_SEL_3_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)gpioout <<12));
}
__INLINE uint8_t io_ctrl_ant_sel_3_gpio_oe_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_ANT_SEL_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void io_ctrl_ant_sel_3_gpio_oe_setf(uint8_t gpiooe)
{
	ASSERT_ERR((((uint32_t)gpiooe << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(IO_CTRL_ANT_SEL_3_ADDR, (REG_PL_RD(IO_CTRL_ANT_SEL_3_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)gpiooe <<11));
}
__INLINE uint8_t io_ctrl_ant_sel_3_gpio_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_ANT_SEL_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void io_ctrl_ant_sel_3_gpio_enable_setf(uint8_t gpioenable)
{
	ASSERT_ERR((((uint32_t)gpioenable << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(IO_CTRL_ANT_SEL_3_ADDR, (REG_PL_RD(IO_CTRL_ANT_SEL_3_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)gpioenable <<10));
}
__INLINE uint8_t io_ctrl_ant_sel_3_input_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_ANT_SEL_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void io_ctrl_ant_sel_3_input_enable_setf(uint8_t inputenable)
{
	ASSERT_ERR((((uint32_t)inputenable << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(IO_CTRL_ANT_SEL_3_ADDR, (REG_PL_RD(IO_CTRL_ANT_SEL_3_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)inputenable <<9));
}
__INLINE uint8_t io_ctrl_ant_sel_3_driver_pull_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_ANT_SEL_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE void io_ctrl_ant_sel_3_driver_pull_state_setf(uint8_t driverpullstate)
{
	ASSERT_ERR((((uint32_t)driverpullstate << 6) & ~((uint32_t)0x000000C0)) == 0);
	REG_PL_WR(IO_CTRL_ANT_SEL_3_ADDR, (REG_PL_RD(IO_CTRL_ANT_SEL_3_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)driverpullstate <<6));
}
__INLINE uint8_t io_ctrl_ant_sel_3_output_pad_strength_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_ANT_SEL_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000038)) >> 3);
}
__INLINE void io_ctrl_ant_sel_3_output_pad_strength_setf(uint8_t outputpadstrength)
{
	ASSERT_ERR((((uint32_t)outputpadstrength << 3) & ~((uint32_t)0x00000038)) == 0);
	REG_PL_WR(IO_CTRL_ANT_SEL_3_ADDR, (REG_PL_RD(IO_CTRL_ANT_SEL_3_ADDR) & ~((uint32_t)0x00000038)) | ((uint32_t)outputpadstrength <<3));
}
__INLINE uint8_t io_ctrl_ant_sel_3_mux_select_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_ANT_SEL_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void io_ctrl_ant_sel_3_mux_select_setf(uint8_t muxselect)
{
	ASSERT_ERR((((uint32_t)muxselect << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_ANT_SEL_3_ADDR, (REG_PL_RD(IO_CTRL_ANT_SEL_3_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)muxselect <<0));
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
#define IO_CTRL_GPIO_2_ADDR        (REG_IO_CTRL_BASE_ADDR+0x0000005C)
#define IO_CTRL_GPIO_2_OFFSET      0x0000005C
#define IO_CTRL_GPIO_2_INDEX       0x00000017
#define IO_CTRL_GPIO_2_RESET       0x000019C8

__INLINE uint32_t  io_ctrl_gpio_2_get(void)
{
	return REG_PL_RD(IO_CTRL_GPIO_2_ADDR);
}

__INLINE void io_ctrl_gpio_2_set(uint32_t value)
{
	REG_PL_WR(IO_CTRL_GPIO_2_ADDR, value);
}

// field definitions
#define IO_CTRL_GPIO_2_HOST_INTERFACE_BIT    ((uint32_t)0x00004000)
#define IO_CTRL_GPIO_2_HOST_INTERFACE_POS    14
#define IO_CTRL_GPIO_2_GPIO_IN_BIT          ((uint32_t)0x00002000)
#define IO_CTRL_GPIO_2_GPIO_IN_POS          13
#define IO_CTRL_GPIO_2_GPIO_OUT_BIT         ((uint32_t)0x00001000)
#define IO_CTRL_GPIO_2_GPIO_OUT_POS         12
#define IO_CTRL_GPIO_2_GPIO_OE_BIT          ((uint32_t)0x00000800)
#define IO_CTRL_GPIO_2_GPIO_OE_POS          11
#define IO_CTRL_GPIO_2_GPIO_ENABLE_BIT      ((uint32_t)0x00000400)
#define IO_CTRL_GPIO_2_GPIO_ENABLE_POS      10
#define IO_CTRL_GPIO_2_INPUT_ENABLE_BIT     ((uint32_t)0x00000200)
#define IO_CTRL_GPIO_2_INPUT_ENABLE_POS     9
#define IO_CTRL_GPIO_2_DRIVER_PULL_STATE_MASK    ((uint32_t)0x000000C0)
#define IO_CTRL_GPIO_2_DRIVER_PULL_STATE_LSB    6
#define IO_CTRL_GPIO_2_DRIVER_PULL_STATE_WIDTH    ((uint32_t)0x00000002)
#define IO_CTRL_GPIO_2_OUTPUT_PAD_STRENGTH_MASK    ((uint32_t)0x00000038)
#define IO_CTRL_GPIO_2_OUTPUT_PAD_STRENGTH_LSB    3
#define IO_CTRL_GPIO_2_OUTPUT_PAD_STRENGTH_WIDTH    ((uint32_t)0x00000003)
#define IO_CTRL_GPIO_2_MUX_SELECT_MASK      ((uint32_t)0x00000007)
#define IO_CTRL_GPIO_2_MUX_SELECT_LSB       0
#define IO_CTRL_GPIO_2_MUX_SELECT_WIDTH     ((uint32_t)0x00000003)

#define IO_CTRL_GPIO_2_HOST_INTERFACE_RST    0x1
#define IO_CTRL_GPIO_2_GPIO_IN_RST          0x1
#define IO_CTRL_GPIO_2_GPIO_OUT_RST         0x0
#define IO_CTRL_GPIO_2_GPIO_OE_RST          0x0
#define IO_CTRL_GPIO_2_GPIO_ENABLE_RST      0x1
#define IO_CTRL_GPIO_2_INPUT_ENABLE_RST     0x1
#define IO_CTRL_GPIO_2_DRIVER_PULL_STATE_RST    0x2
#define IO_CTRL_GPIO_2_OUTPUT_PAD_STRENGTH_RST    0x2
#define IO_CTRL_GPIO_2_MUX_SELECT_RST       0x0

__INLINE void io_ctrl_gpio_2_pack(uint8_t host_interface, uint8_t gpio_in, uint8_t gpio_out, uint8_t gpio_oe, uint8_t gpio_enable, uint8_t input_enable, uint8_t driver_pull_state, uint8_t output_pad_strength, uint8_t mux_select)
{
	ASSERT_ERR((((uint32_t)host_interface << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_in << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_out << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)gpio_oe << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)gpio_enable << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)input_enable << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)driver_pull_state << 6) & ~((uint32_t)0x000000C0)) == 0);
	ASSERT_ERR((((uint32_t)output_pad_strength << 3) & ~((uint32_t)0x00000038)) == 0);
	ASSERT_ERR((((uint32_t)mux_select << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_GPIO_2_ADDR,  ((uint32_t)host_interface << 14) |((uint32_t)gpio_in << 13) |((uint32_t)gpio_out << 12) |((uint32_t)gpio_oe << 11) |((uint32_t)gpio_enable << 10) |((uint32_t)input_enable << 9) |((uint32_t)driver_pull_state << 6) |((uint32_t)output_pad_strength << 3) |((uint32_t)mux_select << 0));
}

__INLINE void io_ctrl_gpio_2_unpack(uint8_t* host_interface, uint8_t* gpio_in, uint8_t* gpio_out, uint8_t* gpio_oe, uint8_t* gpio_enable, uint8_t* input_enable, uint8_t* driver_pull_state, uint8_t* output_pad_strength, uint8_t* mux_select)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_GPIO_2_ADDR);

	*host_interface = (localVal & ((uint32_t)0x00004000)) >>  14;
	*gpio_in = (localVal & ((uint32_t)0x00002000)) >>  13;
	*gpio_out = (localVal & ((uint32_t)0x00001000)) >>  12;
	*gpio_oe = (localVal & ((uint32_t)0x00000800)) >>  11;
	*gpio_enable = (localVal & ((uint32_t)0x00000400)) >>  10;
	*input_enable = (localVal & ((uint32_t)0x00000200)) >>  9;
	*driver_pull_state = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*output_pad_strength = (localVal & ((uint32_t)0x00000038)) >>  3;
	*mux_select = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t io_ctrl_gpio_2_host_interface_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_GPIO_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE uint8_t io_ctrl_gpio_2_gpio_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_GPIO_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE uint8_t io_ctrl_gpio_2_gpio_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_GPIO_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void io_ctrl_gpio_2_gpio_out_setf(uint8_t gpioout)
{
	ASSERT_ERR((((uint32_t)gpioout << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(IO_CTRL_GPIO_2_ADDR, (REG_PL_RD(IO_CTRL_GPIO_2_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)gpioout <<12));
}
__INLINE uint8_t io_ctrl_gpio_2_gpio_oe_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_GPIO_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void io_ctrl_gpio_2_gpio_oe_setf(uint8_t gpiooe)
{
	ASSERT_ERR((((uint32_t)gpiooe << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(IO_CTRL_GPIO_2_ADDR, (REG_PL_RD(IO_CTRL_GPIO_2_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)gpiooe <<11));
}
__INLINE uint8_t io_ctrl_gpio_2_gpio_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_GPIO_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void io_ctrl_gpio_2_gpio_enable_setf(uint8_t gpioenable)
{
	ASSERT_ERR((((uint32_t)gpioenable << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(IO_CTRL_GPIO_2_ADDR, (REG_PL_RD(IO_CTRL_GPIO_2_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)gpioenable <<10));
}
__INLINE uint8_t io_ctrl_gpio_2_input_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_GPIO_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void io_ctrl_gpio_2_input_enable_setf(uint8_t inputenable)
{
	ASSERT_ERR((((uint32_t)inputenable << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(IO_CTRL_GPIO_2_ADDR, (REG_PL_RD(IO_CTRL_GPIO_2_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)inputenable <<9));
}
__INLINE uint8_t io_ctrl_gpio_2_driver_pull_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_GPIO_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE void io_ctrl_gpio_2_driver_pull_state_setf(uint8_t driverpullstate)
{
	ASSERT_ERR((((uint32_t)driverpullstate << 6) & ~((uint32_t)0x000000C0)) == 0);
	REG_PL_WR(IO_CTRL_GPIO_2_ADDR, (REG_PL_RD(IO_CTRL_GPIO_2_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)driverpullstate <<6));
}
__INLINE uint8_t io_ctrl_gpio_2_output_pad_strength_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_GPIO_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000038)) >> 3);
}
__INLINE void io_ctrl_gpio_2_output_pad_strength_setf(uint8_t outputpadstrength)
{
	ASSERT_ERR((((uint32_t)outputpadstrength << 3) & ~((uint32_t)0x00000038)) == 0);
	REG_PL_WR(IO_CTRL_GPIO_2_ADDR, (REG_PL_RD(IO_CTRL_GPIO_2_ADDR) & ~((uint32_t)0x00000038)) | ((uint32_t)outputpadstrength <<3));
}
__INLINE uint8_t io_ctrl_gpio_2_mux_select_getf(void)
{
	uint32_t localVal = REG_PL_RD(IO_CTRL_GPIO_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void io_ctrl_gpio_2_mux_select_setf(uint8_t muxselect)
{
	ASSERT_ERR((((uint32_t)muxselect << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IO_CTRL_GPIO_2_ADDR, (REG_PL_RD(IO_CTRL_GPIO_2_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)muxselect <<0));
}


#undef DBG_FILEID
#endif //_REG_IO_CTRL_H_

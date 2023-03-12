#ifndef _REG_SYSCTL_H_
#define _REG_SYSCTL_H_

#include <stdint.h>
#include "_reg_sysctl.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define DBG_FILEID __REG_SYSCTL__H__FILEID__

#define REG_SYSCTL_COUNT  13


/**
 * @brief SIGNATURE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 FPGA_SIGNATURE            0x0
 * </pre>
 */
#define SYSCTL_SIGNATURE_ADDR        (REG_SYSCTL_BASE_ADDR+0x00000000)
#define SYSCTL_SIGNATURE_OFFSET      0x00000000
#define SYSCTL_SIGNATURE_INDEX       0x00000000
#define SYSCTL_SIGNATURE_RESET       0x00000000

__INLINE uint32_t  sysctl_signature_get(void)
{
	return REG_PL_RD(SYSCTL_SIGNATURE_ADDR);
}

// field definitions
#define SYSCTL_SIGNATURE_FPGA_SIGNATURE_MASK    ((uint32_t)0xFFFFFFFF)
#define SYSCTL_SIGNATURE_FPGA_SIGNATURE_LSB    0
#define SYSCTL_SIGNATURE_FPGA_SIGNATURE_WIDTH    ((uint32_t)0x00000020)

#define SYSCTL_SIGNATURE_FPGA_SIGNATURE_RST    0x0

__INLINE uint32_t sysctl_signature_fpga_signature_getf(void)
{
	uint32_t localVal = REG_PL_RD(SYSCTL_SIGNATURE_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief INTSET register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01    MMU_INT_SET               0              
 *    00    DMA_INT_SET               0              
 * </pre>
 */
#define SYSCTL_INTSET_ADDR        (REG_SYSCTL_BASE_ADDR+0x00000004)
#define SYSCTL_INTSET_OFFSET      0x00000004
#define SYSCTL_INTSET_INDEX       0x00000001
#define SYSCTL_INTSET_RESET       0x00000000

__INLINE void sysctl_intset_set(uint32_t value)
{
	REG_PL_WR(SYSCTL_INTSET_ADDR, value);
}

// field definitions
#define SYSCTL_INTSET_MMU_INT_SET_BIT       ((uint32_t)0x00000002)
#define SYSCTL_INTSET_MMU_INT_SET_POS       1
#define SYSCTL_INTSET_DMA_INT_SET_BIT       ((uint32_t)0x00000001)
#define SYSCTL_INTSET_DMA_INT_SET_POS       0

#define SYSCTL_INTSET_MMU_INT_SET_RST       0x0
#define SYSCTL_INTSET_DMA_INT_SET_RST       0x0

__INLINE void sysctl_intset_pack(uint8_t mmu_int_set, uint8_t dma_int_set)
{
	ASSERT_ERR((((uint32_t)mmu_int_set << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)dma_int_set << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(SYSCTL_INTSET_ADDR,  ((uint32_t)mmu_int_set << 1) |((uint32_t)dma_int_set << 0));
}

__INLINE void sysctl_intset_mmu_int_set_setf(uint8_t mmuintset)
{
	ASSERT_ERR((((uint32_t)mmuintset << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(SYSCTL_INTSET_ADDR, (REG_PL_RD(SYSCTL_INTSET_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)mmuintset <<1));
}
__INLINE void sysctl_intset_dma_int_set_setf(uint8_t dmaintset)
{
	ASSERT_ERR((((uint32_t)dmaintset << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(SYSCTL_INTSET_ADDR, (REG_PL_RD(SYSCTL_INTSET_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)dmaintset <<0));
}

/**
 * @brief INTRESET register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01    MMU_INT_RESET             0              
 *    00    DMA_INT_RESET             0              
 * </pre>
 */
#define SYSCTL_INTRESET_ADDR        (REG_SYSCTL_BASE_ADDR+0x00000008)
#define SYSCTL_INTRESET_OFFSET      0x00000008
#define SYSCTL_INTRESET_INDEX       0x00000002
#define SYSCTL_INTRESET_RESET       0x00000000

__INLINE void sysctl_intreset_set(uint32_t value)
{
	REG_PL_WR(SYSCTL_INTRESET_ADDR, value);
}

// field definitions
#define SYSCTL_INTRESET_MMU_INT_RESET_BIT    ((uint32_t)0x00000002)
#define SYSCTL_INTRESET_MMU_INT_RESET_POS    1
#define SYSCTL_INTRESET_DMA_INT_RESET_BIT    ((uint32_t)0x00000001)
#define SYSCTL_INTRESET_DMA_INT_RESET_POS    0

#define SYSCTL_INTRESET_MMU_INT_RESET_RST    0x0
#define SYSCTL_INTRESET_DMA_INT_RESET_RST    0x0

__INLINE void sysctl_intreset_pack(uint8_t mmu_int_reset, uint8_t dma_int_reset)
{
	ASSERT_ERR((((uint32_t)mmu_int_reset << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)dma_int_reset << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(SYSCTL_INTRESET_ADDR,  ((uint32_t)mmu_int_reset << 1) |((uint32_t)dma_int_reset << 0));
}

__INLINE void sysctl_intreset_mmu_int_reset_setf(uint8_t mmuintreset)
{
	ASSERT_ERR((((uint32_t)mmuintreset << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(SYSCTL_INTRESET_ADDR, (REG_PL_RD(SYSCTL_INTRESET_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)mmuintreset <<1));
}
__INLINE void sysctl_intreset_dma_int_reset_setf(uint8_t dmaintreset)
{
	ASSERT_ERR((((uint32_t)dmaintreset << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(SYSCTL_INTRESET_ADDR, (REG_PL_RD(SYSCTL_INTRESET_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)dmaintreset <<0));
}

/**
 * @brief DATE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 FPGA_DATE                 0x0
 * </pre>
 */
#define SYSCTL_DATE_ADDR        (REG_SYSCTL_BASE_ADDR+0x0000000C)
#define SYSCTL_DATE_OFFSET      0x0000000C
#define SYSCTL_DATE_INDEX       0x00000003
#define SYSCTL_DATE_RESET       0x00000000

__INLINE uint32_t  sysctl_date_get(void)
{
	return REG_PL_RD(SYSCTL_DATE_ADDR);
}

// field definitions
#define SYSCTL_DATE_FPGA_DATE_MASK          ((uint32_t)0xFFFFFFFF)
#define SYSCTL_DATE_FPGA_DATE_LSB           0
#define SYSCTL_DATE_FPGA_DATE_WIDTH         ((uint32_t)0x00000020)

#define SYSCTL_DATE_FPGA_DATE_RST           0x0

__INLINE uint32_t sysctl_date_fpga_date_getf(void)
{
	uint32_t localVal = REG_PL_RD(SYSCTL_DATE_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_VALUE               0x0
 * </pre>
 */
#define SYSCTL_TIMER_ADDR        (REG_SYSCTL_BASE_ADDR+0x00000040)
#define SYSCTL_TIMER_OFFSET      0x00000040
#define SYSCTL_TIMER_INDEX       0x00000010
#define SYSCTL_TIMER_RESET       0x00000000

__INLINE uint32_t  sysctl_timer_get(void)
{
	return REG_PL_RD(SYSCTL_TIMER_ADDR);
}

__INLINE void sysctl_timer_set(uint32_t value)
{
	REG_PL_WR(SYSCTL_TIMER_ADDR, value);
}

// field definitions
#define SYSCTL_TIMER_TIMER_VALUE_MASK       ((uint32_t)0xFFFFFFFF)
#define SYSCTL_TIMER_TIMER_VALUE_LSB        0
#define SYSCTL_TIMER_TIMER_VALUE_WIDTH      ((uint32_t)0x00000020)

#define SYSCTL_TIMER_TIMER_VALUE_RST        0x0

__INLINE uint32_t sysctl_timer_timer_value_getf(void)
{
	uint32_t localVal = REG_PL_RD(SYSCTL_TIMER_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void sysctl_timer_timer_value_setf(uint32_t timervalue)
{
	ASSERT_ERR((((uint32_t)timervalue << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SYSCTL_TIMER_ADDR, (uint32_t)timervalue << 0);
}

/**
 * @brief DIAG_CONF register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    DIAG_SEL_EN               0              
 *    15:00 DIAG_SEL                  0x1888
 * </pre>
 */
#define SYSCTL_DIAG_CONF_ADDR        (REG_SYSCTL_BASE_ADDR+0x00000068)
#define SYSCTL_DIAG_CONF_OFFSET      0x00000068
#define SYSCTL_DIAG_CONF_INDEX       0x0000001A
#define SYSCTL_DIAG_CONF_RESET       0x00001888

__INLINE uint32_t  sysctl_diag_conf_get(void)
{
	return REG_PL_RD(SYSCTL_DIAG_CONF_ADDR);
}

__INLINE void sysctl_diag_conf_set(uint32_t value)
{
	REG_PL_WR(SYSCTL_DIAG_CONF_ADDR, value);
}

// field definitions
#define SYSCTL_DIAG_CONF_DIAG_SEL_EN_BIT    ((uint32_t)0x80000000)
#define SYSCTL_DIAG_CONF_DIAG_SEL_EN_POS    31
#define SYSCTL_DIAG_CONF_DIAG_SEL_MASK      ((uint32_t)0x0000FFFF)
#define SYSCTL_DIAG_CONF_DIAG_SEL_LSB       0
#define SYSCTL_DIAG_CONF_DIAG_SEL_WIDTH     ((uint32_t)0x00000010)

#define SYSCTL_DIAG_CONF_DIAG_SEL_EN_RST    0x0
#define SYSCTL_DIAG_CONF_DIAG_SEL_RST       0x1888

__INLINE void sysctl_diag_conf_pack(uint8_t diag_sel_en, uint16_t diag_sel)
{
	ASSERT_ERR((((uint32_t)diag_sel_en << 31) & ~((uint32_t)0x80000000)) == 0);
	ASSERT_ERR((((uint32_t)diag_sel << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SYSCTL_DIAG_CONF_ADDR,  ((uint32_t)diag_sel_en << 31) |((uint32_t)diag_sel << 0));
}

__INLINE void sysctl_diag_conf_unpack(uint8_t* diag_sel_en, uint16_t* diag_sel)
{
	uint32_t localVal = REG_PL_RD(SYSCTL_DIAG_CONF_ADDR);

	*diag_sel_en = (localVal & ((uint32_t)0x80000000)) >>  31;
	*diag_sel = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint8_t sysctl_diag_conf_diag_sel_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(SYSCTL_DIAG_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE void sysctl_diag_conf_diag_sel_en_setf(uint8_t diagselen)
{
	ASSERT_ERR((((uint32_t)diagselen << 31) & ~((uint32_t)0x80000000)) == 0);
	REG_PL_WR(SYSCTL_DIAG_CONF_ADDR, (REG_PL_RD(SYSCTL_DIAG_CONF_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)diagselen <<31));
}
__INLINE uint16_t sysctl_diag_conf_diag_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(SYSCTL_DIAG_CONF_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void sysctl_diag_conf_diag_sel_setf(uint16_t diagsel)
{
	ASSERT_ERR((((uint32_t)diagsel << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SYSCTL_DIAG_CONF_ADDR, (REG_PL_RD(SYSCTL_DIAG_CONF_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)diagsel <<0));
}

/**
 * @brief DIAG_STAT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DIAG_VALUE                0x0
 * </pre>
 */
#define SYSCTL_DIAG_STAT_ADDR        (REG_SYSCTL_BASE_ADDR+0x0000006C)
#define SYSCTL_DIAG_STAT_OFFSET      0x0000006C
#define SYSCTL_DIAG_STAT_INDEX       0x0000001B
#define SYSCTL_DIAG_STAT_RESET       0x00000000

__INLINE uint32_t  sysctl_diag_stat_get(void)
{
	return REG_PL_RD(SYSCTL_DIAG_STAT_ADDR);
}

// field definitions
#define SYSCTL_DIAG_STAT_DIAG_VALUE_MASK    ((uint32_t)0xFFFFFFFF)
#define SYSCTL_DIAG_STAT_DIAG_VALUE_LSB     0
#define SYSCTL_DIAG_STAT_DIAG_VALUE_WIDTH    ((uint32_t)0x00000020)

#define SYSCTL_DIAG_STAT_DIAG_VALUE_RST     0x0

__INLINE uint32_t sysctl_diag_stat_diag_value_getf(void)
{
	uint32_t localVal = REG_PL_RD(SYSCTL_DIAG_STAT_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief DIAG_TRIGGER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    DIAG_TRIG                 1              
 * </pre>
 */
#define SYSCTL_DIAG_TRIGGER_ADDR        (REG_SYSCTL_BASE_ADDR+0x00000070)
#define SYSCTL_DIAG_TRIGGER_OFFSET      0x00000070
#define SYSCTL_DIAG_TRIGGER_INDEX       0x0000001C
#define SYSCTL_DIAG_TRIGGER_RESET       0x00000001

__INLINE uint32_t  sysctl_diag_trigger_get(void)
{
	return REG_PL_RD(SYSCTL_DIAG_TRIGGER_ADDR);
}

__INLINE void sysctl_diag_trigger_set(uint32_t value)
{
	REG_PL_WR(SYSCTL_DIAG_TRIGGER_ADDR, value);
}

// field definitions
#define SYSCTL_DIAG_TRIGGER_DIAG_TRIG_BIT    ((uint32_t)0x00000001)
#define SYSCTL_DIAG_TRIGGER_DIAG_TRIG_POS    0

#define SYSCTL_DIAG_TRIGGER_DIAG_TRIG_RST    0x1

__INLINE uint8_t sysctl_diag_trigger_diag_trig_getf(void)
{
	uint32_t localVal = REG_PL_RD(SYSCTL_DIAG_TRIGGER_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void sysctl_diag_trigger_diag_trig_setf(uint8_t diagtrig)
{
	ASSERT_ERR((((uint32_t)diagtrig << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(SYSCTL_DIAG_TRIGGER_ADDR, (uint32_t)diagtrig << 0);
}

/**
 * @brief GPIO_OEN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 GPIO_OEN                  0x0
 * </pre>
 */
#define SYSCTL_GPIO_OEN_ADDR        (REG_SYSCTL_BASE_ADDR+0x00000080)
#define SYSCTL_GPIO_OEN_OFFSET      0x00000080
#define SYSCTL_GPIO_OEN_INDEX       0x00000020
#define SYSCTL_GPIO_OEN_RESET       0x00000000

__INLINE uint32_t  sysctl_gpio_oen_get(void)
{
	return REG_PL_RD(SYSCTL_GPIO_OEN_ADDR);
}

__INLINE void sysctl_gpio_oen_set(uint32_t value)
{
	REG_PL_WR(SYSCTL_GPIO_OEN_ADDR, value);
}

// field definitions
#define SYSCTL_GPIO_OEN_GPIO_OEN_MASK       ((uint32_t)0xFFFFFFFF)
#define SYSCTL_GPIO_OEN_GPIO_OEN_LSB        0
#define SYSCTL_GPIO_OEN_GPIO_OEN_WIDTH      ((uint32_t)0x00000020)

#define SYSCTL_GPIO_OEN_GPIO_OEN_RST        0x0

__INLINE uint32_t sysctl_gpio_oen_gpio_oen_getf(void)
{
	uint32_t localVal = REG_PL_RD(SYSCTL_GPIO_OEN_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void sysctl_gpio_oen_gpio_oen_setf(uint32_t gpiooen)
{
	ASSERT_ERR((((uint32_t)gpiooen << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SYSCTL_GPIO_OEN_ADDR, (uint32_t)gpiooen << 0);
}

/**
 * @brief GPIO_OUT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 GPIO_OUT                  0x0
 * </pre>
 */
#define SYSCTL_GPIO_OUT_ADDR        (REG_SYSCTL_BASE_ADDR+0x00000084)
#define SYSCTL_GPIO_OUT_OFFSET      0x00000084
#define SYSCTL_GPIO_OUT_INDEX       0x00000021
#define SYSCTL_GPIO_OUT_RESET       0x00000000

__INLINE uint32_t  sysctl_gpio_out_get(void)
{
	return REG_PL_RD(SYSCTL_GPIO_OUT_ADDR);
}

__INLINE void sysctl_gpio_out_set(uint32_t value)
{
	REG_PL_WR(SYSCTL_GPIO_OUT_ADDR, value);
}

// field definitions
#define SYSCTL_GPIO_OUT_GPIO_OUT_MASK       ((uint32_t)0xFFFFFFFF)
#define SYSCTL_GPIO_OUT_GPIO_OUT_LSB        0
#define SYSCTL_GPIO_OUT_GPIO_OUT_WIDTH      ((uint32_t)0x00000020)

#define SYSCTL_GPIO_OUT_GPIO_OUT_RST        0x0

__INLINE uint32_t sysctl_gpio_out_gpio_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(SYSCTL_GPIO_OUT_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void sysctl_gpio_out_gpio_out_setf(uint32_t gpioout)
{
	ASSERT_ERR((((uint32_t)gpioout << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SYSCTL_GPIO_OUT_ADDR, (uint32_t)gpioout << 0);
}

/**
 * @brief GPIO_IN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 GPIO_IN                   0x0
 * </pre>
 */
#define SYSCTL_GPIO_IN_ADDR        (REG_SYSCTL_BASE_ADDR+0x00000088)
#define SYSCTL_GPIO_IN_OFFSET      0x00000088
#define SYSCTL_GPIO_IN_INDEX       0x00000022
#define SYSCTL_GPIO_IN_RESET       0x00000000

__INLINE uint32_t  sysctl_gpio_in_get(void)
{
	return REG_PL_RD(SYSCTL_GPIO_IN_ADDR);
}

// field definitions
#define SYSCTL_GPIO_IN_GPIO_IN_MASK         ((uint32_t)0xFFFFFFFF)
#define SYSCTL_GPIO_IN_GPIO_IN_LSB          0
#define SYSCTL_GPIO_IN_GPIO_IN_WIDTH        ((uint32_t)0x00000020)

#define SYSCTL_GPIO_IN_GPIO_IN_RST          0x0

__INLINE uint32_t sysctl_gpio_in_gpio_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(SYSCTL_GPIO_IN_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief MISC_CNTL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    NMB_IO_BUSY               0              
 *    04    BOOTROM_ENABLE            0              
 *    00    SOFT_RESET_REQ            0              
 * </pre>
 */
#define SYSCTL_MISC_CNTL_ADDR        (REG_SYSCTL_BASE_ADDR+0x000000E0)
#define SYSCTL_MISC_CNTL_OFFSET      0x000000E0
#define SYSCTL_MISC_CNTL_INDEX       0x00000038
#define SYSCTL_MISC_CNTL_RESET       0x00000000

__INLINE uint32_t  sysctl_misc_cntl_get(void)
{
	return REG_PL_RD(SYSCTL_MISC_CNTL_ADDR);
}

__INLINE void sysctl_misc_cntl_set(uint32_t value)
{
	REG_PL_WR(SYSCTL_MISC_CNTL_ADDR, value);
}

// field definitions
#define SYSCTL_MISC_CNTL_NMB_IO_BUSY_BIT    ((uint32_t)0x80000000)
#define SYSCTL_MISC_CNTL_NMB_IO_BUSY_POS    31
#define SYSCTL_MISC_CNTL_BOOTROM_ENABLE_BIT    ((uint32_t)0x00000010)
#define SYSCTL_MISC_CNTL_BOOTROM_ENABLE_POS    4
#define SYSCTL_MISC_CNTL_SOFT_RESET_REQ_BIT    ((uint32_t)0x00000001)
#define SYSCTL_MISC_CNTL_SOFT_RESET_REQ_POS    0

#define SYSCTL_MISC_CNTL_NMB_IO_BUSY_RST    0x0
#define SYSCTL_MISC_CNTL_BOOTROM_ENABLE_RST    0x0
#define SYSCTL_MISC_CNTL_SOFT_RESET_REQ_RST    0x0

__INLINE void sysctl_misc_cntl_pack(uint8_t nmb_io_busy, uint8_t bootrom_enable, uint8_t soft_reset_req)
{
	ASSERT_ERR((((uint32_t)nmb_io_busy << 31) & ~((uint32_t)0x80000000)) == 0);
	ASSERT_ERR((((uint32_t)bootrom_enable << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)soft_reset_req << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(SYSCTL_MISC_CNTL_ADDR,  ((uint32_t)nmb_io_busy << 31) |((uint32_t)bootrom_enable << 4) |((uint32_t)soft_reset_req << 0));
}

__INLINE void sysctl_misc_cntl_unpack(uint8_t* nmb_io_busy, uint8_t* bootrom_enable, uint8_t* soft_reset_req)
{
	uint32_t localVal = REG_PL_RD(SYSCTL_MISC_CNTL_ADDR);

	*nmb_io_busy = (localVal & ((uint32_t)0x80000000)) >>  31;
	*bootrom_enable = (localVal & ((uint32_t)0x00000010)) >>  4;
	*soft_reset_req = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t sysctl_misc_cntl_nmb_io_busy_getf(void)
{
	uint32_t localVal = REG_PL_RD(SYSCTL_MISC_CNTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE uint8_t sysctl_misc_cntl_bootrom_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(SYSCTL_MISC_CNTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void sysctl_misc_cntl_bootrom_enable_setf(uint8_t bootromenable)
{
	ASSERT_ERR((((uint32_t)bootromenable << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(SYSCTL_MISC_CNTL_ADDR, (REG_PL_RD(SYSCTL_MISC_CNTL_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)bootromenable <<4));
}
__INLINE uint8_t sysctl_misc_cntl_soft_reset_req_getf(void)
{
	uint32_t localVal = REG_PL_RD(SYSCTL_MISC_CNTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void sysctl_misc_cntl_soft_reset_req_setf(uint8_t softresetreq)
{
	ASSERT_ERR((((uint32_t)softresetreq << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(SYSCTL_MISC_CNTL_ADDR, (REG_PL_RD(SYSCTL_MISC_CNTL_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)softresetreq <<0));
}

/**
 * @brief CLOCK_CNTL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    17:13 MPIF_WR_RD_WR             0xB
 *    12:10 MPIF_READ_WRITE           0x2
 *    04:00 MPIF_CLK_DELAY            0x0
 * </pre>
 */
#define SYSCTL_CLOCK_CNTL_ADDR        (REG_SYSCTL_BASE_ADDR+0x000000E4)
#define SYSCTL_CLOCK_CNTL_OFFSET      0x000000E4
#define SYSCTL_CLOCK_CNTL_INDEX       0x00000039
#define SYSCTL_CLOCK_CNTL_RESET       0x00016800

__INLINE uint32_t  sysctl_clock_cntl_get(void)
{
	return REG_PL_RD(SYSCTL_CLOCK_CNTL_ADDR);
}

__INLINE void sysctl_clock_cntl_set(uint32_t value)
{
	REG_PL_WR(SYSCTL_CLOCK_CNTL_ADDR, value);
}

// field definitions
#define SYSCTL_CLOCK_CNTL_MPIF_WR_RD_WR_MASK    ((uint32_t)0x0003E000)
#define SYSCTL_CLOCK_CNTL_MPIF_WR_RD_WR_LSB    13
#define SYSCTL_CLOCK_CNTL_MPIF_WR_RD_WR_WIDTH    ((uint32_t)0x00000005)
#define SYSCTL_CLOCK_CNTL_MPIF_READ_WRITE_MASK    ((uint32_t)0x00001C00)
#define SYSCTL_CLOCK_CNTL_MPIF_READ_WRITE_LSB    10
#define SYSCTL_CLOCK_CNTL_MPIF_READ_WRITE_WIDTH    ((uint32_t)0x00000003)
#define SYSCTL_CLOCK_CNTL_MPIF_CLK_DELAY_MASK    ((uint32_t)0x0000001F)
#define SYSCTL_CLOCK_CNTL_MPIF_CLK_DELAY_LSB    0
#define SYSCTL_CLOCK_CNTL_MPIF_CLK_DELAY_WIDTH    ((uint32_t)0x00000005)

#define SYSCTL_CLOCK_CNTL_MPIF_WR_RD_WR_RST    0xB
#define SYSCTL_CLOCK_CNTL_MPIF_READ_WRITE_RST    0x2
#define SYSCTL_CLOCK_CNTL_MPIF_CLK_DELAY_RST    0x0

__INLINE void sysctl_clock_cntl_pack(uint8_t mpif_wr_rd_wr, uint8_t mpif_read_write, uint8_t mpif_clk_delay)
{
	ASSERT_ERR((((uint32_t)mpif_wr_rd_wr << 13) & ~((uint32_t)0x0003E000)) == 0);
	ASSERT_ERR((((uint32_t)mpif_read_write << 10) & ~((uint32_t)0x00001C00)) == 0);
	ASSERT_ERR((((uint32_t)mpif_clk_delay << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(SYSCTL_CLOCK_CNTL_ADDR,  ((uint32_t)mpif_wr_rd_wr << 13) |((uint32_t)mpif_read_write << 10) |((uint32_t)mpif_clk_delay << 0));
}

__INLINE void sysctl_clock_cntl_unpack(uint8_t* mpif_wr_rd_wr, uint8_t* mpif_read_write, uint8_t* mpif_clk_delay)
{
	uint32_t localVal = REG_PL_RD(SYSCTL_CLOCK_CNTL_ADDR);

	*mpif_wr_rd_wr = (localVal & ((uint32_t)0x0003E000)) >>  13;
	*mpif_read_write = (localVal & ((uint32_t)0x00001C00)) >>  10;
	*mpif_clk_delay = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t sysctl_clock_cntl_mpif_wr_rd_wr_getf(void)
{
	uint32_t localVal = REG_PL_RD(SYSCTL_CLOCK_CNTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0003E000)) >> 13);
}
__INLINE uint8_t sysctl_clock_cntl_mpif_read_write_getf(void)
{
	uint32_t localVal = REG_PL_RD(SYSCTL_CLOCK_CNTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001C00)) >> 10);
}
__INLINE void sysctl_clock_cntl_mpif_read_write_setf(uint8_t mpifreadwrite)
{
	ASSERT_ERR((((uint32_t)mpifreadwrite << 10) & ~((uint32_t)0x00001C00)) == 0);
	REG_PL_WR(SYSCTL_CLOCK_CNTL_ADDR, (REG_PL_RD(SYSCTL_CLOCK_CNTL_ADDR) & ~((uint32_t)0x00001C00)) | ((uint32_t)mpifreadwrite <<10));
}
__INLINE uint8_t sysctl_clock_cntl_mpif_clk_delay_getf(void)
{
	uint32_t localVal = REG_PL_RD(SYSCTL_CLOCK_CNTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void sysctl_clock_cntl_mpif_clk_delay_setf(uint8_t mpifclkdelay)
{
	ASSERT_ERR((((uint32_t)mpifclkdelay << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(SYSCTL_CLOCK_CNTL_ADDR, (REG_PL_RD(SYSCTL_CLOCK_CNTL_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)mpifclkdelay <<0));
}


#undef DBG_FILEID
#endif //_REG_SYSCTL_H_

#ifndef _REG_BMU_H_
#define _REG_BMU_H_

#include <stdint.h>
#include "_reg_bmu.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define DBG_FILEID __REG_BMU__H__FILEID__

#define REG_BMU_COUNT  139


/**
 * @brief BMU_SPR_ELMNT_INIT_0 register definition
 *  Spare Element Address0 Init register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SPARE_ELEMENT_ADDRESS_INIT 0x0
 * </pre>
 */
#define BMU_BMU_SPR_ELMNT_INIT_0_ADDR        (REG_BMU_BASE_ADDR+0x00000000)
#define BMU_BMU_SPR_ELMNT_INIT_0_OFFSET      0x00000000
#define BMU_BMU_SPR_ELMNT_INIT_0_INDEX       0x00000000
#define BMU_BMU_SPR_ELMNT_INIT_0_RESET       0x00000000

__INLINE void bmu_bmu_spr_elmnt_init_0_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_SPR_ELMNT_INIT_0_ADDR, value);
}

// field definitions
#define BMU_BMU_SPR_ELMNT_INIT_0_SPARE_ELEMENT_ADDRESS_INIT_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_SPR_ELMNT_INIT_0_SPARE_ELEMENT_ADDRESS_INIT_LSB    0
#define BMU_BMU_SPR_ELMNT_INIT_0_SPARE_ELEMENT_ADDRESS_INIT_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_SPR_ELMNT_INIT_0_SPARE_ELEMENT_ADDRESS_INIT_RST    0x0

__INLINE void bmu_bmu_spr_elmnt_init_0_spare_element_address_init_setf(uint32_t spareelementaddressinit)
{
	ASSERT_ERR((((uint32_t)spareelementaddressinit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BMU_SPR_ELMNT_INIT_0_ADDR, (uint32_t)spareelementaddressinit << 0);
}

/**
 * @brief BMU_SPR_ELMNT_INIT_1 register definition
 *  Spare Element Address1 Init register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SPARE_ELEMENT_ADDRESS_INIT 0x0
 * </pre>
 */
#define BMU_BMU_SPR_ELMNT_INIT_1_ADDR        (REG_BMU_BASE_ADDR+0x00000004)
#define BMU_BMU_SPR_ELMNT_INIT_1_OFFSET      0x00000004
#define BMU_BMU_SPR_ELMNT_INIT_1_INDEX       0x00000001
#define BMU_BMU_SPR_ELMNT_INIT_1_RESET       0x00000000

__INLINE void bmu_bmu_spr_elmnt_init_1_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_SPR_ELMNT_INIT_1_ADDR, value);
}

// field definitions
#define BMU_BMU_SPR_ELMNT_INIT_1_SPARE_ELEMENT_ADDRESS_INIT_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_SPR_ELMNT_INIT_1_SPARE_ELEMENT_ADDRESS_INIT_LSB    0
#define BMU_BMU_SPR_ELMNT_INIT_1_SPARE_ELEMENT_ADDRESS_INIT_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_SPR_ELMNT_INIT_1_SPARE_ELEMENT_ADDRESS_INIT_RST    0x0

__INLINE void bmu_bmu_spr_elmnt_init_1_spare_element_address_init_setf(uint32_t spareelementaddressinit)
{
	ASSERT_ERR((((uint32_t)spareelementaddressinit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BMU_SPR_ELMNT_INIT_1_ADDR, (uint32_t)spareelementaddressinit << 0);
}

/**
 * @brief BMU_SPR_ELMNT_INIT_2 register definition
 *  Spare Element Address2 Init register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SPARE_ELEMENT_ADDRESS_INIT 0x0
 * </pre>
 */
#define BMU_BMU_SPR_ELMNT_INIT_2_ADDR        (REG_BMU_BASE_ADDR+0x00000008)
#define BMU_BMU_SPR_ELMNT_INIT_2_OFFSET      0x00000008
#define BMU_BMU_SPR_ELMNT_INIT_2_INDEX       0x00000002
#define BMU_BMU_SPR_ELMNT_INIT_2_RESET       0x00000000

__INLINE void bmu_bmu_spr_elmnt_init_2_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_SPR_ELMNT_INIT_2_ADDR, value);
}

// field definitions
#define BMU_BMU_SPR_ELMNT_INIT_2_SPARE_ELEMENT_ADDRESS_INIT_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_SPR_ELMNT_INIT_2_SPARE_ELEMENT_ADDRESS_INIT_LSB    0
#define BMU_BMU_SPR_ELMNT_INIT_2_SPARE_ELEMENT_ADDRESS_INIT_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_SPR_ELMNT_INIT_2_SPARE_ELEMENT_ADDRESS_INIT_RST    0x0

__INLINE void bmu_bmu_spr_elmnt_init_2_spare_element_address_init_setf(uint32_t spareelementaddressinit)
{
	ASSERT_ERR((((uint32_t)spareelementaddressinit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BMU_SPR_ELMNT_INIT_2_ADDR, (uint32_t)spareelementaddressinit << 0);
}

/**
 * @brief BMU_SPR_ELMNT_INIT_3 register definition
 *  Spare Element Address3 Init register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SPARE_ELEMENT_ADDRESS_INIT 0x0
 * </pre>
 */
#define BMU_BMU_SPR_ELMNT_INIT_3_ADDR        (REG_BMU_BASE_ADDR+0x0000000C)
#define BMU_BMU_SPR_ELMNT_INIT_3_OFFSET      0x0000000C
#define BMU_BMU_SPR_ELMNT_INIT_3_INDEX       0x00000003
#define BMU_BMU_SPR_ELMNT_INIT_3_RESET       0x00000000

__INLINE void bmu_bmu_spr_elmnt_init_3_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_SPR_ELMNT_INIT_3_ADDR, value);
}

// field definitions
#define BMU_BMU_SPR_ELMNT_INIT_3_SPARE_ELEMENT_ADDRESS_INIT_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_SPR_ELMNT_INIT_3_SPARE_ELEMENT_ADDRESS_INIT_LSB    0
#define BMU_BMU_SPR_ELMNT_INIT_3_SPARE_ELEMENT_ADDRESS_INIT_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_SPR_ELMNT_INIT_3_SPARE_ELEMENT_ADDRESS_INIT_RST    0x0

__INLINE void bmu_bmu_spr_elmnt_init_3_spare_element_address_init_setf(uint32_t spareelementaddressinit)
{
	ASSERT_ERR((((uint32_t)spareelementaddressinit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BMU_SPR_ELMNT_INIT_3_ADDR, (uint32_t)spareelementaddressinit << 0);
}

/**
 * @brief BMU_SPR_ELMNT_INIT_4 register definition
 *  Spare Element Address4 Init register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SPARE_ELEMENT_ADDRESS_INIT 0x0
 * </pre>
 */
#define BMU_BMU_SPR_ELMNT_INIT_4_ADDR        (REG_BMU_BASE_ADDR+0x00000010)
#define BMU_BMU_SPR_ELMNT_INIT_4_OFFSET      0x00000010
#define BMU_BMU_SPR_ELMNT_INIT_4_INDEX       0x00000004
#define BMU_BMU_SPR_ELMNT_INIT_4_RESET       0x00000000

__INLINE void bmu_bmu_spr_elmnt_init_4_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_SPR_ELMNT_INIT_4_ADDR, value);
}

// field definitions
#define BMU_BMU_SPR_ELMNT_INIT_4_SPARE_ELEMENT_ADDRESS_INIT_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_SPR_ELMNT_INIT_4_SPARE_ELEMENT_ADDRESS_INIT_LSB    0
#define BMU_BMU_SPR_ELMNT_INIT_4_SPARE_ELEMENT_ADDRESS_INIT_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_SPR_ELMNT_INIT_4_SPARE_ELEMENT_ADDRESS_INIT_RST    0x0

__INLINE void bmu_bmu_spr_elmnt_init_4_spare_element_address_init_setf(uint32_t spareelementaddressinit)
{
	ASSERT_ERR((((uint32_t)spareelementaddressinit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BMU_SPR_ELMNT_INIT_4_ADDR, (uint32_t)spareelementaddressinit << 0);
}

/**
 * @brief BMU_SPR_ELMNT_INIT_5 register definition
 *  Spare Element Address5 Init register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SPARE_ELEMENT_ADDRESS_INIT 0x0
 * </pre>
 */
#define BMU_BMU_SPR_ELMNT_INIT_5_ADDR        (REG_BMU_BASE_ADDR+0x00000014)
#define BMU_BMU_SPR_ELMNT_INIT_5_OFFSET      0x00000014
#define BMU_BMU_SPR_ELMNT_INIT_5_INDEX       0x00000005
#define BMU_BMU_SPR_ELMNT_INIT_5_RESET       0x00000000

__INLINE void bmu_bmu_spr_elmnt_init_5_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_SPR_ELMNT_INIT_5_ADDR, value);
}

// field definitions
#define BMU_BMU_SPR_ELMNT_INIT_5_SPARE_ELEMENT_ADDRESS_INIT_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_SPR_ELMNT_INIT_5_SPARE_ELEMENT_ADDRESS_INIT_LSB    0
#define BMU_BMU_SPR_ELMNT_INIT_5_SPARE_ELEMENT_ADDRESS_INIT_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_SPR_ELMNT_INIT_5_SPARE_ELEMENT_ADDRESS_INIT_RST    0x0

__INLINE void bmu_bmu_spr_elmnt_init_5_spare_element_address_init_setf(uint32_t spareelementaddressinit)
{
	ASSERT_ERR((((uint32_t)spareelementaddressinit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BMU_SPR_ELMNT_INIT_5_ADDR, (uint32_t)spareelementaddressinit << 0);
}

/**
 * @brief BMU_SPR_ELMNT_INIT_6 register definition
 *  Spare Element Address6 Init register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SPARE_ELEMENT_ADDRESS_INIT 0x0
 * </pre>
 */
#define BMU_BMU_SPR_ELMNT_INIT_6_ADDR        (REG_BMU_BASE_ADDR+0x00000018)
#define BMU_BMU_SPR_ELMNT_INIT_6_OFFSET      0x00000018
#define BMU_BMU_SPR_ELMNT_INIT_6_INDEX       0x00000006
#define BMU_BMU_SPR_ELMNT_INIT_6_RESET       0x00000000

__INLINE void bmu_bmu_spr_elmnt_init_6_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_SPR_ELMNT_INIT_6_ADDR, value);
}

// field definitions
#define BMU_BMU_SPR_ELMNT_INIT_6_SPARE_ELEMENT_ADDRESS_INIT_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_SPR_ELMNT_INIT_6_SPARE_ELEMENT_ADDRESS_INIT_LSB    0
#define BMU_BMU_SPR_ELMNT_INIT_6_SPARE_ELEMENT_ADDRESS_INIT_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_SPR_ELMNT_INIT_6_SPARE_ELEMENT_ADDRESS_INIT_RST    0x0

__INLINE void bmu_bmu_spr_elmnt_init_6_spare_element_address_init_setf(uint32_t spareelementaddressinit)
{
	ASSERT_ERR((((uint32_t)spareelementaddressinit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BMU_SPR_ELMNT_INIT_6_ADDR, (uint32_t)spareelementaddressinit << 0);
}

/**
 * @brief BMU_SPR_ELMNT_INIT_7 register definition
 *  Spare Element Address7 Init register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SPARE_ELEMENT_ADDRESS_INIT 0x0
 * </pre>
 */
#define BMU_BMU_SPR_ELMNT_INIT_7_ADDR        (REG_BMU_BASE_ADDR+0x0000001C)
#define BMU_BMU_SPR_ELMNT_INIT_7_OFFSET      0x0000001C
#define BMU_BMU_SPR_ELMNT_INIT_7_INDEX       0x00000007
#define BMU_BMU_SPR_ELMNT_INIT_7_RESET       0x00000000

__INLINE void bmu_bmu_spr_elmnt_init_7_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_SPR_ELMNT_INIT_7_ADDR, value);
}

// field definitions
#define BMU_BMU_SPR_ELMNT_INIT_7_SPARE_ELEMENT_ADDRESS_INIT_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_SPR_ELMNT_INIT_7_SPARE_ELEMENT_ADDRESS_INIT_LSB    0
#define BMU_BMU_SPR_ELMNT_INIT_7_SPARE_ELEMENT_ADDRESS_INIT_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_SPR_ELMNT_INIT_7_SPARE_ELEMENT_ADDRESS_INIT_RST    0x0

__INLINE void bmu_bmu_spr_elmnt_init_7_spare_element_address_init_setf(uint32_t spareelementaddressinit)
{
	ASSERT_ERR((((uint32_t)spareelementaddressinit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BMU_SPR_ELMNT_INIT_7_ADDR, (uint32_t)spareelementaddressinit << 0);
}

/**
 * @brief BMU_SPR_ELMNT_0 register definition
 *  Spare Element Address0 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BMU_SPARE_ELEMENT_ADDRESS 0x0
 * </pre>
 */
#define BMU_BMU_SPR_ELMNT_0_ADDR        (REG_BMU_BASE_ADDR+0x00000040)
#define BMU_BMU_SPR_ELMNT_0_OFFSET      0x00000040
#define BMU_BMU_SPR_ELMNT_0_INDEX       0x00000010
#define BMU_BMU_SPR_ELMNT_0_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_spr_elmnt_0_get(void)
{
	return REG_PL_RD(BMU_BMU_SPR_ELMNT_0_ADDR);
}

// field definitions
#define BMU_BMU_SPR_ELMNT_0_BMU_SPARE_ELEMENT_ADDRESS_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_SPR_ELMNT_0_BMU_SPARE_ELEMENT_ADDRESS_LSB    0
#define BMU_BMU_SPR_ELMNT_0_BMU_SPARE_ELEMENT_ADDRESS_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_SPR_ELMNT_0_BMU_SPARE_ELEMENT_ADDRESS_RST    0x0

__INLINE uint32_t bmu_bmu_spr_elmnt_0_bmu_spare_element_address_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_SPR_ELMNT_0_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BMU_SPR_ELMNT_1 register definition
 *  Spare Element Address1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BMU_SPARE_ELEMENT_ADDRESS 0x0
 * </pre>
 */
#define BMU_BMU_SPR_ELMNT_1_ADDR        (REG_BMU_BASE_ADDR+0x00000044)
#define BMU_BMU_SPR_ELMNT_1_OFFSET      0x00000044
#define BMU_BMU_SPR_ELMNT_1_INDEX       0x00000011
#define BMU_BMU_SPR_ELMNT_1_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_spr_elmnt_1_get(void)
{
	return REG_PL_RD(BMU_BMU_SPR_ELMNT_1_ADDR);
}

// field definitions
#define BMU_BMU_SPR_ELMNT_1_BMU_SPARE_ELEMENT_ADDRESS_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_SPR_ELMNT_1_BMU_SPARE_ELEMENT_ADDRESS_LSB    0
#define BMU_BMU_SPR_ELMNT_1_BMU_SPARE_ELEMENT_ADDRESS_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_SPR_ELMNT_1_BMU_SPARE_ELEMENT_ADDRESS_RST    0x0

__INLINE uint32_t bmu_bmu_spr_elmnt_1_bmu_spare_element_address_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_SPR_ELMNT_1_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BMU_SPR_ELMNT_2 register definition
 *  Spare Element Address2 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BMU_SPARE_ELEMENT_ADDRESS 0x0
 * </pre>
 */
#define BMU_BMU_SPR_ELMNT_2_ADDR        (REG_BMU_BASE_ADDR+0x00000048)
#define BMU_BMU_SPR_ELMNT_2_OFFSET      0x00000048
#define BMU_BMU_SPR_ELMNT_2_INDEX       0x00000012
#define BMU_BMU_SPR_ELMNT_2_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_spr_elmnt_2_get(void)
{
	return REG_PL_RD(BMU_BMU_SPR_ELMNT_2_ADDR);
}

// field definitions
#define BMU_BMU_SPR_ELMNT_2_BMU_SPARE_ELEMENT_ADDRESS_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_SPR_ELMNT_2_BMU_SPARE_ELEMENT_ADDRESS_LSB    0
#define BMU_BMU_SPR_ELMNT_2_BMU_SPARE_ELEMENT_ADDRESS_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_SPR_ELMNT_2_BMU_SPARE_ELEMENT_ADDRESS_RST    0x0

__INLINE uint32_t bmu_bmu_spr_elmnt_2_bmu_spare_element_address_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_SPR_ELMNT_2_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BMU_SPR_ELMNT_3 register definition
 *  Spare Element Address3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BMU_SPARE_ELEMENT_ADDRESS 0x0
 * </pre>
 */
#define BMU_BMU_SPR_ELMNT_3_ADDR        (REG_BMU_BASE_ADDR+0x0000004C)
#define BMU_BMU_SPR_ELMNT_3_OFFSET      0x0000004C
#define BMU_BMU_SPR_ELMNT_3_INDEX       0x00000013
#define BMU_BMU_SPR_ELMNT_3_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_spr_elmnt_3_get(void)
{
	return REG_PL_RD(BMU_BMU_SPR_ELMNT_3_ADDR);
}

// field definitions
#define BMU_BMU_SPR_ELMNT_3_BMU_SPARE_ELEMENT_ADDRESS_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_SPR_ELMNT_3_BMU_SPARE_ELEMENT_ADDRESS_LSB    0
#define BMU_BMU_SPR_ELMNT_3_BMU_SPARE_ELEMENT_ADDRESS_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_SPR_ELMNT_3_BMU_SPARE_ELEMENT_ADDRESS_RST    0x0

__INLINE uint32_t bmu_bmu_spr_elmnt_3_bmu_spare_element_address_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_SPR_ELMNT_3_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BMU_SPR_ELMNT_4 register definition
 *  Spare Element Address4 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BMU_SPARE_ELEMENT_ADDRESS 0x0
 * </pre>
 */
#define BMU_BMU_SPR_ELMNT_4_ADDR        (REG_BMU_BASE_ADDR+0x00000050)
#define BMU_BMU_SPR_ELMNT_4_OFFSET      0x00000050
#define BMU_BMU_SPR_ELMNT_4_INDEX       0x00000014
#define BMU_BMU_SPR_ELMNT_4_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_spr_elmnt_4_get(void)
{
	return REG_PL_RD(BMU_BMU_SPR_ELMNT_4_ADDR);
}

// field definitions
#define BMU_BMU_SPR_ELMNT_4_BMU_SPARE_ELEMENT_ADDRESS_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_SPR_ELMNT_4_BMU_SPARE_ELEMENT_ADDRESS_LSB    0
#define BMU_BMU_SPR_ELMNT_4_BMU_SPARE_ELEMENT_ADDRESS_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_SPR_ELMNT_4_BMU_SPARE_ELEMENT_ADDRESS_RST    0x0

__INLINE uint32_t bmu_bmu_spr_elmnt_4_bmu_spare_element_address_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_SPR_ELMNT_4_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BMU_SPR_ELMNT_5 register definition
 *  Spare Element Address5 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BMU_SPARE_ELEMENT_ADDRESS 0x0
 * </pre>
 */
#define BMU_BMU_SPR_ELMNT_5_ADDR        (REG_BMU_BASE_ADDR+0x00000054)
#define BMU_BMU_SPR_ELMNT_5_OFFSET      0x00000054
#define BMU_BMU_SPR_ELMNT_5_INDEX       0x00000015
#define BMU_BMU_SPR_ELMNT_5_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_spr_elmnt_5_get(void)
{
	return REG_PL_RD(BMU_BMU_SPR_ELMNT_5_ADDR);
}

// field definitions
#define BMU_BMU_SPR_ELMNT_5_BMU_SPARE_ELEMENT_ADDRESS_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_SPR_ELMNT_5_BMU_SPARE_ELEMENT_ADDRESS_LSB    0
#define BMU_BMU_SPR_ELMNT_5_BMU_SPARE_ELEMENT_ADDRESS_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_SPR_ELMNT_5_BMU_SPARE_ELEMENT_ADDRESS_RST    0x0

__INLINE uint32_t bmu_bmu_spr_elmnt_5_bmu_spare_element_address_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_SPR_ELMNT_5_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BMU_SPR_ELMNT_6 register definition
 *  Spare Element Address6 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BMU_SPARE_ELEMENT_ADDRESS 0x0
 * </pre>
 */
#define BMU_BMU_SPR_ELMNT_6_ADDR        (REG_BMU_BASE_ADDR+0x00000058)
#define BMU_BMU_SPR_ELMNT_6_OFFSET      0x00000058
#define BMU_BMU_SPR_ELMNT_6_INDEX       0x00000016
#define BMU_BMU_SPR_ELMNT_6_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_spr_elmnt_6_get(void)
{
	return REG_PL_RD(BMU_BMU_SPR_ELMNT_6_ADDR);
}

// field definitions
#define BMU_BMU_SPR_ELMNT_6_BMU_SPARE_ELEMENT_ADDRESS_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_SPR_ELMNT_6_BMU_SPARE_ELEMENT_ADDRESS_LSB    0
#define BMU_BMU_SPR_ELMNT_6_BMU_SPARE_ELEMENT_ADDRESS_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_SPR_ELMNT_6_BMU_SPARE_ELEMENT_ADDRESS_RST    0x0

__INLINE uint32_t bmu_bmu_spr_elmnt_6_bmu_spare_element_address_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_SPR_ELMNT_6_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BMU_SPR_ELMNT_7 register definition
 *  Spare Element Address7 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BMU_SPARE_ELEMENT_ADDRESS 0x0
 * </pre>
 */
#define BMU_BMU_SPR_ELMNT_7_ADDR        (REG_BMU_BASE_ADDR+0x0000005C)
#define BMU_BMU_SPR_ELMNT_7_OFFSET      0x0000005C
#define BMU_BMU_SPR_ELMNT_7_INDEX       0x00000017
#define BMU_BMU_SPR_ELMNT_7_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_spr_elmnt_7_get(void)
{
	return REG_PL_RD(BMU_BMU_SPR_ELMNT_7_ADDR);
}

// field definitions
#define BMU_BMU_SPR_ELMNT_7_BMU_SPARE_ELEMENT_ADDRESS_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_SPR_ELMNT_7_BMU_SPARE_ELEMENT_ADDRESS_LSB    0
#define BMU_BMU_SPR_ELMNT_7_BMU_SPARE_ELEMENT_ADDRESS_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_SPR_ELMNT_7_BMU_SPARE_ELEMENT_ADDRESS_RST    0x0

__INLINE uint32_t bmu_bmu_spr_elmnt_7_bmu_spare_element_address_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_SPR_ELMNT_7_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BMU_ALLOC_CNT_INIT_0 register definition
 *  Allocated Counter Init register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 ALLOCATED_COUNTER_INIT    0x0
 * </pre>
 */
#define BMU_BMU_ALLOC_CNT_INIT_0_ADDR        (REG_BMU_BASE_ADDR+0x00000080)
#define BMU_BMU_ALLOC_CNT_INIT_0_OFFSET      0x00000080
#define BMU_BMU_ALLOC_CNT_INIT_0_INDEX       0x00000020
#define BMU_BMU_ALLOC_CNT_INIT_0_RESET       0x00000000

__INLINE void bmu_bmu_alloc_cnt_init_0_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_ALLOC_CNT_INIT_0_ADDR, value);
}

// field definitions
#define BMU_BMU_ALLOC_CNT_INIT_0_ALLOCATED_COUNTER_INIT_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_ALLOC_CNT_INIT_0_ALLOCATED_COUNTER_INIT_LSB    0
#define BMU_BMU_ALLOC_CNT_INIT_0_ALLOCATED_COUNTER_INIT_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_ALLOC_CNT_INIT_0_ALLOCATED_COUNTER_INIT_RST    0x0

__INLINE void bmu_bmu_alloc_cnt_init_0_allocated_counter_init_setf(uint32_t allocatedcounterinit)
{
	ASSERT_ERR((((uint32_t)allocatedcounterinit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BMU_ALLOC_CNT_INIT_0_ADDR, (uint32_t)allocatedcounterinit << 0);
}

/**
 * @brief BMU_ALLOC_CNT_INIT_1 register definition
 *  Allocated Counter Init register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 ALLOCATED_COUNTER_INIT    0x0
 * </pre>
 */
#define BMU_BMU_ALLOC_CNT_INIT_1_ADDR        (REG_BMU_BASE_ADDR+0x00000084)
#define BMU_BMU_ALLOC_CNT_INIT_1_OFFSET      0x00000084
#define BMU_BMU_ALLOC_CNT_INIT_1_INDEX       0x00000021
#define BMU_BMU_ALLOC_CNT_INIT_1_RESET       0x00000000

__INLINE void bmu_bmu_alloc_cnt_init_1_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_ALLOC_CNT_INIT_1_ADDR, value);
}

// field definitions
#define BMU_BMU_ALLOC_CNT_INIT_1_ALLOCATED_COUNTER_INIT_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_ALLOC_CNT_INIT_1_ALLOCATED_COUNTER_INIT_LSB    0
#define BMU_BMU_ALLOC_CNT_INIT_1_ALLOCATED_COUNTER_INIT_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_ALLOC_CNT_INIT_1_ALLOCATED_COUNTER_INIT_RST    0x0

__INLINE void bmu_bmu_alloc_cnt_init_1_allocated_counter_init_setf(uint32_t allocatedcounterinit)
{
	ASSERT_ERR((((uint32_t)allocatedcounterinit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BMU_ALLOC_CNT_INIT_1_ADDR, (uint32_t)allocatedcounterinit << 0);
}

/**
 * @brief BMU_ALLOC_CNT_INIT_2 register definition
 *  Allocated Counter Init register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 ALLOCATED_COUNTER_INIT    0x0
 * </pre>
 */
#define BMU_BMU_ALLOC_CNT_INIT_2_ADDR        (REG_BMU_BASE_ADDR+0x00000088)
#define BMU_BMU_ALLOC_CNT_INIT_2_OFFSET      0x00000088
#define BMU_BMU_ALLOC_CNT_INIT_2_INDEX       0x00000022
#define BMU_BMU_ALLOC_CNT_INIT_2_RESET       0x00000000

__INLINE void bmu_bmu_alloc_cnt_init_2_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_ALLOC_CNT_INIT_2_ADDR, value);
}

// field definitions
#define BMU_BMU_ALLOC_CNT_INIT_2_ALLOCATED_COUNTER_INIT_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_ALLOC_CNT_INIT_2_ALLOCATED_COUNTER_INIT_LSB    0
#define BMU_BMU_ALLOC_CNT_INIT_2_ALLOCATED_COUNTER_INIT_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_ALLOC_CNT_INIT_2_ALLOCATED_COUNTER_INIT_RST    0x0

__INLINE void bmu_bmu_alloc_cnt_init_2_allocated_counter_init_setf(uint32_t allocatedcounterinit)
{
	ASSERT_ERR((((uint32_t)allocatedcounterinit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BMU_ALLOC_CNT_INIT_2_ADDR, (uint32_t)allocatedcounterinit << 0);
}

/**
 * @brief BMU_ALLOC_CNT_INIT_3 register definition
 *  Allocated Counter Init register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 ALLOCATED_COUNTER_INIT    0x0
 * </pre>
 */
#define BMU_BMU_ALLOC_CNT_INIT_3_ADDR        (REG_BMU_BASE_ADDR+0x0000008C)
#define BMU_BMU_ALLOC_CNT_INIT_3_OFFSET      0x0000008C
#define BMU_BMU_ALLOC_CNT_INIT_3_INDEX       0x00000023
#define BMU_BMU_ALLOC_CNT_INIT_3_RESET       0x00000000

__INLINE void bmu_bmu_alloc_cnt_init_3_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_ALLOC_CNT_INIT_3_ADDR, value);
}

// field definitions
#define BMU_BMU_ALLOC_CNT_INIT_3_ALLOCATED_COUNTER_INIT_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_ALLOC_CNT_INIT_3_ALLOCATED_COUNTER_INIT_LSB    0
#define BMU_BMU_ALLOC_CNT_INIT_3_ALLOCATED_COUNTER_INIT_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_ALLOC_CNT_INIT_3_ALLOCATED_COUNTER_INIT_RST    0x0

__INLINE void bmu_bmu_alloc_cnt_init_3_allocated_counter_init_setf(uint32_t allocatedcounterinit)
{
	ASSERT_ERR((((uint32_t)allocatedcounterinit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BMU_ALLOC_CNT_INIT_3_ADDR, (uint32_t)allocatedcounterinit << 0);
}

/**
 * @brief BMU_ALLOC_CNT_INIT_4 register definition
 *  Allocated Counter Init register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 ALLOCATED_COUNTER_INIT    0x0
 * </pre>
 */
#define BMU_BMU_ALLOC_CNT_INIT_4_ADDR        (REG_BMU_BASE_ADDR+0x00000090)
#define BMU_BMU_ALLOC_CNT_INIT_4_OFFSET      0x00000090
#define BMU_BMU_ALLOC_CNT_INIT_4_INDEX       0x00000024
#define BMU_BMU_ALLOC_CNT_INIT_4_RESET       0x00000000

__INLINE void bmu_bmu_alloc_cnt_init_4_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_ALLOC_CNT_INIT_4_ADDR, value);
}

// field definitions
#define BMU_BMU_ALLOC_CNT_INIT_4_ALLOCATED_COUNTER_INIT_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_ALLOC_CNT_INIT_4_ALLOCATED_COUNTER_INIT_LSB    0
#define BMU_BMU_ALLOC_CNT_INIT_4_ALLOCATED_COUNTER_INIT_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_ALLOC_CNT_INIT_4_ALLOCATED_COUNTER_INIT_RST    0x0

__INLINE void bmu_bmu_alloc_cnt_init_4_allocated_counter_init_setf(uint32_t allocatedcounterinit)
{
	ASSERT_ERR((((uint32_t)allocatedcounterinit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BMU_ALLOC_CNT_INIT_4_ADDR, (uint32_t)allocatedcounterinit << 0);
}

/**
 * @brief BMU_ALLOC_CNT_INIT_5 register definition
 *  Allocated Counter Init register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 ALLOCATED_COUNTER_INIT    0x0
 * </pre>
 */
#define BMU_BMU_ALLOC_CNT_INIT_5_ADDR        (REG_BMU_BASE_ADDR+0x00000094)
#define BMU_BMU_ALLOC_CNT_INIT_5_OFFSET      0x00000094
#define BMU_BMU_ALLOC_CNT_INIT_5_INDEX       0x00000025
#define BMU_BMU_ALLOC_CNT_INIT_5_RESET       0x00000000

__INLINE void bmu_bmu_alloc_cnt_init_5_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_ALLOC_CNT_INIT_5_ADDR, value);
}

// field definitions
#define BMU_BMU_ALLOC_CNT_INIT_5_ALLOCATED_COUNTER_INIT_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_ALLOC_CNT_INIT_5_ALLOCATED_COUNTER_INIT_LSB    0
#define BMU_BMU_ALLOC_CNT_INIT_5_ALLOCATED_COUNTER_INIT_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_ALLOC_CNT_INIT_5_ALLOCATED_COUNTER_INIT_RST    0x0

__INLINE void bmu_bmu_alloc_cnt_init_5_allocated_counter_init_setf(uint32_t allocatedcounterinit)
{
	ASSERT_ERR((((uint32_t)allocatedcounterinit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BMU_ALLOC_CNT_INIT_5_ADDR, (uint32_t)allocatedcounterinit << 0);
}

/**
 * @brief BMU_ALLOC_CNT_INIT_6 register definition
 *  Allocated Counter Init register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 ALLOCATED_COUNTER_INIT    0x0
 * </pre>
 */
#define BMU_BMU_ALLOC_CNT_INIT_6_ADDR        (REG_BMU_BASE_ADDR+0x00000098)
#define BMU_BMU_ALLOC_CNT_INIT_6_OFFSET      0x00000098
#define BMU_BMU_ALLOC_CNT_INIT_6_INDEX       0x00000026
#define BMU_BMU_ALLOC_CNT_INIT_6_RESET       0x00000000

__INLINE void bmu_bmu_alloc_cnt_init_6_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_ALLOC_CNT_INIT_6_ADDR, value);
}

// field definitions
#define BMU_BMU_ALLOC_CNT_INIT_6_ALLOCATED_COUNTER_INIT_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_ALLOC_CNT_INIT_6_ALLOCATED_COUNTER_INIT_LSB    0
#define BMU_BMU_ALLOC_CNT_INIT_6_ALLOCATED_COUNTER_INIT_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_ALLOC_CNT_INIT_6_ALLOCATED_COUNTER_INIT_RST    0x0

__INLINE void bmu_bmu_alloc_cnt_init_6_allocated_counter_init_setf(uint32_t allocatedcounterinit)
{
	ASSERT_ERR((((uint32_t)allocatedcounterinit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BMU_ALLOC_CNT_INIT_6_ADDR, (uint32_t)allocatedcounterinit << 0);
}

/**
 * @brief BMU_ALLOC_CNT_INIT_7 register definition
 *  Allocated Counter Init register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 ALLOCATED_COUNTER_INIT    0x0
 * </pre>
 */
#define BMU_BMU_ALLOC_CNT_INIT_7_ADDR        (REG_BMU_BASE_ADDR+0x0000009C)
#define BMU_BMU_ALLOC_CNT_INIT_7_OFFSET      0x0000009C
#define BMU_BMU_ALLOC_CNT_INIT_7_INDEX       0x00000027
#define BMU_BMU_ALLOC_CNT_INIT_7_RESET       0x00000000

__INLINE void bmu_bmu_alloc_cnt_init_7_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_ALLOC_CNT_INIT_7_ADDR, value);
}

// field definitions
#define BMU_BMU_ALLOC_CNT_INIT_7_ALLOCATED_COUNTER_INIT_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_ALLOC_CNT_INIT_7_ALLOCATED_COUNTER_INIT_LSB    0
#define BMU_BMU_ALLOC_CNT_INIT_7_ALLOCATED_COUNTER_INIT_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_ALLOC_CNT_INIT_7_ALLOCATED_COUNTER_INIT_RST    0x0

__INLINE void bmu_bmu_alloc_cnt_init_7_allocated_counter_init_setf(uint32_t allocatedcounterinit)
{
	ASSERT_ERR((((uint32_t)allocatedcounterinit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BMU_ALLOC_CNT_INIT_7_ADDR, (uint32_t)allocatedcounterinit << 0);
}

/**
 * @brief BMU_ALLOC_CNT_INC_0 register definition
 *  Number of elements allocated by the BAU for BMU0 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    03:00 BMU_ALLOC_CNTR_INC        0x0
 * </pre>
 */
#define BMU_BMU_ALLOC_CNT_INC_0_ADDR        (REG_BMU_BASE_ADDR+0x000000C0)
#define BMU_BMU_ALLOC_CNT_INC_0_OFFSET      0x000000C0
#define BMU_BMU_ALLOC_CNT_INC_0_INDEX       0x00000030
#define BMU_BMU_ALLOC_CNT_INC_0_RESET       0x00000000

__INLINE void bmu_bmu_alloc_cnt_inc_0_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_ALLOC_CNT_INC_0_ADDR, value);
}

// field definitions
#define BMU_BMU_ALLOC_CNT_INC_0_BMU_ALLOC_CNTR_INC_MASK    ((uint32_t)0x0000000F)
#define BMU_BMU_ALLOC_CNT_INC_0_BMU_ALLOC_CNTR_INC_LSB    0
#define BMU_BMU_ALLOC_CNT_INC_0_BMU_ALLOC_CNTR_INC_WIDTH    ((uint32_t)0x00000004)

#define BMU_BMU_ALLOC_CNT_INC_0_BMU_ALLOC_CNTR_INC_RST    0x0

__INLINE void bmu_bmu_alloc_cnt_inc_0_bmu_alloc_cntr_inc_setf(uint8_t bmualloccntrinc)
{
	ASSERT_ERR((((uint32_t)bmualloccntrinc << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(BMU_BMU_ALLOC_CNT_INC_0_ADDR, (uint32_t)bmualloccntrinc << 0);
}

/**
 * @brief BMU_ALLOC_CNT_INC_1 register definition
 *  Number of elements allocated by the BAU for BMU1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    03:00 BMU_ALLOC_CNTR_INC        0x0
 * </pre>
 */
#define BMU_BMU_ALLOC_CNT_INC_1_ADDR        (REG_BMU_BASE_ADDR+0x000000C4)
#define BMU_BMU_ALLOC_CNT_INC_1_OFFSET      0x000000C4
#define BMU_BMU_ALLOC_CNT_INC_1_INDEX       0x00000031
#define BMU_BMU_ALLOC_CNT_INC_1_RESET       0x00000000

__INLINE void bmu_bmu_alloc_cnt_inc_1_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_ALLOC_CNT_INC_1_ADDR, value);
}

// field definitions
#define BMU_BMU_ALLOC_CNT_INC_1_BMU_ALLOC_CNTR_INC_MASK    ((uint32_t)0x0000000F)
#define BMU_BMU_ALLOC_CNT_INC_1_BMU_ALLOC_CNTR_INC_LSB    0
#define BMU_BMU_ALLOC_CNT_INC_1_BMU_ALLOC_CNTR_INC_WIDTH    ((uint32_t)0x00000004)

#define BMU_BMU_ALLOC_CNT_INC_1_BMU_ALLOC_CNTR_INC_RST    0x0

__INLINE void bmu_bmu_alloc_cnt_inc_1_bmu_alloc_cntr_inc_setf(uint8_t bmualloccntrinc)
{
	ASSERT_ERR((((uint32_t)bmualloccntrinc << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(BMU_BMU_ALLOC_CNT_INC_1_ADDR, (uint32_t)bmualloccntrinc << 0);
}

/**
 * @brief BMU_ALLOC_CNT_INC_2 register definition
 *  Number of elements allocated by the BAU for BMU2 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    03:00 BMU_ALLOC_CNTR_INC        0x0
 * </pre>
 */
#define BMU_BMU_ALLOC_CNT_INC_2_ADDR        (REG_BMU_BASE_ADDR+0x000000C8)
#define BMU_BMU_ALLOC_CNT_INC_2_OFFSET      0x000000C8
#define BMU_BMU_ALLOC_CNT_INC_2_INDEX       0x00000032
#define BMU_BMU_ALLOC_CNT_INC_2_RESET       0x00000000

__INLINE void bmu_bmu_alloc_cnt_inc_2_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_ALLOC_CNT_INC_2_ADDR, value);
}

// field definitions
#define BMU_BMU_ALLOC_CNT_INC_2_BMU_ALLOC_CNTR_INC_MASK    ((uint32_t)0x0000000F)
#define BMU_BMU_ALLOC_CNT_INC_2_BMU_ALLOC_CNTR_INC_LSB    0
#define BMU_BMU_ALLOC_CNT_INC_2_BMU_ALLOC_CNTR_INC_WIDTH    ((uint32_t)0x00000004)

#define BMU_BMU_ALLOC_CNT_INC_2_BMU_ALLOC_CNTR_INC_RST    0x0

__INLINE void bmu_bmu_alloc_cnt_inc_2_bmu_alloc_cntr_inc_setf(uint8_t bmualloccntrinc)
{
	ASSERT_ERR((((uint32_t)bmualloccntrinc << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(BMU_BMU_ALLOC_CNT_INC_2_ADDR, (uint32_t)bmualloccntrinc << 0);
}

/**
 * @brief BMU_ALLOC_CNT_INC_3 register definition
 *  Number of elements allocated by the BAU for BMU3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    03:00 BMU_ALLOC_CNTR_INC        0x0
 * </pre>
 */
#define BMU_BMU_ALLOC_CNT_INC_3_ADDR        (REG_BMU_BASE_ADDR+0x000000CC)
#define BMU_BMU_ALLOC_CNT_INC_3_OFFSET      0x000000CC
#define BMU_BMU_ALLOC_CNT_INC_3_INDEX       0x00000033
#define BMU_BMU_ALLOC_CNT_INC_3_RESET       0x00000000

__INLINE void bmu_bmu_alloc_cnt_inc_3_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_ALLOC_CNT_INC_3_ADDR, value);
}

// field definitions
#define BMU_BMU_ALLOC_CNT_INC_3_BMU_ALLOC_CNTR_INC_MASK    ((uint32_t)0x0000000F)
#define BMU_BMU_ALLOC_CNT_INC_3_BMU_ALLOC_CNTR_INC_LSB    0
#define BMU_BMU_ALLOC_CNT_INC_3_BMU_ALLOC_CNTR_INC_WIDTH    ((uint32_t)0x00000004)

#define BMU_BMU_ALLOC_CNT_INC_3_BMU_ALLOC_CNTR_INC_RST    0x0

__INLINE void bmu_bmu_alloc_cnt_inc_3_bmu_alloc_cntr_inc_setf(uint8_t bmualloccntrinc)
{
	ASSERT_ERR((((uint32_t)bmualloccntrinc << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(BMU_BMU_ALLOC_CNT_INC_3_ADDR, (uint32_t)bmualloccntrinc << 0);
}

/**
 * @brief BMU_ALLOC_CNT_INC_4 register definition
 *  Number of elements allocated by the BAU for BMU4 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    03:00 BMU_ALLOC_CNTR_INC        0x0
 * </pre>
 */
#define BMU_BMU_ALLOC_CNT_INC_4_ADDR        (REG_BMU_BASE_ADDR+0x000000D0)
#define BMU_BMU_ALLOC_CNT_INC_4_OFFSET      0x000000D0
#define BMU_BMU_ALLOC_CNT_INC_4_INDEX       0x00000034
#define BMU_BMU_ALLOC_CNT_INC_4_RESET       0x00000000

__INLINE void bmu_bmu_alloc_cnt_inc_4_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_ALLOC_CNT_INC_4_ADDR, value);
}

// field definitions
#define BMU_BMU_ALLOC_CNT_INC_4_BMU_ALLOC_CNTR_INC_MASK    ((uint32_t)0x0000000F)
#define BMU_BMU_ALLOC_CNT_INC_4_BMU_ALLOC_CNTR_INC_LSB    0
#define BMU_BMU_ALLOC_CNT_INC_4_BMU_ALLOC_CNTR_INC_WIDTH    ((uint32_t)0x00000004)

#define BMU_BMU_ALLOC_CNT_INC_4_BMU_ALLOC_CNTR_INC_RST    0x0

__INLINE void bmu_bmu_alloc_cnt_inc_4_bmu_alloc_cntr_inc_setf(uint8_t bmualloccntrinc)
{
	ASSERT_ERR((((uint32_t)bmualloccntrinc << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(BMU_BMU_ALLOC_CNT_INC_4_ADDR, (uint32_t)bmualloccntrinc << 0);
}

/**
 * @brief BMU_ALLOC_CNT_INC_5 register definition
 *  Number of elements allocated by the BAU for BMU5 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    03:00 BMU_ALLOC_CNTR_INC        0x0
 * </pre>
 */
#define BMU_BMU_ALLOC_CNT_INC_5_ADDR        (REG_BMU_BASE_ADDR+0x000000D4)
#define BMU_BMU_ALLOC_CNT_INC_5_OFFSET      0x000000D4
#define BMU_BMU_ALLOC_CNT_INC_5_INDEX       0x00000035
#define BMU_BMU_ALLOC_CNT_INC_5_RESET       0x00000000

__INLINE void bmu_bmu_alloc_cnt_inc_5_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_ALLOC_CNT_INC_5_ADDR, value);
}

// field definitions
#define BMU_BMU_ALLOC_CNT_INC_5_BMU_ALLOC_CNTR_INC_MASK    ((uint32_t)0x0000000F)
#define BMU_BMU_ALLOC_CNT_INC_5_BMU_ALLOC_CNTR_INC_LSB    0
#define BMU_BMU_ALLOC_CNT_INC_5_BMU_ALLOC_CNTR_INC_WIDTH    ((uint32_t)0x00000004)

#define BMU_BMU_ALLOC_CNT_INC_5_BMU_ALLOC_CNTR_INC_RST    0x0

__INLINE void bmu_bmu_alloc_cnt_inc_5_bmu_alloc_cntr_inc_setf(uint8_t bmualloccntrinc)
{
	ASSERT_ERR((((uint32_t)bmualloccntrinc << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(BMU_BMU_ALLOC_CNT_INC_5_ADDR, (uint32_t)bmualloccntrinc << 0);
}

/**
 * @brief BMU_ALLOC_CNT_INC_6 register definition
 *  Number of elements allocated by the BAU for BMU6 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    03:00 BMU_ALLOC_CNTR_INC        0x0
 * </pre>
 */
#define BMU_BMU_ALLOC_CNT_INC_6_ADDR        (REG_BMU_BASE_ADDR+0x000000D8)
#define BMU_BMU_ALLOC_CNT_INC_6_OFFSET      0x000000D8
#define BMU_BMU_ALLOC_CNT_INC_6_INDEX       0x00000036
#define BMU_BMU_ALLOC_CNT_INC_6_RESET       0x00000000

__INLINE void bmu_bmu_alloc_cnt_inc_6_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_ALLOC_CNT_INC_6_ADDR, value);
}

// field definitions
#define BMU_BMU_ALLOC_CNT_INC_6_BMU_ALLOC_CNTR_INC_MASK    ((uint32_t)0x0000000F)
#define BMU_BMU_ALLOC_CNT_INC_6_BMU_ALLOC_CNTR_INC_LSB    0
#define BMU_BMU_ALLOC_CNT_INC_6_BMU_ALLOC_CNTR_INC_WIDTH    ((uint32_t)0x00000004)

#define BMU_BMU_ALLOC_CNT_INC_6_BMU_ALLOC_CNTR_INC_RST    0x0

__INLINE void bmu_bmu_alloc_cnt_inc_6_bmu_alloc_cntr_inc_setf(uint8_t bmualloccntrinc)
{
	ASSERT_ERR((((uint32_t)bmualloccntrinc << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(BMU_BMU_ALLOC_CNT_INC_6_ADDR, (uint32_t)bmualloccntrinc << 0);
}

/**
 * @brief BMU_ALLOC_CNT_INC_7 register definition
 *  Number of elements allocated by the BAU for BMU7 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    03:00 BMU_ALLOC_CNTR_INC        0x0
 * </pre>
 */
#define BMU_BMU_ALLOC_CNT_INC_7_ADDR        (REG_BMU_BASE_ADDR+0x000000DC)
#define BMU_BMU_ALLOC_CNT_INC_7_OFFSET      0x000000DC
#define BMU_BMU_ALLOC_CNT_INC_7_INDEX       0x00000037
#define BMU_BMU_ALLOC_CNT_INC_7_RESET       0x00000000

__INLINE void bmu_bmu_alloc_cnt_inc_7_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_ALLOC_CNT_INC_7_ADDR, value);
}

// field definitions
#define BMU_BMU_ALLOC_CNT_INC_7_BMU_ALLOC_CNTR_INC_MASK    ((uint32_t)0x0000000F)
#define BMU_BMU_ALLOC_CNT_INC_7_BMU_ALLOC_CNTR_INC_LSB    0
#define BMU_BMU_ALLOC_CNT_INC_7_BMU_ALLOC_CNTR_INC_WIDTH    ((uint32_t)0x00000004)

#define BMU_BMU_ALLOC_CNT_INC_7_BMU_ALLOC_CNTR_INC_RST    0x0

__INLINE void bmu_bmu_alloc_cnt_inc_7_bmu_alloc_cntr_inc_setf(uint8_t bmualloccntrinc)
{
	ASSERT_ERR((((uint32_t)bmualloccntrinc << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(BMU_BMU_ALLOC_CNT_INC_7_ADDR, (uint32_t)bmualloccntrinc << 0);
}

/**
 * @brief BMU_ALLOC_CNT_0 register definition
 *  Number of elements allocated by the BAU for BMU0 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BMU_ALLOCAED_COUNTER      0x0
 * </pre>
 */
#define BMU_BMU_ALLOC_CNT_0_ADDR        (REG_BMU_BASE_ADDR+0x00000100)
#define BMU_BMU_ALLOC_CNT_0_OFFSET      0x00000100
#define BMU_BMU_ALLOC_CNT_0_INDEX       0x00000040
#define BMU_BMU_ALLOC_CNT_0_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_alloc_cnt_0_get(void)
{
	return REG_PL_RD(BMU_BMU_ALLOC_CNT_0_ADDR);
}

// field definitions
#define BMU_BMU_ALLOC_CNT_0_BMU_ALLOCAED_COUNTER_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_ALLOC_CNT_0_BMU_ALLOCAED_COUNTER_LSB    0
#define BMU_BMU_ALLOC_CNT_0_BMU_ALLOCAED_COUNTER_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_ALLOC_CNT_0_BMU_ALLOCAED_COUNTER_RST    0x0

__INLINE uint32_t bmu_bmu_alloc_cnt_0_bmu_allocaed_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_ALLOC_CNT_0_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BMU_ALLOC_CNT_1 register definition
 *  Number of elements allocated by the BAU for BMU1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BMU_ALLOCAED_COUNTER      0x0
 * </pre>
 */
#define BMU_BMU_ALLOC_CNT_1_ADDR        (REG_BMU_BASE_ADDR+0x00000104)
#define BMU_BMU_ALLOC_CNT_1_OFFSET      0x00000104
#define BMU_BMU_ALLOC_CNT_1_INDEX       0x00000041
#define BMU_BMU_ALLOC_CNT_1_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_alloc_cnt_1_get(void)
{
	return REG_PL_RD(BMU_BMU_ALLOC_CNT_1_ADDR);
}

// field definitions
#define BMU_BMU_ALLOC_CNT_1_BMU_ALLOCAED_COUNTER_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_ALLOC_CNT_1_BMU_ALLOCAED_COUNTER_LSB    0
#define BMU_BMU_ALLOC_CNT_1_BMU_ALLOCAED_COUNTER_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_ALLOC_CNT_1_BMU_ALLOCAED_COUNTER_RST    0x0

__INLINE uint32_t bmu_bmu_alloc_cnt_1_bmu_allocaed_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_ALLOC_CNT_1_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BMU_ALLOC_CNT_2 register definition
 *  Number of elements allocated by the BAU for BMU2 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BMU_ALLOCAED_COUNTER      0x0
 * </pre>
 */
#define BMU_BMU_ALLOC_CNT_2_ADDR        (REG_BMU_BASE_ADDR+0x00000108)
#define BMU_BMU_ALLOC_CNT_2_OFFSET      0x00000108
#define BMU_BMU_ALLOC_CNT_2_INDEX       0x00000042
#define BMU_BMU_ALLOC_CNT_2_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_alloc_cnt_2_get(void)
{
	return REG_PL_RD(BMU_BMU_ALLOC_CNT_2_ADDR);
}

// field definitions
#define BMU_BMU_ALLOC_CNT_2_BMU_ALLOCAED_COUNTER_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_ALLOC_CNT_2_BMU_ALLOCAED_COUNTER_LSB    0
#define BMU_BMU_ALLOC_CNT_2_BMU_ALLOCAED_COUNTER_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_ALLOC_CNT_2_BMU_ALLOCAED_COUNTER_RST    0x0

__INLINE uint32_t bmu_bmu_alloc_cnt_2_bmu_allocaed_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_ALLOC_CNT_2_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BMU_ALLOC_CNT_3 register definition
 *  Number of elements allocated by the BAU for BMU3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BMU_ALLOCAED_COUNTER      0x0
 * </pre>
 */
#define BMU_BMU_ALLOC_CNT_3_ADDR        (REG_BMU_BASE_ADDR+0x0000010C)
#define BMU_BMU_ALLOC_CNT_3_OFFSET      0x0000010C
#define BMU_BMU_ALLOC_CNT_3_INDEX       0x00000043
#define BMU_BMU_ALLOC_CNT_3_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_alloc_cnt_3_get(void)
{
	return REG_PL_RD(BMU_BMU_ALLOC_CNT_3_ADDR);
}

// field definitions
#define BMU_BMU_ALLOC_CNT_3_BMU_ALLOCAED_COUNTER_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_ALLOC_CNT_3_BMU_ALLOCAED_COUNTER_LSB    0
#define BMU_BMU_ALLOC_CNT_3_BMU_ALLOCAED_COUNTER_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_ALLOC_CNT_3_BMU_ALLOCAED_COUNTER_RST    0x0

__INLINE uint32_t bmu_bmu_alloc_cnt_3_bmu_allocaed_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_ALLOC_CNT_3_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BMU_ALLOC_CNT_4 register definition
 *  Number of elements allocated by the BAU for BMU4 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BMU_ALLOCAED_COUNTER      0x0
 * </pre>
 */
#define BMU_BMU_ALLOC_CNT_4_ADDR        (REG_BMU_BASE_ADDR+0x00000110)
#define BMU_BMU_ALLOC_CNT_4_OFFSET      0x00000110
#define BMU_BMU_ALLOC_CNT_4_INDEX       0x00000044
#define BMU_BMU_ALLOC_CNT_4_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_alloc_cnt_4_get(void)
{
	return REG_PL_RD(BMU_BMU_ALLOC_CNT_4_ADDR);
}

// field definitions
#define BMU_BMU_ALLOC_CNT_4_BMU_ALLOCAED_COUNTER_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_ALLOC_CNT_4_BMU_ALLOCAED_COUNTER_LSB    0
#define BMU_BMU_ALLOC_CNT_4_BMU_ALLOCAED_COUNTER_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_ALLOC_CNT_4_BMU_ALLOCAED_COUNTER_RST    0x0

__INLINE uint32_t bmu_bmu_alloc_cnt_4_bmu_allocaed_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_ALLOC_CNT_4_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BMU_ALLOC_CNT_5 register definition
 *  Number of elements allocated by the BAU for BMU5 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BMU_ALLOCAED_COUNTER      0x0
 * </pre>
 */
#define BMU_BMU_ALLOC_CNT_5_ADDR        (REG_BMU_BASE_ADDR+0x00000114)
#define BMU_BMU_ALLOC_CNT_5_OFFSET      0x00000114
#define BMU_BMU_ALLOC_CNT_5_INDEX       0x00000045
#define BMU_BMU_ALLOC_CNT_5_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_alloc_cnt_5_get(void)
{
	return REG_PL_RD(BMU_BMU_ALLOC_CNT_5_ADDR);
}

// field definitions
#define BMU_BMU_ALLOC_CNT_5_BMU_ALLOCAED_COUNTER_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_ALLOC_CNT_5_BMU_ALLOCAED_COUNTER_LSB    0
#define BMU_BMU_ALLOC_CNT_5_BMU_ALLOCAED_COUNTER_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_ALLOC_CNT_5_BMU_ALLOCAED_COUNTER_RST    0x0

__INLINE uint32_t bmu_bmu_alloc_cnt_5_bmu_allocaed_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_ALLOC_CNT_5_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BMU_ALLOC_CNT_6 register definition
 *  Number of elements allocated by the BAU for BMU6 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BMU_ALLOCAED_COUNTER      0x0
 * </pre>
 */
#define BMU_BMU_ALLOC_CNT_6_ADDR        (REG_BMU_BASE_ADDR+0x00000118)
#define BMU_BMU_ALLOC_CNT_6_OFFSET      0x00000118
#define BMU_BMU_ALLOC_CNT_6_INDEX       0x00000046
#define BMU_BMU_ALLOC_CNT_6_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_alloc_cnt_6_get(void)
{
	return REG_PL_RD(BMU_BMU_ALLOC_CNT_6_ADDR);
}

// field definitions
#define BMU_BMU_ALLOC_CNT_6_BMU_ALLOCAED_COUNTER_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_ALLOC_CNT_6_BMU_ALLOCAED_COUNTER_LSB    0
#define BMU_BMU_ALLOC_CNT_6_BMU_ALLOCAED_COUNTER_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_ALLOC_CNT_6_BMU_ALLOCAED_COUNTER_RST    0x0

__INLINE uint32_t bmu_bmu_alloc_cnt_6_bmu_allocaed_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_ALLOC_CNT_6_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BMU_ALLOC_CNT_7 register definition
 *  Number of elements allocated by the BAU for BMU7 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BMU_ALLOCAED_COUNTER      0x0
 * </pre>
 */
#define BMU_BMU_ALLOC_CNT_7_ADDR        (REG_BMU_BASE_ADDR+0x0000011C)
#define BMU_BMU_ALLOC_CNT_7_OFFSET      0x0000011C
#define BMU_BMU_ALLOC_CNT_7_INDEX       0x00000047
#define BMU_BMU_ALLOC_CNT_7_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_alloc_cnt_7_get(void)
{
	return REG_PL_RD(BMU_BMU_ALLOC_CNT_7_ADDR);
}

// field definitions
#define BMU_BMU_ALLOC_CNT_7_BMU_ALLOCAED_COUNTER_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_ALLOC_CNT_7_BMU_ALLOCAED_COUNTER_LSB    0
#define BMU_BMU_ALLOC_CNT_7_BMU_ALLOCAED_COUNTER_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_ALLOC_CNT_7_BMU_ALLOCAED_COUNTER_RST    0x0

__INLINE uint32_t bmu_bmu_alloc_cnt_7_bmu_allocaed_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_ALLOC_CNT_7_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BMU_RTRN_CNT_INIT_0 register definition
 *  Initialization of BMU0 Returned Counter register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BMU_RTRN_CNT_INIT         0x0
 * </pre>
 */
#define BMU_BMU_RTRN_CNT_INIT_0_ADDR        (REG_BMU_BASE_ADDR+0x00000140)
#define BMU_BMU_RTRN_CNT_INIT_0_OFFSET      0x00000140
#define BMU_BMU_RTRN_CNT_INIT_0_INDEX       0x00000050
#define BMU_BMU_RTRN_CNT_INIT_0_RESET       0x00000000

__INLINE void bmu_bmu_rtrn_cnt_init_0_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_RTRN_CNT_INIT_0_ADDR, value);
}

// field definitions
#define BMU_BMU_RTRN_CNT_INIT_0_BMU_RTRN_CNT_INIT_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_RTRN_CNT_INIT_0_BMU_RTRN_CNT_INIT_LSB    0
#define BMU_BMU_RTRN_CNT_INIT_0_BMU_RTRN_CNT_INIT_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_RTRN_CNT_INIT_0_BMU_RTRN_CNT_INIT_RST    0x0

__INLINE void bmu_bmu_rtrn_cnt_init_0_bmu_rtrn_cnt_init_setf(uint32_t bmurtrncntinit)
{
	ASSERT_ERR((((uint32_t)bmurtrncntinit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BMU_RTRN_CNT_INIT_0_ADDR, (uint32_t)bmurtrncntinit << 0);
}

/**
 * @brief BMU_RTRN_CNT_INIT_1 register definition
 *  Initialization of BMU1 Returned Counter register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BMU_RTRN_CNT_INIT         0x0
 * </pre>
 */
#define BMU_BMU_RTRN_CNT_INIT_1_ADDR        (REG_BMU_BASE_ADDR+0x00000144)
#define BMU_BMU_RTRN_CNT_INIT_1_OFFSET      0x00000144
#define BMU_BMU_RTRN_CNT_INIT_1_INDEX       0x00000051
#define BMU_BMU_RTRN_CNT_INIT_1_RESET       0x00000000

__INLINE void bmu_bmu_rtrn_cnt_init_1_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_RTRN_CNT_INIT_1_ADDR, value);
}

// field definitions
#define BMU_BMU_RTRN_CNT_INIT_1_BMU_RTRN_CNT_INIT_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_RTRN_CNT_INIT_1_BMU_RTRN_CNT_INIT_LSB    0
#define BMU_BMU_RTRN_CNT_INIT_1_BMU_RTRN_CNT_INIT_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_RTRN_CNT_INIT_1_BMU_RTRN_CNT_INIT_RST    0x0

__INLINE void bmu_bmu_rtrn_cnt_init_1_bmu_rtrn_cnt_init_setf(uint32_t bmurtrncntinit)
{
	ASSERT_ERR((((uint32_t)bmurtrncntinit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BMU_RTRN_CNT_INIT_1_ADDR, (uint32_t)bmurtrncntinit << 0);
}

/**
 * @brief BMU_RTRN_CNT_INIT_2 register definition
 *  Initialization of BMU2 Returned Counter register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BMU_RTRN_CNT_INIT         0x0
 * </pre>
 */
#define BMU_BMU_RTRN_CNT_INIT_2_ADDR        (REG_BMU_BASE_ADDR+0x00000148)
#define BMU_BMU_RTRN_CNT_INIT_2_OFFSET      0x00000148
#define BMU_BMU_RTRN_CNT_INIT_2_INDEX       0x00000052
#define BMU_BMU_RTRN_CNT_INIT_2_RESET       0x00000000

__INLINE void bmu_bmu_rtrn_cnt_init_2_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_RTRN_CNT_INIT_2_ADDR, value);
}

// field definitions
#define BMU_BMU_RTRN_CNT_INIT_2_BMU_RTRN_CNT_INIT_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_RTRN_CNT_INIT_2_BMU_RTRN_CNT_INIT_LSB    0
#define BMU_BMU_RTRN_CNT_INIT_2_BMU_RTRN_CNT_INIT_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_RTRN_CNT_INIT_2_BMU_RTRN_CNT_INIT_RST    0x0

__INLINE void bmu_bmu_rtrn_cnt_init_2_bmu_rtrn_cnt_init_setf(uint32_t bmurtrncntinit)
{
	ASSERT_ERR((((uint32_t)bmurtrncntinit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BMU_RTRN_CNT_INIT_2_ADDR, (uint32_t)bmurtrncntinit << 0);
}

/**
 * @brief BMU_RTRN_CNT_INIT_3 register definition
 *  Initialization of BMU3 Returned Counter register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BMU_RTRN_CNT_INIT         0x0
 * </pre>
 */
#define BMU_BMU_RTRN_CNT_INIT_3_ADDR        (REG_BMU_BASE_ADDR+0x0000014C)
#define BMU_BMU_RTRN_CNT_INIT_3_OFFSET      0x0000014C
#define BMU_BMU_RTRN_CNT_INIT_3_INDEX       0x00000053
#define BMU_BMU_RTRN_CNT_INIT_3_RESET       0x00000000

__INLINE void bmu_bmu_rtrn_cnt_init_3_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_RTRN_CNT_INIT_3_ADDR, value);
}

// field definitions
#define BMU_BMU_RTRN_CNT_INIT_3_BMU_RTRN_CNT_INIT_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_RTRN_CNT_INIT_3_BMU_RTRN_CNT_INIT_LSB    0
#define BMU_BMU_RTRN_CNT_INIT_3_BMU_RTRN_CNT_INIT_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_RTRN_CNT_INIT_3_BMU_RTRN_CNT_INIT_RST    0x0

__INLINE void bmu_bmu_rtrn_cnt_init_3_bmu_rtrn_cnt_init_setf(uint32_t bmurtrncntinit)
{
	ASSERT_ERR((((uint32_t)bmurtrncntinit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BMU_RTRN_CNT_INIT_3_ADDR, (uint32_t)bmurtrncntinit << 0);
}

/**
 * @brief BMU_RTRN_CNT_INIT_4 register definition
 *  Initialization of BMU4 Returned Counter register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BMU_RTRN_CNT_INIT         0x0
 * </pre>
 */
#define BMU_BMU_RTRN_CNT_INIT_4_ADDR        (REG_BMU_BASE_ADDR+0x00000150)
#define BMU_BMU_RTRN_CNT_INIT_4_OFFSET      0x00000150
#define BMU_BMU_RTRN_CNT_INIT_4_INDEX       0x00000054
#define BMU_BMU_RTRN_CNT_INIT_4_RESET       0x00000000

__INLINE void bmu_bmu_rtrn_cnt_init_4_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_RTRN_CNT_INIT_4_ADDR, value);
}

// field definitions
#define BMU_BMU_RTRN_CNT_INIT_4_BMU_RTRN_CNT_INIT_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_RTRN_CNT_INIT_4_BMU_RTRN_CNT_INIT_LSB    0
#define BMU_BMU_RTRN_CNT_INIT_4_BMU_RTRN_CNT_INIT_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_RTRN_CNT_INIT_4_BMU_RTRN_CNT_INIT_RST    0x0

__INLINE void bmu_bmu_rtrn_cnt_init_4_bmu_rtrn_cnt_init_setf(uint32_t bmurtrncntinit)
{
	ASSERT_ERR((((uint32_t)bmurtrncntinit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BMU_RTRN_CNT_INIT_4_ADDR, (uint32_t)bmurtrncntinit << 0);
}

/**
 * @brief BMU_RTRN_CNT_INIT_5 register definition
 *  Initialization of BMU5 Returned Counter register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BMU_RTRN_CNT_INIT         0x0
 * </pre>
 */
#define BMU_BMU_RTRN_CNT_INIT_5_ADDR        (REG_BMU_BASE_ADDR+0x00000154)
#define BMU_BMU_RTRN_CNT_INIT_5_OFFSET      0x00000154
#define BMU_BMU_RTRN_CNT_INIT_5_INDEX       0x00000055
#define BMU_BMU_RTRN_CNT_INIT_5_RESET       0x00000000

__INLINE void bmu_bmu_rtrn_cnt_init_5_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_RTRN_CNT_INIT_5_ADDR, value);
}

// field definitions
#define BMU_BMU_RTRN_CNT_INIT_5_BMU_RTRN_CNT_INIT_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_RTRN_CNT_INIT_5_BMU_RTRN_CNT_INIT_LSB    0
#define BMU_BMU_RTRN_CNT_INIT_5_BMU_RTRN_CNT_INIT_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_RTRN_CNT_INIT_5_BMU_RTRN_CNT_INIT_RST    0x0

__INLINE void bmu_bmu_rtrn_cnt_init_5_bmu_rtrn_cnt_init_setf(uint32_t bmurtrncntinit)
{
	ASSERT_ERR((((uint32_t)bmurtrncntinit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BMU_RTRN_CNT_INIT_5_ADDR, (uint32_t)bmurtrncntinit << 0);
}

/**
 * @brief BMU_RTRN_CNT_INIT_6 register definition
 *  Initialization of BMU6 Returned Counter register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BMU_RTRN_CNT_INIT         0x0
 * </pre>
 */
#define BMU_BMU_RTRN_CNT_INIT_6_ADDR        (REG_BMU_BASE_ADDR+0x00000158)
#define BMU_BMU_RTRN_CNT_INIT_6_OFFSET      0x00000158
#define BMU_BMU_RTRN_CNT_INIT_6_INDEX       0x00000056
#define BMU_BMU_RTRN_CNT_INIT_6_RESET       0x00000000

__INLINE void bmu_bmu_rtrn_cnt_init_6_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_RTRN_CNT_INIT_6_ADDR, value);
}

// field definitions
#define BMU_BMU_RTRN_CNT_INIT_6_BMU_RTRN_CNT_INIT_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_RTRN_CNT_INIT_6_BMU_RTRN_CNT_INIT_LSB    0
#define BMU_BMU_RTRN_CNT_INIT_6_BMU_RTRN_CNT_INIT_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_RTRN_CNT_INIT_6_BMU_RTRN_CNT_INIT_RST    0x0

__INLINE void bmu_bmu_rtrn_cnt_init_6_bmu_rtrn_cnt_init_setf(uint32_t bmurtrncntinit)
{
	ASSERT_ERR((((uint32_t)bmurtrncntinit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BMU_RTRN_CNT_INIT_6_ADDR, (uint32_t)bmurtrncntinit << 0);
}

/**
 * @brief BMU_RTRN_CNT_INIT_7 register definition
 *  Initialization of BMU7 Returned Counter register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BMU_RTRN_CNT_INIT         0x0
 * </pre>
 */
#define BMU_BMU_RTRN_CNT_INIT_7_ADDR        (REG_BMU_BASE_ADDR+0x0000015C)
#define BMU_BMU_RTRN_CNT_INIT_7_OFFSET      0x0000015C
#define BMU_BMU_RTRN_CNT_INIT_7_INDEX       0x00000057
#define BMU_BMU_RTRN_CNT_INIT_7_RESET       0x00000000

__INLINE void bmu_bmu_rtrn_cnt_init_7_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_RTRN_CNT_INIT_7_ADDR, value);
}

// field definitions
#define BMU_BMU_RTRN_CNT_INIT_7_BMU_RTRN_CNT_INIT_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_RTRN_CNT_INIT_7_BMU_RTRN_CNT_INIT_LSB    0
#define BMU_BMU_RTRN_CNT_INIT_7_BMU_RTRN_CNT_INIT_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_RTRN_CNT_INIT_7_BMU_RTRN_CNT_INIT_RST    0x0

__INLINE void bmu_bmu_rtrn_cnt_init_7_bmu_rtrn_cnt_init_setf(uint32_t bmurtrncntinit)
{
	ASSERT_ERR((((uint32_t)bmurtrncntinit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BMU_RTRN_CNT_INIT_7_ADDR, (uint32_t)bmurtrncntinit << 0);
}

/**
 * @brief BMU_RTRN_CNT_0 register definition
 *  Number of elements returned by the BRU to the BMU0 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BMU_RETURNED_COUNTER      0x0
 * </pre>
 */
#define BMU_BMU_RTRN_CNT_0_ADDR        (REG_BMU_BASE_ADDR+0x00000180)
#define BMU_BMU_RTRN_CNT_0_OFFSET      0x00000180
#define BMU_BMU_RTRN_CNT_0_INDEX       0x00000060
#define BMU_BMU_RTRN_CNT_0_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_rtrn_cnt_0_get(void)
{
	return REG_PL_RD(BMU_BMU_RTRN_CNT_0_ADDR);
}

// field definitions
#define BMU_BMU_RTRN_CNT_0_BMU_RETURNED_COUNTER_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_RTRN_CNT_0_BMU_RETURNED_COUNTER_LSB    0
#define BMU_BMU_RTRN_CNT_0_BMU_RETURNED_COUNTER_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_RTRN_CNT_0_BMU_RETURNED_COUNTER_RST    0x0

__INLINE uint32_t bmu_bmu_rtrn_cnt_0_bmu_returned_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_RTRN_CNT_0_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BMU_RTRN_CNT_1 register definition
 *  Number of elements returned by the BRU to the BMU1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BMU_RETURNED_COUNTER      0x0
 * </pre>
 */
#define BMU_BMU_RTRN_CNT_1_ADDR        (REG_BMU_BASE_ADDR+0x00000184)
#define BMU_BMU_RTRN_CNT_1_OFFSET      0x00000184
#define BMU_BMU_RTRN_CNT_1_INDEX       0x00000061
#define BMU_BMU_RTRN_CNT_1_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_rtrn_cnt_1_get(void)
{
	return REG_PL_RD(BMU_BMU_RTRN_CNT_1_ADDR);
}

// field definitions
#define BMU_BMU_RTRN_CNT_1_BMU_RETURNED_COUNTER_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_RTRN_CNT_1_BMU_RETURNED_COUNTER_LSB    0
#define BMU_BMU_RTRN_CNT_1_BMU_RETURNED_COUNTER_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_RTRN_CNT_1_BMU_RETURNED_COUNTER_RST    0x0

__INLINE uint32_t bmu_bmu_rtrn_cnt_1_bmu_returned_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_RTRN_CNT_1_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BMU_RTRN_CNT_2 register definition
 *  Number of elements returned by the BRU to the BMU2 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BMU_RETURNED_COUNTER      0x0
 * </pre>
 */
#define BMU_BMU_RTRN_CNT_2_ADDR        (REG_BMU_BASE_ADDR+0x00000188)
#define BMU_BMU_RTRN_CNT_2_OFFSET      0x00000188
#define BMU_BMU_RTRN_CNT_2_INDEX       0x00000062
#define BMU_BMU_RTRN_CNT_2_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_rtrn_cnt_2_get(void)
{
	return REG_PL_RD(BMU_BMU_RTRN_CNT_2_ADDR);
}

// field definitions
#define BMU_BMU_RTRN_CNT_2_BMU_RETURNED_COUNTER_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_RTRN_CNT_2_BMU_RETURNED_COUNTER_LSB    0
#define BMU_BMU_RTRN_CNT_2_BMU_RETURNED_COUNTER_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_RTRN_CNT_2_BMU_RETURNED_COUNTER_RST    0x0

__INLINE uint32_t bmu_bmu_rtrn_cnt_2_bmu_returned_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_RTRN_CNT_2_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BMU_RTRN_CNT_3 register definition
 *  Number of elements returned by the BRU to the BMU3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BMU_RETURNED_COUNTER      0x0
 * </pre>
 */
#define BMU_BMU_RTRN_CNT_3_ADDR        (REG_BMU_BASE_ADDR+0x0000018C)
#define BMU_BMU_RTRN_CNT_3_OFFSET      0x0000018C
#define BMU_BMU_RTRN_CNT_3_INDEX       0x00000063
#define BMU_BMU_RTRN_CNT_3_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_rtrn_cnt_3_get(void)
{
	return REG_PL_RD(BMU_BMU_RTRN_CNT_3_ADDR);
}

// field definitions
#define BMU_BMU_RTRN_CNT_3_BMU_RETURNED_COUNTER_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_RTRN_CNT_3_BMU_RETURNED_COUNTER_LSB    0
#define BMU_BMU_RTRN_CNT_3_BMU_RETURNED_COUNTER_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_RTRN_CNT_3_BMU_RETURNED_COUNTER_RST    0x0

__INLINE uint32_t bmu_bmu_rtrn_cnt_3_bmu_returned_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_RTRN_CNT_3_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BMU_RTRN_CNT_4 register definition
 *  Number of elements returned by the BRU to the BMU4 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BMU_RETURNED_COUNTER      0x0
 * </pre>
 */
#define BMU_BMU_RTRN_CNT_4_ADDR        (REG_BMU_BASE_ADDR+0x00000190)
#define BMU_BMU_RTRN_CNT_4_OFFSET      0x00000190
#define BMU_BMU_RTRN_CNT_4_INDEX       0x00000064
#define BMU_BMU_RTRN_CNT_4_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_rtrn_cnt_4_get(void)
{
	return REG_PL_RD(BMU_BMU_RTRN_CNT_4_ADDR);
}

// field definitions
#define BMU_BMU_RTRN_CNT_4_BMU_RETURNED_COUNTER_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_RTRN_CNT_4_BMU_RETURNED_COUNTER_LSB    0
#define BMU_BMU_RTRN_CNT_4_BMU_RETURNED_COUNTER_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_RTRN_CNT_4_BMU_RETURNED_COUNTER_RST    0x0

__INLINE uint32_t bmu_bmu_rtrn_cnt_4_bmu_returned_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_RTRN_CNT_4_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BMU_RTRN_CNT_5 register definition
 *  Number of elements returned by the BRU to the BMU5 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BMU_RETURNED_COUNTER      0x0
 * </pre>
 */
#define BMU_BMU_RTRN_CNT_5_ADDR        (REG_BMU_BASE_ADDR+0x00000194)
#define BMU_BMU_RTRN_CNT_5_OFFSET      0x00000194
#define BMU_BMU_RTRN_CNT_5_INDEX       0x00000065
#define BMU_BMU_RTRN_CNT_5_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_rtrn_cnt_5_get(void)
{
	return REG_PL_RD(BMU_BMU_RTRN_CNT_5_ADDR);
}

// field definitions
#define BMU_BMU_RTRN_CNT_5_BMU_RETURNED_COUNTER_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_RTRN_CNT_5_BMU_RETURNED_COUNTER_LSB    0
#define BMU_BMU_RTRN_CNT_5_BMU_RETURNED_COUNTER_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_RTRN_CNT_5_BMU_RETURNED_COUNTER_RST    0x0

__INLINE uint32_t bmu_bmu_rtrn_cnt_5_bmu_returned_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_RTRN_CNT_5_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BMU_RTRN_CNT_6 register definition
 *  Number of elements returned by the BRU to the BMU6 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BMU_RETURNED_COUNTER      0x0
 * </pre>
 */
#define BMU_BMU_RTRN_CNT_6_ADDR        (REG_BMU_BASE_ADDR+0x00000198)
#define BMU_BMU_RTRN_CNT_6_OFFSET      0x00000198
#define BMU_BMU_RTRN_CNT_6_INDEX       0x00000066
#define BMU_BMU_RTRN_CNT_6_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_rtrn_cnt_6_get(void)
{
	return REG_PL_RD(BMU_BMU_RTRN_CNT_6_ADDR);
}

// field definitions
#define BMU_BMU_RTRN_CNT_6_BMU_RETURNED_COUNTER_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_RTRN_CNT_6_BMU_RETURNED_COUNTER_LSB    0
#define BMU_BMU_RTRN_CNT_6_BMU_RETURNED_COUNTER_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_RTRN_CNT_6_BMU_RETURNED_COUNTER_RST    0x0

__INLINE uint32_t bmu_bmu_rtrn_cnt_6_bmu_returned_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_RTRN_CNT_6_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BMU_RTRN_CNT_7 register definition
 *  Number of elements returned by the BRU to the BMU7 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BMU_RETURNED_COUNTER      0x0
 * </pre>
 */
#define BMU_BMU_RTRN_CNT_7_ADDR        (REG_BMU_BASE_ADDR+0x0000019C)
#define BMU_BMU_RTRN_CNT_7_OFFSET      0x0000019C
#define BMU_BMU_RTRN_CNT_7_INDEX       0x00000067
#define BMU_BMU_RTRN_CNT_7_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_rtrn_cnt_7_get(void)
{
	return REG_PL_RD(BMU_BMU_RTRN_CNT_7_ADDR);
}

// field definitions
#define BMU_BMU_RTRN_CNT_7_BMU_RETURNED_COUNTER_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_RTRN_CNT_7_BMU_RETURNED_COUNTER_LSB    0
#define BMU_BMU_RTRN_CNT_7_BMU_RETURNED_COUNTER_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_RTRN_CNT_7_BMU_RETURNED_COUNTER_RST    0x0

__INLINE uint32_t bmu_bmu_rtrn_cnt_7_bmu_returned_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_RTRN_CNT_7_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_0 register definition
 *  The offset within the descriptors of the “next” fi register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NEXT_POINTER_OFFSET       0x0
 * </pre>
 */
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_0_ADDR        (REG_BMU_BASE_ADDR+0x000001C0)
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_0_OFFSET      0x000001C0
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_0_INDEX       0x00000070
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_0_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_release_desc_next_pointer_offset_0_get(void)
{
	return REG_PL_RD(BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_0_ADDR);
}

__INLINE void bmu_bmu_release_desc_next_pointer_offset_0_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_0_ADDR, value);
}

// field definitions
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_0_NEXT_POINTER_OFFSET_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_0_NEXT_POINTER_OFFSET_LSB    0
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_0_NEXT_POINTER_OFFSET_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_0_NEXT_POINTER_OFFSET_RST    0x0

__INLINE uint32_t bmu_bmu_release_desc_next_pointer_offset_0_next_pointer_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_0_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bmu_bmu_release_desc_next_pointer_offset_0_next_pointer_offset_setf(uint32_t nextpointeroffset)
{
	ASSERT_ERR((((uint32_t)nextpointeroffset << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_0_ADDR, (uint32_t)nextpointeroffset << 0);
}

/**
 * @brief BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_1 register definition
 *  The offset within the descriptors of the “next” fi register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NEXT_POINTER_OFFSET       0x0
 * </pre>
 */
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_1_ADDR        (REG_BMU_BASE_ADDR+0x000001C4)
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_1_OFFSET      0x000001C4
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_1_INDEX       0x00000071
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_1_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_release_desc_next_pointer_offset_1_get(void)
{
	return REG_PL_RD(BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_1_ADDR);
}

__INLINE void bmu_bmu_release_desc_next_pointer_offset_1_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_1_ADDR, value);
}

// field definitions
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_1_NEXT_POINTER_OFFSET_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_1_NEXT_POINTER_OFFSET_LSB    0
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_1_NEXT_POINTER_OFFSET_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_1_NEXT_POINTER_OFFSET_RST    0x0

__INLINE uint32_t bmu_bmu_release_desc_next_pointer_offset_1_next_pointer_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_1_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bmu_bmu_release_desc_next_pointer_offset_1_next_pointer_offset_setf(uint32_t nextpointeroffset)
{
	ASSERT_ERR((((uint32_t)nextpointeroffset << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_1_ADDR, (uint32_t)nextpointeroffset << 0);
}

/**
 * @brief BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_2 register definition
 *  The offset within the descriptors of the “next” fi register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NEXT_POINTER_OFFSET       0x0
 * </pre>
 */
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_2_ADDR        (REG_BMU_BASE_ADDR+0x000001C8)
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_2_OFFSET      0x000001C8
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_2_INDEX       0x00000072
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_2_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_release_desc_next_pointer_offset_2_get(void)
{
	return REG_PL_RD(BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_2_ADDR);
}

__INLINE void bmu_bmu_release_desc_next_pointer_offset_2_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_2_ADDR, value);
}

// field definitions
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_2_NEXT_POINTER_OFFSET_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_2_NEXT_POINTER_OFFSET_LSB    0
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_2_NEXT_POINTER_OFFSET_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_2_NEXT_POINTER_OFFSET_RST    0x0

__INLINE uint32_t bmu_bmu_release_desc_next_pointer_offset_2_next_pointer_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_2_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bmu_bmu_release_desc_next_pointer_offset_2_next_pointer_offset_setf(uint32_t nextpointeroffset)
{
	ASSERT_ERR((((uint32_t)nextpointeroffset << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_2_ADDR, (uint32_t)nextpointeroffset << 0);
}

/**
 * @brief BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_3 register definition
 *  The offset within the descriptors of the “next” fi register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NEXT_POINTER_OFFSET       0x0
 * </pre>
 */
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_3_ADDR        (REG_BMU_BASE_ADDR+0x000001CC)
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_3_OFFSET      0x000001CC
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_3_INDEX       0x00000073
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_3_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_release_desc_next_pointer_offset_3_get(void)
{
	return REG_PL_RD(BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_3_ADDR);
}

__INLINE void bmu_bmu_release_desc_next_pointer_offset_3_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_3_ADDR, value);
}

// field definitions
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_3_NEXT_POINTER_OFFSET_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_3_NEXT_POINTER_OFFSET_LSB    0
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_3_NEXT_POINTER_OFFSET_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_3_NEXT_POINTER_OFFSET_RST    0x0

__INLINE uint32_t bmu_bmu_release_desc_next_pointer_offset_3_next_pointer_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_3_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bmu_bmu_release_desc_next_pointer_offset_3_next_pointer_offset_setf(uint32_t nextpointeroffset)
{
	ASSERT_ERR((((uint32_t)nextpointeroffset << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_3_ADDR, (uint32_t)nextpointeroffset << 0);
}

/**
 * @brief BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_4 register definition
 *  The offset within the descriptors of the “next” fi register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NEXT_POINTER_OFFSET       0x0
 * </pre>
 */
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_4_ADDR        (REG_BMU_BASE_ADDR+0x000001D0)
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_4_OFFSET      0x000001D0
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_4_INDEX       0x00000074
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_4_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_release_desc_next_pointer_offset_4_get(void)
{
	return REG_PL_RD(BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_4_ADDR);
}

__INLINE void bmu_bmu_release_desc_next_pointer_offset_4_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_4_ADDR, value);
}

// field definitions
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_4_NEXT_POINTER_OFFSET_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_4_NEXT_POINTER_OFFSET_LSB    0
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_4_NEXT_POINTER_OFFSET_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_4_NEXT_POINTER_OFFSET_RST    0x0

__INLINE uint32_t bmu_bmu_release_desc_next_pointer_offset_4_next_pointer_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_4_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bmu_bmu_release_desc_next_pointer_offset_4_next_pointer_offset_setf(uint32_t nextpointeroffset)
{
	ASSERT_ERR((((uint32_t)nextpointeroffset << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_4_ADDR, (uint32_t)nextpointeroffset << 0);
}

/**
 * @brief BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_5 register definition
 *  The offset within the descriptors of the “next” fi register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NEXT_POINTER_OFFSET       0x0
 * </pre>
 */
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_5_ADDR        (REG_BMU_BASE_ADDR+0x000001D4)
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_5_OFFSET      0x000001D4
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_5_INDEX       0x00000075
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_5_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_release_desc_next_pointer_offset_5_get(void)
{
	return REG_PL_RD(BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_5_ADDR);
}

__INLINE void bmu_bmu_release_desc_next_pointer_offset_5_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_5_ADDR, value);
}

// field definitions
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_5_NEXT_POINTER_OFFSET_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_5_NEXT_POINTER_OFFSET_LSB    0
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_5_NEXT_POINTER_OFFSET_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_5_NEXT_POINTER_OFFSET_RST    0x0

__INLINE uint32_t bmu_bmu_release_desc_next_pointer_offset_5_next_pointer_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_5_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bmu_bmu_release_desc_next_pointer_offset_5_next_pointer_offset_setf(uint32_t nextpointeroffset)
{
	ASSERT_ERR((((uint32_t)nextpointeroffset << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_5_ADDR, (uint32_t)nextpointeroffset << 0);
}

/**
 * @brief BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_6 register definition
 *  The offset within the descriptors of the “next” fi register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NEXT_POINTER_OFFSET       0x0
 * </pre>
 */
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_6_ADDR        (REG_BMU_BASE_ADDR+0x000001D8)
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_6_OFFSET      0x000001D8
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_6_INDEX       0x00000076
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_6_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_release_desc_next_pointer_offset_6_get(void)
{
	return REG_PL_RD(BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_6_ADDR);
}

__INLINE void bmu_bmu_release_desc_next_pointer_offset_6_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_6_ADDR, value);
}

// field definitions
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_6_NEXT_POINTER_OFFSET_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_6_NEXT_POINTER_OFFSET_LSB    0
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_6_NEXT_POINTER_OFFSET_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_6_NEXT_POINTER_OFFSET_RST    0x0

__INLINE uint32_t bmu_bmu_release_desc_next_pointer_offset_6_next_pointer_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_6_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bmu_bmu_release_desc_next_pointer_offset_6_next_pointer_offset_setf(uint32_t nextpointeroffset)
{
	ASSERT_ERR((((uint32_t)nextpointeroffset << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_6_ADDR, (uint32_t)nextpointeroffset << 0);
}

/**
 * @brief BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_7 register definition
 *  The offset within the descriptors of the “next” fi register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NEXT_POINTER_OFFSET       0x0
 * </pre>
 */
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_7_ADDR        (REG_BMU_BASE_ADDR+0x000001DC)
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_7_OFFSET      0x000001DC
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_7_INDEX       0x00000077
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_7_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_release_desc_next_pointer_offset_7_get(void)
{
	return REG_PL_RD(BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_7_ADDR);
}

__INLINE void bmu_bmu_release_desc_next_pointer_offset_7_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_7_ADDR, value);
}

// field definitions
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_7_NEXT_POINTER_OFFSET_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_7_NEXT_POINTER_OFFSET_LSB    0
#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_7_NEXT_POINTER_OFFSET_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_7_NEXT_POINTER_OFFSET_RST    0x0

__INLINE uint32_t bmu_bmu_release_desc_next_pointer_offset_7_next_pointer_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_7_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bmu_bmu_release_desc_next_pointer_offset_7_next_pointer_offset_setf(uint32_t nextpointeroffset)
{
	ASSERT_ERR((((uint32_t)nextpointeroffset << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BMU_RELEASE_DESC_NEXT_POINTER_OFFSET_7_ADDR, (uint32_t)nextpointeroffset << 0);
}

/**
 * @brief BMU_RLS_OFFSET_0 register definition
 *  backward offset from the release_address  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BMU_RELEASE_OFFSET        0x0
 * </pre>
 */
#define BMU_BMU_RLS_OFFSET_0_ADDR        (REG_BMU_BASE_ADDR+0x00000200)
#define BMU_BMU_RLS_OFFSET_0_OFFSET      0x00000200
#define BMU_BMU_RLS_OFFSET_0_INDEX       0x00000080
#define BMU_BMU_RLS_OFFSET_0_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_rls_offset_0_get(void)
{
	return REG_PL_RD(BMU_BMU_RLS_OFFSET_0_ADDR);
}

__INLINE void bmu_bmu_rls_offset_0_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_RLS_OFFSET_0_ADDR, value);
}

// field definitions
#define BMU_BMU_RLS_OFFSET_0_BMU_RELEASE_OFFSET_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_RLS_OFFSET_0_BMU_RELEASE_OFFSET_LSB    0
#define BMU_BMU_RLS_OFFSET_0_BMU_RELEASE_OFFSET_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_RLS_OFFSET_0_BMU_RELEASE_OFFSET_RST    0x0

__INLINE uint32_t bmu_bmu_rls_offset_0_bmu_release_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_RLS_OFFSET_0_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bmu_bmu_rls_offset_0_bmu_release_offset_setf(uint32_t bmureleaseoffset)
{
	ASSERT_ERR((((uint32_t)bmureleaseoffset << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BMU_RLS_OFFSET_0_ADDR, (uint32_t)bmureleaseoffset << 0);
}

/**
 * @brief BMU_RLS_OFFSET_1 register definition
 *  backward offset from the release_address  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BMU_RELEASE_OFFSET        0x0
 * </pre>
 */
#define BMU_BMU_RLS_OFFSET_1_ADDR        (REG_BMU_BASE_ADDR+0x00000204)
#define BMU_BMU_RLS_OFFSET_1_OFFSET      0x00000204
#define BMU_BMU_RLS_OFFSET_1_INDEX       0x00000081
#define BMU_BMU_RLS_OFFSET_1_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_rls_offset_1_get(void)
{
	return REG_PL_RD(BMU_BMU_RLS_OFFSET_1_ADDR);
}

__INLINE void bmu_bmu_rls_offset_1_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_RLS_OFFSET_1_ADDR, value);
}

// field definitions
#define BMU_BMU_RLS_OFFSET_1_BMU_RELEASE_OFFSET_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_RLS_OFFSET_1_BMU_RELEASE_OFFSET_LSB    0
#define BMU_BMU_RLS_OFFSET_1_BMU_RELEASE_OFFSET_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_RLS_OFFSET_1_BMU_RELEASE_OFFSET_RST    0x0

__INLINE uint32_t bmu_bmu_rls_offset_1_bmu_release_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_RLS_OFFSET_1_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bmu_bmu_rls_offset_1_bmu_release_offset_setf(uint32_t bmureleaseoffset)
{
	ASSERT_ERR((((uint32_t)bmureleaseoffset << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BMU_RLS_OFFSET_1_ADDR, (uint32_t)bmureleaseoffset << 0);
}

/**
 * @brief BMU_RLS_OFFSET_2 register definition
 *  backward offset from the release_address  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BMU_RELEASE_OFFSET        0x0
 * </pre>
 */
#define BMU_BMU_RLS_OFFSET_2_ADDR        (REG_BMU_BASE_ADDR+0x00000208)
#define BMU_BMU_RLS_OFFSET_2_OFFSET      0x00000208
#define BMU_BMU_RLS_OFFSET_2_INDEX       0x00000082
#define BMU_BMU_RLS_OFFSET_2_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_rls_offset_2_get(void)
{
	return REG_PL_RD(BMU_BMU_RLS_OFFSET_2_ADDR);
}

__INLINE void bmu_bmu_rls_offset_2_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_RLS_OFFSET_2_ADDR, value);
}

// field definitions
#define BMU_BMU_RLS_OFFSET_2_BMU_RELEASE_OFFSET_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_RLS_OFFSET_2_BMU_RELEASE_OFFSET_LSB    0
#define BMU_BMU_RLS_OFFSET_2_BMU_RELEASE_OFFSET_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_RLS_OFFSET_2_BMU_RELEASE_OFFSET_RST    0x0

__INLINE uint32_t bmu_bmu_rls_offset_2_bmu_release_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_RLS_OFFSET_2_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bmu_bmu_rls_offset_2_bmu_release_offset_setf(uint32_t bmureleaseoffset)
{
	ASSERT_ERR((((uint32_t)bmureleaseoffset << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BMU_RLS_OFFSET_2_ADDR, (uint32_t)bmureleaseoffset << 0);
}

/**
 * @brief BMU_RLS_OFFSET_3 register definition
 *  backward offset from the release_address  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BMU_RELEASE_OFFSET        0x0
 * </pre>
 */
#define BMU_BMU_RLS_OFFSET_3_ADDR        (REG_BMU_BASE_ADDR+0x0000020C)
#define BMU_BMU_RLS_OFFSET_3_OFFSET      0x0000020C
#define BMU_BMU_RLS_OFFSET_3_INDEX       0x00000083
#define BMU_BMU_RLS_OFFSET_3_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_rls_offset_3_get(void)
{
	return REG_PL_RD(BMU_BMU_RLS_OFFSET_3_ADDR);
}

__INLINE void bmu_bmu_rls_offset_3_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_RLS_OFFSET_3_ADDR, value);
}

// field definitions
#define BMU_BMU_RLS_OFFSET_3_BMU_RELEASE_OFFSET_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_RLS_OFFSET_3_BMU_RELEASE_OFFSET_LSB    0
#define BMU_BMU_RLS_OFFSET_3_BMU_RELEASE_OFFSET_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_RLS_OFFSET_3_BMU_RELEASE_OFFSET_RST    0x0

__INLINE uint32_t bmu_bmu_rls_offset_3_bmu_release_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_RLS_OFFSET_3_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bmu_bmu_rls_offset_3_bmu_release_offset_setf(uint32_t bmureleaseoffset)
{
	ASSERT_ERR((((uint32_t)bmureleaseoffset << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BMU_RLS_OFFSET_3_ADDR, (uint32_t)bmureleaseoffset << 0);
}

/**
 * @brief BMU_RLS_OFFSET_4 register definition
 *  backward offset from the release_address  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BMU_RELEASE_OFFSET        0x0
 * </pre>
 */
#define BMU_BMU_RLS_OFFSET_4_ADDR        (REG_BMU_BASE_ADDR+0x00000210)
#define BMU_BMU_RLS_OFFSET_4_OFFSET      0x00000210
#define BMU_BMU_RLS_OFFSET_4_INDEX       0x00000084
#define BMU_BMU_RLS_OFFSET_4_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_rls_offset_4_get(void)
{
	return REG_PL_RD(BMU_BMU_RLS_OFFSET_4_ADDR);
}

__INLINE void bmu_bmu_rls_offset_4_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_RLS_OFFSET_4_ADDR, value);
}

// field definitions
#define BMU_BMU_RLS_OFFSET_4_BMU_RELEASE_OFFSET_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_RLS_OFFSET_4_BMU_RELEASE_OFFSET_LSB    0
#define BMU_BMU_RLS_OFFSET_4_BMU_RELEASE_OFFSET_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_RLS_OFFSET_4_BMU_RELEASE_OFFSET_RST    0x0

__INLINE uint32_t bmu_bmu_rls_offset_4_bmu_release_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_RLS_OFFSET_4_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bmu_bmu_rls_offset_4_bmu_release_offset_setf(uint32_t bmureleaseoffset)
{
	ASSERT_ERR((((uint32_t)bmureleaseoffset << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BMU_RLS_OFFSET_4_ADDR, (uint32_t)bmureleaseoffset << 0);
}

/**
 * @brief BMU_RLS_OFFSET_5 register definition
 *  backward offset from the release_address  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BMU_RELEASE_OFFSET        0x0
 * </pre>
 */
#define BMU_BMU_RLS_OFFSET_5_ADDR        (REG_BMU_BASE_ADDR+0x00000214)
#define BMU_BMU_RLS_OFFSET_5_OFFSET      0x00000214
#define BMU_BMU_RLS_OFFSET_5_INDEX       0x00000085
#define BMU_BMU_RLS_OFFSET_5_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_rls_offset_5_get(void)
{
	return REG_PL_RD(BMU_BMU_RLS_OFFSET_5_ADDR);
}

__INLINE void bmu_bmu_rls_offset_5_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_RLS_OFFSET_5_ADDR, value);
}

// field definitions
#define BMU_BMU_RLS_OFFSET_5_BMU_RELEASE_OFFSET_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_RLS_OFFSET_5_BMU_RELEASE_OFFSET_LSB    0
#define BMU_BMU_RLS_OFFSET_5_BMU_RELEASE_OFFSET_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_RLS_OFFSET_5_BMU_RELEASE_OFFSET_RST    0x0

__INLINE uint32_t bmu_bmu_rls_offset_5_bmu_release_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_RLS_OFFSET_5_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bmu_bmu_rls_offset_5_bmu_release_offset_setf(uint32_t bmureleaseoffset)
{
	ASSERT_ERR((((uint32_t)bmureleaseoffset << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BMU_RLS_OFFSET_5_ADDR, (uint32_t)bmureleaseoffset << 0);
}

/**
 * @brief BMU_RLS_OFFSET_6 register definition
 *  backward offset from the release_address  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BMU_RELEASE_OFFSET        0x0
 * </pre>
 */
#define BMU_BMU_RLS_OFFSET_6_ADDR        (REG_BMU_BASE_ADDR+0x00000218)
#define BMU_BMU_RLS_OFFSET_6_OFFSET      0x00000218
#define BMU_BMU_RLS_OFFSET_6_INDEX       0x00000086
#define BMU_BMU_RLS_OFFSET_6_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_rls_offset_6_get(void)
{
	return REG_PL_RD(BMU_BMU_RLS_OFFSET_6_ADDR);
}

__INLINE void bmu_bmu_rls_offset_6_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_RLS_OFFSET_6_ADDR, value);
}

// field definitions
#define BMU_BMU_RLS_OFFSET_6_BMU_RELEASE_OFFSET_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_RLS_OFFSET_6_BMU_RELEASE_OFFSET_LSB    0
#define BMU_BMU_RLS_OFFSET_6_BMU_RELEASE_OFFSET_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_RLS_OFFSET_6_BMU_RELEASE_OFFSET_RST    0x0

__INLINE uint32_t bmu_bmu_rls_offset_6_bmu_release_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_RLS_OFFSET_6_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bmu_bmu_rls_offset_6_bmu_release_offset_setf(uint32_t bmureleaseoffset)
{
	ASSERT_ERR((((uint32_t)bmureleaseoffset << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BMU_RLS_OFFSET_6_ADDR, (uint32_t)bmureleaseoffset << 0);
}

/**
 * @brief BMU_RLS_OFFSET_7 register definition
 *  backward offset from the release_address  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BMU_RELEASE_OFFSET        0x0
 * </pre>
 */
#define BMU_BMU_RLS_OFFSET_7_ADDR        (REG_BMU_BASE_ADDR+0x0000021C)
#define BMU_BMU_RLS_OFFSET_7_OFFSET      0x0000021C
#define BMU_BMU_RLS_OFFSET_7_INDEX       0x00000087
#define BMU_BMU_RLS_OFFSET_7_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_rls_offset_7_get(void)
{
	return REG_PL_RD(BMU_BMU_RLS_OFFSET_7_ADDR);
}

__INLINE void bmu_bmu_rls_offset_7_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_RLS_OFFSET_7_ADDR, value);
}

// field definitions
#define BMU_BMU_RLS_OFFSET_7_BMU_RELEASE_OFFSET_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_RLS_OFFSET_7_BMU_RELEASE_OFFSET_LSB    0
#define BMU_BMU_RLS_OFFSET_7_BMU_RELEASE_OFFSET_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_RLS_OFFSET_7_BMU_RELEASE_OFFSET_RST    0x0

__INLINE uint32_t bmu_bmu_rls_offset_7_bmu_release_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_RLS_OFFSET_7_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bmu_bmu_rls_offset_7_bmu_release_offset_setf(uint32_t bmureleaseoffset)
{
	ASSERT_ERR((((uint32_t)bmureleaseoffset << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BMU_RLS_OFFSET_7_ADDR, (uint32_t)bmureleaseoffset << 0);
}

/**
 * @brief BMU_INT_RAW_STAT register definition
 *  Int RAW Status register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 LIST_ERROR                0x0
 *    15:00 LIST_NOT_EMPTY            0x0
 * </pre>
 */
#define BMU_BMU_INT_RAW_STAT_ADDR        (REG_BMU_BASE_ADDR+0x00000240)
#define BMU_BMU_INT_RAW_STAT_OFFSET      0x00000240
#define BMU_BMU_INT_RAW_STAT_INDEX       0x00000090
#define BMU_BMU_INT_RAW_STAT_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_int_raw_stat_get(void)
{
	return REG_PL_RD(BMU_BMU_INT_RAW_STAT_ADDR);
}

// field definitions
#define BMU_BMU_INT_RAW_STAT_LIST_ERROR_MASK    ((uint32_t)0xFFFF0000)
#define BMU_BMU_INT_RAW_STAT_LIST_ERROR_LSB    16
#define BMU_BMU_INT_RAW_STAT_LIST_ERROR_WIDTH    ((uint32_t)0x00000010)
#define BMU_BMU_INT_RAW_STAT_LIST_NOT_EMPTY_MASK    ((uint32_t)0x0000FFFF)
#define BMU_BMU_INT_RAW_STAT_LIST_NOT_EMPTY_LSB    0
#define BMU_BMU_INT_RAW_STAT_LIST_NOT_EMPTY_WIDTH    ((uint32_t)0x00000010)

#define BMU_BMU_INT_RAW_STAT_LIST_ERROR_RST    0x0
#define BMU_BMU_INT_RAW_STAT_LIST_NOT_EMPTY_RST    0x0

__INLINE void bmu_bmu_int_raw_stat_unpack(uint16_t* list_error, uint16_t* list_not_empty)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_INT_RAW_STAT_ADDR);

	*list_error = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*list_not_empty = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t bmu_bmu_int_raw_stat_list_error_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_INT_RAW_STAT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE uint16_t bmu_bmu_int_raw_stat_list_not_empty_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_INT_RAW_STAT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

/**
 * @brief BMU_ERROR_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:14 ERROR_REASON_LIST7        0x0
 *    13:12 ERROR_REASON_LIST6        0x0
 *    11:10 ERROR_REASON_LIST5        0x0
 *    09:08 ERROR_REASON_LIST4        0x0
 *    07:06 ERROR_REASON_LIST3        0x0
 *    05:04 ERROR_REASON_LIST2        0x0
 *    03:02 ERROR_REASON_LIST1        0x0
 *    01:00 ERROR_REASON_LIST0        0x0
 * </pre>
 */
#define BMU_BMU_ERROR_STATUS_ADDR        (REG_BMU_BASE_ADDR+0x00000244)
#define BMU_BMU_ERROR_STATUS_OFFSET      0x00000244
#define BMU_BMU_ERROR_STATUS_INDEX       0x00000091
#define BMU_BMU_ERROR_STATUS_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_error_status_get(void)
{
	return REG_PL_RD(BMU_BMU_ERROR_STATUS_ADDR);
}

// field definitions
#define BMU_BMU_ERROR_STATUS_ERROR_REASON_LIST_7_MASK    ((uint32_t)0x0000C000)
#define BMU_BMU_ERROR_STATUS_ERROR_REASON_LIST_7_LSB    14
#define BMU_BMU_ERROR_STATUS_ERROR_REASON_LIST_7_WIDTH    ((uint32_t)0x00000002)
#define BMU_BMU_ERROR_STATUS_ERROR_REASON_LIST_6_MASK    ((uint32_t)0x00003000)
#define BMU_BMU_ERROR_STATUS_ERROR_REASON_LIST_6_LSB    12
#define BMU_BMU_ERROR_STATUS_ERROR_REASON_LIST_6_WIDTH    ((uint32_t)0x00000002)
#define BMU_BMU_ERROR_STATUS_ERROR_REASON_LIST_5_MASK    ((uint32_t)0x00000C00)
#define BMU_BMU_ERROR_STATUS_ERROR_REASON_LIST_5_LSB    10
#define BMU_BMU_ERROR_STATUS_ERROR_REASON_LIST_5_WIDTH    ((uint32_t)0x00000002)
#define BMU_BMU_ERROR_STATUS_ERROR_REASON_LIST_4_MASK    ((uint32_t)0x00000300)
#define BMU_BMU_ERROR_STATUS_ERROR_REASON_LIST_4_LSB    8
#define BMU_BMU_ERROR_STATUS_ERROR_REASON_LIST_4_WIDTH    ((uint32_t)0x00000002)
#define BMU_BMU_ERROR_STATUS_ERROR_REASON_LIST_3_MASK    ((uint32_t)0x000000C0)
#define BMU_BMU_ERROR_STATUS_ERROR_REASON_LIST_3_LSB    6
#define BMU_BMU_ERROR_STATUS_ERROR_REASON_LIST_3_WIDTH    ((uint32_t)0x00000002)
#define BMU_BMU_ERROR_STATUS_ERROR_REASON_LIST_2_MASK    ((uint32_t)0x00000030)
#define BMU_BMU_ERROR_STATUS_ERROR_REASON_LIST_2_LSB    4
#define BMU_BMU_ERROR_STATUS_ERROR_REASON_LIST_2_WIDTH    ((uint32_t)0x00000002)
#define BMU_BMU_ERROR_STATUS_ERROR_REASON_LIST_1_MASK    ((uint32_t)0x0000000C)
#define BMU_BMU_ERROR_STATUS_ERROR_REASON_LIST_1_LSB    2
#define BMU_BMU_ERROR_STATUS_ERROR_REASON_LIST_1_WIDTH    ((uint32_t)0x00000002)
#define BMU_BMU_ERROR_STATUS_ERROR_REASON_LIST_0_MASK    ((uint32_t)0x00000003)
#define BMU_BMU_ERROR_STATUS_ERROR_REASON_LIST_0_LSB    0
#define BMU_BMU_ERROR_STATUS_ERROR_REASON_LIST_0_WIDTH    ((uint32_t)0x00000002)

#define BMU_BMU_ERROR_STATUS_ERROR_REASON_LIST_7_RST    0x0
#define BMU_BMU_ERROR_STATUS_ERROR_REASON_LIST_6_RST    0x0
#define BMU_BMU_ERROR_STATUS_ERROR_REASON_LIST_5_RST    0x0
#define BMU_BMU_ERROR_STATUS_ERROR_REASON_LIST_4_RST    0x0
#define BMU_BMU_ERROR_STATUS_ERROR_REASON_LIST_3_RST    0x0
#define BMU_BMU_ERROR_STATUS_ERROR_REASON_LIST_2_RST    0x0
#define BMU_BMU_ERROR_STATUS_ERROR_REASON_LIST_1_RST    0x0
#define BMU_BMU_ERROR_STATUS_ERROR_REASON_LIST_0_RST    0x0

__INLINE void bmu_bmu_error_status_unpack(uint8_t* error_reason_list7, uint8_t* error_reason_list6, uint8_t* error_reason_list5, uint8_t* error_reason_list4, uint8_t* error_reason_list3, uint8_t* error_reason_list2, uint8_t* error_reason_list1, uint8_t* error_reason_list0)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_ERROR_STATUS_ADDR);

	*error_reason_list7 = (localVal & ((uint32_t)0x0000C000)) >>  14;
	*error_reason_list6 = (localVal & ((uint32_t)0x00003000)) >>  12;
	*error_reason_list5 = (localVal & ((uint32_t)0x00000C00)) >>  10;
	*error_reason_list4 = (localVal & ((uint32_t)0x00000300)) >>  8;
	*error_reason_list3 = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*error_reason_list2 = (localVal & ((uint32_t)0x00000030)) >>  4;
	*error_reason_list1 = (localVal & ((uint32_t)0x0000000C)) >>  2;
	*error_reason_list0 = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint8_t bmu_bmu_error_status_error_reason_list_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_ERROR_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000C000)) >> 14);
}
__INLINE uint8_t bmu_bmu_error_status_error_reason_list_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_ERROR_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00003000)) >> 12);
}
__INLINE uint8_t bmu_bmu_error_status_error_reason_list_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_ERROR_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000C00)) >> 10);
}
__INLINE uint8_t bmu_bmu_error_status_error_reason_list_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_ERROR_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000300)) >> 8);
}
__INLINE uint8_t bmu_bmu_error_status_error_reason_list_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_ERROR_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE uint8_t bmu_bmu_error_status_error_reason_list_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_ERROR_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000030)) >> 4);
}
__INLINE uint8_t bmu_bmu_error_status_error_reason_list_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_ERROR_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000C)) >> 2);
}
__INLINE uint8_t bmu_bmu_error_status_error_reason_list_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_ERROR_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}

/**
 * @brief BMU_ERROR_ADDR_CAPTURE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 ERROR_ADDR                0x0
 * </pre>
 */
#define BMU_BMU_ERROR_ADDR_CAPTURE_ADDR        (REG_BMU_BASE_ADDR+0x00000248)
#define BMU_BMU_ERROR_ADDR_CAPTURE_OFFSET      0x00000248
#define BMU_BMU_ERROR_ADDR_CAPTURE_INDEX       0x00000092
#define BMU_BMU_ERROR_ADDR_CAPTURE_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_error_addr_capture_get(void)
{
	return REG_PL_RD(BMU_BMU_ERROR_ADDR_CAPTURE_ADDR);
}

// field definitions
#define BMU_BMU_ERROR_ADDR_CAPTURE_ERROR_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BMU_ERROR_ADDR_CAPTURE_ERROR_ADDR_LSB    0
#define BMU_BMU_ERROR_ADDR_CAPTURE_ERROR_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BMU_BMU_ERROR_ADDR_CAPTURE_ERROR_ADDR_RST    0x0

__INLINE uint32_t bmu_bmu_error_addr_capture_error_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_ERROR_ADDR_CAPTURE_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BMU_ERROR_ID_CAPTURE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    03:00 ERROR_LIST_ID             0x0
 * </pre>
 */
#define BMU_BMU_ERROR_ID_CAPTURE_ADDR        (REG_BMU_BASE_ADDR+0x0000024C)
#define BMU_BMU_ERROR_ID_CAPTURE_OFFSET      0x0000024C
#define BMU_BMU_ERROR_ID_CAPTURE_INDEX       0x00000093
#define BMU_BMU_ERROR_ID_CAPTURE_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_error_id_capture_get(void)
{
	return REG_PL_RD(BMU_BMU_ERROR_ID_CAPTURE_ADDR);
}

// field definitions
#define BMU_BMU_ERROR_ID_CAPTURE_ERROR_LIST_ID_MASK    ((uint32_t)0x0000000F)
#define BMU_BMU_ERROR_ID_CAPTURE_ERROR_LIST_ID_LSB    0
#define BMU_BMU_ERROR_ID_CAPTURE_ERROR_LIST_ID_WIDTH    ((uint32_t)0x00000004)

#define BMU_BMU_ERROR_ID_CAPTURE_ERROR_LIST_ID_RST    0x0

__INLINE uint8_t bmu_bmu_error_id_capture_error_list_id_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_ERROR_ID_CAPTURE_ADDR);
	return (uint8_t)(localVal >> 0);
}

/**
 * @brief BMU_INT_EN_LMAC register definition
 *  LMAC interrupt enable register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 LIST_ERROR_EN             0x0
 *    15:00 LIST_NOT_EMPTY_EN         0x0
 * </pre>
 */
#define BMU_BMU_INT_EN_LMAC_ADDR        (REG_BMU_BASE_ADDR+0x00000250)
#define BMU_BMU_INT_EN_LMAC_OFFSET      0x00000250
#define BMU_BMU_INT_EN_LMAC_INDEX       0x00000094
#define BMU_BMU_INT_EN_LMAC_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_int_en_lmac_get(void)
{
	return REG_PL_RD(BMU_BMU_INT_EN_LMAC_ADDR);
}

__INLINE void bmu_bmu_int_en_lmac_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_INT_EN_LMAC_ADDR, value);
}

// field definitions
#define BMU_BMU_INT_EN_LMAC_LIST_ERROR_EN_MASK    ((uint32_t)0xFFFF0000)
#define BMU_BMU_INT_EN_LMAC_LIST_ERROR_EN_LSB    16
#define BMU_BMU_INT_EN_LMAC_LIST_ERROR_EN_WIDTH    ((uint32_t)0x00000010)
#define BMU_BMU_INT_EN_LMAC_LIST_NOT_EMPTY_EN_MASK    ((uint32_t)0x0000FFFF)
#define BMU_BMU_INT_EN_LMAC_LIST_NOT_EMPTY_EN_LSB    0
#define BMU_BMU_INT_EN_LMAC_LIST_NOT_EMPTY_EN_WIDTH    ((uint32_t)0x00000010)

#define BMU_BMU_INT_EN_LMAC_LIST_ERROR_EN_RST    0x0
#define BMU_BMU_INT_EN_LMAC_LIST_NOT_EMPTY_EN_RST    0x0

__INLINE void bmu_bmu_int_en_lmac_pack(uint16_t list_error_en, uint16_t list_not_empty_en)
{
	ASSERT_ERR((((uint32_t)list_error_en << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)list_not_empty_en << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(BMU_BMU_INT_EN_LMAC_ADDR,  ((uint32_t)list_error_en << 16) |((uint32_t)list_not_empty_en << 0));
}

__INLINE void bmu_bmu_int_en_lmac_unpack(uint16_t* list_error_en, uint16_t* list_not_empty_en)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_INT_EN_LMAC_ADDR);

	*list_error_en = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*list_not_empty_en = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t bmu_bmu_int_en_lmac_list_error_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_INT_EN_LMAC_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void bmu_bmu_int_en_lmac_list_error_en_setf(uint16_t listerroren)
{
	ASSERT_ERR((((uint32_t)listerroren << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(BMU_BMU_INT_EN_LMAC_ADDR, (REG_PL_RD(BMU_BMU_INT_EN_LMAC_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)listerroren <<16));
}
__INLINE uint16_t bmu_bmu_int_en_lmac_list_not_empty_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_INT_EN_LMAC_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void bmu_bmu_int_en_lmac_list_not_empty_en_setf(uint16_t listnotemptyen)
{
	ASSERT_ERR((((uint32_t)listnotemptyen << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(BMU_BMU_INT_EN_LMAC_ADDR, (REG_PL_RD(BMU_BMU_INT_EN_LMAC_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)listnotemptyen <<0));
}

/**
 * @brief BMU_INT_EN_UMAC register definition
 *  UMAC interrupt enable register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 LIST_ERROR_EN             0x0
 *    15:00 LIST_NOT_EMPTY_EN         0x0
 * </pre>
 */
#define BMU_BMU_INT_EN_UMAC_ADDR        (REG_BMU_BASE_ADDR+0x00000254)
#define BMU_BMU_INT_EN_UMAC_OFFSET      0x00000254
#define BMU_BMU_INT_EN_UMAC_INDEX       0x00000095
#define BMU_BMU_INT_EN_UMAC_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_int_en_umac_get(void)
{
	return REG_PL_RD(BMU_BMU_INT_EN_UMAC_ADDR);
}

__INLINE void bmu_bmu_int_en_umac_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_INT_EN_UMAC_ADDR, value);
}

// field definitions
#define BMU_BMU_INT_EN_UMAC_LIST_ERROR_EN_MASK    ((uint32_t)0xFFFF0000)
#define BMU_BMU_INT_EN_UMAC_LIST_ERROR_EN_LSB    16
#define BMU_BMU_INT_EN_UMAC_LIST_ERROR_EN_WIDTH    ((uint32_t)0x00000010)
#define BMU_BMU_INT_EN_UMAC_LIST_NOT_EMPTY_EN_MASK    ((uint32_t)0x0000FFFF)
#define BMU_BMU_INT_EN_UMAC_LIST_NOT_EMPTY_EN_LSB    0
#define BMU_BMU_INT_EN_UMAC_LIST_NOT_EMPTY_EN_WIDTH    ((uint32_t)0x00000010)

#define BMU_BMU_INT_EN_UMAC_LIST_ERROR_EN_RST    0x0
#define BMU_BMU_INT_EN_UMAC_LIST_NOT_EMPTY_EN_RST    0x0

__INLINE void bmu_bmu_int_en_umac_pack(uint16_t list_error_en, uint16_t list_not_empty_en)
{
	ASSERT_ERR((((uint32_t)list_error_en << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)list_not_empty_en << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(BMU_BMU_INT_EN_UMAC_ADDR,  ((uint32_t)list_error_en << 16) |((uint32_t)list_not_empty_en << 0));
}

__INLINE void bmu_bmu_int_en_umac_unpack(uint16_t* list_error_en, uint16_t* list_not_empty_en)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_INT_EN_UMAC_ADDR);

	*list_error_en = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*list_not_empty_en = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t bmu_bmu_int_en_umac_list_error_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_INT_EN_UMAC_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void bmu_bmu_int_en_umac_list_error_en_setf(uint16_t listerroren)
{
	ASSERT_ERR((((uint32_t)listerroren << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(BMU_BMU_INT_EN_UMAC_ADDR, (REG_PL_RD(BMU_BMU_INT_EN_UMAC_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)listerroren <<16));
}
__INLINE uint16_t bmu_bmu_int_en_umac_list_not_empty_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_INT_EN_UMAC_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void bmu_bmu_int_en_umac_list_not_empty_en_setf(uint16_t listnotemptyen)
{
	ASSERT_ERR((((uint32_t)listnotemptyen << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(BMU_BMU_INT_EN_UMAC_ADDR, (REG_PL_RD(BMU_BMU_INT_EN_UMAC_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)listnotemptyen <<0));
}

/**
 * @brief BMU_INT_EN_SMAC register definition
 *  SMAC interrupt enable register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 LIST_ERROR_EN             0x0
 *    15:00 LIST_NOT_EMPTY_EN         0x0
 * </pre>
 */
#define BMU_BMU_INT_EN_SMAC_ADDR        (REG_BMU_BASE_ADDR+0x00000258)
#define BMU_BMU_INT_EN_SMAC_OFFSET      0x00000258
#define BMU_BMU_INT_EN_SMAC_INDEX       0x00000096
#define BMU_BMU_INT_EN_SMAC_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_int_en_smac_get(void)
{
	return REG_PL_RD(BMU_BMU_INT_EN_SMAC_ADDR);
}

__INLINE void bmu_bmu_int_en_smac_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_INT_EN_SMAC_ADDR, value);
}

// field definitions
#define BMU_BMU_INT_EN_SMAC_LIST_ERROR_EN_MASK    ((uint32_t)0xFFFF0000)
#define BMU_BMU_INT_EN_SMAC_LIST_ERROR_EN_LSB    16
#define BMU_BMU_INT_EN_SMAC_LIST_ERROR_EN_WIDTH    ((uint32_t)0x00000010)
#define BMU_BMU_INT_EN_SMAC_LIST_NOT_EMPTY_EN_MASK    ((uint32_t)0x0000FFFF)
#define BMU_BMU_INT_EN_SMAC_LIST_NOT_EMPTY_EN_LSB    0
#define BMU_BMU_INT_EN_SMAC_LIST_NOT_EMPTY_EN_WIDTH    ((uint32_t)0x00000010)

#define BMU_BMU_INT_EN_SMAC_LIST_ERROR_EN_RST    0x0
#define BMU_BMU_INT_EN_SMAC_LIST_NOT_EMPTY_EN_RST    0x0

__INLINE void bmu_bmu_int_en_smac_pack(uint16_t list_error_en, uint16_t list_not_empty_en)
{
	ASSERT_ERR((((uint32_t)list_error_en << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)list_not_empty_en << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(BMU_BMU_INT_EN_SMAC_ADDR,  ((uint32_t)list_error_en << 16) |((uint32_t)list_not_empty_en << 0));
}

__INLINE void bmu_bmu_int_en_smac_unpack(uint16_t* list_error_en, uint16_t* list_not_empty_en)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_INT_EN_SMAC_ADDR);

	*list_error_en = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*list_not_empty_en = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t bmu_bmu_int_en_smac_list_error_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_INT_EN_SMAC_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void bmu_bmu_int_en_smac_list_error_en_setf(uint16_t listerroren)
{
	ASSERT_ERR((((uint32_t)listerroren << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(BMU_BMU_INT_EN_SMAC_ADDR, (REG_PL_RD(BMU_BMU_INT_EN_SMAC_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)listerroren <<16));
}
__INLINE uint16_t bmu_bmu_int_en_smac_list_not_empty_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_INT_EN_SMAC_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void bmu_bmu_int_en_smac_list_not_empty_en_setf(uint16_t listnotemptyen)
{
	ASSERT_ERR((((uint32_t)listnotemptyen << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(BMU_BMU_INT_EN_SMAC_ADDR, (REG_PL_RD(BMU_BMU_INT_EN_SMAC_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)listnotemptyen <<0));
}

/**
 * @brief BMU_INT_STAT_LMAC register definition
 *  LMAC interrupt status register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 LIST_ERROR                0x0
 *    15:00 LIST_NOT_EMPTY            0x0
 * </pre>
 */
#define BMU_BMU_INT_STAT_LMAC_ADDR        (REG_BMU_BASE_ADDR+0x0000025C)
#define BMU_BMU_INT_STAT_LMAC_OFFSET      0x0000025C
#define BMU_BMU_INT_STAT_LMAC_INDEX       0x00000097
#define BMU_BMU_INT_STAT_LMAC_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_int_stat_lmac_get(void)
{
	return REG_PL_RD(BMU_BMU_INT_STAT_LMAC_ADDR);
}

// field definitions
#define BMU_BMU_INT_STAT_LMAC_LIST_ERROR_MASK    ((uint32_t)0xFFFF0000)
#define BMU_BMU_INT_STAT_LMAC_LIST_ERROR_LSB    16
#define BMU_BMU_INT_STAT_LMAC_LIST_ERROR_WIDTH    ((uint32_t)0x00000010)
#define BMU_BMU_INT_STAT_LMAC_LIST_NOT_EMPTY_MASK    ((uint32_t)0x0000FFFF)
#define BMU_BMU_INT_STAT_LMAC_LIST_NOT_EMPTY_LSB    0
#define BMU_BMU_INT_STAT_LMAC_LIST_NOT_EMPTY_WIDTH    ((uint32_t)0x00000010)

#define BMU_BMU_INT_STAT_LMAC_LIST_ERROR_RST    0x0
#define BMU_BMU_INT_STAT_LMAC_LIST_NOT_EMPTY_RST    0x0

__INLINE void bmu_bmu_int_stat_lmac_unpack(uint16_t* list_error, uint16_t* list_not_empty)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_INT_STAT_LMAC_ADDR);

	*list_error = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*list_not_empty = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t bmu_bmu_int_stat_lmac_list_error_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_INT_STAT_LMAC_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE uint16_t bmu_bmu_int_stat_lmac_list_not_empty_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_INT_STAT_LMAC_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

/**
 * @brief BMU_INT_STAT_UMAC register definition
 *  UMAC interrupt status register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 LIST_ERROR                0x0
 *    15:00 LIST_NOT_EMPTY            0x0
 * </pre>
 */
#define BMU_BMU_INT_STAT_UMAC_ADDR        (REG_BMU_BASE_ADDR+0x00000260)
#define BMU_BMU_INT_STAT_UMAC_OFFSET      0x00000260
#define BMU_BMU_INT_STAT_UMAC_INDEX       0x00000098
#define BMU_BMU_INT_STAT_UMAC_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_int_stat_umac_get(void)
{
	return REG_PL_RD(BMU_BMU_INT_STAT_UMAC_ADDR);
}

// field definitions
#define BMU_BMU_INT_STAT_UMAC_LIST_ERROR_MASK    ((uint32_t)0xFFFF0000)
#define BMU_BMU_INT_STAT_UMAC_LIST_ERROR_LSB    16
#define BMU_BMU_INT_STAT_UMAC_LIST_ERROR_WIDTH    ((uint32_t)0x00000010)
#define BMU_BMU_INT_STAT_UMAC_LIST_NOT_EMPTY_MASK    ((uint32_t)0x0000FFFF)
#define BMU_BMU_INT_STAT_UMAC_LIST_NOT_EMPTY_LSB    0
#define BMU_BMU_INT_STAT_UMAC_LIST_NOT_EMPTY_WIDTH    ((uint32_t)0x00000010)

#define BMU_BMU_INT_STAT_UMAC_LIST_ERROR_RST    0x0
#define BMU_BMU_INT_STAT_UMAC_LIST_NOT_EMPTY_RST    0x0

__INLINE void bmu_bmu_int_stat_umac_unpack(uint16_t* list_error, uint16_t* list_not_empty)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_INT_STAT_UMAC_ADDR);

	*list_error = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*list_not_empty = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t bmu_bmu_int_stat_umac_list_error_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_INT_STAT_UMAC_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE uint16_t bmu_bmu_int_stat_umac_list_not_empty_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_INT_STAT_UMAC_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

/**
 * @brief BMU_INT_STAT_SMAC register definition
 *  SMAC interrupt status register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 LIST_ERROR                0x0
 *    15:00 LIST_NOT_EMPTY            0x0
 * </pre>
 */
#define BMU_BMU_INT_STAT_SMAC_ADDR        (REG_BMU_BASE_ADDR+0x00000264)
#define BMU_BMU_INT_STAT_SMAC_OFFSET      0x00000264
#define BMU_BMU_INT_STAT_SMAC_INDEX       0x00000099
#define BMU_BMU_INT_STAT_SMAC_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_int_stat_smac_get(void)
{
	return REG_PL_RD(BMU_BMU_INT_STAT_SMAC_ADDR);
}

// field definitions
#define BMU_BMU_INT_STAT_SMAC_LIST_ERROR_MASK    ((uint32_t)0xFFFF0000)
#define BMU_BMU_INT_STAT_SMAC_LIST_ERROR_LSB    16
#define BMU_BMU_INT_STAT_SMAC_LIST_ERROR_WIDTH    ((uint32_t)0x00000010)
#define BMU_BMU_INT_STAT_SMAC_LIST_NOT_EMPTY_MASK    ((uint32_t)0x0000FFFF)
#define BMU_BMU_INT_STAT_SMAC_LIST_NOT_EMPTY_LSB    0
#define BMU_BMU_INT_STAT_SMAC_LIST_NOT_EMPTY_WIDTH    ((uint32_t)0x00000010)

#define BMU_BMU_INT_STAT_SMAC_LIST_ERROR_RST    0x0
#define BMU_BMU_INT_STAT_SMAC_LIST_NOT_EMPTY_RST    0x0

__INLINE void bmu_bmu_int_stat_smac_unpack(uint16_t* list_error, uint16_t* list_not_empty)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_INT_STAT_SMAC_ADDR);

	*list_error = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*list_not_empty = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t bmu_bmu_int_stat_smac_list_error_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_INT_STAT_SMAC_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE uint16_t bmu_bmu_int_stat_smac_list_not_empty_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_INT_STAT_SMAC_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

/**
 * @brief BMU_INT_FORCE register definition
 *  Force interrupt register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 FORCE_LIST_ERROR          0x0
 *    15:00 FORCE_LIST_NOT_EMPTY      0x0
 * </pre>
 */
#define BMU_BMU_INT_FORCE_ADDR        (REG_BMU_BASE_ADDR+0x00000268)
#define BMU_BMU_INT_FORCE_OFFSET      0x00000268
#define BMU_BMU_INT_FORCE_INDEX       0x0000009A
#define BMU_BMU_INT_FORCE_RESET       0x00000000

__INLINE void bmu_bmu_int_force_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_INT_FORCE_ADDR, value);
}

// field definitions
#define BMU_BMU_INT_FORCE_FORCE_LIST_ERROR_MASK    ((uint32_t)0xFFFF0000)
#define BMU_BMU_INT_FORCE_FORCE_LIST_ERROR_LSB    16
#define BMU_BMU_INT_FORCE_FORCE_LIST_ERROR_WIDTH    ((uint32_t)0x00000010)
#define BMU_BMU_INT_FORCE_FORCE_LIST_NOT_EMPTY_MASK    ((uint32_t)0x0000FFFF)
#define BMU_BMU_INT_FORCE_FORCE_LIST_NOT_EMPTY_LSB    0
#define BMU_BMU_INT_FORCE_FORCE_LIST_NOT_EMPTY_WIDTH    ((uint32_t)0x00000010)

#define BMU_BMU_INT_FORCE_FORCE_LIST_ERROR_RST    0x0
#define BMU_BMU_INT_FORCE_FORCE_LIST_NOT_EMPTY_RST    0x0

__INLINE void bmu_bmu_int_force_pack(uint16_t force_list_error, uint16_t force_list_not_empty)
{
	ASSERT_ERR((((uint32_t)force_list_error << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)force_list_not_empty << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(BMU_BMU_INT_FORCE_ADDR,  ((uint32_t)force_list_error << 16) |((uint32_t)force_list_not_empty << 0));
}

__INLINE void bmu_bmu_int_force_force_list_error_setf(uint16_t forcelisterror)
{
	ASSERT_ERR((((uint32_t)forcelisterror << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(BMU_BMU_INT_FORCE_ADDR, (REG_PL_RD(BMU_BMU_INT_FORCE_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)forcelisterror <<16));
}
__INLINE void bmu_bmu_int_force_force_list_not_empty_setf(uint16_t forcelistnotempty)
{
	ASSERT_ERR((((uint32_t)forcelistnotempty << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(BMU_BMU_INT_FORCE_ADDR, (REG_PL_RD(BMU_BMU_INT_FORCE_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)forcelistnotempty <<0));
}

/**
 * @brief BMU_INT_CLEAR register definition
 *  Clear Interrupt Register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 CLEAR_LIST_ERROR          0x0
 *    15:00 CLEAR_LIST_NOT_EMPTY      0x0
 * </pre>
 */
#define BMU_BMU_INT_CLEAR_ADDR        (REG_BMU_BASE_ADDR+0x0000026C)
#define BMU_BMU_INT_CLEAR_OFFSET      0x0000026C
#define BMU_BMU_INT_CLEAR_INDEX       0x0000009B
#define BMU_BMU_INT_CLEAR_RESET       0x00000000

__INLINE void bmu_bmu_int_clear_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_INT_CLEAR_ADDR, value);
}

// field definitions
#define BMU_BMU_INT_CLEAR_CLEAR_LIST_ERROR_MASK    ((uint32_t)0xFFFF0000)
#define BMU_BMU_INT_CLEAR_CLEAR_LIST_ERROR_LSB    16
#define BMU_BMU_INT_CLEAR_CLEAR_LIST_ERROR_WIDTH    ((uint32_t)0x00000010)
#define BMU_BMU_INT_CLEAR_CLEAR_LIST_NOT_EMPTY_MASK    ((uint32_t)0x0000FFFF)
#define BMU_BMU_INT_CLEAR_CLEAR_LIST_NOT_EMPTY_LSB    0
#define BMU_BMU_INT_CLEAR_CLEAR_LIST_NOT_EMPTY_WIDTH    ((uint32_t)0x00000010)

#define BMU_BMU_INT_CLEAR_CLEAR_LIST_ERROR_RST    0x0
#define BMU_BMU_INT_CLEAR_CLEAR_LIST_NOT_EMPTY_RST    0x0

__INLINE void bmu_bmu_int_clear_pack(uint16_t clear_list_error, uint16_t clear_list_not_empty)
{
	ASSERT_ERR((((uint32_t)clear_list_error << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)clear_list_not_empty << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(BMU_BMU_INT_CLEAR_ADDR,  ((uint32_t)clear_list_error << 16) |((uint32_t)clear_list_not_empty << 0));
}

__INLINE void bmu_bmu_int_clear_clear_list_error_setf(uint16_t clearlisterror)
{
	ASSERT_ERR((((uint32_t)clearlisterror << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(BMU_BMU_INT_CLEAR_ADDR, (REG_PL_RD(BMU_BMU_INT_CLEAR_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)clearlisterror <<16));
}
__INLINE void bmu_bmu_int_clear_clear_list_not_empty_setf(uint16_t clearlistnotempty)
{
	ASSERT_ERR((((uint32_t)clearlistnotempty << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(BMU_BMU_INT_CLEAR_ADDR, (REG_PL_RD(BMU_BMU_INT_CLEAR_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)clearlistnotempty <<0));
}

/**
 * @brief BMU_MODE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    IGNORE_SAME_RELAESE_ADDR  0              
 * </pre>
 */
#define BMU_BMU_MODE_ADDR        (REG_BMU_BASE_ADDR+0x00000270)
#define BMU_BMU_MODE_OFFSET      0x00000270
#define BMU_BMU_MODE_INDEX       0x0000009C
#define BMU_BMU_MODE_RESET       0x00000000

__INLINE uint32_t  bmu_bmu_mode_get(void)
{
	return REG_PL_RD(BMU_BMU_MODE_ADDR);
}

__INLINE void bmu_bmu_mode_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_MODE_ADDR, value);
}

// field definitions
#define BMU_BMU_MODE_IGNORE_SAME_RELAESE_ADDR_BIT    ((uint32_t)0x00000001)
#define BMU_BMU_MODE_IGNORE_SAME_RELAESE_ADDR_POS    0

#define BMU_BMU_MODE_IGNORE_SAME_RELAESE_ADDR_RST    0x0

__INLINE uint8_t bmu_bmu_mode_ignore_same_relaese_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_MODE_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void bmu_bmu_mode_ignore_same_relaese_addr_setf(uint8_t ignoresamerelaeseaddr)
{
	ASSERT_ERR((((uint32_t)ignoresamerelaeseaddr << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(BMU_BMU_MODE_ADDR, (uint32_t)ignoresamerelaeseaddr << 0);
}

/**
 * @brief BMU_GENERAL_ERROR_CLEAR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    GENERAL_ERROR_CLEAR       0              
 * </pre>
 */
#define BMU_BMU_GENERAL_ERROR_CLEAR_ADDR        (REG_BMU_BASE_ADDR+0x00000274)
#define BMU_BMU_GENERAL_ERROR_CLEAR_OFFSET      0x00000274
#define BMU_BMU_GENERAL_ERROR_CLEAR_INDEX       0x0000009D
#define BMU_BMU_GENERAL_ERROR_CLEAR_RESET       0x00000000

__INLINE void bmu_bmu_general_error_clear_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_GENERAL_ERROR_CLEAR_ADDR, value);
}

// field definitions
#define BMU_BMU_GENERAL_ERROR_CLEAR_GENERAL_ERROR_CLEAR_BIT    ((uint32_t)0x00000001)
#define BMU_BMU_GENERAL_ERROR_CLEAR_GENERAL_ERROR_CLEAR_POS    0

#define BMU_BMU_GENERAL_ERROR_CLEAR_GENERAL_ERROR_CLEAR_RST    0x0

__INLINE void bmu_bmu_general_error_clear_general_error_clear_setf(uint8_t generalerrorclear)
{
	ASSERT_ERR((((uint32_t)generalerrorclear << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(BMU_BMU_GENERAL_ERROR_CLEAR_ADDR, (uint32_t)generalerrorclear << 0);
}

/**
 * @brief BMU_DEBUG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    12    FIFO_EMPTY                1              
 *    11:08 AXI_STATE                 0x0
 *    07:00 FREE_LIST_STATUS          0xFF
 * </pre>
 */
#define BMU_BMU_DEBUG_ADDR        (REG_BMU_BASE_ADDR+0x00000278)
#define BMU_BMU_DEBUG_OFFSET      0x00000278
#define BMU_BMU_DEBUG_INDEX       0x0000009E
#define BMU_BMU_DEBUG_RESET       0x000010FF

__INLINE uint32_t  bmu_bmu_debug_get(void)
{
	return REG_PL_RD(BMU_BMU_DEBUG_ADDR);
}

// field definitions
#define BMU_BMU_DEBUG_FIFO_EMPTY_BIT        ((uint32_t)0x00001000)
#define BMU_BMU_DEBUG_FIFO_EMPTY_POS        12
#define BMU_BMU_DEBUG_AXI_STATE_MASK        ((uint32_t)0x00000F00)
#define BMU_BMU_DEBUG_AXI_STATE_LSB         8
#define BMU_BMU_DEBUG_AXI_STATE_WIDTH       ((uint32_t)0x00000004)
#define BMU_BMU_DEBUG_FREE_LIST_STATUS_MASK    ((uint32_t)0x000000FF)
#define BMU_BMU_DEBUG_FREE_LIST_STATUS_LSB    0
#define BMU_BMU_DEBUG_FREE_LIST_STATUS_WIDTH    ((uint32_t)0x00000008)

#define BMU_BMU_DEBUG_FIFO_EMPTY_RST        0x1
#define BMU_BMU_DEBUG_AXI_STATE_RST         0x0
#define BMU_BMU_DEBUG_FREE_LIST_STATUS_RST    0xFF

__INLINE void bmu_bmu_debug_unpack(uint8_t* fifo_empty, uint8_t* axi_state, uint8_t* free_list_status)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_DEBUG_ADDR);

	*fifo_empty = (localVal & ((uint32_t)0x00001000)) >>  12;
	*axi_state = (localVal & ((uint32_t)0x00000F00)) >>  8;
	*free_list_status = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t bmu_bmu_debug_fifo_empty_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_DEBUG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE uint8_t bmu_bmu_debug_axi_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_DEBUG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000F00)) >> 8);
}
__INLINE uint8_t bmu_bmu_debug_free_list_status_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BMU_DEBUG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/**
 * @brief BMU_SW_RST register definition
 *  SW reset register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    SW_RST                    0              
 * </pre>
 */
#define BMU_BMU_SW_RST_ADDR        (REG_BMU_BASE_ADDR+0x0000027C)
#define BMU_BMU_SW_RST_OFFSET      0x0000027C
#define BMU_BMU_SW_RST_INDEX       0x0000009F
#define BMU_BMU_SW_RST_RESET       0x00000000

__INLINE void bmu_bmu_sw_rst_set(uint32_t value)
{
	REG_PL_WR(BMU_BMU_SW_RST_ADDR, value);
}

// field definitions
#define BMU_BMU_SW_RST_SW_RST_BIT           ((uint32_t)0x00000001)
#define BMU_BMU_SW_RST_SW_RST_POS           0

#define BMU_BMU_SW_RST_SW_RST_RST           0x0

__INLINE void bmu_bmu_sw_rst_sw_rst_setf(uint8_t swrst)
{
	ASSERT_ERR((((uint32_t)swrst << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(BMU_BMU_SW_RST_ADDR, (uint32_t)swrst << 0);
}

/**
 * @brief BAU_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    BAU_EN                    0              
 * </pre>
 */
#define BMU_BAU_EN_ADDR        (REG_BMU_BASE_ADDR+0x00000800)
#define BMU_BAU_EN_OFFSET      0x00000800
#define BMU_BAU_EN_INDEX       0x00000200
#define BMU_BAU_EN_RESET       0x00000000

__INLINE uint32_t  bmu_bau_en_get(void)
{
	return REG_PL_RD(BMU_BAU_EN_ADDR);
}

__INLINE void bmu_bau_en_set(uint32_t value)
{
	REG_PL_WR(BMU_BAU_EN_ADDR, value);
}

// field definitions
#define BMU_BAU_EN_BAU_EN_BIT               ((uint32_t)0x00000001)
#define BMU_BAU_EN_BAU_EN_POS               0

#define BMU_BAU_EN_BAU_EN_RST               0x0

__INLINE uint8_t bmu_bau_en_bau_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_EN_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void bmu_bau_en_bau_en_setf(uint8_t bauen)
{
	ASSERT_ERR((((uint32_t)bauen << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(BMU_BAU_EN_ADDR, (uint32_t)bauen << 0);
}

/**
 * @brief BAU_DEBUG_MODE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    BAU_DEBUG_EN              0              
 * </pre>
 */
#define BMU_BAU_DEBUG_MODE_ADDR        (REG_BMU_BASE_ADDR+0x00000804)
#define BMU_BAU_DEBUG_MODE_OFFSET      0x00000804
#define BMU_BAU_DEBUG_MODE_INDEX       0x00000201
#define BMU_BAU_DEBUG_MODE_RESET       0x00000000

__INLINE uint32_t  bmu_bau_debug_mode_get(void)
{
	return REG_PL_RD(BMU_BAU_DEBUG_MODE_ADDR);
}

__INLINE void bmu_bau_debug_mode_set(uint32_t value)
{
	REG_PL_WR(BMU_BAU_DEBUG_MODE_ADDR, value);
}

// field definitions
#define BMU_BAU_DEBUG_MODE_BAU_DEBUG_EN_BIT    ((uint32_t)0x00000001)
#define BMU_BAU_DEBUG_MODE_BAU_DEBUG_EN_POS    0

#define BMU_BAU_DEBUG_MODE_BAU_DEBUG_EN_RST    0x0

__INLINE uint8_t bmu_bau_debug_mode_bau_debug_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_DEBUG_MODE_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void bmu_bau_debug_mode_bau_debug_en_setf(uint8_t baudebugen)
{
	ASSERT_ERR((((uint32_t)baudebugen << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(BMU_BAU_DEBUG_MODE_ADDR, (uint32_t)baudebugen << 0);
}

/**
 * @brief BAU_RPD_TERM_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RPD_TERM_ADDR             0x0
 * </pre>
 */
#define BMU_BAU_RPD_TERM_ADDR_ADDR        (REG_BMU_BASE_ADDR+0x00000808)
#define BMU_BAU_RPD_TERM_ADDR_OFFSET      0x00000808
#define BMU_BAU_RPD_TERM_ADDR_INDEX       0x00000202
#define BMU_BAU_RPD_TERM_ADDR_RESET       0x00000000

__INLINE uint32_t  bmu_bau_rpd_term_addr_get(void)
{
	return REG_PL_RD(BMU_BAU_RPD_TERM_ADDR_ADDR);
}

__INLINE void bmu_bau_rpd_term_addr_set(uint32_t value)
{
	REG_PL_WR(BMU_BAU_RPD_TERM_ADDR_ADDR, value);
}

// field definitions
#define BMU_BAU_RPD_TERM_ADDR_RPD_TERM_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BAU_RPD_TERM_ADDR_RPD_TERM_ADDR_LSB    0
#define BMU_BAU_RPD_TERM_ADDR_RPD_TERM_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BMU_BAU_RPD_TERM_ADDR_RPD_TERM_ADDR_RST    0x0

__INLINE uint32_t bmu_bau_rpd_term_addr_rpd_term_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_RPD_TERM_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bmu_bau_rpd_term_addr_rpd_term_addr_setf(uint32_t rpdtermaddr)
{
	ASSERT_ERR((((uint32_t)rpdtermaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BAU_RPD_TERM_ADDR_ADDR, (uint32_t)rpdtermaddr << 0);
}

/**
 * @brief BAU_MAC_LIST_ID_FOR_CONF_BAND_0_INIT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    04:00 MAC_LIST_ID               0x0
 * </pre>
 */
#define BMU_BAU_MAC_LIST_ID_FOR_CONF_BAND_0_INIT_ADDR        (REG_BMU_BASE_ADDR+0x00000810)
#define BMU_BAU_MAC_LIST_ID_FOR_CONF_BAND_0_INIT_OFFSET      0x00000810
#define BMU_BAU_MAC_LIST_ID_FOR_CONF_BAND_0_INIT_INDEX       0x00000204
#define BMU_BAU_MAC_LIST_ID_FOR_CONF_BAND_0_INIT_RESET       0x00000000

__INLINE void bmu_bau_mac_list_id_for_conf_band_0_init_set(uint32_t value)
{
	REG_PL_WR(BMU_BAU_MAC_LIST_ID_FOR_CONF_BAND_0_INIT_ADDR, value);
}

// field definitions
#define BMU_BAU_MAC_LIST_ID_FOR_CONF_BAND_0_INIT_MAC_LIST_ID_MASK    ((uint32_t)0x0000001F)
#define BMU_BAU_MAC_LIST_ID_FOR_CONF_BAND_0_INIT_MAC_LIST_ID_LSB    0
#define BMU_BAU_MAC_LIST_ID_FOR_CONF_BAND_0_INIT_MAC_LIST_ID_WIDTH    ((uint32_t)0x00000005)

#define BMU_BAU_MAC_LIST_ID_FOR_CONF_BAND_0_INIT_MAC_LIST_ID_RST    0x0

__INLINE void bmu_bau_mac_list_id_for_conf_band_0_init_mac_list_id_setf(uint8_t maclistid)
{
	ASSERT_ERR((((uint32_t)maclistid << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(BMU_BAU_MAC_LIST_ID_FOR_CONF_BAND_0_INIT_ADDR, (uint32_t)maclistid << 0);
}

/**
 * @brief BAU_MAC_LIST_TAIL_BAND_0_INIT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 MAC_LIST_TAIL             0x0
 * </pre>
 */
#define BMU_BAU_MAC_LIST_TAIL_BAND_0_INIT_ADDR        (REG_BMU_BASE_ADDR+0x00000814)
#define BMU_BAU_MAC_LIST_TAIL_BAND_0_INIT_OFFSET      0x00000814
#define BMU_BAU_MAC_LIST_TAIL_BAND_0_INIT_INDEX       0x00000205
#define BMU_BAU_MAC_LIST_TAIL_BAND_0_INIT_RESET       0x00000000

__INLINE void bmu_bau_mac_list_tail_band_0_init_set(uint32_t value)
{
	REG_PL_WR(BMU_BAU_MAC_LIST_TAIL_BAND_0_INIT_ADDR, value);
}

// field definitions
#define BMU_BAU_MAC_LIST_TAIL_BAND_0_INIT_MAC_LIST_TAIL_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BAU_MAC_LIST_TAIL_BAND_0_INIT_MAC_LIST_TAIL_LSB    0
#define BMU_BAU_MAC_LIST_TAIL_BAND_0_INIT_MAC_LIST_TAIL_WIDTH    ((uint32_t)0x00000020)

#define BMU_BAU_MAC_LIST_TAIL_BAND_0_INIT_MAC_LIST_TAIL_RST    0x0

__INLINE void bmu_bau_mac_list_tail_band_0_init_mac_list_tail_setf(uint32_t maclisttail)
{
	ASSERT_ERR((((uint32_t)maclisttail << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BAU_MAC_LIST_TAIL_BAND_0_INIT_ADDR, (uint32_t)maclisttail << 0);
}

/**
 * @brief BAU_MAC_LIST_ID_FOR_CONF_BAND_1_INIT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    04:00 MAC_LIST_ID               0x0
 * </pre>
 */
#define BMU_BAU_MAC_LIST_ID_FOR_CONF_BAND_1_INIT_ADDR        (REG_BMU_BASE_ADDR+0x00000818)
#define BMU_BAU_MAC_LIST_ID_FOR_CONF_BAND_1_INIT_OFFSET      0x00000818
#define BMU_BAU_MAC_LIST_ID_FOR_CONF_BAND_1_INIT_INDEX       0x00000206
#define BMU_BAU_MAC_LIST_ID_FOR_CONF_BAND_1_INIT_RESET       0x00000000

__INLINE void bmu_bau_mac_list_id_for_conf_band_1_init_set(uint32_t value)
{
	REG_PL_WR(BMU_BAU_MAC_LIST_ID_FOR_CONF_BAND_1_INIT_ADDR, value);
}

// field definitions
#define BMU_BAU_MAC_LIST_ID_FOR_CONF_BAND_1_INIT_MAC_LIST_ID_MASK    ((uint32_t)0x0000001F)
#define BMU_BAU_MAC_LIST_ID_FOR_CONF_BAND_1_INIT_MAC_LIST_ID_LSB    0
#define BMU_BAU_MAC_LIST_ID_FOR_CONF_BAND_1_INIT_MAC_LIST_ID_WIDTH    ((uint32_t)0x00000005)

#define BMU_BAU_MAC_LIST_ID_FOR_CONF_BAND_1_INIT_MAC_LIST_ID_RST    0x0

__INLINE void bmu_bau_mac_list_id_for_conf_band_1_init_mac_list_id_setf(uint8_t maclistid)
{
	ASSERT_ERR((((uint32_t)maclistid << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(BMU_BAU_MAC_LIST_ID_FOR_CONF_BAND_1_INIT_ADDR, (uint32_t)maclistid << 0);
}

/**
 * @brief BAU_MAC_LIST_TAIL_BAND_1_INIT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 MAC_LIST_TAIL_INIT        0x0
 * </pre>
 */
#define BMU_BAU_MAC_LIST_TAIL_BAND_1_INIT_ADDR        (REG_BMU_BASE_ADDR+0x0000081C)
#define BMU_BAU_MAC_LIST_TAIL_BAND_1_INIT_OFFSET      0x0000081C
#define BMU_BAU_MAC_LIST_TAIL_BAND_1_INIT_INDEX       0x00000207
#define BMU_BAU_MAC_LIST_TAIL_BAND_1_INIT_RESET       0x00000000

__INLINE void bmu_bau_mac_list_tail_band_1_init_set(uint32_t value)
{
	REG_PL_WR(BMU_BAU_MAC_LIST_TAIL_BAND_1_INIT_ADDR, value);
}

// field definitions
#define BMU_BAU_MAC_LIST_TAIL_BAND_1_INIT_MAC_LIST_TAIL_INIT_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BAU_MAC_LIST_TAIL_BAND_1_INIT_MAC_LIST_TAIL_INIT_LSB    0
#define BMU_BAU_MAC_LIST_TAIL_BAND_1_INIT_MAC_LIST_TAIL_INIT_WIDTH    ((uint32_t)0x00000020)

#define BMU_BAU_MAC_LIST_TAIL_BAND_1_INIT_MAC_LIST_TAIL_INIT_RST    0x0

__INLINE void bmu_bau_mac_list_tail_band_1_init_mac_list_tail_init_setf(uint32_t maclisttailinit)
{
	ASSERT_ERR((((uint32_t)maclisttailinit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BAU_MAC_LIST_TAIL_BAND_1_INIT_ADDR, (uint32_t)maclisttailinit << 0);
}

/**
 * @brief BAU_MAC_LIST_TAIL_BAND_0_SEL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    04:00 MAC_LIST_TAIL_SEL         0x0
 * </pre>
 */
#define BMU_BAU_MAC_LIST_TAIL_BAND_0_SEL_ADDR        (REG_BMU_BASE_ADDR+0x00000820)
#define BMU_BAU_MAC_LIST_TAIL_BAND_0_SEL_OFFSET      0x00000820
#define BMU_BAU_MAC_LIST_TAIL_BAND_0_SEL_INDEX       0x00000208
#define BMU_BAU_MAC_LIST_TAIL_BAND_0_SEL_RESET       0x00000000

__INLINE void bmu_bau_mac_list_tail_band_0_sel_set(uint32_t value)
{
	REG_PL_WR(BMU_BAU_MAC_LIST_TAIL_BAND_0_SEL_ADDR, value);
}

// field definitions
#define BMU_BAU_MAC_LIST_TAIL_BAND_0_SEL_MAC_LIST_TAIL_SEL_MASK    ((uint32_t)0x0000001F)
#define BMU_BAU_MAC_LIST_TAIL_BAND_0_SEL_MAC_LIST_TAIL_SEL_LSB    0
#define BMU_BAU_MAC_LIST_TAIL_BAND_0_SEL_MAC_LIST_TAIL_SEL_WIDTH    ((uint32_t)0x00000005)

#define BMU_BAU_MAC_LIST_TAIL_BAND_0_SEL_MAC_LIST_TAIL_SEL_RST    0x0

__INLINE void bmu_bau_mac_list_tail_band_0_sel_mac_list_tail_sel_setf(uint8_t maclisttailsel)
{
	ASSERT_ERR((((uint32_t)maclisttailsel << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(BMU_BAU_MAC_LIST_TAIL_BAND_0_SEL_ADDR, (uint32_t)maclisttailsel << 0);
}

/**
 * @brief BAU_MAC_LIST_TAIL_BAND_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 MAC_LIST_TAIL             0x0
 * </pre>
 */
#define BMU_BAU_MAC_LIST_TAIL_BAND_0_ADDR        (REG_BMU_BASE_ADDR+0x00000824)
#define BMU_BAU_MAC_LIST_TAIL_BAND_0_OFFSET      0x00000824
#define BMU_BAU_MAC_LIST_TAIL_BAND_0_INDEX       0x00000209
#define BMU_BAU_MAC_LIST_TAIL_BAND_0_RESET       0x00000000

__INLINE uint32_t  bmu_bau_mac_list_tail_band_0_get(void)
{
	return REG_PL_RD(BMU_BAU_MAC_LIST_TAIL_BAND_0_ADDR);
}

// field definitions
#define BMU_BAU_MAC_LIST_TAIL_BAND_0_MAC_LIST_TAIL_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BAU_MAC_LIST_TAIL_BAND_0_MAC_LIST_TAIL_LSB    0
#define BMU_BAU_MAC_LIST_TAIL_BAND_0_MAC_LIST_TAIL_WIDTH    ((uint32_t)0x00000020)

#define BMU_BAU_MAC_LIST_TAIL_BAND_0_MAC_LIST_TAIL_RST    0x0

__INLINE uint32_t bmu_bau_mac_list_tail_band_0_mac_list_tail_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_MAC_LIST_TAIL_BAND_0_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BAU_MAC_LIST_TAIL_BAND_1_SEL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    04:00 MAC_LIST_TAIL_SEL         0x0
 * </pre>
 */
#define BMU_BAU_MAC_LIST_TAIL_BAND_1_SEL_ADDR        (REG_BMU_BASE_ADDR+0x00000828)
#define BMU_BAU_MAC_LIST_TAIL_BAND_1_SEL_OFFSET      0x00000828
#define BMU_BAU_MAC_LIST_TAIL_BAND_1_SEL_INDEX       0x0000020A
#define BMU_BAU_MAC_LIST_TAIL_BAND_1_SEL_RESET       0x00000000

__INLINE void bmu_bau_mac_list_tail_band_1_sel_set(uint32_t value)
{
	REG_PL_WR(BMU_BAU_MAC_LIST_TAIL_BAND_1_SEL_ADDR, value);
}

// field definitions
#define BMU_BAU_MAC_LIST_TAIL_BAND_1_SEL_MAC_LIST_TAIL_SEL_MASK    ((uint32_t)0x0000001F)
#define BMU_BAU_MAC_LIST_TAIL_BAND_1_SEL_MAC_LIST_TAIL_SEL_LSB    0
#define BMU_BAU_MAC_LIST_TAIL_BAND_1_SEL_MAC_LIST_TAIL_SEL_WIDTH    ((uint32_t)0x00000005)

#define BMU_BAU_MAC_LIST_TAIL_BAND_1_SEL_MAC_LIST_TAIL_SEL_RST    0x0

__INLINE void bmu_bau_mac_list_tail_band_1_sel_mac_list_tail_sel_setf(uint8_t maclisttailsel)
{
	ASSERT_ERR((((uint32_t)maclisttailsel << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(BMU_BAU_MAC_LIST_TAIL_BAND_1_SEL_ADDR, (uint32_t)maclisttailsel << 0);
}

/**
 * @brief BAU_MAC_LIST_TAIL_BAND_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 MAC_LIST_TAIL             0x0
 * </pre>
 */
#define BMU_BAU_MAC_LIST_TAIL_BAND_1_ADDR        (REG_BMU_BASE_ADDR+0x0000082C)
#define BMU_BAU_MAC_LIST_TAIL_BAND_1_OFFSET      0x0000082C
#define BMU_BAU_MAC_LIST_TAIL_BAND_1_INDEX       0x0000020B
#define BMU_BAU_MAC_LIST_TAIL_BAND_1_RESET       0x00000000

__INLINE uint32_t  bmu_bau_mac_list_tail_band_1_get(void)
{
	return REG_PL_RD(BMU_BAU_MAC_LIST_TAIL_BAND_1_ADDR);
}

// field definitions
#define BMU_BAU_MAC_LIST_TAIL_BAND_1_MAC_LIST_TAIL_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BAU_MAC_LIST_TAIL_BAND_1_MAC_LIST_TAIL_LSB    0
#define BMU_BAU_MAC_LIST_TAIL_BAND_1_MAC_LIST_TAIL_WIDTH    ((uint32_t)0x00000020)

#define BMU_BAU_MAC_LIST_TAIL_BAND_1_MAC_LIST_TAIL_RST    0x0

__INLINE uint32_t bmu_bau_mac_list_tail_band_1_mac_list_tail_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_MAC_LIST_TAIL_BAND_1_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BAU_FREE_LIST_0_HEAD_ADDRESS_INIT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 FREE_LIST_HEAD_ADDR       0x0
 * </pre>
 */
#define BMU_BAU_FREE_LIST_0_HEAD_ADDRESS_INIT_ADDR        (REG_BMU_BASE_ADDR+0x00000830)
#define BMU_BAU_FREE_LIST_0_HEAD_ADDRESS_INIT_OFFSET      0x00000830
#define BMU_BAU_FREE_LIST_0_HEAD_ADDRESS_INIT_INDEX       0x0000020C
#define BMU_BAU_FREE_LIST_0_HEAD_ADDRESS_INIT_RESET       0x00000000

__INLINE void bmu_bau_free_list_0_head_address_init_set(uint32_t value)
{
	REG_PL_WR(BMU_BAU_FREE_LIST_0_HEAD_ADDRESS_INIT_ADDR, value);
}

// field definitions
#define BMU_BAU_FREE_LIST_0_HEAD_ADDRESS_INIT_FREE_LIST_HEAD_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BAU_FREE_LIST_0_HEAD_ADDRESS_INIT_FREE_LIST_HEAD_ADDR_LSB    0
#define BMU_BAU_FREE_LIST_0_HEAD_ADDRESS_INIT_FREE_LIST_HEAD_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BMU_BAU_FREE_LIST_0_HEAD_ADDRESS_INIT_FREE_LIST_HEAD_ADDR_RST    0x0

__INLINE void bmu_bau_free_list_0_head_address_init_free_list_head_addr_setf(uint32_t freelistheadaddr)
{
	ASSERT_ERR((((uint32_t)freelistheadaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BAU_FREE_LIST_0_HEAD_ADDRESS_INIT_ADDR, (uint32_t)freelistheadaddr << 0);
}

/**
 * @brief BAU_FREE_LIST_1_HEAD_ADDRESS_INIT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 FREE_LIST_HEAD_ADDR       0x0
 * </pre>
 */
#define BMU_BAU_FREE_LIST_1_HEAD_ADDRESS_INIT_ADDR        (REG_BMU_BASE_ADDR+0x00000834)
#define BMU_BAU_FREE_LIST_1_HEAD_ADDRESS_INIT_OFFSET      0x00000834
#define BMU_BAU_FREE_LIST_1_HEAD_ADDRESS_INIT_INDEX       0x0000020D
#define BMU_BAU_FREE_LIST_1_HEAD_ADDRESS_INIT_RESET       0x00000000

__INLINE void bmu_bau_free_list_1_head_address_init_set(uint32_t value)
{
	REG_PL_WR(BMU_BAU_FREE_LIST_1_HEAD_ADDRESS_INIT_ADDR, value);
}

// field definitions
#define BMU_BAU_FREE_LIST_1_HEAD_ADDRESS_INIT_FREE_LIST_HEAD_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BAU_FREE_LIST_1_HEAD_ADDRESS_INIT_FREE_LIST_HEAD_ADDR_LSB    0
#define BMU_BAU_FREE_LIST_1_HEAD_ADDRESS_INIT_FREE_LIST_HEAD_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BMU_BAU_FREE_LIST_1_HEAD_ADDRESS_INIT_FREE_LIST_HEAD_ADDR_RST    0x0

__INLINE void bmu_bau_free_list_1_head_address_init_free_list_head_addr_setf(uint32_t freelistheadaddr)
{
	ASSERT_ERR((((uint32_t)freelistheadaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BAU_FREE_LIST_1_HEAD_ADDRESS_INIT_ADDR, (uint32_t)freelistheadaddr << 0);
}

/**
 * @brief BAU_FREE_LIST_2_HEAD_ADDRESS_INIT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 FREE_LIST_HEAD_ADDR       0x0
 * </pre>
 */
#define BMU_BAU_FREE_LIST_2_HEAD_ADDRESS_INIT_ADDR        (REG_BMU_BASE_ADDR+0x00000838)
#define BMU_BAU_FREE_LIST_2_HEAD_ADDRESS_INIT_OFFSET      0x00000838
#define BMU_BAU_FREE_LIST_2_HEAD_ADDRESS_INIT_INDEX       0x0000020E
#define BMU_BAU_FREE_LIST_2_HEAD_ADDRESS_INIT_RESET       0x00000000

__INLINE void bmu_bau_free_list_2_head_address_init_set(uint32_t value)
{
	REG_PL_WR(BMU_BAU_FREE_LIST_2_HEAD_ADDRESS_INIT_ADDR, value);
}

// field definitions
#define BMU_BAU_FREE_LIST_2_HEAD_ADDRESS_INIT_FREE_LIST_HEAD_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BAU_FREE_LIST_2_HEAD_ADDRESS_INIT_FREE_LIST_HEAD_ADDR_LSB    0
#define BMU_BAU_FREE_LIST_2_HEAD_ADDRESS_INIT_FREE_LIST_HEAD_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BMU_BAU_FREE_LIST_2_HEAD_ADDRESS_INIT_FREE_LIST_HEAD_ADDR_RST    0x0

__INLINE void bmu_bau_free_list_2_head_address_init_free_list_head_addr_setf(uint32_t freelistheadaddr)
{
	ASSERT_ERR((((uint32_t)freelistheadaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BAU_FREE_LIST_2_HEAD_ADDRESS_INIT_ADDR, (uint32_t)freelistheadaddr << 0);
}

/**
 * @brief BAU_FREE_LIST_3_HEAD_ADDRESS_INIT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 FREE_LIST_HEAD_ADDR       0x0
 * </pre>
 */
#define BMU_BAU_FREE_LIST_3_HEAD_ADDRESS_INIT_ADDR        (REG_BMU_BASE_ADDR+0x0000083C)
#define BMU_BAU_FREE_LIST_3_HEAD_ADDRESS_INIT_OFFSET      0x0000083C
#define BMU_BAU_FREE_LIST_3_HEAD_ADDRESS_INIT_INDEX       0x0000020F
#define BMU_BAU_FREE_LIST_3_HEAD_ADDRESS_INIT_RESET       0x00000000

__INLINE void bmu_bau_free_list_3_head_address_init_set(uint32_t value)
{
	REG_PL_WR(BMU_BAU_FREE_LIST_3_HEAD_ADDRESS_INIT_ADDR, value);
}

// field definitions
#define BMU_BAU_FREE_LIST_3_HEAD_ADDRESS_INIT_FREE_LIST_HEAD_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BAU_FREE_LIST_3_HEAD_ADDRESS_INIT_FREE_LIST_HEAD_ADDR_LSB    0
#define BMU_BAU_FREE_LIST_3_HEAD_ADDRESS_INIT_FREE_LIST_HEAD_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BMU_BAU_FREE_LIST_3_HEAD_ADDRESS_INIT_FREE_LIST_HEAD_ADDR_RST    0x0

__INLINE void bmu_bau_free_list_3_head_address_init_free_list_head_addr_setf(uint32_t freelistheadaddr)
{
	ASSERT_ERR((((uint32_t)freelistheadaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BAU_FREE_LIST_3_HEAD_ADDRESS_INIT_ADDR, (uint32_t)freelistheadaddr << 0);
}

/**
 * @brief BAU_FREE_LIST_4_HEAD_ADDRESS_INIT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 FREE_LIST_HEAD_ADDR       0x0
 * </pre>
 */
#define BMU_BAU_FREE_LIST_4_HEAD_ADDRESS_INIT_ADDR        (REG_BMU_BASE_ADDR+0x00000840)
#define BMU_BAU_FREE_LIST_4_HEAD_ADDRESS_INIT_OFFSET      0x00000840
#define BMU_BAU_FREE_LIST_4_HEAD_ADDRESS_INIT_INDEX       0x00000210
#define BMU_BAU_FREE_LIST_4_HEAD_ADDRESS_INIT_RESET       0x00000000

__INLINE void bmu_bau_free_list_4_head_address_init_set(uint32_t value)
{
	REG_PL_WR(BMU_BAU_FREE_LIST_4_HEAD_ADDRESS_INIT_ADDR, value);
}

// field definitions
#define BMU_BAU_FREE_LIST_4_HEAD_ADDRESS_INIT_FREE_LIST_HEAD_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BAU_FREE_LIST_4_HEAD_ADDRESS_INIT_FREE_LIST_HEAD_ADDR_LSB    0
#define BMU_BAU_FREE_LIST_4_HEAD_ADDRESS_INIT_FREE_LIST_HEAD_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BMU_BAU_FREE_LIST_4_HEAD_ADDRESS_INIT_FREE_LIST_HEAD_ADDR_RST    0x0

__INLINE void bmu_bau_free_list_4_head_address_init_free_list_head_addr_setf(uint32_t freelistheadaddr)
{
	ASSERT_ERR((((uint32_t)freelistheadaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BAU_FREE_LIST_4_HEAD_ADDRESS_INIT_ADDR, (uint32_t)freelistheadaddr << 0);
}

/**
 * @brief BAU_FREE_LIST_5_HEAD_ADDRESS_INIT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 FREE_LIST_HEAD_ADDR       0x0
 * </pre>
 */
#define BMU_BAU_FREE_LIST_5_HEAD_ADDRESS_INIT_ADDR        (REG_BMU_BASE_ADDR+0x00000844)
#define BMU_BAU_FREE_LIST_5_HEAD_ADDRESS_INIT_OFFSET      0x00000844
#define BMU_BAU_FREE_LIST_5_HEAD_ADDRESS_INIT_INDEX       0x00000211
#define BMU_BAU_FREE_LIST_5_HEAD_ADDRESS_INIT_RESET       0x00000000

__INLINE void bmu_bau_free_list_5_head_address_init_set(uint32_t value)
{
	REG_PL_WR(BMU_BAU_FREE_LIST_5_HEAD_ADDRESS_INIT_ADDR, value);
}

// field definitions
#define BMU_BAU_FREE_LIST_5_HEAD_ADDRESS_INIT_FREE_LIST_HEAD_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BAU_FREE_LIST_5_HEAD_ADDRESS_INIT_FREE_LIST_HEAD_ADDR_LSB    0
#define BMU_BAU_FREE_LIST_5_HEAD_ADDRESS_INIT_FREE_LIST_HEAD_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BMU_BAU_FREE_LIST_5_HEAD_ADDRESS_INIT_FREE_LIST_HEAD_ADDR_RST    0x0

__INLINE void bmu_bau_free_list_5_head_address_init_free_list_head_addr_setf(uint32_t freelistheadaddr)
{
	ASSERT_ERR((((uint32_t)freelistheadaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BAU_FREE_LIST_5_HEAD_ADDRESS_INIT_ADDR, (uint32_t)freelistheadaddr << 0);
}

/**
 * @brief BAU_FREE_LIST_6_HEAD_ADDRESS_INIT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 FREE_LIST_HEAD_ADDR       0x0
 * </pre>
 */
#define BMU_BAU_FREE_LIST_6_HEAD_ADDRESS_INIT_ADDR        (REG_BMU_BASE_ADDR+0x00000848)
#define BMU_BAU_FREE_LIST_6_HEAD_ADDRESS_INIT_OFFSET      0x00000848
#define BMU_BAU_FREE_LIST_6_HEAD_ADDRESS_INIT_INDEX       0x00000212
#define BMU_BAU_FREE_LIST_6_HEAD_ADDRESS_INIT_RESET       0x00000000

__INLINE void bmu_bau_free_list_6_head_address_init_set(uint32_t value)
{
	REG_PL_WR(BMU_BAU_FREE_LIST_6_HEAD_ADDRESS_INIT_ADDR, value);
}

// field definitions
#define BMU_BAU_FREE_LIST_6_HEAD_ADDRESS_INIT_FREE_LIST_HEAD_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BAU_FREE_LIST_6_HEAD_ADDRESS_INIT_FREE_LIST_HEAD_ADDR_LSB    0
#define BMU_BAU_FREE_LIST_6_HEAD_ADDRESS_INIT_FREE_LIST_HEAD_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BMU_BAU_FREE_LIST_6_HEAD_ADDRESS_INIT_FREE_LIST_HEAD_ADDR_RST    0x0

__INLINE void bmu_bau_free_list_6_head_address_init_free_list_head_addr_setf(uint32_t freelistheadaddr)
{
	ASSERT_ERR((((uint32_t)freelistheadaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BAU_FREE_LIST_6_HEAD_ADDRESS_INIT_ADDR, (uint32_t)freelistheadaddr << 0);
}

/**
 * @brief BAU_FREE_LIST_7_HEAD_ADDRESS_INIT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 FREE_LIST_HEAD_ADDR       0x0
 * </pre>
 */
#define BMU_BAU_FREE_LIST_7_HEAD_ADDRESS_INIT_ADDR        (REG_BMU_BASE_ADDR+0x0000084C)
#define BMU_BAU_FREE_LIST_7_HEAD_ADDRESS_INIT_OFFSET      0x0000084C
#define BMU_BAU_FREE_LIST_7_HEAD_ADDRESS_INIT_INDEX       0x00000213
#define BMU_BAU_FREE_LIST_7_HEAD_ADDRESS_INIT_RESET       0x00000000

__INLINE void bmu_bau_free_list_7_head_address_init_set(uint32_t value)
{
	REG_PL_WR(BMU_BAU_FREE_LIST_7_HEAD_ADDRESS_INIT_ADDR, value);
}

// field definitions
#define BMU_BAU_FREE_LIST_7_HEAD_ADDRESS_INIT_FREE_LIST_HEAD_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BAU_FREE_LIST_7_HEAD_ADDRESS_INIT_FREE_LIST_HEAD_ADDR_LSB    0
#define BMU_BAU_FREE_LIST_7_HEAD_ADDRESS_INIT_FREE_LIST_HEAD_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BMU_BAU_FREE_LIST_7_HEAD_ADDRESS_INIT_FREE_LIST_HEAD_ADDR_RST    0x0

__INLINE void bmu_bau_free_list_7_head_address_init_free_list_head_addr_setf(uint32_t freelistheadaddr)
{
	ASSERT_ERR((((uint32_t)freelistheadaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BAU_FREE_LIST_7_HEAD_ADDRESS_INIT_ADDR, (uint32_t)freelistheadaddr << 0);
}

/**
 * @brief BAU_FREE_LIST_0_HEAD_ADDRESS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 FREE_LIST_HEAD_ADDR       0x0
 * </pre>
 */
#define BMU_BAU_FREE_LIST_0_HEAD_ADDRESS_ADDR        (REG_BMU_BASE_ADDR+0x00000870)
#define BMU_BAU_FREE_LIST_0_HEAD_ADDRESS_OFFSET      0x00000870
#define BMU_BAU_FREE_LIST_0_HEAD_ADDRESS_INDEX       0x0000021C
#define BMU_BAU_FREE_LIST_0_HEAD_ADDRESS_RESET       0x00000000

__INLINE uint32_t  bmu_bau_free_list_0_head_address_get(void)
{
	return REG_PL_RD(BMU_BAU_FREE_LIST_0_HEAD_ADDRESS_ADDR);
}

// field definitions
#define BMU_BAU_FREE_LIST_0_HEAD_ADDRESS_FREE_LIST_HEAD_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BAU_FREE_LIST_0_HEAD_ADDRESS_FREE_LIST_HEAD_ADDR_LSB    0
#define BMU_BAU_FREE_LIST_0_HEAD_ADDRESS_FREE_LIST_HEAD_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BMU_BAU_FREE_LIST_0_HEAD_ADDRESS_FREE_LIST_HEAD_ADDR_RST    0x0

__INLINE uint32_t bmu_bau_free_list_0_head_address_free_list_head_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_FREE_LIST_0_HEAD_ADDRESS_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BAU_FREE_LIST_1_HEAD_ADDRESS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 FREE_LIST_HEAD_ADDR       0x0
 * </pre>
 */
#define BMU_BAU_FREE_LIST_1_HEAD_ADDRESS_ADDR        (REG_BMU_BASE_ADDR+0x00000874)
#define BMU_BAU_FREE_LIST_1_HEAD_ADDRESS_OFFSET      0x00000874
#define BMU_BAU_FREE_LIST_1_HEAD_ADDRESS_INDEX       0x0000021D
#define BMU_BAU_FREE_LIST_1_HEAD_ADDRESS_RESET       0x00000000

__INLINE uint32_t  bmu_bau_free_list_1_head_address_get(void)
{
	return REG_PL_RD(BMU_BAU_FREE_LIST_1_HEAD_ADDRESS_ADDR);
}

// field definitions
#define BMU_BAU_FREE_LIST_1_HEAD_ADDRESS_FREE_LIST_HEAD_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BAU_FREE_LIST_1_HEAD_ADDRESS_FREE_LIST_HEAD_ADDR_LSB    0
#define BMU_BAU_FREE_LIST_1_HEAD_ADDRESS_FREE_LIST_HEAD_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BMU_BAU_FREE_LIST_1_HEAD_ADDRESS_FREE_LIST_HEAD_ADDR_RST    0x0

__INLINE uint32_t bmu_bau_free_list_1_head_address_free_list_head_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_FREE_LIST_1_HEAD_ADDRESS_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BAU_FREE_LIST_2_HEAD_ADDRESS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 FREE_LIST_HEAD_ADDR       0x0
 * </pre>
 */
#define BMU_BAU_FREE_LIST_2_HEAD_ADDRESS_ADDR        (REG_BMU_BASE_ADDR+0x00000878)
#define BMU_BAU_FREE_LIST_2_HEAD_ADDRESS_OFFSET      0x00000878
#define BMU_BAU_FREE_LIST_2_HEAD_ADDRESS_INDEX       0x0000021E
#define BMU_BAU_FREE_LIST_2_HEAD_ADDRESS_RESET       0x00000000

__INLINE uint32_t  bmu_bau_free_list_2_head_address_get(void)
{
	return REG_PL_RD(BMU_BAU_FREE_LIST_2_HEAD_ADDRESS_ADDR);
}

// field definitions
#define BMU_BAU_FREE_LIST_2_HEAD_ADDRESS_FREE_LIST_HEAD_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BAU_FREE_LIST_2_HEAD_ADDRESS_FREE_LIST_HEAD_ADDR_LSB    0
#define BMU_BAU_FREE_LIST_2_HEAD_ADDRESS_FREE_LIST_HEAD_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BMU_BAU_FREE_LIST_2_HEAD_ADDRESS_FREE_LIST_HEAD_ADDR_RST    0x0

__INLINE uint32_t bmu_bau_free_list_2_head_address_free_list_head_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_FREE_LIST_2_HEAD_ADDRESS_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BAU_FREE_LIST_3_HEAD_ADDRESS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 FREE_LIST_HEAD_ADDR       0x0
 * </pre>
 */
#define BMU_BAU_FREE_LIST_3_HEAD_ADDRESS_ADDR        (REG_BMU_BASE_ADDR+0x0000087C)
#define BMU_BAU_FREE_LIST_3_HEAD_ADDRESS_OFFSET      0x0000087C
#define BMU_BAU_FREE_LIST_3_HEAD_ADDRESS_INDEX       0x0000021F
#define BMU_BAU_FREE_LIST_3_HEAD_ADDRESS_RESET       0x00000000

__INLINE uint32_t  bmu_bau_free_list_3_head_address_get(void)
{
	return REG_PL_RD(BMU_BAU_FREE_LIST_3_HEAD_ADDRESS_ADDR);
}

// field definitions
#define BMU_BAU_FREE_LIST_3_HEAD_ADDRESS_FREE_LIST_HEAD_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BAU_FREE_LIST_3_HEAD_ADDRESS_FREE_LIST_HEAD_ADDR_LSB    0
#define BMU_BAU_FREE_LIST_3_HEAD_ADDRESS_FREE_LIST_HEAD_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BMU_BAU_FREE_LIST_3_HEAD_ADDRESS_FREE_LIST_HEAD_ADDR_RST    0x0

__INLINE uint32_t bmu_bau_free_list_3_head_address_free_list_head_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_FREE_LIST_3_HEAD_ADDRESS_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BAU_FREE_LIST_4_HEAD_ADDRESS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 FREE_LIST_HEAD_ADDR       0x0
 * </pre>
 */
#define BMU_BAU_FREE_LIST_4_HEAD_ADDRESS_ADDR        (REG_BMU_BASE_ADDR+0x00000880)
#define BMU_BAU_FREE_LIST_4_HEAD_ADDRESS_OFFSET      0x00000880
#define BMU_BAU_FREE_LIST_4_HEAD_ADDRESS_INDEX       0x00000220
#define BMU_BAU_FREE_LIST_4_HEAD_ADDRESS_RESET       0x00000000

__INLINE uint32_t  bmu_bau_free_list_4_head_address_get(void)
{
	return REG_PL_RD(BMU_BAU_FREE_LIST_4_HEAD_ADDRESS_ADDR);
}

// field definitions
#define BMU_BAU_FREE_LIST_4_HEAD_ADDRESS_FREE_LIST_HEAD_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BAU_FREE_LIST_4_HEAD_ADDRESS_FREE_LIST_HEAD_ADDR_LSB    0
#define BMU_BAU_FREE_LIST_4_HEAD_ADDRESS_FREE_LIST_HEAD_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BMU_BAU_FREE_LIST_4_HEAD_ADDRESS_FREE_LIST_HEAD_ADDR_RST    0x0

__INLINE uint32_t bmu_bau_free_list_4_head_address_free_list_head_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_FREE_LIST_4_HEAD_ADDRESS_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BAU_FREE_LIST_5_HEAD_ADDRESS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 FREE_LIST_HEAD_ADDR       0x0
 * </pre>
 */
#define BMU_BAU_FREE_LIST_5_HEAD_ADDRESS_ADDR        (REG_BMU_BASE_ADDR+0x00000884)
#define BMU_BAU_FREE_LIST_5_HEAD_ADDRESS_OFFSET      0x00000884
#define BMU_BAU_FREE_LIST_5_HEAD_ADDRESS_INDEX       0x00000221
#define BMU_BAU_FREE_LIST_5_HEAD_ADDRESS_RESET       0x00000000

__INLINE uint32_t  bmu_bau_free_list_5_head_address_get(void)
{
	return REG_PL_RD(BMU_BAU_FREE_LIST_5_HEAD_ADDRESS_ADDR);
}

// field definitions
#define BMU_BAU_FREE_LIST_5_HEAD_ADDRESS_FREE_LIST_HEAD_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BAU_FREE_LIST_5_HEAD_ADDRESS_FREE_LIST_HEAD_ADDR_LSB    0
#define BMU_BAU_FREE_LIST_5_HEAD_ADDRESS_FREE_LIST_HEAD_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BMU_BAU_FREE_LIST_5_HEAD_ADDRESS_FREE_LIST_HEAD_ADDR_RST    0x0

__INLINE uint32_t bmu_bau_free_list_5_head_address_free_list_head_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_FREE_LIST_5_HEAD_ADDRESS_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BAU_FREE_LIST_6_HEAD_ADDRESS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 FREE_LIST_HEAD_ADDR       0x0
 * </pre>
 */
#define BMU_BAU_FREE_LIST_6_HEAD_ADDRESS_ADDR        (REG_BMU_BASE_ADDR+0x00000888)
#define BMU_BAU_FREE_LIST_6_HEAD_ADDRESS_OFFSET      0x00000888
#define BMU_BAU_FREE_LIST_6_HEAD_ADDRESS_INDEX       0x00000222
#define BMU_BAU_FREE_LIST_6_HEAD_ADDRESS_RESET       0x00000000

__INLINE uint32_t  bmu_bau_free_list_6_head_address_get(void)
{
	return REG_PL_RD(BMU_BAU_FREE_LIST_6_HEAD_ADDRESS_ADDR);
}

// field definitions
#define BMU_BAU_FREE_LIST_6_HEAD_ADDRESS_FREE_LIST_HEAD_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BAU_FREE_LIST_6_HEAD_ADDRESS_FREE_LIST_HEAD_ADDR_LSB    0
#define BMU_BAU_FREE_LIST_6_HEAD_ADDRESS_FREE_LIST_HEAD_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BMU_BAU_FREE_LIST_6_HEAD_ADDRESS_FREE_LIST_HEAD_ADDR_RST    0x0

__INLINE uint32_t bmu_bau_free_list_6_head_address_free_list_head_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_FREE_LIST_6_HEAD_ADDRESS_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BAU_FREE_LIST_7_HEAD_ADDRESS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 FREE_LIST_HEAD_ADDR       0x0
 * </pre>
 */
#define BMU_BAU_FREE_LIST_7_HEAD_ADDRESS_ADDR        (REG_BMU_BASE_ADDR+0x0000088C)
#define BMU_BAU_FREE_LIST_7_HEAD_ADDRESS_OFFSET      0x0000088C
#define BMU_BAU_FREE_LIST_7_HEAD_ADDRESS_INDEX       0x00000223
#define BMU_BAU_FREE_LIST_7_HEAD_ADDRESS_RESET       0x00000000

__INLINE uint32_t  bmu_bau_free_list_7_head_address_get(void)
{
	return REG_PL_RD(BMU_BAU_FREE_LIST_7_HEAD_ADDRESS_ADDR);
}

// field definitions
#define BMU_BAU_FREE_LIST_7_HEAD_ADDRESS_FREE_LIST_HEAD_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BAU_FREE_LIST_7_HEAD_ADDRESS_FREE_LIST_HEAD_ADDR_LSB    0
#define BMU_BAU_FREE_LIST_7_HEAD_ADDRESS_FREE_LIST_HEAD_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BMU_BAU_FREE_LIST_7_HEAD_ADDRESS_FREE_LIST_HEAD_ADDR_RST    0x0

__INLINE uint32_t bmu_bau_free_list_7_head_address_free_list_head_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_FREE_LIST_7_HEAD_ADDRESS_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BAU_RPD_DATA_OFFSET register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RPD_DATA_OFFSET           0x0
 * </pre>
 */
#define BMU_BAU_RPD_DATA_OFFSET_ADDR        (REG_BMU_BASE_ADDR+0x000008B0)
#define BMU_BAU_RPD_DATA_OFFSET_OFFSET      0x000008B0
#define BMU_BAU_RPD_DATA_OFFSET_INDEX       0x0000022C
#define BMU_BAU_RPD_DATA_OFFSET_RESET       0x00000000

__INLINE uint32_t  bmu_bau_rpd_data_offset_get(void)
{
	return REG_PL_RD(BMU_BAU_RPD_DATA_OFFSET_ADDR);
}

__INLINE void bmu_bau_rpd_data_offset_set(uint32_t value)
{
	REG_PL_WR(BMU_BAU_RPD_DATA_OFFSET_ADDR, value);
}

// field definitions
#define BMU_BAU_RPD_DATA_OFFSET_RPD_DATA_OFFSET_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BAU_RPD_DATA_OFFSET_RPD_DATA_OFFSET_LSB    0
#define BMU_BAU_RPD_DATA_OFFSET_RPD_DATA_OFFSET_WIDTH    ((uint32_t)0x00000020)

#define BMU_BAU_RPD_DATA_OFFSET_RPD_DATA_OFFSET_RST    0x0

__INLINE uint32_t bmu_bau_rpd_data_offset_rpd_data_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_RPD_DATA_OFFSET_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bmu_bau_rpd_data_offset_rpd_data_offset_setf(uint32_t rpddataoffset)
{
	ASSERT_ERR((((uint32_t)rpddataoffset << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BAU_RPD_DATA_OFFSET_ADDR, (uint32_t)rpddataoffset << 0);
}

/**
 * @brief BAU_RHD_SPARE_OFFSET register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RHD_SPARE_OFFSET          0x0
 * </pre>
 */
#define BMU_BAU_RHD_SPARE_OFFSET_ADDR        (REG_BMU_BASE_ADDR+0x000008B4)
#define BMU_BAU_RHD_SPARE_OFFSET_OFFSET      0x000008B4
#define BMU_BAU_RHD_SPARE_OFFSET_INDEX       0x0000022D
#define BMU_BAU_RHD_SPARE_OFFSET_RESET       0x00000000

__INLINE uint32_t  bmu_bau_rhd_spare_offset_get(void)
{
	return REG_PL_RD(BMU_BAU_RHD_SPARE_OFFSET_ADDR);
}

__INLINE void bmu_bau_rhd_spare_offset_set(uint32_t value)
{
	REG_PL_WR(BMU_BAU_RHD_SPARE_OFFSET_ADDR, value);
}

// field definitions
#define BMU_BAU_RHD_SPARE_OFFSET_RHD_SPARE_OFFSET_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BAU_RHD_SPARE_OFFSET_RHD_SPARE_OFFSET_LSB    0
#define BMU_BAU_RHD_SPARE_OFFSET_RHD_SPARE_OFFSET_WIDTH    ((uint32_t)0x00000020)

#define BMU_BAU_RHD_SPARE_OFFSET_RHD_SPARE_OFFSET_RST    0x0

__INLINE uint32_t bmu_bau_rhd_spare_offset_rhd_spare_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_RHD_SPARE_OFFSET_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bmu_bau_rhd_spare_offset_rhd_spare_offset_setf(uint32_t rhdspareoffset)
{
	ASSERT_ERR((((uint32_t)rhdspareoffset << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BAU_RHD_SPARE_OFFSET_ADDR, (uint32_t)rhdspareoffset << 0);
}

/**
 * @brief BAU_RPD_SPARE_OFFSET register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RPD_SPARE_OFFSET          0x0
 * </pre>
 */
#define BMU_BAU_RPD_SPARE_OFFSET_ADDR        (REG_BMU_BASE_ADDR+0x000008B8)
#define BMU_BAU_RPD_SPARE_OFFSET_OFFSET      0x000008B8
#define BMU_BAU_RPD_SPARE_OFFSET_INDEX       0x0000022E
#define BMU_BAU_RPD_SPARE_OFFSET_RESET       0x00000000

__INLINE uint32_t  bmu_bau_rpd_spare_offset_get(void)
{
	return REG_PL_RD(BMU_BAU_RPD_SPARE_OFFSET_ADDR);
}

__INLINE void bmu_bau_rpd_spare_offset_set(uint32_t value)
{
	REG_PL_WR(BMU_BAU_RPD_SPARE_OFFSET_ADDR, value);
}

// field definitions
#define BMU_BAU_RPD_SPARE_OFFSET_RPD_SPARE_OFFSET_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BAU_RPD_SPARE_OFFSET_RPD_SPARE_OFFSET_LSB    0
#define BMU_BAU_RPD_SPARE_OFFSET_RPD_SPARE_OFFSET_WIDTH    ((uint32_t)0x00000020)

#define BMU_BAU_RPD_SPARE_OFFSET_RPD_SPARE_OFFSET_RST    0x0

__INLINE uint32_t bmu_bau_rpd_spare_offset_rpd_spare_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_RPD_SPARE_OFFSET_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bmu_bau_rpd_spare_offset_rpd_spare_offset_setf(uint32_t rpdspareoffset)
{
	ASSERT_ERR((((uint32_t)rpdspareoffset << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BMU_BAU_RPD_SPARE_OFFSET_ADDR, (uint32_t)rpdspareoffset << 0);
}

/**
 * @brief BAU_RHD_SPARE_POSITION register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    04:00 RHD_SPARE_POS             0x0
 * </pre>
 */
#define BMU_BAU_RHD_SPARE_POSITION_ADDR        (REG_BMU_BASE_ADDR+0x000008BC)
#define BMU_BAU_RHD_SPARE_POSITION_OFFSET      0x000008BC
#define BMU_BAU_RHD_SPARE_POSITION_INDEX       0x0000022F
#define BMU_BAU_RHD_SPARE_POSITION_RESET       0x00000000

__INLINE uint32_t  bmu_bau_rhd_spare_position_get(void)
{
	return REG_PL_RD(BMU_BAU_RHD_SPARE_POSITION_ADDR);
}

__INLINE void bmu_bau_rhd_spare_position_set(uint32_t value)
{
	REG_PL_WR(BMU_BAU_RHD_SPARE_POSITION_ADDR, value);
}

// field definitions
#define BMU_BAU_RHD_SPARE_POSITION_RHD_SPARE_POS_MASK    ((uint32_t)0x0000001F)
#define BMU_BAU_RHD_SPARE_POSITION_RHD_SPARE_POS_LSB    0
#define BMU_BAU_RHD_SPARE_POSITION_RHD_SPARE_POS_WIDTH    ((uint32_t)0x00000005)

#define BMU_BAU_RHD_SPARE_POSITION_RHD_SPARE_POS_RST    0x0

__INLINE uint8_t bmu_bau_rhd_spare_position_rhd_spare_pos_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_RHD_SPARE_POSITION_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void bmu_bau_rhd_spare_position_rhd_spare_pos_setf(uint8_t rhdsparepos)
{
	ASSERT_ERR((((uint32_t)rhdsparepos << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(BMU_BAU_RHD_SPARE_POSITION_ADDR, (uint32_t)rhdsparepos << 0);
}

/**
 * @brief BAU_RPD_SPARE_POSITION register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    04:00 RPD_SPARE_POS             0x0
 * </pre>
 */
#define BMU_BAU_RPD_SPARE_POSITION_ADDR        (REG_BMU_BASE_ADDR+0x000008C0)
#define BMU_BAU_RPD_SPARE_POSITION_OFFSET      0x000008C0
#define BMU_BAU_RPD_SPARE_POSITION_INDEX       0x00000230
#define BMU_BAU_RPD_SPARE_POSITION_RESET       0x00000000

__INLINE uint32_t  bmu_bau_rpd_spare_position_get(void)
{
	return REG_PL_RD(BMU_BAU_RPD_SPARE_POSITION_ADDR);
}

__INLINE void bmu_bau_rpd_spare_position_set(uint32_t value)
{
	REG_PL_WR(BMU_BAU_RPD_SPARE_POSITION_ADDR, value);
}

// field definitions
#define BMU_BAU_RPD_SPARE_POSITION_RPD_SPARE_POS_MASK    ((uint32_t)0x0000001F)
#define BMU_BAU_RPD_SPARE_POSITION_RPD_SPARE_POS_LSB    0
#define BMU_BAU_RPD_SPARE_POSITION_RPD_SPARE_POS_WIDTH    ((uint32_t)0x00000005)

#define BMU_BAU_RPD_SPARE_POSITION_RPD_SPARE_POS_RST    0x0

__INLINE uint8_t bmu_bau_rpd_spare_position_rpd_spare_pos_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_RPD_SPARE_POSITION_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void bmu_bau_rpd_spare_position_rpd_spare_pos_setf(uint8_t rpdsparepos)
{
	ASSERT_ERR((((uint32_t)rpdsparepos << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(BMU_BAU_RPD_SPARE_POSITION_ADDR, (uint32_t)rpdsparepos << 0);
}

/**
 * @brief BAU_RPD_0_DATA_SIZE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 RPD_DATA_SIZE             0x0
 * </pre>
 */
#define BMU_BAU_RPD_0_DATA_SIZE_ADDR        (REG_BMU_BASE_ADDR+0x000008C4)
#define BMU_BAU_RPD_0_DATA_SIZE_OFFSET      0x000008C4
#define BMU_BAU_RPD_0_DATA_SIZE_INDEX       0x00000231
#define BMU_BAU_RPD_0_DATA_SIZE_RESET       0x00000000

__INLINE uint32_t  bmu_bau_rpd_0_data_size_get(void)
{
	return REG_PL_RD(BMU_BAU_RPD_0_DATA_SIZE_ADDR);
}

__INLINE void bmu_bau_rpd_0_data_size_set(uint32_t value)
{
	REG_PL_WR(BMU_BAU_RPD_0_DATA_SIZE_ADDR, value);
}

// field definitions
#define BMU_BAU_RPD_0_DATA_SIZE_RPD_DATA_SIZE_MASK    ((uint32_t)0x0000FFFF)
#define BMU_BAU_RPD_0_DATA_SIZE_RPD_DATA_SIZE_LSB    0
#define BMU_BAU_RPD_0_DATA_SIZE_RPD_DATA_SIZE_WIDTH    ((uint32_t)0x00000010)

#define BMU_BAU_RPD_0_DATA_SIZE_RPD_DATA_SIZE_RST    0x0

__INLINE uint16_t bmu_bau_rpd_0_data_size_rpd_data_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_RPD_0_DATA_SIZE_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void bmu_bau_rpd_0_data_size_rpd_data_size_setf(uint16_t rpddatasize)
{
	ASSERT_ERR((((uint32_t)rpddatasize << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(BMU_BAU_RPD_0_DATA_SIZE_ADDR, (uint32_t)rpddatasize << 0);
}

/**
 * @brief BAU_RPD_1_DATA_SIZE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 RPD_DATA_SIZE             0x0
 * </pre>
 */
#define BMU_BAU_RPD_1_DATA_SIZE_ADDR        (REG_BMU_BASE_ADDR+0x000008C8)
#define BMU_BAU_RPD_1_DATA_SIZE_OFFSET      0x000008C8
#define BMU_BAU_RPD_1_DATA_SIZE_INDEX       0x00000232
#define BMU_BAU_RPD_1_DATA_SIZE_RESET       0x00000000

__INLINE uint32_t  bmu_bau_rpd_1_data_size_get(void)
{
	return REG_PL_RD(BMU_BAU_RPD_1_DATA_SIZE_ADDR);
}

__INLINE void bmu_bau_rpd_1_data_size_set(uint32_t value)
{
	REG_PL_WR(BMU_BAU_RPD_1_DATA_SIZE_ADDR, value);
}

// field definitions
#define BMU_BAU_RPD_1_DATA_SIZE_RPD_DATA_SIZE_MASK    ((uint32_t)0x0000FFFF)
#define BMU_BAU_RPD_1_DATA_SIZE_RPD_DATA_SIZE_LSB    0
#define BMU_BAU_RPD_1_DATA_SIZE_RPD_DATA_SIZE_WIDTH    ((uint32_t)0x00000010)

#define BMU_BAU_RPD_1_DATA_SIZE_RPD_DATA_SIZE_RST    0x0

__INLINE uint16_t bmu_bau_rpd_1_data_size_rpd_data_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_RPD_1_DATA_SIZE_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void bmu_bau_rpd_1_data_size_rpd_data_size_setf(uint16_t rpddatasize)
{
	ASSERT_ERR((((uint32_t)rpddatasize << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(BMU_BAU_RPD_1_DATA_SIZE_ADDR, (uint32_t)rpddatasize << 0);
}

/**
 * @brief BAU_RPD_2_DATA_SIZE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 RPD_DATA_SIZE             0x0
 * </pre>
 */
#define BMU_BAU_RPD_2_DATA_SIZE_ADDR        (REG_BMU_BASE_ADDR+0x000008CC)
#define BMU_BAU_RPD_2_DATA_SIZE_OFFSET      0x000008CC
#define BMU_BAU_RPD_2_DATA_SIZE_INDEX       0x00000233
#define BMU_BAU_RPD_2_DATA_SIZE_RESET       0x00000000

__INLINE uint32_t  bmu_bau_rpd_2_data_size_get(void)
{
	return REG_PL_RD(BMU_BAU_RPD_2_DATA_SIZE_ADDR);
}

__INLINE void bmu_bau_rpd_2_data_size_set(uint32_t value)
{
	REG_PL_WR(BMU_BAU_RPD_2_DATA_SIZE_ADDR, value);
}

// field definitions
#define BMU_BAU_RPD_2_DATA_SIZE_RPD_DATA_SIZE_MASK    ((uint32_t)0x0000FFFF)
#define BMU_BAU_RPD_2_DATA_SIZE_RPD_DATA_SIZE_LSB    0
#define BMU_BAU_RPD_2_DATA_SIZE_RPD_DATA_SIZE_WIDTH    ((uint32_t)0x00000010)

#define BMU_BAU_RPD_2_DATA_SIZE_RPD_DATA_SIZE_RST    0x0

__INLINE uint16_t bmu_bau_rpd_2_data_size_rpd_data_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_RPD_2_DATA_SIZE_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void bmu_bau_rpd_2_data_size_rpd_data_size_setf(uint16_t rpddatasize)
{
	ASSERT_ERR((((uint32_t)rpddatasize << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(BMU_BAU_RPD_2_DATA_SIZE_ADDR, (uint32_t)rpddatasize << 0);
}

/**
 * @brief BAU_RPD_3_DATA_SIZE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 RPD_DATA_SIZE             0x0
 * </pre>
 */
#define BMU_BAU_RPD_3_DATA_SIZE_ADDR        (REG_BMU_BASE_ADDR+0x000008D0)
#define BMU_BAU_RPD_3_DATA_SIZE_OFFSET      0x000008D0
#define BMU_BAU_RPD_3_DATA_SIZE_INDEX       0x00000234
#define BMU_BAU_RPD_3_DATA_SIZE_RESET       0x00000000

__INLINE uint32_t  bmu_bau_rpd_3_data_size_get(void)
{
	return REG_PL_RD(BMU_BAU_RPD_3_DATA_SIZE_ADDR);
}

__INLINE void bmu_bau_rpd_3_data_size_set(uint32_t value)
{
	REG_PL_WR(BMU_BAU_RPD_3_DATA_SIZE_ADDR, value);
}

// field definitions
#define BMU_BAU_RPD_3_DATA_SIZE_RPD_DATA_SIZE_MASK    ((uint32_t)0x0000FFFF)
#define BMU_BAU_RPD_3_DATA_SIZE_RPD_DATA_SIZE_LSB    0
#define BMU_BAU_RPD_3_DATA_SIZE_RPD_DATA_SIZE_WIDTH    ((uint32_t)0x00000010)

#define BMU_BAU_RPD_3_DATA_SIZE_RPD_DATA_SIZE_RST    0x0

__INLINE uint16_t bmu_bau_rpd_3_data_size_rpd_data_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_RPD_3_DATA_SIZE_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void bmu_bau_rpd_3_data_size_rpd_data_size_setf(uint16_t rpddatasize)
{
	ASSERT_ERR((((uint32_t)rpddatasize << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(BMU_BAU_RPD_3_DATA_SIZE_ADDR, (uint32_t)rpddatasize << 0);
}

/**
 * @brief BAU_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01    BAND1_BUSY                0              
 *    00    BAND0_BUSY                0              
 * </pre>
 */
#define BMU_BAU_STATUS_ADDR        (REG_BMU_BASE_ADDR+0x000008D4)
#define BMU_BAU_STATUS_OFFSET      0x000008D4
#define BMU_BAU_STATUS_INDEX       0x00000235
#define BMU_BAU_STATUS_RESET       0x00000000

__INLINE uint32_t  bmu_bau_status_get(void)
{
	return REG_PL_RD(BMU_BAU_STATUS_ADDR);
}

// field definitions
#define BMU_BAU_STATUS_BAND_1_BUSY_BIT      ((uint32_t)0x00000002)
#define BMU_BAU_STATUS_BAND_1_BUSY_POS      1
#define BMU_BAU_STATUS_BAND_0_BUSY_BIT      ((uint32_t)0x00000001)
#define BMU_BAU_STATUS_BAND_0_BUSY_POS      0

#define BMU_BAU_STATUS_BAND_1_BUSY_RST      0x0
#define BMU_BAU_STATUS_BAND_0_BUSY_RST      0x0

__INLINE void bmu_bau_status_unpack(uint8_t* band1_busy, uint8_t* band0_busy)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_STATUS_ADDR);

	*band1_busy = (localVal & ((uint32_t)0x00000002)) >>  1;
	*band0_busy = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t bmu_bau_status_band_1_busy_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t bmu_bau_status_band_0_busy_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief BAU_INT_RAW_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 PTRN_MTCH_ERROR           0x0
 *    15:00 AXI_ERROR                 0x0
 * </pre>
 */
#define BMU_BAU_INT_RAW_STATUS_ADDR        (REG_BMU_BASE_ADDR+0x000008D8)
#define BMU_BAU_INT_RAW_STATUS_OFFSET      0x000008D8
#define BMU_BAU_INT_RAW_STATUS_INDEX       0x00000236
#define BMU_BAU_INT_RAW_STATUS_RESET       0x00000000

__INLINE uint32_t  bmu_bau_int_raw_status_get(void)
{
	return REG_PL_RD(BMU_BAU_INT_RAW_STATUS_ADDR);
}

// field definitions
#define BMU_BAU_INT_RAW_STATUS_PTRN_MTCH_ERROR_MASK    ((uint32_t)0xFFFF0000)
#define BMU_BAU_INT_RAW_STATUS_PTRN_MTCH_ERROR_LSB    16
#define BMU_BAU_INT_RAW_STATUS_PTRN_MTCH_ERROR_WIDTH    ((uint32_t)0x00000010)
#define BMU_BAU_INT_RAW_STATUS_AXI_ERROR_MASK    ((uint32_t)0x0000FFFF)
#define BMU_BAU_INT_RAW_STATUS_AXI_ERROR_LSB    0
#define BMU_BAU_INT_RAW_STATUS_AXI_ERROR_WIDTH    ((uint32_t)0x00000010)

#define BMU_BAU_INT_RAW_STATUS_PTRN_MTCH_ERROR_RST    0x0
#define BMU_BAU_INT_RAW_STATUS_AXI_ERROR_RST    0x0

__INLINE void bmu_bau_int_raw_status_unpack(uint16_t* ptrn_mtch_error, uint16_t* axi_error)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_INT_RAW_STATUS_ADDR);

	*ptrn_mtch_error = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*axi_error = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t bmu_bau_int_raw_status_ptrn_mtch_error_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_INT_RAW_STATUS_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE uint16_t bmu_bau_int_raw_status_axi_error_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_INT_RAW_STATUS_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

/**
 * @brief BAU_INT_ENABLE_LMAC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 PTRN_MTCH_ERROR           0x0
 *    15:00 AXI_ERROR_EN              0x0
 * </pre>
 */
#define BMU_BAU_INT_ENABLE_LMAC_ADDR        (REG_BMU_BASE_ADDR+0x000008DC)
#define BMU_BAU_INT_ENABLE_LMAC_OFFSET      0x000008DC
#define BMU_BAU_INT_ENABLE_LMAC_INDEX       0x00000237
#define BMU_BAU_INT_ENABLE_LMAC_RESET       0x00000000

__INLINE uint32_t  bmu_bau_int_enable_lmac_get(void)
{
	return REG_PL_RD(BMU_BAU_INT_ENABLE_LMAC_ADDR);
}

__INLINE void bmu_bau_int_enable_lmac_set(uint32_t value)
{
	REG_PL_WR(BMU_BAU_INT_ENABLE_LMAC_ADDR, value);
}

// field definitions
#define BMU_BAU_INT_ENABLE_LMAC_PTRN_MTCH_ERROR_MASK    ((uint32_t)0xFFFF0000)
#define BMU_BAU_INT_ENABLE_LMAC_PTRN_MTCH_ERROR_LSB    16
#define BMU_BAU_INT_ENABLE_LMAC_PTRN_MTCH_ERROR_WIDTH    ((uint32_t)0x00000010)
#define BMU_BAU_INT_ENABLE_LMAC_AXI_ERROR_EN_MASK    ((uint32_t)0x0000FFFF)
#define BMU_BAU_INT_ENABLE_LMAC_AXI_ERROR_EN_LSB    0
#define BMU_BAU_INT_ENABLE_LMAC_AXI_ERROR_EN_WIDTH    ((uint32_t)0x00000010)

#define BMU_BAU_INT_ENABLE_LMAC_PTRN_MTCH_ERROR_RST    0x0
#define BMU_BAU_INT_ENABLE_LMAC_AXI_ERROR_EN_RST    0x0

__INLINE void bmu_bau_int_enable_lmac_pack(uint16_t ptrn_mtch_error, uint16_t axi_error_en)
{
	ASSERT_ERR((((uint32_t)ptrn_mtch_error << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)axi_error_en << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(BMU_BAU_INT_ENABLE_LMAC_ADDR,  ((uint32_t)ptrn_mtch_error << 16) |((uint32_t)axi_error_en << 0));
}

__INLINE void bmu_bau_int_enable_lmac_unpack(uint16_t* ptrn_mtch_error, uint16_t* axi_error_en)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_INT_ENABLE_LMAC_ADDR);

	*ptrn_mtch_error = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*axi_error_en = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t bmu_bau_int_enable_lmac_ptrn_mtch_error_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_INT_ENABLE_LMAC_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void bmu_bau_int_enable_lmac_ptrn_mtch_error_setf(uint16_t ptrnmtcherror)
{
	ASSERT_ERR((((uint32_t)ptrnmtcherror << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(BMU_BAU_INT_ENABLE_LMAC_ADDR, (REG_PL_RD(BMU_BAU_INT_ENABLE_LMAC_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)ptrnmtcherror <<16));
}
__INLINE uint16_t bmu_bau_int_enable_lmac_axi_error_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_INT_ENABLE_LMAC_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void bmu_bau_int_enable_lmac_axi_error_en_setf(uint16_t axierroren)
{
	ASSERT_ERR((((uint32_t)axierroren << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(BMU_BAU_INT_ENABLE_LMAC_ADDR, (REG_PL_RD(BMU_BAU_INT_ENABLE_LMAC_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)axierroren <<0));
}

/**
 * @brief BAU_INT_ENABLE_UMAC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 PTRN_MTCH_ERROR_EN        0x0
 *    15:00 AXI_ERROR_EN              0x0
 * </pre>
 */
#define BMU_BAU_INT_ENABLE_UMAC_ADDR        (REG_BMU_BASE_ADDR+0x000008E0)
#define BMU_BAU_INT_ENABLE_UMAC_OFFSET      0x000008E0
#define BMU_BAU_INT_ENABLE_UMAC_INDEX       0x00000238
#define BMU_BAU_INT_ENABLE_UMAC_RESET       0x00000000

__INLINE uint32_t  bmu_bau_int_enable_umac_get(void)
{
	return REG_PL_RD(BMU_BAU_INT_ENABLE_UMAC_ADDR);
}

__INLINE void bmu_bau_int_enable_umac_set(uint32_t value)
{
	REG_PL_WR(BMU_BAU_INT_ENABLE_UMAC_ADDR, value);
}

// field definitions
#define BMU_BAU_INT_ENABLE_UMAC_PTRN_MTCH_ERROR_EN_MASK    ((uint32_t)0xFFFF0000)
#define BMU_BAU_INT_ENABLE_UMAC_PTRN_MTCH_ERROR_EN_LSB    16
#define BMU_BAU_INT_ENABLE_UMAC_PTRN_MTCH_ERROR_EN_WIDTH    ((uint32_t)0x00000010)
#define BMU_BAU_INT_ENABLE_UMAC_AXI_ERROR_EN_MASK    ((uint32_t)0x0000FFFF)
#define BMU_BAU_INT_ENABLE_UMAC_AXI_ERROR_EN_LSB    0
#define BMU_BAU_INT_ENABLE_UMAC_AXI_ERROR_EN_WIDTH    ((uint32_t)0x00000010)

#define BMU_BAU_INT_ENABLE_UMAC_PTRN_MTCH_ERROR_EN_RST    0x0
#define BMU_BAU_INT_ENABLE_UMAC_AXI_ERROR_EN_RST    0x0

__INLINE void bmu_bau_int_enable_umac_pack(uint16_t ptrn_mtch_error_en, uint16_t axi_error_en)
{
	ASSERT_ERR((((uint32_t)ptrn_mtch_error_en << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)axi_error_en << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(BMU_BAU_INT_ENABLE_UMAC_ADDR,  ((uint32_t)ptrn_mtch_error_en << 16) |((uint32_t)axi_error_en << 0));
}

__INLINE void bmu_bau_int_enable_umac_unpack(uint16_t* ptrn_mtch_error_en, uint16_t* axi_error_en)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_INT_ENABLE_UMAC_ADDR);

	*ptrn_mtch_error_en = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*axi_error_en = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t bmu_bau_int_enable_umac_ptrn_mtch_error_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_INT_ENABLE_UMAC_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void bmu_bau_int_enable_umac_ptrn_mtch_error_en_setf(uint16_t ptrnmtcherroren)
{
	ASSERT_ERR((((uint32_t)ptrnmtcherroren << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(BMU_BAU_INT_ENABLE_UMAC_ADDR, (REG_PL_RD(BMU_BAU_INT_ENABLE_UMAC_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)ptrnmtcherroren <<16));
}
__INLINE uint16_t bmu_bau_int_enable_umac_axi_error_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_INT_ENABLE_UMAC_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void bmu_bau_int_enable_umac_axi_error_en_setf(uint16_t axierroren)
{
	ASSERT_ERR((((uint32_t)axierroren << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(BMU_BAU_INT_ENABLE_UMAC_ADDR, (REG_PL_RD(BMU_BAU_INT_ENABLE_UMAC_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)axierroren <<0));
}

/**
 * @brief BAU_INT_ENABLE_SMAC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 PTRN_MTCH_ERROR_EN        0x0
 *    15:00 AXI_ERROR_EN              0x0
 * </pre>
 */
#define BMU_BAU_INT_ENABLE_SMAC_ADDR        (REG_BMU_BASE_ADDR+0x000008E4)
#define BMU_BAU_INT_ENABLE_SMAC_OFFSET      0x000008E4
#define BMU_BAU_INT_ENABLE_SMAC_INDEX       0x00000239
#define BMU_BAU_INT_ENABLE_SMAC_RESET       0x00000000

__INLINE uint32_t  bmu_bau_int_enable_smac_get(void)
{
	return REG_PL_RD(BMU_BAU_INT_ENABLE_SMAC_ADDR);
}

__INLINE void bmu_bau_int_enable_smac_set(uint32_t value)
{
	REG_PL_WR(BMU_BAU_INT_ENABLE_SMAC_ADDR, value);
}

// field definitions
#define BMU_BAU_INT_ENABLE_SMAC_PTRN_MTCH_ERROR_EN_MASK    ((uint32_t)0xFFFF0000)
#define BMU_BAU_INT_ENABLE_SMAC_PTRN_MTCH_ERROR_EN_LSB    16
#define BMU_BAU_INT_ENABLE_SMAC_PTRN_MTCH_ERROR_EN_WIDTH    ((uint32_t)0x00000010)
#define BMU_BAU_INT_ENABLE_SMAC_AXI_ERROR_EN_MASK    ((uint32_t)0x0000FFFF)
#define BMU_BAU_INT_ENABLE_SMAC_AXI_ERROR_EN_LSB    0
#define BMU_BAU_INT_ENABLE_SMAC_AXI_ERROR_EN_WIDTH    ((uint32_t)0x00000010)

#define BMU_BAU_INT_ENABLE_SMAC_PTRN_MTCH_ERROR_EN_RST    0x0
#define BMU_BAU_INT_ENABLE_SMAC_AXI_ERROR_EN_RST    0x0

__INLINE void bmu_bau_int_enable_smac_pack(uint16_t ptrn_mtch_error_en, uint16_t axi_error_en)
{
	ASSERT_ERR((((uint32_t)ptrn_mtch_error_en << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)axi_error_en << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(BMU_BAU_INT_ENABLE_SMAC_ADDR,  ((uint32_t)ptrn_mtch_error_en << 16) |((uint32_t)axi_error_en << 0));
}

__INLINE void bmu_bau_int_enable_smac_unpack(uint16_t* ptrn_mtch_error_en, uint16_t* axi_error_en)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_INT_ENABLE_SMAC_ADDR);

	*ptrn_mtch_error_en = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*axi_error_en = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t bmu_bau_int_enable_smac_ptrn_mtch_error_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_INT_ENABLE_SMAC_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void bmu_bau_int_enable_smac_ptrn_mtch_error_en_setf(uint16_t ptrnmtcherroren)
{
	ASSERT_ERR((((uint32_t)ptrnmtcherroren << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(BMU_BAU_INT_ENABLE_SMAC_ADDR, (REG_PL_RD(BMU_BAU_INT_ENABLE_SMAC_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)ptrnmtcherroren <<16));
}
__INLINE uint16_t bmu_bau_int_enable_smac_axi_error_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_INT_ENABLE_SMAC_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void bmu_bau_int_enable_smac_axi_error_en_setf(uint16_t axierroren)
{
	ASSERT_ERR((((uint32_t)axierroren << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(BMU_BAU_INT_ENABLE_SMAC_ADDR, (REG_PL_RD(BMU_BAU_INT_ENABLE_SMAC_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)axierroren <<0));
}

/**
 * @brief BAU_INT_STATUS_LMAC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 PTRN_MTCH_ERROR           0x0
 *    15:00 AXI_ERROR                 0x0
 * </pre>
 */
#define BMU_BAU_INT_STATUS_LMAC_ADDR        (REG_BMU_BASE_ADDR+0x000008E8)
#define BMU_BAU_INT_STATUS_LMAC_OFFSET      0x000008E8
#define BMU_BAU_INT_STATUS_LMAC_INDEX       0x0000023A
#define BMU_BAU_INT_STATUS_LMAC_RESET       0x00000000

__INLINE uint32_t  bmu_bau_int_status_lmac_get(void)
{
	return REG_PL_RD(BMU_BAU_INT_STATUS_LMAC_ADDR);
}

// field definitions
#define BMU_BAU_INT_STATUS_LMAC_PTRN_MTCH_ERROR_MASK    ((uint32_t)0xFFFF0000)
#define BMU_BAU_INT_STATUS_LMAC_PTRN_MTCH_ERROR_LSB    16
#define BMU_BAU_INT_STATUS_LMAC_PTRN_MTCH_ERROR_WIDTH    ((uint32_t)0x00000010)
#define BMU_BAU_INT_STATUS_LMAC_AXI_ERROR_MASK    ((uint32_t)0x0000FFFF)
#define BMU_BAU_INT_STATUS_LMAC_AXI_ERROR_LSB    0
#define BMU_BAU_INT_STATUS_LMAC_AXI_ERROR_WIDTH    ((uint32_t)0x00000010)

#define BMU_BAU_INT_STATUS_LMAC_PTRN_MTCH_ERROR_RST    0x0
#define BMU_BAU_INT_STATUS_LMAC_AXI_ERROR_RST    0x0

__INLINE void bmu_bau_int_status_lmac_unpack(uint16_t* ptrn_mtch_error, uint16_t* axi_error)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_INT_STATUS_LMAC_ADDR);

	*ptrn_mtch_error = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*axi_error = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t bmu_bau_int_status_lmac_ptrn_mtch_error_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_INT_STATUS_LMAC_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE uint16_t bmu_bau_int_status_lmac_axi_error_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_INT_STATUS_LMAC_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

/**
 * @brief BAU_INT_STATUS_UMAC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 PTRN_MTCH_ERROR           0x0
 *    15:00 AXI_ERROR                 0x0
 * </pre>
 */
#define BMU_BAU_INT_STATUS_UMAC_ADDR        (REG_BMU_BASE_ADDR+0x000008EC)
#define BMU_BAU_INT_STATUS_UMAC_OFFSET      0x000008EC
#define BMU_BAU_INT_STATUS_UMAC_INDEX       0x0000023B
#define BMU_BAU_INT_STATUS_UMAC_RESET       0x00000000

__INLINE uint32_t  bmu_bau_int_status_umac_get(void)
{
	return REG_PL_RD(BMU_BAU_INT_STATUS_UMAC_ADDR);
}

// field definitions
#define BMU_BAU_INT_STATUS_UMAC_PTRN_MTCH_ERROR_MASK    ((uint32_t)0xFFFF0000)
#define BMU_BAU_INT_STATUS_UMAC_PTRN_MTCH_ERROR_LSB    16
#define BMU_BAU_INT_STATUS_UMAC_PTRN_MTCH_ERROR_WIDTH    ((uint32_t)0x00000010)
#define BMU_BAU_INT_STATUS_UMAC_AXI_ERROR_MASK    ((uint32_t)0x0000FFFF)
#define BMU_BAU_INT_STATUS_UMAC_AXI_ERROR_LSB    0
#define BMU_BAU_INT_STATUS_UMAC_AXI_ERROR_WIDTH    ((uint32_t)0x00000010)

#define BMU_BAU_INT_STATUS_UMAC_PTRN_MTCH_ERROR_RST    0x0
#define BMU_BAU_INT_STATUS_UMAC_AXI_ERROR_RST    0x0

__INLINE void bmu_bau_int_status_umac_unpack(uint16_t* ptrn_mtch_error, uint16_t* axi_error)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_INT_STATUS_UMAC_ADDR);

	*ptrn_mtch_error = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*axi_error = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t bmu_bau_int_status_umac_ptrn_mtch_error_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_INT_STATUS_UMAC_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE uint16_t bmu_bau_int_status_umac_axi_error_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_INT_STATUS_UMAC_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

/**
 * @brief BAU_INT_STATUS_SMAC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 PTRN_MTCH_ERROR           0x0
 *    15:00 AXI_ERROR                 0x0
 * </pre>
 */
#define BMU_BAU_INT_STATUS_SMAC_ADDR        (REG_BMU_BASE_ADDR+0x000008F0)
#define BMU_BAU_INT_STATUS_SMAC_OFFSET      0x000008F0
#define BMU_BAU_INT_STATUS_SMAC_INDEX       0x0000023C
#define BMU_BAU_INT_STATUS_SMAC_RESET       0x00000000

__INLINE uint32_t  bmu_bau_int_status_smac_get(void)
{
	return REG_PL_RD(BMU_BAU_INT_STATUS_SMAC_ADDR);
}

// field definitions
#define BMU_BAU_INT_STATUS_SMAC_PTRN_MTCH_ERROR_MASK    ((uint32_t)0xFFFF0000)
#define BMU_BAU_INT_STATUS_SMAC_PTRN_MTCH_ERROR_LSB    16
#define BMU_BAU_INT_STATUS_SMAC_PTRN_MTCH_ERROR_WIDTH    ((uint32_t)0x00000010)
#define BMU_BAU_INT_STATUS_SMAC_AXI_ERROR_MASK    ((uint32_t)0x0000FFFF)
#define BMU_BAU_INT_STATUS_SMAC_AXI_ERROR_LSB    0
#define BMU_BAU_INT_STATUS_SMAC_AXI_ERROR_WIDTH    ((uint32_t)0x00000010)

#define BMU_BAU_INT_STATUS_SMAC_PTRN_MTCH_ERROR_RST    0x0
#define BMU_BAU_INT_STATUS_SMAC_AXI_ERROR_RST    0x0

__INLINE void bmu_bau_int_status_smac_unpack(uint16_t* ptrn_mtch_error, uint16_t* axi_error)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_INT_STATUS_SMAC_ADDR);

	*ptrn_mtch_error = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*axi_error = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t bmu_bau_int_status_smac_ptrn_mtch_error_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_INT_STATUS_SMAC_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE uint16_t bmu_bau_int_status_smac_axi_error_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_INT_STATUS_SMAC_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

/**
 * @brief BAU_INT_FORCE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 PTRN_MTCH_ERROR_FORCE     0x0
 *    15:00 AXI_ERROR_FORCE           0x0
 * </pre>
 */
#define BMU_BAU_INT_FORCE_ADDR        (REG_BMU_BASE_ADDR+0x000008F4)
#define BMU_BAU_INT_FORCE_OFFSET      0x000008F4
#define BMU_BAU_INT_FORCE_INDEX       0x0000023D
#define BMU_BAU_INT_FORCE_RESET       0x00000000

__INLINE void bmu_bau_int_force_set(uint32_t value)
{
	REG_PL_WR(BMU_BAU_INT_FORCE_ADDR, value);
}

// field definitions
#define BMU_BAU_INT_FORCE_PTRN_MTCH_ERROR_FORCE_MASK    ((uint32_t)0xFFFF0000)
#define BMU_BAU_INT_FORCE_PTRN_MTCH_ERROR_FORCE_LSB    16
#define BMU_BAU_INT_FORCE_PTRN_MTCH_ERROR_FORCE_WIDTH    ((uint32_t)0x00000010)
#define BMU_BAU_INT_FORCE_AXI_ERROR_FORCE_MASK    ((uint32_t)0x0000FFFF)
#define BMU_BAU_INT_FORCE_AXI_ERROR_FORCE_LSB    0
#define BMU_BAU_INT_FORCE_AXI_ERROR_FORCE_WIDTH    ((uint32_t)0x00000010)

#define BMU_BAU_INT_FORCE_PTRN_MTCH_ERROR_FORCE_RST    0x0
#define BMU_BAU_INT_FORCE_AXI_ERROR_FORCE_RST    0x0

__INLINE void bmu_bau_int_force_pack(uint16_t ptrn_mtch_error_force, uint16_t axi_error_force)
{
	ASSERT_ERR((((uint32_t)ptrn_mtch_error_force << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)axi_error_force << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(BMU_BAU_INT_FORCE_ADDR,  ((uint32_t)ptrn_mtch_error_force << 16) |((uint32_t)axi_error_force << 0));
}

__INLINE void bmu_bau_int_force_ptrn_mtch_error_force_setf(uint16_t ptrnmtcherrorforce)
{
	ASSERT_ERR((((uint32_t)ptrnmtcherrorforce << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(BMU_BAU_INT_FORCE_ADDR, (REG_PL_RD(BMU_BAU_INT_FORCE_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)ptrnmtcherrorforce <<16));
}
__INLINE void bmu_bau_int_force_axi_error_force_setf(uint16_t axierrorforce)
{
	ASSERT_ERR((((uint32_t)axierrorforce << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(BMU_BAU_INT_FORCE_ADDR, (REG_PL_RD(BMU_BAU_INT_FORCE_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)axierrorforce <<0));
}

/**
 * @brief BAU_INT_CLEAR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 PTRN_MTCH_ERROR_CLEAR     0x0
 *    15:00 AXI_ERROR_CLEAR           0x0
 * </pre>
 */
#define BMU_BAU_INT_CLEAR_ADDR        (REG_BMU_BASE_ADDR+0x000008F8)
#define BMU_BAU_INT_CLEAR_OFFSET      0x000008F8
#define BMU_BAU_INT_CLEAR_INDEX       0x0000023E
#define BMU_BAU_INT_CLEAR_RESET       0x00000000

__INLINE void bmu_bau_int_clear_set(uint32_t value)
{
	REG_PL_WR(BMU_BAU_INT_CLEAR_ADDR, value);
}

// field definitions
#define BMU_BAU_INT_CLEAR_PTRN_MTCH_ERROR_CLEAR_MASK    ((uint32_t)0xFFFF0000)
#define BMU_BAU_INT_CLEAR_PTRN_MTCH_ERROR_CLEAR_LSB    16
#define BMU_BAU_INT_CLEAR_PTRN_MTCH_ERROR_CLEAR_WIDTH    ((uint32_t)0x00000010)
#define BMU_BAU_INT_CLEAR_AXI_ERROR_CLEAR_MASK    ((uint32_t)0x0000FFFF)
#define BMU_BAU_INT_CLEAR_AXI_ERROR_CLEAR_LSB    0
#define BMU_BAU_INT_CLEAR_AXI_ERROR_CLEAR_WIDTH    ((uint32_t)0x00000010)

#define BMU_BAU_INT_CLEAR_PTRN_MTCH_ERROR_CLEAR_RST    0x0
#define BMU_BAU_INT_CLEAR_AXI_ERROR_CLEAR_RST    0x0

__INLINE void bmu_bau_int_clear_pack(uint16_t ptrn_mtch_error_clear, uint16_t axi_error_clear)
{
	ASSERT_ERR((((uint32_t)ptrn_mtch_error_clear << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)axi_error_clear << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(BMU_BAU_INT_CLEAR_ADDR,  ((uint32_t)ptrn_mtch_error_clear << 16) |((uint32_t)axi_error_clear << 0));
}

__INLINE void bmu_bau_int_clear_ptrn_mtch_error_clear_setf(uint16_t ptrnmtcherrorclear)
{
	ASSERT_ERR((((uint32_t)ptrnmtcherrorclear << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(BMU_BAU_INT_CLEAR_ADDR, (REG_PL_RD(BMU_BAU_INT_CLEAR_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)ptrnmtcherrorclear <<16));
}
__INLINE void bmu_bau_int_clear_axi_error_clear_setf(uint16_t axierrorclear)
{
	ASSERT_ERR((((uint32_t)axierrorclear << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(BMU_BAU_INT_CLEAR_ADDR, (REG_PL_RD(BMU_BAU_INT_CLEAR_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)axierrorclear <<0));
}

/**
 * @brief BAU_DEBUG_SEL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01:00 DEBUG_SEL                 0x0
 * </pre>
 */
#define BMU_BAU_DEBUG_SEL_ADDR        (REG_BMU_BASE_ADDR+0x000008FC)
#define BMU_BAU_DEBUG_SEL_OFFSET      0x000008FC
#define BMU_BAU_DEBUG_SEL_INDEX       0x0000023F
#define BMU_BAU_DEBUG_SEL_RESET       0x00000000

__INLINE uint32_t  bmu_bau_debug_sel_get(void)
{
	return REG_PL_RD(BMU_BAU_DEBUG_SEL_ADDR);
}

__INLINE void bmu_bau_debug_sel_set(uint32_t value)
{
	REG_PL_WR(BMU_BAU_DEBUG_SEL_ADDR, value);
}

// field definitions
#define BMU_BAU_DEBUG_SEL_DEBUG_SEL_MASK    ((uint32_t)0x00000003)
#define BMU_BAU_DEBUG_SEL_DEBUG_SEL_LSB     0
#define BMU_BAU_DEBUG_SEL_DEBUG_SEL_WIDTH    ((uint32_t)0x00000002)

#define BMU_BAU_DEBUG_SEL_DEBUG_SEL_RST     0x0

__INLINE uint8_t bmu_bau_debug_sel_debug_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_DEBUG_SEL_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void bmu_bau_debug_sel_debug_sel_setf(uint8_t debugsel)
{
	ASSERT_ERR((((uint32_t)debugsel << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(BMU_BAU_DEBUG_SEL_ADDR, (uint32_t)debugsel << 0);
}

/**
 * @brief BAU_DEBUG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:20 RPD_AXI_WR_STATE          0x0
 *    19:16 RHD_AXI_WR_STATE          0x0
 *    15:12 RPD_AXI_RD_STATE          0x0
 *    11:08 RHD_AXI_RD_STATE          0x0
 *    07:04 ACTIVE_MAC                0x0
 *    03:00 ACTIVE_FREE_LIST          0x7
 * </pre>
 */
#define BMU_BAU_DEBUG_1_ADDR        (REG_BMU_BASE_ADDR+0x00000900)
#define BMU_BAU_DEBUG_1_OFFSET      0x00000900
#define BMU_BAU_DEBUG_1_INDEX       0x00000240
#define BMU_BAU_DEBUG_1_RESET       0x00000007

__INLINE uint32_t  bmu_bau_debug_1_get(void)
{
	return REG_PL_RD(BMU_BAU_DEBUG_1_ADDR);
}

// field definitions
#define BMU_BAU_DEBUG_1_RPD_AXI_WR_STATE_MASK    ((uint32_t)0x0FF00000)
#define BMU_BAU_DEBUG_1_RPD_AXI_WR_STATE_LSB    20
#define BMU_BAU_DEBUG_1_RPD_AXI_WR_STATE_WIDTH    ((uint32_t)0x00000008)
#define BMU_BAU_DEBUG_1_RHD_AXI_WR_STATE_MASK    ((uint32_t)0x000F0000)
#define BMU_BAU_DEBUG_1_RHD_AXI_WR_STATE_LSB    16
#define BMU_BAU_DEBUG_1_RHD_AXI_WR_STATE_WIDTH    ((uint32_t)0x00000004)
#define BMU_BAU_DEBUG_1_RPD_AXI_RD_STATE_MASK    ((uint32_t)0x0000F000)
#define BMU_BAU_DEBUG_1_RPD_AXI_RD_STATE_LSB    12
#define BMU_BAU_DEBUG_1_RPD_AXI_RD_STATE_WIDTH    ((uint32_t)0x00000004)
#define BMU_BAU_DEBUG_1_RHD_AXI_RD_STATE_MASK    ((uint32_t)0x00000F00)
#define BMU_BAU_DEBUG_1_RHD_AXI_RD_STATE_LSB    8
#define BMU_BAU_DEBUG_1_RHD_AXI_RD_STATE_WIDTH    ((uint32_t)0x00000004)
#define BMU_BAU_DEBUG_1_ACTIVE_MAC_MASK     ((uint32_t)0x000000F0)
#define BMU_BAU_DEBUG_1_ACTIVE_MAC_LSB      4
#define BMU_BAU_DEBUG_1_ACTIVE_MAC_WIDTH    ((uint32_t)0x00000004)
#define BMU_BAU_DEBUG_1_ACTIVE_FREE_LIST_MASK    ((uint32_t)0x0000000F)
#define BMU_BAU_DEBUG_1_ACTIVE_FREE_LIST_LSB    0
#define BMU_BAU_DEBUG_1_ACTIVE_FREE_LIST_WIDTH    ((uint32_t)0x00000004)

#define BMU_BAU_DEBUG_1_RPD_AXI_WR_STATE_RST    0x0
#define BMU_BAU_DEBUG_1_RHD_AXI_WR_STATE_RST    0x0
#define BMU_BAU_DEBUG_1_RPD_AXI_RD_STATE_RST    0x0
#define BMU_BAU_DEBUG_1_RHD_AXI_RD_STATE_RST    0x0
#define BMU_BAU_DEBUG_1_ACTIVE_MAC_RST      0x0
#define BMU_BAU_DEBUG_1_ACTIVE_FREE_LIST_RST    0x7

__INLINE void bmu_bau_debug_1_unpack(uint8_t* rpd_axi_wr_state, uint8_t* rhd_axi_wr_state, uint8_t* rpd_axi_rd_state, uint8_t* rhd_axi_rd_state, uint8_t* active_mac, uint8_t* active_free_list)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_DEBUG_1_ADDR);

	*rpd_axi_wr_state = (localVal & ((uint32_t)0x0FF00000)) >>  20;
	*rhd_axi_wr_state = (localVal & ((uint32_t)0x000F0000)) >>  16;
	*rpd_axi_rd_state = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*rhd_axi_rd_state = (localVal & ((uint32_t)0x00000F00)) >>  8;
	*active_mac = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*active_free_list = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t bmu_bau_debug_1_rpd_axi_wr_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_DEBUG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0FF00000)) >> 20);
}
__INLINE uint8_t bmu_bau_debug_1_rhd_axi_wr_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_DEBUG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000F0000)) >> 16);
}
__INLINE uint8_t bmu_bau_debug_1_rpd_axi_rd_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_DEBUG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE uint8_t bmu_bau_debug_1_rhd_axi_rd_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_DEBUG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000F00)) >> 8);
}
__INLINE uint8_t bmu_bau_debug_1_active_mac_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_DEBUG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t bmu_bau_debug_1_active_free_list_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_DEBUG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}

/**
 * @brief BAU_DEBUG_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BAU_BAND0_VALID           0x0
 * </pre>
 */
#define BMU_BAU_DEBUG_2_ADDR        (REG_BMU_BASE_ADDR+0x00000904)
#define BMU_BAU_DEBUG_2_OFFSET      0x00000904
#define BMU_BAU_DEBUG_2_INDEX       0x00000241
#define BMU_BAU_DEBUG_2_RESET       0x00000000

__INLINE uint32_t  bmu_bau_debug_2_get(void)
{
	return REG_PL_RD(BMU_BAU_DEBUG_2_ADDR);
}

// field definitions
#define BMU_BAU_DEBUG_2_BAU_BAND_0_VALID_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BAU_DEBUG_2_BAU_BAND_0_VALID_LSB    0
#define BMU_BAU_DEBUG_2_BAU_BAND_0_VALID_WIDTH    ((uint32_t)0x00000020)

#define BMU_BAU_DEBUG_2_BAU_BAND_0_VALID_RST    0x0

__INLINE uint32_t bmu_bau_debug_2_bau_band_0_valid_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_DEBUG_2_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BAU_DEBUG_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BAU_BAND1_VALID           0x0
 * </pre>
 */
#define BMU_BAU_DEBUG_3_ADDR        (REG_BMU_BASE_ADDR+0x00000908)
#define BMU_BAU_DEBUG_3_OFFSET      0x00000908
#define BMU_BAU_DEBUG_3_INDEX       0x00000242
#define BMU_BAU_DEBUG_3_RESET       0x00000000

__INLINE uint32_t  bmu_bau_debug_3_get(void)
{
	return REG_PL_RD(BMU_BAU_DEBUG_3_ADDR);
}

// field definitions
#define BMU_BAU_DEBUG_3_BAU_BAND_1_VALID_MASK    ((uint32_t)0xFFFFFFFF)
#define BMU_BAU_DEBUG_3_BAU_BAND_1_VALID_LSB    0
#define BMU_BAU_DEBUG_3_BAU_BAND_1_VALID_WIDTH    ((uint32_t)0x00000020)

#define BMU_BAU_DEBUG_3_BAU_BAND_1_VALID_RST    0x0

__INLINE uint32_t bmu_bau_debug_3_bau_band_1_valid_getf(void)
{
	uint32_t localVal = REG_PL_RD(BMU_BAU_DEBUG_3_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BAU_FREE_LIST_CLEAR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    FREE_LIST_CLEAR           0              
 *    03:00 FREE_LIST_ID              0x0
 * </pre>
 */
#define BMU_BAU_FREE_LIST_CLEAR_ADDR        (REG_BMU_BASE_ADDR+0x0000090C)
#define BMU_BAU_FREE_LIST_CLEAR_OFFSET      0x0000090C
#define BMU_BAU_FREE_LIST_CLEAR_INDEX       0x00000243
#define BMU_BAU_FREE_LIST_CLEAR_RESET       0x00000000

__INLINE void bmu_bau_free_list_clear_set(uint32_t value)
{
	REG_PL_WR(BMU_BAU_FREE_LIST_CLEAR_ADDR, value);
}

// field definitions
#define BMU_BAU_FREE_LIST_CLEAR_FREE_LIST_CLEAR_BIT    ((uint32_t)0x80000000)
#define BMU_BAU_FREE_LIST_CLEAR_FREE_LIST_CLEAR_POS    31
#define BMU_BAU_FREE_LIST_CLEAR_FREE_LIST_ID_MASK    ((uint32_t)0x0000000F)
#define BMU_BAU_FREE_LIST_CLEAR_FREE_LIST_ID_LSB    0
#define BMU_BAU_FREE_LIST_CLEAR_FREE_LIST_ID_WIDTH    ((uint32_t)0x00000004)

#define BMU_BAU_FREE_LIST_CLEAR_FREE_LIST_CLEAR_RST    0x0
#define BMU_BAU_FREE_LIST_CLEAR_FREE_LIST_ID_RST    0x0

__INLINE void bmu_bau_free_list_clear_pack(uint8_t free_list_clear, uint8_t free_list_id)
{
	ASSERT_ERR((((uint32_t)free_list_clear << 31) & ~((uint32_t)0x80000000)) == 0);
	ASSERT_ERR((((uint32_t)free_list_id << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(BMU_BAU_FREE_LIST_CLEAR_ADDR,  ((uint32_t)free_list_clear << 31) |((uint32_t)free_list_id << 0));
}

__INLINE void bmu_bau_free_list_clear_free_list_clear_setf(uint8_t freelistclear)
{
	ASSERT_ERR((((uint32_t)freelistclear << 31) & ~((uint32_t)0x80000000)) == 0);
	REG_PL_WR(BMU_BAU_FREE_LIST_CLEAR_ADDR, (REG_PL_RD(BMU_BAU_FREE_LIST_CLEAR_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)freelistclear <<31));
}
__INLINE void bmu_bau_free_list_clear_free_list_id_setf(uint8_t freelistid)
{
	ASSERT_ERR((((uint32_t)freelistid << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(BMU_BAU_FREE_LIST_CLEAR_ADDR, (REG_PL_RD(BMU_BAU_FREE_LIST_CLEAR_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)freelistid <<0));
}


#undef DBG_FILEID
#endif //_REG_BMU_H_

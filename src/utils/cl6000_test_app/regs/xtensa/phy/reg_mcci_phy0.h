#ifndef _REG_MCCI_PHY0_H_
#define _REG_MCCI_PHY0_H_

#include <stdint.h>
#include "phy/_reg_mcci_phy0.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define DBG_FILEID __REG_MCCI_PHY0__H__FILEID__

#define REG_MCCI_PHY0_COUNT  35


/**
 * @brief COM_REG_0 register definition
 *  Messaging memory register 0 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 COM_REG                   0x0
 * </pre>
 */
#define MCCI_PHY0_COM_REG_0_ADDR        (REG_MCCI_PHY0_BASE_ADDR+0x00000000)
#define MCCI_PHY0_COM_REG_0_OFFSET      0x00000000
#define MCCI_PHY0_COM_REG_0_INDEX       0x00000000
#define MCCI_PHY0_COM_REG_0_RESET       0x00000000

__INLINE void mcci_phy0_com_reg_0_set(uint32_t value)
{
	REG_PL_WR(MCCI_PHY0_COM_REG_0_ADDR, value);
}

// field definitions
#define MCCI_PHY0_COM_REG_0_COM_REG_MASK    ((uint32_t)0xFFFFFFFF)
#define MCCI_PHY0_COM_REG_0_COM_REG_LSB     0
#define MCCI_PHY0_COM_REG_0_COM_REG_WIDTH    ((uint32_t)0x00000020)

#define MCCI_PHY0_COM_REG_0_COM_REG_RST     0x0

__INLINE void mcci_phy0_com_reg_0_com_reg_setf(uint32_t comreg)
{
	ASSERT_ERR((((uint32_t)comreg << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MCCI_PHY0_COM_REG_0_ADDR, (uint32_t)comreg << 0);
}

/**
 * @brief COM_REG_1 register definition
 *  Messaging memory register 1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 COM_REG                   0x0
 * </pre>
 */
#define MCCI_PHY0_COM_REG_1_ADDR        (REG_MCCI_PHY0_BASE_ADDR+0x00000004)
#define MCCI_PHY0_COM_REG_1_OFFSET      0x00000004
#define MCCI_PHY0_COM_REG_1_INDEX       0x00000001
#define MCCI_PHY0_COM_REG_1_RESET       0x00000000

__INLINE void mcci_phy0_com_reg_1_set(uint32_t value)
{
	REG_PL_WR(MCCI_PHY0_COM_REG_1_ADDR, value);
}

// field definitions
#define MCCI_PHY0_COM_REG_1_COM_REG_MASK    ((uint32_t)0xFFFFFFFF)
#define MCCI_PHY0_COM_REG_1_COM_REG_LSB     0
#define MCCI_PHY0_COM_REG_1_COM_REG_WIDTH    ((uint32_t)0x00000020)

#define MCCI_PHY0_COM_REG_1_COM_REG_RST     0x0

__INLINE void mcci_phy0_com_reg_1_com_reg_setf(uint32_t comreg)
{
	ASSERT_ERR((((uint32_t)comreg << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MCCI_PHY0_COM_REG_1_ADDR, (uint32_t)comreg << 0);
}

/**
 * @brief COM_REG_2 register definition
 *  Messaging memory register 2 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 COM_REG                   0x0
 * </pre>
 */
#define MCCI_PHY0_COM_REG_2_ADDR        (REG_MCCI_PHY0_BASE_ADDR+0x00000008)
#define MCCI_PHY0_COM_REG_2_OFFSET      0x00000008
#define MCCI_PHY0_COM_REG_2_INDEX       0x00000002
#define MCCI_PHY0_COM_REG_2_RESET       0x00000000

__INLINE void mcci_phy0_com_reg_2_set(uint32_t value)
{
	REG_PL_WR(MCCI_PHY0_COM_REG_2_ADDR, value);
}

// field definitions
#define MCCI_PHY0_COM_REG_2_COM_REG_MASK    ((uint32_t)0xFFFFFFFF)
#define MCCI_PHY0_COM_REG_2_COM_REG_LSB     0
#define MCCI_PHY0_COM_REG_2_COM_REG_WIDTH    ((uint32_t)0x00000020)

#define MCCI_PHY0_COM_REG_2_COM_REG_RST     0x0

__INLINE void mcci_phy0_com_reg_2_com_reg_setf(uint32_t comreg)
{
	ASSERT_ERR((((uint32_t)comreg << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MCCI_PHY0_COM_REG_2_ADDR, (uint32_t)comreg << 0);
}

/**
 * @brief COM_REG_3 register definition
 *  Messaging memory register 3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 COM_REG                   0x0
 * </pre>
 */
#define MCCI_PHY0_COM_REG_3_ADDR        (REG_MCCI_PHY0_BASE_ADDR+0x0000000C)
#define MCCI_PHY0_COM_REG_3_OFFSET      0x0000000C
#define MCCI_PHY0_COM_REG_3_INDEX       0x00000003
#define MCCI_PHY0_COM_REG_3_RESET       0x00000000

__INLINE void mcci_phy0_com_reg_3_set(uint32_t value)
{
	REG_PL_WR(MCCI_PHY0_COM_REG_3_ADDR, value);
}

// field definitions
#define MCCI_PHY0_COM_REG_3_COM_REG_MASK    ((uint32_t)0xFFFFFFFF)
#define MCCI_PHY0_COM_REG_3_COM_REG_LSB     0
#define MCCI_PHY0_COM_REG_3_COM_REG_WIDTH    ((uint32_t)0x00000020)

#define MCCI_PHY0_COM_REG_3_COM_REG_RST     0x0

__INLINE void mcci_phy0_com_reg_3_com_reg_setf(uint32_t comreg)
{
	ASSERT_ERR((((uint32_t)comreg << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MCCI_PHY0_COM_REG_3_ADDR, (uint32_t)comreg << 0);
}

/**
 * @brief COM_REG_4 register definition
 *  Messaging memory register 4 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 COM_REG                   0x0
 * </pre>
 */
#define MCCI_PHY0_COM_REG_4_ADDR        (REG_MCCI_PHY0_BASE_ADDR+0x00000010)
#define MCCI_PHY0_COM_REG_4_OFFSET      0x00000010
#define MCCI_PHY0_COM_REG_4_INDEX       0x00000004
#define MCCI_PHY0_COM_REG_4_RESET       0x00000000

__INLINE void mcci_phy0_com_reg_4_set(uint32_t value)
{
	REG_PL_WR(MCCI_PHY0_COM_REG_4_ADDR, value);
}

// field definitions
#define MCCI_PHY0_COM_REG_4_COM_REG_MASK    ((uint32_t)0xFFFFFFFF)
#define MCCI_PHY0_COM_REG_4_COM_REG_LSB     0
#define MCCI_PHY0_COM_REG_4_COM_REG_WIDTH    ((uint32_t)0x00000020)

#define MCCI_PHY0_COM_REG_4_COM_REG_RST     0x0

__INLINE void mcci_phy0_com_reg_4_com_reg_setf(uint32_t comreg)
{
	ASSERT_ERR((((uint32_t)comreg << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MCCI_PHY0_COM_REG_4_ADDR, (uint32_t)comreg << 0);
}

/**
 * @brief COM_REG_5 register definition
 *  Messaging memory register 5 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 COM_REG                   0x0
 * </pre>
 */
#define MCCI_PHY0_COM_REG_5_ADDR        (REG_MCCI_PHY0_BASE_ADDR+0x00000014)
#define MCCI_PHY0_COM_REG_5_OFFSET      0x00000014
#define MCCI_PHY0_COM_REG_5_INDEX       0x00000005
#define MCCI_PHY0_COM_REG_5_RESET       0x00000000

__INLINE void mcci_phy0_com_reg_5_set(uint32_t value)
{
	REG_PL_WR(MCCI_PHY0_COM_REG_5_ADDR, value);
}

// field definitions
#define MCCI_PHY0_COM_REG_5_COM_REG_MASK    ((uint32_t)0xFFFFFFFF)
#define MCCI_PHY0_COM_REG_5_COM_REG_LSB     0
#define MCCI_PHY0_COM_REG_5_COM_REG_WIDTH    ((uint32_t)0x00000020)

#define MCCI_PHY0_COM_REG_5_COM_REG_RST     0x0

__INLINE void mcci_phy0_com_reg_5_com_reg_setf(uint32_t comreg)
{
	ASSERT_ERR((((uint32_t)comreg << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MCCI_PHY0_COM_REG_5_ADDR, (uint32_t)comreg << 0);
}

/**
 * @brief COM_REG_6 register definition
 *  Messaging memory register 6 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 COM_REG                   0x0
 * </pre>
 */
#define MCCI_PHY0_COM_REG_6_ADDR        (REG_MCCI_PHY0_BASE_ADDR+0x00000018)
#define MCCI_PHY0_COM_REG_6_OFFSET      0x00000018
#define MCCI_PHY0_COM_REG_6_INDEX       0x00000006
#define MCCI_PHY0_COM_REG_6_RESET       0x00000000

__INLINE void mcci_phy0_com_reg_6_set(uint32_t value)
{
	REG_PL_WR(MCCI_PHY0_COM_REG_6_ADDR, value);
}

// field definitions
#define MCCI_PHY0_COM_REG_6_COM_REG_MASK    ((uint32_t)0xFFFFFFFF)
#define MCCI_PHY0_COM_REG_6_COM_REG_LSB     0
#define MCCI_PHY0_COM_REG_6_COM_REG_WIDTH    ((uint32_t)0x00000020)

#define MCCI_PHY0_COM_REG_6_COM_REG_RST     0x0

__INLINE void mcci_phy0_com_reg_6_com_reg_setf(uint32_t comreg)
{
	ASSERT_ERR((((uint32_t)comreg << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MCCI_PHY0_COM_REG_6_ADDR, (uint32_t)comreg << 0);
}

/**
 * @brief COM_REG_7 register definition
 *  Messaging memory register 7 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 COM_REG                   0x0
 * </pre>
 */
#define MCCI_PHY0_COM_REG_7_ADDR        (REG_MCCI_PHY0_BASE_ADDR+0x0000001C)
#define MCCI_PHY0_COM_REG_7_OFFSET      0x0000001C
#define MCCI_PHY0_COM_REG_7_INDEX       0x00000007
#define MCCI_PHY0_COM_REG_7_RESET       0x00000000

__INLINE void mcci_phy0_com_reg_7_set(uint32_t value)
{
	REG_PL_WR(MCCI_PHY0_COM_REG_7_ADDR, value);
}

// field definitions
#define MCCI_PHY0_COM_REG_7_COM_REG_MASK    ((uint32_t)0xFFFFFFFF)
#define MCCI_PHY0_COM_REG_7_COM_REG_LSB     0
#define MCCI_PHY0_COM_REG_7_COM_REG_WIDTH    ((uint32_t)0x00000020)

#define MCCI_PHY0_COM_REG_7_COM_REG_RST     0x0

__INLINE void mcci_phy0_com_reg_7_com_reg_setf(uint32_t comreg)
{
	ASSERT_ERR((((uint32_t)comreg << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MCCI_PHY0_COM_REG_7_ADDR, (uint32_t)comreg << 0);
}

/**
 * @brief COM_REG_8 register definition
 *  Messaging memory register 8 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 COM_REG                   0x0
 * </pre>
 */
#define MCCI_PHY0_COM_REG_8_ADDR        (REG_MCCI_PHY0_BASE_ADDR+0x00000020)
#define MCCI_PHY0_COM_REG_8_OFFSET      0x00000020
#define MCCI_PHY0_COM_REG_8_INDEX       0x00000008
#define MCCI_PHY0_COM_REG_8_RESET       0x00000000

__INLINE void mcci_phy0_com_reg_8_set(uint32_t value)
{
	REG_PL_WR(MCCI_PHY0_COM_REG_8_ADDR, value);
}

// field definitions
#define MCCI_PHY0_COM_REG_8_COM_REG_MASK    ((uint32_t)0xFFFFFFFF)
#define MCCI_PHY0_COM_REG_8_COM_REG_LSB     0
#define MCCI_PHY0_COM_REG_8_COM_REG_WIDTH    ((uint32_t)0x00000020)

#define MCCI_PHY0_COM_REG_8_COM_REG_RST     0x0

__INLINE void mcci_phy0_com_reg_8_com_reg_setf(uint32_t comreg)
{
	ASSERT_ERR((((uint32_t)comreg << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MCCI_PHY0_COM_REG_8_ADDR, (uint32_t)comreg << 0);
}

/**
 * @brief COM_REG_9 register definition
 *  Messaging memory register 9 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 COM_REG                   0x0
 * </pre>
 */
#define MCCI_PHY0_COM_REG_9_ADDR        (REG_MCCI_PHY0_BASE_ADDR+0x00000024)
#define MCCI_PHY0_COM_REG_9_OFFSET      0x00000024
#define MCCI_PHY0_COM_REG_9_INDEX       0x00000009
#define MCCI_PHY0_COM_REG_9_RESET       0x00000000

__INLINE void mcci_phy0_com_reg_9_set(uint32_t value)
{
	REG_PL_WR(MCCI_PHY0_COM_REG_9_ADDR, value);
}

// field definitions
#define MCCI_PHY0_COM_REG_9_COM_REG_MASK    ((uint32_t)0xFFFFFFFF)
#define MCCI_PHY0_COM_REG_9_COM_REG_LSB     0
#define MCCI_PHY0_COM_REG_9_COM_REG_WIDTH    ((uint32_t)0x00000020)

#define MCCI_PHY0_COM_REG_9_COM_REG_RST     0x0

__INLINE void mcci_phy0_com_reg_9_com_reg_setf(uint32_t comreg)
{
	ASSERT_ERR((((uint32_t)comreg << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MCCI_PHY0_COM_REG_9_ADDR, (uint32_t)comreg << 0);
}

/**
 * @brief COM_REG_10 register definition
 *  Messaging memory register 10 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 COM_REG                   0x0
 * </pre>
 */
#define MCCI_PHY0_COM_REG_10_ADDR        (REG_MCCI_PHY0_BASE_ADDR+0x00000028)
#define MCCI_PHY0_COM_REG_10_OFFSET      0x00000028
#define MCCI_PHY0_COM_REG_10_INDEX       0x0000000A
#define MCCI_PHY0_COM_REG_10_RESET       0x00000000

__INLINE void mcci_phy0_com_reg_10_set(uint32_t value)
{
	REG_PL_WR(MCCI_PHY0_COM_REG_10_ADDR, value);
}

// field definitions
#define MCCI_PHY0_COM_REG_10_COM_REG_MASK    ((uint32_t)0xFFFFFFFF)
#define MCCI_PHY0_COM_REG_10_COM_REG_LSB    0
#define MCCI_PHY0_COM_REG_10_COM_REG_WIDTH    ((uint32_t)0x00000020)

#define MCCI_PHY0_COM_REG_10_COM_REG_RST    0x0

__INLINE void mcci_phy0_com_reg_10_com_reg_setf(uint32_t comreg)
{
	ASSERT_ERR((((uint32_t)comreg << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MCCI_PHY0_COM_REG_10_ADDR, (uint32_t)comreg << 0);
}

/**
 * @brief COM_REG_11 register definition
 *  Messaging memory register 11 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 COM_REG                   0x0
 * </pre>
 */
#define MCCI_PHY0_COM_REG_11_ADDR        (REG_MCCI_PHY0_BASE_ADDR+0x0000002C)
#define MCCI_PHY0_COM_REG_11_OFFSET      0x0000002C
#define MCCI_PHY0_COM_REG_11_INDEX       0x0000000B
#define MCCI_PHY0_COM_REG_11_RESET       0x00000000

__INLINE void mcci_phy0_com_reg_11_set(uint32_t value)
{
	REG_PL_WR(MCCI_PHY0_COM_REG_11_ADDR, value);
}

// field definitions
#define MCCI_PHY0_COM_REG_11_COM_REG_MASK    ((uint32_t)0xFFFFFFFF)
#define MCCI_PHY0_COM_REG_11_COM_REG_LSB    0
#define MCCI_PHY0_COM_REG_11_COM_REG_WIDTH    ((uint32_t)0x00000020)

#define MCCI_PHY0_COM_REG_11_COM_REG_RST    0x0

__INLINE void mcci_phy0_com_reg_11_com_reg_setf(uint32_t comreg)
{
	ASSERT_ERR((((uint32_t)comreg << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MCCI_PHY0_COM_REG_11_ADDR, (uint32_t)comreg << 0);
}

/**
 * @brief COM_REG_12 register definition
 *  Messaging memory register 12 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 COM_REG                   0x0
 * </pre>
 */
#define MCCI_PHY0_COM_REG_12_ADDR        (REG_MCCI_PHY0_BASE_ADDR+0x00000030)
#define MCCI_PHY0_COM_REG_12_OFFSET      0x00000030
#define MCCI_PHY0_COM_REG_12_INDEX       0x0000000C
#define MCCI_PHY0_COM_REG_12_RESET       0x00000000

__INLINE void mcci_phy0_com_reg_12_set(uint32_t value)
{
	REG_PL_WR(MCCI_PHY0_COM_REG_12_ADDR, value);
}

// field definitions
#define MCCI_PHY0_COM_REG_12_COM_REG_MASK    ((uint32_t)0xFFFFFFFF)
#define MCCI_PHY0_COM_REG_12_COM_REG_LSB    0
#define MCCI_PHY0_COM_REG_12_COM_REG_WIDTH    ((uint32_t)0x00000020)

#define MCCI_PHY0_COM_REG_12_COM_REG_RST    0x0

__INLINE void mcci_phy0_com_reg_12_com_reg_setf(uint32_t comreg)
{
	ASSERT_ERR((((uint32_t)comreg << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MCCI_PHY0_COM_REG_12_ADDR, (uint32_t)comreg << 0);
}

/**
 * @brief COM_REG_13 register definition
 *  Messaging memory register 13 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 COM_REG                   0x0
 * </pre>
 */
#define MCCI_PHY0_COM_REG_13_ADDR        (REG_MCCI_PHY0_BASE_ADDR+0x00000034)
#define MCCI_PHY0_COM_REG_13_OFFSET      0x00000034
#define MCCI_PHY0_COM_REG_13_INDEX       0x0000000D
#define MCCI_PHY0_COM_REG_13_RESET       0x00000000

__INLINE void mcci_phy0_com_reg_13_set(uint32_t value)
{
	REG_PL_WR(MCCI_PHY0_COM_REG_13_ADDR, value);
}

// field definitions
#define MCCI_PHY0_COM_REG_13_COM_REG_MASK    ((uint32_t)0xFFFFFFFF)
#define MCCI_PHY0_COM_REG_13_COM_REG_LSB    0
#define MCCI_PHY0_COM_REG_13_COM_REG_WIDTH    ((uint32_t)0x00000020)

#define MCCI_PHY0_COM_REG_13_COM_REG_RST    0x0

__INLINE void mcci_phy0_com_reg_13_com_reg_setf(uint32_t comreg)
{
	ASSERT_ERR((((uint32_t)comreg << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MCCI_PHY0_COM_REG_13_ADDR, (uint32_t)comreg << 0);
}

/**
 * @brief COM_REG_14 register definition
 *  Messaging memory register 14 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 COM_REG                   0x0
 * </pre>
 */
#define MCCI_PHY0_COM_REG_14_ADDR        (REG_MCCI_PHY0_BASE_ADDR+0x00000038)
#define MCCI_PHY0_COM_REG_14_OFFSET      0x00000038
#define MCCI_PHY0_COM_REG_14_INDEX       0x0000000E
#define MCCI_PHY0_COM_REG_14_RESET       0x00000000

__INLINE void mcci_phy0_com_reg_14_set(uint32_t value)
{
	REG_PL_WR(MCCI_PHY0_COM_REG_14_ADDR, value);
}

// field definitions
#define MCCI_PHY0_COM_REG_14_COM_REG_MASK    ((uint32_t)0xFFFFFFFF)
#define MCCI_PHY0_COM_REG_14_COM_REG_LSB    0
#define MCCI_PHY0_COM_REG_14_COM_REG_WIDTH    ((uint32_t)0x00000020)

#define MCCI_PHY0_COM_REG_14_COM_REG_RST    0x0

__INLINE void mcci_phy0_com_reg_14_com_reg_setf(uint32_t comreg)
{
	ASSERT_ERR((((uint32_t)comreg << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MCCI_PHY0_COM_REG_14_ADDR, (uint32_t)comreg << 0);
}

/**
 * @brief COM_REG_15 register definition
 *  Messaging memory register 15 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 COM_REG                   0x0
 * </pre>
 */
#define MCCI_PHY0_COM_REG_15_ADDR        (REG_MCCI_PHY0_BASE_ADDR+0x0000003C)
#define MCCI_PHY0_COM_REG_15_OFFSET      0x0000003C
#define MCCI_PHY0_COM_REG_15_INDEX       0x0000000F
#define MCCI_PHY0_COM_REG_15_RESET       0x00000000

__INLINE void mcci_phy0_com_reg_15_set(uint32_t value)
{
	REG_PL_WR(MCCI_PHY0_COM_REG_15_ADDR, value);
}

// field definitions
#define MCCI_PHY0_COM_REG_15_COM_REG_MASK    ((uint32_t)0xFFFFFFFF)
#define MCCI_PHY0_COM_REG_15_COM_REG_LSB    0
#define MCCI_PHY0_COM_REG_15_COM_REG_WIDTH    ((uint32_t)0x00000020)

#define MCCI_PHY0_COM_REG_15_COM_REG_RST    0x0

__INLINE void mcci_phy0_com_reg_15_com_reg_setf(uint32_t comreg)
{
	ASSERT_ERR((((uint32_t)comreg << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MCCI_PHY0_COM_REG_15_ADDR, (uint32_t)comreg << 0);
}

/**
 * @brief COM_REG_16 register definition
 *  Messaging memory register 16 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 COM_REG                   0x0
 * </pre>
 */
#define MCCI_PHY0_COM_REG_16_ADDR        (REG_MCCI_PHY0_BASE_ADDR+0x00000040)
#define MCCI_PHY0_COM_REG_16_OFFSET      0x00000040
#define MCCI_PHY0_COM_REG_16_INDEX       0x00000010
#define MCCI_PHY0_COM_REG_16_RESET       0x00000000

__INLINE void mcci_phy0_com_reg_16_set(uint32_t value)
{
	REG_PL_WR(MCCI_PHY0_COM_REG_16_ADDR, value);
}

// field definitions
#define MCCI_PHY0_COM_REG_16_COM_REG_MASK    ((uint32_t)0xFFFFFFFF)
#define MCCI_PHY0_COM_REG_16_COM_REG_LSB    0
#define MCCI_PHY0_COM_REG_16_COM_REG_WIDTH    ((uint32_t)0x00000020)

#define MCCI_PHY0_COM_REG_16_COM_REG_RST    0x0

__INLINE void mcci_phy0_com_reg_16_com_reg_setf(uint32_t comreg)
{
	ASSERT_ERR((((uint32_t)comreg << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MCCI_PHY0_COM_REG_16_ADDR, (uint32_t)comreg << 0);
}

/**
 * @brief COM_REG_17 register definition
 *  Messaging memory register 17 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 COM_REG                   0x0
 * </pre>
 */
#define MCCI_PHY0_COM_REG_17_ADDR        (REG_MCCI_PHY0_BASE_ADDR+0x00000044)
#define MCCI_PHY0_COM_REG_17_OFFSET      0x00000044
#define MCCI_PHY0_COM_REG_17_INDEX       0x00000011
#define MCCI_PHY0_COM_REG_17_RESET       0x00000000

__INLINE void mcci_phy0_com_reg_17_set(uint32_t value)
{
	REG_PL_WR(MCCI_PHY0_COM_REG_17_ADDR, value);
}

// field definitions
#define MCCI_PHY0_COM_REG_17_COM_REG_MASK    ((uint32_t)0xFFFFFFFF)
#define MCCI_PHY0_COM_REG_17_COM_REG_LSB    0
#define MCCI_PHY0_COM_REG_17_COM_REG_WIDTH    ((uint32_t)0x00000020)

#define MCCI_PHY0_COM_REG_17_COM_REG_RST    0x0

__INLINE void mcci_phy0_com_reg_17_com_reg_setf(uint32_t comreg)
{
	ASSERT_ERR((((uint32_t)comreg << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MCCI_PHY0_COM_REG_17_ADDR, (uint32_t)comreg << 0);
}

/**
 * @brief COM_REG_18 register definition
 *  Messaging memory register 18 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 COM_REG                   0x0
 * </pre>
 */
#define MCCI_PHY0_COM_REG_18_ADDR        (REG_MCCI_PHY0_BASE_ADDR+0x00000048)
#define MCCI_PHY0_COM_REG_18_OFFSET      0x00000048
#define MCCI_PHY0_COM_REG_18_INDEX       0x00000012
#define MCCI_PHY0_COM_REG_18_RESET       0x00000000

__INLINE void mcci_phy0_com_reg_18_set(uint32_t value)
{
	REG_PL_WR(MCCI_PHY0_COM_REG_18_ADDR, value);
}

// field definitions
#define MCCI_PHY0_COM_REG_18_COM_REG_MASK    ((uint32_t)0xFFFFFFFF)
#define MCCI_PHY0_COM_REG_18_COM_REG_LSB    0
#define MCCI_PHY0_COM_REG_18_COM_REG_WIDTH    ((uint32_t)0x00000020)

#define MCCI_PHY0_COM_REG_18_COM_REG_RST    0x0

__INLINE void mcci_phy0_com_reg_18_com_reg_setf(uint32_t comreg)
{
	ASSERT_ERR((((uint32_t)comreg << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MCCI_PHY0_COM_REG_18_ADDR, (uint32_t)comreg << 0);
}

/**
 * @brief COM_REG_19 register definition
 *  Messaging memory register 19 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 COM_REG                   0x0
 * </pre>
 */
#define MCCI_PHY0_COM_REG_19_ADDR        (REG_MCCI_PHY0_BASE_ADDR+0x0000004C)
#define MCCI_PHY0_COM_REG_19_OFFSET      0x0000004C
#define MCCI_PHY0_COM_REG_19_INDEX       0x00000013
#define MCCI_PHY0_COM_REG_19_RESET       0x00000000

__INLINE void mcci_phy0_com_reg_19_set(uint32_t value)
{
	REG_PL_WR(MCCI_PHY0_COM_REG_19_ADDR, value);
}

// field definitions
#define MCCI_PHY0_COM_REG_19_COM_REG_MASK    ((uint32_t)0xFFFFFFFF)
#define MCCI_PHY0_COM_REG_19_COM_REG_LSB    0
#define MCCI_PHY0_COM_REG_19_COM_REG_WIDTH    ((uint32_t)0x00000020)

#define MCCI_PHY0_COM_REG_19_COM_REG_RST    0x0

__INLINE void mcci_phy0_com_reg_19_com_reg_setf(uint32_t comreg)
{
	ASSERT_ERR((((uint32_t)comreg << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MCCI_PHY0_COM_REG_19_ADDR, (uint32_t)comreg << 0);
}

/**
 * @brief COM_REG_20 register definition
 *  Messaging memory register 20 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 COM_REG                   0x0
 * </pre>
 */
#define MCCI_PHY0_COM_REG_20_ADDR        (REG_MCCI_PHY0_BASE_ADDR+0x00000050)
#define MCCI_PHY0_COM_REG_20_OFFSET      0x00000050
#define MCCI_PHY0_COM_REG_20_INDEX       0x00000014
#define MCCI_PHY0_COM_REG_20_RESET       0x00000000

__INLINE void mcci_phy0_com_reg_20_set(uint32_t value)
{
	REG_PL_WR(MCCI_PHY0_COM_REG_20_ADDR, value);
}

// field definitions
#define MCCI_PHY0_COM_REG_20_COM_REG_MASK    ((uint32_t)0xFFFFFFFF)
#define MCCI_PHY0_COM_REG_20_COM_REG_LSB    0
#define MCCI_PHY0_COM_REG_20_COM_REG_WIDTH    ((uint32_t)0x00000020)

#define MCCI_PHY0_COM_REG_20_COM_REG_RST    0x0

__INLINE void mcci_phy0_com_reg_20_com_reg_setf(uint32_t comreg)
{
	ASSERT_ERR((((uint32_t)comreg << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MCCI_PHY0_COM_REG_20_ADDR, (uint32_t)comreg << 0);
}

/**
 * @brief COM_REG_21 register definition
 *  Messaging memory register 21 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 COM_REG                   0x0
 * </pre>
 */
#define MCCI_PHY0_COM_REG_21_ADDR        (REG_MCCI_PHY0_BASE_ADDR+0x00000054)
#define MCCI_PHY0_COM_REG_21_OFFSET      0x00000054
#define MCCI_PHY0_COM_REG_21_INDEX       0x00000015
#define MCCI_PHY0_COM_REG_21_RESET       0x00000000

__INLINE void mcci_phy0_com_reg_21_set(uint32_t value)
{
	REG_PL_WR(MCCI_PHY0_COM_REG_21_ADDR, value);
}

// field definitions
#define MCCI_PHY0_COM_REG_21_COM_REG_MASK    ((uint32_t)0xFFFFFFFF)
#define MCCI_PHY0_COM_REG_21_COM_REG_LSB    0
#define MCCI_PHY0_COM_REG_21_COM_REG_WIDTH    ((uint32_t)0x00000020)

#define MCCI_PHY0_COM_REG_21_COM_REG_RST    0x0

__INLINE void mcci_phy0_com_reg_21_com_reg_setf(uint32_t comreg)
{
	ASSERT_ERR((((uint32_t)comreg << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MCCI_PHY0_COM_REG_21_ADDR, (uint32_t)comreg << 0);
}

/**
 * @brief COM_REG_22 register definition
 *  Messaging memory register 22 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 COM_REG                   0x0
 * </pre>
 */
#define MCCI_PHY0_COM_REG_22_ADDR        (REG_MCCI_PHY0_BASE_ADDR+0x00000058)
#define MCCI_PHY0_COM_REG_22_OFFSET      0x00000058
#define MCCI_PHY0_COM_REG_22_INDEX       0x00000016
#define MCCI_PHY0_COM_REG_22_RESET       0x00000000

__INLINE void mcci_phy0_com_reg_22_set(uint32_t value)
{
	REG_PL_WR(MCCI_PHY0_COM_REG_22_ADDR, value);
}

// field definitions
#define MCCI_PHY0_COM_REG_22_COM_REG_MASK    ((uint32_t)0xFFFFFFFF)
#define MCCI_PHY0_COM_REG_22_COM_REG_LSB    0
#define MCCI_PHY0_COM_REG_22_COM_REG_WIDTH    ((uint32_t)0x00000020)

#define MCCI_PHY0_COM_REG_22_COM_REG_RST    0x0

__INLINE void mcci_phy0_com_reg_22_com_reg_setf(uint32_t comreg)
{
	ASSERT_ERR((((uint32_t)comreg << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MCCI_PHY0_COM_REG_22_ADDR, (uint32_t)comreg << 0);
}

/**
 * @brief COM_REG_23 register definition
 *  Messaging memory register 23 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 COM_REG                   0x0
 * </pre>
 */
#define MCCI_PHY0_COM_REG_23_ADDR        (REG_MCCI_PHY0_BASE_ADDR+0x0000005C)
#define MCCI_PHY0_COM_REG_23_OFFSET      0x0000005C
#define MCCI_PHY0_COM_REG_23_INDEX       0x00000017
#define MCCI_PHY0_COM_REG_23_RESET       0x00000000

__INLINE void mcci_phy0_com_reg_23_set(uint32_t value)
{
	REG_PL_WR(MCCI_PHY0_COM_REG_23_ADDR, value);
}

// field definitions
#define MCCI_PHY0_COM_REG_23_COM_REG_MASK    ((uint32_t)0xFFFFFFFF)
#define MCCI_PHY0_COM_REG_23_COM_REG_LSB    0
#define MCCI_PHY0_COM_REG_23_COM_REG_WIDTH    ((uint32_t)0x00000020)

#define MCCI_PHY0_COM_REG_23_COM_REG_RST    0x0

__INLINE void mcci_phy0_com_reg_23_com_reg_setf(uint32_t comreg)
{
	ASSERT_ERR((((uint32_t)comreg << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MCCI_PHY0_COM_REG_23_ADDR, (uint32_t)comreg << 0);
}

/**
 * @brief COM_REG_24 register definition
 *  Messaging memory register 24 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 COM_REG                   0x0
 * </pre>
 */
#define MCCI_PHY0_COM_REG_24_ADDR        (REG_MCCI_PHY0_BASE_ADDR+0x00000060)
#define MCCI_PHY0_COM_REG_24_OFFSET      0x00000060
#define MCCI_PHY0_COM_REG_24_INDEX       0x00000018
#define MCCI_PHY0_COM_REG_24_RESET       0x00000000

__INLINE void mcci_phy0_com_reg_24_set(uint32_t value)
{
	REG_PL_WR(MCCI_PHY0_COM_REG_24_ADDR, value);
}

// field definitions
#define MCCI_PHY0_COM_REG_24_COM_REG_MASK    ((uint32_t)0xFFFFFFFF)
#define MCCI_PHY0_COM_REG_24_COM_REG_LSB    0
#define MCCI_PHY0_COM_REG_24_COM_REG_WIDTH    ((uint32_t)0x00000020)

#define MCCI_PHY0_COM_REG_24_COM_REG_RST    0x0

__INLINE void mcci_phy0_com_reg_24_com_reg_setf(uint32_t comreg)
{
	ASSERT_ERR((((uint32_t)comreg << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MCCI_PHY0_COM_REG_24_ADDR, (uint32_t)comreg << 0);
}

/**
 * @brief COM_REG_25 register definition
 *  Messaging memory register 25 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 COM_REG                   0x0
 * </pre>
 */
#define MCCI_PHY0_COM_REG_25_ADDR        (REG_MCCI_PHY0_BASE_ADDR+0x00000064)
#define MCCI_PHY0_COM_REG_25_OFFSET      0x00000064
#define MCCI_PHY0_COM_REG_25_INDEX       0x00000019
#define MCCI_PHY0_COM_REG_25_RESET       0x00000000

__INLINE void mcci_phy0_com_reg_25_set(uint32_t value)
{
	REG_PL_WR(MCCI_PHY0_COM_REG_25_ADDR, value);
}

// field definitions
#define MCCI_PHY0_COM_REG_25_COM_REG_MASK    ((uint32_t)0xFFFFFFFF)
#define MCCI_PHY0_COM_REG_25_COM_REG_LSB    0
#define MCCI_PHY0_COM_REG_25_COM_REG_WIDTH    ((uint32_t)0x00000020)

#define MCCI_PHY0_COM_REG_25_COM_REG_RST    0x0

__INLINE void mcci_phy0_com_reg_25_com_reg_setf(uint32_t comreg)
{
	ASSERT_ERR((((uint32_t)comreg << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MCCI_PHY0_COM_REG_25_ADDR, (uint32_t)comreg << 0);
}

/**
 * @brief COM_REG_26 register definition
 *  Messaging memory register 26 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 COM_REG                   0x0
 * </pre>
 */
#define MCCI_PHY0_COM_REG_26_ADDR        (REG_MCCI_PHY0_BASE_ADDR+0x00000068)
#define MCCI_PHY0_COM_REG_26_OFFSET      0x00000068
#define MCCI_PHY0_COM_REG_26_INDEX       0x0000001A
#define MCCI_PHY0_COM_REG_26_RESET       0x00000000

__INLINE void mcci_phy0_com_reg_26_set(uint32_t value)
{
	REG_PL_WR(MCCI_PHY0_COM_REG_26_ADDR, value);
}

// field definitions
#define MCCI_PHY0_COM_REG_26_COM_REG_MASK    ((uint32_t)0xFFFFFFFF)
#define MCCI_PHY0_COM_REG_26_COM_REG_LSB    0
#define MCCI_PHY0_COM_REG_26_COM_REG_WIDTH    ((uint32_t)0x00000020)

#define MCCI_PHY0_COM_REG_26_COM_REG_RST    0x0

__INLINE void mcci_phy0_com_reg_26_com_reg_setf(uint32_t comreg)
{
	ASSERT_ERR((((uint32_t)comreg << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MCCI_PHY0_COM_REG_26_ADDR, (uint32_t)comreg << 0);
}

/**
 * @brief COM_REG_27 register definition
 *  Messaging memory register 27 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 COM_REG                   0x0
 * </pre>
 */
#define MCCI_PHY0_COM_REG_27_ADDR        (REG_MCCI_PHY0_BASE_ADDR+0x0000006C)
#define MCCI_PHY0_COM_REG_27_OFFSET      0x0000006C
#define MCCI_PHY0_COM_REG_27_INDEX       0x0000001B
#define MCCI_PHY0_COM_REG_27_RESET       0x00000000

__INLINE void mcci_phy0_com_reg_27_set(uint32_t value)
{
	REG_PL_WR(MCCI_PHY0_COM_REG_27_ADDR, value);
}

// field definitions
#define MCCI_PHY0_COM_REG_27_COM_REG_MASK    ((uint32_t)0xFFFFFFFF)
#define MCCI_PHY0_COM_REG_27_COM_REG_LSB    0
#define MCCI_PHY0_COM_REG_27_COM_REG_WIDTH    ((uint32_t)0x00000020)

#define MCCI_PHY0_COM_REG_27_COM_REG_RST    0x0

__INLINE void mcci_phy0_com_reg_27_com_reg_setf(uint32_t comreg)
{
	ASSERT_ERR((((uint32_t)comreg << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MCCI_PHY0_COM_REG_27_ADDR, (uint32_t)comreg << 0);
}

/**
 * @brief COM_REG_28 register definition
 *  Messaging memory register 28 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 COM_REG                   0x0
 * </pre>
 */
#define MCCI_PHY0_COM_REG_28_ADDR        (REG_MCCI_PHY0_BASE_ADDR+0x00000070)
#define MCCI_PHY0_COM_REG_28_OFFSET      0x00000070
#define MCCI_PHY0_COM_REG_28_INDEX       0x0000001C
#define MCCI_PHY0_COM_REG_28_RESET       0x00000000

__INLINE void mcci_phy0_com_reg_28_set(uint32_t value)
{
	REG_PL_WR(MCCI_PHY0_COM_REG_28_ADDR, value);
}

// field definitions
#define MCCI_PHY0_COM_REG_28_COM_REG_MASK    ((uint32_t)0xFFFFFFFF)
#define MCCI_PHY0_COM_REG_28_COM_REG_LSB    0
#define MCCI_PHY0_COM_REG_28_COM_REG_WIDTH    ((uint32_t)0x00000020)

#define MCCI_PHY0_COM_REG_28_COM_REG_RST    0x0

__INLINE void mcci_phy0_com_reg_28_com_reg_setf(uint32_t comreg)
{
	ASSERT_ERR((((uint32_t)comreg << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MCCI_PHY0_COM_REG_28_ADDR, (uint32_t)comreg << 0);
}

/**
 * @brief COM_REG_29 register definition
 *  Messaging memory register 29 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 COM_REG                   0x0
 * </pre>
 */
#define MCCI_PHY0_COM_REG_29_ADDR        (REG_MCCI_PHY0_BASE_ADDR+0x00000074)
#define MCCI_PHY0_COM_REG_29_OFFSET      0x00000074
#define MCCI_PHY0_COM_REG_29_INDEX       0x0000001D
#define MCCI_PHY0_COM_REG_29_RESET       0x00000000

__INLINE void mcci_phy0_com_reg_29_set(uint32_t value)
{
	REG_PL_WR(MCCI_PHY0_COM_REG_29_ADDR, value);
}

// field definitions
#define MCCI_PHY0_COM_REG_29_COM_REG_MASK    ((uint32_t)0xFFFFFFFF)
#define MCCI_PHY0_COM_REG_29_COM_REG_LSB    0
#define MCCI_PHY0_COM_REG_29_COM_REG_WIDTH    ((uint32_t)0x00000020)

#define MCCI_PHY0_COM_REG_29_COM_REG_RST    0x0

__INLINE void mcci_phy0_com_reg_29_com_reg_setf(uint32_t comreg)
{
	ASSERT_ERR((((uint32_t)comreg << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MCCI_PHY0_COM_REG_29_ADDR, (uint32_t)comreg << 0);
}

/**
 * @brief COM_REG_30 register definition
 *  Messaging memory register 30 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 COM_REG                   0x0
 * </pre>
 */
#define MCCI_PHY0_COM_REG_30_ADDR        (REG_MCCI_PHY0_BASE_ADDR+0x00000078)
#define MCCI_PHY0_COM_REG_30_OFFSET      0x00000078
#define MCCI_PHY0_COM_REG_30_INDEX       0x0000001E
#define MCCI_PHY0_COM_REG_30_RESET       0x00000000

__INLINE void mcci_phy0_com_reg_30_set(uint32_t value)
{
	REG_PL_WR(MCCI_PHY0_COM_REG_30_ADDR, value);
}

// field definitions
#define MCCI_PHY0_COM_REG_30_COM_REG_MASK    ((uint32_t)0xFFFFFFFF)
#define MCCI_PHY0_COM_REG_30_COM_REG_LSB    0
#define MCCI_PHY0_COM_REG_30_COM_REG_WIDTH    ((uint32_t)0x00000020)

#define MCCI_PHY0_COM_REG_30_COM_REG_RST    0x0

__INLINE void mcci_phy0_com_reg_30_com_reg_setf(uint32_t comreg)
{
	ASSERT_ERR((((uint32_t)comreg << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MCCI_PHY0_COM_REG_30_ADDR, (uint32_t)comreg << 0);
}

/**
 * @brief COM_REG_31 register definition
 *  Messaging memory register 31 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 COM_REG                   0x0
 * </pre>
 */
#define MCCI_PHY0_COM_REG_31_ADDR        (REG_MCCI_PHY0_BASE_ADDR+0x0000007C)
#define MCCI_PHY0_COM_REG_31_OFFSET      0x0000007C
#define MCCI_PHY0_COM_REG_31_INDEX       0x0000001F
#define MCCI_PHY0_COM_REG_31_RESET       0x00000000

__INLINE void mcci_phy0_com_reg_31_set(uint32_t value)
{
	REG_PL_WR(MCCI_PHY0_COM_REG_31_ADDR, value);
}

// field definitions
#define MCCI_PHY0_COM_REG_31_COM_REG_MASK    ((uint32_t)0xFFFFFFFF)
#define MCCI_PHY0_COM_REG_31_COM_REG_LSB    0
#define MCCI_PHY0_COM_REG_31_COM_REG_WIDTH    ((uint32_t)0x00000020)

#define MCCI_PHY0_COM_REG_31_COM_REG_RST    0x0

__INLINE void mcci_phy0_com_reg_31_com_reg_setf(uint32_t comreg)
{
	ASSERT_ERR((((uint32_t)comreg << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MCCI_PHY0_COM_REG_31_ADDR, (uint32_t)comreg << 0);
}

/**
 * @brief MSS_PDEA register definition
 *  PDMA external source address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PDEA                      0x0
 * </pre>
 */
#define MCCI_PHY0_MSS_PDEA_ADDR        (REG_MCCI_PHY0_BASE_ADDR+0x00002008)
#define MCCI_PHY0_MSS_PDEA_OFFSET      0x00002008
#define MCCI_PHY0_MSS_PDEA_INDEX       0x00000802
#define MCCI_PHY0_MSS_PDEA_RESET       0x00000000

__INLINE uint32_t  mcci_phy0_mss_pdea_get(void)
{
	return REG_PL_RD(MCCI_PHY0_MSS_PDEA_ADDR);
}

__INLINE void mcci_phy0_mss_pdea_set(uint32_t value)
{
	REG_PL_WR(MCCI_PHY0_MSS_PDEA_ADDR, value);
}

// field definitions
#define MCCI_PHY0_MSS_PDEA_PDEA_MASK        ((uint32_t)0xFFFFFFFF)
#define MCCI_PHY0_MSS_PDEA_PDEA_LSB         0
#define MCCI_PHY0_MSS_PDEA_PDEA_WIDTH       ((uint32_t)0x00000020)

#define MCCI_PHY0_MSS_PDEA_PDEA_RST         0x0

__INLINE uint32_t mcci_phy0_mss_pdea_pdea_getf(void)
{
	uint32_t localVal = REG_PL_RD(MCCI_PHY0_MSS_PDEA_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void mcci_phy0_mss_pdea_pdea_setf(uint32_t pdea)
{
	ASSERT_ERR((((uint32_t)pdea << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MCCI_PHY0_MSS_PDEA_ADDR, (uint32_t)pdea << 0);
}

/**
 * @brief MSS_PDIA register definition
 *  PDMA internal destination address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PDIA                      0x0
 * </pre>
 */
#define MCCI_PHY0_MSS_PDIA_ADDR        (REG_MCCI_PHY0_BASE_ADDR+0x0000200C)
#define MCCI_PHY0_MSS_PDIA_OFFSET      0x0000200C
#define MCCI_PHY0_MSS_PDIA_INDEX       0x00000803
#define MCCI_PHY0_MSS_PDIA_RESET       0x00000000

__INLINE uint32_t  mcci_phy0_mss_pdia_get(void)
{
	return REG_PL_RD(MCCI_PHY0_MSS_PDIA_ADDR);
}

__INLINE void mcci_phy0_mss_pdia_set(uint32_t value)
{
	REG_PL_WR(MCCI_PHY0_MSS_PDIA_ADDR, value);
}

// field definitions
#define MCCI_PHY0_MSS_PDIA_PDIA_MASK        ((uint32_t)0xFFFFFFFF)
#define MCCI_PHY0_MSS_PDIA_PDIA_LSB         0
#define MCCI_PHY0_MSS_PDIA_PDIA_WIDTH       ((uint32_t)0x00000020)

#define MCCI_PHY0_MSS_PDIA_PDIA_RST         0x0

__INLINE uint32_t mcci_phy0_mss_pdia_pdia_getf(void)
{
	uint32_t localVal = REG_PL_RD(MCCI_PHY0_MSS_PDIA_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void mcci_phy0_mss_pdia_pdia_setf(uint32_t pdia)
{
	ASSERT_ERR((((uint32_t)pdia << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MCCI_PHY0_MSS_PDIA_ADDR, (uint32_t)pdia << 0);
}

/**
 * @brief MSS_PDTC register definition
 *  PDMA transfer control register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    PDIE                      0              
 *    30    CAC_INV                   0              
 *    29    PDST                      0              
 *    28:27 OUTS                      0x0
 *    26:25 PBSZ                      0x0
 *    24:20 Reserved                  0x0
 *    19:00 PDTC                      0x0
 * </pre>
 */
#define MCCI_PHY0_MSS_PDTC_ADDR        (REG_MCCI_PHY0_BASE_ADDR+0x00002010)
#define MCCI_PHY0_MSS_PDTC_OFFSET      0x00002010
#define MCCI_PHY0_MSS_PDTC_INDEX       0x00000804
#define MCCI_PHY0_MSS_PDTC_RESET       0x00000000

__INLINE uint32_t  mcci_phy0_mss_pdtc_get(void)
{
	return REG_PL_RD(MCCI_PHY0_MSS_PDTC_ADDR);
}

__INLINE void mcci_phy0_mss_pdtc_set(uint32_t value)
{
	REG_PL_WR(MCCI_PHY0_MSS_PDTC_ADDR, value);
}

// field definitions
#define MCCI_PHY0_MSS_PDTC_PDIE_BIT         ((uint32_t)0x80000000)
#define MCCI_PHY0_MSS_PDTC_PDIE_POS         31
#define MCCI_PHY0_MSS_PDTC_CAC_INV_BIT      ((uint32_t)0x40000000)
#define MCCI_PHY0_MSS_PDTC_CAC_INV_POS      30
#define MCCI_PHY0_MSS_PDTC_PDST_BIT         ((uint32_t)0x20000000)
#define MCCI_PHY0_MSS_PDTC_PDST_POS         29
#define MCCI_PHY0_MSS_PDTC_OUTS_MASK        ((uint32_t)0x18000000)
#define MCCI_PHY0_MSS_PDTC_OUTS_LSB         27
#define MCCI_PHY0_MSS_PDTC_OUTS_WIDTH       ((uint32_t)0x00000002)
#define MCCI_PHY0_MSS_PDTC_PBSZ_MASK        ((uint32_t)0x06000000)
#define MCCI_PHY0_MSS_PDTC_PBSZ_LSB         25
#define MCCI_PHY0_MSS_PDTC_PBSZ_WIDTH       ((uint32_t)0x00000002)
#define MCCI_PHY0_MSS_PDTC_RESERVED_MASK    ((uint32_t)0x01F00000)
#define MCCI_PHY0_MSS_PDTC_RESERVED_LSB     20
#define MCCI_PHY0_MSS_PDTC_RESERVED_WIDTH    ((uint32_t)0x00000005)
#define MCCI_PHY0_MSS_PDTC_PDTC_MASK        ((uint32_t)0x000FFFFF)
#define MCCI_PHY0_MSS_PDTC_PDTC_LSB         0
#define MCCI_PHY0_MSS_PDTC_PDTC_WIDTH       ((uint32_t)0x00000014)

#define MCCI_PHY0_MSS_PDTC_PDIE_RST         0x0
#define MCCI_PHY0_MSS_PDTC_CAC_INV_RST      0x0
#define MCCI_PHY0_MSS_PDTC_PDST_RST         0x0
#define MCCI_PHY0_MSS_PDTC_OUTS_RST         0x0
#define MCCI_PHY0_MSS_PDTC_PBSZ_RST         0x0
#define MCCI_PHY0_MSS_PDTC_RESERVED_RST     0x0
#define MCCI_PHY0_MSS_PDTC_PDTC_RST         0x0

__INLINE void mcci_phy0_mss_pdtc_pack(uint8_t pdie, uint8_t cac_inv, uint8_t pdst, uint8_t outs, uint8_t pbsz, uint8_t reserved, uint32_t pdtc)
{
	ASSERT_ERR((((uint32_t)pdie << 31) & ~((uint32_t)0x80000000)) == 0);
	ASSERT_ERR((((uint32_t)cac_inv << 30) & ~((uint32_t)0x40000000)) == 0);
	ASSERT_ERR((((uint32_t)pdst << 29) & ~((uint32_t)0x20000000)) == 0);
	ASSERT_ERR((((uint32_t)outs << 27) & ~((uint32_t)0x18000000)) == 0);
	ASSERT_ERR((((uint32_t)pbsz << 25) & ~((uint32_t)0x06000000)) == 0);
	ASSERT_ERR((((uint32_t)reserved << 20) & ~((uint32_t)0x01F00000)) == 0);
	ASSERT_ERR((((uint32_t)pdtc << 0) & ~((uint32_t)0x000FFFFF)) == 0);
	REG_PL_WR(MCCI_PHY0_MSS_PDTC_ADDR,  ((uint32_t)pdie << 31) |((uint32_t)cac_inv << 30) |((uint32_t)pdst << 29) |((uint32_t)outs << 27) |((uint32_t)pbsz << 25) |((uint32_t)reserved << 20) |((uint32_t)pdtc << 0));
}

__INLINE void mcci_phy0_mss_pdtc_unpack(uint8_t* pdie, uint8_t* cac_inv, uint8_t* pdst, uint8_t* outs, uint8_t* pbsz, uint8_t* reserved, uint32_t* pdtc)
{
	uint32_t localVal = REG_PL_RD(MCCI_PHY0_MSS_PDTC_ADDR);

	*pdie = (localVal & ((uint32_t)0x80000000)) >>  31;
	*cac_inv = (localVal & ((uint32_t)0x40000000)) >>  30;
	*pdst = (localVal & ((uint32_t)0x20000000)) >>  29;
	*outs = (localVal & ((uint32_t)0x18000000)) >>  27;
	*pbsz = (localVal & ((uint32_t)0x06000000)) >>  25;
	*reserved = (localVal & ((uint32_t)0x01F00000)) >>  20;
	*pdtc = (localVal & ((uint32_t)0x000FFFFF)) >>  0;
}

__INLINE uint8_t mcci_phy0_mss_pdtc_pdie_getf(void)
{
	uint32_t localVal = REG_PL_RD(MCCI_PHY0_MSS_PDTC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE void mcci_phy0_mss_pdtc_pdie_setf(uint8_t pdie)
{
	ASSERT_ERR((((uint32_t)pdie << 31) & ~((uint32_t)0x80000000)) == 0);
	REG_PL_WR(MCCI_PHY0_MSS_PDTC_ADDR, (REG_PL_RD(MCCI_PHY0_MSS_PDTC_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)pdie <<31));
}
__INLINE uint8_t mcci_phy0_mss_pdtc_cac_inv_getf(void)
{
	uint32_t localVal = REG_PL_RD(MCCI_PHY0_MSS_PDTC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x40000000)) >> 30);
}
__INLINE void mcci_phy0_mss_pdtc_cac_inv_setf(uint8_t cacinv)
{
	ASSERT_ERR((((uint32_t)cacinv << 30) & ~((uint32_t)0x40000000)) == 0);
	REG_PL_WR(MCCI_PHY0_MSS_PDTC_ADDR, (REG_PL_RD(MCCI_PHY0_MSS_PDTC_ADDR) & ~((uint32_t)0x40000000)) | ((uint32_t)cacinv <<30));
}
__INLINE uint8_t mcci_phy0_mss_pdtc_pdst_getf(void)
{
	uint32_t localVal = REG_PL_RD(MCCI_PHY0_MSS_PDTC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x20000000)) >> 29);
}
__INLINE uint8_t mcci_phy0_mss_pdtc_outs_getf(void)
{
	uint32_t localVal = REG_PL_RD(MCCI_PHY0_MSS_PDTC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x18000000)) >> 27);
}
__INLINE void mcci_phy0_mss_pdtc_outs_setf(uint8_t outs)
{
	ASSERT_ERR((((uint32_t)outs << 27) & ~((uint32_t)0x18000000)) == 0);
	REG_PL_WR(MCCI_PHY0_MSS_PDTC_ADDR, (REG_PL_RD(MCCI_PHY0_MSS_PDTC_ADDR) & ~((uint32_t)0x18000000)) | ((uint32_t)outs <<27));
}
__INLINE uint8_t mcci_phy0_mss_pdtc_pbsz_getf(void)
{
	uint32_t localVal = REG_PL_RD(MCCI_PHY0_MSS_PDTC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x06000000)) >> 25);
}
__INLINE void mcci_phy0_mss_pdtc_pbsz_setf(uint8_t pbsz)
{
	ASSERT_ERR((((uint32_t)pbsz << 25) & ~((uint32_t)0x06000000)) == 0);
	REG_PL_WR(MCCI_PHY0_MSS_PDTC_ADDR, (REG_PL_RD(MCCI_PHY0_MSS_PDTC_ADDR) & ~((uint32_t)0x06000000)) | ((uint32_t)pbsz <<25));
}
__INLINE uint8_t mcci_phy0_mss_pdtc_reserved_getf(void)
{
	uint32_t localVal = REG_PL_RD(MCCI_PHY0_MSS_PDTC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01F00000)) >> 20);
}
__INLINE void mcci_phy0_mss_pdtc_reserved_setf(uint8_t reserved)
{
	ASSERT_ERR((((uint32_t)reserved << 20) & ~((uint32_t)0x01F00000)) == 0);
	REG_PL_WR(MCCI_PHY0_MSS_PDTC_ADDR, (REG_PL_RD(MCCI_PHY0_MSS_PDTC_ADDR) & ~((uint32_t)0x01F00000)) | ((uint32_t)reserved <<20));
}
__INLINE uint32_t mcci_phy0_mss_pdtc_pdtc_getf(void)
{
	uint32_t localVal = REG_PL_RD(MCCI_PHY0_MSS_PDTC_ADDR);
	return (uint32_t)((localVal & ((uint32_t)0x000FFFFF)) >> 0);
}
__INLINE void mcci_phy0_mss_pdtc_pdtc_setf(uint32_t pdtc)
{
	ASSERT_ERR((((uint32_t)pdtc << 0) & ~((uint32_t)0x000FFFFF)) == 0);
	REG_PL_WR(MCCI_PHY0_MSS_PDTC_ADDR, (REG_PL_RD(MCCI_PHY0_MSS_PDTC_ADDR) & ~((uint32_t)0x000FFFFF)) | ((uint32_t)pdtc <<0));
}


#undef DBG_FILEID
#endif //_REG_MCCI_PHY0_H_

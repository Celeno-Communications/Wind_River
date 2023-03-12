#ifndef _REG_LCU_PHY_H_
#define _REG_LCU_PHY_H_

#include <stdint.h>
#include "phy/_reg_lcu_phy.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define DBG_FILEID __REG_LCU_PHY__H__FILEID__

#define REG_LCU_PHY_COUNT  90


/**
 * @brief LCU_CH_0_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    CH0_EN                    0              
 * </pre>
 */
#define LCU_PHY_LCU_CH_0_EN_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000000)
#define LCU_PHY_LCU_CH_0_EN_OFFSET      0x00000000
#define LCU_PHY_LCU_CH_0_EN_INDEX       0x00000000
#define LCU_PHY_LCU_CH_0_EN_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_0_en_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_0_EN_ADDR);
}

__INLINE void lcu_phy_lcu_ch_0_en_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_0_EN_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_0_EN_CH_0_EN_BIT     ((uint32_t)0x00000001)
#define LCU_PHY_LCU_CH_0_EN_CH_0_EN_POS     0

#define LCU_PHY_LCU_CH_0_EN_CH_0_EN_RST     0x0

__INLINE uint8_t lcu_phy_lcu_ch_0_en_ch_0_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_0_EN_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_0_en_ch_0_en_setf(uint8_t ch0en)
{
	ASSERT_ERR((((uint32_t)ch0en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_0_EN_ADDR, (uint32_t)ch0en << 0);
}

/**
 * @brief LCU_CH_1_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    CH1_EN                    0              
 * </pre>
 */
#define LCU_PHY_LCU_CH_1_EN_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000004)
#define LCU_PHY_LCU_CH_1_EN_OFFSET      0x00000004
#define LCU_PHY_LCU_CH_1_EN_INDEX       0x00000001
#define LCU_PHY_LCU_CH_1_EN_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_1_en_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_1_EN_ADDR);
}

__INLINE void lcu_phy_lcu_ch_1_en_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_1_EN_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_1_EN_CH_1_EN_BIT     ((uint32_t)0x00000001)
#define LCU_PHY_LCU_CH_1_EN_CH_1_EN_POS     0

#define LCU_PHY_LCU_CH_1_EN_CH_1_EN_RST     0x0

__INLINE uint8_t lcu_phy_lcu_ch_1_en_ch_1_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_1_EN_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_1_en_ch_1_en_setf(uint8_t ch1en)
{
	ASSERT_ERR((((uint32_t)ch1en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_1_EN_ADDR, (uint32_t)ch1en << 0);
}

/**
 * @brief LCU_CH_0_CONF register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    11:08 CH0_TYPE                  0x0
 *    04    CH0_SIZE                  0              
 *    01:00 CH0_MODE                  0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_0_CONF_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000008)
#define LCU_PHY_LCU_CH_0_CONF_OFFSET      0x00000008
#define LCU_PHY_LCU_CH_0_CONF_INDEX       0x00000002
#define LCU_PHY_LCU_CH_0_CONF_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_0_conf_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_0_CONF_ADDR);
}

__INLINE void lcu_phy_lcu_ch_0_conf_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_0_CONF_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_0_CONF_CH_0_TYPE_MASK    ((uint32_t)0x00000F00)
#define LCU_PHY_LCU_CH_0_CONF_CH_0_TYPE_LSB    8
#define LCU_PHY_LCU_CH_0_CONF_CH_0_TYPE_WIDTH    ((uint32_t)0x00000004)
#define LCU_PHY_LCU_CH_0_CONF_CH_0_SIZE_BIT    ((uint32_t)0x00000010)
#define LCU_PHY_LCU_CH_0_CONF_CH_0_SIZE_POS    4
#define LCU_PHY_LCU_CH_0_CONF_CH_0_MODE_MASK    ((uint32_t)0x00000003)
#define LCU_PHY_LCU_CH_0_CONF_CH_0_MODE_LSB    0
#define LCU_PHY_LCU_CH_0_CONF_CH_0_MODE_WIDTH    ((uint32_t)0x00000002)

#define LCU_PHY_LCU_CH_0_CONF_CH_0_TYPE_RST    0x0
#define LCU_PHY_LCU_CH_0_CONF_CH_0_SIZE_RST    0x0
#define LCU_PHY_LCU_CH_0_CONF_CH_0_MODE_RST    0x0

__INLINE void lcu_phy_lcu_ch_0_conf_pack(uint8_t ch0_type, uint8_t ch0_size, uint8_t ch0_mode)
{
	ASSERT_ERR((((uint32_t)ch0_type << 8) & ~((uint32_t)0x00000F00)) == 0);
	ASSERT_ERR((((uint32_t)ch0_size << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)ch0_mode << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_0_CONF_ADDR,  ((uint32_t)ch0_type << 8) |((uint32_t)ch0_size << 4) |((uint32_t)ch0_mode << 0));
}

__INLINE void lcu_phy_lcu_ch_0_conf_unpack(uint8_t* ch0_type, uint8_t* ch0_size, uint8_t* ch0_mode)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_0_CONF_ADDR);

	*ch0_type = (localVal & ((uint32_t)0x00000F00)) >>  8;
	*ch0_size = (localVal & ((uint32_t)0x00000010)) >>  4;
	*ch0_mode = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint8_t lcu_phy_lcu_ch_0_conf_ch_0_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_0_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000F00)) >> 8);
}
__INLINE void lcu_phy_lcu_ch_0_conf_ch_0_type_setf(uint8_t ch0type)
{
	ASSERT_ERR((((uint32_t)ch0type << 8) & ~((uint32_t)0x00000F00)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_0_CONF_ADDR, (REG_PL_RD(LCU_PHY_LCU_CH_0_CONF_ADDR) & ~((uint32_t)0x00000F00)) | ((uint32_t)ch0type <<8));
}
__INLINE uint8_t lcu_phy_lcu_ch_0_conf_ch_0_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_0_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void lcu_phy_lcu_ch_0_conf_ch_0_size_setf(uint8_t ch0size)
{
	ASSERT_ERR((((uint32_t)ch0size << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_0_CONF_ADDR, (REG_PL_RD(LCU_PHY_LCU_CH_0_CONF_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)ch0size <<4));
}
__INLINE uint8_t lcu_phy_lcu_ch_0_conf_ch_0_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_0_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void lcu_phy_lcu_ch_0_conf_ch_0_mode_setf(uint8_t ch0mode)
{
	ASSERT_ERR((((uint32_t)ch0mode << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_0_CONF_ADDR, (REG_PL_RD(LCU_PHY_LCU_CH_0_CONF_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)ch0mode <<0));
}

/**
 * @brief LCU_CH_1_CONF register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    11:08 CH1_TYPE                  0x0
 *    04    CH1_SIZE                  0              
 *    01:00 CH1_MODE                  0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_1_CONF_ADDR        (REG_LCU_PHY_BASE_ADDR+0x0000000C)
#define LCU_PHY_LCU_CH_1_CONF_OFFSET      0x0000000C
#define LCU_PHY_LCU_CH_1_CONF_INDEX       0x00000003
#define LCU_PHY_LCU_CH_1_CONF_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_1_conf_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_1_CONF_ADDR);
}

__INLINE void lcu_phy_lcu_ch_1_conf_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_1_CONF_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_1_CONF_CH_1_TYPE_MASK    ((uint32_t)0x00000F00)
#define LCU_PHY_LCU_CH_1_CONF_CH_1_TYPE_LSB    8
#define LCU_PHY_LCU_CH_1_CONF_CH_1_TYPE_WIDTH    ((uint32_t)0x00000004)
#define LCU_PHY_LCU_CH_1_CONF_CH_1_SIZE_BIT    ((uint32_t)0x00000010)
#define LCU_PHY_LCU_CH_1_CONF_CH_1_SIZE_POS    4
#define LCU_PHY_LCU_CH_1_CONF_CH_1_MODE_MASK    ((uint32_t)0x00000003)
#define LCU_PHY_LCU_CH_1_CONF_CH_1_MODE_LSB    0
#define LCU_PHY_LCU_CH_1_CONF_CH_1_MODE_WIDTH    ((uint32_t)0x00000002)

#define LCU_PHY_LCU_CH_1_CONF_CH_1_TYPE_RST    0x0
#define LCU_PHY_LCU_CH_1_CONF_CH_1_SIZE_RST    0x0
#define LCU_PHY_LCU_CH_1_CONF_CH_1_MODE_RST    0x0

__INLINE void lcu_phy_lcu_ch_1_conf_pack(uint8_t ch1_type, uint8_t ch1_size, uint8_t ch1_mode)
{
	ASSERT_ERR((((uint32_t)ch1_type << 8) & ~((uint32_t)0x00000F00)) == 0);
	ASSERT_ERR((((uint32_t)ch1_size << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)ch1_mode << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_1_CONF_ADDR,  ((uint32_t)ch1_type << 8) |((uint32_t)ch1_size << 4) |((uint32_t)ch1_mode << 0));
}

__INLINE void lcu_phy_lcu_ch_1_conf_unpack(uint8_t* ch1_type, uint8_t* ch1_size, uint8_t* ch1_mode)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_1_CONF_ADDR);

	*ch1_type = (localVal & ((uint32_t)0x00000F00)) >>  8;
	*ch1_size = (localVal & ((uint32_t)0x00000010)) >>  4;
	*ch1_mode = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint8_t lcu_phy_lcu_ch_1_conf_ch_1_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_1_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000F00)) >> 8);
}
__INLINE void lcu_phy_lcu_ch_1_conf_ch_1_type_setf(uint8_t ch1type)
{
	ASSERT_ERR((((uint32_t)ch1type << 8) & ~((uint32_t)0x00000F00)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_1_CONF_ADDR, (REG_PL_RD(LCU_PHY_LCU_CH_1_CONF_ADDR) & ~((uint32_t)0x00000F00)) | ((uint32_t)ch1type <<8));
}
__INLINE uint8_t lcu_phy_lcu_ch_1_conf_ch_1_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_1_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE uint8_t lcu_phy_lcu_ch_1_conf_ch_1_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_1_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void lcu_phy_lcu_ch_1_conf_ch_1_mode_setf(uint8_t ch1mode)
{
	ASSERT_ERR((((uint32_t)ch1mode << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_1_CONF_ADDR, (REG_PL_RD(LCU_PHY_LCU_CH_1_CONF_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)ch1mode <<0));
}

/**
 * @brief LCU_CH_0_CHAINS_BITMAP register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01:00 CH0_CHAINS_BITMAP         0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_0_CHAINS_BITMAP_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000010)
#define LCU_PHY_LCU_CH_0_CHAINS_BITMAP_OFFSET      0x00000010
#define LCU_PHY_LCU_CH_0_CHAINS_BITMAP_INDEX       0x00000004
#define LCU_PHY_LCU_CH_0_CHAINS_BITMAP_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_0_chains_bitmap_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_0_CHAINS_BITMAP_ADDR);
}

__INLINE void lcu_phy_lcu_ch_0_chains_bitmap_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_0_CHAINS_BITMAP_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_0_CHAINS_BITMAP_CH_0_CHAINS_BITMAP_MASK    ((uint32_t)0x00000003)
#define LCU_PHY_LCU_CH_0_CHAINS_BITMAP_CH_0_CHAINS_BITMAP_LSB    0
#define LCU_PHY_LCU_CH_0_CHAINS_BITMAP_CH_0_CHAINS_BITMAP_WIDTH    ((uint32_t)0x00000002)

#define LCU_PHY_LCU_CH_0_CHAINS_BITMAP_CH_0_CHAINS_BITMAP_RST    0x0

__INLINE uint8_t lcu_phy_lcu_ch_0_chains_bitmap_ch_0_chains_bitmap_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_0_CHAINS_BITMAP_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_0_chains_bitmap_ch_0_chains_bitmap_setf(uint8_t ch0chainsbitmap)
{
	ASSERT_ERR((((uint32_t)ch0chainsbitmap << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_0_CHAINS_BITMAP_ADDR, (uint32_t)ch0chainsbitmap << 0);
}

/**
 * @brief LCU_CH_1_CHAINS_BITMAP register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01:00 CH1_CHAINS_BITMAP         0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_1_CHAINS_BITMAP_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000014)
#define LCU_PHY_LCU_CH_1_CHAINS_BITMAP_OFFSET      0x00000014
#define LCU_PHY_LCU_CH_1_CHAINS_BITMAP_INDEX       0x00000005
#define LCU_PHY_LCU_CH_1_CHAINS_BITMAP_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_1_chains_bitmap_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_1_CHAINS_BITMAP_ADDR);
}

__INLINE void lcu_phy_lcu_ch_1_chains_bitmap_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_1_CHAINS_BITMAP_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_1_CHAINS_BITMAP_CH_1_CHAINS_BITMAP_MASK    ((uint32_t)0x00000003)
#define LCU_PHY_LCU_CH_1_CHAINS_BITMAP_CH_1_CHAINS_BITMAP_LSB    0
#define LCU_PHY_LCU_CH_1_CHAINS_BITMAP_CH_1_CHAINS_BITMAP_WIDTH    ((uint32_t)0x00000002)

#define LCU_PHY_LCU_CH_1_CHAINS_BITMAP_CH_1_CHAINS_BITMAP_RST    0x0

__INLINE uint8_t lcu_phy_lcu_ch_1_chains_bitmap_ch_1_chains_bitmap_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_1_CHAINS_BITMAP_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_1_chains_bitmap_ch_1_chains_bitmap_setf(uint8_t ch1chainsbitmap)
{
	ASSERT_ERR((((uint32_t)ch1chainsbitmap << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_1_CHAINS_BITMAP_ADDR, (uint32_t)ch1chainsbitmap << 0);
}

/**
 * @brief LCU_CH_0_DECIMATION register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    02:00 CH0_DECIMATION            0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_0_DECIMATION_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000018)
#define LCU_PHY_LCU_CH_0_DECIMATION_OFFSET      0x00000018
#define LCU_PHY_LCU_CH_0_DECIMATION_INDEX       0x00000006
#define LCU_PHY_LCU_CH_0_DECIMATION_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_0_decimation_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_0_DECIMATION_ADDR);
}

__INLINE void lcu_phy_lcu_ch_0_decimation_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_0_DECIMATION_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_0_DECIMATION_CH_0_DECIMATION_MASK    ((uint32_t)0x00000007)
#define LCU_PHY_LCU_CH_0_DECIMATION_CH_0_DECIMATION_LSB    0
#define LCU_PHY_LCU_CH_0_DECIMATION_CH_0_DECIMATION_WIDTH    ((uint32_t)0x00000003)

#define LCU_PHY_LCU_CH_0_DECIMATION_CH_0_DECIMATION_RST    0x0

__INLINE uint8_t lcu_phy_lcu_ch_0_decimation_ch_0_decimation_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_0_DECIMATION_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_0_decimation_ch_0_decimation_setf(uint8_t ch0decimation)
{
	ASSERT_ERR((((uint32_t)ch0decimation << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_0_DECIMATION_ADDR, (uint32_t)ch0decimation << 0);
}

/**
 * @brief LCU_CH_1_DECIMATION register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    02:00 CH1_DECIMATION            0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_1_DECIMATION_ADDR        (REG_LCU_PHY_BASE_ADDR+0x0000001C)
#define LCU_PHY_LCU_CH_1_DECIMATION_OFFSET      0x0000001C
#define LCU_PHY_LCU_CH_1_DECIMATION_INDEX       0x00000007
#define LCU_PHY_LCU_CH_1_DECIMATION_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_1_decimation_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_1_DECIMATION_ADDR);
}

__INLINE void lcu_phy_lcu_ch_1_decimation_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_1_DECIMATION_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_1_DECIMATION_CH_1_DECIMATION_MASK    ((uint32_t)0x00000007)
#define LCU_PHY_LCU_CH_1_DECIMATION_CH_1_DECIMATION_LSB    0
#define LCU_PHY_LCU_CH_1_DECIMATION_CH_1_DECIMATION_WIDTH    ((uint32_t)0x00000003)

#define LCU_PHY_LCU_CH_1_DECIMATION_CH_1_DECIMATION_RST    0x0

__INLINE uint8_t lcu_phy_lcu_ch_1_decimation_ch_1_decimation_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_1_DECIMATION_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_1_decimation_ch_1_decimation_setf(uint8_t ch1decimation)
{
	ASSERT_ERR((((uint32_t)ch1decimation << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_1_DECIMATION_ADDR, (uint32_t)ch1decimation << 0);
}

/**
 * @brief LCU_CH_0_START register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    CH0_START                 0              
 * </pre>
 */
#define LCU_PHY_LCU_CH_0_START_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000020)
#define LCU_PHY_LCU_CH_0_START_OFFSET      0x00000020
#define LCU_PHY_LCU_CH_0_START_INDEX       0x00000008
#define LCU_PHY_LCU_CH_0_START_RESET       0x00000000

__INLINE void lcu_phy_lcu_ch_0_start_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_0_START_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_0_START_CH_0_START_BIT    ((uint32_t)0x00000001)
#define LCU_PHY_LCU_CH_0_START_CH_0_START_POS    0

#define LCU_PHY_LCU_CH_0_START_CH_0_START_RST    0x0

__INLINE void lcu_phy_lcu_ch_0_start_ch_0_start_setf(uint8_t ch0start)
{
	ASSERT_ERR((((uint32_t)ch0start << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_0_START_ADDR, (uint32_t)ch0start << 0);
}

/**
 * @brief LCU_CH_1_START register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    CH1_START                 0              
 * </pre>
 */
#define LCU_PHY_LCU_CH_1_START_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000024)
#define LCU_PHY_LCU_CH_1_START_OFFSET      0x00000024
#define LCU_PHY_LCU_CH_1_START_INDEX       0x00000009
#define LCU_PHY_LCU_CH_1_START_RESET       0x00000000

__INLINE void lcu_phy_lcu_ch_1_start_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_1_START_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_1_START_CH_1_START_BIT    ((uint32_t)0x00000001)
#define LCU_PHY_LCU_CH_1_START_CH_1_START_POS    0

#define LCU_PHY_LCU_CH_1_START_CH_1_START_RST    0x0

__INLINE void lcu_phy_lcu_ch_1_start_ch_1_start_setf(uint8_t ch1start)
{
	ASSERT_ERR((((uint32_t)ch1start << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_1_START_ADDR, (uint32_t)ch1start << 0);
}

/**
 * @brief LCU_CH_0_START_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01    CH0_EXT_STRT_EN           0              
 *    00    CH0_STRT_PTRN_EN          0              
 * </pre>
 */
#define LCU_PHY_LCU_CH_0_START_EN_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000028)
#define LCU_PHY_LCU_CH_0_START_EN_OFFSET      0x00000028
#define LCU_PHY_LCU_CH_0_START_EN_INDEX       0x0000000A
#define LCU_PHY_LCU_CH_0_START_EN_RESET       0x00000000

__INLINE void lcu_phy_lcu_ch_0_start_en_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_0_START_EN_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_0_START_EN_CH_0_EXT_STRT_EN_BIT    ((uint32_t)0x00000002)
#define LCU_PHY_LCU_CH_0_START_EN_CH_0_EXT_STRT_EN_POS    1
#define LCU_PHY_LCU_CH_0_START_EN_CH_0_STRT_PTRN_EN_BIT    ((uint32_t)0x00000001)
#define LCU_PHY_LCU_CH_0_START_EN_CH_0_STRT_PTRN_EN_POS    0

#define LCU_PHY_LCU_CH_0_START_EN_CH_0_EXT_STRT_EN_RST    0x0
#define LCU_PHY_LCU_CH_0_START_EN_CH_0_STRT_PTRN_EN_RST    0x0

__INLINE void lcu_phy_lcu_ch_0_start_en_pack(uint8_t ch0_ext_strt_en, uint8_t ch0_strt_ptrn_en)
{
	ASSERT_ERR((((uint32_t)ch0_ext_strt_en << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)ch0_strt_ptrn_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_0_START_EN_ADDR,  ((uint32_t)ch0_ext_strt_en << 1) |((uint32_t)ch0_strt_ptrn_en << 0));
}

__INLINE void lcu_phy_lcu_ch_0_start_en_ch_0_ext_strt_en_setf(uint8_t ch0extstrten)
{
	ASSERT_ERR((((uint32_t)ch0extstrten << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_0_START_EN_ADDR, (REG_PL_RD(LCU_PHY_LCU_CH_0_START_EN_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)ch0extstrten <<1));
}
__INLINE void lcu_phy_lcu_ch_0_start_en_ch_0_strt_ptrn_en_setf(uint8_t ch0strtptrnen)
{
	ASSERT_ERR((((uint32_t)ch0strtptrnen << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_0_START_EN_ADDR, (REG_PL_RD(LCU_PHY_LCU_CH_0_START_EN_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)ch0strtptrnen <<0));
}

/**
 * @brief LCU_CH_1_START_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    CH1_STRT_PTRN_EN          0              
 * </pre>
 */
#define LCU_PHY_LCU_CH_1_START_EN_ADDR        (REG_LCU_PHY_BASE_ADDR+0x0000002C)
#define LCU_PHY_LCU_CH_1_START_EN_OFFSET      0x0000002C
#define LCU_PHY_LCU_CH_1_START_EN_INDEX       0x0000000B
#define LCU_PHY_LCU_CH_1_START_EN_RESET       0x00000000

__INLINE void lcu_phy_lcu_ch_1_start_en_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_1_START_EN_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_1_START_EN_CH_1_STRT_PTRN_EN_BIT    ((uint32_t)0x00000001)
#define LCU_PHY_LCU_CH_1_START_EN_CH_1_STRT_PTRN_EN_POS    0

#define LCU_PHY_LCU_CH_1_START_EN_CH_1_STRT_PTRN_EN_RST    0x0

__INLINE void lcu_phy_lcu_ch_1_start_en_ch_1_strt_ptrn_en_setf(uint8_t ch1strtptrnen)
{
	ASSERT_ERR((((uint32_t)ch1strtptrnen << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_1_START_EN_ADDR, (uint32_t)ch1strtptrnen << 0);
}

/**
 * @brief LCU_CH_01_START_PTRN_REG_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STRT_PTRN            0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_0_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000030)
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_0_OFFSET      0x00000030
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_0_INDEX       0x0000000C
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_0_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_start_ptrn_reg_0_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_START_PTRN_REG_0_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_start_ptrn_reg_0_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_START_PTRN_REG_0_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_0_CH_01_STRT_PTRN_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_0_CH_01_STRT_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_0_CH_01_STRT_PTRN_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_START_PTRN_REG_0_CH_01_STRT_PTRN_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_start_ptrn_reg_0_ch_01_strt_ptrn_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_START_PTRN_REG_0_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_start_ptrn_reg_0_ch_01_strt_ptrn_setf(uint32_t ch01strtptrn)
{
	ASSERT_ERR((((uint32_t)ch01strtptrn << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_START_PTRN_REG_0_ADDR, (uint32_t)ch01strtptrn << 0);
}

/**
 * @brief LCU_CH_01_START_PTRN_REG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STRT_PTRN            0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_1_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000034)
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_1_OFFSET      0x00000034
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_1_INDEX       0x0000000D
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_1_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_start_ptrn_reg_1_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_START_PTRN_REG_1_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_start_ptrn_reg_1_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_START_PTRN_REG_1_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_1_CH_01_STRT_PTRN_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_1_CH_01_STRT_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_1_CH_01_STRT_PTRN_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_START_PTRN_REG_1_CH_01_STRT_PTRN_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_start_ptrn_reg_1_ch_01_strt_ptrn_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_START_PTRN_REG_1_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_start_ptrn_reg_1_ch_01_strt_ptrn_setf(uint32_t ch01strtptrn)
{
	ASSERT_ERR((((uint32_t)ch01strtptrn << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_START_PTRN_REG_1_ADDR, (uint32_t)ch01strtptrn << 0);
}

/**
 * @brief LCU_CH_01_START_PTRN_REG_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STRT_PTRN            0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_2_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000038)
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_2_OFFSET      0x00000038
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_2_INDEX       0x0000000E
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_2_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_start_ptrn_reg_2_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_START_PTRN_REG_2_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_start_ptrn_reg_2_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_START_PTRN_REG_2_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_2_CH_01_STRT_PTRN_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_2_CH_01_STRT_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_2_CH_01_STRT_PTRN_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_START_PTRN_REG_2_CH_01_STRT_PTRN_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_start_ptrn_reg_2_ch_01_strt_ptrn_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_START_PTRN_REG_2_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_start_ptrn_reg_2_ch_01_strt_ptrn_setf(uint32_t ch01strtptrn)
{
	ASSERT_ERR((((uint32_t)ch01strtptrn << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_START_PTRN_REG_2_ADDR, (uint32_t)ch01strtptrn << 0);
}

/**
 * @brief LCU_CH_01_START_PTRN_REG_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STRT_PTRN            0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_3_ADDR        (REG_LCU_PHY_BASE_ADDR+0x0000003C)
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_3_OFFSET      0x0000003C
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_3_INDEX       0x0000000F
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_3_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_start_ptrn_reg_3_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_START_PTRN_REG_3_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_start_ptrn_reg_3_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_START_PTRN_REG_3_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_3_CH_01_STRT_PTRN_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_3_CH_01_STRT_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_3_CH_01_STRT_PTRN_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_START_PTRN_REG_3_CH_01_STRT_PTRN_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_start_ptrn_reg_3_ch_01_strt_ptrn_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_START_PTRN_REG_3_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_start_ptrn_reg_3_ch_01_strt_ptrn_setf(uint32_t ch01strtptrn)
{
	ASSERT_ERR((((uint32_t)ch01strtptrn << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_START_PTRN_REG_3_ADDR, (uint32_t)ch01strtptrn << 0);
}

/**
 * @brief LCU_CH_01_START_PTRN_REG_4 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STRT_PTRN            0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_4_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000040)
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_4_OFFSET      0x00000040
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_4_INDEX       0x00000010
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_4_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_start_ptrn_reg_4_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_START_PTRN_REG_4_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_start_ptrn_reg_4_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_START_PTRN_REG_4_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_4_CH_01_STRT_PTRN_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_4_CH_01_STRT_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_4_CH_01_STRT_PTRN_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_START_PTRN_REG_4_CH_01_STRT_PTRN_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_start_ptrn_reg_4_ch_01_strt_ptrn_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_START_PTRN_REG_4_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_start_ptrn_reg_4_ch_01_strt_ptrn_setf(uint32_t ch01strtptrn)
{
	ASSERT_ERR((((uint32_t)ch01strtptrn << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_START_PTRN_REG_4_ADDR, (uint32_t)ch01strtptrn << 0);
}

/**
 * @brief LCU_CH_01_START_PTRN_REG_5 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STRT_PTRN            0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_5_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000044)
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_5_OFFSET      0x00000044
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_5_INDEX       0x00000011
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_5_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_start_ptrn_reg_5_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_START_PTRN_REG_5_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_start_ptrn_reg_5_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_START_PTRN_REG_5_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_5_CH_01_STRT_PTRN_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_5_CH_01_STRT_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_5_CH_01_STRT_PTRN_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_START_PTRN_REG_5_CH_01_STRT_PTRN_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_start_ptrn_reg_5_ch_01_strt_ptrn_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_START_PTRN_REG_5_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_start_ptrn_reg_5_ch_01_strt_ptrn_setf(uint32_t ch01strtptrn)
{
	ASSERT_ERR((((uint32_t)ch01strtptrn << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_START_PTRN_REG_5_ADDR, (uint32_t)ch01strtptrn << 0);
}

/**
 * @brief LCU_CH_01_START_PTRN_REG_6 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STRT_PTRN            0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_6_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000048)
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_6_OFFSET      0x00000048
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_6_INDEX       0x00000012
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_6_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_start_ptrn_reg_6_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_START_PTRN_REG_6_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_start_ptrn_reg_6_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_START_PTRN_REG_6_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_6_CH_01_STRT_PTRN_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_6_CH_01_STRT_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_6_CH_01_STRT_PTRN_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_START_PTRN_REG_6_CH_01_STRT_PTRN_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_start_ptrn_reg_6_ch_01_strt_ptrn_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_START_PTRN_REG_6_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_start_ptrn_reg_6_ch_01_strt_ptrn_setf(uint32_t ch01strtptrn)
{
	ASSERT_ERR((((uint32_t)ch01strtptrn << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_START_PTRN_REG_6_ADDR, (uint32_t)ch01strtptrn << 0);
}

/**
 * @brief LCU_CH_01_START_PTRN_REG_7 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STRT_PTRN            0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_7_ADDR        (REG_LCU_PHY_BASE_ADDR+0x0000004C)
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_7_OFFSET      0x0000004C
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_7_INDEX       0x00000013
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_7_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_start_ptrn_reg_7_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_START_PTRN_REG_7_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_start_ptrn_reg_7_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_START_PTRN_REG_7_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_7_CH_01_STRT_PTRN_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_7_CH_01_STRT_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_7_CH_01_STRT_PTRN_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_START_PTRN_REG_7_CH_01_STRT_PTRN_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_start_ptrn_reg_7_ch_01_strt_ptrn_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_START_PTRN_REG_7_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_start_ptrn_reg_7_ch_01_strt_ptrn_setf(uint32_t ch01strtptrn)
{
	ASSERT_ERR((((uint32_t)ch01strtptrn << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_START_PTRN_REG_7_ADDR, (uint32_t)ch01strtptrn << 0);
}

/**
 * @brief LCU_CH_01_START_PTRN_MASK_REG_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STRT_PTRN_MASK       0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_0_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000050)
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_0_OFFSET      0x00000050
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_0_INDEX       0x00000014
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_0_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_start_ptrn_mask_reg_0_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_0_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_start_ptrn_mask_reg_0_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_0_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_0_CH_01_STRT_PTRN_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_0_CH_01_STRT_PTRN_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_0_CH_01_STRT_PTRN_MASK_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_0_CH_01_STRT_PTRN_MASK_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_start_ptrn_mask_reg_0_ch_01_strt_ptrn_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_0_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_start_ptrn_mask_reg_0_ch_01_strt_ptrn_mask_setf(uint32_t ch01strtptrnmask)
{
	ASSERT_ERR((((uint32_t)ch01strtptrnmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_0_ADDR, (uint32_t)ch01strtptrnmask << 0);
}

/**
 * @brief LCU_CH_01_START_PTRN_MASK_REG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STRT_PTRN_MASK       0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_1_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000054)
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_1_OFFSET      0x00000054
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_1_INDEX       0x00000015
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_1_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_start_ptrn_mask_reg_1_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_1_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_start_ptrn_mask_reg_1_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_1_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_1_CH_01_STRT_PTRN_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_1_CH_01_STRT_PTRN_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_1_CH_01_STRT_PTRN_MASK_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_1_CH_01_STRT_PTRN_MASK_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_start_ptrn_mask_reg_1_ch_01_strt_ptrn_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_1_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_start_ptrn_mask_reg_1_ch_01_strt_ptrn_mask_setf(uint32_t ch01strtptrnmask)
{
	ASSERT_ERR((((uint32_t)ch01strtptrnmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_1_ADDR, (uint32_t)ch01strtptrnmask << 0);
}

/**
 * @brief LCU_CH_01_START_PTRN_MASK_REG_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STRT_PTRN_MASK       0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_2_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000058)
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_2_OFFSET      0x00000058
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_2_INDEX       0x00000016
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_2_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_start_ptrn_mask_reg_2_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_2_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_start_ptrn_mask_reg_2_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_2_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_2_CH_01_STRT_PTRN_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_2_CH_01_STRT_PTRN_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_2_CH_01_STRT_PTRN_MASK_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_2_CH_01_STRT_PTRN_MASK_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_start_ptrn_mask_reg_2_ch_01_strt_ptrn_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_2_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_start_ptrn_mask_reg_2_ch_01_strt_ptrn_mask_setf(uint32_t ch01strtptrnmask)
{
	ASSERT_ERR((((uint32_t)ch01strtptrnmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_2_ADDR, (uint32_t)ch01strtptrnmask << 0);
}

/**
 * @brief LCU_CH_01_START_PTRN_MASK_REG_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STRT_PTRN_MASK       0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_3_ADDR        (REG_LCU_PHY_BASE_ADDR+0x0000005C)
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_3_OFFSET      0x0000005C
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_3_INDEX       0x00000017
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_3_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_start_ptrn_mask_reg_3_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_3_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_start_ptrn_mask_reg_3_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_3_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_3_CH_01_STRT_PTRN_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_3_CH_01_STRT_PTRN_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_3_CH_01_STRT_PTRN_MASK_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_3_CH_01_STRT_PTRN_MASK_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_start_ptrn_mask_reg_3_ch_01_strt_ptrn_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_3_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_start_ptrn_mask_reg_3_ch_01_strt_ptrn_mask_setf(uint32_t ch01strtptrnmask)
{
	ASSERT_ERR((((uint32_t)ch01strtptrnmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_3_ADDR, (uint32_t)ch01strtptrnmask << 0);
}

/**
 * @brief LCU_CH_01_START_PTRN_MASK_REG_4 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STRT_PTRN_MASK       0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_4_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000060)
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_4_OFFSET      0x00000060
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_4_INDEX       0x00000018
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_4_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_start_ptrn_mask_reg_4_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_4_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_start_ptrn_mask_reg_4_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_4_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_4_CH_01_STRT_PTRN_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_4_CH_01_STRT_PTRN_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_4_CH_01_STRT_PTRN_MASK_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_4_CH_01_STRT_PTRN_MASK_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_start_ptrn_mask_reg_4_ch_01_strt_ptrn_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_4_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_start_ptrn_mask_reg_4_ch_01_strt_ptrn_mask_setf(uint32_t ch01strtptrnmask)
{
	ASSERT_ERR((((uint32_t)ch01strtptrnmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_4_ADDR, (uint32_t)ch01strtptrnmask << 0);
}

/**
 * @brief LCU_CH_01_START_PTRN_MASK_REG_5 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STRT_PTRN_MASK       0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_5_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000064)
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_5_OFFSET      0x00000064
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_5_INDEX       0x00000019
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_5_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_start_ptrn_mask_reg_5_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_5_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_start_ptrn_mask_reg_5_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_5_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_5_CH_01_STRT_PTRN_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_5_CH_01_STRT_PTRN_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_5_CH_01_STRT_PTRN_MASK_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_5_CH_01_STRT_PTRN_MASK_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_start_ptrn_mask_reg_5_ch_01_strt_ptrn_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_5_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_start_ptrn_mask_reg_5_ch_01_strt_ptrn_mask_setf(uint32_t ch01strtptrnmask)
{
	ASSERT_ERR((((uint32_t)ch01strtptrnmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_5_ADDR, (uint32_t)ch01strtptrnmask << 0);
}

/**
 * @brief LCU_CH_01_START_PTRN_MASK_REG_6 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STRT_PTRN_MASK       0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_6_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000068)
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_6_OFFSET      0x00000068
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_6_INDEX       0x0000001A
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_6_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_start_ptrn_mask_reg_6_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_6_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_start_ptrn_mask_reg_6_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_6_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_6_CH_01_STRT_PTRN_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_6_CH_01_STRT_PTRN_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_6_CH_01_STRT_PTRN_MASK_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_6_CH_01_STRT_PTRN_MASK_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_start_ptrn_mask_reg_6_ch_01_strt_ptrn_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_6_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_start_ptrn_mask_reg_6_ch_01_strt_ptrn_mask_setf(uint32_t ch01strtptrnmask)
{
	ASSERT_ERR((((uint32_t)ch01strtptrnmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_6_ADDR, (uint32_t)ch01strtptrnmask << 0);
}

/**
 * @brief LCU_CH_01_START_PTRN_MASK_REG_7 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STRT_PTRN_MASK       0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_7_ADDR        (REG_LCU_PHY_BASE_ADDR+0x0000006C)
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_7_OFFSET      0x0000006C
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_7_INDEX       0x0000001B
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_7_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_start_ptrn_mask_reg_7_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_7_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_start_ptrn_mask_reg_7_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_7_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_7_CH_01_STRT_PTRN_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_7_CH_01_STRT_PTRN_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_7_CH_01_STRT_PTRN_MASK_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_7_CH_01_STRT_PTRN_MASK_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_start_ptrn_mask_reg_7_ch_01_strt_ptrn_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_7_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_start_ptrn_mask_reg_7_ch_01_strt_ptrn_mask_setf(uint32_t ch01strtptrnmask)
{
	ASSERT_ERR((((uint32_t)ch01strtptrnmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_7_ADDR, (uint32_t)ch01strtptrnmask << 0);
}

/**
 * @brief LCU_CH_0_STOP register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    CH0_STOP                  0              
 * </pre>
 */
#define LCU_PHY_LCU_CH_0_STOP_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000070)
#define LCU_PHY_LCU_CH_0_STOP_OFFSET      0x00000070
#define LCU_PHY_LCU_CH_0_STOP_INDEX       0x0000001C
#define LCU_PHY_LCU_CH_0_STOP_RESET       0x00000000

__INLINE void lcu_phy_lcu_ch_0_stop_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_0_STOP_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_0_STOP_CH_0_STOP_BIT    ((uint32_t)0x00000001)
#define LCU_PHY_LCU_CH_0_STOP_CH_0_STOP_POS    0

#define LCU_PHY_LCU_CH_0_STOP_CH_0_STOP_RST    0x0

__INLINE void lcu_phy_lcu_ch_0_stop_ch_0_stop_setf(uint8_t ch0stop)
{
	ASSERT_ERR((((uint32_t)ch0stop << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_0_STOP_ADDR, (uint32_t)ch0stop << 0);
}

/**
 * @brief LCU_CH_1_STOP register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    CH1_STOP                  0              
 * </pre>
 */
#define LCU_PHY_LCU_CH_1_STOP_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000074)
#define LCU_PHY_LCU_CH_1_STOP_OFFSET      0x00000074
#define LCU_PHY_LCU_CH_1_STOP_INDEX       0x0000001D
#define LCU_PHY_LCU_CH_1_STOP_RESET       0x00000000

__INLINE void lcu_phy_lcu_ch_1_stop_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_1_STOP_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_1_STOP_CH_1_STOP_BIT    ((uint32_t)0x00000001)
#define LCU_PHY_LCU_CH_1_STOP_CH_1_STOP_POS    0

#define LCU_PHY_LCU_CH_1_STOP_CH_1_STOP_RST    0x0

__INLINE void lcu_phy_lcu_ch_1_stop_ch_1_stop_setf(uint8_t ch1stop)
{
	ASSERT_ERR((((uint32_t)ch1stop << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_1_STOP_ADDR, (uint32_t)ch1stop << 0);
}

/**
 * @brief LCU_CH_0_STOP_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    02    CH0_EXT_STOP_EN           0              
 *    01    CH0_FIC_STOP_EN           0              
 *    00    CH0_STOP_PTRN_EN          0              
 * </pre>
 */
#define LCU_PHY_LCU_CH_0_STOP_EN_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000078)
#define LCU_PHY_LCU_CH_0_STOP_EN_OFFSET      0x00000078
#define LCU_PHY_LCU_CH_0_STOP_EN_INDEX       0x0000001E
#define LCU_PHY_LCU_CH_0_STOP_EN_RESET       0x00000000

__INLINE void lcu_phy_lcu_ch_0_stop_en_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_0_STOP_EN_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_0_STOP_EN_CH_0_EXT_STOP_EN_BIT    ((uint32_t)0x00000004)
#define LCU_PHY_LCU_CH_0_STOP_EN_CH_0_EXT_STOP_EN_POS    2
#define LCU_PHY_LCU_CH_0_STOP_EN_CH_0_FIC_STOP_EN_BIT    ((uint32_t)0x00000002)
#define LCU_PHY_LCU_CH_0_STOP_EN_CH_0_FIC_STOP_EN_POS    1
#define LCU_PHY_LCU_CH_0_STOP_EN_CH_0_STOP_PTRN_EN_BIT    ((uint32_t)0x00000001)
#define LCU_PHY_LCU_CH_0_STOP_EN_CH_0_STOP_PTRN_EN_POS    0

#define LCU_PHY_LCU_CH_0_STOP_EN_CH_0_EXT_STOP_EN_RST    0x0
#define LCU_PHY_LCU_CH_0_STOP_EN_CH_0_FIC_STOP_EN_RST    0x0
#define LCU_PHY_LCU_CH_0_STOP_EN_CH_0_STOP_PTRN_EN_RST    0x0

__INLINE void lcu_phy_lcu_ch_0_stop_en_pack(uint8_t ch0_ext_stop_en, uint8_t ch0_fic_stop_en, uint8_t ch0_stop_ptrn_en)
{
	ASSERT_ERR((((uint32_t)ch0_ext_stop_en << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)ch0_fic_stop_en << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)ch0_stop_ptrn_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_0_STOP_EN_ADDR,  ((uint32_t)ch0_ext_stop_en << 2) |((uint32_t)ch0_fic_stop_en << 1) |((uint32_t)ch0_stop_ptrn_en << 0));
}

__INLINE void lcu_phy_lcu_ch_0_stop_en_ch_0_ext_stop_en_setf(uint8_t ch0extstopen)
{
	ASSERT_ERR((((uint32_t)ch0extstopen << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_0_STOP_EN_ADDR, (REG_PL_RD(LCU_PHY_LCU_CH_0_STOP_EN_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)ch0extstopen <<2));
}
__INLINE void lcu_phy_lcu_ch_0_stop_en_ch_0_fic_stop_en_setf(uint8_t ch0ficstopen)
{
	ASSERT_ERR((((uint32_t)ch0ficstopen << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_0_STOP_EN_ADDR, (REG_PL_RD(LCU_PHY_LCU_CH_0_STOP_EN_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)ch0ficstopen <<1));
}
__INLINE void lcu_phy_lcu_ch_0_stop_en_ch_0_stop_ptrn_en_setf(uint8_t ch0stopptrnen)
{
	ASSERT_ERR((((uint32_t)ch0stopptrnen << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_0_STOP_EN_ADDR, (REG_PL_RD(LCU_PHY_LCU_CH_0_STOP_EN_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)ch0stopptrnen <<0));
}

/**
 * @brief LCU_CH_1_STOP_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01    CH1_FIC_STOP_EN           0              
 *    00    CH1_STOP_PTRN_EN          0              
 * </pre>
 */
#define LCU_PHY_LCU_CH_1_STOP_EN_ADDR        (REG_LCU_PHY_BASE_ADDR+0x0000007C)
#define LCU_PHY_LCU_CH_1_STOP_EN_OFFSET      0x0000007C
#define LCU_PHY_LCU_CH_1_STOP_EN_INDEX       0x0000001F
#define LCU_PHY_LCU_CH_1_STOP_EN_RESET       0x00000000

__INLINE void lcu_phy_lcu_ch_1_stop_en_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_1_STOP_EN_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_1_STOP_EN_CH_1_FIC_STOP_EN_BIT    ((uint32_t)0x00000002)
#define LCU_PHY_LCU_CH_1_STOP_EN_CH_1_FIC_STOP_EN_POS    1
#define LCU_PHY_LCU_CH_1_STOP_EN_CH_1_STOP_PTRN_EN_BIT    ((uint32_t)0x00000001)
#define LCU_PHY_LCU_CH_1_STOP_EN_CH_1_STOP_PTRN_EN_POS    0

#define LCU_PHY_LCU_CH_1_STOP_EN_CH_1_FIC_STOP_EN_RST    0x0
#define LCU_PHY_LCU_CH_1_STOP_EN_CH_1_STOP_PTRN_EN_RST    0x0

__INLINE void lcu_phy_lcu_ch_1_stop_en_pack(uint8_t ch1_fic_stop_en, uint8_t ch1_stop_ptrn_en)
{
	ASSERT_ERR((((uint32_t)ch1_fic_stop_en << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)ch1_stop_ptrn_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_1_STOP_EN_ADDR,  ((uint32_t)ch1_fic_stop_en << 1) |((uint32_t)ch1_stop_ptrn_en << 0));
}

__INLINE void lcu_phy_lcu_ch_1_stop_en_ch_1_fic_stop_en_setf(uint8_t ch1ficstopen)
{
	ASSERT_ERR((((uint32_t)ch1ficstopen << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_1_STOP_EN_ADDR, (REG_PL_RD(LCU_PHY_LCU_CH_1_STOP_EN_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)ch1ficstopen <<1));
}
__INLINE void lcu_phy_lcu_ch_1_stop_en_ch_1_stop_ptrn_en_setf(uint8_t ch1stopptrnen)
{
	ASSERT_ERR((((uint32_t)ch1stopptrnen << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_1_STOP_EN_ADDR, (REG_PL_RD(LCU_PHY_LCU_CH_1_STOP_EN_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)ch1stopptrnen <<0));
}

/**
 * @brief LCU_CH_01_STOP_PTRN_REG_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STOP_PTRN            0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_0_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000080)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_0_OFFSET      0x00000080
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_0_INDEX       0x00000020
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_0_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_stop_ptrn_reg_0_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_STOP_PTRN_REG_0_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_stop_ptrn_reg_0_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_STOP_PTRN_REG_0_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_0_CH_01_STOP_PTRN_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_0_CH_01_STOP_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_0_CH_01_STOP_PTRN_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_0_CH_01_STOP_PTRN_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_stop_ptrn_reg_0_ch_01_stop_ptrn_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_STOP_PTRN_REG_0_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_stop_ptrn_reg_0_ch_01_stop_ptrn_setf(uint32_t ch01stopptrn)
{
	ASSERT_ERR((((uint32_t)ch01stopptrn << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_STOP_PTRN_REG_0_ADDR, (uint32_t)ch01stopptrn << 0);
}

/**
 * @brief LCU_CH_01_STOP_PTRN_REG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STOP_PTRN            0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_1_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000084)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_1_OFFSET      0x00000084
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_1_INDEX       0x00000021
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_1_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_stop_ptrn_reg_1_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_STOP_PTRN_REG_1_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_stop_ptrn_reg_1_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_STOP_PTRN_REG_1_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_1_CH_01_STOP_PTRN_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_1_CH_01_STOP_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_1_CH_01_STOP_PTRN_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_1_CH_01_STOP_PTRN_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_stop_ptrn_reg_1_ch_01_stop_ptrn_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_STOP_PTRN_REG_1_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_stop_ptrn_reg_1_ch_01_stop_ptrn_setf(uint32_t ch01stopptrn)
{
	ASSERT_ERR((((uint32_t)ch01stopptrn << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_STOP_PTRN_REG_1_ADDR, (uint32_t)ch01stopptrn << 0);
}

/**
 * @brief LCU_CH_01_STOP_PTRN_REG_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STOP_PTRN            0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_2_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000088)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_2_OFFSET      0x00000088
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_2_INDEX       0x00000022
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_2_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_stop_ptrn_reg_2_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_STOP_PTRN_REG_2_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_stop_ptrn_reg_2_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_STOP_PTRN_REG_2_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_2_CH_01_STOP_PTRN_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_2_CH_01_STOP_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_2_CH_01_STOP_PTRN_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_2_CH_01_STOP_PTRN_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_stop_ptrn_reg_2_ch_01_stop_ptrn_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_STOP_PTRN_REG_2_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_stop_ptrn_reg_2_ch_01_stop_ptrn_setf(uint32_t ch01stopptrn)
{
	ASSERT_ERR((((uint32_t)ch01stopptrn << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_STOP_PTRN_REG_2_ADDR, (uint32_t)ch01stopptrn << 0);
}

/**
 * @brief LCU_CH_01_STOP_PTRN_REG_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STOP_PTRN            0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_3_ADDR        (REG_LCU_PHY_BASE_ADDR+0x0000008C)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_3_OFFSET      0x0000008C
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_3_INDEX       0x00000023
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_3_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_stop_ptrn_reg_3_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_STOP_PTRN_REG_3_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_stop_ptrn_reg_3_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_STOP_PTRN_REG_3_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_3_CH_01_STOP_PTRN_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_3_CH_01_STOP_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_3_CH_01_STOP_PTRN_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_3_CH_01_STOP_PTRN_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_stop_ptrn_reg_3_ch_01_stop_ptrn_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_STOP_PTRN_REG_3_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_stop_ptrn_reg_3_ch_01_stop_ptrn_setf(uint32_t ch01stopptrn)
{
	ASSERT_ERR((((uint32_t)ch01stopptrn << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_STOP_PTRN_REG_3_ADDR, (uint32_t)ch01stopptrn << 0);
}

/**
 * @brief LCU_CH_01_STOP_PTRN_REG_4 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STOP_PTRN            0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_4_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000090)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_4_OFFSET      0x00000090
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_4_INDEX       0x00000024
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_4_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_stop_ptrn_reg_4_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_STOP_PTRN_REG_4_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_stop_ptrn_reg_4_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_STOP_PTRN_REG_4_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_4_CH_01_STOP_PTRN_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_4_CH_01_STOP_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_4_CH_01_STOP_PTRN_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_4_CH_01_STOP_PTRN_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_stop_ptrn_reg_4_ch_01_stop_ptrn_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_STOP_PTRN_REG_4_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_stop_ptrn_reg_4_ch_01_stop_ptrn_setf(uint32_t ch01stopptrn)
{
	ASSERT_ERR((((uint32_t)ch01stopptrn << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_STOP_PTRN_REG_4_ADDR, (uint32_t)ch01stopptrn << 0);
}

/**
 * @brief LCU_CH_01_STOP_PTRN_REG_5 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STOP_PTRN            0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_5_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000094)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_5_OFFSET      0x00000094
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_5_INDEX       0x00000025
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_5_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_stop_ptrn_reg_5_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_STOP_PTRN_REG_5_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_stop_ptrn_reg_5_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_STOP_PTRN_REG_5_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_5_CH_01_STOP_PTRN_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_5_CH_01_STOP_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_5_CH_01_STOP_PTRN_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_5_CH_01_STOP_PTRN_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_stop_ptrn_reg_5_ch_01_stop_ptrn_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_STOP_PTRN_REG_5_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_stop_ptrn_reg_5_ch_01_stop_ptrn_setf(uint32_t ch01stopptrn)
{
	ASSERT_ERR((((uint32_t)ch01stopptrn << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_STOP_PTRN_REG_5_ADDR, (uint32_t)ch01stopptrn << 0);
}

/**
 * @brief LCU_CH_01_STOP_PTRN_REG_6 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STOP_PTRN            0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_6_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000098)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_6_OFFSET      0x00000098
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_6_INDEX       0x00000026
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_6_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_stop_ptrn_reg_6_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_STOP_PTRN_REG_6_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_stop_ptrn_reg_6_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_STOP_PTRN_REG_6_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_6_CH_01_STOP_PTRN_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_6_CH_01_STOP_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_6_CH_01_STOP_PTRN_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_6_CH_01_STOP_PTRN_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_stop_ptrn_reg_6_ch_01_stop_ptrn_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_STOP_PTRN_REG_6_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_stop_ptrn_reg_6_ch_01_stop_ptrn_setf(uint32_t ch01stopptrn)
{
	ASSERT_ERR((((uint32_t)ch01stopptrn << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_STOP_PTRN_REG_6_ADDR, (uint32_t)ch01stopptrn << 0);
}

/**
 * @brief LCU_CH_01_STOP_PTRN_REG_7 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STOP_PTRN            0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_7_ADDR        (REG_LCU_PHY_BASE_ADDR+0x0000009C)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_7_OFFSET      0x0000009C
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_7_INDEX       0x00000027
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_7_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_stop_ptrn_reg_7_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_STOP_PTRN_REG_7_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_stop_ptrn_reg_7_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_STOP_PTRN_REG_7_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_7_CH_01_STOP_PTRN_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_7_CH_01_STOP_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_7_CH_01_STOP_PTRN_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_7_CH_01_STOP_PTRN_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_stop_ptrn_reg_7_ch_01_stop_ptrn_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_STOP_PTRN_REG_7_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_stop_ptrn_reg_7_ch_01_stop_ptrn_setf(uint32_t ch01stopptrn)
{
	ASSERT_ERR((((uint32_t)ch01stopptrn << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_STOP_PTRN_REG_7_ADDR, (uint32_t)ch01stopptrn << 0);
}

/**
 * @brief LCU_CH_01_STOP_PTRN_MASK_REG_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STOP_PTRN_MASK       0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_0_ADDR        (REG_LCU_PHY_BASE_ADDR+0x000000A0)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_0_OFFSET      0x000000A0
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_0_INDEX       0x00000028
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_0_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_0_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_0_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_0_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_0_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_0_CH_01_STOP_PTRN_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_0_CH_01_STOP_PTRN_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_0_CH_01_STOP_PTRN_MASK_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_0_CH_01_STOP_PTRN_MASK_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_0_ch_01_stop_ptrn_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_0_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_0_ch_01_stop_ptrn_mask_setf(uint32_t ch01stopptrnmask)
{
	ASSERT_ERR((((uint32_t)ch01stopptrnmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_0_ADDR, (uint32_t)ch01stopptrnmask << 0);
}

/**
 * @brief LCU_CH_01_STOP_PTRN_MASK_REG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STOP_PTRN_MASK       0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_1_ADDR        (REG_LCU_PHY_BASE_ADDR+0x000000A4)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_1_OFFSET      0x000000A4
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_1_INDEX       0x00000029
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_1_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_1_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_1_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_1_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_1_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_1_CH_01_STOP_PTRN_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_1_CH_01_STOP_PTRN_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_1_CH_01_STOP_PTRN_MASK_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_1_CH_01_STOP_PTRN_MASK_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_1_ch_01_stop_ptrn_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_1_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_1_ch_01_stop_ptrn_mask_setf(uint32_t ch01stopptrnmask)
{
	ASSERT_ERR((((uint32_t)ch01stopptrnmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_1_ADDR, (uint32_t)ch01stopptrnmask << 0);
}

/**
 * @brief LCU_CH_01_STOP_PTRN_MASK_REG_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STOP_PTRN_MASK       0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_2_ADDR        (REG_LCU_PHY_BASE_ADDR+0x000000A8)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_2_OFFSET      0x000000A8
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_2_INDEX       0x0000002A
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_2_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_2_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_2_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_2_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_2_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_2_CH_01_STOP_PTRN_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_2_CH_01_STOP_PTRN_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_2_CH_01_STOP_PTRN_MASK_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_2_CH_01_STOP_PTRN_MASK_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_2_ch_01_stop_ptrn_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_2_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_2_ch_01_stop_ptrn_mask_setf(uint32_t ch01stopptrnmask)
{
	ASSERT_ERR((((uint32_t)ch01stopptrnmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_2_ADDR, (uint32_t)ch01stopptrnmask << 0);
}

/**
 * @brief LCU_CH_01_STOP_PTRN_MASK_REG_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STOP_PTRN_MASK       0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_3_ADDR        (REG_LCU_PHY_BASE_ADDR+0x000000AC)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_3_OFFSET      0x000000AC
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_3_INDEX       0x0000002B
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_3_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_3_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_3_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_3_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_3_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_3_CH_01_STOP_PTRN_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_3_CH_01_STOP_PTRN_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_3_CH_01_STOP_PTRN_MASK_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_3_CH_01_STOP_PTRN_MASK_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_3_ch_01_stop_ptrn_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_3_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_3_ch_01_stop_ptrn_mask_setf(uint32_t ch01stopptrnmask)
{
	ASSERT_ERR((((uint32_t)ch01stopptrnmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_3_ADDR, (uint32_t)ch01stopptrnmask << 0);
}

/**
 * @brief LCU_CH_01_STOP_PTRN_MASK_REG_4 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STOP_PTRN_MASK       0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_4_ADDR        (REG_LCU_PHY_BASE_ADDR+0x000000B0)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_4_OFFSET      0x000000B0
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_4_INDEX       0x0000002C
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_4_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_4_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_4_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_4_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_4_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_4_CH_01_STOP_PTRN_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_4_CH_01_STOP_PTRN_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_4_CH_01_STOP_PTRN_MASK_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_4_CH_01_STOP_PTRN_MASK_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_4_ch_01_stop_ptrn_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_4_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_4_ch_01_stop_ptrn_mask_setf(uint32_t ch01stopptrnmask)
{
	ASSERT_ERR((((uint32_t)ch01stopptrnmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_4_ADDR, (uint32_t)ch01stopptrnmask << 0);
}

/**
 * @brief LCU_CH_01_STOP_PTRN_MASK_REG_5 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STOP_PTRN_MASK       0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_5_ADDR        (REG_LCU_PHY_BASE_ADDR+0x000000B4)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_5_OFFSET      0x000000B4
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_5_INDEX       0x0000002D
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_5_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_5_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_5_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_5_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_5_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_5_CH_01_STOP_PTRN_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_5_CH_01_STOP_PTRN_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_5_CH_01_STOP_PTRN_MASK_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_5_CH_01_STOP_PTRN_MASK_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_5_ch_01_stop_ptrn_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_5_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_5_ch_01_stop_ptrn_mask_setf(uint32_t ch01stopptrnmask)
{
	ASSERT_ERR((((uint32_t)ch01stopptrnmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_5_ADDR, (uint32_t)ch01stopptrnmask << 0);
}

/**
 * @brief LCU_CH_01_STOP_PTRN_MASK_REG_6 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STOP_PTRN_MASK       0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_6_ADDR        (REG_LCU_PHY_BASE_ADDR+0x000000B8)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_6_OFFSET      0x000000B8
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_6_INDEX       0x0000002E
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_6_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_6_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_6_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_6_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_6_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_6_CH_01_STOP_PTRN_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_6_CH_01_STOP_PTRN_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_6_CH_01_STOP_PTRN_MASK_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_6_CH_01_STOP_PTRN_MASK_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_6_ch_01_stop_ptrn_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_6_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_6_ch_01_stop_ptrn_mask_setf(uint32_t ch01stopptrnmask)
{
	ASSERT_ERR((((uint32_t)ch01stopptrnmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_6_ADDR, (uint32_t)ch01stopptrnmask << 0);
}

/**
 * @brief LCU_CH_01_STOP_PTRN_MASK_REG_7 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STOP_PTRN_MASK       0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_7_ADDR        (REG_LCU_PHY_BASE_ADDR+0x000000BC)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_7_OFFSET      0x000000BC
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_7_INDEX       0x0000002F
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_7_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_7_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_7_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_7_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_7_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_7_CH_01_STOP_PTRN_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_7_CH_01_STOP_PTRN_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_7_CH_01_STOP_PTRN_MASK_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_7_CH_01_STOP_PTRN_MASK_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_7_ch_01_stop_ptrn_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_7_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_7_ch_01_stop_ptrn_mask_setf(uint32_t ch01stopptrnmask)
{
	ASSERT_ERR((((uint32_t)ch01stopptrnmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_7_ADDR, (uint32_t)ch01stopptrnmask << 0);
}

/**
 * @brief LCU_CH_0_CTPREV_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    CH0_CTPREV_EN             0              
 * </pre>
 */
#define LCU_PHY_LCU_CH_0_CTPREV_EN_ADDR        (REG_LCU_PHY_BASE_ADDR+0x000000C0)
#define LCU_PHY_LCU_CH_0_CTPREV_EN_OFFSET      0x000000C0
#define LCU_PHY_LCU_CH_0_CTPREV_EN_INDEX       0x00000030
#define LCU_PHY_LCU_CH_0_CTPREV_EN_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_0_ctprev_en_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_0_CTPREV_EN_ADDR);
}

__INLINE void lcu_phy_lcu_ch_0_ctprev_en_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_0_CTPREV_EN_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_0_CTPREV_EN_CH_0_CTPREV_EN_BIT    ((uint32_t)0x00000001)
#define LCU_PHY_LCU_CH_0_CTPREV_EN_CH_0_CTPREV_EN_POS    0

#define LCU_PHY_LCU_CH_0_CTPREV_EN_CH_0_CTPREV_EN_RST    0x0

__INLINE uint8_t lcu_phy_lcu_ch_0_ctprev_en_ch_0_ctprev_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_0_CTPREV_EN_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_0_ctprev_en_ch_0_ctprev_en_setf(uint8_t ch0ctpreven)
{
	ASSERT_ERR((((uint32_t)ch0ctpreven << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_0_CTPREV_EN_ADDR, (uint32_t)ch0ctpreven << 0);
}

/**
 * @brief LCU_CH_1_CTPREV_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    CH1_CTPREV_EN             0              
 * </pre>
 */
#define LCU_PHY_LCU_CH_1_CTPREV_EN_ADDR        (REG_LCU_PHY_BASE_ADDR+0x000000C4)
#define LCU_PHY_LCU_CH_1_CTPREV_EN_OFFSET      0x000000C4
#define LCU_PHY_LCU_CH_1_CTPREV_EN_INDEX       0x00000031
#define LCU_PHY_LCU_CH_1_CTPREV_EN_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_1_ctprev_en_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_1_CTPREV_EN_ADDR);
}

__INLINE void lcu_phy_lcu_ch_1_ctprev_en_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_1_CTPREV_EN_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_1_CTPREV_EN_CH_1_CTPREV_EN_BIT    ((uint32_t)0x00000001)
#define LCU_PHY_LCU_CH_1_CTPREV_EN_CH_1_CTPREV_EN_POS    0

#define LCU_PHY_LCU_CH_1_CTPREV_EN_CH_1_CTPREV_EN_RST    0x0

__INLINE uint8_t lcu_phy_lcu_ch_1_ctprev_en_ch_1_ctprev_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_1_CTPREV_EN_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_1_ctprev_en_ch_1_ctprev_en_setf(uint8_t ch1ctpreven)
{
	ASSERT_ERR((((uint32_t)ch1ctpreven << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_1_CTPREV_EN_ADDR, (uint32_t)ch1ctpreven << 0);
}

/**
 * @brief LCU_CH_01_CTPREV_MASK_REG_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPREV_MASK          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_0_ADDR        (REG_LCU_PHY_BASE_ADDR+0x000000D0)
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_0_OFFSET      0x000000D0
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_0_INDEX       0x00000034
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_0_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_ctprev_mask_reg_0_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_0_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_ctprev_mask_reg_0_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_0_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_0_CH_01_CTPREV_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_0_CH_01_CTPREV_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_0_CH_01_CTPREV_MASK_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_0_CH_01_CTPREV_MASK_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_ctprev_mask_reg_0_ch_01_ctprev_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_0_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_ctprev_mask_reg_0_ch_01_ctprev_mask_setf(uint32_t ch01ctprevmask)
{
	ASSERT_ERR((((uint32_t)ch01ctprevmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_0_ADDR, (uint32_t)ch01ctprevmask << 0);
}

/**
 * @brief LCU_CH_01_CTPREV_MASK_REG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPREV_MASK          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_1_ADDR        (REG_LCU_PHY_BASE_ADDR+0x000000D4)
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_1_OFFSET      0x000000D4
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_1_INDEX       0x00000035
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_1_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_ctprev_mask_reg_1_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_1_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_ctprev_mask_reg_1_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_1_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_1_CH_01_CTPREV_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_1_CH_01_CTPREV_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_1_CH_01_CTPREV_MASK_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_1_CH_01_CTPREV_MASK_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_ctprev_mask_reg_1_ch_01_ctprev_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_1_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_ctprev_mask_reg_1_ch_01_ctprev_mask_setf(uint32_t ch01ctprevmask)
{
	ASSERT_ERR((((uint32_t)ch01ctprevmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_1_ADDR, (uint32_t)ch01ctprevmask << 0);
}

/**
 * @brief LCU_CH_01_CTPREV_MASK_REG_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPREV_MASK          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_2_ADDR        (REG_LCU_PHY_BASE_ADDR+0x000000D8)
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_2_OFFSET      0x000000D8
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_2_INDEX       0x00000036
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_2_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_ctprev_mask_reg_2_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_2_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_ctprev_mask_reg_2_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_2_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_2_CH_01_CTPREV_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_2_CH_01_CTPREV_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_2_CH_01_CTPREV_MASK_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_2_CH_01_CTPREV_MASK_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_ctprev_mask_reg_2_ch_01_ctprev_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_2_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_ctprev_mask_reg_2_ch_01_ctprev_mask_setf(uint32_t ch01ctprevmask)
{
	ASSERT_ERR((((uint32_t)ch01ctprevmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_2_ADDR, (uint32_t)ch01ctprevmask << 0);
}

/**
 * @brief LCU_CH_01_CTPREV_MASK_REG_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPREV_MASK          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_3_ADDR        (REG_LCU_PHY_BASE_ADDR+0x000000DC)
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_3_OFFSET      0x000000DC
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_3_INDEX       0x00000037
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_3_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_ctprev_mask_reg_3_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_3_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_ctprev_mask_reg_3_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_3_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_3_CH_01_CTPREV_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_3_CH_01_CTPREV_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_3_CH_01_CTPREV_MASK_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_3_CH_01_CTPREV_MASK_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_ctprev_mask_reg_3_ch_01_ctprev_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_3_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_ctprev_mask_reg_3_ch_01_ctprev_mask_setf(uint32_t ch01ctprevmask)
{
	ASSERT_ERR((((uint32_t)ch01ctprevmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_3_ADDR, (uint32_t)ch01ctprevmask << 0);
}

/**
 * @brief LCU_CH_01_CTPREV_MASK_REG_4 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPREV_MASK          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_4_ADDR        (REG_LCU_PHY_BASE_ADDR+0x000000E0)
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_4_OFFSET      0x000000E0
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_4_INDEX       0x00000038
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_4_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_ctprev_mask_reg_4_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_4_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_ctprev_mask_reg_4_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_4_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_4_CH_01_CTPREV_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_4_CH_01_CTPREV_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_4_CH_01_CTPREV_MASK_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_4_CH_01_CTPREV_MASK_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_ctprev_mask_reg_4_ch_01_ctprev_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_4_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_ctprev_mask_reg_4_ch_01_ctprev_mask_setf(uint32_t ch01ctprevmask)
{
	ASSERT_ERR((((uint32_t)ch01ctprevmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_4_ADDR, (uint32_t)ch01ctprevmask << 0);
}

/**
 * @brief LCU_CH_01_CTPREV_MASK_REG_5 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPREV_MASK          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_5_ADDR        (REG_LCU_PHY_BASE_ADDR+0x000000E4)
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_5_OFFSET      0x000000E4
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_5_INDEX       0x00000039
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_5_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_ctprev_mask_reg_5_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_5_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_ctprev_mask_reg_5_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_5_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_5_CH_01_CTPREV_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_5_CH_01_CTPREV_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_5_CH_01_CTPREV_MASK_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_5_CH_01_CTPREV_MASK_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_ctprev_mask_reg_5_ch_01_ctprev_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_5_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_ctprev_mask_reg_5_ch_01_ctprev_mask_setf(uint32_t ch01ctprevmask)
{
	ASSERT_ERR((((uint32_t)ch01ctprevmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_5_ADDR, (uint32_t)ch01ctprevmask << 0);
}

/**
 * @brief LCU_CH_01_CTPREV_MASK_REG_6 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPREV_MASK          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_6_ADDR        (REG_LCU_PHY_BASE_ADDR+0x000000E8)
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_6_OFFSET      0x000000E8
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_6_INDEX       0x0000003A
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_6_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_ctprev_mask_reg_6_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_6_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_ctprev_mask_reg_6_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_6_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_6_CH_01_CTPREV_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_6_CH_01_CTPREV_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_6_CH_01_CTPREV_MASK_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_6_CH_01_CTPREV_MASK_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_ctprev_mask_reg_6_ch_01_ctprev_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_6_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_ctprev_mask_reg_6_ch_01_ctprev_mask_setf(uint32_t ch01ctprevmask)
{
	ASSERT_ERR((((uint32_t)ch01ctprevmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_6_ADDR, (uint32_t)ch01ctprevmask << 0);
}

/**
 * @brief LCU_CH_01_CTPREV_MASK_REG_7 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPREV_MASK          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_7_ADDR        (REG_LCU_PHY_BASE_ADDR+0x000000EC)
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_7_OFFSET      0x000000EC
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_7_INDEX       0x0000003B
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_7_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_ctprev_mask_reg_7_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_7_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_ctprev_mask_reg_7_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_7_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_7_CH_01_CTPREV_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_7_CH_01_CTPREV_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_7_CH_01_CTPREV_MASK_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_7_CH_01_CTPREV_MASK_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_ctprev_mask_reg_7_ch_01_ctprev_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_7_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_ctprev_mask_reg_7_ch_01_ctprev_mask_setf(uint32_t ch01ctprevmask)
{
	ASSERT_ERR((((uint32_t)ch01ctprevmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_7_ADDR, (uint32_t)ch01ctprevmask << 0);
}

/**
 * @brief LCU_CH_0_CTPATT_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    CH0_CTPATT_EN             0              
 * </pre>
 */
#define LCU_PHY_LCU_CH_0_CTPATT_EN_ADDR        (REG_LCU_PHY_BASE_ADDR+0x000000F0)
#define LCU_PHY_LCU_CH_0_CTPATT_EN_OFFSET      0x000000F0
#define LCU_PHY_LCU_CH_0_CTPATT_EN_INDEX       0x0000003C
#define LCU_PHY_LCU_CH_0_CTPATT_EN_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_0_ctpatt_en_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_0_CTPATT_EN_ADDR);
}

__INLINE void lcu_phy_lcu_ch_0_ctpatt_en_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_0_CTPATT_EN_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_0_CTPATT_EN_CH_0_CTPATT_EN_BIT    ((uint32_t)0x00000001)
#define LCU_PHY_LCU_CH_0_CTPATT_EN_CH_0_CTPATT_EN_POS    0

#define LCU_PHY_LCU_CH_0_CTPATT_EN_CH_0_CTPATT_EN_RST    0x0

__INLINE uint8_t lcu_phy_lcu_ch_0_ctpatt_en_ch_0_ctpatt_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_0_CTPATT_EN_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_0_ctpatt_en_ch_0_ctpatt_en_setf(uint8_t ch0ctpatten)
{
	ASSERT_ERR((((uint32_t)ch0ctpatten << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_0_CTPATT_EN_ADDR, (uint32_t)ch0ctpatten << 0);
}

/**
 * @brief LCU_CH_0_CTPATT_MODE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    CH0_CTPATT_MODE           0              
 * </pre>
 */
#define LCU_PHY_LCU_CH_0_CTPATT_MODE_ADDR        (REG_LCU_PHY_BASE_ADDR+0x000000F4)
#define LCU_PHY_LCU_CH_0_CTPATT_MODE_OFFSET      0x000000F4
#define LCU_PHY_LCU_CH_0_CTPATT_MODE_INDEX       0x0000003D
#define LCU_PHY_LCU_CH_0_CTPATT_MODE_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_0_ctpatt_mode_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_0_CTPATT_MODE_ADDR);
}

__INLINE void lcu_phy_lcu_ch_0_ctpatt_mode_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_0_CTPATT_MODE_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_0_CTPATT_MODE_CH_0_CTPATT_MODE_BIT    ((uint32_t)0x00000001)
#define LCU_PHY_LCU_CH_0_CTPATT_MODE_CH_0_CTPATT_MODE_POS    0

#define LCU_PHY_LCU_CH_0_CTPATT_MODE_CH_0_CTPATT_MODE_RST    0x0

__INLINE uint8_t lcu_phy_lcu_ch_0_ctpatt_mode_ch_0_ctpatt_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_0_CTPATT_MODE_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_0_ctpatt_mode_ch_0_ctpatt_mode_setf(uint8_t ch0ctpattmode)
{
	ASSERT_ERR((((uint32_t)ch0ctpattmode << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_0_CTPATT_MODE_ADDR, (uint32_t)ch0ctpattmode << 0);
}

/**
 * @brief LCU_CH_1_CTPATT_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    CH1_CTPATT_EN             0              
 * </pre>
 */
#define LCU_PHY_LCU_CH_1_CTPATT_EN_ADDR        (REG_LCU_PHY_BASE_ADDR+0x000000F8)
#define LCU_PHY_LCU_CH_1_CTPATT_EN_OFFSET      0x000000F8
#define LCU_PHY_LCU_CH_1_CTPATT_EN_INDEX       0x0000003E
#define LCU_PHY_LCU_CH_1_CTPATT_EN_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_1_ctpatt_en_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_1_CTPATT_EN_ADDR);
}

__INLINE void lcu_phy_lcu_ch_1_ctpatt_en_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_1_CTPATT_EN_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_1_CTPATT_EN_CH_1_CTPATT_EN_BIT    ((uint32_t)0x00000001)
#define LCU_PHY_LCU_CH_1_CTPATT_EN_CH_1_CTPATT_EN_POS    0

#define LCU_PHY_LCU_CH_1_CTPATT_EN_CH_1_CTPATT_EN_RST    0x0

__INLINE uint8_t lcu_phy_lcu_ch_1_ctpatt_en_ch_1_ctpatt_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_1_CTPATT_EN_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_1_ctpatt_en_ch_1_ctpatt_en_setf(uint8_t ch1ctpatten)
{
	ASSERT_ERR((((uint32_t)ch1ctpatten << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_1_CTPATT_EN_ADDR, (uint32_t)ch1ctpatten << 0);
}

/**
 * @brief LCU_CH_1_CTPATT_MODE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    CH1_CTPATT_MODE           0              
 * </pre>
 */
#define LCU_PHY_LCU_CH_1_CTPATT_MODE_ADDR        (REG_LCU_PHY_BASE_ADDR+0x000000FC)
#define LCU_PHY_LCU_CH_1_CTPATT_MODE_OFFSET      0x000000FC
#define LCU_PHY_LCU_CH_1_CTPATT_MODE_INDEX       0x0000003F
#define LCU_PHY_LCU_CH_1_CTPATT_MODE_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_1_ctpatt_mode_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_1_CTPATT_MODE_ADDR);
}

__INLINE void lcu_phy_lcu_ch_1_ctpatt_mode_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_1_CTPATT_MODE_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_1_CTPATT_MODE_CH_1_CTPATT_MODE_BIT    ((uint32_t)0x00000001)
#define LCU_PHY_LCU_CH_1_CTPATT_MODE_CH_1_CTPATT_MODE_POS    0

#define LCU_PHY_LCU_CH_1_CTPATT_MODE_CH_1_CTPATT_MODE_RST    0x0

__INLINE uint8_t lcu_phy_lcu_ch_1_ctpatt_mode_ch_1_ctpatt_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_1_CTPATT_MODE_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_1_ctpatt_mode_ch_1_ctpatt_mode_setf(uint8_t ch1ctpattmode)
{
	ASSERT_ERR((((uint32_t)ch1ctpattmode << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_1_CTPATT_MODE_ADDR, (uint32_t)ch1ctpattmode << 0);
}

/**
 * @brief LCU_CH_01_CTPATT_PTRN_REG_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPATT_PTRN          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_0_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000100)
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_0_OFFSET      0x00000100
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_0_INDEX       0x00000040
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_0_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_0_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_0_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_0_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_0_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_0_CH_01_CTPATT_PTRN_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_0_CH_01_CTPATT_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_0_CH_01_CTPATT_PTRN_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_0_CH_01_CTPATT_PTRN_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_0_ch_01_ctpatt_ptrn_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_0_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_0_ch_01_ctpatt_ptrn_setf(uint32_t ch01ctpattptrn)
{
	ASSERT_ERR((((uint32_t)ch01ctpattptrn << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_0_ADDR, (uint32_t)ch01ctpattptrn << 0);
}

/**
 * @brief LCU_CH_01_CTPATT_PTRN_REG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPATT_PTRN          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_1_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000104)
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_1_OFFSET      0x00000104
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_1_INDEX       0x00000041
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_1_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_1_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_1_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_1_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_1_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_1_CH_01_CTPATT_PTRN_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_1_CH_01_CTPATT_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_1_CH_01_CTPATT_PTRN_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_1_CH_01_CTPATT_PTRN_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_1_ch_01_ctpatt_ptrn_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_1_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_1_ch_01_ctpatt_ptrn_setf(uint32_t ch01ctpattptrn)
{
	ASSERT_ERR((((uint32_t)ch01ctpattptrn << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_1_ADDR, (uint32_t)ch01ctpattptrn << 0);
}

/**
 * @brief LCU_CH_01_CTPATT_PTRN_REG_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPATT_PTRN          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_2_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000108)
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_2_OFFSET      0x00000108
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_2_INDEX       0x00000042
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_2_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_2_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_2_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_2_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_2_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_2_CH_01_CTPATT_PTRN_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_2_CH_01_CTPATT_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_2_CH_01_CTPATT_PTRN_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_2_CH_01_CTPATT_PTRN_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_2_ch_01_ctpatt_ptrn_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_2_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_2_ch_01_ctpatt_ptrn_setf(uint32_t ch01ctpattptrn)
{
	ASSERT_ERR((((uint32_t)ch01ctpattptrn << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_2_ADDR, (uint32_t)ch01ctpattptrn << 0);
}

/**
 * @brief LCU_CH_01_CTPATT_PTRN_REG_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPATT_PTRN          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_3_ADDR        (REG_LCU_PHY_BASE_ADDR+0x0000010C)
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_3_OFFSET      0x0000010C
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_3_INDEX       0x00000043
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_3_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_3_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_3_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_3_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_3_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_3_CH_01_CTPATT_PTRN_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_3_CH_01_CTPATT_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_3_CH_01_CTPATT_PTRN_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_3_CH_01_CTPATT_PTRN_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_3_ch_01_ctpatt_ptrn_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_3_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_3_ch_01_ctpatt_ptrn_setf(uint32_t ch01ctpattptrn)
{
	ASSERT_ERR((((uint32_t)ch01ctpattptrn << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_3_ADDR, (uint32_t)ch01ctpattptrn << 0);
}

/**
 * @brief LCU_CH_01_CTPATT_PTRN_REG_4 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPATT_PTRN          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_4_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000110)
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_4_OFFSET      0x00000110
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_4_INDEX       0x00000044
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_4_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_4_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_4_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_4_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_4_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_4_CH_01_CTPATT_PTRN_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_4_CH_01_CTPATT_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_4_CH_01_CTPATT_PTRN_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_4_CH_01_CTPATT_PTRN_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_4_ch_01_ctpatt_ptrn_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_4_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_4_ch_01_ctpatt_ptrn_setf(uint32_t ch01ctpattptrn)
{
	ASSERT_ERR((((uint32_t)ch01ctpattptrn << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_4_ADDR, (uint32_t)ch01ctpattptrn << 0);
}

/**
 * @brief LCU_CH_01_CTPATT_PTRN_REG_5 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPATT_PTRN          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_5_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000114)
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_5_OFFSET      0x00000114
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_5_INDEX       0x00000045
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_5_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_5_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_5_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_5_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_5_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_5_CH_01_CTPATT_PTRN_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_5_CH_01_CTPATT_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_5_CH_01_CTPATT_PTRN_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_5_CH_01_CTPATT_PTRN_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_5_ch_01_ctpatt_ptrn_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_5_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_5_ch_01_ctpatt_ptrn_setf(uint32_t ch01ctpattptrn)
{
	ASSERT_ERR((((uint32_t)ch01ctpattptrn << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_5_ADDR, (uint32_t)ch01ctpattptrn << 0);
}

/**
 * @brief LCU_CH_01_CTPATT_PTRN_REG_6 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPATT_PTRN          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_6_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000118)
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_6_OFFSET      0x00000118
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_6_INDEX       0x00000046
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_6_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_6_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_6_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_6_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_6_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_6_CH_01_CTPATT_PTRN_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_6_CH_01_CTPATT_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_6_CH_01_CTPATT_PTRN_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_6_CH_01_CTPATT_PTRN_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_6_ch_01_ctpatt_ptrn_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_6_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_6_ch_01_ctpatt_ptrn_setf(uint32_t ch01ctpattptrn)
{
	ASSERT_ERR((((uint32_t)ch01ctpattptrn << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_6_ADDR, (uint32_t)ch01ctpattptrn << 0);
}

/**
 * @brief LCU_CH_01_CTPATT_PTRN_REG_7 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPATT_PTRN          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_7_ADDR        (REG_LCU_PHY_BASE_ADDR+0x0000011C)
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_7_OFFSET      0x0000011C
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_7_INDEX       0x00000047
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_7_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_7_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_7_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_7_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_7_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_7_CH_01_CTPATT_PTRN_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_7_CH_01_CTPATT_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_7_CH_01_CTPATT_PTRN_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_7_CH_01_CTPATT_PTRN_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_7_ch_01_ctpatt_ptrn_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_7_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_7_ch_01_ctpatt_ptrn_setf(uint32_t ch01ctpattptrn)
{
	ASSERT_ERR((((uint32_t)ch01ctpattptrn << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_7_ADDR, (uint32_t)ch01ctpattptrn << 0);
}

/**
 * @brief LCU_CH_01_CTPATT_MASK_REG_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPATT_MASK          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_0_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000120)
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_0_OFFSET      0x00000120
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_0_INDEX       0x00000048
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_0_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_ctpatt_mask_reg_0_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_0_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_ctpatt_mask_reg_0_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_0_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_0_CH_01_CTPATT_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_0_CH_01_CTPATT_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_0_CH_01_CTPATT_MASK_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_0_CH_01_CTPATT_MASK_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_ctpatt_mask_reg_0_ch_01_ctpatt_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_0_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_ctpatt_mask_reg_0_ch_01_ctpatt_mask_setf(uint32_t ch01ctpattmask)
{
	ASSERT_ERR((((uint32_t)ch01ctpattmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_0_ADDR, (uint32_t)ch01ctpattmask << 0);
}

/**
 * @brief LCU_CH_01_CTPATT_MASK_REG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPATT_MASK          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_1_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000124)
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_1_OFFSET      0x00000124
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_1_INDEX       0x00000049
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_1_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_ctpatt_mask_reg_1_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_1_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_ctpatt_mask_reg_1_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_1_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_1_CH_01_CTPATT_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_1_CH_01_CTPATT_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_1_CH_01_CTPATT_MASK_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_1_CH_01_CTPATT_MASK_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_ctpatt_mask_reg_1_ch_01_ctpatt_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_1_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_ctpatt_mask_reg_1_ch_01_ctpatt_mask_setf(uint32_t ch01ctpattmask)
{
	ASSERT_ERR((((uint32_t)ch01ctpattmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_1_ADDR, (uint32_t)ch01ctpattmask << 0);
}

/**
 * @brief LCU_CH_01_CTPATT_MASK_REG_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPATT_MASK          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_2_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000128)
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_2_OFFSET      0x00000128
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_2_INDEX       0x0000004A
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_2_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_ctpatt_mask_reg_2_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_2_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_ctpatt_mask_reg_2_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_2_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_2_CH_01_CTPATT_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_2_CH_01_CTPATT_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_2_CH_01_CTPATT_MASK_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_2_CH_01_CTPATT_MASK_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_ctpatt_mask_reg_2_ch_01_ctpatt_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_2_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_ctpatt_mask_reg_2_ch_01_ctpatt_mask_setf(uint32_t ch01ctpattmask)
{
	ASSERT_ERR((((uint32_t)ch01ctpattmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_2_ADDR, (uint32_t)ch01ctpattmask << 0);
}

/**
 * @brief LCU_CH_01_CTPATT_MASK_REG_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPATT_MASK          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_3_ADDR        (REG_LCU_PHY_BASE_ADDR+0x0000012C)
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_3_OFFSET      0x0000012C
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_3_INDEX       0x0000004B
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_3_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_ctpatt_mask_reg_3_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_3_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_ctpatt_mask_reg_3_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_3_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_3_CH_01_CTPATT_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_3_CH_01_CTPATT_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_3_CH_01_CTPATT_MASK_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_3_CH_01_CTPATT_MASK_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_ctpatt_mask_reg_3_ch_01_ctpatt_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_3_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_ctpatt_mask_reg_3_ch_01_ctpatt_mask_setf(uint32_t ch01ctpattmask)
{
	ASSERT_ERR((((uint32_t)ch01ctpattmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_3_ADDR, (uint32_t)ch01ctpattmask << 0);
}

/**
 * @brief LCU_CH_01_CTPATT_MASK_REG_4 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPATT_MASK          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_4_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000130)
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_4_OFFSET      0x00000130
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_4_INDEX       0x0000004C
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_4_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_ctpatt_mask_reg_4_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_4_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_ctpatt_mask_reg_4_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_4_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_4_CH_01_CTPATT_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_4_CH_01_CTPATT_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_4_CH_01_CTPATT_MASK_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_4_CH_01_CTPATT_MASK_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_ctpatt_mask_reg_4_ch_01_ctpatt_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_4_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_ctpatt_mask_reg_4_ch_01_ctpatt_mask_setf(uint32_t ch01ctpattmask)
{
	ASSERT_ERR((((uint32_t)ch01ctpattmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_4_ADDR, (uint32_t)ch01ctpattmask << 0);
}

/**
 * @brief LCU_CH_01_CTPATT_MASK_REG_5 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPATT_MASK          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_5_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000134)
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_5_OFFSET      0x00000134
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_5_INDEX       0x0000004D
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_5_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_ctpatt_mask_reg_5_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_5_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_ctpatt_mask_reg_5_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_5_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_5_CH_01_CTPATT_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_5_CH_01_CTPATT_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_5_CH_01_CTPATT_MASK_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_5_CH_01_CTPATT_MASK_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_ctpatt_mask_reg_5_ch_01_ctpatt_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_5_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_ctpatt_mask_reg_5_ch_01_ctpatt_mask_setf(uint32_t ch01ctpattmask)
{
	ASSERT_ERR((((uint32_t)ch01ctpattmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_5_ADDR, (uint32_t)ch01ctpattmask << 0);
}

/**
 * @brief LCU_CH_01_CTPATT_MASK_REG_6 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPATT_MASK          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_6_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000138)
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_6_OFFSET      0x00000138
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_6_INDEX       0x0000004E
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_6_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_ctpatt_mask_reg_6_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_6_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_ctpatt_mask_reg_6_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_6_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_6_CH_01_CTPATT_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_6_CH_01_CTPATT_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_6_CH_01_CTPATT_MASK_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_6_CH_01_CTPATT_MASK_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_ctpatt_mask_reg_6_ch_01_ctpatt_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_6_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_ctpatt_mask_reg_6_ch_01_ctpatt_mask_setf(uint32_t ch01ctpattmask)
{
	ASSERT_ERR((((uint32_t)ch01ctpattmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_6_ADDR, (uint32_t)ch01ctpattmask << 0);
}

/**
 * @brief LCU_CH_01_CTPATT_MASK_REG_7 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPATT_MASK          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_7_ADDR        (REG_LCU_PHY_BASE_ADDR+0x0000013C)
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_7_OFFSET      0x0000013C
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_7_INDEX       0x0000004F
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_7_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_01_ctpatt_mask_reg_7_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_7_ADDR);
}

__INLINE void lcu_phy_lcu_ch_01_ctpatt_mask_reg_7_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_7_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_7_CH_01_CTPATT_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_7_CH_01_CTPATT_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_7_CH_01_CTPATT_MASK_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_7_CH_01_CTPATT_MASK_RST    0x0

__INLINE uint32_t lcu_phy_lcu_ch_01_ctpatt_mask_reg_7_ch_01_ctpatt_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_7_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_ch_01_ctpatt_mask_reg_7_ch_01_ctpatt_mask_setf(uint32_t ch01ctpattmask)
{
	ASSERT_ERR((((uint32_t)ch01ctpattmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_7_ADDR, (uint32_t)ch01ctpattmask << 0);
}

/**
 * @brief LCU_MICTORS_BITMAP_REG_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    29:24 MICTOR4_INDX              0x3F
 *    23:18 MICTOR3_INDX              0x3F
 *    17:12 MICTOR2_INDX              0x3F
 *    11:06 MICTOR1_INDX              0x3F
 *    05:00 MICTOR0_INDX              0x3F
 * </pre>
 */
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000140)
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_OFFSET      0x00000140
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_INDEX       0x00000050
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_RESET       0x3FFFFFFF

__INLINE uint32_t  lcu_phy_lcu_mictors_bitmap_reg_0_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_MICTORS_BITMAP_REG_0_ADDR);
}

__INLINE void lcu_phy_lcu_mictors_bitmap_reg_0_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_MICTORS_BITMAP_REG_0_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_MICTOR_4_INDX_MASK    ((uint32_t)0x3F000000)
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_MICTOR_4_INDX_LSB    24
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_MICTOR_4_INDX_WIDTH    ((uint32_t)0x00000006)
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_MICTOR_3_INDX_MASK    ((uint32_t)0x00FC0000)
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_MICTOR_3_INDX_LSB    18
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_MICTOR_3_INDX_WIDTH    ((uint32_t)0x00000006)
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_MICTOR_2_INDX_MASK    ((uint32_t)0x0003F000)
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_MICTOR_2_INDX_LSB    12
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_MICTOR_2_INDX_WIDTH    ((uint32_t)0x00000006)
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_MICTOR_1_INDX_MASK    ((uint32_t)0x00000FC0)
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_MICTOR_1_INDX_LSB    6
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_MICTOR_1_INDX_WIDTH    ((uint32_t)0x00000006)
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_MICTOR_0_INDX_MASK    ((uint32_t)0x0000003F)
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_MICTOR_0_INDX_LSB    0
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_MICTOR_0_INDX_WIDTH    ((uint32_t)0x00000006)

#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_MICTOR_4_INDX_RST    0x3F
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_MICTOR_3_INDX_RST    0x3F
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_MICTOR_2_INDX_RST    0x3F
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_MICTOR_1_INDX_RST    0x3F
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_MICTOR_0_INDX_RST    0x3F

__INLINE void lcu_phy_lcu_mictors_bitmap_reg_0_pack(uint8_t mictor4_indx, uint8_t mictor3_indx, uint8_t mictor2_indx, uint8_t mictor1_indx, uint8_t mictor0_indx)
{
	ASSERT_ERR((((uint32_t)mictor4_indx << 24) & ~((uint32_t)0x3F000000)) == 0);
	ASSERT_ERR((((uint32_t)mictor3_indx << 18) & ~((uint32_t)0x00FC0000)) == 0);
	ASSERT_ERR((((uint32_t)mictor2_indx << 12) & ~((uint32_t)0x0003F000)) == 0);
	ASSERT_ERR((((uint32_t)mictor1_indx << 6) & ~((uint32_t)0x00000FC0)) == 0);
	ASSERT_ERR((((uint32_t)mictor0_indx << 0) & ~((uint32_t)0x0000003F)) == 0);
	REG_PL_WR(LCU_PHY_LCU_MICTORS_BITMAP_REG_0_ADDR,  ((uint32_t)mictor4_indx << 24) |((uint32_t)mictor3_indx << 18) |((uint32_t)mictor2_indx << 12) |((uint32_t)mictor1_indx << 6) |((uint32_t)mictor0_indx << 0));
}

__INLINE void lcu_phy_lcu_mictors_bitmap_reg_0_unpack(uint8_t* mictor4_indx, uint8_t* mictor3_indx, uint8_t* mictor2_indx, uint8_t* mictor1_indx, uint8_t* mictor0_indx)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_MICTORS_BITMAP_REG_0_ADDR);

	*mictor4_indx = (localVal & ((uint32_t)0x3F000000)) >>  24;
	*mictor3_indx = (localVal & ((uint32_t)0x00FC0000)) >>  18;
	*mictor2_indx = (localVal & ((uint32_t)0x0003F000)) >>  12;
	*mictor1_indx = (localVal & ((uint32_t)0x00000FC0)) >>  6;
	*mictor0_indx = (localVal & ((uint32_t)0x0000003F)) >>  0;
}

__INLINE uint8_t lcu_phy_lcu_mictors_bitmap_reg_0_mictor_4_indx_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_MICTORS_BITMAP_REG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x3F000000)) >> 24);
}
__INLINE void lcu_phy_lcu_mictors_bitmap_reg_0_mictor_4_indx_setf(uint8_t mictor4indx)
{
	ASSERT_ERR((((uint32_t)mictor4indx << 24) & ~((uint32_t)0x3F000000)) == 0);
	REG_PL_WR(LCU_PHY_LCU_MICTORS_BITMAP_REG_0_ADDR, (REG_PL_RD(LCU_PHY_LCU_MICTORS_BITMAP_REG_0_ADDR) & ~((uint32_t)0x3F000000)) | ((uint32_t)mictor4indx <<24));
}
__INLINE uint8_t lcu_phy_lcu_mictors_bitmap_reg_0_mictor_3_indx_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_MICTORS_BITMAP_REG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FC0000)) >> 18);
}
__INLINE void lcu_phy_lcu_mictors_bitmap_reg_0_mictor_3_indx_setf(uint8_t mictor3indx)
{
	ASSERT_ERR((((uint32_t)mictor3indx << 18) & ~((uint32_t)0x00FC0000)) == 0);
	REG_PL_WR(LCU_PHY_LCU_MICTORS_BITMAP_REG_0_ADDR, (REG_PL_RD(LCU_PHY_LCU_MICTORS_BITMAP_REG_0_ADDR) & ~((uint32_t)0x00FC0000)) | ((uint32_t)mictor3indx <<18));
}
__INLINE uint8_t lcu_phy_lcu_mictors_bitmap_reg_0_mictor_2_indx_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_MICTORS_BITMAP_REG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0003F000)) >> 12);
}
__INLINE void lcu_phy_lcu_mictors_bitmap_reg_0_mictor_2_indx_setf(uint8_t mictor2indx)
{
	ASSERT_ERR((((uint32_t)mictor2indx << 12) & ~((uint32_t)0x0003F000)) == 0);
	REG_PL_WR(LCU_PHY_LCU_MICTORS_BITMAP_REG_0_ADDR, (REG_PL_RD(LCU_PHY_LCU_MICTORS_BITMAP_REG_0_ADDR) & ~((uint32_t)0x0003F000)) | ((uint32_t)mictor2indx <<12));
}
__INLINE uint8_t lcu_phy_lcu_mictors_bitmap_reg_0_mictor_1_indx_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_MICTORS_BITMAP_REG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000FC0)) >> 6);
}
__INLINE void lcu_phy_lcu_mictors_bitmap_reg_0_mictor_1_indx_setf(uint8_t mictor1indx)
{
	ASSERT_ERR((((uint32_t)mictor1indx << 6) & ~((uint32_t)0x00000FC0)) == 0);
	REG_PL_WR(LCU_PHY_LCU_MICTORS_BITMAP_REG_0_ADDR, (REG_PL_RD(LCU_PHY_LCU_MICTORS_BITMAP_REG_0_ADDR) & ~((uint32_t)0x00000FC0)) | ((uint32_t)mictor1indx <<6));
}
__INLINE uint8_t lcu_phy_lcu_mictors_bitmap_reg_0_mictor_0_indx_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_MICTORS_BITMAP_REG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000003F)) >> 0);
}
__INLINE void lcu_phy_lcu_mictors_bitmap_reg_0_mictor_0_indx_setf(uint8_t mictor0indx)
{
	ASSERT_ERR((((uint32_t)mictor0indx << 0) & ~((uint32_t)0x0000003F)) == 0);
	REG_PL_WR(LCU_PHY_LCU_MICTORS_BITMAP_REG_0_ADDR, (REG_PL_RD(LCU_PHY_LCU_MICTORS_BITMAP_REG_0_ADDR) & ~((uint32_t)0x0000003F)) | ((uint32_t)mictor0indx <<0));
}

/**
 * @brief LCU_MICTORS_BITMAP_REG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    11:06 MICTOR6_INDX              0x3F
 *    05:00 MICTOR5_INDX              0x3F
 * </pre>
 */
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_1_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000144)
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_1_OFFSET      0x00000144
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_1_INDEX       0x00000051
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_1_RESET       0x00000FFF

__INLINE uint32_t  lcu_phy_lcu_mictors_bitmap_reg_1_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_MICTORS_BITMAP_REG_1_ADDR);
}

__INLINE void lcu_phy_lcu_mictors_bitmap_reg_1_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_MICTORS_BITMAP_REG_1_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_1_MICTOR_6_INDX_MASK    ((uint32_t)0x00000FC0)
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_1_MICTOR_6_INDX_LSB    6
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_1_MICTOR_6_INDX_WIDTH    ((uint32_t)0x00000006)
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_1_MICTOR_5_INDX_MASK    ((uint32_t)0x0000003F)
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_1_MICTOR_5_INDX_LSB    0
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_1_MICTOR_5_INDX_WIDTH    ((uint32_t)0x00000006)

#define LCU_PHY_LCU_MICTORS_BITMAP_REG_1_MICTOR_6_INDX_RST    0x3F
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_1_MICTOR_5_INDX_RST    0x3F

__INLINE void lcu_phy_lcu_mictors_bitmap_reg_1_pack(uint8_t mictor6_indx, uint8_t mictor5_indx)
{
	ASSERT_ERR((((uint32_t)mictor6_indx << 6) & ~((uint32_t)0x00000FC0)) == 0);
	ASSERT_ERR((((uint32_t)mictor5_indx << 0) & ~((uint32_t)0x0000003F)) == 0);
	REG_PL_WR(LCU_PHY_LCU_MICTORS_BITMAP_REG_1_ADDR,  ((uint32_t)mictor6_indx << 6) |((uint32_t)mictor5_indx << 0));
}

__INLINE void lcu_phy_lcu_mictors_bitmap_reg_1_unpack(uint8_t* mictor6_indx, uint8_t* mictor5_indx)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_MICTORS_BITMAP_REG_1_ADDR);

	*mictor6_indx = (localVal & ((uint32_t)0x00000FC0)) >>  6;
	*mictor5_indx = (localVal & ((uint32_t)0x0000003F)) >>  0;
}

__INLINE uint8_t lcu_phy_lcu_mictors_bitmap_reg_1_mictor_6_indx_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_MICTORS_BITMAP_REG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000FC0)) >> 6);
}
__INLINE void lcu_phy_lcu_mictors_bitmap_reg_1_mictor_6_indx_setf(uint8_t mictor6indx)
{
	ASSERT_ERR((((uint32_t)mictor6indx << 6) & ~((uint32_t)0x00000FC0)) == 0);
	REG_PL_WR(LCU_PHY_LCU_MICTORS_BITMAP_REG_1_ADDR, (REG_PL_RD(LCU_PHY_LCU_MICTORS_BITMAP_REG_1_ADDR) & ~((uint32_t)0x00000FC0)) | ((uint32_t)mictor6indx <<6));
}
__INLINE uint8_t lcu_phy_lcu_mictors_bitmap_reg_1_mictor_5_indx_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_MICTORS_BITMAP_REG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000003F)) >> 0);
}
__INLINE void lcu_phy_lcu_mictors_bitmap_reg_1_mictor_5_indx_setf(uint8_t mictor5indx)
{
	ASSERT_ERR((((uint32_t)mictor5indx << 0) & ~((uint32_t)0x0000003F)) == 0);
	REG_PL_WR(LCU_PHY_LCU_MICTORS_BITMAP_REG_1_ADDR, (REG_PL_RD(LCU_PHY_LCU_MICTORS_BITMAP_REG_1_ADDR) & ~((uint32_t)0x0000003F)) | ((uint32_t)mictor5indx <<0));
}

/**
 * @brief LCU_DMEM_START_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DMEM_START_ADDR           0x0
 * </pre>
 */
#define LCU_PHY_LCU_DMEM_START_ADDR_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000148)
#define LCU_PHY_LCU_DMEM_START_ADDR_OFFSET      0x00000148
#define LCU_PHY_LCU_DMEM_START_ADDR_INDEX       0x00000052
#define LCU_PHY_LCU_DMEM_START_ADDR_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_dmem_start_addr_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_DMEM_START_ADDR_ADDR);
}

__INLINE void lcu_phy_lcu_dmem_start_addr_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_DMEM_START_ADDR_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_DMEM_START_ADDR_DMEM_START_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_PHY_LCU_DMEM_START_ADDR_DMEM_START_ADDR_LSB    0
#define LCU_PHY_LCU_DMEM_START_ADDR_DMEM_START_ADDR_WIDTH    ((uint32_t)0x00000020)

#define LCU_PHY_LCU_DMEM_START_ADDR_DMEM_START_ADDR_RST    0x0

__INLINE uint32_t lcu_phy_lcu_dmem_start_addr_dmem_start_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_DMEM_START_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_dmem_start_addr_dmem_start_addr_setf(uint32_t dmemstartaddr)
{
	ASSERT_ERR((((uint32_t)dmemstartaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_DMEM_START_ADDR_ADDR, (uint32_t)dmemstartaddr << 0);
}

/**
 * @brief LCU_DMEM_SIZE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    19:00 DMEM_SIZE                 0x0
 * </pre>
 */
#define LCU_PHY_LCU_DMEM_SIZE_ADDR        (REG_LCU_PHY_BASE_ADDR+0x0000014C)
#define LCU_PHY_LCU_DMEM_SIZE_OFFSET      0x0000014C
#define LCU_PHY_LCU_DMEM_SIZE_INDEX       0x00000053
#define LCU_PHY_LCU_DMEM_SIZE_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_dmem_size_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_DMEM_SIZE_ADDR);
}

__INLINE void lcu_phy_lcu_dmem_size_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_DMEM_SIZE_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_DMEM_SIZE_DMEM_SIZE_MASK    ((uint32_t)0x000FFFFF)
#define LCU_PHY_LCU_DMEM_SIZE_DMEM_SIZE_LSB    0
#define LCU_PHY_LCU_DMEM_SIZE_DMEM_SIZE_WIDTH    ((uint32_t)0x00000014)

#define LCU_PHY_LCU_DMEM_SIZE_DMEM_SIZE_RST    0x0

__INLINE uint32_t lcu_phy_lcu_dmem_size_dmem_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_DMEM_SIZE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_dmem_size_dmem_size_setf(uint32_t dmemsize)
{
	ASSERT_ERR((((uint32_t)dmemsize << 0) & ~((uint32_t)0x000FFFFF)) == 0);
	REG_PL_WR(LCU_PHY_LCU_DMEM_SIZE_ADDR, (uint32_t)dmemsize << 0);
}

/**
 * @brief LCU_MPIF_DATA_SEL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01:00 MPIF_DATA_SEL             0x1
 * </pre>
 */
#define LCU_PHY_LCU_MPIF_DATA_SEL_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000150)
#define LCU_PHY_LCU_MPIF_DATA_SEL_OFFSET      0x00000150
#define LCU_PHY_LCU_MPIF_DATA_SEL_INDEX       0x00000054
#define LCU_PHY_LCU_MPIF_DATA_SEL_RESET       0x00000001

__INLINE uint32_t  lcu_phy_lcu_mpif_data_sel_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_MPIF_DATA_SEL_ADDR);
}

__INLINE void lcu_phy_lcu_mpif_data_sel_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_MPIF_DATA_SEL_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_MPIF_DATA_SEL_MPIF_DATA_SEL_MASK    ((uint32_t)0x00000003)
#define LCU_PHY_LCU_MPIF_DATA_SEL_MPIF_DATA_SEL_LSB    0
#define LCU_PHY_LCU_MPIF_DATA_SEL_MPIF_DATA_SEL_WIDTH    ((uint32_t)0x00000002)

#define LCU_PHY_LCU_MPIF_DATA_SEL_MPIF_DATA_SEL_RST    0x1

__INLINE uint8_t lcu_phy_lcu_mpif_data_sel_mpif_data_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_MPIF_DATA_SEL_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_mpif_data_sel_mpif_data_sel_setf(uint8_t mpifdatasel)
{
	ASSERT_ERR((((uint32_t)mpifdatasel << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(LCU_PHY_LCU_MPIF_DATA_SEL_ADDR, (uint32_t)mpifdatasel << 0);
}

/**
 * @brief LCU_SW_RST register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    SW_RST                    0              
 * </pre>
 */
#define LCU_PHY_LCU_SW_RST_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000154)
#define LCU_PHY_LCU_SW_RST_OFFSET      0x00000154
#define LCU_PHY_LCU_SW_RST_INDEX       0x00000055
#define LCU_PHY_LCU_SW_RST_RESET       0x00000000

__INLINE void lcu_phy_lcu_sw_rst_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_SW_RST_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_SW_RST_SW_RST_BIT       ((uint32_t)0x00000001)
#define LCU_PHY_LCU_SW_RST_SW_RST_POS       0

#define LCU_PHY_LCU_SW_RST_SW_RST_RST       0x0

__INLINE void lcu_phy_lcu_sw_rst_sw_rst_setf(uint8_t swrst)
{
	ASSERT_ERR((((uint32_t)swrst << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_PHY_LCU_SW_RST_ADDR, (uint32_t)swrst << 0);
}

/**
 * @brief LCU_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    05    AXI_WDATA_FIFO_OVF        0              
 *    04    AXI_ADDR_FIFO_OVF         0              
 *    03    MICTOR2_OVF               0              
 *    02    MICTOR1_OVF               0              
 *    01    MICTOR0_OVF               0              
 *    00    DSP_DMEM_FINISH           0              
 * </pre>
 */
#define LCU_PHY_LCU_STATUS_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000158)
#define LCU_PHY_LCU_STATUS_OFFSET      0x00000158
#define LCU_PHY_LCU_STATUS_INDEX       0x00000056
#define LCU_PHY_LCU_STATUS_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_status_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_STATUS_ADDR);
}

// field definitions
#define LCU_PHY_LCU_STATUS_AXI_WDATA_FIFO_OVF_BIT    ((uint32_t)0x00000020)
#define LCU_PHY_LCU_STATUS_AXI_WDATA_FIFO_OVF_POS    5
#define LCU_PHY_LCU_STATUS_AXI_ADDR_FIFO_OVF_BIT    ((uint32_t)0x00000010)
#define LCU_PHY_LCU_STATUS_AXI_ADDR_FIFO_OVF_POS    4
#define LCU_PHY_LCU_STATUS_MICTOR_2_OVF_BIT    ((uint32_t)0x00000008)
#define LCU_PHY_LCU_STATUS_MICTOR_2_OVF_POS    3
#define LCU_PHY_LCU_STATUS_MICTOR_1_OVF_BIT    ((uint32_t)0x00000004)
#define LCU_PHY_LCU_STATUS_MICTOR_1_OVF_POS    2
#define LCU_PHY_LCU_STATUS_MICTOR_0_OVF_BIT    ((uint32_t)0x00000002)
#define LCU_PHY_LCU_STATUS_MICTOR_0_OVF_POS    1
#define LCU_PHY_LCU_STATUS_DSP_DMEM_FINISH_BIT    ((uint32_t)0x00000001)
#define LCU_PHY_LCU_STATUS_DSP_DMEM_FINISH_POS    0

#define LCU_PHY_LCU_STATUS_AXI_WDATA_FIFO_OVF_RST    0x0
#define LCU_PHY_LCU_STATUS_AXI_ADDR_FIFO_OVF_RST    0x0
#define LCU_PHY_LCU_STATUS_MICTOR_2_OVF_RST    0x0
#define LCU_PHY_LCU_STATUS_MICTOR_1_OVF_RST    0x0
#define LCU_PHY_LCU_STATUS_MICTOR_0_OVF_RST    0x0
#define LCU_PHY_LCU_STATUS_DSP_DMEM_FINISH_RST    0x0

__INLINE void lcu_phy_lcu_status_unpack(uint8_t* axi_wdata_fifo_ovf, uint8_t* axi_addr_fifo_ovf, uint8_t* mictor2_ovf, uint8_t* mictor1_ovf, uint8_t* mictor0_ovf, uint8_t* dsp_dmem_finish)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_STATUS_ADDR);

	*axi_wdata_fifo_ovf = (localVal & ((uint32_t)0x00000020)) >>  5;
	*axi_addr_fifo_ovf = (localVal & ((uint32_t)0x00000010)) >>  4;
	*mictor2_ovf = (localVal & ((uint32_t)0x00000008)) >>  3;
	*mictor1_ovf = (localVal & ((uint32_t)0x00000004)) >>  2;
	*mictor0_ovf = (localVal & ((uint32_t)0x00000002)) >>  1;
	*dsp_dmem_finish = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t lcu_phy_lcu_status_axi_wdata_fifo_ovf_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE uint8_t lcu_phy_lcu_status_axi_addr_fifo_ovf_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE uint8_t lcu_phy_lcu_status_mictor_2_ovf_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE uint8_t lcu_phy_lcu_status_mictor_1_ovf_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE uint8_t lcu_phy_lcu_status_mictor_0_ovf_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t lcu_phy_lcu_status_dsp_dmem_finish_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief LCU_CH_0_TRIG_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    17:16 CH0_EXT_STOP_TRIG_STAT    0x0
 *    13:12 CH0_FIC_STOP_TRIG_STAT    0x0
 *    09:08 CH0_STOP_PTRN_TRIG_STAT   0x0
 *    05:04 CH0_EXT_STRT_TRIG_STAT    0x0
 *    01:00 CH0_STRT_PTRN_TRIG_STAT   0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_ADDR        (REG_LCU_PHY_BASE_ADDR+0x0000015C)
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_OFFSET      0x0000015C
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_INDEX       0x00000057
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_0_trig_status_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_0_TRIG_STATUS_ADDR);
}

// field definitions
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_CH_0_EXT_STOP_TRIG_STAT_MASK    ((uint32_t)0x00030000)
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_CH_0_EXT_STOP_TRIG_STAT_LSB    16
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_CH_0_EXT_STOP_TRIG_STAT_WIDTH    ((uint32_t)0x00000002)
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_CH_0_FIC_STOP_TRIG_STAT_MASK    ((uint32_t)0x00003000)
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_CH_0_FIC_STOP_TRIG_STAT_LSB    12
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_CH_0_FIC_STOP_TRIG_STAT_WIDTH    ((uint32_t)0x00000002)
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_CH_0_STOP_PTRN_TRIG_STAT_MASK    ((uint32_t)0x00000300)
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_CH_0_STOP_PTRN_TRIG_STAT_LSB    8
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_CH_0_STOP_PTRN_TRIG_STAT_WIDTH    ((uint32_t)0x00000002)
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_CH_0_EXT_STRT_TRIG_STAT_MASK    ((uint32_t)0x00000030)
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_CH_0_EXT_STRT_TRIG_STAT_LSB    4
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_CH_0_EXT_STRT_TRIG_STAT_WIDTH    ((uint32_t)0x00000002)
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_CH_0_STRT_PTRN_TRIG_STAT_MASK    ((uint32_t)0x00000003)
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_CH_0_STRT_PTRN_TRIG_STAT_LSB    0
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_CH_0_STRT_PTRN_TRIG_STAT_WIDTH    ((uint32_t)0x00000002)

#define LCU_PHY_LCU_CH_0_TRIG_STATUS_CH_0_EXT_STOP_TRIG_STAT_RST    0x0
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_CH_0_FIC_STOP_TRIG_STAT_RST    0x0
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_CH_0_STOP_PTRN_TRIG_STAT_RST    0x0
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_CH_0_EXT_STRT_TRIG_STAT_RST    0x0
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_CH_0_STRT_PTRN_TRIG_STAT_RST    0x0

__INLINE void lcu_phy_lcu_ch_0_trig_status_unpack(uint8_t* ch0_ext_stop_trig_stat, uint8_t* ch0_fic_stop_trig_stat, uint8_t* ch0_stop_ptrn_trig_stat, uint8_t* ch0_ext_strt_trig_stat, uint8_t* ch0_strt_ptrn_trig_stat)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_0_TRIG_STATUS_ADDR);

	*ch0_ext_stop_trig_stat = (localVal & ((uint32_t)0x00030000)) >>  16;
	*ch0_fic_stop_trig_stat = (localVal & ((uint32_t)0x00003000)) >>  12;
	*ch0_stop_ptrn_trig_stat = (localVal & ((uint32_t)0x00000300)) >>  8;
	*ch0_ext_strt_trig_stat = (localVal & ((uint32_t)0x00000030)) >>  4;
	*ch0_strt_ptrn_trig_stat = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint8_t lcu_phy_lcu_ch_0_trig_status_ch_0_ext_stop_trig_stat_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_0_TRIG_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00030000)) >> 16);
}
__INLINE uint8_t lcu_phy_lcu_ch_0_trig_status_ch_0_fic_stop_trig_stat_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_0_TRIG_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00003000)) >> 12);
}
__INLINE uint8_t lcu_phy_lcu_ch_0_trig_status_ch_0_stop_ptrn_trig_stat_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_0_TRIG_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000300)) >> 8);
}
__INLINE uint8_t lcu_phy_lcu_ch_0_trig_status_ch_0_ext_strt_trig_stat_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_0_TRIG_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000030)) >> 4);
}
__INLINE uint8_t lcu_phy_lcu_ch_0_trig_status_ch_0_strt_ptrn_trig_stat_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_0_TRIG_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}

/**
 * @brief LCU_CH_1_TRIG_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    09:08 CH1_FIC_STOP_TRIG_STAT    0x0
 *    05:04 CH1_STOP_PTRN_TRIG_STAT   0x0
 *    01:00 CH1_STRT_PTRN_TRIG_STAT   0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_1_TRIG_STATUS_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000160)
#define LCU_PHY_LCU_CH_1_TRIG_STATUS_OFFSET      0x00000160
#define LCU_PHY_LCU_CH_1_TRIG_STATUS_INDEX       0x00000058
#define LCU_PHY_LCU_CH_1_TRIG_STATUS_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_ch_1_trig_status_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_CH_1_TRIG_STATUS_ADDR);
}

// field definitions
#define LCU_PHY_LCU_CH_1_TRIG_STATUS_CH_1_FIC_STOP_TRIG_STAT_MASK    ((uint32_t)0x00000300)
#define LCU_PHY_LCU_CH_1_TRIG_STATUS_CH_1_FIC_STOP_TRIG_STAT_LSB    8
#define LCU_PHY_LCU_CH_1_TRIG_STATUS_CH_1_FIC_STOP_TRIG_STAT_WIDTH    ((uint32_t)0x00000002)
#define LCU_PHY_LCU_CH_1_TRIG_STATUS_CH_1_STOP_PTRN_TRIG_STAT_MASK    ((uint32_t)0x00000030)
#define LCU_PHY_LCU_CH_1_TRIG_STATUS_CH_1_STOP_PTRN_TRIG_STAT_LSB    4
#define LCU_PHY_LCU_CH_1_TRIG_STATUS_CH_1_STOP_PTRN_TRIG_STAT_WIDTH    ((uint32_t)0x00000002)
#define LCU_PHY_LCU_CH_1_TRIG_STATUS_CH_1_STRT_PTRN_TRIG_STAT_MASK    ((uint32_t)0x00000003)
#define LCU_PHY_LCU_CH_1_TRIG_STATUS_CH_1_STRT_PTRN_TRIG_STAT_LSB    0
#define LCU_PHY_LCU_CH_1_TRIG_STATUS_CH_1_STRT_PTRN_TRIG_STAT_WIDTH    ((uint32_t)0x00000002)

#define LCU_PHY_LCU_CH_1_TRIG_STATUS_CH_1_FIC_STOP_TRIG_STAT_RST    0x0
#define LCU_PHY_LCU_CH_1_TRIG_STATUS_CH_1_STOP_PTRN_TRIG_STAT_RST    0x0
#define LCU_PHY_LCU_CH_1_TRIG_STATUS_CH_1_STRT_PTRN_TRIG_STAT_RST    0x0

__INLINE void lcu_phy_lcu_ch_1_trig_status_unpack(uint8_t* ch1_fic_stop_trig_stat, uint8_t* ch1_stop_ptrn_trig_stat, uint8_t* ch1_strt_ptrn_trig_stat)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_1_TRIG_STATUS_ADDR);

	*ch1_fic_stop_trig_stat = (localVal & ((uint32_t)0x00000300)) >>  8;
	*ch1_stop_ptrn_trig_stat = (localVal & ((uint32_t)0x00000030)) >>  4;
	*ch1_strt_ptrn_trig_stat = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint8_t lcu_phy_lcu_ch_1_trig_status_ch_1_fic_stop_trig_stat_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_1_TRIG_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000300)) >> 8);
}
__INLINE uint8_t lcu_phy_lcu_ch_1_trig_status_ch_1_stop_ptrn_trig_stat_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_1_TRIG_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000030)) >> 4);
}
__INLINE uint8_t lcu_phy_lcu_ch_1_trig_status_ch_1_strt_ptrn_trig_stat_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_CH_1_TRIG_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}

/**
 * @brief LCU_RX_RIU_OUT_SEL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    02:00 RX_RIU_OUT_SEL            0x0
 * </pre>
 */
#define LCU_PHY_LCU_RX_RIU_OUT_SEL_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000164)
#define LCU_PHY_LCU_RX_RIU_OUT_SEL_OFFSET      0x00000164
#define LCU_PHY_LCU_RX_RIU_OUT_SEL_INDEX       0x00000059
#define LCU_PHY_LCU_RX_RIU_OUT_SEL_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_rx_riu_out_sel_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_RX_RIU_OUT_SEL_ADDR);
}

__INLINE void lcu_phy_lcu_rx_riu_out_sel_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_RX_RIU_OUT_SEL_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_RX_RIU_OUT_SEL_RX_RIU_OUT_SEL_MASK    ((uint32_t)0x00000007)
#define LCU_PHY_LCU_RX_RIU_OUT_SEL_RX_RIU_OUT_SEL_LSB    0
#define LCU_PHY_LCU_RX_RIU_OUT_SEL_RX_RIU_OUT_SEL_WIDTH    ((uint32_t)0x00000003)

#define LCU_PHY_LCU_RX_RIU_OUT_SEL_RX_RIU_OUT_SEL_RST    0x0

__INLINE uint8_t lcu_phy_lcu_rx_riu_out_sel_rx_riu_out_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_RX_RIU_OUT_SEL_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void lcu_phy_lcu_rx_riu_out_sel_rx_riu_out_sel_setf(uint8_t rxriuoutsel)
{
	ASSERT_ERR((((uint32_t)rxriuoutsel << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(LCU_PHY_LCU_RX_RIU_OUT_SEL_ADDR, (uint32_t)rxriuoutsel << 0);
}

/**
 * @brief LCU_RIU_OUT_COMB_CONF register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    02    S2_3_CONF                 0              
 *    01:00 CH_BW                     0x0
 * </pre>
 */
#define LCU_PHY_LCU_RIU_OUT_COMB_CONF_ADDR        (REG_LCU_PHY_BASE_ADDR+0x00000168)
#define LCU_PHY_LCU_RIU_OUT_COMB_CONF_OFFSET      0x00000168
#define LCU_PHY_LCU_RIU_OUT_COMB_CONF_INDEX       0x0000005A
#define LCU_PHY_LCU_RIU_OUT_COMB_CONF_RESET       0x00000000

__INLINE uint32_t  lcu_phy_lcu_riu_out_comb_conf_get(void)
{
	return REG_PL_RD(LCU_PHY_LCU_RIU_OUT_COMB_CONF_ADDR);
}

__INLINE void lcu_phy_lcu_riu_out_comb_conf_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_RIU_OUT_COMB_CONF_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_RIU_OUT_COMB_CONF_S_2_3_CONF_BIT    ((uint32_t)0x00000004)
#define LCU_PHY_LCU_RIU_OUT_COMB_CONF_S_2_3_CONF_POS    2
#define LCU_PHY_LCU_RIU_OUT_COMB_CONF_CH_BW_MASK    ((uint32_t)0x00000003)
#define LCU_PHY_LCU_RIU_OUT_COMB_CONF_CH_BW_LSB    0
#define LCU_PHY_LCU_RIU_OUT_COMB_CONF_CH_BW_WIDTH    ((uint32_t)0x00000002)

#define LCU_PHY_LCU_RIU_OUT_COMB_CONF_S_2_3_CONF_RST    0x0
#define LCU_PHY_LCU_RIU_OUT_COMB_CONF_CH_BW_RST    0x0

__INLINE void lcu_phy_lcu_riu_out_comb_conf_pack(uint8_t s2_3_conf, uint8_t ch_bw)
{
	ASSERT_ERR((((uint32_t)s2_3_conf << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)ch_bw << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(LCU_PHY_LCU_RIU_OUT_COMB_CONF_ADDR,  ((uint32_t)s2_3_conf << 2) |((uint32_t)ch_bw << 0));
}

__INLINE void lcu_phy_lcu_riu_out_comb_conf_unpack(uint8_t* s2_3_conf, uint8_t* ch_bw)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_RIU_OUT_COMB_CONF_ADDR);

	*s2_3_conf = (localVal & ((uint32_t)0x00000004)) >>  2;
	*ch_bw = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint8_t lcu_phy_lcu_riu_out_comb_conf_s_2_3_conf_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_RIU_OUT_COMB_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void lcu_phy_lcu_riu_out_comb_conf_s_2_3_conf_setf(uint8_t s23conf)
{
	ASSERT_ERR((((uint32_t)s23conf << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(LCU_PHY_LCU_RIU_OUT_COMB_CONF_ADDR, (REG_PL_RD(LCU_PHY_LCU_RIU_OUT_COMB_CONF_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)s23conf <<2));
}
__INLINE uint8_t lcu_phy_lcu_riu_out_comb_conf_ch_bw_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_PHY_LCU_RIU_OUT_COMB_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void lcu_phy_lcu_riu_out_comb_conf_ch_bw_setf(uint8_t chbw)
{
	ASSERT_ERR((((uint32_t)chbw << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(LCU_PHY_LCU_RIU_OUT_COMB_CONF_ADDR, (REG_PL_RD(LCU_PHY_LCU_RIU_OUT_COMB_CONF_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)chbw <<0));
}

/**
 * @brief LCU_STATUS_CLEAR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    05    AXI_WDATA_FIFO_OVF_CLEAR  0              
 *    04    AXI_ADDR_FIFO_OVF_CLEAR   0              
 *    03    MICTOR2_OVF_CLEAR         0              
 *    02    MICTOR1_OVF_CLEAR         0              
 *    01    MICTOR0_OVF_CLEAR         0              
 * </pre>
 */
#define LCU_PHY_LCU_STATUS_CLEAR_ADDR        (REG_LCU_PHY_BASE_ADDR+0x0000016C)
#define LCU_PHY_LCU_STATUS_CLEAR_OFFSET      0x0000016C
#define LCU_PHY_LCU_STATUS_CLEAR_INDEX       0x0000005B
#define LCU_PHY_LCU_STATUS_CLEAR_RESET       0x00000000

__INLINE void lcu_phy_lcu_status_clear_set(uint32_t value)
{
	REG_PL_WR(LCU_PHY_LCU_STATUS_CLEAR_ADDR, value);
}

// field definitions
#define LCU_PHY_LCU_STATUS_CLEAR_AXI_WDATA_FIFO_OVF_CLEAR_BIT    ((uint32_t)0x00000020)
#define LCU_PHY_LCU_STATUS_CLEAR_AXI_WDATA_FIFO_OVF_CLEAR_POS    5
#define LCU_PHY_LCU_STATUS_CLEAR_AXI_ADDR_FIFO_OVF_CLEAR_BIT    ((uint32_t)0x00000010)
#define LCU_PHY_LCU_STATUS_CLEAR_AXI_ADDR_FIFO_OVF_CLEAR_POS    4
#define LCU_PHY_LCU_STATUS_CLEAR_MICTOR_2_OVF_CLEAR_BIT    ((uint32_t)0x00000008)
#define LCU_PHY_LCU_STATUS_CLEAR_MICTOR_2_OVF_CLEAR_POS    3
#define LCU_PHY_LCU_STATUS_CLEAR_MICTOR_1_OVF_CLEAR_BIT    ((uint32_t)0x00000004)
#define LCU_PHY_LCU_STATUS_CLEAR_MICTOR_1_OVF_CLEAR_POS    2
#define LCU_PHY_LCU_STATUS_CLEAR_MICTOR_0_OVF_CLEAR_BIT    ((uint32_t)0x00000002)
#define LCU_PHY_LCU_STATUS_CLEAR_MICTOR_0_OVF_CLEAR_POS    1

#define LCU_PHY_LCU_STATUS_CLEAR_AXI_WDATA_FIFO_OVF_CLEAR_RST    0x0
#define LCU_PHY_LCU_STATUS_CLEAR_AXI_ADDR_FIFO_OVF_CLEAR_RST    0x0
#define LCU_PHY_LCU_STATUS_CLEAR_MICTOR_2_OVF_CLEAR_RST    0x0
#define LCU_PHY_LCU_STATUS_CLEAR_MICTOR_1_OVF_CLEAR_RST    0x0
#define LCU_PHY_LCU_STATUS_CLEAR_MICTOR_0_OVF_CLEAR_RST    0x0

__INLINE void lcu_phy_lcu_status_clear_pack(uint8_t axi_wdata_fifo_ovf_clear, uint8_t axi_addr_fifo_ovf_clear, uint8_t mictor2_ovf_clear, uint8_t mictor1_ovf_clear, uint8_t mictor0_ovf_clear)
{
	ASSERT_ERR((((uint32_t)axi_wdata_fifo_ovf_clear << 5) & ~((uint32_t)0x00000020)) == 0);
	ASSERT_ERR((((uint32_t)axi_addr_fifo_ovf_clear << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)mictor2_ovf_clear << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)mictor1_ovf_clear << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)mictor0_ovf_clear << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(LCU_PHY_LCU_STATUS_CLEAR_ADDR,  ((uint32_t)axi_wdata_fifo_ovf_clear << 5) |((uint32_t)axi_addr_fifo_ovf_clear << 4) |((uint32_t)mictor2_ovf_clear << 3) |((uint32_t)mictor1_ovf_clear << 2) |((uint32_t)mictor0_ovf_clear << 1));
}

__INLINE void lcu_phy_lcu_status_clear_axi_wdata_fifo_ovf_clear_setf(uint8_t axiwdatafifoovfclear)
{
	ASSERT_ERR((((uint32_t)axiwdatafifoovfclear << 5) & ~((uint32_t)0x00000020)) == 0);
	REG_PL_WR(LCU_PHY_LCU_STATUS_CLEAR_ADDR, (REG_PL_RD(LCU_PHY_LCU_STATUS_CLEAR_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)axiwdatafifoovfclear <<5));
}
__INLINE void lcu_phy_lcu_status_clear_axi_addr_fifo_ovf_clear_setf(uint8_t axiaddrfifoovfclear)
{
	ASSERT_ERR((((uint32_t)axiaddrfifoovfclear << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(LCU_PHY_LCU_STATUS_CLEAR_ADDR, (REG_PL_RD(LCU_PHY_LCU_STATUS_CLEAR_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)axiaddrfifoovfclear <<4));
}
__INLINE void lcu_phy_lcu_status_clear_mictor_2_ovf_clear_setf(uint8_t mictor2ovfclear)
{
	ASSERT_ERR((((uint32_t)mictor2ovfclear << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(LCU_PHY_LCU_STATUS_CLEAR_ADDR, (REG_PL_RD(LCU_PHY_LCU_STATUS_CLEAR_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)mictor2ovfclear <<3));
}
__INLINE void lcu_phy_lcu_status_clear_mictor_1_ovf_clear_setf(uint8_t mictor1ovfclear)
{
	ASSERT_ERR((((uint32_t)mictor1ovfclear << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(LCU_PHY_LCU_STATUS_CLEAR_ADDR, (REG_PL_RD(LCU_PHY_LCU_STATUS_CLEAR_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)mictor1ovfclear <<2));
}
__INLINE void lcu_phy_lcu_status_clear_mictor_0_ovf_clear_setf(uint8_t mictor0ovfclear)
{
	ASSERT_ERR((((uint32_t)mictor0ovfclear << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(LCU_PHY_LCU_STATUS_CLEAR_ADDR, (REG_PL_RD(LCU_PHY_LCU_STATUS_CLEAR_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)mictor0ovfclear <<1));
}


#undef DBG_FILEID
#endif //_REG_LCU_PHY_H_

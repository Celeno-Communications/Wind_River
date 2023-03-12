#ifndef _REG_MPU_COMMON_H_
#define _REG_MPU_COMMON_H_

#include <stdint.h>
#include "phy/_reg_mpu_common.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define DBG_FILEID __REG_MPU_COMMON__H__FILEID__

#define REG_MPU_COMMON_COUNT  64


/**
 * @brief VERSION register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 VERSION                   0x0
 * </pre>
 */
#define MPU_COMMON_VERSION_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000000)
#define MPU_COMMON_VERSION_OFFSET      0x00000000
#define MPU_COMMON_VERSION_INDEX       0x00000000
#define MPU_COMMON_VERSION_RESET       0x00000000

__INLINE uint32_t  mpu_common_version_get(void)
{
	return REG_PL_RD(MPU_COMMON_VERSION_ADDR);
}

// field definitions
#define MPU_COMMON_VERSION_VERSION_MASK     ((uint32_t)0xFFFFFFFF)
#define MPU_COMMON_VERSION_VERSION_LSB      0
#define MPU_COMMON_VERSION_VERSION_WIDTH    ((uint32_t)0x00000020)

#define MPU_COMMON_VERSION_VERSION_RST      0x0

__INLINE uint32_t mpu_common_version_version_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_VERSION_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief ENABLE_AND_ERROR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    RX_WARN                   0              
 *    10    RX_ERR2                   0              
 *    08    TX_END_REQ                0              
 *    07    TX_CLEAR                  0              
 *    06    RX_CLEAR                  0              
 *    05    RX_ERR                    0              
 *    04    PHY_ERR                   0              
 *    02    RX_REQ_ACK_SW             0              
 *    01    RX_REQ_ACK_AUTO           0              
 *    00    ENABLE                    0              
 * </pre>
 */
#define MPU_COMMON_ENABLE_AND_ERROR_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000004)
#define MPU_COMMON_ENABLE_AND_ERROR_OFFSET      0x00000004
#define MPU_COMMON_ENABLE_AND_ERROR_INDEX       0x00000001
#define MPU_COMMON_ENABLE_AND_ERROR_RESET       0x00000000

__INLINE uint32_t  mpu_common_enable_and_error_get(void)
{
	return REG_PL_RD(MPU_COMMON_ENABLE_AND_ERROR_ADDR);
}

__INLINE void mpu_common_enable_and_error_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_ENABLE_AND_ERROR_ADDR, value);
}

// field definitions
#define MPU_COMMON_ENABLE_AND_ERROR_RX_WARN_BIT    ((uint32_t)0x00010000)
#define MPU_COMMON_ENABLE_AND_ERROR_RX_WARN_POS    16
#define MPU_COMMON_ENABLE_AND_ERROR_RX_ERR_2_BIT    ((uint32_t)0x00000400)
#define MPU_COMMON_ENABLE_AND_ERROR_RX_ERR_2_POS    10
#define MPU_COMMON_ENABLE_AND_ERROR_TX_END_REQ_BIT    ((uint32_t)0x00000100)
#define MPU_COMMON_ENABLE_AND_ERROR_TX_END_REQ_POS    8
#define MPU_COMMON_ENABLE_AND_ERROR_TX_CLEAR_BIT    ((uint32_t)0x00000080)
#define MPU_COMMON_ENABLE_AND_ERROR_TX_CLEAR_POS    7
#define MPU_COMMON_ENABLE_AND_ERROR_RX_CLEAR_BIT    ((uint32_t)0x00000040)
#define MPU_COMMON_ENABLE_AND_ERROR_RX_CLEAR_POS    6
#define MPU_COMMON_ENABLE_AND_ERROR_RX_ERR_BIT    ((uint32_t)0x00000020)
#define MPU_COMMON_ENABLE_AND_ERROR_RX_ERR_POS    5
#define MPU_COMMON_ENABLE_AND_ERROR_PHY_ERR_BIT    ((uint32_t)0x00000010)
#define MPU_COMMON_ENABLE_AND_ERROR_PHY_ERR_POS    4
#define MPU_COMMON_ENABLE_AND_ERROR_RX_REQ_ACK_SW_BIT    ((uint32_t)0x00000004)
#define MPU_COMMON_ENABLE_AND_ERROR_RX_REQ_ACK_SW_POS    2
#define MPU_COMMON_ENABLE_AND_ERROR_RX_REQ_ACK_AUTO_BIT    ((uint32_t)0x00000002)
#define MPU_COMMON_ENABLE_AND_ERROR_RX_REQ_ACK_AUTO_POS    1
#define MPU_COMMON_ENABLE_AND_ERROR_ENABLE_BIT    ((uint32_t)0x00000001)
#define MPU_COMMON_ENABLE_AND_ERROR_ENABLE_POS    0

#define MPU_COMMON_ENABLE_AND_ERROR_RX_WARN_RST    0x0
#define MPU_COMMON_ENABLE_AND_ERROR_RX_ERR_2_RST    0x0
#define MPU_COMMON_ENABLE_AND_ERROR_TX_END_REQ_RST    0x0
#define MPU_COMMON_ENABLE_AND_ERROR_TX_CLEAR_RST    0x0
#define MPU_COMMON_ENABLE_AND_ERROR_RX_CLEAR_RST    0x0
#define MPU_COMMON_ENABLE_AND_ERROR_RX_ERR_RST    0x0
#define MPU_COMMON_ENABLE_AND_ERROR_PHY_ERR_RST    0x0
#define MPU_COMMON_ENABLE_AND_ERROR_RX_REQ_ACK_SW_RST    0x0
#define MPU_COMMON_ENABLE_AND_ERROR_RX_REQ_ACK_AUTO_RST    0x0
#define MPU_COMMON_ENABLE_AND_ERROR_ENABLE_RST    0x0

__INLINE void mpu_common_enable_and_error_pack(uint8_t rx_warn, uint8_t rx_err2, uint8_t tx_end_req, uint8_t tx_clear, uint8_t rx_clear, uint8_t rx_err, uint8_t phy_err, uint8_t rx_req_ack_sw, uint8_t rx_req_ack_auto, uint8_t enable)
{
	ASSERT_ERR((((uint32_t)rx_warn << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)rx_err2 << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)tx_end_req << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)tx_clear << 7) & ~((uint32_t)0x00000080)) == 0);
	ASSERT_ERR((((uint32_t)rx_clear << 6) & ~((uint32_t)0x00000040)) == 0);
	ASSERT_ERR((((uint32_t)rx_err << 5) & ~((uint32_t)0x00000020)) == 0);
	ASSERT_ERR((((uint32_t)phy_err << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)rx_req_ack_sw << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)rx_req_ack_auto << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)enable << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MPU_COMMON_ENABLE_AND_ERROR_ADDR,  ((uint32_t)rx_warn << 16) |((uint32_t)rx_err2 << 10) |((uint32_t)tx_end_req << 8) |((uint32_t)tx_clear << 7) |((uint32_t)rx_clear << 6) |((uint32_t)rx_err << 5) |((uint32_t)phy_err << 4) |((uint32_t)rx_req_ack_sw << 2) |((uint32_t)rx_req_ack_auto << 1) |((uint32_t)enable << 0));
}

__INLINE void mpu_common_enable_and_error_unpack(uint8_t* rx_warn, uint8_t* rx_err2, uint8_t* tx_end_req, uint8_t* tx_clear, uint8_t* rx_clear, uint8_t* rx_err, uint8_t* phy_err, uint8_t* rx_req_ack_sw, uint8_t* rx_req_ack_auto, uint8_t* enable)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_ENABLE_AND_ERROR_ADDR);

	*rx_warn = (localVal & ((uint32_t)0x00010000)) >>  16;
	*rx_err2 = (localVal & ((uint32_t)0x00000400)) >>  10;
	*tx_end_req = (localVal & ((uint32_t)0x00000100)) >>  8;
	*tx_clear = (localVal & ((uint32_t)0x00000080)) >>  7;
	*rx_clear = (localVal & ((uint32_t)0x00000040)) >>  6;
	*rx_err = (localVal & ((uint32_t)0x00000020)) >>  5;
	*phy_err = (localVal & ((uint32_t)0x00000010)) >>  4;
	*rx_req_ack_sw = (localVal & ((uint32_t)0x00000004)) >>  2;
	*rx_req_ack_auto = (localVal & ((uint32_t)0x00000002)) >>  1;
	*enable = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE void mpu_common_enable_and_error_rx_warn_setf(uint8_t rxwarn)
{
	ASSERT_ERR((((uint32_t)rxwarn << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(MPU_COMMON_ENABLE_AND_ERROR_ADDR, (REG_PL_RD(MPU_COMMON_ENABLE_AND_ERROR_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)rxwarn <<16));
}
__INLINE void mpu_common_enable_and_error_rx_err_2_setf(uint8_t rxerr2)
{
	ASSERT_ERR((((uint32_t)rxerr2 << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(MPU_COMMON_ENABLE_AND_ERROR_ADDR, (REG_PL_RD(MPU_COMMON_ENABLE_AND_ERROR_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)rxerr2 <<10));
}
__INLINE void mpu_common_enable_and_error_tx_end_req_setf(uint8_t txendreq)
{
	ASSERT_ERR((((uint32_t)txendreq << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(MPU_COMMON_ENABLE_AND_ERROR_ADDR, (REG_PL_RD(MPU_COMMON_ENABLE_AND_ERROR_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)txendreq <<8));
}
__INLINE void mpu_common_enable_and_error_tx_clear_setf(uint8_t txclear)
{
	ASSERT_ERR((((uint32_t)txclear << 7) & ~((uint32_t)0x00000080)) == 0);
	REG_PL_WR(MPU_COMMON_ENABLE_AND_ERROR_ADDR, (REG_PL_RD(MPU_COMMON_ENABLE_AND_ERROR_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)txclear <<7));
}
__INLINE void mpu_common_enable_and_error_rx_clear_setf(uint8_t rxclear)
{
	ASSERT_ERR((((uint32_t)rxclear << 6) & ~((uint32_t)0x00000040)) == 0);
	REG_PL_WR(MPU_COMMON_ENABLE_AND_ERROR_ADDR, (REG_PL_RD(MPU_COMMON_ENABLE_AND_ERROR_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)rxclear <<6));
}
__INLINE void mpu_common_enable_and_error_rx_err_setf(uint8_t rxerr)
{
	ASSERT_ERR((((uint32_t)rxerr << 5) & ~((uint32_t)0x00000020)) == 0);
	REG_PL_WR(MPU_COMMON_ENABLE_AND_ERROR_ADDR, (REG_PL_RD(MPU_COMMON_ENABLE_AND_ERROR_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)rxerr <<5));
}
__INLINE void mpu_common_enable_and_error_phy_err_setf(uint8_t phyerr)
{
	ASSERT_ERR((((uint32_t)phyerr << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(MPU_COMMON_ENABLE_AND_ERROR_ADDR, (REG_PL_RD(MPU_COMMON_ENABLE_AND_ERROR_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)phyerr <<4));
}
__INLINE uint8_t mpu_common_enable_and_error_rx_req_ack_sw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_ENABLE_AND_ERROR_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void mpu_common_enable_and_error_rx_req_ack_sw_setf(uint8_t rxreqacksw)
{
	ASSERT_ERR((((uint32_t)rxreqacksw << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(MPU_COMMON_ENABLE_AND_ERROR_ADDR, (REG_PL_RD(MPU_COMMON_ENABLE_AND_ERROR_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)rxreqacksw <<2));
}
__INLINE uint8_t mpu_common_enable_and_error_rx_req_ack_auto_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_ENABLE_AND_ERROR_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void mpu_common_enable_and_error_rx_req_ack_auto_setf(uint8_t rxreqackauto)
{
	ASSERT_ERR((((uint32_t)rxreqackauto << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(MPU_COMMON_ENABLE_AND_ERROR_ADDR, (REG_PL_RD(MPU_COMMON_ENABLE_AND_ERROR_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)rxreqackauto <<1));
}
__INLINE uint8_t mpu_common_enable_and_error_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_ENABLE_AND_ERROR_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void mpu_common_enable_and_error_enable_setf(uint8_t enable)
{
	ASSERT_ERR((((uint32_t)enable << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MPU_COMMON_ENABLE_AND_ERROR_ADDR, (REG_PL_RD(MPU_COMMON_ENABLE_AND_ERROR_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)enable <<0));
}

/**
 * @brief FORMAT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    09:08 LEG_LENGTH_MOD3           0x0
 *    05    IMAGING_FRAME             0              
 *    04    PRE_TYPE                  0              
 *    03:00 FORMAT_MODE               0x0
 * </pre>
 */
#define MPU_COMMON_FORMAT_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000008)
#define MPU_COMMON_FORMAT_OFFSET      0x00000008
#define MPU_COMMON_FORMAT_INDEX       0x00000002
#define MPU_COMMON_FORMAT_RESET       0x00000000

__INLINE uint32_t  mpu_common_format_get(void)
{
	return REG_PL_RD(MPU_COMMON_FORMAT_ADDR);
}

__INLINE void mpu_common_format_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_FORMAT_ADDR, value);
}

// field definitions
#define MPU_COMMON_FORMAT_LEG_LENGTH_MOD_3_MASK    ((uint32_t)0x00000300)
#define MPU_COMMON_FORMAT_LEG_LENGTH_MOD_3_LSB    8
#define MPU_COMMON_FORMAT_LEG_LENGTH_MOD_3_WIDTH    ((uint32_t)0x00000002)
#define MPU_COMMON_FORMAT_IMAGING_FRAME_BIT    ((uint32_t)0x00000020)
#define MPU_COMMON_FORMAT_IMAGING_FRAME_POS    5
#define MPU_COMMON_FORMAT_PRE_TYPE_BIT      ((uint32_t)0x00000010)
#define MPU_COMMON_FORMAT_PRE_TYPE_POS      4
#define MPU_COMMON_FORMAT_FORMAT_MODE_MASK    ((uint32_t)0x0000000F)
#define MPU_COMMON_FORMAT_FORMAT_MODE_LSB    0
#define MPU_COMMON_FORMAT_FORMAT_MODE_WIDTH    ((uint32_t)0x00000004)

#define MPU_COMMON_FORMAT_LEG_LENGTH_MOD_3_RST    0x0
#define MPU_COMMON_FORMAT_IMAGING_FRAME_RST    0x0
#define MPU_COMMON_FORMAT_PRE_TYPE_RST      0x0
#define MPU_COMMON_FORMAT_FORMAT_MODE_RST    0x0

__INLINE void mpu_common_format_pack(uint8_t leg_length_mod3, uint8_t imaging_frame, uint8_t pre_type, uint8_t format_mode)
{
	ASSERT_ERR((((uint32_t)leg_length_mod3 << 8) & ~((uint32_t)0x00000300)) == 0);
	ASSERT_ERR((((uint32_t)imaging_frame << 5) & ~((uint32_t)0x00000020)) == 0);
	ASSERT_ERR((((uint32_t)pre_type << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)format_mode << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(MPU_COMMON_FORMAT_ADDR,  ((uint32_t)leg_length_mod3 << 8) |((uint32_t)imaging_frame << 5) |((uint32_t)pre_type << 4) |((uint32_t)format_mode << 0));
}

__INLINE void mpu_common_format_unpack(uint8_t* leg_length_mod3, uint8_t* imaging_frame, uint8_t* pre_type, uint8_t* format_mode)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_FORMAT_ADDR);

	*leg_length_mod3 = (localVal & ((uint32_t)0x00000300)) >>  8;
	*imaging_frame = (localVal & ((uint32_t)0x00000020)) >>  5;
	*pre_type = (localVal & ((uint32_t)0x00000010)) >>  4;
	*format_mode = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t mpu_common_format_leg_length_mod_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_FORMAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000300)) >> 8);
}
__INLINE void mpu_common_format_leg_length_mod_3_setf(uint8_t leglengthmod3)
{
	ASSERT_ERR((((uint32_t)leglengthmod3 << 8) & ~((uint32_t)0x00000300)) == 0);
	REG_PL_WR(MPU_COMMON_FORMAT_ADDR, (REG_PL_RD(MPU_COMMON_FORMAT_ADDR) & ~((uint32_t)0x00000300)) | ((uint32_t)leglengthmod3 <<8));
}
__INLINE uint8_t mpu_common_format_imaging_frame_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_FORMAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE void mpu_common_format_imaging_frame_setf(uint8_t imagingframe)
{
	ASSERT_ERR((((uint32_t)imagingframe << 5) & ~((uint32_t)0x00000020)) == 0);
	REG_PL_WR(MPU_COMMON_FORMAT_ADDR, (REG_PL_RD(MPU_COMMON_FORMAT_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)imagingframe <<5));
}
__INLINE uint8_t mpu_common_format_pre_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_FORMAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void mpu_common_format_pre_type_setf(uint8_t pretype)
{
	ASSERT_ERR((((uint32_t)pretype << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(MPU_COMMON_FORMAT_ADDR, (REG_PL_RD(MPU_COMMON_FORMAT_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)pretype <<4));
}
__INLINE uint8_t mpu_common_format_format_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_FORMAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void mpu_common_format_format_mode_setf(uint8_t formatmode)
{
	ASSERT_ERR((((uint32_t)formatmode << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(MPU_COMMON_FORMAT_ADDR, (REG_PL_RD(MPU_COMMON_FORMAT_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)formatmode <<0));
}

/**
 * @brief FIELD_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    03:00 FIELD_TYPE                0x0
 * </pre>
 */
#define MPU_COMMON_FIELD_CTRL_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x0000000C)
#define MPU_COMMON_FIELD_CTRL_OFFSET      0x0000000C
#define MPU_COMMON_FIELD_CTRL_INDEX       0x00000003
#define MPU_COMMON_FIELD_CTRL_RESET       0x00000000

__INLINE uint32_t  mpu_common_field_ctrl_get(void)
{
	return REG_PL_RD(MPU_COMMON_FIELD_CTRL_ADDR);
}

__INLINE void mpu_common_field_ctrl_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_FIELD_CTRL_ADDR, value);
}

// field definitions
#define MPU_COMMON_FIELD_CTRL_FIELD_TYPE_MASK    ((uint32_t)0x0000000F)
#define MPU_COMMON_FIELD_CTRL_FIELD_TYPE_LSB    0
#define MPU_COMMON_FIELD_CTRL_FIELD_TYPE_WIDTH    ((uint32_t)0x00000004)

#define MPU_COMMON_FIELD_CTRL_FIELD_TYPE_RST    0x0

__INLINE uint8_t mpu_common_field_ctrl_field_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_FIELD_CTRL_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void mpu_common_field_ctrl_field_type_setf(uint8_t fieldtype)
{
	ASSERT_ERR((((uint32_t)fieldtype << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(MPU_COMMON_FIELD_CTRL_ADDR, (uint32_t)fieldtype << 0);
}

/**
 * @brief LEGACY_INFO register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:24 LEG_RATE                  0x0
 *    11:00 LEG_LENGTH                0x0
 * </pre>
 */
#define MPU_COMMON_LEGACY_INFO_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000010)
#define MPU_COMMON_LEGACY_INFO_OFFSET      0x00000010
#define MPU_COMMON_LEGACY_INFO_INDEX       0x00000004
#define MPU_COMMON_LEGACY_INFO_RESET       0x00000000

__INLINE uint32_t  mpu_common_legacy_info_get(void)
{
	return REG_PL_RD(MPU_COMMON_LEGACY_INFO_ADDR);
}

__INLINE void mpu_common_legacy_info_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_LEGACY_INFO_ADDR, value);
}

// field definitions
#define MPU_COMMON_LEGACY_INFO_LEG_RATE_MASK    ((uint32_t)0x0F000000)
#define MPU_COMMON_LEGACY_INFO_LEG_RATE_LSB    24
#define MPU_COMMON_LEGACY_INFO_LEG_RATE_WIDTH    ((uint32_t)0x00000004)
#define MPU_COMMON_LEGACY_INFO_LEG_LENGTH_MASK    ((uint32_t)0x00000FFF)
#define MPU_COMMON_LEGACY_INFO_LEG_LENGTH_LSB    0
#define MPU_COMMON_LEGACY_INFO_LEG_LENGTH_WIDTH    ((uint32_t)0x0000000C)

#define MPU_COMMON_LEGACY_INFO_LEG_RATE_RST    0x0
#define MPU_COMMON_LEGACY_INFO_LEG_LENGTH_RST    0x0

__INLINE void mpu_common_legacy_info_pack(uint8_t leg_rate, uint16_t leg_length)
{
	ASSERT_ERR((((uint32_t)leg_rate << 24) & ~((uint32_t)0x0F000000)) == 0);
	ASSERT_ERR((((uint32_t)leg_length << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(MPU_COMMON_LEGACY_INFO_ADDR,  ((uint32_t)leg_rate << 24) |((uint32_t)leg_length << 0));
}

__INLINE void mpu_common_legacy_info_unpack(uint8_t* leg_rate, uint16_t* leg_length)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_LEGACY_INFO_ADDR);

	*leg_rate = (localVal & ((uint32_t)0x0F000000)) >>  24;
	*leg_length = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint8_t mpu_common_legacy_info_leg_rate_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_LEGACY_INFO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0F000000)) >> 24);
}
__INLINE void mpu_common_legacy_info_leg_rate_setf(uint8_t legrate)
{
	ASSERT_ERR((((uint32_t)legrate << 24) & ~((uint32_t)0x0F000000)) == 0);
	REG_PL_WR(MPU_COMMON_LEGACY_INFO_ADDR, (REG_PL_RD(MPU_COMMON_LEGACY_INFO_ADDR) & ~((uint32_t)0x0F000000)) | ((uint32_t)legrate <<24));
}
__INLINE uint16_t mpu_common_legacy_info_leg_length_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_LEGACY_INFO_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}
__INLINE void mpu_common_legacy_info_leg_length_setf(uint16_t leglength)
{
	ASSERT_ERR((((uint32_t)leglength << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(MPU_COMMON_LEGACY_INFO_ADDR, (REG_PL_RD(MPU_COMMON_LEGACY_INFO_ADDR) & ~((uint32_t)0x00000FFF)) | ((uint32_t)leglength <<0));
}

/**
 * @brief COMMON_CFG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 ACTIVE_TX_CHAINS          0x0
 *    19:16 NUM_TX_CHAINS             0x0
 *    15:08 ACTIVE_RX_CHAINS          0x0
 *    03:00 NUM_RX_CHAINS             0x0
 * </pre>
 */
#define MPU_COMMON_COMMON_CFG_1_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000014)
#define MPU_COMMON_COMMON_CFG_1_OFFSET      0x00000014
#define MPU_COMMON_COMMON_CFG_1_INDEX       0x00000005
#define MPU_COMMON_COMMON_CFG_1_RESET       0x00000000

__INLINE uint32_t  mpu_common_common_cfg_1_get(void)
{
	return REG_PL_RD(MPU_COMMON_COMMON_CFG_1_ADDR);
}

__INLINE void mpu_common_common_cfg_1_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_COMMON_CFG_1_ADDR, value);
}

// field definitions
#define MPU_COMMON_COMMON_CFG_1_ACTIVE_TX_CHAINS_MASK    ((uint32_t)0xFF000000)
#define MPU_COMMON_COMMON_CFG_1_ACTIVE_TX_CHAINS_LSB    24
#define MPU_COMMON_COMMON_CFG_1_ACTIVE_TX_CHAINS_WIDTH    ((uint32_t)0x00000008)
#define MPU_COMMON_COMMON_CFG_1_NUM_TX_CHAINS_MASK    ((uint32_t)0x000F0000)
#define MPU_COMMON_COMMON_CFG_1_NUM_TX_CHAINS_LSB    16
#define MPU_COMMON_COMMON_CFG_1_NUM_TX_CHAINS_WIDTH    ((uint32_t)0x00000004)
#define MPU_COMMON_COMMON_CFG_1_ACTIVE_RX_CHAINS_MASK    ((uint32_t)0x0000FF00)
#define MPU_COMMON_COMMON_CFG_1_ACTIVE_RX_CHAINS_LSB    8
#define MPU_COMMON_COMMON_CFG_1_ACTIVE_RX_CHAINS_WIDTH    ((uint32_t)0x00000008)
#define MPU_COMMON_COMMON_CFG_1_NUM_RX_CHAINS_MASK    ((uint32_t)0x0000000F)
#define MPU_COMMON_COMMON_CFG_1_NUM_RX_CHAINS_LSB    0
#define MPU_COMMON_COMMON_CFG_1_NUM_RX_CHAINS_WIDTH    ((uint32_t)0x00000004)

#define MPU_COMMON_COMMON_CFG_1_ACTIVE_TX_CHAINS_RST    0x0
#define MPU_COMMON_COMMON_CFG_1_NUM_TX_CHAINS_RST    0x0
#define MPU_COMMON_COMMON_CFG_1_ACTIVE_RX_CHAINS_RST    0x0
#define MPU_COMMON_COMMON_CFG_1_NUM_RX_CHAINS_RST    0x0

__INLINE void mpu_common_common_cfg_1_pack(uint8_t active_tx_chains, uint8_t num_tx_chains, uint8_t active_rx_chains, uint8_t num_rx_chains)
{
	ASSERT_ERR((((uint32_t)active_tx_chains << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)num_tx_chains << 16) & ~((uint32_t)0x000F0000)) == 0);
	ASSERT_ERR((((uint32_t)active_rx_chains << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)num_rx_chains << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(MPU_COMMON_COMMON_CFG_1_ADDR,  ((uint32_t)active_tx_chains << 24) |((uint32_t)num_tx_chains << 16) |((uint32_t)active_rx_chains << 8) |((uint32_t)num_rx_chains << 0));
}

__INLINE void mpu_common_common_cfg_1_unpack(uint8_t* active_tx_chains, uint8_t* num_tx_chains, uint8_t* active_rx_chains, uint8_t* num_rx_chains)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_COMMON_CFG_1_ADDR);

	*active_tx_chains = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*num_tx_chains = (localVal & ((uint32_t)0x000F0000)) >>  16;
	*active_rx_chains = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*num_rx_chains = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t mpu_common_common_cfg_1_active_tx_chains_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_COMMON_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void mpu_common_common_cfg_1_active_tx_chains_setf(uint8_t activetxchains)
{
	ASSERT_ERR((((uint32_t)activetxchains << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(MPU_COMMON_COMMON_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_COMMON_CFG_1_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)activetxchains <<24));
}
__INLINE uint8_t mpu_common_common_cfg_1_num_tx_chains_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_COMMON_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000F0000)) >> 16);
}
__INLINE void mpu_common_common_cfg_1_num_tx_chains_setf(uint8_t numtxchains)
{
	ASSERT_ERR((((uint32_t)numtxchains << 16) & ~((uint32_t)0x000F0000)) == 0);
	REG_PL_WR(MPU_COMMON_COMMON_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_COMMON_CFG_1_ADDR) & ~((uint32_t)0x000F0000)) | ((uint32_t)numtxchains <<16));
}
__INLINE uint8_t mpu_common_common_cfg_1_active_rx_chains_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_COMMON_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void mpu_common_common_cfg_1_active_rx_chains_setf(uint8_t activerxchains)
{
	ASSERT_ERR((((uint32_t)activerxchains << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(MPU_COMMON_COMMON_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_COMMON_CFG_1_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)activerxchains <<8));
}
__INLINE uint8_t mpu_common_common_cfg_1_num_rx_chains_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_COMMON_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void mpu_common_common_cfg_1_num_rx_chains_setf(uint8_t numrxchains)
{
	ASSERT_ERR((((uint32_t)numrxchains << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(MPU_COMMON_COMMON_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_COMMON_CFG_1_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)numrxchains <<0));
}

/**
 * @brief COMMON_CFG_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    TRIGGER_RESPONDING        0              
 *    30:28 PA_DETECT                 0x0
 *    25:24 NUM_EXTN_SS               0x0
 *    23    LONG_RESPONSE_TIMEOUT     0              
 *    22    EXPECTED_RESPONSE         0              
 *    21    NO_SIG_EXTN               0              
 *    20    DOZE_NOT_ALLOWED          0              
 *    19    AGGREGATION               0              
 *    18    SMOOTHING                 0              
 *    17    SOUNDING                  0              
 *    16    LDPC_EXTRA                0              
 *    15:14 DYN_BW_CH_BW              0x0
 *    13    DYN_BW                    0              
 *    12    DISAMBIGUITY_BIT          0              
 *    11:10 FTM                       0x0
 *    09:08 GI_TYPE                   0x0
 *    07    DO_IMPLICIT_LEARNING      0              
 *    06    AUTO_RESPONSE             0              
 *    05:04 STBC                      0x0
 *    02:00 FRAME_BW                  0x0
 * </pre>
 */
#define MPU_COMMON_COMMON_CFG_2_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000018)
#define MPU_COMMON_COMMON_CFG_2_OFFSET      0x00000018
#define MPU_COMMON_COMMON_CFG_2_INDEX       0x00000006
#define MPU_COMMON_COMMON_CFG_2_RESET       0x00000000

__INLINE uint32_t  mpu_common_common_cfg_2_get(void)
{
	return REG_PL_RD(MPU_COMMON_COMMON_CFG_2_ADDR);
}

__INLINE void mpu_common_common_cfg_2_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_COMMON_CFG_2_ADDR, value);
}

// field definitions
#define MPU_COMMON_COMMON_CFG_2_TRIGGER_RESPONDING_BIT    ((uint32_t)0x80000000)
#define MPU_COMMON_COMMON_CFG_2_TRIGGER_RESPONDING_POS    31
#define MPU_COMMON_COMMON_CFG_2_PA_DETECT_MASK    ((uint32_t)0x70000000)
#define MPU_COMMON_COMMON_CFG_2_PA_DETECT_LSB    28
#define MPU_COMMON_COMMON_CFG_2_PA_DETECT_WIDTH    ((uint32_t)0x00000003)
#define MPU_COMMON_COMMON_CFG_2_NUM_EXTN_SS_MASK    ((uint32_t)0x03000000)
#define MPU_COMMON_COMMON_CFG_2_NUM_EXTN_SS_LSB    24
#define MPU_COMMON_COMMON_CFG_2_NUM_EXTN_SS_WIDTH    ((uint32_t)0x00000002)
#define MPU_COMMON_COMMON_CFG_2_LONG_RESPONSE_TIMEOUT_BIT    ((uint32_t)0x00800000)
#define MPU_COMMON_COMMON_CFG_2_LONG_RESPONSE_TIMEOUT_POS    23
#define MPU_COMMON_COMMON_CFG_2_EXPECTED_RESPONSE_BIT    ((uint32_t)0x00400000)
#define MPU_COMMON_COMMON_CFG_2_EXPECTED_RESPONSE_POS    22
#define MPU_COMMON_COMMON_CFG_2_NO_SIG_EXTN_BIT    ((uint32_t)0x00200000)
#define MPU_COMMON_COMMON_CFG_2_NO_SIG_EXTN_POS    21
#define MPU_COMMON_COMMON_CFG_2_DOZE_NOT_ALLOWED_BIT    ((uint32_t)0x00100000)
#define MPU_COMMON_COMMON_CFG_2_DOZE_NOT_ALLOWED_POS    20
#define MPU_COMMON_COMMON_CFG_2_AGGREGATION_BIT    ((uint32_t)0x00080000)
#define MPU_COMMON_COMMON_CFG_2_AGGREGATION_POS    19
#define MPU_COMMON_COMMON_CFG_2_SMOOTHING_BIT    ((uint32_t)0x00040000)
#define MPU_COMMON_COMMON_CFG_2_SMOOTHING_POS    18
#define MPU_COMMON_COMMON_CFG_2_SOUNDING_BIT    ((uint32_t)0x00020000)
#define MPU_COMMON_COMMON_CFG_2_SOUNDING_POS    17
#define MPU_COMMON_COMMON_CFG_2_LDPC_EXTRA_BIT    ((uint32_t)0x00010000)
#define MPU_COMMON_COMMON_CFG_2_LDPC_EXTRA_POS    16
#define MPU_COMMON_COMMON_CFG_2_DYN_BW_CH_BW_MASK    ((uint32_t)0x0000C000)
#define MPU_COMMON_COMMON_CFG_2_DYN_BW_CH_BW_LSB    14
#define MPU_COMMON_COMMON_CFG_2_DYN_BW_CH_BW_WIDTH    ((uint32_t)0x00000002)
#define MPU_COMMON_COMMON_CFG_2_DYN_BW_BIT    ((uint32_t)0x00002000)
#define MPU_COMMON_COMMON_CFG_2_DYN_BW_POS    13
#define MPU_COMMON_COMMON_CFG_2_DISAMBIGUITY_BIT_BIT    ((uint32_t)0x00001000)
#define MPU_COMMON_COMMON_CFG_2_DISAMBIGUITY_BIT_POS    12
#define MPU_COMMON_COMMON_CFG_2_FTM_MASK    ((uint32_t)0x00000C00)
#define MPU_COMMON_COMMON_CFG_2_FTM_LSB     10
#define MPU_COMMON_COMMON_CFG_2_FTM_WIDTH    ((uint32_t)0x00000002)
#define MPU_COMMON_COMMON_CFG_2_GI_TYPE_MASK    ((uint32_t)0x00000300)
#define MPU_COMMON_COMMON_CFG_2_GI_TYPE_LSB    8
#define MPU_COMMON_COMMON_CFG_2_GI_TYPE_WIDTH    ((uint32_t)0x00000002)
#define MPU_COMMON_COMMON_CFG_2_DO_IMPLICIT_LEARNING_BIT    ((uint32_t)0x00000080)
#define MPU_COMMON_COMMON_CFG_2_DO_IMPLICIT_LEARNING_POS    7
#define MPU_COMMON_COMMON_CFG_2_AUTO_RESPONSE_BIT    ((uint32_t)0x00000040)
#define MPU_COMMON_COMMON_CFG_2_AUTO_RESPONSE_POS    6
#define MPU_COMMON_COMMON_CFG_2_STBC_MASK    ((uint32_t)0x00000030)
#define MPU_COMMON_COMMON_CFG_2_STBC_LSB    4
#define MPU_COMMON_COMMON_CFG_2_STBC_WIDTH    ((uint32_t)0x00000002)
#define MPU_COMMON_COMMON_CFG_2_FRAME_BW_MASK    ((uint32_t)0x00000007)
#define MPU_COMMON_COMMON_CFG_2_FRAME_BW_LSB    0
#define MPU_COMMON_COMMON_CFG_2_FRAME_BW_WIDTH    ((uint32_t)0x00000003)

#define MPU_COMMON_COMMON_CFG_2_TRIGGER_RESPONDING_RST    0x0
#define MPU_COMMON_COMMON_CFG_2_PA_DETECT_RST    0x0
#define MPU_COMMON_COMMON_CFG_2_NUM_EXTN_SS_RST    0x0
#define MPU_COMMON_COMMON_CFG_2_LONG_RESPONSE_TIMEOUT_RST    0x0
#define MPU_COMMON_COMMON_CFG_2_EXPECTED_RESPONSE_RST    0x0
#define MPU_COMMON_COMMON_CFG_2_NO_SIG_EXTN_RST    0x0
#define MPU_COMMON_COMMON_CFG_2_DOZE_NOT_ALLOWED_RST    0x0
#define MPU_COMMON_COMMON_CFG_2_AGGREGATION_RST    0x0
#define MPU_COMMON_COMMON_CFG_2_SMOOTHING_RST    0x0
#define MPU_COMMON_COMMON_CFG_2_SOUNDING_RST    0x0
#define MPU_COMMON_COMMON_CFG_2_LDPC_EXTRA_RST    0x0
#define MPU_COMMON_COMMON_CFG_2_DYN_BW_CH_BW_RST    0x0
#define MPU_COMMON_COMMON_CFG_2_DYN_BW_RST    0x0
#define MPU_COMMON_COMMON_CFG_2_DISAMBIGUITY_BIT_RST    0x0
#define MPU_COMMON_COMMON_CFG_2_FTM_RST     0x0
#define MPU_COMMON_COMMON_CFG_2_GI_TYPE_RST    0x0
#define MPU_COMMON_COMMON_CFG_2_DO_IMPLICIT_LEARNING_RST    0x0
#define MPU_COMMON_COMMON_CFG_2_AUTO_RESPONSE_RST    0x0
#define MPU_COMMON_COMMON_CFG_2_STBC_RST    0x0
#define MPU_COMMON_COMMON_CFG_2_FRAME_BW_RST    0x0

__INLINE void mpu_common_common_cfg_2_pack(uint8_t trigger_responding, uint8_t pa_detect, uint8_t num_extn_ss, uint8_t long_response_timeout, uint8_t expected_response, uint8_t no_sig_extn, uint8_t doze_not_allowed, uint8_t aggregation, uint8_t smoothing, uint8_t sounding, uint8_t ldpc_extra, uint8_t dyn_bw_ch_bw, uint8_t dyn_bw, uint8_t disambiguity_bit, uint8_t ftm, uint8_t gi_type, uint8_t do_implicit_learning, uint8_t auto_response, uint8_t stbc, uint8_t frame_bw)
{
	ASSERT_ERR((((uint32_t)trigger_responding << 31) & ~((uint32_t)0x80000000)) == 0);
	ASSERT_ERR((((uint32_t)pa_detect << 28) & ~((uint32_t)0x70000000)) == 0);
	ASSERT_ERR((((uint32_t)num_extn_ss << 24) & ~((uint32_t)0x03000000)) == 0);
	ASSERT_ERR((((uint32_t)long_response_timeout << 23) & ~((uint32_t)0x00800000)) == 0);
	ASSERT_ERR((((uint32_t)expected_response << 22) & ~((uint32_t)0x00400000)) == 0);
	ASSERT_ERR((((uint32_t)no_sig_extn << 21) & ~((uint32_t)0x00200000)) == 0);
	ASSERT_ERR((((uint32_t)doze_not_allowed << 20) & ~((uint32_t)0x00100000)) == 0);
	ASSERT_ERR((((uint32_t)aggregation << 19) & ~((uint32_t)0x00080000)) == 0);
	ASSERT_ERR((((uint32_t)smoothing << 18) & ~((uint32_t)0x00040000)) == 0);
	ASSERT_ERR((((uint32_t)sounding << 17) & ~((uint32_t)0x00020000)) == 0);
	ASSERT_ERR((((uint32_t)ldpc_extra << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)dyn_bw_ch_bw << 14) & ~((uint32_t)0x0000C000)) == 0);
	ASSERT_ERR((((uint32_t)dyn_bw << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)disambiguity_bit << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)ftm << 10) & ~((uint32_t)0x00000C00)) == 0);
	ASSERT_ERR((((uint32_t)gi_type << 8) & ~((uint32_t)0x00000300)) == 0);
	ASSERT_ERR((((uint32_t)do_implicit_learning << 7) & ~((uint32_t)0x00000080)) == 0);
	ASSERT_ERR((((uint32_t)auto_response << 6) & ~((uint32_t)0x00000040)) == 0);
	ASSERT_ERR((((uint32_t)stbc << 4) & ~((uint32_t)0x00000030)) == 0);
	ASSERT_ERR((((uint32_t)frame_bw << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(MPU_COMMON_COMMON_CFG_2_ADDR,  ((uint32_t)trigger_responding << 31) |((uint32_t)pa_detect << 28) |((uint32_t)num_extn_ss << 24) |((uint32_t)long_response_timeout << 23) |((uint32_t)expected_response << 22) |((uint32_t)no_sig_extn << 21) |((uint32_t)doze_not_allowed << 20) |((uint32_t)aggregation << 19) |((uint32_t)smoothing << 18) |((uint32_t)sounding << 17) |((uint32_t)ldpc_extra << 16) |((uint32_t)dyn_bw_ch_bw << 14) |((uint32_t)dyn_bw << 13) |((uint32_t)disambiguity_bit << 12) |((uint32_t)ftm << 10) |((uint32_t)gi_type << 8) |((uint32_t)do_implicit_learning << 7) |((uint32_t)auto_response << 6) |((uint32_t)stbc << 4) |((uint32_t)frame_bw << 0));
}

__INLINE void mpu_common_common_cfg_2_unpack(uint8_t* trigger_responding, uint8_t* pa_detect, uint8_t* num_extn_ss, uint8_t* long_response_timeout, uint8_t* expected_response, uint8_t* no_sig_extn, uint8_t* doze_not_allowed, uint8_t* aggregation, uint8_t* smoothing, uint8_t* sounding, uint8_t* ldpc_extra, uint8_t* dyn_bw_ch_bw, uint8_t* dyn_bw, uint8_t* disambiguity_bit, uint8_t* ftm, uint8_t* gi_type, uint8_t* do_implicit_learning, uint8_t* auto_response, uint8_t* stbc, uint8_t* frame_bw)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_COMMON_CFG_2_ADDR);

	*trigger_responding = (localVal & ((uint32_t)0x80000000)) >>  31;
	*pa_detect = (localVal & ((uint32_t)0x70000000)) >>  28;
	*num_extn_ss = (localVal & ((uint32_t)0x03000000)) >>  24;
	*long_response_timeout = (localVal & ((uint32_t)0x00800000)) >>  23;
	*expected_response = (localVal & ((uint32_t)0x00400000)) >>  22;
	*no_sig_extn = (localVal & ((uint32_t)0x00200000)) >>  21;
	*doze_not_allowed = (localVal & ((uint32_t)0x00100000)) >>  20;
	*aggregation = (localVal & ((uint32_t)0x00080000)) >>  19;
	*smoothing = (localVal & ((uint32_t)0x00040000)) >>  18;
	*sounding = (localVal & ((uint32_t)0x00020000)) >>  17;
	*ldpc_extra = (localVal & ((uint32_t)0x00010000)) >>  16;
	*dyn_bw_ch_bw = (localVal & ((uint32_t)0x0000C000)) >>  14;
	*dyn_bw = (localVal & ((uint32_t)0x00002000)) >>  13;
	*disambiguity_bit = (localVal & ((uint32_t)0x00001000)) >>  12;
	*ftm = (localVal & ((uint32_t)0x00000C00)) >>  10;
	*gi_type = (localVal & ((uint32_t)0x00000300)) >>  8;
	*do_implicit_learning = (localVal & ((uint32_t)0x00000080)) >>  7;
	*auto_response = (localVal & ((uint32_t)0x00000040)) >>  6;
	*stbc = (localVal & ((uint32_t)0x00000030)) >>  4;
	*frame_bw = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t mpu_common_common_cfg_2_trigger_responding_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_COMMON_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE void mpu_common_common_cfg_2_trigger_responding_setf(uint8_t triggerresponding)
{
	ASSERT_ERR((((uint32_t)triggerresponding << 31) & ~((uint32_t)0x80000000)) == 0);
	REG_PL_WR(MPU_COMMON_COMMON_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_COMMON_CFG_2_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)triggerresponding <<31));
}
__INLINE uint8_t mpu_common_common_cfg_2_pa_detect_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_COMMON_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x70000000)) >> 28);
}
__INLINE void mpu_common_common_cfg_2_pa_detect_setf(uint8_t padetect)
{
	ASSERT_ERR((((uint32_t)padetect << 28) & ~((uint32_t)0x70000000)) == 0);
	REG_PL_WR(MPU_COMMON_COMMON_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_COMMON_CFG_2_ADDR) & ~((uint32_t)0x70000000)) | ((uint32_t)padetect <<28));
}
__INLINE uint8_t mpu_common_common_cfg_2_num_extn_ss_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_COMMON_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x03000000)) >> 24);
}
__INLINE void mpu_common_common_cfg_2_num_extn_ss_setf(uint8_t numextnss)
{
	ASSERT_ERR((((uint32_t)numextnss << 24) & ~((uint32_t)0x03000000)) == 0);
	REG_PL_WR(MPU_COMMON_COMMON_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_COMMON_CFG_2_ADDR) & ~((uint32_t)0x03000000)) | ((uint32_t)numextnss <<24));
}
__INLINE uint8_t mpu_common_common_cfg_2_long_response_timeout_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_COMMON_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00800000)) >> 23);
}
__INLINE void mpu_common_common_cfg_2_long_response_timeout_setf(uint8_t longresponsetimeout)
{
	ASSERT_ERR((((uint32_t)longresponsetimeout << 23) & ~((uint32_t)0x00800000)) == 0);
	REG_PL_WR(MPU_COMMON_COMMON_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_COMMON_CFG_2_ADDR) & ~((uint32_t)0x00800000)) | ((uint32_t)longresponsetimeout <<23));
}
__INLINE uint8_t mpu_common_common_cfg_2_expected_response_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_COMMON_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00400000)) >> 22);
}
__INLINE void mpu_common_common_cfg_2_expected_response_setf(uint8_t expectedresponse)
{
	ASSERT_ERR((((uint32_t)expectedresponse << 22) & ~((uint32_t)0x00400000)) == 0);
	REG_PL_WR(MPU_COMMON_COMMON_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_COMMON_CFG_2_ADDR) & ~((uint32_t)0x00400000)) | ((uint32_t)expectedresponse <<22));
}
__INLINE uint8_t mpu_common_common_cfg_2_no_sig_extn_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_COMMON_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00200000)) >> 21);
}
__INLINE void mpu_common_common_cfg_2_no_sig_extn_setf(uint8_t nosigextn)
{
	ASSERT_ERR((((uint32_t)nosigextn << 21) & ~((uint32_t)0x00200000)) == 0);
	REG_PL_WR(MPU_COMMON_COMMON_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_COMMON_CFG_2_ADDR) & ~((uint32_t)0x00200000)) | ((uint32_t)nosigextn <<21));
}
__INLINE uint8_t mpu_common_common_cfg_2_doze_not_allowed_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_COMMON_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00100000)) >> 20);
}
__INLINE void mpu_common_common_cfg_2_doze_not_allowed_setf(uint8_t dozenotallowed)
{
	ASSERT_ERR((((uint32_t)dozenotallowed << 20) & ~((uint32_t)0x00100000)) == 0);
	REG_PL_WR(MPU_COMMON_COMMON_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_COMMON_CFG_2_ADDR) & ~((uint32_t)0x00100000)) | ((uint32_t)dozenotallowed <<20));
}
__INLINE uint8_t mpu_common_common_cfg_2_aggregation_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_COMMON_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00080000)) >> 19);
}
__INLINE void mpu_common_common_cfg_2_aggregation_setf(uint8_t aggregation)
{
	ASSERT_ERR((((uint32_t)aggregation << 19) & ~((uint32_t)0x00080000)) == 0);
	REG_PL_WR(MPU_COMMON_COMMON_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_COMMON_CFG_2_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)aggregation <<19));
}
__INLINE uint8_t mpu_common_common_cfg_2_smoothing_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_COMMON_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00040000)) >> 18);
}
__INLINE void mpu_common_common_cfg_2_smoothing_setf(uint8_t smoothing)
{
	ASSERT_ERR((((uint32_t)smoothing << 18) & ~((uint32_t)0x00040000)) == 0);
	REG_PL_WR(MPU_COMMON_COMMON_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_COMMON_CFG_2_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)smoothing <<18));
}
__INLINE uint8_t mpu_common_common_cfg_2_sounding_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_COMMON_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00020000)) >> 17);
}
__INLINE void mpu_common_common_cfg_2_sounding_setf(uint8_t sounding)
{
	ASSERT_ERR((((uint32_t)sounding << 17) & ~((uint32_t)0x00020000)) == 0);
	REG_PL_WR(MPU_COMMON_COMMON_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_COMMON_CFG_2_ADDR) & ~((uint32_t)0x00020000)) | ((uint32_t)sounding <<17));
}
__INLINE uint8_t mpu_common_common_cfg_2_ldpc_extra_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_COMMON_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void mpu_common_common_cfg_2_ldpc_extra_setf(uint8_t ldpcextra)
{
	ASSERT_ERR((((uint32_t)ldpcextra << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(MPU_COMMON_COMMON_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_COMMON_CFG_2_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)ldpcextra <<16));
}
__INLINE uint8_t mpu_common_common_cfg_2_dyn_bw_ch_bw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_COMMON_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000C000)) >> 14);
}
__INLINE void mpu_common_common_cfg_2_dyn_bw_ch_bw_setf(uint8_t dynbwchbw)
{
	ASSERT_ERR((((uint32_t)dynbwchbw << 14) & ~((uint32_t)0x0000C000)) == 0);
	REG_PL_WR(MPU_COMMON_COMMON_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_COMMON_CFG_2_ADDR) & ~((uint32_t)0x0000C000)) | ((uint32_t)dynbwchbw <<14));
}
__INLINE uint8_t mpu_common_common_cfg_2_dyn_bw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_COMMON_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void mpu_common_common_cfg_2_dyn_bw_setf(uint8_t dynbw)
{
	ASSERT_ERR((((uint32_t)dynbw << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(MPU_COMMON_COMMON_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_COMMON_CFG_2_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)dynbw <<13));
}
__INLINE uint8_t mpu_common_common_cfg_2_disambiguity_bit_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_COMMON_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void mpu_common_common_cfg_2_disambiguity_bit_setf(uint8_t disambiguitybit)
{
	ASSERT_ERR((((uint32_t)disambiguitybit << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(MPU_COMMON_COMMON_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_COMMON_CFG_2_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)disambiguitybit <<12));
}
__INLINE uint8_t mpu_common_common_cfg_2_ftm_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_COMMON_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000C00)) >> 10);
}
__INLINE void mpu_common_common_cfg_2_ftm_setf(uint8_t ftm)
{
	ASSERT_ERR((((uint32_t)ftm << 10) & ~((uint32_t)0x00000C00)) == 0);
	REG_PL_WR(MPU_COMMON_COMMON_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_COMMON_CFG_2_ADDR) & ~((uint32_t)0x00000C00)) | ((uint32_t)ftm <<10));
}
__INLINE uint8_t mpu_common_common_cfg_2_gi_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_COMMON_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000300)) >> 8);
}
__INLINE void mpu_common_common_cfg_2_gi_type_setf(uint8_t gitype)
{
	ASSERT_ERR((((uint32_t)gitype << 8) & ~((uint32_t)0x00000300)) == 0);
	REG_PL_WR(MPU_COMMON_COMMON_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_COMMON_CFG_2_ADDR) & ~((uint32_t)0x00000300)) | ((uint32_t)gitype <<8));
}
__INLINE uint8_t mpu_common_common_cfg_2_do_implicit_learning_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_COMMON_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE void mpu_common_common_cfg_2_do_implicit_learning_setf(uint8_t doimplicitlearning)
{
	ASSERT_ERR((((uint32_t)doimplicitlearning << 7) & ~((uint32_t)0x00000080)) == 0);
	REG_PL_WR(MPU_COMMON_COMMON_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_COMMON_CFG_2_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)doimplicitlearning <<7));
}
__INLINE uint8_t mpu_common_common_cfg_2_auto_response_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_COMMON_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE void mpu_common_common_cfg_2_auto_response_setf(uint8_t autoresponse)
{
	ASSERT_ERR((((uint32_t)autoresponse << 6) & ~((uint32_t)0x00000040)) == 0);
	REG_PL_WR(MPU_COMMON_COMMON_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_COMMON_CFG_2_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)autoresponse <<6));
}
__INLINE uint8_t mpu_common_common_cfg_2_stbc_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_COMMON_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000030)) >> 4);
}
__INLINE void mpu_common_common_cfg_2_stbc_setf(uint8_t stbc)
{
	ASSERT_ERR((((uint32_t)stbc << 4) & ~((uint32_t)0x00000030)) == 0);
	REG_PL_WR(MPU_COMMON_COMMON_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_COMMON_CFG_2_ADDR) & ~((uint32_t)0x00000030)) | ((uint32_t)stbc <<4));
}
__INLINE uint8_t mpu_common_common_cfg_2_frame_bw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_COMMON_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void mpu_common_common_cfg_2_frame_bw_setf(uint8_t framebw)
{
	ASSERT_ERR((((uint32_t)framebw << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(MPU_COMMON_COMMON_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_COMMON_CFG_2_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)framebw <<0));
}

/**
 * @brief COMMON_CFG_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26:24 TOTAL_NSTS                0x0
 *    23:16 CFRA                      0x0
 *    15:00 ANTENNA_SET               0x0
 * </pre>
 */
#define MPU_COMMON_COMMON_CFG_3_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x0000001C)
#define MPU_COMMON_COMMON_CFG_3_OFFSET      0x0000001C
#define MPU_COMMON_COMMON_CFG_3_INDEX       0x00000007
#define MPU_COMMON_COMMON_CFG_3_RESET       0x00000000

__INLINE uint32_t  mpu_common_common_cfg_3_get(void)
{
	return REG_PL_RD(MPU_COMMON_COMMON_CFG_3_ADDR);
}

__INLINE void mpu_common_common_cfg_3_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_COMMON_CFG_3_ADDR, value);
}

// field definitions
#define MPU_COMMON_COMMON_CFG_3_TOTAL_NSTS_MASK    ((uint32_t)0x07000000)
#define MPU_COMMON_COMMON_CFG_3_TOTAL_NSTS_LSB    24
#define MPU_COMMON_COMMON_CFG_3_TOTAL_NSTS_WIDTH    ((uint32_t)0x00000003)
#define MPU_COMMON_COMMON_CFG_3_CFRA_MASK    ((uint32_t)0x00FF0000)
#define MPU_COMMON_COMMON_CFG_3_CFRA_LSB    16
#define MPU_COMMON_COMMON_CFG_3_CFRA_WIDTH    ((uint32_t)0x00000008)
#define MPU_COMMON_COMMON_CFG_3_ANTENNA_SET_MASK    ((uint32_t)0x0000FFFF)
#define MPU_COMMON_COMMON_CFG_3_ANTENNA_SET_LSB    0
#define MPU_COMMON_COMMON_CFG_3_ANTENNA_SET_WIDTH    ((uint32_t)0x00000010)

#define MPU_COMMON_COMMON_CFG_3_TOTAL_NSTS_RST    0x0
#define MPU_COMMON_COMMON_CFG_3_CFRA_RST    0x0
#define MPU_COMMON_COMMON_CFG_3_ANTENNA_SET_RST    0x0

__INLINE void mpu_common_common_cfg_3_pack(uint8_t total_nsts, uint8_t cfra, uint16_t antenna_set)
{
	ASSERT_ERR((((uint32_t)total_nsts << 24) & ~((uint32_t)0x07000000)) == 0);
	ASSERT_ERR((((uint32_t)cfra << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)antenna_set << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MPU_COMMON_COMMON_CFG_3_ADDR,  ((uint32_t)total_nsts << 24) |((uint32_t)cfra << 16) |((uint32_t)antenna_set << 0));
}

__INLINE void mpu_common_common_cfg_3_unpack(uint8_t* total_nsts, uint8_t* cfra, uint16_t* antenna_set)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_COMMON_CFG_3_ADDR);

	*total_nsts = (localVal & ((uint32_t)0x07000000)) >>  24;
	*cfra = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*antenna_set = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint8_t mpu_common_common_cfg_3_total_nsts_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_COMMON_CFG_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE void mpu_common_common_cfg_3_total_nsts_setf(uint8_t totalnsts)
{
	ASSERT_ERR((((uint32_t)totalnsts << 24) & ~((uint32_t)0x07000000)) == 0);
	REG_PL_WR(MPU_COMMON_COMMON_CFG_3_ADDR, (REG_PL_RD(MPU_COMMON_COMMON_CFG_3_ADDR) & ~((uint32_t)0x07000000)) | ((uint32_t)totalnsts <<24));
}
__INLINE uint8_t mpu_common_common_cfg_3_cfra_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_COMMON_CFG_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void mpu_common_common_cfg_3_cfra_setf(uint8_t cfra)
{
	ASSERT_ERR((((uint32_t)cfra << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(MPU_COMMON_COMMON_CFG_3_ADDR, (REG_PL_RD(MPU_COMMON_COMMON_CFG_3_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)cfra <<16));
}
__INLINE uint16_t mpu_common_common_cfg_3_antenna_set_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_COMMON_CFG_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void mpu_common_common_cfg_3_antenna_set_setf(uint16_t antennaset)
{
	ASSERT_ERR((((uint32_t)antennaset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MPU_COMMON_COMMON_CFG_3_ADDR, (REG_PL_RD(MPU_COMMON_COMMON_CFG_3_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)antennaset <<0));
}

/**
 * @brief VHT_SIGA_ID register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    21:16 GROUP_ID                  0x0
 *    08:00 PARTIAL_AID               0x0
 * </pre>
 */
#define MPU_COMMON_VHT_SIGA_ID_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000020)
#define MPU_COMMON_VHT_SIGA_ID_OFFSET      0x00000020
#define MPU_COMMON_VHT_SIGA_ID_INDEX       0x00000008
#define MPU_COMMON_VHT_SIGA_ID_RESET       0x00000000

__INLINE uint32_t  mpu_common_vht_siga_id_get(void)
{
	return REG_PL_RD(MPU_COMMON_VHT_SIGA_ID_ADDR);
}

__INLINE void mpu_common_vht_siga_id_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_VHT_SIGA_ID_ADDR, value);
}

// field definitions
#define MPU_COMMON_VHT_SIGA_ID_GROUP_ID_MASK    ((uint32_t)0x003F0000)
#define MPU_COMMON_VHT_SIGA_ID_GROUP_ID_LSB    16
#define MPU_COMMON_VHT_SIGA_ID_GROUP_ID_WIDTH    ((uint32_t)0x00000006)
#define MPU_COMMON_VHT_SIGA_ID_PARTIAL_AID_MASK    ((uint32_t)0x000001FF)
#define MPU_COMMON_VHT_SIGA_ID_PARTIAL_AID_LSB    0
#define MPU_COMMON_VHT_SIGA_ID_PARTIAL_AID_WIDTH    ((uint32_t)0x00000009)

#define MPU_COMMON_VHT_SIGA_ID_GROUP_ID_RST    0x0
#define MPU_COMMON_VHT_SIGA_ID_PARTIAL_AID_RST    0x0

__INLINE void mpu_common_vht_siga_id_pack(uint8_t group_id, uint16_t partial_aid)
{
	ASSERT_ERR((((uint32_t)group_id << 16) & ~((uint32_t)0x003F0000)) == 0);
	ASSERT_ERR((((uint32_t)partial_aid << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(MPU_COMMON_VHT_SIGA_ID_ADDR,  ((uint32_t)group_id << 16) |((uint32_t)partial_aid << 0));
}

__INLINE void mpu_common_vht_siga_id_unpack(uint8_t* group_id, uint16_t* partial_aid)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_VHT_SIGA_ID_ADDR);

	*group_id = (localVal & ((uint32_t)0x003F0000)) >>  16;
	*partial_aid = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint8_t mpu_common_vht_siga_id_group_id_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_VHT_SIGA_ID_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x003F0000)) >> 16);
}
__INLINE void mpu_common_vht_siga_id_group_id_setf(uint8_t groupid)
{
	ASSERT_ERR((((uint32_t)groupid << 16) & ~((uint32_t)0x003F0000)) == 0);
	REG_PL_WR(MPU_COMMON_VHT_SIGA_ID_ADDR, (REG_PL_RD(MPU_COMMON_VHT_SIGA_ID_ADDR) & ~((uint32_t)0x003F0000)) | ((uint32_t)groupid <<16));
}
__INLINE uint16_t mpu_common_vht_siga_id_partial_aid_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_VHT_SIGA_ID_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}
__INLINE void mpu_common_vht_siga_id_partial_aid_setf(uint16_t partialaid)
{
	ASSERT_ERR((((uint32_t)partialaid << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(MPU_COMMON_VHT_SIGA_ID_ADDR, (REG_PL_RD(MPU_COMMON_VHT_SIGA_ID_ADDR) & ~((uint32_t)0x000001FF)) | ((uint32_t)partialaid <<0));
}

/**
 * @brief HE_CFG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    HE_SIGA_FORMAT            0              
 *    30    PE_DISAMBIGUITY           0              
 *    29:28 PRE_FEC_PAD_FACTOR        0x0
 *    27    BEAM_CHANGE               0              
 *    26:24 NUM_HE_LFT_SYMBOLS        0x0
 *    23:20 NUM_SIGB_SYMBOLS_SIGA     0x0
 *    19    SIGB_COMPRESSION          0              
 *    18:12 TXOP_DURATION             0x7F
 *    11    SIGB_DCM                  0              
 *    10:08 SIGB_MCS                  0x0
 *    07    UPLINK                    0              
 *    06    DOPPLER                   0              
 *    05:00 BSS_COLOR                 0x0
 * </pre>
 */
#define MPU_COMMON_HE_CFG_1_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000024)
#define MPU_COMMON_HE_CFG_1_OFFSET      0x00000024
#define MPU_COMMON_HE_CFG_1_INDEX       0x00000009
#define MPU_COMMON_HE_CFG_1_RESET       0x0007F000

__INLINE uint32_t  mpu_common_he_cfg_1_get(void)
{
	return REG_PL_RD(MPU_COMMON_HE_CFG_1_ADDR);
}

__INLINE void mpu_common_he_cfg_1_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_HE_CFG_1_ADDR, value);
}

// field definitions
#define MPU_COMMON_HE_CFG_1_HE_SIGA_FORMAT_BIT    ((uint32_t)0x80000000)
#define MPU_COMMON_HE_CFG_1_HE_SIGA_FORMAT_POS    31
#define MPU_COMMON_HE_CFG_1_PE_DISAMBIGUITY_BIT    ((uint32_t)0x40000000)
#define MPU_COMMON_HE_CFG_1_PE_DISAMBIGUITY_POS    30
#define MPU_COMMON_HE_CFG_1_PRE_FEC_PAD_FACTOR_MASK    ((uint32_t)0x30000000)
#define MPU_COMMON_HE_CFG_1_PRE_FEC_PAD_FACTOR_LSB    28
#define MPU_COMMON_HE_CFG_1_PRE_FEC_PAD_FACTOR_WIDTH    ((uint32_t)0x00000002)
#define MPU_COMMON_HE_CFG_1_BEAM_CHANGE_BIT    ((uint32_t)0x08000000)
#define MPU_COMMON_HE_CFG_1_BEAM_CHANGE_POS    27
#define MPU_COMMON_HE_CFG_1_NUM_HE_LFT_SYMBOLS_MASK    ((uint32_t)0x07000000)
#define MPU_COMMON_HE_CFG_1_NUM_HE_LFT_SYMBOLS_LSB    24
#define MPU_COMMON_HE_CFG_1_NUM_HE_LFT_SYMBOLS_WIDTH    ((uint32_t)0x00000003)
#define MPU_COMMON_HE_CFG_1_NUM_SIGB_SYMBOLS_SIGA_MASK    ((uint32_t)0x00F00000)
#define MPU_COMMON_HE_CFG_1_NUM_SIGB_SYMBOLS_SIGA_LSB    20
#define MPU_COMMON_HE_CFG_1_NUM_SIGB_SYMBOLS_SIGA_WIDTH    ((uint32_t)0x00000004)
#define MPU_COMMON_HE_CFG_1_SIGB_COMPRESSION_BIT    ((uint32_t)0x00080000)
#define MPU_COMMON_HE_CFG_1_SIGB_COMPRESSION_POS    19
#define MPU_COMMON_HE_CFG_1_TXOP_DURATION_MASK    ((uint32_t)0x0007F000)
#define MPU_COMMON_HE_CFG_1_TXOP_DURATION_LSB    12
#define MPU_COMMON_HE_CFG_1_TXOP_DURATION_WIDTH    ((uint32_t)0x00000007)
#define MPU_COMMON_HE_CFG_1_SIGB_DCM_BIT    ((uint32_t)0x00000800)
#define MPU_COMMON_HE_CFG_1_SIGB_DCM_POS    11
#define MPU_COMMON_HE_CFG_1_SIGB_MCS_MASK    ((uint32_t)0x00000700)
#define MPU_COMMON_HE_CFG_1_SIGB_MCS_LSB    8
#define MPU_COMMON_HE_CFG_1_SIGB_MCS_WIDTH    ((uint32_t)0x00000003)
#define MPU_COMMON_HE_CFG_1_UPLINK_BIT      ((uint32_t)0x00000080)
#define MPU_COMMON_HE_CFG_1_UPLINK_POS      7
#define MPU_COMMON_HE_CFG_1_DOPPLER_BIT     ((uint32_t)0x00000040)
#define MPU_COMMON_HE_CFG_1_DOPPLER_POS     6
#define MPU_COMMON_HE_CFG_1_BSS_COLOR_MASK    ((uint32_t)0x0000003F)
#define MPU_COMMON_HE_CFG_1_BSS_COLOR_LSB    0
#define MPU_COMMON_HE_CFG_1_BSS_COLOR_WIDTH    ((uint32_t)0x00000006)

#define MPU_COMMON_HE_CFG_1_HE_SIGA_FORMAT_RST    0x0
#define MPU_COMMON_HE_CFG_1_PE_DISAMBIGUITY_RST    0x0
#define MPU_COMMON_HE_CFG_1_PRE_FEC_PAD_FACTOR_RST    0x0
#define MPU_COMMON_HE_CFG_1_BEAM_CHANGE_RST    0x0
#define MPU_COMMON_HE_CFG_1_NUM_HE_LFT_SYMBOLS_RST    0x0
#define MPU_COMMON_HE_CFG_1_NUM_SIGB_SYMBOLS_SIGA_RST    0x0
#define MPU_COMMON_HE_CFG_1_SIGB_COMPRESSION_RST    0x0
#define MPU_COMMON_HE_CFG_1_TXOP_DURATION_RST    0x7F
#define MPU_COMMON_HE_CFG_1_SIGB_DCM_RST    0x0
#define MPU_COMMON_HE_CFG_1_SIGB_MCS_RST    0x0
#define MPU_COMMON_HE_CFG_1_UPLINK_RST      0x0
#define MPU_COMMON_HE_CFG_1_DOPPLER_RST     0x0
#define MPU_COMMON_HE_CFG_1_BSS_COLOR_RST    0x0

__INLINE void mpu_common_he_cfg_1_pack(uint8_t he_siga_format, uint8_t pe_disambiguity, uint8_t pre_fec_pad_factor, uint8_t beam_change, uint8_t num_he_lft_symbols, uint8_t num_sigb_symbols_siga, uint8_t sigb_compression, uint8_t txop_duration, uint8_t sigb_dcm, uint8_t sigb_mcs, uint8_t uplink, uint8_t doppler, uint8_t bss_color)
{
	ASSERT_ERR((((uint32_t)he_siga_format << 31) & ~((uint32_t)0x80000000)) == 0);
	ASSERT_ERR((((uint32_t)pe_disambiguity << 30) & ~((uint32_t)0x40000000)) == 0);
	ASSERT_ERR((((uint32_t)pre_fec_pad_factor << 28) & ~((uint32_t)0x30000000)) == 0);
	ASSERT_ERR((((uint32_t)beam_change << 27) & ~((uint32_t)0x08000000)) == 0);
	ASSERT_ERR((((uint32_t)num_he_lft_symbols << 24) & ~((uint32_t)0x07000000)) == 0);
	ASSERT_ERR((((uint32_t)num_sigb_symbols_siga << 20) & ~((uint32_t)0x00F00000)) == 0);
	ASSERT_ERR((((uint32_t)sigb_compression << 19) & ~((uint32_t)0x00080000)) == 0);
	ASSERT_ERR((((uint32_t)txop_duration << 12) & ~((uint32_t)0x0007F000)) == 0);
	ASSERT_ERR((((uint32_t)sigb_dcm << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)sigb_mcs << 8) & ~((uint32_t)0x00000700)) == 0);
	ASSERT_ERR((((uint32_t)uplink << 7) & ~((uint32_t)0x00000080)) == 0);
	ASSERT_ERR((((uint32_t)doppler << 6) & ~((uint32_t)0x00000040)) == 0);
	ASSERT_ERR((((uint32_t)bss_color << 0) & ~((uint32_t)0x0000003F)) == 0);
	REG_PL_WR(MPU_COMMON_HE_CFG_1_ADDR,  ((uint32_t)he_siga_format << 31) |((uint32_t)pe_disambiguity << 30) |((uint32_t)pre_fec_pad_factor << 28) |((uint32_t)beam_change << 27) |((uint32_t)num_he_lft_symbols << 24) |((uint32_t)num_sigb_symbols_siga << 20) |((uint32_t)sigb_compression << 19) |((uint32_t)txop_duration << 12) |((uint32_t)sigb_dcm << 11) |((uint32_t)sigb_mcs << 8) |((uint32_t)uplink << 7) |((uint32_t)doppler << 6) |((uint32_t)bss_color << 0));
}

__INLINE void mpu_common_he_cfg_1_unpack(uint8_t* he_siga_format, uint8_t* pe_disambiguity, uint8_t* pre_fec_pad_factor, uint8_t* beam_change, uint8_t* num_he_lft_symbols, uint8_t* num_sigb_symbols_siga, uint8_t* sigb_compression, uint8_t* txop_duration, uint8_t* sigb_dcm, uint8_t* sigb_mcs, uint8_t* uplink, uint8_t* doppler, uint8_t* bss_color)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_CFG_1_ADDR);

	*he_siga_format = (localVal & ((uint32_t)0x80000000)) >>  31;
	*pe_disambiguity = (localVal & ((uint32_t)0x40000000)) >>  30;
	*pre_fec_pad_factor = (localVal & ((uint32_t)0x30000000)) >>  28;
	*beam_change = (localVal & ((uint32_t)0x08000000)) >>  27;
	*num_he_lft_symbols = (localVal & ((uint32_t)0x07000000)) >>  24;
	*num_sigb_symbols_siga = (localVal & ((uint32_t)0x00F00000)) >>  20;
	*sigb_compression = (localVal & ((uint32_t)0x00080000)) >>  19;
	*txop_duration = (localVal & ((uint32_t)0x0007F000)) >>  12;
	*sigb_dcm = (localVal & ((uint32_t)0x00000800)) >>  11;
	*sigb_mcs = (localVal & ((uint32_t)0x00000700)) >>  8;
	*uplink = (localVal & ((uint32_t)0x00000080)) >>  7;
	*doppler = (localVal & ((uint32_t)0x00000040)) >>  6;
	*bss_color = (localVal & ((uint32_t)0x0000003F)) >>  0;
}

__INLINE uint8_t mpu_common_he_cfg_1_he_siga_format_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE void mpu_common_he_cfg_1_he_siga_format_setf(uint8_t hesigaformat)
{
	ASSERT_ERR((((uint32_t)hesigaformat << 31) & ~((uint32_t)0x80000000)) == 0);
	REG_PL_WR(MPU_COMMON_HE_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_HE_CFG_1_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)hesigaformat <<31));
}
__INLINE uint8_t mpu_common_he_cfg_1_pe_disambiguity_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x40000000)) >> 30);
}
__INLINE void mpu_common_he_cfg_1_pe_disambiguity_setf(uint8_t pedisambiguity)
{
	ASSERT_ERR((((uint32_t)pedisambiguity << 30) & ~((uint32_t)0x40000000)) == 0);
	REG_PL_WR(MPU_COMMON_HE_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_HE_CFG_1_ADDR) & ~((uint32_t)0x40000000)) | ((uint32_t)pedisambiguity <<30));
}
__INLINE uint8_t mpu_common_he_cfg_1_pre_fec_pad_factor_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x30000000)) >> 28);
}
__INLINE void mpu_common_he_cfg_1_pre_fec_pad_factor_setf(uint8_t prefecpadfactor)
{
	ASSERT_ERR((((uint32_t)prefecpadfactor << 28) & ~((uint32_t)0x30000000)) == 0);
	REG_PL_WR(MPU_COMMON_HE_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_HE_CFG_1_ADDR) & ~((uint32_t)0x30000000)) | ((uint32_t)prefecpadfactor <<28));
}
__INLINE uint8_t mpu_common_he_cfg_1_beam_change_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x08000000)) >> 27);
}
__INLINE void mpu_common_he_cfg_1_beam_change_setf(uint8_t beamchange)
{
	ASSERT_ERR((((uint32_t)beamchange << 27) & ~((uint32_t)0x08000000)) == 0);
	REG_PL_WR(MPU_COMMON_HE_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_HE_CFG_1_ADDR) & ~((uint32_t)0x08000000)) | ((uint32_t)beamchange <<27));
}
__INLINE uint8_t mpu_common_he_cfg_1_num_he_lft_symbols_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE void mpu_common_he_cfg_1_num_he_lft_symbols_setf(uint8_t numhelftsymbols)
{
	ASSERT_ERR((((uint32_t)numhelftsymbols << 24) & ~((uint32_t)0x07000000)) == 0);
	REG_PL_WR(MPU_COMMON_HE_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_HE_CFG_1_ADDR) & ~((uint32_t)0x07000000)) | ((uint32_t)numhelftsymbols <<24));
}
__INLINE uint8_t mpu_common_he_cfg_1_num_sigb_symbols_siga_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00F00000)) >> 20);
}
__INLINE void mpu_common_he_cfg_1_num_sigb_symbols_siga_setf(uint8_t numsigbsymbolssiga)
{
	ASSERT_ERR((((uint32_t)numsigbsymbolssiga << 20) & ~((uint32_t)0x00F00000)) == 0);
	REG_PL_WR(MPU_COMMON_HE_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_HE_CFG_1_ADDR) & ~((uint32_t)0x00F00000)) | ((uint32_t)numsigbsymbolssiga <<20));
}
__INLINE uint8_t mpu_common_he_cfg_1_sigb_compression_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00080000)) >> 19);
}
__INLINE void mpu_common_he_cfg_1_sigb_compression_setf(uint8_t sigbcompression)
{
	ASSERT_ERR((((uint32_t)sigbcompression << 19) & ~((uint32_t)0x00080000)) == 0);
	REG_PL_WR(MPU_COMMON_HE_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_HE_CFG_1_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)sigbcompression <<19));
}
__INLINE uint8_t mpu_common_he_cfg_1_txop_duration_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0007F000)) >> 12);
}
__INLINE void mpu_common_he_cfg_1_txop_duration_setf(uint8_t txopduration)
{
	ASSERT_ERR((((uint32_t)txopduration << 12) & ~((uint32_t)0x0007F000)) == 0);
	REG_PL_WR(MPU_COMMON_HE_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_HE_CFG_1_ADDR) & ~((uint32_t)0x0007F000)) | ((uint32_t)txopduration <<12));
}
__INLINE uint8_t mpu_common_he_cfg_1_sigb_dcm_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void mpu_common_he_cfg_1_sigb_dcm_setf(uint8_t sigbdcm)
{
	ASSERT_ERR((((uint32_t)sigbdcm << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(MPU_COMMON_HE_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_HE_CFG_1_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)sigbdcm <<11));
}
__INLINE uint8_t mpu_common_he_cfg_1_sigb_mcs_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000700)) >> 8);
}
__INLINE void mpu_common_he_cfg_1_sigb_mcs_setf(uint8_t sigbmcs)
{
	ASSERT_ERR((((uint32_t)sigbmcs << 8) & ~((uint32_t)0x00000700)) == 0);
	REG_PL_WR(MPU_COMMON_HE_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_HE_CFG_1_ADDR) & ~((uint32_t)0x00000700)) | ((uint32_t)sigbmcs <<8));
}
__INLINE uint8_t mpu_common_he_cfg_1_uplink_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE void mpu_common_he_cfg_1_uplink_setf(uint8_t uplink)
{
	ASSERT_ERR((((uint32_t)uplink << 7) & ~((uint32_t)0x00000080)) == 0);
	REG_PL_WR(MPU_COMMON_HE_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_HE_CFG_1_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)uplink <<7));
}
__INLINE uint8_t mpu_common_he_cfg_1_doppler_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE void mpu_common_he_cfg_1_doppler_setf(uint8_t doppler)
{
	ASSERT_ERR((((uint32_t)doppler << 6) & ~((uint32_t)0x00000040)) == 0);
	REG_PL_WR(MPU_COMMON_HE_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_HE_CFG_1_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)doppler <<6));
}
__INLINE uint8_t mpu_common_he_cfg_1_bss_color_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000003F)) >> 0);
}
__INLINE void mpu_common_he_cfg_1_bss_color_setf(uint8_t bsscolor)
{
	ASSERT_ERR((((uint32_t)bsscolor << 0) & ~((uint32_t)0x0000003F)) == 0);
	REG_PL_WR(MPU_COMMON_HE_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_HE_CFG_1_ADDR) & ~((uint32_t)0x0000003F)) | ((uint32_t)bsscolor <<0));
}

/**
 * @brief HE_CFG_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:23 HE_SIG_A2_RESERVED        0x0
 *    22:20 PE_DURATION               0x0
 *    19    MU_RTS                    0              
 *    18    LTF_MODE                  0              
 *    17:16 LTF_TYPE                  0x0
 *    15:00 SPATIAL_REUSE             0x0
 * </pre>
 */
#define MPU_COMMON_HE_CFG_2_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000028)
#define MPU_COMMON_HE_CFG_2_OFFSET      0x00000028
#define MPU_COMMON_HE_CFG_2_INDEX       0x0000000A
#define MPU_COMMON_HE_CFG_2_RESET       0x00000000

__INLINE uint32_t  mpu_common_he_cfg_2_get(void)
{
	return REG_PL_RD(MPU_COMMON_HE_CFG_2_ADDR);
}

__INLINE void mpu_common_he_cfg_2_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_HE_CFG_2_ADDR, value);
}

// field definitions
#define MPU_COMMON_HE_CFG_2_HE_SIG_A_2_RESERVED_MASK    ((uint32_t)0xFF800000)
#define MPU_COMMON_HE_CFG_2_HE_SIG_A_2_RESERVED_LSB    23
#define MPU_COMMON_HE_CFG_2_HE_SIG_A_2_RESERVED_WIDTH    ((uint32_t)0x00000009)
#define MPU_COMMON_HE_CFG_2_PE_DURATION_MASK    ((uint32_t)0x00700000)
#define MPU_COMMON_HE_CFG_2_PE_DURATION_LSB    20
#define MPU_COMMON_HE_CFG_2_PE_DURATION_WIDTH    ((uint32_t)0x00000003)
#define MPU_COMMON_HE_CFG_2_MU_RTS_BIT      ((uint32_t)0x00080000)
#define MPU_COMMON_HE_CFG_2_MU_RTS_POS      19
#define MPU_COMMON_HE_CFG_2_LTF_MODE_BIT    ((uint32_t)0x00040000)
#define MPU_COMMON_HE_CFG_2_LTF_MODE_POS    18
#define MPU_COMMON_HE_CFG_2_LTF_TYPE_MASK    ((uint32_t)0x00030000)
#define MPU_COMMON_HE_CFG_2_LTF_TYPE_LSB    16
#define MPU_COMMON_HE_CFG_2_LTF_TYPE_WIDTH    ((uint32_t)0x00000002)
#define MPU_COMMON_HE_CFG_2_SPATIAL_REUSE_MASK    ((uint32_t)0x0000FFFF)
#define MPU_COMMON_HE_CFG_2_SPATIAL_REUSE_LSB    0
#define MPU_COMMON_HE_CFG_2_SPATIAL_REUSE_WIDTH    ((uint32_t)0x00000010)

#define MPU_COMMON_HE_CFG_2_HE_SIG_A_2_RESERVED_RST    0x0
#define MPU_COMMON_HE_CFG_2_PE_DURATION_RST    0x0
#define MPU_COMMON_HE_CFG_2_MU_RTS_RST      0x0
#define MPU_COMMON_HE_CFG_2_LTF_MODE_RST    0x0
#define MPU_COMMON_HE_CFG_2_LTF_TYPE_RST    0x0
#define MPU_COMMON_HE_CFG_2_SPATIAL_REUSE_RST    0x0

__INLINE void mpu_common_he_cfg_2_pack(uint16_t he_sig_a2_reserved, uint8_t pe_duration, uint8_t mu_rts, uint8_t ltf_mode, uint8_t ltf_type, uint16_t spatial_reuse)
{
	ASSERT_ERR((((uint32_t)he_sig_a2_reserved << 23) & ~((uint32_t)0xFF800000)) == 0);
	ASSERT_ERR((((uint32_t)pe_duration << 20) & ~((uint32_t)0x00700000)) == 0);
	ASSERT_ERR((((uint32_t)mu_rts << 19) & ~((uint32_t)0x00080000)) == 0);
	ASSERT_ERR((((uint32_t)ltf_mode << 18) & ~((uint32_t)0x00040000)) == 0);
	ASSERT_ERR((((uint32_t)ltf_type << 16) & ~((uint32_t)0x00030000)) == 0);
	ASSERT_ERR((((uint32_t)spatial_reuse << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MPU_COMMON_HE_CFG_2_ADDR,  ((uint32_t)he_sig_a2_reserved << 23) |((uint32_t)pe_duration << 20) |((uint32_t)mu_rts << 19) |((uint32_t)ltf_mode << 18) |((uint32_t)ltf_type << 16) |((uint32_t)spatial_reuse << 0));
}

__INLINE void mpu_common_he_cfg_2_unpack(uint16_t* he_sig_a2_reserved, uint8_t* pe_duration, uint8_t* mu_rts, uint8_t* ltf_mode, uint8_t* ltf_type, uint16_t* spatial_reuse)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_CFG_2_ADDR);

	*he_sig_a2_reserved = (localVal & ((uint32_t)0xFF800000)) >>  23;
	*pe_duration = (localVal & ((uint32_t)0x00700000)) >>  20;
	*mu_rts = (localVal & ((uint32_t)0x00080000)) >>  19;
	*ltf_mode = (localVal & ((uint32_t)0x00040000)) >>  18;
	*ltf_type = (localVal & ((uint32_t)0x00030000)) >>  16;
	*spatial_reuse = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t mpu_common_he_cfg_2_he_sig_a_2_reserved_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_CFG_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFF800000)) >> 23);
}
__INLINE void mpu_common_he_cfg_2_he_sig_a_2_reserved_setf(uint16_t hesiga2reserved)
{
	ASSERT_ERR((((uint32_t)hesiga2reserved << 23) & ~((uint32_t)0xFF800000)) == 0);
	REG_PL_WR(MPU_COMMON_HE_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_HE_CFG_2_ADDR) & ~((uint32_t)0xFF800000)) | ((uint32_t)hesiga2reserved <<23));
}
__INLINE uint8_t mpu_common_he_cfg_2_pe_duration_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00700000)) >> 20);
}
__INLINE void mpu_common_he_cfg_2_pe_duration_setf(uint8_t peduration)
{
	ASSERT_ERR((((uint32_t)peduration << 20) & ~((uint32_t)0x00700000)) == 0);
	REG_PL_WR(MPU_COMMON_HE_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_HE_CFG_2_ADDR) & ~((uint32_t)0x00700000)) | ((uint32_t)peduration <<20));
}
__INLINE uint8_t mpu_common_he_cfg_2_mu_rts_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00080000)) >> 19);
}
__INLINE void mpu_common_he_cfg_2_mu_rts_setf(uint8_t murts)
{
	ASSERT_ERR((((uint32_t)murts << 19) & ~((uint32_t)0x00080000)) == 0);
	REG_PL_WR(MPU_COMMON_HE_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_HE_CFG_2_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)murts <<19));
}
__INLINE uint8_t mpu_common_he_cfg_2_ltf_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00040000)) >> 18);
}
__INLINE void mpu_common_he_cfg_2_ltf_mode_setf(uint8_t ltfmode)
{
	ASSERT_ERR((((uint32_t)ltfmode << 18) & ~((uint32_t)0x00040000)) == 0);
	REG_PL_WR(MPU_COMMON_HE_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_HE_CFG_2_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)ltfmode <<18));
}
__INLINE uint8_t mpu_common_he_cfg_2_ltf_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00030000)) >> 16);
}
__INLINE void mpu_common_he_cfg_2_ltf_type_setf(uint8_t ltftype)
{
	ASSERT_ERR((((uint32_t)ltftype << 16) & ~((uint32_t)0x00030000)) == 0);
	REG_PL_WR(MPU_COMMON_HE_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_HE_CFG_2_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)ltftype <<16));
}
__INLINE uint16_t mpu_common_he_cfg_2_spatial_reuse_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_CFG_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void mpu_common_he_cfg_2_spatial_reuse_setf(uint16_t spatialreuse)
{
	ASSERT_ERR((((uint32_t)spatialreuse << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MPU_COMMON_HE_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_HE_CFG_2_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)spatialreuse <<0));
}

/**
 * @brief HE_SIGB_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    09:08 CRC_DELAY                 0x0
 *    06:04 STA_ID_LAST               0x0
 *    01    SIGB_MEM_ACCESS           0              
 *    00    SIGB_GEN_ENABLE           0              
 * </pre>
 */
#define MPU_COMMON_HE_SIGB_CTRL_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x0000002C)
#define MPU_COMMON_HE_SIGB_CTRL_OFFSET      0x0000002C
#define MPU_COMMON_HE_SIGB_CTRL_INDEX       0x0000000B
#define MPU_COMMON_HE_SIGB_CTRL_RESET       0x00000000

__INLINE uint32_t  mpu_common_he_sigb_ctrl_get(void)
{
	return REG_PL_RD(MPU_COMMON_HE_SIGB_CTRL_ADDR);
}

__INLINE void mpu_common_he_sigb_ctrl_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_HE_SIGB_CTRL_ADDR, value);
}

// field definitions
#define MPU_COMMON_HE_SIGB_CTRL_CRC_DELAY_MASK    ((uint32_t)0x00000300)
#define MPU_COMMON_HE_SIGB_CTRL_CRC_DELAY_LSB    8
#define MPU_COMMON_HE_SIGB_CTRL_CRC_DELAY_WIDTH    ((uint32_t)0x00000002)
#define MPU_COMMON_HE_SIGB_CTRL_STA_ID_LAST_MASK    ((uint32_t)0x00000070)
#define MPU_COMMON_HE_SIGB_CTRL_STA_ID_LAST_LSB    4
#define MPU_COMMON_HE_SIGB_CTRL_STA_ID_LAST_WIDTH    ((uint32_t)0x00000003)
#define MPU_COMMON_HE_SIGB_CTRL_SIGB_MEM_ACCESS_BIT    ((uint32_t)0x00000002)
#define MPU_COMMON_HE_SIGB_CTRL_SIGB_MEM_ACCESS_POS    1
#define MPU_COMMON_HE_SIGB_CTRL_SIGB_GEN_ENABLE_BIT    ((uint32_t)0x00000001)
#define MPU_COMMON_HE_SIGB_CTRL_SIGB_GEN_ENABLE_POS    0

#define MPU_COMMON_HE_SIGB_CTRL_CRC_DELAY_RST    0x0
#define MPU_COMMON_HE_SIGB_CTRL_STA_ID_LAST_RST    0x0
#define MPU_COMMON_HE_SIGB_CTRL_SIGB_MEM_ACCESS_RST    0x0
#define MPU_COMMON_HE_SIGB_CTRL_SIGB_GEN_ENABLE_RST    0x0

__INLINE void mpu_common_he_sigb_ctrl_pack(uint8_t crc_delay, uint8_t sta_id_last, uint8_t sigb_mem_access, uint8_t sigb_gen_enable)
{
	ASSERT_ERR((((uint32_t)crc_delay << 8) & ~((uint32_t)0x00000300)) == 0);
	ASSERT_ERR((((uint32_t)sta_id_last << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)sigb_mem_access << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)sigb_gen_enable << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MPU_COMMON_HE_SIGB_CTRL_ADDR,  ((uint32_t)crc_delay << 8) |((uint32_t)sta_id_last << 4) |((uint32_t)sigb_mem_access << 1) |((uint32_t)sigb_gen_enable << 0));
}

__INLINE void mpu_common_he_sigb_ctrl_unpack(uint8_t* crc_delay, uint8_t* sta_id_last, uint8_t* sigb_mem_access, uint8_t* sigb_gen_enable)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_SIGB_CTRL_ADDR);

	*crc_delay = (localVal & ((uint32_t)0x00000300)) >>  8;
	*sta_id_last = (localVal & ((uint32_t)0x00000070)) >>  4;
	*sigb_mem_access = (localVal & ((uint32_t)0x00000002)) >>  1;
	*sigb_gen_enable = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t mpu_common_he_sigb_ctrl_crc_delay_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_SIGB_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000300)) >> 8);
}
__INLINE void mpu_common_he_sigb_ctrl_crc_delay_setf(uint8_t crcdelay)
{
	ASSERT_ERR((((uint32_t)crcdelay << 8) & ~((uint32_t)0x00000300)) == 0);
	REG_PL_WR(MPU_COMMON_HE_SIGB_CTRL_ADDR, (REG_PL_RD(MPU_COMMON_HE_SIGB_CTRL_ADDR) & ~((uint32_t)0x00000300)) | ((uint32_t)crcdelay <<8));
}
__INLINE uint8_t mpu_common_he_sigb_ctrl_sta_id_last_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_SIGB_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void mpu_common_he_sigb_ctrl_sta_id_last_setf(uint8_t staidlast)
{
	ASSERT_ERR((((uint32_t)staidlast << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(MPU_COMMON_HE_SIGB_CTRL_ADDR, (REG_PL_RD(MPU_COMMON_HE_SIGB_CTRL_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)staidlast <<4));
}
__INLINE uint8_t mpu_common_he_sigb_ctrl_sigb_mem_access_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_SIGB_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void mpu_common_he_sigb_ctrl_sigb_mem_access_setf(uint8_t sigbmemaccess)
{
	ASSERT_ERR((((uint32_t)sigbmemaccess << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(MPU_COMMON_HE_SIGB_CTRL_ADDR, (REG_PL_RD(MPU_COMMON_HE_SIGB_CTRL_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)sigbmemaccess <<1));
}
__INLINE void mpu_common_he_sigb_ctrl_sigb_gen_enable_setf(uint8_t sigbgenenable)
{
	ASSERT_ERR((((uint32_t)sigbgenenable << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MPU_COMMON_HE_SIGB_CTRL_ADDR, (REG_PL_RD(MPU_COMMON_HE_SIGB_CTRL_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)sigbgenenable <<0));
}

/**
 * @brief HE_SIGB_CC_1_CFG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28    CC1_CENTER_RU_EXIST       0              
 *    24:12 CC1_PADDING               0x0
 *    10:00 CC1_LENGTH                0x0
 * </pre>
 */
#define MPU_COMMON_HE_SIGB_CC_1_CFG_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000030)
#define MPU_COMMON_HE_SIGB_CC_1_CFG_OFFSET      0x00000030
#define MPU_COMMON_HE_SIGB_CC_1_CFG_INDEX       0x0000000C
#define MPU_COMMON_HE_SIGB_CC_1_CFG_RESET       0x00000000

__INLINE uint32_t  mpu_common_he_sigb_cc_1_cfg_get(void)
{
	return REG_PL_RD(MPU_COMMON_HE_SIGB_CC_1_CFG_ADDR);
}

__INLINE void mpu_common_he_sigb_cc_1_cfg_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_HE_SIGB_CC_1_CFG_ADDR, value);
}

// field definitions
#define MPU_COMMON_HE_SIGB_CC_1_CFG_CC_1_CENTER_RU_EXIST_BIT    ((uint32_t)0x10000000)
#define MPU_COMMON_HE_SIGB_CC_1_CFG_CC_1_CENTER_RU_EXIST_POS    28
#define MPU_COMMON_HE_SIGB_CC_1_CFG_CC_1_PADDING_MASK    ((uint32_t)0x01FFF000)
#define MPU_COMMON_HE_SIGB_CC_1_CFG_CC_1_PADDING_LSB    12
#define MPU_COMMON_HE_SIGB_CC_1_CFG_CC_1_PADDING_WIDTH    ((uint32_t)0x0000000D)
#define MPU_COMMON_HE_SIGB_CC_1_CFG_CC_1_LENGTH_MASK    ((uint32_t)0x000007FF)
#define MPU_COMMON_HE_SIGB_CC_1_CFG_CC_1_LENGTH_LSB    0
#define MPU_COMMON_HE_SIGB_CC_1_CFG_CC_1_LENGTH_WIDTH    ((uint32_t)0x0000000B)

#define MPU_COMMON_HE_SIGB_CC_1_CFG_CC_1_CENTER_RU_EXIST_RST    0x0
#define MPU_COMMON_HE_SIGB_CC_1_CFG_CC_1_PADDING_RST    0x0
#define MPU_COMMON_HE_SIGB_CC_1_CFG_CC_1_LENGTH_RST    0x0

__INLINE void mpu_common_he_sigb_cc_1_cfg_pack(uint8_t cc1_center_ru_exist, uint16_t cc1_padding, uint16_t cc1_length)
{
	ASSERT_ERR((((uint32_t)cc1_center_ru_exist << 28) & ~((uint32_t)0x10000000)) == 0);
	ASSERT_ERR((((uint32_t)cc1_padding << 12) & ~((uint32_t)0x01FFF000)) == 0);
	ASSERT_ERR((((uint32_t)cc1_length << 0) & ~((uint32_t)0x000007FF)) == 0);
	REG_PL_WR(MPU_COMMON_HE_SIGB_CC_1_CFG_ADDR,  ((uint32_t)cc1_center_ru_exist << 28) |((uint32_t)cc1_padding << 12) |((uint32_t)cc1_length << 0));
}

__INLINE void mpu_common_he_sigb_cc_1_cfg_unpack(uint8_t* cc1_center_ru_exist, uint16_t* cc1_padding, uint16_t* cc1_length)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_SIGB_CC_1_CFG_ADDR);

	*cc1_center_ru_exist = (localVal & ((uint32_t)0x10000000)) >>  28;
	*cc1_padding = (localVal & ((uint32_t)0x01FFF000)) >>  12;
	*cc1_length = (localVal & ((uint32_t)0x000007FF)) >>  0;
}

__INLINE uint8_t mpu_common_he_sigb_cc_1_cfg_cc_1_center_ru_exist_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_SIGB_CC_1_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x10000000)) >> 28);
}
__INLINE void mpu_common_he_sigb_cc_1_cfg_cc_1_center_ru_exist_setf(uint8_t cc1centerruexist)
{
	ASSERT_ERR((((uint32_t)cc1centerruexist << 28) & ~((uint32_t)0x10000000)) == 0);
	REG_PL_WR(MPU_COMMON_HE_SIGB_CC_1_CFG_ADDR, (REG_PL_RD(MPU_COMMON_HE_SIGB_CC_1_CFG_ADDR) & ~((uint32_t)0x10000000)) | ((uint32_t)cc1centerruexist <<28));
}
__INLINE uint16_t mpu_common_he_sigb_cc_1_cfg_cc_1_padding_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_SIGB_CC_1_CFG_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x01FFF000)) >> 12);
}
__INLINE void mpu_common_he_sigb_cc_1_cfg_cc_1_padding_setf(uint16_t cc1padding)
{
	ASSERT_ERR((((uint32_t)cc1padding << 12) & ~((uint32_t)0x01FFF000)) == 0);
	REG_PL_WR(MPU_COMMON_HE_SIGB_CC_1_CFG_ADDR, (REG_PL_RD(MPU_COMMON_HE_SIGB_CC_1_CFG_ADDR) & ~((uint32_t)0x01FFF000)) | ((uint32_t)cc1padding <<12));
}
__INLINE uint16_t mpu_common_he_sigb_cc_1_cfg_cc_1_length_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_SIGB_CC_1_CFG_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000007FF)) >> 0);
}
__INLINE void mpu_common_he_sigb_cc_1_cfg_cc_1_length_setf(uint16_t cc1length)
{
	ASSERT_ERR((((uint32_t)cc1length << 0) & ~((uint32_t)0x000007FF)) == 0);
	REG_PL_WR(MPU_COMMON_HE_SIGB_CC_1_CFG_ADDR, (REG_PL_RD(MPU_COMMON_HE_SIGB_CC_1_CFG_ADDR) & ~((uint32_t)0x000007FF)) | ((uint32_t)cc1length <<0));
}

/**
 * @brief HE_SIGB_CC_2_CFG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28    CC2_CENTER_RU_EXIST       0              
 *    24:12 CC2_PADDING               0x0
 *    10:00 CC2_LENGTH                0x0
 * </pre>
 */
#define MPU_COMMON_HE_SIGB_CC_2_CFG_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000034)
#define MPU_COMMON_HE_SIGB_CC_2_CFG_OFFSET      0x00000034
#define MPU_COMMON_HE_SIGB_CC_2_CFG_INDEX       0x0000000D
#define MPU_COMMON_HE_SIGB_CC_2_CFG_RESET       0x00000000

__INLINE uint32_t  mpu_common_he_sigb_cc_2_cfg_get(void)
{
	return REG_PL_RD(MPU_COMMON_HE_SIGB_CC_2_CFG_ADDR);
}

__INLINE void mpu_common_he_sigb_cc_2_cfg_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_HE_SIGB_CC_2_CFG_ADDR, value);
}

// field definitions
#define MPU_COMMON_HE_SIGB_CC_2_CFG_CC_2_CENTER_RU_EXIST_BIT    ((uint32_t)0x10000000)
#define MPU_COMMON_HE_SIGB_CC_2_CFG_CC_2_CENTER_RU_EXIST_POS    28
#define MPU_COMMON_HE_SIGB_CC_2_CFG_CC_2_PADDING_MASK    ((uint32_t)0x01FFF000)
#define MPU_COMMON_HE_SIGB_CC_2_CFG_CC_2_PADDING_LSB    12
#define MPU_COMMON_HE_SIGB_CC_2_CFG_CC_2_PADDING_WIDTH    ((uint32_t)0x0000000D)
#define MPU_COMMON_HE_SIGB_CC_2_CFG_CC_2_LENGTH_MASK    ((uint32_t)0x000007FF)
#define MPU_COMMON_HE_SIGB_CC_2_CFG_CC_2_LENGTH_LSB    0
#define MPU_COMMON_HE_SIGB_CC_2_CFG_CC_2_LENGTH_WIDTH    ((uint32_t)0x0000000B)

#define MPU_COMMON_HE_SIGB_CC_2_CFG_CC_2_CENTER_RU_EXIST_RST    0x0
#define MPU_COMMON_HE_SIGB_CC_2_CFG_CC_2_PADDING_RST    0x0
#define MPU_COMMON_HE_SIGB_CC_2_CFG_CC_2_LENGTH_RST    0x0

__INLINE void mpu_common_he_sigb_cc_2_cfg_pack(uint8_t cc2_center_ru_exist, uint16_t cc2_padding, uint16_t cc2_length)
{
	ASSERT_ERR((((uint32_t)cc2_center_ru_exist << 28) & ~((uint32_t)0x10000000)) == 0);
	ASSERT_ERR((((uint32_t)cc2_padding << 12) & ~((uint32_t)0x01FFF000)) == 0);
	ASSERT_ERR((((uint32_t)cc2_length << 0) & ~((uint32_t)0x000007FF)) == 0);
	REG_PL_WR(MPU_COMMON_HE_SIGB_CC_2_CFG_ADDR,  ((uint32_t)cc2_center_ru_exist << 28) |((uint32_t)cc2_padding << 12) |((uint32_t)cc2_length << 0));
}

__INLINE void mpu_common_he_sigb_cc_2_cfg_unpack(uint8_t* cc2_center_ru_exist, uint16_t* cc2_padding, uint16_t* cc2_length)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_SIGB_CC_2_CFG_ADDR);

	*cc2_center_ru_exist = (localVal & ((uint32_t)0x10000000)) >>  28;
	*cc2_padding = (localVal & ((uint32_t)0x01FFF000)) >>  12;
	*cc2_length = (localVal & ((uint32_t)0x000007FF)) >>  0;
}

__INLINE uint8_t mpu_common_he_sigb_cc_2_cfg_cc_2_center_ru_exist_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_SIGB_CC_2_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x10000000)) >> 28);
}
__INLINE void mpu_common_he_sigb_cc_2_cfg_cc_2_center_ru_exist_setf(uint8_t cc2centerruexist)
{
	ASSERT_ERR((((uint32_t)cc2centerruexist << 28) & ~((uint32_t)0x10000000)) == 0);
	REG_PL_WR(MPU_COMMON_HE_SIGB_CC_2_CFG_ADDR, (REG_PL_RD(MPU_COMMON_HE_SIGB_CC_2_CFG_ADDR) & ~((uint32_t)0x10000000)) | ((uint32_t)cc2centerruexist <<28));
}
__INLINE uint16_t mpu_common_he_sigb_cc_2_cfg_cc_2_padding_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_SIGB_CC_2_CFG_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x01FFF000)) >> 12);
}
__INLINE void mpu_common_he_sigb_cc_2_cfg_cc_2_padding_setf(uint16_t cc2padding)
{
	ASSERT_ERR((((uint32_t)cc2padding << 12) & ~((uint32_t)0x01FFF000)) == 0);
	REG_PL_WR(MPU_COMMON_HE_SIGB_CC_2_CFG_ADDR, (REG_PL_RD(MPU_COMMON_HE_SIGB_CC_2_CFG_ADDR) & ~((uint32_t)0x01FFF000)) | ((uint32_t)cc2padding <<12));
}
__INLINE uint16_t mpu_common_he_sigb_cc_2_cfg_cc_2_length_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_SIGB_CC_2_CFG_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000007FF)) >> 0);
}
__INLINE void mpu_common_he_sigb_cc_2_cfg_cc_2_length_setf(uint16_t cc2length)
{
	ASSERT_ERR((((uint32_t)cc2length << 0) & ~((uint32_t)0x000007FF)) == 0);
	REG_PL_WR(MPU_COMMON_HE_SIGB_CC_2_CFG_ADDR, (REG_PL_RD(MPU_COMMON_HE_SIGB_CC_2_CFG_ADDR) & ~((uint32_t)0x000007FF)) | ((uint32_t)cc2length <<0));
}

/**
 * @brief HE_SIGB_STAT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    22:20 SIGB_RX_STA_ID_MATCH      0x6
 *    19:16 SIGB_TX_NUM_ACTIVE_USERS  0x0
 *    15:08 TONE_PLAN_VALID           0x0
 *    07    SIGB_RX_CC2_USER_CRC_ERROR 0              
 *    06    SIGB_RX_CC1_USER_CRC_ERROR 0              
 *    05    SIGB_RX_CC2_COMMON_CRC_ERROR 0              
 *    04    SIGB_RX_CC1_COMMON_CRC_ERROR 0              
 *    03    SIGB_TX_CC2_DONE          0              
 *    02    SIGB_TX_CC1_DONE          0              
 *    01    SIGB_GEN_ERROR            0              
 *    00    SIGB_GEN_DONE             0              
 * </pre>
 */
#define MPU_COMMON_HE_SIGB_STAT_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000038)
#define MPU_COMMON_HE_SIGB_STAT_OFFSET      0x00000038
#define MPU_COMMON_HE_SIGB_STAT_INDEX       0x0000000E
#define MPU_COMMON_HE_SIGB_STAT_RESET       0x00600000

__INLINE uint32_t  mpu_common_he_sigb_stat_get(void)
{
	return REG_PL_RD(MPU_COMMON_HE_SIGB_STAT_ADDR);
}

// field definitions
#define MPU_COMMON_HE_SIGB_STAT_SIGB_RX_STA_ID_MATCH_MASK    ((uint32_t)0x00700000)
#define MPU_COMMON_HE_SIGB_STAT_SIGB_RX_STA_ID_MATCH_LSB    20
#define MPU_COMMON_HE_SIGB_STAT_SIGB_RX_STA_ID_MATCH_WIDTH    ((uint32_t)0x00000003)
#define MPU_COMMON_HE_SIGB_STAT_SIGB_TX_NUM_ACTIVE_USERS_MASK    ((uint32_t)0x000F0000)
#define MPU_COMMON_HE_SIGB_STAT_SIGB_TX_NUM_ACTIVE_USERS_LSB    16
#define MPU_COMMON_HE_SIGB_STAT_SIGB_TX_NUM_ACTIVE_USERS_WIDTH    ((uint32_t)0x00000004)
#define MPU_COMMON_HE_SIGB_STAT_TONE_PLAN_VALID_MASK    ((uint32_t)0x0000FF00)
#define MPU_COMMON_HE_SIGB_STAT_TONE_PLAN_VALID_LSB    8
#define MPU_COMMON_HE_SIGB_STAT_TONE_PLAN_VALID_WIDTH    ((uint32_t)0x00000008)
#define MPU_COMMON_HE_SIGB_STAT_SIGB_RX_CC_2_USER_CRC_ERROR_BIT    ((uint32_t)0x00000080)
#define MPU_COMMON_HE_SIGB_STAT_SIGB_RX_CC_2_USER_CRC_ERROR_POS    7
#define MPU_COMMON_HE_SIGB_STAT_SIGB_RX_CC_1_USER_CRC_ERROR_BIT    ((uint32_t)0x00000040)
#define MPU_COMMON_HE_SIGB_STAT_SIGB_RX_CC_1_USER_CRC_ERROR_POS    6
#define MPU_COMMON_HE_SIGB_STAT_SIGB_RX_CC_2_COMMON_CRC_ERROR_BIT    ((uint32_t)0x00000020)
#define MPU_COMMON_HE_SIGB_STAT_SIGB_RX_CC_2_COMMON_CRC_ERROR_POS    5
#define MPU_COMMON_HE_SIGB_STAT_SIGB_RX_CC_1_COMMON_CRC_ERROR_BIT    ((uint32_t)0x00000010)
#define MPU_COMMON_HE_SIGB_STAT_SIGB_RX_CC_1_COMMON_CRC_ERROR_POS    4
#define MPU_COMMON_HE_SIGB_STAT_SIGB_TX_CC_2_DONE_BIT    ((uint32_t)0x00000008)
#define MPU_COMMON_HE_SIGB_STAT_SIGB_TX_CC_2_DONE_POS    3
#define MPU_COMMON_HE_SIGB_STAT_SIGB_TX_CC_1_DONE_BIT    ((uint32_t)0x00000004)
#define MPU_COMMON_HE_SIGB_STAT_SIGB_TX_CC_1_DONE_POS    2
#define MPU_COMMON_HE_SIGB_STAT_SIGB_GEN_ERROR_BIT    ((uint32_t)0x00000002)
#define MPU_COMMON_HE_SIGB_STAT_SIGB_GEN_ERROR_POS    1
#define MPU_COMMON_HE_SIGB_STAT_SIGB_GEN_DONE_BIT    ((uint32_t)0x00000001)
#define MPU_COMMON_HE_SIGB_STAT_SIGB_GEN_DONE_POS    0

#define MPU_COMMON_HE_SIGB_STAT_SIGB_RX_STA_ID_MATCH_RST    0x6
#define MPU_COMMON_HE_SIGB_STAT_SIGB_TX_NUM_ACTIVE_USERS_RST    0x0
#define MPU_COMMON_HE_SIGB_STAT_TONE_PLAN_VALID_RST    0x0
#define MPU_COMMON_HE_SIGB_STAT_SIGB_RX_CC_2_USER_CRC_ERROR_RST    0x0
#define MPU_COMMON_HE_SIGB_STAT_SIGB_RX_CC_1_USER_CRC_ERROR_RST    0x0
#define MPU_COMMON_HE_SIGB_STAT_SIGB_RX_CC_2_COMMON_CRC_ERROR_RST    0x0
#define MPU_COMMON_HE_SIGB_STAT_SIGB_RX_CC_1_COMMON_CRC_ERROR_RST    0x0
#define MPU_COMMON_HE_SIGB_STAT_SIGB_TX_CC_2_DONE_RST    0x0
#define MPU_COMMON_HE_SIGB_STAT_SIGB_TX_CC_1_DONE_RST    0x0
#define MPU_COMMON_HE_SIGB_STAT_SIGB_GEN_ERROR_RST    0x0
#define MPU_COMMON_HE_SIGB_STAT_SIGB_GEN_DONE_RST    0x0

__INLINE void mpu_common_he_sigb_stat_unpack(uint8_t* sigb_rx_sta_id_match, uint8_t* sigb_tx_num_active_users, uint8_t* tone_plan_valid, uint8_t* sigb_rx_cc2_user_crc_error, uint8_t* sigb_rx_cc1_user_crc_error, uint8_t* sigb_rx_cc2_common_crc_error, uint8_t* sigb_rx_cc1_common_crc_error, uint8_t* sigb_tx_cc2_done, uint8_t* sigb_tx_cc1_done, uint8_t* sigb_gen_error, uint8_t* sigb_gen_done)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_SIGB_STAT_ADDR);

	*sigb_rx_sta_id_match = (localVal & ((uint32_t)0x00700000)) >>  20;
	*sigb_tx_num_active_users = (localVal & ((uint32_t)0x000F0000)) >>  16;
	*tone_plan_valid = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*sigb_rx_cc2_user_crc_error = (localVal & ((uint32_t)0x00000080)) >>  7;
	*sigb_rx_cc1_user_crc_error = (localVal & ((uint32_t)0x00000040)) >>  6;
	*sigb_rx_cc2_common_crc_error = (localVal & ((uint32_t)0x00000020)) >>  5;
	*sigb_rx_cc1_common_crc_error = (localVal & ((uint32_t)0x00000010)) >>  4;
	*sigb_tx_cc2_done = (localVal & ((uint32_t)0x00000008)) >>  3;
	*sigb_tx_cc1_done = (localVal & ((uint32_t)0x00000004)) >>  2;
	*sigb_gen_error = (localVal & ((uint32_t)0x00000002)) >>  1;
	*sigb_gen_done = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t mpu_common_he_sigb_stat_sigb_rx_sta_id_match_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_SIGB_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00700000)) >> 20);
}
__INLINE uint8_t mpu_common_he_sigb_stat_sigb_tx_num_active_users_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_SIGB_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000F0000)) >> 16);
}
__INLINE uint8_t mpu_common_he_sigb_stat_tone_plan_valid_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_SIGB_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE uint8_t mpu_common_he_sigb_stat_sigb_rx_cc_2_user_crc_error_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_SIGB_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE uint8_t mpu_common_he_sigb_stat_sigb_rx_cc_1_user_crc_error_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_SIGB_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE uint8_t mpu_common_he_sigb_stat_sigb_rx_cc_2_common_crc_error_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_SIGB_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE uint8_t mpu_common_he_sigb_stat_sigb_rx_cc_1_common_crc_error_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_SIGB_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE uint8_t mpu_common_he_sigb_stat_sigb_tx_cc_2_done_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_SIGB_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE uint8_t mpu_common_he_sigb_stat_sigb_tx_cc_1_done_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_SIGB_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE uint8_t mpu_common_he_sigb_stat_sigb_gen_error_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_SIGB_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t mpu_common_he_sigb_stat_sigb_gen_done_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_SIGB_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief TX_PWR_LEVEL_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 TX4_PWR_LVL               0x0
 *    23:16 TX3_PWR_LVL               0x0
 *    15:08 TX2_PWR_LVL               0x0
 *    07:00 TX1_PWR_LVL               0x0
 * </pre>
 */
#define MPU_COMMON_TX_PWR_LEVEL_1_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x0000003C)
#define MPU_COMMON_TX_PWR_LEVEL_1_OFFSET      0x0000003C
#define MPU_COMMON_TX_PWR_LEVEL_1_INDEX       0x0000000F
#define MPU_COMMON_TX_PWR_LEVEL_1_RESET       0x00000000

__INLINE uint32_t  mpu_common_tx_pwr_level_1_get(void)
{
	return REG_PL_RD(MPU_COMMON_TX_PWR_LEVEL_1_ADDR);
}

__INLINE void mpu_common_tx_pwr_level_1_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_TX_PWR_LEVEL_1_ADDR, value);
}

// field definitions
#define MPU_COMMON_TX_PWR_LEVEL_1_TX_4_PWR_LVL_MASK    ((uint32_t)0xFF000000)
#define MPU_COMMON_TX_PWR_LEVEL_1_TX_4_PWR_LVL_LSB    24
#define MPU_COMMON_TX_PWR_LEVEL_1_TX_4_PWR_LVL_WIDTH    ((uint32_t)0x00000008)
#define MPU_COMMON_TX_PWR_LEVEL_1_TX_3_PWR_LVL_MASK    ((uint32_t)0x00FF0000)
#define MPU_COMMON_TX_PWR_LEVEL_1_TX_3_PWR_LVL_LSB    16
#define MPU_COMMON_TX_PWR_LEVEL_1_TX_3_PWR_LVL_WIDTH    ((uint32_t)0x00000008)
#define MPU_COMMON_TX_PWR_LEVEL_1_TX_2_PWR_LVL_MASK    ((uint32_t)0x0000FF00)
#define MPU_COMMON_TX_PWR_LEVEL_1_TX_2_PWR_LVL_LSB    8
#define MPU_COMMON_TX_PWR_LEVEL_1_TX_2_PWR_LVL_WIDTH    ((uint32_t)0x00000008)
#define MPU_COMMON_TX_PWR_LEVEL_1_TX_1_PWR_LVL_MASK    ((uint32_t)0x000000FF)
#define MPU_COMMON_TX_PWR_LEVEL_1_TX_1_PWR_LVL_LSB    0
#define MPU_COMMON_TX_PWR_LEVEL_1_TX_1_PWR_LVL_WIDTH    ((uint32_t)0x00000008)

#define MPU_COMMON_TX_PWR_LEVEL_1_TX_4_PWR_LVL_RST    0x0
#define MPU_COMMON_TX_PWR_LEVEL_1_TX_3_PWR_LVL_RST    0x0
#define MPU_COMMON_TX_PWR_LEVEL_1_TX_2_PWR_LVL_RST    0x0
#define MPU_COMMON_TX_PWR_LEVEL_1_TX_1_PWR_LVL_RST    0x0

__INLINE void mpu_common_tx_pwr_level_1_pack(uint8_t tx4_pwr_lvl, uint8_t tx3_pwr_lvl, uint8_t tx2_pwr_lvl, uint8_t tx1_pwr_lvl)
{
	ASSERT_ERR((((uint32_t)tx4_pwr_lvl << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)tx3_pwr_lvl << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)tx2_pwr_lvl << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)tx1_pwr_lvl << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MPU_COMMON_TX_PWR_LEVEL_1_ADDR,  ((uint32_t)tx4_pwr_lvl << 24) |((uint32_t)tx3_pwr_lvl << 16) |((uint32_t)tx2_pwr_lvl << 8) |((uint32_t)tx1_pwr_lvl << 0));
}

__INLINE void mpu_common_tx_pwr_level_1_unpack(uint8_t* tx4_pwr_lvl, uint8_t* tx3_pwr_lvl, uint8_t* tx2_pwr_lvl, uint8_t* tx1_pwr_lvl)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TX_PWR_LEVEL_1_ADDR);

	*tx4_pwr_lvl = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*tx3_pwr_lvl = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*tx2_pwr_lvl = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*tx1_pwr_lvl = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t mpu_common_tx_pwr_level_1_tx_4_pwr_lvl_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TX_PWR_LEVEL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void mpu_common_tx_pwr_level_1_tx_4_pwr_lvl_setf(uint8_t tx4pwrlvl)
{
	ASSERT_ERR((((uint32_t)tx4pwrlvl << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(MPU_COMMON_TX_PWR_LEVEL_1_ADDR, (REG_PL_RD(MPU_COMMON_TX_PWR_LEVEL_1_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)tx4pwrlvl <<24));
}
__INLINE uint8_t mpu_common_tx_pwr_level_1_tx_3_pwr_lvl_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TX_PWR_LEVEL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void mpu_common_tx_pwr_level_1_tx_3_pwr_lvl_setf(uint8_t tx3pwrlvl)
{
	ASSERT_ERR((((uint32_t)tx3pwrlvl << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(MPU_COMMON_TX_PWR_LEVEL_1_ADDR, (REG_PL_RD(MPU_COMMON_TX_PWR_LEVEL_1_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)tx3pwrlvl <<16));
}
__INLINE uint8_t mpu_common_tx_pwr_level_1_tx_2_pwr_lvl_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TX_PWR_LEVEL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void mpu_common_tx_pwr_level_1_tx_2_pwr_lvl_setf(uint8_t tx2pwrlvl)
{
	ASSERT_ERR((((uint32_t)tx2pwrlvl << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(MPU_COMMON_TX_PWR_LEVEL_1_ADDR, (REG_PL_RD(MPU_COMMON_TX_PWR_LEVEL_1_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)tx2pwrlvl <<8));
}
__INLINE uint8_t mpu_common_tx_pwr_level_1_tx_1_pwr_lvl_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TX_PWR_LEVEL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void mpu_common_tx_pwr_level_1_tx_1_pwr_lvl_setf(uint8_t tx1pwrlvl)
{
	ASSERT_ERR((((uint32_t)tx1pwrlvl << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MPU_COMMON_TX_PWR_LEVEL_1_ADDR, (REG_PL_RD(MPU_COMMON_TX_PWR_LEVEL_1_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)tx1pwrlvl <<0));
}

/**
 * @brief TX_PWR_LEVEL_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:16 TX_PWR_LVL_NOM            0x0
 *    15:08 TX6_PWR_LVL               0x0
 *    07:00 TX5_PWR_LVL               0x0
 * </pre>
 */
#define MPU_COMMON_TX_PWR_LEVEL_2_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000040)
#define MPU_COMMON_TX_PWR_LEVEL_2_OFFSET      0x00000040
#define MPU_COMMON_TX_PWR_LEVEL_2_INDEX       0x00000010
#define MPU_COMMON_TX_PWR_LEVEL_2_RESET       0x00000000

__INLINE uint32_t  mpu_common_tx_pwr_level_2_get(void)
{
	return REG_PL_RD(MPU_COMMON_TX_PWR_LEVEL_2_ADDR);
}

__INLINE void mpu_common_tx_pwr_level_2_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_TX_PWR_LEVEL_2_ADDR, value);
}

// field definitions
#define MPU_COMMON_TX_PWR_LEVEL_2_TX_PWR_LVL_NOM_MASK    ((uint32_t)0x00FF0000)
#define MPU_COMMON_TX_PWR_LEVEL_2_TX_PWR_LVL_NOM_LSB    16
#define MPU_COMMON_TX_PWR_LEVEL_2_TX_PWR_LVL_NOM_WIDTH    ((uint32_t)0x00000008)
#define MPU_COMMON_TX_PWR_LEVEL_2_TX_6_PWR_LVL_MASK    ((uint32_t)0x0000FF00)
#define MPU_COMMON_TX_PWR_LEVEL_2_TX_6_PWR_LVL_LSB    8
#define MPU_COMMON_TX_PWR_LEVEL_2_TX_6_PWR_LVL_WIDTH    ((uint32_t)0x00000008)
#define MPU_COMMON_TX_PWR_LEVEL_2_TX_5_PWR_LVL_MASK    ((uint32_t)0x000000FF)
#define MPU_COMMON_TX_PWR_LEVEL_2_TX_5_PWR_LVL_LSB    0
#define MPU_COMMON_TX_PWR_LEVEL_2_TX_5_PWR_LVL_WIDTH    ((uint32_t)0x00000008)

#define MPU_COMMON_TX_PWR_LEVEL_2_TX_PWR_LVL_NOM_RST    0x0
#define MPU_COMMON_TX_PWR_LEVEL_2_TX_6_PWR_LVL_RST    0x0
#define MPU_COMMON_TX_PWR_LEVEL_2_TX_5_PWR_LVL_RST    0x0

__INLINE void mpu_common_tx_pwr_level_2_pack(uint8_t tx_pwr_lvl_nom, uint8_t tx6_pwr_lvl, uint8_t tx5_pwr_lvl)
{
	ASSERT_ERR((((uint32_t)tx_pwr_lvl_nom << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)tx6_pwr_lvl << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)tx5_pwr_lvl << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MPU_COMMON_TX_PWR_LEVEL_2_ADDR,  ((uint32_t)tx_pwr_lvl_nom << 16) |((uint32_t)tx6_pwr_lvl << 8) |((uint32_t)tx5_pwr_lvl << 0));
}

__INLINE void mpu_common_tx_pwr_level_2_unpack(uint8_t* tx_pwr_lvl_nom, uint8_t* tx6_pwr_lvl, uint8_t* tx5_pwr_lvl)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TX_PWR_LEVEL_2_ADDR);

	*tx_pwr_lvl_nom = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*tx6_pwr_lvl = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*tx5_pwr_lvl = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t mpu_common_tx_pwr_level_2_tx_pwr_lvl_nom_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TX_PWR_LEVEL_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void mpu_common_tx_pwr_level_2_tx_pwr_lvl_nom_setf(uint8_t txpwrlvlnom)
{
	ASSERT_ERR((((uint32_t)txpwrlvlnom << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(MPU_COMMON_TX_PWR_LEVEL_2_ADDR, (REG_PL_RD(MPU_COMMON_TX_PWR_LEVEL_2_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)txpwrlvlnom <<16));
}
__INLINE uint8_t mpu_common_tx_pwr_level_2_tx_6_pwr_lvl_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TX_PWR_LEVEL_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void mpu_common_tx_pwr_level_2_tx_6_pwr_lvl_setf(uint8_t tx6pwrlvl)
{
	ASSERT_ERR((((uint32_t)tx6pwrlvl << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(MPU_COMMON_TX_PWR_LEVEL_2_ADDR, (REG_PL_RD(MPU_COMMON_TX_PWR_LEVEL_2_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)tx6pwrlvl <<8));
}
__INLINE uint8_t mpu_common_tx_pwr_level_2_tx_5_pwr_lvl_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TX_PWR_LEVEL_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void mpu_common_tx_pwr_level_2_tx_5_pwr_lvl_setf(uint8_t tx5pwrlvl)
{
	ASSERT_ERR((((uint32_t)tx5pwrlvl << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MPU_COMMON_TX_PWR_LEVEL_2_ADDR, (REG_PL_RD(MPU_COMMON_TX_PWR_LEVEL_2_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)tx5pwrlvl <<0));
}

/**
 * @brief HE_CFG_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    04:00 NUM_SIGB_SYMBOLS_OUT      0x0
 * </pre>
 */
#define MPU_COMMON_HE_CFG_3_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000044)
#define MPU_COMMON_HE_CFG_3_OFFSET      0x00000044
#define MPU_COMMON_HE_CFG_3_INDEX       0x00000011
#define MPU_COMMON_HE_CFG_3_RESET       0x00000000

__INLINE uint32_t  mpu_common_he_cfg_3_get(void)
{
	return REG_PL_RD(MPU_COMMON_HE_CFG_3_ADDR);
}

__INLINE void mpu_common_he_cfg_3_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_HE_CFG_3_ADDR, value);
}

// field definitions
#define MPU_COMMON_HE_CFG_3_NUM_SIGB_SYMBOLS_OUT_MASK    ((uint32_t)0x0000001F)
#define MPU_COMMON_HE_CFG_3_NUM_SIGB_SYMBOLS_OUT_LSB    0
#define MPU_COMMON_HE_CFG_3_NUM_SIGB_SYMBOLS_OUT_WIDTH    ((uint32_t)0x00000005)

#define MPU_COMMON_HE_CFG_3_NUM_SIGB_SYMBOLS_OUT_RST    0x0

__INLINE uint8_t mpu_common_he_cfg_3_num_sigb_symbols_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_HE_CFG_3_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void mpu_common_he_cfg_3_num_sigb_symbols_out_setf(uint8_t numsigbsymbolsout)
{
	ASSERT_ERR((((uint32_t)numsigbsymbolsout << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(MPU_COMMON_HE_CFG_3_ADDR, (uint32_t)numsigbsymbolsout << 0);
}

/**
 * @brief FORCE_CCA_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    02    FORCE_CCA_OFF             0              
 *    01    FORCE_CCA_CONFIG_ALL      0              
 *    00    FORCE_CCA_CONFIG_ON       0              
 * </pre>
 */
#define MPU_COMMON_FORCE_CCA_CTRL_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000048)
#define MPU_COMMON_FORCE_CCA_CTRL_OFFSET      0x00000048
#define MPU_COMMON_FORCE_CCA_CTRL_INDEX       0x00000012
#define MPU_COMMON_FORCE_CCA_CTRL_RESET       0x00000000

__INLINE uint32_t  mpu_common_force_cca_ctrl_get(void)
{
	return REG_PL_RD(MPU_COMMON_FORCE_CCA_CTRL_ADDR);
}

__INLINE void mpu_common_force_cca_ctrl_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_FORCE_CCA_CTRL_ADDR, value);
}

// field definitions
#define MPU_COMMON_FORCE_CCA_CTRL_FORCE_CCA_OFF_BIT    ((uint32_t)0x00000004)
#define MPU_COMMON_FORCE_CCA_CTRL_FORCE_CCA_OFF_POS    2
#define MPU_COMMON_FORCE_CCA_CTRL_FORCE_CCA_CONFIG_ALL_BIT    ((uint32_t)0x00000002)
#define MPU_COMMON_FORCE_CCA_CTRL_FORCE_CCA_CONFIG_ALL_POS    1
#define MPU_COMMON_FORCE_CCA_CTRL_FORCE_CCA_CONFIG_ON_BIT    ((uint32_t)0x00000001)
#define MPU_COMMON_FORCE_CCA_CTRL_FORCE_CCA_CONFIG_ON_POS    0

#define MPU_COMMON_FORCE_CCA_CTRL_FORCE_CCA_OFF_RST    0x0
#define MPU_COMMON_FORCE_CCA_CTRL_FORCE_CCA_CONFIG_ALL_RST    0x0
#define MPU_COMMON_FORCE_CCA_CTRL_FORCE_CCA_CONFIG_ON_RST    0x0

__INLINE void mpu_common_force_cca_ctrl_pack(uint8_t force_cca_off, uint8_t force_cca_config_all, uint8_t force_cca_config_on)
{
	ASSERT_ERR((((uint32_t)force_cca_off << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)force_cca_config_all << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)force_cca_config_on << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MPU_COMMON_FORCE_CCA_CTRL_ADDR,  ((uint32_t)force_cca_off << 2) |((uint32_t)force_cca_config_all << 1) |((uint32_t)force_cca_config_on << 0));
}

__INLINE void mpu_common_force_cca_ctrl_unpack(uint8_t* force_cca_off, uint8_t* force_cca_config_all, uint8_t* force_cca_config_on)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_FORCE_CCA_CTRL_ADDR);

	*force_cca_off = (localVal & ((uint32_t)0x00000004)) >>  2;
	*force_cca_config_all = (localVal & ((uint32_t)0x00000002)) >>  1;
	*force_cca_config_on = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t mpu_common_force_cca_ctrl_force_cca_off_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_FORCE_CCA_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void mpu_common_force_cca_ctrl_force_cca_off_setf(uint8_t forceccaoff)
{
	ASSERT_ERR((((uint32_t)forceccaoff << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(MPU_COMMON_FORCE_CCA_CTRL_ADDR, (REG_PL_RD(MPU_COMMON_FORCE_CCA_CTRL_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)forceccaoff <<2));
}
__INLINE uint8_t mpu_common_force_cca_ctrl_force_cca_config_all_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_FORCE_CCA_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void mpu_common_force_cca_ctrl_force_cca_config_all_setf(uint8_t forceccaconfigall)
{
	ASSERT_ERR((((uint32_t)forceccaconfigall << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(MPU_COMMON_FORCE_CCA_CTRL_ADDR, (REG_PL_RD(MPU_COMMON_FORCE_CCA_CTRL_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)forceccaconfigall <<1));
}
__INLINE uint8_t mpu_common_force_cca_ctrl_force_cca_config_on_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_FORCE_CCA_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void mpu_common_force_cca_ctrl_force_cca_config_on_setf(uint8_t forceccaconfigon)
{
	ASSERT_ERR((((uint32_t)forceccaconfigon << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MPU_COMMON_FORCE_CCA_CTRL_ADDR, (REG_PL_RD(MPU_COMMON_FORCE_CCA_CTRL_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)forceccaconfigon <<0));
}

/**
 * @brief MAC_CTRL_INFO register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:16 RATE_CTRL_INFO            0x0
 *    07:02 FRAME_TYPE                0x0
 * </pre>
 */
#define MPU_COMMON_MAC_CTRL_INFO_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x0000004C)
#define MPU_COMMON_MAC_CTRL_INFO_OFFSET      0x0000004C
#define MPU_COMMON_MAC_CTRL_INFO_INDEX       0x00000013
#define MPU_COMMON_MAC_CTRL_INFO_RESET       0x00000000

__INLINE uint32_t  mpu_common_mac_ctrl_info_get(void)
{
	return REG_PL_RD(MPU_COMMON_MAC_CTRL_INFO_ADDR);
}

__INLINE void mpu_common_mac_ctrl_info_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_MAC_CTRL_INFO_ADDR, value);
}

// field definitions
#define MPU_COMMON_MAC_CTRL_INFO_RATE_CTRL_INFO_MASK    ((uint32_t)0x00FF0000)
#define MPU_COMMON_MAC_CTRL_INFO_RATE_CTRL_INFO_LSB    16
#define MPU_COMMON_MAC_CTRL_INFO_RATE_CTRL_INFO_WIDTH    ((uint32_t)0x00000008)
#define MPU_COMMON_MAC_CTRL_INFO_FRAME_TYPE_MASK    ((uint32_t)0x000000FC)
#define MPU_COMMON_MAC_CTRL_INFO_FRAME_TYPE_LSB    2
#define MPU_COMMON_MAC_CTRL_INFO_FRAME_TYPE_WIDTH    ((uint32_t)0x00000006)

#define MPU_COMMON_MAC_CTRL_INFO_RATE_CTRL_INFO_RST    0x0
#define MPU_COMMON_MAC_CTRL_INFO_FRAME_TYPE_RST    0x0

__INLINE void mpu_common_mac_ctrl_info_pack(uint8_t rate_ctrl_info, uint8_t frame_type)
{
	ASSERT_ERR((((uint32_t)rate_ctrl_info << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)frame_type << 2) & ~((uint32_t)0x000000FC)) == 0);
	REG_PL_WR(MPU_COMMON_MAC_CTRL_INFO_ADDR,  ((uint32_t)rate_ctrl_info << 16) |((uint32_t)frame_type << 2));
}

__INLINE void mpu_common_mac_ctrl_info_unpack(uint8_t* rate_ctrl_info, uint8_t* frame_type)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_MAC_CTRL_INFO_ADDR);

	*rate_ctrl_info = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*frame_type = (localVal & ((uint32_t)0x000000FC)) >>  2;
}

__INLINE uint8_t mpu_common_mac_ctrl_info_rate_ctrl_info_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_MAC_CTRL_INFO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void mpu_common_mac_ctrl_info_rate_ctrl_info_setf(uint8_t ratectrlinfo)
{
	ASSERT_ERR((((uint32_t)ratectrlinfo << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(MPU_COMMON_MAC_CTRL_INFO_ADDR, (REG_PL_RD(MPU_COMMON_MAC_CTRL_INFO_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)ratectrlinfo <<16));
}
__INLINE uint8_t mpu_common_mac_ctrl_info_frame_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_MAC_CTRL_INFO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FC)) >> 2);
}
__INLINE void mpu_common_mac_ctrl_info_frame_type_setf(uint8_t frametype)
{
	ASSERT_ERR((((uint32_t)frametype << 2) & ~((uint32_t)0x000000FC)) == 0);
	REG_PL_WR(MPU_COMMON_MAC_CTRL_INFO_ADDR, (REG_PL_RD(MPU_COMMON_MAC_CTRL_INFO_ADDR) & ~((uint32_t)0x000000FC)) | ((uint32_t)frametype <<2));
}

/**
 * @brief PADDING_DATA register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PADDING_DATA              0x0
 * </pre>
 */
#define MPU_COMMON_PADDING_DATA_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000050)
#define MPU_COMMON_PADDING_DATA_OFFSET      0x00000050
#define MPU_COMMON_PADDING_DATA_INDEX       0x00000014
#define MPU_COMMON_PADDING_DATA_RESET       0x00000000

__INLINE uint32_t  mpu_common_padding_data_get(void)
{
	return REG_PL_RD(MPU_COMMON_PADDING_DATA_ADDR);
}

__INLINE void mpu_common_padding_data_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_PADDING_DATA_ADDR, value);
}

// field definitions
#define MPU_COMMON_PADDING_DATA_PADDING_DATA_MASK    ((uint32_t)0xFFFFFFFF)
#define MPU_COMMON_PADDING_DATA_PADDING_DATA_LSB    0
#define MPU_COMMON_PADDING_DATA_PADDING_DATA_WIDTH    ((uint32_t)0x00000020)

#define MPU_COMMON_PADDING_DATA_PADDING_DATA_RST    0x0

__INLINE uint32_t mpu_common_padding_data_padding_data_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_PADDING_DATA_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void mpu_common_padding_data_padding_data_setf(uint32_t paddingdata)
{
	ASSERT_ERR((((uint32_t)paddingdata << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MPU_COMMON_PADDING_DATA_ADDR, (uint32_t)paddingdata << 0);
}

/**
 * @brief RAW_SIG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28    ILLEGAL_RATE_ERROR        0              
 *    27    MIN_LENGTH_ERROR          0              
 *    26    RESERVED_ERROR            0              
 *    25    TAIL_ERROR                0              
 *    24    PARITY_ERROR              0              
 *    17:00 L_SIG                     0x0
 * </pre>
 */
#define MPU_COMMON_RAW_SIG_1_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000054)
#define MPU_COMMON_RAW_SIG_1_OFFSET      0x00000054
#define MPU_COMMON_RAW_SIG_1_INDEX       0x00000015
#define MPU_COMMON_RAW_SIG_1_RESET       0x00000000

__INLINE uint32_t  mpu_common_raw_sig_1_get(void)
{
	return REG_PL_RD(MPU_COMMON_RAW_SIG_1_ADDR);
}

// field definitions
#define MPU_COMMON_RAW_SIG_1_ILLEGAL_RATE_ERROR_BIT    ((uint32_t)0x10000000)
#define MPU_COMMON_RAW_SIG_1_ILLEGAL_RATE_ERROR_POS    28
#define MPU_COMMON_RAW_SIG_1_MIN_LENGTH_ERROR_BIT    ((uint32_t)0x08000000)
#define MPU_COMMON_RAW_SIG_1_MIN_LENGTH_ERROR_POS    27
#define MPU_COMMON_RAW_SIG_1_RESERVED_ERROR_BIT    ((uint32_t)0x04000000)
#define MPU_COMMON_RAW_SIG_1_RESERVED_ERROR_POS    26
#define MPU_COMMON_RAW_SIG_1_TAIL_ERROR_BIT    ((uint32_t)0x02000000)
#define MPU_COMMON_RAW_SIG_1_TAIL_ERROR_POS    25
#define MPU_COMMON_RAW_SIG_1_PARITY_ERROR_BIT    ((uint32_t)0x01000000)
#define MPU_COMMON_RAW_SIG_1_PARITY_ERROR_POS    24
#define MPU_COMMON_RAW_SIG_1_L_SIG_MASK     ((uint32_t)0x0003FFFF)
#define MPU_COMMON_RAW_SIG_1_L_SIG_LSB      0
#define MPU_COMMON_RAW_SIG_1_L_SIG_WIDTH    ((uint32_t)0x00000012)

#define MPU_COMMON_RAW_SIG_1_ILLEGAL_RATE_ERROR_RST    0x0
#define MPU_COMMON_RAW_SIG_1_MIN_LENGTH_ERROR_RST    0x0
#define MPU_COMMON_RAW_SIG_1_RESERVED_ERROR_RST    0x0
#define MPU_COMMON_RAW_SIG_1_TAIL_ERROR_RST    0x0
#define MPU_COMMON_RAW_SIG_1_PARITY_ERROR_RST    0x0
#define MPU_COMMON_RAW_SIG_1_L_SIG_RST      0x0

__INLINE void mpu_common_raw_sig_1_unpack(uint8_t* illegal_rate_error, uint8_t* min_length_error, uint8_t* reserved_error, uint8_t* tail_error, uint8_t* parity_error, uint32_t* l_sig)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_RAW_SIG_1_ADDR);

	*illegal_rate_error = (localVal & ((uint32_t)0x10000000)) >>  28;
	*min_length_error = (localVal & ((uint32_t)0x08000000)) >>  27;
	*reserved_error = (localVal & ((uint32_t)0x04000000)) >>  26;
	*tail_error = (localVal & ((uint32_t)0x02000000)) >>  25;
	*parity_error = (localVal & ((uint32_t)0x01000000)) >>  24;
	*l_sig = (localVal & ((uint32_t)0x0003FFFF)) >>  0;
}

__INLINE uint8_t mpu_common_raw_sig_1_illegal_rate_error_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_RAW_SIG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x10000000)) >> 28);
}
__INLINE uint8_t mpu_common_raw_sig_1_min_length_error_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_RAW_SIG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x08000000)) >> 27);
}
__INLINE uint8_t mpu_common_raw_sig_1_reserved_error_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_RAW_SIG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x04000000)) >> 26);
}
__INLINE uint8_t mpu_common_raw_sig_1_tail_error_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_RAW_SIG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x02000000)) >> 25);
}
__INLINE uint8_t mpu_common_raw_sig_1_parity_error_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_RAW_SIG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01000000)) >> 24);
}
__INLINE uint32_t mpu_common_raw_sig_1_l_sig_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_RAW_SIG_1_ADDR);
	return (uint32_t)((localVal & ((uint32_t)0x0003FFFF)) >> 0);
}

/**
 * @brief RAW_SIG_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 A_SIG_LSB                 0x0
 * </pre>
 */
#define MPU_COMMON_RAW_SIG_2_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000058)
#define MPU_COMMON_RAW_SIG_2_OFFSET      0x00000058
#define MPU_COMMON_RAW_SIG_2_INDEX       0x00000016
#define MPU_COMMON_RAW_SIG_2_RESET       0x00000000

__INLINE uint32_t  mpu_common_raw_sig_2_get(void)
{
	return REG_PL_RD(MPU_COMMON_RAW_SIG_2_ADDR);
}

// field definitions
#define MPU_COMMON_RAW_SIG_2_A_SIG_LSB_MASK    ((uint32_t)0xFFFFFFFF)
#define MPU_COMMON_RAW_SIG_2_A_SIG_LSB_LSB    0
#define MPU_COMMON_RAW_SIG_2_A_SIG_LSB_WIDTH    ((uint32_t)0x00000020)

#define MPU_COMMON_RAW_SIG_2_A_SIG_LSB_RST    0x0

__INLINE uint32_t mpu_common_raw_sig_2_a_sig_lsb_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_RAW_SIG_2_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RAW_SIG_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    19:00 A_SIG_MSB                 0x0
 * </pre>
 */
#define MPU_COMMON_RAW_SIG_3_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x0000005C)
#define MPU_COMMON_RAW_SIG_3_OFFSET      0x0000005C
#define MPU_COMMON_RAW_SIG_3_INDEX       0x00000017
#define MPU_COMMON_RAW_SIG_3_RESET       0x00000000

__INLINE uint32_t  mpu_common_raw_sig_3_get(void)
{
	return REG_PL_RD(MPU_COMMON_RAW_SIG_3_ADDR);
}

// field definitions
#define MPU_COMMON_RAW_SIG_3_A_SIG_MSB_MASK    ((uint32_t)0x000FFFFF)
#define MPU_COMMON_RAW_SIG_3_A_SIG_MSB_LSB    0
#define MPU_COMMON_RAW_SIG_3_A_SIG_MSB_WIDTH    ((uint32_t)0x00000014)

#define MPU_COMMON_RAW_SIG_3_A_SIG_MSB_RST    0x0

__INLINE uint32_t mpu_common_raw_sig_3_a_sig_msb_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_RAW_SIG_3_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RXVECT_1_RESERVED register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    07:00 FUTURE_1                  0x0
 * </pre>
 */
#define MPU_COMMON_RXVECT_1_RESERVED_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000060)
#define MPU_COMMON_RXVECT_1_RESERVED_OFFSET      0x00000060
#define MPU_COMMON_RXVECT_1_RESERVED_INDEX       0x00000018
#define MPU_COMMON_RXVECT_1_RESERVED_RESET       0x00000000

__INLINE uint32_t  mpu_common_rxvect_1_reserved_get(void)
{
	return REG_PL_RD(MPU_COMMON_RXVECT_1_RESERVED_ADDR);
}

__INLINE void mpu_common_rxvect_1_reserved_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_RXVECT_1_RESERVED_ADDR, value);
}

// field definitions
#define MPU_COMMON_RXVECT_1_RESERVED_FUTURE_1_MASK    ((uint32_t)0x000000FF)
#define MPU_COMMON_RXVECT_1_RESERVED_FUTURE_1_LSB    0
#define MPU_COMMON_RXVECT_1_RESERVED_FUTURE_1_WIDTH    ((uint32_t)0x00000008)

#define MPU_COMMON_RXVECT_1_RESERVED_FUTURE_1_RST    0x0

__INLINE uint8_t mpu_common_rxvect_1_reserved_future_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_RXVECT_1_RESERVED_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void mpu_common_rxvect_1_reserved_future_1_setf(uint8_t future1)
{
	ASSERT_ERR((((uint32_t)future1 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MPU_COMMON_RXVECT_1_RESERVED_ADDR, (uint32_t)future1 << 0);
}

/**
 * @brief RXVECT_2_RESERVED register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:16 RXVECT2_BYTE7             0x0
 *    15:08 RXVECT2_BYTE6             0x0
 *    07:00 RXVECT2_BYTE5             0x0
 * </pre>
 */
#define MPU_COMMON_RXVECT_2_RESERVED_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000068)
#define MPU_COMMON_RXVECT_2_RESERVED_OFFSET      0x00000068
#define MPU_COMMON_RXVECT_2_RESERVED_INDEX       0x0000001A
#define MPU_COMMON_RXVECT_2_RESERVED_RESET       0x00000000

__INLINE uint32_t  mpu_common_rxvect_2_reserved_get(void)
{
	return REG_PL_RD(MPU_COMMON_RXVECT_2_RESERVED_ADDR);
}

__INLINE void mpu_common_rxvect_2_reserved_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_RXVECT_2_RESERVED_ADDR, value);
}

// field definitions
#define MPU_COMMON_RXVECT_2_RESERVED_RXVECT_2_BYTE_7_MASK    ((uint32_t)0x00FF0000)
#define MPU_COMMON_RXVECT_2_RESERVED_RXVECT_2_BYTE_7_LSB    16
#define MPU_COMMON_RXVECT_2_RESERVED_RXVECT_2_BYTE_7_WIDTH    ((uint32_t)0x00000008)
#define MPU_COMMON_RXVECT_2_RESERVED_RXVECT_2_BYTE_6_MASK    ((uint32_t)0x0000FF00)
#define MPU_COMMON_RXVECT_2_RESERVED_RXVECT_2_BYTE_6_LSB    8
#define MPU_COMMON_RXVECT_2_RESERVED_RXVECT_2_BYTE_6_WIDTH    ((uint32_t)0x00000008)
#define MPU_COMMON_RXVECT_2_RESERVED_RXVECT_2_BYTE_5_MASK    ((uint32_t)0x000000FF)
#define MPU_COMMON_RXVECT_2_RESERVED_RXVECT_2_BYTE_5_LSB    0
#define MPU_COMMON_RXVECT_2_RESERVED_RXVECT_2_BYTE_5_WIDTH    ((uint32_t)0x00000008)

#define MPU_COMMON_RXVECT_2_RESERVED_RXVECT_2_BYTE_7_RST    0x0
#define MPU_COMMON_RXVECT_2_RESERVED_RXVECT_2_BYTE_6_RST    0x0
#define MPU_COMMON_RXVECT_2_RESERVED_RXVECT_2_BYTE_5_RST    0x0

__INLINE void mpu_common_rxvect_2_reserved_pack(uint8_t rxvect2_byte7, uint8_t rxvect2_byte6, uint8_t rxvect2_byte5)
{
	ASSERT_ERR((((uint32_t)rxvect2_byte7 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rxvect2_byte6 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)rxvect2_byte5 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MPU_COMMON_RXVECT_2_RESERVED_ADDR,  ((uint32_t)rxvect2_byte7 << 16) |((uint32_t)rxvect2_byte6 << 8) |((uint32_t)rxvect2_byte5 << 0));
}

__INLINE void mpu_common_rxvect_2_reserved_unpack(uint8_t* rxvect2_byte7, uint8_t* rxvect2_byte6, uint8_t* rxvect2_byte5)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_RXVECT_2_RESERVED_ADDR);

	*rxvect2_byte7 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rxvect2_byte6 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*rxvect2_byte5 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t mpu_common_rxvect_2_reserved_rxvect_2_byte_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_RXVECT_2_RESERVED_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void mpu_common_rxvect_2_reserved_rxvect_2_byte_7_setf(uint8_t rxvect2byte7)
{
	ASSERT_ERR((((uint32_t)rxvect2byte7 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(MPU_COMMON_RXVECT_2_RESERVED_ADDR, (REG_PL_RD(MPU_COMMON_RXVECT_2_RESERVED_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rxvect2byte7 <<16));
}
__INLINE uint8_t mpu_common_rxvect_2_reserved_rxvect_2_byte_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_RXVECT_2_RESERVED_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void mpu_common_rxvect_2_reserved_rxvect_2_byte_6_setf(uint8_t rxvect2byte6)
{
	ASSERT_ERR((((uint32_t)rxvect2byte6 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(MPU_COMMON_RXVECT_2_RESERVED_ADDR, (REG_PL_RD(MPU_COMMON_RXVECT_2_RESERVED_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)rxvect2byte6 <<8));
}
__INLINE uint8_t mpu_common_rxvect_2_reserved_rxvect_2_byte_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_RXVECT_2_RESERVED_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void mpu_common_rxvect_2_reserved_rxvect_2_byte_5_setf(uint8_t rxvect2byte5)
{
	ASSERT_ERR((((uint32_t)rxvect2byte5 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MPU_COMMON_RXVECT_2_RESERVED_ADDR, (REG_PL_RD(MPU_COMMON_RXVECT_2_RESERVED_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)rxvect2byte5 <<0));
}

/**
 * @brief TX_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26    SIG_EN_RAW                0              
 *    25    TX_DONE                   0              
 *    24    TX_ON_GOING               0              
 *    23    USER_7_TX_DATA_DONE       0              
 *    22    USER_6_TX_DATA_DONE       0              
 *    21    USER_5_TX_DATA_DONE       0              
 *    20    USER_4_TX_DATA_DONE       0              
 *    19    USER_3_TX_DATA_DONE       0              
 *    18    USER_2_TX_DATA_DONE       0              
 *    17    USER_1_TX_DATA_DONE       0              
 *    16    USER_0_TX_DATA_DONE       0              
 *    15    USER_7_TX_VEC2            0              
 *    14    USER_6_TX_VEC2            0              
 *    13    USER_5_TX_VEC2            0              
 *    12    USER_4_TX_VEC2            0              
 *    11    USER_3_TX_VEC2            0              
 *    10    USER_2_TX_VEC2            0              
 *    09    USER_1_TX_VEC2            0              
 *    08    USER_0_TX_VEC2            0              
 *    07    USER_7_TX_REQ_RAW         0              
 *    06    USER_6_TX_REQ_RAW         0              
 *    05    USER_5_TX_REQ_RAW         0              
 *    04    USER_4_TX_REQ_RAW         0              
 *    03    USER_3_TX_REQ_RAW         0              
 *    02    USER_2_TX_REQ_RAW         0              
 *    01    USER_1_TX_REQ_RAW         0              
 *    00    USER_0_TX_REQ_RAW         0              
 * </pre>
 */
#define MPU_COMMON_TX_STATUS_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x0000006C)
#define MPU_COMMON_TX_STATUS_OFFSET      0x0000006C
#define MPU_COMMON_TX_STATUS_INDEX       0x0000001B
#define MPU_COMMON_TX_STATUS_RESET       0x00000000

__INLINE uint32_t  mpu_common_tx_status_get(void)
{
	return REG_PL_RD(MPU_COMMON_TX_STATUS_ADDR);
}

// field definitions
#define MPU_COMMON_TX_STATUS_SIG_EN_RAW_BIT    ((uint32_t)0x04000000)
#define MPU_COMMON_TX_STATUS_SIG_EN_RAW_POS    26
#define MPU_COMMON_TX_STATUS_TX_DONE_BIT    ((uint32_t)0x02000000)
#define MPU_COMMON_TX_STATUS_TX_DONE_POS    25
#define MPU_COMMON_TX_STATUS_TX_ON_GOING_BIT    ((uint32_t)0x01000000)
#define MPU_COMMON_TX_STATUS_TX_ON_GOING_POS    24
#define MPU_COMMON_TX_STATUS_USER_7_TX_DATA_DONE_BIT    ((uint32_t)0x00800000)
#define MPU_COMMON_TX_STATUS_USER_7_TX_DATA_DONE_POS    23
#define MPU_COMMON_TX_STATUS_USER_6_TX_DATA_DONE_BIT    ((uint32_t)0x00400000)
#define MPU_COMMON_TX_STATUS_USER_6_TX_DATA_DONE_POS    22
#define MPU_COMMON_TX_STATUS_USER_5_TX_DATA_DONE_BIT    ((uint32_t)0x00200000)
#define MPU_COMMON_TX_STATUS_USER_5_TX_DATA_DONE_POS    21
#define MPU_COMMON_TX_STATUS_USER_4_TX_DATA_DONE_BIT    ((uint32_t)0x00100000)
#define MPU_COMMON_TX_STATUS_USER_4_TX_DATA_DONE_POS    20
#define MPU_COMMON_TX_STATUS_USER_3_TX_DATA_DONE_BIT    ((uint32_t)0x00080000)
#define MPU_COMMON_TX_STATUS_USER_3_TX_DATA_DONE_POS    19
#define MPU_COMMON_TX_STATUS_USER_2_TX_DATA_DONE_BIT    ((uint32_t)0x00040000)
#define MPU_COMMON_TX_STATUS_USER_2_TX_DATA_DONE_POS    18
#define MPU_COMMON_TX_STATUS_USER_1_TX_DATA_DONE_BIT    ((uint32_t)0x00020000)
#define MPU_COMMON_TX_STATUS_USER_1_TX_DATA_DONE_POS    17
#define MPU_COMMON_TX_STATUS_USER_0_TX_DATA_DONE_BIT    ((uint32_t)0x00010000)
#define MPU_COMMON_TX_STATUS_USER_0_TX_DATA_DONE_POS    16
#define MPU_COMMON_TX_STATUS_USER_7_TX_VEC_2_BIT    ((uint32_t)0x00008000)
#define MPU_COMMON_TX_STATUS_USER_7_TX_VEC_2_POS    15
#define MPU_COMMON_TX_STATUS_USER_6_TX_VEC_2_BIT    ((uint32_t)0x00004000)
#define MPU_COMMON_TX_STATUS_USER_6_TX_VEC_2_POS    14
#define MPU_COMMON_TX_STATUS_USER_5_TX_VEC_2_BIT    ((uint32_t)0x00002000)
#define MPU_COMMON_TX_STATUS_USER_5_TX_VEC_2_POS    13
#define MPU_COMMON_TX_STATUS_USER_4_TX_VEC_2_BIT    ((uint32_t)0x00001000)
#define MPU_COMMON_TX_STATUS_USER_4_TX_VEC_2_POS    12
#define MPU_COMMON_TX_STATUS_USER_3_TX_VEC_2_BIT    ((uint32_t)0x00000800)
#define MPU_COMMON_TX_STATUS_USER_3_TX_VEC_2_POS    11
#define MPU_COMMON_TX_STATUS_USER_2_TX_VEC_2_BIT    ((uint32_t)0x00000400)
#define MPU_COMMON_TX_STATUS_USER_2_TX_VEC_2_POS    10
#define MPU_COMMON_TX_STATUS_USER_1_TX_VEC_2_BIT    ((uint32_t)0x00000200)
#define MPU_COMMON_TX_STATUS_USER_1_TX_VEC_2_POS    9
#define MPU_COMMON_TX_STATUS_USER_0_TX_VEC_2_BIT    ((uint32_t)0x00000100)
#define MPU_COMMON_TX_STATUS_USER_0_TX_VEC_2_POS    8
#define MPU_COMMON_TX_STATUS_USER_7_TX_REQ_RAW_BIT    ((uint32_t)0x00000080)
#define MPU_COMMON_TX_STATUS_USER_7_TX_REQ_RAW_POS    7
#define MPU_COMMON_TX_STATUS_USER_6_TX_REQ_RAW_BIT    ((uint32_t)0x00000040)
#define MPU_COMMON_TX_STATUS_USER_6_TX_REQ_RAW_POS    6
#define MPU_COMMON_TX_STATUS_USER_5_TX_REQ_RAW_BIT    ((uint32_t)0x00000020)
#define MPU_COMMON_TX_STATUS_USER_5_TX_REQ_RAW_POS    5
#define MPU_COMMON_TX_STATUS_USER_4_TX_REQ_RAW_BIT    ((uint32_t)0x00000010)
#define MPU_COMMON_TX_STATUS_USER_4_TX_REQ_RAW_POS    4
#define MPU_COMMON_TX_STATUS_USER_3_TX_REQ_RAW_BIT    ((uint32_t)0x00000008)
#define MPU_COMMON_TX_STATUS_USER_3_TX_REQ_RAW_POS    3
#define MPU_COMMON_TX_STATUS_USER_2_TX_REQ_RAW_BIT    ((uint32_t)0x00000004)
#define MPU_COMMON_TX_STATUS_USER_2_TX_REQ_RAW_POS    2
#define MPU_COMMON_TX_STATUS_USER_1_TX_REQ_RAW_BIT    ((uint32_t)0x00000002)
#define MPU_COMMON_TX_STATUS_USER_1_TX_REQ_RAW_POS    1
#define MPU_COMMON_TX_STATUS_USER_0_TX_REQ_RAW_BIT    ((uint32_t)0x00000001)
#define MPU_COMMON_TX_STATUS_USER_0_TX_REQ_RAW_POS    0

#define MPU_COMMON_TX_STATUS_SIG_EN_RAW_RST    0x0
#define MPU_COMMON_TX_STATUS_TX_DONE_RST    0x0
#define MPU_COMMON_TX_STATUS_TX_ON_GOING_RST    0x0
#define MPU_COMMON_TX_STATUS_USER_7_TX_DATA_DONE_RST    0x0
#define MPU_COMMON_TX_STATUS_USER_6_TX_DATA_DONE_RST    0x0
#define MPU_COMMON_TX_STATUS_USER_5_TX_DATA_DONE_RST    0x0
#define MPU_COMMON_TX_STATUS_USER_4_TX_DATA_DONE_RST    0x0
#define MPU_COMMON_TX_STATUS_USER_3_TX_DATA_DONE_RST    0x0
#define MPU_COMMON_TX_STATUS_USER_2_TX_DATA_DONE_RST    0x0
#define MPU_COMMON_TX_STATUS_USER_1_TX_DATA_DONE_RST    0x0
#define MPU_COMMON_TX_STATUS_USER_0_TX_DATA_DONE_RST    0x0
#define MPU_COMMON_TX_STATUS_USER_7_TX_VEC_2_RST    0x0
#define MPU_COMMON_TX_STATUS_USER_6_TX_VEC_2_RST    0x0
#define MPU_COMMON_TX_STATUS_USER_5_TX_VEC_2_RST    0x0
#define MPU_COMMON_TX_STATUS_USER_4_TX_VEC_2_RST    0x0
#define MPU_COMMON_TX_STATUS_USER_3_TX_VEC_2_RST    0x0
#define MPU_COMMON_TX_STATUS_USER_2_TX_VEC_2_RST    0x0
#define MPU_COMMON_TX_STATUS_USER_1_TX_VEC_2_RST    0x0
#define MPU_COMMON_TX_STATUS_USER_0_TX_VEC_2_RST    0x0
#define MPU_COMMON_TX_STATUS_USER_7_TX_REQ_RAW_RST    0x0
#define MPU_COMMON_TX_STATUS_USER_6_TX_REQ_RAW_RST    0x0
#define MPU_COMMON_TX_STATUS_USER_5_TX_REQ_RAW_RST    0x0
#define MPU_COMMON_TX_STATUS_USER_4_TX_REQ_RAW_RST    0x0
#define MPU_COMMON_TX_STATUS_USER_3_TX_REQ_RAW_RST    0x0
#define MPU_COMMON_TX_STATUS_USER_2_TX_REQ_RAW_RST    0x0
#define MPU_COMMON_TX_STATUS_USER_1_TX_REQ_RAW_RST    0x0
#define MPU_COMMON_TX_STATUS_USER_0_TX_REQ_RAW_RST    0x0

__INLINE void mpu_common_tx_status_unpack(uint8_t* sig_en_raw, uint8_t* tx_done, uint8_t* tx_on_going, uint8_t* user_7_tx_data_done, uint8_t* user_6_tx_data_done, uint8_t* user_5_tx_data_done, uint8_t* user_4_tx_data_done, uint8_t* user_3_tx_data_done, uint8_t* user_2_tx_data_done, uint8_t* user_1_tx_data_done, uint8_t* user_0_tx_data_done, uint8_t* user_7_tx_vec2, uint8_t* user_6_tx_vec2, uint8_t* user_5_tx_vec2, uint8_t* user_4_tx_vec2, uint8_t* user_3_tx_vec2, uint8_t* user_2_tx_vec2, uint8_t* user_1_tx_vec2, uint8_t* user_0_tx_vec2, uint8_t* user_7_tx_req_raw, uint8_t* user_6_tx_req_raw, uint8_t* user_5_tx_req_raw, uint8_t* user_4_tx_req_raw, uint8_t* user_3_tx_req_raw, uint8_t* user_2_tx_req_raw, uint8_t* user_1_tx_req_raw, uint8_t* user_0_tx_req_raw)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TX_STATUS_ADDR);

	*sig_en_raw = (localVal & ((uint32_t)0x04000000)) >>  26;
	*tx_done = (localVal & ((uint32_t)0x02000000)) >>  25;
	*tx_on_going = (localVal & ((uint32_t)0x01000000)) >>  24;
	*user_7_tx_data_done = (localVal & ((uint32_t)0x00800000)) >>  23;
	*user_6_tx_data_done = (localVal & ((uint32_t)0x00400000)) >>  22;
	*user_5_tx_data_done = (localVal & ((uint32_t)0x00200000)) >>  21;
	*user_4_tx_data_done = (localVal & ((uint32_t)0x00100000)) >>  20;
	*user_3_tx_data_done = (localVal & ((uint32_t)0x00080000)) >>  19;
	*user_2_tx_data_done = (localVal & ((uint32_t)0x00040000)) >>  18;
	*user_1_tx_data_done = (localVal & ((uint32_t)0x00020000)) >>  17;
	*user_0_tx_data_done = (localVal & ((uint32_t)0x00010000)) >>  16;
	*user_7_tx_vec2 = (localVal & ((uint32_t)0x00008000)) >>  15;
	*user_6_tx_vec2 = (localVal & ((uint32_t)0x00004000)) >>  14;
	*user_5_tx_vec2 = (localVal & ((uint32_t)0x00002000)) >>  13;
	*user_4_tx_vec2 = (localVal & ((uint32_t)0x00001000)) >>  12;
	*user_3_tx_vec2 = (localVal & ((uint32_t)0x00000800)) >>  11;
	*user_2_tx_vec2 = (localVal & ((uint32_t)0x00000400)) >>  10;
	*user_1_tx_vec2 = (localVal & ((uint32_t)0x00000200)) >>  9;
	*user_0_tx_vec2 = (localVal & ((uint32_t)0x00000100)) >>  8;
	*user_7_tx_req_raw = (localVal & ((uint32_t)0x00000080)) >>  7;
	*user_6_tx_req_raw = (localVal & ((uint32_t)0x00000040)) >>  6;
	*user_5_tx_req_raw = (localVal & ((uint32_t)0x00000020)) >>  5;
	*user_4_tx_req_raw = (localVal & ((uint32_t)0x00000010)) >>  4;
	*user_3_tx_req_raw = (localVal & ((uint32_t)0x00000008)) >>  3;
	*user_2_tx_req_raw = (localVal & ((uint32_t)0x00000004)) >>  2;
	*user_1_tx_req_raw = (localVal & ((uint32_t)0x00000002)) >>  1;
	*user_0_tx_req_raw = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t mpu_common_tx_status_sig_en_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TX_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x04000000)) >> 26);
}
__INLINE uint8_t mpu_common_tx_status_tx_done_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TX_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x02000000)) >> 25);
}
__INLINE uint8_t mpu_common_tx_status_tx_on_going_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TX_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01000000)) >> 24);
}
__INLINE uint8_t mpu_common_tx_status_user_7_tx_data_done_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TX_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00800000)) >> 23);
}
__INLINE uint8_t mpu_common_tx_status_user_6_tx_data_done_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TX_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00400000)) >> 22);
}
__INLINE uint8_t mpu_common_tx_status_user_5_tx_data_done_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TX_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00200000)) >> 21);
}
__INLINE uint8_t mpu_common_tx_status_user_4_tx_data_done_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TX_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00100000)) >> 20);
}
__INLINE uint8_t mpu_common_tx_status_user_3_tx_data_done_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TX_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00080000)) >> 19);
}
__INLINE uint8_t mpu_common_tx_status_user_2_tx_data_done_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TX_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00040000)) >> 18);
}
__INLINE uint8_t mpu_common_tx_status_user_1_tx_data_done_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TX_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00020000)) >> 17);
}
__INLINE uint8_t mpu_common_tx_status_user_0_tx_data_done_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TX_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE uint8_t mpu_common_tx_status_user_7_tx_vec_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TX_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE uint8_t mpu_common_tx_status_user_6_tx_vec_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TX_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE uint8_t mpu_common_tx_status_user_5_tx_vec_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TX_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE uint8_t mpu_common_tx_status_user_4_tx_vec_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TX_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE uint8_t mpu_common_tx_status_user_3_tx_vec_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TX_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE uint8_t mpu_common_tx_status_user_2_tx_vec_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TX_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE uint8_t mpu_common_tx_status_user_1_tx_vec_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TX_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t mpu_common_tx_status_user_0_tx_vec_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TX_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE uint8_t mpu_common_tx_status_user_7_tx_req_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TX_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE uint8_t mpu_common_tx_status_user_6_tx_req_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TX_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE uint8_t mpu_common_tx_status_user_5_tx_req_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TX_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE uint8_t mpu_common_tx_status_user_4_tx_req_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TX_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE uint8_t mpu_common_tx_status_user_3_tx_req_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TX_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE uint8_t mpu_common_tx_status_user_2_tx_req_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TX_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE uint8_t mpu_common_tx_status_user_1_tx_req_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TX_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t mpu_common_tx_status_user_0_tx_req_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TX_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief RX_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:24 RX_FRAME_SN               0x0
 *    15    USER_7_RX_DATA_DONE       0              
 *    14    USER_6_RX_DATA_DONE       0              
 *    13    USER_5_RX_DATA_DONE       0              
 *    12    USER_4_RX_DATA_DONE       0              
 *    11    USER_3_RX_DATA_DONE       0              
 *    10    USER_2_RX_DATA_DONE       0              
 *    09    USER_1_RX_DATA_DONE       0              
 *    08    USER_0_RX_DATA_DONE       0              
 *    04    RX_REQ_LOWFLAG            0              
 *    03    RX_END_FOR_TIMING         0              
 *    02    RX_DONE                   0              
 *    01    RX_ON_GOING               0              
 *    00    RX_REQ_RAW                0              
 * </pre>
 */
#define MPU_COMMON_RX_STATUS_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000070)
#define MPU_COMMON_RX_STATUS_OFFSET      0x00000070
#define MPU_COMMON_RX_STATUS_INDEX       0x0000001C
#define MPU_COMMON_RX_STATUS_RESET       0x00000000

__INLINE uint32_t  mpu_common_rx_status_get(void)
{
	return REG_PL_RD(MPU_COMMON_RX_STATUS_ADDR);
}

// field definitions
#define MPU_COMMON_RX_STATUS_RX_FRAME_SN_MASK    ((uint32_t)0x0F000000)
#define MPU_COMMON_RX_STATUS_RX_FRAME_SN_LSB    24
#define MPU_COMMON_RX_STATUS_RX_FRAME_SN_WIDTH    ((uint32_t)0x00000004)
#define MPU_COMMON_RX_STATUS_USER_7_RX_DATA_DONE_BIT    ((uint32_t)0x00008000)
#define MPU_COMMON_RX_STATUS_USER_7_RX_DATA_DONE_POS    15
#define MPU_COMMON_RX_STATUS_USER_6_RX_DATA_DONE_BIT    ((uint32_t)0x00004000)
#define MPU_COMMON_RX_STATUS_USER_6_RX_DATA_DONE_POS    14
#define MPU_COMMON_RX_STATUS_USER_5_RX_DATA_DONE_BIT    ((uint32_t)0x00002000)
#define MPU_COMMON_RX_STATUS_USER_5_RX_DATA_DONE_POS    13
#define MPU_COMMON_RX_STATUS_USER_4_RX_DATA_DONE_BIT    ((uint32_t)0x00001000)
#define MPU_COMMON_RX_STATUS_USER_4_RX_DATA_DONE_POS    12
#define MPU_COMMON_RX_STATUS_USER_3_RX_DATA_DONE_BIT    ((uint32_t)0x00000800)
#define MPU_COMMON_RX_STATUS_USER_3_RX_DATA_DONE_POS    11
#define MPU_COMMON_RX_STATUS_USER_2_RX_DATA_DONE_BIT    ((uint32_t)0x00000400)
#define MPU_COMMON_RX_STATUS_USER_2_RX_DATA_DONE_POS    10
#define MPU_COMMON_RX_STATUS_USER_1_RX_DATA_DONE_BIT    ((uint32_t)0x00000200)
#define MPU_COMMON_RX_STATUS_USER_1_RX_DATA_DONE_POS    9
#define MPU_COMMON_RX_STATUS_USER_0_RX_DATA_DONE_BIT    ((uint32_t)0x00000100)
#define MPU_COMMON_RX_STATUS_USER_0_RX_DATA_DONE_POS    8
#define MPU_COMMON_RX_STATUS_RX_REQ_LOWFLAG_BIT    ((uint32_t)0x00000010)
#define MPU_COMMON_RX_STATUS_RX_REQ_LOWFLAG_POS    4
#define MPU_COMMON_RX_STATUS_RX_END_FOR_TIMING_BIT    ((uint32_t)0x00000008)
#define MPU_COMMON_RX_STATUS_RX_END_FOR_TIMING_POS    3
#define MPU_COMMON_RX_STATUS_RX_DONE_BIT    ((uint32_t)0x00000004)
#define MPU_COMMON_RX_STATUS_RX_DONE_POS    2
#define MPU_COMMON_RX_STATUS_RX_ON_GOING_BIT    ((uint32_t)0x00000002)
#define MPU_COMMON_RX_STATUS_RX_ON_GOING_POS    1
#define MPU_COMMON_RX_STATUS_RX_REQ_RAW_BIT    ((uint32_t)0x00000001)
#define MPU_COMMON_RX_STATUS_RX_REQ_RAW_POS    0

#define MPU_COMMON_RX_STATUS_RX_FRAME_SN_RST    0x0
#define MPU_COMMON_RX_STATUS_USER_7_RX_DATA_DONE_RST    0x0
#define MPU_COMMON_RX_STATUS_USER_6_RX_DATA_DONE_RST    0x0
#define MPU_COMMON_RX_STATUS_USER_5_RX_DATA_DONE_RST    0x0
#define MPU_COMMON_RX_STATUS_USER_4_RX_DATA_DONE_RST    0x0
#define MPU_COMMON_RX_STATUS_USER_3_RX_DATA_DONE_RST    0x0
#define MPU_COMMON_RX_STATUS_USER_2_RX_DATA_DONE_RST    0x0
#define MPU_COMMON_RX_STATUS_USER_1_RX_DATA_DONE_RST    0x0
#define MPU_COMMON_RX_STATUS_USER_0_RX_DATA_DONE_RST    0x0
#define MPU_COMMON_RX_STATUS_RX_REQ_LOWFLAG_RST    0x0
#define MPU_COMMON_RX_STATUS_RX_END_FOR_TIMING_RST    0x0
#define MPU_COMMON_RX_STATUS_RX_DONE_RST    0x0
#define MPU_COMMON_RX_STATUS_RX_ON_GOING_RST    0x0
#define MPU_COMMON_RX_STATUS_RX_REQ_RAW_RST    0x0

__INLINE void mpu_common_rx_status_unpack(uint8_t* rx_frame_sn, uint8_t* user_7_rx_data_done, uint8_t* user_6_rx_data_done, uint8_t* user_5_rx_data_done, uint8_t* user_4_rx_data_done, uint8_t* user_3_rx_data_done, uint8_t* user_2_rx_data_done, uint8_t* user_1_rx_data_done, uint8_t* user_0_rx_data_done, uint8_t* rx_req_lowflag, uint8_t* rx_end_for_timing, uint8_t* rx_done, uint8_t* rx_on_going, uint8_t* rx_req_raw)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_RX_STATUS_ADDR);

	*rx_frame_sn = (localVal & ((uint32_t)0x0F000000)) >>  24;
	*user_7_rx_data_done = (localVal & ((uint32_t)0x00008000)) >>  15;
	*user_6_rx_data_done = (localVal & ((uint32_t)0x00004000)) >>  14;
	*user_5_rx_data_done = (localVal & ((uint32_t)0x00002000)) >>  13;
	*user_4_rx_data_done = (localVal & ((uint32_t)0x00001000)) >>  12;
	*user_3_rx_data_done = (localVal & ((uint32_t)0x00000800)) >>  11;
	*user_2_rx_data_done = (localVal & ((uint32_t)0x00000400)) >>  10;
	*user_1_rx_data_done = (localVal & ((uint32_t)0x00000200)) >>  9;
	*user_0_rx_data_done = (localVal & ((uint32_t)0x00000100)) >>  8;
	*rx_req_lowflag = (localVal & ((uint32_t)0x00000010)) >>  4;
	*rx_end_for_timing = (localVal & ((uint32_t)0x00000008)) >>  3;
	*rx_done = (localVal & ((uint32_t)0x00000004)) >>  2;
	*rx_on_going = (localVal & ((uint32_t)0x00000002)) >>  1;
	*rx_req_raw = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t mpu_common_rx_status_rx_frame_sn_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_RX_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0F000000)) >> 24);
}
__INLINE uint8_t mpu_common_rx_status_user_7_rx_data_done_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_RX_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE uint8_t mpu_common_rx_status_user_6_rx_data_done_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_RX_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE uint8_t mpu_common_rx_status_user_5_rx_data_done_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_RX_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE uint8_t mpu_common_rx_status_user_4_rx_data_done_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_RX_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE uint8_t mpu_common_rx_status_user_3_rx_data_done_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_RX_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE uint8_t mpu_common_rx_status_user_2_rx_data_done_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_RX_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE uint8_t mpu_common_rx_status_user_1_rx_data_done_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_RX_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t mpu_common_rx_status_user_0_rx_data_done_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_RX_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE uint8_t mpu_common_rx_status_rx_req_lowflag_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_RX_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE uint8_t mpu_common_rx_status_rx_end_for_timing_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_RX_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE uint8_t mpu_common_rx_status_rx_done_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_RX_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE uint8_t mpu_common_rx_status_rx_on_going_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_RX_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t mpu_common_rx_status_rx_req_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_RX_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief INT_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    29    TX_REQ_RISE_EN            0              
 *    28    TX_REQ_FALL_EN            0              
 *    27    RX_REQ_RISE_EN            0              
 *    26    RX_REQ_FALL_EN            0              
 *    25    LMAC_INT0_EN              0              
 *    24    SMAC_INT0_EN              0              
 *    23    UMAC_INT0_EN              0              
 *    22    RX_REQ_LOW_FLAG_EN        0              
 *    20    KEEP_RF_ON_RISE_EN        0              
 *    19    KEEP_RF_ON_FALL_EN        0              
 *    18    SERVICE_UP_EN             0              
 *    17    TX_VECTOR_UP_EN           0              
 *    16    TX_OVERFLOW_EN            0              
 *    15    CRC_PARITY_ERR_EN         0              
 *    14    LMAC_INT1_EN              0              
 *    13    SMAC_INT1_EN              0              
 *    12    UMAC_INT1_EN              0              
 *    11    TX_VECTOR2_UP_EN          0              
 *    10    RX_VECTOR_UP_EN           0              
 *    07    SIGB_GEN_DONE_EN          0              
 *    06    MPU_ERR_EN                0              
 *    04    LMAC_INT2_EN              0              
 *    03    SMAC_INT2_EN              0              
 *    02    UMAC_INT2_EN              0              
 * </pre>
 */
#define MPU_COMMON_INT_EN_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000074)
#define MPU_COMMON_INT_EN_OFFSET      0x00000074
#define MPU_COMMON_INT_EN_INDEX       0x0000001D
#define MPU_COMMON_INT_EN_RESET       0x00000000

__INLINE uint32_t  mpu_common_int_en_get(void)
{
	return REG_PL_RD(MPU_COMMON_INT_EN_ADDR);
}

__INLINE void mpu_common_int_en_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_INT_EN_ADDR, value);
}

// field definitions
#define MPU_COMMON_INT_EN_TX_REQ_RISE_EN_BIT    ((uint32_t)0x20000000)
#define MPU_COMMON_INT_EN_TX_REQ_RISE_EN_POS    29
#define MPU_COMMON_INT_EN_TX_REQ_FALL_EN_BIT    ((uint32_t)0x10000000)
#define MPU_COMMON_INT_EN_TX_REQ_FALL_EN_POS    28
#define MPU_COMMON_INT_EN_RX_REQ_RISE_EN_BIT    ((uint32_t)0x08000000)
#define MPU_COMMON_INT_EN_RX_REQ_RISE_EN_POS    27
#define MPU_COMMON_INT_EN_RX_REQ_FALL_EN_BIT    ((uint32_t)0x04000000)
#define MPU_COMMON_INT_EN_RX_REQ_FALL_EN_POS    26
#define MPU_COMMON_INT_EN_LMAC_INT_0_EN_BIT    ((uint32_t)0x02000000)
#define MPU_COMMON_INT_EN_LMAC_INT_0_EN_POS    25
#define MPU_COMMON_INT_EN_SMAC_INT_0_EN_BIT    ((uint32_t)0x01000000)
#define MPU_COMMON_INT_EN_SMAC_INT_0_EN_POS    24
#define MPU_COMMON_INT_EN_UMAC_INT_0_EN_BIT    ((uint32_t)0x00800000)
#define MPU_COMMON_INT_EN_UMAC_INT_0_EN_POS    23
#define MPU_COMMON_INT_EN_RX_REQ_LOW_FLAG_EN_BIT    ((uint32_t)0x00400000)
#define MPU_COMMON_INT_EN_RX_REQ_LOW_FLAG_EN_POS    22
#define MPU_COMMON_INT_EN_KEEP_RF_ON_RISE_EN_BIT    ((uint32_t)0x00100000)
#define MPU_COMMON_INT_EN_KEEP_RF_ON_RISE_EN_POS    20
#define MPU_COMMON_INT_EN_KEEP_RF_ON_FALL_EN_BIT    ((uint32_t)0x00080000)
#define MPU_COMMON_INT_EN_KEEP_RF_ON_FALL_EN_POS    19
#define MPU_COMMON_INT_EN_SERVICE_UP_EN_BIT    ((uint32_t)0x00040000)
#define MPU_COMMON_INT_EN_SERVICE_UP_EN_POS    18
#define MPU_COMMON_INT_EN_TX_VECTOR_UP_EN_BIT    ((uint32_t)0x00020000)
#define MPU_COMMON_INT_EN_TX_VECTOR_UP_EN_POS    17
#define MPU_COMMON_INT_EN_TX_OVERFLOW_EN_BIT    ((uint32_t)0x00010000)
#define MPU_COMMON_INT_EN_TX_OVERFLOW_EN_POS    16
#define MPU_COMMON_INT_EN_CRC_PARITY_ERR_EN_BIT    ((uint32_t)0x00008000)
#define MPU_COMMON_INT_EN_CRC_PARITY_ERR_EN_POS    15
#define MPU_COMMON_INT_EN_LMAC_INT_1_EN_BIT    ((uint32_t)0x00004000)
#define MPU_COMMON_INT_EN_LMAC_INT_1_EN_POS    14
#define MPU_COMMON_INT_EN_SMAC_INT_1_EN_BIT    ((uint32_t)0x00002000)
#define MPU_COMMON_INT_EN_SMAC_INT_1_EN_POS    13
#define MPU_COMMON_INT_EN_UMAC_INT_1_EN_BIT    ((uint32_t)0x00001000)
#define MPU_COMMON_INT_EN_UMAC_INT_1_EN_POS    12
#define MPU_COMMON_INT_EN_TX_VECTOR_2_UP_EN_BIT    ((uint32_t)0x00000800)
#define MPU_COMMON_INT_EN_TX_VECTOR_2_UP_EN_POS    11
#define MPU_COMMON_INT_EN_RX_VECTOR_UP_EN_BIT    ((uint32_t)0x00000400)
#define MPU_COMMON_INT_EN_RX_VECTOR_UP_EN_POS    10
#define MPU_COMMON_INT_EN_SIGB_GEN_DONE_EN_BIT    ((uint32_t)0x00000080)
#define MPU_COMMON_INT_EN_SIGB_GEN_DONE_EN_POS    7
#define MPU_COMMON_INT_EN_MPU_ERR_EN_BIT    ((uint32_t)0x00000040)
#define MPU_COMMON_INT_EN_MPU_ERR_EN_POS    6
#define MPU_COMMON_INT_EN_LMAC_INT_2_EN_BIT    ((uint32_t)0x00000010)
#define MPU_COMMON_INT_EN_LMAC_INT_2_EN_POS    4
#define MPU_COMMON_INT_EN_SMAC_INT_2_EN_BIT    ((uint32_t)0x00000008)
#define MPU_COMMON_INT_EN_SMAC_INT_2_EN_POS    3
#define MPU_COMMON_INT_EN_UMAC_INT_2_EN_BIT    ((uint32_t)0x00000004)
#define MPU_COMMON_INT_EN_UMAC_INT_2_EN_POS    2

#define MPU_COMMON_INT_EN_TX_REQ_RISE_EN_RST    0x0
#define MPU_COMMON_INT_EN_TX_REQ_FALL_EN_RST    0x0
#define MPU_COMMON_INT_EN_RX_REQ_RISE_EN_RST    0x0
#define MPU_COMMON_INT_EN_RX_REQ_FALL_EN_RST    0x0
#define MPU_COMMON_INT_EN_LMAC_INT_0_EN_RST    0x0
#define MPU_COMMON_INT_EN_SMAC_INT_0_EN_RST    0x0
#define MPU_COMMON_INT_EN_UMAC_INT_0_EN_RST    0x0
#define MPU_COMMON_INT_EN_RX_REQ_LOW_FLAG_EN_RST    0x0
#define MPU_COMMON_INT_EN_KEEP_RF_ON_RISE_EN_RST    0x0
#define MPU_COMMON_INT_EN_KEEP_RF_ON_FALL_EN_RST    0x0
#define MPU_COMMON_INT_EN_SERVICE_UP_EN_RST    0x0
#define MPU_COMMON_INT_EN_TX_VECTOR_UP_EN_RST    0x0
#define MPU_COMMON_INT_EN_TX_OVERFLOW_EN_RST    0x0
#define MPU_COMMON_INT_EN_CRC_PARITY_ERR_EN_RST    0x0
#define MPU_COMMON_INT_EN_LMAC_INT_1_EN_RST    0x0
#define MPU_COMMON_INT_EN_SMAC_INT_1_EN_RST    0x0
#define MPU_COMMON_INT_EN_UMAC_INT_1_EN_RST    0x0
#define MPU_COMMON_INT_EN_TX_VECTOR_2_UP_EN_RST    0x0
#define MPU_COMMON_INT_EN_RX_VECTOR_UP_EN_RST    0x0
#define MPU_COMMON_INT_EN_SIGB_GEN_DONE_EN_RST    0x0
#define MPU_COMMON_INT_EN_MPU_ERR_EN_RST    0x0
#define MPU_COMMON_INT_EN_LMAC_INT_2_EN_RST    0x0
#define MPU_COMMON_INT_EN_SMAC_INT_2_EN_RST    0x0
#define MPU_COMMON_INT_EN_UMAC_INT_2_EN_RST    0x0

__INLINE void mpu_common_int_en_pack(uint8_t tx_req_rise_en, uint8_t tx_req_fall_en, uint8_t rx_req_rise_en, uint8_t rx_req_fall_en, uint8_t lmac_int0_en, uint8_t smac_int0_en, uint8_t umac_int0_en, uint8_t rx_req_low_flag_en, uint8_t keep_rf_on_rise_en, uint8_t keep_rf_on_fall_en, uint8_t service_up_en, uint8_t tx_vector_up_en, uint8_t tx_overflow_en, uint8_t crc_parity_err_en, uint8_t lmac_int1_en, uint8_t smac_int1_en, uint8_t umac_int1_en, uint8_t tx_vector2_up_en, uint8_t rx_vector_up_en, uint8_t sigb_gen_done_en, uint8_t mpu_err_en, uint8_t lmac_int2_en, uint8_t smac_int2_en, uint8_t umac_int2_en)
{
	ASSERT_ERR((((uint32_t)tx_req_rise_en << 29) & ~((uint32_t)0x20000000)) == 0);
	ASSERT_ERR((((uint32_t)tx_req_fall_en << 28) & ~((uint32_t)0x10000000)) == 0);
	ASSERT_ERR((((uint32_t)rx_req_rise_en << 27) & ~((uint32_t)0x08000000)) == 0);
	ASSERT_ERR((((uint32_t)rx_req_fall_en << 26) & ~((uint32_t)0x04000000)) == 0);
	ASSERT_ERR((((uint32_t)lmac_int0_en << 25) & ~((uint32_t)0x02000000)) == 0);
	ASSERT_ERR((((uint32_t)smac_int0_en << 24) & ~((uint32_t)0x01000000)) == 0);
	ASSERT_ERR((((uint32_t)umac_int0_en << 23) & ~((uint32_t)0x00800000)) == 0);
	ASSERT_ERR((((uint32_t)rx_req_low_flag_en << 22) & ~((uint32_t)0x00400000)) == 0);
	ASSERT_ERR((((uint32_t)keep_rf_on_rise_en << 20) & ~((uint32_t)0x00100000)) == 0);
	ASSERT_ERR((((uint32_t)keep_rf_on_fall_en << 19) & ~((uint32_t)0x00080000)) == 0);
	ASSERT_ERR((((uint32_t)service_up_en << 18) & ~((uint32_t)0x00040000)) == 0);
	ASSERT_ERR((((uint32_t)tx_vector_up_en << 17) & ~((uint32_t)0x00020000)) == 0);
	ASSERT_ERR((((uint32_t)tx_overflow_en << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)crc_parity_err_en << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)lmac_int1_en << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)smac_int1_en << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)umac_int1_en << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)tx_vector2_up_en << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)rx_vector_up_en << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)sigb_gen_done_en << 7) & ~((uint32_t)0x00000080)) == 0);
	ASSERT_ERR((((uint32_t)mpu_err_en << 6) & ~((uint32_t)0x00000040)) == 0);
	ASSERT_ERR((((uint32_t)lmac_int2_en << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)smac_int2_en << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)umac_int2_en << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(MPU_COMMON_INT_EN_ADDR,  ((uint32_t)tx_req_rise_en << 29) |((uint32_t)tx_req_fall_en << 28) |((uint32_t)rx_req_rise_en << 27) |((uint32_t)rx_req_fall_en << 26) |((uint32_t)lmac_int0_en << 25) |((uint32_t)smac_int0_en << 24) |((uint32_t)umac_int0_en << 23) |((uint32_t)rx_req_low_flag_en << 22) |((uint32_t)keep_rf_on_rise_en << 20) |((uint32_t)keep_rf_on_fall_en << 19) |((uint32_t)service_up_en << 18) |((uint32_t)tx_vector_up_en << 17) |((uint32_t)tx_overflow_en << 16) |((uint32_t)crc_parity_err_en << 15) |((uint32_t)lmac_int1_en << 14) |((uint32_t)smac_int1_en << 13) |((uint32_t)umac_int1_en << 12) |((uint32_t)tx_vector2_up_en << 11) |((uint32_t)rx_vector_up_en << 10) |((uint32_t)sigb_gen_done_en << 7) |((uint32_t)mpu_err_en << 6) |((uint32_t)lmac_int2_en << 4) |((uint32_t)smac_int2_en << 3) |((uint32_t)umac_int2_en << 2));
}

__INLINE void mpu_common_int_en_unpack(uint8_t* tx_req_rise_en, uint8_t* tx_req_fall_en, uint8_t* rx_req_rise_en, uint8_t* rx_req_fall_en, uint8_t* lmac_int0_en, uint8_t* smac_int0_en, uint8_t* umac_int0_en, uint8_t* rx_req_low_flag_en, uint8_t* keep_rf_on_rise_en, uint8_t* keep_rf_on_fall_en, uint8_t* service_up_en, uint8_t* tx_vector_up_en, uint8_t* tx_overflow_en, uint8_t* crc_parity_err_en, uint8_t* lmac_int1_en, uint8_t* smac_int1_en, uint8_t* umac_int1_en, uint8_t* tx_vector2_up_en, uint8_t* rx_vector_up_en, uint8_t* sigb_gen_done_en, uint8_t* mpu_err_en, uint8_t* lmac_int2_en, uint8_t* smac_int2_en, uint8_t* umac_int2_en)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_EN_ADDR);

	*tx_req_rise_en = (localVal & ((uint32_t)0x20000000)) >>  29;
	*tx_req_fall_en = (localVal & ((uint32_t)0x10000000)) >>  28;
	*rx_req_rise_en = (localVal & ((uint32_t)0x08000000)) >>  27;
	*rx_req_fall_en = (localVal & ((uint32_t)0x04000000)) >>  26;
	*lmac_int0_en = (localVal & ((uint32_t)0x02000000)) >>  25;
	*smac_int0_en = (localVal & ((uint32_t)0x01000000)) >>  24;
	*umac_int0_en = (localVal & ((uint32_t)0x00800000)) >>  23;
	*rx_req_low_flag_en = (localVal & ((uint32_t)0x00400000)) >>  22;
	*keep_rf_on_rise_en = (localVal & ((uint32_t)0x00100000)) >>  20;
	*keep_rf_on_fall_en = (localVal & ((uint32_t)0x00080000)) >>  19;
	*service_up_en = (localVal & ((uint32_t)0x00040000)) >>  18;
	*tx_vector_up_en = (localVal & ((uint32_t)0x00020000)) >>  17;
	*tx_overflow_en = (localVal & ((uint32_t)0x00010000)) >>  16;
	*crc_parity_err_en = (localVal & ((uint32_t)0x00008000)) >>  15;
	*lmac_int1_en = (localVal & ((uint32_t)0x00004000)) >>  14;
	*smac_int1_en = (localVal & ((uint32_t)0x00002000)) >>  13;
	*umac_int1_en = (localVal & ((uint32_t)0x00001000)) >>  12;
	*tx_vector2_up_en = (localVal & ((uint32_t)0x00000800)) >>  11;
	*rx_vector_up_en = (localVal & ((uint32_t)0x00000400)) >>  10;
	*sigb_gen_done_en = (localVal & ((uint32_t)0x00000080)) >>  7;
	*mpu_err_en = (localVal & ((uint32_t)0x00000040)) >>  6;
	*lmac_int2_en = (localVal & ((uint32_t)0x00000010)) >>  4;
	*smac_int2_en = (localVal & ((uint32_t)0x00000008)) >>  3;
	*umac_int2_en = (localVal & ((uint32_t)0x00000004)) >>  2;
}

__INLINE uint8_t mpu_common_int_en_tx_req_rise_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x20000000)) >> 29);
}
__INLINE void mpu_common_int_en_tx_req_rise_en_setf(uint8_t txreqriseen)
{
	ASSERT_ERR((((uint32_t)txreqriseen << 29) & ~((uint32_t)0x20000000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_EN_ADDR, (REG_PL_RD(MPU_COMMON_INT_EN_ADDR) & ~((uint32_t)0x20000000)) | ((uint32_t)txreqriseen <<29));
}
__INLINE uint8_t mpu_common_int_en_tx_req_fall_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x10000000)) >> 28);
}
__INLINE void mpu_common_int_en_tx_req_fall_en_setf(uint8_t txreqfallen)
{
	ASSERT_ERR((((uint32_t)txreqfallen << 28) & ~((uint32_t)0x10000000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_EN_ADDR, (REG_PL_RD(MPU_COMMON_INT_EN_ADDR) & ~((uint32_t)0x10000000)) | ((uint32_t)txreqfallen <<28));
}
__INLINE uint8_t mpu_common_int_en_rx_req_rise_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x08000000)) >> 27);
}
__INLINE void mpu_common_int_en_rx_req_rise_en_setf(uint8_t rxreqriseen)
{
	ASSERT_ERR((((uint32_t)rxreqriseen << 27) & ~((uint32_t)0x08000000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_EN_ADDR, (REG_PL_RD(MPU_COMMON_INT_EN_ADDR) & ~((uint32_t)0x08000000)) | ((uint32_t)rxreqriseen <<27));
}
__INLINE uint8_t mpu_common_int_en_rx_req_fall_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x04000000)) >> 26);
}
__INLINE void mpu_common_int_en_rx_req_fall_en_setf(uint8_t rxreqfallen)
{
	ASSERT_ERR((((uint32_t)rxreqfallen << 26) & ~((uint32_t)0x04000000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_EN_ADDR, (REG_PL_RD(MPU_COMMON_INT_EN_ADDR) & ~((uint32_t)0x04000000)) | ((uint32_t)rxreqfallen <<26));
}
__INLINE uint8_t mpu_common_int_en_lmac_int_0_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x02000000)) >> 25);
}
__INLINE void mpu_common_int_en_lmac_int_0_en_setf(uint8_t lmacint0en)
{
	ASSERT_ERR((((uint32_t)lmacint0en << 25) & ~((uint32_t)0x02000000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_EN_ADDR, (REG_PL_RD(MPU_COMMON_INT_EN_ADDR) & ~((uint32_t)0x02000000)) | ((uint32_t)lmacint0en <<25));
}
__INLINE uint8_t mpu_common_int_en_smac_int_0_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01000000)) >> 24);
}
__INLINE void mpu_common_int_en_smac_int_0_en_setf(uint8_t smacint0en)
{
	ASSERT_ERR((((uint32_t)smacint0en << 24) & ~((uint32_t)0x01000000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_EN_ADDR, (REG_PL_RD(MPU_COMMON_INT_EN_ADDR) & ~((uint32_t)0x01000000)) | ((uint32_t)smacint0en <<24));
}
__INLINE uint8_t mpu_common_int_en_umac_int_0_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00800000)) >> 23);
}
__INLINE void mpu_common_int_en_umac_int_0_en_setf(uint8_t umacint0en)
{
	ASSERT_ERR((((uint32_t)umacint0en << 23) & ~((uint32_t)0x00800000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_EN_ADDR, (REG_PL_RD(MPU_COMMON_INT_EN_ADDR) & ~((uint32_t)0x00800000)) | ((uint32_t)umacint0en <<23));
}
__INLINE uint8_t mpu_common_int_en_rx_req_low_flag_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00400000)) >> 22);
}
__INLINE void mpu_common_int_en_rx_req_low_flag_en_setf(uint8_t rxreqlowflagen)
{
	ASSERT_ERR((((uint32_t)rxreqlowflagen << 22) & ~((uint32_t)0x00400000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_EN_ADDR, (REG_PL_RD(MPU_COMMON_INT_EN_ADDR) & ~((uint32_t)0x00400000)) | ((uint32_t)rxreqlowflagen <<22));
}
__INLINE uint8_t mpu_common_int_en_keep_rf_on_rise_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00100000)) >> 20);
}
__INLINE void mpu_common_int_en_keep_rf_on_rise_en_setf(uint8_t keeprfonriseen)
{
	ASSERT_ERR((((uint32_t)keeprfonriseen << 20) & ~((uint32_t)0x00100000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_EN_ADDR, (REG_PL_RD(MPU_COMMON_INT_EN_ADDR) & ~((uint32_t)0x00100000)) | ((uint32_t)keeprfonriseen <<20));
}
__INLINE uint8_t mpu_common_int_en_keep_rf_on_fall_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00080000)) >> 19);
}
__INLINE void mpu_common_int_en_keep_rf_on_fall_en_setf(uint8_t keeprfonfallen)
{
	ASSERT_ERR((((uint32_t)keeprfonfallen << 19) & ~((uint32_t)0x00080000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_EN_ADDR, (REG_PL_RD(MPU_COMMON_INT_EN_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)keeprfonfallen <<19));
}
__INLINE uint8_t mpu_common_int_en_service_up_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00040000)) >> 18);
}
__INLINE void mpu_common_int_en_service_up_en_setf(uint8_t serviceupen)
{
	ASSERT_ERR((((uint32_t)serviceupen << 18) & ~((uint32_t)0x00040000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_EN_ADDR, (REG_PL_RD(MPU_COMMON_INT_EN_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)serviceupen <<18));
}
__INLINE uint8_t mpu_common_int_en_tx_vector_up_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00020000)) >> 17);
}
__INLINE void mpu_common_int_en_tx_vector_up_en_setf(uint8_t txvectorupen)
{
	ASSERT_ERR((((uint32_t)txvectorupen << 17) & ~((uint32_t)0x00020000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_EN_ADDR, (REG_PL_RD(MPU_COMMON_INT_EN_ADDR) & ~((uint32_t)0x00020000)) | ((uint32_t)txvectorupen <<17));
}
__INLINE uint8_t mpu_common_int_en_tx_overflow_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void mpu_common_int_en_tx_overflow_en_setf(uint8_t txoverflowen)
{
	ASSERT_ERR((((uint32_t)txoverflowen << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_EN_ADDR, (REG_PL_RD(MPU_COMMON_INT_EN_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)txoverflowen <<16));
}
__INLINE uint8_t mpu_common_int_en_crc_parity_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void mpu_common_int_en_crc_parity_err_en_setf(uint8_t crcparityerren)
{
	ASSERT_ERR((((uint32_t)crcparityerren << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_EN_ADDR, (REG_PL_RD(MPU_COMMON_INT_EN_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)crcparityerren <<15));
}
__INLINE uint8_t mpu_common_int_en_lmac_int_1_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void mpu_common_int_en_lmac_int_1_en_setf(uint8_t lmacint1en)
{
	ASSERT_ERR((((uint32_t)lmacint1en << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_EN_ADDR, (REG_PL_RD(MPU_COMMON_INT_EN_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)lmacint1en <<14));
}
__INLINE uint8_t mpu_common_int_en_smac_int_1_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void mpu_common_int_en_smac_int_1_en_setf(uint8_t smacint1en)
{
	ASSERT_ERR((((uint32_t)smacint1en << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_EN_ADDR, (REG_PL_RD(MPU_COMMON_INT_EN_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)smacint1en <<13));
}
__INLINE uint8_t mpu_common_int_en_umac_int_1_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void mpu_common_int_en_umac_int_1_en_setf(uint8_t umacint1en)
{
	ASSERT_ERR((((uint32_t)umacint1en << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_EN_ADDR, (REG_PL_RD(MPU_COMMON_INT_EN_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)umacint1en <<12));
}
__INLINE uint8_t mpu_common_int_en_tx_vector_2_up_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void mpu_common_int_en_tx_vector_2_up_en_setf(uint8_t txvector2upen)
{
	ASSERT_ERR((((uint32_t)txvector2upen << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(MPU_COMMON_INT_EN_ADDR, (REG_PL_RD(MPU_COMMON_INT_EN_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)txvector2upen <<11));
}
__INLINE uint8_t mpu_common_int_en_rx_vector_up_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void mpu_common_int_en_rx_vector_up_en_setf(uint8_t rxvectorupen)
{
	ASSERT_ERR((((uint32_t)rxvectorupen << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(MPU_COMMON_INT_EN_ADDR, (REG_PL_RD(MPU_COMMON_INT_EN_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)rxvectorupen <<10));
}
__INLINE uint8_t mpu_common_int_en_sigb_gen_done_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE void mpu_common_int_en_sigb_gen_done_en_setf(uint8_t sigbgendoneen)
{
	ASSERT_ERR((((uint32_t)sigbgendoneen << 7) & ~((uint32_t)0x00000080)) == 0);
	REG_PL_WR(MPU_COMMON_INT_EN_ADDR, (REG_PL_RD(MPU_COMMON_INT_EN_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)sigbgendoneen <<7));
}
__INLINE uint8_t mpu_common_int_en_mpu_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE void mpu_common_int_en_mpu_err_en_setf(uint8_t mpuerren)
{
	ASSERT_ERR((((uint32_t)mpuerren << 6) & ~((uint32_t)0x00000040)) == 0);
	REG_PL_WR(MPU_COMMON_INT_EN_ADDR, (REG_PL_RD(MPU_COMMON_INT_EN_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)mpuerren <<6));
}
__INLINE uint8_t mpu_common_int_en_lmac_int_2_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void mpu_common_int_en_lmac_int_2_en_setf(uint8_t lmacint2en)
{
	ASSERT_ERR((((uint32_t)lmacint2en << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(MPU_COMMON_INT_EN_ADDR, (REG_PL_RD(MPU_COMMON_INT_EN_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)lmacint2en <<4));
}
__INLINE uint8_t mpu_common_int_en_smac_int_2_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void mpu_common_int_en_smac_int_2_en_setf(uint8_t smacint2en)
{
	ASSERT_ERR((((uint32_t)smacint2en << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(MPU_COMMON_INT_EN_ADDR, (REG_PL_RD(MPU_COMMON_INT_EN_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)smacint2en <<3));
}
__INLINE uint8_t mpu_common_int_en_umac_int_2_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void mpu_common_int_en_umac_int_2_en_setf(uint8_t umacint2en)
{
	ASSERT_ERR((((uint32_t)umacint2en << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(MPU_COMMON_INT_EN_ADDR, (REG_PL_RD(MPU_COMMON_INT_EN_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)umacint2en <<2));
}

/**
 * @brief INT_STAT_MASKED register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    29    TX_REQ_RISE_STAT_MASKED   0              
 *    28    TX_REQ_FALL_STAT_MASKED   0              
 *    27    RX_REQ_RISE_STAT_MASKED   0              
 *    26    RX_REQ_FALL_STAT_MASKED   0              
 *    25    LMAC_INT0_STAT_MASKED     0              
 *    24    SMAC_INT0_STAT_MASKED     0              
 *    23    UMAC_INT0_STAT_MASKED     0              
 *    22    RX_REQ_LOW_FLAG_STAT_MASKED 0              
 *    20    KEEP_RF_ON_RISE_STAT_MASKED 0              
 *    19    KEEP_RF_ON_FALL_STAT_MASKED 0              
 *    18    SERVICE_UP_STAT_MASKED    0              
 *    17    TX_VECTOR_UP_STAT_MASKED  0              
 *    16    TX_OVERFLOW_STAT_MASKED   0              
 *    15    CRC_PARITY_ERR_STAT_MASKED 0              
 *    14    LMAC_INT1_STAT_MASKED     0              
 *    13    SMAC_INT1_STAT_MASKED     0              
 *    12    UMAC_INT1_STAT_MASKED     0              
 *    11    TX_VECTOR2_UP_STAT_MASKED 0              
 *    10    RX_VECTOR_UP_STAT_MASKED  0              
 *    07    SIGB_DONE_STAT_MASKED     0              
 *    06    MPU_ERR_STAT_MASKED       0              
 *    04    LMAC_INT2_STAT_MASKED     0              
 *    03    SMAC_INT2_STAT_MASKED     0              
 *    02    UMAC_INT2_STAT_MASKED     0              
 * </pre>
 */
#define MPU_COMMON_INT_STAT_MASKED_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000078)
#define MPU_COMMON_INT_STAT_MASKED_OFFSET      0x00000078
#define MPU_COMMON_INT_STAT_MASKED_INDEX       0x0000001E
#define MPU_COMMON_INT_STAT_MASKED_RESET       0x00000000

__INLINE uint32_t  mpu_common_int_stat_masked_get(void)
{
	return REG_PL_RD(MPU_COMMON_INT_STAT_MASKED_ADDR);
}

// field definitions
#define MPU_COMMON_INT_STAT_MASKED_TX_REQ_RISE_STAT_MASKED_BIT    ((uint32_t)0x20000000)
#define MPU_COMMON_INT_STAT_MASKED_TX_REQ_RISE_STAT_MASKED_POS    29
#define MPU_COMMON_INT_STAT_MASKED_TX_REQ_FALL_STAT_MASKED_BIT    ((uint32_t)0x10000000)
#define MPU_COMMON_INT_STAT_MASKED_TX_REQ_FALL_STAT_MASKED_POS    28
#define MPU_COMMON_INT_STAT_MASKED_RX_REQ_RISE_STAT_MASKED_BIT    ((uint32_t)0x08000000)
#define MPU_COMMON_INT_STAT_MASKED_RX_REQ_RISE_STAT_MASKED_POS    27
#define MPU_COMMON_INT_STAT_MASKED_RX_REQ_FALL_STAT_MASKED_BIT    ((uint32_t)0x04000000)
#define MPU_COMMON_INT_STAT_MASKED_RX_REQ_FALL_STAT_MASKED_POS    26
#define MPU_COMMON_INT_STAT_MASKED_LMAC_INT_0_STAT_MASKED_BIT    ((uint32_t)0x02000000)
#define MPU_COMMON_INT_STAT_MASKED_LMAC_INT_0_STAT_MASKED_POS    25
#define MPU_COMMON_INT_STAT_MASKED_SMAC_INT_0_STAT_MASKED_BIT    ((uint32_t)0x01000000)
#define MPU_COMMON_INT_STAT_MASKED_SMAC_INT_0_STAT_MASKED_POS    24
#define MPU_COMMON_INT_STAT_MASKED_UMAC_INT_0_STAT_MASKED_BIT    ((uint32_t)0x00800000)
#define MPU_COMMON_INT_STAT_MASKED_UMAC_INT_0_STAT_MASKED_POS    23
#define MPU_COMMON_INT_STAT_MASKED_RX_REQ_LOW_FLAG_STAT_MASKED_BIT    ((uint32_t)0x00400000)
#define MPU_COMMON_INT_STAT_MASKED_RX_REQ_LOW_FLAG_STAT_MASKED_POS    22
#define MPU_COMMON_INT_STAT_MASKED_KEEP_RF_ON_RISE_STAT_MASKED_BIT    ((uint32_t)0x00100000)
#define MPU_COMMON_INT_STAT_MASKED_KEEP_RF_ON_RISE_STAT_MASKED_POS    20
#define MPU_COMMON_INT_STAT_MASKED_KEEP_RF_ON_FALL_STAT_MASKED_BIT    ((uint32_t)0x00080000)
#define MPU_COMMON_INT_STAT_MASKED_KEEP_RF_ON_FALL_STAT_MASKED_POS    19
#define MPU_COMMON_INT_STAT_MASKED_SERVICE_UP_STAT_MASKED_BIT    ((uint32_t)0x00040000)
#define MPU_COMMON_INT_STAT_MASKED_SERVICE_UP_STAT_MASKED_POS    18
#define MPU_COMMON_INT_STAT_MASKED_TX_VECTOR_UP_STAT_MASKED_BIT    ((uint32_t)0x00020000)
#define MPU_COMMON_INT_STAT_MASKED_TX_VECTOR_UP_STAT_MASKED_POS    17
#define MPU_COMMON_INT_STAT_MASKED_TX_OVERFLOW_STAT_MASKED_BIT    ((uint32_t)0x00010000)
#define MPU_COMMON_INT_STAT_MASKED_TX_OVERFLOW_STAT_MASKED_POS    16
#define MPU_COMMON_INT_STAT_MASKED_CRC_PARITY_ERR_STAT_MASKED_BIT    ((uint32_t)0x00008000)
#define MPU_COMMON_INT_STAT_MASKED_CRC_PARITY_ERR_STAT_MASKED_POS    15
#define MPU_COMMON_INT_STAT_MASKED_LMAC_INT_1_STAT_MASKED_BIT    ((uint32_t)0x00004000)
#define MPU_COMMON_INT_STAT_MASKED_LMAC_INT_1_STAT_MASKED_POS    14
#define MPU_COMMON_INT_STAT_MASKED_SMAC_INT_1_STAT_MASKED_BIT    ((uint32_t)0x00002000)
#define MPU_COMMON_INT_STAT_MASKED_SMAC_INT_1_STAT_MASKED_POS    13
#define MPU_COMMON_INT_STAT_MASKED_UMAC_INT_1_STAT_MASKED_BIT    ((uint32_t)0x00001000)
#define MPU_COMMON_INT_STAT_MASKED_UMAC_INT_1_STAT_MASKED_POS    12
#define MPU_COMMON_INT_STAT_MASKED_TX_VECTOR_2_UP_STAT_MASKED_BIT    ((uint32_t)0x00000800)
#define MPU_COMMON_INT_STAT_MASKED_TX_VECTOR_2_UP_STAT_MASKED_POS    11
#define MPU_COMMON_INT_STAT_MASKED_RX_VECTOR_UP_STAT_MASKED_BIT    ((uint32_t)0x00000400)
#define MPU_COMMON_INT_STAT_MASKED_RX_VECTOR_UP_STAT_MASKED_POS    10
#define MPU_COMMON_INT_STAT_MASKED_SIGB_DONE_STAT_MASKED_BIT    ((uint32_t)0x00000080)
#define MPU_COMMON_INT_STAT_MASKED_SIGB_DONE_STAT_MASKED_POS    7
#define MPU_COMMON_INT_STAT_MASKED_MPU_ERR_STAT_MASKED_BIT    ((uint32_t)0x00000040)
#define MPU_COMMON_INT_STAT_MASKED_MPU_ERR_STAT_MASKED_POS    6
#define MPU_COMMON_INT_STAT_MASKED_LMAC_INT_2_STAT_MASKED_BIT    ((uint32_t)0x00000010)
#define MPU_COMMON_INT_STAT_MASKED_LMAC_INT_2_STAT_MASKED_POS    4
#define MPU_COMMON_INT_STAT_MASKED_SMAC_INT_2_STAT_MASKED_BIT    ((uint32_t)0x00000008)
#define MPU_COMMON_INT_STAT_MASKED_SMAC_INT_2_STAT_MASKED_POS    3
#define MPU_COMMON_INT_STAT_MASKED_UMAC_INT_2_STAT_MASKED_BIT    ((uint32_t)0x00000004)
#define MPU_COMMON_INT_STAT_MASKED_UMAC_INT_2_STAT_MASKED_POS    2

#define MPU_COMMON_INT_STAT_MASKED_TX_REQ_RISE_STAT_MASKED_RST    0x0
#define MPU_COMMON_INT_STAT_MASKED_TX_REQ_FALL_STAT_MASKED_RST    0x0
#define MPU_COMMON_INT_STAT_MASKED_RX_REQ_RISE_STAT_MASKED_RST    0x0
#define MPU_COMMON_INT_STAT_MASKED_RX_REQ_FALL_STAT_MASKED_RST    0x0
#define MPU_COMMON_INT_STAT_MASKED_LMAC_INT_0_STAT_MASKED_RST    0x0
#define MPU_COMMON_INT_STAT_MASKED_SMAC_INT_0_STAT_MASKED_RST    0x0
#define MPU_COMMON_INT_STAT_MASKED_UMAC_INT_0_STAT_MASKED_RST    0x0
#define MPU_COMMON_INT_STAT_MASKED_RX_REQ_LOW_FLAG_STAT_MASKED_RST    0x0
#define MPU_COMMON_INT_STAT_MASKED_KEEP_RF_ON_RISE_STAT_MASKED_RST    0x0
#define MPU_COMMON_INT_STAT_MASKED_KEEP_RF_ON_FALL_STAT_MASKED_RST    0x0
#define MPU_COMMON_INT_STAT_MASKED_SERVICE_UP_STAT_MASKED_RST    0x0
#define MPU_COMMON_INT_STAT_MASKED_TX_VECTOR_UP_STAT_MASKED_RST    0x0
#define MPU_COMMON_INT_STAT_MASKED_TX_OVERFLOW_STAT_MASKED_RST    0x0
#define MPU_COMMON_INT_STAT_MASKED_CRC_PARITY_ERR_STAT_MASKED_RST    0x0
#define MPU_COMMON_INT_STAT_MASKED_LMAC_INT_1_STAT_MASKED_RST    0x0
#define MPU_COMMON_INT_STAT_MASKED_SMAC_INT_1_STAT_MASKED_RST    0x0
#define MPU_COMMON_INT_STAT_MASKED_UMAC_INT_1_STAT_MASKED_RST    0x0
#define MPU_COMMON_INT_STAT_MASKED_TX_VECTOR_2_UP_STAT_MASKED_RST    0x0
#define MPU_COMMON_INT_STAT_MASKED_RX_VECTOR_UP_STAT_MASKED_RST    0x0
#define MPU_COMMON_INT_STAT_MASKED_SIGB_DONE_STAT_MASKED_RST    0x0
#define MPU_COMMON_INT_STAT_MASKED_MPU_ERR_STAT_MASKED_RST    0x0
#define MPU_COMMON_INT_STAT_MASKED_LMAC_INT_2_STAT_MASKED_RST    0x0
#define MPU_COMMON_INT_STAT_MASKED_SMAC_INT_2_STAT_MASKED_RST    0x0
#define MPU_COMMON_INT_STAT_MASKED_UMAC_INT_2_STAT_MASKED_RST    0x0

__INLINE void mpu_common_int_stat_masked_unpack(uint8_t* tx_req_rise_stat_masked, uint8_t* tx_req_fall_stat_masked, uint8_t* rx_req_rise_stat_masked, uint8_t* rx_req_fall_stat_masked, uint8_t* lmac_int0_stat_masked, uint8_t* smac_int0_stat_masked, uint8_t* umac_int0_stat_masked, uint8_t* rx_req_low_flag_stat_masked, uint8_t* keep_rf_on_rise_stat_masked, uint8_t* keep_rf_on_fall_stat_masked, uint8_t* service_up_stat_masked, uint8_t* tx_vector_up_stat_masked, uint8_t* tx_overflow_stat_masked, uint8_t* crc_parity_err_stat_masked, uint8_t* lmac_int1_stat_masked, uint8_t* smac_int1_stat_masked, uint8_t* umac_int1_stat_masked, uint8_t* tx_vector2_up_stat_masked, uint8_t* rx_vector_up_stat_masked, uint8_t* sigb_done_stat_masked, uint8_t* mpu_err_stat_masked, uint8_t* lmac_int2_stat_masked, uint8_t* smac_int2_stat_masked, uint8_t* umac_int2_stat_masked)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_MASKED_ADDR);

	*tx_req_rise_stat_masked = (localVal & ((uint32_t)0x20000000)) >>  29;
	*tx_req_fall_stat_masked = (localVal & ((uint32_t)0x10000000)) >>  28;
	*rx_req_rise_stat_masked = (localVal & ((uint32_t)0x08000000)) >>  27;
	*rx_req_fall_stat_masked = (localVal & ((uint32_t)0x04000000)) >>  26;
	*lmac_int0_stat_masked = (localVal & ((uint32_t)0x02000000)) >>  25;
	*smac_int0_stat_masked = (localVal & ((uint32_t)0x01000000)) >>  24;
	*umac_int0_stat_masked = (localVal & ((uint32_t)0x00800000)) >>  23;
	*rx_req_low_flag_stat_masked = (localVal & ((uint32_t)0x00400000)) >>  22;
	*keep_rf_on_rise_stat_masked = (localVal & ((uint32_t)0x00100000)) >>  20;
	*keep_rf_on_fall_stat_masked = (localVal & ((uint32_t)0x00080000)) >>  19;
	*service_up_stat_masked = (localVal & ((uint32_t)0x00040000)) >>  18;
	*tx_vector_up_stat_masked = (localVal & ((uint32_t)0x00020000)) >>  17;
	*tx_overflow_stat_masked = (localVal & ((uint32_t)0x00010000)) >>  16;
	*crc_parity_err_stat_masked = (localVal & ((uint32_t)0x00008000)) >>  15;
	*lmac_int1_stat_masked = (localVal & ((uint32_t)0x00004000)) >>  14;
	*smac_int1_stat_masked = (localVal & ((uint32_t)0x00002000)) >>  13;
	*umac_int1_stat_masked = (localVal & ((uint32_t)0x00001000)) >>  12;
	*tx_vector2_up_stat_masked = (localVal & ((uint32_t)0x00000800)) >>  11;
	*rx_vector_up_stat_masked = (localVal & ((uint32_t)0x00000400)) >>  10;
	*sigb_done_stat_masked = (localVal & ((uint32_t)0x00000080)) >>  7;
	*mpu_err_stat_masked = (localVal & ((uint32_t)0x00000040)) >>  6;
	*lmac_int2_stat_masked = (localVal & ((uint32_t)0x00000010)) >>  4;
	*smac_int2_stat_masked = (localVal & ((uint32_t)0x00000008)) >>  3;
	*umac_int2_stat_masked = (localVal & ((uint32_t)0x00000004)) >>  2;
}

__INLINE uint8_t mpu_common_int_stat_masked_tx_req_rise_stat_masked_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_MASKED_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x20000000)) >> 29);
}
__INLINE uint8_t mpu_common_int_stat_masked_tx_req_fall_stat_masked_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_MASKED_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x10000000)) >> 28);
}
__INLINE uint8_t mpu_common_int_stat_masked_rx_req_rise_stat_masked_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_MASKED_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x08000000)) >> 27);
}
__INLINE uint8_t mpu_common_int_stat_masked_rx_req_fall_stat_masked_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_MASKED_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x04000000)) >> 26);
}
__INLINE uint8_t mpu_common_int_stat_masked_lmac_int_0_stat_masked_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_MASKED_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x02000000)) >> 25);
}
__INLINE uint8_t mpu_common_int_stat_masked_smac_int_0_stat_masked_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_MASKED_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01000000)) >> 24);
}
__INLINE uint8_t mpu_common_int_stat_masked_umac_int_0_stat_masked_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_MASKED_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00800000)) >> 23);
}
__INLINE uint8_t mpu_common_int_stat_masked_rx_req_low_flag_stat_masked_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_MASKED_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00400000)) >> 22);
}
__INLINE uint8_t mpu_common_int_stat_masked_keep_rf_on_rise_stat_masked_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_MASKED_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00100000)) >> 20);
}
__INLINE uint8_t mpu_common_int_stat_masked_keep_rf_on_fall_stat_masked_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_MASKED_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00080000)) >> 19);
}
__INLINE uint8_t mpu_common_int_stat_masked_service_up_stat_masked_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_MASKED_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00040000)) >> 18);
}
__INLINE uint8_t mpu_common_int_stat_masked_tx_vector_up_stat_masked_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_MASKED_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00020000)) >> 17);
}
__INLINE uint8_t mpu_common_int_stat_masked_tx_overflow_stat_masked_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_MASKED_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE uint8_t mpu_common_int_stat_masked_crc_parity_err_stat_masked_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_MASKED_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE uint8_t mpu_common_int_stat_masked_lmac_int_1_stat_masked_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_MASKED_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE uint8_t mpu_common_int_stat_masked_smac_int_1_stat_masked_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_MASKED_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE uint8_t mpu_common_int_stat_masked_umac_int_1_stat_masked_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_MASKED_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE uint8_t mpu_common_int_stat_masked_tx_vector_2_up_stat_masked_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_MASKED_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE uint8_t mpu_common_int_stat_masked_rx_vector_up_stat_masked_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_MASKED_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE uint8_t mpu_common_int_stat_masked_sigb_done_stat_masked_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_MASKED_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE uint8_t mpu_common_int_stat_masked_mpu_err_stat_masked_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_MASKED_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE uint8_t mpu_common_int_stat_masked_lmac_int_2_stat_masked_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_MASKED_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE uint8_t mpu_common_int_stat_masked_smac_int_2_stat_masked_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_MASKED_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE uint8_t mpu_common_int_stat_masked_umac_int_2_stat_masked_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_MASKED_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}

/**
 * @brief INT_STAT_RAW register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    29    TX_REQ_RISE_STAT_RAW      0              
 *    28    TX_REQ_FALL_STAT_RAW      0              
 *    27    RX_REQ_RISE_STAT_RAW      0              
 *    26    RX_REQ_FALL_STAT_RAW      0              
 *    25    LMAC_INT0_STAT_RAW        0              
 *    24    SMAC_INT0_STAT_RAW        0              
 *    23    UMAC_INT0_STAT_RAW        0              
 *    22    RX_REQ_LOW_FLAG_STAT_RAW  0              
 *    20    KEEP_RF_ON_RISE_STAT_RAW  0              
 *    19    KEEP_RF_ON_FALL_STAT_RAW  0              
 *    18    SERVICE_UP_STAT_RAW       0              
 *    17    TX_VECTOR_UP_STAT_RAW     0              
 *    16    TX_OVERFLOW_STAT_RAW      0              
 *    15    CRC_PARITY_ERR_STAT_RAW   0              
 *    14    LMAC_INT1_STAT_RAW        0              
 *    13    SMAC_INT1_STAT_RAW        0              
 *    12    UMAC_INT1_STAT_RAW        0              
 *    11    TX_VECTOR2_UP_STAT_RAW    0              
 *    10    RX_VECTOR_UP_STAT_RAW     0              
 *    07    SIGB_DONE_STAT_RAW        0              
 *    06    MPU_ERR_STAT_RAW          0              
 *    04    LMAC_INT2_STAT_RAW        0              
 *    03    SMAC_INT2_STAT_RAW        0              
 *    02    UMAC_INT2_STAT_RAW        0              
 * </pre>
 */
#define MPU_COMMON_INT_STAT_RAW_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x0000007C)
#define MPU_COMMON_INT_STAT_RAW_OFFSET      0x0000007C
#define MPU_COMMON_INT_STAT_RAW_INDEX       0x0000001F
#define MPU_COMMON_INT_STAT_RAW_RESET       0x00000000

__INLINE uint32_t  mpu_common_int_stat_raw_get(void)
{
	return REG_PL_RD(MPU_COMMON_INT_STAT_RAW_ADDR);
}

// field definitions
#define MPU_COMMON_INT_STAT_RAW_TX_REQ_RISE_STAT_RAW_BIT    ((uint32_t)0x20000000)
#define MPU_COMMON_INT_STAT_RAW_TX_REQ_RISE_STAT_RAW_POS    29
#define MPU_COMMON_INT_STAT_RAW_TX_REQ_FALL_STAT_RAW_BIT    ((uint32_t)0x10000000)
#define MPU_COMMON_INT_STAT_RAW_TX_REQ_FALL_STAT_RAW_POS    28
#define MPU_COMMON_INT_STAT_RAW_RX_REQ_RISE_STAT_RAW_BIT    ((uint32_t)0x08000000)
#define MPU_COMMON_INT_STAT_RAW_RX_REQ_RISE_STAT_RAW_POS    27
#define MPU_COMMON_INT_STAT_RAW_RX_REQ_FALL_STAT_RAW_BIT    ((uint32_t)0x04000000)
#define MPU_COMMON_INT_STAT_RAW_RX_REQ_FALL_STAT_RAW_POS    26
#define MPU_COMMON_INT_STAT_RAW_LMAC_INT_0_STAT_RAW_BIT    ((uint32_t)0x02000000)
#define MPU_COMMON_INT_STAT_RAW_LMAC_INT_0_STAT_RAW_POS    25
#define MPU_COMMON_INT_STAT_RAW_SMAC_INT_0_STAT_RAW_BIT    ((uint32_t)0x01000000)
#define MPU_COMMON_INT_STAT_RAW_SMAC_INT_0_STAT_RAW_POS    24
#define MPU_COMMON_INT_STAT_RAW_UMAC_INT_0_STAT_RAW_BIT    ((uint32_t)0x00800000)
#define MPU_COMMON_INT_STAT_RAW_UMAC_INT_0_STAT_RAW_POS    23
#define MPU_COMMON_INT_STAT_RAW_RX_REQ_LOW_FLAG_STAT_RAW_BIT    ((uint32_t)0x00400000)
#define MPU_COMMON_INT_STAT_RAW_RX_REQ_LOW_FLAG_STAT_RAW_POS    22
#define MPU_COMMON_INT_STAT_RAW_KEEP_RF_ON_RISE_STAT_RAW_BIT    ((uint32_t)0x00100000)
#define MPU_COMMON_INT_STAT_RAW_KEEP_RF_ON_RISE_STAT_RAW_POS    20
#define MPU_COMMON_INT_STAT_RAW_KEEP_RF_ON_FALL_STAT_RAW_BIT    ((uint32_t)0x00080000)
#define MPU_COMMON_INT_STAT_RAW_KEEP_RF_ON_FALL_STAT_RAW_POS    19
#define MPU_COMMON_INT_STAT_RAW_SERVICE_UP_STAT_RAW_BIT    ((uint32_t)0x00040000)
#define MPU_COMMON_INT_STAT_RAW_SERVICE_UP_STAT_RAW_POS    18
#define MPU_COMMON_INT_STAT_RAW_TX_VECTOR_UP_STAT_RAW_BIT    ((uint32_t)0x00020000)
#define MPU_COMMON_INT_STAT_RAW_TX_VECTOR_UP_STAT_RAW_POS    17
#define MPU_COMMON_INT_STAT_RAW_TX_OVERFLOW_STAT_RAW_BIT    ((uint32_t)0x00010000)
#define MPU_COMMON_INT_STAT_RAW_TX_OVERFLOW_STAT_RAW_POS    16
#define MPU_COMMON_INT_STAT_RAW_CRC_PARITY_ERR_STAT_RAW_BIT    ((uint32_t)0x00008000)
#define MPU_COMMON_INT_STAT_RAW_CRC_PARITY_ERR_STAT_RAW_POS    15
#define MPU_COMMON_INT_STAT_RAW_LMAC_INT_1_STAT_RAW_BIT    ((uint32_t)0x00004000)
#define MPU_COMMON_INT_STAT_RAW_LMAC_INT_1_STAT_RAW_POS    14
#define MPU_COMMON_INT_STAT_RAW_SMAC_INT_1_STAT_RAW_BIT    ((uint32_t)0x00002000)
#define MPU_COMMON_INT_STAT_RAW_SMAC_INT_1_STAT_RAW_POS    13
#define MPU_COMMON_INT_STAT_RAW_UMAC_INT_1_STAT_RAW_BIT    ((uint32_t)0x00001000)
#define MPU_COMMON_INT_STAT_RAW_UMAC_INT_1_STAT_RAW_POS    12
#define MPU_COMMON_INT_STAT_RAW_TX_VECTOR_2_UP_STAT_RAW_BIT    ((uint32_t)0x00000800)
#define MPU_COMMON_INT_STAT_RAW_TX_VECTOR_2_UP_STAT_RAW_POS    11
#define MPU_COMMON_INT_STAT_RAW_RX_VECTOR_UP_STAT_RAW_BIT    ((uint32_t)0x00000400)
#define MPU_COMMON_INT_STAT_RAW_RX_VECTOR_UP_STAT_RAW_POS    10
#define MPU_COMMON_INT_STAT_RAW_SIGB_DONE_STAT_RAW_BIT    ((uint32_t)0x00000080)
#define MPU_COMMON_INT_STAT_RAW_SIGB_DONE_STAT_RAW_POS    7
#define MPU_COMMON_INT_STAT_RAW_MPU_ERR_STAT_RAW_BIT    ((uint32_t)0x00000040)
#define MPU_COMMON_INT_STAT_RAW_MPU_ERR_STAT_RAW_POS    6
#define MPU_COMMON_INT_STAT_RAW_LMAC_INT_2_STAT_RAW_BIT    ((uint32_t)0x00000010)
#define MPU_COMMON_INT_STAT_RAW_LMAC_INT_2_STAT_RAW_POS    4
#define MPU_COMMON_INT_STAT_RAW_SMAC_INT_2_STAT_RAW_BIT    ((uint32_t)0x00000008)
#define MPU_COMMON_INT_STAT_RAW_SMAC_INT_2_STAT_RAW_POS    3
#define MPU_COMMON_INT_STAT_RAW_UMAC_INT_2_STAT_RAW_BIT    ((uint32_t)0x00000004)
#define MPU_COMMON_INT_STAT_RAW_UMAC_INT_2_STAT_RAW_POS    2

#define MPU_COMMON_INT_STAT_RAW_TX_REQ_RISE_STAT_RAW_RST    0x0
#define MPU_COMMON_INT_STAT_RAW_TX_REQ_FALL_STAT_RAW_RST    0x0
#define MPU_COMMON_INT_STAT_RAW_RX_REQ_RISE_STAT_RAW_RST    0x0
#define MPU_COMMON_INT_STAT_RAW_RX_REQ_FALL_STAT_RAW_RST    0x0
#define MPU_COMMON_INT_STAT_RAW_LMAC_INT_0_STAT_RAW_RST    0x0
#define MPU_COMMON_INT_STAT_RAW_SMAC_INT_0_STAT_RAW_RST    0x0
#define MPU_COMMON_INT_STAT_RAW_UMAC_INT_0_STAT_RAW_RST    0x0
#define MPU_COMMON_INT_STAT_RAW_RX_REQ_LOW_FLAG_STAT_RAW_RST    0x0
#define MPU_COMMON_INT_STAT_RAW_KEEP_RF_ON_RISE_STAT_RAW_RST    0x0
#define MPU_COMMON_INT_STAT_RAW_KEEP_RF_ON_FALL_STAT_RAW_RST    0x0
#define MPU_COMMON_INT_STAT_RAW_SERVICE_UP_STAT_RAW_RST    0x0
#define MPU_COMMON_INT_STAT_RAW_TX_VECTOR_UP_STAT_RAW_RST    0x0
#define MPU_COMMON_INT_STAT_RAW_TX_OVERFLOW_STAT_RAW_RST    0x0
#define MPU_COMMON_INT_STAT_RAW_CRC_PARITY_ERR_STAT_RAW_RST    0x0
#define MPU_COMMON_INT_STAT_RAW_LMAC_INT_1_STAT_RAW_RST    0x0
#define MPU_COMMON_INT_STAT_RAW_SMAC_INT_1_STAT_RAW_RST    0x0
#define MPU_COMMON_INT_STAT_RAW_UMAC_INT_1_STAT_RAW_RST    0x0
#define MPU_COMMON_INT_STAT_RAW_TX_VECTOR_2_UP_STAT_RAW_RST    0x0
#define MPU_COMMON_INT_STAT_RAW_RX_VECTOR_UP_STAT_RAW_RST    0x0
#define MPU_COMMON_INT_STAT_RAW_SIGB_DONE_STAT_RAW_RST    0x0
#define MPU_COMMON_INT_STAT_RAW_MPU_ERR_STAT_RAW_RST    0x0
#define MPU_COMMON_INT_STAT_RAW_LMAC_INT_2_STAT_RAW_RST    0x0
#define MPU_COMMON_INT_STAT_RAW_SMAC_INT_2_STAT_RAW_RST    0x0
#define MPU_COMMON_INT_STAT_RAW_UMAC_INT_2_STAT_RAW_RST    0x0

__INLINE void mpu_common_int_stat_raw_unpack(uint8_t* tx_req_rise_stat_raw, uint8_t* tx_req_fall_stat_raw, uint8_t* rx_req_rise_stat_raw, uint8_t* rx_req_fall_stat_raw, uint8_t* lmac_int0_stat_raw, uint8_t* smac_int0_stat_raw, uint8_t* umac_int0_stat_raw, uint8_t* rx_req_low_flag_stat_raw, uint8_t* keep_rf_on_rise_stat_raw, uint8_t* keep_rf_on_fall_stat_raw, uint8_t* service_up_stat_raw, uint8_t* tx_vector_up_stat_raw, uint8_t* tx_overflow_stat_raw, uint8_t* crc_parity_err_stat_raw, uint8_t* lmac_int1_stat_raw, uint8_t* smac_int1_stat_raw, uint8_t* umac_int1_stat_raw, uint8_t* tx_vector2_up_stat_raw, uint8_t* rx_vector_up_stat_raw, uint8_t* sigb_done_stat_raw, uint8_t* mpu_err_stat_raw, uint8_t* lmac_int2_stat_raw, uint8_t* smac_int2_stat_raw, uint8_t* umac_int2_stat_raw)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_RAW_ADDR);

	*tx_req_rise_stat_raw = (localVal & ((uint32_t)0x20000000)) >>  29;
	*tx_req_fall_stat_raw = (localVal & ((uint32_t)0x10000000)) >>  28;
	*rx_req_rise_stat_raw = (localVal & ((uint32_t)0x08000000)) >>  27;
	*rx_req_fall_stat_raw = (localVal & ((uint32_t)0x04000000)) >>  26;
	*lmac_int0_stat_raw = (localVal & ((uint32_t)0x02000000)) >>  25;
	*smac_int0_stat_raw = (localVal & ((uint32_t)0x01000000)) >>  24;
	*umac_int0_stat_raw = (localVal & ((uint32_t)0x00800000)) >>  23;
	*rx_req_low_flag_stat_raw = (localVal & ((uint32_t)0x00400000)) >>  22;
	*keep_rf_on_rise_stat_raw = (localVal & ((uint32_t)0x00100000)) >>  20;
	*keep_rf_on_fall_stat_raw = (localVal & ((uint32_t)0x00080000)) >>  19;
	*service_up_stat_raw = (localVal & ((uint32_t)0x00040000)) >>  18;
	*tx_vector_up_stat_raw = (localVal & ((uint32_t)0x00020000)) >>  17;
	*tx_overflow_stat_raw = (localVal & ((uint32_t)0x00010000)) >>  16;
	*crc_parity_err_stat_raw = (localVal & ((uint32_t)0x00008000)) >>  15;
	*lmac_int1_stat_raw = (localVal & ((uint32_t)0x00004000)) >>  14;
	*smac_int1_stat_raw = (localVal & ((uint32_t)0x00002000)) >>  13;
	*umac_int1_stat_raw = (localVal & ((uint32_t)0x00001000)) >>  12;
	*tx_vector2_up_stat_raw = (localVal & ((uint32_t)0x00000800)) >>  11;
	*rx_vector_up_stat_raw = (localVal & ((uint32_t)0x00000400)) >>  10;
	*sigb_done_stat_raw = (localVal & ((uint32_t)0x00000080)) >>  7;
	*mpu_err_stat_raw = (localVal & ((uint32_t)0x00000040)) >>  6;
	*lmac_int2_stat_raw = (localVal & ((uint32_t)0x00000010)) >>  4;
	*smac_int2_stat_raw = (localVal & ((uint32_t)0x00000008)) >>  3;
	*umac_int2_stat_raw = (localVal & ((uint32_t)0x00000004)) >>  2;
}

__INLINE uint8_t mpu_common_int_stat_raw_tx_req_rise_stat_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x20000000)) >> 29);
}
__INLINE uint8_t mpu_common_int_stat_raw_tx_req_fall_stat_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x10000000)) >> 28);
}
__INLINE uint8_t mpu_common_int_stat_raw_rx_req_rise_stat_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x08000000)) >> 27);
}
__INLINE uint8_t mpu_common_int_stat_raw_rx_req_fall_stat_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x04000000)) >> 26);
}
__INLINE uint8_t mpu_common_int_stat_raw_lmac_int_0_stat_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x02000000)) >> 25);
}
__INLINE uint8_t mpu_common_int_stat_raw_smac_int_0_stat_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01000000)) >> 24);
}
__INLINE uint8_t mpu_common_int_stat_raw_umac_int_0_stat_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00800000)) >> 23);
}
__INLINE uint8_t mpu_common_int_stat_raw_rx_req_low_flag_stat_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00400000)) >> 22);
}
__INLINE uint8_t mpu_common_int_stat_raw_keep_rf_on_rise_stat_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00100000)) >> 20);
}
__INLINE uint8_t mpu_common_int_stat_raw_keep_rf_on_fall_stat_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00080000)) >> 19);
}
__INLINE uint8_t mpu_common_int_stat_raw_service_up_stat_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00040000)) >> 18);
}
__INLINE uint8_t mpu_common_int_stat_raw_tx_vector_up_stat_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00020000)) >> 17);
}
__INLINE uint8_t mpu_common_int_stat_raw_tx_overflow_stat_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE uint8_t mpu_common_int_stat_raw_crc_parity_err_stat_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE uint8_t mpu_common_int_stat_raw_lmac_int_1_stat_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE uint8_t mpu_common_int_stat_raw_smac_int_1_stat_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE uint8_t mpu_common_int_stat_raw_umac_int_1_stat_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE uint8_t mpu_common_int_stat_raw_tx_vector_2_up_stat_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE uint8_t mpu_common_int_stat_raw_rx_vector_up_stat_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE uint8_t mpu_common_int_stat_raw_sigb_done_stat_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE uint8_t mpu_common_int_stat_raw_mpu_err_stat_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE uint8_t mpu_common_int_stat_raw_lmac_int_2_stat_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE uint8_t mpu_common_int_stat_raw_smac_int_2_stat_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE uint8_t mpu_common_int_stat_raw_umac_int_2_stat_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}

/**
 * @brief INT_CLR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    29    TX_REQ_RISE_CLR           0              
 *    28    TX_REQ_FALL_CLR           0              
 *    27    RX_REQ_RISE_CLR           0              
 *    26    RX_REQ_FALL_CLR           0              
 *    25    LMAC_INT0_CLR             0              
 *    24    SMAC_INT0_CLR             0              
 *    23    UMAC_INT0_CLR             0              
 *    22    RX_REQ_LOW_FLAG_CLR       0              
 *    20    KEEP_RF_ON_RISE_CLR       0              
 *    19    KEEP_RF_ON_FALL_CLR       0              
 *    18    SERVICE_UP_CLR            0              
 *    17    TX_VECTOR_UP_CLR          0              
 *    16    TX_OVERFLOW_CLR           0              
 *    15    CRC_PARITY_ERR_CLR        0              
 *    14    LMAC_INT1_CLR             0              
 *    13    SMAC_INT1_CLR             0              
 *    12    UMAC_INT1_CLR             0              
 *    11    TX_VECTOR2_UP_CLR         0              
 *    10    RX_VECTOR_UP_CLR          0              
 *    07    SIGB_DONE_CLR             0              
 *    06    MPU_ERR_CLR               0              
 *    04    LMAC_INT2_CLR             0              
 *    03    SMAC_INT2_CLR             0              
 *    02    UMAC_INT2_CLR             0              
 * </pre>
 */
#define MPU_COMMON_INT_CLR_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000080)
#define MPU_COMMON_INT_CLR_OFFSET      0x00000080
#define MPU_COMMON_INT_CLR_INDEX       0x00000020
#define MPU_COMMON_INT_CLR_RESET       0x00000000

__INLINE void mpu_common_int_clr_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_INT_CLR_ADDR, value);
}

// field definitions
#define MPU_COMMON_INT_CLR_TX_REQ_RISE_CLR_BIT    ((uint32_t)0x20000000)
#define MPU_COMMON_INT_CLR_TX_REQ_RISE_CLR_POS    29
#define MPU_COMMON_INT_CLR_TX_REQ_FALL_CLR_BIT    ((uint32_t)0x10000000)
#define MPU_COMMON_INT_CLR_TX_REQ_FALL_CLR_POS    28
#define MPU_COMMON_INT_CLR_RX_REQ_RISE_CLR_BIT    ((uint32_t)0x08000000)
#define MPU_COMMON_INT_CLR_RX_REQ_RISE_CLR_POS    27
#define MPU_COMMON_INT_CLR_RX_REQ_FALL_CLR_BIT    ((uint32_t)0x04000000)
#define MPU_COMMON_INT_CLR_RX_REQ_FALL_CLR_POS    26
#define MPU_COMMON_INT_CLR_LMAC_INT_0_CLR_BIT    ((uint32_t)0x02000000)
#define MPU_COMMON_INT_CLR_LMAC_INT_0_CLR_POS    25
#define MPU_COMMON_INT_CLR_SMAC_INT_0_CLR_BIT    ((uint32_t)0x01000000)
#define MPU_COMMON_INT_CLR_SMAC_INT_0_CLR_POS    24
#define MPU_COMMON_INT_CLR_UMAC_INT_0_CLR_BIT    ((uint32_t)0x00800000)
#define MPU_COMMON_INT_CLR_UMAC_INT_0_CLR_POS    23
#define MPU_COMMON_INT_CLR_RX_REQ_LOW_FLAG_CLR_BIT    ((uint32_t)0x00400000)
#define MPU_COMMON_INT_CLR_RX_REQ_LOW_FLAG_CLR_POS    22
#define MPU_COMMON_INT_CLR_KEEP_RF_ON_RISE_CLR_BIT    ((uint32_t)0x00100000)
#define MPU_COMMON_INT_CLR_KEEP_RF_ON_RISE_CLR_POS    20
#define MPU_COMMON_INT_CLR_KEEP_RF_ON_FALL_CLR_BIT    ((uint32_t)0x00080000)
#define MPU_COMMON_INT_CLR_KEEP_RF_ON_FALL_CLR_POS    19
#define MPU_COMMON_INT_CLR_SERVICE_UP_CLR_BIT    ((uint32_t)0x00040000)
#define MPU_COMMON_INT_CLR_SERVICE_UP_CLR_POS    18
#define MPU_COMMON_INT_CLR_TX_VECTOR_UP_CLR_BIT    ((uint32_t)0x00020000)
#define MPU_COMMON_INT_CLR_TX_VECTOR_UP_CLR_POS    17
#define MPU_COMMON_INT_CLR_TX_OVERFLOW_CLR_BIT    ((uint32_t)0x00010000)
#define MPU_COMMON_INT_CLR_TX_OVERFLOW_CLR_POS    16
#define MPU_COMMON_INT_CLR_CRC_PARITY_ERR_CLR_BIT    ((uint32_t)0x00008000)
#define MPU_COMMON_INT_CLR_CRC_PARITY_ERR_CLR_POS    15
#define MPU_COMMON_INT_CLR_LMAC_INT_1_CLR_BIT    ((uint32_t)0x00004000)
#define MPU_COMMON_INT_CLR_LMAC_INT_1_CLR_POS    14
#define MPU_COMMON_INT_CLR_SMAC_INT_1_CLR_BIT    ((uint32_t)0x00002000)
#define MPU_COMMON_INT_CLR_SMAC_INT_1_CLR_POS    13
#define MPU_COMMON_INT_CLR_UMAC_INT_1_CLR_BIT    ((uint32_t)0x00001000)
#define MPU_COMMON_INT_CLR_UMAC_INT_1_CLR_POS    12
#define MPU_COMMON_INT_CLR_TX_VECTOR_2_UP_CLR_BIT    ((uint32_t)0x00000800)
#define MPU_COMMON_INT_CLR_TX_VECTOR_2_UP_CLR_POS    11
#define MPU_COMMON_INT_CLR_RX_VECTOR_UP_CLR_BIT    ((uint32_t)0x00000400)
#define MPU_COMMON_INT_CLR_RX_VECTOR_UP_CLR_POS    10
#define MPU_COMMON_INT_CLR_SIGB_DONE_CLR_BIT    ((uint32_t)0x00000080)
#define MPU_COMMON_INT_CLR_SIGB_DONE_CLR_POS    7
#define MPU_COMMON_INT_CLR_MPU_ERR_CLR_BIT    ((uint32_t)0x00000040)
#define MPU_COMMON_INT_CLR_MPU_ERR_CLR_POS    6
#define MPU_COMMON_INT_CLR_LMAC_INT_2_CLR_BIT    ((uint32_t)0x00000010)
#define MPU_COMMON_INT_CLR_LMAC_INT_2_CLR_POS    4
#define MPU_COMMON_INT_CLR_SMAC_INT_2_CLR_BIT    ((uint32_t)0x00000008)
#define MPU_COMMON_INT_CLR_SMAC_INT_2_CLR_POS    3
#define MPU_COMMON_INT_CLR_UMAC_INT_2_CLR_BIT    ((uint32_t)0x00000004)
#define MPU_COMMON_INT_CLR_UMAC_INT_2_CLR_POS    2

#define MPU_COMMON_INT_CLR_TX_REQ_RISE_CLR_RST    0x0
#define MPU_COMMON_INT_CLR_TX_REQ_FALL_CLR_RST    0x0
#define MPU_COMMON_INT_CLR_RX_REQ_RISE_CLR_RST    0x0
#define MPU_COMMON_INT_CLR_RX_REQ_FALL_CLR_RST    0x0
#define MPU_COMMON_INT_CLR_LMAC_INT_0_CLR_RST    0x0
#define MPU_COMMON_INT_CLR_SMAC_INT_0_CLR_RST    0x0
#define MPU_COMMON_INT_CLR_UMAC_INT_0_CLR_RST    0x0
#define MPU_COMMON_INT_CLR_RX_REQ_LOW_FLAG_CLR_RST    0x0
#define MPU_COMMON_INT_CLR_KEEP_RF_ON_RISE_CLR_RST    0x0
#define MPU_COMMON_INT_CLR_KEEP_RF_ON_FALL_CLR_RST    0x0
#define MPU_COMMON_INT_CLR_SERVICE_UP_CLR_RST    0x0
#define MPU_COMMON_INT_CLR_TX_VECTOR_UP_CLR_RST    0x0
#define MPU_COMMON_INT_CLR_TX_OVERFLOW_CLR_RST    0x0
#define MPU_COMMON_INT_CLR_CRC_PARITY_ERR_CLR_RST    0x0
#define MPU_COMMON_INT_CLR_LMAC_INT_1_CLR_RST    0x0
#define MPU_COMMON_INT_CLR_SMAC_INT_1_CLR_RST    0x0
#define MPU_COMMON_INT_CLR_UMAC_INT_1_CLR_RST    0x0
#define MPU_COMMON_INT_CLR_TX_VECTOR_2_UP_CLR_RST    0x0
#define MPU_COMMON_INT_CLR_RX_VECTOR_UP_CLR_RST    0x0
#define MPU_COMMON_INT_CLR_SIGB_DONE_CLR_RST    0x0
#define MPU_COMMON_INT_CLR_MPU_ERR_CLR_RST    0x0
#define MPU_COMMON_INT_CLR_LMAC_INT_2_CLR_RST    0x0
#define MPU_COMMON_INT_CLR_SMAC_INT_2_CLR_RST    0x0
#define MPU_COMMON_INT_CLR_UMAC_INT_2_CLR_RST    0x0

__INLINE void mpu_common_int_clr_pack(uint8_t tx_req_rise_clr, uint8_t tx_req_fall_clr, uint8_t rx_req_rise_clr, uint8_t rx_req_fall_clr, uint8_t lmac_int0_clr, uint8_t smac_int0_clr, uint8_t umac_int0_clr, uint8_t rx_req_low_flag_clr, uint8_t keep_rf_on_rise_clr, uint8_t keep_rf_on_fall_clr, uint8_t service_up_clr, uint8_t tx_vector_up_clr, uint8_t tx_overflow_clr, uint8_t crc_parity_err_clr, uint8_t lmac_int1_clr, uint8_t smac_int1_clr, uint8_t umac_int1_clr, uint8_t tx_vector2_up_clr, uint8_t rx_vector_up_clr, uint8_t sigb_done_clr, uint8_t mpu_err_clr, uint8_t lmac_int2_clr, uint8_t smac_int2_clr, uint8_t umac_int2_clr)
{
	ASSERT_ERR((((uint32_t)tx_req_rise_clr << 29) & ~((uint32_t)0x20000000)) == 0);
	ASSERT_ERR((((uint32_t)tx_req_fall_clr << 28) & ~((uint32_t)0x10000000)) == 0);
	ASSERT_ERR((((uint32_t)rx_req_rise_clr << 27) & ~((uint32_t)0x08000000)) == 0);
	ASSERT_ERR((((uint32_t)rx_req_fall_clr << 26) & ~((uint32_t)0x04000000)) == 0);
	ASSERT_ERR((((uint32_t)lmac_int0_clr << 25) & ~((uint32_t)0x02000000)) == 0);
	ASSERT_ERR((((uint32_t)smac_int0_clr << 24) & ~((uint32_t)0x01000000)) == 0);
	ASSERT_ERR((((uint32_t)umac_int0_clr << 23) & ~((uint32_t)0x00800000)) == 0);
	ASSERT_ERR((((uint32_t)rx_req_low_flag_clr << 22) & ~((uint32_t)0x00400000)) == 0);
	ASSERT_ERR((((uint32_t)keep_rf_on_rise_clr << 20) & ~((uint32_t)0x00100000)) == 0);
	ASSERT_ERR((((uint32_t)keep_rf_on_fall_clr << 19) & ~((uint32_t)0x00080000)) == 0);
	ASSERT_ERR((((uint32_t)service_up_clr << 18) & ~((uint32_t)0x00040000)) == 0);
	ASSERT_ERR((((uint32_t)tx_vector_up_clr << 17) & ~((uint32_t)0x00020000)) == 0);
	ASSERT_ERR((((uint32_t)tx_overflow_clr << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)crc_parity_err_clr << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)lmac_int1_clr << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)smac_int1_clr << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)umac_int1_clr << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)tx_vector2_up_clr << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)rx_vector_up_clr << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)sigb_done_clr << 7) & ~((uint32_t)0x00000080)) == 0);
	ASSERT_ERR((((uint32_t)mpu_err_clr << 6) & ~((uint32_t)0x00000040)) == 0);
	ASSERT_ERR((((uint32_t)lmac_int2_clr << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)smac_int2_clr << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)umac_int2_clr << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(MPU_COMMON_INT_CLR_ADDR,  ((uint32_t)tx_req_rise_clr << 29) |((uint32_t)tx_req_fall_clr << 28) |((uint32_t)rx_req_rise_clr << 27) |((uint32_t)rx_req_fall_clr << 26) |((uint32_t)lmac_int0_clr << 25) |((uint32_t)smac_int0_clr << 24) |((uint32_t)umac_int0_clr << 23) |((uint32_t)rx_req_low_flag_clr << 22) |((uint32_t)keep_rf_on_rise_clr << 20) |((uint32_t)keep_rf_on_fall_clr << 19) |((uint32_t)service_up_clr << 18) |((uint32_t)tx_vector_up_clr << 17) |((uint32_t)tx_overflow_clr << 16) |((uint32_t)crc_parity_err_clr << 15) |((uint32_t)lmac_int1_clr << 14) |((uint32_t)smac_int1_clr << 13) |((uint32_t)umac_int1_clr << 12) |((uint32_t)tx_vector2_up_clr << 11) |((uint32_t)rx_vector_up_clr << 10) |((uint32_t)sigb_done_clr << 7) |((uint32_t)mpu_err_clr << 6) |((uint32_t)lmac_int2_clr << 4) |((uint32_t)smac_int2_clr << 3) |((uint32_t)umac_int2_clr << 2));
}

__INLINE void mpu_common_int_clr_tx_req_rise_clr_setf(uint8_t txreqriseclr)
{
	ASSERT_ERR((((uint32_t)txreqriseclr << 29) & ~((uint32_t)0x20000000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_CLR_ADDR, (REG_PL_RD(MPU_COMMON_INT_CLR_ADDR) & ~((uint32_t)0x20000000)) | ((uint32_t)txreqriseclr <<29));
}
__INLINE void mpu_common_int_clr_tx_req_fall_clr_setf(uint8_t txreqfallclr)
{
	ASSERT_ERR((((uint32_t)txreqfallclr << 28) & ~((uint32_t)0x10000000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_CLR_ADDR, (REG_PL_RD(MPU_COMMON_INT_CLR_ADDR) & ~((uint32_t)0x10000000)) | ((uint32_t)txreqfallclr <<28));
}
__INLINE void mpu_common_int_clr_rx_req_rise_clr_setf(uint8_t rxreqriseclr)
{
	ASSERT_ERR((((uint32_t)rxreqriseclr << 27) & ~((uint32_t)0x08000000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_CLR_ADDR, (REG_PL_RD(MPU_COMMON_INT_CLR_ADDR) & ~((uint32_t)0x08000000)) | ((uint32_t)rxreqriseclr <<27));
}
__INLINE void mpu_common_int_clr_rx_req_fall_clr_setf(uint8_t rxreqfallclr)
{
	ASSERT_ERR((((uint32_t)rxreqfallclr << 26) & ~((uint32_t)0x04000000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_CLR_ADDR, (REG_PL_RD(MPU_COMMON_INT_CLR_ADDR) & ~((uint32_t)0x04000000)) | ((uint32_t)rxreqfallclr <<26));
}
__INLINE void mpu_common_int_clr_lmac_int_0_clr_setf(uint8_t lmacint0clr)
{
	ASSERT_ERR((((uint32_t)lmacint0clr << 25) & ~((uint32_t)0x02000000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_CLR_ADDR, (REG_PL_RD(MPU_COMMON_INT_CLR_ADDR) & ~((uint32_t)0x02000000)) | ((uint32_t)lmacint0clr <<25));
}
__INLINE void mpu_common_int_clr_smac_int_0_clr_setf(uint8_t smacint0clr)
{
	ASSERT_ERR((((uint32_t)smacint0clr << 24) & ~((uint32_t)0x01000000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_CLR_ADDR, (REG_PL_RD(MPU_COMMON_INT_CLR_ADDR) & ~((uint32_t)0x01000000)) | ((uint32_t)smacint0clr <<24));
}
__INLINE void mpu_common_int_clr_umac_int_0_clr_setf(uint8_t umacint0clr)
{
	ASSERT_ERR((((uint32_t)umacint0clr << 23) & ~((uint32_t)0x00800000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_CLR_ADDR, (REG_PL_RD(MPU_COMMON_INT_CLR_ADDR) & ~((uint32_t)0x00800000)) | ((uint32_t)umacint0clr <<23));
}
__INLINE void mpu_common_int_clr_rx_req_low_flag_clr_setf(uint8_t rxreqlowflagclr)
{
	ASSERT_ERR((((uint32_t)rxreqlowflagclr << 22) & ~((uint32_t)0x00400000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_CLR_ADDR, (REG_PL_RD(MPU_COMMON_INT_CLR_ADDR) & ~((uint32_t)0x00400000)) | ((uint32_t)rxreqlowflagclr <<22));
}
__INLINE void mpu_common_int_clr_keep_rf_on_rise_clr_setf(uint8_t keeprfonriseclr)
{
	ASSERT_ERR((((uint32_t)keeprfonriseclr << 20) & ~((uint32_t)0x00100000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_CLR_ADDR, (REG_PL_RD(MPU_COMMON_INT_CLR_ADDR) & ~((uint32_t)0x00100000)) | ((uint32_t)keeprfonriseclr <<20));
}
__INLINE void mpu_common_int_clr_keep_rf_on_fall_clr_setf(uint8_t keeprfonfallclr)
{
	ASSERT_ERR((((uint32_t)keeprfonfallclr << 19) & ~((uint32_t)0x00080000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_CLR_ADDR, (REG_PL_RD(MPU_COMMON_INT_CLR_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)keeprfonfallclr <<19));
}
__INLINE void mpu_common_int_clr_service_up_clr_setf(uint8_t serviceupclr)
{
	ASSERT_ERR((((uint32_t)serviceupclr << 18) & ~((uint32_t)0x00040000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_CLR_ADDR, (REG_PL_RD(MPU_COMMON_INT_CLR_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)serviceupclr <<18));
}
__INLINE void mpu_common_int_clr_tx_vector_up_clr_setf(uint8_t txvectorupclr)
{
	ASSERT_ERR((((uint32_t)txvectorupclr << 17) & ~((uint32_t)0x00020000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_CLR_ADDR, (REG_PL_RD(MPU_COMMON_INT_CLR_ADDR) & ~((uint32_t)0x00020000)) | ((uint32_t)txvectorupclr <<17));
}
__INLINE void mpu_common_int_clr_tx_overflow_clr_setf(uint8_t txoverflowclr)
{
	ASSERT_ERR((((uint32_t)txoverflowclr << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_CLR_ADDR, (REG_PL_RD(MPU_COMMON_INT_CLR_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)txoverflowclr <<16));
}
__INLINE void mpu_common_int_clr_crc_parity_err_clr_setf(uint8_t crcparityerrclr)
{
	ASSERT_ERR((((uint32_t)crcparityerrclr << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_CLR_ADDR, (REG_PL_RD(MPU_COMMON_INT_CLR_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)crcparityerrclr <<15));
}
__INLINE void mpu_common_int_clr_lmac_int_1_clr_setf(uint8_t lmacint1clr)
{
	ASSERT_ERR((((uint32_t)lmacint1clr << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_CLR_ADDR, (REG_PL_RD(MPU_COMMON_INT_CLR_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)lmacint1clr <<14));
}
__INLINE void mpu_common_int_clr_smac_int_1_clr_setf(uint8_t smacint1clr)
{
	ASSERT_ERR((((uint32_t)smacint1clr << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_CLR_ADDR, (REG_PL_RD(MPU_COMMON_INT_CLR_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)smacint1clr <<13));
}
__INLINE void mpu_common_int_clr_umac_int_1_clr_setf(uint8_t umacint1clr)
{
	ASSERT_ERR((((uint32_t)umacint1clr << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_CLR_ADDR, (REG_PL_RD(MPU_COMMON_INT_CLR_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)umacint1clr <<12));
}
__INLINE void mpu_common_int_clr_tx_vector_2_up_clr_setf(uint8_t txvector2upclr)
{
	ASSERT_ERR((((uint32_t)txvector2upclr << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(MPU_COMMON_INT_CLR_ADDR, (REG_PL_RD(MPU_COMMON_INT_CLR_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)txvector2upclr <<11));
}
__INLINE void mpu_common_int_clr_rx_vector_up_clr_setf(uint8_t rxvectorupclr)
{
	ASSERT_ERR((((uint32_t)rxvectorupclr << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(MPU_COMMON_INT_CLR_ADDR, (REG_PL_RD(MPU_COMMON_INT_CLR_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)rxvectorupclr <<10));
}
__INLINE void mpu_common_int_clr_sigb_done_clr_setf(uint8_t sigbdoneclr)
{
	ASSERT_ERR((((uint32_t)sigbdoneclr << 7) & ~((uint32_t)0x00000080)) == 0);
	REG_PL_WR(MPU_COMMON_INT_CLR_ADDR, (REG_PL_RD(MPU_COMMON_INT_CLR_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)sigbdoneclr <<7));
}
__INLINE void mpu_common_int_clr_mpu_err_clr_setf(uint8_t mpuerrclr)
{
	ASSERT_ERR((((uint32_t)mpuerrclr << 6) & ~((uint32_t)0x00000040)) == 0);
	REG_PL_WR(MPU_COMMON_INT_CLR_ADDR, (REG_PL_RD(MPU_COMMON_INT_CLR_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)mpuerrclr <<6));
}
__INLINE void mpu_common_int_clr_lmac_int_2_clr_setf(uint8_t lmacint2clr)
{
	ASSERT_ERR((((uint32_t)lmacint2clr << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(MPU_COMMON_INT_CLR_ADDR, (REG_PL_RD(MPU_COMMON_INT_CLR_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)lmacint2clr <<4));
}
__INLINE void mpu_common_int_clr_smac_int_2_clr_setf(uint8_t smacint2clr)
{
	ASSERT_ERR((((uint32_t)smacint2clr << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(MPU_COMMON_INT_CLR_ADDR, (REG_PL_RD(MPU_COMMON_INT_CLR_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)smacint2clr <<3));
}
__INLINE void mpu_common_int_clr_umac_int_2_clr_setf(uint8_t umacint2clr)
{
	ASSERT_ERR((((uint32_t)umacint2clr << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(MPU_COMMON_INT_CLR_ADDR, (REG_PL_RD(MPU_COMMON_INT_CLR_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)umacint2clr <<2));
}

/**
 * @brief INT_GEN_SW register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    29    TX_REQ_RISE_GEN           0              
 *    28    TX_REQ_FALL_GEN           0              
 *    27    RX_REQ_RISE_GEN           0              
 *    26    RX_REQ_FALL_GEN           0              
 *    25    LMAC_INT0_GEN             0              
 *    24    SMAC_INT0_GEN             0              
 *    23    UMAC_INT0_GEN             0              
 *    22    RX_REQ_LOW_FLAG_GEN       0              
 *    20    KEEP_RF_ON_RISE_GEN       0              
 *    19    KEEP_RF_ON_FALL_GEN       0              
 *    18    SERVICE_UP_GEN            0              
 *    17    TX_VECTOR_UP_GEN          0              
 *    16    TX_OVERFLOW_GEN           0              
 *    15    CRC_PARITY_ERR_GEN        0              
 *    14    LMAC_INT1_GEN             0              
 *    13    SMAC_INT1_GEN             0              
 *    12    UMAC_INT1_GEN             0              
 *    11    TX_VECTOR2_UP_GEN         0              
 *    10    RX_VECTOR_UP_GEN          0              
 *    07    SIGB_GEN_DONE_GEN         0              
 *    06    MPU_ERR_GEN               0              
 *    04    LMAC_INT2_GEN             0              
 *    03    SMAC_INT2_GEN             0              
 *    02    UMAC_INT2_GEN             0              
 * </pre>
 */
#define MPU_COMMON_INT_GEN_SW_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000084)
#define MPU_COMMON_INT_GEN_SW_OFFSET      0x00000084
#define MPU_COMMON_INT_GEN_SW_INDEX       0x00000021
#define MPU_COMMON_INT_GEN_SW_RESET       0x00000000

__INLINE void mpu_common_int_gen_sw_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_INT_GEN_SW_ADDR, value);
}

// field definitions
#define MPU_COMMON_INT_GEN_SW_TX_REQ_RISE_GEN_BIT    ((uint32_t)0x20000000)
#define MPU_COMMON_INT_GEN_SW_TX_REQ_RISE_GEN_POS    29
#define MPU_COMMON_INT_GEN_SW_TX_REQ_FALL_GEN_BIT    ((uint32_t)0x10000000)
#define MPU_COMMON_INT_GEN_SW_TX_REQ_FALL_GEN_POS    28
#define MPU_COMMON_INT_GEN_SW_RX_REQ_RISE_GEN_BIT    ((uint32_t)0x08000000)
#define MPU_COMMON_INT_GEN_SW_RX_REQ_RISE_GEN_POS    27
#define MPU_COMMON_INT_GEN_SW_RX_REQ_FALL_GEN_BIT    ((uint32_t)0x04000000)
#define MPU_COMMON_INT_GEN_SW_RX_REQ_FALL_GEN_POS    26
#define MPU_COMMON_INT_GEN_SW_LMAC_INT_0_GEN_BIT    ((uint32_t)0x02000000)
#define MPU_COMMON_INT_GEN_SW_LMAC_INT_0_GEN_POS    25
#define MPU_COMMON_INT_GEN_SW_SMAC_INT_0_GEN_BIT    ((uint32_t)0x01000000)
#define MPU_COMMON_INT_GEN_SW_SMAC_INT_0_GEN_POS    24
#define MPU_COMMON_INT_GEN_SW_UMAC_INT_0_GEN_BIT    ((uint32_t)0x00800000)
#define MPU_COMMON_INT_GEN_SW_UMAC_INT_0_GEN_POS    23
#define MPU_COMMON_INT_GEN_SW_RX_REQ_LOW_FLAG_GEN_BIT    ((uint32_t)0x00400000)
#define MPU_COMMON_INT_GEN_SW_RX_REQ_LOW_FLAG_GEN_POS    22
#define MPU_COMMON_INT_GEN_SW_KEEP_RF_ON_RISE_GEN_BIT    ((uint32_t)0x00100000)
#define MPU_COMMON_INT_GEN_SW_KEEP_RF_ON_RISE_GEN_POS    20
#define MPU_COMMON_INT_GEN_SW_KEEP_RF_ON_FALL_GEN_BIT    ((uint32_t)0x00080000)
#define MPU_COMMON_INT_GEN_SW_KEEP_RF_ON_FALL_GEN_POS    19
#define MPU_COMMON_INT_GEN_SW_SERVICE_UP_GEN_BIT    ((uint32_t)0x00040000)
#define MPU_COMMON_INT_GEN_SW_SERVICE_UP_GEN_POS    18
#define MPU_COMMON_INT_GEN_SW_TX_VECTOR_UP_GEN_BIT    ((uint32_t)0x00020000)
#define MPU_COMMON_INT_GEN_SW_TX_VECTOR_UP_GEN_POS    17
#define MPU_COMMON_INT_GEN_SW_TX_OVERFLOW_GEN_BIT    ((uint32_t)0x00010000)
#define MPU_COMMON_INT_GEN_SW_TX_OVERFLOW_GEN_POS    16
#define MPU_COMMON_INT_GEN_SW_CRC_PARITY_ERR_GEN_BIT    ((uint32_t)0x00008000)
#define MPU_COMMON_INT_GEN_SW_CRC_PARITY_ERR_GEN_POS    15
#define MPU_COMMON_INT_GEN_SW_LMAC_INT_1_GEN_BIT    ((uint32_t)0x00004000)
#define MPU_COMMON_INT_GEN_SW_LMAC_INT_1_GEN_POS    14
#define MPU_COMMON_INT_GEN_SW_SMAC_INT_1_GEN_BIT    ((uint32_t)0x00002000)
#define MPU_COMMON_INT_GEN_SW_SMAC_INT_1_GEN_POS    13
#define MPU_COMMON_INT_GEN_SW_UMAC_INT_1_GEN_BIT    ((uint32_t)0x00001000)
#define MPU_COMMON_INT_GEN_SW_UMAC_INT_1_GEN_POS    12
#define MPU_COMMON_INT_GEN_SW_TX_VECTOR_2_UP_GEN_BIT    ((uint32_t)0x00000800)
#define MPU_COMMON_INT_GEN_SW_TX_VECTOR_2_UP_GEN_POS    11
#define MPU_COMMON_INT_GEN_SW_RX_VECTOR_UP_GEN_BIT    ((uint32_t)0x00000400)
#define MPU_COMMON_INT_GEN_SW_RX_VECTOR_UP_GEN_POS    10
#define MPU_COMMON_INT_GEN_SW_SIGB_GEN_DONE_GEN_BIT    ((uint32_t)0x00000080)
#define MPU_COMMON_INT_GEN_SW_SIGB_GEN_DONE_GEN_POS    7
#define MPU_COMMON_INT_GEN_SW_MPU_ERR_GEN_BIT    ((uint32_t)0x00000040)
#define MPU_COMMON_INT_GEN_SW_MPU_ERR_GEN_POS    6
#define MPU_COMMON_INT_GEN_SW_LMAC_INT_2_GEN_BIT    ((uint32_t)0x00000010)
#define MPU_COMMON_INT_GEN_SW_LMAC_INT_2_GEN_POS    4
#define MPU_COMMON_INT_GEN_SW_SMAC_INT_2_GEN_BIT    ((uint32_t)0x00000008)
#define MPU_COMMON_INT_GEN_SW_SMAC_INT_2_GEN_POS    3
#define MPU_COMMON_INT_GEN_SW_UMAC_INT_2_GEN_BIT    ((uint32_t)0x00000004)
#define MPU_COMMON_INT_GEN_SW_UMAC_INT_2_GEN_POS    2

#define MPU_COMMON_INT_GEN_SW_TX_REQ_RISE_GEN_RST    0x0
#define MPU_COMMON_INT_GEN_SW_TX_REQ_FALL_GEN_RST    0x0
#define MPU_COMMON_INT_GEN_SW_RX_REQ_RISE_GEN_RST    0x0
#define MPU_COMMON_INT_GEN_SW_RX_REQ_FALL_GEN_RST    0x0
#define MPU_COMMON_INT_GEN_SW_LMAC_INT_0_GEN_RST    0x0
#define MPU_COMMON_INT_GEN_SW_SMAC_INT_0_GEN_RST    0x0
#define MPU_COMMON_INT_GEN_SW_UMAC_INT_0_GEN_RST    0x0
#define MPU_COMMON_INT_GEN_SW_RX_REQ_LOW_FLAG_GEN_RST    0x0
#define MPU_COMMON_INT_GEN_SW_KEEP_RF_ON_RISE_GEN_RST    0x0
#define MPU_COMMON_INT_GEN_SW_KEEP_RF_ON_FALL_GEN_RST    0x0
#define MPU_COMMON_INT_GEN_SW_SERVICE_UP_GEN_RST    0x0
#define MPU_COMMON_INT_GEN_SW_TX_VECTOR_UP_GEN_RST    0x0
#define MPU_COMMON_INT_GEN_SW_TX_OVERFLOW_GEN_RST    0x0
#define MPU_COMMON_INT_GEN_SW_CRC_PARITY_ERR_GEN_RST    0x0
#define MPU_COMMON_INT_GEN_SW_LMAC_INT_1_GEN_RST    0x0
#define MPU_COMMON_INT_GEN_SW_SMAC_INT_1_GEN_RST    0x0
#define MPU_COMMON_INT_GEN_SW_UMAC_INT_1_GEN_RST    0x0
#define MPU_COMMON_INT_GEN_SW_TX_VECTOR_2_UP_GEN_RST    0x0
#define MPU_COMMON_INT_GEN_SW_RX_VECTOR_UP_GEN_RST    0x0
#define MPU_COMMON_INT_GEN_SW_SIGB_GEN_DONE_GEN_RST    0x0
#define MPU_COMMON_INT_GEN_SW_MPU_ERR_GEN_RST    0x0
#define MPU_COMMON_INT_GEN_SW_LMAC_INT_2_GEN_RST    0x0
#define MPU_COMMON_INT_GEN_SW_SMAC_INT_2_GEN_RST    0x0
#define MPU_COMMON_INT_GEN_SW_UMAC_INT_2_GEN_RST    0x0

__INLINE void mpu_common_int_gen_sw_pack(uint8_t tx_req_rise_gen, uint8_t tx_req_fall_gen, uint8_t rx_req_rise_gen, uint8_t rx_req_fall_gen, uint8_t lmac_int0_gen, uint8_t smac_int0_gen, uint8_t umac_int0_gen, uint8_t rx_req_low_flag_gen, uint8_t keep_rf_on_rise_gen, uint8_t keep_rf_on_fall_gen, uint8_t service_up_gen, uint8_t tx_vector_up_gen, uint8_t tx_overflow_gen, uint8_t crc_parity_err_gen, uint8_t lmac_int1_gen, uint8_t smac_int1_gen, uint8_t umac_int1_gen, uint8_t tx_vector2_up_gen, uint8_t rx_vector_up_gen, uint8_t sigb_gen_done_gen, uint8_t mpu_err_gen, uint8_t lmac_int2_gen, uint8_t smac_int2_gen, uint8_t umac_int2_gen)
{
	ASSERT_ERR((((uint32_t)tx_req_rise_gen << 29) & ~((uint32_t)0x20000000)) == 0);
	ASSERT_ERR((((uint32_t)tx_req_fall_gen << 28) & ~((uint32_t)0x10000000)) == 0);
	ASSERT_ERR((((uint32_t)rx_req_rise_gen << 27) & ~((uint32_t)0x08000000)) == 0);
	ASSERT_ERR((((uint32_t)rx_req_fall_gen << 26) & ~((uint32_t)0x04000000)) == 0);
	ASSERT_ERR((((uint32_t)lmac_int0_gen << 25) & ~((uint32_t)0x02000000)) == 0);
	ASSERT_ERR((((uint32_t)smac_int0_gen << 24) & ~((uint32_t)0x01000000)) == 0);
	ASSERT_ERR((((uint32_t)umac_int0_gen << 23) & ~((uint32_t)0x00800000)) == 0);
	ASSERT_ERR((((uint32_t)rx_req_low_flag_gen << 22) & ~((uint32_t)0x00400000)) == 0);
	ASSERT_ERR((((uint32_t)keep_rf_on_rise_gen << 20) & ~((uint32_t)0x00100000)) == 0);
	ASSERT_ERR((((uint32_t)keep_rf_on_fall_gen << 19) & ~((uint32_t)0x00080000)) == 0);
	ASSERT_ERR((((uint32_t)service_up_gen << 18) & ~((uint32_t)0x00040000)) == 0);
	ASSERT_ERR((((uint32_t)tx_vector_up_gen << 17) & ~((uint32_t)0x00020000)) == 0);
	ASSERT_ERR((((uint32_t)tx_overflow_gen << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)crc_parity_err_gen << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)lmac_int1_gen << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)smac_int1_gen << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)umac_int1_gen << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)tx_vector2_up_gen << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)rx_vector_up_gen << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)sigb_gen_done_gen << 7) & ~((uint32_t)0x00000080)) == 0);
	ASSERT_ERR((((uint32_t)mpu_err_gen << 6) & ~((uint32_t)0x00000040)) == 0);
	ASSERT_ERR((((uint32_t)lmac_int2_gen << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)smac_int2_gen << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)umac_int2_gen << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(MPU_COMMON_INT_GEN_SW_ADDR,  ((uint32_t)tx_req_rise_gen << 29) |((uint32_t)tx_req_fall_gen << 28) |((uint32_t)rx_req_rise_gen << 27) |((uint32_t)rx_req_fall_gen << 26) |((uint32_t)lmac_int0_gen << 25) |((uint32_t)smac_int0_gen << 24) |((uint32_t)umac_int0_gen << 23) |((uint32_t)rx_req_low_flag_gen << 22) |((uint32_t)keep_rf_on_rise_gen << 20) |((uint32_t)keep_rf_on_fall_gen << 19) |((uint32_t)service_up_gen << 18) |((uint32_t)tx_vector_up_gen << 17) |((uint32_t)tx_overflow_gen << 16) |((uint32_t)crc_parity_err_gen << 15) |((uint32_t)lmac_int1_gen << 14) |((uint32_t)smac_int1_gen << 13) |((uint32_t)umac_int1_gen << 12) |((uint32_t)tx_vector2_up_gen << 11) |((uint32_t)rx_vector_up_gen << 10) |((uint32_t)sigb_gen_done_gen << 7) |((uint32_t)mpu_err_gen << 6) |((uint32_t)lmac_int2_gen << 4) |((uint32_t)smac_int2_gen << 3) |((uint32_t)umac_int2_gen << 2));
}

__INLINE void mpu_common_int_gen_sw_tx_req_rise_gen_setf(uint8_t txreqrisegen)
{
	ASSERT_ERR((((uint32_t)txreqrisegen << 29) & ~((uint32_t)0x20000000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_GEN_SW_ADDR, (REG_PL_RD(MPU_COMMON_INT_GEN_SW_ADDR) & ~((uint32_t)0x20000000)) | ((uint32_t)txreqrisegen <<29));
}
__INLINE void mpu_common_int_gen_sw_tx_req_fall_gen_setf(uint8_t txreqfallgen)
{
	ASSERT_ERR((((uint32_t)txreqfallgen << 28) & ~((uint32_t)0x10000000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_GEN_SW_ADDR, (REG_PL_RD(MPU_COMMON_INT_GEN_SW_ADDR) & ~((uint32_t)0x10000000)) | ((uint32_t)txreqfallgen <<28));
}
__INLINE void mpu_common_int_gen_sw_rx_req_rise_gen_setf(uint8_t rxreqrisegen)
{
	ASSERT_ERR((((uint32_t)rxreqrisegen << 27) & ~((uint32_t)0x08000000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_GEN_SW_ADDR, (REG_PL_RD(MPU_COMMON_INT_GEN_SW_ADDR) & ~((uint32_t)0x08000000)) | ((uint32_t)rxreqrisegen <<27));
}
__INLINE void mpu_common_int_gen_sw_rx_req_fall_gen_setf(uint8_t rxreqfallgen)
{
	ASSERT_ERR((((uint32_t)rxreqfallgen << 26) & ~((uint32_t)0x04000000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_GEN_SW_ADDR, (REG_PL_RD(MPU_COMMON_INT_GEN_SW_ADDR) & ~((uint32_t)0x04000000)) | ((uint32_t)rxreqfallgen <<26));
}
__INLINE void mpu_common_int_gen_sw_lmac_int_0_gen_setf(uint8_t lmacint0gen)
{
	ASSERT_ERR((((uint32_t)lmacint0gen << 25) & ~((uint32_t)0x02000000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_GEN_SW_ADDR, (REG_PL_RD(MPU_COMMON_INT_GEN_SW_ADDR) & ~((uint32_t)0x02000000)) | ((uint32_t)lmacint0gen <<25));
}
__INLINE void mpu_common_int_gen_sw_smac_int_0_gen_setf(uint8_t smacint0gen)
{
	ASSERT_ERR((((uint32_t)smacint0gen << 24) & ~((uint32_t)0x01000000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_GEN_SW_ADDR, (REG_PL_RD(MPU_COMMON_INT_GEN_SW_ADDR) & ~((uint32_t)0x01000000)) | ((uint32_t)smacint0gen <<24));
}
__INLINE void mpu_common_int_gen_sw_umac_int_0_gen_setf(uint8_t umacint0gen)
{
	ASSERT_ERR((((uint32_t)umacint0gen << 23) & ~((uint32_t)0x00800000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_GEN_SW_ADDR, (REG_PL_RD(MPU_COMMON_INT_GEN_SW_ADDR) & ~((uint32_t)0x00800000)) | ((uint32_t)umacint0gen <<23));
}
__INLINE void mpu_common_int_gen_sw_rx_req_low_flag_gen_setf(uint8_t rxreqlowflaggen)
{
	ASSERT_ERR((((uint32_t)rxreqlowflaggen << 22) & ~((uint32_t)0x00400000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_GEN_SW_ADDR, (REG_PL_RD(MPU_COMMON_INT_GEN_SW_ADDR) & ~((uint32_t)0x00400000)) | ((uint32_t)rxreqlowflaggen <<22));
}
__INLINE void mpu_common_int_gen_sw_keep_rf_on_rise_gen_setf(uint8_t keeprfonrisegen)
{
	ASSERT_ERR((((uint32_t)keeprfonrisegen << 20) & ~((uint32_t)0x00100000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_GEN_SW_ADDR, (REG_PL_RD(MPU_COMMON_INT_GEN_SW_ADDR) & ~((uint32_t)0x00100000)) | ((uint32_t)keeprfonrisegen <<20));
}
__INLINE void mpu_common_int_gen_sw_keep_rf_on_fall_gen_setf(uint8_t keeprfonfallgen)
{
	ASSERT_ERR((((uint32_t)keeprfonfallgen << 19) & ~((uint32_t)0x00080000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_GEN_SW_ADDR, (REG_PL_RD(MPU_COMMON_INT_GEN_SW_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)keeprfonfallgen <<19));
}
__INLINE void mpu_common_int_gen_sw_service_up_gen_setf(uint8_t serviceupgen)
{
	ASSERT_ERR((((uint32_t)serviceupgen << 18) & ~((uint32_t)0x00040000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_GEN_SW_ADDR, (REG_PL_RD(MPU_COMMON_INT_GEN_SW_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)serviceupgen <<18));
}
__INLINE void mpu_common_int_gen_sw_tx_vector_up_gen_setf(uint8_t txvectorupgen)
{
	ASSERT_ERR((((uint32_t)txvectorupgen << 17) & ~((uint32_t)0x00020000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_GEN_SW_ADDR, (REG_PL_RD(MPU_COMMON_INT_GEN_SW_ADDR) & ~((uint32_t)0x00020000)) | ((uint32_t)txvectorupgen <<17));
}
__INLINE void mpu_common_int_gen_sw_tx_overflow_gen_setf(uint8_t txoverflowgen)
{
	ASSERT_ERR((((uint32_t)txoverflowgen << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_GEN_SW_ADDR, (REG_PL_RD(MPU_COMMON_INT_GEN_SW_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)txoverflowgen <<16));
}
__INLINE void mpu_common_int_gen_sw_crc_parity_err_gen_setf(uint8_t crcparityerrgen)
{
	ASSERT_ERR((((uint32_t)crcparityerrgen << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_GEN_SW_ADDR, (REG_PL_RD(MPU_COMMON_INT_GEN_SW_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)crcparityerrgen <<15));
}
__INLINE void mpu_common_int_gen_sw_lmac_int_1_gen_setf(uint8_t lmacint1gen)
{
	ASSERT_ERR((((uint32_t)lmacint1gen << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_GEN_SW_ADDR, (REG_PL_RD(MPU_COMMON_INT_GEN_SW_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)lmacint1gen <<14));
}
__INLINE void mpu_common_int_gen_sw_smac_int_1_gen_setf(uint8_t smacint1gen)
{
	ASSERT_ERR((((uint32_t)smacint1gen << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_GEN_SW_ADDR, (REG_PL_RD(MPU_COMMON_INT_GEN_SW_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)smacint1gen <<13));
}
__INLINE void mpu_common_int_gen_sw_umac_int_1_gen_setf(uint8_t umacint1gen)
{
	ASSERT_ERR((((uint32_t)umacint1gen << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(MPU_COMMON_INT_GEN_SW_ADDR, (REG_PL_RD(MPU_COMMON_INT_GEN_SW_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)umacint1gen <<12));
}
__INLINE void mpu_common_int_gen_sw_tx_vector_2_up_gen_setf(uint8_t txvector2upgen)
{
	ASSERT_ERR((((uint32_t)txvector2upgen << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(MPU_COMMON_INT_GEN_SW_ADDR, (REG_PL_RD(MPU_COMMON_INT_GEN_SW_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)txvector2upgen <<11));
}
__INLINE void mpu_common_int_gen_sw_rx_vector_up_gen_setf(uint8_t rxvectorupgen)
{
	ASSERT_ERR((((uint32_t)rxvectorupgen << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(MPU_COMMON_INT_GEN_SW_ADDR, (REG_PL_RD(MPU_COMMON_INT_GEN_SW_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)rxvectorupgen <<10));
}
__INLINE void mpu_common_int_gen_sw_sigb_gen_done_gen_setf(uint8_t sigbgendonegen)
{
	ASSERT_ERR((((uint32_t)sigbgendonegen << 7) & ~((uint32_t)0x00000080)) == 0);
	REG_PL_WR(MPU_COMMON_INT_GEN_SW_ADDR, (REG_PL_RD(MPU_COMMON_INT_GEN_SW_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)sigbgendonegen <<7));
}
__INLINE void mpu_common_int_gen_sw_mpu_err_gen_setf(uint8_t mpuerrgen)
{
	ASSERT_ERR((((uint32_t)mpuerrgen << 6) & ~((uint32_t)0x00000040)) == 0);
	REG_PL_WR(MPU_COMMON_INT_GEN_SW_ADDR, (REG_PL_RD(MPU_COMMON_INT_GEN_SW_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)mpuerrgen <<6));
}
__INLINE void mpu_common_int_gen_sw_lmac_int_2_gen_setf(uint8_t lmacint2gen)
{
	ASSERT_ERR((((uint32_t)lmacint2gen << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(MPU_COMMON_INT_GEN_SW_ADDR, (REG_PL_RD(MPU_COMMON_INT_GEN_SW_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)lmacint2gen <<4));
}
__INLINE void mpu_common_int_gen_sw_smac_int_2_gen_setf(uint8_t smacint2gen)
{
	ASSERT_ERR((((uint32_t)smacint2gen << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(MPU_COMMON_INT_GEN_SW_ADDR, (REG_PL_RD(MPU_COMMON_INT_GEN_SW_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)smacint2gen <<3));
}
__INLINE void mpu_common_int_gen_sw_umac_int_2_gen_setf(uint8_t umacint2gen)
{
	ASSERT_ERR((((uint32_t)umacint2gen << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(MPU_COMMON_INT_GEN_SW_ADDR, (REG_PL_RD(MPU_COMMON_INT_GEN_SW_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)umacint2gen <<2));
}

/**
 * @brief STA_ID_01 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26:16 STA_ID_1                  0x0
 *    10:00 STA_ID_0                  0x0
 * </pre>
 */
#define MPU_COMMON_STA_ID_01_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000088)
#define MPU_COMMON_STA_ID_01_OFFSET      0x00000088
#define MPU_COMMON_STA_ID_01_INDEX       0x00000022
#define MPU_COMMON_STA_ID_01_RESET       0x00000000

__INLINE uint32_t  mpu_common_sta_id_01_get(void)
{
	return REG_PL_RD(MPU_COMMON_STA_ID_01_ADDR);
}

__INLINE void mpu_common_sta_id_01_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_STA_ID_01_ADDR, value);
}

// field definitions
#define MPU_COMMON_STA_ID_01_STA_ID_1_MASK    ((uint32_t)0x07FF0000)
#define MPU_COMMON_STA_ID_01_STA_ID_1_LSB    16
#define MPU_COMMON_STA_ID_01_STA_ID_1_WIDTH    ((uint32_t)0x0000000B)
#define MPU_COMMON_STA_ID_01_STA_ID_0_MASK    ((uint32_t)0x000007FF)
#define MPU_COMMON_STA_ID_01_STA_ID_0_LSB    0
#define MPU_COMMON_STA_ID_01_STA_ID_0_WIDTH    ((uint32_t)0x0000000B)

#define MPU_COMMON_STA_ID_01_STA_ID_1_RST    0x0
#define MPU_COMMON_STA_ID_01_STA_ID_0_RST    0x0

__INLINE void mpu_common_sta_id_01_pack(uint16_t sta_id_1, uint16_t sta_id_0)
{
	ASSERT_ERR((((uint32_t)sta_id_1 << 16) & ~((uint32_t)0x07FF0000)) == 0);
	ASSERT_ERR((((uint32_t)sta_id_0 << 0) & ~((uint32_t)0x000007FF)) == 0);
	REG_PL_WR(MPU_COMMON_STA_ID_01_ADDR,  ((uint32_t)sta_id_1 << 16) |((uint32_t)sta_id_0 << 0));
}

__INLINE void mpu_common_sta_id_01_unpack(uint16_t* sta_id_1, uint16_t* sta_id_0)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_STA_ID_01_ADDR);

	*sta_id_1 = (localVal & ((uint32_t)0x07FF0000)) >>  16;
	*sta_id_0 = (localVal & ((uint32_t)0x000007FF)) >>  0;
}

__INLINE uint16_t mpu_common_sta_id_01_sta_id_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_STA_ID_01_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x07FF0000)) >> 16);
}
__INLINE void mpu_common_sta_id_01_sta_id_1_setf(uint16_t staid1)
{
	ASSERT_ERR((((uint32_t)staid1 << 16) & ~((uint32_t)0x07FF0000)) == 0);
	REG_PL_WR(MPU_COMMON_STA_ID_01_ADDR, (REG_PL_RD(MPU_COMMON_STA_ID_01_ADDR) & ~((uint32_t)0x07FF0000)) | ((uint32_t)staid1 <<16));
}
__INLINE uint16_t mpu_common_sta_id_01_sta_id_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_STA_ID_01_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000007FF)) >> 0);
}
__INLINE void mpu_common_sta_id_01_sta_id_0_setf(uint16_t staid0)
{
	ASSERT_ERR((((uint32_t)staid0 << 0) & ~((uint32_t)0x000007FF)) == 0);
	REG_PL_WR(MPU_COMMON_STA_ID_01_ADDR, (REG_PL_RD(MPU_COMMON_STA_ID_01_ADDR) & ~((uint32_t)0x000007FF)) | ((uint32_t)staid0 <<0));
}

/**
 * @brief STA_ID_23 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26:16 STA_ID_3                  0x0
 *    10:00 STA_ID_2                  0x0
 * </pre>
 */
#define MPU_COMMON_STA_ID_23_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x0000008C)
#define MPU_COMMON_STA_ID_23_OFFSET      0x0000008C
#define MPU_COMMON_STA_ID_23_INDEX       0x00000023
#define MPU_COMMON_STA_ID_23_RESET       0x00000000

__INLINE uint32_t  mpu_common_sta_id_23_get(void)
{
	return REG_PL_RD(MPU_COMMON_STA_ID_23_ADDR);
}

__INLINE void mpu_common_sta_id_23_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_STA_ID_23_ADDR, value);
}

// field definitions
#define MPU_COMMON_STA_ID_23_STA_ID_3_MASK    ((uint32_t)0x07FF0000)
#define MPU_COMMON_STA_ID_23_STA_ID_3_LSB    16
#define MPU_COMMON_STA_ID_23_STA_ID_3_WIDTH    ((uint32_t)0x0000000B)
#define MPU_COMMON_STA_ID_23_STA_ID_2_MASK    ((uint32_t)0x000007FF)
#define MPU_COMMON_STA_ID_23_STA_ID_2_LSB    0
#define MPU_COMMON_STA_ID_23_STA_ID_2_WIDTH    ((uint32_t)0x0000000B)

#define MPU_COMMON_STA_ID_23_STA_ID_3_RST    0x0
#define MPU_COMMON_STA_ID_23_STA_ID_2_RST    0x0

__INLINE void mpu_common_sta_id_23_pack(uint16_t sta_id_3, uint16_t sta_id_2)
{
	ASSERT_ERR((((uint32_t)sta_id_3 << 16) & ~((uint32_t)0x07FF0000)) == 0);
	ASSERT_ERR((((uint32_t)sta_id_2 << 0) & ~((uint32_t)0x000007FF)) == 0);
	REG_PL_WR(MPU_COMMON_STA_ID_23_ADDR,  ((uint32_t)sta_id_3 << 16) |((uint32_t)sta_id_2 << 0));
}

__INLINE void mpu_common_sta_id_23_unpack(uint16_t* sta_id_3, uint16_t* sta_id_2)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_STA_ID_23_ADDR);

	*sta_id_3 = (localVal & ((uint32_t)0x07FF0000)) >>  16;
	*sta_id_2 = (localVal & ((uint32_t)0x000007FF)) >>  0;
}

__INLINE uint16_t mpu_common_sta_id_23_sta_id_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_STA_ID_23_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x07FF0000)) >> 16);
}
__INLINE void mpu_common_sta_id_23_sta_id_3_setf(uint16_t staid3)
{
	ASSERT_ERR((((uint32_t)staid3 << 16) & ~((uint32_t)0x07FF0000)) == 0);
	REG_PL_WR(MPU_COMMON_STA_ID_23_ADDR, (REG_PL_RD(MPU_COMMON_STA_ID_23_ADDR) & ~((uint32_t)0x07FF0000)) | ((uint32_t)staid3 <<16));
}
__INLINE uint16_t mpu_common_sta_id_23_sta_id_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_STA_ID_23_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000007FF)) >> 0);
}
__INLINE void mpu_common_sta_id_23_sta_id_2_setf(uint16_t staid2)
{
	ASSERT_ERR((((uint32_t)staid2 << 0) & ~((uint32_t)0x000007FF)) == 0);
	REG_PL_WR(MPU_COMMON_STA_ID_23_ADDR, (REG_PL_RD(MPU_COMMON_STA_ID_23_ADDR) & ~((uint32_t)0x000007FF)) | ((uint32_t)staid2 <<0));
}

/**
 * @brief STA_ID_45 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26:16 STA_ID_5                  0x0
 *    10:00 STA_ID_4                  0x0
 * </pre>
 */
#define MPU_COMMON_STA_ID_45_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000090)
#define MPU_COMMON_STA_ID_45_OFFSET      0x00000090
#define MPU_COMMON_STA_ID_45_INDEX       0x00000024
#define MPU_COMMON_STA_ID_45_RESET       0x00000000

__INLINE uint32_t  mpu_common_sta_id_45_get(void)
{
	return REG_PL_RD(MPU_COMMON_STA_ID_45_ADDR);
}

__INLINE void mpu_common_sta_id_45_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_STA_ID_45_ADDR, value);
}

// field definitions
#define MPU_COMMON_STA_ID_45_STA_ID_5_MASK    ((uint32_t)0x07FF0000)
#define MPU_COMMON_STA_ID_45_STA_ID_5_LSB    16
#define MPU_COMMON_STA_ID_45_STA_ID_5_WIDTH    ((uint32_t)0x0000000B)
#define MPU_COMMON_STA_ID_45_STA_ID_4_MASK    ((uint32_t)0x000007FF)
#define MPU_COMMON_STA_ID_45_STA_ID_4_LSB    0
#define MPU_COMMON_STA_ID_45_STA_ID_4_WIDTH    ((uint32_t)0x0000000B)

#define MPU_COMMON_STA_ID_45_STA_ID_5_RST    0x0
#define MPU_COMMON_STA_ID_45_STA_ID_4_RST    0x0

__INLINE void mpu_common_sta_id_45_pack(uint16_t sta_id_5, uint16_t sta_id_4)
{
	ASSERT_ERR((((uint32_t)sta_id_5 << 16) & ~((uint32_t)0x07FF0000)) == 0);
	ASSERT_ERR((((uint32_t)sta_id_4 << 0) & ~((uint32_t)0x000007FF)) == 0);
	REG_PL_WR(MPU_COMMON_STA_ID_45_ADDR,  ((uint32_t)sta_id_5 << 16) |((uint32_t)sta_id_4 << 0));
}

__INLINE void mpu_common_sta_id_45_unpack(uint16_t* sta_id_5, uint16_t* sta_id_4)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_STA_ID_45_ADDR);

	*sta_id_5 = (localVal & ((uint32_t)0x07FF0000)) >>  16;
	*sta_id_4 = (localVal & ((uint32_t)0x000007FF)) >>  0;
}

__INLINE uint16_t mpu_common_sta_id_45_sta_id_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_STA_ID_45_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x07FF0000)) >> 16);
}
__INLINE void mpu_common_sta_id_45_sta_id_5_setf(uint16_t staid5)
{
	ASSERT_ERR((((uint32_t)staid5 << 16) & ~((uint32_t)0x07FF0000)) == 0);
	REG_PL_WR(MPU_COMMON_STA_ID_45_ADDR, (REG_PL_RD(MPU_COMMON_STA_ID_45_ADDR) & ~((uint32_t)0x07FF0000)) | ((uint32_t)staid5 <<16));
}
__INLINE uint16_t mpu_common_sta_id_45_sta_id_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_STA_ID_45_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000007FF)) >> 0);
}
__INLINE void mpu_common_sta_id_45_sta_id_4_setf(uint16_t staid4)
{
	ASSERT_ERR((((uint32_t)staid4 << 0) & ~((uint32_t)0x000007FF)) == 0);
	REG_PL_WR(MPU_COMMON_STA_ID_45_ADDR, (REG_PL_RD(MPU_COMMON_STA_ID_45_ADDR) & ~((uint32_t)0x000007FF)) | ((uint32_t)staid4 <<0));
}

/**
 * @brief MPU_MISC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 LSIG_MIN_LENGTH           0x0
 *    14    AGC_VALID_ON_LSIG_ERROR   0              
 *    13    RX_VECTOR_ON_LSIG_ERROR   0              
 *    12    LSIG_CHECK_ILLEGAL_RATE   0              
 *    11    LSIG_CHECK_SHORT_LENGTH   0              
 *    10    LSIG_CHECK_RESERVED_BIT   0              
 *    09    LSIG_CHECK_TAIL           0              
 *    08    LSIG_CHECK_PARITY         0              
 *    06:04 TX_FIFO_WATERMARK         0x4
 *    01    DISABLE_AUTO_RXEND_FOR_TIMING 1              
 *    00    DISABLE_AUTO_RX_VECTOR_1_A 0              
 * </pre>
 */
#define MPU_COMMON_MPU_MISC_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000094)
#define MPU_COMMON_MPU_MISC_OFFSET      0x00000094
#define MPU_COMMON_MPU_MISC_INDEX       0x00000025
#define MPU_COMMON_MPU_MISC_RESET       0x00000042

__INLINE uint32_t  mpu_common_mpu_misc_get(void)
{
	return REG_PL_RD(MPU_COMMON_MPU_MISC_ADDR);
}

__INLINE void mpu_common_mpu_misc_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_MPU_MISC_ADDR, value);
}

// field definitions
#define MPU_COMMON_MPU_MISC_LSIG_MIN_LENGTH_MASK    ((uint32_t)0x0FFF0000)
#define MPU_COMMON_MPU_MISC_LSIG_MIN_LENGTH_LSB    16
#define MPU_COMMON_MPU_MISC_LSIG_MIN_LENGTH_WIDTH    ((uint32_t)0x0000000C)
#define MPU_COMMON_MPU_MISC_AGC_VALID_ON_LSIG_ERROR_BIT    ((uint32_t)0x00004000)
#define MPU_COMMON_MPU_MISC_AGC_VALID_ON_LSIG_ERROR_POS    14
#define MPU_COMMON_MPU_MISC_RX_VECTOR_ON_LSIG_ERROR_BIT    ((uint32_t)0x00002000)
#define MPU_COMMON_MPU_MISC_RX_VECTOR_ON_LSIG_ERROR_POS    13
#define MPU_COMMON_MPU_MISC_LSIG_CHECK_ILLEGAL_RATE_BIT    ((uint32_t)0x00001000)
#define MPU_COMMON_MPU_MISC_LSIG_CHECK_ILLEGAL_RATE_POS    12
#define MPU_COMMON_MPU_MISC_LSIG_CHECK_SHORT_LENGTH_BIT    ((uint32_t)0x00000800)
#define MPU_COMMON_MPU_MISC_LSIG_CHECK_SHORT_LENGTH_POS    11
#define MPU_COMMON_MPU_MISC_LSIG_CHECK_RESERVED_BIT_BIT    ((uint32_t)0x00000400)
#define MPU_COMMON_MPU_MISC_LSIG_CHECK_RESERVED_BIT_POS    10
#define MPU_COMMON_MPU_MISC_LSIG_CHECK_TAIL_BIT    ((uint32_t)0x00000200)
#define MPU_COMMON_MPU_MISC_LSIG_CHECK_TAIL_POS    9
#define MPU_COMMON_MPU_MISC_LSIG_CHECK_PARITY_BIT    ((uint32_t)0x00000100)
#define MPU_COMMON_MPU_MISC_LSIG_CHECK_PARITY_POS    8
#define MPU_COMMON_MPU_MISC_TX_FIFO_WATERMARK_MASK    ((uint32_t)0x00000070)
#define MPU_COMMON_MPU_MISC_TX_FIFO_WATERMARK_LSB    4
#define MPU_COMMON_MPU_MISC_TX_FIFO_WATERMARK_WIDTH    ((uint32_t)0x00000003)
#define MPU_COMMON_MPU_MISC_DISABLE_AUTO_RXEND_FOR_TIMING_BIT    ((uint32_t)0x00000002)
#define MPU_COMMON_MPU_MISC_DISABLE_AUTO_RXEND_FOR_TIMING_POS    1
#define MPU_COMMON_MPU_MISC_DISABLE_AUTO_RX_VECTOR_1_A_BIT    ((uint32_t)0x00000001)
#define MPU_COMMON_MPU_MISC_DISABLE_AUTO_RX_VECTOR_1_A_POS    0

#define MPU_COMMON_MPU_MISC_LSIG_MIN_LENGTH_RST    0x0
#define MPU_COMMON_MPU_MISC_AGC_VALID_ON_LSIG_ERROR_RST    0x0
#define MPU_COMMON_MPU_MISC_RX_VECTOR_ON_LSIG_ERROR_RST    0x0
#define MPU_COMMON_MPU_MISC_LSIG_CHECK_ILLEGAL_RATE_RST    0x0
#define MPU_COMMON_MPU_MISC_LSIG_CHECK_SHORT_LENGTH_RST    0x0
#define MPU_COMMON_MPU_MISC_LSIG_CHECK_RESERVED_BIT_RST    0x0
#define MPU_COMMON_MPU_MISC_LSIG_CHECK_TAIL_RST    0x0
#define MPU_COMMON_MPU_MISC_LSIG_CHECK_PARITY_RST    0x0
#define MPU_COMMON_MPU_MISC_TX_FIFO_WATERMARK_RST    0x4
#define MPU_COMMON_MPU_MISC_DISABLE_AUTO_RXEND_FOR_TIMING_RST    0x1
#define MPU_COMMON_MPU_MISC_DISABLE_AUTO_RX_VECTOR_1_A_RST    0x0

__INLINE void mpu_common_mpu_misc_pack(uint16_t lsig_min_length, uint8_t agc_valid_on_lsig_error, uint8_t rx_vector_on_lsig_error, uint8_t lsig_check_illegal_rate, uint8_t lsig_check_short_length, uint8_t lsig_check_reserved_bit, uint8_t lsig_check_tail, uint8_t lsig_check_parity, uint8_t tx_fifo_watermark, uint8_t disable_auto_rxend_for_timing, uint8_t disable_auto_rx_vector_1_a)
{
	ASSERT_ERR((((uint32_t)lsig_min_length << 16) & ~((uint32_t)0x0FFF0000)) == 0);
	ASSERT_ERR((((uint32_t)agc_valid_on_lsig_error << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)rx_vector_on_lsig_error << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)lsig_check_illegal_rate << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)lsig_check_short_length << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)lsig_check_reserved_bit << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)lsig_check_tail << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)lsig_check_parity << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)tx_fifo_watermark << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)disable_auto_rxend_for_timing << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)disable_auto_rx_vector_1_a << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MPU_COMMON_MPU_MISC_ADDR,  ((uint32_t)lsig_min_length << 16) |((uint32_t)agc_valid_on_lsig_error << 14) |((uint32_t)rx_vector_on_lsig_error << 13) |((uint32_t)lsig_check_illegal_rate << 12) |((uint32_t)lsig_check_short_length << 11) |((uint32_t)lsig_check_reserved_bit << 10) |((uint32_t)lsig_check_tail << 9) |((uint32_t)lsig_check_parity << 8) |((uint32_t)tx_fifo_watermark << 4) |((uint32_t)disable_auto_rxend_for_timing << 1) |((uint32_t)disable_auto_rx_vector_1_a << 0));
}

__INLINE void mpu_common_mpu_misc_unpack(uint16_t* lsig_min_length, uint8_t* agc_valid_on_lsig_error, uint8_t* rx_vector_on_lsig_error, uint8_t* lsig_check_illegal_rate, uint8_t* lsig_check_short_length, uint8_t* lsig_check_reserved_bit, uint8_t* lsig_check_tail, uint8_t* lsig_check_parity, uint8_t* tx_fifo_watermark, uint8_t* disable_auto_rxend_for_timing, uint8_t* disable_auto_rx_vector_1_a)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_MPU_MISC_ADDR);

	*lsig_min_length = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*agc_valid_on_lsig_error = (localVal & ((uint32_t)0x00004000)) >>  14;
	*rx_vector_on_lsig_error = (localVal & ((uint32_t)0x00002000)) >>  13;
	*lsig_check_illegal_rate = (localVal & ((uint32_t)0x00001000)) >>  12;
	*lsig_check_short_length = (localVal & ((uint32_t)0x00000800)) >>  11;
	*lsig_check_reserved_bit = (localVal & ((uint32_t)0x00000400)) >>  10;
	*lsig_check_tail = (localVal & ((uint32_t)0x00000200)) >>  9;
	*lsig_check_parity = (localVal & ((uint32_t)0x00000100)) >>  8;
	*tx_fifo_watermark = (localVal & ((uint32_t)0x00000070)) >>  4;
	*disable_auto_rxend_for_timing = (localVal & ((uint32_t)0x00000002)) >>  1;
	*disable_auto_rx_vector_1_a = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint16_t mpu_common_mpu_misc_lsig_min_length_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_MPU_MISC_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE void mpu_common_mpu_misc_lsig_min_length_setf(uint16_t lsigminlength)
{
	ASSERT_ERR((((uint32_t)lsigminlength << 16) & ~((uint32_t)0x0FFF0000)) == 0);
	REG_PL_WR(MPU_COMMON_MPU_MISC_ADDR, (REG_PL_RD(MPU_COMMON_MPU_MISC_ADDR) & ~((uint32_t)0x0FFF0000)) | ((uint32_t)lsigminlength <<16));
}
__INLINE uint8_t mpu_common_mpu_misc_agc_valid_on_lsig_error_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_MPU_MISC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void mpu_common_mpu_misc_agc_valid_on_lsig_error_setf(uint8_t agcvalidonlsigerror)
{
	ASSERT_ERR((((uint32_t)agcvalidonlsigerror << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(MPU_COMMON_MPU_MISC_ADDR, (REG_PL_RD(MPU_COMMON_MPU_MISC_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)agcvalidonlsigerror <<14));
}
__INLINE uint8_t mpu_common_mpu_misc_rx_vector_on_lsig_error_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_MPU_MISC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void mpu_common_mpu_misc_rx_vector_on_lsig_error_setf(uint8_t rxvectoronlsigerror)
{
	ASSERT_ERR((((uint32_t)rxvectoronlsigerror << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(MPU_COMMON_MPU_MISC_ADDR, (REG_PL_RD(MPU_COMMON_MPU_MISC_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)rxvectoronlsigerror <<13));
}
__INLINE uint8_t mpu_common_mpu_misc_lsig_check_illegal_rate_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_MPU_MISC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void mpu_common_mpu_misc_lsig_check_illegal_rate_setf(uint8_t lsigcheckillegalrate)
{
	ASSERT_ERR((((uint32_t)lsigcheckillegalrate << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(MPU_COMMON_MPU_MISC_ADDR, (REG_PL_RD(MPU_COMMON_MPU_MISC_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)lsigcheckillegalrate <<12));
}
__INLINE uint8_t mpu_common_mpu_misc_lsig_check_short_length_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_MPU_MISC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void mpu_common_mpu_misc_lsig_check_short_length_setf(uint8_t lsigcheckshortlength)
{
	ASSERT_ERR((((uint32_t)lsigcheckshortlength << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(MPU_COMMON_MPU_MISC_ADDR, (REG_PL_RD(MPU_COMMON_MPU_MISC_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)lsigcheckshortlength <<11));
}
__INLINE uint8_t mpu_common_mpu_misc_lsig_check_reserved_bit_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_MPU_MISC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void mpu_common_mpu_misc_lsig_check_reserved_bit_setf(uint8_t lsigcheckreservedbit)
{
	ASSERT_ERR((((uint32_t)lsigcheckreservedbit << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(MPU_COMMON_MPU_MISC_ADDR, (REG_PL_RD(MPU_COMMON_MPU_MISC_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)lsigcheckreservedbit <<10));
}
__INLINE uint8_t mpu_common_mpu_misc_lsig_check_tail_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_MPU_MISC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void mpu_common_mpu_misc_lsig_check_tail_setf(uint8_t lsigchecktail)
{
	ASSERT_ERR((((uint32_t)lsigchecktail << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(MPU_COMMON_MPU_MISC_ADDR, (REG_PL_RD(MPU_COMMON_MPU_MISC_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)lsigchecktail <<9));
}
__INLINE uint8_t mpu_common_mpu_misc_lsig_check_parity_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_MPU_MISC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void mpu_common_mpu_misc_lsig_check_parity_setf(uint8_t lsigcheckparity)
{
	ASSERT_ERR((((uint32_t)lsigcheckparity << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(MPU_COMMON_MPU_MISC_ADDR, (REG_PL_RD(MPU_COMMON_MPU_MISC_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)lsigcheckparity <<8));
}
__INLINE uint8_t mpu_common_mpu_misc_tx_fifo_watermark_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_MPU_MISC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void mpu_common_mpu_misc_tx_fifo_watermark_setf(uint8_t txfifowatermark)
{
	ASSERT_ERR((((uint32_t)txfifowatermark << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(MPU_COMMON_MPU_MISC_ADDR, (REG_PL_RD(MPU_COMMON_MPU_MISC_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)txfifowatermark <<4));
}
__INLINE uint8_t mpu_common_mpu_misc_disable_auto_rxend_for_timing_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_MPU_MISC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void mpu_common_mpu_misc_disable_auto_rxend_for_timing_setf(uint8_t disableautorxendfortiming)
{
	ASSERT_ERR((((uint32_t)disableautorxendfortiming << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(MPU_COMMON_MPU_MISC_ADDR, (REG_PL_RD(MPU_COMMON_MPU_MISC_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)disableautorxendfortiming <<1));
}
__INLINE uint8_t mpu_common_mpu_misc_disable_auto_rx_vector_1_a_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_MPU_MISC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void mpu_common_mpu_misc_disable_auto_rx_vector_1_a_setf(uint8_t disableautorxvector1a)
{
	ASSERT_ERR((((uint32_t)disableautorxvector1a << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MPU_COMMON_MPU_MISC_ADDR, (REG_PL_RD(MPU_COMMON_MPU_MISC_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)disableautorxvector1a <<0));
}

/**
 * @brief TX_FRAME_SN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    03:00 TX_FRAME_SN               0x0
 * </pre>
 */
#define MPU_COMMON_TX_FRAME_SN_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000098)
#define MPU_COMMON_TX_FRAME_SN_OFFSET      0x00000098
#define MPU_COMMON_TX_FRAME_SN_INDEX       0x00000026
#define MPU_COMMON_TX_FRAME_SN_RESET       0x00000000

__INLINE uint32_t  mpu_common_tx_frame_sn_get(void)
{
	return REG_PL_RD(MPU_COMMON_TX_FRAME_SN_ADDR);
}

__INLINE void mpu_common_tx_frame_sn_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_TX_FRAME_SN_ADDR, value);
}

// field definitions
#define MPU_COMMON_TX_FRAME_SN_TX_FRAME_SN_MASK    ((uint32_t)0x0000000F)
#define MPU_COMMON_TX_FRAME_SN_TX_FRAME_SN_LSB    0
#define MPU_COMMON_TX_FRAME_SN_TX_FRAME_SN_WIDTH    ((uint32_t)0x00000004)

#define MPU_COMMON_TX_FRAME_SN_TX_FRAME_SN_RST    0x0

__INLINE uint8_t mpu_common_tx_frame_sn_tx_frame_sn_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TX_FRAME_SN_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void mpu_common_tx_frame_sn_tx_frame_sn_setf(uint8_t txframesn)
{
	ASSERT_ERR((((uint32_t)txframesn << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(MPU_COMMON_TX_FRAME_SN_ADDR, (uint32_t)txframesn << 0);
}

/**
 * @brief RX_ERROR_MAP register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RX_ERROR_MAP              0x0
 * </pre>
 */
#define MPU_COMMON_RX_ERROR_MAP_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x0000009C)
#define MPU_COMMON_RX_ERROR_MAP_OFFSET      0x0000009C
#define MPU_COMMON_RX_ERROR_MAP_INDEX       0x00000027
#define MPU_COMMON_RX_ERROR_MAP_RESET       0x00000000

__INLINE uint32_t  mpu_common_rx_error_map_get(void)
{
	return REG_PL_RD(MPU_COMMON_RX_ERROR_MAP_ADDR);
}

__INLINE void mpu_common_rx_error_map_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_RX_ERROR_MAP_ADDR, value);
}

// field definitions
#define MPU_COMMON_RX_ERROR_MAP_RX_ERROR_MAP_MASK    ((uint32_t)0xFFFFFFFF)
#define MPU_COMMON_RX_ERROR_MAP_RX_ERROR_MAP_LSB    0
#define MPU_COMMON_RX_ERROR_MAP_RX_ERROR_MAP_WIDTH    ((uint32_t)0x00000020)

#define MPU_COMMON_RX_ERROR_MAP_RX_ERROR_MAP_RST    0x0

__INLINE uint32_t mpu_common_rx_error_map_rx_error_map_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_RX_ERROR_MAP_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void mpu_common_rx_error_map_rx_error_map_setf(uint32_t rxerrormap)
{
	ASSERT_ERR((((uint32_t)rxerrormap << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MPU_COMMON_RX_ERROR_MAP_ADDR, (uint32_t)rxerrormap << 0);
}

/**
 * @brief TONE_PLAN_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TONE_PLAN_0               0x0
 * </pre>
 */
#define MPU_COMMON_TONE_PLAN_0_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x000000A0)
#define MPU_COMMON_TONE_PLAN_0_OFFSET      0x000000A0
#define MPU_COMMON_TONE_PLAN_0_INDEX       0x00000028
#define MPU_COMMON_TONE_PLAN_0_RESET       0x00000000

__INLINE uint32_t  mpu_common_tone_plan_0_get(void)
{
	return REG_PL_RD(MPU_COMMON_TONE_PLAN_0_ADDR);
}

// field definitions
#define MPU_COMMON_TONE_PLAN_0_TONE_PLAN_0_MASK    ((uint32_t)0xFFFFFFFF)
#define MPU_COMMON_TONE_PLAN_0_TONE_PLAN_0_LSB    0
#define MPU_COMMON_TONE_PLAN_0_TONE_PLAN_0_WIDTH    ((uint32_t)0x00000020)

#define MPU_COMMON_TONE_PLAN_0_TONE_PLAN_0_RST    0x0

__INLINE uint32_t mpu_common_tone_plan_0_tone_plan_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TONE_PLAN_0_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief TONE_PLAN_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TONE_PLAN_1               0x0
 * </pre>
 */
#define MPU_COMMON_TONE_PLAN_1_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x000000A4)
#define MPU_COMMON_TONE_PLAN_1_OFFSET      0x000000A4
#define MPU_COMMON_TONE_PLAN_1_INDEX       0x00000029
#define MPU_COMMON_TONE_PLAN_1_RESET       0x00000000

__INLINE uint32_t  mpu_common_tone_plan_1_get(void)
{
	return REG_PL_RD(MPU_COMMON_TONE_PLAN_1_ADDR);
}

// field definitions
#define MPU_COMMON_TONE_PLAN_1_TONE_PLAN_1_MASK    ((uint32_t)0xFFFFFFFF)
#define MPU_COMMON_TONE_PLAN_1_TONE_PLAN_1_LSB    0
#define MPU_COMMON_TONE_PLAN_1_TONE_PLAN_1_WIDTH    ((uint32_t)0x00000020)

#define MPU_COMMON_TONE_PLAN_1_TONE_PLAN_1_RST    0x0

__INLINE uint32_t mpu_common_tone_plan_1_tone_plan_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TONE_PLAN_1_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief DEBUG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    30:24 DEBUG_SEL_4               0x0
 *    22:16 DEBUG_SEL_3               0x0
 *    14:08 DEBUG_SEL_2               0x0
 *    06:00 DEBUG_SEL_1               0x0
 * </pre>
 */
#define MPU_COMMON_DEBUG_1_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x000000A8)
#define MPU_COMMON_DEBUG_1_OFFSET      0x000000A8
#define MPU_COMMON_DEBUG_1_INDEX       0x0000002A
#define MPU_COMMON_DEBUG_1_RESET       0x00000000

__INLINE uint32_t  mpu_common_debug_1_get(void)
{
	return REG_PL_RD(MPU_COMMON_DEBUG_1_ADDR);
}

__INLINE void mpu_common_debug_1_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_DEBUG_1_ADDR, value);
}

// field definitions
#define MPU_COMMON_DEBUG_1_DEBUG_SEL_4_MASK    ((uint32_t)0x7F000000)
#define MPU_COMMON_DEBUG_1_DEBUG_SEL_4_LSB    24
#define MPU_COMMON_DEBUG_1_DEBUG_SEL_4_WIDTH    ((uint32_t)0x00000007)
#define MPU_COMMON_DEBUG_1_DEBUG_SEL_3_MASK    ((uint32_t)0x007F0000)
#define MPU_COMMON_DEBUG_1_DEBUG_SEL_3_LSB    16
#define MPU_COMMON_DEBUG_1_DEBUG_SEL_3_WIDTH    ((uint32_t)0x00000007)
#define MPU_COMMON_DEBUG_1_DEBUG_SEL_2_MASK    ((uint32_t)0x00007F00)
#define MPU_COMMON_DEBUG_1_DEBUG_SEL_2_LSB    8
#define MPU_COMMON_DEBUG_1_DEBUG_SEL_2_WIDTH    ((uint32_t)0x00000007)
#define MPU_COMMON_DEBUG_1_DEBUG_SEL_1_MASK    ((uint32_t)0x0000007F)
#define MPU_COMMON_DEBUG_1_DEBUG_SEL_1_LSB    0
#define MPU_COMMON_DEBUG_1_DEBUG_SEL_1_WIDTH    ((uint32_t)0x00000007)

#define MPU_COMMON_DEBUG_1_DEBUG_SEL_4_RST    0x0
#define MPU_COMMON_DEBUG_1_DEBUG_SEL_3_RST    0x0
#define MPU_COMMON_DEBUG_1_DEBUG_SEL_2_RST    0x0
#define MPU_COMMON_DEBUG_1_DEBUG_SEL_1_RST    0x0

__INLINE void mpu_common_debug_1_pack(uint8_t debug_sel_4, uint8_t debug_sel_3, uint8_t debug_sel_2, uint8_t debug_sel_1)
{
	ASSERT_ERR((((uint32_t)debug_sel_4 << 24) & ~((uint32_t)0x7F000000)) == 0);
	ASSERT_ERR((((uint32_t)debug_sel_3 << 16) & ~((uint32_t)0x007F0000)) == 0);
	ASSERT_ERR((((uint32_t)debug_sel_2 << 8) & ~((uint32_t)0x00007F00)) == 0);
	ASSERT_ERR((((uint32_t)debug_sel_1 << 0) & ~((uint32_t)0x0000007F)) == 0);
	REG_PL_WR(MPU_COMMON_DEBUG_1_ADDR,  ((uint32_t)debug_sel_4 << 24) |((uint32_t)debug_sel_3 << 16) |((uint32_t)debug_sel_2 << 8) |((uint32_t)debug_sel_1 << 0));
}

__INLINE void mpu_common_debug_1_unpack(uint8_t* debug_sel_4, uint8_t* debug_sel_3, uint8_t* debug_sel_2, uint8_t* debug_sel_1)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_DEBUG_1_ADDR);

	*debug_sel_4 = (localVal & ((uint32_t)0x7F000000)) >>  24;
	*debug_sel_3 = (localVal & ((uint32_t)0x007F0000)) >>  16;
	*debug_sel_2 = (localVal & ((uint32_t)0x00007F00)) >>  8;
	*debug_sel_1 = (localVal & ((uint32_t)0x0000007F)) >>  0;
}

__INLINE uint8_t mpu_common_debug_1_debug_sel_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_DEBUG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x7F000000)) >> 24);
}
__INLINE void mpu_common_debug_1_debug_sel_4_setf(uint8_t debugsel4)
{
	ASSERT_ERR((((uint32_t)debugsel4 << 24) & ~((uint32_t)0x7F000000)) == 0);
	REG_PL_WR(MPU_COMMON_DEBUG_1_ADDR, (REG_PL_RD(MPU_COMMON_DEBUG_1_ADDR) & ~((uint32_t)0x7F000000)) | ((uint32_t)debugsel4 <<24));
}
__INLINE uint8_t mpu_common_debug_1_debug_sel_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_DEBUG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x007F0000)) >> 16);
}
__INLINE void mpu_common_debug_1_debug_sel_3_setf(uint8_t debugsel3)
{
	ASSERT_ERR((((uint32_t)debugsel3 << 16) & ~((uint32_t)0x007F0000)) == 0);
	REG_PL_WR(MPU_COMMON_DEBUG_1_ADDR, (REG_PL_RD(MPU_COMMON_DEBUG_1_ADDR) & ~((uint32_t)0x007F0000)) | ((uint32_t)debugsel3 <<16));
}
__INLINE uint8_t mpu_common_debug_1_debug_sel_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_DEBUG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007F00)) >> 8);
}
__INLINE void mpu_common_debug_1_debug_sel_2_setf(uint8_t debugsel2)
{
	ASSERT_ERR((((uint32_t)debugsel2 << 8) & ~((uint32_t)0x00007F00)) == 0);
	REG_PL_WR(MPU_COMMON_DEBUG_1_ADDR, (REG_PL_RD(MPU_COMMON_DEBUG_1_ADDR) & ~((uint32_t)0x00007F00)) | ((uint32_t)debugsel2 <<8));
}
__INLINE uint8_t mpu_common_debug_1_debug_sel_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_DEBUG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000007F)) >> 0);
}
__INLINE void mpu_common_debug_1_debug_sel_1_setf(uint8_t debugsel1)
{
	ASSERT_ERR((((uint32_t)debugsel1 << 0) & ~((uint32_t)0x0000007F)) == 0);
	REG_PL_WR(MPU_COMMON_DEBUG_1_ADDR, (REG_PL_RD(MPU_COMMON_DEBUG_1_ADDR) & ~((uint32_t)0x0000007F)) | ((uint32_t)debugsel1 <<0));
}

/**
 * @brief DEBUG_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    DEBUG_EN                  0              
 *    14:08 DEBUG_SEL_6               0x0
 *    06:00 DEBUG_SEL_5               0x0
 * </pre>
 */
#define MPU_COMMON_DEBUG_2_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x000000AC)
#define MPU_COMMON_DEBUG_2_OFFSET      0x000000AC
#define MPU_COMMON_DEBUG_2_INDEX       0x0000002B
#define MPU_COMMON_DEBUG_2_RESET       0x00000000

__INLINE uint32_t  mpu_common_debug_2_get(void)
{
	return REG_PL_RD(MPU_COMMON_DEBUG_2_ADDR);
}

__INLINE void mpu_common_debug_2_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_DEBUG_2_ADDR, value);
}

// field definitions
#define MPU_COMMON_DEBUG_2_DEBUG_EN_BIT     ((uint32_t)0x00010000)
#define MPU_COMMON_DEBUG_2_DEBUG_EN_POS     16
#define MPU_COMMON_DEBUG_2_DEBUG_SEL_6_MASK    ((uint32_t)0x00007F00)
#define MPU_COMMON_DEBUG_2_DEBUG_SEL_6_LSB    8
#define MPU_COMMON_DEBUG_2_DEBUG_SEL_6_WIDTH    ((uint32_t)0x00000007)
#define MPU_COMMON_DEBUG_2_DEBUG_SEL_5_MASK    ((uint32_t)0x0000007F)
#define MPU_COMMON_DEBUG_2_DEBUG_SEL_5_LSB    0
#define MPU_COMMON_DEBUG_2_DEBUG_SEL_5_WIDTH    ((uint32_t)0x00000007)

#define MPU_COMMON_DEBUG_2_DEBUG_EN_RST     0x0
#define MPU_COMMON_DEBUG_2_DEBUG_SEL_6_RST    0x0
#define MPU_COMMON_DEBUG_2_DEBUG_SEL_5_RST    0x0

__INLINE void mpu_common_debug_2_pack(uint8_t debug_en, uint8_t debug_sel_6, uint8_t debug_sel_5)
{
	ASSERT_ERR((((uint32_t)debug_en << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)debug_sel_6 << 8) & ~((uint32_t)0x00007F00)) == 0);
	ASSERT_ERR((((uint32_t)debug_sel_5 << 0) & ~((uint32_t)0x0000007F)) == 0);
	REG_PL_WR(MPU_COMMON_DEBUG_2_ADDR,  ((uint32_t)debug_en << 16) |((uint32_t)debug_sel_6 << 8) |((uint32_t)debug_sel_5 << 0));
}

__INLINE void mpu_common_debug_2_unpack(uint8_t* debug_en, uint8_t* debug_sel_6, uint8_t* debug_sel_5)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_DEBUG_2_ADDR);

	*debug_en = (localVal & ((uint32_t)0x00010000)) >>  16;
	*debug_sel_6 = (localVal & ((uint32_t)0x00007F00)) >>  8;
	*debug_sel_5 = (localVal & ((uint32_t)0x0000007F)) >>  0;
}

__INLINE uint8_t mpu_common_debug_2_debug_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_DEBUG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void mpu_common_debug_2_debug_en_setf(uint8_t debugen)
{
	ASSERT_ERR((((uint32_t)debugen << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(MPU_COMMON_DEBUG_2_ADDR, (REG_PL_RD(MPU_COMMON_DEBUG_2_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)debugen <<16));
}
__INLINE uint8_t mpu_common_debug_2_debug_sel_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_DEBUG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007F00)) >> 8);
}
__INLINE void mpu_common_debug_2_debug_sel_6_setf(uint8_t debugsel6)
{
	ASSERT_ERR((((uint32_t)debugsel6 << 8) & ~((uint32_t)0x00007F00)) == 0);
	REG_PL_WR(MPU_COMMON_DEBUG_2_ADDR, (REG_PL_RD(MPU_COMMON_DEBUG_2_ADDR) & ~((uint32_t)0x00007F00)) | ((uint32_t)debugsel6 <<8));
}
__INLINE uint8_t mpu_common_debug_2_debug_sel_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_DEBUG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000007F)) >> 0);
}
__INLINE void mpu_common_debug_2_debug_sel_5_setf(uint8_t debugsel5)
{
	ASSERT_ERR((((uint32_t)debugsel5 << 0) & ~((uint32_t)0x0000007F)) == 0);
	REG_PL_WR(MPU_COMMON_DEBUG_2_ADDR, (REG_PL_RD(MPU_COMMON_DEBUG_2_ADDR) & ~((uint32_t)0x0000007F)) | ((uint32_t)debugsel5 <<0));
}

/**
 * @brief PADDING_SIGB_PATTERN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    30:00 PAD_PATTERN               0x0
 * </pre>
 */
#define MPU_COMMON_PADDING_SIGB_PATTERN_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x000000B0)
#define MPU_COMMON_PADDING_SIGB_PATTERN_OFFSET      0x000000B0
#define MPU_COMMON_PADDING_SIGB_PATTERN_INDEX       0x0000002C
#define MPU_COMMON_PADDING_SIGB_PATTERN_RESET       0x00000000

__INLINE uint32_t  mpu_common_padding_sigb_pattern_get(void)
{
	return REG_PL_RD(MPU_COMMON_PADDING_SIGB_PATTERN_ADDR);
}

__INLINE void mpu_common_padding_sigb_pattern_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_PADDING_SIGB_PATTERN_ADDR, value);
}

// field definitions
#define MPU_COMMON_PADDING_SIGB_PATTERN_PAD_PATTERN_MASK    ((uint32_t)0x7FFFFFFF)
#define MPU_COMMON_PADDING_SIGB_PATTERN_PAD_PATTERN_LSB    0
#define MPU_COMMON_PADDING_SIGB_PATTERN_PAD_PATTERN_WIDTH    ((uint32_t)0x0000001F)

#define MPU_COMMON_PADDING_SIGB_PATTERN_PAD_PATTERN_RST    0x0

__INLINE uint32_t mpu_common_padding_sigb_pattern_pad_pattern_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_PADDING_SIGB_PATTERN_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void mpu_common_padding_sigb_pattern_pad_pattern_setf(uint32_t padpattern)
{
	ASSERT_ERR((((uint32_t)padpattern << 0) & ~((uint32_t)0x7FFFFFFF)) == 0);
	REG_PL_WR(MPU_COMMON_PADDING_SIGB_PATTERN_ADDR, (uint32_t)padpattern << 0);
}

/**
 * @brief TB_COMMON_CFG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:30 TB_PRE_FEC_PAD_FACTOR     0x0
 *    29    TB_LDPC_EXTRA_SYMBOL      0              
 *    28    TB_STBC                   0              
 *    27:25 TB_NUM_OF_HE_LTF_SYMBOLS  0x0
 *    24    TB_MU_MIMO_LTF_MODE       0              
 *    23:22 TB_GI_AND_LTF_TYPE        0x0
 *    21:20 TB_BW                     0x0
 *    19:08 TB_LENGTH                 0x0
 *    07:04 TB_TRIGGER_TYPE           0x0
 *    03:00 TB_NUM_USERS              0x0
 * </pre>
 */
#define MPU_COMMON_TB_COMMON_CFG_1_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000100)
#define MPU_COMMON_TB_COMMON_CFG_1_OFFSET      0x00000100
#define MPU_COMMON_TB_COMMON_CFG_1_INDEX       0x00000040
#define MPU_COMMON_TB_COMMON_CFG_1_RESET       0x00000000

__INLINE uint32_t  mpu_common_tb_common_cfg_1_get(void)
{
	return REG_PL_RD(MPU_COMMON_TB_COMMON_CFG_1_ADDR);
}

__INLINE void mpu_common_tb_common_cfg_1_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_TB_COMMON_CFG_1_ADDR, value);
}

// field definitions
#define MPU_COMMON_TB_COMMON_CFG_1_TB_PRE_FEC_PAD_FACTOR_MASK    ((uint32_t)0xC0000000)
#define MPU_COMMON_TB_COMMON_CFG_1_TB_PRE_FEC_PAD_FACTOR_LSB    30
#define MPU_COMMON_TB_COMMON_CFG_1_TB_PRE_FEC_PAD_FACTOR_WIDTH    ((uint32_t)0x00000002)
#define MPU_COMMON_TB_COMMON_CFG_1_TB_LDPC_EXTRA_SYMBOL_BIT    ((uint32_t)0x20000000)
#define MPU_COMMON_TB_COMMON_CFG_1_TB_LDPC_EXTRA_SYMBOL_POS    29
#define MPU_COMMON_TB_COMMON_CFG_1_TB_STBC_BIT    ((uint32_t)0x10000000)
#define MPU_COMMON_TB_COMMON_CFG_1_TB_STBC_POS    28
#define MPU_COMMON_TB_COMMON_CFG_1_TB_NUM_OF_HE_LTF_SYMBOLS_MASK    ((uint32_t)0x0E000000)
#define MPU_COMMON_TB_COMMON_CFG_1_TB_NUM_OF_HE_LTF_SYMBOLS_LSB    25
#define MPU_COMMON_TB_COMMON_CFG_1_TB_NUM_OF_HE_LTF_SYMBOLS_WIDTH    ((uint32_t)0x00000003)
#define MPU_COMMON_TB_COMMON_CFG_1_TB_MU_MIMO_LTF_MODE_BIT    ((uint32_t)0x01000000)
#define MPU_COMMON_TB_COMMON_CFG_1_TB_MU_MIMO_LTF_MODE_POS    24
#define MPU_COMMON_TB_COMMON_CFG_1_TB_GI_AND_LTF_TYPE_MASK    ((uint32_t)0x00C00000)
#define MPU_COMMON_TB_COMMON_CFG_1_TB_GI_AND_LTF_TYPE_LSB    22
#define MPU_COMMON_TB_COMMON_CFG_1_TB_GI_AND_LTF_TYPE_WIDTH    ((uint32_t)0x00000002)
#define MPU_COMMON_TB_COMMON_CFG_1_TB_BW_MASK    ((uint32_t)0x00300000)
#define MPU_COMMON_TB_COMMON_CFG_1_TB_BW_LSB    20
#define MPU_COMMON_TB_COMMON_CFG_1_TB_BW_WIDTH    ((uint32_t)0x00000002)
#define MPU_COMMON_TB_COMMON_CFG_1_TB_LENGTH_MASK    ((uint32_t)0x000FFF00)
#define MPU_COMMON_TB_COMMON_CFG_1_TB_LENGTH_LSB    8
#define MPU_COMMON_TB_COMMON_CFG_1_TB_LENGTH_WIDTH    ((uint32_t)0x0000000C)
#define MPU_COMMON_TB_COMMON_CFG_1_TB_TRIGGER_TYPE_MASK    ((uint32_t)0x000000F0)
#define MPU_COMMON_TB_COMMON_CFG_1_TB_TRIGGER_TYPE_LSB    4
#define MPU_COMMON_TB_COMMON_CFG_1_TB_TRIGGER_TYPE_WIDTH    ((uint32_t)0x00000004)
#define MPU_COMMON_TB_COMMON_CFG_1_TB_NUM_USERS_MASK    ((uint32_t)0x0000000F)
#define MPU_COMMON_TB_COMMON_CFG_1_TB_NUM_USERS_LSB    0
#define MPU_COMMON_TB_COMMON_CFG_1_TB_NUM_USERS_WIDTH    ((uint32_t)0x00000004)

#define MPU_COMMON_TB_COMMON_CFG_1_TB_PRE_FEC_PAD_FACTOR_RST    0x0
#define MPU_COMMON_TB_COMMON_CFG_1_TB_LDPC_EXTRA_SYMBOL_RST    0x0
#define MPU_COMMON_TB_COMMON_CFG_1_TB_STBC_RST    0x0
#define MPU_COMMON_TB_COMMON_CFG_1_TB_NUM_OF_HE_LTF_SYMBOLS_RST    0x0
#define MPU_COMMON_TB_COMMON_CFG_1_TB_MU_MIMO_LTF_MODE_RST    0x0
#define MPU_COMMON_TB_COMMON_CFG_1_TB_GI_AND_LTF_TYPE_RST    0x0
#define MPU_COMMON_TB_COMMON_CFG_1_TB_BW_RST    0x0
#define MPU_COMMON_TB_COMMON_CFG_1_TB_LENGTH_RST    0x0
#define MPU_COMMON_TB_COMMON_CFG_1_TB_TRIGGER_TYPE_RST    0x0
#define MPU_COMMON_TB_COMMON_CFG_1_TB_NUM_USERS_RST    0x0

__INLINE void mpu_common_tb_common_cfg_1_pack(uint8_t tb_pre_fec_pad_factor, uint8_t tb_ldpc_extra_symbol, uint8_t tb_stbc, uint8_t tb_num_of_he_ltf_symbols, uint8_t tb_mu_mimo_ltf_mode, uint8_t tb_gi_and_ltf_type, uint8_t tb_bw, uint16_t tb_length, uint8_t tb_trigger_type, uint8_t tb_num_users)
{
	ASSERT_ERR((((uint32_t)tb_pre_fec_pad_factor << 30) & ~((uint32_t)0xC0000000)) == 0);
	ASSERT_ERR((((uint32_t)tb_ldpc_extra_symbol << 29) & ~((uint32_t)0x20000000)) == 0);
	ASSERT_ERR((((uint32_t)tb_stbc << 28) & ~((uint32_t)0x10000000)) == 0);
	ASSERT_ERR((((uint32_t)tb_num_of_he_ltf_symbols << 25) & ~((uint32_t)0x0E000000)) == 0);
	ASSERT_ERR((((uint32_t)tb_mu_mimo_ltf_mode << 24) & ~((uint32_t)0x01000000)) == 0);
	ASSERT_ERR((((uint32_t)tb_gi_and_ltf_type << 22) & ~((uint32_t)0x00C00000)) == 0);
	ASSERT_ERR((((uint32_t)tb_bw << 20) & ~((uint32_t)0x00300000)) == 0);
	ASSERT_ERR((((uint32_t)tb_length << 8) & ~((uint32_t)0x000FFF00)) == 0);
	ASSERT_ERR((((uint32_t)tb_trigger_type << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)tb_num_users << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(MPU_COMMON_TB_COMMON_CFG_1_ADDR,  ((uint32_t)tb_pre_fec_pad_factor << 30) |((uint32_t)tb_ldpc_extra_symbol << 29) |((uint32_t)tb_stbc << 28) |((uint32_t)tb_num_of_he_ltf_symbols << 25) |((uint32_t)tb_mu_mimo_ltf_mode << 24) |((uint32_t)tb_gi_and_ltf_type << 22) |((uint32_t)tb_bw << 20) |((uint32_t)tb_length << 8) |((uint32_t)tb_trigger_type << 4) |((uint32_t)tb_num_users << 0));
}

__INLINE void mpu_common_tb_common_cfg_1_unpack(uint8_t* tb_pre_fec_pad_factor, uint8_t* tb_ldpc_extra_symbol, uint8_t* tb_stbc, uint8_t* tb_num_of_he_ltf_symbols, uint8_t* tb_mu_mimo_ltf_mode, uint8_t* tb_gi_and_ltf_type, uint8_t* tb_bw, uint16_t* tb_length, uint8_t* tb_trigger_type, uint8_t* tb_num_users)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_COMMON_CFG_1_ADDR);

	*tb_pre_fec_pad_factor = (localVal & ((uint32_t)0xC0000000)) >>  30;
	*tb_ldpc_extra_symbol = (localVal & ((uint32_t)0x20000000)) >>  29;
	*tb_stbc = (localVal & ((uint32_t)0x10000000)) >>  28;
	*tb_num_of_he_ltf_symbols = (localVal & ((uint32_t)0x0E000000)) >>  25;
	*tb_mu_mimo_ltf_mode = (localVal & ((uint32_t)0x01000000)) >>  24;
	*tb_gi_and_ltf_type = (localVal & ((uint32_t)0x00C00000)) >>  22;
	*tb_bw = (localVal & ((uint32_t)0x00300000)) >>  20;
	*tb_length = (localVal & ((uint32_t)0x000FFF00)) >>  8;
	*tb_trigger_type = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*tb_num_users = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t mpu_common_tb_common_cfg_1_tb_pre_fec_pad_factor_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_COMMON_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xC0000000)) >> 30);
}
__INLINE void mpu_common_tb_common_cfg_1_tb_pre_fec_pad_factor_setf(uint8_t tbprefecpadfactor)
{
	ASSERT_ERR((((uint32_t)tbprefecpadfactor << 30) & ~((uint32_t)0xC0000000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_COMMON_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_COMMON_CFG_1_ADDR) & ~((uint32_t)0xC0000000)) | ((uint32_t)tbprefecpadfactor <<30));
}
__INLINE uint8_t mpu_common_tb_common_cfg_1_tb_ldpc_extra_symbol_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_COMMON_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x20000000)) >> 29);
}
__INLINE void mpu_common_tb_common_cfg_1_tb_ldpc_extra_symbol_setf(uint8_t tbldpcextrasymbol)
{
	ASSERT_ERR((((uint32_t)tbldpcextrasymbol << 29) & ~((uint32_t)0x20000000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_COMMON_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_COMMON_CFG_1_ADDR) & ~((uint32_t)0x20000000)) | ((uint32_t)tbldpcextrasymbol <<29));
}
__INLINE uint8_t mpu_common_tb_common_cfg_1_tb_stbc_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_COMMON_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x10000000)) >> 28);
}
__INLINE void mpu_common_tb_common_cfg_1_tb_stbc_setf(uint8_t tbstbc)
{
	ASSERT_ERR((((uint32_t)tbstbc << 28) & ~((uint32_t)0x10000000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_COMMON_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_COMMON_CFG_1_ADDR) & ~((uint32_t)0x10000000)) | ((uint32_t)tbstbc <<28));
}
__INLINE uint8_t mpu_common_tb_common_cfg_1_tb_num_of_he_ltf_symbols_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_COMMON_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0E000000)) >> 25);
}
__INLINE void mpu_common_tb_common_cfg_1_tb_num_of_he_ltf_symbols_setf(uint8_t tbnumofheltfsymbols)
{
	ASSERT_ERR((((uint32_t)tbnumofheltfsymbols << 25) & ~((uint32_t)0x0E000000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_COMMON_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_COMMON_CFG_1_ADDR) & ~((uint32_t)0x0E000000)) | ((uint32_t)tbnumofheltfsymbols <<25));
}
__INLINE uint8_t mpu_common_tb_common_cfg_1_tb_mu_mimo_ltf_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_COMMON_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01000000)) >> 24);
}
__INLINE void mpu_common_tb_common_cfg_1_tb_mu_mimo_ltf_mode_setf(uint8_t tbmumimoltfmode)
{
	ASSERT_ERR((((uint32_t)tbmumimoltfmode << 24) & ~((uint32_t)0x01000000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_COMMON_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_COMMON_CFG_1_ADDR) & ~((uint32_t)0x01000000)) | ((uint32_t)tbmumimoltfmode <<24));
}
__INLINE uint8_t mpu_common_tb_common_cfg_1_tb_gi_and_ltf_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_COMMON_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00C00000)) >> 22);
}
__INLINE void mpu_common_tb_common_cfg_1_tb_gi_and_ltf_type_setf(uint8_t tbgiandltftype)
{
	ASSERT_ERR((((uint32_t)tbgiandltftype << 22) & ~((uint32_t)0x00C00000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_COMMON_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_COMMON_CFG_1_ADDR) & ~((uint32_t)0x00C00000)) | ((uint32_t)tbgiandltftype <<22));
}
__INLINE uint8_t mpu_common_tb_common_cfg_1_tb_bw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_COMMON_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00300000)) >> 20);
}
__INLINE void mpu_common_tb_common_cfg_1_tb_bw_setf(uint8_t tbbw)
{
	ASSERT_ERR((((uint32_t)tbbw << 20) & ~((uint32_t)0x00300000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_COMMON_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_COMMON_CFG_1_ADDR) & ~((uint32_t)0x00300000)) | ((uint32_t)tbbw <<20));
}
__INLINE uint16_t mpu_common_tb_common_cfg_1_tb_length_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_COMMON_CFG_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000FFF00)) >> 8);
}
__INLINE void mpu_common_tb_common_cfg_1_tb_length_setf(uint16_t tblength)
{
	ASSERT_ERR((((uint32_t)tblength << 8) & ~((uint32_t)0x000FFF00)) == 0);
	REG_PL_WR(MPU_COMMON_TB_COMMON_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_COMMON_CFG_1_ADDR) & ~((uint32_t)0x000FFF00)) | ((uint32_t)tblength <<8));
}
__INLINE uint8_t mpu_common_tb_common_cfg_1_tb_trigger_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_COMMON_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE void mpu_common_tb_common_cfg_1_tb_trigger_type_setf(uint8_t tbtriggertype)
{
	ASSERT_ERR((((uint32_t)tbtriggertype << 4) & ~((uint32_t)0x000000F0)) == 0);
	REG_PL_WR(MPU_COMMON_TB_COMMON_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_COMMON_CFG_1_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)tbtriggertype <<4));
}
__INLINE uint8_t mpu_common_tb_common_cfg_1_tb_num_users_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_COMMON_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void mpu_common_tb_common_cfg_1_tb_num_users_setf(uint8_t tbnumusers)
{
	ASSERT_ERR((((uint32_t)tbnumusers << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(MPU_COMMON_TB_COMMON_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_COMMON_CFG_1_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)tbnumusers <<0));
}

/**
 * @brief TB_COMMON_CFG_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    11:08 TB_RATE                   0xB
 *    07:02 TB_RESERVED               0x0
 *    01    TB_DOPPLER                0              
 *    00    TB_PE_DISAMBIGUITY        0              
 * </pre>
 */
#define MPU_COMMON_TB_COMMON_CFG_2_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000104)
#define MPU_COMMON_TB_COMMON_CFG_2_OFFSET      0x00000104
#define MPU_COMMON_TB_COMMON_CFG_2_INDEX       0x00000041
#define MPU_COMMON_TB_COMMON_CFG_2_RESET       0x00000B00

__INLINE uint32_t  mpu_common_tb_common_cfg_2_get(void)
{
	return REG_PL_RD(MPU_COMMON_TB_COMMON_CFG_2_ADDR);
}

__INLINE void mpu_common_tb_common_cfg_2_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_TB_COMMON_CFG_2_ADDR, value);
}

// field definitions
#define MPU_COMMON_TB_COMMON_CFG_2_TB_RATE_MASK    ((uint32_t)0x00000F00)
#define MPU_COMMON_TB_COMMON_CFG_2_TB_RATE_LSB    8
#define MPU_COMMON_TB_COMMON_CFG_2_TB_RATE_WIDTH    ((uint32_t)0x00000004)
#define MPU_COMMON_TB_COMMON_CFG_2_TB_RESERVED_MASK    ((uint32_t)0x000000FC)
#define MPU_COMMON_TB_COMMON_CFG_2_TB_RESERVED_LSB    2
#define MPU_COMMON_TB_COMMON_CFG_2_TB_RESERVED_WIDTH    ((uint32_t)0x00000006)
#define MPU_COMMON_TB_COMMON_CFG_2_TB_DOPPLER_BIT    ((uint32_t)0x00000002)
#define MPU_COMMON_TB_COMMON_CFG_2_TB_DOPPLER_POS    1
#define MPU_COMMON_TB_COMMON_CFG_2_TB_PE_DISAMBIGUITY_BIT    ((uint32_t)0x00000001)
#define MPU_COMMON_TB_COMMON_CFG_2_TB_PE_DISAMBIGUITY_POS    0

#define MPU_COMMON_TB_COMMON_CFG_2_TB_RATE_RST    0xB
#define MPU_COMMON_TB_COMMON_CFG_2_TB_RESERVED_RST    0x0
#define MPU_COMMON_TB_COMMON_CFG_2_TB_DOPPLER_RST    0x0
#define MPU_COMMON_TB_COMMON_CFG_2_TB_PE_DISAMBIGUITY_RST    0x0

__INLINE void mpu_common_tb_common_cfg_2_pack(uint8_t tb_rate, uint8_t tb_reserved, uint8_t tb_doppler, uint8_t tb_pe_disambiguity)
{
	ASSERT_ERR((((uint32_t)tb_rate << 8) & ~((uint32_t)0x00000F00)) == 0);
	ASSERT_ERR((((uint32_t)tb_reserved << 2) & ~((uint32_t)0x000000FC)) == 0);
	ASSERT_ERR((((uint32_t)tb_doppler << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)tb_pe_disambiguity << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MPU_COMMON_TB_COMMON_CFG_2_ADDR,  ((uint32_t)tb_rate << 8) |((uint32_t)tb_reserved << 2) |((uint32_t)tb_doppler << 1) |((uint32_t)tb_pe_disambiguity << 0));
}

__INLINE void mpu_common_tb_common_cfg_2_unpack(uint8_t* tb_rate, uint8_t* tb_reserved, uint8_t* tb_doppler, uint8_t* tb_pe_disambiguity)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_COMMON_CFG_2_ADDR);

	*tb_rate = (localVal & ((uint32_t)0x00000F00)) >>  8;
	*tb_reserved = (localVal & ((uint32_t)0x000000FC)) >>  2;
	*tb_doppler = (localVal & ((uint32_t)0x00000002)) >>  1;
	*tb_pe_disambiguity = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t mpu_common_tb_common_cfg_2_tb_rate_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_COMMON_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000F00)) >> 8);
}
__INLINE void mpu_common_tb_common_cfg_2_tb_rate_setf(uint8_t tbrate)
{
	ASSERT_ERR((((uint32_t)tbrate << 8) & ~((uint32_t)0x00000F00)) == 0);
	REG_PL_WR(MPU_COMMON_TB_COMMON_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_TB_COMMON_CFG_2_ADDR) & ~((uint32_t)0x00000F00)) | ((uint32_t)tbrate <<8));
}
__INLINE uint8_t mpu_common_tb_common_cfg_2_tb_reserved_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_COMMON_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FC)) >> 2);
}
__INLINE void mpu_common_tb_common_cfg_2_tb_reserved_setf(uint8_t tbreserved)
{
	ASSERT_ERR((((uint32_t)tbreserved << 2) & ~((uint32_t)0x000000FC)) == 0);
	REG_PL_WR(MPU_COMMON_TB_COMMON_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_TB_COMMON_CFG_2_ADDR) & ~((uint32_t)0x000000FC)) | ((uint32_t)tbreserved <<2));
}
__INLINE uint8_t mpu_common_tb_common_cfg_2_tb_doppler_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_COMMON_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void mpu_common_tb_common_cfg_2_tb_doppler_setf(uint8_t tbdoppler)
{
	ASSERT_ERR((((uint32_t)tbdoppler << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(MPU_COMMON_TB_COMMON_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_TB_COMMON_CFG_2_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)tbdoppler <<1));
}
__INLINE uint8_t mpu_common_tb_common_cfg_2_tb_pe_disambiguity_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_COMMON_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void mpu_common_tb_common_cfg_2_tb_pe_disambiguity_setf(uint8_t tbpedisambiguity)
{
	ASSERT_ERR((((uint32_t)tbpedisambiguity << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MPU_COMMON_TB_COMMON_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_TB_COMMON_CFG_2_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)tbpedisambiguity <<0));
}

/**
 * @brief TB_USER_0_CFG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26:24 TB_USER0_NSTS             0x0
 *    22:20 TB_USER0_STARTING_STS     0x0
 *    19    TB_USER0_CODING_TYPE      0              
 *    18:16 TB_USER0_RU_TYPE          0x0
 *    14    TB_USER0_RU_BAND_MAC      0              
 *    13:08 TB_USER0_RU_INDEX         0x0
 *    07:00 TB_USER0_RU_ALLOCATION    0x0
 * </pre>
 */
#define MPU_COMMON_TB_USER_0_CFG_1_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000108)
#define MPU_COMMON_TB_USER_0_CFG_1_OFFSET      0x00000108
#define MPU_COMMON_TB_USER_0_CFG_1_INDEX       0x00000042
#define MPU_COMMON_TB_USER_0_CFG_1_RESET       0x00000000

__INLINE uint32_t  mpu_common_tb_user_0_cfg_1_get(void)
{
	return REG_PL_RD(MPU_COMMON_TB_USER_0_CFG_1_ADDR);
}

__INLINE void mpu_common_tb_user_0_cfg_1_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_TB_USER_0_CFG_1_ADDR, value);
}

// field definitions
#define MPU_COMMON_TB_USER_0_CFG_1_TB_USER_0_NSTS_MASK    ((uint32_t)0x07000000)
#define MPU_COMMON_TB_USER_0_CFG_1_TB_USER_0_NSTS_LSB    24
#define MPU_COMMON_TB_USER_0_CFG_1_TB_USER_0_NSTS_WIDTH    ((uint32_t)0x00000003)
#define MPU_COMMON_TB_USER_0_CFG_1_TB_USER_0_STARTING_STS_MASK    ((uint32_t)0x00700000)
#define MPU_COMMON_TB_USER_0_CFG_1_TB_USER_0_STARTING_STS_LSB    20
#define MPU_COMMON_TB_USER_0_CFG_1_TB_USER_0_STARTING_STS_WIDTH    ((uint32_t)0x00000003)
#define MPU_COMMON_TB_USER_0_CFG_1_TB_USER_0_CODING_TYPE_BIT    ((uint32_t)0x00080000)
#define MPU_COMMON_TB_USER_0_CFG_1_TB_USER_0_CODING_TYPE_POS    19
#define MPU_COMMON_TB_USER_0_CFG_1_TB_USER_0_RU_TYPE_MASK    ((uint32_t)0x00070000)
#define MPU_COMMON_TB_USER_0_CFG_1_TB_USER_0_RU_TYPE_LSB    16
#define MPU_COMMON_TB_USER_0_CFG_1_TB_USER_0_RU_TYPE_WIDTH    ((uint32_t)0x00000003)
#define MPU_COMMON_TB_USER_0_CFG_1_TB_USER_0_RU_BAND_MAC_BIT    ((uint32_t)0x00004000)
#define MPU_COMMON_TB_USER_0_CFG_1_TB_USER_0_RU_BAND_MAC_POS    14
#define MPU_COMMON_TB_USER_0_CFG_1_TB_USER_0_RU_INDEX_MASK    ((uint32_t)0x00003F00)
#define MPU_COMMON_TB_USER_0_CFG_1_TB_USER_0_RU_INDEX_LSB    8
#define MPU_COMMON_TB_USER_0_CFG_1_TB_USER_0_RU_INDEX_WIDTH    ((uint32_t)0x00000006)
#define MPU_COMMON_TB_USER_0_CFG_1_TB_USER_0_RU_ALLOCATION_MASK    ((uint32_t)0x000000FF)
#define MPU_COMMON_TB_USER_0_CFG_1_TB_USER_0_RU_ALLOCATION_LSB    0
#define MPU_COMMON_TB_USER_0_CFG_1_TB_USER_0_RU_ALLOCATION_WIDTH    ((uint32_t)0x00000008)

#define MPU_COMMON_TB_USER_0_CFG_1_TB_USER_0_NSTS_RST    0x0
#define MPU_COMMON_TB_USER_0_CFG_1_TB_USER_0_STARTING_STS_RST    0x0
#define MPU_COMMON_TB_USER_0_CFG_1_TB_USER_0_CODING_TYPE_RST    0x0
#define MPU_COMMON_TB_USER_0_CFG_1_TB_USER_0_RU_TYPE_RST    0x0
#define MPU_COMMON_TB_USER_0_CFG_1_TB_USER_0_RU_BAND_MAC_RST    0x0
#define MPU_COMMON_TB_USER_0_CFG_1_TB_USER_0_RU_INDEX_RST    0x0
#define MPU_COMMON_TB_USER_0_CFG_1_TB_USER_0_RU_ALLOCATION_RST    0x0

__INLINE void mpu_common_tb_user_0_cfg_1_pack(uint8_t tb_user0_nsts, uint8_t tb_user0_starting_sts, uint8_t tb_user0_coding_type, uint8_t tb_user0_ru_type, uint8_t tb_user0_ru_band_mac, uint8_t tb_user0_ru_index, uint8_t tb_user0_ru_allocation)
{
	ASSERT_ERR((((uint32_t)tb_user0_nsts << 24) & ~((uint32_t)0x07000000)) == 0);
	ASSERT_ERR((((uint32_t)tb_user0_starting_sts << 20) & ~((uint32_t)0x00700000)) == 0);
	ASSERT_ERR((((uint32_t)tb_user0_coding_type << 19) & ~((uint32_t)0x00080000)) == 0);
	ASSERT_ERR((((uint32_t)tb_user0_ru_type << 16) & ~((uint32_t)0x00070000)) == 0);
	ASSERT_ERR((((uint32_t)tb_user0_ru_band_mac << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)tb_user0_ru_index << 8) & ~((uint32_t)0x00003F00)) == 0);
	ASSERT_ERR((((uint32_t)tb_user0_ru_allocation << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_0_CFG_1_ADDR,  ((uint32_t)tb_user0_nsts << 24) |((uint32_t)tb_user0_starting_sts << 20) |((uint32_t)tb_user0_coding_type << 19) |((uint32_t)tb_user0_ru_type << 16) |((uint32_t)tb_user0_ru_band_mac << 14) |((uint32_t)tb_user0_ru_index << 8) |((uint32_t)tb_user0_ru_allocation << 0));
}

__INLINE void mpu_common_tb_user_0_cfg_1_unpack(uint8_t* tb_user0_nsts, uint8_t* tb_user0_starting_sts, uint8_t* tb_user0_coding_type, uint8_t* tb_user0_ru_type, uint8_t* tb_user0_ru_band_mac, uint8_t* tb_user0_ru_index, uint8_t* tb_user0_ru_allocation)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_0_CFG_1_ADDR);

	*tb_user0_nsts = (localVal & ((uint32_t)0x07000000)) >>  24;
	*tb_user0_starting_sts = (localVal & ((uint32_t)0x00700000)) >>  20;
	*tb_user0_coding_type = (localVal & ((uint32_t)0x00080000)) >>  19;
	*tb_user0_ru_type = (localVal & ((uint32_t)0x00070000)) >>  16;
	*tb_user0_ru_band_mac = (localVal & ((uint32_t)0x00004000)) >>  14;
	*tb_user0_ru_index = (localVal & ((uint32_t)0x00003F00)) >>  8;
	*tb_user0_ru_allocation = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t mpu_common_tb_user_0_cfg_1_tb_user_0_nsts_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_0_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE void mpu_common_tb_user_0_cfg_1_tb_user_0_nsts_setf(uint8_t tbuser0nsts)
{
	ASSERT_ERR((((uint32_t)tbuser0nsts << 24) & ~((uint32_t)0x07000000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_0_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_0_CFG_1_ADDR) & ~((uint32_t)0x07000000)) | ((uint32_t)tbuser0nsts <<24));
}
__INLINE uint8_t mpu_common_tb_user_0_cfg_1_tb_user_0_starting_sts_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_0_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00700000)) >> 20);
}
__INLINE void mpu_common_tb_user_0_cfg_1_tb_user_0_starting_sts_setf(uint8_t tbuser0startingsts)
{
	ASSERT_ERR((((uint32_t)tbuser0startingsts << 20) & ~((uint32_t)0x00700000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_0_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_0_CFG_1_ADDR) & ~((uint32_t)0x00700000)) | ((uint32_t)tbuser0startingsts <<20));
}
__INLINE uint8_t mpu_common_tb_user_0_cfg_1_tb_user_0_coding_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_0_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00080000)) >> 19);
}
__INLINE void mpu_common_tb_user_0_cfg_1_tb_user_0_coding_type_setf(uint8_t tbuser0codingtype)
{
	ASSERT_ERR((((uint32_t)tbuser0codingtype << 19) & ~((uint32_t)0x00080000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_0_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_0_CFG_1_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)tbuser0codingtype <<19));
}
__INLINE uint8_t mpu_common_tb_user_0_cfg_1_tb_user_0_ru_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_0_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00070000)) >> 16);
}
__INLINE void mpu_common_tb_user_0_cfg_1_tb_user_0_ru_type_setf(uint8_t tbuser0rutype)
{
	ASSERT_ERR((((uint32_t)tbuser0rutype << 16) & ~((uint32_t)0x00070000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_0_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_0_CFG_1_ADDR) & ~((uint32_t)0x00070000)) | ((uint32_t)tbuser0rutype <<16));
}
__INLINE uint8_t mpu_common_tb_user_0_cfg_1_tb_user_0_ru_band_mac_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_0_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void mpu_common_tb_user_0_cfg_1_tb_user_0_ru_band_mac_setf(uint8_t tbuser0rubandmac)
{
	ASSERT_ERR((((uint32_t)tbuser0rubandmac << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_0_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_0_CFG_1_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)tbuser0rubandmac <<14));
}
__INLINE uint8_t mpu_common_tb_user_0_cfg_1_tb_user_0_ru_index_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_0_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00003F00)) >> 8);
}
__INLINE void mpu_common_tb_user_0_cfg_1_tb_user_0_ru_index_setf(uint8_t tbuser0ruindex)
{
	ASSERT_ERR((((uint32_t)tbuser0ruindex << 8) & ~((uint32_t)0x00003F00)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_0_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_0_CFG_1_ADDR) & ~((uint32_t)0x00003F00)) | ((uint32_t)tbuser0ruindex <<8));
}
__INLINE uint8_t mpu_common_tb_user_0_cfg_1_tb_user_0_ru_allocation_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_0_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void mpu_common_tb_user_0_cfg_1_tb_user_0_ru_allocation_setf(uint8_t tbuser0ruallocation)
{
	ASSERT_ERR((((uint32_t)tbuser0ruallocation << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_0_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_0_CFG_1_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)tbuser0ruallocation <<0));
}

/**
 * @brief TB_USER_0_CFG_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    14:08 TB_USER0_TARGET_RSSI      0x0
 *    07:05 TB_USER0_RESERVED         0x0
 *    04    TB_USER0_DCM              0              
 *    03:00 TB_USER0_MCS              0x0
 * </pre>
 */
#define MPU_COMMON_TB_USER_0_CFG_2_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x0000010C)
#define MPU_COMMON_TB_USER_0_CFG_2_OFFSET      0x0000010C
#define MPU_COMMON_TB_USER_0_CFG_2_INDEX       0x00000043
#define MPU_COMMON_TB_USER_0_CFG_2_RESET       0x00000000

__INLINE uint32_t  mpu_common_tb_user_0_cfg_2_get(void)
{
	return REG_PL_RD(MPU_COMMON_TB_USER_0_CFG_2_ADDR);
}

__INLINE void mpu_common_tb_user_0_cfg_2_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_TB_USER_0_CFG_2_ADDR, value);
}

// field definitions
#define MPU_COMMON_TB_USER_0_CFG_2_TB_USER_0_TARGET_RSSI_MASK    ((uint32_t)0x00007F00)
#define MPU_COMMON_TB_USER_0_CFG_2_TB_USER_0_TARGET_RSSI_LSB    8
#define MPU_COMMON_TB_USER_0_CFG_2_TB_USER_0_TARGET_RSSI_WIDTH    ((uint32_t)0x00000007)
#define MPU_COMMON_TB_USER_0_CFG_2_TB_USER_0_RESERVED_MASK    ((uint32_t)0x000000E0)
#define MPU_COMMON_TB_USER_0_CFG_2_TB_USER_0_RESERVED_LSB    5
#define MPU_COMMON_TB_USER_0_CFG_2_TB_USER_0_RESERVED_WIDTH    ((uint32_t)0x00000003)
#define MPU_COMMON_TB_USER_0_CFG_2_TB_USER_0_DCM_BIT    ((uint32_t)0x00000010)
#define MPU_COMMON_TB_USER_0_CFG_2_TB_USER_0_DCM_POS    4
#define MPU_COMMON_TB_USER_0_CFG_2_TB_USER_0_MCS_MASK    ((uint32_t)0x0000000F)
#define MPU_COMMON_TB_USER_0_CFG_2_TB_USER_0_MCS_LSB    0
#define MPU_COMMON_TB_USER_0_CFG_2_TB_USER_0_MCS_WIDTH    ((uint32_t)0x00000004)

#define MPU_COMMON_TB_USER_0_CFG_2_TB_USER_0_TARGET_RSSI_RST    0x0
#define MPU_COMMON_TB_USER_0_CFG_2_TB_USER_0_RESERVED_RST    0x0
#define MPU_COMMON_TB_USER_0_CFG_2_TB_USER_0_DCM_RST    0x0
#define MPU_COMMON_TB_USER_0_CFG_2_TB_USER_0_MCS_RST    0x0

__INLINE void mpu_common_tb_user_0_cfg_2_pack(uint8_t tb_user0_target_rssi, uint8_t tb_user0_reserved, uint8_t tb_user0_dcm, uint8_t tb_user0_mcs)
{
	ASSERT_ERR((((uint32_t)tb_user0_target_rssi << 8) & ~((uint32_t)0x00007F00)) == 0);
	ASSERT_ERR((((uint32_t)tb_user0_reserved << 5) & ~((uint32_t)0x000000E0)) == 0);
	ASSERT_ERR((((uint32_t)tb_user0_dcm << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)tb_user0_mcs << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_0_CFG_2_ADDR,  ((uint32_t)tb_user0_target_rssi << 8) |((uint32_t)tb_user0_reserved << 5) |((uint32_t)tb_user0_dcm << 4) |((uint32_t)tb_user0_mcs << 0));
}

__INLINE void mpu_common_tb_user_0_cfg_2_unpack(uint8_t* tb_user0_target_rssi, uint8_t* tb_user0_reserved, uint8_t* tb_user0_dcm, uint8_t* tb_user0_mcs)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_0_CFG_2_ADDR);

	*tb_user0_target_rssi = (localVal & ((uint32_t)0x00007F00)) >>  8;
	*tb_user0_reserved = (localVal & ((uint32_t)0x000000E0)) >>  5;
	*tb_user0_dcm = (localVal & ((uint32_t)0x00000010)) >>  4;
	*tb_user0_mcs = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t mpu_common_tb_user_0_cfg_2_tb_user_0_target_rssi_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_0_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007F00)) >> 8);
}
__INLINE void mpu_common_tb_user_0_cfg_2_tb_user_0_target_rssi_setf(uint8_t tbuser0targetrssi)
{
	ASSERT_ERR((((uint32_t)tbuser0targetrssi << 8) & ~((uint32_t)0x00007F00)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_0_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_0_CFG_2_ADDR) & ~((uint32_t)0x00007F00)) | ((uint32_t)tbuser0targetrssi <<8));
}
__INLINE uint8_t mpu_common_tb_user_0_cfg_2_tb_user_0_reserved_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_0_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000E0)) >> 5);
}
__INLINE void mpu_common_tb_user_0_cfg_2_tb_user_0_reserved_setf(uint8_t tbuser0reserved)
{
	ASSERT_ERR((((uint32_t)tbuser0reserved << 5) & ~((uint32_t)0x000000E0)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_0_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_0_CFG_2_ADDR) & ~((uint32_t)0x000000E0)) | ((uint32_t)tbuser0reserved <<5));
}
__INLINE uint8_t mpu_common_tb_user_0_cfg_2_tb_user_0_dcm_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_0_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void mpu_common_tb_user_0_cfg_2_tb_user_0_dcm_setf(uint8_t tbuser0dcm)
{
	ASSERT_ERR((((uint32_t)tbuser0dcm << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_0_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_0_CFG_2_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)tbuser0dcm <<4));
}
__INLINE uint8_t mpu_common_tb_user_0_cfg_2_tb_user_0_mcs_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_0_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void mpu_common_tb_user_0_cfg_2_tb_user_0_mcs_setf(uint8_t tbuser0mcs)
{
	ASSERT_ERR((((uint32_t)tbuser0mcs << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_0_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_0_CFG_2_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)tbuser0mcs <<0));
}

/**
 * @brief TB_USER_1_CFG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26:24 TB_USER1_NSTS             0x0
 *    22:20 TB_USER1_STARTING_STS     0x0
 *    19    TB_USER1_CODING_TYPE      0              
 *    18:16 TB_USER1_RU_TYPE          0x0
 *    14    TB_USER1_RU_BAND_MAC      0              
 *    13:08 TB_USER1_RU_INDEX         0x0
 *    07:00 TB_USER1_RU_ALLOCATION    0x0
 * </pre>
 */
#define MPU_COMMON_TB_USER_1_CFG_1_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000110)
#define MPU_COMMON_TB_USER_1_CFG_1_OFFSET      0x00000110
#define MPU_COMMON_TB_USER_1_CFG_1_INDEX       0x00000044
#define MPU_COMMON_TB_USER_1_CFG_1_RESET       0x00000000

__INLINE uint32_t  mpu_common_tb_user_1_cfg_1_get(void)
{
	return REG_PL_RD(MPU_COMMON_TB_USER_1_CFG_1_ADDR);
}

__INLINE void mpu_common_tb_user_1_cfg_1_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_TB_USER_1_CFG_1_ADDR, value);
}

// field definitions
#define MPU_COMMON_TB_USER_1_CFG_1_TB_USER_1_NSTS_MASK    ((uint32_t)0x07000000)
#define MPU_COMMON_TB_USER_1_CFG_1_TB_USER_1_NSTS_LSB    24
#define MPU_COMMON_TB_USER_1_CFG_1_TB_USER_1_NSTS_WIDTH    ((uint32_t)0x00000003)
#define MPU_COMMON_TB_USER_1_CFG_1_TB_USER_1_STARTING_STS_MASK    ((uint32_t)0x00700000)
#define MPU_COMMON_TB_USER_1_CFG_1_TB_USER_1_STARTING_STS_LSB    20
#define MPU_COMMON_TB_USER_1_CFG_1_TB_USER_1_STARTING_STS_WIDTH    ((uint32_t)0x00000003)
#define MPU_COMMON_TB_USER_1_CFG_1_TB_USER_1_CODING_TYPE_BIT    ((uint32_t)0x00080000)
#define MPU_COMMON_TB_USER_1_CFG_1_TB_USER_1_CODING_TYPE_POS    19
#define MPU_COMMON_TB_USER_1_CFG_1_TB_USER_1_RU_TYPE_MASK    ((uint32_t)0x00070000)
#define MPU_COMMON_TB_USER_1_CFG_1_TB_USER_1_RU_TYPE_LSB    16
#define MPU_COMMON_TB_USER_1_CFG_1_TB_USER_1_RU_TYPE_WIDTH    ((uint32_t)0x00000003)
#define MPU_COMMON_TB_USER_1_CFG_1_TB_USER_1_RU_BAND_MAC_BIT    ((uint32_t)0x00004000)
#define MPU_COMMON_TB_USER_1_CFG_1_TB_USER_1_RU_BAND_MAC_POS    14
#define MPU_COMMON_TB_USER_1_CFG_1_TB_USER_1_RU_INDEX_MASK    ((uint32_t)0x00003F00)
#define MPU_COMMON_TB_USER_1_CFG_1_TB_USER_1_RU_INDEX_LSB    8
#define MPU_COMMON_TB_USER_1_CFG_1_TB_USER_1_RU_INDEX_WIDTH    ((uint32_t)0x00000006)
#define MPU_COMMON_TB_USER_1_CFG_1_TB_USER_1_RU_ALLOCATION_MASK    ((uint32_t)0x000000FF)
#define MPU_COMMON_TB_USER_1_CFG_1_TB_USER_1_RU_ALLOCATION_LSB    0
#define MPU_COMMON_TB_USER_1_CFG_1_TB_USER_1_RU_ALLOCATION_WIDTH    ((uint32_t)0x00000008)

#define MPU_COMMON_TB_USER_1_CFG_1_TB_USER_1_NSTS_RST    0x0
#define MPU_COMMON_TB_USER_1_CFG_1_TB_USER_1_STARTING_STS_RST    0x0
#define MPU_COMMON_TB_USER_1_CFG_1_TB_USER_1_CODING_TYPE_RST    0x0
#define MPU_COMMON_TB_USER_1_CFG_1_TB_USER_1_RU_TYPE_RST    0x0
#define MPU_COMMON_TB_USER_1_CFG_1_TB_USER_1_RU_BAND_MAC_RST    0x0
#define MPU_COMMON_TB_USER_1_CFG_1_TB_USER_1_RU_INDEX_RST    0x0
#define MPU_COMMON_TB_USER_1_CFG_1_TB_USER_1_RU_ALLOCATION_RST    0x0

__INLINE void mpu_common_tb_user_1_cfg_1_pack(uint8_t tb_user1_nsts, uint8_t tb_user1_starting_sts, uint8_t tb_user1_coding_type, uint8_t tb_user1_ru_type, uint8_t tb_user1_ru_band_mac, uint8_t tb_user1_ru_index, uint8_t tb_user1_ru_allocation)
{
	ASSERT_ERR((((uint32_t)tb_user1_nsts << 24) & ~((uint32_t)0x07000000)) == 0);
	ASSERT_ERR((((uint32_t)tb_user1_starting_sts << 20) & ~((uint32_t)0x00700000)) == 0);
	ASSERT_ERR((((uint32_t)tb_user1_coding_type << 19) & ~((uint32_t)0x00080000)) == 0);
	ASSERT_ERR((((uint32_t)tb_user1_ru_type << 16) & ~((uint32_t)0x00070000)) == 0);
	ASSERT_ERR((((uint32_t)tb_user1_ru_band_mac << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)tb_user1_ru_index << 8) & ~((uint32_t)0x00003F00)) == 0);
	ASSERT_ERR((((uint32_t)tb_user1_ru_allocation << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_1_CFG_1_ADDR,  ((uint32_t)tb_user1_nsts << 24) |((uint32_t)tb_user1_starting_sts << 20) |((uint32_t)tb_user1_coding_type << 19) |((uint32_t)tb_user1_ru_type << 16) |((uint32_t)tb_user1_ru_band_mac << 14) |((uint32_t)tb_user1_ru_index << 8) |((uint32_t)tb_user1_ru_allocation << 0));
}

__INLINE void mpu_common_tb_user_1_cfg_1_unpack(uint8_t* tb_user1_nsts, uint8_t* tb_user1_starting_sts, uint8_t* tb_user1_coding_type, uint8_t* tb_user1_ru_type, uint8_t* tb_user1_ru_band_mac, uint8_t* tb_user1_ru_index, uint8_t* tb_user1_ru_allocation)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_1_CFG_1_ADDR);

	*tb_user1_nsts = (localVal & ((uint32_t)0x07000000)) >>  24;
	*tb_user1_starting_sts = (localVal & ((uint32_t)0x00700000)) >>  20;
	*tb_user1_coding_type = (localVal & ((uint32_t)0x00080000)) >>  19;
	*tb_user1_ru_type = (localVal & ((uint32_t)0x00070000)) >>  16;
	*tb_user1_ru_band_mac = (localVal & ((uint32_t)0x00004000)) >>  14;
	*tb_user1_ru_index = (localVal & ((uint32_t)0x00003F00)) >>  8;
	*tb_user1_ru_allocation = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t mpu_common_tb_user_1_cfg_1_tb_user_1_nsts_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_1_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE void mpu_common_tb_user_1_cfg_1_tb_user_1_nsts_setf(uint8_t tbuser1nsts)
{
	ASSERT_ERR((((uint32_t)tbuser1nsts << 24) & ~((uint32_t)0x07000000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_1_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_1_CFG_1_ADDR) & ~((uint32_t)0x07000000)) | ((uint32_t)tbuser1nsts <<24));
}
__INLINE uint8_t mpu_common_tb_user_1_cfg_1_tb_user_1_starting_sts_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_1_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00700000)) >> 20);
}
__INLINE void mpu_common_tb_user_1_cfg_1_tb_user_1_starting_sts_setf(uint8_t tbuser1startingsts)
{
	ASSERT_ERR((((uint32_t)tbuser1startingsts << 20) & ~((uint32_t)0x00700000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_1_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_1_CFG_1_ADDR) & ~((uint32_t)0x00700000)) | ((uint32_t)tbuser1startingsts <<20));
}
__INLINE uint8_t mpu_common_tb_user_1_cfg_1_tb_user_1_coding_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_1_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00080000)) >> 19);
}
__INLINE void mpu_common_tb_user_1_cfg_1_tb_user_1_coding_type_setf(uint8_t tbuser1codingtype)
{
	ASSERT_ERR((((uint32_t)tbuser1codingtype << 19) & ~((uint32_t)0x00080000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_1_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_1_CFG_1_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)tbuser1codingtype <<19));
}
__INLINE uint8_t mpu_common_tb_user_1_cfg_1_tb_user_1_ru_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_1_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00070000)) >> 16);
}
__INLINE void mpu_common_tb_user_1_cfg_1_tb_user_1_ru_type_setf(uint8_t tbuser1rutype)
{
	ASSERT_ERR((((uint32_t)tbuser1rutype << 16) & ~((uint32_t)0x00070000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_1_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_1_CFG_1_ADDR) & ~((uint32_t)0x00070000)) | ((uint32_t)tbuser1rutype <<16));
}
__INLINE uint8_t mpu_common_tb_user_1_cfg_1_tb_user_1_ru_band_mac_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_1_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void mpu_common_tb_user_1_cfg_1_tb_user_1_ru_band_mac_setf(uint8_t tbuser1rubandmac)
{
	ASSERT_ERR((((uint32_t)tbuser1rubandmac << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_1_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_1_CFG_1_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)tbuser1rubandmac <<14));
}
__INLINE uint8_t mpu_common_tb_user_1_cfg_1_tb_user_1_ru_index_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_1_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00003F00)) >> 8);
}
__INLINE void mpu_common_tb_user_1_cfg_1_tb_user_1_ru_index_setf(uint8_t tbuser1ruindex)
{
	ASSERT_ERR((((uint32_t)tbuser1ruindex << 8) & ~((uint32_t)0x00003F00)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_1_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_1_CFG_1_ADDR) & ~((uint32_t)0x00003F00)) | ((uint32_t)tbuser1ruindex <<8));
}
__INLINE uint8_t mpu_common_tb_user_1_cfg_1_tb_user_1_ru_allocation_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_1_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void mpu_common_tb_user_1_cfg_1_tb_user_1_ru_allocation_setf(uint8_t tbuser1ruallocation)
{
	ASSERT_ERR((((uint32_t)tbuser1ruallocation << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_1_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_1_CFG_1_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)tbuser1ruallocation <<0));
}

/**
 * @brief TB_USER_1_CFG_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    14:08 TB_USER1_TARGET_RSSI      0x0
 *    07:05 TB_USER1_RESERVED         0x0
 *    04    TB_USER1_DCM              0              
 *    03:00 TB_USER1_MCS              0x0
 * </pre>
 */
#define MPU_COMMON_TB_USER_1_CFG_2_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000114)
#define MPU_COMMON_TB_USER_1_CFG_2_OFFSET      0x00000114
#define MPU_COMMON_TB_USER_1_CFG_2_INDEX       0x00000045
#define MPU_COMMON_TB_USER_1_CFG_2_RESET       0x00000000

__INLINE uint32_t  mpu_common_tb_user_1_cfg_2_get(void)
{
	return REG_PL_RD(MPU_COMMON_TB_USER_1_CFG_2_ADDR);
}

__INLINE void mpu_common_tb_user_1_cfg_2_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_TB_USER_1_CFG_2_ADDR, value);
}

// field definitions
#define MPU_COMMON_TB_USER_1_CFG_2_TB_USER_1_TARGET_RSSI_MASK    ((uint32_t)0x00007F00)
#define MPU_COMMON_TB_USER_1_CFG_2_TB_USER_1_TARGET_RSSI_LSB    8
#define MPU_COMMON_TB_USER_1_CFG_2_TB_USER_1_TARGET_RSSI_WIDTH    ((uint32_t)0x00000007)
#define MPU_COMMON_TB_USER_1_CFG_2_TB_USER_1_RESERVED_MASK    ((uint32_t)0x000000E0)
#define MPU_COMMON_TB_USER_1_CFG_2_TB_USER_1_RESERVED_LSB    5
#define MPU_COMMON_TB_USER_1_CFG_2_TB_USER_1_RESERVED_WIDTH    ((uint32_t)0x00000003)
#define MPU_COMMON_TB_USER_1_CFG_2_TB_USER_1_DCM_BIT    ((uint32_t)0x00000010)
#define MPU_COMMON_TB_USER_1_CFG_2_TB_USER_1_DCM_POS    4
#define MPU_COMMON_TB_USER_1_CFG_2_TB_USER_1_MCS_MASK    ((uint32_t)0x0000000F)
#define MPU_COMMON_TB_USER_1_CFG_2_TB_USER_1_MCS_LSB    0
#define MPU_COMMON_TB_USER_1_CFG_2_TB_USER_1_MCS_WIDTH    ((uint32_t)0x00000004)

#define MPU_COMMON_TB_USER_1_CFG_2_TB_USER_1_TARGET_RSSI_RST    0x0
#define MPU_COMMON_TB_USER_1_CFG_2_TB_USER_1_RESERVED_RST    0x0
#define MPU_COMMON_TB_USER_1_CFG_2_TB_USER_1_DCM_RST    0x0
#define MPU_COMMON_TB_USER_1_CFG_2_TB_USER_1_MCS_RST    0x0

__INLINE void mpu_common_tb_user_1_cfg_2_pack(uint8_t tb_user1_target_rssi, uint8_t tb_user1_reserved, uint8_t tb_user1_dcm, uint8_t tb_user1_mcs)
{
	ASSERT_ERR((((uint32_t)tb_user1_target_rssi << 8) & ~((uint32_t)0x00007F00)) == 0);
	ASSERT_ERR((((uint32_t)tb_user1_reserved << 5) & ~((uint32_t)0x000000E0)) == 0);
	ASSERT_ERR((((uint32_t)tb_user1_dcm << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)tb_user1_mcs << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_1_CFG_2_ADDR,  ((uint32_t)tb_user1_target_rssi << 8) |((uint32_t)tb_user1_reserved << 5) |((uint32_t)tb_user1_dcm << 4) |((uint32_t)tb_user1_mcs << 0));
}

__INLINE void mpu_common_tb_user_1_cfg_2_unpack(uint8_t* tb_user1_target_rssi, uint8_t* tb_user1_reserved, uint8_t* tb_user1_dcm, uint8_t* tb_user1_mcs)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_1_CFG_2_ADDR);

	*tb_user1_target_rssi = (localVal & ((uint32_t)0x00007F00)) >>  8;
	*tb_user1_reserved = (localVal & ((uint32_t)0x000000E0)) >>  5;
	*tb_user1_dcm = (localVal & ((uint32_t)0x00000010)) >>  4;
	*tb_user1_mcs = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t mpu_common_tb_user_1_cfg_2_tb_user_1_target_rssi_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_1_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007F00)) >> 8);
}
__INLINE void mpu_common_tb_user_1_cfg_2_tb_user_1_target_rssi_setf(uint8_t tbuser1targetrssi)
{
	ASSERT_ERR((((uint32_t)tbuser1targetrssi << 8) & ~((uint32_t)0x00007F00)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_1_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_1_CFG_2_ADDR) & ~((uint32_t)0x00007F00)) | ((uint32_t)tbuser1targetrssi <<8));
}
__INLINE uint8_t mpu_common_tb_user_1_cfg_2_tb_user_1_reserved_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_1_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000E0)) >> 5);
}
__INLINE void mpu_common_tb_user_1_cfg_2_tb_user_1_reserved_setf(uint8_t tbuser1reserved)
{
	ASSERT_ERR((((uint32_t)tbuser1reserved << 5) & ~((uint32_t)0x000000E0)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_1_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_1_CFG_2_ADDR) & ~((uint32_t)0x000000E0)) | ((uint32_t)tbuser1reserved <<5));
}
__INLINE uint8_t mpu_common_tb_user_1_cfg_2_tb_user_1_dcm_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_1_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void mpu_common_tb_user_1_cfg_2_tb_user_1_dcm_setf(uint8_t tbuser1dcm)
{
	ASSERT_ERR((((uint32_t)tbuser1dcm << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_1_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_1_CFG_2_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)tbuser1dcm <<4));
}
__INLINE uint8_t mpu_common_tb_user_1_cfg_2_tb_user_1_mcs_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_1_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void mpu_common_tb_user_1_cfg_2_tb_user_1_mcs_setf(uint8_t tbuser1mcs)
{
	ASSERT_ERR((((uint32_t)tbuser1mcs << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_1_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_1_CFG_2_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)tbuser1mcs <<0));
}

/**
 * @brief TB_USER_2_CFG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26:24 TB_USER2_NSTS             0x0
 *    22:20 TB_USER2_STARTING_STS     0x0
 *    19    TB_USER2_CODING_TYPE      0              
 *    18:16 TB_USER2_RU_TYPE          0x0
 *    14    TB_USER2_RU_BAND_MAC      0              
 *    13:08 TB_USER2_RU_INDEX         0x0
 *    07:00 TB_USER2_RU_ALLOCATION    0x0
 * </pre>
 */
#define MPU_COMMON_TB_USER_2_CFG_1_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000118)
#define MPU_COMMON_TB_USER_2_CFG_1_OFFSET      0x00000118
#define MPU_COMMON_TB_USER_2_CFG_1_INDEX       0x00000046
#define MPU_COMMON_TB_USER_2_CFG_1_RESET       0x00000000

__INLINE uint32_t  mpu_common_tb_user_2_cfg_1_get(void)
{
	return REG_PL_RD(MPU_COMMON_TB_USER_2_CFG_1_ADDR);
}

__INLINE void mpu_common_tb_user_2_cfg_1_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_TB_USER_2_CFG_1_ADDR, value);
}

// field definitions
#define MPU_COMMON_TB_USER_2_CFG_1_TB_USER_2_NSTS_MASK    ((uint32_t)0x07000000)
#define MPU_COMMON_TB_USER_2_CFG_1_TB_USER_2_NSTS_LSB    24
#define MPU_COMMON_TB_USER_2_CFG_1_TB_USER_2_NSTS_WIDTH    ((uint32_t)0x00000003)
#define MPU_COMMON_TB_USER_2_CFG_1_TB_USER_2_STARTING_STS_MASK    ((uint32_t)0x00700000)
#define MPU_COMMON_TB_USER_2_CFG_1_TB_USER_2_STARTING_STS_LSB    20
#define MPU_COMMON_TB_USER_2_CFG_1_TB_USER_2_STARTING_STS_WIDTH    ((uint32_t)0x00000003)
#define MPU_COMMON_TB_USER_2_CFG_1_TB_USER_2_CODING_TYPE_BIT    ((uint32_t)0x00080000)
#define MPU_COMMON_TB_USER_2_CFG_1_TB_USER_2_CODING_TYPE_POS    19
#define MPU_COMMON_TB_USER_2_CFG_1_TB_USER_2_RU_TYPE_MASK    ((uint32_t)0x00070000)
#define MPU_COMMON_TB_USER_2_CFG_1_TB_USER_2_RU_TYPE_LSB    16
#define MPU_COMMON_TB_USER_2_CFG_1_TB_USER_2_RU_TYPE_WIDTH    ((uint32_t)0x00000003)
#define MPU_COMMON_TB_USER_2_CFG_1_TB_USER_2_RU_BAND_MAC_BIT    ((uint32_t)0x00004000)
#define MPU_COMMON_TB_USER_2_CFG_1_TB_USER_2_RU_BAND_MAC_POS    14
#define MPU_COMMON_TB_USER_2_CFG_1_TB_USER_2_RU_INDEX_MASK    ((uint32_t)0x00003F00)
#define MPU_COMMON_TB_USER_2_CFG_1_TB_USER_2_RU_INDEX_LSB    8
#define MPU_COMMON_TB_USER_2_CFG_1_TB_USER_2_RU_INDEX_WIDTH    ((uint32_t)0x00000006)
#define MPU_COMMON_TB_USER_2_CFG_1_TB_USER_2_RU_ALLOCATION_MASK    ((uint32_t)0x000000FF)
#define MPU_COMMON_TB_USER_2_CFG_1_TB_USER_2_RU_ALLOCATION_LSB    0
#define MPU_COMMON_TB_USER_2_CFG_1_TB_USER_2_RU_ALLOCATION_WIDTH    ((uint32_t)0x00000008)

#define MPU_COMMON_TB_USER_2_CFG_1_TB_USER_2_NSTS_RST    0x0
#define MPU_COMMON_TB_USER_2_CFG_1_TB_USER_2_STARTING_STS_RST    0x0
#define MPU_COMMON_TB_USER_2_CFG_1_TB_USER_2_CODING_TYPE_RST    0x0
#define MPU_COMMON_TB_USER_2_CFG_1_TB_USER_2_RU_TYPE_RST    0x0
#define MPU_COMMON_TB_USER_2_CFG_1_TB_USER_2_RU_BAND_MAC_RST    0x0
#define MPU_COMMON_TB_USER_2_CFG_1_TB_USER_2_RU_INDEX_RST    0x0
#define MPU_COMMON_TB_USER_2_CFG_1_TB_USER_2_RU_ALLOCATION_RST    0x0

__INLINE void mpu_common_tb_user_2_cfg_1_pack(uint8_t tb_user2_nsts, uint8_t tb_user2_starting_sts, uint8_t tb_user2_coding_type, uint8_t tb_user2_ru_type, uint8_t tb_user2_ru_band_mac, uint8_t tb_user2_ru_index, uint8_t tb_user2_ru_allocation)
{
	ASSERT_ERR((((uint32_t)tb_user2_nsts << 24) & ~((uint32_t)0x07000000)) == 0);
	ASSERT_ERR((((uint32_t)tb_user2_starting_sts << 20) & ~((uint32_t)0x00700000)) == 0);
	ASSERT_ERR((((uint32_t)tb_user2_coding_type << 19) & ~((uint32_t)0x00080000)) == 0);
	ASSERT_ERR((((uint32_t)tb_user2_ru_type << 16) & ~((uint32_t)0x00070000)) == 0);
	ASSERT_ERR((((uint32_t)tb_user2_ru_band_mac << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)tb_user2_ru_index << 8) & ~((uint32_t)0x00003F00)) == 0);
	ASSERT_ERR((((uint32_t)tb_user2_ru_allocation << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_2_CFG_1_ADDR,  ((uint32_t)tb_user2_nsts << 24) |((uint32_t)tb_user2_starting_sts << 20) |((uint32_t)tb_user2_coding_type << 19) |((uint32_t)tb_user2_ru_type << 16) |((uint32_t)tb_user2_ru_band_mac << 14) |((uint32_t)tb_user2_ru_index << 8) |((uint32_t)tb_user2_ru_allocation << 0));
}

__INLINE void mpu_common_tb_user_2_cfg_1_unpack(uint8_t* tb_user2_nsts, uint8_t* tb_user2_starting_sts, uint8_t* tb_user2_coding_type, uint8_t* tb_user2_ru_type, uint8_t* tb_user2_ru_band_mac, uint8_t* tb_user2_ru_index, uint8_t* tb_user2_ru_allocation)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_2_CFG_1_ADDR);

	*tb_user2_nsts = (localVal & ((uint32_t)0x07000000)) >>  24;
	*tb_user2_starting_sts = (localVal & ((uint32_t)0x00700000)) >>  20;
	*tb_user2_coding_type = (localVal & ((uint32_t)0x00080000)) >>  19;
	*tb_user2_ru_type = (localVal & ((uint32_t)0x00070000)) >>  16;
	*tb_user2_ru_band_mac = (localVal & ((uint32_t)0x00004000)) >>  14;
	*tb_user2_ru_index = (localVal & ((uint32_t)0x00003F00)) >>  8;
	*tb_user2_ru_allocation = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t mpu_common_tb_user_2_cfg_1_tb_user_2_nsts_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_2_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE void mpu_common_tb_user_2_cfg_1_tb_user_2_nsts_setf(uint8_t tbuser2nsts)
{
	ASSERT_ERR((((uint32_t)tbuser2nsts << 24) & ~((uint32_t)0x07000000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_2_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_2_CFG_1_ADDR) & ~((uint32_t)0x07000000)) | ((uint32_t)tbuser2nsts <<24));
}
__INLINE uint8_t mpu_common_tb_user_2_cfg_1_tb_user_2_starting_sts_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_2_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00700000)) >> 20);
}
__INLINE void mpu_common_tb_user_2_cfg_1_tb_user_2_starting_sts_setf(uint8_t tbuser2startingsts)
{
	ASSERT_ERR((((uint32_t)tbuser2startingsts << 20) & ~((uint32_t)0x00700000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_2_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_2_CFG_1_ADDR) & ~((uint32_t)0x00700000)) | ((uint32_t)tbuser2startingsts <<20));
}
__INLINE uint8_t mpu_common_tb_user_2_cfg_1_tb_user_2_coding_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_2_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00080000)) >> 19);
}
__INLINE void mpu_common_tb_user_2_cfg_1_tb_user_2_coding_type_setf(uint8_t tbuser2codingtype)
{
	ASSERT_ERR((((uint32_t)tbuser2codingtype << 19) & ~((uint32_t)0x00080000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_2_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_2_CFG_1_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)tbuser2codingtype <<19));
}
__INLINE uint8_t mpu_common_tb_user_2_cfg_1_tb_user_2_ru_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_2_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00070000)) >> 16);
}
__INLINE void mpu_common_tb_user_2_cfg_1_tb_user_2_ru_type_setf(uint8_t tbuser2rutype)
{
	ASSERT_ERR((((uint32_t)tbuser2rutype << 16) & ~((uint32_t)0x00070000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_2_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_2_CFG_1_ADDR) & ~((uint32_t)0x00070000)) | ((uint32_t)tbuser2rutype <<16));
}
__INLINE uint8_t mpu_common_tb_user_2_cfg_1_tb_user_2_ru_band_mac_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_2_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void mpu_common_tb_user_2_cfg_1_tb_user_2_ru_band_mac_setf(uint8_t tbuser2rubandmac)
{
	ASSERT_ERR((((uint32_t)tbuser2rubandmac << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_2_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_2_CFG_1_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)tbuser2rubandmac <<14));
}
__INLINE uint8_t mpu_common_tb_user_2_cfg_1_tb_user_2_ru_index_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_2_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00003F00)) >> 8);
}
__INLINE void mpu_common_tb_user_2_cfg_1_tb_user_2_ru_index_setf(uint8_t tbuser2ruindex)
{
	ASSERT_ERR((((uint32_t)tbuser2ruindex << 8) & ~((uint32_t)0x00003F00)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_2_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_2_CFG_1_ADDR) & ~((uint32_t)0x00003F00)) | ((uint32_t)tbuser2ruindex <<8));
}
__INLINE uint8_t mpu_common_tb_user_2_cfg_1_tb_user_2_ru_allocation_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_2_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void mpu_common_tb_user_2_cfg_1_tb_user_2_ru_allocation_setf(uint8_t tbuser2ruallocation)
{
	ASSERT_ERR((((uint32_t)tbuser2ruallocation << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_2_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_2_CFG_1_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)tbuser2ruallocation <<0));
}

/**
 * @brief TB_USER_2_CFG_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    14:08 TB_USER2_TARGET_RSSI      0x0
 *    07:05 TB_USER2_RESERVED         0x0
 *    04    TB_USER2_DCM              0              
 *    03:00 TB_USER2_MCS              0x0
 * </pre>
 */
#define MPU_COMMON_TB_USER_2_CFG_2_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x0000011C)
#define MPU_COMMON_TB_USER_2_CFG_2_OFFSET      0x0000011C
#define MPU_COMMON_TB_USER_2_CFG_2_INDEX       0x00000047
#define MPU_COMMON_TB_USER_2_CFG_2_RESET       0x00000000

__INLINE uint32_t  mpu_common_tb_user_2_cfg_2_get(void)
{
	return REG_PL_RD(MPU_COMMON_TB_USER_2_CFG_2_ADDR);
}

__INLINE void mpu_common_tb_user_2_cfg_2_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_TB_USER_2_CFG_2_ADDR, value);
}

// field definitions
#define MPU_COMMON_TB_USER_2_CFG_2_TB_USER_2_TARGET_RSSI_MASK    ((uint32_t)0x00007F00)
#define MPU_COMMON_TB_USER_2_CFG_2_TB_USER_2_TARGET_RSSI_LSB    8
#define MPU_COMMON_TB_USER_2_CFG_2_TB_USER_2_TARGET_RSSI_WIDTH    ((uint32_t)0x00000007)
#define MPU_COMMON_TB_USER_2_CFG_2_TB_USER_2_RESERVED_MASK    ((uint32_t)0x000000E0)
#define MPU_COMMON_TB_USER_2_CFG_2_TB_USER_2_RESERVED_LSB    5
#define MPU_COMMON_TB_USER_2_CFG_2_TB_USER_2_RESERVED_WIDTH    ((uint32_t)0x00000003)
#define MPU_COMMON_TB_USER_2_CFG_2_TB_USER_2_DCM_BIT    ((uint32_t)0x00000010)
#define MPU_COMMON_TB_USER_2_CFG_2_TB_USER_2_DCM_POS    4
#define MPU_COMMON_TB_USER_2_CFG_2_TB_USER_2_MCS_MASK    ((uint32_t)0x0000000F)
#define MPU_COMMON_TB_USER_2_CFG_2_TB_USER_2_MCS_LSB    0
#define MPU_COMMON_TB_USER_2_CFG_2_TB_USER_2_MCS_WIDTH    ((uint32_t)0x00000004)

#define MPU_COMMON_TB_USER_2_CFG_2_TB_USER_2_TARGET_RSSI_RST    0x0
#define MPU_COMMON_TB_USER_2_CFG_2_TB_USER_2_RESERVED_RST    0x0
#define MPU_COMMON_TB_USER_2_CFG_2_TB_USER_2_DCM_RST    0x0
#define MPU_COMMON_TB_USER_2_CFG_2_TB_USER_2_MCS_RST    0x0

__INLINE void mpu_common_tb_user_2_cfg_2_pack(uint8_t tb_user2_target_rssi, uint8_t tb_user2_reserved, uint8_t tb_user2_dcm, uint8_t tb_user2_mcs)
{
	ASSERT_ERR((((uint32_t)tb_user2_target_rssi << 8) & ~((uint32_t)0x00007F00)) == 0);
	ASSERT_ERR((((uint32_t)tb_user2_reserved << 5) & ~((uint32_t)0x000000E0)) == 0);
	ASSERT_ERR((((uint32_t)tb_user2_dcm << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)tb_user2_mcs << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_2_CFG_2_ADDR,  ((uint32_t)tb_user2_target_rssi << 8) |((uint32_t)tb_user2_reserved << 5) |((uint32_t)tb_user2_dcm << 4) |((uint32_t)tb_user2_mcs << 0));
}

__INLINE void mpu_common_tb_user_2_cfg_2_unpack(uint8_t* tb_user2_target_rssi, uint8_t* tb_user2_reserved, uint8_t* tb_user2_dcm, uint8_t* tb_user2_mcs)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_2_CFG_2_ADDR);

	*tb_user2_target_rssi = (localVal & ((uint32_t)0x00007F00)) >>  8;
	*tb_user2_reserved = (localVal & ((uint32_t)0x000000E0)) >>  5;
	*tb_user2_dcm = (localVal & ((uint32_t)0x00000010)) >>  4;
	*tb_user2_mcs = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t mpu_common_tb_user_2_cfg_2_tb_user_2_target_rssi_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_2_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007F00)) >> 8);
}
__INLINE void mpu_common_tb_user_2_cfg_2_tb_user_2_target_rssi_setf(uint8_t tbuser2targetrssi)
{
	ASSERT_ERR((((uint32_t)tbuser2targetrssi << 8) & ~((uint32_t)0x00007F00)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_2_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_2_CFG_2_ADDR) & ~((uint32_t)0x00007F00)) | ((uint32_t)tbuser2targetrssi <<8));
}
__INLINE uint8_t mpu_common_tb_user_2_cfg_2_tb_user_2_reserved_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_2_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000E0)) >> 5);
}
__INLINE void mpu_common_tb_user_2_cfg_2_tb_user_2_reserved_setf(uint8_t tbuser2reserved)
{
	ASSERT_ERR((((uint32_t)tbuser2reserved << 5) & ~((uint32_t)0x000000E0)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_2_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_2_CFG_2_ADDR) & ~((uint32_t)0x000000E0)) | ((uint32_t)tbuser2reserved <<5));
}
__INLINE uint8_t mpu_common_tb_user_2_cfg_2_tb_user_2_dcm_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_2_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void mpu_common_tb_user_2_cfg_2_tb_user_2_dcm_setf(uint8_t tbuser2dcm)
{
	ASSERT_ERR((((uint32_t)tbuser2dcm << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_2_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_2_CFG_2_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)tbuser2dcm <<4));
}
__INLINE uint8_t mpu_common_tb_user_2_cfg_2_tb_user_2_mcs_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_2_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void mpu_common_tb_user_2_cfg_2_tb_user_2_mcs_setf(uint8_t tbuser2mcs)
{
	ASSERT_ERR((((uint32_t)tbuser2mcs << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_2_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_2_CFG_2_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)tbuser2mcs <<0));
}

/**
 * @brief TB_USER_3_CFG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26:24 TB_USER3_NSTS             0x0
 *    22:20 TB_USER3_STARTING_STS     0x0
 *    19    TB_USER3_CODING_TYPE      0              
 *    18:16 TB_USER3_RU_TYPE          0x0
 *    14    TB_USER3_RU_BAND_MAC      0              
 *    13:08 TB_USER3_RU_INDEX         0x0
 *    07:00 TB_USER3_RU_ALLOCATION    0x0
 * </pre>
 */
#define MPU_COMMON_TB_USER_3_CFG_1_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000120)
#define MPU_COMMON_TB_USER_3_CFG_1_OFFSET      0x00000120
#define MPU_COMMON_TB_USER_3_CFG_1_INDEX       0x00000048
#define MPU_COMMON_TB_USER_3_CFG_1_RESET       0x00000000

__INLINE uint32_t  mpu_common_tb_user_3_cfg_1_get(void)
{
	return REG_PL_RD(MPU_COMMON_TB_USER_3_CFG_1_ADDR);
}

__INLINE void mpu_common_tb_user_3_cfg_1_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_TB_USER_3_CFG_1_ADDR, value);
}

// field definitions
#define MPU_COMMON_TB_USER_3_CFG_1_TB_USER_3_NSTS_MASK    ((uint32_t)0x07000000)
#define MPU_COMMON_TB_USER_3_CFG_1_TB_USER_3_NSTS_LSB    24
#define MPU_COMMON_TB_USER_3_CFG_1_TB_USER_3_NSTS_WIDTH    ((uint32_t)0x00000003)
#define MPU_COMMON_TB_USER_3_CFG_1_TB_USER_3_STARTING_STS_MASK    ((uint32_t)0x00700000)
#define MPU_COMMON_TB_USER_3_CFG_1_TB_USER_3_STARTING_STS_LSB    20
#define MPU_COMMON_TB_USER_3_CFG_1_TB_USER_3_STARTING_STS_WIDTH    ((uint32_t)0x00000003)
#define MPU_COMMON_TB_USER_3_CFG_1_TB_USER_3_CODING_TYPE_BIT    ((uint32_t)0x00080000)
#define MPU_COMMON_TB_USER_3_CFG_1_TB_USER_3_CODING_TYPE_POS    19
#define MPU_COMMON_TB_USER_3_CFG_1_TB_USER_3_RU_TYPE_MASK    ((uint32_t)0x00070000)
#define MPU_COMMON_TB_USER_3_CFG_1_TB_USER_3_RU_TYPE_LSB    16
#define MPU_COMMON_TB_USER_3_CFG_1_TB_USER_3_RU_TYPE_WIDTH    ((uint32_t)0x00000003)
#define MPU_COMMON_TB_USER_3_CFG_1_TB_USER_3_RU_BAND_MAC_BIT    ((uint32_t)0x00004000)
#define MPU_COMMON_TB_USER_3_CFG_1_TB_USER_3_RU_BAND_MAC_POS    14
#define MPU_COMMON_TB_USER_3_CFG_1_TB_USER_3_RU_INDEX_MASK    ((uint32_t)0x00003F00)
#define MPU_COMMON_TB_USER_3_CFG_1_TB_USER_3_RU_INDEX_LSB    8
#define MPU_COMMON_TB_USER_3_CFG_1_TB_USER_3_RU_INDEX_WIDTH    ((uint32_t)0x00000006)
#define MPU_COMMON_TB_USER_3_CFG_1_TB_USER_3_RU_ALLOCATION_MASK    ((uint32_t)0x000000FF)
#define MPU_COMMON_TB_USER_3_CFG_1_TB_USER_3_RU_ALLOCATION_LSB    0
#define MPU_COMMON_TB_USER_3_CFG_1_TB_USER_3_RU_ALLOCATION_WIDTH    ((uint32_t)0x00000008)

#define MPU_COMMON_TB_USER_3_CFG_1_TB_USER_3_NSTS_RST    0x0
#define MPU_COMMON_TB_USER_3_CFG_1_TB_USER_3_STARTING_STS_RST    0x0
#define MPU_COMMON_TB_USER_3_CFG_1_TB_USER_3_CODING_TYPE_RST    0x0
#define MPU_COMMON_TB_USER_3_CFG_1_TB_USER_3_RU_TYPE_RST    0x0
#define MPU_COMMON_TB_USER_3_CFG_1_TB_USER_3_RU_BAND_MAC_RST    0x0
#define MPU_COMMON_TB_USER_3_CFG_1_TB_USER_3_RU_INDEX_RST    0x0
#define MPU_COMMON_TB_USER_3_CFG_1_TB_USER_3_RU_ALLOCATION_RST    0x0

__INLINE void mpu_common_tb_user_3_cfg_1_pack(uint8_t tb_user3_nsts, uint8_t tb_user3_starting_sts, uint8_t tb_user3_coding_type, uint8_t tb_user3_ru_type, uint8_t tb_user3_ru_band_mac, uint8_t tb_user3_ru_index, uint8_t tb_user3_ru_allocation)
{
	ASSERT_ERR((((uint32_t)tb_user3_nsts << 24) & ~((uint32_t)0x07000000)) == 0);
	ASSERT_ERR((((uint32_t)tb_user3_starting_sts << 20) & ~((uint32_t)0x00700000)) == 0);
	ASSERT_ERR((((uint32_t)tb_user3_coding_type << 19) & ~((uint32_t)0x00080000)) == 0);
	ASSERT_ERR((((uint32_t)tb_user3_ru_type << 16) & ~((uint32_t)0x00070000)) == 0);
	ASSERT_ERR((((uint32_t)tb_user3_ru_band_mac << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)tb_user3_ru_index << 8) & ~((uint32_t)0x00003F00)) == 0);
	ASSERT_ERR((((uint32_t)tb_user3_ru_allocation << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_3_CFG_1_ADDR,  ((uint32_t)tb_user3_nsts << 24) |((uint32_t)tb_user3_starting_sts << 20) |((uint32_t)tb_user3_coding_type << 19) |((uint32_t)tb_user3_ru_type << 16) |((uint32_t)tb_user3_ru_band_mac << 14) |((uint32_t)tb_user3_ru_index << 8) |((uint32_t)tb_user3_ru_allocation << 0));
}

__INLINE void mpu_common_tb_user_3_cfg_1_unpack(uint8_t* tb_user3_nsts, uint8_t* tb_user3_starting_sts, uint8_t* tb_user3_coding_type, uint8_t* tb_user3_ru_type, uint8_t* tb_user3_ru_band_mac, uint8_t* tb_user3_ru_index, uint8_t* tb_user3_ru_allocation)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_3_CFG_1_ADDR);

	*tb_user3_nsts = (localVal & ((uint32_t)0x07000000)) >>  24;
	*tb_user3_starting_sts = (localVal & ((uint32_t)0x00700000)) >>  20;
	*tb_user3_coding_type = (localVal & ((uint32_t)0x00080000)) >>  19;
	*tb_user3_ru_type = (localVal & ((uint32_t)0x00070000)) >>  16;
	*tb_user3_ru_band_mac = (localVal & ((uint32_t)0x00004000)) >>  14;
	*tb_user3_ru_index = (localVal & ((uint32_t)0x00003F00)) >>  8;
	*tb_user3_ru_allocation = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t mpu_common_tb_user_3_cfg_1_tb_user_3_nsts_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_3_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE void mpu_common_tb_user_3_cfg_1_tb_user_3_nsts_setf(uint8_t tbuser3nsts)
{
	ASSERT_ERR((((uint32_t)tbuser3nsts << 24) & ~((uint32_t)0x07000000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_3_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_3_CFG_1_ADDR) & ~((uint32_t)0x07000000)) | ((uint32_t)tbuser3nsts <<24));
}
__INLINE uint8_t mpu_common_tb_user_3_cfg_1_tb_user_3_starting_sts_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_3_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00700000)) >> 20);
}
__INLINE void mpu_common_tb_user_3_cfg_1_tb_user_3_starting_sts_setf(uint8_t tbuser3startingsts)
{
	ASSERT_ERR((((uint32_t)tbuser3startingsts << 20) & ~((uint32_t)0x00700000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_3_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_3_CFG_1_ADDR) & ~((uint32_t)0x00700000)) | ((uint32_t)tbuser3startingsts <<20));
}
__INLINE uint8_t mpu_common_tb_user_3_cfg_1_tb_user_3_coding_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_3_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00080000)) >> 19);
}
__INLINE void mpu_common_tb_user_3_cfg_1_tb_user_3_coding_type_setf(uint8_t tbuser3codingtype)
{
	ASSERT_ERR((((uint32_t)tbuser3codingtype << 19) & ~((uint32_t)0x00080000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_3_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_3_CFG_1_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)tbuser3codingtype <<19));
}
__INLINE uint8_t mpu_common_tb_user_3_cfg_1_tb_user_3_ru_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_3_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00070000)) >> 16);
}
__INLINE void mpu_common_tb_user_3_cfg_1_tb_user_3_ru_type_setf(uint8_t tbuser3rutype)
{
	ASSERT_ERR((((uint32_t)tbuser3rutype << 16) & ~((uint32_t)0x00070000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_3_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_3_CFG_1_ADDR) & ~((uint32_t)0x00070000)) | ((uint32_t)tbuser3rutype <<16));
}
__INLINE uint8_t mpu_common_tb_user_3_cfg_1_tb_user_3_ru_band_mac_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_3_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void mpu_common_tb_user_3_cfg_1_tb_user_3_ru_band_mac_setf(uint8_t tbuser3rubandmac)
{
	ASSERT_ERR((((uint32_t)tbuser3rubandmac << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_3_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_3_CFG_1_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)tbuser3rubandmac <<14));
}
__INLINE uint8_t mpu_common_tb_user_3_cfg_1_tb_user_3_ru_index_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_3_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00003F00)) >> 8);
}
__INLINE void mpu_common_tb_user_3_cfg_1_tb_user_3_ru_index_setf(uint8_t tbuser3ruindex)
{
	ASSERT_ERR((((uint32_t)tbuser3ruindex << 8) & ~((uint32_t)0x00003F00)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_3_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_3_CFG_1_ADDR) & ~((uint32_t)0x00003F00)) | ((uint32_t)tbuser3ruindex <<8));
}
__INLINE uint8_t mpu_common_tb_user_3_cfg_1_tb_user_3_ru_allocation_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_3_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void mpu_common_tb_user_3_cfg_1_tb_user_3_ru_allocation_setf(uint8_t tbuser3ruallocation)
{
	ASSERT_ERR((((uint32_t)tbuser3ruallocation << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_3_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_3_CFG_1_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)tbuser3ruallocation <<0));
}

/**
 * @brief TB_USER_3_CFG_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    14:08 TB_USER3_TARGET_RSSI      0x0
 *    07:05 TB_USER3_RESERVED         0x0
 *    04    TB_USER3_DCM              0              
 *    03:00 TB_USER3_MCS              0x0
 * </pre>
 */
#define MPU_COMMON_TB_USER_3_CFG_2_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000124)
#define MPU_COMMON_TB_USER_3_CFG_2_OFFSET      0x00000124
#define MPU_COMMON_TB_USER_3_CFG_2_INDEX       0x00000049
#define MPU_COMMON_TB_USER_3_CFG_2_RESET       0x00000000

__INLINE uint32_t  mpu_common_tb_user_3_cfg_2_get(void)
{
	return REG_PL_RD(MPU_COMMON_TB_USER_3_CFG_2_ADDR);
}

__INLINE void mpu_common_tb_user_3_cfg_2_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_TB_USER_3_CFG_2_ADDR, value);
}

// field definitions
#define MPU_COMMON_TB_USER_3_CFG_2_TB_USER_3_TARGET_RSSI_MASK    ((uint32_t)0x00007F00)
#define MPU_COMMON_TB_USER_3_CFG_2_TB_USER_3_TARGET_RSSI_LSB    8
#define MPU_COMMON_TB_USER_3_CFG_2_TB_USER_3_TARGET_RSSI_WIDTH    ((uint32_t)0x00000007)
#define MPU_COMMON_TB_USER_3_CFG_2_TB_USER_3_RESERVED_MASK    ((uint32_t)0x000000E0)
#define MPU_COMMON_TB_USER_3_CFG_2_TB_USER_3_RESERVED_LSB    5
#define MPU_COMMON_TB_USER_3_CFG_2_TB_USER_3_RESERVED_WIDTH    ((uint32_t)0x00000003)
#define MPU_COMMON_TB_USER_3_CFG_2_TB_USER_3_DCM_BIT    ((uint32_t)0x00000010)
#define MPU_COMMON_TB_USER_3_CFG_2_TB_USER_3_DCM_POS    4
#define MPU_COMMON_TB_USER_3_CFG_2_TB_USER_3_MCS_MASK    ((uint32_t)0x0000000F)
#define MPU_COMMON_TB_USER_3_CFG_2_TB_USER_3_MCS_LSB    0
#define MPU_COMMON_TB_USER_3_CFG_2_TB_USER_3_MCS_WIDTH    ((uint32_t)0x00000004)

#define MPU_COMMON_TB_USER_3_CFG_2_TB_USER_3_TARGET_RSSI_RST    0x0
#define MPU_COMMON_TB_USER_3_CFG_2_TB_USER_3_RESERVED_RST    0x0
#define MPU_COMMON_TB_USER_3_CFG_2_TB_USER_3_DCM_RST    0x0
#define MPU_COMMON_TB_USER_3_CFG_2_TB_USER_3_MCS_RST    0x0

__INLINE void mpu_common_tb_user_3_cfg_2_pack(uint8_t tb_user3_target_rssi, uint8_t tb_user3_reserved, uint8_t tb_user3_dcm, uint8_t tb_user3_mcs)
{
	ASSERT_ERR((((uint32_t)tb_user3_target_rssi << 8) & ~((uint32_t)0x00007F00)) == 0);
	ASSERT_ERR((((uint32_t)tb_user3_reserved << 5) & ~((uint32_t)0x000000E0)) == 0);
	ASSERT_ERR((((uint32_t)tb_user3_dcm << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)tb_user3_mcs << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_3_CFG_2_ADDR,  ((uint32_t)tb_user3_target_rssi << 8) |((uint32_t)tb_user3_reserved << 5) |((uint32_t)tb_user3_dcm << 4) |((uint32_t)tb_user3_mcs << 0));
}

__INLINE void mpu_common_tb_user_3_cfg_2_unpack(uint8_t* tb_user3_target_rssi, uint8_t* tb_user3_reserved, uint8_t* tb_user3_dcm, uint8_t* tb_user3_mcs)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_3_CFG_2_ADDR);

	*tb_user3_target_rssi = (localVal & ((uint32_t)0x00007F00)) >>  8;
	*tb_user3_reserved = (localVal & ((uint32_t)0x000000E0)) >>  5;
	*tb_user3_dcm = (localVal & ((uint32_t)0x00000010)) >>  4;
	*tb_user3_mcs = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t mpu_common_tb_user_3_cfg_2_tb_user_3_target_rssi_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_3_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007F00)) >> 8);
}
__INLINE void mpu_common_tb_user_3_cfg_2_tb_user_3_target_rssi_setf(uint8_t tbuser3targetrssi)
{
	ASSERT_ERR((((uint32_t)tbuser3targetrssi << 8) & ~((uint32_t)0x00007F00)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_3_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_3_CFG_2_ADDR) & ~((uint32_t)0x00007F00)) | ((uint32_t)tbuser3targetrssi <<8));
}
__INLINE uint8_t mpu_common_tb_user_3_cfg_2_tb_user_3_reserved_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_3_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000E0)) >> 5);
}
__INLINE void mpu_common_tb_user_3_cfg_2_tb_user_3_reserved_setf(uint8_t tbuser3reserved)
{
	ASSERT_ERR((((uint32_t)tbuser3reserved << 5) & ~((uint32_t)0x000000E0)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_3_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_3_CFG_2_ADDR) & ~((uint32_t)0x000000E0)) | ((uint32_t)tbuser3reserved <<5));
}
__INLINE uint8_t mpu_common_tb_user_3_cfg_2_tb_user_3_dcm_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_3_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void mpu_common_tb_user_3_cfg_2_tb_user_3_dcm_setf(uint8_t tbuser3dcm)
{
	ASSERT_ERR((((uint32_t)tbuser3dcm << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_3_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_3_CFG_2_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)tbuser3dcm <<4));
}
__INLINE uint8_t mpu_common_tb_user_3_cfg_2_tb_user_3_mcs_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_3_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void mpu_common_tb_user_3_cfg_2_tb_user_3_mcs_setf(uint8_t tbuser3mcs)
{
	ASSERT_ERR((((uint32_t)tbuser3mcs << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_3_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_3_CFG_2_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)tbuser3mcs <<0));
}

/**
 * @brief TB_USER_4_CFG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26:24 TB_USER4_NSTS             0x0
 *    22:20 TB_USER4_STARTING_STS     0x0
 *    19    TB_USER4_CODING_TYPE      0              
 *    18:16 TB_USER4_RU_TYPE          0x0
 *    14    TB_USER4_RU_BAND_MAC      0              
 *    13:08 TB_USER4_RU_INDEX         0x0
 *    07:00 TB_USER4_RU_ALLOCATION    0x0
 * </pre>
 */
#define MPU_COMMON_TB_USER_4_CFG_1_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000128)
#define MPU_COMMON_TB_USER_4_CFG_1_OFFSET      0x00000128
#define MPU_COMMON_TB_USER_4_CFG_1_INDEX       0x0000004A
#define MPU_COMMON_TB_USER_4_CFG_1_RESET       0x00000000

__INLINE uint32_t  mpu_common_tb_user_4_cfg_1_get(void)
{
	return REG_PL_RD(MPU_COMMON_TB_USER_4_CFG_1_ADDR);
}

__INLINE void mpu_common_tb_user_4_cfg_1_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_TB_USER_4_CFG_1_ADDR, value);
}

// field definitions
#define MPU_COMMON_TB_USER_4_CFG_1_TB_USER_4_NSTS_MASK    ((uint32_t)0x07000000)
#define MPU_COMMON_TB_USER_4_CFG_1_TB_USER_4_NSTS_LSB    24
#define MPU_COMMON_TB_USER_4_CFG_1_TB_USER_4_NSTS_WIDTH    ((uint32_t)0x00000003)
#define MPU_COMMON_TB_USER_4_CFG_1_TB_USER_4_STARTING_STS_MASK    ((uint32_t)0x00700000)
#define MPU_COMMON_TB_USER_4_CFG_1_TB_USER_4_STARTING_STS_LSB    20
#define MPU_COMMON_TB_USER_4_CFG_1_TB_USER_4_STARTING_STS_WIDTH    ((uint32_t)0x00000003)
#define MPU_COMMON_TB_USER_4_CFG_1_TB_USER_4_CODING_TYPE_BIT    ((uint32_t)0x00080000)
#define MPU_COMMON_TB_USER_4_CFG_1_TB_USER_4_CODING_TYPE_POS    19
#define MPU_COMMON_TB_USER_4_CFG_1_TB_USER_4_RU_TYPE_MASK    ((uint32_t)0x00070000)
#define MPU_COMMON_TB_USER_4_CFG_1_TB_USER_4_RU_TYPE_LSB    16
#define MPU_COMMON_TB_USER_4_CFG_1_TB_USER_4_RU_TYPE_WIDTH    ((uint32_t)0x00000003)
#define MPU_COMMON_TB_USER_4_CFG_1_TB_USER_4_RU_BAND_MAC_BIT    ((uint32_t)0x00004000)
#define MPU_COMMON_TB_USER_4_CFG_1_TB_USER_4_RU_BAND_MAC_POS    14
#define MPU_COMMON_TB_USER_4_CFG_1_TB_USER_4_RU_INDEX_MASK    ((uint32_t)0x00003F00)
#define MPU_COMMON_TB_USER_4_CFG_1_TB_USER_4_RU_INDEX_LSB    8
#define MPU_COMMON_TB_USER_4_CFG_1_TB_USER_4_RU_INDEX_WIDTH    ((uint32_t)0x00000006)
#define MPU_COMMON_TB_USER_4_CFG_1_TB_USER_4_RU_ALLOCATION_MASK    ((uint32_t)0x000000FF)
#define MPU_COMMON_TB_USER_4_CFG_1_TB_USER_4_RU_ALLOCATION_LSB    0
#define MPU_COMMON_TB_USER_4_CFG_1_TB_USER_4_RU_ALLOCATION_WIDTH    ((uint32_t)0x00000008)

#define MPU_COMMON_TB_USER_4_CFG_1_TB_USER_4_NSTS_RST    0x0
#define MPU_COMMON_TB_USER_4_CFG_1_TB_USER_4_STARTING_STS_RST    0x0
#define MPU_COMMON_TB_USER_4_CFG_1_TB_USER_4_CODING_TYPE_RST    0x0
#define MPU_COMMON_TB_USER_4_CFG_1_TB_USER_4_RU_TYPE_RST    0x0
#define MPU_COMMON_TB_USER_4_CFG_1_TB_USER_4_RU_BAND_MAC_RST    0x0
#define MPU_COMMON_TB_USER_4_CFG_1_TB_USER_4_RU_INDEX_RST    0x0
#define MPU_COMMON_TB_USER_4_CFG_1_TB_USER_4_RU_ALLOCATION_RST    0x0

__INLINE void mpu_common_tb_user_4_cfg_1_pack(uint8_t tb_user4_nsts, uint8_t tb_user4_starting_sts, uint8_t tb_user4_coding_type, uint8_t tb_user4_ru_type, uint8_t tb_user4_ru_band_mac, uint8_t tb_user4_ru_index, uint8_t tb_user4_ru_allocation)
{
	ASSERT_ERR((((uint32_t)tb_user4_nsts << 24) & ~((uint32_t)0x07000000)) == 0);
	ASSERT_ERR((((uint32_t)tb_user4_starting_sts << 20) & ~((uint32_t)0x00700000)) == 0);
	ASSERT_ERR((((uint32_t)tb_user4_coding_type << 19) & ~((uint32_t)0x00080000)) == 0);
	ASSERT_ERR((((uint32_t)tb_user4_ru_type << 16) & ~((uint32_t)0x00070000)) == 0);
	ASSERT_ERR((((uint32_t)tb_user4_ru_band_mac << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)tb_user4_ru_index << 8) & ~((uint32_t)0x00003F00)) == 0);
	ASSERT_ERR((((uint32_t)tb_user4_ru_allocation << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_4_CFG_1_ADDR,  ((uint32_t)tb_user4_nsts << 24) |((uint32_t)tb_user4_starting_sts << 20) |((uint32_t)tb_user4_coding_type << 19) |((uint32_t)tb_user4_ru_type << 16) |((uint32_t)tb_user4_ru_band_mac << 14) |((uint32_t)tb_user4_ru_index << 8) |((uint32_t)tb_user4_ru_allocation << 0));
}

__INLINE void mpu_common_tb_user_4_cfg_1_unpack(uint8_t* tb_user4_nsts, uint8_t* tb_user4_starting_sts, uint8_t* tb_user4_coding_type, uint8_t* tb_user4_ru_type, uint8_t* tb_user4_ru_band_mac, uint8_t* tb_user4_ru_index, uint8_t* tb_user4_ru_allocation)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_4_CFG_1_ADDR);

	*tb_user4_nsts = (localVal & ((uint32_t)0x07000000)) >>  24;
	*tb_user4_starting_sts = (localVal & ((uint32_t)0x00700000)) >>  20;
	*tb_user4_coding_type = (localVal & ((uint32_t)0x00080000)) >>  19;
	*tb_user4_ru_type = (localVal & ((uint32_t)0x00070000)) >>  16;
	*tb_user4_ru_band_mac = (localVal & ((uint32_t)0x00004000)) >>  14;
	*tb_user4_ru_index = (localVal & ((uint32_t)0x00003F00)) >>  8;
	*tb_user4_ru_allocation = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t mpu_common_tb_user_4_cfg_1_tb_user_4_nsts_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_4_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE void mpu_common_tb_user_4_cfg_1_tb_user_4_nsts_setf(uint8_t tbuser4nsts)
{
	ASSERT_ERR((((uint32_t)tbuser4nsts << 24) & ~((uint32_t)0x07000000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_4_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_4_CFG_1_ADDR) & ~((uint32_t)0x07000000)) | ((uint32_t)tbuser4nsts <<24));
}
__INLINE uint8_t mpu_common_tb_user_4_cfg_1_tb_user_4_starting_sts_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_4_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00700000)) >> 20);
}
__INLINE void mpu_common_tb_user_4_cfg_1_tb_user_4_starting_sts_setf(uint8_t tbuser4startingsts)
{
	ASSERT_ERR((((uint32_t)tbuser4startingsts << 20) & ~((uint32_t)0x00700000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_4_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_4_CFG_1_ADDR) & ~((uint32_t)0x00700000)) | ((uint32_t)tbuser4startingsts <<20));
}
__INLINE uint8_t mpu_common_tb_user_4_cfg_1_tb_user_4_coding_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_4_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00080000)) >> 19);
}
__INLINE void mpu_common_tb_user_4_cfg_1_tb_user_4_coding_type_setf(uint8_t tbuser4codingtype)
{
	ASSERT_ERR((((uint32_t)tbuser4codingtype << 19) & ~((uint32_t)0x00080000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_4_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_4_CFG_1_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)tbuser4codingtype <<19));
}
__INLINE uint8_t mpu_common_tb_user_4_cfg_1_tb_user_4_ru_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_4_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00070000)) >> 16);
}
__INLINE void mpu_common_tb_user_4_cfg_1_tb_user_4_ru_type_setf(uint8_t tbuser4rutype)
{
	ASSERT_ERR((((uint32_t)tbuser4rutype << 16) & ~((uint32_t)0x00070000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_4_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_4_CFG_1_ADDR) & ~((uint32_t)0x00070000)) | ((uint32_t)tbuser4rutype <<16));
}
__INLINE uint8_t mpu_common_tb_user_4_cfg_1_tb_user_4_ru_band_mac_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_4_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void mpu_common_tb_user_4_cfg_1_tb_user_4_ru_band_mac_setf(uint8_t tbuser4rubandmac)
{
	ASSERT_ERR((((uint32_t)tbuser4rubandmac << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_4_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_4_CFG_1_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)tbuser4rubandmac <<14));
}
__INLINE uint8_t mpu_common_tb_user_4_cfg_1_tb_user_4_ru_index_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_4_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00003F00)) >> 8);
}
__INLINE void mpu_common_tb_user_4_cfg_1_tb_user_4_ru_index_setf(uint8_t tbuser4ruindex)
{
	ASSERT_ERR((((uint32_t)tbuser4ruindex << 8) & ~((uint32_t)0x00003F00)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_4_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_4_CFG_1_ADDR) & ~((uint32_t)0x00003F00)) | ((uint32_t)tbuser4ruindex <<8));
}
__INLINE uint8_t mpu_common_tb_user_4_cfg_1_tb_user_4_ru_allocation_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_4_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void mpu_common_tb_user_4_cfg_1_tb_user_4_ru_allocation_setf(uint8_t tbuser4ruallocation)
{
	ASSERT_ERR((((uint32_t)tbuser4ruallocation << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_4_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_4_CFG_1_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)tbuser4ruallocation <<0));
}

/**
 * @brief TB_USER_4_CFG_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    14:08 TB_USER4_TARGET_RSSI      0x0
 *    07:05 TB_USER4_RESERVED         0x0
 *    04    TB_USER4_DCM              0              
 *    03:00 TB_USER4_MCS              0x0
 * </pre>
 */
#define MPU_COMMON_TB_USER_4_CFG_2_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x0000012C)
#define MPU_COMMON_TB_USER_4_CFG_2_OFFSET      0x0000012C
#define MPU_COMMON_TB_USER_4_CFG_2_INDEX       0x0000004B
#define MPU_COMMON_TB_USER_4_CFG_2_RESET       0x00000000

__INLINE uint32_t  mpu_common_tb_user_4_cfg_2_get(void)
{
	return REG_PL_RD(MPU_COMMON_TB_USER_4_CFG_2_ADDR);
}

__INLINE void mpu_common_tb_user_4_cfg_2_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_TB_USER_4_CFG_2_ADDR, value);
}

// field definitions
#define MPU_COMMON_TB_USER_4_CFG_2_TB_USER_4_TARGET_RSSI_MASK    ((uint32_t)0x00007F00)
#define MPU_COMMON_TB_USER_4_CFG_2_TB_USER_4_TARGET_RSSI_LSB    8
#define MPU_COMMON_TB_USER_4_CFG_2_TB_USER_4_TARGET_RSSI_WIDTH    ((uint32_t)0x00000007)
#define MPU_COMMON_TB_USER_4_CFG_2_TB_USER_4_RESERVED_MASK    ((uint32_t)0x000000E0)
#define MPU_COMMON_TB_USER_4_CFG_2_TB_USER_4_RESERVED_LSB    5
#define MPU_COMMON_TB_USER_4_CFG_2_TB_USER_4_RESERVED_WIDTH    ((uint32_t)0x00000003)
#define MPU_COMMON_TB_USER_4_CFG_2_TB_USER_4_DCM_BIT    ((uint32_t)0x00000010)
#define MPU_COMMON_TB_USER_4_CFG_2_TB_USER_4_DCM_POS    4
#define MPU_COMMON_TB_USER_4_CFG_2_TB_USER_4_MCS_MASK    ((uint32_t)0x0000000F)
#define MPU_COMMON_TB_USER_4_CFG_2_TB_USER_4_MCS_LSB    0
#define MPU_COMMON_TB_USER_4_CFG_2_TB_USER_4_MCS_WIDTH    ((uint32_t)0x00000004)

#define MPU_COMMON_TB_USER_4_CFG_2_TB_USER_4_TARGET_RSSI_RST    0x0
#define MPU_COMMON_TB_USER_4_CFG_2_TB_USER_4_RESERVED_RST    0x0
#define MPU_COMMON_TB_USER_4_CFG_2_TB_USER_4_DCM_RST    0x0
#define MPU_COMMON_TB_USER_4_CFG_2_TB_USER_4_MCS_RST    0x0

__INLINE void mpu_common_tb_user_4_cfg_2_pack(uint8_t tb_user4_target_rssi, uint8_t tb_user4_reserved, uint8_t tb_user4_dcm, uint8_t tb_user4_mcs)
{
	ASSERT_ERR((((uint32_t)tb_user4_target_rssi << 8) & ~((uint32_t)0x00007F00)) == 0);
	ASSERT_ERR((((uint32_t)tb_user4_reserved << 5) & ~((uint32_t)0x000000E0)) == 0);
	ASSERT_ERR((((uint32_t)tb_user4_dcm << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)tb_user4_mcs << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_4_CFG_2_ADDR,  ((uint32_t)tb_user4_target_rssi << 8) |((uint32_t)tb_user4_reserved << 5) |((uint32_t)tb_user4_dcm << 4) |((uint32_t)tb_user4_mcs << 0));
}

__INLINE void mpu_common_tb_user_4_cfg_2_unpack(uint8_t* tb_user4_target_rssi, uint8_t* tb_user4_reserved, uint8_t* tb_user4_dcm, uint8_t* tb_user4_mcs)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_4_CFG_2_ADDR);

	*tb_user4_target_rssi = (localVal & ((uint32_t)0x00007F00)) >>  8;
	*tb_user4_reserved = (localVal & ((uint32_t)0x000000E0)) >>  5;
	*tb_user4_dcm = (localVal & ((uint32_t)0x00000010)) >>  4;
	*tb_user4_mcs = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t mpu_common_tb_user_4_cfg_2_tb_user_4_target_rssi_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_4_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007F00)) >> 8);
}
__INLINE void mpu_common_tb_user_4_cfg_2_tb_user_4_target_rssi_setf(uint8_t tbuser4targetrssi)
{
	ASSERT_ERR((((uint32_t)tbuser4targetrssi << 8) & ~((uint32_t)0x00007F00)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_4_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_4_CFG_2_ADDR) & ~((uint32_t)0x00007F00)) | ((uint32_t)tbuser4targetrssi <<8));
}
__INLINE uint8_t mpu_common_tb_user_4_cfg_2_tb_user_4_reserved_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_4_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000E0)) >> 5);
}
__INLINE void mpu_common_tb_user_4_cfg_2_tb_user_4_reserved_setf(uint8_t tbuser4reserved)
{
	ASSERT_ERR((((uint32_t)tbuser4reserved << 5) & ~((uint32_t)0x000000E0)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_4_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_4_CFG_2_ADDR) & ~((uint32_t)0x000000E0)) | ((uint32_t)tbuser4reserved <<5));
}
__INLINE uint8_t mpu_common_tb_user_4_cfg_2_tb_user_4_dcm_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_4_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void mpu_common_tb_user_4_cfg_2_tb_user_4_dcm_setf(uint8_t tbuser4dcm)
{
	ASSERT_ERR((((uint32_t)tbuser4dcm << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_4_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_4_CFG_2_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)tbuser4dcm <<4));
}
__INLINE uint8_t mpu_common_tb_user_4_cfg_2_tb_user_4_mcs_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_4_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void mpu_common_tb_user_4_cfg_2_tb_user_4_mcs_setf(uint8_t tbuser4mcs)
{
	ASSERT_ERR((((uint32_t)tbuser4mcs << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_4_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_4_CFG_2_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)tbuser4mcs <<0));
}

/**
 * @brief TB_USER_5_CFG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26:24 TB_USER5_NSTS             0x0
 *    22:20 TB_USER5_STARTING_STS     0x0
 *    19    TB_USER5_CODING_TYPE      0              
 *    18:16 TB_USER5_RU_TYPE          0x0
 *    14    TB_USER5_RU_BAND_MAC      0              
 *    13:08 TB_USER5_RU_INDEX         0x0
 *    07:00 TB_USER5_RU_ALLOCATION    0x0
 * </pre>
 */
#define MPU_COMMON_TB_USER_5_CFG_1_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000130)
#define MPU_COMMON_TB_USER_5_CFG_1_OFFSET      0x00000130
#define MPU_COMMON_TB_USER_5_CFG_1_INDEX       0x0000004C
#define MPU_COMMON_TB_USER_5_CFG_1_RESET       0x00000000

__INLINE uint32_t  mpu_common_tb_user_5_cfg_1_get(void)
{
	return REG_PL_RD(MPU_COMMON_TB_USER_5_CFG_1_ADDR);
}

__INLINE void mpu_common_tb_user_5_cfg_1_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_TB_USER_5_CFG_1_ADDR, value);
}

// field definitions
#define MPU_COMMON_TB_USER_5_CFG_1_TB_USER_5_NSTS_MASK    ((uint32_t)0x07000000)
#define MPU_COMMON_TB_USER_5_CFG_1_TB_USER_5_NSTS_LSB    24
#define MPU_COMMON_TB_USER_5_CFG_1_TB_USER_5_NSTS_WIDTH    ((uint32_t)0x00000003)
#define MPU_COMMON_TB_USER_5_CFG_1_TB_USER_5_STARTING_STS_MASK    ((uint32_t)0x00700000)
#define MPU_COMMON_TB_USER_5_CFG_1_TB_USER_5_STARTING_STS_LSB    20
#define MPU_COMMON_TB_USER_5_CFG_1_TB_USER_5_STARTING_STS_WIDTH    ((uint32_t)0x00000003)
#define MPU_COMMON_TB_USER_5_CFG_1_TB_USER_5_CODING_TYPE_BIT    ((uint32_t)0x00080000)
#define MPU_COMMON_TB_USER_5_CFG_1_TB_USER_5_CODING_TYPE_POS    19
#define MPU_COMMON_TB_USER_5_CFG_1_TB_USER_5_RU_TYPE_MASK    ((uint32_t)0x00070000)
#define MPU_COMMON_TB_USER_5_CFG_1_TB_USER_5_RU_TYPE_LSB    16
#define MPU_COMMON_TB_USER_5_CFG_1_TB_USER_5_RU_TYPE_WIDTH    ((uint32_t)0x00000003)
#define MPU_COMMON_TB_USER_5_CFG_1_TB_USER_5_RU_BAND_MAC_BIT    ((uint32_t)0x00004000)
#define MPU_COMMON_TB_USER_5_CFG_1_TB_USER_5_RU_BAND_MAC_POS    14
#define MPU_COMMON_TB_USER_5_CFG_1_TB_USER_5_RU_INDEX_MASK    ((uint32_t)0x00003F00)
#define MPU_COMMON_TB_USER_5_CFG_1_TB_USER_5_RU_INDEX_LSB    8
#define MPU_COMMON_TB_USER_5_CFG_1_TB_USER_5_RU_INDEX_WIDTH    ((uint32_t)0x00000006)
#define MPU_COMMON_TB_USER_5_CFG_1_TB_USER_5_RU_ALLOCATION_MASK    ((uint32_t)0x000000FF)
#define MPU_COMMON_TB_USER_5_CFG_1_TB_USER_5_RU_ALLOCATION_LSB    0
#define MPU_COMMON_TB_USER_5_CFG_1_TB_USER_5_RU_ALLOCATION_WIDTH    ((uint32_t)0x00000008)

#define MPU_COMMON_TB_USER_5_CFG_1_TB_USER_5_NSTS_RST    0x0
#define MPU_COMMON_TB_USER_5_CFG_1_TB_USER_5_STARTING_STS_RST    0x0
#define MPU_COMMON_TB_USER_5_CFG_1_TB_USER_5_CODING_TYPE_RST    0x0
#define MPU_COMMON_TB_USER_5_CFG_1_TB_USER_5_RU_TYPE_RST    0x0
#define MPU_COMMON_TB_USER_5_CFG_1_TB_USER_5_RU_BAND_MAC_RST    0x0
#define MPU_COMMON_TB_USER_5_CFG_1_TB_USER_5_RU_INDEX_RST    0x0
#define MPU_COMMON_TB_USER_5_CFG_1_TB_USER_5_RU_ALLOCATION_RST    0x0

__INLINE void mpu_common_tb_user_5_cfg_1_pack(uint8_t tb_user5_nsts, uint8_t tb_user5_starting_sts, uint8_t tb_user5_coding_type, uint8_t tb_user5_ru_type, uint8_t tb_user5_ru_band_mac, uint8_t tb_user5_ru_index, uint8_t tb_user5_ru_allocation)
{
	ASSERT_ERR((((uint32_t)tb_user5_nsts << 24) & ~((uint32_t)0x07000000)) == 0);
	ASSERT_ERR((((uint32_t)tb_user5_starting_sts << 20) & ~((uint32_t)0x00700000)) == 0);
	ASSERT_ERR((((uint32_t)tb_user5_coding_type << 19) & ~((uint32_t)0x00080000)) == 0);
	ASSERT_ERR((((uint32_t)tb_user5_ru_type << 16) & ~((uint32_t)0x00070000)) == 0);
	ASSERT_ERR((((uint32_t)tb_user5_ru_band_mac << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)tb_user5_ru_index << 8) & ~((uint32_t)0x00003F00)) == 0);
	ASSERT_ERR((((uint32_t)tb_user5_ru_allocation << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_5_CFG_1_ADDR,  ((uint32_t)tb_user5_nsts << 24) |((uint32_t)tb_user5_starting_sts << 20) |((uint32_t)tb_user5_coding_type << 19) |((uint32_t)tb_user5_ru_type << 16) |((uint32_t)tb_user5_ru_band_mac << 14) |((uint32_t)tb_user5_ru_index << 8) |((uint32_t)tb_user5_ru_allocation << 0));
}

__INLINE void mpu_common_tb_user_5_cfg_1_unpack(uint8_t* tb_user5_nsts, uint8_t* tb_user5_starting_sts, uint8_t* tb_user5_coding_type, uint8_t* tb_user5_ru_type, uint8_t* tb_user5_ru_band_mac, uint8_t* tb_user5_ru_index, uint8_t* tb_user5_ru_allocation)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_5_CFG_1_ADDR);

	*tb_user5_nsts = (localVal & ((uint32_t)0x07000000)) >>  24;
	*tb_user5_starting_sts = (localVal & ((uint32_t)0x00700000)) >>  20;
	*tb_user5_coding_type = (localVal & ((uint32_t)0x00080000)) >>  19;
	*tb_user5_ru_type = (localVal & ((uint32_t)0x00070000)) >>  16;
	*tb_user5_ru_band_mac = (localVal & ((uint32_t)0x00004000)) >>  14;
	*tb_user5_ru_index = (localVal & ((uint32_t)0x00003F00)) >>  8;
	*tb_user5_ru_allocation = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t mpu_common_tb_user_5_cfg_1_tb_user_5_nsts_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_5_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE void mpu_common_tb_user_5_cfg_1_tb_user_5_nsts_setf(uint8_t tbuser5nsts)
{
	ASSERT_ERR((((uint32_t)tbuser5nsts << 24) & ~((uint32_t)0x07000000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_5_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_5_CFG_1_ADDR) & ~((uint32_t)0x07000000)) | ((uint32_t)tbuser5nsts <<24));
}
__INLINE uint8_t mpu_common_tb_user_5_cfg_1_tb_user_5_starting_sts_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_5_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00700000)) >> 20);
}
__INLINE void mpu_common_tb_user_5_cfg_1_tb_user_5_starting_sts_setf(uint8_t tbuser5startingsts)
{
	ASSERT_ERR((((uint32_t)tbuser5startingsts << 20) & ~((uint32_t)0x00700000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_5_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_5_CFG_1_ADDR) & ~((uint32_t)0x00700000)) | ((uint32_t)tbuser5startingsts <<20));
}
__INLINE uint8_t mpu_common_tb_user_5_cfg_1_tb_user_5_coding_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_5_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00080000)) >> 19);
}
__INLINE void mpu_common_tb_user_5_cfg_1_tb_user_5_coding_type_setf(uint8_t tbuser5codingtype)
{
	ASSERT_ERR((((uint32_t)tbuser5codingtype << 19) & ~((uint32_t)0x00080000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_5_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_5_CFG_1_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)tbuser5codingtype <<19));
}
__INLINE uint8_t mpu_common_tb_user_5_cfg_1_tb_user_5_ru_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_5_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00070000)) >> 16);
}
__INLINE void mpu_common_tb_user_5_cfg_1_tb_user_5_ru_type_setf(uint8_t tbuser5rutype)
{
	ASSERT_ERR((((uint32_t)tbuser5rutype << 16) & ~((uint32_t)0x00070000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_5_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_5_CFG_1_ADDR) & ~((uint32_t)0x00070000)) | ((uint32_t)tbuser5rutype <<16));
}
__INLINE uint8_t mpu_common_tb_user_5_cfg_1_tb_user_5_ru_band_mac_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_5_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void mpu_common_tb_user_5_cfg_1_tb_user_5_ru_band_mac_setf(uint8_t tbuser5rubandmac)
{
	ASSERT_ERR((((uint32_t)tbuser5rubandmac << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_5_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_5_CFG_1_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)tbuser5rubandmac <<14));
}
__INLINE uint8_t mpu_common_tb_user_5_cfg_1_tb_user_5_ru_index_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_5_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00003F00)) >> 8);
}
__INLINE void mpu_common_tb_user_5_cfg_1_tb_user_5_ru_index_setf(uint8_t tbuser5ruindex)
{
	ASSERT_ERR((((uint32_t)tbuser5ruindex << 8) & ~((uint32_t)0x00003F00)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_5_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_5_CFG_1_ADDR) & ~((uint32_t)0x00003F00)) | ((uint32_t)tbuser5ruindex <<8));
}
__INLINE uint8_t mpu_common_tb_user_5_cfg_1_tb_user_5_ru_allocation_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_5_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void mpu_common_tb_user_5_cfg_1_tb_user_5_ru_allocation_setf(uint8_t tbuser5ruallocation)
{
	ASSERT_ERR((((uint32_t)tbuser5ruallocation << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_5_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_5_CFG_1_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)tbuser5ruallocation <<0));
}

/**
 * @brief TB_USER_5_CFG_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    14:08 TB_USER5_TARGET_RSSI      0x0
 *    07:05 TB_USER5_RESERVED         0x0
 *    04    TB_USER5_DCM              0              
 *    03:00 TB_USER5_MCS              0x0
 * </pre>
 */
#define MPU_COMMON_TB_USER_5_CFG_2_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000134)
#define MPU_COMMON_TB_USER_5_CFG_2_OFFSET      0x00000134
#define MPU_COMMON_TB_USER_5_CFG_2_INDEX       0x0000004D
#define MPU_COMMON_TB_USER_5_CFG_2_RESET       0x00000000

__INLINE uint32_t  mpu_common_tb_user_5_cfg_2_get(void)
{
	return REG_PL_RD(MPU_COMMON_TB_USER_5_CFG_2_ADDR);
}

__INLINE void mpu_common_tb_user_5_cfg_2_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_TB_USER_5_CFG_2_ADDR, value);
}

// field definitions
#define MPU_COMMON_TB_USER_5_CFG_2_TB_USER_5_TARGET_RSSI_MASK    ((uint32_t)0x00007F00)
#define MPU_COMMON_TB_USER_5_CFG_2_TB_USER_5_TARGET_RSSI_LSB    8
#define MPU_COMMON_TB_USER_5_CFG_2_TB_USER_5_TARGET_RSSI_WIDTH    ((uint32_t)0x00000007)
#define MPU_COMMON_TB_USER_5_CFG_2_TB_USER_5_RESERVED_MASK    ((uint32_t)0x000000E0)
#define MPU_COMMON_TB_USER_5_CFG_2_TB_USER_5_RESERVED_LSB    5
#define MPU_COMMON_TB_USER_5_CFG_2_TB_USER_5_RESERVED_WIDTH    ((uint32_t)0x00000003)
#define MPU_COMMON_TB_USER_5_CFG_2_TB_USER_5_DCM_BIT    ((uint32_t)0x00000010)
#define MPU_COMMON_TB_USER_5_CFG_2_TB_USER_5_DCM_POS    4
#define MPU_COMMON_TB_USER_5_CFG_2_TB_USER_5_MCS_MASK    ((uint32_t)0x0000000F)
#define MPU_COMMON_TB_USER_5_CFG_2_TB_USER_5_MCS_LSB    0
#define MPU_COMMON_TB_USER_5_CFG_2_TB_USER_5_MCS_WIDTH    ((uint32_t)0x00000004)

#define MPU_COMMON_TB_USER_5_CFG_2_TB_USER_5_TARGET_RSSI_RST    0x0
#define MPU_COMMON_TB_USER_5_CFG_2_TB_USER_5_RESERVED_RST    0x0
#define MPU_COMMON_TB_USER_5_CFG_2_TB_USER_5_DCM_RST    0x0
#define MPU_COMMON_TB_USER_5_CFG_2_TB_USER_5_MCS_RST    0x0

__INLINE void mpu_common_tb_user_5_cfg_2_pack(uint8_t tb_user5_target_rssi, uint8_t tb_user5_reserved, uint8_t tb_user5_dcm, uint8_t tb_user5_mcs)
{
	ASSERT_ERR((((uint32_t)tb_user5_target_rssi << 8) & ~((uint32_t)0x00007F00)) == 0);
	ASSERT_ERR((((uint32_t)tb_user5_reserved << 5) & ~((uint32_t)0x000000E0)) == 0);
	ASSERT_ERR((((uint32_t)tb_user5_dcm << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)tb_user5_mcs << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_5_CFG_2_ADDR,  ((uint32_t)tb_user5_target_rssi << 8) |((uint32_t)tb_user5_reserved << 5) |((uint32_t)tb_user5_dcm << 4) |((uint32_t)tb_user5_mcs << 0));
}

__INLINE void mpu_common_tb_user_5_cfg_2_unpack(uint8_t* tb_user5_target_rssi, uint8_t* tb_user5_reserved, uint8_t* tb_user5_dcm, uint8_t* tb_user5_mcs)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_5_CFG_2_ADDR);

	*tb_user5_target_rssi = (localVal & ((uint32_t)0x00007F00)) >>  8;
	*tb_user5_reserved = (localVal & ((uint32_t)0x000000E0)) >>  5;
	*tb_user5_dcm = (localVal & ((uint32_t)0x00000010)) >>  4;
	*tb_user5_mcs = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t mpu_common_tb_user_5_cfg_2_tb_user_5_target_rssi_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_5_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007F00)) >> 8);
}
__INLINE void mpu_common_tb_user_5_cfg_2_tb_user_5_target_rssi_setf(uint8_t tbuser5targetrssi)
{
	ASSERT_ERR((((uint32_t)tbuser5targetrssi << 8) & ~((uint32_t)0x00007F00)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_5_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_5_CFG_2_ADDR) & ~((uint32_t)0x00007F00)) | ((uint32_t)tbuser5targetrssi <<8));
}
__INLINE uint8_t mpu_common_tb_user_5_cfg_2_tb_user_5_reserved_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_5_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000E0)) >> 5);
}
__INLINE void mpu_common_tb_user_5_cfg_2_tb_user_5_reserved_setf(uint8_t tbuser5reserved)
{
	ASSERT_ERR((((uint32_t)tbuser5reserved << 5) & ~((uint32_t)0x000000E0)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_5_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_5_CFG_2_ADDR) & ~((uint32_t)0x000000E0)) | ((uint32_t)tbuser5reserved <<5));
}
__INLINE uint8_t mpu_common_tb_user_5_cfg_2_tb_user_5_dcm_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_5_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void mpu_common_tb_user_5_cfg_2_tb_user_5_dcm_setf(uint8_t tbuser5dcm)
{
	ASSERT_ERR((((uint32_t)tbuser5dcm << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_5_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_5_CFG_2_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)tbuser5dcm <<4));
}
__INLINE uint8_t mpu_common_tb_user_5_cfg_2_tb_user_5_mcs_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_5_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void mpu_common_tb_user_5_cfg_2_tb_user_5_mcs_setf(uint8_t tbuser5mcs)
{
	ASSERT_ERR((((uint32_t)tbuser5mcs << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_5_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_5_CFG_2_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)tbuser5mcs <<0));
}

/**
 * @brief TB_USER_6_CFG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26:24 TB_USER6_NSTS             0x0
 *    22:20 TB_USER6_STARTING_STS     0x0
 *    19    TB_USER6_CODING_TYPE      0              
 *    18:16 TB_USER6_RU_TYPE          0x0
 *    14    TB_USER6_RU_BAND_MAC      0              
 *    13:08 TB_USER6_RU_INDEX         0x0
 *    07:00 TB_USER6_RU_ALLOCATION    0x0
 * </pre>
 */
#define MPU_COMMON_TB_USER_6_CFG_1_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000138)
#define MPU_COMMON_TB_USER_6_CFG_1_OFFSET      0x00000138
#define MPU_COMMON_TB_USER_6_CFG_1_INDEX       0x0000004E
#define MPU_COMMON_TB_USER_6_CFG_1_RESET       0x00000000

__INLINE uint32_t  mpu_common_tb_user_6_cfg_1_get(void)
{
	return REG_PL_RD(MPU_COMMON_TB_USER_6_CFG_1_ADDR);
}

__INLINE void mpu_common_tb_user_6_cfg_1_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_TB_USER_6_CFG_1_ADDR, value);
}

// field definitions
#define MPU_COMMON_TB_USER_6_CFG_1_TB_USER_6_NSTS_MASK    ((uint32_t)0x07000000)
#define MPU_COMMON_TB_USER_6_CFG_1_TB_USER_6_NSTS_LSB    24
#define MPU_COMMON_TB_USER_6_CFG_1_TB_USER_6_NSTS_WIDTH    ((uint32_t)0x00000003)
#define MPU_COMMON_TB_USER_6_CFG_1_TB_USER_6_STARTING_STS_MASK    ((uint32_t)0x00700000)
#define MPU_COMMON_TB_USER_6_CFG_1_TB_USER_6_STARTING_STS_LSB    20
#define MPU_COMMON_TB_USER_6_CFG_1_TB_USER_6_STARTING_STS_WIDTH    ((uint32_t)0x00000003)
#define MPU_COMMON_TB_USER_6_CFG_1_TB_USER_6_CODING_TYPE_BIT    ((uint32_t)0x00080000)
#define MPU_COMMON_TB_USER_6_CFG_1_TB_USER_6_CODING_TYPE_POS    19
#define MPU_COMMON_TB_USER_6_CFG_1_TB_USER_6_RU_TYPE_MASK    ((uint32_t)0x00070000)
#define MPU_COMMON_TB_USER_6_CFG_1_TB_USER_6_RU_TYPE_LSB    16
#define MPU_COMMON_TB_USER_6_CFG_1_TB_USER_6_RU_TYPE_WIDTH    ((uint32_t)0x00000003)
#define MPU_COMMON_TB_USER_6_CFG_1_TB_USER_6_RU_BAND_MAC_BIT    ((uint32_t)0x00004000)
#define MPU_COMMON_TB_USER_6_CFG_1_TB_USER_6_RU_BAND_MAC_POS    14
#define MPU_COMMON_TB_USER_6_CFG_1_TB_USER_6_RU_INDEX_MASK    ((uint32_t)0x00003F00)
#define MPU_COMMON_TB_USER_6_CFG_1_TB_USER_6_RU_INDEX_LSB    8
#define MPU_COMMON_TB_USER_6_CFG_1_TB_USER_6_RU_INDEX_WIDTH    ((uint32_t)0x00000006)
#define MPU_COMMON_TB_USER_6_CFG_1_TB_USER_6_RU_ALLOCATION_MASK    ((uint32_t)0x000000FF)
#define MPU_COMMON_TB_USER_6_CFG_1_TB_USER_6_RU_ALLOCATION_LSB    0
#define MPU_COMMON_TB_USER_6_CFG_1_TB_USER_6_RU_ALLOCATION_WIDTH    ((uint32_t)0x00000008)

#define MPU_COMMON_TB_USER_6_CFG_1_TB_USER_6_NSTS_RST    0x0
#define MPU_COMMON_TB_USER_6_CFG_1_TB_USER_6_STARTING_STS_RST    0x0
#define MPU_COMMON_TB_USER_6_CFG_1_TB_USER_6_CODING_TYPE_RST    0x0
#define MPU_COMMON_TB_USER_6_CFG_1_TB_USER_6_RU_TYPE_RST    0x0
#define MPU_COMMON_TB_USER_6_CFG_1_TB_USER_6_RU_BAND_MAC_RST    0x0
#define MPU_COMMON_TB_USER_6_CFG_1_TB_USER_6_RU_INDEX_RST    0x0
#define MPU_COMMON_TB_USER_6_CFG_1_TB_USER_6_RU_ALLOCATION_RST    0x0

__INLINE void mpu_common_tb_user_6_cfg_1_pack(uint8_t tb_user6_nsts, uint8_t tb_user6_starting_sts, uint8_t tb_user6_coding_type, uint8_t tb_user6_ru_type, uint8_t tb_user6_ru_band_mac, uint8_t tb_user6_ru_index, uint8_t tb_user6_ru_allocation)
{
	ASSERT_ERR((((uint32_t)tb_user6_nsts << 24) & ~((uint32_t)0x07000000)) == 0);
	ASSERT_ERR((((uint32_t)tb_user6_starting_sts << 20) & ~((uint32_t)0x00700000)) == 0);
	ASSERT_ERR((((uint32_t)tb_user6_coding_type << 19) & ~((uint32_t)0x00080000)) == 0);
	ASSERT_ERR((((uint32_t)tb_user6_ru_type << 16) & ~((uint32_t)0x00070000)) == 0);
	ASSERT_ERR((((uint32_t)tb_user6_ru_band_mac << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)tb_user6_ru_index << 8) & ~((uint32_t)0x00003F00)) == 0);
	ASSERT_ERR((((uint32_t)tb_user6_ru_allocation << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_6_CFG_1_ADDR,  ((uint32_t)tb_user6_nsts << 24) |((uint32_t)tb_user6_starting_sts << 20) |((uint32_t)tb_user6_coding_type << 19) |((uint32_t)tb_user6_ru_type << 16) |((uint32_t)tb_user6_ru_band_mac << 14) |((uint32_t)tb_user6_ru_index << 8) |((uint32_t)tb_user6_ru_allocation << 0));
}

__INLINE void mpu_common_tb_user_6_cfg_1_unpack(uint8_t* tb_user6_nsts, uint8_t* tb_user6_starting_sts, uint8_t* tb_user6_coding_type, uint8_t* tb_user6_ru_type, uint8_t* tb_user6_ru_band_mac, uint8_t* tb_user6_ru_index, uint8_t* tb_user6_ru_allocation)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_6_CFG_1_ADDR);

	*tb_user6_nsts = (localVal & ((uint32_t)0x07000000)) >>  24;
	*tb_user6_starting_sts = (localVal & ((uint32_t)0x00700000)) >>  20;
	*tb_user6_coding_type = (localVal & ((uint32_t)0x00080000)) >>  19;
	*tb_user6_ru_type = (localVal & ((uint32_t)0x00070000)) >>  16;
	*tb_user6_ru_band_mac = (localVal & ((uint32_t)0x00004000)) >>  14;
	*tb_user6_ru_index = (localVal & ((uint32_t)0x00003F00)) >>  8;
	*tb_user6_ru_allocation = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t mpu_common_tb_user_6_cfg_1_tb_user_6_nsts_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_6_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE void mpu_common_tb_user_6_cfg_1_tb_user_6_nsts_setf(uint8_t tbuser6nsts)
{
	ASSERT_ERR((((uint32_t)tbuser6nsts << 24) & ~((uint32_t)0x07000000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_6_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_6_CFG_1_ADDR) & ~((uint32_t)0x07000000)) | ((uint32_t)tbuser6nsts <<24));
}
__INLINE uint8_t mpu_common_tb_user_6_cfg_1_tb_user_6_starting_sts_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_6_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00700000)) >> 20);
}
__INLINE void mpu_common_tb_user_6_cfg_1_tb_user_6_starting_sts_setf(uint8_t tbuser6startingsts)
{
	ASSERT_ERR((((uint32_t)tbuser6startingsts << 20) & ~((uint32_t)0x00700000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_6_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_6_CFG_1_ADDR) & ~((uint32_t)0x00700000)) | ((uint32_t)tbuser6startingsts <<20));
}
__INLINE uint8_t mpu_common_tb_user_6_cfg_1_tb_user_6_coding_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_6_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00080000)) >> 19);
}
__INLINE void mpu_common_tb_user_6_cfg_1_tb_user_6_coding_type_setf(uint8_t tbuser6codingtype)
{
	ASSERT_ERR((((uint32_t)tbuser6codingtype << 19) & ~((uint32_t)0x00080000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_6_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_6_CFG_1_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)tbuser6codingtype <<19));
}
__INLINE uint8_t mpu_common_tb_user_6_cfg_1_tb_user_6_ru_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_6_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00070000)) >> 16);
}
__INLINE void mpu_common_tb_user_6_cfg_1_tb_user_6_ru_type_setf(uint8_t tbuser6rutype)
{
	ASSERT_ERR((((uint32_t)tbuser6rutype << 16) & ~((uint32_t)0x00070000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_6_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_6_CFG_1_ADDR) & ~((uint32_t)0x00070000)) | ((uint32_t)tbuser6rutype <<16));
}
__INLINE uint8_t mpu_common_tb_user_6_cfg_1_tb_user_6_ru_band_mac_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_6_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void mpu_common_tb_user_6_cfg_1_tb_user_6_ru_band_mac_setf(uint8_t tbuser6rubandmac)
{
	ASSERT_ERR((((uint32_t)tbuser6rubandmac << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_6_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_6_CFG_1_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)tbuser6rubandmac <<14));
}
__INLINE uint8_t mpu_common_tb_user_6_cfg_1_tb_user_6_ru_index_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_6_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00003F00)) >> 8);
}
__INLINE void mpu_common_tb_user_6_cfg_1_tb_user_6_ru_index_setf(uint8_t tbuser6ruindex)
{
	ASSERT_ERR((((uint32_t)tbuser6ruindex << 8) & ~((uint32_t)0x00003F00)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_6_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_6_CFG_1_ADDR) & ~((uint32_t)0x00003F00)) | ((uint32_t)tbuser6ruindex <<8));
}
__INLINE uint8_t mpu_common_tb_user_6_cfg_1_tb_user_6_ru_allocation_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_6_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void mpu_common_tb_user_6_cfg_1_tb_user_6_ru_allocation_setf(uint8_t tbuser6ruallocation)
{
	ASSERT_ERR((((uint32_t)tbuser6ruallocation << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_6_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_6_CFG_1_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)tbuser6ruallocation <<0));
}

/**
 * @brief TB_USER_6_CFG_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    14:08 TB_USER6_TARGET_RSSI      0x0
 *    07:05 TB_USER6_RESERVED         0x0
 *    04    TB_USER6_DCM              0              
 *    03:00 TB_USER6_MCS              0x0
 * </pre>
 */
#define MPU_COMMON_TB_USER_6_CFG_2_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x0000013C)
#define MPU_COMMON_TB_USER_6_CFG_2_OFFSET      0x0000013C
#define MPU_COMMON_TB_USER_6_CFG_2_INDEX       0x0000004F
#define MPU_COMMON_TB_USER_6_CFG_2_RESET       0x00000000

__INLINE uint32_t  mpu_common_tb_user_6_cfg_2_get(void)
{
	return REG_PL_RD(MPU_COMMON_TB_USER_6_CFG_2_ADDR);
}

__INLINE void mpu_common_tb_user_6_cfg_2_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_TB_USER_6_CFG_2_ADDR, value);
}

// field definitions
#define MPU_COMMON_TB_USER_6_CFG_2_TB_USER_6_TARGET_RSSI_MASK    ((uint32_t)0x00007F00)
#define MPU_COMMON_TB_USER_6_CFG_2_TB_USER_6_TARGET_RSSI_LSB    8
#define MPU_COMMON_TB_USER_6_CFG_2_TB_USER_6_TARGET_RSSI_WIDTH    ((uint32_t)0x00000007)
#define MPU_COMMON_TB_USER_6_CFG_2_TB_USER_6_RESERVED_MASK    ((uint32_t)0x000000E0)
#define MPU_COMMON_TB_USER_6_CFG_2_TB_USER_6_RESERVED_LSB    5
#define MPU_COMMON_TB_USER_6_CFG_2_TB_USER_6_RESERVED_WIDTH    ((uint32_t)0x00000003)
#define MPU_COMMON_TB_USER_6_CFG_2_TB_USER_6_DCM_BIT    ((uint32_t)0x00000010)
#define MPU_COMMON_TB_USER_6_CFG_2_TB_USER_6_DCM_POS    4
#define MPU_COMMON_TB_USER_6_CFG_2_TB_USER_6_MCS_MASK    ((uint32_t)0x0000000F)
#define MPU_COMMON_TB_USER_6_CFG_2_TB_USER_6_MCS_LSB    0
#define MPU_COMMON_TB_USER_6_CFG_2_TB_USER_6_MCS_WIDTH    ((uint32_t)0x00000004)

#define MPU_COMMON_TB_USER_6_CFG_2_TB_USER_6_TARGET_RSSI_RST    0x0
#define MPU_COMMON_TB_USER_6_CFG_2_TB_USER_6_RESERVED_RST    0x0
#define MPU_COMMON_TB_USER_6_CFG_2_TB_USER_6_DCM_RST    0x0
#define MPU_COMMON_TB_USER_6_CFG_2_TB_USER_6_MCS_RST    0x0

__INLINE void mpu_common_tb_user_6_cfg_2_pack(uint8_t tb_user6_target_rssi, uint8_t tb_user6_reserved, uint8_t tb_user6_dcm, uint8_t tb_user6_mcs)
{
	ASSERT_ERR((((uint32_t)tb_user6_target_rssi << 8) & ~((uint32_t)0x00007F00)) == 0);
	ASSERT_ERR((((uint32_t)tb_user6_reserved << 5) & ~((uint32_t)0x000000E0)) == 0);
	ASSERT_ERR((((uint32_t)tb_user6_dcm << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)tb_user6_mcs << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_6_CFG_2_ADDR,  ((uint32_t)tb_user6_target_rssi << 8) |((uint32_t)tb_user6_reserved << 5) |((uint32_t)tb_user6_dcm << 4) |((uint32_t)tb_user6_mcs << 0));
}

__INLINE void mpu_common_tb_user_6_cfg_2_unpack(uint8_t* tb_user6_target_rssi, uint8_t* tb_user6_reserved, uint8_t* tb_user6_dcm, uint8_t* tb_user6_mcs)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_6_CFG_2_ADDR);

	*tb_user6_target_rssi = (localVal & ((uint32_t)0x00007F00)) >>  8;
	*tb_user6_reserved = (localVal & ((uint32_t)0x000000E0)) >>  5;
	*tb_user6_dcm = (localVal & ((uint32_t)0x00000010)) >>  4;
	*tb_user6_mcs = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t mpu_common_tb_user_6_cfg_2_tb_user_6_target_rssi_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_6_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007F00)) >> 8);
}
__INLINE void mpu_common_tb_user_6_cfg_2_tb_user_6_target_rssi_setf(uint8_t tbuser6targetrssi)
{
	ASSERT_ERR((((uint32_t)tbuser6targetrssi << 8) & ~((uint32_t)0x00007F00)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_6_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_6_CFG_2_ADDR) & ~((uint32_t)0x00007F00)) | ((uint32_t)tbuser6targetrssi <<8));
}
__INLINE uint8_t mpu_common_tb_user_6_cfg_2_tb_user_6_reserved_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_6_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000E0)) >> 5);
}
__INLINE void mpu_common_tb_user_6_cfg_2_tb_user_6_reserved_setf(uint8_t tbuser6reserved)
{
	ASSERT_ERR((((uint32_t)tbuser6reserved << 5) & ~((uint32_t)0x000000E0)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_6_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_6_CFG_2_ADDR) & ~((uint32_t)0x000000E0)) | ((uint32_t)tbuser6reserved <<5));
}
__INLINE uint8_t mpu_common_tb_user_6_cfg_2_tb_user_6_dcm_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_6_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void mpu_common_tb_user_6_cfg_2_tb_user_6_dcm_setf(uint8_t tbuser6dcm)
{
	ASSERT_ERR((((uint32_t)tbuser6dcm << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_6_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_6_CFG_2_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)tbuser6dcm <<4));
}
__INLINE uint8_t mpu_common_tb_user_6_cfg_2_tb_user_6_mcs_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_6_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void mpu_common_tb_user_6_cfg_2_tb_user_6_mcs_setf(uint8_t tbuser6mcs)
{
	ASSERT_ERR((((uint32_t)tbuser6mcs << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_6_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_6_CFG_2_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)tbuser6mcs <<0));
}

/**
 * @brief TB_USER_7_CFG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26:24 TB_USER7_NSTS             0x0
 *    22:20 TB_USER7_STARTING_STS     0x0
 *    19    TB_USER7_CODING_TYPE      0              
 *    18:16 TB_USER7_RU_TYPE          0x0
 *    14    TB_USER7_RU_BAND_MAC      0              
 *    13:08 TB_USER7_RU_INDEX         0x0
 *    07:00 TB_USER7_RU_ALLOCATION    0x0
 * </pre>
 */
#define MPU_COMMON_TB_USER_7_CFG_1_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000140)
#define MPU_COMMON_TB_USER_7_CFG_1_OFFSET      0x00000140
#define MPU_COMMON_TB_USER_7_CFG_1_INDEX       0x00000050
#define MPU_COMMON_TB_USER_7_CFG_1_RESET       0x00000000

__INLINE uint32_t  mpu_common_tb_user_7_cfg_1_get(void)
{
	return REG_PL_RD(MPU_COMMON_TB_USER_7_CFG_1_ADDR);
}

__INLINE void mpu_common_tb_user_7_cfg_1_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_TB_USER_7_CFG_1_ADDR, value);
}

// field definitions
#define MPU_COMMON_TB_USER_7_CFG_1_TB_USER_7_NSTS_MASK    ((uint32_t)0x07000000)
#define MPU_COMMON_TB_USER_7_CFG_1_TB_USER_7_NSTS_LSB    24
#define MPU_COMMON_TB_USER_7_CFG_1_TB_USER_7_NSTS_WIDTH    ((uint32_t)0x00000003)
#define MPU_COMMON_TB_USER_7_CFG_1_TB_USER_7_STARTING_STS_MASK    ((uint32_t)0x00700000)
#define MPU_COMMON_TB_USER_7_CFG_1_TB_USER_7_STARTING_STS_LSB    20
#define MPU_COMMON_TB_USER_7_CFG_1_TB_USER_7_STARTING_STS_WIDTH    ((uint32_t)0x00000003)
#define MPU_COMMON_TB_USER_7_CFG_1_TB_USER_7_CODING_TYPE_BIT    ((uint32_t)0x00080000)
#define MPU_COMMON_TB_USER_7_CFG_1_TB_USER_7_CODING_TYPE_POS    19
#define MPU_COMMON_TB_USER_7_CFG_1_TB_USER_7_RU_TYPE_MASK    ((uint32_t)0x00070000)
#define MPU_COMMON_TB_USER_7_CFG_1_TB_USER_7_RU_TYPE_LSB    16
#define MPU_COMMON_TB_USER_7_CFG_1_TB_USER_7_RU_TYPE_WIDTH    ((uint32_t)0x00000003)
#define MPU_COMMON_TB_USER_7_CFG_1_TB_USER_7_RU_BAND_MAC_BIT    ((uint32_t)0x00004000)
#define MPU_COMMON_TB_USER_7_CFG_1_TB_USER_7_RU_BAND_MAC_POS    14
#define MPU_COMMON_TB_USER_7_CFG_1_TB_USER_7_RU_INDEX_MASK    ((uint32_t)0x00003F00)
#define MPU_COMMON_TB_USER_7_CFG_1_TB_USER_7_RU_INDEX_LSB    8
#define MPU_COMMON_TB_USER_7_CFG_1_TB_USER_7_RU_INDEX_WIDTH    ((uint32_t)0x00000006)
#define MPU_COMMON_TB_USER_7_CFG_1_TB_USER_7_RU_ALLOCATION_MASK    ((uint32_t)0x000000FF)
#define MPU_COMMON_TB_USER_7_CFG_1_TB_USER_7_RU_ALLOCATION_LSB    0
#define MPU_COMMON_TB_USER_7_CFG_1_TB_USER_7_RU_ALLOCATION_WIDTH    ((uint32_t)0x00000008)

#define MPU_COMMON_TB_USER_7_CFG_1_TB_USER_7_NSTS_RST    0x0
#define MPU_COMMON_TB_USER_7_CFG_1_TB_USER_7_STARTING_STS_RST    0x0
#define MPU_COMMON_TB_USER_7_CFG_1_TB_USER_7_CODING_TYPE_RST    0x0
#define MPU_COMMON_TB_USER_7_CFG_1_TB_USER_7_RU_TYPE_RST    0x0
#define MPU_COMMON_TB_USER_7_CFG_1_TB_USER_7_RU_BAND_MAC_RST    0x0
#define MPU_COMMON_TB_USER_7_CFG_1_TB_USER_7_RU_INDEX_RST    0x0
#define MPU_COMMON_TB_USER_7_CFG_1_TB_USER_7_RU_ALLOCATION_RST    0x0

__INLINE void mpu_common_tb_user_7_cfg_1_pack(uint8_t tb_user7_nsts, uint8_t tb_user7_starting_sts, uint8_t tb_user7_coding_type, uint8_t tb_user7_ru_type, uint8_t tb_user7_ru_band_mac, uint8_t tb_user7_ru_index, uint8_t tb_user7_ru_allocation)
{
	ASSERT_ERR((((uint32_t)tb_user7_nsts << 24) & ~((uint32_t)0x07000000)) == 0);
	ASSERT_ERR((((uint32_t)tb_user7_starting_sts << 20) & ~((uint32_t)0x00700000)) == 0);
	ASSERT_ERR((((uint32_t)tb_user7_coding_type << 19) & ~((uint32_t)0x00080000)) == 0);
	ASSERT_ERR((((uint32_t)tb_user7_ru_type << 16) & ~((uint32_t)0x00070000)) == 0);
	ASSERT_ERR((((uint32_t)tb_user7_ru_band_mac << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)tb_user7_ru_index << 8) & ~((uint32_t)0x00003F00)) == 0);
	ASSERT_ERR((((uint32_t)tb_user7_ru_allocation << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_7_CFG_1_ADDR,  ((uint32_t)tb_user7_nsts << 24) |((uint32_t)tb_user7_starting_sts << 20) |((uint32_t)tb_user7_coding_type << 19) |((uint32_t)tb_user7_ru_type << 16) |((uint32_t)tb_user7_ru_band_mac << 14) |((uint32_t)tb_user7_ru_index << 8) |((uint32_t)tb_user7_ru_allocation << 0));
}

__INLINE void mpu_common_tb_user_7_cfg_1_unpack(uint8_t* tb_user7_nsts, uint8_t* tb_user7_starting_sts, uint8_t* tb_user7_coding_type, uint8_t* tb_user7_ru_type, uint8_t* tb_user7_ru_band_mac, uint8_t* tb_user7_ru_index, uint8_t* tb_user7_ru_allocation)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_7_CFG_1_ADDR);

	*tb_user7_nsts = (localVal & ((uint32_t)0x07000000)) >>  24;
	*tb_user7_starting_sts = (localVal & ((uint32_t)0x00700000)) >>  20;
	*tb_user7_coding_type = (localVal & ((uint32_t)0x00080000)) >>  19;
	*tb_user7_ru_type = (localVal & ((uint32_t)0x00070000)) >>  16;
	*tb_user7_ru_band_mac = (localVal & ((uint32_t)0x00004000)) >>  14;
	*tb_user7_ru_index = (localVal & ((uint32_t)0x00003F00)) >>  8;
	*tb_user7_ru_allocation = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t mpu_common_tb_user_7_cfg_1_tb_user_7_nsts_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_7_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE void mpu_common_tb_user_7_cfg_1_tb_user_7_nsts_setf(uint8_t tbuser7nsts)
{
	ASSERT_ERR((((uint32_t)tbuser7nsts << 24) & ~((uint32_t)0x07000000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_7_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_7_CFG_1_ADDR) & ~((uint32_t)0x07000000)) | ((uint32_t)tbuser7nsts <<24));
}
__INLINE uint8_t mpu_common_tb_user_7_cfg_1_tb_user_7_starting_sts_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_7_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00700000)) >> 20);
}
__INLINE void mpu_common_tb_user_7_cfg_1_tb_user_7_starting_sts_setf(uint8_t tbuser7startingsts)
{
	ASSERT_ERR((((uint32_t)tbuser7startingsts << 20) & ~((uint32_t)0x00700000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_7_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_7_CFG_1_ADDR) & ~((uint32_t)0x00700000)) | ((uint32_t)tbuser7startingsts <<20));
}
__INLINE uint8_t mpu_common_tb_user_7_cfg_1_tb_user_7_coding_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_7_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00080000)) >> 19);
}
__INLINE void mpu_common_tb_user_7_cfg_1_tb_user_7_coding_type_setf(uint8_t tbuser7codingtype)
{
	ASSERT_ERR((((uint32_t)tbuser7codingtype << 19) & ~((uint32_t)0x00080000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_7_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_7_CFG_1_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)tbuser7codingtype <<19));
}
__INLINE uint8_t mpu_common_tb_user_7_cfg_1_tb_user_7_ru_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_7_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00070000)) >> 16);
}
__INLINE void mpu_common_tb_user_7_cfg_1_tb_user_7_ru_type_setf(uint8_t tbuser7rutype)
{
	ASSERT_ERR((((uint32_t)tbuser7rutype << 16) & ~((uint32_t)0x00070000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_7_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_7_CFG_1_ADDR) & ~((uint32_t)0x00070000)) | ((uint32_t)tbuser7rutype <<16));
}
__INLINE uint8_t mpu_common_tb_user_7_cfg_1_tb_user_7_ru_band_mac_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_7_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void mpu_common_tb_user_7_cfg_1_tb_user_7_ru_band_mac_setf(uint8_t tbuser7rubandmac)
{
	ASSERT_ERR((((uint32_t)tbuser7rubandmac << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_7_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_7_CFG_1_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)tbuser7rubandmac <<14));
}
__INLINE uint8_t mpu_common_tb_user_7_cfg_1_tb_user_7_ru_index_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_7_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00003F00)) >> 8);
}
__INLINE void mpu_common_tb_user_7_cfg_1_tb_user_7_ru_index_setf(uint8_t tbuser7ruindex)
{
	ASSERT_ERR((((uint32_t)tbuser7ruindex << 8) & ~((uint32_t)0x00003F00)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_7_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_7_CFG_1_ADDR) & ~((uint32_t)0x00003F00)) | ((uint32_t)tbuser7ruindex <<8));
}
__INLINE uint8_t mpu_common_tb_user_7_cfg_1_tb_user_7_ru_allocation_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_7_CFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void mpu_common_tb_user_7_cfg_1_tb_user_7_ru_allocation_setf(uint8_t tbuser7ruallocation)
{
	ASSERT_ERR((((uint32_t)tbuser7ruallocation << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_7_CFG_1_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_7_CFG_1_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)tbuser7ruallocation <<0));
}

/**
 * @brief TB_USER_7_CFG_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    14:08 TB_USER7_TARGET_RSSI      0x0
 *    07:05 TB_USER7_RESERVED         0x0
 *    04    TB_USER7_DCM              0              
 *    03:00 TB_USER7_MCS              0x0
 * </pre>
 */
#define MPU_COMMON_TB_USER_7_CFG_2_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000144)
#define MPU_COMMON_TB_USER_7_CFG_2_OFFSET      0x00000144
#define MPU_COMMON_TB_USER_7_CFG_2_INDEX       0x00000051
#define MPU_COMMON_TB_USER_7_CFG_2_RESET       0x00000000

__INLINE uint32_t  mpu_common_tb_user_7_cfg_2_get(void)
{
	return REG_PL_RD(MPU_COMMON_TB_USER_7_CFG_2_ADDR);
}

__INLINE void mpu_common_tb_user_7_cfg_2_set(uint32_t value)
{
	REG_PL_WR(MPU_COMMON_TB_USER_7_CFG_2_ADDR, value);
}

// field definitions
#define MPU_COMMON_TB_USER_7_CFG_2_TB_USER_7_TARGET_RSSI_MASK    ((uint32_t)0x00007F00)
#define MPU_COMMON_TB_USER_7_CFG_2_TB_USER_7_TARGET_RSSI_LSB    8
#define MPU_COMMON_TB_USER_7_CFG_2_TB_USER_7_TARGET_RSSI_WIDTH    ((uint32_t)0x00000007)
#define MPU_COMMON_TB_USER_7_CFG_2_TB_USER_7_RESERVED_MASK    ((uint32_t)0x000000E0)
#define MPU_COMMON_TB_USER_7_CFG_2_TB_USER_7_RESERVED_LSB    5
#define MPU_COMMON_TB_USER_7_CFG_2_TB_USER_7_RESERVED_WIDTH    ((uint32_t)0x00000003)
#define MPU_COMMON_TB_USER_7_CFG_2_TB_USER_7_DCM_BIT    ((uint32_t)0x00000010)
#define MPU_COMMON_TB_USER_7_CFG_2_TB_USER_7_DCM_POS    4
#define MPU_COMMON_TB_USER_7_CFG_2_TB_USER_7_MCS_MASK    ((uint32_t)0x0000000F)
#define MPU_COMMON_TB_USER_7_CFG_2_TB_USER_7_MCS_LSB    0
#define MPU_COMMON_TB_USER_7_CFG_2_TB_USER_7_MCS_WIDTH    ((uint32_t)0x00000004)

#define MPU_COMMON_TB_USER_7_CFG_2_TB_USER_7_TARGET_RSSI_RST    0x0
#define MPU_COMMON_TB_USER_7_CFG_2_TB_USER_7_RESERVED_RST    0x0
#define MPU_COMMON_TB_USER_7_CFG_2_TB_USER_7_DCM_RST    0x0
#define MPU_COMMON_TB_USER_7_CFG_2_TB_USER_7_MCS_RST    0x0

__INLINE void mpu_common_tb_user_7_cfg_2_pack(uint8_t tb_user7_target_rssi, uint8_t tb_user7_reserved, uint8_t tb_user7_dcm, uint8_t tb_user7_mcs)
{
	ASSERT_ERR((((uint32_t)tb_user7_target_rssi << 8) & ~((uint32_t)0x00007F00)) == 0);
	ASSERT_ERR((((uint32_t)tb_user7_reserved << 5) & ~((uint32_t)0x000000E0)) == 0);
	ASSERT_ERR((((uint32_t)tb_user7_dcm << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)tb_user7_mcs << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_7_CFG_2_ADDR,  ((uint32_t)tb_user7_target_rssi << 8) |((uint32_t)tb_user7_reserved << 5) |((uint32_t)tb_user7_dcm << 4) |((uint32_t)tb_user7_mcs << 0));
}

__INLINE void mpu_common_tb_user_7_cfg_2_unpack(uint8_t* tb_user7_target_rssi, uint8_t* tb_user7_reserved, uint8_t* tb_user7_dcm, uint8_t* tb_user7_mcs)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_7_CFG_2_ADDR);

	*tb_user7_target_rssi = (localVal & ((uint32_t)0x00007F00)) >>  8;
	*tb_user7_reserved = (localVal & ((uint32_t)0x000000E0)) >>  5;
	*tb_user7_dcm = (localVal & ((uint32_t)0x00000010)) >>  4;
	*tb_user7_mcs = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t mpu_common_tb_user_7_cfg_2_tb_user_7_target_rssi_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_7_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007F00)) >> 8);
}
__INLINE void mpu_common_tb_user_7_cfg_2_tb_user_7_target_rssi_setf(uint8_t tbuser7targetrssi)
{
	ASSERT_ERR((((uint32_t)tbuser7targetrssi << 8) & ~((uint32_t)0x00007F00)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_7_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_7_CFG_2_ADDR) & ~((uint32_t)0x00007F00)) | ((uint32_t)tbuser7targetrssi <<8));
}
__INLINE uint8_t mpu_common_tb_user_7_cfg_2_tb_user_7_reserved_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_7_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000E0)) >> 5);
}
__INLINE void mpu_common_tb_user_7_cfg_2_tb_user_7_reserved_setf(uint8_t tbuser7reserved)
{
	ASSERT_ERR((((uint32_t)tbuser7reserved << 5) & ~((uint32_t)0x000000E0)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_7_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_7_CFG_2_ADDR) & ~((uint32_t)0x000000E0)) | ((uint32_t)tbuser7reserved <<5));
}
__INLINE uint8_t mpu_common_tb_user_7_cfg_2_tb_user_7_dcm_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_7_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void mpu_common_tb_user_7_cfg_2_tb_user_7_dcm_setf(uint8_t tbuser7dcm)
{
	ASSERT_ERR((((uint32_t)tbuser7dcm << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_7_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_7_CFG_2_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)tbuser7dcm <<4));
}
__INLINE uint8_t mpu_common_tb_user_7_cfg_2_tb_user_7_mcs_getf(void)
{
	uint32_t localVal = REG_PL_RD(MPU_COMMON_TB_USER_7_CFG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void mpu_common_tb_user_7_cfg_2_tb_user_7_mcs_setf(uint8_t tbuser7mcs)
{
	ASSERT_ERR((((uint32_t)tbuser7mcs << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(MPU_COMMON_TB_USER_7_CFG_2_ADDR, (REG_PL_RD(MPU_COMMON_TB_USER_7_CFG_2_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)tbuser7mcs <<0));
}
/**
 * @brief SIGB_CC_1 register definition
 *  512 memory size
 * </pre>
 */
#define MPU_COMMON_SIGB_CC_1_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000200)
#define MPU_COMMON_SIGB_CC_1_OFFSET      0x00000200
#define MPU_COMMON_SIGB_CC_1_SIZE        0x00000200
#define MPU_COMMON_SIGB_CC_1_END_ADDR    (MPU_COMMON_SIGB_CC_1_ADDR + MPU_COMMON_SIGB_CC_1_SIZE - 1)
/**
 * @brief SIGB_CC_2 register definition
 *  512 memory size
 * </pre>
 */
#define MPU_COMMON_SIGB_CC_2_ADDR        (REG_MPU_COMMON_BASE_ADDR+0x00000400)
#define MPU_COMMON_SIGB_CC_2_OFFSET      0x00000400
#define MPU_COMMON_SIGB_CC_2_SIZE        0x00000200
#define MPU_COMMON_SIGB_CC_2_END_ADDR    (MPU_COMMON_SIGB_CC_2_ADDR + MPU_COMMON_SIGB_CC_2_SIZE - 1)


#undef DBG_FILEID
#endif //_REG_MPU_COMMON_H_

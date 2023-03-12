#ifndef _REG_RXM_H_
#define _REG_RXM_H_

#include <stdint.h>
#include "_reg_rxm.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define DBG_FILEID __REG_RXM__H__FILEID__

#define REG_RXM_COUNT  204


/**
 * @brief RXM_SW_RST register definition
 *  Reset RXM register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    SW_RST                    0              
 * </pre>
 */
#define RXM_RXM_SW_RST_ADDR        (REG_RXM_BASE_ADDR+0x00000000)
#define RXM_RXM_SW_RST_OFFSET      0x00000000
#define RXM_RXM_SW_RST_INDEX       0x00000000
#define RXM_RXM_SW_RST_RESET       0x00000000

__INLINE void rxm_rxm_sw_rst_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_SW_RST_ADDR, value);
}

// field definitions
#define RXM_RXM_SW_RST_SW_RST_BIT           ((uint32_t)0x00000001)
#define RXM_RXM_SW_RST_SW_RST_POS           0

#define RXM_RXM_SW_RST_SW_RST_RST           0x0

__INLINE void rxm_rxm_sw_rst_sw_rst_setf(uint8_t swrst)
{
	ASSERT_ERR((((uint32_t)swrst << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RXM_RXM_SW_RST_ADDR, (uint32_t)swrst << 0);
}

/**
 * @brief RXM_MODES register definition
 *  General RXM modes register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    10    W2_E_NO_STRIP             0              
 *    09    W2_E_CONV_EN              0              
 *    08    SMALL_MPDU_DE_AGG_DIS     0              
 *    07    DRA_EN                    0              
 *    06    RXM_STOP                  0              
 *    05    MSDU_TRUNCATE             0              
 *    04    LLI_NEXT_MODE             0              
 *    03    SW_ACTIVATION_EN          0              
 *    02    DE_AGG_EN                 0              
 *    01    HB_MODE                   0              
 *    00    RXM_EN                    0              
 * </pre>
 */
#define RXM_RXM_MODES_ADDR        (REG_RXM_BASE_ADDR+0x00000004)
#define RXM_RXM_MODES_OFFSET      0x00000004
#define RXM_RXM_MODES_INDEX       0x00000001
#define RXM_RXM_MODES_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_modes_get(void)
{
	return REG_PL_RD(RXM_RXM_MODES_ADDR);
}

__INLINE void rxm_rxm_modes_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_MODES_ADDR, value);
}

// field definitions
#define RXM_RXM_MODES_W_2_E_NO_STRIP_BIT    ((uint32_t)0x00000400)
#define RXM_RXM_MODES_W_2_E_NO_STRIP_POS    10
#define RXM_RXM_MODES_W_2_E_CONV_EN_BIT     ((uint32_t)0x00000200)
#define RXM_RXM_MODES_W_2_E_CONV_EN_POS     9
#define RXM_RXM_MODES_SMALL_MPDU_DE_AGG_DIS_BIT    ((uint32_t)0x00000100)
#define RXM_RXM_MODES_SMALL_MPDU_DE_AGG_DIS_POS    8
#define RXM_RXM_MODES_DRA_EN_BIT            ((uint32_t)0x00000080)
#define RXM_RXM_MODES_DRA_EN_POS            7
#define RXM_RXM_MODES_RXM_STOP_BIT          ((uint32_t)0x00000040)
#define RXM_RXM_MODES_RXM_STOP_POS          6
#define RXM_RXM_MODES_MSDU_TRUNCATE_BIT     ((uint32_t)0x00000020)
#define RXM_RXM_MODES_MSDU_TRUNCATE_POS     5
#define RXM_RXM_MODES_LLI_NEXT_MODE_BIT     ((uint32_t)0x00000010)
#define RXM_RXM_MODES_LLI_NEXT_MODE_POS     4
#define RXM_RXM_MODES_SW_ACTIVATION_EN_BIT    ((uint32_t)0x00000008)
#define RXM_RXM_MODES_SW_ACTIVATION_EN_POS    3
#define RXM_RXM_MODES_DE_AGG_EN_BIT         ((uint32_t)0x00000004)
#define RXM_RXM_MODES_DE_AGG_EN_POS         2
#define RXM_RXM_MODES_HB_MODE_BIT           ((uint32_t)0x00000002)
#define RXM_RXM_MODES_HB_MODE_POS           1
#define RXM_RXM_MODES_RXM_EN_BIT            ((uint32_t)0x00000001)
#define RXM_RXM_MODES_RXM_EN_POS            0

#define RXM_RXM_MODES_W_2_E_NO_STRIP_RST    0x0
#define RXM_RXM_MODES_W_2_E_CONV_EN_RST     0x0
#define RXM_RXM_MODES_SMALL_MPDU_DE_AGG_DIS_RST    0x0
#define RXM_RXM_MODES_DRA_EN_RST            0x0
#define RXM_RXM_MODES_RXM_STOP_RST          0x0
#define RXM_RXM_MODES_MSDU_TRUNCATE_RST     0x0
#define RXM_RXM_MODES_LLI_NEXT_MODE_RST     0x0
#define RXM_RXM_MODES_SW_ACTIVATION_EN_RST    0x0
#define RXM_RXM_MODES_DE_AGG_EN_RST         0x0
#define RXM_RXM_MODES_HB_MODE_RST           0x0
#define RXM_RXM_MODES_RXM_EN_RST            0x0

__INLINE void rxm_rxm_modes_pack(uint8_t w2_e_no_strip, uint8_t w2_e_conv_en, uint8_t small_mpdu_de_agg_dis, uint8_t dra_en, uint8_t rxm_stop, uint8_t msdu_truncate, uint8_t lli_next_mode, uint8_t sw_activation_en, uint8_t de_agg_en, uint8_t hb_mode, uint8_t rxm_en)
{
	ASSERT_ERR((((uint32_t)w2_e_no_strip << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)w2_e_conv_en << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)small_mpdu_de_agg_dis << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)dra_en << 7) & ~((uint32_t)0x00000080)) == 0);
	ASSERT_ERR((((uint32_t)rxm_stop << 6) & ~((uint32_t)0x00000040)) == 0);
	ASSERT_ERR((((uint32_t)msdu_truncate << 5) & ~((uint32_t)0x00000020)) == 0);
	ASSERT_ERR((((uint32_t)lli_next_mode << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)sw_activation_en << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)de_agg_en << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)hb_mode << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)rxm_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RXM_RXM_MODES_ADDR,  ((uint32_t)w2_e_no_strip << 10) |((uint32_t)w2_e_conv_en << 9) |((uint32_t)small_mpdu_de_agg_dis << 8) |((uint32_t)dra_en << 7) |((uint32_t)rxm_stop << 6) |((uint32_t)msdu_truncate << 5) |((uint32_t)lli_next_mode << 4) |((uint32_t)sw_activation_en << 3) |((uint32_t)de_agg_en << 2) |((uint32_t)hb_mode << 1) |((uint32_t)rxm_en << 0));
}

__INLINE void rxm_rxm_modes_unpack(uint8_t* w2_e_no_strip, uint8_t* w2_e_conv_en, uint8_t* small_mpdu_de_agg_dis, uint8_t* dra_en, uint8_t* rxm_stop, uint8_t* msdu_truncate, uint8_t* lli_next_mode, uint8_t* sw_activation_en, uint8_t* de_agg_en, uint8_t* hb_mode, uint8_t* rxm_en)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MODES_ADDR);

	*w2_e_no_strip = (localVal & ((uint32_t)0x00000400)) >>  10;
	*w2_e_conv_en = (localVal & ((uint32_t)0x00000200)) >>  9;
	*small_mpdu_de_agg_dis = (localVal & ((uint32_t)0x00000100)) >>  8;
	*dra_en = (localVal & ((uint32_t)0x00000080)) >>  7;
	*rxm_stop = (localVal & ((uint32_t)0x00000040)) >>  6;
	*msdu_truncate = (localVal & ((uint32_t)0x00000020)) >>  5;
	*lli_next_mode = (localVal & ((uint32_t)0x00000010)) >>  4;
	*sw_activation_en = (localVal & ((uint32_t)0x00000008)) >>  3;
	*de_agg_en = (localVal & ((uint32_t)0x00000004)) >>  2;
	*hb_mode = (localVal & ((uint32_t)0x00000002)) >>  1;
	*rxm_en = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t rxm_rxm_modes_w_2_e_no_strip_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MODES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void rxm_rxm_modes_w_2_e_no_strip_setf(uint8_t w2enostrip)
{
	ASSERT_ERR((((uint32_t)w2enostrip << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(RXM_RXM_MODES_ADDR, (REG_PL_RD(RXM_RXM_MODES_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)w2enostrip <<10));
}
__INLINE uint8_t rxm_rxm_modes_w_2_e_conv_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MODES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void rxm_rxm_modes_w_2_e_conv_en_setf(uint8_t w2econven)
{
	ASSERT_ERR((((uint32_t)w2econven << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(RXM_RXM_MODES_ADDR, (REG_PL_RD(RXM_RXM_MODES_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)w2econven <<9));
}
__INLINE uint8_t rxm_rxm_modes_small_mpdu_de_agg_dis_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MODES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void rxm_rxm_modes_small_mpdu_de_agg_dis_setf(uint8_t smallmpdudeaggdis)
{
	ASSERT_ERR((((uint32_t)smallmpdudeaggdis << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(RXM_RXM_MODES_ADDR, (REG_PL_RD(RXM_RXM_MODES_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)smallmpdudeaggdis <<8));
}
__INLINE uint8_t rxm_rxm_modes_dra_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MODES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE void rxm_rxm_modes_dra_en_setf(uint8_t draen)
{
	ASSERT_ERR((((uint32_t)draen << 7) & ~((uint32_t)0x00000080)) == 0);
	REG_PL_WR(RXM_RXM_MODES_ADDR, (REG_PL_RD(RXM_RXM_MODES_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)draen <<7));
}
__INLINE uint8_t rxm_rxm_modes_rxm_stop_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MODES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE void rxm_rxm_modes_rxm_stop_setf(uint8_t rxmstop)
{
	ASSERT_ERR((((uint32_t)rxmstop << 6) & ~((uint32_t)0x00000040)) == 0);
	REG_PL_WR(RXM_RXM_MODES_ADDR, (REG_PL_RD(RXM_RXM_MODES_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)rxmstop <<6));
}
__INLINE uint8_t rxm_rxm_modes_msdu_truncate_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MODES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE void rxm_rxm_modes_msdu_truncate_setf(uint8_t msdutruncate)
{
	ASSERT_ERR((((uint32_t)msdutruncate << 5) & ~((uint32_t)0x00000020)) == 0);
	REG_PL_WR(RXM_RXM_MODES_ADDR, (REG_PL_RD(RXM_RXM_MODES_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)msdutruncate <<5));
}
__INLINE uint8_t rxm_rxm_modes_lli_next_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MODES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void rxm_rxm_modes_lli_next_mode_setf(uint8_t llinextmode)
{
	ASSERT_ERR((((uint32_t)llinextmode << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(RXM_RXM_MODES_ADDR, (REG_PL_RD(RXM_RXM_MODES_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)llinextmode <<4));
}
__INLINE uint8_t rxm_rxm_modes_sw_activation_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MODES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void rxm_rxm_modes_sw_activation_en_setf(uint8_t swactivationen)
{
	ASSERT_ERR((((uint32_t)swactivationen << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(RXM_RXM_MODES_ADDR, (REG_PL_RD(RXM_RXM_MODES_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)swactivationen <<3));
}
__INLINE uint8_t rxm_rxm_modes_de_agg_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MODES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void rxm_rxm_modes_de_agg_en_setf(uint8_t deaggen)
{
	ASSERT_ERR((((uint32_t)deaggen << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(RXM_RXM_MODES_ADDR, (REG_PL_RD(RXM_RXM_MODES_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)deaggen <<2));
}
__INLINE uint8_t rxm_rxm_modes_hb_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MODES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void rxm_rxm_modes_hb_mode_setf(uint8_t hbmode)
{
	ASSERT_ERR((((uint32_t)hbmode << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(RXM_RXM_MODES_ADDR, (REG_PL_RD(RXM_RXM_MODES_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)hbmode <<1));
}
__INLINE uint8_t rxm_rxm_modes_rxm_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MODES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void rxm_rxm_modes_rxm_en_setf(uint8_t rxmen)
{
	ASSERT_ERR((((uint32_t)rxmen << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RXM_RXM_MODES_ADDR, (REG_PL_RD(RXM_RXM_MODES_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)rxmen <<0));
}

/**
 * @brief RXM_INT_RAWSTAT register definition
 *  Raw interrupt register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    03    ERR                       0              
 *    02    FW_INFO                   0              
 *    01    HBP_ALLOC                 0              
 *    00    HBP_CONSUME               0              
 * </pre>
 */
#define RXM_RXM_INT_RAWSTAT_ADDR        (REG_RXM_BASE_ADDR+0x00000008)
#define RXM_RXM_INT_RAWSTAT_OFFSET      0x00000008
#define RXM_RXM_INT_RAWSTAT_INDEX       0x00000002
#define RXM_RXM_INT_RAWSTAT_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_int_rawstat_get(void)
{
	return REG_PL_RD(RXM_RXM_INT_RAWSTAT_ADDR);
}

// field definitions
#define RXM_RXM_INT_RAWSTAT_ERR_BIT         ((uint32_t)0x00000008)
#define RXM_RXM_INT_RAWSTAT_ERR_POS         3
#define RXM_RXM_INT_RAWSTAT_FW_INFO_BIT     ((uint32_t)0x00000004)
#define RXM_RXM_INT_RAWSTAT_FW_INFO_POS     2
#define RXM_RXM_INT_RAWSTAT_HBP_ALLOC_BIT    ((uint32_t)0x00000002)
#define RXM_RXM_INT_RAWSTAT_HBP_ALLOC_POS    1
#define RXM_RXM_INT_RAWSTAT_HBP_CONSUME_BIT    ((uint32_t)0x00000001)
#define RXM_RXM_INT_RAWSTAT_HBP_CONSUME_POS    0

#define RXM_RXM_INT_RAWSTAT_ERR_RST         0x0
#define RXM_RXM_INT_RAWSTAT_FW_INFO_RST     0x0
#define RXM_RXM_INT_RAWSTAT_HBP_ALLOC_RST    0x0
#define RXM_RXM_INT_RAWSTAT_HBP_CONSUME_RST    0x0

__INLINE void rxm_rxm_int_rawstat_unpack(uint8_t* err, uint8_t* fw_info, uint8_t* hbp_alloc, uint8_t* hbp_consume)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_INT_RAWSTAT_ADDR);

	*err = (localVal & ((uint32_t)0x00000008)) >>  3;
	*fw_info = (localVal & ((uint32_t)0x00000004)) >>  2;
	*hbp_alloc = (localVal & ((uint32_t)0x00000002)) >>  1;
	*hbp_consume = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t rxm_rxm_int_rawstat_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_INT_RAWSTAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE uint8_t rxm_rxm_int_rawstat_fw_info_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_INT_RAWSTAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE uint8_t rxm_rxm_int_rawstat_hbp_alloc_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_INT_RAWSTAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t rxm_rxm_int_rawstat_hbp_consume_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_INT_RAWSTAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief RXM_INT_EN register definition
 *  Interrupt enable register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    03    ERR_EN                    0              
 *    02    FW_INFO_EN                0              
 *    01    HBP_ALLOC_EN              0              
 *    00    HBP_CONSUME_EN            0              
 * </pre>
 */
#define RXM_RXM_INT_EN_ADDR        (REG_RXM_BASE_ADDR+0x0000000C)
#define RXM_RXM_INT_EN_OFFSET      0x0000000C
#define RXM_RXM_INT_EN_INDEX       0x00000003
#define RXM_RXM_INT_EN_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_int_en_get(void)
{
	return REG_PL_RD(RXM_RXM_INT_EN_ADDR);
}

__INLINE void rxm_rxm_int_en_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_INT_EN_ADDR, value);
}

// field definitions
#define RXM_RXM_INT_EN_ERR_EN_BIT           ((uint32_t)0x00000008)
#define RXM_RXM_INT_EN_ERR_EN_POS           3
#define RXM_RXM_INT_EN_FW_INFO_EN_BIT       ((uint32_t)0x00000004)
#define RXM_RXM_INT_EN_FW_INFO_EN_POS       2
#define RXM_RXM_INT_EN_HBP_ALLOC_EN_BIT     ((uint32_t)0x00000002)
#define RXM_RXM_INT_EN_HBP_ALLOC_EN_POS     1
#define RXM_RXM_INT_EN_HBP_CONSUME_EN_BIT    ((uint32_t)0x00000001)
#define RXM_RXM_INT_EN_HBP_CONSUME_EN_POS    0

#define RXM_RXM_INT_EN_ERR_EN_RST           0x0
#define RXM_RXM_INT_EN_FW_INFO_EN_RST       0x0
#define RXM_RXM_INT_EN_HBP_ALLOC_EN_RST     0x0
#define RXM_RXM_INT_EN_HBP_CONSUME_EN_RST    0x0

__INLINE void rxm_rxm_int_en_pack(uint8_t err_en, uint8_t fw_info_en, uint8_t hbp_alloc_en, uint8_t hbp_consume_en)
{
	ASSERT_ERR((((uint32_t)err_en << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)fw_info_en << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)hbp_alloc_en << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)hbp_consume_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RXM_RXM_INT_EN_ADDR,  ((uint32_t)err_en << 3) |((uint32_t)fw_info_en << 2) |((uint32_t)hbp_alloc_en << 1) |((uint32_t)hbp_consume_en << 0));
}

__INLINE void rxm_rxm_int_en_unpack(uint8_t* err_en, uint8_t* fw_info_en, uint8_t* hbp_alloc_en, uint8_t* hbp_consume_en)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_INT_EN_ADDR);

	*err_en = (localVal & ((uint32_t)0x00000008)) >>  3;
	*fw_info_en = (localVal & ((uint32_t)0x00000004)) >>  2;
	*hbp_alloc_en = (localVal & ((uint32_t)0x00000002)) >>  1;
	*hbp_consume_en = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t rxm_rxm_int_en_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void rxm_rxm_int_en_err_en_setf(uint8_t erren)
{
	ASSERT_ERR((((uint32_t)erren << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(RXM_RXM_INT_EN_ADDR, (REG_PL_RD(RXM_RXM_INT_EN_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)erren <<3));
}
__INLINE uint8_t rxm_rxm_int_en_fw_info_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void rxm_rxm_int_en_fw_info_en_setf(uint8_t fwinfoen)
{
	ASSERT_ERR((((uint32_t)fwinfoen << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(RXM_RXM_INT_EN_ADDR, (REG_PL_RD(RXM_RXM_INT_EN_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)fwinfoen <<2));
}
__INLINE uint8_t rxm_rxm_int_en_hbp_alloc_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void rxm_rxm_int_en_hbp_alloc_en_setf(uint8_t hbpallocen)
{
	ASSERT_ERR((((uint32_t)hbpallocen << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(RXM_RXM_INT_EN_ADDR, (REG_PL_RD(RXM_RXM_INT_EN_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)hbpallocen <<1));
}
__INLINE uint8_t rxm_rxm_int_en_hbp_consume_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void rxm_rxm_int_en_hbp_consume_en_setf(uint8_t hbpconsumeen)
{
	ASSERT_ERR((((uint32_t)hbpconsumeen << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RXM_RXM_INT_EN_ADDR, (REG_PL_RD(RXM_RXM_INT_EN_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)hbpconsumeen <<0));
}

/**
 * @brief RXM_INT_STAT register definition
 *  Interrupt after enable register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    03    ERR                       0              
 *    02    FW_INFO                   0              
 *    01    HBP_ALLOC                 0              
 *    00    HBP_CONSUME               0              
 * </pre>
 */
#define RXM_RXM_INT_STAT_ADDR        (REG_RXM_BASE_ADDR+0x00000010)
#define RXM_RXM_INT_STAT_OFFSET      0x00000010
#define RXM_RXM_INT_STAT_INDEX       0x00000004
#define RXM_RXM_INT_STAT_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_int_stat_get(void)
{
	return REG_PL_RD(RXM_RXM_INT_STAT_ADDR);
}

// field definitions
#define RXM_RXM_INT_STAT_ERR_BIT            ((uint32_t)0x00000008)
#define RXM_RXM_INT_STAT_ERR_POS            3
#define RXM_RXM_INT_STAT_FW_INFO_BIT        ((uint32_t)0x00000004)
#define RXM_RXM_INT_STAT_FW_INFO_POS        2
#define RXM_RXM_INT_STAT_HBP_ALLOC_BIT      ((uint32_t)0x00000002)
#define RXM_RXM_INT_STAT_HBP_ALLOC_POS      1
#define RXM_RXM_INT_STAT_HBP_CONSUME_BIT    ((uint32_t)0x00000001)
#define RXM_RXM_INT_STAT_HBP_CONSUME_POS    0

#define RXM_RXM_INT_STAT_ERR_RST            0x0
#define RXM_RXM_INT_STAT_FW_INFO_RST        0x0
#define RXM_RXM_INT_STAT_HBP_ALLOC_RST      0x0
#define RXM_RXM_INT_STAT_HBP_CONSUME_RST    0x0

__INLINE void rxm_rxm_int_stat_unpack(uint8_t* err, uint8_t* fw_info, uint8_t* hbp_alloc, uint8_t* hbp_consume)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_INT_STAT_ADDR);

	*err = (localVal & ((uint32_t)0x00000008)) >>  3;
	*fw_info = (localVal & ((uint32_t)0x00000004)) >>  2;
	*hbp_alloc = (localVal & ((uint32_t)0x00000002)) >>  1;
	*hbp_consume = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t rxm_rxm_int_stat_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE uint8_t rxm_rxm_int_stat_fw_info_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE uint8_t rxm_rxm_int_stat_hbp_alloc_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t rxm_rxm_int_stat_hbp_consume_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief RXM_INT_CLR register definition
 *  Interrupt clear register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    03    ERR_CLR                   0              
 *    02    Spare2                    0              
 *    01    Spare1                    0              
 *    00    HBP_CONSUME_CLR           0              
 * </pre>
 */
#define RXM_RXM_INT_CLR_ADDR        (REG_RXM_BASE_ADDR+0x00000014)
#define RXM_RXM_INT_CLR_OFFSET      0x00000014
#define RXM_RXM_INT_CLR_INDEX       0x00000005
#define RXM_RXM_INT_CLR_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_int_clr_get(void)
{
	return REG_PL_RD(RXM_RXM_INT_CLR_ADDR);
}

__INLINE void rxm_rxm_int_clr_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_INT_CLR_ADDR, value);
}

// field definitions
#define RXM_RXM_INT_CLR_ERR_CLR_BIT         ((uint32_t)0x00000008)
#define RXM_RXM_INT_CLR_ERR_CLR_POS         3
#define RXM_RXM_INT_CLR_SPARE_2_BIT         ((uint32_t)0x00000004)
#define RXM_RXM_INT_CLR_SPARE_2_POS         2
#define RXM_RXM_INT_CLR_SPARE_1_BIT         ((uint32_t)0x00000002)
#define RXM_RXM_INT_CLR_SPARE_1_POS         1
#define RXM_RXM_INT_CLR_HBP_CONSUME_CLR_BIT    ((uint32_t)0x00000001)
#define RXM_RXM_INT_CLR_HBP_CONSUME_CLR_POS    0

#define RXM_RXM_INT_CLR_ERR_CLR_RST         0x0
#define RXM_RXM_INT_CLR_SPARE_2_RST         0x0
#define RXM_RXM_INT_CLR_SPARE_1_RST         0x0
#define RXM_RXM_INT_CLR_HBP_CONSUME_CLR_RST    0x0

__INLINE void rxm_rxm_int_clr_pack(uint8_t err_clr, uint8_t spare2, uint8_t spare1, uint8_t hbp_consume_clr)
{
	ASSERT_ERR((((uint32_t)err_clr << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)spare2 << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)spare1 << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)hbp_consume_clr << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RXM_RXM_INT_CLR_ADDR,  ((uint32_t)err_clr << 3) |((uint32_t)spare2 << 2) |((uint32_t)spare1 << 1) |((uint32_t)hbp_consume_clr << 0));
}

__INLINE void rxm_rxm_int_clr_unpack(uint8_t* err_clr, uint8_t* spare2, uint8_t* spare1, uint8_t* hbp_consume_clr)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_INT_CLR_ADDR);

	*err_clr = (localVal & ((uint32_t)0x00000008)) >>  3;
	*spare2 = (localVal & ((uint32_t)0x00000004)) >>  2;
	*spare1 = (localVal & ((uint32_t)0x00000002)) >>  1;
	*hbp_consume_clr = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE void rxm_rxm_int_clr_err_clr_setf(uint8_t errclr)
{
	ASSERT_ERR((((uint32_t)errclr << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(RXM_RXM_INT_CLR_ADDR, (REG_PL_RD(RXM_RXM_INT_CLR_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)errclr <<3));
}
__INLINE uint8_t rxm_rxm_int_clr_spare_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_INT_CLR_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void rxm_rxm_int_clr_spare_2_setf(uint8_t spare2)
{
	ASSERT_ERR((((uint32_t)spare2 << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(RXM_RXM_INT_CLR_ADDR, (REG_PL_RD(RXM_RXM_INT_CLR_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)spare2 <<2));
}
__INLINE uint8_t rxm_rxm_int_clr_spare_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_INT_CLR_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void rxm_rxm_int_clr_spare_1_setf(uint8_t spare1)
{
	ASSERT_ERR((((uint32_t)spare1 << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(RXM_RXM_INT_CLR_ADDR, (REG_PL_RD(RXM_RXM_INT_CLR_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)spare1 <<1));
}
__INLINE void rxm_rxm_int_clr_hbp_consume_clr_setf(uint8_t hbpconsumeclr)
{
	ASSERT_ERR((((uint32_t)hbpconsumeclr << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RXM_RXM_INT_CLR_ADDR, (REG_PL_RD(RXM_RXM_INT_CLR_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)hbpconsumeclr <<0));
}

/**
 * @brief RXM_INT_FORCE register definition
 *  Force interrupt for debug register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    03    ERR_FORCE                 0              
 *    02    FW_INFO_FORCE             0              
 *    01    HBP_ALLOC_FORCE           0              
 *    00    HBP_CONSUME_FORCE         0              
 * </pre>
 */
#define RXM_RXM_INT_FORCE_ADDR        (REG_RXM_BASE_ADDR+0x00000018)
#define RXM_RXM_INT_FORCE_OFFSET      0x00000018
#define RXM_RXM_INT_FORCE_INDEX       0x00000006
#define RXM_RXM_INT_FORCE_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_int_force_get(void)
{
	return REG_PL_RD(RXM_RXM_INT_FORCE_ADDR);
}

__INLINE void rxm_rxm_int_force_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_INT_FORCE_ADDR, value);
}

// field definitions
#define RXM_RXM_INT_FORCE_ERR_FORCE_BIT     ((uint32_t)0x00000008)
#define RXM_RXM_INT_FORCE_ERR_FORCE_POS     3
#define RXM_RXM_INT_FORCE_FW_INFO_FORCE_BIT    ((uint32_t)0x00000004)
#define RXM_RXM_INT_FORCE_FW_INFO_FORCE_POS    2
#define RXM_RXM_INT_FORCE_HBP_ALLOC_FORCE_BIT    ((uint32_t)0x00000002)
#define RXM_RXM_INT_FORCE_HBP_ALLOC_FORCE_POS    1
#define RXM_RXM_INT_FORCE_HBP_CONSUME_FORCE_BIT    ((uint32_t)0x00000001)
#define RXM_RXM_INT_FORCE_HBP_CONSUME_FORCE_POS    0

#define RXM_RXM_INT_FORCE_ERR_FORCE_RST     0x0
#define RXM_RXM_INT_FORCE_FW_INFO_FORCE_RST    0x0
#define RXM_RXM_INT_FORCE_HBP_ALLOC_FORCE_RST    0x0
#define RXM_RXM_INT_FORCE_HBP_CONSUME_FORCE_RST    0x0

__INLINE void rxm_rxm_int_force_pack(uint8_t err_force, uint8_t fw_info_force, uint8_t hbp_alloc_force, uint8_t hbp_consume_force)
{
	ASSERT_ERR((((uint32_t)err_force << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)fw_info_force << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)hbp_alloc_force << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)hbp_consume_force << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RXM_RXM_INT_FORCE_ADDR,  ((uint32_t)err_force << 3) |((uint32_t)fw_info_force << 2) |((uint32_t)hbp_alloc_force << 1) |((uint32_t)hbp_consume_force << 0));
}

__INLINE void rxm_rxm_int_force_unpack(uint8_t* err_force, uint8_t* fw_info_force, uint8_t* hbp_alloc_force, uint8_t* hbp_consume_force)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_INT_FORCE_ADDR);

	*err_force = (localVal & ((uint32_t)0x00000008)) >>  3;
	*fw_info_force = (localVal & ((uint32_t)0x00000004)) >>  2;
	*hbp_alloc_force = (localVal & ((uint32_t)0x00000002)) >>  1;
	*hbp_consume_force = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t rxm_rxm_int_force_err_force_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_INT_FORCE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void rxm_rxm_int_force_err_force_setf(uint8_t errforce)
{
	ASSERT_ERR((((uint32_t)errforce << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(RXM_RXM_INT_FORCE_ADDR, (REG_PL_RD(RXM_RXM_INT_FORCE_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)errforce <<3));
}
__INLINE uint8_t rxm_rxm_int_force_fw_info_force_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_INT_FORCE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void rxm_rxm_int_force_fw_info_force_setf(uint8_t fwinfoforce)
{
	ASSERT_ERR((((uint32_t)fwinfoforce << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(RXM_RXM_INT_FORCE_ADDR, (REG_PL_RD(RXM_RXM_INT_FORCE_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)fwinfoforce <<2));
}
__INLINE uint8_t rxm_rxm_int_force_hbp_alloc_force_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_INT_FORCE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void rxm_rxm_int_force_hbp_alloc_force_setf(uint8_t hbpallocforce)
{
	ASSERT_ERR((((uint32_t)hbpallocforce << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(RXM_RXM_INT_FORCE_ADDR, (REG_PL_RD(RXM_RXM_INT_FORCE_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)hbpallocforce <<1));
}
__INLINE uint8_t rxm_rxm_int_force_hbp_consume_force_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_INT_FORCE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void rxm_rxm_int_force_hbp_consume_force_setf(uint8_t hbpconsumeforce)
{
	ASSERT_ERR((((uint32_t)hbpconsumeforce << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RXM_RXM_INT_FORCE_ADDR, (REG_PL_RD(RXM_RXM_INT_FORCE_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)hbpconsumeforce <<0));
}

/**
 * @brief RXM_ERR_STAT register definition
 *  Error status register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    05    AXI_RD_ERR                0              
 *    04    DATA_BUFFER_MISMATCH_ERR  0              
 *    03    RPD_LAST_NOT_FOUND_ERR    0              
 *    02    RHD_FIRST_RPD_PTR_ERR     0              
 *    01    RPD_UNIQUE_PATTERN_ERR    0              
 *    00    RHD_UNIQUE_PATTERN_ERR    0              
 * </pre>
 */
#define RXM_RXM_ERR_STAT_ADDR        (REG_RXM_BASE_ADDR+0x0000001C)
#define RXM_RXM_ERR_STAT_OFFSET      0x0000001C
#define RXM_RXM_ERR_STAT_INDEX       0x00000007
#define RXM_RXM_ERR_STAT_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_err_stat_get(void)
{
	return REG_PL_RD(RXM_RXM_ERR_STAT_ADDR);
}

// field definitions
#define RXM_RXM_ERR_STAT_AXI_RD_ERR_BIT     ((uint32_t)0x00000020)
#define RXM_RXM_ERR_STAT_AXI_RD_ERR_POS     5
#define RXM_RXM_ERR_STAT_DATA_BUFFER_MISMATCH_ERR_BIT    ((uint32_t)0x00000010)
#define RXM_RXM_ERR_STAT_DATA_BUFFER_MISMATCH_ERR_POS    4
#define RXM_RXM_ERR_STAT_RPD_LAST_NOT_FOUND_ERR_BIT    ((uint32_t)0x00000008)
#define RXM_RXM_ERR_STAT_RPD_LAST_NOT_FOUND_ERR_POS    3
#define RXM_RXM_ERR_STAT_RHD_FIRST_RPD_PTR_ERR_BIT    ((uint32_t)0x00000004)
#define RXM_RXM_ERR_STAT_RHD_FIRST_RPD_PTR_ERR_POS    2
#define RXM_RXM_ERR_STAT_RPD_UNIQUE_PATTERN_ERR_BIT    ((uint32_t)0x00000002)
#define RXM_RXM_ERR_STAT_RPD_UNIQUE_PATTERN_ERR_POS    1
#define RXM_RXM_ERR_STAT_RHD_UNIQUE_PATTERN_ERR_BIT    ((uint32_t)0x00000001)
#define RXM_RXM_ERR_STAT_RHD_UNIQUE_PATTERN_ERR_POS    0

#define RXM_RXM_ERR_STAT_AXI_RD_ERR_RST     0x0
#define RXM_RXM_ERR_STAT_DATA_BUFFER_MISMATCH_ERR_RST    0x0
#define RXM_RXM_ERR_STAT_RPD_LAST_NOT_FOUND_ERR_RST    0x0
#define RXM_RXM_ERR_STAT_RHD_FIRST_RPD_PTR_ERR_RST    0x0
#define RXM_RXM_ERR_STAT_RPD_UNIQUE_PATTERN_ERR_RST    0x0
#define RXM_RXM_ERR_STAT_RHD_UNIQUE_PATTERN_ERR_RST    0x0

__INLINE void rxm_rxm_err_stat_unpack(uint8_t* axi_rd_err, uint8_t* data_buffer_mismatch_err, uint8_t* rpd_last_not_found_err, uint8_t* rhd_first_rpd_ptr_err, uint8_t* rpd_unique_pattern_err, uint8_t* rhd_unique_pattern_err)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_ERR_STAT_ADDR);

	*axi_rd_err = (localVal & ((uint32_t)0x00000020)) >>  5;
	*data_buffer_mismatch_err = (localVal & ((uint32_t)0x00000010)) >>  4;
	*rpd_last_not_found_err = (localVal & ((uint32_t)0x00000008)) >>  3;
	*rhd_first_rpd_ptr_err = (localVal & ((uint32_t)0x00000004)) >>  2;
	*rpd_unique_pattern_err = (localVal & ((uint32_t)0x00000002)) >>  1;
	*rhd_unique_pattern_err = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t rxm_rxm_err_stat_axi_rd_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_ERR_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE uint8_t rxm_rxm_err_stat_data_buffer_mismatch_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_ERR_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE uint8_t rxm_rxm_err_stat_rpd_last_not_found_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_ERR_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE uint8_t rxm_rxm_err_stat_rhd_first_rpd_ptr_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_ERR_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE uint8_t rxm_rxm_err_stat_rpd_unique_pattern_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_ERR_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t rxm_rxm_err_stat_rhd_unique_pattern_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_ERR_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief RXM_MACHW_RX_MPDU_COUNT_ADDR register definition
 *  MACHW 0 rx MPDU count register address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 MACHW_RX_MPDU_COUNT_ADDR  0x0
 * </pre>
 */
#define RXM_RXM_MACHW_RX_MPDU_COUNT_ADDR_ADDR        (REG_RXM_BASE_ADDR+0x0000002C)
#define RXM_RXM_MACHW_RX_MPDU_COUNT_ADDR_OFFSET      0x0000002C
#define RXM_RXM_MACHW_RX_MPDU_COUNT_ADDR_INDEX       0x0000000B
#define RXM_RXM_MACHW_RX_MPDU_COUNT_ADDR_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_machw_rx_mpdu_count_addr_get(void)
{
	return REG_PL_RD(RXM_RXM_MACHW_RX_MPDU_COUNT_ADDR_ADDR);
}

__INLINE void rxm_rxm_machw_rx_mpdu_count_addr_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_MACHW_RX_MPDU_COUNT_ADDR_ADDR, value);
}

// field definitions
#define RXM_RXM_MACHW_RX_MPDU_COUNT_ADDR_MACHW_RX_MPDU_COUNT_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_MACHW_RX_MPDU_COUNT_ADDR_MACHW_RX_MPDU_COUNT_ADDR_LSB    0
#define RXM_RXM_MACHW_RX_MPDU_COUNT_ADDR_MACHW_RX_MPDU_COUNT_ADDR_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_MACHW_RX_MPDU_COUNT_ADDR_MACHW_RX_MPDU_COUNT_ADDR_RST    0x0

__INLINE uint32_t rxm_rxm_machw_rx_mpdu_count_addr_machw_rx_mpdu_count_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MACHW_RX_MPDU_COUNT_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_machw_rx_mpdu_count_addr_machw_rx_mpdu_count_addr_setf(uint32_t machwrxmpducountaddr)
{
	ASSERT_ERR((((uint32_t)machwrxmpducountaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_MACHW_RX_MPDU_COUNT_ADDR_ADDR, (uint32_t)machwrxmpducountaddr << 0);
}

/**
 * @brief RXM_MAC_0_RHD_ADDR_INIT register definition
 *  Init MACHW stream RHD address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RHD_ADDR_INIT             0x0
 * </pre>
 */
#define RXM_RXM_MAC_0_RHD_ADDR_INIT_ADDR        (REG_RXM_BASE_ADDR+0x00000030)
#define RXM_RXM_MAC_0_RHD_ADDR_INIT_OFFSET      0x00000030
#define RXM_RXM_MAC_0_RHD_ADDR_INIT_INDEX       0x0000000C
#define RXM_RXM_MAC_0_RHD_ADDR_INIT_RESET       0x00000000

__INLINE void rxm_rxm_mac_0_rhd_addr_init_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_MAC_0_RHD_ADDR_INIT_ADDR, value);
}

// field definitions
#define RXM_RXM_MAC_0_RHD_ADDR_INIT_RHD_ADDR_INIT_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_MAC_0_RHD_ADDR_INIT_RHD_ADDR_INIT_LSB    0
#define RXM_RXM_MAC_0_RHD_ADDR_INIT_RHD_ADDR_INIT_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_MAC_0_RHD_ADDR_INIT_RHD_ADDR_INIT_RST    0x0

__INLINE void rxm_rxm_mac_0_rhd_addr_init_rhd_addr_init_setf(uint32_t rhdaddrinit)
{
	ASSERT_ERR((((uint32_t)rhdaddrinit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_MAC_0_RHD_ADDR_INIT_ADDR, (uint32_t)rhdaddrinit << 0);
}

/**
 * @brief RXM_MAC_1_RHD_ADDR_INIT register definition
 *  Init MACHW stream RHD address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RHD_ADDR_INIT             0x0
 * </pre>
 */
#define RXM_RXM_MAC_1_RHD_ADDR_INIT_ADDR        (REG_RXM_BASE_ADDR+0x00000034)
#define RXM_RXM_MAC_1_RHD_ADDR_INIT_OFFSET      0x00000034
#define RXM_RXM_MAC_1_RHD_ADDR_INIT_INDEX       0x0000000D
#define RXM_RXM_MAC_1_RHD_ADDR_INIT_RESET       0x00000000

__INLINE void rxm_rxm_mac_1_rhd_addr_init_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_MAC_1_RHD_ADDR_INIT_ADDR, value);
}

// field definitions
#define RXM_RXM_MAC_1_RHD_ADDR_INIT_RHD_ADDR_INIT_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_MAC_1_RHD_ADDR_INIT_RHD_ADDR_INIT_LSB    0
#define RXM_RXM_MAC_1_RHD_ADDR_INIT_RHD_ADDR_INIT_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_MAC_1_RHD_ADDR_INIT_RHD_ADDR_INIT_RST    0x0

__INLINE void rxm_rxm_mac_1_rhd_addr_init_rhd_addr_init_setf(uint32_t rhdaddrinit)
{
	ASSERT_ERR((((uint32_t)rhdaddrinit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_MAC_1_RHD_ADDR_INIT_ADDR, (uint32_t)rhdaddrinit << 0);
}

/**
 * @brief RXM_MAC_2_RHD_ADDR_INIT register definition
 *  Init MACHW stream RHD address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RHD_ADDR_INIT             0x0
 * </pre>
 */
#define RXM_RXM_MAC_2_RHD_ADDR_INIT_ADDR        (REG_RXM_BASE_ADDR+0x00000038)
#define RXM_RXM_MAC_2_RHD_ADDR_INIT_OFFSET      0x00000038
#define RXM_RXM_MAC_2_RHD_ADDR_INIT_INDEX       0x0000000E
#define RXM_RXM_MAC_2_RHD_ADDR_INIT_RESET       0x00000000

__INLINE void rxm_rxm_mac_2_rhd_addr_init_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_MAC_2_RHD_ADDR_INIT_ADDR, value);
}

// field definitions
#define RXM_RXM_MAC_2_RHD_ADDR_INIT_RHD_ADDR_INIT_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_MAC_2_RHD_ADDR_INIT_RHD_ADDR_INIT_LSB    0
#define RXM_RXM_MAC_2_RHD_ADDR_INIT_RHD_ADDR_INIT_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_MAC_2_RHD_ADDR_INIT_RHD_ADDR_INIT_RST    0x0

__INLINE void rxm_rxm_mac_2_rhd_addr_init_rhd_addr_init_setf(uint32_t rhdaddrinit)
{
	ASSERT_ERR((((uint32_t)rhdaddrinit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_MAC_2_RHD_ADDR_INIT_ADDR, (uint32_t)rhdaddrinit << 0);
}

/**
 * @brief RXM_MAC_3_RHD_ADDR_INIT register definition
 *  Init MACHW stream RHD address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RHD_ADDR_INIT             0x0
 * </pre>
 */
#define RXM_RXM_MAC_3_RHD_ADDR_INIT_ADDR        (REG_RXM_BASE_ADDR+0x0000003C)
#define RXM_RXM_MAC_3_RHD_ADDR_INIT_OFFSET      0x0000003C
#define RXM_RXM_MAC_3_RHD_ADDR_INIT_INDEX       0x0000000F
#define RXM_RXM_MAC_3_RHD_ADDR_INIT_RESET       0x00000000

__INLINE void rxm_rxm_mac_3_rhd_addr_init_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_MAC_3_RHD_ADDR_INIT_ADDR, value);
}

// field definitions
#define RXM_RXM_MAC_3_RHD_ADDR_INIT_RHD_ADDR_INIT_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_MAC_3_RHD_ADDR_INIT_RHD_ADDR_INIT_LSB    0
#define RXM_RXM_MAC_3_RHD_ADDR_INIT_RHD_ADDR_INIT_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_MAC_3_RHD_ADDR_INIT_RHD_ADDR_INIT_RST    0x0

__INLINE void rxm_rxm_mac_3_rhd_addr_init_rhd_addr_init_setf(uint32_t rhdaddrinit)
{
	ASSERT_ERR((((uint32_t)rhdaddrinit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_MAC_3_RHD_ADDR_INIT_ADDR, (uint32_t)rhdaddrinit << 0);
}

/**
 * @brief RXM_MAC_4_RHD_ADDR_INIT register definition
 *  Init MACHW stream RHD address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RHD_ADDR_INIT             0x0
 * </pre>
 */
#define RXM_RXM_MAC_4_RHD_ADDR_INIT_ADDR        (REG_RXM_BASE_ADDR+0x00000040)
#define RXM_RXM_MAC_4_RHD_ADDR_INIT_OFFSET      0x00000040
#define RXM_RXM_MAC_4_RHD_ADDR_INIT_INDEX       0x00000010
#define RXM_RXM_MAC_4_RHD_ADDR_INIT_RESET       0x00000000

__INLINE void rxm_rxm_mac_4_rhd_addr_init_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_MAC_4_RHD_ADDR_INIT_ADDR, value);
}

// field definitions
#define RXM_RXM_MAC_4_RHD_ADDR_INIT_RHD_ADDR_INIT_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_MAC_4_RHD_ADDR_INIT_RHD_ADDR_INIT_LSB    0
#define RXM_RXM_MAC_4_RHD_ADDR_INIT_RHD_ADDR_INIT_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_MAC_4_RHD_ADDR_INIT_RHD_ADDR_INIT_RST    0x0

__INLINE void rxm_rxm_mac_4_rhd_addr_init_rhd_addr_init_setf(uint32_t rhdaddrinit)
{
	ASSERT_ERR((((uint32_t)rhdaddrinit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_MAC_4_RHD_ADDR_INIT_ADDR, (uint32_t)rhdaddrinit << 0);
}

/**
 * @brief RXM_MAC_5_RHD_ADDR_INIT register definition
 *  Init MACHW stream RHD address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RHD_ADDR_INIT             0x0
 * </pre>
 */
#define RXM_RXM_MAC_5_RHD_ADDR_INIT_ADDR        (REG_RXM_BASE_ADDR+0x00000044)
#define RXM_RXM_MAC_5_RHD_ADDR_INIT_OFFSET      0x00000044
#define RXM_RXM_MAC_5_RHD_ADDR_INIT_INDEX       0x00000011
#define RXM_RXM_MAC_5_RHD_ADDR_INIT_RESET       0x00000000

__INLINE void rxm_rxm_mac_5_rhd_addr_init_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_MAC_5_RHD_ADDR_INIT_ADDR, value);
}

// field definitions
#define RXM_RXM_MAC_5_RHD_ADDR_INIT_RHD_ADDR_INIT_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_MAC_5_RHD_ADDR_INIT_RHD_ADDR_INIT_LSB    0
#define RXM_RXM_MAC_5_RHD_ADDR_INIT_RHD_ADDR_INIT_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_MAC_5_RHD_ADDR_INIT_RHD_ADDR_INIT_RST    0x0

__INLINE void rxm_rxm_mac_5_rhd_addr_init_rhd_addr_init_setf(uint32_t rhdaddrinit)
{
	ASSERT_ERR((((uint32_t)rhdaddrinit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_MAC_5_RHD_ADDR_INIT_ADDR, (uint32_t)rhdaddrinit << 0);
}

/**
 * @brief RXM_MAC_6_RHD_ADDR_INIT register definition
 *  Init MACHW stream RHD address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RHD_ADDR_INIT             0x0
 * </pre>
 */
#define RXM_RXM_MAC_6_RHD_ADDR_INIT_ADDR        (REG_RXM_BASE_ADDR+0x00000048)
#define RXM_RXM_MAC_6_RHD_ADDR_INIT_OFFSET      0x00000048
#define RXM_RXM_MAC_6_RHD_ADDR_INIT_INDEX       0x00000012
#define RXM_RXM_MAC_6_RHD_ADDR_INIT_RESET       0x00000000

__INLINE void rxm_rxm_mac_6_rhd_addr_init_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_MAC_6_RHD_ADDR_INIT_ADDR, value);
}

// field definitions
#define RXM_RXM_MAC_6_RHD_ADDR_INIT_RHD_ADDR_INIT_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_MAC_6_RHD_ADDR_INIT_RHD_ADDR_INIT_LSB    0
#define RXM_RXM_MAC_6_RHD_ADDR_INIT_RHD_ADDR_INIT_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_MAC_6_RHD_ADDR_INIT_RHD_ADDR_INIT_RST    0x0

__INLINE void rxm_rxm_mac_6_rhd_addr_init_rhd_addr_init_setf(uint32_t rhdaddrinit)
{
	ASSERT_ERR((((uint32_t)rhdaddrinit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_MAC_6_RHD_ADDR_INIT_ADDR, (uint32_t)rhdaddrinit << 0);
}

/**
 * @brief RXM_MAC_7_RHD_ADDR_INIT register definition
 *  Init MACHW stream RHD address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RHD_ADDR_INIT             0x0
 * </pre>
 */
#define RXM_RXM_MAC_7_RHD_ADDR_INIT_ADDR        (REG_RXM_BASE_ADDR+0x0000004C)
#define RXM_RXM_MAC_7_RHD_ADDR_INIT_OFFSET      0x0000004C
#define RXM_RXM_MAC_7_RHD_ADDR_INIT_INDEX       0x00000013
#define RXM_RXM_MAC_7_RHD_ADDR_INIT_RESET       0x00000000

__INLINE void rxm_rxm_mac_7_rhd_addr_init_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_MAC_7_RHD_ADDR_INIT_ADDR, value);
}

// field definitions
#define RXM_RXM_MAC_7_RHD_ADDR_INIT_RHD_ADDR_INIT_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_MAC_7_RHD_ADDR_INIT_RHD_ADDR_INIT_LSB    0
#define RXM_RXM_MAC_7_RHD_ADDR_INIT_RHD_ADDR_INIT_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_MAC_7_RHD_ADDR_INIT_RHD_ADDR_INIT_RST    0x0

__INLINE void rxm_rxm_mac_7_rhd_addr_init_rhd_addr_init_setf(uint32_t rhdaddrinit)
{
	ASSERT_ERR((((uint32_t)rhdaddrinit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_MAC_7_RHD_ADDR_INIT_ADDR, (uint32_t)rhdaddrinit << 0);
}

/**
 * @brief RXM_MAC_8_RHD_ADDR_INIT register definition
 *  Init MACHW stream RHD address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RHD_ADDR_INIT             0x0
 * </pre>
 */
#define RXM_RXM_MAC_8_RHD_ADDR_INIT_ADDR        (REG_RXM_BASE_ADDR+0x00000050)
#define RXM_RXM_MAC_8_RHD_ADDR_INIT_OFFSET      0x00000050
#define RXM_RXM_MAC_8_RHD_ADDR_INIT_INDEX       0x00000014
#define RXM_RXM_MAC_8_RHD_ADDR_INIT_RESET       0x00000000

__INLINE void rxm_rxm_mac_8_rhd_addr_init_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_MAC_8_RHD_ADDR_INIT_ADDR, value);
}

// field definitions
#define RXM_RXM_MAC_8_RHD_ADDR_INIT_RHD_ADDR_INIT_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_MAC_8_RHD_ADDR_INIT_RHD_ADDR_INIT_LSB    0
#define RXM_RXM_MAC_8_RHD_ADDR_INIT_RHD_ADDR_INIT_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_MAC_8_RHD_ADDR_INIT_RHD_ADDR_INIT_RST    0x0

__INLINE void rxm_rxm_mac_8_rhd_addr_init_rhd_addr_init_setf(uint32_t rhdaddrinit)
{
	ASSERT_ERR((((uint32_t)rhdaddrinit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_MAC_8_RHD_ADDR_INIT_ADDR, (uint32_t)rhdaddrinit << 0);
}

/**
 * @brief RXM_MAC_9_RHD_ADDR_INIT register definition
 *  Init MACHW stream RHD address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RHD_ADDR_INIT             0x0
 * </pre>
 */
#define RXM_RXM_MAC_9_RHD_ADDR_INIT_ADDR        (REG_RXM_BASE_ADDR+0x00000054)
#define RXM_RXM_MAC_9_RHD_ADDR_INIT_OFFSET      0x00000054
#define RXM_RXM_MAC_9_RHD_ADDR_INIT_INDEX       0x00000015
#define RXM_RXM_MAC_9_RHD_ADDR_INIT_RESET       0x00000000

__INLINE void rxm_rxm_mac_9_rhd_addr_init_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_MAC_9_RHD_ADDR_INIT_ADDR, value);
}

// field definitions
#define RXM_RXM_MAC_9_RHD_ADDR_INIT_RHD_ADDR_INIT_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_MAC_9_RHD_ADDR_INIT_RHD_ADDR_INIT_LSB    0
#define RXM_RXM_MAC_9_RHD_ADDR_INIT_RHD_ADDR_INIT_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_MAC_9_RHD_ADDR_INIT_RHD_ADDR_INIT_RST    0x0

__INLINE void rxm_rxm_mac_9_rhd_addr_init_rhd_addr_init_setf(uint32_t rhdaddrinit)
{
	ASSERT_ERR((((uint32_t)rhdaddrinit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_MAC_9_RHD_ADDR_INIT_ADDR, (uint32_t)rhdaddrinit << 0);
}

/**
 * @brief RXM_MAC_10_RHD_ADDR_INIT register definition
 *  Init MACHW stream RHD address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RHD_ADDR_INIT             0x0
 * </pre>
 */
#define RXM_RXM_MAC_10_RHD_ADDR_INIT_ADDR        (REG_RXM_BASE_ADDR+0x00000058)
#define RXM_RXM_MAC_10_RHD_ADDR_INIT_OFFSET      0x00000058
#define RXM_RXM_MAC_10_RHD_ADDR_INIT_INDEX       0x00000016
#define RXM_RXM_MAC_10_RHD_ADDR_INIT_RESET       0x00000000

__INLINE void rxm_rxm_mac_10_rhd_addr_init_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_MAC_10_RHD_ADDR_INIT_ADDR, value);
}

// field definitions
#define RXM_RXM_MAC_10_RHD_ADDR_INIT_RHD_ADDR_INIT_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_MAC_10_RHD_ADDR_INIT_RHD_ADDR_INIT_LSB    0
#define RXM_RXM_MAC_10_RHD_ADDR_INIT_RHD_ADDR_INIT_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_MAC_10_RHD_ADDR_INIT_RHD_ADDR_INIT_RST    0x0

__INLINE void rxm_rxm_mac_10_rhd_addr_init_rhd_addr_init_setf(uint32_t rhdaddrinit)
{
	ASSERT_ERR((((uint32_t)rhdaddrinit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_MAC_10_RHD_ADDR_INIT_ADDR, (uint32_t)rhdaddrinit << 0);
}

/**
 * @brief RXM_MAC_11_RHD_ADDR_INIT register definition
 *  Init MACHW stream RHD address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RHD_ADDR_INIT             0x0
 * </pre>
 */
#define RXM_RXM_MAC_11_RHD_ADDR_INIT_ADDR        (REG_RXM_BASE_ADDR+0x0000005C)
#define RXM_RXM_MAC_11_RHD_ADDR_INIT_OFFSET      0x0000005C
#define RXM_RXM_MAC_11_RHD_ADDR_INIT_INDEX       0x00000017
#define RXM_RXM_MAC_11_RHD_ADDR_INIT_RESET       0x00000000

__INLINE void rxm_rxm_mac_11_rhd_addr_init_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_MAC_11_RHD_ADDR_INIT_ADDR, value);
}

// field definitions
#define RXM_RXM_MAC_11_RHD_ADDR_INIT_RHD_ADDR_INIT_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_MAC_11_RHD_ADDR_INIT_RHD_ADDR_INIT_LSB    0
#define RXM_RXM_MAC_11_RHD_ADDR_INIT_RHD_ADDR_INIT_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_MAC_11_RHD_ADDR_INIT_RHD_ADDR_INIT_RST    0x0

__INLINE void rxm_rxm_mac_11_rhd_addr_init_rhd_addr_init_setf(uint32_t rhdaddrinit)
{
	ASSERT_ERR((((uint32_t)rhdaddrinit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_MAC_11_RHD_ADDR_INIT_ADDR, (uint32_t)rhdaddrinit << 0);
}

/**
 * @brief RXM_MAC_12_RHD_ADDR_INIT register definition
 *  Init MACHW stream RHD address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RHD_ADDR_INIT             0x0
 * </pre>
 */
#define RXM_RXM_MAC_12_RHD_ADDR_INIT_ADDR        (REG_RXM_BASE_ADDR+0x00000060)
#define RXM_RXM_MAC_12_RHD_ADDR_INIT_OFFSET      0x00000060
#define RXM_RXM_MAC_12_RHD_ADDR_INIT_INDEX       0x00000018
#define RXM_RXM_MAC_12_RHD_ADDR_INIT_RESET       0x00000000

__INLINE void rxm_rxm_mac_12_rhd_addr_init_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_MAC_12_RHD_ADDR_INIT_ADDR, value);
}

// field definitions
#define RXM_RXM_MAC_12_RHD_ADDR_INIT_RHD_ADDR_INIT_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_MAC_12_RHD_ADDR_INIT_RHD_ADDR_INIT_LSB    0
#define RXM_RXM_MAC_12_RHD_ADDR_INIT_RHD_ADDR_INIT_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_MAC_12_RHD_ADDR_INIT_RHD_ADDR_INIT_RST    0x0

__INLINE void rxm_rxm_mac_12_rhd_addr_init_rhd_addr_init_setf(uint32_t rhdaddrinit)
{
	ASSERT_ERR((((uint32_t)rhdaddrinit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_MAC_12_RHD_ADDR_INIT_ADDR, (uint32_t)rhdaddrinit << 0);
}

/**
 * @brief RXM_MAC_13_RHD_ADDR_INIT register definition
 *  Init MACHW stream RHD address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RHD_ADDR_INIT             0x0
 * </pre>
 */
#define RXM_RXM_MAC_13_RHD_ADDR_INIT_ADDR        (REG_RXM_BASE_ADDR+0x00000064)
#define RXM_RXM_MAC_13_RHD_ADDR_INIT_OFFSET      0x00000064
#define RXM_RXM_MAC_13_RHD_ADDR_INIT_INDEX       0x00000019
#define RXM_RXM_MAC_13_RHD_ADDR_INIT_RESET       0x00000000

__INLINE void rxm_rxm_mac_13_rhd_addr_init_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_MAC_13_RHD_ADDR_INIT_ADDR, value);
}

// field definitions
#define RXM_RXM_MAC_13_RHD_ADDR_INIT_RHD_ADDR_INIT_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_MAC_13_RHD_ADDR_INIT_RHD_ADDR_INIT_LSB    0
#define RXM_RXM_MAC_13_RHD_ADDR_INIT_RHD_ADDR_INIT_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_MAC_13_RHD_ADDR_INIT_RHD_ADDR_INIT_RST    0x0

__INLINE void rxm_rxm_mac_13_rhd_addr_init_rhd_addr_init_setf(uint32_t rhdaddrinit)
{
	ASSERT_ERR((((uint32_t)rhdaddrinit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_MAC_13_RHD_ADDR_INIT_ADDR, (uint32_t)rhdaddrinit << 0);
}

/**
 * @brief RXM_MAC_14_RHD_ADDR_INIT register definition
 *  Init MACHW stream RHD address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RHD_ADDR_INIT             0x0
 * </pre>
 */
#define RXM_RXM_MAC_14_RHD_ADDR_INIT_ADDR        (REG_RXM_BASE_ADDR+0x00000068)
#define RXM_RXM_MAC_14_RHD_ADDR_INIT_OFFSET      0x00000068
#define RXM_RXM_MAC_14_RHD_ADDR_INIT_INDEX       0x0000001A
#define RXM_RXM_MAC_14_RHD_ADDR_INIT_RESET       0x00000000

__INLINE void rxm_rxm_mac_14_rhd_addr_init_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_MAC_14_RHD_ADDR_INIT_ADDR, value);
}

// field definitions
#define RXM_RXM_MAC_14_RHD_ADDR_INIT_RHD_ADDR_INIT_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_MAC_14_RHD_ADDR_INIT_RHD_ADDR_INIT_LSB    0
#define RXM_RXM_MAC_14_RHD_ADDR_INIT_RHD_ADDR_INIT_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_MAC_14_RHD_ADDR_INIT_RHD_ADDR_INIT_RST    0x0

__INLINE void rxm_rxm_mac_14_rhd_addr_init_rhd_addr_init_setf(uint32_t rhdaddrinit)
{
	ASSERT_ERR((((uint32_t)rhdaddrinit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_MAC_14_RHD_ADDR_INIT_ADDR, (uint32_t)rhdaddrinit << 0);
}

/**
 * @brief RXM_MAC_15_RHD_ADDR_INIT register definition
 *  Init MACHW stream RHD address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RHD_ADDR_INIT             0x0
 * </pre>
 */
#define RXM_RXM_MAC_15_RHD_ADDR_INIT_ADDR        (REG_RXM_BASE_ADDR+0x0000006C)
#define RXM_RXM_MAC_15_RHD_ADDR_INIT_OFFSET      0x0000006C
#define RXM_RXM_MAC_15_RHD_ADDR_INIT_INDEX       0x0000001B
#define RXM_RXM_MAC_15_RHD_ADDR_INIT_RESET       0x00000000

__INLINE void rxm_rxm_mac_15_rhd_addr_init_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_MAC_15_RHD_ADDR_INIT_ADDR, value);
}

// field definitions
#define RXM_RXM_MAC_15_RHD_ADDR_INIT_RHD_ADDR_INIT_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_MAC_15_RHD_ADDR_INIT_RHD_ADDR_INIT_LSB    0
#define RXM_RXM_MAC_15_RHD_ADDR_INIT_RHD_ADDR_INIT_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_MAC_15_RHD_ADDR_INIT_RHD_ADDR_INIT_RST    0x0

__INLINE void rxm_rxm_mac_15_rhd_addr_init_rhd_addr_init_setf(uint32_t rhdaddrinit)
{
	ASSERT_ERR((((uint32_t)rhdaddrinit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_MAC_15_RHD_ADDR_INIT_ADDR, (uint32_t)rhdaddrinit << 0);
}

/**
 * @brief RXM_MAC_0_RHD_ADDR register definition
 *  Current MAC stream RHD address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RHD_ADDR                  0x0
 * </pre>
 */
#define RXM_RXM_MAC_0_RHD_ADDR_ADDR        (REG_RXM_BASE_ADDR+0x00000070)
#define RXM_RXM_MAC_0_RHD_ADDR_OFFSET      0x00000070
#define RXM_RXM_MAC_0_RHD_ADDR_INDEX       0x0000001C
#define RXM_RXM_MAC_0_RHD_ADDR_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_mac_0_rhd_addr_get(void)
{
	return REG_PL_RD(RXM_RXM_MAC_0_RHD_ADDR_ADDR);
}

// field definitions
#define RXM_RXM_MAC_0_RHD_ADDR_RHD_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_MAC_0_RHD_ADDR_RHD_ADDR_LSB    0
#define RXM_RXM_MAC_0_RHD_ADDR_RHD_ADDR_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_MAC_0_RHD_ADDR_RHD_ADDR_RST    0x0

__INLINE uint32_t rxm_rxm_mac_0_rhd_addr_rhd_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MAC_0_RHD_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RXM_MAC_1_RHD_ADDR register definition
 *  Current MAC stream RHD address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RHD_ADDR                  0x0
 * </pre>
 */
#define RXM_RXM_MAC_1_RHD_ADDR_ADDR        (REG_RXM_BASE_ADDR+0x00000074)
#define RXM_RXM_MAC_1_RHD_ADDR_OFFSET      0x00000074
#define RXM_RXM_MAC_1_RHD_ADDR_INDEX       0x0000001D
#define RXM_RXM_MAC_1_RHD_ADDR_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_mac_1_rhd_addr_get(void)
{
	return REG_PL_RD(RXM_RXM_MAC_1_RHD_ADDR_ADDR);
}

// field definitions
#define RXM_RXM_MAC_1_RHD_ADDR_RHD_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_MAC_1_RHD_ADDR_RHD_ADDR_LSB    0
#define RXM_RXM_MAC_1_RHD_ADDR_RHD_ADDR_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_MAC_1_RHD_ADDR_RHD_ADDR_RST    0x0

__INLINE uint32_t rxm_rxm_mac_1_rhd_addr_rhd_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MAC_1_RHD_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RXM_MAC_2_RHD_ADDR register definition
 *  Current MAC stream RHD address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RHD_ADDR                  0x0
 * </pre>
 */
#define RXM_RXM_MAC_2_RHD_ADDR_ADDR        (REG_RXM_BASE_ADDR+0x00000078)
#define RXM_RXM_MAC_2_RHD_ADDR_OFFSET      0x00000078
#define RXM_RXM_MAC_2_RHD_ADDR_INDEX       0x0000001E
#define RXM_RXM_MAC_2_RHD_ADDR_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_mac_2_rhd_addr_get(void)
{
	return REG_PL_RD(RXM_RXM_MAC_2_RHD_ADDR_ADDR);
}

// field definitions
#define RXM_RXM_MAC_2_RHD_ADDR_RHD_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_MAC_2_RHD_ADDR_RHD_ADDR_LSB    0
#define RXM_RXM_MAC_2_RHD_ADDR_RHD_ADDR_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_MAC_2_RHD_ADDR_RHD_ADDR_RST    0x0

__INLINE uint32_t rxm_rxm_mac_2_rhd_addr_rhd_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MAC_2_RHD_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RXM_MAC_3_RHD_ADDR register definition
 *  Current MAC stream RHD address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RHD_ADDR                  0x0
 * </pre>
 */
#define RXM_RXM_MAC_3_RHD_ADDR_ADDR        (REG_RXM_BASE_ADDR+0x0000007C)
#define RXM_RXM_MAC_3_RHD_ADDR_OFFSET      0x0000007C
#define RXM_RXM_MAC_3_RHD_ADDR_INDEX       0x0000001F
#define RXM_RXM_MAC_3_RHD_ADDR_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_mac_3_rhd_addr_get(void)
{
	return REG_PL_RD(RXM_RXM_MAC_3_RHD_ADDR_ADDR);
}

// field definitions
#define RXM_RXM_MAC_3_RHD_ADDR_RHD_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_MAC_3_RHD_ADDR_RHD_ADDR_LSB    0
#define RXM_RXM_MAC_3_RHD_ADDR_RHD_ADDR_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_MAC_3_RHD_ADDR_RHD_ADDR_RST    0x0

__INLINE uint32_t rxm_rxm_mac_3_rhd_addr_rhd_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MAC_3_RHD_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RXM_MAC_4_RHD_ADDR register definition
 *  Current MAC stream RHD address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RHD_ADDR                  0x0
 * </pre>
 */
#define RXM_RXM_MAC_4_RHD_ADDR_ADDR        (REG_RXM_BASE_ADDR+0x00000080)
#define RXM_RXM_MAC_4_RHD_ADDR_OFFSET      0x00000080
#define RXM_RXM_MAC_4_RHD_ADDR_INDEX       0x00000020
#define RXM_RXM_MAC_4_RHD_ADDR_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_mac_4_rhd_addr_get(void)
{
	return REG_PL_RD(RXM_RXM_MAC_4_RHD_ADDR_ADDR);
}

// field definitions
#define RXM_RXM_MAC_4_RHD_ADDR_RHD_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_MAC_4_RHD_ADDR_RHD_ADDR_LSB    0
#define RXM_RXM_MAC_4_RHD_ADDR_RHD_ADDR_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_MAC_4_RHD_ADDR_RHD_ADDR_RST    0x0

__INLINE uint32_t rxm_rxm_mac_4_rhd_addr_rhd_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MAC_4_RHD_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RXM_MAC_5_RHD_ADDR register definition
 *  Current MAC stream RHD address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RHD_ADDR                  0x0
 * </pre>
 */
#define RXM_RXM_MAC_5_RHD_ADDR_ADDR        (REG_RXM_BASE_ADDR+0x00000084)
#define RXM_RXM_MAC_5_RHD_ADDR_OFFSET      0x00000084
#define RXM_RXM_MAC_5_RHD_ADDR_INDEX       0x00000021
#define RXM_RXM_MAC_5_RHD_ADDR_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_mac_5_rhd_addr_get(void)
{
	return REG_PL_RD(RXM_RXM_MAC_5_RHD_ADDR_ADDR);
}

// field definitions
#define RXM_RXM_MAC_5_RHD_ADDR_RHD_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_MAC_5_RHD_ADDR_RHD_ADDR_LSB    0
#define RXM_RXM_MAC_5_RHD_ADDR_RHD_ADDR_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_MAC_5_RHD_ADDR_RHD_ADDR_RST    0x0

__INLINE uint32_t rxm_rxm_mac_5_rhd_addr_rhd_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MAC_5_RHD_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RXM_MAC_6_RHD_ADDR register definition
 *  Current MAC stream RHD address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RHD_ADDR                  0x0
 * </pre>
 */
#define RXM_RXM_MAC_6_RHD_ADDR_ADDR        (REG_RXM_BASE_ADDR+0x00000088)
#define RXM_RXM_MAC_6_RHD_ADDR_OFFSET      0x00000088
#define RXM_RXM_MAC_6_RHD_ADDR_INDEX       0x00000022
#define RXM_RXM_MAC_6_RHD_ADDR_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_mac_6_rhd_addr_get(void)
{
	return REG_PL_RD(RXM_RXM_MAC_6_RHD_ADDR_ADDR);
}

// field definitions
#define RXM_RXM_MAC_6_RHD_ADDR_RHD_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_MAC_6_RHD_ADDR_RHD_ADDR_LSB    0
#define RXM_RXM_MAC_6_RHD_ADDR_RHD_ADDR_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_MAC_6_RHD_ADDR_RHD_ADDR_RST    0x0

__INLINE uint32_t rxm_rxm_mac_6_rhd_addr_rhd_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MAC_6_RHD_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RXM_MAC_7_RHD_ADDR register definition
 *  Current MAC stream RHD address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RHD_ADDR                  0x0
 * </pre>
 */
#define RXM_RXM_MAC_7_RHD_ADDR_ADDR        (REG_RXM_BASE_ADDR+0x0000008C)
#define RXM_RXM_MAC_7_RHD_ADDR_OFFSET      0x0000008C
#define RXM_RXM_MAC_7_RHD_ADDR_INDEX       0x00000023
#define RXM_RXM_MAC_7_RHD_ADDR_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_mac_7_rhd_addr_get(void)
{
	return REG_PL_RD(RXM_RXM_MAC_7_RHD_ADDR_ADDR);
}

// field definitions
#define RXM_RXM_MAC_7_RHD_ADDR_RHD_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_MAC_7_RHD_ADDR_RHD_ADDR_LSB    0
#define RXM_RXM_MAC_7_RHD_ADDR_RHD_ADDR_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_MAC_7_RHD_ADDR_RHD_ADDR_RST    0x0

__INLINE uint32_t rxm_rxm_mac_7_rhd_addr_rhd_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MAC_7_RHD_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RXM_MAC_8_RHD_ADDR register definition
 *  Current MAC stream RHD address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RHD_ADDR                  0x0
 * </pre>
 */
#define RXM_RXM_MAC_8_RHD_ADDR_ADDR        (REG_RXM_BASE_ADDR+0x00000090)
#define RXM_RXM_MAC_8_RHD_ADDR_OFFSET      0x00000090
#define RXM_RXM_MAC_8_RHD_ADDR_INDEX       0x00000024
#define RXM_RXM_MAC_8_RHD_ADDR_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_mac_8_rhd_addr_get(void)
{
	return REG_PL_RD(RXM_RXM_MAC_8_RHD_ADDR_ADDR);
}

// field definitions
#define RXM_RXM_MAC_8_RHD_ADDR_RHD_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_MAC_8_RHD_ADDR_RHD_ADDR_LSB    0
#define RXM_RXM_MAC_8_RHD_ADDR_RHD_ADDR_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_MAC_8_RHD_ADDR_RHD_ADDR_RST    0x0

__INLINE uint32_t rxm_rxm_mac_8_rhd_addr_rhd_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MAC_8_RHD_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RXM_MAC_9_RHD_ADDR register definition
 *  Current MAC stream RHD address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RHD_ADDR                  0x0
 * </pre>
 */
#define RXM_RXM_MAC_9_RHD_ADDR_ADDR        (REG_RXM_BASE_ADDR+0x00000094)
#define RXM_RXM_MAC_9_RHD_ADDR_OFFSET      0x00000094
#define RXM_RXM_MAC_9_RHD_ADDR_INDEX       0x00000025
#define RXM_RXM_MAC_9_RHD_ADDR_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_mac_9_rhd_addr_get(void)
{
	return REG_PL_RD(RXM_RXM_MAC_9_RHD_ADDR_ADDR);
}

// field definitions
#define RXM_RXM_MAC_9_RHD_ADDR_RHD_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_MAC_9_RHD_ADDR_RHD_ADDR_LSB    0
#define RXM_RXM_MAC_9_RHD_ADDR_RHD_ADDR_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_MAC_9_RHD_ADDR_RHD_ADDR_RST    0x0

__INLINE uint32_t rxm_rxm_mac_9_rhd_addr_rhd_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MAC_9_RHD_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RXM_MAC_10_RHD_ADDR register definition
 *  Current MAC stream RHD address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RHD_ADDR                  0x0
 * </pre>
 */
#define RXM_RXM_MAC_10_RHD_ADDR_ADDR        (REG_RXM_BASE_ADDR+0x00000098)
#define RXM_RXM_MAC_10_RHD_ADDR_OFFSET      0x00000098
#define RXM_RXM_MAC_10_RHD_ADDR_INDEX       0x00000026
#define RXM_RXM_MAC_10_RHD_ADDR_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_mac_10_rhd_addr_get(void)
{
	return REG_PL_RD(RXM_RXM_MAC_10_RHD_ADDR_ADDR);
}

// field definitions
#define RXM_RXM_MAC_10_RHD_ADDR_RHD_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_MAC_10_RHD_ADDR_RHD_ADDR_LSB    0
#define RXM_RXM_MAC_10_RHD_ADDR_RHD_ADDR_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_MAC_10_RHD_ADDR_RHD_ADDR_RST    0x0

__INLINE uint32_t rxm_rxm_mac_10_rhd_addr_rhd_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MAC_10_RHD_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RXM_MAC_11_RHD_ADDR register definition
 *  Current MAC stream RHD address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RHD_ADDR                  0x0
 * </pre>
 */
#define RXM_RXM_MAC_11_RHD_ADDR_ADDR        (REG_RXM_BASE_ADDR+0x0000009C)
#define RXM_RXM_MAC_11_RHD_ADDR_OFFSET      0x0000009C
#define RXM_RXM_MAC_11_RHD_ADDR_INDEX       0x00000027
#define RXM_RXM_MAC_11_RHD_ADDR_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_mac_11_rhd_addr_get(void)
{
	return REG_PL_RD(RXM_RXM_MAC_11_RHD_ADDR_ADDR);
}

// field definitions
#define RXM_RXM_MAC_11_RHD_ADDR_RHD_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_MAC_11_RHD_ADDR_RHD_ADDR_LSB    0
#define RXM_RXM_MAC_11_RHD_ADDR_RHD_ADDR_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_MAC_11_RHD_ADDR_RHD_ADDR_RST    0x0

__INLINE uint32_t rxm_rxm_mac_11_rhd_addr_rhd_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MAC_11_RHD_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RXM_MAC_12_RHD_ADDR register definition
 *  Current MAC stream RHD address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RHD_ADDR                  0x0
 * </pre>
 */
#define RXM_RXM_MAC_12_RHD_ADDR_ADDR        (REG_RXM_BASE_ADDR+0x000000A0)
#define RXM_RXM_MAC_12_RHD_ADDR_OFFSET      0x000000A0
#define RXM_RXM_MAC_12_RHD_ADDR_INDEX       0x00000028
#define RXM_RXM_MAC_12_RHD_ADDR_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_mac_12_rhd_addr_get(void)
{
	return REG_PL_RD(RXM_RXM_MAC_12_RHD_ADDR_ADDR);
}

// field definitions
#define RXM_RXM_MAC_12_RHD_ADDR_RHD_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_MAC_12_RHD_ADDR_RHD_ADDR_LSB    0
#define RXM_RXM_MAC_12_RHD_ADDR_RHD_ADDR_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_MAC_12_RHD_ADDR_RHD_ADDR_RST    0x0

__INLINE uint32_t rxm_rxm_mac_12_rhd_addr_rhd_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MAC_12_RHD_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RXM_MAC_13_RHD_ADDR register definition
 *  Current MAC stream RHD address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RHD_ADDR                  0x0
 * </pre>
 */
#define RXM_RXM_MAC_13_RHD_ADDR_ADDR        (REG_RXM_BASE_ADDR+0x000000A4)
#define RXM_RXM_MAC_13_RHD_ADDR_OFFSET      0x000000A4
#define RXM_RXM_MAC_13_RHD_ADDR_INDEX       0x00000029
#define RXM_RXM_MAC_13_RHD_ADDR_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_mac_13_rhd_addr_get(void)
{
	return REG_PL_RD(RXM_RXM_MAC_13_RHD_ADDR_ADDR);
}

// field definitions
#define RXM_RXM_MAC_13_RHD_ADDR_RHD_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_MAC_13_RHD_ADDR_RHD_ADDR_LSB    0
#define RXM_RXM_MAC_13_RHD_ADDR_RHD_ADDR_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_MAC_13_RHD_ADDR_RHD_ADDR_RST    0x0

__INLINE uint32_t rxm_rxm_mac_13_rhd_addr_rhd_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MAC_13_RHD_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RXM_MAC_14_RHD_ADDR register definition
 *  Current MAC stream RHD address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RHD_ADDR                  0x0
 * </pre>
 */
#define RXM_RXM_MAC_14_RHD_ADDR_ADDR        (REG_RXM_BASE_ADDR+0x000000A8)
#define RXM_RXM_MAC_14_RHD_ADDR_OFFSET      0x000000A8
#define RXM_RXM_MAC_14_RHD_ADDR_INDEX       0x0000002A
#define RXM_RXM_MAC_14_RHD_ADDR_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_mac_14_rhd_addr_get(void)
{
	return REG_PL_RD(RXM_RXM_MAC_14_RHD_ADDR_ADDR);
}

// field definitions
#define RXM_RXM_MAC_14_RHD_ADDR_RHD_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_MAC_14_RHD_ADDR_RHD_ADDR_LSB    0
#define RXM_RXM_MAC_14_RHD_ADDR_RHD_ADDR_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_MAC_14_RHD_ADDR_RHD_ADDR_RST    0x0

__INLINE uint32_t rxm_rxm_mac_14_rhd_addr_rhd_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MAC_14_RHD_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RXM_MAC_15_RHD_ADDR register definition
 *  Current MAC stream RHD address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RHD_ADDR                  0x0
 * </pre>
 */
#define RXM_RXM_MAC_15_RHD_ADDR_ADDR        (REG_RXM_BASE_ADDR+0x000000AC)
#define RXM_RXM_MAC_15_RHD_ADDR_OFFSET      0x000000AC
#define RXM_RXM_MAC_15_RHD_ADDR_INDEX       0x0000002B
#define RXM_RXM_MAC_15_RHD_ADDR_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_mac_15_rhd_addr_get(void)
{
	return REG_PL_RD(RXM_RXM_MAC_15_RHD_ADDR_ADDR);
}

// field definitions
#define RXM_RXM_MAC_15_RHD_ADDR_RHD_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_MAC_15_RHD_ADDR_RHD_ADDR_LSB    0
#define RXM_RXM_MAC_15_RHD_ADDR_RHD_ADDR_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_MAC_15_RHD_ADDR_RHD_ADDR_RST    0x0

__INLINE uint32_t rxm_rxm_mac_15_rhd_addr_rhd_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MAC_15_RHD_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RXM_MACHW_INT_CLR_ADDR register definition
 *  MACHW interrupt clear reg address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 MACHW_INT_CLR_ADDR        0x0
 * </pre>
 */
#define RXM_RXM_MACHW_INT_CLR_ADDR_ADDR        (REG_RXM_BASE_ADDR+0x000000B0)
#define RXM_RXM_MACHW_INT_CLR_ADDR_OFFSET      0x000000B0
#define RXM_RXM_MACHW_INT_CLR_ADDR_INDEX       0x0000002C
#define RXM_RXM_MACHW_INT_CLR_ADDR_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_machw_int_clr_addr_get(void)
{
	return REG_PL_RD(RXM_RXM_MACHW_INT_CLR_ADDR_ADDR);
}

__INLINE void rxm_rxm_machw_int_clr_addr_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_MACHW_INT_CLR_ADDR_ADDR, value);
}

// field definitions
#define RXM_RXM_MACHW_INT_CLR_ADDR_MACHW_INT_CLR_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_MACHW_INT_CLR_ADDR_MACHW_INT_CLR_ADDR_LSB    0
#define RXM_RXM_MACHW_INT_CLR_ADDR_MACHW_INT_CLR_ADDR_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_MACHW_INT_CLR_ADDR_MACHW_INT_CLR_ADDR_RST    0x0

__INLINE uint32_t rxm_rxm_machw_int_clr_addr_machw_int_clr_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MACHW_INT_CLR_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_machw_int_clr_addr_machw_int_clr_addr_setf(uint32_t machwintclraddr)
{
	ASSERT_ERR((((uint32_t)machwintclraddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_MACHW_INT_CLR_ADDR_ADDR, (uint32_t)machwintclraddr << 0);
}

/**
 * @brief RXM_MACHW_USER_ADDR_SHIFT register definition
 *  MACHW interrupt clear reg offset register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    04:00 MACHW_USER_ADDR_SHIFT     0x10
 * </pre>
 */
#define RXM_RXM_MACHW_USER_ADDR_SHIFT_ADDR        (REG_RXM_BASE_ADDR+0x000000B4)
#define RXM_RXM_MACHW_USER_ADDR_SHIFT_OFFSET      0x000000B4
#define RXM_RXM_MACHW_USER_ADDR_SHIFT_INDEX       0x0000002D
#define RXM_RXM_MACHW_USER_ADDR_SHIFT_RESET       0x00000010

__INLINE uint32_t  rxm_rxm_machw_user_addr_shift_get(void)
{
	return REG_PL_RD(RXM_RXM_MACHW_USER_ADDR_SHIFT_ADDR);
}

__INLINE void rxm_rxm_machw_user_addr_shift_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_MACHW_USER_ADDR_SHIFT_ADDR, value);
}

// field definitions
#define RXM_RXM_MACHW_USER_ADDR_SHIFT_MACHW_USER_ADDR_SHIFT_MASK    ((uint32_t)0x0000001F)
#define RXM_RXM_MACHW_USER_ADDR_SHIFT_MACHW_USER_ADDR_SHIFT_LSB    0
#define RXM_RXM_MACHW_USER_ADDR_SHIFT_MACHW_USER_ADDR_SHIFT_WIDTH    ((uint32_t)0x00000005)

#define RXM_RXM_MACHW_USER_ADDR_SHIFT_MACHW_USER_ADDR_SHIFT_RST    0x10

__INLINE uint8_t rxm_rxm_machw_user_addr_shift_machw_user_addr_shift_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MACHW_USER_ADDR_SHIFT_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void rxm_rxm_machw_user_addr_shift_machw_user_addr_shift_setf(uint8_t machwuseraddrshift)
{
	ASSERT_ERR((((uint32_t)machwuseraddrshift << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RXM_RXM_MACHW_USER_ADDR_SHIFT_ADDR, (uint32_t)machwuseraddrshift << 0);
}

/**
 * @brief RXM_MACHW_INT_CLR_BMAP register definition
 *  MACHW interrupt clear bit map register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 MACHW_INT_CLR_BMAP        0x10000
 * </pre>
 */
#define RXM_RXM_MACHW_INT_CLR_BMAP_ADDR        (REG_RXM_BASE_ADDR+0x000000B8)
#define RXM_RXM_MACHW_INT_CLR_BMAP_OFFSET      0x000000B8
#define RXM_RXM_MACHW_INT_CLR_BMAP_INDEX       0x0000002E
#define RXM_RXM_MACHW_INT_CLR_BMAP_RESET       0x00010000

__INLINE uint32_t  rxm_rxm_machw_int_clr_bmap_get(void)
{
	return REG_PL_RD(RXM_RXM_MACHW_INT_CLR_BMAP_ADDR);
}

__INLINE void rxm_rxm_machw_int_clr_bmap_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_MACHW_INT_CLR_BMAP_ADDR, value);
}

// field definitions
#define RXM_RXM_MACHW_INT_CLR_BMAP_MACHW_INT_CLR_BMAP_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_MACHW_INT_CLR_BMAP_MACHW_INT_CLR_BMAP_LSB    0
#define RXM_RXM_MACHW_INT_CLR_BMAP_MACHW_INT_CLR_BMAP_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_MACHW_INT_CLR_BMAP_MACHW_INT_CLR_BMAP_RST    0x10000

__INLINE uint32_t rxm_rxm_machw_int_clr_bmap_machw_int_clr_bmap_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MACHW_INT_CLR_BMAP_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_machw_int_clr_bmap_machw_int_clr_bmap_setf(uint32_t machwintclrbmap)
{
	ASSERT_ERR((((uint32_t)machwintclrbmap << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_MACHW_INT_CLR_BMAP_ADDR, (uint32_t)machwintclrbmap << 0);
}

/**
 * @brief RXM_RHD_RETRY_TIMER register definition
 *  RHD retry timer (in clocks)  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    09:00 RHD_RETRY_TIMER           0x1f4
 * </pre>
 */
#define RXM_RXM_RHD_RETRY_TIMER_ADDR        (REG_RXM_BASE_ADDR+0x000000BC)
#define RXM_RXM_RHD_RETRY_TIMER_OFFSET      0x000000BC
#define RXM_RXM_RHD_RETRY_TIMER_INDEX       0x0000002F
#define RXM_RXM_RHD_RETRY_TIMER_RESET       0x000001F4

__INLINE uint32_t  rxm_rxm_rhd_retry_timer_get(void)
{
	return REG_PL_RD(RXM_RXM_RHD_RETRY_TIMER_ADDR);
}

__INLINE void rxm_rxm_rhd_retry_timer_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_RHD_RETRY_TIMER_ADDR, value);
}

// field definitions
#define RXM_RXM_RHD_RETRY_TIMER_RHD_RETRY_TIMER_MASK    ((uint32_t)0x000003FF)
#define RXM_RXM_RHD_RETRY_TIMER_RHD_RETRY_TIMER_LSB    0
#define RXM_RXM_RHD_RETRY_TIMER_RHD_RETRY_TIMER_WIDTH    ((uint32_t)0x0000000A)

#define RXM_RXM_RHD_RETRY_TIMER_RHD_RETRY_TIMER_RST    0x1f4

__INLINE uint16_t rxm_rxm_rhd_retry_timer_rhd_retry_timer_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_RHD_RETRY_TIMER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void rxm_rxm_rhd_retry_timer_rhd_retry_timer_setf(uint16_t rhdretrytimer)
{
	ASSERT_ERR((((uint32_t)rhdretrytimer << 0) & ~((uint32_t)0x000003FF)) == 0);
	REG_PL_WR(RXM_RXM_RHD_RETRY_TIMER_ADDR, (uint32_t)rhdretrytimer << 0);
}

/**
 * @brief RXM_MACSW_TRIG register definition
 *  MACSW trigger register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 MACSW_TRIG                0x0
 * </pre>
 */
#define RXM_RXM_MACSW_TRIG_ADDR        (REG_RXM_BASE_ADDR+0x000000C0)
#define RXM_RXM_MACSW_TRIG_OFFSET      0x000000C0
#define RXM_RXM_MACSW_TRIG_INDEX       0x00000030
#define RXM_RXM_MACSW_TRIG_RESET       0x00000000

__INLINE void rxm_rxm_macsw_trig_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_MACSW_TRIG_ADDR, value);
}

// field definitions
#define RXM_RXM_MACSW_TRIG_MACSW_TRIG_MASK    ((uint32_t)0x0000FFFF)
#define RXM_RXM_MACSW_TRIG_MACSW_TRIG_LSB    0
#define RXM_RXM_MACSW_TRIG_MACSW_TRIG_WIDTH    ((uint32_t)0x00000010)

#define RXM_RXM_MACSW_TRIG_MACSW_TRIG_RST    0x0

__INLINE void rxm_rxm_macsw_trig_macsw_trig_setf(uint16_t macswtrig)
{
	ASSERT_ERR((((uint32_t)macswtrig << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(RXM_RXM_MACSW_TRIG_ADDR, (uint32_t)macswtrig << 0);
}

/**
 * @brief RXM_MACSW_PEND_STAT register definition
 *  MACSW pending status register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 MACSW_PEND_STAT           0x0
 * </pre>
 */
#define RXM_RXM_MACSW_PEND_STAT_ADDR        (REG_RXM_BASE_ADDR+0x000000C4)
#define RXM_RXM_MACSW_PEND_STAT_OFFSET      0x000000C4
#define RXM_RXM_MACSW_PEND_STAT_INDEX       0x00000031
#define RXM_RXM_MACSW_PEND_STAT_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_macsw_pend_stat_get(void)
{
	return REG_PL_RD(RXM_RXM_MACSW_PEND_STAT_ADDR);
}

// field definitions
#define RXM_RXM_MACSW_PEND_STAT_MACSW_PEND_STAT_MASK    ((uint32_t)0x0000FFFF)
#define RXM_RXM_MACSW_PEND_STAT_MACSW_PEND_STAT_LSB    0
#define RXM_RXM_MACSW_PEND_STAT_MACSW_PEND_STAT_WIDTH    ((uint32_t)0x00000010)

#define RXM_RXM_MACSW_PEND_STAT_MACSW_PEND_STAT_RST    0x0

__INLINE uint16_t rxm_rxm_macsw_pend_stat_macsw_pend_stat_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MACSW_PEND_STAT_ADDR);
	return (uint16_t)(localVal >> 0);
}

/**
 * @brief RXM_ARB_SERVING_STAT register definition
 *  Arbiter serving status register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 ARB_SERV_STAT             0x0
 * </pre>
 */
#define RXM_RXM_ARB_SERVING_STAT_ADDR        (REG_RXM_BASE_ADDR+0x000000C8)
#define RXM_RXM_ARB_SERVING_STAT_OFFSET      0x000000C8
#define RXM_RXM_ARB_SERVING_STAT_INDEX       0x00000032
#define RXM_RXM_ARB_SERVING_STAT_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_arb_serving_stat_get(void)
{
	return REG_PL_RD(RXM_RXM_ARB_SERVING_STAT_ADDR);
}

// field definitions
#define RXM_RXM_ARB_SERVING_STAT_ARB_SERV_STAT_MASK    ((uint32_t)0x0000FFFF)
#define RXM_RXM_ARB_SERVING_STAT_ARB_SERV_STAT_LSB    0
#define RXM_RXM_ARB_SERVING_STAT_ARB_SERV_STAT_WIDTH    ((uint32_t)0x00000010)

#define RXM_RXM_ARB_SERVING_STAT_ARB_SERV_STAT_RST    0x0

__INLINE uint16_t rxm_rxm_arb_serving_stat_arb_serv_stat_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_ARB_SERVING_STAT_ADDR);
	return (uint16_t)(localVal >> 0);
}

/**
 * @brief RXM_ARB_RETRY_STAT register definition
 *  Arbiter retry status register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 ARB_RETRY_STAT            0x0
 * </pre>
 */
#define RXM_RXM_ARB_RETRY_STAT_ADDR        (REG_RXM_BASE_ADDR+0x000000CC)
#define RXM_RXM_ARB_RETRY_STAT_OFFSET      0x000000CC
#define RXM_RXM_ARB_RETRY_STAT_INDEX       0x00000033
#define RXM_RXM_ARB_RETRY_STAT_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_arb_retry_stat_get(void)
{
	return REG_PL_RD(RXM_RXM_ARB_RETRY_STAT_ADDR);
}

// field definitions
#define RXM_RXM_ARB_RETRY_STAT_ARB_RETRY_STAT_MASK    ((uint32_t)0x0000FFFF)
#define RXM_RXM_ARB_RETRY_STAT_ARB_RETRY_STAT_LSB    0
#define RXM_RXM_ARB_RETRY_STAT_ARB_RETRY_STAT_WIDTH    ((uint32_t)0x00000010)

#define RXM_RXM_ARB_RETRY_STAT_ARB_RETRY_STAT_RST    0x0

__INLINE uint16_t rxm_rxm_arb_retry_stat_arb_retry_stat_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_ARB_RETRY_STAT_ADDR);
	return (uint16_t)(localVal >> 0);
}

/**
 * @brief RXM_CLS_RULE_0_KEY register definition
 *  Classification key rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SEARCH_KEY                0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_0_KEY_ADDR        (REG_RXM_BASE_ADDR+0x000000D0)
#define RXM_RXM_CLS_RULE_0_KEY_OFFSET      0x000000D0
#define RXM_RXM_CLS_RULE_0_KEY_INDEX       0x00000034
#define RXM_RXM_CLS_RULE_0_KEY_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_0_key_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_0_KEY_ADDR);
}

__INLINE void rxm_rxm_cls_rule_0_key_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_0_KEY_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_0_KEY_SEARCH_KEY_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_CLS_RULE_0_KEY_SEARCH_KEY_LSB    0
#define RXM_RXM_CLS_RULE_0_KEY_SEARCH_KEY_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_CLS_RULE_0_KEY_SEARCH_KEY_RST    0x0

__INLINE uint32_t rxm_rxm_cls_rule_0_key_search_key_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_0_KEY_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_0_key_search_key_setf(uint32_t searchkey)
{
	ASSERT_ERR((((uint32_t)searchkey << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_0_KEY_ADDR, (uint32_t)searchkey << 0);
}

/**
 * @brief RXM_CLS_RULE_0_MASK register definition
 *  Classification mask rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SEARCH_MASK               0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_0_MASK_ADDR        (REG_RXM_BASE_ADDR+0x000000D4)
#define RXM_RXM_CLS_RULE_0_MASK_OFFSET      0x000000D4
#define RXM_RXM_CLS_RULE_0_MASK_INDEX       0x00000035
#define RXM_RXM_CLS_RULE_0_MASK_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_0_mask_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_0_MASK_ADDR);
}

__INLINE void rxm_rxm_cls_rule_0_mask_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_0_MASK_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_0_MASK_SEARCH_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_CLS_RULE_0_MASK_SEARCH_MASK_LSB    0
#define RXM_RXM_CLS_RULE_0_MASK_SEARCH_MASK_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_CLS_RULE_0_MASK_SEARCH_MASK_RST    0x0

__INLINE uint32_t rxm_rxm_cls_rule_0_mask_search_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_0_MASK_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_0_mask_search_mask_setf(uint32_t searchmask)
{
	ASSERT_ERR((((uint32_t)searchmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_0_MASK_ADDR, (uint32_t)searchmask << 0);
}

/**
 * @brief RXM_CLS_RULE_0_ACTION register definition
 *  Classification action rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01:00 ACTION                    0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_0_ACTION_ADDR        (REG_RXM_BASE_ADDR+0x000000D8)
#define RXM_RXM_CLS_RULE_0_ACTION_OFFSET      0x000000D8
#define RXM_RXM_CLS_RULE_0_ACTION_INDEX       0x00000036
#define RXM_RXM_CLS_RULE_0_ACTION_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_0_action_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_0_ACTION_ADDR);
}

__INLINE void rxm_rxm_cls_rule_0_action_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_0_ACTION_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_0_ACTION_ACTION_MASK    ((uint32_t)0x00000003)
#define RXM_RXM_CLS_RULE_0_ACTION_ACTION_LSB    0
#define RXM_RXM_CLS_RULE_0_ACTION_ACTION_WIDTH    ((uint32_t)0x00000002)

#define RXM_RXM_CLS_RULE_0_ACTION_ACTION_RST    0x0

__INLINE uint8_t rxm_rxm_cls_rule_0_action_action_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_0_ACTION_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_0_action_action_setf(uint8_t action)
{
	ASSERT_ERR((((uint32_t)action << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_0_ACTION_ADDR, (uint32_t)action << 0);
}

/**
 * @brief RXM_CLS_RULE_1_KEY register definition
 *  Classification key rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SEARCH_KEY                0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_1_KEY_ADDR        (REG_RXM_BASE_ADDR+0x000000E0)
#define RXM_RXM_CLS_RULE_1_KEY_OFFSET      0x000000E0
#define RXM_RXM_CLS_RULE_1_KEY_INDEX       0x00000038
#define RXM_RXM_CLS_RULE_1_KEY_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_1_key_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_1_KEY_ADDR);
}

__INLINE void rxm_rxm_cls_rule_1_key_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_1_KEY_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_1_KEY_SEARCH_KEY_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_CLS_RULE_1_KEY_SEARCH_KEY_LSB    0
#define RXM_RXM_CLS_RULE_1_KEY_SEARCH_KEY_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_CLS_RULE_1_KEY_SEARCH_KEY_RST    0x0

__INLINE uint32_t rxm_rxm_cls_rule_1_key_search_key_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_1_KEY_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_1_key_search_key_setf(uint32_t searchkey)
{
	ASSERT_ERR((((uint32_t)searchkey << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_1_KEY_ADDR, (uint32_t)searchkey << 0);
}

/**
 * @brief RXM_CLS_RULE_1_MASK register definition
 *  Classification mask rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SEARCH_MASK               0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_1_MASK_ADDR        (REG_RXM_BASE_ADDR+0x000000E4)
#define RXM_RXM_CLS_RULE_1_MASK_OFFSET      0x000000E4
#define RXM_RXM_CLS_RULE_1_MASK_INDEX       0x00000039
#define RXM_RXM_CLS_RULE_1_MASK_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_1_mask_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_1_MASK_ADDR);
}

__INLINE void rxm_rxm_cls_rule_1_mask_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_1_MASK_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_1_MASK_SEARCH_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_CLS_RULE_1_MASK_SEARCH_MASK_LSB    0
#define RXM_RXM_CLS_RULE_1_MASK_SEARCH_MASK_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_CLS_RULE_1_MASK_SEARCH_MASK_RST    0x0

__INLINE uint32_t rxm_rxm_cls_rule_1_mask_search_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_1_MASK_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_1_mask_search_mask_setf(uint32_t searchmask)
{
	ASSERT_ERR((((uint32_t)searchmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_1_MASK_ADDR, (uint32_t)searchmask << 0);
}

/**
 * @brief RXM_CLS_RULE_1_ACTION register definition
 *  Classification action rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01:00 ACTION                    0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_1_ACTION_ADDR        (REG_RXM_BASE_ADDR+0x000000E8)
#define RXM_RXM_CLS_RULE_1_ACTION_OFFSET      0x000000E8
#define RXM_RXM_CLS_RULE_1_ACTION_INDEX       0x0000003A
#define RXM_RXM_CLS_RULE_1_ACTION_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_1_action_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_1_ACTION_ADDR);
}

__INLINE void rxm_rxm_cls_rule_1_action_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_1_ACTION_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_1_ACTION_ACTION_MASK    ((uint32_t)0x00000003)
#define RXM_RXM_CLS_RULE_1_ACTION_ACTION_LSB    0
#define RXM_RXM_CLS_RULE_1_ACTION_ACTION_WIDTH    ((uint32_t)0x00000002)

#define RXM_RXM_CLS_RULE_1_ACTION_ACTION_RST    0x0

__INLINE uint8_t rxm_rxm_cls_rule_1_action_action_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_1_ACTION_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_1_action_action_setf(uint8_t action)
{
	ASSERT_ERR((((uint32_t)action << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_1_ACTION_ADDR, (uint32_t)action << 0);
}

/**
 * @brief RXM_CLS_RULE_2_KEY register definition
 *  Classification key rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SEARCH_KEY                0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_2_KEY_ADDR        (REG_RXM_BASE_ADDR+0x000000F0)
#define RXM_RXM_CLS_RULE_2_KEY_OFFSET      0x000000F0
#define RXM_RXM_CLS_RULE_2_KEY_INDEX       0x0000003C
#define RXM_RXM_CLS_RULE_2_KEY_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_2_key_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_2_KEY_ADDR);
}

__INLINE void rxm_rxm_cls_rule_2_key_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_2_KEY_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_2_KEY_SEARCH_KEY_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_CLS_RULE_2_KEY_SEARCH_KEY_LSB    0
#define RXM_RXM_CLS_RULE_2_KEY_SEARCH_KEY_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_CLS_RULE_2_KEY_SEARCH_KEY_RST    0x0

__INLINE uint32_t rxm_rxm_cls_rule_2_key_search_key_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_2_KEY_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_2_key_search_key_setf(uint32_t searchkey)
{
	ASSERT_ERR((((uint32_t)searchkey << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_2_KEY_ADDR, (uint32_t)searchkey << 0);
}

/**
 * @brief RXM_CLS_RULE_2_MASK register definition
 *  Classification mask rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SEARCH_MASK               0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_2_MASK_ADDR        (REG_RXM_BASE_ADDR+0x000000F4)
#define RXM_RXM_CLS_RULE_2_MASK_OFFSET      0x000000F4
#define RXM_RXM_CLS_RULE_2_MASK_INDEX       0x0000003D
#define RXM_RXM_CLS_RULE_2_MASK_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_2_mask_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_2_MASK_ADDR);
}

__INLINE void rxm_rxm_cls_rule_2_mask_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_2_MASK_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_2_MASK_SEARCH_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_CLS_RULE_2_MASK_SEARCH_MASK_LSB    0
#define RXM_RXM_CLS_RULE_2_MASK_SEARCH_MASK_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_CLS_RULE_2_MASK_SEARCH_MASK_RST    0x0

__INLINE uint32_t rxm_rxm_cls_rule_2_mask_search_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_2_MASK_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_2_mask_search_mask_setf(uint32_t searchmask)
{
	ASSERT_ERR((((uint32_t)searchmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_2_MASK_ADDR, (uint32_t)searchmask << 0);
}

/**
 * @brief RXM_CLS_RULE_2_ACTION register definition
 *  Classification action rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01:00 ACTION                    0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_2_ACTION_ADDR        (REG_RXM_BASE_ADDR+0x000000F8)
#define RXM_RXM_CLS_RULE_2_ACTION_OFFSET      0x000000F8
#define RXM_RXM_CLS_RULE_2_ACTION_INDEX       0x0000003E
#define RXM_RXM_CLS_RULE_2_ACTION_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_2_action_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_2_ACTION_ADDR);
}

__INLINE void rxm_rxm_cls_rule_2_action_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_2_ACTION_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_2_ACTION_ACTION_MASK    ((uint32_t)0x00000003)
#define RXM_RXM_CLS_RULE_2_ACTION_ACTION_LSB    0
#define RXM_RXM_CLS_RULE_2_ACTION_ACTION_WIDTH    ((uint32_t)0x00000002)

#define RXM_RXM_CLS_RULE_2_ACTION_ACTION_RST    0x0

__INLINE uint8_t rxm_rxm_cls_rule_2_action_action_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_2_ACTION_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_2_action_action_setf(uint8_t action)
{
	ASSERT_ERR((((uint32_t)action << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_2_ACTION_ADDR, (uint32_t)action << 0);
}

/**
 * @brief RXM_CLS_RULE_3_KEY register definition
 *  Classification key rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SEARCH_KEY                0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_3_KEY_ADDR        (REG_RXM_BASE_ADDR+0x00000100)
#define RXM_RXM_CLS_RULE_3_KEY_OFFSET      0x00000100
#define RXM_RXM_CLS_RULE_3_KEY_INDEX       0x00000040
#define RXM_RXM_CLS_RULE_3_KEY_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_3_key_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_3_KEY_ADDR);
}

__INLINE void rxm_rxm_cls_rule_3_key_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_3_KEY_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_3_KEY_SEARCH_KEY_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_CLS_RULE_3_KEY_SEARCH_KEY_LSB    0
#define RXM_RXM_CLS_RULE_3_KEY_SEARCH_KEY_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_CLS_RULE_3_KEY_SEARCH_KEY_RST    0x0

__INLINE uint32_t rxm_rxm_cls_rule_3_key_search_key_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_3_KEY_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_3_key_search_key_setf(uint32_t searchkey)
{
	ASSERT_ERR((((uint32_t)searchkey << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_3_KEY_ADDR, (uint32_t)searchkey << 0);
}

/**
 * @brief RXM_CLS_RULE_3_MASK register definition
 *  Classification mask rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SEARCH_MASK               0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_3_MASK_ADDR        (REG_RXM_BASE_ADDR+0x00000104)
#define RXM_RXM_CLS_RULE_3_MASK_OFFSET      0x00000104
#define RXM_RXM_CLS_RULE_3_MASK_INDEX       0x00000041
#define RXM_RXM_CLS_RULE_3_MASK_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_3_mask_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_3_MASK_ADDR);
}

__INLINE void rxm_rxm_cls_rule_3_mask_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_3_MASK_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_3_MASK_SEARCH_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_CLS_RULE_3_MASK_SEARCH_MASK_LSB    0
#define RXM_RXM_CLS_RULE_3_MASK_SEARCH_MASK_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_CLS_RULE_3_MASK_SEARCH_MASK_RST    0x0

__INLINE uint32_t rxm_rxm_cls_rule_3_mask_search_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_3_MASK_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_3_mask_search_mask_setf(uint32_t searchmask)
{
	ASSERT_ERR((((uint32_t)searchmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_3_MASK_ADDR, (uint32_t)searchmask << 0);
}

/**
 * @brief RXM_CLS_RULE_3_ACTION register definition
 *  Classification action rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01:00 ACTION                    0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_3_ACTION_ADDR        (REG_RXM_BASE_ADDR+0x00000108)
#define RXM_RXM_CLS_RULE_3_ACTION_OFFSET      0x00000108
#define RXM_RXM_CLS_RULE_3_ACTION_INDEX       0x00000042
#define RXM_RXM_CLS_RULE_3_ACTION_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_3_action_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_3_ACTION_ADDR);
}

__INLINE void rxm_rxm_cls_rule_3_action_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_3_ACTION_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_3_ACTION_ACTION_MASK    ((uint32_t)0x00000003)
#define RXM_RXM_CLS_RULE_3_ACTION_ACTION_LSB    0
#define RXM_RXM_CLS_RULE_3_ACTION_ACTION_WIDTH    ((uint32_t)0x00000002)

#define RXM_RXM_CLS_RULE_3_ACTION_ACTION_RST    0x0

__INLINE uint8_t rxm_rxm_cls_rule_3_action_action_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_3_ACTION_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_3_action_action_setf(uint8_t action)
{
	ASSERT_ERR((((uint32_t)action << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_3_ACTION_ADDR, (uint32_t)action << 0);
}

/**
 * @brief RXM_CLS_RULE_4_KEY register definition
 *  Classification key rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SEARCH_KEY                0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_4_KEY_ADDR        (REG_RXM_BASE_ADDR+0x00000110)
#define RXM_RXM_CLS_RULE_4_KEY_OFFSET      0x00000110
#define RXM_RXM_CLS_RULE_4_KEY_INDEX       0x00000044
#define RXM_RXM_CLS_RULE_4_KEY_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_4_key_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_4_KEY_ADDR);
}

__INLINE void rxm_rxm_cls_rule_4_key_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_4_KEY_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_4_KEY_SEARCH_KEY_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_CLS_RULE_4_KEY_SEARCH_KEY_LSB    0
#define RXM_RXM_CLS_RULE_4_KEY_SEARCH_KEY_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_CLS_RULE_4_KEY_SEARCH_KEY_RST    0x0

__INLINE uint32_t rxm_rxm_cls_rule_4_key_search_key_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_4_KEY_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_4_key_search_key_setf(uint32_t searchkey)
{
	ASSERT_ERR((((uint32_t)searchkey << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_4_KEY_ADDR, (uint32_t)searchkey << 0);
}

/**
 * @brief RXM_CLS_RULE_4_MASK register definition
 *  Classification mask rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SEARCH_MASK               0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_4_MASK_ADDR        (REG_RXM_BASE_ADDR+0x00000114)
#define RXM_RXM_CLS_RULE_4_MASK_OFFSET      0x00000114
#define RXM_RXM_CLS_RULE_4_MASK_INDEX       0x00000045
#define RXM_RXM_CLS_RULE_4_MASK_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_4_mask_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_4_MASK_ADDR);
}

__INLINE void rxm_rxm_cls_rule_4_mask_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_4_MASK_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_4_MASK_SEARCH_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_CLS_RULE_4_MASK_SEARCH_MASK_LSB    0
#define RXM_RXM_CLS_RULE_4_MASK_SEARCH_MASK_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_CLS_RULE_4_MASK_SEARCH_MASK_RST    0x0

__INLINE uint32_t rxm_rxm_cls_rule_4_mask_search_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_4_MASK_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_4_mask_search_mask_setf(uint32_t searchmask)
{
	ASSERT_ERR((((uint32_t)searchmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_4_MASK_ADDR, (uint32_t)searchmask << 0);
}

/**
 * @brief RXM_CLS_RULE_4_ACTION register definition
 *  Classification action rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01:00 ACTION                    0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_4_ACTION_ADDR        (REG_RXM_BASE_ADDR+0x00000118)
#define RXM_RXM_CLS_RULE_4_ACTION_OFFSET      0x00000118
#define RXM_RXM_CLS_RULE_4_ACTION_INDEX       0x00000046
#define RXM_RXM_CLS_RULE_4_ACTION_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_4_action_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_4_ACTION_ADDR);
}

__INLINE void rxm_rxm_cls_rule_4_action_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_4_ACTION_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_4_ACTION_ACTION_MASK    ((uint32_t)0x00000003)
#define RXM_RXM_CLS_RULE_4_ACTION_ACTION_LSB    0
#define RXM_RXM_CLS_RULE_4_ACTION_ACTION_WIDTH    ((uint32_t)0x00000002)

#define RXM_RXM_CLS_RULE_4_ACTION_ACTION_RST    0x0

__INLINE uint8_t rxm_rxm_cls_rule_4_action_action_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_4_ACTION_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_4_action_action_setf(uint8_t action)
{
	ASSERT_ERR((((uint32_t)action << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_4_ACTION_ADDR, (uint32_t)action << 0);
}

/**
 * @brief RXM_CLS_RULE_5_KEY register definition
 *  Classification key rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SEARCH_KEY                0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_5_KEY_ADDR        (REG_RXM_BASE_ADDR+0x00000120)
#define RXM_RXM_CLS_RULE_5_KEY_OFFSET      0x00000120
#define RXM_RXM_CLS_RULE_5_KEY_INDEX       0x00000048
#define RXM_RXM_CLS_RULE_5_KEY_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_5_key_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_5_KEY_ADDR);
}

__INLINE void rxm_rxm_cls_rule_5_key_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_5_KEY_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_5_KEY_SEARCH_KEY_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_CLS_RULE_5_KEY_SEARCH_KEY_LSB    0
#define RXM_RXM_CLS_RULE_5_KEY_SEARCH_KEY_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_CLS_RULE_5_KEY_SEARCH_KEY_RST    0x0

__INLINE uint32_t rxm_rxm_cls_rule_5_key_search_key_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_5_KEY_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_5_key_search_key_setf(uint32_t searchkey)
{
	ASSERT_ERR((((uint32_t)searchkey << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_5_KEY_ADDR, (uint32_t)searchkey << 0);
}

/**
 * @brief RXM_CLS_RULE_5_MASK register definition
 *  Classification mask rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SEARCH_MASK               0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_5_MASK_ADDR        (REG_RXM_BASE_ADDR+0x00000124)
#define RXM_RXM_CLS_RULE_5_MASK_OFFSET      0x00000124
#define RXM_RXM_CLS_RULE_5_MASK_INDEX       0x00000049
#define RXM_RXM_CLS_RULE_5_MASK_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_5_mask_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_5_MASK_ADDR);
}

__INLINE void rxm_rxm_cls_rule_5_mask_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_5_MASK_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_5_MASK_SEARCH_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_CLS_RULE_5_MASK_SEARCH_MASK_LSB    0
#define RXM_RXM_CLS_RULE_5_MASK_SEARCH_MASK_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_CLS_RULE_5_MASK_SEARCH_MASK_RST    0x0

__INLINE uint32_t rxm_rxm_cls_rule_5_mask_search_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_5_MASK_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_5_mask_search_mask_setf(uint32_t searchmask)
{
	ASSERT_ERR((((uint32_t)searchmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_5_MASK_ADDR, (uint32_t)searchmask << 0);
}

/**
 * @brief RXM_CLS_RULE_5_ACTION register definition
 *  Classification action rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01:00 Action                    0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_5_ACTION_ADDR        (REG_RXM_BASE_ADDR+0x00000128)
#define RXM_RXM_CLS_RULE_5_ACTION_OFFSET      0x00000128
#define RXM_RXM_CLS_RULE_5_ACTION_INDEX       0x0000004A
#define RXM_RXM_CLS_RULE_5_ACTION_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_5_action_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_5_ACTION_ADDR);
}

__INLINE void rxm_rxm_cls_rule_5_action_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_5_ACTION_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_5_ACTION_ACTION_MASK    ((uint32_t)0x00000003)
#define RXM_RXM_CLS_RULE_5_ACTION_ACTION_LSB    0
#define RXM_RXM_CLS_RULE_5_ACTION_ACTION_WIDTH    ((uint32_t)0x00000002)

#define RXM_RXM_CLS_RULE_5_ACTION_ACTION_RST    0x0

__INLINE uint8_t rxm_rxm_cls_rule_5_action_action_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_5_ACTION_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_5_action_action_setf(uint8_t action)
{
	ASSERT_ERR((((uint32_t)action << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_5_ACTION_ADDR, (uint32_t)action << 0);
}

/**
 * @brief RXM_CLS_RULE_6_KEY register definition
 *  Classification key rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SEARCH_KEY                0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_6_KEY_ADDR        (REG_RXM_BASE_ADDR+0x00000130)
#define RXM_RXM_CLS_RULE_6_KEY_OFFSET      0x00000130
#define RXM_RXM_CLS_RULE_6_KEY_INDEX       0x0000004C
#define RXM_RXM_CLS_RULE_6_KEY_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_6_key_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_6_KEY_ADDR);
}

__INLINE void rxm_rxm_cls_rule_6_key_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_6_KEY_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_6_KEY_SEARCH_KEY_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_CLS_RULE_6_KEY_SEARCH_KEY_LSB    0
#define RXM_RXM_CLS_RULE_6_KEY_SEARCH_KEY_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_CLS_RULE_6_KEY_SEARCH_KEY_RST    0x0

__INLINE uint32_t rxm_rxm_cls_rule_6_key_search_key_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_6_KEY_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_6_key_search_key_setf(uint32_t searchkey)
{
	ASSERT_ERR((((uint32_t)searchkey << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_6_KEY_ADDR, (uint32_t)searchkey << 0);
}

/**
 * @brief RXM_CLS_RULE_6_MASK register definition
 *  Classification mask rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SEARCH_MASK               0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_6_MASK_ADDR        (REG_RXM_BASE_ADDR+0x00000134)
#define RXM_RXM_CLS_RULE_6_MASK_OFFSET      0x00000134
#define RXM_RXM_CLS_RULE_6_MASK_INDEX       0x0000004D
#define RXM_RXM_CLS_RULE_6_MASK_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_6_mask_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_6_MASK_ADDR);
}

__INLINE void rxm_rxm_cls_rule_6_mask_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_6_MASK_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_6_MASK_SEARCH_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_CLS_RULE_6_MASK_SEARCH_MASK_LSB    0
#define RXM_RXM_CLS_RULE_6_MASK_SEARCH_MASK_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_CLS_RULE_6_MASK_SEARCH_MASK_RST    0x0

__INLINE uint32_t rxm_rxm_cls_rule_6_mask_search_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_6_MASK_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_6_mask_search_mask_setf(uint32_t searchmask)
{
	ASSERT_ERR((((uint32_t)searchmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_6_MASK_ADDR, (uint32_t)searchmask << 0);
}

/**
 * @brief RXM_CLS_RULE_6_ACTION register definition
 *  Classification action rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01:00 ACTION                    0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_6_ACTION_ADDR        (REG_RXM_BASE_ADDR+0x00000138)
#define RXM_RXM_CLS_RULE_6_ACTION_OFFSET      0x00000138
#define RXM_RXM_CLS_RULE_6_ACTION_INDEX       0x0000004E
#define RXM_RXM_CLS_RULE_6_ACTION_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_6_action_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_6_ACTION_ADDR);
}

__INLINE void rxm_rxm_cls_rule_6_action_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_6_ACTION_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_6_ACTION_ACTION_MASK    ((uint32_t)0x00000003)
#define RXM_RXM_CLS_RULE_6_ACTION_ACTION_LSB    0
#define RXM_RXM_CLS_RULE_6_ACTION_ACTION_WIDTH    ((uint32_t)0x00000002)

#define RXM_RXM_CLS_RULE_6_ACTION_ACTION_RST    0x0

__INLINE uint8_t rxm_rxm_cls_rule_6_action_action_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_6_ACTION_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_6_action_action_setf(uint8_t action)
{
	ASSERT_ERR((((uint32_t)action << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_6_ACTION_ADDR, (uint32_t)action << 0);
}

/**
 * @brief RXM_CLS_RULE_7_KEY register definition
 *  Classification key rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SEARCH_KEY                0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_7_KEY_ADDR        (REG_RXM_BASE_ADDR+0x00000140)
#define RXM_RXM_CLS_RULE_7_KEY_OFFSET      0x00000140
#define RXM_RXM_CLS_RULE_7_KEY_INDEX       0x00000050
#define RXM_RXM_CLS_RULE_7_KEY_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_7_key_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_7_KEY_ADDR);
}

__INLINE void rxm_rxm_cls_rule_7_key_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_7_KEY_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_7_KEY_SEARCH_KEY_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_CLS_RULE_7_KEY_SEARCH_KEY_LSB    0
#define RXM_RXM_CLS_RULE_7_KEY_SEARCH_KEY_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_CLS_RULE_7_KEY_SEARCH_KEY_RST    0x0

__INLINE uint32_t rxm_rxm_cls_rule_7_key_search_key_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_7_KEY_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_7_key_search_key_setf(uint32_t searchkey)
{
	ASSERT_ERR((((uint32_t)searchkey << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_7_KEY_ADDR, (uint32_t)searchkey << 0);
}

/**
 * @brief RXM_CLS_RULE_7_MASK register definition
 *  Classification mask rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SEARCH_MASK               0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_7_MASK_ADDR        (REG_RXM_BASE_ADDR+0x00000144)
#define RXM_RXM_CLS_RULE_7_MASK_OFFSET      0x00000144
#define RXM_RXM_CLS_RULE_7_MASK_INDEX       0x00000051
#define RXM_RXM_CLS_RULE_7_MASK_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_7_mask_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_7_MASK_ADDR);
}

__INLINE void rxm_rxm_cls_rule_7_mask_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_7_MASK_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_7_MASK_SEARCH_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_CLS_RULE_7_MASK_SEARCH_MASK_LSB    0
#define RXM_RXM_CLS_RULE_7_MASK_SEARCH_MASK_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_CLS_RULE_7_MASK_SEARCH_MASK_RST    0x0

__INLINE uint32_t rxm_rxm_cls_rule_7_mask_search_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_7_MASK_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_7_mask_search_mask_setf(uint32_t searchmask)
{
	ASSERT_ERR((((uint32_t)searchmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_7_MASK_ADDR, (uint32_t)searchmask << 0);
}

/**
 * @brief RXM_CLS_RULE_7_ACTION register definition
 *  Classification action rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01:00 ACTION                    0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_7_ACTION_ADDR        (REG_RXM_BASE_ADDR+0x00000148)
#define RXM_RXM_CLS_RULE_7_ACTION_OFFSET      0x00000148
#define RXM_RXM_CLS_RULE_7_ACTION_INDEX       0x00000052
#define RXM_RXM_CLS_RULE_7_ACTION_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_7_action_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_7_ACTION_ADDR);
}

__INLINE void rxm_rxm_cls_rule_7_action_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_7_ACTION_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_7_ACTION_ACTION_MASK    ((uint32_t)0x00000003)
#define RXM_RXM_CLS_RULE_7_ACTION_ACTION_LSB    0
#define RXM_RXM_CLS_RULE_7_ACTION_ACTION_WIDTH    ((uint32_t)0x00000002)

#define RXM_RXM_CLS_RULE_7_ACTION_ACTION_RST    0x0

__INLINE uint8_t rxm_rxm_cls_rule_7_action_action_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_7_ACTION_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_7_action_action_setf(uint8_t action)
{
	ASSERT_ERR((((uint32_t)action << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_7_ACTION_ADDR, (uint32_t)action << 0);
}

/**
 * @brief RXM_CLS_RULE_8_KEY register definition
 *  Classification key rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SEARCH_KEY                0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_8_KEY_ADDR        (REG_RXM_BASE_ADDR+0x00000150)
#define RXM_RXM_CLS_RULE_8_KEY_OFFSET      0x00000150
#define RXM_RXM_CLS_RULE_8_KEY_INDEX       0x00000054
#define RXM_RXM_CLS_RULE_8_KEY_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_8_key_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_8_KEY_ADDR);
}

__INLINE void rxm_rxm_cls_rule_8_key_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_8_KEY_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_8_KEY_SEARCH_KEY_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_CLS_RULE_8_KEY_SEARCH_KEY_LSB    0
#define RXM_RXM_CLS_RULE_8_KEY_SEARCH_KEY_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_CLS_RULE_8_KEY_SEARCH_KEY_RST    0x0

__INLINE uint32_t rxm_rxm_cls_rule_8_key_search_key_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_8_KEY_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_8_key_search_key_setf(uint32_t searchkey)
{
	ASSERT_ERR((((uint32_t)searchkey << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_8_KEY_ADDR, (uint32_t)searchkey << 0);
}

/**
 * @brief RXM_CLS_RULE_8_MASK register definition
 *  Classification mask rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SEARCH_MASK               0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_8_MASK_ADDR        (REG_RXM_BASE_ADDR+0x00000154)
#define RXM_RXM_CLS_RULE_8_MASK_OFFSET      0x00000154
#define RXM_RXM_CLS_RULE_8_MASK_INDEX       0x00000055
#define RXM_RXM_CLS_RULE_8_MASK_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_8_mask_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_8_MASK_ADDR);
}

__INLINE void rxm_rxm_cls_rule_8_mask_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_8_MASK_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_8_MASK_SEARCH_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_CLS_RULE_8_MASK_SEARCH_MASK_LSB    0
#define RXM_RXM_CLS_RULE_8_MASK_SEARCH_MASK_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_CLS_RULE_8_MASK_SEARCH_MASK_RST    0x0

__INLINE uint32_t rxm_rxm_cls_rule_8_mask_search_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_8_MASK_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_8_mask_search_mask_setf(uint32_t searchmask)
{
	ASSERT_ERR((((uint32_t)searchmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_8_MASK_ADDR, (uint32_t)searchmask << 0);
}

/**
 * @brief RXM_CLS_RULE_8_ACTION register definition
 *  Classification action rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01:00 ACTION                    0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_8_ACTION_ADDR        (REG_RXM_BASE_ADDR+0x00000158)
#define RXM_RXM_CLS_RULE_8_ACTION_OFFSET      0x00000158
#define RXM_RXM_CLS_RULE_8_ACTION_INDEX       0x00000056
#define RXM_RXM_CLS_RULE_8_ACTION_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_8_action_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_8_ACTION_ADDR);
}

__INLINE void rxm_rxm_cls_rule_8_action_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_8_ACTION_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_8_ACTION_ACTION_MASK    ((uint32_t)0x00000003)
#define RXM_RXM_CLS_RULE_8_ACTION_ACTION_LSB    0
#define RXM_RXM_CLS_RULE_8_ACTION_ACTION_WIDTH    ((uint32_t)0x00000002)

#define RXM_RXM_CLS_RULE_8_ACTION_ACTION_RST    0x0

__INLINE uint8_t rxm_rxm_cls_rule_8_action_action_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_8_ACTION_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_8_action_action_setf(uint8_t action)
{
	ASSERT_ERR((((uint32_t)action << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_8_ACTION_ADDR, (uint32_t)action << 0);
}

/**
 * @brief RXM_CLS_RULE_9_KEY register definition
 *  Classification key rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SEARCH_KEY                0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_9_KEY_ADDR        (REG_RXM_BASE_ADDR+0x00000160)
#define RXM_RXM_CLS_RULE_9_KEY_OFFSET      0x00000160
#define RXM_RXM_CLS_RULE_9_KEY_INDEX       0x00000058
#define RXM_RXM_CLS_RULE_9_KEY_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_9_key_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_9_KEY_ADDR);
}

__INLINE void rxm_rxm_cls_rule_9_key_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_9_KEY_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_9_KEY_SEARCH_KEY_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_CLS_RULE_9_KEY_SEARCH_KEY_LSB    0
#define RXM_RXM_CLS_RULE_9_KEY_SEARCH_KEY_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_CLS_RULE_9_KEY_SEARCH_KEY_RST    0x0

__INLINE uint32_t rxm_rxm_cls_rule_9_key_search_key_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_9_KEY_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_9_key_search_key_setf(uint32_t searchkey)
{
	ASSERT_ERR((((uint32_t)searchkey << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_9_KEY_ADDR, (uint32_t)searchkey << 0);
}

/**
 * @brief RXM_CLS_RULE_9_MASK register definition
 *  Classification mask rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SEARCH_MASK               0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_9_MASK_ADDR        (REG_RXM_BASE_ADDR+0x00000164)
#define RXM_RXM_CLS_RULE_9_MASK_OFFSET      0x00000164
#define RXM_RXM_CLS_RULE_9_MASK_INDEX       0x00000059
#define RXM_RXM_CLS_RULE_9_MASK_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_9_mask_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_9_MASK_ADDR);
}

__INLINE void rxm_rxm_cls_rule_9_mask_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_9_MASK_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_9_MASK_SEARCH_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_CLS_RULE_9_MASK_SEARCH_MASK_LSB    0
#define RXM_RXM_CLS_RULE_9_MASK_SEARCH_MASK_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_CLS_RULE_9_MASK_SEARCH_MASK_RST    0x0

__INLINE uint32_t rxm_rxm_cls_rule_9_mask_search_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_9_MASK_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_9_mask_search_mask_setf(uint32_t searchmask)
{
	ASSERT_ERR((((uint32_t)searchmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_9_MASK_ADDR, (uint32_t)searchmask << 0);
}

/**
 * @brief RXM_CLS_RULE_9_ACTION register definition
 *  Classification action rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01:00 ACTION                    0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_9_ACTION_ADDR        (REG_RXM_BASE_ADDR+0x00000168)
#define RXM_RXM_CLS_RULE_9_ACTION_OFFSET      0x00000168
#define RXM_RXM_CLS_RULE_9_ACTION_INDEX       0x0000005A
#define RXM_RXM_CLS_RULE_9_ACTION_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_9_action_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_9_ACTION_ADDR);
}

__INLINE void rxm_rxm_cls_rule_9_action_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_9_ACTION_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_9_ACTION_ACTION_MASK    ((uint32_t)0x00000003)
#define RXM_RXM_CLS_RULE_9_ACTION_ACTION_LSB    0
#define RXM_RXM_CLS_RULE_9_ACTION_ACTION_WIDTH    ((uint32_t)0x00000002)

#define RXM_RXM_CLS_RULE_9_ACTION_ACTION_RST    0x0

__INLINE uint8_t rxm_rxm_cls_rule_9_action_action_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_9_ACTION_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_9_action_action_setf(uint8_t action)
{
	ASSERT_ERR((((uint32_t)action << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_9_ACTION_ADDR, (uint32_t)action << 0);
}

/**
 * @brief RXM_CLS_RULE_10_KEY register definition
 *  Classification key rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SEARCH_KEY                0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_10_KEY_ADDR        (REG_RXM_BASE_ADDR+0x00000170)
#define RXM_RXM_CLS_RULE_10_KEY_OFFSET      0x00000170
#define RXM_RXM_CLS_RULE_10_KEY_INDEX       0x0000005C
#define RXM_RXM_CLS_RULE_10_KEY_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_10_key_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_10_KEY_ADDR);
}

__INLINE void rxm_rxm_cls_rule_10_key_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_10_KEY_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_10_KEY_SEARCH_KEY_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_CLS_RULE_10_KEY_SEARCH_KEY_LSB    0
#define RXM_RXM_CLS_RULE_10_KEY_SEARCH_KEY_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_CLS_RULE_10_KEY_SEARCH_KEY_RST    0x0

__INLINE uint32_t rxm_rxm_cls_rule_10_key_search_key_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_10_KEY_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_10_key_search_key_setf(uint32_t searchkey)
{
	ASSERT_ERR((((uint32_t)searchkey << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_10_KEY_ADDR, (uint32_t)searchkey << 0);
}

/**
 * @brief RXM_CLS_RULE_10_MASK register definition
 *  Classification mask rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SEARCH_MASK               0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_10_MASK_ADDR        (REG_RXM_BASE_ADDR+0x00000174)
#define RXM_RXM_CLS_RULE_10_MASK_OFFSET      0x00000174
#define RXM_RXM_CLS_RULE_10_MASK_INDEX       0x0000005D
#define RXM_RXM_CLS_RULE_10_MASK_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_10_mask_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_10_MASK_ADDR);
}

__INLINE void rxm_rxm_cls_rule_10_mask_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_10_MASK_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_10_MASK_SEARCH_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_CLS_RULE_10_MASK_SEARCH_MASK_LSB    0
#define RXM_RXM_CLS_RULE_10_MASK_SEARCH_MASK_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_CLS_RULE_10_MASK_SEARCH_MASK_RST    0x0

__INLINE uint32_t rxm_rxm_cls_rule_10_mask_search_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_10_MASK_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_10_mask_search_mask_setf(uint32_t searchmask)
{
	ASSERT_ERR((((uint32_t)searchmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_10_MASK_ADDR, (uint32_t)searchmask << 0);
}

/**
 * @brief RXM_CLS_RULE_10_ACTION register definition
 *  Classification action rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01:00 ACTION                    0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_10_ACTION_ADDR        (REG_RXM_BASE_ADDR+0x00000178)
#define RXM_RXM_CLS_RULE_10_ACTION_OFFSET      0x00000178
#define RXM_RXM_CLS_RULE_10_ACTION_INDEX       0x0000005E
#define RXM_RXM_CLS_RULE_10_ACTION_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_10_action_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_10_ACTION_ADDR);
}

__INLINE void rxm_rxm_cls_rule_10_action_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_10_ACTION_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_10_ACTION_ACTION_MASK    ((uint32_t)0x00000003)
#define RXM_RXM_CLS_RULE_10_ACTION_ACTION_LSB    0
#define RXM_RXM_CLS_RULE_10_ACTION_ACTION_WIDTH    ((uint32_t)0x00000002)

#define RXM_RXM_CLS_RULE_10_ACTION_ACTION_RST    0x0

__INLINE uint8_t rxm_rxm_cls_rule_10_action_action_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_10_ACTION_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_10_action_action_setf(uint8_t action)
{
	ASSERT_ERR((((uint32_t)action << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_10_ACTION_ADDR, (uint32_t)action << 0);
}

/**
 * @brief RXM_CLS_RULE_11_KEY register definition
 *  Classification key rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SEARCH_KEY                0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_11_KEY_ADDR        (REG_RXM_BASE_ADDR+0x00000180)
#define RXM_RXM_CLS_RULE_11_KEY_OFFSET      0x00000180
#define RXM_RXM_CLS_RULE_11_KEY_INDEX       0x00000060
#define RXM_RXM_CLS_RULE_11_KEY_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_11_key_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_11_KEY_ADDR);
}

__INLINE void rxm_rxm_cls_rule_11_key_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_11_KEY_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_11_KEY_SEARCH_KEY_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_CLS_RULE_11_KEY_SEARCH_KEY_LSB    0
#define RXM_RXM_CLS_RULE_11_KEY_SEARCH_KEY_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_CLS_RULE_11_KEY_SEARCH_KEY_RST    0x0

__INLINE uint32_t rxm_rxm_cls_rule_11_key_search_key_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_11_KEY_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_11_key_search_key_setf(uint32_t searchkey)
{
	ASSERT_ERR((((uint32_t)searchkey << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_11_KEY_ADDR, (uint32_t)searchkey << 0);
}

/**
 * @brief RXM_CLS_RULE_11_MASK register definition
 *  Classification mask rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SEARCH_MASK               0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_11_MASK_ADDR        (REG_RXM_BASE_ADDR+0x00000184)
#define RXM_RXM_CLS_RULE_11_MASK_OFFSET      0x00000184
#define RXM_RXM_CLS_RULE_11_MASK_INDEX       0x00000061
#define RXM_RXM_CLS_RULE_11_MASK_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_11_mask_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_11_MASK_ADDR);
}

__INLINE void rxm_rxm_cls_rule_11_mask_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_11_MASK_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_11_MASK_SEARCH_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_CLS_RULE_11_MASK_SEARCH_MASK_LSB    0
#define RXM_RXM_CLS_RULE_11_MASK_SEARCH_MASK_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_CLS_RULE_11_MASK_SEARCH_MASK_RST    0x0

__INLINE uint32_t rxm_rxm_cls_rule_11_mask_search_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_11_MASK_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_11_mask_search_mask_setf(uint32_t searchmask)
{
	ASSERT_ERR((((uint32_t)searchmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_11_MASK_ADDR, (uint32_t)searchmask << 0);
}

/**
 * @brief RXM_CLS_RULE_11_ACTION register definition
 *  Classification action rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01:00 ACTION                    0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_11_ACTION_ADDR        (REG_RXM_BASE_ADDR+0x00000188)
#define RXM_RXM_CLS_RULE_11_ACTION_OFFSET      0x00000188
#define RXM_RXM_CLS_RULE_11_ACTION_INDEX       0x00000062
#define RXM_RXM_CLS_RULE_11_ACTION_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_11_action_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_11_ACTION_ADDR);
}

__INLINE void rxm_rxm_cls_rule_11_action_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_11_ACTION_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_11_ACTION_ACTION_MASK    ((uint32_t)0x00000003)
#define RXM_RXM_CLS_RULE_11_ACTION_ACTION_LSB    0
#define RXM_RXM_CLS_RULE_11_ACTION_ACTION_WIDTH    ((uint32_t)0x00000002)

#define RXM_RXM_CLS_RULE_11_ACTION_ACTION_RST    0x0

__INLINE uint8_t rxm_rxm_cls_rule_11_action_action_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_11_ACTION_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_11_action_action_setf(uint8_t action)
{
	ASSERT_ERR((((uint32_t)action << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_11_ACTION_ADDR, (uint32_t)action << 0);
}

/**
 * @brief RXM_CLS_RULE_12_KEY register definition
 *  Classification key rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SEARCH_KEY                0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_12_KEY_ADDR        (REG_RXM_BASE_ADDR+0x00000190)
#define RXM_RXM_CLS_RULE_12_KEY_OFFSET      0x00000190
#define RXM_RXM_CLS_RULE_12_KEY_INDEX       0x00000064
#define RXM_RXM_CLS_RULE_12_KEY_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_12_key_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_12_KEY_ADDR);
}

__INLINE void rxm_rxm_cls_rule_12_key_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_12_KEY_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_12_KEY_SEARCH_KEY_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_CLS_RULE_12_KEY_SEARCH_KEY_LSB    0
#define RXM_RXM_CLS_RULE_12_KEY_SEARCH_KEY_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_CLS_RULE_12_KEY_SEARCH_KEY_RST    0x0

__INLINE uint32_t rxm_rxm_cls_rule_12_key_search_key_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_12_KEY_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_12_key_search_key_setf(uint32_t searchkey)
{
	ASSERT_ERR((((uint32_t)searchkey << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_12_KEY_ADDR, (uint32_t)searchkey << 0);
}

/**
 * @brief RXM_CLS_RULE_12_MASK register definition
 *  Classification mask rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SEARCH_MASK               0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_12_MASK_ADDR        (REG_RXM_BASE_ADDR+0x00000194)
#define RXM_RXM_CLS_RULE_12_MASK_OFFSET      0x00000194
#define RXM_RXM_CLS_RULE_12_MASK_INDEX       0x00000065
#define RXM_RXM_CLS_RULE_12_MASK_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_12_mask_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_12_MASK_ADDR);
}

__INLINE void rxm_rxm_cls_rule_12_mask_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_12_MASK_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_12_MASK_SEARCH_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_CLS_RULE_12_MASK_SEARCH_MASK_LSB    0
#define RXM_RXM_CLS_RULE_12_MASK_SEARCH_MASK_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_CLS_RULE_12_MASK_SEARCH_MASK_RST    0x0

__INLINE uint32_t rxm_rxm_cls_rule_12_mask_search_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_12_MASK_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_12_mask_search_mask_setf(uint32_t searchmask)
{
	ASSERT_ERR((((uint32_t)searchmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_12_MASK_ADDR, (uint32_t)searchmask << 0);
}

/**
 * @brief RXM_CLS_RULE_12_ACTION register definition
 *  Classification action rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01:00 ACTION                    0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_12_ACTION_ADDR        (REG_RXM_BASE_ADDR+0x00000198)
#define RXM_RXM_CLS_RULE_12_ACTION_OFFSET      0x00000198
#define RXM_RXM_CLS_RULE_12_ACTION_INDEX       0x00000066
#define RXM_RXM_CLS_RULE_12_ACTION_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_12_action_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_12_ACTION_ADDR);
}

__INLINE void rxm_rxm_cls_rule_12_action_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_12_ACTION_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_12_ACTION_ACTION_MASK    ((uint32_t)0x00000003)
#define RXM_RXM_CLS_RULE_12_ACTION_ACTION_LSB    0
#define RXM_RXM_CLS_RULE_12_ACTION_ACTION_WIDTH    ((uint32_t)0x00000002)

#define RXM_RXM_CLS_RULE_12_ACTION_ACTION_RST    0x0

__INLINE uint8_t rxm_rxm_cls_rule_12_action_action_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_12_ACTION_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_12_action_action_setf(uint8_t action)
{
	ASSERT_ERR((((uint32_t)action << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_12_ACTION_ADDR, (uint32_t)action << 0);
}

/**
 * @brief RXM_CLS_RULE_13_KEY register definition
 *  Classification key rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SEARCH_KEY                0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_13_KEY_ADDR        (REG_RXM_BASE_ADDR+0x000001A0)
#define RXM_RXM_CLS_RULE_13_KEY_OFFSET      0x000001A0
#define RXM_RXM_CLS_RULE_13_KEY_INDEX       0x00000068
#define RXM_RXM_CLS_RULE_13_KEY_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_13_key_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_13_KEY_ADDR);
}

__INLINE void rxm_rxm_cls_rule_13_key_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_13_KEY_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_13_KEY_SEARCH_KEY_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_CLS_RULE_13_KEY_SEARCH_KEY_LSB    0
#define RXM_RXM_CLS_RULE_13_KEY_SEARCH_KEY_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_CLS_RULE_13_KEY_SEARCH_KEY_RST    0x0

__INLINE uint32_t rxm_rxm_cls_rule_13_key_search_key_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_13_KEY_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_13_key_search_key_setf(uint32_t searchkey)
{
	ASSERT_ERR((((uint32_t)searchkey << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_13_KEY_ADDR, (uint32_t)searchkey << 0);
}

/**
 * @brief RXM_CLS_RULE_13_MASK register definition
 *  Classification mask rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SEARCH_MASK               0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_13_MASK_ADDR        (REG_RXM_BASE_ADDR+0x000001A4)
#define RXM_RXM_CLS_RULE_13_MASK_OFFSET      0x000001A4
#define RXM_RXM_CLS_RULE_13_MASK_INDEX       0x00000069
#define RXM_RXM_CLS_RULE_13_MASK_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_13_mask_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_13_MASK_ADDR);
}

__INLINE void rxm_rxm_cls_rule_13_mask_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_13_MASK_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_13_MASK_SEARCH_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_CLS_RULE_13_MASK_SEARCH_MASK_LSB    0
#define RXM_RXM_CLS_RULE_13_MASK_SEARCH_MASK_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_CLS_RULE_13_MASK_SEARCH_MASK_RST    0x0

__INLINE uint32_t rxm_rxm_cls_rule_13_mask_search_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_13_MASK_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_13_mask_search_mask_setf(uint32_t searchmask)
{
	ASSERT_ERR((((uint32_t)searchmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_13_MASK_ADDR, (uint32_t)searchmask << 0);
}

/**
 * @brief RXM_CLS_RULE_13_ACTION register definition
 *  Classification action rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01:00 ACTION                    0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_13_ACTION_ADDR        (REG_RXM_BASE_ADDR+0x000001A8)
#define RXM_RXM_CLS_RULE_13_ACTION_OFFSET      0x000001A8
#define RXM_RXM_CLS_RULE_13_ACTION_INDEX       0x0000006A
#define RXM_RXM_CLS_RULE_13_ACTION_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_13_action_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_13_ACTION_ADDR);
}

__INLINE void rxm_rxm_cls_rule_13_action_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_13_ACTION_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_13_ACTION_ACTION_MASK    ((uint32_t)0x00000003)
#define RXM_RXM_CLS_RULE_13_ACTION_ACTION_LSB    0
#define RXM_RXM_CLS_RULE_13_ACTION_ACTION_WIDTH    ((uint32_t)0x00000002)

#define RXM_RXM_CLS_RULE_13_ACTION_ACTION_RST    0x0

__INLINE uint8_t rxm_rxm_cls_rule_13_action_action_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_13_ACTION_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_13_action_action_setf(uint8_t action)
{
	ASSERT_ERR((((uint32_t)action << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_13_ACTION_ADDR, (uint32_t)action << 0);
}

/**
 * @brief RXM_CLS_RULE_14_KEY register definition
 *  Classification key rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SEARCH_KEY                0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_14_KEY_ADDR        (REG_RXM_BASE_ADDR+0x000001B0)
#define RXM_RXM_CLS_RULE_14_KEY_OFFSET      0x000001B0
#define RXM_RXM_CLS_RULE_14_KEY_INDEX       0x0000006C
#define RXM_RXM_CLS_RULE_14_KEY_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_14_key_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_14_KEY_ADDR);
}

__INLINE void rxm_rxm_cls_rule_14_key_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_14_KEY_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_14_KEY_SEARCH_KEY_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_CLS_RULE_14_KEY_SEARCH_KEY_LSB    0
#define RXM_RXM_CLS_RULE_14_KEY_SEARCH_KEY_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_CLS_RULE_14_KEY_SEARCH_KEY_RST    0x0

__INLINE uint32_t rxm_rxm_cls_rule_14_key_search_key_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_14_KEY_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_14_key_search_key_setf(uint32_t searchkey)
{
	ASSERT_ERR((((uint32_t)searchkey << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_14_KEY_ADDR, (uint32_t)searchkey << 0);
}

/**
 * @brief RXM_CLS_RULE_14_MASK register definition
 *  Classification mask rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SEARCH_MASK               0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_14_MASK_ADDR        (REG_RXM_BASE_ADDR+0x000001B4)
#define RXM_RXM_CLS_RULE_14_MASK_OFFSET      0x000001B4
#define RXM_RXM_CLS_RULE_14_MASK_INDEX       0x0000006D
#define RXM_RXM_CLS_RULE_14_MASK_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_14_mask_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_14_MASK_ADDR);
}

__INLINE void rxm_rxm_cls_rule_14_mask_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_14_MASK_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_14_MASK_SEARCH_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_CLS_RULE_14_MASK_SEARCH_MASK_LSB    0
#define RXM_RXM_CLS_RULE_14_MASK_SEARCH_MASK_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_CLS_RULE_14_MASK_SEARCH_MASK_RST    0x0

__INLINE uint32_t rxm_rxm_cls_rule_14_mask_search_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_14_MASK_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_14_mask_search_mask_setf(uint32_t searchmask)
{
	ASSERT_ERR((((uint32_t)searchmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_14_MASK_ADDR, (uint32_t)searchmask << 0);
}

/**
 * @brief RXM_CLS_RULE_14_ACTION register definition
 *  Classification action rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01:00 ACTION                    0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_14_ACTION_ADDR        (REG_RXM_BASE_ADDR+0x000001B8)
#define RXM_RXM_CLS_RULE_14_ACTION_OFFSET      0x000001B8
#define RXM_RXM_CLS_RULE_14_ACTION_INDEX       0x0000006E
#define RXM_RXM_CLS_RULE_14_ACTION_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_14_action_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_14_ACTION_ADDR);
}

__INLINE void rxm_rxm_cls_rule_14_action_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_14_ACTION_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_14_ACTION_ACTION_MASK    ((uint32_t)0x00000003)
#define RXM_RXM_CLS_RULE_14_ACTION_ACTION_LSB    0
#define RXM_RXM_CLS_RULE_14_ACTION_ACTION_WIDTH    ((uint32_t)0x00000002)

#define RXM_RXM_CLS_RULE_14_ACTION_ACTION_RST    0x0

__INLINE uint8_t rxm_rxm_cls_rule_14_action_action_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_14_ACTION_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_14_action_action_setf(uint8_t action)
{
	ASSERT_ERR((((uint32_t)action << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_14_ACTION_ADDR, (uint32_t)action << 0);
}

/**
 * @brief RXM_CLS_RULE_15_KEY register definition
 *  Classification key rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SEARCH_KEY                0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_15_KEY_ADDR        (REG_RXM_BASE_ADDR+0x000001C0)
#define RXM_RXM_CLS_RULE_15_KEY_OFFSET      0x000001C0
#define RXM_RXM_CLS_RULE_15_KEY_INDEX       0x00000070
#define RXM_RXM_CLS_RULE_15_KEY_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_15_key_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_15_KEY_ADDR);
}

__INLINE void rxm_rxm_cls_rule_15_key_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_15_KEY_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_15_KEY_SEARCH_KEY_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_CLS_RULE_15_KEY_SEARCH_KEY_LSB    0
#define RXM_RXM_CLS_RULE_15_KEY_SEARCH_KEY_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_CLS_RULE_15_KEY_SEARCH_KEY_RST    0x0

__INLINE uint32_t rxm_rxm_cls_rule_15_key_search_key_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_15_KEY_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_15_key_search_key_setf(uint32_t searchkey)
{
	ASSERT_ERR((((uint32_t)searchkey << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_15_KEY_ADDR, (uint32_t)searchkey << 0);
}

/**
 * @brief RXM_CLS_RULE_15_MASK register definition
 *  Classification mask rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SEARCH_MASK               0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_15_MASK_ADDR        (REG_RXM_BASE_ADDR+0x000001C4)
#define RXM_RXM_CLS_RULE_15_MASK_OFFSET      0x000001C4
#define RXM_RXM_CLS_RULE_15_MASK_INDEX       0x00000071
#define RXM_RXM_CLS_RULE_15_MASK_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_15_mask_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_15_MASK_ADDR);
}

__INLINE void rxm_rxm_cls_rule_15_mask_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_15_MASK_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_15_MASK_SEARCH_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_CLS_RULE_15_MASK_SEARCH_MASK_LSB    0
#define RXM_RXM_CLS_RULE_15_MASK_SEARCH_MASK_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_CLS_RULE_15_MASK_SEARCH_MASK_RST    0x0

__INLINE uint32_t rxm_rxm_cls_rule_15_mask_search_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_15_MASK_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_15_mask_search_mask_setf(uint32_t searchmask)
{
	ASSERT_ERR((((uint32_t)searchmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_15_MASK_ADDR, (uint32_t)searchmask << 0);
}

/**
 * @brief RXM_CLS_RULE_15_ACTION register definition
 *  Classification action rule register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01:00 ACTION                    0x0
 * </pre>
 */
#define RXM_RXM_CLS_RULE_15_ACTION_ADDR        (REG_RXM_BASE_ADDR+0x000001C8)
#define RXM_RXM_CLS_RULE_15_ACTION_OFFSET      0x000001C8
#define RXM_RXM_CLS_RULE_15_ACTION_INDEX       0x00000072
#define RXM_RXM_CLS_RULE_15_ACTION_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rule_15_action_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RULE_15_ACTION_ADDR);
}

__INLINE void rxm_rxm_cls_rule_15_action_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RULE_15_ACTION_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RULE_15_ACTION_ACTION_MASK    ((uint32_t)0x00000003)
#define RXM_RXM_CLS_RULE_15_ACTION_ACTION_LSB    0
#define RXM_RXM_CLS_RULE_15_ACTION_ACTION_WIDTH    ((uint32_t)0x00000002)

#define RXM_RXM_CLS_RULE_15_ACTION_ACTION_RST    0x0

__INLINE uint8_t rxm_rxm_cls_rule_15_action_action_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RULE_15_ACTION_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rule_15_action_action_setf(uint8_t action)
{
	ASSERT_ERR((((uint32_t)action << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RULE_15_ACTION_ADDR, (uint32_t)action << 0);
}

/**
 * @brief RXM_CLS_DEFAULT_ACTION register definition
 *  Classification default action register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01:00 Action                    0x0
 * </pre>
 */
#define RXM_RXM_CLS_DEFAULT_ACTION_ADDR        (REG_RXM_BASE_ADDR+0x000001D0)
#define RXM_RXM_CLS_DEFAULT_ACTION_OFFSET      0x000001D0
#define RXM_RXM_CLS_DEFAULT_ACTION_INDEX       0x00000074
#define RXM_RXM_CLS_DEFAULT_ACTION_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_default_action_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_DEFAULT_ACTION_ADDR);
}

__INLINE void rxm_rxm_cls_default_action_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_DEFAULT_ACTION_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_DEFAULT_ACTION_ACTION_MASK    ((uint32_t)0x00000003)
#define RXM_RXM_CLS_DEFAULT_ACTION_ACTION_LSB    0
#define RXM_RXM_CLS_DEFAULT_ACTION_ACTION_WIDTH    ((uint32_t)0x00000002)

#define RXM_RXM_CLS_DEFAULT_ACTION_ACTION_RST    0x0

__INLINE uint8_t rxm_rxm_cls_default_action_action_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_DEFAULT_ACTION_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_default_action_action_setf(uint8_t action)
{
	ASSERT_ERR((((uint32_t)action << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RXM_RXM_CLS_DEFAULT_ACTION_ADDR, (uint32_t)action << 0);
}

/**
 * @brief RXM_CLS_EN register definition
 *  Classification rules enable register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15    CLS_RULE15_EN             0              
 *    14    CLS_RULE14_EN             0              
 *    13    CLS_RULE13_EN             0              
 *    12    CLS_RULE12_EN             0              
 *    11    CLS_RULE11_EN             0              
 *    10    CLS_RULE10_EN             0              
 *    09    CLS_RULE9_EN              0              
 *    08    CLS_RULE8_EN              0              
 *    07    CLS_RULE7_EN              0              
 *    06    CLS_RULE6_EN              0              
 *    05    CLS_RULE5_EN              0              
 *    04    CLS_RULE4_EN              0              
 *    03    CLS_RULE3_EN              0              
 *    02    CLS_RULE2_EN              0              
 *    01    CLS_RULE1_EN              0              
 *    00    CLS_RULE0_EN              0              
 * </pre>
 */
#define RXM_RXM_CLS_EN_ADDR        (REG_RXM_BASE_ADDR+0x000001D4)
#define RXM_RXM_CLS_EN_OFFSET      0x000001D4
#define RXM_RXM_CLS_EN_INDEX       0x00000075
#define RXM_RXM_CLS_EN_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_en_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_EN_ADDR);
}

__INLINE void rxm_rxm_cls_en_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_EN_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_EN_CLS_RULE_15_EN_BIT    ((uint32_t)0x00008000)
#define RXM_RXM_CLS_EN_CLS_RULE_15_EN_POS    15
#define RXM_RXM_CLS_EN_CLS_RULE_14_EN_BIT    ((uint32_t)0x00004000)
#define RXM_RXM_CLS_EN_CLS_RULE_14_EN_POS    14
#define RXM_RXM_CLS_EN_CLS_RULE_13_EN_BIT    ((uint32_t)0x00002000)
#define RXM_RXM_CLS_EN_CLS_RULE_13_EN_POS    13
#define RXM_RXM_CLS_EN_CLS_RULE_12_EN_BIT    ((uint32_t)0x00001000)
#define RXM_RXM_CLS_EN_CLS_RULE_12_EN_POS    12
#define RXM_RXM_CLS_EN_CLS_RULE_11_EN_BIT    ((uint32_t)0x00000800)
#define RXM_RXM_CLS_EN_CLS_RULE_11_EN_POS    11
#define RXM_RXM_CLS_EN_CLS_RULE_10_EN_BIT    ((uint32_t)0x00000400)
#define RXM_RXM_CLS_EN_CLS_RULE_10_EN_POS    10
#define RXM_RXM_CLS_EN_CLS_RULE_9_EN_BIT    ((uint32_t)0x00000200)
#define RXM_RXM_CLS_EN_CLS_RULE_9_EN_POS    9
#define RXM_RXM_CLS_EN_CLS_RULE_8_EN_BIT    ((uint32_t)0x00000100)
#define RXM_RXM_CLS_EN_CLS_RULE_8_EN_POS    8
#define RXM_RXM_CLS_EN_CLS_RULE_7_EN_BIT    ((uint32_t)0x00000080)
#define RXM_RXM_CLS_EN_CLS_RULE_7_EN_POS    7
#define RXM_RXM_CLS_EN_CLS_RULE_6_EN_BIT    ((uint32_t)0x00000040)
#define RXM_RXM_CLS_EN_CLS_RULE_6_EN_POS    6
#define RXM_RXM_CLS_EN_CLS_RULE_5_EN_BIT    ((uint32_t)0x00000020)
#define RXM_RXM_CLS_EN_CLS_RULE_5_EN_POS    5
#define RXM_RXM_CLS_EN_CLS_RULE_4_EN_BIT    ((uint32_t)0x00000010)
#define RXM_RXM_CLS_EN_CLS_RULE_4_EN_POS    4
#define RXM_RXM_CLS_EN_CLS_RULE_3_EN_BIT    ((uint32_t)0x00000008)
#define RXM_RXM_CLS_EN_CLS_RULE_3_EN_POS    3
#define RXM_RXM_CLS_EN_CLS_RULE_2_EN_BIT    ((uint32_t)0x00000004)
#define RXM_RXM_CLS_EN_CLS_RULE_2_EN_POS    2
#define RXM_RXM_CLS_EN_CLS_RULE_1_EN_BIT    ((uint32_t)0x00000002)
#define RXM_RXM_CLS_EN_CLS_RULE_1_EN_POS    1
#define RXM_RXM_CLS_EN_CLS_RULE_0_EN_BIT    ((uint32_t)0x00000001)
#define RXM_RXM_CLS_EN_CLS_RULE_0_EN_POS    0

#define RXM_RXM_CLS_EN_CLS_RULE_15_EN_RST    0x0
#define RXM_RXM_CLS_EN_CLS_RULE_14_EN_RST    0x0
#define RXM_RXM_CLS_EN_CLS_RULE_13_EN_RST    0x0
#define RXM_RXM_CLS_EN_CLS_RULE_12_EN_RST    0x0
#define RXM_RXM_CLS_EN_CLS_RULE_11_EN_RST    0x0
#define RXM_RXM_CLS_EN_CLS_RULE_10_EN_RST    0x0
#define RXM_RXM_CLS_EN_CLS_RULE_9_EN_RST    0x0
#define RXM_RXM_CLS_EN_CLS_RULE_8_EN_RST    0x0
#define RXM_RXM_CLS_EN_CLS_RULE_7_EN_RST    0x0
#define RXM_RXM_CLS_EN_CLS_RULE_6_EN_RST    0x0
#define RXM_RXM_CLS_EN_CLS_RULE_5_EN_RST    0x0
#define RXM_RXM_CLS_EN_CLS_RULE_4_EN_RST    0x0
#define RXM_RXM_CLS_EN_CLS_RULE_3_EN_RST    0x0
#define RXM_RXM_CLS_EN_CLS_RULE_2_EN_RST    0x0
#define RXM_RXM_CLS_EN_CLS_RULE_1_EN_RST    0x0
#define RXM_RXM_CLS_EN_CLS_RULE_0_EN_RST    0x0

__INLINE void rxm_rxm_cls_en_pack(uint8_t cls_rule15_en, uint8_t cls_rule14_en, uint8_t cls_rule13_en, uint8_t cls_rule12_en, uint8_t cls_rule11_en, uint8_t cls_rule10_en, uint8_t cls_rule9_en, uint8_t cls_rule8_en, uint8_t cls_rule7_en, uint8_t cls_rule6_en, uint8_t cls_rule5_en, uint8_t cls_rule4_en, uint8_t cls_rule3_en, uint8_t cls_rule2_en, uint8_t cls_rule1_en, uint8_t cls_rule0_en)
{
	ASSERT_ERR((((uint32_t)cls_rule15_en << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)cls_rule14_en << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)cls_rule13_en << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)cls_rule12_en << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)cls_rule11_en << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)cls_rule10_en << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)cls_rule9_en << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)cls_rule8_en << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)cls_rule7_en << 7) & ~((uint32_t)0x00000080)) == 0);
	ASSERT_ERR((((uint32_t)cls_rule6_en << 6) & ~((uint32_t)0x00000040)) == 0);
	ASSERT_ERR((((uint32_t)cls_rule5_en << 5) & ~((uint32_t)0x00000020)) == 0);
	ASSERT_ERR((((uint32_t)cls_rule4_en << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)cls_rule3_en << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)cls_rule2_en << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)cls_rule1_en << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)cls_rule0_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RXM_RXM_CLS_EN_ADDR,  ((uint32_t)cls_rule15_en << 15) |((uint32_t)cls_rule14_en << 14) |((uint32_t)cls_rule13_en << 13) |((uint32_t)cls_rule12_en << 12) |((uint32_t)cls_rule11_en << 11) |((uint32_t)cls_rule10_en << 10) |((uint32_t)cls_rule9_en << 9) |((uint32_t)cls_rule8_en << 8) |((uint32_t)cls_rule7_en << 7) |((uint32_t)cls_rule6_en << 6) |((uint32_t)cls_rule5_en << 5) |((uint32_t)cls_rule4_en << 4) |((uint32_t)cls_rule3_en << 3) |((uint32_t)cls_rule2_en << 2) |((uint32_t)cls_rule1_en << 1) |((uint32_t)cls_rule0_en << 0));
}

__INLINE void rxm_rxm_cls_en_unpack(uint8_t* cls_rule15_en, uint8_t* cls_rule14_en, uint8_t* cls_rule13_en, uint8_t* cls_rule12_en, uint8_t* cls_rule11_en, uint8_t* cls_rule10_en, uint8_t* cls_rule9_en, uint8_t* cls_rule8_en, uint8_t* cls_rule7_en, uint8_t* cls_rule6_en, uint8_t* cls_rule5_en, uint8_t* cls_rule4_en, uint8_t* cls_rule3_en, uint8_t* cls_rule2_en, uint8_t* cls_rule1_en, uint8_t* cls_rule0_en)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_EN_ADDR);

	*cls_rule15_en = (localVal & ((uint32_t)0x00008000)) >>  15;
	*cls_rule14_en = (localVal & ((uint32_t)0x00004000)) >>  14;
	*cls_rule13_en = (localVal & ((uint32_t)0x00002000)) >>  13;
	*cls_rule12_en = (localVal & ((uint32_t)0x00001000)) >>  12;
	*cls_rule11_en = (localVal & ((uint32_t)0x00000800)) >>  11;
	*cls_rule10_en = (localVal & ((uint32_t)0x00000400)) >>  10;
	*cls_rule9_en = (localVal & ((uint32_t)0x00000200)) >>  9;
	*cls_rule8_en = (localVal & ((uint32_t)0x00000100)) >>  8;
	*cls_rule7_en = (localVal & ((uint32_t)0x00000080)) >>  7;
	*cls_rule6_en = (localVal & ((uint32_t)0x00000040)) >>  6;
	*cls_rule5_en = (localVal & ((uint32_t)0x00000020)) >>  5;
	*cls_rule4_en = (localVal & ((uint32_t)0x00000010)) >>  4;
	*cls_rule3_en = (localVal & ((uint32_t)0x00000008)) >>  3;
	*cls_rule2_en = (localVal & ((uint32_t)0x00000004)) >>  2;
	*cls_rule1_en = (localVal & ((uint32_t)0x00000002)) >>  1;
	*cls_rule0_en = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t rxm_rxm_cls_en_cls_rule_15_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void rxm_rxm_cls_en_cls_rule_15_en_setf(uint8_t clsrule15en)
{
	ASSERT_ERR((((uint32_t)clsrule15en << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(RXM_RXM_CLS_EN_ADDR, (REG_PL_RD(RXM_RXM_CLS_EN_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)clsrule15en <<15));
}
__INLINE uint8_t rxm_rxm_cls_en_cls_rule_14_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void rxm_rxm_cls_en_cls_rule_14_en_setf(uint8_t clsrule14en)
{
	ASSERT_ERR((((uint32_t)clsrule14en << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(RXM_RXM_CLS_EN_ADDR, (REG_PL_RD(RXM_RXM_CLS_EN_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)clsrule14en <<14));
}
__INLINE uint8_t rxm_rxm_cls_en_cls_rule_13_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void rxm_rxm_cls_en_cls_rule_13_en_setf(uint8_t clsrule13en)
{
	ASSERT_ERR((((uint32_t)clsrule13en << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(RXM_RXM_CLS_EN_ADDR, (REG_PL_RD(RXM_RXM_CLS_EN_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)clsrule13en <<13));
}
__INLINE uint8_t rxm_rxm_cls_en_cls_rule_12_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void rxm_rxm_cls_en_cls_rule_12_en_setf(uint8_t clsrule12en)
{
	ASSERT_ERR((((uint32_t)clsrule12en << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(RXM_RXM_CLS_EN_ADDR, (REG_PL_RD(RXM_RXM_CLS_EN_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)clsrule12en <<12));
}
__INLINE uint8_t rxm_rxm_cls_en_cls_rule_11_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void rxm_rxm_cls_en_cls_rule_11_en_setf(uint8_t clsrule11en)
{
	ASSERT_ERR((((uint32_t)clsrule11en << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(RXM_RXM_CLS_EN_ADDR, (REG_PL_RD(RXM_RXM_CLS_EN_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)clsrule11en <<11));
}
__INLINE uint8_t rxm_rxm_cls_en_cls_rule_10_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void rxm_rxm_cls_en_cls_rule_10_en_setf(uint8_t clsrule10en)
{
	ASSERT_ERR((((uint32_t)clsrule10en << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(RXM_RXM_CLS_EN_ADDR, (REG_PL_RD(RXM_RXM_CLS_EN_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)clsrule10en <<10));
}
__INLINE uint8_t rxm_rxm_cls_en_cls_rule_9_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void rxm_rxm_cls_en_cls_rule_9_en_setf(uint8_t clsrule9en)
{
	ASSERT_ERR((((uint32_t)clsrule9en << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(RXM_RXM_CLS_EN_ADDR, (REG_PL_RD(RXM_RXM_CLS_EN_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)clsrule9en <<9));
}
__INLINE uint8_t rxm_rxm_cls_en_cls_rule_8_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void rxm_rxm_cls_en_cls_rule_8_en_setf(uint8_t clsrule8en)
{
	ASSERT_ERR((((uint32_t)clsrule8en << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(RXM_RXM_CLS_EN_ADDR, (REG_PL_RD(RXM_RXM_CLS_EN_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)clsrule8en <<8));
}
__INLINE uint8_t rxm_rxm_cls_en_cls_rule_7_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE void rxm_rxm_cls_en_cls_rule_7_en_setf(uint8_t clsrule7en)
{
	ASSERT_ERR((((uint32_t)clsrule7en << 7) & ~((uint32_t)0x00000080)) == 0);
	REG_PL_WR(RXM_RXM_CLS_EN_ADDR, (REG_PL_RD(RXM_RXM_CLS_EN_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)clsrule7en <<7));
}
__INLINE uint8_t rxm_rxm_cls_en_cls_rule_6_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE void rxm_rxm_cls_en_cls_rule_6_en_setf(uint8_t clsrule6en)
{
	ASSERT_ERR((((uint32_t)clsrule6en << 6) & ~((uint32_t)0x00000040)) == 0);
	REG_PL_WR(RXM_RXM_CLS_EN_ADDR, (REG_PL_RD(RXM_RXM_CLS_EN_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)clsrule6en <<6));
}
__INLINE uint8_t rxm_rxm_cls_en_cls_rule_5_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE void rxm_rxm_cls_en_cls_rule_5_en_setf(uint8_t clsrule5en)
{
	ASSERT_ERR((((uint32_t)clsrule5en << 5) & ~((uint32_t)0x00000020)) == 0);
	REG_PL_WR(RXM_RXM_CLS_EN_ADDR, (REG_PL_RD(RXM_RXM_CLS_EN_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)clsrule5en <<5));
}
__INLINE uint8_t rxm_rxm_cls_en_cls_rule_4_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void rxm_rxm_cls_en_cls_rule_4_en_setf(uint8_t clsrule4en)
{
	ASSERT_ERR((((uint32_t)clsrule4en << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(RXM_RXM_CLS_EN_ADDR, (REG_PL_RD(RXM_RXM_CLS_EN_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)clsrule4en <<4));
}
__INLINE uint8_t rxm_rxm_cls_en_cls_rule_3_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void rxm_rxm_cls_en_cls_rule_3_en_setf(uint8_t clsrule3en)
{
	ASSERT_ERR((((uint32_t)clsrule3en << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(RXM_RXM_CLS_EN_ADDR, (REG_PL_RD(RXM_RXM_CLS_EN_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)clsrule3en <<3));
}
__INLINE uint8_t rxm_rxm_cls_en_cls_rule_2_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void rxm_rxm_cls_en_cls_rule_2_en_setf(uint8_t clsrule2en)
{
	ASSERT_ERR((((uint32_t)clsrule2en << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(RXM_RXM_CLS_EN_ADDR, (REG_PL_RD(RXM_RXM_CLS_EN_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)clsrule2en <<2));
}
__INLINE uint8_t rxm_rxm_cls_en_cls_rule_1_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void rxm_rxm_cls_en_cls_rule_1_en_setf(uint8_t clsrule1en)
{
	ASSERT_ERR((((uint32_t)clsrule1en << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(RXM_RXM_CLS_EN_ADDR, (REG_PL_RD(RXM_RXM_CLS_EN_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)clsrule1en <<1));
}
__INLINE uint8_t rxm_rxm_cls_en_cls_rule_0_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void rxm_rxm_cls_en_cls_rule_0_en_setf(uint8_t clsrule0en)
{
	ASSERT_ERR((((uint32_t)clsrule0en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RXM_RXM_CLS_EN_ADDR, (REG_PL_RD(RXM_RXM_CLS_EN_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)clsrule0en <<0));
}

/**
 * @brief RXM_CLS_RHD_RD_WS register definition
 *  WS cycles before reading RHD info register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    07:00 CLS_RHD_RD_WS             0x0
 * </pre>
 */
#define RXM_RXM_CLS_RHD_RD_WS_ADDR        (REG_RXM_BASE_ADDR+0x000001D8)
#define RXM_RXM_CLS_RHD_RD_WS_OFFSET      0x000001D8
#define RXM_RXM_CLS_RHD_RD_WS_INDEX       0x00000076
#define RXM_RXM_CLS_RHD_RD_WS_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_rhd_rd_ws_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_RHD_RD_WS_ADDR);
}

__INLINE void rxm_rxm_cls_rhd_rd_ws_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_CLS_RHD_RD_WS_ADDR, value);
}

// field definitions
#define RXM_RXM_CLS_RHD_RD_WS_CLS_RHD_RD_WS_MASK    ((uint32_t)0x000000FF)
#define RXM_RXM_CLS_RHD_RD_WS_CLS_RHD_RD_WS_LSB    0
#define RXM_RXM_CLS_RHD_RD_WS_CLS_RHD_RD_WS_WIDTH    ((uint32_t)0x00000008)

#define RXM_RXM_CLS_RHD_RD_WS_CLS_RHD_RD_WS_RST    0x0

__INLINE uint8_t rxm_rxm_cls_rhd_rd_ws_cls_rhd_rd_ws_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_RHD_RD_WS_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void rxm_rxm_cls_rhd_rd_ws_cls_rhd_rd_ws_setf(uint8_t clsrhdrdws)
{
	ASSERT_ERR((((uint32_t)clsrhdrdws << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RXM_RXM_CLS_RHD_RD_WS_ADDR, (uint32_t)clsrhdrdws << 0);
}

/**
 * @brief RXM_CLS_FW_CNT register definition
 *  Fwd to FW MPDUs counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 FWD_FW_CNT                0x0
 * </pre>
 */
#define RXM_RXM_CLS_FW_CNT_ADDR        (REG_RXM_BASE_ADDR+0x000001E0)
#define RXM_RXM_CLS_FW_CNT_OFFSET      0x000001E0
#define RXM_RXM_CLS_FW_CNT_INDEX       0x00000078
#define RXM_RXM_CLS_FW_CNT_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_fw_cnt_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_FW_CNT_ADDR);
}

// field definitions
#define RXM_RXM_CLS_FW_CNT_FWD_FW_CNT_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_CLS_FW_CNT_FWD_FW_CNT_LSB    0
#define RXM_RXM_CLS_FW_CNT_FWD_FW_CNT_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_CLS_FW_CNT_FWD_FW_CNT_RST    0x0

__INLINE uint32_t rxm_rxm_cls_fw_cnt_fwd_fw_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_FW_CNT_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RXM_CLS_HOST_CNT register definition
 *  Fwd to host MPDUs counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 FWD_HOST_CNT              0x0
 * </pre>
 */
#define RXM_RXM_CLS_HOST_CNT_ADDR        (REG_RXM_BASE_ADDR+0x000001E4)
#define RXM_RXM_CLS_HOST_CNT_OFFSET      0x000001E4
#define RXM_RXM_CLS_HOST_CNT_INDEX       0x00000079
#define RXM_RXM_CLS_HOST_CNT_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_host_cnt_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_HOST_CNT_ADDR);
}

// field definitions
#define RXM_RXM_CLS_HOST_CNT_FWD_HOST_CNT_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_CLS_HOST_CNT_FWD_HOST_CNT_LSB    0
#define RXM_RXM_CLS_HOST_CNT_FWD_HOST_CNT_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_CLS_HOST_CNT_FWD_HOST_CNT_RST    0x0

__INLINE uint32_t rxm_rxm_cls_host_cnt_fwd_host_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_HOST_CNT_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RXM_CLS_DISCARD_CNT register definition
 *  Discarded MPDUs counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DISCARD_CNT               0x0
 * </pre>
 */
#define RXM_RXM_CLS_DISCARD_CNT_ADDR        (REG_RXM_BASE_ADDR+0x000001E8)
#define RXM_RXM_CLS_DISCARD_CNT_OFFSET      0x000001E8
#define RXM_RXM_CLS_DISCARD_CNT_INDEX       0x0000007A
#define RXM_RXM_CLS_DISCARD_CNT_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_cls_discard_cnt_get(void)
{
	return REG_PL_RD(RXM_RXM_CLS_DISCARD_CNT_ADDR);
}

// field definitions
#define RXM_RXM_CLS_DISCARD_CNT_DISCARD_CNT_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_CLS_DISCARD_CNT_DISCARD_CNT_LSB    0
#define RXM_RXM_CLS_DISCARD_CNT_DISCARD_CNT_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_CLS_DISCARD_CNT_DISCARD_CNT_RST    0x0

__INLINE uint32_t rxm_rxm_cls_discard_cnt_discard_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_CLS_DISCARD_CNT_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RXM_W_2_E_BUFF_START_ADDR register definition
 *  W2E scratch buffer start address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 W2_E_BUFF_START_ADDR      0x0
 * </pre>
 */
#define RXM_RXM_W_2_E_BUFF_START_ADDR_ADDR        (REG_RXM_BASE_ADDR+0x000001F0)
#define RXM_RXM_W_2_E_BUFF_START_ADDR_OFFSET      0x000001F0
#define RXM_RXM_W_2_E_BUFF_START_ADDR_INDEX       0x0000007C
#define RXM_RXM_W_2_E_BUFF_START_ADDR_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_w_2_e_buff_start_addr_get(void)
{
	return REG_PL_RD(RXM_RXM_W_2_E_BUFF_START_ADDR_ADDR);
}

__INLINE void rxm_rxm_w_2_e_buff_start_addr_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_W_2_E_BUFF_START_ADDR_ADDR, value);
}

// field definitions
#define RXM_RXM_W_2_E_BUFF_START_ADDR_W_2_E_BUFF_START_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_W_2_E_BUFF_START_ADDR_W_2_E_BUFF_START_ADDR_LSB    0
#define RXM_RXM_W_2_E_BUFF_START_ADDR_W_2_E_BUFF_START_ADDR_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_W_2_E_BUFF_START_ADDR_W_2_E_BUFF_START_ADDR_RST    0x0

__INLINE uint32_t rxm_rxm_w_2_e_buff_start_addr_w_2_e_buff_start_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_W_2_E_BUFF_START_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_w_2_e_buff_start_addr_w_2_e_buff_start_addr_setf(uint32_t w2ebuffstartaddr)
{
	ASSERT_ERR((((uint32_t)w2ebuffstartaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_W_2_E_BUFF_START_ADDR_ADDR, (uint32_t)w2ebuffstartaddr << 0);
}

/**
 * @brief RXM_W_2_E_BUFF_SIZE register definition
 *  W2E scratch buffer size  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 W2_E_BUFF_SIZE            0x80
 * </pre>
 */
#define RXM_RXM_W_2_E_BUFF_SIZE_ADDR        (REG_RXM_BASE_ADDR+0x000001F4)
#define RXM_RXM_W_2_E_BUFF_SIZE_OFFSET      0x000001F4
#define RXM_RXM_W_2_E_BUFF_SIZE_INDEX       0x0000007D
#define RXM_RXM_W_2_E_BUFF_SIZE_RESET       0x00000080

__INLINE uint32_t  rxm_rxm_w_2_e_buff_size_get(void)
{
	return REG_PL_RD(RXM_RXM_W_2_E_BUFF_SIZE_ADDR);
}

__INLINE void rxm_rxm_w_2_e_buff_size_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_W_2_E_BUFF_SIZE_ADDR, value);
}

// field definitions
#define RXM_RXM_W_2_E_BUFF_SIZE_W_2_E_BUFF_SIZE_MASK    ((uint32_t)0x0000FFFF)
#define RXM_RXM_W_2_E_BUFF_SIZE_W_2_E_BUFF_SIZE_LSB    0
#define RXM_RXM_W_2_E_BUFF_SIZE_W_2_E_BUFF_SIZE_WIDTH    ((uint32_t)0x00000010)

#define RXM_RXM_W_2_E_BUFF_SIZE_W_2_E_BUFF_SIZE_RST    0x80

__INLINE uint16_t rxm_rxm_w_2_e_buff_size_w_2_e_buff_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_W_2_E_BUFF_SIZE_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void rxm_rxm_w_2_e_buff_size_w_2_e_buff_size_setf(uint16_t w2ebuffsize)
{
	ASSERT_ERR((((uint32_t)w2ebuffsize << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(RXM_RXM_W_2_E_BUFF_SIZE_ADDR, (uint32_t)w2ebuffsize << 0);
}

/**
 * @brief RXM_W_2_E_BUFF_CURR_ADDR register definition
 *  Current scratch buffer address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 W2_E_BUFF_CURR_ADDR       0x0
 * </pre>
 */
#define RXM_RXM_W_2_E_BUFF_CURR_ADDR_ADDR        (REG_RXM_BASE_ADDR+0x000001F8)
#define RXM_RXM_W_2_E_BUFF_CURR_ADDR_OFFSET      0x000001F8
#define RXM_RXM_W_2_E_BUFF_CURR_ADDR_INDEX       0x0000007E
#define RXM_RXM_W_2_E_BUFF_CURR_ADDR_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_w_2_e_buff_curr_addr_get(void)
{
	return REG_PL_RD(RXM_RXM_W_2_E_BUFF_CURR_ADDR_ADDR);
}

// field definitions
#define RXM_RXM_W_2_E_BUFF_CURR_ADDR_W_2_E_BUFF_CURR_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_W_2_E_BUFF_CURR_ADDR_W_2_E_BUFF_CURR_ADDR_LSB    0
#define RXM_RXM_W_2_E_BUFF_CURR_ADDR_W_2_E_BUFF_CURR_ADDR_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_W_2_E_BUFF_CURR_ADDR_W_2_E_BUFF_CURR_ADDR_RST    0x0

__INLINE uint32_t rxm_rxm_w_2_e_buff_curr_addr_w_2_e_buff_curr_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_W_2_E_BUFF_CURR_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RXM_W_2_E_DBG register definition
 *  W2E debug register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:05 W2_E_INFO                 0x40042
 *    04:00 W2_E_SM                   0x0
 * </pre>
 */
#define RXM_RXM_W_2_E_DBG_ADDR        (REG_RXM_BASE_ADDR+0x000001FC)
#define RXM_RXM_W_2_E_DBG_OFFSET      0x000001FC
#define RXM_RXM_W_2_E_DBG_INDEX       0x0000007F
#define RXM_RXM_W_2_E_DBG_RESET       0x00800840

__INLINE uint32_t  rxm_rxm_w_2_e_dbg_get(void)
{
	return REG_PL_RD(RXM_RXM_W_2_E_DBG_ADDR);
}

// field definitions
#define RXM_RXM_W_2_E_DBG_W_2_E_INFO_MASK    ((uint32_t)0xFFFFFFE0)
#define RXM_RXM_W_2_E_DBG_W_2_E_INFO_LSB    5
#define RXM_RXM_W_2_E_DBG_W_2_E_INFO_WIDTH    ((uint32_t)0x0000001B)
#define RXM_RXM_W_2_E_DBG_W_2_E_SM_MASK     ((uint32_t)0x0000001F)
#define RXM_RXM_W_2_E_DBG_W_2_E_SM_LSB      0
#define RXM_RXM_W_2_E_DBG_W_2_E_SM_WIDTH    ((uint32_t)0x00000005)

#define RXM_RXM_W_2_E_DBG_W_2_E_INFO_RST    0x40042
#define RXM_RXM_W_2_E_DBG_W_2_E_SM_RST      0x0

__INLINE void rxm_rxm_w_2_e_dbg_unpack(uint32_t* w2_e_info, uint8_t* w2_e_sm)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_W_2_E_DBG_ADDR);

	*w2_e_info = (localVal & ((uint32_t)0xFFFFFFE0)) >>  5;
	*w2_e_sm = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint32_t rxm_rxm_w_2_e_dbg_w_2_e_info_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_W_2_E_DBG_ADDR);
	return (uint32_t)((localVal & ((uint32_t)0xFFFFFFE0)) >> 5);
}
__INLINE uint8_t rxm_rxm_w_2_e_dbg_w_2_e_sm_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_W_2_E_DBG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}

/**
 * @brief RXM_SIZE_LIMIT register definition
 *  HB size and #MSDU limit register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:16 MAX_MSDU_NUM              0x80
 *    15:00 MAX_HB_DATA_SIZE          0x62c
 * </pre>
 */
#define RXM_RXM_SIZE_LIMIT_ADDR        (REG_RXM_BASE_ADDR+0x00000200)
#define RXM_RXM_SIZE_LIMIT_OFFSET      0x00000200
#define RXM_RXM_SIZE_LIMIT_INDEX       0x00000080
#define RXM_RXM_SIZE_LIMIT_RESET       0x0080062C

__INLINE uint32_t  rxm_rxm_size_limit_get(void)
{
	return REG_PL_RD(RXM_RXM_SIZE_LIMIT_ADDR);
}

__INLINE void rxm_rxm_size_limit_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_SIZE_LIMIT_ADDR, value);
}

// field definitions
#define RXM_RXM_SIZE_LIMIT_MAX_MSDU_NUM_MASK    ((uint32_t)0x00FF0000)
#define RXM_RXM_SIZE_LIMIT_MAX_MSDU_NUM_LSB    16
#define RXM_RXM_SIZE_LIMIT_MAX_MSDU_NUM_WIDTH    ((uint32_t)0x00000008)
#define RXM_RXM_SIZE_LIMIT_MAX_HB_DATA_SIZE_MASK    ((uint32_t)0x0000FFFF)
#define RXM_RXM_SIZE_LIMIT_MAX_HB_DATA_SIZE_LSB    0
#define RXM_RXM_SIZE_LIMIT_MAX_HB_DATA_SIZE_WIDTH    ((uint32_t)0x00000010)

#define RXM_RXM_SIZE_LIMIT_MAX_MSDU_NUM_RST    0x80
#define RXM_RXM_SIZE_LIMIT_MAX_HB_DATA_SIZE_RST    0x62c

__INLINE void rxm_rxm_size_limit_pack(uint8_t max_msdu_num, uint16_t max_hb_data_size)
{
	ASSERT_ERR((((uint32_t)max_msdu_num << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)max_hb_data_size << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(RXM_RXM_SIZE_LIMIT_ADDR,  ((uint32_t)max_msdu_num << 16) |((uint32_t)max_hb_data_size << 0));
}

__INLINE void rxm_rxm_size_limit_unpack(uint8_t* max_msdu_num, uint16_t* max_hb_data_size)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_SIZE_LIMIT_ADDR);

	*max_msdu_num = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*max_hb_data_size = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint8_t rxm_rxm_size_limit_max_msdu_num_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_SIZE_LIMIT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void rxm_rxm_size_limit_max_msdu_num_setf(uint8_t maxmsdunum)
{
	ASSERT_ERR((((uint32_t)maxmsdunum << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(RXM_RXM_SIZE_LIMIT_ADDR, (REG_PL_RD(RXM_RXM_SIZE_LIMIT_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)maxmsdunum <<16));
}
__INLINE uint16_t rxm_rxm_size_limit_max_hb_data_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_SIZE_LIMIT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void rxm_rxm_size_limit_max_hb_data_size_setf(uint16_t maxhbdatasize)
{
	ASSERT_ERR((((uint32_t)maxhbdatasize << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(RXM_RXM_SIZE_LIMIT_ADDR, (REG_PL_RD(RXM_RXM_SIZE_LIMIT_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)maxhbdatasize <<0));
}

/**
 * @brief RXM_INFO_OFFSET register definition
 *  Various LLI offsets configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28:20 HB_PAYLOAD_OFFSET         0x80
 *    19:10 LLI_RPD_OFFSET            0x14
 *    09:00 LLI_RHD_OFFSET            0x5c
 * </pre>
 */
#define RXM_RXM_INFO_OFFSET_ADDR        (REG_RXM_BASE_ADDR+0x00000204)
#define RXM_RXM_INFO_OFFSET_OFFSET      0x00000204
#define RXM_RXM_INFO_OFFSET_INDEX       0x00000081
#define RXM_RXM_INFO_OFFSET_RESET       0x0800505C

__INLINE uint32_t  rxm_rxm_info_offset_get(void)
{
	return REG_PL_RD(RXM_RXM_INFO_OFFSET_ADDR);
}

__INLINE void rxm_rxm_info_offset_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_INFO_OFFSET_ADDR, value);
}

// field definitions
#define RXM_RXM_INFO_OFFSET_HB_PAYLOAD_OFFSET_MASK    ((uint32_t)0x1FF00000)
#define RXM_RXM_INFO_OFFSET_HB_PAYLOAD_OFFSET_LSB    20
#define RXM_RXM_INFO_OFFSET_HB_PAYLOAD_OFFSET_WIDTH    ((uint32_t)0x00000009)
#define RXM_RXM_INFO_OFFSET_LLI_RPD_OFFSET_MASK    ((uint32_t)0x000FFC00)
#define RXM_RXM_INFO_OFFSET_LLI_RPD_OFFSET_LSB    10
#define RXM_RXM_INFO_OFFSET_LLI_RPD_OFFSET_WIDTH    ((uint32_t)0x0000000A)
#define RXM_RXM_INFO_OFFSET_LLI_RHD_OFFSET_MASK    ((uint32_t)0x000003FF)
#define RXM_RXM_INFO_OFFSET_LLI_RHD_OFFSET_LSB    0
#define RXM_RXM_INFO_OFFSET_LLI_RHD_OFFSET_WIDTH    ((uint32_t)0x0000000A)

#define RXM_RXM_INFO_OFFSET_HB_PAYLOAD_OFFSET_RST    0x80
#define RXM_RXM_INFO_OFFSET_LLI_RPD_OFFSET_RST    0x14
#define RXM_RXM_INFO_OFFSET_LLI_RHD_OFFSET_RST    0x5c

__INLINE void rxm_rxm_info_offset_pack(uint16_t hb_payload_offset, uint16_t lli_rpd_offset, uint16_t lli_rhd_offset)
{
	ASSERT_ERR((((uint32_t)hb_payload_offset << 20) & ~((uint32_t)0x1FF00000)) == 0);
	ASSERT_ERR((((uint32_t)lli_rpd_offset << 10) & ~((uint32_t)0x000FFC00)) == 0);
	ASSERT_ERR((((uint32_t)lli_rhd_offset << 0) & ~((uint32_t)0x000003FF)) == 0);
	REG_PL_WR(RXM_RXM_INFO_OFFSET_ADDR,  ((uint32_t)hb_payload_offset << 20) |((uint32_t)lli_rpd_offset << 10) |((uint32_t)lli_rhd_offset << 0));
}

__INLINE void rxm_rxm_info_offset_unpack(uint16_t* hb_payload_offset, uint16_t* lli_rpd_offset, uint16_t* lli_rhd_offset)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_INFO_OFFSET_ADDR);

	*hb_payload_offset = (localVal & ((uint32_t)0x1FF00000)) >>  20;
	*lli_rpd_offset = (localVal & ((uint32_t)0x000FFC00)) >>  10;
	*lli_rhd_offset = (localVal & ((uint32_t)0x000003FF)) >>  0;
}

__INLINE uint16_t rxm_rxm_info_offset_hb_payload_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_INFO_OFFSET_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x1FF00000)) >> 20);
}
__INLINE void rxm_rxm_info_offset_hb_payload_offset_setf(uint16_t hbpayloadoffset)
{
	ASSERT_ERR((((uint32_t)hbpayloadoffset << 20) & ~((uint32_t)0x1FF00000)) == 0);
	REG_PL_WR(RXM_RXM_INFO_OFFSET_ADDR, (REG_PL_RD(RXM_RXM_INFO_OFFSET_ADDR) & ~((uint32_t)0x1FF00000)) | ((uint32_t)hbpayloadoffset <<20));
}
__INLINE uint16_t rxm_rxm_info_offset_lli_rpd_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_INFO_OFFSET_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000FFC00)) >> 10);
}
__INLINE void rxm_rxm_info_offset_lli_rpd_offset_setf(uint16_t llirpdoffset)
{
	ASSERT_ERR((((uint32_t)llirpdoffset << 10) & ~((uint32_t)0x000FFC00)) == 0);
	REG_PL_WR(RXM_RXM_INFO_OFFSET_ADDR, (REG_PL_RD(RXM_RXM_INFO_OFFSET_ADDR) & ~((uint32_t)0x000FFC00)) | ((uint32_t)llirpdoffset <<10));
}
__INLINE uint16_t rxm_rxm_info_offset_lli_rhd_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_INFO_OFFSET_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000003FF)) >> 0);
}
__INLINE void rxm_rxm_info_offset_lli_rhd_offset_setf(uint16_t llirhdoffset)
{
	ASSERT_ERR((((uint32_t)llirhdoffset << 0) & ~((uint32_t)0x000003FF)) == 0);
	REG_PL_WR(RXM_RXM_INFO_OFFSET_ADDR, (REG_PL_RD(RXM_RXM_INFO_OFFSET_ADDR) & ~((uint32_t)0x000003FF)) | ((uint32_t)llirhdoffset <<0));
}

/**
 * @brief RXM_METADATA register definition
 *  META data size and offset for LLI register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:08 LLI_METADATA_SIZE         0x44
 *    07:00 LLI_METADATA_OFFSET       0x18
 * </pre>
 */
#define RXM_RXM_METADATA_ADDR        (REG_RXM_BASE_ADDR+0x00000208)
#define RXM_RXM_METADATA_OFFSET      0x00000208
#define RXM_RXM_METADATA_INDEX       0x00000082
#define RXM_RXM_METADATA_RESET       0x00004418

__INLINE uint32_t  rxm_rxm_metadata_get(void)
{
	return REG_PL_RD(RXM_RXM_METADATA_ADDR);
}

__INLINE void rxm_rxm_metadata_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_METADATA_ADDR, value);
}

// field definitions
#define RXM_RXM_METADATA_LLI_METADATA_SIZE_MASK    ((uint32_t)0x0000FF00)
#define RXM_RXM_METADATA_LLI_METADATA_SIZE_LSB    8
#define RXM_RXM_METADATA_LLI_METADATA_SIZE_WIDTH    ((uint32_t)0x00000008)
#define RXM_RXM_METADATA_LLI_METADATA_OFFSET_MASK    ((uint32_t)0x000000FF)
#define RXM_RXM_METADATA_LLI_METADATA_OFFSET_LSB    0
#define RXM_RXM_METADATA_LLI_METADATA_OFFSET_WIDTH    ((uint32_t)0x00000008)

#define RXM_RXM_METADATA_LLI_METADATA_SIZE_RST    0x44
#define RXM_RXM_METADATA_LLI_METADATA_OFFSET_RST    0x18

__INLINE void rxm_rxm_metadata_pack(uint8_t lli_metadata_size, uint8_t lli_metadata_offset)
{
	ASSERT_ERR((((uint32_t)lli_metadata_size << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)lli_metadata_offset << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RXM_RXM_METADATA_ADDR,  ((uint32_t)lli_metadata_size << 8) |((uint32_t)lli_metadata_offset << 0));
}

__INLINE void rxm_rxm_metadata_unpack(uint8_t* lli_metadata_size, uint8_t* lli_metadata_offset)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_METADATA_ADDR);

	*lli_metadata_size = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*lli_metadata_offset = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t rxm_rxm_metadata_lli_metadata_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_METADATA_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void rxm_rxm_metadata_lli_metadata_size_setf(uint8_t llimetadatasize)
{
	ASSERT_ERR((((uint32_t)llimetadatasize << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(RXM_RXM_METADATA_ADDR, (REG_PL_RD(RXM_RXM_METADATA_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)llimetadatasize <<8));
}
__INLINE uint8_t rxm_rxm_metadata_lli_metadata_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_METADATA_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void rxm_rxm_metadata_lli_metadata_offset_setf(uint8_t llimetadataoffset)
{
	ASSERT_ERR((((uint32_t)llimetadataoffset << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RXM_RXM_METADATA_ADDR, (REG_PL_RD(RXM_RXM_METADATA_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)llimetadataoffset <<0));
}

/**
 * @brief RXM_EXT_LLI_OVERLOAD_TH register definition
 *  External LLI pool overload threshold register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 EXT_LLI_OVERLOAD_TH       0xffff
 * </pre>
 */
#define RXM_RXM_EXT_LLI_OVERLOAD_TH_ADDR        (REG_RXM_BASE_ADDR+0x0000020C)
#define RXM_RXM_EXT_LLI_OVERLOAD_TH_OFFSET      0x0000020C
#define RXM_RXM_EXT_LLI_OVERLOAD_TH_INDEX       0x00000083
#define RXM_RXM_EXT_LLI_OVERLOAD_TH_RESET       0x0000FFFF

__INLINE uint32_t  rxm_rxm_ext_lli_overload_th_get(void)
{
	return REG_PL_RD(RXM_RXM_EXT_LLI_OVERLOAD_TH_ADDR);
}

__INLINE void rxm_rxm_ext_lli_overload_th_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_EXT_LLI_OVERLOAD_TH_ADDR, value);
}

// field definitions
#define RXM_RXM_EXT_LLI_OVERLOAD_TH_EXT_LLI_OVERLOAD_TH_MASK    ((uint32_t)0x0000FFFF)
#define RXM_RXM_EXT_LLI_OVERLOAD_TH_EXT_LLI_OVERLOAD_TH_LSB    0
#define RXM_RXM_EXT_LLI_OVERLOAD_TH_EXT_LLI_OVERLOAD_TH_WIDTH    ((uint32_t)0x00000010)

#define RXM_RXM_EXT_LLI_OVERLOAD_TH_EXT_LLI_OVERLOAD_TH_RST    0xffff

__INLINE uint16_t rxm_rxm_ext_lli_overload_th_ext_lli_overload_th_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_EXT_LLI_OVERLOAD_TH_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void rxm_rxm_ext_lli_overload_th_ext_lli_overload_th_setf(uint16_t extllioverloadth)
{
	ASSERT_ERR((((uint32_t)extllioverloadth << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(RXM_RXM_EXT_LLI_OVERLOAD_TH_ADDR, (uint32_t)extllioverloadth << 0);
}

/**
 * @brief RXM_EXT_LLI_START_ADDR register definition
 *  Ext LLI start address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 EXT_LLI_START_ADDR        0x0
 * </pre>
 */
#define RXM_RXM_EXT_LLI_START_ADDR_ADDR        (REG_RXM_BASE_ADDR+0x00000210)
#define RXM_RXM_EXT_LLI_START_ADDR_OFFSET      0x00000210
#define RXM_RXM_EXT_LLI_START_ADDR_INDEX       0x00000084
#define RXM_RXM_EXT_LLI_START_ADDR_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_ext_lli_start_addr_get(void)
{
	return REG_PL_RD(RXM_RXM_EXT_LLI_START_ADDR_ADDR);
}

__INLINE void rxm_rxm_ext_lli_start_addr_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_EXT_LLI_START_ADDR_ADDR, value);
}

// field definitions
#define RXM_RXM_EXT_LLI_START_ADDR_EXT_LLI_START_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_EXT_LLI_START_ADDR_EXT_LLI_START_ADDR_LSB    0
#define RXM_RXM_EXT_LLI_START_ADDR_EXT_LLI_START_ADDR_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_EXT_LLI_START_ADDR_EXT_LLI_START_ADDR_RST    0x0

__INLINE uint32_t rxm_rxm_ext_lli_start_addr_ext_lli_start_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_EXT_LLI_START_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_ext_lli_start_addr_ext_lli_start_addr_setf(uint32_t extllistartaddr)
{
	ASSERT_ERR((((uint32_t)extllistartaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_EXT_LLI_START_ADDR_ADDR, (uint32_t)extllistartaddr << 0);
}

/**
 * @brief RXM_EXT_LLI_SIZE register definition
 *  Ext LLI pool size register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:16 EXT_LLI_ENTRY_SIZE        0x14
 *    15:00 EXT_LLI_POOL_SIZE         0x80
 * </pre>
 */
#define RXM_RXM_EXT_LLI_SIZE_ADDR        (REG_RXM_BASE_ADDR+0x00000214)
#define RXM_RXM_EXT_LLI_SIZE_OFFSET      0x00000214
#define RXM_RXM_EXT_LLI_SIZE_INDEX       0x00000085
#define RXM_RXM_EXT_LLI_SIZE_RESET       0x00140080

__INLINE uint32_t  rxm_rxm_ext_lli_size_get(void)
{
	return REG_PL_RD(RXM_RXM_EXT_LLI_SIZE_ADDR);
}

__INLINE void rxm_rxm_ext_lli_size_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_EXT_LLI_SIZE_ADDR, value);
}

// field definitions
#define RXM_RXM_EXT_LLI_SIZE_EXT_LLI_ENTRY_SIZE_MASK    ((uint32_t)0x00FF0000)
#define RXM_RXM_EXT_LLI_SIZE_EXT_LLI_ENTRY_SIZE_LSB    16
#define RXM_RXM_EXT_LLI_SIZE_EXT_LLI_ENTRY_SIZE_WIDTH    ((uint32_t)0x00000008)
#define RXM_RXM_EXT_LLI_SIZE_EXT_LLI_POOL_SIZE_MASK    ((uint32_t)0x0000FFFF)
#define RXM_RXM_EXT_LLI_SIZE_EXT_LLI_POOL_SIZE_LSB    0
#define RXM_RXM_EXT_LLI_SIZE_EXT_LLI_POOL_SIZE_WIDTH    ((uint32_t)0x00000010)

#define RXM_RXM_EXT_LLI_SIZE_EXT_LLI_ENTRY_SIZE_RST    0x14
#define RXM_RXM_EXT_LLI_SIZE_EXT_LLI_POOL_SIZE_RST    0x80

__INLINE void rxm_rxm_ext_lli_size_pack(uint8_t ext_lli_entry_size, uint16_t ext_lli_pool_size)
{
	ASSERT_ERR((((uint32_t)ext_lli_entry_size << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)ext_lli_pool_size << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(RXM_RXM_EXT_LLI_SIZE_ADDR,  ((uint32_t)ext_lli_entry_size << 16) |((uint32_t)ext_lli_pool_size << 0));
}

__INLINE void rxm_rxm_ext_lli_size_unpack(uint8_t* ext_lli_entry_size, uint16_t* ext_lli_pool_size)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_EXT_LLI_SIZE_ADDR);

	*ext_lli_entry_size = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*ext_lli_pool_size = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint8_t rxm_rxm_ext_lli_size_ext_lli_entry_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_EXT_LLI_SIZE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void rxm_rxm_ext_lli_size_ext_lli_entry_size_setf(uint8_t extllientrysize)
{
	ASSERT_ERR((((uint32_t)extllientrysize << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(RXM_RXM_EXT_LLI_SIZE_ADDR, (REG_PL_RD(RXM_RXM_EXT_LLI_SIZE_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)extllientrysize <<16));
}
__INLINE uint16_t rxm_rxm_ext_lli_size_ext_lli_pool_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_EXT_LLI_SIZE_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void rxm_rxm_ext_lli_size_ext_lli_pool_size_setf(uint16_t extllipoolsize)
{
	ASSERT_ERR((((uint32_t)extllipoolsize << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(RXM_RXM_EXT_LLI_SIZE_ADDR, (REG_PL_RD(RXM_RXM_EXT_LLI_SIZE_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)extllipoolsize <<0));
}

/**
 * @brief RXM_LLI_DESC register definition
 *  LLI descriptor config register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    12:08 LLI_DONE_INT_NUM          0x8
 *    07:04 RPD_LIST_ID               0x0
 *    03:00 RHD_LIST_ID               0x0
 * </pre>
 */
#define RXM_RXM_LLI_DESC_ADDR        (REG_RXM_BASE_ADDR+0x00000218)
#define RXM_RXM_LLI_DESC_OFFSET      0x00000218
#define RXM_RXM_LLI_DESC_INDEX       0x00000086
#define RXM_RXM_LLI_DESC_RESET       0x00000800

__INLINE uint32_t  rxm_rxm_lli_desc_get(void)
{
	return REG_PL_RD(RXM_RXM_LLI_DESC_ADDR);
}

__INLINE void rxm_rxm_lli_desc_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_LLI_DESC_ADDR, value);
}

// field definitions
#define RXM_RXM_LLI_DESC_LLI_DONE_INT_NUM_MASK    ((uint32_t)0x00001F00)
#define RXM_RXM_LLI_DESC_LLI_DONE_INT_NUM_LSB    8
#define RXM_RXM_LLI_DESC_LLI_DONE_INT_NUM_WIDTH    ((uint32_t)0x00000005)
#define RXM_RXM_LLI_DESC_RPD_LIST_ID_MASK    ((uint32_t)0x000000F0)
#define RXM_RXM_LLI_DESC_RPD_LIST_ID_LSB    4
#define RXM_RXM_LLI_DESC_RPD_LIST_ID_WIDTH    ((uint32_t)0x00000004)
#define RXM_RXM_LLI_DESC_RHD_LIST_ID_MASK    ((uint32_t)0x0000000F)
#define RXM_RXM_LLI_DESC_RHD_LIST_ID_LSB    0
#define RXM_RXM_LLI_DESC_RHD_LIST_ID_WIDTH    ((uint32_t)0x00000004)

#define RXM_RXM_LLI_DESC_LLI_DONE_INT_NUM_RST    0x8
#define RXM_RXM_LLI_DESC_RPD_LIST_ID_RST    0x0
#define RXM_RXM_LLI_DESC_RHD_LIST_ID_RST    0x0

__INLINE void rxm_rxm_lli_desc_pack(uint8_t lli_done_int_num, uint8_t rpd_list_id, uint8_t rhd_list_id)
{
	ASSERT_ERR((((uint32_t)lli_done_int_num << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)rpd_list_id << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)rhd_list_id << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RXM_RXM_LLI_DESC_ADDR,  ((uint32_t)lli_done_int_num << 8) |((uint32_t)rpd_list_id << 4) |((uint32_t)rhd_list_id << 0));
}

__INLINE void rxm_rxm_lli_desc_unpack(uint8_t* lli_done_int_num, uint8_t* rpd_list_id, uint8_t* rhd_list_id)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_LLI_DESC_ADDR);

	*lli_done_int_num = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*rpd_list_id = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*rhd_list_id = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t rxm_rxm_lli_desc_lli_done_int_num_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_LLI_DESC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void rxm_rxm_lli_desc_lli_done_int_num_setf(uint8_t llidoneintnum)
{
	ASSERT_ERR((((uint32_t)llidoneintnum << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(RXM_RXM_LLI_DESC_ADDR, (REG_PL_RD(RXM_RXM_LLI_DESC_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)llidoneintnum <<8));
}
__INLINE uint8_t rxm_rxm_lli_desc_rpd_list_id_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_LLI_DESC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE void rxm_rxm_lli_desc_rpd_list_id_setf(uint8_t rpdlistid)
{
	ASSERT_ERR((((uint32_t)rpdlistid << 4) & ~((uint32_t)0x000000F0)) == 0);
	REG_PL_WR(RXM_RXM_LLI_DESC_ADDR, (REG_PL_RD(RXM_RXM_LLI_DESC_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)rpdlistid <<4));
}
__INLINE uint8_t rxm_rxm_lli_desc_rhd_list_id_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_LLI_DESC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void rxm_rxm_lli_desc_rhd_list_id_setf(uint8_t rhdlistid)
{
	ASSERT_ERR((((uint32_t)rhdlistid << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RXM_RXM_LLI_DESC_ADDR, (REG_PL_RD(RXM_RXM_LLI_DESC_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)rhdlistid <<0));
}

/**
 * @brief RXM_PCIEW_BASE_ADDR register definition
 *  PCIeW base addr register address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PCIEW_UX_LLI_BASE_ADDR    0x0
 * </pre>
 */
#define RXM_RXM_PCIEW_BASE_ADDR_ADDR        (REG_RXM_BASE_ADDR+0x0000021C)
#define RXM_RXM_PCIEW_BASE_ADDR_OFFSET      0x0000021C
#define RXM_RXM_PCIEW_BASE_ADDR_INDEX       0x00000087
#define RXM_RXM_PCIEW_BASE_ADDR_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_pciew_base_addr_get(void)
{
	return REG_PL_RD(RXM_RXM_PCIEW_BASE_ADDR_ADDR);
}

__INLINE void rxm_rxm_pciew_base_addr_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_PCIEW_BASE_ADDR_ADDR, value);
}

// field definitions
#define RXM_RXM_PCIEW_BASE_ADDR_PCIEW_UX_LLI_BASE_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_PCIEW_BASE_ADDR_PCIEW_UX_LLI_BASE_ADDR_LSB    0
#define RXM_RXM_PCIEW_BASE_ADDR_PCIEW_UX_LLI_BASE_ADDR_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_PCIEW_BASE_ADDR_PCIEW_UX_LLI_BASE_ADDR_RST    0x0

__INLINE uint32_t rxm_rxm_pciew_base_addr_pciew_ux_lli_base_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PCIEW_BASE_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_pciew_base_addr_pciew_ux_lli_base_addr_setf(uint32_t pciewuxllibaseaddr)
{
	ASSERT_ERR((((uint32_t)pciewuxllibaseaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_PCIEW_BASE_ADDR_ADDR, (uint32_t)pciewuxllibaseaddr << 0);
}

/**
 * @brief RXM_PCIEW_LLI_CNT_ADDR register definition
 *  PCIeW LLI cnt register address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PCIEW_UX_LLI_CTL_ADDR     0x0
 * </pre>
 */
#define RXM_RXM_PCIEW_LLI_CNT_ADDR_ADDR        (REG_RXM_BASE_ADDR+0x00000220)
#define RXM_RXM_PCIEW_LLI_CNT_ADDR_OFFSET      0x00000220
#define RXM_RXM_PCIEW_LLI_CNT_ADDR_INDEX       0x00000088
#define RXM_RXM_PCIEW_LLI_CNT_ADDR_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_pciew_lli_cnt_addr_get(void)
{
	return REG_PL_RD(RXM_RXM_PCIEW_LLI_CNT_ADDR_ADDR);
}

__INLINE void rxm_rxm_pciew_lli_cnt_addr_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_PCIEW_LLI_CNT_ADDR_ADDR, value);
}

// field definitions
#define RXM_RXM_PCIEW_LLI_CNT_ADDR_PCIEW_UX_LLI_CTL_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_PCIEW_LLI_CNT_ADDR_PCIEW_UX_LLI_CTL_ADDR_LSB    0
#define RXM_RXM_PCIEW_LLI_CNT_ADDR_PCIEW_UX_LLI_CTL_ADDR_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_PCIEW_LLI_CNT_ADDR_PCIEW_UX_LLI_CTL_ADDR_RST    0x0

__INLINE uint32_t rxm_rxm_pciew_lli_cnt_addr_pciew_ux_lli_ctl_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PCIEW_LLI_CNT_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_pciew_lli_cnt_addr_pciew_ux_lli_ctl_addr_setf(uint32_t pciewuxllictladdr)
{
	ASSERT_ERR((((uint32_t)pciewuxllictladdr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_PCIEW_LLI_CNT_ADDR_ADDR, (uint32_t)pciewuxllictladdr << 0);
}

/**
 * @brief RXM_PCIEW_INT_CLR_ADDR register definition
 *  PCIEW done int clear address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PCIEW_INT_CLR_ADDR        0x0
 * </pre>
 */
#define RXM_RXM_PCIEW_INT_CLR_ADDR_ADDR        (REG_RXM_BASE_ADDR+0x00000224)
#define RXM_RXM_PCIEW_INT_CLR_ADDR_OFFSET      0x00000224
#define RXM_RXM_PCIEW_INT_CLR_ADDR_INDEX       0x00000089
#define RXM_RXM_PCIEW_INT_CLR_ADDR_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_pciew_int_clr_addr_get(void)
{
	return REG_PL_RD(RXM_RXM_PCIEW_INT_CLR_ADDR_ADDR);
}

__INLINE void rxm_rxm_pciew_int_clr_addr_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_PCIEW_INT_CLR_ADDR_ADDR, value);
}

// field definitions
#define RXM_RXM_PCIEW_INT_CLR_ADDR_PCIEW_INT_CLR_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_PCIEW_INT_CLR_ADDR_PCIEW_INT_CLR_ADDR_LSB    0
#define RXM_RXM_PCIEW_INT_CLR_ADDR_PCIEW_INT_CLR_ADDR_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_PCIEW_INT_CLR_ADDR_PCIEW_INT_CLR_ADDR_RST    0x0

__INLINE uint32_t rxm_rxm_pciew_int_clr_addr_pciew_int_clr_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PCIEW_INT_CLR_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_pciew_int_clr_addr_pciew_int_clr_addr_setf(uint32_t pciewintclraddr)
{
	ASSERT_ERR((((uint32_t)pciewintclraddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_PCIEW_INT_CLR_ADDR_ADDR, (uint32_t)pciewintclraddr << 0);
}

/**
 * @brief RXM_PCIEW_INT_CLR_BMAP register definition
 *  PCIEW done int clear bit map register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PCIEW_INT_CLR_BMAP        0x0
 * </pre>
 */
#define RXM_RXM_PCIEW_INT_CLR_BMAP_ADDR        (REG_RXM_BASE_ADDR+0x00000228)
#define RXM_RXM_PCIEW_INT_CLR_BMAP_OFFSET      0x00000228
#define RXM_RXM_PCIEW_INT_CLR_BMAP_INDEX       0x0000008A
#define RXM_RXM_PCIEW_INT_CLR_BMAP_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_pciew_int_clr_bmap_get(void)
{
	return REG_PL_RD(RXM_RXM_PCIEW_INT_CLR_BMAP_ADDR);
}

__INLINE void rxm_rxm_pciew_int_clr_bmap_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_PCIEW_INT_CLR_BMAP_ADDR, value);
}

// field definitions
#define RXM_RXM_PCIEW_INT_CLR_BMAP_PCIEW_INT_CLR_BMAP_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_PCIEW_INT_CLR_BMAP_PCIEW_INT_CLR_BMAP_LSB    0
#define RXM_RXM_PCIEW_INT_CLR_BMAP_PCIEW_INT_CLR_BMAP_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_PCIEW_INT_CLR_BMAP_PCIEW_INT_CLR_BMAP_RST    0x0

__INLINE uint32_t rxm_rxm_pciew_int_clr_bmap_pciew_int_clr_bmap_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PCIEW_INT_CLR_BMAP_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_pciew_int_clr_bmap_pciew_int_clr_bmap_setf(uint32_t pciewintclrbmap)
{
	ASSERT_ERR((((uint32_t)pciewintclrbmap << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_PCIEW_INT_CLR_BMAP_ADDR, (uint32_t)pciewintclrbmap << 0);
}

/**
 * @brief RXM_MPDU_TH register definition
 *  Small MPDU threshold register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 SMALL_MPDU_DE_AGG_DIS_TH  0xc8
 * </pre>
 */
#define RXM_RXM_MPDU_TH_ADDR        (REG_RXM_BASE_ADDR+0x0000022C)
#define RXM_RXM_MPDU_TH_OFFSET      0x0000022C
#define RXM_RXM_MPDU_TH_INDEX       0x0000008B
#define RXM_RXM_MPDU_TH_RESET       0x000000C8

__INLINE uint32_t  rxm_rxm_mpdu_th_get(void)
{
	return REG_PL_RD(RXM_RXM_MPDU_TH_ADDR);
}

__INLINE void rxm_rxm_mpdu_th_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_MPDU_TH_ADDR, value);
}

// field definitions
#define RXM_RXM_MPDU_TH_SMALL_MPDU_DE_AGG_DIS_TH_MASK    ((uint32_t)0x0000FFFF)
#define RXM_RXM_MPDU_TH_SMALL_MPDU_DE_AGG_DIS_TH_LSB    0
#define RXM_RXM_MPDU_TH_SMALL_MPDU_DE_AGG_DIS_TH_WIDTH    ((uint32_t)0x00000010)

#define RXM_RXM_MPDU_TH_SMALL_MPDU_DE_AGG_DIS_TH_RST    0xc8

__INLINE uint16_t rxm_rxm_mpdu_th_small_mpdu_de_agg_dis_th_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MPDU_TH_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void rxm_rxm_mpdu_th_small_mpdu_de_agg_dis_th_setf(uint16_t smallmpdudeaggdisth)
{
	ASSERT_ERR((((uint32_t)smallmpdudeaggdisth << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(RXM_RXM_MPDU_TH_ADDR, (uint32_t)smallmpdudeaggdisth << 0);
}

/**
 * @brief RXM_EXT_LLI_CURR_ADDR register definition
 *  Current ext LLI address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 EXT_LLI_CURR_ADDR         0x0
 * </pre>
 */
#define RXM_RXM_EXT_LLI_CURR_ADDR_ADDR        (REG_RXM_BASE_ADDR+0x00000230)
#define RXM_RXM_EXT_LLI_CURR_ADDR_OFFSET      0x00000230
#define RXM_RXM_EXT_LLI_CURR_ADDR_INDEX       0x0000008C
#define RXM_RXM_EXT_LLI_CURR_ADDR_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_ext_lli_curr_addr_get(void)
{
	return REG_PL_RD(RXM_RXM_EXT_LLI_CURR_ADDR_ADDR);
}

// field definitions
#define RXM_RXM_EXT_LLI_CURR_ADDR_EXT_LLI_CURR_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_EXT_LLI_CURR_ADDR_EXT_LLI_CURR_ADDR_LSB    0
#define RXM_RXM_EXT_LLI_CURR_ADDR_EXT_LLI_CURR_ADDR_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_EXT_LLI_CURR_ADDR_EXT_LLI_CURR_ADDR_RST    0x0

__INLINE uint32_t rxm_rxm_ext_lli_curr_addr_ext_lli_curr_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_EXT_LLI_CURR_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RXM_EXT_LLI_CONSUME_LEVEL register definition
 *  Current consumed ext LLIs register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 EXT_LLI_CONSUME_LEVEL     0x0
 * </pre>
 */
#define RXM_RXM_EXT_LLI_CONSUME_LEVEL_ADDR        (REG_RXM_BASE_ADDR+0x00000234)
#define RXM_RXM_EXT_LLI_CONSUME_LEVEL_OFFSET      0x00000234
#define RXM_RXM_EXT_LLI_CONSUME_LEVEL_INDEX       0x0000008D
#define RXM_RXM_EXT_LLI_CONSUME_LEVEL_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_ext_lli_consume_level_get(void)
{
	return REG_PL_RD(RXM_RXM_EXT_LLI_CONSUME_LEVEL_ADDR);
}

// field definitions
#define RXM_RXM_EXT_LLI_CONSUME_LEVEL_EXT_LLI_CONSUME_LEVEL_MASK    ((uint32_t)0x0000FFFF)
#define RXM_RXM_EXT_LLI_CONSUME_LEVEL_EXT_LLI_CONSUME_LEVEL_LSB    0
#define RXM_RXM_EXT_LLI_CONSUME_LEVEL_EXT_LLI_CONSUME_LEVEL_WIDTH    ((uint32_t)0x00000010)

#define RXM_RXM_EXT_LLI_CONSUME_LEVEL_EXT_LLI_CONSUME_LEVEL_RST    0x0

__INLINE uint16_t rxm_rxm_ext_lli_consume_level_ext_lli_consume_level_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_EXT_LLI_CONSUME_LEVEL_ADDR);
	return (uint16_t)(localVal >> 0);
}

/**
 * @brief RXM_LLI_DONE_CNT register definition
 *  Completed LLIs counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 LLI_DONE_CNT              0x0
 * </pre>
 */
#define RXM_RXM_LLI_DONE_CNT_ADDR        (REG_RXM_BASE_ADDR+0x00000238)
#define RXM_RXM_LLI_DONE_CNT_OFFSET      0x00000238
#define RXM_RXM_LLI_DONE_CNT_INDEX       0x0000008E
#define RXM_RXM_LLI_DONE_CNT_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_lli_done_cnt_get(void)
{
	return REG_PL_RD(RXM_RXM_LLI_DONE_CNT_ADDR);
}

__INLINE void rxm_rxm_lli_done_cnt_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_LLI_DONE_CNT_ADDR, value);
}

// field definitions
#define RXM_RXM_LLI_DONE_CNT_LLI_DONE_CNT_MASK    ((uint32_t)0x0000FFFF)
#define RXM_RXM_LLI_DONE_CNT_LLI_DONE_CNT_LSB    0
#define RXM_RXM_LLI_DONE_CNT_LLI_DONE_CNT_WIDTH    ((uint32_t)0x00000010)

#define RXM_RXM_LLI_DONE_CNT_LLI_DONE_CNT_RST    0x0

__INLINE uint16_t rxm_rxm_lli_done_cnt_lli_done_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_LLI_DONE_CNT_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void rxm_rxm_lli_done_cnt_lli_done_cnt_setf(uint16_t llidonecnt)
{
	ASSERT_ERR((((uint32_t)llidonecnt << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(RXM_RXM_LLI_DONE_CNT_ADDR, (uint32_t)llidonecnt << 0);
}

/**
 * @brief RXM_MPDUS_LLI_CNT register definition
 *  Completed MPDUs LLIs counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 MPDUS_LLI_CNT             0x0
 * </pre>
 */
#define RXM_RXM_MPDUS_LLI_CNT_ADDR        (REG_RXM_BASE_ADDR+0x0000023C)
#define RXM_RXM_MPDUS_LLI_CNT_OFFSET      0x0000023C
#define RXM_RXM_MPDUS_LLI_CNT_INDEX       0x0000008F
#define RXM_RXM_MPDUS_LLI_CNT_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_mpdus_lli_cnt_get(void)
{
	return REG_PL_RD(RXM_RXM_MPDUS_LLI_CNT_ADDR);
}

// field definitions
#define RXM_RXM_MPDUS_LLI_CNT_MPDUS_LLI_CNT_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_MPDUS_LLI_CNT_MPDUS_LLI_CNT_LSB    0
#define RXM_RXM_MPDUS_LLI_CNT_MPDUS_LLI_CNT_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_MPDUS_LLI_CNT_MPDUS_LLI_CNT_RST    0x0

__INLINE uint32_t rxm_rxm_mpdus_lli_cnt_mpdus_lli_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MPDUS_LLI_CNT_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RXM_OUTSTAND_LLI_LEVEL register definition
 *  Outstanding LLI number  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 OUTSTAND_LLI_LEVEL        0x0
 * </pre>
 */
#define RXM_RXM_OUTSTAND_LLI_LEVEL_ADDR        (REG_RXM_BASE_ADDR+0x00000240)
#define RXM_RXM_OUTSTAND_LLI_LEVEL_OFFSET      0x00000240
#define RXM_RXM_OUTSTAND_LLI_LEVEL_INDEX       0x00000090
#define RXM_RXM_OUTSTAND_LLI_LEVEL_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_outstand_lli_level_get(void)
{
	return REG_PL_RD(RXM_RXM_OUTSTAND_LLI_LEVEL_ADDR);
}

// field definitions
#define RXM_RXM_OUTSTAND_LLI_LEVEL_OUTSTAND_LLI_LEVEL_MASK    ((uint32_t)0x0000FFFF)
#define RXM_RXM_OUTSTAND_LLI_LEVEL_OUTSTAND_LLI_LEVEL_LSB    0
#define RXM_RXM_OUTSTAND_LLI_LEVEL_OUTSTAND_LLI_LEVEL_WIDTH    ((uint32_t)0x00000010)

#define RXM_RXM_OUTSTAND_LLI_LEVEL_OUTSTAND_LLI_LEVEL_RST    0x0

__INLINE uint16_t rxm_rxm_outstand_lli_level_outstand_lli_level_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_OUTSTAND_LLI_LEVEL_ADDR);
	return (uint16_t)(localVal >> 0);
}

/**
 * @brief RXM_PHY_CHANNEL_INFO_1 register definition
 *  Write in RHD address offset 0x54 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PHY_CHANNEL_INFO_1        0x0
 * </pre>
 */
#define RXM_RXM_PHY_CHANNEL_INFO_1_ADDR        (REG_RXM_BASE_ADDR+0x00000248)
#define RXM_RXM_PHY_CHANNEL_INFO_1_OFFSET      0x00000248
#define RXM_RXM_PHY_CHANNEL_INFO_1_INDEX       0x00000092
#define RXM_RXM_PHY_CHANNEL_INFO_1_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_phy_channel_info_1_get(void)
{
	return REG_PL_RD(RXM_RXM_PHY_CHANNEL_INFO_1_ADDR);
}

__INLINE void rxm_rxm_phy_channel_info_1_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_PHY_CHANNEL_INFO_1_ADDR, value);
}

// field definitions
#define RXM_RXM_PHY_CHANNEL_INFO_1_PHY_CHANNEL_INFO_1_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_PHY_CHANNEL_INFO_1_PHY_CHANNEL_INFO_1_LSB    0
#define RXM_RXM_PHY_CHANNEL_INFO_1_PHY_CHANNEL_INFO_1_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_PHY_CHANNEL_INFO_1_PHY_CHANNEL_INFO_1_RST    0x0

__INLINE uint32_t rxm_rxm_phy_channel_info_1_phy_channel_info_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PHY_CHANNEL_INFO_1_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_phy_channel_info_1_phy_channel_info_1_setf(uint32_t phychannelinfo1)
{
	ASSERT_ERR((((uint32_t)phychannelinfo1 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_PHY_CHANNEL_INFO_1_ADDR, (uint32_t)phychannelinfo1 << 0);
}

/**
 * @brief RXM_PHY_CHANNEL_INFO_2 register definition
 *  Write in RHD address offset 0x58 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PHY_CHANNEL_INFO_2        0x0
 * </pre>
 */
#define RXM_RXM_PHY_CHANNEL_INFO_2_ADDR        (REG_RXM_BASE_ADDR+0x0000024C)
#define RXM_RXM_PHY_CHANNEL_INFO_2_OFFSET      0x0000024C
#define RXM_RXM_PHY_CHANNEL_INFO_2_INDEX       0x00000093
#define RXM_RXM_PHY_CHANNEL_INFO_2_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_phy_channel_info_2_get(void)
{
	return REG_PL_RD(RXM_RXM_PHY_CHANNEL_INFO_2_ADDR);
}

__INLINE void rxm_rxm_phy_channel_info_2_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_PHY_CHANNEL_INFO_2_ADDR, value);
}

// field definitions
#define RXM_RXM_PHY_CHANNEL_INFO_2_PHY_CHANNEL_INFO_2_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_PHY_CHANNEL_INFO_2_PHY_CHANNEL_INFO_2_LSB    0
#define RXM_RXM_PHY_CHANNEL_INFO_2_PHY_CHANNEL_INFO_2_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_PHY_CHANNEL_INFO_2_PHY_CHANNEL_INFO_2_RST    0x0

__INLINE uint32_t rxm_rxm_phy_channel_info_2_phy_channel_info_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PHY_CHANNEL_INFO_2_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_phy_channel_info_2_phy_channel_info_2_setf(uint32_t phychannelinfo2)
{
	ASSERT_ERR((((uint32_t)phychannelinfo2 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_PHY_CHANNEL_INFO_2_ADDR, (uint32_t)phychannelinfo2 << 0);
}

/**
 * @brief RXM_HBP_RING_SIZE register definition
 *  Size of HBP ring in ShRAM register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    12:00 HBP_RING_SIZE             0x100
 * </pre>
 */
#define RXM_RXM_HBP_RING_SIZE_ADDR        (REG_RXM_BASE_ADDR+0x00000250)
#define RXM_RXM_HBP_RING_SIZE_OFFSET      0x00000250
#define RXM_RXM_HBP_RING_SIZE_INDEX       0x00000094
#define RXM_RXM_HBP_RING_SIZE_RESET       0x00000100

__INLINE uint32_t  rxm_rxm_hbp_ring_size_get(void)
{
	return REG_PL_RD(RXM_RXM_HBP_RING_SIZE_ADDR);
}

__INLINE void rxm_rxm_hbp_ring_size_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_HBP_RING_SIZE_ADDR, value);
}

// field definitions
#define RXM_RXM_HBP_RING_SIZE_HBP_RING_SIZE_MASK    ((uint32_t)0x00001FFF)
#define RXM_RXM_HBP_RING_SIZE_HBP_RING_SIZE_LSB    0
#define RXM_RXM_HBP_RING_SIZE_HBP_RING_SIZE_WIDTH    ((uint32_t)0x0000000D)

#define RXM_RXM_HBP_RING_SIZE_HBP_RING_SIZE_RST    0x100

__INLINE uint16_t rxm_rxm_hbp_ring_size_hbp_ring_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_HBP_RING_SIZE_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void rxm_rxm_hbp_ring_size_hbp_ring_size_setf(uint16_t hbpringsize)
{
	ASSERT_ERR((((uint32_t)hbpringsize << 0) & ~((uint32_t)0x00001FFF)) == 0);
	REG_PL_WR(RXM_RXM_HBP_RING_SIZE_ADDR, (uint32_t)hbpringsize << 0);
}

/**
 * @brief RXM_HBP_RING_START_ADDR register definition
 *  HBP ring start address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 HBP_RING_START_ADDR       0x0
 * </pre>
 */
#define RXM_RXM_HBP_RING_START_ADDR_ADDR        (REG_RXM_BASE_ADDR+0x00000254)
#define RXM_RXM_HBP_RING_START_ADDR_OFFSET      0x00000254
#define RXM_RXM_HBP_RING_START_ADDR_INDEX       0x00000095
#define RXM_RXM_HBP_RING_START_ADDR_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_hbp_ring_start_addr_get(void)
{
	return REG_PL_RD(RXM_RXM_HBP_RING_START_ADDR_ADDR);
}

__INLINE void rxm_rxm_hbp_ring_start_addr_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_HBP_RING_START_ADDR_ADDR, value);
}

// field definitions
#define RXM_RXM_HBP_RING_START_ADDR_HBP_RING_START_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_HBP_RING_START_ADDR_HBP_RING_START_ADDR_LSB    0
#define RXM_RXM_HBP_RING_START_ADDR_HBP_RING_START_ADDR_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_HBP_RING_START_ADDR_HBP_RING_START_ADDR_RST    0x0

__INLINE uint32_t rxm_rxm_hbp_ring_start_addr_hbp_ring_start_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_HBP_RING_START_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_hbp_ring_start_addr_hbp_ring_start_addr_setf(uint32_t hbpringstartaddr)
{
	ASSERT_ERR((((uint32_t)hbpringstartaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_HBP_RING_START_ADDR_ADDR, (uint32_t)hbpringstartaddr << 0);
}

/**
 * @brief RXM_HBP_ALLOC_CNT register definition
 *  Allocation counter of HBP ring register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 HBP_ALLOC_CNT             0x0
 * </pre>
 */
#define RXM_RXM_HBP_ALLOC_CNT_ADDR        (REG_RXM_BASE_ADDR+0x00000258)
#define RXM_RXM_HBP_ALLOC_CNT_OFFSET      0x00000258
#define RXM_RXM_HBP_ALLOC_CNT_INDEX       0x00000096
#define RXM_RXM_HBP_ALLOC_CNT_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_hbp_alloc_cnt_get(void)
{
	return REG_PL_RD(RXM_RXM_HBP_ALLOC_CNT_ADDR);
}

__INLINE void rxm_rxm_hbp_alloc_cnt_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_HBP_ALLOC_CNT_ADDR, value);
}

// field definitions
#define RXM_RXM_HBP_ALLOC_CNT_HBP_ALLOC_CNT_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_HBP_ALLOC_CNT_HBP_ALLOC_CNT_LSB    0
#define RXM_RXM_HBP_ALLOC_CNT_HBP_ALLOC_CNT_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_HBP_ALLOC_CNT_HBP_ALLOC_CNT_RST    0x0

__INLINE uint32_t rxm_rxm_hbp_alloc_cnt_hbp_alloc_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_HBP_ALLOC_CNT_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_hbp_alloc_cnt_hbp_alloc_cnt_setf(uint32_t hbpalloccnt)
{
	ASSERT_ERR((((uint32_t)hbpalloccnt << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_HBP_ALLOC_CNT_ADDR, (uint32_t)hbpalloccnt << 0);
}

/**
 * @brief RXM_HBP_CURRENT_CNT register definition
 *  Current counter of HBP ring register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 HBP_CURRENT_CNT           0x0
 * </pre>
 */
#define RXM_RXM_HBP_CURRENT_CNT_ADDR        (REG_RXM_BASE_ADDR+0x0000025C)
#define RXM_RXM_HBP_CURRENT_CNT_OFFSET      0x0000025C
#define RXM_RXM_HBP_CURRENT_CNT_INDEX       0x00000097
#define RXM_RXM_HBP_CURRENT_CNT_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_hbp_current_cnt_get(void)
{
	return REG_PL_RD(RXM_RXM_HBP_CURRENT_CNT_ADDR);
}

// field definitions
#define RXM_RXM_HBP_CURRENT_CNT_HBP_CURRENT_CNT_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_HBP_CURRENT_CNT_HBP_CURRENT_CNT_LSB    0
#define RXM_RXM_HBP_CURRENT_CNT_HBP_CURRENT_CNT_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_HBP_CURRENT_CNT_HBP_CURRENT_CNT_RST    0x0

__INLINE uint32_t rxm_rxm_hbp_current_cnt_hbp_current_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_HBP_CURRENT_CNT_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RXM_HBP_CONSUME_CNT register definition
 *  Consume counter of HBP ring register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 HBP_CONSUME_CNT           0x0
 * </pre>
 */
#define RXM_RXM_HBP_CONSUME_CNT_ADDR        (REG_RXM_BASE_ADDR+0x00000260)
#define RXM_RXM_HBP_CONSUME_CNT_OFFSET      0x00000260
#define RXM_RXM_HBP_CONSUME_CNT_INDEX       0x00000098
#define RXM_RXM_HBP_CONSUME_CNT_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_hbp_consume_cnt_get(void)
{
	return REG_PL_RD(RXM_RXM_HBP_CONSUME_CNT_ADDR);
}

__INLINE void rxm_rxm_hbp_consume_cnt_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_HBP_CONSUME_CNT_ADDR, value);
}

// field definitions
#define RXM_RXM_HBP_CONSUME_CNT_HBP_CONSUME_CNT_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_HBP_CONSUME_CNT_HBP_CONSUME_CNT_LSB    0
#define RXM_RXM_HBP_CONSUME_CNT_HBP_CONSUME_CNT_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_HBP_CONSUME_CNT_HBP_CONSUME_CNT_RST    0x0

__INLINE uint32_t rxm_rxm_hbp_consume_cnt_hbp_consume_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_HBP_CONSUME_CNT_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_hbp_consume_cnt_hbp_consume_cnt_setf(uint32_t hbpconsumecnt)
{
	ASSERT_ERR((((uint32_t)hbpconsumecnt << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_HBP_CONSUME_CNT_ADDR, (uint32_t)hbpconsumecnt << 0);
}

/**
 * @brief RXM_HBP_INT_CONFIG register definition
 *  Depletion TH and coalasing register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 HBP_ALLOC_INT_TH          0x20
 *    15:13 spare                     0x0
 *    12:08 HBP_CONSUME_INT_CNT       0x4
 *    07:00 HBP_CONSUME_INT_TO        0x10
 * </pre>
 */
#define RXM_RXM_HBP_INT_CONFIG_ADDR        (REG_RXM_BASE_ADDR+0x00000264)
#define RXM_RXM_HBP_INT_CONFIG_OFFSET      0x00000264
#define RXM_RXM_HBP_INT_CONFIG_INDEX       0x00000099
#define RXM_RXM_HBP_INT_CONFIG_RESET       0x00200410

__INLINE uint32_t  rxm_rxm_hbp_int_config_get(void)
{
	return REG_PL_RD(RXM_RXM_HBP_INT_CONFIG_ADDR);
}

__INLINE void rxm_rxm_hbp_int_config_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_HBP_INT_CONFIG_ADDR, value);
}

// field definitions
#define RXM_RXM_HBP_INT_CONFIG_HBP_ALLOC_INT_TH_MASK    ((uint32_t)0x0FFF0000)
#define RXM_RXM_HBP_INT_CONFIG_HBP_ALLOC_INT_TH_LSB    16
#define RXM_RXM_HBP_INT_CONFIG_HBP_ALLOC_INT_TH_WIDTH    ((uint32_t)0x0000000C)
#define RXM_RXM_HBP_INT_CONFIG_SPARE_MASK    ((uint32_t)0x0000E000)
#define RXM_RXM_HBP_INT_CONFIG_SPARE_LSB    13
#define RXM_RXM_HBP_INT_CONFIG_SPARE_WIDTH    ((uint32_t)0x00000003)
#define RXM_RXM_HBP_INT_CONFIG_HBP_CONSUME_INT_CNT_MASK    ((uint32_t)0x00001F00)
#define RXM_RXM_HBP_INT_CONFIG_HBP_CONSUME_INT_CNT_LSB    8
#define RXM_RXM_HBP_INT_CONFIG_HBP_CONSUME_INT_CNT_WIDTH    ((uint32_t)0x00000005)
#define RXM_RXM_HBP_INT_CONFIG_HBP_CONSUME_INT_TO_MASK    ((uint32_t)0x000000FF)
#define RXM_RXM_HBP_INT_CONFIG_HBP_CONSUME_INT_TO_LSB    0
#define RXM_RXM_HBP_INT_CONFIG_HBP_CONSUME_INT_TO_WIDTH    ((uint32_t)0x00000008)

#define RXM_RXM_HBP_INT_CONFIG_HBP_ALLOC_INT_TH_RST    0x20
#define RXM_RXM_HBP_INT_CONFIG_SPARE_RST    0x0
#define RXM_RXM_HBP_INT_CONFIG_HBP_CONSUME_INT_CNT_RST    0x4
#define RXM_RXM_HBP_INT_CONFIG_HBP_CONSUME_INT_TO_RST    0x10

__INLINE void rxm_rxm_hbp_int_config_pack(uint16_t hbp_alloc_int_th, uint8_t spare, uint8_t hbp_consume_int_cnt, uint8_t hbp_consume_int_to)
{
	ASSERT_ERR((((uint32_t)hbp_alloc_int_th << 16) & ~((uint32_t)0x0FFF0000)) == 0);
	ASSERT_ERR((((uint32_t)spare << 13) & ~((uint32_t)0x0000E000)) == 0);
	ASSERT_ERR((((uint32_t)hbp_consume_int_cnt << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)hbp_consume_int_to << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RXM_RXM_HBP_INT_CONFIG_ADDR,  ((uint32_t)hbp_alloc_int_th << 16) |((uint32_t)spare << 13) |((uint32_t)hbp_consume_int_cnt << 8) |((uint32_t)hbp_consume_int_to << 0));
}

__INLINE void rxm_rxm_hbp_int_config_unpack(uint16_t* hbp_alloc_int_th, uint8_t* spare, uint8_t* hbp_consume_int_cnt, uint8_t* hbp_consume_int_to)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_HBP_INT_CONFIG_ADDR);

	*hbp_alloc_int_th = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*spare = (localVal & ((uint32_t)0x0000E000)) >>  13;
	*hbp_consume_int_cnt = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*hbp_consume_int_to = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint16_t rxm_rxm_hbp_int_config_hbp_alloc_int_th_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_HBP_INT_CONFIG_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE void rxm_rxm_hbp_int_config_hbp_alloc_int_th_setf(uint16_t hbpallocintth)
{
	ASSERT_ERR((((uint32_t)hbpallocintth << 16) & ~((uint32_t)0x0FFF0000)) == 0);
	REG_PL_WR(RXM_RXM_HBP_INT_CONFIG_ADDR, (REG_PL_RD(RXM_RXM_HBP_INT_CONFIG_ADDR) & ~((uint32_t)0x0FFF0000)) | ((uint32_t)hbpallocintth <<16));
}
__INLINE uint8_t rxm_rxm_hbp_int_config_spare_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_HBP_INT_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000E000)) >> 13);
}
__INLINE uint8_t rxm_rxm_hbp_int_config_hbp_consume_int_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_HBP_INT_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void rxm_rxm_hbp_int_config_hbp_consume_int_cnt_setf(uint8_t hbpconsumeintcnt)
{
	ASSERT_ERR((((uint32_t)hbpconsumeintcnt << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(RXM_RXM_HBP_INT_CONFIG_ADDR, (REG_PL_RD(RXM_RXM_HBP_INT_CONFIG_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)hbpconsumeintcnt <<8));
}
__INLINE uint8_t rxm_rxm_hbp_int_config_hbp_consume_int_to_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_HBP_INT_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void rxm_rxm_hbp_int_config_hbp_consume_int_to_setf(uint8_t hbpconsumeintto)
{
	ASSERT_ERR((((uint32_t)hbpconsumeintto << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RXM_RXM_HBP_INT_CONFIG_ADDR, (REG_PL_RD(RXM_RXM_HBP_INT_CONFIG_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)hbpconsumeintto <<0));
}

/**
 * @brief RXM_HBP_CURRENT_ADDR register definition
 *  HBP ring current RXM address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RXM_HBP_CURRENT_ADDR      0x0
 * </pre>
 */
#define RXM_RXM_HBP_CURRENT_ADDR_ADDR        (REG_RXM_BASE_ADDR+0x00000268)
#define RXM_RXM_HBP_CURRENT_ADDR_OFFSET      0x00000268
#define RXM_RXM_HBP_CURRENT_ADDR_INDEX       0x0000009A
#define RXM_RXM_HBP_CURRENT_ADDR_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_hbp_current_addr_get(void)
{
	return REG_PL_RD(RXM_RXM_HBP_CURRENT_ADDR_ADDR);
}

__INLINE void rxm_rxm_hbp_current_addr_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_HBP_CURRENT_ADDR_ADDR, value);
}

// field definitions
#define RXM_RXM_HBP_CURRENT_ADDR_RXM_HBP_CURRENT_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_HBP_CURRENT_ADDR_RXM_HBP_CURRENT_ADDR_LSB    0
#define RXM_RXM_HBP_CURRENT_ADDR_RXM_HBP_CURRENT_ADDR_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_HBP_CURRENT_ADDR_RXM_HBP_CURRENT_ADDR_RST    0x0

__INLINE uint32_t rxm_rxm_hbp_current_addr_rxm_hbp_current_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_HBP_CURRENT_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_hbp_current_addr_rxm_hbp_current_addr_setf(uint32_t rxmhbpcurrentaddr)
{
	ASSERT_ERR((((uint32_t)rxmhbpcurrentaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_HBP_CURRENT_ADDR_ADDR, (uint32_t)rxmhbpcurrentaddr << 0);
}

/**
 * @brief RXM_MPDU_HIST_FIFO_STAT register definition
 *  MPDU history fifo status register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    25    FIFO_FULL                 0              
 *    24    FIFO_EMPTY                1              
 *    23:12 MAX_LEVEL                 0x0
 *    11:00 CONSUME_LEVEL             0x0
 * </pre>
 */
#define RXM_RXM_MPDU_HIST_FIFO_STAT_ADDR        (REG_RXM_BASE_ADDR+0x00000270)
#define RXM_RXM_MPDU_HIST_FIFO_STAT_OFFSET      0x00000270
#define RXM_RXM_MPDU_HIST_FIFO_STAT_INDEX       0x0000009C
#define RXM_RXM_MPDU_HIST_FIFO_STAT_RESET       0x01000000

__INLINE uint32_t  rxm_rxm_mpdu_hist_fifo_stat_get(void)
{
	return REG_PL_RD(RXM_RXM_MPDU_HIST_FIFO_STAT_ADDR);
}

// field definitions
#define RXM_RXM_MPDU_HIST_FIFO_STAT_FIFO_FULL_BIT    ((uint32_t)0x02000000)
#define RXM_RXM_MPDU_HIST_FIFO_STAT_FIFO_FULL_POS    25
#define RXM_RXM_MPDU_HIST_FIFO_STAT_FIFO_EMPTY_BIT    ((uint32_t)0x01000000)
#define RXM_RXM_MPDU_HIST_FIFO_STAT_FIFO_EMPTY_POS    24
#define RXM_RXM_MPDU_HIST_FIFO_STAT_MAX_LEVEL_MASK    ((uint32_t)0x00FFF000)
#define RXM_RXM_MPDU_HIST_FIFO_STAT_MAX_LEVEL_LSB    12
#define RXM_RXM_MPDU_HIST_FIFO_STAT_MAX_LEVEL_WIDTH    ((uint32_t)0x0000000C)
#define RXM_RXM_MPDU_HIST_FIFO_STAT_CONSUME_LEVEL_MASK    ((uint32_t)0x00000FFF)
#define RXM_RXM_MPDU_HIST_FIFO_STAT_CONSUME_LEVEL_LSB    0
#define RXM_RXM_MPDU_HIST_FIFO_STAT_CONSUME_LEVEL_WIDTH    ((uint32_t)0x0000000C)

#define RXM_RXM_MPDU_HIST_FIFO_STAT_FIFO_FULL_RST    0x0
#define RXM_RXM_MPDU_HIST_FIFO_STAT_FIFO_EMPTY_RST    0x1
#define RXM_RXM_MPDU_HIST_FIFO_STAT_MAX_LEVEL_RST    0x0
#define RXM_RXM_MPDU_HIST_FIFO_STAT_CONSUME_LEVEL_RST    0x0

__INLINE void rxm_rxm_mpdu_hist_fifo_stat_unpack(uint8_t* fifo_full, uint8_t* fifo_empty, uint16_t* max_level, uint16_t* consume_level)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MPDU_HIST_FIFO_STAT_ADDR);

	*fifo_full = (localVal & ((uint32_t)0x02000000)) >>  25;
	*fifo_empty = (localVal & ((uint32_t)0x01000000)) >>  24;
	*max_level = (localVal & ((uint32_t)0x00FFF000)) >>  12;
	*consume_level = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint8_t rxm_rxm_mpdu_hist_fifo_stat_fifo_full_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MPDU_HIST_FIFO_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x02000000)) >> 25);
}
__INLINE uint8_t rxm_rxm_mpdu_hist_fifo_stat_fifo_empty_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MPDU_HIST_FIFO_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01000000)) >> 24);
}
__INLINE uint16_t rxm_rxm_mpdu_hist_fifo_stat_max_level_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MPDU_HIST_FIFO_STAT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00FFF000)) >> 12);
}
__INLINE uint16_t rxm_rxm_mpdu_hist_fifo_stat_consume_level_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MPDU_HIST_FIFO_STAT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}

/**
 * @brief RXM_LLI_HIST_FIFO_STAT register definition
 *  LLI history fifo status register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    25    FIFO_FULL                 0              
 *    24    FIFO_EMPTY                1              
 *    23:12 MAX_LEVEL                 0x0
 *    11:00 CONSUME_LEVEL             0x0
 * </pre>
 */
#define RXM_RXM_LLI_HIST_FIFO_STAT_ADDR        (REG_RXM_BASE_ADDR+0x00000274)
#define RXM_RXM_LLI_HIST_FIFO_STAT_OFFSET      0x00000274
#define RXM_RXM_LLI_HIST_FIFO_STAT_INDEX       0x0000009D
#define RXM_RXM_LLI_HIST_FIFO_STAT_RESET       0x01000000

__INLINE uint32_t  rxm_rxm_lli_hist_fifo_stat_get(void)
{
	return REG_PL_RD(RXM_RXM_LLI_HIST_FIFO_STAT_ADDR);
}

// field definitions
#define RXM_RXM_LLI_HIST_FIFO_STAT_FIFO_FULL_BIT    ((uint32_t)0x02000000)
#define RXM_RXM_LLI_HIST_FIFO_STAT_FIFO_FULL_POS    25
#define RXM_RXM_LLI_HIST_FIFO_STAT_FIFO_EMPTY_BIT    ((uint32_t)0x01000000)
#define RXM_RXM_LLI_HIST_FIFO_STAT_FIFO_EMPTY_POS    24
#define RXM_RXM_LLI_HIST_FIFO_STAT_MAX_LEVEL_MASK    ((uint32_t)0x00FFF000)
#define RXM_RXM_LLI_HIST_FIFO_STAT_MAX_LEVEL_LSB    12
#define RXM_RXM_LLI_HIST_FIFO_STAT_MAX_LEVEL_WIDTH    ((uint32_t)0x0000000C)
#define RXM_RXM_LLI_HIST_FIFO_STAT_CONSUME_LEVEL_MASK    ((uint32_t)0x00000FFF)
#define RXM_RXM_LLI_HIST_FIFO_STAT_CONSUME_LEVEL_LSB    0
#define RXM_RXM_LLI_HIST_FIFO_STAT_CONSUME_LEVEL_WIDTH    ((uint32_t)0x0000000C)

#define RXM_RXM_LLI_HIST_FIFO_STAT_FIFO_FULL_RST    0x0
#define RXM_RXM_LLI_HIST_FIFO_STAT_FIFO_EMPTY_RST    0x1
#define RXM_RXM_LLI_HIST_FIFO_STAT_MAX_LEVEL_RST    0x0
#define RXM_RXM_LLI_HIST_FIFO_STAT_CONSUME_LEVEL_RST    0x0

__INLINE void rxm_rxm_lli_hist_fifo_stat_unpack(uint8_t* fifo_full, uint8_t* fifo_empty, uint16_t* max_level, uint16_t* consume_level)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_LLI_HIST_FIFO_STAT_ADDR);

	*fifo_full = (localVal & ((uint32_t)0x02000000)) >>  25;
	*fifo_empty = (localVal & ((uint32_t)0x01000000)) >>  24;
	*max_level = (localVal & ((uint32_t)0x00FFF000)) >>  12;
	*consume_level = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint8_t rxm_rxm_lli_hist_fifo_stat_fifo_full_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_LLI_HIST_FIFO_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x02000000)) >> 25);
}
__INLINE uint8_t rxm_rxm_lli_hist_fifo_stat_fifo_empty_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_LLI_HIST_FIFO_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01000000)) >> 24);
}
__INLINE uint16_t rxm_rxm_lli_hist_fifo_stat_max_level_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_LLI_HIST_FIFO_STAT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00FFF000)) >> 12);
}
__INLINE uint16_t rxm_rxm_lli_hist_fifo_stat_consume_level_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_LLI_HIST_FIFO_STAT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}

/**
 * @brief RXM_FW_INFO_FIFO_CONFIG register definition
 *  FW info fifo configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    11:00 AVAILBLE_TO_FULL          0x0
 * </pre>
 */
#define RXM_RXM_FW_INFO_FIFO_CONFIG_ADDR        (REG_RXM_BASE_ADDR+0x00000278)
#define RXM_RXM_FW_INFO_FIFO_CONFIG_OFFSET      0x00000278
#define RXM_RXM_FW_INFO_FIFO_CONFIG_INDEX       0x0000009E
#define RXM_RXM_FW_INFO_FIFO_CONFIG_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_fw_info_fifo_config_get(void)
{
	return REG_PL_RD(RXM_RXM_FW_INFO_FIFO_CONFIG_ADDR);
}

__INLINE void rxm_rxm_fw_info_fifo_config_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_FW_INFO_FIFO_CONFIG_ADDR, value);
}

// field definitions
#define RXM_RXM_FW_INFO_FIFO_CONFIG_AVAILBLE_TO_FULL_MASK    ((uint32_t)0x00000FFF)
#define RXM_RXM_FW_INFO_FIFO_CONFIG_AVAILBLE_TO_FULL_LSB    0
#define RXM_RXM_FW_INFO_FIFO_CONFIG_AVAILBLE_TO_FULL_WIDTH    ((uint32_t)0x0000000C)

#define RXM_RXM_FW_INFO_FIFO_CONFIG_AVAILBLE_TO_FULL_RST    0x0

__INLINE uint16_t rxm_rxm_fw_info_fifo_config_availble_to_full_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_FW_INFO_FIFO_CONFIG_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void rxm_rxm_fw_info_fifo_config_availble_to_full_setf(uint16_t availbletofull)
{
	ASSERT_ERR((((uint32_t)availbletofull << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(RXM_RXM_FW_INFO_FIFO_CONFIG_ADDR, (uint32_t)availbletofull << 0);
}

/**
 * @brief RXM_FW_INFO_FIFO_STAT register definition
 *  Status of FW info fifo register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    25    FIFO_FULL                 0              
 *    24    FIFO_EMPTY                1              
 *    23:12 MAX_LEVEL                 0x0
 *    11:00 CONSUME_LEVEL             0x0
 * </pre>
 */
#define RXM_RXM_FW_INFO_FIFO_STAT_ADDR        (REG_RXM_BASE_ADDR+0x0000027C)
#define RXM_RXM_FW_INFO_FIFO_STAT_OFFSET      0x0000027C
#define RXM_RXM_FW_INFO_FIFO_STAT_INDEX       0x0000009F
#define RXM_RXM_FW_INFO_FIFO_STAT_RESET       0x01000000

__INLINE uint32_t  rxm_rxm_fw_info_fifo_stat_get(void)
{
	return REG_PL_RD(RXM_RXM_FW_INFO_FIFO_STAT_ADDR);
}

// field definitions
#define RXM_RXM_FW_INFO_FIFO_STAT_FIFO_FULL_BIT    ((uint32_t)0x02000000)
#define RXM_RXM_FW_INFO_FIFO_STAT_FIFO_FULL_POS    25
#define RXM_RXM_FW_INFO_FIFO_STAT_FIFO_EMPTY_BIT    ((uint32_t)0x01000000)
#define RXM_RXM_FW_INFO_FIFO_STAT_FIFO_EMPTY_POS    24
#define RXM_RXM_FW_INFO_FIFO_STAT_MAX_LEVEL_MASK    ((uint32_t)0x00FFF000)
#define RXM_RXM_FW_INFO_FIFO_STAT_MAX_LEVEL_LSB    12
#define RXM_RXM_FW_INFO_FIFO_STAT_MAX_LEVEL_WIDTH    ((uint32_t)0x0000000C)
#define RXM_RXM_FW_INFO_FIFO_STAT_CONSUME_LEVEL_MASK    ((uint32_t)0x00000FFF)
#define RXM_RXM_FW_INFO_FIFO_STAT_CONSUME_LEVEL_LSB    0
#define RXM_RXM_FW_INFO_FIFO_STAT_CONSUME_LEVEL_WIDTH    ((uint32_t)0x0000000C)

#define RXM_RXM_FW_INFO_FIFO_STAT_FIFO_FULL_RST    0x0
#define RXM_RXM_FW_INFO_FIFO_STAT_FIFO_EMPTY_RST    0x1
#define RXM_RXM_FW_INFO_FIFO_STAT_MAX_LEVEL_RST    0x0
#define RXM_RXM_FW_INFO_FIFO_STAT_CONSUME_LEVEL_RST    0x0

__INLINE void rxm_rxm_fw_info_fifo_stat_unpack(uint8_t* fifo_full, uint8_t* fifo_empty, uint16_t* max_level, uint16_t* consume_level)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_FW_INFO_FIFO_STAT_ADDR);

	*fifo_full = (localVal & ((uint32_t)0x02000000)) >>  25;
	*fifo_empty = (localVal & ((uint32_t)0x01000000)) >>  24;
	*max_level = (localVal & ((uint32_t)0x00FFF000)) >>  12;
	*consume_level = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint8_t rxm_rxm_fw_info_fifo_stat_fifo_full_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_FW_INFO_FIFO_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x02000000)) >> 25);
}
__INLINE uint8_t rxm_rxm_fw_info_fifo_stat_fifo_empty_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_FW_INFO_FIFO_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01000000)) >> 24);
}
__INLINE uint16_t rxm_rxm_fw_info_fifo_stat_max_level_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_FW_INFO_FIFO_STAT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00FFF000)) >> 12);
}
__INLINE uint16_t rxm_rxm_fw_info_fifo_stat_consume_level_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_FW_INFO_FIFO_STAT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}

/**
 * @brief RXM_FW_INFO_FIFO_HEAD register definition
 *  Head of FW info fifo register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:02 FWD_INFO                  0x3fffffff
 *    01:00 FWD_REASON                0x3
 * </pre>
 */
#define RXM_RXM_FW_INFO_FIFO_HEAD_ADDR        (REG_RXM_BASE_ADDR+0x00000280)
#define RXM_RXM_FW_INFO_FIFO_HEAD_OFFSET      0x00000280
#define RXM_RXM_FW_INFO_FIFO_HEAD_INDEX       0x000000A0
#define RXM_RXM_FW_INFO_FIFO_HEAD_RESET       0xFFFFFFFF

__INLINE uint32_t  rxm_rxm_fw_info_fifo_head_get(void)
{
	return REG_PL_RD(RXM_RXM_FW_INFO_FIFO_HEAD_ADDR);
}

// field definitions
#define RXM_RXM_FW_INFO_FIFO_HEAD_FWD_INFO_MASK    ((uint32_t)0xFFFFFFFC)
#define RXM_RXM_FW_INFO_FIFO_HEAD_FWD_INFO_LSB    2
#define RXM_RXM_FW_INFO_FIFO_HEAD_FWD_INFO_WIDTH    ((uint32_t)0x0000001E)
#define RXM_RXM_FW_INFO_FIFO_HEAD_FWD_REASON_MASK    ((uint32_t)0x00000003)
#define RXM_RXM_FW_INFO_FIFO_HEAD_FWD_REASON_LSB    0
#define RXM_RXM_FW_INFO_FIFO_HEAD_FWD_REASON_WIDTH    ((uint32_t)0x00000002)

#define RXM_RXM_FW_INFO_FIFO_HEAD_FWD_INFO_RST    0x3fffffff
#define RXM_RXM_FW_INFO_FIFO_HEAD_FWD_REASON_RST    0x3

__INLINE void rxm_rxm_fw_info_fifo_head_unpack(uint32_t* fwd_info, uint8_t* fwd_reason)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_FW_INFO_FIFO_HEAD_ADDR);

	*fwd_info = (localVal & ((uint32_t)0xFFFFFFFC)) >>  2;
	*fwd_reason = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint32_t rxm_rxm_fw_info_fifo_head_fwd_info_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_FW_INFO_FIFO_HEAD_ADDR);
	return (uint32_t)((localVal & ((uint32_t)0xFFFFFFFC)) >> 2);
}
__INLINE uint8_t rxm_rxm_fw_info_fifo_head_fwd_reason_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_FW_INFO_FIFO_HEAD_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}

/**
 * @brief RXM_MPX_STAT register definition
 *  Status info of MPDU processing register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    MPX_BUSY                  0              
 *    30:12 spare2                    0x0
 *    11:08 MPX_USER                  0x0
 *    07:04 spare1                    0x0
 *    03:00 MPX_PSDU_INDEX            0x0
 * </pre>
 */
#define RXM_RXM_MPX_STAT_ADDR        (REG_RXM_BASE_ADDR+0x00000284)
#define RXM_RXM_MPX_STAT_OFFSET      0x00000284
#define RXM_RXM_MPX_STAT_INDEX       0x000000A1
#define RXM_RXM_MPX_STAT_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_mpx_stat_get(void)
{
	return REG_PL_RD(RXM_RXM_MPX_STAT_ADDR);
}

// field definitions
#define RXM_RXM_MPX_STAT_MPX_BUSY_BIT       ((uint32_t)0x80000000)
#define RXM_RXM_MPX_STAT_MPX_BUSY_POS       31
#define RXM_RXM_MPX_STAT_SPARE_2_MASK       ((uint32_t)0x7FFFF000)
#define RXM_RXM_MPX_STAT_SPARE_2_LSB        12
#define RXM_RXM_MPX_STAT_SPARE_2_WIDTH      ((uint32_t)0x00000013)
#define RXM_RXM_MPX_STAT_MPX_USER_MASK      ((uint32_t)0x00000F00)
#define RXM_RXM_MPX_STAT_MPX_USER_LSB       8
#define RXM_RXM_MPX_STAT_MPX_USER_WIDTH     ((uint32_t)0x00000004)
#define RXM_RXM_MPX_STAT_SPARE_1_MASK       ((uint32_t)0x000000F0)
#define RXM_RXM_MPX_STAT_SPARE_1_LSB        4
#define RXM_RXM_MPX_STAT_SPARE_1_WIDTH      ((uint32_t)0x00000004)
#define RXM_RXM_MPX_STAT_MPX_PSDU_INDEX_MASK    ((uint32_t)0x0000000F)
#define RXM_RXM_MPX_STAT_MPX_PSDU_INDEX_LSB    0
#define RXM_RXM_MPX_STAT_MPX_PSDU_INDEX_WIDTH    ((uint32_t)0x00000004)

#define RXM_RXM_MPX_STAT_MPX_BUSY_RST       0x0
#define RXM_RXM_MPX_STAT_SPARE_2_RST        0x0
#define RXM_RXM_MPX_STAT_MPX_USER_RST       0x0
#define RXM_RXM_MPX_STAT_SPARE_1_RST        0x0
#define RXM_RXM_MPX_STAT_MPX_PSDU_INDEX_RST    0x0

__INLINE void rxm_rxm_mpx_stat_unpack(uint8_t* mpx_busy, uint32_t* spare2, uint8_t* mpx_user, uint8_t* spare1, uint8_t* mpx_psdu_index)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MPX_STAT_ADDR);

	*mpx_busy = (localVal & ((uint32_t)0x80000000)) >>  31;
	*spare2 = (localVal & ((uint32_t)0x7FFFF000)) >>  12;
	*mpx_user = (localVal & ((uint32_t)0x00000F00)) >>  8;
	*spare1 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*mpx_psdu_index = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t rxm_rxm_mpx_stat_mpx_busy_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MPX_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE uint32_t rxm_rxm_mpx_stat_spare_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MPX_STAT_ADDR);
	return (uint32_t)((localVal & ((uint32_t)0x7FFFF000)) >> 12);
}
__INLINE uint8_t rxm_rxm_mpx_stat_mpx_user_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MPX_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000F00)) >> 8);
}
__INLINE uint8_t rxm_rxm_mpx_stat_spare_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MPX_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t rxm_rxm_mpx_stat_mpx_psdu_index_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MPX_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}

/**
 * @brief RXM_MPX_DBG register definition
 *  MPX debug state machines register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:27 W2_E_SM                   0x0
 *    26    spare2                    0              
 *    25:24 DRA_SM                    0x0
 *    23:20 ST_SM                     0x0
 *    19:16 SB_SM                     0x0
 *    15    spare1                    0              
 *    14:10 WR_SM                     0x0
 *    09:05 RD_SM                     0x0
 *    04:00 MPX_SM                    0x0
 * </pre>
 */
#define RXM_RXM_MPX_DBG_ADDR        (REG_RXM_BASE_ADDR+0x00000288)
#define RXM_RXM_MPX_DBG_OFFSET      0x00000288
#define RXM_RXM_MPX_DBG_INDEX       0x000000A2
#define RXM_RXM_MPX_DBG_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_mpx_dbg_get(void)
{
	return REG_PL_RD(RXM_RXM_MPX_DBG_ADDR);
}

// field definitions
#define RXM_RXM_MPX_DBG_W_2_E_SM_MASK       ((uint32_t)0xF8000000)
#define RXM_RXM_MPX_DBG_W_2_E_SM_LSB        27
#define RXM_RXM_MPX_DBG_W_2_E_SM_WIDTH      ((uint32_t)0x00000005)
#define RXM_RXM_MPX_DBG_SPARE_2_BIT         ((uint32_t)0x04000000)
#define RXM_RXM_MPX_DBG_SPARE_2_POS         26
#define RXM_RXM_MPX_DBG_DRA_SM_MASK         ((uint32_t)0x03000000)
#define RXM_RXM_MPX_DBG_DRA_SM_LSB          24
#define RXM_RXM_MPX_DBG_DRA_SM_WIDTH        ((uint32_t)0x00000002)
#define RXM_RXM_MPX_DBG_ST_SM_MASK          ((uint32_t)0x00F00000)
#define RXM_RXM_MPX_DBG_ST_SM_LSB           20
#define RXM_RXM_MPX_DBG_ST_SM_WIDTH         ((uint32_t)0x00000004)
#define RXM_RXM_MPX_DBG_SB_SM_MASK          ((uint32_t)0x000F0000)
#define RXM_RXM_MPX_DBG_SB_SM_LSB           16
#define RXM_RXM_MPX_DBG_SB_SM_WIDTH         ((uint32_t)0x00000004)
#define RXM_RXM_MPX_DBG_SPARE_1_BIT         ((uint32_t)0x00008000)
#define RXM_RXM_MPX_DBG_SPARE_1_POS         15
#define RXM_RXM_MPX_DBG_WR_SM_MASK          ((uint32_t)0x00007C00)
#define RXM_RXM_MPX_DBG_WR_SM_LSB           10
#define RXM_RXM_MPX_DBG_WR_SM_WIDTH         ((uint32_t)0x00000005)
#define RXM_RXM_MPX_DBG_RD_SM_MASK          ((uint32_t)0x000003E0)
#define RXM_RXM_MPX_DBG_RD_SM_LSB           5
#define RXM_RXM_MPX_DBG_RD_SM_WIDTH         ((uint32_t)0x00000005)
#define RXM_RXM_MPX_DBG_MPX_SM_MASK         ((uint32_t)0x0000001F)
#define RXM_RXM_MPX_DBG_MPX_SM_LSB          0
#define RXM_RXM_MPX_DBG_MPX_SM_WIDTH        ((uint32_t)0x00000005)

#define RXM_RXM_MPX_DBG_W_2_E_SM_RST        0x0
#define RXM_RXM_MPX_DBG_SPARE_2_RST         0x0
#define RXM_RXM_MPX_DBG_DRA_SM_RST          0x0
#define RXM_RXM_MPX_DBG_ST_SM_RST           0x0
#define RXM_RXM_MPX_DBG_SB_SM_RST           0x0
#define RXM_RXM_MPX_DBG_SPARE_1_RST         0x0
#define RXM_RXM_MPX_DBG_WR_SM_RST           0x0
#define RXM_RXM_MPX_DBG_RD_SM_RST           0x0
#define RXM_RXM_MPX_DBG_MPX_SM_RST          0x0

__INLINE void rxm_rxm_mpx_dbg_unpack(uint8_t* w2_e_sm, uint8_t* spare2, uint8_t* dra_sm, uint8_t* st_sm, uint8_t* sb_sm, uint8_t* spare1, uint8_t* wr_sm, uint8_t* rd_sm, uint8_t* mpx_sm)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MPX_DBG_ADDR);

	*w2_e_sm = (localVal & ((uint32_t)0xF8000000)) >>  27;
	*spare2 = (localVal & ((uint32_t)0x04000000)) >>  26;
	*dra_sm = (localVal & ((uint32_t)0x03000000)) >>  24;
	*st_sm = (localVal & ((uint32_t)0x00F00000)) >>  20;
	*sb_sm = (localVal & ((uint32_t)0x000F0000)) >>  16;
	*spare1 = (localVal & ((uint32_t)0x00008000)) >>  15;
	*wr_sm = (localVal & ((uint32_t)0x00007C00)) >>  10;
	*rd_sm = (localVal & ((uint32_t)0x000003E0)) >>  5;
	*mpx_sm = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t rxm_rxm_mpx_dbg_w_2_e_sm_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MPX_DBG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xF8000000)) >> 27);
}
__INLINE uint8_t rxm_rxm_mpx_dbg_spare_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MPX_DBG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x04000000)) >> 26);
}
__INLINE uint8_t rxm_rxm_mpx_dbg_dra_sm_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MPX_DBG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x03000000)) >> 24);
}
__INLINE uint8_t rxm_rxm_mpx_dbg_st_sm_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MPX_DBG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00F00000)) >> 20);
}
__INLINE uint8_t rxm_rxm_mpx_dbg_sb_sm_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MPX_DBG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000F0000)) >> 16);
}
__INLINE uint8_t rxm_rxm_mpx_dbg_spare_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MPX_DBG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE uint8_t rxm_rxm_mpx_dbg_wr_sm_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MPX_DBG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007C00)) >> 10);
}
__INLINE uint8_t rxm_rxm_mpx_dbg_rd_sm_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MPX_DBG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000003E0)) >> 5);
}
__INLINE uint8_t rxm_rxm_mpx_dbg_mpx_sm_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_MPX_DBG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}

/**
 * @brief RXM_ARB_CLS_AXI_DBG register definition
 *  ARB CLS and AXI debug state machines register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:12 AXI_WR_SM                 0x0
 *    11:10 spare2                    0x0
 *    09:08 AXI_RD_SM                 0x0
 *    07:04 CLS_SM                    0x0
 *    03    spare1                    0              
 *    02:00 ARB_SM                    0x0
 * </pre>
 */
#define RXM_RXM_ARB_CLS_AXI_DBG_ADDR        (REG_RXM_BASE_ADDR+0x0000028C)
#define RXM_RXM_ARB_CLS_AXI_DBG_OFFSET      0x0000028C
#define RXM_RXM_ARB_CLS_AXI_DBG_INDEX       0x000000A3
#define RXM_RXM_ARB_CLS_AXI_DBG_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_arb_cls_axi_dbg_get(void)
{
	return REG_PL_RD(RXM_RXM_ARB_CLS_AXI_DBG_ADDR);
}

// field definitions
#define RXM_RXM_ARB_CLS_AXI_DBG_AXI_WR_SM_MASK    ((uint32_t)0x0000F000)
#define RXM_RXM_ARB_CLS_AXI_DBG_AXI_WR_SM_LSB    12
#define RXM_RXM_ARB_CLS_AXI_DBG_AXI_WR_SM_WIDTH    ((uint32_t)0x00000004)
#define RXM_RXM_ARB_CLS_AXI_DBG_SPARE_2_MASK    ((uint32_t)0x00000C00)
#define RXM_RXM_ARB_CLS_AXI_DBG_SPARE_2_LSB    10
#define RXM_RXM_ARB_CLS_AXI_DBG_SPARE_2_WIDTH    ((uint32_t)0x00000002)
#define RXM_RXM_ARB_CLS_AXI_DBG_AXI_RD_SM_MASK    ((uint32_t)0x00000300)
#define RXM_RXM_ARB_CLS_AXI_DBG_AXI_RD_SM_LSB    8
#define RXM_RXM_ARB_CLS_AXI_DBG_AXI_RD_SM_WIDTH    ((uint32_t)0x00000002)
#define RXM_RXM_ARB_CLS_AXI_DBG_CLS_SM_MASK    ((uint32_t)0x000000F0)
#define RXM_RXM_ARB_CLS_AXI_DBG_CLS_SM_LSB    4
#define RXM_RXM_ARB_CLS_AXI_DBG_CLS_SM_WIDTH    ((uint32_t)0x00000004)
#define RXM_RXM_ARB_CLS_AXI_DBG_SPARE_1_BIT    ((uint32_t)0x00000008)
#define RXM_RXM_ARB_CLS_AXI_DBG_SPARE_1_POS    3
#define RXM_RXM_ARB_CLS_AXI_DBG_ARB_SM_MASK    ((uint32_t)0x00000007)
#define RXM_RXM_ARB_CLS_AXI_DBG_ARB_SM_LSB    0
#define RXM_RXM_ARB_CLS_AXI_DBG_ARB_SM_WIDTH    ((uint32_t)0x00000003)

#define RXM_RXM_ARB_CLS_AXI_DBG_AXI_WR_SM_RST    0x0
#define RXM_RXM_ARB_CLS_AXI_DBG_SPARE_2_RST    0x0
#define RXM_RXM_ARB_CLS_AXI_DBG_AXI_RD_SM_RST    0x0
#define RXM_RXM_ARB_CLS_AXI_DBG_CLS_SM_RST    0x0
#define RXM_RXM_ARB_CLS_AXI_DBG_SPARE_1_RST    0x0
#define RXM_RXM_ARB_CLS_AXI_DBG_ARB_SM_RST    0x0

__INLINE void rxm_rxm_arb_cls_axi_dbg_unpack(uint8_t* axi_wr_sm, uint8_t* spare2, uint8_t* axi_rd_sm, uint8_t* cls_sm, uint8_t* spare1, uint8_t* arb_sm)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_ARB_CLS_AXI_DBG_ADDR);

	*axi_wr_sm = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*spare2 = (localVal & ((uint32_t)0x00000C00)) >>  10;
	*axi_rd_sm = (localVal & ((uint32_t)0x00000300)) >>  8;
	*cls_sm = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*spare1 = (localVal & ((uint32_t)0x00000008)) >>  3;
	*arb_sm = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t rxm_rxm_arb_cls_axi_dbg_axi_wr_sm_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_ARB_CLS_AXI_DBG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE uint8_t rxm_rxm_arb_cls_axi_dbg_spare_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_ARB_CLS_AXI_DBG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000C00)) >> 10);
}
__INLINE uint8_t rxm_rxm_arb_cls_axi_dbg_axi_rd_sm_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_ARB_CLS_AXI_DBG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000300)) >> 8);
}
__INLINE uint8_t rxm_rxm_arb_cls_axi_dbg_cls_sm_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_ARB_CLS_AXI_DBG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t rxm_rxm_arb_cls_axi_dbg_spare_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_ARB_CLS_AXI_DBG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE uint8_t rxm_rxm_arb_cls_axi_dbg_arb_sm_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_ARB_CLS_AXI_DBG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}

/**
 * @brief RXM_DBG_CONFIG register definition
 *  LCU debug port configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    04    DBG_EN                    0              
 *    03:00 DBG_SEL                   0x0
 * </pre>
 */
#define RXM_RXM_DBG_CONFIG_ADDR        (REG_RXM_BASE_ADDR+0x00000290)
#define RXM_RXM_DBG_CONFIG_OFFSET      0x00000290
#define RXM_RXM_DBG_CONFIG_INDEX       0x000000A4
#define RXM_RXM_DBG_CONFIG_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_dbg_config_get(void)
{
	return REG_PL_RD(RXM_RXM_DBG_CONFIG_ADDR);
}

__INLINE void rxm_rxm_dbg_config_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_DBG_CONFIG_ADDR, value);
}

// field definitions
#define RXM_RXM_DBG_CONFIG_DBG_EN_BIT       ((uint32_t)0x00000010)
#define RXM_RXM_DBG_CONFIG_DBG_EN_POS       4
#define RXM_RXM_DBG_CONFIG_DBG_SEL_MASK     ((uint32_t)0x0000000F)
#define RXM_RXM_DBG_CONFIG_DBG_SEL_LSB      0
#define RXM_RXM_DBG_CONFIG_DBG_SEL_WIDTH    ((uint32_t)0x00000004)

#define RXM_RXM_DBG_CONFIG_DBG_EN_RST       0x0
#define RXM_RXM_DBG_CONFIG_DBG_SEL_RST      0x0

__INLINE void rxm_rxm_dbg_config_pack(uint8_t dbg_en, uint8_t dbg_sel)
{
	ASSERT_ERR((((uint32_t)dbg_en << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)dbg_sel << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RXM_RXM_DBG_CONFIG_ADDR,  ((uint32_t)dbg_en << 4) |((uint32_t)dbg_sel << 0));
}

__INLINE void rxm_rxm_dbg_config_unpack(uint8_t* dbg_en, uint8_t* dbg_sel)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_DBG_CONFIG_ADDR);

	*dbg_en = (localVal & ((uint32_t)0x00000010)) >>  4;
	*dbg_sel = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t rxm_rxm_dbg_config_dbg_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_DBG_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void rxm_rxm_dbg_config_dbg_en_setf(uint8_t dbgen)
{
	ASSERT_ERR((((uint32_t)dbgen << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(RXM_RXM_DBG_CONFIG_ADDR, (REG_PL_RD(RXM_RXM_DBG_CONFIG_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)dbgen <<4));
}
__INLINE uint8_t rxm_rxm_dbg_config_dbg_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_DBG_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void rxm_rxm_dbg_config_dbg_sel_setf(uint8_t dbgsel)
{
	ASSERT_ERR((((uint32_t)dbgsel << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RXM_RXM_DBG_CONFIG_ADDR, (REG_PL_RD(RXM_RXM_DBG_CONFIG_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)dbgsel <<0));
}

/**
 * @brief RXM_DBG register definition
 *  debug data towards LCU  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DBG_DATA                  0x0
 * </pre>
 */
#define RXM_RXM_DBG_ADDR        (REG_RXM_BASE_ADDR+0x00000294)
#define RXM_RXM_DBG_OFFSET      0x00000294
#define RXM_RXM_DBG_INDEX       0x000000A5
#define RXM_RXM_DBG_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_dbg_get(void)
{
	return REG_PL_RD(RXM_RXM_DBG_ADDR);
}

// field definitions
#define RXM_RXM_DBG_DBG_DATA_MASK           ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_DBG_DBG_DATA_LSB            0
#define RXM_RXM_DBG_DBG_DATA_WIDTH          ((uint32_t)0x00000020)

#define RXM_RXM_DBG_DBG_DATA_RST            0x0

__INLINE uint32_t rxm_rxm_dbg_dbg_data_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_DBG_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RXM_USER_0_MPDU_CNT register definition
 *  Number of received MPDU’s per user register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 USER_MPDU_CNT             0x0
 * </pre>
 */
#define RXM_RXM_USER_0_MPDU_CNT_ADDR        (REG_RXM_BASE_ADDR+0x000002A0)
#define RXM_RXM_USER_0_MPDU_CNT_OFFSET      0x000002A0
#define RXM_RXM_USER_0_MPDU_CNT_INDEX       0x000000A8
#define RXM_RXM_USER_0_MPDU_CNT_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_user_0_mpdu_cnt_get(void)
{
	return REG_PL_RD(RXM_RXM_USER_0_MPDU_CNT_ADDR);
}

__INLINE void rxm_rxm_user_0_mpdu_cnt_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_USER_0_MPDU_CNT_ADDR, value);
}

// field definitions
#define RXM_RXM_USER_0_MPDU_CNT_USER_MPDU_CNT_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_USER_0_MPDU_CNT_USER_MPDU_CNT_LSB    0
#define RXM_RXM_USER_0_MPDU_CNT_USER_MPDU_CNT_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_USER_0_MPDU_CNT_USER_MPDU_CNT_RST    0x0

__INLINE uint32_t rxm_rxm_user_0_mpdu_cnt_user_mpdu_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_USER_0_MPDU_CNT_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_user_0_mpdu_cnt_user_mpdu_cnt_setf(uint32_t usermpducnt)
{
	ASSERT_ERR((((uint32_t)usermpducnt << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_USER_0_MPDU_CNT_ADDR, (uint32_t)usermpducnt << 0);
}

/**
 * @brief RXM_USER_1_MPDU_CNT register definition
 *  Number of received MPDU’s per user register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 USER_MPDU_CNT             0x0
 * </pre>
 */
#define RXM_RXM_USER_1_MPDU_CNT_ADDR        (REG_RXM_BASE_ADDR+0x000002A4)
#define RXM_RXM_USER_1_MPDU_CNT_OFFSET      0x000002A4
#define RXM_RXM_USER_1_MPDU_CNT_INDEX       0x000000A9
#define RXM_RXM_USER_1_MPDU_CNT_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_user_1_mpdu_cnt_get(void)
{
	return REG_PL_RD(RXM_RXM_USER_1_MPDU_CNT_ADDR);
}

__INLINE void rxm_rxm_user_1_mpdu_cnt_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_USER_1_MPDU_CNT_ADDR, value);
}

// field definitions
#define RXM_RXM_USER_1_MPDU_CNT_USER_MPDU_CNT_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_USER_1_MPDU_CNT_USER_MPDU_CNT_LSB    0
#define RXM_RXM_USER_1_MPDU_CNT_USER_MPDU_CNT_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_USER_1_MPDU_CNT_USER_MPDU_CNT_RST    0x0

__INLINE uint32_t rxm_rxm_user_1_mpdu_cnt_user_mpdu_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_USER_1_MPDU_CNT_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_user_1_mpdu_cnt_user_mpdu_cnt_setf(uint32_t usermpducnt)
{
	ASSERT_ERR((((uint32_t)usermpducnt << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_USER_1_MPDU_CNT_ADDR, (uint32_t)usermpducnt << 0);
}

/**
 * @brief RXM_USER_2_MPDU_CNT register definition
 *  Number of received MPDU’s per user register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 USER_MPDU_CNT             0x0
 * </pre>
 */
#define RXM_RXM_USER_2_MPDU_CNT_ADDR        (REG_RXM_BASE_ADDR+0x000002A8)
#define RXM_RXM_USER_2_MPDU_CNT_OFFSET      0x000002A8
#define RXM_RXM_USER_2_MPDU_CNT_INDEX       0x000000AA
#define RXM_RXM_USER_2_MPDU_CNT_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_user_2_mpdu_cnt_get(void)
{
	return REG_PL_RD(RXM_RXM_USER_2_MPDU_CNT_ADDR);
}

__INLINE void rxm_rxm_user_2_mpdu_cnt_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_USER_2_MPDU_CNT_ADDR, value);
}

// field definitions
#define RXM_RXM_USER_2_MPDU_CNT_USER_MPDU_CNT_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_USER_2_MPDU_CNT_USER_MPDU_CNT_LSB    0
#define RXM_RXM_USER_2_MPDU_CNT_USER_MPDU_CNT_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_USER_2_MPDU_CNT_USER_MPDU_CNT_RST    0x0

__INLINE uint32_t rxm_rxm_user_2_mpdu_cnt_user_mpdu_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_USER_2_MPDU_CNT_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_user_2_mpdu_cnt_user_mpdu_cnt_setf(uint32_t usermpducnt)
{
	ASSERT_ERR((((uint32_t)usermpducnt << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_USER_2_MPDU_CNT_ADDR, (uint32_t)usermpducnt << 0);
}

/**
 * @brief RXM_USER_3_MPDU_CNT register definition
 *  Number of received MPDU’s per user register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 USER_MPDU_CNT             0x0
 * </pre>
 */
#define RXM_RXM_USER_3_MPDU_CNT_ADDR        (REG_RXM_BASE_ADDR+0x000002AC)
#define RXM_RXM_USER_3_MPDU_CNT_OFFSET      0x000002AC
#define RXM_RXM_USER_3_MPDU_CNT_INDEX       0x000000AB
#define RXM_RXM_USER_3_MPDU_CNT_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_user_3_mpdu_cnt_get(void)
{
	return REG_PL_RD(RXM_RXM_USER_3_MPDU_CNT_ADDR);
}

__INLINE void rxm_rxm_user_3_mpdu_cnt_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_USER_3_MPDU_CNT_ADDR, value);
}

// field definitions
#define RXM_RXM_USER_3_MPDU_CNT_USER_MPDU_CNT_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_USER_3_MPDU_CNT_USER_MPDU_CNT_LSB    0
#define RXM_RXM_USER_3_MPDU_CNT_USER_MPDU_CNT_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_USER_3_MPDU_CNT_USER_MPDU_CNT_RST    0x0

__INLINE uint32_t rxm_rxm_user_3_mpdu_cnt_user_mpdu_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_USER_3_MPDU_CNT_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_user_3_mpdu_cnt_user_mpdu_cnt_setf(uint32_t usermpducnt)
{
	ASSERT_ERR((((uint32_t)usermpducnt << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_USER_3_MPDU_CNT_ADDR, (uint32_t)usermpducnt << 0);
}

/**
 * @brief RXM_USER_4_MPDU_CNT register definition
 *  Number of received MPDU’s per user register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 USER_MPDU_CNT             0x0
 * </pre>
 */
#define RXM_RXM_USER_4_MPDU_CNT_ADDR        (REG_RXM_BASE_ADDR+0x000002B0)
#define RXM_RXM_USER_4_MPDU_CNT_OFFSET      0x000002B0
#define RXM_RXM_USER_4_MPDU_CNT_INDEX       0x000000AC
#define RXM_RXM_USER_4_MPDU_CNT_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_user_4_mpdu_cnt_get(void)
{
	return REG_PL_RD(RXM_RXM_USER_4_MPDU_CNT_ADDR);
}

__INLINE void rxm_rxm_user_4_mpdu_cnt_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_USER_4_MPDU_CNT_ADDR, value);
}

// field definitions
#define RXM_RXM_USER_4_MPDU_CNT_USER_MPDU_CNT_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_USER_4_MPDU_CNT_USER_MPDU_CNT_LSB    0
#define RXM_RXM_USER_4_MPDU_CNT_USER_MPDU_CNT_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_USER_4_MPDU_CNT_USER_MPDU_CNT_RST    0x0

__INLINE uint32_t rxm_rxm_user_4_mpdu_cnt_user_mpdu_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_USER_4_MPDU_CNT_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_user_4_mpdu_cnt_user_mpdu_cnt_setf(uint32_t usermpducnt)
{
	ASSERT_ERR((((uint32_t)usermpducnt << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_USER_4_MPDU_CNT_ADDR, (uint32_t)usermpducnt << 0);
}

/**
 * @brief RXM_USER_5_MPDU_CNT register definition
 *  Number of received MPDU’s per user register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 USER_MPDU_CNT             0x0
 * </pre>
 */
#define RXM_RXM_USER_5_MPDU_CNT_ADDR        (REG_RXM_BASE_ADDR+0x000002B4)
#define RXM_RXM_USER_5_MPDU_CNT_OFFSET      0x000002B4
#define RXM_RXM_USER_5_MPDU_CNT_INDEX       0x000000AD
#define RXM_RXM_USER_5_MPDU_CNT_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_user_5_mpdu_cnt_get(void)
{
	return REG_PL_RD(RXM_RXM_USER_5_MPDU_CNT_ADDR);
}

__INLINE void rxm_rxm_user_5_mpdu_cnt_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_USER_5_MPDU_CNT_ADDR, value);
}

// field definitions
#define RXM_RXM_USER_5_MPDU_CNT_USER_MPDU_CNT_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_USER_5_MPDU_CNT_USER_MPDU_CNT_LSB    0
#define RXM_RXM_USER_5_MPDU_CNT_USER_MPDU_CNT_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_USER_5_MPDU_CNT_USER_MPDU_CNT_RST    0x0

__INLINE uint32_t rxm_rxm_user_5_mpdu_cnt_user_mpdu_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_USER_5_MPDU_CNT_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_user_5_mpdu_cnt_user_mpdu_cnt_setf(uint32_t usermpducnt)
{
	ASSERT_ERR((((uint32_t)usermpducnt << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_USER_5_MPDU_CNT_ADDR, (uint32_t)usermpducnt << 0);
}

/**
 * @brief RXM_USER_6_MPDU_CNT register definition
 *  Number of received MPDU’s per user register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 USER_MPDU_CNT             0x0
 * </pre>
 */
#define RXM_RXM_USER_6_MPDU_CNT_ADDR        (REG_RXM_BASE_ADDR+0x000002B8)
#define RXM_RXM_USER_6_MPDU_CNT_OFFSET      0x000002B8
#define RXM_RXM_USER_6_MPDU_CNT_INDEX       0x000000AE
#define RXM_RXM_USER_6_MPDU_CNT_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_user_6_mpdu_cnt_get(void)
{
	return REG_PL_RD(RXM_RXM_USER_6_MPDU_CNT_ADDR);
}

__INLINE void rxm_rxm_user_6_mpdu_cnt_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_USER_6_MPDU_CNT_ADDR, value);
}

// field definitions
#define RXM_RXM_USER_6_MPDU_CNT_USER_MPDU_CNT_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_USER_6_MPDU_CNT_USER_MPDU_CNT_LSB    0
#define RXM_RXM_USER_6_MPDU_CNT_USER_MPDU_CNT_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_USER_6_MPDU_CNT_USER_MPDU_CNT_RST    0x0

__INLINE uint32_t rxm_rxm_user_6_mpdu_cnt_user_mpdu_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_USER_6_MPDU_CNT_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_user_6_mpdu_cnt_user_mpdu_cnt_setf(uint32_t usermpducnt)
{
	ASSERT_ERR((((uint32_t)usermpducnt << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_USER_6_MPDU_CNT_ADDR, (uint32_t)usermpducnt << 0);
}

/**
 * @brief RXM_USER_7_MPDU_CNT register definition
 *  Number of received MPDU’s per user register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 USER_MPDU_CNT             0x0
 * </pre>
 */
#define RXM_RXM_USER_7_MPDU_CNT_ADDR        (REG_RXM_BASE_ADDR+0x000002BC)
#define RXM_RXM_USER_7_MPDU_CNT_OFFSET      0x000002BC
#define RXM_RXM_USER_7_MPDU_CNT_INDEX       0x000000AF
#define RXM_RXM_USER_7_MPDU_CNT_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_user_7_mpdu_cnt_get(void)
{
	return REG_PL_RD(RXM_RXM_USER_7_MPDU_CNT_ADDR);
}

__INLINE void rxm_rxm_user_7_mpdu_cnt_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_USER_7_MPDU_CNT_ADDR, value);
}

// field definitions
#define RXM_RXM_USER_7_MPDU_CNT_USER_MPDU_CNT_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_USER_7_MPDU_CNT_USER_MPDU_CNT_LSB    0
#define RXM_RXM_USER_7_MPDU_CNT_USER_MPDU_CNT_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_USER_7_MPDU_CNT_USER_MPDU_CNT_RST    0x0

__INLINE uint32_t rxm_rxm_user_7_mpdu_cnt_user_mpdu_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_USER_7_MPDU_CNT_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_user_7_mpdu_cnt_user_mpdu_cnt_setf(uint32_t usermpducnt)
{
	ASSERT_ERR((((uint32_t)usermpducnt << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_USER_7_MPDU_CNT_ADDR, (uint32_t)usermpducnt << 0);
}

/**
 * @brief RXM_USER_8_MPDU_CNT register definition
 *  Number of received MPDU’s per user register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 USER_MPDU_CNT             0x0
 * </pre>
 */
#define RXM_RXM_USER_8_MPDU_CNT_ADDR        (REG_RXM_BASE_ADDR+0x000002C0)
#define RXM_RXM_USER_8_MPDU_CNT_OFFSET      0x000002C0
#define RXM_RXM_USER_8_MPDU_CNT_INDEX       0x000000B0
#define RXM_RXM_USER_8_MPDU_CNT_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_user_8_mpdu_cnt_get(void)
{
	return REG_PL_RD(RXM_RXM_USER_8_MPDU_CNT_ADDR);
}

__INLINE void rxm_rxm_user_8_mpdu_cnt_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_USER_8_MPDU_CNT_ADDR, value);
}

// field definitions
#define RXM_RXM_USER_8_MPDU_CNT_USER_MPDU_CNT_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_USER_8_MPDU_CNT_USER_MPDU_CNT_LSB    0
#define RXM_RXM_USER_8_MPDU_CNT_USER_MPDU_CNT_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_USER_8_MPDU_CNT_USER_MPDU_CNT_RST    0x0

__INLINE uint32_t rxm_rxm_user_8_mpdu_cnt_user_mpdu_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_USER_8_MPDU_CNT_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_user_8_mpdu_cnt_user_mpdu_cnt_setf(uint32_t usermpducnt)
{
	ASSERT_ERR((((uint32_t)usermpducnt << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_USER_8_MPDU_CNT_ADDR, (uint32_t)usermpducnt << 0);
}

/**
 * @brief RXM_USER_9_MPDU_CNT register definition
 *  Number of received MPDU’s per user register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 USER_MPDU_CNT             0x0
 * </pre>
 */
#define RXM_RXM_USER_9_MPDU_CNT_ADDR        (REG_RXM_BASE_ADDR+0x000002C4)
#define RXM_RXM_USER_9_MPDU_CNT_OFFSET      0x000002C4
#define RXM_RXM_USER_9_MPDU_CNT_INDEX       0x000000B1
#define RXM_RXM_USER_9_MPDU_CNT_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_user_9_mpdu_cnt_get(void)
{
	return REG_PL_RD(RXM_RXM_USER_9_MPDU_CNT_ADDR);
}

__INLINE void rxm_rxm_user_9_mpdu_cnt_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_USER_9_MPDU_CNT_ADDR, value);
}

// field definitions
#define RXM_RXM_USER_9_MPDU_CNT_USER_MPDU_CNT_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_USER_9_MPDU_CNT_USER_MPDU_CNT_LSB    0
#define RXM_RXM_USER_9_MPDU_CNT_USER_MPDU_CNT_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_USER_9_MPDU_CNT_USER_MPDU_CNT_RST    0x0

__INLINE uint32_t rxm_rxm_user_9_mpdu_cnt_user_mpdu_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_USER_9_MPDU_CNT_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_user_9_mpdu_cnt_user_mpdu_cnt_setf(uint32_t usermpducnt)
{
	ASSERT_ERR((((uint32_t)usermpducnt << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_USER_9_MPDU_CNT_ADDR, (uint32_t)usermpducnt << 0);
}

/**
 * @brief RXM_USER_10_MPDU_CNT register definition
 *  Number of received MPDU’s per user register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 USER_MPDU_CNT             0x0
 * </pre>
 */
#define RXM_RXM_USER_10_MPDU_CNT_ADDR        (REG_RXM_BASE_ADDR+0x000002C8)
#define RXM_RXM_USER_10_MPDU_CNT_OFFSET      0x000002C8
#define RXM_RXM_USER_10_MPDU_CNT_INDEX       0x000000B2
#define RXM_RXM_USER_10_MPDU_CNT_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_user_10_mpdu_cnt_get(void)
{
	return REG_PL_RD(RXM_RXM_USER_10_MPDU_CNT_ADDR);
}

__INLINE void rxm_rxm_user_10_mpdu_cnt_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_USER_10_MPDU_CNT_ADDR, value);
}

// field definitions
#define RXM_RXM_USER_10_MPDU_CNT_USER_MPDU_CNT_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_USER_10_MPDU_CNT_USER_MPDU_CNT_LSB    0
#define RXM_RXM_USER_10_MPDU_CNT_USER_MPDU_CNT_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_USER_10_MPDU_CNT_USER_MPDU_CNT_RST    0x0

__INLINE uint32_t rxm_rxm_user_10_mpdu_cnt_user_mpdu_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_USER_10_MPDU_CNT_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_user_10_mpdu_cnt_user_mpdu_cnt_setf(uint32_t usermpducnt)
{
	ASSERT_ERR((((uint32_t)usermpducnt << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_USER_10_MPDU_CNT_ADDR, (uint32_t)usermpducnt << 0);
}

/**
 * @brief RXM_USER_11_MPDU_CNT register definition
 *  Number of received MPDU’s per user register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 USER_MPDU_CNT             0x0
 * </pre>
 */
#define RXM_RXM_USER_11_MPDU_CNT_ADDR        (REG_RXM_BASE_ADDR+0x000002CC)
#define RXM_RXM_USER_11_MPDU_CNT_OFFSET      0x000002CC
#define RXM_RXM_USER_11_MPDU_CNT_INDEX       0x000000B3
#define RXM_RXM_USER_11_MPDU_CNT_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_user_11_mpdu_cnt_get(void)
{
	return REG_PL_RD(RXM_RXM_USER_11_MPDU_CNT_ADDR);
}

__INLINE void rxm_rxm_user_11_mpdu_cnt_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_USER_11_MPDU_CNT_ADDR, value);
}

// field definitions
#define RXM_RXM_USER_11_MPDU_CNT_USER_MPDU_CNT_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_USER_11_MPDU_CNT_USER_MPDU_CNT_LSB    0
#define RXM_RXM_USER_11_MPDU_CNT_USER_MPDU_CNT_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_USER_11_MPDU_CNT_USER_MPDU_CNT_RST    0x0

__INLINE uint32_t rxm_rxm_user_11_mpdu_cnt_user_mpdu_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_USER_11_MPDU_CNT_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_user_11_mpdu_cnt_user_mpdu_cnt_setf(uint32_t usermpducnt)
{
	ASSERT_ERR((((uint32_t)usermpducnt << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_USER_11_MPDU_CNT_ADDR, (uint32_t)usermpducnt << 0);
}

/**
 * @brief RXM_USER_12_MPDU_CNT register definition
 *  Number of received MPDU’s per user register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 USER_MPDU_CNT             0x0
 * </pre>
 */
#define RXM_RXM_USER_12_MPDU_CNT_ADDR        (REG_RXM_BASE_ADDR+0x000002D0)
#define RXM_RXM_USER_12_MPDU_CNT_OFFSET      0x000002D0
#define RXM_RXM_USER_12_MPDU_CNT_INDEX       0x000000B4
#define RXM_RXM_USER_12_MPDU_CNT_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_user_12_mpdu_cnt_get(void)
{
	return REG_PL_RD(RXM_RXM_USER_12_MPDU_CNT_ADDR);
}

__INLINE void rxm_rxm_user_12_mpdu_cnt_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_USER_12_MPDU_CNT_ADDR, value);
}

// field definitions
#define RXM_RXM_USER_12_MPDU_CNT_USER_MPDU_CNT_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_USER_12_MPDU_CNT_USER_MPDU_CNT_LSB    0
#define RXM_RXM_USER_12_MPDU_CNT_USER_MPDU_CNT_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_USER_12_MPDU_CNT_USER_MPDU_CNT_RST    0x0

__INLINE uint32_t rxm_rxm_user_12_mpdu_cnt_user_mpdu_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_USER_12_MPDU_CNT_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_user_12_mpdu_cnt_user_mpdu_cnt_setf(uint32_t usermpducnt)
{
	ASSERT_ERR((((uint32_t)usermpducnt << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_USER_12_MPDU_CNT_ADDR, (uint32_t)usermpducnt << 0);
}

/**
 * @brief RXM_USER_13_MPDU_CNT register definition
 *  Number of received MPDU’s per user register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 USER_MPDU_CNT             0x0
 * </pre>
 */
#define RXM_RXM_USER_13_MPDU_CNT_ADDR        (REG_RXM_BASE_ADDR+0x000002D4)
#define RXM_RXM_USER_13_MPDU_CNT_OFFSET      0x000002D4
#define RXM_RXM_USER_13_MPDU_CNT_INDEX       0x000000B5
#define RXM_RXM_USER_13_MPDU_CNT_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_user_13_mpdu_cnt_get(void)
{
	return REG_PL_RD(RXM_RXM_USER_13_MPDU_CNT_ADDR);
}

__INLINE void rxm_rxm_user_13_mpdu_cnt_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_USER_13_MPDU_CNT_ADDR, value);
}

// field definitions
#define RXM_RXM_USER_13_MPDU_CNT_USER_MPDU_CNT_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_USER_13_MPDU_CNT_USER_MPDU_CNT_LSB    0
#define RXM_RXM_USER_13_MPDU_CNT_USER_MPDU_CNT_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_USER_13_MPDU_CNT_USER_MPDU_CNT_RST    0x0

__INLINE uint32_t rxm_rxm_user_13_mpdu_cnt_user_mpdu_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_USER_13_MPDU_CNT_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_user_13_mpdu_cnt_user_mpdu_cnt_setf(uint32_t usermpducnt)
{
	ASSERT_ERR((((uint32_t)usermpducnt << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_USER_13_MPDU_CNT_ADDR, (uint32_t)usermpducnt << 0);
}

/**
 * @brief RXM_USER_14_MPDU_CNT register definition
 *  Number of received MPDU’s per user register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 USER_MPDU_CNT             0x0
 * </pre>
 */
#define RXM_RXM_USER_14_MPDU_CNT_ADDR        (REG_RXM_BASE_ADDR+0x000002D8)
#define RXM_RXM_USER_14_MPDU_CNT_OFFSET      0x000002D8
#define RXM_RXM_USER_14_MPDU_CNT_INDEX       0x000000B6
#define RXM_RXM_USER_14_MPDU_CNT_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_user_14_mpdu_cnt_get(void)
{
	return REG_PL_RD(RXM_RXM_USER_14_MPDU_CNT_ADDR);
}

__INLINE void rxm_rxm_user_14_mpdu_cnt_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_USER_14_MPDU_CNT_ADDR, value);
}

// field definitions
#define RXM_RXM_USER_14_MPDU_CNT_USER_MPDU_CNT_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_USER_14_MPDU_CNT_USER_MPDU_CNT_LSB    0
#define RXM_RXM_USER_14_MPDU_CNT_USER_MPDU_CNT_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_USER_14_MPDU_CNT_USER_MPDU_CNT_RST    0x0

__INLINE uint32_t rxm_rxm_user_14_mpdu_cnt_user_mpdu_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_USER_14_MPDU_CNT_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_user_14_mpdu_cnt_user_mpdu_cnt_setf(uint32_t usermpducnt)
{
	ASSERT_ERR((((uint32_t)usermpducnt << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_USER_14_MPDU_CNT_ADDR, (uint32_t)usermpducnt << 0);
}

/**
 * @brief RXM_USER_15_MPDU_CNT register definition
 *  Number of received MPDU’s per user register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 USER_MPDU_CNT             0x0
 * </pre>
 */
#define RXM_RXM_USER_15_MPDU_CNT_ADDR        (REG_RXM_BASE_ADDR+0x000002DC)
#define RXM_RXM_USER_15_MPDU_CNT_OFFSET      0x000002DC
#define RXM_RXM_USER_15_MPDU_CNT_INDEX       0x000000B7
#define RXM_RXM_USER_15_MPDU_CNT_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_user_15_mpdu_cnt_get(void)
{
	return REG_PL_RD(RXM_RXM_USER_15_MPDU_CNT_ADDR);
}

__INLINE void rxm_rxm_user_15_mpdu_cnt_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_USER_15_MPDU_CNT_ADDR, value);
}

// field definitions
#define RXM_RXM_USER_15_MPDU_CNT_USER_MPDU_CNT_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_USER_15_MPDU_CNT_USER_MPDU_CNT_LSB    0
#define RXM_RXM_USER_15_MPDU_CNT_USER_MPDU_CNT_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_USER_15_MPDU_CNT_USER_MPDU_CNT_RST    0x0

__INLINE uint32_t rxm_rxm_user_15_mpdu_cnt_user_mpdu_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_USER_15_MPDU_CNT_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_user_15_mpdu_cnt_user_mpdu_cnt_setf(uint32_t usermpducnt)
{
	ASSERT_ERR((((uint32_t)usermpducnt << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_USER_15_MPDU_CNT_ADDR, (uint32_t)usermpducnt << 0);
}

/**
 * @brief RXM_PPDU_STAT_USER_0_7_PSDU register definition
 *  Last processed PSDU per user register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:28 USER7_PSDU                0x0
 *    27:24 USER6_PSDU                0x0
 *    23:20 USER5_PSDU                0x0
 *    19:16 USER4_PSDU                0x0
 *    15:12 USER3_PSDU                0x0
 *    11:08 USER2_PSDU                0x0
 *    07:04 USER1_PSDU                0x0
 *    03:00 USER0_PSDU                0x0
 * </pre>
 */
#define RXM_RXM_PPDU_STAT_USER_0_7_PSDU_ADDR        (REG_RXM_BASE_ADDR+0x000002E0)
#define RXM_RXM_PPDU_STAT_USER_0_7_PSDU_OFFSET      0x000002E0
#define RXM_RXM_PPDU_STAT_USER_0_7_PSDU_INDEX       0x000000B8
#define RXM_RXM_PPDU_STAT_USER_0_7_PSDU_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_ppdu_stat_user_0_7_psdu_get(void)
{
	return REG_PL_RD(RXM_RXM_PPDU_STAT_USER_0_7_PSDU_ADDR);
}

// field definitions
#define RXM_RXM_PPDU_STAT_USER_0_7_PSDU_USER_7_PSDU_MASK    ((uint32_t)0xF0000000)
#define RXM_RXM_PPDU_STAT_USER_0_7_PSDU_USER_7_PSDU_LSB    28
#define RXM_RXM_PPDU_STAT_USER_0_7_PSDU_USER_7_PSDU_WIDTH    ((uint32_t)0x00000004)
#define RXM_RXM_PPDU_STAT_USER_0_7_PSDU_USER_6_PSDU_MASK    ((uint32_t)0x0F000000)
#define RXM_RXM_PPDU_STAT_USER_0_7_PSDU_USER_6_PSDU_LSB    24
#define RXM_RXM_PPDU_STAT_USER_0_7_PSDU_USER_6_PSDU_WIDTH    ((uint32_t)0x00000004)
#define RXM_RXM_PPDU_STAT_USER_0_7_PSDU_USER_5_PSDU_MASK    ((uint32_t)0x00F00000)
#define RXM_RXM_PPDU_STAT_USER_0_7_PSDU_USER_5_PSDU_LSB    20
#define RXM_RXM_PPDU_STAT_USER_0_7_PSDU_USER_5_PSDU_WIDTH    ((uint32_t)0x00000004)
#define RXM_RXM_PPDU_STAT_USER_0_7_PSDU_USER_4_PSDU_MASK    ((uint32_t)0x000F0000)
#define RXM_RXM_PPDU_STAT_USER_0_7_PSDU_USER_4_PSDU_LSB    16
#define RXM_RXM_PPDU_STAT_USER_0_7_PSDU_USER_4_PSDU_WIDTH    ((uint32_t)0x00000004)
#define RXM_RXM_PPDU_STAT_USER_0_7_PSDU_USER_3_PSDU_MASK    ((uint32_t)0x0000F000)
#define RXM_RXM_PPDU_STAT_USER_0_7_PSDU_USER_3_PSDU_LSB    12
#define RXM_RXM_PPDU_STAT_USER_0_7_PSDU_USER_3_PSDU_WIDTH    ((uint32_t)0x00000004)
#define RXM_RXM_PPDU_STAT_USER_0_7_PSDU_USER_2_PSDU_MASK    ((uint32_t)0x00000F00)
#define RXM_RXM_PPDU_STAT_USER_0_7_PSDU_USER_2_PSDU_LSB    8
#define RXM_RXM_PPDU_STAT_USER_0_7_PSDU_USER_2_PSDU_WIDTH    ((uint32_t)0x00000004)
#define RXM_RXM_PPDU_STAT_USER_0_7_PSDU_USER_1_PSDU_MASK    ((uint32_t)0x000000F0)
#define RXM_RXM_PPDU_STAT_USER_0_7_PSDU_USER_1_PSDU_LSB    4
#define RXM_RXM_PPDU_STAT_USER_0_7_PSDU_USER_1_PSDU_WIDTH    ((uint32_t)0x00000004)
#define RXM_RXM_PPDU_STAT_USER_0_7_PSDU_USER_0_PSDU_MASK    ((uint32_t)0x0000000F)
#define RXM_RXM_PPDU_STAT_USER_0_7_PSDU_USER_0_PSDU_LSB    0
#define RXM_RXM_PPDU_STAT_USER_0_7_PSDU_USER_0_PSDU_WIDTH    ((uint32_t)0x00000004)

#define RXM_RXM_PPDU_STAT_USER_0_7_PSDU_USER_7_PSDU_RST    0x0
#define RXM_RXM_PPDU_STAT_USER_0_7_PSDU_USER_6_PSDU_RST    0x0
#define RXM_RXM_PPDU_STAT_USER_0_7_PSDU_USER_5_PSDU_RST    0x0
#define RXM_RXM_PPDU_STAT_USER_0_7_PSDU_USER_4_PSDU_RST    0x0
#define RXM_RXM_PPDU_STAT_USER_0_7_PSDU_USER_3_PSDU_RST    0x0
#define RXM_RXM_PPDU_STAT_USER_0_7_PSDU_USER_2_PSDU_RST    0x0
#define RXM_RXM_PPDU_STAT_USER_0_7_PSDU_USER_1_PSDU_RST    0x0
#define RXM_RXM_PPDU_STAT_USER_0_7_PSDU_USER_0_PSDU_RST    0x0

__INLINE void rxm_rxm_ppdu_stat_user_0_7_psdu_unpack(uint8_t* user7_psdu, uint8_t* user6_psdu, uint8_t* user5_psdu, uint8_t* user4_psdu, uint8_t* user3_psdu, uint8_t* user2_psdu, uint8_t* user1_psdu, uint8_t* user0_psdu)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_STAT_USER_0_7_PSDU_ADDR);

	*user7_psdu = (localVal & ((uint32_t)0xF0000000)) >>  28;
	*user6_psdu = (localVal & ((uint32_t)0x0F000000)) >>  24;
	*user5_psdu = (localVal & ((uint32_t)0x00F00000)) >>  20;
	*user4_psdu = (localVal & ((uint32_t)0x000F0000)) >>  16;
	*user3_psdu = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*user2_psdu = (localVal & ((uint32_t)0x00000F00)) >>  8;
	*user1_psdu = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*user0_psdu = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t rxm_rxm_ppdu_stat_user_0_7_psdu_user_7_psdu_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_STAT_USER_0_7_PSDU_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xF0000000)) >> 28);
}
__INLINE uint8_t rxm_rxm_ppdu_stat_user_0_7_psdu_user_6_psdu_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_STAT_USER_0_7_PSDU_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0F000000)) >> 24);
}
__INLINE uint8_t rxm_rxm_ppdu_stat_user_0_7_psdu_user_5_psdu_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_STAT_USER_0_7_PSDU_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00F00000)) >> 20);
}
__INLINE uint8_t rxm_rxm_ppdu_stat_user_0_7_psdu_user_4_psdu_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_STAT_USER_0_7_PSDU_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000F0000)) >> 16);
}
__INLINE uint8_t rxm_rxm_ppdu_stat_user_0_7_psdu_user_3_psdu_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_STAT_USER_0_7_PSDU_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE uint8_t rxm_rxm_ppdu_stat_user_0_7_psdu_user_2_psdu_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_STAT_USER_0_7_PSDU_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000F00)) >> 8);
}
__INLINE uint8_t rxm_rxm_ppdu_stat_user_0_7_psdu_user_1_psdu_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_STAT_USER_0_7_PSDU_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t rxm_rxm_ppdu_stat_user_0_7_psdu_user_0_psdu_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_STAT_USER_0_7_PSDU_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}

/**
 * @brief RXM_PPDU_STAT_USER_8_15_PSDU register definition
 *  Last processed PSDU per user register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:28 USER15_PSDU               0x0
 *    27:24 USER14_PSDU               0x0
 *    23:20 USER13_PSDU               0x0
 *    19:16 USER12_PSDU               0x0
 *    15:12 USER11_PSDU               0x0
 *    11:08 USER10_PSDU               0x0
 *    07:04 USER9_PSDU                0x0
 *    03:00 USER8_PSDU                0x0
 * </pre>
 */
#define RXM_RXM_PPDU_STAT_USER_8_15_PSDU_ADDR        (REG_RXM_BASE_ADDR+0x000002E4)
#define RXM_RXM_PPDU_STAT_USER_8_15_PSDU_OFFSET      0x000002E4
#define RXM_RXM_PPDU_STAT_USER_8_15_PSDU_INDEX       0x000000B9
#define RXM_RXM_PPDU_STAT_USER_8_15_PSDU_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_ppdu_stat_user_8_15_psdu_get(void)
{
	return REG_PL_RD(RXM_RXM_PPDU_STAT_USER_8_15_PSDU_ADDR);
}

// field definitions
#define RXM_RXM_PPDU_STAT_USER_8_15_PSDU_USER_15_PSDU_MASK    ((uint32_t)0xF0000000)
#define RXM_RXM_PPDU_STAT_USER_8_15_PSDU_USER_15_PSDU_LSB    28
#define RXM_RXM_PPDU_STAT_USER_8_15_PSDU_USER_15_PSDU_WIDTH    ((uint32_t)0x00000004)
#define RXM_RXM_PPDU_STAT_USER_8_15_PSDU_USER_14_PSDU_MASK    ((uint32_t)0x0F000000)
#define RXM_RXM_PPDU_STAT_USER_8_15_PSDU_USER_14_PSDU_LSB    24
#define RXM_RXM_PPDU_STAT_USER_8_15_PSDU_USER_14_PSDU_WIDTH    ((uint32_t)0x00000004)
#define RXM_RXM_PPDU_STAT_USER_8_15_PSDU_USER_13_PSDU_MASK    ((uint32_t)0x00F00000)
#define RXM_RXM_PPDU_STAT_USER_8_15_PSDU_USER_13_PSDU_LSB    20
#define RXM_RXM_PPDU_STAT_USER_8_15_PSDU_USER_13_PSDU_WIDTH    ((uint32_t)0x00000004)
#define RXM_RXM_PPDU_STAT_USER_8_15_PSDU_USER_12_PSDU_MASK    ((uint32_t)0x000F0000)
#define RXM_RXM_PPDU_STAT_USER_8_15_PSDU_USER_12_PSDU_LSB    16
#define RXM_RXM_PPDU_STAT_USER_8_15_PSDU_USER_12_PSDU_WIDTH    ((uint32_t)0x00000004)
#define RXM_RXM_PPDU_STAT_USER_8_15_PSDU_USER_11_PSDU_MASK    ((uint32_t)0x0000F000)
#define RXM_RXM_PPDU_STAT_USER_8_15_PSDU_USER_11_PSDU_LSB    12
#define RXM_RXM_PPDU_STAT_USER_8_15_PSDU_USER_11_PSDU_WIDTH    ((uint32_t)0x00000004)
#define RXM_RXM_PPDU_STAT_USER_8_15_PSDU_USER_10_PSDU_MASK    ((uint32_t)0x00000F00)
#define RXM_RXM_PPDU_STAT_USER_8_15_PSDU_USER_10_PSDU_LSB    8
#define RXM_RXM_PPDU_STAT_USER_8_15_PSDU_USER_10_PSDU_WIDTH    ((uint32_t)0x00000004)
#define RXM_RXM_PPDU_STAT_USER_8_15_PSDU_USER_9_PSDU_MASK    ((uint32_t)0x000000F0)
#define RXM_RXM_PPDU_STAT_USER_8_15_PSDU_USER_9_PSDU_LSB    4
#define RXM_RXM_PPDU_STAT_USER_8_15_PSDU_USER_9_PSDU_WIDTH    ((uint32_t)0x00000004)
#define RXM_RXM_PPDU_STAT_USER_8_15_PSDU_USER_8_PSDU_MASK    ((uint32_t)0x0000000F)
#define RXM_RXM_PPDU_STAT_USER_8_15_PSDU_USER_8_PSDU_LSB    0
#define RXM_RXM_PPDU_STAT_USER_8_15_PSDU_USER_8_PSDU_WIDTH    ((uint32_t)0x00000004)

#define RXM_RXM_PPDU_STAT_USER_8_15_PSDU_USER_15_PSDU_RST    0x0
#define RXM_RXM_PPDU_STAT_USER_8_15_PSDU_USER_14_PSDU_RST    0x0
#define RXM_RXM_PPDU_STAT_USER_8_15_PSDU_USER_13_PSDU_RST    0x0
#define RXM_RXM_PPDU_STAT_USER_8_15_PSDU_USER_12_PSDU_RST    0x0
#define RXM_RXM_PPDU_STAT_USER_8_15_PSDU_USER_11_PSDU_RST    0x0
#define RXM_RXM_PPDU_STAT_USER_8_15_PSDU_USER_10_PSDU_RST    0x0
#define RXM_RXM_PPDU_STAT_USER_8_15_PSDU_USER_9_PSDU_RST    0x0
#define RXM_RXM_PPDU_STAT_USER_8_15_PSDU_USER_8_PSDU_RST    0x0

__INLINE void rxm_rxm_ppdu_stat_user_8_15_psdu_unpack(uint8_t* user15_psdu, uint8_t* user14_psdu, uint8_t* user13_psdu, uint8_t* user12_psdu, uint8_t* user11_psdu, uint8_t* user10_psdu, uint8_t* user9_psdu, uint8_t* user8_psdu)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_STAT_USER_8_15_PSDU_ADDR);

	*user15_psdu = (localVal & ((uint32_t)0xF0000000)) >>  28;
	*user14_psdu = (localVal & ((uint32_t)0x0F000000)) >>  24;
	*user13_psdu = (localVal & ((uint32_t)0x00F00000)) >>  20;
	*user12_psdu = (localVal & ((uint32_t)0x000F0000)) >>  16;
	*user11_psdu = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*user10_psdu = (localVal & ((uint32_t)0x00000F00)) >>  8;
	*user9_psdu = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*user8_psdu = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t rxm_rxm_ppdu_stat_user_8_15_psdu_user_15_psdu_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_STAT_USER_8_15_PSDU_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xF0000000)) >> 28);
}
__INLINE uint8_t rxm_rxm_ppdu_stat_user_8_15_psdu_user_14_psdu_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_STAT_USER_8_15_PSDU_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0F000000)) >> 24);
}
__INLINE uint8_t rxm_rxm_ppdu_stat_user_8_15_psdu_user_13_psdu_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_STAT_USER_8_15_PSDU_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00F00000)) >> 20);
}
__INLINE uint8_t rxm_rxm_ppdu_stat_user_8_15_psdu_user_12_psdu_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_STAT_USER_8_15_PSDU_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000F0000)) >> 16);
}
__INLINE uint8_t rxm_rxm_ppdu_stat_user_8_15_psdu_user_11_psdu_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_STAT_USER_8_15_PSDU_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE uint8_t rxm_rxm_ppdu_stat_user_8_15_psdu_user_10_psdu_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_STAT_USER_8_15_PSDU_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000F00)) >> 8);
}
__INLINE uint8_t rxm_rxm_ppdu_stat_user_8_15_psdu_user_9_psdu_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_STAT_USER_8_15_PSDU_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t rxm_rxm_ppdu_stat_user_8_15_psdu_user_8_psdu_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_STAT_USER_8_15_PSDU_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}

/**
 * @brief RXM_PPDU_STAT_USER_0_7_CLEAR register definition
 *  Clear user PSDU’s statistics register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:28 USER7_PSDUS_BMAP          0x0
 *    27:24 USER6_PSDUS_BMAP          0x0
 *    23:20 USER5_PSDUS_BMAP          0x0
 *    19:16 USER4_PSDUS_BMAP          0x0
 *    15:12 USER3_PSDUS_BMAP          0x0
 *    11:08 USER2_PSDUS_BMAP          0x0
 *    07:04 USER1_PSDUS_BMAP          0x0
 *    03:00 USER0_PSDUS_BMAP          0x0
 * </pre>
 */
#define RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_ADDR        (REG_RXM_BASE_ADDR+0x000002E8)
#define RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_OFFSET      0x000002E8
#define RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_INDEX       0x000000BA
#define RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_RESET       0x00000000

__INLINE void rxm_rxm_ppdu_stat_user_0_7_clear_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_ADDR, value);
}

// field definitions
#define RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_USER_7_PSDUS_BMAP_MASK    ((uint32_t)0xF0000000)
#define RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_USER_7_PSDUS_BMAP_LSB    28
#define RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_USER_7_PSDUS_BMAP_WIDTH    ((uint32_t)0x00000004)
#define RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_USER_6_PSDUS_BMAP_MASK    ((uint32_t)0x0F000000)
#define RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_USER_6_PSDUS_BMAP_LSB    24
#define RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_USER_6_PSDUS_BMAP_WIDTH    ((uint32_t)0x00000004)
#define RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_USER_5_PSDUS_BMAP_MASK    ((uint32_t)0x00F00000)
#define RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_USER_5_PSDUS_BMAP_LSB    20
#define RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_USER_5_PSDUS_BMAP_WIDTH    ((uint32_t)0x00000004)
#define RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_USER_4_PSDUS_BMAP_MASK    ((uint32_t)0x000F0000)
#define RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_USER_4_PSDUS_BMAP_LSB    16
#define RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_USER_4_PSDUS_BMAP_WIDTH    ((uint32_t)0x00000004)
#define RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_USER_3_PSDUS_BMAP_MASK    ((uint32_t)0x0000F000)
#define RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_USER_3_PSDUS_BMAP_LSB    12
#define RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_USER_3_PSDUS_BMAP_WIDTH    ((uint32_t)0x00000004)
#define RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_USER_2_PSDUS_BMAP_MASK    ((uint32_t)0x00000F00)
#define RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_USER_2_PSDUS_BMAP_LSB    8
#define RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_USER_2_PSDUS_BMAP_WIDTH    ((uint32_t)0x00000004)
#define RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_USER_1_PSDUS_BMAP_MASK    ((uint32_t)0x000000F0)
#define RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_USER_1_PSDUS_BMAP_LSB    4
#define RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_USER_1_PSDUS_BMAP_WIDTH    ((uint32_t)0x00000004)
#define RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_USER_0_PSDUS_BMAP_MASK    ((uint32_t)0x0000000F)
#define RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_USER_0_PSDUS_BMAP_LSB    0
#define RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_USER_0_PSDUS_BMAP_WIDTH    ((uint32_t)0x00000004)

#define RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_USER_7_PSDUS_BMAP_RST    0x0
#define RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_USER_6_PSDUS_BMAP_RST    0x0
#define RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_USER_5_PSDUS_BMAP_RST    0x0
#define RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_USER_4_PSDUS_BMAP_RST    0x0
#define RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_USER_3_PSDUS_BMAP_RST    0x0
#define RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_USER_2_PSDUS_BMAP_RST    0x0
#define RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_USER_1_PSDUS_BMAP_RST    0x0
#define RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_USER_0_PSDUS_BMAP_RST    0x0

__INLINE void rxm_rxm_ppdu_stat_user_0_7_clear_pack(uint8_t user7_psdus_bmap, uint8_t user6_psdus_bmap, uint8_t user5_psdus_bmap, uint8_t user4_psdus_bmap, uint8_t user3_psdus_bmap, uint8_t user2_psdus_bmap, uint8_t user1_psdus_bmap, uint8_t user0_psdus_bmap)
{
	ASSERT_ERR((((uint32_t)user7_psdus_bmap << 28) & ~((uint32_t)0xF0000000)) == 0);
	ASSERT_ERR((((uint32_t)user6_psdus_bmap << 24) & ~((uint32_t)0x0F000000)) == 0);
	ASSERT_ERR((((uint32_t)user5_psdus_bmap << 20) & ~((uint32_t)0x00F00000)) == 0);
	ASSERT_ERR((((uint32_t)user4_psdus_bmap << 16) & ~((uint32_t)0x000F0000)) == 0);
	ASSERT_ERR((((uint32_t)user3_psdus_bmap << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)user2_psdus_bmap << 8) & ~((uint32_t)0x00000F00)) == 0);
	ASSERT_ERR((((uint32_t)user1_psdus_bmap << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)user0_psdus_bmap << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_ADDR,  ((uint32_t)user7_psdus_bmap << 28) |((uint32_t)user6_psdus_bmap << 24) |((uint32_t)user5_psdus_bmap << 20) |((uint32_t)user4_psdus_bmap << 16) |((uint32_t)user3_psdus_bmap << 12) |((uint32_t)user2_psdus_bmap << 8) |((uint32_t)user1_psdus_bmap << 4) |((uint32_t)user0_psdus_bmap << 0));
}

__INLINE void rxm_rxm_ppdu_stat_user_0_7_clear_user_7_psdus_bmap_setf(uint8_t user7psdusbmap)
{
	ASSERT_ERR((((uint32_t)user7psdusbmap << 28) & ~((uint32_t)0xF0000000)) == 0);
	REG_PL_WR(RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_ADDR, (REG_PL_RD(RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_ADDR) & ~((uint32_t)0xF0000000)) | ((uint32_t)user7psdusbmap <<28));
}
__INLINE void rxm_rxm_ppdu_stat_user_0_7_clear_user_6_psdus_bmap_setf(uint8_t user6psdusbmap)
{
	ASSERT_ERR((((uint32_t)user6psdusbmap << 24) & ~((uint32_t)0x0F000000)) == 0);
	REG_PL_WR(RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_ADDR, (REG_PL_RD(RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_ADDR) & ~((uint32_t)0x0F000000)) | ((uint32_t)user6psdusbmap <<24));
}
__INLINE void rxm_rxm_ppdu_stat_user_0_7_clear_user_5_psdus_bmap_setf(uint8_t user5psdusbmap)
{
	ASSERT_ERR((((uint32_t)user5psdusbmap << 20) & ~((uint32_t)0x00F00000)) == 0);
	REG_PL_WR(RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_ADDR, (REG_PL_RD(RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_ADDR) & ~((uint32_t)0x00F00000)) | ((uint32_t)user5psdusbmap <<20));
}
__INLINE void rxm_rxm_ppdu_stat_user_0_7_clear_user_4_psdus_bmap_setf(uint8_t user4psdusbmap)
{
	ASSERT_ERR((((uint32_t)user4psdusbmap << 16) & ~((uint32_t)0x000F0000)) == 0);
	REG_PL_WR(RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_ADDR, (REG_PL_RD(RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_ADDR) & ~((uint32_t)0x000F0000)) | ((uint32_t)user4psdusbmap <<16));
}
__INLINE void rxm_rxm_ppdu_stat_user_0_7_clear_user_3_psdus_bmap_setf(uint8_t user3psdusbmap)
{
	ASSERT_ERR((((uint32_t)user3psdusbmap << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_ADDR, (REG_PL_RD(RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)user3psdusbmap <<12));
}
__INLINE void rxm_rxm_ppdu_stat_user_0_7_clear_user_2_psdus_bmap_setf(uint8_t user2psdusbmap)
{
	ASSERT_ERR((((uint32_t)user2psdusbmap << 8) & ~((uint32_t)0x00000F00)) == 0);
	REG_PL_WR(RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_ADDR, (REG_PL_RD(RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_ADDR) & ~((uint32_t)0x00000F00)) | ((uint32_t)user2psdusbmap <<8));
}
__INLINE void rxm_rxm_ppdu_stat_user_0_7_clear_user_1_psdus_bmap_setf(uint8_t user1psdusbmap)
{
	ASSERT_ERR((((uint32_t)user1psdusbmap << 4) & ~((uint32_t)0x000000F0)) == 0);
	REG_PL_WR(RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_ADDR, (REG_PL_RD(RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)user1psdusbmap <<4));
}
__INLINE void rxm_rxm_ppdu_stat_user_0_7_clear_user_0_psdus_bmap_setf(uint8_t user0psdusbmap)
{
	ASSERT_ERR((((uint32_t)user0psdusbmap << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_ADDR, (REG_PL_RD(RXM_RXM_PPDU_STAT_USER_0_7_CLEAR_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)user0psdusbmap <<0));
}

/**
 * @brief RXM_PPDU_STAT_USER_8_15_CLEAR register definition
 *  Clear user PSDU’s statistics register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:28 USER15_PSDUS_BMAP         0x0
 *    27:24 USER14_PSDUS_BMAP         0x0
 *    23:20 USER13_PSDUS_BMAP         0x0
 *    19:16 USER12_PSDUS_BMAP         0x0
 *    15:12 USER11_PSDUS_BMAP         0x0
 *    11:08 USER10_PSDUS_BMAP         0x0
 *    07:04 USER9_PSDUS_BMAP          0x0
 *    03:00 USER8_PSDUS_BMAP          0x0
 * </pre>
 */
#define RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_ADDR        (REG_RXM_BASE_ADDR+0x000002EC)
#define RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_OFFSET      0x000002EC
#define RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_INDEX       0x000000BB
#define RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_RESET       0x00000000

__INLINE void rxm_rxm_ppdu_stat_user_8_15_clear_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_ADDR, value);
}

// field definitions
#define RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_USER_15_PSDUS_BMAP_MASK    ((uint32_t)0xF0000000)
#define RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_USER_15_PSDUS_BMAP_LSB    28
#define RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_USER_15_PSDUS_BMAP_WIDTH    ((uint32_t)0x00000004)
#define RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_USER_14_PSDUS_BMAP_MASK    ((uint32_t)0x0F000000)
#define RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_USER_14_PSDUS_BMAP_LSB    24
#define RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_USER_14_PSDUS_BMAP_WIDTH    ((uint32_t)0x00000004)
#define RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_USER_13_PSDUS_BMAP_MASK    ((uint32_t)0x00F00000)
#define RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_USER_13_PSDUS_BMAP_LSB    20
#define RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_USER_13_PSDUS_BMAP_WIDTH    ((uint32_t)0x00000004)
#define RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_USER_12_PSDUS_BMAP_MASK    ((uint32_t)0x000F0000)
#define RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_USER_12_PSDUS_BMAP_LSB    16
#define RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_USER_12_PSDUS_BMAP_WIDTH    ((uint32_t)0x00000004)
#define RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_USER_11_PSDUS_BMAP_MASK    ((uint32_t)0x0000F000)
#define RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_USER_11_PSDUS_BMAP_LSB    12
#define RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_USER_11_PSDUS_BMAP_WIDTH    ((uint32_t)0x00000004)
#define RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_USER_10_PSDUS_BMAP_MASK    ((uint32_t)0x00000F00)
#define RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_USER_10_PSDUS_BMAP_LSB    8
#define RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_USER_10_PSDUS_BMAP_WIDTH    ((uint32_t)0x00000004)
#define RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_USER_9_PSDUS_BMAP_MASK    ((uint32_t)0x000000F0)
#define RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_USER_9_PSDUS_BMAP_LSB    4
#define RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_USER_9_PSDUS_BMAP_WIDTH    ((uint32_t)0x00000004)
#define RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_USER_8_PSDUS_BMAP_MASK    ((uint32_t)0x0000000F)
#define RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_USER_8_PSDUS_BMAP_LSB    0
#define RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_USER_8_PSDUS_BMAP_WIDTH    ((uint32_t)0x00000004)

#define RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_USER_15_PSDUS_BMAP_RST    0x0
#define RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_USER_14_PSDUS_BMAP_RST    0x0
#define RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_USER_13_PSDUS_BMAP_RST    0x0
#define RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_USER_12_PSDUS_BMAP_RST    0x0
#define RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_USER_11_PSDUS_BMAP_RST    0x0
#define RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_USER_10_PSDUS_BMAP_RST    0x0
#define RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_USER_9_PSDUS_BMAP_RST    0x0
#define RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_USER_8_PSDUS_BMAP_RST    0x0

__INLINE void rxm_rxm_ppdu_stat_user_8_15_clear_pack(uint8_t user15_psdus_bmap, uint8_t user14_psdus_bmap, uint8_t user13_psdus_bmap, uint8_t user12_psdus_bmap, uint8_t user11_psdus_bmap, uint8_t user10_psdus_bmap, uint8_t user9_psdus_bmap, uint8_t user8_psdus_bmap)
{
	ASSERT_ERR((((uint32_t)user15_psdus_bmap << 28) & ~((uint32_t)0xF0000000)) == 0);
	ASSERT_ERR((((uint32_t)user14_psdus_bmap << 24) & ~((uint32_t)0x0F000000)) == 0);
	ASSERT_ERR((((uint32_t)user13_psdus_bmap << 20) & ~((uint32_t)0x00F00000)) == 0);
	ASSERT_ERR((((uint32_t)user12_psdus_bmap << 16) & ~((uint32_t)0x000F0000)) == 0);
	ASSERT_ERR((((uint32_t)user11_psdus_bmap << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)user10_psdus_bmap << 8) & ~((uint32_t)0x00000F00)) == 0);
	ASSERT_ERR((((uint32_t)user9_psdus_bmap << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)user8_psdus_bmap << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_ADDR,  ((uint32_t)user15_psdus_bmap << 28) |((uint32_t)user14_psdus_bmap << 24) |((uint32_t)user13_psdus_bmap << 20) |((uint32_t)user12_psdus_bmap << 16) |((uint32_t)user11_psdus_bmap << 12) |((uint32_t)user10_psdus_bmap << 8) |((uint32_t)user9_psdus_bmap << 4) |((uint32_t)user8_psdus_bmap << 0));
}

__INLINE void rxm_rxm_ppdu_stat_user_8_15_clear_user_15_psdus_bmap_setf(uint8_t user15psdusbmap)
{
	ASSERT_ERR((((uint32_t)user15psdusbmap << 28) & ~((uint32_t)0xF0000000)) == 0);
	REG_PL_WR(RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_ADDR, (REG_PL_RD(RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_ADDR) & ~((uint32_t)0xF0000000)) | ((uint32_t)user15psdusbmap <<28));
}
__INLINE void rxm_rxm_ppdu_stat_user_8_15_clear_user_14_psdus_bmap_setf(uint8_t user14psdusbmap)
{
	ASSERT_ERR((((uint32_t)user14psdusbmap << 24) & ~((uint32_t)0x0F000000)) == 0);
	REG_PL_WR(RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_ADDR, (REG_PL_RD(RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_ADDR) & ~((uint32_t)0x0F000000)) | ((uint32_t)user14psdusbmap <<24));
}
__INLINE void rxm_rxm_ppdu_stat_user_8_15_clear_user_13_psdus_bmap_setf(uint8_t user13psdusbmap)
{
	ASSERT_ERR((((uint32_t)user13psdusbmap << 20) & ~((uint32_t)0x00F00000)) == 0);
	REG_PL_WR(RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_ADDR, (REG_PL_RD(RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_ADDR) & ~((uint32_t)0x00F00000)) | ((uint32_t)user13psdusbmap <<20));
}
__INLINE void rxm_rxm_ppdu_stat_user_8_15_clear_user_12_psdus_bmap_setf(uint8_t user12psdusbmap)
{
	ASSERT_ERR((((uint32_t)user12psdusbmap << 16) & ~((uint32_t)0x000F0000)) == 0);
	REG_PL_WR(RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_ADDR, (REG_PL_RD(RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_ADDR) & ~((uint32_t)0x000F0000)) | ((uint32_t)user12psdusbmap <<16));
}
__INLINE void rxm_rxm_ppdu_stat_user_8_15_clear_user_11_psdus_bmap_setf(uint8_t user11psdusbmap)
{
	ASSERT_ERR((((uint32_t)user11psdusbmap << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_ADDR, (REG_PL_RD(RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)user11psdusbmap <<12));
}
__INLINE void rxm_rxm_ppdu_stat_user_8_15_clear_user_10_psdus_bmap_setf(uint8_t user10psdusbmap)
{
	ASSERT_ERR((((uint32_t)user10psdusbmap << 8) & ~((uint32_t)0x00000F00)) == 0);
	REG_PL_WR(RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_ADDR, (REG_PL_RD(RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_ADDR) & ~((uint32_t)0x00000F00)) | ((uint32_t)user10psdusbmap <<8));
}
__INLINE void rxm_rxm_ppdu_stat_user_8_15_clear_user_9_psdus_bmap_setf(uint8_t user9psdusbmap)
{
	ASSERT_ERR((((uint32_t)user9psdusbmap << 4) & ~((uint32_t)0x000000F0)) == 0);
	REG_PL_WR(RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_ADDR, (REG_PL_RD(RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)user9psdusbmap <<4));
}
__INLINE void rxm_rxm_ppdu_stat_user_8_15_clear_user_8_psdus_bmap_setf(uint8_t user8psdusbmap)
{
	ASSERT_ERR((((uint32_t)user8psdusbmap << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_ADDR, (REG_PL_RD(RXM_RXM_PPDU_STAT_USER_8_15_CLEAR_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)user8psdusbmap <<0));
}

/**
 * @brief RXM_PPDU_STAT_RD_ADDR register definition
 *  Statistics read address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    11:08 MAC_USER                  0x0
 *    07:02 spare                     0x0
 *    01:00 PSDU_INDEX                0x0
 * </pre>
 */
#define RXM_RXM_PPDU_STAT_RD_ADDR_ADDR        (REG_RXM_BASE_ADDR+0x000002F0)
#define RXM_RXM_PPDU_STAT_RD_ADDR_OFFSET      0x000002F0
#define RXM_RXM_PPDU_STAT_RD_ADDR_INDEX       0x000000BC
#define RXM_RXM_PPDU_STAT_RD_ADDR_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_ppdu_stat_rd_addr_get(void)
{
	return REG_PL_RD(RXM_RXM_PPDU_STAT_RD_ADDR_ADDR);
}

__INLINE void rxm_rxm_ppdu_stat_rd_addr_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_PPDU_STAT_RD_ADDR_ADDR, value);
}

// field definitions
#define RXM_RXM_PPDU_STAT_RD_ADDR_MAC_USER_MASK    ((uint32_t)0x00000F00)
#define RXM_RXM_PPDU_STAT_RD_ADDR_MAC_USER_LSB    8
#define RXM_RXM_PPDU_STAT_RD_ADDR_MAC_USER_WIDTH    ((uint32_t)0x00000004)
#define RXM_RXM_PPDU_STAT_RD_ADDR_SPARE_MASK    ((uint32_t)0x000000FC)
#define RXM_RXM_PPDU_STAT_RD_ADDR_SPARE_LSB    2
#define RXM_RXM_PPDU_STAT_RD_ADDR_SPARE_WIDTH    ((uint32_t)0x00000006)
#define RXM_RXM_PPDU_STAT_RD_ADDR_PSDU_INDEX_MASK    ((uint32_t)0x00000003)
#define RXM_RXM_PPDU_STAT_RD_ADDR_PSDU_INDEX_LSB    0
#define RXM_RXM_PPDU_STAT_RD_ADDR_PSDU_INDEX_WIDTH    ((uint32_t)0x00000002)

#define RXM_RXM_PPDU_STAT_RD_ADDR_MAC_USER_RST    0x0
#define RXM_RXM_PPDU_STAT_RD_ADDR_SPARE_RST    0x0
#define RXM_RXM_PPDU_STAT_RD_ADDR_PSDU_INDEX_RST    0x0

__INLINE void rxm_rxm_ppdu_stat_rd_addr_pack(uint8_t mac_user, uint8_t spare, uint8_t psdu_index)
{
	ASSERT_ERR((((uint32_t)mac_user << 8) & ~((uint32_t)0x00000F00)) == 0);
	ASSERT_ERR((((uint32_t)spare << 2) & ~((uint32_t)0x000000FC)) == 0);
	ASSERT_ERR((((uint32_t)psdu_index << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RXM_RXM_PPDU_STAT_RD_ADDR_ADDR,  ((uint32_t)mac_user << 8) |((uint32_t)spare << 2) |((uint32_t)psdu_index << 0));
}

__INLINE void rxm_rxm_ppdu_stat_rd_addr_unpack(uint8_t* mac_user, uint8_t* spare, uint8_t* psdu_index)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_STAT_RD_ADDR_ADDR);

	*mac_user = (localVal & ((uint32_t)0x00000F00)) >>  8;
	*spare = (localVal & ((uint32_t)0x000000FC)) >>  2;
	*psdu_index = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint8_t rxm_rxm_ppdu_stat_rd_addr_mac_user_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_STAT_RD_ADDR_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000F00)) >> 8);
}
__INLINE void rxm_rxm_ppdu_stat_rd_addr_mac_user_setf(uint8_t macuser)
{
	ASSERT_ERR((((uint32_t)macuser << 8) & ~((uint32_t)0x00000F00)) == 0);
	REG_PL_WR(RXM_RXM_PPDU_STAT_RD_ADDR_ADDR, (REG_PL_RD(RXM_RXM_PPDU_STAT_RD_ADDR_ADDR) & ~((uint32_t)0x00000F00)) | ((uint32_t)macuser <<8));
}
__INLINE uint8_t rxm_rxm_ppdu_stat_rd_addr_spare_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_STAT_RD_ADDR_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FC)) >> 2);
}
__INLINE uint8_t rxm_rxm_ppdu_stat_rd_addr_psdu_index_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_STAT_RD_ADDR_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void rxm_rxm_ppdu_stat_rd_addr_psdu_index_setf(uint8_t psduindex)
{
	ASSERT_ERR((((uint32_t)psduindex << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RXM_RXM_PPDU_STAT_RD_ADDR_ADDR, (REG_PL_RD(RXM_RXM_PPDU_STAT_RD_ADDR_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)psduindex <<0));
}

/**
 * @brief RXM_PPDU_MPDUS_CNT register definition
 *  Rx, discard and error MPDU’s register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:27 spare                     0x0
 *    26:18 ERR_MPDUS_CNT             0x0
 *    17:09 DIS_MPDUS_CNT             0x0
 *    08:00 RX_MPDUS_CNT              0x0
 * </pre>
 */
#define RXM_RXM_PPDU_MPDUS_CNT_ADDR        (REG_RXM_BASE_ADDR+0x00000300)
#define RXM_RXM_PPDU_MPDUS_CNT_OFFSET      0x00000300
#define RXM_RXM_PPDU_MPDUS_CNT_INDEX       0x000000C0
#define RXM_RXM_PPDU_MPDUS_CNT_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_ppdu_mpdus_cnt_get(void)
{
	return REG_PL_RD(RXM_RXM_PPDU_MPDUS_CNT_ADDR);
}

// field definitions
#define RXM_RXM_PPDU_MPDUS_CNT_SPARE_MASK    ((uint32_t)0xF8000000)
#define RXM_RXM_PPDU_MPDUS_CNT_SPARE_LSB    27
#define RXM_RXM_PPDU_MPDUS_CNT_SPARE_WIDTH    ((uint32_t)0x00000005)
#define RXM_RXM_PPDU_MPDUS_CNT_ERR_MPDUS_CNT_MASK    ((uint32_t)0x07FC0000)
#define RXM_RXM_PPDU_MPDUS_CNT_ERR_MPDUS_CNT_LSB    18
#define RXM_RXM_PPDU_MPDUS_CNT_ERR_MPDUS_CNT_WIDTH    ((uint32_t)0x00000009)
#define RXM_RXM_PPDU_MPDUS_CNT_DIS_MPDUS_CNT_MASK    ((uint32_t)0x0003FE00)
#define RXM_RXM_PPDU_MPDUS_CNT_DIS_MPDUS_CNT_LSB    9
#define RXM_RXM_PPDU_MPDUS_CNT_DIS_MPDUS_CNT_WIDTH    ((uint32_t)0x00000009)
#define RXM_RXM_PPDU_MPDUS_CNT_RX_MPDUS_CNT_MASK    ((uint32_t)0x000001FF)
#define RXM_RXM_PPDU_MPDUS_CNT_RX_MPDUS_CNT_LSB    0
#define RXM_RXM_PPDU_MPDUS_CNT_RX_MPDUS_CNT_WIDTH    ((uint32_t)0x00000009)

#define RXM_RXM_PPDU_MPDUS_CNT_SPARE_RST    0x0
#define RXM_RXM_PPDU_MPDUS_CNT_ERR_MPDUS_CNT_RST    0x0
#define RXM_RXM_PPDU_MPDUS_CNT_DIS_MPDUS_CNT_RST    0x0
#define RXM_RXM_PPDU_MPDUS_CNT_RX_MPDUS_CNT_RST    0x0

__INLINE void rxm_rxm_ppdu_mpdus_cnt_unpack(uint8_t* spare, uint16_t* err_mpdus_cnt, uint16_t* dis_mpdus_cnt, uint16_t* rx_mpdus_cnt)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_MPDUS_CNT_ADDR);

	*spare = (localVal & ((uint32_t)0xF8000000)) >>  27;
	*err_mpdus_cnt = (localVal & ((uint32_t)0x07FC0000)) >>  18;
	*dis_mpdus_cnt = (localVal & ((uint32_t)0x0003FE00)) >>  9;
	*rx_mpdus_cnt = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint8_t rxm_rxm_ppdu_mpdus_cnt_spare_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_MPDUS_CNT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xF8000000)) >> 27);
}
__INLINE uint16_t rxm_rxm_ppdu_mpdus_cnt_err_mpdus_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_MPDUS_CNT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x07FC0000)) >> 18);
}
__INLINE uint16_t rxm_rxm_ppdu_mpdus_cnt_dis_mpdus_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_MPDUS_CNT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0003FE00)) >> 9);
}
__INLINE uint16_t rxm_rxm_ppdu_mpdus_cnt_rx_mpdus_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_MPDUS_CNT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}

/**
 * @brief RXM_PPDU_QOS_DATA_SIZE register definition
 *  AMPDU QoS data byte count register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:00 AMPDU_QOS_DATA_SIZE       0x0
 * </pre>
 */
#define RXM_RXM_PPDU_QOS_DATA_SIZE_ADDR        (REG_RXM_BASE_ADDR+0x00000304)
#define RXM_RXM_PPDU_QOS_DATA_SIZE_OFFSET      0x00000304
#define RXM_RXM_PPDU_QOS_DATA_SIZE_INDEX       0x000000C1
#define RXM_RXM_PPDU_QOS_DATA_SIZE_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_ppdu_qos_data_size_get(void)
{
	return REG_PL_RD(RXM_RXM_PPDU_QOS_DATA_SIZE_ADDR);
}

// field definitions
#define RXM_RXM_PPDU_QOS_DATA_SIZE_AMPDU_QOS_DATA_SIZE_MASK    ((uint32_t)0x00FFFFFF)
#define RXM_RXM_PPDU_QOS_DATA_SIZE_AMPDU_QOS_DATA_SIZE_LSB    0
#define RXM_RXM_PPDU_QOS_DATA_SIZE_AMPDU_QOS_DATA_SIZE_WIDTH    ((uint32_t)0x00000018)

#define RXM_RXM_PPDU_QOS_DATA_SIZE_AMPDU_QOS_DATA_SIZE_RST    0x0

__INLINE uint32_t rxm_rxm_ppdu_qos_data_size_ampdu_qos_data_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_QOS_DATA_SIZE_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RXM_PPDU_RULE_0_1 register definition
 *  Rule hit MPDU’s counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:25 spare2                    0x0
 *    24:16 RULE1_HIT_MPDU_CNT        0x0
 *    15:09 spare1                    0x0
 *    08:00 RULE0_HIT_MPDU_CNT        0x0
 * </pre>
 */
#define RXM_RXM_PPDU_RULE_0_1_ADDR        (REG_RXM_BASE_ADDR+0x00000308)
#define RXM_RXM_PPDU_RULE_0_1_OFFSET      0x00000308
#define RXM_RXM_PPDU_RULE_0_1_INDEX       0x000000C2
#define RXM_RXM_PPDU_RULE_0_1_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_ppdu_rule_0_1_get(void)
{
	return REG_PL_RD(RXM_RXM_PPDU_RULE_0_1_ADDR);
}

// field definitions
#define RXM_RXM_PPDU_RULE_0_1_SPARE_2_MASK    ((uint32_t)0xFE000000)
#define RXM_RXM_PPDU_RULE_0_1_SPARE_2_LSB    25
#define RXM_RXM_PPDU_RULE_0_1_SPARE_2_WIDTH    ((uint32_t)0x00000007)
#define RXM_RXM_PPDU_RULE_0_1_RULE_1_HIT_MPDU_CNT_MASK    ((uint32_t)0x01FF0000)
#define RXM_RXM_PPDU_RULE_0_1_RULE_1_HIT_MPDU_CNT_LSB    16
#define RXM_RXM_PPDU_RULE_0_1_RULE_1_HIT_MPDU_CNT_WIDTH    ((uint32_t)0x00000009)
#define RXM_RXM_PPDU_RULE_0_1_SPARE_1_MASK    ((uint32_t)0x0000FE00)
#define RXM_RXM_PPDU_RULE_0_1_SPARE_1_LSB    9
#define RXM_RXM_PPDU_RULE_0_1_SPARE_1_WIDTH    ((uint32_t)0x00000007)
#define RXM_RXM_PPDU_RULE_0_1_RULE_0_HIT_MPDU_CNT_MASK    ((uint32_t)0x000001FF)
#define RXM_RXM_PPDU_RULE_0_1_RULE_0_HIT_MPDU_CNT_LSB    0
#define RXM_RXM_PPDU_RULE_0_1_RULE_0_HIT_MPDU_CNT_WIDTH    ((uint32_t)0x00000009)

#define RXM_RXM_PPDU_RULE_0_1_SPARE_2_RST    0x0
#define RXM_RXM_PPDU_RULE_0_1_RULE_1_HIT_MPDU_CNT_RST    0x0
#define RXM_RXM_PPDU_RULE_0_1_SPARE_1_RST    0x0
#define RXM_RXM_PPDU_RULE_0_1_RULE_0_HIT_MPDU_CNT_RST    0x0

__INLINE void rxm_rxm_ppdu_rule_0_1_unpack(uint8_t* spare2, uint16_t* rule1_hit_mpdu_cnt, uint8_t* spare1, uint16_t* rule0_hit_mpdu_cnt)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_0_1_ADDR);

	*spare2 = (localVal & ((uint32_t)0xFE000000)) >>  25;
	*rule1_hit_mpdu_cnt = (localVal & ((uint32_t)0x01FF0000)) >>  16;
	*spare1 = (localVal & ((uint32_t)0x0000FE00)) >>  9;
	*rule0_hit_mpdu_cnt = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint8_t rxm_rxm_ppdu_rule_0_1_spare_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_0_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFE000000)) >> 25);
}
__INLINE uint16_t rxm_rxm_ppdu_rule_0_1_rule_1_hit_mpdu_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_0_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x01FF0000)) >> 16);
}
__INLINE uint8_t rxm_rxm_ppdu_rule_0_1_spare_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_0_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FE00)) >> 9);
}
__INLINE uint16_t rxm_rxm_ppdu_rule_0_1_rule_0_hit_mpdu_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_0_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}

/**
 * @brief RXM_PPDU_RULE_2_3 register definition
 *  Rule hit MPDU’s counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:25 spare2                    0x0
 *    24:16 RULE3_HIT_MPDU_CNT        0x0
 *    15:09 spare1                    0x0
 *    08:00 RULE2_HIT_MPDU_CNT        0x0
 * </pre>
 */
#define RXM_RXM_PPDU_RULE_2_3_ADDR        (REG_RXM_BASE_ADDR+0x0000030C)
#define RXM_RXM_PPDU_RULE_2_3_OFFSET      0x0000030C
#define RXM_RXM_PPDU_RULE_2_3_INDEX       0x000000C3
#define RXM_RXM_PPDU_RULE_2_3_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_ppdu_rule_2_3_get(void)
{
	return REG_PL_RD(RXM_RXM_PPDU_RULE_2_3_ADDR);
}

// field definitions
#define RXM_RXM_PPDU_RULE_2_3_SPARE_2_MASK    ((uint32_t)0xFE000000)
#define RXM_RXM_PPDU_RULE_2_3_SPARE_2_LSB    25
#define RXM_RXM_PPDU_RULE_2_3_SPARE_2_WIDTH    ((uint32_t)0x00000007)
#define RXM_RXM_PPDU_RULE_2_3_RULE_3_HIT_MPDU_CNT_MASK    ((uint32_t)0x01FF0000)
#define RXM_RXM_PPDU_RULE_2_3_RULE_3_HIT_MPDU_CNT_LSB    16
#define RXM_RXM_PPDU_RULE_2_3_RULE_3_HIT_MPDU_CNT_WIDTH    ((uint32_t)0x00000009)
#define RXM_RXM_PPDU_RULE_2_3_SPARE_1_MASK    ((uint32_t)0x0000FE00)
#define RXM_RXM_PPDU_RULE_2_3_SPARE_1_LSB    9
#define RXM_RXM_PPDU_RULE_2_3_SPARE_1_WIDTH    ((uint32_t)0x00000007)
#define RXM_RXM_PPDU_RULE_2_3_RULE_2_HIT_MPDU_CNT_MASK    ((uint32_t)0x000001FF)
#define RXM_RXM_PPDU_RULE_2_3_RULE_2_HIT_MPDU_CNT_LSB    0
#define RXM_RXM_PPDU_RULE_2_3_RULE_2_HIT_MPDU_CNT_WIDTH    ((uint32_t)0x00000009)

#define RXM_RXM_PPDU_RULE_2_3_SPARE_2_RST    0x0
#define RXM_RXM_PPDU_RULE_2_3_RULE_3_HIT_MPDU_CNT_RST    0x0
#define RXM_RXM_PPDU_RULE_2_3_SPARE_1_RST    0x0
#define RXM_RXM_PPDU_RULE_2_3_RULE_2_HIT_MPDU_CNT_RST    0x0

__INLINE void rxm_rxm_ppdu_rule_2_3_unpack(uint8_t* spare2, uint16_t* rule3_hit_mpdu_cnt, uint8_t* spare1, uint16_t* rule2_hit_mpdu_cnt)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_2_3_ADDR);

	*spare2 = (localVal & ((uint32_t)0xFE000000)) >>  25;
	*rule3_hit_mpdu_cnt = (localVal & ((uint32_t)0x01FF0000)) >>  16;
	*spare1 = (localVal & ((uint32_t)0x0000FE00)) >>  9;
	*rule2_hit_mpdu_cnt = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint8_t rxm_rxm_ppdu_rule_2_3_spare_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_2_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFE000000)) >> 25);
}
__INLINE uint16_t rxm_rxm_ppdu_rule_2_3_rule_3_hit_mpdu_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_2_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x01FF0000)) >> 16);
}
__INLINE uint8_t rxm_rxm_ppdu_rule_2_3_spare_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_2_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FE00)) >> 9);
}
__INLINE uint16_t rxm_rxm_ppdu_rule_2_3_rule_2_hit_mpdu_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_2_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}

/**
 * @brief RXM_PPDU_RULE_4_5 register definition
 *  Rule hit MPDU’s counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:25 spare2                    0x0
 *    24:16 RULE5_HIT_MPDU_CNT        0x0
 *    15:09 spare1                    0x0
 *    08:00 RULE4_HIT_MPDU_CNT        0x0
 * </pre>
 */
#define RXM_RXM_PPDU_RULE_4_5_ADDR        (REG_RXM_BASE_ADDR+0x00000310)
#define RXM_RXM_PPDU_RULE_4_5_OFFSET      0x00000310
#define RXM_RXM_PPDU_RULE_4_5_INDEX       0x000000C4
#define RXM_RXM_PPDU_RULE_4_5_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_ppdu_rule_4_5_get(void)
{
	return REG_PL_RD(RXM_RXM_PPDU_RULE_4_5_ADDR);
}

// field definitions
#define RXM_RXM_PPDU_RULE_4_5_SPARE_2_MASK    ((uint32_t)0xFE000000)
#define RXM_RXM_PPDU_RULE_4_5_SPARE_2_LSB    25
#define RXM_RXM_PPDU_RULE_4_5_SPARE_2_WIDTH    ((uint32_t)0x00000007)
#define RXM_RXM_PPDU_RULE_4_5_RULE_5_HIT_MPDU_CNT_MASK    ((uint32_t)0x01FF0000)
#define RXM_RXM_PPDU_RULE_4_5_RULE_5_HIT_MPDU_CNT_LSB    16
#define RXM_RXM_PPDU_RULE_4_5_RULE_5_HIT_MPDU_CNT_WIDTH    ((uint32_t)0x00000009)
#define RXM_RXM_PPDU_RULE_4_5_SPARE_1_MASK    ((uint32_t)0x0000FE00)
#define RXM_RXM_PPDU_RULE_4_5_SPARE_1_LSB    9
#define RXM_RXM_PPDU_RULE_4_5_SPARE_1_WIDTH    ((uint32_t)0x00000007)
#define RXM_RXM_PPDU_RULE_4_5_RULE_4_HIT_MPDU_CNT_MASK    ((uint32_t)0x000001FF)
#define RXM_RXM_PPDU_RULE_4_5_RULE_4_HIT_MPDU_CNT_LSB    0
#define RXM_RXM_PPDU_RULE_4_5_RULE_4_HIT_MPDU_CNT_WIDTH    ((uint32_t)0x00000009)

#define RXM_RXM_PPDU_RULE_4_5_SPARE_2_RST    0x0
#define RXM_RXM_PPDU_RULE_4_5_RULE_5_HIT_MPDU_CNT_RST    0x0
#define RXM_RXM_PPDU_RULE_4_5_SPARE_1_RST    0x0
#define RXM_RXM_PPDU_RULE_4_5_RULE_4_HIT_MPDU_CNT_RST    0x0

__INLINE void rxm_rxm_ppdu_rule_4_5_unpack(uint8_t* spare2, uint16_t* rule5_hit_mpdu_cnt, uint8_t* spare1, uint16_t* rule4_hit_mpdu_cnt)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_4_5_ADDR);

	*spare2 = (localVal & ((uint32_t)0xFE000000)) >>  25;
	*rule5_hit_mpdu_cnt = (localVal & ((uint32_t)0x01FF0000)) >>  16;
	*spare1 = (localVal & ((uint32_t)0x0000FE00)) >>  9;
	*rule4_hit_mpdu_cnt = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint8_t rxm_rxm_ppdu_rule_4_5_spare_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_4_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFE000000)) >> 25);
}
__INLINE uint16_t rxm_rxm_ppdu_rule_4_5_rule_5_hit_mpdu_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_4_5_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x01FF0000)) >> 16);
}
__INLINE uint8_t rxm_rxm_ppdu_rule_4_5_spare_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_4_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FE00)) >> 9);
}
__INLINE uint16_t rxm_rxm_ppdu_rule_4_5_rule_4_hit_mpdu_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_4_5_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}

/**
 * @brief RXM_PPDU_RULE_6_7 register definition
 *  Rule hit MPDU’s counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:25 spare2                    0x0
 *    24:16 RULE7_HIT_MPDU_CNT        0x0
 *    15:09 spare1                    0x0
 *    08:00 RULE6_HIT_MPDU_CNT        0x0
 * </pre>
 */
#define RXM_RXM_PPDU_RULE_6_7_ADDR        (REG_RXM_BASE_ADDR+0x00000314)
#define RXM_RXM_PPDU_RULE_6_7_OFFSET      0x00000314
#define RXM_RXM_PPDU_RULE_6_7_INDEX       0x000000C5
#define RXM_RXM_PPDU_RULE_6_7_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_ppdu_rule_6_7_get(void)
{
	return REG_PL_RD(RXM_RXM_PPDU_RULE_6_7_ADDR);
}

// field definitions
#define RXM_RXM_PPDU_RULE_6_7_SPARE_2_MASK    ((uint32_t)0xFE000000)
#define RXM_RXM_PPDU_RULE_6_7_SPARE_2_LSB    25
#define RXM_RXM_PPDU_RULE_6_7_SPARE_2_WIDTH    ((uint32_t)0x00000007)
#define RXM_RXM_PPDU_RULE_6_7_RULE_7_HIT_MPDU_CNT_MASK    ((uint32_t)0x01FF0000)
#define RXM_RXM_PPDU_RULE_6_7_RULE_7_HIT_MPDU_CNT_LSB    16
#define RXM_RXM_PPDU_RULE_6_7_RULE_7_HIT_MPDU_CNT_WIDTH    ((uint32_t)0x00000009)
#define RXM_RXM_PPDU_RULE_6_7_SPARE_1_MASK    ((uint32_t)0x0000FE00)
#define RXM_RXM_PPDU_RULE_6_7_SPARE_1_LSB    9
#define RXM_RXM_PPDU_RULE_6_7_SPARE_1_WIDTH    ((uint32_t)0x00000007)
#define RXM_RXM_PPDU_RULE_6_7_RULE_6_HIT_MPDU_CNT_MASK    ((uint32_t)0x000001FF)
#define RXM_RXM_PPDU_RULE_6_7_RULE_6_HIT_MPDU_CNT_LSB    0
#define RXM_RXM_PPDU_RULE_6_7_RULE_6_HIT_MPDU_CNT_WIDTH    ((uint32_t)0x00000009)

#define RXM_RXM_PPDU_RULE_6_7_SPARE_2_RST    0x0
#define RXM_RXM_PPDU_RULE_6_7_RULE_7_HIT_MPDU_CNT_RST    0x0
#define RXM_RXM_PPDU_RULE_6_7_SPARE_1_RST    0x0
#define RXM_RXM_PPDU_RULE_6_7_RULE_6_HIT_MPDU_CNT_RST    0x0

__INLINE void rxm_rxm_ppdu_rule_6_7_unpack(uint8_t* spare2, uint16_t* rule7_hit_mpdu_cnt, uint8_t* spare1, uint16_t* rule6_hit_mpdu_cnt)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_6_7_ADDR);

	*spare2 = (localVal & ((uint32_t)0xFE000000)) >>  25;
	*rule7_hit_mpdu_cnt = (localVal & ((uint32_t)0x01FF0000)) >>  16;
	*spare1 = (localVal & ((uint32_t)0x0000FE00)) >>  9;
	*rule6_hit_mpdu_cnt = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint8_t rxm_rxm_ppdu_rule_6_7_spare_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_6_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFE000000)) >> 25);
}
__INLINE uint16_t rxm_rxm_ppdu_rule_6_7_rule_7_hit_mpdu_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_6_7_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x01FF0000)) >> 16);
}
__INLINE uint8_t rxm_rxm_ppdu_rule_6_7_spare_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_6_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FE00)) >> 9);
}
__INLINE uint16_t rxm_rxm_ppdu_rule_6_7_rule_6_hit_mpdu_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_6_7_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}

/**
 * @brief RXM_PPDU_RULE_8_9 register definition
 *  Rule hit MPDU’s counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:25 spare2                    0x0
 *    24:16 RULE9_HIT_MPDU_CNT        0x0
 *    15:09 spare1                    0x0
 *    08:00 RULE8_HIT_MPDU_CNT        0x0
 * </pre>
 */
#define RXM_RXM_PPDU_RULE_8_9_ADDR        (REG_RXM_BASE_ADDR+0x00000318)
#define RXM_RXM_PPDU_RULE_8_9_OFFSET      0x00000318
#define RXM_RXM_PPDU_RULE_8_9_INDEX       0x000000C6
#define RXM_RXM_PPDU_RULE_8_9_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_ppdu_rule_8_9_get(void)
{
	return REG_PL_RD(RXM_RXM_PPDU_RULE_8_9_ADDR);
}

// field definitions
#define RXM_RXM_PPDU_RULE_8_9_SPARE_2_MASK    ((uint32_t)0xFE000000)
#define RXM_RXM_PPDU_RULE_8_9_SPARE_2_LSB    25
#define RXM_RXM_PPDU_RULE_8_9_SPARE_2_WIDTH    ((uint32_t)0x00000007)
#define RXM_RXM_PPDU_RULE_8_9_RULE_9_HIT_MPDU_CNT_MASK    ((uint32_t)0x01FF0000)
#define RXM_RXM_PPDU_RULE_8_9_RULE_9_HIT_MPDU_CNT_LSB    16
#define RXM_RXM_PPDU_RULE_8_9_RULE_9_HIT_MPDU_CNT_WIDTH    ((uint32_t)0x00000009)
#define RXM_RXM_PPDU_RULE_8_9_SPARE_1_MASK    ((uint32_t)0x0000FE00)
#define RXM_RXM_PPDU_RULE_8_9_SPARE_1_LSB    9
#define RXM_RXM_PPDU_RULE_8_9_SPARE_1_WIDTH    ((uint32_t)0x00000007)
#define RXM_RXM_PPDU_RULE_8_9_RULE_8_HIT_MPDU_CNT_MASK    ((uint32_t)0x000001FF)
#define RXM_RXM_PPDU_RULE_8_9_RULE_8_HIT_MPDU_CNT_LSB    0
#define RXM_RXM_PPDU_RULE_8_9_RULE_8_HIT_MPDU_CNT_WIDTH    ((uint32_t)0x00000009)

#define RXM_RXM_PPDU_RULE_8_9_SPARE_2_RST    0x0
#define RXM_RXM_PPDU_RULE_8_9_RULE_9_HIT_MPDU_CNT_RST    0x0
#define RXM_RXM_PPDU_RULE_8_9_SPARE_1_RST    0x0
#define RXM_RXM_PPDU_RULE_8_9_RULE_8_HIT_MPDU_CNT_RST    0x0

__INLINE void rxm_rxm_ppdu_rule_8_9_unpack(uint8_t* spare2, uint16_t* rule9_hit_mpdu_cnt, uint8_t* spare1, uint16_t* rule8_hit_mpdu_cnt)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_8_9_ADDR);

	*spare2 = (localVal & ((uint32_t)0xFE000000)) >>  25;
	*rule9_hit_mpdu_cnt = (localVal & ((uint32_t)0x01FF0000)) >>  16;
	*spare1 = (localVal & ((uint32_t)0x0000FE00)) >>  9;
	*rule8_hit_mpdu_cnt = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint8_t rxm_rxm_ppdu_rule_8_9_spare_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_8_9_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFE000000)) >> 25);
}
__INLINE uint16_t rxm_rxm_ppdu_rule_8_9_rule_9_hit_mpdu_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_8_9_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x01FF0000)) >> 16);
}
__INLINE uint8_t rxm_rxm_ppdu_rule_8_9_spare_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_8_9_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FE00)) >> 9);
}
__INLINE uint16_t rxm_rxm_ppdu_rule_8_9_rule_8_hit_mpdu_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_8_9_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}

/**
 * @brief RXM_PPDU_RULE_10_11 register definition
 *  Rule hit MPDU’s counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:25 spare2                    0x0
 *    24:16 RULE11_HIT_MPDU_CNT       0x0
 *    15:09 spare1                    0x0
 *    08:00 RULE10_HIT_MPDU_CNT       0x0
 * </pre>
 */
#define RXM_RXM_PPDU_RULE_10_11_ADDR        (REG_RXM_BASE_ADDR+0x0000031C)
#define RXM_RXM_PPDU_RULE_10_11_OFFSET      0x0000031C
#define RXM_RXM_PPDU_RULE_10_11_INDEX       0x000000C7
#define RXM_RXM_PPDU_RULE_10_11_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_ppdu_rule_10_11_get(void)
{
	return REG_PL_RD(RXM_RXM_PPDU_RULE_10_11_ADDR);
}

// field definitions
#define RXM_RXM_PPDU_RULE_10_11_SPARE_2_MASK    ((uint32_t)0xFE000000)
#define RXM_RXM_PPDU_RULE_10_11_SPARE_2_LSB    25
#define RXM_RXM_PPDU_RULE_10_11_SPARE_2_WIDTH    ((uint32_t)0x00000007)
#define RXM_RXM_PPDU_RULE_10_11_RULE_11_HIT_MPDU_CNT_MASK    ((uint32_t)0x01FF0000)
#define RXM_RXM_PPDU_RULE_10_11_RULE_11_HIT_MPDU_CNT_LSB    16
#define RXM_RXM_PPDU_RULE_10_11_RULE_11_HIT_MPDU_CNT_WIDTH    ((uint32_t)0x00000009)
#define RXM_RXM_PPDU_RULE_10_11_SPARE_1_MASK    ((uint32_t)0x0000FE00)
#define RXM_RXM_PPDU_RULE_10_11_SPARE_1_LSB    9
#define RXM_RXM_PPDU_RULE_10_11_SPARE_1_WIDTH    ((uint32_t)0x00000007)
#define RXM_RXM_PPDU_RULE_10_11_RULE_10_HIT_MPDU_CNT_MASK    ((uint32_t)0x000001FF)
#define RXM_RXM_PPDU_RULE_10_11_RULE_10_HIT_MPDU_CNT_LSB    0
#define RXM_RXM_PPDU_RULE_10_11_RULE_10_HIT_MPDU_CNT_WIDTH    ((uint32_t)0x00000009)

#define RXM_RXM_PPDU_RULE_10_11_SPARE_2_RST    0x0
#define RXM_RXM_PPDU_RULE_10_11_RULE_11_HIT_MPDU_CNT_RST    0x0
#define RXM_RXM_PPDU_RULE_10_11_SPARE_1_RST    0x0
#define RXM_RXM_PPDU_RULE_10_11_RULE_10_HIT_MPDU_CNT_RST    0x0

__INLINE void rxm_rxm_ppdu_rule_10_11_unpack(uint8_t* spare2, uint16_t* rule11_hit_mpdu_cnt, uint8_t* spare1, uint16_t* rule10_hit_mpdu_cnt)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_10_11_ADDR);

	*spare2 = (localVal & ((uint32_t)0xFE000000)) >>  25;
	*rule11_hit_mpdu_cnt = (localVal & ((uint32_t)0x01FF0000)) >>  16;
	*spare1 = (localVal & ((uint32_t)0x0000FE00)) >>  9;
	*rule10_hit_mpdu_cnt = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint8_t rxm_rxm_ppdu_rule_10_11_spare_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_10_11_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFE000000)) >> 25);
}
__INLINE uint16_t rxm_rxm_ppdu_rule_10_11_rule_11_hit_mpdu_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_10_11_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x01FF0000)) >> 16);
}
__INLINE uint8_t rxm_rxm_ppdu_rule_10_11_spare_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_10_11_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FE00)) >> 9);
}
__INLINE uint16_t rxm_rxm_ppdu_rule_10_11_rule_10_hit_mpdu_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_10_11_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}

/**
 * @brief RXM_PPDU_RULE_12_13 register definition
 *  Rule hit MPDU’s counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:25 spare2                    0x0
 *    24:16 RULE13_HIT_MPDU_CNT       0x0
 *    15:09 spare1                    0x0
 *    08:00 RULE12_HIT_MPDU_CNT       0x0
 * </pre>
 */
#define RXM_RXM_PPDU_RULE_12_13_ADDR        (REG_RXM_BASE_ADDR+0x00000320)
#define RXM_RXM_PPDU_RULE_12_13_OFFSET      0x00000320
#define RXM_RXM_PPDU_RULE_12_13_INDEX       0x000000C8
#define RXM_RXM_PPDU_RULE_12_13_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_ppdu_rule_12_13_get(void)
{
	return REG_PL_RD(RXM_RXM_PPDU_RULE_12_13_ADDR);
}

// field definitions
#define RXM_RXM_PPDU_RULE_12_13_SPARE_2_MASK    ((uint32_t)0xFE000000)
#define RXM_RXM_PPDU_RULE_12_13_SPARE_2_LSB    25
#define RXM_RXM_PPDU_RULE_12_13_SPARE_2_WIDTH    ((uint32_t)0x00000007)
#define RXM_RXM_PPDU_RULE_12_13_RULE_13_HIT_MPDU_CNT_MASK    ((uint32_t)0x01FF0000)
#define RXM_RXM_PPDU_RULE_12_13_RULE_13_HIT_MPDU_CNT_LSB    16
#define RXM_RXM_PPDU_RULE_12_13_RULE_13_HIT_MPDU_CNT_WIDTH    ((uint32_t)0x00000009)
#define RXM_RXM_PPDU_RULE_12_13_SPARE_1_MASK    ((uint32_t)0x0000FE00)
#define RXM_RXM_PPDU_RULE_12_13_SPARE_1_LSB    9
#define RXM_RXM_PPDU_RULE_12_13_SPARE_1_WIDTH    ((uint32_t)0x00000007)
#define RXM_RXM_PPDU_RULE_12_13_RULE_12_HIT_MPDU_CNT_MASK    ((uint32_t)0x000001FF)
#define RXM_RXM_PPDU_RULE_12_13_RULE_12_HIT_MPDU_CNT_LSB    0
#define RXM_RXM_PPDU_RULE_12_13_RULE_12_HIT_MPDU_CNT_WIDTH    ((uint32_t)0x00000009)

#define RXM_RXM_PPDU_RULE_12_13_SPARE_2_RST    0x0
#define RXM_RXM_PPDU_RULE_12_13_RULE_13_HIT_MPDU_CNT_RST    0x0
#define RXM_RXM_PPDU_RULE_12_13_SPARE_1_RST    0x0
#define RXM_RXM_PPDU_RULE_12_13_RULE_12_HIT_MPDU_CNT_RST    0x0

__INLINE void rxm_rxm_ppdu_rule_12_13_unpack(uint8_t* spare2, uint16_t* rule13_hit_mpdu_cnt, uint8_t* spare1, uint16_t* rule12_hit_mpdu_cnt)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_12_13_ADDR);

	*spare2 = (localVal & ((uint32_t)0xFE000000)) >>  25;
	*rule13_hit_mpdu_cnt = (localVal & ((uint32_t)0x01FF0000)) >>  16;
	*spare1 = (localVal & ((uint32_t)0x0000FE00)) >>  9;
	*rule12_hit_mpdu_cnt = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint8_t rxm_rxm_ppdu_rule_12_13_spare_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_12_13_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFE000000)) >> 25);
}
__INLINE uint16_t rxm_rxm_ppdu_rule_12_13_rule_13_hit_mpdu_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_12_13_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x01FF0000)) >> 16);
}
__INLINE uint8_t rxm_rxm_ppdu_rule_12_13_spare_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_12_13_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FE00)) >> 9);
}
__INLINE uint16_t rxm_rxm_ppdu_rule_12_13_rule_12_hit_mpdu_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_12_13_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}

/**
 * @brief RXM_PPDU_RULE_14_15 register definition
 *  Rule hit MPDU’s counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:25 spare2                    0x0
 *    24:16 RULE15_HIT_MPDU_CNT       0x0
 *    15:09 spare1                    0x0
 *    08:00 RULE14_HIT_MPDU_CNT       0x0
 * </pre>
 */
#define RXM_RXM_PPDU_RULE_14_15_ADDR        (REG_RXM_BASE_ADDR+0x00000324)
#define RXM_RXM_PPDU_RULE_14_15_OFFSET      0x00000324
#define RXM_RXM_PPDU_RULE_14_15_INDEX       0x000000C9
#define RXM_RXM_PPDU_RULE_14_15_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_ppdu_rule_14_15_get(void)
{
	return REG_PL_RD(RXM_RXM_PPDU_RULE_14_15_ADDR);
}

// field definitions
#define RXM_RXM_PPDU_RULE_14_15_SPARE_2_MASK    ((uint32_t)0xFE000000)
#define RXM_RXM_PPDU_RULE_14_15_SPARE_2_LSB    25
#define RXM_RXM_PPDU_RULE_14_15_SPARE_2_WIDTH    ((uint32_t)0x00000007)
#define RXM_RXM_PPDU_RULE_14_15_RULE_15_HIT_MPDU_CNT_MASK    ((uint32_t)0x01FF0000)
#define RXM_RXM_PPDU_RULE_14_15_RULE_15_HIT_MPDU_CNT_LSB    16
#define RXM_RXM_PPDU_RULE_14_15_RULE_15_HIT_MPDU_CNT_WIDTH    ((uint32_t)0x00000009)
#define RXM_RXM_PPDU_RULE_14_15_SPARE_1_MASK    ((uint32_t)0x0000FE00)
#define RXM_RXM_PPDU_RULE_14_15_SPARE_1_LSB    9
#define RXM_RXM_PPDU_RULE_14_15_SPARE_1_WIDTH    ((uint32_t)0x00000007)
#define RXM_RXM_PPDU_RULE_14_15_RULE_14_HIT_MPDU_CNT_MASK    ((uint32_t)0x000001FF)
#define RXM_RXM_PPDU_RULE_14_15_RULE_14_HIT_MPDU_CNT_LSB    0
#define RXM_RXM_PPDU_RULE_14_15_RULE_14_HIT_MPDU_CNT_WIDTH    ((uint32_t)0x00000009)

#define RXM_RXM_PPDU_RULE_14_15_SPARE_2_RST    0x0
#define RXM_RXM_PPDU_RULE_14_15_RULE_15_HIT_MPDU_CNT_RST    0x0
#define RXM_RXM_PPDU_RULE_14_15_SPARE_1_RST    0x0
#define RXM_RXM_PPDU_RULE_14_15_RULE_14_HIT_MPDU_CNT_RST    0x0

__INLINE void rxm_rxm_ppdu_rule_14_15_unpack(uint8_t* spare2, uint16_t* rule15_hit_mpdu_cnt, uint8_t* spare1, uint16_t* rule14_hit_mpdu_cnt)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_14_15_ADDR);

	*spare2 = (localVal & ((uint32_t)0xFE000000)) >>  25;
	*rule15_hit_mpdu_cnt = (localVal & ((uint32_t)0x01FF0000)) >>  16;
	*spare1 = (localVal & ((uint32_t)0x0000FE00)) >>  9;
	*rule14_hit_mpdu_cnt = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint8_t rxm_rxm_ppdu_rule_14_15_spare_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_14_15_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFE000000)) >> 25);
}
__INLINE uint16_t rxm_rxm_ppdu_rule_14_15_rule_15_hit_mpdu_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_14_15_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x01FF0000)) >> 16);
}
__INLINE uint8_t rxm_rxm_ppdu_rule_14_15_spare_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_14_15_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FE00)) >> 9);
}
__INLINE uint16_t rxm_rxm_ppdu_rule_14_15_rule_14_hit_mpdu_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_14_15_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}

/**
 * @brief RXM_PPDU_RULE_DEFAULT register definition
 *  Default rule hit MPDU’s counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:09 spare                     0x0
 *    08:00 DEFAULT_MPDU_CNT          0x0
 * </pre>
 */
#define RXM_RXM_PPDU_RULE_DEFAULT_ADDR        (REG_RXM_BASE_ADDR+0x00000328)
#define RXM_RXM_PPDU_RULE_DEFAULT_OFFSET      0x00000328
#define RXM_RXM_PPDU_RULE_DEFAULT_INDEX       0x000000CA
#define RXM_RXM_PPDU_RULE_DEFAULT_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_ppdu_rule_default_get(void)
{
	return REG_PL_RD(RXM_RXM_PPDU_RULE_DEFAULT_ADDR);
}

// field definitions
#define RXM_RXM_PPDU_RULE_DEFAULT_SPARE_MASK    ((uint32_t)0xFFFFFE00)
#define RXM_RXM_PPDU_RULE_DEFAULT_SPARE_LSB    9
#define RXM_RXM_PPDU_RULE_DEFAULT_SPARE_WIDTH    ((uint32_t)0x00000017)
#define RXM_RXM_PPDU_RULE_DEFAULT_DEFAULT_MPDU_CNT_MASK    ((uint32_t)0x000001FF)
#define RXM_RXM_PPDU_RULE_DEFAULT_DEFAULT_MPDU_CNT_LSB    0
#define RXM_RXM_PPDU_RULE_DEFAULT_DEFAULT_MPDU_CNT_WIDTH    ((uint32_t)0x00000009)

#define RXM_RXM_PPDU_RULE_DEFAULT_SPARE_RST    0x0
#define RXM_RXM_PPDU_RULE_DEFAULT_DEFAULT_MPDU_CNT_RST    0x0

__INLINE void rxm_rxm_ppdu_rule_default_unpack(uint32_t* spare, uint16_t* default_mpdu_cnt)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_DEFAULT_ADDR);

	*spare = (localVal & ((uint32_t)0xFFFFFE00)) >>  9;
	*default_mpdu_cnt = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint32_t rxm_rxm_ppdu_rule_default_spare_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_DEFAULT_ADDR);
	return (uint32_t)((localVal & ((uint32_t)0xFFFFFE00)) >> 9);
}
__INLINE uint16_t rxm_rxm_ppdu_rule_default_default_mpdu_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RULE_DEFAULT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}

/**
 * @brief RXM_PPDU_HISTOGRAM_BIN_1_2 register definition
 *  MSDU bin MPDU count register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:25 spare2                    0x0
 *    24:16 BIN2_MPDU_CNT             0x0
 *    15:09 spare1                    0x0
 *    08:00 BIN1_MPDU_CNT             0x0
 * </pre>
 */
#define RXM_RXM_PPDU_HISTOGRAM_BIN_1_2_ADDR        (REG_RXM_BASE_ADDR+0x0000032C)
#define RXM_RXM_PPDU_HISTOGRAM_BIN_1_2_OFFSET      0x0000032C
#define RXM_RXM_PPDU_HISTOGRAM_BIN_1_2_INDEX       0x000000CB
#define RXM_RXM_PPDU_HISTOGRAM_BIN_1_2_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_ppdu_histogram_bin_1_2_get(void)
{
	return REG_PL_RD(RXM_RXM_PPDU_HISTOGRAM_BIN_1_2_ADDR);
}

// field definitions
#define RXM_RXM_PPDU_HISTOGRAM_BIN_1_2_SPARE_2_MASK    ((uint32_t)0xFE000000)
#define RXM_RXM_PPDU_HISTOGRAM_BIN_1_2_SPARE_2_LSB    25
#define RXM_RXM_PPDU_HISTOGRAM_BIN_1_2_SPARE_2_WIDTH    ((uint32_t)0x00000007)
#define RXM_RXM_PPDU_HISTOGRAM_BIN_1_2_BIN_2_MPDU_CNT_MASK    ((uint32_t)0x01FF0000)
#define RXM_RXM_PPDU_HISTOGRAM_BIN_1_2_BIN_2_MPDU_CNT_LSB    16
#define RXM_RXM_PPDU_HISTOGRAM_BIN_1_2_BIN_2_MPDU_CNT_WIDTH    ((uint32_t)0x00000009)
#define RXM_RXM_PPDU_HISTOGRAM_BIN_1_2_SPARE_1_MASK    ((uint32_t)0x0000FE00)
#define RXM_RXM_PPDU_HISTOGRAM_BIN_1_2_SPARE_1_LSB    9
#define RXM_RXM_PPDU_HISTOGRAM_BIN_1_2_SPARE_1_WIDTH    ((uint32_t)0x00000007)
#define RXM_RXM_PPDU_HISTOGRAM_BIN_1_2_BIN_1_MPDU_CNT_MASK    ((uint32_t)0x000001FF)
#define RXM_RXM_PPDU_HISTOGRAM_BIN_1_2_BIN_1_MPDU_CNT_LSB    0
#define RXM_RXM_PPDU_HISTOGRAM_BIN_1_2_BIN_1_MPDU_CNT_WIDTH    ((uint32_t)0x00000009)

#define RXM_RXM_PPDU_HISTOGRAM_BIN_1_2_SPARE_2_RST    0x0
#define RXM_RXM_PPDU_HISTOGRAM_BIN_1_2_BIN_2_MPDU_CNT_RST    0x0
#define RXM_RXM_PPDU_HISTOGRAM_BIN_1_2_SPARE_1_RST    0x0
#define RXM_RXM_PPDU_HISTOGRAM_BIN_1_2_BIN_1_MPDU_CNT_RST    0x0

__INLINE void rxm_rxm_ppdu_histogram_bin_1_2_unpack(uint8_t* spare2, uint16_t* bin2_mpdu_cnt, uint8_t* spare1, uint16_t* bin1_mpdu_cnt)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_HISTOGRAM_BIN_1_2_ADDR);

	*spare2 = (localVal & ((uint32_t)0xFE000000)) >>  25;
	*bin2_mpdu_cnt = (localVal & ((uint32_t)0x01FF0000)) >>  16;
	*spare1 = (localVal & ((uint32_t)0x0000FE00)) >>  9;
	*bin1_mpdu_cnt = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint8_t rxm_rxm_ppdu_histogram_bin_1_2_spare_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_HISTOGRAM_BIN_1_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFE000000)) >> 25);
}
__INLINE uint16_t rxm_rxm_ppdu_histogram_bin_1_2_bin_2_mpdu_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_HISTOGRAM_BIN_1_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x01FF0000)) >> 16);
}
__INLINE uint8_t rxm_rxm_ppdu_histogram_bin_1_2_spare_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_HISTOGRAM_BIN_1_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FE00)) >> 9);
}
__INLINE uint16_t rxm_rxm_ppdu_histogram_bin_1_2_bin_1_mpdu_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_HISTOGRAM_BIN_1_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}

/**
 * @brief RXM_PPDU_HISTOGRAM_BIN_3_4 register definition
 *  MSDU bin MPDU count register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:25 spare2                    0x0
 *    24:16 BIN4_MPDU_CNT             0x0
 *    15:09 spare1                    0x0
 *    08:00 BIN3_MPDU_CNT             0x0
 * </pre>
 */
#define RXM_RXM_PPDU_HISTOGRAM_BIN_3_4_ADDR        (REG_RXM_BASE_ADDR+0x00000330)
#define RXM_RXM_PPDU_HISTOGRAM_BIN_3_4_OFFSET      0x00000330
#define RXM_RXM_PPDU_HISTOGRAM_BIN_3_4_INDEX       0x000000CC
#define RXM_RXM_PPDU_HISTOGRAM_BIN_3_4_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_ppdu_histogram_bin_3_4_get(void)
{
	return REG_PL_RD(RXM_RXM_PPDU_HISTOGRAM_BIN_3_4_ADDR);
}

// field definitions
#define RXM_RXM_PPDU_HISTOGRAM_BIN_3_4_SPARE_2_MASK    ((uint32_t)0xFE000000)
#define RXM_RXM_PPDU_HISTOGRAM_BIN_3_4_SPARE_2_LSB    25
#define RXM_RXM_PPDU_HISTOGRAM_BIN_3_4_SPARE_2_WIDTH    ((uint32_t)0x00000007)
#define RXM_RXM_PPDU_HISTOGRAM_BIN_3_4_BIN_4_MPDU_CNT_MASK    ((uint32_t)0x01FF0000)
#define RXM_RXM_PPDU_HISTOGRAM_BIN_3_4_BIN_4_MPDU_CNT_LSB    16
#define RXM_RXM_PPDU_HISTOGRAM_BIN_3_4_BIN_4_MPDU_CNT_WIDTH    ((uint32_t)0x00000009)
#define RXM_RXM_PPDU_HISTOGRAM_BIN_3_4_SPARE_1_MASK    ((uint32_t)0x0000FE00)
#define RXM_RXM_PPDU_HISTOGRAM_BIN_3_4_SPARE_1_LSB    9
#define RXM_RXM_PPDU_HISTOGRAM_BIN_3_4_SPARE_1_WIDTH    ((uint32_t)0x00000007)
#define RXM_RXM_PPDU_HISTOGRAM_BIN_3_4_BIN_3_MPDU_CNT_MASK    ((uint32_t)0x000001FF)
#define RXM_RXM_PPDU_HISTOGRAM_BIN_3_4_BIN_3_MPDU_CNT_LSB    0
#define RXM_RXM_PPDU_HISTOGRAM_BIN_3_4_BIN_3_MPDU_CNT_WIDTH    ((uint32_t)0x00000009)

#define RXM_RXM_PPDU_HISTOGRAM_BIN_3_4_SPARE_2_RST    0x0
#define RXM_RXM_PPDU_HISTOGRAM_BIN_3_4_BIN_4_MPDU_CNT_RST    0x0
#define RXM_RXM_PPDU_HISTOGRAM_BIN_3_4_SPARE_1_RST    0x0
#define RXM_RXM_PPDU_HISTOGRAM_BIN_3_4_BIN_3_MPDU_CNT_RST    0x0

__INLINE void rxm_rxm_ppdu_histogram_bin_3_4_unpack(uint8_t* spare2, uint16_t* bin4_mpdu_cnt, uint8_t* spare1, uint16_t* bin3_mpdu_cnt)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_HISTOGRAM_BIN_3_4_ADDR);

	*spare2 = (localVal & ((uint32_t)0xFE000000)) >>  25;
	*bin4_mpdu_cnt = (localVal & ((uint32_t)0x01FF0000)) >>  16;
	*spare1 = (localVal & ((uint32_t)0x0000FE00)) >>  9;
	*bin3_mpdu_cnt = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint8_t rxm_rxm_ppdu_histogram_bin_3_4_spare_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_HISTOGRAM_BIN_3_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFE000000)) >> 25);
}
__INLINE uint16_t rxm_rxm_ppdu_histogram_bin_3_4_bin_4_mpdu_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_HISTOGRAM_BIN_3_4_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x01FF0000)) >> 16);
}
__INLINE uint8_t rxm_rxm_ppdu_histogram_bin_3_4_spare_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_HISTOGRAM_BIN_3_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FE00)) >> 9);
}
__INLINE uint16_t rxm_rxm_ppdu_histogram_bin_3_4_bin_3_mpdu_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_HISTOGRAM_BIN_3_4_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}

/**
 * @brief RXM_PPDU_HISTOGRAM_BIN_5_6 register definition
 *  MSDU bin MPDU count register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:25 spare2                    0x0
 *    24:16 BIN6_MPDU_CNT             0x0
 *    15:09 spare1                    0x0
 *    08:00 BIN5_MPDU_CNT             0x0
 * </pre>
 */
#define RXM_RXM_PPDU_HISTOGRAM_BIN_5_6_ADDR        (REG_RXM_BASE_ADDR+0x00000334)
#define RXM_RXM_PPDU_HISTOGRAM_BIN_5_6_OFFSET      0x00000334
#define RXM_RXM_PPDU_HISTOGRAM_BIN_5_6_INDEX       0x000000CD
#define RXM_RXM_PPDU_HISTOGRAM_BIN_5_6_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_ppdu_histogram_bin_5_6_get(void)
{
	return REG_PL_RD(RXM_RXM_PPDU_HISTOGRAM_BIN_5_6_ADDR);
}

// field definitions
#define RXM_RXM_PPDU_HISTOGRAM_BIN_5_6_SPARE_2_MASK    ((uint32_t)0xFE000000)
#define RXM_RXM_PPDU_HISTOGRAM_BIN_5_6_SPARE_2_LSB    25
#define RXM_RXM_PPDU_HISTOGRAM_BIN_5_6_SPARE_2_WIDTH    ((uint32_t)0x00000007)
#define RXM_RXM_PPDU_HISTOGRAM_BIN_5_6_BIN_6_MPDU_CNT_MASK    ((uint32_t)0x01FF0000)
#define RXM_RXM_PPDU_HISTOGRAM_BIN_5_6_BIN_6_MPDU_CNT_LSB    16
#define RXM_RXM_PPDU_HISTOGRAM_BIN_5_6_BIN_6_MPDU_CNT_WIDTH    ((uint32_t)0x00000009)
#define RXM_RXM_PPDU_HISTOGRAM_BIN_5_6_SPARE_1_MASK    ((uint32_t)0x0000FE00)
#define RXM_RXM_PPDU_HISTOGRAM_BIN_5_6_SPARE_1_LSB    9
#define RXM_RXM_PPDU_HISTOGRAM_BIN_5_6_SPARE_1_WIDTH    ((uint32_t)0x00000007)
#define RXM_RXM_PPDU_HISTOGRAM_BIN_5_6_BIN_5_MPDU_CNT_MASK    ((uint32_t)0x000001FF)
#define RXM_RXM_PPDU_HISTOGRAM_BIN_5_6_BIN_5_MPDU_CNT_LSB    0
#define RXM_RXM_PPDU_HISTOGRAM_BIN_5_6_BIN_5_MPDU_CNT_WIDTH    ((uint32_t)0x00000009)

#define RXM_RXM_PPDU_HISTOGRAM_BIN_5_6_SPARE_2_RST    0x0
#define RXM_RXM_PPDU_HISTOGRAM_BIN_5_6_BIN_6_MPDU_CNT_RST    0x0
#define RXM_RXM_PPDU_HISTOGRAM_BIN_5_6_SPARE_1_RST    0x0
#define RXM_RXM_PPDU_HISTOGRAM_BIN_5_6_BIN_5_MPDU_CNT_RST    0x0

__INLINE void rxm_rxm_ppdu_histogram_bin_5_6_unpack(uint8_t* spare2, uint16_t* bin6_mpdu_cnt, uint8_t* spare1, uint16_t* bin5_mpdu_cnt)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_HISTOGRAM_BIN_5_6_ADDR);

	*spare2 = (localVal & ((uint32_t)0xFE000000)) >>  25;
	*bin6_mpdu_cnt = (localVal & ((uint32_t)0x01FF0000)) >>  16;
	*spare1 = (localVal & ((uint32_t)0x0000FE00)) >>  9;
	*bin5_mpdu_cnt = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint8_t rxm_rxm_ppdu_histogram_bin_5_6_spare_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_HISTOGRAM_BIN_5_6_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFE000000)) >> 25);
}
__INLINE uint16_t rxm_rxm_ppdu_histogram_bin_5_6_bin_6_mpdu_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_HISTOGRAM_BIN_5_6_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x01FF0000)) >> 16);
}
__INLINE uint8_t rxm_rxm_ppdu_histogram_bin_5_6_spare_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_HISTOGRAM_BIN_5_6_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FE00)) >> 9);
}
__INLINE uint16_t rxm_rxm_ppdu_histogram_bin_5_6_bin_5_mpdu_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_HISTOGRAM_BIN_5_6_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}

/**
 * @brief RXM_PPDU_RSSI_LOW register definition
 *  RSSI low info register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RSSI_LOW                  0x0
 * </pre>
 */
#define RXM_RXM_PPDU_RSSI_LOW_ADDR        (REG_RXM_BASE_ADDR+0x00000338)
#define RXM_RXM_PPDU_RSSI_LOW_OFFSET      0x00000338
#define RXM_RXM_PPDU_RSSI_LOW_INDEX       0x000000CE
#define RXM_RXM_PPDU_RSSI_LOW_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_ppdu_rssi_low_get(void)
{
	return REG_PL_RD(RXM_RXM_PPDU_RSSI_LOW_ADDR);
}

// field definitions
#define RXM_RXM_PPDU_RSSI_LOW_RSSI_LOW_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_PPDU_RSSI_LOW_RSSI_LOW_LSB    0
#define RXM_RXM_PPDU_RSSI_LOW_RSSI_LOW_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_PPDU_RSSI_LOW_RSSI_LOW_RST    0x0

__INLINE uint32_t rxm_rxm_ppdu_rssi_low_rssi_low_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RSSI_LOW_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RXM_PPDU_RSSI_HIGH register definition
 *  RSSI high info register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RSSI_HIGH                 0x0
 * </pre>
 */
#define RXM_RXM_PPDU_RSSI_HIGH_ADDR        (REG_RXM_BASE_ADDR+0x0000033C)
#define RXM_RXM_PPDU_RSSI_HIGH_OFFSET      0x0000033C
#define RXM_RXM_PPDU_RSSI_HIGH_INDEX       0x000000CF
#define RXM_RXM_PPDU_RSSI_HIGH_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_ppdu_rssi_high_get(void)
{
	return REG_PL_RD(RXM_RXM_PPDU_RSSI_HIGH_ADDR);
}

// field definitions
#define RXM_RXM_PPDU_RSSI_HIGH_RSSI_HIGH_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_PPDU_RSSI_HIGH_RSSI_HIGH_LSB    0
#define RXM_RXM_PPDU_RSSI_HIGH_RSSI_HIGH_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_PPDU_RSSI_HIGH_RSSI_HIGH_RST    0x0

__INLINE uint32_t rxm_rxm_ppdu_rssi_high_rssi_high_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_RSSI_HIGH_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RXM_PPDU_KEY_RAM register definition
 *  KEY RAM valid and index register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    KEY_RAM_INDEX_VALID       0              
 *    30:09 spare                     0x0
 *    08:00 KEY_RAM_INDEX             0x0
 * </pre>
 */
#define RXM_RXM_PPDU_KEY_RAM_ADDR        (REG_RXM_BASE_ADDR+0x00000340)
#define RXM_RXM_PPDU_KEY_RAM_OFFSET      0x00000340
#define RXM_RXM_PPDU_KEY_RAM_INDEX       0x000000D0
#define RXM_RXM_PPDU_KEY_RAM_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_ppdu_key_ram_get(void)
{
	return REG_PL_RD(RXM_RXM_PPDU_KEY_RAM_ADDR);
}

// field definitions
#define RXM_RXM_PPDU_KEY_RAM_KEY_RAM_INDEX_VALID_BIT    ((uint32_t)0x80000000)
#define RXM_RXM_PPDU_KEY_RAM_KEY_RAM_INDEX_VALID_POS    31
#define RXM_RXM_PPDU_KEY_RAM_SPARE_MASK     ((uint32_t)0x7FFFFE00)
#define RXM_RXM_PPDU_KEY_RAM_SPARE_LSB      9
#define RXM_RXM_PPDU_KEY_RAM_SPARE_WIDTH    ((uint32_t)0x00000016)
#define RXM_RXM_PPDU_KEY_RAM_KEY_RAM_INDEX_MASK    ((uint32_t)0x000001FF)
#define RXM_RXM_PPDU_KEY_RAM_KEY_RAM_INDEX_LSB    0
#define RXM_RXM_PPDU_KEY_RAM_KEY_RAM_INDEX_WIDTH    ((uint32_t)0x00000009)

#define RXM_RXM_PPDU_KEY_RAM_KEY_RAM_INDEX_VALID_RST    0x0
#define RXM_RXM_PPDU_KEY_RAM_SPARE_RST      0x0
#define RXM_RXM_PPDU_KEY_RAM_KEY_RAM_INDEX_RST    0x0

__INLINE void rxm_rxm_ppdu_key_ram_unpack(uint8_t* key_ram_index_valid, uint32_t* spare, uint16_t* key_ram_index)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_KEY_RAM_ADDR);

	*key_ram_index_valid = (localVal & ((uint32_t)0x80000000)) >>  31;
	*spare = (localVal & ((uint32_t)0x7FFFFE00)) >>  9;
	*key_ram_index = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint8_t rxm_rxm_ppdu_key_ram_key_ram_index_valid_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_KEY_RAM_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE uint32_t rxm_rxm_ppdu_key_ram_spare_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_KEY_RAM_ADDR);
	return (uint32_t)((localVal & ((uint32_t)0x7FFFFE00)) >> 9);
}
__INLINE uint16_t rxm_rxm_ppdu_key_ram_key_ram_index_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_KEY_RAM_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}

/**
 * @brief RXM_PPDU_FC_DURATION register definition
 *  FC and Duration fields register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 DURATION_ID               0x0
 *    15:00 FRAME_CONTROL             0x0
 * </pre>
 */
#define RXM_RXM_PPDU_FC_DURATION_ADDR        (REG_RXM_BASE_ADDR+0x00000344)
#define RXM_RXM_PPDU_FC_DURATION_OFFSET      0x00000344
#define RXM_RXM_PPDU_FC_DURATION_INDEX       0x000000D1
#define RXM_RXM_PPDU_FC_DURATION_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_ppdu_fc_duration_get(void)
{
	return REG_PL_RD(RXM_RXM_PPDU_FC_DURATION_ADDR);
}

// field definitions
#define RXM_RXM_PPDU_FC_DURATION_DURATION_ID_MASK    ((uint32_t)0xFFFF0000)
#define RXM_RXM_PPDU_FC_DURATION_DURATION_ID_LSB    16
#define RXM_RXM_PPDU_FC_DURATION_DURATION_ID_WIDTH    ((uint32_t)0x00000010)
#define RXM_RXM_PPDU_FC_DURATION_FRAME_CONTROL_MASK    ((uint32_t)0x0000FFFF)
#define RXM_RXM_PPDU_FC_DURATION_FRAME_CONTROL_LSB    0
#define RXM_RXM_PPDU_FC_DURATION_FRAME_CONTROL_WIDTH    ((uint32_t)0x00000010)

#define RXM_RXM_PPDU_FC_DURATION_DURATION_ID_RST    0x0
#define RXM_RXM_PPDU_FC_DURATION_FRAME_CONTROL_RST    0x0

__INLINE void rxm_rxm_ppdu_fc_duration_unpack(uint16_t* duration_id, uint16_t* frame_control)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_FC_DURATION_ADDR);

	*duration_id = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*frame_control = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t rxm_rxm_ppdu_fc_duration_duration_id_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_FC_DURATION_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE uint16_t rxm_rxm_ppdu_fc_duration_frame_control_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_FC_DURATION_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

/**
 * @brief RXM_PPDU_QC register definition
 *  QC field register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 spare                     0x0
 *    15:00 QOS_CONTROL               0x0
 * </pre>
 */
#define RXM_RXM_PPDU_QC_ADDR        (REG_RXM_BASE_ADDR+0x00000348)
#define RXM_RXM_PPDU_QC_OFFSET      0x00000348
#define RXM_RXM_PPDU_QC_INDEX       0x000000D2
#define RXM_RXM_PPDU_QC_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_ppdu_qc_get(void)
{
	return REG_PL_RD(RXM_RXM_PPDU_QC_ADDR);
}

// field definitions
#define RXM_RXM_PPDU_QC_SPARE_MASK          ((uint32_t)0xFFFF0000)
#define RXM_RXM_PPDU_QC_SPARE_LSB           16
#define RXM_RXM_PPDU_QC_SPARE_WIDTH         ((uint32_t)0x00000010)
#define RXM_RXM_PPDU_QC_QOS_CONTROL_MASK    ((uint32_t)0x0000FFFF)
#define RXM_RXM_PPDU_QC_QOS_CONTROL_LSB     0
#define RXM_RXM_PPDU_QC_QOS_CONTROL_WIDTH    ((uint32_t)0x00000010)

#define RXM_RXM_PPDU_QC_SPARE_RST           0x0
#define RXM_RXM_PPDU_QC_QOS_CONTROL_RST     0x0

__INLINE void rxm_rxm_ppdu_qc_unpack(uint16_t* spare, uint16_t* qos_control)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_QC_ADDR);

	*spare = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*qos_control = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t rxm_rxm_ppdu_qc_spare_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_QC_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE uint16_t rxm_rxm_ppdu_qc_qos_control_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_QC_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

/**
 * @brief RXM_PPDU_HTC register definition
 *  HTC field register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 HT_CONTROL                0x0
 * </pre>
 */
#define RXM_RXM_PPDU_HTC_ADDR        (REG_RXM_BASE_ADDR+0x0000034C)
#define RXM_RXM_PPDU_HTC_OFFSET      0x0000034C
#define RXM_RXM_PPDU_HTC_INDEX       0x000000D3
#define RXM_RXM_PPDU_HTC_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_ppdu_htc_get(void)
{
	return REG_PL_RD(RXM_RXM_PPDU_HTC_ADDR);
}

// field definitions
#define RXM_RXM_PPDU_HTC_HT_CONTROL_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_PPDU_HTC_HT_CONTROL_LSB     0
#define RXM_RXM_PPDU_HTC_HT_CONTROL_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_PPDU_HTC_HT_CONTROL_RST     0x0

__INLINE uint32_t rxm_rxm_ppdu_htc_ht_control_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_PPDU_HTC_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RXM_DRA_PERIOD register definition
 *  DRA scan period register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    04:00 DRA_PERIOD                0x4
 * </pre>
 */
#define RXM_RXM_DRA_PERIOD_ADDR        (REG_RXM_BASE_ADDR+0x00000360)
#define RXM_RXM_DRA_PERIOD_OFFSET      0x00000360
#define RXM_RXM_DRA_PERIOD_INDEX       0x000000D8
#define RXM_RXM_DRA_PERIOD_RESET       0x00000004

__INLINE uint32_t  rxm_rxm_dra_period_get(void)
{
	return REG_PL_RD(RXM_RXM_DRA_PERIOD_ADDR);
}

__INLINE void rxm_rxm_dra_period_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_DRA_PERIOD_ADDR, value);
}

// field definitions
#define RXM_RXM_DRA_PERIOD_DRA_PERIOD_MASK    ((uint32_t)0x0000001F)
#define RXM_RXM_DRA_PERIOD_DRA_PERIOD_LSB    0
#define RXM_RXM_DRA_PERIOD_DRA_PERIOD_WIDTH    ((uint32_t)0x00000005)

#define RXM_RXM_DRA_PERIOD_DRA_PERIOD_RST    0x4

__INLINE uint8_t rxm_rxm_dra_period_dra_period_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_DRA_PERIOD_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void rxm_rxm_dra_period_dra_period_setf(uint8_t draperiod)
{
	ASSERT_ERR((((uint32_t)draperiod << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RXM_RXM_DRA_PERIOD_ADDR, (uint32_t)draperiod << 0);
}

/**
 * @brief RXM_DRA_PCIEW_GROUP_LIMITS_ADDR register definition
 *  PCIEW_LLI_GROUP_LIMIT register address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PCIEW_GROUP_LIMITS_ADDR   0x0
 * </pre>
 */
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_ADDR_ADDR        (REG_RXM_BASE_ADDR+0x00000364)
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_ADDR_OFFSET      0x00000364
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_ADDR_INDEX       0x000000D9
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_ADDR_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_dra_pciew_group_limits_addr_get(void)
{
	return REG_PL_RD(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_ADDR_ADDR);
}

__INLINE void rxm_rxm_dra_pciew_group_limits_addr_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_ADDR_ADDR, value);
}

// field definitions
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_ADDR_PCIEW_GROUP_LIMITS_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_ADDR_PCIEW_GROUP_LIMITS_ADDR_LSB    0
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_ADDR_PCIEW_GROUP_LIMITS_ADDR_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_ADDR_PCIEW_GROUP_LIMITS_ADDR_RST    0x0

__INLINE uint32_t rxm_rxm_dra_pciew_group_limits_addr_pciew_group_limits_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_dra_pciew_group_limits_addr_pciew_group_limits_addr_setf(uint32_t pciewgrouplimitsaddr)
{
	ASSERT_ERR((((uint32_t)pciewgrouplimitsaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_ADDR_ADDR, (uint32_t)pciewgrouplimitsaddr << 0);
}

/**
 * @brief RXM_DRA_DBG register definition
 *  DRA debug info register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    07:04 DRA_SM                    0x0
 *    03    MACHW1_ACTIVE_TX          0              
 *    02    RXM1_RX_OVERLOAD          0              
 *    01    MACHW0_ACTIVE_TX          0              
 *    00    RXM0_RX_OVERLOAD          0              
 * </pre>
 */
#define RXM_RXM_DRA_DBG_ADDR        (REG_RXM_BASE_ADDR+0x00000368)
#define RXM_RXM_DRA_DBG_OFFSET      0x00000368
#define RXM_RXM_DRA_DBG_INDEX       0x000000DA
#define RXM_RXM_DRA_DBG_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_dra_dbg_get(void)
{
	return REG_PL_RD(RXM_RXM_DRA_DBG_ADDR);
}

// field definitions
#define RXM_RXM_DRA_DBG_DRA_SM_MASK         ((uint32_t)0x000000F0)
#define RXM_RXM_DRA_DBG_DRA_SM_LSB          4
#define RXM_RXM_DRA_DBG_DRA_SM_WIDTH        ((uint32_t)0x00000004)
#define RXM_RXM_DRA_DBG_MACHW_1_ACTIVE_TX_BIT    ((uint32_t)0x00000008)
#define RXM_RXM_DRA_DBG_MACHW_1_ACTIVE_TX_POS    3
#define RXM_RXM_DRA_DBG_RXM_1_RX_OVERLOAD_BIT    ((uint32_t)0x00000004)
#define RXM_RXM_DRA_DBG_RXM_1_RX_OVERLOAD_POS    2
#define RXM_RXM_DRA_DBG_MACHW_0_ACTIVE_TX_BIT    ((uint32_t)0x00000002)
#define RXM_RXM_DRA_DBG_MACHW_0_ACTIVE_TX_POS    1
#define RXM_RXM_DRA_DBG_RXM_0_RX_OVERLOAD_BIT    ((uint32_t)0x00000001)
#define RXM_RXM_DRA_DBG_RXM_0_RX_OVERLOAD_POS    0

#define RXM_RXM_DRA_DBG_DRA_SM_RST          0x0
#define RXM_RXM_DRA_DBG_MACHW_1_ACTIVE_TX_RST    0x0
#define RXM_RXM_DRA_DBG_RXM_1_RX_OVERLOAD_RST    0x0
#define RXM_RXM_DRA_DBG_MACHW_0_ACTIVE_TX_RST    0x0
#define RXM_RXM_DRA_DBG_RXM_0_RX_OVERLOAD_RST    0x0

__INLINE void rxm_rxm_dra_dbg_unpack(uint8_t* dra_sm, uint8_t* machw1_active_tx, uint8_t* rxm1_rx_overload, uint8_t* machw0_active_tx, uint8_t* rxm0_rx_overload)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_DRA_DBG_ADDR);

	*dra_sm = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*machw1_active_tx = (localVal & ((uint32_t)0x00000008)) >>  3;
	*rxm1_rx_overload = (localVal & ((uint32_t)0x00000004)) >>  2;
	*machw0_active_tx = (localVal & ((uint32_t)0x00000002)) >>  1;
	*rxm0_rx_overload = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t rxm_rxm_dra_dbg_dra_sm_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_DRA_DBG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t rxm_rxm_dra_dbg_machw_1_active_tx_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_DRA_DBG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE uint8_t rxm_rxm_dra_dbg_rxm_1_rx_overload_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_DRA_DBG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE uint8_t rxm_rxm_dra_dbg_machw_0_active_tx_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_DRA_DBG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t rxm_rxm_dra_dbg_rxm_0_rx_overload_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_DRA_DBG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief RXM_DRA_PCIEW_GROUP_LIMITS_CHANGE_CNT register definition
 *  Counts number of changes in DRA input status register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PCIEW_GROUP_LIMITS_CHANGE_CNT 0x0
 * </pre>
 */
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_CHANGE_CNT_ADDR        (REG_RXM_BASE_ADDR+0x0000036C)
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_CHANGE_CNT_OFFSET      0x0000036C
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_CHANGE_CNT_INDEX       0x000000DB
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_CHANGE_CNT_RESET       0x00000000

__INLINE uint32_t  rxm_rxm_dra_pciew_group_limits_change_cnt_get(void)
{
	return REG_PL_RD(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_CHANGE_CNT_ADDR);
}

// field definitions
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_CHANGE_CNT_PCIEW_GROUP_LIMITS_CHANGE_CNT_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_CHANGE_CNT_PCIEW_GROUP_LIMITS_CHANGE_CNT_LSB    0
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_CHANGE_CNT_PCIEW_GROUP_LIMITS_CHANGE_CNT_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_CHANGE_CNT_PCIEW_GROUP_LIMITS_CHANGE_CNT_RST    0x0

__INLINE uint32_t rxm_rxm_dra_pciew_group_limits_change_cnt_pciew_group_limits_change_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_CHANGE_CNT_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RXM_DRA_PCIEW_GROUP_LIMITS_0 register definition
 *  DRA group limit value register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PCIEW_GROUP_LIMITS_0      0x08080808
 * </pre>
 */
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_0_ADDR        (REG_RXM_BASE_ADDR+0x00000370)
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_0_OFFSET      0x00000370
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_0_INDEX       0x000000DC
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_0_RESET       0x08080808

__INLINE uint32_t  rxm_rxm_dra_pciew_group_limits_0_get(void)
{
	return REG_PL_RD(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_0_ADDR);
}

__INLINE void rxm_rxm_dra_pciew_group_limits_0_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_0_ADDR, value);
}

// field definitions
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_0_PCIEW_GROUP_LIMITS_0_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_0_PCIEW_GROUP_LIMITS_0_LSB    0
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_0_PCIEW_GROUP_LIMITS_0_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_0_PCIEW_GROUP_LIMITS_0_RST    0x08080808

__INLINE uint32_t rxm_rxm_dra_pciew_group_limits_0_pciew_group_limits_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_0_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_dra_pciew_group_limits_0_pciew_group_limits_0_setf(uint32_t pciewgrouplimits0)
{
	ASSERT_ERR((((uint32_t)pciewgrouplimits0 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_0_ADDR, (uint32_t)pciewgrouplimits0 << 0);
}

/**
 * @brief RXM_DRA_PCIEW_GROUP_LIMITS_1 register definition
 *  DRA group limit value register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PCIEW_GROUP_LIMITS_1      0x08080808
 * </pre>
 */
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_1_ADDR        (REG_RXM_BASE_ADDR+0x00000374)
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_1_OFFSET      0x00000374
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_1_INDEX       0x000000DD
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_1_RESET       0x08080808

__INLINE uint32_t  rxm_rxm_dra_pciew_group_limits_1_get(void)
{
	return REG_PL_RD(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_1_ADDR);
}

__INLINE void rxm_rxm_dra_pciew_group_limits_1_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_1_ADDR, value);
}

// field definitions
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_1_PCIEW_GROUP_LIMITS_1_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_1_PCIEW_GROUP_LIMITS_1_LSB    0
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_1_PCIEW_GROUP_LIMITS_1_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_1_PCIEW_GROUP_LIMITS_1_RST    0x08080808

__INLINE uint32_t rxm_rxm_dra_pciew_group_limits_1_pciew_group_limits_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_1_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_dra_pciew_group_limits_1_pciew_group_limits_1_setf(uint32_t pciewgrouplimits1)
{
	ASSERT_ERR((((uint32_t)pciewgrouplimits1 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_1_ADDR, (uint32_t)pciewgrouplimits1 << 0);
}

/**
 * @brief RXM_DRA_PCIEW_GROUP_LIMITS_2 register definition
 *  DRA group limit value register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PCIEW_GROUP_LIMITS_2      0x08080808
 * </pre>
 */
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_2_ADDR        (REG_RXM_BASE_ADDR+0x00000378)
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_2_OFFSET      0x00000378
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_2_INDEX       0x000000DE
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_2_RESET       0x08080808

__INLINE uint32_t  rxm_rxm_dra_pciew_group_limits_2_get(void)
{
	return REG_PL_RD(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_2_ADDR);
}

__INLINE void rxm_rxm_dra_pciew_group_limits_2_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_2_ADDR, value);
}

// field definitions
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_2_PCIEW_GROUP_LIMITS_2_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_2_PCIEW_GROUP_LIMITS_2_LSB    0
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_2_PCIEW_GROUP_LIMITS_2_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_2_PCIEW_GROUP_LIMITS_2_RST    0x08080808

__INLINE uint32_t rxm_rxm_dra_pciew_group_limits_2_pciew_group_limits_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_2_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_dra_pciew_group_limits_2_pciew_group_limits_2_setf(uint32_t pciewgrouplimits2)
{
	ASSERT_ERR((((uint32_t)pciewgrouplimits2 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_2_ADDR, (uint32_t)pciewgrouplimits2 << 0);
}

/**
 * @brief RXM_DRA_PCIEW_GROUP_LIMITS_3 register definition
 *  DRA group limit value register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PCIEW_GROUP_LIMITS_3      0x08080808
 * </pre>
 */
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_3_ADDR        (REG_RXM_BASE_ADDR+0x0000037C)
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_3_OFFSET      0x0000037C
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_3_INDEX       0x000000DF
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_3_RESET       0x08080808

__INLINE uint32_t  rxm_rxm_dra_pciew_group_limits_3_get(void)
{
	return REG_PL_RD(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_3_ADDR);
}

__INLINE void rxm_rxm_dra_pciew_group_limits_3_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_3_ADDR, value);
}

// field definitions
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_3_PCIEW_GROUP_LIMITS_3_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_3_PCIEW_GROUP_LIMITS_3_LSB    0
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_3_PCIEW_GROUP_LIMITS_3_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_3_PCIEW_GROUP_LIMITS_3_RST    0x08080808

__INLINE uint32_t rxm_rxm_dra_pciew_group_limits_3_pciew_group_limits_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_3_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_dra_pciew_group_limits_3_pciew_group_limits_3_setf(uint32_t pciewgrouplimits3)
{
	ASSERT_ERR((((uint32_t)pciewgrouplimits3 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_3_ADDR, (uint32_t)pciewgrouplimits3 << 0);
}

/**
 * @brief RXM_DRA_PCIEW_GROUP_LIMITS_4 register definition
 *  DRA group limit value register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PCIEW_GROUP_LIMITS_4      0x08080808
 * </pre>
 */
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_4_ADDR        (REG_RXM_BASE_ADDR+0x00000380)
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_4_OFFSET      0x00000380
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_4_INDEX       0x000000E0
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_4_RESET       0x08080808

__INLINE uint32_t  rxm_rxm_dra_pciew_group_limits_4_get(void)
{
	return REG_PL_RD(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_4_ADDR);
}

__INLINE void rxm_rxm_dra_pciew_group_limits_4_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_4_ADDR, value);
}

// field definitions
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_4_PCIEW_GROUP_LIMITS_4_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_4_PCIEW_GROUP_LIMITS_4_LSB    0
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_4_PCIEW_GROUP_LIMITS_4_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_4_PCIEW_GROUP_LIMITS_4_RST    0x08080808

__INLINE uint32_t rxm_rxm_dra_pciew_group_limits_4_pciew_group_limits_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_4_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_dra_pciew_group_limits_4_pciew_group_limits_4_setf(uint32_t pciewgrouplimits4)
{
	ASSERT_ERR((((uint32_t)pciewgrouplimits4 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_4_ADDR, (uint32_t)pciewgrouplimits4 << 0);
}

/**
 * @brief RXM_DRA_PCIEW_GROUP_LIMITS_5 register definition
 *  DRA group limit value register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PCIEW_GROUP_LIMITS_5      0x08080808
 * </pre>
 */
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_5_ADDR        (REG_RXM_BASE_ADDR+0x00000384)
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_5_OFFSET      0x00000384
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_5_INDEX       0x000000E1
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_5_RESET       0x08080808

__INLINE uint32_t  rxm_rxm_dra_pciew_group_limits_5_get(void)
{
	return REG_PL_RD(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_5_ADDR);
}

__INLINE void rxm_rxm_dra_pciew_group_limits_5_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_5_ADDR, value);
}

// field definitions
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_5_PCIEW_GROUP_LIMITS_5_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_5_PCIEW_GROUP_LIMITS_5_LSB    0
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_5_PCIEW_GROUP_LIMITS_5_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_5_PCIEW_GROUP_LIMITS_5_RST    0x08080808

__INLINE uint32_t rxm_rxm_dra_pciew_group_limits_5_pciew_group_limits_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_5_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_dra_pciew_group_limits_5_pciew_group_limits_5_setf(uint32_t pciewgrouplimits5)
{
	ASSERT_ERR((((uint32_t)pciewgrouplimits5 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_5_ADDR, (uint32_t)pciewgrouplimits5 << 0);
}

/**
 * @brief RXM_DRA_PCIEW_GROUP_LIMITS_6 register definition
 *  DRA group limit value register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PCIEW_GROUP_LIMITS_6      0x08080808
 * </pre>
 */
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_6_ADDR        (REG_RXM_BASE_ADDR+0x00000388)
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_6_OFFSET      0x00000388
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_6_INDEX       0x000000E2
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_6_RESET       0x08080808

__INLINE uint32_t  rxm_rxm_dra_pciew_group_limits_6_get(void)
{
	return REG_PL_RD(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_6_ADDR);
}

__INLINE void rxm_rxm_dra_pciew_group_limits_6_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_6_ADDR, value);
}

// field definitions
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_6_PCIEW_GROUP_LIMITS_6_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_6_PCIEW_GROUP_LIMITS_6_LSB    0
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_6_PCIEW_GROUP_LIMITS_6_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_6_PCIEW_GROUP_LIMITS_6_RST    0x08080808

__INLINE uint32_t rxm_rxm_dra_pciew_group_limits_6_pciew_group_limits_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_6_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_dra_pciew_group_limits_6_pciew_group_limits_6_setf(uint32_t pciewgrouplimits6)
{
	ASSERT_ERR((((uint32_t)pciewgrouplimits6 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_6_ADDR, (uint32_t)pciewgrouplimits6 << 0);
}

/**
 * @brief RXM_DRA_PCIEW_GROUP_LIMITS_7 register definition
 *  DRA group limit value register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PCIEW_GROUP_LIMITS_7      0x08080808
 * </pre>
 */
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_7_ADDR        (REG_RXM_BASE_ADDR+0x0000038C)
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_7_OFFSET      0x0000038C
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_7_INDEX       0x000000E3
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_7_RESET       0x08080808

__INLINE uint32_t  rxm_rxm_dra_pciew_group_limits_7_get(void)
{
	return REG_PL_RD(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_7_ADDR);
}

__INLINE void rxm_rxm_dra_pciew_group_limits_7_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_7_ADDR, value);
}

// field definitions
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_7_PCIEW_GROUP_LIMITS_7_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_7_PCIEW_GROUP_LIMITS_7_LSB    0
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_7_PCIEW_GROUP_LIMITS_7_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_7_PCIEW_GROUP_LIMITS_7_RST    0x08080808

__INLINE uint32_t rxm_rxm_dra_pciew_group_limits_7_pciew_group_limits_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_7_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_dra_pciew_group_limits_7_pciew_group_limits_7_setf(uint32_t pciewgrouplimits7)
{
	ASSERT_ERR((((uint32_t)pciewgrouplimits7 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_7_ADDR, (uint32_t)pciewgrouplimits7 << 0);
}

/**
 * @brief RXM_DRA_PCIEW_GROUP_LIMITS_8 register definition
 *  DRA group limit value register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PCIEW_GROUP_LIMITS_8      0x08080808
 * </pre>
 */
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_8_ADDR        (REG_RXM_BASE_ADDR+0x00000390)
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_8_OFFSET      0x00000390
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_8_INDEX       0x000000E4
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_8_RESET       0x08080808

__INLINE uint32_t  rxm_rxm_dra_pciew_group_limits_8_get(void)
{
	return REG_PL_RD(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_8_ADDR);
}

__INLINE void rxm_rxm_dra_pciew_group_limits_8_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_8_ADDR, value);
}

// field definitions
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_8_PCIEW_GROUP_LIMITS_8_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_8_PCIEW_GROUP_LIMITS_8_LSB    0
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_8_PCIEW_GROUP_LIMITS_8_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_8_PCIEW_GROUP_LIMITS_8_RST    0x08080808

__INLINE uint32_t rxm_rxm_dra_pciew_group_limits_8_pciew_group_limits_8_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_8_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_dra_pciew_group_limits_8_pciew_group_limits_8_setf(uint32_t pciewgrouplimits8)
{
	ASSERT_ERR((((uint32_t)pciewgrouplimits8 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_8_ADDR, (uint32_t)pciewgrouplimits8 << 0);
}

/**
 * @brief RXM_DRA_PCIEW_GROUP_LIMITS_9 register definition
 *  DRA group limit value register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PCIEW_GROUP_LIMITS_9      0x08080808
 * </pre>
 */
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_9_ADDR        (REG_RXM_BASE_ADDR+0x00000394)
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_9_OFFSET      0x00000394
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_9_INDEX       0x000000E5
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_9_RESET       0x08080808

__INLINE uint32_t  rxm_rxm_dra_pciew_group_limits_9_get(void)
{
	return REG_PL_RD(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_9_ADDR);
}

__INLINE void rxm_rxm_dra_pciew_group_limits_9_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_9_ADDR, value);
}

// field definitions
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_9_PCIEW_GROUP_LIMITS_9_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_9_PCIEW_GROUP_LIMITS_9_LSB    0
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_9_PCIEW_GROUP_LIMITS_9_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_9_PCIEW_GROUP_LIMITS_9_RST    0x08080808

__INLINE uint32_t rxm_rxm_dra_pciew_group_limits_9_pciew_group_limits_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_9_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_dra_pciew_group_limits_9_pciew_group_limits_9_setf(uint32_t pciewgrouplimits9)
{
	ASSERT_ERR((((uint32_t)pciewgrouplimits9 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_9_ADDR, (uint32_t)pciewgrouplimits9 << 0);
}

/**
 * @brief RXM_DRA_PCIEW_GROUP_LIMITS_10 register definition
 *  DRA group limit value register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PCIEW_GROUP_LIMITS_10     0x08080808
 * </pre>
 */
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_10_ADDR        (REG_RXM_BASE_ADDR+0x00000398)
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_10_OFFSET      0x00000398
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_10_INDEX       0x000000E6
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_10_RESET       0x08080808

__INLINE uint32_t  rxm_rxm_dra_pciew_group_limits_10_get(void)
{
	return REG_PL_RD(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_10_ADDR);
}

__INLINE void rxm_rxm_dra_pciew_group_limits_10_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_10_ADDR, value);
}

// field definitions
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_10_PCIEW_GROUP_LIMITS_10_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_10_PCIEW_GROUP_LIMITS_10_LSB    0
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_10_PCIEW_GROUP_LIMITS_10_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_10_PCIEW_GROUP_LIMITS_10_RST    0x08080808

__INLINE uint32_t rxm_rxm_dra_pciew_group_limits_10_pciew_group_limits_10_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_10_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_dra_pciew_group_limits_10_pciew_group_limits_10_setf(uint32_t pciewgrouplimits10)
{
	ASSERT_ERR((((uint32_t)pciewgrouplimits10 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_10_ADDR, (uint32_t)pciewgrouplimits10 << 0);
}

/**
 * @brief RXM_DRA_PCIEW_GROUP_LIMITS_11 register definition
 *  DRA group limit value register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PCIEW_GROUP_LIMITS_11     0x08080808
 * </pre>
 */
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_11_ADDR        (REG_RXM_BASE_ADDR+0x0000039C)
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_11_OFFSET      0x0000039C
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_11_INDEX       0x000000E7
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_11_RESET       0x08080808

__INLINE uint32_t  rxm_rxm_dra_pciew_group_limits_11_get(void)
{
	return REG_PL_RD(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_11_ADDR);
}

__INLINE void rxm_rxm_dra_pciew_group_limits_11_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_11_ADDR, value);
}

// field definitions
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_11_PCIEW_GROUP_LIMITS_11_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_11_PCIEW_GROUP_LIMITS_11_LSB    0
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_11_PCIEW_GROUP_LIMITS_11_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_11_PCIEW_GROUP_LIMITS_11_RST    0x08080808

__INLINE uint32_t rxm_rxm_dra_pciew_group_limits_11_pciew_group_limits_11_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_11_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_dra_pciew_group_limits_11_pciew_group_limits_11_setf(uint32_t pciewgrouplimits11)
{
	ASSERT_ERR((((uint32_t)pciewgrouplimits11 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_11_ADDR, (uint32_t)pciewgrouplimits11 << 0);
}

/**
 * @brief RXM_DRA_PCIEW_GROUP_LIMITS_12 register definition
 *  DRA group limit value register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PCIEW_GROUP_LIMITS_12     0x08080808
 * </pre>
 */
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_12_ADDR        (REG_RXM_BASE_ADDR+0x000003A0)
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_12_OFFSET      0x000003A0
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_12_INDEX       0x000000E8
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_12_RESET       0x08080808

__INLINE uint32_t  rxm_rxm_dra_pciew_group_limits_12_get(void)
{
	return REG_PL_RD(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_12_ADDR);
}

__INLINE void rxm_rxm_dra_pciew_group_limits_12_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_12_ADDR, value);
}

// field definitions
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_12_PCIEW_GROUP_LIMITS_12_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_12_PCIEW_GROUP_LIMITS_12_LSB    0
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_12_PCIEW_GROUP_LIMITS_12_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_12_PCIEW_GROUP_LIMITS_12_RST    0x08080808

__INLINE uint32_t rxm_rxm_dra_pciew_group_limits_12_pciew_group_limits_12_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_12_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_dra_pciew_group_limits_12_pciew_group_limits_12_setf(uint32_t pciewgrouplimits12)
{
	ASSERT_ERR((((uint32_t)pciewgrouplimits12 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_12_ADDR, (uint32_t)pciewgrouplimits12 << 0);
}

/**
 * @brief RXM_DRA_PCIEW_GROUP_LIMITS_13 register definition
 *  DRA group limit value register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PCIEW_GROUP_LIMITS_13     0x08080808
 * </pre>
 */
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_13_ADDR        (REG_RXM_BASE_ADDR+0x000003A4)
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_13_OFFSET      0x000003A4
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_13_INDEX       0x000000E9
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_13_RESET       0x08080808

__INLINE uint32_t  rxm_rxm_dra_pciew_group_limits_13_get(void)
{
	return REG_PL_RD(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_13_ADDR);
}

__INLINE void rxm_rxm_dra_pciew_group_limits_13_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_13_ADDR, value);
}

// field definitions
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_13_PCIEW_GROUP_LIMITS_13_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_13_PCIEW_GROUP_LIMITS_13_LSB    0
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_13_PCIEW_GROUP_LIMITS_13_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_13_PCIEW_GROUP_LIMITS_13_RST    0x08080808

__INLINE uint32_t rxm_rxm_dra_pciew_group_limits_13_pciew_group_limits_13_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_13_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_dra_pciew_group_limits_13_pciew_group_limits_13_setf(uint32_t pciewgrouplimits13)
{
	ASSERT_ERR((((uint32_t)pciewgrouplimits13 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_13_ADDR, (uint32_t)pciewgrouplimits13 << 0);
}

/**
 * @brief RXM_DRA_PCIEW_GROUP_LIMITS_14 register definition
 *  DRA group limit value register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PCIEW_GROUP_LIMITS_14     0x08080808
 * </pre>
 */
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_14_ADDR        (REG_RXM_BASE_ADDR+0x000003A8)
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_14_OFFSET      0x000003A8
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_14_INDEX       0x000000EA
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_14_RESET       0x08080808

__INLINE uint32_t  rxm_rxm_dra_pciew_group_limits_14_get(void)
{
	return REG_PL_RD(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_14_ADDR);
}

__INLINE void rxm_rxm_dra_pciew_group_limits_14_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_14_ADDR, value);
}

// field definitions
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_14_PCIEW_GROUP_LIMITS_14_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_14_PCIEW_GROUP_LIMITS_14_LSB    0
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_14_PCIEW_GROUP_LIMITS_14_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_14_PCIEW_GROUP_LIMITS_14_RST    0x08080808

__INLINE uint32_t rxm_rxm_dra_pciew_group_limits_14_pciew_group_limits_14_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_14_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_dra_pciew_group_limits_14_pciew_group_limits_14_setf(uint32_t pciewgrouplimits14)
{
	ASSERT_ERR((((uint32_t)pciewgrouplimits14 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_14_ADDR, (uint32_t)pciewgrouplimits14 << 0);
}

/**
 * @brief RXM_DRA_PCIEW_GROUP_LIMITS_15 register definition
 *  DRA group limit value register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PCIEW_GROUP_LIMITS_15     0x08080808
 * </pre>
 */
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_15_ADDR        (REG_RXM_BASE_ADDR+0x000003AC)
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_15_OFFSET      0x000003AC
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_15_INDEX       0x000000EB
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_15_RESET       0x08080808

__INLINE uint32_t  rxm_rxm_dra_pciew_group_limits_15_get(void)
{
	return REG_PL_RD(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_15_ADDR);
}

__INLINE void rxm_rxm_dra_pciew_group_limits_15_set(uint32_t value)
{
	REG_PL_WR(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_15_ADDR, value);
}

// field definitions
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_15_PCIEW_GROUP_LIMITS_15_MASK    ((uint32_t)0xFFFFFFFF)
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_15_PCIEW_GROUP_LIMITS_15_LSB    0
#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_15_PCIEW_GROUP_LIMITS_15_WIDTH    ((uint32_t)0x00000020)

#define RXM_RXM_DRA_PCIEW_GROUP_LIMITS_15_PCIEW_GROUP_LIMITS_15_RST    0x08080808

__INLINE uint32_t rxm_rxm_dra_pciew_group_limits_15_pciew_group_limits_15_getf(void)
{
	uint32_t localVal = REG_PL_RD(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_15_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rxm_rxm_dra_pciew_group_limits_15_pciew_group_limits_15_setf(uint32_t pciewgrouplimits15)
{
	ASSERT_ERR((((uint32_t)pciewgrouplimits15 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RXM_RXM_DRA_PCIEW_GROUP_LIMITS_15_ADDR, (uint32_t)pciewgrouplimits15 << 0);
}


#undef DBG_FILEID
#endif //_REG_RXM_H_

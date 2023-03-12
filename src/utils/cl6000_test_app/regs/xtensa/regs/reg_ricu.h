#ifndef _REG_RICU_H_
#define _REG_RICU_H_

#include <stdint.h>
#include "_reg_ricu.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define DBG_FILEID __REG_RICU__H__FILEID__

#define REG_RICU_COUNT  77


/**
 * @brief VERSION register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 VERSION                   0xff000031
 * </pre>
 */
#define RICU_VERSION_ADDR        (REG_RICU_BASE_ADDR+0x00000000)
#define RICU_VERSION_OFFSET      0x00000000
#define RICU_VERSION_INDEX       0x00000000
#define RICU_VERSION_RESET       0xFF000031

__INLINE uint32_t  ricu_version_get(void)
{
	return REG_PL_RD(RICU_VERSION_ADDR);
}

// field definitions
#define RICU_VERSION_VERSION_MASK           ((uint32_t)0xFFFFFFFF)
#define RICU_VERSION_VERSION_LSB            0
#define RICU_VERSION_VERSION_WIDTH          ((uint32_t)0x00000020)

#define RICU_VERSION_VERSION_RST            0xff000031

__INLINE uint32_t ricu_version_version_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_VERSION_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief STATIC_CONF_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    30    ARB_ONESHOT_BYPASS        1              
 *    28    BTC_SEL                   0              
 *    27    CLK_SAVE_MODE             0              
 *    26    RF_RST_N_DEFAULT          0              
 *    25    RF_RST_N_REQ              0              
 *    24    FORCE_RSSI_ON             0              
 *    23:20 RSSI_M                    0x2
 *    19:16 RSSI_N                    0x6
 *    03:00 CDB_MODE_MAJ              0x0
 * </pre>
 */
#define RICU_STATIC_CONF_0_ADDR        (REG_RICU_BASE_ADDR+0x00000004)
#define RICU_STATIC_CONF_0_OFFSET      0x00000004
#define RICU_STATIC_CONF_0_INDEX       0x00000001
#define RICU_STATIC_CONF_0_RESET       0x40260000

__INLINE uint32_t  ricu_static_conf_0_get(void)
{
	return REG_PL_RD(RICU_STATIC_CONF_0_ADDR);
}

__INLINE void ricu_static_conf_0_set(uint32_t value)
{
	REG_PL_WR(RICU_STATIC_CONF_0_ADDR, value);
}

// field definitions
#define RICU_STATIC_CONF_0_ARB_ONESHOT_BYPASS_BIT    ((uint32_t)0x40000000)
#define RICU_STATIC_CONF_0_ARB_ONESHOT_BYPASS_POS    30
#define RICU_STATIC_CONF_0_BTC_SEL_BIT      ((uint32_t)0x10000000)
#define RICU_STATIC_CONF_0_BTC_SEL_POS      28
#define RICU_STATIC_CONF_0_CLK_SAVE_MODE_BIT    ((uint32_t)0x08000000)
#define RICU_STATIC_CONF_0_CLK_SAVE_MODE_POS    27
#define RICU_STATIC_CONF_0_RF_RST_N_DEFAULT_BIT    ((uint32_t)0x04000000)
#define RICU_STATIC_CONF_0_RF_RST_N_DEFAULT_POS    26
#define RICU_STATIC_CONF_0_RF_RST_N_REQ_BIT    ((uint32_t)0x02000000)
#define RICU_STATIC_CONF_0_RF_RST_N_REQ_POS    25
#define RICU_STATIC_CONF_0_FORCE_RSSI_ON_BIT    ((uint32_t)0x01000000)
#define RICU_STATIC_CONF_0_FORCE_RSSI_ON_POS    24
#define RICU_STATIC_CONF_0_RSSI_M_MASK      ((uint32_t)0x00F00000)
#define RICU_STATIC_CONF_0_RSSI_M_LSB       20
#define RICU_STATIC_CONF_0_RSSI_M_WIDTH     ((uint32_t)0x00000004)
#define RICU_STATIC_CONF_0_RSSI_N_MASK      ((uint32_t)0x000F0000)
#define RICU_STATIC_CONF_0_RSSI_N_LSB       16
#define RICU_STATIC_CONF_0_RSSI_N_WIDTH     ((uint32_t)0x00000004)
#define RICU_STATIC_CONF_0_CDB_MODE_MAJ_MASK    ((uint32_t)0x0000000F)
#define RICU_STATIC_CONF_0_CDB_MODE_MAJ_LSB    0
#define RICU_STATIC_CONF_0_CDB_MODE_MAJ_WIDTH    ((uint32_t)0x00000004)

#define RICU_STATIC_CONF_0_ARB_ONESHOT_BYPASS_RST    0x1
#define RICU_STATIC_CONF_0_BTC_SEL_RST      0x0
#define RICU_STATIC_CONF_0_CLK_SAVE_MODE_RST    0x0
#define RICU_STATIC_CONF_0_RF_RST_N_DEFAULT_RST    0x0
#define RICU_STATIC_CONF_0_RF_RST_N_REQ_RST    0x0
#define RICU_STATIC_CONF_0_FORCE_RSSI_ON_RST    0x0
#define RICU_STATIC_CONF_0_RSSI_M_RST       0x2
#define RICU_STATIC_CONF_0_RSSI_N_RST       0x6
#define RICU_STATIC_CONF_0_CDB_MODE_MAJ_RST    0x0

__INLINE void ricu_static_conf_0_pack(uint8_t arb_oneshot_bypass, uint8_t btc_sel, uint8_t clk_save_mode, uint8_t rf_rst_n_default, uint8_t rf_rst_n_req, uint8_t force_rssi_on, uint8_t rssi_m, uint8_t rssi_n, uint8_t cdb_mode_maj)
{
	ASSERT_ERR((((uint32_t)arb_oneshot_bypass << 30) & ~((uint32_t)0x40000000)) == 0);
	ASSERT_ERR((((uint32_t)btc_sel << 28) & ~((uint32_t)0x10000000)) == 0);
	ASSERT_ERR((((uint32_t)clk_save_mode << 27) & ~((uint32_t)0x08000000)) == 0);
	ASSERT_ERR((((uint32_t)rf_rst_n_default << 26) & ~((uint32_t)0x04000000)) == 0);
	ASSERT_ERR((((uint32_t)rf_rst_n_req << 25) & ~((uint32_t)0x02000000)) == 0);
	ASSERT_ERR((((uint32_t)force_rssi_on << 24) & ~((uint32_t)0x01000000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_m << 20) & ~((uint32_t)0x00F00000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_n << 16) & ~((uint32_t)0x000F0000)) == 0);
	ASSERT_ERR((((uint32_t)cdb_mode_maj << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RICU_STATIC_CONF_0_ADDR,  ((uint32_t)arb_oneshot_bypass << 30) |((uint32_t)btc_sel << 28) |((uint32_t)clk_save_mode << 27) |((uint32_t)rf_rst_n_default << 26) |((uint32_t)rf_rst_n_req << 25) |((uint32_t)force_rssi_on << 24) |((uint32_t)rssi_m << 20) |((uint32_t)rssi_n << 16) |((uint32_t)cdb_mode_maj << 0));
}

__INLINE void ricu_static_conf_0_unpack(uint8_t* arb_oneshot_bypass, uint8_t* btc_sel, uint8_t* clk_save_mode, uint8_t* rf_rst_n_default, uint8_t* rf_rst_n_req, uint8_t* force_rssi_on, uint8_t* rssi_m, uint8_t* rssi_n, uint8_t* cdb_mode_maj)
{
	uint32_t localVal = REG_PL_RD(RICU_STATIC_CONF_0_ADDR);

	*arb_oneshot_bypass = (localVal & ((uint32_t)0x40000000)) >>  30;
	*btc_sel = (localVal & ((uint32_t)0x10000000)) >>  28;
	*clk_save_mode = (localVal & ((uint32_t)0x08000000)) >>  27;
	*rf_rst_n_default = (localVal & ((uint32_t)0x04000000)) >>  26;
	*rf_rst_n_req = (localVal & ((uint32_t)0x02000000)) >>  25;
	*force_rssi_on = (localVal & ((uint32_t)0x01000000)) >>  24;
	*rssi_m = (localVal & ((uint32_t)0x00F00000)) >>  20;
	*rssi_n = (localVal & ((uint32_t)0x000F0000)) >>  16;
	*cdb_mode_maj = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t ricu_static_conf_0_arb_oneshot_bypass_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_STATIC_CONF_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x40000000)) >> 30);
}
__INLINE void ricu_static_conf_0_arb_oneshot_bypass_setf(uint8_t arboneshotbypass)
{
	ASSERT_ERR((((uint32_t)arboneshotbypass << 30) & ~((uint32_t)0x40000000)) == 0);
	REG_PL_WR(RICU_STATIC_CONF_0_ADDR, (REG_PL_RD(RICU_STATIC_CONF_0_ADDR) & ~((uint32_t)0x40000000)) | ((uint32_t)arboneshotbypass <<30));
}
__INLINE uint8_t ricu_static_conf_0_btc_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_STATIC_CONF_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x10000000)) >> 28);
}
__INLINE void ricu_static_conf_0_btc_sel_setf(uint8_t btcsel)
{
	ASSERT_ERR((((uint32_t)btcsel << 28) & ~((uint32_t)0x10000000)) == 0);
	REG_PL_WR(RICU_STATIC_CONF_0_ADDR, (REG_PL_RD(RICU_STATIC_CONF_0_ADDR) & ~((uint32_t)0x10000000)) | ((uint32_t)btcsel <<28));
}
__INLINE uint8_t ricu_static_conf_0_clk_save_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_STATIC_CONF_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x08000000)) >> 27);
}
__INLINE void ricu_static_conf_0_clk_save_mode_setf(uint8_t clksavemode)
{
	ASSERT_ERR((((uint32_t)clksavemode << 27) & ~((uint32_t)0x08000000)) == 0);
	REG_PL_WR(RICU_STATIC_CONF_0_ADDR, (REG_PL_RD(RICU_STATIC_CONF_0_ADDR) & ~((uint32_t)0x08000000)) | ((uint32_t)clksavemode <<27));
}
__INLINE uint8_t ricu_static_conf_0_rf_rst_n_default_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_STATIC_CONF_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x04000000)) >> 26);
}
__INLINE void ricu_static_conf_0_rf_rst_n_default_setf(uint8_t rfrstndefault)
{
	ASSERT_ERR((((uint32_t)rfrstndefault << 26) & ~((uint32_t)0x04000000)) == 0);
	REG_PL_WR(RICU_STATIC_CONF_0_ADDR, (REG_PL_RD(RICU_STATIC_CONF_0_ADDR) & ~((uint32_t)0x04000000)) | ((uint32_t)rfrstndefault <<26));
}
__INLINE uint8_t ricu_static_conf_0_rf_rst_n_req_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_STATIC_CONF_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x02000000)) >> 25);
}
__INLINE void ricu_static_conf_0_rf_rst_n_req_setf(uint8_t rfrstnreq)
{
	ASSERT_ERR((((uint32_t)rfrstnreq << 25) & ~((uint32_t)0x02000000)) == 0);
	REG_PL_WR(RICU_STATIC_CONF_0_ADDR, (REG_PL_RD(RICU_STATIC_CONF_0_ADDR) & ~((uint32_t)0x02000000)) | ((uint32_t)rfrstnreq <<25));
}
__INLINE uint8_t ricu_static_conf_0_force_rssi_on_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_STATIC_CONF_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01000000)) >> 24);
}
__INLINE void ricu_static_conf_0_force_rssi_on_setf(uint8_t forcerssion)
{
	ASSERT_ERR((((uint32_t)forcerssion << 24) & ~((uint32_t)0x01000000)) == 0);
	REG_PL_WR(RICU_STATIC_CONF_0_ADDR, (REG_PL_RD(RICU_STATIC_CONF_0_ADDR) & ~((uint32_t)0x01000000)) | ((uint32_t)forcerssion <<24));
}
__INLINE uint8_t ricu_static_conf_0_rssi_m_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_STATIC_CONF_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00F00000)) >> 20);
}
__INLINE void ricu_static_conf_0_rssi_m_setf(uint8_t rssim)
{
	ASSERT_ERR((((uint32_t)rssim << 20) & ~((uint32_t)0x00F00000)) == 0);
	REG_PL_WR(RICU_STATIC_CONF_0_ADDR, (REG_PL_RD(RICU_STATIC_CONF_0_ADDR) & ~((uint32_t)0x00F00000)) | ((uint32_t)rssim <<20));
}
__INLINE uint8_t ricu_static_conf_0_rssi_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_STATIC_CONF_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000F0000)) >> 16);
}
__INLINE void ricu_static_conf_0_rssi_n_setf(uint8_t rssin)
{
	ASSERT_ERR((((uint32_t)rssin << 16) & ~((uint32_t)0x000F0000)) == 0);
	REG_PL_WR(RICU_STATIC_CONF_0_ADDR, (REG_PL_RD(RICU_STATIC_CONF_0_ADDR) & ~((uint32_t)0x000F0000)) | ((uint32_t)rssin <<16));
}
__INLINE uint8_t ricu_static_conf_0_cdb_mode_maj_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_STATIC_CONF_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void ricu_static_conf_0_cdb_mode_maj_setf(uint8_t cdbmodemaj)
{
	ASSERT_ERR((((uint32_t)cdbmodemaj << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RICU_STATIC_CONF_0_ADDR, (REG_PL_RD(RICU_STATIC_CONF_0_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)cdbmodemaj <<0));
}

/**
 * @brief DYN_CONF register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    FRC_EVENT_REQ             0              
 * </pre>
 */
#define RICU_DYN_CONF_ADDR        (REG_RICU_BASE_ADDR+0x00000008)
#define RICU_DYN_CONF_OFFSET      0x00000008
#define RICU_DYN_CONF_INDEX       0x00000002
#define RICU_DYN_CONF_RESET       0x00000000

__INLINE uint32_t  ricu_dyn_conf_get(void)
{
	return REG_PL_RD(RICU_DYN_CONF_ADDR);
}

__INLINE void ricu_dyn_conf_set(uint32_t value)
{
	REG_PL_WR(RICU_DYN_CONF_ADDR, value);
}

// field definitions
#define RICU_DYN_CONF_FRC_EVENT_REQ_BIT     ((uint32_t)0x00000001)
#define RICU_DYN_CONF_FRC_EVENT_REQ_POS     0

#define RICU_DYN_CONF_FRC_EVENT_REQ_RST     0x0

__INLINE uint8_t ricu_dyn_conf_frc_event_req_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_DYN_CONF_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void ricu_dyn_conf_frc_event_req_setf(uint8_t frceventreq)
{
	ASSERT_ERR((((uint32_t)frceventreq << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RICU_DYN_CONF_ADDR, (uint32_t)frceventreq << 0);
}

/**
 * @brief AFE_CTL_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    PBIAS_CTRL_EN_LC          0              
 *    30    PBIAS_CTRL_EN             0              
 *    29    LRD_EN_LC                 0              
 *    28    LRD_EN                    0              
 *    27    LOCK_EN_LC                0              
 *    26    LOCK_EN                   1              
 *    25    EN_GPADC_CLK              0              
 *    24    EN_GPADC                  0              
 *    23    FEED_EN_LC                0              
 *    22    FEED_EN                   0              
 *    21    EN_CS                     1              
 *    20    EN_CML_GEN                1              
 *    18    EN_AFE_LDO                1              
 *    17    EN_ADC_CLK                1              
 *    15    AFC_ENB_LC                0              
 *    14    AFC_ENB                   0              
 *    13    CP_MODE_LC                1              
 *    12    BYPASS_LC                 0              
 *    11    BYPASS                    0              
 *    10    AFCINIT_SEL_LC            1              
 *    09    AFCINIT_SEL               1              
 *    08    EN_CLK_MON                0              
 *    07    EN_DAC_CLK                1              
 *    06    EN_CDB_DAC_CLK            0              
 *    05    EN_CDB_ADC_CLK            0              
 *    03    EN_CDB_GEN                0              
 *    02    DACCLK_PHASESEL           0              
 *    01    ADCCLK_PHASESEL           0              
 *    00    CDB_CLK_RESETB            0              
 * </pre>
 */
#define RICU_AFE_CTL_0_ADDR        (REG_RICU_BASE_ADDR+0x00000010)
#define RICU_AFE_CTL_0_OFFSET      0x00000010
#define RICU_AFE_CTL_0_INDEX       0x00000004
#define RICU_AFE_CTL_0_RESET       0x04362680

__INLINE uint32_t  ricu_afe_ctl_0_get(void)
{
	return REG_PL_RD(RICU_AFE_CTL_0_ADDR);
}

__INLINE void ricu_afe_ctl_0_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTL_0_ADDR, value);
}

// field definitions
#define RICU_AFE_CTL_0_PBIAS_CTRL_EN_LC_BIT    ((uint32_t)0x80000000)
#define RICU_AFE_CTL_0_PBIAS_CTRL_EN_LC_POS    31
#define RICU_AFE_CTL_0_PBIAS_CTRL_EN_BIT    ((uint32_t)0x40000000)
#define RICU_AFE_CTL_0_PBIAS_CTRL_EN_POS    30
#define RICU_AFE_CTL_0_LRD_EN_LC_BIT        ((uint32_t)0x20000000)
#define RICU_AFE_CTL_0_LRD_EN_LC_POS        29
#define RICU_AFE_CTL_0_LRD_EN_BIT           ((uint32_t)0x10000000)
#define RICU_AFE_CTL_0_LRD_EN_POS           28
#define RICU_AFE_CTL_0_LOCK_EN_LC_BIT       ((uint32_t)0x08000000)
#define RICU_AFE_CTL_0_LOCK_EN_LC_POS       27
#define RICU_AFE_CTL_0_LOCK_EN_BIT          ((uint32_t)0x04000000)
#define RICU_AFE_CTL_0_LOCK_EN_POS          26
#define RICU_AFE_CTL_0_EN_GPADC_CLK_BIT     ((uint32_t)0x02000000)
#define RICU_AFE_CTL_0_EN_GPADC_CLK_POS     25
#define RICU_AFE_CTL_0_EN_GPADC_BIT         ((uint32_t)0x01000000)
#define RICU_AFE_CTL_0_EN_GPADC_POS         24
#define RICU_AFE_CTL_0_FEED_EN_LC_BIT       ((uint32_t)0x00800000)
#define RICU_AFE_CTL_0_FEED_EN_LC_POS       23
#define RICU_AFE_CTL_0_FEED_EN_BIT          ((uint32_t)0x00400000)
#define RICU_AFE_CTL_0_FEED_EN_POS          22
#define RICU_AFE_CTL_0_EN_CS_BIT            ((uint32_t)0x00200000)
#define RICU_AFE_CTL_0_EN_CS_POS            21
#define RICU_AFE_CTL_0_EN_CML_GEN_BIT       ((uint32_t)0x00100000)
#define RICU_AFE_CTL_0_EN_CML_GEN_POS       20
#define RICU_AFE_CTL_0_EN_AFE_LDO_BIT       ((uint32_t)0x00040000)
#define RICU_AFE_CTL_0_EN_AFE_LDO_POS       18
#define RICU_AFE_CTL_0_EN_ADC_CLK_BIT       ((uint32_t)0x00020000)
#define RICU_AFE_CTL_0_EN_ADC_CLK_POS       17
#define RICU_AFE_CTL_0_AFC_ENB_LC_BIT       ((uint32_t)0x00008000)
#define RICU_AFE_CTL_0_AFC_ENB_LC_POS       15
#define RICU_AFE_CTL_0_AFC_ENB_BIT          ((uint32_t)0x00004000)
#define RICU_AFE_CTL_0_AFC_ENB_POS          14
#define RICU_AFE_CTL_0_CP_MODE_LC_BIT       ((uint32_t)0x00002000)
#define RICU_AFE_CTL_0_CP_MODE_LC_POS       13
#define RICU_AFE_CTL_0_BYPASS_LC_BIT        ((uint32_t)0x00001000)
#define RICU_AFE_CTL_0_BYPASS_LC_POS        12
#define RICU_AFE_CTL_0_BYPASS_BIT           ((uint32_t)0x00000800)
#define RICU_AFE_CTL_0_BYPASS_POS           11
#define RICU_AFE_CTL_0_AFCINIT_SEL_LC_BIT    ((uint32_t)0x00000400)
#define RICU_AFE_CTL_0_AFCINIT_SEL_LC_POS    10
#define RICU_AFE_CTL_0_AFCINIT_SEL_BIT      ((uint32_t)0x00000200)
#define RICU_AFE_CTL_0_AFCINIT_SEL_POS      9
#define RICU_AFE_CTL_0_EN_CLK_MON_BIT       ((uint32_t)0x00000100)
#define RICU_AFE_CTL_0_EN_CLK_MON_POS       8
#define RICU_AFE_CTL_0_EN_DAC_CLK_BIT       ((uint32_t)0x00000080)
#define RICU_AFE_CTL_0_EN_DAC_CLK_POS       7
#define RICU_AFE_CTL_0_EN_CDB_DAC_CLK_BIT    ((uint32_t)0x00000040)
#define RICU_AFE_CTL_0_EN_CDB_DAC_CLK_POS    6
#define RICU_AFE_CTL_0_EN_CDB_ADC_CLK_BIT    ((uint32_t)0x00000020)
#define RICU_AFE_CTL_0_EN_CDB_ADC_CLK_POS    5
#define RICU_AFE_CTL_0_EN_CDB_GEN_BIT       ((uint32_t)0x00000008)
#define RICU_AFE_CTL_0_EN_CDB_GEN_POS       3
#define RICU_AFE_CTL_0_DACCLK_PHASESEL_BIT    ((uint32_t)0x00000004)
#define RICU_AFE_CTL_0_DACCLK_PHASESEL_POS    2
#define RICU_AFE_CTL_0_ADCCLK_PHASESEL_BIT    ((uint32_t)0x00000002)
#define RICU_AFE_CTL_0_ADCCLK_PHASESEL_POS    1
#define RICU_AFE_CTL_0_CDB_CLK_RESETB_BIT    ((uint32_t)0x00000001)
#define RICU_AFE_CTL_0_CDB_CLK_RESETB_POS    0

#define RICU_AFE_CTL_0_PBIAS_CTRL_EN_LC_RST    0x0
#define RICU_AFE_CTL_0_PBIAS_CTRL_EN_RST    0x0
#define RICU_AFE_CTL_0_LRD_EN_LC_RST        0x0
#define RICU_AFE_CTL_0_LRD_EN_RST           0x0
#define RICU_AFE_CTL_0_LOCK_EN_LC_RST       0x0
#define RICU_AFE_CTL_0_LOCK_EN_RST          0x1
#define RICU_AFE_CTL_0_EN_GPADC_CLK_RST     0x0
#define RICU_AFE_CTL_0_EN_GPADC_RST         0x0
#define RICU_AFE_CTL_0_FEED_EN_LC_RST       0x0
#define RICU_AFE_CTL_0_FEED_EN_RST          0x0
#define RICU_AFE_CTL_0_EN_CS_RST            0x1
#define RICU_AFE_CTL_0_EN_CML_GEN_RST       0x1
#define RICU_AFE_CTL_0_EN_AFE_LDO_RST       0x1
#define RICU_AFE_CTL_0_EN_ADC_CLK_RST       0x1
#define RICU_AFE_CTL_0_AFC_ENB_LC_RST       0x0
#define RICU_AFE_CTL_0_AFC_ENB_RST          0x0
#define RICU_AFE_CTL_0_CP_MODE_LC_RST       0x1
#define RICU_AFE_CTL_0_BYPASS_LC_RST        0x0
#define RICU_AFE_CTL_0_BYPASS_RST           0x0
#define RICU_AFE_CTL_0_AFCINIT_SEL_LC_RST    0x1
#define RICU_AFE_CTL_0_AFCINIT_SEL_RST      0x1
#define RICU_AFE_CTL_0_EN_CLK_MON_RST       0x0
#define RICU_AFE_CTL_0_EN_DAC_CLK_RST       0x1
#define RICU_AFE_CTL_0_EN_CDB_DAC_CLK_RST    0x0
#define RICU_AFE_CTL_0_EN_CDB_ADC_CLK_RST    0x0
#define RICU_AFE_CTL_0_EN_CDB_GEN_RST       0x0
#define RICU_AFE_CTL_0_DACCLK_PHASESEL_RST    0x0
#define RICU_AFE_CTL_0_ADCCLK_PHASESEL_RST    0x0
#define RICU_AFE_CTL_0_CDB_CLK_RESETB_RST    0x0

__INLINE void ricu_afe_ctl_0_pack(uint8_t pbias_ctrl_en_lc, uint8_t pbias_ctrl_en, uint8_t lrd_en_lc, uint8_t lrd_en, uint8_t lock_en_lc, uint8_t lock_en, uint8_t en_gpadc_clk, uint8_t en_gpadc, uint8_t feed_en_lc, uint8_t feed_en, uint8_t en_cs, uint8_t en_cml_gen, uint8_t en_afe_ldo, uint8_t en_adc_clk, uint8_t afc_enb_lc, uint8_t afc_enb, uint8_t cp_mode_lc, uint8_t bypass_lc, uint8_t bypass, uint8_t afcinit_sel_lc, uint8_t afcinit_sel, uint8_t en_clk_mon, uint8_t en_dac_clk, uint8_t en_cdb_dac_clk, uint8_t en_cdb_adc_clk, uint8_t en_cdb_gen, uint8_t dacclk_phasesel, uint8_t adcclk_phasesel, uint8_t cdb_clk_resetb)
{
	ASSERT_ERR((((uint32_t)pbias_ctrl_en_lc << 31) & ~((uint32_t)0x80000000)) == 0);
	ASSERT_ERR((((uint32_t)pbias_ctrl_en << 30) & ~((uint32_t)0x40000000)) == 0);
	ASSERT_ERR((((uint32_t)lrd_en_lc << 29) & ~((uint32_t)0x20000000)) == 0);
	ASSERT_ERR((((uint32_t)lrd_en << 28) & ~((uint32_t)0x10000000)) == 0);
	ASSERT_ERR((((uint32_t)lock_en_lc << 27) & ~((uint32_t)0x08000000)) == 0);
	ASSERT_ERR((((uint32_t)lock_en << 26) & ~((uint32_t)0x04000000)) == 0);
	ASSERT_ERR((((uint32_t)en_gpadc_clk << 25) & ~((uint32_t)0x02000000)) == 0);
	ASSERT_ERR((((uint32_t)en_gpadc << 24) & ~((uint32_t)0x01000000)) == 0);
	ASSERT_ERR((((uint32_t)feed_en_lc << 23) & ~((uint32_t)0x00800000)) == 0);
	ASSERT_ERR((((uint32_t)feed_en << 22) & ~((uint32_t)0x00400000)) == 0);
	ASSERT_ERR((((uint32_t)en_cs << 21) & ~((uint32_t)0x00200000)) == 0);
	ASSERT_ERR((((uint32_t)en_cml_gen << 20) & ~((uint32_t)0x00100000)) == 0);
	ASSERT_ERR((((uint32_t)en_afe_ldo << 18) & ~((uint32_t)0x00040000)) == 0);
	ASSERT_ERR((((uint32_t)en_adc_clk << 17) & ~((uint32_t)0x00020000)) == 0);
	ASSERT_ERR((((uint32_t)afc_enb_lc << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)afc_enb << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)cp_mode_lc << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)bypass_lc << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)bypass << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)afcinit_sel_lc << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)afcinit_sel << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)en_clk_mon << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)en_dac_clk << 7) & ~((uint32_t)0x00000080)) == 0);
	ASSERT_ERR((((uint32_t)en_cdb_dac_clk << 6) & ~((uint32_t)0x00000040)) == 0);
	ASSERT_ERR((((uint32_t)en_cdb_adc_clk << 5) & ~((uint32_t)0x00000020)) == 0);
	ASSERT_ERR((((uint32_t)en_cdb_gen << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)dacclk_phasesel << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)adcclk_phasesel << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)cdb_clk_resetb << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RICU_AFE_CTL_0_ADDR,  ((uint32_t)pbias_ctrl_en_lc << 31) |((uint32_t)pbias_ctrl_en << 30) |((uint32_t)lrd_en_lc << 29) |((uint32_t)lrd_en << 28) |((uint32_t)lock_en_lc << 27) |((uint32_t)lock_en << 26) |((uint32_t)en_gpadc_clk << 25) |((uint32_t)en_gpadc << 24) |((uint32_t)feed_en_lc << 23) |((uint32_t)feed_en << 22) |((uint32_t)en_cs << 21) |((uint32_t)en_cml_gen << 20) |((uint32_t)en_afe_ldo << 18) |((uint32_t)en_adc_clk << 17) |((uint32_t)afc_enb_lc << 15) |((uint32_t)afc_enb << 14) |((uint32_t)cp_mode_lc << 13) |((uint32_t)bypass_lc << 12) |((uint32_t)bypass << 11) |((uint32_t)afcinit_sel_lc << 10) |((uint32_t)afcinit_sel << 9) |((uint32_t)en_clk_mon << 8) |((uint32_t)en_dac_clk << 7) |((uint32_t)en_cdb_dac_clk << 6) |((uint32_t)en_cdb_adc_clk << 5) |((uint32_t)en_cdb_gen << 3) |((uint32_t)dacclk_phasesel << 2) |((uint32_t)adcclk_phasesel << 1) |((uint32_t)cdb_clk_resetb << 0));
}

__INLINE void ricu_afe_ctl_0_unpack(uint8_t* pbias_ctrl_en_lc, uint8_t* pbias_ctrl_en, uint8_t* lrd_en_lc, uint8_t* lrd_en, uint8_t* lock_en_lc, uint8_t* lock_en, uint8_t* en_gpadc_clk, uint8_t* en_gpadc, uint8_t* feed_en_lc, uint8_t* feed_en, uint8_t* en_cs, uint8_t* en_cml_gen, uint8_t* en_afe_ldo, uint8_t* en_adc_clk, uint8_t* afc_enb_lc, uint8_t* afc_enb, uint8_t* cp_mode_lc, uint8_t* bypass_lc, uint8_t* bypass, uint8_t* afcinit_sel_lc, uint8_t* afcinit_sel, uint8_t* en_clk_mon, uint8_t* en_dac_clk, uint8_t* en_cdb_dac_clk, uint8_t* en_cdb_adc_clk, uint8_t* en_cdb_gen, uint8_t* dacclk_phasesel, uint8_t* adcclk_phasesel, uint8_t* cdb_clk_resetb)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_0_ADDR);

	*pbias_ctrl_en_lc = (localVal & ((uint32_t)0x80000000)) >>  31;
	*pbias_ctrl_en = (localVal & ((uint32_t)0x40000000)) >>  30;
	*lrd_en_lc = (localVal & ((uint32_t)0x20000000)) >>  29;
	*lrd_en = (localVal & ((uint32_t)0x10000000)) >>  28;
	*lock_en_lc = (localVal & ((uint32_t)0x08000000)) >>  27;
	*lock_en = (localVal & ((uint32_t)0x04000000)) >>  26;
	*en_gpadc_clk = (localVal & ((uint32_t)0x02000000)) >>  25;
	*en_gpadc = (localVal & ((uint32_t)0x01000000)) >>  24;
	*feed_en_lc = (localVal & ((uint32_t)0x00800000)) >>  23;
	*feed_en = (localVal & ((uint32_t)0x00400000)) >>  22;
	*en_cs = (localVal & ((uint32_t)0x00200000)) >>  21;
	*en_cml_gen = (localVal & ((uint32_t)0x00100000)) >>  20;
	*en_afe_ldo = (localVal & ((uint32_t)0x00040000)) >>  18;
	*en_adc_clk = (localVal & ((uint32_t)0x00020000)) >>  17;
	*afc_enb_lc = (localVal & ((uint32_t)0x00008000)) >>  15;
	*afc_enb = (localVal & ((uint32_t)0x00004000)) >>  14;
	*cp_mode_lc = (localVal & ((uint32_t)0x00002000)) >>  13;
	*bypass_lc = (localVal & ((uint32_t)0x00001000)) >>  12;
	*bypass = (localVal & ((uint32_t)0x00000800)) >>  11;
	*afcinit_sel_lc = (localVal & ((uint32_t)0x00000400)) >>  10;
	*afcinit_sel = (localVal & ((uint32_t)0x00000200)) >>  9;
	*en_clk_mon = (localVal & ((uint32_t)0x00000100)) >>  8;
	*en_dac_clk = (localVal & ((uint32_t)0x00000080)) >>  7;
	*en_cdb_dac_clk = (localVal & ((uint32_t)0x00000040)) >>  6;
	*en_cdb_adc_clk = (localVal & ((uint32_t)0x00000020)) >>  5;
	*en_cdb_gen = (localVal & ((uint32_t)0x00000008)) >>  3;
	*dacclk_phasesel = (localVal & ((uint32_t)0x00000004)) >>  2;
	*adcclk_phasesel = (localVal & ((uint32_t)0x00000002)) >>  1;
	*cdb_clk_resetb = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t ricu_afe_ctl_0_pbias_ctrl_en_lc_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE void ricu_afe_ctl_0_pbias_ctrl_en_lc_setf(uint8_t pbiasctrlenlc)
{
	ASSERT_ERR((((uint32_t)pbiasctrlenlc << 31) & ~((uint32_t)0x80000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_0_ADDR, (REG_PL_RD(RICU_AFE_CTL_0_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)pbiasctrlenlc <<31));
}
__INLINE uint8_t ricu_afe_ctl_0_pbias_ctrl_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x40000000)) >> 30);
}
__INLINE void ricu_afe_ctl_0_pbias_ctrl_en_setf(uint8_t pbiasctrlen)
{
	ASSERT_ERR((((uint32_t)pbiasctrlen << 30) & ~((uint32_t)0x40000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_0_ADDR, (REG_PL_RD(RICU_AFE_CTL_0_ADDR) & ~((uint32_t)0x40000000)) | ((uint32_t)pbiasctrlen <<30));
}
__INLINE uint8_t ricu_afe_ctl_0_lrd_en_lc_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x20000000)) >> 29);
}
__INLINE void ricu_afe_ctl_0_lrd_en_lc_setf(uint8_t lrdenlc)
{
	ASSERT_ERR((((uint32_t)lrdenlc << 29) & ~((uint32_t)0x20000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_0_ADDR, (REG_PL_RD(RICU_AFE_CTL_0_ADDR) & ~((uint32_t)0x20000000)) | ((uint32_t)lrdenlc <<29));
}
__INLINE uint8_t ricu_afe_ctl_0_lrd_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x10000000)) >> 28);
}
__INLINE void ricu_afe_ctl_0_lrd_en_setf(uint8_t lrden)
{
	ASSERT_ERR((((uint32_t)lrden << 28) & ~((uint32_t)0x10000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_0_ADDR, (REG_PL_RD(RICU_AFE_CTL_0_ADDR) & ~((uint32_t)0x10000000)) | ((uint32_t)lrden <<28));
}
__INLINE uint8_t ricu_afe_ctl_0_lock_en_lc_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x08000000)) >> 27);
}
__INLINE void ricu_afe_ctl_0_lock_en_lc_setf(uint8_t lockenlc)
{
	ASSERT_ERR((((uint32_t)lockenlc << 27) & ~((uint32_t)0x08000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_0_ADDR, (REG_PL_RD(RICU_AFE_CTL_0_ADDR) & ~((uint32_t)0x08000000)) | ((uint32_t)lockenlc <<27));
}
__INLINE uint8_t ricu_afe_ctl_0_lock_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x04000000)) >> 26);
}
__INLINE void ricu_afe_ctl_0_lock_en_setf(uint8_t locken)
{
	ASSERT_ERR((((uint32_t)locken << 26) & ~((uint32_t)0x04000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_0_ADDR, (REG_PL_RD(RICU_AFE_CTL_0_ADDR) & ~((uint32_t)0x04000000)) | ((uint32_t)locken <<26));
}
__INLINE uint8_t ricu_afe_ctl_0_en_gpadc_clk_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x02000000)) >> 25);
}
__INLINE void ricu_afe_ctl_0_en_gpadc_clk_setf(uint8_t engpadcclk)
{
	ASSERT_ERR((((uint32_t)engpadcclk << 25) & ~((uint32_t)0x02000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_0_ADDR, (REG_PL_RD(RICU_AFE_CTL_0_ADDR) & ~((uint32_t)0x02000000)) | ((uint32_t)engpadcclk <<25));
}
__INLINE uint8_t ricu_afe_ctl_0_en_gpadc_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01000000)) >> 24);
}
__INLINE void ricu_afe_ctl_0_en_gpadc_setf(uint8_t engpadc)
{
	ASSERT_ERR((((uint32_t)engpadc << 24) & ~((uint32_t)0x01000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_0_ADDR, (REG_PL_RD(RICU_AFE_CTL_0_ADDR) & ~((uint32_t)0x01000000)) | ((uint32_t)engpadc <<24));
}
__INLINE uint8_t ricu_afe_ctl_0_feed_en_lc_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00800000)) >> 23);
}
__INLINE void ricu_afe_ctl_0_feed_en_lc_setf(uint8_t feedenlc)
{
	ASSERT_ERR((((uint32_t)feedenlc << 23) & ~((uint32_t)0x00800000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_0_ADDR, (REG_PL_RD(RICU_AFE_CTL_0_ADDR) & ~((uint32_t)0x00800000)) | ((uint32_t)feedenlc <<23));
}
__INLINE uint8_t ricu_afe_ctl_0_feed_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00400000)) >> 22);
}
__INLINE void ricu_afe_ctl_0_feed_en_setf(uint8_t feeden)
{
	ASSERT_ERR((((uint32_t)feeden << 22) & ~((uint32_t)0x00400000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_0_ADDR, (REG_PL_RD(RICU_AFE_CTL_0_ADDR) & ~((uint32_t)0x00400000)) | ((uint32_t)feeden <<22));
}
__INLINE uint8_t ricu_afe_ctl_0_en_cs_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00200000)) >> 21);
}
__INLINE uint8_t ricu_afe_ctl_0_en_cml_gen_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00100000)) >> 20);
}
__INLINE uint8_t ricu_afe_ctl_0_en_afe_ldo_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00040000)) >> 18);
}
__INLINE uint8_t ricu_afe_ctl_0_en_adc_clk_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00020000)) >> 17);
}
__INLINE void ricu_afe_ctl_0_en_adc_clk_setf(uint8_t enadcclk)
{
	ASSERT_ERR((((uint32_t)enadcclk << 17) & ~((uint32_t)0x00020000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_0_ADDR, (REG_PL_RD(RICU_AFE_CTL_0_ADDR) & ~((uint32_t)0x00020000)) | ((uint32_t)enadcclk <<17));
}
__INLINE uint8_t ricu_afe_ctl_0_afc_enb_lc_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void ricu_afe_ctl_0_afc_enb_lc_setf(uint8_t afcenblc)
{
	ASSERT_ERR((((uint32_t)afcenblc << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_0_ADDR, (REG_PL_RD(RICU_AFE_CTL_0_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)afcenblc <<15));
}
__INLINE uint8_t ricu_afe_ctl_0_afc_enb_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void ricu_afe_ctl_0_afc_enb_setf(uint8_t afcenb)
{
	ASSERT_ERR((((uint32_t)afcenb << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_0_ADDR, (REG_PL_RD(RICU_AFE_CTL_0_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)afcenb <<14));
}
__INLINE uint8_t ricu_afe_ctl_0_cp_mode_lc_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void ricu_afe_ctl_0_cp_mode_lc_setf(uint8_t cpmodelc)
{
	ASSERT_ERR((((uint32_t)cpmodelc << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_0_ADDR, (REG_PL_RD(RICU_AFE_CTL_0_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)cpmodelc <<13));
}
__INLINE uint8_t ricu_afe_ctl_0_bypass_lc_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void ricu_afe_ctl_0_bypass_lc_setf(uint8_t bypasslc)
{
	ASSERT_ERR((((uint32_t)bypasslc << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_0_ADDR, (REG_PL_RD(RICU_AFE_CTL_0_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)bypasslc <<12));
}
__INLINE uint8_t ricu_afe_ctl_0_bypass_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void ricu_afe_ctl_0_bypass_setf(uint8_t bypass)
{
	ASSERT_ERR((((uint32_t)bypass << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(RICU_AFE_CTL_0_ADDR, (REG_PL_RD(RICU_AFE_CTL_0_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)bypass <<11));
}
__INLINE uint8_t ricu_afe_ctl_0_afcinit_sel_lc_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void ricu_afe_ctl_0_afcinit_sel_lc_setf(uint8_t afcinitsellc)
{
	ASSERT_ERR((((uint32_t)afcinitsellc << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(RICU_AFE_CTL_0_ADDR, (REG_PL_RD(RICU_AFE_CTL_0_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)afcinitsellc <<10));
}
__INLINE uint8_t ricu_afe_ctl_0_afcinit_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void ricu_afe_ctl_0_afcinit_sel_setf(uint8_t afcinitsel)
{
	ASSERT_ERR((((uint32_t)afcinitsel << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(RICU_AFE_CTL_0_ADDR, (REG_PL_RD(RICU_AFE_CTL_0_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)afcinitsel <<9));
}
__INLINE uint8_t ricu_afe_ctl_0_en_clk_mon_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void ricu_afe_ctl_0_en_clk_mon_setf(uint8_t enclkmon)
{
	ASSERT_ERR((((uint32_t)enclkmon << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(RICU_AFE_CTL_0_ADDR, (REG_PL_RD(RICU_AFE_CTL_0_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)enclkmon <<8));
}
__INLINE uint8_t ricu_afe_ctl_0_en_dac_clk_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE void ricu_afe_ctl_0_en_dac_clk_setf(uint8_t endacclk)
{
	ASSERT_ERR((((uint32_t)endacclk << 7) & ~((uint32_t)0x00000080)) == 0);
	REG_PL_WR(RICU_AFE_CTL_0_ADDR, (REG_PL_RD(RICU_AFE_CTL_0_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)endacclk <<7));
}
__INLINE uint8_t ricu_afe_ctl_0_en_cdb_dac_clk_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE void ricu_afe_ctl_0_en_cdb_dac_clk_setf(uint8_t encdbdacclk)
{
	ASSERT_ERR((((uint32_t)encdbdacclk << 6) & ~((uint32_t)0x00000040)) == 0);
	REG_PL_WR(RICU_AFE_CTL_0_ADDR, (REG_PL_RD(RICU_AFE_CTL_0_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)encdbdacclk <<6));
}
__INLINE uint8_t ricu_afe_ctl_0_en_cdb_adc_clk_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE void ricu_afe_ctl_0_en_cdb_adc_clk_setf(uint8_t encdbadcclk)
{
	ASSERT_ERR((((uint32_t)encdbadcclk << 5) & ~((uint32_t)0x00000020)) == 0);
	REG_PL_WR(RICU_AFE_CTL_0_ADDR, (REG_PL_RD(RICU_AFE_CTL_0_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)encdbadcclk <<5));
}
__INLINE uint8_t ricu_afe_ctl_0_en_cdb_gen_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void ricu_afe_ctl_0_en_cdb_gen_setf(uint8_t encdbgen)
{
	ASSERT_ERR((((uint32_t)encdbgen << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(RICU_AFE_CTL_0_ADDR, (REG_PL_RD(RICU_AFE_CTL_0_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)encdbgen <<3));
}
__INLINE uint8_t ricu_afe_ctl_0_dacclk_phasesel_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void ricu_afe_ctl_0_dacclk_phasesel_setf(uint8_t dacclkphasesel)
{
	ASSERT_ERR((((uint32_t)dacclkphasesel << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(RICU_AFE_CTL_0_ADDR, (REG_PL_RD(RICU_AFE_CTL_0_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)dacclkphasesel <<2));
}
__INLINE uint8_t ricu_afe_ctl_0_adcclk_phasesel_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void ricu_afe_ctl_0_adcclk_phasesel_setf(uint8_t adcclkphasesel)
{
	ASSERT_ERR((((uint32_t)adcclkphasesel << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(RICU_AFE_CTL_0_ADDR, (REG_PL_RD(RICU_AFE_CTL_0_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)adcclkphasesel <<1));
}
__INLINE uint8_t ricu_afe_ctl_0_cdb_clk_resetb_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void ricu_afe_ctl_0_cdb_clk_resetb_setf(uint8_t cdbclkresetb)
{
	ASSERT_ERR((((uint32_t)cdbclkresetb << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RICU_AFE_CTL_0_ADDR, (REG_PL_RD(RICU_AFE_CTL_0_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)cdbclkresetb <<0));
}

/**
 * @brief AFE_CTL_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    14    VCO_BOOST                 0              
 *    13    SYS_ADCCLK_SEL            0              
 *    12    SOC_PHASE_SEL             1              
 *    11    SOC_CLK_SEL               1              
 *    10    RESETB_LC                 0              
 *    09    RESETB                    1              
 *    08    PBIAS_CTRL_LC             0              
 *    07    PBIAS_CTRL                0              
 *    06    GP_CLK_PHASESEL           0              
 *    05    FSEL_LC                   0              
 *    04    FSEL                      0              
 *    03    FOUT_MASK_LC              0              
 *    02    FOUT_MASK                 0              
 *    01    EXTCLK_SEL                0              
 *    00    EN_PLL_LDO                0              
 * </pre>
 */
#define RICU_AFE_CTL_1_ADDR        (REG_RICU_BASE_ADDR+0x00000014)
#define RICU_AFE_CTL_1_OFFSET      0x00000014
#define RICU_AFE_CTL_1_INDEX       0x00000005
#define RICU_AFE_CTL_1_RESET       0x00001A00

__INLINE uint32_t  ricu_afe_ctl_1_get(void)
{
	return REG_PL_RD(RICU_AFE_CTL_1_ADDR);
}

__INLINE void ricu_afe_ctl_1_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTL_1_ADDR, value);
}

// field definitions
#define RICU_AFE_CTL_1_VCO_BOOST_BIT        ((uint32_t)0x00004000)
#define RICU_AFE_CTL_1_VCO_BOOST_POS        14
#define RICU_AFE_CTL_1_SYS_ADCCLK_SEL_BIT    ((uint32_t)0x00002000)
#define RICU_AFE_CTL_1_SYS_ADCCLK_SEL_POS    13
#define RICU_AFE_CTL_1_SOC_PHASE_SEL_BIT    ((uint32_t)0x00001000)
#define RICU_AFE_CTL_1_SOC_PHASE_SEL_POS    12
#define RICU_AFE_CTL_1_SOC_CLK_SEL_BIT      ((uint32_t)0x00000800)
#define RICU_AFE_CTL_1_SOC_CLK_SEL_POS      11
#define RICU_AFE_CTL_1_RESETB_LC_BIT        ((uint32_t)0x00000400)
#define RICU_AFE_CTL_1_RESETB_LC_POS        10
#define RICU_AFE_CTL_1_RESETB_BIT           ((uint32_t)0x00000200)
#define RICU_AFE_CTL_1_RESETB_POS           9
#define RICU_AFE_CTL_1_PBIAS_CTRL_LC_BIT    ((uint32_t)0x00000100)
#define RICU_AFE_CTL_1_PBIAS_CTRL_LC_POS    8
#define RICU_AFE_CTL_1_PBIAS_CTRL_BIT       ((uint32_t)0x00000080)
#define RICU_AFE_CTL_1_PBIAS_CTRL_POS       7
#define RICU_AFE_CTL_1_GP_CLK_PHASESEL_BIT    ((uint32_t)0x00000040)
#define RICU_AFE_CTL_1_GP_CLK_PHASESEL_POS    6
#define RICU_AFE_CTL_1_FSEL_LC_BIT          ((uint32_t)0x00000020)
#define RICU_AFE_CTL_1_FSEL_LC_POS          5
#define RICU_AFE_CTL_1_FSEL_BIT             ((uint32_t)0x00000010)
#define RICU_AFE_CTL_1_FSEL_POS             4
#define RICU_AFE_CTL_1_FOUT_MASK_LC_BIT     ((uint32_t)0x00000008)
#define RICU_AFE_CTL_1_FOUT_MASK_LC_POS     3
#define RICU_AFE_CTL_1_FOUT_MASK_BIT        ((uint32_t)0x00000004)
#define RICU_AFE_CTL_1_FOUT_MASK_POS        2
#define RICU_AFE_CTL_1_EXTCLK_SEL_BIT       ((uint32_t)0x00000002)
#define RICU_AFE_CTL_1_EXTCLK_SEL_POS       1
#define RICU_AFE_CTL_1_EN_PLL_LDO_BIT       ((uint32_t)0x00000001)
#define RICU_AFE_CTL_1_EN_PLL_LDO_POS       0

#define RICU_AFE_CTL_1_VCO_BOOST_RST        0x0
#define RICU_AFE_CTL_1_SYS_ADCCLK_SEL_RST    0x0
#define RICU_AFE_CTL_1_SOC_PHASE_SEL_RST    0x1
#define RICU_AFE_CTL_1_SOC_CLK_SEL_RST      0x1
#define RICU_AFE_CTL_1_RESETB_LC_RST        0x0
#define RICU_AFE_CTL_1_RESETB_RST           0x1
#define RICU_AFE_CTL_1_PBIAS_CTRL_LC_RST    0x0
#define RICU_AFE_CTL_1_PBIAS_CTRL_RST       0x0
#define RICU_AFE_CTL_1_GP_CLK_PHASESEL_RST    0x0
#define RICU_AFE_CTL_1_FSEL_LC_RST          0x0
#define RICU_AFE_CTL_1_FSEL_RST             0x0
#define RICU_AFE_CTL_1_FOUT_MASK_LC_RST     0x0
#define RICU_AFE_CTL_1_FOUT_MASK_RST        0x0
#define RICU_AFE_CTL_1_EXTCLK_SEL_RST       0x0
#define RICU_AFE_CTL_1_EN_PLL_LDO_RST       0x0

__INLINE void ricu_afe_ctl_1_pack(uint8_t vco_boost, uint8_t sys_adcclk_sel, uint8_t soc_phase_sel, uint8_t soc_clk_sel, uint8_t resetb_lc, uint8_t resetb, uint8_t pbias_ctrl_lc, uint8_t pbias_ctrl, uint8_t gp_clk_phasesel, uint8_t fsel_lc, uint8_t fsel, uint8_t fout_mask_lc, uint8_t fout_mask, uint8_t extclk_sel, uint8_t en_pll_ldo)
{
	ASSERT_ERR((((uint32_t)vco_boost << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)sys_adcclk_sel << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)soc_phase_sel << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)soc_clk_sel << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)resetb_lc << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)resetb << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)pbias_ctrl_lc << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)pbias_ctrl << 7) & ~((uint32_t)0x00000080)) == 0);
	ASSERT_ERR((((uint32_t)gp_clk_phasesel << 6) & ~((uint32_t)0x00000040)) == 0);
	ASSERT_ERR((((uint32_t)fsel_lc << 5) & ~((uint32_t)0x00000020)) == 0);
	ASSERT_ERR((((uint32_t)fsel << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)fout_mask_lc << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)fout_mask << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)extclk_sel << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)en_pll_ldo << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RICU_AFE_CTL_1_ADDR,  ((uint32_t)vco_boost << 14) |((uint32_t)sys_adcclk_sel << 13) |((uint32_t)soc_phase_sel << 12) |((uint32_t)soc_clk_sel << 11) |((uint32_t)resetb_lc << 10) |((uint32_t)resetb << 9) |((uint32_t)pbias_ctrl_lc << 8) |((uint32_t)pbias_ctrl << 7) |((uint32_t)gp_clk_phasesel << 6) |((uint32_t)fsel_lc << 5) |((uint32_t)fsel << 4) |((uint32_t)fout_mask_lc << 3) |((uint32_t)fout_mask << 2) |((uint32_t)extclk_sel << 1) |((uint32_t)en_pll_ldo << 0));
}

__INLINE void ricu_afe_ctl_1_unpack(uint8_t* vco_boost, uint8_t* sys_adcclk_sel, uint8_t* soc_phase_sel, uint8_t* soc_clk_sel, uint8_t* resetb_lc, uint8_t* resetb, uint8_t* pbias_ctrl_lc, uint8_t* pbias_ctrl, uint8_t* gp_clk_phasesel, uint8_t* fsel_lc, uint8_t* fsel, uint8_t* fout_mask_lc, uint8_t* fout_mask, uint8_t* extclk_sel, uint8_t* en_pll_ldo)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_1_ADDR);

	*vco_boost = (localVal & ((uint32_t)0x00004000)) >>  14;
	*sys_adcclk_sel = (localVal & ((uint32_t)0x00002000)) >>  13;
	*soc_phase_sel = (localVal & ((uint32_t)0x00001000)) >>  12;
	*soc_clk_sel = (localVal & ((uint32_t)0x00000800)) >>  11;
	*resetb_lc = (localVal & ((uint32_t)0x00000400)) >>  10;
	*resetb = (localVal & ((uint32_t)0x00000200)) >>  9;
	*pbias_ctrl_lc = (localVal & ((uint32_t)0x00000100)) >>  8;
	*pbias_ctrl = (localVal & ((uint32_t)0x00000080)) >>  7;
	*gp_clk_phasesel = (localVal & ((uint32_t)0x00000040)) >>  6;
	*fsel_lc = (localVal & ((uint32_t)0x00000020)) >>  5;
	*fsel = (localVal & ((uint32_t)0x00000010)) >>  4;
	*fout_mask_lc = (localVal & ((uint32_t)0x00000008)) >>  3;
	*fout_mask = (localVal & ((uint32_t)0x00000004)) >>  2;
	*extclk_sel = (localVal & ((uint32_t)0x00000002)) >>  1;
	*en_pll_ldo = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t ricu_afe_ctl_1_vco_boost_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void ricu_afe_ctl_1_vco_boost_setf(uint8_t vcoboost)
{
	ASSERT_ERR((((uint32_t)vcoboost << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_1_ADDR, (REG_PL_RD(RICU_AFE_CTL_1_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)vcoboost <<14));
}
__INLINE uint8_t ricu_afe_ctl_1_sys_adcclk_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void ricu_afe_ctl_1_sys_adcclk_sel_setf(uint8_t sysadcclksel)
{
	ASSERT_ERR((((uint32_t)sysadcclksel << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_1_ADDR, (REG_PL_RD(RICU_AFE_CTL_1_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)sysadcclksel <<13));
}
__INLINE uint8_t ricu_afe_ctl_1_soc_phase_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void ricu_afe_ctl_1_soc_phase_sel_setf(uint8_t socphasesel)
{
	ASSERT_ERR((((uint32_t)socphasesel << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_1_ADDR, (REG_PL_RD(RICU_AFE_CTL_1_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)socphasesel <<12));
}
__INLINE uint8_t ricu_afe_ctl_1_soc_clk_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void ricu_afe_ctl_1_soc_clk_sel_setf(uint8_t socclksel)
{
	ASSERT_ERR((((uint32_t)socclksel << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(RICU_AFE_CTL_1_ADDR, (REG_PL_RD(RICU_AFE_CTL_1_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)socclksel <<11));
}
__INLINE uint8_t ricu_afe_ctl_1_resetb_lc_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void ricu_afe_ctl_1_resetb_lc_setf(uint8_t resetblc)
{
	ASSERT_ERR((((uint32_t)resetblc << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(RICU_AFE_CTL_1_ADDR, (REG_PL_RD(RICU_AFE_CTL_1_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)resetblc <<10));
}
__INLINE uint8_t ricu_afe_ctl_1_resetb_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void ricu_afe_ctl_1_resetb_setf(uint8_t resetb)
{
	ASSERT_ERR((((uint32_t)resetb << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(RICU_AFE_CTL_1_ADDR, (REG_PL_RD(RICU_AFE_CTL_1_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)resetb <<9));
}
__INLINE uint8_t ricu_afe_ctl_1_pbias_ctrl_lc_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void ricu_afe_ctl_1_pbias_ctrl_lc_setf(uint8_t pbiasctrllc)
{
	ASSERT_ERR((((uint32_t)pbiasctrllc << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(RICU_AFE_CTL_1_ADDR, (REG_PL_RD(RICU_AFE_CTL_1_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)pbiasctrllc <<8));
}
__INLINE uint8_t ricu_afe_ctl_1_pbias_ctrl_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE void ricu_afe_ctl_1_pbias_ctrl_setf(uint8_t pbiasctrl)
{
	ASSERT_ERR((((uint32_t)pbiasctrl << 7) & ~((uint32_t)0x00000080)) == 0);
	REG_PL_WR(RICU_AFE_CTL_1_ADDR, (REG_PL_RD(RICU_AFE_CTL_1_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)pbiasctrl <<7));
}
__INLINE uint8_t ricu_afe_ctl_1_gp_clk_phasesel_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE void ricu_afe_ctl_1_gp_clk_phasesel_setf(uint8_t gpclkphasesel)
{
	ASSERT_ERR((((uint32_t)gpclkphasesel << 6) & ~((uint32_t)0x00000040)) == 0);
	REG_PL_WR(RICU_AFE_CTL_1_ADDR, (REG_PL_RD(RICU_AFE_CTL_1_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)gpclkphasesel <<6));
}
__INLINE uint8_t ricu_afe_ctl_1_fsel_lc_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE void ricu_afe_ctl_1_fsel_lc_setf(uint8_t fsellc)
{
	ASSERT_ERR((((uint32_t)fsellc << 5) & ~((uint32_t)0x00000020)) == 0);
	REG_PL_WR(RICU_AFE_CTL_1_ADDR, (REG_PL_RD(RICU_AFE_CTL_1_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)fsellc <<5));
}
__INLINE uint8_t ricu_afe_ctl_1_fsel_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void ricu_afe_ctl_1_fsel_setf(uint8_t fsel)
{
	ASSERT_ERR((((uint32_t)fsel << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(RICU_AFE_CTL_1_ADDR, (REG_PL_RD(RICU_AFE_CTL_1_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)fsel <<4));
}
__INLINE uint8_t ricu_afe_ctl_1_fout_mask_lc_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void ricu_afe_ctl_1_fout_mask_lc_setf(uint8_t foutmasklc)
{
	ASSERT_ERR((((uint32_t)foutmasklc << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(RICU_AFE_CTL_1_ADDR, (REG_PL_RD(RICU_AFE_CTL_1_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)foutmasklc <<3));
}
__INLINE uint8_t ricu_afe_ctl_1_fout_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void ricu_afe_ctl_1_fout_mask_setf(uint8_t foutmask)
{
	ASSERT_ERR((((uint32_t)foutmask << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(RICU_AFE_CTL_1_ADDR, (REG_PL_RD(RICU_AFE_CTL_1_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)foutmask <<2));
}
__INLINE uint8_t ricu_afe_ctl_1_extclk_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void ricu_afe_ctl_1_extclk_sel_setf(uint8_t extclksel)
{
	ASSERT_ERR((((uint32_t)extclksel << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(RICU_AFE_CTL_1_ADDR, (REG_PL_RD(RICU_AFE_CTL_1_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)extclksel <<1));
}
__INLINE uint8_t ricu_afe_ctl_1_en_pll_ldo_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void ricu_afe_ctl_1_en_pll_ldo_setf(uint8_t enpllldo)
{
	ASSERT_ERR((((uint32_t)enpllldo << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RICU_AFE_CTL_1_ADDR, (REG_PL_RD(RICU_AFE_CTL_1_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)enpllldo <<0));
}

/**
 * @brief AFE_CTL_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:22 LOCK_CON_REV_LC           0x0
 *    21:20 LOCK_CON_REV              0x0
 *    19:18 LOCK_CON_OUT_LC           0x3
 *    17:16 LOCK_CON_OUT              0x3
 *    15:14 LOCK_CON_IN_LC            0x3
 *    13:12 LOCK_CON_IN               0x3
 *    11:10 LOCK_CON_DLY_LC           0x3
 *    09:08 LOCK_CON_DLY              0x3
 *    07:06 ICP                       0x1
 *    03:02 CTRL_IB                   0x2
 *    01:00 CLK_MON_SEL               0x0
 * </pre>
 */
#define RICU_AFE_CTL_2_ADDR        (REG_RICU_BASE_ADDR+0x00000018)
#define RICU_AFE_CTL_2_OFFSET      0x00000018
#define RICU_AFE_CTL_2_INDEX       0x00000006
#define RICU_AFE_CTL_2_RESET       0x000FFF48

__INLINE uint32_t  ricu_afe_ctl_2_get(void)
{
	return REG_PL_RD(RICU_AFE_CTL_2_ADDR);
}

__INLINE void ricu_afe_ctl_2_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTL_2_ADDR, value);
}

// field definitions
#define RICU_AFE_CTL_2_LOCK_CON_REV_LC_MASK    ((uint32_t)0x00C00000)
#define RICU_AFE_CTL_2_LOCK_CON_REV_LC_LSB    22
#define RICU_AFE_CTL_2_LOCK_CON_REV_LC_WIDTH    ((uint32_t)0x00000002)
#define RICU_AFE_CTL_2_LOCK_CON_REV_MASK    ((uint32_t)0x00300000)
#define RICU_AFE_CTL_2_LOCK_CON_REV_LSB     20
#define RICU_AFE_CTL_2_LOCK_CON_REV_WIDTH    ((uint32_t)0x00000002)
#define RICU_AFE_CTL_2_LOCK_CON_OUT_LC_MASK    ((uint32_t)0x000C0000)
#define RICU_AFE_CTL_2_LOCK_CON_OUT_LC_LSB    18
#define RICU_AFE_CTL_2_LOCK_CON_OUT_LC_WIDTH    ((uint32_t)0x00000002)
#define RICU_AFE_CTL_2_LOCK_CON_OUT_MASK    ((uint32_t)0x00030000)
#define RICU_AFE_CTL_2_LOCK_CON_OUT_LSB     16
#define RICU_AFE_CTL_2_LOCK_CON_OUT_WIDTH    ((uint32_t)0x00000002)
#define RICU_AFE_CTL_2_LOCK_CON_IN_LC_MASK    ((uint32_t)0x0000C000)
#define RICU_AFE_CTL_2_LOCK_CON_IN_LC_LSB    14
#define RICU_AFE_CTL_2_LOCK_CON_IN_LC_WIDTH    ((uint32_t)0x00000002)
#define RICU_AFE_CTL_2_LOCK_CON_IN_MASK     ((uint32_t)0x00003000)
#define RICU_AFE_CTL_2_LOCK_CON_IN_LSB      12
#define RICU_AFE_CTL_2_LOCK_CON_IN_WIDTH    ((uint32_t)0x00000002)
#define RICU_AFE_CTL_2_LOCK_CON_DLY_LC_MASK    ((uint32_t)0x00000C00)
#define RICU_AFE_CTL_2_LOCK_CON_DLY_LC_LSB    10
#define RICU_AFE_CTL_2_LOCK_CON_DLY_LC_WIDTH    ((uint32_t)0x00000002)
#define RICU_AFE_CTL_2_LOCK_CON_DLY_MASK    ((uint32_t)0x00000300)
#define RICU_AFE_CTL_2_LOCK_CON_DLY_LSB     8
#define RICU_AFE_CTL_2_LOCK_CON_DLY_WIDTH    ((uint32_t)0x00000002)
#define RICU_AFE_CTL_2_ICP_MASK             ((uint32_t)0x000000C0)
#define RICU_AFE_CTL_2_ICP_LSB              6
#define RICU_AFE_CTL_2_ICP_WIDTH            ((uint32_t)0x00000002)
#define RICU_AFE_CTL_2_CTRL_IB_MASK         ((uint32_t)0x0000000C)
#define RICU_AFE_CTL_2_CTRL_IB_LSB          2
#define RICU_AFE_CTL_2_CTRL_IB_WIDTH        ((uint32_t)0x00000002)
#define RICU_AFE_CTL_2_CLK_MON_SEL_MASK     ((uint32_t)0x00000003)
#define RICU_AFE_CTL_2_CLK_MON_SEL_LSB      0
#define RICU_AFE_CTL_2_CLK_MON_SEL_WIDTH    ((uint32_t)0x00000002)

#define RICU_AFE_CTL_2_LOCK_CON_REV_LC_RST    0x0
#define RICU_AFE_CTL_2_LOCK_CON_REV_RST     0x0
#define RICU_AFE_CTL_2_LOCK_CON_OUT_LC_RST    0x3
#define RICU_AFE_CTL_2_LOCK_CON_OUT_RST     0x3
#define RICU_AFE_CTL_2_LOCK_CON_IN_LC_RST    0x3
#define RICU_AFE_CTL_2_LOCK_CON_IN_RST      0x3
#define RICU_AFE_CTL_2_LOCK_CON_DLY_LC_RST    0x3
#define RICU_AFE_CTL_2_LOCK_CON_DLY_RST     0x3
#define RICU_AFE_CTL_2_ICP_RST              0x1
#define RICU_AFE_CTL_2_CTRL_IB_RST          0x2
#define RICU_AFE_CTL_2_CLK_MON_SEL_RST      0x0

__INLINE void ricu_afe_ctl_2_pack(uint8_t lock_con_rev_lc, uint8_t lock_con_rev, uint8_t lock_con_out_lc, uint8_t lock_con_out, uint8_t lock_con_in_lc, uint8_t lock_con_in, uint8_t lock_con_dly_lc, uint8_t lock_con_dly, uint8_t icp, uint8_t ctrl_ib, uint8_t clk_mon_sel)
{
	ASSERT_ERR((((uint32_t)lock_con_rev_lc << 22) & ~((uint32_t)0x00C00000)) == 0);
	ASSERT_ERR((((uint32_t)lock_con_rev << 20) & ~((uint32_t)0x00300000)) == 0);
	ASSERT_ERR((((uint32_t)lock_con_out_lc << 18) & ~((uint32_t)0x000C0000)) == 0);
	ASSERT_ERR((((uint32_t)lock_con_out << 16) & ~((uint32_t)0x00030000)) == 0);
	ASSERT_ERR((((uint32_t)lock_con_in_lc << 14) & ~((uint32_t)0x0000C000)) == 0);
	ASSERT_ERR((((uint32_t)lock_con_in << 12) & ~((uint32_t)0x00003000)) == 0);
	ASSERT_ERR((((uint32_t)lock_con_dly_lc << 10) & ~((uint32_t)0x00000C00)) == 0);
	ASSERT_ERR((((uint32_t)lock_con_dly << 8) & ~((uint32_t)0x00000300)) == 0);
	ASSERT_ERR((((uint32_t)icp << 6) & ~((uint32_t)0x000000C0)) == 0);
	ASSERT_ERR((((uint32_t)ctrl_ib << 2) & ~((uint32_t)0x0000000C)) == 0);
	ASSERT_ERR((((uint32_t)clk_mon_sel << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RICU_AFE_CTL_2_ADDR,  ((uint32_t)lock_con_rev_lc << 22) |((uint32_t)lock_con_rev << 20) |((uint32_t)lock_con_out_lc << 18) |((uint32_t)lock_con_out << 16) |((uint32_t)lock_con_in_lc << 14) |((uint32_t)lock_con_in << 12) |((uint32_t)lock_con_dly_lc << 10) |((uint32_t)lock_con_dly << 8) |((uint32_t)icp << 6) |((uint32_t)ctrl_ib << 2) |((uint32_t)clk_mon_sel << 0));
}

__INLINE void ricu_afe_ctl_2_unpack(uint8_t* lock_con_rev_lc, uint8_t* lock_con_rev, uint8_t* lock_con_out_lc, uint8_t* lock_con_out, uint8_t* lock_con_in_lc, uint8_t* lock_con_in, uint8_t* lock_con_dly_lc, uint8_t* lock_con_dly, uint8_t* icp, uint8_t* ctrl_ib, uint8_t* clk_mon_sel)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_2_ADDR);

	*lock_con_rev_lc = (localVal & ((uint32_t)0x00C00000)) >>  22;
	*lock_con_rev = (localVal & ((uint32_t)0x00300000)) >>  20;
	*lock_con_out_lc = (localVal & ((uint32_t)0x000C0000)) >>  18;
	*lock_con_out = (localVal & ((uint32_t)0x00030000)) >>  16;
	*lock_con_in_lc = (localVal & ((uint32_t)0x0000C000)) >>  14;
	*lock_con_in = (localVal & ((uint32_t)0x00003000)) >>  12;
	*lock_con_dly_lc = (localVal & ((uint32_t)0x00000C00)) >>  10;
	*lock_con_dly = (localVal & ((uint32_t)0x00000300)) >>  8;
	*icp = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*ctrl_ib = (localVal & ((uint32_t)0x0000000C)) >>  2;
	*clk_mon_sel = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint8_t ricu_afe_ctl_2_lock_con_rev_lc_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00C00000)) >> 22);
}
__INLINE void ricu_afe_ctl_2_lock_con_rev_lc_setf(uint8_t lockconrevlc)
{
	ASSERT_ERR((((uint32_t)lockconrevlc << 22) & ~((uint32_t)0x00C00000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_2_ADDR, (REG_PL_RD(RICU_AFE_CTL_2_ADDR) & ~((uint32_t)0x00C00000)) | ((uint32_t)lockconrevlc <<22));
}
__INLINE uint8_t ricu_afe_ctl_2_lock_con_rev_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00300000)) >> 20);
}
__INLINE void ricu_afe_ctl_2_lock_con_rev_setf(uint8_t lockconrev)
{
	ASSERT_ERR((((uint32_t)lockconrev << 20) & ~((uint32_t)0x00300000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_2_ADDR, (REG_PL_RD(RICU_AFE_CTL_2_ADDR) & ~((uint32_t)0x00300000)) | ((uint32_t)lockconrev <<20));
}
__INLINE uint8_t ricu_afe_ctl_2_lock_con_out_lc_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000C0000)) >> 18);
}
__INLINE void ricu_afe_ctl_2_lock_con_out_lc_setf(uint8_t lockconoutlc)
{
	ASSERT_ERR((((uint32_t)lockconoutlc << 18) & ~((uint32_t)0x000C0000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_2_ADDR, (REG_PL_RD(RICU_AFE_CTL_2_ADDR) & ~((uint32_t)0x000C0000)) | ((uint32_t)lockconoutlc <<18));
}
__INLINE uint8_t ricu_afe_ctl_2_lock_con_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00030000)) >> 16);
}
__INLINE void ricu_afe_ctl_2_lock_con_out_setf(uint8_t lockconout)
{
	ASSERT_ERR((((uint32_t)lockconout << 16) & ~((uint32_t)0x00030000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_2_ADDR, (REG_PL_RD(RICU_AFE_CTL_2_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)lockconout <<16));
}
__INLINE uint8_t ricu_afe_ctl_2_lock_con_in_lc_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000C000)) >> 14);
}
__INLINE void ricu_afe_ctl_2_lock_con_in_lc_setf(uint8_t lockconinlc)
{
	ASSERT_ERR((((uint32_t)lockconinlc << 14) & ~((uint32_t)0x0000C000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_2_ADDR, (REG_PL_RD(RICU_AFE_CTL_2_ADDR) & ~((uint32_t)0x0000C000)) | ((uint32_t)lockconinlc <<14));
}
__INLINE uint8_t ricu_afe_ctl_2_lock_con_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00003000)) >> 12);
}
__INLINE void ricu_afe_ctl_2_lock_con_in_setf(uint8_t lockconin)
{
	ASSERT_ERR((((uint32_t)lockconin << 12) & ~((uint32_t)0x00003000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_2_ADDR, (REG_PL_RD(RICU_AFE_CTL_2_ADDR) & ~((uint32_t)0x00003000)) | ((uint32_t)lockconin <<12));
}
__INLINE uint8_t ricu_afe_ctl_2_lock_con_dly_lc_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000C00)) >> 10);
}
__INLINE void ricu_afe_ctl_2_lock_con_dly_lc_setf(uint8_t lockcondlylc)
{
	ASSERT_ERR((((uint32_t)lockcondlylc << 10) & ~((uint32_t)0x00000C00)) == 0);
	REG_PL_WR(RICU_AFE_CTL_2_ADDR, (REG_PL_RD(RICU_AFE_CTL_2_ADDR) & ~((uint32_t)0x00000C00)) | ((uint32_t)lockcondlylc <<10));
}
__INLINE uint8_t ricu_afe_ctl_2_lock_con_dly_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000300)) >> 8);
}
__INLINE void ricu_afe_ctl_2_lock_con_dly_setf(uint8_t lockcondly)
{
	ASSERT_ERR((((uint32_t)lockcondly << 8) & ~((uint32_t)0x00000300)) == 0);
	REG_PL_WR(RICU_AFE_CTL_2_ADDR, (REG_PL_RD(RICU_AFE_CTL_2_ADDR) & ~((uint32_t)0x00000300)) | ((uint32_t)lockcondly <<8));
}
__INLINE uint8_t ricu_afe_ctl_2_icp_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE void ricu_afe_ctl_2_icp_setf(uint8_t icp)
{
	ASSERT_ERR((((uint32_t)icp << 6) & ~((uint32_t)0x000000C0)) == 0);
	REG_PL_WR(RICU_AFE_CTL_2_ADDR, (REG_PL_RD(RICU_AFE_CTL_2_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)icp <<6));
}
__INLINE uint8_t ricu_afe_ctl_2_ctrl_ib_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000C)) >> 2);
}
__INLINE void ricu_afe_ctl_2_ctrl_ib_setf(uint8_t ctrlib)
{
	ASSERT_ERR((((uint32_t)ctrlib << 2) & ~((uint32_t)0x0000000C)) == 0);
	REG_PL_WR(RICU_AFE_CTL_2_ADDR, (REG_PL_RD(RICU_AFE_CTL_2_ADDR) & ~((uint32_t)0x0000000C)) | ((uint32_t)ctrlib <<2));
}
__INLINE uint8_t ricu_afe_ctl_2_clk_mon_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void ricu_afe_ctl_2_clk_mon_sel_setf(uint8_t clkmonsel)
{
	ASSERT_ERR((((uint32_t)clkmonsel << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RICU_AFE_CTL_2_ADDR, (REG_PL_RD(RICU_AFE_CTL_2_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)clkmonsel <<0));
}

/**
 * @brief AFE_CTL_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:28 RSEL                      0x0
 *    27:24 I_CSEL_LC                 0xc
 *    23:20 GM_LC                     0xf
 *    19:16 CSEL_LC                   0x3
 *    15:12 CML_SEL                   0x9
 *    11:09 S_LC                      0x0
 *    08:06 S                         0x0
 *    05:03 LBW_LC                    0x7
 *    02:00 ICP_LC                    0x7
 * </pre>
 */
#define RICU_AFE_CTL_3_ADDR        (REG_RICU_BASE_ADDR+0x0000001C)
#define RICU_AFE_CTL_3_OFFSET      0x0000001C
#define RICU_AFE_CTL_3_INDEX       0x00000007
#define RICU_AFE_CTL_3_RESET       0x0CF3903F

__INLINE uint32_t  ricu_afe_ctl_3_get(void)
{
	return REG_PL_RD(RICU_AFE_CTL_3_ADDR);
}

__INLINE void ricu_afe_ctl_3_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTL_3_ADDR, value);
}

// field definitions
#define RICU_AFE_CTL_3_RSEL_MASK            ((uint32_t)0xF0000000)
#define RICU_AFE_CTL_3_RSEL_LSB             28
#define RICU_AFE_CTL_3_RSEL_WIDTH           ((uint32_t)0x00000004)
#define RICU_AFE_CTL_3_I_CSEL_LC_MASK       ((uint32_t)0x0F000000)
#define RICU_AFE_CTL_3_I_CSEL_LC_LSB        24
#define RICU_AFE_CTL_3_I_CSEL_LC_WIDTH      ((uint32_t)0x00000004)
#define RICU_AFE_CTL_3_GM_LC_MASK           ((uint32_t)0x00F00000)
#define RICU_AFE_CTL_3_GM_LC_LSB            20
#define RICU_AFE_CTL_3_GM_LC_WIDTH          ((uint32_t)0x00000004)
#define RICU_AFE_CTL_3_CSEL_LC_MASK         ((uint32_t)0x000F0000)
#define RICU_AFE_CTL_3_CSEL_LC_LSB          16
#define RICU_AFE_CTL_3_CSEL_LC_WIDTH        ((uint32_t)0x00000004)
#define RICU_AFE_CTL_3_CML_SEL_MASK         ((uint32_t)0x0000F000)
#define RICU_AFE_CTL_3_CML_SEL_LSB          12
#define RICU_AFE_CTL_3_CML_SEL_WIDTH        ((uint32_t)0x00000004)
#define RICU_AFE_CTL_3_S_LC_MASK            ((uint32_t)0x00000E00)
#define RICU_AFE_CTL_3_S_LC_LSB             9
#define RICU_AFE_CTL_3_S_LC_WIDTH           ((uint32_t)0x00000003)
#define RICU_AFE_CTL_3_S_MASK               ((uint32_t)0x000001C0)
#define RICU_AFE_CTL_3_S_LSB                6
#define RICU_AFE_CTL_3_S_WIDTH              ((uint32_t)0x00000003)
#define RICU_AFE_CTL_3_LBW_LC_MASK          ((uint32_t)0x00000038)
#define RICU_AFE_CTL_3_LBW_LC_LSB           3
#define RICU_AFE_CTL_3_LBW_LC_WIDTH         ((uint32_t)0x00000003)
#define RICU_AFE_CTL_3_ICP_LC_MASK          ((uint32_t)0x00000007)
#define RICU_AFE_CTL_3_ICP_LC_LSB           0
#define RICU_AFE_CTL_3_ICP_LC_WIDTH         ((uint32_t)0x00000003)

#define RICU_AFE_CTL_3_RSEL_RST             0x0
#define RICU_AFE_CTL_3_I_CSEL_LC_RST        0xc
#define RICU_AFE_CTL_3_GM_LC_RST            0xf
#define RICU_AFE_CTL_3_CSEL_LC_RST          0x3
#define RICU_AFE_CTL_3_CML_SEL_RST          0x9
#define RICU_AFE_CTL_3_S_LC_RST             0x0
#define RICU_AFE_CTL_3_S_RST                0x0
#define RICU_AFE_CTL_3_LBW_LC_RST           0x7
#define RICU_AFE_CTL_3_ICP_LC_RST           0x7

__INLINE void ricu_afe_ctl_3_pack(uint8_t rsel, uint8_t i_csel_lc, uint8_t gm_lc, uint8_t csel_lc, uint8_t cml_sel, uint8_t s_lc, uint8_t s, uint8_t lbw_lc, uint8_t icp_lc)
{
	ASSERT_ERR((((uint32_t)rsel << 28) & ~((uint32_t)0xF0000000)) == 0);
	ASSERT_ERR((((uint32_t)i_csel_lc << 24) & ~((uint32_t)0x0F000000)) == 0);
	ASSERT_ERR((((uint32_t)gm_lc << 20) & ~((uint32_t)0x00F00000)) == 0);
	ASSERT_ERR((((uint32_t)csel_lc << 16) & ~((uint32_t)0x000F0000)) == 0);
	ASSERT_ERR((((uint32_t)cml_sel << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)s_lc << 9) & ~((uint32_t)0x00000E00)) == 0);
	ASSERT_ERR((((uint32_t)s << 6) & ~((uint32_t)0x000001C0)) == 0);
	ASSERT_ERR((((uint32_t)lbw_lc << 3) & ~((uint32_t)0x00000038)) == 0);
	ASSERT_ERR((((uint32_t)icp_lc << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(RICU_AFE_CTL_3_ADDR,  ((uint32_t)rsel << 28) |((uint32_t)i_csel_lc << 24) |((uint32_t)gm_lc << 20) |((uint32_t)csel_lc << 16) |((uint32_t)cml_sel << 12) |((uint32_t)s_lc << 9) |((uint32_t)s << 6) |((uint32_t)lbw_lc << 3) |((uint32_t)icp_lc << 0));
}

__INLINE void ricu_afe_ctl_3_unpack(uint8_t* rsel, uint8_t* i_csel_lc, uint8_t* gm_lc, uint8_t* csel_lc, uint8_t* cml_sel, uint8_t* s_lc, uint8_t* s, uint8_t* lbw_lc, uint8_t* icp_lc)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_3_ADDR);

	*rsel = (localVal & ((uint32_t)0xF0000000)) >>  28;
	*i_csel_lc = (localVal & ((uint32_t)0x0F000000)) >>  24;
	*gm_lc = (localVal & ((uint32_t)0x00F00000)) >>  20;
	*csel_lc = (localVal & ((uint32_t)0x000F0000)) >>  16;
	*cml_sel = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*s_lc = (localVal & ((uint32_t)0x00000E00)) >>  9;
	*s = (localVal & ((uint32_t)0x000001C0)) >>  6;
	*lbw_lc = (localVal & ((uint32_t)0x00000038)) >>  3;
	*icp_lc = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t ricu_afe_ctl_3_rsel_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xF0000000)) >> 28);
}
__INLINE void ricu_afe_ctl_3_rsel_setf(uint8_t rsel)
{
	ASSERT_ERR((((uint32_t)rsel << 28) & ~((uint32_t)0xF0000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_3_ADDR, (REG_PL_RD(RICU_AFE_CTL_3_ADDR) & ~((uint32_t)0xF0000000)) | ((uint32_t)rsel <<28));
}
__INLINE uint8_t ricu_afe_ctl_3_i_csel_lc_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0F000000)) >> 24);
}
__INLINE void ricu_afe_ctl_3_i_csel_lc_setf(uint8_t icsellc)
{
	ASSERT_ERR((((uint32_t)icsellc << 24) & ~((uint32_t)0x0F000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_3_ADDR, (REG_PL_RD(RICU_AFE_CTL_3_ADDR) & ~((uint32_t)0x0F000000)) | ((uint32_t)icsellc <<24));
}
__INLINE uint8_t ricu_afe_ctl_3_gm_lc_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00F00000)) >> 20);
}
__INLINE void ricu_afe_ctl_3_gm_lc_setf(uint8_t gmlc)
{
	ASSERT_ERR((((uint32_t)gmlc << 20) & ~((uint32_t)0x00F00000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_3_ADDR, (REG_PL_RD(RICU_AFE_CTL_3_ADDR) & ~((uint32_t)0x00F00000)) | ((uint32_t)gmlc <<20));
}
__INLINE uint8_t ricu_afe_ctl_3_csel_lc_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000F0000)) >> 16);
}
__INLINE void ricu_afe_ctl_3_csel_lc_setf(uint8_t csellc)
{
	ASSERT_ERR((((uint32_t)csellc << 16) & ~((uint32_t)0x000F0000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_3_ADDR, (REG_PL_RD(RICU_AFE_CTL_3_ADDR) & ~((uint32_t)0x000F0000)) | ((uint32_t)csellc <<16));
}
__INLINE uint8_t ricu_afe_ctl_3_cml_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void ricu_afe_ctl_3_cml_sel_setf(uint8_t cmlsel)
{
	ASSERT_ERR((((uint32_t)cmlsel << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_3_ADDR, (REG_PL_RD(RICU_AFE_CTL_3_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)cmlsel <<12));
}
__INLINE uint8_t ricu_afe_ctl_3_s_lc_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000E00)) >> 9);
}
__INLINE void ricu_afe_ctl_3_s_lc_setf(uint8_t slc)
{
	ASSERT_ERR((((uint32_t)slc << 9) & ~((uint32_t)0x00000E00)) == 0);
	REG_PL_WR(RICU_AFE_CTL_3_ADDR, (REG_PL_RD(RICU_AFE_CTL_3_ADDR) & ~((uint32_t)0x00000E00)) | ((uint32_t)slc <<9));
}
__INLINE uint8_t ricu_afe_ctl_3_s_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000001C0)) >> 6);
}
__INLINE void ricu_afe_ctl_3_s_setf(uint8_t s)
{
	ASSERT_ERR((((uint32_t)s << 6) & ~((uint32_t)0x000001C0)) == 0);
	REG_PL_WR(RICU_AFE_CTL_3_ADDR, (REG_PL_RD(RICU_AFE_CTL_3_ADDR) & ~((uint32_t)0x000001C0)) | ((uint32_t)s <<6));
}
__INLINE uint8_t ricu_afe_ctl_3_lbw_lc_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000038)) >> 3);
}
__INLINE void ricu_afe_ctl_3_lbw_lc_setf(uint8_t lbwlc)
{
	ASSERT_ERR((((uint32_t)lbwlc << 3) & ~((uint32_t)0x00000038)) == 0);
	REG_PL_WR(RICU_AFE_CTL_3_ADDR, (REG_PL_RD(RICU_AFE_CTL_3_ADDR) & ~((uint32_t)0x00000038)) | ((uint32_t)lbwlc <<3));
}
__INLINE uint8_t ricu_afe_ctl_3_icp_lc_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void ricu_afe_ctl_3_icp_lc_setf(uint8_t icplc)
{
	ASSERT_ERR((((uint32_t)icplc << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(RICU_AFE_CTL_3_ADDR, (REG_PL_RD(RICU_AFE_CTL_3_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)icplc <<0));
}

/**
 * @brief AFE_CTL_4 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    29:25 EXTAFC_LC                 0x0
 *    24:20 EXTAFC                    0x0
 *    19:16 VTRIM_PLL                 0x0
 *    15:12 VTRIM_AFE                 0x0
 *    11:08 VCTRL_PLL                 0x9
 *    07:04 VCTRL_AFE                 0x0
 *    03:00 RSEL_LC                   0xd
 * </pre>
 */
#define RICU_AFE_CTL_4_ADDR        (REG_RICU_BASE_ADDR+0x00000020)
#define RICU_AFE_CTL_4_OFFSET      0x00000020
#define RICU_AFE_CTL_4_INDEX       0x00000008
#define RICU_AFE_CTL_4_RESET       0x0000090D

__INLINE uint32_t  ricu_afe_ctl_4_get(void)
{
	return REG_PL_RD(RICU_AFE_CTL_4_ADDR);
}

__INLINE void ricu_afe_ctl_4_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTL_4_ADDR, value);
}

// field definitions
#define RICU_AFE_CTL_4_EXTAFC_LC_MASK       ((uint32_t)0x3E000000)
#define RICU_AFE_CTL_4_EXTAFC_LC_LSB        25
#define RICU_AFE_CTL_4_EXTAFC_LC_WIDTH      ((uint32_t)0x00000005)
#define RICU_AFE_CTL_4_EXTAFC_MASK          ((uint32_t)0x01F00000)
#define RICU_AFE_CTL_4_EXTAFC_LSB           20
#define RICU_AFE_CTL_4_EXTAFC_WIDTH         ((uint32_t)0x00000005)
#define RICU_AFE_CTL_4_VTRIM_PLL_MASK       ((uint32_t)0x000F0000)
#define RICU_AFE_CTL_4_VTRIM_PLL_LSB        16
#define RICU_AFE_CTL_4_VTRIM_PLL_WIDTH      ((uint32_t)0x00000004)
#define RICU_AFE_CTL_4_VTRIM_AFE_MASK       ((uint32_t)0x0000F000)
#define RICU_AFE_CTL_4_VTRIM_AFE_LSB        12
#define RICU_AFE_CTL_4_VTRIM_AFE_WIDTH      ((uint32_t)0x00000004)
#define RICU_AFE_CTL_4_VCTRL_PLL_MASK       ((uint32_t)0x00000F00)
#define RICU_AFE_CTL_4_VCTRL_PLL_LSB        8
#define RICU_AFE_CTL_4_VCTRL_PLL_WIDTH      ((uint32_t)0x00000004)
#define RICU_AFE_CTL_4_VCTRL_AFE_MASK       ((uint32_t)0x000000F0)
#define RICU_AFE_CTL_4_VCTRL_AFE_LSB        4
#define RICU_AFE_CTL_4_VCTRL_AFE_WIDTH      ((uint32_t)0x00000004)
#define RICU_AFE_CTL_4_RSEL_LC_MASK         ((uint32_t)0x0000000F)
#define RICU_AFE_CTL_4_RSEL_LC_LSB          0
#define RICU_AFE_CTL_4_RSEL_LC_WIDTH        ((uint32_t)0x00000004)

#define RICU_AFE_CTL_4_EXTAFC_LC_RST        0x0
#define RICU_AFE_CTL_4_EXTAFC_RST           0x0
#define RICU_AFE_CTL_4_VTRIM_PLL_RST        0x0
#define RICU_AFE_CTL_4_VTRIM_AFE_RST        0x0
#define RICU_AFE_CTL_4_VCTRL_PLL_RST        0x9
#define RICU_AFE_CTL_4_VCTRL_AFE_RST        0x0
#define RICU_AFE_CTL_4_RSEL_LC_RST          0xd

__INLINE void ricu_afe_ctl_4_pack(uint8_t extafc_lc, uint8_t extafc, uint8_t vtrim_pll, uint8_t vtrim_afe, uint8_t vctrl_pll, uint8_t vctrl_afe, uint8_t rsel_lc)
{
	ASSERT_ERR((((uint32_t)extafc_lc << 25) & ~((uint32_t)0x3E000000)) == 0);
	ASSERT_ERR((((uint32_t)extafc << 20) & ~((uint32_t)0x01F00000)) == 0);
	ASSERT_ERR((((uint32_t)vtrim_pll << 16) & ~((uint32_t)0x000F0000)) == 0);
	ASSERT_ERR((((uint32_t)vtrim_afe << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)vctrl_pll << 8) & ~((uint32_t)0x00000F00)) == 0);
	ASSERT_ERR((((uint32_t)vctrl_afe << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)rsel_lc << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RICU_AFE_CTL_4_ADDR,  ((uint32_t)extafc_lc << 25) |((uint32_t)extafc << 20) |((uint32_t)vtrim_pll << 16) |((uint32_t)vtrim_afe << 12) |((uint32_t)vctrl_pll << 8) |((uint32_t)vctrl_afe << 4) |((uint32_t)rsel_lc << 0));
}

__INLINE void ricu_afe_ctl_4_unpack(uint8_t* extafc_lc, uint8_t* extafc, uint8_t* vtrim_pll, uint8_t* vtrim_afe, uint8_t* vctrl_pll, uint8_t* vctrl_afe, uint8_t* rsel_lc)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_4_ADDR);

	*extafc_lc = (localVal & ((uint32_t)0x3E000000)) >>  25;
	*extafc = (localVal & ((uint32_t)0x01F00000)) >>  20;
	*vtrim_pll = (localVal & ((uint32_t)0x000F0000)) >>  16;
	*vtrim_afe = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*vctrl_pll = (localVal & ((uint32_t)0x00000F00)) >>  8;
	*vctrl_afe = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*rsel_lc = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t ricu_afe_ctl_4_extafc_lc_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x3E000000)) >> 25);
}
__INLINE void ricu_afe_ctl_4_extafc_lc_setf(uint8_t extafclc)
{
	ASSERT_ERR((((uint32_t)extafclc << 25) & ~((uint32_t)0x3E000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_4_ADDR, (REG_PL_RD(RICU_AFE_CTL_4_ADDR) & ~((uint32_t)0x3E000000)) | ((uint32_t)extafclc <<25));
}
__INLINE uint8_t ricu_afe_ctl_4_extafc_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01F00000)) >> 20);
}
__INLINE void ricu_afe_ctl_4_extafc_setf(uint8_t extafc)
{
	ASSERT_ERR((((uint32_t)extafc << 20) & ~((uint32_t)0x01F00000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_4_ADDR, (REG_PL_RD(RICU_AFE_CTL_4_ADDR) & ~((uint32_t)0x01F00000)) | ((uint32_t)extafc <<20));
}
__INLINE uint8_t ricu_afe_ctl_4_vtrim_pll_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000F0000)) >> 16);
}
__INLINE void ricu_afe_ctl_4_vtrim_pll_setf(uint8_t vtrimpll)
{
	ASSERT_ERR((((uint32_t)vtrimpll << 16) & ~((uint32_t)0x000F0000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_4_ADDR, (REG_PL_RD(RICU_AFE_CTL_4_ADDR) & ~((uint32_t)0x000F0000)) | ((uint32_t)vtrimpll <<16));
}
__INLINE uint8_t ricu_afe_ctl_4_vtrim_afe_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void ricu_afe_ctl_4_vtrim_afe_setf(uint8_t vtrimafe)
{
	ASSERT_ERR((((uint32_t)vtrimafe << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_4_ADDR, (REG_PL_RD(RICU_AFE_CTL_4_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)vtrimafe <<12));
}
__INLINE uint8_t ricu_afe_ctl_4_vctrl_pll_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000F00)) >> 8);
}
__INLINE void ricu_afe_ctl_4_vctrl_pll_setf(uint8_t vctrlpll)
{
	ASSERT_ERR((((uint32_t)vctrlpll << 8) & ~((uint32_t)0x00000F00)) == 0);
	REG_PL_WR(RICU_AFE_CTL_4_ADDR, (REG_PL_RD(RICU_AFE_CTL_4_ADDR) & ~((uint32_t)0x00000F00)) | ((uint32_t)vctrlpll <<8));
}
__INLINE uint8_t ricu_afe_ctl_4_vctrl_afe_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE void ricu_afe_ctl_4_vctrl_afe_setf(uint8_t vctrlafe)
{
	ASSERT_ERR((((uint32_t)vctrlafe << 4) & ~((uint32_t)0x000000F0)) == 0);
	REG_PL_WR(RICU_AFE_CTL_4_ADDR, (REG_PL_RD(RICU_AFE_CTL_4_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)vctrlafe <<4));
}
__INLINE uint8_t ricu_afe_ctl_4_rsel_lc_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void ricu_afe_ctl_4_rsel_lc_setf(uint8_t rsellc)
{
	ASSERT_ERR((((uint32_t)rsellc << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RICU_AFE_CTL_4_ADDR, (REG_PL_RD(RICU_AFE_CTL_4_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)rsellc <<0));
}

/**
 * @brief AFE_CTL_5 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:18 MAIN_SEL_7_2              0x0
 *    17:12 P_LC                      0x1
 *    11:06 P                         0xA
 *    05:00 CAP_BIAS_CODE_LC          0x4
 * </pre>
 */
#define RICU_AFE_CTL_5_ADDR        (REG_RICU_BASE_ADDR+0x00000024)
#define RICU_AFE_CTL_5_OFFSET      0x00000024
#define RICU_AFE_CTL_5_INDEX       0x00000009
#define RICU_AFE_CTL_5_RESET       0x00001284

__INLINE uint32_t  ricu_afe_ctl_5_get(void)
{
	return REG_PL_RD(RICU_AFE_CTL_5_ADDR);
}

__INLINE void ricu_afe_ctl_5_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTL_5_ADDR, value);
}

// field definitions
#define RICU_AFE_CTL_5_MAIN_SEL_7_2_MASK    ((uint32_t)0x00FC0000)
#define RICU_AFE_CTL_5_MAIN_SEL_7_2_LSB     18
#define RICU_AFE_CTL_5_MAIN_SEL_7_2_WIDTH    ((uint32_t)0x00000006)
#define RICU_AFE_CTL_5_P_LC_MASK            ((uint32_t)0x0003F000)
#define RICU_AFE_CTL_5_P_LC_LSB             12
#define RICU_AFE_CTL_5_P_LC_WIDTH           ((uint32_t)0x00000006)
#define RICU_AFE_CTL_5_P_MASK               ((uint32_t)0x00000FC0)
#define RICU_AFE_CTL_5_P_LSB                6
#define RICU_AFE_CTL_5_P_WIDTH              ((uint32_t)0x00000006)
#define RICU_AFE_CTL_5_CAP_BIAS_CODE_LC_MASK    ((uint32_t)0x0000003F)
#define RICU_AFE_CTL_5_CAP_BIAS_CODE_LC_LSB    0
#define RICU_AFE_CTL_5_CAP_BIAS_CODE_LC_WIDTH    ((uint32_t)0x00000006)

#define RICU_AFE_CTL_5_MAIN_SEL_7_2_RST     0x0
#define RICU_AFE_CTL_5_P_LC_RST             0x1
#define RICU_AFE_CTL_5_P_RST                0xA
#define RICU_AFE_CTL_5_CAP_BIAS_CODE_LC_RST    0x4

__INLINE void ricu_afe_ctl_5_pack(uint8_t main_sel_7_2, uint8_t p_lc, uint8_t p, uint8_t cap_bias_code_lc)
{
	ASSERT_ERR((((uint32_t)main_sel_7_2 << 18) & ~((uint32_t)0x00FC0000)) == 0);
	ASSERT_ERR((((uint32_t)p_lc << 12) & ~((uint32_t)0x0003F000)) == 0);
	ASSERT_ERR((((uint32_t)p << 6) & ~((uint32_t)0x00000FC0)) == 0);
	ASSERT_ERR((((uint32_t)cap_bias_code_lc << 0) & ~((uint32_t)0x0000003F)) == 0);
	REG_PL_WR(RICU_AFE_CTL_5_ADDR,  ((uint32_t)main_sel_7_2 << 18) |((uint32_t)p_lc << 12) |((uint32_t)p << 6) |((uint32_t)cap_bias_code_lc << 0));
}

__INLINE void ricu_afe_ctl_5_unpack(uint8_t* main_sel_7_2, uint8_t* p_lc, uint8_t* p, uint8_t* cap_bias_code_lc)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_5_ADDR);

	*main_sel_7_2 = (localVal & ((uint32_t)0x00FC0000)) >>  18;
	*p_lc = (localVal & ((uint32_t)0x0003F000)) >>  12;
	*p = (localVal & ((uint32_t)0x00000FC0)) >>  6;
	*cap_bias_code_lc = (localVal & ((uint32_t)0x0000003F)) >>  0;
}

__INLINE uint8_t ricu_afe_ctl_5_main_sel_7_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FC0000)) >> 18);
}
__INLINE void ricu_afe_ctl_5_main_sel_7_2_setf(uint8_t mainsel72)
{
	ASSERT_ERR((((uint32_t)mainsel72 << 18) & ~((uint32_t)0x00FC0000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_5_ADDR, (REG_PL_RD(RICU_AFE_CTL_5_ADDR) & ~((uint32_t)0x00FC0000)) | ((uint32_t)mainsel72 <<18));
}
__INLINE uint8_t ricu_afe_ctl_5_p_lc_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0003F000)) >> 12);
}
__INLINE void ricu_afe_ctl_5_p_lc_setf(uint8_t plc)
{
	ASSERT_ERR((((uint32_t)plc << 12) & ~((uint32_t)0x0003F000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_5_ADDR, (REG_PL_RD(RICU_AFE_CTL_5_ADDR) & ~((uint32_t)0x0003F000)) | ((uint32_t)plc <<12));
}
__INLINE uint8_t ricu_afe_ctl_5_p_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000FC0)) >> 6);
}
__INLINE void ricu_afe_ctl_5_p_setf(uint8_t p)
{
	ASSERT_ERR((((uint32_t)p << 6) & ~((uint32_t)0x00000FC0)) == 0);
	REG_PL_WR(RICU_AFE_CTL_5_ADDR, (REG_PL_RD(RICU_AFE_CTL_5_ADDR) & ~((uint32_t)0x00000FC0)) | ((uint32_t)p <<6));
}
__INLINE uint8_t ricu_afe_ctl_5_cap_bias_code_lc_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000003F)) >> 0);
}
__INLINE void ricu_afe_ctl_5_cap_bias_code_lc_setf(uint8_t capbiascodelc)
{
	ASSERT_ERR((((uint32_t)capbiascodelc << 0) & ~((uint32_t)0x0000003F)) == 0);
	REG_PL_WR(RICU_AFE_CTL_5_ADDR, (REG_PL_RD(RICU_AFE_CTL_5_ADDR) & ~((uint32_t)0x0000003F)) | ((uint32_t)capbiascodelc <<0));
}

/**
 * @brief AFE_CTL_6 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    25:16 M_LC                      0x050
 *    09:00 M                         0x0f0
 * </pre>
 */
#define RICU_AFE_CTL_6_ADDR        (REG_RICU_BASE_ADDR+0x00000028)
#define RICU_AFE_CTL_6_OFFSET      0x00000028
#define RICU_AFE_CTL_6_INDEX       0x0000000A
#define RICU_AFE_CTL_6_RESET       0x005000F0

__INLINE uint32_t  ricu_afe_ctl_6_get(void)
{
	return REG_PL_RD(RICU_AFE_CTL_6_ADDR);
}

__INLINE void ricu_afe_ctl_6_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTL_6_ADDR, value);
}

// field definitions
#define RICU_AFE_CTL_6_M_LC_MASK            ((uint32_t)0x03FF0000)
#define RICU_AFE_CTL_6_M_LC_LSB             16
#define RICU_AFE_CTL_6_M_LC_WIDTH           ((uint32_t)0x0000000A)
#define RICU_AFE_CTL_6_M_MASK               ((uint32_t)0x000003FF)
#define RICU_AFE_CTL_6_M_LSB                0
#define RICU_AFE_CTL_6_M_WIDTH              ((uint32_t)0x0000000A)

#define RICU_AFE_CTL_6_M_LC_RST             0x050
#define RICU_AFE_CTL_6_M_RST                0x0f0

__INLINE void ricu_afe_ctl_6_pack(uint16_t m_lc, uint16_t m)
{
	ASSERT_ERR((((uint32_t)m_lc << 16) & ~((uint32_t)0x03FF0000)) == 0);
	ASSERT_ERR((((uint32_t)m << 0) & ~((uint32_t)0x000003FF)) == 0);
	REG_PL_WR(RICU_AFE_CTL_6_ADDR,  ((uint32_t)m_lc << 16) |((uint32_t)m << 0));
}

__INLINE void ricu_afe_ctl_6_unpack(uint16_t* m_lc, uint16_t* m)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_6_ADDR);

	*m_lc = (localVal & ((uint32_t)0x03FF0000)) >>  16;
	*m = (localVal & ((uint32_t)0x000003FF)) >>  0;
}

__INLINE uint16_t ricu_afe_ctl_6_m_lc_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_6_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x03FF0000)) >> 16);
}
__INLINE void ricu_afe_ctl_6_m_lc_setf(uint16_t mlc)
{
	ASSERT_ERR((((uint32_t)mlc << 16) & ~((uint32_t)0x03FF0000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_6_ADDR, (REG_PL_RD(RICU_AFE_CTL_6_ADDR) & ~((uint32_t)0x03FF0000)) | ((uint32_t)mlc <<16));
}
__INLINE uint16_t ricu_afe_ctl_6_m_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_6_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000003FF)) >> 0);
}
__INLINE void ricu_afe_ctl_6_m_setf(uint16_t m)
{
	ASSERT_ERR((((uint32_t)m << 0) & ~((uint32_t)0x000003FF)) == 0);
	REG_PL_WR(RICU_AFE_CTL_6_ADDR, (REG_PL_RD(RICU_AFE_CTL_6_ADDR) & ~((uint32_t)0x000003FF)) | ((uint32_t)m <<0));
}

/**
 * @brief AFE_CTL_7 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    COMP_SEL7                 1              
 *    30    COMP_SEL6                 1              
 *    29    COMP_SEL5                 1              
 *    28    COMP_SEL4                 1              
 *    27    COMP_SEL3                 1              
 *    26    COMP_SEL2                 1              
 *    25    COMP_SEL1                 1              
 *    24    COMP_SEL0                 1              
 *    23    CLK_PHASE_SEL7            0              
 *    22    CLK_PHASE_SEL6            0              
 *    21    CLK_PHASE_SEL5            0              
 *    20    CLK_PHASE_SEL4            0              
 *    19    CLK_PHASE_SEL3            0              
 *    18    CLK_PHASE_SEL2            0              
 *    17    CLK_PHASE_SEL1            0              
 *    16    CLK_PHASE_SEL0            0              
 *    15:14 CKC_SEL7                  0x3
 *    13:12 CKC_SEL6                  0x3
 *    11:10 CKC_SEL5                  0x3
 *    09:08 CKC_SEL4                  0x3
 *    07:06 CKC_SEL3                  0x3
 *    05:04 CKC_SEL2                  0x3
 *    03:02 CKC_SEL1                  0x3
 *    01:00 CKC_SEL0                  0x3
 * </pre>
 */
#define RICU_AFE_CTL_7_ADDR        (REG_RICU_BASE_ADDR+0x0000002C)
#define RICU_AFE_CTL_7_OFFSET      0x0000002C
#define RICU_AFE_CTL_7_INDEX       0x0000000B
#define RICU_AFE_CTL_7_RESET       0xFF00FFFF

__INLINE uint32_t  ricu_afe_ctl_7_get(void)
{
	return REG_PL_RD(RICU_AFE_CTL_7_ADDR);
}

__INLINE void ricu_afe_ctl_7_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTL_7_ADDR, value);
}

// field definitions
#define RICU_AFE_CTL_7_COMP_SEL_7_BIT       ((uint32_t)0x80000000)
#define RICU_AFE_CTL_7_COMP_SEL_7_POS       31
#define RICU_AFE_CTL_7_COMP_SEL_6_BIT       ((uint32_t)0x40000000)
#define RICU_AFE_CTL_7_COMP_SEL_6_POS       30
#define RICU_AFE_CTL_7_COMP_SEL_5_BIT       ((uint32_t)0x20000000)
#define RICU_AFE_CTL_7_COMP_SEL_5_POS       29
#define RICU_AFE_CTL_7_COMP_SEL_4_BIT       ((uint32_t)0x10000000)
#define RICU_AFE_CTL_7_COMP_SEL_4_POS       28
#define RICU_AFE_CTL_7_COMP_SEL_3_BIT       ((uint32_t)0x08000000)
#define RICU_AFE_CTL_7_COMP_SEL_3_POS       27
#define RICU_AFE_CTL_7_COMP_SEL_2_BIT       ((uint32_t)0x04000000)
#define RICU_AFE_CTL_7_COMP_SEL_2_POS       26
#define RICU_AFE_CTL_7_COMP_SEL_1_BIT       ((uint32_t)0x02000000)
#define RICU_AFE_CTL_7_COMP_SEL_1_POS       25
#define RICU_AFE_CTL_7_COMP_SEL_0_BIT       ((uint32_t)0x01000000)
#define RICU_AFE_CTL_7_COMP_SEL_0_POS       24
#define RICU_AFE_CTL_7_CLK_PHASE_SEL_7_BIT    ((uint32_t)0x00800000)
#define RICU_AFE_CTL_7_CLK_PHASE_SEL_7_POS    23
#define RICU_AFE_CTL_7_CLK_PHASE_SEL_6_BIT    ((uint32_t)0x00400000)
#define RICU_AFE_CTL_7_CLK_PHASE_SEL_6_POS    22
#define RICU_AFE_CTL_7_CLK_PHASE_SEL_5_BIT    ((uint32_t)0x00200000)
#define RICU_AFE_CTL_7_CLK_PHASE_SEL_5_POS    21
#define RICU_AFE_CTL_7_CLK_PHASE_SEL_4_BIT    ((uint32_t)0x00100000)
#define RICU_AFE_CTL_7_CLK_PHASE_SEL_4_POS    20
#define RICU_AFE_CTL_7_CLK_PHASE_SEL_3_BIT    ((uint32_t)0x00080000)
#define RICU_AFE_CTL_7_CLK_PHASE_SEL_3_POS    19
#define RICU_AFE_CTL_7_CLK_PHASE_SEL_2_BIT    ((uint32_t)0x00040000)
#define RICU_AFE_CTL_7_CLK_PHASE_SEL_2_POS    18
#define RICU_AFE_CTL_7_CLK_PHASE_SEL_1_BIT    ((uint32_t)0x00020000)
#define RICU_AFE_CTL_7_CLK_PHASE_SEL_1_POS    17
#define RICU_AFE_CTL_7_CLK_PHASE_SEL_0_BIT    ((uint32_t)0x00010000)
#define RICU_AFE_CTL_7_CLK_PHASE_SEL_0_POS    16
#define RICU_AFE_CTL_7_CKC_SEL_7_MASK       ((uint32_t)0x0000C000)
#define RICU_AFE_CTL_7_CKC_SEL_7_LSB        14
#define RICU_AFE_CTL_7_CKC_SEL_7_WIDTH      ((uint32_t)0x00000002)
#define RICU_AFE_CTL_7_CKC_SEL_6_MASK       ((uint32_t)0x00003000)
#define RICU_AFE_CTL_7_CKC_SEL_6_LSB        12
#define RICU_AFE_CTL_7_CKC_SEL_6_WIDTH      ((uint32_t)0x00000002)
#define RICU_AFE_CTL_7_CKC_SEL_5_MASK       ((uint32_t)0x00000C00)
#define RICU_AFE_CTL_7_CKC_SEL_5_LSB        10
#define RICU_AFE_CTL_7_CKC_SEL_5_WIDTH      ((uint32_t)0x00000002)
#define RICU_AFE_CTL_7_CKC_SEL_4_MASK       ((uint32_t)0x00000300)
#define RICU_AFE_CTL_7_CKC_SEL_4_LSB        8
#define RICU_AFE_CTL_7_CKC_SEL_4_WIDTH      ((uint32_t)0x00000002)
#define RICU_AFE_CTL_7_CKC_SEL_3_MASK       ((uint32_t)0x000000C0)
#define RICU_AFE_CTL_7_CKC_SEL_3_LSB        6
#define RICU_AFE_CTL_7_CKC_SEL_3_WIDTH      ((uint32_t)0x00000002)
#define RICU_AFE_CTL_7_CKC_SEL_2_MASK       ((uint32_t)0x00000030)
#define RICU_AFE_CTL_7_CKC_SEL_2_LSB        4
#define RICU_AFE_CTL_7_CKC_SEL_2_WIDTH      ((uint32_t)0x00000002)
#define RICU_AFE_CTL_7_CKC_SEL_1_MASK       ((uint32_t)0x0000000C)
#define RICU_AFE_CTL_7_CKC_SEL_1_LSB        2
#define RICU_AFE_CTL_7_CKC_SEL_1_WIDTH      ((uint32_t)0x00000002)
#define RICU_AFE_CTL_7_CKC_SEL_0_MASK       ((uint32_t)0x00000003)
#define RICU_AFE_CTL_7_CKC_SEL_0_LSB        0
#define RICU_AFE_CTL_7_CKC_SEL_0_WIDTH      ((uint32_t)0x00000002)

#define RICU_AFE_CTL_7_COMP_SEL_7_RST       0x1
#define RICU_AFE_CTL_7_COMP_SEL_6_RST       0x1
#define RICU_AFE_CTL_7_COMP_SEL_5_RST       0x1
#define RICU_AFE_CTL_7_COMP_SEL_4_RST       0x1
#define RICU_AFE_CTL_7_COMP_SEL_3_RST       0x1
#define RICU_AFE_CTL_7_COMP_SEL_2_RST       0x1
#define RICU_AFE_CTL_7_COMP_SEL_1_RST       0x1
#define RICU_AFE_CTL_7_COMP_SEL_0_RST       0x1
#define RICU_AFE_CTL_7_CLK_PHASE_SEL_7_RST    0x0
#define RICU_AFE_CTL_7_CLK_PHASE_SEL_6_RST    0x0
#define RICU_AFE_CTL_7_CLK_PHASE_SEL_5_RST    0x0
#define RICU_AFE_CTL_7_CLK_PHASE_SEL_4_RST    0x0
#define RICU_AFE_CTL_7_CLK_PHASE_SEL_3_RST    0x0
#define RICU_AFE_CTL_7_CLK_PHASE_SEL_2_RST    0x0
#define RICU_AFE_CTL_7_CLK_PHASE_SEL_1_RST    0x0
#define RICU_AFE_CTL_7_CLK_PHASE_SEL_0_RST    0x0
#define RICU_AFE_CTL_7_CKC_SEL_7_RST        0x3
#define RICU_AFE_CTL_7_CKC_SEL_6_RST        0x3
#define RICU_AFE_CTL_7_CKC_SEL_5_RST        0x3
#define RICU_AFE_CTL_7_CKC_SEL_4_RST        0x3
#define RICU_AFE_CTL_7_CKC_SEL_3_RST        0x3
#define RICU_AFE_CTL_7_CKC_SEL_2_RST        0x3
#define RICU_AFE_CTL_7_CKC_SEL_1_RST        0x3
#define RICU_AFE_CTL_7_CKC_SEL_0_RST        0x3

__INLINE void ricu_afe_ctl_7_pack(uint8_t comp_sel7, uint8_t comp_sel6, uint8_t comp_sel5, uint8_t comp_sel4, uint8_t comp_sel3, uint8_t comp_sel2, uint8_t comp_sel1, uint8_t comp_sel0, uint8_t clk_phase_sel7, uint8_t clk_phase_sel6, uint8_t clk_phase_sel5, uint8_t clk_phase_sel4, uint8_t clk_phase_sel3, uint8_t clk_phase_sel2, uint8_t clk_phase_sel1, uint8_t clk_phase_sel0, uint8_t ckc_sel7, uint8_t ckc_sel6, uint8_t ckc_sel5, uint8_t ckc_sel4, uint8_t ckc_sel3, uint8_t ckc_sel2, uint8_t ckc_sel1, uint8_t ckc_sel0)
{
	ASSERT_ERR((((uint32_t)comp_sel7 << 31) & ~((uint32_t)0x80000000)) == 0);
	ASSERT_ERR((((uint32_t)comp_sel6 << 30) & ~((uint32_t)0x40000000)) == 0);
	ASSERT_ERR((((uint32_t)comp_sel5 << 29) & ~((uint32_t)0x20000000)) == 0);
	ASSERT_ERR((((uint32_t)comp_sel4 << 28) & ~((uint32_t)0x10000000)) == 0);
	ASSERT_ERR((((uint32_t)comp_sel3 << 27) & ~((uint32_t)0x08000000)) == 0);
	ASSERT_ERR((((uint32_t)comp_sel2 << 26) & ~((uint32_t)0x04000000)) == 0);
	ASSERT_ERR((((uint32_t)comp_sel1 << 25) & ~((uint32_t)0x02000000)) == 0);
	ASSERT_ERR((((uint32_t)comp_sel0 << 24) & ~((uint32_t)0x01000000)) == 0);
	ASSERT_ERR((((uint32_t)clk_phase_sel7 << 23) & ~((uint32_t)0x00800000)) == 0);
	ASSERT_ERR((((uint32_t)clk_phase_sel6 << 22) & ~((uint32_t)0x00400000)) == 0);
	ASSERT_ERR((((uint32_t)clk_phase_sel5 << 21) & ~((uint32_t)0x00200000)) == 0);
	ASSERT_ERR((((uint32_t)clk_phase_sel4 << 20) & ~((uint32_t)0x00100000)) == 0);
	ASSERT_ERR((((uint32_t)clk_phase_sel3 << 19) & ~((uint32_t)0x00080000)) == 0);
	ASSERT_ERR((((uint32_t)clk_phase_sel2 << 18) & ~((uint32_t)0x00040000)) == 0);
	ASSERT_ERR((((uint32_t)clk_phase_sel1 << 17) & ~((uint32_t)0x00020000)) == 0);
	ASSERT_ERR((((uint32_t)clk_phase_sel0 << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)ckc_sel7 << 14) & ~((uint32_t)0x0000C000)) == 0);
	ASSERT_ERR((((uint32_t)ckc_sel6 << 12) & ~((uint32_t)0x00003000)) == 0);
	ASSERT_ERR((((uint32_t)ckc_sel5 << 10) & ~((uint32_t)0x00000C00)) == 0);
	ASSERT_ERR((((uint32_t)ckc_sel4 << 8) & ~((uint32_t)0x00000300)) == 0);
	ASSERT_ERR((((uint32_t)ckc_sel3 << 6) & ~((uint32_t)0x000000C0)) == 0);
	ASSERT_ERR((((uint32_t)ckc_sel2 << 4) & ~((uint32_t)0x00000030)) == 0);
	ASSERT_ERR((((uint32_t)ckc_sel1 << 2) & ~((uint32_t)0x0000000C)) == 0);
	ASSERT_ERR((((uint32_t)ckc_sel0 << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RICU_AFE_CTL_7_ADDR,  ((uint32_t)comp_sel7 << 31) |((uint32_t)comp_sel6 << 30) |((uint32_t)comp_sel5 << 29) |((uint32_t)comp_sel4 << 28) |((uint32_t)comp_sel3 << 27) |((uint32_t)comp_sel2 << 26) |((uint32_t)comp_sel1 << 25) |((uint32_t)comp_sel0 << 24) |((uint32_t)clk_phase_sel7 << 23) |((uint32_t)clk_phase_sel6 << 22) |((uint32_t)clk_phase_sel5 << 21) |((uint32_t)clk_phase_sel4 << 20) |((uint32_t)clk_phase_sel3 << 19) |((uint32_t)clk_phase_sel2 << 18) |((uint32_t)clk_phase_sel1 << 17) |((uint32_t)clk_phase_sel0 << 16) |((uint32_t)ckc_sel7 << 14) |((uint32_t)ckc_sel6 << 12) |((uint32_t)ckc_sel5 << 10) |((uint32_t)ckc_sel4 << 8) |((uint32_t)ckc_sel3 << 6) |((uint32_t)ckc_sel2 << 4) |((uint32_t)ckc_sel1 << 2) |((uint32_t)ckc_sel0 << 0));
}

__INLINE void ricu_afe_ctl_7_unpack(uint8_t* comp_sel7, uint8_t* comp_sel6, uint8_t* comp_sel5, uint8_t* comp_sel4, uint8_t* comp_sel3, uint8_t* comp_sel2, uint8_t* comp_sel1, uint8_t* comp_sel0, uint8_t* clk_phase_sel7, uint8_t* clk_phase_sel6, uint8_t* clk_phase_sel5, uint8_t* clk_phase_sel4, uint8_t* clk_phase_sel3, uint8_t* clk_phase_sel2, uint8_t* clk_phase_sel1, uint8_t* clk_phase_sel0, uint8_t* ckc_sel7, uint8_t* ckc_sel6, uint8_t* ckc_sel5, uint8_t* ckc_sel4, uint8_t* ckc_sel3, uint8_t* ckc_sel2, uint8_t* ckc_sel1, uint8_t* ckc_sel0)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_7_ADDR);

	*comp_sel7 = (localVal & ((uint32_t)0x80000000)) >>  31;
	*comp_sel6 = (localVal & ((uint32_t)0x40000000)) >>  30;
	*comp_sel5 = (localVal & ((uint32_t)0x20000000)) >>  29;
	*comp_sel4 = (localVal & ((uint32_t)0x10000000)) >>  28;
	*comp_sel3 = (localVal & ((uint32_t)0x08000000)) >>  27;
	*comp_sel2 = (localVal & ((uint32_t)0x04000000)) >>  26;
	*comp_sel1 = (localVal & ((uint32_t)0x02000000)) >>  25;
	*comp_sel0 = (localVal & ((uint32_t)0x01000000)) >>  24;
	*clk_phase_sel7 = (localVal & ((uint32_t)0x00800000)) >>  23;
	*clk_phase_sel6 = (localVal & ((uint32_t)0x00400000)) >>  22;
	*clk_phase_sel5 = (localVal & ((uint32_t)0x00200000)) >>  21;
	*clk_phase_sel4 = (localVal & ((uint32_t)0x00100000)) >>  20;
	*clk_phase_sel3 = (localVal & ((uint32_t)0x00080000)) >>  19;
	*clk_phase_sel2 = (localVal & ((uint32_t)0x00040000)) >>  18;
	*clk_phase_sel1 = (localVal & ((uint32_t)0x00020000)) >>  17;
	*clk_phase_sel0 = (localVal & ((uint32_t)0x00010000)) >>  16;
	*ckc_sel7 = (localVal & ((uint32_t)0x0000C000)) >>  14;
	*ckc_sel6 = (localVal & ((uint32_t)0x00003000)) >>  12;
	*ckc_sel5 = (localVal & ((uint32_t)0x00000C00)) >>  10;
	*ckc_sel4 = (localVal & ((uint32_t)0x00000300)) >>  8;
	*ckc_sel3 = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*ckc_sel2 = (localVal & ((uint32_t)0x00000030)) >>  4;
	*ckc_sel1 = (localVal & ((uint32_t)0x0000000C)) >>  2;
	*ckc_sel0 = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint8_t ricu_afe_ctl_7_comp_sel_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE void ricu_afe_ctl_7_comp_sel_7_setf(uint8_t compsel7)
{
	ASSERT_ERR((((uint32_t)compsel7 << 31) & ~((uint32_t)0x80000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_7_ADDR, (REG_PL_RD(RICU_AFE_CTL_7_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)compsel7 <<31));
}
__INLINE uint8_t ricu_afe_ctl_7_comp_sel_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x40000000)) >> 30);
}
__INLINE void ricu_afe_ctl_7_comp_sel_6_setf(uint8_t compsel6)
{
	ASSERT_ERR((((uint32_t)compsel6 << 30) & ~((uint32_t)0x40000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_7_ADDR, (REG_PL_RD(RICU_AFE_CTL_7_ADDR) & ~((uint32_t)0x40000000)) | ((uint32_t)compsel6 <<30));
}
__INLINE uint8_t ricu_afe_ctl_7_comp_sel_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x20000000)) >> 29);
}
__INLINE void ricu_afe_ctl_7_comp_sel_5_setf(uint8_t compsel5)
{
	ASSERT_ERR((((uint32_t)compsel5 << 29) & ~((uint32_t)0x20000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_7_ADDR, (REG_PL_RD(RICU_AFE_CTL_7_ADDR) & ~((uint32_t)0x20000000)) | ((uint32_t)compsel5 <<29));
}
__INLINE uint8_t ricu_afe_ctl_7_comp_sel_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x10000000)) >> 28);
}
__INLINE void ricu_afe_ctl_7_comp_sel_4_setf(uint8_t compsel4)
{
	ASSERT_ERR((((uint32_t)compsel4 << 28) & ~((uint32_t)0x10000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_7_ADDR, (REG_PL_RD(RICU_AFE_CTL_7_ADDR) & ~((uint32_t)0x10000000)) | ((uint32_t)compsel4 <<28));
}
__INLINE uint8_t ricu_afe_ctl_7_comp_sel_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x08000000)) >> 27);
}
__INLINE void ricu_afe_ctl_7_comp_sel_3_setf(uint8_t compsel3)
{
	ASSERT_ERR((((uint32_t)compsel3 << 27) & ~((uint32_t)0x08000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_7_ADDR, (REG_PL_RD(RICU_AFE_CTL_7_ADDR) & ~((uint32_t)0x08000000)) | ((uint32_t)compsel3 <<27));
}
__INLINE uint8_t ricu_afe_ctl_7_comp_sel_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x04000000)) >> 26);
}
__INLINE void ricu_afe_ctl_7_comp_sel_2_setf(uint8_t compsel2)
{
	ASSERT_ERR((((uint32_t)compsel2 << 26) & ~((uint32_t)0x04000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_7_ADDR, (REG_PL_RD(RICU_AFE_CTL_7_ADDR) & ~((uint32_t)0x04000000)) | ((uint32_t)compsel2 <<26));
}
__INLINE uint8_t ricu_afe_ctl_7_comp_sel_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x02000000)) >> 25);
}
__INLINE void ricu_afe_ctl_7_comp_sel_1_setf(uint8_t compsel1)
{
	ASSERT_ERR((((uint32_t)compsel1 << 25) & ~((uint32_t)0x02000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_7_ADDR, (REG_PL_RD(RICU_AFE_CTL_7_ADDR) & ~((uint32_t)0x02000000)) | ((uint32_t)compsel1 <<25));
}
__INLINE uint8_t ricu_afe_ctl_7_comp_sel_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01000000)) >> 24);
}
__INLINE void ricu_afe_ctl_7_comp_sel_0_setf(uint8_t compsel0)
{
	ASSERT_ERR((((uint32_t)compsel0 << 24) & ~((uint32_t)0x01000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_7_ADDR, (REG_PL_RD(RICU_AFE_CTL_7_ADDR) & ~((uint32_t)0x01000000)) | ((uint32_t)compsel0 <<24));
}
__INLINE uint8_t ricu_afe_ctl_7_clk_phase_sel_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00800000)) >> 23);
}
__INLINE void ricu_afe_ctl_7_clk_phase_sel_7_setf(uint8_t clkphasesel7)
{
	ASSERT_ERR((((uint32_t)clkphasesel7 << 23) & ~((uint32_t)0x00800000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_7_ADDR, (REG_PL_RD(RICU_AFE_CTL_7_ADDR) & ~((uint32_t)0x00800000)) | ((uint32_t)clkphasesel7 <<23));
}
__INLINE uint8_t ricu_afe_ctl_7_clk_phase_sel_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00400000)) >> 22);
}
__INLINE void ricu_afe_ctl_7_clk_phase_sel_6_setf(uint8_t clkphasesel6)
{
	ASSERT_ERR((((uint32_t)clkphasesel6 << 22) & ~((uint32_t)0x00400000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_7_ADDR, (REG_PL_RD(RICU_AFE_CTL_7_ADDR) & ~((uint32_t)0x00400000)) | ((uint32_t)clkphasesel6 <<22));
}
__INLINE uint8_t ricu_afe_ctl_7_clk_phase_sel_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00200000)) >> 21);
}
__INLINE void ricu_afe_ctl_7_clk_phase_sel_5_setf(uint8_t clkphasesel5)
{
	ASSERT_ERR((((uint32_t)clkphasesel5 << 21) & ~((uint32_t)0x00200000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_7_ADDR, (REG_PL_RD(RICU_AFE_CTL_7_ADDR) & ~((uint32_t)0x00200000)) | ((uint32_t)clkphasesel5 <<21));
}
__INLINE uint8_t ricu_afe_ctl_7_clk_phase_sel_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00100000)) >> 20);
}
__INLINE void ricu_afe_ctl_7_clk_phase_sel_4_setf(uint8_t clkphasesel4)
{
	ASSERT_ERR((((uint32_t)clkphasesel4 << 20) & ~((uint32_t)0x00100000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_7_ADDR, (REG_PL_RD(RICU_AFE_CTL_7_ADDR) & ~((uint32_t)0x00100000)) | ((uint32_t)clkphasesel4 <<20));
}
__INLINE uint8_t ricu_afe_ctl_7_clk_phase_sel_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00080000)) >> 19);
}
__INLINE void ricu_afe_ctl_7_clk_phase_sel_3_setf(uint8_t clkphasesel3)
{
	ASSERT_ERR((((uint32_t)clkphasesel3 << 19) & ~((uint32_t)0x00080000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_7_ADDR, (REG_PL_RD(RICU_AFE_CTL_7_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)clkphasesel3 <<19));
}
__INLINE uint8_t ricu_afe_ctl_7_clk_phase_sel_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00040000)) >> 18);
}
__INLINE void ricu_afe_ctl_7_clk_phase_sel_2_setf(uint8_t clkphasesel2)
{
	ASSERT_ERR((((uint32_t)clkphasesel2 << 18) & ~((uint32_t)0x00040000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_7_ADDR, (REG_PL_RD(RICU_AFE_CTL_7_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)clkphasesel2 <<18));
}
__INLINE uint8_t ricu_afe_ctl_7_clk_phase_sel_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00020000)) >> 17);
}
__INLINE void ricu_afe_ctl_7_clk_phase_sel_1_setf(uint8_t clkphasesel1)
{
	ASSERT_ERR((((uint32_t)clkphasesel1 << 17) & ~((uint32_t)0x00020000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_7_ADDR, (REG_PL_RD(RICU_AFE_CTL_7_ADDR) & ~((uint32_t)0x00020000)) | ((uint32_t)clkphasesel1 <<17));
}
__INLINE uint8_t ricu_afe_ctl_7_clk_phase_sel_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void ricu_afe_ctl_7_clk_phase_sel_0_setf(uint8_t clkphasesel0)
{
	ASSERT_ERR((((uint32_t)clkphasesel0 << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_7_ADDR, (REG_PL_RD(RICU_AFE_CTL_7_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)clkphasesel0 <<16));
}
__INLINE uint8_t ricu_afe_ctl_7_ckc_sel_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000C000)) >> 14);
}
__INLINE void ricu_afe_ctl_7_ckc_sel_7_setf(uint8_t ckcsel7)
{
	ASSERT_ERR((((uint32_t)ckcsel7 << 14) & ~((uint32_t)0x0000C000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_7_ADDR, (REG_PL_RD(RICU_AFE_CTL_7_ADDR) & ~((uint32_t)0x0000C000)) | ((uint32_t)ckcsel7 <<14));
}
__INLINE uint8_t ricu_afe_ctl_7_ckc_sel_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00003000)) >> 12);
}
__INLINE void ricu_afe_ctl_7_ckc_sel_6_setf(uint8_t ckcsel6)
{
	ASSERT_ERR((((uint32_t)ckcsel6 << 12) & ~((uint32_t)0x00003000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_7_ADDR, (REG_PL_RD(RICU_AFE_CTL_7_ADDR) & ~((uint32_t)0x00003000)) | ((uint32_t)ckcsel6 <<12));
}
__INLINE uint8_t ricu_afe_ctl_7_ckc_sel_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000C00)) >> 10);
}
__INLINE void ricu_afe_ctl_7_ckc_sel_5_setf(uint8_t ckcsel5)
{
	ASSERT_ERR((((uint32_t)ckcsel5 << 10) & ~((uint32_t)0x00000C00)) == 0);
	REG_PL_WR(RICU_AFE_CTL_7_ADDR, (REG_PL_RD(RICU_AFE_CTL_7_ADDR) & ~((uint32_t)0x00000C00)) | ((uint32_t)ckcsel5 <<10));
}
__INLINE uint8_t ricu_afe_ctl_7_ckc_sel_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000300)) >> 8);
}
__INLINE void ricu_afe_ctl_7_ckc_sel_4_setf(uint8_t ckcsel4)
{
	ASSERT_ERR((((uint32_t)ckcsel4 << 8) & ~((uint32_t)0x00000300)) == 0);
	REG_PL_WR(RICU_AFE_CTL_7_ADDR, (REG_PL_RD(RICU_AFE_CTL_7_ADDR) & ~((uint32_t)0x00000300)) | ((uint32_t)ckcsel4 <<8));
}
__INLINE uint8_t ricu_afe_ctl_7_ckc_sel_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE void ricu_afe_ctl_7_ckc_sel_3_setf(uint8_t ckcsel3)
{
	ASSERT_ERR((((uint32_t)ckcsel3 << 6) & ~((uint32_t)0x000000C0)) == 0);
	REG_PL_WR(RICU_AFE_CTL_7_ADDR, (REG_PL_RD(RICU_AFE_CTL_7_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)ckcsel3 <<6));
}
__INLINE uint8_t ricu_afe_ctl_7_ckc_sel_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000030)) >> 4);
}
__INLINE void ricu_afe_ctl_7_ckc_sel_2_setf(uint8_t ckcsel2)
{
	ASSERT_ERR((((uint32_t)ckcsel2 << 4) & ~((uint32_t)0x00000030)) == 0);
	REG_PL_WR(RICU_AFE_CTL_7_ADDR, (REG_PL_RD(RICU_AFE_CTL_7_ADDR) & ~((uint32_t)0x00000030)) | ((uint32_t)ckcsel2 <<4));
}
__INLINE uint8_t ricu_afe_ctl_7_ckc_sel_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000C)) >> 2);
}
__INLINE void ricu_afe_ctl_7_ckc_sel_1_setf(uint8_t ckcsel1)
{
	ASSERT_ERR((((uint32_t)ckcsel1 << 2) & ~((uint32_t)0x0000000C)) == 0);
	REG_PL_WR(RICU_AFE_CTL_7_ADDR, (REG_PL_RD(RICU_AFE_CTL_7_ADDR) & ~((uint32_t)0x0000000C)) | ((uint32_t)ckcsel1 <<2));
}
__INLINE uint8_t ricu_afe_ctl_7_ckc_sel_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void ricu_afe_ctl_7_ckc_sel_0_setf(uint8_t ckcsel0)
{
	ASSERT_ERR((((uint32_t)ckcsel0 << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RICU_AFE_CTL_7_ADDR, (REG_PL_RD(RICU_AFE_CTL_7_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)ckcsel0 <<0));
}

/**
 * @brief AFE_CTL_8 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    EN_REF7                   0              
 *    30    EN_REF6                   0              
 *    29    EN_REF5                   0              
 *    28    EN_REF4                   0              
 *    27    EN_REF3                   0              
 *    26    EN_REF2                   0              
 *    25    EN_REF1                   0              
 *    24    EN_REF0                   0              
 *    23    EN_EXT_LOAD7              0              
 *    22    EN_EXT_LOAD6              0              
 *    21    EN_EXT_LOAD5              0              
 *    20    EN_EXT_LOAD4              0              
 *    19    EN_EXT_LOAD3              0              
 *    18    EN_EXT_LOAD2              0              
 *    17    EN_EXT_LOAD1              0              
 *    16    EN_EXT_LOAD0              0              
 *    15    CH_CML_SEL7               0              
 *    14    CH_CML_SEL6               0              
 *    13    CH_CML_SEL5               0              
 *    12    CH_CML_SEL4               0              
 *    11    CH_CML_SEL3               0              
 *    10    CH_CML_SEL2               0              
 *    09    CH_CML_SEL1               0              
 *    08    CH_CML_SEL0               0              
 *    07    EN_BGR7                   0              
 *    06    EN_BGR6                   0              
 *    05    EN_BGR5                   0              
 *    04    EN_BGR4                   0              
 *    03    EN_BGR3                   0              
 *    02    EN_BGR2                   0              
 *    01    EN_BGR1                   0              
 *    00    EN_BGR0                   0              
 * </pre>
 */
#define RICU_AFE_CTL_8_ADDR        (REG_RICU_BASE_ADDR+0x00000030)
#define RICU_AFE_CTL_8_OFFSET      0x00000030
#define RICU_AFE_CTL_8_INDEX       0x0000000C
#define RICU_AFE_CTL_8_RESET       0x00000000

__INLINE uint32_t  ricu_afe_ctl_8_get(void)
{
	return REG_PL_RD(RICU_AFE_CTL_8_ADDR);
}

__INLINE void ricu_afe_ctl_8_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTL_8_ADDR, value);
}

// field definitions
#define RICU_AFE_CTL_8_EN_REF_7_BIT         ((uint32_t)0x80000000)
#define RICU_AFE_CTL_8_EN_REF_7_POS         31
#define RICU_AFE_CTL_8_EN_REF_6_BIT         ((uint32_t)0x40000000)
#define RICU_AFE_CTL_8_EN_REF_6_POS         30
#define RICU_AFE_CTL_8_EN_REF_5_BIT         ((uint32_t)0x20000000)
#define RICU_AFE_CTL_8_EN_REF_5_POS         29
#define RICU_AFE_CTL_8_EN_REF_4_BIT         ((uint32_t)0x10000000)
#define RICU_AFE_CTL_8_EN_REF_4_POS         28
#define RICU_AFE_CTL_8_EN_REF_3_BIT         ((uint32_t)0x08000000)
#define RICU_AFE_CTL_8_EN_REF_3_POS         27
#define RICU_AFE_CTL_8_EN_REF_2_BIT         ((uint32_t)0x04000000)
#define RICU_AFE_CTL_8_EN_REF_2_POS         26
#define RICU_AFE_CTL_8_EN_REF_1_BIT         ((uint32_t)0x02000000)
#define RICU_AFE_CTL_8_EN_REF_1_POS         25
#define RICU_AFE_CTL_8_EN_REF_0_BIT         ((uint32_t)0x01000000)
#define RICU_AFE_CTL_8_EN_REF_0_POS         24
#define RICU_AFE_CTL_8_EN_EXT_LOAD_7_BIT    ((uint32_t)0x00800000)
#define RICU_AFE_CTL_8_EN_EXT_LOAD_7_POS    23
#define RICU_AFE_CTL_8_EN_EXT_LOAD_6_BIT    ((uint32_t)0x00400000)
#define RICU_AFE_CTL_8_EN_EXT_LOAD_6_POS    22
#define RICU_AFE_CTL_8_EN_EXT_LOAD_5_BIT    ((uint32_t)0x00200000)
#define RICU_AFE_CTL_8_EN_EXT_LOAD_5_POS    21
#define RICU_AFE_CTL_8_EN_EXT_LOAD_4_BIT    ((uint32_t)0x00100000)
#define RICU_AFE_CTL_8_EN_EXT_LOAD_4_POS    20
#define RICU_AFE_CTL_8_EN_EXT_LOAD_3_BIT    ((uint32_t)0x00080000)
#define RICU_AFE_CTL_8_EN_EXT_LOAD_3_POS    19
#define RICU_AFE_CTL_8_EN_EXT_LOAD_2_BIT    ((uint32_t)0x00040000)
#define RICU_AFE_CTL_8_EN_EXT_LOAD_2_POS    18
#define RICU_AFE_CTL_8_EN_EXT_LOAD_1_BIT    ((uint32_t)0x00020000)
#define RICU_AFE_CTL_8_EN_EXT_LOAD_1_POS    17
#define RICU_AFE_CTL_8_EN_EXT_LOAD_0_BIT    ((uint32_t)0x00010000)
#define RICU_AFE_CTL_8_EN_EXT_LOAD_0_POS    16
#define RICU_AFE_CTL_8_CH_CML_SEL_7_BIT     ((uint32_t)0x00008000)
#define RICU_AFE_CTL_8_CH_CML_SEL_7_POS     15
#define RICU_AFE_CTL_8_CH_CML_SEL_6_BIT     ((uint32_t)0x00004000)
#define RICU_AFE_CTL_8_CH_CML_SEL_6_POS     14
#define RICU_AFE_CTL_8_CH_CML_SEL_5_BIT     ((uint32_t)0x00002000)
#define RICU_AFE_CTL_8_CH_CML_SEL_5_POS     13
#define RICU_AFE_CTL_8_CH_CML_SEL_4_BIT     ((uint32_t)0x00001000)
#define RICU_AFE_CTL_8_CH_CML_SEL_4_POS     12
#define RICU_AFE_CTL_8_CH_CML_SEL_3_BIT     ((uint32_t)0x00000800)
#define RICU_AFE_CTL_8_CH_CML_SEL_3_POS     11
#define RICU_AFE_CTL_8_CH_CML_SEL_2_BIT     ((uint32_t)0x00000400)
#define RICU_AFE_CTL_8_CH_CML_SEL_2_POS     10
#define RICU_AFE_CTL_8_CH_CML_SEL_1_BIT     ((uint32_t)0x00000200)
#define RICU_AFE_CTL_8_CH_CML_SEL_1_POS     9
#define RICU_AFE_CTL_8_CH_CML_SEL_0_BIT     ((uint32_t)0x00000100)
#define RICU_AFE_CTL_8_CH_CML_SEL_0_POS     8
#define RICU_AFE_CTL_8_EN_BGR_7_BIT         ((uint32_t)0x00000080)
#define RICU_AFE_CTL_8_EN_BGR_7_POS         7
#define RICU_AFE_CTL_8_EN_BGR_6_BIT         ((uint32_t)0x00000040)
#define RICU_AFE_CTL_8_EN_BGR_6_POS         6
#define RICU_AFE_CTL_8_EN_BGR_5_BIT         ((uint32_t)0x00000020)
#define RICU_AFE_CTL_8_EN_BGR_5_POS         5
#define RICU_AFE_CTL_8_EN_BGR_4_BIT         ((uint32_t)0x00000010)
#define RICU_AFE_CTL_8_EN_BGR_4_POS         4
#define RICU_AFE_CTL_8_EN_BGR_3_BIT         ((uint32_t)0x00000008)
#define RICU_AFE_CTL_8_EN_BGR_3_POS         3
#define RICU_AFE_CTL_8_EN_BGR_2_BIT         ((uint32_t)0x00000004)
#define RICU_AFE_CTL_8_EN_BGR_2_POS         2
#define RICU_AFE_CTL_8_EN_BGR_1_BIT         ((uint32_t)0x00000002)
#define RICU_AFE_CTL_8_EN_BGR_1_POS         1
#define RICU_AFE_CTL_8_EN_BGR_0_BIT         ((uint32_t)0x00000001)
#define RICU_AFE_CTL_8_EN_BGR_0_POS         0

#define RICU_AFE_CTL_8_EN_REF_7_RST         0x0
#define RICU_AFE_CTL_8_EN_REF_6_RST         0x0
#define RICU_AFE_CTL_8_EN_REF_5_RST         0x0
#define RICU_AFE_CTL_8_EN_REF_4_RST         0x0
#define RICU_AFE_CTL_8_EN_REF_3_RST         0x0
#define RICU_AFE_CTL_8_EN_REF_2_RST         0x0
#define RICU_AFE_CTL_8_EN_REF_1_RST         0x0
#define RICU_AFE_CTL_8_EN_REF_0_RST         0x0
#define RICU_AFE_CTL_8_EN_EXT_LOAD_7_RST    0x0
#define RICU_AFE_CTL_8_EN_EXT_LOAD_6_RST    0x0
#define RICU_AFE_CTL_8_EN_EXT_LOAD_5_RST    0x0
#define RICU_AFE_CTL_8_EN_EXT_LOAD_4_RST    0x0
#define RICU_AFE_CTL_8_EN_EXT_LOAD_3_RST    0x0
#define RICU_AFE_CTL_8_EN_EXT_LOAD_2_RST    0x0
#define RICU_AFE_CTL_8_EN_EXT_LOAD_1_RST    0x0
#define RICU_AFE_CTL_8_EN_EXT_LOAD_0_RST    0x0
#define RICU_AFE_CTL_8_CH_CML_SEL_7_RST     0x0
#define RICU_AFE_CTL_8_CH_CML_SEL_6_RST     0x0
#define RICU_AFE_CTL_8_CH_CML_SEL_5_RST     0x0
#define RICU_AFE_CTL_8_CH_CML_SEL_4_RST     0x0
#define RICU_AFE_CTL_8_CH_CML_SEL_3_RST     0x0
#define RICU_AFE_CTL_8_CH_CML_SEL_2_RST     0x0
#define RICU_AFE_CTL_8_CH_CML_SEL_1_RST     0x0
#define RICU_AFE_CTL_8_CH_CML_SEL_0_RST     0x0
#define RICU_AFE_CTL_8_EN_BGR_7_RST         0x0
#define RICU_AFE_CTL_8_EN_BGR_6_RST         0x0
#define RICU_AFE_CTL_8_EN_BGR_5_RST         0x0
#define RICU_AFE_CTL_8_EN_BGR_4_RST         0x0
#define RICU_AFE_CTL_8_EN_BGR_3_RST         0x0
#define RICU_AFE_CTL_8_EN_BGR_2_RST         0x0
#define RICU_AFE_CTL_8_EN_BGR_1_RST         0x0
#define RICU_AFE_CTL_8_EN_BGR_0_RST         0x0

__INLINE void ricu_afe_ctl_8_pack(uint8_t en_ref7, uint8_t en_ref6, uint8_t en_ref5, uint8_t en_ref4, uint8_t en_ref3, uint8_t en_ref2, uint8_t en_ref1, uint8_t en_ref0, uint8_t en_ext_load7, uint8_t en_ext_load6, uint8_t en_ext_load5, uint8_t en_ext_load4, uint8_t en_ext_load3, uint8_t en_ext_load2, uint8_t en_ext_load1, uint8_t en_ext_load0, uint8_t ch_cml_sel7, uint8_t ch_cml_sel6, uint8_t ch_cml_sel5, uint8_t ch_cml_sel4, uint8_t ch_cml_sel3, uint8_t ch_cml_sel2, uint8_t ch_cml_sel1, uint8_t ch_cml_sel0, uint8_t en_bgr7, uint8_t en_bgr6, uint8_t en_bgr5, uint8_t en_bgr4, uint8_t en_bgr3, uint8_t en_bgr2, uint8_t en_bgr1, uint8_t en_bgr0)
{
	ASSERT_ERR((((uint32_t)en_ref7 << 31) & ~((uint32_t)0x80000000)) == 0);
	ASSERT_ERR((((uint32_t)en_ref6 << 30) & ~((uint32_t)0x40000000)) == 0);
	ASSERT_ERR((((uint32_t)en_ref5 << 29) & ~((uint32_t)0x20000000)) == 0);
	ASSERT_ERR((((uint32_t)en_ref4 << 28) & ~((uint32_t)0x10000000)) == 0);
	ASSERT_ERR((((uint32_t)en_ref3 << 27) & ~((uint32_t)0x08000000)) == 0);
	ASSERT_ERR((((uint32_t)en_ref2 << 26) & ~((uint32_t)0x04000000)) == 0);
	ASSERT_ERR((((uint32_t)en_ref1 << 25) & ~((uint32_t)0x02000000)) == 0);
	ASSERT_ERR((((uint32_t)en_ref0 << 24) & ~((uint32_t)0x01000000)) == 0);
	ASSERT_ERR((((uint32_t)en_ext_load7 << 23) & ~((uint32_t)0x00800000)) == 0);
	ASSERT_ERR((((uint32_t)en_ext_load6 << 22) & ~((uint32_t)0x00400000)) == 0);
	ASSERT_ERR((((uint32_t)en_ext_load5 << 21) & ~((uint32_t)0x00200000)) == 0);
	ASSERT_ERR((((uint32_t)en_ext_load4 << 20) & ~((uint32_t)0x00100000)) == 0);
	ASSERT_ERR((((uint32_t)en_ext_load3 << 19) & ~((uint32_t)0x00080000)) == 0);
	ASSERT_ERR((((uint32_t)en_ext_load2 << 18) & ~((uint32_t)0x00040000)) == 0);
	ASSERT_ERR((((uint32_t)en_ext_load1 << 17) & ~((uint32_t)0x00020000)) == 0);
	ASSERT_ERR((((uint32_t)en_ext_load0 << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)ch_cml_sel7 << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)ch_cml_sel6 << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)ch_cml_sel5 << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)ch_cml_sel4 << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)ch_cml_sel3 << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)ch_cml_sel2 << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)ch_cml_sel1 << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)ch_cml_sel0 << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)en_bgr7 << 7) & ~((uint32_t)0x00000080)) == 0);
	ASSERT_ERR((((uint32_t)en_bgr6 << 6) & ~((uint32_t)0x00000040)) == 0);
	ASSERT_ERR((((uint32_t)en_bgr5 << 5) & ~((uint32_t)0x00000020)) == 0);
	ASSERT_ERR((((uint32_t)en_bgr4 << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)en_bgr3 << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)en_bgr2 << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)en_bgr1 << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)en_bgr0 << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RICU_AFE_CTL_8_ADDR,  ((uint32_t)en_ref7 << 31) |((uint32_t)en_ref6 << 30) |((uint32_t)en_ref5 << 29) |((uint32_t)en_ref4 << 28) |((uint32_t)en_ref3 << 27) |((uint32_t)en_ref2 << 26) |((uint32_t)en_ref1 << 25) |((uint32_t)en_ref0 << 24) |((uint32_t)en_ext_load7 << 23) |((uint32_t)en_ext_load6 << 22) |((uint32_t)en_ext_load5 << 21) |((uint32_t)en_ext_load4 << 20) |((uint32_t)en_ext_load3 << 19) |((uint32_t)en_ext_load2 << 18) |((uint32_t)en_ext_load1 << 17) |((uint32_t)en_ext_load0 << 16) |((uint32_t)ch_cml_sel7 << 15) |((uint32_t)ch_cml_sel6 << 14) |((uint32_t)ch_cml_sel5 << 13) |((uint32_t)ch_cml_sel4 << 12) |((uint32_t)ch_cml_sel3 << 11) |((uint32_t)ch_cml_sel2 << 10) |((uint32_t)ch_cml_sel1 << 9) |((uint32_t)ch_cml_sel0 << 8) |((uint32_t)en_bgr7 << 7) |((uint32_t)en_bgr6 << 6) |((uint32_t)en_bgr5 << 5) |((uint32_t)en_bgr4 << 4) |((uint32_t)en_bgr3 << 3) |((uint32_t)en_bgr2 << 2) |((uint32_t)en_bgr1 << 1) |((uint32_t)en_bgr0 << 0));
}

__INLINE void ricu_afe_ctl_8_unpack(uint8_t* en_ref7, uint8_t* en_ref6, uint8_t* en_ref5, uint8_t* en_ref4, uint8_t* en_ref3, uint8_t* en_ref2, uint8_t* en_ref1, uint8_t* en_ref0, uint8_t* en_ext_load7, uint8_t* en_ext_load6, uint8_t* en_ext_load5, uint8_t* en_ext_load4, uint8_t* en_ext_load3, uint8_t* en_ext_load2, uint8_t* en_ext_load1, uint8_t* en_ext_load0, uint8_t* ch_cml_sel7, uint8_t* ch_cml_sel6, uint8_t* ch_cml_sel5, uint8_t* ch_cml_sel4, uint8_t* ch_cml_sel3, uint8_t* ch_cml_sel2, uint8_t* ch_cml_sel1, uint8_t* ch_cml_sel0, uint8_t* en_bgr7, uint8_t* en_bgr6, uint8_t* en_bgr5, uint8_t* en_bgr4, uint8_t* en_bgr3, uint8_t* en_bgr2, uint8_t* en_bgr1, uint8_t* en_bgr0)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_8_ADDR);

	*en_ref7 = (localVal & ((uint32_t)0x80000000)) >>  31;
	*en_ref6 = (localVal & ((uint32_t)0x40000000)) >>  30;
	*en_ref5 = (localVal & ((uint32_t)0x20000000)) >>  29;
	*en_ref4 = (localVal & ((uint32_t)0x10000000)) >>  28;
	*en_ref3 = (localVal & ((uint32_t)0x08000000)) >>  27;
	*en_ref2 = (localVal & ((uint32_t)0x04000000)) >>  26;
	*en_ref1 = (localVal & ((uint32_t)0x02000000)) >>  25;
	*en_ref0 = (localVal & ((uint32_t)0x01000000)) >>  24;
	*en_ext_load7 = (localVal & ((uint32_t)0x00800000)) >>  23;
	*en_ext_load6 = (localVal & ((uint32_t)0x00400000)) >>  22;
	*en_ext_load5 = (localVal & ((uint32_t)0x00200000)) >>  21;
	*en_ext_load4 = (localVal & ((uint32_t)0x00100000)) >>  20;
	*en_ext_load3 = (localVal & ((uint32_t)0x00080000)) >>  19;
	*en_ext_load2 = (localVal & ((uint32_t)0x00040000)) >>  18;
	*en_ext_load1 = (localVal & ((uint32_t)0x00020000)) >>  17;
	*en_ext_load0 = (localVal & ((uint32_t)0x00010000)) >>  16;
	*ch_cml_sel7 = (localVal & ((uint32_t)0x00008000)) >>  15;
	*ch_cml_sel6 = (localVal & ((uint32_t)0x00004000)) >>  14;
	*ch_cml_sel5 = (localVal & ((uint32_t)0x00002000)) >>  13;
	*ch_cml_sel4 = (localVal & ((uint32_t)0x00001000)) >>  12;
	*ch_cml_sel3 = (localVal & ((uint32_t)0x00000800)) >>  11;
	*ch_cml_sel2 = (localVal & ((uint32_t)0x00000400)) >>  10;
	*ch_cml_sel1 = (localVal & ((uint32_t)0x00000200)) >>  9;
	*ch_cml_sel0 = (localVal & ((uint32_t)0x00000100)) >>  8;
	*en_bgr7 = (localVal & ((uint32_t)0x00000080)) >>  7;
	*en_bgr6 = (localVal & ((uint32_t)0x00000040)) >>  6;
	*en_bgr5 = (localVal & ((uint32_t)0x00000020)) >>  5;
	*en_bgr4 = (localVal & ((uint32_t)0x00000010)) >>  4;
	*en_bgr3 = (localVal & ((uint32_t)0x00000008)) >>  3;
	*en_bgr2 = (localVal & ((uint32_t)0x00000004)) >>  2;
	*en_bgr1 = (localVal & ((uint32_t)0x00000002)) >>  1;
	*en_bgr0 = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t ricu_afe_ctl_8_en_ref_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE void ricu_afe_ctl_8_en_ref_7_setf(uint8_t enref7)
{
	ASSERT_ERR((((uint32_t)enref7 << 31) & ~((uint32_t)0x80000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_8_ADDR, (REG_PL_RD(RICU_AFE_CTL_8_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)enref7 <<31));
}
__INLINE uint8_t ricu_afe_ctl_8_en_ref_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x40000000)) >> 30);
}
__INLINE void ricu_afe_ctl_8_en_ref_6_setf(uint8_t enref6)
{
	ASSERT_ERR((((uint32_t)enref6 << 30) & ~((uint32_t)0x40000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_8_ADDR, (REG_PL_RD(RICU_AFE_CTL_8_ADDR) & ~((uint32_t)0x40000000)) | ((uint32_t)enref6 <<30));
}
__INLINE uint8_t ricu_afe_ctl_8_en_ref_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x20000000)) >> 29);
}
__INLINE void ricu_afe_ctl_8_en_ref_5_setf(uint8_t enref5)
{
	ASSERT_ERR((((uint32_t)enref5 << 29) & ~((uint32_t)0x20000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_8_ADDR, (REG_PL_RD(RICU_AFE_CTL_8_ADDR) & ~((uint32_t)0x20000000)) | ((uint32_t)enref5 <<29));
}
__INLINE uint8_t ricu_afe_ctl_8_en_ref_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x10000000)) >> 28);
}
__INLINE void ricu_afe_ctl_8_en_ref_4_setf(uint8_t enref4)
{
	ASSERT_ERR((((uint32_t)enref4 << 28) & ~((uint32_t)0x10000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_8_ADDR, (REG_PL_RD(RICU_AFE_CTL_8_ADDR) & ~((uint32_t)0x10000000)) | ((uint32_t)enref4 <<28));
}
__INLINE uint8_t ricu_afe_ctl_8_en_ref_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x08000000)) >> 27);
}
__INLINE void ricu_afe_ctl_8_en_ref_3_setf(uint8_t enref3)
{
	ASSERT_ERR((((uint32_t)enref3 << 27) & ~((uint32_t)0x08000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_8_ADDR, (REG_PL_RD(RICU_AFE_CTL_8_ADDR) & ~((uint32_t)0x08000000)) | ((uint32_t)enref3 <<27));
}
__INLINE uint8_t ricu_afe_ctl_8_en_ref_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x04000000)) >> 26);
}
__INLINE void ricu_afe_ctl_8_en_ref_2_setf(uint8_t enref2)
{
	ASSERT_ERR((((uint32_t)enref2 << 26) & ~((uint32_t)0x04000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_8_ADDR, (REG_PL_RD(RICU_AFE_CTL_8_ADDR) & ~((uint32_t)0x04000000)) | ((uint32_t)enref2 <<26));
}
__INLINE uint8_t ricu_afe_ctl_8_en_ref_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x02000000)) >> 25);
}
__INLINE void ricu_afe_ctl_8_en_ref_1_setf(uint8_t enref1)
{
	ASSERT_ERR((((uint32_t)enref1 << 25) & ~((uint32_t)0x02000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_8_ADDR, (REG_PL_RD(RICU_AFE_CTL_8_ADDR) & ~((uint32_t)0x02000000)) | ((uint32_t)enref1 <<25));
}
__INLINE uint8_t ricu_afe_ctl_8_en_ref_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01000000)) >> 24);
}
__INLINE void ricu_afe_ctl_8_en_ref_0_setf(uint8_t enref0)
{
	ASSERT_ERR((((uint32_t)enref0 << 24) & ~((uint32_t)0x01000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_8_ADDR, (REG_PL_RD(RICU_AFE_CTL_8_ADDR) & ~((uint32_t)0x01000000)) | ((uint32_t)enref0 <<24));
}
__INLINE uint8_t ricu_afe_ctl_8_en_ext_load_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00800000)) >> 23);
}
__INLINE void ricu_afe_ctl_8_en_ext_load_7_setf(uint8_t enextload7)
{
	ASSERT_ERR((((uint32_t)enextload7 << 23) & ~((uint32_t)0x00800000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_8_ADDR, (REG_PL_RD(RICU_AFE_CTL_8_ADDR) & ~((uint32_t)0x00800000)) | ((uint32_t)enextload7 <<23));
}
__INLINE uint8_t ricu_afe_ctl_8_en_ext_load_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00400000)) >> 22);
}
__INLINE void ricu_afe_ctl_8_en_ext_load_6_setf(uint8_t enextload6)
{
	ASSERT_ERR((((uint32_t)enextload6 << 22) & ~((uint32_t)0x00400000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_8_ADDR, (REG_PL_RD(RICU_AFE_CTL_8_ADDR) & ~((uint32_t)0x00400000)) | ((uint32_t)enextload6 <<22));
}
__INLINE uint8_t ricu_afe_ctl_8_en_ext_load_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00200000)) >> 21);
}
__INLINE void ricu_afe_ctl_8_en_ext_load_5_setf(uint8_t enextload5)
{
	ASSERT_ERR((((uint32_t)enextload5 << 21) & ~((uint32_t)0x00200000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_8_ADDR, (REG_PL_RD(RICU_AFE_CTL_8_ADDR) & ~((uint32_t)0x00200000)) | ((uint32_t)enextload5 <<21));
}
__INLINE uint8_t ricu_afe_ctl_8_en_ext_load_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00100000)) >> 20);
}
__INLINE void ricu_afe_ctl_8_en_ext_load_4_setf(uint8_t enextload4)
{
	ASSERT_ERR((((uint32_t)enextload4 << 20) & ~((uint32_t)0x00100000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_8_ADDR, (REG_PL_RD(RICU_AFE_CTL_8_ADDR) & ~((uint32_t)0x00100000)) | ((uint32_t)enextload4 <<20));
}
__INLINE uint8_t ricu_afe_ctl_8_en_ext_load_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00080000)) >> 19);
}
__INLINE void ricu_afe_ctl_8_en_ext_load_3_setf(uint8_t enextload3)
{
	ASSERT_ERR((((uint32_t)enextload3 << 19) & ~((uint32_t)0x00080000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_8_ADDR, (REG_PL_RD(RICU_AFE_CTL_8_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)enextload3 <<19));
}
__INLINE uint8_t ricu_afe_ctl_8_en_ext_load_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00040000)) >> 18);
}
__INLINE void ricu_afe_ctl_8_en_ext_load_2_setf(uint8_t enextload2)
{
	ASSERT_ERR((((uint32_t)enextload2 << 18) & ~((uint32_t)0x00040000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_8_ADDR, (REG_PL_RD(RICU_AFE_CTL_8_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)enextload2 <<18));
}
__INLINE uint8_t ricu_afe_ctl_8_en_ext_load_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00020000)) >> 17);
}
__INLINE void ricu_afe_ctl_8_en_ext_load_1_setf(uint8_t enextload1)
{
	ASSERT_ERR((((uint32_t)enextload1 << 17) & ~((uint32_t)0x00020000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_8_ADDR, (REG_PL_RD(RICU_AFE_CTL_8_ADDR) & ~((uint32_t)0x00020000)) | ((uint32_t)enextload1 <<17));
}
__INLINE uint8_t ricu_afe_ctl_8_en_ext_load_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void ricu_afe_ctl_8_en_ext_load_0_setf(uint8_t enextload0)
{
	ASSERT_ERR((((uint32_t)enextload0 << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_8_ADDR, (REG_PL_RD(RICU_AFE_CTL_8_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)enextload0 <<16));
}
__INLINE uint8_t ricu_afe_ctl_8_ch_cml_sel_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void ricu_afe_ctl_8_ch_cml_sel_7_setf(uint8_t chcmlsel7)
{
	ASSERT_ERR((((uint32_t)chcmlsel7 << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_8_ADDR, (REG_PL_RD(RICU_AFE_CTL_8_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)chcmlsel7 <<15));
}
__INLINE uint8_t ricu_afe_ctl_8_ch_cml_sel_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void ricu_afe_ctl_8_ch_cml_sel_6_setf(uint8_t chcmlsel6)
{
	ASSERT_ERR((((uint32_t)chcmlsel6 << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_8_ADDR, (REG_PL_RD(RICU_AFE_CTL_8_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)chcmlsel6 <<14));
}
__INLINE uint8_t ricu_afe_ctl_8_ch_cml_sel_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void ricu_afe_ctl_8_ch_cml_sel_5_setf(uint8_t chcmlsel5)
{
	ASSERT_ERR((((uint32_t)chcmlsel5 << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_8_ADDR, (REG_PL_RD(RICU_AFE_CTL_8_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)chcmlsel5 <<13));
}
__INLINE uint8_t ricu_afe_ctl_8_ch_cml_sel_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void ricu_afe_ctl_8_ch_cml_sel_4_setf(uint8_t chcmlsel4)
{
	ASSERT_ERR((((uint32_t)chcmlsel4 << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_8_ADDR, (REG_PL_RD(RICU_AFE_CTL_8_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)chcmlsel4 <<12));
}
__INLINE uint8_t ricu_afe_ctl_8_ch_cml_sel_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void ricu_afe_ctl_8_ch_cml_sel_3_setf(uint8_t chcmlsel3)
{
	ASSERT_ERR((((uint32_t)chcmlsel3 << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(RICU_AFE_CTL_8_ADDR, (REG_PL_RD(RICU_AFE_CTL_8_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)chcmlsel3 <<11));
}
__INLINE uint8_t ricu_afe_ctl_8_ch_cml_sel_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void ricu_afe_ctl_8_ch_cml_sel_2_setf(uint8_t chcmlsel2)
{
	ASSERT_ERR((((uint32_t)chcmlsel2 << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(RICU_AFE_CTL_8_ADDR, (REG_PL_RD(RICU_AFE_CTL_8_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)chcmlsel2 <<10));
}
__INLINE uint8_t ricu_afe_ctl_8_ch_cml_sel_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void ricu_afe_ctl_8_ch_cml_sel_1_setf(uint8_t chcmlsel1)
{
	ASSERT_ERR((((uint32_t)chcmlsel1 << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(RICU_AFE_CTL_8_ADDR, (REG_PL_RD(RICU_AFE_CTL_8_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)chcmlsel1 <<9));
}
__INLINE uint8_t ricu_afe_ctl_8_ch_cml_sel_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void ricu_afe_ctl_8_ch_cml_sel_0_setf(uint8_t chcmlsel0)
{
	ASSERT_ERR((((uint32_t)chcmlsel0 << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(RICU_AFE_CTL_8_ADDR, (REG_PL_RD(RICU_AFE_CTL_8_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)chcmlsel0 <<8));
}
__INLINE uint8_t ricu_afe_ctl_8_en_bgr_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE void ricu_afe_ctl_8_en_bgr_7_setf(uint8_t enbgr7)
{
	ASSERT_ERR((((uint32_t)enbgr7 << 7) & ~((uint32_t)0x00000080)) == 0);
	REG_PL_WR(RICU_AFE_CTL_8_ADDR, (REG_PL_RD(RICU_AFE_CTL_8_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)enbgr7 <<7));
}
__INLINE uint8_t ricu_afe_ctl_8_en_bgr_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE void ricu_afe_ctl_8_en_bgr_6_setf(uint8_t enbgr6)
{
	ASSERT_ERR((((uint32_t)enbgr6 << 6) & ~((uint32_t)0x00000040)) == 0);
	REG_PL_WR(RICU_AFE_CTL_8_ADDR, (REG_PL_RD(RICU_AFE_CTL_8_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)enbgr6 <<6));
}
__INLINE uint8_t ricu_afe_ctl_8_en_bgr_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE void ricu_afe_ctl_8_en_bgr_5_setf(uint8_t enbgr5)
{
	ASSERT_ERR((((uint32_t)enbgr5 << 5) & ~((uint32_t)0x00000020)) == 0);
	REG_PL_WR(RICU_AFE_CTL_8_ADDR, (REG_PL_RD(RICU_AFE_CTL_8_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)enbgr5 <<5));
}
__INLINE uint8_t ricu_afe_ctl_8_en_bgr_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void ricu_afe_ctl_8_en_bgr_4_setf(uint8_t enbgr4)
{
	ASSERT_ERR((((uint32_t)enbgr4 << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(RICU_AFE_CTL_8_ADDR, (REG_PL_RD(RICU_AFE_CTL_8_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)enbgr4 <<4));
}
__INLINE uint8_t ricu_afe_ctl_8_en_bgr_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void ricu_afe_ctl_8_en_bgr_3_setf(uint8_t enbgr3)
{
	ASSERT_ERR((((uint32_t)enbgr3 << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(RICU_AFE_CTL_8_ADDR, (REG_PL_RD(RICU_AFE_CTL_8_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)enbgr3 <<3));
}
__INLINE uint8_t ricu_afe_ctl_8_en_bgr_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void ricu_afe_ctl_8_en_bgr_2_setf(uint8_t enbgr2)
{
	ASSERT_ERR((((uint32_t)enbgr2 << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(RICU_AFE_CTL_8_ADDR, (REG_PL_RD(RICU_AFE_CTL_8_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)enbgr2 <<2));
}
__INLINE uint8_t ricu_afe_ctl_8_en_bgr_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void ricu_afe_ctl_8_en_bgr_1_setf(uint8_t enbgr1)
{
	ASSERT_ERR((((uint32_t)enbgr1 << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(RICU_AFE_CTL_8_ADDR, (REG_PL_RD(RICU_AFE_CTL_8_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)enbgr1 <<1));
}
__INLINE uint8_t ricu_afe_ctl_8_en_bgr_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void ricu_afe_ctl_8_en_bgr_0_setf(uint8_t enbgr0)
{
	ASSERT_ERR((((uint32_t)enbgr0 << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RICU_AFE_CTL_8_ADDR, (REG_PL_RD(RICU_AFE_CTL_8_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)enbgr0 <<0));
}

/**
 * @brief AFE_CTL_9 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    EN_SIN2_BIAS7             1              
 *    30    EN_SIN2_BIAS6             1              
 *    29    EN_SIN2_BIAS5             1              
 *    28    EN_SIN2_BIAS4             1              
 *    27    EN_SIN2_BIAS3             1              
 *    26    EN_SIN2_BIAS2             1              
 *    25    EN_SIN2_BIAS1             1              
 *    24    EN_SIN2_BIAS0             1              
 *    23    EN_DAC_REF7               0              
 *    22    EN_DAC_REF6               0              
 *    21    EN_DAC_REF5               0              
 *    20    EN_DAC_REF4               0              
 *    19    EN_DAC_REF3               0              
 *    18    EN_DAC_REF2               0              
 *    17    EN_DAC_REF1               0              
 *    16    EN_DAC_REF0               0              
 * </pre>
 */
#define RICU_AFE_CTL_9_ADDR        (REG_RICU_BASE_ADDR+0x00000034)
#define RICU_AFE_CTL_9_OFFSET      0x00000034
#define RICU_AFE_CTL_9_INDEX       0x0000000D
#define RICU_AFE_CTL_9_RESET       0xFF000000

__INLINE uint32_t  ricu_afe_ctl_9_get(void)
{
	return REG_PL_RD(RICU_AFE_CTL_9_ADDR);
}

__INLINE void ricu_afe_ctl_9_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTL_9_ADDR, value);
}

// field definitions
#define RICU_AFE_CTL_9_EN_SIN_2_BIAS_7_BIT    ((uint32_t)0x80000000)
#define RICU_AFE_CTL_9_EN_SIN_2_BIAS_7_POS    31
#define RICU_AFE_CTL_9_EN_SIN_2_BIAS_6_BIT    ((uint32_t)0x40000000)
#define RICU_AFE_CTL_9_EN_SIN_2_BIAS_6_POS    30
#define RICU_AFE_CTL_9_EN_SIN_2_BIAS_5_BIT    ((uint32_t)0x20000000)
#define RICU_AFE_CTL_9_EN_SIN_2_BIAS_5_POS    29
#define RICU_AFE_CTL_9_EN_SIN_2_BIAS_4_BIT    ((uint32_t)0x10000000)
#define RICU_AFE_CTL_9_EN_SIN_2_BIAS_4_POS    28
#define RICU_AFE_CTL_9_EN_SIN_2_BIAS_3_BIT    ((uint32_t)0x08000000)
#define RICU_AFE_CTL_9_EN_SIN_2_BIAS_3_POS    27
#define RICU_AFE_CTL_9_EN_SIN_2_BIAS_2_BIT    ((uint32_t)0x04000000)
#define RICU_AFE_CTL_9_EN_SIN_2_BIAS_2_POS    26
#define RICU_AFE_CTL_9_EN_SIN_2_BIAS_1_BIT    ((uint32_t)0x02000000)
#define RICU_AFE_CTL_9_EN_SIN_2_BIAS_1_POS    25
#define RICU_AFE_CTL_9_EN_SIN_2_BIAS_0_BIT    ((uint32_t)0x01000000)
#define RICU_AFE_CTL_9_EN_SIN_2_BIAS_0_POS    24
#define RICU_AFE_CTL_9_EN_DAC_REF_7_BIT     ((uint32_t)0x00800000)
#define RICU_AFE_CTL_9_EN_DAC_REF_7_POS     23
#define RICU_AFE_CTL_9_EN_DAC_REF_6_BIT     ((uint32_t)0x00400000)
#define RICU_AFE_CTL_9_EN_DAC_REF_6_POS     22
#define RICU_AFE_CTL_9_EN_DAC_REF_5_BIT     ((uint32_t)0x00200000)
#define RICU_AFE_CTL_9_EN_DAC_REF_5_POS     21
#define RICU_AFE_CTL_9_EN_DAC_REF_4_BIT     ((uint32_t)0x00100000)
#define RICU_AFE_CTL_9_EN_DAC_REF_4_POS     20
#define RICU_AFE_CTL_9_EN_DAC_REF_3_BIT     ((uint32_t)0x00080000)
#define RICU_AFE_CTL_9_EN_DAC_REF_3_POS     19
#define RICU_AFE_CTL_9_EN_DAC_REF_2_BIT     ((uint32_t)0x00040000)
#define RICU_AFE_CTL_9_EN_DAC_REF_2_POS     18
#define RICU_AFE_CTL_9_EN_DAC_REF_1_BIT     ((uint32_t)0x00020000)
#define RICU_AFE_CTL_9_EN_DAC_REF_1_POS     17
#define RICU_AFE_CTL_9_EN_DAC_REF_0_BIT     ((uint32_t)0x00010000)
#define RICU_AFE_CTL_9_EN_DAC_REF_0_POS     16

#define RICU_AFE_CTL_9_EN_SIN_2_BIAS_7_RST    0x1
#define RICU_AFE_CTL_9_EN_SIN_2_BIAS_6_RST    0x1
#define RICU_AFE_CTL_9_EN_SIN_2_BIAS_5_RST    0x1
#define RICU_AFE_CTL_9_EN_SIN_2_BIAS_4_RST    0x1
#define RICU_AFE_CTL_9_EN_SIN_2_BIAS_3_RST    0x1
#define RICU_AFE_CTL_9_EN_SIN_2_BIAS_2_RST    0x1
#define RICU_AFE_CTL_9_EN_SIN_2_BIAS_1_RST    0x1
#define RICU_AFE_CTL_9_EN_SIN_2_BIAS_0_RST    0x1
#define RICU_AFE_CTL_9_EN_DAC_REF_7_RST     0x0
#define RICU_AFE_CTL_9_EN_DAC_REF_6_RST     0x0
#define RICU_AFE_CTL_9_EN_DAC_REF_5_RST     0x0
#define RICU_AFE_CTL_9_EN_DAC_REF_4_RST     0x0
#define RICU_AFE_CTL_9_EN_DAC_REF_3_RST     0x0
#define RICU_AFE_CTL_9_EN_DAC_REF_2_RST     0x0
#define RICU_AFE_CTL_9_EN_DAC_REF_1_RST     0x0
#define RICU_AFE_CTL_9_EN_DAC_REF_0_RST     0x0

__INLINE void ricu_afe_ctl_9_pack(uint8_t en_sin2_bias7, uint8_t en_sin2_bias6, uint8_t en_sin2_bias5, uint8_t en_sin2_bias4, uint8_t en_sin2_bias3, uint8_t en_sin2_bias2, uint8_t en_sin2_bias1, uint8_t en_sin2_bias0, uint8_t en_dac_ref7, uint8_t en_dac_ref6, uint8_t en_dac_ref5, uint8_t en_dac_ref4, uint8_t en_dac_ref3, uint8_t en_dac_ref2, uint8_t en_dac_ref1, uint8_t en_dac_ref0)
{
	ASSERT_ERR((((uint32_t)en_sin2_bias7 << 31) & ~((uint32_t)0x80000000)) == 0);
	ASSERT_ERR((((uint32_t)en_sin2_bias6 << 30) & ~((uint32_t)0x40000000)) == 0);
	ASSERT_ERR((((uint32_t)en_sin2_bias5 << 29) & ~((uint32_t)0x20000000)) == 0);
	ASSERT_ERR((((uint32_t)en_sin2_bias4 << 28) & ~((uint32_t)0x10000000)) == 0);
	ASSERT_ERR((((uint32_t)en_sin2_bias3 << 27) & ~((uint32_t)0x08000000)) == 0);
	ASSERT_ERR((((uint32_t)en_sin2_bias2 << 26) & ~((uint32_t)0x04000000)) == 0);
	ASSERT_ERR((((uint32_t)en_sin2_bias1 << 25) & ~((uint32_t)0x02000000)) == 0);
	ASSERT_ERR((((uint32_t)en_sin2_bias0 << 24) & ~((uint32_t)0x01000000)) == 0);
	ASSERT_ERR((((uint32_t)en_dac_ref7 << 23) & ~((uint32_t)0x00800000)) == 0);
	ASSERT_ERR((((uint32_t)en_dac_ref6 << 22) & ~((uint32_t)0x00400000)) == 0);
	ASSERT_ERR((((uint32_t)en_dac_ref5 << 21) & ~((uint32_t)0x00200000)) == 0);
	ASSERT_ERR((((uint32_t)en_dac_ref4 << 20) & ~((uint32_t)0x00100000)) == 0);
	ASSERT_ERR((((uint32_t)en_dac_ref3 << 19) & ~((uint32_t)0x00080000)) == 0);
	ASSERT_ERR((((uint32_t)en_dac_ref2 << 18) & ~((uint32_t)0x00040000)) == 0);
	ASSERT_ERR((((uint32_t)en_dac_ref1 << 17) & ~((uint32_t)0x00020000)) == 0);
	ASSERT_ERR((((uint32_t)en_dac_ref0 << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_9_ADDR,  ((uint32_t)en_sin2_bias7 << 31) |((uint32_t)en_sin2_bias6 << 30) |((uint32_t)en_sin2_bias5 << 29) |((uint32_t)en_sin2_bias4 << 28) |((uint32_t)en_sin2_bias3 << 27) |((uint32_t)en_sin2_bias2 << 26) |((uint32_t)en_sin2_bias1 << 25) |((uint32_t)en_sin2_bias0 << 24) |((uint32_t)en_dac_ref7 << 23) |((uint32_t)en_dac_ref6 << 22) |((uint32_t)en_dac_ref5 << 21) |((uint32_t)en_dac_ref4 << 20) |((uint32_t)en_dac_ref3 << 19) |((uint32_t)en_dac_ref2 << 18) |((uint32_t)en_dac_ref1 << 17) |((uint32_t)en_dac_ref0 << 16));
}

__INLINE void ricu_afe_ctl_9_unpack(uint8_t* en_sin2_bias7, uint8_t* en_sin2_bias6, uint8_t* en_sin2_bias5, uint8_t* en_sin2_bias4, uint8_t* en_sin2_bias3, uint8_t* en_sin2_bias2, uint8_t* en_sin2_bias1, uint8_t* en_sin2_bias0, uint8_t* en_dac_ref7, uint8_t* en_dac_ref6, uint8_t* en_dac_ref5, uint8_t* en_dac_ref4, uint8_t* en_dac_ref3, uint8_t* en_dac_ref2, uint8_t* en_dac_ref1, uint8_t* en_dac_ref0)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_9_ADDR);

	*en_sin2_bias7 = (localVal & ((uint32_t)0x80000000)) >>  31;
	*en_sin2_bias6 = (localVal & ((uint32_t)0x40000000)) >>  30;
	*en_sin2_bias5 = (localVal & ((uint32_t)0x20000000)) >>  29;
	*en_sin2_bias4 = (localVal & ((uint32_t)0x10000000)) >>  28;
	*en_sin2_bias3 = (localVal & ((uint32_t)0x08000000)) >>  27;
	*en_sin2_bias2 = (localVal & ((uint32_t)0x04000000)) >>  26;
	*en_sin2_bias1 = (localVal & ((uint32_t)0x02000000)) >>  25;
	*en_sin2_bias0 = (localVal & ((uint32_t)0x01000000)) >>  24;
	*en_dac_ref7 = (localVal & ((uint32_t)0x00800000)) >>  23;
	*en_dac_ref6 = (localVal & ((uint32_t)0x00400000)) >>  22;
	*en_dac_ref5 = (localVal & ((uint32_t)0x00200000)) >>  21;
	*en_dac_ref4 = (localVal & ((uint32_t)0x00100000)) >>  20;
	*en_dac_ref3 = (localVal & ((uint32_t)0x00080000)) >>  19;
	*en_dac_ref2 = (localVal & ((uint32_t)0x00040000)) >>  18;
	*en_dac_ref1 = (localVal & ((uint32_t)0x00020000)) >>  17;
	*en_dac_ref0 = (localVal & ((uint32_t)0x00010000)) >>  16;
}

__INLINE uint8_t ricu_afe_ctl_9_en_sin_2_bias_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_9_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE void ricu_afe_ctl_9_en_sin_2_bias_7_setf(uint8_t ensin2bias7)
{
	ASSERT_ERR((((uint32_t)ensin2bias7 << 31) & ~((uint32_t)0x80000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_9_ADDR, (REG_PL_RD(RICU_AFE_CTL_9_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)ensin2bias7 <<31));
}
__INLINE uint8_t ricu_afe_ctl_9_en_sin_2_bias_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_9_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x40000000)) >> 30);
}
__INLINE void ricu_afe_ctl_9_en_sin_2_bias_6_setf(uint8_t ensin2bias6)
{
	ASSERT_ERR((((uint32_t)ensin2bias6 << 30) & ~((uint32_t)0x40000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_9_ADDR, (REG_PL_RD(RICU_AFE_CTL_9_ADDR) & ~((uint32_t)0x40000000)) | ((uint32_t)ensin2bias6 <<30));
}
__INLINE uint8_t ricu_afe_ctl_9_en_sin_2_bias_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_9_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x20000000)) >> 29);
}
__INLINE void ricu_afe_ctl_9_en_sin_2_bias_5_setf(uint8_t ensin2bias5)
{
	ASSERT_ERR((((uint32_t)ensin2bias5 << 29) & ~((uint32_t)0x20000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_9_ADDR, (REG_PL_RD(RICU_AFE_CTL_9_ADDR) & ~((uint32_t)0x20000000)) | ((uint32_t)ensin2bias5 <<29));
}
__INLINE uint8_t ricu_afe_ctl_9_en_sin_2_bias_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_9_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x10000000)) >> 28);
}
__INLINE void ricu_afe_ctl_9_en_sin_2_bias_4_setf(uint8_t ensin2bias4)
{
	ASSERT_ERR((((uint32_t)ensin2bias4 << 28) & ~((uint32_t)0x10000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_9_ADDR, (REG_PL_RD(RICU_AFE_CTL_9_ADDR) & ~((uint32_t)0x10000000)) | ((uint32_t)ensin2bias4 <<28));
}
__INLINE uint8_t ricu_afe_ctl_9_en_sin_2_bias_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_9_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x08000000)) >> 27);
}
__INLINE void ricu_afe_ctl_9_en_sin_2_bias_3_setf(uint8_t ensin2bias3)
{
	ASSERT_ERR((((uint32_t)ensin2bias3 << 27) & ~((uint32_t)0x08000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_9_ADDR, (REG_PL_RD(RICU_AFE_CTL_9_ADDR) & ~((uint32_t)0x08000000)) | ((uint32_t)ensin2bias3 <<27));
}
__INLINE uint8_t ricu_afe_ctl_9_en_sin_2_bias_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_9_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x04000000)) >> 26);
}
__INLINE void ricu_afe_ctl_9_en_sin_2_bias_2_setf(uint8_t ensin2bias2)
{
	ASSERT_ERR((((uint32_t)ensin2bias2 << 26) & ~((uint32_t)0x04000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_9_ADDR, (REG_PL_RD(RICU_AFE_CTL_9_ADDR) & ~((uint32_t)0x04000000)) | ((uint32_t)ensin2bias2 <<26));
}
__INLINE uint8_t ricu_afe_ctl_9_en_sin_2_bias_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_9_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x02000000)) >> 25);
}
__INLINE void ricu_afe_ctl_9_en_sin_2_bias_1_setf(uint8_t ensin2bias1)
{
	ASSERT_ERR((((uint32_t)ensin2bias1 << 25) & ~((uint32_t)0x02000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_9_ADDR, (REG_PL_RD(RICU_AFE_CTL_9_ADDR) & ~((uint32_t)0x02000000)) | ((uint32_t)ensin2bias1 <<25));
}
__INLINE uint8_t ricu_afe_ctl_9_en_sin_2_bias_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_9_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01000000)) >> 24);
}
__INLINE void ricu_afe_ctl_9_en_sin_2_bias_0_setf(uint8_t ensin2bias0)
{
	ASSERT_ERR((((uint32_t)ensin2bias0 << 24) & ~((uint32_t)0x01000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_9_ADDR, (REG_PL_RD(RICU_AFE_CTL_9_ADDR) & ~((uint32_t)0x01000000)) | ((uint32_t)ensin2bias0 <<24));
}
__INLINE uint8_t ricu_afe_ctl_9_en_dac_ref_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_9_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00800000)) >> 23);
}
__INLINE void ricu_afe_ctl_9_en_dac_ref_7_setf(uint8_t endacref7)
{
	ASSERT_ERR((((uint32_t)endacref7 << 23) & ~((uint32_t)0x00800000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_9_ADDR, (REG_PL_RD(RICU_AFE_CTL_9_ADDR) & ~((uint32_t)0x00800000)) | ((uint32_t)endacref7 <<23));
}
__INLINE uint8_t ricu_afe_ctl_9_en_dac_ref_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_9_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00400000)) >> 22);
}
__INLINE void ricu_afe_ctl_9_en_dac_ref_6_setf(uint8_t endacref6)
{
	ASSERT_ERR((((uint32_t)endacref6 << 22) & ~((uint32_t)0x00400000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_9_ADDR, (REG_PL_RD(RICU_AFE_CTL_9_ADDR) & ~((uint32_t)0x00400000)) | ((uint32_t)endacref6 <<22));
}
__INLINE uint8_t ricu_afe_ctl_9_en_dac_ref_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_9_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00200000)) >> 21);
}
__INLINE void ricu_afe_ctl_9_en_dac_ref_5_setf(uint8_t endacref5)
{
	ASSERT_ERR((((uint32_t)endacref5 << 21) & ~((uint32_t)0x00200000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_9_ADDR, (REG_PL_RD(RICU_AFE_CTL_9_ADDR) & ~((uint32_t)0x00200000)) | ((uint32_t)endacref5 <<21));
}
__INLINE uint8_t ricu_afe_ctl_9_en_dac_ref_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_9_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00100000)) >> 20);
}
__INLINE void ricu_afe_ctl_9_en_dac_ref_4_setf(uint8_t endacref4)
{
	ASSERT_ERR((((uint32_t)endacref4 << 20) & ~((uint32_t)0x00100000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_9_ADDR, (REG_PL_RD(RICU_AFE_CTL_9_ADDR) & ~((uint32_t)0x00100000)) | ((uint32_t)endacref4 <<20));
}
__INLINE uint8_t ricu_afe_ctl_9_en_dac_ref_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_9_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00080000)) >> 19);
}
__INLINE void ricu_afe_ctl_9_en_dac_ref_3_setf(uint8_t endacref3)
{
	ASSERT_ERR((((uint32_t)endacref3 << 19) & ~((uint32_t)0x00080000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_9_ADDR, (REG_PL_RD(RICU_AFE_CTL_9_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)endacref3 <<19));
}
__INLINE uint8_t ricu_afe_ctl_9_en_dac_ref_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_9_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00040000)) >> 18);
}
__INLINE void ricu_afe_ctl_9_en_dac_ref_2_setf(uint8_t endacref2)
{
	ASSERT_ERR((((uint32_t)endacref2 << 18) & ~((uint32_t)0x00040000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_9_ADDR, (REG_PL_RD(RICU_AFE_CTL_9_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)endacref2 <<18));
}
__INLINE uint8_t ricu_afe_ctl_9_en_dac_ref_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_9_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00020000)) >> 17);
}
__INLINE void ricu_afe_ctl_9_en_dac_ref_1_setf(uint8_t endacref1)
{
	ASSERT_ERR((((uint32_t)endacref1 << 17) & ~((uint32_t)0x00020000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_9_ADDR, (REG_PL_RD(RICU_AFE_CTL_9_ADDR) & ~((uint32_t)0x00020000)) | ((uint32_t)endacref1 <<17));
}
__INLINE uint8_t ricu_afe_ctl_9_en_dac_ref_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_9_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void ricu_afe_ctl_9_en_dac_ref_0_setf(uint8_t endacref0)
{
	ASSERT_ERR((((uint32_t)endacref0 << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_9_ADDR, (REG_PL_RD(RICU_AFE_CTL_9_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)endacref0 <<16));
}

/**
 * @brief AFE_CTL_10 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    VC_LD7                    0              
 *    30    VC_LD6                    0              
 *    29    VC_LD5                    0              
 *    28    VC_LD4                    0              
 *    27    VC_LD3                    0              
 *    26    VC_LD2                    0              
 *    25    VC_LD1                    0              
 *    24    VC_LD0                    0              
 *    23    TWOS7                     0              
 *    22    TWOS6                     0              
 *    21    TWOS5                     0              
 *    20    TWOS4                     0              
 *    19    TWOS3                     0              
 *    18    TWOS2                     0              
 *    17    TWOS1                     0              
 *    16    TWOS0                     0              
 *    07    MINV7                     1              
 *    06    MINV6                     1              
 *    05    MINV5                     1              
 *    04    MINV4                     1              
 *    03    MINV3                     1              
 *    02    MINV2                     1              
 *    01    MINV1                     1              
 *    00    MINV0                     1              
 * </pre>
 */
#define RICU_AFE_CTL_10_ADDR        (REG_RICU_BASE_ADDR+0x00000038)
#define RICU_AFE_CTL_10_OFFSET      0x00000038
#define RICU_AFE_CTL_10_INDEX       0x0000000E
#define RICU_AFE_CTL_10_RESET       0x000000FF

__INLINE uint32_t  ricu_afe_ctl_10_get(void)
{
	return REG_PL_RD(RICU_AFE_CTL_10_ADDR);
}

__INLINE void ricu_afe_ctl_10_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTL_10_ADDR, value);
}

// field definitions
#define RICU_AFE_CTL_10_VC_LD_7_BIT         ((uint32_t)0x80000000)
#define RICU_AFE_CTL_10_VC_LD_7_POS         31
#define RICU_AFE_CTL_10_VC_LD_6_BIT         ((uint32_t)0x40000000)
#define RICU_AFE_CTL_10_VC_LD_6_POS         30
#define RICU_AFE_CTL_10_VC_LD_5_BIT         ((uint32_t)0x20000000)
#define RICU_AFE_CTL_10_VC_LD_5_POS         29
#define RICU_AFE_CTL_10_VC_LD_4_BIT         ((uint32_t)0x10000000)
#define RICU_AFE_CTL_10_VC_LD_4_POS         28
#define RICU_AFE_CTL_10_VC_LD_3_BIT         ((uint32_t)0x08000000)
#define RICU_AFE_CTL_10_VC_LD_3_POS         27
#define RICU_AFE_CTL_10_VC_LD_2_BIT         ((uint32_t)0x04000000)
#define RICU_AFE_CTL_10_VC_LD_2_POS         26
#define RICU_AFE_CTL_10_VC_LD_1_BIT         ((uint32_t)0x02000000)
#define RICU_AFE_CTL_10_VC_LD_1_POS         25
#define RICU_AFE_CTL_10_VC_LD_0_BIT         ((uint32_t)0x01000000)
#define RICU_AFE_CTL_10_VC_LD_0_POS         24
#define RICU_AFE_CTL_10_TWOS_7_BIT          ((uint32_t)0x00800000)
#define RICU_AFE_CTL_10_TWOS_7_POS          23
#define RICU_AFE_CTL_10_TWOS_6_BIT          ((uint32_t)0x00400000)
#define RICU_AFE_CTL_10_TWOS_6_POS          22
#define RICU_AFE_CTL_10_TWOS_5_BIT          ((uint32_t)0x00200000)
#define RICU_AFE_CTL_10_TWOS_5_POS          21
#define RICU_AFE_CTL_10_TWOS_4_BIT          ((uint32_t)0x00100000)
#define RICU_AFE_CTL_10_TWOS_4_POS          20
#define RICU_AFE_CTL_10_TWOS_3_BIT          ((uint32_t)0x00080000)
#define RICU_AFE_CTL_10_TWOS_3_POS          19
#define RICU_AFE_CTL_10_TWOS_2_BIT          ((uint32_t)0x00040000)
#define RICU_AFE_CTL_10_TWOS_2_POS          18
#define RICU_AFE_CTL_10_TWOS_1_BIT          ((uint32_t)0x00020000)
#define RICU_AFE_CTL_10_TWOS_1_POS          17
#define RICU_AFE_CTL_10_TWOS_0_BIT          ((uint32_t)0x00010000)
#define RICU_AFE_CTL_10_TWOS_0_POS          16
#define RICU_AFE_CTL_10_MINV_7_BIT          ((uint32_t)0x00000080)
#define RICU_AFE_CTL_10_MINV_7_POS          7
#define RICU_AFE_CTL_10_MINV_6_BIT          ((uint32_t)0x00000040)
#define RICU_AFE_CTL_10_MINV_6_POS          6
#define RICU_AFE_CTL_10_MINV_5_BIT          ((uint32_t)0x00000020)
#define RICU_AFE_CTL_10_MINV_5_POS          5
#define RICU_AFE_CTL_10_MINV_4_BIT          ((uint32_t)0x00000010)
#define RICU_AFE_CTL_10_MINV_4_POS          4
#define RICU_AFE_CTL_10_MINV_3_BIT          ((uint32_t)0x00000008)
#define RICU_AFE_CTL_10_MINV_3_POS          3
#define RICU_AFE_CTL_10_MINV_2_BIT          ((uint32_t)0x00000004)
#define RICU_AFE_CTL_10_MINV_2_POS          2
#define RICU_AFE_CTL_10_MINV_1_BIT          ((uint32_t)0x00000002)
#define RICU_AFE_CTL_10_MINV_1_POS          1
#define RICU_AFE_CTL_10_MINV_0_BIT          ((uint32_t)0x00000001)
#define RICU_AFE_CTL_10_MINV_0_POS          0

#define RICU_AFE_CTL_10_VC_LD_7_RST         0x0
#define RICU_AFE_CTL_10_VC_LD_6_RST         0x0
#define RICU_AFE_CTL_10_VC_LD_5_RST         0x0
#define RICU_AFE_CTL_10_VC_LD_4_RST         0x0
#define RICU_AFE_CTL_10_VC_LD_3_RST         0x0
#define RICU_AFE_CTL_10_VC_LD_2_RST         0x0
#define RICU_AFE_CTL_10_VC_LD_1_RST         0x0
#define RICU_AFE_CTL_10_VC_LD_0_RST         0x0
#define RICU_AFE_CTL_10_TWOS_7_RST          0x0
#define RICU_AFE_CTL_10_TWOS_6_RST          0x0
#define RICU_AFE_CTL_10_TWOS_5_RST          0x0
#define RICU_AFE_CTL_10_TWOS_4_RST          0x0
#define RICU_AFE_CTL_10_TWOS_3_RST          0x0
#define RICU_AFE_CTL_10_TWOS_2_RST          0x0
#define RICU_AFE_CTL_10_TWOS_1_RST          0x0
#define RICU_AFE_CTL_10_TWOS_0_RST          0x0
#define RICU_AFE_CTL_10_MINV_7_RST          0x1
#define RICU_AFE_CTL_10_MINV_6_RST          0x1
#define RICU_AFE_CTL_10_MINV_5_RST          0x1
#define RICU_AFE_CTL_10_MINV_4_RST          0x1
#define RICU_AFE_CTL_10_MINV_3_RST          0x1
#define RICU_AFE_CTL_10_MINV_2_RST          0x1
#define RICU_AFE_CTL_10_MINV_1_RST          0x1
#define RICU_AFE_CTL_10_MINV_0_RST          0x1

__INLINE void ricu_afe_ctl_10_pack(uint8_t vc_ld7, uint8_t vc_ld6, uint8_t vc_ld5, uint8_t vc_ld4, uint8_t vc_ld3, uint8_t vc_ld2, uint8_t vc_ld1, uint8_t vc_ld0, uint8_t twos7, uint8_t twos6, uint8_t twos5, uint8_t twos4, uint8_t twos3, uint8_t twos2, uint8_t twos1, uint8_t twos0, uint8_t minv7, uint8_t minv6, uint8_t minv5, uint8_t minv4, uint8_t minv3, uint8_t minv2, uint8_t minv1, uint8_t minv0)
{
	ASSERT_ERR((((uint32_t)vc_ld7 << 31) & ~((uint32_t)0x80000000)) == 0);
	ASSERT_ERR((((uint32_t)vc_ld6 << 30) & ~((uint32_t)0x40000000)) == 0);
	ASSERT_ERR((((uint32_t)vc_ld5 << 29) & ~((uint32_t)0x20000000)) == 0);
	ASSERT_ERR((((uint32_t)vc_ld4 << 28) & ~((uint32_t)0x10000000)) == 0);
	ASSERT_ERR((((uint32_t)vc_ld3 << 27) & ~((uint32_t)0x08000000)) == 0);
	ASSERT_ERR((((uint32_t)vc_ld2 << 26) & ~((uint32_t)0x04000000)) == 0);
	ASSERT_ERR((((uint32_t)vc_ld1 << 25) & ~((uint32_t)0x02000000)) == 0);
	ASSERT_ERR((((uint32_t)vc_ld0 << 24) & ~((uint32_t)0x01000000)) == 0);
	ASSERT_ERR((((uint32_t)twos7 << 23) & ~((uint32_t)0x00800000)) == 0);
	ASSERT_ERR((((uint32_t)twos6 << 22) & ~((uint32_t)0x00400000)) == 0);
	ASSERT_ERR((((uint32_t)twos5 << 21) & ~((uint32_t)0x00200000)) == 0);
	ASSERT_ERR((((uint32_t)twos4 << 20) & ~((uint32_t)0x00100000)) == 0);
	ASSERT_ERR((((uint32_t)twos3 << 19) & ~((uint32_t)0x00080000)) == 0);
	ASSERT_ERR((((uint32_t)twos2 << 18) & ~((uint32_t)0x00040000)) == 0);
	ASSERT_ERR((((uint32_t)twos1 << 17) & ~((uint32_t)0x00020000)) == 0);
	ASSERT_ERR((((uint32_t)twos0 << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)minv7 << 7) & ~((uint32_t)0x00000080)) == 0);
	ASSERT_ERR((((uint32_t)minv6 << 6) & ~((uint32_t)0x00000040)) == 0);
	ASSERT_ERR((((uint32_t)minv5 << 5) & ~((uint32_t)0x00000020)) == 0);
	ASSERT_ERR((((uint32_t)minv4 << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)minv3 << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)minv2 << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)minv1 << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)minv0 << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RICU_AFE_CTL_10_ADDR,  ((uint32_t)vc_ld7 << 31) |((uint32_t)vc_ld6 << 30) |((uint32_t)vc_ld5 << 29) |((uint32_t)vc_ld4 << 28) |((uint32_t)vc_ld3 << 27) |((uint32_t)vc_ld2 << 26) |((uint32_t)vc_ld1 << 25) |((uint32_t)vc_ld0 << 24) |((uint32_t)twos7 << 23) |((uint32_t)twos6 << 22) |((uint32_t)twos5 << 21) |((uint32_t)twos4 << 20) |((uint32_t)twos3 << 19) |((uint32_t)twos2 << 18) |((uint32_t)twos1 << 17) |((uint32_t)twos0 << 16) |((uint32_t)minv7 << 7) |((uint32_t)minv6 << 6) |((uint32_t)minv5 << 5) |((uint32_t)minv4 << 4) |((uint32_t)minv3 << 3) |((uint32_t)minv2 << 2) |((uint32_t)minv1 << 1) |((uint32_t)minv0 << 0));
}

__INLINE void ricu_afe_ctl_10_unpack(uint8_t* vc_ld7, uint8_t* vc_ld6, uint8_t* vc_ld5, uint8_t* vc_ld4, uint8_t* vc_ld3, uint8_t* vc_ld2, uint8_t* vc_ld1, uint8_t* vc_ld0, uint8_t* twos7, uint8_t* twos6, uint8_t* twos5, uint8_t* twos4, uint8_t* twos3, uint8_t* twos2, uint8_t* twos1, uint8_t* twos0, uint8_t* minv7, uint8_t* minv6, uint8_t* minv5, uint8_t* minv4, uint8_t* minv3, uint8_t* minv2, uint8_t* minv1, uint8_t* minv0)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_10_ADDR);

	*vc_ld7 = (localVal & ((uint32_t)0x80000000)) >>  31;
	*vc_ld6 = (localVal & ((uint32_t)0x40000000)) >>  30;
	*vc_ld5 = (localVal & ((uint32_t)0x20000000)) >>  29;
	*vc_ld4 = (localVal & ((uint32_t)0x10000000)) >>  28;
	*vc_ld3 = (localVal & ((uint32_t)0x08000000)) >>  27;
	*vc_ld2 = (localVal & ((uint32_t)0x04000000)) >>  26;
	*vc_ld1 = (localVal & ((uint32_t)0x02000000)) >>  25;
	*vc_ld0 = (localVal & ((uint32_t)0x01000000)) >>  24;
	*twos7 = (localVal & ((uint32_t)0x00800000)) >>  23;
	*twos6 = (localVal & ((uint32_t)0x00400000)) >>  22;
	*twos5 = (localVal & ((uint32_t)0x00200000)) >>  21;
	*twos4 = (localVal & ((uint32_t)0x00100000)) >>  20;
	*twos3 = (localVal & ((uint32_t)0x00080000)) >>  19;
	*twos2 = (localVal & ((uint32_t)0x00040000)) >>  18;
	*twos1 = (localVal & ((uint32_t)0x00020000)) >>  17;
	*twos0 = (localVal & ((uint32_t)0x00010000)) >>  16;
	*minv7 = (localVal & ((uint32_t)0x00000080)) >>  7;
	*minv6 = (localVal & ((uint32_t)0x00000040)) >>  6;
	*minv5 = (localVal & ((uint32_t)0x00000020)) >>  5;
	*minv4 = (localVal & ((uint32_t)0x00000010)) >>  4;
	*minv3 = (localVal & ((uint32_t)0x00000008)) >>  3;
	*minv2 = (localVal & ((uint32_t)0x00000004)) >>  2;
	*minv1 = (localVal & ((uint32_t)0x00000002)) >>  1;
	*minv0 = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t ricu_afe_ctl_10_vc_ld_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_10_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE void ricu_afe_ctl_10_vc_ld_7_setf(uint8_t vcld7)
{
	ASSERT_ERR((((uint32_t)vcld7 << 31) & ~((uint32_t)0x80000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_10_ADDR, (REG_PL_RD(RICU_AFE_CTL_10_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)vcld7 <<31));
}
__INLINE uint8_t ricu_afe_ctl_10_vc_ld_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_10_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x40000000)) >> 30);
}
__INLINE void ricu_afe_ctl_10_vc_ld_6_setf(uint8_t vcld6)
{
	ASSERT_ERR((((uint32_t)vcld6 << 30) & ~((uint32_t)0x40000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_10_ADDR, (REG_PL_RD(RICU_AFE_CTL_10_ADDR) & ~((uint32_t)0x40000000)) | ((uint32_t)vcld6 <<30));
}
__INLINE uint8_t ricu_afe_ctl_10_vc_ld_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_10_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x20000000)) >> 29);
}
__INLINE void ricu_afe_ctl_10_vc_ld_5_setf(uint8_t vcld5)
{
	ASSERT_ERR((((uint32_t)vcld5 << 29) & ~((uint32_t)0x20000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_10_ADDR, (REG_PL_RD(RICU_AFE_CTL_10_ADDR) & ~((uint32_t)0x20000000)) | ((uint32_t)vcld5 <<29));
}
__INLINE uint8_t ricu_afe_ctl_10_vc_ld_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_10_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x10000000)) >> 28);
}
__INLINE void ricu_afe_ctl_10_vc_ld_4_setf(uint8_t vcld4)
{
	ASSERT_ERR((((uint32_t)vcld4 << 28) & ~((uint32_t)0x10000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_10_ADDR, (REG_PL_RD(RICU_AFE_CTL_10_ADDR) & ~((uint32_t)0x10000000)) | ((uint32_t)vcld4 <<28));
}
__INLINE uint8_t ricu_afe_ctl_10_vc_ld_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_10_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x08000000)) >> 27);
}
__INLINE void ricu_afe_ctl_10_vc_ld_3_setf(uint8_t vcld3)
{
	ASSERT_ERR((((uint32_t)vcld3 << 27) & ~((uint32_t)0x08000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_10_ADDR, (REG_PL_RD(RICU_AFE_CTL_10_ADDR) & ~((uint32_t)0x08000000)) | ((uint32_t)vcld3 <<27));
}
__INLINE uint8_t ricu_afe_ctl_10_vc_ld_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_10_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x04000000)) >> 26);
}
__INLINE void ricu_afe_ctl_10_vc_ld_2_setf(uint8_t vcld2)
{
	ASSERT_ERR((((uint32_t)vcld2 << 26) & ~((uint32_t)0x04000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_10_ADDR, (REG_PL_RD(RICU_AFE_CTL_10_ADDR) & ~((uint32_t)0x04000000)) | ((uint32_t)vcld2 <<26));
}
__INLINE uint8_t ricu_afe_ctl_10_vc_ld_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_10_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x02000000)) >> 25);
}
__INLINE void ricu_afe_ctl_10_vc_ld_1_setf(uint8_t vcld1)
{
	ASSERT_ERR((((uint32_t)vcld1 << 25) & ~((uint32_t)0x02000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_10_ADDR, (REG_PL_RD(RICU_AFE_CTL_10_ADDR) & ~((uint32_t)0x02000000)) | ((uint32_t)vcld1 <<25));
}
__INLINE uint8_t ricu_afe_ctl_10_vc_ld_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_10_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01000000)) >> 24);
}
__INLINE void ricu_afe_ctl_10_vc_ld_0_setf(uint8_t vcld0)
{
	ASSERT_ERR((((uint32_t)vcld0 << 24) & ~((uint32_t)0x01000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_10_ADDR, (REG_PL_RD(RICU_AFE_CTL_10_ADDR) & ~((uint32_t)0x01000000)) | ((uint32_t)vcld0 <<24));
}
__INLINE uint8_t ricu_afe_ctl_10_twos_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_10_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00800000)) >> 23);
}
__INLINE void ricu_afe_ctl_10_twos_7_setf(uint8_t twos7)
{
	ASSERT_ERR((((uint32_t)twos7 << 23) & ~((uint32_t)0x00800000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_10_ADDR, (REG_PL_RD(RICU_AFE_CTL_10_ADDR) & ~((uint32_t)0x00800000)) | ((uint32_t)twos7 <<23));
}
__INLINE uint8_t ricu_afe_ctl_10_twos_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_10_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00400000)) >> 22);
}
__INLINE void ricu_afe_ctl_10_twos_6_setf(uint8_t twos6)
{
	ASSERT_ERR((((uint32_t)twos6 << 22) & ~((uint32_t)0x00400000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_10_ADDR, (REG_PL_RD(RICU_AFE_CTL_10_ADDR) & ~((uint32_t)0x00400000)) | ((uint32_t)twos6 <<22));
}
__INLINE uint8_t ricu_afe_ctl_10_twos_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_10_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00200000)) >> 21);
}
__INLINE void ricu_afe_ctl_10_twos_5_setf(uint8_t twos5)
{
	ASSERT_ERR((((uint32_t)twos5 << 21) & ~((uint32_t)0x00200000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_10_ADDR, (REG_PL_RD(RICU_AFE_CTL_10_ADDR) & ~((uint32_t)0x00200000)) | ((uint32_t)twos5 <<21));
}
__INLINE uint8_t ricu_afe_ctl_10_twos_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_10_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00100000)) >> 20);
}
__INLINE void ricu_afe_ctl_10_twos_4_setf(uint8_t twos4)
{
	ASSERT_ERR((((uint32_t)twos4 << 20) & ~((uint32_t)0x00100000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_10_ADDR, (REG_PL_RD(RICU_AFE_CTL_10_ADDR) & ~((uint32_t)0x00100000)) | ((uint32_t)twos4 <<20));
}
__INLINE uint8_t ricu_afe_ctl_10_twos_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_10_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00080000)) >> 19);
}
__INLINE void ricu_afe_ctl_10_twos_3_setf(uint8_t twos3)
{
	ASSERT_ERR((((uint32_t)twos3 << 19) & ~((uint32_t)0x00080000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_10_ADDR, (REG_PL_RD(RICU_AFE_CTL_10_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)twos3 <<19));
}
__INLINE uint8_t ricu_afe_ctl_10_twos_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_10_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00040000)) >> 18);
}
__INLINE void ricu_afe_ctl_10_twos_2_setf(uint8_t twos2)
{
	ASSERT_ERR((((uint32_t)twos2 << 18) & ~((uint32_t)0x00040000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_10_ADDR, (REG_PL_RD(RICU_AFE_CTL_10_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)twos2 <<18));
}
__INLINE uint8_t ricu_afe_ctl_10_twos_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_10_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00020000)) >> 17);
}
__INLINE void ricu_afe_ctl_10_twos_1_setf(uint8_t twos1)
{
	ASSERT_ERR((((uint32_t)twos1 << 17) & ~((uint32_t)0x00020000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_10_ADDR, (REG_PL_RD(RICU_AFE_CTL_10_ADDR) & ~((uint32_t)0x00020000)) | ((uint32_t)twos1 <<17));
}
__INLINE uint8_t ricu_afe_ctl_10_twos_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_10_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void ricu_afe_ctl_10_twos_0_setf(uint8_t twos0)
{
	ASSERT_ERR((((uint32_t)twos0 << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_10_ADDR, (REG_PL_RD(RICU_AFE_CTL_10_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)twos0 <<16));
}
__INLINE uint8_t ricu_afe_ctl_10_minv_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_10_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE void ricu_afe_ctl_10_minv_7_setf(uint8_t minv7)
{
	ASSERT_ERR((((uint32_t)minv7 << 7) & ~((uint32_t)0x00000080)) == 0);
	REG_PL_WR(RICU_AFE_CTL_10_ADDR, (REG_PL_RD(RICU_AFE_CTL_10_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)minv7 <<7));
}
__INLINE uint8_t ricu_afe_ctl_10_minv_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_10_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE void ricu_afe_ctl_10_minv_6_setf(uint8_t minv6)
{
	ASSERT_ERR((((uint32_t)minv6 << 6) & ~((uint32_t)0x00000040)) == 0);
	REG_PL_WR(RICU_AFE_CTL_10_ADDR, (REG_PL_RD(RICU_AFE_CTL_10_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)minv6 <<6));
}
__INLINE uint8_t ricu_afe_ctl_10_minv_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_10_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE void ricu_afe_ctl_10_minv_5_setf(uint8_t minv5)
{
	ASSERT_ERR((((uint32_t)minv5 << 5) & ~((uint32_t)0x00000020)) == 0);
	REG_PL_WR(RICU_AFE_CTL_10_ADDR, (REG_PL_RD(RICU_AFE_CTL_10_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)minv5 <<5));
}
__INLINE uint8_t ricu_afe_ctl_10_minv_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_10_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void ricu_afe_ctl_10_minv_4_setf(uint8_t minv4)
{
	ASSERT_ERR((((uint32_t)minv4 << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(RICU_AFE_CTL_10_ADDR, (REG_PL_RD(RICU_AFE_CTL_10_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)minv4 <<4));
}
__INLINE uint8_t ricu_afe_ctl_10_minv_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_10_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void ricu_afe_ctl_10_minv_3_setf(uint8_t minv3)
{
	ASSERT_ERR((((uint32_t)minv3 << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(RICU_AFE_CTL_10_ADDR, (REG_PL_RD(RICU_AFE_CTL_10_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)minv3 <<3));
}
__INLINE uint8_t ricu_afe_ctl_10_minv_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_10_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void ricu_afe_ctl_10_minv_2_setf(uint8_t minv2)
{
	ASSERT_ERR((((uint32_t)minv2 << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(RICU_AFE_CTL_10_ADDR, (REG_PL_RD(RICU_AFE_CTL_10_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)minv2 <<2));
}
__INLINE uint8_t ricu_afe_ctl_10_minv_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_10_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void ricu_afe_ctl_10_minv_1_setf(uint8_t minv1)
{
	ASSERT_ERR((((uint32_t)minv1 << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(RICU_AFE_CTL_10_ADDR, (REG_PL_RD(RICU_AFE_CTL_10_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)minv1 <<1));
}
__INLINE uint8_t ricu_afe_ctl_10_minv_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_10_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void ricu_afe_ctl_10_minv_0_setf(uint8_t minv0)
{
	ASSERT_ERR((((uint32_t)minv0 << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RICU_AFE_CTL_10_ADDR, (REG_PL_RD(RICU_AFE_CTL_10_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)minv0 <<0));
}

/**
 * @brief AFE_CTL_11 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:30 IC_REFAMP7                0x1
 *    29:28 IC_REFAMP6                0x1
 *    27:26 IC_REFAMP5                0x1
 *    25:24 IC_REFAMP4                0x1
 *    23:22 IC_REFAMP3                0x1
 *    21:20 IC_REFAMP2                0x1
 *    19:18 IC_REFAMP1                0x1
 *    17:16 IC_REFAMP0                0x1
 *    15:14 IC_LD7                    0x1
 *    13:12 IC_LD6                    0x1
 *    11:10 IC_LD5                    0x1
 *    09:08 IC_LD4                    0x1
 *    07:06 IC_LD3                    0x1
 *    05:04 IC_LD2                    0x1
 *    03:02 IC_LD1                    0x1
 *    01:00 IC_LD0                    0x1
 * </pre>
 */
#define RICU_AFE_CTL_11_ADDR        (REG_RICU_BASE_ADDR+0x0000003C)
#define RICU_AFE_CTL_11_OFFSET      0x0000003C
#define RICU_AFE_CTL_11_INDEX       0x0000000F
#define RICU_AFE_CTL_11_RESET       0x55555555

__INLINE uint32_t  ricu_afe_ctl_11_get(void)
{
	return REG_PL_RD(RICU_AFE_CTL_11_ADDR);
}

__INLINE void ricu_afe_ctl_11_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTL_11_ADDR, value);
}

// field definitions
#define RICU_AFE_CTL_11_IC_REFAMP_7_MASK    ((uint32_t)0xC0000000)
#define RICU_AFE_CTL_11_IC_REFAMP_7_LSB     30
#define RICU_AFE_CTL_11_IC_REFAMP_7_WIDTH    ((uint32_t)0x00000002)
#define RICU_AFE_CTL_11_IC_REFAMP_6_MASK    ((uint32_t)0x30000000)
#define RICU_AFE_CTL_11_IC_REFAMP_6_LSB     28
#define RICU_AFE_CTL_11_IC_REFAMP_6_WIDTH    ((uint32_t)0x00000002)
#define RICU_AFE_CTL_11_IC_REFAMP_5_MASK    ((uint32_t)0x0C000000)
#define RICU_AFE_CTL_11_IC_REFAMP_5_LSB     26
#define RICU_AFE_CTL_11_IC_REFAMP_5_WIDTH    ((uint32_t)0x00000002)
#define RICU_AFE_CTL_11_IC_REFAMP_4_MASK    ((uint32_t)0x03000000)
#define RICU_AFE_CTL_11_IC_REFAMP_4_LSB     24
#define RICU_AFE_CTL_11_IC_REFAMP_4_WIDTH    ((uint32_t)0x00000002)
#define RICU_AFE_CTL_11_IC_REFAMP_3_MASK    ((uint32_t)0x00C00000)
#define RICU_AFE_CTL_11_IC_REFAMP_3_LSB     22
#define RICU_AFE_CTL_11_IC_REFAMP_3_WIDTH    ((uint32_t)0x00000002)
#define RICU_AFE_CTL_11_IC_REFAMP_2_MASK    ((uint32_t)0x00300000)
#define RICU_AFE_CTL_11_IC_REFAMP_2_LSB     20
#define RICU_AFE_CTL_11_IC_REFAMP_2_WIDTH    ((uint32_t)0x00000002)
#define RICU_AFE_CTL_11_IC_REFAMP_1_MASK    ((uint32_t)0x000C0000)
#define RICU_AFE_CTL_11_IC_REFAMP_1_LSB     18
#define RICU_AFE_CTL_11_IC_REFAMP_1_WIDTH    ((uint32_t)0x00000002)
#define RICU_AFE_CTL_11_IC_REFAMP_0_MASK    ((uint32_t)0x00030000)
#define RICU_AFE_CTL_11_IC_REFAMP_0_LSB     16
#define RICU_AFE_CTL_11_IC_REFAMP_0_WIDTH    ((uint32_t)0x00000002)
#define RICU_AFE_CTL_11_IC_LD_7_MASK        ((uint32_t)0x0000C000)
#define RICU_AFE_CTL_11_IC_LD_7_LSB         14
#define RICU_AFE_CTL_11_IC_LD_7_WIDTH       ((uint32_t)0x00000002)
#define RICU_AFE_CTL_11_IC_LD_6_MASK        ((uint32_t)0x00003000)
#define RICU_AFE_CTL_11_IC_LD_6_LSB         12
#define RICU_AFE_CTL_11_IC_LD_6_WIDTH       ((uint32_t)0x00000002)
#define RICU_AFE_CTL_11_IC_LD_5_MASK        ((uint32_t)0x00000C00)
#define RICU_AFE_CTL_11_IC_LD_5_LSB         10
#define RICU_AFE_CTL_11_IC_LD_5_WIDTH       ((uint32_t)0x00000002)
#define RICU_AFE_CTL_11_IC_LD_4_MASK        ((uint32_t)0x00000300)
#define RICU_AFE_CTL_11_IC_LD_4_LSB         8
#define RICU_AFE_CTL_11_IC_LD_4_WIDTH       ((uint32_t)0x00000002)
#define RICU_AFE_CTL_11_IC_LD_3_MASK        ((uint32_t)0x000000C0)
#define RICU_AFE_CTL_11_IC_LD_3_LSB         6
#define RICU_AFE_CTL_11_IC_LD_3_WIDTH       ((uint32_t)0x00000002)
#define RICU_AFE_CTL_11_IC_LD_2_MASK        ((uint32_t)0x00000030)
#define RICU_AFE_CTL_11_IC_LD_2_LSB         4
#define RICU_AFE_CTL_11_IC_LD_2_WIDTH       ((uint32_t)0x00000002)
#define RICU_AFE_CTL_11_IC_LD_1_MASK        ((uint32_t)0x0000000C)
#define RICU_AFE_CTL_11_IC_LD_1_LSB         2
#define RICU_AFE_CTL_11_IC_LD_1_WIDTH       ((uint32_t)0x00000002)
#define RICU_AFE_CTL_11_IC_LD_0_MASK        ((uint32_t)0x00000003)
#define RICU_AFE_CTL_11_IC_LD_0_LSB         0
#define RICU_AFE_CTL_11_IC_LD_0_WIDTH       ((uint32_t)0x00000002)

#define RICU_AFE_CTL_11_IC_REFAMP_7_RST     0x1
#define RICU_AFE_CTL_11_IC_REFAMP_6_RST     0x1
#define RICU_AFE_CTL_11_IC_REFAMP_5_RST     0x1
#define RICU_AFE_CTL_11_IC_REFAMP_4_RST     0x1
#define RICU_AFE_CTL_11_IC_REFAMP_3_RST     0x1
#define RICU_AFE_CTL_11_IC_REFAMP_2_RST     0x1
#define RICU_AFE_CTL_11_IC_REFAMP_1_RST     0x1
#define RICU_AFE_CTL_11_IC_REFAMP_0_RST     0x1
#define RICU_AFE_CTL_11_IC_LD_7_RST         0x1
#define RICU_AFE_CTL_11_IC_LD_6_RST         0x1
#define RICU_AFE_CTL_11_IC_LD_5_RST         0x1
#define RICU_AFE_CTL_11_IC_LD_4_RST         0x1
#define RICU_AFE_CTL_11_IC_LD_3_RST         0x1
#define RICU_AFE_CTL_11_IC_LD_2_RST         0x1
#define RICU_AFE_CTL_11_IC_LD_1_RST         0x1
#define RICU_AFE_CTL_11_IC_LD_0_RST         0x1

__INLINE void ricu_afe_ctl_11_pack(uint8_t ic_refamp7, uint8_t ic_refamp6, uint8_t ic_refamp5, uint8_t ic_refamp4, uint8_t ic_refamp3, uint8_t ic_refamp2, uint8_t ic_refamp1, uint8_t ic_refamp0, uint8_t ic_ld7, uint8_t ic_ld6, uint8_t ic_ld5, uint8_t ic_ld4, uint8_t ic_ld3, uint8_t ic_ld2, uint8_t ic_ld1, uint8_t ic_ld0)
{
	ASSERT_ERR((((uint32_t)ic_refamp7 << 30) & ~((uint32_t)0xC0000000)) == 0);
	ASSERT_ERR((((uint32_t)ic_refamp6 << 28) & ~((uint32_t)0x30000000)) == 0);
	ASSERT_ERR((((uint32_t)ic_refamp5 << 26) & ~((uint32_t)0x0C000000)) == 0);
	ASSERT_ERR((((uint32_t)ic_refamp4 << 24) & ~((uint32_t)0x03000000)) == 0);
	ASSERT_ERR((((uint32_t)ic_refamp3 << 22) & ~((uint32_t)0x00C00000)) == 0);
	ASSERT_ERR((((uint32_t)ic_refamp2 << 20) & ~((uint32_t)0x00300000)) == 0);
	ASSERT_ERR((((uint32_t)ic_refamp1 << 18) & ~((uint32_t)0x000C0000)) == 0);
	ASSERT_ERR((((uint32_t)ic_refamp0 << 16) & ~((uint32_t)0x00030000)) == 0);
	ASSERT_ERR((((uint32_t)ic_ld7 << 14) & ~((uint32_t)0x0000C000)) == 0);
	ASSERT_ERR((((uint32_t)ic_ld6 << 12) & ~((uint32_t)0x00003000)) == 0);
	ASSERT_ERR((((uint32_t)ic_ld5 << 10) & ~((uint32_t)0x00000C00)) == 0);
	ASSERT_ERR((((uint32_t)ic_ld4 << 8) & ~((uint32_t)0x00000300)) == 0);
	ASSERT_ERR((((uint32_t)ic_ld3 << 6) & ~((uint32_t)0x000000C0)) == 0);
	ASSERT_ERR((((uint32_t)ic_ld2 << 4) & ~((uint32_t)0x00000030)) == 0);
	ASSERT_ERR((((uint32_t)ic_ld1 << 2) & ~((uint32_t)0x0000000C)) == 0);
	ASSERT_ERR((((uint32_t)ic_ld0 << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RICU_AFE_CTL_11_ADDR,  ((uint32_t)ic_refamp7 << 30) |((uint32_t)ic_refamp6 << 28) |((uint32_t)ic_refamp5 << 26) |((uint32_t)ic_refamp4 << 24) |((uint32_t)ic_refamp3 << 22) |((uint32_t)ic_refamp2 << 20) |((uint32_t)ic_refamp1 << 18) |((uint32_t)ic_refamp0 << 16) |((uint32_t)ic_ld7 << 14) |((uint32_t)ic_ld6 << 12) |((uint32_t)ic_ld5 << 10) |((uint32_t)ic_ld4 << 8) |((uint32_t)ic_ld3 << 6) |((uint32_t)ic_ld2 << 4) |((uint32_t)ic_ld1 << 2) |((uint32_t)ic_ld0 << 0));
}

__INLINE void ricu_afe_ctl_11_unpack(uint8_t* ic_refamp7, uint8_t* ic_refamp6, uint8_t* ic_refamp5, uint8_t* ic_refamp4, uint8_t* ic_refamp3, uint8_t* ic_refamp2, uint8_t* ic_refamp1, uint8_t* ic_refamp0, uint8_t* ic_ld7, uint8_t* ic_ld6, uint8_t* ic_ld5, uint8_t* ic_ld4, uint8_t* ic_ld3, uint8_t* ic_ld2, uint8_t* ic_ld1, uint8_t* ic_ld0)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_11_ADDR);

	*ic_refamp7 = (localVal & ((uint32_t)0xC0000000)) >>  30;
	*ic_refamp6 = (localVal & ((uint32_t)0x30000000)) >>  28;
	*ic_refamp5 = (localVal & ((uint32_t)0x0C000000)) >>  26;
	*ic_refamp4 = (localVal & ((uint32_t)0x03000000)) >>  24;
	*ic_refamp3 = (localVal & ((uint32_t)0x00C00000)) >>  22;
	*ic_refamp2 = (localVal & ((uint32_t)0x00300000)) >>  20;
	*ic_refamp1 = (localVal & ((uint32_t)0x000C0000)) >>  18;
	*ic_refamp0 = (localVal & ((uint32_t)0x00030000)) >>  16;
	*ic_ld7 = (localVal & ((uint32_t)0x0000C000)) >>  14;
	*ic_ld6 = (localVal & ((uint32_t)0x00003000)) >>  12;
	*ic_ld5 = (localVal & ((uint32_t)0x00000C00)) >>  10;
	*ic_ld4 = (localVal & ((uint32_t)0x00000300)) >>  8;
	*ic_ld3 = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*ic_ld2 = (localVal & ((uint32_t)0x00000030)) >>  4;
	*ic_ld1 = (localVal & ((uint32_t)0x0000000C)) >>  2;
	*ic_ld0 = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint8_t ricu_afe_ctl_11_ic_refamp_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_11_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xC0000000)) >> 30);
}
__INLINE void ricu_afe_ctl_11_ic_refamp_7_setf(uint8_t icrefamp7)
{
	ASSERT_ERR((((uint32_t)icrefamp7 << 30) & ~((uint32_t)0xC0000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_11_ADDR, (REG_PL_RD(RICU_AFE_CTL_11_ADDR) & ~((uint32_t)0xC0000000)) | ((uint32_t)icrefamp7 <<30));
}
__INLINE uint8_t ricu_afe_ctl_11_ic_refamp_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_11_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x30000000)) >> 28);
}
__INLINE void ricu_afe_ctl_11_ic_refamp_6_setf(uint8_t icrefamp6)
{
	ASSERT_ERR((((uint32_t)icrefamp6 << 28) & ~((uint32_t)0x30000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_11_ADDR, (REG_PL_RD(RICU_AFE_CTL_11_ADDR) & ~((uint32_t)0x30000000)) | ((uint32_t)icrefamp6 <<28));
}
__INLINE uint8_t ricu_afe_ctl_11_ic_refamp_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_11_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0C000000)) >> 26);
}
__INLINE void ricu_afe_ctl_11_ic_refamp_5_setf(uint8_t icrefamp5)
{
	ASSERT_ERR((((uint32_t)icrefamp5 << 26) & ~((uint32_t)0x0C000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_11_ADDR, (REG_PL_RD(RICU_AFE_CTL_11_ADDR) & ~((uint32_t)0x0C000000)) | ((uint32_t)icrefamp5 <<26));
}
__INLINE uint8_t ricu_afe_ctl_11_ic_refamp_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_11_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x03000000)) >> 24);
}
__INLINE void ricu_afe_ctl_11_ic_refamp_4_setf(uint8_t icrefamp4)
{
	ASSERT_ERR((((uint32_t)icrefamp4 << 24) & ~((uint32_t)0x03000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_11_ADDR, (REG_PL_RD(RICU_AFE_CTL_11_ADDR) & ~((uint32_t)0x03000000)) | ((uint32_t)icrefamp4 <<24));
}
__INLINE uint8_t ricu_afe_ctl_11_ic_refamp_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_11_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00C00000)) >> 22);
}
__INLINE void ricu_afe_ctl_11_ic_refamp_3_setf(uint8_t icrefamp3)
{
	ASSERT_ERR((((uint32_t)icrefamp3 << 22) & ~((uint32_t)0x00C00000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_11_ADDR, (REG_PL_RD(RICU_AFE_CTL_11_ADDR) & ~((uint32_t)0x00C00000)) | ((uint32_t)icrefamp3 <<22));
}
__INLINE uint8_t ricu_afe_ctl_11_ic_refamp_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_11_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00300000)) >> 20);
}
__INLINE void ricu_afe_ctl_11_ic_refamp_2_setf(uint8_t icrefamp2)
{
	ASSERT_ERR((((uint32_t)icrefamp2 << 20) & ~((uint32_t)0x00300000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_11_ADDR, (REG_PL_RD(RICU_AFE_CTL_11_ADDR) & ~((uint32_t)0x00300000)) | ((uint32_t)icrefamp2 <<20));
}
__INLINE uint8_t ricu_afe_ctl_11_ic_refamp_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_11_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000C0000)) >> 18);
}
__INLINE void ricu_afe_ctl_11_ic_refamp_1_setf(uint8_t icrefamp1)
{
	ASSERT_ERR((((uint32_t)icrefamp1 << 18) & ~((uint32_t)0x000C0000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_11_ADDR, (REG_PL_RD(RICU_AFE_CTL_11_ADDR) & ~((uint32_t)0x000C0000)) | ((uint32_t)icrefamp1 <<18));
}
__INLINE uint8_t ricu_afe_ctl_11_ic_refamp_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_11_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00030000)) >> 16);
}
__INLINE void ricu_afe_ctl_11_ic_refamp_0_setf(uint8_t icrefamp0)
{
	ASSERT_ERR((((uint32_t)icrefamp0 << 16) & ~((uint32_t)0x00030000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_11_ADDR, (REG_PL_RD(RICU_AFE_CTL_11_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)icrefamp0 <<16));
}
__INLINE uint8_t ricu_afe_ctl_11_ic_ld_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_11_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000C000)) >> 14);
}
__INLINE void ricu_afe_ctl_11_ic_ld_7_setf(uint8_t icld7)
{
	ASSERT_ERR((((uint32_t)icld7 << 14) & ~((uint32_t)0x0000C000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_11_ADDR, (REG_PL_RD(RICU_AFE_CTL_11_ADDR) & ~((uint32_t)0x0000C000)) | ((uint32_t)icld7 <<14));
}
__INLINE uint8_t ricu_afe_ctl_11_ic_ld_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_11_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00003000)) >> 12);
}
__INLINE void ricu_afe_ctl_11_ic_ld_6_setf(uint8_t icld6)
{
	ASSERT_ERR((((uint32_t)icld6 << 12) & ~((uint32_t)0x00003000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_11_ADDR, (REG_PL_RD(RICU_AFE_CTL_11_ADDR) & ~((uint32_t)0x00003000)) | ((uint32_t)icld6 <<12));
}
__INLINE uint8_t ricu_afe_ctl_11_ic_ld_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_11_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000C00)) >> 10);
}
__INLINE void ricu_afe_ctl_11_ic_ld_5_setf(uint8_t icld5)
{
	ASSERT_ERR((((uint32_t)icld5 << 10) & ~((uint32_t)0x00000C00)) == 0);
	REG_PL_WR(RICU_AFE_CTL_11_ADDR, (REG_PL_RD(RICU_AFE_CTL_11_ADDR) & ~((uint32_t)0x00000C00)) | ((uint32_t)icld5 <<10));
}
__INLINE uint8_t ricu_afe_ctl_11_ic_ld_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_11_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000300)) >> 8);
}
__INLINE void ricu_afe_ctl_11_ic_ld_4_setf(uint8_t icld4)
{
	ASSERT_ERR((((uint32_t)icld4 << 8) & ~((uint32_t)0x00000300)) == 0);
	REG_PL_WR(RICU_AFE_CTL_11_ADDR, (REG_PL_RD(RICU_AFE_CTL_11_ADDR) & ~((uint32_t)0x00000300)) | ((uint32_t)icld4 <<8));
}
__INLINE uint8_t ricu_afe_ctl_11_ic_ld_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_11_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE void ricu_afe_ctl_11_ic_ld_3_setf(uint8_t icld3)
{
	ASSERT_ERR((((uint32_t)icld3 << 6) & ~((uint32_t)0x000000C0)) == 0);
	REG_PL_WR(RICU_AFE_CTL_11_ADDR, (REG_PL_RD(RICU_AFE_CTL_11_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)icld3 <<6));
}
__INLINE uint8_t ricu_afe_ctl_11_ic_ld_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_11_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000030)) >> 4);
}
__INLINE void ricu_afe_ctl_11_ic_ld_2_setf(uint8_t icld2)
{
	ASSERT_ERR((((uint32_t)icld2 << 4) & ~((uint32_t)0x00000030)) == 0);
	REG_PL_WR(RICU_AFE_CTL_11_ADDR, (REG_PL_RD(RICU_AFE_CTL_11_ADDR) & ~((uint32_t)0x00000030)) | ((uint32_t)icld2 <<4));
}
__INLINE uint8_t ricu_afe_ctl_11_ic_ld_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_11_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000C)) >> 2);
}
__INLINE void ricu_afe_ctl_11_ic_ld_1_setf(uint8_t icld1)
{
	ASSERT_ERR((((uint32_t)icld1 << 2) & ~((uint32_t)0x0000000C)) == 0);
	REG_PL_WR(RICU_AFE_CTL_11_ADDR, (REG_PL_RD(RICU_AFE_CTL_11_ADDR) & ~((uint32_t)0x0000000C)) | ((uint32_t)icld1 <<2));
}
__INLINE uint8_t ricu_afe_ctl_11_ic_ld_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_11_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void ricu_afe_ctl_11_ic_ld_0_setf(uint8_t icld0)
{
	ASSERT_ERR((((uint32_t)icld0 << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RICU_AFE_CTL_11_ADDR, (REG_PL_RD(RICU_AFE_CTL_11_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)icld0 <<0));
}

/**
 * @brief AFE_CTL_12 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:30 EOC_CTRL7                 0x0
 *    29:28 EOC_CTRL6                 0x0
 *    27:26 EOC_CTRL5                 0x0
 *    25:24 EOC_CTRL4                 0x0
 *    23:22 EOC_CTRL3                 0x0
 *    21:20 EOC_CTRL2                 0x0
 *    19:18 EOC_CTRL1                 0x0
 *    17:16 EOC_CTRL0                 0x0
 *    15:14 IC_REFSSF7                0x1
 *    13:12 IC_REFSSF6                0x1
 *    11:10 IC_REFSSF5                0x1
 *    09:08 IC_REFSSF4                0x1
 *    07:06 IC_REFSSF3                0x1
 *    05:04 IC_REFSSF2                0x1
 *    03:02 IC_REFSSF1                0x1
 *    01:00 IC_REFSSF0                0x1
 * </pre>
 */
#define RICU_AFE_CTL_12_ADDR        (REG_RICU_BASE_ADDR+0x00000040)
#define RICU_AFE_CTL_12_OFFSET      0x00000040
#define RICU_AFE_CTL_12_INDEX       0x00000010
#define RICU_AFE_CTL_12_RESET       0x00005555

__INLINE uint32_t  ricu_afe_ctl_12_get(void)
{
	return REG_PL_RD(RICU_AFE_CTL_12_ADDR);
}

__INLINE void ricu_afe_ctl_12_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTL_12_ADDR, value);
}

// field definitions
#define RICU_AFE_CTL_12_EOC_CTRL_7_MASK     ((uint32_t)0xC0000000)
#define RICU_AFE_CTL_12_EOC_CTRL_7_LSB      30
#define RICU_AFE_CTL_12_EOC_CTRL_7_WIDTH    ((uint32_t)0x00000002)
#define RICU_AFE_CTL_12_EOC_CTRL_6_MASK     ((uint32_t)0x30000000)
#define RICU_AFE_CTL_12_EOC_CTRL_6_LSB      28
#define RICU_AFE_CTL_12_EOC_CTRL_6_WIDTH    ((uint32_t)0x00000002)
#define RICU_AFE_CTL_12_EOC_CTRL_5_MASK     ((uint32_t)0x0C000000)
#define RICU_AFE_CTL_12_EOC_CTRL_5_LSB      26
#define RICU_AFE_CTL_12_EOC_CTRL_5_WIDTH    ((uint32_t)0x00000002)
#define RICU_AFE_CTL_12_EOC_CTRL_4_MASK     ((uint32_t)0x03000000)
#define RICU_AFE_CTL_12_EOC_CTRL_4_LSB      24
#define RICU_AFE_CTL_12_EOC_CTRL_4_WIDTH    ((uint32_t)0x00000002)
#define RICU_AFE_CTL_12_EOC_CTRL_3_MASK     ((uint32_t)0x00C00000)
#define RICU_AFE_CTL_12_EOC_CTRL_3_LSB      22
#define RICU_AFE_CTL_12_EOC_CTRL_3_WIDTH    ((uint32_t)0x00000002)
#define RICU_AFE_CTL_12_EOC_CTRL_2_MASK     ((uint32_t)0x00300000)
#define RICU_AFE_CTL_12_EOC_CTRL_2_LSB      20
#define RICU_AFE_CTL_12_EOC_CTRL_2_WIDTH    ((uint32_t)0x00000002)
#define RICU_AFE_CTL_12_EOC_CTRL_1_MASK     ((uint32_t)0x000C0000)
#define RICU_AFE_CTL_12_EOC_CTRL_1_LSB      18
#define RICU_AFE_CTL_12_EOC_CTRL_1_WIDTH    ((uint32_t)0x00000002)
#define RICU_AFE_CTL_12_EOC_CTRL_0_MASK     ((uint32_t)0x00030000)
#define RICU_AFE_CTL_12_EOC_CTRL_0_LSB      16
#define RICU_AFE_CTL_12_EOC_CTRL_0_WIDTH    ((uint32_t)0x00000002)
#define RICU_AFE_CTL_12_IC_REFSSF_7_MASK    ((uint32_t)0x0000C000)
#define RICU_AFE_CTL_12_IC_REFSSF_7_LSB     14
#define RICU_AFE_CTL_12_IC_REFSSF_7_WIDTH    ((uint32_t)0x00000002)
#define RICU_AFE_CTL_12_IC_REFSSF_6_MASK    ((uint32_t)0x00003000)
#define RICU_AFE_CTL_12_IC_REFSSF_6_LSB     12
#define RICU_AFE_CTL_12_IC_REFSSF_6_WIDTH    ((uint32_t)0x00000002)
#define RICU_AFE_CTL_12_IC_REFSSF_5_MASK    ((uint32_t)0x00000C00)
#define RICU_AFE_CTL_12_IC_REFSSF_5_LSB     10
#define RICU_AFE_CTL_12_IC_REFSSF_5_WIDTH    ((uint32_t)0x00000002)
#define RICU_AFE_CTL_12_IC_REFSSF_4_MASK    ((uint32_t)0x00000300)
#define RICU_AFE_CTL_12_IC_REFSSF_4_LSB     8
#define RICU_AFE_CTL_12_IC_REFSSF_4_WIDTH    ((uint32_t)0x00000002)
#define RICU_AFE_CTL_12_IC_REFSSF_3_MASK    ((uint32_t)0x000000C0)
#define RICU_AFE_CTL_12_IC_REFSSF_3_LSB     6
#define RICU_AFE_CTL_12_IC_REFSSF_3_WIDTH    ((uint32_t)0x00000002)
#define RICU_AFE_CTL_12_IC_REFSSF_2_MASK    ((uint32_t)0x00000030)
#define RICU_AFE_CTL_12_IC_REFSSF_2_LSB     4
#define RICU_AFE_CTL_12_IC_REFSSF_2_WIDTH    ((uint32_t)0x00000002)
#define RICU_AFE_CTL_12_IC_REFSSF_1_MASK    ((uint32_t)0x0000000C)
#define RICU_AFE_CTL_12_IC_REFSSF_1_LSB     2
#define RICU_AFE_CTL_12_IC_REFSSF_1_WIDTH    ((uint32_t)0x00000002)
#define RICU_AFE_CTL_12_IC_REFSSF_0_MASK    ((uint32_t)0x00000003)
#define RICU_AFE_CTL_12_IC_REFSSF_0_LSB     0
#define RICU_AFE_CTL_12_IC_REFSSF_0_WIDTH    ((uint32_t)0x00000002)

#define RICU_AFE_CTL_12_EOC_CTRL_7_RST      0x0
#define RICU_AFE_CTL_12_EOC_CTRL_6_RST      0x0
#define RICU_AFE_CTL_12_EOC_CTRL_5_RST      0x0
#define RICU_AFE_CTL_12_EOC_CTRL_4_RST      0x0
#define RICU_AFE_CTL_12_EOC_CTRL_3_RST      0x0
#define RICU_AFE_CTL_12_EOC_CTRL_2_RST      0x0
#define RICU_AFE_CTL_12_EOC_CTRL_1_RST      0x0
#define RICU_AFE_CTL_12_EOC_CTRL_0_RST      0x0
#define RICU_AFE_CTL_12_IC_REFSSF_7_RST     0x1
#define RICU_AFE_CTL_12_IC_REFSSF_6_RST     0x1
#define RICU_AFE_CTL_12_IC_REFSSF_5_RST     0x1
#define RICU_AFE_CTL_12_IC_REFSSF_4_RST     0x1
#define RICU_AFE_CTL_12_IC_REFSSF_3_RST     0x1
#define RICU_AFE_CTL_12_IC_REFSSF_2_RST     0x1
#define RICU_AFE_CTL_12_IC_REFSSF_1_RST     0x1
#define RICU_AFE_CTL_12_IC_REFSSF_0_RST     0x1

__INLINE void ricu_afe_ctl_12_pack(uint8_t eoc_ctrl7, uint8_t eoc_ctrl6, uint8_t eoc_ctrl5, uint8_t eoc_ctrl4, uint8_t eoc_ctrl3, uint8_t eoc_ctrl2, uint8_t eoc_ctrl1, uint8_t eoc_ctrl0, uint8_t ic_refssf7, uint8_t ic_refssf6, uint8_t ic_refssf5, uint8_t ic_refssf4, uint8_t ic_refssf3, uint8_t ic_refssf2, uint8_t ic_refssf1, uint8_t ic_refssf0)
{
	ASSERT_ERR((((uint32_t)eoc_ctrl7 << 30) & ~((uint32_t)0xC0000000)) == 0);
	ASSERT_ERR((((uint32_t)eoc_ctrl6 << 28) & ~((uint32_t)0x30000000)) == 0);
	ASSERT_ERR((((uint32_t)eoc_ctrl5 << 26) & ~((uint32_t)0x0C000000)) == 0);
	ASSERT_ERR((((uint32_t)eoc_ctrl4 << 24) & ~((uint32_t)0x03000000)) == 0);
	ASSERT_ERR((((uint32_t)eoc_ctrl3 << 22) & ~((uint32_t)0x00C00000)) == 0);
	ASSERT_ERR((((uint32_t)eoc_ctrl2 << 20) & ~((uint32_t)0x00300000)) == 0);
	ASSERT_ERR((((uint32_t)eoc_ctrl1 << 18) & ~((uint32_t)0x000C0000)) == 0);
	ASSERT_ERR((((uint32_t)eoc_ctrl0 << 16) & ~((uint32_t)0x00030000)) == 0);
	ASSERT_ERR((((uint32_t)ic_refssf7 << 14) & ~((uint32_t)0x0000C000)) == 0);
	ASSERT_ERR((((uint32_t)ic_refssf6 << 12) & ~((uint32_t)0x00003000)) == 0);
	ASSERT_ERR((((uint32_t)ic_refssf5 << 10) & ~((uint32_t)0x00000C00)) == 0);
	ASSERT_ERR((((uint32_t)ic_refssf4 << 8) & ~((uint32_t)0x00000300)) == 0);
	ASSERT_ERR((((uint32_t)ic_refssf3 << 6) & ~((uint32_t)0x000000C0)) == 0);
	ASSERT_ERR((((uint32_t)ic_refssf2 << 4) & ~((uint32_t)0x00000030)) == 0);
	ASSERT_ERR((((uint32_t)ic_refssf1 << 2) & ~((uint32_t)0x0000000C)) == 0);
	ASSERT_ERR((((uint32_t)ic_refssf0 << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RICU_AFE_CTL_12_ADDR,  ((uint32_t)eoc_ctrl7 << 30) |((uint32_t)eoc_ctrl6 << 28) |((uint32_t)eoc_ctrl5 << 26) |((uint32_t)eoc_ctrl4 << 24) |((uint32_t)eoc_ctrl3 << 22) |((uint32_t)eoc_ctrl2 << 20) |((uint32_t)eoc_ctrl1 << 18) |((uint32_t)eoc_ctrl0 << 16) |((uint32_t)ic_refssf7 << 14) |((uint32_t)ic_refssf6 << 12) |((uint32_t)ic_refssf5 << 10) |((uint32_t)ic_refssf4 << 8) |((uint32_t)ic_refssf3 << 6) |((uint32_t)ic_refssf2 << 4) |((uint32_t)ic_refssf1 << 2) |((uint32_t)ic_refssf0 << 0));
}

__INLINE void ricu_afe_ctl_12_unpack(uint8_t* eoc_ctrl7, uint8_t* eoc_ctrl6, uint8_t* eoc_ctrl5, uint8_t* eoc_ctrl4, uint8_t* eoc_ctrl3, uint8_t* eoc_ctrl2, uint8_t* eoc_ctrl1, uint8_t* eoc_ctrl0, uint8_t* ic_refssf7, uint8_t* ic_refssf6, uint8_t* ic_refssf5, uint8_t* ic_refssf4, uint8_t* ic_refssf3, uint8_t* ic_refssf2, uint8_t* ic_refssf1, uint8_t* ic_refssf0)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_12_ADDR);

	*eoc_ctrl7 = (localVal & ((uint32_t)0xC0000000)) >>  30;
	*eoc_ctrl6 = (localVal & ((uint32_t)0x30000000)) >>  28;
	*eoc_ctrl5 = (localVal & ((uint32_t)0x0C000000)) >>  26;
	*eoc_ctrl4 = (localVal & ((uint32_t)0x03000000)) >>  24;
	*eoc_ctrl3 = (localVal & ((uint32_t)0x00C00000)) >>  22;
	*eoc_ctrl2 = (localVal & ((uint32_t)0x00300000)) >>  20;
	*eoc_ctrl1 = (localVal & ((uint32_t)0x000C0000)) >>  18;
	*eoc_ctrl0 = (localVal & ((uint32_t)0x00030000)) >>  16;
	*ic_refssf7 = (localVal & ((uint32_t)0x0000C000)) >>  14;
	*ic_refssf6 = (localVal & ((uint32_t)0x00003000)) >>  12;
	*ic_refssf5 = (localVal & ((uint32_t)0x00000C00)) >>  10;
	*ic_refssf4 = (localVal & ((uint32_t)0x00000300)) >>  8;
	*ic_refssf3 = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*ic_refssf2 = (localVal & ((uint32_t)0x00000030)) >>  4;
	*ic_refssf1 = (localVal & ((uint32_t)0x0000000C)) >>  2;
	*ic_refssf0 = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint8_t ricu_afe_ctl_12_eoc_ctrl_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_12_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xC0000000)) >> 30);
}
__INLINE void ricu_afe_ctl_12_eoc_ctrl_7_setf(uint8_t eocctrl7)
{
	ASSERT_ERR((((uint32_t)eocctrl7 << 30) & ~((uint32_t)0xC0000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_12_ADDR, (REG_PL_RD(RICU_AFE_CTL_12_ADDR) & ~((uint32_t)0xC0000000)) | ((uint32_t)eocctrl7 <<30));
}
__INLINE uint8_t ricu_afe_ctl_12_eoc_ctrl_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_12_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x30000000)) >> 28);
}
__INLINE void ricu_afe_ctl_12_eoc_ctrl_6_setf(uint8_t eocctrl6)
{
	ASSERT_ERR((((uint32_t)eocctrl6 << 28) & ~((uint32_t)0x30000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_12_ADDR, (REG_PL_RD(RICU_AFE_CTL_12_ADDR) & ~((uint32_t)0x30000000)) | ((uint32_t)eocctrl6 <<28));
}
__INLINE uint8_t ricu_afe_ctl_12_eoc_ctrl_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_12_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0C000000)) >> 26);
}
__INLINE void ricu_afe_ctl_12_eoc_ctrl_5_setf(uint8_t eocctrl5)
{
	ASSERT_ERR((((uint32_t)eocctrl5 << 26) & ~((uint32_t)0x0C000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_12_ADDR, (REG_PL_RD(RICU_AFE_CTL_12_ADDR) & ~((uint32_t)0x0C000000)) | ((uint32_t)eocctrl5 <<26));
}
__INLINE uint8_t ricu_afe_ctl_12_eoc_ctrl_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_12_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x03000000)) >> 24);
}
__INLINE void ricu_afe_ctl_12_eoc_ctrl_4_setf(uint8_t eocctrl4)
{
	ASSERT_ERR((((uint32_t)eocctrl4 << 24) & ~((uint32_t)0x03000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_12_ADDR, (REG_PL_RD(RICU_AFE_CTL_12_ADDR) & ~((uint32_t)0x03000000)) | ((uint32_t)eocctrl4 <<24));
}
__INLINE uint8_t ricu_afe_ctl_12_eoc_ctrl_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_12_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00C00000)) >> 22);
}
__INLINE void ricu_afe_ctl_12_eoc_ctrl_3_setf(uint8_t eocctrl3)
{
	ASSERT_ERR((((uint32_t)eocctrl3 << 22) & ~((uint32_t)0x00C00000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_12_ADDR, (REG_PL_RD(RICU_AFE_CTL_12_ADDR) & ~((uint32_t)0x00C00000)) | ((uint32_t)eocctrl3 <<22));
}
__INLINE uint8_t ricu_afe_ctl_12_eoc_ctrl_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_12_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00300000)) >> 20);
}
__INLINE void ricu_afe_ctl_12_eoc_ctrl_2_setf(uint8_t eocctrl2)
{
	ASSERT_ERR((((uint32_t)eocctrl2 << 20) & ~((uint32_t)0x00300000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_12_ADDR, (REG_PL_RD(RICU_AFE_CTL_12_ADDR) & ~((uint32_t)0x00300000)) | ((uint32_t)eocctrl2 <<20));
}
__INLINE uint8_t ricu_afe_ctl_12_eoc_ctrl_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_12_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000C0000)) >> 18);
}
__INLINE void ricu_afe_ctl_12_eoc_ctrl_1_setf(uint8_t eocctrl1)
{
	ASSERT_ERR((((uint32_t)eocctrl1 << 18) & ~((uint32_t)0x000C0000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_12_ADDR, (REG_PL_RD(RICU_AFE_CTL_12_ADDR) & ~((uint32_t)0x000C0000)) | ((uint32_t)eocctrl1 <<18));
}
__INLINE uint8_t ricu_afe_ctl_12_eoc_ctrl_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_12_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00030000)) >> 16);
}
__INLINE void ricu_afe_ctl_12_eoc_ctrl_0_setf(uint8_t eocctrl0)
{
	ASSERT_ERR((((uint32_t)eocctrl0 << 16) & ~((uint32_t)0x00030000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_12_ADDR, (REG_PL_RD(RICU_AFE_CTL_12_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)eocctrl0 <<16));
}
__INLINE uint8_t ricu_afe_ctl_12_ic_refssf_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_12_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000C000)) >> 14);
}
__INLINE void ricu_afe_ctl_12_ic_refssf_7_setf(uint8_t icrefssf7)
{
	ASSERT_ERR((((uint32_t)icrefssf7 << 14) & ~((uint32_t)0x0000C000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_12_ADDR, (REG_PL_RD(RICU_AFE_CTL_12_ADDR) & ~((uint32_t)0x0000C000)) | ((uint32_t)icrefssf7 <<14));
}
__INLINE uint8_t ricu_afe_ctl_12_ic_refssf_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_12_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00003000)) >> 12);
}
__INLINE void ricu_afe_ctl_12_ic_refssf_6_setf(uint8_t icrefssf6)
{
	ASSERT_ERR((((uint32_t)icrefssf6 << 12) & ~((uint32_t)0x00003000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_12_ADDR, (REG_PL_RD(RICU_AFE_CTL_12_ADDR) & ~((uint32_t)0x00003000)) | ((uint32_t)icrefssf6 <<12));
}
__INLINE uint8_t ricu_afe_ctl_12_ic_refssf_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_12_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000C00)) >> 10);
}
__INLINE void ricu_afe_ctl_12_ic_refssf_5_setf(uint8_t icrefssf5)
{
	ASSERT_ERR((((uint32_t)icrefssf5 << 10) & ~((uint32_t)0x00000C00)) == 0);
	REG_PL_WR(RICU_AFE_CTL_12_ADDR, (REG_PL_RD(RICU_AFE_CTL_12_ADDR) & ~((uint32_t)0x00000C00)) | ((uint32_t)icrefssf5 <<10));
}
__INLINE uint8_t ricu_afe_ctl_12_ic_refssf_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_12_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000300)) >> 8);
}
__INLINE void ricu_afe_ctl_12_ic_refssf_4_setf(uint8_t icrefssf4)
{
	ASSERT_ERR((((uint32_t)icrefssf4 << 8) & ~((uint32_t)0x00000300)) == 0);
	REG_PL_WR(RICU_AFE_CTL_12_ADDR, (REG_PL_RD(RICU_AFE_CTL_12_ADDR) & ~((uint32_t)0x00000300)) | ((uint32_t)icrefssf4 <<8));
}
__INLINE uint8_t ricu_afe_ctl_12_ic_refssf_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_12_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE void ricu_afe_ctl_12_ic_refssf_3_setf(uint8_t icrefssf3)
{
	ASSERT_ERR((((uint32_t)icrefssf3 << 6) & ~((uint32_t)0x000000C0)) == 0);
	REG_PL_WR(RICU_AFE_CTL_12_ADDR, (REG_PL_RD(RICU_AFE_CTL_12_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)icrefssf3 <<6));
}
__INLINE uint8_t ricu_afe_ctl_12_ic_refssf_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_12_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000030)) >> 4);
}
__INLINE void ricu_afe_ctl_12_ic_refssf_2_setf(uint8_t icrefssf2)
{
	ASSERT_ERR((((uint32_t)icrefssf2 << 4) & ~((uint32_t)0x00000030)) == 0);
	REG_PL_WR(RICU_AFE_CTL_12_ADDR, (REG_PL_RD(RICU_AFE_CTL_12_ADDR) & ~((uint32_t)0x00000030)) | ((uint32_t)icrefssf2 <<4));
}
__INLINE uint8_t ricu_afe_ctl_12_ic_refssf_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_12_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000C)) >> 2);
}
__INLINE void ricu_afe_ctl_12_ic_refssf_1_setf(uint8_t icrefssf1)
{
	ASSERT_ERR((((uint32_t)icrefssf1 << 2) & ~((uint32_t)0x0000000C)) == 0);
	REG_PL_WR(RICU_AFE_CTL_12_ADDR, (REG_PL_RD(RICU_AFE_CTL_12_ADDR) & ~((uint32_t)0x0000000C)) | ((uint32_t)icrefssf1 <<2));
}
__INLINE uint8_t ricu_afe_ctl_12_ic_refssf_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_12_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void ricu_afe_ctl_12_ic_refssf_0_setf(uint8_t icrefssf0)
{
	ASSERT_ERR((((uint32_t)icrefssf0 << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RICU_AFE_CTL_12_ADDR, (REG_PL_RD(RICU_AFE_CTL_12_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)icrefssf0 <<0));
}

/**
 * @brief AFE_CTL_13 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    FORCE_ADC_ON_PHY1         0              
 *    30    FORCE_ADC_ON_PHY0         0              
 *    16    EN_LB8_AUX                0              
 *    15    EN_LB7                    0              
 *    14    EN_LB6                    0              
 *    13    EN_LB5                    0              
 *    12    EN_LB4                    0              
 *    11    EN_LB3                    0              
 *    10    EN_LB2                    0              
 *    09    EN_LB1                    0              
 *    08    EN_LB0                    0              
 * </pre>
 */
#define RICU_AFE_CTL_13_ADDR        (REG_RICU_BASE_ADDR+0x00000044)
#define RICU_AFE_CTL_13_OFFSET      0x00000044
#define RICU_AFE_CTL_13_INDEX       0x00000011
#define RICU_AFE_CTL_13_RESET       0x00000000

__INLINE uint32_t  ricu_afe_ctl_13_get(void)
{
	return REG_PL_RD(RICU_AFE_CTL_13_ADDR);
}

__INLINE void ricu_afe_ctl_13_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTL_13_ADDR, value);
}

// field definitions
#define RICU_AFE_CTL_13_FORCE_ADC_ON_PHY_1_BIT    ((uint32_t)0x80000000)
#define RICU_AFE_CTL_13_FORCE_ADC_ON_PHY_1_POS    31
#define RICU_AFE_CTL_13_FORCE_ADC_ON_PHY_0_BIT    ((uint32_t)0x40000000)
#define RICU_AFE_CTL_13_FORCE_ADC_ON_PHY_0_POS    30
#define RICU_AFE_CTL_13_EN_LB_8_AUX_BIT     ((uint32_t)0x00010000)
#define RICU_AFE_CTL_13_EN_LB_8_AUX_POS     16
#define RICU_AFE_CTL_13_EN_LB_7_BIT         ((uint32_t)0x00008000)
#define RICU_AFE_CTL_13_EN_LB_7_POS         15
#define RICU_AFE_CTL_13_EN_LB_6_BIT         ((uint32_t)0x00004000)
#define RICU_AFE_CTL_13_EN_LB_6_POS         14
#define RICU_AFE_CTL_13_EN_LB_5_BIT         ((uint32_t)0x00002000)
#define RICU_AFE_CTL_13_EN_LB_5_POS         13
#define RICU_AFE_CTL_13_EN_LB_4_BIT         ((uint32_t)0x00001000)
#define RICU_AFE_CTL_13_EN_LB_4_POS         12
#define RICU_AFE_CTL_13_EN_LB_3_BIT         ((uint32_t)0x00000800)
#define RICU_AFE_CTL_13_EN_LB_3_POS         11
#define RICU_AFE_CTL_13_EN_LB_2_BIT         ((uint32_t)0x00000400)
#define RICU_AFE_CTL_13_EN_LB_2_POS         10
#define RICU_AFE_CTL_13_EN_LB_1_BIT         ((uint32_t)0x00000200)
#define RICU_AFE_CTL_13_EN_LB_1_POS         9
#define RICU_AFE_CTL_13_EN_LB_0_BIT         ((uint32_t)0x00000100)
#define RICU_AFE_CTL_13_EN_LB_0_POS         8

#define RICU_AFE_CTL_13_FORCE_ADC_ON_PHY_1_RST    0x0
#define RICU_AFE_CTL_13_FORCE_ADC_ON_PHY_0_RST    0x0
#define RICU_AFE_CTL_13_EN_LB_8_AUX_RST     0x0
#define RICU_AFE_CTL_13_EN_LB_7_RST         0x0
#define RICU_AFE_CTL_13_EN_LB_6_RST         0x0
#define RICU_AFE_CTL_13_EN_LB_5_RST         0x0
#define RICU_AFE_CTL_13_EN_LB_4_RST         0x0
#define RICU_AFE_CTL_13_EN_LB_3_RST         0x0
#define RICU_AFE_CTL_13_EN_LB_2_RST         0x0
#define RICU_AFE_CTL_13_EN_LB_1_RST         0x0
#define RICU_AFE_CTL_13_EN_LB_0_RST         0x0

__INLINE void ricu_afe_ctl_13_pack(uint8_t force_adc_on_phy1, uint8_t force_adc_on_phy0, uint8_t en_lb8_aux, uint8_t en_lb7, uint8_t en_lb6, uint8_t en_lb5, uint8_t en_lb4, uint8_t en_lb3, uint8_t en_lb2, uint8_t en_lb1, uint8_t en_lb0)
{
	ASSERT_ERR((((uint32_t)force_adc_on_phy1 << 31) & ~((uint32_t)0x80000000)) == 0);
	ASSERT_ERR((((uint32_t)force_adc_on_phy0 << 30) & ~((uint32_t)0x40000000)) == 0);
	ASSERT_ERR((((uint32_t)en_lb8_aux << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)en_lb7 << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)en_lb6 << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)en_lb5 << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)en_lb4 << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)en_lb3 << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)en_lb2 << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)en_lb1 << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)en_lb0 << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(RICU_AFE_CTL_13_ADDR,  ((uint32_t)force_adc_on_phy1 << 31) |((uint32_t)force_adc_on_phy0 << 30) |((uint32_t)en_lb8_aux << 16) |((uint32_t)en_lb7 << 15) |((uint32_t)en_lb6 << 14) |((uint32_t)en_lb5 << 13) |((uint32_t)en_lb4 << 12) |((uint32_t)en_lb3 << 11) |((uint32_t)en_lb2 << 10) |((uint32_t)en_lb1 << 9) |((uint32_t)en_lb0 << 8));
}

__INLINE void ricu_afe_ctl_13_unpack(uint8_t* force_adc_on_phy1, uint8_t* force_adc_on_phy0, uint8_t* en_lb8_aux, uint8_t* en_lb7, uint8_t* en_lb6, uint8_t* en_lb5, uint8_t* en_lb4, uint8_t* en_lb3, uint8_t* en_lb2, uint8_t* en_lb1, uint8_t* en_lb0)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_13_ADDR);

	*force_adc_on_phy1 = (localVal & ((uint32_t)0x80000000)) >>  31;
	*force_adc_on_phy0 = (localVal & ((uint32_t)0x40000000)) >>  30;
	*en_lb8_aux = (localVal & ((uint32_t)0x00010000)) >>  16;
	*en_lb7 = (localVal & ((uint32_t)0x00008000)) >>  15;
	*en_lb6 = (localVal & ((uint32_t)0x00004000)) >>  14;
	*en_lb5 = (localVal & ((uint32_t)0x00002000)) >>  13;
	*en_lb4 = (localVal & ((uint32_t)0x00001000)) >>  12;
	*en_lb3 = (localVal & ((uint32_t)0x00000800)) >>  11;
	*en_lb2 = (localVal & ((uint32_t)0x00000400)) >>  10;
	*en_lb1 = (localVal & ((uint32_t)0x00000200)) >>  9;
	*en_lb0 = (localVal & ((uint32_t)0x00000100)) >>  8;
}

__INLINE uint8_t ricu_afe_ctl_13_force_adc_on_phy_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_13_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE void ricu_afe_ctl_13_force_adc_on_phy_1_setf(uint8_t forceadconphy1)
{
	ASSERT_ERR((((uint32_t)forceadconphy1 << 31) & ~((uint32_t)0x80000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_13_ADDR, (REG_PL_RD(RICU_AFE_CTL_13_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)forceadconphy1 <<31));
}
__INLINE uint8_t ricu_afe_ctl_13_force_adc_on_phy_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_13_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x40000000)) >> 30);
}
__INLINE void ricu_afe_ctl_13_force_adc_on_phy_0_setf(uint8_t forceadconphy0)
{
	ASSERT_ERR((((uint32_t)forceadconphy0 << 30) & ~((uint32_t)0x40000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_13_ADDR, (REG_PL_RD(RICU_AFE_CTL_13_ADDR) & ~((uint32_t)0x40000000)) | ((uint32_t)forceadconphy0 <<30));
}
__INLINE uint8_t ricu_afe_ctl_13_en_lb_8_aux_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_13_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void ricu_afe_ctl_13_en_lb_8_aux_setf(uint8_t enlb8aux)
{
	ASSERT_ERR((((uint32_t)enlb8aux << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_13_ADDR, (REG_PL_RD(RICU_AFE_CTL_13_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)enlb8aux <<16));
}
__INLINE uint8_t ricu_afe_ctl_13_en_lb_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_13_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void ricu_afe_ctl_13_en_lb_7_setf(uint8_t enlb7)
{
	ASSERT_ERR((((uint32_t)enlb7 << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_13_ADDR, (REG_PL_RD(RICU_AFE_CTL_13_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)enlb7 <<15));
}
__INLINE uint8_t ricu_afe_ctl_13_en_lb_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_13_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void ricu_afe_ctl_13_en_lb_6_setf(uint8_t enlb6)
{
	ASSERT_ERR((((uint32_t)enlb6 << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_13_ADDR, (REG_PL_RD(RICU_AFE_CTL_13_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)enlb6 <<14));
}
__INLINE uint8_t ricu_afe_ctl_13_en_lb_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_13_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void ricu_afe_ctl_13_en_lb_5_setf(uint8_t enlb5)
{
	ASSERT_ERR((((uint32_t)enlb5 << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_13_ADDR, (REG_PL_RD(RICU_AFE_CTL_13_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)enlb5 <<13));
}
__INLINE uint8_t ricu_afe_ctl_13_en_lb_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_13_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void ricu_afe_ctl_13_en_lb_4_setf(uint8_t enlb4)
{
	ASSERT_ERR((((uint32_t)enlb4 << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_13_ADDR, (REG_PL_RD(RICU_AFE_CTL_13_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)enlb4 <<12));
}
__INLINE uint8_t ricu_afe_ctl_13_en_lb_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_13_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void ricu_afe_ctl_13_en_lb_3_setf(uint8_t enlb3)
{
	ASSERT_ERR((((uint32_t)enlb3 << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(RICU_AFE_CTL_13_ADDR, (REG_PL_RD(RICU_AFE_CTL_13_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)enlb3 <<11));
}
__INLINE uint8_t ricu_afe_ctl_13_en_lb_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_13_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void ricu_afe_ctl_13_en_lb_2_setf(uint8_t enlb2)
{
	ASSERT_ERR((((uint32_t)enlb2 << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(RICU_AFE_CTL_13_ADDR, (REG_PL_RD(RICU_AFE_CTL_13_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)enlb2 <<10));
}
__INLINE uint8_t ricu_afe_ctl_13_en_lb_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_13_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void ricu_afe_ctl_13_en_lb_1_setf(uint8_t enlb1)
{
	ASSERT_ERR((((uint32_t)enlb1 << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(RICU_AFE_CTL_13_ADDR, (REG_PL_RD(RICU_AFE_CTL_13_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)enlb1 <<9));
}
__INLINE uint8_t ricu_afe_ctl_13_en_lb_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_13_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void ricu_afe_ctl_13_en_lb_0_setf(uint8_t enlb0)
{
	ASSERT_ERR((((uint32_t)enlb0 << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(RICU_AFE_CTL_13_ADDR, (REG_PL_RD(RICU_AFE_CTL_13_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)enlb0 <<8));
}

/**
 * @brief AFE_CTL_14 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    30:28 DEC7                      0x0
 *    26:24 DEC6                      0x0
 *    22:20 DEC5                      0x0
 *    18:16 DEC4                      0x0
 *    14:12 DEC3                      0x0
 *    10:08 DEC2                      0x0
 *    06:04 DEC1                      0x0
 *    02:00 DEC0                      0x0
 * </pre>
 */
#define RICU_AFE_CTL_14_ADDR        (REG_RICU_BASE_ADDR+0x00000048)
#define RICU_AFE_CTL_14_OFFSET      0x00000048
#define RICU_AFE_CTL_14_INDEX       0x00000012
#define RICU_AFE_CTL_14_RESET       0x00000000

__INLINE uint32_t  ricu_afe_ctl_14_get(void)
{
	return REG_PL_RD(RICU_AFE_CTL_14_ADDR);
}

__INLINE void ricu_afe_ctl_14_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTL_14_ADDR, value);
}

// field definitions
#define RICU_AFE_CTL_14_DEC_7_MASK          ((uint32_t)0x70000000)
#define RICU_AFE_CTL_14_DEC_7_LSB           28
#define RICU_AFE_CTL_14_DEC_7_WIDTH         ((uint32_t)0x00000003)
#define RICU_AFE_CTL_14_DEC_6_MASK          ((uint32_t)0x07000000)
#define RICU_AFE_CTL_14_DEC_6_LSB           24
#define RICU_AFE_CTL_14_DEC_6_WIDTH         ((uint32_t)0x00000003)
#define RICU_AFE_CTL_14_DEC_5_MASK          ((uint32_t)0x00700000)
#define RICU_AFE_CTL_14_DEC_5_LSB           20
#define RICU_AFE_CTL_14_DEC_5_WIDTH         ((uint32_t)0x00000003)
#define RICU_AFE_CTL_14_DEC_4_MASK          ((uint32_t)0x00070000)
#define RICU_AFE_CTL_14_DEC_4_LSB           16
#define RICU_AFE_CTL_14_DEC_4_WIDTH         ((uint32_t)0x00000003)
#define RICU_AFE_CTL_14_DEC_3_MASK          ((uint32_t)0x00007000)
#define RICU_AFE_CTL_14_DEC_3_LSB           12
#define RICU_AFE_CTL_14_DEC_3_WIDTH         ((uint32_t)0x00000003)
#define RICU_AFE_CTL_14_DEC_2_MASK          ((uint32_t)0x00000700)
#define RICU_AFE_CTL_14_DEC_2_LSB           8
#define RICU_AFE_CTL_14_DEC_2_WIDTH         ((uint32_t)0x00000003)
#define RICU_AFE_CTL_14_DEC_1_MASK          ((uint32_t)0x00000070)
#define RICU_AFE_CTL_14_DEC_1_LSB           4
#define RICU_AFE_CTL_14_DEC_1_WIDTH         ((uint32_t)0x00000003)
#define RICU_AFE_CTL_14_DEC_0_MASK          ((uint32_t)0x00000007)
#define RICU_AFE_CTL_14_DEC_0_LSB           0
#define RICU_AFE_CTL_14_DEC_0_WIDTH         ((uint32_t)0x00000003)

#define RICU_AFE_CTL_14_DEC_7_RST           0x0
#define RICU_AFE_CTL_14_DEC_6_RST           0x0
#define RICU_AFE_CTL_14_DEC_5_RST           0x0
#define RICU_AFE_CTL_14_DEC_4_RST           0x0
#define RICU_AFE_CTL_14_DEC_3_RST           0x0
#define RICU_AFE_CTL_14_DEC_2_RST           0x0
#define RICU_AFE_CTL_14_DEC_1_RST           0x0
#define RICU_AFE_CTL_14_DEC_0_RST           0x0

__INLINE void ricu_afe_ctl_14_pack(uint8_t dec7, uint8_t dec6, uint8_t dec5, uint8_t dec4, uint8_t dec3, uint8_t dec2, uint8_t dec1, uint8_t dec0)
{
	ASSERT_ERR((((uint32_t)dec7 << 28) & ~((uint32_t)0x70000000)) == 0);
	ASSERT_ERR((((uint32_t)dec6 << 24) & ~((uint32_t)0x07000000)) == 0);
	ASSERT_ERR((((uint32_t)dec5 << 20) & ~((uint32_t)0x00700000)) == 0);
	ASSERT_ERR((((uint32_t)dec4 << 16) & ~((uint32_t)0x00070000)) == 0);
	ASSERT_ERR((((uint32_t)dec3 << 12) & ~((uint32_t)0x00007000)) == 0);
	ASSERT_ERR((((uint32_t)dec2 << 8) & ~((uint32_t)0x00000700)) == 0);
	ASSERT_ERR((((uint32_t)dec1 << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)dec0 << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(RICU_AFE_CTL_14_ADDR,  ((uint32_t)dec7 << 28) |((uint32_t)dec6 << 24) |((uint32_t)dec5 << 20) |((uint32_t)dec4 << 16) |((uint32_t)dec3 << 12) |((uint32_t)dec2 << 8) |((uint32_t)dec1 << 4) |((uint32_t)dec0 << 0));
}

__INLINE void ricu_afe_ctl_14_unpack(uint8_t* dec7, uint8_t* dec6, uint8_t* dec5, uint8_t* dec4, uint8_t* dec3, uint8_t* dec2, uint8_t* dec1, uint8_t* dec0)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_14_ADDR);

	*dec7 = (localVal & ((uint32_t)0x70000000)) >>  28;
	*dec6 = (localVal & ((uint32_t)0x07000000)) >>  24;
	*dec5 = (localVal & ((uint32_t)0x00700000)) >>  20;
	*dec4 = (localVal & ((uint32_t)0x00070000)) >>  16;
	*dec3 = (localVal & ((uint32_t)0x00007000)) >>  12;
	*dec2 = (localVal & ((uint32_t)0x00000700)) >>  8;
	*dec1 = (localVal & ((uint32_t)0x00000070)) >>  4;
	*dec0 = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t ricu_afe_ctl_14_dec_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_14_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x70000000)) >> 28);
}
__INLINE void ricu_afe_ctl_14_dec_7_setf(uint8_t dec7)
{
	ASSERT_ERR((((uint32_t)dec7 << 28) & ~((uint32_t)0x70000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_14_ADDR, (REG_PL_RD(RICU_AFE_CTL_14_ADDR) & ~((uint32_t)0x70000000)) | ((uint32_t)dec7 <<28));
}
__INLINE uint8_t ricu_afe_ctl_14_dec_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_14_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE void ricu_afe_ctl_14_dec_6_setf(uint8_t dec6)
{
	ASSERT_ERR((((uint32_t)dec6 << 24) & ~((uint32_t)0x07000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_14_ADDR, (REG_PL_RD(RICU_AFE_CTL_14_ADDR) & ~((uint32_t)0x07000000)) | ((uint32_t)dec6 <<24));
}
__INLINE uint8_t ricu_afe_ctl_14_dec_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_14_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00700000)) >> 20);
}
__INLINE void ricu_afe_ctl_14_dec_5_setf(uint8_t dec5)
{
	ASSERT_ERR((((uint32_t)dec5 << 20) & ~((uint32_t)0x00700000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_14_ADDR, (REG_PL_RD(RICU_AFE_CTL_14_ADDR) & ~((uint32_t)0x00700000)) | ((uint32_t)dec5 <<20));
}
__INLINE uint8_t ricu_afe_ctl_14_dec_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_14_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00070000)) >> 16);
}
__INLINE void ricu_afe_ctl_14_dec_4_setf(uint8_t dec4)
{
	ASSERT_ERR((((uint32_t)dec4 << 16) & ~((uint32_t)0x00070000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_14_ADDR, (REG_PL_RD(RICU_AFE_CTL_14_ADDR) & ~((uint32_t)0x00070000)) | ((uint32_t)dec4 <<16));
}
__INLINE uint8_t ricu_afe_ctl_14_dec_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_14_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007000)) >> 12);
}
__INLINE void ricu_afe_ctl_14_dec_3_setf(uint8_t dec3)
{
	ASSERT_ERR((((uint32_t)dec3 << 12) & ~((uint32_t)0x00007000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_14_ADDR, (REG_PL_RD(RICU_AFE_CTL_14_ADDR) & ~((uint32_t)0x00007000)) | ((uint32_t)dec3 <<12));
}
__INLINE uint8_t ricu_afe_ctl_14_dec_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_14_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000700)) >> 8);
}
__INLINE void ricu_afe_ctl_14_dec_2_setf(uint8_t dec2)
{
	ASSERT_ERR((((uint32_t)dec2 << 8) & ~((uint32_t)0x00000700)) == 0);
	REG_PL_WR(RICU_AFE_CTL_14_ADDR, (REG_PL_RD(RICU_AFE_CTL_14_ADDR) & ~((uint32_t)0x00000700)) | ((uint32_t)dec2 <<8));
}
__INLINE uint8_t ricu_afe_ctl_14_dec_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_14_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void ricu_afe_ctl_14_dec_1_setf(uint8_t dec1)
{
	ASSERT_ERR((((uint32_t)dec1 << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(RICU_AFE_CTL_14_ADDR, (REG_PL_RD(RICU_AFE_CTL_14_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)dec1 <<4));
}
__INLINE uint8_t ricu_afe_ctl_14_dec_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_14_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void ricu_afe_ctl_14_dec_0_setf(uint8_t dec0)
{
	ASSERT_ERR((((uint32_t)dec0 << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(RICU_AFE_CTL_14_ADDR, (REG_PL_RD(RICU_AFE_CTL_14_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)dec0 <<0));
}

/**
 * @brief AFE_CTL_15 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    30:28 EN_OUT_CM7                0x0
 *    26:24 EN_OUT_CM6                0x0
 *    22:20 EN_OUT_CM5                0x0
 *    18:16 EN_OUT_CM4                0x0
 *    14:12 EN_OUT_CM3                0x0
 *    10:08 EN_OUT_CM2                0x0
 *    06:04 EN_OUT_CM1                0x0
 *    02:00 EN_OUT_CM0                0x0
 * </pre>
 */
#define RICU_AFE_CTL_15_ADDR        (REG_RICU_BASE_ADDR+0x0000004C)
#define RICU_AFE_CTL_15_OFFSET      0x0000004C
#define RICU_AFE_CTL_15_INDEX       0x00000013
#define RICU_AFE_CTL_15_RESET       0x00000000

__INLINE uint32_t  ricu_afe_ctl_15_get(void)
{
	return REG_PL_RD(RICU_AFE_CTL_15_ADDR);
}

__INLINE void ricu_afe_ctl_15_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTL_15_ADDR, value);
}

// field definitions
#define RICU_AFE_CTL_15_EN_OUT_CM_7_MASK    ((uint32_t)0x70000000)
#define RICU_AFE_CTL_15_EN_OUT_CM_7_LSB     28
#define RICU_AFE_CTL_15_EN_OUT_CM_7_WIDTH    ((uint32_t)0x00000003)
#define RICU_AFE_CTL_15_EN_OUT_CM_6_MASK    ((uint32_t)0x07000000)
#define RICU_AFE_CTL_15_EN_OUT_CM_6_LSB     24
#define RICU_AFE_CTL_15_EN_OUT_CM_6_WIDTH    ((uint32_t)0x00000003)
#define RICU_AFE_CTL_15_EN_OUT_CM_5_MASK    ((uint32_t)0x00700000)
#define RICU_AFE_CTL_15_EN_OUT_CM_5_LSB     20
#define RICU_AFE_CTL_15_EN_OUT_CM_5_WIDTH    ((uint32_t)0x00000003)
#define RICU_AFE_CTL_15_EN_OUT_CM_4_MASK    ((uint32_t)0x00070000)
#define RICU_AFE_CTL_15_EN_OUT_CM_4_LSB     16
#define RICU_AFE_CTL_15_EN_OUT_CM_4_WIDTH    ((uint32_t)0x00000003)
#define RICU_AFE_CTL_15_EN_OUT_CM_3_MASK    ((uint32_t)0x00007000)
#define RICU_AFE_CTL_15_EN_OUT_CM_3_LSB     12
#define RICU_AFE_CTL_15_EN_OUT_CM_3_WIDTH    ((uint32_t)0x00000003)
#define RICU_AFE_CTL_15_EN_OUT_CM_2_MASK    ((uint32_t)0x00000700)
#define RICU_AFE_CTL_15_EN_OUT_CM_2_LSB     8
#define RICU_AFE_CTL_15_EN_OUT_CM_2_WIDTH    ((uint32_t)0x00000003)
#define RICU_AFE_CTL_15_EN_OUT_CM_1_MASK    ((uint32_t)0x00000070)
#define RICU_AFE_CTL_15_EN_OUT_CM_1_LSB     4
#define RICU_AFE_CTL_15_EN_OUT_CM_1_WIDTH    ((uint32_t)0x00000003)
#define RICU_AFE_CTL_15_EN_OUT_CM_0_MASK    ((uint32_t)0x00000007)
#define RICU_AFE_CTL_15_EN_OUT_CM_0_LSB     0
#define RICU_AFE_CTL_15_EN_OUT_CM_0_WIDTH    ((uint32_t)0x00000003)

#define RICU_AFE_CTL_15_EN_OUT_CM_7_RST     0x0
#define RICU_AFE_CTL_15_EN_OUT_CM_6_RST     0x0
#define RICU_AFE_CTL_15_EN_OUT_CM_5_RST     0x0
#define RICU_AFE_CTL_15_EN_OUT_CM_4_RST     0x0
#define RICU_AFE_CTL_15_EN_OUT_CM_3_RST     0x0
#define RICU_AFE_CTL_15_EN_OUT_CM_2_RST     0x0
#define RICU_AFE_CTL_15_EN_OUT_CM_1_RST     0x0
#define RICU_AFE_CTL_15_EN_OUT_CM_0_RST     0x0

__INLINE void ricu_afe_ctl_15_pack(uint8_t en_out_cm7, uint8_t en_out_cm6, uint8_t en_out_cm5, uint8_t en_out_cm4, uint8_t en_out_cm3, uint8_t en_out_cm2, uint8_t en_out_cm1, uint8_t en_out_cm0)
{
	ASSERT_ERR((((uint32_t)en_out_cm7 << 28) & ~((uint32_t)0x70000000)) == 0);
	ASSERT_ERR((((uint32_t)en_out_cm6 << 24) & ~((uint32_t)0x07000000)) == 0);
	ASSERT_ERR((((uint32_t)en_out_cm5 << 20) & ~((uint32_t)0x00700000)) == 0);
	ASSERT_ERR((((uint32_t)en_out_cm4 << 16) & ~((uint32_t)0x00070000)) == 0);
	ASSERT_ERR((((uint32_t)en_out_cm3 << 12) & ~((uint32_t)0x00007000)) == 0);
	ASSERT_ERR((((uint32_t)en_out_cm2 << 8) & ~((uint32_t)0x00000700)) == 0);
	ASSERT_ERR((((uint32_t)en_out_cm1 << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)en_out_cm0 << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(RICU_AFE_CTL_15_ADDR,  ((uint32_t)en_out_cm7 << 28) |((uint32_t)en_out_cm6 << 24) |((uint32_t)en_out_cm5 << 20) |((uint32_t)en_out_cm4 << 16) |((uint32_t)en_out_cm3 << 12) |((uint32_t)en_out_cm2 << 8) |((uint32_t)en_out_cm1 << 4) |((uint32_t)en_out_cm0 << 0));
}

__INLINE void ricu_afe_ctl_15_unpack(uint8_t* en_out_cm7, uint8_t* en_out_cm6, uint8_t* en_out_cm5, uint8_t* en_out_cm4, uint8_t* en_out_cm3, uint8_t* en_out_cm2, uint8_t* en_out_cm1, uint8_t* en_out_cm0)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_15_ADDR);

	*en_out_cm7 = (localVal & ((uint32_t)0x70000000)) >>  28;
	*en_out_cm6 = (localVal & ((uint32_t)0x07000000)) >>  24;
	*en_out_cm5 = (localVal & ((uint32_t)0x00700000)) >>  20;
	*en_out_cm4 = (localVal & ((uint32_t)0x00070000)) >>  16;
	*en_out_cm3 = (localVal & ((uint32_t)0x00007000)) >>  12;
	*en_out_cm2 = (localVal & ((uint32_t)0x00000700)) >>  8;
	*en_out_cm1 = (localVal & ((uint32_t)0x00000070)) >>  4;
	*en_out_cm0 = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t ricu_afe_ctl_15_en_out_cm_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_15_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x70000000)) >> 28);
}
__INLINE void ricu_afe_ctl_15_en_out_cm_7_setf(uint8_t enoutcm7)
{
	ASSERT_ERR((((uint32_t)enoutcm7 << 28) & ~((uint32_t)0x70000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_15_ADDR, (REG_PL_RD(RICU_AFE_CTL_15_ADDR) & ~((uint32_t)0x70000000)) | ((uint32_t)enoutcm7 <<28));
}
__INLINE uint8_t ricu_afe_ctl_15_en_out_cm_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_15_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE void ricu_afe_ctl_15_en_out_cm_6_setf(uint8_t enoutcm6)
{
	ASSERT_ERR((((uint32_t)enoutcm6 << 24) & ~((uint32_t)0x07000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_15_ADDR, (REG_PL_RD(RICU_AFE_CTL_15_ADDR) & ~((uint32_t)0x07000000)) | ((uint32_t)enoutcm6 <<24));
}
__INLINE uint8_t ricu_afe_ctl_15_en_out_cm_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_15_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00700000)) >> 20);
}
__INLINE void ricu_afe_ctl_15_en_out_cm_5_setf(uint8_t enoutcm5)
{
	ASSERT_ERR((((uint32_t)enoutcm5 << 20) & ~((uint32_t)0x00700000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_15_ADDR, (REG_PL_RD(RICU_AFE_CTL_15_ADDR) & ~((uint32_t)0x00700000)) | ((uint32_t)enoutcm5 <<20));
}
__INLINE uint8_t ricu_afe_ctl_15_en_out_cm_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_15_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00070000)) >> 16);
}
__INLINE void ricu_afe_ctl_15_en_out_cm_4_setf(uint8_t enoutcm4)
{
	ASSERT_ERR((((uint32_t)enoutcm4 << 16) & ~((uint32_t)0x00070000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_15_ADDR, (REG_PL_RD(RICU_AFE_CTL_15_ADDR) & ~((uint32_t)0x00070000)) | ((uint32_t)enoutcm4 <<16));
}
__INLINE uint8_t ricu_afe_ctl_15_en_out_cm_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_15_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007000)) >> 12);
}
__INLINE void ricu_afe_ctl_15_en_out_cm_3_setf(uint8_t enoutcm3)
{
	ASSERT_ERR((((uint32_t)enoutcm3 << 12) & ~((uint32_t)0x00007000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_15_ADDR, (REG_PL_RD(RICU_AFE_CTL_15_ADDR) & ~((uint32_t)0x00007000)) | ((uint32_t)enoutcm3 <<12));
}
__INLINE uint8_t ricu_afe_ctl_15_en_out_cm_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_15_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000700)) >> 8);
}
__INLINE void ricu_afe_ctl_15_en_out_cm_2_setf(uint8_t enoutcm2)
{
	ASSERT_ERR((((uint32_t)enoutcm2 << 8) & ~((uint32_t)0x00000700)) == 0);
	REG_PL_WR(RICU_AFE_CTL_15_ADDR, (REG_PL_RD(RICU_AFE_CTL_15_ADDR) & ~((uint32_t)0x00000700)) | ((uint32_t)enoutcm2 <<8));
}
__INLINE uint8_t ricu_afe_ctl_15_en_out_cm_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_15_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void ricu_afe_ctl_15_en_out_cm_1_setf(uint8_t enoutcm1)
{
	ASSERT_ERR((((uint32_t)enoutcm1 << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(RICU_AFE_CTL_15_ADDR, (REG_PL_RD(RICU_AFE_CTL_15_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)enoutcm1 <<4));
}
__INLINE uint8_t ricu_afe_ctl_15_en_out_cm_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_15_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void ricu_afe_ctl_15_en_out_cm_0_setf(uint8_t enoutcm0)
{
	ASSERT_ERR((((uint32_t)enoutcm0 << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(RICU_AFE_CTL_15_ADDR, (REG_PL_RD(RICU_AFE_CTL_15_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)enoutcm0 <<0));
}

/**
 * @brief AFE_CTL_16 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    30:28 FS_IBUF7                  0x5
 *    26:24 FS_IBUF6                  0x5
 *    22:20 FS_IBUF5                  0x5
 *    18:16 FS_IBUF4                  0x5
 *    14:12 FS_IBUF3                  0x5
 *    10:08 FS_IBUF2                  0x5
 *    06:04 FS_IBUF1                  0x5
 *    02:00 FS_IBUF0                  0x5
 * </pre>
 */
#define RICU_AFE_CTL_16_ADDR        (REG_RICU_BASE_ADDR+0x00000050)
#define RICU_AFE_CTL_16_OFFSET      0x00000050
#define RICU_AFE_CTL_16_INDEX       0x00000014
#define RICU_AFE_CTL_16_RESET       0x55555555

__INLINE uint32_t  ricu_afe_ctl_16_get(void)
{
	return REG_PL_RD(RICU_AFE_CTL_16_ADDR);
}

__INLINE void ricu_afe_ctl_16_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTL_16_ADDR, value);
}

// field definitions
#define RICU_AFE_CTL_16_FS_IBUF_7_MASK      ((uint32_t)0x70000000)
#define RICU_AFE_CTL_16_FS_IBUF_7_LSB       28
#define RICU_AFE_CTL_16_FS_IBUF_7_WIDTH     ((uint32_t)0x00000003)
#define RICU_AFE_CTL_16_FS_IBUF_6_MASK      ((uint32_t)0x07000000)
#define RICU_AFE_CTL_16_FS_IBUF_6_LSB       24
#define RICU_AFE_CTL_16_FS_IBUF_6_WIDTH     ((uint32_t)0x00000003)
#define RICU_AFE_CTL_16_FS_IBUF_5_MASK      ((uint32_t)0x00700000)
#define RICU_AFE_CTL_16_FS_IBUF_5_LSB       20
#define RICU_AFE_CTL_16_FS_IBUF_5_WIDTH     ((uint32_t)0x00000003)
#define RICU_AFE_CTL_16_FS_IBUF_4_MASK      ((uint32_t)0x00070000)
#define RICU_AFE_CTL_16_FS_IBUF_4_LSB       16
#define RICU_AFE_CTL_16_FS_IBUF_4_WIDTH     ((uint32_t)0x00000003)
#define RICU_AFE_CTL_16_FS_IBUF_3_MASK      ((uint32_t)0x00007000)
#define RICU_AFE_CTL_16_FS_IBUF_3_LSB       12
#define RICU_AFE_CTL_16_FS_IBUF_3_WIDTH     ((uint32_t)0x00000003)
#define RICU_AFE_CTL_16_FS_IBUF_2_MASK      ((uint32_t)0x00000700)
#define RICU_AFE_CTL_16_FS_IBUF_2_LSB       8
#define RICU_AFE_CTL_16_FS_IBUF_2_WIDTH     ((uint32_t)0x00000003)
#define RICU_AFE_CTL_16_FS_IBUF_1_MASK      ((uint32_t)0x00000070)
#define RICU_AFE_CTL_16_FS_IBUF_1_LSB       4
#define RICU_AFE_CTL_16_FS_IBUF_1_WIDTH     ((uint32_t)0x00000003)
#define RICU_AFE_CTL_16_FS_IBUF_0_MASK      ((uint32_t)0x00000007)
#define RICU_AFE_CTL_16_FS_IBUF_0_LSB       0
#define RICU_AFE_CTL_16_FS_IBUF_0_WIDTH     ((uint32_t)0x00000003)

#define RICU_AFE_CTL_16_FS_IBUF_7_RST       0x5
#define RICU_AFE_CTL_16_FS_IBUF_6_RST       0x5
#define RICU_AFE_CTL_16_FS_IBUF_5_RST       0x5
#define RICU_AFE_CTL_16_FS_IBUF_4_RST       0x5
#define RICU_AFE_CTL_16_FS_IBUF_3_RST       0x5
#define RICU_AFE_CTL_16_FS_IBUF_2_RST       0x5
#define RICU_AFE_CTL_16_FS_IBUF_1_RST       0x5
#define RICU_AFE_CTL_16_FS_IBUF_0_RST       0x5

__INLINE void ricu_afe_ctl_16_pack(uint8_t fs_ibuf7, uint8_t fs_ibuf6, uint8_t fs_ibuf5, uint8_t fs_ibuf4, uint8_t fs_ibuf3, uint8_t fs_ibuf2, uint8_t fs_ibuf1, uint8_t fs_ibuf0)
{
	ASSERT_ERR((((uint32_t)fs_ibuf7 << 28) & ~((uint32_t)0x70000000)) == 0);
	ASSERT_ERR((((uint32_t)fs_ibuf6 << 24) & ~((uint32_t)0x07000000)) == 0);
	ASSERT_ERR((((uint32_t)fs_ibuf5 << 20) & ~((uint32_t)0x00700000)) == 0);
	ASSERT_ERR((((uint32_t)fs_ibuf4 << 16) & ~((uint32_t)0x00070000)) == 0);
	ASSERT_ERR((((uint32_t)fs_ibuf3 << 12) & ~((uint32_t)0x00007000)) == 0);
	ASSERT_ERR((((uint32_t)fs_ibuf2 << 8) & ~((uint32_t)0x00000700)) == 0);
	ASSERT_ERR((((uint32_t)fs_ibuf1 << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)fs_ibuf0 << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(RICU_AFE_CTL_16_ADDR,  ((uint32_t)fs_ibuf7 << 28) |((uint32_t)fs_ibuf6 << 24) |((uint32_t)fs_ibuf5 << 20) |((uint32_t)fs_ibuf4 << 16) |((uint32_t)fs_ibuf3 << 12) |((uint32_t)fs_ibuf2 << 8) |((uint32_t)fs_ibuf1 << 4) |((uint32_t)fs_ibuf0 << 0));
}

__INLINE void ricu_afe_ctl_16_unpack(uint8_t* fs_ibuf7, uint8_t* fs_ibuf6, uint8_t* fs_ibuf5, uint8_t* fs_ibuf4, uint8_t* fs_ibuf3, uint8_t* fs_ibuf2, uint8_t* fs_ibuf1, uint8_t* fs_ibuf0)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_16_ADDR);

	*fs_ibuf7 = (localVal & ((uint32_t)0x70000000)) >>  28;
	*fs_ibuf6 = (localVal & ((uint32_t)0x07000000)) >>  24;
	*fs_ibuf5 = (localVal & ((uint32_t)0x00700000)) >>  20;
	*fs_ibuf4 = (localVal & ((uint32_t)0x00070000)) >>  16;
	*fs_ibuf3 = (localVal & ((uint32_t)0x00007000)) >>  12;
	*fs_ibuf2 = (localVal & ((uint32_t)0x00000700)) >>  8;
	*fs_ibuf1 = (localVal & ((uint32_t)0x00000070)) >>  4;
	*fs_ibuf0 = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t ricu_afe_ctl_16_fs_ibuf_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_16_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x70000000)) >> 28);
}
__INLINE void ricu_afe_ctl_16_fs_ibuf_7_setf(uint8_t fsibuf7)
{
	ASSERT_ERR((((uint32_t)fsibuf7 << 28) & ~((uint32_t)0x70000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_16_ADDR, (REG_PL_RD(RICU_AFE_CTL_16_ADDR) & ~((uint32_t)0x70000000)) | ((uint32_t)fsibuf7 <<28));
}
__INLINE uint8_t ricu_afe_ctl_16_fs_ibuf_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_16_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE void ricu_afe_ctl_16_fs_ibuf_6_setf(uint8_t fsibuf6)
{
	ASSERT_ERR((((uint32_t)fsibuf6 << 24) & ~((uint32_t)0x07000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_16_ADDR, (REG_PL_RD(RICU_AFE_CTL_16_ADDR) & ~((uint32_t)0x07000000)) | ((uint32_t)fsibuf6 <<24));
}
__INLINE uint8_t ricu_afe_ctl_16_fs_ibuf_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_16_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00700000)) >> 20);
}
__INLINE void ricu_afe_ctl_16_fs_ibuf_5_setf(uint8_t fsibuf5)
{
	ASSERT_ERR((((uint32_t)fsibuf5 << 20) & ~((uint32_t)0x00700000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_16_ADDR, (REG_PL_RD(RICU_AFE_CTL_16_ADDR) & ~((uint32_t)0x00700000)) | ((uint32_t)fsibuf5 <<20));
}
__INLINE uint8_t ricu_afe_ctl_16_fs_ibuf_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_16_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00070000)) >> 16);
}
__INLINE void ricu_afe_ctl_16_fs_ibuf_4_setf(uint8_t fsibuf4)
{
	ASSERT_ERR((((uint32_t)fsibuf4 << 16) & ~((uint32_t)0x00070000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_16_ADDR, (REG_PL_RD(RICU_AFE_CTL_16_ADDR) & ~((uint32_t)0x00070000)) | ((uint32_t)fsibuf4 <<16));
}
__INLINE uint8_t ricu_afe_ctl_16_fs_ibuf_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_16_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007000)) >> 12);
}
__INLINE void ricu_afe_ctl_16_fs_ibuf_3_setf(uint8_t fsibuf3)
{
	ASSERT_ERR((((uint32_t)fsibuf3 << 12) & ~((uint32_t)0x00007000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_16_ADDR, (REG_PL_RD(RICU_AFE_CTL_16_ADDR) & ~((uint32_t)0x00007000)) | ((uint32_t)fsibuf3 <<12));
}
__INLINE uint8_t ricu_afe_ctl_16_fs_ibuf_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_16_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000700)) >> 8);
}
__INLINE void ricu_afe_ctl_16_fs_ibuf_2_setf(uint8_t fsibuf2)
{
	ASSERT_ERR((((uint32_t)fsibuf2 << 8) & ~((uint32_t)0x00000700)) == 0);
	REG_PL_WR(RICU_AFE_CTL_16_ADDR, (REG_PL_RD(RICU_AFE_CTL_16_ADDR) & ~((uint32_t)0x00000700)) | ((uint32_t)fsibuf2 <<8));
}
__INLINE uint8_t ricu_afe_ctl_16_fs_ibuf_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_16_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void ricu_afe_ctl_16_fs_ibuf_1_setf(uint8_t fsibuf1)
{
	ASSERT_ERR((((uint32_t)fsibuf1 << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(RICU_AFE_CTL_16_ADDR, (REG_PL_RD(RICU_AFE_CTL_16_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)fsibuf1 <<4));
}
__INLINE uint8_t ricu_afe_ctl_16_fs_ibuf_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_16_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void ricu_afe_ctl_16_fs_ibuf_0_setf(uint8_t fsibuf0)
{
	ASSERT_ERR((((uint32_t)fsibuf0 << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(RICU_AFE_CTL_16_ADDR, (REG_PL_RD(RICU_AFE_CTL_16_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)fsibuf0 <<0));
}

/**
 * @brief AFE_CTL_17 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    30:28 VC_REF7                   0x1
 *    26:24 VC_REF6                   0x1
 *    22:20 VC_REF5                   0x1
 *    18:16 VC_REF4                   0x1
 *    14:12 VC_REF3                   0x1
 *    10:08 VC_REF2                   0x1
 *    06:04 VC_REF1                   0x1
 *    02:00 VC_REF0                   0x1
 * </pre>
 */
#define RICU_AFE_CTL_17_ADDR        (REG_RICU_BASE_ADDR+0x00000054)
#define RICU_AFE_CTL_17_OFFSET      0x00000054
#define RICU_AFE_CTL_17_INDEX       0x00000015
#define RICU_AFE_CTL_17_RESET       0x11111111

__INLINE uint32_t  ricu_afe_ctl_17_get(void)
{
	return REG_PL_RD(RICU_AFE_CTL_17_ADDR);
}

__INLINE void ricu_afe_ctl_17_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTL_17_ADDR, value);
}

// field definitions
#define RICU_AFE_CTL_17_VC_REF_7_MASK       ((uint32_t)0x70000000)
#define RICU_AFE_CTL_17_VC_REF_7_LSB        28
#define RICU_AFE_CTL_17_VC_REF_7_WIDTH      ((uint32_t)0x00000003)
#define RICU_AFE_CTL_17_VC_REF_6_MASK       ((uint32_t)0x07000000)
#define RICU_AFE_CTL_17_VC_REF_6_LSB        24
#define RICU_AFE_CTL_17_VC_REF_6_WIDTH      ((uint32_t)0x00000003)
#define RICU_AFE_CTL_17_VC_REF_5_MASK       ((uint32_t)0x00700000)
#define RICU_AFE_CTL_17_VC_REF_5_LSB        20
#define RICU_AFE_CTL_17_VC_REF_5_WIDTH      ((uint32_t)0x00000003)
#define RICU_AFE_CTL_17_VC_REF_4_MASK       ((uint32_t)0x00070000)
#define RICU_AFE_CTL_17_VC_REF_4_LSB        16
#define RICU_AFE_CTL_17_VC_REF_4_WIDTH      ((uint32_t)0x00000003)
#define RICU_AFE_CTL_17_VC_REF_3_MASK       ((uint32_t)0x00007000)
#define RICU_AFE_CTL_17_VC_REF_3_LSB        12
#define RICU_AFE_CTL_17_VC_REF_3_WIDTH      ((uint32_t)0x00000003)
#define RICU_AFE_CTL_17_VC_REF_2_MASK       ((uint32_t)0x00000700)
#define RICU_AFE_CTL_17_VC_REF_2_LSB        8
#define RICU_AFE_CTL_17_VC_REF_2_WIDTH      ((uint32_t)0x00000003)
#define RICU_AFE_CTL_17_VC_REF_1_MASK       ((uint32_t)0x00000070)
#define RICU_AFE_CTL_17_VC_REF_1_LSB        4
#define RICU_AFE_CTL_17_VC_REF_1_WIDTH      ((uint32_t)0x00000003)
#define RICU_AFE_CTL_17_VC_REF_0_MASK       ((uint32_t)0x00000007)
#define RICU_AFE_CTL_17_VC_REF_0_LSB        0
#define RICU_AFE_CTL_17_VC_REF_0_WIDTH      ((uint32_t)0x00000003)

#define RICU_AFE_CTL_17_VC_REF_7_RST        0x1
#define RICU_AFE_CTL_17_VC_REF_6_RST        0x1
#define RICU_AFE_CTL_17_VC_REF_5_RST        0x1
#define RICU_AFE_CTL_17_VC_REF_4_RST        0x1
#define RICU_AFE_CTL_17_VC_REF_3_RST        0x1
#define RICU_AFE_CTL_17_VC_REF_2_RST        0x1
#define RICU_AFE_CTL_17_VC_REF_1_RST        0x1
#define RICU_AFE_CTL_17_VC_REF_0_RST        0x1

__INLINE void ricu_afe_ctl_17_pack(uint8_t vc_ref7, uint8_t vc_ref6, uint8_t vc_ref5, uint8_t vc_ref4, uint8_t vc_ref3, uint8_t vc_ref2, uint8_t vc_ref1, uint8_t vc_ref0)
{
	ASSERT_ERR((((uint32_t)vc_ref7 << 28) & ~((uint32_t)0x70000000)) == 0);
	ASSERT_ERR((((uint32_t)vc_ref6 << 24) & ~((uint32_t)0x07000000)) == 0);
	ASSERT_ERR((((uint32_t)vc_ref5 << 20) & ~((uint32_t)0x00700000)) == 0);
	ASSERT_ERR((((uint32_t)vc_ref4 << 16) & ~((uint32_t)0x00070000)) == 0);
	ASSERT_ERR((((uint32_t)vc_ref3 << 12) & ~((uint32_t)0x00007000)) == 0);
	ASSERT_ERR((((uint32_t)vc_ref2 << 8) & ~((uint32_t)0x00000700)) == 0);
	ASSERT_ERR((((uint32_t)vc_ref1 << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)vc_ref0 << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(RICU_AFE_CTL_17_ADDR,  ((uint32_t)vc_ref7 << 28) |((uint32_t)vc_ref6 << 24) |((uint32_t)vc_ref5 << 20) |((uint32_t)vc_ref4 << 16) |((uint32_t)vc_ref3 << 12) |((uint32_t)vc_ref2 << 8) |((uint32_t)vc_ref1 << 4) |((uint32_t)vc_ref0 << 0));
}

__INLINE void ricu_afe_ctl_17_unpack(uint8_t* vc_ref7, uint8_t* vc_ref6, uint8_t* vc_ref5, uint8_t* vc_ref4, uint8_t* vc_ref3, uint8_t* vc_ref2, uint8_t* vc_ref1, uint8_t* vc_ref0)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_17_ADDR);

	*vc_ref7 = (localVal & ((uint32_t)0x70000000)) >>  28;
	*vc_ref6 = (localVal & ((uint32_t)0x07000000)) >>  24;
	*vc_ref5 = (localVal & ((uint32_t)0x00700000)) >>  20;
	*vc_ref4 = (localVal & ((uint32_t)0x00070000)) >>  16;
	*vc_ref3 = (localVal & ((uint32_t)0x00007000)) >>  12;
	*vc_ref2 = (localVal & ((uint32_t)0x00000700)) >>  8;
	*vc_ref1 = (localVal & ((uint32_t)0x00000070)) >>  4;
	*vc_ref0 = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t ricu_afe_ctl_17_vc_ref_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_17_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x70000000)) >> 28);
}
__INLINE void ricu_afe_ctl_17_vc_ref_7_setf(uint8_t vcref7)
{
	ASSERT_ERR((((uint32_t)vcref7 << 28) & ~((uint32_t)0x70000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_17_ADDR, (REG_PL_RD(RICU_AFE_CTL_17_ADDR) & ~((uint32_t)0x70000000)) | ((uint32_t)vcref7 <<28));
}
__INLINE uint8_t ricu_afe_ctl_17_vc_ref_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_17_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE void ricu_afe_ctl_17_vc_ref_6_setf(uint8_t vcref6)
{
	ASSERT_ERR((((uint32_t)vcref6 << 24) & ~((uint32_t)0x07000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_17_ADDR, (REG_PL_RD(RICU_AFE_CTL_17_ADDR) & ~((uint32_t)0x07000000)) | ((uint32_t)vcref6 <<24));
}
__INLINE uint8_t ricu_afe_ctl_17_vc_ref_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_17_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00700000)) >> 20);
}
__INLINE void ricu_afe_ctl_17_vc_ref_5_setf(uint8_t vcref5)
{
	ASSERT_ERR((((uint32_t)vcref5 << 20) & ~((uint32_t)0x00700000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_17_ADDR, (REG_PL_RD(RICU_AFE_CTL_17_ADDR) & ~((uint32_t)0x00700000)) | ((uint32_t)vcref5 <<20));
}
__INLINE uint8_t ricu_afe_ctl_17_vc_ref_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_17_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00070000)) >> 16);
}
__INLINE void ricu_afe_ctl_17_vc_ref_4_setf(uint8_t vcref4)
{
	ASSERT_ERR((((uint32_t)vcref4 << 16) & ~((uint32_t)0x00070000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_17_ADDR, (REG_PL_RD(RICU_AFE_CTL_17_ADDR) & ~((uint32_t)0x00070000)) | ((uint32_t)vcref4 <<16));
}
__INLINE uint8_t ricu_afe_ctl_17_vc_ref_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_17_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007000)) >> 12);
}
__INLINE void ricu_afe_ctl_17_vc_ref_3_setf(uint8_t vcref3)
{
	ASSERT_ERR((((uint32_t)vcref3 << 12) & ~((uint32_t)0x00007000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_17_ADDR, (REG_PL_RD(RICU_AFE_CTL_17_ADDR) & ~((uint32_t)0x00007000)) | ((uint32_t)vcref3 <<12));
}
__INLINE uint8_t ricu_afe_ctl_17_vc_ref_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_17_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000700)) >> 8);
}
__INLINE void ricu_afe_ctl_17_vc_ref_2_setf(uint8_t vcref2)
{
	ASSERT_ERR((((uint32_t)vcref2 << 8) & ~((uint32_t)0x00000700)) == 0);
	REG_PL_WR(RICU_AFE_CTL_17_ADDR, (REG_PL_RD(RICU_AFE_CTL_17_ADDR) & ~((uint32_t)0x00000700)) | ((uint32_t)vcref2 <<8));
}
__INLINE uint8_t ricu_afe_ctl_17_vc_ref_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_17_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void ricu_afe_ctl_17_vc_ref_1_setf(uint8_t vcref1)
{
	ASSERT_ERR((((uint32_t)vcref1 << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(RICU_AFE_CTL_17_ADDR, (REG_PL_RD(RICU_AFE_CTL_17_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)vcref1 <<4));
}
__INLINE uint8_t ricu_afe_ctl_17_vc_ref_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_17_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void ricu_afe_ctl_17_vc_ref_0_setf(uint8_t vcref0)
{
	ASSERT_ERR((((uint32_t)vcref0 << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(RICU_AFE_CTL_17_ADDR, (REG_PL_RD(RICU_AFE_CTL_17_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)vcref0 <<0));
}

/**
 * @brief AFE_CTL_18 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:28 COMP_CTRL_EXT7            0xf
 *    27:24 COMP_CTRL_EXT6            0xf
 *    23:20 COMP_CTRL_EXT5            0xf
 *    19:16 COMP_CTRL_EXT4            0xf
 *    15:12 COMP_CTRL_EXT3            0xf
 *    11:08 COMP_CTRL_EXT2            0xf
 *    07:04 COMP_CTRL_EXT1            0xf
 *    03:00 COMP_CTRL_EXT0            0xf
 * </pre>
 */
#define RICU_AFE_CTL_18_ADDR        (REG_RICU_BASE_ADDR+0x00000058)
#define RICU_AFE_CTL_18_OFFSET      0x00000058
#define RICU_AFE_CTL_18_INDEX       0x00000016
#define RICU_AFE_CTL_18_RESET       0xFFFFFFFF

__INLINE uint32_t  ricu_afe_ctl_18_get(void)
{
	return REG_PL_RD(RICU_AFE_CTL_18_ADDR);
}

__INLINE void ricu_afe_ctl_18_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTL_18_ADDR, value);
}

// field definitions
#define RICU_AFE_CTL_18_COMP_CTRL_EXT_7_MASK    ((uint32_t)0xF0000000)
#define RICU_AFE_CTL_18_COMP_CTRL_EXT_7_LSB    28
#define RICU_AFE_CTL_18_COMP_CTRL_EXT_7_WIDTH    ((uint32_t)0x00000004)
#define RICU_AFE_CTL_18_COMP_CTRL_EXT_6_MASK    ((uint32_t)0x0F000000)
#define RICU_AFE_CTL_18_COMP_CTRL_EXT_6_LSB    24
#define RICU_AFE_CTL_18_COMP_CTRL_EXT_6_WIDTH    ((uint32_t)0x00000004)
#define RICU_AFE_CTL_18_COMP_CTRL_EXT_5_MASK    ((uint32_t)0x00F00000)
#define RICU_AFE_CTL_18_COMP_CTRL_EXT_5_LSB    20
#define RICU_AFE_CTL_18_COMP_CTRL_EXT_5_WIDTH    ((uint32_t)0x00000004)
#define RICU_AFE_CTL_18_COMP_CTRL_EXT_4_MASK    ((uint32_t)0x000F0000)
#define RICU_AFE_CTL_18_COMP_CTRL_EXT_4_LSB    16
#define RICU_AFE_CTL_18_COMP_CTRL_EXT_4_WIDTH    ((uint32_t)0x00000004)
#define RICU_AFE_CTL_18_COMP_CTRL_EXT_3_MASK    ((uint32_t)0x0000F000)
#define RICU_AFE_CTL_18_COMP_CTRL_EXT_3_LSB    12
#define RICU_AFE_CTL_18_COMP_CTRL_EXT_3_WIDTH    ((uint32_t)0x00000004)
#define RICU_AFE_CTL_18_COMP_CTRL_EXT_2_MASK    ((uint32_t)0x00000F00)
#define RICU_AFE_CTL_18_COMP_CTRL_EXT_2_LSB    8
#define RICU_AFE_CTL_18_COMP_CTRL_EXT_2_WIDTH    ((uint32_t)0x00000004)
#define RICU_AFE_CTL_18_COMP_CTRL_EXT_1_MASK    ((uint32_t)0x000000F0)
#define RICU_AFE_CTL_18_COMP_CTRL_EXT_1_LSB    4
#define RICU_AFE_CTL_18_COMP_CTRL_EXT_1_WIDTH    ((uint32_t)0x00000004)
#define RICU_AFE_CTL_18_COMP_CTRL_EXT_0_MASK    ((uint32_t)0x0000000F)
#define RICU_AFE_CTL_18_COMP_CTRL_EXT_0_LSB    0
#define RICU_AFE_CTL_18_COMP_CTRL_EXT_0_WIDTH    ((uint32_t)0x00000004)

#define RICU_AFE_CTL_18_COMP_CTRL_EXT_7_RST    0xf
#define RICU_AFE_CTL_18_COMP_CTRL_EXT_6_RST    0xf
#define RICU_AFE_CTL_18_COMP_CTRL_EXT_5_RST    0xf
#define RICU_AFE_CTL_18_COMP_CTRL_EXT_4_RST    0xf
#define RICU_AFE_CTL_18_COMP_CTRL_EXT_3_RST    0xf
#define RICU_AFE_CTL_18_COMP_CTRL_EXT_2_RST    0xf
#define RICU_AFE_CTL_18_COMP_CTRL_EXT_1_RST    0xf
#define RICU_AFE_CTL_18_COMP_CTRL_EXT_0_RST    0xf

__INLINE void ricu_afe_ctl_18_pack(uint8_t comp_ctrl_ext7, uint8_t comp_ctrl_ext6, uint8_t comp_ctrl_ext5, uint8_t comp_ctrl_ext4, uint8_t comp_ctrl_ext3, uint8_t comp_ctrl_ext2, uint8_t comp_ctrl_ext1, uint8_t comp_ctrl_ext0)
{
	ASSERT_ERR((((uint32_t)comp_ctrl_ext7 << 28) & ~((uint32_t)0xF0000000)) == 0);
	ASSERT_ERR((((uint32_t)comp_ctrl_ext6 << 24) & ~((uint32_t)0x0F000000)) == 0);
	ASSERT_ERR((((uint32_t)comp_ctrl_ext5 << 20) & ~((uint32_t)0x00F00000)) == 0);
	ASSERT_ERR((((uint32_t)comp_ctrl_ext4 << 16) & ~((uint32_t)0x000F0000)) == 0);
	ASSERT_ERR((((uint32_t)comp_ctrl_ext3 << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)comp_ctrl_ext2 << 8) & ~((uint32_t)0x00000F00)) == 0);
	ASSERT_ERR((((uint32_t)comp_ctrl_ext1 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)comp_ctrl_ext0 << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RICU_AFE_CTL_18_ADDR,  ((uint32_t)comp_ctrl_ext7 << 28) |((uint32_t)comp_ctrl_ext6 << 24) |((uint32_t)comp_ctrl_ext5 << 20) |((uint32_t)comp_ctrl_ext4 << 16) |((uint32_t)comp_ctrl_ext3 << 12) |((uint32_t)comp_ctrl_ext2 << 8) |((uint32_t)comp_ctrl_ext1 << 4) |((uint32_t)comp_ctrl_ext0 << 0));
}

__INLINE void ricu_afe_ctl_18_unpack(uint8_t* comp_ctrl_ext7, uint8_t* comp_ctrl_ext6, uint8_t* comp_ctrl_ext5, uint8_t* comp_ctrl_ext4, uint8_t* comp_ctrl_ext3, uint8_t* comp_ctrl_ext2, uint8_t* comp_ctrl_ext1, uint8_t* comp_ctrl_ext0)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_18_ADDR);

	*comp_ctrl_ext7 = (localVal & ((uint32_t)0xF0000000)) >>  28;
	*comp_ctrl_ext6 = (localVal & ((uint32_t)0x0F000000)) >>  24;
	*comp_ctrl_ext5 = (localVal & ((uint32_t)0x00F00000)) >>  20;
	*comp_ctrl_ext4 = (localVal & ((uint32_t)0x000F0000)) >>  16;
	*comp_ctrl_ext3 = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*comp_ctrl_ext2 = (localVal & ((uint32_t)0x00000F00)) >>  8;
	*comp_ctrl_ext1 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*comp_ctrl_ext0 = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t ricu_afe_ctl_18_comp_ctrl_ext_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_18_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xF0000000)) >> 28);
}
__INLINE void ricu_afe_ctl_18_comp_ctrl_ext_7_setf(uint8_t compctrlext7)
{
	ASSERT_ERR((((uint32_t)compctrlext7 << 28) & ~((uint32_t)0xF0000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_18_ADDR, (REG_PL_RD(RICU_AFE_CTL_18_ADDR) & ~((uint32_t)0xF0000000)) | ((uint32_t)compctrlext7 <<28));
}
__INLINE uint8_t ricu_afe_ctl_18_comp_ctrl_ext_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_18_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0F000000)) >> 24);
}
__INLINE void ricu_afe_ctl_18_comp_ctrl_ext_6_setf(uint8_t compctrlext6)
{
	ASSERT_ERR((((uint32_t)compctrlext6 << 24) & ~((uint32_t)0x0F000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_18_ADDR, (REG_PL_RD(RICU_AFE_CTL_18_ADDR) & ~((uint32_t)0x0F000000)) | ((uint32_t)compctrlext6 <<24));
}
__INLINE uint8_t ricu_afe_ctl_18_comp_ctrl_ext_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_18_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00F00000)) >> 20);
}
__INLINE void ricu_afe_ctl_18_comp_ctrl_ext_5_setf(uint8_t compctrlext5)
{
	ASSERT_ERR((((uint32_t)compctrlext5 << 20) & ~((uint32_t)0x00F00000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_18_ADDR, (REG_PL_RD(RICU_AFE_CTL_18_ADDR) & ~((uint32_t)0x00F00000)) | ((uint32_t)compctrlext5 <<20));
}
__INLINE uint8_t ricu_afe_ctl_18_comp_ctrl_ext_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_18_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000F0000)) >> 16);
}
__INLINE void ricu_afe_ctl_18_comp_ctrl_ext_4_setf(uint8_t compctrlext4)
{
	ASSERT_ERR((((uint32_t)compctrlext4 << 16) & ~((uint32_t)0x000F0000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_18_ADDR, (REG_PL_RD(RICU_AFE_CTL_18_ADDR) & ~((uint32_t)0x000F0000)) | ((uint32_t)compctrlext4 <<16));
}
__INLINE uint8_t ricu_afe_ctl_18_comp_ctrl_ext_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_18_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void ricu_afe_ctl_18_comp_ctrl_ext_3_setf(uint8_t compctrlext3)
{
	ASSERT_ERR((((uint32_t)compctrlext3 << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_18_ADDR, (REG_PL_RD(RICU_AFE_CTL_18_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)compctrlext3 <<12));
}
__INLINE uint8_t ricu_afe_ctl_18_comp_ctrl_ext_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_18_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000F00)) >> 8);
}
__INLINE void ricu_afe_ctl_18_comp_ctrl_ext_2_setf(uint8_t compctrlext2)
{
	ASSERT_ERR((((uint32_t)compctrlext2 << 8) & ~((uint32_t)0x00000F00)) == 0);
	REG_PL_WR(RICU_AFE_CTL_18_ADDR, (REG_PL_RD(RICU_AFE_CTL_18_ADDR) & ~((uint32_t)0x00000F00)) | ((uint32_t)compctrlext2 <<8));
}
__INLINE uint8_t ricu_afe_ctl_18_comp_ctrl_ext_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_18_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE void ricu_afe_ctl_18_comp_ctrl_ext_1_setf(uint8_t compctrlext1)
{
	ASSERT_ERR((((uint32_t)compctrlext1 << 4) & ~((uint32_t)0x000000F0)) == 0);
	REG_PL_WR(RICU_AFE_CTL_18_ADDR, (REG_PL_RD(RICU_AFE_CTL_18_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)compctrlext1 <<4));
}
__INLINE uint8_t ricu_afe_ctl_18_comp_ctrl_ext_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_18_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void ricu_afe_ctl_18_comp_ctrl_ext_0_setf(uint8_t compctrlext0)
{
	ASSERT_ERR((((uint32_t)compctrlext0 << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RICU_AFE_CTL_18_ADDR, (REG_PL_RD(RICU_AFE_CTL_18_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)compctrlext0 <<0));
}

/**
 * @brief AFE_CTL_19 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:28 COMP_CTRL7                0x4
 *    27:24 COMP_CTRL6                0x4
 *    23:20 COMP_CTRL5                0x4
 *    19:16 COMP_CTRL4                0x4
 *    15:12 COMP_CTRL3                0x4
 *    11:08 COMP_CTRL2                0x4
 *    07:04 COMP_CTRL1                0x4
 *    03:00 COMP_CTRL0                0x4
 * </pre>
 */
#define RICU_AFE_CTL_19_ADDR        (REG_RICU_BASE_ADDR+0x0000005C)
#define RICU_AFE_CTL_19_OFFSET      0x0000005C
#define RICU_AFE_CTL_19_INDEX       0x00000017
#define RICU_AFE_CTL_19_RESET       0x44444444

__INLINE uint32_t  ricu_afe_ctl_19_get(void)
{
	return REG_PL_RD(RICU_AFE_CTL_19_ADDR);
}

__INLINE void ricu_afe_ctl_19_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTL_19_ADDR, value);
}

// field definitions
#define RICU_AFE_CTL_19_COMP_CTRL_7_MASK    ((uint32_t)0xF0000000)
#define RICU_AFE_CTL_19_COMP_CTRL_7_LSB     28
#define RICU_AFE_CTL_19_COMP_CTRL_7_WIDTH    ((uint32_t)0x00000004)
#define RICU_AFE_CTL_19_COMP_CTRL_6_MASK    ((uint32_t)0x0F000000)
#define RICU_AFE_CTL_19_COMP_CTRL_6_LSB     24
#define RICU_AFE_CTL_19_COMP_CTRL_6_WIDTH    ((uint32_t)0x00000004)
#define RICU_AFE_CTL_19_COMP_CTRL_5_MASK    ((uint32_t)0x00F00000)
#define RICU_AFE_CTL_19_COMP_CTRL_5_LSB     20
#define RICU_AFE_CTL_19_COMP_CTRL_5_WIDTH    ((uint32_t)0x00000004)
#define RICU_AFE_CTL_19_COMP_CTRL_4_MASK    ((uint32_t)0x000F0000)
#define RICU_AFE_CTL_19_COMP_CTRL_4_LSB     16
#define RICU_AFE_CTL_19_COMP_CTRL_4_WIDTH    ((uint32_t)0x00000004)
#define RICU_AFE_CTL_19_COMP_CTRL_3_MASK    ((uint32_t)0x0000F000)
#define RICU_AFE_CTL_19_COMP_CTRL_3_LSB     12
#define RICU_AFE_CTL_19_COMP_CTRL_3_WIDTH    ((uint32_t)0x00000004)
#define RICU_AFE_CTL_19_COMP_CTRL_2_MASK    ((uint32_t)0x00000F00)
#define RICU_AFE_CTL_19_COMP_CTRL_2_LSB     8
#define RICU_AFE_CTL_19_COMP_CTRL_2_WIDTH    ((uint32_t)0x00000004)
#define RICU_AFE_CTL_19_COMP_CTRL_1_MASK    ((uint32_t)0x000000F0)
#define RICU_AFE_CTL_19_COMP_CTRL_1_LSB     4
#define RICU_AFE_CTL_19_COMP_CTRL_1_WIDTH    ((uint32_t)0x00000004)
#define RICU_AFE_CTL_19_COMP_CTRL_0_MASK    ((uint32_t)0x0000000F)
#define RICU_AFE_CTL_19_COMP_CTRL_0_LSB     0
#define RICU_AFE_CTL_19_COMP_CTRL_0_WIDTH    ((uint32_t)0x00000004)

#define RICU_AFE_CTL_19_COMP_CTRL_7_RST     0x4
#define RICU_AFE_CTL_19_COMP_CTRL_6_RST     0x4
#define RICU_AFE_CTL_19_COMP_CTRL_5_RST     0x4
#define RICU_AFE_CTL_19_COMP_CTRL_4_RST     0x4
#define RICU_AFE_CTL_19_COMP_CTRL_3_RST     0x4
#define RICU_AFE_CTL_19_COMP_CTRL_2_RST     0x4
#define RICU_AFE_CTL_19_COMP_CTRL_1_RST     0x4
#define RICU_AFE_CTL_19_COMP_CTRL_0_RST     0x4

__INLINE void ricu_afe_ctl_19_pack(uint8_t comp_ctrl7, uint8_t comp_ctrl6, uint8_t comp_ctrl5, uint8_t comp_ctrl4, uint8_t comp_ctrl3, uint8_t comp_ctrl2, uint8_t comp_ctrl1, uint8_t comp_ctrl0)
{
	ASSERT_ERR((((uint32_t)comp_ctrl7 << 28) & ~((uint32_t)0xF0000000)) == 0);
	ASSERT_ERR((((uint32_t)comp_ctrl6 << 24) & ~((uint32_t)0x0F000000)) == 0);
	ASSERT_ERR((((uint32_t)comp_ctrl5 << 20) & ~((uint32_t)0x00F00000)) == 0);
	ASSERT_ERR((((uint32_t)comp_ctrl4 << 16) & ~((uint32_t)0x000F0000)) == 0);
	ASSERT_ERR((((uint32_t)comp_ctrl3 << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)comp_ctrl2 << 8) & ~((uint32_t)0x00000F00)) == 0);
	ASSERT_ERR((((uint32_t)comp_ctrl1 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)comp_ctrl0 << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RICU_AFE_CTL_19_ADDR,  ((uint32_t)comp_ctrl7 << 28) |((uint32_t)comp_ctrl6 << 24) |((uint32_t)comp_ctrl5 << 20) |((uint32_t)comp_ctrl4 << 16) |((uint32_t)comp_ctrl3 << 12) |((uint32_t)comp_ctrl2 << 8) |((uint32_t)comp_ctrl1 << 4) |((uint32_t)comp_ctrl0 << 0));
}

__INLINE void ricu_afe_ctl_19_unpack(uint8_t* comp_ctrl7, uint8_t* comp_ctrl6, uint8_t* comp_ctrl5, uint8_t* comp_ctrl4, uint8_t* comp_ctrl3, uint8_t* comp_ctrl2, uint8_t* comp_ctrl1, uint8_t* comp_ctrl0)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_19_ADDR);

	*comp_ctrl7 = (localVal & ((uint32_t)0xF0000000)) >>  28;
	*comp_ctrl6 = (localVal & ((uint32_t)0x0F000000)) >>  24;
	*comp_ctrl5 = (localVal & ((uint32_t)0x00F00000)) >>  20;
	*comp_ctrl4 = (localVal & ((uint32_t)0x000F0000)) >>  16;
	*comp_ctrl3 = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*comp_ctrl2 = (localVal & ((uint32_t)0x00000F00)) >>  8;
	*comp_ctrl1 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*comp_ctrl0 = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t ricu_afe_ctl_19_comp_ctrl_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_19_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xF0000000)) >> 28);
}
__INLINE void ricu_afe_ctl_19_comp_ctrl_7_setf(uint8_t compctrl7)
{
	ASSERT_ERR((((uint32_t)compctrl7 << 28) & ~((uint32_t)0xF0000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_19_ADDR, (REG_PL_RD(RICU_AFE_CTL_19_ADDR) & ~((uint32_t)0xF0000000)) | ((uint32_t)compctrl7 <<28));
}
__INLINE uint8_t ricu_afe_ctl_19_comp_ctrl_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_19_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0F000000)) >> 24);
}
__INLINE void ricu_afe_ctl_19_comp_ctrl_6_setf(uint8_t compctrl6)
{
	ASSERT_ERR((((uint32_t)compctrl6 << 24) & ~((uint32_t)0x0F000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_19_ADDR, (REG_PL_RD(RICU_AFE_CTL_19_ADDR) & ~((uint32_t)0x0F000000)) | ((uint32_t)compctrl6 <<24));
}
__INLINE uint8_t ricu_afe_ctl_19_comp_ctrl_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_19_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00F00000)) >> 20);
}
__INLINE void ricu_afe_ctl_19_comp_ctrl_5_setf(uint8_t compctrl5)
{
	ASSERT_ERR((((uint32_t)compctrl5 << 20) & ~((uint32_t)0x00F00000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_19_ADDR, (REG_PL_RD(RICU_AFE_CTL_19_ADDR) & ~((uint32_t)0x00F00000)) | ((uint32_t)compctrl5 <<20));
}
__INLINE uint8_t ricu_afe_ctl_19_comp_ctrl_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_19_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000F0000)) >> 16);
}
__INLINE void ricu_afe_ctl_19_comp_ctrl_4_setf(uint8_t compctrl4)
{
	ASSERT_ERR((((uint32_t)compctrl4 << 16) & ~((uint32_t)0x000F0000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_19_ADDR, (REG_PL_RD(RICU_AFE_CTL_19_ADDR) & ~((uint32_t)0x000F0000)) | ((uint32_t)compctrl4 <<16));
}
__INLINE uint8_t ricu_afe_ctl_19_comp_ctrl_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_19_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void ricu_afe_ctl_19_comp_ctrl_3_setf(uint8_t compctrl3)
{
	ASSERT_ERR((((uint32_t)compctrl3 << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_19_ADDR, (REG_PL_RD(RICU_AFE_CTL_19_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)compctrl3 <<12));
}
__INLINE uint8_t ricu_afe_ctl_19_comp_ctrl_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_19_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000F00)) >> 8);
}
__INLINE void ricu_afe_ctl_19_comp_ctrl_2_setf(uint8_t compctrl2)
{
	ASSERT_ERR((((uint32_t)compctrl2 << 8) & ~((uint32_t)0x00000F00)) == 0);
	REG_PL_WR(RICU_AFE_CTL_19_ADDR, (REG_PL_RD(RICU_AFE_CTL_19_ADDR) & ~((uint32_t)0x00000F00)) | ((uint32_t)compctrl2 <<8));
}
__INLINE uint8_t ricu_afe_ctl_19_comp_ctrl_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_19_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE void ricu_afe_ctl_19_comp_ctrl_1_setf(uint8_t compctrl1)
{
	ASSERT_ERR((((uint32_t)compctrl1 << 4) & ~((uint32_t)0x000000F0)) == 0);
	REG_PL_WR(RICU_AFE_CTL_19_ADDR, (REG_PL_RD(RICU_AFE_CTL_19_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)compctrl1 <<4));
}
__INLINE uint8_t ricu_afe_ctl_19_comp_ctrl_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_19_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void ricu_afe_ctl_19_comp_ctrl_0_setf(uint8_t compctrl0)
{
	ASSERT_ERR((((uint32_t)compctrl0 << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RICU_AFE_CTL_19_ADDR, (REG_PL_RD(RICU_AFE_CTL_19_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)compctrl0 <<0));
}

/**
 * @brief AFE_CTL_20 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28:24 SIN2_IBIAS_CTRL3          0x10
 *    20:16 SIN2_IBIAS_CTRL2          0x10
 *    12:08 SIN2_IBIAS_CTRL1          0x10
 *    04:00 SIN2_IBIAS_CTRL0          0x10
 * </pre>
 */
#define RICU_AFE_CTL_20_ADDR        (REG_RICU_BASE_ADDR+0x00000060)
#define RICU_AFE_CTL_20_OFFSET      0x00000060
#define RICU_AFE_CTL_20_INDEX       0x00000018
#define RICU_AFE_CTL_20_RESET       0x10101010

__INLINE uint32_t  ricu_afe_ctl_20_get(void)
{
	return REG_PL_RD(RICU_AFE_CTL_20_ADDR);
}

__INLINE void ricu_afe_ctl_20_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTL_20_ADDR, value);
}

// field definitions
#define RICU_AFE_CTL_20_SIN_2_IBIAS_CTRL_3_MASK    ((uint32_t)0x1F000000)
#define RICU_AFE_CTL_20_SIN_2_IBIAS_CTRL_3_LSB    24
#define RICU_AFE_CTL_20_SIN_2_IBIAS_CTRL_3_WIDTH    ((uint32_t)0x00000005)
#define RICU_AFE_CTL_20_SIN_2_IBIAS_CTRL_2_MASK    ((uint32_t)0x001F0000)
#define RICU_AFE_CTL_20_SIN_2_IBIAS_CTRL_2_LSB    16
#define RICU_AFE_CTL_20_SIN_2_IBIAS_CTRL_2_WIDTH    ((uint32_t)0x00000005)
#define RICU_AFE_CTL_20_SIN_2_IBIAS_CTRL_1_MASK    ((uint32_t)0x00001F00)
#define RICU_AFE_CTL_20_SIN_2_IBIAS_CTRL_1_LSB    8
#define RICU_AFE_CTL_20_SIN_2_IBIAS_CTRL_1_WIDTH    ((uint32_t)0x00000005)
#define RICU_AFE_CTL_20_SIN_2_IBIAS_CTRL_0_MASK    ((uint32_t)0x0000001F)
#define RICU_AFE_CTL_20_SIN_2_IBIAS_CTRL_0_LSB    0
#define RICU_AFE_CTL_20_SIN_2_IBIAS_CTRL_0_WIDTH    ((uint32_t)0x00000005)

#define RICU_AFE_CTL_20_SIN_2_IBIAS_CTRL_3_RST    0x10
#define RICU_AFE_CTL_20_SIN_2_IBIAS_CTRL_2_RST    0x10
#define RICU_AFE_CTL_20_SIN_2_IBIAS_CTRL_1_RST    0x10
#define RICU_AFE_CTL_20_SIN_2_IBIAS_CTRL_0_RST    0x10

__INLINE void ricu_afe_ctl_20_pack(uint8_t sin2_ibias_ctrl3, uint8_t sin2_ibias_ctrl2, uint8_t sin2_ibias_ctrl1, uint8_t sin2_ibias_ctrl0)
{
	ASSERT_ERR((((uint32_t)sin2_ibias_ctrl3 << 24) & ~((uint32_t)0x1F000000)) == 0);
	ASSERT_ERR((((uint32_t)sin2_ibias_ctrl2 << 16) & ~((uint32_t)0x001F0000)) == 0);
	ASSERT_ERR((((uint32_t)sin2_ibias_ctrl1 << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)sin2_ibias_ctrl0 << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RICU_AFE_CTL_20_ADDR,  ((uint32_t)sin2_ibias_ctrl3 << 24) |((uint32_t)sin2_ibias_ctrl2 << 16) |((uint32_t)sin2_ibias_ctrl1 << 8) |((uint32_t)sin2_ibias_ctrl0 << 0));
}

__INLINE void ricu_afe_ctl_20_unpack(uint8_t* sin2_ibias_ctrl3, uint8_t* sin2_ibias_ctrl2, uint8_t* sin2_ibias_ctrl1, uint8_t* sin2_ibias_ctrl0)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_20_ADDR);

	*sin2_ibias_ctrl3 = (localVal & ((uint32_t)0x1F000000)) >>  24;
	*sin2_ibias_ctrl2 = (localVal & ((uint32_t)0x001F0000)) >>  16;
	*sin2_ibias_ctrl1 = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*sin2_ibias_ctrl0 = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t ricu_afe_ctl_20_sin_2_ibias_ctrl_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_20_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x1F000000)) >> 24);
}
__INLINE void ricu_afe_ctl_20_sin_2_ibias_ctrl_3_setf(uint8_t sin2ibiasctrl3)
{
	ASSERT_ERR((((uint32_t)sin2ibiasctrl3 << 24) & ~((uint32_t)0x1F000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_20_ADDR, (REG_PL_RD(RICU_AFE_CTL_20_ADDR) & ~((uint32_t)0x1F000000)) | ((uint32_t)sin2ibiasctrl3 <<24));
}
__INLINE uint8_t ricu_afe_ctl_20_sin_2_ibias_ctrl_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_20_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001F0000)) >> 16);
}
__INLINE void ricu_afe_ctl_20_sin_2_ibias_ctrl_2_setf(uint8_t sin2ibiasctrl2)
{
	ASSERT_ERR((((uint32_t)sin2ibiasctrl2 << 16) & ~((uint32_t)0x001F0000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_20_ADDR, (REG_PL_RD(RICU_AFE_CTL_20_ADDR) & ~((uint32_t)0x001F0000)) | ((uint32_t)sin2ibiasctrl2 <<16));
}
__INLINE uint8_t ricu_afe_ctl_20_sin_2_ibias_ctrl_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_20_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void ricu_afe_ctl_20_sin_2_ibias_ctrl_1_setf(uint8_t sin2ibiasctrl1)
{
	ASSERT_ERR((((uint32_t)sin2ibiasctrl1 << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(RICU_AFE_CTL_20_ADDR, (REG_PL_RD(RICU_AFE_CTL_20_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)sin2ibiasctrl1 <<8));
}
__INLINE uint8_t ricu_afe_ctl_20_sin_2_ibias_ctrl_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_20_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void ricu_afe_ctl_20_sin_2_ibias_ctrl_0_setf(uint8_t sin2ibiasctrl0)
{
	ASSERT_ERR((((uint32_t)sin2ibiasctrl0 << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RICU_AFE_CTL_20_ADDR, (REG_PL_RD(RICU_AFE_CTL_20_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)sin2ibiasctrl0 <<0));
}

/**
 * @brief AFE_CTL_21 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:28 VSWBS_CTRL7               0x0
 *    27:24 VSWBS_CTRL6               0x0
 *    23:20 VSWBS_CTRL5               0x0
 *    19:16 VSWBS_CTRL4               0x0
 *    15:12 VSWBS_CTRL3               0x0
 *    11:08 VSWBS_CTRL2               0x0
 *    07:04 VSWBS_CTRL1               0x0
 *    03:00 VSWBS_CTRL0               0x0
 * </pre>
 */
#define RICU_AFE_CTL_21_ADDR        (REG_RICU_BASE_ADDR+0x00000064)
#define RICU_AFE_CTL_21_OFFSET      0x00000064
#define RICU_AFE_CTL_21_INDEX       0x00000019
#define RICU_AFE_CTL_21_RESET       0x00000000

__INLINE uint32_t  ricu_afe_ctl_21_get(void)
{
	return REG_PL_RD(RICU_AFE_CTL_21_ADDR);
}

__INLINE void ricu_afe_ctl_21_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTL_21_ADDR, value);
}

// field definitions
#define RICU_AFE_CTL_21_VSWBS_CTRL_7_MASK    ((uint32_t)0xF0000000)
#define RICU_AFE_CTL_21_VSWBS_CTRL_7_LSB    28
#define RICU_AFE_CTL_21_VSWBS_CTRL_7_WIDTH    ((uint32_t)0x00000004)
#define RICU_AFE_CTL_21_VSWBS_CTRL_6_MASK    ((uint32_t)0x0F000000)
#define RICU_AFE_CTL_21_VSWBS_CTRL_6_LSB    24
#define RICU_AFE_CTL_21_VSWBS_CTRL_6_WIDTH    ((uint32_t)0x00000004)
#define RICU_AFE_CTL_21_VSWBS_CTRL_5_MASK    ((uint32_t)0x00F00000)
#define RICU_AFE_CTL_21_VSWBS_CTRL_5_LSB    20
#define RICU_AFE_CTL_21_VSWBS_CTRL_5_WIDTH    ((uint32_t)0x00000004)
#define RICU_AFE_CTL_21_VSWBS_CTRL_4_MASK    ((uint32_t)0x000F0000)
#define RICU_AFE_CTL_21_VSWBS_CTRL_4_LSB    16
#define RICU_AFE_CTL_21_VSWBS_CTRL_4_WIDTH    ((uint32_t)0x00000004)
#define RICU_AFE_CTL_21_VSWBS_CTRL_3_MASK    ((uint32_t)0x0000F000)
#define RICU_AFE_CTL_21_VSWBS_CTRL_3_LSB    12
#define RICU_AFE_CTL_21_VSWBS_CTRL_3_WIDTH    ((uint32_t)0x00000004)
#define RICU_AFE_CTL_21_VSWBS_CTRL_2_MASK    ((uint32_t)0x00000F00)
#define RICU_AFE_CTL_21_VSWBS_CTRL_2_LSB    8
#define RICU_AFE_CTL_21_VSWBS_CTRL_2_WIDTH    ((uint32_t)0x00000004)
#define RICU_AFE_CTL_21_VSWBS_CTRL_1_MASK    ((uint32_t)0x000000F0)
#define RICU_AFE_CTL_21_VSWBS_CTRL_1_LSB    4
#define RICU_AFE_CTL_21_VSWBS_CTRL_1_WIDTH    ((uint32_t)0x00000004)
#define RICU_AFE_CTL_21_VSWBS_CTRL_0_MASK    ((uint32_t)0x0000000F)
#define RICU_AFE_CTL_21_VSWBS_CTRL_0_LSB    0
#define RICU_AFE_CTL_21_VSWBS_CTRL_0_WIDTH    ((uint32_t)0x00000004)

#define RICU_AFE_CTL_21_VSWBS_CTRL_7_RST    0x0
#define RICU_AFE_CTL_21_VSWBS_CTRL_6_RST    0x0
#define RICU_AFE_CTL_21_VSWBS_CTRL_5_RST    0x0
#define RICU_AFE_CTL_21_VSWBS_CTRL_4_RST    0x0
#define RICU_AFE_CTL_21_VSWBS_CTRL_3_RST    0x0
#define RICU_AFE_CTL_21_VSWBS_CTRL_2_RST    0x0
#define RICU_AFE_CTL_21_VSWBS_CTRL_1_RST    0x0
#define RICU_AFE_CTL_21_VSWBS_CTRL_0_RST    0x0

__INLINE void ricu_afe_ctl_21_pack(uint8_t vswbs_ctrl7, uint8_t vswbs_ctrl6, uint8_t vswbs_ctrl5, uint8_t vswbs_ctrl4, uint8_t vswbs_ctrl3, uint8_t vswbs_ctrl2, uint8_t vswbs_ctrl1, uint8_t vswbs_ctrl0)
{
	ASSERT_ERR((((uint32_t)vswbs_ctrl7 << 28) & ~((uint32_t)0xF0000000)) == 0);
	ASSERT_ERR((((uint32_t)vswbs_ctrl6 << 24) & ~((uint32_t)0x0F000000)) == 0);
	ASSERT_ERR((((uint32_t)vswbs_ctrl5 << 20) & ~((uint32_t)0x00F00000)) == 0);
	ASSERT_ERR((((uint32_t)vswbs_ctrl4 << 16) & ~((uint32_t)0x000F0000)) == 0);
	ASSERT_ERR((((uint32_t)vswbs_ctrl3 << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)vswbs_ctrl2 << 8) & ~((uint32_t)0x00000F00)) == 0);
	ASSERT_ERR((((uint32_t)vswbs_ctrl1 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)vswbs_ctrl0 << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RICU_AFE_CTL_21_ADDR,  ((uint32_t)vswbs_ctrl7 << 28) |((uint32_t)vswbs_ctrl6 << 24) |((uint32_t)vswbs_ctrl5 << 20) |((uint32_t)vswbs_ctrl4 << 16) |((uint32_t)vswbs_ctrl3 << 12) |((uint32_t)vswbs_ctrl2 << 8) |((uint32_t)vswbs_ctrl1 << 4) |((uint32_t)vswbs_ctrl0 << 0));
}

__INLINE void ricu_afe_ctl_21_unpack(uint8_t* vswbs_ctrl7, uint8_t* vswbs_ctrl6, uint8_t* vswbs_ctrl5, uint8_t* vswbs_ctrl4, uint8_t* vswbs_ctrl3, uint8_t* vswbs_ctrl2, uint8_t* vswbs_ctrl1, uint8_t* vswbs_ctrl0)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_21_ADDR);

	*vswbs_ctrl7 = (localVal & ((uint32_t)0xF0000000)) >>  28;
	*vswbs_ctrl6 = (localVal & ((uint32_t)0x0F000000)) >>  24;
	*vswbs_ctrl5 = (localVal & ((uint32_t)0x00F00000)) >>  20;
	*vswbs_ctrl4 = (localVal & ((uint32_t)0x000F0000)) >>  16;
	*vswbs_ctrl3 = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*vswbs_ctrl2 = (localVal & ((uint32_t)0x00000F00)) >>  8;
	*vswbs_ctrl1 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*vswbs_ctrl0 = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t ricu_afe_ctl_21_vswbs_ctrl_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_21_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xF0000000)) >> 28);
}
__INLINE void ricu_afe_ctl_21_vswbs_ctrl_7_setf(uint8_t vswbsctrl7)
{
	ASSERT_ERR((((uint32_t)vswbsctrl7 << 28) & ~((uint32_t)0xF0000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_21_ADDR, (REG_PL_RD(RICU_AFE_CTL_21_ADDR) & ~((uint32_t)0xF0000000)) | ((uint32_t)vswbsctrl7 <<28));
}
__INLINE uint8_t ricu_afe_ctl_21_vswbs_ctrl_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_21_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0F000000)) >> 24);
}
__INLINE void ricu_afe_ctl_21_vswbs_ctrl_6_setf(uint8_t vswbsctrl6)
{
	ASSERT_ERR((((uint32_t)vswbsctrl6 << 24) & ~((uint32_t)0x0F000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_21_ADDR, (REG_PL_RD(RICU_AFE_CTL_21_ADDR) & ~((uint32_t)0x0F000000)) | ((uint32_t)vswbsctrl6 <<24));
}
__INLINE uint8_t ricu_afe_ctl_21_vswbs_ctrl_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_21_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00F00000)) >> 20);
}
__INLINE void ricu_afe_ctl_21_vswbs_ctrl_5_setf(uint8_t vswbsctrl5)
{
	ASSERT_ERR((((uint32_t)vswbsctrl5 << 20) & ~((uint32_t)0x00F00000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_21_ADDR, (REG_PL_RD(RICU_AFE_CTL_21_ADDR) & ~((uint32_t)0x00F00000)) | ((uint32_t)vswbsctrl5 <<20));
}
__INLINE uint8_t ricu_afe_ctl_21_vswbs_ctrl_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_21_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000F0000)) >> 16);
}
__INLINE void ricu_afe_ctl_21_vswbs_ctrl_4_setf(uint8_t vswbsctrl4)
{
	ASSERT_ERR((((uint32_t)vswbsctrl4 << 16) & ~((uint32_t)0x000F0000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_21_ADDR, (REG_PL_RD(RICU_AFE_CTL_21_ADDR) & ~((uint32_t)0x000F0000)) | ((uint32_t)vswbsctrl4 <<16));
}
__INLINE uint8_t ricu_afe_ctl_21_vswbs_ctrl_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_21_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void ricu_afe_ctl_21_vswbs_ctrl_3_setf(uint8_t vswbsctrl3)
{
	ASSERT_ERR((((uint32_t)vswbsctrl3 << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_21_ADDR, (REG_PL_RD(RICU_AFE_CTL_21_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)vswbsctrl3 <<12));
}
__INLINE uint8_t ricu_afe_ctl_21_vswbs_ctrl_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_21_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000F00)) >> 8);
}
__INLINE void ricu_afe_ctl_21_vswbs_ctrl_2_setf(uint8_t vswbsctrl2)
{
	ASSERT_ERR((((uint32_t)vswbsctrl2 << 8) & ~((uint32_t)0x00000F00)) == 0);
	REG_PL_WR(RICU_AFE_CTL_21_ADDR, (REG_PL_RD(RICU_AFE_CTL_21_ADDR) & ~((uint32_t)0x00000F00)) | ((uint32_t)vswbsctrl2 <<8));
}
__INLINE uint8_t ricu_afe_ctl_21_vswbs_ctrl_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_21_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE void ricu_afe_ctl_21_vswbs_ctrl_1_setf(uint8_t vswbsctrl1)
{
	ASSERT_ERR((((uint32_t)vswbsctrl1 << 4) & ~((uint32_t)0x000000F0)) == 0);
	REG_PL_WR(RICU_AFE_CTL_21_ADDR, (REG_PL_RD(RICU_AFE_CTL_21_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)vswbsctrl1 <<4));
}
__INLINE uint8_t ricu_afe_ctl_21_vswbs_ctrl_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_21_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void ricu_afe_ctl_21_vswbs_ctrl_0_setf(uint8_t vswbsctrl0)
{
	ASSERT_ERR((((uint32_t)vswbsctrl0 << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RICU_AFE_CTL_21_ADDR, (REG_PL_RD(RICU_AFE_CTL_21_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)vswbsctrl0 <<0));
}

/**
 * @brief AFE_CTL_22_PHY_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    05    PHY0_EN_ADC5              0              
 *    04    PHY0_EN_ADC4              0              
 *    03    PHY0_EN_ADC3              0              
 *    02    PHY0_EN_ADC2              0              
 *    01    PHY0_EN_ADC1              0              
 *    00    PHY0_EN_ADC0              0              
 * </pre>
 */
#define RICU_AFE_CTL_22_PHY_0_ADDR        (REG_RICU_BASE_ADDR+0x00000068)
#define RICU_AFE_CTL_22_PHY_0_OFFSET      0x00000068
#define RICU_AFE_CTL_22_PHY_0_INDEX       0x0000001A
#define RICU_AFE_CTL_22_PHY_0_RESET       0x00000000

__INLINE uint32_t  ricu_afe_ctl_22_phy_0_get(void)
{
	return REG_PL_RD(RICU_AFE_CTL_22_PHY_0_ADDR);
}

__INLINE void ricu_afe_ctl_22_phy_0_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTL_22_PHY_0_ADDR, value);
}

// field definitions
#define RICU_AFE_CTL_22_PHY_0_PHY_0_EN_ADC_5_BIT    ((uint32_t)0x00000020)
#define RICU_AFE_CTL_22_PHY_0_PHY_0_EN_ADC_5_POS    5
#define RICU_AFE_CTL_22_PHY_0_PHY_0_EN_ADC_4_BIT    ((uint32_t)0x00000010)
#define RICU_AFE_CTL_22_PHY_0_PHY_0_EN_ADC_4_POS    4
#define RICU_AFE_CTL_22_PHY_0_PHY_0_EN_ADC_3_BIT    ((uint32_t)0x00000008)
#define RICU_AFE_CTL_22_PHY_0_PHY_0_EN_ADC_3_POS    3
#define RICU_AFE_CTL_22_PHY_0_PHY_0_EN_ADC_2_BIT    ((uint32_t)0x00000004)
#define RICU_AFE_CTL_22_PHY_0_PHY_0_EN_ADC_2_POS    2
#define RICU_AFE_CTL_22_PHY_0_PHY_0_EN_ADC_1_BIT    ((uint32_t)0x00000002)
#define RICU_AFE_CTL_22_PHY_0_PHY_0_EN_ADC_1_POS    1
#define RICU_AFE_CTL_22_PHY_0_PHY_0_EN_ADC_0_BIT    ((uint32_t)0x00000001)
#define RICU_AFE_CTL_22_PHY_0_PHY_0_EN_ADC_0_POS    0

#define RICU_AFE_CTL_22_PHY_0_PHY_0_EN_ADC_5_RST    0x0
#define RICU_AFE_CTL_22_PHY_0_PHY_0_EN_ADC_4_RST    0x0
#define RICU_AFE_CTL_22_PHY_0_PHY_0_EN_ADC_3_RST    0x0
#define RICU_AFE_CTL_22_PHY_0_PHY_0_EN_ADC_2_RST    0x0
#define RICU_AFE_CTL_22_PHY_0_PHY_0_EN_ADC_1_RST    0x0
#define RICU_AFE_CTL_22_PHY_0_PHY_0_EN_ADC_0_RST    0x0

__INLINE void ricu_afe_ctl_22_phy_0_pack(uint8_t phy0_en_adc5, uint8_t phy0_en_adc4, uint8_t phy0_en_adc3, uint8_t phy0_en_adc2, uint8_t phy0_en_adc1, uint8_t phy0_en_adc0)
{
	ASSERT_ERR((((uint32_t)phy0_en_adc5 << 5) & ~((uint32_t)0x00000020)) == 0);
	ASSERT_ERR((((uint32_t)phy0_en_adc4 << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)phy0_en_adc3 << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)phy0_en_adc2 << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)phy0_en_adc1 << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)phy0_en_adc0 << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RICU_AFE_CTL_22_PHY_0_ADDR,  ((uint32_t)phy0_en_adc5 << 5) |((uint32_t)phy0_en_adc4 << 4) |((uint32_t)phy0_en_adc3 << 3) |((uint32_t)phy0_en_adc2 << 2) |((uint32_t)phy0_en_adc1 << 1) |((uint32_t)phy0_en_adc0 << 0));
}

__INLINE void ricu_afe_ctl_22_phy_0_unpack(uint8_t* phy0_en_adc5, uint8_t* phy0_en_adc4, uint8_t* phy0_en_adc3, uint8_t* phy0_en_adc2, uint8_t* phy0_en_adc1, uint8_t* phy0_en_adc0)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_22_PHY_0_ADDR);

	*phy0_en_adc5 = (localVal & ((uint32_t)0x00000020)) >>  5;
	*phy0_en_adc4 = (localVal & ((uint32_t)0x00000010)) >>  4;
	*phy0_en_adc3 = (localVal & ((uint32_t)0x00000008)) >>  3;
	*phy0_en_adc2 = (localVal & ((uint32_t)0x00000004)) >>  2;
	*phy0_en_adc1 = (localVal & ((uint32_t)0x00000002)) >>  1;
	*phy0_en_adc0 = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t ricu_afe_ctl_22_phy_0_phy_0_en_adc_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_22_PHY_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE void ricu_afe_ctl_22_phy_0_phy_0_en_adc_5_setf(uint8_t phy0enadc5)
{
	ASSERT_ERR((((uint32_t)phy0enadc5 << 5) & ~((uint32_t)0x00000020)) == 0);
	REG_PL_WR(RICU_AFE_CTL_22_PHY_0_ADDR, (REG_PL_RD(RICU_AFE_CTL_22_PHY_0_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)phy0enadc5 <<5));
}
__INLINE uint8_t ricu_afe_ctl_22_phy_0_phy_0_en_adc_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_22_PHY_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void ricu_afe_ctl_22_phy_0_phy_0_en_adc_4_setf(uint8_t phy0enadc4)
{
	ASSERT_ERR((((uint32_t)phy0enadc4 << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(RICU_AFE_CTL_22_PHY_0_ADDR, (REG_PL_RD(RICU_AFE_CTL_22_PHY_0_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)phy0enadc4 <<4));
}
__INLINE uint8_t ricu_afe_ctl_22_phy_0_phy_0_en_adc_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_22_PHY_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void ricu_afe_ctl_22_phy_0_phy_0_en_adc_3_setf(uint8_t phy0enadc3)
{
	ASSERT_ERR((((uint32_t)phy0enadc3 << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(RICU_AFE_CTL_22_PHY_0_ADDR, (REG_PL_RD(RICU_AFE_CTL_22_PHY_0_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)phy0enadc3 <<3));
}
__INLINE uint8_t ricu_afe_ctl_22_phy_0_phy_0_en_adc_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_22_PHY_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void ricu_afe_ctl_22_phy_0_phy_0_en_adc_2_setf(uint8_t phy0enadc2)
{
	ASSERT_ERR((((uint32_t)phy0enadc2 << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(RICU_AFE_CTL_22_PHY_0_ADDR, (REG_PL_RD(RICU_AFE_CTL_22_PHY_0_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)phy0enadc2 <<2));
}
__INLINE uint8_t ricu_afe_ctl_22_phy_0_phy_0_en_adc_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_22_PHY_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void ricu_afe_ctl_22_phy_0_phy_0_en_adc_1_setf(uint8_t phy0enadc1)
{
	ASSERT_ERR((((uint32_t)phy0enadc1 << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(RICU_AFE_CTL_22_PHY_0_ADDR, (REG_PL_RD(RICU_AFE_CTL_22_PHY_0_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)phy0enadc1 <<1));
}
__INLINE uint8_t ricu_afe_ctl_22_phy_0_phy_0_en_adc_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_22_PHY_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void ricu_afe_ctl_22_phy_0_phy_0_en_adc_0_setf(uint8_t phy0enadc0)
{
	ASSERT_ERR((((uint32_t)phy0enadc0 << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RICU_AFE_CTL_22_PHY_0_ADDR, (REG_PL_RD(RICU_AFE_CTL_22_PHY_0_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)phy0enadc0 <<0));
}

/**
 * @brief AFE_CTL_23 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    30:28 VC_LD_AVDI7               0x3
 *    26:24 VC_LD_AVDI6               0x3
 *    22:20 VC_LD_AVDI5               0x3
 *    18:16 VC_LD_AVDI4               0x3
 *    14:12 VC_LD_AVDI3               0x3
 *    10:08 VC_LD_AVDI2               0x3
 *    06:04 VC_LD_AVDI1               0x3
 *    02:00 VC_LD_AVDI0               0x3
 * </pre>
 */
#define RICU_AFE_CTL_23_ADDR        (REG_RICU_BASE_ADDR+0x0000006C)
#define RICU_AFE_CTL_23_OFFSET      0x0000006C
#define RICU_AFE_CTL_23_INDEX       0x0000001B
#define RICU_AFE_CTL_23_RESET       0x33333333

__INLINE uint32_t  ricu_afe_ctl_23_get(void)
{
	return REG_PL_RD(RICU_AFE_CTL_23_ADDR);
}

__INLINE void ricu_afe_ctl_23_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTL_23_ADDR, value);
}

// field definitions
#define RICU_AFE_CTL_23_VC_LD_AVDI_7_MASK    ((uint32_t)0x70000000)
#define RICU_AFE_CTL_23_VC_LD_AVDI_7_LSB    28
#define RICU_AFE_CTL_23_VC_LD_AVDI_7_WIDTH    ((uint32_t)0x00000003)
#define RICU_AFE_CTL_23_VC_LD_AVDI_6_MASK    ((uint32_t)0x07000000)
#define RICU_AFE_CTL_23_VC_LD_AVDI_6_LSB    24
#define RICU_AFE_CTL_23_VC_LD_AVDI_6_WIDTH    ((uint32_t)0x00000003)
#define RICU_AFE_CTL_23_VC_LD_AVDI_5_MASK    ((uint32_t)0x00700000)
#define RICU_AFE_CTL_23_VC_LD_AVDI_5_LSB    20
#define RICU_AFE_CTL_23_VC_LD_AVDI_5_WIDTH    ((uint32_t)0x00000003)
#define RICU_AFE_CTL_23_VC_LD_AVDI_4_MASK    ((uint32_t)0x00070000)
#define RICU_AFE_CTL_23_VC_LD_AVDI_4_LSB    16
#define RICU_AFE_CTL_23_VC_LD_AVDI_4_WIDTH    ((uint32_t)0x00000003)
#define RICU_AFE_CTL_23_VC_LD_AVDI_3_MASK    ((uint32_t)0x00007000)
#define RICU_AFE_CTL_23_VC_LD_AVDI_3_LSB    12
#define RICU_AFE_CTL_23_VC_LD_AVDI_3_WIDTH    ((uint32_t)0x00000003)
#define RICU_AFE_CTL_23_VC_LD_AVDI_2_MASK    ((uint32_t)0x00000700)
#define RICU_AFE_CTL_23_VC_LD_AVDI_2_LSB    8
#define RICU_AFE_CTL_23_VC_LD_AVDI_2_WIDTH    ((uint32_t)0x00000003)
#define RICU_AFE_CTL_23_VC_LD_AVDI_1_MASK    ((uint32_t)0x00000070)
#define RICU_AFE_CTL_23_VC_LD_AVDI_1_LSB    4
#define RICU_AFE_CTL_23_VC_LD_AVDI_1_WIDTH    ((uint32_t)0x00000003)
#define RICU_AFE_CTL_23_VC_LD_AVDI_0_MASK    ((uint32_t)0x00000007)
#define RICU_AFE_CTL_23_VC_LD_AVDI_0_LSB    0
#define RICU_AFE_CTL_23_VC_LD_AVDI_0_WIDTH    ((uint32_t)0x00000003)

#define RICU_AFE_CTL_23_VC_LD_AVDI_7_RST    0x3
#define RICU_AFE_CTL_23_VC_LD_AVDI_6_RST    0x3
#define RICU_AFE_CTL_23_VC_LD_AVDI_5_RST    0x3
#define RICU_AFE_CTL_23_VC_LD_AVDI_4_RST    0x3
#define RICU_AFE_CTL_23_VC_LD_AVDI_3_RST    0x3
#define RICU_AFE_CTL_23_VC_LD_AVDI_2_RST    0x3
#define RICU_AFE_CTL_23_VC_LD_AVDI_1_RST    0x3
#define RICU_AFE_CTL_23_VC_LD_AVDI_0_RST    0x3

__INLINE void ricu_afe_ctl_23_pack(uint8_t vc_ld_avdi7, uint8_t vc_ld_avdi6, uint8_t vc_ld_avdi5, uint8_t vc_ld_avdi4, uint8_t vc_ld_avdi3, uint8_t vc_ld_avdi2, uint8_t vc_ld_avdi1, uint8_t vc_ld_avdi0)
{
	ASSERT_ERR((((uint32_t)vc_ld_avdi7 << 28) & ~((uint32_t)0x70000000)) == 0);
	ASSERT_ERR((((uint32_t)vc_ld_avdi6 << 24) & ~((uint32_t)0x07000000)) == 0);
	ASSERT_ERR((((uint32_t)vc_ld_avdi5 << 20) & ~((uint32_t)0x00700000)) == 0);
	ASSERT_ERR((((uint32_t)vc_ld_avdi4 << 16) & ~((uint32_t)0x00070000)) == 0);
	ASSERT_ERR((((uint32_t)vc_ld_avdi3 << 12) & ~((uint32_t)0x00007000)) == 0);
	ASSERT_ERR((((uint32_t)vc_ld_avdi2 << 8) & ~((uint32_t)0x00000700)) == 0);
	ASSERT_ERR((((uint32_t)vc_ld_avdi1 << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)vc_ld_avdi0 << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(RICU_AFE_CTL_23_ADDR,  ((uint32_t)vc_ld_avdi7 << 28) |((uint32_t)vc_ld_avdi6 << 24) |((uint32_t)vc_ld_avdi5 << 20) |((uint32_t)vc_ld_avdi4 << 16) |((uint32_t)vc_ld_avdi3 << 12) |((uint32_t)vc_ld_avdi2 << 8) |((uint32_t)vc_ld_avdi1 << 4) |((uint32_t)vc_ld_avdi0 << 0));
}

__INLINE void ricu_afe_ctl_23_unpack(uint8_t* vc_ld_avdi7, uint8_t* vc_ld_avdi6, uint8_t* vc_ld_avdi5, uint8_t* vc_ld_avdi4, uint8_t* vc_ld_avdi3, uint8_t* vc_ld_avdi2, uint8_t* vc_ld_avdi1, uint8_t* vc_ld_avdi0)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_23_ADDR);

	*vc_ld_avdi7 = (localVal & ((uint32_t)0x70000000)) >>  28;
	*vc_ld_avdi6 = (localVal & ((uint32_t)0x07000000)) >>  24;
	*vc_ld_avdi5 = (localVal & ((uint32_t)0x00700000)) >>  20;
	*vc_ld_avdi4 = (localVal & ((uint32_t)0x00070000)) >>  16;
	*vc_ld_avdi3 = (localVal & ((uint32_t)0x00007000)) >>  12;
	*vc_ld_avdi2 = (localVal & ((uint32_t)0x00000700)) >>  8;
	*vc_ld_avdi1 = (localVal & ((uint32_t)0x00000070)) >>  4;
	*vc_ld_avdi0 = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t ricu_afe_ctl_23_vc_ld_avdi_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_23_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x70000000)) >> 28);
}
__INLINE void ricu_afe_ctl_23_vc_ld_avdi_7_setf(uint8_t vcldavdi7)
{
	ASSERT_ERR((((uint32_t)vcldavdi7 << 28) & ~((uint32_t)0x70000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_23_ADDR, (REG_PL_RD(RICU_AFE_CTL_23_ADDR) & ~((uint32_t)0x70000000)) | ((uint32_t)vcldavdi7 <<28));
}
__INLINE uint8_t ricu_afe_ctl_23_vc_ld_avdi_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_23_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE void ricu_afe_ctl_23_vc_ld_avdi_6_setf(uint8_t vcldavdi6)
{
	ASSERT_ERR((((uint32_t)vcldavdi6 << 24) & ~((uint32_t)0x07000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_23_ADDR, (REG_PL_RD(RICU_AFE_CTL_23_ADDR) & ~((uint32_t)0x07000000)) | ((uint32_t)vcldavdi6 <<24));
}
__INLINE uint8_t ricu_afe_ctl_23_vc_ld_avdi_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_23_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00700000)) >> 20);
}
__INLINE void ricu_afe_ctl_23_vc_ld_avdi_5_setf(uint8_t vcldavdi5)
{
	ASSERT_ERR((((uint32_t)vcldavdi5 << 20) & ~((uint32_t)0x00700000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_23_ADDR, (REG_PL_RD(RICU_AFE_CTL_23_ADDR) & ~((uint32_t)0x00700000)) | ((uint32_t)vcldavdi5 <<20));
}
__INLINE uint8_t ricu_afe_ctl_23_vc_ld_avdi_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_23_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00070000)) >> 16);
}
__INLINE void ricu_afe_ctl_23_vc_ld_avdi_4_setf(uint8_t vcldavdi4)
{
	ASSERT_ERR((((uint32_t)vcldavdi4 << 16) & ~((uint32_t)0x00070000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_23_ADDR, (REG_PL_RD(RICU_AFE_CTL_23_ADDR) & ~((uint32_t)0x00070000)) | ((uint32_t)vcldavdi4 <<16));
}
__INLINE uint8_t ricu_afe_ctl_23_vc_ld_avdi_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_23_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007000)) >> 12);
}
__INLINE void ricu_afe_ctl_23_vc_ld_avdi_3_setf(uint8_t vcldavdi3)
{
	ASSERT_ERR((((uint32_t)vcldavdi3 << 12) & ~((uint32_t)0x00007000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_23_ADDR, (REG_PL_RD(RICU_AFE_CTL_23_ADDR) & ~((uint32_t)0x00007000)) | ((uint32_t)vcldavdi3 <<12));
}
__INLINE uint8_t ricu_afe_ctl_23_vc_ld_avdi_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_23_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000700)) >> 8);
}
__INLINE void ricu_afe_ctl_23_vc_ld_avdi_2_setf(uint8_t vcldavdi2)
{
	ASSERT_ERR((((uint32_t)vcldavdi2 << 8) & ~((uint32_t)0x00000700)) == 0);
	REG_PL_WR(RICU_AFE_CTL_23_ADDR, (REG_PL_RD(RICU_AFE_CTL_23_ADDR) & ~((uint32_t)0x00000700)) | ((uint32_t)vcldavdi2 <<8));
}
__INLINE uint8_t ricu_afe_ctl_23_vc_ld_avdi_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_23_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void ricu_afe_ctl_23_vc_ld_avdi_1_setf(uint8_t vcldavdi1)
{
	ASSERT_ERR((((uint32_t)vcldavdi1 << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(RICU_AFE_CTL_23_ADDR, (REG_PL_RD(RICU_AFE_CTL_23_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)vcldavdi1 <<4));
}
__INLINE uint8_t ricu_afe_ctl_23_vc_ld_avdi_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_23_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void ricu_afe_ctl_23_vc_ld_avdi_0_setf(uint8_t vcldavdi0)
{
	ASSERT_ERR((((uint32_t)vcldavdi0 << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(RICU_AFE_CTL_23_ADDR, (REG_PL_RD(RICU_AFE_CTL_23_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)vcldavdi0 <<0));
}

/**
 * @brief AFE_CTL_24 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    30:28 VC_LD_AVDQ7               0x3
 *    26:24 VC_LD_AVDQ6               0x3
 *    22:20 VC_LD_AVDQ5               0x3
 *    18:16 VC_LD_AVDQ4               0x3
 *    14:12 VC_LD_AVDQ3               0x3
 *    10:08 VC_LD_AVDQ2               0x3
 *    06:04 VC_LD_AVDQ1               0x3
 *    02:00 VC_LD_AVDQ0               0x3
 * </pre>
 */
#define RICU_AFE_CTL_24_ADDR        (REG_RICU_BASE_ADDR+0x00000070)
#define RICU_AFE_CTL_24_OFFSET      0x00000070
#define RICU_AFE_CTL_24_INDEX       0x0000001C
#define RICU_AFE_CTL_24_RESET       0x33333333

__INLINE uint32_t  ricu_afe_ctl_24_get(void)
{
	return REG_PL_RD(RICU_AFE_CTL_24_ADDR);
}

__INLINE void ricu_afe_ctl_24_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTL_24_ADDR, value);
}

// field definitions
#define RICU_AFE_CTL_24_VC_LD_AVDQ_7_MASK    ((uint32_t)0x70000000)
#define RICU_AFE_CTL_24_VC_LD_AVDQ_7_LSB    28
#define RICU_AFE_CTL_24_VC_LD_AVDQ_7_WIDTH    ((uint32_t)0x00000003)
#define RICU_AFE_CTL_24_VC_LD_AVDQ_6_MASK    ((uint32_t)0x07000000)
#define RICU_AFE_CTL_24_VC_LD_AVDQ_6_LSB    24
#define RICU_AFE_CTL_24_VC_LD_AVDQ_6_WIDTH    ((uint32_t)0x00000003)
#define RICU_AFE_CTL_24_VC_LD_AVDQ_5_MASK    ((uint32_t)0x00700000)
#define RICU_AFE_CTL_24_VC_LD_AVDQ_5_LSB    20
#define RICU_AFE_CTL_24_VC_LD_AVDQ_5_WIDTH    ((uint32_t)0x00000003)
#define RICU_AFE_CTL_24_VC_LD_AVDQ_4_MASK    ((uint32_t)0x00070000)
#define RICU_AFE_CTL_24_VC_LD_AVDQ_4_LSB    16
#define RICU_AFE_CTL_24_VC_LD_AVDQ_4_WIDTH    ((uint32_t)0x00000003)
#define RICU_AFE_CTL_24_VC_LD_AVDQ_3_MASK    ((uint32_t)0x00007000)
#define RICU_AFE_CTL_24_VC_LD_AVDQ_3_LSB    12
#define RICU_AFE_CTL_24_VC_LD_AVDQ_3_WIDTH    ((uint32_t)0x00000003)
#define RICU_AFE_CTL_24_VC_LD_AVDQ_2_MASK    ((uint32_t)0x00000700)
#define RICU_AFE_CTL_24_VC_LD_AVDQ_2_LSB    8
#define RICU_AFE_CTL_24_VC_LD_AVDQ_2_WIDTH    ((uint32_t)0x00000003)
#define RICU_AFE_CTL_24_VC_LD_AVDQ_1_MASK    ((uint32_t)0x00000070)
#define RICU_AFE_CTL_24_VC_LD_AVDQ_1_LSB    4
#define RICU_AFE_CTL_24_VC_LD_AVDQ_1_WIDTH    ((uint32_t)0x00000003)
#define RICU_AFE_CTL_24_VC_LD_AVDQ_0_MASK    ((uint32_t)0x00000007)
#define RICU_AFE_CTL_24_VC_LD_AVDQ_0_LSB    0
#define RICU_AFE_CTL_24_VC_LD_AVDQ_0_WIDTH    ((uint32_t)0x00000003)

#define RICU_AFE_CTL_24_VC_LD_AVDQ_7_RST    0x3
#define RICU_AFE_CTL_24_VC_LD_AVDQ_6_RST    0x3
#define RICU_AFE_CTL_24_VC_LD_AVDQ_5_RST    0x3
#define RICU_AFE_CTL_24_VC_LD_AVDQ_4_RST    0x3
#define RICU_AFE_CTL_24_VC_LD_AVDQ_3_RST    0x3
#define RICU_AFE_CTL_24_VC_LD_AVDQ_2_RST    0x3
#define RICU_AFE_CTL_24_VC_LD_AVDQ_1_RST    0x3
#define RICU_AFE_CTL_24_VC_LD_AVDQ_0_RST    0x3

__INLINE void ricu_afe_ctl_24_pack(uint8_t vc_ld_avdq7, uint8_t vc_ld_avdq6, uint8_t vc_ld_avdq5, uint8_t vc_ld_avdq4, uint8_t vc_ld_avdq3, uint8_t vc_ld_avdq2, uint8_t vc_ld_avdq1, uint8_t vc_ld_avdq0)
{
	ASSERT_ERR((((uint32_t)vc_ld_avdq7 << 28) & ~((uint32_t)0x70000000)) == 0);
	ASSERT_ERR((((uint32_t)vc_ld_avdq6 << 24) & ~((uint32_t)0x07000000)) == 0);
	ASSERT_ERR((((uint32_t)vc_ld_avdq5 << 20) & ~((uint32_t)0x00700000)) == 0);
	ASSERT_ERR((((uint32_t)vc_ld_avdq4 << 16) & ~((uint32_t)0x00070000)) == 0);
	ASSERT_ERR((((uint32_t)vc_ld_avdq3 << 12) & ~((uint32_t)0x00007000)) == 0);
	ASSERT_ERR((((uint32_t)vc_ld_avdq2 << 8) & ~((uint32_t)0x00000700)) == 0);
	ASSERT_ERR((((uint32_t)vc_ld_avdq1 << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)vc_ld_avdq0 << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(RICU_AFE_CTL_24_ADDR,  ((uint32_t)vc_ld_avdq7 << 28) |((uint32_t)vc_ld_avdq6 << 24) |((uint32_t)vc_ld_avdq5 << 20) |((uint32_t)vc_ld_avdq4 << 16) |((uint32_t)vc_ld_avdq3 << 12) |((uint32_t)vc_ld_avdq2 << 8) |((uint32_t)vc_ld_avdq1 << 4) |((uint32_t)vc_ld_avdq0 << 0));
}

__INLINE void ricu_afe_ctl_24_unpack(uint8_t* vc_ld_avdq7, uint8_t* vc_ld_avdq6, uint8_t* vc_ld_avdq5, uint8_t* vc_ld_avdq4, uint8_t* vc_ld_avdq3, uint8_t* vc_ld_avdq2, uint8_t* vc_ld_avdq1, uint8_t* vc_ld_avdq0)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_24_ADDR);

	*vc_ld_avdq7 = (localVal & ((uint32_t)0x70000000)) >>  28;
	*vc_ld_avdq6 = (localVal & ((uint32_t)0x07000000)) >>  24;
	*vc_ld_avdq5 = (localVal & ((uint32_t)0x00700000)) >>  20;
	*vc_ld_avdq4 = (localVal & ((uint32_t)0x00070000)) >>  16;
	*vc_ld_avdq3 = (localVal & ((uint32_t)0x00007000)) >>  12;
	*vc_ld_avdq2 = (localVal & ((uint32_t)0x00000700)) >>  8;
	*vc_ld_avdq1 = (localVal & ((uint32_t)0x00000070)) >>  4;
	*vc_ld_avdq0 = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t ricu_afe_ctl_24_vc_ld_avdq_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_24_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x70000000)) >> 28);
}
__INLINE void ricu_afe_ctl_24_vc_ld_avdq_7_setf(uint8_t vcldavdq7)
{
	ASSERT_ERR((((uint32_t)vcldavdq7 << 28) & ~((uint32_t)0x70000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_24_ADDR, (REG_PL_RD(RICU_AFE_CTL_24_ADDR) & ~((uint32_t)0x70000000)) | ((uint32_t)vcldavdq7 <<28));
}
__INLINE uint8_t ricu_afe_ctl_24_vc_ld_avdq_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_24_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE void ricu_afe_ctl_24_vc_ld_avdq_6_setf(uint8_t vcldavdq6)
{
	ASSERT_ERR((((uint32_t)vcldavdq6 << 24) & ~((uint32_t)0x07000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_24_ADDR, (REG_PL_RD(RICU_AFE_CTL_24_ADDR) & ~((uint32_t)0x07000000)) | ((uint32_t)vcldavdq6 <<24));
}
__INLINE uint8_t ricu_afe_ctl_24_vc_ld_avdq_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_24_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00700000)) >> 20);
}
__INLINE void ricu_afe_ctl_24_vc_ld_avdq_5_setf(uint8_t vcldavdq5)
{
	ASSERT_ERR((((uint32_t)vcldavdq5 << 20) & ~((uint32_t)0x00700000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_24_ADDR, (REG_PL_RD(RICU_AFE_CTL_24_ADDR) & ~((uint32_t)0x00700000)) | ((uint32_t)vcldavdq5 <<20));
}
__INLINE uint8_t ricu_afe_ctl_24_vc_ld_avdq_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_24_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00070000)) >> 16);
}
__INLINE void ricu_afe_ctl_24_vc_ld_avdq_4_setf(uint8_t vcldavdq4)
{
	ASSERT_ERR((((uint32_t)vcldavdq4 << 16) & ~((uint32_t)0x00070000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_24_ADDR, (REG_PL_RD(RICU_AFE_CTL_24_ADDR) & ~((uint32_t)0x00070000)) | ((uint32_t)vcldavdq4 <<16));
}
__INLINE uint8_t ricu_afe_ctl_24_vc_ld_avdq_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_24_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007000)) >> 12);
}
__INLINE void ricu_afe_ctl_24_vc_ld_avdq_3_setf(uint8_t vcldavdq3)
{
	ASSERT_ERR((((uint32_t)vcldavdq3 << 12) & ~((uint32_t)0x00007000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_24_ADDR, (REG_PL_RD(RICU_AFE_CTL_24_ADDR) & ~((uint32_t)0x00007000)) | ((uint32_t)vcldavdq3 <<12));
}
__INLINE uint8_t ricu_afe_ctl_24_vc_ld_avdq_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_24_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000700)) >> 8);
}
__INLINE void ricu_afe_ctl_24_vc_ld_avdq_2_setf(uint8_t vcldavdq2)
{
	ASSERT_ERR((((uint32_t)vcldavdq2 << 8) & ~((uint32_t)0x00000700)) == 0);
	REG_PL_WR(RICU_AFE_CTL_24_ADDR, (REG_PL_RD(RICU_AFE_CTL_24_ADDR) & ~((uint32_t)0x00000700)) | ((uint32_t)vcldavdq2 <<8));
}
__INLINE uint8_t ricu_afe_ctl_24_vc_ld_avdq_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_24_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void ricu_afe_ctl_24_vc_ld_avdq_1_setf(uint8_t vcldavdq1)
{
	ASSERT_ERR((((uint32_t)vcldavdq1 << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(RICU_AFE_CTL_24_ADDR, (REG_PL_RD(RICU_AFE_CTL_24_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)vcldavdq1 <<4));
}
__INLINE uint8_t ricu_afe_ctl_24_vc_ld_avdq_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_24_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void ricu_afe_ctl_24_vc_ld_avdq_0_setf(uint8_t vcldavdq0)
{
	ASSERT_ERR((((uint32_t)vcldavdq0 << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(RICU_AFE_CTL_24_ADDR, (REG_PL_RD(RICU_AFE_CTL_24_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)vcldavdq0 <<0));
}

/**
 * @brief AFE_CTL_25 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    ROSEL0                    0              
 *    14:08 RO_CTRLQ0                 0x7
 *    06:00 RO_CTRLI0                 0x7
 * </pre>
 */
#define RICU_AFE_CTL_25_ADDR        (REG_RICU_BASE_ADDR+0x00000074)
#define RICU_AFE_CTL_25_OFFSET      0x00000074
#define RICU_AFE_CTL_25_INDEX       0x0000001D
#define RICU_AFE_CTL_25_RESET       0x00000707

__INLINE uint32_t  ricu_afe_ctl_25_get(void)
{
	return REG_PL_RD(RICU_AFE_CTL_25_ADDR);
}

__INLINE void ricu_afe_ctl_25_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTL_25_ADDR, value);
}

// field definitions
#define RICU_AFE_CTL_25_ROSEL_0_BIT         ((uint32_t)0x00010000)
#define RICU_AFE_CTL_25_ROSEL_0_POS         16
#define RICU_AFE_CTL_25_RO_CTRLQ_0_MASK     ((uint32_t)0x00007F00)
#define RICU_AFE_CTL_25_RO_CTRLQ_0_LSB      8
#define RICU_AFE_CTL_25_RO_CTRLQ_0_WIDTH    ((uint32_t)0x00000007)
#define RICU_AFE_CTL_25_RO_CTRLI_0_MASK     ((uint32_t)0x0000007F)
#define RICU_AFE_CTL_25_RO_CTRLI_0_LSB      0
#define RICU_AFE_CTL_25_RO_CTRLI_0_WIDTH    ((uint32_t)0x00000007)

#define RICU_AFE_CTL_25_ROSEL_0_RST         0x0
#define RICU_AFE_CTL_25_RO_CTRLQ_0_RST      0x7
#define RICU_AFE_CTL_25_RO_CTRLI_0_RST      0x7

__INLINE void ricu_afe_ctl_25_pack(uint8_t rosel0, uint8_t ro_ctrlq0, uint8_t ro_ctrli0)
{
	ASSERT_ERR((((uint32_t)rosel0 << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)ro_ctrlq0 << 8) & ~((uint32_t)0x00007F00)) == 0);
	ASSERT_ERR((((uint32_t)ro_ctrli0 << 0) & ~((uint32_t)0x0000007F)) == 0);
	REG_PL_WR(RICU_AFE_CTL_25_ADDR,  ((uint32_t)rosel0 << 16) |((uint32_t)ro_ctrlq0 << 8) |((uint32_t)ro_ctrli0 << 0));
}

__INLINE void ricu_afe_ctl_25_unpack(uint8_t* rosel0, uint8_t* ro_ctrlq0, uint8_t* ro_ctrli0)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_25_ADDR);

	*rosel0 = (localVal & ((uint32_t)0x00010000)) >>  16;
	*ro_ctrlq0 = (localVal & ((uint32_t)0x00007F00)) >>  8;
	*ro_ctrli0 = (localVal & ((uint32_t)0x0000007F)) >>  0;
}

__INLINE uint8_t ricu_afe_ctl_25_rosel_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_25_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void ricu_afe_ctl_25_rosel_0_setf(uint8_t rosel0)
{
	ASSERT_ERR((((uint32_t)rosel0 << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_25_ADDR, (REG_PL_RD(RICU_AFE_CTL_25_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)rosel0 <<16));
}
__INLINE uint8_t ricu_afe_ctl_25_ro_ctrlq_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_25_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007F00)) >> 8);
}
__INLINE void ricu_afe_ctl_25_ro_ctrlq_0_setf(uint8_t roctrlq0)
{
	ASSERT_ERR((((uint32_t)roctrlq0 << 8) & ~((uint32_t)0x00007F00)) == 0);
	REG_PL_WR(RICU_AFE_CTL_25_ADDR, (REG_PL_RD(RICU_AFE_CTL_25_ADDR) & ~((uint32_t)0x00007F00)) | ((uint32_t)roctrlq0 <<8));
}
__INLINE uint8_t ricu_afe_ctl_25_ro_ctrli_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_25_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000007F)) >> 0);
}
__INLINE void ricu_afe_ctl_25_ro_ctrli_0_setf(uint8_t roctrli0)
{
	ASSERT_ERR((((uint32_t)roctrli0 << 0) & ~((uint32_t)0x0000007F)) == 0);
	REG_PL_WR(RICU_AFE_CTL_25_ADDR, (REG_PL_RD(RICU_AFE_CTL_25_ADDR) & ~((uint32_t)0x0000007F)) | ((uint32_t)roctrli0 <<0));
}

/**
 * @brief AFE_CTL_26 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    ROSEL1                    0              
 *    14:08 RO_CTRLQ1                 0x7
 *    06:00 RO_CTRLI1                 0x7
 * </pre>
 */
#define RICU_AFE_CTL_26_ADDR        (REG_RICU_BASE_ADDR+0x00000078)
#define RICU_AFE_CTL_26_OFFSET      0x00000078
#define RICU_AFE_CTL_26_INDEX       0x0000001E
#define RICU_AFE_CTL_26_RESET       0x00000707

__INLINE uint32_t  ricu_afe_ctl_26_get(void)
{
	return REG_PL_RD(RICU_AFE_CTL_26_ADDR);
}

__INLINE void ricu_afe_ctl_26_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTL_26_ADDR, value);
}

// field definitions
#define RICU_AFE_CTL_26_ROSEL_1_BIT         ((uint32_t)0x00010000)
#define RICU_AFE_CTL_26_ROSEL_1_POS         16
#define RICU_AFE_CTL_26_RO_CTRLQ_1_MASK     ((uint32_t)0x00007F00)
#define RICU_AFE_CTL_26_RO_CTRLQ_1_LSB      8
#define RICU_AFE_CTL_26_RO_CTRLQ_1_WIDTH    ((uint32_t)0x00000007)
#define RICU_AFE_CTL_26_RO_CTRLI_1_MASK     ((uint32_t)0x0000007F)
#define RICU_AFE_CTL_26_RO_CTRLI_1_LSB      0
#define RICU_AFE_CTL_26_RO_CTRLI_1_WIDTH    ((uint32_t)0x00000007)

#define RICU_AFE_CTL_26_ROSEL_1_RST         0x0
#define RICU_AFE_CTL_26_RO_CTRLQ_1_RST      0x7
#define RICU_AFE_CTL_26_RO_CTRLI_1_RST      0x7

__INLINE void ricu_afe_ctl_26_pack(uint8_t rosel1, uint8_t ro_ctrlq1, uint8_t ro_ctrli1)
{
	ASSERT_ERR((((uint32_t)rosel1 << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)ro_ctrlq1 << 8) & ~((uint32_t)0x00007F00)) == 0);
	ASSERT_ERR((((uint32_t)ro_ctrli1 << 0) & ~((uint32_t)0x0000007F)) == 0);
	REG_PL_WR(RICU_AFE_CTL_26_ADDR,  ((uint32_t)rosel1 << 16) |((uint32_t)ro_ctrlq1 << 8) |((uint32_t)ro_ctrli1 << 0));
}

__INLINE void ricu_afe_ctl_26_unpack(uint8_t* rosel1, uint8_t* ro_ctrlq1, uint8_t* ro_ctrli1)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_26_ADDR);

	*rosel1 = (localVal & ((uint32_t)0x00010000)) >>  16;
	*ro_ctrlq1 = (localVal & ((uint32_t)0x00007F00)) >>  8;
	*ro_ctrli1 = (localVal & ((uint32_t)0x0000007F)) >>  0;
}

__INLINE uint8_t ricu_afe_ctl_26_rosel_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_26_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void ricu_afe_ctl_26_rosel_1_setf(uint8_t rosel1)
{
	ASSERT_ERR((((uint32_t)rosel1 << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_26_ADDR, (REG_PL_RD(RICU_AFE_CTL_26_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)rosel1 <<16));
}
__INLINE uint8_t ricu_afe_ctl_26_ro_ctrlq_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_26_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007F00)) >> 8);
}
__INLINE void ricu_afe_ctl_26_ro_ctrlq_1_setf(uint8_t roctrlq1)
{
	ASSERT_ERR((((uint32_t)roctrlq1 << 8) & ~((uint32_t)0x00007F00)) == 0);
	REG_PL_WR(RICU_AFE_CTL_26_ADDR, (REG_PL_RD(RICU_AFE_CTL_26_ADDR) & ~((uint32_t)0x00007F00)) | ((uint32_t)roctrlq1 <<8));
}
__INLINE uint8_t ricu_afe_ctl_26_ro_ctrli_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_26_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000007F)) >> 0);
}
__INLINE void ricu_afe_ctl_26_ro_ctrli_1_setf(uint8_t roctrli1)
{
	ASSERT_ERR((((uint32_t)roctrli1 << 0) & ~((uint32_t)0x0000007F)) == 0);
	REG_PL_WR(RICU_AFE_CTL_26_ADDR, (REG_PL_RD(RICU_AFE_CTL_26_ADDR) & ~((uint32_t)0x0000007F)) | ((uint32_t)roctrli1 <<0));
}

/**
 * @brief AFE_CTL_27 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    ROSEL2                    0              
 *    14:08 RO_CTRLQ2                 0x7
 *    06:00 RO_CTRLI2                 0x7
 * </pre>
 */
#define RICU_AFE_CTL_27_ADDR        (REG_RICU_BASE_ADDR+0x0000007C)
#define RICU_AFE_CTL_27_OFFSET      0x0000007C
#define RICU_AFE_CTL_27_INDEX       0x0000001F
#define RICU_AFE_CTL_27_RESET       0x00000707

__INLINE uint32_t  ricu_afe_ctl_27_get(void)
{
	return REG_PL_RD(RICU_AFE_CTL_27_ADDR);
}

__INLINE void ricu_afe_ctl_27_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTL_27_ADDR, value);
}

// field definitions
#define RICU_AFE_CTL_27_ROSEL_2_BIT         ((uint32_t)0x00010000)
#define RICU_AFE_CTL_27_ROSEL_2_POS         16
#define RICU_AFE_CTL_27_RO_CTRLQ_2_MASK     ((uint32_t)0x00007F00)
#define RICU_AFE_CTL_27_RO_CTRLQ_2_LSB      8
#define RICU_AFE_CTL_27_RO_CTRLQ_2_WIDTH    ((uint32_t)0x00000007)
#define RICU_AFE_CTL_27_RO_CTRLI_2_MASK     ((uint32_t)0x0000007F)
#define RICU_AFE_CTL_27_RO_CTRLI_2_LSB      0
#define RICU_AFE_CTL_27_RO_CTRLI_2_WIDTH    ((uint32_t)0x00000007)

#define RICU_AFE_CTL_27_ROSEL_2_RST         0x0
#define RICU_AFE_CTL_27_RO_CTRLQ_2_RST      0x7
#define RICU_AFE_CTL_27_RO_CTRLI_2_RST      0x7

__INLINE void ricu_afe_ctl_27_pack(uint8_t rosel2, uint8_t ro_ctrlq2, uint8_t ro_ctrli2)
{
	ASSERT_ERR((((uint32_t)rosel2 << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)ro_ctrlq2 << 8) & ~((uint32_t)0x00007F00)) == 0);
	ASSERT_ERR((((uint32_t)ro_ctrli2 << 0) & ~((uint32_t)0x0000007F)) == 0);
	REG_PL_WR(RICU_AFE_CTL_27_ADDR,  ((uint32_t)rosel2 << 16) |((uint32_t)ro_ctrlq2 << 8) |((uint32_t)ro_ctrli2 << 0));
}

__INLINE void ricu_afe_ctl_27_unpack(uint8_t* rosel2, uint8_t* ro_ctrlq2, uint8_t* ro_ctrli2)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_27_ADDR);

	*rosel2 = (localVal & ((uint32_t)0x00010000)) >>  16;
	*ro_ctrlq2 = (localVal & ((uint32_t)0x00007F00)) >>  8;
	*ro_ctrli2 = (localVal & ((uint32_t)0x0000007F)) >>  0;
}

__INLINE uint8_t ricu_afe_ctl_27_rosel_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_27_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void ricu_afe_ctl_27_rosel_2_setf(uint8_t rosel2)
{
	ASSERT_ERR((((uint32_t)rosel2 << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_27_ADDR, (REG_PL_RD(RICU_AFE_CTL_27_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)rosel2 <<16));
}
__INLINE uint8_t ricu_afe_ctl_27_ro_ctrlq_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_27_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007F00)) >> 8);
}
__INLINE void ricu_afe_ctl_27_ro_ctrlq_2_setf(uint8_t roctrlq2)
{
	ASSERT_ERR((((uint32_t)roctrlq2 << 8) & ~((uint32_t)0x00007F00)) == 0);
	REG_PL_WR(RICU_AFE_CTL_27_ADDR, (REG_PL_RD(RICU_AFE_CTL_27_ADDR) & ~((uint32_t)0x00007F00)) | ((uint32_t)roctrlq2 <<8));
}
__INLINE uint8_t ricu_afe_ctl_27_ro_ctrli_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_27_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000007F)) >> 0);
}
__INLINE void ricu_afe_ctl_27_ro_ctrli_2_setf(uint8_t roctrli2)
{
	ASSERT_ERR((((uint32_t)roctrli2 << 0) & ~((uint32_t)0x0000007F)) == 0);
	REG_PL_WR(RICU_AFE_CTL_27_ADDR, (REG_PL_RD(RICU_AFE_CTL_27_ADDR) & ~((uint32_t)0x0000007F)) | ((uint32_t)roctrli2 <<0));
}

/**
 * @brief AFE_CTL_28 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:28 SIN1_CTRL7                0x4
 *    27:24 SIN1_CTRL6                0x4
 *    23:20 SIN1_CTRL5                0x4
 *    19:16 SIN1_CTRL4                0x4
 *    15:12 SIN1_CTRL3                0x4
 *    11:08 SIN1_CTRL2                0x4
 *    07:04 SIN1_CTRL1                0x4
 *    03:00 SIN1_CTRL0                0x4
 * </pre>
 */
#define RICU_AFE_CTL_28_ADDR        (REG_RICU_BASE_ADDR+0x00000080)
#define RICU_AFE_CTL_28_OFFSET      0x00000080
#define RICU_AFE_CTL_28_INDEX       0x00000020
#define RICU_AFE_CTL_28_RESET       0x44444444

__INLINE uint32_t  ricu_afe_ctl_28_get(void)
{
	return REG_PL_RD(RICU_AFE_CTL_28_ADDR);
}

__INLINE void ricu_afe_ctl_28_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTL_28_ADDR, value);
}

// field definitions
#define RICU_AFE_CTL_28_SIN_1_CTRL_7_MASK    ((uint32_t)0xF0000000)
#define RICU_AFE_CTL_28_SIN_1_CTRL_7_LSB    28
#define RICU_AFE_CTL_28_SIN_1_CTRL_7_WIDTH    ((uint32_t)0x00000004)
#define RICU_AFE_CTL_28_SIN_1_CTRL_6_MASK    ((uint32_t)0x0F000000)
#define RICU_AFE_CTL_28_SIN_1_CTRL_6_LSB    24
#define RICU_AFE_CTL_28_SIN_1_CTRL_6_WIDTH    ((uint32_t)0x00000004)
#define RICU_AFE_CTL_28_SIN_1_CTRL_5_MASK    ((uint32_t)0x00F00000)
#define RICU_AFE_CTL_28_SIN_1_CTRL_5_LSB    20
#define RICU_AFE_CTL_28_SIN_1_CTRL_5_WIDTH    ((uint32_t)0x00000004)
#define RICU_AFE_CTL_28_SIN_1_CTRL_4_MASK    ((uint32_t)0x000F0000)
#define RICU_AFE_CTL_28_SIN_1_CTRL_4_LSB    16
#define RICU_AFE_CTL_28_SIN_1_CTRL_4_WIDTH    ((uint32_t)0x00000004)
#define RICU_AFE_CTL_28_SIN_1_CTRL_3_MASK    ((uint32_t)0x0000F000)
#define RICU_AFE_CTL_28_SIN_1_CTRL_3_LSB    12
#define RICU_AFE_CTL_28_SIN_1_CTRL_3_WIDTH    ((uint32_t)0x00000004)
#define RICU_AFE_CTL_28_SIN_1_CTRL_2_MASK    ((uint32_t)0x00000F00)
#define RICU_AFE_CTL_28_SIN_1_CTRL_2_LSB    8
#define RICU_AFE_CTL_28_SIN_1_CTRL_2_WIDTH    ((uint32_t)0x00000004)
#define RICU_AFE_CTL_28_SIN_1_CTRL_1_MASK    ((uint32_t)0x000000F0)
#define RICU_AFE_CTL_28_SIN_1_CTRL_1_LSB    4
#define RICU_AFE_CTL_28_SIN_1_CTRL_1_WIDTH    ((uint32_t)0x00000004)
#define RICU_AFE_CTL_28_SIN_1_CTRL_0_MASK    ((uint32_t)0x0000000F)
#define RICU_AFE_CTL_28_SIN_1_CTRL_0_LSB    0
#define RICU_AFE_CTL_28_SIN_1_CTRL_0_WIDTH    ((uint32_t)0x00000004)

#define RICU_AFE_CTL_28_SIN_1_CTRL_7_RST    0x4
#define RICU_AFE_CTL_28_SIN_1_CTRL_6_RST    0x4
#define RICU_AFE_CTL_28_SIN_1_CTRL_5_RST    0x4
#define RICU_AFE_CTL_28_SIN_1_CTRL_4_RST    0x4
#define RICU_AFE_CTL_28_SIN_1_CTRL_3_RST    0x4
#define RICU_AFE_CTL_28_SIN_1_CTRL_2_RST    0x4
#define RICU_AFE_CTL_28_SIN_1_CTRL_1_RST    0x4
#define RICU_AFE_CTL_28_SIN_1_CTRL_0_RST    0x4

__INLINE void ricu_afe_ctl_28_pack(uint8_t sin1_ctrl7, uint8_t sin1_ctrl6, uint8_t sin1_ctrl5, uint8_t sin1_ctrl4, uint8_t sin1_ctrl3, uint8_t sin1_ctrl2, uint8_t sin1_ctrl1, uint8_t sin1_ctrl0)
{
	ASSERT_ERR((((uint32_t)sin1_ctrl7 << 28) & ~((uint32_t)0xF0000000)) == 0);
	ASSERT_ERR((((uint32_t)sin1_ctrl6 << 24) & ~((uint32_t)0x0F000000)) == 0);
	ASSERT_ERR((((uint32_t)sin1_ctrl5 << 20) & ~((uint32_t)0x00F00000)) == 0);
	ASSERT_ERR((((uint32_t)sin1_ctrl4 << 16) & ~((uint32_t)0x000F0000)) == 0);
	ASSERT_ERR((((uint32_t)sin1_ctrl3 << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)sin1_ctrl2 << 8) & ~((uint32_t)0x00000F00)) == 0);
	ASSERT_ERR((((uint32_t)sin1_ctrl1 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)sin1_ctrl0 << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RICU_AFE_CTL_28_ADDR,  ((uint32_t)sin1_ctrl7 << 28) |((uint32_t)sin1_ctrl6 << 24) |((uint32_t)sin1_ctrl5 << 20) |((uint32_t)sin1_ctrl4 << 16) |((uint32_t)sin1_ctrl3 << 12) |((uint32_t)sin1_ctrl2 << 8) |((uint32_t)sin1_ctrl1 << 4) |((uint32_t)sin1_ctrl0 << 0));
}

__INLINE void ricu_afe_ctl_28_unpack(uint8_t* sin1_ctrl7, uint8_t* sin1_ctrl6, uint8_t* sin1_ctrl5, uint8_t* sin1_ctrl4, uint8_t* sin1_ctrl3, uint8_t* sin1_ctrl2, uint8_t* sin1_ctrl1, uint8_t* sin1_ctrl0)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_28_ADDR);

	*sin1_ctrl7 = (localVal & ((uint32_t)0xF0000000)) >>  28;
	*sin1_ctrl6 = (localVal & ((uint32_t)0x0F000000)) >>  24;
	*sin1_ctrl5 = (localVal & ((uint32_t)0x00F00000)) >>  20;
	*sin1_ctrl4 = (localVal & ((uint32_t)0x000F0000)) >>  16;
	*sin1_ctrl3 = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*sin1_ctrl2 = (localVal & ((uint32_t)0x00000F00)) >>  8;
	*sin1_ctrl1 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*sin1_ctrl0 = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t ricu_afe_ctl_28_sin_1_ctrl_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_28_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xF0000000)) >> 28);
}
__INLINE void ricu_afe_ctl_28_sin_1_ctrl_7_setf(uint8_t sin1ctrl7)
{
	ASSERT_ERR((((uint32_t)sin1ctrl7 << 28) & ~((uint32_t)0xF0000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_28_ADDR, (REG_PL_RD(RICU_AFE_CTL_28_ADDR) & ~((uint32_t)0xF0000000)) | ((uint32_t)sin1ctrl7 <<28));
}
__INLINE uint8_t ricu_afe_ctl_28_sin_1_ctrl_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_28_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0F000000)) >> 24);
}
__INLINE void ricu_afe_ctl_28_sin_1_ctrl_6_setf(uint8_t sin1ctrl6)
{
	ASSERT_ERR((((uint32_t)sin1ctrl6 << 24) & ~((uint32_t)0x0F000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_28_ADDR, (REG_PL_RD(RICU_AFE_CTL_28_ADDR) & ~((uint32_t)0x0F000000)) | ((uint32_t)sin1ctrl6 <<24));
}
__INLINE uint8_t ricu_afe_ctl_28_sin_1_ctrl_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_28_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00F00000)) >> 20);
}
__INLINE void ricu_afe_ctl_28_sin_1_ctrl_5_setf(uint8_t sin1ctrl5)
{
	ASSERT_ERR((((uint32_t)sin1ctrl5 << 20) & ~((uint32_t)0x00F00000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_28_ADDR, (REG_PL_RD(RICU_AFE_CTL_28_ADDR) & ~((uint32_t)0x00F00000)) | ((uint32_t)sin1ctrl5 <<20));
}
__INLINE uint8_t ricu_afe_ctl_28_sin_1_ctrl_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_28_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000F0000)) >> 16);
}
__INLINE void ricu_afe_ctl_28_sin_1_ctrl_4_setf(uint8_t sin1ctrl4)
{
	ASSERT_ERR((((uint32_t)sin1ctrl4 << 16) & ~((uint32_t)0x000F0000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_28_ADDR, (REG_PL_RD(RICU_AFE_CTL_28_ADDR) & ~((uint32_t)0x000F0000)) | ((uint32_t)sin1ctrl4 <<16));
}
__INLINE uint8_t ricu_afe_ctl_28_sin_1_ctrl_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_28_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void ricu_afe_ctl_28_sin_1_ctrl_3_setf(uint8_t sin1ctrl3)
{
	ASSERT_ERR((((uint32_t)sin1ctrl3 << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_28_ADDR, (REG_PL_RD(RICU_AFE_CTL_28_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)sin1ctrl3 <<12));
}
__INLINE uint8_t ricu_afe_ctl_28_sin_1_ctrl_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_28_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000F00)) >> 8);
}
__INLINE void ricu_afe_ctl_28_sin_1_ctrl_2_setf(uint8_t sin1ctrl2)
{
	ASSERT_ERR((((uint32_t)sin1ctrl2 << 8) & ~((uint32_t)0x00000F00)) == 0);
	REG_PL_WR(RICU_AFE_CTL_28_ADDR, (REG_PL_RD(RICU_AFE_CTL_28_ADDR) & ~((uint32_t)0x00000F00)) | ((uint32_t)sin1ctrl2 <<8));
}
__INLINE uint8_t ricu_afe_ctl_28_sin_1_ctrl_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_28_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE void ricu_afe_ctl_28_sin_1_ctrl_1_setf(uint8_t sin1ctrl1)
{
	ASSERT_ERR((((uint32_t)sin1ctrl1 << 4) & ~((uint32_t)0x000000F0)) == 0);
	REG_PL_WR(RICU_AFE_CTL_28_ADDR, (REG_PL_RD(RICU_AFE_CTL_28_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)sin1ctrl1 <<4));
}
__INLINE uint8_t ricu_afe_ctl_28_sin_1_ctrl_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_28_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void ricu_afe_ctl_28_sin_1_ctrl_0_setf(uint8_t sin1ctrl0)
{
	ASSERT_ERR((((uint32_t)sin1ctrl0 << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RICU_AFE_CTL_28_ADDR, (REG_PL_RD(RICU_AFE_CTL_28_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)sin1ctrl0 <<0));
}

/**
 * @brief AFE_CTL_29 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    30:28 VC_CML7_I                 0x5
 *    26:24 VC_CML6_I                 0x5
 *    22:20 VC_CML5_I                 0x5
 *    18:16 VC_CML4_I                 0x5
 *    14:12 VC_CML3_I                 0x5
 *    10:08 VC_CML2_I                 0x5
 *    06:04 VC_CML1_I                 0x5
 *    02:00 VC_CML0_I                 0x5
 * </pre>
 */
#define RICU_AFE_CTL_29_ADDR        (REG_RICU_BASE_ADDR+0x00000084)
#define RICU_AFE_CTL_29_OFFSET      0x00000084
#define RICU_AFE_CTL_29_INDEX       0x00000021
#define RICU_AFE_CTL_29_RESET       0x55555555

__INLINE uint32_t  ricu_afe_ctl_29_get(void)
{
	return REG_PL_RD(RICU_AFE_CTL_29_ADDR);
}

__INLINE void ricu_afe_ctl_29_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTL_29_ADDR, value);
}

// field definitions
#define RICU_AFE_CTL_29_VC_CML_7_I_MASK     ((uint32_t)0x70000000)
#define RICU_AFE_CTL_29_VC_CML_7_I_LSB      28
#define RICU_AFE_CTL_29_VC_CML_7_I_WIDTH    ((uint32_t)0x00000003)
#define RICU_AFE_CTL_29_VC_CML_6_I_MASK     ((uint32_t)0x07000000)
#define RICU_AFE_CTL_29_VC_CML_6_I_LSB      24
#define RICU_AFE_CTL_29_VC_CML_6_I_WIDTH    ((uint32_t)0x00000003)
#define RICU_AFE_CTL_29_VC_CML_5_I_MASK     ((uint32_t)0x00700000)
#define RICU_AFE_CTL_29_VC_CML_5_I_LSB      20
#define RICU_AFE_CTL_29_VC_CML_5_I_WIDTH    ((uint32_t)0x00000003)
#define RICU_AFE_CTL_29_VC_CML_4_I_MASK     ((uint32_t)0x00070000)
#define RICU_AFE_CTL_29_VC_CML_4_I_LSB      16
#define RICU_AFE_CTL_29_VC_CML_4_I_WIDTH    ((uint32_t)0x00000003)
#define RICU_AFE_CTL_29_VC_CML_3_I_MASK     ((uint32_t)0x00007000)
#define RICU_AFE_CTL_29_VC_CML_3_I_LSB      12
#define RICU_AFE_CTL_29_VC_CML_3_I_WIDTH    ((uint32_t)0x00000003)
#define RICU_AFE_CTL_29_VC_CML_2_I_MASK     ((uint32_t)0x00000700)
#define RICU_AFE_CTL_29_VC_CML_2_I_LSB      8
#define RICU_AFE_CTL_29_VC_CML_2_I_WIDTH    ((uint32_t)0x00000003)
#define RICU_AFE_CTL_29_VC_CML_1_I_MASK     ((uint32_t)0x00000070)
#define RICU_AFE_CTL_29_VC_CML_1_I_LSB      4
#define RICU_AFE_CTL_29_VC_CML_1_I_WIDTH    ((uint32_t)0x00000003)
#define RICU_AFE_CTL_29_VC_CML_0_I_MASK     ((uint32_t)0x00000007)
#define RICU_AFE_CTL_29_VC_CML_0_I_LSB      0
#define RICU_AFE_CTL_29_VC_CML_0_I_WIDTH    ((uint32_t)0x00000003)

#define RICU_AFE_CTL_29_VC_CML_7_I_RST      0x5
#define RICU_AFE_CTL_29_VC_CML_6_I_RST      0x5
#define RICU_AFE_CTL_29_VC_CML_5_I_RST      0x5
#define RICU_AFE_CTL_29_VC_CML_4_I_RST      0x5
#define RICU_AFE_CTL_29_VC_CML_3_I_RST      0x5
#define RICU_AFE_CTL_29_VC_CML_2_I_RST      0x5
#define RICU_AFE_CTL_29_VC_CML_1_I_RST      0x5
#define RICU_AFE_CTL_29_VC_CML_0_I_RST      0x5

__INLINE void ricu_afe_ctl_29_pack(uint8_t vc_cml7_i, uint8_t vc_cml6_i, uint8_t vc_cml5_i, uint8_t vc_cml4_i, uint8_t vc_cml3_i, uint8_t vc_cml2_i, uint8_t vc_cml1_i, uint8_t vc_cml0_i)
{
	ASSERT_ERR((((uint32_t)vc_cml7_i << 28) & ~((uint32_t)0x70000000)) == 0);
	ASSERT_ERR((((uint32_t)vc_cml6_i << 24) & ~((uint32_t)0x07000000)) == 0);
	ASSERT_ERR((((uint32_t)vc_cml5_i << 20) & ~((uint32_t)0x00700000)) == 0);
	ASSERT_ERR((((uint32_t)vc_cml4_i << 16) & ~((uint32_t)0x00070000)) == 0);
	ASSERT_ERR((((uint32_t)vc_cml3_i << 12) & ~((uint32_t)0x00007000)) == 0);
	ASSERT_ERR((((uint32_t)vc_cml2_i << 8) & ~((uint32_t)0x00000700)) == 0);
	ASSERT_ERR((((uint32_t)vc_cml1_i << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)vc_cml0_i << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(RICU_AFE_CTL_29_ADDR,  ((uint32_t)vc_cml7_i << 28) |((uint32_t)vc_cml6_i << 24) |((uint32_t)vc_cml5_i << 20) |((uint32_t)vc_cml4_i << 16) |((uint32_t)vc_cml3_i << 12) |((uint32_t)vc_cml2_i << 8) |((uint32_t)vc_cml1_i << 4) |((uint32_t)vc_cml0_i << 0));
}

__INLINE void ricu_afe_ctl_29_unpack(uint8_t* vc_cml7_i, uint8_t* vc_cml6_i, uint8_t* vc_cml5_i, uint8_t* vc_cml4_i, uint8_t* vc_cml3_i, uint8_t* vc_cml2_i, uint8_t* vc_cml1_i, uint8_t* vc_cml0_i)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_29_ADDR);

	*vc_cml7_i = (localVal & ((uint32_t)0x70000000)) >>  28;
	*vc_cml6_i = (localVal & ((uint32_t)0x07000000)) >>  24;
	*vc_cml5_i = (localVal & ((uint32_t)0x00700000)) >>  20;
	*vc_cml4_i = (localVal & ((uint32_t)0x00070000)) >>  16;
	*vc_cml3_i = (localVal & ((uint32_t)0x00007000)) >>  12;
	*vc_cml2_i = (localVal & ((uint32_t)0x00000700)) >>  8;
	*vc_cml1_i = (localVal & ((uint32_t)0x00000070)) >>  4;
	*vc_cml0_i = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t ricu_afe_ctl_29_vc_cml_7_i_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_29_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x70000000)) >> 28);
}
__INLINE void ricu_afe_ctl_29_vc_cml_7_i_setf(uint8_t vccml7i)
{
	ASSERT_ERR((((uint32_t)vccml7i << 28) & ~((uint32_t)0x70000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_29_ADDR, (REG_PL_RD(RICU_AFE_CTL_29_ADDR) & ~((uint32_t)0x70000000)) | ((uint32_t)vccml7i <<28));
}
__INLINE uint8_t ricu_afe_ctl_29_vc_cml_6_i_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_29_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE void ricu_afe_ctl_29_vc_cml_6_i_setf(uint8_t vccml6i)
{
	ASSERT_ERR((((uint32_t)vccml6i << 24) & ~((uint32_t)0x07000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_29_ADDR, (REG_PL_RD(RICU_AFE_CTL_29_ADDR) & ~((uint32_t)0x07000000)) | ((uint32_t)vccml6i <<24));
}
__INLINE uint8_t ricu_afe_ctl_29_vc_cml_5_i_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_29_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00700000)) >> 20);
}
__INLINE void ricu_afe_ctl_29_vc_cml_5_i_setf(uint8_t vccml5i)
{
	ASSERT_ERR((((uint32_t)vccml5i << 20) & ~((uint32_t)0x00700000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_29_ADDR, (REG_PL_RD(RICU_AFE_CTL_29_ADDR) & ~((uint32_t)0x00700000)) | ((uint32_t)vccml5i <<20));
}
__INLINE uint8_t ricu_afe_ctl_29_vc_cml_4_i_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_29_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00070000)) >> 16);
}
__INLINE void ricu_afe_ctl_29_vc_cml_4_i_setf(uint8_t vccml4i)
{
	ASSERT_ERR((((uint32_t)vccml4i << 16) & ~((uint32_t)0x00070000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_29_ADDR, (REG_PL_RD(RICU_AFE_CTL_29_ADDR) & ~((uint32_t)0x00070000)) | ((uint32_t)vccml4i <<16));
}
__INLINE uint8_t ricu_afe_ctl_29_vc_cml_3_i_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_29_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007000)) >> 12);
}
__INLINE void ricu_afe_ctl_29_vc_cml_3_i_setf(uint8_t vccml3i)
{
	ASSERT_ERR((((uint32_t)vccml3i << 12) & ~((uint32_t)0x00007000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_29_ADDR, (REG_PL_RD(RICU_AFE_CTL_29_ADDR) & ~((uint32_t)0x00007000)) | ((uint32_t)vccml3i <<12));
}
__INLINE uint8_t ricu_afe_ctl_29_vc_cml_2_i_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_29_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000700)) >> 8);
}
__INLINE void ricu_afe_ctl_29_vc_cml_2_i_setf(uint8_t vccml2i)
{
	ASSERT_ERR((((uint32_t)vccml2i << 8) & ~((uint32_t)0x00000700)) == 0);
	REG_PL_WR(RICU_AFE_CTL_29_ADDR, (REG_PL_RD(RICU_AFE_CTL_29_ADDR) & ~((uint32_t)0x00000700)) | ((uint32_t)vccml2i <<8));
}
__INLINE uint8_t ricu_afe_ctl_29_vc_cml_1_i_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_29_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void ricu_afe_ctl_29_vc_cml_1_i_setf(uint8_t vccml1i)
{
	ASSERT_ERR((((uint32_t)vccml1i << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(RICU_AFE_CTL_29_ADDR, (REG_PL_RD(RICU_AFE_CTL_29_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)vccml1i <<4));
}
__INLINE uint8_t ricu_afe_ctl_29_vc_cml_0_i_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_29_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void ricu_afe_ctl_29_vc_cml_0_i_setf(uint8_t vccml0i)
{
	ASSERT_ERR((((uint32_t)vccml0i << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(RICU_AFE_CTL_29_ADDR, (REG_PL_RD(RICU_AFE_CTL_29_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)vccml0i <<0));
}

/**
 * @brief AFE_CTL_30 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    30:28 VC_CML7_Q                 0x5
 *    26:24 VC_CML6_Q                 0x5
 *    22:20 VC_CML5_Q                 0x5
 *    18:16 VC_CML4_Q                 0x5
 *    14:12 VC_CML3_Q                 0x5
 *    10:08 VC_CML2_Q                 0x5
 *    06:04 VC_CML1_Q                 0x5
 *    02:00 VC_CML0_Q                 0x5
 * </pre>
 */
#define RICU_AFE_CTL_30_ADDR        (REG_RICU_BASE_ADDR+0x00000088)
#define RICU_AFE_CTL_30_OFFSET      0x00000088
#define RICU_AFE_CTL_30_INDEX       0x00000022
#define RICU_AFE_CTL_30_RESET       0x55555555

__INLINE uint32_t  ricu_afe_ctl_30_get(void)
{
	return REG_PL_RD(RICU_AFE_CTL_30_ADDR);
}

__INLINE void ricu_afe_ctl_30_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTL_30_ADDR, value);
}

// field definitions
#define RICU_AFE_CTL_30_VC_CML_7_Q_MASK     ((uint32_t)0x70000000)
#define RICU_AFE_CTL_30_VC_CML_7_Q_LSB      28
#define RICU_AFE_CTL_30_VC_CML_7_Q_WIDTH    ((uint32_t)0x00000003)
#define RICU_AFE_CTL_30_VC_CML_6_Q_MASK     ((uint32_t)0x07000000)
#define RICU_AFE_CTL_30_VC_CML_6_Q_LSB      24
#define RICU_AFE_CTL_30_VC_CML_6_Q_WIDTH    ((uint32_t)0x00000003)
#define RICU_AFE_CTL_30_VC_CML_5_Q_MASK     ((uint32_t)0x00700000)
#define RICU_AFE_CTL_30_VC_CML_5_Q_LSB      20
#define RICU_AFE_CTL_30_VC_CML_5_Q_WIDTH    ((uint32_t)0x00000003)
#define RICU_AFE_CTL_30_VC_CML_4_Q_MASK     ((uint32_t)0x00070000)
#define RICU_AFE_CTL_30_VC_CML_4_Q_LSB      16
#define RICU_AFE_CTL_30_VC_CML_4_Q_WIDTH    ((uint32_t)0x00000003)
#define RICU_AFE_CTL_30_VC_CML_3_Q_MASK     ((uint32_t)0x00007000)
#define RICU_AFE_CTL_30_VC_CML_3_Q_LSB      12
#define RICU_AFE_CTL_30_VC_CML_3_Q_WIDTH    ((uint32_t)0x00000003)
#define RICU_AFE_CTL_30_VC_CML_2_Q_MASK     ((uint32_t)0x00000700)
#define RICU_AFE_CTL_30_VC_CML_2_Q_LSB      8
#define RICU_AFE_CTL_30_VC_CML_2_Q_WIDTH    ((uint32_t)0x00000003)
#define RICU_AFE_CTL_30_VC_CML_1_Q_MASK     ((uint32_t)0x00000070)
#define RICU_AFE_CTL_30_VC_CML_1_Q_LSB      4
#define RICU_AFE_CTL_30_VC_CML_1_Q_WIDTH    ((uint32_t)0x00000003)
#define RICU_AFE_CTL_30_VC_CML_0_Q_MASK     ((uint32_t)0x00000007)
#define RICU_AFE_CTL_30_VC_CML_0_Q_LSB      0
#define RICU_AFE_CTL_30_VC_CML_0_Q_WIDTH    ((uint32_t)0x00000003)

#define RICU_AFE_CTL_30_VC_CML_7_Q_RST      0x5
#define RICU_AFE_CTL_30_VC_CML_6_Q_RST      0x5
#define RICU_AFE_CTL_30_VC_CML_5_Q_RST      0x5
#define RICU_AFE_CTL_30_VC_CML_4_Q_RST      0x5
#define RICU_AFE_CTL_30_VC_CML_3_Q_RST      0x5
#define RICU_AFE_CTL_30_VC_CML_2_Q_RST      0x5
#define RICU_AFE_CTL_30_VC_CML_1_Q_RST      0x5
#define RICU_AFE_CTL_30_VC_CML_0_Q_RST      0x5

__INLINE void ricu_afe_ctl_30_pack(uint8_t vc_cml7_q, uint8_t vc_cml6_q, uint8_t vc_cml5_q, uint8_t vc_cml4_q, uint8_t vc_cml3_q, uint8_t vc_cml2_q, uint8_t vc_cml1_q, uint8_t vc_cml0_q)
{
	ASSERT_ERR((((uint32_t)vc_cml7_q << 28) & ~((uint32_t)0x70000000)) == 0);
	ASSERT_ERR((((uint32_t)vc_cml6_q << 24) & ~((uint32_t)0x07000000)) == 0);
	ASSERT_ERR((((uint32_t)vc_cml5_q << 20) & ~((uint32_t)0x00700000)) == 0);
	ASSERT_ERR((((uint32_t)vc_cml4_q << 16) & ~((uint32_t)0x00070000)) == 0);
	ASSERT_ERR((((uint32_t)vc_cml3_q << 12) & ~((uint32_t)0x00007000)) == 0);
	ASSERT_ERR((((uint32_t)vc_cml2_q << 8) & ~((uint32_t)0x00000700)) == 0);
	ASSERT_ERR((((uint32_t)vc_cml1_q << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)vc_cml0_q << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(RICU_AFE_CTL_30_ADDR,  ((uint32_t)vc_cml7_q << 28) |((uint32_t)vc_cml6_q << 24) |((uint32_t)vc_cml5_q << 20) |((uint32_t)vc_cml4_q << 16) |((uint32_t)vc_cml3_q << 12) |((uint32_t)vc_cml2_q << 8) |((uint32_t)vc_cml1_q << 4) |((uint32_t)vc_cml0_q << 0));
}

__INLINE void ricu_afe_ctl_30_unpack(uint8_t* vc_cml7_q, uint8_t* vc_cml6_q, uint8_t* vc_cml5_q, uint8_t* vc_cml4_q, uint8_t* vc_cml3_q, uint8_t* vc_cml2_q, uint8_t* vc_cml1_q, uint8_t* vc_cml0_q)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_30_ADDR);

	*vc_cml7_q = (localVal & ((uint32_t)0x70000000)) >>  28;
	*vc_cml6_q = (localVal & ((uint32_t)0x07000000)) >>  24;
	*vc_cml5_q = (localVal & ((uint32_t)0x00700000)) >>  20;
	*vc_cml4_q = (localVal & ((uint32_t)0x00070000)) >>  16;
	*vc_cml3_q = (localVal & ((uint32_t)0x00007000)) >>  12;
	*vc_cml2_q = (localVal & ((uint32_t)0x00000700)) >>  8;
	*vc_cml1_q = (localVal & ((uint32_t)0x00000070)) >>  4;
	*vc_cml0_q = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t ricu_afe_ctl_30_vc_cml_7_q_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_30_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x70000000)) >> 28);
}
__INLINE void ricu_afe_ctl_30_vc_cml_7_q_setf(uint8_t vccml7q)
{
	ASSERT_ERR((((uint32_t)vccml7q << 28) & ~((uint32_t)0x70000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_30_ADDR, (REG_PL_RD(RICU_AFE_CTL_30_ADDR) & ~((uint32_t)0x70000000)) | ((uint32_t)vccml7q <<28));
}
__INLINE uint8_t ricu_afe_ctl_30_vc_cml_6_q_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_30_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE void ricu_afe_ctl_30_vc_cml_6_q_setf(uint8_t vccml6q)
{
	ASSERT_ERR((((uint32_t)vccml6q << 24) & ~((uint32_t)0x07000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_30_ADDR, (REG_PL_RD(RICU_AFE_CTL_30_ADDR) & ~((uint32_t)0x07000000)) | ((uint32_t)vccml6q <<24));
}
__INLINE uint8_t ricu_afe_ctl_30_vc_cml_5_q_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_30_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00700000)) >> 20);
}
__INLINE void ricu_afe_ctl_30_vc_cml_5_q_setf(uint8_t vccml5q)
{
	ASSERT_ERR((((uint32_t)vccml5q << 20) & ~((uint32_t)0x00700000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_30_ADDR, (REG_PL_RD(RICU_AFE_CTL_30_ADDR) & ~((uint32_t)0x00700000)) | ((uint32_t)vccml5q <<20));
}
__INLINE uint8_t ricu_afe_ctl_30_vc_cml_4_q_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_30_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00070000)) >> 16);
}
__INLINE void ricu_afe_ctl_30_vc_cml_4_q_setf(uint8_t vccml4q)
{
	ASSERT_ERR((((uint32_t)vccml4q << 16) & ~((uint32_t)0x00070000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_30_ADDR, (REG_PL_RD(RICU_AFE_CTL_30_ADDR) & ~((uint32_t)0x00070000)) | ((uint32_t)vccml4q <<16));
}
__INLINE uint8_t ricu_afe_ctl_30_vc_cml_3_q_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_30_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007000)) >> 12);
}
__INLINE void ricu_afe_ctl_30_vc_cml_3_q_setf(uint8_t vccml3q)
{
	ASSERT_ERR((((uint32_t)vccml3q << 12) & ~((uint32_t)0x00007000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_30_ADDR, (REG_PL_RD(RICU_AFE_CTL_30_ADDR) & ~((uint32_t)0x00007000)) | ((uint32_t)vccml3q <<12));
}
__INLINE uint8_t ricu_afe_ctl_30_vc_cml_2_q_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_30_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000700)) >> 8);
}
__INLINE void ricu_afe_ctl_30_vc_cml_2_q_setf(uint8_t vccml2q)
{
	ASSERT_ERR((((uint32_t)vccml2q << 8) & ~((uint32_t)0x00000700)) == 0);
	REG_PL_WR(RICU_AFE_CTL_30_ADDR, (REG_PL_RD(RICU_AFE_CTL_30_ADDR) & ~((uint32_t)0x00000700)) | ((uint32_t)vccml2q <<8));
}
__INLINE uint8_t ricu_afe_ctl_30_vc_cml_1_q_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_30_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void ricu_afe_ctl_30_vc_cml_1_q_setf(uint8_t vccml1q)
{
	ASSERT_ERR((((uint32_t)vccml1q << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(RICU_AFE_CTL_30_ADDR, (REG_PL_RD(RICU_AFE_CTL_30_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)vccml1q <<4));
}
__INLINE uint8_t ricu_afe_ctl_30_vc_cml_0_q_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_30_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void ricu_afe_ctl_30_vc_cml_0_q_setf(uint8_t vccml0q)
{
	ASSERT_ERR((((uint32_t)vccml0q << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(RICU_AFE_CTL_30_ADDR, (REG_PL_RD(RICU_AFE_CTL_30_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)vccml0q <<0));
}

/**
 * @brief AFE_CTL_31 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    11:00 AFE_RESERVED              0x0
 * </pre>
 */
#define RICU_AFE_CTL_31_ADDR        (REG_RICU_BASE_ADDR+0x0000008C)
#define RICU_AFE_CTL_31_OFFSET      0x0000008C
#define RICU_AFE_CTL_31_INDEX       0x00000023
#define RICU_AFE_CTL_31_RESET       0x00000000

__INLINE uint32_t  ricu_afe_ctl_31_get(void)
{
	return REG_PL_RD(RICU_AFE_CTL_31_ADDR);
}

__INLINE void ricu_afe_ctl_31_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTL_31_ADDR, value);
}

// field definitions
#define RICU_AFE_CTL_31_AFE_RESERVED_MASK    ((uint32_t)0x00000FFF)
#define RICU_AFE_CTL_31_AFE_RESERVED_LSB    0
#define RICU_AFE_CTL_31_AFE_RESERVED_WIDTH    ((uint32_t)0x0000000C)

#define RICU_AFE_CTL_31_AFE_RESERVED_RST    0x0

__INLINE uint16_t ricu_afe_ctl_31_afe_reserved_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_31_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void ricu_afe_ctl_31_afe_reserved_setf(uint16_t afereserved)
{
	ASSERT_ERR((((uint32_t)afereserved << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(RICU_AFE_CTL_31_ADDR, (uint32_t)afereserved << 0);
}

/**
 * @brief AFE_CTL_32 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28:24 SIN2_IBIAS_CTRL7          0x10
 *    20:16 SIN2_IBIAS_CTRL6          0x10
 *    12:08 SIN2_IBIAS_CTRL5          0x10
 *    04:00 SIN2_IBIAS_CTRL4          0x10
 * </pre>
 */
#define RICU_AFE_CTL_32_ADDR        (REG_RICU_BASE_ADDR+0x00000090)
#define RICU_AFE_CTL_32_OFFSET      0x00000090
#define RICU_AFE_CTL_32_INDEX       0x00000024
#define RICU_AFE_CTL_32_RESET       0x10101010

__INLINE uint32_t  ricu_afe_ctl_32_get(void)
{
	return REG_PL_RD(RICU_AFE_CTL_32_ADDR);
}

__INLINE void ricu_afe_ctl_32_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTL_32_ADDR, value);
}

// field definitions
#define RICU_AFE_CTL_32_SIN_2_IBIAS_CTRL_7_MASK    ((uint32_t)0x1F000000)
#define RICU_AFE_CTL_32_SIN_2_IBIAS_CTRL_7_LSB    24
#define RICU_AFE_CTL_32_SIN_2_IBIAS_CTRL_7_WIDTH    ((uint32_t)0x00000005)
#define RICU_AFE_CTL_32_SIN_2_IBIAS_CTRL_6_MASK    ((uint32_t)0x001F0000)
#define RICU_AFE_CTL_32_SIN_2_IBIAS_CTRL_6_LSB    16
#define RICU_AFE_CTL_32_SIN_2_IBIAS_CTRL_6_WIDTH    ((uint32_t)0x00000005)
#define RICU_AFE_CTL_32_SIN_2_IBIAS_CTRL_5_MASK    ((uint32_t)0x00001F00)
#define RICU_AFE_CTL_32_SIN_2_IBIAS_CTRL_5_LSB    8
#define RICU_AFE_CTL_32_SIN_2_IBIAS_CTRL_5_WIDTH    ((uint32_t)0x00000005)
#define RICU_AFE_CTL_32_SIN_2_IBIAS_CTRL_4_MASK    ((uint32_t)0x0000001F)
#define RICU_AFE_CTL_32_SIN_2_IBIAS_CTRL_4_LSB    0
#define RICU_AFE_CTL_32_SIN_2_IBIAS_CTRL_4_WIDTH    ((uint32_t)0x00000005)

#define RICU_AFE_CTL_32_SIN_2_IBIAS_CTRL_7_RST    0x10
#define RICU_AFE_CTL_32_SIN_2_IBIAS_CTRL_6_RST    0x10
#define RICU_AFE_CTL_32_SIN_2_IBIAS_CTRL_5_RST    0x10
#define RICU_AFE_CTL_32_SIN_2_IBIAS_CTRL_4_RST    0x10

__INLINE void ricu_afe_ctl_32_pack(uint8_t sin2_ibias_ctrl7, uint8_t sin2_ibias_ctrl6, uint8_t sin2_ibias_ctrl5, uint8_t sin2_ibias_ctrl4)
{
	ASSERT_ERR((((uint32_t)sin2_ibias_ctrl7 << 24) & ~((uint32_t)0x1F000000)) == 0);
	ASSERT_ERR((((uint32_t)sin2_ibias_ctrl6 << 16) & ~((uint32_t)0x001F0000)) == 0);
	ASSERT_ERR((((uint32_t)sin2_ibias_ctrl5 << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)sin2_ibias_ctrl4 << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RICU_AFE_CTL_32_ADDR,  ((uint32_t)sin2_ibias_ctrl7 << 24) |((uint32_t)sin2_ibias_ctrl6 << 16) |((uint32_t)sin2_ibias_ctrl5 << 8) |((uint32_t)sin2_ibias_ctrl4 << 0));
}

__INLINE void ricu_afe_ctl_32_unpack(uint8_t* sin2_ibias_ctrl7, uint8_t* sin2_ibias_ctrl6, uint8_t* sin2_ibias_ctrl5, uint8_t* sin2_ibias_ctrl4)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_32_ADDR);

	*sin2_ibias_ctrl7 = (localVal & ((uint32_t)0x1F000000)) >>  24;
	*sin2_ibias_ctrl6 = (localVal & ((uint32_t)0x001F0000)) >>  16;
	*sin2_ibias_ctrl5 = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*sin2_ibias_ctrl4 = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t ricu_afe_ctl_32_sin_2_ibias_ctrl_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_32_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x1F000000)) >> 24);
}
__INLINE void ricu_afe_ctl_32_sin_2_ibias_ctrl_7_setf(uint8_t sin2ibiasctrl7)
{
	ASSERT_ERR((((uint32_t)sin2ibiasctrl7 << 24) & ~((uint32_t)0x1F000000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_32_ADDR, (REG_PL_RD(RICU_AFE_CTL_32_ADDR) & ~((uint32_t)0x1F000000)) | ((uint32_t)sin2ibiasctrl7 <<24));
}
__INLINE uint8_t ricu_afe_ctl_32_sin_2_ibias_ctrl_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_32_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001F0000)) >> 16);
}
__INLINE void ricu_afe_ctl_32_sin_2_ibias_ctrl_6_setf(uint8_t sin2ibiasctrl6)
{
	ASSERT_ERR((((uint32_t)sin2ibiasctrl6 << 16) & ~((uint32_t)0x001F0000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_32_ADDR, (REG_PL_RD(RICU_AFE_CTL_32_ADDR) & ~((uint32_t)0x001F0000)) | ((uint32_t)sin2ibiasctrl6 <<16));
}
__INLINE uint8_t ricu_afe_ctl_32_sin_2_ibias_ctrl_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_32_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void ricu_afe_ctl_32_sin_2_ibias_ctrl_5_setf(uint8_t sin2ibiasctrl5)
{
	ASSERT_ERR((((uint32_t)sin2ibiasctrl5 << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(RICU_AFE_CTL_32_ADDR, (REG_PL_RD(RICU_AFE_CTL_32_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)sin2ibiasctrl5 <<8));
}
__INLINE uint8_t ricu_afe_ctl_32_sin_2_ibias_ctrl_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_32_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void ricu_afe_ctl_32_sin_2_ibias_ctrl_4_setf(uint8_t sin2ibiasctrl4)
{
	ASSERT_ERR((((uint32_t)sin2ibiasctrl4 << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RICU_AFE_CTL_32_ADDR, (REG_PL_RD(RICU_AFE_CTL_32_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)sin2ibiasctrl4 <<0));
}

/**
 * @brief AFE_CTL_33 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    ROSEL3                    0              
 *    14:08 RO_CTRL3_Q                0x7
 *    06:00 RO_CTRL3_I                0x7
 * </pre>
 */
#define RICU_AFE_CTL_33_ADDR        (REG_RICU_BASE_ADDR+0x00000094)
#define RICU_AFE_CTL_33_OFFSET      0x00000094
#define RICU_AFE_CTL_33_INDEX       0x00000025
#define RICU_AFE_CTL_33_RESET       0x00000707

__INLINE uint32_t  ricu_afe_ctl_33_get(void)
{
	return REG_PL_RD(RICU_AFE_CTL_33_ADDR);
}

__INLINE void ricu_afe_ctl_33_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTL_33_ADDR, value);
}

// field definitions
#define RICU_AFE_CTL_33_ROSEL_3_BIT         ((uint32_t)0x00010000)
#define RICU_AFE_CTL_33_ROSEL_3_POS         16
#define RICU_AFE_CTL_33_RO_CTRL_3_Q_MASK    ((uint32_t)0x00007F00)
#define RICU_AFE_CTL_33_RO_CTRL_3_Q_LSB     8
#define RICU_AFE_CTL_33_RO_CTRL_3_Q_WIDTH    ((uint32_t)0x00000007)
#define RICU_AFE_CTL_33_RO_CTRL_3_I_MASK    ((uint32_t)0x0000007F)
#define RICU_AFE_CTL_33_RO_CTRL_3_I_LSB     0
#define RICU_AFE_CTL_33_RO_CTRL_3_I_WIDTH    ((uint32_t)0x00000007)

#define RICU_AFE_CTL_33_ROSEL_3_RST         0x0
#define RICU_AFE_CTL_33_RO_CTRL_3_Q_RST     0x7
#define RICU_AFE_CTL_33_RO_CTRL_3_I_RST     0x7

__INLINE void ricu_afe_ctl_33_pack(uint8_t rosel3, uint8_t ro_ctrl3_q, uint8_t ro_ctrl3_i)
{
	ASSERT_ERR((((uint32_t)rosel3 << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)ro_ctrl3_q << 8) & ~((uint32_t)0x00007F00)) == 0);
	ASSERT_ERR((((uint32_t)ro_ctrl3_i << 0) & ~((uint32_t)0x0000007F)) == 0);
	REG_PL_WR(RICU_AFE_CTL_33_ADDR,  ((uint32_t)rosel3 << 16) |((uint32_t)ro_ctrl3_q << 8) |((uint32_t)ro_ctrl3_i << 0));
}

__INLINE void ricu_afe_ctl_33_unpack(uint8_t* rosel3, uint8_t* ro_ctrl3_q, uint8_t* ro_ctrl3_i)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_33_ADDR);

	*rosel3 = (localVal & ((uint32_t)0x00010000)) >>  16;
	*ro_ctrl3_q = (localVal & ((uint32_t)0x00007F00)) >>  8;
	*ro_ctrl3_i = (localVal & ((uint32_t)0x0000007F)) >>  0;
}

__INLINE uint8_t ricu_afe_ctl_33_rosel_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_33_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void ricu_afe_ctl_33_rosel_3_setf(uint8_t rosel3)
{
	ASSERT_ERR((((uint32_t)rosel3 << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RICU_AFE_CTL_33_ADDR, (REG_PL_RD(RICU_AFE_CTL_33_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)rosel3 <<16));
}
__INLINE uint8_t ricu_afe_ctl_33_ro_ctrl_3_q_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_33_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007F00)) >> 8);
}
__INLINE void ricu_afe_ctl_33_ro_ctrl_3_q_setf(uint8_t roctrl3q)
{
	ASSERT_ERR((((uint32_t)roctrl3q << 8) & ~((uint32_t)0x00007F00)) == 0);
	REG_PL_WR(RICU_AFE_CTL_33_ADDR, (REG_PL_RD(RICU_AFE_CTL_33_ADDR) & ~((uint32_t)0x00007F00)) | ((uint32_t)roctrl3q <<8));
}
__INLINE uint8_t ricu_afe_ctl_33_ro_ctrl_3_i_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_33_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000007F)) >> 0);
}
__INLINE void ricu_afe_ctl_33_ro_ctrl_3_i_setf(uint8_t roctrl3i)
{
	ASSERT_ERR((((uint32_t)roctrl3i << 0) & ~((uint32_t)0x0000007F)) == 0);
	REG_PL_WR(RICU_AFE_CTL_33_ADDR, (REG_PL_RD(RICU_AFE_CTL_33_ADDR) & ~((uint32_t)0x0000007F)) | ((uint32_t)roctrl3i <<0));
}

/**
 * @brief AFE_CTL_22_PHY_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    05    PHY1_EN_ADC5              0              
 *    04    PHY1_EN_ADC4              0              
 *    03    PHY1_EN_ADC3              0              
 *    02    PHY1_EN_ADC2              0              
 *    01    PHY1_EN_ADC1              0              
 *    00    PHY1_EN_ADC0              0              
 * </pre>
 */
#define RICU_AFE_CTL_22_PHY_1_ADDR        (REG_RICU_BASE_ADDR+0x00000098)
#define RICU_AFE_CTL_22_PHY_1_OFFSET      0x00000098
#define RICU_AFE_CTL_22_PHY_1_INDEX       0x00000026
#define RICU_AFE_CTL_22_PHY_1_RESET       0x00000000

__INLINE uint32_t  ricu_afe_ctl_22_phy_1_get(void)
{
	return REG_PL_RD(RICU_AFE_CTL_22_PHY_1_ADDR);
}

__INLINE void ricu_afe_ctl_22_phy_1_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTL_22_PHY_1_ADDR, value);
}

// field definitions
#define RICU_AFE_CTL_22_PHY_1_PHY_1_EN_ADC_5_BIT    ((uint32_t)0x00000020)
#define RICU_AFE_CTL_22_PHY_1_PHY_1_EN_ADC_5_POS    5
#define RICU_AFE_CTL_22_PHY_1_PHY_1_EN_ADC_4_BIT    ((uint32_t)0x00000010)
#define RICU_AFE_CTL_22_PHY_1_PHY_1_EN_ADC_4_POS    4
#define RICU_AFE_CTL_22_PHY_1_PHY_1_EN_ADC_3_BIT    ((uint32_t)0x00000008)
#define RICU_AFE_CTL_22_PHY_1_PHY_1_EN_ADC_3_POS    3
#define RICU_AFE_CTL_22_PHY_1_PHY_1_EN_ADC_2_BIT    ((uint32_t)0x00000004)
#define RICU_AFE_CTL_22_PHY_1_PHY_1_EN_ADC_2_POS    2
#define RICU_AFE_CTL_22_PHY_1_PHY_1_EN_ADC_1_BIT    ((uint32_t)0x00000002)
#define RICU_AFE_CTL_22_PHY_1_PHY_1_EN_ADC_1_POS    1
#define RICU_AFE_CTL_22_PHY_1_PHY_1_EN_ADC_0_BIT    ((uint32_t)0x00000001)
#define RICU_AFE_CTL_22_PHY_1_PHY_1_EN_ADC_0_POS    0

#define RICU_AFE_CTL_22_PHY_1_PHY_1_EN_ADC_5_RST    0x0
#define RICU_AFE_CTL_22_PHY_1_PHY_1_EN_ADC_4_RST    0x0
#define RICU_AFE_CTL_22_PHY_1_PHY_1_EN_ADC_3_RST    0x0
#define RICU_AFE_CTL_22_PHY_1_PHY_1_EN_ADC_2_RST    0x0
#define RICU_AFE_CTL_22_PHY_1_PHY_1_EN_ADC_1_RST    0x0
#define RICU_AFE_CTL_22_PHY_1_PHY_1_EN_ADC_0_RST    0x0

__INLINE void ricu_afe_ctl_22_phy_1_pack(uint8_t phy1_en_adc5, uint8_t phy1_en_adc4, uint8_t phy1_en_adc3, uint8_t phy1_en_adc2, uint8_t phy1_en_adc1, uint8_t phy1_en_adc0)
{
	ASSERT_ERR((((uint32_t)phy1_en_adc5 << 5) & ~((uint32_t)0x00000020)) == 0);
	ASSERT_ERR((((uint32_t)phy1_en_adc4 << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)phy1_en_adc3 << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)phy1_en_adc2 << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)phy1_en_adc1 << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)phy1_en_adc0 << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RICU_AFE_CTL_22_PHY_1_ADDR,  ((uint32_t)phy1_en_adc5 << 5) |((uint32_t)phy1_en_adc4 << 4) |((uint32_t)phy1_en_adc3 << 3) |((uint32_t)phy1_en_adc2 << 2) |((uint32_t)phy1_en_adc1 << 1) |((uint32_t)phy1_en_adc0 << 0));
}

__INLINE void ricu_afe_ctl_22_phy_1_unpack(uint8_t* phy1_en_adc5, uint8_t* phy1_en_adc4, uint8_t* phy1_en_adc3, uint8_t* phy1_en_adc2, uint8_t* phy1_en_adc1, uint8_t* phy1_en_adc0)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_22_PHY_1_ADDR);

	*phy1_en_adc5 = (localVal & ((uint32_t)0x00000020)) >>  5;
	*phy1_en_adc4 = (localVal & ((uint32_t)0x00000010)) >>  4;
	*phy1_en_adc3 = (localVal & ((uint32_t)0x00000008)) >>  3;
	*phy1_en_adc2 = (localVal & ((uint32_t)0x00000004)) >>  2;
	*phy1_en_adc1 = (localVal & ((uint32_t)0x00000002)) >>  1;
	*phy1_en_adc0 = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t ricu_afe_ctl_22_phy_1_phy_1_en_adc_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_22_PHY_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE void ricu_afe_ctl_22_phy_1_phy_1_en_adc_5_setf(uint8_t phy1enadc5)
{
	ASSERT_ERR((((uint32_t)phy1enadc5 << 5) & ~((uint32_t)0x00000020)) == 0);
	REG_PL_WR(RICU_AFE_CTL_22_PHY_1_ADDR, (REG_PL_RD(RICU_AFE_CTL_22_PHY_1_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)phy1enadc5 <<5));
}
__INLINE uint8_t ricu_afe_ctl_22_phy_1_phy_1_en_adc_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_22_PHY_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void ricu_afe_ctl_22_phy_1_phy_1_en_adc_4_setf(uint8_t phy1enadc4)
{
	ASSERT_ERR((((uint32_t)phy1enadc4 << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(RICU_AFE_CTL_22_PHY_1_ADDR, (REG_PL_RD(RICU_AFE_CTL_22_PHY_1_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)phy1enadc4 <<4));
}
__INLINE uint8_t ricu_afe_ctl_22_phy_1_phy_1_en_adc_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_22_PHY_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void ricu_afe_ctl_22_phy_1_phy_1_en_adc_3_setf(uint8_t phy1enadc3)
{
	ASSERT_ERR((((uint32_t)phy1enadc3 << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(RICU_AFE_CTL_22_PHY_1_ADDR, (REG_PL_RD(RICU_AFE_CTL_22_PHY_1_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)phy1enadc3 <<3));
}
__INLINE uint8_t ricu_afe_ctl_22_phy_1_phy_1_en_adc_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_22_PHY_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void ricu_afe_ctl_22_phy_1_phy_1_en_adc_2_setf(uint8_t phy1enadc2)
{
	ASSERT_ERR((((uint32_t)phy1enadc2 << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(RICU_AFE_CTL_22_PHY_1_ADDR, (REG_PL_RD(RICU_AFE_CTL_22_PHY_1_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)phy1enadc2 <<2));
}
__INLINE uint8_t ricu_afe_ctl_22_phy_1_phy_1_en_adc_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_22_PHY_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void ricu_afe_ctl_22_phy_1_phy_1_en_adc_1_setf(uint8_t phy1enadc1)
{
	ASSERT_ERR((((uint32_t)phy1enadc1 << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(RICU_AFE_CTL_22_PHY_1_ADDR, (REG_PL_RD(RICU_AFE_CTL_22_PHY_1_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)phy1enadc1 <<1));
}
__INLINE uint8_t ricu_afe_ctl_22_phy_1_phy_1_en_adc_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTL_22_PHY_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void ricu_afe_ctl_22_phy_1_phy_1_en_adc_0_setf(uint8_t phy1enadc0)
{
	ASSERT_ERR((((uint32_t)phy1enadc0 << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RICU_AFE_CTL_22_PHY_1_ADDR, (REG_PL_RD(RICU_AFE_CTL_22_PHY_1_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)phy1enadc0 <<0));
}

/**
 * @brief AFE_CTRL_34_PHY_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    06    PHY0_ADC_SB_IGNORE_FIFO_INDICATION 0              
 *    05:02 PHY0_ADC_SB_RD_DELAY      0x4
 *    01:00 PHY0_ADC_SB_MODE          0x0
 * </pre>
 */
#define RICU_AFE_CTRL_34_PHY_0_ADDR        (REG_RICU_BASE_ADDR+0x0000009C)
#define RICU_AFE_CTRL_34_PHY_0_OFFSET      0x0000009C
#define RICU_AFE_CTRL_34_PHY_0_INDEX       0x00000027
#define RICU_AFE_CTRL_34_PHY_0_RESET       0x00000010

__INLINE uint32_t  ricu_afe_ctrl_34_phy_0_get(void)
{
	return REG_PL_RD(RICU_AFE_CTRL_34_PHY_0_ADDR);
}

__INLINE void ricu_afe_ctrl_34_phy_0_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTRL_34_PHY_0_ADDR, value);
}

// field definitions
#define RICU_AFE_CTRL_34_PHY_0_PHY_0_ADC_SB_IGNORE_FIFO_INDICATION_BIT    ((uint32_t)0x00000040)
#define RICU_AFE_CTRL_34_PHY_0_PHY_0_ADC_SB_IGNORE_FIFO_INDICATION_POS    6
#define RICU_AFE_CTRL_34_PHY_0_PHY_0_ADC_SB_RD_DELAY_MASK    ((uint32_t)0x0000003C)
#define RICU_AFE_CTRL_34_PHY_0_PHY_0_ADC_SB_RD_DELAY_LSB    2
#define RICU_AFE_CTRL_34_PHY_0_PHY_0_ADC_SB_RD_DELAY_WIDTH    ((uint32_t)0x00000004)
#define RICU_AFE_CTRL_34_PHY_0_PHY_0_ADC_SB_MODE_MASK    ((uint32_t)0x00000003)
#define RICU_AFE_CTRL_34_PHY_0_PHY_0_ADC_SB_MODE_LSB    0
#define RICU_AFE_CTRL_34_PHY_0_PHY_0_ADC_SB_MODE_WIDTH    ((uint32_t)0x00000002)

#define RICU_AFE_CTRL_34_PHY_0_PHY_0_ADC_SB_IGNORE_FIFO_INDICATION_RST    0x0
#define RICU_AFE_CTRL_34_PHY_0_PHY_0_ADC_SB_RD_DELAY_RST    0x4
#define RICU_AFE_CTRL_34_PHY_0_PHY_0_ADC_SB_MODE_RST    0x0

__INLINE void ricu_afe_ctrl_34_phy_0_pack(uint8_t phy0_adc_sb_ignore_fifo_indication, uint8_t phy0_adc_sb_rd_delay, uint8_t phy0_adc_sb_mode)
{
	ASSERT_ERR((((uint32_t)phy0_adc_sb_ignore_fifo_indication << 6) & ~((uint32_t)0x00000040)) == 0);
	ASSERT_ERR((((uint32_t)phy0_adc_sb_rd_delay << 2) & ~((uint32_t)0x0000003C)) == 0);
	ASSERT_ERR((((uint32_t)phy0_adc_sb_mode << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_34_PHY_0_ADDR,  ((uint32_t)phy0_adc_sb_ignore_fifo_indication << 6) |((uint32_t)phy0_adc_sb_rd_delay << 2) |((uint32_t)phy0_adc_sb_mode << 0));
}

__INLINE void ricu_afe_ctrl_34_phy_0_unpack(uint8_t* phy0_adc_sb_ignore_fifo_indication, uint8_t* phy0_adc_sb_rd_delay, uint8_t* phy0_adc_sb_mode)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_34_PHY_0_ADDR);

	*phy0_adc_sb_ignore_fifo_indication = (localVal & ((uint32_t)0x00000040)) >>  6;
	*phy0_adc_sb_rd_delay = (localVal & ((uint32_t)0x0000003C)) >>  2;
	*phy0_adc_sb_mode = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint8_t ricu_afe_ctrl_34_phy_0_phy_0_adc_sb_ignore_fifo_indication_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_34_PHY_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE void ricu_afe_ctrl_34_phy_0_phy_0_adc_sb_ignore_fifo_indication_setf(uint8_t phy0adcsbignorefifoindication)
{
	ASSERT_ERR((((uint32_t)phy0adcsbignorefifoindication << 6) & ~((uint32_t)0x00000040)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_34_PHY_0_ADDR, (REG_PL_RD(RICU_AFE_CTRL_34_PHY_0_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)phy0adcsbignorefifoindication <<6));
}
__INLINE uint8_t ricu_afe_ctrl_34_phy_0_phy_0_adc_sb_rd_delay_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_34_PHY_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000003C)) >> 2);
}
__INLINE void ricu_afe_ctrl_34_phy_0_phy_0_adc_sb_rd_delay_setf(uint8_t phy0adcsbrddelay)
{
	ASSERT_ERR((((uint32_t)phy0adcsbrddelay << 2) & ~((uint32_t)0x0000003C)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_34_PHY_0_ADDR, (REG_PL_RD(RICU_AFE_CTRL_34_PHY_0_ADDR) & ~((uint32_t)0x0000003C)) | ((uint32_t)phy0adcsbrddelay <<2));
}
__INLINE uint8_t ricu_afe_ctrl_34_phy_0_phy_0_adc_sb_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_34_PHY_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void ricu_afe_ctrl_34_phy_0_phy_0_adc_sb_mode_setf(uint8_t phy0adcsbmode)
{
	ASSERT_ERR((((uint32_t)phy0adcsbmode << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_34_PHY_0_ADDR, (REG_PL_RD(RICU_AFE_CTRL_34_PHY_0_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)phy0adcsbmode <<0));
}

/**
 * @brief AFE_CTRL_36_PHY_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    07    PHY0_ADC_ALWAYS_EN_LD_IR  0              
 *    06    PHY0_ADC_ALWAYS_EN_LD_AVDQ 0              
 *    05    PHY0_ADC_ALWAYS_EN_LD_AVDI 0              
 *    04    PHY0_ADC_ALWAYS_EN_ADCQ   0              
 *    03    PHY0_ADC_ALWAYS_EN_ADCI   0              
 *    01    PHY0_HW_MODE_DAC          0              
 *    00    PHY0_HW_MODE_ADC          0              
 * </pre>
 */
#define RICU_AFE_CTRL_36_PHY_0_ADDR        (REG_RICU_BASE_ADDR+0x000000A0)
#define RICU_AFE_CTRL_36_PHY_0_OFFSET      0x000000A0
#define RICU_AFE_CTRL_36_PHY_0_INDEX       0x00000028
#define RICU_AFE_CTRL_36_PHY_0_RESET       0x00000000

__INLINE uint32_t  ricu_afe_ctrl_36_phy_0_get(void)
{
	return REG_PL_RD(RICU_AFE_CTRL_36_PHY_0_ADDR);
}

__INLINE void ricu_afe_ctrl_36_phy_0_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTRL_36_PHY_0_ADDR, value);
}

// field definitions
#define RICU_AFE_CTRL_36_PHY_0_PHY_0_ADC_ALWAYS_EN_LD_IR_BIT    ((uint32_t)0x00000080)
#define RICU_AFE_CTRL_36_PHY_0_PHY_0_ADC_ALWAYS_EN_LD_IR_POS    7
#define RICU_AFE_CTRL_36_PHY_0_PHY_0_ADC_ALWAYS_EN_LD_AVDQ_BIT    ((uint32_t)0x00000040)
#define RICU_AFE_CTRL_36_PHY_0_PHY_0_ADC_ALWAYS_EN_LD_AVDQ_POS    6
#define RICU_AFE_CTRL_36_PHY_0_PHY_0_ADC_ALWAYS_EN_LD_AVDI_BIT    ((uint32_t)0x00000020)
#define RICU_AFE_CTRL_36_PHY_0_PHY_0_ADC_ALWAYS_EN_LD_AVDI_POS    5
#define RICU_AFE_CTRL_36_PHY_0_PHY_0_ADC_ALWAYS_EN_ADCQ_BIT    ((uint32_t)0x00000010)
#define RICU_AFE_CTRL_36_PHY_0_PHY_0_ADC_ALWAYS_EN_ADCQ_POS    4
#define RICU_AFE_CTRL_36_PHY_0_PHY_0_ADC_ALWAYS_EN_ADCI_BIT    ((uint32_t)0x00000008)
#define RICU_AFE_CTRL_36_PHY_0_PHY_0_ADC_ALWAYS_EN_ADCI_POS    3
#define RICU_AFE_CTRL_36_PHY_0_PHY_0_HW_MODE_DAC_BIT    ((uint32_t)0x00000002)
#define RICU_AFE_CTRL_36_PHY_0_PHY_0_HW_MODE_DAC_POS    1
#define RICU_AFE_CTRL_36_PHY_0_PHY_0_HW_MODE_ADC_BIT    ((uint32_t)0x00000001)
#define RICU_AFE_CTRL_36_PHY_0_PHY_0_HW_MODE_ADC_POS    0

#define RICU_AFE_CTRL_36_PHY_0_PHY_0_ADC_ALWAYS_EN_LD_IR_RST    0x0
#define RICU_AFE_CTRL_36_PHY_0_PHY_0_ADC_ALWAYS_EN_LD_AVDQ_RST    0x0
#define RICU_AFE_CTRL_36_PHY_0_PHY_0_ADC_ALWAYS_EN_LD_AVDI_RST    0x0
#define RICU_AFE_CTRL_36_PHY_0_PHY_0_ADC_ALWAYS_EN_ADCQ_RST    0x0
#define RICU_AFE_CTRL_36_PHY_0_PHY_0_ADC_ALWAYS_EN_ADCI_RST    0x0
#define RICU_AFE_CTRL_36_PHY_0_PHY_0_HW_MODE_DAC_RST    0x0
#define RICU_AFE_CTRL_36_PHY_0_PHY_0_HW_MODE_ADC_RST    0x0

__INLINE void ricu_afe_ctrl_36_phy_0_pack(uint8_t phy0_adc_always_en_ld_ir, uint8_t phy0_adc_always_en_ld_avdq, uint8_t phy0_adc_always_en_ld_avdi, uint8_t phy0_adc_always_en_adcq, uint8_t phy0_adc_always_en_adci, uint8_t phy0_hw_mode_dac, uint8_t phy0_hw_mode_adc)
{
	ASSERT_ERR((((uint32_t)phy0_adc_always_en_ld_ir << 7) & ~((uint32_t)0x00000080)) == 0);
	ASSERT_ERR((((uint32_t)phy0_adc_always_en_ld_avdq << 6) & ~((uint32_t)0x00000040)) == 0);
	ASSERT_ERR((((uint32_t)phy0_adc_always_en_ld_avdi << 5) & ~((uint32_t)0x00000020)) == 0);
	ASSERT_ERR((((uint32_t)phy0_adc_always_en_adcq << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)phy0_adc_always_en_adci << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)phy0_hw_mode_dac << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)phy0_hw_mode_adc << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_36_PHY_0_ADDR,  ((uint32_t)phy0_adc_always_en_ld_ir << 7) |((uint32_t)phy0_adc_always_en_ld_avdq << 6) |((uint32_t)phy0_adc_always_en_ld_avdi << 5) |((uint32_t)phy0_adc_always_en_adcq << 4) |((uint32_t)phy0_adc_always_en_adci << 3) |((uint32_t)phy0_hw_mode_dac << 1) |((uint32_t)phy0_hw_mode_adc << 0));
}

__INLINE void ricu_afe_ctrl_36_phy_0_unpack(uint8_t* phy0_adc_always_en_ld_ir, uint8_t* phy0_adc_always_en_ld_avdq, uint8_t* phy0_adc_always_en_ld_avdi, uint8_t* phy0_adc_always_en_adcq, uint8_t* phy0_adc_always_en_adci, uint8_t* phy0_hw_mode_dac, uint8_t* phy0_hw_mode_adc)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_36_PHY_0_ADDR);

	*phy0_adc_always_en_ld_ir = (localVal & ((uint32_t)0x00000080)) >>  7;
	*phy0_adc_always_en_ld_avdq = (localVal & ((uint32_t)0x00000040)) >>  6;
	*phy0_adc_always_en_ld_avdi = (localVal & ((uint32_t)0x00000020)) >>  5;
	*phy0_adc_always_en_adcq = (localVal & ((uint32_t)0x00000010)) >>  4;
	*phy0_adc_always_en_adci = (localVal & ((uint32_t)0x00000008)) >>  3;
	*phy0_hw_mode_dac = (localVal & ((uint32_t)0x00000002)) >>  1;
	*phy0_hw_mode_adc = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t ricu_afe_ctrl_36_phy_0_phy_0_adc_always_en_ld_ir_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_36_PHY_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE void ricu_afe_ctrl_36_phy_0_phy_0_adc_always_en_ld_ir_setf(uint8_t phy0adcalwaysenldir)
{
	ASSERT_ERR((((uint32_t)phy0adcalwaysenldir << 7) & ~((uint32_t)0x00000080)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_36_PHY_0_ADDR, (REG_PL_RD(RICU_AFE_CTRL_36_PHY_0_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)phy0adcalwaysenldir <<7));
}
__INLINE uint8_t ricu_afe_ctrl_36_phy_0_phy_0_adc_always_en_ld_avdq_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_36_PHY_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE void ricu_afe_ctrl_36_phy_0_phy_0_adc_always_en_ld_avdq_setf(uint8_t phy0adcalwaysenldavdq)
{
	ASSERT_ERR((((uint32_t)phy0adcalwaysenldavdq << 6) & ~((uint32_t)0x00000040)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_36_PHY_0_ADDR, (REG_PL_RD(RICU_AFE_CTRL_36_PHY_0_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)phy0adcalwaysenldavdq <<6));
}
__INLINE uint8_t ricu_afe_ctrl_36_phy_0_phy_0_adc_always_en_ld_avdi_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_36_PHY_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE void ricu_afe_ctrl_36_phy_0_phy_0_adc_always_en_ld_avdi_setf(uint8_t phy0adcalwaysenldavdi)
{
	ASSERT_ERR((((uint32_t)phy0adcalwaysenldavdi << 5) & ~((uint32_t)0x00000020)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_36_PHY_0_ADDR, (REG_PL_RD(RICU_AFE_CTRL_36_PHY_0_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)phy0adcalwaysenldavdi <<5));
}
__INLINE uint8_t ricu_afe_ctrl_36_phy_0_phy_0_adc_always_en_adcq_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_36_PHY_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void ricu_afe_ctrl_36_phy_0_phy_0_adc_always_en_adcq_setf(uint8_t phy0adcalwaysenadcq)
{
	ASSERT_ERR((((uint32_t)phy0adcalwaysenadcq << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_36_PHY_0_ADDR, (REG_PL_RD(RICU_AFE_CTRL_36_PHY_0_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)phy0adcalwaysenadcq <<4));
}
__INLINE uint8_t ricu_afe_ctrl_36_phy_0_phy_0_adc_always_en_adci_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_36_PHY_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void ricu_afe_ctrl_36_phy_0_phy_0_adc_always_en_adci_setf(uint8_t phy0adcalwaysenadci)
{
	ASSERT_ERR((((uint32_t)phy0adcalwaysenadci << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_36_PHY_0_ADDR, (REG_PL_RD(RICU_AFE_CTRL_36_PHY_0_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)phy0adcalwaysenadci <<3));
}
__INLINE uint8_t ricu_afe_ctrl_36_phy_0_phy_0_hw_mode_dac_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_36_PHY_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void ricu_afe_ctrl_36_phy_0_phy_0_hw_mode_dac_setf(uint8_t phy0hwmodedac)
{
	ASSERT_ERR((((uint32_t)phy0hwmodedac << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_36_PHY_0_ADDR, (REG_PL_RD(RICU_AFE_CTRL_36_PHY_0_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)phy0hwmodedac <<1));
}
__INLINE uint8_t ricu_afe_ctrl_36_phy_0_phy_0_hw_mode_adc_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_36_PHY_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void ricu_afe_ctrl_36_phy_0_phy_0_hw_mode_adc_setf(uint8_t phy0hwmodeadc)
{
	ASSERT_ERR((((uint32_t)phy0hwmodeadc << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_36_PHY_0_ADDR, (REG_PL_RD(RICU_AFE_CTRL_36_PHY_0_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)phy0hwmodeadc <<0));
}

/**
 * @brief AFE_CTRL_34_PHY_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    06    PHY1_ADC_SB_IGNORE_FIFO_INDICATION 0              
 *    05:02 PHY1_ADC_SB_RD_DELAY      0x4
 *    01:00 PHY1_ADC_SB_MODE          0x0
 * </pre>
 */
#define RICU_AFE_CTRL_34_PHY_1_ADDR        (REG_RICU_BASE_ADDR+0x000000A4)
#define RICU_AFE_CTRL_34_PHY_1_OFFSET      0x000000A4
#define RICU_AFE_CTRL_34_PHY_1_INDEX       0x00000029
#define RICU_AFE_CTRL_34_PHY_1_RESET       0x00000010

__INLINE uint32_t  ricu_afe_ctrl_34_phy_1_get(void)
{
	return REG_PL_RD(RICU_AFE_CTRL_34_PHY_1_ADDR);
}

__INLINE void ricu_afe_ctrl_34_phy_1_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTRL_34_PHY_1_ADDR, value);
}

// field definitions
#define RICU_AFE_CTRL_34_PHY_1_PHY_1_ADC_SB_IGNORE_FIFO_INDICATION_BIT    ((uint32_t)0x00000040)
#define RICU_AFE_CTRL_34_PHY_1_PHY_1_ADC_SB_IGNORE_FIFO_INDICATION_POS    6
#define RICU_AFE_CTRL_34_PHY_1_PHY_1_ADC_SB_RD_DELAY_MASK    ((uint32_t)0x0000003C)
#define RICU_AFE_CTRL_34_PHY_1_PHY_1_ADC_SB_RD_DELAY_LSB    2
#define RICU_AFE_CTRL_34_PHY_1_PHY_1_ADC_SB_RD_DELAY_WIDTH    ((uint32_t)0x00000004)
#define RICU_AFE_CTRL_34_PHY_1_PHY_1_ADC_SB_MODE_MASK    ((uint32_t)0x00000003)
#define RICU_AFE_CTRL_34_PHY_1_PHY_1_ADC_SB_MODE_LSB    0
#define RICU_AFE_CTRL_34_PHY_1_PHY_1_ADC_SB_MODE_WIDTH    ((uint32_t)0x00000002)

#define RICU_AFE_CTRL_34_PHY_1_PHY_1_ADC_SB_IGNORE_FIFO_INDICATION_RST    0x0
#define RICU_AFE_CTRL_34_PHY_1_PHY_1_ADC_SB_RD_DELAY_RST    0x4
#define RICU_AFE_CTRL_34_PHY_1_PHY_1_ADC_SB_MODE_RST    0x0

__INLINE void ricu_afe_ctrl_34_phy_1_pack(uint8_t phy1_adc_sb_ignore_fifo_indication, uint8_t phy1_adc_sb_rd_delay, uint8_t phy1_adc_sb_mode)
{
	ASSERT_ERR((((uint32_t)phy1_adc_sb_ignore_fifo_indication << 6) & ~((uint32_t)0x00000040)) == 0);
	ASSERT_ERR((((uint32_t)phy1_adc_sb_rd_delay << 2) & ~((uint32_t)0x0000003C)) == 0);
	ASSERT_ERR((((uint32_t)phy1_adc_sb_mode << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_34_PHY_1_ADDR,  ((uint32_t)phy1_adc_sb_ignore_fifo_indication << 6) |((uint32_t)phy1_adc_sb_rd_delay << 2) |((uint32_t)phy1_adc_sb_mode << 0));
}

__INLINE void ricu_afe_ctrl_34_phy_1_unpack(uint8_t* phy1_adc_sb_ignore_fifo_indication, uint8_t* phy1_adc_sb_rd_delay, uint8_t* phy1_adc_sb_mode)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_34_PHY_1_ADDR);

	*phy1_adc_sb_ignore_fifo_indication = (localVal & ((uint32_t)0x00000040)) >>  6;
	*phy1_adc_sb_rd_delay = (localVal & ((uint32_t)0x0000003C)) >>  2;
	*phy1_adc_sb_mode = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint8_t ricu_afe_ctrl_34_phy_1_phy_1_adc_sb_ignore_fifo_indication_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_34_PHY_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE void ricu_afe_ctrl_34_phy_1_phy_1_adc_sb_ignore_fifo_indication_setf(uint8_t phy1adcsbignorefifoindication)
{
	ASSERT_ERR((((uint32_t)phy1adcsbignorefifoindication << 6) & ~((uint32_t)0x00000040)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_34_PHY_1_ADDR, (REG_PL_RD(RICU_AFE_CTRL_34_PHY_1_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)phy1adcsbignorefifoindication <<6));
}
__INLINE uint8_t ricu_afe_ctrl_34_phy_1_phy_1_adc_sb_rd_delay_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_34_PHY_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000003C)) >> 2);
}
__INLINE void ricu_afe_ctrl_34_phy_1_phy_1_adc_sb_rd_delay_setf(uint8_t phy1adcsbrddelay)
{
	ASSERT_ERR((((uint32_t)phy1adcsbrddelay << 2) & ~((uint32_t)0x0000003C)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_34_PHY_1_ADDR, (REG_PL_RD(RICU_AFE_CTRL_34_PHY_1_ADDR) & ~((uint32_t)0x0000003C)) | ((uint32_t)phy1adcsbrddelay <<2));
}
__INLINE uint8_t ricu_afe_ctrl_34_phy_1_phy_1_adc_sb_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_34_PHY_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void ricu_afe_ctrl_34_phy_1_phy_1_adc_sb_mode_setf(uint8_t phy1adcsbmode)
{
	ASSERT_ERR((((uint32_t)phy1adcsbmode << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_34_PHY_1_ADDR, (REG_PL_RD(RICU_AFE_CTRL_34_PHY_1_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)phy1adcsbmode <<0));
}

/**
 * @brief AFE_CTRL_35_PHY_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    06    PHY0_DAC_SB_IGNORE_FIFO_INDICATION 0              
 *    05:02 PHY0_DAC_SB_RD_DELAY      0x1
 *    01:00 PHY0_DAC_SB_MODE          0x0
 * </pre>
 */
#define RICU_AFE_CTRL_35_PHY_0_ADDR        (REG_RICU_BASE_ADDR+0x000000A8)
#define RICU_AFE_CTRL_35_PHY_0_OFFSET      0x000000A8
#define RICU_AFE_CTRL_35_PHY_0_INDEX       0x0000002A
#define RICU_AFE_CTRL_35_PHY_0_RESET       0x00000004

__INLINE uint32_t  ricu_afe_ctrl_35_phy_0_get(void)
{
	return REG_PL_RD(RICU_AFE_CTRL_35_PHY_0_ADDR);
}

__INLINE void ricu_afe_ctrl_35_phy_0_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTRL_35_PHY_0_ADDR, value);
}

// field definitions
#define RICU_AFE_CTRL_35_PHY_0_PHY_0_DAC_SB_IGNORE_FIFO_INDICATION_BIT    ((uint32_t)0x00000040)
#define RICU_AFE_CTRL_35_PHY_0_PHY_0_DAC_SB_IGNORE_FIFO_INDICATION_POS    6
#define RICU_AFE_CTRL_35_PHY_0_PHY_0_DAC_SB_RD_DELAY_MASK    ((uint32_t)0x0000003C)
#define RICU_AFE_CTRL_35_PHY_0_PHY_0_DAC_SB_RD_DELAY_LSB    2
#define RICU_AFE_CTRL_35_PHY_0_PHY_0_DAC_SB_RD_DELAY_WIDTH    ((uint32_t)0x00000004)
#define RICU_AFE_CTRL_35_PHY_0_PHY_0_DAC_SB_MODE_MASK    ((uint32_t)0x00000003)
#define RICU_AFE_CTRL_35_PHY_0_PHY_0_DAC_SB_MODE_LSB    0
#define RICU_AFE_CTRL_35_PHY_0_PHY_0_DAC_SB_MODE_WIDTH    ((uint32_t)0x00000002)

#define RICU_AFE_CTRL_35_PHY_0_PHY_0_DAC_SB_IGNORE_FIFO_INDICATION_RST    0x0
#define RICU_AFE_CTRL_35_PHY_0_PHY_0_DAC_SB_RD_DELAY_RST    0x1
#define RICU_AFE_CTRL_35_PHY_0_PHY_0_DAC_SB_MODE_RST    0x0

__INLINE void ricu_afe_ctrl_35_phy_0_pack(uint8_t phy0_dac_sb_ignore_fifo_indication, uint8_t phy0_dac_sb_rd_delay, uint8_t phy0_dac_sb_mode)
{
	ASSERT_ERR((((uint32_t)phy0_dac_sb_ignore_fifo_indication << 6) & ~((uint32_t)0x00000040)) == 0);
	ASSERT_ERR((((uint32_t)phy0_dac_sb_rd_delay << 2) & ~((uint32_t)0x0000003C)) == 0);
	ASSERT_ERR((((uint32_t)phy0_dac_sb_mode << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_35_PHY_0_ADDR,  ((uint32_t)phy0_dac_sb_ignore_fifo_indication << 6) |((uint32_t)phy0_dac_sb_rd_delay << 2) |((uint32_t)phy0_dac_sb_mode << 0));
}

__INLINE void ricu_afe_ctrl_35_phy_0_unpack(uint8_t* phy0_dac_sb_ignore_fifo_indication, uint8_t* phy0_dac_sb_rd_delay, uint8_t* phy0_dac_sb_mode)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_35_PHY_0_ADDR);

	*phy0_dac_sb_ignore_fifo_indication = (localVal & ((uint32_t)0x00000040)) >>  6;
	*phy0_dac_sb_rd_delay = (localVal & ((uint32_t)0x0000003C)) >>  2;
	*phy0_dac_sb_mode = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint8_t ricu_afe_ctrl_35_phy_0_phy_0_dac_sb_ignore_fifo_indication_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_35_PHY_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE void ricu_afe_ctrl_35_phy_0_phy_0_dac_sb_ignore_fifo_indication_setf(uint8_t phy0dacsbignorefifoindication)
{
	ASSERT_ERR((((uint32_t)phy0dacsbignorefifoindication << 6) & ~((uint32_t)0x00000040)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_35_PHY_0_ADDR, (REG_PL_RD(RICU_AFE_CTRL_35_PHY_0_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)phy0dacsbignorefifoindication <<6));
}
__INLINE uint8_t ricu_afe_ctrl_35_phy_0_phy_0_dac_sb_rd_delay_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_35_PHY_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000003C)) >> 2);
}
__INLINE void ricu_afe_ctrl_35_phy_0_phy_0_dac_sb_rd_delay_setf(uint8_t phy0dacsbrddelay)
{
	ASSERT_ERR((((uint32_t)phy0dacsbrddelay << 2) & ~((uint32_t)0x0000003C)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_35_PHY_0_ADDR, (REG_PL_RD(RICU_AFE_CTRL_35_PHY_0_ADDR) & ~((uint32_t)0x0000003C)) | ((uint32_t)phy0dacsbrddelay <<2));
}
__INLINE uint8_t ricu_afe_ctrl_35_phy_0_phy_0_dac_sb_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_35_PHY_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void ricu_afe_ctrl_35_phy_0_phy_0_dac_sb_mode_setf(uint8_t phy0dacsbmode)
{
	ASSERT_ERR((((uint32_t)phy0dacsbmode << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_35_PHY_0_ADDR, (REG_PL_RD(RICU_AFE_CTRL_35_PHY_0_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)phy0dacsbmode <<0));
}

/**
 * @brief AFE_CTRL_35_PHY_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    06    PHY1_DAC_SB_IGNORE_FIFO_INDICATION 0              
 *    05:02 PHY1_DAC_SB_RD_DELAY      0x1
 *    01:00 PHY1_DAC_SB_MODE          0x0
 * </pre>
 */
#define RICU_AFE_CTRL_35_PHY_1_ADDR        (REG_RICU_BASE_ADDR+0x000000AC)
#define RICU_AFE_CTRL_35_PHY_1_OFFSET      0x000000AC
#define RICU_AFE_CTRL_35_PHY_1_INDEX       0x0000002B
#define RICU_AFE_CTRL_35_PHY_1_RESET       0x00000004

__INLINE uint32_t  ricu_afe_ctrl_35_phy_1_get(void)
{
	return REG_PL_RD(RICU_AFE_CTRL_35_PHY_1_ADDR);
}

__INLINE void ricu_afe_ctrl_35_phy_1_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTRL_35_PHY_1_ADDR, value);
}

// field definitions
#define RICU_AFE_CTRL_35_PHY_1_PHY_1_DAC_SB_IGNORE_FIFO_INDICATION_BIT    ((uint32_t)0x00000040)
#define RICU_AFE_CTRL_35_PHY_1_PHY_1_DAC_SB_IGNORE_FIFO_INDICATION_POS    6
#define RICU_AFE_CTRL_35_PHY_1_PHY_1_DAC_SB_RD_DELAY_MASK    ((uint32_t)0x0000003C)
#define RICU_AFE_CTRL_35_PHY_1_PHY_1_DAC_SB_RD_DELAY_LSB    2
#define RICU_AFE_CTRL_35_PHY_1_PHY_1_DAC_SB_RD_DELAY_WIDTH    ((uint32_t)0x00000004)
#define RICU_AFE_CTRL_35_PHY_1_PHY_1_DAC_SB_MODE_MASK    ((uint32_t)0x00000003)
#define RICU_AFE_CTRL_35_PHY_1_PHY_1_DAC_SB_MODE_LSB    0
#define RICU_AFE_CTRL_35_PHY_1_PHY_1_DAC_SB_MODE_WIDTH    ((uint32_t)0x00000002)

#define RICU_AFE_CTRL_35_PHY_1_PHY_1_DAC_SB_IGNORE_FIFO_INDICATION_RST    0x0
#define RICU_AFE_CTRL_35_PHY_1_PHY_1_DAC_SB_RD_DELAY_RST    0x1
#define RICU_AFE_CTRL_35_PHY_1_PHY_1_DAC_SB_MODE_RST    0x0

__INLINE void ricu_afe_ctrl_35_phy_1_pack(uint8_t phy1_dac_sb_ignore_fifo_indication, uint8_t phy1_dac_sb_rd_delay, uint8_t phy1_dac_sb_mode)
{
	ASSERT_ERR((((uint32_t)phy1_dac_sb_ignore_fifo_indication << 6) & ~((uint32_t)0x00000040)) == 0);
	ASSERT_ERR((((uint32_t)phy1_dac_sb_rd_delay << 2) & ~((uint32_t)0x0000003C)) == 0);
	ASSERT_ERR((((uint32_t)phy1_dac_sb_mode << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_35_PHY_1_ADDR,  ((uint32_t)phy1_dac_sb_ignore_fifo_indication << 6) |((uint32_t)phy1_dac_sb_rd_delay << 2) |((uint32_t)phy1_dac_sb_mode << 0));
}

__INLINE void ricu_afe_ctrl_35_phy_1_unpack(uint8_t* phy1_dac_sb_ignore_fifo_indication, uint8_t* phy1_dac_sb_rd_delay, uint8_t* phy1_dac_sb_mode)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_35_PHY_1_ADDR);

	*phy1_dac_sb_ignore_fifo_indication = (localVal & ((uint32_t)0x00000040)) >>  6;
	*phy1_dac_sb_rd_delay = (localVal & ((uint32_t)0x0000003C)) >>  2;
	*phy1_dac_sb_mode = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint8_t ricu_afe_ctrl_35_phy_1_phy_1_dac_sb_ignore_fifo_indication_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_35_PHY_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE void ricu_afe_ctrl_35_phy_1_phy_1_dac_sb_ignore_fifo_indication_setf(uint8_t phy1dacsbignorefifoindication)
{
	ASSERT_ERR((((uint32_t)phy1dacsbignorefifoindication << 6) & ~((uint32_t)0x00000040)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_35_PHY_1_ADDR, (REG_PL_RD(RICU_AFE_CTRL_35_PHY_1_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)phy1dacsbignorefifoindication <<6));
}
__INLINE uint8_t ricu_afe_ctrl_35_phy_1_phy_1_dac_sb_rd_delay_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_35_PHY_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000003C)) >> 2);
}
__INLINE void ricu_afe_ctrl_35_phy_1_phy_1_dac_sb_rd_delay_setf(uint8_t phy1dacsbrddelay)
{
	ASSERT_ERR((((uint32_t)phy1dacsbrddelay << 2) & ~((uint32_t)0x0000003C)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_35_PHY_1_ADDR, (REG_PL_RD(RICU_AFE_CTRL_35_PHY_1_ADDR) & ~((uint32_t)0x0000003C)) | ((uint32_t)phy1dacsbrddelay <<2));
}
__INLINE uint8_t ricu_afe_ctrl_35_phy_1_phy_1_dac_sb_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_35_PHY_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void ricu_afe_ctrl_35_phy_1_phy_1_dac_sb_mode_setf(uint8_t phy1dacsbmode)
{
	ASSERT_ERR((((uint32_t)phy1dacsbmode << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_35_PHY_1_ADDR, (REG_PL_RD(RICU_AFE_CTRL_35_PHY_1_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)phy1dacsbmode <<0));
}

/**
 * @brief BTC_CONF_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 LUT_BTC_TMS_DOUT          0x0
 *    15:00 LUT_BTC_TRST_N_DOUT       0x0
 * </pre>
 */
#define RICU_BTC_CONF_0_ADDR        (REG_RICU_BASE_ADDR+0x000000B0)
#define RICU_BTC_CONF_0_OFFSET      0x000000B0
#define RICU_BTC_CONF_0_INDEX       0x0000002C
#define RICU_BTC_CONF_0_RESET       0x00000000

__INLINE uint32_t  ricu_btc_conf_0_get(void)
{
	return REG_PL_RD(RICU_BTC_CONF_0_ADDR);
}

__INLINE void ricu_btc_conf_0_set(uint32_t value)
{
	REG_PL_WR(RICU_BTC_CONF_0_ADDR, value);
}

// field definitions
#define RICU_BTC_CONF_0_LUT_BTC_TMS_DOUT_MASK    ((uint32_t)0xFFFF0000)
#define RICU_BTC_CONF_0_LUT_BTC_TMS_DOUT_LSB    16
#define RICU_BTC_CONF_0_LUT_BTC_TMS_DOUT_WIDTH    ((uint32_t)0x00000010)
#define RICU_BTC_CONF_0_LUT_BTC_TRST_N_DOUT_MASK    ((uint32_t)0x0000FFFF)
#define RICU_BTC_CONF_0_LUT_BTC_TRST_N_DOUT_LSB    0
#define RICU_BTC_CONF_0_LUT_BTC_TRST_N_DOUT_WIDTH    ((uint32_t)0x00000010)

#define RICU_BTC_CONF_0_LUT_BTC_TMS_DOUT_RST    0x0
#define RICU_BTC_CONF_0_LUT_BTC_TRST_N_DOUT_RST    0x0

__INLINE void ricu_btc_conf_0_pack(uint16_t lut_btc_tms_dout, uint16_t lut_btc_trst_n_dout)
{
	ASSERT_ERR((((uint32_t)lut_btc_tms_dout << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)lut_btc_trst_n_dout << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(RICU_BTC_CONF_0_ADDR,  ((uint32_t)lut_btc_tms_dout << 16) |((uint32_t)lut_btc_trst_n_dout << 0));
}

__INLINE void ricu_btc_conf_0_unpack(uint16_t* lut_btc_tms_dout, uint16_t* lut_btc_trst_n_dout)
{
	uint32_t localVal = REG_PL_RD(RICU_BTC_CONF_0_ADDR);

	*lut_btc_tms_dout = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*lut_btc_trst_n_dout = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t ricu_btc_conf_0_lut_btc_tms_dout_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_BTC_CONF_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void ricu_btc_conf_0_lut_btc_tms_dout_setf(uint16_t lutbtctmsdout)
{
	ASSERT_ERR((((uint32_t)lutbtctmsdout << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(RICU_BTC_CONF_0_ADDR, (REG_PL_RD(RICU_BTC_CONF_0_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)lutbtctmsdout <<16));
}
__INLINE uint16_t ricu_btc_conf_0_lut_btc_trst_n_dout_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_BTC_CONF_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void ricu_btc_conf_0_lut_btc_trst_n_dout_setf(uint16_t lutbtctrstndout)
{
	ASSERT_ERR((((uint32_t)lutbtctrstndout << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(RICU_BTC_CONF_0_ADDR, (REG_PL_RD(RICU_BTC_CONF_0_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)lutbtctrstndout <<0));
}

/**
 * @brief BTC_CONF_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 LUT_BTC_TDO_DOUT          0x0
 *    15:00 LUT_BTC_TDI_DOUT          0x0
 * </pre>
 */
#define RICU_BTC_CONF_1_ADDR        (REG_RICU_BASE_ADDR+0x000000B4)
#define RICU_BTC_CONF_1_OFFSET      0x000000B4
#define RICU_BTC_CONF_1_INDEX       0x0000002D
#define RICU_BTC_CONF_1_RESET       0x00000000

__INLINE uint32_t  ricu_btc_conf_1_get(void)
{
	return REG_PL_RD(RICU_BTC_CONF_1_ADDR);
}

__INLINE void ricu_btc_conf_1_set(uint32_t value)
{
	REG_PL_WR(RICU_BTC_CONF_1_ADDR, value);
}

// field definitions
#define RICU_BTC_CONF_1_LUT_BTC_TDO_DOUT_MASK    ((uint32_t)0xFFFF0000)
#define RICU_BTC_CONF_1_LUT_BTC_TDO_DOUT_LSB    16
#define RICU_BTC_CONF_1_LUT_BTC_TDO_DOUT_WIDTH    ((uint32_t)0x00000010)
#define RICU_BTC_CONF_1_LUT_BTC_TDI_DOUT_MASK    ((uint32_t)0x0000FFFF)
#define RICU_BTC_CONF_1_LUT_BTC_TDI_DOUT_LSB    0
#define RICU_BTC_CONF_1_LUT_BTC_TDI_DOUT_WIDTH    ((uint32_t)0x00000010)

#define RICU_BTC_CONF_1_LUT_BTC_TDO_DOUT_RST    0x0
#define RICU_BTC_CONF_1_LUT_BTC_TDI_DOUT_RST    0x0

__INLINE void ricu_btc_conf_1_pack(uint16_t lut_btc_tdo_dout, uint16_t lut_btc_tdi_dout)
{
	ASSERT_ERR((((uint32_t)lut_btc_tdo_dout << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)lut_btc_tdi_dout << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(RICU_BTC_CONF_1_ADDR,  ((uint32_t)lut_btc_tdo_dout << 16) |((uint32_t)lut_btc_tdi_dout << 0));
}

__INLINE void ricu_btc_conf_1_unpack(uint16_t* lut_btc_tdo_dout, uint16_t* lut_btc_tdi_dout)
{
	uint32_t localVal = REG_PL_RD(RICU_BTC_CONF_1_ADDR);

	*lut_btc_tdo_dout = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*lut_btc_tdi_dout = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t ricu_btc_conf_1_lut_btc_tdo_dout_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_BTC_CONF_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void ricu_btc_conf_1_lut_btc_tdo_dout_setf(uint16_t lutbtctdodout)
{
	ASSERT_ERR((((uint32_t)lutbtctdodout << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(RICU_BTC_CONF_1_ADDR, (REG_PL_RD(RICU_BTC_CONF_1_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)lutbtctdodout <<16));
}
__INLINE uint16_t ricu_btc_conf_1_lut_btc_tdi_dout_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_BTC_CONF_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void ricu_btc_conf_1_lut_btc_tdi_dout_setf(uint16_t lutbtctdidout)
{
	ASSERT_ERR((((uint32_t)lutbtctdidout << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(RICU_BTC_CONF_1_ADDR, (REG_PL_RD(RICU_BTC_CONF_1_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)lutbtctdidout <<0));
}

/**
 * @brief BTC_CONF_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:12 LUT_BTC_TDO_OE            0x0
 *    11:08 LUT_BTC_TDI_OE            0x0
 *    07:04 LUT_BTC_TMS_OE            0x0
 *    03:00 LUT_BTC_TRST_N_OE         0x0
 * </pre>
 */
#define RICU_BTC_CONF_2_ADDR        (REG_RICU_BASE_ADDR+0x000000B8)
#define RICU_BTC_CONF_2_OFFSET      0x000000B8
#define RICU_BTC_CONF_2_INDEX       0x0000002E
#define RICU_BTC_CONF_2_RESET       0x00000000

__INLINE uint32_t  ricu_btc_conf_2_get(void)
{
	return REG_PL_RD(RICU_BTC_CONF_2_ADDR);
}

__INLINE void ricu_btc_conf_2_set(uint32_t value)
{
	REG_PL_WR(RICU_BTC_CONF_2_ADDR, value);
}

// field definitions
#define RICU_BTC_CONF_2_LUT_BTC_TDO_OE_MASK    ((uint32_t)0x0000F000)
#define RICU_BTC_CONF_2_LUT_BTC_TDO_OE_LSB    12
#define RICU_BTC_CONF_2_LUT_BTC_TDO_OE_WIDTH    ((uint32_t)0x00000004)
#define RICU_BTC_CONF_2_LUT_BTC_TDI_OE_MASK    ((uint32_t)0x00000F00)
#define RICU_BTC_CONF_2_LUT_BTC_TDI_OE_LSB    8
#define RICU_BTC_CONF_2_LUT_BTC_TDI_OE_WIDTH    ((uint32_t)0x00000004)
#define RICU_BTC_CONF_2_LUT_BTC_TMS_OE_MASK    ((uint32_t)0x000000F0)
#define RICU_BTC_CONF_2_LUT_BTC_TMS_OE_LSB    4
#define RICU_BTC_CONF_2_LUT_BTC_TMS_OE_WIDTH    ((uint32_t)0x00000004)
#define RICU_BTC_CONF_2_LUT_BTC_TRST_N_OE_MASK    ((uint32_t)0x0000000F)
#define RICU_BTC_CONF_2_LUT_BTC_TRST_N_OE_LSB    0
#define RICU_BTC_CONF_2_LUT_BTC_TRST_N_OE_WIDTH    ((uint32_t)0x00000004)

#define RICU_BTC_CONF_2_LUT_BTC_TDO_OE_RST    0x0
#define RICU_BTC_CONF_2_LUT_BTC_TDI_OE_RST    0x0
#define RICU_BTC_CONF_2_LUT_BTC_TMS_OE_RST    0x0
#define RICU_BTC_CONF_2_LUT_BTC_TRST_N_OE_RST    0x0

__INLINE void ricu_btc_conf_2_pack(uint8_t lut_btc_tdo_oe, uint8_t lut_btc_tdi_oe, uint8_t lut_btc_tms_oe, uint8_t lut_btc_trst_n_oe)
{
	ASSERT_ERR((((uint32_t)lut_btc_tdo_oe << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)lut_btc_tdi_oe << 8) & ~((uint32_t)0x00000F00)) == 0);
	ASSERT_ERR((((uint32_t)lut_btc_tms_oe << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)lut_btc_trst_n_oe << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RICU_BTC_CONF_2_ADDR,  ((uint32_t)lut_btc_tdo_oe << 12) |((uint32_t)lut_btc_tdi_oe << 8) |((uint32_t)lut_btc_tms_oe << 4) |((uint32_t)lut_btc_trst_n_oe << 0));
}

__INLINE void ricu_btc_conf_2_unpack(uint8_t* lut_btc_tdo_oe, uint8_t* lut_btc_tdi_oe, uint8_t* lut_btc_tms_oe, uint8_t* lut_btc_trst_n_oe)
{
	uint32_t localVal = REG_PL_RD(RICU_BTC_CONF_2_ADDR);

	*lut_btc_tdo_oe = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*lut_btc_tdi_oe = (localVal & ((uint32_t)0x00000F00)) >>  8;
	*lut_btc_tms_oe = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*lut_btc_trst_n_oe = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t ricu_btc_conf_2_lut_btc_tdo_oe_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_BTC_CONF_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void ricu_btc_conf_2_lut_btc_tdo_oe_setf(uint8_t lutbtctdooe)
{
	ASSERT_ERR((((uint32_t)lutbtctdooe << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(RICU_BTC_CONF_2_ADDR, (REG_PL_RD(RICU_BTC_CONF_2_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)lutbtctdooe <<12));
}
__INLINE uint8_t ricu_btc_conf_2_lut_btc_tdi_oe_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_BTC_CONF_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000F00)) >> 8);
}
__INLINE void ricu_btc_conf_2_lut_btc_tdi_oe_setf(uint8_t lutbtctdioe)
{
	ASSERT_ERR((((uint32_t)lutbtctdioe << 8) & ~((uint32_t)0x00000F00)) == 0);
	REG_PL_WR(RICU_BTC_CONF_2_ADDR, (REG_PL_RD(RICU_BTC_CONF_2_ADDR) & ~((uint32_t)0x00000F00)) | ((uint32_t)lutbtctdioe <<8));
}
__INLINE uint8_t ricu_btc_conf_2_lut_btc_tms_oe_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_BTC_CONF_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE void ricu_btc_conf_2_lut_btc_tms_oe_setf(uint8_t lutbtctmsoe)
{
	ASSERT_ERR((((uint32_t)lutbtctmsoe << 4) & ~((uint32_t)0x000000F0)) == 0);
	REG_PL_WR(RICU_BTC_CONF_2_ADDR, (REG_PL_RD(RICU_BTC_CONF_2_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)lutbtctmsoe <<4));
}
__INLINE uint8_t ricu_btc_conf_2_lut_btc_trst_n_oe_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_BTC_CONF_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void ricu_btc_conf_2_lut_btc_trst_n_oe_setf(uint8_t lutbtctrstnoe)
{
	ASSERT_ERR((((uint32_t)lutbtctrstnoe << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RICU_BTC_CONF_2_ADDR, (REG_PL_RD(RICU_BTC_CONF_2_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)lutbtctrstnoe <<0));
}

/**
 * @brief AFE_CTRL_37_PHY_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    05    PHY0_EN_DAC5              0              
 *    04    PHY0_EN_DAC4              0              
 *    03    PHY0_EN_DAC3              0              
 *    02    PHY0_EN_DAC2              0              
 *    01    PHY0_EN_DAC1              0              
 *    00    PHY0_EN_DAC0              0              
 * </pre>
 */
#define RICU_AFE_CTRL_37_PHY_0_ADDR        (REG_RICU_BASE_ADDR+0x000000BC)
#define RICU_AFE_CTRL_37_PHY_0_OFFSET      0x000000BC
#define RICU_AFE_CTRL_37_PHY_0_INDEX       0x0000002F
#define RICU_AFE_CTRL_37_PHY_0_RESET       0x00000000

__INLINE uint32_t  ricu_afe_ctrl_37_phy_0_get(void)
{
	return REG_PL_RD(RICU_AFE_CTRL_37_PHY_0_ADDR);
}

__INLINE void ricu_afe_ctrl_37_phy_0_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTRL_37_PHY_0_ADDR, value);
}

// field definitions
#define RICU_AFE_CTRL_37_PHY_0_PHY_0_EN_DAC_5_BIT    ((uint32_t)0x00000020)
#define RICU_AFE_CTRL_37_PHY_0_PHY_0_EN_DAC_5_POS    5
#define RICU_AFE_CTRL_37_PHY_0_PHY_0_EN_DAC_4_BIT    ((uint32_t)0x00000010)
#define RICU_AFE_CTRL_37_PHY_0_PHY_0_EN_DAC_4_POS    4
#define RICU_AFE_CTRL_37_PHY_0_PHY_0_EN_DAC_3_BIT    ((uint32_t)0x00000008)
#define RICU_AFE_CTRL_37_PHY_0_PHY_0_EN_DAC_3_POS    3
#define RICU_AFE_CTRL_37_PHY_0_PHY_0_EN_DAC_2_BIT    ((uint32_t)0x00000004)
#define RICU_AFE_CTRL_37_PHY_0_PHY_0_EN_DAC_2_POS    2
#define RICU_AFE_CTRL_37_PHY_0_PHY_0_EN_DAC_1_BIT    ((uint32_t)0x00000002)
#define RICU_AFE_CTRL_37_PHY_0_PHY_0_EN_DAC_1_POS    1
#define RICU_AFE_CTRL_37_PHY_0_PHY_0_EN_DAC_0_BIT    ((uint32_t)0x00000001)
#define RICU_AFE_CTRL_37_PHY_0_PHY_0_EN_DAC_0_POS    0

#define RICU_AFE_CTRL_37_PHY_0_PHY_0_EN_DAC_5_RST    0x0
#define RICU_AFE_CTRL_37_PHY_0_PHY_0_EN_DAC_4_RST    0x0
#define RICU_AFE_CTRL_37_PHY_0_PHY_0_EN_DAC_3_RST    0x0
#define RICU_AFE_CTRL_37_PHY_0_PHY_0_EN_DAC_2_RST    0x0
#define RICU_AFE_CTRL_37_PHY_0_PHY_0_EN_DAC_1_RST    0x0
#define RICU_AFE_CTRL_37_PHY_0_PHY_0_EN_DAC_0_RST    0x0

__INLINE void ricu_afe_ctrl_37_phy_0_pack(uint8_t phy0_en_dac5, uint8_t phy0_en_dac4, uint8_t phy0_en_dac3, uint8_t phy0_en_dac2, uint8_t phy0_en_dac1, uint8_t phy0_en_dac0)
{
	ASSERT_ERR((((uint32_t)phy0_en_dac5 << 5) & ~((uint32_t)0x00000020)) == 0);
	ASSERT_ERR((((uint32_t)phy0_en_dac4 << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)phy0_en_dac3 << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)phy0_en_dac2 << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)phy0_en_dac1 << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)phy0_en_dac0 << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_37_PHY_0_ADDR,  ((uint32_t)phy0_en_dac5 << 5) |((uint32_t)phy0_en_dac4 << 4) |((uint32_t)phy0_en_dac3 << 3) |((uint32_t)phy0_en_dac2 << 2) |((uint32_t)phy0_en_dac1 << 1) |((uint32_t)phy0_en_dac0 << 0));
}

__INLINE void ricu_afe_ctrl_37_phy_0_unpack(uint8_t* phy0_en_dac5, uint8_t* phy0_en_dac4, uint8_t* phy0_en_dac3, uint8_t* phy0_en_dac2, uint8_t* phy0_en_dac1, uint8_t* phy0_en_dac0)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_37_PHY_0_ADDR);

	*phy0_en_dac5 = (localVal & ((uint32_t)0x00000020)) >>  5;
	*phy0_en_dac4 = (localVal & ((uint32_t)0x00000010)) >>  4;
	*phy0_en_dac3 = (localVal & ((uint32_t)0x00000008)) >>  3;
	*phy0_en_dac2 = (localVal & ((uint32_t)0x00000004)) >>  2;
	*phy0_en_dac1 = (localVal & ((uint32_t)0x00000002)) >>  1;
	*phy0_en_dac0 = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t ricu_afe_ctrl_37_phy_0_phy_0_en_dac_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_37_PHY_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE void ricu_afe_ctrl_37_phy_0_phy_0_en_dac_5_setf(uint8_t phy0endac5)
{
	ASSERT_ERR((((uint32_t)phy0endac5 << 5) & ~((uint32_t)0x00000020)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_37_PHY_0_ADDR, (REG_PL_RD(RICU_AFE_CTRL_37_PHY_0_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)phy0endac5 <<5));
}
__INLINE uint8_t ricu_afe_ctrl_37_phy_0_phy_0_en_dac_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_37_PHY_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void ricu_afe_ctrl_37_phy_0_phy_0_en_dac_4_setf(uint8_t phy0endac4)
{
	ASSERT_ERR((((uint32_t)phy0endac4 << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_37_PHY_0_ADDR, (REG_PL_RD(RICU_AFE_CTRL_37_PHY_0_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)phy0endac4 <<4));
}
__INLINE uint8_t ricu_afe_ctrl_37_phy_0_phy_0_en_dac_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_37_PHY_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void ricu_afe_ctrl_37_phy_0_phy_0_en_dac_3_setf(uint8_t phy0endac3)
{
	ASSERT_ERR((((uint32_t)phy0endac3 << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_37_PHY_0_ADDR, (REG_PL_RD(RICU_AFE_CTRL_37_PHY_0_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)phy0endac3 <<3));
}
__INLINE uint8_t ricu_afe_ctrl_37_phy_0_phy_0_en_dac_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_37_PHY_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void ricu_afe_ctrl_37_phy_0_phy_0_en_dac_2_setf(uint8_t phy0endac2)
{
	ASSERT_ERR((((uint32_t)phy0endac2 << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_37_PHY_0_ADDR, (REG_PL_RD(RICU_AFE_CTRL_37_PHY_0_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)phy0endac2 <<2));
}
__INLINE uint8_t ricu_afe_ctrl_37_phy_0_phy_0_en_dac_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_37_PHY_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void ricu_afe_ctrl_37_phy_0_phy_0_en_dac_1_setf(uint8_t phy0endac1)
{
	ASSERT_ERR((((uint32_t)phy0endac1 << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_37_PHY_0_ADDR, (REG_PL_RD(RICU_AFE_CTRL_37_PHY_0_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)phy0endac1 <<1));
}
__INLINE uint8_t ricu_afe_ctrl_37_phy_0_phy_0_en_dac_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_37_PHY_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void ricu_afe_ctrl_37_phy_0_phy_0_en_dac_0_setf(uint8_t phy0endac0)
{
	ASSERT_ERR((((uint32_t)phy0endac0 << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_37_PHY_0_ADDR, (REG_PL_RD(RICU_AFE_CTRL_37_PHY_0_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)phy0endac0 <<0));
}

/**
 * @brief AFE_CTRL_37_PHY_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    05    PHY1_EN_DAC5              0              
 *    04    PHY1_EN_DAC4              0              
 *    03    PHY1_EN_DAC3              0              
 *    02    PHY1_EN_DAC2              0              
 *    01    PHY1_EN_DAC1              0              
 *    00    PHY1_EN_DAC0              0              
 * </pre>
 */
#define RICU_AFE_CTRL_37_PHY_1_ADDR        (REG_RICU_BASE_ADDR+0x000000C0)
#define RICU_AFE_CTRL_37_PHY_1_OFFSET      0x000000C0
#define RICU_AFE_CTRL_37_PHY_1_INDEX       0x00000030
#define RICU_AFE_CTRL_37_PHY_1_RESET       0x00000000

__INLINE uint32_t  ricu_afe_ctrl_37_phy_1_get(void)
{
	return REG_PL_RD(RICU_AFE_CTRL_37_PHY_1_ADDR);
}

__INLINE void ricu_afe_ctrl_37_phy_1_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTRL_37_PHY_1_ADDR, value);
}

// field definitions
#define RICU_AFE_CTRL_37_PHY_1_PHY_1_EN_DAC_5_BIT    ((uint32_t)0x00000020)
#define RICU_AFE_CTRL_37_PHY_1_PHY_1_EN_DAC_5_POS    5
#define RICU_AFE_CTRL_37_PHY_1_PHY_1_EN_DAC_4_BIT    ((uint32_t)0x00000010)
#define RICU_AFE_CTRL_37_PHY_1_PHY_1_EN_DAC_4_POS    4
#define RICU_AFE_CTRL_37_PHY_1_PHY_1_EN_DAC_3_BIT    ((uint32_t)0x00000008)
#define RICU_AFE_CTRL_37_PHY_1_PHY_1_EN_DAC_3_POS    3
#define RICU_AFE_CTRL_37_PHY_1_PHY_1_EN_DAC_2_BIT    ((uint32_t)0x00000004)
#define RICU_AFE_CTRL_37_PHY_1_PHY_1_EN_DAC_2_POS    2
#define RICU_AFE_CTRL_37_PHY_1_PHY_1_EN_DAC_1_BIT    ((uint32_t)0x00000002)
#define RICU_AFE_CTRL_37_PHY_1_PHY_1_EN_DAC_1_POS    1
#define RICU_AFE_CTRL_37_PHY_1_PHY_1_EN_DAC_0_BIT    ((uint32_t)0x00000001)
#define RICU_AFE_CTRL_37_PHY_1_PHY_1_EN_DAC_0_POS    0

#define RICU_AFE_CTRL_37_PHY_1_PHY_1_EN_DAC_5_RST    0x0
#define RICU_AFE_CTRL_37_PHY_1_PHY_1_EN_DAC_4_RST    0x0
#define RICU_AFE_CTRL_37_PHY_1_PHY_1_EN_DAC_3_RST    0x0
#define RICU_AFE_CTRL_37_PHY_1_PHY_1_EN_DAC_2_RST    0x0
#define RICU_AFE_CTRL_37_PHY_1_PHY_1_EN_DAC_1_RST    0x0
#define RICU_AFE_CTRL_37_PHY_1_PHY_1_EN_DAC_0_RST    0x0

__INLINE void ricu_afe_ctrl_37_phy_1_pack(uint8_t phy1_en_dac5, uint8_t phy1_en_dac4, uint8_t phy1_en_dac3, uint8_t phy1_en_dac2, uint8_t phy1_en_dac1, uint8_t phy1_en_dac0)
{
	ASSERT_ERR((((uint32_t)phy1_en_dac5 << 5) & ~((uint32_t)0x00000020)) == 0);
	ASSERT_ERR((((uint32_t)phy1_en_dac4 << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)phy1_en_dac3 << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)phy1_en_dac2 << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)phy1_en_dac1 << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)phy1_en_dac0 << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_37_PHY_1_ADDR,  ((uint32_t)phy1_en_dac5 << 5) |((uint32_t)phy1_en_dac4 << 4) |((uint32_t)phy1_en_dac3 << 3) |((uint32_t)phy1_en_dac2 << 2) |((uint32_t)phy1_en_dac1 << 1) |((uint32_t)phy1_en_dac0 << 0));
}

__INLINE void ricu_afe_ctrl_37_phy_1_unpack(uint8_t* phy1_en_dac5, uint8_t* phy1_en_dac4, uint8_t* phy1_en_dac3, uint8_t* phy1_en_dac2, uint8_t* phy1_en_dac1, uint8_t* phy1_en_dac0)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_37_PHY_1_ADDR);

	*phy1_en_dac5 = (localVal & ((uint32_t)0x00000020)) >>  5;
	*phy1_en_dac4 = (localVal & ((uint32_t)0x00000010)) >>  4;
	*phy1_en_dac3 = (localVal & ((uint32_t)0x00000008)) >>  3;
	*phy1_en_dac2 = (localVal & ((uint32_t)0x00000004)) >>  2;
	*phy1_en_dac1 = (localVal & ((uint32_t)0x00000002)) >>  1;
	*phy1_en_dac0 = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t ricu_afe_ctrl_37_phy_1_phy_1_en_dac_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_37_PHY_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE void ricu_afe_ctrl_37_phy_1_phy_1_en_dac_5_setf(uint8_t phy1endac5)
{
	ASSERT_ERR((((uint32_t)phy1endac5 << 5) & ~((uint32_t)0x00000020)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_37_PHY_1_ADDR, (REG_PL_RD(RICU_AFE_CTRL_37_PHY_1_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)phy1endac5 <<5));
}
__INLINE uint8_t ricu_afe_ctrl_37_phy_1_phy_1_en_dac_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_37_PHY_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void ricu_afe_ctrl_37_phy_1_phy_1_en_dac_4_setf(uint8_t phy1endac4)
{
	ASSERT_ERR((((uint32_t)phy1endac4 << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_37_PHY_1_ADDR, (REG_PL_RD(RICU_AFE_CTRL_37_PHY_1_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)phy1endac4 <<4));
}
__INLINE uint8_t ricu_afe_ctrl_37_phy_1_phy_1_en_dac_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_37_PHY_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void ricu_afe_ctrl_37_phy_1_phy_1_en_dac_3_setf(uint8_t phy1endac3)
{
	ASSERT_ERR((((uint32_t)phy1endac3 << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_37_PHY_1_ADDR, (REG_PL_RD(RICU_AFE_CTRL_37_PHY_1_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)phy1endac3 <<3));
}
__INLINE uint8_t ricu_afe_ctrl_37_phy_1_phy_1_en_dac_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_37_PHY_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void ricu_afe_ctrl_37_phy_1_phy_1_en_dac_2_setf(uint8_t phy1endac2)
{
	ASSERT_ERR((((uint32_t)phy1endac2 << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_37_PHY_1_ADDR, (REG_PL_RD(RICU_AFE_CTRL_37_PHY_1_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)phy1endac2 <<2));
}
__INLINE uint8_t ricu_afe_ctrl_37_phy_1_phy_1_en_dac_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_37_PHY_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void ricu_afe_ctrl_37_phy_1_phy_1_en_dac_1_setf(uint8_t phy1endac1)
{
	ASSERT_ERR((((uint32_t)phy1endac1 << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_37_PHY_1_ADDR, (REG_PL_RD(RICU_AFE_CTRL_37_PHY_1_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)phy1endac1 <<1));
}
__INLINE uint8_t ricu_afe_ctrl_37_phy_1_phy_1_en_dac_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_37_PHY_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void ricu_afe_ctrl_37_phy_1_phy_1_en_dac_0_setf(uint8_t phy1endac0)
{
	ASSERT_ERR((((uint32_t)phy1endac0 << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_37_PHY_1_ADDR, (REG_PL_RD(RICU_AFE_CTRL_37_PHY_1_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)phy1endac0 <<0));
}

/**
 * @brief AFE_CTRL_38_PHY_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    05    PHY0_DAC_SB_CLEAR_STICKY  0              
 *    04    PHY0_ADC_SB_CLEAR_STICKY  0              
 *    03    PHY0_DAC_SB_UNDERFLOW     0              
 *    02    PHY0_DAC_SB_OVERFLOW      0              
 *    01    PHY0_ADC_SB_UNDERFLOW     0              
 *    00    PHY0_ADC_SB_OVERFLOW      0              
 * </pre>
 */
#define RICU_AFE_CTRL_38_PHY_0_ADDR        (REG_RICU_BASE_ADDR+0x000000C4)
#define RICU_AFE_CTRL_38_PHY_0_OFFSET      0x000000C4
#define RICU_AFE_CTRL_38_PHY_0_INDEX       0x00000031
#define RICU_AFE_CTRL_38_PHY_0_RESET       0x00000000

__INLINE uint32_t  ricu_afe_ctrl_38_phy_0_get(void)
{
	return REG_PL_RD(RICU_AFE_CTRL_38_PHY_0_ADDR);
}

// field definitions
#define RICU_AFE_CTRL_38_PHY_0_PHY_0_DAC_SB_CLEAR_STICKY_BIT    ((uint32_t)0x00000020)
#define RICU_AFE_CTRL_38_PHY_0_PHY_0_DAC_SB_CLEAR_STICKY_POS    5
#define RICU_AFE_CTRL_38_PHY_0_PHY_0_ADC_SB_CLEAR_STICKY_BIT    ((uint32_t)0x00000010)
#define RICU_AFE_CTRL_38_PHY_0_PHY_0_ADC_SB_CLEAR_STICKY_POS    4
#define RICU_AFE_CTRL_38_PHY_0_PHY_0_DAC_SB_UNDERFLOW_BIT    ((uint32_t)0x00000008)
#define RICU_AFE_CTRL_38_PHY_0_PHY_0_DAC_SB_UNDERFLOW_POS    3
#define RICU_AFE_CTRL_38_PHY_0_PHY_0_DAC_SB_OVERFLOW_BIT    ((uint32_t)0x00000004)
#define RICU_AFE_CTRL_38_PHY_0_PHY_0_DAC_SB_OVERFLOW_POS    2
#define RICU_AFE_CTRL_38_PHY_0_PHY_0_ADC_SB_UNDERFLOW_BIT    ((uint32_t)0x00000002)
#define RICU_AFE_CTRL_38_PHY_0_PHY_0_ADC_SB_UNDERFLOW_POS    1
#define RICU_AFE_CTRL_38_PHY_0_PHY_0_ADC_SB_OVERFLOW_BIT    ((uint32_t)0x00000001)
#define RICU_AFE_CTRL_38_PHY_0_PHY_0_ADC_SB_OVERFLOW_POS    0

#define RICU_AFE_CTRL_38_PHY_0_PHY_0_DAC_SB_CLEAR_STICKY_RST    0x0
#define RICU_AFE_CTRL_38_PHY_0_PHY_0_ADC_SB_CLEAR_STICKY_RST    0x0
#define RICU_AFE_CTRL_38_PHY_0_PHY_0_DAC_SB_UNDERFLOW_RST    0x0
#define RICU_AFE_CTRL_38_PHY_0_PHY_0_DAC_SB_OVERFLOW_RST    0x0
#define RICU_AFE_CTRL_38_PHY_0_PHY_0_ADC_SB_UNDERFLOW_RST    0x0
#define RICU_AFE_CTRL_38_PHY_0_PHY_0_ADC_SB_OVERFLOW_RST    0x0

__INLINE void ricu_afe_ctrl_38_phy_0_unpack(uint8_t* phy0_dac_sb_clear_sticky, uint8_t* phy0_adc_sb_clear_sticky, uint8_t* phy0_dac_sb_underflow, uint8_t* phy0_dac_sb_overflow, uint8_t* phy0_adc_sb_underflow, uint8_t* phy0_adc_sb_overflow)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_38_PHY_0_ADDR);

	*phy0_dac_sb_clear_sticky = (localVal & ((uint32_t)0x00000020)) >>  5;
	*phy0_adc_sb_clear_sticky = (localVal & ((uint32_t)0x00000010)) >>  4;
	*phy0_dac_sb_underflow = (localVal & ((uint32_t)0x00000008)) >>  3;
	*phy0_dac_sb_overflow = (localVal & ((uint32_t)0x00000004)) >>  2;
	*phy0_adc_sb_underflow = (localVal & ((uint32_t)0x00000002)) >>  1;
	*phy0_adc_sb_overflow = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t ricu_afe_ctrl_38_phy_0_phy_0_dac_sb_clear_sticky_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_38_PHY_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE uint8_t ricu_afe_ctrl_38_phy_0_phy_0_adc_sb_clear_sticky_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_38_PHY_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE uint8_t ricu_afe_ctrl_38_phy_0_phy_0_dac_sb_underflow_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_38_PHY_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE uint8_t ricu_afe_ctrl_38_phy_0_phy_0_dac_sb_overflow_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_38_PHY_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE uint8_t ricu_afe_ctrl_38_phy_0_phy_0_adc_sb_underflow_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_38_PHY_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t ricu_afe_ctrl_38_phy_0_phy_0_adc_sb_overflow_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_38_PHY_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief AFE_CTRL_38_PHY_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    05    PHY1_DAC_SB_CLEAR_STICKY  0              
 *    04    PHY1_ADC_SB_CLEAR_STICKY  0              
 *    03    PHY1_DAC_SB_UNDERFLOW     0              
 *    02    PHY1_DAC_SB_OVERFLOW      0              
 *    01    PHY1_ADC_SB_UNDERFLOW     0              
 *    00    PHY1_ADC_SB_OVERFLOW      0              
 * </pre>
 */
#define RICU_AFE_CTRL_38_PHY_1_ADDR        (REG_RICU_BASE_ADDR+0x000000C8)
#define RICU_AFE_CTRL_38_PHY_1_OFFSET      0x000000C8
#define RICU_AFE_CTRL_38_PHY_1_INDEX       0x00000032
#define RICU_AFE_CTRL_38_PHY_1_RESET       0x00000000

__INLINE uint32_t  ricu_afe_ctrl_38_phy_1_get(void)
{
	return REG_PL_RD(RICU_AFE_CTRL_38_PHY_1_ADDR);
}

// field definitions
#define RICU_AFE_CTRL_38_PHY_1_PHY_1_DAC_SB_CLEAR_STICKY_BIT    ((uint32_t)0x00000020)
#define RICU_AFE_CTRL_38_PHY_1_PHY_1_DAC_SB_CLEAR_STICKY_POS    5
#define RICU_AFE_CTRL_38_PHY_1_PHY_1_ADC_SB_CLEAR_STICKY_BIT    ((uint32_t)0x00000010)
#define RICU_AFE_CTRL_38_PHY_1_PHY_1_ADC_SB_CLEAR_STICKY_POS    4
#define RICU_AFE_CTRL_38_PHY_1_PHY_1_DAC_SB_UNDERFLOW_BIT    ((uint32_t)0x00000008)
#define RICU_AFE_CTRL_38_PHY_1_PHY_1_DAC_SB_UNDERFLOW_POS    3
#define RICU_AFE_CTRL_38_PHY_1_PHY_1_DAC_SB_OVERFLOW_BIT    ((uint32_t)0x00000004)
#define RICU_AFE_CTRL_38_PHY_1_PHY_1_DAC_SB_OVERFLOW_POS    2
#define RICU_AFE_CTRL_38_PHY_1_PHY_1_ADC_SB_UNDERFLOW_BIT    ((uint32_t)0x00000002)
#define RICU_AFE_CTRL_38_PHY_1_PHY_1_ADC_SB_UNDERFLOW_POS    1
#define RICU_AFE_CTRL_38_PHY_1_PHY_1_ADC_SB_OVERFLOW_BIT    ((uint32_t)0x00000001)
#define RICU_AFE_CTRL_38_PHY_1_PHY_1_ADC_SB_OVERFLOW_POS    0

#define RICU_AFE_CTRL_38_PHY_1_PHY_1_DAC_SB_CLEAR_STICKY_RST    0x0
#define RICU_AFE_CTRL_38_PHY_1_PHY_1_ADC_SB_CLEAR_STICKY_RST    0x0
#define RICU_AFE_CTRL_38_PHY_1_PHY_1_DAC_SB_UNDERFLOW_RST    0x0
#define RICU_AFE_CTRL_38_PHY_1_PHY_1_DAC_SB_OVERFLOW_RST    0x0
#define RICU_AFE_CTRL_38_PHY_1_PHY_1_ADC_SB_UNDERFLOW_RST    0x0
#define RICU_AFE_CTRL_38_PHY_1_PHY_1_ADC_SB_OVERFLOW_RST    0x0

__INLINE void ricu_afe_ctrl_38_phy_1_unpack(uint8_t* phy1_dac_sb_clear_sticky, uint8_t* phy1_adc_sb_clear_sticky, uint8_t* phy1_dac_sb_underflow, uint8_t* phy1_dac_sb_overflow, uint8_t* phy1_adc_sb_underflow, uint8_t* phy1_adc_sb_overflow)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_38_PHY_1_ADDR);

	*phy1_dac_sb_clear_sticky = (localVal & ((uint32_t)0x00000020)) >>  5;
	*phy1_adc_sb_clear_sticky = (localVal & ((uint32_t)0x00000010)) >>  4;
	*phy1_dac_sb_underflow = (localVal & ((uint32_t)0x00000008)) >>  3;
	*phy1_dac_sb_overflow = (localVal & ((uint32_t)0x00000004)) >>  2;
	*phy1_adc_sb_underflow = (localVal & ((uint32_t)0x00000002)) >>  1;
	*phy1_adc_sb_overflow = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t ricu_afe_ctrl_38_phy_1_phy_1_dac_sb_clear_sticky_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_38_PHY_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE uint8_t ricu_afe_ctrl_38_phy_1_phy_1_adc_sb_clear_sticky_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_38_PHY_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE uint8_t ricu_afe_ctrl_38_phy_1_phy_1_dac_sb_underflow_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_38_PHY_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE uint8_t ricu_afe_ctrl_38_phy_1_phy_1_dac_sb_overflow_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_38_PHY_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE uint8_t ricu_afe_ctrl_38_phy_1_phy_1_adc_sb_underflow_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_38_PHY_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t ricu_afe_ctrl_38_phy_1_phy_1_adc_sb_overflow_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_38_PHY_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief AFE_CTRL_39 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    ROSEL4                    0              
 *    14:08 RO_CTRLQ4                 0x7
 *    06:00 RO_CTRLI4                 0x7
 * </pre>
 */
#define RICU_AFE_CTRL_39_ADDR        (REG_RICU_BASE_ADDR+0x000000CC)
#define RICU_AFE_CTRL_39_OFFSET      0x000000CC
#define RICU_AFE_CTRL_39_INDEX       0x00000033
#define RICU_AFE_CTRL_39_RESET       0x00000707

__INLINE uint32_t  ricu_afe_ctrl_39_get(void)
{
	return REG_PL_RD(RICU_AFE_CTRL_39_ADDR);
}

__INLINE void ricu_afe_ctrl_39_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTRL_39_ADDR, value);
}

// field definitions
#define RICU_AFE_CTRL_39_ROSEL_4_BIT        ((uint32_t)0x00010000)
#define RICU_AFE_CTRL_39_ROSEL_4_POS        16
#define RICU_AFE_CTRL_39_RO_CTRLQ_4_MASK    ((uint32_t)0x00007F00)
#define RICU_AFE_CTRL_39_RO_CTRLQ_4_LSB     8
#define RICU_AFE_CTRL_39_RO_CTRLQ_4_WIDTH    ((uint32_t)0x00000007)
#define RICU_AFE_CTRL_39_RO_CTRLI_4_MASK    ((uint32_t)0x0000007F)
#define RICU_AFE_CTRL_39_RO_CTRLI_4_LSB     0
#define RICU_AFE_CTRL_39_RO_CTRLI_4_WIDTH    ((uint32_t)0x00000007)

#define RICU_AFE_CTRL_39_ROSEL_4_RST        0x0
#define RICU_AFE_CTRL_39_RO_CTRLQ_4_RST     0x7
#define RICU_AFE_CTRL_39_RO_CTRLI_4_RST     0x7

__INLINE void ricu_afe_ctrl_39_pack(uint8_t rosel4, uint8_t ro_ctrlq4, uint8_t ro_ctrli4)
{
	ASSERT_ERR((((uint32_t)rosel4 << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)ro_ctrlq4 << 8) & ~((uint32_t)0x00007F00)) == 0);
	ASSERT_ERR((((uint32_t)ro_ctrli4 << 0) & ~((uint32_t)0x0000007F)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_39_ADDR,  ((uint32_t)rosel4 << 16) |((uint32_t)ro_ctrlq4 << 8) |((uint32_t)ro_ctrli4 << 0));
}

__INLINE void ricu_afe_ctrl_39_unpack(uint8_t* rosel4, uint8_t* ro_ctrlq4, uint8_t* ro_ctrli4)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_39_ADDR);

	*rosel4 = (localVal & ((uint32_t)0x00010000)) >>  16;
	*ro_ctrlq4 = (localVal & ((uint32_t)0x00007F00)) >>  8;
	*ro_ctrli4 = (localVal & ((uint32_t)0x0000007F)) >>  0;
}

__INLINE uint8_t ricu_afe_ctrl_39_rosel_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_39_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void ricu_afe_ctrl_39_rosel_4_setf(uint8_t rosel4)
{
	ASSERT_ERR((((uint32_t)rosel4 << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_39_ADDR, (REG_PL_RD(RICU_AFE_CTRL_39_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)rosel4 <<16));
}
__INLINE uint8_t ricu_afe_ctrl_39_ro_ctrlq_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_39_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007F00)) >> 8);
}
__INLINE void ricu_afe_ctrl_39_ro_ctrlq_4_setf(uint8_t roctrlq4)
{
	ASSERT_ERR((((uint32_t)roctrlq4 << 8) & ~((uint32_t)0x00007F00)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_39_ADDR, (REG_PL_RD(RICU_AFE_CTRL_39_ADDR) & ~((uint32_t)0x00007F00)) | ((uint32_t)roctrlq4 <<8));
}
__INLINE uint8_t ricu_afe_ctrl_39_ro_ctrli_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_39_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000007F)) >> 0);
}
__INLINE void ricu_afe_ctrl_39_ro_ctrli_4_setf(uint8_t roctrli4)
{
	ASSERT_ERR((((uint32_t)roctrli4 << 0) & ~((uint32_t)0x0000007F)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_39_ADDR, (REG_PL_RD(RICU_AFE_CTRL_39_ADDR) & ~((uint32_t)0x0000007F)) | ((uint32_t)roctrli4 <<0));
}

/**
 * @brief AFE_CTRL_40 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    ROSEL5                    0              
 *    14:08 RO_CTRLQ5                 0x7
 *    06:00 RO_CTRLI5                 0x7
 * </pre>
 */
#define RICU_AFE_CTRL_40_ADDR        (REG_RICU_BASE_ADDR+0x000000D0)
#define RICU_AFE_CTRL_40_OFFSET      0x000000D0
#define RICU_AFE_CTRL_40_INDEX       0x00000034
#define RICU_AFE_CTRL_40_RESET       0x00000707

__INLINE uint32_t  ricu_afe_ctrl_40_get(void)
{
	return REG_PL_RD(RICU_AFE_CTRL_40_ADDR);
}

__INLINE void ricu_afe_ctrl_40_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTRL_40_ADDR, value);
}

// field definitions
#define RICU_AFE_CTRL_40_ROSEL_5_BIT        ((uint32_t)0x00010000)
#define RICU_AFE_CTRL_40_ROSEL_5_POS        16
#define RICU_AFE_CTRL_40_RO_CTRLQ_5_MASK    ((uint32_t)0x00007F00)
#define RICU_AFE_CTRL_40_RO_CTRLQ_5_LSB     8
#define RICU_AFE_CTRL_40_RO_CTRLQ_5_WIDTH    ((uint32_t)0x00000007)
#define RICU_AFE_CTRL_40_RO_CTRLI_5_MASK    ((uint32_t)0x0000007F)
#define RICU_AFE_CTRL_40_RO_CTRLI_5_LSB     0
#define RICU_AFE_CTRL_40_RO_CTRLI_5_WIDTH    ((uint32_t)0x00000007)

#define RICU_AFE_CTRL_40_ROSEL_5_RST        0x0
#define RICU_AFE_CTRL_40_RO_CTRLQ_5_RST     0x7
#define RICU_AFE_CTRL_40_RO_CTRLI_5_RST     0x7

__INLINE void ricu_afe_ctrl_40_pack(uint8_t rosel5, uint8_t ro_ctrlq5, uint8_t ro_ctrli5)
{
	ASSERT_ERR((((uint32_t)rosel5 << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)ro_ctrlq5 << 8) & ~((uint32_t)0x00007F00)) == 0);
	ASSERT_ERR((((uint32_t)ro_ctrli5 << 0) & ~((uint32_t)0x0000007F)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_40_ADDR,  ((uint32_t)rosel5 << 16) |((uint32_t)ro_ctrlq5 << 8) |((uint32_t)ro_ctrli5 << 0));
}

__INLINE void ricu_afe_ctrl_40_unpack(uint8_t* rosel5, uint8_t* ro_ctrlq5, uint8_t* ro_ctrli5)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_40_ADDR);

	*rosel5 = (localVal & ((uint32_t)0x00010000)) >>  16;
	*ro_ctrlq5 = (localVal & ((uint32_t)0x00007F00)) >>  8;
	*ro_ctrli5 = (localVal & ((uint32_t)0x0000007F)) >>  0;
}

__INLINE uint8_t ricu_afe_ctrl_40_rosel_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_40_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void ricu_afe_ctrl_40_rosel_5_setf(uint8_t rosel5)
{
	ASSERT_ERR((((uint32_t)rosel5 << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_40_ADDR, (REG_PL_RD(RICU_AFE_CTRL_40_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)rosel5 <<16));
}
__INLINE uint8_t ricu_afe_ctrl_40_ro_ctrlq_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_40_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007F00)) >> 8);
}
__INLINE void ricu_afe_ctrl_40_ro_ctrlq_5_setf(uint8_t roctrlq5)
{
	ASSERT_ERR((((uint32_t)roctrlq5 << 8) & ~((uint32_t)0x00007F00)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_40_ADDR, (REG_PL_RD(RICU_AFE_CTRL_40_ADDR) & ~((uint32_t)0x00007F00)) | ((uint32_t)roctrlq5 <<8));
}
__INLINE uint8_t ricu_afe_ctrl_40_ro_ctrli_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_40_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000007F)) >> 0);
}
__INLINE void ricu_afe_ctrl_40_ro_ctrli_5_setf(uint8_t roctrli5)
{
	ASSERT_ERR((((uint32_t)roctrli5 << 0) & ~((uint32_t)0x0000007F)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_40_ADDR, (REG_PL_RD(RICU_AFE_CTRL_40_ADDR) & ~((uint32_t)0x0000007F)) | ((uint32_t)roctrli5 <<0));
}

/**
 * @brief AFE_CTRL_41 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    ROSEL6                    0              
 *    14:08 RO_CTRLQ6                 0x7
 *    06:00 RO_CTRLI6                 0x7
 * </pre>
 */
#define RICU_AFE_CTRL_41_ADDR        (REG_RICU_BASE_ADDR+0x000000D4)
#define RICU_AFE_CTRL_41_OFFSET      0x000000D4
#define RICU_AFE_CTRL_41_INDEX       0x00000035
#define RICU_AFE_CTRL_41_RESET       0x00000707

__INLINE uint32_t  ricu_afe_ctrl_41_get(void)
{
	return REG_PL_RD(RICU_AFE_CTRL_41_ADDR);
}

__INLINE void ricu_afe_ctrl_41_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTRL_41_ADDR, value);
}

// field definitions
#define RICU_AFE_CTRL_41_ROSEL_6_BIT        ((uint32_t)0x00010000)
#define RICU_AFE_CTRL_41_ROSEL_6_POS        16
#define RICU_AFE_CTRL_41_RO_CTRLQ_6_MASK    ((uint32_t)0x00007F00)
#define RICU_AFE_CTRL_41_RO_CTRLQ_6_LSB     8
#define RICU_AFE_CTRL_41_RO_CTRLQ_6_WIDTH    ((uint32_t)0x00000007)
#define RICU_AFE_CTRL_41_RO_CTRLI_6_MASK    ((uint32_t)0x0000007F)
#define RICU_AFE_CTRL_41_RO_CTRLI_6_LSB     0
#define RICU_AFE_CTRL_41_RO_CTRLI_6_WIDTH    ((uint32_t)0x00000007)

#define RICU_AFE_CTRL_41_ROSEL_6_RST        0x0
#define RICU_AFE_CTRL_41_RO_CTRLQ_6_RST     0x7
#define RICU_AFE_CTRL_41_RO_CTRLI_6_RST     0x7

__INLINE void ricu_afe_ctrl_41_pack(uint8_t rosel6, uint8_t ro_ctrlq6, uint8_t ro_ctrli6)
{
	ASSERT_ERR((((uint32_t)rosel6 << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)ro_ctrlq6 << 8) & ~((uint32_t)0x00007F00)) == 0);
	ASSERT_ERR((((uint32_t)ro_ctrli6 << 0) & ~((uint32_t)0x0000007F)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_41_ADDR,  ((uint32_t)rosel6 << 16) |((uint32_t)ro_ctrlq6 << 8) |((uint32_t)ro_ctrli6 << 0));
}

__INLINE void ricu_afe_ctrl_41_unpack(uint8_t* rosel6, uint8_t* ro_ctrlq6, uint8_t* ro_ctrli6)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_41_ADDR);

	*rosel6 = (localVal & ((uint32_t)0x00010000)) >>  16;
	*ro_ctrlq6 = (localVal & ((uint32_t)0x00007F00)) >>  8;
	*ro_ctrli6 = (localVal & ((uint32_t)0x0000007F)) >>  0;
}

__INLINE uint8_t ricu_afe_ctrl_41_rosel_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_41_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void ricu_afe_ctrl_41_rosel_6_setf(uint8_t rosel6)
{
	ASSERT_ERR((((uint32_t)rosel6 << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_41_ADDR, (REG_PL_RD(RICU_AFE_CTRL_41_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)rosel6 <<16));
}
__INLINE uint8_t ricu_afe_ctrl_41_ro_ctrlq_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_41_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007F00)) >> 8);
}
__INLINE void ricu_afe_ctrl_41_ro_ctrlq_6_setf(uint8_t roctrlq6)
{
	ASSERT_ERR((((uint32_t)roctrlq6 << 8) & ~((uint32_t)0x00007F00)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_41_ADDR, (REG_PL_RD(RICU_AFE_CTRL_41_ADDR) & ~((uint32_t)0x00007F00)) | ((uint32_t)roctrlq6 <<8));
}
__INLINE uint8_t ricu_afe_ctrl_41_ro_ctrli_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_41_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000007F)) >> 0);
}
__INLINE void ricu_afe_ctrl_41_ro_ctrli_6_setf(uint8_t roctrli6)
{
	ASSERT_ERR((((uint32_t)roctrli6 << 0) & ~((uint32_t)0x0000007F)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_41_ADDR, (REG_PL_RD(RICU_AFE_CTRL_41_ADDR) & ~((uint32_t)0x0000007F)) | ((uint32_t)roctrli6 <<0));
}

/**
 * @brief AFE_CTRL_42 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    ROSEL7                    0              
 *    14:08 RO_CTRLQ7                 0x7
 *    06:00 RO_CTRLI7                 0x7
 * </pre>
 */
#define RICU_AFE_CTRL_42_ADDR        (REG_RICU_BASE_ADDR+0x000000D8)
#define RICU_AFE_CTRL_42_OFFSET      0x000000D8
#define RICU_AFE_CTRL_42_INDEX       0x00000036
#define RICU_AFE_CTRL_42_RESET       0x00000707

__INLINE uint32_t  ricu_afe_ctrl_42_get(void)
{
	return REG_PL_RD(RICU_AFE_CTRL_42_ADDR);
}

__INLINE void ricu_afe_ctrl_42_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTRL_42_ADDR, value);
}

// field definitions
#define RICU_AFE_CTRL_42_ROSEL_7_BIT        ((uint32_t)0x00010000)
#define RICU_AFE_CTRL_42_ROSEL_7_POS        16
#define RICU_AFE_CTRL_42_RO_CTRLQ_7_MASK    ((uint32_t)0x00007F00)
#define RICU_AFE_CTRL_42_RO_CTRLQ_7_LSB     8
#define RICU_AFE_CTRL_42_RO_CTRLQ_7_WIDTH    ((uint32_t)0x00000007)
#define RICU_AFE_CTRL_42_RO_CTRLI_7_MASK    ((uint32_t)0x0000007F)
#define RICU_AFE_CTRL_42_RO_CTRLI_7_LSB     0
#define RICU_AFE_CTRL_42_RO_CTRLI_7_WIDTH    ((uint32_t)0x00000007)

#define RICU_AFE_CTRL_42_ROSEL_7_RST        0x0
#define RICU_AFE_CTRL_42_RO_CTRLQ_7_RST     0x7
#define RICU_AFE_CTRL_42_RO_CTRLI_7_RST     0x7

__INLINE void ricu_afe_ctrl_42_pack(uint8_t rosel7, uint8_t ro_ctrlq7, uint8_t ro_ctrli7)
{
	ASSERT_ERR((((uint32_t)rosel7 << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)ro_ctrlq7 << 8) & ~((uint32_t)0x00007F00)) == 0);
	ASSERT_ERR((((uint32_t)ro_ctrli7 << 0) & ~((uint32_t)0x0000007F)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_42_ADDR,  ((uint32_t)rosel7 << 16) |((uint32_t)ro_ctrlq7 << 8) |((uint32_t)ro_ctrli7 << 0));
}

__INLINE void ricu_afe_ctrl_42_unpack(uint8_t* rosel7, uint8_t* ro_ctrlq7, uint8_t* ro_ctrli7)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_42_ADDR);

	*rosel7 = (localVal & ((uint32_t)0x00010000)) >>  16;
	*ro_ctrlq7 = (localVal & ((uint32_t)0x00007F00)) >>  8;
	*ro_ctrli7 = (localVal & ((uint32_t)0x0000007F)) >>  0;
}

__INLINE uint8_t ricu_afe_ctrl_42_rosel_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_42_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void ricu_afe_ctrl_42_rosel_7_setf(uint8_t rosel7)
{
	ASSERT_ERR((((uint32_t)rosel7 << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_42_ADDR, (REG_PL_RD(RICU_AFE_CTRL_42_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)rosel7 <<16));
}
__INLINE uint8_t ricu_afe_ctrl_42_ro_ctrlq_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_42_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007F00)) >> 8);
}
__INLINE void ricu_afe_ctrl_42_ro_ctrlq_7_setf(uint8_t roctrlq7)
{
	ASSERT_ERR((((uint32_t)roctrlq7 << 8) & ~((uint32_t)0x00007F00)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_42_ADDR, (REG_PL_RD(RICU_AFE_CTRL_42_ADDR) & ~((uint32_t)0x00007F00)) | ((uint32_t)roctrlq7 <<8));
}
__INLINE uint8_t ricu_afe_ctrl_42_ro_ctrli_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_42_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000007F)) >> 0);
}
__INLINE void ricu_afe_ctrl_42_ro_ctrli_7_setf(uint8_t roctrli7)
{
	ASSERT_ERR((((uint32_t)roctrli7 << 0) & ~((uint32_t)0x0000007F)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_42_ADDR, (REG_PL_RD(RICU_AFE_CTRL_42_ADDR) & ~((uint32_t)0x0000007F)) | ((uint32_t)roctrli7 <<0));
}

/**
 * @brief AFE_CTRL_43 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01:00 FREQ_SEL                  0x3
 * </pre>
 */
#define RICU_AFE_CTRL_43_ADDR        (REG_RICU_BASE_ADDR+0x000000DC)
#define RICU_AFE_CTRL_43_OFFSET      0x000000DC
#define RICU_AFE_CTRL_43_INDEX       0x00000037
#define RICU_AFE_CTRL_43_RESET       0x00000003

__INLINE uint32_t  ricu_afe_ctrl_43_get(void)
{
	return REG_PL_RD(RICU_AFE_CTRL_43_ADDR);
}

__INLINE void ricu_afe_ctrl_43_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTRL_43_ADDR, value);
}

// field definitions
#define RICU_AFE_CTRL_43_FREQ_SEL_MASK      ((uint32_t)0x00000003)
#define RICU_AFE_CTRL_43_FREQ_SEL_LSB       0
#define RICU_AFE_CTRL_43_FREQ_SEL_WIDTH     ((uint32_t)0x00000002)

#define RICU_AFE_CTRL_43_FREQ_SEL_RST       0x3

__INLINE uint8_t ricu_afe_ctrl_43_freq_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_43_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void ricu_afe_ctrl_43_freq_sel_setf(uint8_t freqsel)
{
	ASSERT_ERR((((uint32_t)freqsel << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_43_ADDR, (uint32_t)freqsel << 0);
}

/**
 * @brief AFE_CTRL_44 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01:00 CDB_FREQ_SEL              0x3
 * </pre>
 */
#define RICU_AFE_CTRL_44_ADDR        (REG_RICU_BASE_ADDR+0x000000E0)
#define RICU_AFE_CTRL_44_OFFSET      0x000000E0
#define RICU_AFE_CTRL_44_INDEX       0x00000038
#define RICU_AFE_CTRL_44_RESET       0x00000003

__INLINE uint32_t  ricu_afe_ctrl_44_get(void)
{
	return REG_PL_RD(RICU_AFE_CTRL_44_ADDR);
}

__INLINE void ricu_afe_ctrl_44_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTRL_44_ADDR, value);
}

// field definitions
#define RICU_AFE_CTRL_44_CDB_FREQ_SEL_MASK    ((uint32_t)0x00000003)
#define RICU_AFE_CTRL_44_CDB_FREQ_SEL_LSB    0
#define RICU_AFE_CTRL_44_CDB_FREQ_SEL_WIDTH    ((uint32_t)0x00000002)

#define RICU_AFE_CTRL_44_CDB_FREQ_SEL_RST    0x3

__INLINE uint8_t ricu_afe_ctrl_44_cdb_freq_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_44_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void ricu_afe_ctrl_44_cdb_freq_sel_setf(uint8_t cdbfreqsel)
{
	ASSERT_ERR((((uint32_t)cdbfreqsel << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_44_ADDR, (uint32_t)cdbfreqsel << 0);
}

/**
 * @brief SPI_CLK_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    05:00 SPI_CLK_BITMAP            0xE
 * </pre>
 */
#define RICU_SPI_CLK_CTRL_ADDR        (REG_RICU_BASE_ADDR+0x000000E4)
#define RICU_SPI_CLK_CTRL_OFFSET      0x000000E4
#define RICU_SPI_CLK_CTRL_INDEX       0x00000039
#define RICU_SPI_CLK_CTRL_RESET       0x0000000E

__INLINE uint32_t  ricu_spi_clk_ctrl_get(void)
{
	return REG_PL_RD(RICU_SPI_CLK_CTRL_ADDR);
}

__INLINE void ricu_spi_clk_ctrl_set(uint32_t value)
{
	REG_PL_WR(RICU_SPI_CLK_CTRL_ADDR, value);
}

// field definitions
#define RICU_SPI_CLK_CTRL_SPI_CLK_BITMAP_MASK    ((uint32_t)0x0000003F)
#define RICU_SPI_CLK_CTRL_SPI_CLK_BITMAP_LSB    0
#define RICU_SPI_CLK_CTRL_SPI_CLK_BITMAP_WIDTH    ((uint32_t)0x00000006)

#define RICU_SPI_CLK_CTRL_SPI_CLK_BITMAP_RST    0xE

__INLINE uint8_t ricu_spi_clk_ctrl_spi_clk_bitmap_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_SPI_CLK_CTRL_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void ricu_spi_clk_ctrl_spi_clk_bitmap_setf(uint8_t spiclkbitmap)
{
	ASSERT_ERR((((uint32_t)spiclkbitmap << 0) & ~((uint32_t)0x0000003F)) == 0);
	REG_PL_WR(RICU_SPI_CLK_CTRL_ADDR, (uint32_t)spiclkbitmap << 0);
}

/**
 * @brief FEM_CONF_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:20 FEM5_CTL_SEL              0x5
 *    19:16 FEM4_CTL_SEL              0x4
 *    15:12 FEM3_CTL_SEL              0x3
 *    11:08 FEM2_CTL_SEL              0x2
 *    07:04 FEM1_CTL_SEL              0x1
 *    03:00 FEM0_CTL_SEL              0x0
 * </pre>
 */
#define RICU_FEM_CONF_0_ADDR        (REG_RICU_BASE_ADDR+0x000000F0)
#define RICU_FEM_CONF_0_OFFSET      0x000000F0
#define RICU_FEM_CONF_0_INDEX       0x0000003C
#define RICU_FEM_CONF_0_RESET       0x00543210

__INLINE uint32_t  ricu_fem_conf_0_get(void)
{
	return REG_PL_RD(RICU_FEM_CONF_0_ADDR);
}

__INLINE void ricu_fem_conf_0_set(uint32_t value)
{
	REG_PL_WR(RICU_FEM_CONF_0_ADDR, value);
}

// field definitions
#define RICU_FEM_CONF_0_FEM_5_CTL_SEL_MASK    ((uint32_t)0x00F00000)
#define RICU_FEM_CONF_0_FEM_5_CTL_SEL_LSB    20
#define RICU_FEM_CONF_0_FEM_5_CTL_SEL_WIDTH    ((uint32_t)0x00000004)
#define RICU_FEM_CONF_0_FEM_4_CTL_SEL_MASK    ((uint32_t)0x000F0000)
#define RICU_FEM_CONF_0_FEM_4_CTL_SEL_LSB    16
#define RICU_FEM_CONF_0_FEM_4_CTL_SEL_WIDTH    ((uint32_t)0x00000004)
#define RICU_FEM_CONF_0_FEM_3_CTL_SEL_MASK    ((uint32_t)0x0000F000)
#define RICU_FEM_CONF_0_FEM_3_CTL_SEL_LSB    12
#define RICU_FEM_CONF_0_FEM_3_CTL_SEL_WIDTH    ((uint32_t)0x00000004)
#define RICU_FEM_CONF_0_FEM_2_CTL_SEL_MASK    ((uint32_t)0x00000F00)
#define RICU_FEM_CONF_0_FEM_2_CTL_SEL_LSB    8
#define RICU_FEM_CONF_0_FEM_2_CTL_SEL_WIDTH    ((uint32_t)0x00000004)
#define RICU_FEM_CONF_0_FEM_1_CTL_SEL_MASK    ((uint32_t)0x000000F0)
#define RICU_FEM_CONF_0_FEM_1_CTL_SEL_LSB    4
#define RICU_FEM_CONF_0_FEM_1_CTL_SEL_WIDTH    ((uint32_t)0x00000004)
#define RICU_FEM_CONF_0_FEM_0_CTL_SEL_MASK    ((uint32_t)0x0000000F)
#define RICU_FEM_CONF_0_FEM_0_CTL_SEL_LSB    0
#define RICU_FEM_CONF_0_FEM_0_CTL_SEL_WIDTH    ((uint32_t)0x00000004)

#define RICU_FEM_CONF_0_FEM_5_CTL_SEL_RST    0x5
#define RICU_FEM_CONF_0_FEM_4_CTL_SEL_RST    0x4
#define RICU_FEM_CONF_0_FEM_3_CTL_SEL_RST    0x3
#define RICU_FEM_CONF_0_FEM_2_CTL_SEL_RST    0x2
#define RICU_FEM_CONF_0_FEM_1_CTL_SEL_RST    0x1
#define RICU_FEM_CONF_0_FEM_0_CTL_SEL_RST    0x0

__INLINE void ricu_fem_conf_0_pack(uint8_t fem5_ctl_sel, uint8_t fem4_ctl_sel, uint8_t fem3_ctl_sel, uint8_t fem2_ctl_sel, uint8_t fem1_ctl_sel, uint8_t fem0_ctl_sel)
{
	ASSERT_ERR((((uint32_t)fem5_ctl_sel << 20) & ~((uint32_t)0x00F00000)) == 0);
	ASSERT_ERR((((uint32_t)fem4_ctl_sel << 16) & ~((uint32_t)0x000F0000)) == 0);
	ASSERT_ERR((((uint32_t)fem3_ctl_sel << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)fem2_ctl_sel << 8) & ~((uint32_t)0x00000F00)) == 0);
	ASSERT_ERR((((uint32_t)fem1_ctl_sel << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)fem0_ctl_sel << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RICU_FEM_CONF_0_ADDR,  ((uint32_t)fem5_ctl_sel << 20) |((uint32_t)fem4_ctl_sel << 16) |((uint32_t)fem3_ctl_sel << 12) |((uint32_t)fem2_ctl_sel << 8) |((uint32_t)fem1_ctl_sel << 4) |((uint32_t)fem0_ctl_sel << 0));
}

__INLINE void ricu_fem_conf_0_unpack(uint8_t* fem5_ctl_sel, uint8_t* fem4_ctl_sel, uint8_t* fem3_ctl_sel, uint8_t* fem2_ctl_sel, uint8_t* fem1_ctl_sel, uint8_t* fem0_ctl_sel)
{
	uint32_t localVal = REG_PL_RD(RICU_FEM_CONF_0_ADDR);

	*fem5_ctl_sel = (localVal & ((uint32_t)0x00F00000)) >>  20;
	*fem4_ctl_sel = (localVal & ((uint32_t)0x000F0000)) >>  16;
	*fem3_ctl_sel = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*fem2_ctl_sel = (localVal & ((uint32_t)0x00000F00)) >>  8;
	*fem1_ctl_sel = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*fem0_ctl_sel = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t ricu_fem_conf_0_fem_5_ctl_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_FEM_CONF_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00F00000)) >> 20);
}
__INLINE void ricu_fem_conf_0_fem_5_ctl_sel_setf(uint8_t fem5ctlsel)
{
	ASSERT_ERR((((uint32_t)fem5ctlsel << 20) & ~((uint32_t)0x00F00000)) == 0);
	REG_PL_WR(RICU_FEM_CONF_0_ADDR, (REG_PL_RD(RICU_FEM_CONF_0_ADDR) & ~((uint32_t)0x00F00000)) | ((uint32_t)fem5ctlsel <<20));
}
__INLINE uint8_t ricu_fem_conf_0_fem_4_ctl_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_FEM_CONF_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000F0000)) >> 16);
}
__INLINE void ricu_fem_conf_0_fem_4_ctl_sel_setf(uint8_t fem4ctlsel)
{
	ASSERT_ERR((((uint32_t)fem4ctlsel << 16) & ~((uint32_t)0x000F0000)) == 0);
	REG_PL_WR(RICU_FEM_CONF_0_ADDR, (REG_PL_RD(RICU_FEM_CONF_0_ADDR) & ~((uint32_t)0x000F0000)) | ((uint32_t)fem4ctlsel <<16));
}
__INLINE uint8_t ricu_fem_conf_0_fem_3_ctl_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_FEM_CONF_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void ricu_fem_conf_0_fem_3_ctl_sel_setf(uint8_t fem3ctlsel)
{
	ASSERT_ERR((((uint32_t)fem3ctlsel << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(RICU_FEM_CONF_0_ADDR, (REG_PL_RD(RICU_FEM_CONF_0_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)fem3ctlsel <<12));
}
__INLINE uint8_t ricu_fem_conf_0_fem_2_ctl_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_FEM_CONF_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000F00)) >> 8);
}
__INLINE void ricu_fem_conf_0_fem_2_ctl_sel_setf(uint8_t fem2ctlsel)
{
	ASSERT_ERR((((uint32_t)fem2ctlsel << 8) & ~((uint32_t)0x00000F00)) == 0);
	REG_PL_WR(RICU_FEM_CONF_0_ADDR, (REG_PL_RD(RICU_FEM_CONF_0_ADDR) & ~((uint32_t)0x00000F00)) | ((uint32_t)fem2ctlsel <<8));
}
__INLINE uint8_t ricu_fem_conf_0_fem_1_ctl_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_FEM_CONF_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE void ricu_fem_conf_0_fem_1_ctl_sel_setf(uint8_t fem1ctlsel)
{
	ASSERT_ERR((((uint32_t)fem1ctlsel << 4) & ~((uint32_t)0x000000F0)) == 0);
	REG_PL_WR(RICU_FEM_CONF_0_ADDR, (REG_PL_RD(RICU_FEM_CONF_0_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)fem1ctlsel <<4));
}
__INLINE uint8_t ricu_fem_conf_0_fem_0_ctl_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_FEM_CONF_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void ricu_fem_conf_0_fem_0_ctl_sel_setf(uint8_t fem0ctlsel)
{
	ASSERT_ERR((((uint32_t)fem0ctlsel << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RICU_FEM_CONF_0_ADDR, (REG_PL_RD(RICU_FEM_CONF_0_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)fem0ctlsel <<0));
}

/**
 * @brief FEM_CONF_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:20 FEM11_CTL_SEL             0xd
 *    19:16 FEM10_CTL_SEL             0xc
 *    15:12 FEM9_CTL_SEL              0xb
 *    11:08 FEM8_CTL_SEL              0xa
 *    07:04 FEM7_CTL_SEL              0x9
 *    03:00 FEM6_CTL_SEL              0x8
 * </pre>
 */
#define RICU_FEM_CONF_1_ADDR        (REG_RICU_BASE_ADDR+0x000000F4)
#define RICU_FEM_CONF_1_OFFSET      0x000000F4
#define RICU_FEM_CONF_1_INDEX       0x0000003D
#define RICU_FEM_CONF_1_RESET       0x00DCBA98

__INLINE uint32_t  ricu_fem_conf_1_get(void)
{
	return REG_PL_RD(RICU_FEM_CONF_1_ADDR);
}

__INLINE void ricu_fem_conf_1_set(uint32_t value)
{
	REG_PL_WR(RICU_FEM_CONF_1_ADDR, value);
}

// field definitions
#define RICU_FEM_CONF_1_FEM_11_CTL_SEL_MASK    ((uint32_t)0x00F00000)
#define RICU_FEM_CONF_1_FEM_11_CTL_SEL_LSB    20
#define RICU_FEM_CONF_1_FEM_11_CTL_SEL_WIDTH    ((uint32_t)0x00000004)
#define RICU_FEM_CONF_1_FEM_10_CTL_SEL_MASK    ((uint32_t)0x000F0000)
#define RICU_FEM_CONF_1_FEM_10_CTL_SEL_LSB    16
#define RICU_FEM_CONF_1_FEM_10_CTL_SEL_WIDTH    ((uint32_t)0x00000004)
#define RICU_FEM_CONF_1_FEM_9_CTL_SEL_MASK    ((uint32_t)0x0000F000)
#define RICU_FEM_CONF_1_FEM_9_CTL_SEL_LSB    12
#define RICU_FEM_CONF_1_FEM_9_CTL_SEL_WIDTH    ((uint32_t)0x00000004)
#define RICU_FEM_CONF_1_FEM_8_CTL_SEL_MASK    ((uint32_t)0x00000F00)
#define RICU_FEM_CONF_1_FEM_8_CTL_SEL_LSB    8
#define RICU_FEM_CONF_1_FEM_8_CTL_SEL_WIDTH    ((uint32_t)0x00000004)
#define RICU_FEM_CONF_1_FEM_7_CTL_SEL_MASK    ((uint32_t)0x000000F0)
#define RICU_FEM_CONF_1_FEM_7_CTL_SEL_LSB    4
#define RICU_FEM_CONF_1_FEM_7_CTL_SEL_WIDTH    ((uint32_t)0x00000004)
#define RICU_FEM_CONF_1_FEM_6_CTL_SEL_MASK    ((uint32_t)0x0000000F)
#define RICU_FEM_CONF_1_FEM_6_CTL_SEL_LSB    0
#define RICU_FEM_CONF_1_FEM_6_CTL_SEL_WIDTH    ((uint32_t)0x00000004)

#define RICU_FEM_CONF_1_FEM_11_CTL_SEL_RST    0xd
#define RICU_FEM_CONF_1_FEM_10_CTL_SEL_RST    0xc
#define RICU_FEM_CONF_1_FEM_9_CTL_SEL_RST    0xb
#define RICU_FEM_CONF_1_FEM_8_CTL_SEL_RST    0xa
#define RICU_FEM_CONF_1_FEM_7_CTL_SEL_RST    0x9
#define RICU_FEM_CONF_1_FEM_6_CTL_SEL_RST    0x8

__INLINE void ricu_fem_conf_1_pack(uint8_t fem11_ctl_sel, uint8_t fem10_ctl_sel, uint8_t fem9_ctl_sel, uint8_t fem8_ctl_sel, uint8_t fem7_ctl_sel, uint8_t fem6_ctl_sel)
{
	ASSERT_ERR((((uint32_t)fem11_ctl_sel << 20) & ~((uint32_t)0x00F00000)) == 0);
	ASSERT_ERR((((uint32_t)fem10_ctl_sel << 16) & ~((uint32_t)0x000F0000)) == 0);
	ASSERT_ERR((((uint32_t)fem9_ctl_sel << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)fem8_ctl_sel << 8) & ~((uint32_t)0x00000F00)) == 0);
	ASSERT_ERR((((uint32_t)fem7_ctl_sel << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)fem6_ctl_sel << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RICU_FEM_CONF_1_ADDR,  ((uint32_t)fem11_ctl_sel << 20) |((uint32_t)fem10_ctl_sel << 16) |((uint32_t)fem9_ctl_sel << 12) |((uint32_t)fem8_ctl_sel << 8) |((uint32_t)fem7_ctl_sel << 4) |((uint32_t)fem6_ctl_sel << 0));
}

__INLINE void ricu_fem_conf_1_unpack(uint8_t* fem11_ctl_sel, uint8_t* fem10_ctl_sel, uint8_t* fem9_ctl_sel, uint8_t* fem8_ctl_sel, uint8_t* fem7_ctl_sel, uint8_t* fem6_ctl_sel)
{
	uint32_t localVal = REG_PL_RD(RICU_FEM_CONF_1_ADDR);

	*fem11_ctl_sel = (localVal & ((uint32_t)0x00F00000)) >>  20;
	*fem10_ctl_sel = (localVal & ((uint32_t)0x000F0000)) >>  16;
	*fem9_ctl_sel = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*fem8_ctl_sel = (localVal & ((uint32_t)0x00000F00)) >>  8;
	*fem7_ctl_sel = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*fem6_ctl_sel = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t ricu_fem_conf_1_fem_11_ctl_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_FEM_CONF_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00F00000)) >> 20);
}
__INLINE void ricu_fem_conf_1_fem_11_ctl_sel_setf(uint8_t fem11ctlsel)
{
	ASSERT_ERR((((uint32_t)fem11ctlsel << 20) & ~((uint32_t)0x00F00000)) == 0);
	REG_PL_WR(RICU_FEM_CONF_1_ADDR, (REG_PL_RD(RICU_FEM_CONF_1_ADDR) & ~((uint32_t)0x00F00000)) | ((uint32_t)fem11ctlsel <<20));
}
__INLINE uint8_t ricu_fem_conf_1_fem_10_ctl_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_FEM_CONF_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000F0000)) >> 16);
}
__INLINE void ricu_fem_conf_1_fem_10_ctl_sel_setf(uint8_t fem10ctlsel)
{
	ASSERT_ERR((((uint32_t)fem10ctlsel << 16) & ~((uint32_t)0x000F0000)) == 0);
	REG_PL_WR(RICU_FEM_CONF_1_ADDR, (REG_PL_RD(RICU_FEM_CONF_1_ADDR) & ~((uint32_t)0x000F0000)) | ((uint32_t)fem10ctlsel <<16));
}
__INLINE uint8_t ricu_fem_conf_1_fem_9_ctl_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_FEM_CONF_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void ricu_fem_conf_1_fem_9_ctl_sel_setf(uint8_t fem9ctlsel)
{
	ASSERT_ERR((((uint32_t)fem9ctlsel << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(RICU_FEM_CONF_1_ADDR, (REG_PL_RD(RICU_FEM_CONF_1_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)fem9ctlsel <<12));
}
__INLINE uint8_t ricu_fem_conf_1_fem_8_ctl_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_FEM_CONF_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000F00)) >> 8);
}
__INLINE void ricu_fem_conf_1_fem_8_ctl_sel_setf(uint8_t fem8ctlsel)
{
	ASSERT_ERR((((uint32_t)fem8ctlsel << 8) & ~((uint32_t)0x00000F00)) == 0);
	REG_PL_WR(RICU_FEM_CONF_1_ADDR, (REG_PL_RD(RICU_FEM_CONF_1_ADDR) & ~((uint32_t)0x00000F00)) | ((uint32_t)fem8ctlsel <<8));
}
__INLINE uint8_t ricu_fem_conf_1_fem_7_ctl_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_FEM_CONF_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE void ricu_fem_conf_1_fem_7_ctl_sel_setf(uint8_t fem7ctlsel)
{
	ASSERT_ERR((((uint32_t)fem7ctlsel << 4) & ~((uint32_t)0x000000F0)) == 0);
	REG_PL_WR(RICU_FEM_CONF_1_ADDR, (REG_PL_RD(RICU_FEM_CONF_1_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)fem7ctlsel <<4));
}
__INLINE uint8_t ricu_fem_conf_1_fem_6_ctl_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_FEM_CONF_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void ricu_fem_conf_1_fem_6_ctl_sel_setf(uint8_t fem6ctlsel)
{
	ASSERT_ERR((((uint32_t)fem6ctlsel << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RICU_FEM_CONF_1_ADDR, (REG_PL_RD(RICU_FEM_CONF_1_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)fem6ctlsel <<0));
}

/**
 * @brief AFE_CTRL_36_PHY_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    07    PHY1_ADC_ALWAYS_EN_LD_IR  0              
 *    06    PHY1_ADC_ALWAYS_EN_LD_AVDQ 0              
 *    05    PHY1_ADC_ALWAYS_EN_LD_AVDI 0              
 *    04    PHY1_ADC_ALWAYS_EN_ADCQ   0              
 *    03    PHY1_ADC_ALWAYS_EN_ADCI   0              
 *    01    PHY1_HW_MODE_DAC          0              
 *    00    PHY1_HW_MODE_ADC          0              
 * </pre>
 */
#define RICU_AFE_CTRL_36_PHY_1_ADDR        (REG_RICU_BASE_ADDR+0x000000F8)
#define RICU_AFE_CTRL_36_PHY_1_OFFSET      0x000000F8
#define RICU_AFE_CTRL_36_PHY_1_INDEX       0x0000003E
#define RICU_AFE_CTRL_36_PHY_1_RESET       0x00000000

__INLINE uint32_t  ricu_afe_ctrl_36_phy_1_get(void)
{
	return REG_PL_RD(RICU_AFE_CTRL_36_PHY_1_ADDR);
}

__INLINE void ricu_afe_ctrl_36_phy_1_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_CTRL_36_PHY_1_ADDR, value);
}

// field definitions
#define RICU_AFE_CTRL_36_PHY_1_PHY_1_ADC_ALWAYS_EN_LD_IR_BIT    ((uint32_t)0x00000080)
#define RICU_AFE_CTRL_36_PHY_1_PHY_1_ADC_ALWAYS_EN_LD_IR_POS    7
#define RICU_AFE_CTRL_36_PHY_1_PHY_1_ADC_ALWAYS_EN_LD_AVDQ_BIT    ((uint32_t)0x00000040)
#define RICU_AFE_CTRL_36_PHY_1_PHY_1_ADC_ALWAYS_EN_LD_AVDQ_POS    6
#define RICU_AFE_CTRL_36_PHY_1_PHY_1_ADC_ALWAYS_EN_LD_AVDI_BIT    ((uint32_t)0x00000020)
#define RICU_AFE_CTRL_36_PHY_1_PHY_1_ADC_ALWAYS_EN_LD_AVDI_POS    5
#define RICU_AFE_CTRL_36_PHY_1_PHY_1_ADC_ALWAYS_EN_ADCQ_BIT    ((uint32_t)0x00000010)
#define RICU_AFE_CTRL_36_PHY_1_PHY_1_ADC_ALWAYS_EN_ADCQ_POS    4
#define RICU_AFE_CTRL_36_PHY_1_PHY_1_ADC_ALWAYS_EN_ADCI_BIT    ((uint32_t)0x00000008)
#define RICU_AFE_CTRL_36_PHY_1_PHY_1_ADC_ALWAYS_EN_ADCI_POS    3
#define RICU_AFE_CTRL_36_PHY_1_PHY_1_HW_MODE_DAC_BIT    ((uint32_t)0x00000002)
#define RICU_AFE_CTRL_36_PHY_1_PHY_1_HW_MODE_DAC_POS    1
#define RICU_AFE_CTRL_36_PHY_1_PHY_1_HW_MODE_ADC_BIT    ((uint32_t)0x00000001)
#define RICU_AFE_CTRL_36_PHY_1_PHY_1_HW_MODE_ADC_POS    0

#define RICU_AFE_CTRL_36_PHY_1_PHY_1_ADC_ALWAYS_EN_LD_IR_RST    0x0
#define RICU_AFE_CTRL_36_PHY_1_PHY_1_ADC_ALWAYS_EN_LD_AVDQ_RST    0x0
#define RICU_AFE_CTRL_36_PHY_1_PHY_1_ADC_ALWAYS_EN_LD_AVDI_RST    0x0
#define RICU_AFE_CTRL_36_PHY_1_PHY_1_ADC_ALWAYS_EN_ADCQ_RST    0x0
#define RICU_AFE_CTRL_36_PHY_1_PHY_1_ADC_ALWAYS_EN_ADCI_RST    0x0
#define RICU_AFE_CTRL_36_PHY_1_PHY_1_HW_MODE_DAC_RST    0x0
#define RICU_AFE_CTRL_36_PHY_1_PHY_1_HW_MODE_ADC_RST    0x0

__INLINE void ricu_afe_ctrl_36_phy_1_pack(uint8_t phy1_adc_always_en_ld_ir, uint8_t phy1_adc_always_en_ld_avdq, uint8_t phy1_adc_always_en_ld_avdi, uint8_t phy1_adc_always_en_adcq, uint8_t phy1_adc_always_en_adci, uint8_t phy1_hw_mode_dac, uint8_t phy1_hw_mode_adc)
{
	ASSERT_ERR((((uint32_t)phy1_adc_always_en_ld_ir << 7) & ~((uint32_t)0x00000080)) == 0);
	ASSERT_ERR((((uint32_t)phy1_adc_always_en_ld_avdq << 6) & ~((uint32_t)0x00000040)) == 0);
	ASSERT_ERR((((uint32_t)phy1_adc_always_en_ld_avdi << 5) & ~((uint32_t)0x00000020)) == 0);
	ASSERT_ERR((((uint32_t)phy1_adc_always_en_adcq << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)phy1_adc_always_en_adci << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)phy1_hw_mode_dac << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)phy1_hw_mode_adc << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_36_PHY_1_ADDR,  ((uint32_t)phy1_adc_always_en_ld_ir << 7) |((uint32_t)phy1_adc_always_en_ld_avdq << 6) |((uint32_t)phy1_adc_always_en_ld_avdi << 5) |((uint32_t)phy1_adc_always_en_adcq << 4) |((uint32_t)phy1_adc_always_en_adci << 3) |((uint32_t)phy1_hw_mode_dac << 1) |((uint32_t)phy1_hw_mode_adc << 0));
}

__INLINE void ricu_afe_ctrl_36_phy_1_unpack(uint8_t* phy1_adc_always_en_ld_ir, uint8_t* phy1_adc_always_en_ld_avdq, uint8_t* phy1_adc_always_en_ld_avdi, uint8_t* phy1_adc_always_en_adcq, uint8_t* phy1_adc_always_en_adci, uint8_t* phy1_hw_mode_dac, uint8_t* phy1_hw_mode_adc)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_36_PHY_1_ADDR);

	*phy1_adc_always_en_ld_ir = (localVal & ((uint32_t)0x00000080)) >>  7;
	*phy1_adc_always_en_ld_avdq = (localVal & ((uint32_t)0x00000040)) >>  6;
	*phy1_adc_always_en_ld_avdi = (localVal & ((uint32_t)0x00000020)) >>  5;
	*phy1_adc_always_en_adcq = (localVal & ((uint32_t)0x00000010)) >>  4;
	*phy1_adc_always_en_adci = (localVal & ((uint32_t)0x00000008)) >>  3;
	*phy1_hw_mode_dac = (localVal & ((uint32_t)0x00000002)) >>  1;
	*phy1_hw_mode_adc = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t ricu_afe_ctrl_36_phy_1_phy_1_adc_always_en_ld_ir_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_36_PHY_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE void ricu_afe_ctrl_36_phy_1_phy_1_adc_always_en_ld_ir_setf(uint8_t phy1adcalwaysenldir)
{
	ASSERT_ERR((((uint32_t)phy1adcalwaysenldir << 7) & ~((uint32_t)0x00000080)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_36_PHY_1_ADDR, (REG_PL_RD(RICU_AFE_CTRL_36_PHY_1_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)phy1adcalwaysenldir <<7));
}
__INLINE uint8_t ricu_afe_ctrl_36_phy_1_phy_1_adc_always_en_ld_avdq_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_36_PHY_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE void ricu_afe_ctrl_36_phy_1_phy_1_adc_always_en_ld_avdq_setf(uint8_t phy1adcalwaysenldavdq)
{
	ASSERT_ERR((((uint32_t)phy1adcalwaysenldavdq << 6) & ~((uint32_t)0x00000040)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_36_PHY_1_ADDR, (REG_PL_RD(RICU_AFE_CTRL_36_PHY_1_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)phy1adcalwaysenldavdq <<6));
}
__INLINE uint8_t ricu_afe_ctrl_36_phy_1_phy_1_adc_always_en_ld_avdi_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_36_PHY_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE void ricu_afe_ctrl_36_phy_1_phy_1_adc_always_en_ld_avdi_setf(uint8_t phy1adcalwaysenldavdi)
{
	ASSERT_ERR((((uint32_t)phy1adcalwaysenldavdi << 5) & ~((uint32_t)0x00000020)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_36_PHY_1_ADDR, (REG_PL_RD(RICU_AFE_CTRL_36_PHY_1_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)phy1adcalwaysenldavdi <<5));
}
__INLINE uint8_t ricu_afe_ctrl_36_phy_1_phy_1_adc_always_en_adcq_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_36_PHY_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void ricu_afe_ctrl_36_phy_1_phy_1_adc_always_en_adcq_setf(uint8_t phy1adcalwaysenadcq)
{
	ASSERT_ERR((((uint32_t)phy1adcalwaysenadcq << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_36_PHY_1_ADDR, (REG_PL_RD(RICU_AFE_CTRL_36_PHY_1_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)phy1adcalwaysenadcq <<4));
}
__INLINE uint8_t ricu_afe_ctrl_36_phy_1_phy_1_adc_always_en_adci_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_36_PHY_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void ricu_afe_ctrl_36_phy_1_phy_1_adc_always_en_adci_setf(uint8_t phy1adcalwaysenadci)
{
	ASSERT_ERR((((uint32_t)phy1adcalwaysenadci << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_36_PHY_1_ADDR, (REG_PL_RD(RICU_AFE_CTRL_36_PHY_1_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)phy1adcalwaysenadci <<3));
}
__INLINE uint8_t ricu_afe_ctrl_36_phy_1_phy_1_hw_mode_dac_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_36_PHY_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void ricu_afe_ctrl_36_phy_1_phy_1_hw_mode_dac_setf(uint8_t phy1hwmodedac)
{
	ASSERT_ERR((((uint32_t)phy1hwmodedac << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_36_PHY_1_ADDR, (REG_PL_RD(RICU_AFE_CTRL_36_PHY_1_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)phy1hwmodedac <<1));
}
__INLINE uint8_t ricu_afe_ctrl_36_phy_1_phy_1_hw_mode_adc_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_CTRL_36_PHY_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void ricu_afe_ctrl_36_phy_1_phy_1_hw_mode_adc_setf(uint8_t phy1hwmodeadc)
{
	ASSERT_ERR((((uint32_t)phy1hwmodeadc << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RICU_AFE_CTRL_36_PHY_1_ADDR, (REG_PL_RD(RICU_AFE_CTRL_36_PHY_1_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)phy1hwmodeadc <<0));
}

/**
 * @brief AFE_ADC_CH_ALLOC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    07:00 AFE_ADC_CH_ALLOC          0xFF
 * </pre>
 */
#define RICU_AFE_ADC_CH_ALLOC_ADDR        (REG_RICU_BASE_ADDR+0x000000FC)
#define RICU_AFE_ADC_CH_ALLOC_OFFSET      0x000000FC
#define RICU_AFE_ADC_CH_ALLOC_INDEX       0x0000003F
#define RICU_AFE_ADC_CH_ALLOC_RESET       0x000000FF

__INLINE uint32_t  ricu_afe_adc_ch_alloc_get(void)
{
	return REG_PL_RD(RICU_AFE_ADC_CH_ALLOC_ADDR);
}

__INLINE void ricu_afe_adc_ch_alloc_set(uint32_t value)
{
	REG_PL_WR(RICU_AFE_ADC_CH_ALLOC_ADDR, value);
}

// field definitions
#define RICU_AFE_ADC_CH_ALLOC_AFE_ADC_CH_ALLOC_MASK    ((uint32_t)0x000000FF)
#define RICU_AFE_ADC_CH_ALLOC_AFE_ADC_CH_ALLOC_LSB    0
#define RICU_AFE_ADC_CH_ALLOC_AFE_ADC_CH_ALLOC_WIDTH    ((uint32_t)0x00000008)

#define RICU_AFE_ADC_CH_ALLOC_AFE_ADC_CH_ALLOC_RST    0xFF

__INLINE uint8_t ricu_afe_adc_ch_alloc_afe_adc_ch_alloc_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AFE_ADC_CH_ALLOC_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void ricu_afe_adc_ch_alloc_afe_adc_ch_alloc_setf(uint8_t afeadcchalloc)
{
	ASSERT_ERR((((uint32_t)afeadcchalloc << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RICU_AFE_ADC_CH_ALLOC_ADDR, (uint32_t)afeadcchalloc << 0);
}

/**
 * @brief PHY_0_RSSI_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:30 RC0_RSSI0                 0x0
 *    29:28 RC0_RSSI1                 0x0
 *    27:26 RC0_RSSI2                 0x0
 *    25:24 RC0_RSSI3                 0x0
 *    23:22 RC0_RSSI4                 0x0
 *    21:20 RC0_RSSI5                 0x0
 *    19:18 RC0_RSSI6                 0x0
 *    17:16 RC0_RSSI7                 0x0
 *    07:00 RC0_RSSI_VALID            0x0
 * </pre>
 */
#define RICU_PHY_0_RSSI_STATUS_ADDR        (REG_RICU_BASE_ADDR+0x00000100)
#define RICU_PHY_0_RSSI_STATUS_OFFSET      0x00000100
#define RICU_PHY_0_RSSI_STATUS_INDEX       0x00000040
#define RICU_PHY_0_RSSI_STATUS_RESET       0x00000000

__INLINE uint32_t  ricu_phy_0_rssi_status_get(void)
{
	return REG_PL_RD(RICU_PHY_0_RSSI_STATUS_ADDR);
}

// field definitions
#define RICU_PHY_0_RSSI_STATUS_RC_0_RSSI_0_MASK    ((uint32_t)0xC0000000)
#define RICU_PHY_0_RSSI_STATUS_RC_0_RSSI_0_LSB    30
#define RICU_PHY_0_RSSI_STATUS_RC_0_RSSI_0_WIDTH    ((uint32_t)0x00000002)
#define RICU_PHY_0_RSSI_STATUS_RC_0_RSSI_1_MASK    ((uint32_t)0x30000000)
#define RICU_PHY_0_RSSI_STATUS_RC_0_RSSI_1_LSB    28
#define RICU_PHY_0_RSSI_STATUS_RC_0_RSSI_1_WIDTH    ((uint32_t)0x00000002)
#define RICU_PHY_0_RSSI_STATUS_RC_0_RSSI_2_MASK    ((uint32_t)0x0C000000)
#define RICU_PHY_0_RSSI_STATUS_RC_0_RSSI_2_LSB    26
#define RICU_PHY_0_RSSI_STATUS_RC_0_RSSI_2_WIDTH    ((uint32_t)0x00000002)
#define RICU_PHY_0_RSSI_STATUS_RC_0_RSSI_3_MASK    ((uint32_t)0x03000000)
#define RICU_PHY_0_RSSI_STATUS_RC_0_RSSI_3_LSB    24
#define RICU_PHY_0_RSSI_STATUS_RC_0_RSSI_3_WIDTH    ((uint32_t)0x00000002)
#define RICU_PHY_0_RSSI_STATUS_RC_0_RSSI_4_MASK    ((uint32_t)0x00C00000)
#define RICU_PHY_0_RSSI_STATUS_RC_0_RSSI_4_LSB    22
#define RICU_PHY_0_RSSI_STATUS_RC_0_RSSI_4_WIDTH    ((uint32_t)0x00000002)
#define RICU_PHY_0_RSSI_STATUS_RC_0_RSSI_5_MASK    ((uint32_t)0x00300000)
#define RICU_PHY_0_RSSI_STATUS_RC_0_RSSI_5_LSB    20
#define RICU_PHY_0_RSSI_STATUS_RC_0_RSSI_5_WIDTH    ((uint32_t)0x00000002)
#define RICU_PHY_0_RSSI_STATUS_RC_0_RSSI_6_MASK    ((uint32_t)0x000C0000)
#define RICU_PHY_0_RSSI_STATUS_RC_0_RSSI_6_LSB    18
#define RICU_PHY_0_RSSI_STATUS_RC_0_RSSI_6_WIDTH    ((uint32_t)0x00000002)
#define RICU_PHY_0_RSSI_STATUS_RC_0_RSSI_7_MASK    ((uint32_t)0x00030000)
#define RICU_PHY_0_RSSI_STATUS_RC_0_RSSI_7_LSB    16
#define RICU_PHY_0_RSSI_STATUS_RC_0_RSSI_7_WIDTH    ((uint32_t)0x00000002)
#define RICU_PHY_0_RSSI_STATUS_RC_0_RSSI_VALID_MASK    ((uint32_t)0x000000FF)
#define RICU_PHY_0_RSSI_STATUS_RC_0_RSSI_VALID_LSB    0
#define RICU_PHY_0_RSSI_STATUS_RC_0_RSSI_VALID_WIDTH    ((uint32_t)0x00000008)

#define RICU_PHY_0_RSSI_STATUS_RC_0_RSSI_0_RST    0x0
#define RICU_PHY_0_RSSI_STATUS_RC_0_RSSI_1_RST    0x0
#define RICU_PHY_0_RSSI_STATUS_RC_0_RSSI_2_RST    0x0
#define RICU_PHY_0_RSSI_STATUS_RC_0_RSSI_3_RST    0x0
#define RICU_PHY_0_RSSI_STATUS_RC_0_RSSI_4_RST    0x0
#define RICU_PHY_0_RSSI_STATUS_RC_0_RSSI_5_RST    0x0
#define RICU_PHY_0_RSSI_STATUS_RC_0_RSSI_6_RST    0x0
#define RICU_PHY_0_RSSI_STATUS_RC_0_RSSI_7_RST    0x0
#define RICU_PHY_0_RSSI_STATUS_RC_0_RSSI_VALID_RST    0x0

__INLINE void ricu_phy_0_rssi_status_unpack(uint8_t* rc0_rssi0, uint8_t* rc0_rssi1, uint8_t* rc0_rssi2, uint8_t* rc0_rssi3, uint8_t* rc0_rssi4, uint8_t* rc0_rssi5, uint8_t* rc0_rssi6, uint8_t* rc0_rssi7, uint8_t* rc0_rssi_valid)
{
	uint32_t localVal = REG_PL_RD(RICU_PHY_0_RSSI_STATUS_ADDR);

	*rc0_rssi0 = (localVal & ((uint32_t)0xC0000000)) >>  30;
	*rc0_rssi1 = (localVal & ((uint32_t)0x30000000)) >>  28;
	*rc0_rssi2 = (localVal & ((uint32_t)0x0C000000)) >>  26;
	*rc0_rssi3 = (localVal & ((uint32_t)0x03000000)) >>  24;
	*rc0_rssi4 = (localVal & ((uint32_t)0x00C00000)) >>  22;
	*rc0_rssi5 = (localVal & ((uint32_t)0x00300000)) >>  20;
	*rc0_rssi6 = (localVal & ((uint32_t)0x000C0000)) >>  18;
	*rc0_rssi7 = (localVal & ((uint32_t)0x00030000)) >>  16;
	*rc0_rssi_valid = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t ricu_phy_0_rssi_status_rc_0_rssi_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_PHY_0_RSSI_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xC0000000)) >> 30);
}
__INLINE uint8_t ricu_phy_0_rssi_status_rc_0_rssi_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_PHY_0_RSSI_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x30000000)) >> 28);
}
__INLINE uint8_t ricu_phy_0_rssi_status_rc_0_rssi_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_PHY_0_RSSI_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0C000000)) >> 26);
}
__INLINE uint8_t ricu_phy_0_rssi_status_rc_0_rssi_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_PHY_0_RSSI_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x03000000)) >> 24);
}
__INLINE uint8_t ricu_phy_0_rssi_status_rc_0_rssi_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_PHY_0_RSSI_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00C00000)) >> 22);
}
__INLINE uint8_t ricu_phy_0_rssi_status_rc_0_rssi_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_PHY_0_RSSI_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00300000)) >> 20);
}
__INLINE uint8_t ricu_phy_0_rssi_status_rc_0_rssi_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_PHY_0_RSSI_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000C0000)) >> 18);
}
__INLINE uint8_t ricu_phy_0_rssi_status_rc_0_rssi_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_PHY_0_RSSI_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00030000)) >> 16);
}
__INLINE uint8_t ricu_phy_0_rssi_status_rc_0_rssi_valid_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_PHY_0_RSSI_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/**
 * @brief PHY_1_RSSI_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:30 RC1_RSSI0                 0x0
 *    29:28 RC1_RSSI1                 0x0
 *    27:26 RC1_RSSI2                 0x0
 *    25:24 RC1_RSSI3                 0x0
 *    23:22 RC1_RSSI4                 0x0
 *    21:20 RC1_RSSI5                 0x0
 *    19:18 RC1_RSSI6                 0x0
 *    17:16 RC1_RSSI7                 0x0
 *    07:00 RC1_RSSI_VALID            0x0
 * </pre>
 */
#define RICU_PHY_1_RSSI_STATUS_ADDR        (REG_RICU_BASE_ADDR+0x00000104)
#define RICU_PHY_1_RSSI_STATUS_OFFSET      0x00000104
#define RICU_PHY_1_RSSI_STATUS_INDEX       0x00000041
#define RICU_PHY_1_RSSI_STATUS_RESET       0x00000000

__INLINE uint32_t  ricu_phy_1_rssi_status_get(void)
{
	return REG_PL_RD(RICU_PHY_1_RSSI_STATUS_ADDR);
}

__INLINE void ricu_phy_1_rssi_status_set(uint32_t value)
{
	REG_PL_WR(RICU_PHY_1_RSSI_STATUS_ADDR, value);
}

// field definitions
#define RICU_PHY_1_RSSI_STATUS_RC_1_RSSI_0_MASK    ((uint32_t)0xC0000000)
#define RICU_PHY_1_RSSI_STATUS_RC_1_RSSI_0_LSB    30
#define RICU_PHY_1_RSSI_STATUS_RC_1_RSSI_0_WIDTH    ((uint32_t)0x00000002)
#define RICU_PHY_1_RSSI_STATUS_RC_1_RSSI_1_MASK    ((uint32_t)0x30000000)
#define RICU_PHY_1_RSSI_STATUS_RC_1_RSSI_1_LSB    28
#define RICU_PHY_1_RSSI_STATUS_RC_1_RSSI_1_WIDTH    ((uint32_t)0x00000002)
#define RICU_PHY_1_RSSI_STATUS_RC_1_RSSI_2_MASK    ((uint32_t)0x0C000000)
#define RICU_PHY_1_RSSI_STATUS_RC_1_RSSI_2_LSB    26
#define RICU_PHY_1_RSSI_STATUS_RC_1_RSSI_2_WIDTH    ((uint32_t)0x00000002)
#define RICU_PHY_1_RSSI_STATUS_RC_1_RSSI_3_MASK    ((uint32_t)0x03000000)
#define RICU_PHY_1_RSSI_STATUS_RC_1_RSSI_3_LSB    24
#define RICU_PHY_1_RSSI_STATUS_RC_1_RSSI_3_WIDTH    ((uint32_t)0x00000002)
#define RICU_PHY_1_RSSI_STATUS_RC_1_RSSI_4_MASK    ((uint32_t)0x00C00000)
#define RICU_PHY_1_RSSI_STATUS_RC_1_RSSI_4_LSB    22
#define RICU_PHY_1_RSSI_STATUS_RC_1_RSSI_4_WIDTH    ((uint32_t)0x00000002)
#define RICU_PHY_1_RSSI_STATUS_RC_1_RSSI_5_MASK    ((uint32_t)0x00300000)
#define RICU_PHY_1_RSSI_STATUS_RC_1_RSSI_5_LSB    20
#define RICU_PHY_1_RSSI_STATUS_RC_1_RSSI_5_WIDTH    ((uint32_t)0x00000002)
#define RICU_PHY_1_RSSI_STATUS_RC_1_RSSI_6_MASK    ((uint32_t)0x000C0000)
#define RICU_PHY_1_RSSI_STATUS_RC_1_RSSI_6_LSB    18
#define RICU_PHY_1_RSSI_STATUS_RC_1_RSSI_6_WIDTH    ((uint32_t)0x00000002)
#define RICU_PHY_1_RSSI_STATUS_RC_1_RSSI_7_MASK    ((uint32_t)0x00030000)
#define RICU_PHY_1_RSSI_STATUS_RC_1_RSSI_7_LSB    16
#define RICU_PHY_1_RSSI_STATUS_RC_1_RSSI_7_WIDTH    ((uint32_t)0x00000002)
#define RICU_PHY_1_RSSI_STATUS_RC_1_RSSI_VALID_MASK    ((uint32_t)0x000000FF)
#define RICU_PHY_1_RSSI_STATUS_RC_1_RSSI_VALID_LSB    0
#define RICU_PHY_1_RSSI_STATUS_RC_1_RSSI_VALID_WIDTH    ((uint32_t)0x00000008)

#define RICU_PHY_1_RSSI_STATUS_RC_1_RSSI_0_RST    0x0
#define RICU_PHY_1_RSSI_STATUS_RC_1_RSSI_1_RST    0x0
#define RICU_PHY_1_RSSI_STATUS_RC_1_RSSI_2_RST    0x0
#define RICU_PHY_1_RSSI_STATUS_RC_1_RSSI_3_RST    0x0
#define RICU_PHY_1_RSSI_STATUS_RC_1_RSSI_4_RST    0x0
#define RICU_PHY_1_RSSI_STATUS_RC_1_RSSI_5_RST    0x0
#define RICU_PHY_1_RSSI_STATUS_RC_1_RSSI_6_RST    0x0
#define RICU_PHY_1_RSSI_STATUS_RC_1_RSSI_7_RST    0x0
#define RICU_PHY_1_RSSI_STATUS_RC_1_RSSI_VALID_RST    0x0

__INLINE void ricu_phy_1_rssi_status_pack(uint8_t rc1_rssi0, uint8_t rc1_rssi1, uint8_t rc1_rssi2, uint8_t rc1_rssi3, uint8_t rc1_rssi4, uint8_t rc1_rssi5, uint8_t rc1_rssi6, uint8_t rc1_rssi7, uint8_t rc1_rssi_valid)
{
	ASSERT_ERR((((uint32_t)rc1_rssi0 << 30) & ~((uint32_t)0xC0000000)) == 0);
	ASSERT_ERR((((uint32_t)rc1_rssi1 << 28) & ~((uint32_t)0x30000000)) == 0);
	ASSERT_ERR((((uint32_t)rc1_rssi2 << 26) & ~((uint32_t)0x0C000000)) == 0);
	ASSERT_ERR((((uint32_t)rc1_rssi3 << 24) & ~((uint32_t)0x03000000)) == 0);
	ASSERT_ERR((((uint32_t)rc1_rssi4 << 22) & ~((uint32_t)0x00C00000)) == 0);
	ASSERT_ERR((((uint32_t)rc1_rssi5 << 20) & ~((uint32_t)0x00300000)) == 0);
	ASSERT_ERR((((uint32_t)rc1_rssi6 << 18) & ~((uint32_t)0x000C0000)) == 0);
	ASSERT_ERR((((uint32_t)rc1_rssi7 << 16) & ~((uint32_t)0x00030000)) == 0);
	ASSERT_ERR((((uint32_t)rc1_rssi_valid << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RICU_PHY_1_RSSI_STATUS_ADDR,  ((uint32_t)rc1_rssi0 << 30) |((uint32_t)rc1_rssi1 << 28) |((uint32_t)rc1_rssi2 << 26) |((uint32_t)rc1_rssi3 << 24) |((uint32_t)rc1_rssi4 << 22) |((uint32_t)rc1_rssi5 << 20) |((uint32_t)rc1_rssi6 << 18) |((uint32_t)rc1_rssi7 << 16) |((uint32_t)rc1_rssi_valid << 0));
}

__INLINE void ricu_phy_1_rssi_status_unpack(uint8_t* rc1_rssi0, uint8_t* rc1_rssi1, uint8_t* rc1_rssi2, uint8_t* rc1_rssi3, uint8_t* rc1_rssi4, uint8_t* rc1_rssi5, uint8_t* rc1_rssi6, uint8_t* rc1_rssi7, uint8_t* rc1_rssi_valid)
{
	uint32_t localVal = REG_PL_RD(RICU_PHY_1_RSSI_STATUS_ADDR);

	*rc1_rssi0 = (localVal & ((uint32_t)0xC0000000)) >>  30;
	*rc1_rssi1 = (localVal & ((uint32_t)0x30000000)) >>  28;
	*rc1_rssi2 = (localVal & ((uint32_t)0x0C000000)) >>  26;
	*rc1_rssi3 = (localVal & ((uint32_t)0x03000000)) >>  24;
	*rc1_rssi4 = (localVal & ((uint32_t)0x00C00000)) >>  22;
	*rc1_rssi5 = (localVal & ((uint32_t)0x00300000)) >>  20;
	*rc1_rssi6 = (localVal & ((uint32_t)0x000C0000)) >>  18;
	*rc1_rssi7 = (localVal & ((uint32_t)0x00030000)) >>  16;
	*rc1_rssi_valid = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t ricu_phy_1_rssi_status_rc_1_rssi_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_PHY_1_RSSI_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xC0000000)) >> 30);
}
__INLINE uint8_t ricu_phy_1_rssi_status_rc_1_rssi_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_PHY_1_RSSI_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x30000000)) >> 28);
}
__INLINE void ricu_phy_1_rssi_status_rc_1_rssi_1_setf(uint8_t rc1rssi1)
{
	ASSERT_ERR((((uint32_t)rc1rssi1 << 28) & ~((uint32_t)0x30000000)) == 0);
	REG_PL_WR(RICU_PHY_1_RSSI_STATUS_ADDR, (REG_PL_RD(RICU_PHY_1_RSSI_STATUS_ADDR) & ~((uint32_t)0x30000000)) | ((uint32_t)rc1rssi1 <<28));
}
__INLINE uint8_t ricu_phy_1_rssi_status_rc_1_rssi_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_PHY_1_RSSI_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0C000000)) >> 26);
}
__INLINE uint8_t ricu_phy_1_rssi_status_rc_1_rssi_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_PHY_1_RSSI_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x03000000)) >> 24);
}
__INLINE uint8_t ricu_phy_1_rssi_status_rc_1_rssi_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_PHY_1_RSSI_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00C00000)) >> 22);
}
__INLINE uint8_t ricu_phy_1_rssi_status_rc_1_rssi_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_PHY_1_RSSI_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00300000)) >> 20);
}
__INLINE uint8_t ricu_phy_1_rssi_status_rc_1_rssi_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_PHY_1_RSSI_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000C0000)) >> 18);
}
__INLINE uint8_t ricu_phy_1_rssi_status_rc_1_rssi_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_PHY_1_RSSI_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00030000)) >> 16);
}
__INLINE uint8_t ricu_phy_1_rssi_status_rc_1_rssi_valid_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_PHY_1_RSSI_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/**
 * @brief PHY_0_FWR_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    PHY0_RESET_COUNTER        0              
 *    30    PHY0_FWR_REQ_PEND         0              
 *    23:16 PHY0_FWR_ISSUED_NUM       0x0
 *    15:08 PHY0_FWR_GRANT_NUM        0x0
 *    07:00 PHY0_FWR_REQ_NUM          0x0
 * </pre>
 */
#define RICU_PHY_0_FWR_STATUS_ADDR        (REG_RICU_BASE_ADDR+0x00000108)
#define RICU_PHY_0_FWR_STATUS_OFFSET      0x00000108
#define RICU_PHY_0_FWR_STATUS_INDEX       0x00000042
#define RICU_PHY_0_FWR_STATUS_RESET       0x00000000

__INLINE uint32_t  ricu_phy_0_fwr_status_get(void)
{
	return REG_PL_RD(RICU_PHY_0_FWR_STATUS_ADDR);
}

__INLINE void ricu_phy_0_fwr_status_set(uint32_t value)
{
	REG_PL_WR(RICU_PHY_0_FWR_STATUS_ADDR, value);
}

// field definitions
#define RICU_PHY_0_FWR_STATUS_PHY_0_RESET_COUNTER_BIT    ((uint32_t)0x80000000)
#define RICU_PHY_0_FWR_STATUS_PHY_0_RESET_COUNTER_POS    31
#define RICU_PHY_0_FWR_STATUS_PHY_0_FWR_REQ_PEND_BIT    ((uint32_t)0x40000000)
#define RICU_PHY_0_FWR_STATUS_PHY_0_FWR_REQ_PEND_POS    30
#define RICU_PHY_0_FWR_STATUS_PHY_0_FWR_ISSUED_NUM_MASK    ((uint32_t)0x00FF0000)
#define RICU_PHY_0_FWR_STATUS_PHY_0_FWR_ISSUED_NUM_LSB    16
#define RICU_PHY_0_FWR_STATUS_PHY_0_FWR_ISSUED_NUM_WIDTH    ((uint32_t)0x00000008)
#define RICU_PHY_0_FWR_STATUS_PHY_0_FWR_GRANT_NUM_MASK    ((uint32_t)0x0000FF00)
#define RICU_PHY_0_FWR_STATUS_PHY_0_FWR_GRANT_NUM_LSB    8
#define RICU_PHY_0_FWR_STATUS_PHY_0_FWR_GRANT_NUM_WIDTH    ((uint32_t)0x00000008)
#define RICU_PHY_0_FWR_STATUS_PHY_0_FWR_REQ_NUM_MASK    ((uint32_t)0x000000FF)
#define RICU_PHY_0_FWR_STATUS_PHY_0_FWR_REQ_NUM_LSB    0
#define RICU_PHY_0_FWR_STATUS_PHY_0_FWR_REQ_NUM_WIDTH    ((uint32_t)0x00000008)

#define RICU_PHY_0_FWR_STATUS_PHY_0_RESET_COUNTER_RST    0x0
#define RICU_PHY_0_FWR_STATUS_PHY_0_FWR_REQ_PEND_RST    0x0
#define RICU_PHY_0_FWR_STATUS_PHY_0_FWR_ISSUED_NUM_RST    0x0
#define RICU_PHY_0_FWR_STATUS_PHY_0_FWR_GRANT_NUM_RST    0x0
#define RICU_PHY_0_FWR_STATUS_PHY_0_FWR_REQ_NUM_RST    0x0

__INLINE void ricu_phy_0_fwr_status_pack(uint8_t phy0_reset_counter, uint8_t phy0_fwr_req_pend, uint8_t phy0_fwr_issued_num, uint8_t phy0_fwr_grant_num, uint8_t phy0_fwr_req_num)
{
	ASSERT_ERR((((uint32_t)phy0_reset_counter << 31) & ~((uint32_t)0x80000000)) == 0);
	ASSERT_ERR((((uint32_t)phy0_fwr_req_pend << 30) & ~((uint32_t)0x40000000)) == 0);
	ASSERT_ERR((((uint32_t)phy0_fwr_issued_num << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)phy0_fwr_grant_num << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)phy0_fwr_req_num << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RICU_PHY_0_FWR_STATUS_ADDR,  ((uint32_t)phy0_reset_counter << 31) |((uint32_t)phy0_fwr_req_pend << 30) |((uint32_t)phy0_fwr_issued_num << 16) |((uint32_t)phy0_fwr_grant_num << 8) |((uint32_t)phy0_fwr_req_num << 0));
}

__INLINE void ricu_phy_0_fwr_status_unpack(uint8_t* phy0_reset_counter, uint8_t* phy0_fwr_req_pend, uint8_t* phy0_fwr_issued_num, uint8_t* phy0_fwr_grant_num, uint8_t* phy0_fwr_req_num)
{
	uint32_t localVal = REG_PL_RD(RICU_PHY_0_FWR_STATUS_ADDR);

	*phy0_reset_counter = (localVal & ((uint32_t)0x80000000)) >>  31;
	*phy0_fwr_req_pend = (localVal & ((uint32_t)0x40000000)) >>  30;
	*phy0_fwr_issued_num = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*phy0_fwr_grant_num = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*phy0_fwr_req_num = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE void ricu_phy_0_fwr_status_phy_0_reset_counter_setf(uint8_t phy0resetcounter)
{
	ASSERT_ERR((((uint32_t)phy0resetcounter << 31) & ~((uint32_t)0x80000000)) == 0);
	REG_PL_WR(RICU_PHY_0_FWR_STATUS_ADDR, (REG_PL_RD(RICU_PHY_0_FWR_STATUS_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)phy0resetcounter <<31));
}
__INLINE uint8_t ricu_phy_0_fwr_status_phy_0_fwr_req_pend_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_PHY_0_FWR_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x40000000)) >> 30);
}
__INLINE uint8_t ricu_phy_0_fwr_status_phy_0_fwr_issued_num_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_PHY_0_FWR_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE uint8_t ricu_phy_0_fwr_status_phy_0_fwr_grant_num_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_PHY_0_FWR_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE uint8_t ricu_phy_0_fwr_status_phy_0_fwr_req_num_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_PHY_0_FWR_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/**
 * @brief PHY_1_FWR_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    PHY1_RESET_COUNTER        0              
 *    30    PHY1_FWR_REQ_PEND         0              
 *    23:16 PHY1_FWR_ISSUED_NUM       0x0
 *    15:08 PHY1_FWR_GRANT_NUM        0x0
 *    07:00 PHY1_FWR_REQ_NUM          0x0
 * </pre>
 */
#define RICU_PHY_1_FWR_STATUS_ADDR        (REG_RICU_BASE_ADDR+0x0000010C)
#define RICU_PHY_1_FWR_STATUS_OFFSET      0x0000010C
#define RICU_PHY_1_FWR_STATUS_INDEX       0x00000043
#define RICU_PHY_1_FWR_STATUS_RESET       0x00000000

__INLINE uint32_t  ricu_phy_1_fwr_status_get(void)
{
	return REG_PL_RD(RICU_PHY_1_FWR_STATUS_ADDR);
}

__INLINE void ricu_phy_1_fwr_status_set(uint32_t value)
{
	REG_PL_WR(RICU_PHY_1_FWR_STATUS_ADDR, value);
}

// field definitions
#define RICU_PHY_1_FWR_STATUS_PHY_1_RESET_COUNTER_BIT    ((uint32_t)0x80000000)
#define RICU_PHY_1_FWR_STATUS_PHY_1_RESET_COUNTER_POS    31
#define RICU_PHY_1_FWR_STATUS_PHY_1_FWR_REQ_PEND_BIT    ((uint32_t)0x40000000)
#define RICU_PHY_1_FWR_STATUS_PHY_1_FWR_REQ_PEND_POS    30
#define RICU_PHY_1_FWR_STATUS_PHY_1_FWR_ISSUED_NUM_MASK    ((uint32_t)0x00FF0000)
#define RICU_PHY_1_FWR_STATUS_PHY_1_FWR_ISSUED_NUM_LSB    16
#define RICU_PHY_1_FWR_STATUS_PHY_1_FWR_ISSUED_NUM_WIDTH    ((uint32_t)0x00000008)
#define RICU_PHY_1_FWR_STATUS_PHY_1_FWR_GRANT_NUM_MASK    ((uint32_t)0x0000FF00)
#define RICU_PHY_1_FWR_STATUS_PHY_1_FWR_GRANT_NUM_LSB    8
#define RICU_PHY_1_FWR_STATUS_PHY_1_FWR_GRANT_NUM_WIDTH    ((uint32_t)0x00000008)
#define RICU_PHY_1_FWR_STATUS_PHY_1_FWR_REQ_NUM_MASK    ((uint32_t)0x000000FF)
#define RICU_PHY_1_FWR_STATUS_PHY_1_FWR_REQ_NUM_LSB    0
#define RICU_PHY_1_FWR_STATUS_PHY_1_FWR_REQ_NUM_WIDTH    ((uint32_t)0x00000008)

#define RICU_PHY_1_FWR_STATUS_PHY_1_RESET_COUNTER_RST    0x0
#define RICU_PHY_1_FWR_STATUS_PHY_1_FWR_REQ_PEND_RST    0x0
#define RICU_PHY_1_FWR_STATUS_PHY_1_FWR_ISSUED_NUM_RST    0x0
#define RICU_PHY_1_FWR_STATUS_PHY_1_FWR_GRANT_NUM_RST    0x0
#define RICU_PHY_1_FWR_STATUS_PHY_1_FWR_REQ_NUM_RST    0x0

__INLINE void ricu_phy_1_fwr_status_pack(uint8_t phy1_reset_counter, uint8_t phy1_fwr_req_pend, uint8_t phy1_fwr_issued_num, uint8_t phy1_fwr_grant_num, uint8_t phy1_fwr_req_num)
{
	ASSERT_ERR((((uint32_t)phy1_reset_counter << 31) & ~((uint32_t)0x80000000)) == 0);
	ASSERT_ERR((((uint32_t)phy1_fwr_req_pend << 30) & ~((uint32_t)0x40000000)) == 0);
	ASSERT_ERR((((uint32_t)phy1_fwr_issued_num << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)phy1_fwr_grant_num << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)phy1_fwr_req_num << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RICU_PHY_1_FWR_STATUS_ADDR,  ((uint32_t)phy1_reset_counter << 31) |((uint32_t)phy1_fwr_req_pend << 30) |((uint32_t)phy1_fwr_issued_num << 16) |((uint32_t)phy1_fwr_grant_num << 8) |((uint32_t)phy1_fwr_req_num << 0));
}

__INLINE void ricu_phy_1_fwr_status_unpack(uint8_t* phy1_reset_counter, uint8_t* phy1_fwr_req_pend, uint8_t* phy1_fwr_issued_num, uint8_t* phy1_fwr_grant_num, uint8_t* phy1_fwr_req_num)
{
	uint32_t localVal = REG_PL_RD(RICU_PHY_1_FWR_STATUS_ADDR);

	*phy1_reset_counter = (localVal & ((uint32_t)0x80000000)) >>  31;
	*phy1_fwr_req_pend = (localVal & ((uint32_t)0x40000000)) >>  30;
	*phy1_fwr_issued_num = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*phy1_fwr_grant_num = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*phy1_fwr_req_num = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE void ricu_phy_1_fwr_status_phy_1_reset_counter_setf(uint8_t phy1resetcounter)
{
	ASSERT_ERR((((uint32_t)phy1resetcounter << 31) & ~((uint32_t)0x80000000)) == 0);
	REG_PL_WR(RICU_PHY_1_FWR_STATUS_ADDR, (REG_PL_RD(RICU_PHY_1_FWR_STATUS_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)phy1resetcounter <<31));
}
__INLINE uint8_t ricu_phy_1_fwr_status_phy_1_fwr_req_pend_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_PHY_1_FWR_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x40000000)) >> 30);
}
__INLINE uint8_t ricu_phy_1_fwr_status_phy_1_fwr_issued_num_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_PHY_1_FWR_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE uint8_t ricu_phy_1_fwr_status_phy_1_fwr_grant_num_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_PHY_1_FWR_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE uint8_t ricu_phy_1_fwr_status_phy_1_fwr_req_num_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_PHY_1_FWR_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/**
 * @brief RF_FWR_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    08    RF_FWR_LAST_MASTER        0              
 *    07:00 RF_FWR_LAST_DATA          0x0
 * </pre>
 */
#define RICU_RF_FWR_STATUS_ADDR        (REG_RICU_BASE_ADDR+0x00000110)
#define RICU_RF_FWR_STATUS_OFFSET      0x00000110
#define RICU_RF_FWR_STATUS_INDEX       0x00000044
#define RICU_RF_FWR_STATUS_RESET       0x00000000

__INLINE uint32_t  ricu_rf_fwr_status_get(void)
{
	return REG_PL_RD(RICU_RF_FWR_STATUS_ADDR);
}

// field definitions
#define RICU_RF_FWR_STATUS_RF_FWR_LAST_MASTER_BIT    ((uint32_t)0x00000100)
#define RICU_RF_FWR_STATUS_RF_FWR_LAST_MASTER_POS    8
#define RICU_RF_FWR_STATUS_RF_FWR_LAST_DATA_MASK    ((uint32_t)0x000000FF)
#define RICU_RF_FWR_STATUS_RF_FWR_LAST_DATA_LSB    0
#define RICU_RF_FWR_STATUS_RF_FWR_LAST_DATA_WIDTH    ((uint32_t)0x00000008)

#define RICU_RF_FWR_STATUS_RF_FWR_LAST_MASTER_RST    0x0
#define RICU_RF_FWR_STATUS_RF_FWR_LAST_DATA_RST    0x0

__INLINE void ricu_rf_fwr_status_unpack(uint8_t* rf_fwr_last_master, uint8_t* rf_fwr_last_data)
{
	uint32_t localVal = REG_PL_RD(RICU_RF_FWR_STATUS_ADDR);

	*rf_fwr_last_master = (localVal & ((uint32_t)0x00000100)) >>  8;
	*rf_fwr_last_data = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t ricu_rf_fwr_status_rf_fwr_last_master_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_RF_FWR_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE uint8_t ricu_rf_fwr_status_rf_fwr_last_data_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_RF_FWR_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/**
 * @brief PHY_0_SPI_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    30:24 RC0_SPI_RD_ADDR           0x0
 *    23:16 RC0_SPI_RD_DATA           0x0
 *    14:08 RC0_SPI_WR_ADDR           0x0
 *    07:00 RC0_SPI_WR_DATA           0x0
 * </pre>
 */
#define RICU_PHY_0_SPI_STATUS_ADDR        (REG_RICU_BASE_ADDR+0x00000114)
#define RICU_PHY_0_SPI_STATUS_OFFSET      0x00000114
#define RICU_PHY_0_SPI_STATUS_INDEX       0x00000045
#define RICU_PHY_0_SPI_STATUS_RESET       0x00000000

__INLINE uint32_t  ricu_phy_0_spi_status_get(void)
{
	return REG_PL_RD(RICU_PHY_0_SPI_STATUS_ADDR);
}

// field definitions
#define RICU_PHY_0_SPI_STATUS_RC_0_SPI_RD_ADDR_MASK    ((uint32_t)0x7F000000)
#define RICU_PHY_0_SPI_STATUS_RC_0_SPI_RD_ADDR_LSB    24
#define RICU_PHY_0_SPI_STATUS_RC_0_SPI_RD_ADDR_WIDTH    ((uint32_t)0x00000007)
#define RICU_PHY_0_SPI_STATUS_RC_0_SPI_RD_DATA_MASK    ((uint32_t)0x00FF0000)
#define RICU_PHY_0_SPI_STATUS_RC_0_SPI_RD_DATA_LSB    16
#define RICU_PHY_0_SPI_STATUS_RC_0_SPI_RD_DATA_WIDTH    ((uint32_t)0x00000008)
#define RICU_PHY_0_SPI_STATUS_RC_0_SPI_WR_ADDR_MASK    ((uint32_t)0x00007F00)
#define RICU_PHY_0_SPI_STATUS_RC_0_SPI_WR_ADDR_LSB    8
#define RICU_PHY_0_SPI_STATUS_RC_0_SPI_WR_ADDR_WIDTH    ((uint32_t)0x00000007)
#define RICU_PHY_0_SPI_STATUS_RC_0_SPI_WR_DATA_MASK    ((uint32_t)0x000000FF)
#define RICU_PHY_0_SPI_STATUS_RC_0_SPI_WR_DATA_LSB    0
#define RICU_PHY_0_SPI_STATUS_RC_0_SPI_WR_DATA_WIDTH    ((uint32_t)0x00000008)

#define RICU_PHY_0_SPI_STATUS_RC_0_SPI_RD_ADDR_RST    0x0
#define RICU_PHY_0_SPI_STATUS_RC_0_SPI_RD_DATA_RST    0x0
#define RICU_PHY_0_SPI_STATUS_RC_0_SPI_WR_ADDR_RST    0x0
#define RICU_PHY_0_SPI_STATUS_RC_0_SPI_WR_DATA_RST    0x0

__INLINE void ricu_phy_0_spi_status_unpack(uint8_t* rc0_spi_rd_addr, uint8_t* rc0_spi_rd_data, uint8_t* rc0_spi_wr_addr, uint8_t* rc0_spi_wr_data)
{
	uint32_t localVal = REG_PL_RD(RICU_PHY_0_SPI_STATUS_ADDR);

	*rc0_spi_rd_addr = (localVal & ((uint32_t)0x7F000000)) >>  24;
	*rc0_spi_rd_data = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rc0_spi_wr_addr = (localVal & ((uint32_t)0x00007F00)) >>  8;
	*rc0_spi_wr_data = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t ricu_phy_0_spi_status_rc_0_spi_rd_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_PHY_0_SPI_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x7F000000)) >> 24);
}
__INLINE uint8_t ricu_phy_0_spi_status_rc_0_spi_rd_data_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_PHY_0_SPI_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE uint8_t ricu_phy_0_spi_status_rc_0_spi_wr_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_PHY_0_SPI_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007F00)) >> 8);
}
__INLINE uint8_t ricu_phy_0_spi_status_rc_0_spi_wr_data_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_PHY_0_SPI_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/**
 * @brief PHY_1_SPI_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    30:24 RC1_SPI_RD_ADDR           0x0
 *    23:16 RC1_SPI_RD_DATA           0x0
 *    14:08 RC1_SPI_WR_ADDR           0x0
 *    07:00 RC1_SPI_WR_DATA           0x0
 * </pre>
 */
#define RICU_PHY_1_SPI_STATUS_ADDR        (REG_RICU_BASE_ADDR+0x00000118)
#define RICU_PHY_1_SPI_STATUS_OFFSET      0x00000118
#define RICU_PHY_1_SPI_STATUS_INDEX       0x00000046
#define RICU_PHY_1_SPI_STATUS_RESET       0x00000000

__INLINE uint32_t  ricu_phy_1_spi_status_get(void)
{
	return REG_PL_RD(RICU_PHY_1_SPI_STATUS_ADDR);
}

// field definitions
#define RICU_PHY_1_SPI_STATUS_RC_1_SPI_RD_ADDR_MASK    ((uint32_t)0x7F000000)
#define RICU_PHY_1_SPI_STATUS_RC_1_SPI_RD_ADDR_LSB    24
#define RICU_PHY_1_SPI_STATUS_RC_1_SPI_RD_ADDR_WIDTH    ((uint32_t)0x00000007)
#define RICU_PHY_1_SPI_STATUS_RC_1_SPI_RD_DATA_MASK    ((uint32_t)0x00FF0000)
#define RICU_PHY_1_SPI_STATUS_RC_1_SPI_RD_DATA_LSB    16
#define RICU_PHY_1_SPI_STATUS_RC_1_SPI_RD_DATA_WIDTH    ((uint32_t)0x00000008)
#define RICU_PHY_1_SPI_STATUS_RC_1_SPI_WR_ADDR_MASK    ((uint32_t)0x00007F00)
#define RICU_PHY_1_SPI_STATUS_RC_1_SPI_WR_ADDR_LSB    8
#define RICU_PHY_1_SPI_STATUS_RC_1_SPI_WR_ADDR_WIDTH    ((uint32_t)0x00000007)
#define RICU_PHY_1_SPI_STATUS_RC_1_SPI_WR_DATA_MASK    ((uint32_t)0x000000FF)
#define RICU_PHY_1_SPI_STATUS_RC_1_SPI_WR_DATA_LSB    0
#define RICU_PHY_1_SPI_STATUS_RC_1_SPI_WR_DATA_WIDTH    ((uint32_t)0x00000008)

#define RICU_PHY_1_SPI_STATUS_RC_1_SPI_RD_ADDR_RST    0x0
#define RICU_PHY_1_SPI_STATUS_RC_1_SPI_RD_DATA_RST    0x0
#define RICU_PHY_1_SPI_STATUS_RC_1_SPI_WR_ADDR_RST    0x0
#define RICU_PHY_1_SPI_STATUS_RC_1_SPI_WR_DATA_RST    0x0

__INLINE void ricu_phy_1_spi_status_unpack(uint8_t* rc1_spi_rd_addr, uint8_t* rc1_spi_rd_data, uint8_t* rc1_spi_wr_addr, uint8_t* rc1_spi_wr_data)
{
	uint32_t localVal = REG_PL_RD(RICU_PHY_1_SPI_STATUS_ADDR);

	*rc1_spi_rd_addr = (localVal & ((uint32_t)0x7F000000)) >>  24;
	*rc1_spi_rd_data = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rc1_spi_wr_addr = (localVal & ((uint32_t)0x00007F00)) >>  8;
	*rc1_spi_wr_data = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t ricu_phy_1_spi_status_rc_1_spi_rd_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_PHY_1_SPI_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x7F000000)) >> 24);
}
__INLINE uint8_t ricu_phy_1_spi_status_rc_1_spi_rd_data_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_PHY_1_SPI_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE uint8_t ricu_phy_1_spi_status_rc_1_spi_wr_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_PHY_1_SPI_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007F00)) >> 8);
}
__INLINE uint8_t ricu_phy_1_spi_status_rc_1_spi_wr_data_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_PHY_1_SPI_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/**
 * @brief RF_SPI_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    30:24 RF_SPI_RD_ADDR            0x0
 *    23:16 RF_SPI_RD_DATA            0x0
 *    14:08 RF_SPI_WR_ADDR            0x0
 *    07:00 RF_SPI_WR_DATA            0x0
 * </pre>
 */
#define RICU_RF_SPI_STATUS_ADDR        (REG_RICU_BASE_ADDR+0x0000011C)
#define RICU_RF_SPI_STATUS_OFFSET      0x0000011C
#define RICU_RF_SPI_STATUS_INDEX       0x00000047
#define RICU_RF_SPI_STATUS_RESET       0x00000000

__INLINE uint32_t  ricu_rf_spi_status_get(void)
{
	return REG_PL_RD(RICU_RF_SPI_STATUS_ADDR);
}

// field definitions
#define RICU_RF_SPI_STATUS_RF_SPI_RD_ADDR_MASK    ((uint32_t)0x7F000000)
#define RICU_RF_SPI_STATUS_RF_SPI_RD_ADDR_LSB    24
#define RICU_RF_SPI_STATUS_RF_SPI_RD_ADDR_WIDTH    ((uint32_t)0x00000007)
#define RICU_RF_SPI_STATUS_RF_SPI_RD_DATA_MASK    ((uint32_t)0x00FF0000)
#define RICU_RF_SPI_STATUS_RF_SPI_RD_DATA_LSB    16
#define RICU_RF_SPI_STATUS_RF_SPI_RD_DATA_WIDTH    ((uint32_t)0x00000008)
#define RICU_RF_SPI_STATUS_RF_SPI_WR_ADDR_MASK    ((uint32_t)0x00007F00)
#define RICU_RF_SPI_STATUS_RF_SPI_WR_ADDR_LSB    8
#define RICU_RF_SPI_STATUS_RF_SPI_WR_ADDR_WIDTH    ((uint32_t)0x00000007)
#define RICU_RF_SPI_STATUS_RF_SPI_WR_DATA_MASK    ((uint32_t)0x000000FF)
#define RICU_RF_SPI_STATUS_RF_SPI_WR_DATA_LSB    0
#define RICU_RF_SPI_STATUS_RF_SPI_WR_DATA_WIDTH    ((uint32_t)0x00000008)

#define RICU_RF_SPI_STATUS_RF_SPI_RD_ADDR_RST    0x0
#define RICU_RF_SPI_STATUS_RF_SPI_RD_DATA_RST    0x0
#define RICU_RF_SPI_STATUS_RF_SPI_WR_ADDR_RST    0x0
#define RICU_RF_SPI_STATUS_RF_SPI_WR_DATA_RST    0x0

__INLINE void ricu_rf_spi_status_unpack(uint8_t* rf_spi_rd_addr, uint8_t* rf_spi_rd_data, uint8_t* rf_spi_wr_addr, uint8_t* rf_spi_wr_data)
{
	uint32_t localVal = REG_PL_RD(RICU_RF_SPI_STATUS_ADDR);

	*rf_spi_rd_addr = (localVal & ((uint32_t)0x7F000000)) >>  24;
	*rf_spi_rd_data = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rf_spi_wr_addr = (localVal & ((uint32_t)0x00007F00)) >>  8;
	*rf_spi_wr_data = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t ricu_rf_spi_status_rf_spi_rd_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_RF_SPI_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x7F000000)) >> 24);
}
__INLINE uint8_t ricu_rf_spi_status_rf_spi_rd_data_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_RF_SPI_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE uint8_t ricu_rf_spi_status_rf_spi_wr_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_RF_SPI_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007F00)) >> 8);
}
__INLINE uint8_t ricu_rf_spi_status_rf_spi_wr_data_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_RF_SPI_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/**
 * @brief FEM_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 FEM_STATUS                0x0
 * </pre>
 */
#define RICU_FEM_STATUS_ADDR        (REG_RICU_BASE_ADDR+0x00000120)
#define RICU_FEM_STATUS_OFFSET      0x00000120
#define RICU_FEM_STATUS_INDEX       0x00000048
#define RICU_FEM_STATUS_RESET       0x00000000

__INLINE uint32_t  ricu_fem_status_get(void)
{
	return REG_PL_RD(RICU_FEM_STATUS_ADDR);
}

// field definitions
#define RICU_FEM_STATUS_FEM_STATUS_MASK     ((uint32_t)0xFFFFFFFF)
#define RICU_FEM_STATUS_FEM_STATUS_LSB      0
#define RICU_FEM_STATUS_FEM_STATUS_WIDTH    ((uint32_t)0x00000020)

#define RICU_FEM_STATUS_FEM_STATUS_RST      0x0

__INLINE uint32_t ricu_fem_status_fem_status_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_FEM_STATUS_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BTC_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BTC_STATUS                0xF000000
 * </pre>
 */
#define RICU_BTC_STATUS_ADDR        (REG_RICU_BASE_ADDR+0x00000124)
#define RICU_BTC_STATUS_OFFSET      0x00000124
#define RICU_BTC_STATUS_INDEX       0x00000049
#define RICU_BTC_STATUS_RESET       0x0F000000

__INLINE uint32_t  ricu_btc_status_get(void)
{
	return REG_PL_RD(RICU_BTC_STATUS_ADDR);
}

// field definitions
#define RICU_BTC_STATUS_BTC_STATUS_MASK     ((uint32_t)0xFFFFFFFF)
#define RICU_BTC_STATUS_BTC_STATUS_LSB      0
#define RICU_BTC_STATUS_BTC_STATUS_WIDTH    ((uint32_t)0x00000020)

#define RICU_BTC_STATUS_BTC_STATUS_RST      0xF000000

__INLINE uint32_t ricu_btc_status_btc_status_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_BTC_STATUS_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief FSM_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    10:08 RSSI_SEQ                  0x0
 *    05:04 FWR_STATE                 0x0
 *    01:00 SPI_ARB_STATE             0x0
 * </pre>
 */
#define RICU_FSM_STATUS_ADDR        (REG_RICU_BASE_ADDR+0x00000128)
#define RICU_FSM_STATUS_OFFSET      0x00000128
#define RICU_FSM_STATUS_INDEX       0x0000004A
#define RICU_FSM_STATUS_RESET       0x00000000

__INLINE uint32_t  ricu_fsm_status_get(void)
{
	return REG_PL_RD(RICU_FSM_STATUS_ADDR);
}

// field definitions
#define RICU_FSM_STATUS_RSSI_SEQ_MASK       ((uint32_t)0x00000700)
#define RICU_FSM_STATUS_RSSI_SEQ_LSB        8
#define RICU_FSM_STATUS_RSSI_SEQ_WIDTH      ((uint32_t)0x00000003)
#define RICU_FSM_STATUS_FWR_STATE_MASK      ((uint32_t)0x00000030)
#define RICU_FSM_STATUS_FWR_STATE_LSB       4
#define RICU_FSM_STATUS_FWR_STATE_WIDTH     ((uint32_t)0x00000002)
#define RICU_FSM_STATUS_SPI_ARB_STATE_MASK    ((uint32_t)0x00000003)
#define RICU_FSM_STATUS_SPI_ARB_STATE_LSB    0
#define RICU_FSM_STATUS_SPI_ARB_STATE_WIDTH    ((uint32_t)0x00000002)

#define RICU_FSM_STATUS_RSSI_SEQ_RST        0x0
#define RICU_FSM_STATUS_FWR_STATE_RST       0x0
#define RICU_FSM_STATUS_SPI_ARB_STATE_RST    0x0

__INLINE void ricu_fsm_status_unpack(uint8_t* rssi_seq, uint8_t* fwr_state, uint8_t* spi_arb_state)
{
	uint32_t localVal = REG_PL_RD(RICU_FSM_STATUS_ADDR);

	*rssi_seq = (localVal & ((uint32_t)0x00000700)) >>  8;
	*fwr_state = (localVal & ((uint32_t)0x00000030)) >>  4;
	*spi_arb_state = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint8_t ricu_fsm_status_rssi_seq_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_FSM_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000700)) >> 8);
}
__INLINE uint8_t ricu_fsm_status_fwr_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_FSM_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000030)) >> 4);
}
__INLINE uint8_t ricu_fsm_status_spi_arb_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_FSM_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}

/**
 * @brief MICTOR_SEL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    07:04 MICTOR1_SEL               0x0
 *    03:00 MICTOR0_SEL               0x0
 * </pre>
 */
#define RICU_MICTOR_SEL_ADDR        (REG_RICU_BASE_ADDR+0x0000012C)
#define RICU_MICTOR_SEL_OFFSET      0x0000012C
#define RICU_MICTOR_SEL_INDEX       0x0000004B
#define RICU_MICTOR_SEL_RESET       0x00000000

__INLINE uint32_t  ricu_mictor_sel_get(void)
{
	return REG_PL_RD(RICU_MICTOR_SEL_ADDR);
}

__INLINE void ricu_mictor_sel_set(uint32_t value)
{
	REG_PL_WR(RICU_MICTOR_SEL_ADDR, value);
}

// field definitions
#define RICU_MICTOR_SEL_MICTOR_1_SEL_MASK    ((uint32_t)0x000000F0)
#define RICU_MICTOR_SEL_MICTOR_1_SEL_LSB    4
#define RICU_MICTOR_SEL_MICTOR_1_SEL_WIDTH    ((uint32_t)0x00000004)
#define RICU_MICTOR_SEL_MICTOR_0_SEL_MASK    ((uint32_t)0x0000000F)
#define RICU_MICTOR_SEL_MICTOR_0_SEL_LSB    0
#define RICU_MICTOR_SEL_MICTOR_0_SEL_WIDTH    ((uint32_t)0x00000004)

#define RICU_MICTOR_SEL_MICTOR_1_SEL_RST    0x0
#define RICU_MICTOR_SEL_MICTOR_0_SEL_RST    0x0

__INLINE void ricu_mictor_sel_pack(uint8_t mictor1_sel, uint8_t mictor0_sel)
{
	ASSERT_ERR((((uint32_t)mictor1_sel << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)mictor0_sel << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RICU_MICTOR_SEL_ADDR,  ((uint32_t)mictor1_sel << 4) |((uint32_t)mictor0_sel << 0));
}

__INLINE void ricu_mictor_sel_unpack(uint8_t* mictor1_sel, uint8_t* mictor0_sel)
{
	uint32_t localVal = REG_PL_RD(RICU_MICTOR_SEL_ADDR);

	*mictor1_sel = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*mictor0_sel = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t ricu_mictor_sel_mictor_1_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_MICTOR_SEL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE void ricu_mictor_sel_mictor_1_sel_setf(uint8_t mictor1sel)
{
	ASSERT_ERR((((uint32_t)mictor1sel << 4) & ~((uint32_t)0x000000F0)) == 0);
	REG_PL_WR(RICU_MICTOR_SEL_ADDR, (REG_PL_RD(RICU_MICTOR_SEL_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)mictor1sel <<4));
}
__INLINE uint8_t ricu_mictor_sel_mictor_0_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_MICTOR_SEL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void ricu_mictor_sel_mictor_0_sel_setf(uint8_t mictor0sel)
{
	ASSERT_ERR((((uint32_t)mictor0sel << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RICU_MICTOR_SEL_ADDR, (REG_PL_RD(RICU_MICTOR_SEL_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)mictor0sel <<0));
}

/**
 * @brief AUXADC_STAT_0 register definition
 *  auxadc data from fifo address 0 and 1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:12 auxadc_data1              0x0
 *    11:00 auxadc_data0              0x0
 * </pre>
 */
#define RICU_AUXADC_STAT_0_ADDR        (REG_RICU_BASE_ADDR+0x00000130)
#define RICU_AUXADC_STAT_0_OFFSET      0x00000130
#define RICU_AUXADC_STAT_0_INDEX       0x0000004C
#define RICU_AUXADC_STAT_0_RESET       0x00000000

__INLINE uint32_t  ricu_auxadc_stat_0_get(void)
{
	return REG_PL_RD(RICU_AUXADC_STAT_0_ADDR);
}

// field definitions
#define RICU_AUXADC_STAT_0_AUXADC_DATA_1_MASK    ((uint32_t)0x00FFF000)
#define RICU_AUXADC_STAT_0_AUXADC_DATA_1_LSB    12
#define RICU_AUXADC_STAT_0_AUXADC_DATA_1_WIDTH    ((uint32_t)0x0000000C)
#define RICU_AUXADC_STAT_0_AUXADC_DATA_0_MASK    ((uint32_t)0x00000FFF)
#define RICU_AUXADC_STAT_0_AUXADC_DATA_0_LSB    0
#define RICU_AUXADC_STAT_0_AUXADC_DATA_0_WIDTH    ((uint32_t)0x0000000C)

#define RICU_AUXADC_STAT_0_AUXADC_DATA_1_RST    0x0
#define RICU_AUXADC_STAT_0_AUXADC_DATA_0_RST    0x0

__INLINE void ricu_auxadc_stat_0_unpack(uint16_t* auxadc_data1, uint16_t* auxadc_data0)
{
	uint32_t localVal = REG_PL_RD(RICU_AUXADC_STAT_0_ADDR);

	*auxadc_data1 = (localVal & ((uint32_t)0x00FFF000)) >>  12;
	*auxadc_data0 = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t ricu_auxadc_stat_0_auxadc_data_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AUXADC_STAT_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00FFF000)) >> 12);
}
__INLINE uint16_t ricu_auxadc_stat_0_auxadc_data_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AUXADC_STAT_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}

/**
 * @brief AUXADC_STAT_1 register definition
 *  auxadc data from fifo address 2 and 3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:12 auxadc_data3              0x0
 *    11:00 auxadc_data2              0x0
 * </pre>
 */
#define RICU_AUXADC_STAT_1_ADDR        (REG_RICU_BASE_ADDR+0x00000134)
#define RICU_AUXADC_STAT_1_OFFSET      0x00000134
#define RICU_AUXADC_STAT_1_INDEX       0x0000004D
#define RICU_AUXADC_STAT_1_RESET       0x00000000

__INLINE uint32_t  ricu_auxadc_stat_1_get(void)
{
	return REG_PL_RD(RICU_AUXADC_STAT_1_ADDR);
}

// field definitions
#define RICU_AUXADC_STAT_1_AUXADC_DATA_3_MASK    ((uint32_t)0x00FFF000)
#define RICU_AUXADC_STAT_1_AUXADC_DATA_3_LSB    12
#define RICU_AUXADC_STAT_1_AUXADC_DATA_3_WIDTH    ((uint32_t)0x0000000C)
#define RICU_AUXADC_STAT_1_AUXADC_DATA_2_MASK    ((uint32_t)0x00000FFF)
#define RICU_AUXADC_STAT_1_AUXADC_DATA_2_LSB    0
#define RICU_AUXADC_STAT_1_AUXADC_DATA_2_WIDTH    ((uint32_t)0x0000000C)

#define RICU_AUXADC_STAT_1_AUXADC_DATA_3_RST    0x0
#define RICU_AUXADC_STAT_1_AUXADC_DATA_2_RST    0x0

__INLINE void ricu_auxadc_stat_1_unpack(uint16_t* auxadc_data3, uint16_t* auxadc_data2)
{
	uint32_t localVal = REG_PL_RD(RICU_AUXADC_STAT_1_ADDR);

	*auxadc_data3 = (localVal & ((uint32_t)0x00FFF000)) >>  12;
	*auxadc_data2 = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t ricu_auxadc_stat_1_auxadc_data_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AUXADC_STAT_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00FFF000)) >> 12);
}
__INLINE uint16_t ricu_auxadc_stat_1_auxadc_data_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AUXADC_STAT_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}

/**
 * @brief AUXADC_STAT_2 register definition
 *  auxadc data from fifo address 4 and 5 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:12 auxadc_data5              0x0
 *    11:00 auxadc_data4              0x0
 * </pre>
 */
#define RICU_AUXADC_STAT_2_ADDR        (REG_RICU_BASE_ADDR+0x00000138)
#define RICU_AUXADC_STAT_2_OFFSET      0x00000138
#define RICU_AUXADC_STAT_2_INDEX       0x0000004E
#define RICU_AUXADC_STAT_2_RESET       0x00000000

__INLINE uint32_t  ricu_auxadc_stat_2_get(void)
{
	return REG_PL_RD(RICU_AUXADC_STAT_2_ADDR);
}

// field definitions
#define RICU_AUXADC_STAT_2_AUXADC_DATA_5_MASK    ((uint32_t)0x00FFF000)
#define RICU_AUXADC_STAT_2_AUXADC_DATA_5_LSB    12
#define RICU_AUXADC_STAT_2_AUXADC_DATA_5_WIDTH    ((uint32_t)0x0000000C)
#define RICU_AUXADC_STAT_2_AUXADC_DATA_4_MASK    ((uint32_t)0x00000FFF)
#define RICU_AUXADC_STAT_2_AUXADC_DATA_4_LSB    0
#define RICU_AUXADC_STAT_2_AUXADC_DATA_4_WIDTH    ((uint32_t)0x0000000C)

#define RICU_AUXADC_STAT_2_AUXADC_DATA_5_RST    0x0
#define RICU_AUXADC_STAT_2_AUXADC_DATA_4_RST    0x0

__INLINE void ricu_auxadc_stat_2_unpack(uint16_t* auxadc_data5, uint16_t* auxadc_data4)
{
	uint32_t localVal = REG_PL_RD(RICU_AUXADC_STAT_2_ADDR);

	*auxadc_data5 = (localVal & ((uint32_t)0x00FFF000)) >>  12;
	*auxadc_data4 = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t ricu_auxadc_stat_2_auxadc_data_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AUXADC_STAT_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00FFF000)) >> 12);
}
__INLINE uint16_t ricu_auxadc_stat_2_auxadc_data_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AUXADC_STAT_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}

/**
 * @brief AUXADC_STAT_3 register definition
 *  auxadc cur fifo address and data from add 6 and 7 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26:24 auxadc_wr_ptr             0x0
 *    23:12 auxadc_data7              0x0
 *    11:00 auxadc_data6              0x0
 * </pre>
 */
#define RICU_AUXADC_STAT_3_ADDR        (REG_RICU_BASE_ADDR+0x0000013C)
#define RICU_AUXADC_STAT_3_OFFSET      0x0000013C
#define RICU_AUXADC_STAT_3_INDEX       0x0000004F
#define RICU_AUXADC_STAT_3_RESET       0x00000000

__INLINE uint32_t  ricu_auxadc_stat_3_get(void)
{
	return REG_PL_RD(RICU_AUXADC_STAT_3_ADDR);
}

// field definitions
#define RICU_AUXADC_STAT_3_AUXADC_WR_PTR_MASK    ((uint32_t)0x07000000)
#define RICU_AUXADC_STAT_3_AUXADC_WR_PTR_LSB    24
#define RICU_AUXADC_STAT_3_AUXADC_WR_PTR_WIDTH    ((uint32_t)0x00000003)
#define RICU_AUXADC_STAT_3_AUXADC_DATA_7_MASK    ((uint32_t)0x00FFF000)
#define RICU_AUXADC_STAT_3_AUXADC_DATA_7_LSB    12
#define RICU_AUXADC_STAT_3_AUXADC_DATA_7_WIDTH    ((uint32_t)0x0000000C)
#define RICU_AUXADC_STAT_3_AUXADC_DATA_6_MASK    ((uint32_t)0x00000FFF)
#define RICU_AUXADC_STAT_3_AUXADC_DATA_6_LSB    0
#define RICU_AUXADC_STAT_3_AUXADC_DATA_6_WIDTH    ((uint32_t)0x0000000C)

#define RICU_AUXADC_STAT_3_AUXADC_WR_PTR_RST    0x0
#define RICU_AUXADC_STAT_3_AUXADC_DATA_7_RST    0x0
#define RICU_AUXADC_STAT_3_AUXADC_DATA_6_RST    0x0

__INLINE void ricu_auxadc_stat_3_unpack(uint8_t* auxadc_wr_ptr, uint16_t* auxadc_data7, uint16_t* auxadc_data6)
{
	uint32_t localVal = REG_PL_RD(RICU_AUXADC_STAT_3_ADDR);

	*auxadc_wr_ptr = (localVal & ((uint32_t)0x07000000)) >>  24;
	*auxadc_data7 = (localVal & ((uint32_t)0x00FFF000)) >>  12;
	*auxadc_data6 = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint8_t ricu_auxadc_stat_3_auxadc_wr_ptr_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AUXADC_STAT_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE uint16_t ricu_auxadc_stat_3_auxadc_data_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AUXADC_STAT_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00FFF000)) >> 12);
}
__INLINE uint16_t ricu_auxadc_stat_3_auxadc_data_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(RICU_AUXADC_STAT_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}


#undef DBG_FILEID
#endif //_REG_RICU_H_

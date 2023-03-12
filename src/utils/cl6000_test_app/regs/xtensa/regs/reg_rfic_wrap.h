#ifndef _REG_RFIC_WRAP_H_
#define _REG_RFIC_WRAP_H_

#include <stdint.h>
#include "_reg_rfic_wrap.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define DBG_FILEID __REG_RFIC_WRAP__H__FILEID__

#define REG_RFIC_WRAP_COUNT  133


/**
 * @brief WIFI_DAC_SW_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    14    DAC1_TEST_PATTERN         0              
 *    13    DAC1_PDN_OVR_VAL          0              
 *    12    DAC1_PDN_OVR_EN           1              
 *    11    DAC1_STANDBYNI_OVR_VAL    0              
 *    10    DAC1_STANDBYNI_OVR_EN     1              
 *    09    DAC1_STANDBYNQ_OVR_VAL    0              
 *    08    DAC1_STANDBYNQ_OVR_EN     1              
 *    06    DAC0_TEST_PATTERN         0              
 *    05    DAC0_PDN_OVR_VAL          0              
 *    04    DAC0_PDN_OVR_EN           1              
 *    03    DAC0_STANDBYNI_OVR_VAL    0              
 *    02    DAC0_STANDBYNI_OVR_EN     1              
 *    01    DAC0_STANDBYNQ_OVR_VAL    0              
 *    00    DAC0_STANDBYNQ_OVR_EN     1              
 * </pre>
 */
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000000)
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_OFFSET      0x00000000
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_INDEX       0x00000000
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_RESET       0x00001515

__INLINE uint32_t  rfic_wrap_wifi_dac_sw_ctrl_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR);
}

__INLINE void rfic_wrap_wifi_dac_sw_ctrl_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_DAC_1_TEST_PATTERN_BIT    ((uint32_t)0x00004000)
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_DAC_1_TEST_PATTERN_POS    14
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_DAC_1_PDN_OVR_VAL_BIT    ((uint32_t)0x00002000)
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_DAC_1_PDN_OVR_VAL_POS    13
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_DAC_1_PDN_OVR_EN_BIT    ((uint32_t)0x00001000)
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_DAC_1_PDN_OVR_EN_POS    12
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_DAC_1_STANDBYNI_OVR_VAL_BIT    ((uint32_t)0x00000800)
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_DAC_1_STANDBYNI_OVR_VAL_POS    11
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_DAC_1_STANDBYNI_OVR_EN_BIT    ((uint32_t)0x00000400)
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_DAC_1_STANDBYNI_OVR_EN_POS    10
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_DAC_1_STANDBYNQ_OVR_VAL_BIT    ((uint32_t)0x00000200)
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_DAC_1_STANDBYNQ_OVR_VAL_POS    9
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_DAC_1_STANDBYNQ_OVR_EN_BIT    ((uint32_t)0x00000100)
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_DAC_1_STANDBYNQ_OVR_EN_POS    8
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_DAC_0_TEST_PATTERN_BIT    ((uint32_t)0x00000040)
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_DAC_0_TEST_PATTERN_POS    6
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_DAC_0_PDN_OVR_VAL_BIT    ((uint32_t)0x00000020)
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_DAC_0_PDN_OVR_VAL_POS    5
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_DAC_0_PDN_OVR_EN_BIT    ((uint32_t)0x00000010)
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_DAC_0_PDN_OVR_EN_POS    4
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_DAC_0_STANDBYNI_OVR_VAL_BIT    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_DAC_0_STANDBYNI_OVR_VAL_POS    3
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_DAC_0_STANDBYNI_OVR_EN_BIT    ((uint32_t)0x00000004)
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_DAC_0_STANDBYNI_OVR_EN_POS    2
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_DAC_0_STANDBYNQ_OVR_VAL_BIT    ((uint32_t)0x00000002)
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_DAC_0_STANDBYNQ_OVR_VAL_POS    1
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_DAC_0_STANDBYNQ_OVR_EN_BIT    ((uint32_t)0x00000001)
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_DAC_0_STANDBYNQ_OVR_EN_POS    0

#define RFIC_WRAP_WIFI_DAC_SW_CTRL_DAC_1_TEST_PATTERN_RST    0x0
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_DAC_1_PDN_OVR_VAL_RST    0x0
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_DAC_1_PDN_OVR_EN_RST    0x1
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_DAC_1_STANDBYNI_OVR_VAL_RST    0x0
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_DAC_1_STANDBYNI_OVR_EN_RST    0x1
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_DAC_1_STANDBYNQ_OVR_VAL_RST    0x0
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_DAC_1_STANDBYNQ_OVR_EN_RST    0x1
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_DAC_0_TEST_PATTERN_RST    0x0
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_DAC_0_PDN_OVR_VAL_RST    0x0
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_DAC_0_PDN_OVR_EN_RST    0x1
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_DAC_0_STANDBYNI_OVR_VAL_RST    0x0
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_DAC_0_STANDBYNI_OVR_EN_RST    0x1
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_DAC_0_STANDBYNQ_OVR_VAL_RST    0x0
#define RFIC_WRAP_WIFI_DAC_SW_CTRL_DAC_0_STANDBYNQ_OVR_EN_RST    0x1

__INLINE void rfic_wrap_wifi_dac_sw_ctrl_pack(uint8_t dac1_test_pattern, uint8_t dac1_pdn_ovr_val, uint8_t dac1_pdn_ovr_en, uint8_t dac1_standbyni_ovr_val, uint8_t dac1_standbyni_ovr_en, uint8_t dac1_standbynq_ovr_val, uint8_t dac1_standbynq_ovr_en, uint8_t dac0_test_pattern, uint8_t dac0_pdn_ovr_val, uint8_t dac0_pdn_ovr_en, uint8_t dac0_standbyni_ovr_val, uint8_t dac0_standbyni_ovr_en, uint8_t dac0_standbynq_ovr_val, uint8_t dac0_standbynq_ovr_en)
{
	ASSERT_ERR((((uint32_t)dac1_test_pattern << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)dac1_pdn_ovr_val << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)dac1_pdn_ovr_en << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)dac1_standbyni_ovr_val << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)dac1_standbyni_ovr_en << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)dac1_standbynq_ovr_val << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)dac1_standbynq_ovr_en << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)dac0_test_pattern << 6) & ~((uint32_t)0x00000040)) == 0);
	ASSERT_ERR((((uint32_t)dac0_pdn_ovr_val << 5) & ~((uint32_t)0x00000020)) == 0);
	ASSERT_ERR((((uint32_t)dac0_pdn_ovr_en << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)dac0_standbyni_ovr_val << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)dac0_standbyni_ovr_en << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)dac0_standbynq_ovr_val << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)dac0_standbynq_ovr_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR,  ((uint32_t)dac1_test_pattern << 14) |((uint32_t)dac1_pdn_ovr_val << 13) |((uint32_t)dac1_pdn_ovr_en << 12) |((uint32_t)dac1_standbyni_ovr_val << 11) |((uint32_t)dac1_standbyni_ovr_en << 10) |((uint32_t)dac1_standbynq_ovr_val << 9) |((uint32_t)dac1_standbynq_ovr_en << 8) |((uint32_t)dac0_test_pattern << 6) |((uint32_t)dac0_pdn_ovr_val << 5) |((uint32_t)dac0_pdn_ovr_en << 4) |((uint32_t)dac0_standbyni_ovr_val << 3) |((uint32_t)dac0_standbyni_ovr_en << 2) |((uint32_t)dac0_standbynq_ovr_val << 1) |((uint32_t)dac0_standbynq_ovr_en << 0));
}

__INLINE void rfic_wrap_wifi_dac_sw_ctrl_unpack(uint8_t* dac1_test_pattern, uint8_t* dac1_pdn_ovr_val, uint8_t* dac1_pdn_ovr_en, uint8_t* dac1_standbyni_ovr_val, uint8_t* dac1_standbyni_ovr_en, uint8_t* dac1_standbynq_ovr_val, uint8_t* dac1_standbynq_ovr_en, uint8_t* dac0_test_pattern, uint8_t* dac0_pdn_ovr_val, uint8_t* dac0_pdn_ovr_en, uint8_t* dac0_standbyni_ovr_val, uint8_t* dac0_standbyni_ovr_en, uint8_t* dac0_standbynq_ovr_val, uint8_t* dac0_standbynq_ovr_en)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR);

	*dac1_test_pattern = (localVal & ((uint32_t)0x00004000)) >>  14;
	*dac1_pdn_ovr_val = (localVal & ((uint32_t)0x00002000)) >>  13;
	*dac1_pdn_ovr_en = (localVal & ((uint32_t)0x00001000)) >>  12;
	*dac1_standbyni_ovr_val = (localVal & ((uint32_t)0x00000800)) >>  11;
	*dac1_standbyni_ovr_en = (localVal & ((uint32_t)0x00000400)) >>  10;
	*dac1_standbynq_ovr_val = (localVal & ((uint32_t)0x00000200)) >>  9;
	*dac1_standbynq_ovr_en = (localVal & ((uint32_t)0x00000100)) >>  8;
	*dac0_test_pattern = (localVal & ((uint32_t)0x00000040)) >>  6;
	*dac0_pdn_ovr_val = (localVal & ((uint32_t)0x00000020)) >>  5;
	*dac0_pdn_ovr_en = (localVal & ((uint32_t)0x00000010)) >>  4;
	*dac0_standbyni_ovr_val = (localVal & ((uint32_t)0x00000008)) >>  3;
	*dac0_standbyni_ovr_en = (localVal & ((uint32_t)0x00000004)) >>  2;
	*dac0_standbynq_ovr_val = (localVal & ((uint32_t)0x00000002)) >>  1;
	*dac0_standbynq_ovr_en = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_dac_sw_ctrl_dac_1_test_pattern_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void rfic_wrap_wifi_dac_sw_ctrl_dac_1_test_pattern_setf(uint8_t dac1testpattern)
{
	ASSERT_ERR((((uint32_t)dac1testpattern << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)dac1testpattern <<14));
}
__INLINE uint8_t rfic_wrap_wifi_dac_sw_ctrl_dac_1_pdn_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void rfic_wrap_wifi_dac_sw_ctrl_dac_1_pdn_ovr_val_setf(uint8_t dac1pdnovrval)
{
	ASSERT_ERR((((uint32_t)dac1pdnovrval << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)dac1pdnovrval <<13));
}
__INLINE uint8_t rfic_wrap_wifi_dac_sw_ctrl_dac_1_pdn_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void rfic_wrap_wifi_dac_sw_ctrl_dac_1_pdn_ovr_en_setf(uint8_t dac1pdnovren)
{
	ASSERT_ERR((((uint32_t)dac1pdnovren << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)dac1pdnovren <<12));
}
__INLINE uint8_t rfic_wrap_wifi_dac_sw_ctrl_dac_1_standbyni_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void rfic_wrap_wifi_dac_sw_ctrl_dac_1_standbyni_ovr_val_setf(uint8_t dac1standbyniovrval)
{
	ASSERT_ERR((((uint32_t)dac1standbyniovrval << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)dac1standbyniovrval <<11));
}
__INLINE uint8_t rfic_wrap_wifi_dac_sw_ctrl_dac_1_standbyni_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void rfic_wrap_wifi_dac_sw_ctrl_dac_1_standbyni_ovr_en_setf(uint8_t dac1standbyniovren)
{
	ASSERT_ERR((((uint32_t)dac1standbyniovren << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)dac1standbyniovren <<10));
}
__INLINE uint8_t rfic_wrap_wifi_dac_sw_ctrl_dac_1_standbynq_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void rfic_wrap_wifi_dac_sw_ctrl_dac_1_standbynq_ovr_val_setf(uint8_t dac1standbynqovrval)
{
	ASSERT_ERR((((uint32_t)dac1standbynqovrval << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)dac1standbynqovrval <<9));
}
__INLINE uint8_t rfic_wrap_wifi_dac_sw_ctrl_dac_1_standbynq_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void rfic_wrap_wifi_dac_sw_ctrl_dac_1_standbynq_ovr_en_setf(uint8_t dac1standbynqovren)
{
	ASSERT_ERR((((uint32_t)dac1standbynqovren << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)dac1standbynqovren <<8));
}
__INLINE uint8_t rfic_wrap_wifi_dac_sw_ctrl_dac_0_test_pattern_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE void rfic_wrap_wifi_dac_sw_ctrl_dac_0_test_pattern_setf(uint8_t dac0testpattern)
{
	ASSERT_ERR((((uint32_t)dac0testpattern << 6) & ~((uint32_t)0x00000040)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)dac0testpattern <<6));
}
__INLINE uint8_t rfic_wrap_wifi_dac_sw_ctrl_dac_0_pdn_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE void rfic_wrap_wifi_dac_sw_ctrl_dac_0_pdn_ovr_val_setf(uint8_t dac0pdnovrval)
{
	ASSERT_ERR((((uint32_t)dac0pdnovrval << 5) & ~((uint32_t)0x00000020)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)dac0pdnovrval <<5));
}
__INLINE uint8_t rfic_wrap_wifi_dac_sw_ctrl_dac_0_pdn_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void rfic_wrap_wifi_dac_sw_ctrl_dac_0_pdn_ovr_en_setf(uint8_t dac0pdnovren)
{
	ASSERT_ERR((((uint32_t)dac0pdnovren << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)dac0pdnovren <<4));
}
__INLINE uint8_t rfic_wrap_wifi_dac_sw_ctrl_dac_0_standbyni_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void rfic_wrap_wifi_dac_sw_ctrl_dac_0_standbyni_ovr_val_setf(uint8_t dac0standbyniovrval)
{
	ASSERT_ERR((((uint32_t)dac0standbyniovrval << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)dac0standbyniovrval <<3));
}
__INLINE uint8_t rfic_wrap_wifi_dac_sw_ctrl_dac_0_standbyni_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void rfic_wrap_wifi_dac_sw_ctrl_dac_0_standbyni_ovr_en_setf(uint8_t dac0standbyniovren)
{
	ASSERT_ERR((((uint32_t)dac0standbyniovren << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)dac0standbyniovren <<2));
}
__INLINE uint8_t rfic_wrap_wifi_dac_sw_ctrl_dac_0_standbynq_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void rfic_wrap_wifi_dac_sw_ctrl_dac_0_standbynq_ovr_val_setf(uint8_t dac0standbynqovrval)
{
	ASSERT_ERR((((uint32_t)dac0standbynqovrval << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)dac0standbynqovrval <<1));
}
__INLINE uint8_t rfic_wrap_wifi_dac_sw_ctrl_dac_0_standbynq_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void rfic_wrap_wifi_dac_sw_ctrl_dac_0_standbynq_ovr_en_setf(uint8_t dac0standbynqovren)
{
	ASSERT_ERR((((uint32_t)dac0standbynqovren << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_DAC_SW_CTRL_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)dac0standbynqovren <<0));
}

/**
 * @brief WIFI_ADC_SW_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    17    ADC_DATA_EN_OVR_VAL       0              
 *    16    ADC_DATA_EN_OVR_EN        1              
 *    11    ADC1_CALN                 0              
 *    10:09 ADC1_EN_OVR_VAL           0x0
 *    08    ADC1_EN_OVR_EN            1              
 *    03    ADC0_CALN                 0              
 *    02:01 ADC0_EN_OVR_VAL           0x0
 *    00    ADC0_EN_OVR_EN            1              
 * </pre>
 */
#define RFIC_WRAP_WIFI_ADC_SW_CTRL_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000004)
#define RFIC_WRAP_WIFI_ADC_SW_CTRL_OFFSET      0x00000004
#define RFIC_WRAP_WIFI_ADC_SW_CTRL_INDEX       0x00000001
#define RFIC_WRAP_WIFI_ADC_SW_CTRL_RESET       0x00010101

__INLINE uint32_t  rfic_wrap_wifi_adc_sw_ctrl_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_ADC_SW_CTRL_ADDR);
}

__INLINE void rfic_wrap_wifi_adc_sw_ctrl_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_ADC_SW_CTRL_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_ADC_SW_CTRL_ADC_DATA_EN_OVR_VAL_BIT    ((uint32_t)0x00020000)
#define RFIC_WRAP_WIFI_ADC_SW_CTRL_ADC_DATA_EN_OVR_VAL_POS    17
#define RFIC_WRAP_WIFI_ADC_SW_CTRL_ADC_DATA_EN_OVR_EN_BIT    ((uint32_t)0x00010000)
#define RFIC_WRAP_WIFI_ADC_SW_CTRL_ADC_DATA_EN_OVR_EN_POS    16
#define RFIC_WRAP_WIFI_ADC_SW_CTRL_ADC_1_CALN_BIT    ((uint32_t)0x00000800)
#define RFIC_WRAP_WIFI_ADC_SW_CTRL_ADC_1_CALN_POS    11
#define RFIC_WRAP_WIFI_ADC_SW_CTRL_ADC_1_EN_OVR_VAL_MASK    ((uint32_t)0x00000600)
#define RFIC_WRAP_WIFI_ADC_SW_CTRL_ADC_1_EN_OVR_VAL_LSB    9
#define RFIC_WRAP_WIFI_ADC_SW_CTRL_ADC_1_EN_OVR_VAL_WIDTH    ((uint32_t)0x00000002)
#define RFIC_WRAP_WIFI_ADC_SW_CTRL_ADC_1_EN_OVR_EN_BIT    ((uint32_t)0x00000100)
#define RFIC_WRAP_WIFI_ADC_SW_CTRL_ADC_1_EN_OVR_EN_POS    8
#define RFIC_WRAP_WIFI_ADC_SW_CTRL_ADC_0_CALN_BIT    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_ADC_SW_CTRL_ADC_0_CALN_POS    3
#define RFIC_WRAP_WIFI_ADC_SW_CTRL_ADC_0_EN_OVR_VAL_MASK    ((uint32_t)0x00000006)
#define RFIC_WRAP_WIFI_ADC_SW_CTRL_ADC_0_EN_OVR_VAL_LSB    1
#define RFIC_WRAP_WIFI_ADC_SW_CTRL_ADC_0_EN_OVR_VAL_WIDTH    ((uint32_t)0x00000002)
#define RFIC_WRAP_WIFI_ADC_SW_CTRL_ADC_0_EN_OVR_EN_BIT    ((uint32_t)0x00000001)
#define RFIC_WRAP_WIFI_ADC_SW_CTRL_ADC_0_EN_OVR_EN_POS    0

#define RFIC_WRAP_WIFI_ADC_SW_CTRL_ADC_DATA_EN_OVR_VAL_RST    0x0
#define RFIC_WRAP_WIFI_ADC_SW_CTRL_ADC_DATA_EN_OVR_EN_RST    0x1
#define RFIC_WRAP_WIFI_ADC_SW_CTRL_ADC_1_CALN_RST    0x0
#define RFIC_WRAP_WIFI_ADC_SW_CTRL_ADC_1_EN_OVR_VAL_RST    0x0
#define RFIC_WRAP_WIFI_ADC_SW_CTRL_ADC_1_EN_OVR_EN_RST    0x1
#define RFIC_WRAP_WIFI_ADC_SW_CTRL_ADC_0_CALN_RST    0x0
#define RFIC_WRAP_WIFI_ADC_SW_CTRL_ADC_0_EN_OVR_VAL_RST    0x0
#define RFIC_WRAP_WIFI_ADC_SW_CTRL_ADC_0_EN_OVR_EN_RST    0x1

__INLINE void rfic_wrap_wifi_adc_sw_ctrl_pack(uint8_t adc_data_en_ovr_val, uint8_t adc_data_en_ovr_en, uint8_t adc1_caln, uint8_t adc1_en_ovr_val, uint8_t adc1_en_ovr_en, uint8_t adc0_caln, uint8_t adc0_en_ovr_val, uint8_t adc0_en_ovr_en)
{
	ASSERT_ERR((((uint32_t)adc_data_en_ovr_val << 17) & ~((uint32_t)0x00020000)) == 0);
	ASSERT_ERR((((uint32_t)adc_data_en_ovr_en << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)adc1_caln << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)adc1_en_ovr_val << 9) & ~((uint32_t)0x00000600)) == 0);
	ASSERT_ERR((((uint32_t)adc1_en_ovr_en << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)adc0_caln << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)adc0_en_ovr_val << 1) & ~((uint32_t)0x00000006)) == 0);
	ASSERT_ERR((((uint32_t)adc0_en_ovr_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_ADC_SW_CTRL_ADDR,  ((uint32_t)adc_data_en_ovr_val << 17) |((uint32_t)adc_data_en_ovr_en << 16) |((uint32_t)adc1_caln << 11) |((uint32_t)adc1_en_ovr_val << 9) |((uint32_t)adc1_en_ovr_en << 8) |((uint32_t)adc0_caln << 3) |((uint32_t)adc0_en_ovr_val << 1) |((uint32_t)adc0_en_ovr_en << 0));
}

__INLINE void rfic_wrap_wifi_adc_sw_ctrl_unpack(uint8_t* adc_data_en_ovr_val, uint8_t* adc_data_en_ovr_en, uint8_t* adc1_caln, uint8_t* adc1_en_ovr_val, uint8_t* adc1_en_ovr_en, uint8_t* adc0_caln, uint8_t* adc0_en_ovr_val, uint8_t* adc0_en_ovr_en)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_ADC_SW_CTRL_ADDR);

	*adc_data_en_ovr_val = (localVal & ((uint32_t)0x00020000)) >>  17;
	*adc_data_en_ovr_en = (localVal & ((uint32_t)0x00010000)) >>  16;
	*adc1_caln = (localVal & ((uint32_t)0x00000800)) >>  11;
	*adc1_en_ovr_val = (localVal & ((uint32_t)0x00000600)) >>  9;
	*adc1_en_ovr_en = (localVal & ((uint32_t)0x00000100)) >>  8;
	*adc0_caln = (localVal & ((uint32_t)0x00000008)) >>  3;
	*adc0_en_ovr_val = (localVal & ((uint32_t)0x00000006)) >>  1;
	*adc0_en_ovr_en = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_adc_sw_ctrl_adc_data_en_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_ADC_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00020000)) >> 17);
}
__INLINE void rfic_wrap_wifi_adc_sw_ctrl_adc_data_en_ovr_val_setf(uint8_t adcdataenovrval)
{
	ASSERT_ERR((((uint32_t)adcdataenovrval << 17) & ~((uint32_t)0x00020000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_ADC_SW_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_ADC_SW_CTRL_ADDR) & ~((uint32_t)0x00020000)) | ((uint32_t)adcdataenovrval <<17));
}
__INLINE uint8_t rfic_wrap_wifi_adc_sw_ctrl_adc_data_en_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_ADC_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void rfic_wrap_wifi_adc_sw_ctrl_adc_data_en_ovr_en_setf(uint8_t adcdataenovren)
{
	ASSERT_ERR((((uint32_t)adcdataenovren << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_ADC_SW_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_ADC_SW_CTRL_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)adcdataenovren <<16));
}
__INLINE uint8_t rfic_wrap_wifi_adc_sw_ctrl_adc_1_caln_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_ADC_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void rfic_wrap_wifi_adc_sw_ctrl_adc_1_caln_setf(uint8_t adc1caln)
{
	ASSERT_ERR((((uint32_t)adc1caln << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_ADC_SW_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_ADC_SW_CTRL_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)adc1caln <<11));
}
__INLINE uint8_t rfic_wrap_wifi_adc_sw_ctrl_adc_1_en_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_ADC_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000600)) >> 9);
}
__INLINE void rfic_wrap_wifi_adc_sw_ctrl_adc_1_en_ovr_val_setf(uint8_t adc1enovrval)
{
	ASSERT_ERR((((uint32_t)adc1enovrval << 9) & ~((uint32_t)0x00000600)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_ADC_SW_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_ADC_SW_CTRL_ADDR) & ~((uint32_t)0x00000600)) | ((uint32_t)adc1enovrval <<9));
}
__INLINE uint8_t rfic_wrap_wifi_adc_sw_ctrl_adc_1_en_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_ADC_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void rfic_wrap_wifi_adc_sw_ctrl_adc_1_en_ovr_en_setf(uint8_t adc1enovren)
{
	ASSERT_ERR((((uint32_t)adc1enovren << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_ADC_SW_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_ADC_SW_CTRL_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)adc1enovren <<8));
}
__INLINE uint8_t rfic_wrap_wifi_adc_sw_ctrl_adc_0_caln_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_ADC_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void rfic_wrap_wifi_adc_sw_ctrl_adc_0_caln_setf(uint8_t adc0caln)
{
	ASSERT_ERR((((uint32_t)adc0caln << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_ADC_SW_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_ADC_SW_CTRL_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)adc0caln <<3));
}
__INLINE uint8_t rfic_wrap_wifi_adc_sw_ctrl_adc_0_en_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_ADC_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000006)) >> 1);
}
__INLINE void rfic_wrap_wifi_adc_sw_ctrl_adc_0_en_ovr_val_setf(uint8_t adc0enovrval)
{
	ASSERT_ERR((((uint32_t)adc0enovrval << 1) & ~((uint32_t)0x00000006)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_ADC_SW_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_ADC_SW_CTRL_ADDR) & ~((uint32_t)0x00000006)) | ((uint32_t)adc0enovrval <<1));
}
__INLINE uint8_t rfic_wrap_wifi_adc_sw_ctrl_adc_0_en_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_ADC_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void rfic_wrap_wifi_adc_sw_ctrl_adc_0_en_ovr_en_setf(uint8_t adc0enovren)
{
	ASSERT_ERR((((uint32_t)adc0enovren << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_ADC_SW_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_ADC_SW_CTRL_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)adc0enovren <<0));
}

/**
 * @brief WIFI_RF_TX_SW_CTRL_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    13    CH1_RF_TR_SW_OVR_VAL      0              
 *    12    CH1_RF_TR_SW_OVR_EN       1              
 *    11    CH1_RF_PA_EN_OVR_VAL      0              
 *    10    CH1_RF_PA_EN_OVR_EN       1              
 *    09    CH1_RF_TX_EN_OVR_VAL      0              
 *    08    CH1_RF_TX_EN_OVR_EN       1              
 *    05    CH0_RF_TR_SW_OVR_VAL      0              
 *    04    CH0_RF_TR_SW_OVR_EN       1              
 *    03    CH0_RF_PA_EN_OVR_VAL      0              
 *    02    CH0_RF_PA_EN_OVR_EN       1              
 *    01    CH0_RF_TX_EN_OVR_VAL      0              
 *    00    CH0_RF_TX_EN_OVR_EN       1              
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000008)
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_OFFSET      0x00000008
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_INDEX       0x00000002
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_RESET       0x00001515

__INLINE uint32_t  rfic_wrap_wifi_rf_tx_sw_ctrl_0_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_tx_sw_ctrl_0_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_CH_1_RF_TR_SW_OVR_VAL_BIT    ((uint32_t)0x00002000)
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_CH_1_RF_TR_SW_OVR_VAL_POS    13
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_CH_1_RF_TR_SW_OVR_EN_BIT    ((uint32_t)0x00001000)
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_CH_1_RF_TR_SW_OVR_EN_POS    12
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_CH_1_RF_PA_EN_OVR_VAL_BIT    ((uint32_t)0x00000800)
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_CH_1_RF_PA_EN_OVR_VAL_POS    11
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_CH_1_RF_PA_EN_OVR_EN_BIT    ((uint32_t)0x00000400)
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_CH_1_RF_PA_EN_OVR_EN_POS    10
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_CH_1_RF_TX_EN_OVR_VAL_BIT    ((uint32_t)0x00000200)
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_CH_1_RF_TX_EN_OVR_VAL_POS    9
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_CH_1_RF_TX_EN_OVR_EN_BIT    ((uint32_t)0x00000100)
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_CH_1_RF_TX_EN_OVR_EN_POS    8
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_CH_0_RF_TR_SW_OVR_VAL_BIT    ((uint32_t)0x00000020)
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_CH_0_RF_TR_SW_OVR_VAL_POS    5
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_CH_0_RF_TR_SW_OVR_EN_BIT    ((uint32_t)0x00000010)
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_CH_0_RF_TR_SW_OVR_EN_POS    4
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_CH_0_RF_PA_EN_OVR_VAL_BIT    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_CH_0_RF_PA_EN_OVR_VAL_POS    3
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_CH_0_RF_PA_EN_OVR_EN_BIT    ((uint32_t)0x00000004)
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_CH_0_RF_PA_EN_OVR_EN_POS    2
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_CH_0_RF_TX_EN_OVR_VAL_BIT    ((uint32_t)0x00000002)
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_CH_0_RF_TX_EN_OVR_VAL_POS    1
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_CH_0_RF_TX_EN_OVR_EN_BIT    ((uint32_t)0x00000001)
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_CH_0_RF_TX_EN_OVR_EN_POS    0

#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_CH_1_RF_TR_SW_OVR_VAL_RST    0x0
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_CH_1_RF_TR_SW_OVR_EN_RST    0x1
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_CH_1_RF_PA_EN_OVR_VAL_RST    0x0
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_CH_1_RF_PA_EN_OVR_EN_RST    0x1
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_CH_1_RF_TX_EN_OVR_VAL_RST    0x0
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_CH_1_RF_TX_EN_OVR_EN_RST    0x1
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_CH_0_RF_TR_SW_OVR_VAL_RST    0x0
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_CH_0_RF_TR_SW_OVR_EN_RST    0x1
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_CH_0_RF_PA_EN_OVR_VAL_RST    0x0
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_CH_0_RF_PA_EN_OVR_EN_RST    0x1
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_CH_0_RF_TX_EN_OVR_VAL_RST    0x0
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_CH_0_RF_TX_EN_OVR_EN_RST    0x1

__INLINE void rfic_wrap_wifi_rf_tx_sw_ctrl_0_pack(uint8_t ch1_rf_tr_sw_ovr_val, uint8_t ch1_rf_tr_sw_ovr_en, uint8_t ch1_rf_pa_en_ovr_val, uint8_t ch1_rf_pa_en_ovr_en, uint8_t ch1_rf_tx_en_ovr_val, uint8_t ch1_rf_tx_en_ovr_en, uint8_t ch0_rf_tr_sw_ovr_val, uint8_t ch0_rf_tr_sw_ovr_en, uint8_t ch0_rf_pa_en_ovr_val, uint8_t ch0_rf_pa_en_ovr_en, uint8_t ch0_rf_tx_en_ovr_val, uint8_t ch0_rf_tx_en_ovr_en)
{
	ASSERT_ERR((((uint32_t)ch1_rf_tr_sw_ovr_val << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)ch1_rf_tr_sw_ovr_en << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)ch1_rf_pa_en_ovr_val << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)ch1_rf_pa_en_ovr_en << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)ch1_rf_tx_en_ovr_val << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)ch1_rf_tx_en_ovr_en << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)ch0_rf_tr_sw_ovr_val << 5) & ~((uint32_t)0x00000020)) == 0);
	ASSERT_ERR((((uint32_t)ch0_rf_tr_sw_ovr_en << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)ch0_rf_pa_en_ovr_val << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)ch0_rf_pa_en_ovr_en << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)ch0_rf_tx_en_ovr_val << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)ch0_rf_tx_en_ovr_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_ADDR,  ((uint32_t)ch1_rf_tr_sw_ovr_val << 13) |((uint32_t)ch1_rf_tr_sw_ovr_en << 12) |((uint32_t)ch1_rf_pa_en_ovr_val << 11) |((uint32_t)ch1_rf_pa_en_ovr_en << 10) |((uint32_t)ch1_rf_tx_en_ovr_val << 9) |((uint32_t)ch1_rf_tx_en_ovr_en << 8) |((uint32_t)ch0_rf_tr_sw_ovr_val << 5) |((uint32_t)ch0_rf_tr_sw_ovr_en << 4) |((uint32_t)ch0_rf_pa_en_ovr_val << 3) |((uint32_t)ch0_rf_pa_en_ovr_en << 2) |((uint32_t)ch0_rf_tx_en_ovr_val << 1) |((uint32_t)ch0_rf_tx_en_ovr_en << 0));
}

__INLINE void rfic_wrap_wifi_rf_tx_sw_ctrl_0_unpack(uint8_t* ch1_rf_tr_sw_ovr_val, uint8_t* ch1_rf_tr_sw_ovr_en, uint8_t* ch1_rf_pa_en_ovr_val, uint8_t* ch1_rf_pa_en_ovr_en, uint8_t* ch1_rf_tx_en_ovr_val, uint8_t* ch1_rf_tx_en_ovr_en, uint8_t* ch0_rf_tr_sw_ovr_val, uint8_t* ch0_rf_tr_sw_ovr_en, uint8_t* ch0_rf_pa_en_ovr_val, uint8_t* ch0_rf_pa_en_ovr_en, uint8_t* ch0_rf_tx_en_ovr_val, uint8_t* ch0_rf_tx_en_ovr_en)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_ADDR);

	*ch1_rf_tr_sw_ovr_val = (localVal & ((uint32_t)0x00002000)) >>  13;
	*ch1_rf_tr_sw_ovr_en = (localVal & ((uint32_t)0x00001000)) >>  12;
	*ch1_rf_pa_en_ovr_val = (localVal & ((uint32_t)0x00000800)) >>  11;
	*ch1_rf_pa_en_ovr_en = (localVal & ((uint32_t)0x00000400)) >>  10;
	*ch1_rf_tx_en_ovr_val = (localVal & ((uint32_t)0x00000200)) >>  9;
	*ch1_rf_tx_en_ovr_en = (localVal & ((uint32_t)0x00000100)) >>  8;
	*ch0_rf_tr_sw_ovr_val = (localVal & ((uint32_t)0x00000020)) >>  5;
	*ch0_rf_tr_sw_ovr_en = (localVal & ((uint32_t)0x00000010)) >>  4;
	*ch0_rf_pa_en_ovr_val = (localVal & ((uint32_t)0x00000008)) >>  3;
	*ch0_rf_pa_en_ovr_en = (localVal & ((uint32_t)0x00000004)) >>  2;
	*ch0_rf_tx_en_ovr_val = (localVal & ((uint32_t)0x00000002)) >>  1;
	*ch0_rf_tx_en_ovr_en = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_tx_sw_ctrl_0_ch_1_rf_tr_sw_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void rfic_wrap_wifi_rf_tx_sw_ctrl_0_ch_1_rf_tr_sw_ovr_val_setf(uint8_t ch1rftrswovrval)
{
	ASSERT_ERR((((uint32_t)ch1rftrswovrval << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)ch1rftrswovrval <<13));
}
__INLINE uint8_t rfic_wrap_wifi_rf_tx_sw_ctrl_0_ch_1_rf_tr_sw_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void rfic_wrap_wifi_rf_tx_sw_ctrl_0_ch_1_rf_tr_sw_ovr_en_setf(uint8_t ch1rftrswovren)
{
	ASSERT_ERR((((uint32_t)ch1rftrswovren << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)ch1rftrswovren <<12));
}
__INLINE uint8_t rfic_wrap_wifi_rf_tx_sw_ctrl_0_ch_1_rf_pa_en_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void rfic_wrap_wifi_rf_tx_sw_ctrl_0_ch_1_rf_pa_en_ovr_val_setf(uint8_t ch1rfpaenovrval)
{
	ASSERT_ERR((((uint32_t)ch1rfpaenovrval << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)ch1rfpaenovrval <<11));
}
__INLINE uint8_t rfic_wrap_wifi_rf_tx_sw_ctrl_0_ch_1_rf_pa_en_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void rfic_wrap_wifi_rf_tx_sw_ctrl_0_ch_1_rf_pa_en_ovr_en_setf(uint8_t ch1rfpaenovren)
{
	ASSERT_ERR((((uint32_t)ch1rfpaenovren << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)ch1rfpaenovren <<10));
}
__INLINE uint8_t rfic_wrap_wifi_rf_tx_sw_ctrl_0_ch_1_rf_tx_en_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void rfic_wrap_wifi_rf_tx_sw_ctrl_0_ch_1_rf_tx_en_ovr_val_setf(uint8_t ch1rftxenovrval)
{
	ASSERT_ERR((((uint32_t)ch1rftxenovrval << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)ch1rftxenovrval <<9));
}
__INLINE uint8_t rfic_wrap_wifi_rf_tx_sw_ctrl_0_ch_1_rf_tx_en_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_tx_sw_ctrl_0_ch_1_rf_tx_en_ovr_en_setf(uint8_t ch1rftxenovren)
{
	ASSERT_ERR((((uint32_t)ch1rftxenovren << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)ch1rftxenovren <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_tx_sw_ctrl_0_ch_0_rf_tr_sw_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE void rfic_wrap_wifi_rf_tx_sw_ctrl_0_ch_0_rf_tr_sw_ovr_val_setf(uint8_t ch0rftrswovrval)
{
	ASSERT_ERR((((uint32_t)ch0rftrswovrval << 5) & ~((uint32_t)0x00000020)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)ch0rftrswovrval <<5));
}
__INLINE uint8_t rfic_wrap_wifi_rf_tx_sw_ctrl_0_ch_0_rf_tr_sw_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void rfic_wrap_wifi_rf_tx_sw_ctrl_0_ch_0_rf_tr_sw_ovr_en_setf(uint8_t ch0rftrswovren)
{
	ASSERT_ERR((((uint32_t)ch0rftrswovren << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)ch0rftrswovren <<4));
}
__INLINE uint8_t rfic_wrap_wifi_rf_tx_sw_ctrl_0_ch_0_rf_pa_en_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void rfic_wrap_wifi_rf_tx_sw_ctrl_0_ch_0_rf_pa_en_ovr_val_setf(uint8_t ch0rfpaenovrval)
{
	ASSERT_ERR((((uint32_t)ch0rfpaenovrval << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)ch0rfpaenovrval <<3));
}
__INLINE uint8_t rfic_wrap_wifi_rf_tx_sw_ctrl_0_ch_0_rf_pa_en_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void rfic_wrap_wifi_rf_tx_sw_ctrl_0_ch_0_rf_pa_en_ovr_en_setf(uint8_t ch0rfpaenovren)
{
	ASSERT_ERR((((uint32_t)ch0rfpaenovren << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)ch0rfpaenovren <<2));
}
__INLINE uint8_t rfic_wrap_wifi_rf_tx_sw_ctrl_0_ch_0_rf_tx_en_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void rfic_wrap_wifi_rf_tx_sw_ctrl_0_ch_0_rf_tx_en_ovr_val_setf(uint8_t ch0rftxenovrval)
{
	ASSERT_ERR((((uint32_t)ch0rftxenovrval << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)ch0rftxenovrval <<1));
}
__INLINE uint8_t rfic_wrap_wifi_rf_tx_sw_ctrl_0_ch_0_rf_tx_en_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_tx_sw_ctrl_0_ch_0_rf_tx_en_ovr_en_setf(uint8_t ch0rftxenovren)
{
	ASSERT_ERR((((uint32_t)ch0rftxenovren << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_0_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)ch0rftxenovren <<0));
}

/**
 * @brief WIFI_RF_TX_SW_CTRL_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    20:13 CH1_RF_TX_GAIN_OVR_VAL    0x0
 *    12    CH1_RF_TX_GAIN_OVR_EN     1              
 *    08:01 CH0_RF_TX_GAIN_OVR_VAL    0x0
 *    00    CH0_RF_TX_GAIN_OVR_EN     1              
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_1_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x0000000C)
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_1_OFFSET      0x0000000C
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_1_INDEX       0x00000003
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_1_RESET       0x00001001

__INLINE uint32_t  rfic_wrap_wifi_rf_tx_sw_ctrl_1_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_1_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_tx_sw_ctrl_1_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_1_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_1_CH_1_RF_TX_GAIN_OVR_VAL_MASK    ((uint32_t)0x001FE000)
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_1_CH_1_RF_TX_GAIN_OVR_VAL_LSB    13
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_1_CH_1_RF_TX_GAIN_OVR_VAL_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_1_CH_1_RF_TX_GAIN_OVR_EN_BIT    ((uint32_t)0x00001000)
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_1_CH_1_RF_TX_GAIN_OVR_EN_POS    12
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_1_CH_0_RF_TX_GAIN_OVR_VAL_MASK    ((uint32_t)0x000001FE)
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_1_CH_0_RF_TX_GAIN_OVR_VAL_LSB    1
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_1_CH_0_RF_TX_GAIN_OVR_VAL_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_1_CH_0_RF_TX_GAIN_OVR_EN_BIT    ((uint32_t)0x00000001)
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_1_CH_0_RF_TX_GAIN_OVR_EN_POS    0

#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_1_CH_1_RF_TX_GAIN_OVR_VAL_RST    0x0
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_1_CH_1_RF_TX_GAIN_OVR_EN_RST    0x1
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_1_CH_0_RF_TX_GAIN_OVR_VAL_RST    0x0
#define RFIC_WRAP_WIFI_RF_TX_SW_CTRL_1_CH_0_RF_TX_GAIN_OVR_EN_RST    0x1

__INLINE void rfic_wrap_wifi_rf_tx_sw_ctrl_1_pack(uint8_t ch1_rf_tx_gain_ovr_val, uint8_t ch1_rf_tx_gain_ovr_en, uint8_t ch0_rf_tx_gain_ovr_val, uint8_t ch0_rf_tx_gain_ovr_en)
{
	ASSERT_ERR((((uint32_t)ch1_rf_tx_gain_ovr_val << 13) & ~((uint32_t)0x001FE000)) == 0);
	ASSERT_ERR((((uint32_t)ch1_rf_tx_gain_ovr_en << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)ch0_rf_tx_gain_ovr_val << 1) & ~((uint32_t)0x000001FE)) == 0);
	ASSERT_ERR((((uint32_t)ch0_rf_tx_gain_ovr_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_1_ADDR,  ((uint32_t)ch1_rf_tx_gain_ovr_val << 13) |((uint32_t)ch1_rf_tx_gain_ovr_en << 12) |((uint32_t)ch0_rf_tx_gain_ovr_val << 1) |((uint32_t)ch0_rf_tx_gain_ovr_en << 0));
}

__INLINE void rfic_wrap_wifi_rf_tx_sw_ctrl_1_unpack(uint8_t* ch1_rf_tx_gain_ovr_val, uint8_t* ch1_rf_tx_gain_ovr_en, uint8_t* ch0_rf_tx_gain_ovr_val, uint8_t* ch0_rf_tx_gain_ovr_en)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_1_ADDR);

	*ch1_rf_tx_gain_ovr_val = (localVal & ((uint32_t)0x001FE000)) >>  13;
	*ch1_rf_tx_gain_ovr_en = (localVal & ((uint32_t)0x00001000)) >>  12;
	*ch0_rf_tx_gain_ovr_val = (localVal & ((uint32_t)0x000001FE)) >>  1;
	*ch0_rf_tx_gain_ovr_en = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_tx_sw_ctrl_1_ch_1_rf_tx_gain_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001FE000)) >> 13);
}
__INLINE void rfic_wrap_wifi_rf_tx_sw_ctrl_1_ch_1_rf_tx_gain_ovr_val_setf(uint8_t ch1rftxgainovrval)
{
	ASSERT_ERR((((uint32_t)ch1rftxgainovrval << 13) & ~((uint32_t)0x001FE000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_1_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_1_ADDR) & ~((uint32_t)0x001FE000)) | ((uint32_t)ch1rftxgainovrval <<13));
}
__INLINE uint8_t rfic_wrap_wifi_rf_tx_sw_ctrl_1_ch_1_rf_tx_gain_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void rfic_wrap_wifi_rf_tx_sw_ctrl_1_ch_1_rf_tx_gain_ovr_en_setf(uint8_t ch1rftxgainovren)
{
	ASSERT_ERR((((uint32_t)ch1rftxgainovren << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_1_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_1_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)ch1rftxgainovren <<12));
}
__INLINE uint8_t rfic_wrap_wifi_rf_tx_sw_ctrl_1_ch_0_rf_tx_gain_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000001FE)) >> 1);
}
__INLINE void rfic_wrap_wifi_rf_tx_sw_ctrl_1_ch_0_rf_tx_gain_ovr_val_setf(uint8_t ch0rftxgainovrval)
{
	ASSERT_ERR((((uint32_t)ch0rftxgainovrval << 1) & ~((uint32_t)0x000001FE)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_1_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_1_ADDR) & ~((uint32_t)0x000001FE)) | ((uint32_t)ch0rftxgainovrval <<1));
}
__INLINE uint8_t rfic_wrap_wifi_rf_tx_sw_ctrl_1_ch_0_rf_tx_gain_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_tx_sw_ctrl_1_ch_0_rf_tx_gain_ovr_en_setf(uint8_t ch0rftxgainovren)
{
	ASSERT_ERR((((uint32_t)ch0rftxgainovren << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_1_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_TX_SW_CTRL_1_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)ch0rftxgainovren <<0));
}

/**
 * @brief WIFI_SB_COMMON_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    03:02 DAC_DATA_VALID_MODE       0x0
 *    01:00 ADC_DATA_EN_MODE          0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_SB_COMMON_CTRL_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000010)
#define RFIC_WRAP_WIFI_SB_COMMON_CTRL_OFFSET      0x00000010
#define RFIC_WRAP_WIFI_SB_COMMON_CTRL_INDEX       0x00000004
#define RFIC_WRAP_WIFI_SB_COMMON_CTRL_RESET       0x00000010

__INLINE uint32_t  rfic_wrap_wifi_sb_common_ctrl_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_SB_COMMON_CTRL_ADDR);
}

__INLINE void rfic_wrap_wifi_sb_common_ctrl_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_SB_COMMON_CTRL_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_SB_COMMON_CTRL_DAC_DATA_VALID_MODE_MASK    ((uint32_t)0x0000000C)
#define RFIC_WRAP_WIFI_SB_COMMON_CTRL_DAC_DATA_VALID_MODE_LSB    2
#define RFIC_WRAP_WIFI_SB_COMMON_CTRL_DAC_DATA_VALID_MODE_WIDTH    ((uint32_t)0x00000002)
#define RFIC_WRAP_WIFI_SB_COMMON_CTRL_ADC_DATA_EN_MODE_MASK    ((uint32_t)0x00000003)
#define RFIC_WRAP_WIFI_SB_COMMON_CTRL_ADC_DATA_EN_MODE_LSB    0
#define RFIC_WRAP_WIFI_SB_COMMON_CTRL_ADC_DATA_EN_MODE_WIDTH    ((uint32_t)0x00000002)

#define RFIC_WRAP_WIFI_SB_COMMON_CTRL_DAC_DATA_VALID_MODE_RST    0x0
#define RFIC_WRAP_WIFI_SB_COMMON_CTRL_ADC_DATA_EN_MODE_RST    0x0

__INLINE void rfic_wrap_wifi_sb_common_ctrl_pack(uint8_t dac_data_valid_mode, uint8_t adc_data_en_mode)
{
	ASSERT_ERR((((uint32_t)dac_data_valid_mode << 2) & ~((uint32_t)0x0000000C)) == 0);
	ASSERT_ERR((((uint32_t)adc_data_en_mode << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_SB_COMMON_CTRL_ADDR,  ((uint32_t)dac_data_valid_mode << 2) |((uint32_t)adc_data_en_mode << 0));
}

__INLINE void rfic_wrap_wifi_sb_common_ctrl_unpack(uint8_t* dac_data_valid_mode, uint8_t* adc_data_en_mode)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_SB_COMMON_CTRL_ADDR);

	*dac_data_valid_mode = (localVal & ((uint32_t)0x0000000C)) >>  2;
	*adc_data_en_mode = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_sb_common_ctrl_dac_data_valid_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_SB_COMMON_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000C)) >> 2);
}
__INLINE void rfic_wrap_wifi_sb_common_ctrl_dac_data_valid_mode_setf(uint8_t dacdatavalidmode)
{
	ASSERT_ERR((((uint32_t)dacdatavalidmode << 2) & ~((uint32_t)0x0000000C)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_SB_COMMON_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_SB_COMMON_CTRL_ADDR) & ~((uint32_t)0x0000000C)) | ((uint32_t)dacdatavalidmode <<2));
}
__INLINE uint8_t rfic_wrap_wifi_sb_common_ctrl_adc_data_en_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_SB_COMMON_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void rfic_wrap_wifi_sb_common_ctrl_adc_data_en_mode_setf(uint8_t adcdataenmode)
{
	ASSERT_ERR((((uint32_t)adcdataenmode << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_SB_COMMON_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_SB_COMMON_CTRL_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)adcdataenmode <<0));
}

/**
 * @brief WIFI_SB_TX_0_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 CH0_INIT_Q                0x0
 *    11:00 CH0_INIT_I                0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_SB_TX_0_CTRL_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000014)
#define RFIC_WRAP_WIFI_SB_TX_0_CTRL_OFFSET      0x00000014
#define RFIC_WRAP_WIFI_SB_TX_0_CTRL_INDEX       0x00000005
#define RFIC_WRAP_WIFI_SB_TX_0_CTRL_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_sb_tx_0_ctrl_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_SB_TX_0_CTRL_ADDR);
}

__INLINE void rfic_wrap_wifi_sb_tx_0_ctrl_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_SB_TX_0_CTRL_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_SB_TX_0_CTRL_CH_0_INIT_Q_MASK    ((uint32_t)0x0FFF0000)
#define RFIC_WRAP_WIFI_SB_TX_0_CTRL_CH_0_INIT_Q_LSB    16
#define RFIC_WRAP_WIFI_SB_TX_0_CTRL_CH_0_INIT_Q_WIDTH    ((uint32_t)0x0000000C)
#define RFIC_WRAP_WIFI_SB_TX_0_CTRL_CH_0_INIT_I_MASK    ((uint32_t)0x00000FFF)
#define RFIC_WRAP_WIFI_SB_TX_0_CTRL_CH_0_INIT_I_LSB    0
#define RFIC_WRAP_WIFI_SB_TX_0_CTRL_CH_0_INIT_I_WIDTH    ((uint32_t)0x0000000C)

#define RFIC_WRAP_WIFI_SB_TX_0_CTRL_CH_0_INIT_Q_RST    0x0
#define RFIC_WRAP_WIFI_SB_TX_0_CTRL_CH_0_INIT_I_RST    0x0

__INLINE void rfic_wrap_wifi_sb_tx_0_ctrl_pack(uint16_t ch0_init_q, uint16_t ch0_init_i)
{
	ASSERT_ERR((((uint32_t)ch0_init_q << 16) & ~((uint32_t)0x0FFF0000)) == 0);
	ASSERT_ERR((((uint32_t)ch0_init_i << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_SB_TX_0_CTRL_ADDR,  ((uint32_t)ch0_init_q << 16) |((uint32_t)ch0_init_i << 0));
}

__INLINE void rfic_wrap_wifi_sb_tx_0_ctrl_unpack(uint16_t* ch0_init_q, uint16_t* ch0_init_i)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_SB_TX_0_CTRL_ADDR);

	*ch0_init_q = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*ch0_init_i = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t rfic_wrap_wifi_sb_tx_0_ctrl_ch_0_init_q_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_SB_TX_0_CTRL_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_sb_tx_0_ctrl_ch_0_init_q_setf(uint16_t ch0initq)
{
	ASSERT_ERR((((uint32_t)ch0initq << 16) & ~((uint32_t)0x0FFF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_SB_TX_0_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_SB_TX_0_CTRL_ADDR) & ~((uint32_t)0x0FFF0000)) | ((uint32_t)ch0initq <<16));
}
__INLINE uint16_t rfic_wrap_wifi_sb_tx_0_ctrl_ch_0_init_i_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_SB_TX_0_CTRL_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}
__INLINE void rfic_wrap_wifi_sb_tx_0_ctrl_ch_0_init_i_setf(uint16_t ch0initi)
{
	ASSERT_ERR((((uint32_t)ch0initi << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_SB_TX_0_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_SB_TX_0_CTRL_ADDR) & ~((uint32_t)0x00000FFF)) | ((uint32_t)ch0initi <<0));
}

/**
 * @brief WIFI_SB_TX_1_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 CH1_TX_Q                  0x0
 *    11:00 CH1_TX_I                  0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_SB_TX_1_CTRL_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000018)
#define RFIC_WRAP_WIFI_SB_TX_1_CTRL_OFFSET      0x00000018
#define RFIC_WRAP_WIFI_SB_TX_1_CTRL_INDEX       0x00000006
#define RFIC_WRAP_WIFI_SB_TX_1_CTRL_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_sb_tx_1_ctrl_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_SB_TX_1_CTRL_ADDR);
}

__INLINE void rfic_wrap_wifi_sb_tx_1_ctrl_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_SB_TX_1_CTRL_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_SB_TX_1_CTRL_CH_1_TX_Q_MASK    ((uint32_t)0x0FFF0000)
#define RFIC_WRAP_WIFI_SB_TX_1_CTRL_CH_1_TX_Q_LSB    16
#define RFIC_WRAP_WIFI_SB_TX_1_CTRL_CH_1_TX_Q_WIDTH    ((uint32_t)0x0000000C)
#define RFIC_WRAP_WIFI_SB_TX_1_CTRL_CH_1_TX_I_MASK    ((uint32_t)0x00000FFF)
#define RFIC_WRAP_WIFI_SB_TX_1_CTRL_CH_1_TX_I_LSB    0
#define RFIC_WRAP_WIFI_SB_TX_1_CTRL_CH_1_TX_I_WIDTH    ((uint32_t)0x0000000C)

#define RFIC_WRAP_WIFI_SB_TX_1_CTRL_CH_1_TX_Q_RST    0x0
#define RFIC_WRAP_WIFI_SB_TX_1_CTRL_CH_1_TX_I_RST    0x0

__INLINE void rfic_wrap_wifi_sb_tx_1_ctrl_pack(uint16_t ch1_tx_q, uint16_t ch1_tx_i)
{
	ASSERT_ERR((((uint32_t)ch1_tx_q << 16) & ~((uint32_t)0x0FFF0000)) == 0);
	ASSERT_ERR((((uint32_t)ch1_tx_i << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_SB_TX_1_CTRL_ADDR,  ((uint32_t)ch1_tx_q << 16) |((uint32_t)ch1_tx_i << 0));
}

__INLINE void rfic_wrap_wifi_sb_tx_1_ctrl_unpack(uint16_t* ch1_tx_q, uint16_t* ch1_tx_i)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_SB_TX_1_CTRL_ADDR);

	*ch1_tx_q = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*ch1_tx_i = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t rfic_wrap_wifi_sb_tx_1_ctrl_ch_1_tx_q_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_SB_TX_1_CTRL_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_sb_tx_1_ctrl_ch_1_tx_q_setf(uint16_t ch1txq)
{
	ASSERT_ERR((((uint32_t)ch1txq << 16) & ~((uint32_t)0x0FFF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_SB_TX_1_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_SB_TX_1_CTRL_ADDR) & ~((uint32_t)0x0FFF0000)) | ((uint32_t)ch1txq <<16));
}
__INLINE uint16_t rfic_wrap_wifi_sb_tx_1_ctrl_ch_1_tx_i_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_SB_TX_1_CTRL_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}
__INLINE void rfic_wrap_wifi_sb_tx_1_ctrl_ch_1_tx_i_setf(uint16_t ch1txi)
{
	ASSERT_ERR((((uint32_t)ch1txi << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_SB_TX_1_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_SB_TX_1_CTRL_ADDR) & ~((uint32_t)0x00000FFF)) | ((uint32_t)ch1txi <<0));
}

/**
 * @brief WIFI_RF_RX_SW_CTRL_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    09    CH1_RF_RX_EN_OVR_VAL      0              
 *    08    CH1_RF_RX_EN_OVR_EN       1              
 *    01    CH0_RF_RX_EN_OVR_VAL      0              
 *    00    CH0_RF_RX_EN_OVR_EN       1              
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_0_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x0000001C)
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_0_OFFSET      0x0000001C
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_0_INDEX       0x00000007
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_0_RESET       0x00000101

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_sw_ctrl_0_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_0_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_sw_ctrl_0_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_0_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_0_CH_1_RF_RX_EN_OVR_VAL_BIT    ((uint32_t)0x00000200)
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_0_CH_1_RF_RX_EN_OVR_VAL_POS    9
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_0_CH_1_RF_RX_EN_OVR_EN_BIT    ((uint32_t)0x00000100)
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_0_CH_1_RF_RX_EN_OVR_EN_POS    8
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_0_CH_0_RF_RX_EN_OVR_VAL_BIT    ((uint32_t)0x00000002)
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_0_CH_0_RF_RX_EN_OVR_VAL_POS    1
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_0_CH_0_RF_RX_EN_OVR_EN_BIT    ((uint32_t)0x00000001)
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_0_CH_0_RF_RX_EN_OVR_EN_POS    0

#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_0_CH_1_RF_RX_EN_OVR_VAL_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_0_CH_1_RF_RX_EN_OVR_EN_RST    0x1
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_0_CH_0_RF_RX_EN_OVR_VAL_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_0_CH_0_RF_RX_EN_OVR_EN_RST    0x1

__INLINE void rfic_wrap_wifi_rf_rx_sw_ctrl_0_pack(uint8_t ch1_rf_rx_en_ovr_val, uint8_t ch1_rf_rx_en_ovr_en, uint8_t ch0_rf_rx_en_ovr_val, uint8_t ch0_rf_rx_en_ovr_en)
{
	ASSERT_ERR((((uint32_t)ch1_rf_rx_en_ovr_val << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)ch1_rf_rx_en_ovr_en << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)ch0_rf_rx_en_ovr_val << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)ch0_rf_rx_en_ovr_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_0_ADDR,  ((uint32_t)ch1_rf_rx_en_ovr_val << 9) |((uint32_t)ch1_rf_rx_en_ovr_en << 8) |((uint32_t)ch0_rf_rx_en_ovr_val << 1) |((uint32_t)ch0_rf_rx_en_ovr_en << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_sw_ctrl_0_unpack(uint8_t* ch1_rf_rx_en_ovr_val, uint8_t* ch1_rf_rx_en_ovr_en, uint8_t* ch0_rf_rx_en_ovr_val, uint8_t* ch0_rf_rx_en_ovr_en)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_0_ADDR);

	*ch1_rf_rx_en_ovr_val = (localVal & ((uint32_t)0x00000200)) >>  9;
	*ch1_rf_rx_en_ovr_en = (localVal & ((uint32_t)0x00000100)) >>  8;
	*ch0_rf_rx_en_ovr_val = (localVal & ((uint32_t)0x00000002)) >>  1;
	*ch0_rf_rx_en_ovr_en = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_sw_ctrl_0_ch_1_rf_rx_en_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void rfic_wrap_wifi_rf_rx_sw_ctrl_0_ch_1_rf_rx_en_ovr_val_setf(uint8_t ch1rfrxenovrval)
{
	ASSERT_ERR((((uint32_t)ch1rfrxenovrval << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_0_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_0_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)ch1rfrxenovrval <<9));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_sw_ctrl_0_ch_1_rf_rx_en_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_sw_ctrl_0_ch_1_rf_rx_en_ovr_en_setf(uint8_t ch1rfrxenovren)
{
	ASSERT_ERR((((uint32_t)ch1rfrxenovren << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_0_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_0_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)ch1rfrxenovren <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_sw_ctrl_0_ch_0_rf_rx_en_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void rfic_wrap_wifi_rf_rx_sw_ctrl_0_ch_0_rf_rx_en_ovr_val_setf(uint8_t ch0rfrxenovrval)
{
	ASSERT_ERR((((uint32_t)ch0rfrxenovrval << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_0_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_0_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)ch0rfrxenovrval <<1));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_sw_ctrl_0_ch_0_rf_rx_en_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_sw_ctrl_0_ch_0_rf_rx_en_ovr_en_setf(uint8_t ch0rfrxenovren)
{
	ASSERT_ERR((((uint32_t)ch0rfrxenovren << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_0_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_0_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)ch0rfrxenovren <<0));
}

/**
 * @brief WIFI_RF_RX_SW_CTRL_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    21:13 CH1_RF_RX_GAIN_OVR_VAL    0x0
 *    12    CH1_RF_RX_GAIN_OVR_EN     1              
 *    09:01 CH0_RF_RX_GAIN_OVR_VAL    0x0
 *    00    CH0_RF_RX_GAIN_OVR_EN     1              
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_1_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000020)
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_1_OFFSET      0x00000020
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_1_INDEX       0x00000008
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_1_RESET       0x00001001

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_sw_ctrl_1_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_1_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_sw_ctrl_1_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_1_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_1_CH_1_RF_RX_GAIN_OVR_VAL_MASK    ((uint32_t)0x003FE000)
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_1_CH_1_RF_RX_GAIN_OVR_VAL_LSB    13
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_1_CH_1_RF_RX_GAIN_OVR_VAL_WIDTH    ((uint32_t)0x00000009)
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_1_CH_1_RF_RX_GAIN_OVR_EN_BIT    ((uint32_t)0x00001000)
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_1_CH_1_RF_RX_GAIN_OVR_EN_POS    12
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_1_CH_0_RF_RX_GAIN_OVR_VAL_MASK    ((uint32_t)0x000003FE)
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_1_CH_0_RF_RX_GAIN_OVR_VAL_LSB    1
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_1_CH_0_RF_RX_GAIN_OVR_VAL_WIDTH    ((uint32_t)0x00000009)
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_1_CH_0_RF_RX_GAIN_OVR_EN_BIT    ((uint32_t)0x00000001)
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_1_CH_0_RF_RX_GAIN_OVR_EN_POS    0

#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_1_CH_1_RF_RX_GAIN_OVR_VAL_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_1_CH_1_RF_RX_GAIN_OVR_EN_RST    0x1
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_1_CH_0_RF_RX_GAIN_OVR_VAL_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_1_CH_0_RF_RX_GAIN_OVR_EN_RST    0x1

__INLINE void rfic_wrap_wifi_rf_rx_sw_ctrl_1_pack(uint16_t ch1_rf_rx_gain_ovr_val, uint8_t ch1_rf_rx_gain_ovr_en, uint16_t ch0_rf_rx_gain_ovr_val, uint8_t ch0_rf_rx_gain_ovr_en)
{
	ASSERT_ERR((((uint32_t)ch1_rf_rx_gain_ovr_val << 13) & ~((uint32_t)0x003FE000)) == 0);
	ASSERT_ERR((((uint32_t)ch1_rf_rx_gain_ovr_en << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)ch0_rf_rx_gain_ovr_val << 1) & ~((uint32_t)0x000003FE)) == 0);
	ASSERT_ERR((((uint32_t)ch0_rf_rx_gain_ovr_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_1_ADDR,  ((uint32_t)ch1_rf_rx_gain_ovr_val << 13) |((uint32_t)ch1_rf_rx_gain_ovr_en << 12) |((uint32_t)ch0_rf_rx_gain_ovr_val << 1) |((uint32_t)ch0_rf_rx_gain_ovr_en << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_sw_ctrl_1_unpack(uint16_t* ch1_rf_rx_gain_ovr_val, uint8_t* ch1_rf_rx_gain_ovr_en, uint16_t* ch0_rf_rx_gain_ovr_val, uint8_t* ch0_rf_rx_gain_ovr_en)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_1_ADDR);

	*ch1_rf_rx_gain_ovr_val = (localVal & ((uint32_t)0x003FE000)) >>  13;
	*ch1_rf_rx_gain_ovr_en = (localVal & ((uint32_t)0x00001000)) >>  12;
	*ch0_rf_rx_gain_ovr_val = (localVal & ((uint32_t)0x000003FE)) >>  1;
	*ch0_rf_rx_gain_ovr_en = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint16_t rfic_wrap_wifi_rf_rx_sw_ctrl_1_ch_1_rf_rx_gain_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x003FE000)) >> 13);
}
__INLINE void rfic_wrap_wifi_rf_rx_sw_ctrl_1_ch_1_rf_rx_gain_ovr_val_setf(uint16_t ch1rfrxgainovrval)
{
	ASSERT_ERR((((uint32_t)ch1rfrxgainovrval << 13) & ~((uint32_t)0x003FE000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_1_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_1_ADDR) & ~((uint32_t)0x003FE000)) | ((uint32_t)ch1rfrxgainovrval <<13));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_sw_ctrl_1_ch_1_rf_rx_gain_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void rfic_wrap_wifi_rf_rx_sw_ctrl_1_ch_1_rf_rx_gain_ovr_en_setf(uint8_t ch1rfrxgainovren)
{
	ASSERT_ERR((((uint32_t)ch1rfrxgainovren << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_1_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_1_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)ch1rfrxgainovren <<12));
}
__INLINE uint16_t rfic_wrap_wifi_rf_rx_sw_ctrl_1_ch_0_rf_rx_gain_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000003FE)) >> 1);
}
__INLINE void rfic_wrap_wifi_rf_rx_sw_ctrl_1_ch_0_rf_rx_gain_ovr_val_setf(uint16_t ch0rfrxgainovrval)
{
	ASSERT_ERR((((uint32_t)ch0rfrxgainovrval << 1) & ~((uint32_t)0x000003FE)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_1_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_1_ADDR) & ~((uint32_t)0x000003FE)) | ((uint32_t)ch0rfrxgainovrval <<1));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_sw_ctrl_1_ch_0_rf_rx_gain_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_sw_ctrl_1_ch_0_rf_rx_gain_ovr_en_setf(uint8_t ch0rfrxgainovren)
{
	ASSERT_ERR((((uint32_t)ch0rfrxgainovren << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_1_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_1_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)ch0rfrxgainovren <<0));
}

/**
 * @brief WIFI_RF_RX_SW_CTRL_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    09    SX1_FRAC_FREQ_SEL_OVR_VAL 0              
 *    08    SX1_FRAC_FREQ_SEL_OVR_EN  1              
 *    01    SX0_FRAC_FREQ_SEL_OVR_VAL 0              
 *    00    SX0_FRAC_FREQ_SEL_OVR_EN  1              
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_2_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000024)
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_2_OFFSET      0x00000024
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_2_INDEX       0x00000009
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_2_RESET       0x00000101

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_sw_ctrl_2_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_2_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_sw_ctrl_2_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_2_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_2_SX_1_FRAC_FREQ_SEL_OVR_VAL_BIT    ((uint32_t)0x00000200)
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_2_SX_1_FRAC_FREQ_SEL_OVR_VAL_POS    9
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_2_SX_1_FRAC_FREQ_SEL_OVR_EN_BIT    ((uint32_t)0x00000100)
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_2_SX_1_FRAC_FREQ_SEL_OVR_EN_POS    8
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_2_SX_0_FRAC_FREQ_SEL_OVR_VAL_BIT    ((uint32_t)0x00000002)
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_2_SX_0_FRAC_FREQ_SEL_OVR_VAL_POS    1
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_2_SX_0_FRAC_FREQ_SEL_OVR_EN_BIT    ((uint32_t)0x00000001)
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_2_SX_0_FRAC_FREQ_SEL_OVR_EN_POS    0

#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_2_SX_1_FRAC_FREQ_SEL_OVR_VAL_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_2_SX_1_FRAC_FREQ_SEL_OVR_EN_RST    0x1
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_2_SX_0_FRAC_FREQ_SEL_OVR_VAL_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_2_SX_0_FRAC_FREQ_SEL_OVR_EN_RST    0x1

__INLINE void rfic_wrap_wifi_rf_rx_sw_ctrl_2_pack(uint8_t sx1_frac_freq_sel_ovr_val, uint8_t sx1_frac_freq_sel_ovr_en, uint8_t sx0_frac_freq_sel_ovr_val, uint8_t sx0_frac_freq_sel_ovr_en)
{
	ASSERT_ERR((((uint32_t)sx1_frac_freq_sel_ovr_val << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)sx1_frac_freq_sel_ovr_en << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)sx0_frac_freq_sel_ovr_val << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)sx0_frac_freq_sel_ovr_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_2_ADDR,  ((uint32_t)sx1_frac_freq_sel_ovr_val << 9) |((uint32_t)sx1_frac_freq_sel_ovr_en << 8) |((uint32_t)sx0_frac_freq_sel_ovr_val << 1) |((uint32_t)sx0_frac_freq_sel_ovr_en << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_sw_ctrl_2_unpack(uint8_t* sx1_frac_freq_sel_ovr_val, uint8_t* sx1_frac_freq_sel_ovr_en, uint8_t* sx0_frac_freq_sel_ovr_val, uint8_t* sx0_frac_freq_sel_ovr_en)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_2_ADDR);

	*sx1_frac_freq_sel_ovr_val = (localVal & ((uint32_t)0x00000200)) >>  9;
	*sx1_frac_freq_sel_ovr_en = (localVal & ((uint32_t)0x00000100)) >>  8;
	*sx0_frac_freq_sel_ovr_val = (localVal & ((uint32_t)0x00000002)) >>  1;
	*sx0_frac_freq_sel_ovr_en = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_sw_ctrl_2_sx_1_frac_freq_sel_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void rfic_wrap_wifi_rf_rx_sw_ctrl_2_sx_1_frac_freq_sel_ovr_val_setf(uint8_t sx1fracfreqselovrval)
{
	ASSERT_ERR((((uint32_t)sx1fracfreqselovrval << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_2_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_2_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)sx1fracfreqselovrval <<9));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_sw_ctrl_2_sx_1_frac_freq_sel_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_sw_ctrl_2_sx_1_frac_freq_sel_ovr_en_setf(uint8_t sx1fracfreqselovren)
{
	ASSERT_ERR((((uint32_t)sx1fracfreqselovren << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_2_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_2_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)sx1fracfreqselovren <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_sw_ctrl_2_sx_0_frac_freq_sel_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void rfic_wrap_wifi_rf_rx_sw_ctrl_2_sx_0_frac_freq_sel_ovr_val_setf(uint8_t sx0fracfreqselovrval)
{
	ASSERT_ERR((((uint32_t)sx0fracfreqselovrval << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_2_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_2_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)sx0fracfreqselovrval <<1));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_sw_ctrl_2_sx_0_frac_freq_sel_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_sw_ctrl_2_sx_0_frac_freq_sel_ovr_en_setf(uint8_t sx0fracfreqselovren)
{
	ASSERT_ERR((((uint32_t)sx0fracfreqselovren << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_2_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_2_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)sx0fracfreqselovren <<0));
}

/**
 * @brief WIFI_RF_RX_SW_CTRL_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    13    CH1_RSSI_VALID_OVR_VAL    0              
 *    12    CH1_RSSI_VALID_OVR_EN     1              
 *    10:09 CH1_RSSI_OVR_VAL          0x0
 *    08    CH1_RSSI_OVR_EN           1              
 *    05    CH0_RSSI_VALID_OVR_VAL    0              
 *    04    CH0_RSSI_VALID_OVR_EN     1              
 *    02:01 CH0_RSSI_OVR_VAL          0x0
 *    00    CH0_RSSI_OVR_EN           1              
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000028)
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_OFFSET      0x00000028
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_INDEX       0x0000000A
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_RESET       0x00001111

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_sw_ctrl_3_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_sw_ctrl_3_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_CH_1_RSSI_VALID_OVR_VAL_BIT    ((uint32_t)0x00002000)
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_CH_1_RSSI_VALID_OVR_VAL_POS    13
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_CH_1_RSSI_VALID_OVR_EN_BIT    ((uint32_t)0x00001000)
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_CH_1_RSSI_VALID_OVR_EN_POS    12
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_CH_1_RSSI_OVR_VAL_MASK    ((uint32_t)0x00000600)
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_CH_1_RSSI_OVR_VAL_LSB    9
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_CH_1_RSSI_OVR_VAL_WIDTH    ((uint32_t)0x00000002)
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_CH_1_RSSI_OVR_EN_BIT    ((uint32_t)0x00000100)
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_CH_1_RSSI_OVR_EN_POS    8
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_CH_0_RSSI_VALID_OVR_VAL_BIT    ((uint32_t)0x00000020)
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_CH_0_RSSI_VALID_OVR_VAL_POS    5
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_CH_0_RSSI_VALID_OVR_EN_BIT    ((uint32_t)0x00000010)
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_CH_0_RSSI_VALID_OVR_EN_POS    4
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_CH_0_RSSI_OVR_VAL_MASK    ((uint32_t)0x00000006)
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_CH_0_RSSI_OVR_VAL_LSB    1
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_CH_0_RSSI_OVR_VAL_WIDTH    ((uint32_t)0x00000002)
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_CH_0_RSSI_OVR_EN_BIT    ((uint32_t)0x00000001)
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_CH_0_RSSI_OVR_EN_POS    0

#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_CH_1_RSSI_VALID_OVR_VAL_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_CH_1_RSSI_VALID_OVR_EN_RST    0x1
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_CH_1_RSSI_OVR_VAL_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_CH_1_RSSI_OVR_EN_RST    0x1
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_CH_0_RSSI_VALID_OVR_VAL_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_CH_0_RSSI_VALID_OVR_EN_RST    0x1
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_CH_0_RSSI_OVR_VAL_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_CH_0_RSSI_OVR_EN_RST    0x1

__INLINE void rfic_wrap_wifi_rf_rx_sw_ctrl_3_pack(uint8_t ch1_rssi_valid_ovr_val, uint8_t ch1_rssi_valid_ovr_en, uint8_t ch1_rssi_ovr_val, uint8_t ch1_rssi_ovr_en, uint8_t ch0_rssi_valid_ovr_val, uint8_t ch0_rssi_valid_ovr_en, uint8_t ch0_rssi_ovr_val, uint8_t ch0_rssi_ovr_en)
{
	ASSERT_ERR((((uint32_t)ch1_rssi_valid_ovr_val << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)ch1_rssi_valid_ovr_en << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)ch1_rssi_ovr_val << 9) & ~((uint32_t)0x00000600)) == 0);
	ASSERT_ERR((((uint32_t)ch1_rssi_ovr_en << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)ch0_rssi_valid_ovr_val << 5) & ~((uint32_t)0x00000020)) == 0);
	ASSERT_ERR((((uint32_t)ch0_rssi_valid_ovr_en << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)ch0_rssi_ovr_val << 1) & ~((uint32_t)0x00000006)) == 0);
	ASSERT_ERR((((uint32_t)ch0_rssi_ovr_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_ADDR,  ((uint32_t)ch1_rssi_valid_ovr_val << 13) |((uint32_t)ch1_rssi_valid_ovr_en << 12) |((uint32_t)ch1_rssi_ovr_val << 9) |((uint32_t)ch1_rssi_ovr_en << 8) |((uint32_t)ch0_rssi_valid_ovr_val << 5) |((uint32_t)ch0_rssi_valid_ovr_en << 4) |((uint32_t)ch0_rssi_ovr_val << 1) |((uint32_t)ch0_rssi_ovr_en << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_sw_ctrl_3_unpack(uint8_t* ch1_rssi_valid_ovr_val, uint8_t* ch1_rssi_valid_ovr_en, uint8_t* ch1_rssi_ovr_val, uint8_t* ch1_rssi_ovr_en, uint8_t* ch0_rssi_valid_ovr_val, uint8_t* ch0_rssi_valid_ovr_en, uint8_t* ch0_rssi_ovr_val, uint8_t* ch0_rssi_ovr_en)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_ADDR);

	*ch1_rssi_valid_ovr_val = (localVal & ((uint32_t)0x00002000)) >>  13;
	*ch1_rssi_valid_ovr_en = (localVal & ((uint32_t)0x00001000)) >>  12;
	*ch1_rssi_ovr_val = (localVal & ((uint32_t)0x00000600)) >>  9;
	*ch1_rssi_ovr_en = (localVal & ((uint32_t)0x00000100)) >>  8;
	*ch0_rssi_valid_ovr_val = (localVal & ((uint32_t)0x00000020)) >>  5;
	*ch0_rssi_valid_ovr_en = (localVal & ((uint32_t)0x00000010)) >>  4;
	*ch0_rssi_ovr_val = (localVal & ((uint32_t)0x00000006)) >>  1;
	*ch0_rssi_ovr_en = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_sw_ctrl_3_ch_1_rssi_valid_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void rfic_wrap_wifi_rf_rx_sw_ctrl_3_ch_1_rssi_valid_ovr_val_setf(uint8_t ch1rssivalidovrval)
{
	ASSERT_ERR((((uint32_t)ch1rssivalidovrval << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)ch1rssivalidovrval <<13));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_sw_ctrl_3_ch_1_rssi_valid_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void rfic_wrap_wifi_rf_rx_sw_ctrl_3_ch_1_rssi_valid_ovr_en_setf(uint8_t ch1rssivalidovren)
{
	ASSERT_ERR((((uint32_t)ch1rssivalidovren << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)ch1rssivalidovren <<12));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_sw_ctrl_3_ch_1_rssi_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000600)) >> 9);
}
__INLINE void rfic_wrap_wifi_rf_rx_sw_ctrl_3_ch_1_rssi_ovr_val_setf(uint8_t ch1rssiovrval)
{
	ASSERT_ERR((((uint32_t)ch1rssiovrval << 9) & ~((uint32_t)0x00000600)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_ADDR) & ~((uint32_t)0x00000600)) | ((uint32_t)ch1rssiovrval <<9));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_sw_ctrl_3_ch_1_rssi_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_sw_ctrl_3_ch_1_rssi_ovr_en_setf(uint8_t ch1rssiovren)
{
	ASSERT_ERR((((uint32_t)ch1rssiovren << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)ch1rssiovren <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_sw_ctrl_3_ch_0_rssi_valid_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE void rfic_wrap_wifi_rf_rx_sw_ctrl_3_ch_0_rssi_valid_ovr_val_setf(uint8_t ch0rssivalidovrval)
{
	ASSERT_ERR((((uint32_t)ch0rssivalidovrval << 5) & ~((uint32_t)0x00000020)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)ch0rssivalidovrval <<5));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_sw_ctrl_3_ch_0_rssi_valid_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void rfic_wrap_wifi_rf_rx_sw_ctrl_3_ch_0_rssi_valid_ovr_en_setf(uint8_t ch0rssivalidovren)
{
	ASSERT_ERR((((uint32_t)ch0rssivalidovren << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)ch0rssivalidovren <<4));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_sw_ctrl_3_ch_0_rssi_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000006)) >> 1);
}
__INLINE void rfic_wrap_wifi_rf_rx_sw_ctrl_3_ch_0_rssi_ovr_val_setf(uint8_t ch0rssiovrval)
{
	ASSERT_ERR((((uint32_t)ch0rssiovrval << 1) & ~((uint32_t)0x00000006)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_ADDR) & ~((uint32_t)0x00000006)) | ((uint32_t)ch0rssiovrval <<1));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_sw_ctrl_3_ch_0_rssi_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_sw_ctrl_3_ch_0_rssi_ovr_en_setf(uint8_t ch0rssiovren)
{
	ASSERT_ERR((((uint32_t)ch0rssiovren << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_SW_CTRL_3_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)ch0rssiovren <<0));
}

/**
 * @brief WIFI_RSSI_STAT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    07    LNA1_SAT                  0              
 *    06    LNA0_SAT                  0              
 *    05:04 RSSI1                     0x0
 *    03:02 RSSI0                     0x0
 *    01    RSSI1_VALID               0              
 *    00    RSSI0_VALID               0              
 * </pre>
 */
#define RFIC_WRAP_WIFI_RSSI_STAT_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x0000002C)
#define RFIC_WRAP_WIFI_RSSI_STAT_OFFSET      0x0000002C
#define RFIC_WRAP_WIFI_RSSI_STAT_INDEX       0x0000000B
#define RFIC_WRAP_WIFI_RSSI_STAT_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rssi_stat_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RSSI_STAT_ADDR);
}

// field definitions
#define RFIC_WRAP_WIFI_RSSI_STAT_LNA_1_SAT_BIT    ((uint32_t)0x00000080)
#define RFIC_WRAP_WIFI_RSSI_STAT_LNA_1_SAT_POS    7
#define RFIC_WRAP_WIFI_RSSI_STAT_LNA_0_SAT_BIT    ((uint32_t)0x00000040)
#define RFIC_WRAP_WIFI_RSSI_STAT_LNA_0_SAT_POS    6
#define RFIC_WRAP_WIFI_RSSI_STAT_RSSI_1_MASK    ((uint32_t)0x00000030)
#define RFIC_WRAP_WIFI_RSSI_STAT_RSSI_1_LSB    4
#define RFIC_WRAP_WIFI_RSSI_STAT_RSSI_1_WIDTH    ((uint32_t)0x00000002)
#define RFIC_WRAP_WIFI_RSSI_STAT_RSSI_0_MASK    ((uint32_t)0x0000000C)
#define RFIC_WRAP_WIFI_RSSI_STAT_RSSI_0_LSB    2
#define RFIC_WRAP_WIFI_RSSI_STAT_RSSI_0_WIDTH    ((uint32_t)0x00000002)
#define RFIC_WRAP_WIFI_RSSI_STAT_RSSI_1_VALID_BIT    ((uint32_t)0x00000002)
#define RFIC_WRAP_WIFI_RSSI_STAT_RSSI_1_VALID_POS    1
#define RFIC_WRAP_WIFI_RSSI_STAT_RSSI_0_VALID_BIT    ((uint32_t)0x00000001)
#define RFIC_WRAP_WIFI_RSSI_STAT_RSSI_0_VALID_POS    0

#define RFIC_WRAP_WIFI_RSSI_STAT_LNA_1_SAT_RST    0x0
#define RFIC_WRAP_WIFI_RSSI_STAT_LNA_0_SAT_RST    0x0
#define RFIC_WRAP_WIFI_RSSI_STAT_RSSI_1_RST    0x0
#define RFIC_WRAP_WIFI_RSSI_STAT_RSSI_0_RST    0x0
#define RFIC_WRAP_WIFI_RSSI_STAT_RSSI_1_VALID_RST    0x0
#define RFIC_WRAP_WIFI_RSSI_STAT_RSSI_0_VALID_RST    0x0

__INLINE void rfic_wrap_wifi_rssi_stat_unpack(uint8_t* lna1_sat, uint8_t* lna0_sat, uint8_t* rssi1, uint8_t* rssi0, uint8_t* rssi1_valid, uint8_t* rssi0_valid)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RSSI_STAT_ADDR);

	*lna1_sat = (localVal & ((uint32_t)0x00000080)) >>  7;
	*lna0_sat = (localVal & ((uint32_t)0x00000040)) >>  6;
	*rssi1 = (localVal & ((uint32_t)0x00000030)) >>  4;
	*rssi0 = (localVal & ((uint32_t)0x0000000C)) >>  2;
	*rssi1_valid = (localVal & ((uint32_t)0x00000002)) >>  1;
	*rssi0_valid = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rssi_stat_lna_1_sat_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RSSI_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE uint8_t rfic_wrap_wifi_rssi_stat_lna_0_sat_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RSSI_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE uint8_t rfic_wrap_wifi_rssi_stat_rssi_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RSSI_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000030)) >> 4);
}
__INLINE uint8_t rfic_wrap_wifi_rssi_stat_rssi_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RSSI_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000C)) >> 2);
}
__INLINE uint8_t rfic_wrap_wifi_rssi_stat_rssi_1_valid_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RSSI_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t rfic_wrap_wifi_rssi_stat_rssi_0_valid_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RSSI_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief WIFI_RF_DYN_CFG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01    CH1_SYN_SEL               0              
 *    00    CH0_SYN_SEL               0              
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_DYN_CFG_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000030)
#define RFIC_WRAP_WIFI_RF_DYN_CFG_OFFSET      0x00000030
#define RFIC_WRAP_WIFI_RF_DYN_CFG_INDEX       0x0000000C
#define RFIC_WRAP_WIFI_RF_DYN_CFG_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_dyn_cfg_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_DYN_CFG_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_dyn_cfg_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_DYN_CFG_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_DYN_CFG_CH_1_SYN_SEL_BIT    ((uint32_t)0x00000002)
#define RFIC_WRAP_WIFI_RF_DYN_CFG_CH_1_SYN_SEL_POS    1
#define RFIC_WRAP_WIFI_RF_DYN_CFG_CH_0_SYN_SEL_BIT    ((uint32_t)0x00000001)
#define RFIC_WRAP_WIFI_RF_DYN_CFG_CH_0_SYN_SEL_POS    0

#define RFIC_WRAP_WIFI_RF_DYN_CFG_CH_1_SYN_SEL_RST    0x0
#define RFIC_WRAP_WIFI_RF_DYN_CFG_CH_0_SYN_SEL_RST    0x0

__INLINE void rfic_wrap_wifi_rf_dyn_cfg_pack(uint8_t ch1_syn_sel, uint8_t ch0_syn_sel)
{
	ASSERT_ERR((((uint32_t)ch1_syn_sel << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)ch0_syn_sel << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_DYN_CFG_ADDR,  ((uint32_t)ch1_syn_sel << 1) |((uint32_t)ch0_syn_sel << 0));
}

__INLINE void rfic_wrap_wifi_rf_dyn_cfg_unpack(uint8_t* ch1_syn_sel, uint8_t* ch0_syn_sel)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_DYN_CFG_ADDR);

	*ch1_syn_sel = (localVal & ((uint32_t)0x00000002)) >>  1;
	*ch0_syn_sel = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_dyn_cfg_ch_1_syn_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_DYN_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void rfic_wrap_wifi_rf_dyn_cfg_ch_1_syn_sel_setf(uint8_t ch1synsel)
{
	ASSERT_ERR((((uint32_t)ch1synsel << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_DYN_CFG_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_DYN_CFG_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)ch1synsel <<1));
}
__INLINE uint8_t rfic_wrap_wifi_rf_dyn_cfg_ch_0_syn_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_DYN_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_dyn_cfg_ch_0_syn_sel_setf(uint8_t ch0synsel)
{
	ASSERT_ERR((((uint32_t)ch0synsel << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_DYN_CFG_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_DYN_CFG_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)ch0synsel <<0));
}

/**
 * @brief WIFI_DAC_TEST_GEN_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    29    DELTA_SIGN_I              0              
 *    28:24 DELTA_VAL_I               0x0
 *    23:12 LAST_VAL_I                0x0
 *    11:00 INIT_VAL_I                0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_1_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000034)
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_1_OFFSET      0x00000034
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_1_INDEX       0x0000000D
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_1_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_dac_test_gen_1_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_DAC_TEST_GEN_1_ADDR);
}

__INLINE void rfic_wrap_wifi_dac_test_gen_1_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_DAC_TEST_GEN_1_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_1_DELTA_SIGN_I_BIT    ((uint32_t)0x20000000)
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_1_DELTA_SIGN_I_POS    29
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_1_DELTA_VAL_I_MASK    ((uint32_t)0x1F000000)
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_1_DELTA_VAL_I_LSB    24
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_1_DELTA_VAL_I_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_1_LAST_VAL_I_MASK    ((uint32_t)0x00FFF000)
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_1_LAST_VAL_I_LSB    12
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_1_LAST_VAL_I_WIDTH    ((uint32_t)0x0000000C)
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_1_INIT_VAL_I_MASK    ((uint32_t)0x00000FFF)
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_1_INIT_VAL_I_LSB    0
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_1_INIT_VAL_I_WIDTH    ((uint32_t)0x0000000C)

#define RFIC_WRAP_WIFI_DAC_TEST_GEN_1_DELTA_SIGN_I_RST    0x0
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_1_DELTA_VAL_I_RST    0x0
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_1_LAST_VAL_I_RST    0x0
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_1_INIT_VAL_I_RST    0x0

__INLINE void rfic_wrap_wifi_dac_test_gen_1_pack(uint8_t delta_sign_i, uint8_t delta_val_i, uint16_t last_val_i, uint16_t init_val_i)
{
	ASSERT_ERR((((uint32_t)delta_sign_i << 29) & ~((uint32_t)0x20000000)) == 0);
	ASSERT_ERR((((uint32_t)delta_val_i << 24) & ~((uint32_t)0x1F000000)) == 0);
	ASSERT_ERR((((uint32_t)last_val_i << 12) & ~((uint32_t)0x00FFF000)) == 0);
	ASSERT_ERR((((uint32_t)init_val_i << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_DAC_TEST_GEN_1_ADDR,  ((uint32_t)delta_sign_i << 29) |((uint32_t)delta_val_i << 24) |((uint32_t)last_val_i << 12) |((uint32_t)init_val_i << 0));
}

__INLINE void rfic_wrap_wifi_dac_test_gen_1_unpack(uint8_t* delta_sign_i, uint8_t* delta_val_i, uint16_t* last_val_i, uint16_t* init_val_i)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_DAC_TEST_GEN_1_ADDR);

	*delta_sign_i = (localVal & ((uint32_t)0x20000000)) >>  29;
	*delta_val_i = (localVal & ((uint32_t)0x1F000000)) >>  24;
	*last_val_i = (localVal & ((uint32_t)0x00FFF000)) >>  12;
	*init_val_i = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_dac_test_gen_1_delta_sign_i_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_DAC_TEST_GEN_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x20000000)) >> 29);
}
__INLINE void rfic_wrap_wifi_dac_test_gen_1_delta_sign_i_setf(uint8_t deltasigni)
{
	ASSERT_ERR((((uint32_t)deltasigni << 29) & ~((uint32_t)0x20000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_DAC_TEST_GEN_1_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_DAC_TEST_GEN_1_ADDR) & ~((uint32_t)0x20000000)) | ((uint32_t)deltasigni <<29));
}
__INLINE uint8_t rfic_wrap_wifi_dac_test_gen_1_delta_val_i_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_DAC_TEST_GEN_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x1F000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_dac_test_gen_1_delta_val_i_setf(uint8_t deltavali)
{
	ASSERT_ERR((((uint32_t)deltavali << 24) & ~((uint32_t)0x1F000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_DAC_TEST_GEN_1_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_DAC_TEST_GEN_1_ADDR) & ~((uint32_t)0x1F000000)) | ((uint32_t)deltavali <<24));
}
__INLINE uint16_t rfic_wrap_wifi_dac_test_gen_1_last_val_i_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_DAC_TEST_GEN_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00FFF000)) >> 12);
}
__INLINE void rfic_wrap_wifi_dac_test_gen_1_last_val_i_setf(uint16_t lastvali)
{
	ASSERT_ERR((((uint32_t)lastvali << 12) & ~((uint32_t)0x00FFF000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_DAC_TEST_GEN_1_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_DAC_TEST_GEN_1_ADDR) & ~((uint32_t)0x00FFF000)) | ((uint32_t)lastvali <<12));
}
__INLINE uint16_t rfic_wrap_wifi_dac_test_gen_1_init_val_i_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_DAC_TEST_GEN_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}
__INLINE void rfic_wrap_wifi_dac_test_gen_1_init_val_i_setf(uint16_t initvali)
{
	ASSERT_ERR((((uint32_t)initvali << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_DAC_TEST_GEN_1_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_DAC_TEST_GEN_1_ADDR) & ~((uint32_t)0x00000FFF)) | ((uint32_t)initvali <<0));
}

/**
 * @brief WIFI_DAC_TEST_GEN_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    29    DELTA_SIGN_Q              0              
 *    28:24 DELTA_VAL_Q               0x0
 *    23:12 LAST_VAL_Q                0x0
 *    11:00 INIT_VAL_Q                0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_2_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000038)
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_2_OFFSET      0x00000038
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_2_INDEX       0x0000000E
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_2_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_dac_test_gen_2_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_DAC_TEST_GEN_2_ADDR);
}

__INLINE void rfic_wrap_wifi_dac_test_gen_2_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_DAC_TEST_GEN_2_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_2_DELTA_SIGN_Q_BIT    ((uint32_t)0x20000000)
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_2_DELTA_SIGN_Q_POS    29
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_2_DELTA_VAL_Q_MASK    ((uint32_t)0x1F000000)
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_2_DELTA_VAL_Q_LSB    24
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_2_DELTA_VAL_Q_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_2_LAST_VAL_Q_MASK    ((uint32_t)0x00FFF000)
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_2_LAST_VAL_Q_LSB    12
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_2_LAST_VAL_Q_WIDTH    ((uint32_t)0x0000000C)
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_2_INIT_VAL_Q_MASK    ((uint32_t)0x00000FFF)
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_2_INIT_VAL_Q_LSB    0
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_2_INIT_VAL_Q_WIDTH    ((uint32_t)0x0000000C)

#define RFIC_WRAP_WIFI_DAC_TEST_GEN_2_DELTA_SIGN_Q_RST    0x0
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_2_DELTA_VAL_Q_RST    0x0
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_2_LAST_VAL_Q_RST    0x0
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_2_INIT_VAL_Q_RST    0x0

__INLINE void rfic_wrap_wifi_dac_test_gen_2_pack(uint8_t delta_sign_q, uint8_t delta_val_q, uint16_t last_val_q, uint16_t init_val_q)
{
	ASSERT_ERR((((uint32_t)delta_sign_q << 29) & ~((uint32_t)0x20000000)) == 0);
	ASSERT_ERR((((uint32_t)delta_val_q << 24) & ~((uint32_t)0x1F000000)) == 0);
	ASSERT_ERR((((uint32_t)last_val_q << 12) & ~((uint32_t)0x00FFF000)) == 0);
	ASSERT_ERR((((uint32_t)init_val_q << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_DAC_TEST_GEN_2_ADDR,  ((uint32_t)delta_sign_q << 29) |((uint32_t)delta_val_q << 24) |((uint32_t)last_val_q << 12) |((uint32_t)init_val_q << 0));
}

__INLINE void rfic_wrap_wifi_dac_test_gen_2_unpack(uint8_t* delta_sign_q, uint8_t* delta_val_q, uint16_t* last_val_q, uint16_t* init_val_q)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_DAC_TEST_GEN_2_ADDR);

	*delta_sign_q = (localVal & ((uint32_t)0x20000000)) >>  29;
	*delta_val_q = (localVal & ((uint32_t)0x1F000000)) >>  24;
	*last_val_q = (localVal & ((uint32_t)0x00FFF000)) >>  12;
	*init_val_q = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_dac_test_gen_2_delta_sign_q_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_DAC_TEST_GEN_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x20000000)) >> 29);
}
__INLINE void rfic_wrap_wifi_dac_test_gen_2_delta_sign_q_setf(uint8_t deltasignq)
{
	ASSERT_ERR((((uint32_t)deltasignq << 29) & ~((uint32_t)0x20000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_DAC_TEST_GEN_2_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_DAC_TEST_GEN_2_ADDR) & ~((uint32_t)0x20000000)) | ((uint32_t)deltasignq <<29));
}
__INLINE uint8_t rfic_wrap_wifi_dac_test_gen_2_delta_val_q_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_DAC_TEST_GEN_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x1F000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_dac_test_gen_2_delta_val_q_setf(uint8_t deltavalq)
{
	ASSERT_ERR((((uint32_t)deltavalq << 24) & ~((uint32_t)0x1F000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_DAC_TEST_GEN_2_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_DAC_TEST_GEN_2_ADDR) & ~((uint32_t)0x1F000000)) | ((uint32_t)deltavalq <<24));
}
__INLINE uint16_t rfic_wrap_wifi_dac_test_gen_2_last_val_q_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_DAC_TEST_GEN_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00FFF000)) >> 12);
}
__INLINE void rfic_wrap_wifi_dac_test_gen_2_last_val_q_setf(uint16_t lastvalq)
{
	ASSERT_ERR((((uint32_t)lastvalq << 12) & ~((uint32_t)0x00FFF000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_DAC_TEST_GEN_2_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_DAC_TEST_GEN_2_ADDR) & ~((uint32_t)0x00FFF000)) | ((uint32_t)lastvalq <<12));
}
__INLINE uint16_t rfic_wrap_wifi_dac_test_gen_2_init_val_q_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_DAC_TEST_GEN_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}
__INLINE void rfic_wrap_wifi_dac_test_gen_2_init_val_q_setf(uint16_t initvalq)
{
	ASSERT_ERR((((uint32_t)initvalq << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_DAC_TEST_GEN_2_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_DAC_TEST_GEN_2_ADDR) & ~((uint32_t)0x00000FFF)) | ((uint32_t)initvalq <<0));
}

/**
 * @brief WIFI_DAC_TEST_GEN_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:12 DELAY_CFG_Q               0x0
 *    11:08 DELAY_CFG_I               0x0
 *    01    LOAD_INIT_VAL             0              
 *    00    ENABLE                    0              
 * </pre>
 */
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_3_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x0000003C)
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_3_OFFSET      0x0000003C
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_3_INDEX       0x0000000F
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_3_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_dac_test_gen_3_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_DAC_TEST_GEN_3_ADDR);
}

__INLINE void rfic_wrap_wifi_dac_test_gen_3_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_DAC_TEST_GEN_3_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_3_DELAY_CFG_Q_MASK    ((uint32_t)0x0000F000)
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_3_DELAY_CFG_Q_LSB    12
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_3_DELAY_CFG_Q_WIDTH    ((uint32_t)0x00000004)
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_3_DELAY_CFG_I_MASK    ((uint32_t)0x00000F00)
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_3_DELAY_CFG_I_LSB    8
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_3_DELAY_CFG_I_WIDTH    ((uint32_t)0x00000004)
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_3_LOAD_INIT_VAL_BIT    ((uint32_t)0x00000002)
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_3_LOAD_INIT_VAL_POS    1
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_3_ENABLE_BIT    ((uint32_t)0x00000001)
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_3_ENABLE_POS    0

#define RFIC_WRAP_WIFI_DAC_TEST_GEN_3_DELAY_CFG_Q_RST    0x0
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_3_DELAY_CFG_I_RST    0x0
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_3_LOAD_INIT_VAL_RST    0x0
#define RFIC_WRAP_WIFI_DAC_TEST_GEN_3_ENABLE_RST    0x0

__INLINE void rfic_wrap_wifi_dac_test_gen_3_pack(uint8_t delay_cfg_q, uint8_t delay_cfg_i, uint8_t load_init_val, uint8_t enable)
{
	ASSERT_ERR((((uint32_t)delay_cfg_q << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)delay_cfg_i << 8) & ~((uint32_t)0x00000F00)) == 0);
	ASSERT_ERR((((uint32_t)load_init_val << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)enable << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_DAC_TEST_GEN_3_ADDR,  ((uint32_t)delay_cfg_q << 12) |((uint32_t)delay_cfg_i << 8) |((uint32_t)load_init_val << 1) |((uint32_t)enable << 0));
}

__INLINE void rfic_wrap_wifi_dac_test_gen_3_unpack(uint8_t* delay_cfg_q, uint8_t* delay_cfg_i, uint8_t* load_init_val, uint8_t* enable)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_DAC_TEST_GEN_3_ADDR);

	*delay_cfg_q = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*delay_cfg_i = (localVal & ((uint32_t)0x00000F00)) >>  8;
	*load_init_val = (localVal & ((uint32_t)0x00000002)) >>  1;
	*enable = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_dac_test_gen_3_delay_cfg_q_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_DAC_TEST_GEN_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void rfic_wrap_wifi_dac_test_gen_3_delay_cfg_q_setf(uint8_t delaycfgq)
{
	ASSERT_ERR((((uint32_t)delaycfgq << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_DAC_TEST_GEN_3_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_DAC_TEST_GEN_3_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)delaycfgq <<12));
}
__INLINE uint8_t rfic_wrap_wifi_dac_test_gen_3_delay_cfg_i_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_DAC_TEST_GEN_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000F00)) >> 8);
}
__INLINE void rfic_wrap_wifi_dac_test_gen_3_delay_cfg_i_setf(uint8_t delaycfgi)
{
	ASSERT_ERR((((uint32_t)delaycfgi << 8) & ~((uint32_t)0x00000F00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_DAC_TEST_GEN_3_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_DAC_TEST_GEN_3_ADDR) & ~((uint32_t)0x00000F00)) | ((uint32_t)delaycfgi <<8));
}
__INLINE void rfic_wrap_wifi_dac_test_gen_3_load_init_val_setf(uint8_t loadinitval)
{
	ASSERT_ERR((((uint32_t)loadinitval << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_DAC_TEST_GEN_3_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_DAC_TEST_GEN_3_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)loadinitval <<1));
}
__INLINE uint8_t rfic_wrap_wifi_dac_test_gen_3_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_DAC_TEST_GEN_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void rfic_wrap_wifi_dac_test_gen_3_enable_setf(uint8_t enable)
{
	ASSERT_ERR((((uint32_t)enable << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_DAC_TEST_GEN_3_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_DAC_TEST_GEN_3_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)enable <<0));
}

/**
 * @brief LB_CFG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    04    BT_RX_LB_SEL              0              
 *    03    BT_TX_LB_SEL              0              
 *    02:01 WIFI_ADC1_LB_SEL          0x0
 *    00    WIFI_ADC0_LB_SEL          0              
 * </pre>
 */
#define RFIC_WRAP_LB_CFG_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000040)
#define RFIC_WRAP_LB_CFG_OFFSET      0x00000040
#define RFIC_WRAP_LB_CFG_INDEX       0x00000010
#define RFIC_WRAP_LB_CFG_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_lb_cfg_get(void)
{
	return REG_PL_RD(RFIC_WRAP_LB_CFG_ADDR);
}

__INLINE void rfic_wrap_lb_cfg_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_LB_CFG_ADDR, value);
}

// field definitions
#define RFIC_WRAP_LB_CFG_BT_RX_LB_SEL_BIT    ((uint32_t)0x00000010)
#define RFIC_WRAP_LB_CFG_BT_RX_LB_SEL_POS    4
#define RFIC_WRAP_LB_CFG_BT_TX_LB_SEL_BIT    ((uint32_t)0x00000008)
#define RFIC_WRAP_LB_CFG_BT_TX_LB_SEL_POS    3
#define RFIC_WRAP_LB_CFG_WIFI_ADC_1_LB_SEL_MASK    ((uint32_t)0x00000006)
#define RFIC_WRAP_LB_CFG_WIFI_ADC_1_LB_SEL_LSB    1
#define RFIC_WRAP_LB_CFG_WIFI_ADC_1_LB_SEL_WIDTH    ((uint32_t)0x00000002)
#define RFIC_WRAP_LB_CFG_WIFI_ADC_0_LB_SEL_BIT    ((uint32_t)0x00000001)
#define RFIC_WRAP_LB_CFG_WIFI_ADC_0_LB_SEL_POS    0

#define RFIC_WRAP_LB_CFG_BT_RX_LB_SEL_RST    0x0
#define RFIC_WRAP_LB_CFG_BT_TX_LB_SEL_RST    0x0
#define RFIC_WRAP_LB_CFG_WIFI_ADC_1_LB_SEL_RST    0x0
#define RFIC_WRAP_LB_CFG_WIFI_ADC_0_LB_SEL_RST    0x0

__INLINE void rfic_wrap_lb_cfg_pack(uint8_t bt_rx_lb_sel, uint8_t bt_tx_lb_sel, uint8_t wifi_adc1_lb_sel, uint8_t wifi_adc0_lb_sel)
{
	ASSERT_ERR((((uint32_t)bt_rx_lb_sel << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)bt_tx_lb_sel << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)wifi_adc1_lb_sel << 1) & ~((uint32_t)0x00000006)) == 0);
	ASSERT_ERR((((uint32_t)wifi_adc0_lb_sel << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RFIC_WRAP_LB_CFG_ADDR,  ((uint32_t)bt_rx_lb_sel << 4) |((uint32_t)bt_tx_lb_sel << 3) |((uint32_t)wifi_adc1_lb_sel << 1) |((uint32_t)wifi_adc0_lb_sel << 0));
}

__INLINE void rfic_wrap_lb_cfg_unpack(uint8_t* bt_rx_lb_sel, uint8_t* bt_tx_lb_sel, uint8_t* wifi_adc1_lb_sel, uint8_t* wifi_adc0_lb_sel)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_LB_CFG_ADDR);

	*bt_rx_lb_sel = (localVal & ((uint32_t)0x00000010)) >>  4;
	*bt_tx_lb_sel = (localVal & ((uint32_t)0x00000008)) >>  3;
	*wifi_adc1_lb_sel = (localVal & ((uint32_t)0x00000006)) >>  1;
	*wifi_adc0_lb_sel = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t rfic_wrap_lb_cfg_bt_rx_lb_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_LB_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void rfic_wrap_lb_cfg_bt_rx_lb_sel_setf(uint8_t btrxlbsel)
{
	ASSERT_ERR((((uint32_t)btrxlbsel << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(RFIC_WRAP_LB_CFG_ADDR, (REG_PL_RD(RFIC_WRAP_LB_CFG_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)btrxlbsel <<4));
}
__INLINE uint8_t rfic_wrap_lb_cfg_bt_tx_lb_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_LB_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void rfic_wrap_lb_cfg_bt_tx_lb_sel_setf(uint8_t bttxlbsel)
{
	ASSERT_ERR((((uint32_t)bttxlbsel << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(RFIC_WRAP_LB_CFG_ADDR, (REG_PL_RD(RFIC_WRAP_LB_CFG_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)bttxlbsel <<3));
}
__INLINE uint8_t rfic_wrap_lb_cfg_wifi_adc_1_lb_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_LB_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000006)) >> 1);
}
__INLINE void rfic_wrap_lb_cfg_wifi_adc_1_lb_sel_setf(uint8_t wifiadc1lbsel)
{
	ASSERT_ERR((((uint32_t)wifiadc1lbsel << 1) & ~((uint32_t)0x00000006)) == 0);
	REG_PL_WR(RFIC_WRAP_LB_CFG_ADDR, (REG_PL_RD(RFIC_WRAP_LB_CFG_ADDR) & ~((uint32_t)0x00000006)) | ((uint32_t)wifiadc1lbsel <<1));
}
__INLINE uint8_t rfic_wrap_lb_cfg_wifi_adc_0_lb_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_LB_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void rfic_wrap_lb_cfg_wifi_adc_0_lb_sel_setf(uint8_t wifiadc0lbsel)
{
	ASSERT_ERR((((uint32_t)wifiadc0lbsel << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RFIC_WRAP_LB_CFG_ADDR, (REG_PL_RD(RFIC_WRAP_LB_CFG_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)wifiadc0lbsel <<0));
}

/**
 * @brief AUX_ADC_STAT_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:12 AUX_ADC_DATA_1            0x0
 *    11:00 AUX_ADC_DATA_0            0x0
 * </pre>
 */
#define RFIC_WRAP_AUX_ADC_STAT_0_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000060)
#define RFIC_WRAP_AUX_ADC_STAT_0_OFFSET      0x00000060
#define RFIC_WRAP_AUX_ADC_STAT_0_INDEX       0x00000018
#define RFIC_WRAP_AUX_ADC_STAT_0_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_aux_adc_stat_0_get(void)
{
	return REG_PL_RD(RFIC_WRAP_AUX_ADC_STAT_0_ADDR);
}

// field definitions
#define RFIC_WRAP_AUX_ADC_STAT_0_AUX_ADC_DATA_1_MASK    ((uint32_t)0x00FFF000)
#define RFIC_WRAP_AUX_ADC_STAT_0_AUX_ADC_DATA_1_LSB    12
#define RFIC_WRAP_AUX_ADC_STAT_0_AUX_ADC_DATA_1_WIDTH    ((uint32_t)0x0000000C)
#define RFIC_WRAP_AUX_ADC_STAT_0_AUX_ADC_DATA_0_MASK    ((uint32_t)0x00000FFF)
#define RFIC_WRAP_AUX_ADC_STAT_0_AUX_ADC_DATA_0_LSB    0
#define RFIC_WRAP_AUX_ADC_STAT_0_AUX_ADC_DATA_0_WIDTH    ((uint32_t)0x0000000C)

#define RFIC_WRAP_AUX_ADC_STAT_0_AUX_ADC_DATA_1_RST    0x0
#define RFIC_WRAP_AUX_ADC_STAT_0_AUX_ADC_DATA_0_RST    0x0

__INLINE void rfic_wrap_aux_adc_stat_0_unpack(uint16_t* aux_adc_data_1, uint16_t* aux_adc_data_0)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_AUX_ADC_STAT_0_ADDR);

	*aux_adc_data_1 = (localVal & ((uint32_t)0x00FFF000)) >>  12;
	*aux_adc_data_0 = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t rfic_wrap_aux_adc_stat_0_aux_adc_data_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_AUX_ADC_STAT_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00FFF000)) >> 12);
}
__INLINE uint16_t rfic_wrap_aux_adc_stat_0_aux_adc_data_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_AUX_ADC_STAT_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}

/**
 * @brief AUX_ADC_STAT_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:12 AUX_ADC_DATA_3            0x0
 *    11:00 AUX_ADC_DATA_2            0x0
 * </pre>
 */
#define RFIC_WRAP_AUX_ADC_STAT_1_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000064)
#define RFIC_WRAP_AUX_ADC_STAT_1_OFFSET      0x00000064
#define RFIC_WRAP_AUX_ADC_STAT_1_INDEX       0x00000019
#define RFIC_WRAP_AUX_ADC_STAT_1_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_aux_adc_stat_1_get(void)
{
	return REG_PL_RD(RFIC_WRAP_AUX_ADC_STAT_1_ADDR);
}

// field definitions
#define RFIC_WRAP_AUX_ADC_STAT_1_AUX_ADC_DATA_3_MASK    ((uint32_t)0x00FFF000)
#define RFIC_WRAP_AUX_ADC_STAT_1_AUX_ADC_DATA_3_LSB    12
#define RFIC_WRAP_AUX_ADC_STAT_1_AUX_ADC_DATA_3_WIDTH    ((uint32_t)0x0000000C)
#define RFIC_WRAP_AUX_ADC_STAT_1_AUX_ADC_DATA_2_MASK    ((uint32_t)0x00000FFF)
#define RFIC_WRAP_AUX_ADC_STAT_1_AUX_ADC_DATA_2_LSB    0
#define RFIC_WRAP_AUX_ADC_STAT_1_AUX_ADC_DATA_2_WIDTH    ((uint32_t)0x0000000C)

#define RFIC_WRAP_AUX_ADC_STAT_1_AUX_ADC_DATA_3_RST    0x0
#define RFIC_WRAP_AUX_ADC_STAT_1_AUX_ADC_DATA_2_RST    0x0

__INLINE void rfic_wrap_aux_adc_stat_1_unpack(uint16_t* aux_adc_data_3, uint16_t* aux_adc_data_2)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_AUX_ADC_STAT_1_ADDR);

	*aux_adc_data_3 = (localVal & ((uint32_t)0x00FFF000)) >>  12;
	*aux_adc_data_2 = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t rfic_wrap_aux_adc_stat_1_aux_adc_data_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_AUX_ADC_STAT_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00FFF000)) >> 12);
}
__INLINE uint16_t rfic_wrap_aux_adc_stat_1_aux_adc_data_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_AUX_ADC_STAT_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}

/**
 * @brief AUX_ADC_STAT_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:12 AUX_ADC_DATA_5            0x0
 *    11:00 AUX_ADC_DATA_4            0x0
 * </pre>
 */
#define RFIC_WRAP_AUX_ADC_STAT_2_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000068)
#define RFIC_WRAP_AUX_ADC_STAT_2_OFFSET      0x00000068
#define RFIC_WRAP_AUX_ADC_STAT_2_INDEX       0x0000001A
#define RFIC_WRAP_AUX_ADC_STAT_2_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_aux_adc_stat_2_get(void)
{
	return REG_PL_RD(RFIC_WRAP_AUX_ADC_STAT_2_ADDR);
}

// field definitions
#define RFIC_WRAP_AUX_ADC_STAT_2_AUX_ADC_DATA_5_MASK    ((uint32_t)0x00FFF000)
#define RFIC_WRAP_AUX_ADC_STAT_2_AUX_ADC_DATA_5_LSB    12
#define RFIC_WRAP_AUX_ADC_STAT_2_AUX_ADC_DATA_5_WIDTH    ((uint32_t)0x0000000C)
#define RFIC_WRAP_AUX_ADC_STAT_2_AUX_ADC_DATA_4_MASK    ((uint32_t)0x00000FFF)
#define RFIC_WRAP_AUX_ADC_STAT_2_AUX_ADC_DATA_4_LSB    0
#define RFIC_WRAP_AUX_ADC_STAT_2_AUX_ADC_DATA_4_WIDTH    ((uint32_t)0x0000000C)

#define RFIC_WRAP_AUX_ADC_STAT_2_AUX_ADC_DATA_5_RST    0x0
#define RFIC_WRAP_AUX_ADC_STAT_2_AUX_ADC_DATA_4_RST    0x0

__INLINE void rfic_wrap_aux_adc_stat_2_unpack(uint16_t* aux_adc_data_5, uint16_t* aux_adc_data_4)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_AUX_ADC_STAT_2_ADDR);

	*aux_adc_data_5 = (localVal & ((uint32_t)0x00FFF000)) >>  12;
	*aux_adc_data_4 = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t rfic_wrap_aux_adc_stat_2_aux_adc_data_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_AUX_ADC_STAT_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00FFF000)) >> 12);
}
__INLINE uint16_t rfic_wrap_aux_adc_stat_2_aux_adc_data_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_AUX_ADC_STAT_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}

/**
 * @brief AUX_ADC_STAT_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26:24 AUX_ADC_WR_PTR            0x0
 *    23:12 AUX_ADC_DATA_7            0x0
 *    11:00 AUX_ADC_DATA_6            0x0
 * </pre>
 */
#define RFIC_WRAP_AUX_ADC_STAT_3_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x0000006C)
#define RFIC_WRAP_AUX_ADC_STAT_3_OFFSET      0x0000006C
#define RFIC_WRAP_AUX_ADC_STAT_3_INDEX       0x0000001B
#define RFIC_WRAP_AUX_ADC_STAT_3_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_aux_adc_stat_3_get(void)
{
	return REG_PL_RD(RFIC_WRAP_AUX_ADC_STAT_3_ADDR);
}

// field definitions
#define RFIC_WRAP_AUX_ADC_STAT_3_AUX_ADC_WR_PTR_MASK    ((uint32_t)0x07000000)
#define RFIC_WRAP_AUX_ADC_STAT_3_AUX_ADC_WR_PTR_LSB    24
#define RFIC_WRAP_AUX_ADC_STAT_3_AUX_ADC_WR_PTR_WIDTH    ((uint32_t)0x00000003)
#define RFIC_WRAP_AUX_ADC_STAT_3_AUX_ADC_DATA_7_MASK    ((uint32_t)0x00FFF000)
#define RFIC_WRAP_AUX_ADC_STAT_3_AUX_ADC_DATA_7_LSB    12
#define RFIC_WRAP_AUX_ADC_STAT_3_AUX_ADC_DATA_7_WIDTH    ((uint32_t)0x0000000C)
#define RFIC_WRAP_AUX_ADC_STAT_3_AUX_ADC_DATA_6_MASK    ((uint32_t)0x00000FFF)
#define RFIC_WRAP_AUX_ADC_STAT_3_AUX_ADC_DATA_6_LSB    0
#define RFIC_WRAP_AUX_ADC_STAT_3_AUX_ADC_DATA_6_WIDTH    ((uint32_t)0x0000000C)

#define RFIC_WRAP_AUX_ADC_STAT_3_AUX_ADC_WR_PTR_RST    0x0
#define RFIC_WRAP_AUX_ADC_STAT_3_AUX_ADC_DATA_7_RST    0x0
#define RFIC_WRAP_AUX_ADC_STAT_3_AUX_ADC_DATA_6_RST    0x0

__INLINE void rfic_wrap_aux_adc_stat_3_unpack(uint8_t* aux_adc_wr_ptr, uint16_t* aux_adc_data_7, uint16_t* aux_adc_data_6)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_AUX_ADC_STAT_3_ADDR);

	*aux_adc_wr_ptr = (localVal & ((uint32_t)0x07000000)) >>  24;
	*aux_adc_data_7 = (localVal & ((uint32_t)0x00FFF000)) >>  12;
	*aux_adc_data_6 = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint8_t rfic_wrap_aux_adc_stat_3_aux_adc_wr_ptr_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_AUX_ADC_STAT_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE uint16_t rfic_wrap_aux_adc_stat_3_aux_adc_data_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_AUX_ADC_STAT_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00FFF000)) >> 12);
}
__INLINE uint16_t rfic_wrap_aux_adc_stat_3_aux_adc_data_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_AUX_ADC_STAT_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}

/**
 * @brief AUX_ADC_SW_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    AUX_ADC_CALN              0              
 * </pre>
 */
#define RFIC_WRAP_AUX_ADC_SW_CTRL_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000070)
#define RFIC_WRAP_AUX_ADC_SW_CTRL_OFFSET      0x00000070
#define RFIC_WRAP_AUX_ADC_SW_CTRL_INDEX       0x0000001C
#define RFIC_WRAP_AUX_ADC_SW_CTRL_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_aux_adc_sw_ctrl_get(void)
{
	return REG_PL_RD(RFIC_WRAP_AUX_ADC_SW_CTRL_ADDR);
}

__INLINE void rfic_wrap_aux_adc_sw_ctrl_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_AUX_ADC_SW_CTRL_ADDR, value);
}

// field definitions
#define RFIC_WRAP_AUX_ADC_SW_CTRL_AUX_ADC_CALN_BIT    ((uint32_t)0x00000001)
#define RFIC_WRAP_AUX_ADC_SW_CTRL_AUX_ADC_CALN_POS    0

#define RFIC_WRAP_AUX_ADC_SW_CTRL_AUX_ADC_CALN_RST    0x0

__INLINE uint8_t rfic_wrap_aux_adc_sw_ctrl_aux_adc_caln_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_AUX_ADC_SW_CTRL_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void rfic_wrap_aux_adc_sw_ctrl_aux_adc_caln_setf(uint8_t auxadccaln)
{
	ASSERT_ERR((((uint32_t)auxadccaln << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RFIC_WRAP_AUX_ADC_SW_CTRL_ADDR, (uint32_t)auxadccaln << 0);
}

/**
 * @brief DEBUG_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    08    DEBUG_EN                  0              
 *    04:00 DEBUG_SEL                 0x0
 * </pre>
 */
#define RFIC_WRAP_DEBUG_CTRL_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000074)
#define RFIC_WRAP_DEBUG_CTRL_OFFSET      0x00000074
#define RFIC_WRAP_DEBUG_CTRL_INDEX       0x0000001D
#define RFIC_WRAP_DEBUG_CTRL_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_debug_ctrl_get(void)
{
	return REG_PL_RD(RFIC_WRAP_DEBUG_CTRL_ADDR);
}

__INLINE void rfic_wrap_debug_ctrl_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_DEBUG_CTRL_ADDR, value);
}

// field definitions
#define RFIC_WRAP_DEBUG_CTRL_DEBUG_EN_BIT    ((uint32_t)0x00000100)
#define RFIC_WRAP_DEBUG_CTRL_DEBUG_EN_POS    8
#define RFIC_WRAP_DEBUG_CTRL_DEBUG_SEL_MASK    ((uint32_t)0x0000001F)
#define RFIC_WRAP_DEBUG_CTRL_DEBUG_SEL_LSB    0
#define RFIC_WRAP_DEBUG_CTRL_DEBUG_SEL_WIDTH    ((uint32_t)0x00000005)

#define RFIC_WRAP_DEBUG_CTRL_DEBUG_EN_RST    0x0
#define RFIC_WRAP_DEBUG_CTRL_DEBUG_SEL_RST    0x0

__INLINE void rfic_wrap_debug_ctrl_pack(uint8_t debug_en, uint8_t debug_sel)
{
	ASSERT_ERR((((uint32_t)debug_en << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)debug_sel << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_DEBUG_CTRL_ADDR,  ((uint32_t)debug_en << 8) |((uint32_t)debug_sel << 0));
}

__INLINE void rfic_wrap_debug_ctrl_unpack(uint8_t* debug_en, uint8_t* debug_sel)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_DEBUG_CTRL_ADDR);

	*debug_en = (localVal & ((uint32_t)0x00000100)) >>  8;
	*debug_sel = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t rfic_wrap_debug_ctrl_debug_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_DEBUG_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void rfic_wrap_debug_ctrl_debug_en_setf(uint8_t debugen)
{
	ASSERT_ERR((((uint32_t)debugen << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(RFIC_WRAP_DEBUG_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_DEBUG_CTRL_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)debugen <<8));
}
__INLINE uint8_t rfic_wrap_debug_ctrl_debug_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_DEBUG_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void rfic_wrap_debug_ctrl_debug_sel_setf(uint8_t debugsel)
{
	ASSERT_ERR((((uint32_t)debugsel << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_DEBUG_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_DEBUG_CTRL_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)debugsel <<0));
}

/**
 * @brief WIFI_RF_RX_CH_0_LNA_0_DCOC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28:24 BB_DCOC_QP                0x0
 *    20:16 BB_DCOC_QN                0x0
 *    12:08 BB_DCOC_IP                0x0
 *    04:00 BB_DCOC_IN                0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_DCOC_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000080)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_DCOC_OFFSET      0x00000080
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_DCOC_INDEX       0x00000020
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_DCOC_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_0_lna_0_dcoc_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_DCOC_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_0_dcoc_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_DCOC_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_DCOC_BB_DCOC_QP_MASK    ((uint32_t)0x1F000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_DCOC_BB_DCOC_QP_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_DCOC_BB_DCOC_QP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_DCOC_BB_DCOC_QN_MASK    ((uint32_t)0x001F0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_DCOC_BB_DCOC_QN_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_DCOC_BB_DCOC_QN_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_DCOC_BB_DCOC_IP_MASK    ((uint32_t)0x00001F00)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_DCOC_BB_DCOC_IP_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_DCOC_BB_DCOC_IP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_DCOC_BB_DCOC_IN_MASK    ((uint32_t)0x0000001F)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_DCOC_BB_DCOC_IN_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_DCOC_BB_DCOC_IN_WIDTH    ((uint32_t)0x00000005)

#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_DCOC_BB_DCOC_QP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_DCOC_BB_DCOC_QN_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_DCOC_BB_DCOC_IP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_DCOC_BB_DCOC_IN_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_0_dcoc_pack(uint8_t bb_dcoc_qp, uint8_t bb_dcoc_qn, uint8_t bb_dcoc_ip, uint8_t bb_dcoc_in)
{
	ASSERT_ERR((((uint32_t)bb_dcoc_qp << 24) & ~((uint32_t)0x1F000000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_qn << 16) & ~((uint32_t)0x001F0000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_ip << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_in << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_DCOC_ADDR,  ((uint32_t)bb_dcoc_qp << 24) |((uint32_t)bb_dcoc_qn << 16) |((uint32_t)bb_dcoc_ip << 8) |((uint32_t)bb_dcoc_in << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_0_dcoc_unpack(uint8_t* bb_dcoc_qp, uint8_t* bb_dcoc_qn, uint8_t* bb_dcoc_ip, uint8_t* bb_dcoc_in)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_DCOC_ADDR);

	*bb_dcoc_qp = (localVal & ((uint32_t)0x1F000000)) >>  24;
	*bb_dcoc_qn = (localVal & ((uint32_t)0x001F0000)) >>  16;
	*bb_dcoc_ip = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*bb_dcoc_in = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_0_dcoc_bb_dcoc_qp_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x1F000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_0_dcoc_bb_dcoc_qp_setf(uint8_t bbdcocqp)
{
	ASSERT_ERR((((uint32_t)bbdcocqp << 24) & ~((uint32_t)0x1F000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_DCOC_ADDR) & ~((uint32_t)0x1F000000)) | ((uint32_t)bbdcocqp <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_0_dcoc_bb_dcoc_qn_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001F0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_0_dcoc_bb_dcoc_qn_setf(uint8_t bbdcocqn)
{
	ASSERT_ERR((((uint32_t)bbdcocqn << 16) & ~((uint32_t)0x001F0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_DCOC_ADDR) & ~((uint32_t)0x001F0000)) | ((uint32_t)bbdcocqn <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_0_dcoc_bb_dcoc_ip_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_0_dcoc_bb_dcoc_ip_setf(uint8_t bbdcocip)
{
	ASSERT_ERR((((uint32_t)bbdcocip << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_DCOC_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)bbdcocip <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_0_dcoc_bb_dcoc_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_0_dcoc_bb_dcoc_in_setf(uint8_t bbdcocin)
{
	ASSERT_ERR((((uint32_t)bbdcocin << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_DCOC_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)bbdcocin <<0));
}

/**
 * @brief WIFI_RF_RX_CH_0_LNA_1_DCOC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28:24 BB_DCOC_QP                0x0
 *    20:16 BB_DCOC_QN                0x0
 *    12:08 BB_DCOC_IP                0x0
 *    04:00 BB_DCOC_IN                0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_DCOC_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000084)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_DCOC_OFFSET      0x00000084
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_DCOC_INDEX       0x00000021
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_DCOC_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_0_lna_1_dcoc_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_DCOC_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_1_dcoc_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_DCOC_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_DCOC_BB_DCOC_QP_MASK    ((uint32_t)0x1F000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_DCOC_BB_DCOC_QP_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_DCOC_BB_DCOC_QP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_DCOC_BB_DCOC_QN_MASK    ((uint32_t)0x001F0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_DCOC_BB_DCOC_QN_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_DCOC_BB_DCOC_QN_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_DCOC_BB_DCOC_IP_MASK    ((uint32_t)0x00001F00)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_DCOC_BB_DCOC_IP_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_DCOC_BB_DCOC_IP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_DCOC_BB_DCOC_IN_MASK    ((uint32_t)0x0000001F)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_DCOC_BB_DCOC_IN_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_DCOC_BB_DCOC_IN_WIDTH    ((uint32_t)0x00000005)

#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_DCOC_BB_DCOC_QP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_DCOC_BB_DCOC_QN_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_DCOC_BB_DCOC_IP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_DCOC_BB_DCOC_IN_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_1_dcoc_pack(uint8_t bb_dcoc_qp, uint8_t bb_dcoc_qn, uint8_t bb_dcoc_ip, uint8_t bb_dcoc_in)
{
	ASSERT_ERR((((uint32_t)bb_dcoc_qp << 24) & ~((uint32_t)0x1F000000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_qn << 16) & ~((uint32_t)0x001F0000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_ip << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_in << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_DCOC_ADDR,  ((uint32_t)bb_dcoc_qp << 24) |((uint32_t)bb_dcoc_qn << 16) |((uint32_t)bb_dcoc_ip << 8) |((uint32_t)bb_dcoc_in << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_1_dcoc_unpack(uint8_t* bb_dcoc_qp, uint8_t* bb_dcoc_qn, uint8_t* bb_dcoc_ip, uint8_t* bb_dcoc_in)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_DCOC_ADDR);

	*bb_dcoc_qp = (localVal & ((uint32_t)0x1F000000)) >>  24;
	*bb_dcoc_qn = (localVal & ((uint32_t)0x001F0000)) >>  16;
	*bb_dcoc_ip = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*bb_dcoc_in = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_1_dcoc_bb_dcoc_qp_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x1F000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_1_dcoc_bb_dcoc_qp_setf(uint8_t bbdcocqp)
{
	ASSERT_ERR((((uint32_t)bbdcocqp << 24) & ~((uint32_t)0x1F000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_DCOC_ADDR) & ~((uint32_t)0x1F000000)) | ((uint32_t)bbdcocqp <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_1_dcoc_bb_dcoc_qn_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001F0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_1_dcoc_bb_dcoc_qn_setf(uint8_t bbdcocqn)
{
	ASSERT_ERR((((uint32_t)bbdcocqn << 16) & ~((uint32_t)0x001F0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_DCOC_ADDR) & ~((uint32_t)0x001F0000)) | ((uint32_t)bbdcocqn <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_1_dcoc_bb_dcoc_ip_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_1_dcoc_bb_dcoc_ip_setf(uint8_t bbdcocip)
{
	ASSERT_ERR((((uint32_t)bbdcocip << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_DCOC_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)bbdcocip <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_1_dcoc_bb_dcoc_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_1_dcoc_bb_dcoc_in_setf(uint8_t bbdcocin)
{
	ASSERT_ERR((((uint32_t)bbdcocin << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_DCOC_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)bbdcocin <<0));
}

/**
 * @brief WIFI_RF_RX_CH_0_LNA_2_DCOC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28:24 BB_DCOC_QP                0x0
 *    20:16 BB_DCOC_QN                0x0
 *    12:08 BB_DCOC_IP                0x0
 *    04:00 BB_DCOC_IN                0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_DCOC_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000088)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_DCOC_OFFSET      0x00000088
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_DCOC_INDEX       0x00000022
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_DCOC_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_0_lna_2_dcoc_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_DCOC_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_2_dcoc_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_DCOC_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_DCOC_BB_DCOC_QP_MASK    ((uint32_t)0x1F000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_DCOC_BB_DCOC_QP_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_DCOC_BB_DCOC_QP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_DCOC_BB_DCOC_QN_MASK    ((uint32_t)0x001F0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_DCOC_BB_DCOC_QN_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_DCOC_BB_DCOC_QN_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_DCOC_BB_DCOC_IP_MASK    ((uint32_t)0x00001F00)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_DCOC_BB_DCOC_IP_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_DCOC_BB_DCOC_IP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_DCOC_BB_DCOC_IN_MASK    ((uint32_t)0x0000001F)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_DCOC_BB_DCOC_IN_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_DCOC_BB_DCOC_IN_WIDTH    ((uint32_t)0x00000005)

#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_DCOC_BB_DCOC_QP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_DCOC_BB_DCOC_QN_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_DCOC_BB_DCOC_IP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_DCOC_BB_DCOC_IN_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_2_dcoc_pack(uint8_t bb_dcoc_qp, uint8_t bb_dcoc_qn, uint8_t bb_dcoc_ip, uint8_t bb_dcoc_in)
{
	ASSERT_ERR((((uint32_t)bb_dcoc_qp << 24) & ~((uint32_t)0x1F000000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_qn << 16) & ~((uint32_t)0x001F0000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_ip << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_in << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_DCOC_ADDR,  ((uint32_t)bb_dcoc_qp << 24) |((uint32_t)bb_dcoc_qn << 16) |((uint32_t)bb_dcoc_ip << 8) |((uint32_t)bb_dcoc_in << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_2_dcoc_unpack(uint8_t* bb_dcoc_qp, uint8_t* bb_dcoc_qn, uint8_t* bb_dcoc_ip, uint8_t* bb_dcoc_in)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_DCOC_ADDR);

	*bb_dcoc_qp = (localVal & ((uint32_t)0x1F000000)) >>  24;
	*bb_dcoc_qn = (localVal & ((uint32_t)0x001F0000)) >>  16;
	*bb_dcoc_ip = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*bb_dcoc_in = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_2_dcoc_bb_dcoc_qp_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x1F000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_2_dcoc_bb_dcoc_qp_setf(uint8_t bbdcocqp)
{
	ASSERT_ERR((((uint32_t)bbdcocqp << 24) & ~((uint32_t)0x1F000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_DCOC_ADDR) & ~((uint32_t)0x1F000000)) | ((uint32_t)bbdcocqp <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_2_dcoc_bb_dcoc_qn_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001F0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_2_dcoc_bb_dcoc_qn_setf(uint8_t bbdcocqn)
{
	ASSERT_ERR((((uint32_t)bbdcocqn << 16) & ~((uint32_t)0x001F0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_DCOC_ADDR) & ~((uint32_t)0x001F0000)) | ((uint32_t)bbdcocqn <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_2_dcoc_bb_dcoc_ip_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_2_dcoc_bb_dcoc_ip_setf(uint8_t bbdcocip)
{
	ASSERT_ERR((((uint32_t)bbdcocip << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_DCOC_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)bbdcocip <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_2_dcoc_bb_dcoc_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_2_dcoc_bb_dcoc_in_setf(uint8_t bbdcocin)
{
	ASSERT_ERR((((uint32_t)bbdcocin << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_DCOC_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)bbdcocin <<0));
}

/**
 * @brief WIFI_RF_RX_CH_0_LNA_3_DCOC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28:24 BB_DCOC_QP                0x0
 *    20:16 BB_DCOC_QN                0x0
 *    12:08 BB_DCOC_IP                0x0
 *    04:00 BB_DCOC_IN                0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_DCOC_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x0000008C)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_DCOC_OFFSET      0x0000008C
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_DCOC_INDEX       0x00000023
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_DCOC_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_0_lna_3_dcoc_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_DCOC_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_3_dcoc_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_DCOC_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_DCOC_BB_DCOC_QP_MASK    ((uint32_t)0x1F000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_DCOC_BB_DCOC_QP_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_DCOC_BB_DCOC_QP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_DCOC_BB_DCOC_QN_MASK    ((uint32_t)0x001F0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_DCOC_BB_DCOC_QN_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_DCOC_BB_DCOC_QN_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_DCOC_BB_DCOC_IP_MASK    ((uint32_t)0x00001F00)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_DCOC_BB_DCOC_IP_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_DCOC_BB_DCOC_IP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_DCOC_BB_DCOC_IN_MASK    ((uint32_t)0x0000001F)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_DCOC_BB_DCOC_IN_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_DCOC_BB_DCOC_IN_WIDTH    ((uint32_t)0x00000005)

#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_DCOC_BB_DCOC_QP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_DCOC_BB_DCOC_QN_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_DCOC_BB_DCOC_IP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_DCOC_BB_DCOC_IN_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_3_dcoc_pack(uint8_t bb_dcoc_qp, uint8_t bb_dcoc_qn, uint8_t bb_dcoc_ip, uint8_t bb_dcoc_in)
{
	ASSERT_ERR((((uint32_t)bb_dcoc_qp << 24) & ~((uint32_t)0x1F000000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_qn << 16) & ~((uint32_t)0x001F0000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_ip << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_in << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_DCOC_ADDR,  ((uint32_t)bb_dcoc_qp << 24) |((uint32_t)bb_dcoc_qn << 16) |((uint32_t)bb_dcoc_ip << 8) |((uint32_t)bb_dcoc_in << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_3_dcoc_unpack(uint8_t* bb_dcoc_qp, uint8_t* bb_dcoc_qn, uint8_t* bb_dcoc_ip, uint8_t* bb_dcoc_in)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_DCOC_ADDR);

	*bb_dcoc_qp = (localVal & ((uint32_t)0x1F000000)) >>  24;
	*bb_dcoc_qn = (localVal & ((uint32_t)0x001F0000)) >>  16;
	*bb_dcoc_ip = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*bb_dcoc_in = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_3_dcoc_bb_dcoc_qp_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x1F000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_3_dcoc_bb_dcoc_qp_setf(uint8_t bbdcocqp)
{
	ASSERT_ERR((((uint32_t)bbdcocqp << 24) & ~((uint32_t)0x1F000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_DCOC_ADDR) & ~((uint32_t)0x1F000000)) | ((uint32_t)bbdcocqp <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_3_dcoc_bb_dcoc_qn_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001F0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_3_dcoc_bb_dcoc_qn_setf(uint8_t bbdcocqn)
{
	ASSERT_ERR((((uint32_t)bbdcocqn << 16) & ~((uint32_t)0x001F0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_DCOC_ADDR) & ~((uint32_t)0x001F0000)) | ((uint32_t)bbdcocqn <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_3_dcoc_bb_dcoc_ip_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_3_dcoc_bb_dcoc_ip_setf(uint8_t bbdcocip)
{
	ASSERT_ERR((((uint32_t)bbdcocip << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_DCOC_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)bbdcocip <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_3_dcoc_bb_dcoc_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_3_dcoc_bb_dcoc_in_setf(uint8_t bbdcocin)
{
	ASSERT_ERR((((uint32_t)bbdcocin << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_DCOC_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)bbdcocin <<0));
}

/**
 * @brief WIFI_RF_RX_CH_0_LNA_4_DCOC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28:24 BB_DCOC_QP                0x0
 *    20:16 BB_DCOC_QN                0x0
 *    12:08 BB_DCOC_IP                0x0
 *    04:00 BB_DCOC_IN                0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_DCOC_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000090)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_DCOC_OFFSET      0x00000090
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_DCOC_INDEX       0x00000024
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_DCOC_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_0_lna_4_dcoc_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_DCOC_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_4_dcoc_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_DCOC_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_DCOC_BB_DCOC_QP_MASK    ((uint32_t)0x1F000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_DCOC_BB_DCOC_QP_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_DCOC_BB_DCOC_QP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_DCOC_BB_DCOC_QN_MASK    ((uint32_t)0x001F0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_DCOC_BB_DCOC_QN_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_DCOC_BB_DCOC_QN_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_DCOC_BB_DCOC_IP_MASK    ((uint32_t)0x00001F00)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_DCOC_BB_DCOC_IP_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_DCOC_BB_DCOC_IP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_DCOC_BB_DCOC_IN_MASK    ((uint32_t)0x0000001F)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_DCOC_BB_DCOC_IN_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_DCOC_BB_DCOC_IN_WIDTH    ((uint32_t)0x00000005)

#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_DCOC_BB_DCOC_QP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_DCOC_BB_DCOC_QN_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_DCOC_BB_DCOC_IP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_DCOC_BB_DCOC_IN_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_4_dcoc_pack(uint8_t bb_dcoc_qp, uint8_t bb_dcoc_qn, uint8_t bb_dcoc_ip, uint8_t bb_dcoc_in)
{
	ASSERT_ERR((((uint32_t)bb_dcoc_qp << 24) & ~((uint32_t)0x1F000000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_qn << 16) & ~((uint32_t)0x001F0000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_ip << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_in << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_DCOC_ADDR,  ((uint32_t)bb_dcoc_qp << 24) |((uint32_t)bb_dcoc_qn << 16) |((uint32_t)bb_dcoc_ip << 8) |((uint32_t)bb_dcoc_in << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_4_dcoc_unpack(uint8_t* bb_dcoc_qp, uint8_t* bb_dcoc_qn, uint8_t* bb_dcoc_ip, uint8_t* bb_dcoc_in)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_DCOC_ADDR);

	*bb_dcoc_qp = (localVal & ((uint32_t)0x1F000000)) >>  24;
	*bb_dcoc_qn = (localVal & ((uint32_t)0x001F0000)) >>  16;
	*bb_dcoc_ip = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*bb_dcoc_in = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_4_dcoc_bb_dcoc_qp_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x1F000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_4_dcoc_bb_dcoc_qp_setf(uint8_t bbdcocqp)
{
	ASSERT_ERR((((uint32_t)bbdcocqp << 24) & ~((uint32_t)0x1F000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_DCOC_ADDR) & ~((uint32_t)0x1F000000)) | ((uint32_t)bbdcocqp <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_4_dcoc_bb_dcoc_qn_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001F0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_4_dcoc_bb_dcoc_qn_setf(uint8_t bbdcocqn)
{
	ASSERT_ERR((((uint32_t)bbdcocqn << 16) & ~((uint32_t)0x001F0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_DCOC_ADDR) & ~((uint32_t)0x001F0000)) | ((uint32_t)bbdcocqn <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_4_dcoc_bb_dcoc_ip_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_4_dcoc_bb_dcoc_ip_setf(uint8_t bbdcocip)
{
	ASSERT_ERR((((uint32_t)bbdcocip << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_DCOC_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)bbdcocip <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_4_dcoc_bb_dcoc_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_4_dcoc_bb_dcoc_in_setf(uint8_t bbdcocin)
{
	ASSERT_ERR((((uint32_t)bbdcocin << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_DCOC_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)bbdcocin <<0));
}

/**
 * @brief WIFI_RF_RX_CH_0_LNA_5_DCOC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28:24 BB_DCOC_QP                0x0
 *    20:16 BB_DCOC_QN                0x0
 *    12:08 BB_DCOC_IP                0x0
 *    04:00 BB_DCOC_IN                0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_DCOC_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000094)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_DCOC_OFFSET      0x00000094
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_DCOC_INDEX       0x00000025
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_DCOC_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_0_lna_5_dcoc_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_DCOC_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_5_dcoc_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_DCOC_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_DCOC_BB_DCOC_QP_MASK    ((uint32_t)0x1F000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_DCOC_BB_DCOC_QP_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_DCOC_BB_DCOC_QP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_DCOC_BB_DCOC_QN_MASK    ((uint32_t)0x001F0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_DCOC_BB_DCOC_QN_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_DCOC_BB_DCOC_QN_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_DCOC_BB_DCOC_IP_MASK    ((uint32_t)0x00001F00)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_DCOC_BB_DCOC_IP_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_DCOC_BB_DCOC_IP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_DCOC_BB_DCOC_IN_MASK    ((uint32_t)0x0000001F)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_DCOC_BB_DCOC_IN_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_DCOC_BB_DCOC_IN_WIDTH    ((uint32_t)0x00000005)

#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_DCOC_BB_DCOC_QP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_DCOC_BB_DCOC_QN_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_DCOC_BB_DCOC_IP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_DCOC_BB_DCOC_IN_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_5_dcoc_pack(uint8_t bb_dcoc_qp, uint8_t bb_dcoc_qn, uint8_t bb_dcoc_ip, uint8_t bb_dcoc_in)
{
	ASSERT_ERR((((uint32_t)bb_dcoc_qp << 24) & ~((uint32_t)0x1F000000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_qn << 16) & ~((uint32_t)0x001F0000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_ip << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_in << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_DCOC_ADDR,  ((uint32_t)bb_dcoc_qp << 24) |((uint32_t)bb_dcoc_qn << 16) |((uint32_t)bb_dcoc_ip << 8) |((uint32_t)bb_dcoc_in << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_5_dcoc_unpack(uint8_t* bb_dcoc_qp, uint8_t* bb_dcoc_qn, uint8_t* bb_dcoc_ip, uint8_t* bb_dcoc_in)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_DCOC_ADDR);

	*bb_dcoc_qp = (localVal & ((uint32_t)0x1F000000)) >>  24;
	*bb_dcoc_qn = (localVal & ((uint32_t)0x001F0000)) >>  16;
	*bb_dcoc_ip = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*bb_dcoc_in = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_5_dcoc_bb_dcoc_qp_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x1F000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_5_dcoc_bb_dcoc_qp_setf(uint8_t bbdcocqp)
{
	ASSERT_ERR((((uint32_t)bbdcocqp << 24) & ~((uint32_t)0x1F000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_DCOC_ADDR) & ~((uint32_t)0x1F000000)) | ((uint32_t)bbdcocqp <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_5_dcoc_bb_dcoc_qn_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001F0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_5_dcoc_bb_dcoc_qn_setf(uint8_t bbdcocqn)
{
	ASSERT_ERR((((uint32_t)bbdcocqn << 16) & ~((uint32_t)0x001F0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_DCOC_ADDR) & ~((uint32_t)0x001F0000)) | ((uint32_t)bbdcocqn <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_5_dcoc_bb_dcoc_ip_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_5_dcoc_bb_dcoc_ip_setf(uint8_t bbdcocip)
{
	ASSERT_ERR((((uint32_t)bbdcocip << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_DCOC_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)bbdcocip <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_5_dcoc_bb_dcoc_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_5_dcoc_bb_dcoc_in_setf(uint8_t bbdcocin)
{
	ASSERT_ERR((((uint32_t)bbdcocin << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_DCOC_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)bbdcocin <<0));
}

/**
 * @brief WIFI_RF_RX_CH_0_LNA_6_DCOC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28:24 BB_DCOC_QP                0x0
 *    20:16 BB_DCOC_QN                0x0
 *    12:08 BB_DCOC_IP                0x0
 *    04:00 BB_DCOC_IN                0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_DCOC_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000098)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_DCOC_OFFSET      0x00000098
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_DCOC_INDEX       0x00000026
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_DCOC_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_0_lna_6_dcoc_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_DCOC_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_6_dcoc_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_DCOC_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_DCOC_BB_DCOC_QP_MASK    ((uint32_t)0x1F000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_DCOC_BB_DCOC_QP_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_DCOC_BB_DCOC_QP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_DCOC_BB_DCOC_QN_MASK    ((uint32_t)0x001F0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_DCOC_BB_DCOC_QN_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_DCOC_BB_DCOC_QN_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_DCOC_BB_DCOC_IP_MASK    ((uint32_t)0x00001F00)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_DCOC_BB_DCOC_IP_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_DCOC_BB_DCOC_IP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_DCOC_BB_DCOC_IN_MASK    ((uint32_t)0x0000001F)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_DCOC_BB_DCOC_IN_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_DCOC_BB_DCOC_IN_WIDTH    ((uint32_t)0x00000005)

#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_DCOC_BB_DCOC_QP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_DCOC_BB_DCOC_QN_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_DCOC_BB_DCOC_IP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_DCOC_BB_DCOC_IN_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_6_dcoc_pack(uint8_t bb_dcoc_qp, uint8_t bb_dcoc_qn, uint8_t bb_dcoc_ip, uint8_t bb_dcoc_in)
{
	ASSERT_ERR((((uint32_t)bb_dcoc_qp << 24) & ~((uint32_t)0x1F000000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_qn << 16) & ~((uint32_t)0x001F0000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_ip << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_in << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_DCOC_ADDR,  ((uint32_t)bb_dcoc_qp << 24) |((uint32_t)bb_dcoc_qn << 16) |((uint32_t)bb_dcoc_ip << 8) |((uint32_t)bb_dcoc_in << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_6_dcoc_unpack(uint8_t* bb_dcoc_qp, uint8_t* bb_dcoc_qn, uint8_t* bb_dcoc_ip, uint8_t* bb_dcoc_in)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_DCOC_ADDR);

	*bb_dcoc_qp = (localVal & ((uint32_t)0x1F000000)) >>  24;
	*bb_dcoc_qn = (localVal & ((uint32_t)0x001F0000)) >>  16;
	*bb_dcoc_ip = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*bb_dcoc_in = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_6_dcoc_bb_dcoc_qp_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x1F000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_6_dcoc_bb_dcoc_qp_setf(uint8_t bbdcocqp)
{
	ASSERT_ERR((((uint32_t)bbdcocqp << 24) & ~((uint32_t)0x1F000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_DCOC_ADDR) & ~((uint32_t)0x1F000000)) | ((uint32_t)bbdcocqp <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_6_dcoc_bb_dcoc_qn_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001F0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_6_dcoc_bb_dcoc_qn_setf(uint8_t bbdcocqn)
{
	ASSERT_ERR((((uint32_t)bbdcocqn << 16) & ~((uint32_t)0x001F0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_DCOC_ADDR) & ~((uint32_t)0x001F0000)) | ((uint32_t)bbdcocqn <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_6_dcoc_bb_dcoc_ip_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_6_dcoc_bb_dcoc_ip_setf(uint8_t bbdcocip)
{
	ASSERT_ERR((((uint32_t)bbdcocip << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_DCOC_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)bbdcocip <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_6_dcoc_bb_dcoc_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_6_dcoc_bb_dcoc_in_setf(uint8_t bbdcocin)
{
	ASSERT_ERR((((uint32_t)bbdcocin << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_DCOC_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)bbdcocin <<0));
}

/**
 * @brief WIFI_RF_RX_CH_0_LNA_7_DCOC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28:24 BB_DCOC_QP                0x0
 *    20:16 BB_DCOC_QN                0x0
 *    12:08 BB_DCOC_IP                0x0
 *    04:00 BB_DCOC_IN                0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_DCOC_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x0000009C)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_DCOC_OFFSET      0x0000009C
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_DCOC_INDEX       0x00000027
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_DCOC_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_0_lna_7_dcoc_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_DCOC_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_7_dcoc_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_DCOC_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_DCOC_BB_DCOC_QP_MASK    ((uint32_t)0x1F000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_DCOC_BB_DCOC_QP_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_DCOC_BB_DCOC_QP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_DCOC_BB_DCOC_QN_MASK    ((uint32_t)0x001F0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_DCOC_BB_DCOC_QN_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_DCOC_BB_DCOC_QN_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_DCOC_BB_DCOC_IP_MASK    ((uint32_t)0x00001F00)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_DCOC_BB_DCOC_IP_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_DCOC_BB_DCOC_IP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_DCOC_BB_DCOC_IN_MASK    ((uint32_t)0x0000001F)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_DCOC_BB_DCOC_IN_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_DCOC_BB_DCOC_IN_WIDTH    ((uint32_t)0x00000005)

#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_DCOC_BB_DCOC_QP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_DCOC_BB_DCOC_QN_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_DCOC_BB_DCOC_IP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_DCOC_BB_DCOC_IN_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_7_dcoc_pack(uint8_t bb_dcoc_qp, uint8_t bb_dcoc_qn, uint8_t bb_dcoc_ip, uint8_t bb_dcoc_in)
{
	ASSERT_ERR((((uint32_t)bb_dcoc_qp << 24) & ~((uint32_t)0x1F000000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_qn << 16) & ~((uint32_t)0x001F0000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_ip << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_in << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_DCOC_ADDR,  ((uint32_t)bb_dcoc_qp << 24) |((uint32_t)bb_dcoc_qn << 16) |((uint32_t)bb_dcoc_ip << 8) |((uint32_t)bb_dcoc_in << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_7_dcoc_unpack(uint8_t* bb_dcoc_qp, uint8_t* bb_dcoc_qn, uint8_t* bb_dcoc_ip, uint8_t* bb_dcoc_in)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_DCOC_ADDR);

	*bb_dcoc_qp = (localVal & ((uint32_t)0x1F000000)) >>  24;
	*bb_dcoc_qn = (localVal & ((uint32_t)0x001F0000)) >>  16;
	*bb_dcoc_ip = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*bb_dcoc_in = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_7_dcoc_bb_dcoc_qp_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x1F000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_7_dcoc_bb_dcoc_qp_setf(uint8_t bbdcocqp)
{
	ASSERT_ERR((((uint32_t)bbdcocqp << 24) & ~((uint32_t)0x1F000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_DCOC_ADDR) & ~((uint32_t)0x1F000000)) | ((uint32_t)bbdcocqp <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_7_dcoc_bb_dcoc_qn_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001F0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_7_dcoc_bb_dcoc_qn_setf(uint8_t bbdcocqn)
{
	ASSERT_ERR((((uint32_t)bbdcocqn << 16) & ~((uint32_t)0x001F0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_DCOC_ADDR) & ~((uint32_t)0x001F0000)) | ((uint32_t)bbdcocqn <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_7_dcoc_bb_dcoc_ip_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_7_dcoc_bb_dcoc_ip_setf(uint8_t bbdcocip)
{
	ASSERT_ERR((((uint32_t)bbdcocip << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_DCOC_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)bbdcocip <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_7_dcoc_bb_dcoc_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_7_dcoc_bb_dcoc_in_setf(uint8_t bbdcocin)
{
	ASSERT_ERR((((uint32_t)bbdcocin << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_DCOC_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)bbdcocin <<0));
}

/**
 * @brief WIFI_RF_RX_CH_0_LNA_8_DCOC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28:24 BB_DCOC_QP                0x0
 *    20:16 BB_DCOC_QN                0x0
 *    12:08 BB_DCOC_IP                0x0
 *    04:00 BB_DCOC_IN                0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_DCOC_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x000000A0)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_DCOC_OFFSET      0x000000A0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_DCOC_INDEX       0x00000028
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_DCOC_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_0_lna_8_dcoc_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_DCOC_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_8_dcoc_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_DCOC_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_DCOC_BB_DCOC_QP_MASK    ((uint32_t)0x1F000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_DCOC_BB_DCOC_QP_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_DCOC_BB_DCOC_QP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_DCOC_BB_DCOC_QN_MASK    ((uint32_t)0x001F0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_DCOC_BB_DCOC_QN_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_DCOC_BB_DCOC_QN_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_DCOC_BB_DCOC_IP_MASK    ((uint32_t)0x00001F00)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_DCOC_BB_DCOC_IP_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_DCOC_BB_DCOC_IP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_DCOC_BB_DCOC_IN_MASK    ((uint32_t)0x0000001F)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_DCOC_BB_DCOC_IN_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_DCOC_BB_DCOC_IN_WIDTH    ((uint32_t)0x00000005)

#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_DCOC_BB_DCOC_QP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_DCOC_BB_DCOC_QN_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_DCOC_BB_DCOC_IP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_DCOC_BB_DCOC_IN_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_8_dcoc_pack(uint8_t bb_dcoc_qp, uint8_t bb_dcoc_qn, uint8_t bb_dcoc_ip, uint8_t bb_dcoc_in)
{
	ASSERT_ERR((((uint32_t)bb_dcoc_qp << 24) & ~((uint32_t)0x1F000000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_qn << 16) & ~((uint32_t)0x001F0000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_ip << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_in << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_DCOC_ADDR,  ((uint32_t)bb_dcoc_qp << 24) |((uint32_t)bb_dcoc_qn << 16) |((uint32_t)bb_dcoc_ip << 8) |((uint32_t)bb_dcoc_in << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_8_dcoc_unpack(uint8_t* bb_dcoc_qp, uint8_t* bb_dcoc_qn, uint8_t* bb_dcoc_ip, uint8_t* bb_dcoc_in)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_DCOC_ADDR);

	*bb_dcoc_qp = (localVal & ((uint32_t)0x1F000000)) >>  24;
	*bb_dcoc_qn = (localVal & ((uint32_t)0x001F0000)) >>  16;
	*bb_dcoc_ip = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*bb_dcoc_in = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_8_dcoc_bb_dcoc_qp_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x1F000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_8_dcoc_bb_dcoc_qp_setf(uint8_t bbdcocqp)
{
	ASSERT_ERR((((uint32_t)bbdcocqp << 24) & ~((uint32_t)0x1F000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_DCOC_ADDR) & ~((uint32_t)0x1F000000)) | ((uint32_t)bbdcocqp <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_8_dcoc_bb_dcoc_qn_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001F0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_8_dcoc_bb_dcoc_qn_setf(uint8_t bbdcocqn)
{
	ASSERT_ERR((((uint32_t)bbdcocqn << 16) & ~((uint32_t)0x001F0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_DCOC_ADDR) & ~((uint32_t)0x001F0000)) | ((uint32_t)bbdcocqn <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_8_dcoc_bb_dcoc_ip_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_8_dcoc_bb_dcoc_ip_setf(uint8_t bbdcocip)
{
	ASSERT_ERR((((uint32_t)bbdcocip << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_DCOC_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)bbdcocip <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_8_dcoc_bb_dcoc_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_8_dcoc_bb_dcoc_in_setf(uint8_t bbdcocin)
{
	ASSERT_ERR((((uint32_t)bbdcocin << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_DCOC_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)bbdcocin <<0));
}

/**
 * @brief WIFI_RF_RX_CH_0_LNA_9_DCOC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28:24 BB_DCOC_QP                0x0
 *    20:16 BB_DCOC_QN                0x0
 *    12:08 BB_DCOC_IP                0x0
 *    04:00 BB_DCOC_IN                0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_DCOC_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x000000A4)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_DCOC_OFFSET      0x000000A4
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_DCOC_INDEX       0x00000029
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_DCOC_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_0_lna_9_dcoc_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_DCOC_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_9_dcoc_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_DCOC_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_DCOC_BB_DCOC_QP_MASK    ((uint32_t)0x1F000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_DCOC_BB_DCOC_QP_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_DCOC_BB_DCOC_QP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_DCOC_BB_DCOC_QN_MASK    ((uint32_t)0x001F0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_DCOC_BB_DCOC_QN_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_DCOC_BB_DCOC_QN_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_DCOC_BB_DCOC_IP_MASK    ((uint32_t)0x00001F00)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_DCOC_BB_DCOC_IP_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_DCOC_BB_DCOC_IP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_DCOC_BB_DCOC_IN_MASK    ((uint32_t)0x0000001F)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_DCOC_BB_DCOC_IN_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_DCOC_BB_DCOC_IN_WIDTH    ((uint32_t)0x00000005)

#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_DCOC_BB_DCOC_QP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_DCOC_BB_DCOC_QN_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_DCOC_BB_DCOC_IP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_DCOC_BB_DCOC_IN_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_9_dcoc_pack(uint8_t bb_dcoc_qp, uint8_t bb_dcoc_qn, uint8_t bb_dcoc_ip, uint8_t bb_dcoc_in)
{
	ASSERT_ERR((((uint32_t)bb_dcoc_qp << 24) & ~((uint32_t)0x1F000000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_qn << 16) & ~((uint32_t)0x001F0000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_ip << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_in << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_DCOC_ADDR,  ((uint32_t)bb_dcoc_qp << 24) |((uint32_t)bb_dcoc_qn << 16) |((uint32_t)bb_dcoc_ip << 8) |((uint32_t)bb_dcoc_in << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_9_dcoc_unpack(uint8_t* bb_dcoc_qp, uint8_t* bb_dcoc_qn, uint8_t* bb_dcoc_ip, uint8_t* bb_dcoc_in)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_DCOC_ADDR);

	*bb_dcoc_qp = (localVal & ((uint32_t)0x1F000000)) >>  24;
	*bb_dcoc_qn = (localVal & ((uint32_t)0x001F0000)) >>  16;
	*bb_dcoc_ip = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*bb_dcoc_in = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_9_dcoc_bb_dcoc_qp_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x1F000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_9_dcoc_bb_dcoc_qp_setf(uint8_t bbdcocqp)
{
	ASSERT_ERR((((uint32_t)bbdcocqp << 24) & ~((uint32_t)0x1F000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_DCOC_ADDR) & ~((uint32_t)0x1F000000)) | ((uint32_t)bbdcocqp <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_9_dcoc_bb_dcoc_qn_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001F0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_9_dcoc_bb_dcoc_qn_setf(uint8_t bbdcocqn)
{
	ASSERT_ERR((((uint32_t)bbdcocqn << 16) & ~((uint32_t)0x001F0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_DCOC_ADDR) & ~((uint32_t)0x001F0000)) | ((uint32_t)bbdcocqn <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_9_dcoc_bb_dcoc_ip_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_9_dcoc_bb_dcoc_ip_setf(uint8_t bbdcocip)
{
	ASSERT_ERR((((uint32_t)bbdcocip << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_DCOC_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)bbdcocip <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_9_dcoc_bb_dcoc_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_9_dcoc_bb_dcoc_in_setf(uint8_t bbdcocin)
{
	ASSERT_ERR((((uint32_t)bbdcocin << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_DCOC_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)bbdcocin <<0));
}

/**
 * @brief WIFI_RF_RX_CH_0_LNA_10_DCOC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28:24 BB_DCOC_QP                0x0
 *    20:16 BB_DCOC_QN                0x0
 *    12:08 BB_DCOC_IP                0x0
 *    04:00 BB_DCOC_IN                0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_DCOC_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x000000A8)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_DCOC_OFFSET      0x000000A8
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_DCOC_INDEX       0x0000002A
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_DCOC_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_0_lna_10_dcoc_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_DCOC_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_10_dcoc_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_DCOC_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_DCOC_BB_DCOC_QP_MASK    ((uint32_t)0x1F000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_DCOC_BB_DCOC_QP_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_DCOC_BB_DCOC_QP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_DCOC_BB_DCOC_QN_MASK    ((uint32_t)0x001F0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_DCOC_BB_DCOC_QN_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_DCOC_BB_DCOC_QN_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_DCOC_BB_DCOC_IP_MASK    ((uint32_t)0x00001F00)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_DCOC_BB_DCOC_IP_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_DCOC_BB_DCOC_IP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_DCOC_BB_DCOC_IN_MASK    ((uint32_t)0x0000001F)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_DCOC_BB_DCOC_IN_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_DCOC_BB_DCOC_IN_WIDTH    ((uint32_t)0x00000005)

#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_DCOC_BB_DCOC_QP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_DCOC_BB_DCOC_QN_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_DCOC_BB_DCOC_IP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_DCOC_BB_DCOC_IN_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_10_dcoc_pack(uint8_t bb_dcoc_qp, uint8_t bb_dcoc_qn, uint8_t bb_dcoc_ip, uint8_t bb_dcoc_in)
{
	ASSERT_ERR((((uint32_t)bb_dcoc_qp << 24) & ~((uint32_t)0x1F000000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_qn << 16) & ~((uint32_t)0x001F0000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_ip << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_in << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_DCOC_ADDR,  ((uint32_t)bb_dcoc_qp << 24) |((uint32_t)bb_dcoc_qn << 16) |((uint32_t)bb_dcoc_ip << 8) |((uint32_t)bb_dcoc_in << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_10_dcoc_unpack(uint8_t* bb_dcoc_qp, uint8_t* bb_dcoc_qn, uint8_t* bb_dcoc_ip, uint8_t* bb_dcoc_in)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_DCOC_ADDR);

	*bb_dcoc_qp = (localVal & ((uint32_t)0x1F000000)) >>  24;
	*bb_dcoc_qn = (localVal & ((uint32_t)0x001F0000)) >>  16;
	*bb_dcoc_ip = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*bb_dcoc_in = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_10_dcoc_bb_dcoc_qp_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x1F000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_10_dcoc_bb_dcoc_qp_setf(uint8_t bbdcocqp)
{
	ASSERT_ERR((((uint32_t)bbdcocqp << 24) & ~((uint32_t)0x1F000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_DCOC_ADDR) & ~((uint32_t)0x1F000000)) | ((uint32_t)bbdcocqp <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_10_dcoc_bb_dcoc_qn_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001F0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_10_dcoc_bb_dcoc_qn_setf(uint8_t bbdcocqn)
{
	ASSERT_ERR((((uint32_t)bbdcocqn << 16) & ~((uint32_t)0x001F0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_DCOC_ADDR) & ~((uint32_t)0x001F0000)) | ((uint32_t)bbdcocqn <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_10_dcoc_bb_dcoc_ip_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_10_dcoc_bb_dcoc_ip_setf(uint8_t bbdcocip)
{
	ASSERT_ERR((((uint32_t)bbdcocip << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_DCOC_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)bbdcocip <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_10_dcoc_bb_dcoc_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_10_dcoc_bb_dcoc_in_setf(uint8_t bbdcocin)
{
	ASSERT_ERR((((uint32_t)bbdcocin << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_DCOC_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)bbdcocin <<0));
}

/**
 * @brief WIFI_RF_RX_CH_0_LNA_11_DCOC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28:24 BB_DCOC_QP                0x0
 *    20:16 BB_DCOC_QN                0x0
 *    12:08 BB_DCOC_IP                0x0
 *    04:00 BB_DCOC_IN                0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_DCOC_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x000000AC)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_DCOC_OFFSET      0x000000AC
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_DCOC_INDEX       0x0000002B
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_DCOC_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_0_lna_11_dcoc_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_DCOC_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_11_dcoc_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_DCOC_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_DCOC_BB_DCOC_QP_MASK    ((uint32_t)0x1F000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_DCOC_BB_DCOC_QP_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_DCOC_BB_DCOC_QP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_DCOC_BB_DCOC_QN_MASK    ((uint32_t)0x001F0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_DCOC_BB_DCOC_QN_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_DCOC_BB_DCOC_QN_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_DCOC_BB_DCOC_IP_MASK    ((uint32_t)0x00001F00)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_DCOC_BB_DCOC_IP_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_DCOC_BB_DCOC_IP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_DCOC_BB_DCOC_IN_MASK    ((uint32_t)0x0000001F)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_DCOC_BB_DCOC_IN_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_DCOC_BB_DCOC_IN_WIDTH    ((uint32_t)0x00000005)

#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_DCOC_BB_DCOC_QP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_DCOC_BB_DCOC_QN_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_DCOC_BB_DCOC_IP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_DCOC_BB_DCOC_IN_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_11_dcoc_pack(uint8_t bb_dcoc_qp, uint8_t bb_dcoc_qn, uint8_t bb_dcoc_ip, uint8_t bb_dcoc_in)
{
	ASSERT_ERR((((uint32_t)bb_dcoc_qp << 24) & ~((uint32_t)0x1F000000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_qn << 16) & ~((uint32_t)0x001F0000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_ip << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_in << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_DCOC_ADDR,  ((uint32_t)bb_dcoc_qp << 24) |((uint32_t)bb_dcoc_qn << 16) |((uint32_t)bb_dcoc_ip << 8) |((uint32_t)bb_dcoc_in << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_11_dcoc_unpack(uint8_t* bb_dcoc_qp, uint8_t* bb_dcoc_qn, uint8_t* bb_dcoc_ip, uint8_t* bb_dcoc_in)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_DCOC_ADDR);

	*bb_dcoc_qp = (localVal & ((uint32_t)0x1F000000)) >>  24;
	*bb_dcoc_qn = (localVal & ((uint32_t)0x001F0000)) >>  16;
	*bb_dcoc_ip = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*bb_dcoc_in = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_11_dcoc_bb_dcoc_qp_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x1F000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_11_dcoc_bb_dcoc_qp_setf(uint8_t bbdcocqp)
{
	ASSERT_ERR((((uint32_t)bbdcocqp << 24) & ~((uint32_t)0x1F000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_DCOC_ADDR) & ~((uint32_t)0x1F000000)) | ((uint32_t)bbdcocqp <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_11_dcoc_bb_dcoc_qn_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001F0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_11_dcoc_bb_dcoc_qn_setf(uint8_t bbdcocqn)
{
	ASSERT_ERR((((uint32_t)bbdcocqn << 16) & ~((uint32_t)0x001F0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_DCOC_ADDR) & ~((uint32_t)0x001F0000)) | ((uint32_t)bbdcocqn <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_11_dcoc_bb_dcoc_ip_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_11_dcoc_bb_dcoc_ip_setf(uint8_t bbdcocip)
{
	ASSERT_ERR((((uint32_t)bbdcocip << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_DCOC_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)bbdcocip <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_11_dcoc_bb_dcoc_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_11_dcoc_bb_dcoc_in_setf(uint8_t bbdcocin)
{
	ASSERT_ERR((((uint32_t)bbdcocin << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_DCOC_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)bbdcocin <<0));
}

/**
 * @brief WIFI_RF_RX_CH_0_LNA_12_DCOC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28:24 BB_DCOC_QP                0x0
 *    20:16 BB_DCOC_QN                0x0
 *    12:08 BB_DCOC_IP                0x0
 *    04:00 BB_DCOC_IN                0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_DCOC_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x000000B0)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_DCOC_OFFSET      0x000000B0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_DCOC_INDEX       0x0000002C
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_DCOC_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_0_lna_12_dcoc_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_DCOC_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_12_dcoc_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_DCOC_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_DCOC_BB_DCOC_QP_MASK    ((uint32_t)0x1F000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_DCOC_BB_DCOC_QP_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_DCOC_BB_DCOC_QP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_DCOC_BB_DCOC_QN_MASK    ((uint32_t)0x001F0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_DCOC_BB_DCOC_QN_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_DCOC_BB_DCOC_QN_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_DCOC_BB_DCOC_IP_MASK    ((uint32_t)0x00001F00)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_DCOC_BB_DCOC_IP_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_DCOC_BB_DCOC_IP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_DCOC_BB_DCOC_IN_MASK    ((uint32_t)0x0000001F)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_DCOC_BB_DCOC_IN_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_DCOC_BB_DCOC_IN_WIDTH    ((uint32_t)0x00000005)

#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_DCOC_BB_DCOC_QP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_DCOC_BB_DCOC_QN_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_DCOC_BB_DCOC_IP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_DCOC_BB_DCOC_IN_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_12_dcoc_pack(uint8_t bb_dcoc_qp, uint8_t bb_dcoc_qn, uint8_t bb_dcoc_ip, uint8_t bb_dcoc_in)
{
	ASSERT_ERR((((uint32_t)bb_dcoc_qp << 24) & ~((uint32_t)0x1F000000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_qn << 16) & ~((uint32_t)0x001F0000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_ip << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_in << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_DCOC_ADDR,  ((uint32_t)bb_dcoc_qp << 24) |((uint32_t)bb_dcoc_qn << 16) |((uint32_t)bb_dcoc_ip << 8) |((uint32_t)bb_dcoc_in << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_12_dcoc_unpack(uint8_t* bb_dcoc_qp, uint8_t* bb_dcoc_qn, uint8_t* bb_dcoc_ip, uint8_t* bb_dcoc_in)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_DCOC_ADDR);

	*bb_dcoc_qp = (localVal & ((uint32_t)0x1F000000)) >>  24;
	*bb_dcoc_qn = (localVal & ((uint32_t)0x001F0000)) >>  16;
	*bb_dcoc_ip = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*bb_dcoc_in = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_12_dcoc_bb_dcoc_qp_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x1F000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_12_dcoc_bb_dcoc_qp_setf(uint8_t bbdcocqp)
{
	ASSERT_ERR((((uint32_t)bbdcocqp << 24) & ~((uint32_t)0x1F000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_DCOC_ADDR) & ~((uint32_t)0x1F000000)) | ((uint32_t)bbdcocqp <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_12_dcoc_bb_dcoc_qn_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001F0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_12_dcoc_bb_dcoc_qn_setf(uint8_t bbdcocqn)
{
	ASSERT_ERR((((uint32_t)bbdcocqn << 16) & ~((uint32_t)0x001F0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_DCOC_ADDR) & ~((uint32_t)0x001F0000)) | ((uint32_t)bbdcocqn <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_12_dcoc_bb_dcoc_ip_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_12_dcoc_bb_dcoc_ip_setf(uint8_t bbdcocip)
{
	ASSERT_ERR((((uint32_t)bbdcocip << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_DCOC_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)bbdcocip <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_12_dcoc_bb_dcoc_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_12_dcoc_bb_dcoc_in_setf(uint8_t bbdcocin)
{
	ASSERT_ERR((((uint32_t)bbdcocin << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_DCOC_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)bbdcocin <<0));
}

/**
 * @brief WIFI_RF_RX_CH_0_LNA_13_DCOC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28:24 BB_DCOC_QP                0x0
 *    20:16 BB_DCOC_QN                0x0
 *    12:08 BB_DCOC_IP                0x0
 *    04:00 BB_DCOC_IN                0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_DCOC_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x000000B4)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_DCOC_OFFSET      0x000000B4
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_DCOC_INDEX       0x0000002D
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_DCOC_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_0_lna_13_dcoc_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_DCOC_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_13_dcoc_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_DCOC_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_DCOC_BB_DCOC_QP_MASK    ((uint32_t)0x1F000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_DCOC_BB_DCOC_QP_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_DCOC_BB_DCOC_QP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_DCOC_BB_DCOC_QN_MASK    ((uint32_t)0x001F0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_DCOC_BB_DCOC_QN_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_DCOC_BB_DCOC_QN_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_DCOC_BB_DCOC_IP_MASK    ((uint32_t)0x00001F00)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_DCOC_BB_DCOC_IP_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_DCOC_BB_DCOC_IP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_DCOC_BB_DCOC_IN_MASK    ((uint32_t)0x0000001F)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_DCOC_BB_DCOC_IN_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_DCOC_BB_DCOC_IN_WIDTH    ((uint32_t)0x00000005)

#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_DCOC_BB_DCOC_QP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_DCOC_BB_DCOC_QN_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_DCOC_BB_DCOC_IP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_DCOC_BB_DCOC_IN_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_13_dcoc_pack(uint8_t bb_dcoc_qp, uint8_t bb_dcoc_qn, uint8_t bb_dcoc_ip, uint8_t bb_dcoc_in)
{
	ASSERT_ERR((((uint32_t)bb_dcoc_qp << 24) & ~((uint32_t)0x1F000000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_qn << 16) & ~((uint32_t)0x001F0000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_ip << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_in << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_DCOC_ADDR,  ((uint32_t)bb_dcoc_qp << 24) |((uint32_t)bb_dcoc_qn << 16) |((uint32_t)bb_dcoc_ip << 8) |((uint32_t)bb_dcoc_in << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_13_dcoc_unpack(uint8_t* bb_dcoc_qp, uint8_t* bb_dcoc_qn, uint8_t* bb_dcoc_ip, uint8_t* bb_dcoc_in)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_DCOC_ADDR);

	*bb_dcoc_qp = (localVal & ((uint32_t)0x1F000000)) >>  24;
	*bb_dcoc_qn = (localVal & ((uint32_t)0x001F0000)) >>  16;
	*bb_dcoc_ip = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*bb_dcoc_in = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_13_dcoc_bb_dcoc_qp_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x1F000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_13_dcoc_bb_dcoc_qp_setf(uint8_t bbdcocqp)
{
	ASSERT_ERR((((uint32_t)bbdcocqp << 24) & ~((uint32_t)0x1F000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_DCOC_ADDR) & ~((uint32_t)0x1F000000)) | ((uint32_t)bbdcocqp <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_13_dcoc_bb_dcoc_qn_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001F0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_13_dcoc_bb_dcoc_qn_setf(uint8_t bbdcocqn)
{
	ASSERT_ERR((((uint32_t)bbdcocqn << 16) & ~((uint32_t)0x001F0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_DCOC_ADDR) & ~((uint32_t)0x001F0000)) | ((uint32_t)bbdcocqn <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_13_dcoc_bb_dcoc_ip_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_13_dcoc_bb_dcoc_ip_setf(uint8_t bbdcocip)
{
	ASSERT_ERR((((uint32_t)bbdcocip << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_DCOC_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)bbdcocip <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_13_dcoc_bb_dcoc_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_13_dcoc_bb_dcoc_in_setf(uint8_t bbdcocin)
{
	ASSERT_ERR((((uint32_t)bbdcocin << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_DCOC_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)bbdcocin <<0));
}

/**
 * @brief WIFI_RF_RX_CH_0_LNA_14_DCOC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28:24 BB_DCOC_QP                0x0
 *    20:16 BB_DCOC_QN                0x0
 *    12:08 BB_DCOC_IP                0x0
 *    04:00 BB_DCOC_IN                0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_DCOC_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x000000B8)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_DCOC_OFFSET      0x000000B8
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_DCOC_INDEX       0x0000002E
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_DCOC_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_0_lna_14_dcoc_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_DCOC_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_14_dcoc_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_DCOC_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_DCOC_BB_DCOC_QP_MASK    ((uint32_t)0x1F000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_DCOC_BB_DCOC_QP_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_DCOC_BB_DCOC_QP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_DCOC_BB_DCOC_QN_MASK    ((uint32_t)0x001F0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_DCOC_BB_DCOC_QN_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_DCOC_BB_DCOC_QN_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_DCOC_BB_DCOC_IP_MASK    ((uint32_t)0x00001F00)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_DCOC_BB_DCOC_IP_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_DCOC_BB_DCOC_IP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_DCOC_BB_DCOC_IN_MASK    ((uint32_t)0x0000001F)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_DCOC_BB_DCOC_IN_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_DCOC_BB_DCOC_IN_WIDTH    ((uint32_t)0x00000005)

#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_DCOC_BB_DCOC_QP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_DCOC_BB_DCOC_QN_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_DCOC_BB_DCOC_IP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_DCOC_BB_DCOC_IN_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_14_dcoc_pack(uint8_t bb_dcoc_qp, uint8_t bb_dcoc_qn, uint8_t bb_dcoc_ip, uint8_t bb_dcoc_in)
{
	ASSERT_ERR((((uint32_t)bb_dcoc_qp << 24) & ~((uint32_t)0x1F000000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_qn << 16) & ~((uint32_t)0x001F0000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_ip << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_in << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_DCOC_ADDR,  ((uint32_t)bb_dcoc_qp << 24) |((uint32_t)bb_dcoc_qn << 16) |((uint32_t)bb_dcoc_ip << 8) |((uint32_t)bb_dcoc_in << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_14_dcoc_unpack(uint8_t* bb_dcoc_qp, uint8_t* bb_dcoc_qn, uint8_t* bb_dcoc_ip, uint8_t* bb_dcoc_in)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_DCOC_ADDR);

	*bb_dcoc_qp = (localVal & ((uint32_t)0x1F000000)) >>  24;
	*bb_dcoc_qn = (localVal & ((uint32_t)0x001F0000)) >>  16;
	*bb_dcoc_ip = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*bb_dcoc_in = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_14_dcoc_bb_dcoc_qp_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x1F000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_14_dcoc_bb_dcoc_qp_setf(uint8_t bbdcocqp)
{
	ASSERT_ERR((((uint32_t)bbdcocqp << 24) & ~((uint32_t)0x1F000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_DCOC_ADDR) & ~((uint32_t)0x1F000000)) | ((uint32_t)bbdcocqp <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_14_dcoc_bb_dcoc_qn_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001F0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_14_dcoc_bb_dcoc_qn_setf(uint8_t bbdcocqn)
{
	ASSERT_ERR((((uint32_t)bbdcocqn << 16) & ~((uint32_t)0x001F0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_DCOC_ADDR) & ~((uint32_t)0x001F0000)) | ((uint32_t)bbdcocqn <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_14_dcoc_bb_dcoc_ip_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_14_dcoc_bb_dcoc_ip_setf(uint8_t bbdcocip)
{
	ASSERT_ERR((((uint32_t)bbdcocip << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_DCOC_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)bbdcocip <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_14_dcoc_bb_dcoc_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_14_dcoc_bb_dcoc_in_setf(uint8_t bbdcocin)
{
	ASSERT_ERR((((uint32_t)bbdcocin << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_DCOC_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)bbdcocin <<0));
}

/**
 * @brief WIFI_RF_RX_CH_0_LNA_15_DCOC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28:24 BB_DCOC_QP                0x0
 *    20:16 BB_DCOC_QN                0x0
 *    12:08 BB_DCOC_IP                0x0
 *    04:00 BB_DCOC_IN                0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_DCOC_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x000000BC)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_DCOC_OFFSET      0x000000BC
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_DCOC_INDEX       0x0000002F
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_DCOC_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_0_lna_15_dcoc_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_DCOC_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_15_dcoc_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_DCOC_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_DCOC_BB_DCOC_QP_MASK    ((uint32_t)0x1F000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_DCOC_BB_DCOC_QP_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_DCOC_BB_DCOC_QP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_DCOC_BB_DCOC_QN_MASK    ((uint32_t)0x001F0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_DCOC_BB_DCOC_QN_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_DCOC_BB_DCOC_QN_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_DCOC_BB_DCOC_IP_MASK    ((uint32_t)0x00001F00)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_DCOC_BB_DCOC_IP_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_DCOC_BB_DCOC_IP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_DCOC_BB_DCOC_IN_MASK    ((uint32_t)0x0000001F)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_DCOC_BB_DCOC_IN_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_DCOC_BB_DCOC_IN_WIDTH    ((uint32_t)0x00000005)

#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_DCOC_BB_DCOC_QP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_DCOC_BB_DCOC_QN_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_DCOC_BB_DCOC_IP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_DCOC_BB_DCOC_IN_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_15_dcoc_pack(uint8_t bb_dcoc_qp, uint8_t bb_dcoc_qn, uint8_t bb_dcoc_ip, uint8_t bb_dcoc_in)
{
	ASSERT_ERR((((uint32_t)bb_dcoc_qp << 24) & ~((uint32_t)0x1F000000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_qn << 16) & ~((uint32_t)0x001F0000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_ip << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_in << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_DCOC_ADDR,  ((uint32_t)bb_dcoc_qp << 24) |((uint32_t)bb_dcoc_qn << 16) |((uint32_t)bb_dcoc_ip << 8) |((uint32_t)bb_dcoc_in << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_15_dcoc_unpack(uint8_t* bb_dcoc_qp, uint8_t* bb_dcoc_qn, uint8_t* bb_dcoc_ip, uint8_t* bb_dcoc_in)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_DCOC_ADDR);

	*bb_dcoc_qp = (localVal & ((uint32_t)0x1F000000)) >>  24;
	*bb_dcoc_qn = (localVal & ((uint32_t)0x001F0000)) >>  16;
	*bb_dcoc_ip = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*bb_dcoc_in = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_15_dcoc_bb_dcoc_qp_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x1F000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_15_dcoc_bb_dcoc_qp_setf(uint8_t bbdcocqp)
{
	ASSERT_ERR((((uint32_t)bbdcocqp << 24) & ~((uint32_t)0x1F000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_DCOC_ADDR) & ~((uint32_t)0x1F000000)) | ((uint32_t)bbdcocqp <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_15_dcoc_bb_dcoc_qn_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001F0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_15_dcoc_bb_dcoc_qn_setf(uint8_t bbdcocqn)
{
	ASSERT_ERR((((uint32_t)bbdcocqn << 16) & ~((uint32_t)0x001F0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_DCOC_ADDR) & ~((uint32_t)0x001F0000)) | ((uint32_t)bbdcocqn <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_15_dcoc_bb_dcoc_ip_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_15_dcoc_bb_dcoc_ip_setf(uint8_t bbdcocip)
{
	ASSERT_ERR((((uint32_t)bbdcocip << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_DCOC_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)bbdcocip <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_15_dcoc_bb_dcoc_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_15_dcoc_bb_dcoc_in_setf(uint8_t bbdcocin)
{
	ASSERT_ERR((((uint32_t)bbdcocin << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_DCOC_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)bbdcocin <<0));
}

/**
 * @brief WIFI_RF_RX_CH_1_LNA_0_DCOC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28:24 BB_DCOC_QP                0x0
 *    20:16 BB_DCOC_QN                0x0
 *    12:08 BB_DCOC_IP                0x0
 *    04:00 BB_DCOC_IN                0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_DCOC_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x000000C0)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_DCOC_OFFSET      0x000000C0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_DCOC_INDEX       0x00000030
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_DCOC_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_1_lna_0_dcoc_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_DCOC_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_0_dcoc_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_DCOC_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_DCOC_BB_DCOC_QP_MASK    ((uint32_t)0x1F000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_DCOC_BB_DCOC_QP_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_DCOC_BB_DCOC_QP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_DCOC_BB_DCOC_QN_MASK    ((uint32_t)0x001F0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_DCOC_BB_DCOC_QN_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_DCOC_BB_DCOC_QN_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_DCOC_BB_DCOC_IP_MASK    ((uint32_t)0x00001F00)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_DCOC_BB_DCOC_IP_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_DCOC_BB_DCOC_IP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_DCOC_BB_DCOC_IN_MASK    ((uint32_t)0x0000001F)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_DCOC_BB_DCOC_IN_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_DCOC_BB_DCOC_IN_WIDTH    ((uint32_t)0x00000005)

#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_DCOC_BB_DCOC_QP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_DCOC_BB_DCOC_QN_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_DCOC_BB_DCOC_IP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_DCOC_BB_DCOC_IN_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_0_dcoc_pack(uint8_t bb_dcoc_qp, uint8_t bb_dcoc_qn, uint8_t bb_dcoc_ip, uint8_t bb_dcoc_in)
{
	ASSERT_ERR((((uint32_t)bb_dcoc_qp << 24) & ~((uint32_t)0x1F000000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_qn << 16) & ~((uint32_t)0x001F0000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_ip << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_in << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_DCOC_ADDR,  ((uint32_t)bb_dcoc_qp << 24) |((uint32_t)bb_dcoc_qn << 16) |((uint32_t)bb_dcoc_ip << 8) |((uint32_t)bb_dcoc_in << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_0_dcoc_unpack(uint8_t* bb_dcoc_qp, uint8_t* bb_dcoc_qn, uint8_t* bb_dcoc_ip, uint8_t* bb_dcoc_in)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_DCOC_ADDR);

	*bb_dcoc_qp = (localVal & ((uint32_t)0x1F000000)) >>  24;
	*bb_dcoc_qn = (localVal & ((uint32_t)0x001F0000)) >>  16;
	*bb_dcoc_ip = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*bb_dcoc_in = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_0_dcoc_bb_dcoc_qp_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x1F000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_0_dcoc_bb_dcoc_qp_setf(uint8_t bbdcocqp)
{
	ASSERT_ERR((((uint32_t)bbdcocqp << 24) & ~((uint32_t)0x1F000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_DCOC_ADDR) & ~((uint32_t)0x1F000000)) | ((uint32_t)bbdcocqp <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_0_dcoc_bb_dcoc_qn_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001F0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_0_dcoc_bb_dcoc_qn_setf(uint8_t bbdcocqn)
{
	ASSERT_ERR((((uint32_t)bbdcocqn << 16) & ~((uint32_t)0x001F0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_DCOC_ADDR) & ~((uint32_t)0x001F0000)) | ((uint32_t)bbdcocqn <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_0_dcoc_bb_dcoc_ip_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_0_dcoc_bb_dcoc_ip_setf(uint8_t bbdcocip)
{
	ASSERT_ERR((((uint32_t)bbdcocip << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_DCOC_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)bbdcocip <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_0_dcoc_bb_dcoc_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_0_dcoc_bb_dcoc_in_setf(uint8_t bbdcocin)
{
	ASSERT_ERR((((uint32_t)bbdcocin << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_DCOC_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)bbdcocin <<0));
}

/**
 * @brief WIFI_RF_RX_CH_1_LNA_1_DCOC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28:24 BB_DCOC_QP                0x0
 *    20:16 BB_DCOC_QN                0x0
 *    12:08 BB_DCOC_IP                0x0
 *    04:00 BB_DCOC_IN                0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_DCOC_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x000000C4)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_DCOC_OFFSET      0x000000C4
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_DCOC_INDEX       0x00000031
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_DCOC_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_1_lna_1_dcoc_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_DCOC_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_1_dcoc_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_DCOC_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_DCOC_BB_DCOC_QP_MASK    ((uint32_t)0x1F000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_DCOC_BB_DCOC_QP_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_DCOC_BB_DCOC_QP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_DCOC_BB_DCOC_QN_MASK    ((uint32_t)0x001F0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_DCOC_BB_DCOC_QN_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_DCOC_BB_DCOC_QN_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_DCOC_BB_DCOC_IP_MASK    ((uint32_t)0x00001F00)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_DCOC_BB_DCOC_IP_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_DCOC_BB_DCOC_IP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_DCOC_BB_DCOC_IN_MASK    ((uint32_t)0x0000001F)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_DCOC_BB_DCOC_IN_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_DCOC_BB_DCOC_IN_WIDTH    ((uint32_t)0x00000005)

#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_DCOC_BB_DCOC_QP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_DCOC_BB_DCOC_QN_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_DCOC_BB_DCOC_IP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_DCOC_BB_DCOC_IN_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_1_dcoc_pack(uint8_t bb_dcoc_qp, uint8_t bb_dcoc_qn, uint8_t bb_dcoc_ip, uint8_t bb_dcoc_in)
{
	ASSERT_ERR((((uint32_t)bb_dcoc_qp << 24) & ~((uint32_t)0x1F000000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_qn << 16) & ~((uint32_t)0x001F0000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_ip << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_in << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_DCOC_ADDR,  ((uint32_t)bb_dcoc_qp << 24) |((uint32_t)bb_dcoc_qn << 16) |((uint32_t)bb_dcoc_ip << 8) |((uint32_t)bb_dcoc_in << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_1_dcoc_unpack(uint8_t* bb_dcoc_qp, uint8_t* bb_dcoc_qn, uint8_t* bb_dcoc_ip, uint8_t* bb_dcoc_in)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_DCOC_ADDR);

	*bb_dcoc_qp = (localVal & ((uint32_t)0x1F000000)) >>  24;
	*bb_dcoc_qn = (localVal & ((uint32_t)0x001F0000)) >>  16;
	*bb_dcoc_ip = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*bb_dcoc_in = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_1_dcoc_bb_dcoc_qp_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x1F000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_1_dcoc_bb_dcoc_qp_setf(uint8_t bbdcocqp)
{
	ASSERT_ERR((((uint32_t)bbdcocqp << 24) & ~((uint32_t)0x1F000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_DCOC_ADDR) & ~((uint32_t)0x1F000000)) | ((uint32_t)bbdcocqp <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_1_dcoc_bb_dcoc_qn_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001F0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_1_dcoc_bb_dcoc_qn_setf(uint8_t bbdcocqn)
{
	ASSERT_ERR((((uint32_t)bbdcocqn << 16) & ~((uint32_t)0x001F0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_DCOC_ADDR) & ~((uint32_t)0x001F0000)) | ((uint32_t)bbdcocqn <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_1_dcoc_bb_dcoc_ip_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_1_dcoc_bb_dcoc_ip_setf(uint8_t bbdcocip)
{
	ASSERT_ERR((((uint32_t)bbdcocip << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_DCOC_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)bbdcocip <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_1_dcoc_bb_dcoc_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_1_dcoc_bb_dcoc_in_setf(uint8_t bbdcocin)
{
	ASSERT_ERR((((uint32_t)bbdcocin << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_DCOC_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)bbdcocin <<0));
}

/**
 * @brief WIFI_RF_RX_CH_1_LNA_2_DCOC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28:24 BB_DCOC_QP                0x0
 *    20:16 BB_DCOC_QN                0x0
 *    12:08 BB_DCOC_IP                0x0
 *    04:00 BB_DCOC_IN                0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_DCOC_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x000000C8)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_DCOC_OFFSET      0x000000C8
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_DCOC_INDEX       0x00000032
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_DCOC_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_1_lna_2_dcoc_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_DCOC_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_2_dcoc_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_DCOC_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_DCOC_BB_DCOC_QP_MASK    ((uint32_t)0x1F000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_DCOC_BB_DCOC_QP_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_DCOC_BB_DCOC_QP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_DCOC_BB_DCOC_QN_MASK    ((uint32_t)0x001F0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_DCOC_BB_DCOC_QN_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_DCOC_BB_DCOC_QN_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_DCOC_BB_DCOC_IP_MASK    ((uint32_t)0x00001F00)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_DCOC_BB_DCOC_IP_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_DCOC_BB_DCOC_IP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_DCOC_BB_DCOC_IN_MASK    ((uint32_t)0x0000001F)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_DCOC_BB_DCOC_IN_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_DCOC_BB_DCOC_IN_WIDTH    ((uint32_t)0x00000005)

#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_DCOC_BB_DCOC_QP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_DCOC_BB_DCOC_QN_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_DCOC_BB_DCOC_IP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_DCOC_BB_DCOC_IN_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_2_dcoc_pack(uint8_t bb_dcoc_qp, uint8_t bb_dcoc_qn, uint8_t bb_dcoc_ip, uint8_t bb_dcoc_in)
{
	ASSERT_ERR((((uint32_t)bb_dcoc_qp << 24) & ~((uint32_t)0x1F000000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_qn << 16) & ~((uint32_t)0x001F0000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_ip << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_in << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_DCOC_ADDR,  ((uint32_t)bb_dcoc_qp << 24) |((uint32_t)bb_dcoc_qn << 16) |((uint32_t)bb_dcoc_ip << 8) |((uint32_t)bb_dcoc_in << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_2_dcoc_unpack(uint8_t* bb_dcoc_qp, uint8_t* bb_dcoc_qn, uint8_t* bb_dcoc_ip, uint8_t* bb_dcoc_in)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_DCOC_ADDR);

	*bb_dcoc_qp = (localVal & ((uint32_t)0x1F000000)) >>  24;
	*bb_dcoc_qn = (localVal & ((uint32_t)0x001F0000)) >>  16;
	*bb_dcoc_ip = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*bb_dcoc_in = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_2_dcoc_bb_dcoc_qp_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x1F000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_2_dcoc_bb_dcoc_qp_setf(uint8_t bbdcocqp)
{
	ASSERT_ERR((((uint32_t)bbdcocqp << 24) & ~((uint32_t)0x1F000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_DCOC_ADDR) & ~((uint32_t)0x1F000000)) | ((uint32_t)bbdcocqp <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_2_dcoc_bb_dcoc_qn_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001F0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_2_dcoc_bb_dcoc_qn_setf(uint8_t bbdcocqn)
{
	ASSERT_ERR((((uint32_t)bbdcocqn << 16) & ~((uint32_t)0x001F0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_DCOC_ADDR) & ~((uint32_t)0x001F0000)) | ((uint32_t)bbdcocqn <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_2_dcoc_bb_dcoc_ip_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_2_dcoc_bb_dcoc_ip_setf(uint8_t bbdcocip)
{
	ASSERT_ERR((((uint32_t)bbdcocip << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_DCOC_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)bbdcocip <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_2_dcoc_bb_dcoc_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_2_dcoc_bb_dcoc_in_setf(uint8_t bbdcocin)
{
	ASSERT_ERR((((uint32_t)bbdcocin << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_DCOC_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)bbdcocin <<0));
}

/**
 * @brief WIFI_RF_RX_CH_1_LNA_3_DCOC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28:24 BB_DCOC_QP                0x0
 *    20:16 BB_DCOC_QN                0x0
 *    12:08 BB_DCOC_IP                0x0
 *    04:00 BB_DCOC_IN                0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_DCOC_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x000000CC)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_DCOC_OFFSET      0x000000CC
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_DCOC_INDEX       0x00000033
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_DCOC_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_1_lna_3_dcoc_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_DCOC_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_3_dcoc_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_DCOC_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_DCOC_BB_DCOC_QP_MASK    ((uint32_t)0x1F000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_DCOC_BB_DCOC_QP_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_DCOC_BB_DCOC_QP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_DCOC_BB_DCOC_QN_MASK    ((uint32_t)0x001F0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_DCOC_BB_DCOC_QN_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_DCOC_BB_DCOC_QN_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_DCOC_BB_DCOC_IP_MASK    ((uint32_t)0x00001F00)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_DCOC_BB_DCOC_IP_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_DCOC_BB_DCOC_IP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_DCOC_BB_DCOC_IN_MASK    ((uint32_t)0x0000001F)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_DCOC_BB_DCOC_IN_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_DCOC_BB_DCOC_IN_WIDTH    ((uint32_t)0x00000005)

#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_DCOC_BB_DCOC_QP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_DCOC_BB_DCOC_QN_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_DCOC_BB_DCOC_IP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_DCOC_BB_DCOC_IN_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_3_dcoc_pack(uint8_t bb_dcoc_qp, uint8_t bb_dcoc_qn, uint8_t bb_dcoc_ip, uint8_t bb_dcoc_in)
{
	ASSERT_ERR((((uint32_t)bb_dcoc_qp << 24) & ~((uint32_t)0x1F000000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_qn << 16) & ~((uint32_t)0x001F0000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_ip << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_in << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_DCOC_ADDR,  ((uint32_t)bb_dcoc_qp << 24) |((uint32_t)bb_dcoc_qn << 16) |((uint32_t)bb_dcoc_ip << 8) |((uint32_t)bb_dcoc_in << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_3_dcoc_unpack(uint8_t* bb_dcoc_qp, uint8_t* bb_dcoc_qn, uint8_t* bb_dcoc_ip, uint8_t* bb_dcoc_in)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_DCOC_ADDR);

	*bb_dcoc_qp = (localVal & ((uint32_t)0x1F000000)) >>  24;
	*bb_dcoc_qn = (localVal & ((uint32_t)0x001F0000)) >>  16;
	*bb_dcoc_ip = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*bb_dcoc_in = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_3_dcoc_bb_dcoc_qp_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x1F000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_3_dcoc_bb_dcoc_qp_setf(uint8_t bbdcocqp)
{
	ASSERT_ERR((((uint32_t)bbdcocqp << 24) & ~((uint32_t)0x1F000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_DCOC_ADDR) & ~((uint32_t)0x1F000000)) | ((uint32_t)bbdcocqp <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_3_dcoc_bb_dcoc_qn_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001F0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_3_dcoc_bb_dcoc_qn_setf(uint8_t bbdcocqn)
{
	ASSERT_ERR((((uint32_t)bbdcocqn << 16) & ~((uint32_t)0x001F0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_DCOC_ADDR) & ~((uint32_t)0x001F0000)) | ((uint32_t)bbdcocqn <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_3_dcoc_bb_dcoc_ip_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_3_dcoc_bb_dcoc_ip_setf(uint8_t bbdcocip)
{
	ASSERT_ERR((((uint32_t)bbdcocip << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_DCOC_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)bbdcocip <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_3_dcoc_bb_dcoc_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_3_dcoc_bb_dcoc_in_setf(uint8_t bbdcocin)
{
	ASSERT_ERR((((uint32_t)bbdcocin << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_DCOC_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)bbdcocin <<0));
}

/**
 * @brief WIFI_RF_RX_CH_1_LNA_4_DCOC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28:24 BB_DCOC_QP                0x0
 *    20:16 BB_DCOC_QN                0x0
 *    12:08 BB_DCOC_IP                0x0
 *    04:00 BB_DCOC_IN                0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_DCOC_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x000000D0)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_DCOC_OFFSET      0x000000D0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_DCOC_INDEX       0x00000034
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_DCOC_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_1_lna_4_dcoc_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_DCOC_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_4_dcoc_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_DCOC_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_DCOC_BB_DCOC_QP_MASK    ((uint32_t)0x1F000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_DCOC_BB_DCOC_QP_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_DCOC_BB_DCOC_QP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_DCOC_BB_DCOC_QN_MASK    ((uint32_t)0x001F0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_DCOC_BB_DCOC_QN_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_DCOC_BB_DCOC_QN_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_DCOC_BB_DCOC_IP_MASK    ((uint32_t)0x00001F00)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_DCOC_BB_DCOC_IP_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_DCOC_BB_DCOC_IP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_DCOC_BB_DCOC_IN_MASK    ((uint32_t)0x0000001F)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_DCOC_BB_DCOC_IN_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_DCOC_BB_DCOC_IN_WIDTH    ((uint32_t)0x00000005)

#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_DCOC_BB_DCOC_QP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_DCOC_BB_DCOC_QN_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_DCOC_BB_DCOC_IP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_DCOC_BB_DCOC_IN_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_4_dcoc_pack(uint8_t bb_dcoc_qp, uint8_t bb_dcoc_qn, uint8_t bb_dcoc_ip, uint8_t bb_dcoc_in)
{
	ASSERT_ERR((((uint32_t)bb_dcoc_qp << 24) & ~((uint32_t)0x1F000000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_qn << 16) & ~((uint32_t)0x001F0000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_ip << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_in << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_DCOC_ADDR,  ((uint32_t)bb_dcoc_qp << 24) |((uint32_t)bb_dcoc_qn << 16) |((uint32_t)bb_dcoc_ip << 8) |((uint32_t)bb_dcoc_in << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_4_dcoc_unpack(uint8_t* bb_dcoc_qp, uint8_t* bb_dcoc_qn, uint8_t* bb_dcoc_ip, uint8_t* bb_dcoc_in)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_DCOC_ADDR);

	*bb_dcoc_qp = (localVal & ((uint32_t)0x1F000000)) >>  24;
	*bb_dcoc_qn = (localVal & ((uint32_t)0x001F0000)) >>  16;
	*bb_dcoc_ip = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*bb_dcoc_in = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_4_dcoc_bb_dcoc_qp_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x1F000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_4_dcoc_bb_dcoc_qp_setf(uint8_t bbdcocqp)
{
	ASSERT_ERR((((uint32_t)bbdcocqp << 24) & ~((uint32_t)0x1F000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_DCOC_ADDR) & ~((uint32_t)0x1F000000)) | ((uint32_t)bbdcocqp <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_4_dcoc_bb_dcoc_qn_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001F0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_4_dcoc_bb_dcoc_qn_setf(uint8_t bbdcocqn)
{
	ASSERT_ERR((((uint32_t)bbdcocqn << 16) & ~((uint32_t)0x001F0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_DCOC_ADDR) & ~((uint32_t)0x001F0000)) | ((uint32_t)bbdcocqn <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_4_dcoc_bb_dcoc_ip_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_4_dcoc_bb_dcoc_ip_setf(uint8_t bbdcocip)
{
	ASSERT_ERR((((uint32_t)bbdcocip << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_DCOC_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)bbdcocip <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_4_dcoc_bb_dcoc_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_4_dcoc_bb_dcoc_in_setf(uint8_t bbdcocin)
{
	ASSERT_ERR((((uint32_t)bbdcocin << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_DCOC_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)bbdcocin <<0));
}

/**
 * @brief WIFI_RF_RX_CH_1_LNA_5_DCOC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28:24 BB_DCOC_QP                0x0
 *    20:16 BB_DCOC_QN                0x0
 *    12:08 BB_DCOC_IP                0x0
 *    04:00 BB_DCOC_IN                0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_DCOC_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x000000D4)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_DCOC_OFFSET      0x000000D4
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_DCOC_INDEX       0x00000035
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_DCOC_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_1_lna_5_dcoc_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_DCOC_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_5_dcoc_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_DCOC_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_DCOC_BB_DCOC_QP_MASK    ((uint32_t)0x1F000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_DCOC_BB_DCOC_QP_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_DCOC_BB_DCOC_QP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_DCOC_BB_DCOC_QN_MASK    ((uint32_t)0x001F0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_DCOC_BB_DCOC_QN_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_DCOC_BB_DCOC_QN_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_DCOC_BB_DCOC_IP_MASK    ((uint32_t)0x00001F00)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_DCOC_BB_DCOC_IP_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_DCOC_BB_DCOC_IP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_DCOC_BB_DCOC_IN_MASK    ((uint32_t)0x0000001F)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_DCOC_BB_DCOC_IN_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_DCOC_BB_DCOC_IN_WIDTH    ((uint32_t)0x00000005)

#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_DCOC_BB_DCOC_QP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_DCOC_BB_DCOC_QN_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_DCOC_BB_DCOC_IP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_DCOC_BB_DCOC_IN_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_5_dcoc_pack(uint8_t bb_dcoc_qp, uint8_t bb_dcoc_qn, uint8_t bb_dcoc_ip, uint8_t bb_dcoc_in)
{
	ASSERT_ERR((((uint32_t)bb_dcoc_qp << 24) & ~((uint32_t)0x1F000000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_qn << 16) & ~((uint32_t)0x001F0000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_ip << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_in << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_DCOC_ADDR,  ((uint32_t)bb_dcoc_qp << 24) |((uint32_t)bb_dcoc_qn << 16) |((uint32_t)bb_dcoc_ip << 8) |((uint32_t)bb_dcoc_in << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_5_dcoc_unpack(uint8_t* bb_dcoc_qp, uint8_t* bb_dcoc_qn, uint8_t* bb_dcoc_ip, uint8_t* bb_dcoc_in)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_DCOC_ADDR);

	*bb_dcoc_qp = (localVal & ((uint32_t)0x1F000000)) >>  24;
	*bb_dcoc_qn = (localVal & ((uint32_t)0x001F0000)) >>  16;
	*bb_dcoc_ip = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*bb_dcoc_in = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_5_dcoc_bb_dcoc_qp_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x1F000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_5_dcoc_bb_dcoc_qp_setf(uint8_t bbdcocqp)
{
	ASSERT_ERR((((uint32_t)bbdcocqp << 24) & ~((uint32_t)0x1F000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_DCOC_ADDR) & ~((uint32_t)0x1F000000)) | ((uint32_t)bbdcocqp <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_5_dcoc_bb_dcoc_qn_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001F0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_5_dcoc_bb_dcoc_qn_setf(uint8_t bbdcocqn)
{
	ASSERT_ERR((((uint32_t)bbdcocqn << 16) & ~((uint32_t)0x001F0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_DCOC_ADDR) & ~((uint32_t)0x001F0000)) | ((uint32_t)bbdcocqn <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_5_dcoc_bb_dcoc_ip_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_5_dcoc_bb_dcoc_ip_setf(uint8_t bbdcocip)
{
	ASSERT_ERR((((uint32_t)bbdcocip << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_DCOC_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)bbdcocip <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_5_dcoc_bb_dcoc_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_5_dcoc_bb_dcoc_in_setf(uint8_t bbdcocin)
{
	ASSERT_ERR((((uint32_t)bbdcocin << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_DCOC_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)bbdcocin <<0));
}

/**
 * @brief WIFI_RF_RX_CH_1_LNA_6_DCOC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28:24 BB_DCOC_QP                0x0
 *    20:16 BB_DCOC_QN                0x0
 *    12:08 BB_DCOC_IP                0x0
 *    04:00 BB_DCOC_IN                0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_DCOC_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x000000D8)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_DCOC_OFFSET      0x000000D8
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_DCOC_INDEX       0x00000036
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_DCOC_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_1_lna_6_dcoc_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_DCOC_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_6_dcoc_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_DCOC_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_DCOC_BB_DCOC_QP_MASK    ((uint32_t)0x1F000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_DCOC_BB_DCOC_QP_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_DCOC_BB_DCOC_QP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_DCOC_BB_DCOC_QN_MASK    ((uint32_t)0x001F0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_DCOC_BB_DCOC_QN_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_DCOC_BB_DCOC_QN_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_DCOC_BB_DCOC_IP_MASK    ((uint32_t)0x00001F00)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_DCOC_BB_DCOC_IP_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_DCOC_BB_DCOC_IP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_DCOC_BB_DCOC_IN_MASK    ((uint32_t)0x0000001F)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_DCOC_BB_DCOC_IN_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_DCOC_BB_DCOC_IN_WIDTH    ((uint32_t)0x00000005)

#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_DCOC_BB_DCOC_QP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_DCOC_BB_DCOC_QN_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_DCOC_BB_DCOC_IP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_DCOC_BB_DCOC_IN_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_6_dcoc_pack(uint8_t bb_dcoc_qp, uint8_t bb_dcoc_qn, uint8_t bb_dcoc_ip, uint8_t bb_dcoc_in)
{
	ASSERT_ERR((((uint32_t)bb_dcoc_qp << 24) & ~((uint32_t)0x1F000000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_qn << 16) & ~((uint32_t)0x001F0000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_ip << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_in << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_DCOC_ADDR,  ((uint32_t)bb_dcoc_qp << 24) |((uint32_t)bb_dcoc_qn << 16) |((uint32_t)bb_dcoc_ip << 8) |((uint32_t)bb_dcoc_in << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_6_dcoc_unpack(uint8_t* bb_dcoc_qp, uint8_t* bb_dcoc_qn, uint8_t* bb_dcoc_ip, uint8_t* bb_dcoc_in)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_DCOC_ADDR);

	*bb_dcoc_qp = (localVal & ((uint32_t)0x1F000000)) >>  24;
	*bb_dcoc_qn = (localVal & ((uint32_t)0x001F0000)) >>  16;
	*bb_dcoc_ip = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*bb_dcoc_in = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_6_dcoc_bb_dcoc_qp_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x1F000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_6_dcoc_bb_dcoc_qp_setf(uint8_t bbdcocqp)
{
	ASSERT_ERR((((uint32_t)bbdcocqp << 24) & ~((uint32_t)0x1F000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_DCOC_ADDR) & ~((uint32_t)0x1F000000)) | ((uint32_t)bbdcocqp <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_6_dcoc_bb_dcoc_qn_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001F0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_6_dcoc_bb_dcoc_qn_setf(uint8_t bbdcocqn)
{
	ASSERT_ERR((((uint32_t)bbdcocqn << 16) & ~((uint32_t)0x001F0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_DCOC_ADDR) & ~((uint32_t)0x001F0000)) | ((uint32_t)bbdcocqn <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_6_dcoc_bb_dcoc_ip_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_6_dcoc_bb_dcoc_ip_setf(uint8_t bbdcocip)
{
	ASSERT_ERR((((uint32_t)bbdcocip << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_DCOC_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)bbdcocip <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_6_dcoc_bb_dcoc_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_6_dcoc_bb_dcoc_in_setf(uint8_t bbdcocin)
{
	ASSERT_ERR((((uint32_t)bbdcocin << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_DCOC_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)bbdcocin <<0));
}

/**
 * @brief WIFI_RF_RX_CH_1_LNA_7_DCOC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28:24 BB_DCOC_QP                0x0
 *    20:16 BB_DCOC_QN                0x0
 *    12:08 BB_DCOC_IP                0x0
 *    04:00 BB_DCOC_IN                0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_DCOC_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x000000DC)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_DCOC_OFFSET      0x000000DC
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_DCOC_INDEX       0x00000037
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_DCOC_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_1_lna_7_dcoc_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_DCOC_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_7_dcoc_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_DCOC_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_DCOC_BB_DCOC_QP_MASK    ((uint32_t)0x1F000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_DCOC_BB_DCOC_QP_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_DCOC_BB_DCOC_QP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_DCOC_BB_DCOC_QN_MASK    ((uint32_t)0x001F0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_DCOC_BB_DCOC_QN_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_DCOC_BB_DCOC_QN_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_DCOC_BB_DCOC_IP_MASK    ((uint32_t)0x00001F00)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_DCOC_BB_DCOC_IP_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_DCOC_BB_DCOC_IP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_DCOC_BB_DCOC_IN_MASK    ((uint32_t)0x0000001F)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_DCOC_BB_DCOC_IN_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_DCOC_BB_DCOC_IN_WIDTH    ((uint32_t)0x00000005)

#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_DCOC_BB_DCOC_QP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_DCOC_BB_DCOC_QN_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_DCOC_BB_DCOC_IP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_DCOC_BB_DCOC_IN_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_7_dcoc_pack(uint8_t bb_dcoc_qp, uint8_t bb_dcoc_qn, uint8_t bb_dcoc_ip, uint8_t bb_dcoc_in)
{
	ASSERT_ERR((((uint32_t)bb_dcoc_qp << 24) & ~((uint32_t)0x1F000000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_qn << 16) & ~((uint32_t)0x001F0000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_ip << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_in << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_DCOC_ADDR,  ((uint32_t)bb_dcoc_qp << 24) |((uint32_t)bb_dcoc_qn << 16) |((uint32_t)bb_dcoc_ip << 8) |((uint32_t)bb_dcoc_in << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_7_dcoc_unpack(uint8_t* bb_dcoc_qp, uint8_t* bb_dcoc_qn, uint8_t* bb_dcoc_ip, uint8_t* bb_dcoc_in)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_DCOC_ADDR);

	*bb_dcoc_qp = (localVal & ((uint32_t)0x1F000000)) >>  24;
	*bb_dcoc_qn = (localVal & ((uint32_t)0x001F0000)) >>  16;
	*bb_dcoc_ip = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*bb_dcoc_in = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_7_dcoc_bb_dcoc_qp_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x1F000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_7_dcoc_bb_dcoc_qp_setf(uint8_t bbdcocqp)
{
	ASSERT_ERR((((uint32_t)bbdcocqp << 24) & ~((uint32_t)0x1F000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_DCOC_ADDR) & ~((uint32_t)0x1F000000)) | ((uint32_t)bbdcocqp <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_7_dcoc_bb_dcoc_qn_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001F0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_7_dcoc_bb_dcoc_qn_setf(uint8_t bbdcocqn)
{
	ASSERT_ERR((((uint32_t)bbdcocqn << 16) & ~((uint32_t)0x001F0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_DCOC_ADDR) & ~((uint32_t)0x001F0000)) | ((uint32_t)bbdcocqn <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_7_dcoc_bb_dcoc_ip_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_7_dcoc_bb_dcoc_ip_setf(uint8_t bbdcocip)
{
	ASSERT_ERR((((uint32_t)bbdcocip << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_DCOC_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)bbdcocip <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_7_dcoc_bb_dcoc_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_7_dcoc_bb_dcoc_in_setf(uint8_t bbdcocin)
{
	ASSERT_ERR((((uint32_t)bbdcocin << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_DCOC_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)bbdcocin <<0));
}

/**
 * @brief WIFI_RF_RX_CH_1_LNA_8_DCOC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28:24 BB_DCOC_QP                0x0
 *    20:16 BB_DCOC_QN                0x0
 *    12:08 BB_DCOC_IP                0x0
 *    04:00 BB_DCOC_IN                0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_DCOC_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x000000E0)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_DCOC_OFFSET      0x000000E0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_DCOC_INDEX       0x00000038
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_DCOC_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_1_lna_8_dcoc_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_DCOC_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_8_dcoc_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_DCOC_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_DCOC_BB_DCOC_QP_MASK    ((uint32_t)0x1F000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_DCOC_BB_DCOC_QP_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_DCOC_BB_DCOC_QP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_DCOC_BB_DCOC_QN_MASK    ((uint32_t)0x001F0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_DCOC_BB_DCOC_QN_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_DCOC_BB_DCOC_QN_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_DCOC_BB_DCOC_IP_MASK    ((uint32_t)0x00001F00)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_DCOC_BB_DCOC_IP_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_DCOC_BB_DCOC_IP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_DCOC_BB_DCOC_IN_MASK    ((uint32_t)0x0000001F)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_DCOC_BB_DCOC_IN_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_DCOC_BB_DCOC_IN_WIDTH    ((uint32_t)0x00000005)

#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_DCOC_BB_DCOC_QP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_DCOC_BB_DCOC_QN_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_DCOC_BB_DCOC_IP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_DCOC_BB_DCOC_IN_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_8_dcoc_pack(uint8_t bb_dcoc_qp, uint8_t bb_dcoc_qn, uint8_t bb_dcoc_ip, uint8_t bb_dcoc_in)
{
	ASSERT_ERR((((uint32_t)bb_dcoc_qp << 24) & ~((uint32_t)0x1F000000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_qn << 16) & ~((uint32_t)0x001F0000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_ip << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_in << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_DCOC_ADDR,  ((uint32_t)bb_dcoc_qp << 24) |((uint32_t)bb_dcoc_qn << 16) |((uint32_t)bb_dcoc_ip << 8) |((uint32_t)bb_dcoc_in << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_8_dcoc_unpack(uint8_t* bb_dcoc_qp, uint8_t* bb_dcoc_qn, uint8_t* bb_dcoc_ip, uint8_t* bb_dcoc_in)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_DCOC_ADDR);

	*bb_dcoc_qp = (localVal & ((uint32_t)0x1F000000)) >>  24;
	*bb_dcoc_qn = (localVal & ((uint32_t)0x001F0000)) >>  16;
	*bb_dcoc_ip = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*bb_dcoc_in = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_8_dcoc_bb_dcoc_qp_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x1F000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_8_dcoc_bb_dcoc_qp_setf(uint8_t bbdcocqp)
{
	ASSERT_ERR((((uint32_t)bbdcocqp << 24) & ~((uint32_t)0x1F000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_DCOC_ADDR) & ~((uint32_t)0x1F000000)) | ((uint32_t)bbdcocqp <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_8_dcoc_bb_dcoc_qn_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001F0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_8_dcoc_bb_dcoc_qn_setf(uint8_t bbdcocqn)
{
	ASSERT_ERR((((uint32_t)bbdcocqn << 16) & ~((uint32_t)0x001F0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_DCOC_ADDR) & ~((uint32_t)0x001F0000)) | ((uint32_t)bbdcocqn <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_8_dcoc_bb_dcoc_ip_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_8_dcoc_bb_dcoc_ip_setf(uint8_t bbdcocip)
{
	ASSERT_ERR((((uint32_t)bbdcocip << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_DCOC_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)bbdcocip <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_8_dcoc_bb_dcoc_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_8_dcoc_bb_dcoc_in_setf(uint8_t bbdcocin)
{
	ASSERT_ERR((((uint32_t)bbdcocin << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_DCOC_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)bbdcocin <<0));
}

/**
 * @brief WIFI_RF_RX_CH_1_LNA_9_DCOC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28:24 BB_DCOC_QP                0x0
 *    20:16 BB_DCOC_QN                0x0
 *    12:08 BB_DCOC_IP                0x0
 *    04:00 BB_DCOC_IN                0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_DCOC_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x000000E4)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_DCOC_OFFSET      0x000000E4
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_DCOC_INDEX       0x00000039
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_DCOC_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_1_lna_9_dcoc_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_DCOC_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_9_dcoc_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_DCOC_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_DCOC_BB_DCOC_QP_MASK    ((uint32_t)0x1F000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_DCOC_BB_DCOC_QP_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_DCOC_BB_DCOC_QP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_DCOC_BB_DCOC_QN_MASK    ((uint32_t)0x001F0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_DCOC_BB_DCOC_QN_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_DCOC_BB_DCOC_QN_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_DCOC_BB_DCOC_IP_MASK    ((uint32_t)0x00001F00)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_DCOC_BB_DCOC_IP_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_DCOC_BB_DCOC_IP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_DCOC_BB_DCOC_IN_MASK    ((uint32_t)0x0000001F)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_DCOC_BB_DCOC_IN_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_DCOC_BB_DCOC_IN_WIDTH    ((uint32_t)0x00000005)

#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_DCOC_BB_DCOC_QP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_DCOC_BB_DCOC_QN_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_DCOC_BB_DCOC_IP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_DCOC_BB_DCOC_IN_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_9_dcoc_pack(uint8_t bb_dcoc_qp, uint8_t bb_dcoc_qn, uint8_t bb_dcoc_ip, uint8_t bb_dcoc_in)
{
	ASSERT_ERR((((uint32_t)bb_dcoc_qp << 24) & ~((uint32_t)0x1F000000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_qn << 16) & ~((uint32_t)0x001F0000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_ip << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_in << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_DCOC_ADDR,  ((uint32_t)bb_dcoc_qp << 24) |((uint32_t)bb_dcoc_qn << 16) |((uint32_t)bb_dcoc_ip << 8) |((uint32_t)bb_dcoc_in << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_9_dcoc_unpack(uint8_t* bb_dcoc_qp, uint8_t* bb_dcoc_qn, uint8_t* bb_dcoc_ip, uint8_t* bb_dcoc_in)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_DCOC_ADDR);

	*bb_dcoc_qp = (localVal & ((uint32_t)0x1F000000)) >>  24;
	*bb_dcoc_qn = (localVal & ((uint32_t)0x001F0000)) >>  16;
	*bb_dcoc_ip = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*bb_dcoc_in = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_9_dcoc_bb_dcoc_qp_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x1F000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_9_dcoc_bb_dcoc_qp_setf(uint8_t bbdcocqp)
{
	ASSERT_ERR((((uint32_t)bbdcocqp << 24) & ~((uint32_t)0x1F000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_DCOC_ADDR) & ~((uint32_t)0x1F000000)) | ((uint32_t)bbdcocqp <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_9_dcoc_bb_dcoc_qn_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001F0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_9_dcoc_bb_dcoc_qn_setf(uint8_t bbdcocqn)
{
	ASSERT_ERR((((uint32_t)bbdcocqn << 16) & ~((uint32_t)0x001F0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_DCOC_ADDR) & ~((uint32_t)0x001F0000)) | ((uint32_t)bbdcocqn <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_9_dcoc_bb_dcoc_ip_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_9_dcoc_bb_dcoc_ip_setf(uint8_t bbdcocip)
{
	ASSERT_ERR((((uint32_t)bbdcocip << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_DCOC_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)bbdcocip <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_9_dcoc_bb_dcoc_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_9_dcoc_bb_dcoc_in_setf(uint8_t bbdcocin)
{
	ASSERT_ERR((((uint32_t)bbdcocin << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_DCOC_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)bbdcocin <<0));
}

/**
 * @brief WIFI_RF_RX_CH_1_LNA_10_DCOC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28:24 BB_DCOC_QP                0x0
 *    20:16 BB_DCOC_QN                0x0
 *    12:08 BB_DCOC_IP                0x0
 *    04:00 BB_DCOC_IN                0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_DCOC_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x000000E8)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_DCOC_OFFSET      0x000000E8
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_DCOC_INDEX       0x0000003A
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_DCOC_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_1_lna_10_dcoc_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_DCOC_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_10_dcoc_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_DCOC_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_DCOC_BB_DCOC_QP_MASK    ((uint32_t)0x1F000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_DCOC_BB_DCOC_QP_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_DCOC_BB_DCOC_QP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_DCOC_BB_DCOC_QN_MASK    ((uint32_t)0x001F0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_DCOC_BB_DCOC_QN_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_DCOC_BB_DCOC_QN_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_DCOC_BB_DCOC_IP_MASK    ((uint32_t)0x00001F00)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_DCOC_BB_DCOC_IP_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_DCOC_BB_DCOC_IP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_DCOC_BB_DCOC_IN_MASK    ((uint32_t)0x0000001F)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_DCOC_BB_DCOC_IN_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_DCOC_BB_DCOC_IN_WIDTH    ((uint32_t)0x00000005)

#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_DCOC_BB_DCOC_QP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_DCOC_BB_DCOC_QN_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_DCOC_BB_DCOC_IP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_DCOC_BB_DCOC_IN_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_10_dcoc_pack(uint8_t bb_dcoc_qp, uint8_t bb_dcoc_qn, uint8_t bb_dcoc_ip, uint8_t bb_dcoc_in)
{
	ASSERT_ERR((((uint32_t)bb_dcoc_qp << 24) & ~((uint32_t)0x1F000000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_qn << 16) & ~((uint32_t)0x001F0000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_ip << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_in << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_DCOC_ADDR,  ((uint32_t)bb_dcoc_qp << 24) |((uint32_t)bb_dcoc_qn << 16) |((uint32_t)bb_dcoc_ip << 8) |((uint32_t)bb_dcoc_in << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_10_dcoc_unpack(uint8_t* bb_dcoc_qp, uint8_t* bb_dcoc_qn, uint8_t* bb_dcoc_ip, uint8_t* bb_dcoc_in)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_DCOC_ADDR);

	*bb_dcoc_qp = (localVal & ((uint32_t)0x1F000000)) >>  24;
	*bb_dcoc_qn = (localVal & ((uint32_t)0x001F0000)) >>  16;
	*bb_dcoc_ip = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*bb_dcoc_in = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_10_dcoc_bb_dcoc_qp_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x1F000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_10_dcoc_bb_dcoc_qp_setf(uint8_t bbdcocqp)
{
	ASSERT_ERR((((uint32_t)bbdcocqp << 24) & ~((uint32_t)0x1F000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_DCOC_ADDR) & ~((uint32_t)0x1F000000)) | ((uint32_t)bbdcocqp <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_10_dcoc_bb_dcoc_qn_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001F0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_10_dcoc_bb_dcoc_qn_setf(uint8_t bbdcocqn)
{
	ASSERT_ERR((((uint32_t)bbdcocqn << 16) & ~((uint32_t)0x001F0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_DCOC_ADDR) & ~((uint32_t)0x001F0000)) | ((uint32_t)bbdcocqn <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_10_dcoc_bb_dcoc_ip_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_10_dcoc_bb_dcoc_ip_setf(uint8_t bbdcocip)
{
	ASSERT_ERR((((uint32_t)bbdcocip << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_DCOC_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)bbdcocip <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_10_dcoc_bb_dcoc_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_10_dcoc_bb_dcoc_in_setf(uint8_t bbdcocin)
{
	ASSERT_ERR((((uint32_t)bbdcocin << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_DCOC_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)bbdcocin <<0));
}

/**
 * @brief WIFI_RF_RX_CH_1_LNA_11_DCOC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28:24 BB_DCOC_QP                0x0
 *    20:16 BB_DCOC_QN                0x0
 *    12:08 BB_DCOC_IP                0x0
 *    04:00 BB_DCOC_IN                0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_DCOC_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x000000EC)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_DCOC_OFFSET      0x000000EC
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_DCOC_INDEX       0x0000003B
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_DCOC_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_1_lna_11_dcoc_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_DCOC_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_11_dcoc_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_DCOC_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_DCOC_BB_DCOC_QP_MASK    ((uint32_t)0x1F000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_DCOC_BB_DCOC_QP_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_DCOC_BB_DCOC_QP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_DCOC_BB_DCOC_QN_MASK    ((uint32_t)0x001F0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_DCOC_BB_DCOC_QN_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_DCOC_BB_DCOC_QN_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_DCOC_BB_DCOC_IP_MASK    ((uint32_t)0x00001F00)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_DCOC_BB_DCOC_IP_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_DCOC_BB_DCOC_IP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_DCOC_BB_DCOC_IN_MASK    ((uint32_t)0x0000001F)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_DCOC_BB_DCOC_IN_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_DCOC_BB_DCOC_IN_WIDTH    ((uint32_t)0x00000005)

#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_DCOC_BB_DCOC_QP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_DCOC_BB_DCOC_QN_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_DCOC_BB_DCOC_IP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_DCOC_BB_DCOC_IN_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_11_dcoc_pack(uint8_t bb_dcoc_qp, uint8_t bb_dcoc_qn, uint8_t bb_dcoc_ip, uint8_t bb_dcoc_in)
{
	ASSERT_ERR((((uint32_t)bb_dcoc_qp << 24) & ~((uint32_t)0x1F000000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_qn << 16) & ~((uint32_t)0x001F0000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_ip << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_in << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_DCOC_ADDR,  ((uint32_t)bb_dcoc_qp << 24) |((uint32_t)bb_dcoc_qn << 16) |((uint32_t)bb_dcoc_ip << 8) |((uint32_t)bb_dcoc_in << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_11_dcoc_unpack(uint8_t* bb_dcoc_qp, uint8_t* bb_dcoc_qn, uint8_t* bb_dcoc_ip, uint8_t* bb_dcoc_in)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_DCOC_ADDR);

	*bb_dcoc_qp = (localVal & ((uint32_t)0x1F000000)) >>  24;
	*bb_dcoc_qn = (localVal & ((uint32_t)0x001F0000)) >>  16;
	*bb_dcoc_ip = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*bb_dcoc_in = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_11_dcoc_bb_dcoc_qp_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x1F000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_11_dcoc_bb_dcoc_qp_setf(uint8_t bbdcocqp)
{
	ASSERT_ERR((((uint32_t)bbdcocqp << 24) & ~((uint32_t)0x1F000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_DCOC_ADDR) & ~((uint32_t)0x1F000000)) | ((uint32_t)bbdcocqp <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_11_dcoc_bb_dcoc_qn_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001F0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_11_dcoc_bb_dcoc_qn_setf(uint8_t bbdcocqn)
{
	ASSERT_ERR((((uint32_t)bbdcocqn << 16) & ~((uint32_t)0x001F0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_DCOC_ADDR) & ~((uint32_t)0x001F0000)) | ((uint32_t)bbdcocqn <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_11_dcoc_bb_dcoc_ip_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_11_dcoc_bb_dcoc_ip_setf(uint8_t bbdcocip)
{
	ASSERT_ERR((((uint32_t)bbdcocip << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_DCOC_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)bbdcocip <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_11_dcoc_bb_dcoc_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_11_dcoc_bb_dcoc_in_setf(uint8_t bbdcocin)
{
	ASSERT_ERR((((uint32_t)bbdcocin << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_DCOC_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)bbdcocin <<0));
}

/**
 * @brief WIFI_RF_RX_CH_1_LNA_12_DCOC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28:24 BB_DCOC_QP                0x0
 *    20:16 BB_DCOC_QN                0x0
 *    12:08 BB_DCOC_IP                0x0
 *    04:00 BB_DCOC_IN                0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_DCOC_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x000000F0)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_DCOC_OFFSET      0x000000F0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_DCOC_INDEX       0x0000003C
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_DCOC_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_1_lna_12_dcoc_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_DCOC_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_12_dcoc_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_DCOC_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_DCOC_BB_DCOC_QP_MASK    ((uint32_t)0x1F000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_DCOC_BB_DCOC_QP_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_DCOC_BB_DCOC_QP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_DCOC_BB_DCOC_QN_MASK    ((uint32_t)0x001F0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_DCOC_BB_DCOC_QN_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_DCOC_BB_DCOC_QN_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_DCOC_BB_DCOC_IP_MASK    ((uint32_t)0x00001F00)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_DCOC_BB_DCOC_IP_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_DCOC_BB_DCOC_IP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_DCOC_BB_DCOC_IN_MASK    ((uint32_t)0x0000001F)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_DCOC_BB_DCOC_IN_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_DCOC_BB_DCOC_IN_WIDTH    ((uint32_t)0x00000005)

#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_DCOC_BB_DCOC_QP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_DCOC_BB_DCOC_QN_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_DCOC_BB_DCOC_IP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_DCOC_BB_DCOC_IN_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_12_dcoc_pack(uint8_t bb_dcoc_qp, uint8_t bb_dcoc_qn, uint8_t bb_dcoc_ip, uint8_t bb_dcoc_in)
{
	ASSERT_ERR((((uint32_t)bb_dcoc_qp << 24) & ~((uint32_t)0x1F000000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_qn << 16) & ~((uint32_t)0x001F0000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_ip << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_in << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_DCOC_ADDR,  ((uint32_t)bb_dcoc_qp << 24) |((uint32_t)bb_dcoc_qn << 16) |((uint32_t)bb_dcoc_ip << 8) |((uint32_t)bb_dcoc_in << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_12_dcoc_unpack(uint8_t* bb_dcoc_qp, uint8_t* bb_dcoc_qn, uint8_t* bb_dcoc_ip, uint8_t* bb_dcoc_in)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_DCOC_ADDR);

	*bb_dcoc_qp = (localVal & ((uint32_t)0x1F000000)) >>  24;
	*bb_dcoc_qn = (localVal & ((uint32_t)0x001F0000)) >>  16;
	*bb_dcoc_ip = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*bb_dcoc_in = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_12_dcoc_bb_dcoc_qp_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x1F000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_12_dcoc_bb_dcoc_qp_setf(uint8_t bbdcocqp)
{
	ASSERT_ERR((((uint32_t)bbdcocqp << 24) & ~((uint32_t)0x1F000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_DCOC_ADDR) & ~((uint32_t)0x1F000000)) | ((uint32_t)bbdcocqp <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_12_dcoc_bb_dcoc_qn_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001F0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_12_dcoc_bb_dcoc_qn_setf(uint8_t bbdcocqn)
{
	ASSERT_ERR((((uint32_t)bbdcocqn << 16) & ~((uint32_t)0x001F0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_DCOC_ADDR) & ~((uint32_t)0x001F0000)) | ((uint32_t)bbdcocqn <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_12_dcoc_bb_dcoc_ip_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_12_dcoc_bb_dcoc_ip_setf(uint8_t bbdcocip)
{
	ASSERT_ERR((((uint32_t)bbdcocip << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_DCOC_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)bbdcocip <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_12_dcoc_bb_dcoc_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_12_dcoc_bb_dcoc_in_setf(uint8_t bbdcocin)
{
	ASSERT_ERR((((uint32_t)bbdcocin << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_DCOC_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)bbdcocin <<0));
}

/**
 * @brief WIFI_RF_RX_CH_1_LNA_13_DCOC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28:24 BB_DCOC_QP                0x0
 *    20:16 BB_DCOC_QN                0x0
 *    12:08 BB_DCOC_IP                0x0
 *    04:00 BB_DCOC_IN                0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_DCOC_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x000000F4)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_DCOC_OFFSET      0x000000F4
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_DCOC_INDEX       0x0000003D
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_DCOC_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_1_lna_13_dcoc_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_DCOC_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_13_dcoc_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_DCOC_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_DCOC_BB_DCOC_QP_MASK    ((uint32_t)0x1F000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_DCOC_BB_DCOC_QP_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_DCOC_BB_DCOC_QP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_DCOC_BB_DCOC_QN_MASK    ((uint32_t)0x001F0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_DCOC_BB_DCOC_QN_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_DCOC_BB_DCOC_QN_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_DCOC_BB_DCOC_IP_MASK    ((uint32_t)0x00001F00)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_DCOC_BB_DCOC_IP_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_DCOC_BB_DCOC_IP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_DCOC_BB_DCOC_IN_MASK    ((uint32_t)0x0000001F)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_DCOC_BB_DCOC_IN_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_DCOC_BB_DCOC_IN_WIDTH    ((uint32_t)0x00000005)

#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_DCOC_BB_DCOC_QP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_DCOC_BB_DCOC_QN_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_DCOC_BB_DCOC_IP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_DCOC_BB_DCOC_IN_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_13_dcoc_pack(uint8_t bb_dcoc_qp, uint8_t bb_dcoc_qn, uint8_t bb_dcoc_ip, uint8_t bb_dcoc_in)
{
	ASSERT_ERR((((uint32_t)bb_dcoc_qp << 24) & ~((uint32_t)0x1F000000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_qn << 16) & ~((uint32_t)0x001F0000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_ip << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_in << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_DCOC_ADDR,  ((uint32_t)bb_dcoc_qp << 24) |((uint32_t)bb_dcoc_qn << 16) |((uint32_t)bb_dcoc_ip << 8) |((uint32_t)bb_dcoc_in << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_13_dcoc_unpack(uint8_t* bb_dcoc_qp, uint8_t* bb_dcoc_qn, uint8_t* bb_dcoc_ip, uint8_t* bb_dcoc_in)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_DCOC_ADDR);

	*bb_dcoc_qp = (localVal & ((uint32_t)0x1F000000)) >>  24;
	*bb_dcoc_qn = (localVal & ((uint32_t)0x001F0000)) >>  16;
	*bb_dcoc_ip = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*bb_dcoc_in = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_13_dcoc_bb_dcoc_qp_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x1F000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_13_dcoc_bb_dcoc_qp_setf(uint8_t bbdcocqp)
{
	ASSERT_ERR((((uint32_t)bbdcocqp << 24) & ~((uint32_t)0x1F000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_DCOC_ADDR) & ~((uint32_t)0x1F000000)) | ((uint32_t)bbdcocqp <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_13_dcoc_bb_dcoc_qn_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001F0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_13_dcoc_bb_dcoc_qn_setf(uint8_t bbdcocqn)
{
	ASSERT_ERR((((uint32_t)bbdcocqn << 16) & ~((uint32_t)0x001F0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_DCOC_ADDR) & ~((uint32_t)0x001F0000)) | ((uint32_t)bbdcocqn <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_13_dcoc_bb_dcoc_ip_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_13_dcoc_bb_dcoc_ip_setf(uint8_t bbdcocip)
{
	ASSERT_ERR((((uint32_t)bbdcocip << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_DCOC_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)bbdcocip <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_13_dcoc_bb_dcoc_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_13_dcoc_bb_dcoc_in_setf(uint8_t bbdcocin)
{
	ASSERT_ERR((((uint32_t)bbdcocin << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_DCOC_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)bbdcocin <<0));
}

/**
 * @brief WIFI_RF_RX_CH_1_LNA_14_DCOC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28:24 BB_DCOC_QP                0x0
 *    20:16 BB_DCOC_QN                0x0
 *    12:08 BB_DCOC_IP                0x0
 *    04:00 BB_DCOC_IN                0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_DCOC_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x000000F8)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_DCOC_OFFSET      0x000000F8
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_DCOC_INDEX       0x0000003E
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_DCOC_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_1_lna_14_dcoc_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_DCOC_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_14_dcoc_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_DCOC_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_DCOC_BB_DCOC_QP_MASK    ((uint32_t)0x1F000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_DCOC_BB_DCOC_QP_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_DCOC_BB_DCOC_QP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_DCOC_BB_DCOC_QN_MASK    ((uint32_t)0x001F0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_DCOC_BB_DCOC_QN_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_DCOC_BB_DCOC_QN_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_DCOC_BB_DCOC_IP_MASK    ((uint32_t)0x00001F00)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_DCOC_BB_DCOC_IP_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_DCOC_BB_DCOC_IP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_DCOC_BB_DCOC_IN_MASK    ((uint32_t)0x0000001F)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_DCOC_BB_DCOC_IN_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_DCOC_BB_DCOC_IN_WIDTH    ((uint32_t)0x00000005)

#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_DCOC_BB_DCOC_QP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_DCOC_BB_DCOC_QN_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_DCOC_BB_DCOC_IP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_DCOC_BB_DCOC_IN_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_14_dcoc_pack(uint8_t bb_dcoc_qp, uint8_t bb_dcoc_qn, uint8_t bb_dcoc_ip, uint8_t bb_dcoc_in)
{
	ASSERT_ERR((((uint32_t)bb_dcoc_qp << 24) & ~((uint32_t)0x1F000000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_qn << 16) & ~((uint32_t)0x001F0000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_ip << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_in << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_DCOC_ADDR,  ((uint32_t)bb_dcoc_qp << 24) |((uint32_t)bb_dcoc_qn << 16) |((uint32_t)bb_dcoc_ip << 8) |((uint32_t)bb_dcoc_in << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_14_dcoc_unpack(uint8_t* bb_dcoc_qp, uint8_t* bb_dcoc_qn, uint8_t* bb_dcoc_ip, uint8_t* bb_dcoc_in)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_DCOC_ADDR);

	*bb_dcoc_qp = (localVal & ((uint32_t)0x1F000000)) >>  24;
	*bb_dcoc_qn = (localVal & ((uint32_t)0x001F0000)) >>  16;
	*bb_dcoc_ip = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*bb_dcoc_in = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_14_dcoc_bb_dcoc_qp_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x1F000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_14_dcoc_bb_dcoc_qp_setf(uint8_t bbdcocqp)
{
	ASSERT_ERR((((uint32_t)bbdcocqp << 24) & ~((uint32_t)0x1F000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_DCOC_ADDR) & ~((uint32_t)0x1F000000)) | ((uint32_t)bbdcocqp <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_14_dcoc_bb_dcoc_qn_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001F0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_14_dcoc_bb_dcoc_qn_setf(uint8_t bbdcocqn)
{
	ASSERT_ERR((((uint32_t)bbdcocqn << 16) & ~((uint32_t)0x001F0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_DCOC_ADDR) & ~((uint32_t)0x001F0000)) | ((uint32_t)bbdcocqn <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_14_dcoc_bb_dcoc_ip_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_14_dcoc_bb_dcoc_ip_setf(uint8_t bbdcocip)
{
	ASSERT_ERR((((uint32_t)bbdcocip << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_DCOC_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)bbdcocip <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_14_dcoc_bb_dcoc_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_14_dcoc_bb_dcoc_in_setf(uint8_t bbdcocin)
{
	ASSERT_ERR((((uint32_t)bbdcocin << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_DCOC_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)bbdcocin <<0));
}

/**
 * @brief WIFI_RF_RX_CH_1_LNA_15_DCOC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28:24 BB_DCOC_QP                0x0
 *    20:16 BB_DCOC_QN                0x0
 *    12:08 BB_DCOC_IP                0x0
 *    04:00 BB_DCOC_IN                0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_DCOC_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x000000FC)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_DCOC_OFFSET      0x000000FC
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_DCOC_INDEX       0x0000003F
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_DCOC_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_1_lna_15_dcoc_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_DCOC_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_15_dcoc_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_DCOC_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_DCOC_BB_DCOC_QP_MASK    ((uint32_t)0x1F000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_DCOC_BB_DCOC_QP_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_DCOC_BB_DCOC_QP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_DCOC_BB_DCOC_QN_MASK    ((uint32_t)0x001F0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_DCOC_BB_DCOC_QN_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_DCOC_BB_DCOC_QN_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_DCOC_BB_DCOC_IP_MASK    ((uint32_t)0x00001F00)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_DCOC_BB_DCOC_IP_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_DCOC_BB_DCOC_IP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_DCOC_BB_DCOC_IN_MASK    ((uint32_t)0x0000001F)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_DCOC_BB_DCOC_IN_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_DCOC_BB_DCOC_IN_WIDTH    ((uint32_t)0x00000005)

#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_DCOC_BB_DCOC_QP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_DCOC_BB_DCOC_QN_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_DCOC_BB_DCOC_IP_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_DCOC_BB_DCOC_IN_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_15_dcoc_pack(uint8_t bb_dcoc_qp, uint8_t bb_dcoc_qn, uint8_t bb_dcoc_ip, uint8_t bb_dcoc_in)
{
	ASSERT_ERR((((uint32_t)bb_dcoc_qp << 24) & ~((uint32_t)0x1F000000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_qn << 16) & ~((uint32_t)0x001F0000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_ip << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_in << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_DCOC_ADDR,  ((uint32_t)bb_dcoc_qp << 24) |((uint32_t)bb_dcoc_qn << 16) |((uint32_t)bb_dcoc_ip << 8) |((uint32_t)bb_dcoc_in << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_15_dcoc_unpack(uint8_t* bb_dcoc_qp, uint8_t* bb_dcoc_qn, uint8_t* bb_dcoc_ip, uint8_t* bb_dcoc_in)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_DCOC_ADDR);

	*bb_dcoc_qp = (localVal & ((uint32_t)0x1F000000)) >>  24;
	*bb_dcoc_qn = (localVal & ((uint32_t)0x001F0000)) >>  16;
	*bb_dcoc_ip = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*bb_dcoc_in = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_15_dcoc_bb_dcoc_qp_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x1F000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_15_dcoc_bb_dcoc_qp_setf(uint8_t bbdcocqp)
{
	ASSERT_ERR((((uint32_t)bbdcocqp << 24) & ~((uint32_t)0x1F000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_DCOC_ADDR) & ~((uint32_t)0x1F000000)) | ((uint32_t)bbdcocqp <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_15_dcoc_bb_dcoc_qn_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001F0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_15_dcoc_bb_dcoc_qn_setf(uint8_t bbdcocqn)
{
	ASSERT_ERR((((uint32_t)bbdcocqn << 16) & ~((uint32_t)0x001F0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_DCOC_ADDR) & ~((uint32_t)0x001F0000)) | ((uint32_t)bbdcocqn <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_15_dcoc_bb_dcoc_ip_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_15_dcoc_bb_dcoc_ip_setf(uint8_t bbdcocip)
{
	ASSERT_ERR((((uint32_t)bbdcocip << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_DCOC_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)bbdcocip <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_15_dcoc_bb_dcoc_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_15_dcoc_bb_dcoc_in_setf(uint8_t bbdcocin)
{
	ASSERT_ERR((((uint32_t)bbdcocin << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_DCOC_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)bbdcocin <<0));
}

/**
 * @brief BT_ADC_SW_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    04    ADC_CALN                  0              
 *    03    ADC_RESET_OVR_VAL         0              
 *    02    ADC_RESET_OVR_EN          1              
 *    01    ADC_EN_OVR_VAL            0              
 *    00    ADC_EN_OVR_EN             1              
 * </pre>
 */
#define RFIC_WRAP_BT_ADC_SW_CTRL_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000100)
#define RFIC_WRAP_BT_ADC_SW_CTRL_OFFSET      0x00000100
#define RFIC_WRAP_BT_ADC_SW_CTRL_INDEX       0x00000040
#define RFIC_WRAP_BT_ADC_SW_CTRL_RESET       0x00000005

__INLINE uint32_t  rfic_wrap_bt_adc_sw_ctrl_get(void)
{
	return REG_PL_RD(RFIC_WRAP_BT_ADC_SW_CTRL_ADDR);
}

__INLINE void rfic_wrap_bt_adc_sw_ctrl_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_BT_ADC_SW_CTRL_ADDR, value);
}

// field definitions
#define RFIC_WRAP_BT_ADC_SW_CTRL_ADC_CALN_BIT    ((uint32_t)0x00000010)
#define RFIC_WRAP_BT_ADC_SW_CTRL_ADC_CALN_POS    4
#define RFIC_WRAP_BT_ADC_SW_CTRL_ADC_RESET_OVR_VAL_BIT    ((uint32_t)0x00000008)
#define RFIC_WRAP_BT_ADC_SW_CTRL_ADC_RESET_OVR_VAL_POS    3
#define RFIC_WRAP_BT_ADC_SW_CTRL_ADC_RESET_OVR_EN_BIT    ((uint32_t)0x00000004)
#define RFIC_WRAP_BT_ADC_SW_CTRL_ADC_RESET_OVR_EN_POS    2
#define RFIC_WRAP_BT_ADC_SW_CTRL_ADC_EN_OVR_VAL_BIT    ((uint32_t)0x00000002)
#define RFIC_WRAP_BT_ADC_SW_CTRL_ADC_EN_OVR_VAL_POS    1
#define RFIC_WRAP_BT_ADC_SW_CTRL_ADC_EN_OVR_EN_BIT    ((uint32_t)0x00000001)
#define RFIC_WRAP_BT_ADC_SW_CTRL_ADC_EN_OVR_EN_POS    0

#define RFIC_WRAP_BT_ADC_SW_CTRL_ADC_CALN_RST    0x0
#define RFIC_WRAP_BT_ADC_SW_CTRL_ADC_RESET_OVR_VAL_RST    0x0
#define RFIC_WRAP_BT_ADC_SW_CTRL_ADC_RESET_OVR_EN_RST    0x1
#define RFIC_WRAP_BT_ADC_SW_CTRL_ADC_EN_OVR_VAL_RST    0x0
#define RFIC_WRAP_BT_ADC_SW_CTRL_ADC_EN_OVR_EN_RST    0x1

__INLINE void rfic_wrap_bt_adc_sw_ctrl_pack(uint8_t adc_caln, uint8_t adc_reset_ovr_val, uint8_t adc_reset_ovr_en, uint8_t adc_en_ovr_val, uint8_t adc_en_ovr_en)
{
	ASSERT_ERR((((uint32_t)adc_caln << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)adc_reset_ovr_val << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)adc_reset_ovr_en << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)adc_en_ovr_val << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)adc_en_ovr_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_ADC_SW_CTRL_ADDR,  ((uint32_t)adc_caln << 4) |((uint32_t)adc_reset_ovr_val << 3) |((uint32_t)adc_reset_ovr_en << 2) |((uint32_t)adc_en_ovr_val << 1) |((uint32_t)adc_en_ovr_en << 0));
}

__INLINE void rfic_wrap_bt_adc_sw_ctrl_unpack(uint8_t* adc_caln, uint8_t* adc_reset_ovr_val, uint8_t* adc_reset_ovr_en, uint8_t* adc_en_ovr_val, uint8_t* adc_en_ovr_en)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_ADC_SW_CTRL_ADDR);

	*adc_caln = (localVal & ((uint32_t)0x00000010)) >>  4;
	*adc_reset_ovr_val = (localVal & ((uint32_t)0x00000008)) >>  3;
	*adc_reset_ovr_en = (localVal & ((uint32_t)0x00000004)) >>  2;
	*adc_en_ovr_val = (localVal & ((uint32_t)0x00000002)) >>  1;
	*adc_en_ovr_en = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t rfic_wrap_bt_adc_sw_ctrl_adc_caln_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_ADC_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void rfic_wrap_bt_adc_sw_ctrl_adc_caln_setf(uint8_t adccaln)
{
	ASSERT_ERR((((uint32_t)adccaln << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_ADC_SW_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_BT_ADC_SW_CTRL_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)adccaln <<4));
}
__INLINE uint8_t rfic_wrap_bt_adc_sw_ctrl_adc_reset_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_ADC_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void rfic_wrap_bt_adc_sw_ctrl_adc_reset_ovr_val_setf(uint8_t adcresetovrval)
{
	ASSERT_ERR((((uint32_t)adcresetovrval << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_ADC_SW_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_BT_ADC_SW_CTRL_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)adcresetovrval <<3));
}
__INLINE uint8_t rfic_wrap_bt_adc_sw_ctrl_adc_reset_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_ADC_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void rfic_wrap_bt_adc_sw_ctrl_adc_reset_ovr_en_setf(uint8_t adcresetovren)
{
	ASSERT_ERR((((uint32_t)adcresetovren << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_ADC_SW_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_BT_ADC_SW_CTRL_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)adcresetovren <<2));
}
__INLINE uint8_t rfic_wrap_bt_adc_sw_ctrl_adc_en_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_ADC_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void rfic_wrap_bt_adc_sw_ctrl_adc_en_ovr_val_setf(uint8_t adcenovrval)
{
	ASSERT_ERR((((uint32_t)adcenovrval << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_ADC_SW_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_BT_ADC_SW_CTRL_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)adcenovrval <<1));
}
__INLINE uint8_t rfic_wrap_bt_adc_sw_ctrl_adc_en_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_ADC_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void rfic_wrap_bt_adc_sw_ctrl_adc_en_ovr_en_setf(uint8_t adcenovren)
{
	ASSERT_ERR((((uint32_t)adcenovren << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_ADC_SW_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_BT_ADC_SW_CTRL_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)adcenovren <<0));
}

/**
 * @brief BT_DAC_SW_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    20:16 DAC_EN_FALL_DLY_VAL       0x0
 *    12:08 DAC_EN_RISE_DLY_VAL       0x0
 *    02    DAC_EN_DLY_MODE           0              
 *    01    DAC_EN_OVR_VAL            0              
 *    00    DAC_EN_OVR_EN             1              
 * </pre>
 */
#define RFIC_WRAP_BT_DAC_SW_CTRL_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000104)
#define RFIC_WRAP_BT_DAC_SW_CTRL_OFFSET      0x00000104
#define RFIC_WRAP_BT_DAC_SW_CTRL_INDEX       0x00000041
#define RFIC_WRAP_BT_DAC_SW_CTRL_RESET       0x00000001

__INLINE uint32_t  rfic_wrap_bt_dac_sw_ctrl_get(void)
{
	return REG_PL_RD(RFIC_WRAP_BT_DAC_SW_CTRL_ADDR);
}

__INLINE void rfic_wrap_bt_dac_sw_ctrl_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_BT_DAC_SW_CTRL_ADDR, value);
}

// field definitions
#define RFIC_WRAP_BT_DAC_SW_CTRL_DAC_EN_FALL_DLY_VAL_MASK    ((uint32_t)0x001F0000)
#define RFIC_WRAP_BT_DAC_SW_CTRL_DAC_EN_FALL_DLY_VAL_LSB    16
#define RFIC_WRAP_BT_DAC_SW_CTRL_DAC_EN_FALL_DLY_VAL_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_BT_DAC_SW_CTRL_DAC_EN_RISE_DLY_VAL_MASK    ((uint32_t)0x00001F00)
#define RFIC_WRAP_BT_DAC_SW_CTRL_DAC_EN_RISE_DLY_VAL_LSB    8
#define RFIC_WRAP_BT_DAC_SW_CTRL_DAC_EN_RISE_DLY_VAL_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_BT_DAC_SW_CTRL_DAC_EN_DLY_MODE_BIT    ((uint32_t)0x00000004)
#define RFIC_WRAP_BT_DAC_SW_CTRL_DAC_EN_DLY_MODE_POS    2
#define RFIC_WRAP_BT_DAC_SW_CTRL_DAC_EN_OVR_VAL_BIT    ((uint32_t)0x00000002)
#define RFIC_WRAP_BT_DAC_SW_CTRL_DAC_EN_OVR_VAL_POS    1
#define RFIC_WRAP_BT_DAC_SW_CTRL_DAC_EN_OVR_EN_BIT    ((uint32_t)0x00000001)
#define RFIC_WRAP_BT_DAC_SW_CTRL_DAC_EN_OVR_EN_POS    0

#define RFIC_WRAP_BT_DAC_SW_CTRL_DAC_EN_FALL_DLY_VAL_RST    0x0
#define RFIC_WRAP_BT_DAC_SW_CTRL_DAC_EN_RISE_DLY_VAL_RST    0x0
#define RFIC_WRAP_BT_DAC_SW_CTRL_DAC_EN_DLY_MODE_RST    0x0
#define RFIC_WRAP_BT_DAC_SW_CTRL_DAC_EN_OVR_VAL_RST    0x0
#define RFIC_WRAP_BT_DAC_SW_CTRL_DAC_EN_OVR_EN_RST    0x1

__INLINE void rfic_wrap_bt_dac_sw_ctrl_pack(uint8_t dac_en_fall_dly_val, uint8_t dac_en_rise_dly_val, uint8_t dac_en_dly_mode, uint8_t dac_en_ovr_val, uint8_t dac_en_ovr_en)
{
	ASSERT_ERR((((uint32_t)dac_en_fall_dly_val << 16) & ~((uint32_t)0x001F0000)) == 0);
	ASSERT_ERR((((uint32_t)dac_en_rise_dly_val << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)dac_en_dly_mode << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)dac_en_ovr_val << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)dac_en_ovr_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_DAC_SW_CTRL_ADDR,  ((uint32_t)dac_en_fall_dly_val << 16) |((uint32_t)dac_en_rise_dly_val << 8) |((uint32_t)dac_en_dly_mode << 2) |((uint32_t)dac_en_ovr_val << 1) |((uint32_t)dac_en_ovr_en << 0));
}

__INLINE void rfic_wrap_bt_dac_sw_ctrl_unpack(uint8_t* dac_en_fall_dly_val, uint8_t* dac_en_rise_dly_val, uint8_t* dac_en_dly_mode, uint8_t* dac_en_ovr_val, uint8_t* dac_en_ovr_en)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_DAC_SW_CTRL_ADDR);

	*dac_en_fall_dly_val = (localVal & ((uint32_t)0x001F0000)) >>  16;
	*dac_en_rise_dly_val = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*dac_en_dly_mode = (localVal & ((uint32_t)0x00000004)) >>  2;
	*dac_en_ovr_val = (localVal & ((uint32_t)0x00000002)) >>  1;
	*dac_en_ovr_en = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t rfic_wrap_bt_dac_sw_ctrl_dac_en_fall_dly_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_DAC_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001F0000)) >> 16);
}
__INLINE void rfic_wrap_bt_dac_sw_ctrl_dac_en_fall_dly_val_setf(uint8_t dacenfalldlyval)
{
	ASSERT_ERR((((uint32_t)dacenfalldlyval << 16) & ~((uint32_t)0x001F0000)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_DAC_SW_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_BT_DAC_SW_CTRL_ADDR) & ~((uint32_t)0x001F0000)) | ((uint32_t)dacenfalldlyval <<16));
}
__INLINE uint8_t rfic_wrap_bt_dac_sw_ctrl_dac_en_rise_dly_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_DAC_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void rfic_wrap_bt_dac_sw_ctrl_dac_en_rise_dly_val_setf(uint8_t dacenrisedlyval)
{
	ASSERT_ERR((((uint32_t)dacenrisedlyval << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_DAC_SW_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_BT_DAC_SW_CTRL_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)dacenrisedlyval <<8));
}
__INLINE uint8_t rfic_wrap_bt_dac_sw_ctrl_dac_en_dly_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_DAC_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void rfic_wrap_bt_dac_sw_ctrl_dac_en_dly_mode_setf(uint8_t dacendlymode)
{
	ASSERT_ERR((((uint32_t)dacendlymode << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_DAC_SW_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_BT_DAC_SW_CTRL_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)dacendlymode <<2));
}
__INLINE uint8_t rfic_wrap_bt_dac_sw_ctrl_dac_en_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_DAC_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void rfic_wrap_bt_dac_sw_ctrl_dac_en_ovr_val_setf(uint8_t dacenovrval)
{
	ASSERT_ERR((((uint32_t)dacenovrval << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_DAC_SW_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_BT_DAC_SW_CTRL_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)dacenovrval <<1));
}
__INLINE uint8_t rfic_wrap_bt_dac_sw_ctrl_dac_en_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_DAC_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void rfic_wrap_bt_dac_sw_ctrl_dac_en_ovr_en_setf(uint8_t dacenovren)
{
	ASSERT_ERR((((uint32_t)dacenovren << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_DAC_SW_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_BT_DAC_SW_CTRL_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)dacenovren <<0));
}

/**
 * @brief BT_RF_TX_SW_CTRL_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    05    RF_TR_SW_OVR_VAL          0              
 *    04    RF_TR_SW_OVR_EN           1              
 *    03    RF_PA_EN_OVR_VAL          0              
 *    02    RF_PA_EN_OVR_EN           1              
 *    01    RF_TX_EN_OVR_VAL          0              
 *    00    RF_TX_EN_OVR_EN           1              
 * </pre>
 */
#define RFIC_WRAP_BT_RF_TX_SW_CTRL_0_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000108)
#define RFIC_WRAP_BT_RF_TX_SW_CTRL_0_OFFSET      0x00000108
#define RFIC_WRAP_BT_RF_TX_SW_CTRL_0_INDEX       0x00000042
#define RFIC_WRAP_BT_RF_TX_SW_CTRL_0_RESET       0x00000015

__INLINE uint32_t  rfic_wrap_bt_rf_tx_sw_ctrl_0_get(void)
{
	return REG_PL_RD(RFIC_WRAP_BT_RF_TX_SW_CTRL_0_ADDR);
}

__INLINE void rfic_wrap_bt_rf_tx_sw_ctrl_0_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_BT_RF_TX_SW_CTRL_0_ADDR, value);
}

// field definitions
#define RFIC_WRAP_BT_RF_TX_SW_CTRL_0_RF_TR_SW_OVR_VAL_BIT    ((uint32_t)0x00000020)
#define RFIC_WRAP_BT_RF_TX_SW_CTRL_0_RF_TR_SW_OVR_VAL_POS    5
#define RFIC_WRAP_BT_RF_TX_SW_CTRL_0_RF_TR_SW_OVR_EN_BIT    ((uint32_t)0x00000010)
#define RFIC_WRAP_BT_RF_TX_SW_CTRL_0_RF_TR_SW_OVR_EN_POS    4
#define RFIC_WRAP_BT_RF_TX_SW_CTRL_0_RF_PA_EN_OVR_VAL_BIT    ((uint32_t)0x00000008)
#define RFIC_WRAP_BT_RF_TX_SW_CTRL_0_RF_PA_EN_OVR_VAL_POS    3
#define RFIC_WRAP_BT_RF_TX_SW_CTRL_0_RF_PA_EN_OVR_EN_BIT    ((uint32_t)0x00000004)
#define RFIC_WRAP_BT_RF_TX_SW_CTRL_0_RF_PA_EN_OVR_EN_POS    2
#define RFIC_WRAP_BT_RF_TX_SW_CTRL_0_RF_TX_EN_OVR_VAL_BIT    ((uint32_t)0x00000002)
#define RFIC_WRAP_BT_RF_TX_SW_CTRL_0_RF_TX_EN_OVR_VAL_POS    1
#define RFIC_WRAP_BT_RF_TX_SW_CTRL_0_RF_TX_EN_OVR_EN_BIT    ((uint32_t)0x00000001)
#define RFIC_WRAP_BT_RF_TX_SW_CTRL_0_RF_TX_EN_OVR_EN_POS    0

#define RFIC_WRAP_BT_RF_TX_SW_CTRL_0_RF_TR_SW_OVR_VAL_RST    0x0
#define RFIC_WRAP_BT_RF_TX_SW_CTRL_0_RF_TR_SW_OVR_EN_RST    0x1
#define RFIC_WRAP_BT_RF_TX_SW_CTRL_0_RF_PA_EN_OVR_VAL_RST    0x0
#define RFIC_WRAP_BT_RF_TX_SW_CTRL_0_RF_PA_EN_OVR_EN_RST    0x1
#define RFIC_WRAP_BT_RF_TX_SW_CTRL_0_RF_TX_EN_OVR_VAL_RST    0x0
#define RFIC_WRAP_BT_RF_TX_SW_CTRL_0_RF_TX_EN_OVR_EN_RST    0x1

__INLINE void rfic_wrap_bt_rf_tx_sw_ctrl_0_pack(uint8_t rf_tr_sw_ovr_val, uint8_t rf_tr_sw_ovr_en, uint8_t rf_pa_en_ovr_val, uint8_t rf_pa_en_ovr_en, uint8_t rf_tx_en_ovr_val, uint8_t rf_tx_en_ovr_en)
{
	ASSERT_ERR((((uint32_t)rf_tr_sw_ovr_val << 5) & ~((uint32_t)0x00000020)) == 0);
	ASSERT_ERR((((uint32_t)rf_tr_sw_ovr_en << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)rf_pa_en_ovr_val << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)rf_pa_en_ovr_en << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)rf_tx_en_ovr_val << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)rf_tx_en_ovr_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_TX_SW_CTRL_0_ADDR,  ((uint32_t)rf_tr_sw_ovr_val << 5) |((uint32_t)rf_tr_sw_ovr_en << 4) |((uint32_t)rf_pa_en_ovr_val << 3) |((uint32_t)rf_pa_en_ovr_en << 2) |((uint32_t)rf_tx_en_ovr_val << 1) |((uint32_t)rf_tx_en_ovr_en << 0));
}

__INLINE void rfic_wrap_bt_rf_tx_sw_ctrl_0_unpack(uint8_t* rf_tr_sw_ovr_val, uint8_t* rf_tr_sw_ovr_en, uint8_t* rf_pa_en_ovr_val, uint8_t* rf_pa_en_ovr_en, uint8_t* rf_tx_en_ovr_val, uint8_t* rf_tx_en_ovr_en)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_TX_SW_CTRL_0_ADDR);

	*rf_tr_sw_ovr_val = (localVal & ((uint32_t)0x00000020)) >>  5;
	*rf_tr_sw_ovr_en = (localVal & ((uint32_t)0x00000010)) >>  4;
	*rf_pa_en_ovr_val = (localVal & ((uint32_t)0x00000008)) >>  3;
	*rf_pa_en_ovr_en = (localVal & ((uint32_t)0x00000004)) >>  2;
	*rf_tx_en_ovr_val = (localVal & ((uint32_t)0x00000002)) >>  1;
	*rf_tx_en_ovr_en = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t rfic_wrap_bt_rf_tx_sw_ctrl_0_rf_tr_sw_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_TX_SW_CTRL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE void rfic_wrap_bt_rf_tx_sw_ctrl_0_rf_tr_sw_ovr_val_setf(uint8_t rftrswovrval)
{
	ASSERT_ERR((((uint32_t)rftrswovrval << 5) & ~((uint32_t)0x00000020)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_TX_SW_CTRL_0_ADDR, (REG_PL_RD(RFIC_WRAP_BT_RF_TX_SW_CTRL_0_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)rftrswovrval <<5));
}
__INLINE uint8_t rfic_wrap_bt_rf_tx_sw_ctrl_0_rf_tr_sw_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_TX_SW_CTRL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void rfic_wrap_bt_rf_tx_sw_ctrl_0_rf_tr_sw_ovr_en_setf(uint8_t rftrswovren)
{
	ASSERT_ERR((((uint32_t)rftrswovren << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_TX_SW_CTRL_0_ADDR, (REG_PL_RD(RFIC_WRAP_BT_RF_TX_SW_CTRL_0_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)rftrswovren <<4));
}
__INLINE uint8_t rfic_wrap_bt_rf_tx_sw_ctrl_0_rf_pa_en_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_TX_SW_CTRL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void rfic_wrap_bt_rf_tx_sw_ctrl_0_rf_pa_en_ovr_val_setf(uint8_t rfpaenovrval)
{
	ASSERT_ERR((((uint32_t)rfpaenovrval << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_TX_SW_CTRL_0_ADDR, (REG_PL_RD(RFIC_WRAP_BT_RF_TX_SW_CTRL_0_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)rfpaenovrval <<3));
}
__INLINE uint8_t rfic_wrap_bt_rf_tx_sw_ctrl_0_rf_pa_en_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_TX_SW_CTRL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void rfic_wrap_bt_rf_tx_sw_ctrl_0_rf_pa_en_ovr_en_setf(uint8_t rfpaenovren)
{
	ASSERT_ERR((((uint32_t)rfpaenovren << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_TX_SW_CTRL_0_ADDR, (REG_PL_RD(RFIC_WRAP_BT_RF_TX_SW_CTRL_0_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)rfpaenovren <<2));
}
__INLINE uint8_t rfic_wrap_bt_rf_tx_sw_ctrl_0_rf_tx_en_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_TX_SW_CTRL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void rfic_wrap_bt_rf_tx_sw_ctrl_0_rf_tx_en_ovr_val_setf(uint8_t rftxenovrval)
{
	ASSERT_ERR((((uint32_t)rftxenovrval << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_TX_SW_CTRL_0_ADDR, (REG_PL_RD(RFIC_WRAP_BT_RF_TX_SW_CTRL_0_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)rftxenovrval <<1));
}
__INLINE uint8_t rfic_wrap_bt_rf_tx_sw_ctrl_0_rf_tx_en_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_TX_SW_CTRL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void rfic_wrap_bt_rf_tx_sw_ctrl_0_rf_tx_en_ovr_en_setf(uint8_t rftxenovren)
{
	ASSERT_ERR((((uint32_t)rftxenovren << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_TX_SW_CTRL_0_ADDR, (REG_PL_RD(RFIC_WRAP_BT_RF_TX_SW_CTRL_0_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)rftxenovren <<0));
}

/**
 * @brief BT_RF_TX_SW_CTRL_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    08:01 TX_POWER_OVR_VAL          0x0
 *    00    TX_POWER_OVR_EN           1              
 * </pre>
 */
#define RFIC_WRAP_BT_RF_TX_SW_CTRL_1_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x0000010C)
#define RFIC_WRAP_BT_RF_TX_SW_CTRL_1_OFFSET      0x0000010C
#define RFIC_WRAP_BT_RF_TX_SW_CTRL_1_INDEX       0x00000043
#define RFIC_WRAP_BT_RF_TX_SW_CTRL_1_RESET       0x00000001

__INLINE uint32_t  rfic_wrap_bt_rf_tx_sw_ctrl_1_get(void)
{
	return REG_PL_RD(RFIC_WRAP_BT_RF_TX_SW_CTRL_1_ADDR);
}

__INLINE void rfic_wrap_bt_rf_tx_sw_ctrl_1_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_BT_RF_TX_SW_CTRL_1_ADDR, value);
}

// field definitions
#define RFIC_WRAP_BT_RF_TX_SW_CTRL_1_TX_POWER_OVR_VAL_MASK    ((uint32_t)0x000001FE)
#define RFIC_WRAP_BT_RF_TX_SW_CTRL_1_TX_POWER_OVR_VAL_LSB    1
#define RFIC_WRAP_BT_RF_TX_SW_CTRL_1_TX_POWER_OVR_VAL_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_BT_RF_TX_SW_CTRL_1_TX_POWER_OVR_EN_BIT    ((uint32_t)0x00000001)
#define RFIC_WRAP_BT_RF_TX_SW_CTRL_1_TX_POWER_OVR_EN_POS    0

#define RFIC_WRAP_BT_RF_TX_SW_CTRL_1_TX_POWER_OVR_VAL_RST    0x0
#define RFIC_WRAP_BT_RF_TX_SW_CTRL_1_TX_POWER_OVR_EN_RST    0x1

__INLINE void rfic_wrap_bt_rf_tx_sw_ctrl_1_pack(uint8_t tx_power_ovr_val, uint8_t tx_power_ovr_en)
{
	ASSERT_ERR((((uint32_t)tx_power_ovr_val << 1) & ~((uint32_t)0x000001FE)) == 0);
	ASSERT_ERR((((uint32_t)tx_power_ovr_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_TX_SW_CTRL_1_ADDR,  ((uint32_t)tx_power_ovr_val << 1) |((uint32_t)tx_power_ovr_en << 0));
}

__INLINE void rfic_wrap_bt_rf_tx_sw_ctrl_1_unpack(uint8_t* tx_power_ovr_val, uint8_t* tx_power_ovr_en)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_TX_SW_CTRL_1_ADDR);

	*tx_power_ovr_val = (localVal & ((uint32_t)0x000001FE)) >>  1;
	*tx_power_ovr_en = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t rfic_wrap_bt_rf_tx_sw_ctrl_1_tx_power_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_TX_SW_CTRL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000001FE)) >> 1);
}
__INLINE void rfic_wrap_bt_rf_tx_sw_ctrl_1_tx_power_ovr_val_setf(uint8_t txpowerovrval)
{
	ASSERT_ERR((((uint32_t)txpowerovrval << 1) & ~((uint32_t)0x000001FE)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_TX_SW_CTRL_1_ADDR, (REG_PL_RD(RFIC_WRAP_BT_RF_TX_SW_CTRL_1_ADDR) & ~((uint32_t)0x000001FE)) | ((uint32_t)txpowerovrval <<1));
}
__INLINE uint8_t rfic_wrap_bt_rf_tx_sw_ctrl_1_tx_power_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_TX_SW_CTRL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void rfic_wrap_bt_rf_tx_sw_ctrl_1_tx_power_ovr_en_setf(uint8_t txpowerovren)
{
	ASSERT_ERR((((uint32_t)txpowerovren << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_TX_SW_CTRL_1_ADDR, (REG_PL_RD(RFIC_WRAP_BT_RF_TX_SW_CTRL_1_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)txpowerovren <<0));
}

/**
 * @brief BT_RF_RX_SW_CTRL_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01    RF_RX_EN_OVR_VAL          0              
 *    00    RF_RX_EN_OVR_EN           1              
 * </pre>
 */
#define RFIC_WRAP_BT_RF_RX_SW_CTRL_0_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000110)
#define RFIC_WRAP_BT_RF_RX_SW_CTRL_0_OFFSET      0x00000110
#define RFIC_WRAP_BT_RF_RX_SW_CTRL_0_INDEX       0x00000044
#define RFIC_WRAP_BT_RF_RX_SW_CTRL_0_RESET       0x00000001

__INLINE uint32_t  rfic_wrap_bt_rf_rx_sw_ctrl_0_get(void)
{
	return REG_PL_RD(RFIC_WRAP_BT_RF_RX_SW_CTRL_0_ADDR);
}

__INLINE void rfic_wrap_bt_rf_rx_sw_ctrl_0_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_SW_CTRL_0_ADDR, value);
}

// field definitions
#define RFIC_WRAP_BT_RF_RX_SW_CTRL_0_RF_RX_EN_OVR_VAL_BIT    ((uint32_t)0x00000002)
#define RFIC_WRAP_BT_RF_RX_SW_CTRL_0_RF_RX_EN_OVR_VAL_POS    1
#define RFIC_WRAP_BT_RF_RX_SW_CTRL_0_RF_RX_EN_OVR_EN_BIT    ((uint32_t)0x00000001)
#define RFIC_WRAP_BT_RF_RX_SW_CTRL_0_RF_RX_EN_OVR_EN_POS    0

#define RFIC_WRAP_BT_RF_RX_SW_CTRL_0_RF_RX_EN_OVR_VAL_RST    0x0
#define RFIC_WRAP_BT_RF_RX_SW_CTRL_0_RF_RX_EN_OVR_EN_RST    0x1

__INLINE void rfic_wrap_bt_rf_rx_sw_ctrl_0_pack(uint8_t rf_rx_en_ovr_val, uint8_t rf_rx_en_ovr_en)
{
	ASSERT_ERR((((uint32_t)rf_rx_en_ovr_val << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)rf_rx_en_ovr_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_SW_CTRL_0_ADDR,  ((uint32_t)rf_rx_en_ovr_val << 1) |((uint32_t)rf_rx_en_ovr_en << 0));
}

__INLINE void rfic_wrap_bt_rf_rx_sw_ctrl_0_unpack(uint8_t* rf_rx_en_ovr_val, uint8_t* rf_rx_en_ovr_en)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_RX_SW_CTRL_0_ADDR);

	*rf_rx_en_ovr_val = (localVal & ((uint32_t)0x00000002)) >>  1;
	*rf_rx_en_ovr_en = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t rfic_wrap_bt_rf_rx_sw_ctrl_0_rf_rx_en_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_RX_SW_CTRL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void rfic_wrap_bt_rf_rx_sw_ctrl_0_rf_rx_en_ovr_val_setf(uint8_t rfrxenovrval)
{
	ASSERT_ERR((((uint32_t)rfrxenovrval << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_SW_CTRL_0_ADDR, (REG_PL_RD(RFIC_WRAP_BT_RF_RX_SW_CTRL_0_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)rfrxenovrval <<1));
}
__INLINE uint8_t rfic_wrap_bt_rf_rx_sw_ctrl_0_rf_rx_en_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_RX_SW_CTRL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void rfic_wrap_bt_rf_rx_sw_ctrl_0_rf_rx_en_ovr_en_setf(uint8_t rfrxenovren)
{
	ASSERT_ERR((((uint32_t)rfrxenovren << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_SW_CTRL_0_ADDR, (REG_PL_RD(RFIC_WRAP_BT_RF_RX_SW_CTRL_0_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)rfrxenovren <<0));
}

/**
 * @brief BT_RF_RX_SW_CTRL_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    17    LNA_SAT_OVR_VAL           0              
 *    16    LNA_SAT_OVR_EN            1              
 *    12:09 LPF2_GAIN_OVR_VAL         0x0
 *    08    LPF2_GAIN_OVR_EN          1              
 *    06:05 LPF1_GAIN_OVR_VAL         0x0
 *    04    LPF1_GAIN_OVR_EN          1              
 *    02:01 LNA_GAIN_OVR_VAL          0x0
 *    00    LNA_GAIN_OVR_EN           1              
 * </pre>
 */
#define RFIC_WRAP_BT_RF_RX_SW_CTRL_1_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000114)
#define RFIC_WRAP_BT_RF_RX_SW_CTRL_1_OFFSET      0x00000114
#define RFIC_WRAP_BT_RF_RX_SW_CTRL_1_INDEX       0x00000045
#define RFIC_WRAP_BT_RF_RX_SW_CTRL_1_RESET       0x00010111

__INLINE uint32_t  rfic_wrap_bt_rf_rx_sw_ctrl_1_get(void)
{
	return REG_PL_RD(RFIC_WRAP_BT_RF_RX_SW_CTRL_1_ADDR);
}

__INLINE void rfic_wrap_bt_rf_rx_sw_ctrl_1_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_SW_CTRL_1_ADDR, value);
}

// field definitions
#define RFIC_WRAP_BT_RF_RX_SW_CTRL_1_LNA_SAT_OVR_VAL_BIT    ((uint32_t)0x00020000)
#define RFIC_WRAP_BT_RF_RX_SW_CTRL_1_LNA_SAT_OVR_VAL_POS    17
#define RFIC_WRAP_BT_RF_RX_SW_CTRL_1_LNA_SAT_OVR_EN_BIT    ((uint32_t)0x00010000)
#define RFIC_WRAP_BT_RF_RX_SW_CTRL_1_LNA_SAT_OVR_EN_POS    16
#define RFIC_WRAP_BT_RF_RX_SW_CTRL_1_LPF_2_GAIN_OVR_VAL_MASK    ((uint32_t)0x00001E00)
#define RFIC_WRAP_BT_RF_RX_SW_CTRL_1_LPF_2_GAIN_OVR_VAL_LSB    9
#define RFIC_WRAP_BT_RF_RX_SW_CTRL_1_LPF_2_GAIN_OVR_VAL_WIDTH    ((uint32_t)0x00000004)
#define RFIC_WRAP_BT_RF_RX_SW_CTRL_1_LPF_2_GAIN_OVR_EN_BIT    ((uint32_t)0x00000100)
#define RFIC_WRAP_BT_RF_RX_SW_CTRL_1_LPF_2_GAIN_OVR_EN_POS    8
#define RFIC_WRAP_BT_RF_RX_SW_CTRL_1_LPF_1_GAIN_OVR_VAL_MASK    ((uint32_t)0x00000060)
#define RFIC_WRAP_BT_RF_RX_SW_CTRL_1_LPF_1_GAIN_OVR_VAL_LSB    5
#define RFIC_WRAP_BT_RF_RX_SW_CTRL_1_LPF_1_GAIN_OVR_VAL_WIDTH    ((uint32_t)0x00000002)
#define RFIC_WRAP_BT_RF_RX_SW_CTRL_1_LPF_1_GAIN_OVR_EN_BIT    ((uint32_t)0x00000010)
#define RFIC_WRAP_BT_RF_RX_SW_CTRL_1_LPF_1_GAIN_OVR_EN_POS    4
#define RFIC_WRAP_BT_RF_RX_SW_CTRL_1_LNA_GAIN_OVR_VAL_MASK    ((uint32_t)0x00000006)
#define RFIC_WRAP_BT_RF_RX_SW_CTRL_1_LNA_GAIN_OVR_VAL_LSB    1
#define RFIC_WRAP_BT_RF_RX_SW_CTRL_1_LNA_GAIN_OVR_VAL_WIDTH    ((uint32_t)0x00000002)
#define RFIC_WRAP_BT_RF_RX_SW_CTRL_1_LNA_GAIN_OVR_EN_BIT    ((uint32_t)0x00000001)
#define RFIC_WRAP_BT_RF_RX_SW_CTRL_1_LNA_GAIN_OVR_EN_POS    0

#define RFIC_WRAP_BT_RF_RX_SW_CTRL_1_LNA_SAT_OVR_VAL_RST    0x0
#define RFIC_WRAP_BT_RF_RX_SW_CTRL_1_LNA_SAT_OVR_EN_RST    0x1
#define RFIC_WRAP_BT_RF_RX_SW_CTRL_1_LPF_2_GAIN_OVR_VAL_RST    0x0
#define RFIC_WRAP_BT_RF_RX_SW_CTRL_1_LPF_2_GAIN_OVR_EN_RST    0x1
#define RFIC_WRAP_BT_RF_RX_SW_CTRL_1_LPF_1_GAIN_OVR_VAL_RST    0x0
#define RFIC_WRAP_BT_RF_RX_SW_CTRL_1_LPF_1_GAIN_OVR_EN_RST    0x1
#define RFIC_WRAP_BT_RF_RX_SW_CTRL_1_LNA_GAIN_OVR_VAL_RST    0x0
#define RFIC_WRAP_BT_RF_RX_SW_CTRL_1_LNA_GAIN_OVR_EN_RST    0x1

__INLINE void rfic_wrap_bt_rf_rx_sw_ctrl_1_pack(uint8_t lna_sat_ovr_val, uint8_t lna_sat_ovr_en, uint8_t lpf2_gain_ovr_val, uint8_t lpf2_gain_ovr_en, uint8_t lpf1_gain_ovr_val, uint8_t lpf1_gain_ovr_en, uint8_t lna_gain_ovr_val, uint8_t lna_gain_ovr_en)
{
	ASSERT_ERR((((uint32_t)lna_sat_ovr_val << 17) & ~((uint32_t)0x00020000)) == 0);
	ASSERT_ERR((((uint32_t)lna_sat_ovr_en << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)lpf2_gain_ovr_val << 9) & ~((uint32_t)0x00001E00)) == 0);
	ASSERT_ERR((((uint32_t)lpf2_gain_ovr_en << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)lpf1_gain_ovr_val << 5) & ~((uint32_t)0x00000060)) == 0);
	ASSERT_ERR((((uint32_t)lpf1_gain_ovr_en << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)lna_gain_ovr_val << 1) & ~((uint32_t)0x00000006)) == 0);
	ASSERT_ERR((((uint32_t)lna_gain_ovr_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_SW_CTRL_1_ADDR,  ((uint32_t)lna_sat_ovr_val << 17) |((uint32_t)lna_sat_ovr_en << 16) |((uint32_t)lpf2_gain_ovr_val << 9) |((uint32_t)lpf2_gain_ovr_en << 8) |((uint32_t)lpf1_gain_ovr_val << 5) |((uint32_t)lpf1_gain_ovr_en << 4) |((uint32_t)lna_gain_ovr_val << 1) |((uint32_t)lna_gain_ovr_en << 0));
}

__INLINE void rfic_wrap_bt_rf_rx_sw_ctrl_1_unpack(uint8_t* lna_sat_ovr_val, uint8_t* lna_sat_ovr_en, uint8_t* lpf2_gain_ovr_val, uint8_t* lpf2_gain_ovr_en, uint8_t* lpf1_gain_ovr_val, uint8_t* lpf1_gain_ovr_en, uint8_t* lna_gain_ovr_val, uint8_t* lna_gain_ovr_en)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_RX_SW_CTRL_1_ADDR);

	*lna_sat_ovr_val = (localVal & ((uint32_t)0x00020000)) >>  17;
	*lna_sat_ovr_en = (localVal & ((uint32_t)0x00010000)) >>  16;
	*lpf2_gain_ovr_val = (localVal & ((uint32_t)0x00001E00)) >>  9;
	*lpf2_gain_ovr_en = (localVal & ((uint32_t)0x00000100)) >>  8;
	*lpf1_gain_ovr_val = (localVal & ((uint32_t)0x00000060)) >>  5;
	*lpf1_gain_ovr_en = (localVal & ((uint32_t)0x00000010)) >>  4;
	*lna_gain_ovr_val = (localVal & ((uint32_t)0x00000006)) >>  1;
	*lna_gain_ovr_en = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t rfic_wrap_bt_rf_rx_sw_ctrl_1_lna_sat_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_RX_SW_CTRL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00020000)) >> 17);
}
__INLINE void rfic_wrap_bt_rf_rx_sw_ctrl_1_lna_sat_ovr_val_setf(uint8_t lnasatovrval)
{
	ASSERT_ERR((((uint32_t)lnasatovrval << 17) & ~((uint32_t)0x00020000)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_SW_CTRL_1_ADDR, (REG_PL_RD(RFIC_WRAP_BT_RF_RX_SW_CTRL_1_ADDR) & ~((uint32_t)0x00020000)) | ((uint32_t)lnasatovrval <<17));
}
__INLINE uint8_t rfic_wrap_bt_rf_rx_sw_ctrl_1_lna_sat_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_RX_SW_CTRL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void rfic_wrap_bt_rf_rx_sw_ctrl_1_lna_sat_ovr_en_setf(uint8_t lnasatovren)
{
	ASSERT_ERR((((uint32_t)lnasatovren << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_SW_CTRL_1_ADDR, (REG_PL_RD(RFIC_WRAP_BT_RF_RX_SW_CTRL_1_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)lnasatovren <<16));
}
__INLINE uint8_t rfic_wrap_bt_rf_rx_sw_ctrl_1_lpf_2_gain_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_RX_SW_CTRL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001E00)) >> 9);
}
__INLINE void rfic_wrap_bt_rf_rx_sw_ctrl_1_lpf_2_gain_ovr_val_setf(uint8_t lpf2gainovrval)
{
	ASSERT_ERR((((uint32_t)lpf2gainovrval << 9) & ~((uint32_t)0x00001E00)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_SW_CTRL_1_ADDR, (REG_PL_RD(RFIC_WRAP_BT_RF_RX_SW_CTRL_1_ADDR) & ~((uint32_t)0x00001E00)) | ((uint32_t)lpf2gainovrval <<9));
}
__INLINE uint8_t rfic_wrap_bt_rf_rx_sw_ctrl_1_lpf_2_gain_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_RX_SW_CTRL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void rfic_wrap_bt_rf_rx_sw_ctrl_1_lpf_2_gain_ovr_en_setf(uint8_t lpf2gainovren)
{
	ASSERT_ERR((((uint32_t)lpf2gainovren << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_SW_CTRL_1_ADDR, (REG_PL_RD(RFIC_WRAP_BT_RF_RX_SW_CTRL_1_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)lpf2gainovren <<8));
}
__INLINE uint8_t rfic_wrap_bt_rf_rx_sw_ctrl_1_lpf_1_gain_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_RX_SW_CTRL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000060)) >> 5);
}
__INLINE void rfic_wrap_bt_rf_rx_sw_ctrl_1_lpf_1_gain_ovr_val_setf(uint8_t lpf1gainovrval)
{
	ASSERT_ERR((((uint32_t)lpf1gainovrval << 5) & ~((uint32_t)0x00000060)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_SW_CTRL_1_ADDR, (REG_PL_RD(RFIC_WRAP_BT_RF_RX_SW_CTRL_1_ADDR) & ~((uint32_t)0x00000060)) | ((uint32_t)lpf1gainovrval <<5));
}
__INLINE uint8_t rfic_wrap_bt_rf_rx_sw_ctrl_1_lpf_1_gain_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_RX_SW_CTRL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void rfic_wrap_bt_rf_rx_sw_ctrl_1_lpf_1_gain_ovr_en_setf(uint8_t lpf1gainovren)
{
	ASSERT_ERR((((uint32_t)lpf1gainovren << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_SW_CTRL_1_ADDR, (REG_PL_RD(RFIC_WRAP_BT_RF_RX_SW_CTRL_1_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)lpf1gainovren <<4));
}
__INLINE uint8_t rfic_wrap_bt_rf_rx_sw_ctrl_1_lna_gain_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_RX_SW_CTRL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000006)) >> 1);
}
__INLINE void rfic_wrap_bt_rf_rx_sw_ctrl_1_lna_gain_ovr_val_setf(uint8_t lnagainovrval)
{
	ASSERT_ERR((((uint32_t)lnagainovrval << 1) & ~((uint32_t)0x00000006)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_SW_CTRL_1_ADDR, (REG_PL_RD(RFIC_WRAP_BT_RF_RX_SW_CTRL_1_ADDR) & ~((uint32_t)0x00000006)) | ((uint32_t)lnagainovrval <<1));
}
__INLINE uint8_t rfic_wrap_bt_rf_rx_sw_ctrl_1_lna_gain_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_RX_SW_CTRL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void rfic_wrap_bt_rf_rx_sw_ctrl_1_lna_gain_ovr_en_setf(uint8_t lnagainovren)
{
	ASSERT_ERR((((uint32_t)lnagainovren << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_SW_CTRL_1_ADDR, (REG_PL_RD(RFIC_WRAP_BT_RF_RX_SW_CTRL_1_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)lnagainovren <<0));
}

/**
 * @brief BT_RF_COMMON_SW_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    11:09 MOD_SEL_OVR_VAL           0x0
 *    08    MOD_SEL_OVR_EN            1              
 *    07:01 CHANNEL_OVR_VAL           0x0
 *    00    CHANNEL_OVR_EN            1              
 * </pre>
 */
#define RFIC_WRAP_BT_RF_COMMON_SW_CTRL_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000118)
#define RFIC_WRAP_BT_RF_COMMON_SW_CTRL_OFFSET      0x00000118
#define RFIC_WRAP_BT_RF_COMMON_SW_CTRL_INDEX       0x00000046
#define RFIC_WRAP_BT_RF_COMMON_SW_CTRL_RESET       0x00000101

__INLINE uint32_t  rfic_wrap_bt_rf_common_sw_ctrl_get(void)
{
	return REG_PL_RD(RFIC_WRAP_BT_RF_COMMON_SW_CTRL_ADDR);
}

__INLINE void rfic_wrap_bt_rf_common_sw_ctrl_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_BT_RF_COMMON_SW_CTRL_ADDR, value);
}

// field definitions
#define RFIC_WRAP_BT_RF_COMMON_SW_CTRL_MOD_SEL_OVR_VAL_MASK    ((uint32_t)0x00000E00)
#define RFIC_WRAP_BT_RF_COMMON_SW_CTRL_MOD_SEL_OVR_VAL_LSB    9
#define RFIC_WRAP_BT_RF_COMMON_SW_CTRL_MOD_SEL_OVR_VAL_WIDTH    ((uint32_t)0x00000003)
#define RFIC_WRAP_BT_RF_COMMON_SW_CTRL_MOD_SEL_OVR_EN_BIT    ((uint32_t)0x00000100)
#define RFIC_WRAP_BT_RF_COMMON_SW_CTRL_MOD_SEL_OVR_EN_POS    8
#define RFIC_WRAP_BT_RF_COMMON_SW_CTRL_CHANNEL_OVR_VAL_MASK    ((uint32_t)0x000000FE)
#define RFIC_WRAP_BT_RF_COMMON_SW_CTRL_CHANNEL_OVR_VAL_LSB    1
#define RFIC_WRAP_BT_RF_COMMON_SW_CTRL_CHANNEL_OVR_VAL_WIDTH    ((uint32_t)0x00000007)
#define RFIC_WRAP_BT_RF_COMMON_SW_CTRL_CHANNEL_OVR_EN_BIT    ((uint32_t)0x00000001)
#define RFIC_WRAP_BT_RF_COMMON_SW_CTRL_CHANNEL_OVR_EN_POS    0

#define RFIC_WRAP_BT_RF_COMMON_SW_CTRL_MOD_SEL_OVR_VAL_RST    0x0
#define RFIC_WRAP_BT_RF_COMMON_SW_CTRL_MOD_SEL_OVR_EN_RST    0x1
#define RFIC_WRAP_BT_RF_COMMON_SW_CTRL_CHANNEL_OVR_VAL_RST    0x0
#define RFIC_WRAP_BT_RF_COMMON_SW_CTRL_CHANNEL_OVR_EN_RST    0x1

__INLINE void rfic_wrap_bt_rf_common_sw_ctrl_pack(uint8_t mod_sel_ovr_val, uint8_t mod_sel_ovr_en, uint8_t channel_ovr_val, uint8_t channel_ovr_en)
{
	ASSERT_ERR((((uint32_t)mod_sel_ovr_val << 9) & ~((uint32_t)0x00000E00)) == 0);
	ASSERT_ERR((((uint32_t)mod_sel_ovr_en << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)channel_ovr_val << 1) & ~((uint32_t)0x000000FE)) == 0);
	ASSERT_ERR((((uint32_t)channel_ovr_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_COMMON_SW_CTRL_ADDR,  ((uint32_t)mod_sel_ovr_val << 9) |((uint32_t)mod_sel_ovr_en << 8) |((uint32_t)channel_ovr_val << 1) |((uint32_t)channel_ovr_en << 0));
}

__INLINE void rfic_wrap_bt_rf_common_sw_ctrl_unpack(uint8_t* mod_sel_ovr_val, uint8_t* mod_sel_ovr_en, uint8_t* channel_ovr_val, uint8_t* channel_ovr_en)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_COMMON_SW_CTRL_ADDR);

	*mod_sel_ovr_val = (localVal & ((uint32_t)0x00000E00)) >>  9;
	*mod_sel_ovr_en = (localVal & ((uint32_t)0x00000100)) >>  8;
	*channel_ovr_val = (localVal & ((uint32_t)0x000000FE)) >>  1;
	*channel_ovr_en = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t rfic_wrap_bt_rf_common_sw_ctrl_mod_sel_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_COMMON_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000E00)) >> 9);
}
__INLINE void rfic_wrap_bt_rf_common_sw_ctrl_mod_sel_ovr_val_setf(uint8_t modselovrval)
{
	ASSERT_ERR((((uint32_t)modselovrval << 9) & ~((uint32_t)0x00000E00)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_COMMON_SW_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_BT_RF_COMMON_SW_CTRL_ADDR) & ~((uint32_t)0x00000E00)) | ((uint32_t)modselovrval <<9));
}
__INLINE uint8_t rfic_wrap_bt_rf_common_sw_ctrl_mod_sel_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_COMMON_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void rfic_wrap_bt_rf_common_sw_ctrl_mod_sel_ovr_en_setf(uint8_t modselovren)
{
	ASSERT_ERR((((uint32_t)modselovren << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_COMMON_SW_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_BT_RF_COMMON_SW_CTRL_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)modselovren <<8));
}
__INLINE uint8_t rfic_wrap_bt_rf_common_sw_ctrl_channel_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_COMMON_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FE)) >> 1);
}
__INLINE void rfic_wrap_bt_rf_common_sw_ctrl_channel_ovr_val_setf(uint8_t channelovrval)
{
	ASSERT_ERR((((uint32_t)channelovrval << 1) & ~((uint32_t)0x000000FE)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_COMMON_SW_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_BT_RF_COMMON_SW_CTRL_ADDR) & ~((uint32_t)0x000000FE)) | ((uint32_t)channelovrval <<1));
}
__INLINE uint8_t rfic_wrap_bt_rf_common_sw_ctrl_channel_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_COMMON_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void rfic_wrap_bt_rf_common_sw_ctrl_channel_ovr_en_setf(uint8_t channelovren)
{
	ASSERT_ERR((((uint32_t)channelovren << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_COMMON_SW_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_BT_RF_COMMON_SW_CTRL_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)channelovren <<0));
}

/**
 * @brief BT_SYNC_BUFF_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    04    RX_SW_SYNC_EN             0              
 *    03:02 DAC_DATA_VALID_MODE       0x0
 *    01:00 ADC_DATA_EN_MODE          0x0
 * </pre>
 */
#define RFIC_WRAP_BT_SYNC_BUFF_CTRL_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x0000011C)
#define RFIC_WRAP_BT_SYNC_BUFF_CTRL_OFFSET      0x0000011C
#define RFIC_WRAP_BT_SYNC_BUFF_CTRL_INDEX       0x00000047
#define RFIC_WRAP_BT_SYNC_BUFF_CTRL_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_bt_sync_buff_ctrl_get(void)
{
	return REG_PL_RD(RFIC_WRAP_BT_SYNC_BUFF_CTRL_ADDR);
}

__INLINE void rfic_wrap_bt_sync_buff_ctrl_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_BT_SYNC_BUFF_CTRL_ADDR, value);
}

// field definitions
#define RFIC_WRAP_BT_SYNC_BUFF_CTRL_RX_SW_SYNC_EN_BIT    ((uint32_t)0x00000010)
#define RFIC_WRAP_BT_SYNC_BUFF_CTRL_RX_SW_SYNC_EN_POS    4
#define RFIC_WRAP_BT_SYNC_BUFF_CTRL_DAC_DATA_VALID_MODE_MASK    ((uint32_t)0x0000000C)
#define RFIC_WRAP_BT_SYNC_BUFF_CTRL_DAC_DATA_VALID_MODE_LSB    2
#define RFIC_WRAP_BT_SYNC_BUFF_CTRL_DAC_DATA_VALID_MODE_WIDTH    ((uint32_t)0x00000002)
#define RFIC_WRAP_BT_SYNC_BUFF_CTRL_ADC_DATA_EN_MODE_MASK    ((uint32_t)0x00000003)
#define RFIC_WRAP_BT_SYNC_BUFF_CTRL_ADC_DATA_EN_MODE_LSB    0
#define RFIC_WRAP_BT_SYNC_BUFF_CTRL_ADC_DATA_EN_MODE_WIDTH    ((uint32_t)0x00000002)

#define RFIC_WRAP_BT_SYNC_BUFF_CTRL_RX_SW_SYNC_EN_RST    0x0
#define RFIC_WRAP_BT_SYNC_BUFF_CTRL_DAC_DATA_VALID_MODE_RST    0x0
#define RFIC_WRAP_BT_SYNC_BUFF_CTRL_ADC_DATA_EN_MODE_RST    0x0

__INLINE void rfic_wrap_bt_sync_buff_ctrl_pack(uint8_t rx_sw_sync_en, uint8_t dac_data_valid_mode, uint8_t adc_data_en_mode)
{
	ASSERT_ERR((((uint32_t)rx_sw_sync_en << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)dac_data_valid_mode << 2) & ~((uint32_t)0x0000000C)) == 0);
	ASSERT_ERR((((uint32_t)adc_data_en_mode << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_SYNC_BUFF_CTRL_ADDR,  ((uint32_t)rx_sw_sync_en << 4) |((uint32_t)dac_data_valid_mode << 2) |((uint32_t)adc_data_en_mode << 0));
}

__INLINE void rfic_wrap_bt_sync_buff_ctrl_unpack(uint8_t* rx_sw_sync_en, uint8_t* dac_data_valid_mode, uint8_t* adc_data_en_mode)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_SYNC_BUFF_CTRL_ADDR);

	*rx_sw_sync_en = (localVal & ((uint32_t)0x00000010)) >>  4;
	*dac_data_valid_mode = (localVal & ((uint32_t)0x0000000C)) >>  2;
	*adc_data_en_mode = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint8_t rfic_wrap_bt_sync_buff_ctrl_rx_sw_sync_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_SYNC_BUFF_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void rfic_wrap_bt_sync_buff_ctrl_rx_sw_sync_en_setf(uint8_t rxswsyncen)
{
	ASSERT_ERR((((uint32_t)rxswsyncen << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_SYNC_BUFF_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_BT_SYNC_BUFF_CTRL_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)rxswsyncen <<4));
}
__INLINE uint8_t rfic_wrap_bt_sync_buff_ctrl_dac_data_valid_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_SYNC_BUFF_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000C)) >> 2);
}
__INLINE void rfic_wrap_bt_sync_buff_ctrl_dac_data_valid_mode_setf(uint8_t dacdatavalidmode)
{
	ASSERT_ERR((((uint32_t)dacdatavalidmode << 2) & ~((uint32_t)0x0000000C)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_SYNC_BUFF_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_BT_SYNC_BUFF_CTRL_ADDR) & ~((uint32_t)0x0000000C)) | ((uint32_t)dacdatavalidmode <<2));
}
__INLINE uint8_t rfic_wrap_bt_sync_buff_ctrl_adc_data_en_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_SYNC_BUFF_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void rfic_wrap_bt_sync_buff_ctrl_adc_data_en_mode_setf(uint8_t adcdataenmode)
{
	ASSERT_ERR((((uint32_t)adcdataenmode << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_SYNC_BUFF_CTRL_ADDR, (REG_PL_RD(RFIC_WRAP_BT_SYNC_BUFF_CTRL_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)adcdataenmode <<0));
}

/**
 * @brief BT_SYNC_BUFF_INIT_VAL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:08 INIT_Q                    0x0
 *    07:00 INIT_I                    0x0
 * </pre>
 */
#define RFIC_WRAP_BT_SYNC_BUFF_INIT_VAL_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000120)
#define RFIC_WRAP_BT_SYNC_BUFF_INIT_VAL_OFFSET      0x00000120
#define RFIC_WRAP_BT_SYNC_BUFF_INIT_VAL_INDEX       0x00000048
#define RFIC_WRAP_BT_SYNC_BUFF_INIT_VAL_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_bt_sync_buff_init_val_get(void)
{
	return REG_PL_RD(RFIC_WRAP_BT_SYNC_BUFF_INIT_VAL_ADDR);
}

__INLINE void rfic_wrap_bt_sync_buff_init_val_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_BT_SYNC_BUFF_INIT_VAL_ADDR, value);
}

// field definitions
#define RFIC_WRAP_BT_SYNC_BUFF_INIT_VAL_INIT_Q_MASK    ((uint32_t)0x0000FF00)
#define RFIC_WRAP_BT_SYNC_BUFF_INIT_VAL_INIT_Q_LSB    8
#define RFIC_WRAP_BT_SYNC_BUFF_INIT_VAL_INIT_Q_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_BT_SYNC_BUFF_INIT_VAL_INIT_I_MASK    ((uint32_t)0x000000FF)
#define RFIC_WRAP_BT_SYNC_BUFF_INIT_VAL_INIT_I_LSB    0
#define RFIC_WRAP_BT_SYNC_BUFF_INIT_VAL_INIT_I_WIDTH    ((uint32_t)0x00000008)

#define RFIC_WRAP_BT_SYNC_BUFF_INIT_VAL_INIT_Q_RST    0x0
#define RFIC_WRAP_BT_SYNC_BUFF_INIT_VAL_INIT_I_RST    0x0

__INLINE void rfic_wrap_bt_sync_buff_init_val_pack(uint8_t init_q, uint8_t init_i)
{
	ASSERT_ERR((((uint32_t)init_q << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)init_i << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_SYNC_BUFF_INIT_VAL_ADDR,  ((uint32_t)init_q << 8) |((uint32_t)init_i << 0));
}

__INLINE void rfic_wrap_bt_sync_buff_init_val_unpack(uint8_t* init_q, uint8_t* init_i)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_SYNC_BUFF_INIT_VAL_ADDR);

	*init_q = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*init_i = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t rfic_wrap_bt_sync_buff_init_val_init_q_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_SYNC_BUFF_INIT_VAL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void rfic_wrap_bt_sync_buff_init_val_init_q_setf(uint8_t initq)
{
	ASSERT_ERR((((uint32_t)initq << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_SYNC_BUFF_INIT_VAL_ADDR, (REG_PL_RD(RFIC_WRAP_BT_SYNC_BUFF_INIT_VAL_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)initq <<8));
}
__INLINE uint8_t rfic_wrap_bt_sync_buff_init_val_init_i_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_SYNC_BUFF_INIT_VAL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void rfic_wrap_bt_sync_buff_init_val_init_i_setf(uint8_t initi)
{
	ASSERT_ERR((((uint32_t)initi << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_SYNC_BUFF_INIT_VAL_ADDR, (REG_PL_RD(RFIC_WRAP_BT_SYNC_BUFF_INIT_VAL_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)initi <<0));
}

/**
 * @brief BT_RF_RX_LNA_0_DCOC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28:24 BB_DCOC_QP                0x0
 *    20:16 BB_DCOC_QN                0x0
 *    12:08 BB_DCOC_IP                0x0
 *    04:00 BB_DCOC_IN                0x0
 * </pre>
 */
#define RFIC_WRAP_BT_RF_RX_LNA_0_DCOC_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000124)
#define RFIC_WRAP_BT_RF_RX_LNA_0_DCOC_OFFSET      0x00000124
#define RFIC_WRAP_BT_RF_RX_LNA_0_DCOC_INDEX       0x00000049
#define RFIC_WRAP_BT_RF_RX_LNA_0_DCOC_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_bt_rf_rx_lna_0_dcoc_get(void)
{
	return REG_PL_RD(RFIC_WRAP_BT_RF_RX_LNA_0_DCOC_ADDR);
}

__INLINE void rfic_wrap_bt_rf_rx_lna_0_dcoc_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_LNA_0_DCOC_ADDR, value);
}

// field definitions
#define RFIC_WRAP_BT_RF_RX_LNA_0_DCOC_BB_DCOC_QP_MASK    ((uint32_t)0x1F000000)
#define RFIC_WRAP_BT_RF_RX_LNA_0_DCOC_BB_DCOC_QP_LSB    24
#define RFIC_WRAP_BT_RF_RX_LNA_0_DCOC_BB_DCOC_QP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_BT_RF_RX_LNA_0_DCOC_BB_DCOC_QN_MASK    ((uint32_t)0x001F0000)
#define RFIC_WRAP_BT_RF_RX_LNA_0_DCOC_BB_DCOC_QN_LSB    16
#define RFIC_WRAP_BT_RF_RX_LNA_0_DCOC_BB_DCOC_QN_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_BT_RF_RX_LNA_0_DCOC_BB_DCOC_IP_MASK    ((uint32_t)0x00001F00)
#define RFIC_WRAP_BT_RF_RX_LNA_0_DCOC_BB_DCOC_IP_LSB    8
#define RFIC_WRAP_BT_RF_RX_LNA_0_DCOC_BB_DCOC_IP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_BT_RF_RX_LNA_0_DCOC_BB_DCOC_IN_MASK    ((uint32_t)0x0000001F)
#define RFIC_WRAP_BT_RF_RX_LNA_0_DCOC_BB_DCOC_IN_LSB    0
#define RFIC_WRAP_BT_RF_RX_LNA_0_DCOC_BB_DCOC_IN_WIDTH    ((uint32_t)0x00000005)

#define RFIC_WRAP_BT_RF_RX_LNA_0_DCOC_BB_DCOC_QP_RST    0x0
#define RFIC_WRAP_BT_RF_RX_LNA_0_DCOC_BB_DCOC_QN_RST    0x0
#define RFIC_WRAP_BT_RF_RX_LNA_0_DCOC_BB_DCOC_IP_RST    0x0
#define RFIC_WRAP_BT_RF_RX_LNA_0_DCOC_BB_DCOC_IN_RST    0x0

__INLINE void rfic_wrap_bt_rf_rx_lna_0_dcoc_pack(uint8_t bb_dcoc_qp, uint8_t bb_dcoc_qn, uint8_t bb_dcoc_ip, uint8_t bb_dcoc_in)
{
	ASSERT_ERR((((uint32_t)bb_dcoc_qp << 24) & ~((uint32_t)0x1F000000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_qn << 16) & ~((uint32_t)0x001F0000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_ip << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_in << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_LNA_0_DCOC_ADDR,  ((uint32_t)bb_dcoc_qp << 24) |((uint32_t)bb_dcoc_qn << 16) |((uint32_t)bb_dcoc_ip << 8) |((uint32_t)bb_dcoc_in << 0));
}

__INLINE void rfic_wrap_bt_rf_rx_lna_0_dcoc_unpack(uint8_t* bb_dcoc_qp, uint8_t* bb_dcoc_qn, uint8_t* bb_dcoc_ip, uint8_t* bb_dcoc_in)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_RX_LNA_0_DCOC_ADDR);

	*bb_dcoc_qp = (localVal & ((uint32_t)0x1F000000)) >>  24;
	*bb_dcoc_qn = (localVal & ((uint32_t)0x001F0000)) >>  16;
	*bb_dcoc_ip = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*bb_dcoc_in = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t rfic_wrap_bt_rf_rx_lna_0_dcoc_bb_dcoc_qp_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_RX_LNA_0_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x1F000000)) >> 24);
}
__INLINE void rfic_wrap_bt_rf_rx_lna_0_dcoc_bb_dcoc_qp_setf(uint8_t bbdcocqp)
{
	ASSERT_ERR((((uint32_t)bbdcocqp << 24) & ~((uint32_t)0x1F000000)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_LNA_0_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_BT_RF_RX_LNA_0_DCOC_ADDR) & ~((uint32_t)0x1F000000)) | ((uint32_t)bbdcocqp <<24));
}
__INLINE uint8_t rfic_wrap_bt_rf_rx_lna_0_dcoc_bb_dcoc_qn_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_RX_LNA_0_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001F0000)) >> 16);
}
__INLINE void rfic_wrap_bt_rf_rx_lna_0_dcoc_bb_dcoc_qn_setf(uint8_t bbdcocqn)
{
	ASSERT_ERR((((uint32_t)bbdcocqn << 16) & ~((uint32_t)0x001F0000)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_LNA_0_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_BT_RF_RX_LNA_0_DCOC_ADDR) & ~((uint32_t)0x001F0000)) | ((uint32_t)bbdcocqn <<16));
}
__INLINE uint8_t rfic_wrap_bt_rf_rx_lna_0_dcoc_bb_dcoc_ip_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_RX_LNA_0_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void rfic_wrap_bt_rf_rx_lna_0_dcoc_bb_dcoc_ip_setf(uint8_t bbdcocip)
{
	ASSERT_ERR((((uint32_t)bbdcocip << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_LNA_0_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_BT_RF_RX_LNA_0_DCOC_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)bbdcocip <<8));
}
__INLINE uint8_t rfic_wrap_bt_rf_rx_lna_0_dcoc_bb_dcoc_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_RX_LNA_0_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void rfic_wrap_bt_rf_rx_lna_0_dcoc_bb_dcoc_in_setf(uint8_t bbdcocin)
{
	ASSERT_ERR((((uint32_t)bbdcocin << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_LNA_0_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_BT_RF_RX_LNA_0_DCOC_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)bbdcocin <<0));
}

/**
 * @brief BT_RF_RX_LNA_1_DCOC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28:24 BB_DCOC_QP                0x0
 *    20:16 BB_DCOC_QN                0x0
 *    12:08 BB_DCOC_IP                0x0
 *    04:00 BB_DCOC_IN                0x0
 * </pre>
 */
#define RFIC_WRAP_BT_RF_RX_LNA_1_DCOC_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000128)
#define RFIC_WRAP_BT_RF_RX_LNA_1_DCOC_OFFSET      0x00000128
#define RFIC_WRAP_BT_RF_RX_LNA_1_DCOC_INDEX       0x0000004A
#define RFIC_WRAP_BT_RF_RX_LNA_1_DCOC_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_bt_rf_rx_lna_1_dcoc_get(void)
{
	return REG_PL_RD(RFIC_WRAP_BT_RF_RX_LNA_1_DCOC_ADDR);
}

__INLINE void rfic_wrap_bt_rf_rx_lna_1_dcoc_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_LNA_1_DCOC_ADDR, value);
}

// field definitions
#define RFIC_WRAP_BT_RF_RX_LNA_1_DCOC_BB_DCOC_QP_MASK    ((uint32_t)0x1F000000)
#define RFIC_WRAP_BT_RF_RX_LNA_1_DCOC_BB_DCOC_QP_LSB    24
#define RFIC_WRAP_BT_RF_RX_LNA_1_DCOC_BB_DCOC_QP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_BT_RF_RX_LNA_1_DCOC_BB_DCOC_QN_MASK    ((uint32_t)0x001F0000)
#define RFIC_WRAP_BT_RF_RX_LNA_1_DCOC_BB_DCOC_QN_LSB    16
#define RFIC_WRAP_BT_RF_RX_LNA_1_DCOC_BB_DCOC_QN_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_BT_RF_RX_LNA_1_DCOC_BB_DCOC_IP_MASK    ((uint32_t)0x00001F00)
#define RFIC_WRAP_BT_RF_RX_LNA_1_DCOC_BB_DCOC_IP_LSB    8
#define RFIC_WRAP_BT_RF_RX_LNA_1_DCOC_BB_DCOC_IP_WIDTH    ((uint32_t)0x00000005)
#define RFIC_WRAP_BT_RF_RX_LNA_1_DCOC_BB_DCOC_IN_MASK    ((uint32_t)0x0000001F)
#define RFIC_WRAP_BT_RF_RX_LNA_1_DCOC_BB_DCOC_IN_LSB    0
#define RFIC_WRAP_BT_RF_RX_LNA_1_DCOC_BB_DCOC_IN_WIDTH    ((uint32_t)0x00000005)

#define RFIC_WRAP_BT_RF_RX_LNA_1_DCOC_BB_DCOC_QP_RST    0x0
#define RFIC_WRAP_BT_RF_RX_LNA_1_DCOC_BB_DCOC_QN_RST    0x0
#define RFIC_WRAP_BT_RF_RX_LNA_1_DCOC_BB_DCOC_IP_RST    0x0
#define RFIC_WRAP_BT_RF_RX_LNA_1_DCOC_BB_DCOC_IN_RST    0x0

__INLINE void rfic_wrap_bt_rf_rx_lna_1_dcoc_pack(uint8_t bb_dcoc_qp, uint8_t bb_dcoc_qn, uint8_t bb_dcoc_ip, uint8_t bb_dcoc_in)
{
	ASSERT_ERR((((uint32_t)bb_dcoc_qp << 24) & ~((uint32_t)0x1F000000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_qn << 16) & ~((uint32_t)0x001F0000)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_ip << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)bb_dcoc_in << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_LNA_1_DCOC_ADDR,  ((uint32_t)bb_dcoc_qp << 24) |((uint32_t)bb_dcoc_qn << 16) |((uint32_t)bb_dcoc_ip << 8) |((uint32_t)bb_dcoc_in << 0));
}

__INLINE void rfic_wrap_bt_rf_rx_lna_1_dcoc_unpack(uint8_t* bb_dcoc_qp, uint8_t* bb_dcoc_qn, uint8_t* bb_dcoc_ip, uint8_t* bb_dcoc_in)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_RX_LNA_1_DCOC_ADDR);

	*bb_dcoc_qp = (localVal & ((uint32_t)0x1F000000)) >>  24;
	*bb_dcoc_qn = (localVal & ((uint32_t)0x001F0000)) >>  16;
	*bb_dcoc_ip = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*bb_dcoc_in = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t rfic_wrap_bt_rf_rx_lna_1_dcoc_bb_dcoc_qp_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_RX_LNA_1_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x1F000000)) >> 24);
}
__INLINE void rfic_wrap_bt_rf_rx_lna_1_dcoc_bb_dcoc_qp_setf(uint8_t bbdcocqp)
{
	ASSERT_ERR((((uint32_t)bbdcocqp << 24) & ~((uint32_t)0x1F000000)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_LNA_1_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_BT_RF_RX_LNA_1_DCOC_ADDR) & ~((uint32_t)0x1F000000)) | ((uint32_t)bbdcocqp <<24));
}
__INLINE uint8_t rfic_wrap_bt_rf_rx_lna_1_dcoc_bb_dcoc_qn_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_RX_LNA_1_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001F0000)) >> 16);
}
__INLINE void rfic_wrap_bt_rf_rx_lna_1_dcoc_bb_dcoc_qn_setf(uint8_t bbdcocqn)
{
	ASSERT_ERR((((uint32_t)bbdcocqn << 16) & ~((uint32_t)0x001F0000)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_LNA_1_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_BT_RF_RX_LNA_1_DCOC_ADDR) & ~((uint32_t)0x001F0000)) | ((uint32_t)bbdcocqn <<16));
}
__INLINE uint8_t rfic_wrap_bt_rf_rx_lna_1_dcoc_bb_dcoc_ip_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_RX_LNA_1_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void rfic_wrap_bt_rf_rx_lna_1_dcoc_bb_dcoc_ip_setf(uint8_t bbdcocip)
{
	ASSERT_ERR((((uint32_t)bbdcocip << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_LNA_1_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_BT_RF_RX_LNA_1_DCOC_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)bbdcocip <<8));
}
__INLINE uint8_t rfic_wrap_bt_rf_rx_lna_1_dcoc_bb_dcoc_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_RX_LNA_1_DCOC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void rfic_wrap_bt_rf_rx_lna_1_dcoc_bb_dcoc_in_setf(uint8_t bbdcocin)
{
	ASSERT_ERR((((uint32_t)bbdcocin << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_LNA_1_DCOC_ADDR, (REG_PL_RD(RFIC_WRAP_BT_RF_RX_LNA_1_DCOC_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)bbdcocin <<0));
}

/**
 * @brief BT_TX_STAT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    19    TX_SYNC_STAT              0              
 *    18:16 MOD_SEL_STAT              0x0
 *    15:09 CHANNEL_STAT              0x0
 *    08:01 TX_POWER_STAT             0x0
 *    00    TX_EN_STAT                0              
 * </pre>
 */
#define RFIC_WRAP_BT_TX_STAT_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x0000012C)
#define RFIC_WRAP_BT_TX_STAT_OFFSET      0x0000012C
#define RFIC_WRAP_BT_TX_STAT_INDEX       0x0000004B
#define RFIC_WRAP_BT_TX_STAT_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_bt_tx_stat_get(void)
{
	return REG_PL_RD(RFIC_WRAP_BT_TX_STAT_ADDR);
}

__INLINE void rfic_wrap_bt_tx_stat_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_BT_TX_STAT_ADDR, value);
}

// field definitions
#define RFIC_WRAP_BT_TX_STAT_TX_SYNC_STAT_BIT    ((uint32_t)0x00080000)
#define RFIC_WRAP_BT_TX_STAT_TX_SYNC_STAT_POS    19
#define RFIC_WRAP_BT_TX_STAT_MOD_SEL_STAT_MASK    ((uint32_t)0x00070000)
#define RFIC_WRAP_BT_TX_STAT_MOD_SEL_STAT_LSB    16
#define RFIC_WRAP_BT_TX_STAT_MOD_SEL_STAT_WIDTH    ((uint32_t)0x00000003)
#define RFIC_WRAP_BT_TX_STAT_CHANNEL_STAT_MASK    ((uint32_t)0x0000FE00)
#define RFIC_WRAP_BT_TX_STAT_CHANNEL_STAT_LSB    9
#define RFIC_WRAP_BT_TX_STAT_CHANNEL_STAT_WIDTH    ((uint32_t)0x00000007)
#define RFIC_WRAP_BT_TX_STAT_TX_POWER_STAT_MASK    ((uint32_t)0x000001FE)
#define RFIC_WRAP_BT_TX_STAT_TX_POWER_STAT_LSB    1
#define RFIC_WRAP_BT_TX_STAT_TX_POWER_STAT_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_BT_TX_STAT_TX_EN_STAT_BIT    ((uint32_t)0x00000001)
#define RFIC_WRAP_BT_TX_STAT_TX_EN_STAT_POS    0

#define RFIC_WRAP_BT_TX_STAT_TX_SYNC_STAT_RST    0x0
#define RFIC_WRAP_BT_TX_STAT_MOD_SEL_STAT_RST    0x0
#define RFIC_WRAP_BT_TX_STAT_CHANNEL_STAT_RST    0x0
#define RFIC_WRAP_BT_TX_STAT_TX_POWER_STAT_RST    0x0
#define RFIC_WRAP_BT_TX_STAT_TX_EN_STAT_RST    0x0

__INLINE void rfic_wrap_bt_tx_stat_pack(uint8_t tx_sync_stat, uint8_t mod_sel_stat, uint8_t channel_stat, uint8_t tx_power_stat, uint8_t tx_en_stat)
{
	ASSERT_ERR((((uint32_t)tx_sync_stat << 19) & ~((uint32_t)0x00080000)) == 0);
	ASSERT_ERR((((uint32_t)mod_sel_stat << 16) & ~((uint32_t)0x00070000)) == 0);
	ASSERT_ERR((((uint32_t)channel_stat << 9) & ~((uint32_t)0x0000FE00)) == 0);
	ASSERT_ERR((((uint32_t)tx_power_stat << 1) & ~((uint32_t)0x000001FE)) == 0);
	ASSERT_ERR((((uint32_t)tx_en_stat << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_TX_STAT_ADDR,  ((uint32_t)tx_sync_stat << 19) |((uint32_t)mod_sel_stat << 16) |((uint32_t)channel_stat << 9) |((uint32_t)tx_power_stat << 1) |((uint32_t)tx_en_stat << 0));
}

__INLINE void rfic_wrap_bt_tx_stat_unpack(uint8_t* tx_sync_stat, uint8_t* mod_sel_stat, uint8_t* channel_stat, uint8_t* tx_power_stat, uint8_t* tx_en_stat)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_TX_STAT_ADDR);

	*tx_sync_stat = (localVal & ((uint32_t)0x00080000)) >>  19;
	*mod_sel_stat = (localVal & ((uint32_t)0x00070000)) >>  16;
	*channel_stat = (localVal & ((uint32_t)0x0000FE00)) >>  9;
	*tx_power_stat = (localVal & ((uint32_t)0x000001FE)) >>  1;
	*tx_en_stat = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t rfic_wrap_bt_tx_stat_tx_sync_stat_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_TX_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00080000)) >> 19);
}
__INLINE void rfic_wrap_bt_tx_stat_tx_sync_stat_setf(uint8_t txsyncstat)
{
	ASSERT_ERR((((uint32_t)txsyncstat << 19) & ~((uint32_t)0x00080000)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_TX_STAT_ADDR, (REG_PL_RD(RFIC_WRAP_BT_TX_STAT_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)txsyncstat <<19));
}
__INLINE uint8_t rfic_wrap_bt_tx_stat_mod_sel_stat_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_TX_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00070000)) >> 16);
}
__INLINE uint8_t rfic_wrap_bt_tx_stat_channel_stat_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_TX_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FE00)) >> 9);
}
__INLINE uint8_t rfic_wrap_bt_tx_stat_tx_power_stat_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_TX_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000001FE)) >> 1);
}
__INLINE uint8_t rfic_wrap_bt_tx_stat_tx_en_stat_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_TX_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief BT_RX_STAT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    25:24 RX_RSSI                   0x0
 *    23    RX_RSSI_VALID             0              
 *    22    RX_AFE_SYNC_STAT          0              
 *    21    RX_MOD_SYNC_STAT          0              
 *    20    ADC_RESET_STAT            0              
 *    19    LNA_SAT_STAT              0              
 *    18:16 MOD_SEL_STAT              0x0
 *    15:09 CHANNEL_STAT              0x0
 *    08:05 LPF2_GAIN_STAT            0x0
 *    04:03 LPF1_GAIN_STAT            0x0
 *    02:01 LNA_GAIN_STAT             0x0
 *    00    RX_EN_STAT                0              
 * </pre>
 */
#define RFIC_WRAP_BT_RX_STAT_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000130)
#define RFIC_WRAP_BT_RX_STAT_OFFSET      0x00000130
#define RFIC_WRAP_BT_RX_STAT_INDEX       0x0000004C
#define RFIC_WRAP_BT_RX_STAT_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_bt_rx_stat_get(void)
{
	return REG_PL_RD(RFIC_WRAP_BT_RX_STAT_ADDR);
}

// field definitions
#define RFIC_WRAP_BT_RX_STAT_RX_RSSI_MASK    ((uint32_t)0x03000000)
#define RFIC_WRAP_BT_RX_STAT_RX_RSSI_LSB    24
#define RFIC_WRAP_BT_RX_STAT_RX_RSSI_WIDTH    ((uint32_t)0x00000002)
#define RFIC_WRAP_BT_RX_STAT_RX_RSSI_VALID_BIT    ((uint32_t)0x00800000)
#define RFIC_WRAP_BT_RX_STAT_RX_RSSI_VALID_POS    23
#define RFIC_WRAP_BT_RX_STAT_RX_AFE_SYNC_STAT_BIT    ((uint32_t)0x00400000)
#define RFIC_WRAP_BT_RX_STAT_RX_AFE_SYNC_STAT_POS    22
#define RFIC_WRAP_BT_RX_STAT_RX_MOD_SYNC_STAT_BIT    ((uint32_t)0x00200000)
#define RFIC_WRAP_BT_RX_STAT_RX_MOD_SYNC_STAT_POS    21
#define RFIC_WRAP_BT_RX_STAT_ADC_RESET_STAT_BIT    ((uint32_t)0x00100000)
#define RFIC_WRAP_BT_RX_STAT_ADC_RESET_STAT_POS    20
#define RFIC_WRAP_BT_RX_STAT_LNA_SAT_STAT_BIT    ((uint32_t)0x00080000)
#define RFIC_WRAP_BT_RX_STAT_LNA_SAT_STAT_POS    19
#define RFIC_WRAP_BT_RX_STAT_MOD_SEL_STAT_MASK    ((uint32_t)0x00070000)
#define RFIC_WRAP_BT_RX_STAT_MOD_SEL_STAT_LSB    16
#define RFIC_WRAP_BT_RX_STAT_MOD_SEL_STAT_WIDTH    ((uint32_t)0x00000003)
#define RFIC_WRAP_BT_RX_STAT_CHANNEL_STAT_MASK    ((uint32_t)0x0000FE00)
#define RFIC_WRAP_BT_RX_STAT_CHANNEL_STAT_LSB    9
#define RFIC_WRAP_BT_RX_STAT_CHANNEL_STAT_WIDTH    ((uint32_t)0x00000007)
#define RFIC_WRAP_BT_RX_STAT_LPF_2_GAIN_STAT_MASK    ((uint32_t)0x000001E0)
#define RFIC_WRAP_BT_RX_STAT_LPF_2_GAIN_STAT_LSB    5
#define RFIC_WRAP_BT_RX_STAT_LPF_2_GAIN_STAT_WIDTH    ((uint32_t)0x00000004)
#define RFIC_WRAP_BT_RX_STAT_LPF_1_GAIN_STAT_MASK    ((uint32_t)0x00000018)
#define RFIC_WRAP_BT_RX_STAT_LPF_1_GAIN_STAT_LSB    3
#define RFIC_WRAP_BT_RX_STAT_LPF_1_GAIN_STAT_WIDTH    ((uint32_t)0x00000002)
#define RFIC_WRAP_BT_RX_STAT_LNA_GAIN_STAT_MASK    ((uint32_t)0x00000006)
#define RFIC_WRAP_BT_RX_STAT_LNA_GAIN_STAT_LSB    1
#define RFIC_WRAP_BT_RX_STAT_LNA_GAIN_STAT_WIDTH    ((uint32_t)0x00000002)
#define RFIC_WRAP_BT_RX_STAT_RX_EN_STAT_BIT    ((uint32_t)0x00000001)
#define RFIC_WRAP_BT_RX_STAT_RX_EN_STAT_POS    0

#define RFIC_WRAP_BT_RX_STAT_RX_RSSI_RST    0x0
#define RFIC_WRAP_BT_RX_STAT_RX_RSSI_VALID_RST    0x0
#define RFIC_WRAP_BT_RX_STAT_RX_AFE_SYNC_STAT_RST    0x0
#define RFIC_WRAP_BT_RX_STAT_RX_MOD_SYNC_STAT_RST    0x0
#define RFIC_WRAP_BT_RX_STAT_ADC_RESET_STAT_RST    0x0
#define RFIC_WRAP_BT_RX_STAT_LNA_SAT_STAT_RST    0x0
#define RFIC_WRAP_BT_RX_STAT_MOD_SEL_STAT_RST    0x0
#define RFIC_WRAP_BT_RX_STAT_CHANNEL_STAT_RST    0x0
#define RFIC_WRAP_BT_RX_STAT_LPF_2_GAIN_STAT_RST    0x0
#define RFIC_WRAP_BT_RX_STAT_LPF_1_GAIN_STAT_RST    0x0
#define RFIC_WRAP_BT_RX_STAT_LNA_GAIN_STAT_RST    0x0
#define RFIC_WRAP_BT_RX_STAT_RX_EN_STAT_RST    0x0

__INLINE void rfic_wrap_bt_rx_stat_unpack(uint8_t* rx_rssi, uint8_t* rx_rssi_valid, uint8_t* rx_afe_sync_stat, uint8_t* rx_mod_sync_stat, uint8_t* adc_reset_stat, uint8_t* lna_sat_stat, uint8_t* mod_sel_stat, uint8_t* channel_stat, uint8_t* lpf2_gain_stat, uint8_t* lpf1_gain_stat, uint8_t* lna_gain_stat, uint8_t* rx_en_stat)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RX_STAT_ADDR);

	*rx_rssi = (localVal & ((uint32_t)0x03000000)) >>  24;
	*rx_rssi_valid = (localVal & ((uint32_t)0x00800000)) >>  23;
	*rx_afe_sync_stat = (localVal & ((uint32_t)0x00400000)) >>  22;
	*rx_mod_sync_stat = (localVal & ((uint32_t)0x00200000)) >>  21;
	*adc_reset_stat = (localVal & ((uint32_t)0x00100000)) >>  20;
	*lna_sat_stat = (localVal & ((uint32_t)0x00080000)) >>  19;
	*mod_sel_stat = (localVal & ((uint32_t)0x00070000)) >>  16;
	*channel_stat = (localVal & ((uint32_t)0x0000FE00)) >>  9;
	*lpf2_gain_stat = (localVal & ((uint32_t)0x000001E0)) >>  5;
	*lpf1_gain_stat = (localVal & ((uint32_t)0x00000018)) >>  3;
	*lna_gain_stat = (localVal & ((uint32_t)0x00000006)) >>  1;
	*rx_en_stat = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t rfic_wrap_bt_rx_stat_rx_rssi_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RX_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x03000000)) >> 24);
}
__INLINE uint8_t rfic_wrap_bt_rx_stat_rx_rssi_valid_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RX_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00800000)) >> 23);
}
__INLINE uint8_t rfic_wrap_bt_rx_stat_rx_afe_sync_stat_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RX_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00400000)) >> 22);
}
__INLINE uint8_t rfic_wrap_bt_rx_stat_rx_mod_sync_stat_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RX_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00200000)) >> 21);
}
__INLINE uint8_t rfic_wrap_bt_rx_stat_adc_reset_stat_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RX_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00100000)) >> 20);
}
__INLINE uint8_t rfic_wrap_bt_rx_stat_lna_sat_stat_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RX_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00080000)) >> 19);
}
__INLINE uint8_t rfic_wrap_bt_rx_stat_mod_sel_stat_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RX_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00070000)) >> 16);
}
__INLINE uint8_t rfic_wrap_bt_rx_stat_channel_stat_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RX_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FE00)) >> 9);
}
__INLINE uint8_t rfic_wrap_bt_rx_stat_lpf_2_gain_stat_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RX_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000001E0)) >> 5);
}
__INLINE uint8_t rfic_wrap_bt_rx_stat_lpf_1_gain_stat_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RX_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000018)) >> 3);
}
__INLINE uint8_t rfic_wrap_bt_rx_stat_lna_gain_stat_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RX_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000006)) >> 1);
}
__INLINE uint8_t rfic_wrap_bt_rx_stat_rx_en_stat_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RX_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief BT_SPI_STAT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    02    SPI_MISO_STAT             0              
 *    01    SPI_MOSI_STAT             0              
 *    00    SPI_SEL_STAT              0              
 * </pre>
 */
#define RFIC_WRAP_BT_SPI_STAT_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000134)
#define RFIC_WRAP_BT_SPI_STAT_OFFSET      0x00000134
#define RFIC_WRAP_BT_SPI_STAT_INDEX       0x0000004D
#define RFIC_WRAP_BT_SPI_STAT_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_bt_spi_stat_get(void)
{
	return REG_PL_RD(RFIC_WRAP_BT_SPI_STAT_ADDR);
}

// field definitions
#define RFIC_WRAP_BT_SPI_STAT_SPI_MISO_STAT_BIT    ((uint32_t)0x00000004)
#define RFIC_WRAP_BT_SPI_STAT_SPI_MISO_STAT_POS    2
#define RFIC_WRAP_BT_SPI_STAT_SPI_MOSI_STAT_BIT    ((uint32_t)0x00000002)
#define RFIC_WRAP_BT_SPI_STAT_SPI_MOSI_STAT_POS    1
#define RFIC_WRAP_BT_SPI_STAT_SPI_SEL_STAT_BIT    ((uint32_t)0x00000001)
#define RFIC_WRAP_BT_SPI_STAT_SPI_SEL_STAT_POS    0

#define RFIC_WRAP_BT_SPI_STAT_SPI_MISO_STAT_RST    0x0
#define RFIC_WRAP_BT_SPI_STAT_SPI_MOSI_STAT_RST    0x0
#define RFIC_WRAP_BT_SPI_STAT_SPI_SEL_STAT_RST    0x0

__INLINE void rfic_wrap_bt_spi_stat_unpack(uint8_t* spi_miso_stat, uint8_t* spi_mosi_stat, uint8_t* spi_sel_stat)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_SPI_STAT_ADDR);

	*spi_miso_stat = (localVal & ((uint32_t)0x00000004)) >>  2;
	*spi_mosi_stat = (localVal & ((uint32_t)0x00000002)) >>  1;
	*spi_sel_stat = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t rfic_wrap_bt_spi_stat_spi_miso_stat_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_SPI_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE uint8_t rfic_wrap_bt_spi_stat_spi_mosi_stat_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_SPI_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t rfic_wrap_bt_spi_stat_spi_sel_stat_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_SPI_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief BT_RF_RX_LNA_0_RSSI_THRES register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 RSSI_THRES_3              0x0
 *    23:16 RSSI_THRES_2              0x0
 *    15:08 RSSI_THRES_1              0x0
 *    07:00 RSSI_THRES_0              0x0
 * </pre>
 */
#define RFIC_WRAP_BT_RF_RX_LNA_0_RSSI_THRES_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000138)
#define RFIC_WRAP_BT_RF_RX_LNA_0_RSSI_THRES_OFFSET      0x00000138
#define RFIC_WRAP_BT_RF_RX_LNA_0_RSSI_THRES_INDEX       0x0000004E
#define RFIC_WRAP_BT_RF_RX_LNA_0_RSSI_THRES_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_bt_rf_rx_lna_0_rssi_thres_get(void)
{
	return REG_PL_RD(RFIC_WRAP_BT_RF_RX_LNA_0_RSSI_THRES_ADDR);
}

__INLINE void rfic_wrap_bt_rf_rx_lna_0_rssi_thres_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_LNA_0_RSSI_THRES_ADDR, value);
}

// field definitions
#define RFIC_WRAP_BT_RF_RX_LNA_0_RSSI_THRES_RSSI_THRES_3_MASK    ((uint32_t)0xFF000000)
#define RFIC_WRAP_BT_RF_RX_LNA_0_RSSI_THRES_RSSI_THRES_3_LSB    24
#define RFIC_WRAP_BT_RF_RX_LNA_0_RSSI_THRES_RSSI_THRES_3_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_BT_RF_RX_LNA_0_RSSI_THRES_RSSI_THRES_2_MASK    ((uint32_t)0x00FF0000)
#define RFIC_WRAP_BT_RF_RX_LNA_0_RSSI_THRES_RSSI_THRES_2_LSB    16
#define RFIC_WRAP_BT_RF_RX_LNA_0_RSSI_THRES_RSSI_THRES_2_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_BT_RF_RX_LNA_0_RSSI_THRES_RSSI_THRES_1_MASK    ((uint32_t)0x0000FF00)
#define RFIC_WRAP_BT_RF_RX_LNA_0_RSSI_THRES_RSSI_THRES_1_LSB    8
#define RFIC_WRAP_BT_RF_RX_LNA_0_RSSI_THRES_RSSI_THRES_1_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_BT_RF_RX_LNA_0_RSSI_THRES_RSSI_THRES_0_MASK    ((uint32_t)0x000000FF)
#define RFIC_WRAP_BT_RF_RX_LNA_0_RSSI_THRES_RSSI_THRES_0_LSB    0
#define RFIC_WRAP_BT_RF_RX_LNA_0_RSSI_THRES_RSSI_THRES_0_WIDTH    ((uint32_t)0x00000008)

#define RFIC_WRAP_BT_RF_RX_LNA_0_RSSI_THRES_RSSI_THRES_3_RST    0x0
#define RFIC_WRAP_BT_RF_RX_LNA_0_RSSI_THRES_RSSI_THRES_2_RST    0x0
#define RFIC_WRAP_BT_RF_RX_LNA_0_RSSI_THRES_RSSI_THRES_1_RST    0x0
#define RFIC_WRAP_BT_RF_RX_LNA_0_RSSI_THRES_RSSI_THRES_0_RST    0x0

__INLINE void rfic_wrap_bt_rf_rx_lna_0_rssi_thres_pack(uint8_t rssi_thres_3, uint8_t rssi_thres_2, uint8_t rssi_thres_1, uint8_t rssi_thres_0)
{
	ASSERT_ERR((((uint32_t)rssi_thres_3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_LNA_0_RSSI_THRES_ADDR,  ((uint32_t)rssi_thres_3 << 24) |((uint32_t)rssi_thres_2 << 16) |((uint32_t)rssi_thres_1 << 8) |((uint32_t)rssi_thres_0 << 0));
}

__INLINE void rfic_wrap_bt_rf_rx_lna_0_rssi_thres_unpack(uint8_t* rssi_thres_3, uint8_t* rssi_thres_2, uint8_t* rssi_thres_1, uint8_t* rssi_thres_0)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_RX_LNA_0_RSSI_THRES_ADDR);

	*rssi_thres_3 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rssi_thres_2 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rssi_thres_1 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*rssi_thres_0 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t rfic_wrap_bt_rf_rx_lna_0_rssi_thres_rssi_thres_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_RX_LNA_0_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void rfic_wrap_bt_rf_rx_lna_0_rssi_thres_rssi_thres_3_setf(uint8_t rssithres3)
{
	ASSERT_ERR((((uint32_t)rssithres3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_LNA_0_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_BT_RF_RX_LNA_0_RSSI_THRES_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)rssithres3 <<24));
}
__INLINE uint8_t rfic_wrap_bt_rf_rx_lna_0_rssi_thres_rssi_thres_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_RX_LNA_0_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void rfic_wrap_bt_rf_rx_lna_0_rssi_thres_rssi_thres_2_setf(uint8_t rssithres2)
{
	ASSERT_ERR((((uint32_t)rssithres2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_LNA_0_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_BT_RF_RX_LNA_0_RSSI_THRES_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rssithres2 <<16));
}
__INLINE uint8_t rfic_wrap_bt_rf_rx_lna_0_rssi_thres_rssi_thres_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_RX_LNA_0_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void rfic_wrap_bt_rf_rx_lna_0_rssi_thres_rssi_thres_1_setf(uint8_t rssithres1)
{
	ASSERT_ERR((((uint32_t)rssithres1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_LNA_0_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_BT_RF_RX_LNA_0_RSSI_THRES_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)rssithres1 <<8));
}
__INLINE uint8_t rfic_wrap_bt_rf_rx_lna_0_rssi_thres_rssi_thres_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_RX_LNA_0_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void rfic_wrap_bt_rf_rx_lna_0_rssi_thres_rssi_thres_0_setf(uint8_t rssithres0)
{
	ASSERT_ERR((((uint32_t)rssithres0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_LNA_0_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_BT_RF_RX_LNA_0_RSSI_THRES_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)rssithres0 <<0));
}

/**
 * @brief BT_RF_RX_LNA_1_RSSI_THRES register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 RSSI_THRES_3              0x0
 *    23:16 RSSI_THRES_2              0x0
 *    15:08 RSSI_THRES_1              0x0
 *    07:00 RSSI_THRES_0              0x0
 * </pre>
 */
#define RFIC_WRAP_BT_RF_RX_LNA_1_RSSI_THRES_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x0000013C)
#define RFIC_WRAP_BT_RF_RX_LNA_1_RSSI_THRES_OFFSET      0x0000013C
#define RFIC_WRAP_BT_RF_RX_LNA_1_RSSI_THRES_INDEX       0x0000004F
#define RFIC_WRAP_BT_RF_RX_LNA_1_RSSI_THRES_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_bt_rf_rx_lna_1_rssi_thres_get(void)
{
	return REG_PL_RD(RFIC_WRAP_BT_RF_RX_LNA_1_RSSI_THRES_ADDR);
}

__INLINE void rfic_wrap_bt_rf_rx_lna_1_rssi_thres_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_LNA_1_RSSI_THRES_ADDR, value);
}

// field definitions
#define RFIC_WRAP_BT_RF_RX_LNA_1_RSSI_THRES_RSSI_THRES_3_MASK    ((uint32_t)0xFF000000)
#define RFIC_WRAP_BT_RF_RX_LNA_1_RSSI_THRES_RSSI_THRES_3_LSB    24
#define RFIC_WRAP_BT_RF_RX_LNA_1_RSSI_THRES_RSSI_THRES_3_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_BT_RF_RX_LNA_1_RSSI_THRES_RSSI_THRES_2_MASK    ((uint32_t)0x00FF0000)
#define RFIC_WRAP_BT_RF_RX_LNA_1_RSSI_THRES_RSSI_THRES_2_LSB    16
#define RFIC_WRAP_BT_RF_RX_LNA_1_RSSI_THRES_RSSI_THRES_2_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_BT_RF_RX_LNA_1_RSSI_THRES_RSSI_THRES_1_MASK    ((uint32_t)0x0000FF00)
#define RFIC_WRAP_BT_RF_RX_LNA_1_RSSI_THRES_RSSI_THRES_1_LSB    8
#define RFIC_WRAP_BT_RF_RX_LNA_1_RSSI_THRES_RSSI_THRES_1_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_BT_RF_RX_LNA_1_RSSI_THRES_RSSI_THRES_0_MASK    ((uint32_t)0x000000FF)
#define RFIC_WRAP_BT_RF_RX_LNA_1_RSSI_THRES_RSSI_THRES_0_LSB    0
#define RFIC_WRAP_BT_RF_RX_LNA_1_RSSI_THRES_RSSI_THRES_0_WIDTH    ((uint32_t)0x00000008)

#define RFIC_WRAP_BT_RF_RX_LNA_1_RSSI_THRES_RSSI_THRES_3_RST    0x0
#define RFIC_WRAP_BT_RF_RX_LNA_1_RSSI_THRES_RSSI_THRES_2_RST    0x0
#define RFIC_WRAP_BT_RF_RX_LNA_1_RSSI_THRES_RSSI_THRES_1_RST    0x0
#define RFIC_WRAP_BT_RF_RX_LNA_1_RSSI_THRES_RSSI_THRES_0_RST    0x0

__INLINE void rfic_wrap_bt_rf_rx_lna_1_rssi_thres_pack(uint8_t rssi_thres_3, uint8_t rssi_thres_2, uint8_t rssi_thres_1, uint8_t rssi_thres_0)
{
	ASSERT_ERR((((uint32_t)rssi_thres_3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_LNA_1_RSSI_THRES_ADDR,  ((uint32_t)rssi_thres_3 << 24) |((uint32_t)rssi_thres_2 << 16) |((uint32_t)rssi_thres_1 << 8) |((uint32_t)rssi_thres_0 << 0));
}

__INLINE void rfic_wrap_bt_rf_rx_lna_1_rssi_thres_unpack(uint8_t* rssi_thres_3, uint8_t* rssi_thres_2, uint8_t* rssi_thres_1, uint8_t* rssi_thres_0)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_RX_LNA_1_RSSI_THRES_ADDR);

	*rssi_thres_3 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rssi_thres_2 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rssi_thres_1 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*rssi_thres_0 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t rfic_wrap_bt_rf_rx_lna_1_rssi_thres_rssi_thres_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_RX_LNA_1_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void rfic_wrap_bt_rf_rx_lna_1_rssi_thres_rssi_thres_3_setf(uint8_t rssithres3)
{
	ASSERT_ERR((((uint32_t)rssithres3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_LNA_1_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_BT_RF_RX_LNA_1_RSSI_THRES_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)rssithres3 <<24));
}
__INLINE uint8_t rfic_wrap_bt_rf_rx_lna_1_rssi_thres_rssi_thres_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_RX_LNA_1_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void rfic_wrap_bt_rf_rx_lna_1_rssi_thres_rssi_thres_2_setf(uint8_t rssithres2)
{
	ASSERT_ERR((((uint32_t)rssithres2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_LNA_1_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_BT_RF_RX_LNA_1_RSSI_THRES_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rssithres2 <<16));
}
__INLINE uint8_t rfic_wrap_bt_rf_rx_lna_1_rssi_thres_rssi_thres_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_RX_LNA_1_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void rfic_wrap_bt_rf_rx_lna_1_rssi_thres_rssi_thres_1_setf(uint8_t rssithres1)
{
	ASSERT_ERR((((uint32_t)rssithres1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_LNA_1_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_BT_RF_RX_LNA_1_RSSI_THRES_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)rssithres1 <<8));
}
__INLINE uint8_t rfic_wrap_bt_rf_rx_lna_1_rssi_thres_rssi_thres_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_RX_LNA_1_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void rfic_wrap_bt_rf_rx_lna_1_rssi_thres_rssi_thres_0_setf(uint8_t rssithres0)
{
	ASSERT_ERR((((uint32_t)rssithres0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_LNA_1_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_BT_RF_RX_LNA_1_RSSI_THRES_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)rssithres0 <<0));
}

/**
 * @brief BT_RF_RX_PHASE_CORRECTION register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    05:03 RX_PHASE_CORRECTION_2_M   0x0
 *    02:00 RX_PHASE_CORRECTION_1_M   0x0
 * </pre>
 */
#define RFIC_WRAP_BT_RF_RX_PHASE_CORRECTION_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000140)
#define RFIC_WRAP_BT_RF_RX_PHASE_CORRECTION_OFFSET      0x00000140
#define RFIC_WRAP_BT_RF_RX_PHASE_CORRECTION_INDEX       0x00000050
#define RFIC_WRAP_BT_RF_RX_PHASE_CORRECTION_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_bt_rf_rx_phase_correction_get(void)
{
	return REG_PL_RD(RFIC_WRAP_BT_RF_RX_PHASE_CORRECTION_ADDR);
}

__INLINE void rfic_wrap_bt_rf_rx_phase_correction_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_PHASE_CORRECTION_ADDR, value);
}

// field definitions
#define RFIC_WRAP_BT_RF_RX_PHASE_CORRECTION_RX_PHASE_CORRECTION_2_M_MASK    ((uint32_t)0x00000038)
#define RFIC_WRAP_BT_RF_RX_PHASE_CORRECTION_RX_PHASE_CORRECTION_2_M_LSB    3
#define RFIC_WRAP_BT_RF_RX_PHASE_CORRECTION_RX_PHASE_CORRECTION_2_M_WIDTH    ((uint32_t)0x00000003)
#define RFIC_WRAP_BT_RF_RX_PHASE_CORRECTION_RX_PHASE_CORRECTION_1_M_MASK    ((uint32_t)0x00000007)
#define RFIC_WRAP_BT_RF_RX_PHASE_CORRECTION_RX_PHASE_CORRECTION_1_M_LSB    0
#define RFIC_WRAP_BT_RF_RX_PHASE_CORRECTION_RX_PHASE_CORRECTION_1_M_WIDTH    ((uint32_t)0x00000003)

#define RFIC_WRAP_BT_RF_RX_PHASE_CORRECTION_RX_PHASE_CORRECTION_2_M_RST    0x0
#define RFIC_WRAP_BT_RF_RX_PHASE_CORRECTION_RX_PHASE_CORRECTION_1_M_RST    0x0

__INLINE void rfic_wrap_bt_rf_rx_phase_correction_pack(uint8_t rx_phase_correction_2_m, uint8_t rx_phase_correction_1_m)
{
	ASSERT_ERR((((uint32_t)rx_phase_correction_2_m << 3) & ~((uint32_t)0x00000038)) == 0);
	ASSERT_ERR((((uint32_t)rx_phase_correction_1_m << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_PHASE_CORRECTION_ADDR,  ((uint32_t)rx_phase_correction_2_m << 3) |((uint32_t)rx_phase_correction_1_m << 0));
}

__INLINE void rfic_wrap_bt_rf_rx_phase_correction_unpack(uint8_t* rx_phase_correction_2_m, uint8_t* rx_phase_correction_1_m)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_RX_PHASE_CORRECTION_ADDR);

	*rx_phase_correction_2_m = (localVal & ((uint32_t)0x00000038)) >>  3;
	*rx_phase_correction_1_m = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t rfic_wrap_bt_rf_rx_phase_correction_rx_phase_correction_2_m_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_RX_PHASE_CORRECTION_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000038)) >> 3);
}
__INLINE void rfic_wrap_bt_rf_rx_phase_correction_rx_phase_correction_2_m_setf(uint8_t rxphasecorrection2m)
{
	ASSERT_ERR((((uint32_t)rxphasecorrection2m << 3) & ~((uint32_t)0x00000038)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_PHASE_CORRECTION_ADDR, (REG_PL_RD(RFIC_WRAP_BT_RF_RX_PHASE_CORRECTION_ADDR) & ~((uint32_t)0x00000038)) | ((uint32_t)rxphasecorrection2m <<3));
}
__INLINE uint8_t rfic_wrap_bt_rf_rx_phase_correction_rx_phase_correction_1_m_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_RX_PHASE_CORRECTION_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void rfic_wrap_bt_rf_rx_phase_correction_rx_phase_correction_1_m_setf(uint8_t rxphasecorrection1m)
{
	ASSERT_ERR((((uint32_t)rxphasecorrection1m << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_PHASE_CORRECTION_ADDR, (REG_PL_RD(RFIC_WRAP_BT_RF_RX_PHASE_CORRECTION_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)rxphasecorrection1m <<0));
}

/**
 * @brief BT_RF_RX_RSSI_GAIN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    03:00 RSSI_GAIN_SEL             0x0
 * </pre>
 */
#define RFIC_WRAP_BT_RF_RX_RSSI_GAIN_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000144)
#define RFIC_WRAP_BT_RF_RX_RSSI_GAIN_OFFSET      0x00000144
#define RFIC_WRAP_BT_RF_RX_RSSI_GAIN_INDEX       0x00000051
#define RFIC_WRAP_BT_RF_RX_RSSI_GAIN_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_bt_rf_rx_rssi_gain_get(void)
{
	return REG_PL_RD(RFIC_WRAP_BT_RF_RX_RSSI_GAIN_ADDR);
}

__INLINE void rfic_wrap_bt_rf_rx_rssi_gain_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_RSSI_GAIN_ADDR, value);
}

// field definitions
#define RFIC_WRAP_BT_RF_RX_RSSI_GAIN_RSSI_GAIN_SEL_MASK    ((uint32_t)0x0000000F)
#define RFIC_WRAP_BT_RF_RX_RSSI_GAIN_RSSI_GAIN_SEL_LSB    0
#define RFIC_WRAP_BT_RF_RX_RSSI_GAIN_RSSI_GAIN_SEL_WIDTH    ((uint32_t)0x00000004)

#define RFIC_WRAP_BT_RF_RX_RSSI_GAIN_RSSI_GAIN_SEL_RST    0x0

__INLINE uint8_t rfic_wrap_bt_rf_rx_rssi_gain_rssi_gain_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_BT_RF_RX_RSSI_GAIN_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void rfic_wrap_bt_rf_rx_rssi_gain_rssi_gain_sel_setf(uint8_t rssigainsel)
{
	ASSERT_ERR((((uint32_t)rssigainsel << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RFIC_WRAP_BT_RF_RX_RSSI_GAIN_ADDR, (uint32_t)rssigainsel << 0);
}

/**
 * @brief IQDC_TX_CONTROL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    19:18 IQDC_TX_FIR_SCALE_2_M     0x0
 *    17:16 IQDC_TX_FIR_SCALE_1_M     0x0
 *    10:09 IQDC_TX_BYPASS_TYPE       0x0
 *    08    IQDC_TX_BYPASS_MODE       0              
 *    00    IQDC_TX_START             0              
 * </pre>
 */
#define RFIC_WRAP_IQDC_TX_CONTROL_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000180)
#define RFIC_WRAP_IQDC_TX_CONTROL_OFFSET      0x00000180
#define RFIC_WRAP_IQDC_TX_CONTROL_INDEX       0x00000060
#define RFIC_WRAP_IQDC_TX_CONTROL_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_iqdc_tx_control_get(void)
{
	return REG_PL_RD(RFIC_WRAP_IQDC_TX_CONTROL_ADDR);
}

__INLINE void rfic_wrap_iqdc_tx_control_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_IQDC_TX_CONTROL_ADDR, value);
}

// field definitions
#define RFIC_WRAP_IQDC_TX_CONTROL_IQDC_TX_FIR_SCALE_2_M_MASK    ((uint32_t)0x000C0000)
#define RFIC_WRAP_IQDC_TX_CONTROL_IQDC_TX_FIR_SCALE_2_M_LSB    18
#define RFIC_WRAP_IQDC_TX_CONTROL_IQDC_TX_FIR_SCALE_2_M_WIDTH    ((uint32_t)0x00000002)
#define RFIC_WRAP_IQDC_TX_CONTROL_IQDC_TX_FIR_SCALE_1_M_MASK    ((uint32_t)0x00030000)
#define RFIC_WRAP_IQDC_TX_CONTROL_IQDC_TX_FIR_SCALE_1_M_LSB    16
#define RFIC_WRAP_IQDC_TX_CONTROL_IQDC_TX_FIR_SCALE_1_M_WIDTH    ((uint32_t)0x00000002)
#define RFIC_WRAP_IQDC_TX_CONTROL_IQDC_TX_BYPASS_TYPE_MASK    ((uint32_t)0x00000600)
#define RFIC_WRAP_IQDC_TX_CONTROL_IQDC_TX_BYPASS_TYPE_LSB    9
#define RFIC_WRAP_IQDC_TX_CONTROL_IQDC_TX_BYPASS_TYPE_WIDTH    ((uint32_t)0x00000002)
#define RFIC_WRAP_IQDC_TX_CONTROL_IQDC_TX_BYPASS_MODE_BIT    ((uint32_t)0x00000100)
#define RFIC_WRAP_IQDC_TX_CONTROL_IQDC_TX_BYPASS_MODE_POS    8
#define RFIC_WRAP_IQDC_TX_CONTROL_IQDC_TX_START_BIT    ((uint32_t)0x00000001)
#define RFIC_WRAP_IQDC_TX_CONTROL_IQDC_TX_START_POS    0

#define RFIC_WRAP_IQDC_TX_CONTROL_IQDC_TX_FIR_SCALE_2_M_RST    0x0
#define RFIC_WRAP_IQDC_TX_CONTROL_IQDC_TX_FIR_SCALE_1_M_RST    0x0
#define RFIC_WRAP_IQDC_TX_CONTROL_IQDC_TX_BYPASS_TYPE_RST    0x0
#define RFIC_WRAP_IQDC_TX_CONTROL_IQDC_TX_BYPASS_MODE_RST    0x0
#define RFIC_WRAP_IQDC_TX_CONTROL_IQDC_TX_START_RST    0x0

__INLINE void rfic_wrap_iqdc_tx_control_pack(uint8_t iqdc_tx_fir_scale_2_m, uint8_t iqdc_tx_fir_scale_1_m, uint8_t iqdc_tx_bypass_type, uint8_t iqdc_tx_bypass_mode, uint8_t iqdc_tx_start)
{
	ASSERT_ERR((((uint32_t)iqdc_tx_fir_scale_2_m << 18) & ~((uint32_t)0x000C0000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_tx_fir_scale_1_m << 16) & ~((uint32_t)0x00030000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_tx_bypass_type << 9) & ~((uint32_t)0x00000600)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_tx_bypass_mode << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_tx_start << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_CONTROL_ADDR,  ((uint32_t)iqdc_tx_fir_scale_2_m << 18) |((uint32_t)iqdc_tx_fir_scale_1_m << 16) |((uint32_t)iqdc_tx_bypass_type << 9) |((uint32_t)iqdc_tx_bypass_mode << 8) |((uint32_t)iqdc_tx_start << 0));
}

__INLINE void rfic_wrap_iqdc_tx_control_unpack(uint8_t* iqdc_tx_fir_scale_2_m, uint8_t* iqdc_tx_fir_scale_1_m, uint8_t* iqdc_tx_bypass_type, uint8_t* iqdc_tx_bypass_mode, uint8_t* iqdc_tx_start)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_CONTROL_ADDR);

	*iqdc_tx_fir_scale_2_m = (localVal & ((uint32_t)0x000C0000)) >>  18;
	*iqdc_tx_fir_scale_1_m = (localVal & ((uint32_t)0x00030000)) >>  16;
	*iqdc_tx_bypass_type = (localVal & ((uint32_t)0x00000600)) >>  9;
	*iqdc_tx_bypass_mode = (localVal & ((uint32_t)0x00000100)) >>  8;
	*iqdc_tx_start = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t rfic_wrap_iqdc_tx_control_iqdc_tx_fir_scale_2_m_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_CONTROL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000C0000)) >> 18);
}
__INLINE void rfic_wrap_iqdc_tx_control_iqdc_tx_fir_scale_2_m_setf(uint8_t iqdctxfirscale2m)
{
	ASSERT_ERR((((uint32_t)iqdctxfirscale2m << 18) & ~((uint32_t)0x000C0000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_CONTROL_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_TX_CONTROL_ADDR) & ~((uint32_t)0x000C0000)) | ((uint32_t)iqdctxfirscale2m <<18));
}
__INLINE uint8_t rfic_wrap_iqdc_tx_control_iqdc_tx_fir_scale_1_m_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_CONTROL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00030000)) >> 16);
}
__INLINE void rfic_wrap_iqdc_tx_control_iqdc_tx_fir_scale_1_m_setf(uint8_t iqdctxfirscale1m)
{
	ASSERT_ERR((((uint32_t)iqdctxfirscale1m << 16) & ~((uint32_t)0x00030000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_CONTROL_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_TX_CONTROL_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)iqdctxfirscale1m <<16));
}
__INLINE uint8_t rfic_wrap_iqdc_tx_control_iqdc_tx_bypass_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_CONTROL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000600)) >> 9);
}
__INLINE void rfic_wrap_iqdc_tx_control_iqdc_tx_bypass_type_setf(uint8_t iqdctxbypasstype)
{
	ASSERT_ERR((((uint32_t)iqdctxbypasstype << 9) & ~((uint32_t)0x00000600)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_CONTROL_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_TX_CONTROL_ADDR) & ~((uint32_t)0x00000600)) | ((uint32_t)iqdctxbypasstype <<9));
}
__INLINE uint8_t rfic_wrap_iqdc_tx_control_iqdc_tx_bypass_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_CONTROL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void rfic_wrap_iqdc_tx_control_iqdc_tx_bypass_mode_setf(uint8_t iqdctxbypassmode)
{
	ASSERT_ERR((((uint32_t)iqdctxbypassmode << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_CONTROL_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_TX_CONTROL_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)iqdctxbypassmode <<8));
}
__INLINE void rfic_wrap_iqdc_tx_control_iqdc_tx_start_setf(uint8_t iqdctxstart)
{
	ASSERT_ERR((((uint32_t)iqdctxstart << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_CONTROL_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_TX_CONTROL_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)iqdctxstart <<0));
}

/**
 * @brief IQDC_TX_1_M_GAIN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 IQDC_TX_PHASE_GAIN        0x0
 *    10:00 IQDC_TX_AMP_GAIN          0x0
 * </pre>
 */
#define RFIC_WRAP_IQDC_TX_1_M_GAIN_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000184)
#define RFIC_WRAP_IQDC_TX_1_M_GAIN_OFFSET      0x00000184
#define RFIC_WRAP_IQDC_TX_1_M_GAIN_INDEX       0x00000061
#define RFIC_WRAP_IQDC_TX_1_M_GAIN_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_iqdc_tx_1_m_gain_get(void)
{
	return REG_PL_RD(RFIC_WRAP_IQDC_TX_1_M_GAIN_ADDR);
}

__INLINE void rfic_wrap_iqdc_tx_1_m_gain_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_IQDC_TX_1_M_GAIN_ADDR, value);
}

// field definitions
#define RFIC_WRAP_IQDC_TX_1_M_GAIN_IQDC_TX_PHASE_GAIN_MASK    ((uint32_t)0x0FFF0000)
#define RFIC_WRAP_IQDC_TX_1_M_GAIN_IQDC_TX_PHASE_GAIN_LSB    16
#define RFIC_WRAP_IQDC_TX_1_M_GAIN_IQDC_TX_PHASE_GAIN_WIDTH    ((uint32_t)0x0000000C)
#define RFIC_WRAP_IQDC_TX_1_M_GAIN_IQDC_TX_AMP_GAIN_MASK    ((uint32_t)0x000007FF)
#define RFIC_WRAP_IQDC_TX_1_M_GAIN_IQDC_TX_AMP_GAIN_LSB    0
#define RFIC_WRAP_IQDC_TX_1_M_GAIN_IQDC_TX_AMP_GAIN_WIDTH    ((uint32_t)0x0000000B)

#define RFIC_WRAP_IQDC_TX_1_M_GAIN_IQDC_TX_PHASE_GAIN_RST    0x0
#define RFIC_WRAP_IQDC_TX_1_M_GAIN_IQDC_TX_AMP_GAIN_RST    0x0

__INLINE void rfic_wrap_iqdc_tx_1_m_gain_pack(uint16_t iqdc_tx_phase_gain, uint16_t iqdc_tx_amp_gain)
{
	ASSERT_ERR((((uint32_t)iqdc_tx_phase_gain << 16) & ~((uint32_t)0x0FFF0000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_tx_amp_gain << 0) & ~((uint32_t)0x000007FF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_1_M_GAIN_ADDR,  ((uint32_t)iqdc_tx_phase_gain << 16) |((uint32_t)iqdc_tx_amp_gain << 0));
}

__INLINE void rfic_wrap_iqdc_tx_1_m_gain_unpack(uint16_t* iqdc_tx_phase_gain, uint16_t* iqdc_tx_amp_gain)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_1_M_GAIN_ADDR);

	*iqdc_tx_phase_gain = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*iqdc_tx_amp_gain = (localVal & ((uint32_t)0x000007FF)) >>  0;
}

__INLINE uint16_t rfic_wrap_iqdc_tx_1_m_gain_iqdc_tx_phase_gain_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_1_M_GAIN_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE void rfic_wrap_iqdc_tx_1_m_gain_iqdc_tx_phase_gain_setf(uint16_t iqdctxphasegain)
{
	ASSERT_ERR((((uint32_t)iqdctxphasegain << 16) & ~((uint32_t)0x0FFF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_1_M_GAIN_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_TX_1_M_GAIN_ADDR) & ~((uint32_t)0x0FFF0000)) | ((uint32_t)iqdctxphasegain <<16));
}
__INLINE uint16_t rfic_wrap_iqdc_tx_1_m_gain_iqdc_tx_amp_gain_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_1_M_GAIN_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000007FF)) >> 0);
}
__INLINE void rfic_wrap_iqdc_tx_1_m_gain_iqdc_tx_amp_gain_setf(uint16_t iqdctxampgain)
{
	ASSERT_ERR((((uint32_t)iqdctxampgain << 0) & ~((uint32_t)0x000007FF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_1_M_GAIN_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_TX_1_M_GAIN_ADDR) & ~((uint32_t)0x000007FF)) | ((uint32_t)iqdctxampgain <<0));
}

/**
 * @brief IQDC_TX_1_M_DC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 IQDC_TX_DCQ               0x0
 *    11:00 IQDC_TX_DCI               0x0
 * </pre>
 */
#define RFIC_WRAP_IQDC_TX_1_M_DC_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000188)
#define RFIC_WRAP_IQDC_TX_1_M_DC_OFFSET      0x00000188
#define RFIC_WRAP_IQDC_TX_1_M_DC_INDEX       0x00000062
#define RFIC_WRAP_IQDC_TX_1_M_DC_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_iqdc_tx_1_m_dc_get(void)
{
	return REG_PL_RD(RFIC_WRAP_IQDC_TX_1_M_DC_ADDR);
}

__INLINE void rfic_wrap_iqdc_tx_1_m_dc_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_IQDC_TX_1_M_DC_ADDR, value);
}

// field definitions
#define RFIC_WRAP_IQDC_TX_1_M_DC_IQDC_TX_DCQ_MASK    ((uint32_t)0x0FFF0000)
#define RFIC_WRAP_IQDC_TX_1_M_DC_IQDC_TX_DCQ_LSB    16
#define RFIC_WRAP_IQDC_TX_1_M_DC_IQDC_TX_DCQ_WIDTH    ((uint32_t)0x0000000C)
#define RFIC_WRAP_IQDC_TX_1_M_DC_IQDC_TX_DCI_MASK    ((uint32_t)0x00000FFF)
#define RFIC_WRAP_IQDC_TX_1_M_DC_IQDC_TX_DCI_LSB    0
#define RFIC_WRAP_IQDC_TX_1_M_DC_IQDC_TX_DCI_WIDTH    ((uint32_t)0x0000000C)

#define RFIC_WRAP_IQDC_TX_1_M_DC_IQDC_TX_DCQ_RST    0x0
#define RFIC_WRAP_IQDC_TX_1_M_DC_IQDC_TX_DCI_RST    0x0

__INLINE void rfic_wrap_iqdc_tx_1_m_dc_pack(uint16_t iqdc_tx_dcq, uint16_t iqdc_tx_dci)
{
	ASSERT_ERR((((uint32_t)iqdc_tx_dcq << 16) & ~((uint32_t)0x0FFF0000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_tx_dci << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_1_M_DC_ADDR,  ((uint32_t)iqdc_tx_dcq << 16) |((uint32_t)iqdc_tx_dci << 0));
}

__INLINE void rfic_wrap_iqdc_tx_1_m_dc_unpack(uint16_t* iqdc_tx_dcq, uint16_t* iqdc_tx_dci)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_1_M_DC_ADDR);

	*iqdc_tx_dcq = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*iqdc_tx_dci = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t rfic_wrap_iqdc_tx_1_m_dc_iqdc_tx_dcq_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_1_M_DC_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE void rfic_wrap_iqdc_tx_1_m_dc_iqdc_tx_dcq_setf(uint16_t iqdctxdcq)
{
	ASSERT_ERR((((uint32_t)iqdctxdcq << 16) & ~((uint32_t)0x0FFF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_1_M_DC_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_TX_1_M_DC_ADDR) & ~((uint32_t)0x0FFF0000)) | ((uint32_t)iqdctxdcq <<16));
}
__INLINE uint16_t rfic_wrap_iqdc_tx_1_m_dc_iqdc_tx_dci_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_1_M_DC_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}
__INLINE void rfic_wrap_iqdc_tx_1_m_dc_iqdc_tx_dci_setf(uint16_t iqdctxdci)
{
	ASSERT_ERR((((uint32_t)iqdctxdci << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_1_M_DC_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_TX_1_M_DC_ADDR) & ~((uint32_t)0x00000FFF)) | ((uint32_t)iqdctxdci <<0));
}

/**
 * @brief IQDC_TX_1_M_COEFF_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:23 IQDC_TX_FIR_COEFF_2       0x0
 *    20:12 IQDC_TX_FIR_COEFF_1       0x0
 *    08:00 IQDC_TX_FIR_COEFF_0       0x0
 * </pre>
 */
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_0_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x0000018C)
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_0_OFFSET      0x0000018C
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_0_INDEX       0x00000063
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_0_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_iqdc_tx_1_m_coeff_0_get(void)
{
	return REG_PL_RD(RFIC_WRAP_IQDC_TX_1_M_COEFF_0_ADDR);
}

__INLINE void rfic_wrap_iqdc_tx_1_m_coeff_0_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_IQDC_TX_1_M_COEFF_0_ADDR, value);
}

// field definitions
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_0_IQDC_TX_FIR_COEFF_2_MASK    ((uint32_t)0xFF800000)
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_0_IQDC_TX_FIR_COEFF_2_LSB    23
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_0_IQDC_TX_FIR_COEFF_2_WIDTH    ((uint32_t)0x00000009)
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_0_IQDC_TX_FIR_COEFF_1_MASK    ((uint32_t)0x001FF000)
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_0_IQDC_TX_FIR_COEFF_1_LSB    12
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_0_IQDC_TX_FIR_COEFF_1_WIDTH    ((uint32_t)0x00000009)
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_0_IQDC_TX_FIR_COEFF_0_MASK    ((uint32_t)0x000001FF)
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_0_IQDC_TX_FIR_COEFF_0_LSB    0
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_0_IQDC_TX_FIR_COEFF_0_WIDTH    ((uint32_t)0x00000009)

#define RFIC_WRAP_IQDC_TX_1_M_COEFF_0_IQDC_TX_FIR_COEFF_2_RST    0x0
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_0_IQDC_TX_FIR_COEFF_1_RST    0x0
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_0_IQDC_TX_FIR_COEFF_0_RST    0x0

__INLINE void rfic_wrap_iqdc_tx_1_m_coeff_0_pack(uint16_t iqdc_tx_fir_coeff_2, uint16_t iqdc_tx_fir_coeff_1, uint16_t iqdc_tx_fir_coeff_0)
{
	ASSERT_ERR((((uint32_t)iqdc_tx_fir_coeff_2 << 23) & ~((uint32_t)0xFF800000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_tx_fir_coeff_1 << 12) & ~((uint32_t)0x001FF000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_tx_fir_coeff_0 << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_1_M_COEFF_0_ADDR,  ((uint32_t)iqdc_tx_fir_coeff_2 << 23) |((uint32_t)iqdc_tx_fir_coeff_1 << 12) |((uint32_t)iqdc_tx_fir_coeff_0 << 0));
}

__INLINE void rfic_wrap_iqdc_tx_1_m_coeff_0_unpack(uint16_t* iqdc_tx_fir_coeff_2, uint16_t* iqdc_tx_fir_coeff_1, uint16_t* iqdc_tx_fir_coeff_0)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_1_M_COEFF_0_ADDR);

	*iqdc_tx_fir_coeff_2 = (localVal & ((uint32_t)0xFF800000)) >>  23;
	*iqdc_tx_fir_coeff_1 = (localVal & ((uint32_t)0x001FF000)) >>  12;
	*iqdc_tx_fir_coeff_0 = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint16_t rfic_wrap_iqdc_tx_1_m_coeff_0_iqdc_tx_fir_coeff_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_1_M_COEFF_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFF800000)) >> 23);
}
__INLINE void rfic_wrap_iqdc_tx_1_m_coeff_0_iqdc_tx_fir_coeff_2_setf(uint16_t iqdctxfircoeff2)
{
	ASSERT_ERR((((uint32_t)iqdctxfircoeff2 << 23) & ~((uint32_t)0xFF800000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_1_M_COEFF_0_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_TX_1_M_COEFF_0_ADDR) & ~((uint32_t)0xFF800000)) | ((uint32_t)iqdctxfircoeff2 <<23));
}
__INLINE uint16_t rfic_wrap_iqdc_tx_1_m_coeff_0_iqdc_tx_fir_coeff_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_1_M_COEFF_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x001FF000)) >> 12);
}
__INLINE void rfic_wrap_iqdc_tx_1_m_coeff_0_iqdc_tx_fir_coeff_1_setf(uint16_t iqdctxfircoeff1)
{
	ASSERT_ERR((((uint32_t)iqdctxfircoeff1 << 12) & ~((uint32_t)0x001FF000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_1_M_COEFF_0_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_TX_1_M_COEFF_0_ADDR) & ~((uint32_t)0x001FF000)) | ((uint32_t)iqdctxfircoeff1 <<12));
}
__INLINE uint16_t rfic_wrap_iqdc_tx_1_m_coeff_0_iqdc_tx_fir_coeff_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_1_M_COEFF_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}
__INLINE void rfic_wrap_iqdc_tx_1_m_coeff_0_iqdc_tx_fir_coeff_0_setf(uint16_t iqdctxfircoeff0)
{
	ASSERT_ERR((((uint32_t)iqdctxfircoeff0 << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_1_M_COEFF_0_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_TX_1_M_COEFF_0_ADDR) & ~((uint32_t)0x000001FF)) | ((uint32_t)iqdctxfircoeff0 <<0));
}

/**
 * @brief IQDC_TX_1_M_COEFF_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:23 IQDC_TX_FIR_COEFF_5       0x0
 *    20:12 IQDC_TX_FIR_COEFF_4       0x0
 *    08:00 IQDC_TX_FIR_COEFF_3       0x0
 * </pre>
 */
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_1_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000190)
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_1_OFFSET      0x00000190
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_1_INDEX       0x00000064
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_1_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_iqdc_tx_1_m_coeff_1_get(void)
{
	return REG_PL_RD(RFIC_WRAP_IQDC_TX_1_M_COEFF_1_ADDR);
}

__INLINE void rfic_wrap_iqdc_tx_1_m_coeff_1_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_IQDC_TX_1_M_COEFF_1_ADDR, value);
}

// field definitions
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_1_IQDC_TX_FIR_COEFF_5_MASK    ((uint32_t)0xFF800000)
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_1_IQDC_TX_FIR_COEFF_5_LSB    23
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_1_IQDC_TX_FIR_COEFF_5_WIDTH    ((uint32_t)0x00000009)
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_1_IQDC_TX_FIR_COEFF_4_MASK    ((uint32_t)0x001FF000)
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_1_IQDC_TX_FIR_COEFF_4_LSB    12
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_1_IQDC_TX_FIR_COEFF_4_WIDTH    ((uint32_t)0x00000009)
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_1_IQDC_TX_FIR_COEFF_3_MASK    ((uint32_t)0x000001FF)
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_1_IQDC_TX_FIR_COEFF_3_LSB    0
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_1_IQDC_TX_FIR_COEFF_3_WIDTH    ((uint32_t)0x00000009)

#define RFIC_WRAP_IQDC_TX_1_M_COEFF_1_IQDC_TX_FIR_COEFF_5_RST    0x0
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_1_IQDC_TX_FIR_COEFF_4_RST    0x0
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_1_IQDC_TX_FIR_COEFF_3_RST    0x0

__INLINE void rfic_wrap_iqdc_tx_1_m_coeff_1_pack(uint16_t iqdc_tx_fir_coeff_5, uint16_t iqdc_tx_fir_coeff_4, uint16_t iqdc_tx_fir_coeff_3)
{
	ASSERT_ERR((((uint32_t)iqdc_tx_fir_coeff_5 << 23) & ~((uint32_t)0xFF800000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_tx_fir_coeff_4 << 12) & ~((uint32_t)0x001FF000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_tx_fir_coeff_3 << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_1_M_COEFF_1_ADDR,  ((uint32_t)iqdc_tx_fir_coeff_5 << 23) |((uint32_t)iqdc_tx_fir_coeff_4 << 12) |((uint32_t)iqdc_tx_fir_coeff_3 << 0));
}

__INLINE void rfic_wrap_iqdc_tx_1_m_coeff_1_unpack(uint16_t* iqdc_tx_fir_coeff_5, uint16_t* iqdc_tx_fir_coeff_4, uint16_t* iqdc_tx_fir_coeff_3)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_1_M_COEFF_1_ADDR);

	*iqdc_tx_fir_coeff_5 = (localVal & ((uint32_t)0xFF800000)) >>  23;
	*iqdc_tx_fir_coeff_4 = (localVal & ((uint32_t)0x001FF000)) >>  12;
	*iqdc_tx_fir_coeff_3 = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint16_t rfic_wrap_iqdc_tx_1_m_coeff_1_iqdc_tx_fir_coeff_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_1_M_COEFF_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFF800000)) >> 23);
}
__INLINE void rfic_wrap_iqdc_tx_1_m_coeff_1_iqdc_tx_fir_coeff_5_setf(uint16_t iqdctxfircoeff5)
{
	ASSERT_ERR((((uint32_t)iqdctxfircoeff5 << 23) & ~((uint32_t)0xFF800000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_1_M_COEFF_1_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_TX_1_M_COEFF_1_ADDR) & ~((uint32_t)0xFF800000)) | ((uint32_t)iqdctxfircoeff5 <<23));
}
__INLINE uint16_t rfic_wrap_iqdc_tx_1_m_coeff_1_iqdc_tx_fir_coeff_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_1_M_COEFF_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x001FF000)) >> 12);
}
__INLINE void rfic_wrap_iqdc_tx_1_m_coeff_1_iqdc_tx_fir_coeff_4_setf(uint16_t iqdctxfircoeff4)
{
	ASSERT_ERR((((uint32_t)iqdctxfircoeff4 << 12) & ~((uint32_t)0x001FF000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_1_M_COEFF_1_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_TX_1_M_COEFF_1_ADDR) & ~((uint32_t)0x001FF000)) | ((uint32_t)iqdctxfircoeff4 <<12));
}
__INLINE uint16_t rfic_wrap_iqdc_tx_1_m_coeff_1_iqdc_tx_fir_coeff_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_1_M_COEFF_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}
__INLINE void rfic_wrap_iqdc_tx_1_m_coeff_1_iqdc_tx_fir_coeff_3_setf(uint16_t iqdctxfircoeff3)
{
	ASSERT_ERR((((uint32_t)iqdctxfircoeff3 << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_1_M_COEFF_1_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_TX_1_M_COEFF_1_ADDR) & ~((uint32_t)0x000001FF)) | ((uint32_t)iqdctxfircoeff3 <<0));
}

/**
 * @brief IQDC_TX_1_M_COEFF_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:23 IQDC_TX_FIR_COEFF_8       0x0
 *    20:12 IQDC_TX_FIR_COEFF_7       0x0
 *    08:00 IQDC_TX_FIR_COEFF_6       0x0
 * </pre>
 */
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_2_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000194)
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_2_OFFSET      0x00000194
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_2_INDEX       0x00000065
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_2_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_iqdc_tx_1_m_coeff_2_get(void)
{
	return REG_PL_RD(RFIC_WRAP_IQDC_TX_1_M_COEFF_2_ADDR);
}

__INLINE void rfic_wrap_iqdc_tx_1_m_coeff_2_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_IQDC_TX_1_M_COEFF_2_ADDR, value);
}

// field definitions
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_2_IQDC_TX_FIR_COEFF_8_MASK    ((uint32_t)0xFF800000)
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_2_IQDC_TX_FIR_COEFF_8_LSB    23
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_2_IQDC_TX_FIR_COEFF_8_WIDTH    ((uint32_t)0x00000009)
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_2_IQDC_TX_FIR_COEFF_7_MASK    ((uint32_t)0x001FF000)
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_2_IQDC_TX_FIR_COEFF_7_LSB    12
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_2_IQDC_TX_FIR_COEFF_7_WIDTH    ((uint32_t)0x00000009)
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_2_IQDC_TX_FIR_COEFF_6_MASK    ((uint32_t)0x000001FF)
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_2_IQDC_TX_FIR_COEFF_6_LSB    0
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_2_IQDC_TX_FIR_COEFF_6_WIDTH    ((uint32_t)0x00000009)

#define RFIC_WRAP_IQDC_TX_1_M_COEFF_2_IQDC_TX_FIR_COEFF_8_RST    0x0
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_2_IQDC_TX_FIR_COEFF_7_RST    0x0
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_2_IQDC_TX_FIR_COEFF_6_RST    0x0

__INLINE void rfic_wrap_iqdc_tx_1_m_coeff_2_pack(uint16_t iqdc_tx_fir_coeff_8, uint16_t iqdc_tx_fir_coeff_7, uint16_t iqdc_tx_fir_coeff_6)
{
	ASSERT_ERR((((uint32_t)iqdc_tx_fir_coeff_8 << 23) & ~((uint32_t)0xFF800000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_tx_fir_coeff_7 << 12) & ~((uint32_t)0x001FF000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_tx_fir_coeff_6 << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_1_M_COEFF_2_ADDR,  ((uint32_t)iqdc_tx_fir_coeff_8 << 23) |((uint32_t)iqdc_tx_fir_coeff_7 << 12) |((uint32_t)iqdc_tx_fir_coeff_6 << 0));
}

__INLINE void rfic_wrap_iqdc_tx_1_m_coeff_2_unpack(uint16_t* iqdc_tx_fir_coeff_8, uint16_t* iqdc_tx_fir_coeff_7, uint16_t* iqdc_tx_fir_coeff_6)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_1_M_COEFF_2_ADDR);

	*iqdc_tx_fir_coeff_8 = (localVal & ((uint32_t)0xFF800000)) >>  23;
	*iqdc_tx_fir_coeff_7 = (localVal & ((uint32_t)0x001FF000)) >>  12;
	*iqdc_tx_fir_coeff_6 = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint16_t rfic_wrap_iqdc_tx_1_m_coeff_2_iqdc_tx_fir_coeff_8_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_1_M_COEFF_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFF800000)) >> 23);
}
__INLINE void rfic_wrap_iqdc_tx_1_m_coeff_2_iqdc_tx_fir_coeff_8_setf(uint16_t iqdctxfircoeff8)
{
	ASSERT_ERR((((uint32_t)iqdctxfircoeff8 << 23) & ~((uint32_t)0xFF800000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_1_M_COEFF_2_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_TX_1_M_COEFF_2_ADDR) & ~((uint32_t)0xFF800000)) | ((uint32_t)iqdctxfircoeff8 <<23));
}
__INLINE uint16_t rfic_wrap_iqdc_tx_1_m_coeff_2_iqdc_tx_fir_coeff_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_1_M_COEFF_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x001FF000)) >> 12);
}
__INLINE void rfic_wrap_iqdc_tx_1_m_coeff_2_iqdc_tx_fir_coeff_7_setf(uint16_t iqdctxfircoeff7)
{
	ASSERT_ERR((((uint32_t)iqdctxfircoeff7 << 12) & ~((uint32_t)0x001FF000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_1_M_COEFF_2_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_TX_1_M_COEFF_2_ADDR) & ~((uint32_t)0x001FF000)) | ((uint32_t)iqdctxfircoeff7 <<12));
}
__INLINE uint16_t rfic_wrap_iqdc_tx_1_m_coeff_2_iqdc_tx_fir_coeff_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_1_M_COEFF_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}
__INLINE void rfic_wrap_iqdc_tx_1_m_coeff_2_iqdc_tx_fir_coeff_6_setf(uint16_t iqdctxfircoeff6)
{
	ASSERT_ERR((((uint32_t)iqdctxfircoeff6 << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_1_M_COEFF_2_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_TX_1_M_COEFF_2_ADDR) & ~((uint32_t)0x000001FF)) | ((uint32_t)iqdctxfircoeff6 <<0));
}

/**
 * @brief IQDC_TX_1_M_COEFF_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    20:12 IQDC_TX_FIR_COEFF_10      0x0
 *    08:00 IQDC_TX_FIR_COEFF_9       0x0
 * </pre>
 */
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_3_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000198)
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_3_OFFSET      0x00000198
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_3_INDEX       0x00000066
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_3_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_iqdc_tx_1_m_coeff_3_get(void)
{
	return REG_PL_RD(RFIC_WRAP_IQDC_TX_1_M_COEFF_3_ADDR);
}

__INLINE void rfic_wrap_iqdc_tx_1_m_coeff_3_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_IQDC_TX_1_M_COEFF_3_ADDR, value);
}

// field definitions
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_3_IQDC_TX_FIR_COEFF_10_MASK    ((uint32_t)0x001FF000)
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_3_IQDC_TX_FIR_COEFF_10_LSB    12
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_3_IQDC_TX_FIR_COEFF_10_WIDTH    ((uint32_t)0x00000009)
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_3_IQDC_TX_FIR_COEFF_9_MASK    ((uint32_t)0x000001FF)
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_3_IQDC_TX_FIR_COEFF_9_LSB    0
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_3_IQDC_TX_FIR_COEFF_9_WIDTH    ((uint32_t)0x00000009)

#define RFIC_WRAP_IQDC_TX_1_M_COEFF_3_IQDC_TX_FIR_COEFF_10_RST    0x0
#define RFIC_WRAP_IQDC_TX_1_M_COEFF_3_IQDC_TX_FIR_COEFF_9_RST    0x0

__INLINE void rfic_wrap_iqdc_tx_1_m_coeff_3_pack(uint16_t iqdc_tx_fir_coeff_10, uint16_t iqdc_tx_fir_coeff_9)
{
	ASSERT_ERR((((uint32_t)iqdc_tx_fir_coeff_10 << 12) & ~((uint32_t)0x001FF000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_tx_fir_coeff_9 << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_1_M_COEFF_3_ADDR,  ((uint32_t)iqdc_tx_fir_coeff_10 << 12) |((uint32_t)iqdc_tx_fir_coeff_9 << 0));
}

__INLINE void rfic_wrap_iqdc_tx_1_m_coeff_3_unpack(uint16_t* iqdc_tx_fir_coeff_10, uint16_t* iqdc_tx_fir_coeff_9)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_1_M_COEFF_3_ADDR);

	*iqdc_tx_fir_coeff_10 = (localVal & ((uint32_t)0x001FF000)) >>  12;
	*iqdc_tx_fir_coeff_9 = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint16_t rfic_wrap_iqdc_tx_1_m_coeff_3_iqdc_tx_fir_coeff_10_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_1_M_COEFF_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x001FF000)) >> 12);
}
__INLINE void rfic_wrap_iqdc_tx_1_m_coeff_3_iqdc_tx_fir_coeff_10_setf(uint16_t iqdctxfircoeff10)
{
	ASSERT_ERR((((uint32_t)iqdctxfircoeff10 << 12) & ~((uint32_t)0x001FF000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_1_M_COEFF_3_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_TX_1_M_COEFF_3_ADDR) & ~((uint32_t)0x001FF000)) | ((uint32_t)iqdctxfircoeff10 <<12));
}
__INLINE uint16_t rfic_wrap_iqdc_tx_1_m_coeff_3_iqdc_tx_fir_coeff_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_1_M_COEFF_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}
__INLINE void rfic_wrap_iqdc_tx_1_m_coeff_3_iqdc_tx_fir_coeff_9_setf(uint16_t iqdctxfircoeff9)
{
	ASSERT_ERR((((uint32_t)iqdctxfircoeff9 << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_1_M_COEFF_3_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_TX_1_M_COEFF_3_ADDR) & ~((uint32_t)0x000001FF)) | ((uint32_t)iqdctxfircoeff9 <<0));
}

/**
 * @brief IQDC_TX_2_M_GAIN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26:16 IQDC_TX_PHASE_GAIN        0x0
 *    10:00 IQDC_TX_AMP_GAIN          0x0
 * </pre>
 */
#define RFIC_WRAP_IQDC_TX_2_M_GAIN_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x0000019C)
#define RFIC_WRAP_IQDC_TX_2_M_GAIN_OFFSET      0x0000019C
#define RFIC_WRAP_IQDC_TX_2_M_GAIN_INDEX       0x00000067
#define RFIC_WRAP_IQDC_TX_2_M_GAIN_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_iqdc_tx_2_m_gain_get(void)
{
	return REG_PL_RD(RFIC_WRAP_IQDC_TX_2_M_GAIN_ADDR);
}

__INLINE void rfic_wrap_iqdc_tx_2_m_gain_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_IQDC_TX_2_M_GAIN_ADDR, value);
}

// field definitions
#define RFIC_WRAP_IQDC_TX_2_M_GAIN_IQDC_TX_PHASE_GAIN_MASK    ((uint32_t)0x07FF0000)
#define RFIC_WRAP_IQDC_TX_2_M_GAIN_IQDC_TX_PHASE_GAIN_LSB    16
#define RFIC_WRAP_IQDC_TX_2_M_GAIN_IQDC_TX_PHASE_GAIN_WIDTH    ((uint32_t)0x0000000B)
#define RFIC_WRAP_IQDC_TX_2_M_GAIN_IQDC_TX_AMP_GAIN_MASK    ((uint32_t)0x000007FF)
#define RFIC_WRAP_IQDC_TX_2_M_GAIN_IQDC_TX_AMP_GAIN_LSB    0
#define RFIC_WRAP_IQDC_TX_2_M_GAIN_IQDC_TX_AMP_GAIN_WIDTH    ((uint32_t)0x0000000B)

#define RFIC_WRAP_IQDC_TX_2_M_GAIN_IQDC_TX_PHASE_GAIN_RST    0x0
#define RFIC_WRAP_IQDC_TX_2_M_GAIN_IQDC_TX_AMP_GAIN_RST    0x0

__INLINE void rfic_wrap_iqdc_tx_2_m_gain_pack(uint16_t iqdc_tx_phase_gain, uint16_t iqdc_tx_amp_gain)
{
	ASSERT_ERR((((uint32_t)iqdc_tx_phase_gain << 16) & ~((uint32_t)0x07FF0000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_tx_amp_gain << 0) & ~((uint32_t)0x000007FF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_2_M_GAIN_ADDR,  ((uint32_t)iqdc_tx_phase_gain << 16) |((uint32_t)iqdc_tx_amp_gain << 0));
}

__INLINE void rfic_wrap_iqdc_tx_2_m_gain_unpack(uint16_t* iqdc_tx_phase_gain, uint16_t* iqdc_tx_amp_gain)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_2_M_GAIN_ADDR);

	*iqdc_tx_phase_gain = (localVal & ((uint32_t)0x07FF0000)) >>  16;
	*iqdc_tx_amp_gain = (localVal & ((uint32_t)0x000007FF)) >>  0;
}

__INLINE uint16_t rfic_wrap_iqdc_tx_2_m_gain_iqdc_tx_phase_gain_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_2_M_GAIN_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x07FF0000)) >> 16);
}
__INLINE void rfic_wrap_iqdc_tx_2_m_gain_iqdc_tx_phase_gain_setf(uint16_t iqdctxphasegain)
{
	ASSERT_ERR((((uint32_t)iqdctxphasegain << 16) & ~((uint32_t)0x07FF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_2_M_GAIN_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_TX_2_M_GAIN_ADDR) & ~((uint32_t)0x07FF0000)) | ((uint32_t)iqdctxphasegain <<16));
}
__INLINE uint16_t rfic_wrap_iqdc_tx_2_m_gain_iqdc_tx_amp_gain_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_2_M_GAIN_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000007FF)) >> 0);
}
__INLINE void rfic_wrap_iqdc_tx_2_m_gain_iqdc_tx_amp_gain_setf(uint16_t iqdctxampgain)
{
	ASSERT_ERR((((uint32_t)iqdctxampgain << 0) & ~((uint32_t)0x000007FF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_2_M_GAIN_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_TX_2_M_GAIN_ADDR) & ~((uint32_t)0x000007FF)) | ((uint32_t)iqdctxampgain <<0));
}

/**
 * @brief IQDC_TX_2_M_DC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 IQDC_TX_DCQ               0x0
 *    11:00 IQDC_TX_DCI               0x0
 * </pre>
 */
#define RFIC_WRAP_IQDC_TX_2_M_DC_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x000001A0)
#define RFIC_WRAP_IQDC_TX_2_M_DC_OFFSET      0x000001A0
#define RFIC_WRAP_IQDC_TX_2_M_DC_INDEX       0x00000068
#define RFIC_WRAP_IQDC_TX_2_M_DC_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_iqdc_tx_2_m_dc_get(void)
{
	return REG_PL_RD(RFIC_WRAP_IQDC_TX_2_M_DC_ADDR);
}

__INLINE void rfic_wrap_iqdc_tx_2_m_dc_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_IQDC_TX_2_M_DC_ADDR, value);
}

// field definitions
#define RFIC_WRAP_IQDC_TX_2_M_DC_IQDC_TX_DCQ_MASK    ((uint32_t)0x0FFF0000)
#define RFIC_WRAP_IQDC_TX_2_M_DC_IQDC_TX_DCQ_LSB    16
#define RFIC_WRAP_IQDC_TX_2_M_DC_IQDC_TX_DCQ_WIDTH    ((uint32_t)0x0000000C)
#define RFIC_WRAP_IQDC_TX_2_M_DC_IQDC_TX_DCI_MASK    ((uint32_t)0x00000FFF)
#define RFIC_WRAP_IQDC_TX_2_M_DC_IQDC_TX_DCI_LSB    0
#define RFIC_WRAP_IQDC_TX_2_M_DC_IQDC_TX_DCI_WIDTH    ((uint32_t)0x0000000C)

#define RFIC_WRAP_IQDC_TX_2_M_DC_IQDC_TX_DCQ_RST    0x0
#define RFIC_WRAP_IQDC_TX_2_M_DC_IQDC_TX_DCI_RST    0x0

__INLINE void rfic_wrap_iqdc_tx_2_m_dc_pack(uint16_t iqdc_tx_dcq, uint16_t iqdc_tx_dci)
{
	ASSERT_ERR((((uint32_t)iqdc_tx_dcq << 16) & ~((uint32_t)0x0FFF0000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_tx_dci << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_2_M_DC_ADDR,  ((uint32_t)iqdc_tx_dcq << 16) |((uint32_t)iqdc_tx_dci << 0));
}

__INLINE void rfic_wrap_iqdc_tx_2_m_dc_unpack(uint16_t* iqdc_tx_dcq, uint16_t* iqdc_tx_dci)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_2_M_DC_ADDR);

	*iqdc_tx_dcq = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*iqdc_tx_dci = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t rfic_wrap_iqdc_tx_2_m_dc_iqdc_tx_dcq_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_2_M_DC_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE void rfic_wrap_iqdc_tx_2_m_dc_iqdc_tx_dcq_setf(uint16_t iqdctxdcq)
{
	ASSERT_ERR((((uint32_t)iqdctxdcq << 16) & ~((uint32_t)0x0FFF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_2_M_DC_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_TX_2_M_DC_ADDR) & ~((uint32_t)0x0FFF0000)) | ((uint32_t)iqdctxdcq <<16));
}
__INLINE uint16_t rfic_wrap_iqdc_tx_2_m_dc_iqdc_tx_dci_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_2_M_DC_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}
__INLINE void rfic_wrap_iqdc_tx_2_m_dc_iqdc_tx_dci_setf(uint16_t iqdctxdci)
{
	ASSERT_ERR((((uint32_t)iqdctxdci << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_2_M_DC_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_TX_2_M_DC_ADDR) & ~((uint32_t)0x00000FFF)) | ((uint32_t)iqdctxdci <<0));
}

/**
 * @brief IQDC_TX_2_M_COEFF_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:23 IQDC_TX_FIR_COEFF_2       0x0
 *    20:12 IQDC_TX_FIR_COEFF_1       0x0
 *    08:00 IQDC_TX_FIR_COEFF_0       0x0
 * </pre>
 */
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_0_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x000001A4)
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_0_OFFSET      0x000001A4
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_0_INDEX       0x00000069
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_0_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_iqdc_tx_2_m_coeff_0_get(void)
{
	return REG_PL_RD(RFIC_WRAP_IQDC_TX_2_M_COEFF_0_ADDR);
}

__INLINE void rfic_wrap_iqdc_tx_2_m_coeff_0_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_IQDC_TX_2_M_COEFF_0_ADDR, value);
}

// field definitions
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_0_IQDC_TX_FIR_COEFF_2_MASK    ((uint32_t)0xFF800000)
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_0_IQDC_TX_FIR_COEFF_2_LSB    23
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_0_IQDC_TX_FIR_COEFF_2_WIDTH    ((uint32_t)0x00000009)
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_0_IQDC_TX_FIR_COEFF_1_MASK    ((uint32_t)0x001FF000)
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_0_IQDC_TX_FIR_COEFF_1_LSB    12
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_0_IQDC_TX_FIR_COEFF_1_WIDTH    ((uint32_t)0x00000009)
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_0_IQDC_TX_FIR_COEFF_0_MASK    ((uint32_t)0x000001FF)
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_0_IQDC_TX_FIR_COEFF_0_LSB    0
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_0_IQDC_TX_FIR_COEFF_0_WIDTH    ((uint32_t)0x00000009)

#define RFIC_WRAP_IQDC_TX_2_M_COEFF_0_IQDC_TX_FIR_COEFF_2_RST    0x0
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_0_IQDC_TX_FIR_COEFF_1_RST    0x0
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_0_IQDC_TX_FIR_COEFF_0_RST    0x0

__INLINE void rfic_wrap_iqdc_tx_2_m_coeff_0_pack(uint16_t iqdc_tx_fir_coeff_2, uint16_t iqdc_tx_fir_coeff_1, uint16_t iqdc_tx_fir_coeff_0)
{
	ASSERT_ERR((((uint32_t)iqdc_tx_fir_coeff_2 << 23) & ~((uint32_t)0xFF800000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_tx_fir_coeff_1 << 12) & ~((uint32_t)0x001FF000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_tx_fir_coeff_0 << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_2_M_COEFF_0_ADDR,  ((uint32_t)iqdc_tx_fir_coeff_2 << 23) |((uint32_t)iqdc_tx_fir_coeff_1 << 12) |((uint32_t)iqdc_tx_fir_coeff_0 << 0));
}

__INLINE void rfic_wrap_iqdc_tx_2_m_coeff_0_unpack(uint16_t* iqdc_tx_fir_coeff_2, uint16_t* iqdc_tx_fir_coeff_1, uint16_t* iqdc_tx_fir_coeff_0)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_2_M_COEFF_0_ADDR);

	*iqdc_tx_fir_coeff_2 = (localVal & ((uint32_t)0xFF800000)) >>  23;
	*iqdc_tx_fir_coeff_1 = (localVal & ((uint32_t)0x001FF000)) >>  12;
	*iqdc_tx_fir_coeff_0 = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint16_t rfic_wrap_iqdc_tx_2_m_coeff_0_iqdc_tx_fir_coeff_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_2_M_COEFF_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFF800000)) >> 23);
}
__INLINE void rfic_wrap_iqdc_tx_2_m_coeff_0_iqdc_tx_fir_coeff_2_setf(uint16_t iqdctxfircoeff2)
{
	ASSERT_ERR((((uint32_t)iqdctxfircoeff2 << 23) & ~((uint32_t)0xFF800000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_2_M_COEFF_0_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_TX_2_M_COEFF_0_ADDR) & ~((uint32_t)0xFF800000)) | ((uint32_t)iqdctxfircoeff2 <<23));
}
__INLINE uint16_t rfic_wrap_iqdc_tx_2_m_coeff_0_iqdc_tx_fir_coeff_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_2_M_COEFF_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x001FF000)) >> 12);
}
__INLINE void rfic_wrap_iqdc_tx_2_m_coeff_0_iqdc_tx_fir_coeff_1_setf(uint16_t iqdctxfircoeff1)
{
	ASSERT_ERR((((uint32_t)iqdctxfircoeff1 << 12) & ~((uint32_t)0x001FF000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_2_M_COEFF_0_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_TX_2_M_COEFF_0_ADDR) & ~((uint32_t)0x001FF000)) | ((uint32_t)iqdctxfircoeff1 <<12));
}
__INLINE uint16_t rfic_wrap_iqdc_tx_2_m_coeff_0_iqdc_tx_fir_coeff_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_2_M_COEFF_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}
__INLINE void rfic_wrap_iqdc_tx_2_m_coeff_0_iqdc_tx_fir_coeff_0_setf(uint16_t iqdctxfircoeff0)
{
	ASSERT_ERR((((uint32_t)iqdctxfircoeff0 << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_2_M_COEFF_0_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_TX_2_M_COEFF_0_ADDR) & ~((uint32_t)0x000001FF)) | ((uint32_t)iqdctxfircoeff0 <<0));
}

/**
 * @brief IQDC_TX_2_M_COEFF_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:23 IQDC_TX_FIR_COEFF_5       0x0
 *    20:12 IQDC_TX_FIR_COEFF_4       0x0
 *    08:00 IQDC_TX_FIR_COEFF_3       0x0
 * </pre>
 */
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_1_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x000001A8)
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_1_OFFSET      0x000001A8
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_1_INDEX       0x0000006A
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_1_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_iqdc_tx_2_m_coeff_1_get(void)
{
	return REG_PL_RD(RFIC_WRAP_IQDC_TX_2_M_COEFF_1_ADDR);
}

__INLINE void rfic_wrap_iqdc_tx_2_m_coeff_1_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_IQDC_TX_2_M_COEFF_1_ADDR, value);
}

// field definitions
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_1_IQDC_TX_FIR_COEFF_5_MASK    ((uint32_t)0xFF800000)
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_1_IQDC_TX_FIR_COEFF_5_LSB    23
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_1_IQDC_TX_FIR_COEFF_5_WIDTH    ((uint32_t)0x00000009)
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_1_IQDC_TX_FIR_COEFF_4_MASK    ((uint32_t)0x001FF000)
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_1_IQDC_TX_FIR_COEFF_4_LSB    12
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_1_IQDC_TX_FIR_COEFF_4_WIDTH    ((uint32_t)0x00000009)
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_1_IQDC_TX_FIR_COEFF_3_MASK    ((uint32_t)0x000001FF)
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_1_IQDC_TX_FIR_COEFF_3_LSB    0
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_1_IQDC_TX_FIR_COEFF_3_WIDTH    ((uint32_t)0x00000009)

#define RFIC_WRAP_IQDC_TX_2_M_COEFF_1_IQDC_TX_FIR_COEFF_5_RST    0x0
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_1_IQDC_TX_FIR_COEFF_4_RST    0x0
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_1_IQDC_TX_FIR_COEFF_3_RST    0x0

__INLINE void rfic_wrap_iqdc_tx_2_m_coeff_1_pack(uint16_t iqdc_tx_fir_coeff_5, uint16_t iqdc_tx_fir_coeff_4, uint16_t iqdc_tx_fir_coeff_3)
{
	ASSERT_ERR((((uint32_t)iqdc_tx_fir_coeff_5 << 23) & ~((uint32_t)0xFF800000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_tx_fir_coeff_4 << 12) & ~((uint32_t)0x001FF000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_tx_fir_coeff_3 << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_2_M_COEFF_1_ADDR,  ((uint32_t)iqdc_tx_fir_coeff_5 << 23) |((uint32_t)iqdc_tx_fir_coeff_4 << 12) |((uint32_t)iqdc_tx_fir_coeff_3 << 0));
}

__INLINE void rfic_wrap_iqdc_tx_2_m_coeff_1_unpack(uint16_t* iqdc_tx_fir_coeff_5, uint16_t* iqdc_tx_fir_coeff_4, uint16_t* iqdc_tx_fir_coeff_3)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_2_M_COEFF_1_ADDR);

	*iqdc_tx_fir_coeff_5 = (localVal & ((uint32_t)0xFF800000)) >>  23;
	*iqdc_tx_fir_coeff_4 = (localVal & ((uint32_t)0x001FF000)) >>  12;
	*iqdc_tx_fir_coeff_3 = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint16_t rfic_wrap_iqdc_tx_2_m_coeff_1_iqdc_tx_fir_coeff_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_2_M_COEFF_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFF800000)) >> 23);
}
__INLINE void rfic_wrap_iqdc_tx_2_m_coeff_1_iqdc_tx_fir_coeff_5_setf(uint16_t iqdctxfircoeff5)
{
	ASSERT_ERR((((uint32_t)iqdctxfircoeff5 << 23) & ~((uint32_t)0xFF800000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_2_M_COEFF_1_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_TX_2_M_COEFF_1_ADDR) & ~((uint32_t)0xFF800000)) | ((uint32_t)iqdctxfircoeff5 <<23));
}
__INLINE uint16_t rfic_wrap_iqdc_tx_2_m_coeff_1_iqdc_tx_fir_coeff_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_2_M_COEFF_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x001FF000)) >> 12);
}
__INLINE void rfic_wrap_iqdc_tx_2_m_coeff_1_iqdc_tx_fir_coeff_4_setf(uint16_t iqdctxfircoeff4)
{
	ASSERT_ERR((((uint32_t)iqdctxfircoeff4 << 12) & ~((uint32_t)0x001FF000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_2_M_COEFF_1_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_TX_2_M_COEFF_1_ADDR) & ~((uint32_t)0x001FF000)) | ((uint32_t)iqdctxfircoeff4 <<12));
}
__INLINE uint16_t rfic_wrap_iqdc_tx_2_m_coeff_1_iqdc_tx_fir_coeff_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_2_M_COEFF_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}
__INLINE void rfic_wrap_iqdc_tx_2_m_coeff_1_iqdc_tx_fir_coeff_3_setf(uint16_t iqdctxfircoeff3)
{
	ASSERT_ERR((((uint32_t)iqdctxfircoeff3 << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_2_M_COEFF_1_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_TX_2_M_COEFF_1_ADDR) & ~((uint32_t)0x000001FF)) | ((uint32_t)iqdctxfircoeff3 <<0));
}

/**
 * @brief IQDC_TX_2_M_COEFF_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:23 IQDC_TX_FIR_COEFF_8       0x0
 *    20:12 IQDC_TX_FIR_COEFF_7       0x0
 *    08:00 IQDC_TX_FIR_COEFF_6       0x0
 * </pre>
 */
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_2_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x000001AC)
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_2_OFFSET      0x000001AC
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_2_INDEX       0x0000006B
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_2_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_iqdc_tx_2_m_coeff_2_get(void)
{
	return REG_PL_RD(RFIC_WRAP_IQDC_TX_2_M_COEFF_2_ADDR);
}

__INLINE void rfic_wrap_iqdc_tx_2_m_coeff_2_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_IQDC_TX_2_M_COEFF_2_ADDR, value);
}

// field definitions
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_2_IQDC_TX_FIR_COEFF_8_MASK    ((uint32_t)0xFF800000)
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_2_IQDC_TX_FIR_COEFF_8_LSB    23
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_2_IQDC_TX_FIR_COEFF_8_WIDTH    ((uint32_t)0x00000009)
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_2_IQDC_TX_FIR_COEFF_7_MASK    ((uint32_t)0x001FF000)
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_2_IQDC_TX_FIR_COEFF_7_LSB    12
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_2_IQDC_TX_FIR_COEFF_7_WIDTH    ((uint32_t)0x00000009)
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_2_IQDC_TX_FIR_COEFF_6_MASK    ((uint32_t)0x000001FF)
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_2_IQDC_TX_FIR_COEFF_6_LSB    0
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_2_IQDC_TX_FIR_COEFF_6_WIDTH    ((uint32_t)0x00000009)

#define RFIC_WRAP_IQDC_TX_2_M_COEFF_2_IQDC_TX_FIR_COEFF_8_RST    0x0
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_2_IQDC_TX_FIR_COEFF_7_RST    0x0
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_2_IQDC_TX_FIR_COEFF_6_RST    0x0

__INLINE void rfic_wrap_iqdc_tx_2_m_coeff_2_pack(uint16_t iqdc_tx_fir_coeff_8, uint16_t iqdc_tx_fir_coeff_7, uint16_t iqdc_tx_fir_coeff_6)
{
	ASSERT_ERR((((uint32_t)iqdc_tx_fir_coeff_8 << 23) & ~((uint32_t)0xFF800000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_tx_fir_coeff_7 << 12) & ~((uint32_t)0x001FF000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_tx_fir_coeff_6 << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_2_M_COEFF_2_ADDR,  ((uint32_t)iqdc_tx_fir_coeff_8 << 23) |((uint32_t)iqdc_tx_fir_coeff_7 << 12) |((uint32_t)iqdc_tx_fir_coeff_6 << 0));
}

__INLINE void rfic_wrap_iqdc_tx_2_m_coeff_2_unpack(uint16_t* iqdc_tx_fir_coeff_8, uint16_t* iqdc_tx_fir_coeff_7, uint16_t* iqdc_tx_fir_coeff_6)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_2_M_COEFF_2_ADDR);

	*iqdc_tx_fir_coeff_8 = (localVal & ((uint32_t)0xFF800000)) >>  23;
	*iqdc_tx_fir_coeff_7 = (localVal & ((uint32_t)0x001FF000)) >>  12;
	*iqdc_tx_fir_coeff_6 = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint16_t rfic_wrap_iqdc_tx_2_m_coeff_2_iqdc_tx_fir_coeff_8_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_2_M_COEFF_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFF800000)) >> 23);
}
__INLINE void rfic_wrap_iqdc_tx_2_m_coeff_2_iqdc_tx_fir_coeff_8_setf(uint16_t iqdctxfircoeff8)
{
	ASSERT_ERR((((uint32_t)iqdctxfircoeff8 << 23) & ~((uint32_t)0xFF800000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_2_M_COEFF_2_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_TX_2_M_COEFF_2_ADDR) & ~((uint32_t)0xFF800000)) | ((uint32_t)iqdctxfircoeff8 <<23));
}
__INLINE uint16_t rfic_wrap_iqdc_tx_2_m_coeff_2_iqdc_tx_fir_coeff_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_2_M_COEFF_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x001FF000)) >> 12);
}
__INLINE void rfic_wrap_iqdc_tx_2_m_coeff_2_iqdc_tx_fir_coeff_7_setf(uint16_t iqdctxfircoeff7)
{
	ASSERT_ERR((((uint32_t)iqdctxfircoeff7 << 12) & ~((uint32_t)0x001FF000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_2_M_COEFF_2_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_TX_2_M_COEFF_2_ADDR) & ~((uint32_t)0x001FF000)) | ((uint32_t)iqdctxfircoeff7 <<12));
}
__INLINE uint16_t rfic_wrap_iqdc_tx_2_m_coeff_2_iqdc_tx_fir_coeff_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_2_M_COEFF_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}
__INLINE void rfic_wrap_iqdc_tx_2_m_coeff_2_iqdc_tx_fir_coeff_6_setf(uint16_t iqdctxfircoeff6)
{
	ASSERT_ERR((((uint32_t)iqdctxfircoeff6 << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_2_M_COEFF_2_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_TX_2_M_COEFF_2_ADDR) & ~((uint32_t)0x000001FF)) | ((uint32_t)iqdctxfircoeff6 <<0));
}

/**
 * @brief IQDC_TX_2_M_COEFF_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    20:12 IQDC_TX_FIR_COEFF_10      0x0
 *    08:00 IQDC_TX_FIR_COEFF_9       0x0
 * </pre>
 */
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_3_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x000001B0)
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_3_OFFSET      0x000001B0
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_3_INDEX       0x0000006C
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_3_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_iqdc_tx_2_m_coeff_3_get(void)
{
	return REG_PL_RD(RFIC_WRAP_IQDC_TX_2_M_COEFF_3_ADDR);
}

__INLINE void rfic_wrap_iqdc_tx_2_m_coeff_3_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_IQDC_TX_2_M_COEFF_3_ADDR, value);
}

// field definitions
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_3_IQDC_TX_FIR_COEFF_10_MASK    ((uint32_t)0x001FF000)
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_3_IQDC_TX_FIR_COEFF_10_LSB    12
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_3_IQDC_TX_FIR_COEFF_10_WIDTH    ((uint32_t)0x00000009)
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_3_IQDC_TX_FIR_COEFF_9_MASK    ((uint32_t)0x000001FF)
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_3_IQDC_TX_FIR_COEFF_9_LSB    0
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_3_IQDC_TX_FIR_COEFF_9_WIDTH    ((uint32_t)0x00000009)

#define RFIC_WRAP_IQDC_TX_2_M_COEFF_3_IQDC_TX_FIR_COEFF_10_RST    0x0
#define RFIC_WRAP_IQDC_TX_2_M_COEFF_3_IQDC_TX_FIR_COEFF_9_RST    0x0

__INLINE void rfic_wrap_iqdc_tx_2_m_coeff_3_pack(uint16_t iqdc_tx_fir_coeff_10, uint16_t iqdc_tx_fir_coeff_9)
{
	ASSERT_ERR((((uint32_t)iqdc_tx_fir_coeff_10 << 12) & ~((uint32_t)0x001FF000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_tx_fir_coeff_9 << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_2_M_COEFF_3_ADDR,  ((uint32_t)iqdc_tx_fir_coeff_10 << 12) |((uint32_t)iqdc_tx_fir_coeff_9 << 0));
}

__INLINE void rfic_wrap_iqdc_tx_2_m_coeff_3_unpack(uint16_t* iqdc_tx_fir_coeff_10, uint16_t* iqdc_tx_fir_coeff_9)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_2_M_COEFF_3_ADDR);

	*iqdc_tx_fir_coeff_10 = (localVal & ((uint32_t)0x001FF000)) >>  12;
	*iqdc_tx_fir_coeff_9 = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint16_t rfic_wrap_iqdc_tx_2_m_coeff_3_iqdc_tx_fir_coeff_10_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_2_M_COEFF_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x001FF000)) >> 12);
}
__INLINE void rfic_wrap_iqdc_tx_2_m_coeff_3_iqdc_tx_fir_coeff_10_setf(uint16_t iqdctxfircoeff10)
{
	ASSERT_ERR((((uint32_t)iqdctxfircoeff10 << 12) & ~((uint32_t)0x001FF000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_2_M_COEFF_3_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_TX_2_M_COEFF_3_ADDR) & ~((uint32_t)0x001FF000)) | ((uint32_t)iqdctxfircoeff10 <<12));
}
__INLINE uint16_t rfic_wrap_iqdc_tx_2_m_coeff_3_iqdc_tx_fir_coeff_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_TX_2_M_COEFF_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}
__INLINE void rfic_wrap_iqdc_tx_2_m_coeff_3_iqdc_tx_fir_coeff_9_setf(uint16_t iqdctxfircoeff9)
{
	ASSERT_ERR((((uint32_t)iqdctxfircoeff9 << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_TX_2_M_COEFF_3_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_TX_2_M_COEFF_3_ADDR) & ~((uint32_t)0x000001FF)) | ((uint32_t)iqdctxfircoeff9 <<0));
}

/**
 * @brief IQDC_RX_CONTROL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    19:18 IQDC_RX_FIR_SCALE_2_M     0x0
 *    17:16 IQDC_RX_FIR_SCALE_1_M     0x0
 *    15    IQDC_ZERO_DATA_OVR_EN     0              
 *    14    IQDC_ZERO_DATA_OVR_VAL    0              
 *    13    IQDC_2_M_SEL_OVR_VAL      0              
 *    12    IQDC_2_M_SEL_OVR_EN       0              
 *    10:09 IQDC_RX_BYPASS_TYPE       0x0
 *    08    IQDC_RX_BYPASS_MODE       0              
 *    00    IQDC_RX_START             0              
 * </pre>
 */
#define RFIC_WRAP_IQDC_RX_CONTROL_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x000001B4)
#define RFIC_WRAP_IQDC_RX_CONTROL_OFFSET      0x000001B4
#define RFIC_WRAP_IQDC_RX_CONTROL_INDEX       0x0000006D
#define RFIC_WRAP_IQDC_RX_CONTROL_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_iqdc_rx_control_get(void)
{
	return REG_PL_RD(RFIC_WRAP_IQDC_RX_CONTROL_ADDR);
}

__INLINE void rfic_wrap_iqdc_rx_control_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_IQDC_RX_CONTROL_ADDR, value);
}

// field definitions
#define RFIC_WRAP_IQDC_RX_CONTROL_IQDC_RX_FIR_SCALE_2_M_MASK    ((uint32_t)0x000C0000)
#define RFIC_WRAP_IQDC_RX_CONTROL_IQDC_RX_FIR_SCALE_2_M_LSB    18
#define RFIC_WRAP_IQDC_RX_CONTROL_IQDC_RX_FIR_SCALE_2_M_WIDTH    ((uint32_t)0x00000002)
#define RFIC_WRAP_IQDC_RX_CONTROL_IQDC_RX_FIR_SCALE_1_M_MASK    ((uint32_t)0x00030000)
#define RFIC_WRAP_IQDC_RX_CONTROL_IQDC_RX_FIR_SCALE_1_M_LSB    16
#define RFIC_WRAP_IQDC_RX_CONTROL_IQDC_RX_FIR_SCALE_1_M_WIDTH    ((uint32_t)0x00000002)
#define RFIC_WRAP_IQDC_RX_CONTROL_IQDC_ZERO_DATA_OVR_EN_BIT    ((uint32_t)0x00008000)
#define RFIC_WRAP_IQDC_RX_CONTROL_IQDC_ZERO_DATA_OVR_EN_POS    15
#define RFIC_WRAP_IQDC_RX_CONTROL_IQDC_ZERO_DATA_OVR_VAL_BIT    ((uint32_t)0x00004000)
#define RFIC_WRAP_IQDC_RX_CONTROL_IQDC_ZERO_DATA_OVR_VAL_POS    14
#define RFIC_WRAP_IQDC_RX_CONTROL_IQDC_2_M_SEL_OVR_VAL_BIT    ((uint32_t)0x00002000)
#define RFIC_WRAP_IQDC_RX_CONTROL_IQDC_2_M_SEL_OVR_VAL_POS    13
#define RFIC_WRAP_IQDC_RX_CONTROL_IQDC_2_M_SEL_OVR_EN_BIT    ((uint32_t)0x00001000)
#define RFIC_WRAP_IQDC_RX_CONTROL_IQDC_2_M_SEL_OVR_EN_POS    12
#define RFIC_WRAP_IQDC_RX_CONTROL_IQDC_RX_BYPASS_TYPE_MASK    ((uint32_t)0x00000600)
#define RFIC_WRAP_IQDC_RX_CONTROL_IQDC_RX_BYPASS_TYPE_LSB    9
#define RFIC_WRAP_IQDC_RX_CONTROL_IQDC_RX_BYPASS_TYPE_WIDTH    ((uint32_t)0x00000002)
#define RFIC_WRAP_IQDC_RX_CONTROL_IQDC_RX_BYPASS_MODE_BIT    ((uint32_t)0x00000100)
#define RFIC_WRAP_IQDC_RX_CONTROL_IQDC_RX_BYPASS_MODE_POS    8
#define RFIC_WRAP_IQDC_RX_CONTROL_IQDC_RX_START_BIT    ((uint32_t)0x00000001)
#define RFIC_WRAP_IQDC_RX_CONTROL_IQDC_RX_START_POS    0

#define RFIC_WRAP_IQDC_RX_CONTROL_IQDC_RX_FIR_SCALE_2_M_RST    0x0
#define RFIC_WRAP_IQDC_RX_CONTROL_IQDC_RX_FIR_SCALE_1_M_RST    0x0
#define RFIC_WRAP_IQDC_RX_CONTROL_IQDC_ZERO_DATA_OVR_EN_RST    0x0
#define RFIC_WRAP_IQDC_RX_CONTROL_IQDC_ZERO_DATA_OVR_VAL_RST    0x0
#define RFIC_WRAP_IQDC_RX_CONTROL_IQDC_2_M_SEL_OVR_VAL_RST    0x0
#define RFIC_WRAP_IQDC_RX_CONTROL_IQDC_2_M_SEL_OVR_EN_RST    0x0
#define RFIC_WRAP_IQDC_RX_CONTROL_IQDC_RX_BYPASS_TYPE_RST    0x0
#define RFIC_WRAP_IQDC_RX_CONTROL_IQDC_RX_BYPASS_MODE_RST    0x0
#define RFIC_WRAP_IQDC_RX_CONTROL_IQDC_RX_START_RST    0x0

__INLINE void rfic_wrap_iqdc_rx_control_pack(uint8_t iqdc_rx_fir_scale_2_m, uint8_t iqdc_rx_fir_scale_1_m, uint8_t iqdc_zero_data_ovr_en, uint8_t iqdc_zero_data_ovr_val, uint8_t iqdc_2_m_sel_ovr_val, uint8_t iqdc_2_m_sel_ovr_en, uint8_t iqdc_rx_bypass_type, uint8_t iqdc_rx_bypass_mode, uint8_t iqdc_rx_start)
{
	ASSERT_ERR((((uint32_t)iqdc_rx_fir_scale_2_m << 18) & ~((uint32_t)0x000C0000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_rx_fir_scale_1_m << 16) & ~((uint32_t)0x00030000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_zero_data_ovr_en << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_zero_data_ovr_val << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_2_m_sel_ovr_val << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_2_m_sel_ovr_en << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_rx_bypass_type << 9) & ~((uint32_t)0x00000600)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_rx_bypass_mode << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_rx_start << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_CONTROL_ADDR,  ((uint32_t)iqdc_rx_fir_scale_2_m << 18) |((uint32_t)iqdc_rx_fir_scale_1_m << 16) |((uint32_t)iqdc_zero_data_ovr_en << 15) |((uint32_t)iqdc_zero_data_ovr_val << 14) |((uint32_t)iqdc_2_m_sel_ovr_val << 13) |((uint32_t)iqdc_2_m_sel_ovr_en << 12) |((uint32_t)iqdc_rx_bypass_type << 9) |((uint32_t)iqdc_rx_bypass_mode << 8) |((uint32_t)iqdc_rx_start << 0));
}

__INLINE void rfic_wrap_iqdc_rx_control_unpack(uint8_t* iqdc_rx_fir_scale_2_m, uint8_t* iqdc_rx_fir_scale_1_m, uint8_t* iqdc_zero_data_ovr_en, uint8_t* iqdc_zero_data_ovr_val, uint8_t* iqdc_2_m_sel_ovr_val, uint8_t* iqdc_2_m_sel_ovr_en, uint8_t* iqdc_rx_bypass_type, uint8_t* iqdc_rx_bypass_mode, uint8_t* iqdc_rx_start)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_CONTROL_ADDR);

	*iqdc_rx_fir_scale_2_m = (localVal & ((uint32_t)0x000C0000)) >>  18;
	*iqdc_rx_fir_scale_1_m = (localVal & ((uint32_t)0x00030000)) >>  16;
	*iqdc_zero_data_ovr_en = (localVal & ((uint32_t)0x00008000)) >>  15;
	*iqdc_zero_data_ovr_val = (localVal & ((uint32_t)0x00004000)) >>  14;
	*iqdc_2_m_sel_ovr_val = (localVal & ((uint32_t)0x00002000)) >>  13;
	*iqdc_2_m_sel_ovr_en = (localVal & ((uint32_t)0x00001000)) >>  12;
	*iqdc_rx_bypass_type = (localVal & ((uint32_t)0x00000600)) >>  9;
	*iqdc_rx_bypass_mode = (localVal & ((uint32_t)0x00000100)) >>  8;
	*iqdc_rx_start = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t rfic_wrap_iqdc_rx_control_iqdc_rx_fir_scale_2_m_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_CONTROL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000C0000)) >> 18);
}
__INLINE void rfic_wrap_iqdc_rx_control_iqdc_rx_fir_scale_2_m_setf(uint8_t iqdcrxfirscale2m)
{
	ASSERT_ERR((((uint32_t)iqdcrxfirscale2m << 18) & ~((uint32_t)0x000C0000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_CONTROL_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_RX_CONTROL_ADDR) & ~((uint32_t)0x000C0000)) | ((uint32_t)iqdcrxfirscale2m <<18));
}
__INLINE uint8_t rfic_wrap_iqdc_rx_control_iqdc_rx_fir_scale_1_m_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_CONTROL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00030000)) >> 16);
}
__INLINE void rfic_wrap_iqdc_rx_control_iqdc_rx_fir_scale_1_m_setf(uint8_t iqdcrxfirscale1m)
{
	ASSERT_ERR((((uint32_t)iqdcrxfirscale1m << 16) & ~((uint32_t)0x00030000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_CONTROL_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_RX_CONTROL_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)iqdcrxfirscale1m <<16));
}
__INLINE uint8_t rfic_wrap_iqdc_rx_control_iqdc_zero_data_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_CONTROL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void rfic_wrap_iqdc_rx_control_iqdc_zero_data_ovr_en_setf(uint8_t iqdczerodataovren)
{
	ASSERT_ERR((((uint32_t)iqdczerodataovren << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_CONTROL_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_RX_CONTROL_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)iqdczerodataovren <<15));
}
__INLINE uint8_t rfic_wrap_iqdc_rx_control_iqdc_zero_data_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_CONTROL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void rfic_wrap_iqdc_rx_control_iqdc_zero_data_ovr_val_setf(uint8_t iqdczerodataovrval)
{
	ASSERT_ERR((((uint32_t)iqdczerodataovrval << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_CONTROL_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_RX_CONTROL_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)iqdczerodataovrval <<14));
}
__INLINE uint8_t rfic_wrap_iqdc_rx_control_iqdc_2_m_sel_ovr_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_CONTROL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void rfic_wrap_iqdc_rx_control_iqdc_2_m_sel_ovr_val_setf(uint8_t iqdc2mselovrval)
{
	ASSERT_ERR((((uint32_t)iqdc2mselovrval << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_CONTROL_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_RX_CONTROL_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)iqdc2mselovrval <<13));
}
__INLINE uint8_t rfic_wrap_iqdc_rx_control_iqdc_2_m_sel_ovr_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_CONTROL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void rfic_wrap_iqdc_rx_control_iqdc_2_m_sel_ovr_en_setf(uint8_t iqdc2mselovren)
{
	ASSERT_ERR((((uint32_t)iqdc2mselovren << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_CONTROL_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_RX_CONTROL_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)iqdc2mselovren <<12));
}
__INLINE uint8_t rfic_wrap_iqdc_rx_control_iqdc_rx_bypass_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_CONTROL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000600)) >> 9);
}
__INLINE void rfic_wrap_iqdc_rx_control_iqdc_rx_bypass_type_setf(uint8_t iqdcrxbypasstype)
{
	ASSERT_ERR((((uint32_t)iqdcrxbypasstype << 9) & ~((uint32_t)0x00000600)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_CONTROL_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_RX_CONTROL_ADDR) & ~((uint32_t)0x00000600)) | ((uint32_t)iqdcrxbypasstype <<9));
}
__INLINE uint8_t rfic_wrap_iqdc_rx_control_iqdc_rx_bypass_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_CONTROL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void rfic_wrap_iqdc_rx_control_iqdc_rx_bypass_mode_setf(uint8_t iqdcrxbypassmode)
{
	ASSERT_ERR((((uint32_t)iqdcrxbypassmode << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_CONTROL_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_RX_CONTROL_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)iqdcrxbypassmode <<8));
}
__INLINE void rfic_wrap_iqdc_rx_control_iqdc_rx_start_setf(uint8_t iqdcrxstart)
{
	ASSERT_ERR((((uint32_t)iqdcrxstart << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_CONTROL_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_RX_CONTROL_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)iqdcrxstart <<0));
}

/**
 * @brief IQDC_RX_1_M_GAIN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 IQDC_RX_PHASE_GAIN        0x0
 *    10:00 IQDC_RX_AMP_GAIN          0x0
 * </pre>
 */
#define RFIC_WRAP_IQDC_RX_1_M_GAIN_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x000001B8)
#define RFIC_WRAP_IQDC_RX_1_M_GAIN_OFFSET      0x000001B8
#define RFIC_WRAP_IQDC_RX_1_M_GAIN_INDEX       0x0000006E
#define RFIC_WRAP_IQDC_RX_1_M_GAIN_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_iqdc_rx_1_m_gain_get(void)
{
	return REG_PL_RD(RFIC_WRAP_IQDC_RX_1_M_GAIN_ADDR);
}

__INLINE void rfic_wrap_iqdc_rx_1_m_gain_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_IQDC_RX_1_M_GAIN_ADDR, value);
}

// field definitions
#define RFIC_WRAP_IQDC_RX_1_M_GAIN_IQDC_RX_PHASE_GAIN_MASK    ((uint32_t)0x0FFF0000)
#define RFIC_WRAP_IQDC_RX_1_M_GAIN_IQDC_RX_PHASE_GAIN_LSB    16
#define RFIC_WRAP_IQDC_RX_1_M_GAIN_IQDC_RX_PHASE_GAIN_WIDTH    ((uint32_t)0x0000000C)
#define RFIC_WRAP_IQDC_RX_1_M_GAIN_IQDC_RX_AMP_GAIN_MASK    ((uint32_t)0x000007FF)
#define RFIC_WRAP_IQDC_RX_1_M_GAIN_IQDC_RX_AMP_GAIN_LSB    0
#define RFIC_WRAP_IQDC_RX_1_M_GAIN_IQDC_RX_AMP_GAIN_WIDTH    ((uint32_t)0x0000000B)

#define RFIC_WRAP_IQDC_RX_1_M_GAIN_IQDC_RX_PHASE_GAIN_RST    0x0
#define RFIC_WRAP_IQDC_RX_1_M_GAIN_IQDC_RX_AMP_GAIN_RST    0x0

__INLINE void rfic_wrap_iqdc_rx_1_m_gain_pack(uint16_t iqdc_rx_phase_gain, uint16_t iqdc_rx_amp_gain)
{
	ASSERT_ERR((((uint32_t)iqdc_rx_phase_gain << 16) & ~((uint32_t)0x0FFF0000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_rx_amp_gain << 0) & ~((uint32_t)0x000007FF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_1_M_GAIN_ADDR,  ((uint32_t)iqdc_rx_phase_gain << 16) |((uint32_t)iqdc_rx_amp_gain << 0));
}

__INLINE void rfic_wrap_iqdc_rx_1_m_gain_unpack(uint16_t* iqdc_rx_phase_gain, uint16_t* iqdc_rx_amp_gain)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_1_M_GAIN_ADDR);

	*iqdc_rx_phase_gain = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*iqdc_rx_amp_gain = (localVal & ((uint32_t)0x000007FF)) >>  0;
}

__INLINE uint16_t rfic_wrap_iqdc_rx_1_m_gain_iqdc_rx_phase_gain_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_1_M_GAIN_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE void rfic_wrap_iqdc_rx_1_m_gain_iqdc_rx_phase_gain_setf(uint16_t iqdcrxphasegain)
{
	ASSERT_ERR((((uint32_t)iqdcrxphasegain << 16) & ~((uint32_t)0x0FFF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_1_M_GAIN_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_RX_1_M_GAIN_ADDR) & ~((uint32_t)0x0FFF0000)) | ((uint32_t)iqdcrxphasegain <<16));
}
__INLINE uint16_t rfic_wrap_iqdc_rx_1_m_gain_iqdc_rx_amp_gain_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_1_M_GAIN_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000007FF)) >> 0);
}
__INLINE void rfic_wrap_iqdc_rx_1_m_gain_iqdc_rx_amp_gain_setf(uint16_t iqdcrxampgain)
{
	ASSERT_ERR((((uint32_t)iqdcrxampgain << 0) & ~((uint32_t)0x000007FF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_1_M_GAIN_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_RX_1_M_GAIN_ADDR) & ~((uint32_t)0x000007FF)) | ((uint32_t)iqdcrxampgain <<0));
}

/**
 * @brief IQDC_RX_1_M_DC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 IQDC_RX_DCQ               0x0
 *    11:00 IQDC_RX_DCI               0x0
 * </pre>
 */
#define RFIC_WRAP_IQDC_RX_1_M_DC_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x000001BC)
#define RFIC_WRAP_IQDC_RX_1_M_DC_OFFSET      0x000001BC
#define RFIC_WRAP_IQDC_RX_1_M_DC_INDEX       0x0000006F
#define RFIC_WRAP_IQDC_RX_1_M_DC_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_iqdc_rx_1_m_dc_get(void)
{
	return REG_PL_RD(RFIC_WRAP_IQDC_RX_1_M_DC_ADDR);
}

__INLINE void rfic_wrap_iqdc_rx_1_m_dc_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_IQDC_RX_1_M_DC_ADDR, value);
}

// field definitions
#define RFIC_WRAP_IQDC_RX_1_M_DC_IQDC_RX_DCQ_MASK    ((uint32_t)0x0FFF0000)
#define RFIC_WRAP_IQDC_RX_1_M_DC_IQDC_RX_DCQ_LSB    16
#define RFIC_WRAP_IQDC_RX_1_M_DC_IQDC_RX_DCQ_WIDTH    ((uint32_t)0x0000000C)
#define RFIC_WRAP_IQDC_RX_1_M_DC_IQDC_RX_DCI_MASK    ((uint32_t)0x00000FFF)
#define RFIC_WRAP_IQDC_RX_1_M_DC_IQDC_RX_DCI_LSB    0
#define RFIC_WRAP_IQDC_RX_1_M_DC_IQDC_RX_DCI_WIDTH    ((uint32_t)0x0000000C)

#define RFIC_WRAP_IQDC_RX_1_M_DC_IQDC_RX_DCQ_RST    0x0
#define RFIC_WRAP_IQDC_RX_1_M_DC_IQDC_RX_DCI_RST    0x0

__INLINE void rfic_wrap_iqdc_rx_1_m_dc_pack(uint16_t iqdc_rx_dcq, uint16_t iqdc_rx_dci)
{
	ASSERT_ERR((((uint32_t)iqdc_rx_dcq << 16) & ~((uint32_t)0x0FFF0000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_rx_dci << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_1_M_DC_ADDR,  ((uint32_t)iqdc_rx_dcq << 16) |((uint32_t)iqdc_rx_dci << 0));
}

__INLINE void rfic_wrap_iqdc_rx_1_m_dc_unpack(uint16_t* iqdc_rx_dcq, uint16_t* iqdc_rx_dci)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_1_M_DC_ADDR);

	*iqdc_rx_dcq = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*iqdc_rx_dci = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t rfic_wrap_iqdc_rx_1_m_dc_iqdc_rx_dcq_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_1_M_DC_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE void rfic_wrap_iqdc_rx_1_m_dc_iqdc_rx_dcq_setf(uint16_t iqdcrxdcq)
{
	ASSERT_ERR((((uint32_t)iqdcrxdcq << 16) & ~((uint32_t)0x0FFF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_1_M_DC_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_RX_1_M_DC_ADDR) & ~((uint32_t)0x0FFF0000)) | ((uint32_t)iqdcrxdcq <<16));
}
__INLINE uint16_t rfic_wrap_iqdc_rx_1_m_dc_iqdc_rx_dci_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_1_M_DC_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}
__INLINE void rfic_wrap_iqdc_rx_1_m_dc_iqdc_rx_dci_setf(uint16_t iqdcrxdci)
{
	ASSERT_ERR((((uint32_t)iqdcrxdci << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_1_M_DC_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_RX_1_M_DC_ADDR) & ~((uint32_t)0x00000FFF)) | ((uint32_t)iqdcrxdci <<0));
}

/**
 * @brief IQDC_RX_1_M_COEFF_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:23 IQDC_RX_FIR_COEFF_2       0x0
 *    20:12 IQDC_RX_FIR_COEFF_1       0x0
 *    08:00 IQDC_RX_FIR_COEFF_0       0x0
 * </pre>
 */
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_0_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x000001C0)
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_0_OFFSET      0x000001C0
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_0_INDEX       0x00000070
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_0_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_iqdc_rx_1_m_coeff_0_get(void)
{
	return REG_PL_RD(RFIC_WRAP_IQDC_RX_1_M_COEFF_0_ADDR);
}

__INLINE void rfic_wrap_iqdc_rx_1_m_coeff_0_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_IQDC_RX_1_M_COEFF_0_ADDR, value);
}

// field definitions
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_0_IQDC_RX_FIR_COEFF_2_MASK    ((uint32_t)0xFF800000)
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_0_IQDC_RX_FIR_COEFF_2_LSB    23
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_0_IQDC_RX_FIR_COEFF_2_WIDTH    ((uint32_t)0x00000009)
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_0_IQDC_RX_FIR_COEFF_1_MASK    ((uint32_t)0x001FF000)
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_0_IQDC_RX_FIR_COEFF_1_LSB    12
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_0_IQDC_RX_FIR_COEFF_1_WIDTH    ((uint32_t)0x00000009)
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_0_IQDC_RX_FIR_COEFF_0_MASK    ((uint32_t)0x000001FF)
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_0_IQDC_RX_FIR_COEFF_0_LSB    0
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_0_IQDC_RX_FIR_COEFF_0_WIDTH    ((uint32_t)0x00000009)

#define RFIC_WRAP_IQDC_RX_1_M_COEFF_0_IQDC_RX_FIR_COEFF_2_RST    0x0
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_0_IQDC_RX_FIR_COEFF_1_RST    0x0
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_0_IQDC_RX_FIR_COEFF_0_RST    0x0

__INLINE void rfic_wrap_iqdc_rx_1_m_coeff_0_pack(uint16_t iqdc_rx_fir_coeff_2, uint16_t iqdc_rx_fir_coeff_1, uint16_t iqdc_rx_fir_coeff_0)
{
	ASSERT_ERR((((uint32_t)iqdc_rx_fir_coeff_2 << 23) & ~((uint32_t)0xFF800000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_rx_fir_coeff_1 << 12) & ~((uint32_t)0x001FF000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_rx_fir_coeff_0 << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_1_M_COEFF_0_ADDR,  ((uint32_t)iqdc_rx_fir_coeff_2 << 23) |((uint32_t)iqdc_rx_fir_coeff_1 << 12) |((uint32_t)iqdc_rx_fir_coeff_0 << 0));
}

__INLINE void rfic_wrap_iqdc_rx_1_m_coeff_0_unpack(uint16_t* iqdc_rx_fir_coeff_2, uint16_t* iqdc_rx_fir_coeff_1, uint16_t* iqdc_rx_fir_coeff_0)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_1_M_COEFF_0_ADDR);

	*iqdc_rx_fir_coeff_2 = (localVal & ((uint32_t)0xFF800000)) >>  23;
	*iqdc_rx_fir_coeff_1 = (localVal & ((uint32_t)0x001FF000)) >>  12;
	*iqdc_rx_fir_coeff_0 = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint16_t rfic_wrap_iqdc_rx_1_m_coeff_0_iqdc_rx_fir_coeff_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_1_M_COEFF_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFF800000)) >> 23);
}
__INLINE void rfic_wrap_iqdc_rx_1_m_coeff_0_iqdc_rx_fir_coeff_2_setf(uint16_t iqdcrxfircoeff2)
{
	ASSERT_ERR((((uint32_t)iqdcrxfircoeff2 << 23) & ~((uint32_t)0xFF800000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_1_M_COEFF_0_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_RX_1_M_COEFF_0_ADDR) & ~((uint32_t)0xFF800000)) | ((uint32_t)iqdcrxfircoeff2 <<23));
}
__INLINE uint16_t rfic_wrap_iqdc_rx_1_m_coeff_0_iqdc_rx_fir_coeff_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_1_M_COEFF_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x001FF000)) >> 12);
}
__INLINE void rfic_wrap_iqdc_rx_1_m_coeff_0_iqdc_rx_fir_coeff_1_setf(uint16_t iqdcrxfircoeff1)
{
	ASSERT_ERR((((uint32_t)iqdcrxfircoeff1 << 12) & ~((uint32_t)0x001FF000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_1_M_COEFF_0_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_RX_1_M_COEFF_0_ADDR) & ~((uint32_t)0x001FF000)) | ((uint32_t)iqdcrxfircoeff1 <<12));
}
__INLINE uint16_t rfic_wrap_iqdc_rx_1_m_coeff_0_iqdc_rx_fir_coeff_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_1_M_COEFF_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}
__INLINE void rfic_wrap_iqdc_rx_1_m_coeff_0_iqdc_rx_fir_coeff_0_setf(uint16_t iqdcrxfircoeff0)
{
	ASSERT_ERR((((uint32_t)iqdcrxfircoeff0 << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_1_M_COEFF_0_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_RX_1_M_COEFF_0_ADDR) & ~((uint32_t)0x000001FF)) | ((uint32_t)iqdcrxfircoeff0 <<0));
}

/**
 * @brief IQDC_RX_1_M_COEFF_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:23 IQDC_RX_FIR_COEFF_5       0x0
 *    20:12 IQDC_RX_FIR_COEFF_4       0x0
 *    08:00 IQDC_RX_FIR_COEFF_3       0x0
 * </pre>
 */
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_1_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x000001C4)
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_1_OFFSET      0x000001C4
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_1_INDEX       0x00000071
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_1_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_iqdc_rx_1_m_coeff_1_get(void)
{
	return REG_PL_RD(RFIC_WRAP_IQDC_RX_1_M_COEFF_1_ADDR);
}

__INLINE void rfic_wrap_iqdc_rx_1_m_coeff_1_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_IQDC_RX_1_M_COEFF_1_ADDR, value);
}

// field definitions
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_1_IQDC_RX_FIR_COEFF_5_MASK    ((uint32_t)0xFF800000)
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_1_IQDC_RX_FIR_COEFF_5_LSB    23
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_1_IQDC_RX_FIR_COEFF_5_WIDTH    ((uint32_t)0x00000009)
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_1_IQDC_RX_FIR_COEFF_4_MASK    ((uint32_t)0x001FF000)
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_1_IQDC_RX_FIR_COEFF_4_LSB    12
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_1_IQDC_RX_FIR_COEFF_4_WIDTH    ((uint32_t)0x00000009)
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_1_IQDC_RX_FIR_COEFF_3_MASK    ((uint32_t)0x000001FF)
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_1_IQDC_RX_FIR_COEFF_3_LSB    0
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_1_IQDC_RX_FIR_COEFF_3_WIDTH    ((uint32_t)0x00000009)

#define RFIC_WRAP_IQDC_RX_1_M_COEFF_1_IQDC_RX_FIR_COEFF_5_RST    0x0
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_1_IQDC_RX_FIR_COEFF_4_RST    0x0
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_1_IQDC_RX_FIR_COEFF_3_RST    0x0

__INLINE void rfic_wrap_iqdc_rx_1_m_coeff_1_pack(uint16_t iqdc_rx_fir_coeff_5, uint16_t iqdc_rx_fir_coeff_4, uint16_t iqdc_rx_fir_coeff_3)
{
	ASSERT_ERR((((uint32_t)iqdc_rx_fir_coeff_5 << 23) & ~((uint32_t)0xFF800000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_rx_fir_coeff_4 << 12) & ~((uint32_t)0x001FF000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_rx_fir_coeff_3 << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_1_M_COEFF_1_ADDR,  ((uint32_t)iqdc_rx_fir_coeff_5 << 23) |((uint32_t)iqdc_rx_fir_coeff_4 << 12) |((uint32_t)iqdc_rx_fir_coeff_3 << 0));
}

__INLINE void rfic_wrap_iqdc_rx_1_m_coeff_1_unpack(uint16_t* iqdc_rx_fir_coeff_5, uint16_t* iqdc_rx_fir_coeff_4, uint16_t* iqdc_rx_fir_coeff_3)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_1_M_COEFF_1_ADDR);

	*iqdc_rx_fir_coeff_5 = (localVal & ((uint32_t)0xFF800000)) >>  23;
	*iqdc_rx_fir_coeff_4 = (localVal & ((uint32_t)0x001FF000)) >>  12;
	*iqdc_rx_fir_coeff_3 = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint16_t rfic_wrap_iqdc_rx_1_m_coeff_1_iqdc_rx_fir_coeff_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_1_M_COEFF_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFF800000)) >> 23);
}
__INLINE void rfic_wrap_iqdc_rx_1_m_coeff_1_iqdc_rx_fir_coeff_5_setf(uint16_t iqdcrxfircoeff5)
{
	ASSERT_ERR((((uint32_t)iqdcrxfircoeff5 << 23) & ~((uint32_t)0xFF800000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_1_M_COEFF_1_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_RX_1_M_COEFF_1_ADDR) & ~((uint32_t)0xFF800000)) | ((uint32_t)iqdcrxfircoeff5 <<23));
}
__INLINE uint16_t rfic_wrap_iqdc_rx_1_m_coeff_1_iqdc_rx_fir_coeff_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_1_M_COEFF_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x001FF000)) >> 12);
}
__INLINE void rfic_wrap_iqdc_rx_1_m_coeff_1_iqdc_rx_fir_coeff_4_setf(uint16_t iqdcrxfircoeff4)
{
	ASSERT_ERR((((uint32_t)iqdcrxfircoeff4 << 12) & ~((uint32_t)0x001FF000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_1_M_COEFF_1_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_RX_1_M_COEFF_1_ADDR) & ~((uint32_t)0x001FF000)) | ((uint32_t)iqdcrxfircoeff4 <<12));
}
__INLINE uint16_t rfic_wrap_iqdc_rx_1_m_coeff_1_iqdc_rx_fir_coeff_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_1_M_COEFF_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}
__INLINE void rfic_wrap_iqdc_rx_1_m_coeff_1_iqdc_rx_fir_coeff_3_setf(uint16_t iqdcrxfircoeff3)
{
	ASSERT_ERR((((uint32_t)iqdcrxfircoeff3 << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_1_M_COEFF_1_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_RX_1_M_COEFF_1_ADDR) & ~((uint32_t)0x000001FF)) | ((uint32_t)iqdcrxfircoeff3 <<0));
}

/**
 * @brief IQDC_RX_1_M_COEFF_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:23 IQDC_RX_FIR_COEFF_8       0x0
 *    20:12 IQDC_RX_FIR_COEFF_7       0x0
 *    08:00 IQDC_RX_FIR_COEFF_6       0x0
 * </pre>
 */
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_2_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x000001C8)
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_2_OFFSET      0x000001C8
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_2_INDEX       0x00000072
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_2_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_iqdc_rx_1_m_coeff_2_get(void)
{
	return REG_PL_RD(RFIC_WRAP_IQDC_RX_1_M_COEFF_2_ADDR);
}

__INLINE void rfic_wrap_iqdc_rx_1_m_coeff_2_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_IQDC_RX_1_M_COEFF_2_ADDR, value);
}

// field definitions
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_2_IQDC_RX_FIR_COEFF_8_MASK    ((uint32_t)0xFF800000)
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_2_IQDC_RX_FIR_COEFF_8_LSB    23
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_2_IQDC_RX_FIR_COEFF_8_WIDTH    ((uint32_t)0x00000009)
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_2_IQDC_RX_FIR_COEFF_7_MASK    ((uint32_t)0x001FF000)
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_2_IQDC_RX_FIR_COEFF_7_LSB    12
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_2_IQDC_RX_FIR_COEFF_7_WIDTH    ((uint32_t)0x00000009)
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_2_IQDC_RX_FIR_COEFF_6_MASK    ((uint32_t)0x000001FF)
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_2_IQDC_RX_FIR_COEFF_6_LSB    0
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_2_IQDC_RX_FIR_COEFF_6_WIDTH    ((uint32_t)0x00000009)

#define RFIC_WRAP_IQDC_RX_1_M_COEFF_2_IQDC_RX_FIR_COEFF_8_RST    0x0
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_2_IQDC_RX_FIR_COEFF_7_RST    0x0
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_2_IQDC_RX_FIR_COEFF_6_RST    0x0

__INLINE void rfic_wrap_iqdc_rx_1_m_coeff_2_pack(uint16_t iqdc_rx_fir_coeff_8, uint16_t iqdc_rx_fir_coeff_7, uint16_t iqdc_rx_fir_coeff_6)
{
	ASSERT_ERR((((uint32_t)iqdc_rx_fir_coeff_8 << 23) & ~((uint32_t)0xFF800000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_rx_fir_coeff_7 << 12) & ~((uint32_t)0x001FF000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_rx_fir_coeff_6 << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_1_M_COEFF_2_ADDR,  ((uint32_t)iqdc_rx_fir_coeff_8 << 23) |((uint32_t)iqdc_rx_fir_coeff_7 << 12) |((uint32_t)iqdc_rx_fir_coeff_6 << 0));
}

__INLINE void rfic_wrap_iqdc_rx_1_m_coeff_2_unpack(uint16_t* iqdc_rx_fir_coeff_8, uint16_t* iqdc_rx_fir_coeff_7, uint16_t* iqdc_rx_fir_coeff_6)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_1_M_COEFF_2_ADDR);

	*iqdc_rx_fir_coeff_8 = (localVal & ((uint32_t)0xFF800000)) >>  23;
	*iqdc_rx_fir_coeff_7 = (localVal & ((uint32_t)0x001FF000)) >>  12;
	*iqdc_rx_fir_coeff_6 = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint16_t rfic_wrap_iqdc_rx_1_m_coeff_2_iqdc_rx_fir_coeff_8_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_1_M_COEFF_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFF800000)) >> 23);
}
__INLINE void rfic_wrap_iqdc_rx_1_m_coeff_2_iqdc_rx_fir_coeff_8_setf(uint16_t iqdcrxfircoeff8)
{
	ASSERT_ERR((((uint32_t)iqdcrxfircoeff8 << 23) & ~((uint32_t)0xFF800000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_1_M_COEFF_2_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_RX_1_M_COEFF_2_ADDR) & ~((uint32_t)0xFF800000)) | ((uint32_t)iqdcrxfircoeff8 <<23));
}
__INLINE uint16_t rfic_wrap_iqdc_rx_1_m_coeff_2_iqdc_rx_fir_coeff_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_1_M_COEFF_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x001FF000)) >> 12);
}
__INLINE void rfic_wrap_iqdc_rx_1_m_coeff_2_iqdc_rx_fir_coeff_7_setf(uint16_t iqdcrxfircoeff7)
{
	ASSERT_ERR((((uint32_t)iqdcrxfircoeff7 << 12) & ~((uint32_t)0x001FF000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_1_M_COEFF_2_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_RX_1_M_COEFF_2_ADDR) & ~((uint32_t)0x001FF000)) | ((uint32_t)iqdcrxfircoeff7 <<12));
}
__INLINE uint16_t rfic_wrap_iqdc_rx_1_m_coeff_2_iqdc_rx_fir_coeff_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_1_M_COEFF_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}
__INLINE void rfic_wrap_iqdc_rx_1_m_coeff_2_iqdc_rx_fir_coeff_6_setf(uint16_t iqdcrxfircoeff6)
{
	ASSERT_ERR((((uint32_t)iqdcrxfircoeff6 << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_1_M_COEFF_2_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_RX_1_M_COEFF_2_ADDR) & ~((uint32_t)0x000001FF)) | ((uint32_t)iqdcrxfircoeff6 <<0));
}

/**
 * @brief IQDC_RX_1_M_COEFF_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    20:12 IQDC_RX_FIR_COEFF_10      0x0
 *    08:00 IQDC_RX_FIR_COEFF_9       0x0
 * </pre>
 */
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_3_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x000001CC)
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_3_OFFSET      0x000001CC
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_3_INDEX       0x00000073
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_3_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_iqdc_rx_1_m_coeff_3_get(void)
{
	return REG_PL_RD(RFIC_WRAP_IQDC_RX_1_M_COEFF_3_ADDR);
}

__INLINE void rfic_wrap_iqdc_rx_1_m_coeff_3_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_IQDC_RX_1_M_COEFF_3_ADDR, value);
}

// field definitions
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_3_IQDC_RX_FIR_COEFF_10_MASK    ((uint32_t)0x001FF000)
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_3_IQDC_RX_FIR_COEFF_10_LSB    12
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_3_IQDC_RX_FIR_COEFF_10_WIDTH    ((uint32_t)0x00000009)
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_3_IQDC_RX_FIR_COEFF_9_MASK    ((uint32_t)0x000001FF)
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_3_IQDC_RX_FIR_COEFF_9_LSB    0
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_3_IQDC_RX_FIR_COEFF_9_WIDTH    ((uint32_t)0x00000009)

#define RFIC_WRAP_IQDC_RX_1_M_COEFF_3_IQDC_RX_FIR_COEFF_10_RST    0x0
#define RFIC_WRAP_IQDC_RX_1_M_COEFF_3_IQDC_RX_FIR_COEFF_9_RST    0x0

__INLINE void rfic_wrap_iqdc_rx_1_m_coeff_3_pack(uint16_t iqdc_rx_fir_coeff_10, uint16_t iqdc_rx_fir_coeff_9)
{
	ASSERT_ERR((((uint32_t)iqdc_rx_fir_coeff_10 << 12) & ~((uint32_t)0x001FF000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_rx_fir_coeff_9 << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_1_M_COEFF_3_ADDR,  ((uint32_t)iqdc_rx_fir_coeff_10 << 12) |((uint32_t)iqdc_rx_fir_coeff_9 << 0));
}

__INLINE void rfic_wrap_iqdc_rx_1_m_coeff_3_unpack(uint16_t* iqdc_rx_fir_coeff_10, uint16_t* iqdc_rx_fir_coeff_9)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_1_M_COEFF_3_ADDR);

	*iqdc_rx_fir_coeff_10 = (localVal & ((uint32_t)0x001FF000)) >>  12;
	*iqdc_rx_fir_coeff_9 = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint16_t rfic_wrap_iqdc_rx_1_m_coeff_3_iqdc_rx_fir_coeff_10_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_1_M_COEFF_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x001FF000)) >> 12);
}
__INLINE void rfic_wrap_iqdc_rx_1_m_coeff_3_iqdc_rx_fir_coeff_10_setf(uint16_t iqdcrxfircoeff10)
{
	ASSERT_ERR((((uint32_t)iqdcrxfircoeff10 << 12) & ~((uint32_t)0x001FF000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_1_M_COEFF_3_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_RX_1_M_COEFF_3_ADDR) & ~((uint32_t)0x001FF000)) | ((uint32_t)iqdcrxfircoeff10 <<12));
}
__INLINE uint16_t rfic_wrap_iqdc_rx_1_m_coeff_3_iqdc_rx_fir_coeff_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_1_M_COEFF_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}
__INLINE void rfic_wrap_iqdc_rx_1_m_coeff_3_iqdc_rx_fir_coeff_9_setf(uint16_t iqdcrxfircoeff9)
{
	ASSERT_ERR((((uint32_t)iqdcrxfircoeff9 << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_1_M_COEFF_3_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_RX_1_M_COEFF_3_ADDR) & ~((uint32_t)0x000001FF)) | ((uint32_t)iqdcrxfircoeff9 <<0));
}

/**
 * @brief IQDC_RX_2_M_GAIN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26:16 IQDC_RX_PHASE_GAIN        0x0
 *    10:00 IQDC_RX_AMP_GAIN          0x0
 * </pre>
 */
#define RFIC_WRAP_IQDC_RX_2_M_GAIN_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x000001D0)
#define RFIC_WRAP_IQDC_RX_2_M_GAIN_OFFSET      0x000001D0
#define RFIC_WRAP_IQDC_RX_2_M_GAIN_INDEX       0x00000074
#define RFIC_WRAP_IQDC_RX_2_M_GAIN_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_iqdc_rx_2_m_gain_get(void)
{
	return REG_PL_RD(RFIC_WRAP_IQDC_RX_2_M_GAIN_ADDR);
}

__INLINE void rfic_wrap_iqdc_rx_2_m_gain_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_IQDC_RX_2_M_GAIN_ADDR, value);
}

// field definitions
#define RFIC_WRAP_IQDC_RX_2_M_GAIN_IQDC_RX_PHASE_GAIN_MASK    ((uint32_t)0x07FF0000)
#define RFIC_WRAP_IQDC_RX_2_M_GAIN_IQDC_RX_PHASE_GAIN_LSB    16
#define RFIC_WRAP_IQDC_RX_2_M_GAIN_IQDC_RX_PHASE_GAIN_WIDTH    ((uint32_t)0x0000000B)
#define RFIC_WRAP_IQDC_RX_2_M_GAIN_IQDC_RX_AMP_GAIN_MASK    ((uint32_t)0x000007FF)
#define RFIC_WRAP_IQDC_RX_2_M_GAIN_IQDC_RX_AMP_GAIN_LSB    0
#define RFIC_WRAP_IQDC_RX_2_M_GAIN_IQDC_RX_AMP_GAIN_WIDTH    ((uint32_t)0x0000000B)

#define RFIC_WRAP_IQDC_RX_2_M_GAIN_IQDC_RX_PHASE_GAIN_RST    0x0
#define RFIC_WRAP_IQDC_RX_2_M_GAIN_IQDC_RX_AMP_GAIN_RST    0x0

__INLINE void rfic_wrap_iqdc_rx_2_m_gain_pack(uint16_t iqdc_rx_phase_gain, uint16_t iqdc_rx_amp_gain)
{
	ASSERT_ERR((((uint32_t)iqdc_rx_phase_gain << 16) & ~((uint32_t)0x07FF0000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_rx_amp_gain << 0) & ~((uint32_t)0x000007FF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_2_M_GAIN_ADDR,  ((uint32_t)iqdc_rx_phase_gain << 16) |((uint32_t)iqdc_rx_amp_gain << 0));
}

__INLINE void rfic_wrap_iqdc_rx_2_m_gain_unpack(uint16_t* iqdc_rx_phase_gain, uint16_t* iqdc_rx_amp_gain)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_2_M_GAIN_ADDR);

	*iqdc_rx_phase_gain = (localVal & ((uint32_t)0x07FF0000)) >>  16;
	*iqdc_rx_amp_gain = (localVal & ((uint32_t)0x000007FF)) >>  0;
}

__INLINE uint16_t rfic_wrap_iqdc_rx_2_m_gain_iqdc_rx_phase_gain_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_2_M_GAIN_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x07FF0000)) >> 16);
}
__INLINE void rfic_wrap_iqdc_rx_2_m_gain_iqdc_rx_phase_gain_setf(uint16_t iqdcrxphasegain)
{
	ASSERT_ERR((((uint32_t)iqdcrxphasegain << 16) & ~((uint32_t)0x07FF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_2_M_GAIN_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_RX_2_M_GAIN_ADDR) & ~((uint32_t)0x07FF0000)) | ((uint32_t)iqdcrxphasegain <<16));
}
__INLINE uint16_t rfic_wrap_iqdc_rx_2_m_gain_iqdc_rx_amp_gain_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_2_M_GAIN_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000007FF)) >> 0);
}
__INLINE void rfic_wrap_iqdc_rx_2_m_gain_iqdc_rx_amp_gain_setf(uint16_t iqdcrxampgain)
{
	ASSERT_ERR((((uint32_t)iqdcrxampgain << 0) & ~((uint32_t)0x000007FF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_2_M_GAIN_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_RX_2_M_GAIN_ADDR) & ~((uint32_t)0x000007FF)) | ((uint32_t)iqdcrxampgain <<0));
}

/**
 * @brief IQDC_RX_2_M_DC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 IQDC_RX_DCQ               0x0
 *    11:00 IQDC_RX_DCI               0x0
 * </pre>
 */
#define RFIC_WRAP_IQDC_RX_2_M_DC_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x000001D4)
#define RFIC_WRAP_IQDC_RX_2_M_DC_OFFSET      0x000001D4
#define RFIC_WRAP_IQDC_RX_2_M_DC_INDEX       0x00000075
#define RFIC_WRAP_IQDC_RX_2_M_DC_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_iqdc_rx_2_m_dc_get(void)
{
	return REG_PL_RD(RFIC_WRAP_IQDC_RX_2_M_DC_ADDR);
}

__INLINE void rfic_wrap_iqdc_rx_2_m_dc_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_IQDC_RX_2_M_DC_ADDR, value);
}

// field definitions
#define RFIC_WRAP_IQDC_RX_2_M_DC_IQDC_RX_DCQ_MASK    ((uint32_t)0x0FFF0000)
#define RFIC_WRAP_IQDC_RX_2_M_DC_IQDC_RX_DCQ_LSB    16
#define RFIC_WRAP_IQDC_RX_2_M_DC_IQDC_RX_DCQ_WIDTH    ((uint32_t)0x0000000C)
#define RFIC_WRAP_IQDC_RX_2_M_DC_IQDC_RX_DCI_MASK    ((uint32_t)0x00000FFF)
#define RFIC_WRAP_IQDC_RX_2_M_DC_IQDC_RX_DCI_LSB    0
#define RFIC_WRAP_IQDC_RX_2_M_DC_IQDC_RX_DCI_WIDTH    ((uint32_t)0x0000000C)

#define RFIC_WRAP_IQDC_RX_2_M_DC_IQDC_RX_DCQ_RST    0x0
#define RFIC_WRAP_IQDC_RX_2_M_DC_IQDC_RX_DCI_RST    0x0

__INLINE void rfic_wrap_iqdc_rx_2_m_dc_pack(uint16_t iqdc_rx_dcq, uint16_t iqdc_rx_dci)
{
	ASSERT_ERR((((uint32_t)iqdc_rx_dcq << 16) & ~((uint32_t)0x0FFF0000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_rx_dci << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_2_M_DC_ADDR,  ((uint32_t)iqdc_rx_dcq << 16) |((uint32_t)iqdc_rx_dci << 0));
}

__INLINE void rfic_wrap_iqdc_rx_2_m_dc_unpack(uint16_t* iqdc_rx_dcq, uint16_t* iqdc_rx_dci)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_2_M_DC_ADDR);

	*iqdc_rx_dcq = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*iqdc_rx_dci = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t rfic_wrap_iqdc_rx_2_m_dc_iqdc_rx_dcq_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_2_M_DC_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE void rfic_wrap_iqdc_rx_2_m_dc_iqdc_rx_dcq_setf(uint16_t iqdcrxdcq)
{
	ASSERT_ERR((((uint32_t)iqdcrxdcq << 16) & ~((uint32_t)0x0FFF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_2_M_DC_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_RX_2_M_DC_ADDR) & ~((uint32_t)0x0FFF0000)) | ((uint32_t)iqdcrxdcq <<16));
}
__INLINE uint16_t rfic_wrap_iqdc_rx_2_m_dc_iqdc_rx_dci_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_2_M_DC_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}
__INLINE void rfic_wrap_iqdc_rx_2_m_dc_iqdc_rx_dci_setf(uint16_t iqdcrxdci)
{
	ASSERT_ERR((((uint32_t)iqdcrxdci << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_2_M_DC_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_RX_2_M_DC_ADDR) & ~((uint32_t)0x00000FFF)) | ((uint32_t)iqdcrxdci <<0));
}

/**
 * @brief IQDC_RX_2_M_COEFF_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:23 IQDC_RX_FIR_COEFF_2       0x0
 *    20:12 IQDC_RX_FIR_COEFF_1       0x0
 *    08:00 IQDC_RX_FIR_COEFF_0       0x0
 * </pre>
 */
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_0_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x000001D8)
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_0_OFFSET      0x000001D8
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_0_INDEX       0x00000076
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_0_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_iqdc_rx_2_m_coeff_0_get(void)
{
	return REG_PL_RD(RFIC_WRAP_IQDC_RX_2_M_COEFF_0_ADDR);
}

__INLINE void rfic_wrap_iqdc_rx_2_m_coeff_0_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_IQDC_RX_2_M_COEFF_0_ADDR, value);
}

// field definitions
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_0_IQDC_RX_FIR_COEFF_2_MASK    ((uint32_t)0xFF800000)
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_0_IQDC_RX_FIR_COEFF_2_LSB    23
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_0_IQDC_RX_FIR_COEFF_2_WIDTH    ((uint32_t)0x00000009)
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_0_IQDC_RX_FIR_COEFF_1_MASK    ((uint32_t)0x001FF000)
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_0_IQDC_RX_FIR_COEFF_1_LSB    12
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_0_IQDC_RX_FIR_COEFF_1_WIDTH    ((uint32_t)0x00000009)
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_0_IQDC_RX_FIR_COEFF_0_MASK    ((uint32_t)0x000001FF)
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_0_IQDC_RX_FIR_COEFF_0_LSB    0
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_0_IQDC_RX_FIR_COEFF_0_WIDTH    ((uint32_t)0x00000009)

#define RFIC_WRAP_IQDC_RX_2_M_COEFF_0_IQDC_RX_FIR_COEFF_2_RST    0x0
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_0_IQDC_RX_FIR_COEFF_1_RST    0x0
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_0_IQDC_RX_FIR_COEFF_0_RST    0x0

__INLINE void rfic_wrap_iqdc_rx_2_m_coeff_0_pack(uint16_t iqdc_rx_fir_coeff_2, uint16_t iqdc_rx_fir_coeff_1, uint16_t iqdc_rx_fir_coeff_0)
{
	ASSERT_ERR((((uint32_t)iqdc_rx_fir_coeff_2 << 23) & ~((uint32_t)0xFF800000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_rx_fir_coeff_1 << 12) & ~((uint32_t)0x001FF000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_rx_fir_coeff_0 << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_2_M_COEFF_0_ADDR,  ((uint32_t)iqdc_rx_fir_coeff_2 << 23) |((uint32_t)iqdc_rx_fir_coeff_1 << 12) |((uint32_t)iqdc_rx_fir_coeff_0 << 0));
}

__INLINE void rfic_wrap_iqdc_rx_2_m_coeff_0_unpack(uint16_t* iqdc_rx_fir_coeff_2, uint16_t* iqdc_rx_fir_coeff_1, uint16_t* iqdc_rx_fir_coeff_0)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_2_M_COEFF_0_ADDR);

	*iqdc_rx_fir_coeff_2 = (localVal & ((uint32_t)0xFF800000)) >>  23;
	*iqdc_rx_fir_coeff_1 = (localVal & ((uint32_t)0x001FF000)) >>  12;
	*iqdc_rx_fir_coeff_0 = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint16_t rfic_wrap_iqdc_rx_2_m_coeff_0_iqdc_rx_fir_coeff_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_2_M_COEFF_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFF800000)) >> 23);
}
__INLINE void rfic_wrap_iqdc_rx_2_m_coeff_0_iqdc_rx_fir_coeff_2_setf(uint16_t iqdcrxfircoeff2)
{
	ASSERT_ERR((((uint32_t)iqdcrxfircoeff2 << 23) & ~((uint32_t)0xFF800000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_2_M_COEFF_0_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_RX_2_M_COEFF_0_ADDR) & ~((uint32_t)0xFF800000)) | ((uint32_t)iqdcrxfircoeff2 <<23));
}
__INLINE uint16_t rfic_wrap_iqdc_rx_2_m_coeff_0_iqdc_rx_fir_coeff_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_2_M_COEFF_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x001FF000)) >> 12);
}
__INLINE void rfic_wrap_iqdc_rx_2_m_coeff_0_iqdc_rx_fir_coeff_1_setf(uint16_t iqdcrxfircoeff1)
{
	ASSERT_ERR((((uint32_t)iqdcrxfircoeff1 << 12) & ~((uint32_t)0x001FF000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_2_M_COEFF_0_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_RX_2_M_COEFF_0_ADDR) & ~((uint32_t)0x001FF000)) | ((uint32_t)iqdcrxfircoeff1 <<12));
}
__INLINE uint16_t rfic_wrap_iqdc_rx_2_m_coeff_0_iqdc_rx_fir_coeff_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_2_M_COEFF_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}
__INLINE void rfic_wrap_iqdc_rx_2_m_coeff_0_iqdc_rx_fir_coeff_0_setf(uint16_t iqdcrxfircoeff0)
{
	ASSERT_ERR((((uint32_t)iqdcrxfircoeff0 << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_2_M_COEFF_0_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_RX_2_M_COEFF_0_ADDR) & ~((uint32_t)0x000001FF)) | ((uint32_t)iqdcrxfircoeff0 <<0));
}

/**
 * @brief IQDC_RX_2_M_COEFF_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:23 IQDC_RX_FIR_COEFF_5       0x0
 *    20:12 IQDC_RX_FIR_COEFF_4       0x0
 *    08:00 IQDC_RX_FIR_COEFF_3       0x0
 * </pre>
 */
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_1_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x000001DC)
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_1_OFFSET      0x000001DC
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_1_INDEX       0x00000077
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_1_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_iqdc_rx_2_m_coeff_1_get(void)
{
	return REG_PL_RD(RFIC_WRAP_IQDC_RX_2_M_COEFF_1_ADDR);
}

__INLINE void rfic_wrap_iqdc_rx_2_m_coeff_1_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_IQDC_RX_2_M_COEFF_1_ADDR, value);
}

// field definitions
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_1_IQDC_RX_FIR_COEFF_5_MASK    ((uint32_t)0xFF800000)
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_1_IQDC_RX_FIR_COEFF_5_LSB    23
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_1_IQDC_RX_FIR_COEFF_5_WIDTH    ((uint32_t)0x00000009)
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_1_IQDC_RX_FIR_COEFF_4_MASK    ((uint32_t)0x001FF000)
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_1_IQDC_RX_FIR_COEFF_4_LSB    12
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_1_IQDC_RX_FIR_COEFF_4_WIDTH    ((uint32_t)0x00000009)
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_1_IQDC_RX_FIR_COEFF_3_MASK    ((uint32_t)0x000001FF)
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_1_IQDC_RX_FIR_COEFF_3_LSB    0
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_1_IQDC_RX_FIR_COEFF_3_WIDTH    ((uint32_t)0x00000009)

#define RFIC_WRAP_IQDC_RX_2_M_COEFF_1_IQDC_RX_FIR_COEFF_5_RST    0x0
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_1_IQDC_RX_FIR_COEFF_4_RST    0x0
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_1_IQDC_RX_FIR_COEFF_3_RST    0x0

__INLINE void rfic_wrap_iqdc_rx_2_m_coeff_1_pack(uint16_t iqdc_rx_fir_coeff_5, uint16_t iqdc_rx_fir_coeff_4, uint16_t iqdc_rx_fir_coeff_3)
{
	ASSERT_ERR((((uint32_t)iqdc_rx_fir_coeff_5 << 23) & ~((uint32_t)0xFF800000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_rx_fir_coeff_4 << 12) & ~((uint32_t)0x001FF000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_rx_fir_coeff_3 << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_2_M_COEFF_1_ADDR,  ((uint32_t)iqdc_rx_fir_coeff_5 << 23) |((uint32_t)iqdc_rx_fir_coeff_4 << 12) |((uint32_t)iqdc_rx_fir_coeff_3 << 0));
}

__INLINE void rfic_wrap_iqdc_rx_2_m_coeff_1_unpack(uint16_t* iqdc_rx_fir_coeff_5, uint16_t* iqdc_rx_fir_coeff_4, uint16_t* iqdc_rx_fir_coeff_3)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_2_M_COEFF_1_ADDR);

	*iqdc_rx_fir_coeff_5 = (localVal & ((uint32_t)0xFF800000)) >>  23;
	*iqdc_rx_fir_coeff_4 = (localVal & ((uint32_t)0x001FF000)) >>  12;
	*iqdc_rx_fir_coeff_3 = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint16_t rfic_wrap_iqdc_rx_2_m_coeff_1_iqdc_rx_fir_coeff_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_2_M_COEFF_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFF800000)) >> 23);
}
__INLINE void rfic_wrap_iqdc_rx_2_m_coeff_1_iqdc_rx_fir_coeff_5_setf(uint16_t iqdcrxfircoeff5)
{
	ASSERT_ERR((((uint32_t)iqdcrxfircoeff5 << 23) & ~((uint32_t)0xFF800000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_2_M_COEFF_1_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_RX_2_M_COEFF_1_ADDR) & ~((uint32_t)0xFF800000)) | ((uint32_t)iqdcrxfircoeff5 <<23));
}
__INLINE uint16_t rfic_wrap_iqdc_rx_2_m_coeff_1_iqdc_rx_fir_coeff_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_2_M_COEFF_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x001FF000)) >> 12);
}
__INLINE void rfic_wrap_iqdc_rx_2_m_coeff_1_iqdc_rx_fir_coeff_4_setf(uint16_t iqdcrxfircoeff4)
{
	ASSERT_ERR((((uint32_t)iqdcrxfircoeff4 << 12) & ~((uint32_t)0x001FF000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_2_M_COEFF_1_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_RX_2_M_COEFF_1_ADDR) & ~((uint32_t)0x001FF000)) | ((uint32_t)iqdcrxfircoeff4 <<12));
}
__INLINE uint16_t rfic_wrap_iqdc_rx_2_m_coeff_1_iqdc_rx_fir_coeff_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_2_M_COEFF_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}
__INLINE void rfic_wrap_iqdc_rx_2_m_coeff_1_iqdc_rx_fir_coeff_3_setf(uint16_t iqdcrxfircoeff3)
{
	ASSERT_ERR((((uint32_t)iqdcrxfircoeff3 << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_2_M_COEFF_1_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_RX_2_M_COEFF_1_ADDR) & ~((uint32_t)0x000001FF)) | ((uint32_t)iqdcrxfircoeff3 <<0));
}

/**
 * @brief IQDC_RX_2_M_COEFF_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:23 IQDC_RX_FIR_COEFF_8       0x0
 *    20:12 IQDC_RX_FIR_COEFF_7       0x0
 *    08:00 IQDC_RX_FIR_COEFF_6       0x0
 * </pre>
 */
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_2_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x000001E0)
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_2_OFFSET      0x000001E0
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_2_INDEX       0x00000078
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_2_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_iqdc_rx_2_m_coeff_2_get(void)
{
	return REG_PL_RD(RFIC_WRAP_IQDC_RX_2_M_COEFF_2_ADDR);
}

__INLINE void rfic_wrap_iqdc_rx_2_m_coeff_2_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_IQDC_RX_2_M_COEFF_2_ADDR, value);
}

// field definitions
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_2_IQDC_RX_FIR_COEFF_8_MASK    ((uint32_t)0xFF800000)
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_2_IQDC_RX_FIR_COEFF_8_LSB    23
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_2_IQDC_RX_FIR_COEFF_8_WIDTH    ((uint32_t)0x00000009)
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_2_IQDC_RX_FIR_COEFF_7_MASK    ((uint32_t)0x001FF000)
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_2_IQDC_RX_FIR_COEFF_7_LSB    12
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_2_IQDC_RX_FIR_COEFF_7_WIDTH    ((uint32_t)0x00000009)
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_2_IQDC_RX_FIR_COEFF_6_MASK    ((uint32_t)0x000001FF)
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_2_IQDC_RX_FIR_COEFF_6_LSB    0
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_2_IQDC_RX_FIR_COEFF_6_WIDTH    ((uint32_t)0x00000009)

#define RFIC_WRAP_IQDC_RX_2_M_COEFF_2_IQDC_RX_FIR_COEFF_8_RST    0x0
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_2_IQDC_RX_FIR_COEFF_7_RST    0x0
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_2_IQDC_RX_FIR_COEFF_6_RST    0x0

__INLINE void rfic_wrap_iqdc_rx_2_m_coeff_2_pack(uint16_t iqdc_rx_fir_coeff_8, uint16_t iqdc_rx_fir_coeff_7, uint16_t iqdc_rx_fir_coeff_6)
{
	ASSERT_ERR((((uint32_t)iqdc_rx_fir_coeff_8 << 23) & ~((uint32_t)0xFF800000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_rx_fir_coeff_7 << 12) & ~((uint32_t)0x001FF000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_rx_fir_coeff_6 << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_2_M_COEFF_2_ADDR,  ((uint32_t)iqdc_rx_fir_coeff_8 << 23) |((uint32_t)iqdc_rx_fir_coeff_7 << 12) |((uint32_t)iqdc_rx_fir_coeff_6 << 0));
}

__INLINE void rfic_wrap_iqdc_rx_2_m_coeff_2_unpack(uint16_t* iqdc_rx_fir_coeff_8, uint16_t* iqdc_rx_fir_coeff_7, uint16_t* iqdc_rx_fir_coeff_6)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_2_M_COEFF_2_ADDR);

	*iqdc_rx_fir_coeff_8 = (localVal & ((uint32_t)0xFF800000)) >>  23;
	*iqdc_rx_fir_coeff_7 = (localVal & ((uint32_t)0x001FF000)) >>  12;
	*iqdc_rx_fir_coeff_6 = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint16_t rfic_wrap_iqdc_rx_2_m_coeff_2_iqdc_rx_fir_coeff_8_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_2_M_COEFF_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFF800000)) >> 23);
}
__INLINE void rfic_wrap_iqdc_rx_2_m_coeff_2_iqdc_rx_fir_coeff_8_setf(uint16_t iqdcrxfircoeff8)
{
	ASSERT_ERR((((uint32_t)iqdcrxfircoeff8 << 23) & ~((uint32_t)0xFF800000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_2_M_COEFF_2_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_RX_2_M_COEFF_2_ADDR) & ~((uint32_t)0xFF800000)) | ((uint32_t)iqdcrxfircoeff8 <<23));
}
__INLINE uint16_t rfic_wrap_iqdc_rx_2_m_coeff_2_iqdc_rx_fir_coeff_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_2_M_COEFF_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x001FF000)) >> 12);
}
__INLINE void rfic_wrap_iqdc_rx_2_m_coeff_2_iqdc_rx_fir_coeff_7_setf(uint16_t iqdcrxfircoeff7)
{
	ASSERT_ERR((((uint32_t)iqdcrxfircoeff7 << 12) & ~((uint32_t)0x001FF000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_2_M_COEFF_2_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_RX_2_M_COEFF_2_ADDR) & ~((uint32_t)0x001FF000)) | ((uint32_t)iqdcrxfircoeff7 <<12));
}
__INLINE uint16_t rfic_wrap_iqdc_rx_2_m_coeff_2_iqdc_rx_fir_coeff_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_2_M_COEFF_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}
__INLINE void rfic_wrap_iqdc_rx_2_m_coeff_2_iqdc_rx_fir_coeff_6_setf(uint16_t iqdcrxfircoeff6)
{
	ASSERT_ERR((((uint32_t)iqdcrxfircoeff6 << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_2_M_COEFF_2_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_RX_2_M_COEFF_2_ADDR) & ~((uint32_t)0x000001FF)) | ((uint32_t)iqdcrxfircoeff6 <<0));
}

/**
 * @brief IQDC_RX_2_M_COEFF_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    20:12 IQDC_RX_FIR_COEFF_10      0x0
 *    08:00 IQDC_RX_FIR_COEFF_9       0x0
 * </pre>
 */
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_3_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x000001E4)
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_3_OFFSET      0x000001E4
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_3_INDEX       0x00000079
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_3_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_iqdc_rx_2_m_coeff_3_get(void)
{
	return REG_PL_RD(RFIC_WRAP_IQDC_RX_2_M_COEFF_3_ADDR);
}

__INLINE void rfic_wrap_iqdc_rx_2_m_coeff_3_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_IQDC_RX_2_M_COEFF_3_ADDR, value);
}

// field definitions
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_3_IQDC_RX_FIR_COEFF_10_MASK    ((uint32_t)0x001FF000)
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_3_IQDC_RX_FIR_COEFF_10_LSB    12
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_3_IQDC_RX_FIR_COEFF_10_WIDTH    ((uint32_t)0x00000009)
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_3_IQDC_RX_FIR_COEFF_9_MASK    ((uint32_t)0x000001FF)
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_3_IQDC_RX_FIR_COEFF_9_LSB    0
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_3_IQDC_RX_FIR_COEFF_9_WIDTH    ((uint32_t)0x00000009)

#define RFIC_WRAP_IQDC_RX_2_M_COEFF_3_IQDC_RX_FIR_COEFF_10_RST    0x0
#define RFIC_WRAP_IQDC_RX_2_M_COEFF_3_IQDC_RX_FIR_COEFF_9_RST    0x0

__INLINE void rfic_wrap_iqdc_rx_2_m_coeff_3_pack(uint16_t iqdc_rx_fir_coeff_10, uint16_t iqdc_rx_fir_coeff_9)
{
	ASSERT_ERR((((uint32_t)iqdc_rx_fir_coeff_10 << 12) & ~((uint32_t)0x001FF000)) == 0);
	ASSERT_ERR((((uint32_t)iqdc_rx_fir_coeff_9 << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_2_M_COEFF_3_ADDR,  ((uint32_t)iqdc_rx_fir_coeff_10 << 12) |((uint32_t)iqdc_rx_fir_coeff_9 << 0));
}

__INLINE void rfic_wrap_iqdc_rx_2_m_coeff_3_unpack(uint16_t* iqdc_rx_fir_coeff_10, uint16_t* iqdc_rx_fir_coeff_9)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_2_M_COEFF_3_ADDR);

	*iqdc_rx_fir_coeff_10 = (localVal & ((uint32_t)0x001FF000)) >>  12;
	*iqdc_rx_fir_coeff_9 = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint16_t rfic_wrap_iqdc_rx_2_m_coeff_3_iqdc_rx_fir_coeff_10_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_2_M_COEFF_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x001FF000)) >> 12);
}
__INLINE void rfic_wrap_iqdc_rx_2_m_coeff_3_iqdc_rx_fir_coeff_10_setf(uint16_t iqdcrxfircoeff10)
{
	ASSERT_ERR((((uint32_t)iqdcrxfircoeff10 << 12) & ~((uint32_t)0x001FF000)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_2_M_COEFF_3_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_RX_2_M_COEFF_3_ADDR) & ~((uint32_t)0x001FF000)) | ((uint32_t)iqdcrxfircoeff10 <<12));
}
__INLINE uint16_t rfic_wrap_iqdc_rx_2_m_coeff_3_iqdc_rx_fir_coeff_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_IQDC_RX_2_M_COEFF_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}
__INLINE void rfic_wrap_iqdc_rx_2_m_coeff_3_iqdc_rx_fir_coeff_9_setf(uint16_t iqdcrxfircoeff9)
{
	ASSERT_ERR((((uint32_t)iqdcrxfircoeff9 << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(RFIC_WRAP_IQDC_RX_2_M_COEFF_3_ADDR, (REG_PL_RD(RFIC_WRAP_IQDC_RX_2_M_COEFF_3_ADDR) & ~((uint32_t)0x000001FF)) | ((uint32_t)iqdcrxfircoeff9 <<0));
}

/**
 * @brief WIFI_RF_RX_CH_0_LNA_0_RSSI_THRES register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 RSSI_THRES_3              0x0
 *    23:16 RSSI_THRES_2              0x0
 *    15:08 RSSI_THRES_1              0x0
 *    07:00 RSSI_THRES_0              0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_RSSI_THRES_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000200)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_RSSI_THRES_OFFSET      0x00000200
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_RSSI_THRES_INDEX       0x00000080
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_RSSI_THRES_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_0_lna_0_rssi_thres_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_RSSI_THRES_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_0_rssi_thres_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_RSSI_THRES_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_RSSI_THRES_RSSI_THRES_3_MASK    ((uint32_t)0xFF000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_RSSI_THRES_RSSI_THRES_3_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_RSSI_THRES_RSSI_THRES_3_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_RSSI_THRES_RSSI_THRES_2_MASK    ((uint32_t)0x00FF0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_RSSI_THRES_RSSI_THRES_2_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_RSSI_THRES_RSSI_THRES_2_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_RSSI_THRES_RSSI_THRES_1_MASK    ((uint32_t)0x0000FF00)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_RSSI_THRES_RSSI_THRES_1_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_RSSI_THRES_RSSI_THRES_1_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_RSSI_THRES_RSSI_THRES_0_MASK    ((uint32_t)0x000000FF)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_RSSI_THRES_RSSI_THRES_0_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_RSSI_THRES_RSSI_THRES_0_WIDTH    ((uint32_t)0x00000008)

#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_RSSI_THRES_RSSI_THRES_3_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_RSSI_THRES_RSSI_THRES_2_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_RSSI_THRES_RSSI_THRES_1_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_RSSI_THRES_RSSI_THRES_0_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_0_rssi_thres_pack(uint8_t rssi_thres_3, uint8_t rssi_thres_2, uint8_t rssi_thres_1, uint8_t rssi_thres_0)
{
	ASSERT_ERR((((uint32_t)rssi_thres_3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_RSSI_THRES_ADDR,  ((uint32_t)rssi_thres_3 << 24) |((uint32_t)rssi_thres_2 << 16) |((uint32_t)rssi_thres_1 << 8) |((uint32_t)rssi_thres_0 << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_0_rssi_thres_unpack(uint8_t* rssi_thres_3, uint8_t* rssi_thres_2, uint8_t* rssi_thres_1, uint8_t* rssi_thres_0)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_RSSI_THRES_ADDR);

	*rssi_thres_3 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rssi_thres_2 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rssi_thres_1 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*rssi_thres_0 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_0_rssi_thres_rssi_thres_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_0_rssi_thres_rssi_thres_3_setf(uint8_t rssithres3)
{
	ASSERT_ERR((((uint32_t)rssithres3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_RSSI_THRES_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)rssithres3 <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_0_rssi_thres_rssi_thres_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_0_rssi_thres_rssi_thres_2_setf(uint8_t rssithres2)
{
	ASSERT_ERR((((uint32_t)rssithres2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_RSSI_THRES_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rssithres2 <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_0_rssi_thres_rssi_thres_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_0_rssi_thres_rssi_thres_1_setf(uint8_t rssithres1)
{
	ASSERT_ERR((((uint32_t)rssithres1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_RSSI_THRES_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)rssithres1 <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_0_rssi_thres_rssi_thres_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_0_rssi_thres_rssi_thres_0_setf(uint8_t rssithres0)
{
	ASSERT_ERR((((uint32_t)rssithres0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_0_RSSI_THRES_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)rssithres0 <<0));
}

/**
 * @brief WIFI_RF_RX_CH_0_LNA_1_RSSI_THRES register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 RSSI_THRES_3              0x0
 *    23:16 RSSI_THRES_2              0x0
 *    15:08 RSSI_THRES_1              0x0
 *    07:00 RSSI_THRES_0              0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_RSSI_THRES_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000204)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_RSSI_THRES_OFFSET      0x00000204
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_RSSI_THRES_INDEX       0x00000081
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_RSSI_THRES_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_0_lna_1_rssi_thres_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_RSSI_THRES_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_1_rssi_thres_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_RSSI_THRES_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_RSSI_THRES_RSSI_THRES_3_MASK    ((uint32_t)0xFF000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_RSSI_THRES_RSSI_THRES_3_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_RSSI_THRES_RSSI_THRES_3_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_RSSI_THRES_RSSI_THRES_2_MASK    ((uint32_t)0x00FF0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_RSSI_THRES_RSSI_THRES_2_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_RSSI_THRES_RSSI_THRES_2_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_RSSI_THRES_RSSI_THRES_1_MASK    ((uint32_t)0x0000FF00)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_RSSI_THRES_RSSI_THRES_1_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_RSSI_THRES_RSSI_THRES_1_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_RSSI_THRES_RSSI_THRES_0_MASK    ((uint32_t)0x000000FF)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_RSSI_THRES_RSSI_THRES_0_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_RSSI_THRES_RSSI_THRES_0_WIDTH    ((uint32_t)0x00000008)

#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_RSSI_THRES_RSSI_THRES_3_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_RSSI_THRES_RSSI_THRES_2_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_RSSI_THRES_RSSI_THRES_1_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_RSSI_THRES_RSSI_THRES_0_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_1_rssi_thres_pack(uint8_t rssi_thres_3, uint8_t rssi_thres_2, uint8_t rssi_thres_1, uint8_t rssi_thres_0)
{
	ASSERT_ERR((((uint32_t)rssi_thres_3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_RSSI_THRES_ADDR,  ((uint32_t)rssi_thres_3 << 24) |((uint32_t)rssi_thres_2 << 16) |((uint32_t)rssi_thres_1 << 8) |((uint32_t)rssi_thres_0 << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_1_rssi_thres_unpack(uint8_t* rssi_thres_3, uint8_t* rssi_thres_2, uint8_t* rssi_thres_1, uint8_t* rssi_thres_0)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_RSSI_THRES_ADDR);

	*rssi_thres_3 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rssi_thres_2 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rssi_thres_1 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*rssi_thres_0 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_1_rssi_thres_rssi_thres_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_1_rssi_thres_rssi_thres_3_setf(uint8_t rssithres3)
{
	ASSERT_ERR((((uint32_t)rssithres3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_RSSI_THRES_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)rssithres3 <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_1_rssi_thres_rssi_thres_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_1_rssi_thres_rssi_thres_2_setf(uint8_t rssithres2)
{
	ASSERT_ERR((((uint32_t)rssithres2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_RSSI_THRES_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rssithres2 <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_1_rssi_thres_rssi_thres_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_1_rssi_thres_rssi_thres_1_setf(uint8_t rssithres1)
{
	ASSERT_ERR((((uint32_t)rssithres1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_RSSI_THRES_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)rssithres1 <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_1_rssi_thres_rssi_thres_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_1_rssi_thres_rssi_thres_0_setf(uint8_t rssithres0)
{
	ASSERT_ERR((((uint32_t)rssithres0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_1_RSSI_THRES_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)rssithres0 <<0));
}

/**
 * @brief WIFI_RF_RX_CH_0_LNA_2_RSSI_THRES register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 RSSI_THRES_3              0x0
 *    23:16 RSSI_THRES_2              0x0
 *    15:08 RSSI_THRES_1              0x0
 *    07:00 RSSI_THRES_0              0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_RSSI_THRES_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000208)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_RSSI_THRES_OFFSET      0x00000208
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_RSSI_THRES_INDEX       0x00000082
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_RSSI_THRES_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_0_lna_2_rssi_thres_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_RSSI_THRES_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_2_rssi_thres_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_RSSI_THRES_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_RSSI_THRES_RSSI_THRES_3_MASK    ((uint32_t)0xFF000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_RSSI_THRES_RSSI_THRES_3_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_RSSI_THRES_RSSI_THRES_3_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_RSSI_THRES_RSSI_THRES_2_MASK    ((uint32_t)0x00FF0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_RSSI_THRES_RSSI_THRES_2_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_RSSI_THRES_RSSI_THRES_2_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_RSSI_THRES_RSSI_THRES_1_MASK    ((uint32_t)0x0000FF00)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_RSSI_THRES_RSSI_THRES_1_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_RSSI_THRES_RSSI_THRES_1_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_RSSI_THRES_RSSI_THRES_0_MASK    ((uint32_t)0x000000FF)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_RSSI_THRES_RSSI_THRES_0_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_RSSI_THRES_RSSI_THRES_0_WIDTH    ((uint32_t)0x00000008)

#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_RSSI_THRES_RSSI_THRES_3_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_RSSI_THRES_RSSI_THRES_2_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_RSSI_THRES_RSSI_THRES_1_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_RSSI_THRES_RSSI_THRES_0_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_2_rssi_thres_pack(uint8_t rssi_thres_3, uint8_t rssi_thres_2, uint8_t rssi_thres_1, uint8_t rssi_thres_0)
{
	ASSERT_ERR((((uint32_t)rssi_thres_3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_RSSI_THRES_ADDR,  ((uint32_t)rssi_thres_3 << 24) |((uint32_t)rssi_thres_2 << 16) |((uint32_t)rssi_thres_1 << 8) |((uint32_t)rssi_thres_0 << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_2_rssi_thres_unpack(uint8_t* rssi_thres_3, uint8_t* rssi_thres_2, uint8_t* rssi_thres_1, uint8_t* rssi_thres_0)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_RSSI_THRES_ADDR);

	*rssi_thres_3 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rssi_thres_2 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rssi_thres_1 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*rssi_thres_0 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_2_rssi_thres_rssi_thres_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_2_rssi_thres_rssi_thres_3_setf(uint8_t rssithres3)
{
	ASSERT_ERR((((uint32_t)rssithres3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_RSSI_THRES_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)rssithres3 <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_2_rssi_thres_rssi_thres_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_2_rssi_thres_rssi_thres_2_setf(uint8_t rssithres2)
{
	ASSERT_ERR((((uint32_t)rssithres2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_RSSI_THRES_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rssithres2 <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_2_rssi_thres_rssi_thres_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_2_rssi_thres_rssi_thres_1_setf(uint8_t rssithres1)
{
	ASSERT_ERR((((uint32_t)rssithres1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_RSSI_THRES_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)rssithres1 <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_2_rssi_thres_rssi_thres_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_2_rssi_thres_rssi_thres_0_setf(uint8_t rssithres0)
{
	ASSERT_ERR((((uint32_t)rssithres0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_2_RSSI_THRES_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)rssithres0 <<0));
}

/**
 * @brief WIFI_RF_RX_CH_0_LNA_3_RSSI_THRES register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 RSSI_THRES_3              0x0
 *    23:16 RSSI_THRES_2              0x0
 *    15:08 RSSI_THRES_1              0x0
 *    07:00 RSSI_THRES_0              0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_RSSI_THRES_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x0000020C)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_RSSI_THRES_OFFSET      0x0000020C
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_RSSI_THRES_INDEX       0x00000083
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_RSSI_THRES_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_0_lna_3_rssi_thres_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_RSSI_THRES_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_3_rssi_thres_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_RSSI_THRES_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_RSSI_THRES_RSSI_THRES_3_MASK    ((uint32_t)0xFF000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_RSSI_THRES_RSSI_THRES_3_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_RSSI_THRES_RSSI_THRES_3_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_RSSI_THRES_RSSI_THRES_2_MASK    ((uint32_t)0x00FF0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_RSSI_THRES_RSSI_THRES_2_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_RSSI_THRES_RSSI_THRES_2_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_RSSI_THRES_RSSI_THRES_1_MASK    ((uint32_t)0x0000FF00)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_RSSI_THRES_RSSI_THRES_1_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_RSSI_THRES_RSSI_THRES_1_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_RSSI_THRES_RSSI_THRES_0_MASK    ((uint32_t)0x000000FF)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_RSSI_THRES_RSSI_THRES_0_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_RSSI_THRES_RSSI_THRES_0_WIDTH    ((uint32_t)0x00000008)

#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_RSSI_THRES_RSSI_THRES_3_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_RSSI_THRES_RSSI_THRES_2_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_RSSI_THRES_RSSI_THRES_1_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_RSSI_THRES_RSSI_THRES_0_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_3_rssi_thres_pack(uint8_t rssi_thres_3, uint8_t rssi_thres_2, uint8_t rssi_thres_1, uint8_t rssi_thres_0)
{
	ASSERT_ERR((((uint32_t)rssi_thres_3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_RSSI_THRES_ADDR,  ((uint32_t)rssi_thres_3 << 24) |((uint32_t)rssi_thres_2 << 16) |((uint32_t)rssi_thres_1 << 8) |((uint32_t)rssi_thres_0 << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_3_rssi_thres_unpack(uint8_t* rssi_thres_3, uint8_t* rssi_thres_2, uint8_t* rssi_thres_1, uint8_t* rssi_thres_0)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_RSSI_THRES_ADDR);

	*rssi_thres_3 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rssi_thres_2 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rssi_thres_1 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*rssi_thres_0 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_3_rssi_thres_rssi_thres_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_3_rssi_thres_rssi_thres_3_setf(uint8_t rssithres3)
{
	ASSERT_ERR((((uint32_t)rssithres3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_RSSI_THRES_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)rssithres3 <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_3_rssi_thres_rssi_thres_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_3_rssi_thres_rssi_thres_2_setf(uint8_t rssithres2)
{
	ASSERT_ERR((((uint32_t)rssithres2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_RSSI_THRES_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rssithres2 <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_3_rssi_thres_rssi_thres_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_3_rssi_thres_rssi_thres_1_setf(uint8_t rssithres1)
{
	ASSERT_ERR((((uint32_t)rssithres1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_RSSI_THRES_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)rssithres1 <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_3_rssi_thres_rssi_thres_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_3_rssi_thres_rssi_thres_0_setf(uint8_t rssithres0)
{
	ASSERT_ERR((((uint32_t)rssithres0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_3_RSSI_THRES_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)rssithres0 <<0));
}

/**
 * @brief WIFI_RF_RX_CH_0_LNA_4_RSSI_THRES register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 RSSI_THRES_3              0x0
 *    23:16 RSSI_THRES_2              0x0
 *    15:08 RSSI_THRES_1              0x0
 *    07:00 RSSI_THRES_0              0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_RSSI_THRES_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000210)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_RSSI_THRES_OFFSET      0x00000210
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_RSSI_THRES_INDEX       0x00000084
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_RSSI_THRES_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_0_lna_4_rssi_thres_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_RSSI_THRES_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_4_rssi_thres_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_RSSI_THRES_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_RSSI_THRES_RSSI_THRES_3_MASK    ((uint32_t)0xFF000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_RSSI_THRES_RSSI_THRES_3_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_RSSI_THRES_RSSI_THRES_3_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_RSSI_THRES_RSSI_THRES_2_MASK    ((uint32_t)0x00FF0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_RSSI_THRES_RSSI_THRES_2_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_RSSI_THRES_RSSI_THRES_2_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_RSSI_THRES_RSSI_THRES_1_MASK    ((uint32_t)0x0000FF00)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_RSSI_THRES_RSSI_THRES_1_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_RSSI_THRES_RSSI_THRES_1_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_RSSI_THRES_RSSI_THRES_0_MASK    ((uint32_t)0x000000FF)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_RSSI_THRES_RSSI_THRES_0_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_RSSI_THRES_RSSI_THRES_0_WIDTH    ((uint32_t)0x00000008)

#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_RSSI_THRES_RSSI_THRES_3_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_RSSI_THRES_RSSI_THRES_2_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_RSSI_THRES_RSSI_THRES_1_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_RSSI_THRES_RSSI_THRES_0_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_4_rssi_thres_pack(uint8_t rssi_thres_3, uint8_t rssi_thres_2, uint8_t rssi_thres_1, uint8_t rssi_thres_0)
{
	ASSERT_ERR((((uint32_t)rssi_thres_3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_RSSI_THRES_ADDR,  ((uint32_t)rssi_thres_3 << 24) |((uint32_t)rssi_thres_2 << 16) |((uint32_t)rssi_thres_1 << 8) |((uint32_t)rssi_thres_0 << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_4_rssi_thres_unpack(uint8_t* rssi_thres_3, uint8_t* rssi_thres_2, uint8_t* rssi_thres_1, uint8_t* rssi_thres_0)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_RSSI_THRES_ADDR);

	*rssi_thres_3 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rssi_thres_2 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rssi_thres_1 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*rssi_thres_0 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_4_rssi_thres_rssi_thres_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_4_rssi_thres_rssi_thres_3_setf(uint8_t rssithres3)
{
	ASSERT_ERR((((uint32_t)rssithres3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_RSSI_THRES_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)rssithres3 <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_4_rssi_thres_rssi_thres_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_4_rssi_thres_rssi_thres_2_setf(uint8_t rssithres2)
{
	ASSERT_ERR((((uint32_t)rssithres2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_RSSI_THRES_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rssithres2 <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_4_rssi_thres_rssi_thres_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_4_rssi_thres_rssi_thres_1_setf(uint8_t rssithres1)
{
	ASSERT_ERR((((uint32_t)rssithres1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_RSSI_THRES_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)rssithres1 <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_4_rssi_thres_rssi_thres_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_4_rssi_thres_rssi_thres_0_setf(uint8_t rssithres0)
{
	ASSERT_ERR((((uint32_t)rssithres0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_4_RSSI_THRES_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)rssithres0 <<0));
}

/**
 * @brief WIFI_RF_RX_CH_0_LNA_5_RSSI_THRES register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 RSSI_THRES_3              0x0
 *    23:16 RSSI_THRES_2              0x0
 *    15:08 RSSI_THRES_1              0x0
 *    07:00 RSSI_THRES_0              0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_RSSI_THRES_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000214)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_RSSI_THRES_OFFSET      0x00000214
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_RSSI_THRES_INDEX       0x00000085
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_RSSI_THRES_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_0_lna_5_rssi_thres_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_RSSI_THRES_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_5_rssi_thres_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_RSSI_THRES_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_RSSI_THRES_RSSI_THRES_3_MASK    ((uint32_t)0xFF000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_RSSI_THRES_RSSI_THRES_3_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_RSSI_THRES_RSSI_THRES_3_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_RSSI_THRES_RSSI_THRES_2_MASK    ((uint32_t)0x00FF0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_RSSI_THRES_RSSI_THRES_2_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_RSSI_THRES_RSSI_THRES_2_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_RSSI_THRES_RSSI_THRES_1_MASK    ((uint32_t)0x0000FF00)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_RSSI_THRES_RSSI_THRES_1_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_RSSI_THRES_RSSI_THRES_1_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_RSSI_THRES_RSSI_THRES_0_MASK    ((uint32_t)0x000000FF)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_RSSI_THRES_RSSI_THRES_0_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_RSSI_THRES_RSSI_THRES_0_WIDTH    ((uint32_t)0x00000008)

#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_RSSI_THRES_RSSI_THRES_3_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_RSSI_THRES_RSSI_THRES_2_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_RSSI_THRES_RSSI_THRES_1_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_RSSI_THRES_RSSI_THRES_0_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_5_rssi_thres_pack(uint8_t rssi_thres_3, uint8_t rssi_thres_2, uint8_t rssi_thres_1, uint8_t rssi_thres_0)
{
	ASSERT_ERR((((uint32_t)rssi_thres_3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_RSSI_THRES_ADDR,  ((uint32_t)rssi_thres_3 << 24) |((uint32_t)rssi_thres_2 << 16) |((uint32_t)rssi_thres_1 << 8) |((uint32_t)rssi_thres_0 << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_5_rssi_thres_unpack(uint8_t* rssi_thres_3, uint8_t* rssi_thres_2, uint8_t* rssi_thres_1, uint8_t* rssi_thres_0)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_RSSI_THRES_ADDR);

	*rssi_thres_3 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rssi_thres_2 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rssi_thres_1 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*rssi_thres_0 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_5_rssi_thres_rssi_thres_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_5_rssi_thres_rssi_thres_3_setf(uint8_t rssithres3)
{
	ASSERT_ERR((((uint32_t)rssithres3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_RSSI_THRES_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)rssithres3 <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_5_rssi_thres_rssi_thres_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_5_rssi_thres_rssi_thres_2_setf(uint8_t rssithres2)
{
	ASSERT_ERR((((uint32_t)rssithres2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_RSSI_THRES_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rssithres2 <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_5_rssi_thres_rssi_thres_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_5_rssi_thres_rssi_thres_1_setf(uint8_t rssithres1)
{
	ASSERT_ERR((((uint32_t)rssithres1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_RSSI_THRES_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)rssithres1 <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_5_rssi_thres_rssi_thres_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_5_rssi_thres_rssi_thres_0_setf(uint8_t rssithres0)
{
	ASSERT_ERR((((uint32_t)rssithres0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_5_RSSI_THRES_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)rssithres0 <<0));
}

/**
 * @brief WIFI_RF_RX_CH_0_LNA_6_RSSI_THRES register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 RSSI_THRES_3              0x0
 *    23:16 RSSI_THRES_2              0x0
 *    15:08 RSSI_THRES_1              0x0
 *    07:00 RSSI_THRES_0              0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_RSSI_THRES_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000218)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_RSSI_THRES_OFFSET      0x00000218
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_RSSI_THRES_INDEX       0x00000086
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_RSSI_THRES_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_0_lna_6_rssi_thres_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_RSSI_THRES_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_6_rssi_thres_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_RSSI_THRES_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_RSSI_THRES_RSSI_THRES_3_MASK    ((uint32_t)0xFF000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_RSSI_THRES_RSSI_THRES_3_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_RSSI_THRES_RSSI_THRES_3_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_RSSI_THRES_RSSI_THRES_2_MASK    ((uint32_t)0x00FF0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_RSSI_THRES_RSSI_THRES_2_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_RSSI_THRES_RSSI_THRES_2_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_RSSI_THRES_RSSI_THRES_1_MASK    ((uint32_t)0x0000FF00)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_RSSI_THRES_RSSI_THRES_1_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_RSSI_THRES_RSSI_THRES_1_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_RSSI_THRES_RSSI_THRES_0_MASK    ((uint32_t)0x000000FF)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_RSSI_THRES_RSSI_THRES_0_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_RSSI_THRES_RSSI_THRES_0_WIDTH    ((uint32_t)0x00000008)

#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_RSSI_THRES_RSSI_THRES_3_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_RSSI_THRES_RSSI_THRES_2_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_RSSI_THRES_RSSI_THRES_1_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_RSSI_THRES_RSSI_THRES_0_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_6_rssi_thres_pack(uint8_t rssi_thres_3, uint8_t rssi_thres_2, uint8_t rssi_thres_1, uint8_t rssi_thres_0)
{
	ASSERT_ERR((((uint32_t)rssi_thres_3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_RSSI_THRES_ADDR,  ((uint32_t)rssi_thres_3 << 24) |((uint32_t)rssi_thres_2 << 16) |((uint32_t)rssi_thres_1 << 8) |((uint32_t)rssi_thres_0 << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_6_rssi_thres_unpack(uint8_t* rssi_thres_3, uint8_t* rssi_thres_2, uint8_t* rssi_thres_1, uint8_t* rssi_thres_0)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_RSSI_THRES_ADDR);

	*rssi_thres_3 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rssi_thres_2 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rssi_thres_1 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*rssi_thres_0 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_6_rssi_thres_rssi_thres_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_6_rssi_thres_rssi_thres_3_setf(uint8_t rssithres3)
{
	ASSERT_ERR((((uint32_t)rssithres3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_RSSI_THRES_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)rssithres3 <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_6_rssi_thres_rssi_thres_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_6_rssi_thres_rssi_thres_2_setf(uint8_t rssithres2)
{
	ASSERT_ERR((((uint32_t)rssithres2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_RSSI_THRES_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rssithres2 <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_6_rssi_thres_rssi_thres_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_6_rssi_thres_rssi_thres_1_setf(uint8_t rssithres1)
{
	ASSERT_ERR((((uint32_t)rssithres1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_RSSI_THRES_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)rssithres1 <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_6_rssi_thres_rssi_thres_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_6_rssi_thres_rssi_thres_0_setf(uint8_t rssithres0)
{
	ASSERT_ERR((((uint32_t)rssithres0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_6_RSSI_THRES_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)rssithres0 <<0));
}

/**
 * @brief WIFI_RF_RX_CH_0_LNA_7_RSSI_THRES register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 RSSI_THRES_3              0x0
 *    23:16 RSSI_THRES_2              0x0
 *    15:08 RSSI_THRES_1              0x0
 *    07:00 RSSI_THRES_0              0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_RSSI_THRES_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x0000021C)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_RSSI_THRES_OFFSET      0x0000021C
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_RSSI_THRES_INDEX       0x00000087
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_RSSI_THRES_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_0_lna_7_rssi_thres_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_RSSI_THRES_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_7_rssi_thres_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_RSSI_THRES_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_RSSI_THRES_RSSI_THRES_3_MASK    ((uint32_t)0xFF000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_RSSI_THRES_RSSI_THRES_3_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_RSSI_THRES_RSSI_THRES_3_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_RSSI_THRES_RSSI_THRES_2_MASK    ((uint32_t)0x00FF0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_RSSI_THRES_RSSI_THRES_2_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_RSSI_THRES_RSSI_THRES_2_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_RSSI_THRES_RSSI_THRES_1_MASK    ((uint32_t)0x0000FF00)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_RSSI_THRES_RSSI_THRES_1_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_RSSI_THRES_RSSI_THRES_1_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_RSSI_THRES_RSSI_THRES_0_MASK    ((uint32_t)0x000000FF)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_RSSI_THRES_RSSI_THRES_0_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_RSSI_THRES_RSSI_THRES_0_WIDTH    ((uint32_t)0x00000008)

#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_RSSI_THRES_RSSI_THRES_3_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_RSSI_THRES_RSSI_THRES_2_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_RSSI_THRES_RSSI_THRES_1_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_RSSI_THRES_RSSI_THRES_0_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_7_rssi_thres_pack(uint8_t rssi_thres_3, uint8_t rssi_thres_2, uint8_t rssi_thres_1, uint8_t rssi_thres_0)
{
	ASSERT_ERR((((uint32_t)rssi_thres_3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_RSSI_THRES_ADDR,  ((uint32_t)rssi_thres_3 << 24) |((uint32_t)rssi_thres_2 << 16) |((uint32_t)rssi_thres_1 << 8) |((uint32_t)rssi_thres_0 << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_7_rssi_thres_unpack(uint8_t* rssi_thres_3, uint8_t* rssi_thres_2, uint8_t* rssi_thres_1, uint8_t* rssi_thres_0)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_RSSI_THRES_ADDR);

	*rssi_thres_3 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rssi_thres_2 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rssi_thres_1 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*rssi_thres_0 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_7_rssi_thres_rssi_thres_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_7_rssi_thres_rssi_thres_3_setf(uint8_t rssithres3)
{
	ASSERT_ERR((((uint32_t)rssithres3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_RSSI_THRES_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)rssithres3 <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_7_rssi_thres_rssi_thres_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_7_rssi_thres_rssi_thres_2_setf(uint8_t rssithres2)
{
	ASSERT_ERR((((uint32_t)rssithres2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_RSSI_THRES_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rssithres2 <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_7_rssi_thres_rssi_thres_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_7_rssi_thres_rssi_thres_1_setf(uint8_t rssithres1)
{
	ASSERT_ERR((((uint32_t)rssithres1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_RSSI_THRES_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)rssithres1 <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_7_rssi_thres_rssi_thres_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_7_rssi_thres_rssi_thres_0_setf(uint8_t rssithres0)
{
	ASSERT_ERR((((uint32_t)rssithres0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_7_RSSI_THRES_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)rssithres0 <<0));
}

/**
 * @brief WIFI_RF_RX_CH_0_LNA_8_RSSI_THRES register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 RSSI_THRES_3              0x0
 *    23:16 RSSI_THRES_2              0x0
 *    15:08 RSSI_THRES_1              0x0
 *    07:00 RSSI_THRES_0              0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_RSSI_THRES_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000220)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_RSSI_THRES_OFFSET      0x00000220
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_RSSI_THRES_INDEX       0x00000088
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_RSSI_THRES_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_0_lna_8_rssi_thres_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_RSSI_THRES_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_8_rssi_thres_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_RSSI_THRES_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_RSSI_THRES_RSSI_THRES_3_MASK    ((uint32_t)0xFF000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_RSSI_THRES_RSSI_THRES_3_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_RSSI_THRES_RSSI_THRES_3_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_RSSI_THRES_RSSI_THRES_2_MASK    ((uint32_t)0x00FF0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_RSSI_THRES_RSSI_THRES_2_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_RSSI_THRES_RSSI_THRES_2_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_RSSI_THRES_RSSI_THRES_1_MASK    ((uint32_t)0x0000FF00)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_RSSI_THRES_RSSI_THRES_1_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_RSSI_THRES_RSSI_THRES_1_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_RSSI_THRES_RSSI_THRES_0_MASK    ((uint32_t)0x000000FF)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_RSSI_THRES_RSSI_THRES_0_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_RSSI_THRES_RSSI_THRES_0_WIDTH    ((uint32_t)0x00000008)

#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_RSSI_THRES_RSSI_THRES_3_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_RSSI_THRES_RSSI_THRES_2_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_RSSI_THRES_RSSI_THRES_1_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_RSSI_THRES_RSSI_THRES_0_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_8_rssi_thres_pack(uint8_t rssi_thres_3, uint8_t rssi_thres_2, uint8_t rssi_thres_1, uint8_t rssi_thres_0)
{
	ASSERT_ERR((((uint32_t)rssi_thres_3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_RSSI_THRES_ADDR,  ((uint32_t)rssi_thres_3 << 24) |((uint32_t)rssi_thres_2 << 16) |((uint32_t)rssi_thres_1 << 8) |((uint32_t)rssi_thres_0 << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_8_rssi_thres_unpack(uint8_t* rssi_thres_3, uint8_t* rssi_thres_2, uint8_t* rssi_thres_1, uint8_t* rssi_thres_0)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_RSSI_THRES_ADDR);

	*rssi_thres_3 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rssi_thres_2 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rssi_thres_1 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*rssi_thres_0 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_8_rssi_thres_rssi_thres_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_8_rssi_thres_rssi_thres_3_setf(uint8_t rssithres3)
{
	ASSERT_ERR((((uint32_t)rssithres3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_RSSI_THRES_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)rssithres3 <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_8_rssi_thres_rssi_thres_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_8_rssi_thres_rssi_thres_2_setf(uint8_t rssithres2)
{
	ASSERT_ERR((((uint32_t)rssithres2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_RSSI_THRES_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rssithres2 <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_8_rssi_thres_rssi_thres_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_8_rssi_thres_rssi_thres_1_setf(uint8_t rssithres1)
{
	ASSERT_ERR((((uint32_t)rssithres1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_RSSI_THRES_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)rssithres1 <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_8_rssi_thres_rssi_thres_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_8_rssi_thres_rssi_thres_0_setf(uint8_t rssithres0)
{
	ASSERT_ERR((((uint32_t)rssithres0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_8_RSSI_THRES_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)rssithres0 <<0));
}

/**
 * @brief WIFI_RF_RX_CH_0_LNA_9_RSSI_THRES register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 RSSI_THRES_3              0x0
 *    23:16 RSSI_THRES_2              0x0
 *    15:08 RSSI_THRES_1              0x0
 *    07:00 RSSI_THRES_0              0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_RSSI_THRES_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000224)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_RSSI_THRES_OFFSET      0x00000224
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_RSSI_THRES_INDEX       0x00000089
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_RSSI_THRES_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_0_lna_9_rssi_thres_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_RSSI_THRES_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_9_rssi_thres_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_RSSI_THRES_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_RSSI_THRES_RSSI_THRES_3_MASK    ((uint32_t)0xFF000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_RSSI_THRES_RSSI_THRES_3_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_RSSI_THRES_RSSI_THRES_3_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_RSSI_THRES_RSSI_THRES_2_MASK    ((uint32_t)0x00FF0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_RSSI_THRES_RSSI_THRES_2_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_RSSI_THRES_RSSI_THRES_2_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_RSSI_THRES_RSSI_THRES_1_MASK    ((uint32_t)0x0000FF00)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_RSSI_THRES_RSSI_THRES_1_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_RSSI_THRES_RSSI_THRES_1_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_RSSI_THRES_RSSI_THRES_0_MASK    ((uint32_t)0x000000FF)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_RSSI_THRES_RSSI_THRES_0_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_RSSI_THRES_RSSI_THRES_0_WIDTH    ((uint32_t)0x00000008)

#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_RSSI_THRES_RSSI_THRES_3_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_RSSI_THRES_RSSI_THRES_2_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_RSSI_THRES_RSSI_THRES_1_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_RSSI_THRES_RSSI_THRES_0_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_9_rssi_thres_pack(uint8_t rssi_thres_3, uint8_t rssi_thres_2, uint8_t rssi_thres_1, uint8_t rssi_thres_0)
{
	ASSERT_ERR((((uint32_t)rssi_thres_3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_RSSI_THRES_ADDR,  ((uint32_t)rssi_thres_3 << 24) |((uint32_t)rssi_thres_2 << 16) |((uint32_t)rssi_thres_1 << 8) |((uint32_t)rssi_thres_0 << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_9_rssi_thres_unpack(uint8_t* rssi_thres_3, uint8_t* rssi_thres_2, uint8_t* rssi_thres_1, uint8_t* rssi_thres_0)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_RSSI_THRES_ADDR);

	*rssi_thres_3 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rssi_thres_2 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rssi_thres_1 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*rssi_thres_0 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_9_rssi_thres_rssi_thres_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_9_rssi_thres_rssi_thres_3_setf(uint8_t rssithres3)
{
	ASSERT_ERR((((uint32_t)rssithres3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_RSSI_THRES_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)rssithres3 <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_9_rssi_thres_rssi_thres_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_9_rssi_thres_rssi_thres_2_setf(uint8_t rssithres2)
{
	ASSERT_ERR((((uint32_t)rssithres2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_RSSI_THRES_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rssithres2 <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_9_rssi_thres_rssi_thres_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_9_rssi_thres_rssi_thres_1_setf(uint8_t rssithres1)
{
	ASSERT_ERR((((uint32_t)rssithres1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_RSSI_THRES_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)rssithres1 <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_9_rssi_thres_rssi_thres_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_9_rssi_thres_rssi_thres_0_setf(uint8_t rssithres0)
{
	ASSERT_ERR((((uint32_t)rssithres0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_9_RSSI_THRES_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)rssithres0 <<0));
}

/**
 * @brief WIFI_RF_RX_CH_0_LNA_10_RSSI_THRES register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 RSSI_THRES_3              0x0
 *    23:16 RSSI_THRES_2              0x0
 *    15:08 RSSI_THRES_1              0x0
 *    07:00 RSSI_THRES_0              0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_RSSI_THRES_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000228)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_RSSI_THRES_OFFSET      0x00000228
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_RSSI_THRES_INDEX       0x0000008A
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_RSSI_THRES_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_0_lna_10_rssi_thres_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_RSSI_THRES_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_10_rssi_thres_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_RSSI_THRES_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_RSSI_THRES_RSSI_THRES_3_MASK    ((uint32_t)0xFF000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_RSSI_THRES_RSSI_THRES_3_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_RSSI_THRES_RSSI_THRES_3_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_RSSI_THRES_RSSI_THRES_2_MASK    ((uint32_t)0x00FF0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_RSSI_THRES_RSSI_THRES_2_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_RSSI_THRES_RSSI_THRES_2_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_RSSI_THRES_RSSI_THRES_1_MASK    ((uint32_t)0x0000FF00)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_RSSI_THRES_RSSI_THRES_1_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_RSSI_THRES_RSSI_THRES_1_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_RSSI_THRES_RSSI_THRES_0_MASK    ((uint32_t)0x000000FF)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_RSSI_THRES_RSSI_THRES_0_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_RSSI_THRES_RSSI_THRES_0_WIDTH    ((uint32_t)0x00000008)

#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_RSSI_THRES_RSSI_THRES_3_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_RSSI_THRES_RSSI_THRES_2_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_RSSI_THRES_RSSI_THRES_1_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_RSSI_THRES_RSSI_THRES_0_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_10_rssi_thres_pack(uint8_t rssi_thres_3, uint8_t rssi_thres_2, uint8_t rssi_thres_1, uint8_t rssi_thres_0)
{
	ASSERT_ERR((((uint32_t)rssi_thres_3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_RSSI_THRES_ADDR,  ((uint32_t)rssi_thres_3 << 24) |((uint32_t)rssi_thres_2 << 16) |((uint32_t)rssi_thres_1 << 8) |((uint32_t)rssi_thres_0 << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_10_rssi_thres_unpack(uint8_t* rssi_thres_3, uint8_t* rssi_thres_2, uint8_t* rssi_thres_1, uint8_t* rssi_thres_0)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_RSSI_THRES_ADDR);

	*rssi_thres_3 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rssi_thres_2 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rssi_thres_1 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*rssi_thres_0 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_10_rssi_thres_rssi_thres_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_10_rssi_thres_rssi_thres_3_setf(uint8_t rssithres3)
{
	ASSERT_ERR((((uint32_t)rssithres3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_RSSI_THRES_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)rssithres3 <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_10_rssi_thres_rssi_thres_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_10_rssi_thres_rssi_thres_2_setf(uint8_t rssithres2)
{
	ASSERT_ERR((((uint32_t)rssithres2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_RSSI_THRES_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rssithres2 <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_10_rssi_thres_rssi_thres_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_10_rssi_thres_rssi_thres_1_setf(uint8_t rssithres1)
{
	ASSERT_ERR((((uint32_t)rssithres1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_RSSI_THRES_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)rssithres1 <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_10_rssi_thres_rssi_thres_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_10_rssi_thres_rssi_thres_0_setf(uint8_t rssithres0)
{
	ASSERT_ERR((((uint32_t)rssithres0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_10_RSSI_THRES_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)rssithres0 <<0));
}

/**
 * @brief WIFI_RF_RX_CH_0_LNA_11_RSSI_THRES register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 RSSI_THRES_3              0x0
 *    23:16 RSSI_THRES_2              0x0
 *    15:08 RSSI_THRES_1              0x0
 *    07:00 RSSI_THRES_0              0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_RSSI_THRES_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x0000022C)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_RSSI_THRES_OFFSET      0x0000022C
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_RSSI_THRES_INDEX       0x0000008B
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_RSSI_THRES_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_0_lna_11_rssi_thres_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_RSSI_THRES_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_11_rssi_thres_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_RSSI_THRES_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_RSSI_THRES_RSSI_THRES_3_MASK    ((uint32_t)0xFF000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_RSSI_THRES_RSSI_THRES_3_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_RSSI_THRES_RSSI_THRES_3_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_RSSI_THRES_RSSI_THRES_2_MASK    ((uint32_t)0x00FF0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_RSSI_THRES_RSSI_THRES_2_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_RSSI_THRES_RSSI_THRES_2_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_RSSI_THRES_RSSI_THRES_1_MASK    ((uint32_t)0x0000FF00)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_RSSI_THRES_RSSI_THRES_1_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_RSSI_THRES_RSSI_THRES_1_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_RSSI_THRES_RSSI_THRES_0_MASK    ((uint32_t)0x000000FF)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_RSSI_THRES_RSSI_THRES_0_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_RSSI_THRES_RSSI_THRES_0_WIDTH    ((uint32_t)0x00000008)

#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_RSSI_THRES_RSSI_THRES_3_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_RSSI_THRES_RSSI_THRES_2_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_RSSI_THRES_RSSI_THRES_1_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_RSSI_THRES_RSSI_THRES_0_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_11_rssi_thres_pack(uint8_t rssi_thres_3, uint8_t rssi_thres_2, uint8_t rssi_thres_1, uint8_t rssi_thres_0)
{
	ASSERT_ERR((((uint32_t)rssi_thres_3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_RSSI_THRES_ADDR,  ((uint32_t)rssi_thres_3 << 24) |((uint32_t)rssi_thres_2 << 16) |((uint32_t)rssi_thres_1 << 8) |((uint32_t)rssi_thres_0 << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_11_rssi_thres_unpack(uint8_t* rssi_thres_3, uint8_t* rssi_thres_2, uint8_t* rssi_thres_1, uint8_t* rssi_thres_0)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_RSSI_THRES_ADDR);

	*rssi_thres_3 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rssi_thres_2 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rssi_thres_1 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*rssi_thres_0 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_11_rssi_thres_rssi_thres_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_11_rssi_thres_rssi_thres_3_setf(uint8_t rssithres3)
{
	ASSERT_ERR((((uint32_t)rssithres3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_RSSI_THRES_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)rssithres3 <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_11_rssi_thres_rssi_thres_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_11_rssi_thres_rssi_thres_2_setf(uint8_t rssithres2)
{
	ASSERT_ERR((((uint32_t)rssithres2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_RSSI_THRES_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rssithres2 <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_11_rssi_thres_rssi_thres_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_11_rssi_thres_rssi_thres_1_setf(uint8_t rssithres1)
{
	ASSERT_ERR((((uint32_t)rssithres1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_RSSI_THRES_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)rssithres1 <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_11_rssi_thres_rssi_thres_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_11_rssi_thres_rssi_thres_0_setf(uint8_t rssithres0)
{
	ASSERT_ERR((((uint32_t)rssithres0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_11_RSSI_THRES_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)rssithres0 <<0));
}

/**
 * @brief WIFI_RF_RX_CH_0_LNA_12_RSSI_THRES register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 RSSI_THRES_3              0x0
 *    23:16 RSSI_THRES_2              0x0
 *    15:08 RSSI_THRES_1              0x0
 *    07:00 RSSI_THRES_0              0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_RSSI_THRES_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000230)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_RSSI_THRES_OFFSET      0x00000230
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_RSSI_THRES_INDEX       0x0000008C
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_RSSI_THRES_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_0_lna_12_rssi_thres_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_RSSI_THRES_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_12_rssi_thres_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_RSSI_THRES_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_RSSI_THRES_RSSI_THRES_3_MASK    ((uint32_t)0xFF000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_RSSI_THRES_RSSI_THRES_3_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_RSSI_THRES_RSSI_THRES_3_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_RSSI_THRES_RSSI_THRES_2_MASK    ((uint32_t)0x00FF0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_RSSI_THRES_RSSI_THRES_2_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_RSSI_THRES_RSSI_THRES_2_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_RSSI_THRES_RSSI_THRES_1_MASK    ((uint32_t)0x0000FF00)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_RSSI_THRES_RSSI_THRES_1_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_RSSI_THRES_RSSI_THRES_1_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_RSSI_THRES_RSSI_THRES_0_MASK    ((uint32_t)0x000000FF)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_RSSI_THRES_RSSI_THRES_0_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_RSSI_THRES_RSSI_THRES_0_WIDTH    ((uint32_t)0x00000008)

#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_RSSI_THRES_RSSI_THRES_3_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_RSSI_THRES_RSSI_THRES_2_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_RSSI_THRES_RSSI_THRES_1_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_RSSI_THRES_RSSI_THRES_0_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_12_rssi_thres_pack(uint8_t rssi_thres_3, uint8_t rssi_thres_2, uint8_t rssi_thres_1, uint8_t rssi_thres_0)
{
	ASSERT_ERR((((uint32_t)rssi_thres_3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_RSSI_THRES_ADDR,  ((uint32_t)rssi_thres_3 << 24) |((uint32_t)rssi_thres_2 << 16) |((uint32_t)rssi_thres_1 << 8) |((uint32_t)rssi_thres_0 << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_12_rssi_thres_unpack(uint8_t* rssi_thres_3, uint8_t* rssi_thres_2, uint8_t* rssi_thres_1, uint8_t* rssi_thres_0)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_RSSI_THRES_ADDR);

	*rssi_thres_3 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rssi_thres_2 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rssi_thres_1 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*rssi_thres_0 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_12_rssi_thres_rssi_thres_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_12_rssi_thres_rssi_thres_3_setf(uint8_t rssithres3)
{
	ASSERT_ERR((((uint32_t)rssithres3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_RSSI_THRES_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)rssithres3 <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_12_rssi_thres_rssi_thres_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_12_rssi_thres_rssi_thres_2_setf(uint8_t rssithres2)
{
	ASSERT_ERR((((uint32_t)rssithres2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_RSSI_THRES_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rssithres2 <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_12_rssi_thres_rssi_thres_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_12_rssi_thres_rssi_thres_1_setf(uint8_t rssithres1)
{
	ASSERT_ERR((((uint32_t)rssithres1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_RSSI_THRES_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)rssithres1 <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_12_rssi_thres_rssi_thres_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_12_rssi_thres_rssi_thres_0_setf(uint8_t rssithres0)
{
	ASSERT_ERR((((uint32_t)rssithres0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_12_RSSI_THRES_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)rssithres0 <<0));
}

/**
 * @brief WIFI_RF_RX_CH_0_LNA_13_RSSI_THRES register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 RSSI_THRES_3              0x0
 *    23:16 RSSI_THRES_2              0x0
 *    15:08 RSSI_THRES_1              0x0
 *    07:00 RSSI_THRES_0              0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_RSSI_THRES_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000234)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_RSSI_THRES_OFFSET      0x00000234
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_RSSI_THRES_INDEX       0x0000008D
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_RSSI_THRES_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_0_lna_13_rssi_thres_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_RSSI_THRES_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_13_rssi_thres_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_RSSI_THRES_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_RSSI_THRES_RSSI_THRES_3_MASK    ((uint32_t)0xFF000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_RSSI_THRES_RSSI_THRES_3_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_RSSI_THRES_RSSI_THRES_3_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_RSSI_THRES_RSSI_THRES_2_MASK    ((uint32_t)0x00FF0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_RSSI_THRES_RSSI_THRES_2_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_RSSI_THRES_RSSI_THRES_2_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_RSSI_THRES_RSSI_THRES_1_MASK    ((uint32_t)0x0000FF00)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_RSSI_THRES_RSSI_THRES_1_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_RSSI_THRES_RSSI_THRES_1_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_RSSI_THRES_RSSI_THRES_0_MASK    ((uint32_t)0x000000FF)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_RSSI_THRES_RSSI_THRES_0_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_RSSI_THRES_RSSI_THRES_0_WIDTH    ((uint32_t)0x00000008)

#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_RSSI_THRES_RSSI_THRES_3_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_RSSI_THRES_RSSI_THRES_2_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_RSSI_THRES_RSSI_THRES_1_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_RSSI_THRES_RSSI_THRES_0_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_13_rssi_thres_pack(uint8_t rssi_thres_3, uint8_t rssi_thres_2, uint8_t rssi_thres_1, uint8_t rssi_thres_0)
{
	ASSERT_ERR((((uint32_t)rssi_thres_3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_RSSI_THRES_ADDR,  ((uint32_t)rssi_thres_3 << 24) |((uint32_t)rssi_thres_2 << 16) |((uint32_t)rssi_thres_1 << 8) |((uint32_t)rssi_thres_0 << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_13_rssi_thres_unpack(uint8_t* rssi_thres_3, uint8_t* rssi_thres_2, uint8_t* rssi_thres_1, uint8_t* rssi_thres_0)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_RSSI_THRES_ADDR);

	*rssi_thres_3 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rssi_thres_2 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rssi_thres_1 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*rssi_thres_0 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_13_rssi_thres_rssi_thres_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_13_rssi_thres_rssi_thres_3_setf(uint8_t rssithres3)
{
	ASSERT_ERR((((uint32_t)rssithres3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_RSSI_THRES_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)rssithres3 <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_13_rssi_thres_rssi_thres_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_13_rssi_thres_rssi_thres_2_setf(uint8_t rssithres2)
{
	ASSERT_ERR((((uint32_t)rssithres2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_RSSI_THRES_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rssithres2 <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_13_rssi_thres_rssi_thres_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_13_rssi_thres_rssi_thres_1_setf(uint8_t rssithres1)
{
	ASSERT_ERR((((uint32_t)rssithres1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_RSSI_THRES_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)rssithres1 <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_13_rssi_thres_rssi_thres_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_13_rssi_thres_rssi_thres_0_setf(uint8_t rssithres0)
{
	ASSERT_ERR((((uint32_t)rssithres0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_13_RSSI_THRES_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)rssithres0 <<0));
}

/**
 * @brief WIFI_RF_RX_CH_0_LNA_14_RSSI_THRES register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 RSSI_THRES_3              0x0
 *    23:16 RSSI_THRES_2              0x0
 *    15:08 RSSI_THRES_1              0x0
 *    07:00 RSSI_THRES_0              0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_RSSI_THRES_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000238)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_RSSI_THRES_OFFSET      0x00000238
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_RSSI_THRES_INDEX       0x0000008E
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_RSSI_THRES_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_0_lna_14_rssi_thres_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_RSSI_THRES_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_14_rssi_thres_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_RSSI_THRES_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_RSSI_THRES_RSSI_THRES_3_MASK    ((uint32_t)0xFF000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_RSSI_THRES_RSSI_THRES_3_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_RSSI_THRES_RSSI_THRES_3_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_RSSI_THRES_RSSI_THRES_2_MASK    ((uint32_t)0x00FF0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_RSSI_THRES_RSSI_THRES_2_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_RSSI_THRES_RSSI_THRES_2_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_RSSI_THRES_RSSI_THRES_1_MASK    ((uint32_t)0x0000FF00)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_RSSI_THRES_RSSI_THRES_1_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_RSSI_THRES_RSSI_THRES_1_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_RSSI_THRES_RSSI_THRES_0_MASK    ((uint32_t)0x000000FF)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_RSSI_THRES_RSSI_THRES_0_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_RSSI_THRES_RSSI_THRES_0_WIDTH    ((uint32_t)0x00000008)

#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_RSSI_THRES_RSSI_THRES_3_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_RSSI_THRES_RSSI_THRES_2_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_RSSI_THRES_RSSI_THRES_1_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_RSSI_THRES_RSSI_THRES_0_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_14_rssi_thres_pack(uint8_t rssi_thres_3, uint8_t rssi_thres_2, uint8_t rssi_thres_1, uint8_t rssi_thres_0)
{
	ASSERT_ERR((((uint32_t)rssi_thres_3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_RSSI_THRES_ADDR,  ((uint32_t)rssi_thres_3 << 24) |((uint32_t)rssi_thres_2 << 16) |((uint32_t)rssi_thres_1 << 8) |((uint32_t)rssi_thres_0 << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_14_rssi_thres_unpack(uint8_t* rssi_thres_3, uint8_t* rssi_thres_2, uint8_t* rssi_thres_1, uint8_t* rssi_thres_0)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_RSSI_THRES_ADDR);

	*rssi_thres_3 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rssi_thres_2 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rssi_thres_1 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*rssi_thres_0 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_14_rssi_thres_rssi_thres_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_14_rssi_thres_rssi_thres_3_setf(uint8_t rssithres3)
{
	ASSERT_ERR((((uint32_t)rssithres3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_RSSI_THRES_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)rssithres3 <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_14_rssi_thres_rssi_thres_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_14_rssi_thres_rssi_thres_2_setf(uint8_t rssithres2)
{
	ASSERT_ERR((((uint32_t)rssithres2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_RSSI_THRES_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rssithres2 <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_14_rssi_thres_rssi_thres_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_14_rssi_thres_rssi_thres_1_setf(uint8_t rssithres1)
{
	ASSERT_ERR((((uint32_t)rssithres1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_RSSI_THRES_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)rssithres1 <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_14_rssi_thres_rssi_thres_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_14_rssi_thres_rssi_thres_0_setf(uint8_t rssithres0)
{
	ASSERT_ERR((((uint32_t)rssithres0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_14_RSSI_THRES_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)rssithres0 <<0));
}

/**
 * @brief WIFI_RF_RX_CH_0_LNA_15_RSSI_THRES register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 RSSI_THRES_3              0x0
 *    23:16 RSSI_THRES_2              0x0
 *    15:08 RSSI_THRES_1              0x0
 *    07:00 RSSI_THRES_0              0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_RSSI_THRES_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x0000023C)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_RSSI_THRES_OFFSET      0x0000023C
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_RSSI_THRES_INDEX       0x0000008F
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_RSSI_THRES_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_0_lna_15_rssi_thres_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_RSSI_THRES_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_15_rssi_thres_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_RSSI_THRES_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_RSSI_THRES_RSSI_THRES_3_MASK    ((uint32_t)0xFF000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_RSSI_THRES_RSSI_THRES_3_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_RSSI_THRES_RSSI_THRES_3_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_RSSI_THRES_RSSI_THRES_2_MASK    ((uint32_t)0x00FF0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_RSSI_THRES_RSSI_THRES_2_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_RSSI_THRES_RSSI_THRES_2_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_RSSI_THRES_RSSI_THRES_1_MASK    ((uint32_t)0x0000FF00)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_RSSI_THRES_RSSI_THRES_1_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_RSSI_THRES_RSSI_THRES_1_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_RSSI_THRES_RSSI_THRES_0_MASK    ((uint32_t)0x000000FF)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_RSSI_THRES_RSSI_THRES_0_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_RSSI_THRES_RSSI_THRES_0_WIDTH    ((uint32_t)0x00000008)

#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_RSSI_THRES_RSSI_THRES_3_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_RSSI_THRES_RSSI_THRES_2_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_RSSI_THRES_RSSI_THRES_1_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_RSSI_THRES_RSSI_THRES_0_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_15_rssi_thres_pack(uint8_t rssi_thres_3, uint8_t rssi_thres_2, uint8_t rssi_thres_1, uint8_t rssi_thres_0)
{
	ASSERT_ERR((((uint32_t)rssi_thres_3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_RSSI_THRES_ADDR,  ((uint32_t)rssi_thres_3 << 24) |((uint32_t)rssi_thres_2 << 16) |((uint32_t)rssi_thres_1 << 8) |((uint32_t)rssi_thres_0 << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_15_rssi_thres_unpack(uint8_t* rssi_thres_3, uint8_t* rssi_thres_2, uint8_t* rssi_thres_1, uint8_t* rssi_thres_0)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_RSSI_THRES_ADDR);

	*rssi_thres_3 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rssi_thres_2 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rssi_thres_1 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*rssi_thres_0 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_15_rssi_thres_rssi_thres_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_15_rssi_thres_rssi_thres_3_setf(uint8_t rssithres3)
{
	ASSERT_ERR((((uint32_t)rssithres3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_RSSI_THRES_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)rssithres3 <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_15_rssi_thres_rssi_thres_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_15_rssi_thres_rssi_thres_2_setf(uint8_t rssithres2)
{
	ASSERT_ERR((((uint32_t)rssithres2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_RSSI_THRES_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rssithres2 <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_15_rssi_thres_rssi_thres_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_15_rssi_thres_rssi_thres_1_setf(uint8_t rssithres1)
{
	ASSERT_ERR((((uint32_t)rssithres1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_RSSI_THRES_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)rssithres1 <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_0_lna_15_rssi_thres_rssi_thres_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_lna_15_rssi_thres_rssi_thres_0_setf(uint8_t rssithres0)
{
	ASSERT_ERR((((uint32_t)rssithres0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_LNA_15_RSSI_THRES_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)rssithres0 <<0));
}

/**
 * @brief WIFI_RF_RX_CH_1_LNA_0_RSSI_THRES register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 RSSI_THRES_3              0x0
 *    23:16 RSSI_THRES_2              0x0
 *    15:08 RSSI_THRES_1              0x0
 *    07:00 RSSI_THRES_0              0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_RSSI_THRES_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000240)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_RSSI_THRES_OFFSET      0x00000240
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_RSSI_THRES_INDEX       0x00000090
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_RSSI_THRES_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_1_lna_0_rssi_thres_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_RSSI_THRES_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_0_rssi_thres_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_RSSI_THRES_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_RSSI_THRES_RSSI_THRES_3_MASK    ((uint32_t)0xFF000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_RSSI_THRES_RSSI_THRES_3_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_RSSI_THRES_RSSI_THRES_3_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_RSSI_THRES_RSSI_THRES_2_MASK    ((uint32_t)0x00FF0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_RSSI_THRES_RSSI_THRES_2_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_RSSI_THRES_RSSI_THRES_2_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_RSSI_THRES_RSSI_THRES_1_MASK    ((uint32_t)0x0000FF00)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_RSSI_THRES_RSSI_THRES_1_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_RSSI_THRES_RSSI_THRES_1_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_RSSI_THRES_RSSI_THRES_0_MASK    ((uint32_t)0x000000FF)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_RSSI_THRES_RSSI_THRES_0_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_RSSI_THRES_RSSI_THRES_0_WIDTH    ((uint32_t)0x00000008)

#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_RSSI_THRES_RSSI_THRES_3_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_RSSI_THRES_RSSI_THRES_2_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_RSSI_THRES_RSSI_THRES_1_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_RSSI_THRES_RSSI_THRES_0_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_0_rssi_thres_pack(uint8_t rssi_thres_3, uint8_t rssi_thres_2, uint8_t rssi_thres_1, uint8_t rssi_thres_0)
{
	ASSERT_ERR((((uint32_t)rssi_thres_3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_RSSI_THRES_ADDR,  ((uint32_t)rssi_thres_3 << 24) |((uint32_t)rssi_thres_2 << 16) |((uint32_t)rssi_thres_1 << 8) |((uint32_t)rssi_thres_0 << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_0_rssi_thres_unpack(uint8_t* rssi_thres_3, uint8_t* rssi_thres_2, uint8_t* rssi_thres_1, uint8_t* rssi_thres_0)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_RSSI_THRES_ADDR);

	*rssi_thres_3 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rssi_thres_2 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rssi_thres_1 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*rssi_thres_0 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_0_rssi_thres_rssi_thres_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_0_rssi_thres_rssi_thres_3_setf(uint8_t rssithres3)
{
	ASSERT_ERR((((uint32_t)rssithres3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_RSSI_THRES_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)rssithres3 <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_0_rssi_thres_rssi_thres_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_0_rssi_thres_rssi_thres_2_setf(uint8_t rssithres2)
{
	ASSERT_ERR((((uint32_t)rssithres2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_RSSI_THRES_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rssithres2 <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_0_rssi_thres_rssi_thres_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_0_rssi_thres_rssi_thres_1_setf(uint8_t rssithres1)
{
	ASSERT_ERR((((uint32_t)rssithres1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_RSSI_THRES_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)rssithres1 <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_0_rssi_thres_rssi_thres_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_0_rssi_thres_rssi_thres_0_setf(uint8_t rssithres0)
{
	ASSERT_ERR((((uint32_t)rssithres0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_0_RSSI_THRES_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)rssithres0 <<0));
}

/**
 * @brief WIFI_RF_RX_CH_1_LNA_1_RSSI_THRES register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 RSSI_THRES_3              0x0
 *    23:16 RSSI_THRES_2              0x0
 *    15:08 RSSI_THRES_1              0x0
 *    07:00 RSSI_THRES_0              0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_RSSI_THRES_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000244)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_RSSI_THRES_OFFSET      0x00000244
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_RSSI_THRES_INDEX       0x00000091
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_RSSI_THRES_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_1_lna_1_rssi_thres_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_RSSI_THRES_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_1_rssi_thres_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_RSSI_THRES_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_RSSI_THRES_RSSI_THRES_3_MASK    ((uint32_t)0xFF000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_RSSI_THRES_RSSI_THRES_3_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_RSSI_THRES_RSSI_THRES_3_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_RSSI_THRES_RSSI_THRES_2_MASK    ((uint32_t)0x00FF0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_RSSI_THRES_RSSI_THRES_2_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_RSSI_THRES_RSSI_THRES_2_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_RSSI_THRES_RSSI_THRES_1_MASK    ((uint32_t)0x0000FF00)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_RSSI_THRES_RSSI_THRES_1_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_RSSI_THRES_RSSI_THRES_1_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_RSSI_THRES_RSSI_THRES_0_MASK    ((uint32_t)0x000000FF)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_RSSI_THRES_RSSI_THRES_0_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_RSSI_THRES_RSSI_THRES_0_WIDTH    ((uint32_t)0x00000008)

#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_RSSI_THRES_RSSI_THRES_3_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_RSSI_THRES_RSSI_THRES_2_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_RSSI_THRES_RSSI_THRES_1_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_RSSI_THRES_RSSI_THRES_0_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_1_rssi_thres_pack(uint8_t rssi_thres_3, uint8_t rssi_thres_2, uint8_t rssi_thres_1, uint8_t rssi_thres_0)
{
	ASSERT_ERR((((uint32_t)rssi_thres_3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_RSSI_THRES_ADDR,  ((uint32_t)rssi_thres_3 << 24) |((uint32_t)rssi_thres_2 << 16) |((uint32_t)rssi_thres_1 << 8) |((uint32_t)rssi_thres_0 << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_1_rssi_thres_unpack(uint8_t* rssi_thres_3, uint8_t* rssi_thres_2, uint8_t* rssi_thres_1, uint8_t* rssi_thres_0)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_RSSI_THRES_ADDR);

	*rssi_thres_3 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rssi_thres_2 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rssi_thres_1 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*rssi_thres_0 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_1_rssi_thres_rssi_thres_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_1_rssi_thres_rssi_thres_3_setf(uint8_t rssithres3)
{
	ASSERT_ERR((((uint32_t)rssithres3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_RSSI_THRES_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)rssithres3 <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_1_rssi_thres_rssi_thres_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_1_rssi_thres_rssi_thres_2_setf(uint8_t rssithres2)
{
	ASSERT_ERR((((uint32_t)rssithres2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_RSSI_THRES_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rssithres2 <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_1_rssi_thres_rssi_thres_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_1_rssi_thres_rssi_thres_1_setf(uint8_t rssithres1)
{
	ASSERT_ERR((((uint32_t)rssithres1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_RSSI_THRES_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)rssithres1 <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_1_rssi_thres_rssi_thres_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_1_rssi_thres_rssi_thres_0_setf(uint8_t rssithres0)
{
	ASSERT_ERR((((uint32_t)rssithres0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_1_RSSI_THRES_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)rssithres0 <<0));
}

/**
 * @brief WIFI_RF_RX_CH_1_LNA_2_RSSI_THRES register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 RSSI_THRES_3              0x0
 *    23:16 RSSI_THRES_2              0x0
 *    15:08 RSSI_THRES_1              0x0
 *    07:00 RSSI_THRES_0              0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_RSSI_THRES_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000248)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_RSSI_THRES_OFFSET      0x00000248
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_RSSI_THRES_INDEX       0x00000092
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_RSSI_THRES_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_1_lna_2_rssi_thres_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_RSSI_THRES_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_2_rssi_thres_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_RSSI_THRES_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_RSSI_THRES_RSSI_THRES_3_MASK    ((uint32_t)0xFF000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_RSSI_THRES_RSSI_THRES_3_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_RSSI_THRES_RSSI_THRES_3_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_RSSI_THRES_RSSI_THRES_2_MASK    ((uint32_t)0x00FF0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_RSSI_THRES_RSSI_THRES_2_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_RSSI_THRES_RSSI_THRES_2_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_RSSI_THRES_RSSI_THRES_1_MASK    ((uint32_t)0x0000FF00)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_RSSI_THRES_RSSI_THRES_1_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_RSSI_THRES_RSSI_THRES_1_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_RSSI_THRES_RSSI_THRES_0_MASK    ((uint32_t)0x000000FF)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_RSSI_THRES_RSSI_THRES_0_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_RSSI_THRES_RSSI_THRES_0_WIDTH    ((uint32_t)0x00000008)

#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_RSSI_THRES_RSSI_THRES_3_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_RSSI_THRES_RSSI_THRES_2_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_RSSI_THRES_RSSI_THRES_1_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_RSSI_THRES_RSSI_THRES_0_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_2_rssi_thres_pack(uint8_t rssi_thres_3, uint8_t rssi_thres_2, uint8_t rssi_thres_1, uint8_t rssi_thres_0)
{
	ASSERT_ERR((((uint32_t)rssi_thres_3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_RSSI_THRES_ADDR,  ((uint32_t)rssi_thres_3 << 24) |((uint32_t)rssi_thres_2 << 16) |((uint32_t)rssi_thres_1 << 8) |((uint32_t)rssi_thres_0 << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_2_rssi_thres_unpack(uint8_t* rssi_thres_3, uint8_t* rssi_thres_2, uint8_t* rssi_thres_1, uint8_t* rssi_thres_0)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_RSSI_THRES_ADDR);

	*rssi_thres_3 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rssi_thres_2 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rssi_thres_1 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*rssi_thres_0 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_2_rssi_thres_rssi_thres_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_2_rssi_thres_rssi_thres_3_setf(uint8_t rssithres3)
{
	ASSERT_ERR((((uint32_t)rssithres3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_RSSI_THRES_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)rssithres3 <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_2_rssi_thres_rssi_thres_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_2_rssi_thres_rssi_thres_2_setf(uint8_t rssithres2)
{
	ASSERT_ERR((((uint32_t)rssithres2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_RSSI_THRES_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rssithres2 <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_2_rssi_thres_rssi_thres_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_2_rssi_thres_rssi_thres_1_setf(uint8_t rssithres1)
{
	ASSERT_ERR((((uint32_t)rssithres1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_RSSI_THRES_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)rssithres1 <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_2_rssi_thres_rssi_thres_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_2_rssi_thres_rssi_thres_0_setf(uint8_t rssithres0)
{
	ASSERT_ERR((((uint32_t)rssithres0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_2_RSSI_THRES_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)rssithres0 <<0));
}

/**
 * @brief WIFI_RF_RX_CH_1_LNA_3_RSSI_THRES register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 RSSI_THRES_3              0x0
 *    23:16 RSSI_THRES_2              0x0
 *    15:08 RSSI_THRES_1              0x0
 *    07:00 RSSI_THRES_0              0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_RSSI_THRES_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x0000024C)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_RSSI_THRES_OFFSET      0x0000024C
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_RSSI_THRES_INDEX       0x00000093
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_RSSI_THRES_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_1_lna_3_rssi_thres_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_RSSI_THRES_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_3_rssi_thres_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_RSSI_THRES_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_RSSI_THRES_RSSI_THRES_3_MASK    ((uint32_t)0xFF000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_RSSI_THRES_RSSI_THRES_3_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_RSSI_THRES_RSSI_THRES_3_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_RSSI_THRES_RSSI_THRES_2_MASK    ((uint32_t)0x00FF0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_RSSI_THRES_RSSI_THRES_2_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_RSSI_THRES_RSSI_THRES_2_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_RSSI_THRES_RSSI_THRES_1_MASK    ((uint32_t)0x0000FF00)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_RSSI_THRES_RSSI_THRES_1_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_RSSI_THRES_RSSI_THRES_1_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_RSSI_THRES_RSSI_THRES_0_MASK    ((uint32_t)0x000000FF)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_RSSI_THRES_RSSI_THRES_0_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_RSSI_THRES_RSSI_THRES_0_WIDTH    ((uint32_t)0x00000008)

#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_RSSI_THRES_RSSI_THRES_3_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_RSSI_THRES_RSSI_THRES_2_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_RSSI_THRES_RSSI_THRES_1_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_RSSI_THRES_RSSI_THRES_0_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_3_rssi_thres_pack(uint8_t rssi_thres_3, uint8_t rssi_thres_2, uint8_t rssi_thres_1, uint8_t rssi_thres_0)
{
	ASSERT_ERR((((uint32_t)rssi_thres_3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_RSSI_THRES_ADDR,  ((uint32_t)rssi_thres_3 << 24) |((uint32_t)rssi_thres_2 << 16) |((uint32_t)rssi_thres_1 << 8) |((uint32_t)rssi_thres_0 << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_3_rssi_thres_unpack(uint8_t* rssi_thres_3, uint8_t* rssi_thres_2, uint8_t* rssi_thres_1, uint8_t* rssi_thres_0)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_RSSI_THRES_ADDR);

	*rssi_thres_3 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rssi_thres_2 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rssi_thres_1 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*rssi_thres_0 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_3_rssi_thres_rssi_thres_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_3_rssi_thres_rssi_thres_3_setf(uint8_t rssithres3)
{
	ASSERT_ERR((((uint32_t)rssithres3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_RSSI_THRES_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)rssithres3 <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_3_rssi_thres_rssi_thres_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_3_rssi_thres_rssi_thres_2_setf(uint8_t rssithres2)
{
	ASSERT_ERR((((uint32_t)rssithres2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_RSSI_THRES_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rssithres2 <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_3_rssi_thres_rssi_thres_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_3_rssi_thres_rssi_thres_1_setf(uint8_t rssithres1)
{
	ASSERT_ERR((((uint32_t)rssithres1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_RSSI_THRES_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)rssithres1 <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_3_rssi_thres_rssi_thres_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_3_rssi_thres_rssi_thres_0_setf(uint8_t rssithres0)
{
	ASSERT_ERR((((uint32_t)rssithres0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_3_RSSI_THRES_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)rssithres0 <<0));
}

/**
 * @brief WIFI_RF_RX_CH_1_LNA_4_RSSI_THRES register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 RSSI_THRES_3              0x0
 *    23:16 RSSI_THRES_2              0x0
 *    15:08 RSSI_THRES_1              0x0
 *    07:00 RSSI_THRES_0              0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_RSSI_THRES_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000250)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_RSSI_THRES_OFFSET      0x00000250
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_RSSI_THRES_INDEX       0x00000094
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_RSSI_THRES_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_1_lna_4_rssi_thres_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_RSSI_THRES_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_4_rssi_thres_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_RSSI_THRES_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_RSSI_THRES_RSSI_THRES_3_MASK    ((uint32_t)0xFF000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_RSSI_THRES_RSSI_THRES_3_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_RSSI_THRES_RSSI_THRES_3_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_RSSI_THRES_RSSI_THRES_2_MASK    ((uint32_t)0x00FF0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_RSSI_THRES_RSSI_THRES_2_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_RSSI_THRES_RSSI_THRES_2_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_RSSI_THRES_RSSI_THRES_1_MASK    ((uint32_t)0x0000FF00)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_RSSI_THRES_RSSI_THRES_1_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_RSSI_THRES_RSSI_THRES_1_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_RSSI_THRES_RSSI_THRES_0_MASK    ((uint32_t)0x000000FF)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_RSSI_THRES_RSSI_THRES_0_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_RSSI_THRES_RSSI_THRES_0_WIDTH    ((uint32_t)0x00000008)

#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_RSSI_THRES_RSSI_THRES_3_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_RSSI_THRES_RSSI_THRES_2_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_RSSI_THRES_RSSI_THRES_1_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_RSSI_THRES_RSSI_THRES_0_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_4_rssi_thres_pack(uint8_t rssi_thres_3, uint8_t rssi_thres_2, uint8_t rssi_thres_1, uint8_t rssi_thres_0)
{
	ASSERT_ERR((((uint32_t)rssi_thres_3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_RSSI_THRES_ADDR,  ((uint32_t)rssi_thres_3 << 24) |((uint32_t)rssi_thres_2 << 16) |((uint32_t)rssi_thres_1 << 8) |((uint32_t)rssi_thres_0 << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_4_rssi_thres_unpack(uint8_t* rssi_thres_3, uint8_t* rssi_thres_2, uint8_t* rssi_thres_1, uint8_t* rssi_thres_0)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_RSSI_THRES_ADDR);

	*rssi_thres_3 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rssi_thres_2 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rssi_thres_1 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*rssi_thres_0 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_4_rssi_thres_rssi_thres_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_4_rssi_thres_rssi_thres_3_setf(uint8_t rssithres3)
{
	ASSERT_ERR((((uint32_t)rssithres3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_RSSI_THRES_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)rssithres3 <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_4_rssi_thres_rssi_thres_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_4_rssi_thres_rssi_thres_2_setf(uint8_t rssithres2)
{
	ASSERT_ERR((((uint32_t)rssithres2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_RSSI_THRES_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rssithres2 <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_4_rssi_thres_rssi_thres_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_4_rssi_thres_rssi_thres_1_setf(uint8_t rssithres1)
{
	ASSERT_ERR((((uint32_t)rssithres1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_RSSI_THRES_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)rssithres1 <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_4_rssi_thres_rssi_thres_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_4_rssi_thres_rssi_thres_0_setf(uint8_t rssithres0)
{
	ASSERT_ERR((((uint32_t)rssithres0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_4_RSSI_THRES_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)rssithres0 <<0));
}

/**
 * @brief WIFI_RF_RX_CH_1_LNA_5_RSSI_THRES register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 RSSI_THRES_3              0x0
 *    23:16 RSSI_THRES_2              0x0
 *    15:08 RSSI_THRES_1              0x0
 *    07:00 RSSI_THRES_0              0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_RSSI_THRES_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000254)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_RSSI_THRES_OFFSET      0x00000254
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_RSSI_THRES_INDEX       0x00000095
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_RSSI_THRES_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_1_lna_5_rssi_thres_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_RSSI_THRES_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_5_rssi_thres_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_RSSI_THRES_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_RSSI_THRES_RSSI_THRES_3_MASK    ((uint32_t)0xFF000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_RSSI_THRES_RSSI_THRES_3_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_RSSI_THRES_RSSI_THRES_3_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_RSSI_THRES_RSSI_THRES_2_MASK    ((uint32_t)0x00FF0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_RSSI_THRES_RSSI_THRES_2_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_RSSI_THRES_RSSI_THRES_2_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_RSSI_THRES_RSSI_THRES_1_MASK    ((uint32_t)0x0000FF00)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_RSSI_THRES_RSSI_THRES_1_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_RSSI_THRES_RSSI_THRES_1_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_RSSI_THRES_RSSI_THRES_0_MASK    ((uint32_t)0x000000FF)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_RSSI_THRES_RSSI_THRES_0_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_RSSI_THRES_RSSI_THRES_0_WIDTH    ((uint32_t)0x00000008)

#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_RSSI_THRES_RSSI_THRES_3_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_RSSI_THRES_RSSI_THRES_2_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_RSSI_THRES_RSSI_THRES_1_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_RSSI_THRES_RSSI_THRES_0_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_5_rssi_thres_pack(uint8_t rssi_thres_3, uint8_t rssi_thres_2, uint8_t rssi_thres_1, uint8_t rssi_thres_0)
{
	ASSERT_ERR((((uint32_t)rssi_thres_3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_RSSI_THRES_ADDR,  ((uint32_t)rssi_thres_3 << 24) |((uint32_t)rssi_thres_2 << 16) |((uint32_t)rssi_thres_1 << 8) |((uint32_t)rssi_thres_0 << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_5_rssi_thres_unpack(uint8_t* rssi_thres_3, uint8_t* rssi_thres_2, uint8_t* rssi_thres_1, uint8_t* rssi_thres_0)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_RSSI_THRES_ADDR);

	*rssi_thres_3 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rssi_thres_2 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rssi_thres_1 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*rssi_thres_0 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_5_rssi_thres_rssi_thres_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_5_rssi_thres_rssi_thres_3_setf(uint8_t rssithres3)
{
	ASSERT_ERR((((uint32_t)rssithres3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_RSSI_THRES_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)rssithres3 <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_5_rssi_thres_rssi_thres_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_5_rssi_thres_rssi_thres_2_setf(uint8_t rssithres2)
{
	ASSERT_ERR((((uint32_t)rssithres2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_RSSI_THRES_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rssithres2 <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_5_rssi_thres_rssi_thres_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_5_rssi_thres_rssi_thres_1_setf(uint8_t rssithres1)
{
	ASSERT_ERR((((uint32_t)rssithres1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_RSSI_THRES_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)rssithres1 <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_5_rssi_thres_rssi_thres_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_5_rssi_thres_rssi_thres_0_setf(uint8_t rssithres0)
{
	ASSERT_ERR((((uint32_t)rssithres0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_5_RSSI_THRES_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)rssithres0 <<0));
}

/**
 * @brief WIFI_RF_RX_CH_1_LNA_6_RSSI_THRES register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 RSSI_THRES_3              0x0
 *    23:16 RSSI_THRES_2              0x0
 *    15:08 RSSI_THRES_1              0x0
 *    07:00 RSSI_THRES_0              0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_RSSI_THRES_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000258)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_RSSI_THRES_OFFSET      0x00000258
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_RSSI_THRES_INDEX       0x00000096
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_RSSI_THRES_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_1_lna_6_rssi_thres_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_RSSI_THRES_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_6_rssi_thres_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_RSSI_THRES_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_RSSI_THRES_RSSI_THRES_3_MASK    ((uint32_t)0xFF000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_RSSI_THRES_RSSI_THRES_3_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_RSSI_THRES_RSSI_THRES_3_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_RSSI_THRES_RSSI_THRES_2_MASK    ((uint32_t)0x00FF0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_RSSI_THRES_RSSI_THRES_2_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_RSSI_THRES_RSSI_THRES_2_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_RSSI_THRES_RSSI_THRES_1_MASK    ((uint32_t)0x0000FF00)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_RSSI_THRES_RSSI_THRES_1_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_RSSI_THRES_RSSI_THRES_1_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_RSSI_THRES_RSSI_THRES_0_MASK    ((uint32_t)0x000000FF)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_RSSI_THRES_RSSI_THRES_0_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_RSSI_THRES_RSSI_THRES_0_WIDTH    ((uint32_t)0x00000008)

#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_RSSI_THRES_RSSI_THRES_3_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_RSSI_THRES_RSSI_THRES_2_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_RSSI_THRES_RSSI_THRES_1_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_RSSI_THRES_RSSI_THRES_0_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_6_rssi_thres_pack(uint8_t rssi_thres_3, uint8_t rssi_thres_2, uint8_t rssi_thres_1, uint8_t rssi_thres_0)
{
	ASSERT_ERR((((uint32_t)rssi_thres_3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_RSSI_THRES_ADDR,  ((uint32_t)rssi_thres_3 << 24) |((uint32_t)rssi_thres_2 << 16) |((uint32_t)rssi_thres_1 << 8) |((uint32_t)rssi_thres_0 << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_6_rssi_thres_unpack(uint8_t* rssi_thres_3, uint8_t* rssi_thres_2, uint8_t* rssi_thres_1, uint8_t* rssi_thres_0)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_RSSI_THRES_ADDR);

	*rssi_thres_3 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rssi_thres_2 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rssi_thres_1 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*rssi_thres_0 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_6_rssi_thres_rssi_thres_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_6_rssi_thres_rssi_thres_3_setf(uint8_t rssithres3)
{
	ASSERT_ERR((((uint32_t)rssithres3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_RSSI_THRES_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)rssithres3 <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_6_rssi_thres_rssi_thres_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_6_rssi_thres_rssi_thres_2_setf(uint8_t rssithres2)
{
	ASSERT_ERR((((uint32_t)rssithres2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_RSSI_THRES_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rssithres2 <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_6_rssi_thres_rssi_thres_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_6_rssi_thres_rssi_thres_1_setf(uint8_t rssithres1)
{
	ASSERT_ERR((((uint32_t)rssithres1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_RSSI_THRES_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)rssithres1 <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_6_rssi_thres_rssi_thres_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_6_rssi_thres_rssi_thres_0_setf(uint8_t rssithres0)
{
	ASSERT_ERR((((uint32_t)rssithres0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_6_RSSI_THRES_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)rssithres0 <<0));
}

/**
 * @brief WIFI_RF_RX_CH_1_LNA_7_RSSI_THRES register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 RSSI_THRES_3              0x0
 *    23:16 RSSI_THRES_2              0x0
 *    15:08 RSSI_THRES_1              0x0
 *    07:00 RSSI_THRES_0              0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_RSSI_THRES_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x0000025C)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_RSSI_THRES_OFFSET      0x0000025C
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_RSSI_THRES_INDEX       0x00000097
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_RSSI_THRES_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_1_lna_7_rssi_thres_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_RSSI_THRES_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_7_rssi_thres_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_RSSI_THRES_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_RSSI_THRES_RSSI_THRES_3_MASK    ((uint32_t)0xFF000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_RSSI_THRES_RSSI_THRES_3_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_RSSI_THRES_RSSI_THRES_3_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_RSSI_THRES_RSSI_THRES_2_MASK    ((uint32_t)0x00FF0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_RSSI_THRES_RSSI_THRES_2_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_RSSI_THRES_RSSI_THRES_2_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_RSSI_THRES_RSSI_THRES_1_MASK    ((uint32_t)0x0000FF00)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_RSSI_THRES_RSSI_THRES_1_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_RSSI_THRES_RSSI_THRES_1_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_RSSI_THRES_RSSI_THRES_0_MASK    ((uint32_t)0x000000FF)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_RSSI_THRES_RSSI_THRES_0_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_RSSI_THRES_RSSI_THRES_0_WIDTH    ((uint32_t)0x00000008)

#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_RSSI_THRES_RSSI_THRES_3_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_RSSI_THRES_RSSI_THRES_2_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_RSSI_THRES_RSSI_THRES_1_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_RSSI_THRES_RSSI_THRES_0_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_7_rssi_thres_pack(uint8_t rssi_thres_3, uint8_t rssi_thres_2, uint8_t rssi_thres_1, uint8_t rssi_thres_0)
{
	ASSERT_ERR((((uint32_t)rssi_thres_3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_RSSI_THRES_ADDR,  ((uint32_t)rssi_thres_3 << 24) |((uint32_t)rssi_thres_2 << 16) |((uint32_t)rssi_thres_1 << 8) |((uint32_t)rssi_thres_0 << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_7_rssi_thres_unpack(uint8_t* rssi_thres_3, uint8_t* rssi_thres_2, uint8_t* rssi_thres_1, uint8_t* rssi_thres_0)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_RSSI_THRES_ADDR);

	*rssi_thres_3 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rssi_thres_2 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rssi_thres_1 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*rssi_thres_0 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_7_rssi_thres_rssi_thres_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_7_rssi_thres_rssi_thres_3_setf(uint8_t rssithres3)
{
	ASSERT_ERR((((uint32_t)rssithres3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_RSSI_THRES_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)rssithres3 <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_7_rssi_thres_rssi_thres_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_7_rssi_thres_rssi_thres_2_setf(uint8_t rssithres2)
{
	ASSERT_ERR((((uint32_t)rssithres2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_RSSI_THRES_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rssithres2 <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_7_rssi_thres_rssi_thres_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_7_rssi_thres_rssi_thres_1_setf(uint8_t rssithres1)
{
	ASSERT_ERR((((uint32_t)rssithres1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_RSSI_THRES_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)rssithres1 <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_7_rssi_thres_rssi_thres_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_7_rssi_thres_rssi_thres_0_setf(uint8_t rssithres0)
{
	ASSERT_ERR((((uint32_t)rssithres0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_7_RSSI_THRES_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)rssithres0 <<0));
}

/**
 * @brief WIFI_RF_RX_CH_1_LNA_8_RSSI_THRES register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 RSSI_THRES_3              0x0
 *    23:16 RSSI_THRES_2              0x0
 *    15:08 RSSI_THRES_1              0x0
 *    07:00 RSSI_THRES_0              0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_RSSI_THRES_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000260)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_RSSI_THRES_OFFSET      0x00000260
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_RSSI_THRES_INDEX       0x00000098
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_RSSI_THRES_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_1_lna_8_rssi_thres_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_RSSI_THRES_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_8_rssi_thres_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_RSSI_THRES_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_RSSI_THRES_RSSI_THRES_3_MASK    ((uint32_t)0xFF000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_RSSI_THRES_RSSI_THRES_3_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_RSSI_THRES_RSSI_THRES_3_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_RSSI_THRES_RSSI_THRES_2_MASK    ((uint32_t)0x00FF0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_RSSI_THRES_RSSI_THRES_2_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_RSSI_THRES_RSSI_THRES_2_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_RSSI_THRES_RSSI_THRES_1_MASK    ((uint32_t)0x0000FF00)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_RSSI_THRES_RSSI_THRES_1_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_RSSI_THRES_RSSI_THRES_1_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_RSSI_THRES_RSSI_THRES_0_MASK    ((uint32_t)0x000000FF)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_RSSI_THRES_RSSI_THRES_0_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_RSSI_THRES_RSSI_THRES_0_WIDTH    ((uint32_t)0x00000008)

#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_RSSI_THRES_RSSI_THRES_3_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_RSSI_THRES_RSSI_THRES_2_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_RSSI_THRES_RSSI_THRES_1_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_RSSI_THRES_RSSI_THRES_0_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_8_rssi_thres_pack(uint8_t rssi_thres_3, uint8_t rssi_thres_2, uint8_t rssi_thres_1, uint8_t rssi_thres_0)
{
	ASSERT_ERR((((uint32_t)rssi_thres_3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_RSSI_THRES_ADDR,  ((uint32_t)rssi_thres_3 << 24) |((uint32_t)rssi_thres_2 << 16) |((uint32_t)rssi_thres_1 << 8) |((uint32_t)rssi_thres_0 << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_8_rssi_thres_unpack(uint8_t* rssi_thres_3, uint8_t* rssi_thres_2, uint8_t* rssi_thres_1, uint8_t* rssi_thres_0)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_RSSI_THRES_ADDR);

	*rssi_thres_3 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rssi_thres_2 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rssi_thres_1 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*rssi_thres_0 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_8_rssi_thres_rssi_thres_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_8_rssi_thres_rssi_thres_3_setf(uint8_t rssithres3)
{
	ASSERT_ERR((((uint32_t)rssithres3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_RSSI_THRES_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)rssithres3 <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_8_rssi_thres_rssi_thres_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_8_rssi_thres_rssi_thres_2_setf(uint8_t rssithres2)
{
	ASSERT_ERR((((uint32_t)rssithres2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_RSSI_THRES_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rssithres2 <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_8_rssi_thres_rssi_thres_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_8_rssi_thres_rssi_thres_1_setf(uint8_t rssithres1)
{
	ASSERT_ERR((((uint32_t)rssithres1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_RSSI_THRES_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)rssithres1 <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_8_rssi_thres_rssi_thres_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_8_rssi_thres_rssi_thres_0_setf(uint8_t rssithres0)
{
	ASSERT_ERR((((uint32_t)rssithres0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_8_RSSI_THRES_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)rssithres0 <<0));
}

/**
 * @brief WIFI_RF_RX_CH_1_LNA_9_RSSI_THRES register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 RSSI_THRES_3              0x0
 *    23:16 RSSI_THRES_2              0x0
 *    15:08 RSSI_THRES_1              0x0
 *    07:00 RSSI_THRES_0              0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_RSSI_THRES_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000264)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_RSSI_THRES_OFFSET      0x00000264
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_RSSI_THRES_INDEX       0x00000099
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_RSSI_THRES_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_1_lna_9_rssi_thres_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_RSSI_THRES_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_9_rssi_thres_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_RSSI_THRES_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_RSSI_THRES_RSSI_THRES_3_MASK    ((uint32_t)0xFF000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_RSSI_THRES_RSSI_THRES_3_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_RSSI_THRES_RSSI_THRES_3_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_RSSI_THRES_RSSI_THRES_2_MASK    ((uint32_t)0x00FF0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_RSSI_THRES_RSSI_THRES_2_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_RSSI_THRES_RSSI_THRES_2_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_RSSI_THRES_RSSI_THRES_1_MASK    ((uint32_t)0x0000FF00)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_RSSI_THRES_RSSI_THRES_1_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_RSSI_THRES_RSSI_THRES_1_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_RSSI_THRES_RSSI_THRES_0_MASK    ((uint32_t)0x000000FF)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_RSSI_THRES_RSSI_THRES_0_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_RSSI_THRES_RSSI_THRES_0_WIDTH    ((uint32_t)0x00000008)

#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_RSSI_THRES_RSSI_THRES_3_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_RSSI_THRES_RSSI_THRES_2_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_RSSI_THRES_RSSI_THRES_1_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_RSSI_THRES_RSSI_THRES_0_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_9_rssi_thres_pack(uint8_t rssi_thres_3, uint8_t rssi_thres_2, uint8_t rssi_thres_1, uint8_t rssi_thres_0)
{
	ASSERT_ERR((((uint32_t)rssi_thres_3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_RSSI_THRES_ADDR,  ((uint32_t)rssi_thres_3 << 24) |((uint32_t)rssi_thres_2 << 16) |((uint32_t)rssi_thres_1 << 8) |((uint32_t)rssi_thres_0 << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_9_rssi_thres_unpack(uint8_t* rssi_thres_3, uint8_t* rssi_thres_2, uint8_t* rssi_thres_1, uint8_t* rssi_thres_0)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_RSSI_THRES_ADDR);

	*rssi_thres_3 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rssi_thres_2 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rssi_thres_1 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*rssi_thres_0 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_9_rssi_thres_rssi_thres_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_9_rssi_thres_rssi_thres_3_setf(uint8_t rssithres3)
{
	ASSERT_ERR((((uint32_t)rssithres3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_RSSI_THRES_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)rssithres3 <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_9_rssi_thres_rssi_thres_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_9_rssi_thres_rssi_thres_2_setf(uint8_t rssithres2)
{
	ASSERT_ERR((((uint32_t)rssithres2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_RSSI_THRES_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rssithres2 <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_9_rssi_thres_rssi_thres_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_9_rssi_thres_rssi_thres_1_setf(uint8_t rssithres1)
{
	ASSERT_ERR((((uint32_t)rssithres1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_RSSI_THRES_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)rssithres1 <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_9_rssi_thres_rssi_thres_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_9_rssi_thres_rssi_thres_0_setf(uint8_t rssithres0)
{
	ASSERT_ERR((((uint32_t)rssithres0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_9_RSSI_THRES_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)rssithres0 <<0));
}

/**
 * @brief WIFI_RF_RX_CH_1_LNA_10_RSSI_THRES register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 RSSI_THRES_3              0x0
 *    23:16 RSSI_THRES_2              0x0
 *    15:08 RSSI_THRES_1              0x0
 *    07:00 RSSI_THRES_0              0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_RSSI_THRES_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000268)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_RSSI_THRES_OFFSET      0x00000268
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_RSSI_THRES_INDEX       0x0000009A
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_RSSI_THRES_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_1_lna_10_rssi_thres_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_RSSI_THRES_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_10_rssi_thres_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_RSSI_THRES_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_RSSI_THRES_RSSI_THRES_3_MASK    ((uint32_t)0xFF000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_RSSI_THRES_RSSI_THRES_3_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_RSSI_THRES_RSSI_THRES_3_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_RSSI_THRES_RSSI_THRES_2_MASK    ((uint32_t)0x00FF0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_RSSI_THRES_RSSI_THRES_2_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_RSSI_THRES_RSSI_THRES_2_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_RSSI_THRES_RSSI_THRES_1_MASK    ((uint32_t)0x0000FF00)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_RSSI_THRES_RSSI_THRES_1_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_RSSI_THRES_RSSI_THRES_1_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_RSSI_THRES_RSSI_THRES_0_MASK    ((uint32_t)0x000000FF)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_RSSI_THRES_RSSI_THRES_0_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_RSSI_THRES_RSSI_THRES_0_WIDTH    ((uint32_t)0x00000008)

#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_RSSI_THRES_RSSI_THRES_3_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_RSSI_THRES_RSSI_THRES_2_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_RSSI_THRES_RSSI_THRES_1_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_RSSI_THRES_RSSI_THRES_0_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_10_rssi_thres_pack(uint8_t rssi_thres_3, uint8_t rssi_thres_2, uint8_t rssi_thres_1, uint8_t rssi_thres_0)
{
	ASSERT_ERR((((uint32_t)rssi_thres_3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_RSSI_THRES_ADDR,  ((uint32_t)rssi_thres_3 << 24) |((uint32_t)rssi_thres_2 << 16) |((uint32_t)rssi_thres_1 << 8) |((uint32_t)rssi_thres_0 << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_10_rssi_thres_unpack(uint8_t* rssi_thres_3, uint8_t* rssi_thres_2, uint8_t* rssi_thres_1, uint8_t* rssi_thres_0)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_RSSI_THRES_ADDR);

	*rssi_thres_3 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rssi_thres_2 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rssi_thres_1 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*rssi_thres_0 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_10_rssi_thres_rssi_thres_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_10_rssi_thres_rssi_thres_3_setf(uint8_t rssithres3)
{
	ASSERT_ERR((((uint32_t)rssithres3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_RSSI_THRES_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)rssithres3 <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_10_rssi_thres_rssi_thres_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_10_rssi_thres_rssi_thres_2_setf(uint8_t rssithres2)
{
	ASSERT_ERR((((uint32_t)rssithres2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_RSSI_THRES_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rssithres2 <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_10_rssi_thres_rssi_thres_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_10_rssi_thres_rssi_thres_1_setf(uint8_t rssithres1)
{
	ASSERT_ERR((((uint32_t)rssithres1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_RSSI_THRES_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)rssithres1 <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_10_rssi_thres_rssi_thres_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_10_rssi_thres_rssi_thres_0_setf(uint8_t rssithres0)
{
	ASSERT_ERR((((uint32_t)rssithres0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_10_RSSI_THRES_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)rssithres0 <<0));
}

/**
 * @brief WIFI_RF_RX_CH_1_LNA_11_RSSI_THRES register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 RSSI_THRES_3              0x0
 *    23:16 RSSI_THRES_2              0x0
 *    15:08 RSSI_THRES_1              0x0
 *    07:00 RSSI_THRES_0              0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_RSSI_THRES_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x0000026C)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_RSSI_THRES_OFFSET      0x0000026C
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_RSSI_THRES_INDEX       0x0000009B
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_RSSI_THRES_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_1_lna_11_rssi_thres_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_RSSI_THRES_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_11_rssi_thres_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_RSSI_THRES_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_RSSI_THRES_RSSI_THRES_3_MASK    ((uint32_t)0xFF000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_RSSI_THRES_RSSI_THRES_3_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_RSSI_THRES_RSSI_THRES_3_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_RSSI_THRES_RSSI_THRES_2_MASK    ((uint32_t)0x00FF0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_RSSI_THRES_RSSI_THRES_2_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_RSSI_THRES_RSSI_THRES_2_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_RSSI_THRES_RSSI_THRES_1_MASK    ((uint32_t)0x0000FF00)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_RSSI_THRES_RSSI_THRES_1_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_RSSI_THRES_RSSI_THRES_1_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_RSSI_THRES_RSSI_THRES_0_MASK    ((uint32_t)0x000000FF)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_RSSI_THRES_RSSI_THRES_0_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_RSSI_THRES_RSSI_THRES_0_WIDTH    ((uint32_t)0x00000008)

#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_RSSI_THRES_RSSI_THRES_3_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_RSSI_THRES_RSSI_THRES_2_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_RSSI_THRES_RSSI_THRES_1_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_RSSI_THRES_RSSI_THRES_0_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_11_rssi_thres_pack(uint8_t rssi_thres_3, uint8_t rssi_thres_2, uint8_t rssi_thres_1, uint8_t rssi_thres_0)
{
	ASSERT_ERR((((uint32_t)rssi_thres_3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_RSSI_THRES_ADDR,  ((uint32_t)rssi_thres_3 << 24) |((uint32_t)rssi_thres_2 << 16) |((uint32_t)rssi_thres_1 << 8) |((uint32_t)rssi_thres_0 << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_11_rssi_thres_unpack(uint8_t* rssi_thres_3, uint8_t* rssi_thres_2, uint8_t* rssi_thres_1, uint8_t* rssi_thres_0)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_RSSI_THRES_ADDR);

	*rssi_thres_3 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rssi_thres_2 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rssi_thres_1 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*rssi_thres_0 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_11_rssi_thres_rssi_thres_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_11_rssi_thres_rssi_thres_3_setf(uint8_t rssithres3)
{
	ASSERT_ERR((((uint32_t)rssithres3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_RSSI_THRES_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)rssithres3 <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_11_rssi_thres_rssi_thres_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_11_rssi_thres_rssi_thres_2_setf(uint8_t rssithres2)
{
	ASSERT_ERR((((uint32_t)rssithres2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_RSSI_THRES_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rssithres2 <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_11_rssi_thres_rssi_thres_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_11_rssi_thres_rssi_thres_1_setf(uint8_t rssithres1)
{
	ASSERT_ERR((((uint32_t)rssithres1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_RSSI_THRES_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)rssithres1 <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_11_rssi_thres_rssi_thres_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_11_rssi_thres_rssi_thres_0_setf(uint8_t rssithres0)
{
	ASSERT_ERR((((uint32_t)rssithres0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_11_RSSI_THRES_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)rssithres0 <<0));
}

/**
 * @brief WIFI_RF_RX_CH_1_LNA_12_RSSI_THRES register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 RSSI_THRES_3              0x0
 *    23:16 RSSI_THRES_2              0x0
 *    15:08 RSSI_THRES_1              0x0
 *    07:00 RSSI_THRES_0              0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_RSSI_THRES_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000270)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_RSSI_THRES_OFFSET      0x00000270
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_RSSI_THRES_INDEX       0x0000009C
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_RSSI_THRES_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_1_lna_12_rssi_thres_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_RSSI_THRES_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_12_rssi_thres_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_RSSI_THRES_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_RSSI_THRES_RSSI_THRES_3_MASK    ((uint32_t)0xFF000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_RSSI_THRES_RSSI_THRES_3_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_RSSI_THRES_RSSI_THRES_3_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_RSSI_THRES_RSSI_THRES_2_MASK    ((uint32_t)0x00FF0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_RSSI_THRES_RSSI_THRES_2_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_RSSI_THRES_RSSI_THRES_2_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_RSSI_THRES_RSSI_THRES_1_MASK    ((uint32_t)0x0000FF00)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_RSSI_THRES_RSSI_THRES_1_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_RSSI_THRES_RSSI_THRES_1_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_RSSI_THRES_RSSI_THRES_0_MASK    ((uint32_t)0x000000FF)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_RSSI_THRES_RSSI_THRES_0_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_RSSI_THRES_RSSI_THRES_0_WIDTH    ((uint32_t)0x00000008)

#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_RSSI_THRES_RSSI_THRES_3_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_RSSI_THRES_RSSI_THRES_2_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_RSSI_THRES_RSSI_THRES_1_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_RSSI_THRES_RSSI_THRES_0_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_12_rssi_thres_pack(uint8_t rssi_thres_3, uint8_t rssi_thres_2, uint8_t rssi_thres_1, uint8_t rssi_thres_0)
{
	ASSERT_ERR((((uint32_t)rssi_thres_3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_RSSI_THRES_ADDR,  ((uint32_t)rssi_thres_3 << 24) |((uint32_t)rssi_thres_2 << 16) |((uint32_t)rssi_thres_1 << 8) |((uint32_t)rssi_thres_0 << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_12_rssi_thres_unpack(uint8_t* rssi_thres_3, uint8_t* rssi_thres_2, uint8_t* rssi_thres_1, uint8_t* rssi_thres_0)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_RSSI_THRES_ADDR);

	*rssi_thres_3 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rssi_thres_2 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rssi_thres_1 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*rssi_thres_0 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_12_rssi_thres_rssi_thres_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_12_rssi_thres_rssi_thres_3_setf(uint8_t rssithres3)
{
	ASSERT_ERR((((uint32_t)rssithres3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_RSSI_THRES_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)rssithres3 <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_12_rssi_thres_rssi_thres_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_12_rssi_thres_rssi_thres_2_setf(uint8_t rssithres2)
{
	ASSERT_ERR((((uint32_t)rssithres2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_RSSI_THRES_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rssithres2 <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_12_rssi_thres_rssi_thres_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_12_rssi_thres_rssi_thres_1_setf(uint8_t rssithres1)
{
	ASSERT_ERR((((uint32_t)rssithres1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_RSSI_THRES_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)rssithres1 <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_12_rssi_thres_rssi_thres_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_12_rssi_thres_rssi_thres_0_setf(uint8_t rssithres0)
{
	ASSERT_ERR((((uint32_t)rssithres0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_12_RSSI_THRES_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)rssithres0 <<0));
}

/**
 * @brief WIFI_RF_RX_CH_1_LNA_13_RSSI_THRES register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 RSSI_THRES_3              0x0
 *    23:16 RSSI_THRES_2              0x0
 *    15:08 RSSI_THRES_1              0x0
 *    07:00 RSSI_THRES_0              0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_RSSI_THRES_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000274)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_RSSI_THRES_OFFSET      0x00000274
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_RSSI_THRES_INDEX       0x0000009D
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_RSSI_THRES_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_1_lna_13_rssi_thres_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_RSSI_THRES_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_13_rssi_thres_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_RSSI_THRES_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_RSSI_THRES_RSSI_THRES_3_MASK    ((uint32_t)0xFF000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_RSSI_THRES_RSSI_THRES_3_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_RSSI_THRES_RSSI_THRES_3_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_RSSI_THRES_RSSI_THRES_2_MASK    ((uint32_t)0x00FF0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_RSSI_THRES_RSSI_THRES_2_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_RSSI_THRES_RSSI_THRES_2_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_RSSI_THRES_RSSI_THRES_1_MASK    ((uint32_t)0x0000FF00)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_RSSI_THRES_RSSI_THRES_1_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_RSSI_THRES_RSSI_THRES_1_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_RSSI_THRES_RSSI_THRES_0_MASK    ((uint32_t)0x000000FF)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_RSSI_THRES_RSSI_THRES_0_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_RSSI_THRES_RSSI_THRES_0_WIDTH    ((uint32_t)0x00000008)

#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_RSSI_THRES_RSSI_THRES_3_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_RSSI_THRES_RSSI_THRES_2_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_RSSI_THRES_RSSI_THRES_1_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_RSSI_THRES_RSSI_THRES_0_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_13_rssi_thres_pack(uint8_t rssi_thres_3, uint8_t rssi_thres_2, uint8_t rssi_thres_1, uint8_t rssi_thres_0)
{
	ASSERT_ERR((((uint32_t)rssi_thres_3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_RSSI_THRES_ADDR,  ((uint32_t)rssi_thres_3 << 24) |((uint32_t)rssi_thres_2 << 16) |((uint32_t)rssi_thres_1 << 8) |((uint32_t)rssi_thres_0 << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_13_rssi_thres_unpack(uint8_t* rssi_thres_3, uint8_t* rssi_thres_2, uint8_t* rssi_thres_1, uint8_t* rssi_thres_0)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_RSSI_THRES_ADDR);

	*rssi_thres_3 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rssi_thres_2 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rssi_thres_1 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*rssi_thres_0 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_13_rssi_thres_rssi_thres_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_13_rssi_thres_rssi_thres_3_setf(uint8_t rssithres3)
{
	ASSERT_ERR((((uint32_t)rssithres3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_RSSI_THRES_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)rssithres3 <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_13_rssi_thres_rssi_thres_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_13_rssi_thres_rssi_thres_2_setf(uint8_t rssithres2)
{
	ASSERT_ERR((((uint32_t)rssithres2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_RSSI_THRES_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rssithres2 <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_13_rssi_thres_rssi_thres_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_13_rssi_thres_rssi_thres_1_setf(uint8_t rssithres1)
{
	ASSERT_ERR((((uint32_t)rssithres1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_RSSI_THRES_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)rssithres1 <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_13_rssi_thres_rssi_thres_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_13_rssi_thres_rssi_thres_0_setf(uint8_t rssithres0)
{
	ASSERT_ERR((((uint32_t)rssithres0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_13_RSSI_THRES_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)rssithres0 <<0));
}

/**
 * @brief WIFI_RF_RX_CH_1_LNA_14_RSSI_THRES register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 RSSI_THRES_3              0x0
 *    23:16 RSSI_THRES_2              0x0
 *    15:08 RSSI_THRES_1              0x0
 *    07:00 RSSI_THRES_0              0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_RSSI_THRES_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000278)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_RSSI_THRES_OFFSET      0x00000278
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_RSSI_THRES_INDEX       0x0000009E
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_RSSI_THRES_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_1_lna_14_rssi_thres_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_RSSI_THRES_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_14_rssi_thres_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_RSSI_THRES_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_RSSI_THRES_RSSI_THRES_3_MASK    ((uint32_t)0xFF000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_RSSI_THRES_RSSI_THRES_3_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_RSSI_THRES_RSSI_THRES_3_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_RSSI_THRES_RSSI_THRES_2_MASK    ((uint32_t)0x00FF0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_RSSI_THRES_RSSI_THRES_2_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_RSSI_THRES_RSSI_THRES_2_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_RSSI_THRES_RSSI_THRES_1_MASK    ((uint32_t)0x0000FF00)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_RSSI_THRES_RSSI_THRES_1_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_RSSI_THRES_RSSI_THRES_1_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_RSSI_THRES_RSSI_THRES_0_MASK    ((uint32_t)0x000000FF)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_RSSI_THRES_RSSI_THRES_0_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_RSSI_THRES_RSSI_THRES_0_WIDTH    ((uint32_t)0x00000008)

#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_RSSI_THRES_RSSI_THRES_3_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_RSSI_THRES_RSSI_THRES_2_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_RSSI_THRES_RSSI_THRES_1_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_RSSI_THRES_RSSI_THRES_0_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_14_rssi_thres_pack(uint8_t rssi_thres_3, uint8_t rssi_thres_2, uint8_t rssi_thres_1, uint8_t rssi_thres_0)
{
	ASSERT_ERR((((uint32_t)rssi_thres_3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_RSSI_THRES_ADDR,  ((uint32_t)rssi_thres_3 << 24) |((uint32_t)rssi_thres_2 << 16) |((uint32_t)rssi_thres_1 << 8) |((uint32_t)rssi_thres_0 << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_14_rssi_thres_unpack(uint8_t* rssi_thres_3, uint8_t* rssi_thres_2, uint8_t* rssi_thres_1, uint8_t* rssi_thres_0)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_RSSI_THRES_ADDR);

	*rssi_thres_3 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rssi_thres_2 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rssi_thres_1 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*rssi_thres_0 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_14_rssi_thres_rssi_thres_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_14_rssi_thres_rssi_thres_3_setf(uint8_t rssithres3)
{
	ASSERT_ERR((((uint32_t)rssithres3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_RSSI_THRES_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)rssithres3 <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_14_rssi_thres_rssi_thres_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_14_rssi_thres_rssi_thres_2_setf(uint8_t rssithres2)
{
	ASSERT_ERR((((uint32_t)rssithres2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_RSSI_THRES_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rssithres2 <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_14_rssi_thres_rssi_thres_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_14_rssi_thres_rssi_thres_1_setf(uint8_t rssithres1)
{
	ASSERT_ERR((((uint32_t)rssithres1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_RSSI_THRES_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)rssithres1 <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_14_rssi_thres_rssi_thres_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_14_rssi_thres_rssi_thres_0_setf(uint8_t rssithres0)
{
	ASSERT_ERR((((uint32_t)rssithres0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_14_RSSI_THRES_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)rssithres0 <<0));
}

/**
 * @brief WIFI_RF_RX_CH_1_LNA_15_RSSI_THRES register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 RSSI_THRES_3              0x0
 *    23:16 RSSI_THRES_2              0x0
 *    15:08 RSSI_THRES_1              0x0
 *    07:00 RSSI_THRES_0              0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_RSSI_THRES_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x0000027C)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_RSSI_THRES_OFFSET      0x0000027C
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_RSSI_THRES_INDEX       0x0000009F
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_RSSI_THRES_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_1_lna_15_rssi_thres_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_RSSI_THRES_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_15_rssi_thres_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_RSSI_THRES_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_RSSI_THRES_RSSI_THRES_3_MASK    ((uint32_t)0xFF000000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_RSSI_THRES_RSSI_THRES_3_LSB    24
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_RSSI_THRES_RSSI_THRES_3_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_RSSI_THRES_RSSI_THRES_2_MASK    ((uint32_t)0x00FF0000)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_RSSI_THRES_RSSI_THRES_2_LSB    16
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_RSSI_THRES_RSSI_THRES_2_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_RSSI_THRES_RSSI_THRES_1_MASK    ((uint32_t)0x0000FF00)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_RSSI_THRES_RSSI_THRES_1_LSB    8
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_RSSI_THRES_RSSI_THRES_1_WIDTH    ((uint32_t)0x00000008)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_RSSI_THRES_RSSI_THRES_0_MASK    ((uint32_t)0x000000FF)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_RSSI_THRES_RSSI_THRES_0_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_RSSI_THRES_RSSI_THRES_0_WIDTH    ((uint32_t)0x00000008)

#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_RSSI_THRES_RSSI_THRES_3_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_RSSI_THRES_RSSI_THRES_2_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_RSSI_THRES_RSSI_THRES_1_RST    0x0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_RSSI_THRES_RSSI_THRES_0_RST    0x0

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_15_rssi_thres_pack(uint8_t rssi_thres_3, uint8_t rssi_thres_2, uint8_t rssi_thres_1, uint8_t rssi_thres_0)
{
	ASSERT_ERR((((uint32_t)rssi_thres_3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)rssi_thres_0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_RSSI_THRES_ADDR,  ((uint32_t)rssi_thres_3 << 24) |((uint32_t)rssi_thres_2 << 16) |((uint32_t)rssi_thres_1 << 8) |((uint32_t)rssi_thres_0 << 0));
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_15_rssi_thres_unpack(uint8_t* rssi_thres_3, uint8_t* rssi_thres_2, uint8_t* rssi_thres_1, uint8_t* rssi_thres_0)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_RSSI_THRES_ADDR);

	*rssi_thres_3 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rssi_thres_2 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rssi_thres_1 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*rssi_thres_0 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_15_rssi_thres_rssi_thres_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_15_rssi_thres_rssi_thres_3_setf(uint8_t rssithres3)
{
	ASSERT_ERR((((uint32_t)rssithres3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_RSSI_THRES_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)rssithres3 <<24));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_15_rssi_thres_rssi_thres_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_15_rssi_thres_rssi_thres_2_setf(uint8_t rssithres2)
{
	ASSERT_ERR((((uint32_t)rssithres2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_RSSI_THRES_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rssithres2 <<16));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_15_rssi_thres_rssi_thres_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_15_rssi_thres_rssi_thres_1_setf(uint8_t rssithres1)
{
	ASSERT_ERR((((uint32_t)rssithres1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_RSSI_THRES_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)rssithres1 <<8));
}
__INLINE uint8_t rfic_wrap_wifi_rf_rx_ch_1_lna_15_rssi_thres_rssi_thres_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_RSSI_THRES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_lna_15_rssi_thres_rssi_thres_0_setf(uint8_t rssithres0)
{
	ASSERT_ERR((((uint32_t)rssithres0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_RSSI_THRES_ADDR, (REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_LNA_15_RSSI_THRES_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)rssithres0 <<0));
}

/**
 * @brief WIFI_RF_RX_CH_0_RSSI_GAIN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RSSI_GAIN_SEL             0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_0_RSSI_GAIN_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000280)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_RSSI_GAIN_OFFSET      0x00000280
#define RFIC_WRAP_WIFI_RF_RX_CH_0_RSSI_GAIN_INDEX       0x000000A0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_RSSI_GAIN_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_0_rssi_gain_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_RSSI_GAIN_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_0_rssi_gain_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_RSSI_GAIN_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_0_RSSI_GAIN_RSSI_GAIN_SEL_MASK    ((uint32_t)0xFFFFFFFF)
#define RFIC_WRAP_WIFI_RF_RX_CH_0_RSSI_GAIN_RSSI_GAIN_SEL_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_0_RSSI_GAIN_RSSI_GAIN_SEL_WIDTH    ((uint32_t)0x00000020)

#define RFIC_WRAP_WIFI_RF_RX_CH_0_RSSI_GAIN_RSSI_GAIN_SEL_RST    0x0

__INLINE uint32_t rfic_wrap_wifi_rf_rx_ch_0_rssi_gain_rssi_gain_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_0_RSSI_GAIN_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_0_rssi_gain_rssi_gain_sel_setf(uint32_t rssigainsel)
{
	ASSERT_ERR((((uint32_t)rssigainsel << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_0_RSSI_GAIN_ADDR, (uint32_t)rssigainsel << 0);
}

/**
 * @brief WIFI_RF_RX_CH_1_RSSI_GAIN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RSSI_GAIN_SEL             0x0
 * </pre>
 */
#define RFIC_WRAP_WIFI_RF_RX_CH_1_RSSI_GAIN_ADDR        (REG_RFIC_WRAP_BASE_ADDR+0x00000284)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_RSSI_GAIN_OFFSET      0x00000284
#define RFIC_WRAP_WIFI_RF_RX_CH_1_RSSI_GAIN_INDEX       0x000000A1
#define RFIC_WRAP_WIFI_RF_RX_CH_1_RSSI_GAIN_RESET       0x00000000

__INLINE uint32_t  rfic_wrap_wifi_rf_rx_ch_1_rssi_gain_get(void)
{
	return REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_RSSI_GAIN_ADDR);
}

__INLINE void rfic_wrap_wifi_rf_rx_ch_1_rssi_gain_set(uint32_t value)
{
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_RSSI_GAIN_ADDR, value);
}

// field definitions
#define RFIC_WRAP_WIFI_RF_RX_CH_1_RSSI_GAIN_RSSI_GAIN_SEL_MASK    ((uint32_t)0xFFFFFFFF)
#define RFIC_WRAP_WIFI_RF_RX_CH_1_RSSI_GAIN_RSSI_GAIN_SEL_LSB    0
#define RFIC_WRAP_WIFI_RF_RX_CH_1_RSSI_GAIN_RSSI_GAIN_SEL_WIDTH    ((uint32_t)0x00000020)

#define RFIC_WRAP_WIFI_RF_RX_CH_1_RSSI_GAIN_RSSI_GAIN_SEL_RST    0x0

__INLINE uint32_t rfic_wrap_wifi_rf_rx_ch_1_rssi_gain_rssi_gain_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(RFIC_WRAP_WIFI_RF_RX_CH_1_RSSI_GAIN_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void rfic_wrap_wifi_rf_rx_ch_1_rssi_gain_rssi_gain_sel_setf(uint32_t rssigainsel)
{
	ASSERT_ERR((((uint32_t)rssigainsel << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RFIC_WRAP_WIFI_RF_RX_CH_1_RSSI_GAIN_ADDR, (uint32_t)rssigainsel << 0);
}


#undef DBG_FILEID
#endif //_REG_RFIC_WRAP_H_

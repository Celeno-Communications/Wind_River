#ifndef _REG_SMU_H_
#define _REG_SMU_H_

#include <stdint.h>
#include "phy/_reg_smu.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define DBG_FILEID __REG_SMU__H__FILEID__

#define REG_SMU_COUNT  81


/**
 * @brief RESERVED_RW register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RESERVED_RW               0x0
 * </pre>
 */
#define SMU_RESERVED_RW_ADDR        (REG_SMU_BASE_ADDR+0x00000000)
#define SMU_RESERVED_RW_OFFSET      0x00000000
#define SMU_RESERVED_RW_INDEX       0x00000000
#define SMU_RESERVED_RW_RESET       0x00000000

__INLINE uint32_t  smu_reserved_rw_get(void)
{
	return REG_PL_RD(SMU_RESERVED_RW_ADDR);
}

__INLINE void smu_reserved_rw_set(uint32_t value)
{
	REG_PL_WR(SMU_RESERVED_RW_ADDR, value);
}

// field definitions
#define SMU_RESERVED_RW_RESERVED_RW_MASK    ((uint32_t)0xFFFFFFFF)
#define SMU_RESERVED_RW_RESERVED_RW_LSB     0
#define SMU_RESERVED_RW_RESERVED_RW_WIDTH    ((uint32_t)0x00000020)

#define SMU_RESERVED_RW_RESERVED_RW_RST     0x0

__INLINE uint32_t smu_reserved_rw_reserved_rw_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RESERVED_RW_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void smu_reserved_rw_reserved_rw_setf(uint32_t reservedrw)
{
	ASSERT_ERR((((uint32_t)reservedrw << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SMU_RESERVED_RW_ADDR, (uint32_t)reservedrw << 0);
}

/**
 * @brief START_AND_STOP register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 FIC_ISO_DELAY             0x10
 *    23:16 RU_READY                  0x0
 *    15    FORCE_FIC_ISOLATION       1              
 *    12    START_AUTO                0              
 *    08    LOAD_FILTER               0              
 *    04    STOP                      0              
 *    00    START                     0              
 * </pre>
 */
#define SMU_START_AND_STOP_ADDR        (REG_SMU_BASE_ADDR+0x00000004)
#define SMU_START_AND_STOP_OFFSET      0x00000004
#define SMU_START_AND_STOP_INDEX       0x00000001
#define SMU_START_AND_STOP_RESET       0x10008000

__INLINE uint32_t  smu_start_and_stop_get(void)
{
	return REG_PL_RD(SMU_START_AND_STOP_ADDR);
}

__INLINE void smu_start_and_stop_set(uint32_t value)
{
	REG_PL_WR(SMU_START_AND_STOP_ADDR, value);
}

// field definitions
#define SMU_START_AND_STOP_FIC_ISO_DELAY_MASK    ((uint32_t)0xFF000000)
#define SMU_START_AND_STOP_FIC_ISO_DELAY_LSB    24
#define SMU_START_AND_STOP_FIC_ISO_DELAY_WIDTH    ((uint32_t)0x00000008)
#define SMU_START_AND_STOP_RU_READY_MASK    ((uint32_t)0x00FF0000)
#define SMU_START_AND_STOP_RU_READY_LSB     16
#define SMU_START_AND_STOP_RU_READY_WIDTH    ((uint32_t)0x00000008)
#define SMU_START_AND_STOP_FORCE_FIC_ISOLATION_BIT    ((uint32_t)0x00008000)
#define SMU_START_AND_STOP_FORCE_FIC_ISOLATION_POS    15
#define SMU_START_AND_STOP_START_AUTO_BIT    ((uint32_t)0x00001000)
#define SMU_START_AND_STOP_START_AUTO_POS    12
#define SMU_START_AND_STOP_LOAD_FILTER_BIT    ((uint32_t)0x00000100)
#define SMU_START_AND_STOP_LOAD_FILTER_POS    8
#define SMU_START_AND_STOP_STOP_BIT         ((uint32_t)0x00000010)
#define SMU_START_AND_STOP_STOP_POS         4
#define SMU_START_AND_STOP_START_BIT        ((uint32_t)0x00000001)
#define SMU_START_AND_STOP_START_POS        0

#define SMU_START_AND_STOP_FIC_ISO_DELAY_RST    0x10
#define SMU_START_AND_STOP_RU_READY_RST     0x0
#define SMU_START_AND_STOP_FORCE_FIC_ISOLATION_RST    0x1
#define SMU_START_AND_STOP_START_AUTO_RST    0x0
#define SMU_START_AND_STOP_LOAD_FILTER_RST    0x0
#define SMU_START_AND_STOP_STOP_RST         0x0
#define SMU_START_AND_STOP_START_RST        0x0

__INLINE void smu_start_and_stop_pack(uint8_t fic_iso_delay, uint8_t ru_ready, uint8_t force_fic_isolation, uint8_t start_auto, uint8_t load_filter, uint8_t stop, uint8_t start)
{
	ASSERT_ERR((((uint32_t)fic_iso_delay << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)ru_ready << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)force_fic_isolation << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)start_auto << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)load_filter << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)stop << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)start << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(SMU_START_AND_STOP_ADDR,  ((uint32_t)fic_iso_delay << 24) |((uint32_t)ru_ready << 16) |((uint32_t)force_fic_isolation << 15) |((uint32_t)start_auto << 12) |((uint32_t)load_filter << 8) |((uint32_t)stop << 4) |((uint32_t)start << 0));
}

__INLINE void smu_start_and_stop_unpack(uint8_t* fic_iso_delay, uint8_t* ru_ready, uint8_t* force_fic_isolation, uint8_t* start_auto, uint8_t* load_filter, uint8_t* stop, uint8_t* start)
{
	uint32_t localVal = REG_PL_RD(SMU_START_AND_STOP_ADDR);

	*fic_iso_delay = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*ru_ready = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*force_fic_isolation = (localVal & ((uint32_t)0x00008000)) >>  15;
	*start_auto = (localVal & ((uint32_t)0x00001000)) >>  12;
	*load_filter = (localVal & ((uint32_t)0x00000100)) >>  8;
	*stop = (localVal & ((uint32_t)0x00000010)) >>  4;
	*start = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t smu_start_and_stop_fic_iso_delay_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_START_AND_STOP_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void smu_start_and_stop_fic_iso_delay_setf(uint8_t ficisodelay)
{
	ASSERT_ERR((((uint32_t)ficisodelay << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(SMU_START_AND_STOP_ADDR, (REG_PL_RD(SMU_START_AND_STOP_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)ficisodelay <<24));
}
__INLINE uint8_t smu_start_and_stop_ru_ready_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_START_AND_STOP_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void smu_start_and_stop_ru_ready_setf(uint8_t ruready)
{
	ASSERT_ERR((((uint32_t)ruready << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(SMU_START_AND_STOP_ADDR, (REG_PL_RD(SMU_START_AND_STOP_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)ruready <<16));
}
__INLINE uint8_t smu_start_and_stop_force_fic_isolation_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_START_AND_STOP_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void smu_start_and_stop_force_fic_isolation_setf(uint8_t forceficisolation)
{
	ASSERT_ERR((((uint32_t)forceficisolation << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(SMU_START_AND_STOP_ADDR, (REG_PL_RD(SMU_START_AND_STOP_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)forceficisolation <<15));
}
__INLINE void smu_start_and_stop_start_auto_setf(uint8_t startauto)
{
	ASSERT_ERR((((uint32_t)startauto << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(SMU_START_AND_STOP_ADDR, (REG_PL_RD(SMU_START_AND_STOP_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)startauto <<12));
}
__INLINE void smu_start_and_stop_load_filter_setf(uint8_t loadfilter)
{
	ASSERT_ERR((((uint32_t)loadfilter << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(SMU_START_AND_STOP_ADDR, (REG_PL_RD(SMU_START_AND_STOP_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)loadfilter <<8));
}
__INLINE void smu_start_and_stop_stop_setf(uint8_t stop)
{
	ASSERT_ERR((((uint32_t)stop << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(SMU_START_AND_STOP_ADDR, (REG_PL_RD(SMU_START_AND_STOP_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)stop <<4));
}
__INLINE void smu_start_and_stop_start_setf(uint8_t start)
{
	ASSERT_ERR((((uint32_t)start << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(SMU_START_AND_STOP_ADDR, (REG_PL_RD(SMU_START_AND_STOP_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)start <<0));
}

/**
 * @brief COMMON_CFG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:24 NB_RU                     0x0
 *    22:20 DYNAMIC_BYPASS_EN         0x0
 *    19    MODE_LEG_52               0              
 *    17:16 INPUT_DECIMATION          0x0
 *    15:14 OUTPUT_SHIFT              0x0
 *    13:12 INPUT_SHIFT               0x0
 *    11:10 FRAME_BW                  0x0
 *    09    MODE_HE                   0              
 *    08    CONJUGATE                 0              
 *    06    REMOVE_PILOT_EN           0              
 *    05    POST_ROT_EN               0              
 *    04    PRE_ROT_EN                0              
 *    02:00 NB_ANT                    0x0
 * </pre>
 */
#define SMU_COMMON_CFG_ADDR        (REG_SMU_BASE_ADDR+0x00000008)
#define SMU_COMMON_CFG_OFFSET      0x00000008
#define SMU_COMMON_CFG_INDEX       0x00000002
#define SMU_COMMON_CFG_RESET       0x00000000

__INLINE uint32_t  smu_common_cfg_get(void)
{
	return REG_PL_RD(SMU_COMMON_CFG_ADDR);
}

__INLINE void smu_common_cfg_set(uint32_t value)
{
	REG_PL_WR(SMU_COMMON_CFG_ADDR, value);
}

// field definitions
#define SMU_COMMON_CFG_NB_RU_MASK           ((uint32_t)0x0F000000)
#define SMU_COMMON_CFG_NB_RU_LSB            24
#define SMU_COMMON_CFG_NB_RU_WIDTH          ((uint32_t)0x00000004)
#define SMU_COMMON_CFG_DYNAMIC_BYPASS_EN_MASK    ((uint32_t)0x00700000)
#define SMU_COMMON_CFG_DYNAMIC_BYPASS_EN_LSB    20
#define SMU_COMMON_CFG_DYNAMIC_BYPASS_EN_WIDTH    ((uint32_t)0x00000003)
#define SMU_COMMON_CFG_MODE_LEG_52_BIT      ((uint32_t)0x00080000)
#define SMU_COMMON_CFG_MODE_LEG_52_POS      19
#define SMU_COMMON_CFG_INPUT_DECIMATION_MASK    ((uint32_t)0x00030000)
#define SMU_COMMON_CFG_INPUT_DECIMATION_LSB    16
#define SMU_COMMON_CFG_INPUT_DECIMATION_WIDTH    ((uint32_t)0x00000002)
#define SMU_COMMON_CFG_OUTPUT_SHIFT_MASK    ((uint32_t)0x0000C000)
#define SMU_COMMON_CFG_OUTPUT_SHIFT_LSB     14
#define SMU_COMMON_CFG_OUTPUT_SHIFT_WIDTH    ((uint32_t)0x00000002)
#define SMU_COMMON_CFG_INPUT_SHIFT_MASK     ((uint32_t)0x00003000)
#define SMU_COMMON_CFG_INPUT_SHIFT_LSB      12
#define SMU_COMMON_CFG_INPUT_SHIFT_WIDTH    ((uint32_t)0x00000002)
#define SMU_COMMON_CFG_FRAME_BW_MASK        ((uint32_t)0x00000C00)
#define SMU_COMMON_CFG_FRAME_BW_LSB         10
#define SMU_COMMON_CFG_FRAME_BW_WIDTH       ((uint32_t)0x00000002)
#define SMU_COMMON_CFG_MODE_HE_BIT          ((uint32_t)0x00000200)
#define SMU_COMMON_CFG_MODE_HE_POS          9
#define SMU_COMMON_CFG_CONJUGATE_BIT        ((uint32_t)0x00000100)
#define SMU_COMMON_CFG_CONJUGATE_POS        8
#define SMU_COMMON_CFG_REMOVE_PILOT_EN_BIT    ((uint32_t)0x00000040)
#define SMU_COMMON_CFG_REMOVE_PILOT_EN_POS    6
#define SMU_COMMON_CFG_POST_ROT_EN_BIT      ((uint32_t)0x00000020)
#define SMU_COMMON_CFG_POST_ROT_EN_POS      5
#define SMU_COMMON_CFG_PRE_ROT_EN_BIT       ((uint32_t)0x00000010)
#define SMU_COMMON_CFG_PRE_ROT_EN_POS       4
#define SMU_COMMON_CFG_NB_ANT_MASK          ((uint32_t)0x00000007)
#define SMU_COMMON_CFG_NB_ANT_LSB           0
#define SMU_COMMON_CFG_NB_ANT_WIDTH         ((uint32_t)0x00000003)

#define SMU_COMMON_CFG_NB_RU_RST            0x0
#define SMU_COMMON_CFG_DYNAMIC_BYPASS_EN_RST    0x0
#define SMU_COMMON_CFG_MODE_LEG_52_RST      0x0
#define SMU_COMMON_CFG_INPUT_DECIMATION_RST    0x0
#define SMU_COMMON_CFG_OUTPUT_SHIFT_RST     0x0
#define SMU_COMMON_CFG_INPUT_SHIFT_RST      0x0
#define SMU_COMMON_CFG_FRAME_BW_RST         0x0
#define SMU_COMMON_CFG_MODE_HE_RST          0x0
#define SMU_COMMON_CFG_CONJUGATE_RST        0x0
#define SMU_COMMON_CFG_REMOVE_PILOT_EN_RST    0x0
#define SMU_COMMON_CFG_POST_ROT_EN_RST      0x0
#define SMU_COMMON_CFG_PRE_ROT_EN_RST       0x0
#define SMU_COMMON_CFG_NB_ANT_RST           0x0

__INLINE void smu_common_cfg_pack(uint8_t nb_ru, uint8_t dynamic_bypass_en, uint8_t mode_leg_52, uint8_t input_decimation, uint8_t output_shift, uint8_t input_shift, uint8_t frame_bw, uint8_t mode_he, uint8_t conjugate, uint8_t remove_pilot_en, uint8_t post_rot_en, uint8_t pre_rot_en, uint8_t nb_ant)
{
	ASSERT_ERR((((uint32_t)nb_ru << 24) & ~((uint32_t)0x0F000000)) == 0);
	ASSERT_ERR((((uint32_t)dynamic_bypass_en << 20) & ~((uint32_t)0x00700000)) == 0);
	ASSERT_ERR((((uint32_t)mode_leg_52 << 19) & ~((uint32_t)0x00080000)) == 0);
	ASSERT_ERR((((uint32_t)input_decimation << 16) & ~((uint32_t)0x00030000)) == 0);
	ASSERT_ERR((((uint32_t)output_shift << 14) & ~((uint32_t)0x0000C000)) == 0);
	ASSERT_ERR((((uint32_t)input_shift << 12) & ~((uint32_t)0x00003000)) == 0);
	ASSERT_ERR((((uint32_t)frame_bw << 10) & ~((uint32_t)0x00000C00)) == 0);
	ASSERT_ERR((((uint32_t)mode_he << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)conjugate << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)remove_pilot_en << 6) & ~((uint32_t)0x00000040)) == 0);
	ASSERT_ERR((((uint32_t)post_rot_en << 5) & ~((uint32_t)0x00000020)) == 0);
	ASSERT_ERR((((uint32_t)pre_rot_en << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)nb_ant << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(SMU_COMMON_CFG_ADDR,  ((uint32_t)nb_ru << 24) |((uint32_t)dynamic_bypass_en << 20) |((uint32_t)mode_leg_52 << 19) |((uint32_t)input_decimation << 16) |((uint32_t)output_shift << 14) |((uint32_t)input_shift << 12) |((uint32_t)frame_bw << 10) |((uint32_t)mode_he << 9) |((uint32_t)conjugate << 8) |((uint32_t)remove_pilot_en << 6) |((uint32_t)post_rot_en << 5) |((uint32_t)pre_rot_en << 4) |((uint32_t)nb_ant << 0));
}

__INLINE void smu_common_cfg_unpack(uint8_t* nb_ru, uint8_t* dynamic_bypass_en, uint8_t* mode_leg_52, uint8_t* input_decimation, uint8_t* output_shift, uint8_t* input_shift, uint8_t* frame_bw, uint8_t* mode_he, uint8_t* conjugate, uint8_t* remove_pilot_en, uint8_t* post_rot_en, uint8_t* pre_rot_en, uint8_t* nb_ant)
{
	uint32_t localVal = REG_PL_RD(SMU_COMMON_CFG_ADDR);

	*nb_ru = (localVal & ((uint32_t)0x0F000000)) >>  24;
	*dynamic_bypass_en = (localVal & ((uint32_t)0x00700000)) >>  20;
	*mode_leg_52 = (localVal & ((uint32_t)0x00080000)) >>  19;
	*input_decimation = (localVal & ((uint32_t)0x00030000)) >>  16;
	*output_shift = (localVal & ((uint32_t)0x0000C000)) >>  14;
	*input_shift = (localVal & ((uint32_t)0x00003000)) >>  12;
	*frame_bw = (localVal & ((uint32_t)0x00000C00)) >>  10;
	*mode_he = (localVal & ((uint32_t)0x00000200)) >>  9;
	*conjugate = (localVal & ((uint32_t)0x00000100)) >>  8;
	*remove_pilot_en = (localVal & ((uint32_t)0x00000040)) >>  6;
	*post_rot_en = (localVal & ((uint32_t)0x00000020)) >>  5;
	*pre_rot_en = (localVal & ((uint32_t)0x00000010)) >>  4;
	*nb_ant = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t smu_common_cfg_nb_ru_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_COMMON_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0F000000)) >> 24);
}
__INLINE void smu_common_cfg_nb_ru_setf(uint8_t nbru)
{
	ASSERT_ERR((((uint32_t)nbru << 24) & ~((uint32_t)0x0F000000)) == 0);
	REG_PL_WR(SMU_COMMON_CFG_ADDR, (REG_PL_RD(SMU_COMMON_CFG_ADDR) & ~((uint32_t)0x0F000000)) | ((uint32_t)nbru <<24));
}
__INLINE uint8_t smu_common_cfg_dynamic_bypass_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_COMMON_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00700000)) >> 20);
}
__INLINE void smu_common_cfg_dynamic_bypass_en_setf(uint8_t dynamicbypassen)
{
	ASSERT_ERR((((uint32_t)dynamicbypassen << 20) & ~((uint32_t)0x00700000)) == 0);
	REG_PL_WR(SMU_COMMON_CFG_ADDR, (REG_PL_RD(SMU_COMMON_CFG_ADDR) & ~((uint32_t)0x00700000)) | ((uint32_t)dynamicbypassen <<20));
}
__INLINE uint8_t smu_common_cfg_mode_leg_52_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_COMMON_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00080000)) >> 19);
}
__INLINE void smu_common_cfg_mode_leg_52_setf(uint8_t modeleg52)
{
	ASSERT_ERR((((uint32_t)modeleg52 << 19) & ~((uint32_t)0x00080000)) == 0);
	REG_PL_WR(SMU_COMMON_CFG_ADDR, (REG_PL_RD(SMU_COMMON_CFG_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)modeleg52 <<19));
}
__INLINE uint8_t smu_common_cfg_input_decimation_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_COMMON_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00030000)) >> 16);
}
__INLINE void smu_common_cfg_input_decimation_setf(uint8_t inputdecimation)
{
	ASSERT_ERR((((uint32_t)inputdecimation << 16) & ~((uint32_t)0x00030000)) == 0);
	REG_PL_WR(SMU_COMMON_CFG_ADDR, (REG_PL_RD(SMU_COMMON_CFG_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)inputdecimation <<16));
}
__INLINE uint8_t smu_common_cfg_output_shift_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_COMMON_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000C000)) >> 14);
}
__INLINE void smu_common_cfg_output_shift_setf(uint8_t outputshift)
{
	ASSERT_ERR((((uint32_t)outputshift << 14) & ~((uint32_t)0x0000C000)) == 0);
	REG_PL_WR(SMU_COMMON_CFG_ADDR, (REG_PL_RD(SMU_COMMON_CFG_ADDR) & ~((uint32_t)0x0000C000)) | ((uint32_t)outputshift <<14));
}
__INLINE uint8_t smu_common_cfg_input_shift_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_COMMON_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00003000)) >> 12);
}
__INLINE void smu_common_cfg_input_shift_setf(uint8_t inputshift)
{
	ASSERT_ERR((((uint32_t)inputshift << 12) & ~((uint32_t)0x00003000)) == 0);
	REG_PL_WR(SMU_COMMON_CFG_ADDR, (REG_PL_RD(SMU_COMMON_CFG_ADDR) & ~((uint32_t)0x00003000)) | ((uint32_t)inputshift <<12));
}
__INLINE uint8_t smu_common_cfg_frame_bw_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_COMMON_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000C00)) >> 10);
}
__INLINE void smu_common_cfg_frame_bw_setf(uint8_t framebw)
{
	ASSERT_ERR((((uint32_t)framebw << 10) & ~((uint32_t)0x00000C00)) == 0);
	REG_PL_WR(SMU_COMMON_CFG_ADDR, (REG_PL_RD(SMU_COMMON_CFG_ADDR) & ~((uint32_t)0x00000C00)) | ((uint32_t)framebw <<10));
}
__INLINE uint8_t smu_common_cfg_mode_he_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_COMMON_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void smu_common_cfg_mode_he_setf(uint8_t modehe)
{
	ASSERT_ERR((((uint32_t)modehe << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(SMU_COMMON_CFG_ADDR, (REG_PL_RD(SMU_COMMON_CFG_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)modehe <<9));
}
__INLINE uint8_t smu_common_cfg_conjugate_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_COMMON_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void smu_common_cfg_conjugate_setf(uint8_t conjugate)
{
	ASSERT_ERR((((uint32_t)conjugate << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(SMU_COMMON_CFG_ADDR, (REG_PL_RD(SMU_COMMON_CFG_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)conjugate <<8));
}
__INLINE uint8_t smu_common_cfg_remove_pilot_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_COMMON_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE void smu_common_cfg_remove_pilot_en_setf(uint8_t removepiloten)
{
	ASSERT_ERR((((uint32_t)removepiloten << 6) & ~((uint32_t)0x00000040)) == 0);
	REG_PL_WR(SMU_COMMON_CFG_ADDR, (REG_PL_RD(SMU_COMMON_CFG_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)removepiloten <<6));
}
__INLINE uint8_t smu_common_cfg_post_rot_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_COMMON_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE void smu_common_cfg_post_rot_en_setf(uint8_t postroten)
{
	ASSERT_ERR((((uint32_t)postroten << 5) & ~((uint32_t)0x00000020)) == 0);
	REG_PL_WR(SMU_COMMON_CFG_ADDR, (REG_PL_RD(SMU_COMMON_CFG_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)postroten <<5));
}
__INLINE uint8_t smu_common_cfg_pre_rot_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_COMMON_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void smu_common_cfg_pre_rot_en_setf(uint8_t preroten)
{
	ASSERT_ERR((((uint32_t)preroten << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(SMU_COMMON_CFG_ADDR, (REG_PL_RD(SMU_COMMON_CFG_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)preroten <<4));
}
__INLINE uint8_t smu_common_cfg_nb_ant_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_COMMON_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void smu_common_cfg_nb_ant_setf(uint8_t nbant)
{
	ASSERT_ERR((((uint32_t)nbant << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(SMU_COMMON_CFG_ADDR, (REG_PL_RD(SMU_COMMON_CFG_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)nbant <<0));
}

/**
 * @brief MESS_PTR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 MESS_PTR                  0x0
 * </pre>
 */
#define SMU_MESS_PTR_ADDR        (REG_SMU_BASE_ADDR+0x00000010)
#define SMU_MESS_PTR_OFFSET      0x00000010
#define SMU_MESS_PTR_INDEX       0x00000004
#define SMU_MESS_PTR_RESET       0x00000000

__INLINE uint32_t  smu_mess_ptr_get(void)
{
	return REG_PL_RD(SMU_MESS_PTR_ADDR);
}

__INLINE void smu_mess_ptr_set(uint32_t value)
{
	REG_PL_WR(SMU_MESS_PTR_ADDR, value);
}

// field definitions
#define SMU_MESS_PTR_MESS_PTR_MASK          ((uint32_t)0xFFFFFFFF)
#define SMU_MESS_PTR_MESS_PTR_LSB           0
#define SMU_MESS_PTR_MESS_PTR_WIDTH         ((uint32_t)0x00000020)

#define SMU_MESS_PTR_MESS_PTR_RST           0x0

__INLINE uint32_t smu_mess_ptr_mess_ptr_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_MESS_PTR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void smu_mess_ptr_mess_ptr_setf(uint32_t messptr)
{
	ASSERT_ERR((((uint32_t)messptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SMU_MESS_PTR_ADDR, (uint32_t)messptr << 0);
}

/**
 * @brief STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 RU_DONE                   0x0
 *    16    FILTER_READ_DONE          0              
 *    14:12 NSS_BEING_USED            0x1
 *    08    PTR_BEING_USED            0              
 *    00    PROCESSING                0              
 * </pre>
 */
#define SMU_STATUS_ADDR        (REG_SMU_BASE_ADDR+0x00000014)
#define SMU_STATUS_OFFSET      0x00000014
#define SMU_STATUS_INDEX       0x00000005
#define SMU_STATUS_RESET       0x00001000

__INLINE uint32_t  smu_status_get(void)
{
	return REG_PL_RD(SMU_STATUS_ADDR);
}

// field definitions
#define SMU_STATUS_RU_DONE_MASK             ((uint32_t)0xFF000000)
#define SMU_STATUS_RU_DONE_LSB              24
#define SMU_STATUS_RU_DONE_WIDTH            ((uint32_t)0x00000008)
#define SMU_STATUS_FILTER_READ_DONE_BIT     ((uint32_t)0x00010000)
#define SMU_STATUS_FILTER_READ_DONE_POS     16
#define SMU_STATUS_NSS_BEING_USED_MASK      ((uint32_t)0x00007000)
#define SMU_STATUS_NSS_BEING_USED_LSB       12
#define SMU_STATUS_NSS_BEING_USED_WIDTH     ((uint32_t)0x00000003)
#define SMU_STATUS_PTR_BEING_USED_BIT       ((uint32_t)0x00000100)
#define SMU_STATUS_PTR_BEING_USED_POS       8
#define SMU_STATUS_PROCESSING_BIT           ((uint32_t)0x00000001)
#define SMU_STATUS_PROCESSING_POS           0

#define SMU_STATUS_RU_DONE_RST              0x0
#define SMU_STATUS_FILTER_READ_DONE_RST     0x0
#define SMU_STATUS_NSS_BEING_USED_RST       0x1
#define SMU_STATUS_PTR_BEING_USED_RST       0x0
#define SMU_STATUS_PROCESSING_RST           0x0

__INLINE void smu_status_unpack(uint8_t* ru_done, uint8_t* filter_read_done, uint8_t* nss_being_used, uint8_t* ptr_being_used, uint8_t* processing)
{
	uint32_t localVal = REG_PL_RD(SMU_STATUS_ADDR);

	*ru_done = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*filter_read_done = (localVal & ((uint32_t)0x00010000)) >>  16;
	*nss_being_used = (localVal & ((uint32_t)0x00007000)) >>  12;
	*ptr_being_used = (localVal & ((uint32_t)0x00000100)) >>  8;
	*processing = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t smu_status_ru_done_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE uint8_t smu_status_filter_read_done_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE uint8_t smu_status_nss_being_used_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007000)) >> 12);
}
__INLINE uint8_t smu_status_ptr_being_used_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE uint8_t smu_status_processing_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief RU_INFO register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    29:20 NB_SC_TOT                 0x38
 *    19:10 LAST_SC_INDEX             0x0
 *    09:00 FIRST_SC_INDEX            0x0
 * </pre>
 */
#define SMU_RU_INFO_ADDR        (REG_SMU_BASE_ADDR+0x00000018)
#define SMU_RU_INFO_OFFSET      0x00000018
#define SMU_RU_INFO_INDEX       0x00000006
#define SMU_RU_INFO_RESET       0x03800000

__INLINE uint32_t  smu_ru_info_get(void)
{
	return REG_PL_RD(SMU_RU_INFO_ADDR);
}

// field definitions
#define SMU_RU_INFO_NB_SC_TOT_MASK          ((uint32_t)0x3FF00000)
#define SMU_RU_INFO_NB_SC_TOT_LSB           20
#define SMU_RU_INFO_NB_SC_TOT_WIDTH         ((uint32_t)0x0000000A)
#define SMU_RU_INFO_LAST_SC_INDEX_MASK      ((uint32_t)0x000FFC00)
#define SMU_RU_INFO_LAST_SC_INDEX_LSB       10
#define SMU_RU_INFO_LAST_SC_INDEX_WIDTH     ((uint32_t)0x0000000A)
#define SMU_RU_INFO_FIRST_SC_INDEX_MASK     ((uint32_t)0x000003FF)
#define SMU_RU_INFO_FIRST_SC_INDEX_LSB      0
#define SMU_RU_INFO_FIRST_SC_INDEX_WIDTH    ((uint32_t)0x0000000A)

#define SMU_RU_INFO_NB_SC_TOT_RST           0x38
#define SMU_RU_INFO_LAST_SC_INDEX_RST       0x0
#define SMU_RU_INFO_FIRST_SC_INDEX_RST      0x0

__INLINE void smu_ru_info_unpack(uint16_t* nb_sc_tot, uint16_t* last_sc_index, uint16_t* first_sc_index)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_INFO_ADDR);

	*nb_sc_tot = (localVal & ((uint32_t)0x3FF00000)) >>  20;
	*last_sc_index = (localVal & ((uint32_t)0x000FFC00)) >>  10;
	*first_sc_index = (localVal & ((uint32_t)0x000003FF)) >>  0;
}

__INLINE uint16_t smu_ru_info_nb_sc_tot_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_INFO_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x3FF00000)) >> 20);
}
__INLINE uint16_t smu_ru_info_last_sc_index_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_INFO_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000FFC00)) >> 10);
}
__INLINE uint16_t smu_ru_info_first_sc_index_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_INFO_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000003FF)) >> 0);
}

/**
 * @brief DYN_BYP_LEFT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    25:16 DYN_BYP_LEFT_END          0x0
 *    09:00 DYN_BYP_LEFT_START        0x0
 * </pre>
 */
#define SMU_DYN_BYP_LEFT_ADDR        (REG_SMU_BASE_ADDR+0x00000020)
#define SMU_DYN_BYP_LEFT_OFFSET      0x00000020
#define SMU_DYN_BYP_LEFT_INDEX       0x00000008
#define SMU_DYN_BYP_LEFT_RESET       0x00000000

__INLINE uint32_t  smu_dyn_byp_left_get(void)
{
	return REG_PL_RD(SMU_DYN_BYP_LEFT_ADDR);
}

__INLINE void smu_dyn_byp_left_set(uint32_t value)
{
	REG_PL_WR(SMU_DYN_BYP_LEFT_ADDR, value);
}

// field definitions
#define SMU_DYN_BYP_LEFT_DYN_BYP_LEFT_END_MASK    ((uint32_t)0x03FF0000)
#define SMU_DYN_BYP_LEFT_DYN_BYP_LEFT_END_LSB    16
#define SMU_DYN_BYP_LEFT_DYN_BYP_LEFT_END_WIDTH    ((uint32_t)0x0000000A)
#define SMU_DYN_BYP_LEFT_DYN_BYP_LEFT_START_MASK    ((uint32_t)0x000003FF)
#define SMU_DYN_BYP_LEFT_DYN_BYP_LEFT_START_LSB    0
#define SMU_DYN_BYP_LEFT_DYN_BYP_LEFT_START_WIDTH    ((uint32_t)0x0000000A)

#define SMU_DYN_BYP_LEFT_DYN_BYP_LEFT_END_RST    0x0
#define SMU_DYN_BYP_LEFT_DYN_BYP_LEFT_START_RST    0x0

__INLINE void smu_dyn_byp_left_pack(uint16_t dyn_byp_left_end, uint16_t dyn_byp_left_start)
{
	ASSERT_ERR((((uint32_t)dyn_byp_left_end << 16) & ~((uint32_t)0x03FF0000)) == 0);
	ASSERT_ERR((((uint32_t)dyn_byp_left_start << 0) & ~((uint32_t)0x000003FF)) == 0);
	REG_PL_WR(SMU_DYN_BYP_LEFT_ADDR,  ((uint32_t)dyn_byp_left_end << 16) |((uint32_t)dyn_byp_left_start << 0));
}

__INLINE void smu_dyn_byp_left_unpack(uint16_t* dyn_byp_left_end, uint16_t* dyn_byp_left_start)
{
	uint32_t localVal = REG_PL_RD(SMU_DYN_BYP_LEFT_ADDR);

	*dyn_byp_left_end = (localVal & ((uint32_t)0x03FF0000)) >>  16;
	*dyn_byp_left_start = (localVal & ((uint32_t)0x000003FF)) >>  0;
}

__INLINE uint16_t smu_dyn_byp_left_dyn_byp_left_end_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_DYN_BYP_LEFT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x03FF0000)) >> 16);
}
__INLINE void smu_dyn_byp_left_dyn_byp_left_end_setf(uint16_t dynbypleftend)
{
	ASSERT_ERR((((uint32_t)dynbypleftend << 16) & ~((uint32_t)0x03FF0000)) == 0);
	REG_PL_WR(SMU_DYN_BYP_LEFT_ADDR, (REG_PL_RD(SMU_DYN_BYP_LEFT_ADDR) & ~((uint32_t)0x03FF0000)) | ((uint32_t)dynbypleftend <<16));
}
__INLINE uint16_t smu_dyn_byp_left_dyn_byp_left_start_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_DYN_BYP_LEFT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000003FF)) >> 0);
}
__INLINE void smu_dyn_byp_left_dyn_byp_left_start_setf(uint16_t dynbypleftstart)
{
	ASSERT_ERR((((uint32_t)dynbypleftstart << 0) & ~((uint32_t)0x000003FF)) == 0);
	REG_PL_WR(SMU_DYN_BYP_LEFT_ADDR, (REG_PL_RD(SMU_DYN_BYP_LEFT_ADDR) & ~((uint32_t)0x000003FF)) | ((uint32_t)dynbypleftstart <<0));
}

/**
 * @brief DYN_BYP_DC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    25:16 DYN_BYP_DC_END            0x0
 *    09:00 DYN_BYP_DC_START          0x0
 * </pre>
 */
#define SMU_DYN_BYP_DC_ADDR        (REG_SMU_BASE_ADDR+0x00000024)
#define SMU_DYN_BYP_DC_OFFSET      0x00000024
#define SMU_DYN_BYP_DC_INDEX       0x00000009
#define SMU_DYN_BYP_DC_RESET       0x00000000

__INLINE uint32_t  smu_dyn_byp_dc_get(void)
{
	return REG_PL_RD(SMU_DYN_BYP_DC_ADDR);
}

__INLINE void smu_dyn_byp_dc_set(uint32_t value)
{
	REG_PL_WR(SMU_DYN_BYP_DC_ADDR, value);
}

// field definitions
#define SMU_DYN_BYP_DC_DYN_BYP_DC_END_MASK    ((uint32_t)0x03FF0000)
#define SMU_DYN_BYP_DC_DYN_BYP_DC_END_LSB    16
#define SMU_DYN_BYP_DC_DYN_BYP_DC_END_WIDTH    ((uint32_t)0x0000000A)
#define SMU_DYN_BYP_DC_DYN_BYP_DC_START_MASK    ((uint32_t)0x000003FF)
#define SMU_DYN_BYP_DC_DYN_BYP_DC_START_LSB    0
#define SMU_DYN_BYP_DC_DYN_BYP_DC_START_WIDTH    ((uint32_t)0x0000000A)

#define SMU_DYN_BYP_DC_DYN_BYP_DC_END_RST    0x0
#define SMU_DYN_BYP_DC_DYN_BYP_DC_START_RST    0x0

__INLINE void smu_dyn_byp_dc_pack(uint16_t dyn_byp_dc_end, uint16_t dyn_byp_dc_start)
{
	ASSERT_ERR((((uint32_t)dyn_byp_dc_end << 16) & ~((uint32_t)0x03FF0000)) == 0);
	ASSERT_ERR((((uint32_t)dyn_byp_dc_start << 0) & ~((uint32_t)0x000003FF)) == 0);
	REG_PL_WR(SMU_DYN_BYP_DC_ADDR,  ((uint32_t)dyn_byp_dc_end << 16) |((uint32_t)dyn_byp_dc_start << 0));
}

__INLINE void smu_dyn_byp_dc_unpack(uint16_t* dyn_byp_dc_end, uint16_t* dyn_byp_dc_start)
{
	uint32_t localVal = REG_PL_RD(SMU_DYN_BYP_DC_ADDR);

	*dyn_byp_dc_end = (localVal & ((uint32_t)0x03FF0000)) >>  16;
	*dyn_byp_dc_start = (localVal & ((uint32_t)0x000003FF)) >>  0;
}

__INLINE uint16_t smu_dyn_byp_dc_dyn_byp_dc_end_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_DYN_BYP_DC_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x03FF0000)) >> 16);
}
__INLINE void smu_dyn_byp_dc_dyn_byp_dc_end_setf(uint16_t dynbypdcend)
{
	ASSERT_ERR((((uint32_t)dynbypdcend << 16) & ~((uint32_t)0x03FF0000)) == 0);
	REG_PL_WR(SMU_DYN_BYP_DC_ADDR, (REG_PL_RD(SMU_DYN_BYP_DC_ADDR) & ~((uint32_t)0x03FF0000)) | ((uint32_t)dynbypdcend <<16));
}
__INLINE uint16_t smu_dyn_byp_dc_dyn_byp_dc_start_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_DYN_BYP_DC_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000003FF)) >> 0);
}
__INLINE void smu_dyn_byp_dc_dyn_byp_dc_start_setf(uint16_t dynbypdcstart)
{
	ASSERT_ERR((((uint32_t)dynbypdcstart << 0) & ~((uint32_t)0x000003FF)) == 0);
	REG_PL_WR(SMU_DYN_BYP_DC_ADDR, (REG_PL_RD(SMU_DYN_BYP_DC_ADDR) & ~((uint32_t)0x000003FF)) | ((uint32_t)dynbypdcstart <<0));
}

/**
 * @brief DYN_BYP_RIGHT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    25:16 DYN_BYP_RIGHT_END         0x0
 *    09:00 DYN_BYP_RIGHT_START       0x0
 * </pre>
 */
#define SMU_DYN_BYP_RIGHT_ADDR        (REG_SMU_BASE_ADDR+0x00000028)
#define SMU_DYN_BYP_RIGHT_OFFSET      0x00000028
#define SMU_DYN_BYP_RIGHT_INDEX       0x0000000A
#define SMU_DYN_BYP_RIGHT_RESET       0x00000000

__INLINE uint32_t  smu_dyn_byp_right_get(void)
{
	return REG_PL_RD(SMU_DYN_BYP_RIGHT_ADDR);
}

__INLINE void smu_dyn_byp_right_set(uint32_t value)
{
	REG_PL_WR(SMU_DYN_BYP_RIGHT_ADDR, value);
}

// field definitions
#define SMU_DYN_BYP_RIGHT_DYN_BYP_RIGHT_END_MASK    ((uint32_t)0x03FF0000)
#define SMU_DYN_BYP_RIGHT_DYN_BYP_RIGHT_END_LSB    16
#define SMU_DYN_BYP_RIGHT_DYN_BYP_RIGHT_END_WIDTH    ((uint32_t)0x0000000A)
#define SMU_DYN_BYP_RIGHT_DYN_BYP_RIGHT_START_MASK    ((uint32_t)0x000003FF)
#define SMU_DYN_BYP_RIGHT_DYN_BYP_RIGHT_START_LSB    0
#define SMU_DYN_BYP_RIGHT_DYN_BYP_RIGHT_START_WIDTH    ((uint32_t)0x0000000A)

#define SMU_DYN_BYP_RIGHT_DYN_BYP_RIGHT_END_RST    0x0
#define SMU_DYN_BYP_RIGHT_DYN_BYP_RIGHT_START_RST    0x0

__INLINE void smu_dyn_byp_right_pack(uint16_t dyn_byp_right_end, uint16_t dyn_byp_right_start)
{
	ASSERT_ERR((((uint32_t)dyn_byp_right_end << 16) & ~((uint32_t)0x03FF0000)) == 0);
	ASSERT_ERR((((uint32_t)dyn_byp_right_start << 0) & ~((uint32_t)0x000003FF)) == 0);
	REG_PL_WR(SMU_DYN_BYP_RIGHT_ADDR,  ((uint32_t)dyn_byp_right_end << 16) |((uint32_t)dyn_byp_right_start << 0));
}

__INLINE void smu_dyn_byp_right_unpack(uint16_t* dyn_byp_right_end, uint16_t* dyn_byp_right_start)
{
	uint32_t localVal = REG_PL_RD(SMU_DYN_BYP_RIGHT_ADDR);

	*dyn_byp_right_end = (localVal & ((uint32_t)0x03FF0000)) >>  16;
	*dyn_byp_right_start = (localVal & ((uint32_t)0x000003FF)) >>  0;
}

__INLINE uint16_t smu_dyn_byp_right_dyn_byp_right_end_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_DYN_BYP_RIGHT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x03FF0000)) >> 16);
}
__INLINE void smu_dyn_byp_right_dyn_byp_right_end_setf(uint16_t dynbyprightend)
{
	ASSERT_ERR((((uint32_t)dynbyprightend << 16) & ~((uint32_t)0x03FF0000)) == 0);
	REG_PL_WR(SMU_DYN_BYP_RIGHT_ADDR, (REG_PL_RD(SMU_DYN_BYP_RIGHT_ADDR) & ~((uint32_t)0x03FF0000)) | ((uint32_t)dynbyprightend <<16));
}
__INLINE uint16_t smu_dyn_byp_right_dyn_byp_right_start_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_DYN_BYP_RIGHT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000003FF)) >> 0);
}
__INLINE void smu_dyn_byp_right_dyn_byp_right_start_setf(uint16_t dynbyprightstart)
{
	ASSERT_ERR((((uint32_t)dynbyprightstart << 0) & ~((uint32_t)0x000003FF)) == 0);
	REG_PL_WR(SMU_DYN_BYP_RIGHT_ADDR, (REG_PL_RD(SMU_DYN_BYP_RIGHT_ADDR) & ~((uint32_t)0x000003FF)) | ((uint32_t)dynbyprightstart <<0));
}

/**
 * @brief SEGMENT_CFG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SEGMENT_OFFSET            0x0
 *    01:00 SEGMENT_SIZE              0x0
 * </pre>
 */
#define SMU_SEGMENT_CFG_ADDR        (REG_SMU_BASE_ADDR+0x0000002C)
#define SMU_SEGMENT_CFG_OFFSET      0x0000002C
#define SMU_SEGMENT_CFG_INDEX       0x0000000B
#define SMU_SEGMENT_CFG_RESET       0x00000000

__INLINE uint32_t  smu_segment_cfg_get(void)
{
	return REG_PL_RD(SMU_SEGMENT_CFG_ADDR);
}

__INLINE void smu_segment_cfg_set(uint32_t value)
{
	REG_PL_WR(SMU_SEGMENT_CFG_ADDR, value);
}

// field definitions
#define SMU_SEGMENT_CFG_SEGMENT_OFFSET_MASK    ((uint32_t)0xFFFF0000)
#define SMU_SEGMENT_CFG_SEGMENT_OFFSET_LSB    16
#define SMU_SEGMENT_CFG_SEGMENT_OFFSET_WIDTH    ((uint32_t)0x00000010)
#define SMU_SEGMENT_CFG_SEGMENT_SIZE_MASK    ((uint32_t)0x00000003)
#define SMU_SEGMENT_CFG_SEGMENT_SIZE_LSB    0
#define SMU_SEGMENT_CFG_SEGMENT_SIZE_WIDTH    ((uint32_t)0x00000002)

#define SMU_SEGMENT_CFG_SEGMENT_OFFSET_RST    0x0
#define SMU_SEGMENT_CFG_SEGMENT_SIZE_RST    0x0

__INLINE void smu_segment_cfg_pack(uint16_t segment_offset, uint8_t segment_size)
{
	ASSERT_ERR((((uint32_t)segment_offset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)segment_size << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(SMU_SEGMENT_CFG_ADDR,  ((uint32_t)segment_offset << 16) |((uint32_t)segment_size << 0));
}

__INLINE void smu_segment_cfg_unpack(uint16_t* segment_offset, uint8_t* segment_size)
{
	uint32_t localVal = REG_PL_RD(SMU_SEGMENT_CFG_ADDR);

	*segment_offset = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*segment_size = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint16_t smu_segment_cfg_segment_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_SEGMENT_CFG_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void smu_segment_cfg_segment_offset_setf(uint16_t segmentoffset)
{
	ASSERT_ERR((((uint32_t)segmentoffset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SMU_SEGMENT_CFG_ADDR, (REG_PL_RD(SMU_SEGMENT_CFG_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)segmentoffset <<16));
}
__INLINE uint8_t smu_segment_cfg_segment_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_SEGMENT_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void smu_segment_cfg_segment_size_setf(uint8_t segmentsize)
{
	ASSERT_ERR((((uint32_t)segmentsize << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(SMU_SEGMENT_CFG_ADDR, (REG_PL_RD(SMU_SEGMENT_CFG_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)segmentsize <<0));
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
#define SMU_DEBUG_1_ADDR        (REG_SMU_BASE_ADDR+0x00000030)
#define SMU_DEBUG_1_OFFSET      0x00000030
#define SMU_DEBUG_1_INDEX       0x0000000C
#define SMU_DEBUG_1_RESET       0x00000000

__INLINE uint32_t  smu_debug_1_get(void)
{
	return REG_PL_RD(SMU_DEBUG_1_ADDR);
}

__INLINE void smu_debug_1_set(uint32_t value)
{
	REG_PL_WR(SMU_DEBUG_1_ADDR, value);
}

// field definitions
#define SMU_DEBUG_1_DEBUG_SEL_4_MASK        ((uint32_t)0x7F000000)
#define SMU_DEBUG_1_DEBUG_SEL_4_LSB         24
#define SMU_DEBUG_1_DEBUG_SEL_4_WIDTH       ((uint32_t)0x00000007)
#define SMU_DEBUG_1_DEBUG_SEL_3_MASK        ((uint32_t)0x007F0000)
#define SMU_DEBUG_1_DEBUG_SEL_3_LSB         16
#define SMU_DEBUG_1_DEBUG_SEL_3_WIDTH       ((uint32_t)0x00000007)
#define SMU_DEBUG_1_DEBUG_SEL_2_MASK        ((uint32_t)0x00007F00)
#define SMU_DEBUG_1_DEBUG_SEL_2_LSB         8
#define SMU_DEBUG_1_DEBUG_SEL_2_WIDTH       ((uint32_t)0x00000007)
#define SMU_DEBUG_1_DEBUG_SEL_1_MASK        ((uint32_t)0x0000007F)
#define SMU_DEBUG_1_DEBUG_SEL_1_LSB         0
#define SMU_DEBUG_1_DEBUG_SEL_1_WIDTH       ((uint32_t)0x00000007)

#define SMU_DEBUG_1_DEBUG_SEL_4_RST         0x0
#define SMU_DEBUG_1_DEBUG_SEL_3_RST         0x0
#define SMU_DEBUG_1_DEBUG_SEL_2_RST         0x0
#define SMU_DEBUG_1_DEBUG_SEL_1_RST         0x0

__INLINE void smu_debug_1_pack(uint8_t debug_sel_4, uint8_t debug_sel_3, uint8_t debug_sel_2, uint8_t debug_sel_1)
{
	ASSERT_ERR((((uint32_t)debug_sel_4 << 24) & ~((uint32_t)0x7F000000)) == 0);
	ASSERT_ERR((((uint32_t)debug_sel_3 << 16) & ~((uint32_t)0x007F0000)) == 0);
	ASSERT_ERR((((uint32_t)debug_sel_2 << 8) & ~((uint32_t)0x00007F00)) == 0);
	ASSERT_ERR((((uint32_t)debug_sel_1 << 0) & ~((uint32_t)0x0000007F)) == 0);
	REG_PL_WR(SMU_DEBUG_1_ADDR,  ((uint32_t)debug_sel_4 << 24) |((uint32_t)debug_sel_3 << 16) |((uint32_t)debug_sel_2 << 8) |((uint32_t)debug_sel_1 << 0));
}

__INLINE void smu_debug_1_unpack(uint8_t* debug_sel_4, uint8_t* debug_sel_3, uint8_t* debug_sel_2, uint8_t* debug_sel_1)
{
	uint32_t localVal = REG_PL_RD(SMU_DEBUG_1_ADDR);

	*debug_sel_4 = (localVal & ((uint32_t)0x7F000000)) >>  24;
	*debug_sel_3 = (localVal & ((uint32_t)0x007F0000)) >>  16;
	*debug_sel_2 = (localVal & ((uint32_t)0x00007F00)) >>  8;
	*debug_sel_1 = (localVal & ((uint32_t)0x0000007F)) >>  0;
}

__INLINE uint8_t smu_debug_1_debug_sel_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_DEBUG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x7F000000)) >> 24);
}
__INLINE void smu_debug_1_debug_sel_4_setf(uint8_t debugsel4)
{
	ASSERT_ERR((((uint32_t)debugsel4 << 24) & ~((uint32_t)0x7F000000)) == 0);
	REG_PL_WR(SMU_DEBUG_1_ADDR, (REG_PL_RD(SMU_DEBUG_1_ADDR) & ~((uint32_t)0x7F000000)) | ((uint32_t)debugsel4 <<24));
}
__INLINE uint8_t smu_debug_1_debug_sel_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_DEBUG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x007F0000)) >> 16);
}
__INLINE void smu_debug_1_debug_sel_3_setf(uint8_t debugsel3)
{
	ASSERT_ERR((((uint32_t)debugsel3 << 16) & ~((uint32_t)0x007F0000)) == 0);
	REG_PL_WR(SMU_DEBUG_1_ADDR, (REG_PL_RD(SMU_DEBUG_1_ADDR) & ~((uint32_t)0x007F0000)) | ((uint32_t)debugsel3 <<16));
}
__INLINE uint8_t smu_debug_1_debug_sel_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_DEBUG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007F00)) >> 8);
}
__INLINE void smu_debug_1_debug_sel_2_setf(uint8_t debugsel2)
{
	ASSERT_ERR((((uint32_t)debugsel2 << 8) & ~((uint32_t)0x00007F00)) == 0);
	REG_PL_WR(SMU_DEBUG_1_ADDR, (REG_PL_RD(SMU_DEBUG_1_ADDR) & ~((uint32_t)0x00007F00)) | ((uint32_t)debugsel2 <<8));
}
__INLINE uint8_t smu_debug_1_debug_sel_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_DEBUG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000007F)) >> 0);
}
__INLINE void smu_debug_1_debug_sel_1_setf(uint8_t debugsel1)
{
	ASSERT_ERR((((uint32_t)debugsel1 << 0) & ~((uint32_t)0x0000007F)) == 0);
	REG_PL_WR(SMU_DEBUG_1_ADDR, (REG_PL_RD(SMU_DEBUG_1_ADDR) & ~((uint32_t)0x0000007F)) | ((uint32_t)debugsel1 <<0));
}

/**
 * @brief DEBUG_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    17    DISABLE_CLOCK_GATE        0              
 *    16    DEBUG_EN                  0              
 *    14:08 DEBUG_SEL_6               0x0
 *    06:00 DEBUG_SEL_5               0x0
 * </pre>
 */
#define SMU_DEBUG_2_ADDR        (REG_SMU_BASE_ADDR+0x00000034)
#define SMU_DEBUG_2_OFFSET      0x00000034
#define SMU_DEBUG_2_INDEX       0x0000000D
#define SMU_DEBUG_2_RESET       0x00000000

__INLINE uint32_t  smu_debug_2_get(void)
{
	return REG_PL_RD(SMU_DEBUG_2_ADDR);
}

__INLINE void smu_debug_2_set(uint32_t value)
{
	REG_PL_WR(SMU_DEBUG_2_ADDR, value);
}

// field definitions
#define SMU_DEBUG_2_DISABLE_CLOCK_GATE_BIT    ((uint32_t)0x00020000)
#define SMU_DEBUG_2_DISABLE_CLOCK_GATE_POS    17
#define SMU_DEBUG_2_DEBUG_EN_BIT            ((uint32_t)0x00010000)
#define SMU_DEBUG_2_DEBUG_EN_POS            16
#define SMU_DEBUG_2_DEBUG_SEL_6_MASK        ((uint32_t)0x00007F00)
#define SMU_DEBUG_2_DEBUG_SEL_6_LSB         8
#define SMU_DEBUG_2_DEBUG_SEL_6_WIDTH       ((uint32_t)0x00000007)
#define SMU_DEBUG_2_DEBUG_SEL_5_MASK        ((uint32_t)0x0000007F)
#define SMU_DEBUG_2_DEBUG_SEL_5_LSB         0
#define SMU_DEBUG_2_DEBUG_SEL_5_WIDTH       ((uint32_t)0x00000007)

#define SMU_DEBUG_2_DISABLE_CLOCK_GATE_RST    0x0
#define SMU_DEBUG_2_DEBUG_EN_RST            0x0
#define SMU_DEBUG_2_DEBUG_SEL_6_RST         0x0
#define SMU_DEBUG_2_DEBUG_SEL_5_RST         0x0

__INLINE void smu_debug_2_pack(uint8_t disable_clock_gate, uint8_t debug_en, uint8_t debug_sel_6, uint8_t debug_sel_5)
{
	ASSERT_ERR((((uint32_t)disable_clock_gate << 17) & ~((uint32_t)0x00020000)) == 0);
	ASSERT_ERR((((uint32_t)debug_en << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)debug_sel_6 << 8) & ~((uint32_t)0x00007F00)) == 0);
	ASSERT_ERR((((uint32_t)debug_sel_5 << 0) & ~((uint32_t)0x0000007F)) == 0);
	REG_PL_WR(SMU_DEBUG_2_ADDR,  ((uint32_t)disable_clock_gate << 17) |((uint32_t)debug_en << 16) |((uint32_t)debug_sel_6 << 8) |((uint32_t)debug_sel_5 << 0));
}

__INLINE void smu_debug_2_unpack(uint8_t* disable_clock_gate, uint8_t* debug_en, uint8_t* debug_sel_6, uint8_t* debug_sel_5)
{
	uint32_t localVal = REG_PL_RD(SMU_DEBUG_2_ADDR);

	*disable_clock_gate = (localVal & ((uint32_t)0x00020000)) >>  17;
	*debug_en = (localVal & ((uint32_t)0x00010000)) >>  16;
	*debug_sel_6 = (localVal & ((uint32_t)0x00007F00)) >>  8;
	*debug_sel_5 = (localVal & ((uint32_t)0x0000007F)) >>  0;
}

__INLINE uint8_t smu_debug_2_disable_clock_gate_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_DEBUG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00020000)) >> 17);
}
__INLINE void smu_debug_2_disable_clock_gate_setf(uint8_t disableclockgate)
{
	ASSERT_ERR((((uint32_t)disableclockgate << 17) & ~((uint32_t)0x00020000)) == 0);
	REG_PL_WR(SMU_DEBUG_2_ADDR, (REG_PL_RD(SMU_DEBUG_2_ADDR) & ~((uint32_t)0x00020000)) | ((uint32_t)disableclockgate <<17));
}
__INLINE uint8_t smu_debug_2_debug_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_DEBUG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void smu_debug_2_debug_en_setf(uint8_t debugen)
{
	ASSERT_ERR((((uint32_t)debugen << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(SMU_DEBUG_2_ADDR, (REG_PL_RD(SMU_DEBUG_2_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)debugen <<16));
}
__INLINE uint8_t smu_debug_2_debug_sel_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_DEBUG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007F00)) >> 8);
}
__INLINE void smu_debug_2_debug_sel_6_setf(uint8_t debugsel6)
{
	ASSERT_ERR((((uint32_t)debugsel6 << 8) & ~((uint32_t)0x00007F00)) == 0);
	REG_PL_WR(SMU_DEBUG_2_ADDR, (REG_PL_RD(SMU_DEBUG_2_ADDR) & ~((uint32_t)0x00007F00)) | ((uint32_t)debugsel6 <<8));
}
__INLINE uint8_t smu_debug_2_debug_sel_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_DEBUG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000007F)) >> 0);
}
__INLINE void smu_debug_2_debug_sel_5_setf(uint8_t debugsel5)
{
	ASSERT_ERR((((uint32_t)debugsel5 << 0) & ~((uint32_t)0x0000007F)) == 0);
	REG_PL_WR(SMU_DEBUG_2_ADDR, (REG_PL_RD(SMU_DEBUG_2_ADDR) & ~((uint32_t)0x0000007F)) | ((uint32_t)debugsel5 <<0));
}

/**
 * @brief INT_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    FILTER_LOAD_DONE_EN       0              
 *    08    SMOOTH_DONE_EN            0              
 *    00    SMOOTH_DONE_BUF_A_EN      0              
 * </pre>
 */
#define SMU_INT_EN_ADDR        (REG_SMU_BASE_ADDR+0x00000040)
#define SMU_INT_EN_OFFSET      0x00000040
#define SMU_INT_EN_INDEX       0x00000010
#define SMU_INT_EN_RESET       0x00000000

__INLINE uint32_t  smu_int_en_get(void)
{
	return REG_PL_RD(SMU_INT_EN_ADDR);
}

__INLINE void smu_int_en_set(uint32_t value)
{
	REG_PL_WR(SMU_INT_EN_ADDR, value);
}

// field definitions
#define SMU_INT_EN_FILTER_LOAD_DONE_EN_BIT    ((uint32_t)0x00010000)
#define SMU_INT_EN_FILTER_LOAD_DONE_EN_POS    16
#define SMU_INT_EN_SMOOTH_DONE_EN_BIT       ((uint32_t)0x00000100)
#define SMU_INT_EN_SMOOTH_DONE_EN_POS       8
#define SMU_INT_EN_SMOOTH_DONE_BUF_A_EN_BIT    ((uint32_t)0x00000001)
#define SMU_INT_EN_SMOOTH_DONE_BUF_A_EN_POS    0

#define SMU_INT_EN_FILTER_LOAD_DONE_EN_RST    0x0
#define SMU_INT_EN_SMOOTH_DONE_EN_RST       0x0
#define SMU_INT_EN_SMOOTH_DONE_BUF_A_EN_RST    0x0

__INLINE void smu_int_en_pack(uint8_t filter_load_done_en, uint8_t smooth_done_en, uint8_t smooth_done_buf_a_en)
{
	ASSERT_ERR((((uint32_t)filter_load_done_en << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)smooth_done_en << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)smooth_done_buf_a_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(SMU_INT_EN_ADDR,  ((uint32_t)filter_load_done_en << 16) |((uint32_t)smooth_done_en << 8) |((uint32_t)smooth_done_buf_a_en << 0));
}

__INLINE void smu_int_en_unpack(uint8_t* filter_load_done_en, uint8_t* smooth_done_en, uint8_t* smooth_done_buf_a_en)
{
	uint32_t localVal = REG_PL_RD(SMU_INT_EN_ADDR);

	*filter_load_done_en = (localVal & ((uint32_t)0x00010000)) >>  16;
	*smooth_done_en = (localVal & ((uint32_t)0x00000100)) >>  8;
	*smooth_done_buf_a_en = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t smu_int_en_filter_load_done_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void smu_int_en_filter_load_done_en_setf(uint8_t filterloaddoneen)
{
	ASSERT_ERR((((uint32_t)filterloaddoneen << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(SMU_INT_EN_ADDR, (REG_PL_RD(SMU_INT_EN_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)filterloaddoneen <<16));
}
__INLINE uint8_t smu_int_en_smooth_done_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void smu_int_en_smooth_done_en_setf(uint8_t smoothdoneen)
{
	ASSERT_ERR((((uint32_t)smoothdoneen << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(SMU_INT_EN_ADDR, (REG_PL_RD(SMU_INT_EN_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)smoothdoneen <<8));
}
__INLINE uint8_t smu_int_en_smooth_done_buf_a_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void smu_int_en_smooth_done_buf_a_en_setf(uint8_t smoothdonebufaen)
{
	ASSERT_ERR((((uint32_t)smoothdonebufaen << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(SMU_INT_EN_ADDR, (REG_PL_RD(SMU_INT_EN_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)smoothdonebufaen <<0));
}

/**
 * @brief INT_STAT_RAW register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    FILTER_LOAD_DONE_RAW      0              
 *    08    SMOOTH_DONE_RAW           0              
 *    00    SMOOTH_DONE_BUF_A_RAW     0              
 * </pre>
 */
#define SMU_INT_STAT_RAW_ADDR        (REG_SMU_BASE_ADDR+0x00000044)
#define SMU_INT_STAT_RAW_OFFSET      0x00000044
#define SMU_INT_STAT_RAW_INDEX       0x00000011
#define SMU_INT_STAT_RAW_RESET       0x00000000

__INLINE uint32_t  smu_int_stat_raw_get(void)
{
	return REG_PL_RD(SMU_INT_STAT_RAW_ADDR);
}

// field definitions
#define SMU_INT_STAT_RAW_FILTER_LOAD_DONE_RAW_BIT    ((uint32_t)0x00010000)
#define SMU_INT_STAT_RAW_FILTER_LOAD_DONE_RAW_POS    16
#define SMU_INT_STAT_RAW_SMOOTH_DONE_RAW_BIT    ((uint32_t)0x00000100)
#define SMU_INT_STAT_RAW_SMOOTH_DONE_RAW_POS    8
#define SMU_INT_STAT_RAW_SMOOTH_DONE_BUF_A_RAW_BIT    ((uint32_t)0x00000001)
#define SMU_INT_STAT_RAW_SMOOTH_DONE_BUF_A_RAW_POS    0

#define SMU_INT_STAT_RAW_FILTER_LOAD_DONE_RAW_RST    0x0
#define SMU_INT_STAT_RAW_SMOOTH_DONE_RAW_RST    0x0
#define SMU_INT_STAT_RAW_SMOOTH_DONE_BUF_A_RAW_RST    0x0

__INLINE void smu_int_stat_raw_unpack(uint8_t* filter_load_done_raw, uint8_t* smooth_done_raw, uint8_t* smooth_done_buf_a_raw)
{
	uint32_t localVal = REG_PL_RD(SMU_INT_STAT_RAW_ADDR);

	*filter_load_done_raw = (localVal & ((uint32_t)0x00010000)) >>  16;
	*smooth_done_raw = (localVal & ((uint32_t)0x00000100)) >>  8;
	*smooth_done_buf_a_raw = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t smu_int_stat_raw_filter_load_done_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE uint8_t smu_int_stat_raw_smooth_done_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE uint8_t smu_int_stat_raw_smooth_done_buf_a_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief INT_STAT_MASKED register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    FILTER_LOAD_DONE_MASKED   0              
 *    08    SMOOTH_DONE_MASKED        0              
 *    00    SMOOTH_DONE_BUF_A_MASKED  0              
 * </pre>
 */
#define SMU_INT_STAT_MASKED_ADDR        (REG_SMU_BASE_ADDR+0x00000048)
#define SMU_INT_STAT_MASKED_OFFSET      0x00000048
#define SMU_INT_STAT_MASKED_INDEX       0x00000012
#define SMU_INT_STAT_MASKED_RESET       0x00000000

__INLINE uint32_t  smu_int_stat_masked_get(void)
{
	return REG_PL_RD(SMU_INT_STAT_MASKED_ADDR);
}

// field definitions
#define SMU_INT_STAT_MASKED_FILTER_LOAD_DONE_MASKED_BIT    ((uint32_t)0x00010000)
#define SMU_INT_STAT_MASKED_FILTER_LOAD_DONE_MASKED_POS    16
#define SMU_INT_STAT_MASKED_SMOOTH_DONE_MASKED_BIT    ((uint32_t)0x00000100)
#define SMU_INT_STAT_MASKED_SMOOTH_DONE_MASKED_POS    8
#define SMU_INT_STAT_MASKED_SMOOTH_DONE_BUF_A_MASKED_BIT    ((uint32_t)0x00000001)
#define SMU_INT_STAT_MASKED_SMOOTH_DONE_BUF_A_MASKED_POS    0

#define SMU_INT_STAT_MASKED_FILTER_LOAD_DONE_MASKED_RST    0x0
#define SMU_INT_STAT_MASKED_SMOOTH_DONE_MASKED_RST    0x0
#define SMU_INT_STAT_MASKED_SMOOTH_DONE_BUF_A_MASKED_RST    0x0

__INLINE void smu_int_stat_masked_unpack(uint8_t* filter_load_done_masked, uint8_t* smooth_done_masked, uint8_t* smooth_done_buf_a_masked)
{
	uint32_t localVal = REG_PL_RD(SMU_INT_STAT_MASKED_ADDR);

	*filter_load_done_masked = (localVal & ((uint32_t)0x00010000)) >>  16;
	*smooth_done_masked = (localVal & ((uint32_t)0x00000100)) >>  8;
	*smooth_done_buf_a_masked = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t smu_int_stat_masked_filter_load_done_masked_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_INT_STAT_MASKED_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE uint8_t smu_int_stat_masked_smooth_done_masked_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_INT_STAT_MASKED_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE uint8_t smu_int_stat_masked_smooth_done_buf_a_masked_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_INT_STAT_MASKED_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief INT_ACK register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    FILTER_LOAD_DONE_ACK      0              
 *    08    SMOOTH_DONE_ACK           0              
 *    00    SMOOTH_DONE_BUF_A_ACK     0              
 * </pre>
 */
#define SMU_INT_ACK_ADDR        (REG_SMU_BASE_ADDR+0x0000004C)
#define SMU_INT_ACK_OFFSET      0x0000004C
#define SMU_INT_ACK_INDEX       0x00000013
#define SMU_INT_ACK_RESET       0x00000000

__INLINE void smu_int_ack_set(uint32_t value)
{
	REG_PL_WR(SMU_INT_ACK_ADDR, value);
}

__INLINE void smu_int_ack_clear(uint32_t value)
{
	REG_PL_WR(SMU_INT_ACK_ADDR, value);
}

// field definitions
#define SMU_INT_ACK_FILTER_LOAD_DONE_ACK_BIT    ((uint32_t)0x00010000)
#define SMU_INT_ACK_FILTER_LOAD_DONE_ACK_POS    16
#define SMU_INT_ACK_SMOOTH_DONE_ACK_BIT     ((uint32_t)0x00000100)
#define SMU_INT_ACK_SMOOTH_DONE_ACK_POS     8
#define SMU_INT_ACK_SMOOTH_DONE_BUF_A_ACK_BIT    ((uint32_t)0x00000001)
#define SMU_INT_ACK_SMOOTH_DONE_BUF_A_ACK_POS    0

#define SMU_INT_ACK_FILTER_LOAD_DONE_ACK_RST    0x0
#define SMU_INT_ACK_SMOOTH_DONE_ACK_RST     0x0
#define SMU_INT_ACK_SMOOTH_DONE_BUF_A_ACK_RST    0x0

__INLINE void smu_int_ack_pack(uint8_t filter_load_done_ack, uint8_t smooth_done_ack, uint8_t smooth_done_buf_a_ack)
{
	ASSERT_ERR((((uint32_t)filter_load_done_ack << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)smooth_done_ack << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)smooth_done_buf_a_ack << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(SMU_INT_ACK_ADDR,  ((uint32_t)filter_load_done_ack << 16) |((uint32_t)smooth_done_ack << 8) |((uint32_t)smooth_done_buf_a_ack << 0));
}

__INLINE void smu_int_ack_filter_load_done_ack_setf(uint8_t filterloaddoneack)
{
	ASSERT_ERR((((uint32_t)filterloaddoneack << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(SMU_INT_ACK_ADDR, (REG_PL_RD(SMU_INT_ACK_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)filterloaddoneack <<16));
}
__INLINE void smu_int_ack_filter_load_done_ack_clearf(uint8_t filterloaddoneack)
{
	ASSERT_ERR((((uint32_t)filterloaddoneack << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(SMU_INT_ACK_ADDR, (REG_PL_RD(SMU_INT_ACK_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)filterloaddoneack << 16));
}
__INLINE void smu_int_ack_smooth_done_ack_setf(uint8_t smoothdoneack)
{
	ASSERT_ERR((((uint32_t)smoothdoneack << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(SMU_INT_ACK_ADDR, (REG_PL_RD(SMU_INT_ACK_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)smoothdoneack <<8));
}
__INLINE void smu_int_ack_smooth_done_ack_clearf(uint8_t smoothdoneack)
{
	ASSERT_ERR((((uint32_t)smoothdoneack << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(SMU_INT_ACK_ADDR, (REG_PL_RD(SMU_INT_ACK_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)smoothdoneack << 8));
}
__INLINE void smu_int_ack_smooth_done_buf_a_ack_setf(uint8_t smoothdonebufaack)
{
	ASSERT_ERR((((uint32_t)smoothdonebufaack << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(SMU_INT_ACK_ADDR, (REG_PL_RD(SMU_INT_ACK_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)smoothdonebufaack <<0));
}
__INLINE void smu_int_ack_smooth_done_buf_a_ack_clearf(uint8_t smoothdonebufaack)
{
	ASSERT_ERR((((uint32_t)smoothdonebufaack << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(SMU_INT_ACK_ADDR, (REG_PL_RD(SMU_INT_ACK_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)smoothdonebufaack << 0));
}

/**
 * @brief INT_GEN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    FILTER_LOAD_DONE_GEN      0              
 *    08    SMOOTH_DONE_GEN           0              
 *    00    SMOOTH_DONE_BUF_A_GEN     0              
 * </pre>
 */
#define SMU_INT_GEN_ADDR        (REG_SMU_BASE_ADDR+0x00000050)
#define SMU_INT_GEN_OFFSET      0x00000050
#define SMU_INT_GEN_INDEX       0x00000014
#define SMU_INT_GEN_RESET       0x00000000

__INLINE void smu_int_gen_set(uint32_t value)
{
	REG_PL_WR(SMU_INT_GEN_ADDR, value);
}

// field definitions
#define SMU_INT_GEN_FILTER_LOAD_DONE_GEN_BIT    ((uint32_t)0x00010000)
#define SMU_INT_GEN_FILTER_LOAD_DONE_GEN_POS    16
#define SMU_INT_GEN_SMOOTH_DONE_GEN_BIT     ((uint32_t)0x00000100)
#define SMU_INT_GEN_SMOOTH_DONE_GEN_POS     8
#define SMU_INT_GEN_SMOOTH_DONE_BUF_A_GEN_BIT    ((uint32_t)0x00000001)
#define SMU_INT_GEN_SMOOTH_DONE_BUF_A_GEN_POS    0

#define SMU_INT_GEN_FILTER_LOAD_DONE_GEN_RST    0x0
#define SMU_INT_GEN_SMOOTH_DONE_GEN_RST     0x0
#define SMU_INT_GEN_SMOOTH_DONE_BUF_A_GEN_RST    0x0

__INLINE void smu_int_gen_pack(uint8_t filter_load_done_gen, uint8_t smooth_done_gen, uint8_t smooth_done_buf_a_gen)
{
	ASSERT_ERR((((uint32_t)filter_load_done_gen << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)smooth_done_gen << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)smooth_done_buf_a_gen << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(SMU_INT_GEN_ADDR,  ((uint32_t)filter_load_done_gen << 16) |((uint32_t)smooth_done_gen << 8) |((uint32_t)smooth_done_buf_a_gen << 0));
}

__INLINE void smu_int_gen_filter_load_done_gen_setf(uint8_t filterloaddonegen)
{
	ASSERT_ERR((((uint32_t)filterloaddonegen << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(SMU_INT_GEN_ADDR, (REG_PL_RD(SMU_INT_GEN_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)filterloaddonegen <<16));
}
__INLINE void smu_int_gen_smooth_done_gen_setf(uint8_t smoothdonegen)
{
	ASSERT_ERR((((uint32_t)smoothdonegen << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(SMU_INT_GEN_ADDR, (REG_PL_RD(SMU_INT_GEN_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)smoothdonegen <<8));
}
__INLINE void smu_int_gen_smooth_done_buf_a_gen_setf(uint8_t smoothdonebufagen)
{
	ASSERT_ERR((((uint32_t)smoothdonebufagen << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(SMU_INT_GEN_ADDR, (REG_PL_RD(SMU_INT_GEN_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)smoothdonebufagen <<0));
}

/**
 * @brief RU_0_CFG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26:24 STARTING_STS              0x0
 *    21:16 RU_INDEX                  0x0
 *    14:12 RU_TYPE                   0x0
 *    11    SMOOTH_FILTER_EN          0              
 *    10    PILOT_AV_EN               0              
 *    09:08 OUTPUT_DECIMATION         0x0
 *    07:06 NB_SC_SW_A                0x0
 *    05:04 GROUPING                  0x0
 *    03:00 NSS                       0x0
 * </pre>
 */
#define SMU_RU_0_CFG_ADDR        (REG_SMU_BASE_ADDR+0x00000100)
#define SMU_RU_0_CFG_OFFSET      0x00000100
#define SMU_RU_0_CFG_INDEX       0x00000040
#define SMU_RU_0_CFG_RESET       0x00000000

__INLINE uint32_t  smu_ru_0_cfg_get(void)
{
	return REG_PL_RD(SMU_RU_0_CFG_ADDR);
}

__INLINE void smu_ru_0_cfg_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_0_CFG_ADDR, value);
}

// field definitions
#define SMU_RU_0_CFG_STARTING_STS_MASK      ((uint32_t)0x07000000)
#define SMU_RU_0_CFG_STARTING_STS_LSB       24
#define SMU_RU_0_CFG_STARTING_STS_WIDTH     ((uint32_t)0x00000003)
#define SMU_RU_0_CFG_RU_INDEX_MASK          ((uint32_t)0x003F0000)
#define SMU_RU_0_CFG_RU_INDEX_LSB           16
#define SMU_RU_0_CFG_RU_INDEX_WIDTH         ((uint32_t)0x00000006)
#define SMU_RU_0_CFG_RU_TYPE_MASK           ((uint32_t)0x00007000)
#define SMU_RU_0_CFG_RU_TYPE_LSB            12
#define SMU_RU_0_CFG_RU_TYPE_WIDTH          ((uint32_t)0x00000003)
#define SMU_RU_0_CFG_SMOOTH_FILTER_EN_BIT    ((uint32_t)0x00000800)
#define SMU_RU_0_CFG_SMOOTH_FILTER_EN_POS    11
#define SMU_RU_0_CFG_PILOT_AV_EN_BIT        ((uint32_t)0x00000400)
#define SMU_RU_0_CFG_PILOT_AV_EN_POS        10
#define SMU_RU_0_CFG_OUTPUT_DECIMATION_MASK    ((uint32_t)0x00000300)
#define SMU_RU_0_CFG_OUTPUT_DECIMATION_LSB    8
#define SMU_RU_0_CFG_OUTPUT_DECIMATION_WIDTH    ((uint32_t)0x00000002)
#define SMU_RU_0_CFG_NB_SC_SW_A_MASK        ((uint32_t)0x000000C0)
#define SMU_RU_0_CFG_NB_SC_SW_A_LSB         6
#define SMU_RU_0_CFG_NB_SC_SW_A_WIDTH       ((uint32_t)0x00000002)
#define SMU_RU_0_CFG_GROUPING_MASK          ((uint32_t)0x00000030)
#define SMU_RU_0_CFG_GROUPING_LSB           4
#define SMU_RU_0_CFG_GROUPING_WIDTH         ((uint32_t)0x00000002)
#define SMU_RU_0_CFG_NSS_MASK               ((uint32_t)0x0000000F)
#define SMU_RU_0_CFG_NSS_LSB                0
#define SMU_RU_0_CFG_NSS_WIDTH              ((uint32_t)0x00000004)

#define SMU_RU_0_CFG_STARTING_STS_RST       0x0
#define SMU_RU_0_CFG_RU_INDEX_RST           0x0
#define SMU_RU_0_CFG_RU_TYPE_RST            0x0
#define SMU_RU_0_CFG_SMOOTH_FILTER_EN_RST    0x0
#define SMU_RU_0_CFG_PILOT_AV_EN_RST        0x0
#define SMU_RU_0_CFG_OUTPUT_DECIMATION_RST    0x0
#define SMU_RU_0_CFG_NB_SC_SW_A_RST         0x0
#define SMU_RU_0_CFG_GROUPING_RST           0x0
#define SMU_RU_0_CFG_NSS_RST                0x0

__INLINE void smu_ru_0_cfg_pack(uint8_t starting_sts, uint8_t ru_index, uint8_t ru_type, uint8_t smooth_filter_en, uint8_t pilot_av_en, uint8_t output_decimation, uint8_t nb_sc_sw_a, uint8_t grouping, uint8_t nss)
{
	ASSERT_ERR((((uint32_t)starting_sts << 24) & ~((uint32_t)0x07000000)) == 0);
	ASSERT_ERR((((uint32_t)ru_index << 16) & ~((uint32_t)0x003F0000)) == 0);
	ASSERT_ERR((((uint32_t)ru_type << 12) & ~((uint32_t)0x00007000)) == 0);
	ASSERT_ERR((((uint32_t)smooth_filter_en << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)pilot_av_en << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)output_decimation << 8) & ~((uint32_t)0x00000300)) == 0);
	ASSERT_ERR((((uint32_t)nb_sc_sw_a << 6) & ~((uint32_t)0x000000C0)) == 0);
	ASSERT_ERR((((uint32_t)grouping << 4) & ~((uint32_t)0x00000030)) == 0);
	ASSERT_ERR((((uint32_t)nss << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(SMU_RU_0_CFG_ADDR,  ((uint32_t)starting_sts << 24) |((uint32_t)ru_index << 16) |((uint32_t)ru_type << 12) |((uint32_t)smooth_filter_en << 11) |((uint32_t)pilot_av_en << 10) |((uint32_t)output_decimation << 8) |((uint32_t)nb_sc_sw_a << 6) |((uint32_t)grouping << 4) |((uint32_t)nss << 0));
}

__INLINE void smu_ru_0_cfg_unpack(uint8_t* starting_sts, uint8_t* ru_index, uint8_t* ru_type, uint8_t* smooth_filter_en, uint8_t* pilot_av_en, uint8_t* output_decimation, uint8_t* nb_sc_sw_a, uint8_t* grouping, uint8_t* nss)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_0_CFG_ADDR);

	*starting_sts = (localVal & ((uint32_t)0x07000000)) >>  24;
	*ru_index = (localVal & ((uint32_t)0x003F0000)) >>  16;
	*ru_type = (localVal & ((uint32_t)0x00007000)) >>  12;
	*smooth_filter_en = (localVal & ((uint32_t)0x00000800)) >>  11;
	*pilot_av_en = (localVal & ((uint32_t)0x00000400)) >>  10;
	*output_decimation = (localVal & ((uint32_t)0x00000300)) >>  8;
	*nb_sc_sw_a = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*grouping = (localVal & ((uint32_t)0x00000030)) >>  4;
	*nss = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t smu_ru_0_cfg_starting_sts_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_0_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE void smu_ru_0_cfg_starting_sts_setf(uint8_t startingsts)
{
	ASSERT_ERR((((uint32_t)startingsts << 24) & ~((uint32_t)0x07000000)) == 0);
	REG_PL_WR(SMU_RU_0_CFG_ADDR, (REG_PL_RD(SMU_RU_0_CFG_ADDR) & ~((uint32_t)0x07000000)) | ((uint32_t)startingsts <<24));
}
__INLINE uint8_t smu_ru_0_cfg_ru_index_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_0_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x003F0000)) >> 16);
}
__INLINE void smu_ru_0_cfg_ru_index_setf(uint8_t ruindex)
{
	ASSERT_ERR((((uint32_t)ruindex << 16) & ~((uint32_t)0x003F0000)) == 0);
	REG_PL_WR(SMU_RU_0_CFG_ADDR, (REG_PL_RD(SMU_RU_0_CFG_ADDR) & ~((uint32_t)0x003F0000)) | ((uint32_t)ruindex <<16));
}
__INLINE uint8_t smu_ru_0_cfg_ru_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_0_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007000)) >> 12);
}
__INLINE void smu_ru_0_cfg_ru_type_setf(uint8_t rutype)
{
	ASSERT_ERR((((uint32_t)rutype << 12) & ~((uint32_t)0x00007000)) == 0);
	REG_PL_WR(SMU_RU_0_CFG_ADDR, (REG_PL_RD(SMU_RU_0_CFG_ADDR) & ~((uint32_t)0x00007000)) | ((uint32_t)rutype <<12));
}
__INLINE uint8_t smu_ru_0_cfg_smooth_filter_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_0_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void smu_ru_0_cfg_smooth_filter_en_setf(uint8_t smoothfilteren)
{
	ASSERT_ERR((((uint32_t)smoothfilteren << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(SMU_RU_0_CFG_ADDR, (REG_PL_RD(SMU_RU_0_CFG_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)smoothfilteren <<11));
}
__INLINE uint8_t smu_ru_0_cfg_pilot_av_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_0_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void smu_ru_0_cfg_pilot_av_en_setf(uint8_t pilotaven)
{
	ASSERT_ERR((((uint32_t)pilotaven << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(SMU_RU_0_CFG_ADDR, (REG_PL_RD(SMU_RU_0_CFG_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)pilotaven <<10));
}
__INLINE uint8_t smu_ru_0_cfg_output_decimation_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_0_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000300)) >> 8);
}
__INLINE void smu_ru_0_cfg_output_decimation_setf(uint8_t outputdecimation)
{
	ASSERT_ERR((((uint32_t)outputdecimation << 8) & ~((uint32_t)0x00000300)) == 0);
	REG_PL_WR(SMU_RU_0_CFG_ADDR, (REG_PL_RD(SMU_RU_0_CFG_ADDR) & ~((uint32_t)0x00000300)) | ((uint32_t)outputdecimation <<8));
}
__INLINE uint8_t smu_ru_0_cfg_nb_sc_sw_a_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_0_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE void smu_ru_0_cfg_nb_sc_sw_a_setf(uint8_t nbscswa)
{
	ASSERT_ERR((((uint32_t)nbscswa << 6) & ~((uint32_t)0x000000C0)) == 0);
	REG_PL_WR(SMU_RU_0_CFG_ADDR, (REG_PL_RD(SMU_RU_0_CFG_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)nbscswa <<6));
}
__INLINE uint8_t smu_ru_0_cfg_grouping_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_0_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000030)) >> 4);
}
__INLINE void smu_ru_0_cfg_grouping_setf(uint8_t grouping)
{
	ASSERT_ERR((((uint32_t)grouping << 4) & ~((uint32_t)0x00000030)) == 0);
	REG_PL_WR(SMU_RU_0_CFG_ADDR, (REG_PL_RD(SMU_RU_0_CFG_ADDR) & ~((uint32_t)0x00000030)) | ((uint32_t)grouping <<4));
}
__INLINE uint8_t smu_ru_0_cfg_nss_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_0_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void smu_ru_0_cfg_nss_setf(uint8_t nss)
{
	ASSERT_ERR((((uint32_t)nss << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(SMU_RU_0_CFG_ADDR, (REG_PL_RD(SMU_RU_0_CFG_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)nss <<0));
}

/**
 * @brief RU_0_FILTER_PTR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 FILTER_PTR                0x0
 * </pre>
 */
#define SMU_RU_0_FILTER_PTR_ADDR        (REG_SMU_BASE_ADDR+0x00000104)
#define SMU_RU_0_FILTER_PTR_OFFSET      0x00000104
#define SMU_RU_0_FILTER_PTR_INDEX       0x00000041
#define SMU_RU_0_FILTER_PTR_RESET       0x00000000

__INLINE uint32_t  smu_ru_0_filter_ptr_get(void)
{
	return REG_PL_RD(SMU_RU_0_FILTER_PTR_ADDR);
}

__INLINE void smu_ru_0_filter_ptr_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_0_FILTER_PTR_ADDR, value);
}

// field definitions
#define SMU_RU_0_FILTER_PTR_FILTER_PTR_MASK    ((uint32_t)0xFFFFFFFF)
#define SMU_RU_0_FILTER_PTR_FILTER_PTR_LSB    0
#define SMU_RU_0_FILTER_PTR_FILTER_PTR_WIDTH    ((uint32_t)0x00000020)

#define SMU_RU_0_FILTER_PTR_FILTER_PTR_RST    0x0

__INLINE uint32_t smu_ru_0_filter_ptr_filter_ptr_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_0_FILTER_PTR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void smu_ru_0_filter_ptr_filter_ptr_setf(uint32_t filterptr)
{
	ASSERT_ERR((((uint32_t)filterptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SMU_RU_0_FILTER_PTR_ADDR, (uint32_t)filterptr << 0);
}

/**
 * @brief RU_0_DATA_RD_PTR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DATA_RD_PTR               0x0
 * </pre>
 */
#define SMU_RU_0_DATA_RD_PTR_ADDR        (REG_SMU_BASE_ADDR+0x00000108)
#define SMU_RU_0_DATA_RD_PTR_OFFSET      0x00000108
#define SMU_RU_0_DATA_RD_PTR_INDEX       0x00000042
#define SMU_RU_0_DATA_RD_PTR_RESET       0x00000000

__INLINE uint32_t  smu_ru_0_data_rd_ptr_get(void)
{
	return REG_PL_RD(SMU_RU_0_DATA_RD_PTR_ADDR);
}

__INLINE void smu_ru_0_data_rd_ptr_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_0_DATA_RD_PTR_ADDR, value);
}

// field definitions
#define SMU_RU_0_DATA_RD_PTR_DATA_RD_PTR_MASK    ((uint32_t)0xFFFFFFFF)
#define SMU_RU_0_DATA_RD_PTR_DATA_RD_PTR_LSB    0
#define SMU_RU_0_DATA_RD_PTR_DATA_RD_PTR_WIDTH    ((uint32_t)0x00000020)

#define SMU_RU_0_DATA_RD_PTR_DATA_RD_PTR_RST    0x0

__INLINE uint32_t smu_ru_0_data_rd_ptr_data_rd_ptr_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_0_DATA_RD_PTR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void smu_ru_0_data_rd_ptr_data_rd_ptr_setf(uint32_t datardptr)
{
	ASSERT_ERR((((uint32_t)datardptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SMU_RU_0_DATA_RD_PTR_ADDR, (uint32_t)datardptr << 0);
}

/**
 * @brief RU_0_RD_OFFSET register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SS_OFFSET                 0x0
 *    15:00 ANT_OFFSET                0x0
 * </pre>
 */
#define SMU_RU_0_RD_OFFSET_ADDR        (REG_SMU_BASE_ADDR+0x0000010C)
#define SMU_RU_0_RD_OFFSET_OFFSET      0x0000010C
#define SMU_RU_0_RD_OFFSET_INDEX       0x00000043
#define SMU_RU_0_RD_OFFSET_RESET       0x00000000

__INLINE uint32_t  smu_ru_0_rd_offset_get(void)
{
	return REG_PL_RD(SMU_RU_0_RD_OFFSET_ADDR);
}

__INLINE void smu_ru_0_rd_offset_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_0_RD_OFFSET_ADDR, value);
}

// field definitions
#define SMU_RU_0_RD_OFFSET_SS_OFFSET_MASK    ((uint32_t)0xFFFF0000)
#define SMU_RU_0_RD_OFFSET_SS_OFFSET_LSB    16
#define SMU_RU_0_RD_OFFSET_SS_OFFSET_WIDTH    ((uint32_t)0x00000010)
#define SMU_RU_0_RD_OFFSET_ANT_OFFSET_MASK    ((uint32_t)0x0000FFFF)
#define SMU_RU_0_RD_OFFSET_ANT_OFFSET_LSB    0
#define SMU_RU_0_RD_OFFSET_ANT_OFFSET_WIDTH    ((uint32_t)0x00000010)

#define SMU_RU_0_RD_OFFSET_SS_OFFSET_RST    0x0
#define SMU_RU_0_RD_OFFSET_ANT_OFFSET_RST    0x0

__INLINE void smu_ru_0_rd_offset_pack(uint16_t ss_offset, uint16_t ant_offset)
{
	ASSERT_ERR((((uint32_t)ss_offset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)ant_offset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_0_RD_OFFSET_ADDR,  ((uint32_t)ss_offset << 16) |((uint32_t)ant_offset << 0));
}

__INLINE void smu_ru_0_rd_offset_unpack(uint16_t* ss_offset, uint16_t* ant_offset)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_0_RD_OFFSET_ADDR);

	*ss_offset = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*ant_offset = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t smu_ru_0_rd_offset_ss_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_0_RD_OFFSET_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void smu_ru_0_rd_offset_ss_offset_setf(uint16_t ssoffset)
{
	ASSERT_ERR((((uint32_t)ssoffset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SMU_RU_0_RD_OFFSET_ADDR, (REG_PL_RD(SMU_RU_0_RD_OFFSET_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)ssoffset <<16));
}
__INLINE uint16_t smu_ru_0_rd_offset_ant_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_0_RD_OFFSET_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void smu_ru_0_rd_offset_ant_offset_setf(uint16_t antoffset)
{
	ASSERT_ERR((((uint32_t)antoffset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_0_RD_OFFSET_ADDR, (REG_PL_RD(SMU_RU_0_RD_OFFSET_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)antoffset <<0));
}

/**
 * @brief RU_0_DATA_WR_PTR_A register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DATA_WR_PTR_A             0x0
 * </pre>
 */
#define SMU_RU_0_DATA_WR_PTR_A_ADDR        (REG_SMU_BASE_ADDR+0x00000110)
#define SMU_RU_0_DATA_WR_PTR_A_OFFSET      0x00000110
#define SMU_RU_0_DATA_WR_PTR_A_INDEX       0x00000044
#define SMU_RU_0_DATA_WR_PTR_A_RESET       0x00000000

__INLINE uint32_t  smu_ru_0_data_wr_ptr_a_get(void)
{
	return REG_PL_RD(SMU_RU_0_DATA_WR_PTR_A_ADDR);
}

__INLINE void smu_ru_0_data_wr_ptr_a_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_0_DATA_WR_PTR_A_ADDR, value);
}

// field definitions
#define SMU_RU_0_DATA_WR_PTR_A_DATA_WR_PTR_A_MASK    ((uint32_t)0xFFFFFFFF)
#define SMU_RU_0_DATA_WR_PTR_A_DATA_WR_PTR_A_LSB    0
#define SMU_RU_0_DATA_WR_PTR_A_DATA_WR_PTR_A_WIDTH    ((uint32_t)0x00000020)

#define SMU_RU_0_DATA_WR_PTR_A_DATA_WR_PTR_A_RST    0x0

__INLINE uint32_t smu_ru_0_data_wr_ptr_a_data_wr_ptr_a_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_0_DATA_WR_PTR_A_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void smu_ru_0_data_wr_ptr_a_data_wr_ptr_a_setf(uint32_t datawrptra)
{
	ASSERT_ERR((((uint32_t)datawrptra << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SMU_RU_0_DATA_WR_PTR_A_ADDR, (uint32_t)datawrptra << 0);
}

/**
 * @brief RU_0_DATA_WR_PTR_B register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DATA_WR_PTR_B             0x0
 * </pre>
 */
#define SMU_RU_0_DATA_WR_PTR_B_ADDR        (REG_SMU_BASE_ADDR+0x00000114)
#define SMU_RU_0_DATA_WR_PTR_B_OFFSET      0x00000114
#define SMU_RU_0_DATA_WR_PTR_B_INDEX       0x00000045
#define SMU_RU_0_DATA_WR_PTR_B_RESET       0x00000000

__INLINE uint32_t  smu_ru_0_data_wr_ptr_b_get(void)
{
	return REG_PL_RD(SMU_RU_0_DATA_WR_PTR_B_ADDR);
}

__INLINE void smu_ru_0_data_wr_ptr_b_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_0_DATA_WR_PTR_B_ADDR, value);
}

// field definitions
#define SMU_RU_0_DATA_WR_PTR_B_DATA_WR_PTR_B_MASK    ((uint32_t)0xFFFFFFFF)
#define SMU_RU_0_DATA_WR_PTR_B_DATA_WR_PTR_B_LSB    0
#define SMU_RU_0_DATA_WR_PTR_B_DATA_WR_PTR_B_WIDTH    ((uint32_t)0x00000020)

#define SMU_RU_0_DATA_WR_PTR_B_DATA_WR_PTR_B_RST    0x0

__INLINE uint32_t smu_ru_0_data_wr_ptr_b_data_wr_ptr_b_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_0_DATA_WR_PTR_B_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void smu_ru_0_data_wr_ptr_b_data_wr_ptr_b_setf(uint32_t datawrptrb)
{
	ASSERT_ERR((((uint32_t)datawrptrb << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SMU_RU_0_DATA_WR_PTR_B_ADDR, (uint32_t)datawrptrb << 0);
}

/**
 * @brief RU_0_WR_OFFSET_A register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SS_OFFSET                 0x0
 *    15:00 ANT_OFFSET                0x0
 * </pre>
 */
#define SMU_RU_0_WR_OFFSET_A_ADDR        (REG_SMU_BASE_ADDR+0x00000118)
#define SMU_RU_0_WR_OFFSET_A_OFFSET      0x00000118
#define SMU_RU_0_WR_OFFSET_A_INDEX       0x00000046
#define SMU_RU_0_WR_OFFSET_A_RESET       0x00000000

__INLINE uint32_t  smu_ru_0_wr_offset_a_get(void)
{
	return REG_PL_RD(SMU_RU_0_WR_OFFSET_A_ADDR);
}

__INLINE void smu_ru_0_wr_offset_a_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_0_WR_OFFSET_A_ADDR, value);
}

// field definitions
#define SMU_RU_0_WR_OFFSET_A_SS_OFFSET_MASK    ((uint32_t)0xFFFF0000)
#define SMU_RU_0_WR_OFFSET_A_SS_OFFSET_LSB    16
#define SMU_RU_0_WR_OFFSET_A_SS_OFFSET_WIDTH    ((uint32_t)0x00000010)
#define SMU_RU_0_WR_OFFSET_A_ANT_OFFSET_MASK    ((uint32_t)0x0000FFFF)
#define SMU_RU_0_WR_OFFSET_A_ANT_OFFSET_LSB    0
#define SMU_RU_0_WR_OFFSET_A_ANT_OFFSET_WIDTH    ((uint32_t)0x00000010)

#define SMU_RU_0_WR_OFFSET_A_SS_OFFSET_RST    0x0
#define SMU_RU_0_WR_OFFSET_A_ANT_OFFSET_RST    0x0

__INLINE void smu_ru_0_wr_offset_a_pack(uint16_t ss_offset, uint16_t ant_offset)
{
	ASSERT_ERR((((uint32_t)ss_offset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)ant_offset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_0_WR_OFFSET_A_ADDR,  ((uint32_t)ss_offset << 16) |((uint32_t)ant_offset << 0));
}

__INLINE void smu_ru_0_wr_offset_a_unpack(uint16_t* ss_offset, uint16_t* ant_offset)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_0_WR_OFFSET_A_ADDR);

	*ss_offset = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*ant_offset = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t smu_ru_0_wr_offset_a_ss_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_0_WR_OFFSET_A_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void smu_ru_0_wr_offset_a_ss_offset_setf(uint16_t ssoffset)
{
	ASSERT_ERR((((uint32_t)ssoffset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SMU_RU_0_WR_OFFSET_A_ADDR, (REG_PL_RD(SMU_RU_0_WR_OFFSET_A_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)ssoffset <<16));
}
__INLINE uint16_t smu_ru_0_wr_offset_a_ant_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_0_WR_OFFSET_A_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void smu_ru_0_wr_offset_a_ant_offset_setf(uint16_t antoffset)
{
	ASSERT_ERR((((uint32_t)antoffset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_0_WR_OFFSET_A_ADDR, (REG_PL_RD(SMU_RU_0_WR_OFFSET_A_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)antoffset <<0));
}

/**
 * @brief RU_0_WR_OFFSET_B register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SS_OFFSET                 0x0
 *    15:00 ANT_OFFSET                0x0
 * </pre>
 */
#define SMU_RU_0_WR_OFFSET_B_ADDR        (REG_SMU_BASE_ADDR+0x0000011C)
#define SMU_RU_0_WR_OFFSET_B_OFFSET      0x0000011C
#define SMU_RU_0_WR_OFFSET_B_INDEX       0x00000047
#define SMU_RU_0_WR_OFFSET_B_RESET       0x00000000

__INLINE uint32_t  smu_ru_0_wr_offset_b_get(void)
{
	return REG_PL_RD(SMU_RU_0_WR_OFFSET_B_ADDR);
}

__INLINE void smu_ru_0_wr_offset_b_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_0_WR_OFFSET_B_ADDR, value);
}

// field definitions
#define SMU_RU_0_WR_OFFSET_B_SS_OFFSET_MASK    ((uint32_t)0xFFFF0000)
#define SMU_RU_0_WR_OFFSET_B_SS_OFFSET_LSB    16
#define SMU_RU_0_WR_OFFSET_B_SS_OFFSET_WIDTH    ((uint32_t)0x00000010)
#define SMU_RU_0_WR_OFFSET_B_ANT_OFFSET_MASK    ((uint32_t)0x0000FFFF)
#define SMU_RU_0_WR_OFFSET_B_ANT_OFFSET_LSB    0
#define SMU_RU_0_WR_OFFSET_B_ANT_OFFSET_WIDTH    ((uint32_t)0x00000010)

#define SMU_RU_0_WR_OFFSET_B_SS_OFFSET_RST    0x0
#define SMU_RU_0_WR_OFFSET_B_ANT_OFFSET_RST    0x0

__INLINE void smu_ru_0_wr_offset_b_pack(uint16_t ss_offset, uint16_t ant_offset)
{
	ASSERT_ERR((((uint32_t)ss_offset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)ant_offset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_0_WR_OFFSET_B_ADDR,  ((uint32_t)ss_offset << 16) |((uint32_t)ant_offset << 0));
}

__INLINE void smu_ru_0_wr_offset_b_unpack(uint16_t* ss_offset, uint16_t* ant_offset)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_0_WR_OFFSET_B_ADDR);

	*ss_offset = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*ant_offset = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t smu_ru_0_wr_offset_b_ss_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_0_WR_OFFSET_B_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void smu_ru_0_wr_offset_b_ss_offset_setf(uint16_t ssoffset)
{
	ASSERT_ERR((((uint32_t)ssoffset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SMU_RU_0_WR_OFFSET_B_ADDR, (REG_PL_RD(SMU_RU_0_WR_OFFSET_B_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)ssoffset <<16));
}
__INLINE uint16_t smu_ru_0_wr_offset_b_ant_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_0_WR_OFFSET_B_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void smu_ru_0_wr_offset_b_ant_offset_setf(uint16_t antoffset)
{
	ASSERT_ERR((((uint32_t)antoffset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_0_WR_OFFSET_B_ADDR, (REG_PL_RD(SMU_RU_0_WR_OFFSET_B_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)antoffset <<0));
}

/**
 * @brief RU_1_CFG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26:24 STARTING_STS              0x0
 *    21:16 RU_INDEX                  0x0
 *    14:12 RU_TYPE                   0x0
 *    11    SMOOTH_FILTER_EN          0              
 *    10    PILOT_AV_EN               0              
 *    09:08 OUTPUT_DECIMATION         0x0
 *    07:06 NB_SC_SW_A                0x0
 *    05:04 GROUPING                  0x0
 *    03:00 NSS                       0x0
 * </pre>
 */
#define SMU_RU_1_CFG_ADDR        (REG_SMU_BASE_ADDR+0x00000120)
#define SMU_RU_1_CFG_OFFSET      0x00000120
#define SMU_RU_1_CFG_INDEX       0x00000048
#define SMU_RU_1_CFG_RESET       0x00000000

__INLINE uint32_t  smu_ru_1_cfg_get(void)
{
	return REG_PL_RD(SMU_RU_1_CFG_ADDR);
}

__INLINE void smu_ru_1_cfg_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_1_CFG_ADDR, value);
}

// field definitions
#define SMU_RU_1_CFG_STARTING_STS_MASK      ((uint32_t)0x07000000)
#define SMU_RU_1_CFG_STARTING_STS_LSB       24
#define SMU_RU_1_CFG_STARTING_STS_WIDTH     ((uint32_t)0x00000003)
#define SMU_RU_1_CFG_RU_INDEX_MASK          ((uint32_t)0x003F0000)
#define SMU_RU_1_CFG_RU_INDEX_LSB           16
#define SMU_RU_1_CFG_RU_INDEX_WIDTH         ((uint32_t)0x00000006)
#define SMU_RU_1_CFG_RU_TYPE_MASK           ((uint32_t)0x00007000)
#define SMU_RU_1_CFG_RU_TYPE_LSB            12
#define SMU_RU_1_CFG_RU_TYPE_WIDTH          ((uint32_t)0x00000003)
#define SMU_RU_1_CFG_SMOOTH_FILTER_EN_BIT    ((uint32_t)0x00000800)
#define SMU_RU_1_CFG_SMOOTH_FILTER_EN_POS    11
#define SMU_RU_1_CFG_PILOT_AV_EN_BIT        ((uint32_t)0x00000400)
#define SMU_RU_1_CFG_PILOT_AV_EN_POS        10
#define SMU_RU_1_CFG_OUTPUT_DECIMATION_MASK    ((uint32_t)0x00000300)
#define SMU_RU_1_CFG_OUTPUT_DECIMATION_LSB    8
#define SMU_RU_1_CFG_OUTPUT_DECIMATION_WIDTH    ((uint32_t)0x00000002)
#define SMU_RU_1_CFG_NB_SC_SW_A_MASK        ((uint32_t)0x000000C0)
#define SMU_RU_1_CFG_NB_SC_SW_A_LSB         6
#define SMU_RU_1_CFG_NB_SC_SW_A_WIDTH       ((uint32_t)0x00000002)
#define SMU_RU_1_CFG_GROUPING_MASK          ((uint32_t)0x00000030)
#define SMU_RU_1_CFG_GROUPING_LSB           4
#define SMU_RU_1_CFG_GROUPING_WIDTH         ((uint32_t)0x00000002)
#define SMU_RU_1_CFG_NSS_MASK               ((uint32_t)0x0000000F)
#define SMU_RU_1_CFG_NSS_LSB                0
#define SMU_RU_1_CFG_NSS_WIDTH              ((uint32_t)0x00000004)

#define SMU_RU_1_CFG_STARTING_STS_RST       0x0
#define SMU_RU_1_CFG_RU_INDEX_RST           0x0
#define SMU_RU_1_CFG_RU_TYPE_RST            0x0
#define SMU_RU_1_CFG_SMOOTH_FILTER_EN_RST    0x0
#define SMU_RU_1_CFG_PILOT_AV_EN_RST        0x0
#define SMU_RU_1_CFG_OUTPUT_DECIMATION_RST    0x0
#define SMU_RU_1_CFG_NB_SC_SW_A_RST         0x0
#define SMU_RU_1_CFG_GROUPING_RST           0x0
#define SMU_RU_1_CFG_NSS_RST                0x0

__INLINE void smu_ru_1_cfg_pack(uint8_t starting_sts, uint8_t ru_index, uint8_t ru_type, uint8_t smooth_filter_en, uint8_t pilot_av_en, uint8_t output_decimation, uint8_t nb_sc_sw_a, uint8_t grouping, uint8_t nss)
{
	ASSERT_ERR((((uint32_t)starting_sts << 24) & ~((uint32_t)0x07000000)) == 0);
	ASSERT_ERR((((uint32_t)ru_index << 16) & ~((uint32_t)0x003F0000)) == 0);
	ASSERT_ERR((((uint32_t)ru_type << 12) & ~((uint32_t)0x00007000)) == 0);
	ASSERT_ERR((((uint32_t)smooth_filter_en << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)pilot_av_en << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)output_decimation << 8) & ~((uint32_t)0x00000300)) == 0);
	ASSERT_ERR((((uint32_t)nb_sc_sw_a << 6) & ~((uint32_t)0x000000C0)) == 0);
	ASSERT_ERR((((uint32_t)grouping << 4) & ~((uint32_t)0x00000030)) == 0);
	ASSERT_ERR((((uint32_t)nss << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(SMU_RU_1_CFG_ADDR,  ((uint32_t)starting_sts << 24) |((uint32_t)ru_index << 16) |((uint32_t)ru_type << 12) |((uint32_t)smooth_filter_en << 11) |((uint32_t)pilot_av_en << 10) |((uint32_t)output_decimation << 8) |((uint32_t)nb_sc_sw_a << 6) |((uint32_t)grouping << 4) |((uint32_t)nss << 0));
}

__INLINE void smu_ru_1_cfg_unpack(uint8_t* starting_sts, uint8_t* ru_index, uint8_t* ru_type, uint8_t* smooth_filter_en, uint8_t* pilot_av_en, uint8_t* output_decimation, uint8_t* nb_sc_sw_a, uint8_t* grouping, uint8_t* nss)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_1_CFG_ADDR);

	*starting_sts = (localVal & ((uint32_t)0x07000000)) >>  24;
	*ru_index = (localVal & ((uint32_t)0x003F0000)) >>  16;
	*ru_type = (localVal & ((uint32_t)0x00007000)) >>  12;
	*smooth_filter_en = (localVal & ((uint32_t)0x00000800)) >>  11;
	*pilot_av_en = (localVal & ((uint32_t)0x00000400)) >>  10;
	*output_decimation = (localVal & ((uint32_t)0x00000300)) >>  8;
	*nb_sc_sw_a = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*grouping = (localVal & ((uint32_t)0x00000030)) >>  4;
	*nss = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t smu_ru_1_cfg_starting_sts_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_1_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE void smu_ru_1_cfg_starting_sts_setf(uint8_t startingsts)
{
	ASSERT_ERR((((uint32_t)startingsts << 24) & ~((uint32_t)0x07000000)) == 0);
	REG_PL_WR(SMU_RU_1_CFG_ADDR, (REG_PL_RD(SMU_RU_1_CFG_ADDR) & ~((uint32_t)0x07000000)) | ((uint32_t)startingsts <<24));
}
__INLINE uint8_t smu_ru_1_cfg_ru_index_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_1_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x003F0000)) >> 16);
}
__INLINE void smu_ru_1_cfg_ru_index_setf(uint8_t ruindex)
{
	ASSERT_ERR((((uint32_t)ruindex << 16) & ~((uint32_t)0x003F0000)) == 0);
	REG_PL_WR(SMU_RU_1_CFG_ADDR, (REG_PL_RD(SMU_RU_1_CFG_ADDR) & ~((uint32_t)0x003F0000)) | ((uint32_t)ruindex <<16));
}
__INLINE uint8_t smu_ru_1_cfg_ru_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_1_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007000)) >> 12);
}
__INLINE void smu_ru_1_cfg_ru_type_setf(uint8_t rutype)
{
	ASSERT_ERR((((uint32_t)rutype << 12) & ~((uint32_t)0x00007000)) == 0);
	REG_PL_WR(SMU_RU_1_CFG_ADDR, (REG_PL_RD(SMU_RU_1_CFG_ADDR) & ~((uint32_t)0x00007000)) | ((uint32_t)rutype <<12));
}
__INLINE uint8_t smu_ru_1_cfg_smooth_filter_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_1_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void smu_ru_1_cfg_smooth_filter_en_setf(uint8_t smoothfilteren)
{
	ASSERT_ERR((((uint32_t)smoothfilteren << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(SMU_RU_1_CFG_ADDR, (REG_PL_RD(SMU_RU_1_CFG_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)smoothfilteren <<11));
}
__INLINE uint8_t smu_ru_1_cfg_pilot_av_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_1_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void smu_ru_1_cfg_pilot_av_en_setf(uint8_t pilotaven)
{
	ASSERT_ERR((((uint32_t)pilotaven << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(SMU_RU_1_CFG_ADDR, (REG_PL_RD(SMU_RU_1_CFG_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)pilotaven <<10));
}
__INLINE uint8_t smu_ru_1_cfg_output_decimation_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_1_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000300)) >> 8);
}
__INLINE void smu_ru_1_cfg_output_decimation_setf(uint8_t outputdecimation)
{
	ASSERT_ERR((((uint32_t)outputdecimation << 8) & ~((uint32_t)0x00000300)) == 0);
	REG_PL_WR(SMU_RU_1_CFG_ADDR, (REG_PL_RD(SMU_RU_1_CFG_ADDR) & ~((uint32_t)0x00000300)) | ((uint32_t)outputdecimation <<8));
}
__INLINE uint8_t smu_ru_1_cfg_nb_sc_sw_a_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_1_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE void smu_ru_1_cfg_nb_sc_sw_a_setf(uint8_t nbscswa)
{
	ASSERT_ERR((((uint32_t)nbscswa << 6) & ~((uint32_t)0x000000C0)) == 0);
	REG_PL_WR(SMU_RU_1_CFG_ADDR, (REG_PL_RD(SMU_RU_1_CFG_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)nbscswa <<6));
}
__INLINE uint8_t smu_ru_1_cfg_grouping_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_1_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000030)) >> 4);
}
__INLINE void smu_ru_1_cfg_grouping_setf(uint8_t grouping)
{
	ASSERT_ERR((((uint32_t)grouping << 4) & ~((uint32_t)0x00000030)) == 0);
	REG_PL_WR(SMU_RU_1_CFG_ADDR, (REG_PL_RD(SMU_RU_1_CFG_ADDR) & ~((uint32_t)0x00000030)) | ((uint32_t)grouping <<4));
}
__INLINE uint8_t smu_ru_1_cfg_nss_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_1_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void smu_ru_1_cfg_nss_setf(uint8_t nss)
{
	ASSERT_ERR((((uint32_t)nss << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(SMU_RU_1_CFG_ADDR, (REG_PL_RD(SMU_RU_1_CFG_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)nss <<0));
}

/**
 * @brief RU_1_FILTER_PTR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 FILTER_PTR                0x0
 * </pre>
 */
#define SMU_RU_1_FILTER_PTR_ADDR        (REG_SMU_BASE_ADDR+0x00000124)
#define SMU_RU_1_FILTER_PTR_OFFSET      0x00000124
#define SMU_RU_1_FILTER_PTR_INDEX       0x00000049
#define SMU_RU_1_FILTER_PTR_RESET       0x00000000

__INLINE uint32_t  smu_ru_1_filter_ptr_get(void)
{
	return REG_PL_RD(SMU_RU_1_FILTER_PTR_ADDR);
}

__INLINE void smu_ru_1_filter_ptr_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_1_FILTER_PTR_ADDR, value);
}

// field definitions
#define SMU_RU_1_FILTER_PTR_FILTER_PTR_MASK    ((uint32_t)0xFFFFFFFF)
#define SMU_RU_1_FILTER_PTR_FILTER_PTR_LSB    0
#define SMU_RU_1_FILTER_PTR_FILTER_PTR_WIDTH    ((uint32_t)0x00000020)

#define SMU_RU_1_FILTER_PTR_FILTER_PTR_RST    0x0

__INLINE uint32_t smu_ru_1_filter_ptr_filter_ptr_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_1_FILTER_PTR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void smu_ru_1_filter_ptr_filter_ptr_setf(uint32_t filterptr)
{
	ASSERT_ERR((((uint32_t)filterptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SMU_RU_1_FILTER_PTR_ADDR, (uint32_t)filterptr << 0);
}

/**
 * @brief RU_1_DATA_RD_PTR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DATA_RD_PTR               0x0
 * </pre>
 */
#define SMU_RU_1_DATA_RD_PTR_ADDR        (REG_SMU_BASE_ADDR+0x00000128)
#define SMU_RU_1_DATA_RD_PTR_OFFSET      0x00000128
#define SMU_RU_1_DATA_RD_PTR_INDEX       0x0000004A
#define SMU_RU_1_DATA_RD_PTR_RESET       0x00000000

__INLINE uint32_t  smu_ru_1_data_rd_ptr_get(void)
{
	return REG_PL_RD(SMU_RU_1_DATA_RD_PTR_ADDR);
}

__INLINE void smu_ru_1_data_rd_ptr_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_1_DATA_RD_PTR_ADDR, value);
}

// field definitions
#define SMU_RU_1_DATA_RD_PTR_DATA_RD_PTR_MASK    ((uint32_t)0xFFFFFFFF)
#define SMU_RU_1_DATA_RD_PTR_DATA_RD_PTR_LSB    0
#define SMU_RU_1_DATA_RD_PTR_DATA_RD_PTR_WIDTH    ((uint32_t)0x00000020)

#define SMU_RU_1_DATA_RD_PTR_DATA_RD_PTR_RST    0x0

__INLINE uint32_t smu_ru_1_data_rd_ptr_data_rd_ptr_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_1_DATA_RD_PTR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void smu_ru_1_data_rd_ptr_data_rd_ptr_setf(uint32_t datardptr)
{
	ASSERT_ERR((((uint32_t)datardptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SMU_RU_1_DATA_RD_PTR_ADDR, (uint32_t)datardptr << 0);
}

/**
 * @brief RU_1_RD_OFFSET register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SS_OFFSET                 0x0
 *    15:00 ANT_OFFSET                0x0
 * </pre>
 */
#define SMU_RU_1_RD_OFFSET_ADDR        (REG_SMU_BASE_ADDR+0x0000012C)
#define SMU_RU_1_RD_OFFSET_OFFSET      0x0000012C
#define SMU_RU_1_RD_OFFSET_INDEX       0x0000004B
#define SMU_RU_1_RD_OFFSET_RESET       0x00000000

__INLINE uint32_t  smu_ru_1_rd_offset_get(void)
{
	return REG_PL_RD(SMU_RU_1_RD_OFFSET_ADDR);
}

__INLINE void smu_ru_1_rd_offset_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_1_RD_OFFSET_ADDR, value);
}

// field definitions
#define SMU_RU_1_RD_OFFSET_SS_OFFSET_MASK    ((uint32_t)0xFFFF0000)
#define SMU_RU_1_RD_OFFSET_SS_OFFSET_LSB    16
#define SMU_RU_1_RD_OFFSET_SS_OFFSET_WIDTH    ((uint32_t)0x00000010)
#define SMU_RU_1_RD_OFFSET_ANT_OFFSET_MASK    ((uint32_t)0x0000FFFF)
#define SMU_RU_1_RD_OFFSET_ANT_OFFSET_LSB    0
#define SMU_RU_1_RD_OFFSET_ANT_OFFSET_WIDTH    ((uint32_t)0x00000010)

#define SMU_RU_1_RD_OFFSET_SS_OFFSET_RST    0x0
#define SMU_RU_1_RD_OFFSET_ANT_OFFSET_RST    0x0

__INLINE void smu_ru_1_rd_offset_pack(uint16_t ss_offset, uint16_t ant_offset)
{
	ASSERT_ERR((((uint32_t)ss_offset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)ant_offset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_1_RD_OFFSET_ADDR,  ((uint32_t)ss_offset << 16) |((uint32_t)ant_offset << 0));
}

__INLINE void smu_ru_1_rd_offset_unpack(uint16_t* ss_offset, uint16_t* ant_offset)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_1_RD_OFFSET_ADDR);

	*ss_offset = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*ant_offset = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t smu_ru_1_rd_offset_ss_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_1_RD_OFFSET_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void smu_ru_1_rd_offset_ss_offset_setf(uint16_t ssoffset)
{
	ASSERT_ERR((((uint32_t)ssoffset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SMU_RU_1_RD_OFFSET_ADDR, (REG_PL_RD(SMU_RU_1_RD_OFFSET_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)ssoffset <<16));
}
__INLINE uint16_t smu_ru_1_rd_offset_ant_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_1_RD_OFFSET_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void smu_ru_1_rd_offset_ant_offset_setf(uint16_t antoffset)
{
	ASSERT_ERR((((uint32_t)antoffset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_1_RD_OFFSET_ADDR, (REG_PL_RD(SMU_RU_1_RD_OFFSET_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)antoffset <<0));
}

/**
 * @brief RU_1_DATA_WR_PTR_A register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DATA_WR_PTR_A             0x0
 * </pre>
 */
#define SMU_RU_1_DATA_WR_PTR_A_ADDR        (REG_SMU_BASE_ADDR+0x00000130)
#define SMU_RU_1_DATA_WR_PTR_A_OFFSET      0x00000130
#define SMU_RU_1_DATA_WR_PTR_A_INDEX       0x0000004C
#define SMU_RU_1_DATA_WR_PTR_A_RESET       0x00000000

__INLINE uint32_t  smu_ru_1_data_wr_ptr_a_get(void)
{
	return REG_PL_RD(SMU_RU_1_DATA_WR_PTR_A_ADDR);
}

__INLINE void smu_ru_1_data_wr_ptr_a_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_1_DATA_WR_PTR_A_ADDR, value);
}

// field definitions
#define SMU_RU_1_DATA_WR_PTR_A_DATA_WR_PTR_A_MASK    ((uint32_t)0xFFFFFFFF)
#define SMU_RU_1_DATA_WR_PTR_A_DATA_WR_PTR_A_LSB    0
#define SMU_RU_1_DATA_WR_PTR_A_DATA_WR_PTR_A_WIDTH    ((uint32_t)0x00000020)

#define SMU_RU_1_DATA_WR_PTR_A_DATA_WR_PTR_A_RST    0x0

__INLINE uint32_t smu_ru_1_data_wr_ptr_a_data_wr_ptr_a_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_1_DATA_WR_PTR_A_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void smu_ru_1_data_wr_ptr_a_data_wr_ptr_a_setf(uint32_t datawrptra)
{
	ASSERT_ERR((((uint32_t)datawrptra << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SMU_RU_1_DATA_WR_PTR_A_ADDR, (uint32_t)datawrptra << 0);
}

/**
 * @brief RU_1_DATA_WR_PTR_B register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DATA_WR_PTR_B             0x0
 * </pre>
 */
#define SMU_RU_1_DATA_WR_PTR_B_ADDR        (REG_SMU_BASE_ADDR+0x00000134)
#define SMU_RU_1_DATA_WR_PTR_B_OFFSET      0x00000134
#define SMU_RU_1_DATA_WR_PTR_B_INDEX       0x0000004D
#define SMU_RU_1_DATA_WR_PTR_B_RESET       0x00000000

__INLINE uint32_t  smu_ru_1_data_wr_ptr_b_get(void)
{
	return REG_PL_RD(SMU_RU_1_DATA_WR_PTR_B_ADDR);
}

__INLINE void smu_ru_1_data_wr_ptr_b_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_1_DATA_WR_PTR_B_ADDR, value);
}

// field definitions
#define SMU_RU_1_DATA_WR_PTR_B_DATA_WR_PTR_B_MASK    ((uint32_t)0xFFFFFFFF)
#define SMU_RU_1_DATA_WR_PTR_B_DATA_WR_PTR_B_LSB    0
#define SMU_RU_1_DATA_WR_PTR_B_DATA_WR_PTR_B_WIDTH    ((uint32_t)0x00000020)

#define SMU_RU_1_DATA_WR_PTR_B_DATA_WR_PTR_B_RST    0x0

__INLINE uint32_t smu_ru_1_data_wr_ptr_b_data_wr_ptr_b_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_1_DATA_WR_PTR_B_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void smu_ru_1_data_wr_ptr_b_data_wr_ptr_b_setf(uint32_t datawrptrb)
{
	ASSERT_ERR((((uint32_t)datawrptrb << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SMU_RU_1_DATA_WR_PTR_B_ADDR, (uint32_t)datawrptrb << 0);
}

/**
 * @brief RU_1_WR_OFFSET_A register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SS_OFFSET                 0x0
 *    15:00 ANT_OFFSET                0x0
 * </pre>
 */
#define SMU_RU_1_WR_OFFSET_A_ADDR        (REG_SMU_BASE_ADDR+0x00000138)
#define SMU_RU_1_WR_OFFSET_A_OFFSET      0x00000138
#define SMU_RU_1_WR_OFFSET_A_INDEX       0x0000004E
#define SMU_RU_1_WR_OFFSET_A_RESET       0x00000000

__INLINE uint32_t  smu_ru_1_wr_offset_a_get(void)
{
	return REG_PL_RD(SMU_RU_1_WR_OFFSET_A_ADDR);
}

__INLINE void smu_ru_1_wr_offset_a_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_1_WR_OFFSET_A_ADDR, value);
}

// field definitions
#define SMU_RU_1_WR_OFFSET_A_SS_OFFSET_MASK    ((uint32_t)0xFFFF0000)
#define SMU_RU_1_WR_OFFSET_A_SS_OFFSET_LSB    16
#define SMU_RU_1_WR_OFFSET_A_SS_OFFSET_WIDTH    ((uint32_t)0x00000010)
#define SMU_RU_1_WR_OFFSET_A_ANT_OFFSET_MASK    ((uint32_t)0x0000FFFF)
#define SMU_RU_1_WR_OFFSET_A_ANT_OFFSET_LSB    0
#define SMU_RU_1_WR_OFFSET_A_ANT_OFFSET_WIDTH    ((uint32_t)0x00000010)

#define SMU_RU_1_WR_OFFSET_A_SS_OFFSET_RST    0x0
#define SMU_RU_1_WR_OFFSET_A_ANT_OFFSET_RST    0x0

__INLINE void smu_ru_1_wr_offset_a_pack(uint16_t ss_offset, uint16_t ant_offset)
{
	ASSERT_ERR((((uint32_t)ss_offset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)ant_offset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_1_WR_OFFSET_A_ADDR,  ((uint32_t)ss_offset << 16) |((uint32_t)ant_offset << 0));
}

__INLINE void smu_ru_1_wr_offset_a_unpack(uint16_t* ss_offset, uint16_t* ant_offset)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_1_WR_OFFSET_A_ADDR);

	*ss_offset = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*ant_offset = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t smu_ru_1_wr_offset_a_ss_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_1_WR_OFFSET_A_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void smu_ru_1_wr_offset_a_ss_offset_setf(uint16_t ssoffset)
{
	ASSERT_ERR((((uint32_t)ssoffset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SMU_RU_1_WR_OFFSET_A_ADDR, (REG_PL_RD(SMU_RU_1_WR_OFFSET_A_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)ssoffset <<16));
}
__INLINE uint16_t smu_ru_1_wr_offset_a_ant_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_1_WR_OFFSET_A_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void smu_ru_1_wr_offset_a_ant_offset_setf(uint16_t antoffset)
{
	ASSERT_ERR((((uint32_t)antoffset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_1_WR_OFFSET_A_ADDR, (REG_PL_RD(SMU_RU_1_WR_OFFSET_A_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)antoffset <<0));
}

/**
 * @brief RU_1_WR_OFFSET_B register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SS_OFFSET                 0x0
 *    15:00 ANT_OFFSET                0x0
 * </pre>
 */
#define SMU_RU_1_WR_OFFSET_B_ADDR        (REG_SMU_BASE_ADDR+0x0000013C)
#define SMU_RU_1_WR_OFFSET_B_OFFSET      0x0000013C
#define SMU_RU_1_WR_OFFSET_B_INDEX       0x0000004F
#define SMU_RU_1_WR_OFFSET_B_RESET       0x00000000

__INLINE uint32_t  smu_ru_1_wr_offset_b_get(void)
{
	return REG_PL_RD(SMU_RU_1_WR_OFFSET_B_ADDR);
}

__INLINE void smu_ru_1_wr_offset_b_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_1_WR_OFFSET_B_ADDR, value);
}

// field definitions
#define SMU_RU_1_WR_OFFSET_B_SS_OFFSET_MASK    ((uint32_t)0xFFFF0000)
#define SMU_RU_1_WR_OFFSET_B_SS_OFFSET_LSB    16
#define SMU_RU_1_WR_OFFSET_B_SS_OFFSET_WIDTH    ((uint32_t)0x00000010)
#define SMU_RU_1_WR_OFFSET_B_ANT_OFFSET_MASK    ((uint32_t)0x0000FFFF)
#define SMU_RU_1_WR_OFFSET_B_ANT_OFFSET_LSB    0
#define SMU_RU_1_WR_OFFSET_B_ANT_OFFSET_WIDTH    ((uint32_t)0x00000010)

#define SMU_RU_1_WR_OFFSET_B_SS_OFFSET_RST    0x0
#define SMU_RU_1_WR_OFFSET_B_ANT_OFFSET_RST    0x0

__INLINE void smu_ru_1_wr_offset_b_pack(uint16_t ss_offset, uint16_t ant_offset)
{
	ASSERT_ERR((((uint32_t)ss_offset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)ant_offset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_1_WR_OFFSET_B_ADDR,  ((uint32_t)ss_offset << 16) |((uint32_t)ant_offset << 0));
}

__INLINE void smu_ru_1_wr_offset_b_unpack(uint16_t* ss_offset, uint16_t* ant_offset)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_1_WR_OFFSET_B_ADDR);

	*ss_offset = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*ant_offset = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t smu_ru_1_wr_offset_b_ss_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_1_WR_OFFSET_B_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void smu_ru_1_wr_offset_b_ss_offset_setf(uint16_t ssoffset)
{
	ASSERT_ERR((((uint32_t)ssoffset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SMU_RU_1_WR_OFFSET_B_ADDR, (REG_PL_RD(SMU_RU_1_WR_OFFSET_B_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)ssoffset <<16));
}
__INLINE uint16_t smu_ru_1_wr_offset_b_ant_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_1_WR_OFFSET_B_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void smu_ru_1_wr_offset_b_ant_offset_setf(uint16_t antoffset)
{
	ASSERT_ERR((((uint32_t)antoffset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_1_WR_OFFSET_B_ADDR, (REG_PL_RD(SMU_RU_1_WR_OFFSET_B_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)antoffset <<0));
}

/**
 * @brief RU_2_CFG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26:24 STARTING_STS              0x0
 *    21:16 RU_INDEX                  0x0
 *    14:12 RU_TYPE                   0x0
 *    11    SMOOTH_FILTER_EN          0              
 *    10    PILOT_AV_EN               0              
 *    09:08 OUTPUT_DECIMATION         0x0
 *    07:06 NB_SC_SW_A                0x0
 *    05:04 GROUPING                  0x0
 *    03:00 NSS                       0x0
 * </pre>
 */
#define SMU_RU_2_CFG_ADDR        (REG_SMU_BASE_ADDR+0x00000140)
#define SMU_RU_2_CFG_OFFSET      0x00000140
#define SMU_RU_2_CFG_INDEX       0x00000050
#define SMU_RU_2_CFG_RESET       0x00000000

__INLINE uint32_t  smu_ru_2_cfg_get(void)
{
	return REG_PL_RD(SMU_RU_2_CFG_ADDR);
}

__INLINE void smu_ru_2_cfg_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_2_CFG_ADDR, value);
}

// field definitions
#define SMU_RU_2_CFG_STARTING_STS_MASK      ((uint32_t)0x07000000)
#define SMU_RU_2_CFG_STARTING_STS_LSB       24
#define SMU_RU_2_CFG_STARTING_STS_WIDTH     ((uint32_t)0x00000003)
#define SMU_RU_2_CFG_RU_INDEX_MASK          ((uint32_t)0x003F0000)
#define SMU_RU_2_CFG_RU_INDEX_LSB           16
#define SMU_RU_2_CFG_RU_INDEX_WIDTH         ((uint32_t)0x00000006)
#define SMU_RU_2_CFG_RU_TYPE_MASK           ((uint32_t)0x00007000)
#define SMU_RU_2_CFG_RU_TYPE_LSB            12
#define SMU_RU_2_CFG_RU_TYPE_WIDTH          ((uint32_t)0x00000003)
#define SMU_RU_2_CFG_SMOOTH_FILTER_EN_BIT    ((uint32_t)0x00000800)
#define SMU_RU_2_CFG_SMOOTH_FILTER_EN_POS    11
#define SMU_RU_2_CFG_PILOT_AV_EN_BIT        ((uint32_t)0x00000400)
#define SMU_RU_2_CFG_PILOT_AV_EN_POS        10
#define SMU_RU_2_CFG_OUTPUT_DECIMATION_MASK    ((uint32_t)0x00000300)
#define SMU_RU_2_CFG_OUTPUT_DECIMATION_LSB    8
#define SMU_RU_2_CFG_OUTPUT_DECIMATION_WIDTH    ((uint32_t)0x00000002)
#define SMU_RU_2_CFG_NB_SC_SW_A_MASK        ((uint32_t)0x000000C0)
#define SMU_RU_2_CFG_NB_SC_SW_A_LSB         6
#define SMU_RU_2_CFG_NB_SC_SW_A_WIDTH       ((uint32_t)0x00000002)
#define SMU_RU_2_CFG_GROUPING_MASK          ((uint32_t)0x00000030)
#define SMU_RU_2_CFG_GROUPING_LSB           4
#define SMU_RU_2_CFG_GROUPING_WIDTH         ((uint32_t)0x00000002)
#define SMU_RU_2_CFG_NSS_MASK               ((uint32_t)0x0000000F)
#define SMU_RU_2_CFG_NSS_LSB                0
#define SMU_RU_2_CFG_NSS_WIDTH              ((uint32_t)0x00000004)

#define SMU_RU_2_CFG_STARTING_STS_RST       0x0
#define SMU_RU_2_CFG_RU_INDEX_RST           0x0
#define SMU_RU_2_CFG_RU_TYPE_RST            0x0
#define SMU_RU_2_CFG_SMOOTH_FILTER_EN_RST    0x0
#define SMU_RU_2_CFG_PILOT_AV_EN_RST        0x0
#define SMU_RU_2_CFG_OUTPUT_DECIMATION_RST    0x0
#define SMU_RU_2_CFG_NB_SC_SW_A_RST         0x0
#define SMU_RU_2_CFG_GROUPING_RST           0x0
#define SMU_RU_2_CFG_NSS_RST                0x0

__INLINE void smu_ru_2_cfg_pack(uint8_t starting_sts, uint8_t ru_index, uint8_t ru_type, uint8_t smooth_filter_en, uint8_t pilot_av_en, uint8_t output_decimation, uint8_t nb_sc_sw_a, uint8_t grouping, uint8_t nss)
{
	ASSERT_ERR((((uint32_t)starting_sts << 24) & ~((uint32_t)0x07000000)) == 0);
	ASSERT_ERR((((uint32_t)ru_index << 16) & ~((uint32_t)0x003F0000)) == 0);
	ASSERT_ERR((((uint32_t)ru_type << 12) & ~((uint32_t)0x00007000)) == 0);
	ASSERT_ERR((((uint32_t)smooth_filter_en << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)pilot_av_en << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)output_decimation << 8) & ~((uint32_t)0x00000300)) == 0);
	ASSERT_ERR((((uint32_t)nb_sc_sw_a << 6) & ~((uint32_t)0x000000C0)) == 0);
	ASSERT_ERR((((uint32_t)grouping << 4) & ~((uint32_t)0x00000030)) == 0);
	ASSERT_ERR((((uint32_t)nss << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(SMU_RU_2_CFG_ADDR,  ((uint32_t)starting_sts << 24) |((uint32_t)ru_index << 16) |((uint32_t)ru_type << 12) |((uint32_t)smooth_filter_en << 11) |((uint32_t)pilot_av_en << 10) |((uint32_t)output_decimation << 8) |((uint32_t)nb_sc_sw_a << 6) |((uint32_t)grouping << 4) |((uint32_t)nss << 0));
}

__INLINE void smu_ru_2_cfg_unpack(uint8_t* starting_sts, uint8_t* ru_index, uint8_t* ru_type, uint8_t* smooth_filter_en, uint8_t* pilot_av_en, uint8_t* output_decimation, uint8_t* nb_sc_sw_a, uint8_t* grouping, uint8_t* nss)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_2_CFG_ADDR);

	*starting_sts = (localVal & ((uint32_t)0x07000000)) >>  24;
	*ru_index = (localVal & ((uint32_t)0x003F0000)) >>  16;
	*ru_type = (localVal & ((uint32_t)0x00007000)) >>  12;
	*smooth_filter_en = (localVal & ((uint32_t)0x00000800)) >>  11;
	*pilot_av_en = (localVal & ((uint32_t)0x00000400)) >>  10;
	*output_decimation = (localVal & ((uint32_t)0x00000300)) >>  8;
	*nb_sc_sw_a = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*grouping = (localVal & ((uint32_t)0x00000030)) >>  4;
	*nss = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t smu_ru_2_cfg_starting_sts_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_2_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE void smu_ru_2_cfg_starting_sts_setf(uint8_t startingsts)
{
	ASSERT_ERR((((uint32_t)startingsts << 24) & ~((uint32_t)0x07000000)) == 0);
	REG_PL_WR(SMU_RU_2_CFG_ADDR, (REG_PL_RD(SMU_RU_2_CFG_ADDR) & ~((uint32_t)0x07000000)) | ((uint32_t)startingsts <<24));
}
__INLINE uint8_t smu_ru_2_cfg_ru_index_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_2_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x003F0000)) >> 16);
}
__INLINE void smu_ru_2_cfg_ru_index_setf(uint8_t ruindex)
{
	ASSERT_ERR((((uint32_t)ruindex << 16) & ~((uint32_t)0x003F0000)) == 0);
	REG_PL_WR(SMU_RU_2_CFG_ADDR, (REG_PL_RD(SMU_RU_2_CFG_ADDR) & ~((uint32_t)0x003F0000)) | ((uint32_t)ruindex <<16));
}
__INLINE uint8_t smu_ru_2_cfg_ru_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_2_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007000)) >> 12);
}
__INLINE void smu_ru_2_cfg_ru_type_setf(uint8_t rutype)
{
	ASSERT_ERR((((uint32_t)rutype << 12) & ~((uint32_t)0x00007000)) == 0);
	REG_PL_WR(SMU_RU_2_CFG_ADDR, (REG_PL_RD(SMU_RU_2_CFG_ADDR) & ~((uint32_t)0x00007000)) | ((uint32_t)rutype <<12));
}
__INLINE uint8_t smu_ru_2_cfg_smooth_filter_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_2_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void smu_ru_2_cfg_smooth_filter_en_setf(uint8_t smoothfilteren)
{
	ASSERT_ERR((((uint32_t)smoothfilteren << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(SMU_RU_2_CFG_ADDR, (REG_PL_RD(SMU_RU_2_CFG_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)smoothfilteren <<11));
}
__INLINE uint8_t smu_ru_2_cfg_pilot_av_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_2_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void smu_ru_2_cfg_pilot_av_en_setf(uint8_t pilotaven)
{
	ASSERT_ERR((((uint32_t)pilotaven << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(SMU_RU_2_CFG_ADDR, (REG_PL_RD(SMU_RU_2_CFG_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)pilotaven <<10));
}
__INLINE uint8_t smu_ru_2_cfg_output_decimation_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_2_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000300)) >> 8);
}
__INLINE void smu_ru_2_cfg_output_decimation_setf(uint8_t outputdecimation)
{
	ASSERT_ERR((((uint32_t)outputdecimation << 8) & ~((uint32_t)0x00000300)) == 0);
	REG_PL_WR(SMU_RU_2_CFG_ADDR, (REG_PL_RD(SMU_RU_2_CFG_ADDR) & ~((uint32_t)0x00000300)) | ((uint32_t)outputdecimation <<8));
}
__INLINE uint8_t smu_ru_2_cfg_nb_sc_sw_a_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_2_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE void smu_ru_2_cfg_nb_sc_sw_a_setf(uint8_t nbscswa)
{
	ASSERT_ERR((((uint32_t)nbscswa << 6) & ~((uint32_t)0x000000C0)) == 0);
	REG_PL_WR(SMU_RU_2_CFG_ADDR, (REG_PL_RD(SMU_RU_2_CFG_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)nbscswa <<6));
}
__INLINE uint8_t smu_ru_2_cfg_grouping_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_2_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000030)) >> 4);
}
__INLINE void smu_ru_2_cfg_grouping_setf(uint8_t grouping)
{
	ASSERT_ERR((((uint32_t)grouping << 4) & ~((uint32_t)0x00000030)) == 0);
	REG_PL_WR(SMU_RU_2_CFG_ADDR, (REG_PL_RD(SMU_RU_2_CFG_ADDR) & ~((uint32_t)0x00000030)) | ((uint32_t)grouping <<4));
}
__INLINE uint8_t smu_ru_2_cfg_nss_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_2_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void smu_ru_2_cfg_nss_setf(uint8_t nss)
{
	ASSERT_ERR((((uint32_t)nss << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(SMU_RU_2_CFG_ADDR, (REG_PL_RD(SMU_RU_2_CFG_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)nss <<0));
}

/**
 * @brief RU_2_FILTER_PTR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 FILTER_PTR                0x0
 * </pre>
 */
#define SMU_RU_2_FILTER_PTR_ADDR        (REG_SMU_BASE_ADDR+0x00000144)
#define SMU_RU_2_FILTER_PTR_OFFSET      0x00000144
#define SMU_RU_2_FILTER_PTR_INDEX       0x00000051
#define SMU_RU_2_FILTER_PTR_RESET       0x00000000

__INLINE uint32_t  smu_ru_2_filter_ptr_get(void)
{
	return REG_PL_RD(SMU_RU_2_FILTER_PTR_ADDR);
}

__INLINE void smu_ru_2_filter_ptr_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_2_FILTER_PTR_ADDR, value);
}

// field definitions
#define SMU_RU_2_FILTER_PTR_FILTER_PTR_MASK    ((uint32_t)0xFFFFFFFF)
#define SMU_RU_2_FILTER_PTR_FILTER_PTR_LSB    0
#define SMU_RU_2_FILTER_PTR_FILTER_PTR_WIDTH    ((uint32_t)0x00000020)

#define SMU_RU_2_FILTER_PTR_FILTER_PTR_RST    0x0

__INLINE uint32_t smu_ru_2_filter_ptr_filter_ptr_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_2_FILTER_PTR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void smu_ru_2_filter_ptr_filter_ptr_setf(uint32_t filterptr)
{
	ASSERT_ERR((((uint32_t)filterptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SMU_RU_2_FILTER_PTR_ADDR, (uint32_t)filterptr << 0);
}

/**
 * @brief RU_2_DATA_RD_PTR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DATA_RD_PTR               0x0
 * </pre>
 */
#define SMU_RU_2_DATA_RD_PTR_ADDR        (REG_SMU_BASE_ADDR+0x00000148)
#define SMU_RU_2_DATA_RD_PTR_OFFSET      0x00000148
#define SMU_RU_2_DATA_RD_PTR_INDEX       0x00000052
#define SMU_RU_2_DATA_RD_PTR_RESET       0x00000000

__INLINE uint32_t  smu_ru_2_data_rd_ptr_get(void)
{
	return REG_PL_RD(SMU_RU_2_DATA_RD_PTR_ADDR);
}

__INLINE void smu_ru_2_data_rd_ptr_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_2_DATA_RD_PTR_ADDR, value);
}

// field definitions
#define SMU_RU_2_DATA_RD_PTR_DATA_RD_PTR_MASK    ((uint32_t)0xFFFFFFFF)
#define SMU_RU_2_DATA_RD_PTR_DATA_RD_PTR_LSB    0
#define SMU_RU_2_DATA_RD_PTR_DATA_RD_PTR_WIDTH    ((uint32_t)0x00000020)

#define SMU_RU_2_DATA_RD_PTR_DATA_RD_PTR_RST    0x0

__INLINE uint32_t smu_ru_2_data_rd_ptr_data_rd_ptr_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_2_DATA_RD_PTR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void smu_ru_2_data_rd_ptr_data_rd_ptr_setf(uint32_t datardptr)
{
	ASSERT_ERR((((uint32_t)datardptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SMU_RU_2_DATA_RD_PTR_ADDR, (uint32_t)datardptr << 0);
}

/**
 * @brief RU_2_RD_OFFSET register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SS_OFFSET                 0x0
 *    15:00 ANT_OFFSET                0x0
 * </pre>
 */
#define SMU_RU_2_RD_OFFSET_ADDR        (REG_SMU_BASE_ADDR+0x0000014C)
#define SMU_RU_2_RD_OFFSET_OFFSET      0x0000014C
#define SMU_RU_2_RD_OFFSET_INDEX       0x00000053
#define SMU_RU_2_RD_OFFSET_RESET       0x00000000

__INLINE uint32_t  smu_ru_2_rd_offset_get(void)
{
	return REG_PL_RD(SMU_RU_2_RD_OFFSET_ADDR);
}

__INLINE void smu_ru_2_rd_offset_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_2_RD_OFFSET_ADDR, value);
}

// field definitions
#define SMU_RU_2_RD_OFFSET_SS_OFFSET_MASK    ((uint32_t)0xFFFF0000)
#define SMU_RU_2_RD_OFFSET_SS_OFFSET_LSB    16
#define SMU_RU_2_RD_OFFSET_SS_OFFSET_WIDTH    ((uint32_t)0x00000010)
#define SMU_RU_2_RD_OFFSET_ANT_OFFSET_MASK    ((uint32_t)0x0000FFFF)
#define SMU_RU_2_RD_OFFSET_ANT_OFFSET_LSB    0
#define SMU_RU_2_RD_OFFSET_ANT_OFFSET_WIDTH    ((uint32_t)0x00000010)

#define SMU_RU_2_RD_OFFSET_SS_OFFSET_RST    0x0
#define SMU_RU_2_RD_OFFSET_ANT_OFFSET_RST    0x0

__INLINE void smu_ru_2_rd_offset_pack(uint16_t ss_offset, uint16_t ant_offset)
{
	ASSERT_ERR((((uint32_t)ss_offset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)ant_offset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_2_RD_OFFSET_ADDR,  ((uint32_t)ss_offset << 16) |((uint32_t)ant_offset << 0));
}

__INLINE void smu_ru_2_rd_offset_unpack(uint16_t* ss_offset, uint16_t* ant_offset)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_2_RD_OFFSET_ADDR);

	*ss_offset = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*ant_offset = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t smu_ru_2_rd_offset_ss_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_2_RD_OFFSET_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void smu_ru_2_rd_offset_ss_offset_setf(uint16_t ssoffset)
{
	ASSERT_ERR((((uint32_t)ssoffset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SMU_RU_2_RD_OFFSET_ADDR, (REG_PL_RD(SMU_RU_2_RD_OFFSET_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)ssoffset <<16));
}
__INLINE uint16_t smu_ru_2_rd_offset_ant_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_2_RD_OFFSET_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void smu_ru_2_rd_offset_ant_offset_setf(uint16_t antoffset)
{
	ASSERT_ERR((((uint32_t)antoffset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_2_RD_OFFSET_ADDR, (REG_PL_RD(SMU_RU_2_RD_OFFSET_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)antoffset <<0));
}

/**
 * @brief RU_2_DATA_WR_PTR_A register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DATA_WR_PTR_A             0x0
 * </pre>
 */
#define SMU_RU_2_DATA_WR_PTR_A_ADDR        (REG_SMU_BASE_ADDR+0x00000150)
#define SMU_RU_2_DATA_WR_PTR_A_OFFSET      0x00000150
#define SMU_RU_2_DATA_WR_PTR_A_INDEX       0x00000054
#define SMU_RU_2_DATA_WR_PTR_A_RESET       0x00000000

__INLINE uint32_t  smu_ru_2_data_wr_ptr_a_get(void)
{
	return REG_PL_RD(SMU_RU_2_DATA_WR_PTR_A_ADDR);
}

__INLINE void smu_ru_2_data_wr_ptr_a_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_2_DATA_WR_PTR_A_ADDR, value);
}

// field definitions
#define SMU_RU_2_DATA_WR_PTR_A_DATA_WR_PTR_A_MASK    ((uint32_t)0xFFFFFFFF)
#define SMU_RU_2_DATA_WR_PTR_A_DATA_WR_PTR_A_LSB    0
#define SMU_RU_2_DATA_WR_PTR_A_DATA_WR_PTR_A_WIDTH    ((uint32_t)0x00000020)

#define SMU_RU_2_DATA_WR_PTR_A_DATA_WR_PTR_A_RST    0x0

__INLINE uint32_t smu_ru_2_data_wr_ptr_a_data_wr_ptr_a_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_2_DATA_WR_PTR_A_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void smu_ru_2_data_wr_ptr_a_data_wr_ptr_a_setf(uint32_t datawrptra)
{
	ASSERT_ERR((((uint32_t)datawrptra << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SMU_RU_2_DATA_WR_PTR_A_ADDR, (uint32_t)datawrptra << 0);
}

/**
 * @brief RU_2_DATA_WR_PTR_B register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DATA_WR_PTR_B             0x0
 * </pre>
 */
#define SMU_RU_2_DATA_WR_PTR_B_ADDR        (REG_SMU_BASE_ADDR+0x00000154)
#define SMU_RU_2_DATA_WR_PTR_B_OFFSET      0x00000154
#define SMU_RU_2_DATA_WR_PTR_B_INDEX       0x00000055
#define SMU_RU_2_DATA_WR_PTR_B_RESET       0x00000000

__INLINE uint32_t  smu_ru_2_data_wr_ptr_b_get(void)
{
	return REG_PL_RD(SMU_RU_2_DATA_WR_PTR_B_ADDR);
}

__INLINE void smu_ru_2_data_wr_ptr_b_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_2_DATA_WR_PTR_B_ADDR, value);
}

// field definitions
#define SMU_RU_2_DATA_WR_PTR_B_DATA_WR_PTR_B_MASK    ((uint32_t)0xFFFFFFFF)
#define SMU_RU_2_DATA_WR_PTR_B_DATA_WR_PTR_B_LSB    0
#define SMU_RU_2_DATA_WR_PTR_B_DATA_WR_PTR_B_WIDTH    ((uint32_t)0x00000020)

#define SMU_RU_2_DATA_WR_PTR_B_DATA_WR_PTR_B_RST    0x0

__INLINE uint32_t smu_ru_2_data_wr_ptr_b_data_wr_ptr_b_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_2_DATA_WR_PTR_B_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void smu_ru_2_data_wr_ptr_b_data_wr_ptr_b_setf(uint32_t datawrptrb)
{
	ASSERT_ERR((((uint32_t)datawrptrb << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SMU_RU_2_DATA_WR_PTR_B_ADDR, (uint32_t)datawrptrb << 0);
}

/**
 * @brief RU_2_WR_OFFSET_A register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SS_OFFSET                 0x0
 *    15:00 ANT_OFFSET                0x0
 * </pre>
 */
#define SMU_RU_2_WR_OFFSET_A_ADDR        (REG_SMU_BASE_ADDR+0x00000158)
#define SMU_RU_2_WR_OFFSET_A_OFFSET      0x00000158
#define SMU_RU_2_WR_OFFSET_A_INDEX       0x00000056
#define SMU_RU_2_WR_OFFSET_A_RESET       0x00000000

__INLINE uint32_t  smu_ru_2_wr_offset_a_get(void)
{
	return REG_PL_RD(SMU_RU_2_WR_OFFSET_A_ADDR);
}

__INLINE void smu_ru_2_wr_offset_a_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_2_WR_OFFSET_A_ADDR, value);
}

// field definitions
#define SMU_RU_2_WR_OFFSET_A_SS_OFFSET_MASK    ((uint32_t)0xFFFF0000)
#define SMU_RU_2_WR_OFFSET_A_SS_OFFSET_LSB    16
#define SMU_RU_2_WR_OFFSET_A_SS_OFFSET_WIDTH    ((uint32_t)0x00000010)
#define SMU_RU_2_WR_OFFSET_A_ANT_OFFSET_MASK    ((uint32_t)0x0000FFFF)
#define SMU_RU_2_WR_OFFSET_A_ANT_OFFSET_LSB    0
#define SMU_RU_2_WR_OFFSET_A_ANT_OFFSET_WIDTH    ((uint32_t)0x00000010)

#define SMU_RU_2_WR_OFFSET_A_SS_OFFSET_RST    0x0
#define SMU_RU_2_WR_OFFSET_A_ANT_OFFSET_RST    0x0

__INLINE void smu_ru_2_wr_offset_a_pack(uint16_t ss_offset, uint16_t ant_offset)
{
	ASSERT_ERR((((uint32_t)ss_offset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)ant_offset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_2_WR_OFFSET_A_ADDR,  ((uint32_t)ss_offset << 16) |((uint32_t)ant_offset << 0));
}

__INLINE void smu_ru_2_wr_offset_a_unpack(uint16_t* ss_offset, uint16_t* ant_offset)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_2_WR_OFFSET_A_ADDR);

	*ss_offset = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*ant_offset = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t smu_ru_2_wr_offset_a_ss_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_2_WR_OFFSET_A_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void smu_ru_2_wr_offset_a_ss_offset_setf(uint16_t ssoffset)
{
	ASSERT_ERR((((uint32_t)ssoffset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SMU_RU_2_WR_OFFSET_A_ADDR, (REG_PL_RD(SMU_RU_2_WR_OFFSET_A_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)ssoffset <<16));
}
__INLINE uint16_t smu_ru_2_wr_offset_a_ant_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_2_WR_OFFSET_A_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void smu_ru_2_wr_offset_a_ant_offset_setf(uint16_t antoffset)
{
	ASSERT_ERR((((uint32_t)antoffset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_2_WR_OFFSET_A_ADDR, (REG_PL_RD(SMU_RU_2_WR_OFFSET_A_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)antoffset <<0));
}

/**
 * @brief RU_2_WR_OFFSET_B register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SS_OFFSET                 0x0
 *    15:00 ANT_OFFSET                0x0
 * </pre>
 */
#define SMU_RU_2_WR_OFFSET_B_ADDR        (REG_SMU_BASE_ADDR+0x0000015C)
#define SMU_RU_2_WR_OFFSET_B_OFFSET      0x0000015C
#define SMU_RU_2_WR_OFFSET_B_INDEX       0x00000057
#define SMU_RU_2_WR_OFFSET_B_RESET       0x00000000

__INLINE uint32_t  smu_ru_2_wr_offset_b_get(void)
{
	return REG_PL_RD(SMU_RU_2_WR_OFFSET_B_ADDR);
}

__INLINE void smu_ru_2_wr_offset_b_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_2_WR_OFFSET_B_ADDR, value);
}

// field definitions
#define SMU_RU_2_WR_OFFSET_B_SS_OFFSET_MASK    ((uint32_t)0xFFFF0000)
#define SMU_RU_2_WR_OFFSET_B_SS_OFFSET_LSB    16
#define SMU_RU_2_WR_OFFSET_B_SS_OFFSET_WIDTH    ((uint32_t)0x00000010)
#define SMU_RU_2_WR_OFFSET_B_ANT_OFFSET_MASK    ((uint32_t)0x0000FFFF)
#define SMU_RU_2_WR_OFFSET_B_ANT_OFFSET_LSB    0
#define SMU_RU_2_WR_OFFSET_B_ANT_OFFSET_WIDTH    ((uint32_t)0x00000010)

#define SMU_RU_2_WR_OFFSET_B_SS_OFFSET_RST    0x0
#define SMU_RU_2_WR_OFFSET_B_ANT_OFFSET_RST    0x0

__INLINE void smu_ru_2_wr_offset_b_pack(uint16_t ss_offset, uint16_t ant_offset)
{
	ASSERT_ERR((((uint32_t)ss_offset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)ant_offset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_2_WR_OFFSET_B_ADDR,  ((uint32_t)ss_offset << 16) |((uint32_t)ant_offset << 0));
}

__INLINE void smu_ru_2_wr_offset_b_unpack(uint16_t* ss_offset, uint16_t* ant_offset)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_2_WR_OFFSET_B_ADDR);

	*ss_offset = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*ant_offset = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t smu_ru_2_wr_offset_b_ss_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_2_WR_OFFSET_B_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void smu_ru_2_wr_offset_b_ss_offset_setf(uint16_t ssoffset)
{
	ASSERT_ERR((((uint32_t)ssoffset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SMU_RU_2_WR_OFFSET_B_ADDR, (REG_PL_RD(SMU_RU_2_WR_OFFSET_B_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)ssoffset <<16));
}
__INLINE uint16_t smu_ru_2_wr_offset_b_ant_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_2_WR_OFFSET_B_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void smu_ru_2_wr_offset_b_ant_offset_setf(uint16_t antoffset)
{
	ASSERT_ERR((((uint32_t)antoffset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_2_WR_OFFSET_B_ADDR, (REG_PL_RD(SMU_RU_2_WR_OFFSET_B_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)antoffset <<0));
}

/**
 * @brief RU_3_CFG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26:24 STARTING_STS              0x0
 *    21:16 RU_INDEX                  0x0
 *    14:12 RU_TYPE                   0x0
 *    11    SMOOTH_FILTER_EN          0              
 *    10    PILOT_AV_EN               0              
 *    09:08 OUTPUT_DECIMATION         0x0
 *    07:06 NB_SC_SW_A                0x0
 *    05:04 GROUPING                  0x0
 *    03:00 NSS                       0x0
 * </pre>
 */
#define SMU_RU_3_CFG_ADDR        (REG_SMU_BASE_ADDR+0x00000160)
#define SMU_RU_3_CFG_OFFSET      0x00000160
#define SMU_RU_3_CFG_INDEX       0x00000058
#define SMU_RU_3_CFG_RESET       0x00000000

__INLINE uint32_t  smu_ru_3_cfg_get(void)
{
	return REG_PL_RD(SMU_RU_3_CFG_ADDR);
}

__INLINE void smu_ru_3_cfg_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_3_CFG_ADDR, value);
}

// field definitions
#define SMU_RU_3_CFG_STARTING_STS_MASK      ((uint32_t)0x07000000)
#define SMU_RU_3_CFG_STARTING_STS_LSB       24
#define SMU_RU_3_CFG_STARTING_STS_WIDTH     ((uint32_t)0x00000003)
#define SMU_RU_3_CFG_RU_INDEX_MASK          ((uint32_t)0x003F0000)
#define SMU_RU_3_CFG_RU_INDEX_LSB           16
#define SMU_RU_3_CFG_RU_INDEX_WIDTH         ((uint32_t)0x00000006)
#define SMU_RU_3_CFG_RU_TYPE_MASK           ((uint32_t)0x00007000)
#define SMU_RU_3_CFG_RU_TYPE_LSB            12
#define SMU_RU_3_CFG_RU_TYPE_WIDTH          ((uint32_t)0x00000003)
#define SMU_RU_3_CFG_SMOOTH_FILTER_EN_BIT    ((uint32_t)0x00000800)
#define SMU_RU_3_CFG_SMOOTH_FILTER_EN_POS    11
#define SMU_RU_3_CFG_PILOT_AV_EN_BIT        ((uint32_t)0x00000400)
#define SMU_RU_3_CFG_PILOT_AV_EN_POS        10
#define SMU_RU_3_CFG_OUTPUT_DECIMATION_MASK    ((uint32_t)0x00000300)
#define SMU_RU_3_CFG_OUTPUT_DECIMATION_LSB    8
#define SMU_RU_3_CFG_OUTPUT_DECIMATION_WIDTH    ((uint32_t)0x00000002)
#define SMU_RU_3_CFG_NB_SC_SW_A_MASK        ((uint32_t)0x000000C0)
#define SMU_RU_3_CFG_NB_SC_SW_A_LSB         6
#define SMU_RU_3_CFG_NB_SC_SW_A_WIDTH       ((uint32_t)0x00000002)
#define SMU_RU_3_CFG_GROUPING_MASK          ((uint32_t)0x00000030)
#define SMU_RU_3_CFG_GROUPING_LSB           4
#define SMU_RU_3_CFG_GROUPING_WIDTH         ((uint32_t)0x00000002)
#define SMU_RU_3_CFG_NSS_MASK               ((uint32_t)0x0000000F)
#define SMU_RU_3_CFG_NSS_LSB                0
#define SMU_RU_3_CFG_NSS_WIDTH              ((uint32_t)0x00000004)

#define SMU_RU_3_CFG_STARTING_STS_RST       0x0
#define SMU_RU_3_CFG_RU_INDEX_RST           0x0
#define SMU_RU_3_CFG_RU_TYPE_RST            0x0
#define SMU_RU_3_CFG_SMOOTH_FILTER_EN_RST    0x0
#define SMU_RU_3_CFG_PILOT_AV_EN_RST        0x0
#define SMU_RU_3_CFG_OUTPUT_DECIMATION_RST    0x0
#define SMU_RU_3_CFG_NB_SC_SW_A_RST         0x0
#define SMU_RU_3_CFG_GROUPING_RST           0x0
#define SMU_RU_3_CFG_NSS_RST                0x0

__INLINE void smu_ru_3_cfg_pack(uint8_t starting_sts, uint8_t ru_index, uint8_t ru_type, uint8_t smooth_filter_en, uint8_t pilot_av_en, uint8_t output_decimation, uint8_t nb_sc_sw_a, uint8_t grouping, uint8_t nss)
{
	ASSERT_ERR((((uint32_t)starting_sts << 24) & ~((uint32_t)0x07000000)) == 0);
	ASSERT_ERR((((uint32_t)ru_index << 16) & ~((uint32_t)0x003F0000)) == 0);
	ASSERT_ERR((((uint32_t)ru_type << 12) & ~((uint32_t)0x00007000)) == 0);
	ASSERT_ERR((((uint32_t)smooth_filter_en << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)pilot_av_en << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)output_decimation << 8) & ~((uint32_t)0x00000300)) == 0);
	ASSERT_ERR((((uint32_t)nb_sc_sw_a << 6) & ~((uint32_t)0x000000C0)) == 0);
	ASSERT_ERR((((uint32_t)grouping << 4) & ~((uint32_t)0x00000030)) == 0);
	ASSERT_ERR((((uint32_t)nss << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(SMU_RU_3_CFG_ADDR,  ((uint32_t)starting_sts << 24) |((uint32_t)ru_index << 16) |((uint32_t)ru_type << 12) |((uint32_t)smooth_filter_en << 11) |((uint32_t)pilot_av_en << 10) |((uint32_t)output_decimation << 8) |((uint32_t)nb_sc_sw_a << 6) |((uint32_t)grouping << 4) |((uint32_t)nss << 0));
}

__INLINE void smu_ru_3_cfg_unpack(uint8_t* starting_sts, uint8_t* ru_index, uint8_t* ru_type, uint8_t* smooth_filter_en, uint8_t* pilot_av_en, uint8_t* output_decimation, uint8_t* nb_sc_sw_a, uint8_t* grouping, uint8_t* nss)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_3_CFG_ADDR);

	*starting_sts = (localVal & ((uint32_t)0x07000000)) >>  24;
	*ru_index = (localVal & ((uint32_t)0x003F0000)) >>  16;
	*ru_type = (localVal & ((uint32_t)0x00007000)) >>  12;
	*smooth_filter_en = (localVal & ((uint32_t)0x00000800)) >>  11;
	*pilot_av_en = (localVal & ((uint32_t)0x00000400)) >>  10;
	*output_decimation = (localVal & ((uint32_t)0x00000300)) >>  8;
	*nb_sc_sw_a = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*grouping = (localVal & ((uint32_t)0x00000030)) >>  4;
	*nss = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t smu_ru_3_cfg_starting_sts_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_3_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE void smu_ru_3_cfg_starting_sts_setf(uint8_t startingsts)
{
	ASSERT_ERR((((uint32_t)startingsts << 24) & ~((uint32_t)0x07000000)) == 0);
	REG_PL_WR(SMU_RU_3_CFG_ADDR, (REG_PL_RD(SMU_RU_3_CFG_ADDR) & ~((uint32_t)0x07000000)) | ((uint32_t)startingsts <<24));
}
__INLINE uint8_t smu_ru_3_cfg_ru_index_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_3_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x003F0000)) >> 16);
}
__INLINE void smu_ru_3_cfg_ru_index_setf(uint8_t ruindex)
{
	ASSERT_ERR((((uint32_t)ruindex << 16) & ~((uint32_t)0x003F0000)) == 0);
	REG_PL_WR(SMU_RU_3_CFG_ADDR, (REG_PL_RD(SMU_RU_3_CFG_ADDR) & ~((uint32_t)0x003F0000)) | ((uint32_t)ruindex <<16));
}
__INLINE uint8_t smu_ru_3_cfg_ru_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_3_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007000)) >> 12);
}
__INLINE void smu_ru_3_cfg_ru_type_setf(uint8_t rutype)
{
	ASSERT_ERR((((uint32_t)rutype << 12) & ~((uint32_t)0x00007000)) == 0);
	REG_PL_WR(SMU_RU_3_CFG_ADDR, (REG_PL_RD(SMU_RU_3_CFG_ADDR) & ~((uint32_t)0x00007000)) | ((uint32_t)rutype <<12));
}
__INLINE uint8_t smu_ru_3_cfg_smooth_filter_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_3_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void smu_ru_3_cfg_smooth_filter_en_setf(uint8_t smoothfilteren)
{
	ASSERT_ERR((((uint32_t)smoothfilteren << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(SMU_RU_3_CFG_ADDR, (REG_PL_RD(SMU_RU_3_CFG_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)smoothfilteren <<11));
}
__INLINE uint8_t smu_ru_3_cfg_pilot_av_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_3_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void smu_ru_3_cfg_pilot_av_en_setf(uint8_t pilotaven)
{
	ASSERT_ERR((((uint32_t)pilotaven << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(SMU_RU_3_CFG_ADDR, (REG_PL_RD(SMU_RU_3_CFG_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)pilotaven <<10));
}
__INLINE uint8_t smu_ru_3_cfg_output_decimation_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_3_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000300)) >> 8);
}
__INLINE void smu_ru_3_cfg_output_decimation_setf(uint8_t outputdecimation)
{
	ASSERT_ERR((((uint32_t)outputdecimation << 8) & ~((uint32_t)0x00000300)) == 0);
	REG_PL_WR(SMU_RU_3_CFG_ADDR, (REG_PL_RD(SMU_RU_3_CFG_ADDR) & ~((uint32_t)0x00000300)) | ((uint32_t)outputdecimation <<8));
}
__INLINE uint8_t smu_ru_3_cfg_nb_sc_sw_a_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_3_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE void smu_ru_3_cfg_nb_sc_sw_a_setf(uint8_t nbscswa)
{
	ASSERT_ERR((((uint32_t)nbscswa << 6) & ~((uint32_t)0x000000C0)) == 0);
	REG_PL_WR(SMU_RU_3_CFG_ADDR, (REG_PL_RD(SMU_RU_3_CFG_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)nbscswa <<6));
}
__INLINE uint8_t smu_ru_3_cfg_grouping_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_3_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000030)) >> 4);
}
__INLINE void smu_ru_3_cfg_grouping_setf(uint8_t grouping)
{
	ASSERT_ERR((((uint32_t)grouping << 4) & ~((uint32_t)0x00000030)) == 0);
	REG_PL_WR(SMU_RU_3_CFG_ADDR, (REG_PL_RD(SMU_RU_3_CFG_ADDR) & ~((uint32_t)0x00000030)) | ((uint32_t)grouping <<4));
}
__INLINE uint8_t smu_ru_3_cfg_nss_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_3_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void smu_ru_3_cfg_nss_setf(uint8_t nss)
{
	ASSERT_ERR((((uint32_t)nss << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(SMU_RU_3_CFG_ADDR, (REG_PL_RD(SMU_RU_3_CFG_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)nss <<0));
}

/**
 * @brief RU_3_FILTER_PTR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 FILTER_PTR                0x0
 * </pre>
 */
#define SMU_RU_3_FILTER_PTR_ADDR        (REG_SMU_BASE_ADDR+0x00000164)
#define SMU_RU_3_FILTER_PTR_OFFSET      0x00000164
#define SMU_RU_3_FILTER_PTR_INDEX       0x00000059
#define SMU_RU_3_FILTER_PTR_RESET       0x00000000

__INLINE uint32_t  smu_ru_3_filter_ptr_get(void)
{
	return REG_PL_RD(SMU_RU_3_FILTER_PTR_ADDR);
}

__INLINE void smu_ru_3_filter_ptr_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_3_FILTER_PTR_ADDR, value);
}

// field definitions
#define SMU_RU_3_FILTER_PTR_FILTER_PTR_MASK    ((uint32_t)0xFFFFFFFF)
#define SMU_RU_3_FILTER_PTR_FILTER_PTR_LSB    0
#define SMU_RU_3_FILTER_PTR_FILTER_PTR_WIDTH    ((uint32_t)0x00000020)

#define SMU_RU_3_FILTER_PTR_FILTER_PTR_RST    0x0

__INLINE uint32_t smu_ru_3_filter_ptr_filter_ptr_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_3_FILTER_PTR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void smu_ru_3_filter_ptr_filter_ptr_setf(uint32_t filterptr)
{
	ASSERT_ERR((((uint32_t)filterptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SMU_RU_3_FILTER_PTR_ADDR, (uint32_t)filterptr << 0);
}

/**
 * @brief RU_3_DATA_RD_PTR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DATA_RD_PTR               0x0
 * </pre>
 */
#define SMU_RU_3_DATA_RD_PTR_ADDR        (REG_SMU_BASE_ADDR+0x00000168)
#define SMU_RU_3_DATA_RD_PTR_OFFSET      0x00000168
#define SMU_RU_3_DATA_RD_PTR_INDEX       0x0000005A
#define SMU_RU_3_DATA_RD_PTR_RESET       0x00000000

__INLINE uint32_t  smu_ru_3_data_rd_ptr_get(void)
{
	return REG_PL_RD(SMU_RU_3_DATA_RD_PTR_ADDR);
}

__INLINE void smu_ru_3_data_rd_ptr_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_3_DATA_RD_PTR_ADDR, value);
}

// field definitions
#define SMU_RU_3_DATA_RD_PTR_DATA_RD_PTR_MASK    ((uint32_t)0xFFFFFFFF)
#define SMU_RU_3_DATA_RD_PTR_DATA_RD_PTR_LSB    0
#define SMU_RU_3_DATA_RD_PTR_DATA_RD_PTR_WIDTH    ((uint32_t)0x00000020)

#define SMU_RU_3_DATA_RD_PTR_DATA_RD_PTR_RST    0x0

__INLINE uint32_t smu_ru_3_data_rd_ptr_data_rd_ptr_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_3_DATA_RD_PTR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void smu_ru_3_data_rd_ptr_data_rd_ptr_setf(uint32_t datardptr)
{
	ASSERT_ERR((((uint32_t)datardptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SMU_RU_3_DATA_RD_PTR_ADDR, (uint32_t)datardptr << 0);
}

/**
 * @brief RU_3_RD_OFFSET register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SS_OFFSET                 0x0
 *    15:00 ANT_OFFSET                0x0
 * </pre>
 */
#define SMU_RU_3_RD_OFFSET_ADDR        (REG_SMU_BASE_ADDR+0x0000016C)
#define SMU_RU_3_RD_OFFSET_OFFSET      0x0000016C
#define SMU_RU_3_RD_OFFSET_INDEX       0x0000005B
#define SMU_RU_3_RD_OFFSET_RESET       0x00000000

__INLINE uint32_t  smu_ru_3_rd_offset_get(void)
{
	return REG_PL_RD(SMU_RU_3_RD_OFFSET_ADDR);
}

__INLINE void smu_ru_3_rd_offset_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_3_RD_OFFSET_ADDR, value);
}

// field definitions
#define SMU_RU_3_RD_OFFSET_SS_OFFSET_MASK    ((uint32_t)0xFFFF0000)
#define SMU_RU_3_RD_OFFSET_SS_OFFSET_LSB    16
#define SMU_RU_3_RD_OFFSET_SS_OFFSET_WIDTH    ((uint32_t)0x00000010)
#define SMU_RU_3_RD_OFFSET_ANT_OFFSET_MASK    ((uint32_t)0x0000FFFF)
#define SMU_RU_3_RD_OFFSET_ANT_OFFSET_LSB    0
#define SMU_RU_3_RD_OFFSET_ANT_OFFSET_WIDTH    ((uint32_t)0x00000010)

#define SMU_RU_3_RD_OFFSET_SS_OFFSET_RST    0x0
#define SMU_RU_3_RD_OFFSET_ANT_OFFSET_RST    0x0

__INLINE void smu_ru_3_rd_offset_pack(uint16_t ss_offset, uint16_t ant_offset)
{
	ASSERT_ERR((((uint32_t)ss_offset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)ant_offset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_3_RD_OFFSET_ADDR,  ((uint32_t)ss_offset << 16) |((uint32_t)ant_offset << 0));
}

__INLINE void smu_ru_3_rd_offset_unpack(uint16_t* ss_offset, uint16_t* ant_offset)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_3_RD_OFFSET_ADDR);

	*ss_offset = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*ant_offset = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t smu_ru_3_rd_offset_ss_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_3_RD_OFFSET_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void smu_ru_3_rd_offset_ss_offset_setf(uint16_t ssoffset)
{
	ASSERT_ERR((((uint32_t)ssoffset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SMU_RU_3_RD_OFFSET_ADDR, (REG_PL_RD(SMU_RU_3_RD_OFFSET_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)ssoffset <<16));
}
__INLINE uint16_t smu_ru_3_rd_offset_ant_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_3_RD_OFFSET_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void smu_ru_3_rd_offset_ant_offset_setf(uint16_t antoffset)
{
	ASSERT_ERR((((uint32_t)antoffset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_3_RD_OFFSET_ADDR, (REG_PL_RD(SMU_RU_3_RD_OFFSET_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)antoffset <<0));
}

/**
 * @brief RU_3_DATA_WR_PTR_A register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DATA_WR_PTR_A             0x0
 * </pre>
 */
#define SMU_RU_3_DATA_WR_PTR_A_ADDR        (REG_SMU_BASE_ADDR+0x00000170)
#define SMU_RU_3_DATA_WR_PTR_A_OFFSET      0x00000170
#define SMU_RU_3_DATA_WR_PTR_A_INDEX       0x0000005C
#define SMU_RU_3_DATA_WR_PTR_A_RESET       0x00000000

__INLINE uint32_t  smu_ru_3_data_wr_ptr_a_get(void)
{
	return REG_PL_RD(SMU_RU_3_DATA_WR_PTR_A_ADDR);
}

__INLINE void smu_ru_3_data_wr_ptr_a_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_3_DATA_WR_PTR_A_ADDR, value);
}

// field definitions
#define SMU_RU_3_DATA_WR_PTR_A_DATA_WR_PTR_A_MASK    ((uint32_t)0xFFFFFFFF)
#define SMU_RU_3_DATA_WR_PTR_A_DATA_WR_PTR_A_LSB    0
#define SMU_RU_3_DATA_WR_PTR_A_DATA_WR_PTR_A_WIDTH    ((uint32_t)0x00000020)

#define SMU_RU_3_DATA_WR_PTR_A_DATA_WR_PTR_A_RST    0x0

__INLINE uint32_t smu_ru_3_data_wr_ptr_a_data_wr_ptr_a_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_3_DATA_WR_PTR_A_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void smu_ru_3_data_wr_ptr_a_data_wr_ptr_a_setf(uint32_t datawrptra)
{
	ASSERT_ERR((((uint32_t)datawrptra << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SMU_RU_3_DATA_WR_PTR_A_ADDR, (uint32_t)datawrptra << 0);
}

/**
 * @brief RU_3_DATA_WR_PTR_B register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DATA_WR_PTR_B             0x0
 * </pre>
 */
#define SMU_RU_3_DATA_WR_PTR_B_ADDR        (REG_SMU_BASE_ADDR+0x00000174)
#define SMU_RU_3_DATA_WR_PTR_B_OFFSET      0x00000174
#define SMU_RU_3_DATA_WR_PTR_B_INDEX       0x0000005D
#define SMU_RU_3_DATA_WR_PTR_B_RESET       0x00000000

__INLINE uint32_t  smu_ru_3_data_wr_ptr_b_get(void)
{
	return REG_PL_RD(SMU_RU_3_DATA_WR_PTR_B_ADDR);
}

__INLINE void smu_ru_3_data_wr_ptr_b_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_3_DATA_WR_PTR_B_ADDR, value);
}

// field definitions
#define SMU_RU_3_DATA_WR_PTR_B_DATA_WR_PTR_B_MASK    ((uint32_t)0xFFFFFFFF)
#define SMU_RU_3_DATA_WR_PTR_B_DATA_WR_PTR_B_LSB    0
#define SMU_RU_3_DATA_WR_PTR_B_DATA_WR_PTR_B_WIDTH    ((uint32_t)0x00000020)

#define SMU_RU_3_DATA_WR_PTR_B_DATA_WR_PTR_B_RST    0x0

__INLINE uint32_t smu_ru_3_data_wr_ptr_b_data_wr_ptr_b_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_3_DATA_WR_PTR_B_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void smu_ru_3_data_wr_ptr_b_data_wr_ptr_b_setf(uint32_t datawrptrb)
{
	ASSERT_ERR((((uint32_t)datawrptrb << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SMU_RU_3_DATA_WR_PTR_B_ADDR, (uint32_t)datawrptrb << 0);
}

/**
 * @brief RU_3_WR_OFFSET_A register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SS_OFFSET                 0x0
 *    15:00 ANT_OFFSET                0x0
 * </pre>
 */
#define SMU_RU_3_WR_OFFSET_A_ADDR        (REG_SMU_BASE_ADDR+0x00000178)
#define SMU_RU_3_WR_OFFSET_A_OFFSET      0x00000178
#define SMU_RU_3_WR_OFFSET_A_INDEX       0x0000005E
#define SMU_RU_3_WR_OFFSET_A_RESET       0x00000000

__INLINE uint32_t  smu_ru_3_wr_offset_a_get(void)
{
	return REG_PL_RD(SMU_RU_3_WR_OFFSET_A_ADDR);
}

__INLINE void smu_ru_3_wr_offset_a_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_3_WR_OFFSET_A_ADDR, value);
}

// field definitions
#define SMU_RU_3_WR_OFFSET_A_SS_OFFSET_MASK    ((uint32_t)0xFFFF0000)
#define SMU_RU_3_WR_OFFSET_A_SS_OFFSET_LSB    16
#define SMU_RU_3_WR_OFFSET_A_SS_OFFSET_WIDTH    ((uint32_t)0x00000010)
#define SMU_RU_3_WR_OFFSET_A_ANT_OFFSET_MASK    ((uint32_t)0x0000FFFF)
#define SMU_RU_3_WR_OFFSET_A_ANT_OFFSET_LSB    0
#define SMU_RU_3_WR_OFFSET_A_ANT_OFFSET_WIDTH    ((uint32_t)0x00000010)

#define SMU_RU_3_WR_OFFSET_A_SS_OFFSET_RST    0x0
#define SMU_RU_3_WR_OFFSET_A_ANT_OFFSET_RST    0x0

__INLINE void smu_ru_3_wr_offset_a_pack(uint16_t ss_offset, uint16_t ant_offset)
{
	ASSERT_ERR((((uint32_t)ss_offset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)ant_offset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_3_WR_OFFSET_A_ADDR,  ((uint32_t)ss_offset << 16) |((uint32_t)ant_offset << 0));
}

__INLINE void smu_ru_3_wr_offset_a_unpack(uint16_t* ss_offset, uint16_t* ant_offset)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_3_WR_OFFSET_A_ADDR);

	*ss_offset = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*ant_offset = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t smu_ru_3_wr_offset_a_ss_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_3_WR_OFFSET_A_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void smu_ru_3_wr_offset_a_ss_offset_setf(uint16_t ssoffset)
{
	ASSERT_ERR((((uint32_t)ssoffset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SMU_RU_3_WR_OFFSET_A_ADDR, (REG_PL_RD(SMU_RU_3_WR_OFFSET_A_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)ssoffset <<16));
}
__INLINE uint16_t smu_ru_3_wr_offset_a_ant_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_3_WR_OFFSET_A_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void smu_ru_3_wr_offset_a_ant_offset_setf(uint16_t antoffset)
{
	ASSERT_ERR((((uint32_t)antoffset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_3_WR_OFFSET_A_ADDR, (REG_PL_RD(SMU_RU_3_WR_OFFSET_A_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)antoffset <<0));
}

/**
 * @brief RU_3_WR_OFFSET_B register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SS_OFFSET                 0x0
 *    15:00 ANT_OFFSET                0x0
 * </pre>
 */
#define SMU_RU_3_WR_OFFSET_B_ADDR        (REG_SMU_BASE_ADDR+0x0000017C)
#define SMU_RU_3_WR_OFFSET_B_OFFSET      0x0000017C
#define SMU_RU_3_WR_OFFSET_B_INDEX       0x0000005F
#define SMU_RU_3_WR_OFFSET_B_RESET       0x00000000

__INLINE uint32_t  smu_ru_3_wr_offset_b_get(void)
{
	return REG_PL_RD(SMU_RU_3_WR_OFFSET_B_ADDR);
}

__INLINE void smu_ru_3_wr_offset_b_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_3_WR_OFFSET_B_ADDR, value);
}

// field definitions
#define SMU_RU_3_WR_OFFSET_B_SS_OFFSET_MASK    ((uint32_t)0xFFFF0000)
#define SMU_RU_3_WR_OFFSET_B_SS_OFFSET_LSB    16
#define SMU_RU_3_WR_OFFSET_B_SS_OFFSET_WIDTH    ((uint32_t)0x00000010)
#define SMU_RU_3_WR_OFFSET_B_ANT_OFFSET_MASK    ((uint32_t)0x0000FFFF)
#define SMU_RU_3_WR_OFFSET_B_ANT_OFFSET_LSB    0
#define SMU_RU_3_WR_OFFSET_B_ANT_OFFSET_WIDTH    ((uint32_t)0x00000010)

#define SMU_RU_3_WR_OFFSET_B_SS_OFFSET_RST    0x0
#define SMU_RU_3_WR_OFFSET_B_ANT_OFFSET_RST    0x0

__INLINE void smu_ru_3_wr_offset_b_pack(uint16_t ss_offset, uint16_t ant_offset)
{
	ASSERT_ERR((((uint32_t)ss_offset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)ant_offset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_3_WR_OFFSET_B_ADDR,  ((uint32_t)ss_offset << 16) |((uint32_t)ant_offset << 0));
}

__INLINE void smu_ru_3_wr_offset_b_unpack(uint16_t* ss_offset, uint16_t* ant_offset)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_3_WR_OFFSET_B_ADDR);

	*ss_offset = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*ant_offset = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t smu_ru_3_wr_offset_b_ss_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_3_WR_OFFSET_B_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void smu_ru_3_wr_offset_b_ss_offset_setf(uint16_t ssoffset)
{
	ASSERT_ERR((((uint32_t)ssoffset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SMU_RU_3_WR_OFFSET_B_ADDR, (REG_PL_RD(SMU_RU_3_WR_OFFSET_B_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)ssoffset <<16));
}
__INLINE uint16_t smu_ru_3_wr_offset_b_ant_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_3_WR_OFFSET_B_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void smu_ru_3_wr_offset_b_ant_offset_setf(uint16_t antoffset)
{
	ASSERT_ERR((((uint32_t)antoffset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_3_WR_OFFSET_B_ADDR, (REG_PL_RD(SMU_RU_3_WR_OFFSET_B_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)antoffset <<0));
}

/**
 * @brief RU_4_CFG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26:24 STARTING_STS              0x0
 *    21:16 RU_INDEX                  0x0
 *    14:12 RU_TYPE                   0x0
 *    11    SMOOTH_FILTER_EN          0              
 *    10    PILOT_AV_EN               0              
 *    09:08 OUTPUT_DECIMATION         0x0
 *    07:06 NB_SC_SW_A                0x0
 *    05:04 GROUPING                  0x0
 *    03:00 NSS                       0x0
 * </pre>
 */
#define SMU_RU_4_CFG_ADDR        (REG_SMU_BASE_ADDR+0x00000180)
#define SMU_RU_4_CFG_OFFSET      0x00000180
#define SMU_RU_4_CFG_INDEX       0x00000060
#define SMU_RU_4_CFG_RESET       0x00000000

__INLINE uint32_t  smu_ru_4_cfg_get(void)
{
	return REG_PL_RD(SMU_RU_4_CFG_ADDR);
}

__INLINE void smu_ru_4_cfg_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_4_CFG_ADDR, value);
}

// field definitions
#define SMU_RU_4_CFG_STARTING_STS_MASK      ((uint32_t)0x07000000)
#define SMU_RU_4_CFG_STARTING_STS_LSB       24
#define SMU_RU_4_CFG_STARTING_STS_WIDTH     ((uint32_t)0x00000003)
#define SMU_RU_4_CFG_RU_INDEX_MASK          ((uint32_t)0x003F0000)
#define SMU_RU_4_CFG_RU_INDEX_LSB           16
#define SMU_RU_4_CFG_RU_INDEX_WIDTH         ((uint32_t)0x00000006)
#define SMU_RU_4_CFG_RU_TYPE_MASK           ((uint32_t)0x00007000)
#define SMU_RU_4_CFG_RU_TYPE_LSB            12
#define SMU_RU_4_CFG_RU_TYPE_WIDTH          ((uint32_t)0x00000003)
#define SMU_RU_4_CFG_SMOOTH_FILTER_EN_BIT    ((uint32_t)0x00000800)
#define SMU_RU_4_CFG_SMOOTH_FILTER_EN_POS    11
#define SMU_RU_4_CFG_PILOT_AV_EN_BIT        ((uint32_t)0x00000400)
#define SMU_RU_4_CFG_PILOT_AV_EN_POS        10
#define SMU_RU_4_CFG_OUTPUT_DECIMATION_MASK    ((uint32_t)0x00000300)
#define SMU_RU_4_CFG_OUTPUT_DECIMATION_LSB    8
#define SMU_RU_4_CFG_OUTPUT_DECIMATION_WIDTH    ((uint32_t)0x00000002)
#define SMU_RU_4_CFG_NB_SC_SW_A_MASK        ((uint32_t)0x000000C0)
#define SMU_RU_4_CFG_NB_SC_SW_A_LSB         6
#define SMU_RU_4_CFG_NB_SC_SW_A_WIDTH       ((uint32_t)0x00000002)
#define SMU_RU_4_CFG_GROUPING_MASK          ((uint32_t)0x00000030)
#define SMU_RU_4_CFG_GROUPING_LSB           4
#define SMU_RU_4_CFG_GROUPING_WIDTH         ((uint32_t)0x00000002)
#define SMU_RU_4_CFG_NSS_MASK               ((uint32_t)0x0000000F)
#define SMU_RU_4_CFG_NSS_LSB                0
#define SMU_RU_4_CFG_NSS_WIDTH              ((uint32_t)0x00000004)

#define SMU_RU_4_CFG_STARTING_STS_RST       0x0
#define SMU_RU_4_CFG_RU_INDEX_RST           0x0
#define SMU_RU_4_CFG_RU_TYPE_RST            0x0
#define SMU_RU_4_CFG_SMOOTH_FILTER_EN_RST    0x0
#define SMU_RU_4_CFG_PILOT_AV_EN_RST        0x0
#define SMU_RU_4_CFG_OUTPUT_DECIMATION_RST    0x0
#define SMU_RU_4_CFG_NB_SC_SW_A_RST         0x0
#define SMU_RU_4_CFG_GROUPING_RST           0x0
#define SMU_RU_4_CFG_NSS_RST                0x0

__INLINE void smu_ru_4_cfg_pack(uint8_t starting_sts, uint8_t ru_index, uint8_t ru_type, uint8_t smooth_filter_en, uint8_t pilot_av_en, uint8_t output_decimation, uint8_t nb_sc_sw_a, uint8_t grouping, uint8_t nss)
{
	ASSERT_ERR((((uint32_t)starting_sts << 24) & ~((uint32_t)0x07000000)) == 0);
	ASSERT_ERR((((uint32_t)ru_index << 16) & ~((uint32_t)0x003F0000)) == 0);
	ASSERT_ERR((((uint32_t)ru_type << 12) & ~((uint32_t)0x00007000)) == 0);
	ASSERT_ERR((((uint32_t)smooth_filter_en << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)pilot_av_en << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)output_decimation << 8) & ~((uint32_t)0x00000300)) == 0);
	ASSERT_ERR((((uint32_t)nb_sc_sw_a << 6) & ~((uint32_t)0x000000C0)) == 0);
	ASSERT_ERR((((uint32_t)grouping << 4) & ~((uint32_t)0x00000030)) == 0);
	ASSERT_ERR((((uint32_t)nss << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(SMU_RU_4_CFG_ADDR,  ((uint32_t)starting_sts << 24) |((uint32_t)ru_index << 16) |((uint32_t)ru_type << 12) |((uint32_t)smooth_filter_en << 11) |((uint32_t)pilot_av_en << 10) |((uint32_t)output_decimation << 8) |((uint32_t)nb_sc_sw_a << 6) |((uint32_t)grouping << 4) |((uint32_t)nss << 0));
}

__INLINE void smu_ru_4_cfg_unpack(uint8_t* starting_sts, uint8_t* ru_index, uint8_t* ru_type, uint8_t* smooth_filter_en, uint8_t* pilot_av_en, uint8_t* output_decimation, uint8_t* nb_sc_sw_a, uint8_t* grouping, uint8_t* nss)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_4_CFG_ADDR);

	*starting_sts = (localVal & ((uint32_t)0x07000000)) >>  24;
	*ru_index = (localVal & ((uint32_t)0x003F0000)) >>  16;
	*ru_type = (localVal & ((uint32_t)0x00007000)) >>  12;
	*smooth_filter_en = (localVal & ((uint32_t)0x00000800)) >>  11;
	*pilot_av_en = (localVal & ((uint32_t)0x00000400)) >>  10;
	*output_decimation = (localVal & ((uint32_t)0x00000300)) >>  8;
	*nb_sc_sw_a = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*grouping = (localVal & ((uint32_t)0x00000030)) >>  4;
	*nss = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t smu_ru_4_cfg_starting_sts_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_4_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE void smu_ru_4_cfg_starting_sts_setf(uint8_t startingsts)
{
	ASSERT_ERR((((uint32_t)startingsts << 24) & ~((uint32_t)0x07000000)) == 0);
	REG_PL_WR(SMU_RU_4_CFG_ADDR, (REG_PL_RD(SMU_RU_4_CFG_ADDR) & ~((uint32_t)0x07000000)) | ((uint32_t)startingsts <<24));
}
__INLINE uint8_t smu_ru_4_cfg_ru_index_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_4_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x003F0000)) >> 16);
}
__INLINE void smu_ru_4_cfg_ru_index_setf(uint8_t ruindex)
{
	ASSERT_ERR((((uint32_t)ruindex << 16) & ~((uint32_t)0x003F0000)) == 0);
	REG_PL_WR(SMU_RU_4_CFG_ADDR, (REG_PL_RD(SMU_RU_4_CFG_ADDR) & ~((uint32_t)0x003F0000)) | ((uint32_t)ruindex <<16));
}
__INLINE uint8_t smu_ru_4_cfg_ru_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_4_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007000)) >> 12);
}
__INLINE void smu_ru_4_cfg_ru_type_setf(uint8_t rutype)
{
	ASSERT_ERR((((uint32_t)rutype << 12) & ~((uint32_t)0x00007000)) == 0);
	REG_PL_WR(SMU_RU_4_CFG_ADDR, (REG_PL_RD(SMU_RU_4_CFG_ADDR) & ~((uint32_t)0x00007000)) | ((uint32_t)rutype <<12));
}
__INLINE uint8_t smu_ru_4_cfg_smooth_filter_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_4_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void smu_ru_4_cfg_smooth_filter_en_setf(uint8_t smoothfilteren)
{
	ASSERT_ERR((((uint32_t)smoothfilteren << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(SMU_RU_4_CFG_ADDR, (REG_PL_RD(SMU_RU_4_CFG_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)smoothfilteren <<11));
}
__INLINE uint8_t smu_ru_4_cfg_pilot_av_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_4_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void smu_ru_4_cfg_pilot_av_en_setf(uint8_t pilotaven)
{
	ASSERT_ERR((((uint32_t)pilotaven << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(SMU_RU_4_CFG_ADDR, (REG_PL_RD(SMU_RU_4_CFG_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)pilotaven <<10));
}
__INLINE uint8_t smu_ru_4_cfg_output_decimation_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_4_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000300)) >> 8);
}
__INLINE void smu_ru_4_cfg_output_decimation_setf(uint8_t outputdecimation)
{
	ASSERT_ERR((((uint32_t)outputdecimation << 8) & ~((uint32_t)0x00000300)) == 0);
	REG_PL_WR(SMU_RU_4_CFG_ADDR, (REG_PL_RD(SMU_RU_4_CFG_ADDR) & ~((uint32_t)0x00000300)) | ((uint32_t)outputdecimation <<8));
}
__INLINE uint8_t smu_ru_4_cfg_nb_sc_sw_a_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_4_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE void smu_ru_4_cfg_nb_sc_sw_a_setf(uint8_t nbscswa)
{
	ASSERT_ERR((((uint32_t)nbscswa << 6) & ~((uint32_t)0x000000C0)) == 0);
	REG_PL_WR(SMU_RU_4_CFG_ADDR, (REG_PL_RD(SMU_RU_4_CFG_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)nbscswa <<6));
}
__INLINE uint8_t smu_ru_4_cfg_grouping_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_4_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000030)) >> 4);
}
__INLINE void smu_ru_4_cfg_grouping_setf(uint8_t grouping)
{
	ASSERT_ERR((((uint32_t)grouping << 4) & ~((uint32_t)0x00000030)) == 0);
	REG_PL_WR(SMU_RU_4_CFG_ADDR, (REG_PL_RD(SMU_RU_4_CFG_ADDR) & ~((uint32_t)0x00000030)) | ((uint32_t)grouping <<4));
}
__INLINE uint8_t smu_ru_4_cfg_nss_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_4_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void smu_ru_4_cfg_nss_setf(uint8_t nss)
{
	ASSERT_ERR((((uint32_t)nss << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(SMU_RU_4_CFG_ADDR, (REG_PL_RD(SMU_RU_4_CFG_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)nss <<0));
}

/**
 * @brief RU_4_FILTER_PTR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 FILTER_PTR                0x0
 * </pre>
 */
#define SMU_RU_4_FILTER_PTR_ADDR        (REG_SMU_BASE_ADDR+0x00000184)
#define SMU_RU_4_FILTER_PTR_OFFSET      0x00000184
#define SMU_RU_4_FILTER_PTR_INDEX       0x00000061
#define SMU_RU_4_FILTER_PTR_RESET       0x00000000

__INLINE uint32_t  smu_ru_4_filter_ptr_get(void)
{
	return REG_PL_RD(SMU_RU_4_FILTER_PTR_ADDR);
}

__INLINE void smu_ru_4_filter_ptr_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_4_FILTER_PTR_ADDR, value);
}

// field definitions
#define SMU_RU_4_FILTER_PTR_FILTER_PTR_MASK    ((uint32_t)0xFFFFFFFF)
#define SMU_RU_4_FILTER_PTR_FILTER_PTR_LSB    0
#define SMU_RU_4_FILTER_PTR_FILTER_PTR_WIDTH    ((uint32_t)0x00000020)

#define SMU_RU_4_FILTER_PTR_FILTER_PTR_RST    0x0

__INLINE uint32_t smu_ru_4_filter_ptr_filter_ptr_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_4_FILTER_PTR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void smu_ru_4_filter_ptr_filter_ptr_setf(uint32_t filterptr)
{
	ASSERT_ERR((((uint32_t)filterptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SMU_RU_4_FILTER_PTR_ADDR, (uint32_t)filterptr << 0);
}

/**
 * @brief RU_4_DATA_RD_PTR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DATA_RD_PTR               0x0
 * </pre>
 */
#define SMU_RU_4_DATA_RD_PTR_ADDR        (REG_SMU_BASE_ADDR+0x00000188)
#define SMU_RU_4_DATA_RD_PTR_OFFSET      0x00000188
#define SMU_RU_4_DATA_RD_PTR_INDEX       0x00000062
#define SMU_RU_4_DATA_RD_PTR_RESET       0x00000000

__INLINE uint32_t  smu_ru_4_data_rd_ptr_get(void)
{
	return REG_PL_RD(SMU_RU_4_DATA_RD_PTR_ADDR);
}

__INLINE void smu_ru_4_data_rd_ptr_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_4_DATA_RD_PTR_ADDR, value);
}

// field definitions
#define SMU_RU_4_DATA_RD_PTR_DATA_RD_PTR_MASK    ((uint32_t)0xFFFFFFFF)
#define SMU_RU_4_DATA_RD_PTR_DATA_RD_PTR_LSB    0
#define SMU_RU_4_DATA_RD_PTR_DATA_RD_PTR_WIDTH    ((uint32_t)0x00000020)

#define SMU_RU_4_DATA_RD_PTR_DATA_RD_PTR_RST    0x0

__INLINE uint32_t smu_ru_4_data_rd_ptr_data_rd_ptr_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_4_DATA_RD_PTR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void smu_ru_4_data_rd_ptr_data_rd_ptr_setf(uint32_t datardptr)
{
	ASSERT_ERR((((uint32_t)datardptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SMU_RU_4_DATA_RD_PTR_ADDR, (uint32_t)datardptr << 0);
}

/**
 * @brief RU_4_RD_OFFSET register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SS_OFFSET                 0x0
 *    15:00 ANT_OFFSET                0x0
 * </pre>
 */
#define SMU_RU_4_RD_OFFSET_ADDR        (REG_SMU_BASE_ADDR+0x0000018C)
#define SMU_RU_4_RD_OFFSET_OFFSET      0x0000018C
#define SMU_RU_4_RD_OFFSET_INDEX       0x00000063
#define SMU_RU_4_RD_OFFSET_RESET       0x00000000

__INLINE uint32_t  smu_ru_4_rd_offset_get(void)
{
	return REG_PL_RD(SMU_RU_4_RD_OFFSET_ADDR);
}

__INLINE void smu_ru_4_rd_offset_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_4_RD_OFFSET_ADDR, value);
}

// field definitions
#define SMU_RU_4_RD_OFFSET_SS_OFFSET_MASK    ((uint32_t)0xFFFF0000)
#define SMU_RU_4_RD_OFFSET_SS_OFFSET_LSB    16
#define SMU_RU_4_RD_OFFSET_SS_OFFSET_WIDTH    ((uint32_t)0x00000010)
#define SMU_RU_4_RD_OFFSET_ANT_OFFSET_MASK    ((uint32_t)0x0000FFFF)
#define SMU_RU_4_RD_OFFSET_ANT_OFFSET_LSB    0
#define SMU_RU_4_RD_OFFSET_ANT_OFFSET_WIDTH    ((uint32_t)0x00000010)

#define SMU_RU_4_RD_OFFSET_SS_OFFSET_RST    0x0
#define SMU_RU_4_RD_OFFSET_ANT_OFFSET_RST    0x0

__INLINE void smu_ru_4_rd_offset_pack(uint16_t ss_offset, uint16_t ant_offset)
{
	ASSERT_ERR((((uint32_t)ss_offset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)ant_offset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_4_RD_OFFSET_ADDR,  ((uint32_t)ss_offset << 16) |((uint32_t)ant_offset << 0));
}

__INLINE void smu_ru_4_rd_offset_unpack(uint16_t* ss_offset, uint16_t* ant_offset)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_4_RD_OFFSET_ADDR);

	*ss_offset = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*ant_offset = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t smu_ru_4_rd_offset_ss_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_4_RD_OFFSET_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void smu_ru_4_rd_offset_ss_offset_setf(uint16_t ssoffset)
{
	ASSERT_ERR((((uint32_t)ssoffset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SMU_RU_4_RD_OFFSET_ADDR, (REG_PL_RD(SMU_RU_4_RD_OFFSET_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)ssoffset <<16));
}
__INLINE uint16_t smu_ru_4_rd_offset_ant_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_4_RD_OFFSET_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void smu_ru_4_rd_offset_ant_offset_setf(uint16_t antoffset)
{
	ASSERT_ERR((((uint32_t)antoffset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_4_RD_OFFSET_ADDR, (REG_PL_RD(SMU_RU_4_RD_OFFSET_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)antoffset <<0));
}

/**
 * @brief RU_4_DATA_WR_PTR_A register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DATA_WR_PTR_A             0x0
 * </pre>
 */
#define SMU_RU_4_DATA_WR_PTR_A_ADDR        (REG_SMU_BASE_ADDR+0x00000190)
#define SMU_RU_4_DATA_WR_PTR_A_OFFSET      0x00000190
#define SMU_RU_4_DATA_WR_PTR_A_INDEX       0x00000064
#define SMU_RU_4_DATA_WR_PTR_A_RESET       0x00000000

__INLINE uint32_t  smu_ru_4_data_wr_ptr_a_get(void)
{
	return REG_PL_RD(SMU_RU_4_DATA_WR_PTR_A_ADDR);
}

__INLINE void smu_ru_4_data_wr_ptr_a_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_4_DATA_WR_PTR_A_ADDR, value);
}

// field definitions
#define SMU_RU_4_DATA_WR_PTR_A_DATA_WR_PTR_A_MASK    ((uint32_t)0xFFFFFFFF)
#define SMU_RU_4_DATA_WR_PTR_A_DATA_WR_PTR_A_LSB    0
#define SMU_RU_4_DATA_WR_PTR_A_DATA_WR_PTR_A_WIDTH    ((uint32_t)0x00000020)

#define SMU_RU_4_DATA_WR_PTR_A_DATA_WR_PTR_A_RST    0x0

__INLINE uint32_t smu_ru_4_data_wr_ptr_a_data_wr_ptr_a_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_4_DATA_WR_PTR_A_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void smu_ru_4_data_wr_ptr_a_data_wr_ptr_a_setf(uint32_t datawrptra)
{
	ASSERT_ERR((((uint32_t)datawrptra << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SMU_RU_4_DATA_WR_PTR_A_ADDR, (uint32_t)datawrptra << 0);
}

/**
 * @brief RU_4_DATA_WR_PTR_B register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DATA_WR_PTR_B             0x0
 * </pre>
 */
#define SMU_RU_4_DATA_WR_PTR_B_ADDR        (REG_SMU_BASE_ADDR+0x00000194)
#define SMU_RU_4_DATA_WR_PTR_B_OFFSET      0x00000194
#define SMU_RU_4_DATA_WR_PTR_B_INDEX       0x00000065
#define SMU_RU_4_DATA_WR_PTR_B_RESET       0x00000000

__INLINE uint32_t  smu_ru_4_data_wr_ptr_b_get(void)
{
	return REG_PL_RD(SMU_RU_4_DATA_WR_PTR_B_ADDR);
}

__INLINE void smu_ru_4_data_wr_ptr_b_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_4_DATA_WR_PTR_B_ADDR, value);
}

// field definitions
#define SMU_RU_4_DATA_WR_PTR_B_DATA_WR_PTR_B_MASK    ((uint32_t)0xFFFFFFFF)
#define SMU_RU_4_DATA_WR_PTR_B_DATA_WR_PTR_B_LSB    0
#define SMU_RU_4_DATA_WR_PTR_B_DATA_WR_PTR_B_WIDTH    ((uint32_t)0x00000020)

#define SMU_RU_4_DATA_WR_PTR_B_DATA_WR_PTR_B_RST    0x0

__INLINE uint32_t smu_ru_4_data_wr_ptr_b_data_wr_ptr_b_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_4_DATA_WR_PTR_B_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void smu_ru_4_data_wr_ptr_b_data_wr_ptr_b_setf(uint32_t datawrptrb)
{
	ASSERT_ERR((((uint32_t)datawrptrb << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SMU_RU_4_DATA_WR_PTR_B_ADDR, (uint32_t)datawrptrb << 0);
}

/**
 * @brief RU_4_WR_OFFSET_A register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SS_OFFSET                 0x0
 *    15:00 ANT_OFFSET                0x0
 * </pre>
 */
#define SMU_RU_4_WR_OFFSET_A_ADDR        (REG_SMU_BASE_ADDR+0x00000198)
#define SMU_RU_4_WR_OFFSET_A_OFFSET      0x00000198
#define SMU_RU_4_WR_OFFSET_A_INDEX       0x00000066
#define SMU_RU_4_WR_OFFSET_A_RESET       0x00000000

__INLINE uint32_t  smu_ru_4_wr_offset_a_get(void)
{
	return REG_PL_RD(SMU_RU_4_WR_OFFSET_A_ADDR);
}

__INLINE void smu_ru_4_wr_offset_a_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_4_WR_OFFSET_A_ADDR, value);
}

// field definitions
#define SMU_RU_4_WR_OFFSET_A_SS_OFFSET_MASK    ((uint32_t)0xFFFF0000)
#define SMU_RU_4_WR_OFFSET_A_SS_OFFSET_LSB    16
#define SMU_RU_4_WR_OFFSET_A_SS_OFFSET_WIDTH    ((uint32_t)0x00000010)
#define SMU_RU_4_WR_OFFSET_A_ANT_OFFSET_MASK    ((uint32_t)0x0000FFFF)
#define SMU_RU_4_WR_OFFSET_A_ANT_OFFSET_LSB    0
#define SMU_RU_4_WR_OFFSET_A_ANT_OFFSET_WIDTH    ((uint32_t)0x00000010)

#define SMU_RU_4_WR_OFFSET_A_SS_OFFSET_RST    0x0
#define SMU_RU_4_WR_OFFSET_A_ANT_OFFSET_RST    0x0

__INLINE void smu_ru_4_wr_offset_a_pack(uint16_t ss_offset, uint16_t ant_offset)
{
	ASSERT_ERR((((uint32_t)ss_offset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)ant_offset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_4_WR_OFFSET_A_ADDR,  ((uint32_t)ss_offset << 16) |((uint32_t)ant_offset << 0));
}

__INLINE void smu_ru_4_wr_offset_a_unpack(uint16_t* ss_offset, uint16_t* ant_offset)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_4_WR_OFFSET_A_ADDR);

	*ss_offset = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*ant_offset = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t smu_ru_4_wr_offset_a_ss_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_4_WR_OFFSET_A_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void smu_ru_4_wr_offset_a_ss_offset_setf(uint16_t ssoffset)
{
	ASSERT_ERR((((uint32_t)ssoffset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SMU_RU_4_WR_OFFSET_A_ADDR, (REG_PL_RD(SMU_RU_4_WR_OFFSET_A_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)ssoffset <<16));
}
__INLINE uint16_t smu_ru_4_wr_offset_a_ant_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_4_WR_OFFSET_A_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void smu_ru_4_wr_offset_a_ant_offset_setf(uint16_t antoffset)
{
	ASSERT_ERR((((uint32_t)antoffset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_4_WR_OFFSET_A_ADDR, (REG_PL_RD(SMU_RU_4_WR_OFFSET_A_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)antoffset <<0));
}

/**
 * @brief RU_4_WR_OFFSET_B register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SS_OFFSET                 0x0
 *    15:00 ANT_OFFSET                0x0
 * </pre>
 */
#define SMU_RU_4_WR_OFFSET_B_ADDR        (REG_SMU_BASE_ADDR+0x0000019C)
#define SMU_RU_4_WR_OFFSET_B_OFFSET      0x0000019C
#define SMU_RU_4_WR_OFFSET_B_INDEX       0x00000067
#define SMU_RU_4_WR_OFFSET_B_RESET       0x00000000

__INLINE uint32_t  smu_ru_4_wr_offset_b_get(void)
{
	return REG_PL_RD(SMU_RU_4_WR_OFFSET_B_ADDR);
}

__INLINE void smu_ru_4_wr_offset_b_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_4_WR_OFFSET_B_ADDR, value);
}

// field definitions
#define SMU_RU_4_WR_OFFSET_B_SS_OFFSET_MASK    ((uint32_t)0xFFFF0000)
#define SMU_RU_4_WR_OFFSET_B_SS_OFFSET_LSB    16
#define SMU_RU_4_WR_OFFSET_B_SS_OFFSET_WIDTH    ((uint32_t)0x00000010)
#define SMU_RU_4_WR_OFFSET_B_ANT_OFFSET_MASK    ((uint32_t)0x0000FFFF)
#define SMU_RU_4_WR_OFFSET_B_ANT_OFFSET_LSB    0
#define SMU_RU_4_WR_OFFSET_B_ANT_OFFSET_WIDTH    ((uint32_t)0x00000010)

#define SMU_RU_4_WR_OFFSET_B_SS_OFFSET_RST    0x0
#define SMU_RU_4_WR_OFFSET_B_ANT_OFFSET_RST    0x0

__INLINE void smu_ru_4_wr_offset_b_pack(uint16_t ss_offset, uint16_t ant_offset)
{
	ASSERT_ERR((((uint32_t)ss_offset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)ant_offset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_4_WR_OFFSET_B_ADDR,  ((uint32_t)ss_offset << 16) |((uint32_t)ant_offset << 0));
}

__INLINE void smu_ru_4_wr_offset_b_unpack(uint16_t* ss_offset, uint16_t* ant_offset)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_4_WR_OFFSET_B_ADDR);

	*ss_offset = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*ant_offset = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t smu_ru_4_wr_offset_b_ss_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_4_WR_OFFSET_B_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void smu_ru_4_wr_offset_b_ss_offset_setf(uint16_t ssoffset)
{
	ASSERT_ERR((((uint32_t)ssoffset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SMU_RU_4_WR_OFFSET_B_ADDR, (REG_PL_RD(SMU_RU_4_WR_OFFSET_B_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)ssoffset <<16));
}
__INLINE uint16_t smu_ru_4_wr_offset_b_ant_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_4_WR_OFFSET_B_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void smu_ru_4_wr_offset_b_ant_offset_setf(uint16_t antoffset)
{
	ASSERT_ERR((((uint32_t)antoffset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_4_WR_OFFSET_B_ADDR, (REG_PL_RD(SMU_RU_4_WR_OFFSET_B_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)antoffset <<0));
}

/**
 * @brief RU_5_CFG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26:24 STARTING_STS              0x0
 *    21:16 RU_INDEX                  0x0
 *    14:12 RU_TYPE                   0x0
 *    11    SMOOTH_FILTER_EN          0              
 *    10    PILOT_AV_EN               0              
 *    09:08 OUTPUT_DECIMATION         0x0
 *    07:06 NB_SC_SW_A                0x0
 *    05:04 GROUPING                  0x0
 *    03:00 NSS                       0x0
 * </pre>
 */
#define SMU_RU_5_CFG_ADDR        (REG_SMU_BASE_ADDR+0x000001A0)
#define SMU_RU_5_CFG_OFFSET      0x000001A0
#define SMU_RU_5_CFG_INDEX       0x00000068
#define SMU_RU_5_CFG_RESET       0x00000000

__INLINE uint32_t  smu_ru_5_cfg_get(void)
{
	return REG_PL_RD(SMU_RU_5_CFG_ADDR);
}

__INLINE void smu_ru_5_cfg_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_5_CFG_ADDR, value);
}

// field definitions
#define SMU_RU_5_CFG_STARTING_STS_MASK      ((uint32_t)0x07000000)
#define SMU_RU_5_CFG_STARTING_STS_LSB       24
#define SMU_RU_5_CFG_STARTING_STS_WIDTH     ((uint32_t)0x00000003)
#define SMU_RU_5_CFG_RU_INDEX_MASK          ((uint32_t)0x003F0000)
#define SMU_RU_5_CFG_RU_INDEX_LSB           16
#define SMU_RU_5_CFG_RU_INDEX_WIDTH         ((uint32_t)0x00000006)
#define SMU_RU_5_CFG_RU_TYPE_MASK           ((uint32_t)0x00007000)
#define SMU_RU_5_CFG_RU_TYPE_LSB            12
#define SMU_RU_5_CFG_RU_TYPE_WIDTH          ((uint32_t)0x00000003)
#define SMU_RU_5_CFG_SMOOTH_FILTER_EN_BIT    ((uint32_t)0x00000800)
#define SMU_RU_5_CFG_SMOOTH_FILTER_EN_POS    11
#define SMU_RU_5_CFG_PILOT_AV_EN_BIT        ((uint32_t)0x00000400)
#define SMU_RU_5_CFG_PILOT_AV_EN_POS        10
#define SMU_RU_5_CFG_OUTPUT_DECIMATION_MASK    ((uint32_t)0x00000300)
#define SMU_RU_5_CFG_OUTPUT_DECIMATION_LSB    8
#define SMU_RU_5_CFG_OUTPUT_DECIMATION_WIDTH    ((uint32_t)0x00000002)
#define SMU_RU_5_CFG_NB_SC_SW_A_MASK        ((uint32_t)0x000000C0)
#define SMU_RU_5_CFG_NB_SC_SW_A_LSB         6
#define SMU_RU_5_CFG_NB_SC_SW_A_WIDTH       ((uint32_t)0x00000002)
#define SMU_RU_5_CFG_GROUPING_MASK          ((uint32_t)0x00000030)
#define SMU_RU_5_CFG_GROUPING_LSB           4
#define SMU_RU_5_CFG_GROUPING_WIDTH         ((uint32_t)0x00000002)
#define SMU_RU_5_CFG_NSS_MASK               ((uint32_t)0x0000000F)
#define SMU_RU_5_CFG_NSS_LSB                0
#define SMU_RU_5_CFG_NSS_WIDTH              ((uint32_t)0x00000004)

#define SMU_RU_5_CFG_STARTING_STS_RST       0x0
#define SMU_RU_5_CFG_RU_INDEX_RST           0x0
#define SMU_RU_5_CFG_RU_TYPE_RST            0x0
#define SMU_RU_5_CFG_SMOOTH_FILTER_EN_RST    0x0
#define SMU_RU_5_CFG_PILOT_AV_EN_RST        0x0
#define SMU_RU_5_CFG_OUTPUT_DECIMATION_RST    0x0
#define SMU_RU_5_CFG_NB_SC_SW_A_RST         0x0
#define SMU_RU_5_CFG_GROUPING_RST           0x0
#define SMU_RU_5_CFG_NSS_RST                0x0

__INLINE void smu_ru_5_cfg_pack(uint8_t starting_sts, uint8_t ru_index, uint8_t ru_type, uint8_t smooth_filter_en, uint8_t pilot_av_en, uint8_t output_decimation, uint8_t nb_sc_sw_a, uint8_t grouping, uint8_t nss)
{
	ASSERT_ERR((((uint32_t)starting_sts << 24) & ~((uint32_t)0x07000000)) == 0);
	ASSERT_ERR((((uint32_t)ru_index << 16) & ~((uint32_t)0x003F0000)) == 0);
	ASSERT_ERR((((uint32_t)ru_type << 12) & ~((uint32_t)0x00007000)) == 0);
	ASSERT_ERR((((uint32_t)smooth_filter_en << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)pilot_av_en << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)output_decimation << 8) & ~((uint32_t)0x00000300)) == 0);
	ASSERT_ERR((((uint32_t)nb_sc_sw_a << 6) & ~((uint32_t)0x000000C0)) == 0);
	ASSERT_ERR((((uint32_t)grouping << 4) & ~((uint32_t)0x00000030)) == 0);
	ASSERT_ERR((((uint32_t)nss << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(SMU_RU_5_CFG_ADDR,  ((uint32_t)starting_sts << 24) |((uint32_t)ru_index << 16) |((uint32_t)ru_type << 12) |((uint32_t)smooth_filter_en << 11) |((uint32_t)pilot_av_en << 10) |((uint32_t)output_decimation << 8) |((uint32_t)nb_sc_sw_a << 6) |((uint32_t)grouping << 4) |((uint32_t)nss << 0));
}

__INLINE void smu_ru_5_cfg_unpack(uint8_t* starting_sts, uint8_t* ru_index, uint8_t* ru_type, uint8_t* smooth_filter_en, uint8_t* pilot_av_en, uint8_t* output_decimation, uint8_t* nb_sc_sw_a, uint8_t* grouping, uint8_t* nss)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_5_CFG_ADDR);

	*starting_sts = (localVal & ((uint32_t)0x07000000)) >>  24;
	*ru_index = (localVal & ((uint32_t)0x003F0000)) >>  16;
	*ru_type = (localVal & ((uint32_t)0x00007000)) >>  12;
	*smooth_filter_en = (localVal & ((uint32_t)0x00000800)) >>  11;
	*pilot_av_en = (localVal & ((uint32_t)0x00000400)) >>  10;
	*output_decimation = (localVal & ((uint32_t)0x00000300)) >>  8;
	*nb_sc_sw_a = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*grouping = (localVal & ((uint32_t)0x00000030)) >>  4;
	*nss = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t smu_ru_5_cfg_starting_sts_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_5_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE void smu_ru_5_cfg_starting_sts_setf(uint8_t startingsts)
{
	ASSERT_ERR((((uint32_t)startingsts << 24) & ~((uint32_t)0x07000000)) == 0);
	REG_PL_WR(SMU_RU_5_CFG_ADDR, (REG_PL_RD(SMU_RU_5_CFG_ADDR) & ~((uint32_t)0x07000000)) | ((uint32_t)startingsts <<24));
}
__INLINE uint8_t smu_ru_5_cfg_ru_index_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_5_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x003F0000)) >> 16);
}
__INLINE void smu_ru_5_cfg_ru_index_setf(uint8_t ruindex)
{
	ASSERT_ERR((((uint32_t)ruindex << 16) & ~((uint32_t)0x003F0000)) == 0);
	REG_PL_WR(SMU_RU_5_CFG_ADDR, (REG_PL_RD(SMU_RU_5_CFG_ADDR) & ~((uint32_t)0x003F0000)) | ((uint32_t)ruindex <<16));
}
__INLINE uint8_t smu_ru_5_cfg_ru_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_5_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007000)) >> 12);
}
__INLINE void smu_ru_5_cfg_ru_type_setf(uint8_t rutype)
{
	ASSERT_ERR((((uint32_t)rutype << 12) & ~((uint32_t)0x00007000)) == 0);
	REG_PL_WR(SMU_RU_5_CFG_ADDR, (REG_PL_RD(SMU_RU_5_CFG_ADDR) & ~((uint32_t)0x00007000)) | ((uint32_t)rutype <<12));
}
__INLINE uint8_t smu_ru_5_cfg_smooth_filter_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_5_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void smu_ru_5_cfg_smooth_filter_en_setf(uint8_t smoothfilteren)
{
	ASSERT_ERR((((uint32_t)smoothfilteren << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(SMU_RU_5_CFG_ADDR, (REG_PL_RD(SMU_RU_5_CFG_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)smoothfilteren <<11));
}
__INLINE uint8_t smu_ru_5_cfg_pilot_av_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_5_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void smu_ru_5_cfg_pilot_av_en_setf(uint8_t pilotaven)
{
	ASSERT_ERR((((uint32_t)pilotaven << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(SMU_RU_5_CFG_ADDR, (REG_PL_RD(SMU_RU_5_CFG_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)pilotaven <<10));
}
__INLINE uint8_t smu_ru_5_cfg_output_decimation_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_5_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000300)) >> 8);
}
__INLINE void smu_ru_5_cfg_output_decimation_setf(uint8_t outputdecimation)
{
	ASSERT_ERR((((uint32_t)outputdecimation << 8) & ~((uint32_t)0x00000300)) == 0);
	REG_PL_WR(SMU_RU_5_CFG_ADDR, (REG_PL_RD(SMU_RU_5_CFG_ADDR) & ~((uint32_t)0x00000300)) | ((uint32_t)outputdecimation <<8));
}
__INLINE uint8_t smu_ru_5_cfg_nb_sc_sw_a_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_5_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE void smu_ru_5_cfg_nb_sc_sw_a_setf(uint8_t nbscswa)
{
	ASSERT_ERR((((uint32_t)nbscswa << 6) & ~((uint32_t)0x000000C0)) == 0);
	REG_PL_WR(SMU_RU_5_CFG_ADDR, (REG_PL_RD(SMU_RU_5_CFG_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)nbscswa <<6));
}
__INLINE uint8_t smu_ru_5_cfg_grouping_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_5_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000030)) >> 4);
}
__INLINE void smu_ru_5_cfg_grouping_setf(uint8_t grouping)
{
	ASSERT_ERR((((uint32_t)grouping << 4) & ~((uint32_t)0x00000030)) == 0);
	REG_PL_WR(SMU_RU_5_CFG_ADDR, (REG_PL_RD(SMU_RU_5_CFG_ADDR) & ~((uint32_t)0x00000030)) | ((uint32_t)grouping <<4));
}
__INLINE uint8_t smu_ru_5_cfg_nss_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_5_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void smu_ru_5_cfg_nss_setf(uint8_t nss)
{
	ASSERT_ERR((((uint32_t)nss << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(SMU_RU_5_CFG_ADDR, (REG_PL_RD(SMU_RU_5_CFG_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)nss <<0));
}

/**
 * @brief RU_5_FILTER_PTR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 FILTER_PTR                0x0
 * </pre>
 */
#define SMU_RU_5_FILTER_PTR_ADDR        (REG_SMU_BASE_ADDR+0x000001A4)
#define SMU_RU_5_FILTER_PTR_OFFSET      0x000001A4
#define SMU_RU_5_FILTER_PTR_INDEX       0x00000069
#define SMU_RU_5_FILTER_PTR_RESET       0x00000000

__INLINE uint32_t  smu_ru_5_filter_ptr_get(void)
{
	return REG_PL_RD(SMU_RU_5_FILTER_PTR_ADDR);
}

__INLINE void smu_ru_5_filter_ptr_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_5_FILTER_PTR_ADDR, value);
}

// field definitions
#define SMU_RU_5_FILTER_PTR_FILTER_PTR_MASK    ((uint32_t)0xFFFFFFFF)
#define SMU_RU_5_FILTER_PTR_FILTER_PTR_LSB    0
#define SMU_RU_5_FILTER_PTR_FILTER_PTR_WIDTH    ((uint32_t)0x00000020)

#define SMU_RU_5_FILTER_PTR_FILTER_PTR_RST    0x0

__INLINE uint32_t smu_ru_5_filter_ptr_filter_ptr_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_5_FILTER_PTR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void smu_ru_5_filter_ptr_filter_ptr_setf(uint32_t filterptr)
{
	ASSERT_ERR((((uint32_t)filterptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SMU_RU_5_FILTER_PTR_ADDR, (uint32_t)filterptr << 0);
}

/**
 * @brief RU_5_DATA_RD_PTR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DATA_RD_PTR               0x0
 * </pre>
 */
#define SMU_RU_5_DATA_RD_PTR_ADDR        (REG_SMU_BASE_ADDR+0x000001A8)
#define SMU_RU_5_DATA_RD_PTR_OFFSET      0x000001A8
#define SMU_RU_5_DATA_RD_PTR_INDEX       0x0000006A
#define SMU_RU_5_DATA_RD_PTR_RESET       0x00000000

__INLINE uint32_t  smu_ru_5_data_rd_ptr_get(void)
{
	return REG_PL_RD(SMU_RU_5_DATA_RD_PTR_ADDR);
}

__INLINE void smu_ru_5_data_rd_ptr_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_5_DATA_RD_PTR_ADDR, value);
}

// field definitions
#define SMU_RU_5_DATA_RD_PTR_DATA_RD_PTR_MASK    ((uint32_t)0xFFFFFFFF)
#define SMU_RU_5_DATA_RD_PTR_DATA_RD_PTR_LSB    0
#define SMU_RU_5_DATA_RD_PTR_DATA_RD_PTR_WIDTH    ((uint32_t)0x00000020)

#define SMU_RU_5_DATA_RD_PTR_DATA_RD_PTR_RST    0x0

__INLINE uint32_t smu_ru_5_data_rd_ptr_data_rd_ptr_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_5_DATA_RD_PTR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void smu_ru_5_data_rd_ptr_data_rd_ptr_setf(uint32_t datardptr)
{
	ASSERT_ERR((((uint32_t)datardptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SMU_RU_5_DATA_RD_PTR_ADDR, (uint32_t)datardptr << 0);
}

/**
 * @brief RU_5_RD_OFFSET register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SS_OFFSET                 0x0
 *    15:00 ANT_OFFSET                0x0
 * </pre>
 */
#define SMU_RU_5_RD_OFFSET_ADDR        (REG_SMU_BASE_ADDR+0x000001AC)
#define SMU_RU_5_RD_OFFSET_OFFSET      0x000001AC
#define SMU_RU_5_RD_OFFSET_INDEX       0x0000006B
#define SMU_RU_5_RD_OFFSET_RESET       0x00000000

__INLINE uint32_t  smu_ru_5_rd_offset_get(void)
{
	return REG_PL_RD(SMU_RU_5_RD_OFFSET_ADDR);
}

__INLINE void smu_ru_5_rd_offset_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_5_RD_OFFSET_ADDR, value);
}

// field definitions
#define SMU_RU_5_RD_OFFSET_SS_OFFSET_MASK    ((uint32_t)0xFFFF0000)
#define SMU_RU_5_RD_OFFSET_SS_OFFSET_LSB    16
#define SMU_RU_5_RD_OFFSET_SS_OFFSET_WIDTH    ((uint32_t)0x00000010)
#define SMU_RU_5_RD_OFFSET_ANT_OFFSET_MASK    ((uint32_t)0x0000FFFF)
#define SMU_RU_5_RD_OFFSET_ANT_OFFSET_LSB    0
#define SMU_RU_5_RD_OFFSET_ANT_OFFSET_WIDTH    ((uint32_t)0x00000010)

#define SMU_RU_5_RD_OFFSET_SS_OFFSET_RST    0x0
#define SMU_RU_5_RD_OFFSET_ANT_OFFSET_RST    0x0

__INLINE void smu_ru_5_rd_offset_pack(uint16_t ss_offset, uint16_t ant_offset)
{
	ASSERT_ERR((((uint32_t)ss_offset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)ant_offset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_5_RD_OFFSET_ADDR,  ((uint32_t)ss_offset << 16) |((uint32_t)ant_offset << 0));
}

__INLINE void smu_ru_5_rd_offset_unpack(uint16_t* ss_offset, uint16_t* ant_offset)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_5_RD_OFFSET_ADDR);

	*ss_offset = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*ant_offset = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t smu_ru_5_rd_offset_ss_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_5_RD_OFFSET_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void smu_ru_5_rd_offset_ss_offset_setf(uint16_t ssoffset)
{
	ASSERT_ERR((((uint32_t)ssoffset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SMU_RU_5_RD_OFFSET_ADDR, (REG_PL_RD(SMU_RU_5_RD_OFFSET_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)ssoffset <<16));
}
__INLINE uint16_t smu_ru_5_rd_offset_ant_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_5_RD_OFFSET_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void smu_ru_5_rd_offset_ant_offset_setf(uint16_t antoffset)
{
	ASSERT_ERR((((uint32_t)antoffset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_5_RD_OFFSET_ADDR, (REG_PL_RD(SMU_RU_5_RD_OFFSET_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)antoffset <<0));
}

/**
 * @brief RU_5_DATA_WR_PTR_A register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DATA_WR_PTR_A             0x0
 * </pre>
 */
#define SMU_RU_5_DATA_WR_PTR_A_ADDR        (REG_SMU_BASE_ADDR+0x000001B0)
#define SMU_RU_5_DATA_WR_PTR_A_OFFSET      0x000001B0
#define SMU_RU_5_DATA_WR_PTR_A_INDEX       0x0000006C
#define SMU_RU_5_DATA_WR_PTR_A_RESET       0x00000000

__INLINE uint32_t  smu_ru_5_data_wr_ptr_a_get(void)
{
	return REG_PL_RD(SMU_RU_5_DATA_WR_PTR_A_ADDR);
}

__INLINE void smu_ru_5_data_wr_ptr_a_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_5_DATA_WR_PTR_A_ADDR, value);
}

// field definitions
#define SMU_RU_5_DATA_WR_PTR_A_DATA_WR_PTR_A_MASK    ((uint32_t)0xFFFFFFFF)
#define SMU_RU_5_DATA_WR_PTR_A_DATA_WR_PTR_A_LSB    0
#define SMU_RU_5_DATA_WR_PTR_A_DATA_WR_PTR_A_WIDTH    ((uint32_t)0x00000020)

#define SMU_RU_5_DATA_WR_PTR_A_DATA_WR_PTR_A_RST    0x0

__INLINE uint32_t smu_ru_5_data_wr_ptr_a_data_wr_ptr_a_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_5_DATA_WR_PTR_A_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void smu_ru_5_data_wr_ptr_a_data_wr_ptr_a_setf(uint32_t datawrptra)
{
	ASSERT_ERR((((uint32_t)datawrptra << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SMU_RU_5_DATA_WR_PTR_A_ADDR, (uint32_t)datawrptra << 0);
}

/**
 * @brief RU_5_DATA_WR_PTR_B register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DATA_WR_PTR_B             0x0
 * </pre>
 */
#define SMU_RU_5_DATA_WR_PTR_B_ADDR        (REG_SMU_BASE_ADDR+0x000001B4)
#define SMU_RU_5_DATA_WR_PTR_B_OFFSET      0x000001B4
#define SMU_RU_5_DATA_WR_PTR_B_INDEX       0x0000006D
#define SMU_RU_5_DATA_WR_PTR_B_RESET       0x00000000

__INLINE uint32_t  smu_ru_5_data_wr_ptr_b_get(void)
{
	return REG_PL_RD(SMU_RU_5_DATA_WR_PTR_B_ADDR);
}

__INLINE void smu_ru_5_data_wr_ptr_b_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_5_DATA_WR_PTR_B_ADDR, value);
}

// field definitions
#define SMU_RU_5_DATA_WR_PTR_B_DATA_WR_PTR_B_MASK    ((uint32_t)0xFFFFFFFF)
#define SMU_RU_5_DATA_WR_PTR_B_DATA_WR_PTR_B_LSB    0
#define SMU_RU_5_DATA_WR_PTR_B_DATA_WR_PTR_B_WIDTH    ((uint32_t)0x00000020)

#define SMU_RU_5_DATA_WR_PTR_B_DATA_WR_PTR_B_RST    0x0

__INLINE uint32_t smu_ru_5_data_wr_ptr_b_data_wr_ptr_b_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_5_DATA_WR_PTR_B_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void smu_ru_5_data_wr_ptr_b_data_wr_ptr_b_setf(uint32_t datawrptrb)
{
	ASSERT_ERR((((uint32_t)datawrptrb << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SMU_RU_5_DATA_WR_PTR_B_ADDR, (uint32_t)datawrptrb << 0);
}

/**
 * @brief RU_5_WR_OFFSET_A register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SS_OFFSET                 0x0
 *    15:00 ANT_OFFSET                0x0
 * </pre>
 */
#define SMU_RU_5_WR_OFFSET_A_ADDR        (REG_SMU_BASE_ADDR+0x000001B8)
#define SMU_RU_5_WR_OFFSET_A_OFFSET      0x000001B8
#define SMU_RU_5_WR_OFFSET_A_INDEX       0x0000006E
#define SMU_RU_5_WR_OFFSET_A_RESET       0x00000000

__INLINE uint32_t  smu_ru_5_wr_offset_a_get(void)
{
	return REG_PL_RD(SMU_RU_5_WR_OFFSET_A_ADDR);
}

__INLINE void smu_ru_5_wr_offset_a_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_5_WR_OFFSET_A_ADDR, value);
}

// field definitions
#define SMU_RU_5_WR_OFFSET_A_SS_OFFSET_MASK    ((uint32_t)0xFFFF0000)
#define SMU_RU_5_WR_OFFSET_A_SS_OFFSET_LSB    16
#define SMU_RU_5_WR_OFFSET_A_SS_OFFSET_WIDTH    ((uint32_t)0x00000010)
#define SMU_RU_5_WR_OFFSET_A_ANT_OFFSET_MASK    ((uint32_t)0x0000FFFF)
#define SMU_RU_5_WR_OFFSET_A_ANT_OFFSET_LSB    0
#define SMU_RU_5_WR_OFFSET_A_ANT_OFFSET_WIDTH    ((uint32_t)0x00000010)

#define SMU_RU_5_WR_OFFSET_A_SS_OFFSET_RST    0x0
#define SMU_RU_5_WR_OFFSET_A_ANT_OFFSET_RST    0x0

__INLINE void smu_ru_5_wr_offset_a_pack(uint16_t ss_offset, uint16_t ant_offset)
{
	ASSERT_ERR((((uint32_t)ss_offset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)ant_offset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_5_WR_OFFSET_A_ADDR,  ((uint32_t)ss_offset << 16) |((uint32_t)ant_offset << 0));
}

__INLINE void smu_ru_5_wr_offset_a_unpack(uint16_t* ss_offset, uint16_t* ant_offset)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_5_WR_OFFSET_A_ADDR);

	*ss_offset = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*ant_offset = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t smu_ru_5_wr_offset_a_ss_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_5_WR_OFFSET_A_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void smu_ru_5_wr_offset_a_ss_offset_setf(uint16_t ssoffset)
{
	ASSERT_ERR((((uint32_t)ssoffset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SMU_RU_5_WR_OFFSET_A_ADDR, (REG_PL_RD(SMU_RU_5_WR_OFFSET_A_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)ssoffset <<16));
}
__INLINE uint16_t smu_ru_5_wr_offset_a_ant_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_5_WR_OFFSET_A_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void smu_ru_5_wr_offset_a_ant_offset_setf(uint16_t antoffset)
{
	ASSERT_ERR((((uint32_t)antoffset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_5_WR_OFFSET_A_ADDR, (REG_PL_RD(SMU_RU_5_WR_OFFSET_A_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)antoffset <<0));
}

/**
 * @brief RU_5_WR_OFFSET_B register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SS_OFFSET                 0x0
 *    15:00 ANT_OFFSET                0x0
 * </pre>
 */
#define SMU_RU_5_WR_OFFSET_B_ADDR        (REG_SMU_BASE_ADDR+0x000001BC)
#define SMU_RU_5_WR_OFFSET_B_OFFSET      0x000001BC
#define SMU_RU_5_WR_OFFSET_B_INDEX       0x0000006F
#define SMU_RU_5_WR_OFFSET_B_RESET       0x00000000

__INLINE uint32_t  smu_ru_5_wr_offset_b_get(void)
{
	return REG_PL_RD(SMU_RU_5_WR_OFFSET_B_ADDR);
}

__INLINE void smu_ru_5_wr_offset_b_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_5_WR_OFFSET_B_ADDR, value);
}

// field definitions
#define SMU_RU_5_WR_OFFSET_B_SS_OFFSET_MASK    ((uint32_t)0xFFFF0000)
#define SMU_RU_5_WR_OFFSET_B_SS_OFFSET_LSB    16
#define SMU_RU_5_WR_OFFSET_B_SS_OFFSET_WIDTH    ((uint32_t)0x00000010)
#define SMU_RU_5_WR_OFFSET_B_ANT_OFFSET_MASK    ((uint32_t)0x0000FFFF)
#define SMU_RU_5_WR_OFFSET_B_ANT_OFFSET_LSB    0
#define SMU_RU_5_WR_OFFSET_B_ANT_OFFSET_WIDTH    ((uint32_t)0x00000010)

#define SMU_RU_5_WR_OFFSET_B_SS_OFFSET_RST    0x0
#define SMU_RU_5_WR_OFFSET_B_ANT_OFFSET_RST    0x0

__INLINE void smu_ru_5_wr_offset_b_pack(uint16_t ss_offset, uint16_t ant_offset)
{
	ASSERT_ERR((((uint32_t)ss_offset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)ant_offset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_5_WR_OFFSET_B_ADDR,  ((uint32_t)ss_offset << 16) |((uint32_t)ant_offset << 0));
}

__INLINE void smu_ru_5_wr_offset_b_unpack(uint16_t* ss_offset, uint16_t* ant_offset)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_5_WR_OFFSET_B_ADDR);

	*ss_offset = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*ant_offset = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t smu_ru_5_wr_offset_b_ss_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_5_WR_OFFSET_B_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void smu_ru_5_wr_offset_b_ss_offset_setf(uint16_t ssoffset)
{
	ASSERT_ERR((((uint32_t)ssoffset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SMU_RU_5_WR_OFFSET_B_ADDR, (REG_PL_RD(SMU_RU_5_WR_OFFSET_B_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)ssoffset <<16));
}
__INLINE uint16_t smu_ru_5_wr_offset_b_ant_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_5_WR_OFFSET_B_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void smu_ru_5_wr_offset_b_ant_offset_setf(uint16_t antoffset)
{
	ASSERT_ERR((((uint32_t)antoffset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_5_WR_OFFSET_B_ADDR, (REG_PL_RD(SMU_RU_5_WR_OFFSET_B_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)antoffset <<0));
}

/**
 * @brief RU_6_CFG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26:24 STARTING_STS              0x0
 *    21:16 RU_INDEX                  0x0
 *    14:12 RU_TYPE                   0x0
 *    11    SMOOTH_FILTER_EN          0              
 *    10    PILOT_AV_EN               0              
 *    09:08 OUTPUT_DECIMATION         0x0
 *    07:06 NB_SC_SW_A                0x0
 *    05:04 GROUPING                  0x0
 *    03:00 NSS                       0x0
 * </pre>
 */
#define SMU_RU_6_CFG_ADDR        (REG_SMU_BASE_ADDR+0x000001C0)
#define SMU_RU_6_CFG_OFFSET      0x000001C0
#define SMU_RU_6_CFG_INDEX       0x00000070
#define SMU_RU_6_CFG_RESET       0x00000000

__INLINE uint32_t  smu_ru_6_cfg_get(void)
{
	return REG_PL_RD(SMU_RU_6_CFG_ADDR);
}

__INLINE void smu_ru_6_cfg_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_6_CFG_ADDR, value);
}

// field definitions
#define SMU_RU_6_CFG_STARTING_STS_MASK      ((uint32_t)0x07000000)
#define SMU_RU_6_CFG_STARTING_STS_LSB       24
#define SMU_RU_6_CFG_STARTING_STS_WIDTH     ((uint32_t)0x00000003)
#define SMU_RU_6_CFG_RU_INDEX_MASK          ((uint32_t)0x003F0000)
#define SMU_RU_6_CFG_RU_INDEX_LSB           16
#define SMU_RU_6_CFG_RU_INDEX_WIDTH         ((uint32_t)0x00000006)
#define SMU_RU_6_CFG_RU_TYPE_MASK           ((uint32_t)0x00007000)
#define SMU_RU_6_CFG_RU_TYPE_LSB            12
#define SMU_RU_6_CFG_RU_TYPE_WIDTH          ((uint32_t)0x00000003)
#define SMU_RU_6_CFG_SMOOTH_FILTER_EN_BIT    ((uint32_t)0x00000800)
#define SMU_RU_6_CFG_SMOOTH_FILTER_EN_POS    11
#define SMU_RU_6_CFG_PILOT_AV_EN_BIT        ((uint32_t)0x00000400)
#define SMU_RU_6_CFG_PILOT_AV_EN_POS        10
#define SMU_RU_6_CFG_OUTPUT_DECIMATION_MASK    ((uint32_t)0x00000300)
#define SMU_RU_6_CFG_OUTPUT_DECIMATION_LSB    8
#define SMU_RU_6_CFG_OUTPUT_DECIMATION_WIDTH    ((uint32_t)0x00000002)
#define SMU_RU_6_CFG_NB_SC_SW_A_MASK        ((uint32_t)0x000000C0)
#define SMU_RU_6_CFG_NB_SC_SW_A_LSB         6
#define SMU_RU_6_CFG_NB_SC_SW_A_WIDTH       ((uint32_t)0x00000002)
#define SMU_RU_6_CFG_GROUPING_MASK          ((uint32_t)0x00000030)
#define SMU_RU_6_CFG_GROUPING_LSB           4
#define SMU_RU_6_CFG_GROUPING_WIDTH         ((uint32_t)0x00000002)
#define SMU_RU_6_CFG_NSS_MASK               ((uint32_t)0x0000000F)
#define SMU_RU_6_CFG_NSS_LSB                0
#define SMU_RU_6_CFG_NSS_WIDTH              ((uint32_t)0x00000004)

#define SMU_RU_6_CFG_STARTING_STS_RST       0x0
#define SMU_RU_6_CFG_RU_INDEX_RST           0x0
#define SMU_RU_6_CFG_RU_TYPE_RST            0x0
#define SMU_RU_6_CFG_SMOOTH_FILTER_EN_RST    0x0
#define SMU_RU_6_CFG_PILOT_AV_EN_RST        0x0
#define SMU_RU_6_CFG_OUTPUT_DECIMATION_RST    0x0
#define SMU_RU_6_CFG_NB_SC_SW_A_RST         0x0
#define SMU_RU_6_CFG_GROUPING_RST           0x0
#define SMU_RU_6_CFG_NSS_RST                0x0

__INLINE void smu_ru_6_cfg_pack(uint8_t starting_sts, uint8_t ru_index, uint8_t ru_type, uint8_t smooth_filter_en, uint8_t pilot_av_en, uint8_t output_decimation, uint8_t nb_sc_sw_a, uint8_t grouping, uint8_t nss)
{
	ASSERT_ERR((((uint32_t)starting_sts << 24) & ~((uint32_t)0x07000000)) == 0);
	ASSERT_ERR((((uint32_t)ru_index << 16) & ~((uint32_t)0x003F0000)) == 0);
	ASSERT_ERR((((uint32_t)ru_type << 12) & ~((uint32_t)0x00007000)) == 0);
	ASSERT_ERR((((uint32_t)smooth_filter_en << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)pilot_av_en << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)output_decimation << 8) & ~((uint32_t)0x00000300)) == 0);
	ASSERT_ERR((((uint32_t)nb_sc_sw_a << 6) & ~((uint32_t)0x000000C0)) == 0);
	ASSERT_ERR((((uint32_t)grouping << 4) & ~((uint32_t)0x00000030)) == 0);
	ASSERT_ERR((((uint32_t)nss << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(SMU_RU_6_CFG_ADDR,  ((uint32_t)starting_sts << 24) |((uint32_t)ru_index << 16) |((uint32_t)ru_type << 12) |((uint32_t)smooth_filter_en << 11) |((uint32_t)pilot_av_en << 10) |((uint32_t)output_decimation << 8) |((uint32_t)nb_sc_sw_a << 6) |((uint32_t)grouping << 4) |((uint32_t)nss << 0));
}

__INLINE void smu_ru_6_cfg_unpack(uint8_t* starting_sts, uint8_t* ru_index, uint8_t* ru_type, uint8_t* smooth_filter_en, uint8_t* pilot_av_en, uint8_t* output_decimation, uint8_t* nb_sc_sw_a, uint8_t* grouping, uint8_t* nss)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_6_CFG_ADDR);

	*starting_sts = (localVal & ((uint32_t)0x07000000)) >>  24;
	*ru_index = (localVal & ((uint32_t)0x003F0000)) >>  16;
	*ru_type = (localVal & ((uint32_t)0x00007000)) >>  12;
	*smooth_filter_en = (localVal & ((uint32_t)0x00000800)) >>  11;
	*pilot_av_en = (localVal & ((uint32_t)0x00000400)) >>  10;
	*output_decimation = (localVal & ((uint32_t)0x00000300)) >>  8;
	*nb_sc_sw_a = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*grouping = (localVal & ((uint32_t)0x00000030)) >>  4;
	*nss = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t smu_ru_6_cfg_starting_sts_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_6_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE void smu_ru_6_cfg_starting_sts_setf(uint8_t startingsts)
{
	ASSERT_ERR((((uint32_t)startingsts << 24) & ~((uint32_t)0x07000000)) == 0);
	REG_PL_WR(SMU_RU_6_CFG_ADDR, (REG_PL_RD(SMU_RU_6_CFG_ADDR) & ~((uint32_t)0x07000000)) | ((uint32_t)startingsts <<24));
}
__INLINE uint8_t smu_ru_6_cfg_ru_index_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_6_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x003F0000)) >> 16);
}
__INLINE void smu_ru_6_cfg_ru_index_setf(uint8_t ruindex)
{
	ASSERT_ERR((((uint32_t)ruindex << 16) & ~((uint32_t)0x003F0000)) == 0);
	REG_PL_WR(SMU_RU_6_CFG_ADDR, (REG_PL_RD(SMU_RU_6_CFG_ADDR) & ~((uint32_t)0x003F0000)) | ((uint32_t)ruindex <<16));
}
__INLINE uint8_t smu_ru_6_cfg_ru_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_6_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007000)) >> 12);
}
__INLINE void smu_ru_6_cfg_ru_type_setf(uint8_t rutype)
{
	ASSERT_ERR((((uint32_t)rutype << 12) & ~((uint32_t)0x00007000)) == 0);
	REG_PL_WR(SMU_RU_6_CFG_ADDR, (REG_PL_RD(SMU_RU_6_CFG_ADDR) & ~((uint32_t)0x00007000)) | ((uint32_t)rutype <<12));
}
__INLINE uint8_t smu_ru_6_cfg_smooth_filter_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_6_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void smu_ru_6_cfg_smooth_filter_en_setf(uint8_t smoothfilteren)
{
	ASSERT_ERR((((uint32_t)smoothfilteren << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(SMU_RU_6_CFG_ADDR, (REG_PL_RD(SMU_RU_6_CFG_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)smoothfilteren <<11));
}
__INLINE uint8_t smu_ru_6_cfg_pilot_av_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_6_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void smu_ru_6_cfg_pilot_av_en_setf(uint8_t pilotaven)
{
	ASSERT_ERR((((uint32_t)pilotaven << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(SMU_RU_6_CFG_ADDR, (REG_PL_RD(SMU_RU_6_CFG_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)pilotaven <<10));
}
__INLINE uint8_t smu_ru_6_cfg_output_decimation_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_6_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000300)) >> 8);
}
__INLINE void smu_ru_6_cfg_output_decimation_setf(uint8_t outputdecimation)
{
	ASSERT_ERR((((uint32_t)outputdecimation << 8) & ~((uint32_t)0x00000300)) == 0);
	REG_PL_WR(SMU_RU_6_CFG_ADDR, (REG_PL_RD(SMU_RU_6_CFG_ADDR) & ~((uint32_t)0x00000300)) | ((uint32_t)outputdecimation <<8));
}
__INLINE uint8_t smu_ru_6_cfg_nb_sc_sw_a_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_6_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE void smu_ru_6_cfg_nb_sc_sw_a_setf(uint8_t nbscswa)
{
	ASSERT_ERR((((uint32_t)nbscswa << 6) & ~((uint32_t)0x000000C0)) == 0);
	REG_PL_WR(SMU_RU_6_CFG_ADDR, (REG_PL_RD(SMU_RU_6_CFG_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)nbscswa <<6));
}
__INLINE uint8_t smu_ru_6_cfg_grouping_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_6_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000030)) >> 4);
}
__INLINE void smu_ru_6_cfg_grouping_setf(uint8_t grouping)
{
	ASSERT_ERR((((uint32_t)grouping << 4) & ~((uint32_t)0x00000030)) == 0);
	REG_PL_WR(SMU_RU_6_CFG_ADDR, (REG_PL_RD(SMU_RU_6_CFG_ADDR) & ~((uint32_t)0x00000030)) | ((uint32_t)grouping <<4));
}
__INLINE uint8_t smu_ru_6_cfg_nss_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_6_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void smu_ru_6_cfg_nss_setf(uint8_t nss)
{
	ASSERT_ERR((((uint32_t)nss << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(SMU_RU_6_CFG_ADDR, (REG_PL_RD(SMU_RU_6_CFG_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)nss <<0));
}

/**
 * @brief RU_6_FILTER_PTR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 FILTER_PTR                0x0
 * </pre>
 */
#define SMU_RU_6_FILTER_PTR_ADDR        (REG_SMU_BASE_ADDR+0x000001C4)
#define SMU_RU_6_FILTER_PTR_OFFSET      0x000001C4
#define SMU_RU_6_FILTER_PTR_INDEX       0x00000071
#define SMU_RU_6_FILTER_PTR_RESET       0x00000000

__INLINE uint32_t  smu_ru_6_filter_ptr_get(void)
{
	return REG_PL_RD(SMU_RU_6_FILTER_PTR_ADDR);
}

__INLINE void smu_ru_6_filter_ptr_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_6_FILTER_PTR_ADDR, value);
}

// field definitions
#define SMU_RU_6_FILTER_PTR_FILTER_PTR_MASK    ((uint32_t)0xFFFFFFFF)
#define SMU_RU_6_FILTER_PTR_FILTER_PTR_LSB    0
#define SMU_RU_6_FILTER_PTR_FILTER_PTR_WIDTH    ((uint32_t)0x00000020)

#define SMU_RU_6_FILTER_PTR_FILTER_PTR_RST    0x0

__INLINE uint32_t smu_ru_6_filter_ptr_filter_ptr_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_6_FILTER_PTR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void smu_ru_6_filter_ptr_filter_ptr_setf(uint32_t filterptr)
{
	ASSERT_ERR((((uint32_t)filterptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SMU_RU_6_FILTER_PTR_ADDR, (uint32_t)filterptr << 0);
}

/**
 * @brief RU_6_DATA_RD_PTR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DATA_RD_PTR               0x0
 * </pre>
 */
#define SMU_RU_6_DATA_RD_PTR_ADDR        (REG_SMU_BASE_ADDR+0x000001C8)
#define SMU_RU_6_DATA_RD_PTR_OFFSET      0x000001C8
#define SMU_RU_6_DATA_RD_PTR_INDEX       0x00000072
#define SMU_RU_6_DATA_RD_PTR_RESET       0x00000000

__INLINE uint32_t  smu_ru_6_data_rd_ptr_get(void)
{
	return REG_PL_RD(SMU_RU_6_DATA_RD_PTR_ADDR);
}

__INLINE void smu_ru_6_data_rd_ptr_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_6_DATA_RD_PTR_ADDR, value);
}

// field definitions
#define SMU_RU_6_DATA_RD_PTR_DATA_RD_PTR_MASK    ((uint32_t)0xFFFFFFFF)
#define SMU_RU_6_DATA_RD_PTR_DATA_RD_PTR_LSB    0
#define SMU_RU_6_DATA_RD_PTR_DATA_RD_PTR_WIDTH    ((uint32_t)0x00000020)

#define SMU_RU_6_DATA_RD_PTR_DATA_RD_PTR_RST    0x0

__INLINE uint32_t smu_ru_6_data_rd_ptr_data_rd_ptr_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_6_DATA_RD_PTR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void smu_ru_6_data_rd_ptr_data_rd_ptr_setf(uint32_t datardptr)
{
	ASSERT_ERR((((uint32_t)datardptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SMU_RU_6_DATA_RD_PTR_ADDR, (uint32_t)datardptr << 0);
}

/**
 * @brief RU_6_RD_OFFSET register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SS_OFFSET                 0x0
 *    15:00 ANT_OFFSET                0x0
 * </pre>
 */
#define SMU_RU_6_RD_OFFSET_ADDR        (REG_SMU_BASE_ADDR+0x000001CC)
#define SMU_RU_6_RD_OFFSET_OFFSET      0x000001CC
#define SMU_RU_6_RD_OFFSET_INDEX       0x00000073
#define SMU_RU_6_RD_OFFSET_RESET       0x00000000

__INLINE uint32_t  smu_ru_6_rd_offset_get(void)
{
	return REG_PL_RD(SMU_RU_6_RD_OFFSET_ADDR);
}

__INLINE void smu_ru_6_rd_offset_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_6_RD_OFFSET_ADDR, value);
}

// field definitions
#define SMU_RU_6_RD_OFFSET_SS_OFFSET_MASK    ((uint32_t)0xFFFF0000)
#define SMU_RU_6_RD_OFFSET_SS_OFFSET_LSB    16
#define SMU_RU_6_RD_OFFSET_SS_OFFSET_WIDTH    ((uint32_t)0x00000010)
#define SMU_RU_6_RD_OFFSET_ANT_OFFSET_MASK    ((uint32_t)0x0000FFFF)
#define SMU_RU_6_RD_OFFSET_ANT_OFFSET_LSB    0
#define SMU_RU_6_RD_OFFSET_ANT_OFFSET_WIDTH    ((uint32_t)0x00000010)

#define SMU_RU_6_RD_OFFSET_SS_OFFSET_RST    0x0
#define SMU_RU_6_RD_OFFSET_ANT_OFFSET_RST    0x0

__INLINE void smu_ru_6_rd_offset_pack(uint16_t ss_offset, uint16_t ant_offset)
{
	ASSERT_ERR((((uint32_t)ss_offset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)ant_offset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_6_RD_OFFSET_ADDR,  ((uint32_t)ss_offset << 16) |((uint32_t)ant_offset << 0));
}

__INLINE void smu_ru_6_rd_offset_unpack(uint16_t* ss_offset, uint16_t* ant_offset)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_6_RD_OFFSET_ADDR);

	*ss_offset = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*ant_offset = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t smu_ru_6_rd_offset_ss_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_6_RD_OFFSET_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void smu_ru_6_rd_offset_ss_offset_setf(uint16_t ssoffset)
{
	ASSERT_ERR((((uint32_t)ssoffset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SMU_RU_6_RD_OFFSET_ADDR, (REG_PL_RD(SMU_RU_6_RD_OFFSET_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)ssoffset <<16));
}
__INLINE uint16_t smu_ru_6_rd_offset_ant_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_6_RD_OFFSET_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void smu_ru_6_rd_offset_ant_offset_setf(uint16_t antoffset)
{
	ASSERT_ERR((((uint32_t)antoffset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_6_RD_OFFSET_ADDR, (REG_PL_RD(SMU_RU_6_RD_OFFSET_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)antoffset <<0));
}

/**
 * @brief RU_6_DATA_WR_PTR_A register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DATA_WR_PTR_A             0x0
 * </pre>
 */
#define SMU_RU_6_DATA_WR_PTR_A_ADDR        (REG_SMU_BASE_ADDR+0x000001D0)
#define SMU_RU_6_DATA_WR_PTR_A_OFFSET      0x000001D0
#define SMU_RU_6_DATA_WR_PTR_A_INDEX       0x00000074
#define SMU_RU_6_DATA_WR_PTR_A_RESET       0x00000000

__INLINE uint32_t  smu_ru_6_data_wr_ptr_a_get(void)
{
	return REG_PL_RD(SMU_RU_6_DATA_WR_PTR_A_ADDR);
}

__INLINE void smu_ru_6_data_wr_ptr_a_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_6_DATA_WR_PTR_A_ADDR, value);
}

// field definitions
#define SMU_RU_6_DATA_WR_PTR_A_DATA_WR_PTR_A_MASK    ((uint32_t)0xFFFFFFFF)
#define SMU_RU_6_DATA_WR_PTR_A_DATA_WR_PTR_A_LSB    0
#define SMU_RU_6_DATA_WR_PTR_A_DATA_WR_PTR_A_WIDTH    ((uint32_t)0x00000020)

#define SMU_RU_6_DATA_WR_PTR_A_DATA_WR_PTR_A_RST    0x0

__INLINE uint32_t smu_ru_6_data_wr_ptr_a_data_wr_ptr_a_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_6_DATA_WR_PTR_A_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void smu_ru_6_data_wr_ptr_a_data_wr_ptr_a_setf(uint32_t datawrptra)
{
	ASSERT_ERR((((uint32_t)datawrptra << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SMU_RU_6_DATA_WR_PTR_A_ADDR, (uint32_t)datawrptra << 0);
}

/**
 * @brief RU_6_DATA_WR_PTR_B register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DATA_WR_PTR_B             0x0
 * </pre>
 */
#define SMU_RU_6_DATA_WR_PTR_B_ADDR        (REG_SMU_BASE_ADDR+0x000001D4)
#define SMU_RU_6_DATA_WR_PTR_B_OFFSET      0x000001D4
#define SMU_RU_6_DATA_WR_PTR_B_INDEX       0x00000075
#define SMU_RU_6_DATA_WR_PTR_B_RESET       0x00000000

__INLINE uint32_t  smu_ru_6_data_wr_ptr_b_get(void)
{
	return REG_PL_RD(SMU_RU_6_DATA_WR_PTR_B_ADDR);
}

__INLINE void smu_ru_6_data_wr_ptr_b_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_6_DATA_WR_PTR_B_ADDR, value);
}

// field definitions
#define SMU_RU_6_DATA_WR_PTR_B_DATA_WR_PTR_B_MASK    ((uint32_t)0xFFFFFFFF)
#define SMU_RU_6_DATA_WR_PTR_B_DATA_WR_PTR_B_LSB    0
#define SMU_RU_6_DATA_WR_PTR_B_DATA_WR_PTR_B_WIDTH    ((uint32_t)0x00000020)

#define SMU_RU_6_DATA_WR_PTR_B_DATA_WR_PTR_B_RST    0x0

__INLINE uint32_t smu_ru_6_data_wr_ptr_b_data_wr_ptr_b_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_6_DATA_WR_PTR_B_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void smu_ru_6_data_wr_ptr_b_data_wr_ptr_b_setf(uint32_t datawrptrb)
{
	ASSERT_ERR((((uint32_t)datawrptrb << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SMU_RU_6_DATA_WR_PTR_B_ADDR, (uint32_t)datawrptrb << 0);
}

/**
 * @brief RU_6_WR_OFFSET_A register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SS_OFFSET                 0x0
 *    15:00 ANT_OFFSET                0x0
 * </pre>
 */
#define SMU_RU_6_WR_OFFSET_A_ADDR        (REG_SMU_BASE_ADDR+0x000001D8)
#define SMU_RU_6_WR_OFFSET_A_OFFSET      0x000001D8
#define SMU_RU_6_WR_OFFSET_A_INDEX       0x00000076
#define SMU_RU_6_WR_OFFSET_A_RESET       0x00000000

__INLINE uint32_t  smu_ru_6_wr_offset_a_get(void)
{
	return REG_PL_RD(SMU_RU_6_WR_OFFSET_A_ADDR);
}

__INLINE void smu_ru_6_wr_offset_a_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_6_WR_OFFSET_A_ADDR, value);
}

// field definitions
#define SMU_RU_6_WR_OFFSET_A_SS_OFFSET_MASK    ((uint32_t)0xFFFF0000)
#define SMU_RU_6_WR_OFFSET_A_SS_OFFSET_LSB    16
#define SMU_RU_6_WR_OFFSET_A_SS_OFFSET_WIDTH    ((uint32_t)0x00000010)
#define SMU_RU_6_WR_OFFSET_A_ANT_OFFSET_MASK    ((uint32_t)0x0000FFFF)
#define SMU_RU_6_WR_OFFSET_A_ANT_OFFSET_LSB    0
#define SMU_RU_6_WR_OFFSET_A_ANT_OFFSET_WIDTH    ((uint32_t)0x00000010)

#define SMU_RU_6_WR_OFFSET_A_SS_OFFSET_RST    0x0
#define SMU_RU_6_WR_OFFSET_A_ANT_OFFSET_RST    0x0

__INLINE void smu_ru_6_wr_offset_a_pack(uint16_t ss_offset, uint16_t ant_offset)
{
	ASSERT_ERR((((uint32_t)ss_offset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)ant_offset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_6_WR_OFFSET_A_ADDR,  ((uint32_t)ss_offset << 16) |((uint32_t)ant_offset << 0));
}

__INLINE void smu_ru_6_wr_offset_a_unpack(uint16_t* ss_offset, uint16_t* ant_offset)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_6_WR_OFFSET_A_ADDR);

	*ss_offset = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*ant_offset = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t smu_ru_6_wr_offset_a_ss_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_6_WR_OFFSET_A_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void smu_ru_6_wr_offset_a_ss_offset_setf(uint16_t ssoffset)
{
	ASSERT_ERR((((uint32_t)ssoffset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SMU_RU_6_WR_OFFSET_A_ADDR, (REG_PL_RD(SMU_RU_6_WR_OFFSET_A_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)ssoffset <<16));
}
__INLINE uint16_t smu_ru_6_wr_offset_a_ant_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_6_WR_OFFSET_A_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void smu_ru_6_wr_offset_a_ant_offset_setf(uint16_t antoffset)
{
	ASSERT_ERR((((uint32_t)antoffset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_6_WR_OFFSET_A_ADDR, (REG_PL_RD(SMU_RU_6_WR_OFFSET_A_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)antoffset <<0));
}

/**
 * @brief RU_6_WR_OFFSET_B register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SS_OFFSET                 0x0
 *    15:00 ANT_OFFSET                0x0
 * </pre>
 */
#define SMU_RU_6_WR_OFFSET_B_ADDR        (REG_SMU_BASE_ADDR+0x000001DC)
#define SMU_RU_6_WR_OFFSET_B_OFFSET      0x000001DC
#define SMU_RU_6_WR_OFFSET_B_INDEX       0x00000077
#define SMU_RU_6_WR_OFFSET_B_RESET       0x00000000

__INLINE uint32_t  smu_ru_6_wr_offset_b_get(void)
{
	return REG_PL_RD(SMU_RU_6_WR_OFFSET_B_ADDR);
}

__INLINE void smu_ru_6_wr_offset_b_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_6_WR_OFFSET_B_ADDR, value);
}

// field definitions
#define SMU_RU_6_WR_OFFSET_B_SS_OFFSET_MASK    ((uint32_t)0xFFFF0000)
#define SMU_RU_6_WR_OFFSET_B_SS_OFFSET_LSB    16
#define SMU_RU_6_WR_OFFSET_B_SS_OFFSET_WIDTH    ((uint32_t)0x00000010)
#define SMU_RU_6_WR_OFFSET_B_ANT_OFFSET_MASK    ((uint32_t)0x0000FFFF)
#define SMU_RU_6_WR_OFFSET_B_ANT_OFFSET_LSB    0
#define SMU_RU_6_WR_OFFSET_B_ANT_OFFSET_WIDTH    ((uint32_t)0x00000010)

#define SMU_RU_6_WR_OFFSET_B_SS_OFFSET_RST    0x0
#define SMU_RU_6_WR_OFFSET_B_ANT_OFFSET_RST    0x0

__INLINE void smu_ru_6_wr_offset_b_pack(uint16_t ss_offset, uint16_t ant_offset)
{
	ASSERT_ERR((((uint32_t)ss_offset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)ant_offset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_6_WR_OFFSET_B_ADDR,  ((uint32_t)ss_offset << 16) |((uint32_t)ant_offset << 0));
}

__INLINE void smu_ru_6_wr_offset_b_unpack(uint16_t* ss_offset, uint16_t* ant_offset)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_6_WR_OFFSET_B_ADDR);

	*ss_offset = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*ant_offset = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t smu_ru_6_wr_offset_b_ss_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_6_WR_OFFSET_B_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void smu_ru_6_wr_offset_b_ss_offset_setf(uint16_t ssoffset)
{
	ASSERT_ERR((((uint32_t)ssoffset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SMU_RU_6_WR_OFFSET_B_ADDR, (REG_PL_RD(SMU_RU_6_WR_OFFSET_B_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)ssoffset <<16));
}
__INLINE uint16_t smu_ru_6_wr_offset_b_ant_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_6_WR_OFFSET_B_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void smu_ru_6_wr_offset_b_ant_offset_setf(uint16_t antoffset)
{
	ASSERT_ERR((((uint32_t)antoffset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_6_WR_OFFSET_B_ADDR, (REG_PL_RD(SMU_RU_6_WR_OFFSET_B_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)antoffset <<0));
}

/**
 * @brief RU_7_CFG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26:24 STARTING_STS              0x0
 *    21:16 RU_INDEX                  0x0
 *    14:12 RU_TYPE                   0x0
 *    11    SMOOTH_FILTER_EN          0              
 *    10    PILOT_AV_EN               0              
 *    09:08 OUTPUT_DECIMATION         0x0
 *    07:06 NB_SC_SW_A                0x0
 *    05:04 GROUPING                  0x0
 *    03:00 NSS                       0x0
 * </pre>
 */
#define SMU_RU_7_CFG_ADDR        (REG_SMU_BASE_ADDR+0x000001E0)
#define SMU_RU_7_CFG_OFFSET      0x000001E0
#define SMU_RU_7_CFG_INDEX       0x00000078
#define SMU_RU_7_CFG_RESET       0x00000000

__INLINE uint32_t  smu_ru_7_cfg_get(void)
{
	return REG_PL_RD(SMU_RU_7_CFG_ADDR);
}

__INLINE void smu_ru_7_cfg_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_7_CFG_ADDR, value);
}

// field definitions
#define SMU_RU_7_CFG_STARTING_STS_MASK      ((uint32_t)0x07000000)
#define SMU_RU_7_CFG_STARTING_STS_LSB       24
#define SMU_RU_7_CFG_STARTING_STS_WIDTH     ((uint32_t)0x00000003)
#define SMU_RU_7_CFG_RU_INDEX_MASK          ((uint32_t)0x003F0000)
#define SMU_RU_7_CFG_RU_INDEX_LSB           16
#define SMU_RU_7_CFG_RU_INDEX_WIDTH         ((uint32_t)0x00000006)
#define SMU_RU_7_CFG_RU_TYPE_MASK           ((uint32_t)0x00007000)
#define SMU_RU_7_CFG_RU_TYPE_LSB            12
#define SMU_RU_7_CFG_RU_TYPE_WIDTH          ((uint32_t)0x00000003)
#define SMU_RU_7_CFG_SMOOTH_FILTER_EN_BIT    ((uint32_t)0x00000800)
#define SMU_RU_7_CFG_SMOOTH_FILTER_EN_POS    11
#define SMU_RU_7_CFG_PILOT_AV_EN_BIT        ((uint32_t)0x00000400)
#define SMU_RU_7_CFG_PILOT_AV_EN_POS        10
#define SMU_RU_7_CFG_OUTPUT_DECIMATION_MASK    ((uint32_t)0x00000300)
#define SMU_RU_7_CFG_OUTPUT_DECIMATION_LSB    8
#define SMU_RU_7_CFG_OUTPUT_DECIMATION_WIDTH    ((uint32_t)0x00000002)
#define SMU_RU_7_CFG_NB_SC_SW_A_MASK        ((uint32_t)0x000000C0)
#define SMU_RU_7_CFG_NB_SC_SW_A_LSB         6
#define SMU_RU_7_CFG_NB_SC_SW_A_WIDTH       ((uint32_t)0x00000002)
#define SMU_RU_7_CFG_GROUPING_MASK          ((uint32_t)0x00000030)
#define SMU_RU_7_CFG_GROUPING_LSB           4
#define SMU_RU_7_CFG_GROUPING_WIDTH         ((uint32_t)0x00000002)
#define SMU_RU_7_CFG_NSS_MASK               ((uint32_t)0x0000000F)
#define SMU_RU_7_CFG_NSS_LSB                0
#define SMU_RU_7_CFG_NSS_WIDTH              ((uint32_t)0x00000004)

#define SMU_RU_7_CFG_STARTING_STS_RST       0x0
#define SMU_RU_7_CFG_RU_INDEX_RST           0x0
#define SMU_RU_7_CFG_RU_TYPE_RST            0x0
#define SMU_RU_7_CFG_SMOOTH_FILTER_EN_RST    0x0
#define SMU_RU_7_CFG_PILOT_AV_EN_RST        0x0
#define SMU_RU_7_CFG_OUTPUT_DECIMATION_RST    0x0
#define SMU_RU_7_CFG_NB_SC_SW_A_RST         0x0
#define SMU_RU_7_CFG_GROUPING_RST           0x0
#define SMU_RU_7_CFG_NSS_RST                0x0

__INLINE void smu_ru_7_cfg_pack(uint8_t starting_sts, uint8_t ru_index, uint8_t ru_type, uint8_t smooth_filter_en, uint8_t pilot_av_en, uint8_t output_decimation, uint8_t nb_sc_sw_a, uint8_t grouping, uint8_t nss)
{
	ASSERT_ERR((((uint32_t)starting_sts << 24) & ~((uint32_t)0x07000000)) == 0);
	ASSERT_ERR((((uint32_t)ru_index << 16) & ~((uint32_t)0x003F0000)) == 0);
	ASSERT_ERR((((uint32_t)ru_type << 12) & ~((uint32_t)0x00007000)) == 0);
	ASSERT_ERR((((uint32_t)smooth_filter_en << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)pilot_av_en << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)output_decimation << 8) & ~((uint32_t)0x00000300)) == 0);
	ASSERT_ERR((((uint32_t)nb_sc_sw_a << 6) & ~((uint32_t)0x000000C0)) == 0);
	ASSERT_ERR((((uint32_t)grouping << 4) & ~((uint32_t)0x00000030)) == 0);
	ASSERT_ERR((((uint32_t)nss << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(SMU_RU_7_CFG_ADDR,  ((uint32_t)starting_sts << 24) |((uint32_t)ru_index << 16) |((uint32_t)ru_type << 12) |((uint32_t)smooth_filter_en << 11) |((uint32_t)pilot_av_en << 10) |((uint32_t)output_decimation << 8) |((uint32_t)nb_sc_sw_a << 6) |((uint32_t)grouping << 4) |((uint32_t)nss << 0));
}

__INLINE void smu_ru_7_cfg_unpack(uint8_t* starting_sts, uint8_t* ru_index, uint8_t* ru_type, uint8_t* smooth_filter_en, uint8_t* pilot_av_en, uint8_t* output_decimation, uint8_t* nb_sc_sw_a, uint8_t* grouping, uint8_t* nss)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_7_CFG_ADDR);

	*starting_sts = (localVal & ((uint32_t)0x07000000)) >>  24;
	*ru_index = (localVal & ((uint32_t)0x003F0000)) >>  16;
	*ru_type = (localVal & ((uint32_t)0x00007000)) >>  12;
	*smooth_filter_en = (localVal & ((uint32_t)0x00000800)) >>  11;
	*pilot_av_en = (localVal & ((uint32_t)0x00000400)) >>  10;
	*output_decimation = (localVal & ((uint32_t)0x00000300)) >>  8;
	*nb_sc_sw_a = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*grouping = (localVal & ((uint32_t)0x00000030)) >>  4;
	*nss = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t smu_ru_7_cfg_starting_sts_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_7_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE void smu_ru_7_cfg_starting_sts_setf(uint8_t startingsts)
{
	ASSERT_ERR((((uint32_t)startingsts << 24) & ~((uint32_t)0x07000000)) == 0);
	REG_PL_WR(SMU_RU_7_CFG_ADDR, (REG_PL_RD(SMU_RU_7_CFG_ADDR) & ~((uint32_t)0x07000000)) | ((uint32_t)startingsts <<24));
}
__INLINE uint8_t smu_ru_7_cfg_ru_index_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_7_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x003F0000)) >> 16);
}
__INLINE void smu_ru_7_cfg_ru_index_setf(uint8_t ruindex)
{
	ASSERT_ERR((((uint32_t)ruindex << 16) & ~((uint32_t)0x003F0000)) == 0);
	REG_PL_WR(SMU_RU_7_CFG_ADDR, (REG_PL_RD(SMU_RU_7_CFG_ADDR) & ~((uint32_t)0x003F0000)) | ((uint32_t)ruindex <<16));
}
__INLINE uint8_t smu_ru_7_cfg_ru_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_7_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007000)) >> 12);
}
__INLINE void smu_ru_7_cfg_ru_type_setf(uint8_t rutype)
{
	ASSERT_ERR((((uint32_t)rutype << 12) & ~((uint32_t)0x00007000)) == 0);
	REG_PL_WR(SMU_RU_7_CFG_ADDR, (REG_PL_RD(SMU_RU_7_CFG_ADDR) & ~((uint32_t)0x00007000)) | ((uint32_t)rutype <<12));
}
__INLINE uint8_t smu_ru_7_cfg_smooth_filter_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_7_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void smu_ru_7_cfg_smooth_filter_en_setf(uint8_t smoothfilteren)
{
	ASSERT_ERR((((uint32_t)smoothfilteren << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(SMU_RU_7_CFG_ADDR, (REG_PL_RD(SMU_RU_7_CFG_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)smoothfilteren <<11));
}
__INLINE uint8_t smu_ru_7_cfg_pilot_av_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_7_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void smu_ru_7_cfg_pilot_av_en_setf(uint8_t pilotaven)
{
	ASSERT_ERR((((uint32_t)pilotaven << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(SMU_RU_7_CFG_ADDR, (REG_PL_RD(SMU_RU_7_CFG_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)pilotaven <<10));
}
__INLINE uint8_t smu_ru_7_cfg_output_decimation_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_7_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000300)) >> 8);
}
__INLINE void smu_ru_7_cfg_output_decimation_setf(uint8_t outputdecimation)
{
	ASSERT_ERR((((uint32_t)outputdecimation << 8) & ~((uint32_t)0x00000300)) == 0);
	REG_PL_WR(SMU_RU_7_CFG_ADDR, (REG_PL_RD(SMU_RU_7_CFG_ADDR) & ~((uint32_t)0x00000300)) | ((uint32_t)outputdecimation <<8));
}
__INLINE uint8_t smu_ru_7_cfg_nb_sc_sw_a_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_7_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE void smu_ru_7_cfg_nb_sc_sw_a_setf(uint8_t nbscswa)
{
	ASSERT_ERR((((uint32_t)nbscswa << 6) & ~((uint32_t)0x000000C0)) == 0);
	REG_PL_WR(SMU_RU_7_CFG_ADDR, (REG_PL_RD(SMU_RU_7_CFG_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)nbscswa <<6));
}
__INLINE uint8_t smu_ru_7_cfg_grouping_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_7_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000030)) >> 4);
}
__INLINE void smu_ru_7_cfg_grouping_setf(uint8_t grouping)
{
	ASSERT_ERR((((uint32_t)grouping << 4) & ~((uint32_t)0x00000030)) == 0);
	REG_PL_WR(SMU_RU_7_CFG_ADDR, (REG_PL_RD(SMU_RU_7_CFG_ADDR) & ~((uint32_t)0x00000030)) | ((uint32_t)grouping <<4));
}
__INLINE uint8_t smu_ru_7_cfg_nss_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_7_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void smu_ru_7_cfg_nss_setf(uint8_t nss)
{
	ASSERT_ERR((((uint32_t)nss << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(SMU_RU_7_CFG_ADDR, (REG_PL_RD(SMU_RU_7_CFG_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)nss <<0));
}

/**
 * @brief RU_7_FILTER_PTR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 FILTER_PTR                0x0
 * </pre>
 */
#define SMU_RU_7_FILTER_PTR_ADDR        (REG_SMU_BASE_ADDR+0x000001E4)
#define SMU_RU_7_FILTER_PTR_OFFSET      0x000001E4
#define SMU_RU_7_FILTER_PTR_INDEX       0x00000079
#define SMU_RU_7_FILTER_PTR_RESET       0x00000000

__INLINE uint32_t  smu_ru_7_filter_ptr_get(void)
{
	return REG_PL_RD(SMU_RU_7_FILTER_PTR_ADDR);
}

__INLINE void smu_ru_7_filter_ptr_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_7_FILTER_PTR_ADDR, value);
}

// field definitions
#define SMU_RU_7_FILTER_PTR_FILTER_PTR_MASK    ((uint32_t)0xFFFFFFFF)
#define SMU_RU_7_FILTER_PTR_FILTER_PTR_LSB    0
#define SMU_RU_7_FILTER_PTR_FILTER_PTR_WIDTH    ((uint32_t)0x00000020)

#define SMU_RU_7_FILTER_PTR_FILTER_PTR_RST    0x0

__INLINE uint32_t smu_ru_7_filter_ptr_filter_ptr_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_7_FILTER_PTR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void smu_ru_7_filter_ptr_filter_ptr_setf(uint32_t filterptr)
{
	ASSERT_ERR((((uint32_t)filterptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SMU_RU_7_FILTER_PTR_ADDR, (uint32_t)filterptr << 0);
}

/**
 * @brief RU_7_DATA_RD_PTR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DATA_RD_PTR               0x0
 * </pre>
 */
#define SMU_RU_7_DATA_RD_PTR_ADDR        (REG_SMU_BASE_ADDR+0x000001E8)
#define SMU_RU_7_DATA_RD_PTR_OFFSET      0x000001E8
#define SMU_RU_7_DATA_RD_PTR_INDEX       0x0000007A
#define SMU_RU_7_DATA_RD_PTR_RESET       0x00000000

__INLINE uint32_t  smu_ru_7_data_rd_ptr_get(void)
{
	return REG_PL_RD(SMU_RU_7_DATA_RD_PTR_ADDR);
}

__INLINE void smu_ru_7_data_rd_ptr_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_7_DATA_RD_PTR_ADDR, value);
}

// field definitions
#define SMU_RU_7_DATA_RD_PTR_DATA_RD_PTR_MASK    ((uint32_t)0xFFFFFFFF)
#define SMU_RU_7_DATA_RD_PTR_DATA_RD_PTR_LSB    0
#define SMU_RU_7_DATA_RD_PTR_DATA_RD_PTR_WIDTH    ((uint32_t)0x00000020)

#define SMU_RU_7_DATA_RD_PTR_DATA_RD_PTR_RST    0x0

__INLINE uint32_t smu_ru_7_data_rd_ptr_data_rd_ptr_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_7_DATA_RD_PTR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void smu_ru_7_data_rd_ptr_data_rd_ptr_setf(uint32_t datardptr)
{
	ASSERT_ERR((((uint32_t)datardptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SMU_RU_7_DATA_RD_PTR_ADDR, (uint32_t)datardptr << 0);
}

/**
 * @brief RU_7_RD_OFFSET register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SS_OFFSET                 0x0
 *    15:00 ANT_OFFSET                0x0
 * </pre>
 */
#define SMU_RU_7_RD_OFFSET_ADDR        (REG_SMU_BASE_ADDR+0x000001EC)
#define SMU_RU_7_RD_OFFSET_OFFSET      0x000001EC
#define SMU_RU_7_RD_OFFSET_INDEX       0x0000007B
#define SMU_RU_7_RD_OFFSET_RESET       0x00000000

__INLINE uint32_t  smu_ru_7_rd_offset_get(void)
{
	return REG_PL_RD(SMU_RU_7_RD_OFFSET_ADDR);
}

__INLINE void smu_ru_7_rd_offset_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_7_RD_OFFSET_ADDR, value);
}

// field definitions
#define SMU_RU_7_RD_OFFSET_SS_OFFSET_MASK    ((uint32_t)0xFFFF0000)
#define SMU_RU_7_RD_OFFSET_SS_OFFSET_LSB    16
#define SMU_RU_7_RD_OFFSET_SS_OFFSET_WIDTH    ((uint32_t)0x00000010)
#define SMU_RU_7_RD_OFFSET_ANT_OFFSET_MASK    ((uint32_t)0x0000FFFF)
#define SMU_RU_7_RD_OFFSET_ANT_OFFSET_LSB    0
#define SMU_RU_7_RD_OFFSET_ANT_OFFSET_WIDTH    ((uint32_t)0x00000010)

#define SMU_RU_7_RD_OFFSET_SS_OFFSET_RST    0x0
#define SMU_RU_7_RD_OFFSET_ANT_OFFSET_RST    0x0

__INLINE void smu_ru_7_rd_offset_pack(uint16_t ss_offset, uint16_t ant_offset)
{
	ASSERT_ERR((((uint32_t)ss_offset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)ant_offset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_7_RD_OFFSET_ADDR,  ((uint32_t)ss_offset << 16) |((uint32_t)ant_offset << 0));
}

__INLINE void smu_ru_7_rd_offset_unpack(uint16_t* ss_offset, uint16_t* ant_offset)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_7_RD_OFFSET_ADDR);

	*ss_offset = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*ant_offset = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t smu_ru_7_rd_offset_ss_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_7_RD_OFFSET_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void smu_ru_7_rd_offset_ss_offset_setf(uint16_t ssoffset)
{
	ASSERT_ERR((((uint32_t)ssoffset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SMU_RU_7_RD_OFFSET_ADDR, (REG_PL_RD(SMU_RU_7_RD_OFFSET_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)ssoffset <<16));
}
__INLINE uint16_t smu_ru_7_rd_offset_ant_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_7_RD_OFFSET_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void smu_ru_7_rd_offset_ant_offset_setf(uint16_t antoffset)
{
	ASSERT_ERR((((uint32_t)antoffset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_7_RD_OFFSET_ADDR, (REG_PL_RD(SMU_RU_7_RD_OFFSET_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)antoffset <<0));
}

/**
 * @brief RU_7_DATA_WR_PTR_A register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DATA_WR_PTR_A             0x0
 * </pre>
 */
#define SMU_RU_7_DATA_WR_PTR_A_ADDR        (REG_SMU_BASE_ADDR+0x000001F0)
#define SMU_RU_7_DATA_WR_PTR_A_OFFSET      0x000001F0
#define SMU_RU_7_DATA_WR_PTR_A_INDEX       0x0000007C
#define SMU_RU_7_DATA_WR_PTR_A_RESET       0x00000000

__INLINE uint32_t  smu_ru_7_data_wr_ptr_a_get(void)
{
	return REG_PL_RD(SMU_RU_7_DATA_WR_PTR_A_ADDR);
}

__INLINE void smu_ru_7_data_wr_ptr_a_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_7_DATA_WR_PTR_A_ADDR, value);
}

// field definitions
#define SMU_RU_7_DATA_WR_PTR_A_DATA_WR_PTR_A_MASK    ((uint32_t)0xFFFFFFFF)
#define SMU_RU_7_DATA_WR_PTR_A_DATA_WR_PTR_A_LSB    0
#define SMU_RU_7_DATA_WR_PTR_A_DATA_WR_PTR_A_WIDTH    ((uint32_t)0x00000020)

#define SMU_RU_7_DATA_WR_PTR_A_DATA_WR_PTR_A_RST    0x0

__INLINE uint32_t smu_ru_7_data_wr_ptr_a_data_wr_ptr_a_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_7_DATA_WR_PTR_A_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void smu_ru_7_data_wr_ptr_a_data_wr_ptr_a_setf(uint32_t datawrptra)
{
	ASSERT_ERR((((uint32_t)datawrptra << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SMU_RU_7_DATA_WR_PTR_A_ADDR, (uint32_t)datawrptra << 0);
}

/**
 * @brief RU_7_DATA_WR_PTR_B register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DATA_WR_PTR_B             0x0
 * </pre>
 */
#define SMU_RU_7_DATA_WR_PTR_B_ADDR        (REG_SMU_BASE_ADDR+0x000001F4)
#define SMU_RU_7_DATA_WR_PTR_B_OFFSET      0x000001F4
#define SMU_RU_7_DATA_WR_PTR_B_INDEX       0x0000007D
#define SMU_RU_7_DATA_WR_PTR_B_RESET       0x00000000

__INLINE uint32_t  smu_ru_7_data_wr_ptr_b_get(void)
{
	return REG_PL_RD(SMU_RU_7_DATA_WR_PTR_B_ADDR);
}

__INLINE void smu_ru_7_data_wr_ptr_b_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_7_DATA_WR_PTR_B_ADDR, value);
}

// field definitions
#define SMU_RU_7_DATA_WR_PTR_B_DATA_WR_PTR_B_MASK    ((uint32_t)0xFFFFFFFF)
#define SMU_RU_7_DATA_WR_PTR_B_DATA_WR_PTR_B_LSB    0
#define SMU_RU_7_DATA_WR_PTR_B_DATA_WR_PTR_B_WIDTH    ((uint32_t)0x00000020)

#define SMU_RU_7_DATA_WR_PTR_B_DATA_WR_PTR_B_RST    0x0

__INLINE uint32_t smu_ru_7_data_wr_ptr_b_data_wr_ptr_b_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_7_DATA_WR_PTR_B_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void smu_ru_7_data_wr_ptr_b_data_wr_ptr_b_setf(uint32_t datawrptrb)
{
	ASSERT_ERR((((uint32_t)datawrptrb << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SMU_RU_7_DATA_WR_PTR_B_ADDR, (uint32_t)datawrptrb << 0);
}

/**
 * @brief RU_7_WR_OFFSET_A register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SS_OFFSET                 0x0
 *    15:00 ANT_OFFSET                0x0
 * </pre>
 */
#define SMU_RU_7_WR_OFFSET_A_ADDR        (REG_SMU_BASE_ADDR+0x000001F8)
#define SMU_RU_7_WR_OFFSET_A_OFFSET      0x000001F8
#define SMU_RU_7_WR_OFFSET_A_INDEX       0x0000007E
#define SMU_RU_7_WR_OFFSET_A_RESET       0x00000000

__INLINE uint32_t  smu_ru_7_wr_offset_a_get(void)
{
	return REG_PL_RD(SMU_RU_7_WR_OFFSET_A_ADDR);
}

__INLINE void smu_ru_7_wr_offset_a_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_7_WR_OFFSET_A_ADDR, value);
}

// field definitions
#define SMU_RU_7_WR_OFFSET_A_SS_OFFSET_MASK    ((uint32_t)0xFFFF0000)
#define SMU_RU_7_WR_OFFSET_A_SS_OFFSET_LSB    16
#define SMU_RU_7_WR_OFFSET_A_SS_OFFSET_WIDTH    ((uint32_t)0x00000010)
#define SMU_RU_7_WR_OFFSET_A_ANT_OFFSET_MASK    ((uint32_t)0x0000FFFF)
#define SMU_RU_7_WR_OFFSET_A_ANT_OFFSET_LSB    0
#define SMU_RU_7_WR_OFFSET_A_ANT_OFFSET_WIDTH    ((uint32_t)0x00000010)

#define SMU_RU_7_WR_OFFSET_A_SS_OFFSET_RST    0x0
#define SMU_RU_7_WR_OFFSET_A_ANT_OFFSET_RST    0x0

__INLINE void smu_ru_7_wr_offset_a_pack(uint16_t ss_offset, uint16_t ant_offset)
{
	ASSERT_ERR((((uint32_t)ss_offset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)ant_offset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_7_WR_OFFSET_A_ADDR,  ((uint32_t)ss_offset << 16) |((uint32_t)ant_offset << 0));
}

__INLINE void smu_ru_7_wr_offset_a_unpack(uint16_t* ss_offset, uint16_t* ant_offset)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_7_WR_OFFSET_A_ADDR);

	*ss_offset = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*ant_offset = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t smu_ru_7_wr_offset_a_ss_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_7_WR_OFFSET_A_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void smu_ru_7_wr_offset_a_ss_offset_setf(uint16_t ssoffset)
{
	ASSERT_ERR((((uint32_t)ssoffset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SMU_RU_7_WR_OFFSET_A_ADDR, (REG_PL_RD(SMU_RU_7_WR_OFFSET_A_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)ssoffset <<16));
}
__INLINE uint16_t smu_ru_7_wr_offset_a_ant_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_7_WR_OFFSET_A_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void smu_ru_7_wr_offset_a_ant_offset_setf(uint16_t antoffset)
{
	ASSERT_ERR((((uint32_t)antoffset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_7_WR_OFFSET_A_ADDR, (REG_PL_RD(SMU_RU_7_WR_OFFSET_A_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)antoffset <<0));
}

/**
 * @brief RU_7_WR_OFFSET_B register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SS_OFFSET                 0x0
 *    15:00 ANT_OFFSET                0x0
 * </pre>
 */
#define SMU_RU_7_WR_OFFSET_B_ADDR        (REG_SMU_BASE_ADDR+0x000001FC)
#define SMU_RU_7_WR_OFFSET_B_OFFSET      0x000001FC
#define SMU_RU_7_WR_OFFSET_B_INDEX       0x0000007F
#define SMU_RU_7_WR_OFFSET_B_RESET       0x00000000

__INLINE uint32_t  smu_ru_7_wr_offset_b_get(void)
{
	return REG_PL_RD(SMU_RU_7_WR_OFFSET_B_ADDR);
}

__INLINE void smu_ru_7_wr_offset_b_set(uint32_t value)
{
	REG_PL_WR(SMU_RU_7_WR_OFFSET_B_ADDR, value);
}

// field definitions
#define SMU_RU_7_WR_OFFSET_B_SS_OFFSET_MASK    ((uint32_t)0xFFFF0000)
#define SMU_RU_7_WR_OFFSET_B_SS_OFFSET_LSB    16
#define SMU_RU_7_WR_OFFSET_B_SS_OFFSET_WIDTH    ((uint32_t)0x00000010)
#define SMU_RU_7_WR_OFFSET_B_ANT_OFFSET_MASK    ((uint32_t)0x0000FFFF)
#define SMU_RU_7_WR_OFFSET_B_ANT_OFFSET_LSB    0
#define SMU_RU_7_WR_OFFSET_B_ANT_OFFSET_WIDTH    ((uint32_t)0x00000010)

#define SMU_RU_7_WR_OFFSET_B_SS_OFFSET_RST    0x0
#define SMU_RU_7_WR_OFFSET_B_ANT_OFFSET_RST    0x0

__INLINE void smu_ru_7_wr_offset_b_pack(uint16_t ss_offset, uint16_t ant_offset)
{
	ASSERT_ERR((((uint32_t)ss_offset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)ant_offset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_7_WR_OFFSET_B_ADDR,  ((uint32_t)ss_offset << 16) |((uint32_t)ant_offset << 0));
}

__INLINE void smu_ru_7_wr_offset_b_unpack(uint16_t* ss_offset, uint16_t* ant_offset)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_7_WR_OFFSET_B_ADDR);

	*ss_offset = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*ant_offset = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t smu_ru_7_wr_offset_b_ss_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_7_WR_OFFSET_B_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void smu_ru_7_wr_offset_b_ss_offset_setf(uint16_t ssoffset)
{
	ASSERT_ERR((((uint32_t)ssoffset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SMU_RU_7_WR_OFFSET_B_ADDR, (REG_PL_RD(SMU_RU_7_WR_OFFSET_B_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)ssoffset <<16));
}
__INLINE uint16_t smu_ru_7_wr_offset_b_ant_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SMU_RU_7_WR_OFFSET_B_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void smu_ru_7_wr_offset_b_ant_offset_setf(uint16_t antoffset)
{
	ASSERT_ERR((((uint32_t)antoffset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SMU_RU_7_WR_OFFSET_B_ADDR, (REG_PL_RD(SMU_RU_7_WR_OFFSET_B_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)antoffset <<0));
}


#undef DBG_FILEID
#endif //_REG_SMU_H_

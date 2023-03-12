#ifndef _REG_EPA_H_
#define _REG_EPA_H_

#include <stdint.h>
#include "phy/_reg_epa.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define DBG_FILEID __REG_EPA__H__FILEID__

#define REG_EPA_COUNT  10


/**
 * @brief SYSTEM_CFG register definition
 *  This is a system configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    12:08 Nb_SC                     0x0
 *    06:04 Nc                        0x0
 *    02:00 Nr                        0x0
 * </pre>
 */
#define EPA_SYSTEM_CFG_ADDR        (REG_EPA_BASE_ADDR+0x00000000)
#define EPA_SYSTEM_CFG_OFFSET      0x00000000
#define EPA_SYSTEM_CFG_INDEX       0x00000000
#define EPA_SYSTEM_CFG_RESET       0x00000000

__INLINE uint32_t  epa_system_cfg_get(void)
{
	return REG_PL_RD(EPA_SYSTEM_CFG_ADDR);
}

__INLINE void epa_system_cfg_set(uint32_t value)
{
	REG_PL_WR(EPA_SYSTEM_CFG_ADDR, value);
}

// field definitions
#define EPA_SYSTEM_CFG_NB_SC_MASK           ((uint32_t)0x00001F00)
#define EPA_SYSTEM_CFG_NB_SC_LSB            8
#define EPA_SYSTEM_CFG_NB_SC_WIDTH          ((uint32_t)0x00000005)
#define EPA_SYSTEM_CFG_NC_MASK              ((uint32_t)0x00000070)
#define EPA_SYSTEM_CFG_NC_LSB               4
#define EPA_SYSTEM_CFG_NC_WIDTH             ((uint32_t)0x00000003)
#define EPA_SYSTEM_CFG_NR_MASK              ((uint32_t)0x00000007)
#define EPA_SYSTEM_CFG_NR_LSB               0
#define EPA_SYSTEM_CFG_NR_WIDTH             ((uint32_t)0x00000003)

#define EPA_SYSTEM_CFG_NB_SC_RST            0x0
#define EPA_SYSTEM_CFG_NC_RST               0x0
#define EPA_SYSTEM_CFG_NR_RST               0x0

__INLINE void epa_system_cfg_pack(uint8_t nb_sc, uint8_t nc, uint8_t nr)
{
	ASSERT_ERR((((uint32_t)nb_sc << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)nc << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)nr << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(EPA_SYSTEM_CFG_ADDR,  ((uint32_t)nb_sc << 8) |((uint32_t)nc << 4) |((uint32_t)nr << 0));
}

__INLINE void epa_system_cfg_unpack(uint8_t* nb_sc, uint8_t* nc, uint8_t* nr)
{
	uint32_t localVal = REG_PL_RD(EPA_SYSTEM_CFG_ADDR);

	*nb_sc = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*nc = (localVal & ((uint32_t)0x00000070)) >>  4;
	*nr = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t epa_system_cfg_nb_sc_getf(void)
{
	uint32_t localVal = REG_PL_RD(EPA_SYSTEM_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void epa_system_cfg_nb_sc_setf(uint8_t nbsc)
{
	ASSERT_ERR((((uint32_t)nbsc << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(EPA_SYSTEM_CFG_ADDR, (REG_PL_RD(EPA_SYSTEM_CFG_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)nbsc <<8));
}
__INLINE uint8_t epa_system_cfg_nc_getf(void)
{
	uint32_t localVal = REG_PL_RD(EPA_SYSTEM_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void epa_system_cfg_nc_setf(uint8_t nc)
{
	ASSERT_ERR((((uint32_t)nc << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(EPA_SYSTEM_CFG_ADDR, (REG_PL_RD(EPA_SYSTEM_CFG_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)nc <<4));
}
__INLINE uint8_t epa_system_cfg_nr_getf(void)
{
	uint32_t localVal = REG_PL_RD(EPA_SYSTEM_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void epa_system_cfg_nr_setf(uint8_t nr)
{
	ASSERT_ERR((((uint32_t)nr << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(EPA_SYSTEM_CFG_ADDR, (REG_PL_RD(EPA_SYSTEM_CFG_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)nr <<0));
}

/**
 * @brief EPA_CONTROL register definition
 *  Enable and Pause controls register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01    PAUSE                     0              
 *    00    ENABLE                    0              
 * </pre>
 */
#define EPA_EPA_CONTROL_ADDR        (REG_EPA_BASE_ADDR+0x00000004)
#define EPA_EPA_CONTROL_OFFSET      0x00000004
#define EPA_EPA_CONTROL_INDEX       0x00000001
#define EPA_EPA_CONTROL_RESET       0x00000000

__INLINE uint32_t  epa_epa_control_get(void)
{
	return REG_PL_RD(EPA_EPA_CONTROL_ADDR);
}

__INLINE void epa_epa_control_set(uint32_t value)
{
	REG_PL_WR(EPA_EPA_CONTROL_ADDR, value);
}

// field definitions
#define EPA_EPA_CONTROL_PAUSE_BIT           ((uint32_t)0x00000002)
#define EPA_EPA_CONTROL_PAUSE_POS           1
#define EPA_EPA_CONTROL_ENABLE_BIT          ((uint32_t)0x00000001)
#define EPA_EPA_CONTROL_ENABLE_POS          0

#define EPA_EPA_CONTROL_PAUSE_RST           0x0
#define EPA_EPA_CONTROL_ENABLE_RST          0x0

__INLINE void epa_epa_control_pack(uint8_t pause, uint8_t enable)
{
	ASSERT_ERR((((uint32_t)pause << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)enable << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(EPA_EPA_CONTROL_ADDR,  ((uint32_t)pause << 1) |((uint32_t)enable << 0));
}

__INLINE void epa_epa_control_unpack(uint8_t* pause, uint8_t* enable)
{
	uint32_t localVal = REG_PL_RD(EPA_EPA_CONTROL_ADDR);

	*pause = (localVal & ((uint32_t)0x00000002)) >>  1;
	*enable = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t epa_epa_control_pause_getf(void)
{
	uint32_t localVal = REG_PL_RD(EPA_EPA_CONTROL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void epa_epa_control_pause_setf(uint8_t pause)
{
	ASSERT_ERR((((uint32_t)pause << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(EPA_EPA_CONTROL_ADDR, (REG_PL_RD(EPA_EPA_CONTROL_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)pause <<1));
}
__INLINE uint8_t epa_epa_control_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(EPA_EPA_CONTROL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void epa_epa_control_enable_setf(uint8_t enable)
{
	ASSERT_ERR((((uint32_t)enable << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(EPA_EPA_CONTROL_ADDR, (REG_PL_RD(EPA_EPA_CONTROL_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)enable <<0));
}

/**
 * @brief CLK_GATE_CFG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    09:02 CLK_GATE_DLY              0x10
 *    01    FORCE_FIC_ISOLATION       1              
 *    00    CLK_GATE_EN               1              
 * </pre>
 */
#define EPA_CLK_GATE_CFG_ADDR        (REG_EPA_BASE_ADDR+0x00000008)
#define EPA_CLK_GATE_CFG_OFFSET      0x00000008
#define EPA_CLK_GATE_CFG_INDEX       0x00000002
#define EPA_CLK_GATE_CFG_RESET       0x00000043

__INLINE uint32_t  epa_clk_gate_cfg_get(void)
{
	return REG_PL_RD(EPA_CLK_GATE_CFG_ADDR);
}

__INLINE void epa_clk_gate_cfg_set(uint32_t value)
{
	REG_PL_WR(EPA_CLK_GATE_CFG_ADDR, value);
}

// field definitions
#define EPA_CLK_GATE_CFG_CLK_GATE_DLY_MASK    ((uint32_t)0x000003FC)
#define EPA_CLK_GATE_CFG_CLK_GATE_DLY_LSB    2
#define EPA_CLK_GATE_CFG_CLK_GATE_DLY_WIDTH    ((uint32_t)0x00000008)
#define EPA_CLK_GATE_CFG_FORCE_FIC_ISOLATION_BIT    ((uint32_t)0x00000002)
#define EPA_CLK_GATE_CFG_FORCE_FIC_ISOLATION_POS    1
#define EPA_CLK_GATE_CFG_CLK_GATE_EN_BIT    ((uint32_t)0x00000001)
#define EPA_CLK_GATE_CFG_CLK_GATE_EN_POS    0

#define EPA_CLK_GATE_CFG_CLK_GATE_DLY_RST    0x10
#define EPA_CLK_GATE_CFG_FORCE_FIC_ISOLATION_RST    0x1
#define EPA_CLK_GATE_CFG_CLK_GATE_EN_RST    0x1

__INLINE void epa_clk_gate_cfg_pack(uint8_t clk_gate_dly, uint8_t force_fic_isolation, uint8_t clk_gate_en)
{
	ASSERT_ERR((((uint32_t)clk_gate_dly << 2) & ~((uint32_t)0x000003FC)) == 0);
	ASSERT_ERR((((uint32_t)force_fic_isolation << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)clk_gate_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(EPA_CLK_GATE_CFG_ADDR,  ((uint32_t)clk_gate_dly << 2) |((uint32_t)force_fic_isolation << 1) |((uint32_t)clk_gate_en << 0));
}

__INLINE void epa_clk_gate_cfg_unpack(uint8_t* clk_gate_dly, uint8_t* force_fic_isolation, uint8_t* clk_gate_en)
{
	uint32_t localVal = REG_PL_RD(EPA_CLK_GATE_CFG_ADDR);

	*clk_gate_dly = (localVal & ((uint32_t)0x000003FC)) >>  2;
	*force_fic_isolation = (localVal & ((uint32_t)0x00000002)) >>  1;
	*clk_gate_en = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t epa_clk_gate_cfg_clk_gate_dly_getf(void)
{
	uint32_t localVal = REG_PL_RD(EPA_CLK_GATE_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000003FC)) >> 2);
}
__INLINE void epa_clk_gate_cfg_clk_gate_dly_setf(uint8_t clkgatedly)
{
	ASSERT_ERR((((uint32_t)clkgatedly << 2) & ~((uint32_t)0x000003FC)) == 0);
	REG_PL_WR(EPA_CLK_GATE_CFG_ADDR, (REG_PL_RD(EPA_CLK_GATE_CFG_ADDR) & ~((uint32_t)0x000003FC)) | ((uint32_t)clkgatedly <<2));
}
__INLINE uint8_t epa_clk_gate_cfg_force_fic_isolation_getf(void)
{
	uint32_t localVal = REG_PL_RD(EPA_CLK_GATE_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void epa_clk_gate_cfg_force_fic_isolation_setf(uint8_t forceficisolation)
{
	ASSERT_ERR((((uint32_t)forceficisolation << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(EPA_CLK_GATE_CFG_ADDR, (REG_PL_RD(EPA_CLK_GATE_CFG_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)forceficisolation <<1));
}
__INLINE uint8_t epa_clk_gate_cfg_clk_gate_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(EPA_CLK_GATE_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void epa_clk_gate_cfg_clk_gate_en_setf(uint8_t clkgateen)
{
	ASSERT_ERR((((uint32_t)clkgateen << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(EPA_CLK_GATE_CFG_ADDR, (REG_PL_RD(EPA_CLK_GATE_CFG_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)clkgateen <<0));
}

/**
 * @brief EPA_STATUS register definition
 *  EPA controller status, current col info register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    04:03 Current_Col               0x0
 *    02:00 CTRL_STATE                0x0
 * </pre>
 */
#define EPA_EPA_STATUS_ADDR        (REG_EPA_BASE_ADDR+0x00000010)
#define EPA_EPA_STATUS_OFFSET      0x00000010
#define EPA_EPA_STATUS_INDEX       0x00000004
#define EPA_EPA_STATUS_RESET       0x00000000

__INLINE uint32_t  epa_epa_status_get(void)
{
	return REG_PL_RD(EPA_EPA_STATUS_ADDR);
}

// field definitions
#define EPA_EPA_STATUS_CURRENT_COL_MASK     ((uint32_t)0x00000018)
#define EPA_EPA_STATUS_CURRENT_COL_LSB      3
#define EPA_EPA_STATUS_CURRENT_COL_WIDTH    ((uint32_t)0x00000002)
#define EPA_EPA_STATUS_CTRL_STATE_MASK      ((uint32_t)0x00000007)
#define EPA_EPA_STATUS_CTRL_STATE_LSB       0
#define EPA_EPA_STATUS_CTRL_STATE_WIDTH     ((uint32_t)0x00000003)

#define EPA_EPA_STATUS_CURRENT_COL_RST      0x0
#define EPA_EPA_STATUS_CTRL_STATE_RST       0x0

__INLINE void epa_epa_status_unpack(uint8_t* current_col, uint8_t* ctrl_state)
{
	uint32_t localVal = REG_PL_RD(EPA_EPA_STATUS_ADDR);

	*current_col = (localVal & ((uint32_t)0x00000018)) >>  3;
	*ctrl_state = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t epa_epa_status_current_col_getf(void)
{
	uint32_t localVal = REG_PL_RD(EPA_EPA_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000018)) >> 3);
}
__INLINE uint8_t epa_epa_status_ctrl_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(EPA_EPA_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}

/**
 * @brief RD_PTR register definition
 *  EPA Read Pointer from DMEM register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RD_PTR                    0x0
 * </pre>
 */
#define EPA_RD_PTR_ADDR        (REG_EPA_BASE_ADDR+0x00000020)
#define EPA_RD_PTR_OFFSET      0x00000020
#define EPA_RD_PTR_INDEX       0x00000008
#define EPA_RD_PTR_RESET       0x00000000

__INLINE uint32_t  epa_rd_ptr_get(void)
{
	return REG_PL_RD(EPA_RD_PTR_ADDR);
}

__INLINE void epa_rd_ptr_set(uint32_t value)
{
	REG_PL_WR(EPA_RD_PTR_ADDR, value);
}

// field definitions
#define EPA_RD_PTR_RD_PTR_MASK              ((uint32_t)0xFFFFFFFF)
#define EPA_RD_PTR_RD_PTR_LSB               0
#define EPA_RD_PTR_RD_PTR_WIDTH             ((uint32_t)0x00000020)

#define EPA_RD_PTR_RD_PTR_RST               0x0

__INLINE uint32_t epa_rd_ptr_rd_ptr_getf(void)
{
	uint32_t localVal = REG_PL_RD(EPA_RD_PTR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void epa_rd_ptr_rd_ptr_setf(uint32_t rdptr)
{
	ASSERT_ERR((((uint32_t)rdptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(EPA_RD_PTR_ADDR, (uint32_t)rdptr << 0);
}

/**
 * @brief RD_OFFSET register definition
 *  EPA Read Offsets register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 RD_COL_OFFSET             0x0
 *    15:00 RD_ROW_OFFSET             0x0
 * </pre>
 */
#define EPA_RD_OFFSET_ADDR        (REG_EPA_BASE_ADDR+0x00000024)
#define EPA_RD_OFFSET_OFFSET      0x00000024
#define EPA_RD_OFFSET_INDEX       0x00000009
#define EPA_RD_OFFSET_RESET       0x00000000

__INLINE uint32_t  epa_rd_offset_get(void)
{
	return REG_PL_RD(EPA_RD_OFFSET_ADDR);
}

__INLINE void epa_rd_offset_set(uint32_t value)
{
	REG_PL_WR(EPA_RD_OFFSET_ADDR, value);
}

// field definitions
#define EPA_RD_OFFSET_RD_COL_OFFSET_MASK    ((uint32_t)0xFFFF0000)
#define EPA_RD_OFFSET_RD_COL_OFFSET_LSB     16
#define EPA_RD_OFFSET_RD_COL_OFFSET_WIDTH    ((uint32_t)0x00000010)
#define EPA_RD_OFFSET_RD_ROW_OFFSET_MASK    ((uint32_t)0x0000FFFF)
#define EPA_RD_OFFSET_RD_ROW_OFFSET_LSB     0
#define EPA_RD_OFFSET_RD_ROW_OFFSET_WIDTH    ((uint32_t)0x00000010)

#define EPA_RD_OFFSET_RD_COL_OFFSET_RST     0x0
#define EPA_RD_OFFSET_RD_ROW_OFFSET_RST     0x0

__INLINE void epa_rd_offset_pack(uint16_t rd_col_offset, uint16_t rd_row_offset)
{
	ASSERT_ERR((((uint32_t)rd_col_offset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)rd_row_offset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(EPA_RD_OFFSET_ADDR,  ((uint32_t)rd_col_offset << 16) |((uint32_t)rd_row_offset << 0));
}

__INLINE void epa_rd_offset_unpack(uint16_t* rd_col_offset, uint16_t* rd_row_offset)
{
	uint32_t localVal = REG_PL_RD(EPA_RD_OFFSET_ADDR);

	*rd_col_offset = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*rd_row_offset = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t epa_rd_offset_rd_col_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(EPA_RD_OFFSET_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void epa_rd_offset_rd_col_offset_setf(uint16_t rdcoloffset)
{
	ASSERT_ERR((((uint32_t)rdcoloffset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(EPA_RD_OFFSET_ADDR, (REG_PL_RD(EPA_RD_OFFSET_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)rdcoloffset <<16));
}
__INLINE uint16_t epa_rd_offset_rd_row_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(EPA_RD_OFFSET_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void epa_rd_offset_rd_row_offset_setf(uint16_t rdrowoffset)
{
	ASSERT_ERR((((uint32_t)rdrowoffset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(EPA_RD_OFFSET_ADDR, (REG_PL_RD(EPA_RD_OFFSET_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)rdrowoffset <<0));
}

/**
 * @brief WR_PTR register definition
 *  EPA Write Pointer of results to DMEM  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 WR_PTR                    0x0
 * </pre>
 */
#define EPA_WR_PTR_ADDR        (REG_EPA_BASE_ADDR+0x00000030)
#define EPA_WR_PTR_OFFSET      0x00000030
#define EPA_WR_PTR_INDEX       0x0000000C
#define EPA_WR_PTR_RESET       0x00000000

__INLINE uint32_t  epa_wr_ptr_get(void)
{
	return REG_PL_RD(EPA_WR_PTR_ADDR);
}

__INLINE void epa_wr_ptr_set(uint32_t value)
{
	REG_PL_WR(EPA_WR_PTR_ADDR, value);
}

// field definitions
#define EPA_WR_PTR_WR_PTR_MASK              ((uint32_t)0xFFFFFFFF)
#define EPA_WR_PTR_WR_PTR_LSB               0
#define EPA_WR_PTR_WR_PTR_WIDTH             ((uint32_t)0x00000020)

#define EPA_WR_PTR_WR_PTR_RST               0x0

__INLINE uint32_t epa_wr_ptr_wr_ptr_getf(void)
{
	uint32_t localVal = REG_PL_RD(EPA_WR_PTR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void epa_wr_ptr_wr_ptr_setf(uint32_t wrptr)
{
	ASSERT_ERR((((uint32_t)wrptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(EPA_WR_PTR_ADDR, (uint32_t)wrptr << 0);
}

/**
 * @brief WR_OFFSET register definition
 *  EPA Write Offsets register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 WR_COL_OFFSET             0x0
 *    15:00 WR_ROW_OFFSET             0x0
 * </pre>
 */
#define EPA_WR_OFFSET_ADDR        (REG_EPA_BASE_ADDR+0x00000034)
#define EPA_WR_OFFSET_OFFSET      0x00000034
#define EPA_WR_OFFSET_INDEX       0x0000000D
#define EPA_WR_OFFSET_RESET       0x00000000

__INLINE uint32_t  epa_wr_offset_get(void)
{
	return REG_PL_RD(EPA_WR_OFFSET_ADDR);
}

__INLINE void epa_wr_offset_set(uint32_t value)
{
	REG_PL_WR(EPA_WR_OFFSET_ADDR, value);
}

// field definitions
#define EPA_WR_OFFSET_WR_COL_OFFSET_MASK    ((uint32_t)0xFFFF0000)
#define EPA_WR_OFFSET_WR_COL_OFFSET_LSB     16
#define EPA_WR_OFFSET_WR_COL_OFFSET_WIDTH    ((uint32_t)0x00000010)
#define EPA_WR_OFFSET_WR_ROW_OFFSET_MASK    ((uint32_t)0x0000FFFF)
#define EPA_WR_OFFSET_WR_ROW_OFFSET_LSB     0
#define EPA_WR_OFFSET_WR_ROW_OFFSET_WIDTH    ((uint32_t)0x00000010)

#define EPA_WR_OFFSET_WR_COL_OFFSET_RST     0x0
#define EPA_WR_OFFSET_WR_ROW_OFFSET_RST     0x0

__INLINE void epa_wr_offset_pack(uint16_t wr_col_offset, uint16_t wr_row_offset)
{
	ASSERT_ERR((((uint32_t)wr_col_offset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)wr_row_offset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(EPA_WR_OFFSET_ADDR,  ((uint32_t)wr_col_offset << 16) |((uint32_t)wr_row_offset << 0));
}

__INLINE void epa_wr_offset_unpack(uint16_t* wr_col_offset, uint16_t* wr_row_offset)
{
	uint32_t localVal = REG_PL_RD(EPA_WR_OFFSET_ADDR);

	*wr_col_offset = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*wr_row_offset = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t epa_wr_offset_wr_col_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(EPA_WR_OFFSET_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void epa_wr_offset_wr_col_offset_setf(uint16_t wrcoloffset)
{
	ASSERT_ERR((((uint32_t)wrcoloffset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(EPA_WR_OFFSET_ADDR, (REG_PL_RD(EPA_WR_OFFSET_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)wrcoloffset <<16));
}
__INLINE uint16_t epa_wr_offset_wr_row_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(EPA_WR_OFFSET_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void epa_wr_offset_wr_row_offset_setf(uint16_t wrrowoffset)
{
	ASSERT_ERR((((uint32_t)wrrowoffset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(EPA_WR_OFFSET_ADDR, (REG_PL_RD(EPA_WR_OFFSET_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)wrrowoffset <<0));
}

/**
 * @brief MCCI_PTR register definition
 *  MCCI Message Pointer when done register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 MESS_PTR                  0x0
 * </pre>
 */
#define EPA_MCCI_PTR_ADDR        (REG_EPA_BASE_ADDR+0x00000044)
#define EPA_MCCI_PTR_OFFSET      0x00000044
#define EPA_MCCI_PTR_INDEX       0x00000011
#define EPA_MCCI_PTR_RESET       0x00000000

__INLINE uint32_t  epa_mcci_ptr_get(void)
{
	return REG_PL_RD(EPA_MCCI_PTR_ADDR);
}

__INLINE void epa_mcci_ptr_set(uint32_t value)
{
	REG_PL_WR(EPA_MCCI_PTR_ADDR, value);
}

// field definitions
#define EPA_MCCI_PTR_MESS_PTR_MASK          ((uint32_t)0xFFFFFFFF)
#define EPA_MCCI_PTR_MESS_PTR_LSB           0
#define EPA_MCCI_PTR_MESS_PTR_WIDTH         ((uint32_t)0x00000020)

#define EPA_MCCI_PTR_MESS_PTR_RST           0x0

__INLINE uint32_t epa_mcci_ptr_mess_ptr_getf(void)
{
	uint32_t localVal = REG_PL_RD(EPA_MCCI_PTR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void epa_mcci_ptr_mess_ptr_setf(uint32_t messptr)
{
	ASSERT_ERR((((uint32_t)messptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(EPA_MCCI_PTR_ADDR, (uint32_t)messptr << 0);
}

/**
 * @brief DEBUG_CFG register definition
 *  Logger Data select register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    DEBUG_EN                  0              
 *    29:25 DEBUG_SEL_6               0x0
 *    24:20 DEBUG_SEL_5               0x0
 *    19:15 DEBUG_SEL_4               0x0
 *    14:10 DEBUG_SEL_3               0x0
 *    09:05 DEBUG_SEL_2               0x0
 *    04:00 DEBUG_SEL_1               0x0
 * </pre>
 */
#define EPA_DEBUG_CFG_ADDR        (REG_EPA_BASE_ADDR+0x00000060)
#define EPA_DEBUG_CFG_OFFSET      0x00000060
#define EPA_DEBUG_CFG_INDEX       0x00000018
#define EPA_DEBUG_CFG_RESET       0x00000000

__INLINE uint32_t  epa_debug_cfg_get(void)
{
	return REG_PL_RD(EPA_DEBUG_CFG_ADDR);
}

__INLINE void epa_debug_cfg_set(uint32_t value)
{
	REG_PL_WR(EPA_DEBUG_CFG_ADDR, value);
}

// field definitions
#define EPA_DEBUG_CFG_DEBUG_EN_BIT          ((uint32_t)0x80000000)
#define EPA_DEBUG_CFG_DEBUG_EN_POS          31
#define EPA_DEBUG_CFG_DEBUG_SEL_6_MASK      ((uint32_t)0x3E000000)
#define EPA_DEBUG_CFG_DEBUG_SEL_6_LSB       25
#define EPA_DEBUG_CFG_DEBUG_SEL_6_WIDTH     ((uint32_t)0x00000005)
#define EPA_DEBUG_CFG_DEBUG_SEL_5_MASK      ((uint32_t)0x01F00000)
#define EPA_DEBUG_CFG_DEBUG_SEL_5_LSB       20
#define EPA_DEBUG_CFG_DEBUG_SEL_5_WIDTH     ((uint32_t)0x00000005)
#define EPA_DEBUG_CFG_DEBUG_SEL_4_MASK      ((uint32_t)0x000F8000)
#define EPA_DEBUG_CFG_DEBUG_SEL_4_LSB       15
#define EPA_DEBUG_CFG_DEBUG_SEL_4_WIDTH     ((uint32_t)0x00000005)
#define EPA_DEBUG_CFG_DEBUG_SEL_3_MASK      ((uint32_t)0x00007C00)
#define EPA_DEBUG_CFG_DEBUG_SEL_3_LSB       10
#define EPA_DEBUG_CFG_DEBUG_SEL_3_WIDTH     ((uint32_t)0x00000005)
#define EPA_DEBUG_CFG_DEBUG_SEL_2_MASK      ((uint32_t)0x000003E0)
#define EPA_DEBUG_CFG_DEBUG_SEL_2_LSB       5
#define EPA_DEBUG_CFG_DEBUG_SEL_2_WIDTH     ((uint32_t)0x00000005)
#define EPA_DEBUG_CFG_DEBUG_SEL_1_MASK      ((uint32_t)0x0000001F)
#define EPA_DEBUG_CFG_DEBUG_SEL_1_LSB       0
#define EPA_DEBUG_CFG_DEBUG_SEL_1_WIDTH     ((uint32_t)0x00000005)

#define EPA_DEBUG_CFG_DEBUG_EN_RST          0x0
#define EPA_DEBUG_CFG_DEBUG_SEL_6_RST       0x0
#define EPA_DEBUG_CFG_DEBUG_SEL_5_RST       0x0
#define EPA_DEBUG_CFG_DEBUG_SEL_4_RST       0x0
#define EPA_DEBUG_CFG_DEBUG_SEL_3_RST       0x0
#define EPA_DEBUG_CFG_DEBUG_SEL_2_RST       0x0
#define EPA_DEBUG_CFG_DEBUG_SEL_1_RST       0x0

__INLINE void epa_debug_cfg_pack(uint8_t debug_en, uint8_t debug_sel_6, uint8_t debug_sel_5, uint8_t debug_sel_4, uint8_t debug_sel_3, uint8_t debug_sel_2, uint8_t debug_sel_1)
{
	ASSERT_ERR((((uint32_t)debug_en << 31) & ~((uint32_t)0x80000000)) == 0);
	ASSERT_ERR((((uint32_t)debug_sel_6 << 25) & ~((uint32_t)0x3E000000)) == 0);
	ASSERT_ERR((((uint32_t)debug_sel_5 << 20) & ~((uint32_t)0x01F00000)) == 0);
	ASSERT_ERR((((uint32_t)debug_sel_4 << 15) & ~((uint32_t)0x000F8000)) == 0);
	ASSERT_ERR((((uint32_t)debug_sel_3 << 10) & ~((uint32_t)0x00007C00)) == 0);
	ASSERT_ERR((((uint32_t)debug_sel_2 << 5) & ~((uint32_t)0x000003E0)) == 0);
	ASSERT_ERR((((uint32_t)debug_sel_1 << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(EPA_DEBUG_CFG_ADDR,  ((uint32_t)debug_en << 31) |((uint32_t)debug_sel_6 << 25) |((uint32_t)debug_sel_5 << 20) |((uint32_t)debug_sel_4 << 15) |((uint32_t)debug_sel_3 << 10) |((uint32_t)debug_sel_2 << 5) |((uint32_t)debug_sel_1 << 0));
}

__INLINE void epa_debug_cfg_unpack(uint8_t* debug_en, uint8_t* debug_sel_6, uint8_t* debug_sel_5, uint8_t* debug_sel_4, uint8_t* debug_sel_3, uint8_t* debug_sel_2, uint8_t* debug_sel_1)
{
	uint32_t localVal = REG_PL_RD(EPA_DEBUG_CFG_ADDR);

	*debug_en = (localVal & ((uint32_t)0x80000000)) >>  31;
	*debug_sel_6 = (localVal & ((uint32_t)0x3E000000)) >>  25;
	*debug_sel_5 = (localVal & ((uint32_t)0x01F00000)) >>  20;
	*debug_sel_4 = (localVal & ((uint32_t)0x000F8000)) >>  15;
	*debug_sel_3 = (localVal & ((uint32_t)0x00007C00)) >>  10;
	*debug_sel_2 = (localVal & ((uint32_t)0x000003E0)) >>  5;
	*debug_sel_1 = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t epa_debug_cfg_debug_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(EPA_DEBUG_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE void epa_debug_cfg_debug_en_setf(uint8_t debugen)
{
	ASSERT_ERR((((uint32_t)debugen << 31) & ~((uint32_t)0x80000000)) == 0);
	REG_PL_WR(EPA_DEBUG_CFG_ADDR, (REG_PL_RD(EPA_DEBUG_CFG_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)debugen <<31));
}
__INLINE uint8_t epa_debug_cfg_debug_sel_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(EPA_DEBUG_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x3E000000)) >> 25);
}
__INLINE void epa_debug_cfg_debug_sel_6_setf(uint8_t debugsel6)
{
	ASSERT_ERR((((uint32_t)debugsel6 << 25) & ~((uint32_t)0x3E000000)) == 0);
	REG_PL_WR(EPA_DEBUG_CFG_ADDR, (REG_PL_RD(EPA_DEBUG_CFG_ADDR) & ~((uint32_t)0x3E000000)) | ((uint32_t)debugsel6 <<25));
}
__INLINE uint8_t epa_debug_cfg_debug_sel_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(EPA_DEBUG_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01F00000)) >> 20);
}
__INLINE void epa_debug_cfg_debug_sel_5_setf(uint8_t debugsel5)
{
	ASSERT_ERR((((uint32_t)debugsel5 << 20) & ~((uint32_t)0x01F00000)) == 0);
	REG_PL_WR(EPA_DEBUG_CFG_ADDR, (REG_PL_RD(EPA_DEBUG_CFG_ADDR) & ~((uint32_t)0x01F00000)) | ((uint32_t)debugsel5 <<20));
}
__INLINE uint8_t epa_debug_cfg_debug_sel_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(EPA_DEBUG_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000F8000)) >> 15);
}
__INLINE void epa_debug_cfg_debug_sel_4_setf(uint8_t debugsel4)
{
	ASSERT_ERR((((uint32_t)debugsel4 << 15) & ~((uint32_t)0x000F8000)) == 0);
	REG_PL_WR(EPA_DEBUG_CFG_ADDR, (REG_PL_RD(EPA_DEBUG_CFG_ADDR) & ~((uint32_t)0x000F8000)) | ((uint32_t)debugsel4 <<15));
}
__INLINE uint8_t epa_debug_cfg_debug_sel_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(EPA_DEBUG_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007C00)) >> 10);
}
__INLINE void epa_debug_cfg_debug_sel_3_setf(uint8_t debugsel3)
{
	ASSERT_ERR((((uint32_t)debugsel3 << 10) & ~((uint32_t)0x00007C00)) == 0);
	REG_PL_WR(EPA_DEBUG_CFG_ADDR, (REG_PL_RD(EPA_DEBUG_CFG_ADDR) & ~((uint32_t)0x00007C00)) | ((uint32_t)debugsel3 <<10));
}
__INLINE uint8_t epa_debug_cfg_debug_sel_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(EPA_DEBUG_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000003E0)) >> 5);
}
__INLINE void epa_debug_cfg_debug_sel_2_setf(uint8_t debugsel2)
{
	ASSERT_ERR((((uint32_t)debugsel2 << 5) & ~((uint32_t)0x000003E0)) == 0);
	REG_PL_WR(EPA_DEBUG_CFG_ADDR, (REG_PL_RD(EPA_DEBUG_CFG_ADDR) & ~((uint32_t)0x000003E0)) | ((uint32_t)debugsel2 <<5));
}
__INLINE uint8_t epa_debug_cfg_debug_sel_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(EPA_DEBUG_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void epa_debug_cfg_debug_sel_1_setf(uint8_t debugsel1)
{
	ASSERT_ERR((((uint32_t)debugsel1 << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(EPA_DEBUG_CFG_ADDR, (REG_PL_RD(EPA_DEBUG_CFG_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)debugsel1 <<0));
}


#undef DBG_FILEID
#endif //_REG_EPA_H_

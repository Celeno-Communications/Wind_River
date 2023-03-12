/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef REG_CMU_H
#define REG_CMU_H

#include <linux/types.h>
#include "reg_access.h"
#include "chip.h"

#define REG_CMU_BASE_ADDR 0x007C6000

/**
 * @brief CMU_CLK_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    spare_afe_gnrl_en         0
 *    30    spare_sys_gnrl_en         0
 *    27    spare_riu44_clk_en        0
 *    26    spare_riu_clk_en          0
 *    25    spare_riu2x_clk_en        0
 *    24    spare_riu4x_clk_en        0
 *    23    spare_phy_clk_en          0
 *    22    spare_phy2x_clk_en        0
 *    21    spare_sysx_clk_en         0
 *    20    spare_sys2x_clk_en        0
 *    19    rfic_wrap_clk_en          0
 *    05    smac_proc_clk_en          1
 *    04    umac_proc_clk_en          1
 *    03    lmac_proc_clk_en          1
 *    02    pcie_clk_en               1
 *    01    usbc_clk_en               1
 * </pre>
 */
#define CMU_CLK_EN_ADDR        (REG_CMU_BASE_ADDR + 0x00000000)
#define CMU_CLK_EN_OFFSET      0x00000000
#define CMU_CLK_EN_INDEX       0x00000000
#define CMU_CLK_EN_RESET       0x0000003E

static inline u32 cmu_clk_en_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, CMU_CLK_EN_ADDR);
}

static inline void cmu_clk_en_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, CMU_CLK_EN_ADDR, value);
}

/* Field definitions */
#define CMU_CLK_EN_SPARE_AFE_GNRL_EN_BIT    ((u32)0x80000000)
#define CMU_CLK_EN_SPARE_AFE_GNRL_EN_POS    31
#define CMU_CLK_EN_SPARE_SYS_GNRL_EN_BIT    ((u32)0x40000000)
#define CMU_CLK_EN_SPARE_SYS_GNRL_EN_POS    30
#define CMU_CLK_EN_SPARE_RIU_44_CLK_EN_BIT    ((u32)0x08000000)
#define CMU_CLK_EN_SPARE_RIU_44_CLK_EN_POS    27
#define CMU_CLK_EN_SPARE_RIU_CLK_EN_BIT    ((u32)0x04000000)
#define CMU_CLK_EN_SPARE_RIU_CLK_EN_POS    26
#define CMU_CLK_EN_SPARE_RIU_2_X_CLK_EN_BIT    ((u32)0x02000000)
#define CMU_CLK_EN_SPARE_RIU_2_X_CLK_EN_POS    25
#define CMU_CLK_EN_SPARE_RIU_4_X_CLK_EN_BIT    ((u32)0x01000000)
#define CMU_CLK_EN_SPARE_RIU_4_X_CLK_EN_POS    24
#define CMU_CLK_EN_SPARE_PHY_CLK_EN_BIT    ((u32)0x00800000)
#define CMU_CLK_EN_SPARE_PHY_CLK_EN_POS    23
#define CMU_CLK_EN_SPARE_PHY_2_X_CLK_EN_BIT    ((u32)0x00400000)
#define CMU_CLK_EN_SPARE_PHY_2_X_CLK_EN_POS    22
#define CMU_CLK_EN_SPARE_SYSX_CLK_EN_BIT    ((u32)0x00200000)
#define CMU_CLK_EN_SPARE_SYSX_CLK_EN_POS    21
#define CMU_CLK_EN_SPARE_SYS_2_X_CLK_EN_BIT    ((u32)0x00100000)
#define CMU_CLK_EN_SPARE_SYS_2_X_CLK_EN_POS    20
#define CMU_CLK_EN_RFIC_WRAP_CLK_EN_BIT    ((u32)0x00080000)
#define CMU_CLK_EN_RFIC_WRAP_CLK_EN_POS    19
#define CMU_CLK_EN_SMAC_PROC_CLK_EN_BIT    ((u32)0x00000020)
#define CMU_CLK_EN_SMAC_PROC_CLK_EN_POS    5
#define CMU_CLK_EN_UMAC_PROC_CLK_EN_BIT    ((u32)0x00000010)
#define CMU_CLK_EN_UMAC_PROC_CLK_EN_POS    4
#define CMU_CLK_EN_LMAC_PROC_CLK_EN_BIT    ((u32)0x00000008)
#define CMU_CLK_EN_LMAC_PROC_CLK_EN_POS    3
#define CMU_CLK_EN_PCIE_CLK_EN_BIT      ((u32)0x00000004)
#define CMU_CLK_EN_PCIE_CLK_EN_POS      2
#define CMU_CLK_EN_USBC_CLK_EN_BIT      ((u32)0x00000002)
#define CMU_CLK_EN_USBC_CLK_EN_POS      1

#define CMU_CLK_EN_SPARE_AFE_GNRL_EN_RST    0x0
#define CMU_CLK_EN_SPARE_SYS_GNRL_EN_RST    0x0
#define CMU_CLK_EN_SPARE_RIU_44_CLK_EN_RST    0x0
#define CMU_CLK_EN_SPARE_RIU_CLK_EN_RST    0x0
#define CMU_CLK_EN_SPARE_RIU_2_X_CLK_EN_RST    0x0
#define CMU_CLK_EN_SPARE_RIU_4_X_CLK_EN_RST    0x0
#define CMU_CLK_EN_SPARE_PHY_CLK_EN_RST    0x0
#define CMU_CLK_EN_SPARE_PHY_2_X_CLK_EN_RST    0x0
#define CMU_CLK_EN_SPARE_SYSX_CLK_EN_RST    0x0
#define CMU_CLK_EN_SPARE_SYS_2_X_CLK_EN_RST    0x0
#define CMU_CLK_EN_RFIC_WRAP_CLK_EN_RST    0x0
#define CMU_CLK_EN_SMAC_PROC_CLK_EN_RST    0x1
#define CMU_CLK_EN_UMAC_PROC_CLK_EN_RST    0x1
#define CMU_CLK_EN_LMAC_PROC_CLK_EN_RST    0x1
#define CMU_CLK_EN_PCIE_CLK_EN_RST      0x1
#define CMU_CLK_EN_USBC_CLK_EN_RST      0x1

static inline void cmu_clk_en_pack(struct cl_chip *chip, u8 spare_afe_gnrl_en, u8 spare_sys_gnrl_en, u8 spare_riu44_clk_en, u8 spare_riu_clk_en, u8 spare_riu2x_clk_en, u8 spare_riu4x_clk_en, u8 spare_phy_clk_en, u8 spare_phy2x_clk_en, u8 spare_sysx_clk_en, u8 spare_sys2x_clk_en, u8 rfic_wrap_clk_en, u8 smac_proc_clk_en, u8 umac_proc_clk_en, u8 lmac_proc_clk_en, u8 pcie_clk_en, u8 usbc_clk_en)
{
	ASSERT_ERR_CHIP((((u32)spare_afe_gnrl_en << 31) & ~((u32)0x80000000)) == 0);
	ASSERT_ERR_CHIP((((u32)spare_sys_gnrl_en << 30) & ~((u32)0x40000000)) == 0);
	ASSERT_ERR_CHIP((((u32)spare_riu44_clk_en << 27) & ~((u32)0x08000000)) == 0);
	ASSERT_ERR_CHIP((((u32)spare_riu_clk_en << 26) & ~((u32)0x04000000)) == 0);
	ASSERT_ERR_CHIP((((u32)spare_riu2x_clk_en << 25) & ~((u32)0x02000000)) == 0);
	ASSERT_ERR_CHIP((((u32)spare_riu4x_clk_en << 24) & ~((u32)0x01000000)) == 0);
	ASSERT_ERR_CHIP((((u32)spare_phy_clk_en << 23) & ~((u32)0x00800000)) == 0);
	ASSERT_ERR_CHIP((((u32)spare_phy2x_clk_en << 22) & ~((u32)0x00400000)) == 0);
	ASSERT_ERR_CHIP((((u32)spare_sysx_clk_en << 21) & ~((u32)0x00200000)) == 0);
	ASSERT_ERR_CHIP((((u32)spare_sys2x_clk_en << 20) & ~((u32)0x00100000)) == 0);
	ASSERT_ERR_CHIP((((u32)rfic_wrap_clk_en << 19) & ~((u32)0x00080000)) == 0);
	ASSERT_ERR_CHIP((((u32)smac_proc_clk_en << 5) & ~((u32)0x00000020)) == 0);
	ASSERT_ERR_CHIP((((u32)umac_proc_clk_en << 4) & ~((u32)0x00000010)) == 0);
	ASSERT_ERR_CHIP((((u32)lmac_proc_clk_en << 3) & ~((u32)0x00000008)) == 0);
	ASSERT_ERR_CHIP((((u32)pcie_clk_en << 2) & ~((u32)0x00000004)) == 0);
	ASSERT_ERR_CHIP((((u32)usbc_clk_en << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, CMU_CLK_EN_ADDR, ((u32)spare_afe_gnrl_en << 31) | ((u32)spare_sys_gnrl_en << 30) | ((u32)spare_riu44_clk_en << 27) | ((u32)spare_riu_clk_en << 26) | ((u32)spare_riu2x_clk_en << 25) | ((u32)spare_riu4x_clk_en << 24) | ((u32)spare_phy_clk_en << 23) | ((u32)spare_phy2x_clk_en << 22) | ((u32)spare_sysx_clk_en << 21) | ((u32)spare_sys2x_clk_en << 20) | ((u32)rfic_wrap_clk_en << 19) | ((u32)smac_proc_clk_en << 5) | ((u32)umac_proc_clk_en << 4) | ((u32)lmac_proc_clk_en << 3) | ((u32)pcie_clk_en << 2) | ((u32)usbc_clk_en << 1));
}

static inline void cmu_clk_en_unpack(struct cl_chip *chip, u8 *spare_afe_gnrl_en, u8 *spare_sys_gnrl_en, u8 *spare_riu44_clk_en, u8 *spare_riu_clk_en, u8 *spare_riu2x_clk_en, u8 *spare_riu4x_clk_en, u8 *spare_phy_clk_en, u8 *spare_phy2x_clk_en, u8 *spare_sysx_clk_en, u8 *spare_sys2x_clk_en, u8 *rfic_wrap_clk_en, u8 *smac_proc_clk_en, u8 *umac_proc_clk_en, u8 *lmac_proc_clk_en, u8 *pcie_clk_en, u8 *usbc_clk_en)
{
	u32 local_val = cl_reg_read(chip, CMU_CLK_EN_ADDR);

	*spare_afe_gnrl_en = (local_val & ((u32)0x80000000)) >> 31;
	*spare_sys_gnrl_en = (local_val & ((u32)0x40000000)) >> 30;
	*spare_riu44_clk_en = (local_val & ((u32)0x08000000)) >> 27;
	*spare_riu_clk_en = (local_val & ((u32)0x04000000)) >> 26;
	*spare_riu2x_clk_en = (local_val & ((u32)0x02000000)) >> 25;
	*spare_riu4x_clk_en = (local_val & ((u32)0x01000000)) >> 24;
	*spare_phy_clk_en = (local_val & ((u32)0x00800000)) >> 23;
	*spare_phy2x_clk_en = (local_val & ((u32)0x00400000)) >> 22;
	*spare_sysx_clk_en = (local_val & ((u32)0x00200000)) >> 21;
	*spare_sys2x_clk_en = (local_val & ((u32)0x00100000)) >> 20;
	*rfic_wrap_clk_en = (local_val & ((u32)0x00080000)) >> 19;
	*smac_proc_clk_en = (local_val & ((u32)0x00000020)) >> 5;
	*umac_proc_clk_en = (local_val & ((u32)0x00000010)) >> 4;
	*lmac_proc_clk_en = (local_val & ((u32)0x00000008)) >> 3;
	*pcie_clk_en = (local_val & ((u32)0x00000004)) >> 2;
	*usbc_clk_en = (local_val & ((u32)0x00000002)) >> 1;
}

static inline u8 cmu_clk_en_spare_afe_gnrl_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_CLK_EN_ADDR);

	return (u8)((local_val & ((u32)0x80000000)) >> 31);
}

static inline void cmu_clk_en_spare_afe_gnrl_en_setf(struct cl_chip *chip, u8 spareafegnrlen)
{
	ASSERT_ERR_CHIP((((u32)spareafegnrlen << 31) & ~((u32)0x80000000)) == 0);
	cl_reg_write(chip, CMU_CLK_EN_ADDR, (cl_reg_read(chip, CMU_CLK_EN_ADDR) & ~((u32)0x80000000)) | ((u32)spareafegnrlen << 31));
}

static inline u8 cmu_clk_en_spare_sys_gnrl_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_CLK_EN_ADDR);

	return (u8)((local_val & ((u32)0x40000000)) >> 30);
}

static inline void cmu_clk_en_spare_sys_gnrl_en_setf(struct cl_chip *chip, u8 sparesysgnrlen)
{
	ASSERT_ERR_CHIP((((u32)sparesysgnrlen << 30) & ~((u32)0x40000000)) == 0);
	cl_reg_write(chip, CMU_CLK_EN_ADDR, (cl_reg_read(chip, CMU_CLK_EN_ADDR) & ~((u32)0x40000000)) | ((u32)sparesysgnrlen << 30));
}

static inline u8 cmu_clk_en_spare_riu_44_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_CLK_EN_ADDR);

	return (u8)((local_val & ((u32)0x08000000)) >> 27);
}

static inline void cmu_clk_en_spare_riu_44_clk_en_setf(struct cl_chip *chip, u8 spareriu44clken)
{
	ASSERT_ERR_CHIP((((u32)spareriu44clken << 27) & ~((u32)0x08000000)) == 0);
	cl_reg_write(chip, CMU_CLK_EN_ADDR, (cl_reg_read(chip, CMU_CLK_EN_ADDR) & ~((u32)0x08000000)) | ((u32)spareriu44clken << 27));
}

static inline u8 cmu_clk_en_spare_riu_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_CLK_EN_ADDR);

	return (u8)((local_val & ((u32)0x04000000)) >> 26);
}

static inline void cmu_clk_en_spare_riu_clk_en_setf(struct cl_chip *chip, u8 spareriuclken)
{
	ASSERT_ERR_CHIP((((u32)spareriuclken << 26) & ~((u32)0x04000000)) == 0);
	cl_reg_write(chip, CMU_CLK_EN_ADDR, (cl_reg_read(chip, CMU_CLK_EN_ADDR) & ~((u32)0x04000000)) | ((u32)spareriuclken << 26));
}

static inline u8 cmu_clk_en_spare_riu_2_x_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_CLK_EN_ADDR);

	return (u8)((local_val & ((u32)0x02000000)) >> 25);
}

static inline void cmu_clk_en_spare_riu_2_x_clk_en_setf(struct cl_chip *chip, u8 spareriu2xclken)
{
	ASSERT_ERR_CHIP((((u32)spareriu2xclken << 25) & ~((u32)0x02000000)) == 0);
	cl_reg_write(chip, CMU_CLK_EN_ADDR, (cl_reg_read(chip, CMU_CLK_EN_ADDR) & ~((u32)0x02000000)) | ((u32)spareriu2xclken << 25));
}

static inline u8 cmu_clk_en_spare_riu_4_x_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_CLK_EN_ADDR);

	return (u8)((local_val & ((u32)0x01000000)) >> 24);
}

static inline void cmu_clk_en_spare_riu_4_x_clk_en_setf(struct cl_chip *chip, u8 spareriu4xclken)
{
	ASSERT_ERR_CHIP((((u32)spareriu4xclken << 24) & ~((u32)0x01000000)) == 0);
	cl_reg_write(chip, CMU_CLK_EN_ADDR, (cl_reg_read(chip, CMU_CLK_EN_ADDR) & ~((u32)0x01000000)) | ((u32)spareriu4xclken << 24));
}

static inline u8 cmu_clk_en_spare_phy_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_CLK_EN_ADDR);

	return (u8)((local_val & ((u32)0x00800000)) >> 23);
}

static inline void cmu_clk_en_spare_phy_clk_en_setf(struct cl_chip *chip, u8 sparephyclken)
{
	ASSERT_ERR_CHIP((((u32)sparephyclken << 23) & ~((u32)0x00800000)) == 0);
	cl_reg_write(chip, CMU_CLK_EN_ADDR, (cl_reg_read(chip, CMU_CLK_EN_ADDR) & ~((u32)0x00800000)) | ((u32)sparephyclken << 23));
}

static inline u8 cmu_clk_en_spare_phy_2_x_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_CLK_EN_ADDR);

	return (u8)((local_val & ((u32)0x00400000)) >> 22);
}

static inline void cmu_clk_en_spare_phy_2_x_clk_en_setf(struct cl_chip *chip, u8 sparephy2xclken)
{
	ASSERT_ERR_CHIP((((u32)sparephy2xclken << 22) & ~((u32)0x00400000)) == 0);
	cl_reg_write(chip, CMU_CLK_EN_ADDR, (cl_reg_read(chip, CMU_CLK_EN_ADDR) & ~((u32)0x00400000)) | ((u32)sparephy2xclken << 22));
}

static inline u8 cmu_clk_en_spare_sysx_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_CLK_EN_ADDR);

	return (u8)((local_val & ((u32)0x00200000)) >> 21);
}

static inline void cmu_clk_en_spare_sysx_clk_en_setf(struct cl_chip *chip, u8 sparesysxclken)
{
	ASSERT_ERR_CHIP((((u32)sparesysxclken << 21) & ~((u32)0x00200000)) == 0);
	cl_reg_write(chip, CMU_CLK_EN_ADDR, (cl_reg_read(chip, CMU_CLK_EN_ADDR) & ~((u32)0x00200000)) | ((u32)sparesysxclken << 21));
}

static inline u8 cmu_clk_en_spare_sys_2_x_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_CLK_EN_ADDR);

	return (u8)((local_val & ((u32)0x00100000)) >> 20);
}

static inline void cmu_clk_en_spare_sys_2_x_clk_en_setf(struct cl_chip *chip, u8 sparesys2xclken)
{
	ASSERT_ERR_CHIP((((u32)sparesys2xclken << 20) & ~((u32)0x00100000)) == 0);
	cl_reg_write(chip, CMU_CLK_EN_ADDR, (cl_reg_read(chip, CMU_CLK_EN_ADDR) & ~((u32)0x00100000)) | ((u32)sparesys2xclken << 20));
}

static inline u8 cmu_clk_en_rfic_wrap_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_CLK_EN_ADDR);

	return (u8)((local_val & ((u32)0x00080000)) >> 19);
}

static inline void cmu_clk_en_rfic_wrap_clk_en_setf(struct cl_chip *chip, u8 rficwrapclken)
{
	ASSERT_ERR_CHIP((((u32)rficwrapclken << 19) & ~((u32)0x00080000)) == 0);
	cl_reg_write(chip, CMU_CLK_EN_ADDR, (cl_reg_read(chip, CMU_CLK_EN_ADDR) & ~((u32)0x00080000)) | ((u32)rficwrapclken << 19));
}

static inline u8 cmu_clk_en_smac_proc_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_CLK_EN_ADDR);

	return (u8)((local_val & ((u32)0x00000020)) >> 5);
}

static inline void cmu_clk_en_smac_proc_clk_en_setf(struct cl_chip *chip, u8 smacprocclken)
{
	ASSERT_ERR_CHIP((((u32)smacprocclken << 5) & ~((u32)0x00000020)) == 0);
	cl_reg_write(chip, CMU_CLK_EN_ADDR, (cl_reg_read(chip, CMU_CLK_EN_ADDR) & ~((u32)0x00000020)) | ((u32)smacprocclken << 5));
}

static inline u8 cmu_clk_en_umac_proc_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_CLK_EN_ADDR);

	return (u8)((local_val & ((u32)0x00000010)) >> 4);
}

static inline void cmu_clk_en_umac_proc_clk_en_setf(struct cl_chip *chip, u8 umacprocclken)
{
	ASSERT_ERR_CHIP((((u32)umacprocclken << 4) & ~((u32)0x00000010)) == 0);
	cl_reg_write(chip, CMU_CLK_EN_ADDR, (cl_reg_read(chip, CMU_CLK_EN_ADDR) & ~((u32)0x00000010)) | ((u32)umacprocclken << 4));
}

static inline u8 cmu_clk_en_lmac_proc_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_CLK_EN_ADDR);

	return (u8)((local_val & ((u32)0x00000008)) >> 3);
}

static inline void cmu_clk_en_lmac_proc_clk_en_setf(struct cl_chip *chip, u8 lmacprocclken)
{
	ASSERT_ERR_CHIP((((u32)lmacprocclken << 3) & ~((u32)0x00000008)) == 0);
	cl_reg_write(chip, CMU_CLK_EN_ADDR, (cl_reg_read(chip, CMU_CLK_EN_ADDR) & ~((u32)0x00000008)) | ((u32)lmacprocclken << 3));
}

static inline u8 cmu_clk_en_pcie_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_CLK_EN_ADDR);

	return (u8)((local_val & ((u32)0x00000004)) >> 2);
}

static inline void cmu_clk_en_pcie_clk_en_setf(struct cl_chip *chip, u8 pcieclken)
{
	ASSERT_ERR_CHIP((((u32)pcieclken << 2) & ~((u32)0x00000004)) == 0);
	cl_reg_write(chip, CMU_CLK_EN_ADDR, (cl_reg_read(chip, CMU_CLK_EN_ADDR) & ~((u32)0x00000004)) | ((u32)pcieclken << 2));
}

static inline u8 cmu_clk_en_usbc_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_CLK_EN_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void cmu_clk_en_usbc_clk_en_setf(struct cl_chip *chip, u8 usbcclken)
{
	ASSERT_ERR_CHIP((((u32)usbcclken << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, CMU_CLK_EN_ADDR, (cl_reg_read(chip, CMU_CLK_EN_ADDR) & ~((u32)0x00000002)) | ((u32)usbcclken << 1));
}

/**
 * @brief CMU_PHY_0_CLK_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    02    reserved              0
 *    01    phy0_apb_clk_en           0
 *    00    phy0_main_clk_en          0
 * </pre>
 */
#define CMU_PHY_0_CLK_EN_ADDR        (REG_CMU_BASE_ADDR + 0x00000004)
#define CMU_PHY_0_CLK_EN_OFFSET      0x00000004
#define CMU_PHY_0_CLK_EN_INDEX       0x00000001
#define CMU_PHY_0_CLK_EN_RESET       0x00000000

static inline u32 cmu_phy_0_clk_en_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, CMU_PHY_0_CLK_EN_ADDR);
}

static inline void cmu_phy_0_clk_en_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, CMU_PHY_0_CLK_EN_ADDR, value);
}

/* Field definitions */
#define CMU_PHY_0_CLK_EN_PHY_0_APB_CLK_EN_BIT    ((u32)0x00000002)
#define CMU_PHY_0_CLK_EN_PHY_0_APB_CLK_EN_POS    1
#define CMU_PHY_0_CLK_EN_PHY_0_MAIN_CLK_EN_BIT    ((u32)0x00000001)
#define CMU_PHY_0_CLK_EN_PHY_0_MAIN_CLK_EN_POS    0

#define CMU_PHY_0_CLK_EN_PHY_0_APB_CLK_EN_RST    0x0
#define CMU_PHY_0_CLK_EN_PHY_0_MAIN_CLK_EN_RST    0x0

static inline void cmu_phy_0_clk_en_pack(struct cl_chip *chip, u8 phy0_apb_clk_en, u8 phy0_main_clk_en)
{
	ASSERT_ERR_CHIP((((u32)phy0_apb_clk_en << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)phy0_main_clk_en << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, CMU_PHY_0_CLK_EN_ADDR, ((u32)0 << 2) | ((u32)phy0_apb_clk_en << 1) | ((u32)phy0_main_clk_en << 0));
}

static inline void cmu_phy_0_clk_en_unpack(struct cl_chip *chip, u8 *phy0_apb_clk_en, u8 *phy0_main_clk_en)
{
	u32 local_val = cl_reg_read(chip, CMU_PHY_0_CLK_EN_ADDR);

	*phy0_apb_clk_en = (local_val & ((u32)0x00000002)) >> 1;
	*phy0_main_clk_en = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 cmu_phy_0_clk_en_phy_0_apb_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_PHY_0_CLK_EN_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void cmu_phy_0_clk_en_phy_0_apb_clk_en_setf(struct cl_chip *chip, u8 phy0apbclken)
{
	ASSERT_ERR_CHIP((((u32)phy0apbclken << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, CMU_PHY_0_CLK_EN_ADDR, (cl_reg_read(chip, CMU_PHY_0_CLK_EN_ADDR) & ~((u32)0x00000002)) | ((u32)phy0apbclken << 1));
}

static inline u8 cmu_phy_0_clk_en_phy_0_main_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_PHY_0_CLK_EN_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void cmu_phy_0_clk_en_phy_0_main_clk_en_setf(struct cl_chip *chip, u8 phy0mainclken)
{
	ASSERT_ERR_CHIP((((u32)phy0mainclken << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, CMU_PHY_0_CLK_EN_ADDR, (cl_reg_read(chip, CMU_PHY_0_CLK_EN_ADDR) & ~((u32)0x00000001)) | ((u32)phy0mainclken << 0));
}

/**
 * @brief CMU_PHY_1_CLK_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    02    reserved              0
 *    01    phy1_apb_clk_en           0
 *    00    phy1_main_clk_en          0
 * </pre>
 */
#define CMU_PHY_1_CLK_EN_ADDR        (REG_CMU_BASE_ADDR + 0x00000008)
#define CMU_PHY_1_CLK_EN_OFFSET      0x00000008
#define CMU_PHY_1_CLK_EN_INDEX       0x00000002
#define CMU_PHY_1_CLK_EN_RESET       0x00000000

static inline u32 cmu_phy_1_clk_en_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, CMU_PHY_1_CLK_EN_ADDR);
}

static inline void cmu_phy_1_clk_en_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, CMU_PHY_1_CLK_EN_ADDR, value);
}

/* Field definitions */
#define CMU_PHY_1_CLK_EN_PHY_1_APB_CLK_EN_BIT    ((u32)0x00000002)
#define CMU_PHY_1_CLK_EN_PHY_1_APB_CLK_EN_POS    1
#define CMU_PHY_1_CLK_EN_PHY_1_MAIN_CLK_EN_BIT    ((u32)0x00000001)
#define CMU_PHY_1_CLK_EN_PHY_1_MAIN_CLK_EN_POS    0

#define CMU_PHY_1_CLK_EN_PHY_1_APB_CLK_EN_RST    0x0
#define CMU_PHY_1_CLK_EN_PHY_1_MAIN_CLK_EN_RST    0x0

static inline void cmu_phy_1_clk_en_pack(struct cl_chip *chip, u8 phy1_apb_clk_en, u8 phy1_main_clk_en)
{
	ASSERT_ERR_CHIP((((u32)phy1_apb_clk_en << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)phy1_main_clk_en << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, CMU_PHY_1_CLK_EN_ADDR, ((u32)0 << 2) | ((u32)phy1_apb_clk_en << 1) | ((u32)phy1_main_clk_en << 0));
}

static inline void cmu_phy_1_clk_en_unpack(struct cl_chip *chip, u8 *phy1_apb_clk_en, u8 *phy1_main_clk_en)
{
	u32 local_val = cl_reg_read(chip, CMU_PHY_1_CLK_EN_ADDR);

	*phy1_apb_clk_en = (local_val & ((u32)0x00000002)) >> 1;
	*phy1_main_clk_en = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 cmu_phy_1_clk_en_phy_1_apb_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_PHY_1_CLK_EN_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void cmu_phy_1_clk_en_phy_1_apb_clk_en_setf(struct cl_chip *chip, u8 phy1apbclken)
{
	ASSERT_ERR_CHIP((((u32)phy1apbclken << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, CMU_PHY_1_CLK_EN_ADDR, (cl_reg_read(chip, CMU_PHY_1_CLK_EN_ADDR) & ~((u32)0x00000002)) | ((u32)phy1apbclken << 1));
}

static inline u8 cmu_phy_1_clk_en_phy_1_main_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_PHY_1_CLK_EN_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void cmu_phy_1_clk_en_phy_1_main_clk_en_setf(struct cl_chip *chip, u8 phy1mainclken)
{
	ASSERT_ERR_CHIP((((u32)phy1mainclken << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, CMU_PHY_1_CLK_EN_ADDR, (cl_reg_read(chip, CMU_PHY_1_CLK_EN_ADDR) & ~((u32)0x00000001)) | ((u32)phy1mainclken << 0));
}

/**
 * @brief CMU_CONTROL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    gl_mux_sel                0
 * </pre>
 */
#define CMU_CONTROL_ADDR        (REG_CMU_BASE_ADDR + 0x0000000C)
#define CMU_CONTROL_OFFSET      0x0000000C
#define CMU_CONTROL_INDEX       0x00000003
#define CMU_CONTROL_RESET       0x00000000

static inline u32 cmu_control_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, CMU_CONTROL_ADDR);
}

static inline void cmu_control_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, CMU_CONTROL_ADDR, value);
}

/* Field definitions */
#define CMU_CONTROL_GL_MUX_SEL_BIT      ((u32)0x00000001)
#define CMU_CONTROL_GL_MUX_SEL_POS      0

#define CMU_CONTROL_GL_MUX_SEL_RST      0x0

static inline u8 cmu_control_gl_mux_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_CONTROL_ADDR);

	return (u8)(local_val >> 0);
}

static inline void cmu_control_gl_mux_sel_setf(struct cl_chip *chip, u8 glmuxsel)
{
	ASSERT_ERR_CHIP((((u32)glmuxsel << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, CMU_CONTROL_ADDR, (u32)glmuxsel << 0);
}

/**
 * @brief CMU_RST register definition
 *  cmu reset register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:01 spare_reset_31_1          0x0
 *    00    adc_reset_b               1
 * </pre>
 */
#define CMU_RST_ADDR        (REG_CMU_BASE_ADDR + 0x00000010)
#define CMU_RST_OFFSET      0x00000010
#define CMU_RST_INDEX       0x00000004
#define CMU_RST_RESET       0x00000001

static inline u32 cmu_rst_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, CMU_RST_ADDR);
}

static inline void cmu_rst_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, CMU_RST_ADDR, value);
}

/* Field definitions */
#define CMU_RST_SPARE_RESET_31_1_MASK    ((u32)0xFFFFFFFE)
#define CMU_RST_SPARE_RESET_31_1_LSB    1
#define CMU_RST_SPARE_RESET_31_1_WIDTH    ((u32)0x0000001F)
#define CMU_RST_ADC_RESET_B_BIT         ((u32)0x00000001)
#define CMU_RST_ADC_RESET_B_POS         0

#define CMU_RST_SPARE_RESET_31_1_RST    0x0
#define CMU_RST_ADC_RESET_B_RST         0x1

static inline void cmu_rst_pack(struct cl_chip *chip, u32 spare_reset_31_1, u8 adc_reset_b)
{
	ASSERT_ERR_CHIP((((u32)spare_reset_31_1 << 1) & ~((u32)0xFFFFFFFE)) == 0);
	ASSERT_ERR_CHIP((((u32)adc_reset_b << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, CMU_RST_ADDR, ((u32)spare_reset_31_1 << 1) | ((u32)adc_reset_b << 0));
}

static inline void cmu_rst_unpack(struct cl_chip *chip, u32 *spare_reset_31_1, u8 *adc_reset_b)
{
	u32 local_val = cl_reg_read(chip, CMU_RST_ADDR);

	*spare_reset_31_1 = (local_val & ((u32)0xFFFFFFFE)) >> 1;
	*adc_reset_b = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u32 cmu_rst_spare_reset_31_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_RST_ADDR);

	return (u32)((local_val & ((u32)0xFFFFFFFE)) >> 1);
}

static inline void cmu_rst_spare_reset_31_1_setf(struct cl_chip *chip, u32 sparereset311)
{
	ASSERT_ERR_CHIP((((u32)sparereset311 << 1) & ~((u32)0xFFFFFFFE)) == 0);
	cl_reg_write(chip, CMU_RST_ADDR, (cl_reg_read(chip, CMU_RST_ADDR) & ~((u32)0xFFFFFFFE)) | ((u32)sparereset311 << 1));
}

static inline u8 cmu_rst_adc_reset_b_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_RST_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void cmu_rst_adc_reset_b_setf(struct cl_chip *chip, u8 adcresetb)
{
	ASSERT_ERR_CHIP((((u32)adcresetb << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, CMU_RST_ADDR, (cl_reg_read(chip, CMU_RST_ADDR) & ~((u32)0x00000001)) | ((u32)adcresetb << 0));
}

/**
 * @brief CMU_PHY_0_RST register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    03    reserved        1
 *    02    mpif0_rst_n               1
 *    01    phy0_preset_n             1
 *    00    phy0_rst_n                1
 * </pre>
 */
#define CMU_PHY_0_RST_ADDR        (REG_CMU_BASE_ADDR + 0x00000014)
#define CMU_PHY_0_RST_OFFSET      0x00000014
#define CMU_PHY_0_RST_INDEX       0x00000005
#define CMU_PHY_0_RST_RESET       0x0000000F

static inline u32 cmu_phy_0_rst_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, CMU_PHY_0_RST_ADDR);
}

static inline void cmu_phy_0_rst_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, CMU_PHY_0_RST_ADDR, value);
}

/* Field definitions */
#define CMU_PHY_0_RST_MPIF_0_RST_N_BIT    ((u32)0x00000004)
#define CMU_PHY_0_RST_MPIF_0_RST_N_POS    2
#define CMU_PHY_0_RST_PHY_0_PRESET_N_BIT    ((u32)0x00000002)
#define CMU_PHY_0_RST_PHY_0_PRESET_N_POS    1
#define CMU_PHY_0_RST_PHY_0_RST_N_BIT    ((u32)0x00000001)
#define CMU_PHY_0_RST_PHY_0_RST_N_POS    0

#define CMU_PHY_0_RST_MPIF_0_RST_N_RST    0x1
#define CMU_PHY_0_RST_PHY_0_PRESET_N_RST    0x1
#define CMU_PHY_0_RST_PHY_0_RST_N_RST    0x1

static inline void cmu_phy_0_rst_pack(struct cl_chip *chip, u8 mpif0_rst_n, u8 phy0_preset_n, u8 phy0_rst_n)
{
	ASSERT_ERR_CHIP((((u32)mpif0_rst_n << 2) & ~((u32)0x00000004)) == 0);
	ASSERT_ERR_CHIP((((u32)phy0_preset_n << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)phy0_rst_n << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, CMU_PHY_0_RST_ADDR, ((u32)0 << 3) | ((u32)mpif0_rst_n << 2) | ((u32)phy0_preset_n << 1) | ((u32)phy0_rst_n << 0));
}

static inline void cmu_phy_0_rst_unpack(struct cl_chip *chip, u8 *mpif0_rst_n, u8 *phy0_preset_n, u8 *phy0_rst_n)
{
	u32 local_val = cl_reg_read(chip, CMU_PHY_0_RST_ADDR);

	*mpif0_rst_n = (local_val & ((u32)0x00000004)) >> 2;
	*phy0_preset_n = (local_val & ((u32)0x00000002)) >> 1;
	*phy0_rst_n = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 cmu_phy_0_rst_mpif_0_rst_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_PHY_0_RST_ADDR);

	return (u8)((local_val & ((u32)0x00000004)) >> 2);
}

static inline void cmu_phy_0_rst_mpif_0_rst_n_setf(struct cl_chip *chip, u8 mpif0rstn)
{
	ASSERT_ERR_CHIP((((u32)mpif0rstn << 2) & ~((u32)0x00000004)) == 0);
	cl_reg_write(chip, CMU_PHY_0_RST_ADDR, (cl_reg_read(chip, CMU_PHY_0_RST_ADDR) & ~((u32)0x00000004)) | ((u32)mpif0rstn << 2));
}

static inline u8 cmu_phy_0_rst_phy_0_preset_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_PHY_0_RST_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void cmu_phy_0_rst_phy_0_preset_n_setf(struct cl_chip *chip, u8 phy0presetn)
{
	ASSERT_ERR_CHIP((((u32)phy0presetn << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, CMU_PHY_0_RST_ADDR, (cl_reg_read(chip, CMU_PHY_0_RST_ADDR) & ~((u32)0x00000002)) | ((u32)phy0presetn << 1));
}

static inline u8 cmu_phy_0_rst_phy_0_rst_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_PHY_0_RST_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void cmu_phy_0_rst_phy_0_rst_n_setf(struct cl_chip *chip, u8 phy0rstn)
{
	ASSERT_ERR_CHIP((((u32)phy0rstn << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, CMU_PHY_0_RST_ADDR, (cl_reg_read(chip, CMU_PHY_0_RST_ADDR) & ~((u32)0x00000001)) | ((u32)phy0rstn << 0));
}

/**
 * @brief CMU_PHY_1_RST register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    03    reserved        1
 *    02    mpif1_rst_n               1
 *    01    phy1_preset_n             1
 *    00    phy1_rst_n                1
 * </pre>
 */
#define CMU_PHY_1_RST_ADDR        (REG_CMU_BASE_ADDR + 0x00000018)
#define CMU_PHY_1_RST_OFFSET      0x00000018
#define CMU_PHY_1_RST_INDEX       0x00000006
#define CMU_PHY_1_RST_RESET       0x0000000F

static inline u32 cmu_phy_1_rst_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, CMU_PHY_1_RST_ADDR);
}

static inline void cmu_phy_1_rst_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, CMU_PHY_1_RST_ADDR, value);
}

/* Field definitions */
#define CMU_PHY_1_RST_MPIF_1_RST_N_BIT    ((u32)0x00000004)
#define CMU_PHY_1_RST_MPIF_1_RST_N_POS    2
#define CMU_PHY_1_RST_PHY_1_PRESET_N_BIT    ((u32)0x00000002)
#define CMU_PHY_1_RST_PHY_1_PRESET_N_POS    1
#define CMU_PHY_1_RST_PHY_1_RST_N_BIT    ((u32)0x00000001)
#define CMU_PHY_1_RST_PHY_1_RST_N_POS    0

#define CMU_PHY_1_RST_MPIF_1_RST_N_RST    0x1
#define CMU_PHY_1_RST_PHY_1_PRESET_N_RST    0x1
#define CMU_PHY_1_RST_PHY_1_RST_N_RST    0x1

static inline void cmu_phy_1_rst_pack(struct cl_chip *chip, u8 mpif1_rst_n, u8 phy1_preset_n, u8 phy1_rst_n)
{
	ASSERT_ERR_CHIP((((u32)mpif1_rst_n << 2) & ~((u32)0x00000004)) == 0);
	ASSERT_ERR_CHIP((((u32)phy1_preset_n << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)phy1_rst_n << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, CMU_PHY_1_RST_ADDR, ((u32)0 << 3) | ((u32)mpif1_rst_n << 2) | ((u32)phy1_preset_n << 1) | ((u32)phy1_rst_n << 0));
}

static inline void cmu_phy_1_rst_unpack(struct cl_chip *chip, u8 *mpif1_rst_n, u8 *phy1_preset_n, u8 *phy1_rst_n)
{
	u32 local_val = cl_reg_read(chip, CMU_PHY_1_RST_ADDR);

	*mpif1_rst_n = (local_val & ((u32)0x00000004)) >> 2;
	*phy1_preset_n = (local_val & ((u32)0x00000002)) >> 1;
	*phy1_rst_n = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 cmu_phy_1_rst_mpif_1_rst_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_PHY_1_RST_ADDR);

	return (u8)((local_val & ((u32)0x00000004)) >> 2);
}

static inline void cmu_phy_1_rst_mpif_1_rst_n_setf(struct cl_chip *chip, u8 mpif1rstn)
{
	ASSERT_ERR_CHIP((((u32)mpif1rstn << 2) & ~((u32)0x00000004)) == 0);
	cl_reg_write(chip, CMU_PHY_1_RST_ADDR, (cl_reg_read(chip, CMU_PHY_1_RST_ADDR) & ~((u32)0x00000004)) | ((u32)mpif1rstn << 2));
}

static inline u8 cmu_phy_1_rst_phy_1_preset_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_PHY_1_RST_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void cmu_phy_1_rst_phy_1_preset_n_setf(struct cl_chip *chip, u8 phy1presetn)
{
	ASSERT_ERR_CHIP((((u32)phy1presetn << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, CMU_PHY_1_RST_ADDR, (cl_reg_read(chip, CMU_PHY_1_RST_ADDR) & ~((u32)0x00000002)) | ((u32)phy1presetn << 1));
}

static inline u8 cmu_phy_1_rst_phy_1_rst_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_PHY_1_RST_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void cmu_phy_1_rst_phy_1_rst_n_setf(struct cl_chip *chip, u8 phy1rstn)
{
	ASSERT_ERR_CHIP((((u32)phy1rstn << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, CMU_PHY_1_RST_ADDR, (cl_reg_read(chip, CMU_PHY_1_RST_ADDR) & ~((u32)0x00000001)) | ((u32)phy1rstn << 0));
}

/**
 * @brief CMU_GLOBAL_RST register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 key_reset                 0x0
 * </pre>
 */
#define CMU_GLOBAL_RST_ADDR        (REG_CMU_BASE_ADDR + 0x0000001C)
#define CMU_GLOBAL_RST_OFFSET      0x0000001C
#define CMU_GLOBAL_RST_INDEX       0x00000007
#define CMU_GLOBAL_RST_RESET       0x00000000

static inline u32 cmu_global_rst_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, CMU_GLOBAL_RST_ADDR);
}

static inline void cmu_global_rst_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, CMU_GLOBAL_RST_ADDR, value);
}

/* Field definitions */
#define CMU_GLOBAL_RST_KEY_RESET_MASK    ((u32)0xFFFFFFFF)
#define CMU_GLOBAL_RST_KEY_RESET_LSB    0
#define CMU_GLOBAL_RST_KEY_RESET_WIDTH    ((u32)0x00000020)

#define CMU_GLOBAL_RST_KEY_RESET_RST    0x0

static inline u32 cmu_global_rst_key_reset_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_GLOBAL_RST_ADDR);

	return (u32)(local_val >> 0);
}

static inline void cmu_global_rst_key_reset_setf(struct cl_chip *chip, u32 keyreset)
{
	ASSERT_ERR_CHIP((((u32)keyreset << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, CMU_GLOBAL_RST_ADDR, (u32)keyreset << 0);
}

/**
 * @brief CMU_BT_CLK_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    bt_clk_en                 1
 * </pre>
 */
#define CMU_BT_CLK_EN_ADDR        (REG_CMU_BASE_ADDR + 0x00000020)
#define CMU_BT_CLK_EN_OFFSET      0x00000020
#define CMU_BT_CLK_EN_INDEX       0x00000008
#define CMU_BT_CLK_EN_RESET       0x00000001

static inline u32 cmu_bt_clk_en_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, CMU_BT_CLK_EN_ADDR);
}

static inline void cmu_bt_clk_en_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, CMU_BT_CLK_EN_ADDR, value);
}

/* Field definitions */
#define CMU_BT_CLK_EN_BT_CLK_EN_BIT     ((u32)0x00000001)
#define CMU_BT_CLK_EN_BT_CLK_EN_POS     0

#define CMU_BT_CLK_EN_BT_CLK_EN_RST     0x1

static inline u8 cmu_bt_clk_en_bt_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_BT_CLK_EN_ADDR);

	return (u8)(local_val >> 0);
}

static inline void cmu_bt_clk_en_bt_clk_en_setf(struct cl_chip *chip, u8 btclken)
{
	ASSERT_ERR_CHIP((((u32)btclken << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, CMU_BT_CLK_EN_ADDR, (u32)btclken << 0);
}

/**
 * @brief CMU_BT_RST register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    bt_rst_n                  1
 * </pre>
 */
#define CMU_BT_RST_ADDR        (REG_CMU_BASE_ADDR + 0x00000024)
#define CMU_BT_RST_OFFSET      0x00000024
#define CMU_BT_RST_INDEX       0x00000009
#define CMU_BT_RST_RESET       0x00000001

static inline u32 cmu_bt_rst_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, CMU_BT_RST_ADDR);
}

static inline void cmu_bt_rst_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, CMU_BT_RST_ADDR, value);
}

/* Field definitions */
#define CMU_BT_RST_BT_RST_N_BIT         ((u32)0x00000001)
#define CMU_BT_RST_BT_RST_N_POS         0

#define CMU_BT_RST_BT_RST_N_RST         0x1

static inline u8 cmu_bt_rst_bt_rst_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_BT_RST_ADDR);

	return (u8)(local_val >> 0);
}

static inline void cmu_bt_rst_bt_rst_n_setf(struct cl_chip *chip, u8 btrstn)
{
	ASSERT_ERR_CHIP((((u32)btrstn << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, CMU_BT_RST_ADDR, (u32)btrstn << 0);
}

/**
 * @brief CMU_MCLK_CONTROL_1 register definition
 *  cmu mclk control register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    mclk_enable               0
 *    15:08 first_phase               0x0
 *    07:00 period_num                0x0
 * </pre>
 */
#define CMU_MCLK_CONTROL_1_ADDR        (REG_CMU_BASE_ADDR + 0x00000028)
#define CMU_MCLK_CONTROL_1_OFFSET      0x00000028
#define CMU_MCLK_CONTROL_1_INDEX       0x0000000A
#define CMU_MCLK_CONTROL_1_RESET       0x00000000

static inline u32 cmu_mclk_control_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, CMU_MCLK_CONTROL_1_ADDR);
}

static inline void cmu_mclk_control_1_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, CMU_MCLK_CONTROL_1_ADDR, value);
}

/* Field definitions */
#define CMU_MCLK_CONTROL_1_MCLK_ENABLE_BIT    ((u32)0x80000000)
#define CMU_MCLK_CONTROL_1_MCLK_ENABLE_POS    31
#define CMU_MCLK_CONTROL_1_FIRST_PHASE_MASK    ((u32)0x0000FF00)
#define CMU_MCLK_CONTROL_1_FIRST_PHASE_LSB    8
#define CMU_MCLK_CONTROL_1_FIRST_PHASE_WIDTH    ((u32)0x00000008)
#define CMU_MCLK_CONTROL_1_PERIOD_NUM_MASK    ((u32)0x000000FF)
#define CMU_MCLK_CONTROL_1_PERIOD_NUM_LSB    0
#define CMU_MCLK_CONTROL_1_PERIOD_NUM_WIDTH    ((u32)0x00000008)

#define CMU_MCLK_CONTROL_1_MCLK_ENABLE_RST    0x0
#define CMU_MCLK_CONTROL_1_FIRST_PHASE_RST    0x0
#define CMU_MCLK_CONTROL_1_PERIOD_NUM_RST    0x0

static inline void cmu_mclk_control_1_pack(struct cl_chip *chip, u8 mclk_enable, u8 first_phase, u8 period_num)
{
	ASSERT_ERR_CHIP((((u32)mclk_enable << 31) & ~((u32)0x80000000)) == 0);
	ASSERT_ERR_CHIP((((u32)first_phase << 8) & ~((u32)0x0000FF00)) == 0);
	ASSERT_ERR_CHIP((((u32)period_num << 0) & ~((u32)0x000000FF)) == 0);
	cl_reg_write(chip, CMU_MCLK_CONTROL_1_ADDR, ((u32)mclk_enable << 31) | ((u32)first_phase << 8) | ((u32)period_num << 0));
}

static inline void cmu_mclk_control_1_unpack(struct cl_chip *chip, u8 *mclk_enable, u8 *first_phase, u8 *period_num)
{
	u32 local_val = cl_reg_read(chip, CMU_MCLK_CONTROL_1_ADDR);

	*mclk_enable = (local_val & ((u32)0x80000000)) >> 31;
	*first_phase = (local_val & ((u32)0x0000FF00)) >> 8;
	*period_num = (local_val & ((u32)0x000000FF)) >> 0;
}

static inline u8 cmu_mclk_control_1_mclk_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_MCLK_CONTROL_1_ADDR);

	return (u8)((local_val & ((u32)0x80000000)) >> 31);
}

static inline void cmu_mclk_control_1_mclk_enable_setf(struct cl_chip *chip, u8 mclkenable)
{
	ASSERT_ERR_CHIP((((u32)mclkenable << 31) & ~((u32)0x80000000)) == 0);
	cl_reg_write(chip, CMU_MCLK_CONTROL_1_ADDR, (cl_reg_read(chip, CMU_MCLK_CONTROL_1_ADDR) & ~((u32)0x80000000)) | ((u32)mclkenable << 31));
}

static inline u8 cmu_mclk_control_1_first_phase_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_MCLK_CONTROL_1_ADDR);

	return (u8)((local_val & ((u32)0x0000FF00)) >> 8);
}

static inline void cmu_mclk_control_1_first_phase_setf(struct cl_chip *chip, u8 firstphase)
{
	ASSERT_ERR_CHIP((((u32)firstphase << 8) & ~((u32)0x0000FF00)) == 0);
	cl_reg_write(chip, CMU_MCLK_CONTROL_1_ADDR, (cl_reg_read(chip, CMU_MCLK_CONTROL_1_ADDR) & ~((u32)0x0000FF00)) | ((u32)firstphase << 8));
}

static inline u8 cmu_mclk_control_1_period_num_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_MCLK_CONTROL_1_ADDR);

	return (u8)((local_val & ((u32)0x000000FF)) >> 0);
}

static inline void cmu_mclk_control_1_period_num_setf(struct cl_chip *chip, u8 periodnum)
{
	ASSERT_ERR_CHIP((((u32)periodnum << 0) & ~((u32)0x000000FF)) == 0);
	cl_reg_write(chip, CMU_MCLK_CONTROL_1_ADDR, (cl_reg_read(chip, CMU_MCLK_CONTROL_1_ADDR) & ~((u32)0x000000FF)) | ((u32)periodnum << 0));
}

/**
 * @brief CMU_MCLK_CONTROL_2 register definition
 *  cmu mclk control register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:16 pwm_low_p2                0x0
 *    15:08 pwm_low_p1                0x0
 *    07:00 pwm_high                  0x0
 * </pre>
 */
#define CMU_MCLK_CONTROL_2_ADDR        (REG_CMU_BASE_ADDR + 0x0000002C)
#define CMU_MCLK_CONTROL_2_OFFSET      0x0000002C
#define CMU_MCLK_CONTROL_2_INDEX       0x0000000B
#define CMU_MCLK_CONTROL_2_RESET       0x00000000

static inline u32 cmu_mclk_control_2_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, CMU_MCLK_CONTROL_2_ADDR);
}

static inline void cmu_mclk_control_2_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, CMU_MCLK_CONTROL_2_ADDR, value);
}

/* Field definitions */
#define CMU_MCLK_CONTROL_2_PWM_LOW_P_2_MASK    ((u32)0x00FF0000)
#define CMU_MCLK_CONTROL_2_PWM_LOW_P_2_LSB    16
#define CMU_MCLK_CONTROL_2_PWM_LOW_P_2_WIDTH    ((u32)0x00000008)
#define CMU_MCLK_CONTROL_2_PWM_LOW_P_1_MASK    ((u32)0x0000FF00)
#define CMU_MCLK_CONTROL_2_PWM_LOW_P_1_LSB    8
#define CMU_MCLK_CONTROL_2_PWM_LOW_P_1_WIDTH    ((u32)0x00000008)
#define CMU_MCLK_CONTROL_2_PWM_HIGH_MASK    ((u32)0x000000FF)
#define CMU_MCLK_CONTROL_2_PWM_HIGH_LSB    0
#define CMU_MCLK_CONTROL_2_PWM_HIGH_WIDTH    ((u32)0x00000008)

#define CMU_MCLK_CONTROL_2_PWM_LOW_P_2_RST    0x0
#define CMU_MCLK_CONTROL_2_PWM_LOW_P_1_RST    0x0
#define CMU_MCLK_CONTROL_2_PWM_HIGH_RST    0x0

static inline void cmu_mclk_control_2_pack(struct cl_chip *chip, u8 pwm_low_p2, u8 pwm_low_p1, u8 pwm_high)
{
	ASSERT_ERR_CHIP((((u32)pwm_low_p2 << 16) & ~((u32)0x00FF0000)) == 0);
	ASSERT_ERR_CHIP((((u32)pwm_low_p1 << 8) & ~((u32)0x0000FF00)) == 0);
	ASSERT_ERR_CHIP((((u32)pwm_high << 0) & ~((u32)0x000000FF)) == 0);
	cl_reg_write(chip, CMU_MCLK_CONTROL_2_ADDR, ((u32)pwm_low_p2 << 16) | ((u32)pwm_low_p1 << 8) | ((u32)pwm_high << 0));
}

static inline void cmu_mclk_control_2_unpack(struct cl_chip *chip, u8 *pwm_low_p2, u8 *pwm_low_p1, u8 *pwm_high)
{
	u32 local_val = cl_reg_read(chip, CMU_MCLK_CONTROL_2_ADDR);

	*pwm_low_p2 = (local_val & ((u32)0x00FF0000)) >> 16;
	*pwm_low_p1 = (local_val & ((u32)0x0000FF00)) >> 8;
	*pwm_high = (local_val & ((u32)0x000000FF)) >> 0;
}

static inline u8 cmu_mclk_control_2_pwm_low_p_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_MCLK_CONTROL_2_ADDR);

	return (u8)((local_val & ((u32)0x00FF0000)) >> 16);
}

static inline void cmu_mclk_control_2_pwm_low_p_2_setf(struct cl_chip *chip, u8 pwmlowp2)
{
	ASSERT_ERR_CHIP((((u32)pwmlowp2 << 16) & ~((u32)0x00FF0000)) == 0);
	cl_reg_write(chip, CMU_MCLK_CONTROL_2_ADDR, (cl_reg_read(chip, CMU_MCLK_CONTROL_2_ADDR) & ~((u32)0x00FF0000)) | ((u32)pwmlowp2 << 16));
}

static inline u8 cmu_mclk_control_2_pwm_low_p_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_MCLK_CONTROL_2_ADDR);

	return (u8)((local_val & ((u32)0x0000FF00)) >> 8);
}

static inline void cmu_mclk_control_2_pwm_low_p_1_setf(struct cl_chip *chip, u8 pwmlowp1)
{
	ASSERT_ERR_CHIP((((u32)pwmlowp1 << 8) & ~((u32)0x0000FF00)) == 0);
	cl_reg_write(chip, CMU_MCLK_CONTROL_2_ADDR, (cl_reg_read(chip, CMU_MCLK_CONTROL_2_ADDR) & ~((u32)0x0000FF00)) | ((u32)pwmlowp1 << 8));
}

static inline u8 cmu_mclk_control_2_pwm_high_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_MCLK_CONTROL_2_ADDR);

	return (u8)((local_val & ((u32)0x000000FF)) >> 0);
}

static inline void cmu_mclk_control_2_pwm_high_setf(struct cl_chip *chip, u8 pwmhigh)
{
	ASSERT_ERR_CHIP((((u32)pwmhigh << 0) & ~((u32)0x000000FF)) == 0);
	cl_reg_write(chip, CMU_MCLK_CONTROL_2_ADDR, (cl_reg_read(chip, CMU_MCLK_CONTROL_2_ADDR) & ~((u32)0x000000FF)) | ((u32)pwmhigh << 0));
}

/**
 * @brief CMU_RESET_CONTROL register definition
 *  cmu reset control register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    05:04 hw_watchdog_reset_scope   0x0
 *    01:00 global_reset_scope        0x0
 * </pre>
 */
#define CMU_RESET_CONTROL_ADDR        (REG_CMU_BASE_ADDR + 0x00000030)
#define CMU_RESET_CONTROL_OFFSET      0x00000030
#define CMU_RESET_CONTROL_INDEX       0x0000000C
#define CMU_RESET_CONTROL_RESET       0x00000000

static inline u32 cmu_reset_control_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, CMU_RESET_CONTROL_ADDR);
}

static inline void cmu_reset_control_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, CMU_RESET_CONTROL_ADDR, value);
}

/* Field definitions */
#define CMU_RESET_CONTROL_HW_WATCHDOG_RESET_SCOPE_MASK    ((u32)0x00000030)
#define CMU_RESET_CONTROL_HW_WATCHDOG_RESET_SCOPE_LSB    4
#define CMU_RESET_CONTROL_HW_WATCHDOG_RESET_SCOPE_WIDTH    ((u32)0x00000002)
#define CMU_RESET_CONTROL_GLOBAL_RESET_SCOPE_MASK    ((u32)0x00000003)
#define CMU_RESET_CONTROL_GLOBAL_RESET_SCOPE_LSB    0
#define CMU_RESET_CONTROL_GLOBAL_RESET_SCOPE_WIDTH    ((u32)0x00000002)

#define CMU_RESET_CONTROL_HW_WATCHDOG_RESET_SCOPE_RST    0x0
#define CMU_RESET_CONTROL_GLOBAL_RESET_SCOPE_RST    0x0

static inline void cmu_reset_control_pack(struct cl_chip *chip, u8 hw_watchdog_reset_scope, u8 global_reset_scope)
{
	ASSERT_ERR_CHIP((((u32)hw_watchdog_reset_scope << 4) & ~((u32)0x00000030)) == 0);
	ASSERT_ERR_CHIP((((u32)global_reset_scope << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, CMU_RESET_CONTROL_ADDR, ((u32)hw_watchdog_reset_scope << 4) | ((u32)global_reset_scope << 0));
}

static inline void cmu_reset_control_unpack(struct cl_chip *chip, u8 *hw_watchdog_reset_scope, u8 *global_reset_scope)
{
	u32 local_val = cl_reg_read(chip, CMU_RESET_CONTROL_ADDR);

	*hw_watchdog_reset_scope = (local_val & ((u32)0x00000030)) >> 4;
	*global_reset_scope = (local_val & ((u32)0x00000003)) >> 0;
}

static inline u8 cmu_reset_control_hw_watchdog_reset_scope_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_RESET_CONTROL_ADDR);

	return (u8)((local_val & ((u32)0x00000030)) >> 4);
}

static inline void cmu_reset_control_hw_watchdog_reset_scope_setf(struct cl_chip *chip, u8 hwwatchdogresetscope)
{
	ASSERT_ERR_CHIP((((u32)hwwatchdogresetscope << 4) & ~((u32)0x00000030)) == 0);
	cl_reg_write(chip, CMU_RESET_CONTROL_ADDR, (cl_reg_read(chip, CMU_RESET_CONTROL_ADDR) & ~((u32)0x00000030)) | ((u32)hwwatchdogresetscope << 4));
}

static inline u8 cmu_reset_control_global_reset_scope_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_RESET_CONTROL_ADDR);

	return (u8)((local_val & ((u32)0x00000003)) >> 0);
}

static inline void cmu_reset_control_global_reset_scope_setf(struct cl_chip *chip, u8 globalresetscope)
{
	ASSERT_ERR_CHIP((((u32)globalresetscope << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, CMU_RESET_CONTROL_ADDR, (cl_reg_read(chip, CMU_RESET_CONTROL_ADDR) & ~((u32)0x00000003)) | ((u32)globalresetscope << 0));
}

/**
 * @brief CMU_MON_SEL register definition
 *  monitor clock select register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    clk_mon_out_select        0
 * </pre>
 */
#define CMU_MON_SEL_ADDR        (REG_CMU_BASE_ADDR + 0x00000034)
#define CMU_MON_SEL_OFFSET      0x00000034
#define CMU_MON_SEL_INDEX       0x0000000D
#define CMU_MON_SEL_RESET       0x00000000

static inline u32 cmu_mon_sel_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, CMU_MON_SEL_ADDR);
}

static inline void cmu_mon_sel_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, CMU_MON_SEL_ADDR, value);
}

/* Field definitions */
#define CMU_MON_SEL_CLK_MON_OUT_SELECT_BIT    ((u32)0x00000001)
#define CMU_MON_SEL_CLK_MON_OUT_SELECT_POS    0

#define CMU_MON_SEL_CLK_MON_OUT_SELECT_RST    0x0

static inline u8 cmu_mon_sel_clk_mon_out_select_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_MON_SEL_ADDR);

	return (u8)(local_val >> 0);
}

static inline void cmu_mon_sel_clk_mon_out_select_setf(struct cl_chip *chip, u8 clkmonoutselect)
{
	ASSERT_ERR_CHIP((((u32)clkmonoutselect << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, CMU_MON_SEL_ADDR, (u32)clkmonoutselect << 0);
}

/**
 * @brief CMU_PHASE_SEL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    21    auxadc_clk_phase_sel      1
 *    20    bt_clk_phase_sel          1
 *    19    dac_cdb_clk_phase_sel     0
 *    18    adc_cdb_clk_phase_sel     0
 *    17    dac_clk_phase_sel         0
 *    16    adc_clk_phase_sel         0
 * </pre>
 */
#define CMU_PHASE_SEL_ADDR        (REG_CMU_BASE_ADDR + 0x00000060)
#define CMU_PHASE_SEL_OFFSET      0x00000060
#define CMU_PHASE_SEL_INDEX       0x00000018
#define CMU_PHASE_SEL_RESET       0x00300000

static inline u32 cmu_phase_sel_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, CMU_PHASE_SEL_ADDR);
}

static inline void cmu_phase_sel_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, CMU_PHASE_SEL_ADDR, value);
}

/* Field definitions */
#define CMU_PHASE_SEL_AUXADC_CLK_PHASE_SEL_BIT    ((u32)0x00200000)
#define CMU_PHASE_SEL_AUXADC_CLK_PHASE_SEL_POS    21
#define CMU_PHASE_SEL_BT_CLK_PHASE_SEL_BIT    ((u32)0x00100000)
#define CMU_PHASE_SEL_BT_CLK_PHASE_SEL_POS    20
#define CMU_PHASE_SEL_DAC_CDB_CLK_PHASE_SEL_BIT    ((u32)0x00080000)
#define CMU_PHASE_SEL_DAC_CDB_CLK_PHASE_SEL_POS    19
#define CMU_PHASE_SEL_ADC_CDB_CLK_PHASE_SEL_BIT    ((u32)0x00040000)
#define CMU_PHASE_SEL_ADC_CDB_CLK_PHASE_SEL_POS    18
#define CMU_PHASE_SEL_DAC_CLK_PHASE_SEL_BIT    ((u32)0x00020000)
#define CMU_PHASE_SEL_DAC_CLK_PHASE_SEL_POS    17
#define CMU_PHASE_SEL_ADC_CLK_PHASE_SEL_BIT    ((u32)0x00010000)
#define CMU_PHASE_SEL_ADC_CLK_PHASE_SEL_POS    16

#define CMU_PHASE_SEL_AUXADC_CLK_PHASE_SEL_RST    0x1
#define CMU_PHASE_SEL_BT_CLK_PHASE_SEL_RST    0x1
#define CMU_PHASE_SEL_DAC_CDB_CLK_PHASE_SEL_RST    0x0
#define CMU_PHASE_SEL_ADC_CDB_CLK_PHASE_SEL_RST    0x0
#define CMU_PHASE_SEL_DAC_CLK_PHASE_SEL_RST    0x0
#define CMU_PHASE_SEL_ADC_CLK_PHASE_SEL_RST    0x0

static inline void cmu_phase_sel_pack(struct cl_chip *chip, u8 auxadc_clk_phase_sel, u8 bt_clk_phase_sel, u8 dac_cdb_clk_phase_sel, u8 adc_cdb_clk_phase_sel, u8 dac_clk_phase_sel, u8 adc_clk_phase_sel)
{
	ASSERT_ERR_CHIP((((u32)auxadc_clk_phase_sel << 21) & ~((u32)0x00200000)) == 0);
	ASSERT_ERR_CHIP((((u32)bt_clk_phase_sel << 20) & ~((u32)0x00100000)) == 0);
	ASSERT_ERR_CHIP((((u32)dac_cdb_clk_phase_sel << 19) & ~((u32)0x00080000)) == 0);
	ASSERT_ERR_CHIP((((u32)adc_cdb_clk_phase_sel << 18) & ~((u32)0x00040000)) == 0);
	ASSERT_ERR_CHIP((((u32)dac_clk_phase_sel << 17) & ~((u32)0x00020000)) == 0);
	ASSERT_ERR_CHIP((((u32)adc_clk_phase_sel << 16) & ~((u32)0x00010000)) == 0);
	cl_reg_write(chip, CMU_PHASE_SEL_ADDR, ((u32)auxadc_clk_phase_sel << 21) | ((u32)bt_clk_phase_sel << 20) | ((u32)dac_cdb_clk_phase_sel << 19) | ((u32)adc_cdb_clk_phase_sel << 18) | ((u32)dac_clk_phase_sel << 17) | ((u32)adc_clk_phase_sel << 16));
}

static inline void cmu_phase_sel_unpack(struct cl_chip *chip, u8 *auxadc_clk_phase_sel, u8 *bt_clk_phase_sel, u8 *dac_cdb_clk_phase_sel, u8 *adc_cdb_clk_phase_sel, u8 *dac_clk_phase_sel, u8 *adc_clk_phase_sel)
{
	u32 local_val = cl_reg_read(chip, CMU_PHASE_SEL_ADDR);

	*auxadc_clk_phase_sel = (local_val & ((u32)0x00200000)) >> 21;
	*bt_clk_phase_sel = (local_val & ((u32)0x00100000)) >> 20;
	*dac_cdb_clk_phase_sel = (local_val & ((u32)0x00080000)) >> 19;
	*adc_cdb_clk_phase_sel = (local_val & ((u32)0x00040000)) >> 18;
	*dac_clk_phase_sel = (local_val & ((u32)0x00020000)) >> 17;
	*adc_clk_phase_sel = (local_val & ((u32)0x00010000)) >> 16;
}

static inline u8 cmu_phase_sel_auxadc_clk_phase_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_PHASE_SEL_ADDR);

	return (u8)((local_val & ((u32)0x00200000)) >> 21);
}

static inline void cmu_phase_sel_auxadc_clk_phase_sel_setf(struct cl_chip *chip, u8 auxadcclkphasesel)
{
	ASSERT_ERR_CHIP((((u32)auxadcclkphasesel << 21) & ~((u32)0x00200000)) == 0);
	cl_reg_write(chip, CMU_PHASE_SEL_ADDR, (cl_reg_read(chip, CMU_PHASE_SEL_ADDR) & ~((u32)0x00200000)) | ((u32)auxadcclkphasesel << 21));
}

static inline u8 cmu_phase_sel_bt_clk_phase_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_PHASE_SEL_ADDR);

	return (u8)((local_val & ((u32)0x00100000)) >> 20);
}

static inline void cmu_phase_sel_bt_clk_phase_sel_setf(struct cl_chip *chip, u8 btclkphasesel)
{
	ASSERT_ERR_CHIP((((u32)btclkphasesel << 20) & ~((u32)0x00100000)) == 0);
	cl_reg_write(chip, CMU_PHASE_SEL_ADDR, (cl_reg_read(chip, CMU_PHASE_SEL_ADDR) & ~((u32)0x00100000)) | ((u32)btclkphasesel << 20));
}

static inline u8 cmu_phase_sel_dac_cdb_clk_phase_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_PHASE_SEL_ADDR);

	return (u8)((local_val & ((u32)0x00080000)) >> 19);
}

static inline void cmu_phase_sel_dac_cdb_clk_phase_sel_setf(struct cl_chip *chip, u8 daccdbclkphasesel)
{
	ASSERT_ERR_CHIP((((u32)daccdbclkphasesel << 19) & ~((u32)0x00080000)) == 0);
	cl_reg_write(chip, CMU_PHASE_SEL_ADDR, (cl_reg_read(chip, CMU_PHASE_SEL_ADDR) & ~((u32)0x00080000)) | ((u32)daccdbclkphasesel << 19));
}

static inline u8 cmu_phase_sel_adc_cdb_clk_phase_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_PHASE_SEL_ADDR);

	return (u8)((local_val & ((u32)0x00040000)) >> 18);
}

static inline void cmu_phase_sel_adc_cdb_clk_phase_sel_setf(struct cl_chip *chip, u8 adccdbclkphasesel)
{
	ASSERT_ERR_CHIP((((u32)adccdbclkphasesel << 18) & ~((u32)0x00040000)) == 0);
	cl_reg_write(chip, CMU_PHASE_SEL_ADDR, (cl_reg_read(chip, CMU_PHASE_SEL_ADDR) & ~((u32)0x00040000)) | ((u32)adccdbclkphasesel << 18));
}

static inline u8 cmu_phase_sel_dac_clk_phase_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_PHASE_SEL_ADDR);

	return (u8)((local_val & ((u32)0x00020000)) >> 17);
}

static inline void cmu_phase_sel_dac_clk_phase_sel_setf(struct cl_chip *chip, u8 dacclkphasesel)
{
	ASSERT_ERR_CHIP((((u32)dacclkphasesel << 17) & ~((u32)0x00020000)) == 0);
	cl_reg_write(chip, CMU_PHASE_SEL_ADDR, (cl_reg_read(chip, CMU_PHASE_SEL_ADDR) & ~((u32)0x00020000)) | ((u32)dacclkphasesel << 17));
}

static inline u8 cmu_phase_sel_adc_clk_phase_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, CMU_PHASE_SEL_ADDR);

	return (u8)((local_val & ((u32)0x00010000)) >> 16);
}

static inline void cmu_phase_sel_adc_clk_phase_sel_setf(struct cl_chip *chip, u8 adcclkphasesel)
{
	ASSERT_ERR_CHIP((((u32)adcclkphasesel << 16) & ~((u32)0x00010000)) == 0);
	cl_reg_write(chip, CMU_PHASE_SEL_ADDR, (cl_reg_read(chip, CMU_PHASE_SEL_ADDR) & ~((u32)0x00010000)) | ((u32)adcclkphasesel << 16));
}

#endif /* REG_CMU_H */

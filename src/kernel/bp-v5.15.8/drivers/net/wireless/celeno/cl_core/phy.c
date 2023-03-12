// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "phy.h"
#include "reg_modem_gcu.h"
#include "reg_cmu.h"
#include "reg_mac_hw.h"
#include "reg_macsys_gcu.h"
#include "reg_lcu_phy.h"

static void phy_disable(struct cl_chip *chip)
{
	/* Modem GCU modules - Reset */
	/* Disable clocks (reset is not asserted) */
	modem_gcu_mpu_set(chip, MODEM_GCU_MPU_MPU_RST_N_BIT | MODEM_GCU_MPU_MPU_REG_RST_N_BIT);
	modem_gcu_bpu_set(chip, MODEM_GCU_BPU_BPU_RST_N_BIT | MODEM_GCU_BPU_BPU_RX_RST_N_BIT |
			  MODEM_GCU_BPU_BPU_TX_RST_N_BIT | MODEM_GCU_BPU_BPU_REG_RST_N_BIT);
	modem_gcu_tfu_set(chip, MODEM_GCU_TFU_TFU_RST_N_BIT | MODEM_GCU_TFU_TFU_REG_RST_N_BIT);
	modem_gcu_smu_set(chip, MODEM_GCU_SMU_SMU_RST_N_BIT | MODEM_GCU_SMU_SMU_REG_RST_N_BIT);
	modem_gcu_spu_set(chip, MODEM_GCU_SPU_SPU_RST_N_BIT | MODEM_GCU_SPU_SPU_REG_RST_N_BIT);
	modem_gcu_bf_set(chip, MODEM_GCU_BF_BF_RST_N_BIT | MODEM_GCU_BF_BF_REG_RST_N_BIT);
	modem_gcu_epa_set(chip, MODEM_GCU_EPA_EPA_RST_N_BIT | MODEM_GCU_EPA_EPA_REG_RST_N_BIT);
	modem_gcu_lcu_set(chip, MODEM_GCU_LCU_LCU_HLF_RST_N_BIT | MODEM_GCU_LCU_LCU_RST_N_BIT |
			  MODEM_GCU_LCU_LCU_REG_RST_N_BIT);
	modem_gcu_mux_fic_set(chip, MODEM_GCU_MUX_FIC_FIC_MUX_SOFT_RST_N_BIT |
			      MODEM_GCU_MUX_FIC_MUX_FIC_RST_N_BIT);
	modem_gcu_riu_clk_set(chip, 0);

	/* Assert reset (clocks already disabled) */
	modem_gcu_mpu_set(chip, 0);
	modem_gcu_bpu_set(chip, 0);
	modem_gcu_tfu_set(chip, 0);
	modem_gcu_smu_set(chip, 0);
	modem_gcu_spu_set(chip, 0);
	modem_gcu_bf_set(chip, 0);
	modem_gcu_epa_set(chip, 0);
	modem_gcu_lcu_set(chip, 0);
	modem_gcu_mux_fic_set(chip, MODEM_GCU_MUX_FIC_FIC_MUX_SOFT_RST_N_BIT);
	modem_gcu_riu_rst_set(chip, 0);
}

static void phy_reset(struct cl_chip *chip)
{
	/* Isolate FIC bus in case PHY chip reset is not required */
	modem_gcu_mux_fic_config_fic_isolate_setf(chip, 1);
	while (modem_gcu_mux_fic_config_fic_isolated_getf(chip) == 0)
		;
	modem_gcu_mux_fic_config_fic_isolate_setf(chip, 0);

	/*
	 * Stop the LCU recording.
	 * Stop on one channel actually stops the recording on all channels.
	 * This stop is required because PHY LCU is going to be reset.
	 */
	lcu_phy_lcu_ch_0_stop_set(chip, 1);

	/* PHY reset sequence */
	phy_disable(chip);
}

static void system_ctrl_reg_reset(struct cl_chip *chip)
{
	u32 regval = macsys_gcu_xt_control_get(chip);

	/* Set LMAC_RUN_STALL */
	regval |= LMAC_RUN_STALL;
	/* Clear LMAC_OCD_HALT_ON_RESET and clear LMAC_BRESET */
	regval &= ~(LMAC_OCD_HALT_ON_RESET | LMAC_BRESET);

	/* Reset MACHW */
	macsys_gcu_xt_control_set(chip, regval);
}

void cl_phy_reset(struct cl_chip *chip)
{
	system_ctrl_reg_reset(chip);
	phy_reset(chip);
	cmu_phy_0_rst_set(chip, CMU_PHY_0_RST_RESET);
}
EXPORT_SYMBOL(cl_phy_reset);

void cl_phy_enable(struct cl_chip *chip)
{
	/* Modem GCU modules - De-assert Reset */

	/* De-assert reset (clocks disabled) */
	modem_gcu_mpu_set(chip, MODEM_GCU_MPU_MPU_RST_N_BIT | MODEM_GCU_MPU_MPU_REG_RST_N_BIT);
	modem_gcu_bpu_set(chip, MODEM_GCU_BPU_BPU_RST_N_BIT | MODEM_GCU_BPU_BPU_RX_RST_N_BIT |
			  MODEM_GCU_BPU_BPU_TX_RST_N_BIT | MODEM_GCU_BPU_BPU_REG_RST_N_BIT);
	modem_gcu_tfu_set(chip, MODEM_GCU_TFU_TFU_RST_N_BIT | MODEM_GCU_TFU_TFU_REG_RST_N_BIT);
	modem_gcu_smu_set(chip, MODEM_GCU_SMU_SMU_RST_N_BIT | MODEM_GCU_SMU_SMU_REG_RST_N_BIT);
	modem_gcu_spu_set(chip, MODEM_GCU_SPU_SPU_RST_N_BIT | MODEM_GCU_SPU_SPU_REG_RST_N_BIT);
	modem_gcu_bf_set(chip, MODEM_GCU_BF_BF_RST_N_BIT | MODEM_GCU_BF_BF_REG_RST_N_BIT);
	modem_gcu_epa_set(chip, MODEM_GCU_EPA_EPA_RST_N_BIT | MODEM_GCU_EPA_EPA_REG_RST_N_BIT);
	modem_gcu_lcu_set(chip, MODEM_GCU_LCU_LCU_HLF_RST_N_BIT | MODEM_GCU_LCU_LCU_RST_N_BIT |
			  MODEM_GCU_LCU_LCU_REG_RST_N_BIT);
	modem_gcu_mux_fic_set(chip, MODEM_GCU_MUX_FIC_FIC_MUX_SOFT_RST_N_BIT |
			      MODEM_GCU_MUX_FIC_MUX_FIC_RST_N_BIT);
	modem_gcu_riu_rst_set(chip, MODEM_GCU_RIU_RST_RIUFE_RST_N_BIT | MODEM_GCU_RIU_RST_RIUAGC_RST_N_BIT |
			      MODEM_GCU_RIU_RST_RIU_MDM_B_RST_N_BIT | MODEM_GCU_RIU_RST_RIULB_RST_N_BIT |
			      MODEM_GCU_RIU_RST_RIURC_RST_N_BIT | MODEM_GCU_RIU_RST_RIU_RADAR_RST_N_BIT |
			      MODEM_GCU_RIU_RST_RIU_RST_N_BIT | MODEM_GCU_RIU_RST_RIU_REG_RST_N_BIT);

	/* Enable clocks */
	modem_gcu_mpu_set(chip, 0xFFFFFFFF);
	modem_gcu_bpu_set(chip, 0xFFFFFFFF);
	modem_gcu_tfu_set(chip, 0xFFFFFFFF);
	modem_gcu_smu_set(chip, 0xFFFFFFFF);
	modem_gcu_spu_set(chip, 0xFFFFFFFF);
	modem_gcu_bf_set(chip, 0xFFFFFFFF);
	modem_gcu_epa_set(chip, 0xFFFFFFFF);
	modem_gcu_lcu_set(chip, 0xFFFFFFFF);
	modem_gcu_mux_fic_set(chip, 0xFFFFFFFF);
	modem_gcu_riu_clk_set(chip, 0xFFFFFFFF);
	/*
	 * Configure minimum latency between 2 masters connected
	 * to same FIC, Read/Write transaction
	 */
	modem_gcu_mux_fic_config_set(chip, 0x00000808);
}

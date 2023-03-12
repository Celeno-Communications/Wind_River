// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include <linux/delay.h>
#include "rf_boot.h"
#include "file.h"
#include "phy.h"
#include "lcu.h"
#include "reg_access.h"
#include "reg_cmu.h"
#include "reg_modem_gcu.h"
#include "reg_rfic_regs.h"
#include "reg_riu.h"
#include "reg_mac_hw.h"
#include "reg_lcu_phy.h"
#include "reg_rfic_wrap.h"
#include "reg_macsys_gcu.h"

static void cl_clk_init(struct cl_chip *chip)
{
	u32 value = 0xFFFFFFFF;

	if (IS_PCI_BUS_TYPE(chip))
		value &= ~(CMU_CLK_EN_USBC_CLK_EN_BIT);
	else
		value &= ~(CMU_CLK_EN_PCIE_CLK_EN_BIT);

	cmu_clk_en_set(chip, value);
}

static int cl_pll1_init(struct cl_chip *chip)
{
	int retry = 0;

	/* Verify pll is locked */
	while (!rfic_regs_dpll_regout_1_dpll_fsm_lock_detect_getf(chip) &&
	       (++retry < 10)) {
		cl_dbg_chip_verbose(chip, "retry=%d\n", retry);
		usleep_range(100, 200);
	}

	/* Pll is not locked - fatal error */
	if (retry == 10) {
		cl_dbg_chip_err(chip, "retry limit reached - pll is not locked !!!\n");
		return -1;
	}

	return 0;
}

static int cl_cmu_init(struct cl_chip *chip)
{
	int ret = 0;

	cmu_phy_0_clk_en_set(chip, CMU_PHY_0_CLK_EN_PHY_0_APB_CLK_EN_BIT |
			     CMU_PHY_0_CLK_EN_PHY_0_MAIN_CLK_EN_BIT);

	if (IS_REAL_PHY(chip)) {
		ret = cl_pll1_init(chip);
		if (ret)
			return ret;
	}

	/* Set gl_mux_sel bit to work with pll1 instead of crystal */
	cmu_control_gl_mux_sel_setf(chip, 1);
	cmu_bt_clk_en_set(chip, 1);
	cmu_rst_set(chip, CMU_RST_RESET);
	cmu_phy_0_rst_set(chip, CMU_PHY_0_RST_RESET);
	cmu_bt_rst_set(chip, 1);

	return ret;
}

static int cl_load_riu_rsf_memory(struct cl_chip *chip, const char *filename)
{
	char *buf = NULL;
	loff_t size, i = 0;

	size = cl_file_open_and_read(chip, filename, &buf);

	if (!buf)
		return -ENOMEM;

	/* Enable re-sampling filter init */
	riu_rsf_control_rsf_init_en_setf(chip, 0x1);

	while (i < size) {
		riu_rsf_init_set(chip, *(u32 *)&buf[i]);
		i += 4;
	}

	kfree(buf);

	return 0;
}

static int cl_load_agc_data(struct cl_chip *chip, const char *filename)
{
	char *buf = NULL;
	loff_t size, i = 0;

	size = cl_file_open_and_read(chip, filename, &buf);

	if (!buf)
		return -ENOMEM;

	/* Enable AGC FSM ram init state */
	riu_agcfsm_ram_init_1_agc_fsm_ram_init_en_setf(chip, 0x1);
	/* Start writing the firmware from WPTR=0 */
	riu_agcfsm_ram_init_1_agc_fsm_ram_init_wptr_setf(chip, 0x0);
	/* Allow WPTR register to be writable */
	riu_agcfsm_ram_init_1_agc_fsm_ram_init_wptr_set_setf(chip, 0x1);
	/* Enable auto increment WPTR by 1 upon any write */
	riu_agcfsm_ram_init_1_agc_fsm_ram_init_ainc_1_setf(chip, 0x1);

	while (i < size) {
		riu_agcfsm_ram_init_2_set(chip, *(u32 *)&buf[i]);
		i += 4;
	}

	/* Disable AGC FSM ram init state */
	riu_agcfsm_ram_init_1_agc_fsm_ram_init_en_setf(chip, 0x0);

	kfree(buf);

	return 0;
}

static int cl_load_agc_fw(struct cl_chip *chip, const char *filename)
{
	int ret = 0;

	/* Switch AGC to programming mode */

	/* Disable RIU Modules clocks (RC,LB,ModemB,FE,ADC,Regs,AGC,Radar) */
	modem_gcu_riu_clk_set(chip, MODEM_GCU_RIU_CLK_RESET);

	/* Switch AGC MEM clock to 480MHz */
	modem_gcu_riu_clk_bw_agc_mem_clk_bw_setf(chip, 3);

	/* Enable RIU Modules clocks (RC,LB,ModemB,FE,ADC,Regs,AGC,Radar) */
	modem_gcu_riu_clk_set(chip, 0xFFFFFFFF);

	/* Assert AGC FSM reset */
	riu_rwnxagccntl_agcfsmreset_setf(chip, 1);

	/* Load AGC RAM data */
	ret = cl_load_agc_data(chip, filename);
	if (ret)
		goto out;

	/* Switch AGC back to operational mode */

	/* Disable RIU Modules clocks (RC, LB, ModemB, FE, ADC, Regs, AGC, Radar) */
	modem_gcu_riu_clk_set(chip, MODEM_GCU_RIU_CLK_RESET);
	/* Switch AGC MEM clock back to 80M */
	modem_gcu_riu_clk_bw_agc_mem_clk_bw_setf(chip, 1);
	/* Enable RIU Modules clocks (RC, LB, ModemB, FE, ADC, Regs, AGC, Radar) */
	modem_gcu_riu_clk_set(chip, 0xFFFFFFFF);

	/* Release AGC FSM reset */
	riu_rwnxagccntl_agcfsmreset_setf(chip, 0);

out:
	return ret;
}

int cl_rf_boot(struct cl_chip *chip)
{
	int ret = 0;

	/* Call only once per chip after ASIC reset - configure both phys */
	ret = cl_cmu_init(chip);
	if (ret != 0)
		goto out;

	cl_clk_init(chip);
	cmu_phase_sel_set(chip, CMU_PHASE_SEL_AUXADC_CLK_PHASE_SEL_BIT |
				CMU_PHASE_SEL_BT_CLK_PHASE_SEL_BIT);

	mac_hw_mac_cntrl_1_active_clk_gating_setf(chip, 1); /* Disable MPIF clock */
	mac_hw_state_cntrl_next_state_setf(chip, 2);        /* Move to doze */

	/* Enable all PHY modules */
	cl_phy_enable(chip);

	mac_hw_doze_cntrl_2_wake_up_sw_setf(chip, 1); /* Exit from doze */
	mac_hw_state_cntrl_next_state_setf(chip, 0);  /* Move to idle */

	/* Load RIU re-sampling filter memory with coefficients */
	ret = cl_load_riu_rsf_memory(chip, "riu_rsf.bin");
	if (ret != 0) {
		cl_dbg_chip_err(chip, "riu_rsf.bin load failed %d\n", ret);
		goto out;
	}

	/* Load AGC FW */
	ret = cl_load_agc_fw(chip, "agcram.bin");
	if (ret) {
		cl_dbg_chip_err(chip, "agcram.bin load failed %d\n", ret);
		goto out;
	}

	rfic_wrap_wifi_adc_sw_ctrl_set(chip, 0);

	/* Invert status of RTS */
	macsys_gcu_uart_if_rts_if_mode_setf(chip, 1);
	/* Switch UART clocks to fast ones (640 MHz) */
	cmu_control_gl_mux_sel_setf(chip, 1);

out:
	return ret;
}

int cl_rf_boot_recovery(struct cl_chip *chip, u8 bw)
{
	int ret = 0;

	mac_hw_mac_cntrl_1_active_clk_gating_setf(chip, 1); /* Disable MPIF clock */
	mac_hw_state_cntrl_next_state_setf(chip, 2);        /* Move to doze */

	/* Enable all PHY modules */
	cl_phy_enable(chip);

	/* Restart LCU recording */
	lcu_phy_lcu_ch_0_stop_set(chip, 0);

	if (cl_lcu_ela_is_on(chip)) {
		cl_lcu_stop(chip);
		cl_lcu_apply_config(chip);
	}

	mac_hw_doze_cntrl_2_wake_up_sw_setf(chip, 1); /* Exit from doze */
	mac_hw_state_cntrl_next_state_setf(chip, 0);  /* Move to idle */

	/* Load RIU re-sampling filter memory with coefficients */
	ret = cl_load_riu_rsf_memory(chip, "riu_rsf.bin");
	if (ret != 0) {
		cl_dbg_chip_err(chip, "riu_rsf.bin load failed %d\n", ret);
		goto out;
	}

	/* Load AGC FW */
	ret = cl_load_agc_fw(chip, "agcram.bin");
	if (ret) {
		cl_dbg_chip_err(chip, "agcram.bin load failed %d\n", ret);
		goto out;
	}

out:
	return ret;
}
EXPORT_SYMBOL(cl_rf_boot_recovery);


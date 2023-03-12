// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_enhanced_tim.h"
#include "reg_access.h"
#include "cl_ipc.h"
#include "cl_utils.h"
#include "chip_ops.h"

/*
 * The kernel's test_and_set_bit() gets unsigned long * as an argument, but we actually
 * pass a pointer to u32, what cause to alignment fault in 64bit platforms.
 * This function gets a pointer to u32 to prevent this alignment fault.
 * Notice that the kernel's function sets the bit as an atomic operation,
 * and our function doesn't. Vut it's not an issue since we set the bit from one context only.
 */
static int cl_test_and_set_bit(unsigned long nr, u32 *addr)
{
	u32 *new_addr, mask, old;

	new_addr = ((u32 *)addr) + (nr >> 5);
	mask = 1 << (nr & 31);
	old = *new_addr & mask;
	*new_addr |= mask;

	return (old != 0);
}

static int CFM_TEST_AND_CLEAR_BIT(unsigned long nr, u32 *addr)
{
	u32 *new_addr, mask, old;

	new_addr = ((u32 *)addr) + (nr >> 5);
	mask = 1 << (nr & 31);
	old = *new_addr & mask;
	*new_addr &= ~mask;

	return (old != 0);
}

bool cl_enhanced_tim_is_ac_clear(struct cl_hw *cl_hw, u8 ac)
{
	u32 *source = cl_hw->enhanced_tim.tx_rx_agg[ac];
	int i;

	for (i = 0; i < CL_BITS_TO_U32S(IPC_TIM_AGG_SIZE); i++)
		if (source[i])
			return false;

	return true;
}

void cl_enhanced_tim_reset(struct cl_hw *cl_hw)
{
	/*
	 * There is no need to reset cl_hw->ipc_env->shared->enhanced_tim.
	 * It is done as part of ipc_shared_env_init()
	 */
	memset(&cl_hw->enhanced_tim, 0, sizeof(struct cl_ipc_enhanced_tim));
}


void cl_enhanced_tim_clear_tx_agg(struct cl_hw *cl_hw, u32 ipc_queue_idx,
				  u8 ac, struct cl_sta *cl_sta, u8 tid)
{
	/* Pointer to HOST enhanced TIM */
	u32 *source = cl_hw->enhanced_tim.tx_rx_agg[ac];
	u32 ipc_queue_idx_common = IPC_TX_QUEUE_IDX_TO_COMMON_QUEUE_IDX(ipc_queue_idx);
	/*
	 * Does the UMAC enhanced TIM need update?
	 * If the TIM element is set then clear it and update the UMAC TIM element
	 */
	if (CFM_TEST_AND_CLEAR_BIT(ipc_queue_idx_common, source)) {
		/* Offset to UMAC enhanced TIM array position */
		u32 agg_offset = ipc_queue_idx_common / (BITS_PER_BYTE * sizeof(u32));
		u32 sram_offset = (offsetof(struct cl_ipc_shared_env, enhanced_tim) +
				   offsetof(struct cl_ipc_enhanced_tim, tx_rx_agg) +
				   (sizeof(u32) * ac * CL_BITS_TO_U32S(IPC_TIM_AGG_SIZE)) +
				   (sizeof(u32) * agg_offset));
		if (chip_ops_write32(cl_hw->chip,
				     SHARED_RAM_START_ADDR + sram_offset,
				     source[agg_offset]))
			cl_dbg_err(cl_hw, "chip_ops_write32 failed !\n");
		/* Update tim element */
		if (cl_sta && test_sta_flag(cl_sta->stainfo, WLAN_STA_PS_STA))
			ieee80211_sta_set_buffered(&cl_sta->stainfo->sta, tid,
						   false);
	}
}

void cl_enhanced_tim_clear_tx_single(struct cl_hw *cl_hw, u32 ipc_queue_idx, u8 ac,
				     bool no_ps_buffer, struct cl_sta *cl_sta, u8 tid)
{
	/* Pointer to HOST enhanced TIM */
	u32 *source = cl_hw->enhanced_tim.tx_single[ac];
	/* Staton index: 0 - 128 (do not use cl_sta->sta_idx which is 0 -127) */
	u32 sta_idx = ipc_queue_idx % FW_MAX_NUM_STA;

	/*
	 * Does the UMAC enhanced TIM need update?
	 * If the TIM element is set then clear it and update the UMAC TIM element
	 */
	if (CFM_TEST_AND_CLEAR_BIT(sta_idx, source)) {
		/* Offset to UMAC enhanced TIM array position */
		u32 sta_offset = sta_idx / (BITS_PER_BYTE * sizeof(u32));
		u32 sram_offset = (offsetof(struct cl_ipc_shared_env, enhanced_tim) +
				  offsetof(struct cl_ipc_enhanced_tim, tx_single) +
				  (sizeof(u32) * ac * CL_BITS_TO_U32S(FW_MAX_NUM_STA)) +
				  (sizeof(u32) * sta_offset));
		if (chip_ops_write32(cl_hw->chip,
				     SHARED_RAM_START_ADDR + sram_offset,
				     source[sta_offset]))
			cl_dbg_err(cl_hw, "chip_ops_write32 failed !\n");
		/* Update tim element */
		if (!no_ps_buffer && cl_sta &&
		    test_sta_flag(cl_sta->stainfo, WLAN_STA_PS_STA))
			ieee80211_sta_set_buffered(&cl_sta->stainfo->sta, tid,
						   false);
	}
}

void cl_enhanced_tim_set_tx_agg(struct cl_hw *cl_hw, u32 ipc_queue_idx, u8 ac,
				bool no_ps_buffer, struct cl_sta *cl_sta, u8 tid)
{
	/* Pointer to HOST enhanced TIM */
	u32 *source = cl_hw->enhanced_tim.tx_rx_agg[ac];
	u32 ipc_queue_idx_common = IPC_TX_QUEUE_IDX_TO_COMMON_QUEUE_IDX(ipc_queue_idx);
	/*
	 * Does the UMAC enhanced TIM need update?
	 * If the TIM element is cleared then set it and update the UMAC TIM element
	 */
	if (!cl_test_and_set_bit(ipc_queue_idx_common, source)) {
		/* Offset to UMAC enhanced TIM array position */
		u32 agg_offset = ipc_queue_idx_common / (BITS_PER_BYTE * sizeof(u32));
		u32 sram_offset = (offsetof(struct cl_ipc_shared_env, enhanced_tim) +
				  offsetof(struct cl_ipc_enhanced_tim, tx_rx_agg) +
				  (sizeof(u32) * ac * CL_BITS_TO_U32S(IPC_TIM_AGG_SIZE)) +
				  (sizeof(u32) * agg_offset));
		if (chip_ops_write32(cl_hw->chip,
				     SHARED_RAM_START_ADDR + sram_offset,
				      source[agg_offset]))
			cl_dbg_err(cl_hw, "chip_ops_write32 failed !\n");
		/* Update tim element */
		if (!no_ps_buffer && cl_sta &&
		    test_sta_flag(cl_sta->stainfo, WLAN_STA_PS_STA))
			ieee80211_sta_set_buffered(&cl_sta->stainfo->sta, tid,
						   true);
	}
}

void cl_enhanced_tim_set_tx_single(struct cl_hw *cl_hw, u32 ipc_queue_idx, u8 ac,
				   bool no_ps_buffer, struct cl_sta *cl_sta, u8 tid)
{
	/* Pointer to HOST enhanced TIM */
	u32 *source = cl_hw->enhanced_tim.tx_single[ac];
	/* Staton index: 0 - 128 (do not use cl_sta->sta_idx which is 0 -127) */
	u32 sta_idx = ipc_queue_idx % FW_MAX_NUM_STA;

	/*
	 * Does the UMAC enhanced TIM need update?
	 * If the TIM element is cleared then set it and update the UMAC TIM element
	 */
	if (!cl_test_and_set_bit(sta_idx, source)) {
		/* Offset to UMAC enhanced TIM array position */
		u32 sta_offset = sta_idx / (BITS_PER_BYTE * sizeof(u32));
		u32 sram_offset = (offsetof(struct cl_ipc_shared_env, enhanced_tim) +
				  offsetof(struct cl_ipc_enhanced_tim, tx_single) +
				  (sizeof(u32) * ac * CL_BITS_TO_U32S(FW_MAX_NUM_STA)) +
				  (sizeof(u32) * sta_offset));
		if (chip_ops_write32(cl_hw->chip,
				     SHARED_RAM_START_ADDR + sram_offset,
				     source[sta_offset]))
			cl_dbg_err(cl_hw, "chip_ops_write32 failed !\n");
		/* Update tim element */
		if (!no_ps_buffer && cl_sta &&
		    test_sta_flag(cl_sta->stainfo, WLAN_STA_PS_STA))
			ieee80211_sta_set_buffered(&cl_sta->stainfo->sta, tid,
						   true);
	}
}

void cl_enhanced_tim_clear_rx(struct cl_hw *cl_hw, u8 ac, u8 sta_idx)
{
	/* Pointer to HOST enhanced TIM */
	u32 *source = cl_hw->enhanced_tim.tx_rx_agg[ac];
	u32 ipc_queue_idx_common = IPC_RX_QUEUE_IDX_TO_COMMON_QUEUE_IDX(sta_idx);
	/*
	 * Does the UMAC enhanced TIM need update?
	 * If the TIM element is set then clear it and update the UMAC TIM element
	 */
	if (IS_PCI_BUS_TYPE(cl_hw->chip) &&
	    CFM_TEST_AND_CLEAR_BIT(ipc_queue_idx_common, source)) {
		/* Offset to UMAC enhanced TIM array position */
		u32 sta_offset = ipc_queue_idx_common / (BITS_PER_BYTE * sizeof(u32));
		// TOOD: needed for USB ?
		/* Pointer to UMAC enhanced TIM for singles or aggregation */
		u32 __iomem *target =
			(u32 __iomem *)cl_hw->ipc_env->shared->enhanced_tim.tx_rx_agg[ac];

		iowrite32(source[sta_offset], (void __iomem *)&target[sta_offset]);
	}
}

void cl_enhanced_tim_set_rx(struct cl_hw *cl_hw, u8 ac, u8 sta_idx)
{
	/* Pointer to HOST enhanced TIM */
	u32 *source = cl_hw->enhanced_tim.tx_rx_agg[ac];
	u32 ipc_queue_idx_common = IPC_RX_QUEUE_IDX_TO_COMMON_QUEUE_IDX(sta_idx);
	/*
	 * Does the UMAC enhanced TIM need update?
	 * If the TIM element is cleared then set it and update the UMAC TIM element
	 */
	if (!cl_test_and_set_bit(ipc_queue_idx_common, source)) {
		if (IS_PCI_BUS_TYPE(cl_hw->chip)) {
			/* Offset to UMAC enhanced TIM array position */
			u32 sta_offset = ipc_queue_idx_common /
					 (BITS_PER_BYTE * sizeof(u32));
			/* Pointer to UMAC enhanced TIM */
			u32 __iomem *target =
				(u32 __iomem *)cl_hw->ipc_env->shared->enhanced_tim.tx_rx_agg[ac];

			iowrite32(source[sta_offset], (void __iomem *)&target[sta_offset]);
		}
		cl_hw->ipc_host2xmac_trigger_set(cl_hw->chip, BIT(IPC_IRQ_A2E_RX_STA_MAP(ac)));
	}
}

void cl_enhanced_tim_clear_rx_sta(struct cl_hw *cl_hw, u8 sta_idx)
{
	u8 ac;

	for (ac = 0; ac < AC_MAX; ac++)
		cl_enhanced_tim_clear_rx(cl_hw, ac, sta_idx);
}

static void print_binary_tim(char *buf, int *len, u32 x)
{
	/*
	 * Print from right to left
	 * Example: x = 0x0000030009
	 * Output: 10010000000000001100000000000000
	 */
	u8 i;

	for (i = 0; i < 32; i++)
		*len += snprintf(buf + *len, PAGE_SIZE - *len,
				 "%u", x & (1 << i) ? 1 : 0);

	*len += snprintf(buf + *len, PAGE_SIZE - *len, " ");
}

static int cl_enhanced_tim_print_rx(struct cl_hw *cl_hw)
{
	u8 i, j;
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;
	struct cl_ipc_shared_env __iomem *shared = cl_hw->ipc_env->shared;

	for (i = 0; i < AC_MAX; i++) {
		cl_snprintf(&buf, &len, &buf_size, "AC = %u - ", i);

		for (j = 1; j < CL_BITS_TO_U32S(CL_MAX_NUM_STA); j += 2)
			print_binary_tim(buf, &len,
					 __raw_readl(&shared->enhanced_tim.tx_rx_agg[i][j]));

		cl_snprintf(&buf, &len, &buf_size, "\n");
	}

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

static int cl_enhanced_tim_cli_help(struct cl_hw *cl_hw)
{
	char *buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!buf)
		return -ENOMEM;

	snprintf(buf, PAGE_SIZE,
		 "tim usage:\n"
		 "-c : Clear rx bit [ac].[sta_idx]\n"
		 "-p : Print rx enhanced tim\n"
		 "-s : Set rx bit [ac].[sta_idx]\n");

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

int cl_enhanced_tim_cli(struct cl_hw *cl_hw, struct cli_params *cli_params)
{
	u32 expected_params = 0;
	bool clear_rx_bit = false;
	bool print_rx_enhanced = false;
	bool set_rx_bit = false;

	switch (cli_params->option) {
	case 'c':
		clear_rx_bit = true;
		expected_params = 2;
		break;
	case 'p':
		print_rx_enhanced = true;
		expected_params = 0;
		break;
	case 's':
		set_rx_bit = true;
		expected_params = 2;
		break;
	case '?':
		return cl_enhanced_tim_cli_help(cl_hw);
	default:
		cl_dbg_err(cl_hw, "Illegal option (%c) - try '?' for help\n", cli_params->option);
		goto out_err;
	}

	if (cli_params->num_params != expected_params) {
		cl_dbg_err(cl_hw, "Wrong number of arguments (expected %u) (actual %u)\n",
			   expected_params, cli_params->num_params);
		goto out_err;
	}

	if (clear_rx_bit) {
		u8 ac = (u8)cli_params->params[0];
		u8 sta_idx = (u8)cli_params->params[1];

		cl_enhanced_tim_clear_rx(cl_hw, ac, sta_idx);
		return 0;
	}

	if (print_rx_enhanced)
		return cl_enhanced_tim_print_rx(cl_hw);

	if (set_rx_bit) {
		u8 ac = (u8)cli_params->params[0];
		u8 sta_idx = (u8)cli_params->params[1];

		cl_enhanced_tim_set_rx(cl_hw, ac, sta_idx);
		return 0;
	}

out_err:
	return -EIO;
}

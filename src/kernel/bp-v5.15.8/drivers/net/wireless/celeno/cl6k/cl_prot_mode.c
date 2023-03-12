// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_prot_mode.h"
#include "cl_msg_tx.h"
#include <linux/string.h>

void cl_prot_mode_init(struct cl_hw *cl_hw)
{
	struct cl_prot_mode *prot_mode = &cl_hw->prot_mode;
	u8 init = cl_hw->conf->ce_prot_mode;

	prot_mode->current_val = init;
	prot_mode->default_val = init;
	prot_mode->dynamic_val = (init != TXL_NO_PROT) ?
				  init : TXL_PROT_RTS_FW;
}

void cl_prot_mode_set(struct cl_hw *cl_hw, u8 prot_mode_new)
{
	struct cl_prot_mode *prot_mode = &cl_hw->prot_mode;
	struct cl_tcv_conf *conf = cl_hw->conf;

	if (prot_mode->current_val != prot_mode_new) {
		prot_mode->current_val = prot_mode_new;
		cl_msg_tx_prot_mode(cl_hw,
				    conf->ce_prot_log_nav_en,
				    prot_mode_new,
				    conf->ce_prot_rate_format,
				    conf->ce_prot_rate_mcs,
				    conf->ce_prot_rate_pre_type);
	}
}

void cl_prot_mode_disable(struct cl_hw *cl_hw)
{
	cl_prot_mode_set(cl_hw, TXL_NO_PROT);
}

void cl_prot_mode_enable(struct cl_hw *cl_hw)
{
	cl_prot_mode_set(cl_hw, cl_hw->prot_mode.dynamic_val);
}

void cl_prot_mode_restore_default(struct cl_hw *cl_hw)
{
	cl_prot_mode_set(cl_hw, cl_hw->prot_mode.default_val);
}

u8 cl_prot_mode_get(struct cl_hw *cl_hw)
{
	return cl_hw->prot_mode.current_val;
}


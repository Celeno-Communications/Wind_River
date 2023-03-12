// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_edca.h"
#include "cl_sta.h"
#include "cl_vendor_cmd.h"
#include "cl_msg_tx.h"
#include "cl_utils.h"

static u8 conv_to_fw_ac[EDCA_AC_MAX] = {
	[EDCA_AC_BE] = AC_BE,
	[EDCA_AC_BK] = AC_BK,
	[EDCA_AC_VI] = AC_VI,
	[EDCA_AC_VO] = AC_VO
};

static const char *edca_ac_str[EDCA_AC_MAX] = {
	[EDCA_AC_BE] = "BE",
	[EDCA_AC_BK] = "BK",
	[EDCA_AC_VI] = "VI",
	[EDCA_AC_VO] = "VO"
};

static bool cl_edca_is_high_rate(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	struct cl_wrs_rate *max_rate_cap = &cl_sta->wrs_sta.max_rate_cap;
	struct cl_wrs_rate_params *rate_params = &cl_sta->wrs_sta.tx_su_params.rate_params;
	u8 max_bw = max_rate_cap->bw;
	u8 max_nss = max_rate_cap->nss;
	u8 max_mcs = max_rate_cap->mcs;

	return ((rate_params->bw == max_bw) &&
		(rate_params->nss == max_nss) &&
		(rate_params->mcs >= max_mcs - 1));
}

static int cl_edca_print(struct cl_hw *cl_hw)
{
	u8 ac = 0;
	struct edca_params *params;
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;

	cl_snprintf(&buf, &len, &buf_size,
		    "---------------------------------------\n"
		    "| ac | aifsn | cw_min | cw_max | txop |\n"
		    "|----+-------+--------+--------+------|\n");

	for (ac = 0; ac < AC_MAX; ac++) {
		params = &cl_hw->edca_db.hw_params[ac];
		cl_snprintf(&buf, &len, &buf_size,
			    "| %s | %5u | %6u | %6u | %4u |\n",
			    edca_ac_str[ac], params->aifsn, params->cw_min,
			    params->cw_max, params->txop);
	}

	cl_snprintf(&buf, &len, &buf_size,
		    "---------------------------------------\n\n");

	err = cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);

	return err;
}

static void cl_edca_set_conf(struct cl_hw *cl_hw, u8 ac)
{
	struct edca_params params = {
		.aifsn = cl_hw->conf->ce_wmm_aifsn[ac],
		.cw_min = cl_hw->conf->ce_wmm_cwmin[ac],
		.cw_max = cl_hw->conf->ce_wmm_cwmax[ac],
		.txop = cl_hw->conf->ce_wmm_txop[ac]
	};

	cl_edca_set(cl_hw, ac, &params, NULL);
}

static void cl_edca_ac_set(struct cl_hw *cl_hw, u8 ac, u8 aifsn, u8 cw_min, u8 cw_max, u16 txop)
{
	pr_debug("ac = %u, aifsn = %u, cw_min = %u, cw_max = %u, txop = %u\n",
		 ac, aifsn, cw_min, cw_max, txop);

	cl_hw->conf->ce_wmm_aifsn[ac] = aifsn;
	cl_hw->conf->ce_wmm_cwmin[ac] = cw_min;
	cl_hw->conf->ce_wmm_cwmax[ac] = cw_max;
	cl_hw->conf->ce_wmm_txop[ac] = txop;

	cl_edca_set_conf(cl_hw, ac);
}

static void cl_edca_aifsn_set(struct cl_hw *cl_hw, s32 aifsn[AC_MAX])
{
	u8 ac = 0;

	pr_debug("Set aifsn: BE = %d, BK = %d, VI = %d, VO = %d\n",
		 aifsn[0], aifsn[1], aifsn[2], aifsn[3]);

	for (ac = 0; ac < AC_MAX; ac++) {
		cl_hw->conf->ce_wmm_aifsn[ac] = (u8)aifsn[ac];
		cl_edca_set_conf(cl_hw, ac);
	}
}

static void cl_edca_cwmin_set(struct cl_hw *cl_hw, s32 cw_min[AC_MAX])
{
	u8 ac = 0;

	pr_debug("Set cw_min: BE = %d, BK = %d, VI = %d, VO = %d\n",
		 cw_min[0], cw_min[1], cw_min[2], cw_min[3]);

	for (ac = 0; ac < AC_MAX; ac++) {
		cl_hw->conf->ce_wmm_cwmin[ac] = (u8)cw_min[ac];
		cl_edca_set_conf(cl_hw, ac);
	}
}

static void cl_edca_cwmax_set(struct cl_hw *cl_hw, s32 cw_max[AC_MAX])
{
	u8 ac = 0;

	pr_debug("Set cw_max: BE = %d, BK = %d, VI = %d, VO = %d\n",
		 cw_max[0], cw_max[1], cw_max[2], cw_max[3]);

	for (ac = 0; ac < AC_MAX; ac++) {
		cl_hw->conf->ce_wmm_cwmax[ac] = (u8)cw_max[ac];
		cl_edca_set_conf(cl_hw, ac);
	}
}

static void cl_edca_txop_set(struct cl_hw *cl_hw, s32 txop[AC_MAX])
{
	u8 ac = 0;

	pr_debug("Set txop: BE = %d, BK = %d, VI = %d, VO = %d\n",
		 txop[0], txop[1], txop[2], txop[3]);

	for (ac = 0; ac < AC_MAX; ac++) {
		cl_hw->conf->ce_wmm_txop[ac] = (u16)txop[ac];
		cl_edca_set_conf(cl_hw, ac);
	}
}

static void cl_edca_dynamic_config(struct cl_hw *cl_hw)
{
	/*
	 * Dynamic configuration for clean environment,
	 * single downlink active station and high rate
	 */
	if (cl_hw->edca_db.dyn_param.set)
		return;

	cl_hw->edca_db.dyn_param.set = true;

	cl_edca_set(cl_hw, EDCA_AC_BE, &cl_hw->edca_db.dyn_param.params, NULL);
}

static void cl_edca_dynamic_restore(struct cl_hw *cl_hw)
{
	/* Restore default configuration */
	if (!cl_hw->edca_db.dyn_param.set)
		return;

	cl_hw->edca_db.dyn_param.set = false;

	cl_edca_set_conf(cl_hw, EDCA_AC_BE);
}

static void cl_edca_dynamic_set(struct cl_hw *cl_hw, u8 aifsn, u8 cw_min, u8 cw_max, u16 txop)
{
	/*
	 * Set dynamic configuration to be used for clean environemnt and
	 * single active station.
	 * If all dynamic parameters are set to 0, feature is disabled.
	 */

	struct edca_params *params = &cl_hw->edca_db.dyn_param.params;

	params->aifsn = aifsn;
	params->cw_min = cw_min;
	params->cw_max = cw_max;
	params->txop = txop;

	cl_hw->edca_db.dyn_param.enable =
		params->aifsn || params->cw_min || params->cw_max || params->txop;

	if (cl_hw->edca_db.dyn_param.set && !cl_hw->edca_db.dyn_param.enable)
		cl_edca_dynamic_restore(cl_hw);
}

static int cl_edca_cli_help(struct cl_hw *cl_hw)
{
	char *buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!buf)
		return -ENOMEM;

	snprintf(buf, PAGE_SIZE,
		 "edca usage:\n"
		 "-a : Print current configuration\n"
		 "-b : Set per AC [0-BE,1-BK,2-VI,3-VO].[aifsn].[cw_min]."
			"[cw_max].[txop]\n"
		 "-c : Set aifsn [BE].[BK].[VI].[VO]\n"
		 "-d : Set cw_min [BE].[BK].[VI].[VO]\n"
		 "-e : Set cw_max [BE].[BK].[VI].[VO]\n"
		 "-f : Set txop  [BE].[BK].[VI].[VO]\n"
		 "-g : Set dynamic BE configuration [aifsn].[cw_min].[cw_max]."
			"[txop]\n");

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

void cl_edca_hw_conf(struct cl_hw *cl_hw)
{
	u8 ac = 0;
	struct cl_tcv_conf *conf = cl_hw->conf;

	for (ac = 0; ac < AC_MAX; ac++) {
		struct edca_params params = {
			.aifsn = conf->ce_wmm_aifsn[ac],
			.cw_min = conf->ce_wmm_cwmin[ac],
			.cw_max = conf->ce_wmm_cwmax[ac],
			.txop = conf->ce_wmm_txop[ac]
		};

		cl_edca_set(cl_hw, ac, &params, NULL);
	}

	cl_edca_dynamic_set(cl_hw,
			    conf->ce_dynamic_edca[EDCA_AIFSN],
			    conf->ce_dynamic_edca[EDCA_CW_MIN],
			    conf->ce_dynamic_edca[EDCA_CW_MAX],
			    conf->ce_dynamic_edca[EDCA_TXOP]);
}

void cl_edca_set(struct cl_hw *cl_hw, u8 ac, struct edca_params *params,
		 struct ieee80211_he_mu_edca_param_ac_rec *mu_edca)
{
	u32 edca_reg_val = 0;

	if (ac >= AC_MAX) {
		pr_err("%s: Invalid AC index\n", __func__);
		return;
	}

	edca_reg_val  = (u32)(params->aifsn);
	edca_reg_val |= (u32)(params->cw_min << 4);
	edca_reg_val |= (u32)(params->cw_max << 8);
	edca_reg_val |= (u32)(params->txop << 12);

	memcpy(&cl_hw->edca_db.hw_params[ac], params, sizeof(struct edca_params));

	cl_msg_tx_set_edca(cl_hw, conv_to_fw_ac[ac], edca_reg_val, mu_edca);

	cl_dbg_trace(cl_hw, "EDCA-%s: aifsn=%u, cw_min=%u, cw_max=%u, txop=%u\n",
		     edca_ac_str[ac], params->aifsn, params->cw_min, params->cw_max, params->txop);
}

void cl_edca_restore_conf(struct cl_hw *cl_hw, u8 ac)
{
	cl_edca_set_conf(cl_hw, ac);
}

void cl_edca_recovery(struct cl_hw *cl_hw)
{
	u8 ac;

	for (ac = 0; ac < AC_MAX; ac++)
		cl_edca_set(cl_hw, ac, &cl_hw->edca_db.hw_params[ac], NULL);
}

void cl_edca_dynamic_update_single_sta(struct cl_hw *cl_hw,
				       struct cl_sta *cl_sta,
				       bool is_single_sta)
{
	struct edca_dynamic *dyn_param = &cl_hw->edca_db.dyn_param;

	if (!dyn_param->enable)
		return;

	dyn_param->is_single_sta = is_single_sta;

	if (is_single_sta) {
		dyn_param->sta_idx = cl_sta->sta_idx;
		dyn_param->high_rate = cl_edca_is_high_rate(cl_hw, cl_sta);

		if (dyn_param->high_rate)
			cl_edca_dynamic_config(cl_hw);
	} else {
		cl_edca_dynamic_restore(cl_hw);
	}
}

void cl_edca_dynamic_update_sta_rate(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	struct edca_dynamic *dyn_param = &cl_hw->edca_db.dyn_param;

	if (!dyn_param->enable)
		return;

	if (dyn_param->is_single_sta && dyn_param->sta_idx == cl_sta->sta_idx) {
		dyn_param->high_rate = cl_edca_is_high_rate(cl_hw, cl_sta);

		if (dyn_param->high_rate)
			cl_edca_dynamic_config(cl_hw);
		else
			cl_edca_dynamic_restore(cl_hw);
	}
}

int cl_edca_cli(struct cl_hw *cl_hw, struct cli_params *cli_params)
{
	u8 ac, aifsn, cw_min, cw_max;
	u16 txop;

	switch (cli_params->option) {
	case 'a':
		return cl_edca_print(cl_hw);
	case 'b':
		if (cli_params->num_params != 5)
			goto err_num_of_arg;

		ac = (u8)cli_params->params[0];
		aifsn = (u8)cli_params->params[1];
		cw_min = (u8)cli_params->params[2];
		cw_max = (u8)cli_params->params[3];
		txop = (u16)cli_params->params[4];

		cl_edca_ac_set(cl_hw, ac, aifsn, cw_min, cw_max, txop);
		break;
	case 'c':
		if (cli_params->num_params != AC_MAX)
			goto err_num_of_arg;

		cl_edca_aifsn_set(cl_hw, cli_params->params);
		break;
	case 'd':
		if (cli_params->num_params != AC_MAX)
			goto err_num_of_arg;

		cl_edca_cwmin_set(cl_hw, cli_params->params);
		break;
	case 'e':
		if (cli_params->num_params != AC_MAX)
			goto err_num_of_arg;

		cl_edca_cwmax_set(cl_hw, cli_params->params);
		break;
	case 'f':
		if (cli_params->num_params != AC_MAX)
			goto err_num_of_arg;

		cl_edca_txop_set(cl_hw, cli_params->params);
		break;
	case 'g':
		if (cli_params->num_params != 4)
			goto err_num_of_arg;

		aifsn = (u8)cli_params->params[0];
		cw_min = (u8)cli_params->params[1];
		cw_max = (u8)cli_params->params[2];
		txop = (u16)cli_params->params[3];

		cl_edca_dynamic_set(cl_hw, aifsn, cw_min, cw_max, txop);
		break;
	case '?':
		return cl_edca_cli_help(cl_hw);
	default:
		cl_dbg_err(cl_hw, "Illegal option (%c) - try '?' for help\n", cli_params->option);
		break;
	}

	return 0;

err_num_of_arg:
	pr_err("wrong number of arguments\n");
	return 0;
}

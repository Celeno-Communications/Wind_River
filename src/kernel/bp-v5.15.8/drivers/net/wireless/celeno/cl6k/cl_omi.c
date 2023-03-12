// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_omi.h"
#include "cl_mac80211.h"
#include "cl_sta.h"
#include "cl_mac_addr.h"
#include "cl_tx.h"
#include "cl_wrs_api.h"
#include "cl_enhanced_tim.h"

#define MAX_OMI_NSTS (WRS_SS_MAX - 1)

static int cl_omi_cli_help(struct cl_hw *cl_hw)
{
	char *buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!buf)
		return -ENOMEM;

	snprintf(buf, PAGE_SIZE,
		 "omi usage:\n"
		 "-e : Enable/Disable OMI [0-dis, 1-en]\n"
		 "-s : Send OM control frame [sta_idx].[bw].[nss].[mu_ul_dis]."
			"[mu_ul_data_dis].[tx_nsts]\n");

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

static bool cl_omi_validate_parms(u8 bw, u8 nss, u8 ul_mu_dis, u8 ul_mu_data_dis, u8 tx_nsts)
{
	return (bw < CHNL_BW_MAX && nss < WRS_SS_MAX && tx_nsts <= MAX_OMI_NSTS);
}

static int cl_omi_send(struct cl_hw *cl_hw, struct cl_sta *cl_sta, u8 bw, u8 nss, u8 ul_mu_dis,
		       u8 ul_mu_data_dis, u8 tx_nsts)
{
	struct ieee80211_sub_if_data *sdata = NULL;
	struct sk_buff *skb = NULL;
	struct ieee80211_qos_htc_hdr *hdr = NULL;
	struct cl_om_ctrl om_ctrl;
	struct ieee80211_vif *vif = NULL;
	int hdr_len = offsetof(struct ieee80211_qos_htc_hdr, a_ctrl) + sizeof(hdr->a_ctrl);

	if (!cl_hw->conf->ce_omi_en || !cl_sta)
		return -1;

	vif = cl_sta->cl_vif->vif;
	sdata = cl_sta->stainfo->sdata;

	if (!cl_omi_validate_parms(bw, nss, ul_mu_dis, ul_mu_data_dis, tx_nsts) ||
	    vif->type != NL80211_IFTYPE_STATION)
		return -1;

	skb = dev_alloc_skb(cl_hw->hw->extra_tx_headroom + hdr_len);

	if (!skb)
		return -ENOMEM;

	skb_reserve(skb, cl_hw->hw->extra_tx_headroom);

	hdr = (struct ieee80211_qos_htc_hdr *)skb_put_zero(skb, hdr_len);
	cl_mac_addr_copy(hdr->addr1, cl_sta->addr);
	cl_mac_addr_copy(hdr->addr2, sdata->vif.addr);
	cl_mac_addr_copy(hdr->addr3, sdata->u.mgd.bssid);

	hdr->frame_control = cpu_to_le16(IEEE80211_FTYPE_MGMT | IEEE80211_STYPE_ACTION |
					 IEEE80211_FCTL_ORDER);

	om_ctrl.u.fields.chan_width = bw;
	om_ctrl.u.fields.rx_nss = nss;
	om_ctrl.u.fields.ul_mu_dis = ul_mu_dis;
	om_ctrl.u.fields.ul_mu_data_dis = ul_mu_data_dis;
	om_ctrl.u.fields.tx_nsts = tx_nsts;

	/* Set A-control subfield */
	hdr->a_ctrl.u.fields.b0 = 1;
	hdr->a_ctrl.u.fields.b1 = 1;
	hdr->a_ctrl.u.fields.control_id = IEEE80211_CTRL_A_CTRL_ID_OM;
	hdr->a_ctrl.u.fields.control_info = om_ctrl.u.value;

	if (!ieee80211_tx_prepare_skb(cl_hw->hw, vif, skb, cl_hw->nl_band, NULL))
		return -1;

	/* Send the OMI frame */
	cl_tx_single(cl_hw, cl_sta, skb, false, true);
	pr_debug("OM control frame was sent!\n");

	return 0;
}

static void cl_omi_set_tb_mode(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
			       u8 ul_mu_dis, u8 ul_mu_data_dis)
{
	struct ieee80211_sta_he_cap *he_cap = &cl_hw->iftype_data[1].he_cap;
	bool mu_dis_rx_sup = (he_cap->he_cap_elem.mac_cap_info[5] &
			      IEEE80211_HE_MAC_CAP5_OM_CTRL_UL_MU_DATA_DIS_RX) ? true : false;
	u8 ac;

	/*
	 * According to Table 9-24a - UL MU Disable and UL MU Data Disable subfields encoding
	 * At this point we need to suspend/resume trigger base flow
	 */

	for (ac = 0; ac < AC_MAX; ac++)
		cl_sta->data_pending[ac] = 0;

	if (!ul_mu_dis && !ul_mu_data_dis) {
		cl_sta->tf_support_dis = false;
		pr_debug("All trigger based UL MU transmissions are enabled!\n");
	} else if (!ul_mu_dis && ul_mu_data_dis && mu_dis_rx_sup) {
		cl_sta->tf_support_dis = true;
		cl_enhanced_tim_clear_rx_sta(cl_hw, cl_sta->sta_idx);
		pr_debug("Basic Trigger is suspended!\n");
	} else if (ul_mu_dis && !ul_mu_data_dis) {
		cl_sta->tf_support_dis = true;
		cl_enhanced_tim_clear_rx_sta(cl_hw, cl_sta->sta_idx);
		pr_debug("All trigger based UL MU transmissions are suspended!\n");
	}
}

void cl_omi_parse_om_ctrl_frm(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
			      struct ieee80211_a_control a_ctl)
{
	struct cl_wrs_rate *wrs_rate = &cl_sta->wrs_sta.max_rate_cap;
	struct cl_wrs_params *wrs_params = cl_sta->wrs_sta.rx_params;
	struct cl_wrs_rate_params *rate_params = NULL;
	struct cl_om_ctrl om_ctrl;
	u8 nss, bw, ul_mu_dis, ul_mu_data_dis, tx_nsts;

	if (!cl_hw->conf->ce_omi_en || !wrs_params)
		return;

	rate_params = &wrs_params->rate_params;

	om_ctrl.u.value = a_ctl.u.fields.control_info;
	nss = om_ctrl.u.fields.rx_nss;
	bw = om_ctrl.u.fields.chan_width;
	ul_mu_dis = om_ctrl.u.fields.ul_mu_dis;
	ul_mu_data_dis = om_ctrl.u.fields.ul_mu_data_dis;
	tx_nsts = om_ctrl.u.fields.tx_nsts;

	if (!cl_omi_validate_parms(bw, nss, ul_mu_dis, ul_mu_data_dis, tx_nsts))
		return;

	/* Set TB mode */
	cl_omi_set_tb_mode(cl_hw, cl_sta, ul_mu_dis, ul_mu_data_dis);

	/* Update URS rates */
	if (tx_nsts != rate_params->nss || bw != rate_params->bw)
		cl_wrs_api_set_omi_rate(cl_hw, cl_sta, bw, tx_nsts);

	if (nss != wrs_rate->nss)
		cl_wrs_api_nss_changed(cl_hw, &cl_sta->stainfo->sta, nss);

	if (bw != wrs_rate->bw)
		cl_wrs_api_bw_changed(cl_hw, &cl_sta->stainfo->sta, bw);
}

int cl_omi_cli(struct cl_hw *cl_hw, struct cli_params *cli_params)
{
	u32 expected_params = 0;
	bool send_om_ctrl = false;
	bool enable = false;

	switch (cli_params->option) {
	case 'e':
		enable = true;
		expected_params = 1;
		break;
	case 's':
		send_om_ctrl = true;
		expected_params = 6;
		break;
	case '?':
		return cl_omi_cli_help(cl_hw);
	default:
		cl_dbg_err(cl_hw, "Illegal option (%c) - try '?' for help\n", cli_params->option);
		goto out_err;
	}

	if (expected_params != cli_params->num_params) {
		cl_dbg_err(cl_hw, "Wrong number of arguments (expected %u) (actual %u)\n",
			   expected_params, cli_params->num_params);
		goto out_err;
	}

	if (enable) {
		bool enable = (bool)cli_params->params[0];

		if (enable != cl_hw->conf->ce_omi_en) {
			cl_hw->conf->ce_omi_en = enable;
			pr_debug("OMI %s\n", enable ? "Enabled" : "Disabled");
		} else {
			pr_debug("OMI already %s\n", enable ? "Enabled" : "Disabled");
		}
	}

	if (send_om_ctrl) {
		u8 sta_idx = (u8)cli_params->params[0];
		u8 bw = (u8)cli_params->params[1];
		u8 nss = (u8)cli_params->params[2];
		bool ul_mu_dis = (bool)cli_params->params[3];
		bool ul_mu_data_dis = (bool)cli_params->params[4];
		u8 tx_nsts = (u8)cli_params->params[5];
		struct cl_sta *cl_sta;

		cl_sta_lock_bh(cl_hw);
		cl_sta = cl_sta_get(cl_hw, sta_idx);

		if (cl_omi_send(cl_hw, cl_sta, bw, nss, ul_mu_dis, ul_mu_data_dis, tx_nsts))
			pr_warn("Failed to send OM control frame!\n");

		cl_sta_unlock_bh(cl_hw);

		return 0;
	}

out_err:
	return -EIO;
}

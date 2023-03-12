// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_hw.h"
#include "chip.h"
#include "cl_tf.h"
#include "cl_sta.h"
#include "cl_msg_tx.h"
#include "cl_omi.h"
#include "cl_ul_rssi.h"
#include "cl_utils.h"
#include "chip_ops.h"

static int cl_tf_cli_help(struct cl_hw *cl_hw)
{
	char *buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!buf)
		return -ENOMEM;

	snprintf(buf, PAGE_SIZE,
		 "tf usage:\n"
		 "-a : Send trigger frame\n"
		 "-b : Set packet count [#packets]\n"
		 "-c : Set common info parameters [tf_type].[ul_length].[more_tf]"
		 ".[cs_req].[bw].[gi].[ltf_mode].[ldpc_ex_sym].[pe_dis]\n"
		 "-e : Enable trigger frame flow [0-dis, 1-en]\n"
		 "-p : Print trigger configurations\n"
		 "-r : Reset trigger frame parameters\n"
		 "-s : Stop Sending Triggers\n"
		 "-u : Set user info parameters [sta_idx].[ru_alloc].[ru_band]"
		 ".[fec].[dcm].[mcs].[nss].[rssi]\n"
		 "-v : Set rate entry [rate_entry]\n");

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

static bool cl_tf_is_common_info_valid(u8 tf_type, u8 ul_bw, u8 ul_gi_ltf)
{
	if (tf_type != CL_TF_BASIC_TRIGGER &&
	    tf_type != CL_TF_BSRP &&
	    tf_type != CL_TF_BFRP) {
		pr_err("Invalid tf type %u, valid values are 0,1,4!\n", tf_type);
		return false;
	}

	if (ul_bw >= CHNL_BW_MAX) {
		pr_err("Invalid bw %u, valid values are 0-3!\n", ul_bw);
		return false;
	}

	if (ul_gi_ltf != HE_LTF_X2_GI_16 && ul_gi_ltf != HE_LTF_X4_GI_32) {
		pr_err("Invalid gi_ltf %u, valid values are 1,2!\n", ul_gi_ltf);
		return false;
	}

	return true;
}

static bool cl_tf_is_user_info_valid(u8 ru_alloc, u8 ul_mcs, u8 ul_nss)
{
	if (ru_alloc > CL_TF_RU_ALLOC_MAX_TYPE_7) {
		pr_err("Invalid ru alloc %u, valid values are 0-68!\n", ru_alloc);
		return false;
	}

	if (ul_nss >= WRS_SS_MAX) {
		pr_err("Invalid ul_nss %u, valid values are 0-3!\n", ul_nss);
		return false;
	}

	if (ul_mcs >= WRS_MCS_MAX) {
		pr_err("Invalid ul_mcs %u, valid values are 0-11!\n", ul_mcs);
		return false;
	}

	return true;
}

static void cl_tf_set_common_info(struct cl_hw *cl_hw, u8 tf_type, u32 ul_length,
				  u8 more_tf, u8 cs_req, u8 ul_bw, u8 ul_gi_ltf,
				  u8 he_ltf_mode, u8 ldpc_extra_sym, u8 pe_disambiguity)
{
	struct cl_tf_params *tf_params = &cl_hw->tf_params;
	struct cl_tf_common_info *common_info = &tf_params->common_info;

	if (!cl_tf_is_common_info_valid(tf_type, ul_bw, ul_gi_ltf))
		return;

	common_info->tf_type = tf_type;
	common_info->ul_length = cpu_to_le32(ul_length);
	common_info->more_tf = more_tf;
	common_info->cs_req = cs_req;
	common_info->ul_bw = ul_bw;
	common_info->ul_gi_ltf = ul_gi_ltf;
	common_info->he_ltf_mode = he_ltf_mode;
	common_info->ldpc_extra_sym = ldpc_extra_sym;
	common_info->pe_disambiguity = pe_disambiguity;

	pr_debug("Common Info configured successfully!\n");
}

static void cl_tf_set_user_info(struct cl_hw *cl_hw, u8 sta_idx, u8 ru_alloc,
				u8 ru_band, u8 ul_fec, u8 ul_dcm, u8 ul_mcs, u8 ul_nss, u8 rssi)
{
	struct cl_tf_params *tf_params = &cl_hw->tf_params;
	struct cl_tf_user_info *user_info;
	struct cl_sta *cl_sta;
	u8 sta_num;

	if (!cl_tf_is_user_info_valid(ru_alloc, ul_mcs, ul_nss))
		return;

	cl_sta_lock_bh(cl_hw);

	cl_sta = cl_sta_get(cl_hw, sta_idx);
	sta_num = cl_hw->cl_sta_db.num;

	if (!cl_sta) {
		cl_sta_unlock_bh(cl_hw);
		pr_warn("sta %u is not connected!\n", sta_idx);
		return;
	}

	cl_sta_unlock_bh(cl_hw);

	user_info = &tf_params->user_info[sta_idx];
	user_info->ru_alloc = ru_alloc;
	user_info->ru_band = ru_band;
	user_info->ul_fec = ul_fec;
	user_info->ul_dcm = ul_dcm;
	user_info->ul_mcs = ul_mcs;
	user_info->ul_nss = ul_nss;
	user_info->rssi = rssi;
	tf_params->sta_idx[tf_params->sta_cnt] = sta_idx;

	if (sta_num > tf_params->sta_cnt)
		tf_params->sta_cnt++;

	pr_debug("User info for sta %u configured successfully!\n", sta_idx);
}

static void cl_tf_set_rate_entry(struct cl_hw *cl_hw, u8 rate_entry)
{
	struct cl_tf_params *tf_params = &cl_hw->tf_params;

	if (rate_entry >= RATE_CTRL_ENTRY_MAX) {
		pr_err("Invalid rate_entry %d, valid values are %d-%d!\n", rate_entry,
		       RATE_CTRL_ENTRY_NA, RATE_CTRL_ENTRY_BCAST);
		return;
	}

	tf_params->rate_entry = rate_entry;
	pr_debug("Rate entry set to %d!\n", rate_entry);
}

static int cl_tf_print_config(struct cl_hw *cl_hw)
{
	struct cl_tf_params *tf_params = &cl_hw->tf_params;
	struct cl_tf_common_info *common_info = &tf_params->common_info;
	struct cl_tf_user_info *user_info = tf_params->user_info;
	u8 i;
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;

	cl_snprintf(&buf, &len, &buf_size,
		    "COMMON INFO\n"
		    "-----------------\n"
		    "Trigger type : %s\n",
		    CL_TF_TYPE_STR(common_info->tf_type));
	cl_snprintf(&buf, &len, &buf_size,
		    "UL length    : %u\n", common_info->ul_length);
	cl_snprintf(&buf, &len, &buf_size,
		    "More TF      : %u\n", common_info->more_tf);
	cl_snprintf(&buf, &len, &buf_size,
		    "UL bw        : %u\n", common_info->ul_bw);
	cl_snprintf(&buf, &len, &buf_size,
		    "UL gi        : %u\n", common_info->ul_gi_ltf);
	cl_snprintf(&buf, &len, &buf_size,
		    "HE LTF mode  : %u\n", common_info->he_ltf_mode);

	for (i = 0; i < cl_hw->tf_params.sta_cnt; i++) {
		cl_snprintf(&buf, &len, &buf_size,
			    "USER INFO %u:\n", i);
		cl_snprintf(&buf, &len, &buf_size,
			    "-------------\n"
			    "RU alloc : %u\n", user_info->ru_alloc);
		cl_snprintf(&buf, &len, &buf_size,
			    "RU band  : %u\n", user_info->ru_band);
		cl_snprintf(&buf, &len, &buf_size,
			    "UL fec   : %u\n", user_info->ul_fec);
		cl_snprintf(&buf, &len, &buf_size,
			    "UL dcm   : %u\n", user_info->ul_dcm);
		cl_snprintf(&buf, &len, &buf_size,
			    "Mcs      : %u\n", user_info->ul_mcs);
		cl_snprintf(&buf, &len, &buf_size,
			    "NSS      : %u\n", user_info->ul_nss);
		cl_snprintf(&buf, &len, &buf_size,
			    "Rssi     : %u\n\n", user_info->rssi);
		user_info++;
	}

	cl_snprintf(&buf, &len, &buf_size,
		    "Rate entry  : %d\n", tf_params->rate_entry);

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

static void cl_tf_reset_params(struct cl_hw *cl_hw)
{
	struct cl_tf_params *tf_params = &cl_hw->tf_params;

	if (tf_params->pkt_send_cnt) {
		pr_debug("Stop sending triggers first!\n");
		return;
	}

	memset(&tf_params->common_info, 0, sizeof(tf_params->common_info));
	memset(tf_params->user_info, 0, sizeof(tf_params->user_info));
	memset(tf_params->sta_idx, 0, sizeof(tf_params->sta_idx));
	tf_params->pkt_rcv_cnt = 0;
	tf_params->sta_cnt = 0;
	tf_params->rate_entry = 0;

	pr_debug("Reset TF parameters!\n");
}

static void cl_tf_send(unsigned long data)
{
	struct cl_hw *cl_hw = (struct cl_hw *)data;
	struct cl_tf_params *tf_params = &cl_hw->tf_params;
	struct cl_tf_common_info *common_info = &tf_params->common_info;
	struct cl_tf_user_info *user_info = tf_params->user_info;
	struct mm_tf_req tf_req = {{0}};
	u8 i;

	if (!tf_params->sta_cnt) {
		pr_warn("Set User info first!\n");
		return;
	}

	if (tf_params->pkt_send_cnt) {
		tf_params->pkt_send_cnt--;
	} else {
		pr_debug("Finished sending all TF packets!\n");
		return;
	}

	tf_req.common_info.tf_type = common_info->tf_type;
	tf_req.common_info.ul_length = common_info->ul_length;
	tf_req.common_info.more_tf = common_info->more_tf;
	tf_req.common_info.cs_req = common_info->cs_req;
	tf_req.common_info.ul_bw = common_info->ul_bw;
	tf_req.common_info.ul_gi_ltf = common_info->ul_gi_ltf;
	tf_req.common_info.he_ltf_mode = common_info->he_ltf_mode;
	tf_req.common_info.ldpc_extra_sym = common_info->ldpc_extra_sym;
	tf_req.common_info.pe_disambiguity = common_info->pe_disambiguity;
	tf_req.rate_entry = tf_params->rate_entry;

	for (i = 0; i < tf_params->sta_cnt; i++) {
		tf_req.user_info[i].ru_alloc = user_info->ru_alloc;
		tf_req.user_info[i].ru_band = user_info->ru_band;
		tf_req.user_info[i].ul_fec = user_info->ul_fec;
		tf_req.user_info[i].ul_dcm = user_info->ul_dcm;
		tf_req.user_info[i].ul_mcs = user_info->ul_mcs;
		tf_req.user_info[i].rssi = user_info->rssi;
		tf_req.user_info[i].ul_nss = user_info->ul_nss;
		tf_req.sta_idx[i] = tf_params->sta_idx[i];
		user_info++;
	}

	tf_req.rx_params_mode = CL_TF_RX_PARAMS_MODE_USER;
	tf_req.sta_cnt = tf_params->sta_cnt;
	tf_params->pkt_rcv_cnt = 0;
	cl_timer_enable(&tf_params->tf_timer);
	cl_msg_tx_tf(cl_hw, &tf_req);
}

void cl_tf_init(struct cl_hw *cl_hw)
{
	cl_timer_init(&cl_hw->tf_params.tf_timer, cl_tf_send,
		      (unsigned long)cl_hw, TF_TIMER_PERIOD_MS, false);
}

void cl_tf_close(struct cl_hw *cl_hw)
{
	cl_timer_disable_sync(&cl_hw->tf_params.tf_timer);
}

void cl_tf_handle_response(struct cl_hw *cl_hw)
{
	struct cl_tf_params *tf_params = &cl_hw->tf_params;

	if (++tf_params->pkt_rcv_cnt >= TID_MAX * tf_params->sta_cnt) {
		cl_timer_disable_sync(&tf_params->tf_timer);
		cl_tf_send((unsigned long)cl_hw);
	}
}

void cl_tf_handler(struct cl_hw *cl_hw, struct sk_buff *skb,
		   struct cl_sta *cl_sta, struct cl_rx_w2e_hdr *w2e_hdr)
{
	struct ieee80211_a_control a_ctl = {};
	__le16 fc = cl_get_frame_ctrl(cl_hw, skb, w2e_hdr);

	/* Check if HTC subfield is present */
	if (!ieee80211_has_order(fc))
		return;

	a_ctl.u.value = cl_get_ht_ctl(cl_hw, skb, w2e_hdr);

	/* Check A-Control subfield is present */
	if (!ieee80211_has_a_ctrl(a_ctl.u.value))
		return;

	/* Check Control id subfield */
	switch (a_ctl.u.fields.control_id) {
	case IEEE80211_CTRL_A_CTRL_ID_UPH:
		cl_ul_rssi_update_uph(cl_hw, cl_sta, a_ctl);
		break;
	case IEEE80211_CTRL_A_CTRL_ID_OM:
		cl_omi_parse_om_ctrl_frm(cl_hw, cl_sta, a_ctl);
		break;
	default:
		break;
	}
}

int cl_tf_alloc(struct cl_hw *cl_hw)
{
	struct cl_tf_data *buf = NULL;
	u32 len = sizeof(struct cl_tf_data);
	dma_addr_t phys_dma_addr;

	buf = chip_ops_alloc_coherent(cl_hw->chip, len, GFP_KERNEL, &phys_dma_addr);
	if (!buf)
		return -1;

	cl_hw->tf_info.data = buf;
	cl_hw->tf_info.dma_addr = phys_dma_addr;

	return 0;
}

void cl_tf_free(struct cl_hw *cl_hw)
{
	struct cl_tf_info *tf_info = &cl_hw->tf_info;
	u32 len = sizeof(struct cl_tf_data);
	dma_addr_t phys_dma_addr = tf_info->dma_addr;

	if (!tf_info->data)
		return;

	chip_ops_free_coherent(cl_hw->chip, len, (void *)tf_info->data, phys_dma_addr);
	tf_info->data = NULL;
}

int cl_tf_cli(struct cl_hw *cl_hw, struct cli_params *cli_params)
{
	u32 expected_params = -1;
	bool send_tf = false;
	bool set_pkt_cnt = false;
	bool set_common_info = false;
	bool enable = false;
	bool print_config = false;
	bool reset_config = false;
	bool stop_tf = false;
	bool set_user_info = false;
	bool set_rate_entry = false;

	switch (cli_params->option) {
	case 'a':
		send_tf = true;
		expected_params = 0;
		break;
	case 'b':
		set_pkt_cnt = true;
		expected_params = 1;
		break;
	case 'c':
		set_common_info = true;
		expected_params = 9;
		break;
	case 'e':
		enable = true;
		expected_params = 1;
		break;
	case 'p':
		print_config = true;
		expected_params = 0;
		break;
	case 'r':
		reset_config = true;
		expected_params = 0;
		break;
	case 's':
		stop_tf = true;
		expected_params = 0;
		break;
	case 'u':
		set_user_info = true;
		expected_params = 8;
		break;
	case 'v':
		set_rate_entry = true;
		expected_params = 1;
		break;
	case '?':
		return cl_tf_cli_help(cl_hw);
	default:
		cl_dbg_err(cl_hw, "Illegal option (%c) - try '?' for help\n",
			   cli_params->option);
		goto out_err;
	}

	if (expected_params != cli_params->num_params) {
		cl_dbg_err(cl_hw,
			   "Wrong number of arguments (expected %u) (actual %u)\n",
			   expected_params, cli_params->num_params);
		goto out_err;
	}

	if (enable) {
		bool enable = (bool)cli_params->params[0];

		if (enable != cl_hw->tf_params.enable) {
			cl_hw->tf_params.enable = enable;
			pr_debug("TF %s\n", enable ? "Enabled" : "Disabled");
		} else {
			pr_debug("TF already %s\n", enable ? "Enabled" : "Disabled");
		}

		return 0;
	}

	if (!cl_hw->tf_params.enable) {
		pr_warn("TF flow is disabled!\n");
		return 0;
	}

	if (send_tf) {
		cl_tf_send((unsigned long)cl_hw);
		return 0;
	}

	if (set_pkt_cnt) {
		u32 pkt_cnt = (u32)cli_params->params[0];

		cl_hw->tf_params.pkt_send_cnt = pkt_cnt;
		pr_debug("Packet number set to %u!\n", pkt_cnt);
		return 0;
	}

	if (set_common_info) {
		u8 tf_type = (u8)cli_params->params[0];
		u32 ul_length = (u32)cli_params->params[1];
		u8 more_tf = (u8)cli_params->params[2];
		u8 cs_req = (u8)cli_params->params[3];
		u8 ul_bw = (u8)cli_params->params[4];
		u8 ul_gi_ltf = (u8)cli_params->params[5];
		u8 he_ltf_mode = (u8)cli_params->params[6];
		u8 ldpc_extra_sym = (u8)cli_params->params[7];
		u8 pe_disambiguity = (u8)cli_params->params[8];

		cl_tf_set_common_info(cl_hw, tf_type, ul_length, more_tf, cs_req,
				      ul_bw, ul_gi_ltf, he_ltf_mode, ldpc_extra_sym,
				      pe_disambiguity);
		return 0;
	}

	if (print_config)
		return cl_tf_print_config(cl_hw);

	if (reset_config) {
		cl_tf_reset_params(cl_hw);
		return 0;
	}

	if (stop_tf) {
		cl_timer_disable_sync(&cl_hw->tf_params.tf_timer);
		cl_hw->tf_params.pkt_send_cnt = 0;

		pr_debug("Stop sending trigger frames!\n");
		return 0;
	}

	if (set_user_info) {
		u8 sta_idx = (u8)cli_params->params[0];
		u8 ru_alloc = (u8)cli_params->params[1];
		bool ru_band = (bool)cli_params->params[2];
		bool ul_fec = (bool)cli_params->params[3];
		bool ul_dcm = (bool)cli_params->params[4];
		u8 tf_mcs = (u8)cli_params->params[5];
		u8 tf_nss = (u8)cli_params->params[6];
		u8 rssi = (u8)cli_params->params[7];

		cl_tf_set_user_info(cl_hw, sta_idx, ru_alloc, ru_band, ul_fec,
				    ul_dcm, tf_mcs, tf_nss, rssi);
		return 0;
	}

	if (set_rate_entry) {
		u8 rate_entry = (u8)cli_params->params[0];

		cl_tf_set_rate_entry(cl_hw, rate_entry);
		return 0;
	}

out_err:
	return -EIO;
}

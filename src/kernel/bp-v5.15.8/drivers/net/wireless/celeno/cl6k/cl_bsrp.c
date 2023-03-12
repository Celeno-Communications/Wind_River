// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_bsrp.h"
#include "cl_fw_msg.h"
#include "cl_sta.h"
#include "cl_utils.h"
#include "cl_enhanced_tim.h"
#include "cl_tf.h"
#include "cl_ul_length.h"
#include "cl_msg_tx.h"
#include "cl_wrs.h"

#define SCALE_FACTOR_MASK   0xC0
#define SCALE_FACTOR_OFFSET 6
#define UNSCALE_VAL_MASK    0x3F
#define UNSCALE_VAL_MAX     62
#define Q_SIZE_MAX          0x20C400

static int cl_bsrp_cli_help(struct cl_hw *cl_hw)
{
	char *buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!buf)
		return -ENOMEM;

	snprintf(buf, PAGE_SIZE,
		 "bsrp usage:\n"
		 "-d : Set debug level [0-dis, 1-en]\n"
		 "-e : Enable/Disable BSRP [0-dis, 1-en]\n"
		 "-l : Set UL length [sta idx].[ac].[bytes]\n"
		 "-t : Set BSRP threshold for a group [group id].[value]\n"
		 "-u : Set BSRP threshold for a STA [sta idx].[value]\n");

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

static bool cl_bsrp_is_cap_support(struct cl_sta *cl_sta)
{
	return cl_sta && cl_sta->stainfo->sta.he_cap.has_he;
}

static bool cl_bsrp_ignore_frame(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	if (!cl_hw->conf->ce_bsrp_en)
		return true;

	if (cl_sta->wrs_sta.mode != WRS_MODE_HE ||
	    cl_sta->tf_support_dis)
		return true;

	return false;
}

static void cl_bsrp_set_bitmap_su(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	u8 ac;
	bool start_timer = false;

	for (ac = 0; ac < AC_MAX; ac++)
		if (cl_sta->data_pending[ac]) {
			/* Set BSR bitmap */
			start_timer = true;
			cl_sta->bsrp_info.bsr_bitmap |= 1 << ac;
		}

	if (start_timer)
		cl_timer_enable(&cl_sta->bsrp_info.timeout_timer);
}

static void cl_bsrp_maintenance(unsigned long data)
{
	struct cl_hw *cl_hw = (struct cl_hw *)data;
	struct cl_sta *cl_sta = NULL;

	if (!cl_hw->conf->ce_bsrp_en)
		return;

	/* Loop through all STA's */
	cl_sta_lock(cl_hw);

	list_for_each_entry(cl_sta, &cl_hw->cl_sta_db.head, list)
		cl_bsrp_send_su((unsigned long)cl_sta);

	cl_sta_unlock(cl_hw);
}

static void cl_bsrp_set_threshold_su(struct cl_hw *cl_hw, u8 sta_idx, u32 threshold)
{
	struct cl_sta *cl_sta = NULL;

	if (!cl_hw->conf->ce_bsrp_en) {
		pr_warn("BSRP flow is disabled!\n");
		return;
	}

	cl_sta_lock_bh(cl_hw);

	cl_sta = cl_sta_get(cl_hw, sta_idx);

	if (cl_sta) {
		cl_sta->bsrp_info.byte_threshold = threshold;
		pr_debug("STA%u: threshold set to %u!\n", sta_idx, threshold);
	} else {
		pr_err("Invalid STA %u!\n", sta_idx);
	}

	cl_sta_unlock_bh(cl_hw);
}

static u32 cl_bsr_queue_size_get(u8 scal_factor, u8 unscale_val)
{
	u32 val;

	switch (scal_factor) {
	case SCAL_FACTOR_0:
		val = QS_FACTOR_16 * unscale_val;
		break;
	case SCAL_FACTOR_1:
		val = 1024 + (QS_FACTOR_256 * unscale_val);
		break;
	case SCAL_FACTOR_2:
		val = 17408 + (QS_FACTOR_2048 * unscale_val);
		break;
	case SCAL_FACTOR_3:
		if (unscale_val < UNSCALE_VAL_MAX)
			val = 148480 + (QS_FACTOR_32768 * unscale_val);
		else
			val = Q_SIZE_MAX;

		break;
	default:
		val = 0;
		break;
	}

	return val;
}

static u16 cl_bsrp_get_ul_length(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	struct cl_wrs_params *wrs_params = cl_sta->wrs_sta.rx_params;
	struct cl_wrs_rate_params *rate_params = NULL;
	u16 duration;
	u8 duration_idx;
	u8 min_spacing = max(cl_hw->conf->ci_su_force_min_spacing,
			     cl_hw->conf->ci_mu_force_min_spacing);

	if (!wrs_params)
		return 0;

	rate_params = &wrs_params->rate_params;

	if (min_spacing == CL_TX_MPDU_SPACING_INVALID)
		min_spacing = cl_sta->ampdu_min_spacing;

	duration = cl_ul_length_get_duration(QOS_NULL_LEN, rate_params->bw,
					     rate_params->nss, rate_params->mcs,
					     rate_params->gi);

	if (duration < min_spacing)
		duration = min_spacing;

	duration_idx = (duration * TID_MAX) >> UL_LEN_IDX_FACTOR;
	if (duration_idx > UL_LEN_MAX_IDX)
		duration_idx = UL_LEN_MAX_IDX;

	return cl_ul_length_get(duration_idx, rate_params->nss, rate_params->gi);
}

static void cl_bsrp_trigger_prep_su(struct cl_hw *cl_hw,
				    struct cl_sta *cl_sta,
				    struct mm_tf_req *req)
{
	u32 ul_length;

	req->common_info.tf_type = CL_TF_BSRP;
	req->sta_idx[0] = cl_sta->sta_idx;
	req->sta_cnt = 1;
	ul_length = (u32)cl_bsrp_get_ul_length(cl_hw, cl_sta);
	req->common_info.ul_length = cpu_to_le32(ul_length);
	req->rx_params_mode = CL_TF_RX_PARAMS_MODE_STA;
}

static void cl_bsrp_update_ul_length(struct cl_hw *cl_hw,
				     struct cl_sta *cl_sta, u8 ac)
{
	struct cl_wrs_rate_params *rate_params = cl_wrs_rx_rate_get(cl_sta);
	u32 bytes = cl_sta->data_pending[ac];

	if (bytes) {
		u16 rate = cl_ul_length_get_duration(bytes, rate_params->bw,
						     rate_params->nss,
						     rate_params->mcs, rate_params->gi);
		u16 duration_indcies = rate >> UL_LEN_IDX_FACTOR;

		if (duration_indcies > UL_LEN_MAX_IDX)
			duration_indcies = UL_LEN_MAX_IDX;

		cl_hw->tf_info.data->tf_sta_data[ac][cl_sta->sta_idx].ul_length[0] =
			cl_ul_length_get(duration_indcies,
					 rate_params->nss, rate_params->gi);
	} else {
		/* Update UL length for FW */
		cl_hw->tf_info.data->tf_sta_data[ac][cl_sta->sta_idx].ul_length[0] =
			cl_ul_length_get(0, rate_params->nss, rate_params->gi);
	}
}

void cl_bsrp_send_su(unsigned long data)
{
	struct cl_sta *cl_sta = (struct cl_sta *)data;
	struct cl_hw *cl_hw = NULL;
	struct mm_tf_req tf_req = {{0}};

	if (cl_sta->tf_support_dis)
		return;

	cl_hw = cl_sta->cl_vif->cl_hw;

	cl_bsrp_trigger_prep_su(cl_hw, cl_sta, &tf_req);
	cl_bsrp_set_bitmap_su(cl_hw, cl_sta);
	cl_msg_tx_tf(cl_hw, &tf_req);

	BSRP_DBG("BSRP trigger frame sent to STA %u!\n", cl_sta->sta_idx);
}

void cl_bsrp_init(struct cl_hw *cl_hw)
{
	/* Init BSRP maintenance timer */
	cl_timer_init(&cl_hw->bsrp_maintenance_timer, cl_bsrp_maintenance,
		      (unsigned long)cl_hw, BSRP_MAINTENANCE_PERIOD_MS, true);
	if (cl_hw->conf->ce_bsrp_en)
		cl_timer_enable(&cl_hw->bsrp_maintenance_timer);
}

void cl_bsrp_close(struct cl_hw *cl_hw)
{
	cl_timer_disable_sync(&cl_hw->bsrp_maintenance_timer);
}

int cl_bsrp_cli(struct cl_hw *cl_hw, struct cli_params *cli_params)
{
	bool debug = false;
	bool bsrp_en = false;
	bool set_bsrp_threshold_su = false;
	bool set_ul_length = false;
	u32 expected_params = -1;

	switch (cli_params->option) {
	case 'd':
		debug = true;
		expected_params = 1;
		break;
	case 'e':
		bsrp_en = true;
		expected_params = 1;
		break;
	case 'l':
		set_ul_length = true;
		expected_params = 3;
		break;
	case 'u':
		set_bsrp_threshold_su = true;
		expected_params = 2;
		break;
	case '?':
		return cl_bsrp_cli_help(cl_hw);
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

	if (debug) {
		bool dbg_en = cli_params->params[0];

		cl_hw->bsrp_dbg = dbg_en;
		pr_debug("BSRP: Debug = %s\n", dbg_en ? "True" : "False");
	}

	if (bsrp_en) {
		bool enable = (bool)cli_params->params[0];

		if (enable != cl_hw->conf->ce_bsrp_en) {
			if (enable)
				cl_timer_enable(&cl_hw->bsrp_maintenance_timer);
			else
				cl_timer_disable_sync(&cl_hw->bsrp_maintenance_timer);

			cl_hw->conf->ce_bsrp_en = enable;
			pr_debug("BSRP %s\n", enable ? "Enabled" : "Disabled");
		} else {
			pr_debug("BSRP already %s\n", enable ? "Enabled" : "Disabled");
		}

		return 0;
	}

	if (set_ul_length) {
		u8 sta_idx = (u8)cli_params->params[0];
		u8 ac = (u8)cli_params->params[1];
		u32 bytes = cli_params->params[2];

		cl_ul_length_set_manual(cl_hw, sta_idx, ac, bytes);
		return 0;
	}

	if (set_bsrp_threshold_su) {
		u8 sta_idx = (u8)cli_params->params[0];
		u32 threshold = (u32)cli_params->params[1];

		cl_bsrp_set_threshold_su(cl_hw, sta_idx, threshold);
		return 0;
	}

out_err:
	return -EIO;
}

void cl_bsrp_parse_bsr(struct cl_hw *cl_hw, struct sk_buff *skb,
		       struct cl_sta *cl_sta, struct cl_rx_w2e_hdr *w2e_hdr)
{
	struct cl_bsrp_info *bsrp_info = NULL;
	u32 queue_size;
	u8 *qc = NULL;
	u8 ac, eosp, sf, uv;

	if (cl_bsrp_ignore_frame(cl_hw, cl_sta))
		return;

	bsrp_info = &cl_sta->bsrp_info;

	qc = cl_get_qos_ctrl(cl_hw, skb, w2e_hdr);

	eosp = qc[0] & IEEE80211_QOS_CTL_EOSP;

	/* Check EOSP bit */
	if (!eosp)
		return;

	ac = cl_get_skb_ac(cl_hw, skb, w2e_hdr);
	uv = qc[1] & UNSCALE_VAL_MASK;
	sf = (qc[1] & SCALE_FACTOR_MASK) >> SCALE_FACTOR_OFFSET;

	/* Queue size per TID as reported by the STA */
	queue_size = cl_bsr_queue_size_get(sf, uv);
	if (queue_size) {
		cl_enhanced_tim_set_rx(cl_hw, ac, cl_sta->sta_idx);
		/* Update Data pending per STA */
		cl_sta->data_pending[ac] += queue_size;
	}

	/* Update UL-length */
	cl_bsrp_update_ul_length(cl_hw, cl_sta, ac);

	/* Unset BSR bitmap */
	cl_sta->bsrp_info.bsr_bitmap &= ~(1 << ac);

	if (!cl_sta->bsrp_info.bsr_bitmap) {
		cl_timer_disable_sync(&bsrp_info->timeout_timer);

		if (queue_size &&
		    queue_size < bsrp_info->byte_threshold)
			cl_bsrp_send_su((unsigned long)cl_sta);
	}
}

void cl_bsrp_data_pending_dec(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
			      struct sk_buff *skb,
			      struct cl_rx_w2e_hdr *w2e_hdr, u16 bytes)
{
	struct cl_bsrp_info *bsrp_info = NULL;
	u32 prev_data_pending;
	u8 ac;

	if (!cl_hw->conf->ce_bsrp_en)
		return;

	bsrp_info = &cl_sta->bsrp_info;
	ac = cl_get_skb_ac(cl_hw, skb, w2e_hdr);
	prev_data_pending = cl_sta->data_pending[ac];

	if (cl_sta->data_pending[ac] > bytes) {
		cl_sta->data_pending[ac] -= bytes;
	} else {
		/* Clear enhanced tim RX bit */
		cl_enhanced_tim_clear_rx(cl_hw, ac, cl_sta->sta_idx);
		cl_sta->data_pending[ac] = 0;
	}

	/* Update UL-length */
	cl_bsrp_update_ul_length(cl_hw, cl_sta, ac);

	/* Check if we reached BSRP threshold */
	if (cl_sta->data_pending[ac] < bsrp_info->byte_threshold &&
	    prev_data_pending > bsrp_info->byte_threshold)
		cl_bsrp_send_su((unsigned long)cl_sta);
}

void cl_bsrp_set_su_ul(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	struct cl_bsrp_info *bsrp_info = NULL;

	if (!cl_bsrp_is_cap_support(cl_sta))
		return;

	bsrp_info = &cl_sta->bsrp_info;

	bsrp_info->byte_threshold = BSRP_BYTE_THRESHOLD_DEFAULT;
	cl_timer_init(&bsrp_info->timeout_timer, cl_bsrp_send_su,
		      (unsigned long)cl_sta, BSRP_TIMEOUT_PERIOD_MS, false);
}

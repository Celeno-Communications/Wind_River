// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_bf.h"
#include "cl_sounding.h"
#include "cl_msg_tx.h"
#include "cl_traffic.h"
#include "cl_sta.h"
#include "cl_vw.h"
#include "cl_math.h"
#include "cl_utils.h"

#define CL_BF_SOUNDING_INTERVAL_MAX 0x3ff
#define CL_BF_MIN_SOUNDING_NR       3
#define CL_BF_TIMER_SOUNDING_FACTOR 10

#define bf_pr(cl_hw, level, ...) \
	do { \
		if ((level) <= (cl_hw)->bf_db.dbg_level) \
			pr_debug(__VA_ARGS__); \
	} while (0)

#define bf_pr_verbose(cl_hw, ...) bf_pr((cl_hw), DBG_LVL_VERBOSE, ##__VA_ARGS__)
#define bf_pr_err(cl_hw, ...)     bf_pr((cl_hw), DBG_LVL_ERROR, ##__VA_ARGS__)
#define bf_pr_warn(cl_hw, ...)    bf_pr((cl_hw), DBG_LVL_WARNING, ##__VA_ARGS__)
#define bf_pr_trace(cl_hw, ...)   bf_pr((cl_hw), DBG_LVL_TRACE, ##__VA_ARGS__)
#define bf_pr_info(cl_hw, ...)    bf_pr((cl_hw), DBG_LVL_INFO, ##__VA_ARGS__)

static void cl_bf_cli_fw_control_stats(struct cl_hw *cl_hw, u32 action)
{
	if (action == 0)
		cl_msg_tx_dbg_print_stats(cl_hw, DBG_PRINT_RESET, 0, 0, 0, 0);
	else if (action == 1)
		cl_msg_tx_dbg_print_stats(cl_hw, DBG_PRINT_BF_CTRL_ACTIVE, 0, 0, 0, 0);
	else if (action == 2)
		cl_msg_tx_dbg_print_stats(cl_hw, DBG_PRINT_BF_CTRL_PASSIVE, 0, 0, 0, 0);
	else
		bf_pr_verbose(cl_hw, "Invalid input [%u]\n", action);
}

static bool cl_bf_is_beamformee_capable_he(struct ieee80211_sta *sta, bool mu_cap)
{
	u8 phy_cap_info4 = sta->he_cap.he_cap_elem.phy_cap_info[4];

	if (mu_cap)
		return (phy_cap_info4 & IEEE80211_HE_PHY_CAP4_MU_BEAMFORMER) ? true : false;
	else
		return (phy_cap_info4 & IEEE80211_HE_PHY_CAP4_SU_BEAMFORMEE) ? true : false;
}

static bool cl_bf_is_beamformee_capable_vht(struct ieee80211_sta *sta, bool mu_cap)
{
	u32 vht_cap = sta->vht_cap.cap;

	if (mu_cap)
		return (vht_cap & IEEE80211_VHT_CAP_MU_BEAMFORMEE_CAPABLE) ? true : false;
	else
		return (vht_cap & IEEE80211_VHT_CAP_SU_BEAMFORMEE_CAPABLE) ? true : false;
}

static bool cl_bf_is_beamformee_capable(struct cl_sta *cl_sta, bool mu_cap)
{
	struct ieee80211_sta *sta = &cl_sta->stainfo->sta;

	if (sta->he_cap.has_he)
		return cl_bf_is_beamformee_capable_he(sta, mu_cap);

	if (sta->vht_cap.vht_supported)
		return cl_bf_is_beamformee_capable_vht(sta, mu_cap);

	return false;
}

static int cl_bf_cli_config_print(struct cl_hw *cl_hw)
{
	bool is_enabled = cl_bf_is_enabled(cl_hw);
	struct cl_tcv_conf *conf = cl_hw->conf;
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;

	cl_snprintf(&buf, &len, &buf_size,
		    "Beamforming Configuration\n"
		    "------------------------------\n");

	cl_snprintf(&buf, &len, &buf_size,
		    "Is enabled:                %s\n",
		    is_enabled ? "True" : "False");

	cl_snprintf(&buf, &len, &buf_size,
		    "Force:                     %s\n",
		    cl_hw->bf_db.force ? "True" : "False");

	cl_snprintf(&buf, &len, &buf_size,
		    "Debug level:               %d\n",
		    cl_hw->bf_db.dbg_level);

	cl_snprintf(&buf, &len, &buf_size,
		    "Max nss supported:         %u\n",
		    conf->ci_bf_max_nss);

	err = cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);

	return err;
}

static void cl_bf_cli_debug_set(struct cl_hw *cl_hw, u32 dbg_level)
{
	if (dbg_level < DBG_LVL_MAX) {
		cl_hw->bf_db.dbg_level = dbg_level;
		pr_debug("[BF] Debug level [%d]\n", dbg_level);
	}
}

void cl_bf_enable(struct cl_hw *cl_hw, bool enable)
{
	struct cl_tcv_conf *conf = cl_hw->conf;

	if (conf->ce_bf_en == enable)
		return;

	conf->ce_bf_en = enable;
	pr_debug("[BF] %s\n", enable ? "Enable" : "Disable");

	cl_sta_loop_bh(cl_hw, cl_bf_sounding_decision);
}

static void cl_bf_cli_force_set(struct cl_hw *cl_hw, bool force)
{
	if (cl_hw->bf_db.force == force)
		return;

	cl_hw->bf_db.force = force;
	pr_debug("[BF] Force: %s\n", force ? "True" : "False");

	cl_sta_loop_bh(cl_hw, cl_bf_sounding_decision);
}

static int cl_bf_cli_sta_info_print(struct cl_hw *cl_hw)
{
	struct cl_sta *cl_sta = NULL;
	char *buf = NULL;
	ssize_t buf_size;
	int len = 0;
	int err = 0;

	/* Go over all stations - use bottom-half lock */
	read_lock_bh(&cl_hw->cl_sta_db.lock);

	list_for_each_entry(cl_sta, &cl_hw->cl_sta_db.head, list) {
		struct cl_bf_sta_db *bf_db = &cl_sta->bf_db;
		u8 nss = cl_sta->wrs_sta.tx_su_params.rate_params.nss;
		bool is_on = cl_bf_is_on(cl_hw, cl_sta, nss);
		bool su_beamformee_capable =
				cl_bf_is_beamformee_capable(cl_sta, false);
		bool mu_beamformee_capable =
				cl_bf_is_beamformee_capable(cl_sta, true);

		cl_snprintf(&buf, &len, &buf_size,
			    "\nStation [%u]\n", cl_sta->sta_idx);
		cl_snprintf(&buf, &len, &buf_size,
			    "-------------------------------\n");
		cl_snprintf(&buf, &len, &buf_size,
			    "SU beamformee capable: %s\n",
			    su_beamformee_capable ? "True" : "False");
		cl_snprintf(&buf, &len, &buf_size,
			    "MU beamformee capable: %s\n",
			    mu_beamformee_capable ? "True" : "False");
		cl_snprintf(&buf, &len, &buf_size,
			    "Beamformee STS:        %u\n",
			    bf_db->beamformee_sts);
		cl_snprintf(&buf, &len, &buf_size,
			    "Beamformee NSS:        %u\n", bf_db->nc);
		cl_snprintf(&buf, &len, &buf_size,
			    "Traffic active:        %s\n",
			    bf_db->traffic_active ? "True" : "False");
		cl_snprintf(&buf, &len, &buf_size,
			    "Sound start:           %s\n",
			    bf_db->sounding_start ? "True" : "False");
		cl_snprintf(&buf, &len, &buf_size,
			    "Sounding indications:  %u\n",
			    bf_db->sounding_indications);
		cl_snprintf(&buf, &len, &buf_size,
			    "Indication_timeout:    %s\n",
			    bf_db->indication_timeout ? "True" : "False");
		cl_snprintf(&buf, &len, &buf_size,
			    "Is on:                 %s\n",
			    is_on ? "True" : "False");
	}

	read_unlock_bh(&cl_hw->cl_sta_db.lock);

	err = cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);

	return err;
}

static int cl_bf_cli_help(struct cl_hw *cl_hw)
{
	char *ret_buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!ret_buf)
		return -ENOMEM;

	snprintf(ret_buf, PAGE_SIZE,
		 "bf usage\n"
		 "-a: Firmware BF control stats [0-Reset,1-PrintActive,2-PrintPassive]\n"
		 "-c: Print BF configuration\n"
		 "-d: Set debug level [0-OFF,1-ERROR,2-WARN,3-TRACE,4-INFO]\n"
		 "-e: Disable or Enable BF [0/1]\n"
		 "-f: Force BF [0-Disable,1-Enable]\n"
		 "-s: Print BF station info\n");

	err = cl_vendor_reply(cl_hw, ret_buf, strlen(ret_buf));
	kfree(ret_buf);

	return err;
}

static void cl_bf_timer_callback(unsigned long data)
{
	/*
	 * If timer expired it means that we started sounding but didn't get any
	 * indication for (10 * sounding_interval).
	 * So we disable sounding for this station (even when in starts again traffic).
	 */
	struct cl_sta *cl_sta = (struct cl_sta *)data;

	if (cl_sta) {
		struct cl_hw *cl_hw = cl_sta->cl_vif->cl_hw;

		bf_pr_trace(cl_hw, "[BF] Failed to get reply (%u)\n", cl_sta->sta_idx);
		cl_sta->bf_db.indication_timeout = true;
		cl_bf_sounding_decision(cl_hw, cl_sta);
	}
}

void cl_bf_sounding_start(struct cl_hw *cl_hw, enum sounding_type type, struct cl_sta **cl_sta_arr,
			  u8 sta_num, struct cl_sounding_info *recovery_elem)
{
#define STA_INDICES_STR_SIZE 64

	/* Send request to start sounding */
	u8 i, bw = CHNL_BW_MAX;
	char sta_indices_str[STA_INDICES_STR_SIZE] = {0};
	u8 str_len = 0;

	for (i = 0; i < sta_num; i++) {
		struct cl_sta *cl_sta = cl_sta_arr[i];
		struct cl_bf_sta_db *bf_db = &cl_sta->bf_db;

		bw = cl_sta->wrs_sta.assoc_bw;
		bf_db->synced = false;
		bf_db->sounding_start = true;
		bf_db->sounding_indications = 0;

		str_len += snprintf(sta_indices_str, STA_INDICES_STR_SIZE - str_len, "%u%s",
				    cl_sta->sta_idx, (i == sta_num - 1 ? ", " : ""));

	}

	bf_pr_trace(cl_hw, "[BF] Start sounding: Sta = %s\n", sta_indices_str);
	cl_sounding_send_request(cl_hw, cl_sta_arr, sta_num, SOUNDING_ENABLE, type, bw, 0,
				 recovery_elem);

#undef STA_INDICES_STR_SIZE
}

void cl_bf_sounding_stop(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	struct cl_bf_sta_db *bf_db = &cl_sta->bf_db;

	if (bf_db->sounding_start) {
		/* Send request to stop sounding */
		bf_db->synced = false;
		bf_db->sounding_start = false;
		bf_db->sounding_indications = 0;
		bf_pr_trace(cl_hw, "[BF] Sta = %u, Stop sounding\n", cl_sta->sta_idx);
		cl_sounding_send_request(cl_hw, &cl_sta, 1, SOUNDING_DISABLE, SOUNDING_TYPE_HE_SU,
					 0, 0, NULL);
		bf_pr_trace(cl_hw, "[BF] Sta: %u, Beamforming disabled\n", cl_sta->sta_idx);
	}
}

void cl_bf_sounding_decision(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	struct cl_bf_sta_db *bf_db = &cl_sta->bf_db;

	if (cl_bf_is_enabled(cl_hw) &&
	    cl_bf_is_beamformee_capable(cl_sta, false) &&
	    !bf_db->indication_timeout &&
	    !cl_vw_is_detected(cl_hw) &&
	    ((bf_db->beamformee_sts + 1) >= CL_BF_MIN_SOUNDING_NR) &&
	    (bf_db->traffic_active || cl_hw->bf_db.force)) {
		if (!bf_db->sounding_start)
			cl_bf_sounding_start(cl_hw, SOUNDING_TYPE_HE_SU, &cl_sta,
					     1, NULL);
	} else {
		cl_timer_disable(&bf_db->timer);
		cl_bf_sounding_stop(cl_hw, cl_sta);
	}
}

static u8 cl_bf_get_sts_he(struct ieee80211_sta *sta)
{
	u8 *phy_cap_info = sta->he_cap.he_cap_elem.phy_cap_info;

	if (phy_cap_info[0] & IEEE80211_HE_PHY_CAP0_CHANNEL_WIDTH_SET_160MHZ_IN_5G ||
	    phy_cap_info[0] & IEEE80211_HE_PHY_CAP0_CHANNEL_WIDTH_SET_80PLUS80_MHZ_IN_5G)
		return u8_get_bits(phy_cap_info[4],
				   IEEE80211_HE_PHY_CAP4_BEAMFORMEE_MAX_STS_ABOVE_80MHZ_MASK);
	else
		return u8_get_bits(phy_cap_info[4],
				   IEEE80211_HE_PHY_CAP4_BEAMFORMEE_MAX_STS_UNDER_80MHZ_MASK);
}

static u8 cl_bf_get_sts_vht(struct ieee80211_sta *sta)
{
	struct ieee80211_sta_vht_cap *vht_cap = &sta->vht_cap;

	return u32_get_bits(vht_cap->cap, IEEE80211_VHT_CAP_BEAMFORMEE_STS_MASK);
}

static u8 cl_bf_get_sts(struct ieee80211_sta *sta)
{
	if (sta->he_cap.has_he)
		return cl_bf_get_sts_he(sta);

	return cl_bf_get_sts_vht(sta);
}

void cl_bf_update_rate(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	struct cl_bf_sta_db *bf_db = &cl_sta->bf_db;

	/* Old & new BF state for main rate */
	bool bf_on_old = bf_db->is_on;
	bool bf_on_new = cl_bf_is_on(cl_hw, cl_sta, bf_db->num_ss);

	/* Old & new BF state for fallback rate */
	bool bf_on_old_fbk = bf_db->is_on_fallback;
	bool bf_on_new_fbk = cl_bf_is_on(cl_hw, cl_sta, bf_db->num_ss_fallback);

	if (bf_on_old != bf_on_new || bf_on_old_fbk != bf_on_new_fbk) {
		/* BF state for main rate or fallback rate changed */

		/* Save the new state */
		bf_db->is_on = bf_on_new;
		bf_db->is_on_fallback = bf_on_new_fbk;

		/* Update the firmware */
		if (cl_msg_tx_set_tx_bf(cl_hw, cl_sta->sta_idx, bf_on_new, bf_on_new_fbk))
			pr_err("%s: failed to set TX-BF\n", __func__);
	}
}

void cl_bf_sta_add(struct cl_hw *cl_hw, struct cl_sta *cl_sta, struct ieee80211_sta *sta)
{
	/* Beamformee capabilities */
	bool su_beamformee_capable = cl_bf_is_beamformee_capable(cl_sta, false);
	bool mu_beamformee_capable = cl_bf_is_beamformee_capable(cl_sta, true);
	struct cl_bf_sta_db *bf_db = &cl_sta->bf_db;

	bf_db->beamformee_sts = cl_bf_get_sts(sta);
	bf_db->nc = min_t(u8, sta->rx_nss, WRS_SS_MAX) - 1;

	bf_pr_trace(cl_hw,
		    "[BF] sta_idx: %u, su_beamformee_capable: %u, mu_beamformee_capable: %u, "
		    "beamformee_sts: %u, nc = %u\n",
		    cl_sta->sta_idx, su_beamformee_capable, mu_beamformee_capable,
		    bf_db->beamformee_sts, bf_db->nc);

	if (bf_db->beamformee_sts == 0)
		bf_db->beamformee_sts = 3;

	/*
	 * Init the BF timer
	 * Period is set to 0. It will be updated before enabling it.
	 */
	cl_timer_init(&bf_db->timer, cl_bf_timer_callback, (unsigned long)cl_sta, 0, false);
}

void cl_bf_sta_remove(struct cl_sta *cl_sta)
{
	struct cl_bf_sta_db *bf_db = &cl_sta->bf_db;

	/* Disable only initialized timers */
	if (!bf_db->nc)
		return;

	/* Disable timer before removing the station */
	cl_timer_disable_sync(&bf_db->timer);
}

void cl_bf_sta_active(struct cl_hw *cl_hw, struct cl_sta *cl_sta, bool active)
{
	struct cl_bf_sta_db *bf_db = &cl_sta->bf_db;

	if (bf_db->traffic_active != active) {
		bf_pr_trace(cl_hw, "[BF] Sta: %u, Active: %s\n",
			    cl_sta->sta_idx, active ? "True" : " False");

		bf_db->traffic_active = active;
		cl_bf_sounding_decision(cl_hw, cl_sta);
	}
}

void cl_bf_reset_sounding_ind(struct cl_sta *cl_sta)
{
	cl_sta->bf_db.sounding_indications = 0;
}

bool cl_bf_is_enabled(struct cl_hw *cl_hw)
{
	return cl_hw->conf->ce_bf_en;
}

int cl_bf_cli(struct cl_hw *cl_hw, struct cli_params *cli_params)
{
	u32 expected_params = 0;
	bool fw_ctrl_stats = false;
	bool config_print = false;
	bool debug_set = false;
	bool enable_set = false;
	bool force_set = false;
	bool sta_info_print = false;

	switch (cli_params->option) {
	case 'a':
		fw_ctrl_stats = true;
		expected_params = 1;
		break;
	case 'c':
		config_print = true;
		expected_params = 0;
		break;
	case 'd':
		debug_set = true;
		expected_params = 1;
		break;
	case 'e':
		enable_set = true;
		expected_params = 1;
		break;
	case 'f':
		force_set = true;
		expected_params = 1;
		break;
	case 's':
		sta_info_print = true;
		expected_params = 0;
		break;
	case '?':
		return cl_bf_cli_help(cl_hw);
	default:
		cl_dbg_err(cl_hw, "Illegal option (%c) - try '?' for help\n", cli_params->option);
		goto out_err;
	}

	if (expected_params != cli_params->num_params) {
		cl_dbg_err(cl_hw, "Wrong number of arguments (expected %u) (actual %u)\n",
			   expected_params, cli_params->num_params);
		goto out_err;
	}

	if (fw_ctrl_stats)
		cl_bf_cli_fw_control_stats(cl_hw, cli_params->params[0]);
	else if (config_print)
		return cl_bf_cli_config_print(cl_hw);
	else if (debug_set)
		cl_bf_cli_debug_set(cl_hw, cli_params->params[0]);
	else if (enable_set)
		cl_bf_enable(cl_hw, !!cli_params->params[0]);
	else  if (force_set)
		cl_bf_cli_force_set(cl_hw, !!cli_params->params[0]);
	else if (sta_info_print)
		return cl_bf_cli_sta_info_print(cl_hw);

	return 0;
out_err:
	return -EIO;
}

bool cl_bf_is_on(struct cl_hw *cl_hw, struct cl_sta *cl_sta, u8 nss)
{
	struct cl_bf_sta_db *bf_db = &cl_sta->bf_db;

	return (cl_bf_is_enabled(cl_hw) &&
		bf_db->sounding_start &&
		bf_db->sounding_indications &&
		(nss <= min(cl_hw->conf->ci_bf_max_nss, bf_db->nc)));
}

void cl_bf_sounding_req_success(struct cl_hw *cl_hw, struct cl_sounding_info *new_elem)
{
	/*
	 * Start a timer to check that we are receiving indications from the station.
	 * The period of the timer is set to 10 times the sounding-interval.
	 */
	u8 i;
	struct cl_sta *cl_sta;
	struct cl_bf_sta_db *bf_db;
	unsigned long period = CL_BF_TIMER_SOUNDING_FACTOR * cl_sounding_get_interval(cl_hw);

	for (i = 0; i < new_elem->sta_num; i++) {
		cl_sta = new_elem->su_cl_sta_arr[i];
		bf_db = &cl_sta->bf_db;

		if (cl_sta) {
			cl_sta->bf_db.sounding_start = true;
			cl_sta->su_sid = new_elem->sounding_id;

			/* Don't enable BF timer in case of force mode */
			if (!cl_hw->bf_db.force) {
				cl_timer_period_set(&bf_db->timer, period);
				cl_timer_enable(&bf_db->timer);
			}
		}
	}
}

void cl_bf_sounding_req_failure(struct cl_hw *cl_hw, struct cl_sounding_info *new_elem)
{
	u8 i;
	struct cl_sta *cl_sta;
	struct cl_bf_sta_db *bf_db;

	for (i = 0; i < new_elem->sta_num; i++) {
		cl_sta = new_elem->su_cl_sta_arr[i];

		if (cl_sta) {
			bf_db = &cl_sta->bf_db;
			bf_db->sounding_start = false;
			bf_db->sounding_indications = 0;
		}
	}
}

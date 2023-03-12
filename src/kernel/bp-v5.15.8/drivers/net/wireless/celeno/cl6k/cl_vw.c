// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_vw.h"
#include "cl_msg_tx.h"
#include "cl_rssi.h"
#include "cl_env_det.h"
#include "cl_utils.h"
#include "cl_band.h"

#define CL_VW_DBG(...) \
	do { \
		if (unlikely(cl_hw->vw_db.dbg)) \
			pr_debug(__VA_ARGS__); \
	} while (0)

static void cl_vw_enable(struct cl_hw *cl_hw, struct cl_vw_db *vw_db)
{
	if (!vw_db->is_vw_global) {
		CL_VW_DBG("[VW] Enable\n");
		vw_db->is_vw_global = true;
	}
}

static void cl_vw_disable(struct cl_hw *cl_hw, struct cl_vw_db *vw_db)
{
	if (vw_db->is_vw_global) {
		CL_VW_DBG("[VW] Disable\n");
		vw_db->is_vw_global = false;
	}
}

static void cl_vw_check_rssi(struct cl_hw *cl_hw, struct cl_vw_db *vw_db,
			     u8 num_sta, s8 rssi[MAX_ANTENNAS])
{
	/* Sort RSSI's from largest to smallest. */
	cl_rssi_sort_descending(rssi, cl_hw->num_antennas);

	/*
	 * In vw setup, management frames are received only from a single phy,
	 * and therefore all RSSI's except the first one will be very low.
	 * Parameter vw_db->is_vw_rssi is set to true only if all stations fulfill this condition.
	 */
	if (num_sta == 1)
		vw_db->is_vw_rssi = ((cl_hw->num_antennas >= 2) &&
				     (rssi[0] - rssi[1] >= cl_hw->conf->ci_vw_delta_rssi));
	else
		vw_db->is_vw_rssi &= ((cl_hw->num_antennas >= 2) &&
				      (rssi[0] - rssi[1] >= cl_hw->conf->ci_vw_delta_rssi));

	CL_VW_DBG("[VW] rssi = [%d,%d], is_vw_rssi = %u\n", rssi[0], rssi[1], vw_db->is_vw_rssi);
}

static void cl_vw_check_mac(struct cl_hw *cl_hw, struct cl_vw_db *vw_db, u8 *addr, u8 num_sta)
{
	u64 mac_addr = ether_addr_to_u64(addr);

	/*
	 * Check if this is a vw setup according to mac address of sations.
	 * In vw setup mac addresses are expected to be continuous, or have a constant delta.
	 */
	if (num_sta == 1) {
		vw_db->is_vw_mac = false;
	} else if (num_sta == 2) {
		/*
		 * When second station connects calculate the delta from the first mac.
		 * If 4 MSB are equal set vw_db->is_vw_mac to true;
		 */
		vw_db->mac_addr_delta = mac_addr - vw_db->mac_addr_prev;
		vw_db->is_vw_mac = (vw_db->mac_addr_delta < 0xffff) ? true : false;
	} else {
		u64 expected_mac_addr = vw_db->mac_addr_prev + vw_db->mac_addr_delta;

		vw_db->is_vw_mac &= ((expected_mac_addr == mac_addr) ? true : false);
	}

	CL_VW_DBG("[VW] mac = %llx, mac_prev = %llx, is_vw_mac = %u\n",
		  mac_addr, vw_db->mac_addr_prev, vw_db->is_vw_mac);

	vw_db->mac_addr_prev = mac_addr;
}

static void cl_vw_check_time(struct cl_hw *cl_hw, struct cl_vw_db *vw_db, u8 num_sta)
{
	/* In vw setup the delta between connections is very short. */
	unsigned long assoc_timestamp = jiffies_to_msecs(jiffies);

	/*
	 * Update the global parameter - vw_db->is_vw_time.
	 * This parameter will be true only if all connected stations are detected as vw.
	 */
	if (num_sta == 1) {
		vw_db->is_vw_time = true;
	} else {
		unsigned long diff_timestamp = assoc_timestamp - vw_db->assoc_timestamp_prev;

		vw_db->is_vw_time &= (diff_timestamp < cl_hw->conf->ci_vw_delta_time);
	}

	CL_VW_DBG("[VW] time = %lu, time_prev = %lu, is_vw_time = %u\n",
		  assoc_timestamp, vw_db->assoc_timestamp_prev, vw_db->is_vw_time);

	vw_db->assoc_timestamp_prev = assoc_timestamp;
}

static int cl_vw_cli_help(struct cl_hw *cl_hw)
{
	char *buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!buf)
		return -ENOMEM;

	snprintf(buf, PAGE_SIZE,
		 "vw usage:\n"
		 "-d: Set debug [0/1]\n"
		 "-f: Set force [0/1]\n"
		 "-r: Set delta rssi [rssi]\n"
		 "-t: Set delta time [time]\n");

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

void cl_vw_sta_assoc(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
		     s8 rssi[MAX_ANTENNAS], u8 num_sta)
{
	struct cl_vw_db *vw_db = &cl_hw->vw_db;
	bool is_vw = false;
	bool is_clean = cl_env_det_is_clean(cl_hw);

	if (!cl_hw->conf->ci_vw_en)
		return;

	CL_VW_DBG("[VW] sta_assoc = %pM, num_sta = %u\n", cl_sta->addr, num_sta);

	cl_vw_check_rssi(cl_hw, vw_db, num_sta, rssi);
	cl_vw_check_mac(cl_hw, vw_db, cl_sta->addr, num_sta);
	cl_vw_check_time(cl_hw, vw_db, num_sta);

	/* Time condition must be true and at leat rssi or mac */
	is_vw = vw_db->is_vw_time && (vw_db->is_vw_rssi || vw_db->is_vw_mac);

	/* Environment must also be clean */
	if ((is_vw && is_clean) || vw_db->force)
		cl_vw_enable(cl_hw, vw_db);
	else
		cl_vw_disable(cl_hw, vw_db);
}

void cl_vw_sta_remove(struct cl_hw *cl_hw, struct cl_sta *cl_sta, u8 num_sta)
{
	if (!cl_hw->conf->ci_vw_en)
		return;

	CL_VW_DBG("[VW] sta_remove = %pM, num_sta = %u\n", cl_sta->addr, num_sta);

	/* If this is the last station reset the vw flags */
	if (num_sta == 0) {
		struct cl_vw_db *vw_db = &cl_hw->vw_db;

		vw_db->is_vw_rssi = 0;
		vw_db->is_vw_mac = 0;
		vw_db->is_vw_time = 0;
		vw_db->mac_addr_prev = 0;
		vw_db->assoc_timestamp_prev = 0;
		vw_db->mac_addr_delta = 0;

		cl_vw_disable(cl_hw, vw_db);
	}
}

bool cl_vw_is_detected(struct cl_hw *cl_hw)
{
	return cl_hw->vw_db.is_vw_global;
}

void cl_vw_start_tx_ba_session(struct cl_hw *cl_hw, struct ieee80211_sta *sta)
{
	if (cl_hw->conf->ci_vw_start_ba_session &&
	    (sta->ht_cap.ht_supported || sta->vht_cap.vht_supported || cl_band_is_6g(cl_hw)) &&
	    cl_vw_is_detected(cl_hw)) {
		cl_dbg_trace(cl_hw, " %pM\n", sta->addr);
		ieee80211_start_tx_ba_session(sta, 0, cl_hw->conf->ce_tx_ba_session_timeout);
	}
}

int cl_vw_cli(struct cl_hw *cl_hw, struct cli_params *cli_params)
{
	u32 expected_params = 0;
	bool set_debug = false;
	bool set_force = false;
	bool set_delta_rssi = false;
	bool set_delta_time = false;

	switch (cli_params->option) {
	case 'd':
		set_debug = true;
		expected_params = 1;
		break;
	case 'f':
		set_force = true;
		expected_params = 1;
		break;
	case 'r':
		set_delta_rssi = true;
		expected_params = 1;
		break;
	case 't':
		set_delta_time = true;
		expected_params = 1;
		break;
	case '?':
		return cl_vw_cli_help(cl_hw);
	default:
		cl_dbg_err(cl_hw, "Illegal option (%c) - try '?' for help\n", cli_params->option);
		goto out_err;
	}

	if (expected_params != cli_params->num_params) {
		cl_dbg_err(cl_hw, "Wrong number of arguments (expected %u) (actual %u)\n",
			   expected_params, cli_params->num_params);
		goto out_err;
	}

	if (set_debug) {
		cl_hw->vw_db.dbg = (bool)cli_params->params[0];
		pr_debug("[VW] debug = %u\n", cl_hw->vw_db.dbg);
		return 0;
	}

	if (set_force) {
		cl_hw->vw_db.force = (bool)cli_params->params[0];
		pr_debug("[VW] force = %u\n", cl_hw->vw_db.force);
		return 0;
	}

	if (set_delta_rssi) {
		cl_hw->conf->ci_vw_delta_rssi = (s8)cli_params->params[0];
		pr_debug("[VW] delta rssi = %d\n", cl_hw->conf->ci_vw_delta_rssi);
		return 0;
	}

	if (set_delta_time) {
		cl_hw->conf->ci_vw_delta_time = (u32)cli_params->params[0];
		pr_debug("[VW] delta time = %u\n", cl_hw->conf->ci_vw_delta_time);
		return 0;
	}

out_err:
	return -EIO;
}

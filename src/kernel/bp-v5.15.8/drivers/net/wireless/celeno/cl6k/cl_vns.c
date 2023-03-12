// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_vns.h"
#include "cl_rssi.h"
#include "cl_msg_tx.h"
#include "cl_maintenance.h"
#include "cl_mac_addr.h"

#define CL_VNS_HASH_IDX    (ETH_ALEN - 2)
#define CL_VNS_MGMT_AGEOUT 200

#define CL_VNS_DBG(...) \
	do { \
		if (unlikely(cl_hw->vns_db.dbg)) \
			pr_debug(__VA_ARGS__); \
	} while (0)

#define CL_VNS_DBG_PER_PACKET(...) \
	do { \
		if (unlikely(cl_hw->vns_db.dbg_per_packet)) \
			pr_debug(__VA_ARGS__); \
	} while (0)

static void cl_vns_mgmt_list_add(struct cl_hw *cl_hw, u8 *addr, s8 strongset_rssi)
{
	/* Add entry to mgmt list */
	struct cl_vns_rssi_entry *entry = kzalloc(sizeof(*entry), GFP_ATOMIC);

	if (!entry)
		return;

	/* Fill entry parameters */
	INIT_LIST_HEAD(&entry->list_all);
	INIT_LIST_HEAD(&entry->list_addr);
	cl_mac_addr_copy(entry->addr, addr);
	entry->strongset_rssi = strongset_rssi;
	entry->timestamp = jiffies;

	/* Add to list */
	cl_hw->vns_db.mgmt_db.num_entries++;
	list_add(&entry->list_all, &cl_hw->vns_db.mgmt_db.list_all);
	list_add(&entry->list_addr, &cl_hw->vns_db.mgmt_db.list_addr[addr[CL_VNS_HASH_IDX]]);
}

static void cl_vns_mgmt_list_remove(struct cl_hw *cl_hw, struct cl_vns_rssi_entry *entry)
{
	/* Remove entry from mgmt list */
	cl_hw->vns_db.mgmt_db.num_entries--;
	list_del(&entry->list_all);
	list_del(&entry->list_addr);
	kfree(entry);
}

static void cl_vns_mgmt_list_flush(struct cl_hw *cl_hw)
{
	/* Flush all mgmt list */
	if (cl_hw->vns_db.mgmt_db.num_entries > 0) {
		struct cl_vns_rssi_entry *entry = NULL, *tmp = NULL;

		list_for_each_entry_safe(entry, tmp, &cl_hw->vns_db.mgmt_db.list_all, list_all)
			cl_vns_mgmt_list_remove(cl_hw, entry);
	}
}

static struct cl_vns_rssi_entry *cl_vns_mgmt_list_find(struct cl_hw *cl_hw, u8 *addr)
{
	/* Search for entry in mgmt list */
	struct cl_vns_mgmt_db *mgmt_db = &cl_hw->vns_db.mgmt_db;

	if (mgmt_db->num_entries > 0) {
		struct cl_vns_rssi_entry *entry = NULL;

		list_for_each_entry(entry, &mgmt_db->list_addr[addr[CL_VNS_HASH_IDX]], list_addr)
			if (ether_addr_equal(entry->addr, addr))
				return entry;
	}

	return NULL;
}

static bool cl_vns_mgmt_list_find_and_remove(struct cl_hw *cl_hw, u8 *addr)
{
	/*
	 * Search for entry in mgmt list
	 * If entry found remove it and return true
	 */
	struct cl_vns_rssi_entry *entry = cl_vns_mgmt_list_find(cl_hw, addr);

	if (entry) {
		cl_vns_mgmt_list_remove(cl_hw, entry);
		return true;
	}

	return false;
}

static void cl_vns_mgmt_list_ageout(struct cl_hw *cl_hw)
{
	/* Remove old entries from mgmt list */
	struct cl_vns_mgmt_db *mgmt_db = &cl_hw->vns_db.mgmt_db;

	if (mgmt_db->num_entries > 0) {
		struct cl_vns_rssi_entry *entry = NULL, *tmp = NULL;
		unsigned long delta_time;

		list_for_each_entry_safe(entry, tmp, &mgmt_db->list_all, list_all) {
			delta_time = jiffies_to_msecs(jiffies - entry->timestamp);

			if (delta_time > CL_VNS_MGMT_AGEOUT) {
				CL_VNS_DBG("[VNS] sta %pM removed from list because of ageout\n",
					   entry->addr);
				cl_vns_mgmt_list_remove(cl_hw, entry);
			}
		}
	}
}

static s8 cl_vns_get_strongest_rssi(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	struct cl_vns_sta_db *vns_db = &cl_sta->vns_db;
	s32 rssi_samples = vns_db->rssi_samples;

	if (rssi_samples > 0) {
		u8 i;
		s32 strongest_rssi = S32_MIN;

		for (i = 0; i < cl_hw->num_antennas; i++)
			if (vns_db->rssi_sum[i] > strongest_rssi)
				strongest_rssi = vns_db->rssi_sum[i];

		/* Reset rssi for next time that cl_vns_get_strongest_rssi() will be called */
		memset(vns_db->rssi_sum, 0, sizeof(vns_db->rssi_sum));
		vns_db->rssi_samples = 0;

		return (s8)(strongest_rssi / rssi_samples);
	}

	return 0;
}

static void cl_vns_monitor_rssi(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	/* Monitor RSSI of associated stations and update state if necessary */
	struct cl_vns_sta_db *vns_db = &cl_sta->vns_db;
	s8 strongset_rssi = cl_vns_get_strongest_rssi(cl_hw, cl_sta);
	s8 rssi_thr = 0;
	bool is_vns = false;

	if (strongset_rssi == 0)
		return;

	/*
	 * Calculate RSSI threshold (take hystersis into
	 *  consideration according to current state)
	 */
	if (vns_db->is_very_near)
		rssi_thr = cl_hw->conf->ci_vns_rssi_thr - cl_hw->conf->ci_vns_rssi_hys;
	else
		rssi_thr = cl_hw->conf->ci_vns_rssi_thr + cl_hw->conf->ci_vns_rssi_hys;

	is_vns = (strongset_rssi > rssi_thr) ? true : false;

	/* Avoid toggling of VNS state - require two consecutive same decisions */
	if (is_vns != vns_db->prev_decision) {
		vns_db->prev_decision = is_vns;
		return;
	}

	if (is_vns != vns_db->is_very_near) {
		CL_VNS_DBG("[VNS] sta %pM changed state, strongset_rssi = %d, is_vns = %s\n",
			   cl_sta->addr, strongset_rssi, is_vns ? "TRUE" : "FALSE");
		vns_db->is_very_near = is_vns;
		cl_msg_tx_set_vns(cl_hw, cl_sta->sta_idx, is_vns);
	}
}

static void cl_vns_recovery_sta(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	if (cl_sta->vns_db.is_very_near)
		cl_msg_tx_set_vns(cl_hw, cl_sta->sta_idx, true);
}

static int cl_vns_print_sta_state(struct cl_hw *cl_hw)
{
	struct cl_sta *cl_sta = NULL;
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;

	/* Go over all stations - use bottom-half lock */
	read_lock_bh(&cl_hw->cl_sta_db.lock);

	list_for_each_entry(cl_sta, &cl_hw->cl_sta_db.head, list)
		cl_snprintf(&buf, &len, &buf_size,
			    "sta_idx = %u, mac = %pM, is_very_near = %s\n",
			    cl_sta->sta_idx, cl_sta->addr,
			    cl_sta->vns_db.is_very_near ?
			    "true" : "false");

	read_unlock_bh(&cl_hw->cl_sta_db.lock);
	err = cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);

	return err;
}

static int cl_vns_cli_help(struct cl_hw *cl_hw)
{
	char *buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!buf)
		return -ENOMEM;

	snprintf(buf, PAGE_SIZE,
		 "vns usage\n"
		 "-a: Set rssi auto response threhold [thr]\n"
		 "-d: Set debug [0/1]\n"
		 "-h: Set rssi hystersis [hyst]\n"
		 "-l: Set power limit [limit]\n"
		 "-m: Set power mode [mode]\n"
		 "-p: Set debug per packet [0/1]\n"
		 "-s: Print all stations state\n"
		 "-t: Set rssi threshold [thr]\n");

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

void cl_vns_init(struct cl_hw *cl_hw)
{
	int i = 0;
	u8 vns_pwr_mode = cl_hw->conf->ci_vns_pwr_mode;

	if (vns_pwr_mode == VNS_MODE_DATA || vns_pwr_mode == VNS_MODE_ALL)
		cl_hw->vns_db.enable = true;

	spin_lock_init(&cl_hw->vns_db.lock);

	INIT_LIST_HEAD(&cl_hw->vns_db.mgmt_db.list_all);

	for (i = 0; i < STA_HASH_SIZE; i++)
		INIT_LIST_HEAD(&cl_hw->vns_db.mgmt_db.list_addr[i]);
}

void cl_vns_close(struct cl_hw *cl_hw)
{
	if (cl_hw->vns_db.enable) {
		spin_lock_bh(&cl_hw->vns_db.lock);
		cl_vns_mgmt_list_flush(cl_hw);
		spin_unlock_bh(&cl_hw->vns_db.lock);

		cl_hw->vns_db.enable = false;
	}
}

void cl_vns_maintenance(struct cl_hw *cl_hw)
{
	/*
	 * Maintenance:
	 * 1) Remove old entries from mgmt list
	 * 2) Update state for associated clients
	 */
	if (!cl_hw->vns_db.enable)
		return;

	cl_hw->vns_db.interval_period += CL_MAINTENANCE_PERIOD_SLOW_MS;

	if (cl_hw->vns_db.interval_period < cl_hw->conf->ci_vns_maintenance_time)
		return;

	cl_hw->vns_db.interval_period = 0;

	spin_lock_bh(&cl_hw->vns_db.lock);
	cl_vns_mgmt_list_ageout(cl_hw);
	spin_unlock_bh(&cl_hw->vns_db.lock);

	/* Check RSSI of associated stations */
	cl_sta_loop(cl_hw, cl_vns_monitor_rssi);
}

void cl_vns_mgmt_handler(struct cl_hw *cl_hw, u8 *addr, s8 rssi[MAX_ANTENNAS])
{
	/*
	 * Handle management frames of non-associated stations,
	 * and save the very-near ones in the mgmt list
	 */
	s8 strongset_rssi = 0;
	struct cl_vns_rssi_entry *entry = NULL;

	if (!cl_hw->vns_db.enable)
		return;

	strongset_rssi = cl_rssi_get_strongest(cl_hw, rssi);

	spin_lock_bh(&cl_hw->vns_db.lock);

	entry = cl_vns_mgmt_list_find(cl_hw, addr);

	if (entry) {
		if (strongset_rssi > cl_hw->conf->ci_vns_rssi_thr) {
			/* Update exisiting entry */
			entry->strongset_rssi = strongset_rssi;
			entry->timestamp = jiffies;
			CL_VNS_DBG("[VNS] sta %pM updated in list (rssi=%d)\n",
				   addr, strongset_rssi);
		} else {
			/* Remove exisiting entry */
			cl_vns_mgmt_list_remove(cl_hw, entry);
			CL_VNS_DBG("[VNS] sta %pM removed from list (rssi=%d)\n",
				   addr, strongset_rssi);
		}
	} else {
		if (strongset_rssi > cl_hw->conf->ci_vns_rssi_thr) {
			/* Add new entry */
			cl_vns_mgmt_list_add(cl_hw, addr, strongset_rssi);
			CL_VNS_DBG("[VNS] sta %pM added to list (rssi=%d)\n",
				   addr, strongset_rssi);
		}
	}

	spin_unlock_bh(&cl_hw->vns_db.lock);
}

bool cl_vns_is_very_near(struct cl_hw *cl_hw, struct cl_sta *cl_sta, struct sk_buff *skb)
{
	bool is_vns = false;
	/* This function checks for every TX packet whether it's VNS or not */
	if (!cl_hw->vns_db.enable)
		return false;

	if (unlikely(!cl_sta)) {
		struct ieee80211_hdr *mac_hdr = (struct ieee80211_hdr *)skb->data;

		spin_lock_bh(&cl_hw->vns_db.lock);
		is_vns = cl_vns_mgmt_list_find(cl_hw, mac_hdr->addr1) ? true : false;
		spin_unlock_bh(&cl_hw->vns_db.lock);

		CL_VNS_DBG_PER_PACKET("[VNS] mgmt-sta %pM, is_vns = %s\n",
				      mac_hdr->addr1, is_vns ? "TRUE" : "FALSE");

		return is_vns;
	}
	is_vns = cl_sta->vns_db.is_very_near;

	CL_VNS_DBG_PER_PACKET("[VNS] assoc-sta %pM, is_vns = %s\n",
			      cl_sta->addr, is_vns ? "TRUE" : "FALSE");

	return is_vns;
}

void cl_vns_sta_add(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	/* Update is_very_near according to mgmt list */
	bool is_vns = false;

	if (!cl_hw->vns_db.enable)
		return;

	spin_lock_bh(&cl_hw->vns_db.lock);
	is_vns = cl_vns_mgmt_list_find_and_remove(cl_hw, cl_sta->addr);
	spin_unlock_bh(&cl_hw->vns_db.lock);

	if (is_vns) {
		CL_VNS_DBG("[VNS] sta %pM connected - is_vns = TRUE\n", cl_sta->addr);
		cl_sta->vns_db.is_very_near = true;
		cl_sta->vns_db.prev_decision = true;
		cl_msg_tx_set_vns(cl_hw, cl_sta->sta_idx, true);
	} else {
		CL_VNS_DBG("[VNS] sta %pM connected - is_vns = FALSE\n", cl_sta->addr);
	}
}

void cl_vns_handle_rssi(struct cl_hw *cl_hw, struct cl_sta *cl_sta, s8 rssi[MAX_ANTENNAS])
{
	/* Collect rssi samples */
	int i;

	if (!cl_hw->vns_db.enable)
		return;

	for (i = 0; i < cl_hw->num_antennas; i++)
		cl_sta->vns_db.rssi_sum[i] += rssi[i];

	cl_sta->vns_db.rssi_samples++;
}

void cl_vns_recovery(struct cl_hw *cl_hw)
{
	CL_VNS_DBG("[VNS] Recovery\n");
	cl_sta_loop_bh(cl_hw, cl_vns_recovery_sta);
}

int cl_vns_cli(struct cl_hw *cl_hw, struct cli_params *cli_params)
{
	u32 expected_params = 0;
	bool set_rssi_auto_rsp_thr = false;
	bool set_dbg = false;
	bool set_rssi_hyst = false;
	bool set_pwr_limit = false;
	bool set_pwr_mode = false;
	bool set_dbg_per_packet = false;
	bool print_sta_state = false;
	bool set_rssi_thr = false;

	switch (cli_params->option) {
	case 'a':
		set_rssi_auto_rsp_thr = true;
		expected_params = 1;
		break;
	case 'd':
		set_dbg = true;
		expected_params = 1;
		break;
	case 'h':
		set_rssi_hyst = true;
		expected_params = 1;
		break;
	case 'l':
		set_pwr_limit = true;
		expected_params = 1;
		break;
	case 'm':
		set_pwr_mode = true;
		expected_params = 1;
		break;
	case 'p':
		set_dbg_per_packet = true;
		expected_params = 1;
		break;
	case 's':
		print_sta_state = true;
		expected_params = 0;
		break;
	case 't':
		set_rssi_thr = true;
		expected_params = 1;
		break;
	case '?':
		return cl_vns_cli_help(cl_hw);
	default:
		cl_dbg_err(cl_hw, "Illegal option (%c) - try '?' for help\n", cli_params->option);
		goto out_err;
	}

	if (expected_params != cli_params->num_params) {
		cl_dbg_err(cl_hw, "Wrong number of arguments (expected %u) (actual %u)\n",
			   expected_params, cli_params->num_params);
		goto out_err;
	}

	if (set_rssi_auto_rsp_thr) {
		cl_hw->conf->ci_vns_rssi_auto_resp_thr = (s8)cli_params->params[0];
		pr_debug("[VNS] rssi auto response threshold = %d\n",
			 cl_hw->conf->ci_vns_rssi_auto_resp_thr);
		return 0;
	}

	if (set_dbg) {
		cl_hw->vns_db.dbg = (bool)cli_params->params[0];
		pr_debug("[VNS] debug = %s\n", cl_hw->vns_db.dbg ? "enable" : "disable");
		return 0;
	}

	if (set_pwr_limit) {
		cl_hw->conf->ci_vns_pwr_limit = (u8)cli_params->params[0];
		pr_debug("[VNS] power limit = %u\n", cl_hw->conf->ci_vns_pwr_limit);
		return 0;
	}

	if (set_rssi_hyst) {
		cl_hw->conf->ci_vns_rssi_hys = (s8)cli_params->params[0];
		pr_debug("[VNS] rssi hystersis = %d\n", cl_hw->conf->ci_vns_rssi_hys);
		return 0;
	}

	if (set_pwr_mode) {
		cl_hw->conf->ci_vns_pwr_mode = (u8)cli_params->params[0];
		pr_debug("[VNS] power mode = %u\n", cl_hw->conf->ci_vns_pwr_mode);
		return 0;
	}

	if (set_dbg_per_packet) {
		cl_hw->vns_db.dbg_per_packet = (bool)cli_params->params[0];
		pr_debug("[VNS] debug per packet = %s\n",
			 cl_hw->vns_db.dbg_per_packet ? "enable" : "disable");
		return 0;
	}

	if (set_rssi_thr) {
		cl_hw->conf->ci_vns_rssi_thr = (s8)cli_params->params[0];
		pr_debug("[VNS] rssi threshold = %d\n", cl_hw->conf->ci_vns_rssi_thr);
		return 0;
	}

	if (print_sta_state)
		return cl_vns_print_sta_state(cl_hw);

out_err:
	return -EIO;
}

// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_bss_color.h"
#include "cl_utils.h"
#include "cl_mac_addr.h"
#include "cl_tx.h"
#include "cl_msg_tx.h"

static int cl_bss_color_cli_help(struct cl_hw *cl_hw)
{
	char *buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!buf)
		return -ENOMEM;

	snprintf(buf, PAGE_SIZE,
		 "bss_color usage:\n"
		 "-a : print the current BSS color information\n"
		 "-b : add color to blacklist for debug [color]\n"
		 "-c : send single color_in_use report [sta_idx][color]\n"
		 "-d : send single colision report [sta_idx][color]\n"
		 "-e : force collision [color][direction 0:DL, 1:UL]\n");

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

static int cl_bss_color_config_print(struct cl_vif *cl_vif)
{
	struct cl_hw *cl_hw = cl_vif->cl_hw;
	struct cfg80211_he_bss_color
		*he_bss_color = &cl_vif->vif->bss_conf.he_bss_color;
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;

	cl_snprintf(&buf, &len, &buf_size,
		    "-------------------------------\n"
		    "BSS color current configuration\n"
		    "-------------------------------\n");
	cl_snprintf(&buf, &len, &buf_size,
		    "color     = [%u]\n", he_bss_color->color);
	cl_snprintf(&buf, &len, &buf_size,
		    "enabled   = [%u]\n", he_bss_color->enabled);
	cl_snprintf(&buf, &len, &buf_size,
		    "partial   = [%u]\n", he_bss_color->partial);
	cl_snprintf(&buf, &len, &buf_size,
		    "blacklist = [0x%llx]\n", cl_hw->bss_color_blacklist);

	err = cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);

	return err;
}

static void cl_bss_color_send_collision_report(struct cl_vif *cl_vif,
					       struct cl_sta *cl_sta,
					       u8 color)
{
	struct cl_hw *cl_hw = cl_vif->cl_hw;
	struct sk_buff *skb;
	struct ieee80211_mgmt *mgmt;
	struct wnm_event_report_collision *event_report;
	int hdr_len = offsetofend(struct ieee80211_mgmt, u.action.category);
	u64 color_mask = BIT(color);

	if (!cl_sta) {
		cl_dbg_err(cl_hw, "cl_sta is NULL - return\n");
		return;
	}

	skb = dev_alloc_skb(cl_hw->hw->extra_tx_headroom + hdr_len +
			    sizeof(struct wnm_event_report_collision));
	if (!skb)
		return;

	skb_reserve(skb, cl_hw->hw->extra_tx_headroom);
	mgmt = skb_put_zero(skb, hdr_len);
	mgmt->frame_control = cpu_to_le16(IEEE80211_FTYPE_MGMT |
					  IEEE80211_STYPE_ACTION);

	cl_mac_addr_copy(mgmt->da, cl_sta->addr);
	cl_mac_addr_copy(mgmt->sa, cl_vif->vif->addr);
	cl_mac_addr_copy(mgmt->bssid, cl_sta->addr);
	mgmt->u.action.category = WLAN_CATEGORY_WNM;
	event_report = skb_put_zero(skb, sizeof(struct wnm_event_report_collision));
	event_report->wnm_action = WMN_ACTION_EVENT_REPORT;
	event_report->dialog_token = 0; /* Autonomous report */
	event_report->elem_id = WLAN_EID_EVENT_REPORT;
	event_report->length = 3 + 8;
	event_report->event_token = 0;
	event_report->event_type = WMN_ACTION_EVENT_REPORT_TYPE_COLOR_COLLISION;
	event_report->event_report_status = 0; /* SUCCESSFUL */
	event_report->color_mask = color_mask;

	ieee80211_tx_prepare_skb(cl_hw->hw, cl_vif->vif, skb, cl_hw->nl_band,
				 NULL);
	cl_tx_single(cl_hw, cl_sta, skb, false, true);
	cl_dbg_verbose(cl_hw, "Sent\n");
}

static void cl_bss_color_send_color_in_use_report(struct cl_vif *cl_vif,
						  struct cl_sta *cl_sta,
						  u8 ap_color)
{
	struct cl_hw *cl_hw = cl_vif->cl_hw;
	struct sk_buff *skb;
	struct ieee80211_mgmt *mgmt;
	struct wnm_event_report_in_use *event_report;
	int hdr_len = offsetofend(struct ieee80211_mgmt, u.action.category);

	if (!cl_sta) {
		cl_dbg_err(cl_hw, "cl_sta is NULL - return\n");
		return;
	}

	skb = dev_alloc_skb(cl_hw->hw->extra_tx_headroom + hdr_len +
			    sizeof(struct wnm_event_report_in_use));
	if (!skb)
		return;

	skb_reserve(skb, cl_hw->hw->extra_tx_headroom);
	mgmt = skb_put_zero(skb, hdr_len);
	mgmt->frame_control = cpu_to_le16(IEEE80211_FTYPE_MGMT |
					  IEEE80211_STYPE_ACTION);

	cl_mac_addr_copy(mgmt->da, cl_sta->addr);
	cl_mac_addr_copy(mgmt->sa, cl_vif->vif->addr);
	cl_mac_addr_copy(mgmt->bssid, cl_sta->addr);
	mgmt->u.action.category = WLAN_CATEGORY_WNM;
	event_report = skb_put_zero(skb, sizeof(struct wnm_event_report_in_use));
	event_report->wnm_action = WMN_ACTION_EVENT_REPORT;
	event_report->dialog_token = 0; /* Autonomous report */
	event_report->elem_id = WLAN_EID_EVENT_REPORT;
	event_report->length = 3 + 1;
	event_report->event_token = 0;
	event_report->event_type = WMN_ACTION_EVENT_REPORT_TYPE_COLOR_IN_USE;
	event_report->event_report_status = 0; /* SUCCESSFUL */
	event_report->ap_color = ap_color;

	ieee80211_tx_prepare_skb(cl_hw->hw, cl_vif->vif, skb, cl_hw->nl_band, NULL);
	cl_tx_single(cl_hw, cl_sta, skb, false, true);
	cl_dbg_verbose(cl_hw, "Sent\n");
}

static void cl_bss_color_handle_ul_collision(struct cl_vif *cl_vif,
					     u8 collision_color)
{
	struct cl_hw *cl_hw = cl_vif->cl_hw;
	struct cl_sta *cl_sta;
	struct cfg80211_he_bss_color
		*he_bss_color = &cl_vif->vif->bss_conf.he_bss_color;

	/* Should not happen */
	if (he_bss_color->color != collision_color) {
		cl_dbg_err(cl_hw,
			   "color %d differ from collision color=%d - reenable\n",
			   he_bss_color->color, collision_color);
		cl_msg_tx_set_bss_color(cl_vif, he_bss_color);
		return;
	}

	/*
	 * UL collison can happen only in station mode, and the AP
	 * will be connected as index 0.
	 */
	cl_sta_lock(cl_hw);
	cl_sta = cl_sta_get(cl_hw, 0);
	cl_bss_color_send_collision_report(cl_vif, cl_sta, collision_color);
	cl_sta_unlock(cl_hw);
}

static void cl_bss_color_handle_dl_collision(struct cl_vif *cl_vif,
					     u64 color_mask)
{
	struct cl_hw *cl_hw = cl_vif->cl_hw;
	struct cfg80211_he_bss_color
		*he_bss_color = &cl_vif->vif->bss_conf.he_bss_color;

	/* Should not happen */
	if ((color_mask & BIT(he_bss_color->color)) == 0) {
		cl_dbg_err(cl_hw,
			   "color %d missing from color_mask=0x%llx - reenable\n",
			   he_bss_color->color, color_mask);
		cl_msg_tx_set_bss_color(cl_vif, he_bss_color);
		return;
	}
	cl_hw->bss_color_blacklist |= color_mask;
	ieeee80211_obss_color_collision_notify(cl_vif->vif, cl_hw->bss_color_blacklist);
}

void cl_bss_color_check_action(struct cl_vif *cl_vif,
			       struct ieee80211_mgmt *mgmt)
{
	struct wnm_event_report_collision *event_report =
		(struct wnm_event_report_collision *)(&mgmt->u.action.category + 1);

	if (cl_vif->vif->type != NL80211_IFTYPE_AP)
		return;

	if (event_report->wnm_action == WMN_ACTION_EVENT_REPORT &&
	    event_report->dialog_token == 0 &&
	    event_report->elem_id == WLAN_EID_EVENT_REPORT &&
	    event_report->event_type == WMN_ACTION_EVENT_REPORT_TYPE_COLOR_COLLISION)
		cl_bss_color_handle_dl_collision(cl_vif, event_report->color_mask);
}

void cl_bss_color_repeater_handle(struct cl_vif *cl_vif, struct cl_sta *cl_sta)
{
	struct cl_hw *cl_hw = cl_vif->cl_hw;
	struct cl_vif *cl_vif_ap, *tmp;
	u8 ap_color = 0;
	struct cfg80211_he_bss_color
		*he_bss_color = &cl_vif->vif->bss_conf.he_bss_color;

	if (cl_hw->conf->ce_wireless_mode <= WIRELESS_MODE_HT_VHT)
		return;

	if (!he_bss_color->enabled ||
	    he_bss_color->color == 0)
		return;

	cl_hw->bss_color_blacklist |= BIT(he_bss_color->color);
	list_for_each_entry_safe(cl_vif_ap, tmp, &cl_hw->vif_db.head, list) {
		if (cl_vif_ap->vif->type != NL80211_IFTYPE_AP)
			continue;
		ap_color = cl_vif_ap->vif->bss_conf.he_bss_color.color;
		if (he_bss_color->color == ap_color)
			ieeee80211_obss_color_collision_notify(cl_vif_ap->vif,
							       cl_hw->bss_color_blacklist);
	}

	cl_bss_color_send_color_in_use_report(cl_vif, cl_sta, ap_color);
}

void cl_bss_color_collision_indication(struct cl_hw *cl_hw,
				       struct mm_bss_color_collision_ind *ind)
{
	struct cl_vif *cl_vif, *tmp;
	u8 color = ind->bss_color;

	cl_dbg_verbose(cl_hw, "color=%d\n", color);

	list_for_each_entry_safe(cl_vif, tmp, &cl_hw->vif_db.head, list) {
		if (cl_vif->vif->type == NL80211_IFTYPE_AP &&
		    ind->direction == MM_BSS_COLOR_COLLISION_DIRECTION_DL)
			cl_bss_color_handle_dl_collision(cl_vif, BIT(color));
		else if (cl_vif->vif->type == NL80211_IFTYPE_STATION &&
			 ind->direction == MM_BSS_COLOR_COLLISION_DIRECTION_UL)
			cl_bss_color_handle_ul_collision(cl_vif, color);
	}
}

int cl_bss_color_cli(struct cl_hw *cl_hw, struct cl_vif *cl_vif, struct cli_params *cli_params)
{
	u32 expected_params = 0;
	bool print_conf = false;
	bool set_bl = false;
	bool send_color_in_use = false;
	bool send_collision_report = false;
	bool collision = false;

	switch (cli_params->option) {
	case 'a':
		print_conf = true;
		expected_params = 0;
		break;
	case 'b':
		set_bl = true;
		expected_params = 1;
		break;
	case 'c':
		send_color_in_use = true;
		expected_params = 2;
		break;
	case 'd':
		send_collision_report = true;
		expected_params = 2;
		break;
	case 'e':
		collision = true;
		expected_params = 2;
		break;
	case '?':
		return cl_bss_color_cli_help(cl_hw);
	default:
		cl_dbg_err(cl_hw, "Illegal option %c\n", cli_params->option);
		goto out_err;
	}

	if (expected_params != cli_params->num_params) {
		cl_dbg_err(cl_hw, "Wrong number of arguments (expected %u) (actual %u)\n",
			   expected_params, cli_params->num_params);
		goto out_err;
	}

	if (print_conf)
		return cl_bss_color_config_print(cl_vif);

	if (set_bl) {
		u8 color = (u8)cli_params->params[0];

		cl_hw->bss_color_blacklist |= BIT(color);
		return 0;
	}

	if (send_color_in_use) {
		u8 sta_idx = (u8)cli_params->params[0];
		u8 ap_color = (u8)cli_params->params[1];
		struct cl_sta *cl_sta;

		cl_sta_lock_bh(cl_hw);
		cl_sta = cl_sta_get(cl_hw, sta_idx);
		cl_bss_color_send_color_in_use_report(cl_vif, cl_sta,
						      ap_color);
		cl_sta_unlock_bh(cl_hw);

		return 0;
	}

	if (send_collision_report) {
		u8 sta_idx = (u8)cli_params->params[0];
		u8 color = (u8)cli_params->params[1];
		struct cl_sta *cl_sta;

		cl_sta_lock_bh(cl_hw);
		cl_sta = cl_sta_get(cl_hw, sta_idx);
		cl_bss_color_send_collision_report(cl_vif, cl_sta, color);
		cl_sta_unlock_bh(cl_hw);

		return 0;
	}

	if (collision) {
		struct mm_bss_color_collision_ind ind = {0};

		ind.bss_color = cli_params->params[0];
		ind.direction = cli_params->params[1];
		cl_bss_color_collision_indication(cl_hw, &ind);

		return 0;
	}

out_err:
	return -EIO;
}


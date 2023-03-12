// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_rssi.h"
#include "cl_vns.h"
#include "cl_rx_sens.h"
#include "cl_stats.h"
#include "cl_sta.h"
#include "cl_vw.h"
#include "cl_mac_addr.h"
#include "chip.h"

/*
 * cl_rssi_assoc_###()
 * -------------------
 * RSSI values of association packets (request in AP mode and respone in STA mode)
 * are not added to rssi pool sample, because at this stage station is not added
 * to driver database.
 * RSSI of association is important for WRS in order to select its initial rate.
 * The goal of this code is to save MAC address and RSSI values of all association
 * packets, and after station fully connects, search for the correct RSSI and add
 * it to the rssi pool sample.
 */
struct assoc_queue_elem {
	struct list_head list;
	u8 addr[ETH_ALEN];
	s8 rssi[MAX_ANTENNAS];
	unsigned long timestamp;
};

#define CL_RSSI_LIFETIME_MS 5000

static void cl_rssi_add_to_wrs(struct cl_hw *cl_hw, struct cl_sta *cl_sta, s8 rssi[MAX_ANTENNAS])
{
	struct cl_wrs_rssi *wrs_rssi = &cl_sta->wrs_rssi;
	int i = 0;

	for (i = 0; i < cl_hw->num_antennas; i++)
		wrs_rssi->sum[i] += rssi[i];

	wrs_rssi->cnt++;
}

void cl_rssi_assoc_init(struct cl_hw *cl_hw)
{
	INIT_LIST_HEAD(&cl_hw->assoc_queue.list);
	spin_lock_init(&cl_hw->assoc_queue.lock);
}

void cl_rssi_assoc_exit(struct cl_hw *cl_hw)
{
	/* Delete all remaining elements in list */
	spin_lock_bh(&cl_hw->assoc_queue.lock);

	if (!list_empty(&cl_hw->assoc_queue.list)) {
		struct assoc_queue_elem *elem = NULL;
		struct assoc_queue_elem *tmp = NULL;

		list_for_each_entry_safe(elem, tmp, &cl_hw->assoc_queue.list, list) {
			list_del(&elem->list);
			kfree(elem);
		}
	}

	spin_unlock_bh(&cl_hw->assoc_queue.lock);
}

void cl_rssi_assoc_handle(struct cl_hw *cl_hw, u8 *mac_addr, struct hw_rxhdr *rxhdr)
{
	/* Allocate new element and add to list */
	struct assoc_queue_elem *elem = kmalloc(sizeof(*elem), GFP_ATOMIC);

	if (elem) {
		INIT_LIST_HEAD(&elem->list);
		cl_mac_addr_copy(elem->addr, mac_addr);

		elem->rssi[0] = (s8)rxhdr->rssi1;
		elem->rssi[1] = (s8)rxhdr->rssi2;

		elem->timestamp = jiffies;

		spin_lock(&cl_hw->assoc_queue.lock);
		list_add(&elem->list, &cl_hw->assoc_queue.list);
		spin_unlock(&cl_hw->assoc_queue.lock);
	}
}

void cl_rssi_assoc_find(struct cl_hw *cl_hw, struct cl_sta *cl_sta, u8 num_sta)
{
	/* Search for rssi of association according to mac address */
	spin_lock_bh(&cl_hw->assoc_queue.lock);

	if (!list_empty(&cl_hw->assoc_queue.list)) {
		unsigned long lifetime = 0;
		struct assoc_queue_elem *elem = NULL;
		struct assoc_queue_elem *tmp = NULL;

		list_for_each_entry_safe(elem, tmp, &cl_hw->assoc_queue.list, list) {
			lifetime = jiffies_to_msecs(CL_TIME_DIFF(jiffies, elem->timestamp));

			/* Check lifetime of rssi before using it */
			if (lifetime > CL_RSSI_LIFETIME_MS) {
				/* Delete element from list */
				list_del(&elem->list);
				kfree(elem);
				continue;
			}

			if (ether_addr_equal(elem->addr, cl_sta->addr)) {
				struct hw_rxhdr rxhdr;
				s8 equivalent_rssi = cl_rssi_calc_equivalent(cl_hw, elem->rssi);

				rxhdr.rssi1 = elem->rssi[0];
				rxhdr.rssi2 = elem->rssi[1];

				cl_vw_sta_assoc(cl_hw, cl_sta, elem->rssi, num_sta);

				cl_rssi_raw_rx_handler(cl_hw, cl_sta, &rxhdr);
				cl_rssi_rx_handler(cl_hw, cl_sta, &rxhdr, equivalent_rssi);

				/* Delete element from list */
				list_del(&elem->list);
				kfree(elem);
			}
		}
	}

	spin_unlock_bh(&cl_hw->assoc_queue.lock);
}

void cl_rssi_sort_descending(s8 rssi[MAX_ANTENNAS], u8 num_ant)
{
	int i, j;

	for (i = 0; i < num_ant - 1; i++)
		for (j = 0; j < num_ant - i - 1; j++)
			if (rssi[j] < rssi[j + 1])
				swap(rssi[j], rssi[j + 1]);
}

static s8 cl_rssi_equivalent_2_phys(s8 rssi_max, s8 rssi_min)
{
	s8 rssi_diff = rssi_min - rssi_max;

	if (rssi_diff > (-2))
		return (rssi_max + 3);
	else if (rssi_diff > (-5))
		return (rssi_max + 2);
	else if (rssi_diff > (-9))
		return (rssi_max + 1);
	else
		return rssi_max;
}

s8 cl_rssi_calc_equivalent(struct cl_hw *cl_hw, s8 rssi[MAX_ANTENNAS])
{
	s8 rssi_tmp[MAX_ANTENNAS] = {0};
	u8 rx_ant = cl_hw->num_antennas;
	int i, j;

	/* Copy to rssi_tmp */
	memcpy(rssi_tmp, rssi, rx_ant);

	/* Sort the rssi's in desceding order */
	cl_rssi_sort_descending(rssi_tmp, rx_ant);

	/*
	 * 1) Calc equivalent rssi between the two lowest values.
	 * 2) Sort again
	 * 3) Repeat steps 1 and 2 according to number of antennas.
	 */
	for (i = 0; i < rx_ant - 1; i++) {
		rssi_tmp[rx_ant - i - 2] = cl_rssi_equivalent_2_phys(rssi_tmp[rx_ant - i - 2],
								     rssi_tmp[rx_ant - i - 1]);

		for (j = rx_ant - i - 2; j > 0; j--) {
			if (rssi_tmp[j] > rssi_tmp[j - 1])
				swap(rssi_tmp[j], rssi_tmp[j - 1]);
			else
				break;
		}
	}

	return rssi_tmp[0];
}

s8 cl_rssi_get_strongest(struct cl_hw *cl_hw, s8 rssi[MAX_ANTENNAS])
{
	int i;
	s8 strongest_rssi = S8_MIN;

	for (i = 0; i < cl_hw->num_antennas; i++) {
		if (rssi[i] > strongest_rssi)
			strongest_rssi = rssi[i];
	}

	return strongest_rssi;
}

static void cl_update_sta_rssi(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
			       s8 rssi[MAX_ANTENNAS], s8 equivalent_rssi)
{
	/* Last RSSI */
	memcpy(cl_sta->last_rssi, rssi, cl_hw->num_antennas);

	if (cl_sta->manual_alpha_rssi)
		return;

	/* Alpha RSSI - use alpha filter (87.5% current + 12.5% new) */
	if (cl_sta->alpha_rssi)
		cl_sta->alpha_rssi =
			((cl_sta->alpha_rssi << 3) - cl_sta->alpha_rssi + equivalent_rssi) >> 3;
	else
		cl_sta->alpha_rssi = equivalent_rssi;
}

void cl_rssi_block_ack_handler(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
			       struct cl_agg_tx_report *agg_report)
{
	/* Handle RSSI of block-ack's */
	union cl_rate_ctrl_info rate_ctrl_info = {
			.word = le32_to_cpu(agg_report->rate_cntrl_info)};

	u8 bw = rate_ctrl_info.field.bw;
	s8 rssi[MAX_ANTENNAS] = {
		(s8)agg_report->rssi1,
		(s8)agg_report->rssi2,
	};
	s8 equivalent_rssi;
	int i;

	if (cl_hw->rssi_simulate)
		for (i = 0; i < cl_hw->num_antennas; i++)
			rssi[i] = cl_hw->rssi_simulate;

	/*
	 * RX-SENS should be based on raw 20MHz RSSI.
	 * It must be done before adjusting RSSI according to BW.
	 */
	cl_rx_sens_handle_rssi(cl_hw, cl_sta, rssi);

	if (!cl_hw->rssi_simulate) {
		s8 bw_factor = 0;

		/*
		 * RSSI adjustment according to BW
		 * The BA is transmitted in the BW of the aggregation it acknowledges
		 */
		if (bw == CHNL_BW_160)
			bw_factor = 9;
		else if (bw == CHNL_BW_80)
			bw_factor = 6;
		else if (bw == CHNL_BW_40)
			bw_factor = 3;

		for (i = 0; i < cl_hw->num_antennas; i++)
			rssi[i] += bw_factor;
	}

	equivalent_rssi = cl_rssi_calc_equivalent(cl_hw, rssi);

	/* Handle RSSI after BW adjustment */
	cl_rssi_add_to_wrs(cl_hw, cl_sta, rssi);
	cl_stats_update_rx_rssi(cl_hw, cl_sta, rssi);
	cl_vns_handle_rssi(cl_hw, cl_sta, rssi);
	cl_update_sta_rssi(cl_hw, cl_sta, rssi, equivalent_rssi);
}

void cl_rssi_raw_rx_handler(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
			    struct hw_rxhdr *rxhdr)
{
	/* Called before BW adjustment */
	s8 rssi[MAX_ANTENNAS] = RX_HDR_RSSI(rxhdr);

	/* RX-SENS should be based on raw 20MHz RSSI */
	cl_rx_sens_handle_rssi(cl_hw, cl_sta, rssi);
}

void cl_rssi_rx_handler(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
			struct hw_rxhdr *rxhdr, s8 equivalent_rssi)
{
	/* Called after BW adjustment */
	s8 rssi[MAX_ANTENNAS] = RX_HDR_RSSI(rxhdr);

	if (!IS_REAL_PHY(cl_hw->chip) && rssi[0] == 0)
		return;

	cl_rssi_add_to_wrs(cl_hw, cl_sta, rssi);
	cl_stats_update_rx_rssi(cl_hw, cl_sta, rssi);
	cl_vns_handle_rssi(cl_hw, cl_sta, rssi);
	cl_update_sta_rssi(cl_hw, cl_sta, rssi, equivalent_rssi);
}

void cl_rssi_bw_adjust(struct cl_hw *cl_hw, struct hw_rxhdr *rxhdr, s8 bw_factor)
{
	if (cl_hw->rssi_simulate)
		return;

	rxhdr->rssi1 += bw_factor;
	rxhdr->rssi2 += bw_factor;
}

void cl_rssi_simulate(struct cl_hw *cl_hw, struct hw_rxhdr *rxhdr)
{
	rxhdr->rssi1 = cl_hw->rssi_simulate;
	rxhdr->rssi2 = cl_hw->rssi_simulate;
}

static int cl_rssi_alpha_set_manual(struct cl_hw *cl_hw, u8 sta_idx, s8 rssi)
{
	struct cl_sta *cl_sta;

	if (rssi > 0) {
		pr_err("Invalid rssi %d\n", rssi);
		return -1;
	}

	cl_sta_lock_bh(cl_hw);
	cl_sta = cl_sta_get(cl_hw, sta_idx);

	if (!cl_sta) {
		pr_err("Invalid sta idx %u\n", sta_idx);
		cl_sta_unlock_bh(cl_hw);
		return -1;
	}

	if (rssi == 0) {
		cl_sta->manual_alpha_rssi = false;
		cl_sta->alpha_rssi = cl_rssi_calc_equivalent(cl_hw, cl_sta->last_rssi);
	} else {
		cl_sta->manual_alpha_rssi = true;
		cl_sta->alpha_rssi = rssi;
	}

	cl_sta_unlock_bh(cl_hw);

	return 0;
}

static int cl_rssi_cli_help(struct cl_hw *cl_hw)
{
	char *buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!buf)
		return -ENOMEM;

	snprintf(buf, PAGE_SIZE,
		 "rssi usage:\n"
		 "-m : Set manual alpha rssi [sta_idx].[RSSI (0 to disable)]\n"
		 "-s : Simulate RX hdr rssi [RSSI (0 to disable)]\n");

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

int cl_rssi_cli(struct cl_hw *cl_hw, struct cli_params *cli_params)
{
	bool manual_alpha_rssi = false;
	bool rssi_simulate = false;
	int expected_params = -1;

	switch (cli_params->option) {
	case 'm':
		manual_alpha_rssi = true;
		expected_params = 2;
		break;
	case 's':
		rssi_simulate = true;
		expected_params = 1;
		break;
	case '?':
		return cl_rssi_cli_help(cl_hw);
	default:
		cl_dbg_err(cl_hw, "Illegal option (%c) - try '?' for help\n", cli_params->option);
		goto out_err;
	}

	if (expected_params != cli_params->num_params) {
		cl_dbg_err(cl_hw, "Wrong number of arguments (expected %u) (actual %u)\n",
			   expected_params, cli_params->num_params);
		goto out_err;
	}

	if (manual_alpha_rssi) {
		u8 sta_idx = (u8)cli_params->params[0];
		s8 rssi = (s8)cli_params->params[1];

		return cl_rssi_alpha_set_manual(cl_hw, sta_idx, rssi);
	}

	if (rssi_simulate) {
		cl_hw->rssi_simulate = (s8)cli_params->params[0];
		pr_debug("rssi_simulate = %d\n", cl_hw->rssi_simulate);
		return 0;
	}

out_err:
	return -EIO;
}

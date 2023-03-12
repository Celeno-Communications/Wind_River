// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include <linux/string.h>
#include "cl_stats.h"
#include "cl_rx.h"
#include "cl_sta.h"
#include "cl_band.h"
#include "cl_mib.h"
#include "cl_rate_ctrl.h"
#include "cl_vif.h"
#include "cl_data_rates.h"

typedef void (*stats_callback)(struct cl_hw *, struct cl_sta *);

static const char *bw_str[CHNL_BW_MAX] = {
	[CHNL_BW_20] = "20",
	[CHNL_BW_40] = "40",
	[CHNL_BW_80] = "80",
	[CHNL_BW_160] = "160"
};

static const char *gi_he_str[WRS_GI_MAX_HE] = {
	[WRS_GI_LONG] = "3.2",
	[WRS_GI_SHORT] = "1.6",
	[WRS_GI_VSHORT] = "0.8"
};

static const char *gi_ht_vht_str[WRS_GI_MAX_HT] = {
	[WRS_GI_LONG] = "0.8",
	[WRS_GI_SHORT] = "0.4",
};

static void cl_stats_sta_reset(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	struct cl_ps_stats *ps = &cl_sta->stats->ps;
	bool is_ps = ps->is_ps;
	unsigned long timestamp_sleep = ps->timestamp_sleep;

	memset(cl_sta->stats, 0, sizeof(struct cl_stats));

	/* Restore value of power-save state and timestamp */
	ps->is_ps = is_ps;
	ps->timestamp_sleep = timestamp_sleep;
}

static void cl_stats_print_per(struct cl_hw *cl_hw, u32 delay)
{
	u32 system_per = 0, air_per = 0, ampdu_all,
		old_phy_error, old_fcs_error, old_overflow, old_complete,
		old_ampdu_failed, old_real_fcs, old_ampdu_success,
		new_phy_error, new_fcs_error, new_overflow, new_complete,
		new_ampdu_failed, new_real_fcs, new_ampdu_success;

	old_phy_error = cl_mib_cntr_read(cl_hw, MIB_DOT11_RX_PHY_ERROR_COUNT);
	old_fcs_error = cl_mib_cntr_read(cl_hw, MIB_DOT11_FCS_ERROR_COUNT);
	old_overflow = cl_mib_cntr_read(cl_hw, MIB_DOT11_RX_FIFO_OVERFLOW_COUNT);
	old_complete = cl_mib_cntr_read(cl_hw, MIB_RW_QOS_U_RECEIVED_MPDU_COUNT0) +
		       cl_mib_cntr_read(cl_hw, MIB_RW_QOS_U_RECEIVED_MPDU_COUNT1) +
		       cl_mib_cntr_read(cl_hw, MIB_RW_QOS_U_RECEIVED_MPDU_COUNT2) +
		       cl_mib_cntr_read(cl_hw, MIB_RW_QOS_U_RECEIVED_MPDU_COUNT3) +
		       cl_mib_cntr_read(cl_hw, MIB_RW_QOS_U_RECEIVED_MPDU_COUNT4) +
		       cl_mib_cntr_read(cl_hw, MIB_RW_QOS_U_RECEIVED_MPDU_COUNT5) +
		       cl_mib_cntr_read(cl_hw, MIB_RW_QOS_U_RECEIVED_MPDU_COUNT6) +
		       cl_mib_cntr_read(cl_hw, MIB_RW_QOS_U_RECEIVED_MPDU_COUNT7);
	old_ampdu_failed = cl_mib_cntr_read(cl_hw, MIB_AMPDU_INCORRECT_RCVED_COUNT);
	old_ampdu_success = cl_mib_cntr_read(cl_hw, MIB_RW_U_AMPDU_RECEIVED_COUNT);
	old_real_fcs = old_fcs_error - old_overflow;

	mdelay(delay);

	new_phy_error = cl_mib_cntr_read(cl_hw, MIB_DOT11_RX_PHY_ERROR_COUNT);
	new_fcs_error = cl_mib_cntr_read(cl_hw, MIB_DOT11_FCS_ERROR_COUNT);
	new_overflow = cl_mib_cntr_read(cl_hw, MIB_DOT11_RX_FIFO_OVERFLOW_COUNT);
	new_complete = cl_mib_cntr_read(cl_hw, MIB_RW_QOS_U_RECEIVED_MPDU_COUNT0) +
		cl_mib_cntr_read(cl_hw, MIB_RW_QOS_U_RECEIVED_MPDU_COUNT1) +
		cl_mib_cntr_read(cl_hw, MIB_RW_QOS_U_RECEIVED_MPDU_COUNT2) +
		cl_mib_cntr_read(cl_hw, MIB_RW_QOS_U_RECEIVED_MPDU_COUNT3) +
		cl_mib_cntr_read(cl_hw, MIB_RW_QOS_U_RECEIVED_MPDU_COUNT4) +
		cl_mib_cntr_read(cl_hw, MIB_RW_QOS_U_RECEIVED_MPDU_COUNT5) +
		cl_mib_cntr_read(cl_hw, MIB_RW_QOS_U_RECEIVED_MPDU_COUNT6) +
		cl_mib_cntr_read(cl_hw, MIB_RW_QOS_U_RECEIVED_MPDU_COUNT7);
	new_ampdu_failed = cl_mib_cntr_read(cl_hw, MIB_AMPDU_INCORRECT_RCVED_COUNT);
	new_ampdu_success = cl_mib_cntr_read(cl_hw, MIB_RW_U_AMPDU_RECEIVED_COUNT);
	new_real_fcs = new_fcs_error - new_overflow;

	/* Overflow handling */
	if (old_complete > new_complete ||
	    old_overflow > new_overflow ||
	    old_fcs_error > new_fcs_error ||
	    old_phy_error > new_phy_error ||
	    old_ampdu_failed > new_ampdu_failed)
		return;

	ampdu_all = (new_ampdu_failed - old_ampdu_failed) +
		(new_ampdu_success - old_ampdu_success);

	if (new_complete - old_complete) {
		system_per = ((new_overflow - old_overflow) * 100 /
			      (new_complete - old_complete));
	} else {
		pr_debug("No successfully received packets\n");
		return;
	}

	if ((new_fcs_error + new_phy_error + new_complete) -
	    (old_fcs_error + old_phy_error + old_complete))
		air_per = (new_real_fcs - old_real_fcs) * 100 /
		((new_real_fcs + new_complete) - (old_real_fcs + old_complete));

	pr_debug("Air PER = [%u%%]\n"
		 "System PER = [%u%%]\n"
		 "Successfully received Packets = [%u]\n"
		 "Number of Phy errors received: [%u]\n"
		 "Aggregation failure ratio: [%u/%u]\n",
		 air_per, system_per, new_complete - old_complete,
		 new_phy_error - old_phy_error,
		 new_ampdu_failed - old_ampdu_failed, ampdu_all);
}

static void cl_stats_print_rssi(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	struct cl_stats *stats = cl_sta->stats;
	u32 i = 0, j = 0;
	u64 avg_rssi[MAX_ANTENNAS] = {0};
	u64 sum_rssi[MAX_ANTENNAS] = {0};
	u64 total_rssi = 0;
	char buf[STR_LEN_128B];
	int len = 0;

	snprintf(buf, sizeof(buf), "STA #%u, MAC %pM\n", cl_sta->sta_idx, cl_sta->addr);
	pr_debug("%s", buf);

	len = snprintf(buf, sizeof(buf), "|----");
	for (j = 0; j < cl_hw->num_antennas; j++)
		len += snprintf(buf + len, sizeof(buf) - len, "-----------");
	len += snprintf(buf + len, sizeof(buf) - len, "|\n");
	pr_debug("%s", buf);

	len = snprintf(buf, sizeof(buf), "|RSSI");
	for (j = 0; j < cl_hw->num_antennas; j++)
		len += snprintf(buf + len, sizeof(buf) - len, "|   Ant%u   ", j + 1);
	len += snprintf(buf + len, sizeof(buf) - len, "|\n");
	pr_debug("%s", buf);

	len = snprintf(buf, sizeof(buf), "|----");
	for (j = 0; j < cl_hw->num_antennas; j++)
		len += snprintf(buf + len, sizeof(buf) - len, "+----------");
	len += snprintf(buf + len, sizeof(buf) - len, "|\n");
	pr_debug("%s", buf);

	for (i = 0; i < RSSI_ARR_SIZE; i++) {
		total_rssi = 0;

		for (j = 0; j < cl_hw->num_antennas; j++) {
			total_rssi += stats->rssi[i][j];
			sum_rssi[j] += stats->rssi[i][j];
			avg_rssi[j] += (i * stats->rssi[i][j]);
		}

		/* Does not print rssi entries with 0 packets */
		if (total_rssi == 0)
			continue;

		len = snprintf(buf, sizeof(buf), "|%3d ", -i);
		for (j = 0; j < cl_hw->num_antennas; j++)
			len += snprintf(buf + len, sizeof(buf) - len,
					"|%10u", stats->rssi[i][j]);
		len += snprintf(buf + len, sizeof(buf) - len, "|\n");
		pr_debug("%s", buf);
	}

	total_rssi = 0;

	for (j = 0; j < cl_hw->num_antennas; j++) {
		if (sum_rssi[j] == 0)
			return;

		avg_rssi[j] = div64_u64(avg_rssi[j], sum_rssi[j]);
	}

	len = snprintf(buf, sizeof(buf), "|----");
	for (j = 0; j < cl_hw->num_antennas; j++)
		len += snprintf(buf + len, sizeof(buf) - len, "+----------");
	len += snprintf(buf + len, sizeof(buf) - len, "|\n");
	pr_debug("%s", buf);

	len = snprintf(buf, sizeof(buf), "|AVG ");
	for (j = 0; j < cl_hw->num_antennas; j++)
		len += snprintf(buf + len, sizeof(buf) - len, "|%10lld", -avg_rssi[j]);
	len += snprintf(buf + len, sizeof(buf) - len, "|\n");
	pr_debug("%s", buf);

	len = snprintf(buf, sizeof(buf), "|----");
	for (j = 0; j < cl_hw->num_antennas; j++)
		len += snprintf(buf + len, sizeof(buf) - len, "-----------");
	len += snprintf(buf + len, sizeof(buf) - len, "|\n");
	pr_debug("%s", buf);
}

static void cl_stats_print_fec_coding(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	struct cl_stats *stats = cl_sta->stats;

	pr_debug("\nSTA #%u, MAC %pM\n", cl_sta->sta_idx, cl_sta->addr);
	pr_debug("BCC  = %u\n", stats->fec_coding[CL_FEC_CODING_BCC]);
	pr_debug("LDPC = %u\n", stats->fec_coding[CL_FEC_CODING_LDPC]);
}

static void cl_stats_print_power_save(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	struct cl_ps_stats *ps_stats = &cl_sta->stats->ps;

	pr_debug("\n");
	pr_debug("STA #%u, MAC %pM\n", cl_sta->sta_idx, cl_sta->addr);
	pr_debug("Current state = %s\n", ps_stats->is_ps ? "SLEEP" : "AWAKE");
	pr_debug("|-------------------------|\n");
	pr_debug("| Period     | Counter    |\n");
	pr_debug("|-------------------------|\n");
	pr_debug("| <= 50ms    | %10u |\n", ps_stats->period[PS_PERIOD_50MS]);
	pr_debug("| <= 100ms   | %10u |\n", ps_stats->period[PS_PERIOD_100MS]);
	pr_debug("| <= 250ms   | %10u |\n", ps_stats->period[PS_PERIOD_250MS]);
	pr_debug("| <= 500ms   | %10u |\n", ps_stats->period[PS_PERIOD_500MS]);
	pr_debug("| <= 750ms   | %10u |\n", ps_stats->period[PS_PERIOD_750MS]);
	pr_debug("| <= 1000ms  | %10u |\n", ps_stats->period[PS_PERIOD_1000MS]);
	pr_debug("| <= 2000ms  | %10u |\n", ps_stats->period[PS_PERIOD_2000MS]);
	pr_debug("| <= 5000ms  | %10u |\n", ps_stats->period[PS_PERIOD_5000MS]);
	pr_debug("| <= 10000ms | %10u |\n", ps_stats->period[PS_PERIOD_10000MS]);
	pr_debug("|  > 10000ms | %10u |\n", ps_stats->period[PS_PERIOD_ABOVE]);
	pr_debug("|-------------------------|\n");
}

static void _cl_stats_print_tx(struct cl_tx_cntrs *cntrs,
			       const char *mode_str, const char *bw_str, const char *gi_str,
			       u8 nss, u8 mcs, u8 bf,
			       u64 *total_success, u64 *total_fail)
{
	u8 per = 0;

	if (cntrs->fail == 0 && cntrs->success == 0)
		return;

	per = (u8)div64_u64(100 * (u64)cntrs->fail, cntrs->fail + cntrs->success);

	pr_debug("|%-8s|%-3s|%2u|%3u|%3s|%2u|%10u|%10u|%3u|\n",
		 mode_str, bw_str, nss, mcs, gi_str, bf, cntrs->success, cntrs->fail, per);

	*total_success += cntrs->success;
	*total_fail += cntrs->fail;
}

static void cl_stats_print_tx_he(struct cl_stats *stats, u64 *total_success, u64 *total_fail)
{
	struct cl_tx_cntrs *cntrs;
	u8 bw = 0, nss = 0, mcs = 0, gi = 0, bf = 0;

	for (bw = 0; bw < CHNL_BW_MAX; bw++)
		for (nss = 0; nss < WRS_SS_MAX; nss++)
			for (mcs = 0; mcs < WRS_MCS_MAX; mcs++)
				for (gi = 0; gi < WRS_GI_MAX; gi++)
					for (bf = 0; bf < BF_IDX_MAX; bf++) {
						cntrs = &stats->tx.he[bw][nss][mcs][gi][bf];
						_cl_stats_print_tx(cntrs,
								   "HE",
								   bw_str[bw], gi_he_str[gi],
								   nss, mcs, bf,
								   total_success, total_fail);
					}
}

static void cl_stats_print_tx_vht(struct cl_stats *stats, u64 *total_success, u64 *total_fail)
{
	struct cl_tx_cntrs *cntrs;
	u8 bw = 0, nss = 0, mcs = 0, gi = 0, bf = 0;

	for (bw = 0; bw < CHNL_BW_MAX_VHT; bw++)
		for (nss = 0; nss < WRS_SS_MAX; nss++)
			for (mcs = 0; mcs < WRS_MCS_MAX_VHT; mcs++)
				for (gi = 0; gi < WRS_GI_MAX_VHT; gi++)
					for (bf = 0; bf < BF_IDX_MAX; bf++) {
						cntrs = &stats->tx.vht[bw][nss][mcs][gi][bf];
						_cl_stats_print_tx(cntrs,
								   "VHT",
								   bw_str[bw], gi_ht_vht_str[gi],
								   nss, mcs, bf,
								   total_success, total_fail);
					}
}

static void cl_stats_print_tx_ht(struct cl_stats *stats, u64 *total_success, u64 *total_fail)
{
	struct cl_tx_cntrs *cntrs;
	u8 bw = 0, nss = 0, mcs = 0, gi = 0;

	for (bw = 0; bw < CHNL_BW_MAX_HT; bw++)
		for (nss = 0; nss < WRS_SS_MAX; nss++)
			for (mcs = 0; mcs < WRS_MCS_MAX_HT; mcs++)
				for (gi = 0; gi < WRS_GI_MAX_HT; gi++) {
					cntrs = &stats->tx.ht[bw][nss][mcs][gi];
					_cl_stats_print_tx(cntrs,
							   "HT",
							   bw_str[bw], gi_ht_vht_str[gi],
							   nss, mcs, 0,
							   total_success, total_fail);
				}
}

static void cl_stats_print_tx_ofdm(struct cl_stats *stats, u64 *total_success, u64 *total_fail)
{
	struct cl_tx_cntrs *cntrs;
	u8 mcs;

	for (mcs = 0; mcs < WRS_MCS_MAX_OFDM; mcs++) {
		cntrs = &stats->tx.ofdm[mcs];
		_cl_stats_print_tx(cntrs,
				   "OFDM", bw_str[0], "0",
				   0, mcs, 0,
				   total_success, total_fail);
	}
}

static void cl_stats_print_tx_cck(struct cl_stats *stats, u64 *total_success, u64 *total_fail)
{
	struct cl_tx_cntrs *cntrs;
	u8 mcs;

	for (mcs = 0; mcs < WRS_MCS_MAX_CCK; mcs++) {
		cntrs = &stats->tx.cck[mcs];
		_cl_stats_print_tx(cntrs,
				   "CCK", bw_str[0], "0",
				   0, mcs, 0,
				   total_success, total_fail);
	}
}

static void cl_stats_print_tx(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	struct cl_stats *stats = cl_sta->stats;
	u64 total_success = 0, total_fail = 0;

	pr_debug("\nSTA #%u, MAC %pM\n", cl_sta->sta_idx, cl_sta->addr);
	pr_debug("------------------------------------------------------\n");
	pr_debug("|MODE    |BW |SS|MCS|GI |BF| Success  |   Fail   |PER|\n");
	pr_debug("|--------+---+--+---+---+--+----------+----------+---|\n");

	cl_stats_print_tx_he(stats, &total_success, &total_fail);
	cl_stats_print_tx_vht(stats, &total_success, &total_fail);
	cl_stats_print_tx_ht(stats, &total_success, &total_fail);
	cl_stats_print_tx_ofdm(stats, &total_success, &total_fail);
	cl_stats_print_tx_cck(stats, &total_success, &total_fail);

	pr_debug("------------------------------------------------------\n");
	pr_debug("                           |%10llu|%10llu|\n", total_success, total_fail);
	pr_debug("                           -----------------------\n");
	pr_debug("\n");
}

static void _cl_stats_print_rx(struct cl_rx_stats *rx_stats)
{
	u8 mode = 0, mcs = 0, nss = 0, bw = 0, gi = 0, flag = rx_stats->flag;
	u16 data_rate = 0, data_rate_div_10 = 0, data_rate_mod_10 = 0;
	u64 remainder = 0, packets = 0, total_packets[WRS_MODE_MAX] = {0},
		total_data_rate[WRS_MODE_MAX] = {0}, equivalent_data_rate = 0;

	pr_debug("-------------------------------------------------------\n");
	pr_debug("|  MODE   | BW | SS | MCS | GI | Data-Rate | #Packets |\n");
	pr_debug("|---------+----+----+-----+----+-----------+----------|\n");

	if ((flag & RX_STATS_HE_TRIG) == 0)
		goto stats_he_ext;

	for (bw = 0; bw < CHNL_BW_MAX_HE; bw++) {
		for (nss = 0; nss < WRS_SS_MAX; nss++) {
			for (mcs = 0; mcs < WRS_MCS_MAX_HE; mcs++) {
				for (gi = 0; gi < WRS_GI_MAX_HE; gi++) {
					packets = rx_stats->he_trig[bw][nss][mcs][gi];

					if (packets == 0)
						continue;

					data_rate = cl_data_rates_get_x10(WRS_MODE_HE, bw,
									  nss, mcs, gi);
					data_rate_div_10 = data_rate / 10;
					data_rate_mod_10 = data_rate % 10;

					total_packets[WRS_MODE_HE] += packets;
					total_data_rate[WRS_MODE_HE] += (packets * data_rate);

					pr_debug("| HE_TRIG |%4u|%4u|%5u|%4s| %7u.%u |%10llu|\n",
						 BW_TO_MHZ(bw), nss, mcs, gi_he_str[gi],
						 data_rate_div_10, data_rate_mod_10, packets);
				}
			}
		}
	}

stats_he_ext:
	if ((flag & RX_STATS_HE_EXT) == 0)
		goto stats_he_mu;

	for (bw = 0; bw < CHNL_BW_MAX_HE; bw++) {
		for (nss = 0; nss < WRS_SS_MAX; nss++) {
			for (mcs = 0; mcs < WRS_MCS_MAX_HE; mcs++) {
				for (gi = 0; gi < WRS_GI_MAX_HE; gi++) {
					packets = rx_stats->he_ext[bw][nss][mcs][gi];

					if (packets == 0)
						continue;

					data_rate = cl_data_rates_get_x10(WRS_MODE_HE, bw,
									  nss, mcs, gi);
					data_rate_div_10 = data_rate / 10;
					data_rate_mod_10 = data_rate % 10;

					total_packets[WRS_MODE_HE] += packets;
					total_data_rate[WRS_MODE_HE] += (packets * data_rate);

					pr_debug("| HE_EXT  |%4u|%4u|%5u|%4s| %7u.%u |%10llu|\n",
						 BW_TO_MHZ(bw), nss, mcs, gi_he_str[gi],
						 data_rate_div_10, data_rate_mod_10, packets);
				}
			}
		}
	}

stats_he_mu:
	if ((flag & RX_STATS_HE_MU) == 0)
		goto stats_he_su;

	for (bw = 0; bw < CHNL_BW_MAX_HE; bw++) {
		for (nss = 0; nss < WRS_SS_MAX; nss++) {
			for (mcs = 0; mcs < WRS_MCS_MAX_HE; mcs++) {
				for (gi = 0; gi < WRS_GI_MAX_HE; gi++) {
					packets = rx_stats->he_mu[bw][nss][mcs][gi];

					if (packets == 0)
						continue;

					data_rate = cl_data_rates_get_x10(WRS_MODE_HE, bw,
									  nss, mcs, gi);
					data_rate_div_10 = data_rate / 10;
					data_rate_mod_10 = data_rate % 10;

					total_packets[WRS_MODE_HE] += packets;
					total_data_rate[WRS_MODE_HE] += (packets * data_rate);

					pr_debug("| HE_MU   |%4u|%4u|%5u|%4s| %7u.%u |%10llu|\n",
						 BW_TO_MHZ(bw), nss, mcs, gi_he_str[gi],
						 data_rate_div_10, data_rate_mod_10, packets);
				}
			}
		}
	}

stats_he_su:
	if ((flag & RX_STATS_HE_SU) == 0)
		goto stats_vht;

	for (bw = 0; bw < CHNL_BW_MAX_HE; bw++) {
		for (nss = 0; nss < WRS_SS_MAX; nss++) {
			for (mcs = 0; mcs < WRS_MCS_MAX_HE; mcs++) {
				for (gi = 0; gi < WRS_GI_MAX_HE; gi++) {
					packets = rx_stats->he_su[bw][nss][mcs][gi];

					if (packets == 0)
						continue;

					data_rate = cl_data_rates_get_x10(WRS_MODE_HE, bw,
									  nss, mcs, gi);
					data_rate_div_10 = data_rate / 10;
					data_rate_mod_10 = data_rate % 10;

					total_packets[WRS_MODE_HE] += packets;
					total_data_rate[WRS_MODE_HE] += (packets * data_rate);

					pr_debug("| HE_SU   |%4u|%4u|%5u|%4s| %7u.%u |%10llu|\n",
						 BW_TO_MHZ(bw), nss, mcs, gi_he_str[gi],
						 data_rate_div_10, data_rate_mod_10, packets);
				}
			}
		}
	}

stats_vht:
	if ((flag & RX_STATS_VHT) == 0)
		goto stats_ht;

	for (bw = 0; bw < CHNL_BW_MAX_VHT; bw++) {
		for (nss = 0; nss < WRS_SS_MAX; nss++) {
			for (mcs = 0; mcs < WRS_MCS_MAX_VHT; mcs++) {
				for (gi = 0; gi < WRS_GI_MAX_VHT; gi++) {
					packets = rx_stats->vht[bw][nss][mcs][gi];

					if (packets == 0)
						continue;

					data_rate = cl_data_rates_get_x10(WRS_MODE_VHT,
									  bw, nss, mcs, gi);
					data_rate_div_10 = data_rate / 10;
					data_rate_mod_10 = data_rate % 10;

					total_packets[WRS_MODE_VHT] += packets;
					total_data_rate[WRS_MODE_VHT] += (packets * data_rate);

					pr_debug("| VHT     |%4u|%4u|%5u|%4s| %7u.%u |%10llu|\n",
						 BW_TO_MHZ(bw), nss, mcs, gi_ht_vht_str[gi],
						 data_rate_div_10, data_rate_mod_10, packets);
				}
			}
		}
	}

stats_ht:
	if ((flag & RX_STATS_HT) == 0)
		goto stats_ofdm;

	for (bw = 0; bw < CHNL_BW_MAX_HT; bw++) {
		for (nss = 0; nss < WRS_SS_MAX; nss++) {
			for (mcs = 0; mcs < WRS_MCS_MAX_HT; mcs++) {
				for (gi = 0; gi < WRS_GI_MAX_HT; gi++) {
					packets = rx_stats->ht[bw][nss][mcs][gi];

					if (packets == 0)
						continue;

					data_rate = cl_data_rates_get_x10(WRS_MODE_HT,
									  bw, nss, mcs, gi);
					data_rate_div_10 = data_rate / 10;
					data_rate_mod_10 = data_rate % 10;

					total_packets[WRS_MODE_HT] += packets;
					total_data_rate[WRS_MODE_HT] += (packets * data_rate);

					pr_debug("| HT      |%4u|%4u|%5u|%4s| %7u.%u |%10llu|\n",
						 BW_TO_MHZ(bw), nss, mcs, gi_ht_vht_str[gi],
						 data_rate_div_10, data_rate_mod_10, packets);
				}
			}
		}
	}

stats_ofdm:
	if ((flag & RX_STATS_OFDM) == 0)
		goto stats_cck;

	for (mcs = 0; mcs < WRS_MCS_MAX_OFDM; mcs++) {
		packets = rx_stats->ofdm[mcs];

		if (packets == 0)
			continue;

		data_rate = cl_data_rates_get_x10(WRS_MODE_OFDM, 0, 0, mcs, 0);
		data_rate_div_10 = data_rate / 10;
		data_rate_mod_10 = data_rate % 10;

		total_packets[WRS_MODE_OFDM] += packets;
		total_data_rate[WRS_MODE_OFDM] += (packets * data_rate);

		pr_debug("| OFDM    |  20|   0|%5u|   0| %7u.%u |%10llu|\n",
			 mcs, data_rate_div_10, data_rate_mod_10, packets);
	}

stats_cck:
	if ((flag & RX_STATS_CCK) == 0)
		goto stats_end;

	for (mcs = 0; mcs < WRS_MCS_MAX_CCK; mcs++) {
		packets = rx_stats->cck[mcs];

		if (packets == 0)
			continue;

		data_rate = cl_data_rates_get_x10(WRS_MODE_CCK, 0, 0, mcs, 0);
		data_rate_div_10 = data_rate / 10;
		data_rate_mod_10 = data_rate % 10;

		total_packets[WRS_MODE_CCK] += packets;
		total_data_rate[WRS_MODE_CCK] += (packets * data_rate);

		pr_debug("| CCK     |  20|   0|%5u|   0| %7u.%u |%10llu|\n",
			 mcs, data_rate_div_10, data_rate_mod_10, packets);
	}

stats_end:
	pr_debug("-------------------------------------------------------\n");

	for (mode = 0; mode < WRS_MODE_MAX; mode++) {
		if (total_packets[mode] == 0)
			continue;

		equivalent_data_rate = div64_u64(total_data_rate[mode], total_packets[mode]);
		data_rate_div_10 = (u16)div64_u64_rem(equivalent_data_rate, 10, &remainder);

		pr_debug("%s: Equivalent data rate = %u.%u Mbps\n\n",
			 WRS_MODE_STR(mode), data_rate_div_10, (u16)remainder);
	}
}

static void cl_stats_print_rx(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	if (cl_hw->chip->conf->ce_production_mode) {
		_cl_stats_print_rx(cl_hw->rx_stats);
	} else {
		pr_debug("\nSTA #%u, MAC %pM\n", cl_sta->sta_idx, cl_sta->addr);
		_cl_stats_print_rx(&cl_sta->stats->rx);
	}
}

static void cl_stats_print_cpu(struct cl_hw *cl_hw)
{
	u32 cpu = 0;

	pr_debug("|-------------------------|\n");
	pr_debug("|CPU|Tx Agg    |Tx Single |\n");
	pr_debug("|---+----------+----------|\n");

	for (cpu = 0; cpu < CPU_MAX_NUM; cpu++)
		pr_debug("| %u |%10u|%10u|\n",
			 cpu,
			 cl_hw->cpu_cntr.tx_agg[cpu],
			 cl_hw->cpu_cntr.tx_single[cpu]);

	pr_debug("|-------------------------|\n");
}

static void cl_sta_print_do(struct cl_hw *cl_hw, u8 sta_idx, stats_callback callback)
{
	struct cl_sta *cl_sta;

	cl_sta_lock_bh(cl_hw);

	cl_sta = cl_sta_get(cl_hw, sta_idx);
	if (cl_sta)
		callback(cl_hw, cl_sta);

	cl_sta_unlock_bh(cl_hw);
}

static void cl_stats_cli_cpu(struct cl_hw *cl_hw, bool action)
{
	if (action)
		cl_stats_print_cpu(cl_hw);
	else
		memset(&cl_hw->cpu_cntr, 0, sizeof(struct cl_cpu_cntr));
}

static void cl_stats_cli_rx_info(struct cl_hw *cl_hw, bool action)
{
	if (action)
		cl_rx_info_print(cl_hw);
	else
		cl_rx_info_reset(cl_hw);
}

static void cl_stats_cli_trfc_cntrs(struct cl_vif *cl_vif, bool action)
{
	if (action)
		cl_vif_trfc_cntrs_print(cl_vif);
	else
		cl_vif_trfc_cntrs_reset(cl_vif);
}

static void cll_stats_config_ps(struct cl_sta *cl_sta)
{
	cl_sta->stats->ps.timestamp_sleep = jiffies;
	cl_sta->stats->ps.is_ps = test_sta_flag(cl_sta->stainfo, WLAN_STA_PS_STA) ? true : false;
}

static void cl_stats_free(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	kfree(cl_sta->stats);
	cl_sta->stats = NULL;
}

static void cl_stats_alloc(struct cl_hw *cl_hw)
{
	/*
	 * Allocate for all existing stations.
	 * If one of the allocations fails disable ci_stats_en (and free the
	 * stations that were already allocated).
	 * In production mode also allocate cl_hw->rx_stats
	 */
	struct cl_sta *cl_sta = NULL;
	bool success = true;

	if (cl_hw->chip->conf->ce_production_mode) {
		cl_hw->rx_stats = kzalloc(sizeof(*cl_hw->rx_stats), GFP_ATOMIC);

		if (!cl_hw->rx_stats)
			return;
	}

	read_lock(&cl_hw->cl_sta_db.lock);

	list_for_each_entry(cl_sta, &cl_hw->cl_sta_db.head, list) {
		cl_sta->stats = kzalloc(sizeof(*cl_sta->stats), GFP_ATOMIC);

		if (cl_sta->stats) {
			cll_stats_config_ps(cl_sta);
		} else {
			success = false;
			break;
		}
	}

	if (success) {
		pr_debug("Statistics enabled\n");
		cl_hw->conf->ci_stats_en = true;
	} else {
		list_for_each_entry(cl_sta, &cl_hw->cl_sta_db.head, list)
			cl_stats_free(cl_hw, cl_sta);
	}

	read_unlock(&cl_hw->cl_sta_db.lock);
}

static void cl_stats_cli_enable(struct cl_hw *cl_hw, bool enable)
{
	if (enable == cl_hw->conf->ci_stats_en) {
		pr_debug("Statistics are already %s\n", enable ? "Enabled" : "Disabled");
		return;
	}

	spin_lock_bh(&cl_hw->lock_stats);

	if (enable) {
		cl_stats_alloc(cl_hw);
	} else {
		pr_debug("Statistics disabled\n");
		cl_hw->conf->ci_stats_en = false;
		cl_sta_loop(cl_hw, cl_stats_free);

		if (cl_hw->chip->conf->ce_production_mode) {
			kfree(cl_hw->rx_stats);
			cl_hw->rx_stats = NULL;
		}
	}

	spin_unlock_bh(&cl_hw->lock_stats);
}

static void cl_stats_cli_rx(struct cl_hw *cl_hw, u8 sta_idx)
{
	if (!cl_hw->conf->ci_stats_en)
		return;

	spin_lock_bh(&cl_hw->lock_stats);

	if (cl_hw->chip->conf->ce_production_mode) {
		cl_stats_print_rx(cl_hw, NULL);
	} else {
		if (sta_idx == STA_IDX_INVALID) {
			cl_sta_loop_bh(cl_hw, cl_stats_print_rx);
			pr_debug("*** END OF RX STATS ***\n");
		} else {
			cl_sta_print_do(cl_hw, sta_idx, cl_stats_print_rx);
		}
	}

	spin_unlock_bh(&cl_hw->lock_stats);
}

static void cl_stats_cli_rssi(struct cl_hw *cl_hw, u8 sta_idx)
{
	if (!cl_hw->conf->ci_stats_en)
		return;

	spin_lock_bh(&cl_hw->lock_stats);

	if (sta_idx == STA_IDX_INVALID) {
		cl_sta_loop_bh(cl_hw, cl_stats_print_rssi);
		pr_debug("*** END OF RSSI STATS ***\n");
	} else {
		cl_sta_print_do(cl_hw, sta_idx, cl_stats_print_rssi);
	}

	spin_unlock_bh(&cl_hw->lock_stats);
}

static void cl_stats_cli_fec_coding(struct cl_hw *cl_hw, u8 sta_idx)
{
	if (!cl_hw->conf->ci_stats_en)
		return;

	spin_lock_bh(&cl_hw->lock_stats);

	if (sta_idx == STA_IDX_INVALID) {
		cl_sta_loop_bh(cl_hw, cl_stats_print_fec_coding);
		pr_debug("*** END OF FEC STATS ***\n");
	} else {
		cl_sta_print_do(cl_hw, sta_idx, cl_stats_print_fec_coding);
	}

	spin_unlock_bh(&cl_hw->lock_stats);
}

static void cl_stats_cli_ps(struct cl_hw *cl_hw, u8 sta_idx)
{
	if (!cl_hw->conf->ci_stats_en)
		return;

	spin_lock_bh(&cl_hw->lock_stats);

	if (sta_idx == STA_IDX_INVALID) {
		cl_sta_loop_bh(cl_hw, cl_stats_print_power_save);
		pr_debug("*** END OF POWER_SAVE STATS ***\n");
	} else {
		cl_sta_print_do(cl_hw, sta_idx, cl_stats_print_power_save);
	}

	spin_unlock_bh(&cl_hw->lock_stats);
}

static void cl_stats_cli_tx(struct cl_hw *cl_hw, u8 sta_idx)
{
	if (!cl_hw->conf->ci_stats_en)
		return;

	spin_lock_bh(&cl_hw->lock_stats);

	if (sta_idx == STA_IDX_INVALID) {
		cl_sta_loop_bh(cl_hw, cl_stats_print_tx);
		pr_debug("*** END OF TX STATS ***\n");
	} else {
		cl_sta_print_do(cl_hw, sta_idx, cl_stats_print_tx);
	}

	spin_unlock_bh(&cl_hw->lock_stats);
}

static void cl_stats_cli_reset(struct cl_hw *cl_hw, u8 sta_idx)
{
	if (!cl_hw->conf->ci_stats_en)
		return;

	spin_lock_bh(&cl_hw->lock_stats);

	if (cl_hw->chip->conf->ce_production_mode) {
		memset(cl_hw->rx_stats, 0, sizeof(struct cl_rx_stats));
	} else {
		if (sta_idx == STA_IDX_INVALID)
			cl_sta_loop_bh(cl_hw, cl_stats_sta_reset);
		else
			cl_sta_print_do(cl_hw, sta_idx, cl_stats_sta_reset);
	}

	spin_unlock_bh(&cl_hw->lock_stats);
}

static int cl_stats_cli_help(struct cl_hw *cl_hw)
{
	char *buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!buf)
		return -ENOMEM;

	snprintf(buf, PAGE_SIZE,
		 "stats usage:\n"
		 "-a : Print air PER and system PER [delay-ms)]\n"
		 "-b : CPU stats [0-reset, 1-print]\n"
		 "-e : Enable/Disable statistics [0-dis, 1-en]\n"
		 "-f : Print RX FEC coding counters [sta_idx]\n"
		 "-p : Print power-save statistics [sta_idx]\n"
		 "-r : Print RX stats table [sta_idx]\n"
		 "-s : Print RSSI stats tables [sta_idx]\n"
		 "-t : Print TX stats table [sta_idx]\n"
		 "-u : Uplink stats [0-reset, 1-print]\n"
		 "-v : VIF traffic counters [0-reset, 1-print]\n"
		 "-z : Reset stats tables [sta_idx]\n");

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

static void _cl_stats_update_tx(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
				struct cl_agg_tx_report *agg_report)
{
	struct cl_stats *stats = cl_sta->stats;
	struct cl_tx_cntrs *cntrs;
	union cl_rate_ctrl_info rate_ctrl_info = {
			.word = le32_to_cpu(agg_report->rate_cntrl_info)};
	u8 bw, nss, mcs, gi, bf;

	switch (rate_ctrl_info.field.format_mod) {
	case WRS_MODE_HE:
		bw = rate_ctrl_info.field.bw;
		nss = (rate_ctrl_info.field.mcs_index >> 4);
		mcs = (rate_ctrl_info.field.mcs_index & 0xF);
		gi = rate_ctrl_info.field.gi;
		bf = agg_report->bf;
		cntrs = &stats->tx.he[bw][nss][mcs][gi][bf];
		break;
	case WRS_MODE_VHT:
		bw = rate_ctrl_info.field.bw;
		nss = (rate_ctrl_info.field.mcs_index >> 4);
		mcs = (rate_ctrl_info.field.mcs_index & 0xF);
		gi = rate_ctrl_info.field.gi;
		bf = agg_report->bf;
		cntrs = &stats->tx.vht[bw][nss][mcs][gi][bf];
		break;
	case WRS_MODE_HT:
		bw = rate_ctrl_info.field.bw;
		nss = (rate_ctrl_info.field.mcs_index >> 3);
		mcs = (rate_ctrl_info.field.mcs_index & 0x7);
		gi = rate_ctrl_info.field.gi;
		cntrs = &stats->tx.ht[bw][nss][mcs][gi];
		break;
	case WRS_MODE_OFDM:
		mcs = rate_ctrl_info.field.mcs_index - RATE_CTRL_OFFSET_OFDM;
		cntrs = &stats->tx.ofdm[mcs];
		break;
	case WRS_MODE_CCK:
		mcs = rate_ctrl_info.field.mcs_index;
		cntrs = &stats->tx.cck[mcs];
		break;
	default:
		return;
	}

	cntrs->success += agg_report->success;
	cntrs->fail += agg_report->fail;
}

static void _cl_stats_update_rx_rate(struct cl_hw *cl_hw,
				     struct cl_rx_stats *rx_stats,
				     struct hw_rxhdr *rxhdr)
{
	u8 bw, nss, mcs, gi;

	switch (rxhdr->format_mod) {
	case FORMATMOD_HE_TRIG:
		nss = rxhdr->n_sts & 0x3;
		mcs = min_t(int, rxhdr->mcs, WRS_MCS_MAX_HE);
		gi = min_t(int, rxhdr->gi_type, WRS_GI_MAX_HE);
		rx_stats->he_trig[rxhdr->ch_bw][nss][mcs][gi] += rxhdr->frm_successful_rx;
		rx_stats->flag |= RX_STATS_HE_TRIG;
		break;
	case FORMATMOD_HE_EXT:
		nss = rxhdr->n_sts & 0x3;
		mcs = min_t(int, rxhdr->mcs, WRS_MCS_MAX_HE);
		gi = min_t(int, rxhdr->gi_type, WRS_GI_MAX_HE);
		rx_stats->he_ext[rxhdr->ch_bw][nss][mcs][gi] += rxhdr->frm_successful_rx;
		rx_stats->flag |= RX_STATS_HE_EXT;
		break;
	case FORMATMOD_HE_MU:
		nss = rxhdr->n_sts & 0x3;
		mcs = min_t(int, rxhdr->mcs, WRS_MCS_MAX_HE);
		gi = min_t(int, rxhdr->gi_type, WRS_GI_MAX_HE);
		rx_stats->he_mu[rxhdr->ch_bw][nss][mcs][gi] += rxhdr->frm_successful_rx;
		rx_stats->flag |= RX_STATS_HE_MU;
		break;
	case FORMATMOD_HE_SU:
		nss = rxhdr->n_sts & 0x3;
		mcs = min_t(int, rxhdr->mcs, WRS_MCS_MAX_HE);
		gi = min_t(int, rxhdr->gi_type, WRS_GI_MAX_HE);
		rx_stats->he_su[rxhdr->ch_bw][nss][mcs][gi] += rxhdr->frm_successful_rx;
		rx_stats->flag |= RX_STATS_HE_SU;
		break;
	case FORMATMOD_VHT:
		nss = rxhdr->n_sts & 0x3;
		mcs = min_t(int, rxhdr->mcs, WRS_MCS_MAX_VHT);
		gi = rxhdr->gi_type & 0x1;
		rx_stats->vht[rxhdr->ch_bw][nss][mcs][gi] += rxhdr->frm_successful_rx;
		rx_stats->flag |= RX_STATS_VHT;
		break;
	case FORMATMOD_HT_MF:
	case FORMATMOD_HT_GF:
		bw = rxhdr->ch_bw & 0x1;
		nss = (rxhdr->mcs >> 3) & 0x3;
		mcs = rxhdr->mcs & 0x7;
		gi = rxhdr->gi_type & 0x1;
		rx_stats->ht[bw][nss][mcs][gi] += rxhdr->frm_successful_rx;
		rx_stats->flag |= RX_STATS_HT;
		break;
	case FORMATMOD_NON_HT:
		if (rxhdr->mcs >= RATE_CTRL_OFFSET_OFDM) {
			mcs = (rxhdr->mcs - RATE_CTRL_OFFSET_OFDM) & 0x7;
			rx_stats->ofdm[mcs] += rxhdr->frm_successful_rx;
			rx_stats->flag |= RX_STATS_OFDM;
		} else if (cl_band_is_24g(cl_hw)) {
			mcs = rxhdr->mcs & 0x3;
			rx_stats->cck[mcs] += rxhdr->frm_successful_rx;
			rx_stats->flag |= RX_STATS_CCK;
		}
		break;
	}
}

void cl_stats_init(struct cl_hw *cl_hw)
{
	spin_lock_init(&cl_hw->lock_stats);

	if (cl_hw->conf->ci_stats_en && cl_hw->chip->conf->ce_production_mode) {
		cl_hw->rx_stats = kzalloc(sizeof(*cl_hw->rx_stats), GFP_ATOMIC);

		if (!cl_hw->rx_stats)
			cl_hw->conf->ci_stats_en = false;
	}
}

void cl_stats_deinit(struct cl_hw *cl_hw)
{
	if (cl_hw->conf->ci_stats_en && cl_hw->chip->conf->ce_production_mode) {
		cl_hw->conf->ci_stats_en = false;

		spin_lock_bh(&cl_hw->lock_stats);

		kfree(cl_hw->rx_stats);
		cl_hw->rx_stats = NULL;

		spin_unlock_bh(&cl_hw->lock_stats);
	}
}

void cl_stats_sta_add(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	/*
	 * If allocation failed disable ci_stats_en
	 * and free the memory of all other stations
	 */
	bool disable = false;

	if (cl_hw->conf->ci_stats_en) {
		/*
		 * Take regular lock and not BH
		 * because cl_sta_add_to_lut() already disables BH
		 */
		spin_lock(&cl_hw->lock_stats);

		cl_sta->stats = kzalloc(sizeof(*cl_sta->stats), GFP_ATOMIC);

		if (cl_sta->stats)
			cll_stats_config_ps(cl_sta);
		else
			disable = true;

		spin_unlock(&cl_hw->lock_stats);
	}

	if (disable)
		cl_stats_cli_enable(cl_hw, false);
}

void cl_stats_sta_remove(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	if (!cl_hw->conf->ci_stats_en)
		return;

	spin_lock_bh(&cl_hw->lock_stats);

	cl_stats_free(cl_hw, cl_sta);

	spin_unlock_bh(&cl_hw->lock_stats);
}

void cl_stats_update_tx_agg(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
			    struct cl_agg_tx_report *agg_report)
{
	struct cl_stats *stats = cl_sta->stats;

	if (!cl_hw->conf->ci_stats_en)
		return;

	spin_lock(&cl_hw->lock_stats);

	stats->tx.agg_cntr++;
	stats->tx.fail_cntr += agg_report->fail;
	_cl_stats_update_tx(cl_hw, cl_sta, agg_report);

	spin_unlock(&cl_hw->lock_stats);
}

void cl_stats_update_tx_single(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
			       struct cl_agg_tx_report *agg_report)
{
	if (!cl_hw->conf->ci_stats_en)
		return;

	spin_lock(&cl_hw->lock_stats);

	cl_sta->stats->tx.fail_cntr += agg_report->fail;
	_cl_stats_update_tx(cl_hw, cl_sta, agg_report);

	spin_unlock(&cl_hw->lock_stats);
}

void cl_stats_update_rx_rssi(struct cl_hw *cl_hw, struct cl_sta *cl_sta, s8 rssi[MAX_ANTENNAS])
{
	int i;
	s8 rx_rssi;

	if (!cl_hw->conf->ci_stats_en)
		return;

	spin_lock_bh(&cl_hw->lock_stats);

	for (i = 0; i < cl_hw->num_antennas; i++) {
		rx_rssi = rssi[i] * -1;

		if (rx_rssi >= 0 && rx_rssi < RSSI_ARR_SIZE)
			cl_sta->stats->rssi[rx_rssi][i]++;
	}

	spin_unlock_bh(&cl_hw->lock_stats);
}

void cl_stats_update_rx_rate(struct cl_hw *cl_hw, struct cl_sta *cl_sta, struct hw_rxhdr *rxhdr)
{
	if (!cl_hw->conf->ci_stats_en)
		return;

	spin_lock(&cl_hw->lock_stats);

	_cl_stats_update_rx_rate(cl_hw, &cl_sta->stats->rx, rxhdr);
	cl_sta->stats->fec_coding[rxhdr->fec_coding]++;

	spin_unlock(&cl_hw->lock_stats);
}

void cl_stats_update_rx_rate_production(struct cl_hw *cl_hw, struct hw_rxhdr *rxhdr)
{
	if (!cl_hw->conf->ci_stats_en)
		return;

	spin_lock(&cl_hw->lock_stats);

	_cl_stats_update_rx_rate(cl_hw, cl_hw->rx_stats, rxhdr);

	spin_unlock(&cl_hw->lock_stats);
}

void cl_stats_update_ps(struct cl_hw *cl_hw, struct cl_sta *cl_sta, bool is_ps)
{
	struct cl_ps_stats *ps;

	if (!cl_hw->conf->ci_stats_en)
		return;

	spin_lock_bh(&cl_hw->lock_stats);

	ps = &cl_sta->stats->ps;

	if (ps->is_ps == is_ps)
		goto out;

	ps->is_ps = is_ps;

	if (is_ps) {
		ps->timestamp_sleep = jiffies;
	} else {
		unsigned long sleep_time = jiffies_to_msecs(jiffies - ps->timestamp_sleep);

		if (sleep_time <= 50)
			ps->period[PS_PERIOD_50MS]++;
		else if (sleep_time <= 100)
			ps->period[PS_PERIOD_100MS]++;
		else if (sleep_time <= 250)
			ps->period[PS_PERIOD_250MS]++;
		else if (sleep_time <= 500)
			ps->period[PS_PERIOD_500MS]++;
		else if (sleep_time <= 750)
			ps->period[PS_PERIOD_750MS]++;
		else if (sleep_time <= 1000)
			ps->period[PS_PERIOD_1000MS]++;
		else if (sleep_time <= 2000)
			ps->period[PS_PERIOD_2000MS]++;
		else if (sleep_time <= 5000)
			ps->period[PS_PERIOD_5000MS]++;
		else if (sleep_time <= 10000)
			ps->period[PS_PERIOD_10000MS]++;
		else
			ps->period[PS_PERIOD_ABOVE]++;
	}

out:
	spin_unlock_bh(&cl_hw->lock_stats);
}

int cl_stats_cli(struct cl_hw *cl_hw, struct cl_vif *cl_vif, struct cli_params *cli_params)
{
	bool print_per = false;
	bool cpu_stats = false;
	bool enable_tx_rx_rssi = false;
	bool print_rx = false;
	bool print_rssi = false;
	bool print_fec_coding = false;
	bool print_power_save = false;
	bool print_tx = false;
	bool uplink_stats = false;
	bool vif_cntrs = false;
	bool reset_stats = false;
	u32 expected_params = -1;

	switch (cli_params->option) {
	case 'a':
		print_per = true;
		expected_params = 1;
		break;
	case 'b':
		cpu_stats = true;
		expected_params = 1;
		break;
	case 'e':
		enable_tx_rx_rssi = true;
		expected_params = 1;
		break;
	case 'f':
		print_fec_coding = true;
		expected_params = 1;
		break;
	case 'p':
		print_power_save = true;
		expected_params = 1;
		break;
	case 't':
		print_tx = true;
		expected_params = 1;
		break;
	case 'r':
		print_rx = true;
		expected_params = cl_hw->chip->conf->ce_production_mode ? 0 : 1;
		break;
	case 'z':
		reset_stats = true;
		expected_params = cl_hw->chip->conf->ce_production_mode ? 0 : 1;
		break;
	case 's':
		print_rssi = true;
		expected_params = 1;
		break;
	case 'u':
		uplink_stats = true;
		expected_params = 1;
		break;
	case 'v':
		vif_cntrs = true;
		expected_params = 1;
		break;
	case '?':
		return cl_stats_cli_help(cl_hw);
	default:
		cl_dbg_err(cl_hw, "Illegal option (%c) - try '?' for help\n", cli_params->option);
		goto out_err;
	}

	if (expected_params != cli_params->num_params) {
		cl_dbg_err(cl_hw, "Wrong number of arguments (expected %u) (actual %u)\n",
			   expected_params, cli_params->num_params);
		goto out_err;
	}

	if (print_per) {
		cl_stats_print_per(cl_hw, (u32)cli_params->params[0]);
		return 0;
	}

	if (cpu_stats) {
		cl_stats_cli_cpu(cl_hw, (bool)cli_params->params[0]);
		return 0;
	}

	if (uplink_stats) {
		cl_stats_cli_rx_info(cl_hw, (bool)cli_params->params[0]);
		return 0;
	}

	if (vif_cntrs) {
		cl_stats_cli_trfc_cntrs(cl_vif, (bool)cli_params->params[0]);
		return 0;
	}

	if (enable_tx_rx_rssi) {
		cl_stats_cli_enable(cl_hw, (bool)cli_params->params[0]);
		return 0;
	}

	if (!cl_hw->conf->ci_stats_en) {
		pr_debug("Statistics are disabled!\n"
			 "To enable them type: "
			 "'iwcl <interface> cecli stats -e.1'\n");
		return 0;
	}

	if (print_rx) {
		u8 sta_idx = (u8)cli_params->params[0];

		cl_stats_cli_rx(cl_hw, sta_idx);
		return 0;
	}

	if (print_rssi) {
		u8 sta_idx = (u8)cli_params->params[0];

		cl_stats_cli_rssi(cl_hw, sta_idx);
		return 0;
	}

	if (print_fec_coding) {
		u8 sta_idx = (u8)cli_params->params[0];

		cl_stats_cli_fec_coding(cl_hw, sta_idx);
		return 0;
	}

	if (print_power_save) {
		u8 sta_idx = (u8)cli_params->params[0];

		cl_stats_cli_ps(cl_hw, sta_idx);
		return 0;
	}

	if (print_tx) {
		u8 sta_idx = (u8)cli_params->params[0];

		cl_stats_cli_tx(cl_hw, sta_idx);
		return 0;
	}

	if (reset_stats) {
		u8 sta_idx = (u8)cli_params->params[0];

		cl_stats_cli_reset(cl_hw, sta_idx);
		return 0;
	}

out_err:
	return -EIO;
}

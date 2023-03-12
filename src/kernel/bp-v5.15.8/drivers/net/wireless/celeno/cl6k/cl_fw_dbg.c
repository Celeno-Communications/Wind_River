// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_fw_dbg.h"
#include "cl_band.h"
#include "chip.h"
#include "cl_um_helper.h"
#include "file.h"
#include "cl_dbgfile.h"
#include "cl_rx.h"
#include "cl_msg_tx.h"
#include "chip_ops.h"
#include "cl_ipc.h"
#include "cl_usb.h"
#include "cl_mib.h"

/* Work struct wrapper for print statistics */
struct cl_print_stats_work {
	struct work_struct ws;
	struct cl_hw *cl_hw;
	u32 dbg_info_type;
};

#define FW_DBG_INVALID_SESSION U8_MAX

#define PRINT_FW(cl_hw, fmt, ...) \
	pr_debug("lmac%u " fmt, (cl_hw)->chip->idx, ##__VA_ARGS__)

#define FW_DBG_MAX_BUF 1024
#define FW_DBG_WR_THR  (FW_DBG_MAX_BUF * 8 / 10) /* 80% */

#define fw_snprintf(cl_hw, filp, ...) \
do { \
	struct cl_fw_dbg *fw_dbg = &(cl_hw)->fw_dbg; \
	fw_dbg->len += snprintf(fw_dbg->buf + fw_dbg->len, \
				FW_DBG_MAX_BUF - fw_dbg->len, ##__VA_ARGS__); \
	if (fw_dbg->len > FW_DBG_WR_THR) { \
		ssize_t ret = cl_file_write_buffer(filp, fw_dbg->buf, fw_dbg->len); \
		if (ret != fw_dbg->len) \
			cl_dbg_err(cl_hw, "Error writing to firmware debug file.\n"); \
		fw_dbg->len = 0; \
	} \
} while (0)

/*
 * Display 2 digit decimal fraction.
 * Example: x = 541, y = 19 = 28.47368
 *   ==> 47
 */
#define DECIMAL_FRACTION_X2(x, y) (100 * ((x) - (y) * ((x) / (y))) / (y))

static void cl_print_tx_stats(struct cl_hw *cl_hw)
{
	int i;
	u8 per = 0;
	u64 total_retry = 0;
	u64 total_tx = 0;
	u32 total_natt = 0;
	u32 avg_backoff = 0;
	u32 agg_size_total = 0;
	u32 agg_size_x100 = 0;
	u32 total_vns_off = 0;
	u32 total_vns_on = 0;
	bool is_agg_in_txop = false;
	struct cl_txl_statistics *tx_stats = &cl_hw->dbginfo.buf->u.tx_stats;
	struct cl_txl_agg_statistics *agg = &tx_stats->agg;
	struct cl_txl_htp_statistics *htp = &tx_stats->htp;
	struct cl_txl_natt_statistics *natt = &tx_stats->natt;
	struct cl_txl_vns_statistics *vns = &tx_stats->vns;
	struct cl_txl_fec_statistics *fec = &tx_stats->fec;
	struct cl_txl_backoff_params *backoff_params = &tx_stats->backoff_params;
	struct cl_txl_rts_cts_statistics *rts_cts = &tx_stats->rts_cts;
	struct cl_txl_underrun_statistics *underrun = &tx_stats->underrun;

	const char *fw_tx_backoff_str[CE_BACKOFF_MAX] = {
		[CE_BACKOFF_25]          = "<25",
		[CE_BACKOFF_50]          = "50",
		[CE_BACKOFF_100]         = "100",
		[CE_BACKOFF_500]         = "500",
		[CE_BACKOFF_1000]        = "1000",
		[CE_BACKOFF_5000]        = "5000",
		[CE_BACKOFF_10000]       = "10000",
		[CE_BACKOFF_20000]       = "20000",
		[CE_BACKOFF_20000_ABOVE] = ">20000",
	};

	/* Singles info */
	PRINT_FW(cl_hw, "TX statistics - singles\n");
	PRINT_FW(cl_hw, "------------------------------------------------------------------\n");
	PRINT_FW(cl_hw, "| q |sent      |retry     |lft exp   |ret limit |ret lim ps|per %%|\n");
	PRINT_FW(cl_hw, "|---+----------+----------+----------+----------+----------+-----|\n");

	for (i = 0; i < IPC_TX_QUEUE_CNT; i++) {
		total_retry = tx_stats->single[i].total_rtx_cnt +
			tx_stats->single[i].total_lifetime_expired_cnt +
			tx_stats->single[i].total_rtx_limit_reached;

		total_tx = tx_stats->single[i].total_cnt + total_retry;

		if (total_tx == 0)
			continue;

		per = (u8)div64_u64(total_retry * 100, total_tx);

		PRINT_FW(cl_hw, "|%3u|%10u|%10u|%10u|%10u|%10u|%5u|\n",
			 i,
			 tx_stats->single[i].total_cnt,
			 tx_stats->single[i].total_rtx_cnt,
			 tx_stats->single[i].total_lifetime_expired_cnt,
			 tx_stats->single[i].total_rtx_limit_reached,
			 tx_stats->single[i].total_rtx_limit_reached_ps,
			 per);
	}

	PRINT_FW(cl_hw, "------------------------------------------------------------------\n");
	PRINT_FW(cl_hw, "\n");

	/* Aggregation info */
	PRINT_FW(cl_hw, "TX statistics - aggregations - MAX [%u]\n", IPC_MAX_BA_SESSIONS);
	PRINT_FW(cl_hw, "-----------------------------------------------------------------------------------------------------------------------------\n");
	PRINT_FW(cl_hw, "|Q |Total    |Total    |Lifetime|Retry |BA       |BA not   |BA     |BA     |BA    |Below BA|Above BA|ACK    |PS BA not|Total|\n");
	PRINT_FW(cl_hw, "|  |sent     |retry    |expired |Limit |received |received |Cleared|Invalid|un-exp|window  |window  |inst BA|received |Per %%|\n");
	PRINT_FW(cl_hw, "|--+---------+---------+--------+------+---------+---------+-------+-------+------+--------+--------+-------+---------+-----|\n");

	for (i = 0; i < IPC_MAX_BA_SESSIONS; i++) {
		total_retry = tx_stats->ba[i].total_rtx_cnt +
			tx_stats->ba[i].total_lifetime_expired_cnt +
			tx_stats->ba[i].total_rtx_limit_reached;

		total_tx = tx_stats->ba[i].total_cnt;

		if (total_tx == 0)
			continue;

		per = (u8)div64_u64(total_retry * 100, total_tx);

		PRINT_FW(cl_hw, "|%2u|%9u|%9u|%8u|%6u|%9u|%9u|%7u|%7u|%6u|%8u|%8u|%7u|%9u|%5u|\n",
			 i,
			 tx_stats->ba[i].total_cnt,
			 tx_stats->ba[i].total_rtx_cnt,
			 tx_stats->ba[i].total_lifetime_expired_cnt,
			 tx_stats->ba[i].total_rtx_limit_reached,
			 tx_stats->ba[i].total_ba_received,
			 tx_stats->ba[i].total_ba_not_received_cnt,
			 tx_stats->ba[i].total_cleard_ba,
			 tx_stats->ba[i].total_invalid_ba,
			 tx_stats->ba[i].total_unexpected_ba,
			 tx_stats->ba[i].total_packets_below_baw,
			 tx_stats->ba[i].total_packets_above_baw,
			 tx_stats->ba[i].total_ack_instead_ba,
			 tx_stats->ba[i].total_ba_not_received_cnt_ps,
			 per);
	}
	PRINT_FW(cl_hw, "-----------------------------------------------------------------------------------------------------------------------------\n");
	PRINT_FW(cl_hw, "\n");

	/* TID info */
	PRINT_FW(cl_hw, "----------------\n");
	PRINT_FW(cl_hw, "|TID|NumPackets|\n");
	PRINT_FW(cl_hw, "|---+----------|\n");

	for (i = 0; i < TID_MAX; i++) {
		if (tx_stats->tid[i].total_tid_desc_cnt == 0)
			continue;

		PRINT_FW(cl_hw, "|%3d|%10u|\n", i, tx_stats->tid[i].total_tid_desc_cnt);
	}

	PRINT_FW(cl_hw, "----------------\n");
	PRINT_FW(cl_hw, "\n");

	/* AC info */
	PRINT_FW(cl_hw, "---------------------------------------------------------------------\n");
	PRINT_FW(cl_hw, "|     AC     |    0     |    1     |    2     |    3     |    4     |\n");
	PRINT_FW(cl_hw, "|------------+----------+----------+----------+----------+----------|\n");
	PRINT_FW(cl_hw, "|Num switches|%10u|%10u|%10u|%10u|%10u|\n",
		 tx_stats->ac[0].total_q_switch_cnt,
		 tx_stats->ac[1].total_q_switch_cnt,
		 tx_stats->ac[2].total_q_switch_cnt,
		 tx_stats->ac[3].total_q_switch_cnt,
		 tx_stats->ac[4].total_q_switch_cnt);
	PRINT_FW(cl_hw, "|Num txdesc  |%10u|%10u|%10u|%10u|%10u|\n",
		 tx_stats->ac[0].total_ac_desc_cnt,
		 tx_stats->ac[1].total_ac_desc_cnt,
		 tx_stats->ac[2].total_ac_desc_cnt,
		 tx_stats->ac[3].total_ac_desc_cnt,
		 tx_stats->ac[4].total_ac_desc_cnt);
	PRINT_FW(cl_hw, "---------------------------------------------------------------------\n");
	PRINT_FW(cl_hw, "\n");

	/* Underrun info */
	if (underrun->length_cnt || underrun->pattern_cnt) {
		PRINT_FW(cl_hw, "======== Underrun recovery statistics =======\n");
		PRINT_FW(cl_hw, "Length underrun %u\n",
			 underrun->length_cnt);
		PRINT_FW(cl_hw, "Pattern underrun %u\n",
			 underrun->pattern_cnt);
		PRINT_FW(cl_hw, "Total frames flushed in underrun %u\n",
			 underrun->flushed_frames_cnt);
		PRINT_FW(cl_hw, "\n");
	}

	/* BW drop fail info */
	if (tx_stats->tx_obtain_bw_fail_cnt) {
		PRINT_FW(cl_hw, "Failed to obtain BW count %u\n", tx_stats->tx_obtain_bw_fail_cnt);
		PRINT_FW(cl_hw, "\n");
	}

	/* mu desision statistics */
	PRINT_FW(cl_hw, "MU Desision statistics\n");
	PRINT_FW(cl_hw, "=======================\n");
	PRINT_FW(cl_hw, "SU - only one station in mu group = %u\n",
		 tx_stats->mu_desision.num_sta_in_mu_group[0]);
	PRINT_FW(cl_hw, "SU - mu_tx_active = %u\n",
		 tx_stats->mu_desision.mu_tx_active);
	PRINT_FW(cl_hw, "SU - primary not_mu_group = %u\n",
		 tx_stats->mu_desision.prim_not_in_mu_group);
	PRINT_FW(cl_hw, "SU - Primary rate_invalid = %u\n",
		 tx_stats->mu_desision.prim_rate_invalid);
	PRINT_FW(cl_hw, "SU - other = %u\n",
		 tx_stats->mu_desision.other_reason);
	PRINT_FW(cl_hw, "SU - total primary SU = %u\n",
		 tx_stats->mu_desision.total_num_su);
	PRINT_FW(cl_hw, "secondary  - rate invalid = %u\n",
		 tx_stats->mu_desision.is_2nd_rate_invalid);
	PRINT_FW(cl_hw, "secondary  - awake = %u\n",
		 tx_stats->mu_desision.is_2nd_awake);
	PRINT_FW(cl_hw, "secondary  - enough data = %u\n",
		 tx_stats->mu_desision.is_2nd_enouhg_data);
	PRINT_FW(cl_hw, "\n");

	/* Backoff time info */
	PRINT_FW(cl_hw, "Backoff Time [us]\n");
	PRINT_FW(cl_hw, "------------------------------------------------------\n");
	PRINT_FW(cl_hw, "|Backoff |   AC 0   |   AC 1   |   AC 2   |   AC 3   |\n");

	for (i = 0; i < CE_BACKOFF_MAX; i++) {
		if (tx_stats->backoff_stats[AC_BK].backoff_hist[i] == 0 &&
		    tx_stats->backoff_stats[AC_BE].backoff_hist[i] == 0 &&
		    tx_stats->backoff_stats[AC_VI].backoff_hist[i] == 0 &&
		    tx_stats->backoff_stats[AC_VO].backoff_hist[i] == 0)
			continue;

		PRINT_FW(cl_hw, "|--------+----------+----------+----------+----------|\n");
		PRINT_FW(cl_hw, "| %6s |%10u|%10u|%10u|%10u|\n",
			 fw_tx_backoff_str[i],
			 tx_stats->backoff_stats[AC_BK].backoff_hist[i],
			 tx_stats->backoff_stats[AC_BE].backoff_hist[i],
			 tx_stats->backoff_stats[AC_VI].backoff_hist[i],
			 tx_stats->backoff_stats[AC_VO].backoff_hist[i]);
	}

	PRINT_FW(cl_hw, "------------------------------------------------------\n");
	PRINT_FW(cl_hw, "\n");

	/* AMSDU Packet cnt */
	PRINT_FW(cl_hw, "|--------------------|\n");
	PRINT_FW(cl_hw, "|  AMSDU Packet cnt  |\n");
	PRINT_FW(cl_hw, "|--------------------|\n");
	for (i = 0; i < IPC_MAX_BA_SESSIONS; i++) {
		if (agg->amsdu_stat[i].packet_cnt_2 == 0 &&
		    agg->amsdu_stat[i].packet_cnt_3 == 0 &&
		    agg->amsdu_stat[i].packet_cnt_4 == 0 &&
		    agg->amsdu_stat[i].packet_cnt_5_or_more == 0)
			continue;

		PRINT_FW(cl_hw, "# session=%u\n", i);
		PRINT_FW(cl_hw, "packet_cnt  = 2: [%u]\n",
			 agg->amsdu_stat[i].packet_cnt_2);
		PRINT_FW(cl_hw, "packet_cnt  = 3: [%u]\n",
			 agg->amsdu_stat[i].packet_cnt_3);
		PRINT_FW(cl_hw, "packet_cnt  = 4: [%u]\n",
			 agg->amsdu_stat[i].packet_cnt_4);
		PRINT_FW(cl_hw, "packet_cnt >= 5: [%u]\n",
			 agg->amsdu_stat[i].packet_cnt_5_or_more);
		PRINT_FW(cl_hw, "\n");
	}
	PRINT_FW(cl_hw, "\n");

	/* Agg statistics */
	for (i = 1; i < CL_MAX_AGG_IN_TXOP; i++) {
		if (agg->agg_in_txop_statistics[i]) {
			is_agg_in_txop = true;
			break;
		}
	}

	if (is_agg_in_txop) {
		/* Agg in TXOP */
		PRINT_FW(cl_hw, "Agg in TXOP\n");
		PRINT_FW(cl_hw, "|----------------|\n");
		PRINT_FW(cl_hw, "| Agg |  Count   |\n");
		PRINT_FW(cl_hw, "|-----+----------|\n");

		for (i = 1; i < CL_MAX_AGG_IN_TXOP; i++) {
			if (!agg->agg_in_txop_statistics[i])
				continue;

			PRINT_FW(cl_hw, "|%5u|%10u|\n",
				 i + 1, agg->agg_in_txop_statistics[i]);
		}

		PRINT_FW(cl_hw, "|----------------|\n");
		PRINT_FW(cl_hw, "\n");

		/* Agg close reason & Agg queue switch */
		PRINT_FW(cl_hw, "Agg close reason:\n");
		PRINT_FW(cl_hw, "  Not enough txdescs = %u\n",
			 agg->agg_in_txop_close_reason[AGG_IN_TXOP_CLOSE_REASON_NO_TXDESC]);
		PRINT_FW(cl_hw, "  TXOP expired       = %u\n",
			 agg->agg_in_txop_close_reason[AGG_IN_TXOP_CLOSE_REASON_TXOP_EXPIRED]);
		PRINT_FW(cl_hw, "  Delba in process   = %u\n",
			 agg->agg_in_txop_close_reason[AGG_IN_TXOP_CLOSE_REASON_ACTIVE_DELBA]);
		PRINT_FW(cl_hw, "Agg queue switch:\n");
		PRINT_FW(cl_hw, "  Queue switch within TXOP               = %u\n",
			 agg->agg_in_txop_queue_switch);
		PRINT_FW(cl_hw, "  Queue switch abort due diff bw in TXOP = %u\n",
			 agg->agg_in_txop_queue_switch_abort_bw);
		PRINT_FW(cl_hw, "\n");
	}

	/* RTS-CTS statistics */
	if (rts_cts->fw_rts_cnt ||
	    rts_cts->fw_cts_cnt ||
	    rts_cts->hw_rts_cnt ||
	    rts_cts->hw_cts_cnt) {
		PRINT_FW(cl_hw, "RTS-CTS statistics\n");
		PRINT_FW(cl_hw, "==================\n");
		PRINT_FW(cl_hw, "FW RTS frame count = %u\n", rts_cts->fw_rts_cnt);
		PRINT_FW(cl_hw, "FW CTS frame count = %u\n", rts_cts->fw_cts_cnt);
		PRINT_FW(cl_hw, "HW RTS frame count = %u\n", rts_cts->hw_rts_cnt);
		PRINT_FW(cl_hw, "HW CTS frame count = %u\n", rts_cts->hw_cts_cnt);
		PRINT_FW(cl_hw, "\n");
	}

	/* Natt statistics */
	PRINT_FW(cl_hw, "natt statistics\n");
	PRINT_FW(cl_hw, "===============\n");
	PRINT_FW(cl_hw, "agg size[0] = %u <singeltons>\n", agg->agg_size_statistics[0]);
	PRINT_FW(cl_hw, "\n");

	PRINT_FW(cl_hw, "-----------------------------------------------------------\n");
	PRINT_FW(cl_hw, "|agg | num sent |percent | pass per | drop per | PER per  |\n");
	PRINT_FW(cl_hw, "|size| per size |per size| agg size | agg size | agg size |\n");
	PRINT_FW(cl_hw, "|----+----------+--------+----------+----------+----------|\n");

	for (i = 1; i < DBG_STATS_MAX_AGG_SIZE; i++)
		agg_size_total += agg->agg_size_statistics[i];

	for (i = 1; i < DBG_STATS_MAX_AGG_SIZE; i++) {
		if (agg->agg_size_statistics[i] == 0)
			continue;

		total_natt = agg->packet_failed_statistics[i] + agg->packet_passed_statistics[i];

		if (total_natt == 0)
			continue;

		agg_size_x100 = 100 * agg->agg_size_statistics[i];

		PRINT_FW(cl_hw, "|%4u|%10u|%5u.%02u|%10u|%10u|%10u|\n",
			 i,
			 agg->agg_size_statistics[i],
			 agg_size_x100 / agg_size_total,
			 DECIMAL_FRACTION_X2(agg_size_x100, agg_size_total),
			 agg->packet_passed_statistics[i],
			 agg->packet_failed_statistics[i],
			 ((agg->packet_failed_statistics[i] * 100) / total_natt));
	}
	PRINT_FW(cl_hw, "-----------------------------------------------------------\n");
	PRINT_FW(cl_hw, "Amount of all su aggregations: %u\n", agg_size_total);
	PRINT_FW(cl_hw, "\n");

	/* Natt statistics (HTP flows) */
	PRINT_FW(cl_hw, "natt statistics HTP flows\n");
	PRINT_FW(cl_hw, "=========================\n");
	PRINT_FW(cl_hw, "-----------------------------------------------------------\n");
	PRINT_FW(cl_hw, "|agg |num sent| percent  | pass per | drop per | PER per  |\n");
	PRINT_FW(cl_hw, "|size|per size| per size | agg size | agg size | agg size |\n");
	PRINT_FW(cl_hw, "|----+--------+----------+----------+----------+----------|\n");

	agg_size_total = 0;
	for (i = 1; i < DBG_STATS_MAX_AGG_SIZE; i++)
		agg_size_total += agg->htp_agg_size_statistics[i];

	for (i = 1; i < DBG_STATS_MAX_AGG_SIZE; i++) {
		if (agg->htp_agg_size_statistics[i] == 0)
			continue;

		total_natt = agg->htp_packet_failed_statistics[i] +
			agg->htp_packet_passed_statistics[i];

		if (total_natt == 0)
			continue;

		agg_size_x100 = 100 * agg->htp_agg_size_statistics[i];

		PRINT_FW(cl_hw, "|%4u|%10u|%5u.%02u|%10u|%10u|%10u|\n",
			 i,
			 agg->htp_agg_size_statistics[i],
			 agg_size_x100 / agg_size_total,
			 DECIMAL_FRACTION_X2(agg_size_x100, agg_size_total),
			 agg->htp_packet_passed_statistics[i],
			 agg->htp_packet_failed_statistics[i],
			 (agg->htp_agg_size_statistics[i] * 100 / total_natt));
	}
	PRINT_FW(cl_hw, "-----------------------------------------------------------\n");
	PRINT_FW(cl_hw, "\n");

	/* Chosen frame BW */
	PRINT_FW(cl_hw, "Chosen frame BW\n");
	for (i = 0; i < NATT_BW_MAX; i++)
		PRINT_FW(cl_hw, "BW[%u] = %u\n", i, natt->chosen_frame_bw[i]);
	PRINT_FW(cl_hw, "\n");

	/* Natt operation mode */
	PRINT_FW(cl_hw, "Natt operation mode\n");
	for (i = 0; i < 8; i++)
		if (natt->operation_mode[i] != 0)
			PRINT_FW(cl_hw, "[0x%x] = %u\n", i, natt->operation_mode[i]);
	PRINT_FW(cl_hw, "\n");

	/* Natt agg close reason */
	PRINT_FW(cl_hw, "natt agg close reason\n");
	PRINT_FW(cl_hw, "=====================\n");
	PRINT_FW(cl_hw, "Max length exceed  %u\n", natt->agg_close_reason[NATT_REASON_MAX_LEN]);
	PRINT_FW(cl_hw, "TXOP limit exceed  %u\n", natt->agg_close_reason[NATT_REASON_TXOP_LIMIT]);
	PRINT_FW(cl_hw, "MPDU number exceed %u\n", natt->agg_close_reason[NATT_REASON_MPDU_NUM]);
	PRINT_FW(cl_hw, "\n");

	/* Recovery count */
	if (tx_stats->recovery_count) {
		PRINT_FW(cl_hw, "Recovery count\n");
		PRINT_FW(cl_hw, "==============\n");
		PRINT_FW(cl_hw, "Total: %u\n", tx_stats->recovery_count);
		PRINT_FW(cl_hw, "\n");
	}

	/* Singelton backoff_params time */
	PRINT_FW(cl_hw, "Singelton backoff_params time:\n");
	for (i = 0; i < AC_MAX; i++) {
		if (backoff_params->singelton_cnt[i]) {
			avg_backoff = backoff_params->singelton_total[i] /
				backoff_params->singelton_cnt[i];
			PRINT_FW(cl_hw, "ac%d avarage backoff_params %u\n", i, avg_backoff);
		} else {
			PRINT_FW(cl_hw, "ac%d avarage backoff_params 0\n", i);
		}
	}
	PRINT_FW(cl_hw, "\n");

	/* Aggregation backoff_params time */
	PRINT_FW(cl_hw, "Aggregation backoff_params time:\n");
	for (i = 0; i < AC_VO; i++) {
		if (backoff_params->agg_cnt[i]) {
			avg_backoff = backoff_params->agg_total[i] /
				backoff_params->agg_cnt[i];
			PRINT_FW(cl_hw, "ac%d avarage backoff_params %u\n", i, avg_backoff);
		} else {
			PRINT_FW(cl_hw, "ac%d avarage backoff_params 0\n", i);
		}
	}
	PRINT_FW(cl_hw, "\n");

	/* Trigger Based traffic statistics */
	PRINT_FW(cl_hw, "Trigger Based traffic statistics:\n");
	for (i = 0; i < TID_MAX; i++) {
		u32 total_tid_desc_cnt;
		u32 total_htp_percent;

		if (!htp->total_cnt[i])
			continue;

		total_tid_desc_cnt = tx_stats->tid[i].total_tid_desc_cnt;
		total_htp_percent = total_tid_desc_cnt ?
				    (htp->total_cnt[i] * 100) /
				    total_tid_desc_cnt : 0;

		PRINT_FW(cl_hw, "TID%d total_cnt %u TB percent %u\n",
			 i, htp->total_cnt[i], total_htp_percent);
	}

	PRINT_FW(cl_hw, "\n");

	if (htp->need_response || htp->tb_response_required) {
		PRINT_FW(cl_hw, "need_response         = %u\n", htp->need_response);
		PRINT_FW(cl_hw, "tb_response_required  = %u\n", htp->tb_response_required);
		PRINT_FW(cl_hw, "ac_not_found          = %u\n", htp->ac_not_found);
		PRINT_FW(cl_hw, "end_of_packet_int     = %u\n", htp->end_of_packet_int);
		PRINT_FW(cl_hw, "tb_bw_decision        = %u\n", htp->tb_bw_decision);
		PRINT_FW(cl_hw, "tb_ba_thd_removed     = %u\n", htp->tb_ba_thd_removed);
		PRINT_FW(cl_hw, "tb_ac_unchain         = %u\n", htp->tb_ac_unchain);
		PRINT_FW(cl_hw, "tb_htp_unchain        = %u\n", htp->tb_htp_unchain);
		PRINT_FW(cl_hw, "tb_dummy_htp_tx       = %u\n", htp->tb_dummy_htp_tx);
		PRINT_FW(cl_hw, "tb_dummy_no_tx        = %u\n", htp->tb_dummy_no_tx);
		PRINT_FW(cl_hw, "msta_ba_received      = %u\n", htp->msta_ba_received);
		PRINT_FW(cl_hw, "msta_ba_aid_not_found = %u\n", htp->msta_ba_aid_not_found);
#ifdef PRESILICON_TESTING
		PRINT_FW(cl_hw, "uora_cnt_trigger_frame_tx = %u\n",
			 htp->uora_cnt_trigger_frame_tx);
		PRINT_FW(cl_hw, "uora_cnt_trigger_frame_rx = %u\n",
			 htp->uora_cnt_trigger_frame_rx);
		PRINT_FW(cl_hw, "uora_cnt_probe_req_tx = %u\n",
			 htp->uora_cnt_probe_req_tx);
		PRINT_FW(cl_hw, "uora_cnt_probe_req_rx = %u\n",
			 htp->uora_cnt_probe_req_rx);
		PRINT_FW(cl_hw, "\n");
#endif
	}

	total_vns_off = vns->off_cck + vns->off_ofdm + vns->off_ht_vht + vns->off_he;
	total_vns_on = vns->on_cck + vns->on_ofdm + vns->on_ht_vht + vns->on_he;

	if (total_vns_off || total_vns_on) {
		PRINT_FW(cl_hw, "       -----------------------\n");
		PRINT_FW(cl_hw, "       | VNS-OFF  |  VNS-ON  |\n");
		PRINT_FW(cl_hw, "-------+----------+----------|\n");
		PRINT_FW(cl_hw, "|CCK   |%10u|%10u|\n", vns->off_cck, vns->on_cck);
		PRINT_FW(cl_hw, "|OFDM  |%10u|%10u|\n", vns->off_ofdm, vns->on_ofdm);
		PRINT_FW(cl_hw, "|HT-VHT|%10u|%10u|\n", vns->off_ht_vht, vns->on_ht_vht);
		PRINT_FW(cl_hw, "|HE    |%10u|%10u|\n", vns->off_he, vns->on_he);
		PRINT_FW(cl_hw, "|------+----------+----------|\n");
		PRINT_FW(cl_hw, "|TOTAL |%10u|%10u|\n", total_vns_off, total_vns_on);
		PRINT_FW(cl_hw, "------------------------------\n");
		PRINT_FW(cl_hw, "\n");
	}

	if (fec->ldpc || fec->bcc) {
		PRINT_FW(cl_hw, "FEC Coding:\n");
		PRINT_FW(cl_hw, "LDPC = %u\n", fec->ldpc);
		PRINT_FW(cl_hw, "BCC  = %u\n", fec->bcc);
		PRINT_FW(cl_hw, "\n");
	}
}

static void cl_print_bcn_stats(struct cl_hw *cl_hw)
{
	struct cl_bcn_statistics *bcn_stats = &cl_hw->dbginfo.buf->u.bcn_stats;
	struct beacon_timing *bcn_timing_stats = &bcn_stats->beacon_timing;
	struct beacon_counters *bcn_cnt_stats = &bcn_stats->beacon_counters;
	struct bcn_backup_stats *bcn_backup_stats = &bcn_stats->bcn_backup_stats;
	u32 avg_time_between_bcn = 0, avg_time_bcn_chain = 0;

	if (bcn_cnt_stats->nof_time_intervals_between_beacons != 0)
		avg_time_between_bcn = (bcn_timing_stats->total_bcn_time /
					bcn_cnt_stats->nof_time_intervals_between_beacons);

	if (bcn_cnt_stats->bcn_chain_total_cnt != 0)
		avg_time_bcn_chain = ((bcn_timing_stats->bcn_chain_total_time) /
				      (bcn_cnt_stats->bcn_chain_total_cnt));

	PRINT_FW(cl_hw, "----------------------------------------\n");
	PRINT_FW(cl_hw, "Number of beacon flushed\n");
	PRINT_FW(cl_hw, "+---------+-------------+--------------+\n");
	PRINT_FW(cl_hw, "| pending | downloading | transmitting |\n");
	PRINT_FW(cl_hw, "+---------+-------------+--------------+\n");
	PRINT_FW(cl_hw, "|%-9u|%-13u|%-14u|\n",
		 bcn_cnt_stats->ce_txl_flushed_beacons[BCN_FLUSH_PENDING],
		 bcn_cnt_stats->ce_txl_flushed_beacons[BCN_FLUSH_DOWNLOADING],
		 bcn_cnt_stats->ce_txl_flushed_beacons[BCN_FLUSH_TRANSMITTING]);
	PRINT_FW(cl_hw, "+---------+-------------+--------------+\n\n");

	PRINT_FW(cl_hw, "----------------------------------------\n");
	PRINT_FW(cl_hw, "Time between transmission of two beacons\n");
	PRINT_FW(cl_hw, "+----------+----------+---------+----------------+\n");
	PRINT_FW(cl_hw, "| min time | max time | bcn cnt | avg time[mSec] |\n");
	PRINT_FW(cl_hw, "+----------+----------+---------+----------------+\n");
	PRINT_FW(cl_hw, "|%-10u|%-10u|%-9u|%-16u|\n",
		 bcn_timing_stats->min_time_from_last_bcn,
		 bcn_timing_stats->max_time_from_last_bcn,
		 bcn_cnt_stats->total_cnt,
		 avg_time_between_bcn);
	PRINT_FW(cl_hw, "+----------+----------+---------+----------------+\n\n");

	PRINT_FW(cl_hw, "---------------------------------------------------------------\n");
	PRINT_FW(cl_hw, "Time of beacon until chain\n");
	PRINT_FW(cl_hw, "+----------+----------+---------------+----------+\n");
	PRINT_FW(cl_hw, "| min time | max time | bcn chain cnt | avg time |\n");
	PRINT_FW(cl_hw, "+----------+----------+---------------+----------+\n");
	PRINT_FW(cl_hw, "|%-10u|%-10u|%-15u|%-10u|\n",
		 bcn_timing_stats->bcn_chain_min_time,
		 bcn_timing_stats->bcn_chain_max_time,
		 bcn_cnt_stats->bcn_chain_total_cnt,
		 avg_time_bcn_chain);
	PRINT_FW(cl_hw, "+----------+----------+---------------+----------+\n\n");

	PRINT_FW(cl_hw, "---------------------------------------------------------------------\n");
	PRINT_FW(cl_hw, " beacon pending-chain path max time = %u\n",
		 bcn_timing_stats->bcn_pending_2_chain_max_time);
	PRINT_FW(cl_hw, " beacon pending-chain not in time count = %u\n",
		 bcn_cnt_stats->pending2chain_not_in_threshold_cnt);
	PRINT_FW(cl_hw, " Max time until recievd beacon from driver = %u\n",
		 bcn_timing_stats->max_bcn_time_until_get_beacon_from_driver_in_tbtt);
	PRINT_FW(cl_hw, " Total count of beacon flushed because didn't received in time = %u\n",
		 bcn_cnt_stats->bcn_time_from_driver_not_in_threshold_cnt);
	PRINT_FW(cl_hw, " Max num of beacon not received from driver = %u\n",
		 bcn_cnt_stats->max_bcn_not_received_from_host);
	PRINT_FW(cl_hw, "---------------------------------------------------------------------\n");

	PRINT_FW(cl_hw, "+--------------------------------------+\n");
	PRINT_FW(cl_hw, "|        Backup beacon stats           |\n");
	PRINT_FW(cl_hw, "+------+------+---------+--------------+\n");
	PRINT_FW(cl_hw, "| Used |  TX  | flushed | Max in a row |\n");
	PRINT_FW(cl_hw, "+------+------+---------+--------------+\n");
	PRINT_FW(cl_hw, "|%6u|%6u|%9u|%14u|\n",
		 bcn_backup_stats->bcn_backup_used_cnt,
		 bcn_backup_stats->bcn_backup_tx_cnt,
		 bcn_backup_stats->bcn_backup_flushed_cnt,
		 bcn_backup_stats->bcn_backup_max_used_in_arow_cnt);
	PRINT_FW(cl_hw, "+------+------+---------+--------------+\n");
}

static void cl_print_rate_fallback_stats(struct cl_hw *cl_hw)
{
	struct cl_rate_drop_statistics
			*stats = &cl_hw->dbginfo.buf->u.rate_drop_stats;

	PRINT_FW(cl_hw, "\n");
	PRINT_FW(cl_hw, "---------------------------\n");
	PRINT_FW(cl_hw, "   Fallback statistics\n");
	PRINT_FW(cl_hw, "---------------------------\n");
	PRINT_FW(cl_hw, "ba_per_stats          = %u\n",
		 stats->drop_reason[AGG_TX_RATE_DROP_MAX_BA_PER_REACHED]);
	PRINT_FW(cl_hw, "ba_not_received_stats = %u\n",
		 stats->drop_reason[AGG_TX_RATE_DROP_MAX_BA_NOT_RECEIVED_REACHED]);
	PRINT_FW(cl_hw, "max_retry_reached     = %u\n",
		 stats->drop_reason[AGG_TX_RATE_DROP_MAX_RETRY_REACHED]);
}

static void cl_print_rx_stats_precent(struct cl_hw *cl_hw, const char *str, u32 x, u32 y)
{
	/*
	 * Example:
	 * x = 541, y = 19
	 * Result 28.4736
	 */
	u32 integer = x / y;
	u32 fraction = 10000 * (x - y * (x / y)) / y;

	PRINT_FW(cl_hw, "%s = %u.%04u\n", str, integer, fraction);
}

static void cl_print_rx_stats(struct cl_hw *cl_hw)
{
	int i, mu_idx, total_rx = 0;
	struct cl_rxl_statistics *rx_stats = &cl_hw->dbginfo.buf->u.rx_stats;

	PRINT_FW(cl_hw, "=========================================\n");
	PRINT_FW(cl_hw, "        Global RX stats\n");
	PRINT_FW(cl_hw, "=========================================\n");
	PRINT_FW(cl_hw, "host rxelem not ready      = %u\n",
		 rx_stats->host_rxelem_not_ready_cnt);
	PRINT_FW(cl_hw, "MSDU host rxelem not ready = %u\n",
		 rx_stats->msdu_host_rxelem_not_ready_cnt);
	PRINT_FW(cl_hw, "MSDU dma pool not ready    = %u\n",
		 rx_stats->dma_rx_pool_not_ready_cnt);
	PRINT_FW(cl_hw, "Percent of Rx CCA busy      = %u\n",
		 rx_stats->cca_busy_percent);
	PRINT_FW(cl_hw, "Percent of Rx mine CCA busy = %u\n",
		 rx_stats->rx_mine_busy_percent);
	PRINT_FW(cl_hw, "Percent of Tx mine busy     = %u\n",
		 rx_stats->tx_mine_busy_percent);
	PRINT_FW(cl_hw, "\n");

	PRINT_FW(cl_hw, "=== Rx Format ==\n");
	for (i = 0; i < MAX_NUM_OF_FORMATS; i++)
		if (rx_stats->stats_rx_format[i])
			PRINT_FW(cl_hw, "Rx Format[%d] = %u\n", i, rx_stats->stats_rx_format[i]);

	PRINT_FW(cl_hw, "=== Rx Decryption errors ==\n");
	for (i = RHD_DECR_ICVFAIL_IDX; i < RHD_DECR_IDX_MAX; i++)
		if (rx_stats->decrypt_err[i])
			PRINT_FW(cl_hw, "decrypt_err[%d] = %u\n", i, rx_stats->decrypt_err[i]);

	/* RX prints */
	for (mu_idx = 0; mu_idx < MAX_NUM_OF_SIMULTANEUS_UL_STREAMS; mu_idx++) {
		PRINT_FW(cl_hw, "============================================\n");
		PRINT_FW(cl_hw, "=====         RX MAC HW MU [%2d]       =====\n", mu_idx);
		PRINT_FW(cl_hw, "============================================\n");
		total_rx = rx_stats->total_rx_packets[mu_idx] +
			rx_stats->fcs_error_counter[mu_idx] +
			rx_stats->phy_error_counter[mu_idx] +
			rx_stats->ampdu_incorrect_received_counter[mu_idx] +
			rx_stats->delimiter_error_counter[mu_idx] +
			rx_stats->rx_fifo_overflow_err_cnt[mu_idx];

		if (total_rx == 0)
			continue;

		for (i = 0; i < MAX_HANDLED_FRM_TYPE; i++) {
			if (!rx_stats->emb_ll1_handled_frame_counter[mu_idx][i])
				continue;

			PRINT_FW(cl_hw, "emb_handled_packet[%d] - %u\n",
				 i, rx_stats->emb_ll1_handled_frame_counter[mu_idx][i]);
		}

		PRINT_FW(cl_hw, "Total packets dropped (pckt_len > %u) %u\n",
			 rx_stats->max_mpdu_data_len[mu_idx],
			 rx_stats->rx_pckt_exceed_max_len_cnt[mu_idx]);
		PRINT_FW(cl_hw, "Number of bad formated BA frames = %u\n",
			 rx_stats->rx_pckt_bad_ba_statinfo_cnt[mu_idx]);
		PRINT_FW(cl_hw, "Max occupancy list2 = %u\n",
			 rx_stats->rhd_ll2_max_cnt[mu_idx]);
		PRINT_FW(cl_hw, "Max occupancy list1 = %u\n",
			 rx_stats->rhd_ll1_max_cnt[mu_idx]);
		PRINT_FW(cl_hw, "\n");
		PRINT_FW(cl_hw, "Total Qos MPDU received    = %u\n",
			 rx_stats->total_rx_packets[mu_idx]);
		PRINT_FW(cl_hw, "Total Aggregation received = %u\n",
			 rx_stats->total_agg_packets[mu_idx]);
		PRINT_FW(cl_hw, "Number of Rx Fifo Overflow = %u\n",
			 rx_stats->rx_fifo_overflow_err_cnt[mu_idx]);
		PRINT_FW(cl_hw, "Number of FCS ERROR        = %u\n",
			 rx_stats->fcs_error_counter[mu_idx]);
		PRINT_FW(cl_hw, "Number of PHY ERROR        = %u\n",
			 rx_stats->phy_error_counter[mu_idx]);
		PRINT_FW(cl_hw, "Number of AMPDUS           = %u\n",
			 rx_stats->ampdu_received_counter[mu_idx]);
		PRINT_FW(cl_hw, "Number of Incorrect AMPDUS = %u\n",
			 rx_stats->ampdu_incorrect_received_counter[mu_idx]);
		PRINT_FW(cl_hw, "Number of Delimiter errors = %u\n",
			 rx_stats->delimiter_error_counter[mu_idx]);

		if (rx_stats->total_rx_packets[mu_idx]) {
			u32 total_rx_packets = rx_stats->total_rx_packets[mu_idx] +
				rx_stats->rx_fifo_overflow_err_cnt[mu_idx] +
				rx_stats->fcs_error_counter[mu_idx] +
				rx_stats->phy_error_counter[mu_idx] +
				rx_stats->delimiter_error_counter[mu_idx];

			cl_print_rx_stats_precent(cl_hw,
						  "Rx Fifo Overflow percent  ",
						  100 * rx_stats->rx_fifo_overflow_err_cnt[mu_idx],
						  total_rx_packets);
			cl_print_rx_stats_precent(cl_hw,
						  "FCS Error percent         ",
						  100 * rx_stats->fcs_error_counter[mu_idx],
						  total_rx_packets);
			cl_print_rx_stats_precent(cl_hw,
						  "Phy Error percent         ",
						  100 * rx_stats->phy_error_counter[mu_idx],
						  total_rx_packets);
			cl_print_rx_stats_precent(cl_hw,
						  "Delimiter Error percent   ",
						  100 * rx_stats->delimiter_error_counter[mu_idx],
						  total_rx_packets);
		}

		PRINT_FW(cl_hw, "Current NAV value          = %u\n", rx_stats->nav_value[mu_idx]);

		PRINT_FW(cl_hw, "\n");
		PRINT_FW(cl_hw, "Rx LL split stats: 1st LL interrupts = %u\n",
			 rx_stats->counter_timer_trigger_ll1[mu_idx]);
		PRINT_FW(cl_hw, "Rx LL split stats: 2nd LL interrupts = %u\n",
			 rx_stats->counter_timer_trigger_ll2[mu_idx]);
		PRINT_FW(cl_hw, "Number of incorrect format mode received = %u\n",
			 rx_stats->rx_incorrect_format_mode[mu_idx]);

		for (i = 0; i < CL_RX_CLASSIFICATION_MAX; i++) {
			if (!rx_stats->rx_class_counter[mu_idx][i])
				continue;

			PRINT_FW(cl_hw, "Rx classification rules stats: Rx rule%d= %u\n",
				 i, rx_stats->rx_class_counter[mu_idx][i]);
		}

		if (rx_stats->rx_class_int_counter[mu_idx])
			PRINT_FW(cl_hw, "Rx classification interrupts rules = %u\n",
				 rx_stats->rx_class_int_counter[mu_idx]);

		PRINT_FW(cl_hw, "\n");
		PRINT_FW(cl_hw, "Rx Implicit BF statistics:      = %u\n",
			 rx_stats->rx_imp_bf_counter[mu_idx]);
		PRINT_FW(cl_hw, "Rx Implicit BF interrupts stats = %u\n",
			 rx_stats->rx_imp_bf_int_counter[mu_idx]);
		PRINT_FW(cl_hw, "RXM STATISTICS\n");
		PRINT_FW(cl_hw, "rxm_stats_overflow      = %u\n",
			 rx_stats->rxm_stats_overflow[mu_idx]);
		PRINT_FW(cl_hw, "rx_incorrect_format_mode= %u\n",
			 rx_stats->rx_incorrect_format_mode[mu_idx]);
		PRINT_FW(cl_hw, "correct_received_mpdu   = %u\n",
			 rx_stats->correct_received_mpdu[mu_idx]);
		PRINT_FW(cl_hw, "incorrect_received_mpdu = %u\n",
			 rx_stats->incorrect_received_mpdu[mu_idx]);
		PRINT_FW(cl_hw, "discarded_mpdu          = %u\n",
			 rx_stats->discarded_mpdu[mu_idx]);
		PRINT_FW(cl_hw, "incorrect_delimiter     = %u\n",
			 rx_stats->incorrect_delimiter[mu_idx]);
		PRINT_FW(cl_hw, "rts_bar_cnt             = %u\n",
			 rx_stats->rts_bar_cnt[mu_idx]);
		PRINT_FW(cl_hw, "rxm_mpdu_cnt            = %u\n",
			 rx_stats->rxm_mpdu_cnt[mu_idx]);

		if (rx_stats->rxm_mpdu_cnt[mu_idx]) {
			PRINT_FW(cl_hw, "rxm_rule0_match        = %u\n",
				 rx_stats->rxm_rule0_match[mu_idx]);
			PRINT_FW(cl_hw, "rxm_rule1_match        = %u\n",
				 rx_stats->rxm_rule1_match[mu_idx]);
			PRINT_FW(cl_hw, "rxm_rule2_match        = %u\n",
				 rx_stats->rxm_rule2_match[mu_idx]);
			PRINT_FW(cl_hw, "rxm_rule3_match        = %u\n",
				 rx_stats->rxm_rule3_match[mu_idx]);
			PRINT_FW(cl_hw, "rxm_rule4_match        = %u\n",
				 rx_stats->rxm_rule4_match[mu_idx]);
			PRINT_FW(cl_hw, "rxm_rule5_match        = %u\n",
				 rx_stats->rxm_rule5_match[mu_idx]);
			PRINT_FW(cl_hw, "rxm_rule6_match        = %u\n",
				 rx_stats->rxm_rule6_match[mu_idx]);
			PRINT_FW(cl_hw, "rxm_default_rule_match = %u\n",
				 rx_stats->rxm_default_rule_match[mu_idx]);
#if 0
			PRINT_FW(cl_hw, "rxm_amsdua_1            = %u\n",
				 rx_stats->rxm_amsdu_1[mu_idx]);
			PRINT_FW(cl_hw, "rxm_amsdu_2            = %u\n",
				 rx_stats->rxm_amsdu_2[mu_idx]);
			PRINT_FW(cl_hw, "rxm_amsdu_3            = %u\n",
				 rx_stats->rxm_amsdu_3[mu_idx]);
			PRINT_FW(cl_hw, "rxm_amsdu_4            = %u\n",
				 rx_stats->rxm_amsdu_4[mu_idx]);
			PRINT_FW(cl_hw, "rxm_amsdu_5-15         = %u\n",
				 rx_stats->rxm_amsdu_5_15[mu_idx]);
			PRINT_FW(cl_hw, "rxm_amsdu_>=16         = %u\n",
				 rx_stats->rxm_amsdu_16_or_more[mu_idx]);
#endif
		}

		/* RX AMSDU prints */
		PRINT_FW(cl_hw, "\n");
		PRINT_FW(cl_hw, "RX AMSDU STATS\n");

		PRINT_FW(cl_hw, "AMSDU RX cnt  = %u\n",
			 rx_stats->stats_tot_rx_amsdu_cnt[mu_idx]);

		for (i = 0; i < ARRAY_SIZE(rx_stats->stats_rx_amsdu_cnt[mu_idx]); i++)
			if (rx_stats->stats_rx_amsdu_cnt[mu_idx][i])
				PRINT_FW(cl_hw, "A-MSDU of %d = %u\n",
					 i + 1, rx_stats->stats_rx_amsdu_cnt[mu_idx][i]);

		PRINT_FW(cl_hw, "A-MSDU RX errors:\n");
		for (i = 0; i < AMSDU_DEAGGREGATION_ERR_MAX; i++)
			if (rx_stats->stats_rx_amsdu_err[mu_idx][i])
				PRINT_FW(cl_hw, " err_id[%d] = %u\n",
					 i, rx_stats->stats_rx_amsdu_err[mu_idx][i]);
	}

	PRINT_FW(cl_hw, "Frequency offset:\n");
	for (i = 0; i < FREQ_OFFSET_TABLE_MAX_IDX; i++)
		if (rx_stats->frequency_offset[i])
			PRINT_FW(cl_hw, "frequency_offset = %u\n", rx_stats->frequency_offset[i]);
}

static void cl_print_trigger_flow_stats(struct cl_hw *cl_hw)
{
	u16 idx;
	struct cl_trigger_flow_statistics
			*tf_stats = &cl_hw->dbginfo.buf->u.trigger_flow_stats;
	struct cl_rx_trigger_based_stats *tb_stats = &cl_hw->tb_stats;

	if (!tb_stats->enable) {
		PRINT_FW(cl_hw, "WARNING: Trigger based statistics are disabled!\n");
		return;
	}

	PRINT_FW(cl_hw, "Trigger flow statistics\n\n");

	PRINT_FW(cl_hw, "Sent trigger frames\n");
	PRINT_FW(cl_hw, "-----------------------------------------------------------------\n");
	PRINT_FW(cl_hw, "|               |    AC0    |    AC1    |    AC2    |    AC3    |\n");
	PRINT_FW(cl_hw, "|---------------+-----------+-----------+-----------+-----------|\n");
	PRINT_FW(cl_hw, "| BASIC         | %9u | %9u | %9u | %9u |\n",
		 tf_stats->single_trigger_sent[TRIGGER_FLOW_BASIC_TRIGGER_TYPE][AC_BK],
		 tf_stats->single_trigger_sent[TRIGGER_FLOW_BASIC_TRIGGER_TYPE][AC_BE],
		 tf_stats->single_trigger_sent[TRIGGER_FLOW_BASIC_TRIGGER_TYPE][AC_VI],
		 tf_stats->single_trigger_sent[TRIGGER_FLOW_BASIC_TRIGGER_TYPE][AC_VO]);
	PRINT_FW(cl_hw, "| BSRP          | %9u | %9u | %9u | %9u |\n",
		 tf_stats->single_trigger_sent[TRIGGER_FLOW_BSRP_TYPE][AC_BK],
		 tf_stats->single_trigger_sent[TRIGGER_FLOW_BSRP_TYPE][AC_BE],
		 tf_stats->single_trigger_sent[TRIGGER_FLOW_BSRP_TYPE][AC_VI],
		 tf_stats->single_trigger_sent[TRIGGER_FLOW_BSRP_TYPE][AC_VO]);
	PRINT_FW(cl_hw, "| BFRP          | %9u | %9u | %9u | %9u |\n",
		 tf_stats->single_trigger_sent[TRIGGER_FLOW_BFRP_TYPE][AC_BK],
		 tf_stats->single_trigger_sent[TRIGGER_FLOW_BFRP_TYPE][AC_BE],
		 tf_stats->single_trigger_sent[TRIGGER_FLOW_BFRP_TYPE][AC_VI],
		 tf_stats->single_trigger_sent[TRIGGER_FLOW_BFRP_TYPE][AC_VO]);
	PRINT_FW(cl_hw, "| HTP FAILURE   | %9u | %9u | %9u | %9u |\n",
		 tf_stats->htp_rx_failure[AC_BK],
		 tf_stats->htp_rx_failure[AC_BE],
		 tf_stats->htp_rx_failure[AC_VI],
		 tf_stats->htp_rx_failure[AC_VO]);
	PRINT_FW(cl_hw, "-----------------------------------------------------------------\n\n");

	PRINT_FW(cl_hw, "Received TB MPDUs per MAC HW\n");
	PRINT_FW(cl_hw, "---------------------------------------\n");
	PRINT_FW(cl_hw, " Total - %10u\n", tb_stats->total);
	PRINT_FW(cl_hw, "---------------------------------------\n\n");

	PRINT_FW(cl_hw, "Received TB Data AGGs\n");
	PRINT_FW(cl_hw, "----------------------\n");
	PRINT_FW(cl_hw, "| Size |    Count    |\n");
	PRINT_FW(cl_hw, "|------+-------------|\n");
	for (idx = 1; idx < DBG_STATS_MAX_AGG_SIZE; idx++) {
		if (tb_stats->data[idx] == 0)
			continue;

		PRINT_FW(cl_hw, "| %4u |%13u|\n", idx, tb_stats->data[idx]);
	}
	PRINT_FW(cl_hw, "----------------------\n\n");

	PRINT_FW(cl_hw, "Received TB QoS-Null AGGs\n");
	PRINT_FW(cl_hw, "----------------------\n");
	PRINT_FW(cl_hw, "| Size |    Count    |\n");
	PRINT_FW(cl_hw, "|------+-------------|\n");
	for (idx = 1; idx < TID_MAX + 1; idx++)
		if (tb_stats->qos_null[idx] > 0)
			PRINT_FW(cl_hw, "| %4u |%13u|\n", idx, tb_stats->qos_null[idx]);

	if (tb_stats->qos_null[TID_MAX + 1] > 0)
		PRINT_FW(cl_hw, "|  >8  |%13u|\n", tb_stats->qos_null[TID_MAX + 1]);
	PRINT_FW(cl_hw, "----------------------\n\n");
}

static void cl_print_dyn_calib_stats(struct cl_hw *cl_hw)
{
	u8 i, j;
	struct cl_dyn_calib_statistics
		*dyn_cal_stats = &cl_hw->dbginfo.buf->u.dyn_calib_stats;

	PRINT_FW(cl_hw, "--------------------------------\n");
	PRINT_FW(cl_hw, "Dynamic Calibration Information\n");
	PRINT_FW(cl_hw, "--------------------------------\n\n");

	PRINT_FW(cl_hw, "Default Dynamic Calibation Value = %u\n\n",
		 dyn_cal_stats->default_dyn_cal_val);

	for (i = dyn_cal_stats->dyn_cal_debug_info_ix, j = 0;
	     j < DYN_CAL_DEBUG_NUM_ITER;
	     (i = ((i + 1) % 3)), j++) {
		struct dyn_cal_debug_info_t *dyn_cal_debug_info =
			&dyn_cal_stats->dyn_cal_debug_info[i];

		if (dyn_cal_stats->is_multi_client_mode)
			PRINT_FW(cl_hw,
				 "calib_num = %u, min_val = %d, max_val = %d, min_config = %u, "
				 "max_config = %u, curr_config = %u, new_config = %u\n",
				 dyn_cal_debug_info->calib_num,
				 (s32)dyn_cal_debug_info->dyn_cal_min_val,
				 (s32)dyn_cal_debug_info->dyn_cal_max_val,
				 dyn_cal_debug_info->min_config,
				 dyn_cal_debug_info->max_config,
				 dyn_cal_debug_info->curr_config,
				 dyn_cal_debug_info->new_config);
		else
			PRINT_FW(cl_hw,
				 "calib_num = %u, iter_num = %u, config_val_prev = %u, "
				 "measured_val = %u, new_config_val = %u\n",
				 dyn_cal_debug_info->calib_num,
				 dyn_cal_debug_info->iter_num,
				 dyn_cal_debug_info->curr_config,
				 dyn_cal_debug_info->measured_val,
				 dyn_cal_debug_info->new_config);
	}

	if (dyn_cal_stats->mac_phy_sync_err_cnt)
		PRINT_FW(cl_hw, "mac_phy_sync_err_cnt = %u\n\n",
			 dyn_cal_stats->mac_phy_sync_err_cnt);

	PRINT_FW(cl_hw, "\n-----------------------------------------\n\n");
}

static void cl_print_bf_stats(struct cl_hw *cl_hw)
{
	u32 idx;
	bool should_print = false;
	u16 *tx_bf_data_err;
	struct cl_bf_statistics *bf_stats = &cl_hw->dbginfo.buf->u.bf_stats;

	for (idx = 0; idx < BF_DB_MAX; idx++)
		if (bf_stats->print_active_free_list == bf_stats->stats_data[idx].is_active_list) {
			should_print = true;
			break;
		}

	if (!should_print)
		return;

	/* Info phase 1 */
	PRINT_FW(cl_hw, "List of non active BFs:\n");
	PRINT_FW(cl_hw, "============================\n");
	PRINT_FW(cl_hw, "BF_CTRL statistics\n");
	PRINT_FW(cl_hw, "+-----+----+----+-------+-------+----------------+-----------------+--------------+---------------+-----------------+---------------+--------------+------------+-------+\n");
	PRINT_FW(cl_hw, "|INDEX|#NDP|#BFP|#SU BFR|#MU BFR|#BFR_BW_MISMATCH|#BFR_NSS_MISMATCH|#SOUNDING_CHBW|#TOKEN_MISMATCH|#NDP_NDPA_TX_DROP|#BFR_RX_ERR_ACK|#BFR SEGMENTED|#RESOURCE_NA|STA_IDX|\n");
	PRINT_FW(cl_hw, "+-----+----+----+-------+-------+----------------+-----------------+--------------+---------------+-----------------+---------------+--------------+------------+-------+\n");

	for (idx = 0; idx < BF_DB_MAX; idx++) {
		if (bf_stats->print_active_free_list != bf_stats->stats_data[idx].is_active_list)
			continue;

		PRINT_FW(cl_hw,
			 "|%5u|%4u|%4u|%7u|%7u|%16u|%17u|%14u|%15u|%17u|%15u|%14u|%12u|%7u|\n",
			 idx,
			 bf_stats->stats_data[idx].dbg.ndp_cnt,
			 bf_stats->stats_data[idx].dbg.bfp_cnt,
			 bf_stats->stats_data[idx].dbg.su_bfr_cnt,
			 bf_stats->stats_data[idx].dbg.mu_bfr_cnt,
			 bf_stats->stats_data[idx].dbg.bf_invalid_cnt[BFR_RX_ERR_BW_MISMATCH],
			 bf_stats->stats_data[idx].dbg.bf_invalid_cnt[BFR_RX_ERR_NSS_MISMATCH],
			 bf_stats->stats_data[idx].dbg.bf_invalid_cnt[BFR_RX_ERR_SOUNDING_CHBW],
			 bf_stats->stats_data[idx].dbg.bf_invalid_cnt[BFR_RX_ERR_TOKEN_MISMATCH],
			 bf_stats->stats_data[idx].dbg.bf_invalid_cnt[BFR_RX_ERR_NDP_DROP],
			 bf_stats->stats_data[idx].dbg.bf_invalid_cnt[BFR_RX_ERR_MISS_ACK],
			 bf_stats->stats_data[idx].dbg.bf_invalid_cnt[BFR_SEGMENTED_DROP],
			 bf_stats->stats_data[idx].dbg.bf_invalid_cnt[BFR_RX_ERR_RESOURCE_NA],
			 bf_stats->stats_data[idx].sta_idx);
	}

	PRINT_FW(cl_hw, "+-----+----+----+-------+-------+----------------+-----------------+--------------+---------------+-----------------+---------------+--------------+------------+-------+\n");

	/* Info phase 2 */
	PRINT_FW(cl_hw, "statistic BF DATA FRAMESs:\n");
	PRINT_FW(cl_hw, "============================\n");
	PRINT_FW(cl_hw, "BF_CTRL statistics\n");
	PRINT_FW(cl_hw, "+-----+-----------+------------+-------------+-----------------+----------------+-----------------+-----------+-----------+----------+------------------+-----------------+-------+\n");
	PRINT_FW(cl_hw, "|INDEX|#ACTIVE_IDX|#PASSIVE_IDX|#ERR_BFR_MISS|#ERR_BFR_OUTDATED|#ERR_BW_MISMATCH|#ERR_NSS_MISMATCH|#BF_DATA_OK|#BUFF_IN_PS|#REL_IN_PS|#BUFF_RESOURCE_ERR|#REL_RESOURCE_ERR|STA_IDX|\n");
	PRINT_FW(cl_hw, "+-----+-----------+------------+-------------+-----------------+----------------+-----------------+-----------+-----------+----------+------------------+-----------------+-------+\n");

	for (idx = 0; idx < BF_DB_MAX; idx++) {
		if (bf_stats->print_active_free_list != bf_stats->stats_data[idx].is_active_list)
			continue;

		tx_bf_data_err = bf_stats->stats_data[idx].dbg.tx_bf_data_err;

		PRINT_FW(cl_hw,
			 "|%5u|%11u|%12u|%13u|%17u|%16u|%17u|%11u|%11u|%10u|%18u|%17u|%7u|\n",
			 idx,
			 bf_stats->stats_data[idx].active_dsp_idx,
			 bf_stats->stats_data[idx].passive_dsp_idx,
			 tx_bf_data_err[TX_BF_DATA_ERR_BFR_MISS],
			 tx_bf_data_err[TX_BF_DATA_ERR_BFR_OUTDATED],
			 tx_bf_data_err[TX_BF_DATA_ERR_MISMATCH_BW],
			 tx_bf_data_err[TX_BF_DATA_ERR_MISMATCH_NSS],
			 tx_bf_data_err[TX_BF_DATA_OK],
			 tx_bf_data_err[TX_BF_DATA_BUFFERED_PS_STA],
			 tx_bf_data_err[TX_BF_DATA_RELEASED_PS_STA],
			 tx_bf_data_err[TX_BF_DATA_BUFFERED_RESOURCE_ERR],
			 tx_bf_data_err[TX_BF_DATA_RELEASED_RESOURCE_ERR],
			 bf_stats->stats_data[idx].sta_idx);
	}

	PRINT_FW(cl_hw, "+-----+-----------+------------+-------------+-----------------+----------------+-----------------+-----------+-----------+----------+------------------+-----------------+-------+\n");
}

static void cl_print_pta_stats(struct cl_hw *cl_hw)
{
	struct cl_pta_statistics *pta_stats = &cl_hw->dbginfo.buf->u.pta_stats;
	u32 dev1_id = le32_to_cpu(pta_stats->dev_1_dev_2_collision_sel_dev_1);
	u32 dev2_id = le32_to_cpu(pta_stats->dev_1_dev_2_collision_sel_dev_2);

	PRINT_FW(cl_hw, "\nPTA statistics\n");
	PRINT_FW(cl_hw, "----------------------------------------------------------\n");
	PRINT_FW(cl_hw, "| Type            | Req        | Wait (cyc) | Air (cyc)  |\n");
	PRINT_FW(cl_hw, "|-----------------+------------+------------+------------|\n");
	PRINT_FW(cl_hw, "| Wifi 20 MHz Rx  | %10u | %10u | %10u |\n",
		 le32_to_cpu(pta_stats->wifi_rx_20_m_pkt),
		 le32_to_cpu(pta_stats->wifi_rx_20_m_wait),
		 le32_to_cpu(pta_stats->wifi_rx_20_m_air));
	PRINT_FW(cl_hw, "| Wifi 20 MHz Tx  | %10u | %10u | %10u |\n",
		 le32_to_cpu(pta_stats->wifi_tx_20_m_pkt),
		 le32_to_cpu(pta_stats->wifi_tx_20_m_wait),
		 le32_to_cpu(pta_stats->wifi_tx_20_m_air));
	PRINT_FW(cl_hw, "| Wifi 40 MHz Rx  | %10u | %10u | %10u |\n",
		 le32_to_cpu(pta_stats->wifi_rx_40_m_pkt),
		 le32_to_cpu(pta_stats->wifi_rx_40_m_wait),
		 le32_to_cpu(pta_stats->wifi_rx_40_m_air));
	PRINT_FW(cl_hw, "| Wifi 40 MHz Tx  | %10u | %10u | %10u |\n",
		 le32_to_cpu(pta_stats->wifi_tx_40_m_pkt),
		 le32_to_cpu(pta_stats->wifi_tx_40_m_wait),
		 le32_to_cpu(pta_stats->wifi_tx_40_m_air));
	PRINT_FW(cl_hw, "| Wifi 80 MHz Rx  | %10u | %10u | %10u |\n",
		 le32_to_cpu(pta_stats->wifi_rx_80_m_pkt),
		 le32_to_cpu(pta_stats->wifi_rx_80_m_wait),
		 le32_to_cpu(pta_stats->wifi_rx_80_m_air));
	PRINT_FW(cl_hw, "| Wifi 80 MHz Tx  | %10u | %10u | %10u |\n",
		 le32_to_cpu(pta_stats->wifi_tx_80_m_pkt),
		 le32_to_cpu(pta_stats->wifi_tx_80_m_wait),
		 le32_to_cpu(pta_stats->wifi_tx_80_m_air));
	PRINT_FW(cl_hw, "| Wifi 160 MHz Rx | %10u | %10u | %10u |\n",
		 le32_to_cpu(pta_stats->wifi_rx_160_m_pkt),
		 le32_to_cpu(pta_stats->wifi_rx_160_m_wait),
		 le32_to_cpu(pta_stats->wifi_rx_160_m_air));
	PRINT_FW(cl_hw, "| Wifi 160 MHz Tx | %10u | %10u | %10u |\n",
		 le32_to_cpu(pta_stats->wifi_tx_160_m_pkt),
		 le32_to_cpu(pta_stats->wifi_tx_160_m_wait),
		 le32_to_cpu(pta_stats->wifi_tx_160_m_air));
	PRINT_FW(cl_hw, "| EDR Rx          | %10u | %10u | %10u |\n",
		 le32_to_cpu(pta_stats->edr_rx_pkt),
		 le32_to_cpu(pta_stats->edr_rx_wait),
		 le32_to_cpu(pta_stats->edr_rx_air));
	PRINT_FW(cl_hw, "| EDR Tx          | %10u | %10u | %10u |\n",
		 le32_to_cpu(pta_stats->edr_tx_pkt),
		 le32_to_cpu(pta_stats->edr_tx_wait),
		 le32_to_cpu(pta_stats->edr_tx_air));
	PRINT_FW(cl_hw, "| BLE Rx          | %10u | %10u | %10u |\n",
		 le32_to_cpu(pta_stats->ble_rx_pkt),
		 le32_to_cpu(pta_stats->ble_rx_wait),
		 le32_to_cpu(pta_stats->ble_rx_air));
	PRINT_FW(cl_hw, "| BLE Tx          | %10u | %10u | %10u |\n",
		 le32_to_cpu(pta_stats->ble_tx_pkt),
		 le32_to_cpu(pta_stats->ble_tx_wait),
		 le32_to_cpu(pta_stats->ble_tx_air));
	PRINT_FW(cl_hw, "| External dev 1  | %10u | %10u | %10u |\n",
		 le32_to_cpu(pta_stats->ext_1_pkt),
		 le32_to_cpu(pta_stats->ext_1_wait),
		 le32_to_cpu(pta_stats->ext_1_air));
	PRINT_FW(cl_hw, "| External dev 2  | %10u | %10u | %10u |\n",
		 le32_to_cpu(pta_stats->ext_2_pkt),
		 le32_to_cpu(pta_stats->ext_2_wait),
		 le32_to_cpu(pta_stats->ext_2_air));
	PRINT_FW(cl_hw, "| Imaging         | %10u | %10u | %10u |\n",
		 le32_to_cpu(pta_stats->img_pkt),
		 le32_to_cpu(pta_stats->img_wait),
		 le32_to_cpu(pta_stats->img_air));
	PRINT_FW(cl_hw, "----------------------------------------------------------\n\n");

	PRINT_FW(cl_hw, "WiFi vs. Dev (any) collision map (cycles):\n");
	PRINT_FW(cl_hw, "-------------------------------------\n");
	PRINT_FW(cl_hw, "|         | Dev Tx     | Dev Rx     |\n");
	PRINT_FW(cl_hw, "|---------+------------+------------|\n");
	PRINT_FW(cl_hw, "| WiFi Tx | %10u | %10u |\n",
		 le32_to_cpu(pta_stats->wifi_tx_dev_tx_collision),
		 le32_to_cpu(pta_stats->wifi_tx_dev_rx_collision));
	PRINT_FW(cl_hw, "|---------+------------+------------|\n");
	PRINT_FW(cl_hw, "| WiFi Rx | %10u | %10u |\n",
		 le32_to_cpu(pta_stats->wifi_rx_dev_tx_collision),
		 le32_to_cpu(pta_stats->wifi_rx_dev_rx_collision));
	PRINT_FW(cl_hw, "-------------------------------------\n\n");

	PRINT_FW(cl_hw, "Dev%d vs. Dev%d collision map (cycles):\n", dev1_id, dev2_id);
	PRINT_FW(cl_hw, "-------------------------------------\n");
	PRINT_FW(cl_hw, "|         | Dev%d Tx    | Dev%d Rx    |\n", dev2_id, dev2_id);
	PRINT_FW(cl_hw, "|---------+------------+------------|\n");
	PRINT_FW(cl_hw, "| Dev%d Tx | %10u | %10u |\n",
		 dev1_id,
		 le32_to_cpu(pta_stats->dev_1_tx_dev_2_tx_collision),
		 le32_to_cpu(pta_stats->dev_1_tx_dev_2_rx_collision));
	PRINT_FW(cl_hw, "|---------+------------+------------|\n");
	PRINT_FW(cl_hw, "| Dev%d Rx | %10u | %10u |\n",
		 dev1_id,
		 le32_to_cpu(pta_stats->dev_1_rx_dev_2_tx_collision),
		 le32_to_cpu(pta_stats->dev_1_rx_dev_2_rx_collision));
	PRINT_FW(cl_hw, "-------------------------------------\n");
	PRINT_FW(cl_hw, "Device IDs: 0=WiFi, 1=BTC, 2=Ext1, 3=Ext2\n\n");
}

static void cl_print_stats_handler(struct work_struct *ws)
{
	struct cl_print_stats_work *stats_work = container_of(ws, struct cl_print_stats_work, ws);
	struct cl_hw *cl_hw = stats_work->cl_hw;
	u32 dbg_info_type = stats_work->dbg_info_type;

	if (dbg_info_type == DBG_INFO_TX_STATS)
		cl_print_tx_stats(cl_hw);
	else if (dbg_info_type == DBG_INFO_BCN_STATS)
		cl_print_bcn_stats(cl_hw);
	else if (dbg_info_type == DBG_INFO_RX_STATS)
		cl_print_rx_stats(cl_hw);
	else if (dbg_info_type == DBG_INFO_DYN_CAL_STATS)
		cl_print_dyn_calib_stats(cl_hw);
	else if (dbg_info_type == DBG_INFO_RATE_FALLBACK_STATS)
		cl_print_rate_fallback_stats(cl_hw);
	else if (dbg_info_type == DBG_INFO_BF)
		cl_print_bf_stats(cl_hw);
	else if (dbg_info_type == DBG_INFO_TRIGGER_FLOW)
		cl_print_trigger_flow_stats(cl_hw);
	else if (dbg_info_type == DBG_INFO_PTA_STATS)
		cl_print_pta_stats(cl_hw);

	if (IS_PCI_BUS_TYPE(cl_hw->chip))
		cl_ipc_dbginfobuf_push(cl_hw->ipc_env, cl_hw->dbginfo.dma_addr);
	else
		cl_usb_dbginfobuf_push(cl_hw);
	kfree(stats_work);
}

static void cl_schedule_print_stats(struct cl_hw *cl_hw, u32 dbg_info_type)
{
	struct cl_print_stats_work *stats_work =
		kzalloc(sizeof(*stats_work), GFP_ATOMIC);

	if (stats_work) {
		INIT_WORK(&stats_work->ws, cl_print_stats_handler);
		stats_work->cl_hw = cl_hw;
		stats_work->dbg_info_type = dbg_info_type;

		/* Schedule work, the work will be executed in the background */
		queue_work(cl_hw->drv_workqueue, &stats_work->ws);
	} else {
		cl_dbg_err(cl_hw, "stats_work allocation failed\n");
	}
}

void cl_fw_dbg_handler(struct cl_hw *cl_hw)
{
	struct dbg_info *dbg_info = NULL;

	/* Function called upon DBG_INFO_IND message reception. */
	dma_sync_single_for_device(cl_hw->chip->dev, cl_hw->dbginfo.dma_addr,
				   cl_hw->dbginfo.bufsz, DMA_FROM_DEVICE);
	dbg_info = (struct dbg_info *)cl_hw->dbginfo.buf;

	if (dbg_info->u.type == DBG_INFO_DUMP) {
		cl_dbg_info(cl_hw, "type %u): dump received\n",
			    cl_hw->dbginfo.buf->u.dump.general_data.error_type);
		cl_um_helper_trigger(cl_hw);
	} else if (dbg_info->u.type < DBG_INFO_MAX) {
		cl_schedule_print_stats(cl_hw, dbg_info->u.type);
	} else {
		cl_dbg_err(cl_hw, "Debug info wrong type - %u\n", dbg_info->u.type);
	}
}

static int cl_fw_dbg_cli_help(struct cl_hw *cl_hw)
{
	char *buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!buf)
		return -ENOMEM;

	snprintf(buf, PAGE_SIZE,
		 "fw usage:\n"
		 "-a : Trigger assert error (echo ASSERT_ERR > errsim)\n"
		 "-b : Trigger assert recovery (echo 1 > test_mode)\n"
		 "-c : Print mib counters\n"
		 "-d : Set trigger-based debug statistics [0-dis/1-en]\n"
		 "-e : Force trigger on sta del [0-dis/1-en]\n"
		 "-m : Trigger firmware dump (echo 1 > mactrace)\n"
		 "-s : Print lmac statistics (echo param > stat_print)\n"
		 "-t : Test mode command (cmd + 0 to 5 parameters)\n"
		 "-u : Print umac statistics\n");

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

int cl_fw_dbg_cli(struct cl_hw *cl_hw, struct cli_params *cli_params)
{
	u32 expected_params = 0;
	bool assert_err = false;
	bool assert_rec = false;
	bool dbg_tb_stats = false;
	bool sta_del_force_trig = false;
	bool mactrace = false;
	bool lmac_stat_print = false;
	bool mib_print = false;
	bool test_mode = false;
	bool umac_stat_print = false;
	bool check_params_num = true;

	switch (cli_params->option) {
	case 'a':
		assert_err = true;
		expected_params = 0;
		break;
	case 'b':
		assert_rec = true;
		expected_params = 0;
		break;
	case 'c':
		mib_print = true;
		expected_params = 0;
		break;
	case 'd':
		dbg_tb_stats = true;
		expected_params = 1;
		break;
	case 'e':
		sta_del_force_trig = true;
		expected_params = 1;
		break;
	case 'm':
		mactrace = true;
		expected_params = 0;
		break;
	case 's':
		lmac_stat_print = true;
		check_params_num = false;
		break;
	case 't':
		test_mode = true;
		check_params_num = false;
		break;
	case 'u':
		umac_stat_print = true;
		expected_params = 0;
		break;
	case '?':
		return cl_fw_dbg_cli_help(cl_hw);
	default:
		cl_dbg_err(cl_hw, "Illegal option (%c) - try '?' for help\n", cli_params->option);
		goto out_err;
	}

	if (check_params_num && expected_params != cli_params->num_params) {
		cl_dbg_err(cl_hw, "Wrong number of arguments (expected %u) (actual %u)\n",
			   expected_params, cli_params->num_params);
		goto out_err;
	}

	if (assert_err) {
		cl_msg_tx_key_del(cl_hw, 0xFF);
		return 0;
	}

	if (assert_rec) {
		u32 params[TEST_MODE_PARAM_MAX + 1] = {1, 0, 0, 0, 0, 0};

		cl_msg_tx_dbg_test_mode(cl_hw, params);
		return 0;
	}

	if (dbg_tb_stats) {
		cl_hw->tb_stats.enable = (bool)cli_params->params[0];
		pr_debug("TB statistics %s\n", cl_hw->tb_stats.enable ? "enable" : "disable");
		return 0;
	}

	if (sta_del_force_trig) {
		cl_hw->sta_del_force_trig = (bool)cli_params->params[0];
		pr_debug("STA del trigger %s\n", cl_hw->sta_del_force_trig ? "enable" : "disable");
		return 0;
	}

	if (mactrace) {
		cl_msg_tx_dbg_trigger(cl_hw, "Force trigger");
		return 0;
	}

	if (lmac_stat_print) {
		u32 bitmap = (u32)cli_params->params[0];

		cl_msg_tx_dbg_print_stats(cl_hw, bitmap,
					  (u32)cli_params->params[1],
					  (u32)cli_params->params[2],
					  (u32)cli_params->params[3],
					  (u32)cli_params->params[4]);
		return 0;
	}

	if (test_mode) {
		u32 params[TEST_MODE_PARAM_MAX + 1] = {0};
		u8 i;

		if (cli_params->num_params == 0 ||
		    cli_params->num_params > TEST_MODE_PARAM_MAX + 1) {
			cl_dbg_err(cl_hw, "Test mode expects cmd + 0 to 5 parameters\n");
			goto out_err;
		}

		for (i = 0; i < cli_params->num_params; i++)
			params[i] = (u32)cli_params->params[i];

		cl_msg_tx_dbg_test_mode(cl_hw, params);
		return 0;
	}

	if (mib_print) {
		cl_mib_cntrs_dump(cl_hw);
		return 0;
	}

	if (umac_stat_print) {
		chip_ops_print_umac_stats(cl_hw->chip);

		return 0;
	}

out_err:
	return -EIO;
}

static void cl_fw_dbg_check_params(struct cl_hw *cl_hw, struct file *filp,
				   struct dbg_error_trace_info_drv *dump)
{
	int is_mismatch = false;
	struct dbg_meta_data *dbg_metadata = &dump->common_info.dbg_metadata;

	if (le32_to_cpu(dbg_metadata->lmac_req_buf_size) !=
	    sizeof(struct dbg_error_trace_info_drv) ||
	    dbg_metadata->physical_queue_cnt != CL_MAX_BA_PHYSICAL_QUEUE_CNT ||
	    dbg_metadata->agg_index_max != AGG_IDX_MAX ||
	    dbg_metadata->ce_ac_max != CE_AC_MAX ||
	    dbg_metadata->mu_user_max != MU_MAX_STREAMS ||
	    dbg_metadata->txl_exch_trace_depth != DBG_TXL_FRAME_EXCH_TRACE_DEPTH ||
	    le16_to_cpu(dbg_metadata->mac_hw_regs_max) != HAL_MACHW_REG_NUM ||
	    le16_to_cpu(dbg_metadata->la_conf_len) != LA_CONF_LEN ||
	    le16_to_cpu(dbg_metadata->phy_hw_regs_max) != PHY_HW_DBG_REGS_CNT)
		is_mismatch = true;

	if (is_mismatch) {
		fw_snprintf(cl_hw, filp, "\nWarning!!!!\n");
		fw_snprintf(cl_hw, filp, "DBG metadata mismatch bwtween FW & DRV!!!!\n");
	}

	if (le32_to_cpu(dbg_metadata->lmac_req_buf_size) !=
	    (sizeof(struct dbg_error_trace_info_drv)))
		fw_snprintf(cl_hw, filp, "FW buf size       %u expected %zu\n",
			    le32_to_cpu(dbg_metadata->lmac_req_buf_size),
			    (sizeof(struct dbg_error_trace_info_drv)));

	if (dbg_metadata->physical_queue_cnt != CL_MAX_BA_PHYSICAL_QUEUE_CNT)
		fw_snprintf(cl_hw, filp, "physical queue cn %u expected %u\n",
			    dbg_metadata->physical_queue_cnt, CL_MAX_BA_PHYSICAL_QUEUE_CNT);

	if (dbg_metadata->agg_index_max != AGG_IDX_MAX)
		fw_snprintf(cl_hw, filp, "agg idx max       %u expected %u\n",
			    dbg_metadata->agg_index_max, AGG_IDX_MAX);

	if (dbg_metadata->ce_ac_max != CE_AC_MAX)
		fw_snprintf(cl_hw, filp, "ac max            %u expected %u\n",
			    dbg_metadata->ce_ac_max, CE_AC_MAX);

	if (dbg_metadata->mu_user_max != MU_MAX_STREAMS)
		fw_snprintf(cl_hw, filp, "MU MAX            %u expected %u\n",
			    dbg_metadata->mu_user_max, MU_MAX_STREAMS);

	if (dbg_metadata->txl_exch_trace_depth != DBG_TXL_FRAME_EXCH_TRACE_DEPTH)
		fw_snprintf(cl_hw, filp, "txl trace depth   %u expected %u\n",
			    dbg_metadata->txl_exch_trace_depth, DBG_TXL_FRAME_EXCH_TRACE_DEPTH);

	if (le16_to_cpu(dbg_metadata->mac_hw_regs_max) != HAL_MACHW_REG_NUM)
		fw_snprintf(cl_hw, filp, "MAC HW regs cnt   %u expected %u\n",
			    le16_to_cpu(dbg_metadata->mac_hw_regs_max), HAL_MACHW_REG_NUM);

	if (le16_to_cpu(dbg_metadata->phy_hw_regs_max) != PHY_HW_DBG_REGS_CNT)
		fw_snprintf(cl_hw, filp, "PHY HW regs       %u expected %u\n",
			    le16_to_cpu(dbg_metadata->phy_hw_regs_max), PHY_HW_DBG_REGS_CNT);

	if (le16_to_cpu(dbg_metadata->la_conf_len) != LA_CONF_LEN)
		fw_snprintf(cl_hw, filp, "LA conf len       %u expected %u\n",
			    le16_to_cpu(dbg_metadata->la_conf_len), LA_CONF_LEN);
}

static void cl_dbg_policy_table_print(struct cl_hw *cl_hw,
				      struct file *filp,
				      struct tx_policy_tbl *policy_table_ptr,
				      u32 policy_table_addr)
{
	fw_snprintf(cl_hw, filp, "================================================== Policy Table 0x%x =========================================================\n",
		    policy_table_addr);
	fw_snprintf(cl_hw, filp, "| upatterntx         = 0x%08x| phycntrlinfo1      = 0x%08x| phycntrlinfo2     = 0x%08x| maccntrlinfo1      = 0x%08x|\n",
		    policy_table_ptr->upatterntx,
		    policy_table_ptr->phycntrlinfo1,
		    policy_table_ptr->phycntrlinfo2,
		    policy_table_ptr->maccntrlinfo1);
	fw_snprintf(cl_hw, filp, "| maccntrlinfo2      = 0x%08x| ratecntrlinfo[0]   = 0x%08x| ratecntrlinfo[1]  = 0x%08x| ratecntrlinfo[2]   = 0x%08x|\n",
		    policy_table_ptr->maccntrlinfo2,
		    policy_table_ptr->ratecntrlinfo[0],
		    policy_table_ptr->ratecntrlinfo[1],
		    policy_table_ptr->ratecntrlinfo[2]);
	fw_snprintf(cl_hw, filp, "| ratecntrlinfo[3]   = 0x%08x| phycntrlinfo3      = 0x%08x| phycntrlinfo4     = 0x%08x| phycntrlinfo5      = 0x%08x|\n",
		    policy_table_ptr->ratecntrlinfo[3],
		    policy_table_ptr->phycntrlinfo3,
		    policy_table_ptr->phycntrlinfo4,
		    policy_table_ptr->phycntrlinfo5);
	fw_snprintf(cl_hw, filp, "| stationinfo        = 0x%08x| ratecntrlinfohe[0] = 0x%08x| ratecntrlinfohe[1]= 0x%08x| ratecntrlinfohe[2] = 0x%08x|\n",
		    policy_table_ptr->stationinfo,
		    policy_table_ptr->ratecntrlinfohe[0],
		    policy_table_ptr->ratecntrlinfohe[1],
		    policy_table_ptr->ratecntrlinfohe[2]);
	fw_snprintf(cl_hw, filp, "| ratecntrlinfohe[3] = 0x%08x| maccntrlinfo3      = 0x%08x| triggercommoninfo = 0x%08x| trigperuserinfo[0] = 0x%08x|\n",
		    policy_table_ptr->ratecntrlinfohe[3],
		    policy_table_ptr->maccntrlinfo3,
		    policy_table_ptr->triggercommoninfo,
		    policy_table_ptr->triggerperuserinfo[0]);
	fw_snprintf(cl_hw, filp, "| trigperuserinfo[1] = 0x%08x| trigperuserinfo[2] = 0x%08x| trigperuserinfo[3]= 0x%08x| trigperuserinfo[4] = 0x%08x|\n",
		    policy_table_ptr->triggerperuserinfo[1],
		    policy_table_ptr->triggerperuserinfo[2],
		    policy_table_ptr->triggerperuserinfo[3],
		    policy_table_ptr->triggerperuserinfo[4]);
	fw_snprintf(cl_hw, filp, "| trigperuserinfo[5] = 0x%08x| trigperuserinfo[6] = 0x%08x| trigperuserinfo[7]= 0x%08x|\n",
		    policy_table_ptr->triggerperuserinfo[5],
		    policy_table_ptr->triggerperuserinfo[6],
		    policy_table_ptr->triggerperuserinfo[7]);
	fw_snprintf(cl_hw, filp, "| triginforallocau0u3= 0x%08x| triginforallocau4u7= 0x%08x |\n",
		    policy_table_ptr->triggerinforuallocationu0u3,
		    policy_table_ptr->triggerinforuallocationu4u7);
	fw_snprintf(cl_hw, filp, "====================================================================================================================================\n\n");
}

static void cl_dbg_thd_print(struct cl_hw *cl_hw, struct file *filp,
			     struct tx_hd *thd_ptr, u32 thd_addr)
{
	fw_snprintf(cl_hw, filp, "===============================================       THD 0x%x      ===============================================\n",
		    thd_addr);
	fw_snprintf(cl_hw, filp, "| upatterntx   = 0x%08x | nextfrmexseq_ptr = 0x%08x | nextmpdudesc_ptr = 0x%08x | first_pbd_ptr = 0x%08x|\n",
		    thd_ptr->upatterntx,
		    thd_ptr->nextfrmexseq_ptr,
		    thd_ptr->nextmpdudesc_ptr,
		    thd_ptr->first_pbd_ptr);
	fw_snprintf(cl_hw, filp, "| datastartptr = 0x%08x | dataendptr       = 0x%08x | frmlen           = 0x%08x | spacinginfo   = 0x%08x|\n",
		    thd_ptr->datastartptr,
		    thd_ptr->dataendptr,
		    thd_ptr->frmlen,
		    thd_ptr->spacinginfo);
	fw_snprintf(cl_hw, filp, "| phyctrlinfo1 = 0x%08x | policyentryaddr  = 0x%08x | macctrlinfo1     = 0x%08x | macctrlinfo2  = 0x%08x|\n",
		    thd_ptr->phyctrlinfo1,
		    thd_ptr->policyentryaddr,
		    thd_ptr->macctrlinfo1,
		    thd_ptr->macctrlinfo2);
	fw_snprintf(cl_hw, filp, "| statinfo     = 0x%08x | phyctrlinfo2     = 0x%08x |\n",
		    thd_ptr->statinfo,
		    thd_ptr->phyctrlinfo2);
	fw_snprintf(cl_hw, filp, "=========================================================================================================================\n\n");
}

static void cl_dbg_pbd_print(struct cl_hw *cl_hw, struct file *filp,
			     struct tx_pbd *pbd_ptr, u32 pbd_addr)
{
	fw_snprintf(cl_hw, filp, "==================================================      PBD 0x%x     =================================================\n",
		    pbd_addr);
	fw_snprintf(cl_hw, filp, "| upatterntx = 0x%08x | next = 0x%08x| datastartptr = 0x%08x| dataendptr = 0x%08x| bufctrlinfo = 0x%08x|\n",
		    pbd_ptr->upatterntx,
		    pbd_ptr->next,
		    pbd_ptr->datastartptr,
		    pbd_ptr->dataendptr,
		    pbd_ptr->bufctrlinfo);
	fw_snprintf(cl_hw, filp, "============================================================================================================================\n\n");
}

static void cl_dbg_dump_txm_regs(struct cl_hw *cl_hw, struct file *filp,
				 struct dbg_error_trace_info_drv *dump)
{
	int stream_idx;
	struct dbg_fw_info *fw_info = &dump->common_info.fw_info;

	for (stream_idx = 0; stream_idx < AGG_IDX_MAX; ++stream_idx) {
		struct dbg_txm_regs *txm_regs;

		if (!fw_info->txlist_info_agg[stream_idx].curr_session_idx)
			continue;

		txm_regs = &dump->common_info.hw_info.txm_regs[stream_idx];
		fw_snprintf(cl_hw, filp, "#### TXM stream %u Registers\n", stream_idx);
		fw_snprintf(cl_hw, filp, "|--------------------------------------------------------------------|\n");
		fw_snprintf(cl_hw, filp, "| HW state = %3u FW state = %3u SPX state = %3u free buff state = %3u|\n",
			    txm_regs->hw_state, txm_regs->fw_state, txm_regs->spx_state, txm_regs->free_buf_state);
		fw_snprintf(cl_hw, filp, "| MPDU cnt = %3u LLI cnt  = %3u LLI done mpdu num = %3u  reason = %3u|\n",
			    txm_regs->mpdu_cnt, txm_regs->lli_cnt, txm_regs->lli_done_mpdu_num, txm_regs->lli_done_reason);
		fw_snprintf(cl_hw, filp, "| active bytes   = 0x%08x prefetch bytes = 0x%08x            |\n",
			    txm_regs->active_bytes, txm_regs->prefetch_bytes);
		fw_snprintf(cl_hw, filp, "| last THD: addr = 0x%x MPDU number = %3u underrun cnt = %3u   |\n",
			    txm_regs->last_thd_done_addr, txm_regs->last_thd_done_mpdu_num, txm_regs->underrun_cnt);
		fw_snprintf(cl_hw, filp, "|--------------------------------------------------------------------|\n\n");
	}
}

static void cl_dbg_dump_machw_regs(struct cl_hw *cl_hw, struct file *filp,
				   struct dbg_error_trace_info_drv *dump)
{
	u8 i = 0;
	struct dbg_hw_reg_info *hw_info = &dump->common_info.hw_info;

	const char *hal_machw_reg_str[HAL_MACHW_REG_NUM] = {
		[HAL_MACHW_AGGR_STATUS]                    = "AGGR_STATUS",
		[HAL_MACHW_DEBUG_HWSM_1]                   = "DBG_HWSM_1",
		[HAL_MACHW_DEBUG_HWSM_2]                   = "DBG_HWSM_2",
		[HAL_MACHW_DEBUG_HWSM_3]                   = "DBG_HWSM_3",
		[HAL_MACHW_DMA_STATUS_1]                   = "DMA_STATUS_1",
		[HAL_MACHW_DMA_STATUS_2]                   = "DMA_STATUS_2",
		[HAL_MACHW_DMA_STATUS_3]                   = "DMA_STATUS_3",
		[HAL_MACHW_DMA_STATUS_4]                   = "DMA_STATUS_4",
		[HAL_MACHW_RX_HEADER_H_PTR]                = "RX_HEADER_HEAD_PTR",
		[HAL_MACHW_RX_PAYLOAD_H_PTR]               = "RX_PAYLOAD_HEAD_PTR",
		[HAL_MACHW_DEBUG_BCN_S_PTR]                = "DBG_BCN_STATUS_PTR",
		[HAL_MACHW_DEBUG_AC0_S_PTR]                = "DBG_AC_0_STATUS_PTR",
		[HAL_MACHW_DEBUG_AC1_S_PTR]                = "DBG_AC_1_STATUS_PTR",
		[HAL_MACHW_DEBUG_AC2_S_PTR]                = "DBG_AC_2_STATUS_PTR",
		[HAL_MACHW_DEBUG_AC3_S_PTR]                = "DBG_AC_3_STATUS_PTR",
		[HAL_MACHW_DEBUG_HTP_S_PTR]                = "DBG_HTP_STATUS_PTR",
		[HAL_MACHW_DEBUG_TX_C_PTR]                 = "DBG_TX_CURRENT_PTR",
		[HAL_MACHW_DEBUG_RX_HDR_C_PTR]             = "DBG_RX_HDR_CURRENT_PTR",
		[HAL_MACHW_DEBUG_RX_PAY_C_PTR]             = "DBG_RX_PAY_CURRENT_PTR",
		[HAL_MACHW_MU0_TX_POWER_LEVEL_DELTA_1]     = "DBG_MU0_TX_PWR_LEVEL_DELTA_1",
		[HAL_MACHW_MU0_TX_POWER_LEVEL_DELTA_2]     = "DBG_MU0_TX_PWR_LEVEL_DELTA_2",
		[HAL_MACHW_POWER_BW_CALIB_FACTOR]          = "DBG_TX_POWER_BW_CALIB_FACTOR",
		[HAL_MACHW_TX_POWER_ANTENNA_FACTOR_1_ADDR] = "DBG_tX_POWER_ANT_FACTOR_1",
		[HAL_MACHW_TX_POWER_ANTENNA_FACTOR_2_ADDR] = "DBG_TX_POWER_ANT_FACTOR_2"
	};

	fw_snprintf(cl_hw, filp, "\n##### MAC HW regs ####\n");

	for (i = 0; i < HAL_MACHW_REG_NUM; ++i)
		fw_snprintf(cl_hw, filp, "%30s = 0x%08x\n",
			    hal_machw_reg_str[i], hw_info->mac_hw_reg[i]);

	fw_snprintf(cl_hw, filp, "#########################\n\n");

	fw_snprintf(cl_hw, filp, "############# MAC HW Secondary FSMs #############\n");
	fw_snprintf(cl_hw, filp, "|---------------------------------------------------------|\n");
	fw_snprintf(cl_hw, filp, "|MU IDX|%12s|%12s|%12s|%11s|\n",
		    hal_machw_reg_str[HAL_MACHW_AGGR_STATUS],
		    hal_machw_reg_str[HAL_MACHW_DEBUG_HWSM_1],
		    hal_machw_reg_str[HAL_MACHW_DEBUG_HWSM_2],
		    hal_machw_reg_str[HAL_MACHW_DEBUG_HWSM_3]);

	fw_snprintf(cl_hw, filp, "|---------------------------------------------------------|\n\n");

	/* Write THD data if valid */
	for (i = HAL_MACHW_DEBUG_BCN_S_PTR; i <= HAL_MACHW_DEBUG_TX_C_PTR; ++i)
		if (hw_info->mac_hw_reg[i]) {
			u8 thd_idx = i - HAL_MACHW_DEBUG_BCN_S_PTR;

			cl_dbg_thd_print(cl_hw, filp, &dump->machw_thd_info.thd[thd_idx],
					 hw_info->mac_hw_reg[i]);
		}

	cl_dbg_dump_txm_regs(cl_hw, filp, dump);
}

static void cl_dbg_dump_phyhw_regs(struct cl_hw *cl_hw, struct file *filp,
				   struct dbg_error_trace_info_drv *dump)
{
	int i = 0;
	const char *phy_hw_mpu_reg_str[PHY_HW_DBG_REGS_CNT] = {
		[MPU_COMMON_FORMAT]       = "MPU_COMMON_FORMAT",
		[MPU_COMMON_FIELD_CTRL]   = "MPU_COMMON_FIELD_CTRL",
		[MPU_COMMON_LEGACY_INFO]  = "MPU_COMMON_LEGACY_INFO",
		[MPU_COMMON_COMMON_CFG_1] = "MPU_COMMON_COMMON_CFG_1",
		[MPU_COMMON_COMMON_CFG_2] = "MPU_COMMON_COMMON_CFG_2",
		[MPU_COMMON_COMMON_CFG_3] = "MPU_COMMON_COMMON_CFG_3",
		[MPU_COMMON_HE_CFG_1]     = "MPU_COMMON_HE_CFG_1",
		[MPU_COMMON_HE_CFG_2]     = "MPU_COMMON_HE_CFG_2",
		[MPU_COMMON_INT_STAT_RAW] = "MPU_COMMON_INT_STAT_RAW",
		[RIU_CCAGENSTAT]          = "RIU_CCAGENSTAT",
	};

	fw_snprintf(cl_hw, filp, "##### PHY HW regs ####\n");

	for (i = 0; i < PHY_HW_DBG_REGS_CNT; ++i)
		fw_snprintf(cl_hw, filp, "%25s = 0x%08x\n",
			    phy_hw_mpu_reg_str[i], dump->common_info.hw_info.phy_mpu_hw_reg[i]);

	fw_snprintf(cl_hw, filp, "#########################\n\n");
}

static void cl_dbg_dump_ac_info(struct cl_hw *cl_hw, struct file *filp,
				struct dbg_error_trace_info_drv *dump)
{
	int i = 0;
	struct dbg_fw_info *fw_info = &dump->common_info.fw_info;
	const char *fw_tx_state_str[CE_TXL_TX_PATH_MAX] = {
		[CE_TXL_TX_PATH_IDLE]                  = "PATH_IDLE",
		[CE_TXL_TX_PATH_START]                 = "PATH_START",
		[CE_TXL_TX_PATH_POST_START_DOWNLOAD]   = "POST_START_DOWNLOAD",
		[CE_TXL_TX_PATH_TX_DATA_DOWNLOADING]   = "TX_DATA_DOWNLOADING",
		[CE_TXL_TX_PATH_MU_RECOVERY]           = "MU_RECOVERY",
		[CE_TXL_TX_PATH_LAST_DOWNLOADING]      = "LAST_DOWNLOADING",
		[CE_TXL_TX_PATH_NEXT_SESSION_PREPARED] = "NEXT_SESSION_PREP",
		[CE_TXL_TX_PATH_MU_NEXT_JOB_READY]     = "MU_NEXT_JOB_READY",
	};

	fw_snprintf(cl_hw, filp, "\n#####  Per AC info  ####\n");
	fw_snprintf(cl_hw, filp, "|-----------------------------------------------------|\n");
	fw_snprintf(cl_hw, filp, "|AC|session|phys queue|check_state|   TX path state   |\n");

	for (i = 0; i < CE_AC_MAX; ++i) {
		u32 session_idx = (fw_info->ac_info[i].active_session != FW_DBG_INVALID_SESSION) ?
			fw_info->ac_info[i].active_session : 0;

		fw_snprintf(cl_hw, filp,
			    "|--+-------+----------+-----------+-------------------|\n");
		fw_snprintf(cl_hw, filp, "|%2u|%7u|%10u|%11u|%19s|\n",
			    i,
			    session_idx,
			    fw_info->ac_info[i].physical_queue_idx,
			    fw_info->ac_info[i].chk_state,
			    fw_tx_state_str[fw_info->ac_info[i].tx_path_state]);
	}

	fw_snprintf(cl_hw, filp, "|-----------------------------------------------------|\n");
}

static void cl_dbg_dump_single_tx_list_info(struct cl_hw *cl_hw, struct file *filp,
					    struct dbg_error_trace_info_drv *dump)
{
	int i = 0;
	struct dbg_fw_info *fw_info = &dump->common_info.fw_info;

	fw_snprintf(cl_hw, filp, "\n##### Singles txdesc lists info ####\n");
	fw_snprintf(cl_hw, filp, "|----|---------|-------------|--------------|\n");
	fw_snprintf(cl_hw, filp, "| AC | pending | downloading | transmitting |\n");
	fw_snprintf(cl_hw, filp, "|----|---------|-------------|--------------|\n");

	for (i = 0; i < IPC_TX_QUEUE_CNT; ++i) {
		fw_snprintf(cl_hw, filp, "|%4u|%9u|%13u|%14u|\n",
			    i,
			    fw_info->txlist_info_singles[i].pending_cnt,
			    fw_info->txlist_info_singles[i].download_cnt,
			    fw_info->txlist_info_singles[i].transmit_cnt);

		fw_snprintf(cl_hw, filp, "|----|---------|-------------|--------------|\n");
	}
}

static void cl_dbg_dump_agg_tx_usb_retry_info(struct cl_hw *cl_hw, struct file *filp,
					      struct dbg_error_trace_info_drv *dump)
{
	struct dbg_fw_info *fw_info = &dump->common_info.fw_info;

	fw_snprintf(cl_hw, filp,
		    "\n##### USB Agg txdesc retry lists info ####\n");
	fw_snprintf(cl_hw, filp,
		    "|-----------------------------------------------------------------------------|\n");
	fw_snprintf(cl_hw, filp,
		    "|session|pending|pending|transmit|transmit|wait4ba|wait4ba|next     |next     |\n");
	fw_snprintf(cl_hw, filp,
		    "|       |0      |1      |0       |1       |0      |1      |pending-0|pending-1|\n");
	fw_snprintf(cl_hw, filp,
		    "|-----------------------------------------------------------------------------|\n");

	fw_snprintf(cl_hw, filp, "|%7u|%7u|%7u|%8u|%8u|%7u|%7u|%9u|%9u|\n",
		    fw_info->usb_retry_txlist_info.session_idx,
		    fw_info->usb_retry_txlist_info.curr_pending_cnt[0],
		    fw_info->usb_retry_txlist_info.curr_pending_cnt[1],
		    fw_info->usb_retry_txlist_info.transmit_cnt[0],
		    fw_info->usb_retry_txlist_info.transmit_cnt[1],
		    fw_info->usb_retry_txlist_info.wait_for_ba_cnt[0],
		    fw_info->usb_retry_txlist_info.wait_for_ba_cnt[1],
		    fw_info->usb_retry_txlist_info.next_pending_cnt[0],
		    fw_info->usb_retry_txlist_info.next_pending_cnt[1]);

	fw_snprintf(cl_hw, filp,
		    "|-----------------------------------------------------------------------------|\n");
}

static void cl_dbg_dump_agg_tx_list_info(struct cl_hw *cl_hw, struct file *filp,
					 struct dbg_error_trace_info_drv *dump)
{
	int i = 0;
	struct dbg_fw_info *fw_info = &dump->common_info.fw_info;

	fw_snprintf(cl_hw, filp,
		    "\n##### Agg txdesc lists info ####\n");
	fw_snprintf(cl_hw, filp,
		    "|-------------------------------------------------------------|\n");
	fw_snprintf(cl_hw, filp,
		    "|idx|session|pending|download|transmit|wait4ba|next   |next   |\n");
	fw_snprintf(cl_hw, filp,
		    "|   |       |       |        |        |       |session|pending|\n");
	for (i = 0; i < AGG_IDX_MAX; ++i) {

		fw_snprintf(cl_hw, filp,
			    "|---+-------+-------+--------+--------+-------+-------+-------|\n");
		fw_snprintf(cl_hw, filp, "|%3u|%7u|%7u|%8u|%8u|%7u|%7u|%7u|\n",
			    i,
			    fw_info->txlist_info_agg[i].curr_session_idx,
			    fw_info->txlist_info_agg[i].pending_cnt,
			    fw_info->txlist_info_agg[i].download_cnt,
			    fw_info->txlist_info_agg[i].transmit_cnt,
			    fw_info->txlist_info_agg[i].wait_for_ba_cnt,
			    fw_info->txlist_info_agg[i].next_session_idx,
			    fw_info->txlist_info_agg[i].next_pending_cnt);
	}

	fw_snprintf(cl_hw, filp,
		    "|-------------------------------------------------------------|\n");

	if (IS_USB_BUS_TYPE(cl_hw->chip)) {
		for (i = 0; i < AGG_IDX_MAX; i++) {
			if (fw_info->txlist_info_agg[i].curr_session_idx)
				cl_dbg_dump_agg_tx_usb_retry_info(cl_hw, filp, dump);
		}
	}
}

static void cl_dbg_dump_thd_chains_info(struct cl_hw *cl_hw, struct file *filp,
					struct dbg_error_trace_info_drv *dump, u8 ac)
{
	int i = 0;
	u32 data_offset = 0;
	struct dbg_thd_chains_info *chain_info = &dump->thd_chains_info[ac];
	struct dbg_thd_chains_data *chain_data = &dump->thd_chains_data[ac];
	struct tx_hd *hd;
	struct tx_policy_tbl *policy_tbl;
	struct tx_pbd *pbd;

	while (chain_info->type_array[i] != DBG_CHAINS_INFO_EMPTY) {
		switch (chain_info->type_array[i]) {
		case DBG_CHAINS_INFO_THD:
			hd = (struct tx_hd *)&chain_data->data[data_offset];
			cl_dbg_thd_print(cl_hw, filp, hd, chain_info->elem_address[i]);
			data_offset += sizeof(struct tx_hd);
			break;

		case DBG_CHAINS_INFO_PT:
			policy_tbl = (struct tx_policy_tbl *)&chain_data->data[data_offset];
			cl_dbg_policy_table_print(cl_hw, filp, policy_tbl,
						  chain_info->elem_address[i]);
			data_offset += sizeof(struct tx_policy_tbl);
			break;

		case DBG_CHAINS_INFO_PBD:
			pbd = (struct tx_pbd *)&chain_data->data[data_offset];
			cl_dbg_pbd_print(cl_hw, filp, pbd, chain_info->elem_address[i]);
			data_offset += sizeof(struct tx_pbd);
			break;

		default:
			return;
		}

		i++;
		if (i >= DBG_CHAINS_INFO_ELEM_CNT)
			break;
	}
}

static void cl_dbg_dump_agg_thd_info(struct cl_hw *cl_hw, struct file *filp,
				     struct dbg_error_trace_info_drv *dump, u8 ac, u8 mu_idx)
{
	u32 addr = dump->common_info.agg_thds_addr[ac].rts_cts_thd_addr;

	if (addr) {
		/* RTS CTS THD print */
		fw_snprintf(cl_hw, filp, "\n  RTS CTS THD 0x%x\n", addr);
		cl_dbg_thd_print(cl_hw, filp, &dump->agg_thd_info[ac].rts_cts_thd, addr);
	}

	addr = dump->common_info.agg_thds_addr[ac].athd_addr;
	if (addr) {
		/* ATHD print */
		fw_snprintf(cl_hw, filp, "\n  ATHD 0x%x\n", addr);
		cl_dbg_thd_print(cl_hw, filp, &dump->agg_thd_info[ac].athd, addr);
	}

	addr = dump->common_info.agg_thds_addr[ac].policy_table_addr;
	if (addr) {
		/* Policy Table print */
		fw_snprintf(cl_hw, filp, "  Policy Table 0x%x\n", addr);
		cl_dbg_policy_table_print(cl_hw, filp,
					  &dump->agg_thd_info[ac].policy_table,
					  addr);
	}

	addr = dump->common_info.agg_thds_addr[ac].tf_thd_addr;
	if (addr) {
		/* TF-THD print */
		fw_snprintf(cl_hw, filp, "  TF-THD 0x%x\n", addr);
		cl_dbg_thd_print(cl_hw, filp, &dump->agg_thd_info[ac].tf_thd, addr);
	}

	cl_dbg_dump_thd_chains_info(cl_hw, filp, dump, ac);

	addr = dump->common_info.agg_thds_addr[ac].bar_thd_addr;
	if (addr) {
		/* BAR THD print */
		fw_snprintf(cl_hw, filp, "  BAR THD 0x%x\n", addr);
		cl_dbg_thd_print(cl_hw, filp, &dump->agg_thd_info[ac].bar_thd, addr);
	}
}

static void cl_dbg_dump_thd_info(struct cl_hw *cl_hw, struct file *filp,
				 struct dbg_error_trace_info_drv *dump, u8 ac, u8 mu_idx)
{
	u32 session_idx = dump->common_info.fw_info.ac_info[ac].active_session;

	if (session_idx != FW_DBG_INVALID_SESSION) {
		bool is_agg = ((mu_idx > 0) || (session_idx >= IPC_TX_QUEUE_CNT)) ? true : false;

		if (is_agg)
			cl_dbg_dump_agg_thd_info(cl_hw, filp, dump, ac, mu_idx);
		else
			cl_dbg_dump_thd_chains_info(cl_hw, filp, dump, ac);
	}
}

static void cl_dbg_dump_tx_trace_info(struct cl_hw *cl_hw, struct file *filp,
				      struct dbg_error_trace_info_drv *dump)
{
	int i = 0;
	const char *fw_tx_frame_type_str[CL_DBG_FRAME_TYPE_MAX] = {
		[CL_DBG_FRAME_TYPE_INVALID]          = "UNKNOWN",
		[CL_DBG_FRAME_TYPE_SINGLE]           = "MPDU",
		[CL_DBG_FRAME_TYPE_BEACON]           = "BCN",
		[CL_DBG_FRAME_TYPE_BACKUP_BEACON]    = "BCN_BCK",
		[CL_DBG_FRAME_TYPE_AGG]              = "AMPDU",
		[CL_DBG_FRAME_TYPE_AGG_NEXT_IN_TXOP] = "TXOP",
		[CL_DBG_FRAME_TYPE_AGG_MU]           = "MU_AMPDU",
		[CL_DBG_FRAME_TYPE_TF_AGG]           = "TF_AMPDU",
		[CL_DBG_FRAME_TYPE_TB_QOS_NULL]      = "TB_QOS_NULL",
		[CL_DBG_FRAME_TYPE_TB_SINGLE]        = "TB_SMPDU",
		[CL_DBG_FRAME_TYPE_TB_AGG]           = "TB_AMPDU",
		[CL_DBG_FRAME_TYPE_PS_DATA_NULL]     = "PS_DATA_NULL",
		[CL_DBG_FRAME_TYPE_PS_QOS_NULL]      = "PS_QOS_NULL",
		[CL_DBG_FRAME_TYPE_RTS]              = "RTS",
		[CL_DBG_FRAME_TYPE_CTS]              = "CTS",
		[CL_DBG_FRAME_TYPE_CFEND]            = "CFEND",
		[CL_DBG_FRAME_TYPE_TF_BASIC]         = "BASIC_TF",
		[CL_DBG_FRAME_TYPE_TF_BSRP]          = "BSRP",
		[CL_DBG_FRAME_TYPE_TF_BFRP]          = "BFRP",
		[CL_DBG_FRAME_TYPE_TF_MU_BAR]        = "MU_BAR",
		[CL_DBG_FRAME_TYPE_BFR_POLL]         = "BRP",
		[CL_DBG_FRAME_TYPE_BF_NDPA]          = "BF_NDPA",
		[CL_DBG_FRAME_TYPE_BF_NDP]           = "BF_NDP",
		[CL_DBG_FRAME_TYPE_SENSING_NDP]      = "SENSING_NDP",
	};

	fw_snprintf(cl_hw, filp, "\n#### TX Trace ####\n");

	for (i = 0; i < CE_AC_MAX; ++i) {
		u8 trace_idx = 0, table_idx = 0;
		struct dbg_txl_ac_chain_trace *trace_ptr =
			&dump->common_info.fw_info.txl_ac_chain_trace[i];
		struct cl_dbg_txl_chain_info *data;

		if (trace_ptr->next_chain_index == 0)
			table_idx = DBG_TXL_FRAME_EXCH_TRACE_DEPTH - 1;
		else
			table_idx = trace_ptr->next_chain_index - 1;

		data = &trace_ptr->data[table_idx];

		if (data->count == 0)
			continue;

		fw_snprintf(cl_hw, filp, "\n AC %u\n", i);
		fw_snprintf(cl_hw, filp, "|========|========|==========|==========|==========|======|==========|==========|=====|=======|======|=========|=======|==========|\n");
		fw_snprintf(cl_hw, filp, "|#PPDU   | Type   |First THD | Last THD | Prev THD |Req BW| PTalbe   |PTalbe_HE |queue|Length |#MPDU |Chosen BW|TX time| txstatus |\n");
		fw_snprintf(cl_hw, filp, "|========|========|==========|==========|==========|======|==========|==========|=====|=======|======|=========|=======|==========|\n");

		for (trace_idx = 0; trace_idx < DBG_TXL_FRAME_EXCH_TRACE_DEPTH; ++trace_idx) {
			fw_snprintf(cl_hw, filp,
				    "|%8u|%8s|0x%08x|0x%08x|0x%08x|%6u|0x%08x|0x%08x|%5u|%7u|%6u|%9u|%7u|0x%08x|\n",
				    data->count,
				    fw_tx_frame_type_str[data->frm_type],
				    data->first_thd_ptr,
				    data->last_thd_ptr,
				    data->prev_thd_ptr,
				    data->reqbw,
				    data->rate_ctrl_info,
				    data->rate_ctrl_info_he,
				    data->ce_txq_idx,
				    data->length,
				    data->mpdu_count,
				    data->chbw,
				    data->tx_time,
				    data->txstatus);

			if (!table_idx)
				table_idx = DBG_TXL_FRAME_EXCH_TRACE_DEPTH - 1;
			else
				table_idx--;

			data = &trace_ptr->data[table_idx];
		}

		fw_snprintf(cl_hw, filp, "|========|========|==========|==========|==========|======|==========|==========|=====|=======|======|=========|=======|==========|\n");

		cl_dbg_dump_thd_info(cl_hw, filp, dump, i, 0);
	}
}

static void cl_dbg_dump_error_info(struct cl_hw *cl_hw, struct file *filp,
				   struct dbg_error_trace_info_drv *dump)
{
	struct dbg_print_ind *ind = &dump->common_info.error_info;
	const char *assert_string;
	u16 file_id = le16_to_cpu(ind->file_id);
	u16 line = le16_to_cpu(ind->line);
	u16 has_param = le16_to_cpu(ind->has_param);
	u32 param = has_param ? le32_to_cpu(ind->param) : 0;

	if (file_id && line) {
		fw_snprintf(cl_hw, filp, "ASSERT_TCV%u @ FILE=%u LINE=%u param=0x%08X\n",
			    cl_hw->idx, file_id, line, param);

		/* Get assert string */
		assert_string = cl_dbgfile_get_msg_txt(&cl_hw->dbg_data, file_id, line);
		if (!assert_string)
			assert_string = "ASSERT STRING NOT FOUND";

		fw_snprintf(cl_hw, filp, "%s\n", assert_string);
	} else {
		struct dbg_info *dbg_info = (struct dbg_info *)cl_hw->dbginfo.buf;

		fw_snprintf(cl_hw, filp, "%s\n", dbg_info->u.dump.general_data.error);
	}
}

static void cl_dbg_dump_fw_trace_info(struct cl_hw *cl_hw, struct file *filp,
				      struct dbg_error_trace_info_drv *dump)
{
	int i = 0;

	fw_snprintf(cl_hw, filp, "\n###   FW trace dump   ###\n");
	fw_snprintf(cl_hw, filp, "-----------------------------------------------------------------------------------------\n");
	fw_snprintf(cl_hw, filp, "|idx|   String        | value 1  | value 2  | value 3  | value 4  | value 5  | value 6  |\n");
	fw_snprintf(cl_hw, filp, "|---+-----------------+----------+----------+----------+----------+----------+----------|\n");

	for (i = 0; i < DBG_FW_TRACE_SIZE; ++i) {
		u8 dbg_idx = (dump->common_info.fw_info.fw_trace_idx + i) % DBG_FW_TRACE_SIZE;
		struct dbg_fw_trace *trace = &dump->common_info.fw_info.fw_trace[dbg_idx];
		char *str = trace->string_ptr ? trace->string_char : "NULL";

		fw_snprintf(cl_hw, filp,
			    "|%3u|%17s|0x%08x|0x%08x|0x%08x|0x%08x|0x%08x|0x%08x|\n",
			    i,
			    str,
			    trace->var_1,
			    trace->var_2,
			    trace->var_3,
			    trace->var_4,
			    trace->var_5,
			    trace->var_6);
	}

	fw_snprintf(cl_hw, filp, "-----------------------------------------------------------------------------------------\n");
}

void cl_fw_dbg_dump_file(struct cl_hw *cl_hw)
{
	struct dbg_info *dbg_info = (struct dbg_info *)cl_hw->dbginfo.buf;
	struct dbg_error_trace_info_drv *dump = &dbg_info->u.dump.fw_dump;
	struct cl_fw_dbg *fw_dbg = &cl_hw->fw_dbg;
	char dump_file[CL_PATH_MAX];
	struct file *filp;

	snprintf(dump_file, sizeof(dump_file), "/tmp/dbg_dump_file_tcv_%u.txt", cl_hw->tcv_idx);

	filp = filp_open(dump_file, O_WRONLY | O_CREAT | O_TRUNC, 0600);

	if (IS_ERR(filp))
		return;

	fw_dbg->len = 0;
	fw_dbg->buf = kzalloc(FW_DBG_MAX_BUF, GFP_KERNEL);

	if (!fw_dbg->buf)
		goto out;

	/* Write error string */
	cl_dbg_dump_error_info(cl_hw, filp, dump);

	/* Check parameters */
	cl_fw_dbg_check_params(cl_hw, filp, dump);

	/* Write MAC regs */
	cl_dbg_dump_machw_regs(cl_hw, filp, dump);

	/* Write PHY regs */
	cl_dbg_dump_phyhw_regs(cl_hw, filp, dump);

	/* Write per AC info */
	cl_dbg_dump_ac_info(cl_hw, filp, dump);

	/* Write singles TX lists info */
	cl_dbg_dump_single_tx_list_info(cl_hw, filp, dump);

	/* Write agg TX lists info */
	cl_dbg_dump_agg_tx_list_info(cl_hw, filp, dump);

	/* Write TX trace info */
	cl_dbg_dump_tx_trace_info(cl_hw, filp, dump);

	/* Write FW trace info */
	cl_dbg_dump_fw_trace_info(cl_hw, filp, dump);

	/* Write the remaining characters */
	cl_file_write_buffer(filp, fw_dbg->buf, fw_dbg->len);

	kfree(fw_dbg->buf);

out:
	filp_close(filp, NULL);
}

#define INVALID_AMPDU_CNT U8_MAX

void cl_fw_dbg_trigger_based_init(struct cl_hw *cl_hw)
{
	memset(&cl_hw->tb_stats, 0, sizeof(struct cl_rx_trigger_based_stats));
	cl_hw->tb_stats.ampdu_cnt = INVALID_AMPDU_CNT;
	cl_hw->tb_stats.valid = false;
}

void cl_fw_dbg_trigger_based_update(struct cl_hw *cl_hw,
				    struct hw_rxhdr *rxhdr, __le16 fc)
{
	struct cl_rx_trigger_based_stats *tb_stats = &cl_hw->tb_stats;

	if (!tb_stats->enable)
		return;

	/* New ampdu - can now add size of previous agg */
	if (tb_stats->ampdu_cnt != rxhdr->ampdu_cnt) {
		if (tb_stats->valid) {
			if (unlikely(tb_stats->data_per_agg >= DBG_STATS_MAX_AGG_SIZE))
				cl_dbg_err(cl_hw, "rx trigger_based agg size %u > 256\n",
					   tb_stats->data_per_agg);
			else
				tb_stats->data[tb_stats->data_per_agg]++;

			if (unlikely(tb_stats->qos_null_per_agg > TID_MAX))
				tb_stats->qos_null[TID_MAX + 1]++;
			else
				tb_stats->qos_null[tb_stats->qos_null_per_agg]++;
		}

		tb_stats->valid = false;
		tb_stats->data_per_agg = 0;
		tb_stats->qos_null_per_agg = 0;
		tb_stats->ampdu_cnt = rxhdr->ampdu_cnt;
	}

	/* Count newly arrived mpdu */
	if (rxhdr->format_mod == FORMATMOD_HE_TRIG) {
		if (ieee80211_is_qos_nullfunc(fc))
			tb_stats->qos_null_per_agg += rxhdr->frm_successful_rx;
		else
			tb_stats->data_per_agg += rxhdr->frm_successful_rx;

		tb_stats->total += rxhdr->frm_successful_rx;
		tb_stats->valid = true;
	}
}

void cl_fw_dbg_trigger_based_reset(struct cl_hw *cl_hw)
{
	u32 idx;
	struct cl_rx_trigger_based_stats *tb_stats = &cl_hw->tb_stats;

	tb_stats->total = 0;

	for (idx = 0; idx < DBG_STATS_MAX_AGG_SIZE; idx++)
		tb_stats->data[idx] = 0;

	for (idx = 0; idx < TID_MAX + 2; idx++)
		tb_stats->qos_null[idx] = 0;
}

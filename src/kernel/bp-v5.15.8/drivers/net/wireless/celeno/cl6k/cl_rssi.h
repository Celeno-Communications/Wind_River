/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_RSSI_H
#define CL_RSSI_H

#include "cl_rx.h"
#include "cl_hw.h"
#include "cl_agg_tx_report.h"

#define RX_HDR_RSSI(rxhdr) \
	{(rxhdr)->rssi1, (rxhdr)->rssi2}

void cl_rssi_assoc_init(struct cl_hw *cl_hw);
void cl_rssi_assoc_exit(struct cl_hw *cl_hw);
void cl_rssi_assoc_handle(struct cl_hw *cl_hw, u8 *mac_addr, struct hw_rxhdr *rxhdr);
void cl_rssi_assoc_find(struct cl_hw *cl_hw, struct cl_sta *cl_sta, u8 num_sta);
void cl_rssi_sort_descending(s8 rssi[MAX_ANTENNAS], u8 num_ant);
s8 cl_rssi_calc_equivalent(struct cl_hw *cl_hw, s8 rssi[MAX_ANTENNAS]);
s8 cl_rssi_get_strongest(struct cl_hw *cl_hw, s8 rssi[MAX_ANTENNAS]);
void cl_rssi_block_ack_handler(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
			       struct cl_agg_tx_report *agg_report);
void cl_rssi_raw_rx_handler(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
			    struct hw_rxhdr *rxhdr);
void cl_rssi_rx_handler(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
			struct hw_rxhdr *rxhdr, s8 equivalent_rssi);
void cl_rssi_bw_adjust(struct cl_hw *cl_hw, struct hw_rxhdr *rxhdr, s8 bw_factor);
void cl_rssi_simulate(struct cl_hw *cl_hw, struct hw_rxhdr *rxhdr);
int cl_rssi_cli(struct cl_hw *cl_hw, struct cli_params *cli_params);

#endif /* CL_RSSI_H */

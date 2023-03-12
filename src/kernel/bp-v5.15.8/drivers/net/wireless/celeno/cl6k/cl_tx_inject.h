/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_TX_INJECT_H
#define CL_TX_INJECT_H

#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/kmod.h>
#include <linux/debugfs.h>
#include <linux/string.h>

#include "cl_hw.h"

#define TX_INJECT_AGG_TID         1
#define TX_INJECT_SINGLE_AC       AC_BK
#define TX_INJECT_MAX_STA         IPC_MAX_BA_SESSIONS
#define TX_INJECT_MAX_SKBS        8192
#define TX_INJECT_SKB_LEN_MAX     4096
#define TX_INJECT_SKB_LEN_MIN     16
#define TX_INJECT_SKB_LEN_DEFAULT 1024

extern int ce_tx_inject_real_sta;

void cl_tx_inject_init(struct cl_hw *cl_hw);
void cl_tx_inject_close(struct cl_hw *cl_hw);
void cl_tx_inject_reset(struct cl_hw *cl_hw);
void cl_tx_inject_start(struct cl_hw *cl_hw, u32 tx_cnt);
void cl_tx_inject_start_continuous(struct cl_hw *cl_hw);
void cl_tx_inject_start_agg(struct cl_hw *cl_hw, u32 tx_cnt);
void cl_tx_inject_stop(struct cl_hw *cl_hw);
void cl_tx_inject_stop_in_recovery(struct cl_hw *cl_hw);
void cl_tx_inject_stop_traffic(struct cl_hw *cl_hw);
void cl_tx_inject_stop_ba_session(struct cl_hw *cl_hw, struct cl_sta *cl_sta, u8 tid);
bool cl_tx_inject_is_running(struct cl_hw *cl_hw);
void cl_tx_inject_cfm(struct cl_hw *cl_hw);
void cl_tx_inject_sta_remove(struct cl_hw *cl_hw, struct cl_sta *cl_sta);
void cl_tx_inject_iface_remove(struct cl_hw *cl_hw, struct cl_vif *cl_vif);
int cl_tx_inject_set_length(struct cl_hw *cl_hw, u32 length);
struct sk_buff *cl_tx_inject_alloc_skb(struct cl_hw *cl_hw, struct cl_sta *cl_sta, bool is_agg);

#endif /* CL_TX_INJECT_H */

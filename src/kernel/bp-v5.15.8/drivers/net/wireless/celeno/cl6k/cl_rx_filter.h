/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_RX_FILTER_H
#define CL_RX_FILTER_H

#include "cl_hw.h"
#include "cl_vendor_cmd.h"

/* Field definitions */
#define RX_CNTRL_EN_DUPLICATE_DETECTION_BIT      ((u32)0x80000000)
#define RX_CNTRL_EN_DUPLICATE_DETECTION_POS      31
#define RX_CNTRL_ACCEPT_UNKNOWN_BIT              ((u32)0x40000000)
#define RX_CNTRL_ACCEPT_UNKNOWN_POS              30
#define RX_CNTRL_ACCEPT_OTHER_DATA_FRAMES_BIT    ((u32)0x20000000)
#define RX_CNTRL_ACCEPT_OTHER_DATA_FRAMES_POS    29
#define RX_CNTRL_ACCEPT_QO_S_NULL_BIT            ((u32)0x10000000)
#define RX_CNTRL_ACCEPT_QO_S_NULL_POS            28
#define RX_CNTRL_ACCEPT_QCFWO_DATA_BIT           ((u32)0x08000000)
#define RX_CNTRL_ACCEPT_QCFWO_DATA_POS           27
#define RX_CNTRL_ACCEPT_Q_DATA_BIT               ((u32)0x04000000)
#define RX_CNTRL_ACCEPT_Q_DATA_POS               26
#define RX_CNTRL_ACCEPT_CFWO_DATA_BIT            ((u32)0x02000000)
#define RX_CNTRL_ACCEPT_CFWO_DATA_POS            25
#define RX_CNTRL_ACCEPT_DATA_BIT                 ((u32)0x01000000)
#define RX_CNTRL_ACCEPT_DATA_POS                 24
#define RX_CNTRL_ACCEPT_OTHER_CNTRL_FRAMES_BIT   ((u32)0x00800000)
#define RX_CNTRL_ACCEPT_OTHER_CNTRL_FRAMES_POS   23
#define RX_CNTRL_ACCEPT_CF_END_BIT               ((u32)0x00400000)
#define RX_CNTRL_ACCEPT_CF_END_POS               22
#define RX_CNTRL_ACCEPT_ACK_BIT                  ((u32)0x00200000)
#define RX_CNTRL_ACCEPT_ACK_POS                  21
#define RX_CNTRL_ACCEPT_CTS_BIT                  ((u32)0x00100000)
#define RX_CNTRL_ACCEPT_CTS_POS                  20
#define RX_CNTRL_ACCEPT_RTS_BIT                  ((u32)0x00080000)
#define RX_CNTRL_ACCEPT_RTS_POS                  19
#define RX_CNTRL_ACCEPT_PS_POLL_BIT              ((u32)0x00040000)
#define RX_CNTRL_ACCEPT_PS_POLL_POS              18
#define RX_CNTRL_ACCEPT_BA_BIT                   ((u32)0x00020000)
#define RX_CNTRL_ACCEPT_BA_POS                   17
#define RX_CNTRL_ACCEPT_BAR_BIT                  ((u32)0x00010000)
#define RX_CNTRL_ACCEPT_BAR_POS                  16
#define RX_CNTRL_ACCEPT_OTHER_MGMT_FRAMES_BIT    ((u32)0x00008000)
#define RX_CNTRL_ACCEPT_OTHER_MGMT_FRAMES_POS    15
#define RX_CNTRL_ACCEPT_ALL_BEACON_BIT           ((u32)0x00002000)
#define RX_CNTRL_ACCEPT_ALL_BEACON_POS           13
#define RX_CNTRL_ACCEPT_NOT_EXPECTED_BA_BIT      ((u32)0x00001000)
#define RX_CNTRL_ACCEPT_NOT_EXPECTED_BA_POS      12
#define RX_CNTRL_ACCEPT_DECRYPT_ERROR_FRAMES_BIT ((u32)0x00000800)
#define RX_CNTRL_ACCEPT_DECRYPT_ERROR_FRAMES_POS 11
#define RX_CNTRL_ACCEPT_BEACON_BIT               ((u32)0x00000400)
#define RX_CNTRL_ACCEPT_BEACON_POS               10
#define RX_CNTRL_ACCEPT_PROBE_RESP_BIT           ((u32)0x00000200)
#define RX_CNTRL_ACCEPT_PROBE_RESP_POS           9
#define RX_CNTRL_ACCEPT_PROBE_REQ_BIT            ((u32)0x00000100)
#define RX_CNTRL_ACCEPT_PROBE_REQ_POS            8
#define RX_CNTRL_ACCEPT_MY_UNICAST_BIT           ((u32)0x00000080)
#define RX_CNTRL_ACCEPT_MY_UNICAST_POS           7
#define RX_CNTRL_ACCEPT_UNICAST_BIT              ((u32)0x00000040)
#define RX_CNTRL_ACCEPT_UNICAST_POS              6
#define RX_CNTRL_ACCEPT_ERROR_FRAMES_BIT         ((u32)0x00000020)
#define RX_CNTRL_ACCEPT_ERROR_FRAMES_POS         5
#define RX_CNTRL_ACCEPT_OTHER_BSSID_BIT          ((u32)0x00000010)
#define RX_CNTRL_ACCEPT_OTHER_BSSID_POS          4
#define RX_CNTRL_ACCEPT_BROADCAST_BIT            ((u32)0x00000008)
#define RX_CNTRL_ACCEPT_BROADCAST_POS            3
#define RX_CNTRL_ACCEPT_MULTICAST_BIT            ((u32)0x00000004)
#define RX_CNTRL_ACCEPT_MULTICAST_POS            2
#define RX_CNTRL_DONT_DECRYPT_BIT                ((u32)0x00000002)
#define RX_CNTRL_DONT_DECRYPT_POS                1
#define RX_CNTRL_EXC_UNENCRYPTED_BIT             ((u32)0x00000001)
#define RX_CNTRL_EXC_UNENCRYPTED_POS             0

/* Default MAC Rx filters that cannot be changed by mac80211 */
#define CL_MAC80211_NOT_CHANGEABLE (            \
	RX_CNTRL_ACCEPT_QO_S_NULL_BIT         | \
	RX_CNTRL_ACCEPT_Q_DATA_BIT            | \
	RX_CNTRL_ACCEPT_DATA_BIT              | \
	RX_CNTRL_ACCEPT_OTHER_MGMT_FRAMES_BIT | \
	RX_CNTRL_ACCEPT_MY_UNICAST_BIT        | \
	RX_CNTRL_ACCEPT_BROADCAST_BIT         | \
	RX_CNTRL_ACCEPT_BEACON_BIT            | \
	RX_CNTRL_ACCEPT_PROBE_RESP_BIT          \
	)

int cl_rx_filter_cli(struct cl_hw *cl_hw, struct cli_params *cli_params);
u32 cl_rx_filter_update_flags(struct cl_hw *cl_hw, u32 filter);
void cl_rx_filter_restore_flags(struct cl_hw *cl_hw);
void cl_rx_filter_set_promiscuous_off(unsigned long data);
void cl_rx_filter_set_promiscuous(struct cl_hw *cl_hw);

#endif /* CL_RX_FILTER_H */

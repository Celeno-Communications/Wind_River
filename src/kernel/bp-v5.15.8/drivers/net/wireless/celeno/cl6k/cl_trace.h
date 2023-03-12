/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#undef TRACE_SYSTEM
#define TRACE_SYSTEM cl_trace

#if !defined(_TRACE_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_H

#include <linux/tracepoint.h>

/* Here, we need to include headers for definitions used in TP_PROTO */
#include <net/mac80211.h>
#include <linux/skbuff.h>
#include <linux/ieee80211.h>
#include "cl_rx.h"

/* Add your tracepoint definitions here. */
TRACE_EVENT
(
	cl_trace_start_xmit,
	TP_PROTO(unsigned char cl_hw_idx, struct sk_buff *skb, int buffer_cnt),
	TP_ARGS(cl_hw_idx, skb, buffer_cnt),

	/*
	 * These are not used by lttng. We fill them in to make the
	 * tracepoint available to ftrace and perf as well.
	 */
	TP_STRUCT__entry(),

	TP_fast_assign(),

	TP_printk("%d", 0)
)

TRACE_EVENT
(
	cl_trace_tx_push,
	TP_PROTO(unsigned char cl_hw_idx, struct sk_buff *skb, unsigned char packet_cnt,
		 unsigned short seq_ctrl, unsigned char tid),
	TP_ARGS(cl_hw_idx, skb, packet_cnt, seq_ctrl, tid),
	/*
	 * These are not used by lttng. We fill them in to make the
	 * tracepoint available to ftrace and perf as well.
	 */
	TP_STRUCT__entry(),

	TP_fast_assign(),

	TP_printk("%d", 0)
)

TRACE_EVENT
(
	cl_trace_tx_pci_single_cfm_tasklet_start,
	TP_PROTO(unsigned char cl_hw_idx, unsigned int cfm_read_idx),
	TP_ARGS(cl_hw_idx, cfm_read_idx),

	/*
	 * These are not used by lttng. We fill them in to make the
	 * tracepoint available to ftrace and perf as well.
	 */
	TP_STRUCT__entry(),

	TP_fast_assign(),

	TP_printk("%d", 0)
)

TRACE_EVENT
(
	cl_trace_tx_pci_single_cfm_tasklet_end,
	TP_PROTO(unsigned char cl_hw_idx, unsigned int cfm_read_idx),
	TP_ARGS(cl_hw_idx, cfm_read_idx),

	/*
	 * These are not used by lttng. We fill them in to make the
	 * tracepoint available to ftrace and perf as well.
	 */
	TP_STRUCT__entry(),

	TP_fast_assign(),

	TP_printk("%d", 0)
)

TRACE_EVENT
(
	cl_trace_msg_ind_start,
	TP_PROTO(unsigned char cl_hw_idx, unsigned short msg_id,
		 unsigned long msg_pattern, unsigned long *cfm_flags),
	TP_ARGS(cl_hw_idx, msg_id, msg_pattern, cfm_flags),

	/*
	 * These are not used by lttng. We fill them in to make the
	 * tracepoint available to ftrace and perf as well.
	 */
	TP_STRUCT__entry(),

	TP_fast_assign(),

	TP_printk("%d", 0)
)

TRACE_EVENT
(
	cl_trace_msg_ind_end,
	TP_PROTO(unsigned char cl_hw_idx, unsigned long *cfm_flags),
	TP_ARGS(cl_hw_idx, cfm_flags),

	/*
	 * These are not used by lttng. We fill them in to make the
	 * tracepoint available to ftrace and perf as well.
	 */
	TP_STRUCT__entry(),

	TP_fast_assign(),

	TP_printk("%d", 0)
)

TRACE_EVENT
(
	cl_trace_msg_tasklet_start,
	TP_PROTO(unsigned char cl_hw_idx),
	TP_ARGS(cl_hw_idx),

	/*
	 * These are not used by lttng. We fill them in to make the
	 * tracepoint available to ftrace and perf as well.
	 */
	TP_STRUCT__entry(),

	TP_fast_assign(),

	TP_printk("%d", 0)
)

TRACE_EVENT
(
	cl_trace_msg_tasklet_end,
	TP_PROTO(unsigned char cl_hw_idx, int msg_handled),
	TP_ARGS(cl_hw_idx, msg_handled),

	/*
	 * These are not used by lttng. We fill them in to make the
	 * tracepoint available to ftrace and perf as well.
	 */
	TP_STRUCT__entry(),

	TP_fast_assign(),

	TP_printk("%d", 0)
)

TRACE_EVENT
(
	cl_trace_dbg_tasklet_start,
	TP_PROTO(unsigned char cl_hw_idx),
	TP_ARGS(cl_hw_idx),

	/*
	 * These are not used by lttng. We fill them in to make the
	 * tracepoint available to ftrace and perf as well.
	 */
	TP_STRUCT__entry(),

	TP_fast_assign(),

	TP_printk("%d", 0)
)

TRACE_EVENT
(
	cl_trace_dbg_tasklet_end,
	TP_PROTO(unsigned char cl_hw_idx, int dbg_handled),
	TP_ARGS(cl_hw_idx, dbg_handled),

	/*
	 * These are not used by lttng. We fill them in to make the
	 * tracepoint available to ftrace and perf as well.
	 */
	TP_STRUCT__entry(),

	TP_fast_assign(),

	TP_printk("%d", 0)
)

TRACE_EVENT
(
	cl_trace_tx_agg_cfm_tasklet_start,
	TP_PROTO(unsigned char cl_hw_idx),
	TP_ARGS(cl_hw_idx),

	/*
	 * These are not used by lttng. We fill them in to make the
	 * tracepoint available to ftrace and perf as well.
	 */
	TP_STRUCT__entry(),

	TP_fast_assign(),

	TP_printk("%d", 0)
)

TRACE_EVENT
(
	cl_trace_tx_agg_cfm_tasklet_end,
	TP_PROTO(unsigned char cl_hw_idx, int cfm_handled),
	TP_ARGS(cl_hw_idx, cfm_handled),

	/*
	 * These are not used by lttng. We fill them in to make the
	 * tracepoint available to ftrace and perf as well.
	 */
	TP_STRUCT__entry(),

	TP_fast_assign(),

	TP_printk("%d", 0)
)

TRACE_EVENT
(
	cl_trace_rx_desc_tasklet_start,
	TP_PROTO(unsigned char cl_hw_idx, unsigned int write_idx_rxm, unsigned int write_idx_fw),
	TP_ARGS(cl_hw_idx, write_idx_rxm, write_idx_fw),

	/*
	 * These are not used by lttng. We fill them in to make the
	 * tracepoint available to ftrace and perf as well.
	 */
	TP_STRUCT__entry(),

	TP_fast_assign(),

	TP_printk("%d", 0)
	)

TRACE_EVENT
(
	cl_trace_rx_desc_tasklet_end,
	TP_PROTO(unsigned char cl_hw_idx, unsigned int write_idx_rxm, unsigned int write_idx_fw),
	TP_ARGS(cl_hw_idx, write_idx_rxm, write_idx_fw),

	/*
	 * These are not used by lttng. We fill them in to make the
	 * tracepoint available to ftrace and perf as well.
	 */
	TP_STRUCT__entry(),

	TP_fast_assign(),

	TP_printk("%d", 0)
)

TRACE_EVENT
(
	cl_trace_rx_tasklet_start,
	TP_PROTO(unsigned char cl_hw_idx),
	TP_ARGS(cl_hw_idx),

	/*
	 * These are not used by lttng. We fill them in to make the
	 * tracepoint available to ftrace and perf as well.
	 */
	TP_STRUCT__entry(),

	TP_fast_assign(),

	TP_printk("%d", 0)
)

TRACE_EVENT
(
	cl_trace_rx_tasklet_end,
	TP_PROTO(unsigned char cl_hw_idx, int handled),
	TP_ARGS(cl_hw_idx, handled),

	/*
	 * These are not used by lttng. We fill them in to make the
	 * tracepoint available to ftrace and perf as well.
	 */
	TP_STRUCT__entry(),

	TP_fast_assign(),

	TP_printk("%d", 0)
)

TRACE_EVENT
(
	cl_trace_netif_rx_start,
	TP_PROTO(unsigned char cl_hw_idx),
	TP_ARGS(cl_hw_idx),

	/*
	 * These are not used by lttng. We fill them in to make the
	 * tracepoint available to ftrace and perf as well.
	 */
	TP_STRUCT__entry(),

	TP_fast_assign(),

	TP_printk("%d", 0)
)

TRACE_EVENT
(
	cl_trace_netif_rx_end,
	TP_PROTO(unsigned char cl_hw_idx),
	TP_ARGS(cl_hw_idx),

	/*
	 * These are not used by lttng. We fill them in to make the
	 * tracepoint available to ftrace and perf as well.
	 */
	TP_STRUCT__entry(),

	TP_fast_assign(),

	TP_printk("%d", 0)
)

TRACE_EVENT
(
	cl_trace_cl_msg_fw_send,
	TP_PROTO(unsigned char cl_hw_idx, int msg_id),
	TP_ARGS(cl_hw_idx, msg_id),

	/*
	 * These are not used by lttng. We fill them in to make the
	 ** tracepoint available to ftrace and perf as well.
	 */
	TP_STRUCT__entry(),

	TP_fast_assign(),

	TP_printk("%d", 0)
)
#endif /* !defined(_TRACE_H) || defined(TRACE_HEADER_MULTI_READ) */

/*
 * Without these two lines, the tracepoint will be searched
 * for in include/trace/events, which is not what we desire.
 */
#undef TRACE_INCLUDE_PATH
#define TRACE_INCLUDE_PATH .
#undef TRACE_INCLUDE_FILE
#define TRACE_INCLUDE_FILE cl_trace

#include <trace/define_trace.h>

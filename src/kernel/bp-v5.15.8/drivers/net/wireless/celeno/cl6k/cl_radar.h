/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_RADAR_H
#define CL_RADAR_H

  #include <linux/types.h>

/* Number of pulses in a radar event structure */
#define RADAR_PULSE_MAX 4

/*
 * Structure used to store information regarding
 * E2A radar events in the driver
 */
struct cl_radar_elem {
	struct cl_radar_pulse_array *radarbuf_ptr;
	dma_addr_t dma_addr;
};

/* Bit mapping inside a radar pulse element */
struct cl_radar_pulse {
	u64 freq        : 8;
	u64 fom         : 8;
	u64 len         : 8;  /* Pulse length timer */
	u64 measure_cnt : 2;  /* Measure count */
	u64 rsv1        : 6;  /* Reserve1 */
	u64 rep         : 16; /* PRI */
	u64 rsv2        : 16; /* Reserve2 */
};

/* Definition of an array of radar pulses */
struct cl_radar_pulse_array {
	/* Buffer containing the radar pulses */
	u64 pulse[RADAR_PULSE_MAX];
	/* Number of valid pulses in the buffer */
	u32 cnt;
};

struct cl_radar_queue_elem {
	struct list_head list;
	struct cl_hw *cl_hw;
	struct cl_radar_elem radar_elem;
	unsigned long time;
};

struct cl_hw;

void cl_radar_init(struct cl_hw *cl_hw);
void cl_radar_push(struct cl_hw *cl_hw, struct cl_radar_elem *radar_elem);
void cl_radar_tasklet_schedule(struct cl_hw *cl_hw);
void cl_radar_flush(struct cl_hw *cl_hw);
void cl_radar_close(struct cl_hw *cl_hw);

#endif /* CL_RADAR_H */

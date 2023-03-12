/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_AGC_PARAMS_H
#define CL_AGC_PARAMS_H

#include <linux/types.h>
#include <linux/bitfield.h>
#include "def.h"
#include "cl_vendor_cmd.h"

struct cl_agc_reg {
	u32 val;
	u32 mask;
};

struct cl_agc_params {
	u32 id;
	struct cl_agc_reg fsm_preset_p1;      /* 0x240 - StepA */
	struct cl_agc_reg fsm_preset_p2;      /* 0x244 */
	struct cl_agc_reg fsm_preset_p6;      /* 0x254 - StepA */
	struct cl_agc_reg fsm_preset_p7;      /* 0x258 - StepA */
	struct cl_agc_reg lna_thr_set0_ref2;  /* 0x25C */
	struct cl_agc_reg lna_thr_set0_ref3;  /* 0x260 */
	struct cl_agc_reg lna_thr_set1_ref2;  /* 0x264 */
	struct cl_agc_reg lna_thr_set1_ref3;  /* 0x268 */
	struct cl_agc_reg lna_thr_set2_ref2;  /* 0x26C */
	struct cl_agc_reg lna_thr_set2_ref3;  /* 0x270 */
	struct cl_agc_reg lna_gain_set0_ref2; /* 0x274 */
	struct cl_agc_reg lna_gain_set0_ref3; /* 0x278 */
	struct cl_agc_reg lna_nf_set0_ref2;   /* 0x27C */
	struct cl_agc_reg lna_nf_set0_ref3;   /* 0x280 */
	struct cl_agc_reg lna_icp1_set0_ref2; /* 0x284 */
	struct cl_agc_reg lna_icp1_set0_ref3; /* 0x288 */
	struct cl_agc_reg fsm_preset_p10;     /* 0x2A8 - StepB */
	struct cl_agc_reg fsm_preset_p11;     /* 0x2AC - StepB */
	struct cl_agc_reg fsm_preset_p12;     /* 0x2B0 - StepB */
	struct cl_agc_reg ant_loss;           /* 0x300 */
	struct cl_agc_reg gain_range;         /* 0x304 */
	struct cl_agc_reg vga_ref0;           /* 0x308 */
	struct cl_agc_reg lna_gain_set0_ref0; /* 0x30C */
	struct cl_agc_reg lna_gain_set0_ref1; /* 0x310 */
	struct cl_agc_reg lna_thr_set0_ref0;  /* 0x314 */
	struct cl_agc_reg lna_thr_set0_ref1;  /* 0x318 */
	struct cl_agc_reg lna_thr_set1_ref0;  /* 0x31C */
	struct cl_agc_reg lna_thr_set1_ref1;  /* 0x320 */
	struct cl_agc_reg lna_thr_set2_ref0;  /* 0x324 */
	struct cl_agc_reg lna_thr_set2_ref1;  /* 0x328 */
	struct cl_agc_reg lna_nf_set0_ref0;   /* 0x32C */
	struct cl_agc_reg lna_nf_set0_ref1;   /* 0x330 */
	struct cl_agc_reg lna_icp1_set0_ref0; /* 0x334 */
	struct cl_agc_reg lna_icp1_set0_ref1; /* 0x338 */
	struct cl_agc_reg ramp;               /* 0x36C */
	struct cl_agc_reg dsp3;               /* 0x3A0 */
	struct cl_agc_reg lna_gain_set1_ref0; /* 0x590 - StepB */
	struct cl_agc_reg lna_gain_set1_ref1; /* 0x594 - StepB */
	struct cl_agc_reg lna_gain_set1_ref2; /* 0x598 - StepB */
	struct cl_agc_reg lna_gain_set1_ref3; /* 0x59c - StepB */
	struct cl_agc_reg lna_nf_set1_ref0;   /* 0x5A0 - StepB */
	struct cl_agc_reg lna_nf_set1_ref1;   /* 0x5A4 - StepB */
	struct cl_agc_reg lna_nf_set1_ref2;   /* 0x5A8 - StepB */
	struct cl_agc_reg lna_nf_set1_ref3 ;  /* 0x5AC - StepB */
	struct cl_agc_reg lna_icp1_set1_ref0; /* 0x5B0 - StepB */
	struct cl_agc_reg lna_icp1_set1_ref1; /* 0x5B4 - StepB */
	struct cl_agc_reg lna_icp1_set1_ref2; /* 0x5B8 - StepB */
	struct cl_agc_reg lna_icp1_set1_ref3 ;/* 0x5BC - StepB */
};

struct cl_hw;

void cl_agc_params_fill(struct cl_hw *cl_hw, struct cl_agc_params *agc_params);
int cl_agc_params_cli(struct cl_hw *cl_hw, struct cli_params *cli_params);

#endif /* CL_AGC_PARAMS_H */

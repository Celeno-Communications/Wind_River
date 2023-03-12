/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_DSP_LOAD_H
#define CL_DSP_LOAD_H

#include "chip.h"

/*
 * cl_dsp_load - Load DSP firmware for both TCV's.
 *
 * @chip - chip pointer.
 *
 * Return value: 0 upon success, negative errno code upon failure.
 */
int cl_dsp_load(struct cl_chip *chip);

/*
 * cl_dsp_load_recovery - Load only DSP data for single TCV.
 *
 * @chip - chip pointer.
 *
 * Return value: 0 upon success, negative errno code upon failure.
 */
int cl_dsp_load_recovery(struct cl_hw *cl_hw);

#endif /* CL_DSP_LOAD_H */

/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_VERSION_H
#define CL_VERSION_H

#include "cl_hw.h"

/* Timestamp - number of seconds from Unix time,
 *  January 1, 1970, 00:00:00 till January 1, 2020, 00:00:00
 */
#define CL_TIMESTAMP_1_1_2020    1577836800ull

int cl_version_read(struct cl_hw *cl_hw, bool reply);
int cl_version_cli(struct cl_hw *cl_hw);

#endif /* CL_VERSION_H */

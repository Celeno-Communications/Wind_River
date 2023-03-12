/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_RADIO_H
#define CL_RADIO_H

#include "cl_hw.h"

#define RADIO_STATUS_OFF        0
#define RADIO_STATUS_ON         1
#define RADIO_STATUS_GOING_DOWN 2

int cl_radio_on(struct cl_hw *cl_hw);
void cl_radio_off_chip(struct cl_chip *chip);
void cl_radio_on_chip(struct cl_chip *chip);
bool cl_radio_is_off(struct cl_hw *cl_hw);
bool cl_radio_is_on(struct cl_hw *cl_hw);
bool cl_radio_is_going_down(struct cl_hw *cl_hw);
int cl_radio_cli(struct cl_hw *cl_hw, bool radio_on);

/* Wakes up cl_radio_off_kthread after all the stations have disconnected. */
void cl_radio_off_wake_up(struct cl_hw *cl_hw);

#endif /* CL_RADIO_H */

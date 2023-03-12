/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef PHY_H
#define PHY_H

#include "chip.h"

void cl_phy_reset(struct cl_chip *chip);
void cl_phy_off(struct cl_chip *chip);
void cl_phy_enable(struct cl_chip *chip);

#endif /* PHY_H */

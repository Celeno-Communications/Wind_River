/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef RF_BOOT_H
#define RF_BOOT_H

#include "chip.h"

int cl_rf_boot(struct cl_chip *chip);
int cl_rf_boot_recovery(struct cl_chip *chip, u8 bw);

#endif /* RF_BOOT_H */

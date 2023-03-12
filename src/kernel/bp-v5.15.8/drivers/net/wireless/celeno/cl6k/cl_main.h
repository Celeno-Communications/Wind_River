/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_MAIN_H
#define CL_MAIN_H

#include "chip.h"
#include "cl_hw.h"

int cl_main_init(struct cl_chip *chip);
void cl_main_deinit(struct cl_hw *cl_hw);
int cl_main_on(struct cl_hw *cl_hw);
void cl_main_off(struct cl_hw *cl_hw);

void cl_pci_set_cl_hw(struct cl_chip *chip, struct cl_hw *cl_hw);
int cl_pci_init(void);
void cl_pci_exit(void);
void cl_usb_set_cl_hw(struct cl_chip *chip, struct cl_hw *cl_hw);
int cl_usb_init(void);
void cl_usb_exit(void);
#endif /* CL_MAIN_H */

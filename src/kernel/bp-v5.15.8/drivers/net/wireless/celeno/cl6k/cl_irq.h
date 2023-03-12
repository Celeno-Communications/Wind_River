/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_IRQ_H
#define CL_IRQ_H

#include "chip.h"
#include "cl_hw.h"

int cl_irq_request(struct cl_chip *chip);
void cl_irq_free(struct cl_chip *chip);
void cl_irq_status(struct cl_hw *cl_hw, u32 status);
void cl_irq_enable(struct cl_hw *cl_hw, u32 value);
void cl_irq_disable(struct cl_hw *cl_hw, u32 value);

#endif /* CL_IRQ_H */

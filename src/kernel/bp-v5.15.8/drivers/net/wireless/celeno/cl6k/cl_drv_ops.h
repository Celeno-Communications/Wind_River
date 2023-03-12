/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_DRV_OPS_H
#define CL_DRV_OPS_H

#include "cl_hw.h"

static inline int cl_drv_ops_msg_fw_send(struct cl_hw *cl_hw,
					 const void *msg_params,
					 bool background)
{
	if (cl_hw && cl_hw->ops->msg_fw_send)
		return cl_hw->ops->msg_fw_send(cl_hw, msg_params, background);

	return 0;
}

#endif /* CL_DRV_OPS_H */

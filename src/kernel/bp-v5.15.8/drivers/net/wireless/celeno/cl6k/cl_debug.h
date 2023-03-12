/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_DEBUG_H
#define CL_DEBUG_H

#include <linux/string.h>
#include "core_debug.h"

#define CL_DBG(cl_hw, lvl, fmt, ...) \
do { \
	if ((cl_hw)->conf && (lvl) <= (cl_hw)->conf->ce_debug_level) \
		pr_debug("[tcv%u][%s][%d] " fmt, (cl_hw)->idx, __func__, __LINE__, ##__VA_ARGS__); \
} while (0)

#define cl_dbg_verbose(cl_hw, ...) CL_DBG((cl_hw), DBG_LVL_VERBOSE, ##__VA_ARGS__)
#define cl_dbg_err(cl_hw, ...)     CL_DBG((cl_hw), DBG_LVL_ERROR, ##__VA_ARGS__)
#define cl_dbg_warn(cl_hw, ...)    CL_DBG((cl_hw), DBG_LVL_WARNING, ##__VA_ARGS__)
#define cl_dbg_trace(cl_hw, ...)   CL_DBG((cl_hw), DBG_LVL_TRACE, ##__VA_ARGS__)
#define cl_dbg_info(cl_hw, ...)    CL_DBG((cl_hw), DBG_LVL_INFO, ##__VA_ARGS__)

#define INFO_CL_HW(cl_hw, ...) \
	do { \
		pr_debug("\n"); \
		pr_debug("CHIP:        %u\n", (cl_hw)->chip->idx); \
		pr_debug("TCV:         %u\n", (cl_hw)->idx); \
		pr_debug("FILE:        %s\n", basename(__FILE__)); \
		pr_debug("FUNCTION:    %s\n", __func__); \
		pr_debug("LINE:        %u\n", __LINE__); \
		pr_debug("DESCRIPTION: " __VA_ARGS__); \
		pr_debug("\n"); \
	} while (0)

#define CL_DBG_ERROR(cl_hw, ...) \
	do { \
		TXT_ERROR; \
		INFO_CL_HW(cl_hw, __VA_ARGS__); \
	} while (0)

#define CL_DBG_WARNING(cl_hw, ...) \
	do { \
		TXT_WARNING; \
		INFO_CL_HW(cl_hw, __VA_ARGS__); \
	} while (0)

#endif /* CL_DEBUG_H */

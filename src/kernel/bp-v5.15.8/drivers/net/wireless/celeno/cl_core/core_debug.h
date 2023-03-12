/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CORE_DEBUG_H
#define CORE_DEBUG_H

#include <linux/string.h>
#include <linux/module.h>

enum cl_dbg_level {
	DBG_LVL_VERBOSE,
	DBG_LVL_ERROR,
	DBG_LVL_WARNING,
	DBG_LVL_TRACE,
	DBG_LVL_INFO,

	DBG_LVL_MAX
};

#define CL_DBG_CHIP(chip, lvl, fmt, ...) \
do { \
	if ((lvl) <= (chip)->conf->ce_debug_level) \
		pr_crit("[%s][chip%u][%s][%d] " fmt, \
			module_name(THIS_MODULE), (chip)->idx, \
			__func__, __LINE__, ##__VA_ARGS__); \
} while (0)

#define cl_dbg_chip_verbose(chip, ...) CL_DBG_CHIP((chip), DBG_LVL_VERBOSE, ##__VA_ARGS__)
#define cl_dbg_chip_err(chip, ...)     CL_DBG_CHIP((chip), DBG_LVL_ERROR, ##__VA_ARGS__)
#define cl_dbg_chip_warn(chip, ...)    CL_DBG_CHIP((chip), DBG_LVL_WARNING, ##__VA_ARGS__)
#define cl_dbg_chip_trace(chip, ...)   CL_DBG_CHIP((chip), DBG_LVL_TRACE, ##__VA_ARGS__)
#define cl_dbg_chip_info(chip, ...)    CL_DBG_CHIP((chip), DBG_LVL_INFO, ##__VA_ARGS__)

static inline char *basename(const char *filename)
{
	char *p = strrchr(filename, '/');

	return p ? p + 1 : (char *)filename;
}

#define TXT_ERROR \
	do { \
		pr_crit("\n"); \
		pr_crit("#######  #####    #####     #####   #####\n"); \
		pr_crit("#        #    #   #    #   #     #  #    #\n"); \
		pr_crit("#        #    #   #    #   #     #  #    #\n"); \
		pr_crit("#######  #####    #####    #     #  #####\n"); \
		pr_crit("#        #    #   #    #   #     #  #    #\n"); \
		pr_crit("#        #     #  #     #  #     #  #     #\n"); \
		pr_crit("#######  #     #  #     #   #####   #     #\n"); \
	} while (0)

#define TXT_WARNING \
	do { \
		pr_crit("\n"); \
		pr_crit("#       #   #####   #####    #     #  ###  #     #   #####\n"); \
		pr_crit("#       #  #     #  #    #   ##    #   #   ##    #  #     #\n"); \
		pr_crit("#       #  #     #  #    #   # #   #   #   # #   #  #\n"); \
		pr_crit("#   #   #  #######  #####    #  #  #   #   #  #  #  #    ###\n"); \
		pr_crit("#  # #  #  #     #  #    #   #   # #   #   #   # #  #     #\n"); \
		pr_crit("# #   # #  #     #  #     #  #    ##   #   #    ##  #     #\n"); \
		pr_crit(" #     #   #     #  #     #  #     #  ###  #     #   #####\n"); \
	} while (0)

#define INFO_CHIP(chip, ...) \
	do { \
		pr_crit("\n"); \
		pr_crit("CHIP:        %u\n", (chip)->idx); \
		pr_crit("FILE:        %s\n", basename(__FILE__)); \
		pr_crit("FUNCTION:    %s\n", __func__); \
		pr_crit("LINE:        %u\n", __LINE__); \
		pr_crit("DESCRIPTION: " __VA_ARGS__); \
		pr_crit("\n"); \
	} while (0)

#define CL_DBG_ERROR_CHIP(chip, ...) \
	do { \
		TXT_ERROR; \
		INFO_CHIP(chip, __VA_ARGS__); \
	} while (0)

#define CL_DBG_WARNING_CHIP(chip, ...) \
	do { \
		TXT_WARNING; \
		INFO_CHIP(chip, __VA_ARGS__); \
	} while (0)

#endif /* CORE_DEBUG_H */

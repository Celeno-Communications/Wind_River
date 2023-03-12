/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CONFIG_H
#define CONFIG_H

#include <linux/types.h>
#include <linux/kernel.h>
#include "string.h"

#define MAX_PARAM_NAME_LENGTH 64

#define PRINT_UNSIGNED_ARR(param, old_val, size, new_val) \
do { \
	u8 i; \
	char buf[STR_LEN_256B]; \
	int len = 0; \
	len += snprintf(buf, sizeof(buf), "%s: old value ", #param); \
	for (i = 0; i < (size) - 1; i++) \
		len += snprintf(buf + len, sizeof(buf) - len, \
				"%u,", old_val[i]); \
	len += snprintf(buf + len, sizeof(buf) - len, \
			"%u --> new value %s\n", old_val[(size) - 1], new_val); \
	pr_debug("%s", buf); \
} while (0)

#define PRINT_SIGNED_ARR(param, old_val, size, new_val) \
do { \
	u8 i; \
	char buf[STR_LEN_256B]; \
	int len = 0; \
	len += snprintf(buf, sizeof(buf), "%s: old value ", #param); \
	for (i = 0; i < (size) - 1; i++) \
		len += snprintf(buf + len, sizeof(buf) - len, \
				"%d,", old_val[i]); \
	len += snprintf(buf + len, sizeof(buf) - len, \
			"%d --> new value %s\n", old_val[(size) - 1], new_val); \
	pr_debug("%s", buf); \
} while (0)

#define READ_BOOL(param) \
{ \
	if (!strcmp(name, #param)) { \
		bool new_val = false; \
		ret = kstrtobool(value, &new_val); \
		if (ret) { \
			pr_err("%s: invalid value [%s]\n", #param, value); \
			break; \
		} \
		if (conf->param != new_val) { \
			pr_debug("%s: old value %u -> new value %u\n", \
				 #param, conf->param, new_val); \
			conf->param = new_val; \
		} \
		break; \
	} \
}

#define READ_U8(param) \
{ \
	if (!strcmp(name, #param)) { \
		u8 new_val = 0; \
		ret = kstrtou8(value, 0, &new_val); \
		if (ret) { \
			pr_err("%s: invalid value [%s]\n", #param, value); \
			break; \
		} \
		if (conf->param != new_val) { \
			pr_debug("%s: old value %u -> new value %u\n", \
				 #param, conf->param, new_val); \
			conf->param = new_val; \
		} \
		break; \
	} \
}

#define READ_U16(param) \
{ \
	if (!strcmp(name, #param)) { \
		u16 new_val = 0; \
		ret = kstrtou16(value, 0, &new_val); \
		if (ret) { \
			pr_err("%s: invalid value [%s]\n", #param, value); \
			break; \
		} \
		if (conf->param != new_val) { \
			pr_debug("%s: old value %u -> new value %u\n", \
				 #param, conf->param, new_val); \
			conf->param = new_val; \
		} \
		break; \
	} \
}

#define READ_U32(param) \
{ \
	if (!strcmp(name, #param)) { \
		u32 new_val = 0; \
		ret = kstrtou32(value, 0, &new_val); \
		if (ret) { \
			pr_err("%s: invalid value [%s]\n", #param, value); \
			break; \
		} \
		if (conf->param != new_val) { \
			pr_debug("%s: old value %u -> new value %u\n", \
				 #param, conf->param, new_val); \
			conf->param = new_val; \
		} \
		break; \
	} \
}

#define READ_S8(param) \
{ \
	if (!strcmp(name, #param)) { \
		s8 new_val = 0; \
		ret = kstrtos8(value, 0, &new_val); \
		if (ret) { \
			pr_err("%s: invalid value [%s]\n", #param, value); \
			break; \
		} \
		if (conf->param != new_val) { \
			pr_debug("%s: old value %d -> new value %d\n", \
				 #param, conf->param, new_val); \
			conf->param = new_val; \
		} \
		break; \
	} \
}

#define READ_S16(param) \
{ \
	if (!strcmp(name, #param)) { \
		s16 new_val = 0; \
		ret = kstrtos16(value, 0, &new_val); \
		if (ret) { \
			pr_err("%s: invalid value [%s]\n", #param, value); \
			break; \
		} \
		if (conf->param != new_val) { \
			pr_debug("%s: old value %d -> new value %d\n", \
				 #param, conf->param, new_val); \
			conf->param = new_val; \
		} \
		break; \
	} \
}

#define READ_S32(param) \
{ \
	if (!strcmp(name, #param)) { \
		s32 new_val = 0; \
		ret = kstrtos32(value, 0, &new_val); \
		if (ret) { \
			pr_err("%s: invalid value [%s]\n", #param, value); \
			break; \
		} \
		if (conf->param != new_val) { \
			pr_debug("%s: old value %d -> new value %d\n", \
				 #param, conf->param, new_val); \
			conf->param = new_val; \
		} \
		break; \
	} \
}

#define READ_BOOL_ARR(param, size) \
{ \
	if (!strcmp(name, #param)) { \
		bool old_val[size] = {false}; \
		memcpy(old_val, conf->param, sizeof(old_val)); \
		ret = cl_strtobool_vector(value, conf->param, size, ","); \
		if (ret == 0) { \
			if (memcmp(old_val, conf->param, sizeof(old_val))) \
				PRINT_UNSIGNED_ARR(param, old_val, size, value); \
		} else if (ret == -E2BIG) { \
			pr_err("%s: value [%s] too big [%zu]\n", #param, value, strlen(value)); \
		} else if (ret == -EIO) { \
			pr_err("%s: delimiter ',' not found\n", #param); \
		} else if (ret == -EINVAL) { \
			pr_err("%s: invalid argument [%s]\n", #param, value); \
		} else if (ret == -ENODATA) { \
			pr_err("%s: value [%s] doesn't have %u elements\n", #param, value, size); \
		} \
		break; \
	} \
}

#define READ_U8_ARR(param, size) \
{ \
	if (!strcmp(name, #param)) { \
		u8 old_val[size] = {0}; \
		memcpy(old_val, conf->param, sizeof(old_val)); \
		ret = cl_strtou8_vector(value, conf->param, size, ","); \
		if (ret == 0) { \
			if (memcmp(old_val, conf->param, sizeof(old_val))) \
				PRINT_UNSIGNED_ARR(param, old_val, size, value); \
		} else if (ret == -E2BIG) { \
			pr_err("%s: value [%s] too big [%zu]\n", #param, value, strlen(value)); \
		} else if (ret == -EIO) { \
			pr_err("%s: delimiter ',' not found\n", #param); \
		} else if (ret == -EINVAL) { \
			pr_err("%s: invalid argument [%s]\n", #param, value); \
		} else if (ret == -ENODATA) { \
			pr_err("%s: value [%s] doesn't have %u elements\n", #param, value, size); \
		} \
		break; \
	} \
}

#define READ_U16_ARR(param, size) \
{ \
	if (!strcmp(name, #param)) { \
		u16 old_val[size] = {0}; \
		memcpy(old_val, conf->param, sizeof(old_val)); \
		ret = cl_strtou16_vector(value, conf->param, size, ","); \
		if (ret == 0) { \
			if (memcmp(old_val, conf->param, sizeof(old_val))) \
				PRINT_UNSIGNED_ARR(param, old_val, size, value); \
		} else if (ret == -E2BIG) { \
			pr_err("%s: value [%s] too big [%zu]\n", #param, value, strlen(value)); \
		} else if (ret == -EIO) { \
			pr_err("%s: delimiter ',' not found\n", #param); \
		} else if (ret == -EINVAL) { \
			pr_err("%s: invalid argument [%s]\n", #param, value); \
		} else if (ret == -ENODATA) { \
			pr_err("%s: value [%s] doesn't have %u elements\n", #param, value, size); \
		} \
		break; \
	} \
}

#define READ_U32_ARR(param, size) \
{ \
	if (!strcmp(name, #param)) { \
		u32 old_val[size] = {0}; \
		memcpy(old_val, conf->param, sizeof(old_val)); \
		ret = cl_strtou32_vector(value, conf->param, size, ","); \
		if (ret == 0) { \
			if (memcmp(old_val, conf->param, sizeof(old_val))) \
				PRINT_UNSIGNED_ARR(param, old_val, size, value); \
		} else if (ret == -E2BIG) { \
			pr_err("%s: value [%s] too big [%zu]\n", #param, value, strlen(value)); \
		} else if (ret == -EIO) { \
			pr_err("%s: delimiter ',' not found\n", #param); \
		} else if (ret == -EINVAL) { \
			pr_err("%s: invalid argument [%s]\n", #param, value); \
		} else if (ret == -ENODATA) { \
			pr_err("%s: value [%s] doesn't have %u elements\n", #param, value, size); \
		} \
		break; \
	} \
}

#define READ_S8_ARR(param, size) \
{ \
	if (!strcmp(name, #param)) { \
		s8 old_val[size] = {0}; \
		memcpy(old_val, conf->param, sizeof(old_val)); \
		ret = cl_strtos8_vector(value, conf->param, size, ","); \
		if (ret == 0) { \
			if (memcmp(old_val, conf->param, sizeof(old_val))) \
				PRINT_SIGNED_ARR(param, old_val, size, value); \
		} else if (ret == -E2BIG) { \
			pr_err("%s: value [%s] too big [%zu]\n", #param, value, strlen(value)); \
		} else if (ret == -EIO) { \
			pr_err("%s: delimiter ',' not found\n", #param); \
		} else if (ret == -EINVAL) { \
			pr_err("%s: invalid argument [%s]\n", #param, value); \
		} else if (ret == -ENODATA) { \
			pr_err("%s: value [%s] doesn't have %u elements\n", #param, value, size); \
		} \
		break; \
	} \
}

#define READ_S16_ARR(param, size) \
{ \
	if (!strcmp(name, #param)) { \
		s16 old_val[size] = {0}; \
		memcpy(old_val, conf->param, sizeof(old_val)); \
		ret = cl_strtos16_vector(value, conf->param, size, ","); \
		if (ret == 0) { \
			if (memcmp(old_val, conf->param, sizeof(old_val))) \
				PRINT_SIGNED_ARR(param, old_val, size, value); \
		} else if (ret == -E2BIG) { \
			pr_err("%s: value [%s] too big [%zu]\n", #param, value, strlen(value)); \
		} else if (ret == -EIO) { \
			pr_err("%s: delimiter ',' not found\n", #param); \
		} else if (ret == -EINVAL) { \
			pr_err("%s: invalid argument [%s]\n", #param, value); \
		} else if (ret == -ENODATA) { \
			pr_err("%s: value [%s] doesn't have %u elements\n", #param, value, size); \
		} \
		break; \
	} \
}

#define READ_S32_ARR(param, size) \
{ \
	if (!strcmp(name, #param)) { \
		s32 old_val[size] = {0}; \
		memcpy(old_val, conf->param, sizeof(old_val)); \
		ret = cl_strtos32_vector(value, conf->param, size, ","); \
		if (ret == 0) { \
			if (memcmp(old_val, conf->param, sizeof(old_val))) \
				PRINT_SIGNED_ARR(param, old_val, size, value); \
		} else if (ret == -E2BIG) { \
			pr_err("%s: value [%s] too big [%zu]\n", #param, value, strlen(value)); \
		} else if (ret == -EIO) { \
			pr_err("%s: delimiter ',' not found\n", #param); \
		} else if (ret == -EINVAL) { \
			pr_err("%s: invalid argument [%s]\n", #param, value); \
		} else if (ret == -ENODATA) { \
			pr_err("%s: value [%s] doesn't have %u elements\n", #param, value, size); \
		} \
		break; \
	} \
}

#define READ_STR(param) \
{ \
	if (!strcmp(name, #param)) { \
		if (strcmp(value, conf->param)) { \
			pr_debug("%s: old value %s -> new value %s\n", \
				 #param, conf->param, value); \
			strncpy(conf->param, value, sizeof(conf->param) - 1); \
		} \
		ret = 0; \
		break; \
	} \
}

#define READ_MAC(param) \
{ \
	if (!strcmp(name, #param)) { \
		u8 old_val[ETH_ALEN] = {0}; \
		memcpy(old_val, conf->param, ETH_ALEN); \
		ret = cl_strtou8_hex_vector(value, conf->param, ETH_ALEN, ":"); \
		if (ret == 0) { \
			if (memcmp(old_val, conf->param, sizeof(old_val))) \
				pr_debug("%s: old value %pM -> new value %pM\n", \
					 #param, old_val, conf->param); \
		} else if (ret == -E2BIG) { \
			pr_err("%s: value [%s] too big [%zu]\n", #param, value, strlen(value)); \
		} else if (ret == -EIO) { \
			pr_err("%s: delimiter ',' not found\n", #param); \
		} else if (ret == -EINVAL) { \
			pr_err("%s: invalid argument [%s]\n", #param, value); \
		} else if (ret == -ENODATA) { \
			pr_err("%s: value [%s] doesn't have %u elements\n", #param, value, \
			       ETH_ALEN); \
		} \
		break; \
	} \
}

#define READ_IP(param)                        \
{ \
	if (!strcmp(name, #param)) { \
		u8 old_val[ETH_IP_ADDR_LEN] = {0};        \
		memcpy(old_val, conf->param, sizeof(old_val)); \
		ret = cl_strtou8_vector(value, conf->param, ETH_IP_ADDR_LEN, "."); \
		if (ret == 0) { \
			if (memcmp(old_val, conf->param, sizeof(old_val))) \
				PRINT_UNSIGNED_ARR(param, old_val, ETH_IP_ADDR_LEN, value); \
		} else if (ret == -E2BIG) { \
			pr_err("%s: value [%s] too big [%zu]\n", #param, value, strlen(value)); \
		} else if (ret == -EIO) { \
			pr_err("%s: delimiter ',' not found\n", #param); \
		} else if (ret == -EINVAL) { \
			pr_err("%s: invalid argument [%s]\n", #param, value); \
		} else if (ret == -ENODATA) { \
			pr_err("%s: value [%s] doesn't have %u elements\n", \
				#param, value, ETH_IP_ADDR_LEN);    \
		} \
		break; \
	} \
}

#define print_signed(var) \
	pr_debug("%s = %d\n", #var, conf->var)

#define print_unsigned(var) \
	pr_debug("%s = %u\n", #var, conf->var)

#define print_bool(var) \
	pr_debug("%s = %s\n", #var, conf->var ? "true" : "false")

#define print_str(var) \
	pr_debug("%s = %s\n", #var, conf->var)

#define print_mac(var) \
	pr_debug("%s = %pM\n", #var, conf->var)

#define print_hex(var) \
	pr_debug("%s = 0x%x\n", #var, conf->var)

#define print_signed_arr(var, size) \
	{ \
		int i, len; \
		char str[256] = {0}; \
		len = snprintf(str, sizeof(str), "%s = ", #var); \
		for (i = 0; i < (size); i++) \
			len += snprintf(str + len, sizeof(str) - len, \
					"%d%s", conf->var[i], (i < ((size) - 1)) ? "," : ""); \
		pr_debug("%s\n", str); \
	}

#define print_unsigned_arr(var, size) \
	{ \
		int i, len; \
		char str[256] = {0}; \
		len = snprintf(str, sizeof(str), "%s = ", #var); \
		for (i = 0; i < (size); i++) \
			len += snprintf(str + len, sizeof(str) - len, \
					"%u%s", conf->var[i], (i < ((size) - 1)) ? "," : ""); \
		pr_debug("%s\n", str); \
	}

struct cl_chip;

bool cl_config_is_non_driver_param(char *name);
int add_bt_config(struct cl_chip *chip, u8 *data);

#endif /* CONFIG_H */

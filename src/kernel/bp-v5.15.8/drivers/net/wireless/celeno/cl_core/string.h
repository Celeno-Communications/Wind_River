/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef __STRING_H
#define __STRING_H

#include <linux/errno.h>
#include <linux/string.h>
#include <linux/kernel.h>
#include <linux/types.h>

#define STR_LEN_16B  16
#define STR_LEN_32B  32
#define STR_LEN_64B  64
#define STR_LEN_128B 128
#define STR_LEN_256B 256
#define STR_LEN_512B 512

static s8 *_strtok;

/* cl_strtok_r() is a reentrant version of cl_strtok() */
static inline s8 *cl_strtok_r(s8 *s, const s8 *ct, s8 **saveptr)
{
	s8 *sbegin, *send;

	sbegin  = s ? s : *saveptr;
	if (!sbegin)
		return NULL;

	sbegin += strspn(sbegin, ct);
	if (*sbegin == '\0') {
		*saveptr = NULL;
		return NULL;
	}

	send = strpbrk(sbegin, ct);
	if (send && *send != '\0')
		*send++ = '\0';

	*saveptr = send;

	return sbegin;
}

static s8 *cl_strtok(s8 *s, const s8 *ct)
{
	return cl_strtok_r(s, ct, &_strtok);
}

static inline int cl_strtobool_vector(char *src, bool *dest,
				      u8 elem_cnt, char *delim)
{
	u8 i = 0;
	char *buf = NULL;
	char vector[STR_LEN_256B] = {0};

	if (strlen(src) >= sizeof(vector))
		return -E2BIG;

	strcpy(vector, src);
	buf = cl_strtok(vector, delim);

	if (!buf)
		return -EIO;
	if (kstrtobool(buf, &dest[0]) != 0)
		return -EINVAL;

	for (i = 1; i < elem_cnt; i++) {
		buf = cl_strtok(NULL, delim);
		if (!buf)
			break;
		if (kstrtobool(buf, &dest[i]) != 0)
			return -EINVAL;
	}

	if (i < elem_cnt) {
		pr_err("src %s doesn't have %u elements\n", src, elem_cnt);
		return  -ENODATA;
	}

	return 0;
}

static inline int cl_strtou8_vector(char *src, u8 *dest,
				    u8 elem_cnt, char *delim)
{
	u8 i = 0;
	char *buf = NULL;
	char vector[STR_LEN_256B] = {0};

	if (strlen(src) >= sizeof(vector))
		return -E2BIG;

	strcpy(vector, src);
	buf = cl_strtok(vector, delim);

	if (!buf)
		return -EIO;
	if (kstrtou8(buf, 0, &dest[0]) != 0)
		return -EINVAL;

	for (i = 1; i < elem_cnt; i++) {
		buf = cl_strtok(NULL, delim);
		if (!buf)
			break;
		if (kstrtou8(buf, 0, &dest[i]) != 0)
			return -EINVAL;
	}

	if (i < elem_cnt) {
		pr_err("src %s doesn't have %u elements\n", src, elem_cnt);
		return -ENODATA;
	}

	return 0;
}

static inline int cl_strtou8_hex_vector(char *src, u8 *dest,
					u8 elem_cnt, char *delim)
{
	u8 i = 0;
	char *buf = NULL;
	char vector[STR_LEN_32B] = {0};

	if (strlen(src) >= sizeof(vector))
		return -E2BIG;

	strcpy(vector, src);
	buf = cl_strtok(vector, delim);

	if (!buf)
		return -EIO;
	if (kstrtou8(buf, 16, &dest[0]) != 0)
		return -EINVAL;

	for (i = 1; i < elem_cnt; i++) {
		buf = cl_strtok(NULL, delim);
		if (!buf)
			break;
		if (kstrtou8(buf, 16, &dest[i]) != 0)
			return -EINVAL;
	}

	if (i < elem_cnt) {
		pr_err("src %s doesn't have %u elements\n", src, elem_cnt);
		return -ENODATA;
	}

	return 0;
}

static inline int cl_strtou16_vector(char *src, u16 *dest,
				     u8 elem_cnt, char *delim)
{
	u8 i = 0;
	char *buf = NULL;
	char vector[STR_LEN_256B] = {0};

	if (strlen(src) >= sizeof(vector))
		return -E2BIG;

	strcpy(vector, src);
	buf = cl_strtok(vector, delim);

	if (!buf)
		return -EIO;
	if (kstrtou16(buf, 0, &dest[0]) != 0)
		return -EINVAL;

	for (i = 1; i < elem_cnt; i++) {
		buf = cl_strtok(NULL, delim);
		if (!buf)
			break;
		if (kstrtou16(buf, 0, &dest[i]) != 0)
			return -EINVAL;
	}

	if (i < elem_cnt) {
		pr_err("src %s doesn't have %u elements\n", src, elem_cnt);
		return -ENODATA;
	}

	return 0;
}

static inline int cl_strtou32_vector(char *src, u32 *dest,
				     u8 elem_cnt, char *delim)
{
	u8 i = 0;
	char *buf = NULL;
	char vector[STR_LEN_256B] = {0};

	if (strlen(src) >= sizeof(vector))
		return -E2BIG;

	strcpy(vector, src);
	buf = cl_strtok(vector, delim);

	if (!buf)
		return -EIO;
	if (kstrtou32(buf, 0, &dest[0]) != 0)
		return -EINVAL;

	for (i = 1; i < elem_cnt; i++) {
		buf = cl_strtok(NULL, delim);
		if (!buf)
			break;
		if (kstrtou32(buf, 0, &dest[i]) != 0)
			return -EINVAL;
	}

	if (i < elem_cnt) {
		pr_err("src %s doesn't have %u elements\n", src, elem_cnt);
		return -ENODATA;
	}

	return 0;
}

static inline int cl_strtos8_vector(char *src, s8 *dest,
				    u8 elem_cnt, char *delim)
{
	u8 i = 0;
	char *buf = NULL;
	char vector[STR_LEN_256B] = {0};

	if (strlen(src) >= sizeof(vector))
		return -E2BIG;

	strcpy(vector, src);
	buf = cl_strtok(vector, delim);

	if (!buf)
		return -EIO;
	if (kstrtos8(buf, 0, &dest[0]) != 0)
		return -EINVAL;

	for (i = 1; i < elem_cnt; i++) {
		buf = cl_strtok(NULL, delim);
		if (!buf)
			break;
		if (kstrtos8(buf, 0, &dest[i]) != 0)
			return -EINVAL;
	}

	if (i < elem_cnt) {
		pr_err("src %s doesn't have %u elements\n", src, elem_cnt);
		return -ENODATA;
	}

	return 0;
}

#endif /* __STRING_H */

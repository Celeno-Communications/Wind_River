// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include <linux/ctype.h>
#include "cl_dbgfile.h"
#include "reg_access.h"
#include "cl_utils.h"
#include "cl_dbgfile.h"
#ifdef TRACE_SUPPORT
#include "cl_trace.h"
#endif

#define MAX_DBGFILE_STORE_OFFLOAD_DATA 420000

const char *cl_dbgfile_get_msg_txt(struct cl_dbg_data *dbg_data, u16 file_id, u16 line)
{
	/* Get the message text from the .dbg file by file_id & line number */
	int remaining_bytes = dbg_data->size;
	const char *str = dbg_data->str;
	char id_str[32];
	int idstr_len;

	if (!str || 0 == remaining_bytes)
		return NULL;

	idstr_len = snprintf(id_str, sizeof(id_str), "%u:%u:", file_id, line);

	/* Skip hash */
	while (*str++ != '\n')
		;

	remaining_bytes -= (str - (char *)dbg_data->str);

	while (remaining_bytes > 0) {
		if (strncmp(id_str, str, idstr_len) == 0) {
			str += idstr_len;
			while (*str == ' ')
				++str;
			return (const char *)str;
		}

		str += strnlen(str, 512) + 1;
		remaining_bytes = dbg_data->size - (str - (char *)dbg_data->str);
	}

	/* No match found */
	pr_err("error: file_id=%d line=%d not found in debug print file\n", file_id, line);
	return NULL;
}

void cl_dbgfile_parse(struct cl_hw *cl_hw, void *edata, u32 esize)
{
	/* Parse & store the firmware debug file */
	struct cl_dbg_data *dbg_data = &cl_hw->dbg_data;

	dbg_data->size = esize;
	dbg_data->str = edata;
}

void cl_dbgfile_release_mem(struct cl_dbg_data *dbg_data,
			    struct cl_str_offload_env *str_offload_env)
{
	dbg_data->str = NULL;

	str_offload_env->enabled = false;
	str_offload_env->block1 = NULL;
	str_offload_env->block2 = NULL;
}

/*
 * Store debug print offload data
 * - part 1: offloaded block that does not exist on target
 * - part 2: resident block that remains on target [optional]
 */
int cl_dbgfile_store_offload_data(struct cl_chip *chip, struct cl_hw *cl_hw,
				  void *data1, u32 size1, u32 base1,
				  void *data2, u32 size2, u32 base2,
				  void *data3, u32 size3, u32 base3)
{
	u32 u = size1;
	struct cl_str_offload_env *str_offload_env = &cl_hw->str_offload_env;

	if (u > MAX_DBGFILE_STORE_OFFLOAD_DATA)
		goto err_too_big;

	str_offload_env->block1 = data1;
	str_offload_env->size1 = size1;
	str_offload_env->base1 = base1;

	str_offload_env->block2 = data2;
	str_offload_env->size2 = size2;
	str_offload_env->base2 = base2;

	str_offload_env->block3 = data3;
	str_offload_env->size3 = size3;
	str_offload_env->base3 = base3;

	str_offload_env->enabled = true;

	cl_dbg_info(cl_hw, "lmac%u: FW prints offload memory use = %uK\n",
		    chip->idx, (size1 + size2 + 1023) / 1024);

	return 0;

err_too_big:
	pr_err("%s: size too big: %u\n", __func__, u);
	return 1;
}

static void do_print_n(struct cl_hw *cl_hw, const char *str, int n)
{
	/* Print formatted string with "band" prefix */
	if (n < 0 || n > 256) {
		cl_dbg_err(cl_hw, "lmac%u: *** FW PRINT - BAD SIZE: %d\n",
			   cl_hw->chip->idx, n);
		return;
	}

	cl_dbg_verbose(cl_hw, "lmac%u: %.*s\n", cl_hw->chip->idx, n, str);
}

static void do_hex_dump_bytes(struct cl_hw *cl_hw, u32 addr, void *data, u32 count)
{
	cl_dbg_verbose(cl_hw, "lmac%u: hex dump:\n", cl_hw->chip->idx);
	hex_dump2(NULL, data, count, addr, true);
}

#define MAGIC_PRINT_OFFLOAD   0xFA  /* 1st (low) byte of signature */
/* 2nd signature byte */
#define MAGIC_PRINT_OFF_XDUMP 0xD0  /* Hex dump, by bytes */
#define MAGIC_PRINT_OFF_LIT   0x01  /* Literal/preformatted string */
#define MAGIC_PRINT_OFF_PRINT 0x02  /* Print with 'virtual' format string */

#define MAX_PRINT_OFF_PARAMS  20

static int offload_print(struct cl_str_offload_env *str_offload_env, char *fmt, const char *params)
{
	static char buf[1024] = {0};
	const char *cur_prm = params;
	char tmp;
	char *fmt_end = fmt;
	size_t size = sizeof(int);
	int len = 0;

	union v {
		u32 val32;
		u64 val64;
		ptrdiff_t str;
	} v;

	while ((fmt_end = strchr(fmt_end, '%'))) {
		fmt_end++;

		/* Skip '%%'. */
		if (*fmt_end == '%') {
			fmt_end++;
			continue;
		}

		/* Skip flags. */
		while (strchr("-+ 0#", *fmt_end))
			fmt_end++;

		/* Skip width. */
		while (isdigit(*fmt_end))
			fmt_end++;

		/* Skip precision. */
		if (*fmt_end == '.') {
			while (*fmt_end == '-' || *fmt_end == '+')
				fmt_end++;

			while (isdigit(*fmt_end))
				fmt_end++;
		}

		/* Get size. */
		if (*fmt_end == 'z') {
			/* Remove 'z' from %zu, %zd, %zx and %zX,
			 * because sizeof(size_t) == 4 in the firmware.
			 * 'z' can only appear in front of 'd', 'u', 'x' or 'X'.
			 */
			if (!strchr("duxX", *(fmt_end + 1)))
				return -1;

			fmt_end++;
			size = 4;
		} else if (*fmt_end == 'l') {
			fmt_end++;

			if (*fmt_end == 'l') {
				fmt_end++;
				size = sizeof(long long);
			} else {
				size = sizeof(long);
			}

			if (*fmt_end == 'p') /* %p can't get 'l' or 'll' modifiers. */
				return -1;
		} else {
			size = 4;
		}

		/* Get parameter. */
		switch (*fmt_end) {
		case 'p': /* Replace %p with %x, because the firmware's pointers are 32 bit wide */
			*fmt_end = 'x';
			fallthrough;
		case 'd':
		case 'u':
		case 'x':
		case 'X':
			if (size == 4)
				v.val32 = __le32_to_cpu(*(__le32 *)cur_prm);
			else
				v.val64 = __le64_to_cpu(*(__le64 *)cur_prm);
			cur_prm += size;
			break;
		case 's':
			v.str = __le32_to_cpu(*(__le32 *)cur_prm);
			cur_prm += 4;
			size = sizeof(ptrdiff_t);

			if (v.str >= str_offload_env->base3 &&
			    v.str < str_offload_env->base3 + str_offload_env->size3) {
				v.str -= str_offload_env->base3;
				v.str += (ptrdiff_t)str_offload_env->block3;
			} else if (v.str >= str_offload_env->base2 &&
				   v.str < str_offload_env->base2 + str_offload_env->size2) {
				v.str -= str_offload_env->base2;
				v.str += (ptrdiff_t)str_offload_env->block2;
			} else
				return -1;

			break;
		default:
			return -1;
		}

		/* Print into buffer. */
		fmt_end++;
		tmp = *fmt_end; /* Truncate the format to the current point and then restore. */
		*fmt_end = 0;
		len += snprintf(buf + len, sizeof(buf) - len, fmt, size == 4 ? v.val32 : v.val64);
		*fmt_end = tmp;
		fmt = fmt_end;
	}

	snprintf(buf + len, sizeof(buf) - len, "%s", fmt);

	pr_debug("%s", buf);

	return 0;
}

struct pr_off_desc {
	u8 file_id;
	u8 flag;
	__le16 line_num;
	char fmt[];
};

char *strreplace(char *s, char old, char new)
{
	for (; *s; ++s)
		if (*s == old)
			*s = new;
	return s;
}

static int do_dprint(struct cl_hw *cl_hw, u32 fmtaddr, u32 nparams, u32 *params)
{
	/*
	 * fmtaddr - virtual address of format descriptor in firmware,
	 *           must be in the offloaded segment
	 * nparams - size of parameters array in u32; min=0, max=MAX_PRINT_OFF_PARAMS
	 * params  - array of parameters[nparams]
	 */
	struct cl_str_offload_env *str_offload_env = &cl_hw->str_offload_env;
	struct pr_off_desc *pfmt = NULL;

	if (!str_offload_env->enabled)
		return -1;

	if (fmtaddr & 0x3)
		cl_dbg_warn(cl_hw, "FW PRINT - format not aligned on 4? %8.8X\n", fmtaddr);

	if (fmtaddr > str_offload_env->base1 &&
	    fmtaddr < (str_offload_env->base1 + str_offload_env->size1)) {
		pfmt = (void *)((fmtaddr - str_offload_env->base1) + str_offload_env->block1);
	} else {
		cl_dbg_err(cl_hw, "FW PRINT - format not in allowed area %8.8X\n", fmtaddr);
		return -1;
	}

	/*
	 * Current string sent by firmware is #mac@ where # is '253' and @ is '254'
	 * Replace '253' with 'l'.
	 * Replace '254' with '0' or '1' according to chip index.
	 */
	strreplace(pfmt->fmt, (char)253, 'l');
	strreplace(pfmt->fmt, (char)254, (cl_hw->chip->idx == CHIP0) ? '0' : '1');

	if (offload_print(str_offload_env, pfmt->fmt, (char *)params) == -1) {
		cl_dbg_err(cl_hw, "FW PRINT - ERROR in format! (file %u:%u)\n",
			   pfmt->file_id, pfmt->line_num);
		hex_dump2(NULL, (void *)pfmt, 48, fmtaddr, true); /* $$$ dbg dump the struct */
		return -1;
	}

	return 0;
}

static int do_offload(struct cl_hw *cl_hw, u8 *data, int bytes_remaining)
{
	u8 magic2 = data[1];
	u32 nb = data[2] + (data[3] << 8); /* Following size in bytes */
	/* DATA IS UNALIGNED! REVISE if alignment required or BIG ENDIAN! */
	__le32 *dp = (__le32 *)data;
	int bytes_consumed = 4; /* 1 + 1 + 2 */

	/* Data: [0] u8 magic1, u8 magic2, u16 following size in bytes */
	if (bytes_remaining < 8) {
		cl_dbg_err(cl_hw, "*** FW PRINT - OFFLOAD PACKET TOO SHORT: %d\n",
			   bytes_remaining);
		return bytes_remaining;
	}

	if (bytes_remaining < (nb + bytes_consumed)) {
		cl_dbg_err(cl_hw, "*** FW PRINT - OFFLOAD PACKET %u > remainder %d??\n",
			   nb, bytes_remaining);
		return bytes_remaining;
	}

	switch (magic2) {
	case MAGIC_PRINT_OFF_PRINT: {
		/*
		 * [1] u32 format descriptor ptr
		 * [2] u32[] parameters
		 */
		u32 fmtp = le32_to_cpu(dp[1]);
		u32 np = (nb - 4) / 4; /* Number of printf parameters */

		if (nb < 4 || nb & 3)  {
			cl_dbg_err(cl_hw, "*** FW PRINT - bad pkt size: %u\n", nb);
			goto err;
		}

		do_dprint(cl_hw, fmtp, np, (u32 *)&dp[2]);

		bytes_consumed += nb; /* Already padded to 4 bytes */
		}
		break;

	case MAGIC_PRINT_OFF_LIT: {
		/* [1] Remaining bytes: literal string */
		do_print_n(cl_hw, (char *)&dp[1], nb);
		bytes_consumed += ((nb + 3) / 4) * 4; /* Padding to 4 bytes */
		}
		break;

	case MAGIC_PRINT_OFF_XDUMP:
		/* [1] bytes[nb] */
		if (nb >= 1)
			do_hex_dump_bytes(cl_hw, 0, &dp[1], nb);

		bytes_consumed += ((nb + 3) / 4) * 4; /* Padding to 4 bytes */
		break;

	default:
		cl_dbg_err(cl_hw, "*** FW PRINT - BAD TYPE: %4.4X\n", magic2);
		goto err;
	}

	return bytes_consumed;

err:
	return bytes_remaining; /* Skip all */
}

void cl_dbgfile_print_fw_str(struct cl_hw *cl_hw, u8 *str, int max_size)
{
	/* Handler for firmware debug prints */
	int bytes_remaining = max_size;
	int i;
	u8 delim = 0;

	while (bytes_remaining > 0) {
		/* Scan for normal print data: */
		for (i = 0; i < bytes_remaining; i++) {
			if (str[i] < ' ' || str[i] >= 0x7F) {
				if (str[i] == '\t')
					continue;
				delim = str[i];
				break;
			}
		}

		if (i > 0) {
			if (delim == '\n') {
				bytes_remaining -= i + 1;
				do_print_n(cl_hw, str, i);
				str += i + 1;
				continue;
			}

			if (delim != MAGIC_PRINT_OFFLOAD) {
				do_print_n(cl_hw, str, i);
				bytes_remaining -= i;
				return; /* Better stop parsing this */
			}
			/* Found offload packet but previous string not terminated: */
			do_print_n(cl_hw, str, i);
			cl_dbg_err(cl_hw, "*** FW PRINT - NO LINE END2\n");
			bytes_remaining -= i;
			str += i;
			continue;
		}

		/* Delimiter at offset 0 */
		switch (delim) {
		case '\n':
			do_print_n(cl_hw, " ", 1); /* Print empty line */
			str++;
			bytes_remaining--;
			continue;
		case 0:
			return;
		case MAGIC_PRINT_OFFLOAD:
			i = do_offload(cl_hw, str, bytes_remaining);
			bytes_remaining -= i;
			str += i;
			break;
		default:
			cl_dbg_err(cl_hw, "*** FW PRINT - BAD BYTE=%2.2X ! rem=%d\n",
				   delim, bytes_remaining);
			return; /* Better stop parsing this */
		}
	}
}


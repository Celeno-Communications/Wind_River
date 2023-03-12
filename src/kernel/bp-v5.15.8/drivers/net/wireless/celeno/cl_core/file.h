/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef FILE_H
#define FILE_H

#include <linux/firmware.h>
#include <linux/fs.h>
#include <linux/vmalloc.h>
#include "core_debug.h"
#include "chip.h"

#define CL_PATH_MAX 200
#define CL_FILENAME_MAX 100

/*
 * cl_file_write_buffer - Write a buffer to an open file.
 *
 * Writes @size bytes to file represented by @filp from @buf. This function exits only when
 * @size bytes have been written. Negative return codes indicate an error condition (see errno).
 */
static inline ssize_t cl_file_write_buffer(struct file *filp,
					   const char *buf, size_t size)
{
	/* Write a buffer to an open file */
	ssize_t offset = 0;
	ssize_t bytes_written = 0;

	while (offset < size) {
#if LINUX_VERSION_IS_GEQ(4, 14, 0)
		bytes_written = kernel_write(filp, buf + offset, size - offset, &filp->f_pos);
#else
		mm_segment_t old_fs = get_fs();

		set_fs(get_ds());
		bytes_written = vfs_write(filp, (const char __user *)(buf + offset),
					  size - offset, &filp->f_pos);
		set_fs(old_fs);
#endif

		if (bytes_written < 0)
			return bytes_written;

		offset += bytes_written;
	}

	return offset;
}

/*
 * cl_file_open_and_write - Open a file and write a buffer.
 *
 * Open file according to @flags and writes @size bytes to file represented by @filename
 * from @buf. This function returns 0 on success and -1 on failure.
 */
static inline int cl_file_open_and_write(const char *filename, int flags,
					 char *buf, size_t size)
{
	struct file *filp;
	size_t ret = 0;

	filp = filp_open(filename, flags, 0600);

	if (IS_ERR(filp))
		return -1;

	ret = cl_file_write_buffer(filp, buf, size);

	filp_close(filp, NULL);

	return (ret == size) ? 0 : -1;
}

/*
 * cl_file_open_and_read - Read the whole file into an allocated buffer.
 *
 * Allocates a buffer large enough to hold the contents of file at @filename
 * and reads the contents of that file into that buffer.
 * Upon success, the address of the allocated buffer is returned
 * (which needs to be free later). Upon failure, returns NULL.
 */
static inline size_t cl_file_open_and_read(struct cl_chip *chip,
					   const char *filename, char **buf)
{
	const struct firmware *fw;
	size_t size = 0;
	int ret = 0;
	char path_name[CL_PATH_MAX] = {0};

	snprintf(path_name, sizeof(path_name), "cl6k/%s", filename);
	ret = request_firmware_direct(&fw, path_name, chip->dev);

	if (ret) {
		cl_dbg_chip_err(chip, "request_firmware_direct %s failed\n",
				path_name);
		return 0;
	}

	if (!fw || !fw->data) {
		cl_dbg_chip_err(chip, "Invalid firmware %s\n", path_name);
		goto out;
	}

	size = fw->size;

	/*
	 * Add one byte with a '\0' so that string manipulation functions
	 * used for parsing these files can find the string '\0' terminator.
	 * Make sure size is aligned to 4.
	 */
	*buf = kzalloc(ALIGN(size + 1, 4), GFP_KERNEL);
	if (!(*buf)) {
		size = 0;
		goto out;
	}

	memcpy(*buf, fw->data, size);

out:
	release_firmware(fw);

	return size;
}
#endif /* FILE_H */

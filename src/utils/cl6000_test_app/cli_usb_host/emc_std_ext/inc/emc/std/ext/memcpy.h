/** @file
     Copyright (C) 2021 emsys Embedded Systems GmbH
 */

#ifndef EMC_STD_EXT_memcpy_H
#define EMC_STD_EXT_memcpy_H

#include "emc/std/configure.h"
#include "emc/std/stddef.h"

// clang-format off extern C
#if defined(__cplusplus)
  extern "C" {
#endif
// clang-format on extern C

/**
 * memcpy variant that's try's to copy cpu aligned data if possible else a byte wise copy is done
 * @param dst Destination buffer
 * @param src Source buffer
 * @param n Number of bytes to copy
 * @return pointer to dst
 */
void* emc_std_ext_memcpy(void* dst, const void* src, emc_std_size_t n);

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif // EMC_STD_EXT_memcpy_H

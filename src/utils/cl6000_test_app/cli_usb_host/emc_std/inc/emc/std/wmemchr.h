/**
 * @file
 * @brief   Includes or emulates wchar_t functions.
 * @author  Paul Kunysch <paul.kunysch@emsys.de>
 *
 * Copyright (C) 2007-2009, 2011 emsys Embedded Systems GmbH
 */

#ifndef EMC_STD_wmemchr_H
#define EMC_STD_wmemchr_H

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

#ifdef HAVE_WCSNCPY

#  include <wmemchr.h>

#else /* ndef HAVE_WCSNCPY */

#  include "emc/std/wchar.h"

#endif /* ndef HAVE_WCSNCPY */

#if EMC_WCHAR_IS_CHAR16
#  define emc_c16sncpy wcsncpy
#else
/** the specific 16-bit character string copy
    @param dst The destination of the copy operation
    @param src The source of the copy operation
    @param size The number of characters (not bytes) to copy in max case
    @return the destination
 */
EMC_MAYBE_INLINE char16_t* emc_c16sncpy(char16_t* dst, const char16_t* src, size_t size)
{
  size_t i;
  for (i = 0; i < size; ++i) {
    if (0 == (dst[i] = src[i])) {
      break;
    }
  }
  for (; i < size; ++i) {
    dst[i] = (char16_t)0;
  }
  return dst;
}

#endif

#if EMC_WCHAR_IS_CHAR32
#  define emc_c32sncpy wcsncpy
#else
/** the specific 32-bit character string copy
    @param dst The destination of the copy operation
    @param src The source of the copy operation
    @param size The number of characters (not bytes) to copy in max case
    @return the destination
 */
EMC_MAYBE_INLINE char32_t* emc_c32sncpy(char32_t* dst, const char32_t* src, size_t size)
{
  size_t i;
  for (i = 0; i < size; ++i) {
    if (0 == (dst[i] = src[i])) {
      break;
    }
  }
  for (; i < size; ++i) {
    dst[i] = (char32_t)0;
  }
  return dst;
}

#endif

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_STD_wmemchr_H */

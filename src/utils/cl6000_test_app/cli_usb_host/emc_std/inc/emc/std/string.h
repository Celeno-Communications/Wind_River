/**
 * @file
 * @brief The indirection header for string.h
 * Copyright (C) 2012-2013,2018 emsys Embedded Systems GmbH
 */

#ifndef EMC_STD_string_H
#define EMC_STD_string_H

#include "emc/std/stddef.h" /* size_t, NULL */

#if !EMC_STD_STDLIB_EMULATE && !defined(_lint)

#  include <string.h>

// clang-format off extern C
#  if defined(__cplusplus)
extern "C" {
#  endif
// clang-format on extern C

inline static void* emc_std_memcpy(void* restrict_s1, const void* restrict_s2, emc_std_size_t n)
{
  return (memcpy)(restrict_s1, restrict_s2, n);
}

inline static char* emc_std_strncpy(char* restrict_s1, const char* restrict_s2, emc_std_size_t n)
{
  return (strncpy)(restrict_s1, restrict_s2, n);
}

inline static int emc_std_memcmp(const void* s1, const void* s2, emc_std_size_t n)
{
  return (memcmp)(s1, s2, n);
}

inline static int emc_std_strcmp(const char* s1, const char* s2)
{
  return (strcmp)(s1, s2);
}

inline static int emc_std_strncmp(const char* s1, const char* s2, emc_std_size_t n)
{
  return (strncmp)(s1, s2, n);
}

inline static void* emc_std_memchr(const void* s, int c, emc_std_size_t n)
{
  return (void*)(memchr)(s, c, n);
}

inline static char* emc_std_strstr(const char* s1, const char* s2)
{
  return (char*)(strstr)(s1, s2);
}

inline static char* emc_std_strchr(const char* s, int c)
{
  return (char*)(strchr)(s, c);
}

inline static void* emc_std_memset(void* s, int c, emc_std_size_t n)
{
  return (memset)(s, c, n);
}

inline static char* emc_std_strerror(int errnum)
{
  return (strerror)(errnum);
}

inline static emc_std_size_t emc_std_strlen(const char* s)
{
  return (strlen)(s);
}

inline static emc_std_size_t emc_std_strnlen(const char* s, emc_std_size_t n)
{
#  if HAVE_STRNLEN_FUNC
  return (strnlen)(s, n);
#  else
  emc_std_size_t result = 0;
  while (n && *s++) {
    ++result;
    --n;
  }
  return result;
#  endif
}

// clang-format off extern C
#  if defined(__cplusplus)
}
#  endif
// clang-format on extern C

#else /* EMC_STD_STDLIB_EMULATE */

#  include "emc/std/emu/string.h"

#endif /* EMC_STD_STDLIB_EMULATE */

#endif /* EMC_STD_string_H */

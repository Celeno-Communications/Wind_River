/**
 * @file
 * @brief   C equivalent to C++ string_view
 *
 * @author  Karsten Pahnke <karsten.pahnke@emsys.de>
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_STD_EXT_string_view_H
#define EMC_STD_EXT_string_view_H

#include "emc/std/configure.h"
#include "emc/std/stddef.h"
#include "emc/std/string.h"
#include "emc/std/stdbool.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/** the string_view holds data and length, and does not add automaticaly \0 */
typedef struct emc_std_string_view {
  const char*    data;
  emc_std_size_t length;
} emc_std_string_view;

static inline emc_std_size_t emc_std_string_view_npos() { return (emc_std_size_t)(-1); }

static inline void emc_std_string_view_init(emc_std_string_view* view, const char* str)
{
  view->data = str;
  if (str) {
    view->length = emc_std_strlen(str);
  }
}

static inline void emc_std_string_view_init_range(emc_std_string_view* view, const char* begin, const char* end)
{
  view->data = begin;
  if (begin && end) {
    view->length = (emc_std_size_t)(end - begin);
  } else {
    view->length = 0;
  }
}

static inline emc_std_bool emc_std_string_view_equal(const emc_std_string_view* a, const emc_std_string_view* b)
{
  if ((a && b) && (a->length == b->length)) {
    return emc_std_strncmp(a->data, b->data, a->length) == 0;
  } else {
    return emc_std_false;
  }
}

static inline emc_std_size_t emc_std_string_view_rfind(const emc_std_string_view* view, char c)
{
  emc_std_size_t pos = view->length;
  while (pos && view->data[--pos] != c) {}
  return (view->data[pos] == c) ? pos : emc_std_string_view_npos();
}

// clang-format off extern C
#  ifdef __cplusplus
}
#  endif
// clang-format on extern C

#endif

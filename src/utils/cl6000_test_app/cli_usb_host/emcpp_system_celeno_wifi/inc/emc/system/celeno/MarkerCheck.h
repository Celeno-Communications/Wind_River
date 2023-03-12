/**
 * @file
 *
 * @author  Günter Hildebrandt <guenter.hildebrandt@emsys.de>
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/

#ifndef EMC_SYSTEM_CELENO_MarkerCheck_H
#define EMC_SYSTEM_CELENO_MarkerCheck_H

#include "emc/std/stdint.h"
#include "emc/std/string.h"
#include "emc/std/assert.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/** define this to activate the check */
#ifdef MARKER_CHECK

/** use the following macros in the application */
#  define MARKER_CHECK_INSTANCE(i) MarkerCheck i
#  define MARKER_CHECK_FORWARD(i) extern MarkerCheck i
#  define MARKER_CHECK_ELEMENT(e) emc_std_uint32_t e
#  define MARKER_CHECK_ELEMENT_SIZE sizeof(emc_std_uint32_t)

/** number of maximal markers to check */
#  ifndef MARKER_CHECK_MAX_MARKER
#    define MARKER_CHECK_MAX_MARKER 10
#  endif
#  define MARKER_CHECK_MAGIC 0x3F3F3F3F
typedef struct MarkerCheck {
  emc_std_uint32_t  active_count;
  emc_std_uint32_t* marker[MARKER_CHECK_MAX_MARKER];
} MarkerCheck;

/** initialize the object */
static inline void MarkerCheck_init(MarkerCheck* self)
{
  emc_std_memset(self, 0, sizeof(*self));
}

/** Add 32 bit value as marker to the object.
 *
 * The storage is provided by the caller and must be persistent.
 * The object stores a magic value in this storage and validates it with each call to
 * MarkerCheck_check.
 * @param self The instance
 * @param marker The caller provided storage for the marker
 * @return the size of the marker
 */
static inline emc_std_size_t MarkerCheck_add(MarkerCheck* self, emc_std_uint32_t* marker)
{
  emc_std_assert(self->active_count < MARKER_CHECK_MAX_MARKER);
  *marker = MARKER_CHECK_MAGIC;
  self->marker[self->active_count++] = marker;
  return sizeof(*marker);
}

/** Check the active markers */
static inline void MarkerCheck_check(MarkerCheck* self)
{
  emc_std_uint32_t i;
  for (i = 0; i < self->active_count; ++i) {
    /* if this fires a memory marker was overwritten */
    emc_std_assert(*self->marker[i] == MARKER_CHECK_MAGIC);
  }
}

#else
/** These macros define the object void */
#  define MARKER_CHECK_INSTANCE(i)
#  define MARKER_CHECK_FORWARD(i)
#  define MARKER_CHECK_ELEMENT(e)
#  define MARKER_CHECK_ELEMENT_SIZE 0
#  define MarkerCheck_init(s)
#  define MarkerCheck_add(s, m) 0
#  define MarkerCheck_check(s)
#endif

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_SYSTEM_CELENO_MarkerCheck_H */

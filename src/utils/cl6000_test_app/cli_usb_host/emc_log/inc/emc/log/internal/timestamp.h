/**
 * @file
 * @author <karsten.pahnke@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 */

#ifndef EMC_LOG_INTERNAL_timestamp_H
#define EMC_LOG_INTERNAL_timestamp_H

#include "emc/log/configure.h"

#ifndef EMC_LOG_TIMESTAMP

#  include "emc/std/ext/timestamp.h"

// clang-format off extern C
#ifdef __cplusplus /*  @srcdist keep  */
extern "C" {
#endif
// clang-format on extern C

#  ifdef __XTENSA__
extern unsigned xthal_get_ccount(void);
#    define EMC_LOG_TIMESTAMP() ((emc_std_uint64_t)xthal_get_ccount())
#  else
#    define EMC_LOG_TIMESTAMP() ((emc_std_uint64_t)emc_timestamp())
#  endif

// clang-format off extern C
#ifdef __cplusplus /*  @srcdist keep  */
}
#endif
// clang-format on extern C

#endif /* EMC_LOG_TIMESTAMP */
#endif

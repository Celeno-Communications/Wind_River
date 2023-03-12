/** @file
    @brief Abstraction of time stamp support from OS.
     Copyright (C) 2016 emsys Embedded Systems GmbH */

#ifndef EMC_STD_EXT_timestamp_H
#define EMC_STD_EXT_timestamp_H

#include "emc/std/configure.h"

// clang-format off extern C
#if defined(__cplusplus)
  extern "C" {
#endif
// clang-format on extern C

EMC_EXTENSION_TYPEDEF_LONG_LONG(timestamp_t);

#if EMC_STD_TIMESTAMP_NULL
#  include "emc/std/ext/private/timestamp_null.h"
#elif EMC_STD_TIMESTAMP_STD
#  include "emc/std/ext/private/timestamp_std.h"
#elif EMC_STD_TIMESTAMP_UTA
#  include "emc/std/ext/private/timestamp_uta.h"
#elif EMC_STD_TIMESTAMP_PTHREADS
#  include "emc/std/ext/private/timestamp_pth.h"
#elif EMC_STD_TIMESTAMP_WINDOWS
#  include "emc/std/ext/private/timestamp_windows.h"
#elif EMC_STD_TIMESTAMP_EMBOS
#  include "emc/std/ext/private/timestamp_embos.h"
#elif EMC_STD_TIMESTAMP_FREERTOS
#  include "emc/std/ext/private/timestamp_freertos.h"
#elif EMC_STD_TIMESTAMP_XTOS
#  include "emc/std/ext/private/timestamp_xtos.h"
#elif EMC_STD_TIMESTAMP_WDK
#  include "emc/std/ext/private/timestamp_wdk.h"
#elif EMC_STD_TIMESTAMP_XILINX
#  include "emc/std/ext/private/timestamp_extern.h"
#elif EMC_STD_TIMESTAMP_NET_EMSYS
#  include "emc/std/ext/private/timestamp_extern.h"
#elif EMC_STD_TIMESTAMP_EXTERN
#  include "emc/std/ext/private/timestamp_extern.h"
#else
#  error "No timestamp OS abstraction selected"
#endif

#include "emc/std/ext/private/timestamp_gen.h"

/** The following inactive code describes the most generic solution to calculate the time difference.
 * In a concrete case the correct "if" path is compile time
 * constant and the function can be reduced to
 * one return statement.
 *
   static inline timestamp_t emc_timestamp_difference(timestamp_t subtrahend, timestamp_t minuend )
   {
   if (((emc_timestamp_wrap() + 1) & emc_timestamp_wrap()) == 0  ) {
    return (subtrahend - minuend) & emc_timestamp_wrap();
   } else {
    if (subtrahend < minuend) {
      return emc_timestamp_wrap() + subtrahend - minuend;
    } else {
      return subtrahend - minuend;
    }
   }
   }
 */

// clang-format off extern C
#if defined(__cplusplus)
  }
#endif
// clang-format on extern C

#endif /* EMC_STD_EXT_timestamp_H */

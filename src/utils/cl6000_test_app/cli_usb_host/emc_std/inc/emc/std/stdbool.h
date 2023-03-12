/** @file
    @brief Boolean type and values.
    Copyright (C) 2013 emsys Embedded Systems GmbH */

#ifndef EMC_STD_stdbool_H
#define EMC_STD_stdbool_H

#include "emc/std/configure.h"

#if C_LIBRARY_HAS_STDBOOL_H && !EMC_STD_STDLIB_EMULATE
#  include <stdbool.h>
#endif /* C_LIBRARY_HAS_STDBOOL_H && !EMC_STD_STDLIB_EMULATE */

#if (C_LIBRARY_HAS_STDBOOL_H && !EMC_STD_STDLIB_EMULATE) || defined __cplusplus
#  define emc_std_bool bool
#  define emc_std_true true
#  define emc_std_false false
#else /* !((HAVE_STDBOOL_H && SYSTEM_HEADER) || !defined __cplusplus) */
#  define emc_std_bool _Bool
#  define emc_std_true 1
#  define emc_std_false 0
#  if C_COMPILER_TYPE == C_COMPILER_TYPE_MSVC
#    undef emc_std_bool
#    define emc_std_bool int
#  endif
#endif /* !C_LIBRARY_HAS_STDBOOL_H || EMC_STD_STDLIB_EMULATE */

/* C code should probably avoid emc_std_true/false and
   use '1' and '0' directly. */
/* Probably not needed:
 #define emc_std_bool_true_false_are_defined 1 */

#endif /* EMC_STD_stdbool_H */

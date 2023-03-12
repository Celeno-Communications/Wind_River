/**
 * @file
 * @brief   The indirection of the standard assert.h header.
 *
 * @author  Karsten Pahnke <karsten.pahnke@emsys.de> +49-3677-68977-0
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2004, 2005, 2006, 2011 emsys Embedded Systems GmbH
 *
 ****************************************************************************/

#ifndef EMC_STD_assert_H
#define EMC_STD_assert_H

#include "emc/std/configure.h"

#if EMC_STD_ASSERT_NONE
#  undef NDEBUG
#  define NDEBUG
#endif

#if defined(_lint)
/** Gimpel recommends to use 'assert(zero)' instead of 'assert(0)'
    @see http://www.gimpel.com/html/techfaq2.htm#q13 */
extern const int emc_lint_zero;
#else /* !defined(_lint) */
#  define emc_lint_zero 0
#endif /* !defined(_lint) */

/* clang-format off extern C */
#  if defined(__cplusplus)
extern "C" {
#  endif
/* clang-format on extern C */

/** 'Perfect' assert function for lint, never implemented. */
void emc_lint_assert(int expression);
/*lint -emacro(506,assert) "Constant value Boolean" */
/*lint ++d"assert(e)=emc_lint_assert(!!(e))" */
/*lint -function(__assert, emc_lint_assert) */

/* clang-format off extern C */
#  if defined(__cplusplus)
}
#  endif
/* clang-format on extern C */

#if defined(NDEBUG) || EMC_DOXYGEN
#  ifndef assert
#    define assert(expr) do {} while (0)
#  endif
#  define emc_std_assert assert
#elif EMC_STD_ASSERT_STD
#  include <assert.h>
#  define emc_std_assert assert
#elif EMC_STD_ASSERT_EMULATE
#  include "emc/std/emu/assert.h"
#  define emc_std_assert assert
#else
#  error "EMC_STD_ASSERT undefined."
#endif

#endif /* EMC_STD_assert_H */

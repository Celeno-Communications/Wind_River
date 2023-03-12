/** @file
    @brief Type and macros for advancing through a list of arguments.

    @see http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1124.pdf
         7.15 Variable arguments

    Copyright (C) 2011-2013 emsys Embedded Systems GmbH */

#ifndef EMC_STD_stdarg_H
#define EMC_STD_stdarg_H

#include "emc/std/configure.h"

#if !EMC_STD_STDLIB_EMULATE

#  if C_LIBRARY_HAS_STDARG_H
#    include <stdarg.h>
#  endif

#  define emc_std_va_arg va_arg
#  define emc_std_va_copy va_copy
#  define emc_std_va_end va_end
#  define emc_std_va_start va_start
typedef va_list emc_std_va_list;

#else /* EMC_STD_STDLIB_EMULATE */

#  include "emc/std/emu/stdarg.h"

#endif /* EMC_STD_STDLIB_EMULATE */

#endif /* EMC_STD_stdarg_H */

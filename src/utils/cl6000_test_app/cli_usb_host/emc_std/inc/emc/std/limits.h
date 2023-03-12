/** @file
    @brief The std limits

    @see www.open-std.org/jtc1/sc22/wg14/www/docs/n1256.pdf
         5.2.4.2.1 Sizes of integer types

    Copyright (C) 2011-2013 emsys Embedded Systems GmbH */

#ifndef EMC_STD_limits_H
#define EMC_STD_limits_H

#include "emc/std/configure.h"

#if !EMC_STD_STDLIB_EMULATE || (_MSC_WDK_VER >= 10010586)

#  include <limits.h>

#  include "emc/std/stdint.h"

#  define EMC_STD_INT_MAX INT_MAX
#  define EMC_STD_INT_MIN INT_MIN

#  define EMC_STD_LONG_MAX LONG_MAX
#  define EMC_STD_LONG_MIN LONG_MIN

#  define EMC_STD_U_LONG_LONG_MAX ULLONG_MAX

#  define EMC_STD_SIZE_MAX SIZE_MAX

//workaround for undefined PTRDIFF_MAX for specific compiler
#  ifndef PTRDIFF_MAX
#    if defined(__GNUC__)
#      if __LONG_MAX__ == 64
#        define EMC_STD_PTRDIFF_MAX (9223372036854775807L)
#      else
#        define EMC_STD_PTRDIFF_MAX (2147483647)
#      endif
#    elif defined(_MSC_VER)
#      ifdef _M_X64
#        define EMC_STD_PTRDIFF_MAX _I64_MAX
#      else
#        define EMC_STD_PTRDIFF_MAX _I32_MAX
#      endif
#    else
#      define EMC_STD_PTRDIFF_MAX EMC_STD_LONG_MAX
#    endif
#  else
#    define EMC_STD_PTRDIFF_MAX PTRDIFF_MAX
#  endif

#else /* EMC_STD_STDLIB_EMULATE */

// Define number required for a char
#  ifndef CHAR_BIT
#    define CHAR_BIT 8
#  endif

//FIXME do not use hard coded value for unknown int max
#  define EMC_STD_INT_MAX 2147483647
#  define EMC_STD_INT_MIN (-EMC_STD_INT_MAX - 1)

#  if defined __LONG_MAX__
#    define EMC_STD_LONG_MAX __LONG_MAX__
#  else
#    define EMC_STD_LONG_MAX 2147483647L
#  endif
#  define EMC_STD_LONG_MIN (-EMC_STD_LONG_MAX - 1)

#  define EMC_STD_U_LONG_LONG_MAX 0xFFFFFFFFFFFFFFFFULL

#  define EMC_STD_PTRDIFF_MAX EMC_STD_LONG_MAX

#endif /* EMC_STD_STDLIB_EMULATE */

#endif /* EMC_STD_limits_H */

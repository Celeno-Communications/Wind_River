/** @file
    @brief Several functions useful for classifying and mapping
           characters.

    @see www.open-std.org/jtc1/sc22/wg14/www/docs/n1256.pdf
         7.4 Character handling

    @see http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/ctype.h.html

    Copyright (C) 2011-2013 emsys Embedded Systems GmbH */

#ifndef EMC_STD_ctype_H
#define EMC_STD_ctype_H

#include "emc/std/configure.h"

#if !EMC_STD_STDLIB_EMULATE

#  include <ctype.h>

inline static int emc_std_tolower(int c) { return (tolower)(c); }

#  ifdef tolower
#    define emc_std_tolower(c) (tolower(c))
#  endif

inline static int emc_std_toupper(int c) { return (toupper)(c); }

#  ifdef toupper
#    define emc_std_toupper(c) (toupper(c))
#  endif

inline static int emc_std_isspace(int c) { return (isspace)(c); }

#  ifdef isspace
#    define emc_std_isspace(c) (isspace(c))
#  endif

inline static int emc_std_isdigit(int c) { return (isdigit)(c); }

#  ifdef isdigit
#    define emc_std_isdigit(c) (isdigit(c))
#  endif

inline static int emc_std_isxdigit(int c) { return (isxdigit)(c); }

#  ifdef isxdigit
#    define emc_std_isxdigit(c) (isxdigit(c))
#  endif

inline static int emc_std_isalpha(int c) { return (isalpha)(c); }

#  ifdef isalpha
#    define emc_std_isalpha(c) (isalpha(c))
#  endif

inline static int emc_std_isprint(int c) { return (isprint)(c); }

#  ifdef isprint
#    define emc_std_isprint(c) (isprint(c))
#  endif

#else /* EMC_STD_STDLIB_EMULATE */

#  include "emc/std/emu/ctype.h"

#endif /* EMC_STD_STDLIB_EMULATE */

#endif /* EMC_STD_ctype_H */

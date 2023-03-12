/** @file
    @brief Declares a type and two functions and defines several
           macros, for handling various signals.

    @see www.open-std.org/jtc1/sc22/wg14/www/docs/n1256.pdf
         7.14 Signal handling

    @see http://pubs.opengroup.org/onlinepubs/009695399/basedefs/signal.h.html

    Copyright (C) 2011, 2012 emsys Embedded Systems GmbH */

#ifndef EMC_STD_signal_H
#define EMC_STD_signal_H

#include "emc/std/configure.h"

#if !EMC_STD_STDLIB_EMULATE

#  ifdef __GNUC__
#    if GCC_VERSION >= 40700
#      pragma GCC diagnostic push
#      pragma GCC diagnostic ignored "-Wpedantic"
#    endif
#  endif

#  include <signal.h>

#  ifdef __GNUC__
#    if GCC_VERSION >= 40700
#      pragma GCC diagnostic pop
#    endif
#  endif

#  define emc_std_raise raise
#  define emc_std_signal signal
/*typedef sig_atomic_t emc_std_sig_atomic_t;*/

#  ifdef _POSIX_SOURCE
typedef union sigval emc_std_sigval;
#  endif

#  define EMC_STD_SIGABRT SIGABRT
#  define EMC_STD_SIGSEGV SIGSEGV

#  define EMC_STD_SIG_DFL SIG_DFL
#  define EMC_STD_SIG_ERR SIG_ERR

#else /* EMC_STD_STDLIB_EMULATE */

#  include "emc/std/emu/signal.h"

#endif /* EMC_STD_STDLIB_EMULATE */

#endif /* EMC_STD_signal_H */

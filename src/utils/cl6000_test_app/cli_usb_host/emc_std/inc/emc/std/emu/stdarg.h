/** @file
    @brief Type and macros for advancing through a list of arguments.

    @see http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1124.pdf
         7.15 Variable arguments

    Copyright (C) 2011-2013 emsys Embedded Systems GmbH */

#ifndef EMC_STD_EMU_stdarg_H
#define EMC_STD_EMU_stdarg_H

#include "emc/std/configure.h"

/** Expands to an expression that has the specified @p type and the value
    of the next argument in the call. */
#define emc_std_va_arg(ap, type) (*(type*)(((ap) += sizeof(type)) - sizeof(type)))

/** Initializes @p dest as a copy of @p src */
#define emc_std_va_copy(dest, src) do { (dest) = (src); } while (0)

/** Facilitates a normal return from a function after using va_copy() or va_start().
    @param ap shall have been initialized by va_start() or va_copy() */
#define emc_std_va_end(ap) do {} while (0)

/** The va_start macro shall be invoked before any access to the unnamed arguments.
    @param ap shall have been initialized by va_start() or va_copy()
    @param paramN is the identifier of the rightmost parameter in the
    variable parameter list of the function definition. */
#define emc_std_va_start(ap, paramN) do { (ap) = (char*)(&(paramN) + 1); } while (0)

typedef char* emc_std_va_list;

#endif /* EMC_STD_EMU_stdarg_H */

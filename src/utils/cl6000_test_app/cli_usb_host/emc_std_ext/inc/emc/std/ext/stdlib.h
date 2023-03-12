/** @file
    @brief Extensions to C standard library

    Copyright (C) 2016 emsys Embedded Systems GmbH */

#ifndef EMC_STD_EXT_stdlib_H
#define EMC_STD_EXT_stdlib_H

#include "emc/std/configure.h"

EMC_EXTERN_C_BEGIN;

/**
 * Converts an integer value to a null-terminated string using the specified base
 * and stores the result in the array given by str parameter.
 * This function is not defined in ANSI-C and is not part of C++, but is supported
 * by some compilers.
 * If base is 10 and value is negative, the resulting string is preceded with a minus sign.
 * With any other base, value is always considered unsigned.
 * @param value Value to be converted to a string.
 * @param str Array in memory where to store the resulting null-terminated string.
 * The caller is responsible for providing sufficient storage
 * @param base Numerical base used to represent the value as a string, between 2 and 36.
 * @return A pointer to the resulting null-terminated string, same as parameter str.
 */
char* emc_std_itoa(int value, char* str, int base);

#ifdef itoa
#  define emc_std_itoa(str, endptr, base) (itoa(str, endptr, base))
#endif

/// @copydoc emc_std_itoa
char* emc_std_litoa(long value, char* str, int base);

/**
 * Converts an integer value to a null-terminated string using the specified base
 * and stores the result in the array given by str parameter.
 * @param value Value to be converted to a string.
 * @param str Array in memory where to store the resulting null-terminated string.
 * The caller is responsible for providing sufficient storage
 * @param base Numerical base used to represent the value as a string, between 2 and 36.
 * @return A pointer to the resulting null-terminated string, same as parameter str.
 */
char* emc_std_utoa(unsigned int value, char* str, int base);

/// @copydoc emc_std_utoa
char* emc_std_lutoa(unsigned long value, char* str, int base);
EMC_EXTERN_C_END;

#endif /* EMC_STD_EXT_stdlib_H */

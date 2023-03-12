/** @file
    @brief Several functions useful for classifying and mapping
           characters.

    @see www.open-std.org/jtc1/sc22/wg14/www/docs/n1256.pdf
         7.4 Character handling

    @see http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/ctype.h.html

    Copyright (C) 2011-2013 emsys Embedded Systems GmbH */

#ifndef EMC_STD_EMU_ctype_H
#define EMC_STD_EMU_ctype_H

// clang-format off extern C
#  if defined(__cplusplus)
extern "C" {
#  endif
// clang-format on extern C

int emc_std_tolower(int c);
int emc_std_toupper(int c);
int emc_std_isspace(int c);
int emc_std_isdigit(int c);
int emc_std_isxdigit(int c);
int emc_std_isalpha(int c);
int emc_std_isprint(int c);

// clang-format off extern C
#  if defined(__cplusplus)
}
#  endif
// clang-format on extern C

#endif

/**
 * @file
 * @brief Emulate the standard @c @<wchar.h@> header.
 *
 * @see http://www.opengroup.org/onlinepubs/000095399/basedefs/wchar.h.html
 *
 * @author  Steffen <steffen.luzemann@emsys.de> +49-3677-68977-0
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 ****************************************************************************/
#ifndef EMC_STD_EMU_wchar_H
#define EMC_STD_EMU_wchar_H

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

#include "emc/std/stddef.h"

#if HAVE_CTYPE_H
#  include <ctype.h>
#endif

/**
 * copies the wide string pointed to by s2 (including the
 * terminating null wide character) into the array pointed to by s1
 *
 * @param s1 target string pointer
 * @param s2 string to copy
 *
 * @return value of s1
 */
emc_std_wchar_t* emc_wcscpy(emc_std_wchar_t* s1, const emc_std_wchar_t* s2);

/** Copy a string to a character array, fill remaining characters with
    zeroes.  The strncpy() function shall copy not more than @p length
    characters from the array pointed to by @n s2 to the array pointed to
    by @n s1.  If the string @p s2 is shorter than n, null characters shall
    be appended until @p length characters in all are written.
    @param s1 is the destination array with room for at least @p length characters.
    @param s2 is the null-terminated or @p length character long source string.
    @param length is the number of characters that will be written to @p s1. */
emc_std_wchar_t* emc_wcsncpy(emc_std_wchar_t* s1, const emc_std_wchar_t* s2, size_t length);

/**
 * returns number of unicode characters
 *
 * @param s pointer to string
 *
 * @return number of wide characters
 */
size_t emc_wcslen(const emc_std_wchar_t* s);

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

/** The preprocessor redirects wcslen() to emc_wcslen() */
#define wcslen emc_wcslen
/** The preprocessor redirects wcscpy() to emc_wcscyp() */
#define wcscpy emc_wcscpy
/** The preprocessor redirects wcsncpy() to emc_wcsncyp() */
#define wcsncpy emc_wcsncpy

#endif /* EMC_STD_EMU_wchar_H */

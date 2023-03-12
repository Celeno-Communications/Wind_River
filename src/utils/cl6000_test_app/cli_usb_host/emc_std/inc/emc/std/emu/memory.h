/**
 * @file
 * @brief   A redirection for the memory functions.
 *
 * @author  Karsten Pahnke <karsten.pahnke@emsys.de> +49-3677-68977-0
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 ****************************************************************************/

#ifndef EMC_STD_EMU_memory_H
#define EMC_STD_EMU_memory_H

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

#include <stdlib.h>

/** copies source to target until c is found in source,
    but no more than length character */
char* memcopy(char* target, const char* source, int c, unsigned int length);

#if !defined(_lint)
/* The return is not "const" with MSVC6 libraries. */
#  ifndef EMC_WITH_MSVC6_LIBRARY_WORKAROUNDS
/** search the first c in string str and
    supplies the address of c or 0 if c is
    not in the first length character */
void* memchr(const void* str, int c, size_t length);
#  endif /* ndef EMC_WITH_MSVC6_LIBRARY_WORKAROUNDS */
#endif /* lint */

/** compares strings str1 and str2, but no more than length charcter */
int memcmp(const void* str1, const void* str2, size_t length);

/** copies length character from source to target */
void* memcpy(void* target, const void* source, size_t length);

/** initializes the first length character of target with c */
void* memset(void* target, int c, size_t length);

/*lint -esym(746, memcpy)*/
/**\lint 746: call to function made without prototype\n
 * memcpy is often used without a prototype!\n
 * Karsten Pahnke <karsten.pahnke@emsys.de>
 */

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_STD_EMU_memory_H */

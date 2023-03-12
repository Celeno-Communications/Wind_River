/** @file
    @brief Emulate the standard @c @<string.h@> header.

    The C standard expects this header to define the @c NULL macro,
    the @c size_t type and two dozens of @c strxxx() and @c memxxx()
    functions.

    @see http://www.opengroup.org/onlinepubs/000095399/basedefs/string.h.html

    Copyright (C) 2013 emsys Embedded Systems GmbH
 */

#ifndef EMC_STD_EMU_string_H
#define EMC_STD_EMU_string_H

// clang-format off extern C
#  if defined(__cplusplus)
extern "C" {
#  endif
// clang-format on extern C

void* emc_std_memcpy(void* restrict_s1, const void* restrict_s2, emc_std_size_t n);
char* emc_std_strncpy(char* restrict_s1, const char* restrict_s2, emc_std_size_t n);
int emc_std_memcmp(const void* s1, const void* s2, emc_std_size_t n);
int emc_std_strcmp(const char* s1, const char* s2);
int emc_std_strncmp(const char* s1, const char* s2, emc_std_size_t n);
void* emc_std_memchr(const void* s, int c, emc_std_size_t n);
char* emc_std_strstr(const char* s1, const char* s2);
char* emc_std_strchr(const char* s, int c);
void* emc_std_memset(void* s, int c, emc_std_size_t n);
char* emc_std_strerror(int errnum);
emc_std_size_t emc_std_strlen(const char* s);
emc_std_size_t emc_std_strnlen(const char* s, emc_std_size_t n);

// clang-format off extern C
#  if defined(__cplusplus)
}
#  endif
// clang-format on extern C

#endif /* EMC_STD_EMU_string_H */

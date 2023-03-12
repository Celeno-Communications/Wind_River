/** @file
    @brief The indirection of stdio.h for all io operations.
    Copyright (C) 2004-2013 emsys Embedded Systems GmbH */
#ifndef EMC_STD_EMU_stdio_H
#define EMC_STD_EMU_stdio_H

#include "emc/std/stdarg.h"
#include "emc/std/stddef.h"

// clang-format off extern C
#  if defined(__cplusplus)
extern "C" {
#  endif
// clang-format on extern C

struct EmcStdFile; ///< @private

typedef struct EmcStdFile EMC_STD_FILE;
#define EMC_STD_IONBF 0
#define EMC_STD_IOLBF 1
#define EMC_STD_IOFBF 2
#define EMC_STD_SEEK_SET 0
#define EMC_STD_SEEK_CUR 1
#define EMC_STD_SEEK_END 2

int emc_std_puts(const char* s);
int emc_std_fputs(const char* restrict_s, EMC_STD_FILE* restrict_stream);
#define emc_std_stderr ((EMC_STD_FILE*)0)
#define EMC_STD_EOF ((int)(-1))

EMC_STD_FILE* emc_std_fopen(const char* restrict_filename, const char* restrict_mode);
emc_std_size_t emc_std_fread(void* restrict_ptr,
                             emc_std_size_t size,
                             emc_std_size_t nmemb,
                             EMC_STD_FILE* restrict_stream);
emc_std_size_t emc_std_fwrite(const void* restrict_ptr,
                              emc_std_size_t size,
                              emc_std_size_t nmemb,
                              EMC_STD_FILE* restrict_stream);
int emc_std_fseek(EMC_STD_FILE* stream, long int offset, int whence);
int emc_std_fclose(EMC_STD_FILE* stream);
int emc_std_ferror(EMC_STD_FILE* stream);
int emc_std_feof(EMC_STD_FILE* stream);
#if defined(_POSIX_SOURCE)
int emc_std_fileno(EMC_STD_FILE* stream);
#endif
int emc_std_setvbuf(EMC_STD_FILE* restrict_stream,
                    char* restrict_buf,
                    int mode,
                    size_t size);
int emc_std_fprintf(EMC_STD_FILE* restrict_stream, const char* restrict_format, ...);
int emc_std_vfprintf(EMC_STD_FILE* restrict_stream,
                     const char* restrict_format,
                     emc_std_va_list arg);
int emc_std_snprintf(char* restrict_s, size_t n, const char* restrict_format, ...);
int emc_std_vsnprintf(char* restrict_s,
                      size_t n,
                      const char* restrict_format,
                      emc_std_va_list arg);

// clang-format off extern C
#  if defined(__cplusplus)
}
#  endif
// clang-format on extern C

#endif /* EMC_STD_stdio_H */

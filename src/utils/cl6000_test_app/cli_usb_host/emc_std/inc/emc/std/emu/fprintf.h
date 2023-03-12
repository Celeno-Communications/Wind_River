/** @file
    @brief Declare fprintf() related functions and types from @c @<stdio.h@>. */
#ifndef EMC_STD_EMU_fprintf_H
#define EMC_STD_EMU_fprintf_H

#include <emc/std/stdarg.h>

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

#if !C_LIBRARY_HAS_FILE_TYPE
#  ifdef stdout
#    undef stdout
#  endif
#  define stdout 0 /**< Emulate the @c FILE* for standard output if @c @<stdio.h@> doesn't have it */

#  ifdef stderr
#    undef stderr
#  endif
#  define stderr 0 /**< Emulate the @c FILE* for standard error if @c @<stdio.h@> doesn't have it */

#  ifdef stdin
#    undef stdin
#  endif
#  define stdin 0 /**< Emulate the @c FILE* for standard input if @c @<stdio.h@> doesn't have it */

/** The FILE structure for buffered IO requests. */
typedef struct FILE {
  int dummy; /**< A small placeholder to reserve at least some space */
} FILE;

#endif /* !C_LIBRARY_HAS_FILE_TYPE */

/** Open the file whose pathname is the string pointed to by filename */
FILE* fopen(const char* filename, const char*);

/** Flush the stream and close the associated file.
    @todo Why are we returning void? */
void fclose(FILE*);

/** Cause any unwritten data to be written to a file.
    @param stream may be NULL to flush all open files.
    @todo Why are we returning void? */
void fflush(FILE* stream);

/** Print formatted output */
int fprintf(FILE* f, const char* form, ...);

/** Convert formatted input */
int fscanf(FILE* f, const char* form, ...);

/** Format output of a @c @<stdarg.h@> argument list */
int vfprintf(FILE* f, const char* form, va_list);

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_STD_EMU_fprintf_H */

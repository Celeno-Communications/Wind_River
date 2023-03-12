/** @file
    @brief The compiler specific configuration for clang
    Copyright (C) 2011, 2012, 2020 emsys Embedded Systems GmbH */

#ifndef EMC_CONFIG_COMPILER_cfg_clang_H
#define EMC_CONFIG_COMPILER_cfg_clang_H

/** The GCC based version info
 * Version 3.6 of Clang is "compatible" with GCC 4.2.1,
 * so most of the switches will make some sense.
 * check if this is realy required any longer
 */
#define GCC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)

/** The Clang versions, not GCC emulation level */
#define CLANG_VERSION (__clang_major__ * 10000 + __clang_minor__ * 100 + __clang_patchlevel__)

/* GCC 2.x and above */

#ifdef __STRICT_ANSI__
#  define inline __inline__
#endif

/** GNU libraries support the @c @<stdbool.h@> header in C and C++
    modes.  This is a standard header for C compilers.  GNU supports
    it even for C++. */
#undef C_LIBRARY_HAS_STDBOOL_H
#define C_LIBRARY_HAS_STDBOOL_H 1

/* #ifdef __CYGWIN__ */
/** Cygwin headers incorrectly return a non-const result in C++ mode.

    It's still not fixed in cygwin-1.7.5-1.  Other gcc distributions
    don't have such problems, for example libc6-dev 2.10.1-0ubuntu17.

    @internal
    It doesn't help to invert the switch with recent GNU C headers
    because both variants are 'extern "C++"' and mixing our emulation
    with their headers must be avoided. */
/* Version check commands for cygwin and ubuntu or debian:
   $ cygcheck -f /usr/include/string.h => cygwin-1.7.5-1
   $ dpkg -S /usr/include/string.h => libc6-dev
   $ dpkg --status libc6-dev */
#undef C_LIBRARY_MEMCHR_RETURN_CONST
#define C_LIBRARY_MEMCHR_RETURN_CONST 0
/* #endif *//* def __CYGWIN__ */

/** Use <tt>inline static</tt> for inlining */
#undef C_COMPILER_INLINE_TYPE
#define C_COMPILER_INLINE_TYPE C_COMPILER_INLINE_TYPE_inline_static

#define HAVE_SYS_STATFS_H 1 /**< The library has the non-standard @<sys/statfs.h@> header */
#define HAVE_UNISTD_H 1     /**< The library has the non-standard @<unistd.h@> header */

/* GCC 3.x and above */

#if GCC_VERSION >= 30000

/** The attribute @c noreturn is implemented since gcc 2.5 */
#  undef  EMC_ATTRIBUTE_NORETURN
#  define EMC_ATTRIBUTE_NORETURN __attribute__((noreturn))

/** GCC can check a printf-like format string and its parameters.  If
    parameters are passed as vargs like in vprintf, then zero must be
    used as @p ELLIPSIS_POS.  */
#  undef  EMC_ATTRIBUTE_PRINTF
#  define EMC_ATTRIBUTE_PRINTF(FORMATSTRING_POS, ELLIPSIS_POS) \
  __attribute__((format(printf, FORMATSTRING_POS, ELLIPSIS_POS)))

/** A @<memory.h@> header redirects to the standard @<string.h@> header */
#  undef C_LIBRARY_HAS_MEMORY_H
#  define C_LIBRARY_HAS_MEMORY_H 1

/* GCC 4.x and above */

#  if GCC_VERSION >= 40000

/* Sourcery 2009q1-203 workaround: see r41901 */

/* New gcc compilers support u"16bit" literals if the "-std=" option
   with "gnu99", "c++0x" or "gnu++0x" is used.  Some builds accept
   "c++0x" but do not support explicit 2-byte string literals, so we
   first check __CHAR16_TYPE__ to detect recent builds. */
#    if defined(__CHAR16_TYPE__)
#      if (defined(__cplusplus) && (__cplusplus >= 201103L)) || \
  (defined(__STDC_VERSION__) && !defined(__STRICT_ANSI__))
#        undef HAVE_CHAR16_T
#        define HAVE_CHAR16_T 1
#      endif
#    endif

#    undef HAVE_CTYPE_H
#    define HAVE_CTYPE_H 1 /**< The header @c @<ctype.h@> is available */

#  endif /* >= 4 */
#endif /* >= 3 */

#endif /* EMC_CONFIG_COMPILER_cfg_clang_H */

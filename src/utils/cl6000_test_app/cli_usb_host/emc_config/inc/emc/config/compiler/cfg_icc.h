/** @file
    @brief The Intel Compiler specific configuration
    Copyright (C) 2014 emsys Embedded Systems GmbH */

#ifndef EMC_CONFIG_COMPILER_cfg_icc_H
#define EMC_CONFIG_COMPILER_cfg_icc_H

#ifdef __CHAR16_TYPE__
#  if (defined(__cplusplus) && (__cplusplus >= 201103L)) || \
  (defined(__STDC_VERSION__) && !defined(__STRICT_ANSI__))
#    undef HAVE_CHAR16_T
#    define HAVE_CHAR16_T 1
#  endif
#endif

/** ICC uses GNU libraries when running linux or cygwin.
 *  GNU libraries support the @c @<stdbool.h@> header in C and C++
    modes.  This is a standard header for C compilers.  GNU supports
    it even for C++. */
#undef C_LIBRARY_HAS_STDBOOL_H
#define C_LIBRARY_HAS_STDBOOL_H 1

#define HAVE_SYS_STATFS_H 1 /**< The library has the non-standard @<sys/statfs.h@> header */
#define HAVE_UNISTD_H 1     /**< The library has the non-standard @<unistd.h@> header */

#endif /* EMC_CONFIG_COMPILER_cfg_icc_H */

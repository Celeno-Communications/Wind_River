/** @file
    @brief Configuration values for the Microsoft Visual C 6.0 compiler.
    Copyright (C) 2004-2008, 2011 emsys Embedded Systems GmbH
 */
#ifndef EMC_CONFIG_COMPILER_cfg_msvc6_H
#define EMC_CONFIG_COMPILER_cfg_msvc6_H

/** Visual C++ headers may not declare fprintf() */
#undef C_LIBRARY_HAS_FPRINTF
#define C_LIBRARY_HAS_FPRINTF 0

/** Visual C++ headers do not overload memchr(). */
#undef C_LIBRARY_MEMCHR_RETURN_CONST
#define C_LIBRARY_MEMCHR_RETURN_CONST 0

/** Use @c __inline for inlining.
    The regular @c inline identifier is only available in C++ mode. */
#ifndef inline
#  define inline __inline
#endif

#ifndef __func__
#  if 1
static const char emc__func__[] = "?";
#    ifdef __func__
#      undef __func__
#    endif
#    define __func__ emc__func__
#  else
/* Redirecting to __FUNCTION__ is an option, but the results will
   look like __PRETTY_FUNCTION__ strings from other compilers. */
#    define __func__ __FUNCTION__
#  endif
#endif

/** The standard header @c @<wctype.h@> is available if not building drivers (kernel mode) */
#undef HAVE_WCTYPE_H
#ifdef _KERNEL_MODE
#  define HAVE_WCTYPE_H 0
#else
#  define HAVE_WCTYPE_H 1
#endif

#endif /* EMC_CONFIG_COMPILER_cfg_msvc6_H */

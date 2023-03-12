/** @file
    @brief Configuration values for the Microsoft Visual C 6.0 compiler.
    Copyright (C) 2004-2008, 2011 emsys Embedded Systems GmbH
 */
#ifndef EMC_CONFIG_COMPILER_cfg_msvc_H
#define EMC_CONFIG_COMPILER_cfg_msvc_H

/** Visual C++ headers may not declare fprintf() */
#undef C_LIBRARY_HAS_FPRINTF
#define C_LIBRARY_HAS_FPRINTF 0

/** Visual C++ headers do not overload memchr(). */
#undef C_LIBRARY_MEMCHR_RETURN_CONST
#define C_LIBRARY_MEMCHR_RETURN_CONST 0

/** For any references to C- and C++ STD library,
 * the Microsoft compiler uses __cdecl convention per default in 32 bit/ARM mode.
 * 64bit compile do not require such convention, but it does not harm.
 * For further info see also https://msdn.microsoft.com/de-de/library/984x0h58.aspx
 */
#undef C_LIBRARY_EXTERNAL_CALLING_CONVENTION
#define C_LIBRARY_EXTERNAL_CALLING_CONVENTION __cdecl

/** Use @c __inline for inlining.
    The regular @c inline identifier is only available in C++ mode. */
#ifndef inline
#  define inline __inline
#endif
#undef _ALLOW_KEYWORD_MACROS
#define _ALLOW_KEYWORD_MACROS

// clang-format off
#undef C_COMPILER_SUPPORTS_INCLUDE_NEXT
#define C_COMPILER_SUPPORTS_INCLUDE_NEXT 0

#undef C_COMPILER_NATIVE_INCLUDE
#define C_COMPILER_NATIVE_INCLUDE(filename) <../include/filename>
// clang-format on

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
#if defined(_KERNEL_MODE) || (_MSC_WDK_VER >= 10010586)
#  define HAVE_WCTYPE_H 0
#else
#  define HAVE_WCTYPE_H 1
#endif

#if _MSC_VER >= 1300 /* Visual Studio 2002, Visual C 7.0 */
/** Visual Studio 2002 and 2003 support @c fprintf() */
#  undef C_LIBRARY_HAS_FPRINTF
#  define C_LIBRARY_HAS_FPRINTF 1
#endif

#if _MSC_VER >= 1400 /* Visual Studio 2005, Visual C 8 */
/** Visual C++ 2005 deprecated many standard functions by default. */
#  undef C_LIBRARY_HAS_FPRINTF
#  define C_LIBRARY_HAS_FPRINTF 0

/** Visual C++ correctly overload %memchr() since 2008.
    If @c _CONST_RETURN is defined the old behavior is used. */
#  undef C_LIBRARY_MEMCHR_RETURN_CONST
#  if defined __cplusplus && !defined _CONST_RETURN
#    define C_LIBRARY_MEMCHR_RETURN_CONST 1
#  else
#    define C_LIBRARY_MEMCHR_RETURN_CONST 0
#  endif

#  undef HAVE_CTYPE_H
#  define HAVE_CTYPE_H 1 /**< The header @c @<ctype.h@> is available */

#  undef HAVE_DIRECT_H
#  define HAVE_DIRECT_H 1 /**< The header @c @<direct.h@> is available */
#endif

#if _MSC_VER >= 1600 /* Visual Studio 2011, Visual C 10 */
#  if defined(_HAS_CHAR16_T_LANGUAGE_SUPPORT) && _HAS_CHAR16_T_LANGUAGE_SUPPORT
#    undef HAVE_CHAR16_T
#    define HAVE_CHAR16_T 1
#  else
#    define _CHAR16T /* to prevent redefinition in yvals.h */
#  endif
#endif

#if _MSC_VER >= 1700 /* Visual Studio 2012, Visual C 11 */
#  undef C_LIBRARY_HAS_STDINT_H
#  undef C_LIBRARY_HAS_STDARG_H
/* WDK10 has no stdint.h, we need full emulation */
#  if defined(_KERNEL_MODE) || (_MSC_WDK_VER >= 10010586)
#    define C_LIBRARY_HAS_STDINT_H 0
#    define  C_LIBRARY_HAS_STDARG_H 0
#  else
#    define C_LIBRARY_HAS_STDINT_H 1
#    define  C_LIBRARY_HAS_STDARG_H 1
#  endif
#endif

#if _MSC_VER >= 1900 /* Visual Studio 2015, Visual C 14 */
#  define  HAVE_STRUCT_TIMESPEC 1
#  define  HAVE_REFERENCE_WRAPPER 1
#  if defined(_KERNEL_MODE) || (_MSC_WDK_VER >= 10010586)
#  else
#    undef  C_LIBRARY_HAS_STDBOOL_H
#    define  C_LIBRARY_HAS_STDBOOL_H 1
#  endif
#  if defined(_KERNEL_MODE) || (_MSC_WDK_VER >= 10010586)
#    define NOMINMAX 1 /* we want to use our own std::min and std::max implementations,
                          disable the ntdef.h variants */
#  endif
#endif

#endif /* EMC_CONFIG_COMPILER_cfg_msvc_H */

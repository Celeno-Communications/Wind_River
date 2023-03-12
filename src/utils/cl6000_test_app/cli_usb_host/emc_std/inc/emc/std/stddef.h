/** @file
    @brief NULL and offsetof macros, ptrdiff_t and size_t types.
    C provides a typedef for wchar_t, C++ provides the nullptr_t typedef.
    Copyright (C) 2009-2013 emsys Embedded Systems GmbH */

#ifndef EMC_STD_stddef_H
#define EMC_STD_stddef_H

#include "emc/std/configure.h"

#if !EMC_STD_STDLIB_EMULATE && C_LIBRARY_HAS_STDDEF_H

#  if C_LIBRARY_HAS_STDDEF_H
#    include <stddef.h>
#  endif
typedef ptrdiff_t emc_std_ptrdiff_t;
typedef size_t    emc_std_size_t;
EMC_EXTENSION_TYPEDEF_LONG_LONG(emc_std_max_align_t);
typedef wchar_t emc_std_wchar_t;
#  ifndef emc_std_offsetof
#    define emc_std_offsetof(type, member) offsetof(type, member)
#  endif

#else /* EMC_STD_STDLIB_EMULATE */

#  if  defined(__GNUC__)

typedef __SIZE_TYPE__    size_t;
typedef __PTRDIFF_TYPE__ ptrdiff_t;
#    if !defined(__cplusplus)
// for C++ compile we have (obviously) built-in wchar_t
typedef __WCHAR_TYPE__ wchar_t;
#    endif

#  elif defined(__ARMCC_VERSION)

#    ifndef __size_t
typedef unsigned int size_t;
#      define __size_t 1
#    endif

typedef signed int ptrdiff_t;
#    if !defined(__cplusplus)
typedef short unsigned wchar_t;
#    endif

#  elif defined(_MSC_VER)

#    ifdef  _WIN64
typedef __int64 ptrdiff_t;
#    else
typedef int ptrdiff_t;
#    endif

#    ifdef  _M_X64
typedef unsigned __int64 size_t;
#    else
typedef unsigned int size_t;
#    endif

#    if !defined(_WCHAR_T_DEFINED)
typedef unsigned short wchar_t;
#    endif

#  else
#    error Unsupported compiler for C-STD library type emulation.
#  endif

typedef ptrdiff_t emc_std_ptrdiff_t;
typedef size_t    emc_std_size_t;
EMC_EXTENSION_TYPEDEF_LONG_LONG(emc_std_max_align_t);
typedef wchar_t emc_std_wchar_t;

/** The offset to the @p member from the beginning of its
    structure @p type as @c size_t bytes */
#  ifndef emc_std_offsetof
#    ifdef CPP_COMPILER_OFFSETOF
#      define emc_std_offsetof(type, member) CPP_COMPILER_OFFSETOF(type, member)
#    else
#      define emc_std_offsetof(type, member) \
  ((emc_std_size_t)((char*)&(((type*)0)->member) - (char*)0))
#    endif
#  endif

#endif /* EMC_STD_STDLIB_EMULATE */

#define EMC_STD_NULL ((void*)0)

#endif /* EMC_STD_stddef_H */

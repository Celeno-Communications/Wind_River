/**
 * @file
 * @brief Sets compiler-specific configuration values.
 *
 * Refer to the @ref emc_config_config_interface group for interface
 * elements.
 *
 * Many settings describe a specific compiler.  Here we set common
 * default values first and change them in compiler specific headers
 * later.  This keeps a list of expected defines in a central place,
 * and this simplifies documentation.
 *
 * @author  Uwe Markl <uwe.markl@emsys.de> +49-3677-68977-0
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2004-2013, 2020 emsys Embedded Systems GmbH
 */

#ifndef EMC_CONFIG_COMPILER_configure_H
#define EMC_CONFIG_COMPILER_configure_H

/** True when generating documentation.  Doxygen sets this to see
    explicitly marked code fragments.  Examine it to always include
    something in the documentation.  This avoids error-prone @c @@def
    @c @<name@> doxygen commands.

    @code
 #if EMC_ASSERT==EMC_ASSERT_NO_EMULATE || EMC_DOXYGEN
    /"* This comment is unconditionally visible to Doxygen. "/
 #define emc_std_assert(X) do {} while(0)
 #endif
    @endcode */
#ifdef DOXYGEN_ONLY
#  define EMC_DOXYGEN 1
#else
#  define EMC_DOXYGEN 0
#endif

/**
 * Always include a code fragment in source distributions.  Our
 * srcdist tool sets it to keep marked code fragments, even if they're
 * not used in the distributed @e eme configurations.
 *
 * @code
 * #if 0 // @srcdist keep
 *   It's easier to use a @srcdist keep comment to prevent the
 *   deletion of a code block in the following line. But here
 *   #includes won't be followed.
 * #endif
 * @endcode
 */
#ifndef EMC_SOURCEDIST
#  ifdef __WAVE__
#    define EMC_SOURCEDIST 1
#  else /* @srcdist keep */
#    define EMC_SOURCEDIST 0
#  endif
#endif

/** The non existing operating system.
    @internal
    Avoid "0" as constant since DEFINED_AS_ZERO == UNDEFINED is true
    with some compilers. */
#define EMC_OS_TYPE_NONE -1

#ifndef EMC_OS_TYPE /** The default target OS type */
#  define EMC_OS_TYPE EMC_OS_TYPE_NONE
#endif /* ndef EMC_OS_TYPE */
#if EMC_OS_TYPE != EMC_OS_TYPE_NONE
#  include "emc/os/configure_defines.h"
#endif /* EMC_OS_TYPE != EMC_OS_TYPE_NONE */

/** @defgroup emc_config_config_interface Configuration
    @ingroup emdoc_emc_config
    Overall library and compiler settings, defining capabilities and
    standard data types. */

/** @addtogroup emc_config_config_interface *//** @{ */

/** True if @c @<stdarg.h@> can be included */
#define C_LIBRARY_HAS_STDARG_H 1

/** True if @c @<stddef.h@> can be included */
#define C_LIBRARY_HAS_STDDEF_H 1

/** True if @c @<stdbool.h@> can be included */
#define C_LIBRARY_HAS_STDBOOL_H 0

/** True if @c @<stdint.h@> can be included */
#define C_LIBRARY_HAS_STDINT_H 1

/** True if @c @<stdatomic.h@> can be included */
#define C_LIBRARY_HAS_STDATOMIC_H 0

/** True if @c @<threads.h@> can be included */
#define C_LIBRARY_HAS_THREADS_H 0

/** True if @c @<stdio.h> declares @c FILE */
#define C_LIBRARY_HAS_FILE_TYPE 1

/** True if @c @<stdio.h> declares @c fprintf() */
#define C_LIBRARY_HAS_FPRINTF 1

/** True if @c @<fcntl.h@> can be included */
#define C_LIBRARY_HAS_FCNTL 1

#if !defined(C_LIBRARY_HAS_WCHAR_H) || EMC_DOXYGEN
/** True if @c @<wchar.h@> can be included */
#  define C_LIBRARY_HAS_WCHAR_H 1
#endif

/** Define calling convention for C STD library.
    @hideinitializer */
#define C_LIBRARY_EXTERNAL_CALLING_CONVENTION

/** True if @c @<wctype.h@> can be included */
#define HAVE_WCTYPE_H 0

/** True if @c @<ctype.h@> can be included */
#define HAVE_CTYPE_H 0

/** True if @c @<direct.h@> can be included */
#define HAVE_DIRECT_H 0

/** True if u"16bit" string literals are supported and @c char16_t is
    a builtin type in C++ */
#define HAVE_CHAR16_T 0

/** True if the function strnlen() is available */
#define HAVE_STRNLEN_FUNC 0

/** True if the function strnlen_s() is available */
#define HAVE_STRNLEN_S_FUNC 0

/** True if <tt>memchr(const void*, char)</tt> returns a <tt>const
    void*</tt> pointer.

    This value is used to support mixing of emulation and default
    headers in C++ sources.

    In C mode all libraries return non-const pointers as expected.  In
    C++ @c memchr() should be overloaded to return const or non-const
    pointers, depending on it's arguments.  Some C++ libraries always
    return non-const pointers. */
#ifdef __cplusplus
#  define C_LIBRARY_MEMCHR_RETURN_CONST 1
#else
#  define C_LIBRARY_MEMCHR_RETURN_CONST 0
#endif

/** True if a C-style cast to void is allowed */
#define C_COMPILER_SUPPORTS_VOID_CAST 1

/** True for most compilers.
    Currently this is only used with Keil compilers to include additional headers.
    @hideinitializer */
#define C_COMPILER_HAS_UNIQUE_PTR_SIZE 1

/** True for sane compilers */
#define C_COMPILER_SUPPORTS_NON_VOID_MAIN 1

/** True for sane compilers */
#define C_COMPILER_SUPPORTS_NON_VOID_MAIN_ARGS 1

/** True if enums are signed integers */
#define C_COMPILER_USES_SIGNED_ENUM 0

/** Describes the header that contains functions from the standard @c
    @<string.h@> header.  In theory a broken library could move some
    @c @<string.h@> functions to a non-standard @c @<memory.h@>
    header, but currently we don't have such a case.

    @see http://www.opengroup.org/onlinepubs/000095399/basedefs/string.h.html */
#define C_LIBRARY_MEMORY_H C_LIBRARY_MEMORY_H_STRING

/** @} */

#define C_COMPILER_SUPPORTS_INCLUDE_NEXT 1
#define C_COMPILER_NATIVE_INCLUDE(filename)

#define C_COMPILER_TYPE_GCC 2      /**< Most GNU C compilers */
#define C_COMPILER_TYPE_ADS 4      /**< The ARM Developer Suite and RealView compilers */
#define C_COMPILER_TYPE_MICROTEC 6 /**< The Microtec compilers */
#define C_COMPILER_TYPE_MSVC 7     /**< The Microsoft Visual C compilers */
#define C_COMPILER_TYPE_BC5 8      /**< The Borland C++ 5 compiler */
#define C_COMPILER_TYPE_ST9GCC 9   /**< GNU C cross-compiler for ST9 */
#define C_COMPILER_TYPE_KEIL 10    /**< The Keil C51/CX51 compilers */
#define C_COMPILER_TYPE_KEIL166 12 /**< The Keil C166 compiler */
#define C_COMPILER_TYPE_CC386 13   /**< The CADUL CC386 compiler */
#define C_COMPILER_TYPE_TMS470 14  /**< A compiler for TMS470 ARM7-based microcontrollers */
#define C_COMPILER_TYPE_CJ2 15     /**< Some obscure compiler */
#define C_COMPILER_TYPE_IAR 16     /**< The IAR Compiler Tool Suite */
#define C_COMPILER_TYPE_KEIL251 17 /**< The Keil C166 compiler */
#define C_COMPILER_TYPE_CLANG 18   /**< Main compiler suite of the llvm project */
#define C_COMPILER_TYPE_ICC 19     /**< The Intel C/C++ compiler */
#define C_COMPILER_TYPE_XTENSA 20  /**< The Cadence Xtensa C/C++ compiler */

#define C_LIBRARY_MEMORY_H_NONE 0   /**< Don't include library headers for memory operations */
#define C_LIBRARY_MEMORY_H_STRING 1 /**< Use the standard header for memory operations */
#define C_LIBRARY_MEMORY_H_MEMORY 2 /**< Use an alternative header for memory operations */

#define EMC_ATTRIBUTE_NORETURN                               /**< Assume that a function never returns */
#define EMC_ATTRIBUTE_PRINTF(FORMATSTRING_POS, ELLIPSIS_POS) /**< Check printf-like parameters */

#undef C_COMPILER_TYPE

#if defined(ST9PLUS)
#  define C_COMPILER_TYPE C_COMPILER_TYPE_ST9GCC
#  include "emc/config/compiler/configure_st9gcc.h"

#elif defined(__clang__)

#  define C_COMPILER_TYPE C_COMPILER_TYPE_CLANG
#  include "emc/config/compiler/cfg_clang.h"

#elif defined(__ICC) || defined(__INTEL_COMPILER)

#  define C_COMPILER_TYPE C_COMPILER_TYPE_ICC
#  include "emc/config/compiler/cfg_icc.h"

#elif defined(__XCC__)
#  define C_COMPILER_TYPE C_COMPILER_TYPE_XTENSA
#  include "emc/config/compiler/cfg_xtensa.h"

#elif defined(__GNUC__) && !defined(__ARMCC_VERSION)

#  define C_COMPILER_TYPE C_COMPILER_TYPE_GCC
#  include "emc/config/compiler/cfg_gcc.h"

#elif defined(__IAR_SYSTEMS_ICC__)
#  define C_COMPILER_TYPE C_COMPILER_TYPE_IAR
#  include "emc/config/compiler/cfg_iar.h"

#elif defined(__arm)
#  define C_COMPILER_TYPE C_COMPILER_TYPE_ADS
#  include "emc/config/compiler/cfg_ads.h"

#elif defined(_MSC_VER)
#  define C_COMPILER_TYPE C_COMPILER_TYPE_MSVC
#  include "emc/config/compiler/cfg_msvc.h"

#elif defined(_MICROTEC)
#  define C_COMPILER_TYPE C_COMPILER_TYPE_MICROTEC
#  include "emc/config/compiler/cfg_microtec.h"

#elif defined(__TURBOC__)
#  if (__TURBOC__ >= 0x500)
#    define C_COMPILER_TYPE C_COMPILER_TYPE_BC5
#    include "emc/config/compiler/cfg_bc5.h"
#  else
#    error "unsupported Compiler"
#  endif

#elif defined(__C51__) || defined(__CX51__)
#  define C_COMPILER_TYPE C_COMPILER_TYPE_KEIL
#  include "emc/config/compiler/cfg_keil.h"

#elif defined(__C251__) || defined(__CX251__)
#  define C_COMPILER_TYPE C_COMPILER_TYPE_KEIL251
#  include "emc/config/compiler/cfg_keil251.h"

#elif defined(__C166__)
#  define C_COMPILER_TYPE C_COMPILER_TYPE_KEIL166
#  include "emc/config/compiler/cfg_keil166.h"

#elif defined(CADUL)
#  define C_COMPILER_TYPE C_COMPILER_TYPE_CC386
#  include "emc/config/compiler/cfg_cc386.h"

#elif defined(__TMS470__)
#  define C_COMPILER_TYPE C_COMPILER_TYPE_TMS470
#  include "emc/config/compiler/cfg_tms470.h"

#elif defined(_CJ2)
#  define C_COMPILER_TYPE C_COMPILER_TYPE_CJ2
#  include "emc/config/compiler/cfg_cj2.h"

#else
#  error "unsupported compiler"
#endif

/** overwrite lint specific compiler switches */
#if defined(_lint)
#  include "emc/config/compiler/cfg_lint.h"
#endif

/** @name Identifiers for Byte Order Types
    The @ref EMC_CPU_ENDIANESS is automatically set to one of these values */
#define EMC_CPU_LITTLE_ENDIAN 1 /**< The constant definition for little endian CPUs */
#define EMC_CPU_BIG_ENDIAN 2    /**< The constant definition for big endian CPUs */
/** @} */
/**    @brief Describes the native byte-order of the processor */
#if !defined EMC_CPU_ENDIANESS || EMC_DOXYGEN
#  define EMC_CPU_ENDIANESS EMC_CPU_LITTLE_ENDIAN
#endif

#if !defined(WRITEONLY_PARAM) || EMC_DOXYGEN
/** Explicitly declare a variables as write-only.  Good compilers show
    warnings if they see variables that are written but never read.
    But some of these variables are meant for interactive debugging or
    access to hardware registers.

    @lint Warning 613 Possible use of null pointer@n
    If we use "if(var)" to use a variable with function's result lint will assume that a
    the variable needs checks.

    @ingroup emdoc_emc_config */
#  ifndef _lint
#    define WRITEONLY_PARAM(p) if (p /*lint --e(774) */) {}
#  else
#    define WRITEONLY_PARAM(p) do { (void)(p); } while (0)
#  endif
#endif

#ifndef UNUSED_PARAM
#  if C_COMPILER_SUPPORTS_VOID_CAST || EMC_DOXYGEN
/** Explicitly declare a variable as unused.
    Good compilers show warnings when variables are not used.  But
    some of these variables are intentionally ignored function
    parameters or are only used when assertions are turned on.
    @ingroup emdoc_emc_config */
#    define UNUSED_PARAM(p)  ((void)(p))
#  else /*C_COMPILER_SUPPORTS_VOID_CAST*/
#    if C_COMPILER_TYPE == C_COMPILER_TYPE_KEIL166
#      define UNUSED_PARAM(p) if (p) {}
#    else
#      define UNUSED_PARAM(p) if (p)
#    endif
#  endif /*C_COMPILER_SUPPORTS_VOID_CAST*/
#endif /*UNUSED_PARAM*/

#if HAVE_CHAR16_T || EMC_DOXYGEN
/** @name String literal prefixes *//** @{ */
/** The L prefix for string literals on all platforms */
#  define EMC_L(x) L"" x
/** The u prefix for 16-bit character string literals */
#  define EMC_u(x) u"" x
/** The U prefix for 32-bit character string literals */
#  define EMC_U(x) U"" x
/** @} */
#else
/* We cannot just concatenate different types of string literals.  Old
   compilers report this as errors. */
#  define EMC_L(x) L ## x
#  define EMC_u(x) L ## x
#  define EMC_U(x) L ## x
#endif

/** @macro EMC_SIZEOF_POINTER to generic identification of pointer size */
#if defined __SIZEOF_POINTER__ /* gcc, clang */
#  define EMC_SIZEOF_POINTER (__SIZEOF_POINTER__)
#elif defined __sizeof_ptr /* rvct, always 4 */
#  define EMC_SIZEOF_POINTER (__sizeof_ptr)
#elif defined _WIN64 /* msvc */
#  define EMC_SIZEOF_POINTER 8
#else /* fallback */
#  define EMC_SIZEOF_POINTER 4
#endif

/** Return the unmodified string literal.  This is used in generic macros
    when no prefix is needed for string literals. */
#define EMC_(x) x

#if defined(__WCHAR_MAX__)
#  if 65535U == __WCHAR_MAX__
#    define EMC_WCHAR_IS_CHAR16 1
#  elif 2147483647 == __WCHAR_MAX__
#    define EMC_WCHAR_IS_CHAR32 1
#  endif
#endif

/** The build in wchar type is 16-bit */
#ifndef EMC_WCHAR_IS_CHAR16
#  define EMC_WCHAR_IS_CHAR16 0
#endif

/** The build in wchar type is 32-bit */
#ifndef EMC_WCHAR_IS_CHAR32
#  define EMC_WCHAR_IS_CHAR32 0
#endif

/* /\** This inline function references our static test function to avoid */
/*     "unused static function" warnings. *\/ */
/* inline static void emc_compiler_configure_inline_test_function() { */
/*   emc_compiler_configure_static_test_function(); */
/* } */

#endif /* EMC_CONFIG_COMPILER_configure_H */

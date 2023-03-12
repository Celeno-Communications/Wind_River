/* Copyright (C) 2013 emsys Embedded Systems GmbH */

#ifndef EMC_CONFIG_configure_H
#  define EMC_CONFIG_configure_H

/// Legacy macro for other headers to check if this file has been included before
#  define EMC_CONFIG_CONFIGURE_H

#  ifdef HAVE_CMAKE_CONFIGURE
#    include "emc_config/cmakeConfigure.h"
#  endif

// FIXME GUARDXREF - Rename switch
#  ifndef EMC_USE_NOT_CUSTOMER_CONFIGURE_H
#    include "customer/emc/base/configure.h"
#  endif
#  include "emc/config/compiler/configure.h"

/**
   @defgroup emsys_modules Software Modules

   @addtogroup emdoc_Specifications Specifications
   @brief Links to external documentation.

   @addtogroup emdoc_Interfaces Application Interfaces
   @brief External or Application Interfaces.

   @addtogroup emdoc_Defines Defines
   @brief Compile time configuration.

   @addtogroup emdoc_ReleaseNotes Release Notes
   @brief Version information and detailed change logs.

   @page emdoc_emcpp_base_page Basic Components
   @copybrief emdoc_emc_config

   @defgroup emdoc_emc_config emc_config
   The @ref emdoc_emc_config library provides a central configuration infrastructure
   for all emsys projects.
   @ingroup emsys_modules

 **/

/** @name Build Configuration
 *
 * The library can be build at least in two ways:
 * with high debugging support (which includes printing and assertions, ...)
 * and highly optimized (with inlinining and minimized debugging).
 */
/*@{*/
/** @def EMC_BUILD  The selected build configuration value.*/

#  define EMC_BUILD_DEBUG 1       /**< Build with most debugging support.*/
#  define EMC_BUILD_OPTIM 2       /**< Highly optimized build.*/
#  define EMC_BUILD_DEBUG_OPTIM 3 /**< Optimized build with debugging information.*/
/*@}*/

#  ifndef EMC_BUILD
/** Default Setting */
#    define EMC_BUILD EMC_BUILD_OPTIM
#  endif

/** @name Inline Configuration
 *
 * The compiler and library dependent selection of the inlining of small
 * functions.
 *

   @internal

   Three independent questions are relevant for our small functions.

   1. Do we want to use macros, inline functions or regular functions?

   We check EMC_INLINE == EMC_INLINE_{NO,MACRO,INLINE}.

   2. Do we want to static, extern or regular inline functions?

   To stay compatible C++ we use "static inline" in C code.  Other
   people suggest to temporarily redefine an INLINE macro to support
   multiple strategies.

   @see http://www.greenend.org.uk/rjk/2003/03/inline.html

   3. How does the compiler support the inline keyword?

   If necessary our compiler headers should redefine "inline" and
   redirect it to "__inline", "_Pragma(inline)" or nothing.  Note that
   the "inline" keyword is available in all C++ and C99 compilers.

 */
/*@{*/
/** @def EMC_INLINE The selected inline configuration value. */

#  define EMC_INLINE_NO 0        /**< No inlining; implemented as functions.*/
#  define EMC_INLINE_INLINE 1    /**< Using the compiler keyword inline.*/
#  define EMC_INLINE_MACRO 2     /**< Expand as a preprocessor macro.*/

#  ifndef EMC_INLINE
#    define EMC_INLINE EMC_INLINE_INLINE
#  endif

#  if EMC_INLINE == EMC_INLINE_NO
#    define EMC_MAYBE_INLINE
#  else
#    define EMC_MAYBE_INLINE inline static
#  endif

#  if (EMC_BUILD == EMC_BUILD_OPTIM)

#    ifndef EMC_INLINE
/** Default Setting */
#      define EMC_INLINE EMC_INLINE_INLINE
#    endif

#  elif (EMC_BUILD == EMC_BUILD_DEBUG)

#    ifndef EMC_INLINE
/** Default Setting */
#      define EMC_INLINE EMC_INLINE_NO
#    endif

#  elif (EMC_BUILD == EMC_BUILD_DEBUG_OPTIM)

#    ifndef EMC_INLINE
/** Default Setting */
#      define EMC_INLINE EMC_INLINE_INLINE
#    endif

#  else
#    error EMC_BUILD not defined
#  endif /* EMC_BUILD */
/*@}*/

/** @name Printing Configuration
 *
 * The library supports the priniting of self writen data types.
 * This feature is optional and can be switched on explicitly on demand.
 * Default is off.
 */
/*@{*/

#  ifndef EMC_PRINT
/** Default Setting */
#    define EMC_PRINT 0
#  endif
/*@}*/

/** @name Testing Configuration
 *
 * The library supports additional code for testing purposes.
 * This feature is optional and can be switched on explicitly on demand.
 * Default is off.
 */
/*@{*/

#  ifndef EMC_TEST
/** Default Setting */
#    define EMC_TEST 0
#  endif
/*@}*/

/** Macro for switching zero-initialization of static variables */
#  ifndef EMC_DECL_INIT_ZERO
#    define EMC_DECL_INIT_ZERO(v) v = 0
#  endif

#  ifndef EMC_CUSTOMER_CONFIG
/** True to add customer-specific configuration headers */
#    define EMC_CUSTOMER_CONFIG 0
#  endif

#  if !defined(EMC_ENABLE_VERSION_INFORMATION) || EMC_DOXYGEN
/** True to add symbols with version information to objects */
#    define EMC_ENABLE_VERSION_INFORMATION 1
#  endif

/** Convert the parameter to a string */
#  define EMC_STR(type, x) EMC_ ## type(# x)
/** Concatenate all parameters */
#  define EMC_NAME2(a, b) a ## b
/** Concatenate all parameters indirectly */
#  define EMC_XNAME2(a, b) EMC_NAME2(a, b)

/** Convert given symbol to string implementation */
#  define EMC_STRINGIZE_IMPL(x) # x
/** Convert given symbol to string implementation */
#  define EMC_STRINGIZE(x) EMC_STRINGIZE_IMPL(x)

#  if EMC_ENABLE_VERSION_INFORMATION

/** Runtime version information datatype for modules */
typedef struct EMC_BASE_VersionInformation {
  unsigned int major;       /**< The major part of the version number */
  unsigned int minor;       /**< The minor part of the version number */
  unsigned int micro;       /**< The micro part of the version number */
  const char*  module_name; /**< The name of the versioned module */
} EMC_BASE_VersionInformation;

/** Declare a symbol with version information */
#    define _EMC_DECLARE_VERSION(module)                                    \
  extern const EMC_BASE_VersionInformation EMC_XNAME2(module, _RUNTIME_VERSION); \
  extern int emc_macro_requires_semicolon /*lint --e{762} */

#  else /* !EMC_ENABLE_VERSION_INFORMATION */

#    define _EMC_DECLARE_VERSION(module) extern int emc_macro_requires_semicolon

#  endif /* !EMC_ENABLE_VERSION_INFORMATION */

#  if defined(__cplusplus) || EMC_DOXYGEN
/// Expands to 'extern "C" {' in c++ mode
#    define EMC_EXTERN_C_BEGIN extern "C" { extern int emc_macro_requires_semicolon
/// Expands to '}' in c++ mode
#    define EMC_EXTERN_C_END } extern int emc_macro_requires_semicolon
#  else
#    define EMC_EXTERN_C_BEGIN extern int emc_macro_requires_semicolon
#    define EMC_EXTERN_C_END extern int emc_macro_requires_semicolon
#  endif

EMC_EXTERN_C_BEGIN;
EMC_EXTERN_C_END;

/** long long typedefs
 * long long is not standard before C++11
 * but most compiler are supporting it as an extension,
 * but this implies compiling with older compiler in strict ANSI mode like
 * -pedantic will generate warnings.
 * To avoid this some compiler specific pragma or other switch is needed.
 */
#  define EMC_EXTENSION_TYPEDEF_LONG_LONG(type) \
  typedef long long int type

#  define EMC_EXTENSION_TYPEDEF_ULONG_LONG(type) \
  typedef unsigned long long type

#  if defined(__GNUC__)
#    if GCC_VERSION < 40300
#      undef EMC_EXTENSION_TYPEDEF_LONG_LONG
#      undef EMC_EXTENSION_TYPEDEF_ULONG_LONG

#      define EMC_EXTENSION_TYPEDEF_LONG_LONG(type) \
  __extension__ typedef long long int type

#      define EMC_EXTENSION_TYPEDEF_ULONG_LONG(type) \
  __extension__ typedef unsigned long long type
#    else
#      if 0 /* only prepared for future */
#        ifdef __UINT64_TYPE__
#          undef EMC_EXTENSION_TYPEDEF_ULONG_LONG
#          define EMC_EXTENSION_TYPEDEF_ULONG_LONG(type) \
  typedef __UINT64_TYPE__ type
#        endif
#        ifdef __INT64_TYPE__
#          undef EMC_EXTENSION_TYPEDEF_LONG_LONG
#          define EMC_EXTENSION_TYPEDEF_LONG_LONG(type) \
  typedef __INT64_TYPE__ type
#        endif
#      endif
#    endif
#  endif

EMC_EXTENSION_TYPEDEF_LONG_LONG(emc_long_long_t);
EMC_EXTENSION_TYPEDEF_ULONG_LONG(emc_ulong_long_t);

/** the emc signature type */
EMC_EXTENSION_TYPEDEF_ULONG_LONG(emc_signature_t);

/** C wrapper for @ref _EMC_DECLARE_VERSION */
#  define EMC_DECLARE_MODULE(module)          \
  _EMC_DECLARE_VERSION(module ## _LIBRARY);              \
  extern int emc_macro_requires_semicolon

/** C++ wrapper for @ref _EMC_DECLARE_VERSION */
#  define EMCPP_DECLARE_MODULE(module)          \
  extern "C" { _EMC_DECLARE_VERSION(module ## _LIBRARY); } \
  emc_signature_t UNIQUE_SIGNATURE();   \
  extern int emc_macro_requires_semicolon

#endif /* EMC_CONFIG_configure_H */

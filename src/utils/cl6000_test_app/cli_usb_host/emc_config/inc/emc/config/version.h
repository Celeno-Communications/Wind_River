/**
 * @file
 * @brief   The version management helper macros.
 *
 * @author  Uwe Markl <uwe.markl@emsys.de> +49-3677-68977-0
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2007, 2010, 2011 emsys Embedded Systems GmbH
 *
 ****************************************************************************/
#ifndef EMC_CONFIG_version_H
#define EMC_CONFIG_version_H

#include <emc/config/configure.h>
#include <emc/config/module_id.h>

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/** Convert MAJOR-, MINOR- and MICRO_VERSION macros to a binary coded decimal number */
#define EMC_VERSION_BCD(x) ((x ## _MAJOR_VERSION << 8) + (x ## _MINOR_VERSION << 4) \
                            + x ## _MICRO_VERSION)

#define EMC_XSTR(type, x) EMC_STR(type, x) /**< Convert the parameter indirectly to a string */

/** Concatenate all parameters */
#define EMC_NAME3(a, b, c)             a ## b ## c
/** Concatenate all parameters indirectly */
#define EMC_XNAME3(a, b, c)            EMC_NAME3(a, b, c)
/** Concatenate all parameters */
#define EMC_NAME4(a, b, c, d)           a ## b ## c ## d
/** Concatenate all parameters indirectly */
#define EMC_XNAME4(a, b, c, d)          EMC_NAME4(a, b, c, d)
/** Concatenate all parameters */
#define EMC_NAME5(a, b, c, d, e)         a ## b ## c ## d ## e
/** Concatenate all parameters indirectly */
#define EMC_XNAME5(a, b, c, d, e)        EMC_NAME5(a, b, c, d, e)

/** Concatenate all parameters */
#define EMC_NAME7(a, b, c, d, e, f, g) a ## b ## c ## d ## e ## f ## g
/** Concatenate all parameters */
#define EMC_XNAME7(a, b, c, d, e, f, g)    EMC_NAME7(a, b, c, d, e, f, g)

/** Concatenate all parameters */
#define EMC_NAME9(a, b, c, d, e, f, g, h, i) a ## b ## c ## d ## e ## f ## g ## h ## i

/** Concatenate MAJOR-, MINOR- and MICRO_VERSION to a version number string literal */
#define _EMC_VERSION_STRING(type, x)                            \
  EMC_XSTR(type, x ## _LIBRARY_MAJOR_VERSION) EMC_ ## type(".") \
  EMC_XSTR(type, x ## _LIBRARY_MINOR_VERSION) EMC_ ## type(".") \
  EMC_XSTR(type, x ## _LIBRARY_MICRO_VERSION)

/** Concatenate to a token with the version number */
#define _EMC_VERSION_TOKEN(x, delimiter) \
  EMC_XNAME5(x ## _MAJOR_VERSION, delimiter, x ## _MINOR_VERSION, delimiter, x ## _MICRO_VERSION)

/** Expands to a string containing the name, a hyphen and the version numbers */
#define _EMC_NAME_VERSION(type, name, ver) EMC_ ## type(name) EMC_ ## type("-") EMC_XSTR(type, ver)

/** Expands to a string containing the name, a hyphen and the version numbers */
#define EMC_NAME_VERSION(type, base) _EMC_NAME_VERSION(type, base ## _NAME, \
                                                       _EMC_VERSION_TOKEN(base, .))

#define _EMC_VERSION_COMPILETIME_NAME(module) \
  EMC_XNAME2(EMC_XNAME2(module, _VERSION_), _EMC_VERSION_TOKEN(module, _))

#define EMC_VERSION_COMPILETIME_NAME(module) \
  _EMC_VERSION_COMPILETIME_NAME(module ## _LIBRARY)

/** Generate a runtime name for a library or package.
 *
 * @param module The name of the library or package.
 */
#define _EMC_VERSION_INFORMATION(module) \
  EMC_XNAME2(module, _RUNTIME_VERSION)

#define EMC_VERSION_INFORMATION(module) \
  _EMC_VERSION_INFORMATION(module ## _LIBRARY)

/** @def EMC_DECLARE_MODULE(module)
 * @brief Declaration of compile and runtime symbols for a library or package.
 *
 * @param module The name of the library or package.
 */

/** @def EMC_DEFINE_MODULE(module)
 * @brief Generation of compile- and runtime symbols for a library or package.
 *
 * @param module The name of the library or package.
 */

#if EMC_ENABLE_VERSION_INFORMATION
/** define build version base macro */

#  define _EMC_DEFINE_VERSION(module)   /*lint -e578 */                 \
  /** The version as a variable name which can be found by @e nm */     \
  const char* /*const*/ _EMC_VERSION_COMPILETIME_NAME(module) =         \
    __DATE__ " " __TIME__;                                              \
  /**The version number as a variable that can be queried at runtime */ \
  const EMC_BASE_VersionInformation _EMC_VERSION_INFORMATION(module) = { \
    module ## _MAJOR_VERSION,                                             \
    module ## _MINOR_VERSION,                                             \
    module ## _MICRO_VERSION,                                             \
    EMC_STR(, module)                                                    \
  };                                      /*lint +e578 */                                                    \
  extern int emc_macro_requires_semicolon /*lint --e{762} */ /*lint --e{1065} */

#else

#  define _EMC_DEFINE_VERSION(module)                                     \
  /* empty */                                                           \
  extern int emc_macro_requires_semicolon

#endif

/** Wrapper for @ref _EMC_DEFINE_VERSION */
#define EMC_DEFINE_MODULE(module)          \
  _EMC_DEFINE_VERSION(module ## _LIBRARY);   \
  extern int emcpp_macro_requires_semicolon

/** Wrapper for @ref _EMC_DEFINE_VERSION */
#define EMCPP_DEFINE_MODULE(module)                                            \
  extern "C" { _EMC_DEFINE_VERSION(module ## _LIBRARY); }                        \
  emc_signature_t UNIQUE_SIGNATURE() { return EMC_UNIQUE_SIGNATURE(module); } \
  extern int emcpp_macro_requires_semicolon

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_CONFIG_version_H */

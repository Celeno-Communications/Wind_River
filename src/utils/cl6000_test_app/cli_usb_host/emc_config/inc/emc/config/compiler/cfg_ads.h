/**
 * @file
 * @brief Configuration values for ARM Developer Suite and RealView compilers.
 *
 * @author  Karsten Pahnke <karsten.pahnke@emsys.de> +49-3677-68977-0
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2004-2008, 2011, 2012 emsys Embedded Systems GmbH
 */

#ifndef EMC_CONFIG_COMPILER_cfg_ads_H
#define EMC_CONFIG_COMPILER_cfg_ads_H

/** Inlining macros use @c __inline.
    @lint Warning 1558: virtual coupled with inline is an unusual combination\n
    When the base class is called from the derived class inlining is a common
    optimization, especially with trivial virtual destructors. */
#ifndef inline
#  define inline /*lint -e(1558) */ __inline
#endif

/** In general __func__ is supported by the ADS C compiler, but it
    generates mangled names in C++. */
#ifdef __cplusplus
#  define __func__ "?"
#endif

/** Provide assert message at higher optimization levels */
#define __ASSERT_MSG

/** Wide-character functions like @c wprintf() are not supported by
    the ADS libraries.  Note that the @c wchar_t type is in the header
    @c @<stddef.h@> and @c @<wchar.h@> is only needed for additional
    functions. */
#undef C_LIBRARY_HAS_WCHAR_H
#define C_LIBRARY_HAS_WCHAR_H 0

#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 210000)

#  undef __func__

/* Disable "storage class is not first" in RVCT2.2 */
#  pragma diag_suppress 82

/* Enable "zero used for undefined preprocessing identifier" warnings. */
#  pragma diag_warning 193

/* Disable "controlling expression is constant" in RVCT2.2 */
#  pragma diag_suppress 236

/* Disable "value copied to temporary, reference to temporary used" warnings. */
#  pragma diag_suppress 340
/* Disable "destructor for base class <type> is not virtual" warnings. */
#  pragma diag_suppress 401
/* Disable "padding inserted in struct <struct>" remarks. */
#  pragma diag_suppress 1301
/* Disable "Header file not guarded against multiple inclusion" remarks.
   This occurs in stl_function.hpp. */
#  pragma diag_suppress 1297
/* Disable "padding added to end of struct <struct>" remarks. */
#  pragma diag_suppress 2530

/* enable Anonymous union and struct declarations which are a C11 feature. */
#  pragma anon_unions

#endif /* RVCT >= 2.1 */

#endif /* EMC_CONFIG_COMPILER_cfg_ads_H */

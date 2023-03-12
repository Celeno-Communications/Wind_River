/** @file
    @brief Configuration values for the Keil C51/CX51 compiler.
    Copyright (C) 2004-2008, 2011 emsys Embedded Systems GmbH
 */
#ifndef EMC_CONFIG_COMPILER_cfg_keil_H
#define EMC_CONFIG_COMPILER_cfg_keil_H

/** Keil standard headers do not declare @c FILE in @c @<stdio.h@> */
#undef C_LIBRARY_HAS_FILE_TYPE
#define C_LIBRARY_HAS_FILE_TYPE 0

/** Keil standard libraries don't support @c fprintf() */
#undef C_LIBRARY_HAS_FPRINTF
#define C_LIBRARY_HAS_FPRINTF 0

/** Do not attempt inlining with Keil */
#ifndef inline
#  define inline /* nothing */
#endif

#if EMC_INLINE == EMC_INLINE_INLINE
#  error "Do not attempt inlining with Keil"
#endif

/** Some obscure Keil workarounds are necessary */
#undef C_COMPILER_HAS_UNIQUE_PTR_SIZE
#define C_COMPILER_HAS_UNIQUE_PTR_SIZE 0

/** Some obscure Keil workarounds are necessary */
#undef C_COMPILER_SUPPORTS_NON_VOID_MAIN
#define C_COMPILER_SUPPORTS_NON_VOID_MAIN 0

/** Some obscure Keil workarounds are necessary */
#undef C_COMPILER_SUPPORTS_NON_VOID_MAIN_ARGS
#define C_COMPILER_SUPPORTS_NON_VOID_MAIN_ARGS 0

/** Keil doesn't supply the POSIX header @c @<fcntl.h@> */
#undef C_LIBRARY_HAS_FCNTL
#define C_LIBRARY_HAS_FCNTL 0

#endif /* EMC_CONFIG_COMPILER_cfg_keil_H */

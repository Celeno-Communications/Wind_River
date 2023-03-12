/**
 * @file
 * @brief Configuration values for IAR ARM Developer Suite.
 *
 * @author  Karsten Pahnke <karsten.pahnke@emsys.de> +49-3677-68977-0
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2010, 2011 emsys Embedded Systems GmbH
 */

#ifndef EMC_CONFIG_COMPILER_cfg_iar_H
#define EMC_CONFIG_COMPILER_cfg_iar_H

#pragma diag_suppress=Pa089 /* Warning: enumerated type mixed with another enumerated type. */

#ifndef __cplusplus
#  if __STDC__ < 199901L
#    undef inline
/** If the C dialect doesn't support the "inline" keywork we will use a pragma instead. */
#    define inline _Pragma("inline")
#  endif
#endif

#ifdef __cplusplus
#  define __func__ \
  _Pragma("language=save") \
  _Pragma("language=extended") \
  __func__ \
  _Pragma("language=restore")
#endif

/** A "noreturn" attribute is supported. */
#undef EMC_ATTRIBUTE_NORETURN
#define EMC_ATTRIBUTE_NORETURN __noreturn

/** Basic support for printf format checking is available. */
#undef EMC_ATTRIBUTE_PRINTF
#define EMC_ATTRIBUTE_PRINTF(FORMATSTRING_POS, ELLIPSIS_POS) __printf_args

#endif /* EMC_CONFIG_COMPILER_cfg_iar_H */

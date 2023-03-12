/**
 * @file
 * @brief   MSVC10 specific compiler and library settings.
 * @author  Enrico Schmidtke <enrico.schmidtke@emsys.de>
 *
 * Copyright (C) 2010 emsys Embedded Systems GmbH
 */

#ifndef EMC_CONFIG_COMPILER_cfg_msvc10_H
#define EMC_CONFIG_COMPILER_cfg_msvc10_H

#include "cfg_msvc8.h"

#if defined(_HAS_CHAR16_T_LANGUAGE_SUPPORT) && _HAS_CHAR16_T_LANGUAGE_SUPPORT
#  undef HAVE_CHAR16_T
#  define HAVE_CHAR16_T 1
#else
#  define _CHAR16T /* to prevent redefinition in yvals.h */
#endif

#undef C_LIBRARY_HAS_STDINT_H
#define C_LIBRARY_HAS_STDINT_H

#endif /* EMC_CONFIG_COMPILER_cfg_msvc10_H */

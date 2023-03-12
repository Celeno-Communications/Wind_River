/** @file
    @brief Compiler specific settings for the ST9 8-bit microcontroller's GNU C compiler.
    Copyright (C) 2004-2008, 2011 emsys Embedded Systems GmbH */

#ifndef EMC_CONFIG_COMPILER_cfg_st9gcc_H
#define EMC_CONFIG_COMPILER_cfg_st9gcc_H

#include "emc/config/compiler/st9/macro.h"

/** We don't use fprintf on the ST9 platform. */
#undef C_LIBRARY_HAS_FPRINTF
#define C_LIBRARY_HAS_FPRINTF 0

/** The @c memchr() overloads will never return a const pointer. */
#undef C_LIBRARY_MEMCHR_RETURN_CONST
#define C_LIBRARY_MEMCHR_RETURN_CONST 0

#endif /* EMC_CONFIG_COMPILER_cfg_st9gcc_H */

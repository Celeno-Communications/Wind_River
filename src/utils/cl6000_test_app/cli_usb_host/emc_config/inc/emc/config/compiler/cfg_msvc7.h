/**
 * @file
 * @brief   MSVC7 specific compiler and library settings.
 *
 * @author  Uwe Markl <uwe.markl@emsys.de> +49-3677-68977-0
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 ****************************************************************************/
#ifndef EMC_CONFIG_COMPILER_cfg_msvc7_H
#define EMC_CONFIG_COMPILER_cfg_msvc7_H

#include "emc/config/compiler/cfg_msvc6.h"

/** Visual Studio 2002 and 2003 support @c fprintf() */
#undef C_LIBRARY_HAS_FPRINTF
#define C_LIBRARY_HAS_FPRINTF 1

#endif /* EMC_CONFIG_COMPILER_cfg_msvc7_H */

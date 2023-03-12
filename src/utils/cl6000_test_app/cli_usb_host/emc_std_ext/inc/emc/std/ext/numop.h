/**
 * @file
 * @brief   some numeric operations
 *
 * @author  Karsten Pahnke <karsten.pahnke@emsys.de>
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2016-2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_STD_EXT_numop_H
#define EMC_STD_EXT_numop_H

#include "emc/std/configure.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/** check if a is power of 2 */
#define EMC_IS_POWER_OF_TWO(a) ((a) > 0 && 0 == ((a) & ((a) - 1)))

// clang-format off extern C
#  ifdef __cplusplus
}
#  endif
// clang-format on extern C

#endif /*EMC_STD_EXT_numop_H*/

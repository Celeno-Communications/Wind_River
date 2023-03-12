/**
 * @file
 * @brief   The generic program counter access
 *
 * @author  Karsten Pahnke <karsten.pahnke@emsys.de>
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 *
 ****************************************************************************/
#ifndef EMC_STD_EMU_program_counter_H
#define EMC_STD_EMU_program_counter_H

#include "emc/std/stdint.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/** get the program counter */
void* emc_std_get_pc(void);

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_STD_EMU_program_counter_H */

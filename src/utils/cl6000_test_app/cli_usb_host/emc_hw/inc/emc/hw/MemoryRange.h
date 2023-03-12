/**
 * @file
 * @brief   range or piece of memory
 *
 * Copyright (C) 2020, 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_HW_MemoryRange_H
#define EMC_HW_MemoryRange_H

#include "emc/hw/configure.h"
#include "emc/std/stdint.h"
#include "emc/std/stddef.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/**
 * A descriptor for a piece of memory
 * @ingroup emdoc_emc_hw
 */
typedef struct EMC_MemoryRange {
  emc_std_uintptr_t base; /**< The base address of the memory */
  emc_std_size_t    size; /**< The size of the memory range in bytes */
} EMC_MemoryRange;

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif

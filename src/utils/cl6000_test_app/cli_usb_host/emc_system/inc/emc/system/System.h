/**
 * @file
 * @brief   Generic System API
 *
 * @author  Karsten Pahnke <karsten.pahnke@emsys.de>
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_SYSTEM_System_H
#define EMC_SYSTEM_System_H

#include "emc/system/configure.h"
#include "emc/system/Interrupt.h"
#include "emc/hw/MemoryRange.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/**
 * @ingroup emdoc_emc_system
 * create and initialize the system and return error code
 */
int EMC_System_init(void);

/**
 * @ingroup emdoc_emc_system
 * deinitialize the system
 */
void EMC_System_exit(void);

/**
 * @ingroup emdoc_emc_system
 * provide the usb register space
 */
EMC_MemoryRange EMC_System_usb_register_space(void);

/**
 * @ingroup emdoc_emc_system
 * provide the dma memory space
 */
EMC_MemoryRange EMC_System_dma_memory_space(void);

/**
 * @ingroup emdoc_emc_system
 * provide the Interrupt context
 * @param self caller provided storage
 * @param interrupt_type A platform specific interrupt type
 * @param instance the zero based instance of that type of interrupt context
 */
void EMC_Interrupt_factory(InterruptContext* self, emc_std_uint32_t interrupt_type, emc_std_uint32_t instance);

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif

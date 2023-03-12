/**
 * @file
 * @brief
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/

#ifndef EMC_SYSTEM_CELENO_DEVICE_APPLICATION_InterruptContextDwc3_H
#define EMC_SYSTEM_CELENO_DEVICE_APPLICATION_InterruptContextDwc3_H

#include "emc/system/celeno/configure.h"
#include "emc/system/Interrupt.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

void EMC_InterruptContext_dwc3_init(InterruptContext* self, emc_std_uint32_t interrupt_type, emc_std_uint32_t instance);

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_SYSTEM_CELENO_DEVICE_APPLICATION_InterruptContextDwc3_H */

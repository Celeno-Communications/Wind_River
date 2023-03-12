/**
 * @file
 * Copyright (C) 2022 emsys Embedded Systems GmbH
 ****************************************************************************/

#ifndef EMC_VENDOR_CELENO_DEVICE_AsicVersion_H
#define EMC_VENDOR_CELENO_DEVICE_AsicVersion_H

#include "emc/system/celeno/configure.h"
#include "emc/vendor/celeno/device/MiscReg.h"
#include "emc/std/stdint.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

extern emc_std_uint8_t mg_asic_version;

void EMC_System_Celeno_InitAsicVersion(void);

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif

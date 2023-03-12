/**
 * @file
 * @brief
 * @author  <karsten.pahnke@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_USB_VENDOR_CELENO_CLI_TargetMemoryDump_H
#define EMC_USB_VENDOR_CELENO_CLI_TargetMemoryDump_H

#include "emc/usb/vendor/celeno/cli/TargetMemory.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/** @relates EMC_USB_CELENO_CLI_TargetMemory @brief dump a range of the memory */
void EMC_USB_CELENO_CLI_TargetMemory_dump(emc_std_uint32_t begin,
                                          emc_std_uint32_t end);

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_USB_VENDOR_CELENO_CLI_TargetMemoryDump_H */

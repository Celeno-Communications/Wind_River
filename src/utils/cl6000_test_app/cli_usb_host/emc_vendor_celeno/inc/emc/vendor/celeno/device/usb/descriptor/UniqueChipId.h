/**
 * @file
 * @brief Compute SerialNumber String from Unique Chip Id
 * @author  <ralf.oberlaender@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_VENDOR_CELENO_DEVICE_USB_DESCRIPTOR_UniqueChipId_H
#define EMC_VENDOR_CELENO_DEVICE_USB_DESCRIPTOR_UniqueChipId_H

#include "emc/vendor/celeno/configure.h"
#include "emc/usb/descriptor/StringDescriptor.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/** Compute Serial Number String Descriptor */
const EMC_USB_StringDescriptor* EMC_USB_CELENO_compute_serial_number();

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_VENDOR_CELENO_DEVICE_USB_DESCRIPTOR_UniqueChipId_H */

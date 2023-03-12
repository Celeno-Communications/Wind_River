/**
 * @file
 * @brief The specific DescriptorSet
 * @author  <karsten.pahnke@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_SYSTEM_CELENO_DEVICE_ISO_TRANSPORT_DescriptorSet_H
#define EMC_SYSTEM_CELENO_DEVICE_ISO_TRANSPORT_DescriptorSet_H

#include "emc/system/celeno/configure.h"
#include "emc/system/celeno/device/iso_transport/config.h"
#include "emc/std/stdbool.h"
#include "emc/usb/descriptor/DescriptorSet.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

extern const emc_std_uint8_t StrDesc_Serial[];

/** Returns the DescriptorSet Instance */
const EMC_USB_DescriptorSet* EMC_USB_DescriptorSet_instance(void);

/** Configures SerialNumber as well as PID of the DescriptorSet
 * @param pid The USB PID
 * @param serial_number Serial-Number String Descriptor. Parameter will be ignored if nullptr.
 */
void EMC_USB_CELENO_ISO_DescriptorSet_configure(uint16_t pid, const EMC_USB_StringDescriptor* serial_number);

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_SYSTEM_CELENO_DEVICE_ISO_TRANSPORT_DescriptorSet_H */

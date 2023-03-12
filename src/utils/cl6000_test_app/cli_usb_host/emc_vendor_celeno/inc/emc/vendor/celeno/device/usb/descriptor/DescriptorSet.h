/**
 * @file
 * @brief The specific DescriptorSet
 * @author  <karsten.pahnke@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_VENDOR_CELENO_DEVICE_USB_DESCRIPTOR_DescriptorSet_H
#define EMC_VENDOR_CELENO_DEVICE_USB_DESCRIPTOR_DescriptorSet_H

#include "emc/std/stdbool.h"
#include "emc/usb/descriptor/DescriptorSet.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/** Returns the DescriptorSet Instance */
const EMC_USB_DescriptorSet* EMC_USB_DescriptorSet_instance(void);

/** Configures SerialNumber as well as VID/PID of the DescriptorSet
 * @param vid The USB VID
 * @param pid The USB PID
 * @param pid The USB bcdDevice code
 * @param serial_number Serial-Number String Descriptor. parameter will be ignored if nullptr.
 */
void EMC_USB_CELENO_DescriptorSet_configure(emc_std_uint16_t vid,
                                            emc_std_uint16_t pid,
                                            emc_std_uint16_t bcdDevice,
                                            const EMC_USB_StringDescriptor* serial_number);

/** Register String descriptor for given index in DescriptorSet
 * @param index The string index
 * @param string The string-descriptor
 */
void EMC_USB_CELENO_DescriptorSet_configure_string(emc_std_uint8_t index, const EMC_USB_StringDescriptor* string);

/** Limit the maximum speed to high speed */
void EMC_USB_CELENO_DescriptorSet_limit_HS(void);

/** Disable the LPM and BESL attributes in the BOS descriptor */
void EMC_USB_CELENO_DescriptorSet_disable_lpm_besl(void);

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_VENDOR_CELENO_DEVICE_USB_DESCRIPTOR_DescriptorSet_H */

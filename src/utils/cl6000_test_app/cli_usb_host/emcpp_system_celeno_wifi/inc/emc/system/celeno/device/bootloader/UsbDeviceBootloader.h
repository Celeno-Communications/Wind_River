/**
 * @file
 *
 * @author  Ralf Oberländer <ralf.oberlaender@emsys.de>
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/

#ifndef EMC_SYSTEM_CELENO_DEVICE_BOOTLOADER_UsbDeviceBootloader_H
#define EMC_SYSTEM_CELENO_DEVICE_BOOTLOADER_UsbDeviceBootloader_H

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

void emc_usb_init(void);

void emc_usb_poll(void);

void emc_usb_shutdown(void);

void* wrapped_memcpy(void* dest, const void* src, unsigned int n);

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_SYSTEM_CELENO_DEVICE_BOOTLOADER_UsbDeviceBootloader_H */

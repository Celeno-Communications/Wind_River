/**
 * @file
 * @brief The OTP API
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_VENDOR_CELENO_DEVICE_Otp_H
#define EMC_VENDOR_CELENO_DEVICE_Otp_H

#include "emc/vendor/celeno/configure.h"
#include "emc/std/stdint.h"
#include "emc/std/stdbool.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/** The timeout in us to wait for OTP ready */
#define EMC_USB_CELENO_OTP_READY_TIMEOUT_US 100

/**
 * Initialize the OTP module.
 */
void EMC_USB_CELENO_OTP_init();

/**
 * Read a value from the OTP memory.
 * @param addr The address as an index to the DWORD array in the range 0..255
 * @param value The pointer to the value that receives the result on success. It is not changed on error.
 * @return True on success. False on timeout or an unrecoverable data corruption.
 */
emc_std_bool EMC_USB_CELENO_OTP_read(emc_std_uint8_t addr, emc_std_uint32_t* value);

/**
 * Write a value to the OTP memory.
 * @param addr The address as an index to the DWORD array in the range 0..255
 * @param value The value to be written.
 * @return True on success. False on timeout or an value that cannot be written.
 */
emc_std_bool EMC_USB_CELENO_OTP_write(emc_std_uint8_t addr, emc_std_uint32_t value);

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_VENDOR_CELENO_DEVICE_Otp_H */

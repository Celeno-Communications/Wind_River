/**
 * @file
 * @brief
 * Copyright (C) 2022 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_VENDOR_CELENO_DEVICE_TciReg_H
#define EMC_VENDOR_CELENO_DEVICE_TciReg_H

#include "emc/vendor/celeno/configure.h"
#include "emc/std/stdint.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/** base address */
#define EMC_CELENO_TCI_BASE 0x607CD000

/** Number of registers */
#define EMC_CELENO_TCI_REG_SPACE (0xA4 >> 2)

/** Initialize the TCI registers */
void EMC_CELENO_TCI_init_reg(void);

/**
 * Read a TCI register.
 * @param offset is the byte-offset from the TCI register base.
 * @return the value of the register.
 */
emc_std_uint32_t EMC_CELENO_TCI_read_reg(emc_std_uint32_t offset);

/**
 * Write a TCI register.
 * @param offset is the byte-offset from the TCI register base.
 * @param value is the value to be written.
 */
void EMC_CELENO_TCI_write_reg(emc_std_uint32_t offset, emc_std_uint32_t value);

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_VENDOR_CELENO_DEVICE_TciReg_H */

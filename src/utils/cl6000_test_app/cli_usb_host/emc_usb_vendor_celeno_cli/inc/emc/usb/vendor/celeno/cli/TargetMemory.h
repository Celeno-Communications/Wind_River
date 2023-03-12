/**
 * @file
 * @brief
 * @author  <karsten.pahnke@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_USB_VENDOR_CELENO_CLI_TargetMemory_H
#define EMC_USB_VENDOR_CELENO_CLI_TargetMemory_H

#include "emc/usb/vendor/celeno/cli/configure.h"

#include "emc/std/stdint.h"
#include "emc/std/stddef.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/** A Project specific abstraction of target memory
    @ingroup emdoc_emc_usb_vendor_celeno_cli
 */
typedef struct EMC_USB_CELENO_CLI_TargetMemory EMC_USB_CELENO_CLI_TargetMemory;

/** @relates EMC_USB_CELENO_CLI_TargetMemory @brief add memory section with a specific size simulating physical_addr  */
void EMC_USB_CELENO_CLI_TargetMemory_add(void* memory, emc_std_uint32_t physical_addr, emc_std_size_t size);

/** @relates EMC_USB_CELENO_CLI_TargetMemory @brief initialize the memory with a specific size */
int EMC_USB_CELENO_CLI_TargetMemory_init(size_t size);

/** @relates EMC_USB_CELENO_CLI_TargetMemory @brief de-initialize the memory */
int EMC_USB_CELENO_CLI_TargetMemory_exit();

/** @relates EMC_USB_CELENO_CLI_TargetMemory @brief provide the first address in the memory*/
emc_std_uint32_t EMC_USB_CELENO_CLI_TargetMemory_begin();

/** @relates EMC_USB_CELENO_CLI_TargetMemory @brief read the value at a specific address */
emc_std_uint32_t EMC_USB_CELENO_CLI_TargetMemory_read(emc_std_uint32_t address);

/** @relates EMC_USB_CELENO_CLI_TargetMemory @brief write the memory at a specific address */
void EMC_USB_CELENO_CLI_TargetMemory_write(emc_std_uint32_t address,
                                           emc_std_uint32_t data,
                                           emc_std_uint32_t mask);

/** @relates EMC_USB_CELENO_CLI_TargetMemory @brief write a chunk of the memory at a specific address */
void EMC_USB_CELENO_CLI_TargetMemory_burst_write(emc_std_uint32_t address,
                                                 const void* buffer,
                                                 emc_std_uint32_t size);

/** @relates EMC_USB_CELENO_CLI_TargetMemory @brief read a chunk of the memory from a specific address */
void EMC_USB_CELENO_CLI_TargetMemory_burst_read(emc_std_uint32_t address,
                                                void* buffer,
                                                emc_std_uint32_t size);

/** private convert address to pointer*/
emc_std_uint32_t* EMC_USB_CELENO_CLI_TargetMemory_ptr(emc_std_uint32_t address);

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_USB_VENDOR_CELENO_CLI_TargetMemory_H */

/**
 * @file
 *
 * @author  Ralf Oberländer
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/

#ifndef EMC_SYSTEM_CELENO_DEVICE_BOOTLOADER_StartupConfiguration_H
#define EMC_SYSTEM_CELENO_DEVICE_BOOTLOADER_StartupConfiguration_H

#include "emc/system/celeno/configure.h"
#include "emc/std/stdint.h"

/** Initializes bootrom config module with base address */
void emc_bootrom_cfg_init(uint32_t* cfg_base);

/** Computes bootrom startup delay
 * @return 0 if signature is not valid, otherwise the configured delay in u-sec limited to 1.0sec max
 */
emc_std_uint32_t emc_bootrom_cfg_startup_delay_us(void);

#endif /* EMC_SYSTEM_CELENO_DEVICE_BOOTLOADER_StartupConfiguration_H */

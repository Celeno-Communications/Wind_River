/**
 * @file
 * Copyright (C) 2022 emsys Embedded Systems GmbH
 ****************************************************************************/

#include "emc/vendor/celeno/device/AsicVersion.h"

emc_std_uint8_t mg_asic_version = EMC_USB_CELENO_STEP_A;

void EMC_System_Celeno_InitAsicVersion(void)
{
  mg_asic_version = EMC_USB_CELENO_chip_version_step();
}

/**
 *
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/

#include "emc/vendor/celeno/device/MiscReg.h"

emc_std_uint32_t EMC_CELENO_read_reg32(emc_std_uint32_t address)
{
  return *(volatile emc_std_uint32_t*)address;
}

void EMC_CELENO_write_reg32(emc_std_uint32_t address, emc_std_uint32_t value)
{
  *(volatile emc_std_uint32_t*)address = value;
}

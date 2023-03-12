/**
 *
 * Copyright (C) 2022 emsys Embedded Systems GmbH
 ****************************************************************************/
#include "emc/vendor/celeno/device/TciReg.h"
#include "emc/std/assert.h"

static volatile emc_std_uint32_t* _reg;

void EMC_CELENO_TCI_init_reg(void)
{
  _reg = (volatile emc_std_uint32_t*)EMC_CELENO_TCI_BASE;
}

emc_std_uint32_t EMC_CELENO_TCI_read_reg(emc_std_uint32_t offset)
{
  emc_std_uint32_t index = offset / 4;
  emc_std_assert(index < EMC_CELENO_TCI_REG_SPACE);
  return *(_reg + index);
}

void EMC_CELENO_TCI_write_reg(emc_std_uint32_t offset, emc_std_uint32_t value)
{
  emc_std_uint32_t index = offset / 4;
  emc_std_assert(index < EMC_CELENO_TCI_REG_SPACE);
  *(_reg + index) = value;
}

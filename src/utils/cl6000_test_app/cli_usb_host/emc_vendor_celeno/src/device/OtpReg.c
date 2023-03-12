/**
 *
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/

#include "emc/vendor/celeno/device/OtpReg.h"
#include "emc/std/assert.h"

static volatile emc_std_uint32_t* _reg;

void EMC_CELENO_OTP_init_reg()
{
  _reg = (volatile emc_std_uint32_t*)EMC_CELENO_OTP_BASE;
}

emc_std_uint32_t EMC_CELENO_OTP_read_reg(emc_std_uint32_t offset)
{
  emc_std_uint32_t index = offset / 4;
  emc_std_assert(index < EMC_CELENO_OTP_REG_SPACE);
  return *(_reg + index);
}

void EMC_CELENO_OTP_write_reg(emc_std_uint32_t offset, emc_std_uint32_t value)
{
  emc_std_uint32_t index = offset / 4;
  emc_std_assert(index < EMC_CELENO_OTP_REG_SPACE);
  *(_reg + index) = value;
}

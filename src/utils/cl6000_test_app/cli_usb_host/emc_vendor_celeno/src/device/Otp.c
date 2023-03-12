/**
 *
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/

#include "emc/vendor/celeno/device/Otp.h"
#include "emc/vendor/celeno/device/OtpReg.h"
#include "emc/std/ext/timestamp.h"

void EMC_USB_CELENO_OTP_init()
{
  EMC_CELENO_OTP_init_reg();
}

static emc_std_bool wait_for_ready(void)
{
  timestamp_t start = emc_timestamp();
  while (!EMC_USB_CELENO_OTP_ready()) {
    if (emc_timestamp_to_microseconds(emc_timestamp_difference(emc_timestamp(),
                                                               start)) > EMC_USB_CELENO_OTP_READY_TIMEOUT_US)
    {
      return emc_std_false;
    }
  }
  return emc_std_true;
}

emc_std_bool EMC_USB_CELENO_OTP_read(emc_std_uint8_t addr, emc_std_uint32_t* value)
{
  emc_std_bool res;
  if (!wait_for_ready()) {
    return emc_std_false;
  }
  EMC_USB_CELENO_OTP_set_address(addr);
  EMC_USB_CELENO_OTP_set_command(EMC_USB_CELENO_OTP_CMD_READ);
  if (!wait_for_ready()) {
    return emc_std_false;
  }
  res = !EMC_USB_CELENO_OTP_read_error();
  if (res) {
    *value = EMC_USB_CELENO_OTP_read_value();
  }
  return res;
}

emc_std_bool EMC_USB_CELENO_OTP_write(emc_std_uint8_t addr, emc_std_uint32_t value)
{
  if (!wait_for_ready()) {
    return emc_std_false;
  }
  EMC_USB_CELENO_OTP_enable_write(emc_std_true);
  EMC_USB_CELENO_OTP_set_address(addr);
  EMC_USB_CELENO_OTP_write_val(value);
  EMC_USB_CELENO_OTP_set_command(EMC_USB_CELENO_OTP_CMD_WRITE);
  if (!wait_for_ready()) {
    return emc_std_false;
  }
  EMC_USB_CELENO_OTP_enable_write(emc_std_false);
  return !EMC_USB_CELENO_OTP_write_error();
}

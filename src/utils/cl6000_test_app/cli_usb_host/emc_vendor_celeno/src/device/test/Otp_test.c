/**
 * @file
 * @brief   Command unit tests.
 * @author  <karsten.pahnke@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#include "emc/vendor/celeno/device/Otp.h"

#include "emc/test/unittest.h"
#include "emc/std/string.h"

void setUp(void)
{
  EMC_USB_CELENO_OTP_init();
}

void tearDown(void)
{}

// clang-format off

EMC_CUNIT_START_TEST(Otp_read_write) {
  emc_std_uint32_t value;
  emc_std_bool     res;

  res = EMC_USB_CELENO_OTP_read(0, &value);
  EMC_CUNIT_ASSERT(res);

  EMC_CUNIT_ASSERT(0 == value);

  res = EMC_USB_CELENO_OTP_write(0, 0x01234567);
  EMC_CUNIT_ASSERT(res);
  res = EMC_USB_CELENO_OTP_read(0, &value);
  EMC_CUNIT_ASSERT(res);
  EMC_CUNIT_ASSERT(0x01234567 == value);

  res = EMC_USB_CELENO_OTP_write(0, 0x01234560);
  EMC_CUNIT_ASSERT(!res);

  res = EMC_USB_CELENO_OTP_write(1, 0x01234567);
  EMC_CUNIT_ASSERT(res);
  res = EMC_USB_CELENO_OTP_read(1, &value);
  EMC_CUNIT_ASSERT(res);
  EMC_CUNIT_ASSERT(0x01234567 == value);
} EMC_CUNIT_END_TEST

// clang-format on

EMC_CUNIT_TEST_SUITE(Otp_test);

EMC_CUNIT_TEST(Otp_read_write);

EMC_CUNIT_TEST_SUITE_END()

EMC_CUNIT_TEST_SUITE_REGISTRATION(Otp_test)

EMC_TEST_SUITE_DEFINE_MAIN()

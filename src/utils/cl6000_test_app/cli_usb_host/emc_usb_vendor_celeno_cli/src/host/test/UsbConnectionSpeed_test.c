/**
 * @file
 * @brief   Protocol functional test as unit tests
 * @author  <guenter.hildebrandt@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/

#include "emc/test/unittest.h"

#include "libusb-1.0/libusb.h"

#include "emc/std/assert.h"
#include "emc/std/string.h"

void setUp(void)
{}

void tearDown(void)
{}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(Speed_test)
{
  libusb_context*       ctx;
  libusb_device_handle* handle;
  libusb_device*        dev;

  libusb_init(&ctx);

  handle = libusb_open_device_with_vid_pid(ctx, 0x33de, 0x6000);
  EMC_CUNIT_ASSERT(handle != EMC_STD_NULL);

  dev = libusb_get_device(handle);
  EMC_CUNIT_ASSERT(dev != EMC_STD_NULL);

  EMC_CUNIT_ASSERT(LIBUSB_SPEED_HIGH == libusb_get_device_speed(dev));

  libusb_close(handle);
  libusb_exit(ctx);
}

EMC_CUNIT_END_TEST EMC_CUNIT_TEST_SUITE(Speed_test);

EMC_CUNIT_TEST(Speed_test);

EMC_CUNIT_TEST_SUITE_END()

EMC_CUNIT_TEST_SUITE_REGISTRATION(UsbConnectionSpeed_test)

EMC_TEST_SUITE_DEFINE_MAIN()

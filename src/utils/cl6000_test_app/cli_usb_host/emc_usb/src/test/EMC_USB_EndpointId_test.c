/// Copyright (C) 2011-2013, 2020 emsys Embedded Systems GmbH
#include "emc/test/unittest.h"
#include "emc/usb/EndpointId.h"
#include "emc/std/string.h"
#include "emc/std/assert.h"
#include "emc/std/stdbool.h"

static void setUp(void) {}

static void tearDown(void) {}

EMC_CUNIT_START_TEST(EMC_USB_EndpointId_init_test) {
  for (emc_std_uint8_t num = 0; num <= 15; ++num) {
    EMC_USB_EndpointId id = EMC_USB_EndpointId_out(num);
    EMC_CUNIT_ASSERT_EQUAL(num, EMC_USB_EndpointId_number(id));
    EMC_CUNIT_ASSERT_EQUAL(emc_std_true, EMC_USB_EndpointId_is_out(id));
    EMC_CUNIT_ASSERT_EQUAL(emc_std_false, EMC_USB_EndpointId_is_in(id));
    EMC_CUNIT_ASSERT_EQUAL(EMC_USB_EndpointDirection_OUT, EMC_USB_EndpointId_direction(id));
  }
  for (emc_std_uint8_t num = 0; num <= 15; ++num) {
    EMC_USB_EndpointId id = EMC_USB_EndpointId_in(num);
    EMC_CUNIT_ASSERT_EQUAL(num, EMC_USB_EndpointId_number(id));
    EMC_CUNIT_ASSERT_EQUAL(emc_std_false, EMC_USB_EndpointId_is_out(id));
    EMC_CUNIT_ASSERT_EQUAL(emc_std_true, EMC_USB_EndpointId_is_in(id));
    EMC_CUNIT_ASSERT_EQUAL(EMC_USB_EndpointDirection_IN, EMC_USB_EndpointId_direction(id));
  }
  for (emc_std_uint8_t num = 0; num <= 15; ++num) {
    EMC_USB_EndpointId id = EMC_USB_EndpointId_create(num, emc_std_false);
    EMC_CUNIT_ASSERT_EQUAL(num, EMC_USB_EndpointId_number(id));
    EMC_CUNIT_ASSERT_EQUAL(emc_std_true, EMC_USB_EndpointId_is_out(id));
    EMC_CUNIT_ASSERT_EQUAL(emc_std_false, EMC_USB_EndpointId_is_in(id));
    EMC_CUNIT_ASSERT_EQUAL(EMC_USB_EndpointDirection_OUT, EMC_USB_EndpointId_direction(id));
  }
  for (emc_std_uint8_t num = 0; num <= 15; ++num) {
    EMC_USB_EndpointId id = EMC_USB_EndpointId_create(num, emc_std_true);
    EMC_CUNIT_ASSERT_EQUAL(num, EMC_USB_EndpointId_number(id));
    EMC_CUNIT_ASSERT_EQUAL(emc_std_false, EMC_USB_EndpointId_is_out(id));
    EMC_CUNIT_ASSERT_EQUAL(emc_std_true, EMC_USB_EndpointId_is_in(id));
    EMC_CUNIT_ASSERT_EQUAL(EMC_USB_EndpointDirection_IN, EMC_USB_EndpointId_direction(id));
  }
}
EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(EMC_USB_EndpointId_conversion_test)
{

  for (emc_std_uint8_t num = 0; num <= 15; ++num) {
    EMC_USB_EndpointAddress addr = EMC_USB_EndpointAddress_out(num);
    EMC_USB_EndpointId      id = EMC_USB_EndpointId_convert(addr);

    EMC_CUNIT_ASSERT_EQUAL(addr, EMC_USB_EndpointId_address(id));

    EMC_CUNIT_ASSERT_EQUAL(num, EMC_USB_EndpointId_number(id));
    EMC_CUNIT_ASSERT_EQUAL(emc_std_true, EMC_USB_EndpointId_is_out(id));
    EMC_CUNIT_ASSERT_EQUAL(emc_std_false, EMC_USB_EndpointId_is_in(id));

    EMC_CUNIT_ASSERT_EQUAL(num, EMC_USB_EndpointAddress_number(addr));
    EMC_CUNIT_ASSERT_EQUAL(emc_std_true, EMC_USB_EndpointAddress_is_out(addr));
    EMC_CUNIT_ASSERT_EQUAL(emc_std_false, EMC_USB_EndpointAddress_is_in(addr));
  }
  for (emc_std_uint8_t num = 0; num <= 15; ++num) {
    EMC_USB_EndpointAddress addr = EMC_USB_EndpointAddress_in(num);
    EMC_USB_EndpointId      id = EMC_USB_EndpointId_convert(addr);

    EMC_CUNIT_ASSERT_EQUAL(addr, EMC_USB_EndpointId_address(id));

    EMC_CUNIT_ASSERT_EQUAL(num, EMC_USB_EndpointId_number(id));
    EMC_CUNIT_ASSERT_EQUAL(emc_std_false, EMC_USB_EndpointId_is_out(id));
    EMC_CUNIT_ASSERT_EQUAL(emc_std_true, EMC_USB_EndpointId_is_in(id));

    EMC_CUNIT_ASSERT_EQUAL(num, EMC_USB_EndpointAddress_number(addr));
    EMC_CUNIT_ASSERT_EQUAL(emc_std_false, EMC_USB_EndpointAddress_is_out(addr));
    EMC_CUNIT_ASSERT_EQUAL(emc_std_true, EMC_USB_EndpointAddress_is_in(addr));
  }
}

EMC_CUNIT_END_TEST EMC_CUNIT_TEST_SUITE(EMC_USB_EndpointId_Test);

EMC_CUNIT_TEST(EMC_USB_EndpointId_init_test);
EMC_CUNIT_TEST(EMC_USB_EndpointId_conversion_test);

EMC_CUNIT_TEST_SUITE_END()

EMC_CUNIT_TEST_SUITE_REGISTRATION(EMC_USB_EndpointId_Test)

EMC_TEST_SUITE_DEFINE_MAIN()

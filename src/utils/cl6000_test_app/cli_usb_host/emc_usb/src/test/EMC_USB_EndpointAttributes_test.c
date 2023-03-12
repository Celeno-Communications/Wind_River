/// Copyright (C) 2021 emsys Embedded Systems GmbH
#include "emc/test/unittest.h"
#include "emc/usb/EndpointAttributes.h"
#include "emc/std/string.h"
#include "emc/std/assert.h"
#include "emc/std/stdbool.h"

static void setUp(void) {}

static void tearDown(void) {}

EMC_CUNIT_START_TEST(EMC_USB_EndpointAttributes_init_bulk_test) {
  emc_std_uint8_t num = 1;

  EMC_USB_EndpointAttributes attributes;
  EMC_USB_EndpointAttributes_init_bulk(&attributes, EMC_USB_EndpointAddress_in(num), 512);

  {
    EMC_USB_EndpointAddress ep_address = attributes.ep_address;

    EMC_CUNIT_ASSERT_EQUAL(num, EMC_USB_EndpointAddress_number(ep_address));
    EMC_CUNIT_ASSERT_EQUAL(emc_std_true, EMC_USB_EndpointAddress_is_in(ep_address));
    EMC_CUNIT_ASSERT_EQUAL(EMC_USB_TransferType_BULK, attributes.transfer_type);
    EMC_CUNIT_ASSERT_EQUAL(512, attributes.max_packet_size);
    EMC_CUNIT_ASSERT_EQUAL(0, attributes.polling_interval);
  }
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(EMC_USB_EndpointAttributes_init_isochronous_test)
{
  emc_std_uint8_t num = 1;

  EMC_USB_EndpointAttributes attributes;
  EMC_USB_EndpointAttributes_init_isochronous(&attributes, EMC_USB_EndpointAddress_in(num), 1024, 4);

  {
    EMC_USB_EndpointAddress ep_address = attributes.ep_address;

    EMC_CUNIT_ASSERT_EQUAL(num, EMC_USB_EndpointAddress_number(ep_address));
    EMC_CUNIT_ASSERT_EQUAL(emc_std_true, EMC_USB_EndpointAddress_is_in(ep_address));
    EMC_CUNIT_ASSERT_EQUAL(EMC_USB_TransferType_ISOCHRONOUS, attributes.transfer_type);
    EMC_CUNIT_ASSERT_EQUAL(1024, attributes.max_packet_size);
    EMC_CUNIT_ASSERT_EQUAL(4, attributes.polling_interval);
  }
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(EMC_USB_EndpointAttributes_init_interrupt_test)
{
  emc_std_uint8_t num = 1;

  EMC_USB_EndpointAttributes attributes;
  EMC_USB_EndpointAttributes_init_interrupt(&attributes, EMC_USB_EndpointAddress_in(num), 8, 1);

  {
    EMC_USB_EndpointAddress ep_address = attributes.ep_address;

    EMC_CUNIT_ASSERT_EQUAL(num, EMC_USB_EndpointAddress_number(ep_address));
    EMC_CUNIT_ASSERT_EQUAL(emc_std_true, EMC_USB_EndpointAddress_is_in(ep_address));
    EMC_CUNIT_ASSERT_EQUAL(EMC_USB_TransferType_INTERRUPT, attributes.transfer_type);
    EMC_CUNIT_ASSERT_EQUAL(8, attributes.max_packet_size);
    EMC_CUNIT_ASSERT_EQUAL(1, attributes.polling_interval);
  }
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(EMC_USB_EndpointAttributes_init_control_test)
{
  emc_std_uint8_t num = 1;

  EMC_USB_EndpointAttributes attributes;
  EMC_USB_EndpointAttributes_init_control(&attributes, EMC_USB_EndpointAddress_in(num), 64);

  {
    EMC_USB_EndpointAddress ep_address = attributes.ep_address;

    EMC_CUNIT_ASSERT_EQUAL(num, EMC_USB_EndpointAddress_number(ep_address));
    EMC_CUNIT_ASSERT_EQUAL(emc_std_true, EMC_USB_EndpointAddress_is_in(ep_address));
    EMC_CUNIT_ASSERT_EQUAL(EMC_USB_TransferType_CONTROL, attributes.transfer_type);
    EMC_CUNIT_ASSERT_EQUAL(64, attributes.max_packet_size);
    EMC_CUNIT_ASSERT_EQUAL(0, attributes.polling_interval);
  }
}

EMC_CUNIT_END_TEST EMC_CUNIT_TEST_SUITE(EMC_USB_EndpointAttributes_Test);

EMC_CUNIT_TEST(EMC_USB_EndpointAttributes_init_bulk_test);
EMC_CUNIT_TEST(EMC_USB_EndpointAttributes_init_isochronous_test);
EMC_CUNIT_TEST(EMC_USB_EndpointAttributes_init_interrupt_test);
EMC_CUNIT_TEST(EMC_USB_EndpointAttributes_init_control_test);

EMC_CUNIT_TEST_SUITE_END()

EMC_CUNIT_TEST_SUITE_REGISTRATION(EMC_USB_EndpointAttributes_Test)

EMC_TEST_SUITE_DEFINE_MAIN()

/**
 * @file
 * @brief   DescriptorSet Configuration test
 * @author  <ralf.oberlaender@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#include "emc/vendor/celeno/device/usb/descriptor/UniqueChipId.h"
#include "emc/usb/descriptor/Descriptor.h"

#include "emc/vendor/celeno/device/Otp.h"
#include "emc/vendor/celeno/device/MiscReg.h"
#include "emc/test/unittest.h"
#include "emc/std/string.h"
#include "emc/std/ext/stdlib.h"

extern uint32_t unique_id32_0;
extern uint32_t unique_id32_1;

static emc_std_uint32_t original_chip_version;

void setUp(void)
{
  original_chip_version = EMC_CELENO_read_reg32(EMC_USB_CELENO_CHIP_VERSION);
}

void tearDown(void)
{
  EMC_CELENO_write_reg32(EMC_USB_CELENO_CHIP_VERSION, original_chip_version);
}

// clang-format off

EMC_CUNIT_START_TEST(UniqueChipId_test_one_A0)
{
  const uint8_t* serialNumber = 0;

  EMC_USB_CELENO_OTP_init();

  serialNumber = (const uint8_t*)EMC_USB_CELENO_compute_serial_number();

  {
    uint8_t expected[] = {
      34, EMC_USB_StringDescriptor_TYPE,
      '1', 0, '2', 0, '3', 0, '4', 0, '5', 0, '6', 0, '7', 0, '8', 0,
      '9', 0, 'A', 0, 'B', 0, 'C', 0, 'D', 0, 'E', 0, 'F', 0, '1', 0
    };

    EMC_CELENO_write_reg32(EMC_USB_CELENO_CHIP_VERSION, 0x006000A0);

    serialNumber = (const uint8_t*)EMC_USB_CELENO_compute_serial_number();
    EMC_CUNIT_ASSERT(serialNumber != 0);
    EMC_CUNIT_ASSERT(0 == emc_std_memcmp(expected, serialNumber, sizeof(expected)));
  }
}
EMC_CUNIT_END_TEST

EMC_CUNIT_START_TEST(UniqueChipId_test_one_B0)
{
  const uint8_t* serialNumber = 0;

  EMC_USB_CELENO_OTP_init();

  serialNumber = (const uint8_t*)EMC_USB_CELENO_compute_serial_number();

  {
    uint8_t expected[] = {
      34, EMC_USB_StringDescriptor_TYPE,
      'F', 0, '1', 0, 'D', 0, 'E', 0, 'B', 0, 'C', 0, '9', 0, 'A', 0,
      '7', 0, '8', 0, '5', 0, '6', 0, '3', 0, '4', 0, '1', 0, '2', 0
    };

    EMC_CELENO_write_reg32(EMC_USB_CELENO_CHIP_VERSION, 0x006000B0);

    serialNumber = (const uint8_t*)EMC_USB_CELENO_compute_serial_number();
    EMC_CUNIT_ASSERT(serialNumber != 0);
    EMC_CUNIT_ASSERT(0 == emc_std_memcmp(expected, serialNumber, sizeof(expected)));
  }
}


EMC_CUNIT_START_TEST(UniqueChipId_test_two_A0)
{
  const uint8_t* serialNumber = 0;

  unique_id32_0 = 0;
  unique_id32_1 = 0;
  EMC_USB_CELENO_OTP_init();

  serialNumber = (const uint8_t*)EMC_USB_CELENO_compute_serial_number();

  {
    uint8_t expected[] = {
      34, EMC_USB_StringDescriptor_TYPE,
      '0', 0, '0', 0, '0', 0, '0', 0, '0', 0, '0', 0, '0', 0, '0', 0,
      '0', 0, '0', 0, '0', 0, '0', 0, '0', 0, '0', 0, '0', 0, '0', 0
    };

    EMC_CELENO_write_reg32(EMC_USB_CELENO_CHIP_VERSION, 0x006000A0);

    serialNumber = (const uint8_t*)EMC_USB_CELENO_compute_serial_number();
    EMC_CUNIT_ASSERT(serialNumber != 0);
    EMC_CUNIT_ASSERT(0 == emc_std_memcmp(expected, serialNumber, sizeof(expected)));
  }
}
EMC_CUNIT_END_TEST

EMC_CUNIT_START_TEST(UniqueChipId_test_two_B0)
{
  const uint8_t* serialNumber = 0;

  unique_id32_0 = 0;
  unique_id32_1 = 0;
  EMC_USB_CELENO_OTP_init();

  serialNumber = (const uint8_t*)EMC_USB_CELENO_compute_serial_number();

  {
    uint8_t expected[] = {
      34, EMC_USB_StringDescriptor_TYPE,
      '0', 0, '0', 0, '0', 0, '0', 0, '0', 0, '0', 0, '0', 0, '0', 0,
      '0', 0, '0', 0, '0', 0, '0', 0, '0', 0, '0', 0, '0', 0, '0', 0
    };

    EMC_CELENO_write_reg32(EMC_USB_CELENO_CHIP_VERSION, 0x006000B0);

    serialNumber = (const uint8_t*)EMC_USB_CELENO_compute_serial_number();
    EMC_CUNIT_ASSERT(serialNumber != 0);
    EMC_CUNIT_ASSERT(0 == emc_std_memcmp(expected, serialNumber, sizeof(expected)));
  }
}

EMC_CUNIT_START_TEST(UniqueChipId_test_three_A0)
{
  const uint8_t* serialNumber = 0;

  unique_id32_0 = 0xC0D0E0F0;
  unique_id32_1 = 0x40506070;
  EMC_USB_CELENO_OTP_init();

  serialNumber = (const uint8_t*)EMC_USB_CELENO_compute_serial_number();

  {
    uint8_t expected[] =
    {
      34, EMC_USB_StringDescriptor_TYPE,
      'F', 0, '0', 0, 'E', 0, '0', 0, 'D', 0, '0', 0, 'C', 0, '0', 0,
      '7', 0, '0', 0, '6', 0, '0', 0, '5', 0, '0', 0, '4', 0, '0', 0
    };

    EMC_CELENO_write_reg32(EMC_USB_CELENO_CHIP_VERSION, 0x006000A0);

    serialNumber = (const uint8_t*)EMC_USB_CELENO_compute_serial_number();
    EMC_CUNIT_ASSERT(serialNumber != 0);
    EMC_CUNIT_ASSERT(0 == emc_std_memcmp(expected, serialNumber, sizeof(expected)));
  }
}
EMC_CUNIT_END_TEST

EMC_CUNIT_START_TEST(UniqueChipId_test_three_B0)
{
  const uint8_t* serialNumber = 0;

  unique_id32_0 = 0xC0D0E0F0;
  unique_id32_1 = 0x40506070;
  EMC_USB_CELENO_OTP_init();

  serialNumber = (const uint8_t*)EMC_USB_CELENO_compute_serial_number();

  {
    uint8_t expected[] =
    {
      34, EMC_USB_StringDescriptor_TYPE,
      '4', 0, '0', 0, '5', 0, '0', 0, '6', 0, '0', 0, '7', 0, '0', 0,
      'C', 0, '0', 0, 'D', 0, '0', 0, 'E', 0, '0', 0, 'F', 0, '0', 0
    };

    EMC_CELENO_write_reg32(EMC_USB_CELENO_CHIP_VERSION, 0x006000B0);

    serialNumber = (const uint8_t*)EMC_USB_CELENO_compute_serial_number();
    EMC_CUNIT_ASSERT(serialNumber != 0);
    EMC_CUNIT_ASSERT(0 == emc_std_memcmp(expected, serialNumber, sizeof(expected)));
  }
}

EMC_CUNIT_TEST_SUITE(UniqueChipId_test);

EMC_CUNIT_TEST(UniqueChipId_test_one_A0);
EMC_CUNIT_TEST(UniqueChipId_test_one_B0);
EMC_CUNIT_TEST(UniqueChipId_test_two_A0);
EMC_CUNIT_TEST(UniqueChipId_test_two_B0);
EMC_CUNIT_TEST(UniqueChipId_test_three_A0);
EMC_CUNIT_TEST(UniqueChipId_test_three_B0);

EMC_CUNIT_TEST_SUITE_END()

EMC_CUNIT_TEST_SUITE_REGISTRATION(UniqueChipId_test)

EMC_TEST_SUITE_DEFINE_MAIN()

// clang-format on

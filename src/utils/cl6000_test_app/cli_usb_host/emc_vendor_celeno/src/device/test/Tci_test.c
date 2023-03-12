/**
 * @file
 * @brief
 * Copyright (C) 2022 emsys Embedded Systems GmbH
 ****************************************************************************/
#include "emc/vendor/celeno/device/Tci.h"
#include "emc/test/unittest.h"
#include "emc/usb/vendor/celeno/usbwrapper/device/PdmaDescriptorMock.h"
#include "emc/vendor/celeno/device/TciReg.h"

void setUp(void)
{
  EMC_CELENO_TCI_init();
}

void tearDown(void)
{}

// clang-format off

EMC_CUNIT_START_TEST(Tci_test_init)
{
  EMC_CUNIT_ASSERT(EMC_CELENO_TCI_is_software_activation());
  EMC_CELENO_TCI_enable_software_activation(emc_std_false);
  EMC_CUNIT_ASSERT(!EMC_CELENO_TCI_is_software_activation());
  EMC_CELENO_TCI_enable_software_activation(emc_std_true);
  EMC_CUNIT_ASSERT(EMC_CELENO_TCI_is_software_activation());

} EMC_CUNIT_END_TEST

static void add_buffers(emc_std_bool split, emc_std_bool nonstandard)
{
  emc_std_uint8_t buffer[16 * 1024];
  emc_std_uintptr_t p;
  emc_std_size_t len1st;

  PdmaDescriptor pdma_desc[16];
  emc_std_size_t idx;
  p = (emc_std_uintptr_t)buffer;

  for (idx = 16; idx > 0; --idx) {
    PdmaDescriptor* pdma = &pdma_desc[idx];
    emc_std_size_t len_pl = idx * 64;

    PdmaDescriptor_init(pdma);
    PdmaDescriptor_set_destination_address(pdma, p);
    PdmaDescriptor_set_transfer_size(pdma, (emc_std_uint16_t)len_pl);
    PdmaDescriptor_set_LLI_channel(pdma, 1, emc_std_true);
    if (0 == (idx % 4)) {
      PdmaDescriptor_set_padding_present(pdma, emc_std_true);
    }

    p += len_pl;
  }

  idx = 16;
  while (--idx) {
    PdmaDescriptor* pdma = &pdma_desc[idx];

    len1st = 0;
    if (split) {
      len1st = EMC_CELENO_TCI_len1st_for_size(PdmaDescriptor_transfer_size(pdma));
    }
    if (nonstandard) {
      len1st = EMC_CELENO_TCI_nonstd_offset_for_pdma(pdma);
    }

    EMC_CELENO_TCI_add_pdma(pdma, idx, len1st, nonstandard);
  }

  idx = 16;
  while (--idx) {
    PdmaDescriptor* pdma = &pdma_desc[idx];
    emc_std_uint32_t val;

    p = PdmaDescriptor_destination_address(pdma);

    val = EMC_CELENO_TCI_read_reg(0x08);
    EMC_CUNIT_ASSERT_EQUAL(0, val & 0x1);
    EMC_CUNIT_ASSERT_EQUAL(p & 0x00FFFFFC, val & 0x00FFFFFC);
    if (PdmaDescriptor_padding_present(pdma)) {
      EMC_CUNIT_ASSERT(emc_test_bit32(val, 1));
    } else {
      EMC_CUNIT_ASSERT(!emc_test_bit32(val, 1));
    }
    EMC_CUNIT_ASSERT_EQUAL(emc_slice32(emc_std_size_t, 28, 24, val), idx);
    EMC_CUNIT_ASSERT_EQUAL(emc_slice32(emc_std_size_t, 31, 29, val), 1);

    val = EMC_CELENO_TCI_read_reg(0x14);
    EMC_CUNIT_ASSERT_EQUAL(val, idx * 64);

    if (split) {
      val = EMC_CELENO_TCI_read_reg(0x10);
      EMC_CUNIT_ASSERT_EQUAL(val, EMC_CELENO_TCI_len1st_for_size(idx * 64));
      val = EMC_CELENO_TCI_read_reg(0x0C);
      EMC_CUNIT_ASSERT_EQUAL(0, val & 0x3);
      EMC_CUNIT_ASSERT_EQUAL(emc_slice32(emc_std_uint32_t, 23, 0, (p + EMC_CELENO_TCI_len1st_for_size(idx * 64))), val);
    }

    val = EMC_CELENO_TCI_read_reg(0x18);
    if (nonstandard) {
      EMC_CUNIT_ASSERT(emc_test_bit32(val, 8));
      EMC_CUNIT_ASSERT_EQUAL(EMC_CELENO_TCI_nonstd_offset_for_pdma(pdma), emc_slice32(emc_std_uint32_t, 7, 0, val));
    } else {
      EMC_CUNIT_ASSERT_EQUAL(0, val);
    }

    EMC_CUNIT_ASSERT(!EMC_CELENO_TCI_is_pdma_done(idx));
    while(!EMC_CELENO_TCI_is_pdma_done(idx)) {}

    p += idx * 64;
  }
}

EMC_CUNIT_START_TEST(Tci_test_add_buffer)
{
  add_buffers(emc_std_false, emc_std_false);
}

EMC_CUNIT_START_TEST(Tci_test_add_split_buffer)
{
  add_buffers(emc_std_true, emc_std_false);
}

EMC_CUNIT_START_TEST(Tci_test_add_nonstandard_buffer)
{
  add_buffers(emc_std_false, emc_std_true);
}

// clang-format on

EMC_CUNIT_TEST_SUITE(Tci_test);

EMC_CUNIT_TEST(Tci_test_init);
EMC_CUNIT_TEST(Tci_test_add_buffer);
EMC_CUNIT_TEST(Tci_test_add_split_buffer);
EMC_CUNIT_TEST(Tci_test_add_nonstandard_buffer);

EMC_CUNIT_TEST_SUITE_END()

EMC_CUNIT_TEST_SUITE_REGISTRATION(Tci_test)

EMC_TEST_SUITE_DEFINE_MAIN()

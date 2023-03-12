/**
 * @file
 * @brief
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#include "emc/test/unittest.h"
#include "emc/usb/iso/ContinuousBuffer.h"
#include "emc/std/string.h"

static emc_std_uint32_t buffer_mem[2014];
static EMC_MemoryRange  buffer_mem_range = {(emc_std_uintptr_t)&buffer_mem, sizeof(buffer_mem)};

void setUp(void)
{}

void tearDown(void)
{}

// clang-format off

EMC_CUNIT_START_TEST(ContinuousBuffer_test_init)
{
  EMC_USB_ContinuousBuffer self;
  emc_std_uint8_t* p = (emc_std_uint8_t*)buffer_mem;

  EMC_USB_ContinuousBuffer_init(&self, buffer_mem_range, 8, 8, emc_std_false);
  EMC_CUNIT_ASSERT(EMC_USB_ContinuousBuffer_next_usb_pos(&self, EMC_USB_ContinuousBuffer_usb_pos(&self))
                   == EMC_USB_ContinuousBuffer_user_pos(&self));

  EMC_CUNIT_ASSERT(p == (emc_std_uint8_t*)EMC_USB_ContinuousBuffer_buffer(&self));
  EMC_CUNIT_ASSERT(8 * sizeof(emc_std_int32_t) == EMC_USB_ContinuousBuffer_chunk_capacity(&self));
  p += sizeof(EMC_USB_ContinuousBuffer_Header);
  EMC_CUNIT_ASSERT(p == (emc_std_uint8_t*)EMC_USB_ContinuousBuffer_status(&self));
  p += 8 * sizeof(EMC_USB_ContinuousBuffer_Status);
  EMC_CUNIT_ASSERT(p == (emc_std_uint8_t*)EMC_USB_ContinuousBuffer_user_pos(&self));
  EMC_CUNIT_ASSERT(p == (emc_std_uint8_t*)EMC_USB_ContinuousBuffer_chunk_buffer(&self));
}
EMC_CUNIT_END_TEST

EMC_CUNIT_START_TEST(ContinuousBuffer_test_IN)
{
  emc_std_uint32_t payload[8];
  EMC_USB_ContinuousBuffer self;
  unsigned i;

  EMC_USB_ContinuousBuffer_init(&self, buffer_mem_range, 8, 8, emc_std_false);
  EMC_CUNIT_ASSERT(7 == EMC_USB_ContinuousBuffer_chunks_to_write(&self));
  EMC_USB_ContinuousBuffer_set_usb_pos(&self, EMC_USB_ContinuousBuffer_user_pos(&self));
  EMC_CUNIT_ASSERT(8 == EMC_USB_ContinuousBuffer_chunks_to_write(&self));

  for (i=0; i < 16; i++) {
    EMC_CUNIT_ASSERT(8 == EMC_USB_ContinuousBuffer_chunks_to_write(&self));
    emc_std_memcpy(EMC_USB_ContinuousBuffer_chunk_buffer(&self), payload, sizeof(payload));
    EMC_USB_ContinuousBuffer_status(&self)->length = sizeof(payload);
    EMC_USB_ContinuousBuffer_inc_user_pos(&self);
    EMC_CUNIT_ASSERT(7 == EMC_USB_ContinuousBuffer_chunks_to_write(&self));
    EMC_USB_ContinuousBuffer_inc_usb_pos(&self);
    EMC_CUNIT_ASSERT(8 == EMC_USB_ContinuousBuffer_chunks_to_write(&self));
  }
}
EMC_CUNIT_END_TEST

EMC_CUNIT_START_TEST(ContinuousBuffer_test_OUT)
{
  emc_std_uint32_t payload[8];
  EMC_USB_ContinuousBuffer self;
  unsigned i;

  EMC_USB_ContinuousBuffer_init(&self, buffer_mem_range, 8, 8, emc_std_true);
  EMC_CUNIT_ASSERT(1 == EMC_USB_ContinuousBuffer_chunks_to_read(&self));
  EMC_USB_ContinuousBuffer_inc_user_pos(&self);
  EMC_CUNIT_ASSERT(0 == EMC_USB_ContinuousBuffer_chunks_to_read(&self));

  for (i=0; i < 16; i++) {
    EMC_CUNIT_ASSERT(0 == EMC_USB_ContinuousBuffer_chunks_to_read(&self));
    EMC_USB_ContinuousBuffer_inc_usb_pos(&self);
    EMC_CUNIT_ASSERT(1 == EMC_USB_ContinuousBuffer_chunks_to_read(&self));
    emc_std_memcpy(payload, EMC_USB_ContinuousBuffer_chunk_buffer(&self), sizeof(payload));
    EMC_USB_ContinuousBuffer_inc_user_pos(&self);
    EMC_CUNIT_ASSERT(0 == EMC_USB_ContinuousBuffer_chunks_to_read(&self));
  }
}
EMC_CUNIT_END_TEST

EMC_CUNIT_START_TEST(ContinuousBuffer_test_OUT_init)
{
  EMC_USB_ContinuousBuffer self;

  EMC_USB_ContinuousBuffer_init(&self, buffer_mem_range, 8, 8, emc_std_true);
  EMC_CUNIT_ASSERT(1 == EMC_USB_ContinuousBuffer_chunks_to_read(&self));
  EMC_USB_ContinuousBuffer_set_usb_pos(&self, self.payload_begin);
  EMC_CUNIT_ASSERT(1 == EMC_USB_ContinuousBuffer_chunks_to_read(&self));
}
EMC_CUNIT_END_TEST

EMC_CUNIT_TEST_SUITE(ContinuousBuffer_test);
  EMC_CUNIT_TEST(ContinuousBuffer_test_init);
  EMC_CUNIT_TEST(ContinuousBuffer_test_IN);
  EMC_CUNIT_TEST(ContinuousBuffer_test_OUT);
  EMC_CUNIT_TEST(ContinuousBuffer_test_OUT_init);
EMC_CUNIT_TEST_SUITE_END()

EMC_CUNIT_TEST_SUITE_REGISTRATION(ContinuousBuffer_test)

EMC_TEST_SUITE_DEFINE_MAIN()

// clang-format on

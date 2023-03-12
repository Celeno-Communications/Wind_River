#include "emc/std/ext/bitoperation.h"

#include "emc/test/unittest.h"

static void setUp(void)
{
  /* FORM_SET_VERBOSE(stdout,true); */
  /* emc_log_init(); */
}

static void tearDown(void)
{}

EMC_CUNIT_START_TEST(bitoperation_bit_uint8_Test) {
  unsigned i;

  emc_std_uint8_t u8 = 0;

  for (i = 0; i < 8; ++i) {
    EMC_CUNIT_ASSERT(emc_std_false == emc_test_bit8(u8, i));
    emc_set_bit8(&u8, i, emc_std_true);
    EMC_CUNIT_ASSERT(emc_std_true == emc_test_bit8(u8, i));
  }
}
EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(bitoperation_bit_uint16_Test)
{
  unsigned i;

  emc_std_uint16_t u16 = 0;

  for (i = 0; i < 16; ++i) {
    EMC_CUNIT_ASSERT(emc_std_false == emc_test_bit16(u16, i));
    emc_set_bit16(&u16, i, emc_std_true);
    EMC_CUNIT_ASSERT(emc_std_true == emc_test_bit16(u16, i));
  }
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(bitoperation_bit_uint32_Test)
{
  unsigned i;

  emc_std_uint32_t u32 = 0;

  for (i = 0; i < 32; ++i) {
    EMC_CUNIT_ASSERT(emc_std_false == emc_test_bit32(u32, i));
    emc_set_bit32(&u32, i, emc_std_true);
    EMC_CUNIT_ASSERT(emc_std_true == emc_test_bit32(u32, i));
  }

}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(bitoperation_slice_uint8_Test)
{
  emc_std_uint8_t v = 0xFF;

  emc_std_uint8_t u8 = 0xFF;

  EMC_CUNIT_ASSERT(7 == emc_slice8(emc_std_uint8_t, 3, 1, u8));

  emc_set_slice8(3, 1, &u8, 0);
  EMC_CUNIT_ASSERT(0 == emc_slice8(emc_std_uint8_t, 3, 1, u8));

  emc_set_slice8(3, 1, &u8, 7);
  EMC_CUNIT_ASSERT(7 == emc_slice8(emc_std_uint8_t, 3, 1, u8));
  EMC_CUNIT_ASSERT(0xFF == u8);

  emc_set_slice8(7, 0, &u8, 0);
  EMC_CUNIT_ASSERT(0 == emc_slice8(emc_std_uint8_t, 7, 0, u8));
  EMC_CUNIT_ASSERT(0 == u8);

  emc_set_slice8(7, 0, &u8, v);
  EMC_CUNIT_ASSERT(0xFF == emc_slice8(emc_std_uint8_t, 7, 0, u8));

  /* should not compile */
  //emc_set_slice8(8,1,&u8,0);
  //emc_set_slice8(1,2,&u8,0);
  //emc_set_slice8(8,8,&u8,0);
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(bitoperation_slice_uint16_Test)
{
  emc_std_uint8_t v = 0xFF;

  emc_std_uint16_t u16 = 0xFFFF;

  EMC_CUNIT_ASSERT(7 == emc_slice16(emc_std_uint8_t, 3, 1, u16));

  emc_set_slice16(3, 1, &u16, 0);
  EMC_CUNIT_ASSERT(0 == emc_slice16(emc_std_uint8_t, 3, 1, u16));

  emc_set_slice16(3, 1, &u16, 7);
  EMC_CUNIT_ASSERT(7 == emc_slice16(emc_std_uint8_t, 3, 1, u16));
  EMC_CUNIT_ASSERT(0xFFFF == u16);

  emc_set_slice16(15, 0, &u16, 0);
  EMC_CUNIT_ASSERT(0 == emc_slice16(emc_std_uint16_t, 15, 0, u16));
  EMC_CUNIT_ASSERT(0 == u16);

  emc_set_slice16(7, 0, &u16, v);
  EMC_CUNIT_ASSERT(0xFF == emc_slice16(emc_std_uint8_t, 7, 0, u16));

  /* should not compile */
  //emc_set_slice16(16,1,&u16,0);
  //emc_set_slice16(1,2,&u16,0);
  //emc_set_slice16(16,16,&u16,0);
  //emc_set_slice16(15,0,&u16,v);
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(bitoperation_slice_uint32_Test)
{
  emc_std_uint8_t v = 0xFF;

  emc_std_uint32_t u32 = 0xFFFFFFFF;

  EMC_CUNIT_ASSERT(7 == emc_slice32(emc_std_uint8_t, 3, 1, u32));

  emc_set_slice32(3, 1, &u32, 0);
  EMC_CUNIT_ASSERT(0 == emc_slice32(emc_std_uint8_t, 3, 1, u32));

  emc_set_slice32(3, 1, &u32, 7);
  EMC_CUNIT_ASSERT(7 == emc_slice32(emc_std_uint8_t, 3, 1, u32));
  EMC_CUNIT_ASSERT(0xFFFFFFFF == u32);

  emc_set_slice32(31, 0, &u32, 0);
  EMC_CUNIT_ASSERT(0 == emc_slice32(emc_std_uint32_t, 31, 0, u32));
  EMC_CUNIT_ASSERT(0 == u32);

  emc_set_slice32(7, 0, &u32, v);
  EMC_CUNIT_ASSERT(0xFF == emc_slice32(emc_std_uint8_t, 7, 0, u32));

  /* should not compile */
  //emc_set_slice32(32,1,&u32,0);
  //emc_set_slice32(1,2,&u32,0);
  //emc_set_slice32(32,32,&u32,0);
  //emc_set_slice32(31,0,&u32,v);
}

EMC_CUNIT_END_TEST EMC_CUNIT_TEST_SUITE(bitoperation_bit_Test);

EMC_CUNIT_TEST(bitoperation_bit_uint8_Test);
EMC_CUNIT_TEST(bitoperation_bit_uint16_Test);
EMC_CUNIT_TEST(bitoperation_bit_uint32_Test);
EMC_CUNIT_TEST(bitoperation_slice_uint8_Test);
EMC_CUNIT_TEST(bitoperation_slice_uint16_Test);
EMC_CUNIT_TEST(bitoperation_slice_uint32_Test);

EMC_CUNIT_TEST_SUITE_END()

EMC_CUNIT_TEST_SUITE_REGISTRATION(bitoperation_bit_Test)

EMC_TEST_SUITE_DEFINE_MAIN()

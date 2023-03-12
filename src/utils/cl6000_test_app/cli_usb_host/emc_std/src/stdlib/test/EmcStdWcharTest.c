/**
 * @file
 * @brief   test frame work for EmcStdWcharTest.c
 *
 *
 * @author  Steffen <steffen.luzemann@emsys.de> +49-3677-68977-0
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 ****************************************************************************/

#include "emc/config/version.h"
#include "emc/std/wchar.h"
#include "emc/std/stdint.h"
#include "emc/test/unittest.h"

#define TEST_STRING "Test String"

static void setUp(void)
{}

static void tearDown(void)
{}

/**
 * \ingroup WCHAR_Implementation_Test
 * \test
 */
EMC_CUNIT_START_TEST(Wchar_String_Length) {
  size_t          wstring_length;
  emc_std_wchar_t w_string[] = EMC_STR(L, TEST_STRING);

  wstring_length = wcslen(w_string);
  EMC_CUNIT_ASSERT(wstring_length == sizeof(TEST_STRING) - 1);
}
EMC_CUNIT_END_TEST
/**
 * \ingroup WCHAR_Implementation_Test
 * \test
 */
EMC_CUNIT_START_TEST(Wchar_String_Copy)
{
  emc_std_uint32_t i;
  emc_std_wchar_t  w_string[] = EMC_STR(L, TEST_STRING);
  emc_std_wchar_t  copied_string[sizeof(w_string)];
  emc_std_wchar_t* return_ptr;

  return_ptr = wcscpy(copied_string, w_string);

  EMC_CUNIT_ASSERT(return_ptr == copied_string);

  for (i = 0; i < sizeof(TEST_STRING); i++) {
    EMC_CUNIT_ASSERT(*(copied_string + i) == *(w_string + i));
  }

  return_ptr = wcsncpy(copied_string, w_string, sizeof(w_string));

  EMC_CUNIT_ASSERT(return_ptr == copied_string);

  for (i = 0; i < sizeof(TEST_STRING); i++) {
    EMC_CUNIT_ASSERT(*(copied_string + i) == *(w_string + i));
  }
}

EMC_CUNIT_END_TEST EMC_CUNIT_TEST_SUITE(WCHAR_Implementation_Test);

EMC_CUNIT_TEST(Wchar_String_Length);
EMC_CUNIT_TEST(Wchar_String_Copy);

EMC_CUNIT_TEST_SUITE_END()

EMC_CUNIT_TEST_SUITE_REGISTRATION(WCHAR_Implementation_Test)

EMC_TEST_SUITE_DEFINE_MAIN()

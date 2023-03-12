/**
 * @file
 * @brief A EMC_USB_Error checksum module test.
 *
 * @author  Karsten Pahnke
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 */

#include "emc/test/unittest.h"
#include "emc/usb/Error.h"
#include "emc/std/string.h"

static void setUp(void) {}

static void tearDown(void) {}

EMC_CUNIT_START_TEST(EMC_USB_Error_name_test) {
  EMC_USB_Error error = EMC_USB_NO_ERROR;
#if EMC_PRINT
  EMC_CUNIT_ASSERT(0 == emc_std_strcmp("USB NO ERROR", EMC_USB_Error_name(error)));
#else
  EMC_CUNIT_ASSERT(0 == emc_std_strcmp("unknown", EMC_USB_Error_name(error)));
#endif
}
EMC_CUNIT_END_TEST EMC_CUNIT_TEST_SUITE(EMC_USB_Error_Test);

EMC_CUNIT_TEST(EMC_USB_Error_name_test);

EMC_CUNIT_TEST_SUITE_END()

EMC_CUNIT_TEST_SUITE_REGISTRATION(EMC_USB_Error_Test)

EMC_TEST_SUITE_DEFINE_MAIN()

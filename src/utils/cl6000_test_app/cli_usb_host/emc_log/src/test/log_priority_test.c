/**
 * @file
 * @brief   log_priority unit tests.
 * @author  <karsten.pahnke@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#include "emc/log/log.h"

#if EMC_PRINT
#  include "emc/std/stdio.h"
#endif
#include "emc/test/unittest.h"
#include "emc/std/string.h"

void setUp(void)
{}

void tearDown(void)
{}

EMC_CUNIT_START_TEST(log_priority_test_priority_from_string) {
  EMC_CUNIT_ASSERT(EMC_LOG_PRIORITY_OFF == EMC_Log_priority_from_string("OFF"));
  EMC_CUNIT_ASSERT(EMC_LOG_PRIORITY_FATAL == EMC_Log_priority_from_string("FATAL"));
  EMC_CUNIT_ASSERT(EMC_LOG_PRIORITY_ERROR == EMC_Log_priority_from_string("ERROR"));
  EMC_CUNIT_ASSERT(EMC_LOG_PRIORITY_WARN == EMC_Log_priority_from_string("WARN"));
  EMC_CUNIT_ASSERT(EMC_LOG_PRIORITY_INFO == EMC_Log_priority_from_string("INFO"));
  EMC_CUNIT_ASSERT(EMC_LOG_PRIORITY_DEBUG == EMC_Log_priority_from_string("DEBUG"));
  EMC_CUNIT_ASSERT(EMC_LOG_PRIORITY_TRACE == EMC_Log_priority_from_string("TRACE"));
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(log_priority_test_priority_as_string)
{
  EMC_CUNIT_ASSERT(emc_std_strcmp("OFF  ", EMC_Log_priority_as_string(EMC_LOG_PRIORITY_OFF)) == 0);
  EMC_CUNIT_ASSERT(emc_std_strcmp("FATAL", EMC_Log_priority_as_string(EMC_LOG_PRIORITY_FATAL)) == 0);
  EMC_CUNIT_ASSERT(emc_std_strcmp("ERROR", EMC_Log_priority_as_string(EMC_LOG_PRIORITY_ERROR)) == 0);
  EMC_CUNIT_ASSERT(emc_std_strcmp("WARN ", EMC_Log_priority_as_string(EMC_LOG_PRIORITY_WARN)) == 0);
  EMC_CUNIT_ASSERT(emc_std_strcmp("INFO ", EMC_Log_priority_as_string(EMC_LOG_PRIORITY_INFO)) == 0);
  EMC_CUNIT_ASSERT(emc_std_strcmp("DEBUG", EMC_Log_priority_as_string(EMC_LOG_PRIORITY_DEBUG)) == 0);
  EMC_CUNIT_ASSERT(emc_std_strcmp("TRACE", EMC_Log_priority_as_string(EMC_LOG_PRIORITY_TRACE)) == 0);
  //EMC_CUNIT_ASSERT(emc_std_strcmp("ALL  ",EMC_Log_priority_as_string(EMC_LOG_PRIORITY_ALL)) == 0);
}

EMC_CUNIT_END_TEST EMC_CUNIT_TEST_SUITE(log_priority_test);

EMC_CUNIT_TEST(log_priority_test_priority_from_string);
EMC_CUNIT_TEST(log_priority_test_priority_as_string);

EMC_CUNIT_TEST_SUITE_END()

EMC_CUNIT_TEST_SUITE_REGISTRATION(log_priority_test)

EMC_TEST_SUITE_DEFINE_MAIN()

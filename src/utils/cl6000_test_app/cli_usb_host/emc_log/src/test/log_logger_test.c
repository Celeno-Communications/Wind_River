/** @file
 * @brief   log_logger unit tests.
 * @author  <karsten.pahnke@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#include "emc/log/log.h"

#if EMC_PRINT
#  include "emc/std/stdio.h"
#endif
#include "emc/test/unittest.h"
#include "emc/std/string.h"

EMC_STATIC_LOG_LEVEL_DEFINE(EMC_LOG_LEVEL);

static emc_logger_t* root_logger = 0;
static emc_logger_t* logger = 0;

void setUp(void)
{}

void tearDown(void)
{}

EMC_CUNIT_START_TEST(log_logger_test_lookup) {
  root_logger = EMC_Log_root_logger();
  EMC_CUNIT_ASSERT(root_logger != 0);

  logger = EMC_Log_logger("test");
  EMC_CUNIT_ASSERT(logger != 0);

}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(log_logger_test_macros)
{
  unsigned int count = 0;
  unsigned int value = 27;

  EMC_Log_set_priority(logger, EMC_LOG_PRIORITY_TRACE);
  EMC_CUNIT_ASSERT(EMC_LOG_PRIORITY_TRACE == EMC_Log_priority(logger));

  EMC_LOG(logger, TRACE, "trace_text");
  EMC_LOG1(logger, TRACE, "trace_value=%d", value);

  EMC_LOG(logger, FATAL, "fatal_text");
  EMC_LOG1(logger, FATAL, "fatal_value=%d", value);

  count = EMC_Log_log_count(logger);

  // requires set logger priority and set appender for some loggers
  //EMC_CUNIT_ASSERT(count > 0);
  UNUSED_PARAM(count);
}

EMC_CUNIT_END_TEST EMC_CUNIT_TEST_SUITE(log_logger_test);

EMC_CUNIT_TEST(log_logger_test_lookup);
EMC_CUNIT_TEST(log_logger_test_macros);

EMC_CUNIT_TEST_SUITE_END()

EMC_CUNIT_TEST_SUITE_REGISTRATION(log_logger_test)

EMC_TEST_SUITE_DEFINE_MAIN()

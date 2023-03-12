/**
 * @file
 * @brief   log_stream unit tests.
 * @author  <karsten.pahnke@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#include "emc/log/log.h"
#include "emc/log/internal/logger.h"
#include "emc/log/internal/appender_fprintf.h"

#if EMC_PRINT
#  include "emc/std/stdio.h"
#endif
#include "emc/test/unittest.h"
#include "emc/std/string.h"

EMC_STATIC_LOG_LEVEL_DEFINE(EMC_LOG_LEVEL);

static emc_logger_t* logger;

void setUp(void)
{
  logger = EMC_Log_root_logger();
  EMC_Log_set_priority(logger, EMC_LOG_PRIORITY_TRACE);
  EMC_Log_logger_set_appender(logger, emc_log_appender_fprintf(stderr));
}

void tearDown(void)
{}

// clang-format off

EMC_CUNIT_START_TEST(log_appender_fprintf_test_log) {
  unsigned int value = 27;
  EMC_LOG(logger, TRACE, "trace_text");
  EMC_LOG1(logger, TRACE, "trace_value=%d", value);

  EMC_LOG(logger, FATAL, "fatal_text");
  EMC_LOG1(logger, FATAL, "fatal_value=%d", value);

  EMC_CUNIT_ASSERT(EMC_Log_log_count(logger) > 0);
} EMC_CUNIT_END_TEST

EMC_CUNIT_TEST_SUITE(log_appender_fprintf_test);
EMC_CUNIT_TEST(log_appender_fprintf_test_log);
EMC_CUNIT_TEST_SUITE_END()

EMC_CUNIT_TEST_SUITE_REGISTRATION(log_appender_fprintf_test)

EMC_TEST_SUITE_DEFINE_MAIN()

// clang-format on

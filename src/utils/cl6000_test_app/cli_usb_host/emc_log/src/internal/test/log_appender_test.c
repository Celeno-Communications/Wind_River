/**
 * @file
 * @brief   log_appender_null unit tests.
 * @author  <karsten.pahnke@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#include "emc/log/log.h"
#include "emc/log/internal/logger.h"
#include "emc/log/internal/appender.h"
#include "emc/log/internal/appender_null.h"

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
}

void tearDown(void)
{}

// clang-format off

EMC_CUNIT_START_TEST(log_appender_test_default_appender)
{
  emc_log_appender* appender = emc_log_appender_null();
  EMC_CUNIT_ASSERT(appender != EMC_STD_NULL);

  EMC_Log_logger_set_appender(logger, appender);
  EMC_CUNIT_ASSERT(appender == EMC_Log_logger_appender(logger));

  EMC_LOG(logger, FATAL, "fatal_text");

  {
    emc_log_data_t dummy_data;
    /* to trigger output, which is in normal operation suppressed (because log record is 0) */
    (*logger->appender->ftbl->output)(logger->appender->context, logger, &dummy_data);
  }
} EMC_CUNIT_END_TEST

EMC_CUNIT_TEST_SUITE(log_appender_test);
EMC_CUNIT_TEST(log_appender_test_default_appender);
EMC_CUNIT_TEST_SUITE_END()

EMC_CUNIT_TEST_SUITE_REGISTRATION(log_appender_test)

EMC_TEST_SUITE_DEFINE_MAIN()

// clang-format on

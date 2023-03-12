/**
 * @file
 * @brief   log_appender_memory unit tests.
 * @author  <karsten.pahnke@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#include "emc/log/log.h"
#include "emc/log/internal/logger.h"
#include "emc/log/internal/appender_memory.h"

#if EMC_PRINT
#  include "emc/std/stdio.h"
#endif
#include "emc/test/unittest.h"
#include "emc/std/string.h"

EMC_STATIC_LOG_LEVEL_DEFINE(EMC_LOG_LEVEL);

static emc_logger_t* logger;

#define MEM1_ITEMS 20
static emc_log_data_t mem1[MEM1_ITEMS];

#define MEM2_ITEMS 1024
static emc_log_data_t mem2[MEM2_ITEMS];

void setUp(void)
{
  emc_std_memset(mem1, 0, sizeof(mem1));
  emc_std_memset(mem2, 0, sizeof(mem2));

  logger = EMC_Log_root_logger();
}

void tearDown(void)
{}

// clang-format off

EMC_CUNIT_START_TEST(log_appender_memory_test_default_appender)
{
  emc_log_appender* appender;
  unsigned i;

  appender = emc_log_appender_memory(mem1, sizeof(mem1));
  EMC_CUNIT_ASSERT(appender != EMC_STD_NULL);

  EMC_Log_set_priority(logger, EMC_LOG_PRIORITY_TRACE);
  EMC_Log_logger_set_appender(logger, appender);
  EMC_CUNIT_ASSERT(appender == EMC_Log_logger_appender(logger));

  appender = emc_log_appender_memory(mem2, sizeof(mem2));

  // check that memory is filling without wrapping
  for (i = 0; i < MEM1_ITEMS; ++i) {
    EMC_LOG1(logger, TRACE, "trace text on mem %d", i);
    EMC_CUNIT_ASSERT(mem1[i].data[1] == i);
  }
  EMC_CUNIT_ASSERT(mem1[0].data[1] == 0);

  // check wrapping
  for (i = 0; i < MEM1_ITEMS; ++i) {
    EMC_LOG1(logger, TRACE, "trace text on mem %d", i + 10);
    EMC_CUNIT_ASSERT(mem1[i].data[1] == i + 10);
  }
  EMC_CUNIT_ASSERT(mem1[0].data[1] == 10);

#if EMC_LOG_INTERNAL_APPENDER_MEMORY_INSTANCES >= 2
  EMC_CUNIT_ASSERT(appender != EMC_STD_NULL);

  EMC_Log_logger_set_appender(logger, appender);

  EMC_CUNIT_ASSERT(appender == EMC_Log_logger_appender(logger));
#else
  EMC_CUNIT_ASSERT(appender == EMC_STD_NULL);
#endif
} EMC_CUNIT_END_TEST

EMC_CUNIT_TEST_SUITE(log_appender_memory_test);
EMC_CUNIT_TEST(log_appender_memory_test_default_appender);
EMC_CUNIT_TEST_SUITE_END()

EMC_CUNIT_TEST_SUITE_REGISTRATION(log_appender_memory_test)

EMC_TEST_SUITE_DEFINE_MAIN()

// clang-format on

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
static emc_logger_t* logger_emc = 0;
static emc_logger_t* logger_emc_usb = 0;
static emc_logger_t* logger_emc_usb_device = 0;
static emc_logger_t* logger_emc_net = 0;

void setUp(void)
{}

void tearDown(void)
{}

EMC_CUNIT_START_TEST(log_hierarchy_test_list) {
  root_logger = EMC_Log_root_logger();
  EMC_CUNIT_ASSERT(root_logger != 0);

  logger_emc = EMC_Log_logger("emc");
  EMC_CUNIT_ASSERT(logger_emc != 0);

  logger_emc_usb = EMC_Log_logger("emc.usb");
  EMC_CUNIT_ASSERT(logger_emc_usb != 0);

  logger_emc_usb_device = EMC_Log_logger("emc.usb.device");
  EMC_CUNIT_ASSERT(logger_emc_usb_device != 0);

  logger_emc_net = EMC_Log_logger("emc.net");
  EMC_CUNIT_ASSERT(logger_emc_net != 0);

  EMC_Log_logger("emc.net.device");
  EMC_Log_logger("emc.net.device.rx");
  EMC_Log_logger("emc.net.device.tx");
  EMC_Log_logger("emc.usb.device.in");
  EMC_Log_logger("emc.usb.host.out");
  EMC_Log_logger("emc.usb.host.in");

  for (unsigned i = 0; i < 20; ++i) {
    char           buffer[120];
    emc_std_size_t info_size = 0;
    emc_logger_t*  logger = EMC_Log_logger_by_index(i);
    if (logger) {
      info_size = EMC_Log_logger_info(logger, buffer, sizeof(buffer));
      EMC_CUNIT_ASSERT(info_size > 0);
      fprintf(stderr, "buffer=%s\n", buffer);
    } else {
      break;
    }
  }
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(log_hierarchy_test_get_set)
{
  EMC_Log_set_priority(logger_emc, EMC_LOG_PRIORITY_TRACE);
  EMC_CUNIT_ASSERT(EMC_LOG_PRIORITY_TRACE == EMC_Log_priority(logger_emc));

  EMC_LOG(logger_emc, TRACE, "trace_text");
  EMC_LOG(logger_emc_usb, TRACE, "trace_text");
  EMC_LOG(logger_emc_usb_device, TRACE, "trace_text");
  EMC_LOG(logger_emc_net, TRACE, "trace_text");
}

EMC_CUNIT_END_TEST EMC_CUNIT_TEST_SUITE(log_hierarchy_test);

EMC_CUNIT_TEST(log_hierarchy_test_list);
EMC_CUNIT_TEST(log_hierarchy_test_get_set);

EMC_CUNIT_TEST_SUITE_END()

EMC_CUNIT_TEST_SUITE_REGISTRATION(log_hierarchy_test)

EMC_TEST_SUITE_DEFINE_MAIN()

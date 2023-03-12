/**
 * @file
 * @brief   multi_logger unit tests.
 * @author  <karsten.pahnke@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#include "emc/log/log.h"
#include "emc/log/internal/logger.h"
#include "emc/log/internal/appender.h"
#include "emc/log/internal/appender_null.h"
#if EMC_LOG_INTERNAL_APPENDER_PRINTF_INSTANCES > 0
#  include "emc/log/internal/appender_fprintf.h"
#endif

#if EMC_PRINT
#  include "emc/std/stdio.h"
#endif
#include "emc/test/unittest.h"
#include "emc/std/string.h"

EMC_STATIC_LOG_LEVEL_DEFINE(EMC_LOG_LEVEL);

static emc_logger_t* root_logger;
static emc_logger_t* logger_customer;
static emc_logger_t* logger_emc;
static emc_logger_t* logger_emc_usb;
static emc_logger_t* logger_emc_net;
static emc_logger_t* logger_emc_io;
static emc_logger_t* logger_emc_ser;
static emc_logger_t* logger_emc_usb_device;
static emc_logger_t* logger_emc_usb_device_hal;
static emc_logger_t* logger_emc_usb_device_customer;
static emc_logger_t* logger_emc_usb_device_customer_command;

static emc_log_appender* appender_null;
static emc_log_appender* appender_stderr;

extern void EMC_Log_logger_print(emc_logger_t* logger);

void setUp(void)
{
  root_logger = EMC_Log_root_logger();
  logger_emc_usb = EMC_Log_logger("emc.usb");
  logger_emc = EMC_Log_logger("emc");
  logger_emc_net = EMC_Log_logger("emc.net");
  logger_emc_io = EMC_Log_logger("emc.io");
  logger_customer = EMC_Log_logger("customer");
  logger_emc_usb_device = EMC_Log_logger("emc.usb.device");
  logger_emc_usb_device_hal = EMC_Log_logger("emc.usb.device.hal");
  logger_emc_usb_device_customer = EMC_Log_logger("emc.usb.device.customer");
  logger_emc_usb_device_customer_command = EMC_Log_logger("emc.usb.device.customer.commandline");

  appender_null = emc_log_appender_null();
#if EMC_LOG_INTERNAL_APPENDER_PRINTF_INSTANCES > 0
  appender_stderr = emc_log_appender_fprintf(stderr);
#else
  appender_stderr = EMC_STD_NULL;
#endif
}

void tearDown(void)
{}

// clang-format off

EMC_CUNIT_START_TEST(multi_logger_test_recursive_set)
{
  EMC_Log_set_priority(root_logger, EMC_LOG_PRIORITY_ERROR);

  EMC_CUNIT_ASSERT(logger_emc_usb_device_customer_command->priority == EMC_LOG_PRIORITY_ERROR);

  EMC_Log_set_priority(root_logger, EMC_LOG_PRIORITY_TRACE);

  EMC_CUNIT_ASSERT(logger_emc_usb_device_customer_command->priority == EMC_LOG_PRIORITY_TRACE);

  EMC_Log_logger_set_appender(root_logger, appender_null);
  EMC_CUNIT_ASSERT(EMC_Log_logger_appender(logger_emc_usb_device_customer_command) == appender_null);
  EMC_Log_logger_print(root_logger);

#if EMC_LOG_INTERNAL_APPENDER_PRINTF_INSTANCES > 0
  EMC_Log_logger_set_appender(root_logger, appender_stderr);
  EMC_CUNIT_ASSERT(EMC_Log_logger_appender(logger_emc_usb_device_customer_command) == appender_stderr);
#endif
  logger_emc_ser = EMC_Log_logger("emc.ser");
  EMC_Log_logger_print(root_logger);

}
EMC_CUNIT_END_TEST

EMC_CUNIT_START_TEST(multi_logger_test_names)
{
  EMC_Log_set_priority(root_logger, EMC_LOG_PRIORITY_TRACE);

#if EMC_LOG_INTERNAL_APPENDER_PRINTF_INSTANCES > 0
  EMC_Log_logger_set_appender(root_logger, appender_stderr);
#else
  EMC_Log_logger_set_appender(logger_emc_usb, appender_null);
#endif

  EMC_LOG(root_logger, ERROR, "error message on root logger");
  EMC_LOG(logger_emc, TRACE, "trace text on emc");
  EMC_LOG(logger_emc_usb, TRACE, "trace text on emc.usb");
  EMC_LOG(logger_emc_usb_device, WARN, "device warning");
  EMC_LOG(logger_emc_usb_device_hal, WARN, "hal warning");
  EMC_LOG(logger_emc_usb_device_customer, WARN, "customer warning");
  EMC_LOG(logger_emc_usb_device_customer_command, WARN, "customer command warning");
  EMC_Log_logger_print(root_logger);
}
EMC_CUNIT_END_TEST

EMC_CUNIT_START_TEST(multi_logger_test_print)
{}
EMC_CUNIT_END_TEST

EMC_CUNIT_TEST_SUITE(multi_logger_test);

EMC_CUNIT_TEST(multi_logger_test_recursive_set);
EMC_CUNIT_TEST(multi_logger_test_names);
EMC_CUNIT_TEST(multi_logger_test_print);

EMC_CUNIT_TEST_SUITE_END()

EMC_CUNIT_TEST_SUITE_REGISTRATION(multi_logger_test)

EMC_TEST_SUITE_DEFINE_MAIN()

// clang-format on

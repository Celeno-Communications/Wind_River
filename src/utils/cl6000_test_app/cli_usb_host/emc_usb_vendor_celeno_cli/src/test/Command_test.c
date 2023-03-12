/**
 * @file
 * @brief   Command unit tests.
 * @author  <karsten.pahnke@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#include "emc/usb/vendor/celeno/cli/Command.h"
#include "emc/usb/vendor/celeno/cli/host/CommandInit.h"

#if EMC_PRINT
#  include "emc/std/stdio.h"
#endif
#include "emc/test/unittest.h"
#include "emc/std/string.h"

void setUp(void)
{}

void tearDown(void)
{}

EMC_CUNIT_START_TEST(Command_test_print) {

  EMC_USB_CELENO_CLI_Command command;
  emc_std_memset(&command, 0, sizeof(command));

  EMC_CUNIT_ASSERT(20 == sizeof(command));

#if EMC_PRINT
  EMC_USB_CELENO_CLI_Command_print(&command, stderr);
#endif
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(Command_test_get_version)
{

  EMC_USB_CELENO_CLI_Command command;

  EMC_USB_CELENO_CLI_Command_init_get_version(&command);

#if EMC_PRINT
  EMC_USB_CELENO_CLI_Command_print(&command, stderr);
#endif
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(Command_test_single_read)
{
  emc_std_uint32_t address = 0xFF;

  EMC_USB_CELENO_CLI_Command command;

  EMC_USB_CELENO_CLI_Command_init_read(&command, address);

#if EMC_PRINT
  EMC_USB_CELENO_CLI_Command_print(&command, stderr);
#endif
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(Command_test_single_write)
{
  emc_std_uint32_t address = 0xFF;
  emc_std_uint32_t data = 0xFF;
  emc_std_uint32_t mask = 0xFF;

  EMC_USB_CELENO_CLI_Command command;

  EMC_USB_CELENO_CLI_Command_init_write(&command, address, data, mask);

#if EMC_PRINT
  EMC_USB_CELENO_CLI_Command_print(&command, stderr);
#endif
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(Command_test_single_write_fast)
{
  emc_std_uint32_t address = 0xFF;
  emc_std_uint32_t data = 0xFF;
  emc_std_uint32_t mask = 0xFF;

  EMC_USB_CELENO_CLI_Command command;

  EMC_USB_CELENO_CLI_Command_init_write_fast(&command, address, data, mask);

#if EMC_PRINT
  EMC_USB_CELENO_CLI_Command_print(&command, stderr);
#endif
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(Command_test_keep_alive)
{

  EMC_USB_CELENO_CLI_Command command;

  EMC_USB_CELENO_CLI_Command_init_keep_alive(&command);

#if EMC_PRINT
  EMC_USB_CELENO_CLI_Command_print(&command, stderr);
#endif
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(Command_test_usb_disconnect)
{
  emc_std_uint32_t disconnect_time = 10;

  EMC_USB_CELENO_CLI_Command command;

  EMC_USB_CELENO_CLI_Command_init_usb_disconnect(&command, disconnect_time);

#if EMC_PRINT
  EMC_USB_CELENO_CLI_Command_print(&command, stderr);
#endif
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(Command_test_umac_execute)
{
  emc_std_uint32_t jump_address = 0xFF;

  EMC_USB_CELENO_CLI_Command command;

  EMC_USB_CELENO_CLI_Command_init_umac_execute(&command, jump_address);

#if EMC_PRINT
  EMC_USB_CELENO_CLI_Command_print(&command, stderr);
#endif
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(Command_test_umac_restart)
{
  emc_std_uint32_t usb_disconnect_delay_ms = 10;
  emc_std_uint32_t restart_delay_ms = 20;
  emc_std_uint32_t jump_address = 0xFF;

  EMC_USB_CELENO_CLI_Command command;

  EMC_USB_CELENO_CLI_Command_init_umac_restart(&command, usb_disconnect_delay_ms, restart_delay_ms, jump_address);

#if EMC_PRINT
  EMC_USB_CELENO_CLI_Command_print(&command, stderr);
#endif
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(Command_test_logger_level_get)
{
  emc_std_uint32_t index = 27;

  EMC_USB_CELENO_CLI_Command command;

  EMC_USB_CELENO_CLI_Command_init_logger_level_get(&command, index);

#if EMC_PRINT
  EMC_USB_CELENO_CLI_Command_print(&command, stderr);
#endif
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(Command_test_logger_level_set)
{
  emc_std_uint32_t index = 27;
  emc_std_uint32_t level = 5;

  EMC_USB_CELENO_CLI_Command command;

  EMC_USB_CELENO_CLI_Command_init_logger_level_set(&command, index, level);

#if EMC_PRINT
  EMC_USB_CELENO_CLI_Command_print(&command, stderr);
#endif
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(Command_test_logger_info_get)
{
  emc_std_uint32_t index = 27;

  EMC_USB_CELENO_CLI_Command command;

  EMC_USB_CELENO_CLI_Command_init_logger_info_get(&command, index);

#if EMC_PRINT
  EMC_USB_CELENO_CLI_Command_print(&command, stderr);
#endif
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(Command_test_burst_read)
{
  emc_std_uint32_t address = 0xFF;
  emc_std_uint32_t length = 10;

  EMC_USB_CELENO_CLI_Command command;

  EMC_USB_CELENO_CLI_Command_init_burst_read(&command, address, length, emc_std_false);

#if EMC_PRINT
  EMC_USB_CELENO_CLI_Command_print(&command, stderr);
#endif
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(Command_test_burst_write)
{
  emc_std_uint32_t address = 0xFF;
  emc_std_uint32_t length = 10;

  EMC_USB_CELENO_CLI_Command command;

  EMC_USB_CELENO_CLI_Command_init_burst_write(&command, address, length, emc_std_false);

#if EMC_PRINT
  EMC_USB_CELENO_CLI_Command_print(&command, stderr);
#endif
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(Command_test_burst_write_fast)
{
  emc_std_uint32_t address = 0xFF;
  emc_std_uint32_t length = 10;

  EMC_USB_CELENO_CLI_Command command;

  EMC_USB_CELENO_CLI_Command_init_burst_write_fast(&command, address, length, emc_std_false);

#if EMC_PRINT
  EMC_USB_CELENO_CLI_Command_print(&command, stderr);
#endif
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(Command_test_burst_read_zero_copy)
{
  emc_std_uint32_t address = 0xFF;
  emc_std_uint32_t length = 10;

  EMC_USB_CELENO_CLI_Command command;

  EMC_USB_CELENO_CLI_Command_init_burst_read(&command, address, length, emc_std_true);

#if EMC_PRINT
  EMC_USB_CELENO_CLI_Command_print(&command, stderr);
#endif
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(Command_test_burst_write_zero_copy)
{
  emc_std_uint32_t address = 0xFF;
  emc_std_uint32_t length = 10;

  EMC_USB_CELENO_CLI_Command command;

  EMC_USB_CELENO_CLI_Command_init_burst_write(&command, address, length, emc_std_true);

#if EMC_PRINT
  EMC_USB_CELENO_CLI_Command_print(&command, stderr);
#endif
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(Command_test_burst_write_fast_zero_copy)
{
  emc_std_uint32_t address = 0xFF;
  emc_std_uint32_t length = 10;

  EMC_USB_CELENO_CLI_Command command;

  EMC_USB_CELENO_CLI_Command_init_burst_write_fast(&command, address, length, emc_std_true);

#if EMC_PRINT
  EMC_USB_CELENO_CLI_Command_print(&command, stderr);
#endif
}

EMC_CUNIT_END_TEST EMC_CUNIT_TEST_SUITE(Command_test);

EMC_CUNIT_TEST(Command_test_print);
EMC_CUNIT_TEST(Command_test_get_version);
EMC_CUNIT_TEST(Command_test_single_read);
EMC_CUNIT_TEST(Command_test_single_write);
EMC_CUNIT_TEST(Command_test_single_write_fast);
EMC_CUNIT_TEST(Command_test_keep_alive);
EMC_CUNIT_TEST(Command_test_usb_disconnect);
EMC_CUNIT_TEST(Command_test_umac_execute);
EMC_CUNIT_TEST(Command_test_umac_restart);
EMC_CUNIT_TEST(Command_test_logger_level_get);
EMC_CUNIT_TEST(Command_test_logger_level_set);
EMC_CUNIT_TEST(Command_test_logger_info_get);
EMC_CUNIT_TEST(Command_test_burst_read);
EMC_CUNIT_TEST(Command_test_burst_write);
EMC_CUNIT_TEST(Command_test_burst_write_fast);
EMC_CUNIT_TEST(Command_test_burst_read_zero_copy);
EMC_CUNIT_TEST(Command_test_burst_write_zero_copy);
EMC_CUNIT_TEST(Command_test_burst_write_fast_zero_copy);
EMC_CUNIT_TEST_SUITE_END()

EMC_CUNIT_TEST_SUITE_REGISTRATION(Command_test)

EMC_TEST_SUITE_DEFINE_MAIN()

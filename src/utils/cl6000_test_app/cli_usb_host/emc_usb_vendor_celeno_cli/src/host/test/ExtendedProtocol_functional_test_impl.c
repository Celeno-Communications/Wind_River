/**
 * @file
 * @brief   Extended Protocol functional test as unit tests
 * @author  <karsten.pahnke@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#include "emc/usb/vendor/celeno/cli/host/FunctionProxy.h"
#include "emc/usb/vendor/celeno/cli/host/FunctionProxy_private.h"
#include "emc/usb/vendor/celeno/cli/host/Error.h"

#ifdef EMC_TEST_GREYBOX
#  include "emc/usb/vendor/celeno/cli/device/test/DeviceMock.h"
#endif

#include "emc/usb/host/hal/HAL.h"

#include "emc/test/unittest.h"
#include "emc/std/string.h"
#include "emc/std/stdlib.h"

#include "emc/log/log.h"

static EMC_USB_CELENO_CLI_FunctionProxy function_proxy;

#define CHECK_VALID 1
#define CHECK_INVALID 0

uint16_t usb_pid = 0;

int device_enumerated = 0;
int host_enumerated = 0;

static int enumerated(void)
{
  return device_enumerated && host_enumerated;
}

static int create_and_enumerate_host(void)
{
  int                    error;
  EMC_USB_HOST_HAL_Error host_error = EMC_USB_HOST_HAL_init();
  if (host_error == EMC_USB_HOST_HAL_Error_NONE) {
    EMC_USB_CELENO_CLI_FunctionProxyConfig config;
    EMC_USB_CELENO_CLI_FunctionProxyConfig_init(&config);
    config.pid = usb_pid;
    error = EMC_USB_CELENO_CLI_FunctionProxy_init(&function_proxy, &config);
    if (!error) {
      error = EMC_USB_CELENO_CLI_FunctionProxy_start(&function_proxy);
    }
    return error ? 0 : 1;
  } else {
    return 0;
  }
}

static void destroy_host(void)
{
  EMC_USB_CELENO_CLI_FunctionProxy_stop(&function_proxy);
  EMC_USB_CELENO_CLI_FunctionProxy_exit(&function_proxy);
  EMC_USB_HOST_HAL_exit();
}

void setUp(void)
{
#ifdef EMC_TEST_GREYBOX
  device_enumerated = create_and_enumerate_device();
#else
  device_enumerated = 1;
#endif
  host_enumerated = create_and_enumerate_host();
}

void tearDown(void)
{
  destroy_host();
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(ExtendedProtocol_functional_test_usb_disconnect)
{
  int              error;
  emc_std_uint32_t disconnect_time = 3;

  EMC_CUNIT_ASSERT(enumerated());

  error = EMC_USB_CELENO_CLI_FunctionProxy_usb_disconnect(&function_proxy, disconnect_time);

  EMC_CUNIT_ASSERT(!error);
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(ExtendedProtocol_functional_test_umac_execute)
{
  int              error;
  emc_std_uint32_t jump_address = 0xFF;

  EMC_CUNIT_ASSERT(enumerated());

  error = EMC_USB_CELENO_CLI_FunctionProxy_umac_execute(&function_proxy, jump_address);
  EMC_CUNIT_ASSERT(!error);

  jump_address = 0x01;

  error = EMC_USB_CELENO_CLI_FunctionProxy_umac_execute(&function_proxy, jump_address);
  EMC_CUNIT_ASSERT(!error);
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(ExtendedProtocol_functional_test_umac_restart)
{
  int              error;
  emc_std_uint32_t usb_disconnect_delay_ms = 10;
  emc_std_uint32_t restart_delay_ms = 20;
  emc_std_uint32_t jump_address = 0xFF;

  EMC_CUNIT_ASSERT(enumerated());

  error = EMC_USB_CELENO_CLI_FunctionProxy_umac_restart(&function_proxy,
                                                        usb_disconnect_delay_ms,
                                                        restart_delay_ms,
                                                        jump_address);
  EMC_CUNIT_ASSERT(!error);

  jump_address = 0x400;
  error = EMC_USB_CELENO_CLI_FunctionProxy_umac_restart(&function_proxy,
                                                        usb_disconnect_delay_ms,
                                                        restart_delay_ms,
                                                        jump_address);
  EMC_CUNIT_ASSERT(!error);
}

EMC_CUNIT_START_TEST(ExtendedProtocol_functional_test_queued_not_allowed) {
  int error;

  EMC_CUNIT_ASSERT(enumerated());

  EMC_USB_CELENO_CLI_FunctionProxy_queue_begin(&function_proxy);

  error = EMC_USB_CELENO_CLI_FunctionProxy_umac_execute(&function_proxy, (uint32_t)0x400000000);
  EMC_CUNIT_ASSERT(error == EMC_USB_CELENO_CLI_Error_QUEUEING_NOT_ALLOWED);

  error = EMC_USB_CELENO_CLI_FunctionProxy_usb_disconnect(&function_proxy, (uint32_t)1000);
  EMC_CUNIT_ASSERT(error == EMC_USB_CELENO_CLI_Error_QUEUEING_NOT_ALLOWED);

  error = EMC_USB_CELENO_CLI_FunctionProxy_umac_restart(&function_proxy,
                                                        (uint32_t)0x10,
                                                        (uint32_t)0x20,
                                                        (uint32_t)0x400000000);
  EMC_CUNIT_ASSERT(error == EMC_USB_CELENO_CLI_Error_QUEUEING_NOT_ALLOWED);
}

EMC_CUNIT_END_TEST EMC_CUNIT_TEST_SUITE(ExtendedProtocol_functional_test);

EMC_CUNIT_TEST(ExtendedProtocol_functional_test_usb_disconnect);
EMC_CUNIT_TEST(ExtendedProtocol_functional_test_umac_execute);
EMC_CUNIT_TEST(ExtendedProtocol_functional_test_umac_restart);
EMC_CUNIT_TEST(ExtendedProtocol_functional_test_queued_not_allowed);

EMC_CUNIT_TEST_SUITE_END()

EMC_CUNIT_TEST_SUITE_REGISTRATION(ExtendedProtocol_functional_test)

int ExtendedProtocol_functional_test_run(int argc, char* argv[])
{
  if (argc >= 2) {
    usb_pid = (uint16_t)strtoul(argv[1], 0, 0);
    fprintf(stderr, "Set expected USB-PID=0x%04X.\n", usb_pid);
  }
  return EMC_TEST_RUNNER_MAIN(argc, argv);
}

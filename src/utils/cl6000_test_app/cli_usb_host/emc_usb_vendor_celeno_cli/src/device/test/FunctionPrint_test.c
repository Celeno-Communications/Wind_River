/**
 * @file
 * @brief   Function printing unit tests.
 * @author  <karsten.pahnke@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#include "emc/usb/vendor/celeno/cli/device/Function.h"
#include "emc/usb/vendor/celeno/cli/device/Function_private.h"
#include "emc/vendor/celeno/device/usb/descriptor/DescriptorSet.h"

#include "emc/usb/device/Device.h"

#if EMC_PRINT
#  include "emc/std/stdio.h"
#endif

#include "emc/test/unittest.h"
#include "emc/std/string.h"
#include "emc/std/assert.h"
#include "emc/std/stddef.h"

#include "emc/log/log.h"

#define BUFFER_LENGTH (2 * EMC_USB_VENDOR_CELENO_CLI_MAX_COMMAND_TRANSFER_LENGTH)

static emc_std_uint32_t buffer[BUFFER_LENGTH / sizeof(emc_std_uint32_t)];

static EMC_USB_Device*                   device = 0;
static EMC_USB_DeviceConfig              device_config;
static EMC_USB_CELENO_CLI_Function       function;
static EMC_USB_CELENO_CLI_FunctionConfig function_config;

void setUp(void)
{
  const EMC_USB_DescriptorSet* desc_set = EMC_USB_DescriptorSet_instance();
  EMC_USB_DeviceConfig_init(&device_config);
  if (desc_set) {
    device = EMC_USB_Device_create(&device_config, desc_set);
  }

  EMC_USB_CELENO_CLI_FunctionConfig_init(&function_config);
  function_config.interface_number = 0;
  function_config.buffer = buffer;
  function_config.buffer_size = BUFFER_LENGTH;
  EMC_USB_CELENO_CLI_Function_init(&function, &function_config);
}

void tearDown(void)
{}

EMC_CUNIT_START_TEST(FunctionPrint_test_print) {
#if EMC_PRINT
  EMC_USB_CELENO_CLI_Function_print(&function, stderr);
#endif
}

EMC_CUNIT_END_TEST EMC_CUNIT_TEST_SUITE(FunctionPrint_test);

EMC_CUNIT_TEST(FunctionPrint_test_print);

EMC_CUNIT_TEST_SUITE_END()

EMC_CUNIT_TEST_SUITE_REGISTRATION(FunctionPrint_test)

EMC_TEST_SUITE_DEFINE_MAIN()

/** Copyright (C) 2021 emsys Embedded Systems GmbH */

#include "emc/usb/vendor/celeno/cli/device/test/DeviceMock.h"

#include "emc/usb/vendor/celeno/cli/device/Function.h"
#include "emc/usb/vendor/celeno/cli/device/Function_private.h"
#include "emc/vendor/celeno/device/usb/descriptor/DescriptorSet.h"

#include "emc/usb/device/Device.h"
#include "emc/usb/device/test/DeviceMock.h"

static EMC_USB_Device*      device = 0;
static EMC_USB_DeviceConfig device_config;

#define BUFFER_LENGTH (2 * EMC_USB_VENDOR_CELENO_CLI_MAX_COMMAND_TRANSFER_LENGTH)

static emc_std_uint32_t buffer[BUFFER_LENGTH / sizeof(emc_std_uint32_t)];

static EMC_USB_CELENO_CLI_Function       function;
static EMC_USB_CELENO_CLI_FunctionConfig function_config;

int create_and_enumerate_device(void)
{
  emc_std_uint8_t address = 1;
  emc_std_uint8_t config = 1;
  emc_std_bool    success;

  {
    const EMC_USB_DescriptorSet* desc_set = EMC_USB_DescriptorSet_instance();
    EMC_USB_DeviceConfig_init(&device_config);
    if (desc_set) {
      device = EMC_USB_Device_create(&device_config, desc_set);
    }
  }

  EMC_USB_CELENO_CLI_FunctionConfig_init(&function_config);
  function_config.interface_number = 0;
  function_config.buffer = buffer;
  function_config.buffer_size = BUFFER_LENGTH;

  EMC_USB_CELENO_CLI_Function_init(&function, &function_config);

  success = EMC_USB_DeviceMock_connect(device);
  if (success) {
    success = EMC_USB_DeviceMock_reset(device);
  }
  if (success) {
    success = EMC_USB_DeviceMock_set_address(device, address);
  }
  if (success) {
    success = EMC_USB_DeviceMock_set_configuration(device, config);
  }

  return success ? 1 : 0;
}

int configure_device(emc_std_uint8_t config)
{
  emc_std_bool success;
  success = EMC_USB_DeviceMock_set_configuration(device, config);
  return success ? 1 : 0;
}

int set_alt_setting(emc_std_uint8_t interface, emc_std_uint8_t alt_setting)
{
  emc_std_bool success;
  success = EMC_USB_DeviceMock_set_alt_setting(device, interface, alt_setting);
  return success ? 1 : 0;
}

void destroy_device(void)
{
  EMC_USB_CELENO_CLI_Function_stop(&function);

  EMC_USB_Device_destroy();
  device = 0;

}

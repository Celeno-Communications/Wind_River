/** Copyright (C) 2021 emsys Embedded Systems GmbH */

#include "emc/usb/vendor/celeno/cli/Status.h"

#if EMC_PRINT

const char* EMC_USB_CELENO_CLI_Status_as_string(EMC_USB_CELENO_CLI_Status status)
{
  const char* result;
  switch (status) {
  case EMC_USB_CELENO_CLI_Status_SUCCESS: result = "SUCCESS"; break;
  case EMC_USB_CELENO_CLI_Status_INVALID_COMMAND_CODE: result = "INVALID_COMMAND_CODE"; break;
  case EMC_USB_CELENO_CLI_Status_INVALID_COMMAND_LENGTH: result = "INVALID_COMMAND_LENGTH"; break;
  case EMC_USB_CELENO_CLI_Status_INVALID_OFFSET: result = "INVALID_OFFSET"; break;
  case EMC_USB_CELENO_CLI_Status_INVALID_ADDRESS: result = "INVALID_ADDRESS"; break;
  case EMC_USB_CELENO_CLI_Status_CRC_MISMATCH: result = "CRC_MISMATCH"; break;
  case EMC_USB_CELENO_CLI_Status_INVALID_FUNCTION_ERROR: result = "INVALID_FUNCTION_ERROR"; break;
  case EMC_USB_CELENO_CLI_Status_FUNCTION_ERROR: result = "FUNCTION_ERROR"; break;
  default: result = "Unknown"; break;
  }
  return result;
}

#endif /*EMC_PRINT*/

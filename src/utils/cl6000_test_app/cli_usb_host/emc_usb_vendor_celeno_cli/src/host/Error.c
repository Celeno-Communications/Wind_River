/** Copyright (C) 2021 emsys Embedded Systems GmbH */

#include "emc/usb/vendor/celeno/cli/host/Error.h"

const char* EMC_USB_CELENO_CLI_Error_as_string(EMC_USB_CELENO_CLI_Error error)
{
  const char* result;
  switch (error) {
  case EMC_USB_CELENO_CLI_Error_SUCCESS: result = "SUCCESS"; break;
  case EMC_USB_CELENO_CLI_Error_TIMEOUT: result = "TIMEOUT"; break;
  case EMC_USB_CELENO_CLI_Error_CONNECTION_ERROR: result = "CONNECTION_ERROR"; break;
  case EMC_USB_CELENO_CLI_Error_INVALID_PARAMETER: result = "INVALID_PARAMETER"; break;
  case EMC_USB_CELENO_CLI_Error_INVALID_RESPONSE_TYPE: result = "INVALID_RESPONSE_TYPE"; break;
  case EMC_USB_CELENO_CLI_Error_INVALID_RESPONSE_STATUS: result = "INVALID_RESPONSE_STATUS"; break;
  case EMC_USB_CELENO_CLI_Error_INVALID_RESPONSE_LENGTH: result = "INVALID_RESPONSE_LENGTH"; break;
  case EMC_USB_CELENO_CLI_Error_INVALID_VERSION: result = "INVALID_VERSION"; break;
  case EMC_USB_CELENO_CLI_Error_QUEUEING_NOT_ALLOWED: result = "QUEUEING_NOT_ALLOWED"; break;
  case EMC_USB_CELENO_CLI_Error_QUEUE_OVERFLOW: result = "QUEUE_OVERFLOW"; break;
  case EMC_USB_CELENO_CLI_Error_QUEUE_EMPTY: result = "QUEUE_EMPTY"; break;
  case EMC_USB_CELENO_CLI_Error_PENDING: result = "PENDING"; break;
  case EMC_USB_CELENO_CLI_Error_GENERIC: result = "GENERIC"; break;
  default: result = "Unknown"; break;
  }
  return result;
}

/** Copyright (C) 2021 emsys Embedded Systems GmbH */

#include "emc/usb/vendor/celeno/cli/CommandId.h"

emc_std_bool EMC_USB_CELENO_CLI_CommandId_has_response(EMC_USB_CELENO_CLI_CommandId id)
{
  if ((id == EMC_USB_CELENO_CLI_CommandId_SINGLE_WRITE_FAST) ||
      (id == EMC_USB_CELENO_CLI_CommandId_BULK_WRITE_FAST) ||
      (id == EMC_USB_CELENO_CLI_CommandId_BULK_WRITE_FAST_ZCOPY) ||
      (id == EMC_USB_CELENO_CLI_CommandId_DISCONNECT_USB) ||
      (id == EMC_USB_CELENO_CLI_CommandId_UMAC_EXECUTE) ||
      (id == EMC_USB_CELENO_CLI_CommandId_UMAC_RESTART))
  {
    return emc_std_false;
  }

  return emc_std_true;
}

#if EMC_PRINT
const char* EMC_USB_CELENO_CLI_CommandId_as_string(EMC_USB_CELENO_CLI_CommandId id)
{
  const char* result;
  switch (id) {
  case EMC_USB_CELENO_CLI_CommandId_GET_VERSION: result = "GET_VERSION"; break;
  case EMC_USB_CELENO_CLI_CommandId_SINGLE_READ: result = "SINGLE_READ"; break;
  case EMC_USB_CELENO_CLI_CommandId_SINGLE_WRITE: result = "SINGLE_WRITE"; break;
  case EMC_USB_CELENO_CLI_CommandId_SINGLE_WRITE_FAST: result = "SINGLE_WRITE_FAST"; break;
  case EMC_USB_CELENO_CLI_CommandId_KEEP_ALIVE: result = "KEEP_ALIVE"; break;
  case EMC_USB_CELENO_CLI_CommandId_DISCONNECT_USB: result = "DISCONNECT_USB"; break;
  case EMC_USB_CELENO_CLI_CommandId_UMAC_EXECUTE: result = "UMAC EXECUTE"; break;
  case EMC_USB_CELENO_CLI_CommandId_UMAC_RESTART: result = "UMAC RESTART"; break;
  case EMC_USB_CELENO_CLI_CommandId_LOGGER_LEVEL_GET: result = "LOGGER_LEVEL_GET"; break;
  case EMC_USB_CELENO_CLI_CommandId_LOGGER_LEVEL_SET: result = "LOGGER_LEVEL_SET"; break;
  case EMC_USB_CELENO_CLI_CommandId_LOGGER_INFO_GET: result = "LOGGER_INFO_GET"; break;
  case EMC_USB_CELENO_CLI_CommandId_BULK_READ: result = "BULK_READ"; break;
  case EMC_USB_CELENO_CLI_CommandId_BULK_WRITE: result = "BULK_WRITE"; break;
  case EMC_USB_CELENO_CLI_CommandId_BULK_WRITE_FAST: result = "BULK_WRITE_FAST"; break;
  case EMC_USB_CELENO_CLI_CommandId_BULK_READ_ZCOPY: result = "BULK_READ_ZCOPY"; break;
  case EMC_USB_CELENO_CLI_CommandId_BULK_WRITE_ZCOPY: result = "BULK_WRITE_ZCOPY"; break;
  case EMC_USB_CELENO_CLI_CommandId_BULK_WRITE_FAST_ZCOPY: result = "BULK_WRITE_FAST_ZCOPY"; break;
  case EMC_USB_CELENO_CLI_CommandId_FUNCTION_IOCTL_0: result = "FUNCTION_IOCTL_0"; break;
  case EMC_USB_CELENO_CLI_CommandId_FUNCTION_IOCTL_1: result = "FUNCTION_IOCTL_1"; break;
  case EMC_USB_CELENO_CLI_CommandId_FUNCTION_IOCTL_2: result = "FUNCTION_IOCTL_2"; break;
  case EMC_USB_CELENO_CLI_CommandId_FUNCTION_IOCTL_3: result = "FUNCTION_IOCTL_3"; break;
  default: result = "Unknown"; break;
  }
  return result;
}

#endif /*EMC_PRINT*/

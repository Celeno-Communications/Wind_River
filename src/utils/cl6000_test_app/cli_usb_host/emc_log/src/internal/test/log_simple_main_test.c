/**
 * @file
 * @brief   log_simple_main_test unit tests.
 * @author  <ralf.oberlaender@emsys.de>
 * Copyright (C) 2022 emsys Embedded Systems GmbH
 ****************************************************************************/
#include "emc/log/log.h"

int main(int argc, char* argv[])
{
  (void)argc;
  (void)argv;

  EMC_Log_set_priority(EMC_Log_logger("emc.nix.neu"), EMC_LOG_PRIORITY_INFO);
  EMC_Log_set_priority(EMC_Log_logger("emc.nix.neu2"), EMC_LOG_PRIORITY_DEBUG);
  EMC_Log_set_priority(EMC_Log_root_logger(), EMC_LOG_PRIORITY_TRACE);

  if (EMC_LOG_PRIORITY_INFO != EMC_Log_priority(EMC_Log_logger("emc.nix.neu"))) {
    return 1;
  }

  if (EMC_LOG_PRIORITY_DEBUG != EMC_Log_priority(EMC_Log_logger("emc.nix.neu2"))) {
    return 1;
  }

  if (EMC_LOG_PRIORITY_TRACE != EMC_Log_priority(EMC_Log_logger("emc.nix.neu3"))) {
    return 1;
  }

  if (EMC_LOG_PRIORITY_TRACE != EMC_Log_priority(EMC_Log_logger("emc"))) {
    return 1;
  }

  if (EMC_LOG_PRIORITY_TRACE != EMC_Log_priority(EMC_Log_root_logger())) {
    return 1;
  }

  return 0;
}

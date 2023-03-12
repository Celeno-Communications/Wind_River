/**
 * @file
 * @brief
 * Copyright (C) 2022 emsys Embedded Systems GmbH
 ****************************************************************************/
#include "emc/vendor/celeno/device/RegisterSetImpl.h"
#include "emc/std/ext/bitoperation.h"
#include "emc/std/assert.h"

EMC_STATIC_LOG_LEVEL_DEFINE(EMC_LOG_LEVEL);

void EMC_CELENO_RegisterSet_check(emc_logger_t* logger)
{
  uint16_t magic = emc_slice32(uint16_t, 31, 16, mg_umac_config_registers.umac_param.magic_version);
  uint16_t version = emc_slice32(uint16_t, 15, 0, mg_umac_config_registers.umac_param.magic_version);
  uint16_t file_size = emc_slice32(uint16_t, 15, 0, mg_umac_config_registers.umac_param.file_size);

  EMC_LOG3(logger, INFO, "RegisterSet current magic=0x%04x version=0x%04x size=%04d", magic, version, file_size);

  emc_std_assert(magic == EMC_CELENO_UMAC_USB_regs_magic);
  emc_std_assert(version == EMC_CELENO_UMAC_USB_regs_version);
  emc_std_assert(file_size == sizeof(mg_umac_config_registers));

  EMC_LOG(logger, INFO, "OK");
}

/**
 * @file
 * @brief cl6000 specific watchdog implementation
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#include "emc/system/Watchdog.h"
#include "emc/vendor/celeno/device/MiscReg.h"
#include "emc/log/log.h"
#include "emc/std/assert.h"

EMC_STATIC_LOG_LEVEL_DEFINE(EMC_LOG_LEVEL);

#define WD_RESOLUTION 50

void EMC_Watchdog_enable(emc_std_bool enable)
{
  EMC_LOG(EMC_Log_root_logger(), INFO, "");
  EMC_CELENO_wd_enable(enable);
}

void EMC_Watchdog_set_timeout(emc_std_uint32_t timeout_ms)
{
  EMC_LOG1(EMC_Log_root_logger(), INFO, "timeout=%dms", timeout_ms);
  EMC_CELENO_wd_timeout((timeout_ms + (WD_RESOLUTION - 1)) / WD_RESOLUTION);
}

void EMC_Watchdog_keepalive(void)
{
  EMC_CELENO_wd_rewind();
}

emc_std_uint32_t EMC_Watchdog_timeleft(void)
{
  return EMC_CELENO_wd_dyn_time() * WD_RESOLUTION;
}

void EMC_Watchdog_emulation(void)
{
  if (EMC_Watchdog_timeleft() == 0) {
    EMC_LOG(EMC_Log_root_logger(), ERROR, "watchdog time out");
#ifdef __XTENSA__
    {
      extern uint8_t _memmap_seg_irom0_0_start;
      void           (* reset_vector)(void) = (void*)&_memmap_seg_irom0_0_start;
      (*reset_vector)();
    }
#endif
  }
}

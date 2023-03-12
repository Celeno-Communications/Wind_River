/**
 * @file
 *
 * @author  Ralf Oberländer
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/

#include "emc/system/celeno/TestHelper.h"
#include "emc/log/log.h"
#include "emc/std/ext/timestamp.h"
#include "emc/std/assert.h"
#include "emc/std/stddef.h"

EMC_STATIC_LOG_LEVEL_DEFINE(EMC_LOG_LEVEL);

static emc_logger_t* logger()
{
#if EMC_LOG_LOGGING
  return EMC_Log_root_logger();
#else
  return 0;
#endif
}

void emc_test_assert(void)
{
  emc_std_assert(5 == 6);
}

void emc_test_div0_exception()
{
  volatile uint32_t a = 5;
  volatile uint32_t b = 0;
  a = a / b; // enforce EXCAUSE_DIVIDE_BY_ZERO
}

uint32_t emc_test_read32_access(uintptr_t addr)
{
  uint32_t data;
  EMC_LOG1(logger(), INFO, "addr = 0x%08X", addr);
  data = *(uint32_t*)addr;
  EMC_LOG1(logger(), INFO, "done, data = 0x%08X", data);
  return data;
}

void emc_test_write32_access(uintptr_t addr, uint32_t data)
{
  EMC_LOG2(logger(), INFO, "addr = 0x%08X <= 0x%08X", (uint32_t)addr, data);
  *(uint32_t*)addr = data;
  EMC_LOG(logger(), INFO, "done");
}

void EMC_USB_Driver_wait_us(unsigned int microSeconds);

void log_cycle_count_1()
{
  EMC_LOG(logger(), INFO, "");
}

void log_cycle_count_2()
{
  EMC_LOG(logger(), INFO, "");
}

void emc_test_cycle_count()
{
  log_cycle_count_1();
  EMC_USB_Driver_wait_us(10);
  log_cycle_count_2();
}

void emc_test_logging(void)
{
#if defined(__FUNCTION__)
  EMC_LOG1(logger(), FATAL, "log fatal function %s", __FUNCTION__);
#endif
  EMC_LOG1(logger(), ERROR, "log error line %d", __LINE__);
  EMC_LOG1(logger(), WARN, "log warn line %d", __LINE__);
  EMC_LOG(logger(), INFO, "log info");
  EMC_LOG1(logger(), INFO, "log info %d", 1);
  EMC_LOG2(logger(), INFO, "log info %d %d", 21, 22);
  EMC_LOG3(logger(), INFO, "log info %d %d %d", 31, 32, 33);
#if defined(__FUNCTION__)
  EMC_LOG4(logger(), INFO, "log info %d %d %s %d", 41, 42, __FUNCTION__, 44);
#endif
  EMC_LOG5(logger(), INFO, "log info %d %d %d %d %d", 51, 52, 53, 54, 55);
  EMC_LOG1(logger(), DEBUG, "log debug line %d", __LINE__);
  EMC_LOG1(logger(), TRACE, "log trace line %d", __LINE__);
  for (size_t i = 0; i < 22; i++) {
    EMC_LOG1(logger(), FATAL, "log #%d", i);
  }

  {
    timestamp_t t;
    for (emc_std_uint32_t i = 0; i < 10; i++) {
      t = emc_timestamp_to_milliseconds(emc_timestamp());
      EMC_LOG1(logger(), WARN, "timestamp %u", t);
      while (t == emc_timestamp_to_milliseconds(emc_timestamp())) {}
    }
  }
}

void emc_test_log_something_and_never_return()
{
  EMC_LOG(logger(), INFO, "Something - !!!");
  while (1) {}
}

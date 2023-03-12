/** Copyright (C) 2021 emsys Embedded Systems GmbH */

#include "emc/usb/vendor/celeno/cli/TargetMemory.h"
#include "emc/log/log.h"
#include "./dma_copy.h"

EMC_STATIC_LOG_LEVEL_DEFINE(EMC_USB_VENDOR_CELENO_CLI_LOG_LEVEL);

static emc_logger_t* logger()
{
  static emc_logger_t* mg_logger = 0;
  if (!mg_logger) {
    mg_logger = EMC_Log_logger("emc.usb.dev.cli.mem");
  }
  return mg_logger;
}

emc_std_uint32_t EMC_USB_CELENO_CLI_TargetMemory_read(emc_std_uint32_t address)
{
  emc_std_uint32_t* ptr = EMC_USB_CELENO_CLI_TargetMemory_ptr(address);
  emc_std_uint32_t  data = *ptr;

  EMC_LOG2(logger(), TRACE, "address=0x%x data=0x%x", address, data);

  return data;
}

void EMC_USB_CELENO_CLI_TargetMemory_write(emc_std_uint32_t address,
                                           emc_std_uint32_t data,
                                           emc_std_uint32_t mask)
{
  emc_std_uint32_t* ptr = EMC_USB_CELENO_CLI_TargetMemory_ptr(address);
  emc_std_uint32_t  orig = *ptr;

  *ptr = (orig & ~mask) | (data & mask);

  EMC_LOG5(logger(), TRACE, "address=0x%x, orig=0x%x, data=0x%x, mask=0x%x, new=0x%x",
           address, orig, data, mask, *ptr);
}

void EMC_USB_CELENO_CLI_TargetMemory_burst_write(emc_std_uint32_t address,
                                                 const void* buffer,
                                                 emc_std_uint32_t size)
{
  emc_std_uint32_t* ptr = EMC_USB_CELENO_CLI_TargetMemory_ptr(address);
  EMC_LOG4(logger(), DEBUG, "address_cli=0x%x, addr=0x%x, buffer=0x%x, size=0x%x", address, ptr, buffer, size);
  dma_word32_copy(ptr, buffer, size);
  EMC_LOG(logger(), DEBUG, "done");
}

void EMC_USB_CELENO_CLI_TargetMemory_burst_read(emc_std_uint32_t address,
                                                void* buffer,
                                                emc_std_uint32_t size)
{
  emc_std_uint32_t* ptr = EMC_USB_CELENO_CLI_TargetMemory_ptr(address);
  EMC_LOG4(logger(), DEBUG, "address_cli=0x%x, addr=0x%x, buffer=0x%x, size=0x%x", address, ptr, buffer, size);
  dma_word32_copy(buffer, ptr, size);
  EMC_LOG(logger(), DEBUG, "done");
}

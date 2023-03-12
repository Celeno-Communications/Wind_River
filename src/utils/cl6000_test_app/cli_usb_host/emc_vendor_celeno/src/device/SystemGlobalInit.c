/**
 * @file
 * @brief
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#include "emc/vendor/celeno/device/SystemGlobalInit.h"
#include "emc/usb/vendor/celeno/usbwrapper/device/register/usbw_reg.h"
#include "emc/std/ext/bitoperation.h"

#define SRAM_IDMA_CONFIG_OFFSET 0
#define IDMA_CHANNELS_ASSIGNED_TO_LMAC 0x20U
#define IDMA_CHANNELS_ASSIGNED_TO_UMAC 0x0FU
#define IDMA_CHANNELS_ASSIGNED_TO_SMAC 0x10U

static void EMC_USB_CELENO_system_global_init_idma(emc_std_uintptr_t sram_base_address)
{
  emc_std_uint32_t idma_per_processor = 0;

  emc_set_slice32(7, 0, &idma_per_processor, IDMA_CHANNELS_ASSIGNED_TO_LMAC);
  emc_set_slice32(15, 8, &idma_per_processor, IDMA_CHANNELS_ASSIGNED_TO_UMAC);
  emc_set_slice32(23, 16, &idma_per_processor, IDMA_CHANNELS_ASSIGNED_TO_SMAC);

  *(volatile emc_std_uint32_t*)(sram_base_address + SRAM_IDMA_CONFIG_OFFSET) = idma_per_processor;
}

static void EMC_USB_CELENO_system_global_init_usbwrapper(void)
{
  usbw_usbw_conf_enforce_rd_cpl_order_setf(0);
}

void EMC_USB_CELENO_system_global_init(emc_std_uintptr_t sram_base_address)
{
  EMC_USB_CELENO_system_global_init_idma(sram_base_address);
  EMC_USB_CELENO_system_global_init_usbwrapper();
}

/**
 *
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/

#include "emc/vendor/celeno/device/MiscReg.h"

emc_std_uint32_t pci_cfg_0_reg = (CELENO_PRODUCT_ID << 16) + 0xCAFE;
emc_std_uint32_t host_if_reg = 0x00000002;
emc_std_uint32_t usb_capabilities = 0x00000003;
emc_std_uint32_t clock_management = 0x00000000;
#if EMC_VENDOR_CELENO_ASIC_IS_A0
emc_std_uint32_t chip_version = 0x006000A0;
#elif EMC_VENDOR_CELENO_ASIC_IS_B0
emc_std_uint32_t chip_version = 0x006000B0;
#else
#  error Unknown ASIC stepping
#endif

emc_std_uint32_t wd_time = 0x14;
emc_std_uint32_t wd_en = 0x00;
emc_std_uint32_t wd_time_dyn = 0x14;

emc_std_uint32_t EMC_CELENO_read_reg32(emc_std_uint32_t address)
{
  switch (address) {
  case EMC_USB_CELENO_CHIP_VERSION:
    return chip_version;
  case EMC_USB_CELENO_PCI_CFG_0:
    return pci_cfg_0_reg;
  case EMC_USB_CELENO_HOST_IF:
    return host_if_reg;
  case EMC_USB_CELENO_USB_CAPS:
    return usb_capabilities;
  case EMC_USB_CELENO_CLOCK_CTRL:
    return clock_management;
  case EMC_CELENO_WD_TIME:
    return wd_time;
  case EMC_CELENO_WD_EN:
    return wd_en;
  case EMC_CELENO_WD_TIME_DYN:
    return wd_time_dyn;
  default:
    return 0xdeadbeaf;
  }
}

void EMC_CELENO_write_reg32(emc_std_uint32_t address, emc_std_uint32_t value)
{
  switch (address) {
  case EMC_USB_CELENO_CHIP_VERSION:
    chip_version = value;
    break;
  case EMC_USB_CELENO_HOST_IF:
    host_if_reg = value;
    break;
  case EMC_USB_CELENO_USB_CAPS:
    usb_capabilities = value;
    break;
  case EMC_USB_CELENO_CLOCK_CTRL:
    clock_management = value;
    break;
  case EMC_CELENO_WD_TIME:
    wd_time = value;
    break;
  case EMC_CELENO_WD_EN:
    wd_en = value;
    break;
  case EMC_CELENO_WD_REWIND:
    wd_time_dyn = wd_time;
    break;
  default:
    break;
  }
}

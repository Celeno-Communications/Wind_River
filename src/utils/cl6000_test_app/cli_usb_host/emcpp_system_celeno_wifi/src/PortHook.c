/**
 * @file
 * @brief
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#include "emc/hw/port/Port.h"
#include "emc/system/celeno/PortHook.h"

#include "emc/std/stdbool.h"
#include "emc/std/ext/bitoperation.h"

static emc_std_uintptr_t mg_dwc3_base_address = 0;
static emc_std_bool      mg_disable_ss_pm = emc_std_false;
static emc_std_bool      mg_disable_hs_pm = emc_std_false;
static emc_std_uint32_t  mg_dcfg_ignore_mask = 0;
static emc_std_uint32_t  mg_dctl_ignore_mask = 0;

#define DWC_usb3_DCFG_OFFSET 0x0000C700
#define DWC_usb3_DCTL_OFFSET 0x0000C704

#define DWC_usb3_DCFG_LPMCAP_POS 22

#define DWC_usb3_DCTL_ACCEPTU1ENA_POS 9
#define DWC_usb3_DCTL_INITU1ENA_POS 10
#define DWC_usb3_DCTL_ACCEPTU2ENA_POS 11
#define DWC_usb3_DCTL_INITU2ENA_POS 12

#define DWC_usb3_DCTL_L1HibernationEn_POS 18
#define DWC_usb3_DCTL_LPM_NYET_thres_LSB 20
#define DWC_usb3_DCTL_LPM_NYET_thres_MSB 23
#define DWC_usb3_DCTL_HIRDTHRES_LSB 24
#define DWC_usb3_DCTL_HIRDTHRES_MSB 28

void EMC_USB_CELENO_port_hook_init(emc_std_uintptr_t base_usb)
{
  mg_dwc3_base_address = base_usb;

  mg_disable_ss_pm = emc_std_false;
  mg_disable_hs_pm = emc_std_false;

  mg_dcfg_ignore_mask = 0;
  mg_dctl_ignore_mask = 0;
}

void EMC_USB_CELENO_port_hook_disable_ss_pm(void)
{
  mg_disable_ss_pm = emc_std_true;

  emc_set_bit32(&mg_dctl_ignore_mask, DWC_usb3_DCTL_INITU2ENA_POS, emc_std_true);
  emc_set_bit32(&mg_dctl_ignore_mask, DWC_usb3_DCTL_ACCEPTU2ENA_POS, emc_std_true);
  emc_set_bit32(&mg_dctl_ignore_mask, DWC_usb3_DCTL_INITU1ENA_POS, emc_std_true);
  emc_set_bit32(&mg_dctl_ignore_mask, DWC_usb3_DCTL_ACCEPTU1ENA_POS, emc_std_true);
}

void EMC_USB_CELENO_port_hook_disable_hs_pm(void)
{
  mg_disable_hs_pm = emc_std_true;

  emc_set_bit32(&mg_dcfg_ignore_mask, DWC_usb3_DCFG_LPMCAP_POS, emc_std_true);

  emc_set_bit32(&mg_dctl_ignore_mask, DWC_usb3_DCTL_L1HibernationEn_POS, emc_std_true);
  emc_set_slice32(DWC_usb3_DCTL_LPM_NYET_thres_MSB, DWC_usb3_DCTL_LPM_NYET_thres_LSB, &mg_dctl_ignore_mask, 0xF);
  emc_set_slice32(DWC_usb3_DCTL_HIRDTHRES_MSB, DWC_usb3_DCTL_HIRDTHRES_LSB, &mg_dctl_ignore_mask, 0x1F);

  // l1_deep_low_power ???
}

#if EMC_HW_PORT_READ_HOOK
void EMC_HW_Port_read_hook(emc_std_uintptr_t address, emc_std_uint32_t* value)
{
  UNUSED_PARAM(address);
  UNUSED_PARAM(value);
}

#endif

#if EMC_HW_PORT_WRITE_HOOK
void EMC_HW_Port_write_hook(emc_std_uintptr_t address, emc_std_uint32_t* value)
{
  if (mg_disable_ss_pm || mg_disable_hs_pm) {
    if (address == mg_dwc3_base_address + DWC_usb3_DCTL_OFFSET) {
      *value &= ~mg_dctl_ignore_mask;
      *value |= (*(volatile emc_std_uint32_t*)address) & mg_dctl_ignore_mask;
    }
  }

  if (mg_disable_hs_pm) {
    if (address == mg_dwc3_base_address + DWC_usb3_DCFG_OFFSET) {
      *value &= ~mg_dcfg_ignore_mask;
      *value |= (*(volatile emc_std_uint32_t*)address) & mg_dcfg_ignore_mask;
    }
  }
}

#endif

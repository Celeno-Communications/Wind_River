/**
 * @file
 * @brief
 * Copyright (C) 2022 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_VENDOR_CELENO_DEVICE_RegisterSetImpl_H
#define EMC_VENDOR_CELENO_DEVICE_RegisterSetImpl_H

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

#include "emc/log/log.h"
#include "emc/vendor/celeno/device/RegisterSet.h"
#include "emc/std/stdbool.h"
#include "emc/std/ext/bitoperation.h"

/**
 * Check if configuration register set is valid. Asserts if not.
 */
void EMC_CELENO_RegisterSet_check(emc_logger_t* logger);

/** Check whether the Wifi function is included in the current profile. */
static inline emc_std_bool EMC_CELENO_RegisterSet_profile_supports_wifi(void)
{ return mg_umac_config_registers.umac_param.usb_profile != EMC_CELENO_UMAC_USB_profile_bluetooth_only; }

/** Check whether the Bluetooth function is included in the current profile. */
static inline emc_std_bool EMC_CELENO_RegisterSet_profile_supports_bluetooth(void)
{ return mg_umac_config_registers.umac_param.usb_profile != EMC_CELENO_UMAC_USB_profile_wifi_only; }

/** Check whether the USBWrapper module is available/usable. */
static inline emc_std_bool EMC_CELENO_RegisterSet_usb_wrapper_available(void)
{
  return (mg_umac_config_registers.umac_param.capabilities
          & EMC_CELENO_UMAC_CAPS_HAS_USBWRAPPER) ? emc_std_true : emc_std_false;
}

static inline emc_std_uint8_t EMC_CELENO_RegisterSet_aggr_opmode(const EMC_CELENO_DOWNSTREAM_AGGR_Param* regs)
{ return emc_slice32(emc_std_uint8_t, 3, 0, regs->capabilities); }

static inline emc_std_bool EMC_CELENO_RegisterSet_aggr_opmode_is_buffered(const EMC_CELENO_DOWNSTREAM_AGGR_Param* regs)
{
  emc_std_uint8_t opmode = emc_slice32(emc_std_uint8_t, 3, 0, regs->capabilities);
  return (opmode == EMC_CELENO_AGGR_OpMode_buffered) ? emc_std_true
         : (opmode == EMC_CELENO_AGGR_OpMode_buffered_tci_split) ? emc_std_true
         : (opmode == EMC_CELENO_AGGR_OpMode_buffered_tci_nonstd) ? emc_std_true
         : emc_std_false;
}

/** Return value of us lli config register. */
static inline emc_std_uint8_t EMC_CELENO_RegisterSet_lli_config_us(emc_std_uint8_t lli_index)
{
  return ((emc_std_uint8_t*)(&mg_umac_config_registers.lli_us_config.lli_config_0_3))[lli_index];
}

/*** Check whether the upstream LLI channel is configured to complete all new pDMAs immediately (no USB transport) */
static inline emc_std_bool EMC_CELENO_RegisterSet_immediate_complete(emc_std_uint8_t lli_index)
{
  return (EMC_CELENO_RegisterSet_lli_config_us(lli_index)
          & EMC_CELENO_LLI_US_CFG_immediate_completion) ? emc_std_true : emc_std_false;
}

/*** Check whether the upstream LLI channel is configured to generate an INT to LMAC */
static inline emc_std_bool EMC_CELENO_RegisterSet_us_lli_lmac_int(emc_std_uint8_t lli_index)
{
  return (EMC_CELENO_RegisterSet_lli_config_us(lli_index)
          & EMC_CELENO_LLI_US_CFG_lmac_interrupt) ? emc_std_true : emc_std_false;
}

/*** Check whether the upstream LLI channel is configured to merge RXV with data (no aggregation) */
static inline emc_std_bool EMC_CELENO_RegisterSet_merge_and_pass(emc_std_uint8_t lli_index)
{
  return (EMC_CELENO_RegisterSet_lli_config_us(lli_index)
          & EMC_CELENO_LLI_US_CFG_merge_and_pass) ? emc_std_true : emc_std_false;
}

/** Return value of downstream LLI config register. */
static inline emc_std_uint8_t EMC_CELENO_RegisterSet_lli_config_ds(emc_std_uint8_t lli_index)
{
  return ((emc_std_uint8_t*)(&mg_umac_config_registers.lli_ds_config.lli_config_0_3))[lli_index];
}

/** Check whether the downstream LLI channel is configured to use TCP Checksum Insertion HW */
static inline emc_std_bool EMC_CELENO_RegisterSet_tci_sw_mode(emc_std_uint8_t lli_index)
{
  return (EMC_CELENO_RegisterSet_lli_config_ds(lli_index)
          & EMC_CELENO_LLI_DS_CFG_tci_sw_mode) ? emc_std_true : emc_std_false;
}

/*** Check whether the downstream LLI channel is configured to generate an INT to LMAC */
static inline emc_std_bool EMC_CELENO_RegisterSet_ds_lli_lmac_int(emc_std_uint8_t lli_index)
{
  return (EMC_CELENO_RegisterSet_lli_config_ds(lli_index)
          & EMC_CELENO_LLI_DS_CFG_lmac_interrupt) ? emc_std_true : emc_std_false;
}

#if EMC_TEST

static inline void EMC_CELENO_RegisterSet_set_lli_config_us(emc_std_uint8_t lli_index, emc_std_uint8_t value)
{
  ((emc_std_uint8_t*)(&mg_umac_config_registers.lli_us_config.lli_config_0_3))[lli_index] = value;
}

static inline void EMC_CELENO_RegisterSet_set_lli_config_ds(emc_std_uint8_t lli_index, emc_std_uint8_t value)
{
  ((emc_std_uint8_t*)(&mg_umac_config_registers.lli_ds_config.lli_config_0_3))[lli_index] = value;
}

#endif

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_VENDOR_CELENO_DEVICE_RegisterSetImpl_H */

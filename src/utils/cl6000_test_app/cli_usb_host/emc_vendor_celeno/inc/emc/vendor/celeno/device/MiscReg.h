/**
 * @file
 * @brief The Misc Register access API
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_VENDOR_CELENO_DEVICE_MiscReg_H
#define EMC_VENDOR_CELENO_DEVICE_MiscReg_H

#include "emc/vendor/celeno/configure.h"
#include "emc/std/stdint.h"
#include "emc/std/ext/bitoperation.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/** PCI_CFG_0 register address */
#define EMC_USB_CELENO_PCI_CFG_0 0x603F0000

/** System Clock Select register address */
#define EMC_USB_CELENO_CLOCK_CTRL 0x607C600C

#define REG_MACSYS_GCU_BASE_ADDR (0x607C5000)

/** Chip-version register address */
#define EMC_USB_CELENO_CHIP_VERSION (REG_MACSYS_GCU_BASE_ADDR + 0x50)

/** HOST_IF register address */
#define EMC_USB_CELENO_HOST_IF (REG_MACSYS_GCU_BASE_ADDR + 0x140)

/** USB_CAPABILITIES register */
#define EMC_USB_CELENO_USB_CAPS (REG_MACSYS_GCU_BASE_ADDR + 0x14C)

/** System WatchDog timeout register address */
#define EMC_CELENO_WD_TIME (REG_MACSYS_GCU_BASE_ADDR + 0x1E8)
/** System WatchDog enable register address */
#define EMC_CELENO_WD_EN (REG_MACSYS_GCU_BASE_ADDR + 0x1EC)
/** System WatchDog rewind register address */
#define EMC_CELENO_WD_REWIND (REG_MACSYS_GCU_BASE_ADDR + 0x1F0)
/** System WatchDog time left register address */
#define EMC_CELENO_WD_TIME_DYN (REG_MACSYS_GCU_BASE_ADDR + 0x1F4)

/**
 * Read a register value.
 * @param address
 * @return the value of the register.
 */
emc_std_uint32_t EMC_CELENO_read_reg32(emc_std_uint32_t address);

/**
 * Write a register value (mock only, not implemented for target)
 * @param address
 * @param value the value of the register.
 */
void EMC_CELENO_write_reg32(emc_std_uint32_t address, emc_std_uint32_t value);

/** Get vendor-ID from DWC3-GUID */
static inline emc_std_uint16_t EMC_USB_CELENO_vendor_id_from_guid(uint32_t guid)
{ return emc_slice32(emc_std_uint16_t, 15, 0, guid); }

/** Get Product-ID from DWC3-GUID */
static inline emc_std_uint16_t EMC_USB_CELENO_product_id_from_guid(uint32_t guid)
{ return emc_slice32(emc_std_uint16_t, 31, 16, guid); }

/** Chip Version STEP A */
#define EMC_USB_CELENO_STEP_A 0xA
/** Chip Version STEP B */
#define EMC_USB_CELENO_STEP_B 0xB

/** Get Chip-Product-ID */
static inline emc_std_uint16_t EMC_USB_CELENO_chip_product_id(void)
{ return emc_slice32(emc_std_uint16_t, 23, 8, EMC_CELENO_read_reg32(EMC_USB_CELENO_CHIP_VERSION)); }

/** Get Chip-Version-Step-ID */
static inline emc_std_uint8_t EMC_USB_CELENO_chip_version_step(void)
{ return emc_slice32(emc_std_uint8_t, 7, 4, EMC_CELENO_read_reg32(EMC_USB_CELENO_CHIP_VERSION)); }

/** Get Chip-Version-Revision-ID */
static inline emc_std_uint8_t EMC_USB_CELENO_chip_version_rev(void)
{ return emc_slice32(emc_std_uint8_t, 3, 0, EMC_CELENO_read_reg32(EMC_USB_CELENO_CHIP_VERSION)); }

/** Get USB pid from PCI_CFG[0] register */
static inline emc_std_uint16_t EMC_USB_CELENO_pci_cfg_read_pid(void)
{ return emc_slice32(emc_std_uint16_t, 31, 16, EMC_CELENO_read_reg32(EMC_USB_CELENO_PCI_CFG_0)); }

/** Check for Host IF USB/PCIe in HOST_IF register */
static inline emc_std_bool EMC_USB_CELENO_host_if_is_usb(void)
{ return !emc_test_bit32(EMC_CELENO_read_reg32(EMC_USB_CELENO_HOST_IF), 0); }

/** Check for speed limitation HOST_IF register */
static inline emc_std_bool EMC_USB_CELENO_host_if_is_hs(void)
{ return !emc_test_bit32(EMC_CELENO_read_reg32(EMC_USB_CELENO_HOST_IF), 1); }

/** Check for SS PM disable in USB_CAPABILITIES register */
static inline emc_std_bool EMC_USB_CELENO_usb_caps_ss_pm_disabled(void)
{ return !emc_test_bit32(EMC_CELENO_read_reg32(EMC_USB_CELENO_USB_CAPS), 1); }

/** Check for HS PM disable in USB_CAPABILITIES register */
static inline emc_std_bool EMC_USB_CELENO_usb_caps_hs_pm_disabled(void)
{ return !emc_test_bit32(EMC_CELENO_read_reg32(EMC_USB_CELENO_USB_CAPS), 0); }

/** Set system clock to pll clock */
static inline void EMC_USB_CELENO_clk_from_pll(void)
{ EMC_CELENO_write_reg32(EMC_USB_CELENO_CLOCK_CTRL, 1); }

/** Get system clock to pll clock status*/
static inline emc_std_bool EMC_USB_CELENO_clk_from_pll_enabled(void)
{ return (EMC_CELENO_read_reg32(EMC_USB_CELENO_CLOCK_CTRL) == 1) ? emc_std_true : emc_std_false; }

/** Enable watchdog */
static inline void EMC_CELENO_wd_enable(emc_std_bool enable)
{ EMC_CELENO_write_reg32(EMC_CELENO_WD_EN, enable ? 1 : 0); }

/** Set watchdog timeout in 50ms resolution */
static inline void EMC_CELENO_wd_timeout(emc_std_uint32_t timeout_50ms)
{ EMC_CELENO_write_reg32(EMC_CELENO_WD_TIME, timeout_50ms); }

/** Get reset watchdog */
static inline void EMC_CELENO_wd_rewind(void)
{ EMC_CELENO_write_reg32(EMC_CELENO_WD_REWIND, 1); }

/** Get watchdog time left  in 50ms resolution */
static inline emc_std_uint32_t EMC_CELENO_wd_dyn_time(void)
{ return EMC_CELENO_read_reg32(EMC_CELENO_WD_TIME_DYN); }

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_VENDOR_CELENO_DEVICE_MiscReg_H */

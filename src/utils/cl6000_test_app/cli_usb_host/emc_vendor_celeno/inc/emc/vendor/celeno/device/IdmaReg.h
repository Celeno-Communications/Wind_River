/**
 * @file
 * @brief
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_VENDOR_CELENO_DEVICE_IdmaReg_H
#define EMC_VENDOR_CELENO_DEVICE_IdmaReg_H

#include "emc/std/stdint.h"
#include "emc/std/stddef.h"
#include "emc/std/ext/bitoperation.h"

/** The base address of the IDMA register space */
#define CELENO_IDMA_BASE_ADDRESS 0x607d9000

/** The storage for the register space */
static volatile emc_std_uint32_t* reg_base = (volatile emc_std_uint32_t*)CELENO_IDMA_BASE_ADDRESS;

/** Initialize the base register
 * @param base The base address
 */
static inline void CELENO_IDMA_init_reg_base(emc_std_uintptr_t base)
{ reg_base = (volatile emc_std_uint32_t*)base; }

/** Software reset */
static inline void CELENO_IDMA_reset(void)
{ emc_set_bit32(reg_base + 0, 0, emc_std_true); }

/** stop all transfers */
static inline void CELENO_IDMA_stop(void)
{ emc_set_bit32(reg_base + 1, 0, emc_std_true); }

/** @return the raw status completed flag for @p channel */
static inline emc_std_bool CELENO_IDMA_raw_status_completed(CELENO_IDMA_CHANNEL channel)
{ return emc_test_bit32(reg_base[2], channel * 4); }

/** @return the raw status rx error flag for @p channel */
static inline emc_std_bool CELENO_IDMA_raw_status_rx_error(CELENO_IDMA_CHANNEL channel)
{ return emc_test_bit32(reg_base[2], channel * 4 + 1); }

/** @return the raw status tx error flag for @p channel */
static inline emc_std_bool CELENO_IDMA_raw_status_tx_error(CELENO_IDMA_CHANNEL channel)
{ return emc_test_bit32(reg_base[2], channel * 4 + 2); }

/** @return the raw status overwrite error flag for @p channel */
static inline emc_std_bool CELENO_IDMA_raw_status_overwrite_error(CELENO_IDMA_CHANNEL channel)
{ return emc_test_bit32(reg_base[2], channel * 4 + 3); }

/** Set interrupt enable flag for completed transfers on @p channel */
static inline void CELENO_IDMA_int_enable_completed(CELENO_IDMA_CHANNEL channel, emc_std_bool enable)
{ emc_set_bit32(reg_base + 3, channel * 4, enable); }

/** Set interrupt enable flag for completed transfers on @p channel */
static inline void CELENO_IDMA_int_enable_rx_error(CELENO_IDMA_CHANNEL channel, emc_std_bool enable)
{ emc_set_bit32(reg_base + 3, channel * 4 + 1, enable); }

static inline void CELENO_IDMA_int_enable_tx_error(CELENO_IDMA_CHANNEL channel, emc_std_bool enable)
{ emc_set_bit32(reg_base + 3, channel * 4 + 2, enable); }

static inline void CELENO_IDMA_int_enable_overwrite_error(CELENO_IDMA_CHANNEL channel, emc_std_bool enable)
{ emc_set_bit32(reg_base + 3, channel * 4 + 3, enable); }

static inline void CELENO_IDMA_source_address(CELENO_IDMA_CHANNEL channel, emc_std_uint32_t src)
{ reg_base[12 + channel * 4] = src; }

static inline void CELENO_IDMA_destination_address(CELENO_IDMA_CHANNEL channel, emc_std_uint32_t dst)
{ reg_base[13 + channel * 4] = dst; }

static inline void CELENO_IDMA_info(CELENO_IDMA_CHANNEL channel, emc_std_uint16_t info)
{ reg_base[14 + channel * 4] = info; }

static inline emc_std_bool CELENO_IDMA_busy(CELENO_IDMA_CHANNEL channel)
{ return emc_test_bit32(reg_base[15 + channel * 4], 0); }

static inline emc_std_bool CELENO_IDMA_request_active(CELENO_IDMA_CHANNEL channel)
{ return emc_test_bit32(reg_base[15 + channel * 4], 1); }

static inline void CELENO_IDMA_clear(CELENO_IDMA_CHANNEL channel)
{ emc_set_bit32(reg_base + 9, channel * 4, emc_std_true); }

static inline emc_std_uint8_t CELENO_IDMA_axi_any_error(CELENO_IDMA_CHANNEL channel)
{ return emc_slice32(emc_std_uint8_t, 4, 2, reg_base[15 + channel * 4]); }

static inline emc_std_bool CELENO_IDMA_axi_rx_error(CELENO_IDMA_CHANNEL channel)
{ return emc_test_bit32(reg_base[15 + channel * 4], 2); }

static inline emc_std_bool CELENO_IDMA_axi_tx_error(CELENO_IDMA_CHANNEL channel)
{ return emc_test_bit32(reg_base[15 + channel * 4], 3); }

#endif /* EMC_VENDOR_CELENO_DEVICE_IdmaReg_H */

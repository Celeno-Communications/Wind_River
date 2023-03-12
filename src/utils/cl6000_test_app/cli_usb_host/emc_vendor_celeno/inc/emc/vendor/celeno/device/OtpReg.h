/**
 * @file
 * @brief The OTP register access API
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_VENDOR_CELENO_DEVICE_OtpReg_H
#define EMC_VENDOR_CELENO_DEVICE_OtpReg_H

#include "emc/vendor/celeno/configure.h"
#include "emc/std/stdint.h"
#include "emc/std/stdbool.h"
#include "emc/std/ext/bitoperation.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/** Number of registers */
#define EMC_CELENO_OTP_REG_SPACE 9

/** Number of 32 bit values */
#define EMC_USB_CELENO_OTP_MEM_SPACE 256

/** base address */
#define EMC_CELENO_OTP_BASE 0x607C9000

/**
 * Initialize the register
 */
void EMC_CELENO_OTP_init_reg();

/**
 * Read a register value.
 * @param offset is the byte-offset from the register base.
 * @return the value of the register.
 */
emc_std_uint32_t EMC_CELENO_OTP_read_reg(emc_std_uint32_t offset);

/**
 * Write a register value.
 * @param offset is the byte-offset from the register base.
 * @param value is the value to be written.
 */
void EMC_CELENO_OTP_write_reg(emc_std_uint32_t offset, emc_std_uint32_t value);

#define EMC_USB_CELENO_OTP_OFFS_CMD 0x00       /**< command */
#define EMC_USB_CELENO_OTP_OFFS_STAT 0x04      /**< status */
#define EMC_USB_CELENO_OTP_OFFS_READ_VAL 0x08  /**< read value */
#define EMC_USB_CELENO_OTP_OFFS_ADDR 0x0C      /**< address index */
#define EMC_USB_CELENO_OTP_OFFS_WRITE_VAL 0x10 /**< write value */
#define EMC_USB_CELENO_OTP_OFFS_KEY 0x14       /**< key register */
#define EMC_USB_CELENO_OTP_OFFS_CLK_DIV 0x18   /**< clock divider */

#define EMC_USB_CELENO_OTP_KEY1 0xA6EE17BF /**< key 1 */
#define EMC_USB_CELENO_OTP_KEY2 0x827532CD /**< key 2 */

/** commands supported by the controller, auto cleared by hardware */
typedef enum EMC_USB_CELENO_OTP_cmd {
  EMC_USB_CELENO_OTP_CMD_NO_OPERATION = 0, /**< no operation */
  EMC_USB_CELENO_OTP_CMD_WRITE        = 1, /**< write operatio */
  EMC_USB_CELENO_OTP_CMD_READ         = 2  /**< read operation */
} EMC_USB_CELENO_OTP_cmd;

static inline void EMC_USB_CELENO_OTP_set_command(EMC_USB_CELENO_OTP_cmd cmd)
{ EMC_CELENO_OTP_write_reg(EMC_USB_CELENO_OTP_OFFS_CMD, cmd & 0x3); }

static inline emc_std_bool EMC_USB_CELENO_OTP_write_error()
{ return emc_test_bit32(EMC_CELENO_OTP_read_reg(EMC_USB_CELENO_OTP_OFFS_STAT), 0); }

static inline emc_std_bool EMC_USB_CELENO_OTP_ready()
{ return emc_test_bit32(EMC_CELENO_OTP_read_reg(EMC_USB_CELENO_OTP_OFFS_STAT), 1); }

static inline emc_std_bool EMC_USB_CELENO_OTP_read_error()
{ return emc_test_bit32(EMC_CELENO_OTP_read_reg(EMC_USB_CELENO_OTP_OFFS_STAT), 3); }

static inline emc_std_uint32_t EMC_USB_CELENO_OTP_read_value()
{ return EMC_CELENO_OTP_read_reg(EMC_USB_CELENO_OTP_OFFS_READ_VAL); }

static inline void EMC_USB_CELENO_OTP_set_address(emc_std_uint8_t address)
{ EMC_CELENO_OTP_write_reg(EMC_USB_CELENO_OTP_OFFS_ADDR, address); }

static inline void EMC_USB_CELENO_OTP_write_val(emc_std_uint32_t value)
{ EMC_CELENO_OTP_write_reg(EMC_USB_CELENO_OTP_OFFS_WRITE_VAL, value); }

static inline void EMC_USB_CELENO_OTP_enable_write(emc_std_bool enable)
{
  if (enable) {
    EMC_CELENO_OTP_write_reg(EMC_USB_CELENO_OTP_OFFS_KEY, 0xA6EE17BF);
    EMC_CELENO_OTP_write_reg(EMC_USB_CELENO_OTP_OFFS_KEY, 0x827532CD);
  } else {
    EMC_CELENO_OTP_write_reg(EMC_USB_CELENO_OTP_OFFS_KEY, 0);
  }
}

static inline void EMC_USB_CELENO_OTP_clock_divider(emc_std_uint8_t divider)
{ EMC_CELENO_OTP_write_reg(EMC_USB_CELENO_OTP_OFFS_CLK_DIV, divider); }

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_VENDOR_CELENO_DEVICE_OtpReg_H */

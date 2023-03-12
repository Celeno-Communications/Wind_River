/**
 *
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/

#include "emc/vendor/celeno/device/OtpReg.h"
#include "emc/std/assert.h"
#include "emc/std/string.h"

uint32_t unique_id32_0 = 0x78563412;
uint32_t unique_id32_1 = 0xF1DEBC9A;

static emc_std_uint32_t _mem[EMC_USB_CELENO_OTP_MEM_SPACE];
static emc_std_uint32_t _reg[EMC_CELENO_OTP_REG_SPACE];

enum KeyState {
  CLOSED,
  HALF,
  OPEN
} _key_state;

void EMC_CELENO_OTP_init_reg()
{
  emc_std_memset(_mem, 0, sizeof(_mem));
  emc_std_memset(_reg, 0, sizeof(_reg));
  _reg[EMC_USB_CELENO_OTP_OFFS_STAT / 4] = 2;    // ready
  _reg[EMC_USB_CELENO_OTP_OFFS_CLK_DIV / 4] = 8; // clock divider
  _mem[0xBE] = unique_id32_0;                    // default serial number
  _mem[0xBF] = unique_id32_1;
  _key_state = CLOSED;
}

emc_std_uint32_t EMC_CELENO_OTP_read_reg(emc_std_uint32_t offset)
{
  emc_std_uint32_t index = offset / 4;
  emc_std_assert(index < EMC_CELENO_OTP_REG_SPACE);
  return _reg[index];
}

void EMC_CELENO_OTP_write_reg(emc_std_uint32_t offset, emc_std_uint32_t value)
{
  emc_std_uint32_t index = offset / 4;
  emc_std_assert(index < EMC_CELENO_OTP_REG_SPACE);
  _reg[index] = value;
  // hardware logic
  switch (offset) {
  case EMC_USB_CELENO_OTP_OFFS_CMD:
    emc_std_assert(_reg[EMC_USB_CELENO_OTP_OFFS_ADDR / 4] < EMC_USB_CELENO_OTP_MEM_SPACE);
    _reg[EMC_USB_CELENO_OTP_OFFS_STAT / 4] = 2;
    if (value == EMC_USB_CELENO_OTP_CMD_WRITE) {
      if (_key_state == OPEN) {
        if ((_mem[_reg[EMC_USB_CELENO_OTP_OFFS_ADDR / 4]] | _reg[EMC_USB_CELENO_OTP_OFFS_WRITE_VAL / 4]) !=
            _reg[EMC_USB_CELENO_OTP_OFFS_WRITE_VAL / 4])
        {
          _reg[EMC_USB_CELENO_OTP_OFFS_STAT / 4] |= 1;
        }
        _mem[_reg[EMC_USB_CELENO_OTP_OFFS_ADDR / 4]] = _reg[EMC_USB_CELENO_OTP_OFFS_WRITE_VAL / 4];
      }
    }
    if (value == EMC_USB_CELENO_OTP_CMD_READ) {
      _reg[EMC_USB_CELENO_OTP_OFFS_READ_VAL / 4] = _mem[_reg[EMC_USB_CELENO_OTP_OFFS_ADDR / 4]];
    }
    break;

  case EMC_USB_CELENO_OTP_OFFS_KEY:
    if ((_key_state == CLOSED) && (value == EMC_USB_CELENO_OTP_KEY1)) {
      _key_state = HALF;
    } else if ((_key_state == HALF) && (value == EMC_USB_CELENO_OTP_KEY2)) {
      _key_state = OPEN;
    } else {
      _key_state = CLOSED;
    }
    break;

  default:
    break;
  }
}

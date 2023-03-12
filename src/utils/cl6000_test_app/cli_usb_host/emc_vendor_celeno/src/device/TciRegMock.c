/**
 *
 * Copyright (C) 2022 emsys Embedded Systems GmbH
 ****************************************************************************/
#include "emc/vendor/celeno/device/TciReg.h"
#include "emc/std/string.h"
#include "emc/std/assert.h"

static emc_std_uint32_t  _reg[0xA8 / sizeof(emc_std_uint32_t)];
static emc_std_uint32_t* mg_reg = 0;
static emc_std_uint32_t  _status_read_counter = 0;

struct _q {
  emc_std_uint32_t val[32];
  emc_std_uint32_t wr;
  emc_std_uint32_t rd;
};

static struct _q _q_start_address;
static struct _q _q_start_address_2;
static struct _q _q_first_part_len;
static struct _q _q_total_len;
static struct _q _q_nonstandard;

static void init_q(struct _q* self)
{
  emc_std_memset(self->val, 0x0, sizeof(*self->val));
  self->wr = 0;
  self->rd = 0;
}

void EMC_CELENO_TCI_init_reg(void)
{
  emc_std_memset(_reg, 0x0, sizeof(_reg));
  mg_reg = _reg;

  init_q(&_q_start_address);
  init_q(&_q_start_address_2);
  init_q(&_q_first_part_len);
  init_q(&_q_total_len);
  init_q(&_q_nonstandard);
}

static emc_std_uint32_t read_q(struct _q* self)
{
  emc_std_uint32_t value = self->val[self->rd];
  ++self->rd;
  self->rd %= sizeof(self->val) / sizeof(self->val[0]);

  return value;
}

static void write_q(struct _q* self, emc_std_uint32_t value)
{
  self->val[self->wr] = value;
  ++self->wr;
  self->wr %= sizeof(self->val) / sizeof(self->val[0]);
}

emc_std_uint32_t EMC_CELENO_TCI_read_reg(emc_std_uint32_t offset)
{
  emc_std_uint32_t idx = offset / sizeof(emc_std_uint32_t);
  emc_std_uint32_t value;

  emc_std_assert(0 == offset % sizeof(emc_std_uint32_t));
  emc_std_assert(idx < (sizeof(_reg) / sizeof(_reg[0])));
  emc_std_assert(0 != mg_reg);

  switch (offset) {
  case 0x08: value = read_q(&_q_start_address); break;
  case 0x0C: value = read_q(&_q_start_address_2); break;
  case 0x10: value = read_q(&_q_first_part_len); break;
  case 0x14: value = read_q(&_q_total_len); break;
  case 0x18: value = read_q(&_q_nonstandard); break;

  case 0x1C:
    ++_status_read_counter;
    if (0 == (_status_read_counter % 4)) {
      value = 0xFFFFFFFF;
    } else {
      value = 0;
    }
    break;

  default: value = mg_reg[idx]; break;
  }

  return value;
}

void EMC_CELENO_TCI_write_reg(emc_std_uint32_t offset, emc_std_uint32_t value)
{
  emc_std_uint32_t idx = offset / sizeof(emc_std_uint32_t);

  emc_std_assert(0 == offset % sizeof(emc_std_uint32_t));
  emc_std_assert(idx < (sizeof(_reg) / sizeof(_reg[0])));
  emc_std_assert(0 != mg_reg);

  switch (offset) {
  case 0x08:
    write_q(&_q_start_address, value);
    emc_std_assert(_q_start_address.wr == _q_total_len.wr);
    break;

  case 0x0C: write_q(&_q_start_address_2, value); break;
  case 0x10: write_q(&_q_first_part_len, value); break;
  case 0x14: write_q(&_q_total_len, value); break;
  case 0x18: write_q(&_q_nonstandard, value); break;

  default: mg_reg[idx] = value; break;
  }
}

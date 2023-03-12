/**
 * @file
 * @brief   CLI implementation
 * @author  <guenter.hildebrandte@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#include "emc/system/celeno/host/cli/cli.h"
#include "emc/system/celeno/host/cli/cli_usb.h"

#include <stdio.h>
#include <errno.h>

static void set_errno(int status)
{
  if (errno == 0) {
    errno = status;
  }
}

static void check_status(const char* message, int status)
{
  if (errno == EAGAIN) {
    errno = 0;
  }
  if (status < 0) {
    set_errno(status);
    fprintf(stderr, "Error: %s: %d\n", message, errno);
  }
}

uint32_t cl_reg_read32(uint32_t offset)
{
  uint32_t data = 0;
  int      status = cl_usb_read32(offset, &data);

  check_status("cl_usb_read32", status);
  if (status != 0) {
    data = 0;
  }
  return data;
}

void cl_reg_write32(uint32_t offset, uint32_t value)
{
  int status = cl_usb_write32(offset, value);
  check_status("cli_usb_write32", status);
}

uint32_t cl_reg_get_bit(uint32_t reg, uint32_t bit_mask)
{
  uint32_t regval = cl_reg_read32(reg);
  return (regval & bit_mask) != 0;
}

void cl_reg_write32_mask(uint32_t offset, uint32_t value, uint32_t mask)
{
  int status = cl_usb_write32_mask(offset, value, mask);
  check_status("cl_usb_write32_mask", status);
}

void cl_reg_set_bit(uint32_t reg, uint32_t bit_mask)
{
  cl_reg_write32_mask(reg, bit_mask, bit_mask);
}

void cl_reg_clear_bit(uint32_t reg, uint32_t bit_mask)
{
  cl_reg_write32_mask(reg, 0, bit_mask);
}

uint32_t cl_reg_get_field(uint32_t reg, uint32_t mask, uint32_t lsb)
{
  uint32_t regval = cl_reg_read32(reg);
  return (regval & mask) >> lsb;
}

void cl_reg_set_field(uint32_t reg, uint32_t mask, uint32_t lsb, uint32_t val)
{
  cl_reg_write32_mask(reg, val << lsb, mask);
}

/* Copyright (C) 2016 emsys Embedded Systems GmbH */

#include "emc/std/stdlib.h"
#include "emc/std/ext/stdlib.h"
#include "emc/std/stdint.h"
#include "emc/std/assert.h"
#include "emc/std/ext/ct_assert.h"

static void make_string(char* p, emc_std_uint32_t value, emc_std_uint32_t base)
{
  emc_std_uint32_t remainder;
  char             fraction;

  // move p to string position of base^0
  remainder = value;
  do {
    p++;
    remainder = remainder / base;
  } while (remainder);

  *p-- = '\0';

  // insert characters for base^n positions to string for n starting at 0
  remainder = value;
  do {
    fraction = (char)(remainder % base);
    *p-- = fraction < 10 ? (char)('0' + fraction)
           : (char)('A' + (fraction - 0xA));
    remainder = remainder / base;
  } while (remainder);
}

static void make_string_64(char* p, emc_std_uint64_t value, emc_std_uint32_t base)
{
  emc_std_uint64_t remainder;
  char             fraction;

  // move p to string position of base^0
  remainder = value;
  do {
    p++;
    remainder = remainder / base;
  } while (remainder);

  *p-- = '\0';

  // insert characters for base^n positions to string for n starting at 0
  remainder = value;
  do {
    fraction = (char)(remainder % base);
    *p-- = fraction < 10 ? (char)('0' + fraction)
           : (char)('A' + (fraction - 0xA));
    remainder = remainder / base;
  } while (remainder);
}

char* emc_std_itoa(int value, char* str, int base)
{
  char* p = str;

  if ((base < 2) || (base > 36)) {
    *p = '\0';
    return str;
  }

  if ((value < 0) && (base == 10)) {
    // minus sign only for base=10, otherwise handle as unsigned
    *p++ = '-';
    value = -value;
  }

  make_string(p, (emc_std_uint32_t)value, (emc_std_uint32_t)base);
  return str;
}

char* emc_std_litoa(long value, char* str, int base)
{
  char* p = str;

  if ((base < 2) || (base > 36)) {
    *p = '\0';
    return str;
  }

  if ((value < 0) && (base == 10)) {
    // minus sign only for base=10, otherwise handle as unsigned
    *p++ = '-';
    value = -value;
  }

  make_string_64(p, (emc_std_uint64_t)(emc_std_int64_t)value, (emc_std_uint32_t)base);
  return str;
}

char* emc_std_utoa(unsigned int value, char* str, int base)
{
  if ((base < 2) || (base > 36)) {
    *str = '\0';
    return str;
  }

  if (sizeof(unsigned long) == 4) { //lint !e506
    make_string(str, value, (emc_std_uint32_t)base);
  } else {
    make_string_64(str, (emc_std_uint64_t)value, (emc_std_uint32_t)base);
  }
  EMC_CT_ASSERT((sizeof(unsigned long) == 4) || (sizeof(unsigned long) == 8));
  return str;
}

char* emc_std_lutoa(unsigned long value, char* str, int base)
{
  if ((base < 2) || (base > 36)) {
    *str = '\0';
    return str;
  }
  if (sizeof(unsigned long) == 4) { //lint !e506
    make_string(str, (emc_std_uint32_t)value, (emc_std_uint32_t)base);
  } else {
    make_string_64(str, (emc_std_uint64_t)value, (emc_std_uint32_t)base);
  }
  EMC_CT_ASSERT((sizeof(unsigned long) == 4) || (sizeof(unsigned long) == 8));
  return str;
}

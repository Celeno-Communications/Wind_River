/* Copyright (C) 2014-2015 emsys Embedded Systems GmbH */

#include "emc/std/ext/ErrorCategory.h"

const EMC_ErrorCategory* emc_system_category(void)
{
  static EMC_ErrorCategory result;
  result.name = "emc stdemu errno";
  return &result;
}

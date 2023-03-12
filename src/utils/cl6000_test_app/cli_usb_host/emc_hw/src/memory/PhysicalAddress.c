/* Copyright (C) 2013, 2020 emsys Embedded Systems GmbH */

#include "emc/hw/memory/PhysicalAddress.h"

int EMC_PhysicalAddress_is_supported(void)
{
  return 1;
}

struct EMC_PhysicalAddress EMC_PhysicalAddress_new(void* address)
{
  struct EMC_PhysicalAddress physical_address;
  physical_address.handle = (emc_std_uintptr_t)address;
  return physical_address;
}

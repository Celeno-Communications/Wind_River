/* Copyright (C) 2013, 2020 emsys Embedded Systems GmbH */

#include "emc/hw/memory/private/ConstMemory.h"
#include "emc/hw/memory/private/Memory.h"
#include "emc/hw/memory/PhysicalAddress.h"

#include "emc/std/assert.h"
#include "emc/std/stdatomic.h"
#include "emc/std/string.h"
#include "emc/std/stdlib.h"
#include "emc/std/stdint.h"

static char* get_virtual_address(struct EMC_Memory this)
{
  ConstMemory* const_memory = (ConstMemory*)this.handle;
  return (char*)const_memory->logical_address;
}

static struct EMC_PhysicalAddress get_physical_address(struct EMC_Memory this)
{
  ConstMemory* const_memory = (ConstMemory*)this.handle;
  return const_memory->physical_address;
}

static void read_memory(struct EMC_Memory this, emc_std_size_t offset, void* buffer, emc_std_size_t size)
{
  emc_std_memcpy(buffer, get_virtual_address(this) + offset, size);
}

static void write_memory(struct EMC_Memory this, emc_std_size_t offset, const void* buffer, emc_std_size_t size)
{
  UNUSED_PARAM(this);
  UNUSED_PARAM(offset);
  UNUSED_PARAM(buffer);
  UNUSED_PARAM(size);
}

static void free_memory(struct EMC_Memory this, emc_std_size_t size_for_debugging)
{
  UNUSED_PARAM(this);
  UNUSED_PARAM(size_for_debugging);
}

struct EMC_Memory* EMC_ConstMemory_initialize(struct ConstMemory* const_memory,
                                              const emc_std_uintptr_t logical_address,
                                              const emc_std_uintptr_t physical_address,
                                              emc_std_size_t size)
{
  /*lint --e{546} suspicious & */
  const_memory->mem_vtable.address = &get_virtual_address;
  const_memory->mem_vtable.physical_address = &get_physical_address;
  const_memory->mem_vtable.read = &read_memory;
  const_memory->mem_vtable.write = &write_memory;
  const_memory->mem_vtable.free = &free_memory;
  const_memory->base.vtable = &const_memory->mem_vtable;

  const_memory->base.handle = (emc_std_uintptr_t)const_memory;

  const_memory->logical_address = logical_address;
  const_memory->physical_address.handle = (emc_std_uintptr_t)physical_address;
  const_memory->size = size;
  const_memory->in_use = emc_std_false;

  return &const_memory->base;
}

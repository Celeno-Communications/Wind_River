/* Copyright (C) 2013, 2020 emsys Embedded Systems GmbH */

#include "emc/hw/memory/private/Memory.h"
#include "emc/std/assert.h"

void EMC_Memory_free(EMC_Memory* memory, size_t size_for_debugging)
{
  if (!memory) {
    return;
  }
  if (!memory->handle) {
    return;
  }
  (*(memory->vtable->free))(*memory, size_for_debugging);
  memory->handle = 0;
  memory->vtable = 0;
}

void EMC_Memory_read(EMC_Memory memory,
                     size_t offset,
                     void* buffer,
                     size_t buffer_size)
{
  (*memory.vtable->read)(memory, offset, buffer, buffer_size);
}

void EMC_Memory_write(EMC_Memory memory,
                      size_t offset,
                      const void* buffer,
                      size_t buffer_size)
{
  (*memory.vtable->write)(memory, offset, buffer, buffer_size);
}

void* EMC_Memory_address(EMC_Memory memory)
{
  return (*memory.vtable->address)(memory);
}

struct EMC_PhysicalAddress EMC_Memory_physical_address(EMC_Memory memory)
{
  return (*memory.vtable->physical_address)(memory);
}

/**
 * @file
 * @brief   Malloc emulation based on GKI memory allocation functions.
 * @author  Stefan Schulze<stefan.schulze@emsys.de>
 * Copyright (C) 2007-2013 emsys Embedded Systems GmbH
 */

#include <emc/std/emu/gki/malloc.h>
#include <emc/std/assert.h>

#include <kernel.h>

void* emc_std_malloc(size_t size)
{
  void* ptr = 0;
  KiAllocMemory(size, &ptr);
  emc_std_assert(ptr);
  return ptr;
}

void emc_std_free(void* pointer)
{
  if (pointer) {
    KiFreeMemory(&pointer);
  }
}

void* emc_std_realloc(void* pointer, size_t size)
{
  emc_std_assert(size <= 0xffff);
  KiReallocMemory((Int16)size, &pointer);
  return pointer;
}

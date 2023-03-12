/* Copyright (C) 2013, 2020 emsys Embedded Systems GmbH */

#ifndef EMC_HW_MEMORY_PRIVATE_StaticPortMemoryTemplate_H
#define EMC_HW_MEMORY_PRIVATE_StaticPortMemoryTemplate_H

#include "emc/hw/memory/private/Memory.h"

#include "emc/std/assert.h"
#include "emc/std/stddef.h"
#include "emc/std/stdint.h"
#include "emc/std/string.h"
#include "emc/config/version.h"
#include "emc/std/ext/align.h"

#if !defined EMC_PORT_POOL_NAME || \
  !defined EMC_PORT_POOL_ALIGNMENT || \
  !defined EMC_PORT_POOL_CHUNK_SIZE || \
  !defined EMC_PORT_POOL_NB_CHUNKS
#  error Parameters are missing.
#endif

#define EMC_STATICPORTMEMORY_ALLOCATE(name) \
  EMC_NAME3(EMC_StaticPort, name, Memory_allocate)

EMC_EXTERN_C_BEGIN;

static emc_std_uint8_t mg_is_used[EMC_MEMORY_POOL_TYPE_STATIC_INSTANCES]
[EMC_PORT_POOL_NB_CHUNKS];

#if defined(__arm)
#  pragma arm section zidata="USB_HAL_BUFFERS"
#endif
/*lint -esym(551,mg_buffer)*/
#if defined(__x86) && !defined(LINT)
static EMC_STD_EXT_ALIGNAS(EMC_PORT_POOL_ALIGNMENT)
char mg_buffer[EMC_MEMORY_POOL_TYPE_STATIC_INSTANCES]
[EMC_PORT_POOL_NB_CHUNKS]
[EMC_PORT_POOL_CHUNK_SIZE] __attribute__((section("USB_HAL_BUFFERS")));
#else
static EMC_STD_EXT_ALIGNAS(EMC_PORT_POOL_ALIGNMENT)
char mg_buffer[EMC_MEMORY_POOL_TYPE_STATIC_INSTANCES]
[EMC_PORT_POOL_NB_CHUNKS]
[EMC_PORT_POOL_CHUNK_SIZE];
#endif

#if defined(__arm)
#  pragma arm section zidata
#endif

static char* memory_address(struct EMC_Memory self)
{
  emc_std_assert(sizeof(emc_std_uintptr_t) <= sizeof(self.handle));
  return (char*)(emc_std_uintptr_t)self.handle;
}

static void memory_free(struct EMC_Memory self, emc_std_size_t size_for_debugging)
{

  char*          ptr = memory_address(self);
  emc_std_size_t instance;
  emc_std_size_t chunk;
  emc_std_assert(ptr >= mg_buffer[0][0]);
  instance = ((emc_std_uintptr_t)(ptr - mg_buffer[0][0])) / sizeof(mg_buffer[0]);
  emc_std_assert(ptr >= mg_buffer[instance][0]);
  chunk = ((emc_std_uintptr_t)(ptr - mg_buffer[instance][0])) / sizeof(mg_buffer[0][0]);
  emc_std_assert(instance < EMC_MEMORY_POOL_TYPE_STATIC_INSTANCES);
  emc_std_assert(chunk < EMC_PORT_POOL_NB_CHUNKS);
  emc_std_assert(ptr + size_for_debugging <= &mg_buffer[instance][chunk + 1][0]);
  emc_std_assert(mg_is_used[instance][chunk]);
  mg_is_used[instance][chunk] = 0;

  UNUSED_PARAM(size_for_debugging);
}

static void memory_read(struct EMC_Memory self,
                        emc_std_size_t offset,
                        void* buffer,
                        emc_std_size_t buffer_size)
{
  emc_std_assert(offset + buffer_size <= EMC_PORT_POOL_CHUNK_SIZE);
  emc_std_memcpy(buffer, memory_address(self) + offset, buffer_size);
}

static void memory_write(struct EMC_Memory self,
                         emc_std_size_t offset,
                         const void* buffer,
                         emc_std_size_t buffer_size)
{
  emc_std_assert(offset + buffer_size <= EMC_PORT_POOL_CHUNK_SIZE);
  emc_std_memcpy(memory_address(self) + offset, buffer, buffer_size);
}

static struct EMC_PhysicalAddress memory_physical(struct EMC_Memory self)
{
  return EMC_PhysicalAddress_new(memory_address(self));
}

static const struct EMC_MemoryFunctionTable memory_vtable = {
  memory_address, memory_free, memory_read, memory_write, memory_physical
};

struct EMC_Memory EMC_STATICPORTMEMORY_ALLOCATE(EMC_PORT_POOL_NAME)(emc_std_ptrdiff_t instance) {
  struct EMC_Memory result = { &memory_vtable, 0U };

  int chunk = 0;
  for (chunk = 0; chunk < EMC_PORT_POOL_NB_CHUNKS; ++chunk) {
    if (!mg_is_used[instance][chunk]) {
      mg_is_used[instance][chunk] = 1;
      result.handle = (emc_std_uintptr_t)mg_buffer[instance][chunk];
      break;
    }
  }
  emc_std_assert(result.handle);
  return result;
}

EMC_EXTERN_C_END;

#endif /* EMC_HW_MEMORY_PRIVATE_StaticPortMemoryTemplate_H */

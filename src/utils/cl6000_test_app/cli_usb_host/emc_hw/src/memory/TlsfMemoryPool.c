/* Copyright (C) 2013, 2020 emsys Embedded Systems GmbH */

#include "emc/hw/memory/UncachedMemoryPool.h"
#include "emc/hw/memory/private/MemoryPool.h"
#include "emc/hw/memory/private/Memory.h"
#include "emc/std/stdint.h"
#include "emc/std/string.h"
#include "external/baisoku/tlsf.h"

/* implementation details:
 * The allocated memory structure EMC_Memory will hold a pointer to the EMC_MemoryFunctionTable
 * as vtable.
 * As long as this vtable is physically embedded in the specific Pool data structure, it's possible,
 * to conclude from the address to the EMC_MemoryFunctionTable (memory.vtable)
 * on the address of the pool itself.
 * This is used in free_memory() below.
 * This technique requires copies of vtables per EMC_MemoryPool, but reduces the
 * physical size of EMC_Memory.
 */
struct Pool {
  struct EMC_MemoryPool              memory_pool;
  struct EMC_MemoryPoolFunctionTable pool_vtable;
  struct EMC_MemoryFunctionTable     mem_vtable;
  tlsf_pool                          handle;
};

static void allocate_aligned_memory(struct EMC_MemoryPool* pool,
                                    emc_std_size_t size,
                                    emc_std_size_t align,
                                    struct EMC_Memory* out_memory)
{
  struct Pool* this = (struct Pool*)pool;
  out_memory->vtable = &this->mem_vtable;
  out_memory->handle = (emc_std_uintptr_t)tlsf_memalign(this->handle, align, size);
}

static void destroy_pool(struct EMC_MemoryPool* pool)
{
  ((struct Pool*)pool)->handle = 0;
}

static char* get_virtual_address(struct EMC_Memory this)
{
  return (char*)this.handle;
}

static struct EMC_PhysicalAddress get_physical_address(struct EMC_Memory this)
{
  return EMC_PhysicalAddress_new(get_virtual_address(this));
}

static void read_memory(struct EMC_Memory this, emc_std_size_t offset, void* buffer, emc_std_size_t size)
{
  emc_std_memcpy(buffer, get_virtual_address(this) + offset, size);
}

static void write_memory(struct EMC_Memory this, emc_std_size_t offset, const void* buffer, emc_std_size_t size)
{
  emc_std_memcpy(get_virtual_address(this) + offset, buffer, size);
}

static void free_memory(struct EMC_Memory this, emc_std_size_t size_for_debugging)
{
  struct Pool* pool = (struct Pool*)(((char*)this.vtable) - emc_std_offsetof(struct Pool, mem_vtable));
  tlsf_free(pool->handle, (void*)this.handle);
  UNUSED_PARAM(size_for_debugging);
}

static struct EMC_MemoryPool* initialize(struct Pool* this, tlsf_pool handle)
{
  /*lint --e{546} suspicious & */
  this->memory_pool.vtable = &this->pool_vtable;
  this->pool_vtable.allocate_aligned = &allocate_aligned_memory;
  this->pool_vtable.delete_pool = &destroy_pool;
  this->pool_vtable.destroy_pool = &destroy_pool;
  this->mem_vtable.address = &get_virtual_address;
  this->mem_vtable.physical_address = &get_physical_address;
  this->mem_vtable.read = &read_memory;
  this->mem_vtable.write = &write_memory;
  this->mem_vtable.free = &free_memory;
  this->handle = handle;
  return this->handle ? &this->memory_pool : 0;
}

struct EMC_MemoryPool* EMC_MemoryPool_new(void* begin, emc_std_size_t size)
{
  if (size > sizeof(struct Pool) + tlsf_pool_size() /* ~ overhead */) {
    struct Pool* this = (struct Pool*)begin;
    return initialize(this, tlsf_create(this + 1, size - sizeof(struct Pool)));
  }
  return 0;
}

struct EMC_MemoryPool* EMC_UncachedMemoryPool_new(void* cached,
                                                  emc_std_size_t cached_size,
                                                  void* uncached,
                                                  emc_std_size_t uncached_size)
{
  /*lint --e{546} suspicious & */
  if (cached_size > sizeof(struct Pool) + tlsf_pool_size() /* ~ overhead */) {
    struct Pool*   this = (struct Pool*)cached;
    emc_std_size_t remaining_cached_size = cached_size - sizeof(struct Pool);
    return initialize(this, tlsf_initialize(this + 1, remaining_cached_size,
                                            uncached, uncached_size));
  }
  return 0;
}

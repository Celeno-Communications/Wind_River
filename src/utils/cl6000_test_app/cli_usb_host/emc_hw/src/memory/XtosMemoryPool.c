/* Copyright (C) 2017, 2020 emsys Embedded Systems GmbH */

#include "emc/hw/memory/UncachedMemoryPool.h"
#include "emc/hw/memory/private/MemoryPool.h"
#include "emc/hw/memory/private/Memory.h"

#include "emc/std/emu/xtos/wrapper.h"
#include "emc/std/stdint.h"
#include "emc/std/string.h"

struct Pool {
  struct EMC_MemoryPool              memory_pool;
  struct EMC_MemoryPoolFunctionTable pool_vtable;
  struct EMC_MemoryFunctionTable     mem_vtable;
  /* base address for slab allocator */
  struct sue_allocator_pool_s sue_pool;
};

static void allocate_aligned_memory(struct EMC_MemoryPool* pool,
                                    emc_std_size_t size,
                                    emc_std_size_t align,
                                    struct EMC_Memory* out_memory)
{
  struct Pool* this = (struct Pool*)pool;
  out_memory->vtable = &this->mem_vtable;
  out_memory->handle = (emc_std_uintptr_t)sue_alloc_aligned(&this->sue_pool, align, size);
}

static void destroy_pool(struct EMC_MemoryPool* pool)
{
  struct sue_allocator_pool_s* sue_pool = &((struct Pool*)pool)->sue_pool;
  sue_pool->base = 0;
  sue_pool->end = 0;
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
  sue_free_aligned(&pool->sue_pool, (void*)(this.handle));
  UNUSED_PARAM(size_for_debugging);
}

static struct EMC_MemoryPool* initialize(struct Pool* this, struct sue_allocator_pool_s handle)
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
  this->sue_pool = handle;
  return this->sue_pool.base ? &this->memory_pool : 0;
}

struct EMC_MemoryPool* EMC_MemoryPool_new(void* begin, emc_std_size_t size)
{
  if (size > sizeof(struct Pool) /* ~ overhead */) {
    struct Pool* this = (struct Pool*)begin;
    sue_create_pool(&this->sue_pool, this + 1, size - sizeof(struct Pool));
    sue_init(&this->sue_pool);
    return initialize(this, this->sue_pool);
  }
  return 0;
}

struct EMC_MemoryPool* EMC_UncachedMemoryPool_new(void* cached,
                                                  emc_std_size_t cached_size,
                                                  void* uncached,
                                                  emc_std_size_t uncached_size)
{
  /* this allocator does not separate management structures from other data
   * therefore we can not optimize access times for management structures
   * by allowing them to be cached
   */

  UNUSED_PARAM(cached);
  UNUSED_PARAM(cached_size);
  return EMC_MemoryPool_new(uncached, uncached_size);
}

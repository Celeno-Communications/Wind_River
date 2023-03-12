/* Copyright (C) 2017 emsys Embedded Systems GmbH */
#include "emc/std/emu/xtos/wrapper.h"

#include "external/sue/sue_allocate.h"
#include "emc/std/assert.h"

void sue_create_pool(struct sue_allocator_pool_s* pool, void* ptr, emc_std_size_t size)
{
  pool->base = ptr;
  pool->end = (((emc_std_uint8_t*)ptr) + size);
}

void sue_init(struct sue_allocator_pool_s* pool)
{
  Usb_InitMemManagement(pool);
}

void* sue_alloc(struct sue_allocator_pool_s* pool, emc_std_size_t size)
{
  return Usb_Alloc(pool, size);
}

void* sue_alloc_aligned(struct sue_allocator_pool_s* pool,
                        emc_std_size_t alignment,
                        emc_std_size_t size)
{
  emc_std_size_t aligned_ptr = 0;
  void*          ptr = EMC_STD_NULL;
  void**         original_ptr_store = EMC_STD_NULL;

  /* alignment must be power of 2
   * we must be able to store the offset to real buffer (also aligned)
   * therefore alignment must be greater or equal size_t
   * */
  emc_std_assert((alignment >= sizeof(emc_std_size_t)) && !(alignment & (alignment - 1)));

  /* calculate block size to store alignment gap and contain an aligned address */
  size += sizeof(emc_std_size_t) + (2 * alignment) - 1;
  size &= ~(alignment - 1);

  /* get block where we can find an aligned address and store alignment value */
  ptr = sue_alloc(pool, size);

  if (ptr != EMC_STD_NULL) {
    /* reserve space for original pointer and make pointer to multiple of alignment */
    aligned_ptr = (emc_std_size_t)ptr + sizeof(emc_std_size_t) + alignment - 1;
    aligned_ptr &= ~(alignment - 1);

    /* using pointer arithmetic */
    original_ptr_store = ((void**)aligned_ptr) - 1;
    /* store pointer we can use directly for sue_free() */
    *original_ptr_store = ptr;

    ptr = (void*)aligned_ptr;
  }

  return ptr;
}

void sue_free_aligned(struct sue_allocator_pool_s* pool, void* ptr)
{
  void*  original_ptr = EMC_STD_NULL;
  void** original_ptr_store = EMC_STD_NULL;

  if (ptr != EMC_STD_NULL) {
    /* using pointer arithmetic */
    original_ptr_store = ((void**)ptr) - 1;
    /* get original pointer */
    original_ptr = *original_ptr_store;
    sue_free(pool, original_ptr);
  }
}

void sue_free(struct sue_allocator_pool_s* pool, void* ptr)
{
  Usb_Free(pool, ptr);
}

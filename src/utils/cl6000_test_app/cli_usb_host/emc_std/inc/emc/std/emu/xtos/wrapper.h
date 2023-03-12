#ifndef EMC_STD_EMU_XTOS_wrapper_H
#define EMC_STD_EMU_XTOS_wrapper_H

#include "emc/std/stdlib.h"

struct sue_allocator_pool_s {
  void* base; /* start address of the memory pool */
  void* end;  /* pointer to the first byte after the memory pool */
};

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

void sue_create_pool(struct sue_allocator_pool_s* pool, void* ptr, emc_std_size_t size);
void sue_init(struct sue_allocator_pool_s* pool);
void* sue_alloc(struct sue_allocator_pool_s* pool, emc_std_size_t size);
void* sue_alloc_aligned(struct sue_allocator_pool_s* pool,
                        emc_std_size_t alignment,
                        emc_std_size_t size);
void sue_free_aligned(struct sue_allocator_pool_s* pool, void* ptr);
void sue_free(struct sue_allocator_pool_s* pool, void* ptr);

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif

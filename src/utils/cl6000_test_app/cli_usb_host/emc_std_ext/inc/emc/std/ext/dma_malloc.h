/**
 * @file
 *
 * @brief   The DMA extenseions to malloc and free
 *
 *
 * @author  Karsten Pahnke <karsten.pahnke@emsys.de>
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2012 emsys Embedded Systems GmbH
 *
 ****************************************************************************/

#ifndef EMC_STD_EXT_dma_malloc_H
#define EMC_STD_EXT_dma_malloc_H

#include "emc/std/stddef.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/** allocates @p size bytes from a DMA capable pool of memory
 * @param size The size in bytes requested (should not be 0)
 * @return the pointer on the allocated memory
 * @retval 0 implies no DMA memory available
 */
void* emc_dma_malloc(size_t size);

/** returns the memory referenced by @p ptr to the DMA memory pool
 * @param ptr the pointer to a piece of memory allocated earlier from the dma memory pool,
 * which should be returned to the memory management
 */
void emc_dma_free(void* ptr);

/** Initialize the cache functions with the correct size of a @p cache_line_size
 */
void emc_set_dma_cache_line_size(emc_std_size_t cache_line_size);

/** Returns the previously  specified size of a cache line
 */
emc_std_size_t emc_dma_cache_line_size(void);

/** Provide dma capable memory buffer for emc_dma_malloc implementations, which handle partitioning itself
 *  @param buffer complete dma area
 *  @param buffer_size size of buffer
 */
void emc_std_dma_malloc_init(void* buffer, emc_std_size_t buffer_size);

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_STD_EXT_dma_malloc_H */

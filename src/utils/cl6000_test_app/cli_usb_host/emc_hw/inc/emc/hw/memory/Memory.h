/** @file
    @brief Memory.
    Copyright (C) 2013, 2020 emsys Embedded Systems GmbH */

#ifndef EMC_HW_MEMORY_Memory_H
#define EMC_HW_MEMORY_Memory_H

#include "emc/hw/configure.h"

#include "emc/hw/MemoryRange.h"
#include "emc/hw/memory/PhysicalAddress.h"

#include "emc/std/stddef.h"
#include "emc/std/stdbool.h"

EMC_EXTERN_C_BEGIN;

struct EMC_MemoryFunctionTable; /**< @private */

/** References one piece of memory from an opaque address space.
    It can be allocated from MemoryPools.
    It supports copying to and from a buffer.
    It knows how to deallocate itself. */
typedef struct EMC_Memory {
  const struct EMC_MemoryFunctionTable* vtable; /**< @private */
  emc_std_uintptr_t                     handle; /**< @private */
} EMC_Memory;

/* @param memory Pointer to the memory object.
 * @param size The size of memory block to be freed
 */

/** @memberof EMC_Memory
    @brief Free Memory */
void EMC_Memory_free(EMC_Memory* memory, emc_std_size_t size_for_debugging);

/* Read from memory
 *
 * @param memory The memory object.
 * @param offset The offset address for the read operation
 * @param buffer The user buffer to be written to memory
 * @param buffer_size The size of the user buffer to be written
 *
 *  @memberof EMC_HW_PortAccess
 */

/** @memberof EMC_Memory
    @brief Copy the memory content to the caller buffer */
void EMC_Memory_read(EMC_Memory memory,
                     emc_std_size_t offset,
                     void* buffer,
                     emc_std_size_t buffer_size);

/* Write to memory
 *
 * @param memory The memory object.
 * @param offset The offset address for the write operation
 * @param buffer The user buffer to be written to memory
 * @param buffer_size The size of the user buffer to be written
 *
 *  @memberof EMC_HW_PortAccess
 */

/** @memberof EMC_Memory
    @brief Write the caller's buffer to Memory */
void EMC_Memory_write(EMC_Memory memory,
                      emc_std_size_t offset,
                      const void* buffer,
                      emc_std_size_t buffer_size);

/* Get the physical address location for a memory object
 *
 * @param memory A handle to reference the memory object.
 *
 * @return The physical address location.
 *
 *  @memberof EMC_HW_PortAccess
 */

/** @memberof EMC_Memory
    @brief Return the corresponding virtual address if available, @c NULL otherwise. */
void* EMC_Memory_address(EMC_Memory memory);

/** @memberof EMC_Memory
    @brief Return the corresponding virtual address if available, @c NULL otherwise. */
static inline void* EMC_Memory_virtual_address(EMC_Memory memory)
{
  return EMC_Memory_address(memory);
}

/** @memberof EMC_Memory
    @brief Get a PhysicalAddress for a piece of Memory. */
struct EMC_PhysicalAddress EMC_Memory_physical_address(EMC_Memory memory);

/** @memberof EMC_Memory
    @brief Check if the specified memory is valid. Returns 0 if not valid, 1 otherwise. */
static inline emc_std_bool EMC_Memory_valid(EMC_Memory memory)
{
  return (0 != memory.vtable) && EMC_Memory_address(memory);
}

/** @memberof EMC_Memory
    @brief Initialize the memory object. */
static inline void EMC_Memory_initialize(EMC_Memory* self)
{
  self->vtable = 0;
  self->handle = 0;
}

EMC_EXTERN_C_END;

#endif /* EMC_HW_MEMORY_Memory_H */

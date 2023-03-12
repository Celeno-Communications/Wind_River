/** @file
    @brief ConstMemory.
    Copyright (C) 2013, 2020 emsys Embedded Systems GmbH */

#ifndef EMC_HW_MEMORY_PRIVATE_ConstMemory_H
#define EMC_HW_MEMORY_PRIVATE_ConstMemory_H

#include "emc/hw/memory/Memory.h"
#include "emc/hw/memory/private/Memory.h"
#include "emc/std/stdbool.h"
#include "emc/std/stddef.h"

EMC_EXTERN_C_BEGIN;

/** The read only memory
 */
typedef struct ConstMemory {
  struct EMC_Memory              base;             /**< The base type part*/
  struct EMC_MemoryFunctionTable mem_vtable;       /**< the virtual function table */
  emc_std_uintptr_t              logical_address;  /**< the logical address */
  struct EMC_PhysicalAddress     physical_address; /**< the physical address */
  emc_std_size_t                 size;             /**< the size in bytes */
  emc_std_bool                   in_use;           /**< the in use flag */
} ConstMemory;

/** Inplace Constructor.
 * Initializes a given ConstMemory element and returns a pointer of the abstract EMC_Memory
    @param const_memory The (externally created) ConstMemory structure
    @param logical_address The logical address of the ConstMemory element
    @param physical_address The physical address of the ConstMemory element
    @param size The size of the memory
    @return Pointer to the abstract EMC_Memory
    @memberof EMC_Memory */
struct EMC_Memory* EMC_ConstMemory_initialize(ConstMemory* const_memory,
                                              const emc_std_uintptr_t logical_address,
                                              const emc_std_uintptr_t physical_address,
                                              emc_std_size_t size);

EMC_EXTERN_C_END;

#endif /* EMC_HW_MEMORY_PRIVATE_ConstMemory_H */

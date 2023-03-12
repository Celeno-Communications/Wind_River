/** @file
    @brief PhysicalAddress.
    Copyright (C) 2013, 2020 emsys Embedded Systems GmbH */

#ifndef EMC_HW_MEMORY_PhysicalAddress_H
#define EMC_HW_MEMORY_PhysicalAddress_H

#include "emc/hw/configure.h"
#include "emc/std/stdint.h"

EMC_EXTERN_C_BEGIN;

/** The physical address type
 */
struct EMC_PhysicalAddress {
  /* No vtable. One kind of physical memory may be sufficient. */
  emc_std_uintptr_t handle; /**< @private */
};

/** @memberof EMC_PhysicalAddress
    @brief Return zero if other interfaces must be used instead. */
int EMC_PhysicalAddress_is_supported(void);

/*
 * @param memory_handle A handle to reference the  memory object.
 *
 * @return The virtual address location. If a non-zero pointer is returned, the content
 *         described by this pointer can be read/written directly. Otherwise
 *         the EMC_HW_Port_dma_write_impl and EMC_HW_Port_dma_read_impl
 *         must be used instead to read/write to the DMA memory. *
 */

/** @memberof EMC_PhysicalAddress
    @brief Return a locked physical address for the given virtual @c address */
struct EMC_PhysicalAddress EMC_PhysicalAddress_new(void* address);

/** @memberof EMC_PhysicalAddress
    @brief Return the low 32-bit part of the physical address
 */
static inline emc_std_uint32_t EMC_PhysicalAddress_low(struct EMC_PhysicalAddress a)
{ return (emc_std_uint32_t)a.handle; }

/** @memberof EMC_PhysicalAddress
    @brief Return the high 32-bit part of the physical address
 */
static inline emc_std_uint32_t EMC_PhysicalAddress_high(struct EMC_PhysicalAddress a)
#if 4 == EMC_SIZEOF_POINTER
{ UNUSED_PARAM(a); return 0; }

#else
{ return (emc_std_uint32_t)(a.handle >> (sizeof(emc_std_uint32_t) * 8)); }
#endif

EMC_EXTERN_C_END;

#endif /* EMC_HW_MEMORY_PhysicalAddress_H */

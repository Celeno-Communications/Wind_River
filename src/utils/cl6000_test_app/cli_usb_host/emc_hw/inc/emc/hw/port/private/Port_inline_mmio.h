/**
 * @file
 * @brief   The Generic Port Access Layer API
 * @author  Stefan Schulze <stefan.schulze@emsys.de> +49-3677-68977-22
 * Copyright (C) 2013, 2020-2021 emsys Embedded Systems GmbH
 */

#ifndef EMC_HW_PORT_PRIVATE_Port_inline_mmio_H
#define EMC_HW_PORT_PRIVATE_Port_inline_mmio_H

#include "emc/hw/port/Port_fwd.h"

#include "emc/std/stdint.h"
#include "emc/std/ext/intconvert.h"

EMC_EXTERN_C_BEGIN;

/** This opaque struct is only used via pointer and has no usable data member, but can't be empty*/
struct EMC_HW_Port { unsigned _reserved; };

/** @memberof EMC_HW_Port
    @brief Destructor */
static inline void EMC_HW_Port_destroy(EMC_HW_Port* self)
{ UNUSED_PARAM(self); }

/** @memberof EMC_HW_Port
    @brief Destroy and delete a port
    This should be a real function, because the address of this function is used on some places
 */
static inline void EMC_HW_Port_delete(EMC_HW_Port* self)
{ UNUSED_PARAM(self); }

/** @relates EMC_HW_Port @brief port read register direct */
static inline void EMC_HW_Port_read_register(emc_std_uintptr_t address, emc_std_uint32_t* u32)
{
  *u32 = /*lint -e(413) */ *(volatile emc_std_uint32_t*)(address);
#if EMC_HW_PORT_READ_HOOK
  EMC_HW_Port_read_hook(address, u32);
#endif
}

/** @relates EMC_HW_Port @brief port read register */
#define EMC_HW_Port_read32(p, o, v) EMC_HW_Port_read_register((emc_std_uintptr_t)(o), &to_uint32(*(v)))

/** Write to a register, use memory-mapped IO
 * @param address The address of the register write access
 * @param u32 The value to write
 *
 * @memberof EMC_HW_Port
 */
static inline void EMC_HW_Port_write_register(emc_std_uintptr_t address, emc_std_uint32_t u32)
{
#if EMC_HW_PORT_WRITE_HOOK
  EMC_HW_Port_write_hook(address, &u32);
#endif
  /*lint -e(413) */ *(volatile emc_std_uint32_t*)(address) = u32;
}

/** @relates EMC_HW_Port @brief Port write register */
#define EMC_HW_Port_write32(p, o, v) EMC_HW_Port_write_register((emc_std_uintptr_t)(o), to_uint32(v))

EMC_EXTERN_C_END;

#endif /* EMC_HW_PORT_PRIVATE_Port_inline_mmio_H */

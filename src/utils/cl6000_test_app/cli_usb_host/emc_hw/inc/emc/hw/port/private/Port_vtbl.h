/**
 * @file
 * @brief   The Generic Port Access Layer API
 * @author  Stefan Schulze <stefan.schulze@emsys.de> +49-3677-68977-22
 * Copyright (C) 2013, 2020 emsys Embedded Systems GmbH
 */

#ifndef EMC_HW_PORT_PRIVATE_Port_vtbl_H
#define EMC_HW_PORT_PRIVATE_Port_vtbl_H

#include "emc/hw/port/Port_fwd.h"

#include "emc/std/stdint.h"
#include "emc/std/ext/intconvert.h"

EMC_EXTERN_C_BEGIN;

/** Generic port access layer */
struct EMC_HW_Port {
  /** The virtual function table */
  const struct EMC_HW_PortFunctionTable* vtable;
};

/** @memberof EMC_HW_Port
    @brief Destructor */
void EMC_HW_Port_destroy(EMC_HW_Port* self);

/** @memberof EMC_HW_Port
    @brief Destroy and delete a port */
void EMC_HW_Port_delete(EMC_HW_Port* self);

/** Read from a register
 * @param port The port instance
 * @param address The address of the register write access
 * @param u32 The value read
 *
 * @memberof EMC_HW_Port
 */
void EMC_HW_Port_read_register(EMC_HW_Port* port, emc_std_uintptr_t address, emc_std_uint32_t* u32);

/** @relates EMC_HW_Port @brief port read register */
#define EMC_HW_Port_read32(p, o, v) EMC_HW_Port_read_register((p), (emc_std_uintptr_t)(o), &to_uint32(*(v)))

/** Write to a register, use write function if provided
 * @param port The port instance
 * @param address The address of the register write access
 * @param u32 The value to write
 *
 * @memberof EMC_HW_Port
 */
void EMC_HW_Port_write_register(EMC_HW_Port* port, emc_std_uintptr_t address, emc_std_uint32_t u32);

/** @relates EMC_HW_Port @brief Port write register */
#define EMC_HW_Port_write32(p, o, v) EMC_HW_Port_write_register((p), (emc_std_uintptr_t)(o), to_uint32(v))

EMC_EXTERN_C_END;

#endif /* EMC_HW_PORT_PRIVATE_Port_vtbl_H */

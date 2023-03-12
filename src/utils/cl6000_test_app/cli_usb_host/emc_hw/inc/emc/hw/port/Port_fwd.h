/**
 * @file
 * @brief   The Generic Port Access Layer API
 * @author  Stefan Schulze <stefan.schulze@emsys.de> +49-3677-68977-22
 * Copyright (C) 2013, 2020-2021 emsys Embedded Systems GmbH
 */

#ifndef EMC_HW_PORT_Port_fwd_H
#define EMC_HW_PORT_Port_fwd_H

#include "emc/hw/configure.h"
#include "emc/std/stdint.h"

EMC_EXTERN_C_BEGIN;

/** Generic port type */
typedef struct EMC_HW_Port EMC_HW_Port;

#if EMC_HW_PORT_READ_HOOK
/** Prototype for port read hook function, called after register is read */
void EMC_HW_Port_read_hook(emc_std_uintptr_t address, emc_std_uint32_t* value);
#endif

#if EMC_HW_PORT_WRITE_HOOK
/** Prototype for port write hook function, called before register is written */
void EMC_HW_Port_write_hook(emc_std_uintptr_t address, emc_std_uint32_t* value);
#endif

EMC_EXTERN_C_END;

#endif /* EMC_HW_PORT_Port_fwd_H */

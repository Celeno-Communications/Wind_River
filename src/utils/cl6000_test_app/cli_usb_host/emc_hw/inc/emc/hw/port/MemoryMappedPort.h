/**
 * @file
 * @brief   The memory mapped Port Access Layer API
 * @author  Stefan Schulze <stefan.schulze@emsys.de> +49-3677-68977-22
 * Copyright (C) 2013, 2020 emsys Embedded Systems GmbH
 */

#ifndef EMC_HW_PORT_MemoryMappedPort_H
#define EMC_HW_PORT_MemoryMappedPort_H

#include "emc/hw/port/Port_fwd.h"
#include "emc/hw/port/Port.h"

EMC_EXTERN_C_BEGIN;

/** @memberof EMC_HW_Port
    @brief Allocate and initialize a memory mapped port instance */
EMC_HW_Port* EMC_MemoryMappedPort_new(emc_std_uintptr_t base_address);

/** @memberof EMC_HW_Port
    @brief Constructor */
void EMC_MemoryMappedPort_init(EMC_HW_Port* self, emc_std_uintptr_t base_address);

EMC_EXTERN_C_END;

#endif /* EMC_HW_PORT_MemoryMappedPort_H */

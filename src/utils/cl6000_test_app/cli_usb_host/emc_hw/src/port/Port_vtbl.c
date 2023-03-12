/* Copyright (C) 2013, 2020-2021 emsys Embedded Systems GmbH */

#include "emc/hw/port/private/Port_vtbl.h"
#include "emc/hw/port/private/PortFunctionTable.h"
#include "emc/std/assert.h"

void EMC_HW_Port_delete(EMC_HW_Port* port)
{
  emc_std_assert(port);
  emc_std_assert(port->vtable);
  emc_std_assert(port->vtable->delete_and_destroy);

  (*port->vtable->delete_and_destroy)(port);
}

void EMC_HW_Port_destroy(EMC_HW_Port* port)
{
  emc_std_assert(port);
  emc_std_assert(port->vtable);
  emc_std_assert(port->vtable->destroy);

  (*port->vtable->destroy)(port);
}

void EMC_HW_Port_read_register(EMC_HW_Port* port, emc_std_uintptr_t address, emc_std_uint32_t* u32)
{
  emc_std_assert(port);
  emc_std_assert(port->vtable);
  emc_std_assert(port->vtable->read_register);

  (*port->vtable->read_register)(port, address, u32);
}

void EMC_HW_Port_write_register(EMC_HW_Port* port, emc_std_uintptr_t address, emc_std_uint32_t u32)
{
  emc_std_assert(port);
  emc_std_assert(port->vtable);
  emc_std_assert(port->vtable->write_register);

  (*port->vtable->write_register)(port, address, u32);
}

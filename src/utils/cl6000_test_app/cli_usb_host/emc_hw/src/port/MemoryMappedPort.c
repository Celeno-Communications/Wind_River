/* Copyright (C) 2013, 2020 emsys Embedded Systems GmbH */

#include "emc/hw/port/MemoryMappedPort.h"
#include "emc/hw/port/private/PortFunctionTable.h"
#include "emc/std/stdlib.h"

static void port_destroy(EMC_HW_Port* self)
{
  UNUSED_PARAM(self);
}

static void port_delete(EMC_HW_Port* self)
{
  port_destroy(self);
  emc_std_free(self);
}

static void read_register(EMC_HW_Port* self, emc_std_uintptr_t address, emc_std_uint32_t* value)
{
  UNUSED_PARAM(self);
  *value = /*lint -e(413) */ *(volatile emc_std_uint32_t*)(address);
#if EMC_HW_PORT_READ_HOOK
  EMC_HW_Port_read_hook(address, value);
#endif
}

static void write_register(EMC_HW_Port* self, emc_std_uintptr_t address, emc_std_uint32_t value)
{
  UNUSED_PARAM(self);
#if EMC_HW_PORT_READ_HOOK
  EMC_HW_Port_write_hook(address, &value);
#endif
  /*lint -e(413) */ *(volatile emc_std_uint32_t*)(address) = value;
}

static const struct EMC_HW_PortFunctionTable mg_port_vtable = {
  port_destroy, port_delete, read_register, write_register
};

void EMC_MemoryMappedPort_init(EMC_HW_Port* self, emc_std_uintptr_t base_address)
{
  self->vtable = &mg_port_vtable;
  UNUSED_PARAM(base_address);
}

EMC_HW_Port* EMC_MemoryMappedPort_new(emc_std_uintptr_t base_address)
{
  EMC_HW_Port* result = emc_std_malloc(sizeof(EMC_HW_Port));
  if (result) {
    EMC_MemoryMappedPort_init(result, base_address);
  }
  return result;
}

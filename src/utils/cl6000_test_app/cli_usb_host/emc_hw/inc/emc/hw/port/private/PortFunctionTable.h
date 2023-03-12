/* Copyright (C) 2013, 2020-2021 emsys Embedded Systems GmbH */

#ifndef EMC_HW_PORT_PRIVATE_PortFunctionTable_H
#define EMC_HW_PORT_PRIVATE_PortFunctionTable_H

#include "emc/hw/port/Port_fwd.h"

EMC_EXTERN_C_BEGIN;

/** Private virtual functions for the generic port access layer */
struct EMC_HW_PortFunctionTable {
  /** The destroy member function */
  void (* destroy)(EMC_HW_Port*);
  /** The delete and destroy member function */
  void (* delete_and_destroy)(EMC_HW_Port*);
  /** The read register member function */
  void (* read_register)(EMC_HW_Port*, emc_std_uintptr_t address, emc_std_uint32_t* value32);
  /** The write register member function */
  void (* write_register)(EMC_HW_Port*, emc_std_uintptr_t address, emc_std_uint32_t value32);
};

EMC_EXTERN_C_END;

#endif /* EMC_HW_PORT_PRIVATE_PortFunctionTable_H */

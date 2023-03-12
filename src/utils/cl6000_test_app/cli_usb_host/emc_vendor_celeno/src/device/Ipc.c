/**
 * @file
 * @brief The IPC Register access API implementation
 * Copyright (C) 2022 emsys Embedded Systems GmbH
 ****************************************************************************/
#include "emc/vendor/celeno/device/Ipc.h"

#undef REG_PL_RD
#undef REG_PL_WR

#define REG_PL_RD(addr)              (*(volatile uint32_t*)(addr))
#define REG_PL_WR(addr, value)       (*(volatile uint32_t*)(addr)) = (value)

#ifndef PRIM_BAND
#  define PRIM_BAND 0
#endif

#include "emc/vendor/celeno/device/register/gen/reg_ipc.h"

void EMC_CELENO_trigger_umac2lmac_interrupt(emc_std_uint32_t value)
{
  ipc_umac_2_lmac_trigger_umac_2_lmac_trigger_setf(value);
}

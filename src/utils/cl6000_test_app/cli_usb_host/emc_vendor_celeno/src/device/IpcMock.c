/**
 * @file
 * @brief The IPC Register access API mock
 * Copyright (C) 2022 emsys Embedded Systems GmbH
 ****************************************************************************/
#include "emc/vendor/celeno/device/Ipc.h"

#undef REG_PL_RD
#undef REG_PL_WR

static emc_std_uint32_t read_reg(emc_std_uint32_t addr);
static void write_reg(emc_std_uint32_t addr, emc_std_uint32_t value);

#define REG_PL_RD(addr)              read_reg(addr)
#define REG_PL_WR(addr, value)       write_reg(addr, value)

#ifndef PRIM_BAND
#  define PRIM_BAND 0
#endif

#ifdef __GNUC__
#  if GCC_VERSION >= 40700
#    pragma GCC diagnostic push
#    pragma GCC diagnostic ignored "-Wconversion"
#  endif
#endif

#include "emc/vendor/celeno/device/register/gen/reg_ipc.h"

#ifdef __GNUC__
#  if GCC_VERSION >= 40700
//#    pragma GCC diagnostic pop
#  endif
#endif

#define IPC_COUNT (IPC_HOST_2_SMAC_STATUS_INDEX)

emc_std_uint32_t mg_ipc_registerset[IPC_COUNT] = {0};

emc_std_uint32_t read_reg(emc_std_uint32_t addr)
{
  emc_std_uint32_t idx = (addr - REG_IPC_BASE_ADDR) / sizeof(emc_std_uint32_t);
  emc_std_assert(idx < IPC_COUNT);
  return mg_ipc_registerset[idx];
}

void write_reg(emc_std_uint32_t addr, emc_std_uint32_t value)
{
  emc_std_uint32_t idx = (addr - REG_IPC_BASE_ADDR) / sizeof(emc_std_uint32_t);
  emc_std_assert(idx < IPC_COUNT);
  mg_ipc_registerset[idx] = value;
}

emc_std_uint32_t mg_ipc_mock_umac2lmac_int = 0; // number of interrupts

void EMC_CELENO_trigger_umac2lmac_interrupt(emc_std_uint32_t value)
{
  mg_ipc_mock_umac2lmac_int++;
  write_reg(IPC_UMAC_2_SMAC_RAW_STATUS_ADDR, read_reg(IPC_UMAC_2_SMAC_RAW_STATUS_ADDR) | value);
  ipc_umac_2_lmac_trigger_umac_2_lmac_trigger_setf(value);
}

emc_std_uint32_t EMC_CELENO_trigger_umac2lmac_status_value()
{
  return read_reg(IPC_UMAC_2_SMAC_RAW_STATUS_ADDR);
}

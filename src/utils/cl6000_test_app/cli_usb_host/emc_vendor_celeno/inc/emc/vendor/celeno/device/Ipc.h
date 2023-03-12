/**
 * @file
 * @brief The IPC Register access API
 * Copyright (C) 2022 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_VENDOR_CELENO_DEVICE_Ipc_H
#define EMC_VENDOR_CELENO_DEVICE_Ipc_H

#include "emc/vendor/celeno/configure.h"
#include "emc/std/stdint.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on

/// Interrupt value for umac2lmac pdma finished
#define EMC_CELENO_IPC_UMAC2LMAC_PDMA_DONE_INT (1 << 0)

/// Trigger from umac an interrupt for lmac
void EMC_CELENO_trigger_umac2lmac_interrupt(emc_std_uint32_t value);

/// Read interrupt raw value
emc_std_uint32_t EMC_CELENO_trigger_umac2lmac_status_value();

// clang-format off extern C
#  ifdef __cplusplus
}
#  endif
// clang-format on

#endif /* EMC_VENDOR_CELENO_DEVICE_Ipc_H */

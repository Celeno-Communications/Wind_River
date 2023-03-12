/**
 * @file
 *
 * @author  Ralf Oberländer <ralf.oberlaender@emsys.de>
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/

#ifndef EMC_SYSTEM_CELENO_TestHelper_H
#define EMC_SYSTEM_CELENO_TestHelper_H

#include <stdint.h>

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/// Rise assert for test purpose
void emc_test_assert(void);

/// Rise div_by_zero exception
void emc_test_div0_exception(void);

/// Test logging capability
void emc_test_logging(void);

/// Test IDMA operation
void emc_test_idma(void);

/// Test read access to address
uint32_t emc_test_read32_access(uintptr_t addr);

/// Test write access to address
void emc_test_write32_access(uintptr_t addr, uint32_t data);

/// Just log some string and stay there
void emc_test_log_something_and_never_return();

/// Produce log-statements with 10us delay in between to verify xtensa cycle count
void emc_test_cycle_count();

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_SYSTEM_CELENO_LogHelper_H */

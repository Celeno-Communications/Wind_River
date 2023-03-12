/**
 * @file
 *
 * @author  Ralf Oberländer <ralf.oberlaender@emsys.de>
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/

#ifndef EMC_SYSTEM_CELENO_DebugHelper_H
#define EMC_SYSTEM_CELENO_DebugHelper_H

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/// Initialize exception/assertion handling
void emc_assertion_exception_handler_init(void);

/// check if coredump is available in sidebuffer
uint32_t emc_coredump_available();

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif

/**
 * @file
 * @author <karsten.pahnke@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 */

#ifndef EMC_LOG_INTERNAL_appender_memory_H
#define EMC_LOG_INTERNAL_appender_memory_H

#include "emc/log/internal/appender.h"
#include "emc/std/stddef.h"

// clang-format off extern C
#ifdef __cplusplus /*  @srcdist keep  */
extern "C" {
#endif
// clang-format on extern C

/** the memory appender instance */
emc_log_appender* emc_log_appender_memory(void* memory, emc_std_size_t memory_size);

// clang-format off extern C
#ifdef __cplusplus /*  @srcdist keep  */
}
#endif
// clang-format on extern C

#endif

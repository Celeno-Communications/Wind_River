/**
 * @file
 * @author <karsten.pahnke@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 */

#ifndef EMC_LOG_INTERNAL_appender_fprintf_H
#define EMC_LOG_INTERNAL_appender_fprintf_H

#include "emc/log/internal/appender.h"
#include "emc/std/stdio.h"

// clang-format off extern C
#ifdef __cplusplus /*  @srcdist keep  */
extern "C" {
#endif
// clang-format on extern C

/** the fprintf appender instance */
emc_log_appender* emc_log_appender_fprintf(FILE* file);

// clang-format off extern C
#ifdef __cplusplus /*  @srcdist keep  */
}
#endif
// clang-format on extern C

#endif

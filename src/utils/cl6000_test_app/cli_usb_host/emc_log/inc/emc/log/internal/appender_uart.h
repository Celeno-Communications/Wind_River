/**
 * @file
 * @author <karsten.pahnke@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 */

#ifndef EMC_LOG_INTERNAL_appender_uart_H
#define EMC_LOG_INTERNAL_appender_uart_H

#include "emc/log/internal/appender.h"

// clang-format off extern C
#ifdef __cplusplus /*  @srcdist keep  */
extern "C" {
#endif
// clang-format on extern C

/** the uart appender instance */
emc_log_appender* emc_log_appender_uart(void);

// clang-format off extern C
#ifdef __cplusplus /*  @srcdist keep  */
}
#endif
// clang-format on extern C

#endif

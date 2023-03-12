#ifndef EMC_SYSTEM_CELENO_DEVICE_APPLICATION_LiveLogging_H
#define EMC_SYSTEM_CELENO_DEVICE_APPLICATION_LiveLogging_H

#include "emc/system/celeno/configure.h"
#include "emc/log/log.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

void CELENO_live_logging_init(void);
void CELENO_live_logging_configure(emc_std_uint32_t timeout_ms, emc_std_uint32_t threshold);
void CELENO_live_logging_poll(void);

emc_logger_t* CELENO_logging_logger_live(void);

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_SYSTEM_CELENO_DEVICE_APPLICATION_LiveLogging_H */

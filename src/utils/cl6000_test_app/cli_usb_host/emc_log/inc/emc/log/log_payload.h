/**
 * @file
 */

#ifndef EMC_LOG_log_payload_H
#define EMC_LOG_log_payload_H

#include "emc/log/log.h"

#if EMC_LOG_LOGGING_VARIANT == EMC_LOG_LOGGING_NONE
#  define EMC_LOG_PAYLOAD(log, prio, data, size)       \
  do {((void)(log)); ((void)(data)); ((void)(size)); \
  } while (0)
#endif

#if (EMC_LOG_LOGGING_VARIANT == EMC_LOG_LOGGING_INTERNAL) || (EMC_LOG_LOGGING_VARIANT == EMC_LOG_LOGGING_EMCPP)
#  define EMC_LOG_PAYLOAD(logger, prio, data, size)               \
  do { if ((static_log_level) >= (EMC_LOG_PRIORITY_ ## prio)) {         \
      if (size >= 4) {                                                  \
        _EMC_LOG_P5((logger), prio, "size = %d, data=0x%x,0x%x,0x%x,0x%x,...", (size), \
                    ((emc_std_uint8_t*)data)[0],                        \
                    ((emc_std_uint8_t*)data)[1],                        \
                    ((emc_std_uint8_t*)data)[2],                        \
                    ((emc_std_uint8_t*)data)[3]);                       \
      } else {                                                          \
        _EMC_LOG_P1((logger), prio, "size = %d", (size));              \
      }                                                                 \
    } } while (0)
#  include "emc/log/log_internal.h"
#endif

#if EMC_LOG_LOGGING_VARIANT == EMC_LOG_LOGGING_CUSTOMER
#  define EMC_LOG_PAYLOAD(log, prio, data, size)       \
  do {((void)(log)); ((void)(data)); ((void)(size)); \
  } while (0)
#endif

#endif /*EMC_LOG_log_payload_H*/

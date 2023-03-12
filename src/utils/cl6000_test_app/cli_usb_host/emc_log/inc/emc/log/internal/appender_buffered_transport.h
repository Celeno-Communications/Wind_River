/**
 * @file
 * Copyright (C) 2022 emsys Embedded Systems GmbH
 */

#ifndef EMC_LOG_INTERNAL_appender_buffered_transport_H
#define EMC_LOG_INTERNAL_appender_buffered_transport_H

#include "emc/log/internal/appender.h"
#include "emc/std/stddef.h"
#include "emc/std/ext/timestamp.h"
#include "emc/log/internal/lock.h"

// clang-format off extern C
#ifdef __cplusplus /*  @srcdist keep  */
extern "C" {
#endif
// clang-format on extern C

/** the appender instance that buffers logs and sends it through transport */
emc_log_appender* emc_log_appender_buffered_transport(void* memory, emc_std_size_t memory_size);

/** set the @param sync synchronization for @param self*/
void emc_log_appender_buffered_transport_set_synchronization(emc_log_appender* self, const emc_log_lock_t* sync);

/** flush all buffered log messages in @param self, forward it to transport */
void emc_log_appender_buffered_transport_flush(emc_log_appender* self);

/** set buffer timeout for @param self, if there was no log for @param timeout ticks
 * all pending buffered logs will be forwarded to transport
 */
void emc_log_appender_buffered_transport_set_timeout(emc_log_appender* self, timestamp_t timeout);

/** set message threshold for @param self, if @param entries are buffered
 * all pending logs will be forwarded to transport */
void emc_log_appender_buffered_transport_set_threshold(emc_log_appender* self, emc_std_size_t entries);

/** Buffer overflow policies */
typedef enum EMC_LOG_AppenderBufferPolicy_e {
  EMC_LOG_APPENDER_BUFFER_POLICY_Discard = 0, /**< Discard the new entry */
  EMC_LOG_APPENDER_BUFFER_POLICY_Overwrite    /**< Overwrite the oldest entry */
} EMC_LOG_AppenderBufferPolicy;

/** set the policy for handling buffer overflow in @param self*/
void emc_log_appender_buffered_transport_set_policy(emc_log_appender* self, EMC_LOG_AppenderBufferPolicy policy);

/** poll appender @param self at time point @param ts ticks to check timeout */
void emc_log_appender_buffered_transport_poll(emc_log_appender* self, timestamp_t now);

/** prototype of send complete callback, to be called if transport send function has consumed the provided log data
 * @param context context provided in cb_context parameter of transport send function
 * @param size    the size of consumed log data in bytes
 */
typedef void (EMC_LOG_APPENDER_BUFFERED_TRANSPORT_complete_func)(void* context,
                                                                 emc_std_size_t size);
/** prototype of transport send function
 * @param context    context provided on setting the log transport
 * @param mem        start of the log data
 * @param size       size of the valid log data at @param mem, in bytes
 * @param cb         callback function to be called if transport has consumed the log data
 * @param cb_context context to be provided when calling @param cb
 */
typedef void (EMC_LOG_APPENDER_BUFFERED_TRANSPORT_send_func)(void* context,
                                                             void* mem,
                                                             emc_std_size_t size,
                                                             EMC_LOG_APPENDER_BUFFERED_TRANSPORT_complete_func* cb,
                                                             void* cb_context);

/** set the log transport of @param self to @param func */
void emc_log_appender_buffered_transport_set_send_func(emc_log_appender* self,
                                                       EMC_LOG_APPENDER_BUFFERED_TRANSPORT_send_func* func,
                                                       void* context);

// clang-format off extern C
#ifdef __cplusplus /*  @srcdist keep  */
}
#endif
// clang-format on extern C

#endif /* EMC_LOG_INTERNAL_appender_buffered_transport_H */

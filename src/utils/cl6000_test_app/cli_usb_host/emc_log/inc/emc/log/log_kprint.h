/*
 * log_kprint.h
 */

#ifndef EMC_LOG_log_kprint_H
#define EMC_LOG_log_kprint_H

#include "Ntddk.h"

// clang-format off extern C
#ifdef __cplusplus /*  @srcdist keep  */
extern "C" {
#endif
// clang-format on extern C

#define EMC_STATIC_LOG_LEVEL_DEFINE(prio) \
  struct emc_macro_requires_semicolon

#define EMC_LOG5(log, prio, msg, p1, p2, p3, p4, \
                 p5) KdPrint(((msg), (p1), (p2), (p3), (p4), (p5)))
#define EMC_LOG4(log, prio, msg, p1, p2, p3, p4) KdPrint(((msg), (p1), (p2), (p3), (p4)))
#define EMC_LOG3(log, prio, msg, p1, p2, p3) KdPrint(((msg), (p1), (p2), (p3)))
#define EMC_LOG2(log, prio, msg, p1, p2) KdPrint(((msg), (p1), (p2)))
#define EMC_LOG1(log, prio, msg, p1) KdPrint(((msg), (p1)))
#define EMC_LOG(log, prio, msg) KdPrint(((msg)))

// clang-format off extern C
#ifdef __cplusplus /*  @srcdist keep  */
}
#endif
// clang-format on extern C

#endif /* EMC_LOG_log_kprint_H */

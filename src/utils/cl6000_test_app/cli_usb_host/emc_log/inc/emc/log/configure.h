/**
 * @file
 * @author  Enrico Schmidtke <enrico.schmidtke@emsys.de> +49-3677-68977-14
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * (C) emsys Embedded Systems GmbH 2013
 *
 ****************************************************************************/
#ifndef EMC_LOG_configure_H
#define EMC_LOG_configure_H

#ifdef HAVE_CMAKE_CONFIGURE
#  include "emc_log/cmakeConfigure.h"
#endif
#include "emc/config/configure.h"

/** Log uses a hash */
#ifndef EMC_LOG_USES_HASH
#  define EMC_LOG_USES_HASH 0
#endif

/** logging capability */
#ifndef EMC_LOG_LOGGING
#  define EMC_LOG_LOGGING 0
#endif

/** logging variant: no logging */
#define EMC_LOG_LOGGING_NONE 0
/** logging variant: internal logging */
#define EMC_LOG_LOGGING_INTERNAL 1
/** logging variant: EMCPP logging */
#define EMC_LOG_LOGGING_EMCPP 2
/** logging variant: customer-specific logging */
#define EMC_LOG_LOGGING_CUSTOMER 3
/** logging variant: Win32 DebugPrint logging */
#define EMC_LOG_LOGGING_KPRINT 4

#ifndef EMC_LOG_LOGGING_VARIANT
#  define EMC_LOG_LOGGING_VARIANT EMC_LOG_LOGGING_NONE
#endif

#ifndef EMC_LOG_DETAILED_PROFILING
#  define EMC_LOG_DETAILED_PROFILING 0
#endif

/** Log internal uses __FILE__ */
#ifndef EMC_LOG_INTERNAL_USES_FILE
#  define EMC_LOG_INTERNAL_USES_FILE 0
#endif

/** Log internal uses timestamp */
#ifndef EMC_LOG_INTERNAL_USES_TIMESTAMP
#  define EMC_LOG_INTERNAL_USES_TIMESTAMP 0
#endif

#ifndef EMC_LOG_INTERNAL_APPENDER_PRINTF_INSTANCES
#  define EMC_LOG_INTERNAL_APPENDER_PRINTF_INSTANCES 0
#endif

#ifndef EMC_LOG_INTERNAL_APPENDER_MEMORY_INSTANCES
#  define EMC_LOG_INTERNAL_APPENDER_MEMORY_INSTANCES 0
#endif

#ifndef EMC_LOG_INTERNAL_APPENDER_UART_INSTANCES
#  define EMC_LOG_INTERNAL_APPENDER_UART_INSTANCES 0
#endif

#ifndef EMC_LOG_INTERNAL_APPENDER_BUFFERED_TRANSPORT_INSTANCES
#  define EMC_LOG_INTERNAL_APPENDER_BUFFERED_TRANSPORT_INSTANCES 0
#endif

#endif /* EMC_LOG_configure_H */

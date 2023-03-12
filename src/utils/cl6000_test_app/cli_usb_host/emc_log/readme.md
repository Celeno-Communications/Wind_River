## emc_log The C Logging Interface {#emc_log_readme}

### Configuration

The emc_log can be configured via the CMake variable EMC_LOG:
* NONE    : disabled logging
* INTERNAL: plain C implementation
* EMCPP   : as interface adaptor to the emcpp_log API
* KPRINT  : as macro wrapper around the Win32 KPrint API
* (LOG4C) : (in planning) adapter to the Log4C logging framework
* CUSTOMER: indirection to customer log macro definitions

### Internal Logging Implementation

If INTERNAL was seleceted the following essential options are available:

#### Appender

EMC_LOG_INTERNAL_APPENDER_NULL     : Null Implementation of the Appender API
EMC_LOG_INTERNAL_APPENDER_MEMORY   : Memory Logging with configurable memory size
EMC_LOG_INTERNAL_APPENDER_PRINTF   : fprintf on stderr
EMC_LOG_INTERNAL_APPENDER_UART     : snprintf on serial channel
EMC_LOG_INTERNAL_APPENDER_CUSTOMER : open symbols for customer implementation

#### Number Instances

The CMake variable EMC_LOG_INTERNAL_INSTANCES defines the number physical logger instances possible.
This has to be at least 1 to hold the root logger.

Logger instances always create the whole path, that implies parent loggers are created (potentially implicit) before the child loggers. If there is no further logger instance possible, the reference on the parent will be provided. The may be in extreme cases (e.g. only 1 logger) the root logger.
As a consequence the function EMC_Log_logger(const char* category) will always return a valid logger (potentially any parent logger or the root_logger).

#### Priorities

By default the loggers (except the root looger) will get initialy a not set priority. If a priority should be set the 
EMC_Log_set_priority() needs to be called.
The priority inheritance is implemented via a cache, so that a priority get/check internaly will read only the cache and not traverse the tree upwards.
This could be done by the following operations:
a) The logger stores the priority (in cache semantics) and the explicit set priority (priority_set).
b) Every set_priority sets the priority_set on this node and the priority cache on all childs, until a child is found with explicit priority_set.
c) If a new logger is created it gets the cache initialized from the parent cache.



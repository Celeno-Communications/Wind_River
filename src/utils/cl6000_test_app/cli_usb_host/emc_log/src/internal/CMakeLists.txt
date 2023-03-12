target_sources(emc_log PRIVATE
  logger.c
  appender_null.c
)

if (EMC_LOG_INTERNAL_APPENDER_MEMORY_INSTANCES GREATER "0")
  target_sources(emc_log PRIVATE
    appender_memory.c
  )
endif()
if (EMC_LOG_INTERNAL_APPENDER_PRINTF_INSTANCES GREATER "0")
  target_sources(emc_log PRIVATE
    appender_fprintf.c
  )
endif()
if (EMC_LOG_INTERNAL_APPENDER_UART_INSTANCES GREATER "0")
  target_sources(emc_log PRIVATE
    appender_uart.c
  )
endif()
if (EMC_LOG_INTERNAL_APPENDER_BUFFERED_TRANSPORT_INSTANCES GREATER "0")
  target_sources(emc_log PRIVATE
    appender_buffered_transport.c
  )
endif()

if(EMC_TEST)
  add_subdirectory(test)
endif()


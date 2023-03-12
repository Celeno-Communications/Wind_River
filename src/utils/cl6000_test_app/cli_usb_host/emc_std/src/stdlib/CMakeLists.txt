if(EMC_TEST)
  add_subdirectory(test)
endif()

if(EMC_PRINT)
  target_sources(emc_std PRIVATE
    fprintf.c
    stdio.c
  )
endif()

if(EMC_TARGET_OS_API STREQUAL "MOPI")
  target_sources(emc_std PRIVATE
    emc_time.c
  )
endif()

target_sources(emc_std PRIVATE
  cstring.c
  wchar.c
  signal.c
  stdlib.c
  ctype.c
  errno.c
)

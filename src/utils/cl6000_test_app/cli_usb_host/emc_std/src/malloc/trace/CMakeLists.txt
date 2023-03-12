target_sources(emc_std PRIVATE
  HeapBreakpoint.c
  HeapChronicle.c
  HeapChunkStatistics.c
  HeapMonitor.c
  HeapSummary.c
  HeapTrace.c
  malloc_debug.c
)

if(EMC_TEST)
  add_subdirectory(test)
endif()

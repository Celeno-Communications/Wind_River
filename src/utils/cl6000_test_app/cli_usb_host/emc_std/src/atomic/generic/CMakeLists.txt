if(CMAKE_C_COMPILER_ID MATCHES "MSVC")
  if(PROJECT_COMPILER_MSC_WDK_VER GREATER 0)
    target_sources(emc_std PRIVATE
      stdatomic_wdk.cpp
    )
  else()
    target_sources(emc_std PRIVATE
      stdatomic_stdcpp.cpp
    )
  endif()
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Intel|Clang")
  target_sources(emc_std PRIVATE
    stdatomic_gcc_sync.c
  )
endif()

if(CMAKE_C_COMPILER_ID MATCHES "ARMCC")
  message("No atomic implementation available for ARMCC in emc_std.")
endif()
  

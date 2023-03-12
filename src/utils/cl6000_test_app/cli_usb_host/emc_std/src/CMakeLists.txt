add_library(emc_std)

target_include_directories(emc_std PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../inc)

set_target_properties(emc_std PROPERTIES NOT_LINTABLE "stdatomic_imc;stdatomic_gcc_sync")


if(EMC_STD_ASSERT_IMPL STREQUAL "LOG")
  target_link_libraries(emc_std PRIVATE emc_log)
endif()

if(EMC_TEST)
  add_subdirectory(test)
endif()

if(EMC_STD_ASSERT STREQUAL "EMULATE")
  add_subdirectory(assert)
endif()

if( NOT (EMC_STD_ATOMIC STREQUAL "STD") )
  add_subdirectory(atomic)
endif()

if ( NOT (EMC_STD_STDLIB STREQUAL "STD") )
  add_subdirectory(stdlib)
endif()

if( NOT (EMC_STD_MALLOC STREQUAL "STD") )
  add_subdirectory(malloc)
endif()

target_sources(emc_std PRIVATE
  dummy_std.c
)

target_link_libraries(emc_std
  PUBLIC
    emc_config
)

if(EMC_STD_MALLOC STREQUAL "AMS")
  target_link_libraries(emc_std PUBLIC external_ams_heap)
elseif(EMC_STD_MALLOC STREQUAL "XALLOC")
  target_link_libraries(emc_std PUBLIC comneon_util)
elseif((EMC_STD_MALLOC STREQUAL "tlsf") OR (EMC_STD_DMA_MALLOC STREQUAL "tlsf"))
  target_link_libraries(emc_std PUBLIC emc_std_thread emc_log external_baisoku_tlsf)
elseif(EMC_STD_MALLOC STREQUAL "XTOS")
  target_link_libraries(emc_std PUBLIC emc_std_thread external_sue)
elseif(EMC_STD_MALLOC MATCHES "rcx|XALLOC")
  #target_link_libraries(emc_std)
endif()

if(EMC_STD_MUTEX MATCHES "extern")
  target_link_libraries(emc_std PUBLIC emc_std_thread)
endif()

if((EMC_STD_MALLOC_LOCK STREQUAL "SPINLOCK") AND (NOT (EMC_STD_SPINLOCK STREQUAL "NONE")) )
  target_link_libraries(emc_std PUBLIC emc_std_thread)
endif()

if( (EMCPP_COMNEON_UTA_OS STREQUAL "windows") OR  (EMCPP_UNITTEST_CPPUNIT) )
  if((EMC_STD_MUTEX STREQUAL "uta") OR (EMC_STD_SPINLOCK STREQUAL "uta"))
    target_link_libraries(emc_std PUBLIC comneon_uta_os)
  endif()
endif()

if((EMC_STD_TIMESTAMP STREQUAL "embos") OR (EMC_STD_SPINLOCK STREQUAL "embos") )
  #target_link_libraries(emc_std PUBLIC external_embos_bsp)
endif()


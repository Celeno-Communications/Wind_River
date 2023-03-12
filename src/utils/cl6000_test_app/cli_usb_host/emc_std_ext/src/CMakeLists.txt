add_library(emc_std_ext)

target_include_directories(emc_std_ext PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../inc)


set_target_properties(emc_std_ext PROPERTIES NOT_LINTABLE "stdatomic_imc;stdatomic_gcc_sync")


target_link_libraries(emc_std_ext
  PUBLIC
    emc_std
)

target_sources(emc_std_ext PRIVATE
  ErrorCategory.c
  assert_ext.c
  memcpy.c
  uitoa.c
)

if(EMC_STD_TIMESTAMP MATCHES "xtos")
  target_sources(emc_std_ext PRIVATE
    timestamp_xtosC.cpp
  )
endif()

if(EMC_STD_TIMESTAMP MATCHES "freertos")
  target_sources(emc_std_ext PRIVATE
    timestamp_freertosC.c
  )

  target_link_libraries(emc_std_ext PUBLIC
    external_freertos_kernel
  )

endif()

add_subdirectory(dma_malloc)

if(EMC_TEST)
  add_subdirectory(test)
endif()


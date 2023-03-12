if(EMCPP_TEST)
  add_subdirectory(test)
endif()

target_sources(emc_std PRIVATE
  malloc.c
  wrapper.c
)

target_sources(emc_usb PRIVATE
  Allocatable.c
)

if( EMC_TEST)
  add_subdirectory(test)
endif()


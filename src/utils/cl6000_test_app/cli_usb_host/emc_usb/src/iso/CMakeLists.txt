target_sources(emc_usb PRIVATE
  ContinuousChannel.c
  ContinuousBuffer.c
)

if(EMC_TEST)
  add_subdirectory(test)
endif()

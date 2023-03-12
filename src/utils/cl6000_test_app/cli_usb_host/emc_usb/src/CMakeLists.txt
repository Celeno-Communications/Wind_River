add_library(emc_usb)

target_include_directories(emc_usb PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../inc)

target_link_libraries(emc_usb
  PUBLIC
    emc_std
    emc_log
    emc_hw
)

if (EMC_PRINT)
  target_link_libraries(emc_usb
    PUBLIC
      emc_data
  )
endif()

if(EMC_TEST)
  add_library(emc_usb_test)

  target_include_directories(emc_usb_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../inc)

  target_link_libraries(emc_usb_test
    PUBLIC
      emc_usb
      emc_test
  )
endif()

target_sources(emc_usb PRIVATE
  Error.c
  EndpointAttributes.c
  emc_usb.c
)

add_subdirectory(request)
add_subdirectory(alloc)

if (EMC_USB_DRIVER_EP_CONTINUOUS_CHANNEL_SUPPORTED)
  add_subdirectory(iso)
endif()

if( EMC_TEST)
  add_subdirectory(test)
endif()


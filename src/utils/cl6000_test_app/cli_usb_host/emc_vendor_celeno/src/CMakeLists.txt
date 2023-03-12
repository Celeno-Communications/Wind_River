if(EMC_USB_ROLE_HOST)
  add_library(emc_usb_vendor_celeno_host INTERFACE)

  target_include_directories(emc_usb_vendor_celeno_host
    INTERFACE
      ${CMAKE_CURRENT_SOURCE_DIR}/../inc
  )
endif()

if(EMC_USB_ROLE_DEVICE OR (EMC_USB_VENDOR_CELENO_UMAC_APP STREQUAL "pcie"))
  add_subdirectory(device)
endif()

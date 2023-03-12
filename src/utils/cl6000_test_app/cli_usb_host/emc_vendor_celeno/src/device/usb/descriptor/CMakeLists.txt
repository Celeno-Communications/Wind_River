add_library(emc_vendor_celeno_device_usb_descriptor
  OBJECT
    DescriptorSet.c
    UniqueChipId.c
)
target_link_libraries(emc_vendor_celeno_device_usb_descriptor
  PUBLIC
    emc_vendor_celeno_device
    emc_usb_descriptor
)

if(EMC_TEST)
  add_subdirectory(test)
endif()

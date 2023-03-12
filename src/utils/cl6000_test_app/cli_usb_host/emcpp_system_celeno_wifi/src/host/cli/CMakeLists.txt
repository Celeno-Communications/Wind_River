add_library(cli_host)

target_sources(cli_host PRIVATE
  cli_legacy.c
  cli_usb.c
  )

target_include_directories(cli_host 
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../inc
)

target_link_libraries(cli_host
  PRIVATE
    emc_usb_vendor_celeno_cli_host
    emc_usb_vendor_celeno_cli_test
    emc_usb_host_hal_libusb
)

add_custom_target(libcli_usb
                  cp ${PROJECT_BINARY_DIR}/liball_libraries.a ${PROJECT_BINARY_DIR}/libcli_usb.a
                  DEPENDS HostGenericProtocol_functional_test all_libraries
                  DEPENDS all_libraries
)

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/../cl6000_fw_test CACHE PATH "..." FORCE)
endif()

add_custom_target(install_cli
                  COMMAND cp ${PROJECT_BINARY_DIR}/libcli_usb.a ${CMAKE_INSTALL_PREFIX}/cli
                  COMMAND cp ${PROJECT_BINARY_DIR}/emc_usb_vendor_celeno_cli/src/host/test/HostGenericProtocol_functional_test ${CMAKE_INSTALL_PREFIX}/cli
                  COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/../../../inc/emc/system/celeno/host/cli/cli.h ${CMAKE_INSTALL_PREFIX}/cli
                  COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/../../../inc/emc/system/celeno/host/cli/cli_usb.h ${CMAKE_INSTALL_PREFIX}/cli
                  COMMAND cp ${PROJECT_SOURCE_DIR}/emc_usb_vendor_celeno_wifi/inc/emc/usb/vendor/celeno/wifi/device/runtime/Statistics.h ${CMAKE_INSTALL_PREFIX}
                  DEPENDS libcli_usb
)

if (NOT libusb-1_FOUND)
  if (NOT "${LIB_USB_OFFLINE_DIR}" STREQUAL "")
    set(LIBUSB_HEADER_DIR ${LIB_USB_OFFLINE_DIR}/libusb)
  else ()
    set(LIBUSB_HEADER_DIR ${PROJECT_BINARY_DIR}/libusb-src/libusb)
  endif()
  add_custom_target(install_libusb
                    COMMAND cp ${PROJECT_BINARY_DIR}/external_libusb-1.0/libusb-1.0.a ${CMAKE_INSTALL_PREFIX}/cli
                    COMMAND mkdir -p ${CMAKE_INSTALL_PREFIX}/libusb-1.0/
                    COMMAND cp ${LIBUSB_HEADER_DIR}/libusb.h ${CMAKE_INSTALL_PREFIX}/libusb-1.0/
                    DEPENDS usb-1.0
  )
  add_dependencies(install_cli install_libusb)
endif()
if (NOT "${LIB_USB_OFFLINE_DIR}" STREQUAL "")
  include(${CMAKE_CURRENT_LIST_DIR}/eme/libusb-offline.cmake)
else()
  include(${CMAKE_CURRENT_LIST_DIR}/eme/libusb-download.cmake)
endif()

set (LIBUSB_BIN_DIR ${CMAKE_BINARY_DIR}/libusb-bin)
set (LIBUSB_SRC_DIR ${LIBUSB_DIR}/libusb)

configure_file(eme/config.h.in ${LIBUSB_BIN_DIR}/config.h ) 

add_library(usb-1.0 EXCLUDE_FROM_ALL) #is internaly libusb-1.0

target_include_directories(usb-1.0
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
    ${LIBUSB_SRC_DIR}
    ../${LIBUSB_SRC_DIR}
  PRIVATE
    ${LIBUSB_BIN_DIR}
    ${LIBUSB_SRC_DIR}/os
)

#target_link_libraries(usb-1.0
#  PUBLIC
#    udev
#)

# core
target_sources(usb-1.0
  PRIVATE
    ${LIBUSB_SRC_DIR}/core.c
    ${LIBUSB_SRC_DIR}/descriptor.c
    ${LIBUSB_SRC_DIR}/hotplug.c 
    ${LIBUSB_SRC_DIR}/io.c  
    ${LIBUSB_SRC_DIR}/strerror.c
    ${LIBUSB_SRC_DIR}/sync.c
  )

# platform
if(CMAKE_SYSTEM_NAME MATCHES "Linux")
  target_sources(usb-1.0
    PRIVATE
      ${LIBUSB_SRC_DIR}/os/events_posix.c
      ${LIBUSB_SRC_DIR}/os/threads_posix.c
      ${LIBUSB_SRC_DIR}/os/linux_usbfs.c
      #${LIBUSB_SRC_DIR}/os/linux_udev.c 
      ${LIBUSB_SRC_DIR}/os/linux_netlink.c 
  )
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  target_sources(usb-1.0
    PRIVATE
      ${LIBUSB_SRC_DIR}/os/events_windows.c
      ${LIBUSB_SRC_DIR}/os/threads_windows.c
      ${LIBUSB_SRC_DIR}/os/windows_common.c
      ${LIBUSB_SRC_DIR}/os/windows_usbdk.c 
      ${LIBUSB_SRC_DIR}/os/windows_winusb.c
  )
else()
endif()

target_compile_options(usb-1.0 PRIVATE 
  $<$<OR:$<C_COMPILER_ID:GNU>,$<C_COMPILER_ID:Clang>>:
  -Wno-switch-default
  -Wno-switch-enum
  -Wno-format
  -Wno-suggest-attribute=format
  -Wno-conversion
  -Wno-pedantic
>)
target_compile_options(usb-1.0 PRIVATE
  $<$<OR:$<AND:$<C_COMPILER_ID:GNU>,$<VERSION_GREATER:$<C_COMPILER_VERSION>,4.3.0>>,$<C_COMPILER_ID:Clang>>:
  -Wno-sign-conversion
  -Wno-declaration-after-statement
>)


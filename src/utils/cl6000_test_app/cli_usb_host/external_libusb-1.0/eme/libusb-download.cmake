include_guard(GLOBAL)

# currently this can't be done in the project specific usecase files
# it must be done in one of the options.cmake
# if never set LIBUSB_VERSION it defaults to "master"
#set(LIBUSB_VERSION "1.0.24")
#set(LIBUSB_VERSION "master")

if(LIBUSB_VERSION STREQUAL "1.0.24")
  set(LIBUSB_VERSION_TAG "v1.0.24" CACHE STRING "")
else()
  set(LIBUSB_VERSION "master")
  set(LIBUSB_VERSION_TAG "master" CACHE STRING "")
endif()

set (LIBUSB_DIR ${CMAKE_BINARY_DIR}/libusb-src CACHE STRING "")

if(LIBUSB_REPO_CACHE)
  set(LIBUSB_GIT_REPO ${LIBUSB_REPO_CACHE_REPO})
else()
  set(LIBUSB_GIT_REPO "https://github.com/libusb")
endif()

if(LIBUSB_PATCH)
  set(LIBUSB_PATCH_COMMAND git apply ${CMAKE_CURRENT_LIST_DIR}/${LIBUSB_PATCH})
else()
  set(LIBUSB_PATCH_COMMAND "")
endif()

message(STATUS "")
message(STATUS "[LIBUSB_GIT_REPO] ............ git repo for libusb .......... <${LIBUSB_GIT_REPO}/libusb.git>")
message(STATUS "[LIBUSB_VERSION_TAG] ......... libusb version ............... <${LIBUSB_VERSION_TAG}>")
message(STATUS "[LIBUSB_PATCH ] .............. optional patch ............... <${LIBUSB_PATCH}>")
#message(STATUS "[LIBUSB_PATCH_COMMAND ] ...... patch command ................ <${LIBUSB_PATCH_COMMAND}>")
message(STATUS "")

include(FetchContent)

FetchContent_Declare( libusb_download
    GIT_REPOSITORY    ${LIBUSB_GIT_REPO}/libusb.git
    GIT_TAG           ${LIBUSB_VERSION_TAG}
    SOURCE_DIR        ${CMAKE_BINARY_DIR}/libusb-src
    PATCH_COMMAND     ${LIBUSB_PATCH_COMMAND}
)

FetchContent_Populate(libusb_download)

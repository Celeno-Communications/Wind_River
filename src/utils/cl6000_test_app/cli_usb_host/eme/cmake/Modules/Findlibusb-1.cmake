# - Find libusb for portable USB support
# This module will find libusb as published by
#  http://libusb.sf.net and
#  http://libusb-win32.sf.net
#
# It will use PkgConfig if present and supported, else search
# it on its own. If the libusb-1_ROOT_DIR environment variable
# is defined, it will be used as base path.
# The following standard variables get defined:
#  libusb-1_FOUND:        true if libusb-1 was found
#  libusb-1_HEADER_FILE:  the location of the C header file
#  libusb-1_INCLUDE_DIRS: the directory that contains the include file
#  libusb-1_LIBRARIES:    the library

include ( CheckLibraryExists )
include ( CheckIncludeFile )

  find_file ( libusb-1_HEADER_FILE
    NAMES
      libusb-1.0/libusb.h
	PATHS
      $ENV{ProgramFiles}/libusb/include/
      $ENV{libusb-1_ROOT_DIR}
  )

  mark_as_advanced ( libusb-1_HEADER_FILE )
  # expecting libusb-1_HEADER_FILE to end with "libusb-1.0/libusb.h"
  # remove libusb.h
  get_filename_component ( libusb-1_INCLUDE_DIRS "${libusb-1_HEADER_FILE}" PATH )
  # remove libusb-1.0
  get_filename_component ( libusb-1_INCLUDE_DIRS "${libusb-1_INCLUDE_DIRS}" PATH )

  if ( ${CMAKE_SYSTEM_NAME} STREQUAL "Windows" )
    # libusb-1-Win32 binary distribution contains several libs.
    # Use the lib that got compiled with the same compiler.
    if ( MSVC )
      if ( WIN32 )
        set ( libusb-1_LIBRARY_PATH_SUFFIX MS32/static )
      else ( WIN32 )
        set ( libusb-1_LIBRARY_PATH_SUFFIX MS64/static )
      endif ( WIN32 )
    elseif ( CMAKE_COMPILER_IS_GNUCC )
      set ( libusb-1_LIBRARY_PATH_SUFFIX lib/gcc )
    endif ( MSVC )
  endif ( ${CMAKE_SYSTEM_NAME} STREQUAL "Windows" )

  find_library ( usb_LIBRARY
    NAMES
      libusb-1.0 usb-1.0 libusb usb
    PATHS
      $ENV{ProgramFiles}/libusb
      $ENV{libusb-1_ROOT_DIR}
    PATH_SUFFIXES
      ${libusb-1_LIBRARY_PATH_SUFFIX}
  )
  mark_as_advanced ( usb_LIBRARY )
  if ( usb_LIBRARY )
    set ( libusb-1_LIBRARIES ${usb_LIBRARY} )
  endif ( usb_LIBRARY )


if ( libusb-1_INCLUDE_DIRS AND libusb-1_LIBRARIES )
  set ( libusb-1_FOUND true )
endif ( libusb-1_INCLUDE_DIRS AND libusb-1_LIBRARIES )

if ( libusb-1_FOUND )
  set ( CMAKE_REQUIRED_INCLUDES "${libusb-1_INCLUDE_DIRS}" )
  check_include_file ( "{libusb-1_HEADER_FILE}" libusb-1_FOUND )
endif ( libusb-1_FOUND )

if ( libusb-1_FOUND )
  check_library_exists ( "${usb_LIBRARY}" usb_open "" libusb-1_FOUND )
  check_library_exists ( "${usb_LIBRARY}" libusb_get_device_list "" libusb-1_VERSION_1.0 )
endif ( libusb-1_FOUND )

if ( NOT libusb-1_FOUND )
  if ( NOT libusb-1_FIND_QUIETLY )
    message ( STATUS "libusb-1 not found, try setting libusb-1_ROOT_DIR environment variable." )
  endif ( NOT libusb-1_FIND_QUIETLY )
  if ( libusb-1_FIND_REQUIRED )
    message ( FATAL_ERROR "" )
  endif ( libusb-1_FIND_REQUIRED )
endif ( NOT libusb-1_FOUND )

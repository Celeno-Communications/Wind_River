# The following standard variables get defined:
#  Catena_FOUND:        true if Catena was found
#  Catena_HEADER_FILE:  the location of the C header file
#  Catena_INCLUDE_DIRS: the directory that contains the include file
#  Catena_LIBRARIES:    the library

include(CheckLibraryExists)
include(CheckIncludeFile)

cmake_print_variables(CMAKE_SOURCE_DIR)

find_file(Catena_HEADER_FILE
  NAMES
    catena1910hsic.h
  PATHS
    "${CMAKE_SOURCE_DIR}/external_mcci_catena/inc"
    "${Catena_ROOT_DIR}"
  NO_DEFAULT_PATH
)
mark_as_advanced(Catena_HEADER_FILE)
get_filename_component(Catena_INCLUDE_DIRS "${Catena_HEADER_FILE}" PATH)

find_library(Catena_LIBRARY
  NAMES
    catena1910hsic
  PATHS
    "${CMAKE_SOURCE_DIR}/external_mcci_catena/lib"
    "${Catena_ROOT_DIR}"
  NO_DEFAULT_PATH
)
mark_as_advanced(Catena_LIBRARY)

if(Catena_LIBRARY)
  set(Catena_LIBRARIES ${Catena_LIBRARY})
endif(Catena_LIBRARY)

if(Catena_INCLUDE_DIRS AND Catena_LIBRARIES)
  set(Catena_FOUND true)
endif(Catena_INCLUDE_DIRS AND Catena_LIBRARIES)

if(Catena_FOUND)
  set(CMAKE_REQUIRED_INCLUDES "${Catena_INCLUDE_DIRS}")
  check_include_file("{Catena_HEADER_FILE}" Catena_FOUND)
endif(Catena_FOUND)

if(Catena_FOUND)
  check_library_exists("${usb_LIBRARY}" McciAnalyzer_InitializeHardware "" Catena_FOUND)
endif(Catena_FOUND)

if(NOT Catena_FOUND)
  if(NOT Catena_FIND_QUIETLY)
    message(STATUS "Catena not found, try setting Catena_ROOT_DIR environment variable.")
  endif(NOT Catena_FIND_QUIETLY)
  if(Catena_FIND_REQUIRED)
    message (FATAL_ERROR "")
  endif(Catena_FIND_REQUIRED)
endif(NOT Catena_FOUND)

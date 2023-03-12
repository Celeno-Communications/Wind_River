
#cmake_minimum_required(VERSION 3.7)
#cmake_minimum_required(VERSION 3.12)
cmake_minimum_required(VERSION 3.13)

# confirm warnings about changes in newer versions
if (CMAKE_VERSION VERSION_GREATER 3.8.99)
    cmake_policy(SET CMP0069 NEW)
endif()    
if (CMAKE_VERSION VERSION_GREATER 3.13)
    cmake_policy(SET CMP0076 NEW)
endif()    

    

project(EmsysModules C CXX ASM)
include (eme/functions.cmake)
include (eme/load.cmake)
include (eme/coverage.cmake)

# system is not probed again when using a toolchain file
# therefore CYGWIN is not set in a second configuration run
# therefore we cache it if it is set in the first run
if(CYGWIN)
  set(CYGWIN TRUE CACHE BOOL "")
endif()

include (EmeAllLibraries)

# outputs a list of used include paths
set(include_dir_list_file "${CMAKE_CURRENT_BINARY_DIR}/include_dirs")
eme_get_target_includes_from_directory(modern_all_includes "${PROJECT_SOURCE_DIR}")
foreach(dir ${modern_all_includes})
  file(APPEND "${include_dir_list_file}" "${dir}\n")
endforeach()

# uses modern_all_includes variable from above
if(EME_TOOLSET_PATH MATCHES "msvc14|msvc15" )
  include(eme/vcxproj_generate.cmake OPTIONAL)
  eme_generate_vcxproj_import(modern_all_includes)
endif()

eme_add_all_libraries_target()


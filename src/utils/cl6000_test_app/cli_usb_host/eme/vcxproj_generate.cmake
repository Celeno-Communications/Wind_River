# Usage:
#  list(APPEND my_include_list "./inc")
#  eme_generate_vcxproj_import(my_include_list)
#
# ToDo: expects variable MODERN_ALL_LIBRARIES to be filled

function(eme_generate_vcxproj_import include_paths)
  #requires:
  # EME_WDK_PROJECT_DIR path where the vcxproj resides relative to CMAKE_SOURCE_DIR
  #   e.g. all_modules/emcpp_system_wdk10/eme/sample_driver.vcxproj -> EME_WDK_PROJECT_DIR = "emcpp_system_wdk10/eme"

  #uses following varibales in templates:
  # EME_WDK_DRIVER_BINARY_DIR equal to CMAKE_BINARY_DIR but converted to native path delimiters
  # EME_WDK_DRIVER_DEFINES semicolon separated list of defines
  # EME_WDK_DRIVER_ADDITIONAL_INCLUDE_DIRS semicolon separated list of include paths, uses path relative to vcproj, native path delimiter
  # EME_WDK_DRIVER_SOURCES string of '<ClCompile Include=\"main.cpp\" />\n', uses space as delimiter, uses path relative to vcproj, native path delimiter


  get_property(EME_WDK_DRIVER_DEFINES DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY COMPILE_DEFINITIONS)

  # make all include paths relative to the output directory
  # all modules get the same include paths
  set(result)
  foreach(entry ${${include_paths}})
    file(RELATIVE_PATH entry "${CMAKE_SOURCE_DIR}/${EME_WDK_PROJECT_DIR}" ${entry})
    # fix path delimiter for WPP Tracing
    file(TO_NATIVE_PATH ${entry} entry)
    list(APPEND result ${entry})
  endforeach()
  set(EME_WDK_DRIVER_ADDITIONAL_INCLUDE_DIRS ${result})

  # make each source path relative to the output directory
  set(EME_WDK_DRIVER_SOURCES "")
  foreach(lib ${MODERN_ALL_LIBRARIES})
    eme_libraries_sources(SOURCES ${lib})
    foreach(source ${SOURCES})
      file(RELATIVE_PATH entry "${CMAKE_SOURCE_DIR}/${EME_WDK_PROJECT_DIR}" ${source})
      # fix path delimiter for WPP Tracing
      file(TO_NATIVE_PATH ${entry} entry)
      set(EME_WDK_DRIVER_SOURCES "${EME_WDK_DRIVER_SOURCES}    <ClCompile Include=\"${entry}\" />\n")
    endforeach()
  endforeach()

  # place generated files nexto vcxproj files
  file(RELATIVE_PATH entry ${CMAKE_CURRENT_BINARY_DIR} "${CMAKE_SOURCE_DIR}/${EME_WDK_PROJECT_DIR}")
  file(RELATIVE_PATH EME_WDK_DRIVER_BINARY_DIR ${CMAKE_SOURCE_DIR}/${EME_WDK_PROJECT_DIR} ${CMAKE_BINARY_DIR})
  file(TO_NATIVE_PATH ${EME_WDK_DRIVER_BINARY_DIR} EME_WDK_DRIVER_BINARY_DIR)
  configure_file("eme/cmake/template/vcxproj_cmake_indirection.xml" "${entry}/cmake_indirection.xml" @ONLY)
  configure_file("eme/cmake/template/vcxproj_import_include_dirs_defines.xml" "${CMAKE_CURRENT_BINARY_DIR}/include_dirs_and_defines.xml" @ONLY)
  configure_file("eme/cmake/template/vcxproj_import_library_sources.xml" "${CMAKE_CURRENT_BINARY_DIR}/driver_lib_sources.xml" @ONLY)
endfunction()

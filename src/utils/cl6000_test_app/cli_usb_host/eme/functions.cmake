# only add functions and macros otherwise this can not be included when using script mode cmake -P

# use for debug only:
#message(STATUS "Included: eme/functions.cmake")

function(eme_trace trace_message filter)
  #message( "filter ${filter} , TRACE : ${TRACE}")
  if( ${TRACE} MATCHES  ${filter} )
    message(STATUS "${trace_message}")
  endif()
endfunction()

function(string_append var)
  foreach(v ${ARGN})
    set(${var} "${${var}} ${v}")
  endforeach(v)
  set(${var} "${${var}}" PARENT_SCOPE)
endfunction(string_append)

macro(eme_define_test)
    # usage eme_define_test( XXXTest LIBS emcpp_test emcpp_lib1 emcpp_lib2) 
    # must be called after declaring all source by eme_add_test_sources(XXXTest XX_test.cpp)
    # OPT_SRC_DIR if set start executable with src directory as working directory
    # LIBS all link libraries
    # WORKING_DIR working directory relative to current binary directory
    # SOURCES additional source files
    # ARGS commandline arguments 
  if(EMCPP_TEST)
        cmake_parse_arguments(TEST_PARAMS "OPT_SRC_DIR" "WORKING_DIR" "SOURCES;LIBS;ARGS" ${ARGN} )
    if ("${TEST_PARAMS_UNPARSED_ARGUMENTS}" STREQUAL "")
        message(FATAL_ERROR "missing test name in call to macro eme_define_test")
    endif()
    set(tst ${TEST_PARAMS_UNPARSED_ARGUMENTS})
    set(${tst}_SOURCES ${TEST_PARAMS_SOURCES})
    if ( ${tst}_SOURCES )    
        add_executable(${tst})
        target_sources(${tst} PRIVATE ${${tst}_SOURCES})
        target_link_libraries(${tst} PRIVATE ${TEST_PARAMS_LIBS})
        if(WIN32)
            add_test(NAME ${tst} COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${tst};${TEST_PARAMS_ARGS})
            set_tests_properties(${tst} PROPERTIES TIMEOUT 60)  
        else()
            add_test(NAME ${tst} COMMAND ${TEST_WRAPPER};${CMAKE_CURRENT_BINARY_DIR}/${tst};${TEST_PARAMS_ARGS} )
        endif()
        if (TEST_PARAMS_WORKING_DIR)
            set_tests_properties("${tst}" PROPERTIES WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/${TEST_PARAMS_WORKING_DIR}")
        endif()
        if (TEST_PARAMS_OPT_SRC_DIR)
            set_tests_properties("${tst}" PROPERTIES WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})
        endif()
        add_dependencies(check_apps ${tst})
        set(ALL_TESTS ${ALL_TESTS} ${tst} CACHE INTERNAL "")
        eme_get_current_module(_module)
        set_tests_properties("${tst}" PROPERTIES LABELS ${_module})
    else()
        message(STATUS "skip empty test ${tst}, no sources declared by eme_add_test_sources()" ) 
    endif()
  endif()
endmacro(eme_define_test tst)

set(TEST_WRAPPER ${PROJECT_SOURCE_DIR}/eme/bin/run_test.sh)

macro(eme_add_test test)
  if(WIN32)
    add_test(NAME ${test}
             COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${test})
    set_tests_properties(${test} PROPERTIES TIMEOUT 30)
  else()
    add_test(NAME ${test}
             COMMAND ${TEST_WRAPPER};${CROSS_TARGET_SIMULATOR};${CMAKE_CURRENT_BINARY_DIR}/${test})
  endif()
  add_dependencies(check_apps ${test})
  set(ALL_TESTS ${ALL_TESTS} ${test} CACHE INTERNAL "")
  eme_get_current_module(_module)
  set_tests_properties("${test}" PROPERTIES LABELS ${_module})
endmacro(eme_add_test)

macro(eme_add_test_with_arguments test)
  add_test(NAME ${test}
           COMMAND ${TEST_WRAPPER};${CMAKE_CURRENT_BINARY_DIR}/${test};${ARGN})
  add_dependencies(check_apps ${test})
  set(ALL_TESTS ${ALL_TESTS} ${test} CACHE INTERNAL "")
  eme_get_current_module(_module)
  set_tests_properties("${test}" PROPERTIES LABELS ${_module})
endmacro()

#usage: eme_add_prefix(result prefix list-item1 list-item2 ...)
macro(eme_add_prefix result prefix)
  set(${result})
  foreach(v ${ARGN})
    list(APPEND ${result} "${prefix}${v}")
  endforeach()
endmacro()

#usage: eme_add_suffix(result suffix list-item1 list-item2 ...)
macro(eme_add_suffix result suffix)
  set(${result})
  foreach(v ${ARGN})
    list(APPEND ${result} "${v}${suffix}")
  endforeach()
endmacro()

macro(eme_get_current_module var)
  file(RELATIVE_PATH ${var} ${PROJECT_SOURCE_DIR} ${CMAKE_CURRENT_LIST_DIR})
  string(REGEX REPLACE "/.*" "" ${var} ${_module} )
endmacro()

#usage eme_add_prerequisites(prereq1 prereq2 ...)
macro(eme_add_prerequisites)
  foreach(m ${ARGV})
    list(FIND EME_EXCLUDED_MODULES ${m} found)
    if(found EQUAL -1)
      list(APPEND MODULES ${m})
    endif()
  endforeach()
  eme_get_current_module(_module)
  foreach( m ${ARGV})
    eme_trace( "${_module} -> ${m}" "dependencies")
    set(_dependency_graph "${_dependency_graph};${_module} -> ${m}" CACHE INTERNAL "store module dependencies for later use")
  endforeach()
endmacro()

function(eme_print_list lst)
  # check if list is empty before using it
  if(NOT ("${${lst}}" STREQUAL ""))
    list(SORT ${lst})
    foreach(l ${${lst}})
      message("  ${l}")
    endforeach()
  endif()
endfunction()

function(eme_print_list lst filter)
  # check if list is empty before using it
  if(NOT ("${${lst}}" STREQUAL ""))
    list(SORT ${lst})
    foreach(l ${${lst}})
      eme_trace("  ${l}" ${filter})
    endforeach()
  endif()
endfunction()

function(eme_set_list_option list_option)
  # check if list was already cleared
  list(FIND RESET_LIST_OPTIONS ${list_option} index)

  if(index EQUAL -1)
    # not found, initialy clear list for this run
    unset(${list_option} CACHE)
    list(APPEND RESET_LIST_OPTIONS ${list_option})
  endif()

  list(APPEND ${list_option} ${ARGN})
  list(REMOVE_DUPLICATES ${list_option})
  set(${list_option} ${${list_option}} CACHE STRING "" FORCE)
  set(RESET_LIST_OPTIONS ${RESET_LIST_OPTIONS} PARENT_SCOPE)
endfunction()

# get source file of a list of libraries
# paths are absolute
# usage: eme_libraries_sources(result lib1 [lib2 ...])
macro(eme_libraries_sources result)
  set(${result})
  foreach(lib ${ARGN})
    get_property(target_sources TARGET ${lib} PROPERTY SOURCES)
    #message("### sources ${target_sources}")
    get_target_property(target_sources_dir ${lib} SOURCE_DIR)
    foreach(target_source ${target_sources})
      if (NOT IS_ABSOLUTE ${target_source})
        set(target_source "${target_sources_dir}/${target_source}")
      endif()
     #message("# source ${target_source}")
     #message("# source_dir ${target_sources_dir}")
      list(APPEND ${result} ${target_source})
    endforeach()
  endforeach()
endmacro()

# convert absolute pathes below working dir to relative path entries, reference path is working dir
# usage: eme_path_abs_to_relative(result source1 source 2 ...
macro(eme_path_abs_to_relative result)
  set(cwd ${PROJECT_SOURCE_DIR})
  set(${result})
  foreach(entry ${ARGN})
    file(RELATIVE_PATH entry ${cwd} ${entry})
    list(APPEND ${result} ${entry})
  endforeach()
endmacro()

macro(eme_add_compile_fail_test test)
  add_executable(${test} EXCLUDE_FROM_ALL ${ARGN})
  add_test(NAME "${test}"
         COMMAND ${CMAKE_COMMAND} --build . --target ${test}
         WORKING_DIRECTORY ${PROJECT_BINARY_DIR})
  set_tests_properties("${test}" PROPERTIES WILL_FAIL TRUE)
  # label to exclude them from testing via ctest test -LE "^XFAIL$"
  eme_get_current_module(_module)
  set_tests_properties("${test}" PROPERTIES LABELS "${_module};XFAIL")
endmacro()

macro(eme_get_subdirectory_list RESULT_LIST STARTDIR)
  file(GLOB nodes RELATIVE ${STARTDIR} ${STARTDIR}/*)
  set(directories "")
  foreach(node ${nodes})
    if(IS_DIRECTORY ${STARTDIR}/${node})
        list(APPEND directories ${node})
    endif()
  endforeach()
  set(${RESULT_LIST} ${directories})
endmacro()

#return true if a variable matches with the provided prefix and is set to true
#e.g. prefix = "EMCPP_USB_DEVICE_CLASS_CDC" matches "EMCPP_USB_DEVICE_CLASS_CDC_ACM"
#and "EMCPP_USB_DEVICE_CLASS_CDC_ACM" = TRUE
#return true
macro(eme_is_prefixed_variable_set prefix result)
  set(variableNames "")
  set(return_value FALSE)
  get_cmake_property(_variableNames VARIABLES)
  if(NOT (${prefix} STREQUAL ""))
    foreach (_variableName ${_variableNames})
      if("${_variableName}" MATCHES "${prefix}")
        if(${_variableName})
          set(return_value TRUE)
        endif()
      endif()
    endforeach()
  endif()
  SET(${result} ${return_value})
endmacro()

#eme_add_parser_test (macro below)
# this macro tests the output of the specified parser with a easy diffscript.
# the script can be found in eme/bin/xmldiff.sh
# app_path -> parsing application (path)
# app_name _> parsing application name to set the dependencie
# file1 -> reference file
# file2 -> output file of the parser
# script_path -> path to script
# target_name -> name of the test that should be executed
macro(eme_add_parser_test app_name file1 file2 script_path target_name)
  add_test(NAME "${target_name}"
    COMMAND ${CMAKE_COMMAND}
    -Dapp_path=$<TARGET_FILE:${app_name}>
    -Dfile1=${file1}
    -Dfile2=${file2}
    -Dscript_path=${script_path}
    -P ${PROJECT_SOURCE_DIR}/eme/bin/${app_name}_test_script.cmake
  )
#   set_tests_properties(${target_name}_script PROPERTIES DEPENDS ${target_name})
  add_dependencies(check_apps ${app_name})
endmacro(eme_add_parser_test)

function(eme_create_zip_from_file_list FILENAME FILELIST)
  file(TO_NATIVE_PATH ${FILENAME} file_name)
  execute_process(COMMAND ${CMAKE_COMMAND} -E tar cf "${file_name}" --format=zip -- ${${FILELIST}}
  RESULT_VARIABLE result
  )
  if(result EQUAL 0)
    message(STATUS "Generated ${file_name}.")
  else()
    message(WARNING "Could not generate ${file_name}.")
  endif()
endfunction()

# Note: cmake 3.6 has list(FILTER)
# removes entries matching FILTER_REGEX from LIST_TO_FILTER
function(eme_filter_list LIST_TO_FILTER FILTER_REGEX)
  set(new_list)
  foreach(value ${${LIST_TO_FILTER}})
    if(value MATCHES "${FILTER_REGEX}")
      message("Filtered ${value}.")
    else()
      list(APPEND new_list ${value})
    endif()
  endforeach()
  set(${LIST_TO_FILTER} ${new_list} PARENT_SCOPE)
endfunction()

# Verifies that actually used compiler matches the one the toolset is supposed to use and
# breaks if does not.
function(eme_require_gnu_compiler_version major)
  if(NOT CMAKE_C_COMPILER_ID STREQUAL "GNU")
    message(FATAL_ERROR "Found C compiler is not a GCC derivative!")
  else()
    if(NOT CMAKE_C_COMPILER_VERSION MATCHES "^${major}\.")
      message(FATAL_ERROR "Found C compiler does not match compiler version of selected toolset!")
    endif()
  endif()
  if(NOT CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message(FATAL_ERROR "Found C++ compiler is not a GCC derivative!")
  else()
    if(NOT CMAKE_CXX_COMPILER_VERSION MATCHES "^${major}\.")
      message(FATAL_ERROR "Found C++ compiler does not match compiler version of selected toolset!")
    endif()
  endif()
endfunction(eme_require_gnu_compiler_version)

# Intended for use by customers.
# Add all include directories of emsys subproject to the include directories in caller scope.
function(emsys_include_directories)
  get_directory_property(includes DIRECTORY "${EmsysModules_SOURCE_DIR}" INCLUDE_DIRECTORIES)
  include_directories(${includes})
endfunction()

# Provides footprint analysis of target executable
# (Works only for GCC/LLVM Linker)
function(eme_analyze_executable)
  if (NOT ${Python_FOUND})
    message(WARNING "python interpreter not available")
    return()
  endif()
  set(supported_compiler GNU Clang)
  if (NOT ((${CMAKE_C_COMPILER_ID} IN_LIST supported_compiler) OR (${CMAKE_CXX_COMPILER_ID} IN_LIST supported_compiler)))
    message(STATUS "Ignoring eme_analyze_executable(${ARGV}).")
    message(STATUS "  Function has no supported for compiler C-${CMAKE_C_COMPILER_ID}/CXX-${CMAKE_C_COMPILER_ID}")
    message(STATUS "  (only supports C/CXX-${supported_compiler}).")
  else()
    foreach(exe ${ARGV})
      target_link_options(${exe} PRIVATE -Wl,--cref -Wl,--Map=${CMAKE_CURRENT_BINARY_DIR}/${exe}.map.txt)
      add_custom_command(TARGET ${exe} POST_BUILD
        COMMAND ${Python_EXECUTABLE} ${CMAKE_SOURCE_DIR}/eme/bin/gcc_map_analyze.py ${exe}.map.txt > ${exe}.map.analyzed.txt
        COMMAND echo "Map file analysis saved to ${CMAKE_CURRENT_BINARY_DIR}/${exe}.map.analyzed.txt"
        BYPRODUCTS ${exe}.map.txt ${exe}.map.analyzed.txt
      ) 
    endforeach()
  endif()
endfunction() 

# bundles given static-libraries into one single static lib
# e.g. bundle_libs(libbase.a LIBS emc_hw_memory emc_log emc_std)
function(bundle_libs LIB)
  set(multiValueArgs LIBS)
  cmake_parse_arguments(bundle_libs "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})
  message("Bundling ${LIB} <= ${bundle_libs_LIBS}")

  foreach(l IN LISTS bundle_libs_LIBS)
    list(APPEND LIB_FILES $<TARGET_FILE:${l}>)
  endforeach()

  add_custom_target(${LIB}
    COMMAND ${CMAKE_SOURCE_DIR}/eme/bin/bundle_libs.sh ${CMAKE_BINARY_DIR}/${LIB} ${LIB_FILES}
    DEPENDS ${bundle_libs_LIBS}
    COMMENT "Bundling ${LIB} ..."
    VERBATIM
  )
endfunction()

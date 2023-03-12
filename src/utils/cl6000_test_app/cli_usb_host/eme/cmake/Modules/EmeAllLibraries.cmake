# include once
include_guard(GLOBAL)


# Declare executable linking with single library all_libraries
# generates two targets
#  <TARGET> links with statlic library all_libraries
#  <TARGET>_whole links with -Wl,-whole-archive all_libraries -Wl,-no-whole-archive
#
#  whole-archive use as sanity check to find duplicate symbols in single library
#
# usage
#    eme_add_all_libraries_executable(
#        TARGET usb_server_embos_single_lib.elf
#        SOURCES "server_embos.c"
#        EXTRA_LIBS "ipc-common;ipc-embos"
#        LINK_OPTIONS "-T;${CMAKE_CURRENT_LIST_DIR}/../system/MIMX8MQ6xxxJZ_cm4_ddr_ram_emsys.ld;--specs=nano.specs"
#    )
function(eme_add_all_libraries_executable)
  cmake_parse_arguments(ALL_LIBRARIES_EXE_PARAMS "" "TARGET" "SOURCES;EXTRA_LIBS;LINK_OPTIONS" ${ARGN} )
  if (ALL_LIBRARIES_EXE_PARAMS_UNPARSED_ARGUMENTS)
      message(FATAL_ERROR "Unexpected ARGUMENTS ${ALL_LIBRARIES_EXE_PARAMS_UNPARSED_ARGUMENTS}")
  endif()

  # target linking all_libraries
  set(exec_name ${ALL_LIBRARIES_EXE_PARAMS_TARGET})
  add_executable(${exec_name} ${ALL_LIBRARIES_EXE_PARAMS_SOURCES})
  target_link_libraries(${exec_name} all_libraries ${ALL_LIBRARIES_EXE_PARAMS_EXTRA_LIBS})
  target_link_options(${exec_name} PRIVATE ${ALL_LIBRARIES_EXE_PARAMS_LINK_OPTIONS})

  # target linking whole-archive all_libraries
  set(exec_name_whole ${exec_name}_whole)
  add_executable(${exec_name_whole} ${ALL_LIBRARIES_EXE_PARAMS_SOURCES})
  target_link_libraries(${exec_name_whole} -Wl,-whole-archive all_libraries -Wl,-no-whole-archive ${ALL_LIBRARIES_EXE_PARAMS_EXTRA_LIBS})
  target_link_options(${exec_name_whole} PRIVATE ${ALL_LIBRARIES_EXE_PARAMS_LINK_OPTIONS})

  # force sanity check when single library executable is used
  add_dependencies(${exec_name} ${exec_name_whole})
endfunction()



macro(get_all_targets_recursive targets dir)
  get_property(subdirectories DIRECTORY ${dir} PROPERTY SUBDIRECTORIES)
  foreach(subdir ${subdirectories})
    get_all_targets_recursive(${targets} ${subdir})
  endforeach()

  get_property(current_targets DIRECTORY ${dir} PROPERTY BUILDSYSTEM_TARGETS)
  list(APPEND ${targets} ${current_targets})
endmacro()

# Generate list of targets in ${dir} and subdirectories.
# The list does not include any Imported Targets or Alias Targets, but does include Interface Libraries.
# Must be called after creation of relevant targets.
function(eme_get_targets_from_directory var dir)
  set(targets)
  get_all_targets_recursive(targets "${dir}")
  set(${var} ${targets} PARENT_SCOPE)
endfunction()


# Generate list includes of targets in ${dir} and subdirectories.
# Must be called after creation of relevant targets.
function(eme_get_target_includes_from_directory var dir)
  set(modern_includes)
  eme_get_targets_from_directory(targets "${dir}")
  foreach(tgt ${targets})
    get_target_property(target_type ${tgt} TYPE)
    if(target_type MATCHES "INTERFACE_LIBRARY")
      get_target_property(target_include ${tgt} INTERFACE_INCLUDE_DIRECTORIES)
    else()
      get_target_property(target_include ${tgt} INCLUDE_DIRECTORIES)
    endif()
    get_filename_component(abs_target_include_path "${target_include}" ABSOLUTE)
    list(APPEND modern_includes ${abs_target_include_path})
  endforeach()
  list(REMOVE_DUPLICATES modern_includes)
  set(${var} ${modern_includes} PARENT_SCOPE)
endfunction()

# Use case:
#  Used with include_dirs feature to simplify use in external projects (single lib + include dirs).
#
# Warning: If symbol is duplicated in static library, first symbol found by linker wins.
# Change of object order in the static library changes which symbols is found first.
# GNU ar does not generate warnings in this case.
#
# Safeguard: use --whole-archive when linking with ld to generate duplicate symbols error
# See eme_add_all_libraries_executable().
#
# Sources of static libraries from list ALL_LIBRARIES_EXCLUDE_TARGETS are not added to all_libraries.

function(eme_add_all_libraries_target)
  set(MODERN_ALL_LIB_SOURCES_ABS_PATH)
  set(MODERN_EXTRA_COMPILE_DEFINITIONS)
  eme_get_targets_from_directory(targets "${PROJECT_SOURCE_DIR}")
  foreach(lib ${targets})
      # dummy target for QtCreator
      if("${lib}" STREQUAL "dummy_headers")
        continue()
      endif()

      get_target_property(target_type ${lib} TYPE)
      if(target_type MATCHES "STATIC_LIBRARY|OBJECT_LIBRARY")
        # check if marked for exclusion from all_libraries
        
        if("${lib}" IN_LIST ALL_LIBRARIES_EXCLUDE_TARGETS)
          #message("all_libraries skipped ${lib}")
          continue()
        endif()

        # get public defines for targets
        get_target_property(extra_compile_definitions ${lib} INTERFACE_COMPILE_DEFINITIONS)
        if(extra_compile_definitions)
          list(APPEND MODERN_EXTRA_COMPILE_DEFINITIONS ${extra_compile_definitions})
        endif()

        get_target_property(lib_target_compile_options ${lib} COMPILE_OPTIONS)
        #message("${lib} ${lib_target_compile_options}")

        get_property(sourcefiles TARGET ${lib} PROPERTY SOURCES)
        foreach(sourcefile ${sourcefiles})
          # if path does not exist assume relative path and covert to absolute path
          if(NOT EXISTS "${sourcefile}")
            get_target_property(target_source_dir ${lib} SOURCE_DIR)
            get_filename_component(sourcefile "${sourcefile}" ABSOLUTE BASE_DIR "${target_source_dir}")
          endif()
          if (lib_target_compile_options)
            set_source_files_properties(${sourcefile} PROPERTIES COMPILE_OPTIONS "${lib_target_compile_options}")
          endif()
          list(APPEND MODERN_ALL_LIB_SOURCES_ABS_PATH "${sourcefile}")
        endforeach()
      endif()
  endforeach()

  #message("ALL_LIB_SOURCES_ABS_PATH ${ALL_LIB_SOURCES_ABS_PATH}")
  #message("ALL_LIB_SOURCES_ABS_PATH_MODERN ${MODERN_ALL_LIB_SOURCES_ABS_PATH}")

  if(NOT MODERN_ALL_LIB_SOURCES_ABS_PATH)
    set(MODERN_ALL_LIB_SOURCES_ABS_PATH "${PROJECT_SOURCE_DIR}/eme/empty.cpp")
  endif()



  add_library(all_libraries STATIC EXCLUDE_FROM_ALL ${MODERN_ALL_LIB_SOURCES_ABS_PATH})
  target_include_directories(all_libraries PUBLIC ${modern_all_includes})
  target_compile_definitions(all_libraries PUBLIC ${MODERN_EXTRA_COMPILE_DEFINITIONS})
endfunction()

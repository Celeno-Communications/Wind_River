set (pthreads-win32_search_paths "" CACHE INTERNAL "tmp")
set (pthreads-win32_search_paths ${pthreads-win32_search_paths} 
  "C:/Program Files*/pthreads-w32*/" 
  "${CMAKE_SOURCE_DIR}/../extern/emsys/external/pthreads-w32*/"
CACHE INTERNAL "tmp")


include(${CMAKE_ROOT}/Modules/FindPackageHandleStandardArgs.cmake)

function( _pthreads_win32_GET_VERSION  header )
    set(_pthreads-win32_test_version "" PARENT_SCOPE)
    #message("file: ${header} ")
    file(STRINGS ${header} _contents REGEX "^[ \t]*#define PTW32_VERSION .*")
    #message("_contents: ${_contents} ")
    if(_contents)
        string(REGEX REPLACE "#define PTW32_VERSION[^0-9]*" "" _contents "${_contents}")
        string(REPLACE "," "." _contents "${_contents}")
        set(_pthreads-win32_test_version ${_contents} PARENT_SCOPE)
    else()
        message(FATAL_ERROR "Include file ${header} does not exist or does not contain expected version information")
    endif()
endfunction()

function (_print msg)
    IF (NOT pthreads-win32_FIND_QUIETLY)
      message(STATUS "${msg}")
    endif()
endfunction()


#if(NOT pthreads-win32_FOUND)
  set(_pthreads-win32_best_version "0.0.0.0")
  set(_pthreads-win32_best_dir "")
  foreach(searchpath IN LISTS pthreads-win32_search_paths )
    file(GLOB pthreads-win32_INCLUDE_DIR "${searchpath}/include/pthread.h")
    foreach(f IN LISTS pthreads-win32_INCLUDE_DIR )
        _pthreads_win32_GET_VERSION( "${f}" )
        _print("current: ${f}   v:${_pthreads-win32_test_version}")
        if (NOT _pthreads-win32_FIND_VERSION_EXACT)
            if ( ${_pthreads-win32_test_version} VERSION_GREATER ${_pthreads-win32_best_version}  )
              set(_pthreads-win32_best_version ${_pthreads-win32_test_version})
              set(_pthreads-win32_best_dir "${f}")
              _print("best: ${_pthreads-win32_best_dir}")
            endif()
        else()
          if ("${pthreads-win32_FIND_VERSION_MAJOR}.${pthreads-win32_FIND_VERSION_MINOR}.${pthreads-win32_FIND_VERSION_PATCH}" VERSION_EQUAL _pthreads-win32_test_version)
              set(_pthreads-win32_best_version ${_pthreads-win32_test_version})
              set(_pthreads-win32_best_dir "${f}")
              _print("best: ${_pthreads-win32_best_dir}")
          endif()
        endif()
    endforeach()
  endforeach()
  if (NOT ${_pthreads-win32_best_version} VERSION_EQUAL "0.0.0" )
    set(pthreads-win32_FOUND true)
    set(pthreads-win32_VERSION ${_pthreads-win32_best_version})
    unset(pthreads-win32_INCLUDE_DIR)
    get_filename_component(pthreads-win32_INCLUDE_DIR ${_pthreads-win32_best_dir} DIRECTORY CACHE)
    get_filename_component(pthreads-win32_ROOT_DIR ${pthreads-win32_INCLUDE_DIR} DIRECTORY CACHE)
    set(pthreads-win32_LIBRARY "${pthreads-win32_ROOT_DIR}/lib/x86/pthreadVCE2.lib")
    set(pthreads-win32_DLL "${pthreads-win32_ROOT_DIR}/dll/x86/pthreadVCE2.dll")
    if (NOT EXISTS ${pthreads-win32_LIBRARY})
     unset(pthreads-win32_LIBRARY)
    endif()
    if (NOT EXISTS ${pthreads-win32_DLL})
     unset(pthreads-win32_DLL)
    endif()
  endif()
   if(NOT pthreads-win32_FOUND)
      message(STATUS "pthreads-win32 not found, searched in :")
      foreach(searchpath IN LISTS pthreads-win32_search_paths )
        message(STATUS "    ${searchpath}")
      endforeach()
  endif()   
  
  FIND_PACKAGE_HANDLE_STANDARD_ARGS("pthreads-win32"
                                  FOUND_VAR "pthreads-win32_FOUND"
                                  REQUIRED_VARS "pthreads-win32_LIBRARY"
                                                "pthreads-win32_DLL"
                                                "pthreads-win32_INCLUDE_DIR"
                                                "pthreads-win32_VERSION"
                                  VERSION_VAR "pthreads-win32_VERSION"
                                  FAIL_MESSAGE "Failed to find pthreads-win32" )
    
#endif()



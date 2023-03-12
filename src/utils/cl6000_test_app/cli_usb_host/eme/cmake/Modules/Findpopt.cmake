# modified from original:
# https://github.com/se-research/OpenDaVINCI/blob/master/automotive/cmake.Modules/Findpopt.cmake
# changed names to popt_XXX
# popt_FOUND
# popt_INCLUDE_DIR 
# popt_LIBRARIES

if(NOT popt_FOUND)
    find_path(popt_INCLUDE_DIR
        NAMES "popt.h"
        PATHS "${LIBPOPT_PATH}/include/"
              "/usr/local/include/"
              "/usr/include/"
    )

    find_library(popt_LIBRARIES
        NAMES "popt" "popt0" "popt.so.0" "libpopt.so.0"
        PATHS "/lib/i386-linux-gnu/" "/usr/lib"
    )

    if(popt_INCLUDE_DIR AND popt_LIBRARIES)
        set (popt_FOUND TRUE)
        if (CYGWIN)
            # on cygwin popt has dependencies to libintl and libiconv 
            set(popt_LIBRARIES ${popt_LIBRARIES} -lintl -liconv)
        endif()
    endif()

    if(popt_FOUND)
        # FIXME The include path printed here is not necessarily the one that is actually used!
        #       E.g., this message says "/usr/include", but when cross-compiling, it is really
        #       included from "TOOLCHAIN_DIR/include". 
        message(STATUS "Found libpopt include (${popt_INCLUDE_DIR}) and lib (${popt_LIBRARIES}).")
    else()
        if(popt_FIND_REQUIRED)
            message(FATAL_ERROR "Could not find libpopt. Please set LIBPOPT_PATH accordingly.")
        else()
            message(STATUS "Could not find libpopt (optional).")
        endif()
    endif()
endif()
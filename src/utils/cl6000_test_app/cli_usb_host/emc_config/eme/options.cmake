option(CUSTOMER_CONFIGURE "" FALSE)
set(EMC_BASE_MAX_FRAME "2048" CACHE STRING "0 (=unlimited) or a number of bytes.")
option(EMC_SOURCEDIST "" FALSE)

set(EMC_INLINE "" CACHE STRING "")
set_property(CACHE EMC_INLINE PROPERTY STRINGS "NO" "INLINE" "MACRO")

option(EMC_PRINT "" FALSE)

if(CMAKE_CROSSCOMPILING)
  option(EMC_TEST "" FALSE)
else()
  option(EMC_TEST "" TRUE)
endif()

option(EMC_EXTERNAL_MOCK "" FALSE)

option(EMC_ENABLE_VERSION_INFORMATION "" TRUE)

# Generate debugging information
option(PROJECT_BUILD_DEBUG "" FALSE)

# Generate Position Independent Code (PIC)
option(PROJECT_BUILD_PIC "" FALSE)

option(PROJECT_LINK_DYNAMIC "" FALSE)
set(PROJECT_DYNAMIC_LOADER "" CACHE STRING "Override location of dynamic library loader on target system")
set(PROJECT_SHARED_OBJECT_NAME "allmodules" CACHE STRING "Name of combined shared library when linking dynamically")
option(PROJECT_COMPILER_EMBEDDED "" FALSE)
option(PROJECT_COMPILER_ENUM_IS_INT "" FALSE)
option(PROJECT_COMPILER_FUNCTION_SECTIONS "" TRUE)
option(PROJECT_COVERAGE "" FALSE)
set(PROJECT_CPU "ARM1176JZ-S" CACHE STRING "")

set(PROJECT_CPU_ENDIANESS "LITTLE" CACHE STRING "")
set_property(CACHE PROJECT_CPU_ENDIANESS PROPERTY STRINGS "LITTLE" "BIG")

set(PROJECT_SANITIZER "none" CACHE STRING "Sanitizer code instrumentation (if supported by compiler)")
set_property(CACHE PROJECT_SANITIZER PROPERTY STRINGS "none" "asan" "lsan" "msan" "tsan" "ubsan")

set(PROJECT_OPTIMIZATION_MODE "default" CACHE STRING "Optimization mode")
set_property(CACHE PROJECT_OPTIMIZATION_MODE PROPERTY STRINGS "none" "default" "size")

set(PROJECT_COMPILER_MSC_WDK_VER "0" CACHE STRING "")
set_property(CACHE PROJECT_COMPILER_MSC_WDK_VER PROPERTY STRINGS
  "0" # UserMode
  "10010586" # Windows Kit 10.0.10586
)

set(PROJECT_CPU_VERSION "thumb" CACHE STRING "")
set_property(CACHE PROJECT_CPU_VERSION PROPERTY STRINGS "arm" "thumb")

set(EMC_CUSTOMER_CONFIG "" CACHE STRING "")


eme_add_prerequisites(external_freertos_kernel)

set(EMC_STD_MUTEX      "freertos" CACHE STRING "")
set(EMC_STD_SPINLOCK   "freertos" CACHE STRING "")
set(EMC_STD_TIMESTAMP  "freertos" CACHE STRING "")

if (CMAKE_SYSTEM_NAME STREQUAL "Generic")
  set(FREERTOS_PORT XCC_XTENSA CACHE STRING "")
endif()
if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
  set(FREERTOS_PORT GCC_POSIX CACHE STRING "")
endif()

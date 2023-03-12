eme_add_prerequisites(
  emc_system
  emc_std_ext
  emc_std_thread
  emc_log
)

set(EMC_LOG "EMCPP" CACHE STRING "")

option(EMCPP_TEST "" TRUE)
option(EMC_TEST "" TRUE)

set(EMC_STD_TIMESTAMP  "freertos" CACHE STRING "" FORCE)
set(EMC_STD_MUTEX      "freertos" CACHE STRING "" FORCE)
set(EMC_STD_SPINLOCK   "freertos" CACHE STRING "" FORCE)
set(EMC_STD_ATOMIC     "EMULATE" CACHE STRING "")


set(FREERTOS_PORT GCC_POSIX CACHE STRING "")
set(FREERTOS_CONFIG_FILE_DIRECTORY ${CMAKE_SOURCE_DIR}/emcpp_system_celeno_wifi/src/freertos/posix CACHE STRING "")
set(EMCPP_SINGLETON_GUARD "NO" CACHE STRING "")
option(EMC_MEMORY_POOL_TYPE_TLSF "" TRUE)
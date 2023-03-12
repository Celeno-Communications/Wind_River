message(STATUS "")
message(STATUS "emc_config                   Description                    Value")
message(STATUS "---------------------------- ------------------------------ -----")
message(STATUS "[EMC_TEST] ................. C tests enabled .............. <${EMC_TEST}>")
message(STATUS "[EMC_PRINT] ................ C pretty printing enabled .... <${EMC_PRINT}>")

configure_file(eme/cmakeConfigure.h.in cmakeConfigure.h)

add_subdirectory(src)


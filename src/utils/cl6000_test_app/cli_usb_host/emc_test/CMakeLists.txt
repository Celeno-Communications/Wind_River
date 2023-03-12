message(STATUS "")
message(STATUS "emc_test                     Description                    Value")
message(STATUS "---------------------------- ------------------------------ -----")
message(STATUS "[EMC_TEST_WRAPPER] ......... C generic test wrapper ....... <${EMC_TEST_WRAPPER}>")
message(STATUS "[EMC_TEST_NATIVE_SIMPLE] ... C simple test framework ...... <${EMC_TEST_NATIVE_SIMPLE}>")

configure_file(eme/cmakeConfigure.h.in cmakeConfigure.h)

add_subdirectory(src)


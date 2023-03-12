option(EMC_TEST_NATIVE_SIMPLE "" TRUE)

if(CMAKE_C_COMPILER_ID MATCHES "GNU|Intel|MSVC|Clang")
  set(EMC_TEST_WRAPPER "CUNIT" CACHE STRING "")
else()
  set(EMC_TEST_WRAPPER "SIMPLE" CACHE STRING "")
endif()

set_property(CACHE EMC_TEST_WRAPPER PROPERTY STRINGS SIMPLE CUNIT CHECK)

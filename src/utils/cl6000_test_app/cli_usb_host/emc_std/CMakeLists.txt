message(STATUS "")
message(STATUS "emc_std                      Description                    Value")
message(STATUS "---------------------------- ------------------------------ -----")
message(STATUS "[EMC_STD] .................. C std implementation ......... <${EMC_STD}>")
message(STATUS "[EMC_STD_ASSERT] ........... C assert implementation ...... <${EMC_STD_ASSERT}>")

if(EMC_STD_ASSERT STREQUAL "STD")
  message(STATUS "[EMC_STD_ASSERT_ABI] ....... C assert ABI used ............ <${EMC_STD_ASSERT_ABI}>")
endif()

if(EMC_STD_ASSERT STREQUAL "EMULATE")
  message(STATUS "[EMC_STD_ASSERT_IMPL] ...... C assert implementation ...... <${EMC_STD_ASSERT_IMPL}>")
  message(STATUS "[EMC_STD_ASSERT_SRC_POS] ... C assert source position ..... <${EMC_STD_ASSERT_SRC_POS}>")
  message(STATUS "[EMC_STD_ASSERT_CONTEXT] ... C assert context ............. <${EMC_STD_ASSERT_CONTEXT}>")
  message(STATUS "[EMC_STD_ASSERT_MESSAGE] ... C assert message parameter ... <${EMC_STD_ASSERT_MESSAGE}>")
  message(STATUS "[EMC_STD_ASSERT_FUNCTION] .. C assert function name ....... <${EMC_STD_ASSERT_FUNCTION}>")
endif()

message(STATUS "[EMC_STD_ATOMIC] ........... C std atomic ................. <${EMC_STD_ATOMIC}>")
message(STATUS "[EMC_STD_STDIO] ............ C stdio functions ............ <${EMC_STD_STDIO}>")
message(STATUS "[EMC_STD_STDLIB] ........... C std library ................ <${EMC_STD_STDLIB}>")
message(STATUS "[EMC_STD_MALLOC] ........... C std malloc ................. <${EMC_STD_MALLOC}>")
message(STATUS "[EMC_STD_DMA_MALLOC] ....... C std ext dma_malloc ......... <${EMC_STD_DMA_MALLOC}>")
message(STATUS "[EMC_STD_MUTEX] ............ C std mutex .................. <${EMC_STD_MUTEX}>")
message(STATUS "[EMC_STD_SPINLOCK] ......... C std spinlock ............... <${EMC_STD_SPINLOCK}>")
message(STATUS "[EMC_STD_TIMESTAMP] ........ C std timestamp .............. <${EMC_STD_TIMESTAMP}>")

configure_file(eme/cmakeConfigure.h.in cmakeConfigure.h)

add_subdirectory(src)


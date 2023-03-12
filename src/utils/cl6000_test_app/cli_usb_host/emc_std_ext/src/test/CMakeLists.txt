add_executable(EmcDmaMallocTest EmcDmaMallocTest.c)
target_link_libraries(EmcDmaMallocTest PRIVATE emc_std_ext emc_test)
eme_add_test(EmcDmaMallocTest)

add_executable(EmcStdextTest EmcStdextTest.c)
target_link_libraries(EmcStdextTest PRIVATE emc_std_ext emc_test)
eme_add_test(EmcStdextTest)

add_executable(EmcStdExtAssertReturnTest EmcStdExtAssertReturnTest.c)
target_link_libraries(EmcStdExtAssertReturnTest PRIVATE emc_std_ext emc_test)
eme_add_test(EmcStdExtAssertReturnTest)

if(EMC_TEST_WRAPPER STREQUAL "CUNIT")
  add_executable(EmcStdExtBitoperationTest EmcStdExtBitoperationTest.c )
  target_link_libraries(EmcStdExtBitoperationTest PRIVATE emc_std_ext emc_test cunit)
  eme_add_test(EmcStdExtBitoperationTest)
endif()

add_executable(CUnit_self_test CUnit_self_test.c)
target_link_libraries(CUnit_self_test
  PRIVATE
    emc_log
    emc_test
)
eme_add_test(CUnit_self_test)

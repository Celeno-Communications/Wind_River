add_executable(InterruptTest InterruptTest.c)
target_link_libraries(InterruptTest PRIVATE emc_system emc_test)
eme_add_test(InterruptTest)

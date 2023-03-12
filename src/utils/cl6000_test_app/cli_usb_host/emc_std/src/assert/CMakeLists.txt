if(EMC_TEST)
  add_subdirectory(test)
endif()


if(EMC_STD_ASSERT_IMPL STREQUAL "HANDLER")
  target_sources(emc_std PRIVATE
    assert_fail_handler.c)
elseif(EMC_STD_ASSERT_IMPL STREQUAL "ABORT")
  target_sources(emc_std PRIVATE
    assert_fail_abort.c)
elseif(EMC_STD_ASSERT_IMPL STREQUAL "LOG")
  target_sources(emc_std PRIVATE
    assert_fail_log.c)
elseif(EMC_STD_ASSERT_IMPL STREQUAL "MEM")
  target_sources(emc_std PRIVATE
    assert_fail_mem.c)
elseif(EMC_STD_ASSERT_IMPL STREQUAL "CPP_LOG")
  target_sources(emc_std PRIVATE
    assert_fail_log.c)
endif()

if(EMC_STD_ASSERT_CONTEXT)
  target_sources(emc_std PRIVATE
    assert_context.c)
endif()

if(EMC_STD_ASSERT_SRC_POS MATCHES "PROGRAM_COUNT")
  target_sources(emc_std PRIVATE
    program_counter.c)
endif()

# only for lint required, in other cases there is no active code inside
# potentially we should use TOOLSET STREQUAL "lint" or similar
if(NOT CMAKE_CXX_COMPILER_ID MATCHES "GNU|Intel|MSVC|Clang")
  target_sources(emc_std PRIVATE
    assert_lint.c
  )
endif()

message(STATUS "Included: eme/coverage.cmake")

set(COVERAGE_IGNORE_PATTERN
  ${COVERAGE_IGNORE_PATTERN}
  \"*/test/*\"
  \"*/emcpp_test/*\"
  \"*/external_*\"
  \"*/include/c++*\"
  \"/lib/gcc*\"
  \"*Test.?pp\"
  \"*Mock*.?pp\"
  \"*Asserter.?pp\"
  \"*/*_mock/*\"
)
  
# create coverage targets

if(PROJECT_COVERAGE)
  # Check prereqs
  find_program(LCOV lcov)
  find_program(FUNCTION_GENINFO "function_geninfo.py" PATHS "${PROJECT_SOURCE_DIR}/eme/bin")
  find_program(GENHTML genhtml)

  if(NOT LCOV)
    message(FATAL_ERROR "lcov not found!")
  elseif(NOT FUNCTION_GENINFO)
    message(FATAL_ERROR "function_geninfo.py not found!")
  elseif(NOT GENHTML)
    message(FATAL_ERROR "genhtml not found!")
  elseif(PROJECT_BUILD_OPTIM)
    message(WARNING "PROJECT_BUILD=OPTIM")
    message(FATAL_ERROR "Optimized build selected. This would produce misleading coverage info." )
  endif()

  message("-- Coverage ignore pattern .... ${COVERAGE_IGNORE_PATTERN}")
  add_custom_command(OUTPUT coverage.info
    # remove old counters, if present
    COMMAND ${LCOV} --zerocounters --directory . --quiet

    # Run tests
    COMMAND ${CMAKE_CTEST_COMMAND} -j4 --timeout 300

    # Collecting lcov counters
    COMMAND ${FUNCTION_GENINFO} . > coverage.info

    WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
    DEPENDS ${ALL_TESTS}
    COMMENT "Run tests and collect coverage data."
  )

  add_custom_command(OUTPUT coverage_initial.info
    # remove incomplete *.gcno files of expectedly not compiling tests
    COMMAND find -regex "\".*_xfail.c\\(pp\\)?.gcno\"" -exec rm -f {} "\;"
    # create zero counter vor ALL functions, even unused ones
    #COMMAND ${LCOV} --capture --initial --directory . --output-file coverage_initial.info --quiet
    COMMAND ${FUNCTION_GENINFO} --initial . > coverage_initial.info

    WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
    DEPENDS ${ALL_TESTS}
    COMMENT "Gather initial coverage info."
  )


  find_program(CXXFILT c++filt)
  if(NOT CXXFILT)
    message(FATAL_ERROR "c++filt not found!")
  endif()
  find_program(COVERAGE_TOOL coverage_tool.py PATHS ${PROJECT_SOURCE_DIR}/eme/bin)
  if(NOT COVERAGE_TOOL)
    message(FATAL_ERROR "coverage_tool.py not found!")
  endif()
  if(VERBOSE_COVERAGE)
    set(_verbose_options -r ${PROJECT_SOURCE_DIR} -v | tee uncovered_functions.txt)
  endif()
  add_custom_command(
    OUTPUT
      coverage_total.info
      coverage_total_clean.info
      coverage_final.info

    # add test run counters to zero counters
    COMMAND ${LCOV} --add-tracefile coverage_initial.info --add-tracefile coverage.info
      --output-file coverage_total.info --quiet
    # remove info stemming from certain source files
    COMMAND ${LCOV} --remove coverage_total.info ${COVERAGE_IGNORE_PATTERN}
      --output-file coverage_total_clean.info --quiet
    # filter out certain functions
    COMMAND ${CXXFILT} -n < coverage_total_clean.info |
      (${COVERAGE_TOOL} - coverage_final.info ${_verbose_options})

    WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
    DEPENDS coverage_initial.info coverage.info
    COMMENT "Combine and filter coverage info."
  )

  add_custom_target(coverage
    DEPENDS "coverage_final.info"
  )

  add_custom_target(genhtml
    COMMAND ${GENHTML} -q -legend -o genhtml coverage_final.info

    WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
    DEPENDS coverage_final.info
    COMMENT "Generating coverage report."
  )
endif(PROJECT_COVERAGE)

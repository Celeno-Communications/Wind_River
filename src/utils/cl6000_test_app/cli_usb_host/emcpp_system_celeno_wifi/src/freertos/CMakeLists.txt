add_executable(freertos_link_test main.c)

target_link_libraries(freertos_link_test
  PRIVATE
    external_freertos_kernel
)

eme_analyze_executable(freertos_link_test)

if (CMAKE_SYSTEM_NAME STREQUAL "Generic")
  add_custom_command(TARGET freertos_link_test POST_BUILD
        COMMAND ${OBJCOPY} --xtensa-system=${XTENSA_CONFIG} --xtensa-core=${EME_XTENSA_CORE} "$<TARGET_FILE:freertos_link_test>" -S -O binary "$<TARGET_FILE:freertos_link_test>.bin"
        COMMAND echo "generated binary $<TARGET_FILE:freertos_link_test>.bin"
  )
endif()

add_executable(freertos_plus_tcp_link_test main_plus_tcp.c)
if(FREERTOS_PLUS_TCP_IPV6)
  target_sources(freertos_plus_tcp_link_test PRIVATE ipv6_stubs.c)
endif()

target_link_libraries(freertos_plus_tcp_link_test
  PRIVATE
    external_freertos_kernel
    external_freertos_plus_tcp
)

eme_analyze_executable(freertos_plus_tcp_link_test)

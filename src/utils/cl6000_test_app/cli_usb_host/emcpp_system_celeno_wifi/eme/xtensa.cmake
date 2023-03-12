if (NOT DEFINED LSP_BASE_DIR)
  set(LSP_BASE_DIR "${CMAKE_SOURCE_DIR}/emcpp_system_celeno_wifi/eme/lsp")
endif()

message("-- LSP_BASE_DIR: ${LSP_BASE_DIR}")

set(EME_XTENSA_CONFIG "${EME_XTENSA_CORE}/config")
set(EMC_HW_PHYSICAL_ADDRESS_MAP "EXTERN" CACHE STRING "" FORCE)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--defsym,_memmap_cacheattr_reset=0x22222222")

# we want always debug symbols inside
add_compile_options("-g")
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

function(xtensa_show_ram_summary)
  foreach(exe ${ARGV})
    add_custom_command(
      TARGET ${exe}
      POST_BUILD
      COMMAND awk "/Name.*Origin.*Length.*Attributes/,/^$$/" ${exe}.map.txt
    )
  endforeach()
endfunction()

function(xtensa_generate_binary)
  foreach(exe ${ARGV})
    add_custom_command(
      TARGET ${exe}
      POST_BUILD
      COMMAND ${OBJCOPY} --xtensa-system=${XTENSA_CONFIG} --xtensa-core=${EME_XTENSA_CORE} "$<TARGET_FILE:${exe}>" -S -O binary "$<TARGET_FILE:${exe}>.bin"
      COMMAND echo "generated binary $<TARGET_FILE:${exe}>.bin"
    )
  endforeach()
endfunction()

SET(EME_XTENSA_PATH "/home/trego/cl2400/Xtensa/XtDevTools/install/tools/RI-2020.5-linux/XtensaTools/bin")

add_compile_options("-fmessage-length=0")
add_compile_options("-mno-padglobals")
add_compile_options("-fdata-sections")
add_compile_options("-ffunction-sections")
add_definitions("-DCE_TEST")
add_definitions("-DCE_HW_VERSION=3")
add_definitions("-DCONFIG_MACH_DINIV6")

include("${PROJECT_SOURCE_DIR}/eme/toolset/xtensa/toolset.cmake") 


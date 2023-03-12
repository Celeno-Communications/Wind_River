
PREFIX ?= /usr
BINDIR ?= $(PREFIX)/bin
MANDIR ?= $(PREFIX)/share/man

INCLUDE_PATHS += -Iregs -Iregs/xtensa -Iregs/xtensa/regs -Iregs/xtensa/phy -Iregs/xtensa/dphy -Icommon_regs -Icli -I$(abspath ../libusb/libusb/)
CC ?= "gcc"
CFLAGS ?= -O2 -g
CFLAGS += -Wall -Werror
CFLAGS += $(INCLUDE_PATHS)
CFLAGS += -DPRIM_BAND=1 -DCE_HW_VERSION=3
OBJS = cl6000_boot_drv.o cl6000_fw_test.o cl6000_usb_test_wrapper.o cl6000_usb_test_wifireset.o cl6000_usb_test_coredump.o cl6000_usb_test_tput.o cl6000_usb_ecm_test.o  cl6000_usb_ecm_udp_test.o cl6000_usb_test_common.o ../cl_reg/cl_reg.o
LDFLAGS = -Lcli -lusb-1.0 -lpthread
LIBS += cli/libcli_usb.a

#libusb offline
LIB_USB_OFFLINE_DIR ?= $(realpath ../libusb)
INCLUDE_PATHS += -I $(LIB_USB_OFFLINE_DIR)/libusb

CMAKE_OPTIONS :=
CMAKE_OPTIONS += "-DLIB_USB_OFFLINE_DIR=$(LIB_USB_OFFLINE_DIR)"
#CMAKE_OPTIONS += "-DCMAKE_TOOLCHAIN_FILE=$(realpath ./cli_usb_host/eme/toolset/gcc8aarch32linux/toolset.cmake)"


ALL = cli/libcli_usb.a cl6000_boot.a

ifeq ($(V),1)
Q=
NQ=true
else
Q=@
NQ=echo
endif

all: $(ALL)

%.o: %.c cli/libcli_usb.a
	@$(NQ) ' CC  ' $@
	$(Q)$(CC) $(CFLAGS) -c -o $@ $<

cli/libcli_usb.a:
	LDFLAGS="" cmake -Hcli_usb_host -Bcli_usb_host/bin -DUSECASE=emcpp_system_celeno_wifi/eme/host_cli.usecase.cmake -DCMAKE_INSTALL_PREFIX=$(CURDIR) $(CMAKE_OPTIONS) -DCMAKE_TRY_COMPILE_TARGET_TYPE=STATIC_LIBRARY
	$(MAKE) -C cli_usb_host/bin install_cli

cl6000_boot.a: $(OBJS) cli/libcli_usb.a
	#$(Q)$(CC) $(CFLAGS) $(OBJS) $(LIBS) -c  $< -o  $@
	$(Q)$(AR) rcs $@ $(OBJS) cli/libcli_usb.a

clean-all: clean
	$(Q)rm -rf cli_usb_host/bin cli/cli*.h libusb-1.0 cli/libcli_usb.a cli/libusb-1.0.a

clean:
	$(Q)rm -f cl6000_boot *.a *.o *~


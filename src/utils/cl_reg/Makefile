CC ?= "gcc"

CFLAGS ?= -O2 -g
CFLAGS += -Wall -Werror

ARFLAGS ?= rcs
CFLAGS += -I../cl6000_test_app/cli/ -I ../cl6000_test_app/cli_usb_host/emcpp_system_celeno_wifi/src/host/cli -I../cl6000_test_app/cli_usb_host/emcpp_system_celeno_wifi/inc/emc/system/celeno/host/cli
OBJS = cl_reg.o

ALL = cl_reg.a

ifeq ($(V),1)
Q=
NQ=true
else
Q=@
NQ=echo
endif

all: $(ALL)

%.a: %.o
	$(Q)$(AR) $(ARFLAGS) $@ $<

%.o: %.c
	@$(NQ) ' CC  ' $@
	$(Q)$(CC) $(CFLAGS) -fPIC -c -o $@ $<

clean:
	$(Q)rm -f *.a *.o *~


PREFIX ?= /usr
BINDIR ?= $(PREFIX)/bin
MANDIR ?= $(PREFIX)/share/man

CC ?= "gcc"

CFLAGS ?= -O2 -g
CFLAGS += -Wall -I../
CFLAGS += -I../cl6000_test_app/cli/ -I../cl_reg/
LIBS += ../cl_reg/cl_reg.a
LIBS += ../cl6000_test_app/cli/libcli_usb.a
LDFLAGS = -L../cl6000_test_app/cli -lusb-1.0 -lpthread

OBJS = otp.o
ALL = otp

ifeq ($(V),1)
Q=
NQ=true
else
Q=@
NQ=echo
endif

all: $(ALL)

%.o: %.c
	@$(NQ) ' CC  ' $@
	$(Q)$(CC) $(CFLAGS) -c -o $@ $<

otp:	$(OBJS)
	@$(NQ) ' CC  ' otp
	$(Q)$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o otp $(LDFLAGS)

clean:
	$(Q)rm -f otp *.o *~

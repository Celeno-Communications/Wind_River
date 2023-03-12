
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

OBJS = e2p.o
ALL = e2p

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

e2p:	$(OBJS)
	@$(NQ) ' CC  ' e2p
	$(Q)$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o e2p $(LDFLAGS)

clean:
	$(Q)rm -f e2p *.o *~

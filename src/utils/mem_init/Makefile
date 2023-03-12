MAKEFLAGS += --no-print-directory

PREFIX ?= /usr
BINDIR ?= $(PREFIX)/bin
MANDIR ?= $(PREFIX)/share/man
PKG_CONFIG ?= pkg-config

MKDIR ?= mkdir -p
CC ?= "gcc"

CFLAGS ?= -O2 -g
CFLAGS += -Wall
CFLAGS += -I../

CFLAGS += -I../cl_reg/
CFLAGS +=  -I../cl6000_test_app/cli/
OBJS = mem_init.o
LIBS += ../cl_reg/cl_reg.a
LIBS += ../cl6000_test_app/cli/libcli_usb.a
LDFLAGS = -L../cl6000_test_app/cli -lusb-1.0 -lpthread

ALL = mem_init
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

mem_init:	$(OBJS)
	@$(NQ) ' CC  ' mem_init
	$(Q)$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o mem_init $(LDFLAGS)

check:
	$(Q)$(MAKE) all CC="REAL_CC=$(CC) CHECK=\"sparse -Wall\" cgcc"

clean:
	$(Q)rm -f mem_init *.o *~

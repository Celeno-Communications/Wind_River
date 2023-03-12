MAKEFLAGS += --no-print-directory

PREFIX ?= /usr
BINDIR ?= $(PREFIX)/bin
MANDIR ?= $(PREFIX)/share/man
PKG_CONFIG ?= pkg-config

MKDIR ?= mkdir -p
CC ?= "gcc"

CFLAGS ?= -O2 -g
CFLAGS += -Wall

ALL = genvcd

ifeq ($(V),1)
Q=
NQ=true
else
Q=@
NQ=echo
endif

all: $(ALL)

%.o: %.c %.h
	@$(NQ) ' CC  ' $@
	$(Q)$(CC) $(CFLAGS) -c -o $@ $<

genvcd: genvcd.o
	@$(NQ) ' CC  ' genvcd
	$(Q)$(CC) $(LDFLAGS) genvcd.o $(LIBS) -o genvcd

check:
	$(Q)$(MAKE) all CC="REAL_CC=$(CC) CHECK=\"sparse -Wall\" cgcc"

clean:
	$(Q)rm -f genvcd *.o *~

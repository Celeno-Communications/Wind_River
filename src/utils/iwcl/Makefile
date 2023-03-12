PREFIX ?= /usr
BINDIR ?= $(PREFIX)/bin
MANDIR ?= $(PREFIX)/share/man
PKG_CONFIG ?= pkg-config

CC ?= "gcc"

CFLAGS ?= -O2 -g
CFLAGS += -Wall -Werror -I../iw/
GCCVERSIONGTEQ9 := $(shell expr `$(CROSS_COMPILE)gcc -dumpversion | cut -f1 -d.` \>= 9)
ifeq "$(GCCVERSIONGTEQ9)" "1"
    CFLAGS += -Wno-address-of-packed-member
endif
LDFLAGS += -lpthread -lrt

OBJS = iwcl.o e2p.o ate.o otp.o cecli.o
ALL = iwcl

ifeq ($(CECFG_LIBNL_ENABLE),y)
CFLAGS += -I$(abspath ../libnl/include)
LDFLAGS += -L$(abspath ../libnl/lib/.libs/)
NO_PKG_CONFIG=y
LIBS += -lnl-genl-3 -lnl-3
endif

ifeq ($(V),1)
Q=
NQ=true
else
Q=@
NQ=echo
endif

ifeq ($(NO_PKG_CONFIG),)
NL3xFOUND := $(shell $(PKG_CONFIG) --atleast-version=3.2 libnl-3.0 && echo Y)
ifneq ($(NL3xFOUND),Y)
NL31FOUND := $(shell $(PKG_CONFIG) --exact-version=3.1 libnl-3.1 && echo Y)
ifneq ($(NL31FOUND),Y)
NL3FOUND := $(shell $(PKG_CONFIG) --atleast-version=3 libnl-3.0 && echo Y)
ifneq ($(NL3FOUND),Y)
NL2FOUND := $(shell $(PKG_CONFIG) --atleast-version=2 libnl-2.0 && echo Y)
ifneq ($(NL2FOUND),Y)
NL1FOUND := $(shell $(PKG_CONFIG) --atleast-version=1 libnl-1 && echo Y)
endif
endif
endif
endif

ifeq ($(NL1FOUND),Y)
NLLIBNAME = libnl-1
endif

ifeq ($(NL2FOUND),Y)
CFLAGS += -DCONFIG_LIBNL20
LIBS += -lnl-genl
NLLIBNAME = libnl-2.0
endif

ifeq ($(NL3xFOUND),Y)
# libnl 3.2 might be found as 3.2 and 3.0
NL3FOUND = N
CFLAGS += -DCONFIG_LIBNL30
LIBS += -lnl-genl-3
NLLIBNAME = libnl-3.0
endif

ifeq ($(NL3FOUND),Y)
CFLAGS += -DCONFIG_LIBNL30
LIBS += -lnl-genl
NLLIBNAME = libnl-3.0
endif

# nl-3.1 has a broken libnl-gnl-3.1.pc file
# as show by pkg-config --debug --libs --cflags --exact-version=3.1 libnl-genl-3.1;echo $?
ifeq ($(NL31FOUND),Y)
CFLAGS += -DCONFIG_LIBNL30
LIBS += -lnl-genl
NLLIBNAME = libnl-3.1
endif

ifeq ($(NLLIBNAME),)
$(error Cannot find development files for any supported version of libnl)
endif

LIBS += $(shell $(PKG_CONFIG) --libs $(NLLIBNAME))
CFLAGS += $(shell $(PKG_CONFIG) --cflags $(NLLIBNAME))
endif # NO_PKG_CONFIG

ifeq ($(ST_NL3FOUND),Y)
LIBS += -lnl-genl-3 -lnl-3
CFLAGS += -DCONFIG_LIBNL30 -I$(SDK_PATH)/stm_base/devkit/armv7/target/usr/include
endif

ifeq ($(NL1FOUND),Y)
NLLIBNAME = libnl-1
endif

all: $(ALL)

%.o: %.c
	@$(NQ) ' CC  ' $@
	$(Q)$(CC) $(CFLAGS) -c -o $@ $<

iwcl:	$(OBJS)
	@$(NQ) ' CC  ' iwcl
	$(Q)$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) $(LIBS) -o iwcl

clean:
	$(Q)rm -f iwcl *.o *~

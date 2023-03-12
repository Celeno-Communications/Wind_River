
PREFIX ?= /usr
BINDIR ?= $(PREFIX)/bin
MANDIR ?= $(PREFIX)/share/man

CC ?= "gcc"

CFLAGS ?= -O2 -g
CFLAGS += -Wall -I../ -I../cl_reg/
CFLAGS += -I../cl6000_test_app/cli/

OBJS = devmem2.o

# For libdevmem:
LIBDM=libdevmem.o
CFLAGS += -DENV_MBASE=\"CL_PCI_BASE_ADDR\" -DENV_MEM_END=\"CL_PCI_LAST_ADDR\"
LIBS += ../cl_reg/cl_reg.a
LIBS +=../cl6000_test_app/cli/libcli_usb.a
LDFLAGS = -L../cl6000_test_app/cli -lusb-1.0 -lpthread


ALL = mem $(LIBDM)

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

mem:	$(OBJS)
	@$(NQ) ' CC  ' mem
	$(Q)$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o mem $(LDFLAGS)

clean:
	$(Q)rm -f mem *.o *~

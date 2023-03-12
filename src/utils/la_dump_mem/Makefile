
PREFIX ?= /usr
BINDIR ?= $(PREFIX)/bin

PROG=la_dump_mem

CC ?= "gcc"

CFLAGS ?= -O2 -Wall
CFLAGS += -I.

# This uses libdevmem:
DEVMEM_DIR?=../devmem
CFLAGS += $(shell $(DEVMEM_DIR)/libdevmem-config --cflags)
LIBS += $(shell $(DEVMEM_DIR)/libdevmem-config --libs)

SRC = la_dump_mem.c

$(PROG): $(SRC)
	$(CC) $(ARCH_COMPILE) -o $@ $(CFLAGS) $(LDFLAGS) $(LIBS) $(SRC)


clean:
	rm -f $(PROG) *.o *~


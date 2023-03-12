EXEC = cl_netlink
OBJS = cl_netlink.o
CFLAGS += $(EXTRA_CFLAGS)
CFLAGS +=-Wall -Werror

ifeq ($(CECFG_LIBNL_ENABLE), y)
	CFLAGS += -I$(abspath ../libnl/include)
	LDFLAGS+=-L$(abspath ../libnl/lib/.libs/)
	LIBS += -lnl-genl-3 -lnl-3
else
	CFLAGS +=$(shell pkg-config --cflags libnl-genl-3.0)
	LIBS +=$(shell pkg-config --libs libnl-genl-3.0)
endif

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) $(LIBS) -o $(EXEC)

clean:
	-rm -f $(EXEC) *.o

distclean: clean

romfs:
	$(ROMFSINST) /sbin/$(EXEC)

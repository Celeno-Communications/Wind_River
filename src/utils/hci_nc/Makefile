EXEC = hci_nc
OBJS = hci_nc.o
CFLAGS += $(EXTRA_CFLAGS)
CFLAGS +=-Wall -Werror
CFLAGS +=-I../bluez-5.62

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) $(LIBS) -o $(EXEC)

clean:
	-rm -f $(EXEC) *.o

distclean: clean

romfs:
	$(ROMFSINST) /bin/$(EXEC)

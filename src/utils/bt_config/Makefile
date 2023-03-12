EXEC = cl_bt_config
OBJS = bt_nvram.o
CFLAGS += $(EXTRA_CFLAGS)
CFLAGS +=-Wall -Werror

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) $(LIBS) -o $(EXEC)

clean:
	-rm -f $(EXEC) *.o

distclean: clean

romfs:
	$(ROMFSINST) /bin/$(EXEC)

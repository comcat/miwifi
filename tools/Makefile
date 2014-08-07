CC = gcc
CFLAGS = -O3 -Wall -Wno-format

all: trx

trx: trx.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *.o trx

%.o: %.c
	$(CC) $(CFLAGS) -c $<

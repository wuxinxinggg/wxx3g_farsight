CFLAGS = -Wall -O0
CC = gcc

SRC = ${wildcard *.c}
BIN = ${patsubst %.c, %, $(SRC)}

all:$(BIN)

$(BIN):%:%.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	@ - $(RM) $(BIN) .*.sw?

.PHONY:clean all

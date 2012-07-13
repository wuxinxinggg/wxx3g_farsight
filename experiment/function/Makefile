CC=gcc
CFLAGS=-g -Wall -O0
SRC=${wildcard *.c}
OBJ=${patsubst %.c,%,$(SRC)}
all:$(OBJ)

clean:
	$(RM) $(OBJ)

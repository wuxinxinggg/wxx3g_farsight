CC=gcc
CFLAGS=-g -Wall -O0
SRC=${wildcard *.c}
OBJ=${patsubst %.c,%,$(SRC)}
echo:
	echo $(SRC) $(OBJ)
all:$(OBJ)
clean:
	$(RM) $(OBJ)

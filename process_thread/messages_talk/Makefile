CC = gcc
CFLAGS = -g -Wall -O0
SUBDIRS = server_src client_src
OBJS = sub_funciton.o
OBJ_DIR = obj
BIN_DIR = bin

export CC CFLAGS SUBDIR OBJS OBJDIR

all:CHECK_DIR $(SUBDIRS)

CHECK_DIR:
	mkdir -p $(BIN_DIR)

$(SUBDIRS):ECHO
	make -C $@

ECHO:
	@echo $(SUBDIRS)
	@echo begin compile

CLEAN:
	$(RM) $(OBJ_DIR)/*.o
	rm -fr $(BIN_DIR)

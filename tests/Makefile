INCLUDE=-I../include
CC=gcc
CFLAGS=-g -Wall
TARGETS=$(wildcard *.c)
OBJDIR=obj
OBJECTS=$(patsubst %.c, %.o, $(TARGETS))
SRC=$(wildcard ../src/*.c)

dir:
	mkdir obj
	make all

all: $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) $(SRC) $< -o $(OBJDIR)/$@
	@echo $< "Compiliation complete"

clean:
	rm -rf obj

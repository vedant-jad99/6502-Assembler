INCLUDE=-I../include
CC=gcc
CFLAGS=-g -Wall
TARGETS=$(wildcard *.c)
OBJDIR=obj
OBJECTS=$(patsubst %.c, $(OBJDIR)/%.o, $(TARGETS))
SRC=$(wildcard ../src/*.c)

all:
	mkdir obj
	$(CC) $(CFLAGS) $(INCLUDE) $(SRC) $(TARGETS) -o $(OBJECTS)

clean:
	rm -rf obj

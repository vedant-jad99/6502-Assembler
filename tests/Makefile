INCLUDE=-I../include
CC=gcc
CFLAGS=-g -Wall
TARGETS=$(wildcard *.c)
OBJDIR=obj
OBJECTS=$(patsubst %.c, $(OBJDIR)/%.o, $(TARGETS))

all:
	mkdir obj
	$(CC) $(CFLAGS) $(INCLUDE) $(TARGETS) -o $(OBJECTS)

clean:
	rm -rf obj

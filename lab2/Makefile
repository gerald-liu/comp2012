# Definition of variables
SRCS = main.cpp file.cpp folder.cpp
OBJS = main.o file.o folder.o
PROG = lab2
CC = g++
CPPFLAGS = -std=c++11
LDFLAGS =
DBGFLAGS = -g -Wall

# Rules' Format
# TARGET: DEPENDENCIES
# [TAB] COMMAND USED TO CREATE THE TARGET

all: $(OBJS)
	$(CC) $(LDFLAGS) -o lab2 $(OBJS)

main.o: main.cpp folder.h
	$(CC) $(CPPFLAGS) -c main.cpp

file.o: file.cpp file.h
	$(CC) $(CPPFLAGS) -c file.cpp

folder.o: folder.cpp folder.h
	$(CC) $(CPPFLAGS) -c folder.cpp

# makedepend can find the .h dependencies automatically
depend:;	makedepend $(SRCS)

clean:
	rm -f core $(OBJS)

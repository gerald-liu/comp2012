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

.cpp.o:
	$(CC) $(CPPFLAGS) -c $*.cpp

# makedepend can find the .h dependencies automatically
depend:;	makedepend $(SRCS)

clean:
	rm -f core $(OBJS)

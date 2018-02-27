# Definition of variables
SRCS = main.cpp CellularPhone.cpp iPhone.cpp OS.cpp SmartPhone.cpp
OBJS = main.o CellularPhone.o iPhone.o OS.o SmartPhone.o
PROG = lab3
CC = g++
CPPFLAGS = -std=c++11
LDFLAGS =
DBGFLAGS = -g -Wall

# Rules' Format
# TARGET: DEPENDENCIES
# [TAB] COMMAND USED TO CREATE THE TARGET

all: $(OBJS)
	$(CC) $(LDFLAGS) -o lab3 $(OBJS)

.cpp.o:
	$(CC) $(CPPFLAGS) -c $*.cpp

# makedepend can find the .h dependencies automatically
depend:;	makedepend $(SRCS)

clean:
	rm -f core $(OBJS)

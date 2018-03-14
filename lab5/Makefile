# Definition of variables
SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp
OBJS = main.o Animal.o Cat.o Dog.o
PROG = lab5
CC = g++
CPPFLAGS = -std=c++11

# Rules' Format
# TARGET: DEPENDENCIES
# [TAB] COMMAND USED TO CREATE THE TARGET

all: $(OBJS)
	$(CC) $(LDFLAGS) -o lab5 $(OBJS)

.cpp.o:
	$(CC) $(CPPFLAGS) -c $*.cpp

# makedepend can find the .h dependencies automatically
depend:;	makedepend $(SRCS)

clean:
	rm -f core $(OBJS) $(PROG)
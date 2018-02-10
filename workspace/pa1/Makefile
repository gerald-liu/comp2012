# Definition of variables
SRCS = main.cpp mall.cpp node.cpp noloop.cpp product.cpp shop.cpp
OBJS = main.o mall.o node.o noloop.o product.o shop.o
PROG = pa1
CC = g++
CPPFLAGS = -std=c++11
LDFLAGS =
DBGFLAGS = -g -Wall

# Rules' Format
# TARGET: DEPENDENCIES
# [TAB] COMMAND USED TO CREATE THE TARGET

$(PROG): $(OBJS)
	$(CC) $(LDFLAGS) -o pa1 $(OBJS)

main.o: main.cpp mall.h
	$(CC) $(CPPFLAGS) -c main.cpp

mall.o: mall.cpp mall.h
	$(CC) $(CPPFLAGS) -c mall.cpp

node.o: node.cpp node.h
	$(CC) $(CPPFLAGS) -c node.cpp

noloop.o: noloop.cpp mall.h
	$(CC) $(CPPFLAGS) -c noloop.cpp

product.o: product.cpp product.h
	$(CC) $(CPPFLAGS) -c product.cpp

shop.o: shop.cpp shop.h
	$(CC) $(CPPFLAGS) -c shop.cpp

# makedepend can find the .h dependencies automatically
depend:;	makedepend $(SRCS)

clean:
	rm -f core $(PROG) $(OBJS)

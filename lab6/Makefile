PROG = lab6
SRCS = *.cpp
CC = g++
CPPFLAGS = -std=c++11

all: $(PROG)

lab6: *.o
	g++ -o $(PROG) *.o

.cpp.o:
	$(CC) $(CPPFLAGS) -c $*.cpp

# makedepend can find the .h dependencies automatically
depend:;	makedepend $(SRCS)

clean:
	rm -f *.o $(PROG)
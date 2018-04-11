PROG = lab7
CC = g++
CPPFLAGS = -std=c++11 -Wall

all: *.o
	$(CC) -o $(PROG) *.o

*.o:
	$(CC) $(CPPFLAGS) -c *.cpp

# makedepend can find the .h dependencies automatically
depend:
	makedepend *.cpp

clean:
	rm -f *.o $(PROG)
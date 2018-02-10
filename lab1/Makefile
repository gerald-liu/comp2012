# Definition of variables
PEN = pen.o
APPLE = apple.o
PINEAPPLE = pineapple.o
APPLE_PEN = $(APPLE) $(PEN) apple-pen.o
PINEAPPLE_PEN = $(PINEAPPLE) $(PEN) pineapple-pen.o
# This will take the union (remove duplicate) of two variables $(PINEAPPLE_PEN) and $(APPLE_PEN)
PPAP = $(sort $(PINEAPPLE_PEN) $(APPLE_PEN))

CC = g++
CPPFLAGS = -std=c++11
DBGFLAGS = -g -Wall

# Rules' Format
# TARGET: DEPENDENCIES
all: ppap apple-pen-main pineapple-pen-main

ppap: $(PPAP) ppap.cpp
	$(CC) -o ppap.exe ppap.cpp $(PPAP)

apple-pen-main: $(APPLE_PEN) apple-pen-main.cpp
	$(CC) -o apple-pen-main.exe apple-pen-main.cpp $(APPLE_PEN)

pineapple-pen-main: $(PINEAPPLE_PEN) pineapple-pen-main.cpp 
	$(CC) -o pineapple-pen-main.exe pineapple-pen-main.cpp $(PINEAPPLE_PEN)

apple-pen.o: apple-pen.cpp apple.h pen.h
	$(CC) $(CPPFLAGS) -c apple-pen.cpp

pineapple-pen.o: pineapple-pen.cpp pineapple.h pen.h
	$(CC) $(CPPFLAGS) -c pineapple-pen.cpp

pen.o: pen.cpp pen.h
	$(CC) $(CPPFLAGS) -c pen.cpp

apple.o: apple.cpp apple.h
	$(CC) $(CPPFLAGS) -c apple.cpp

pineapple.o: pineapple.cpp pineapple.h
	$(CC) $(CPPFLAGS) -c pineapple.cpp

clean:
	rm -f core *.o *.exe

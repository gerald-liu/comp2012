SRCS = main_a.cpp main_b.cpp main_c.cpp Employee.cpp Consultant.cpp EducationalConsultant.cpp
CC = g++
CPPFLAGS = -std=c++11

all: parta partb partc

parta: main_a.o Employee.o Consultant.o
	g++ -o parta main_a.o Employee.o Consultant.o

partb: main_b.o Employee.o Consultant.o EducationalConsultant.o
	g++ -o partb main_b.o Employee.o Consultant.o EducationalConsultant.o

partc: main_c.o Employee.o Consultant.o EducationalConsultant.o
	g++ -o partc main_c.o Employee.o Consultant.o EducationalConsultant.o

.cpp.o:
	$(CC) $(CPPFLAGS) -c $*.cpp

# makedepend can find the .h dependencies automatically
depend:;	makedepend $(SRCS)

clean:
	rm -f *.o parta partb partc
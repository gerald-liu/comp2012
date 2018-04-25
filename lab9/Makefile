EXE = a.out
SRC = *.cpp
OBJ = *.o
CXXFLAGS = -std=c++11 -Wall
DBGFLAGS = -g

all: clean build run

debug: clean dbg_build run

build: $(OBJ)
	$(CXX) -o $(EXE) $(OBJ)

dbg_build: dbg_$(OBJ)
	$(CXX) -o $(EXE) $(OBJ)

$(OBJ):
	$(CXX) $(CXXFLAGS) -c $(SRC)

dbg_$(OBJ):
	$(CXX) $(CXXFLAGS) $(DBGFLAGS) -c $(SRC)

depend:
	makedepend $(SRC)

run:
	./$(EXE)

clean:
	rm -f $(OBJ) $(EXE)
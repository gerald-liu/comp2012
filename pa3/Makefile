EXE = a.out
SRC = main.cpp
OBJ = main.o
CXXFLAGS = -std=c++11 -Wall
DBGFLAGS = -g

all: clean build run

debug: clean dbg_build run

build: $(OBJ)
	$(CXX) -o $(EXE) $(OBJ)

dbg_build: dbg_$(OBJ)
	$(CXX) -o $(EXE) $(OBJ)

$(OBJ): $(SRC) smartArray.h smartArray.tpp container.h pair.h
	$(CXX) $(CXXFLAGS) -c $(SRC)

dbg_$(OBJ): $(SRC) smartArray.h smartArray.tpp container.h pair.h
	$(CXX) $(CXXFLAGS) $(DBGFLAGS) -c $(SRC)

run:
	./$(EXE)

clean:
	rm -f $(OBJ) $(EXE)
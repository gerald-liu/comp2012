ifeq (Windows_NT, $(OS))
ifeq (, $(OSTYPE))
ziptool		:= ./zip.exe
else
ziptool		:= zip
endif
else
ziptool		:= zip
endif



CFLAGS         := -Wall -std=c++11 
OBJDIR         := obj
CLASSES        := Card NumberCard CardPile Player SkipCard ReverseCard DrawTwoCard WildCard DrawFourCard 
TESTER         := testNumberCard testSkipCard testReverseCard testWildCardandDrawFourCard
CLASSES_OBJECT := $(addsuffix .o, $(addprefix $(OBJDIR)/, $(CLASSES)))
TODO		   := NumberCard.h DrawFourCard.h SkipCard.h ReverseCard.h DrawTwoCard.h WildCard.h NumberCard.cpp DrawFourCard.cpp SkipCard.cpp ReverseCard.cpp DrawTwoCard.cpp WildCard.cpp Player.cpp  
#TESTER_OBJECT  := $(addsuffix .o, $(addprefix $(OBJDIR)/, $(TESTER)))

all: game.exe test pa2.zip

test: $(addsuffix .exe, $(TESTER)) 
	
%.exe: $(addprefix $(OBJDIR)/, %.o) $(CLASSES_OBJECT)
	g++ $(CFLAGS) -o $@ $< $(CLASSES_OBJECT) 

game.exe: obj/game.o $(CLASSES_OBJECT)
	g++ -o game.exe $(CFLAGS) obj/game.o $(CLASSES_OBJECT) 
#	
testmain.exe: obj/testmain.o $(CLASSES_OBJECT) 	
	g++ -o testmain.exe $(CFLAGS) obj/testmain.o $(CLASSES_OBJECT)
	
$(addprefix $(OBJDIR)/, %.o): %.cpp $(TODO)
	@mkdir -p obj
	g++ -c -o $@  $(CFLAGS) $<

clean:
	rm -f obj/*.o game.exe $(addsuffix .exe, $(TESTER)) pa2.zip
	
pa2.zip: $(TODO)
	@echo 
	@echo "Preparing your pa2.zip - submit this to Canvas directly"
	@echo
	rm -f pa2.zip
	$(ziptool) pa2.zip $(TODO) 

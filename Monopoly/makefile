CXX=clang++
CXX2=g++
CXXFLAGS=-std=c++2a -Werror

SOURCES=Monopoly.cpp GameCell.cpp Player.cpp GameBoard.cpp GameWindow.cpp
OBJECTS=$(subst .cpp,.o,$(SOURCES))

TESTSOURCES=TestMonopoly.cpp GameCell.cpp Player.cpp GameBoard.cpp GameWindow.cpp
TESTOBJECTS=$(subst .cpp,.o,$(TESTSOURCES))

all: clean
	$(CXX) -c $(SOURCES)
	$(CXX) $(OBJECTS) -o Monopoly -lsfml-graphics -lsfml-window -lsfml-system
	./Monopoly

clean:
	-rm $(OBJECTS)
	-rm $(TESTOBJECTS)
	-rm Monopoly	
	-rm TestMonopoly

test: clean
	$(CXX) -c $(TESTSOURCES)
	$(CXX) $(TESTOBJECTS) -o TestMonopoly -lsfml-graphics -lsfml-window -lsfml-system
	./TestMonopoly --list-test-cases
	./TestMonopoly

g++: clean
	$(CXX2) -c $(SOURCES)
	$(CXX2) $(OBJECTS) -o Monopoly -lsfml-graphics -lsfml-window -lsfml-system
	./Monopoly

testg++: clean
	$(CXX2) -c $(TESTSOURCES)
	$(CXX2) $(TESTOBJECTS) -o TestMonopoly -lsfml-graphics -lsfml-window -lsfml-system
	./TestMonopoly --list-test-cases
	./TestMonopoly



Game: Main.o BoardDisplay.o
	g++ -o Game Main.o BoardDisplay.o -lncurses

BoardDisplay.o: BoardDisplay.cpp BoardDisplay.h
	g++ -c BoardDisplay.cpp -lncurses

Main.o:	Main.cpp BoardDisplay.h
	g++ -c Main.cpp -lncurses

Main: Main.o BoardDisplay.o Referee.o Tortoise.o Hare.o Snack.o random.o
	g++ -o Main Main.o BoardDisplay.o Referee.o Tortoise.o Hare.o Snack.o random.o -lncurses
Main.o: Main.h Main.cpp BoardDispaly.cpp Referee.cpp
	g++ -c Main.cpp

BoardDisplay.o: BoardDisplay.h BoardDisplay.cpp random.h
	g++ -c BoardDisplay.cpp  -lncurses

Referee.o: Referee.h Referee.cpp Hare.h Tortoise.h Snack.h
	g++ -c Referee.cpp

Tortoise.o: Tortoise.h Tortoise.cpp random.h
	g++ -c Tortoise.cpp

Hare.o: Hare.h Hare.cpp random.h
	g++ -c Hare.cpp random.h

Snack.o: Snack.h Snack.cpp
	g++ -c Snack.cpp

all: Main
clean:
	rm -f Main Main.o BoardDisplay.o Referee.o Tortoise.o Hare.o Snack.o random.o

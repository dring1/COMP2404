Main: Main.o BoardDisplay.o Referee.o Tortoise.o Hare.o Snack.o random.o
	g++ -o Main Main.o BoardDisplay.o Referee.o Tortoise.o Hare.o Snack.o random.o -lncurses

Main.o: Main.cpp BoardDisplay.cpp Referee.cpp
	g++ -c Main.cpp

BoardDisplay.o: BoardDisplay.cpp Referee.cpp
	g++ -c BoardDisplay.cpp  -lncurses

Referee.o: Referee.cpp
	g++ -c Referee.cpp

Tortoise.o: Tortoise.cpp
	g++ -c Tortoise.cpp

Hare.o: Hare.cpp
	g++ -c Hare.cpp

Snack.o: Snack.cpp
	g++ -c Snack.cpp

all: Main BoardDisplay
clean:
	rm -f Main Main.o BoardDisplay.o Referee.o Tortoise.o Hare.o Snack.o random.o

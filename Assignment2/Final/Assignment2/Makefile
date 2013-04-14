Main: Main.o Display.o Observer.o PirateLine.o Node.o Pirate.o Hare.o Tortoise.o random.o
	g++ -o Main Main.o Display.o Observer.o PirateLine.o Node.o Pirate.o Hare.o Tortoise.o random.o

Main.o: Main.cpp Observer.cpp PirateLine.cpp Display.cpp Tortoise.cpp Hare.cpp
	g++ -c Main.cpp

Display.o: Display.cpp
	g++ -c Display.cpp

Observer.o: Observer.cpp PirateLine.cpp Hare.cpp Tortoise.cpp
	g++ -c Observer.cpp

PirateLine.o: PirateLine.cpp Node.cpp Pirate.cpp
	g++ -c PirateLine.cpp

Node.o: Node.cpp Pirate.cpp
	g++ -c Node.cpp

Pirate.o: Pirate.cpp
	g++ -c Pirate.cpp

Hare.o: Hare.cpp
	g++ -c Hare.cpp

Tortoise.o: Tortoise.cpp
	g++ -c Tortoise.cpp

clean:
	rm -f Main Main.o Observer.o PirateLine.o Node.o Pirate.o Hare.o Tortoise.o 
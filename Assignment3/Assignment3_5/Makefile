a3main: a3main.o Brig.o Cell.o List.o Node.o Pirate.o Dorc.o Borc.o Porc.o
	g++ -o Main a3main.o Brig.o Cell.o List.o Node.o Pirate.o Dorc.o Borc.o Porc.o

a3main.o: a3main.cpp Brig.cpp List.cpp Node.cpp Pirate.cpp Dorc.cpp Borc.cpp Porc.cpp
	g++ -c a3main.cpp

Brig.o: Brig.cpp List.cpp Node.cpp Pirate.cpp Dorc.cpp Borc.cpp Porc.cpp
	g++ -c Brig.cpp

Cell.o: Cell.cpp List.cpp Node.cpp Pirate.cpp Dorc.cpp Borc.cpp Porc.cpp
	g++ -c Cell.cpp

List.o: List.cpp Node.cpp Pirate.cpp
	g++ -c List.cpp

Node.o: Node.cpp Pirate.cpp
	g++ -c Node.cpp

Pirate.o: Pirate.cpp
	g++ -c Pirate.cpp

Dorc.o: Dorc.cpp Pirate.cpp
	g++ -c Dorc.cpp

Borc.o: Borc.cpp Pirate.cpp
	g++ -c Borc.cpp

Porc.o: Porc.cpp Pirate.cpp
	g++ -c Porc.cpp

clean:
	rm -f Main a3main.o Brig.o Cell.o List.o Node.o Pirate.o Dorc.o Borc.o Porc.o

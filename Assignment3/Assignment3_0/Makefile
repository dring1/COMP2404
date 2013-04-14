Main: a3main.o Brig.o Cell.o List.o Node.o Pirate.o Dorc.o Borc.o Porc.o
	g++ -o Main a3main.o Brig.o Cell.o List.o Node.o Pirate.o Dorc.o Borc.o Porc.o

a3main.o: a3main.cpp Brig.o List.o Node.o Pirate.o Dorc.o Borc.o Porc.o
	g++ -c a3main.cpp

Brig.o: Brig.o Cell.o List.o Node.o Pirate.o Dorc.o Borc.o Porc.o
	g++ -c Brig.cpp

Cell.o: Cell.o List.o Node.o Pirate.o Dorc.o Borc.o Porc.o
	g++ -c Cell.cpp

List.o: List.o Node.o Pirate.o
	g++ -c List.cpp

Node.o: Node.o Pirate.o
	g++ -c Node.cpp

Pirate.o: Pirate.o
	g++ -c Pirate.cpp

Dorc.o: Dorc.o Pirate.o
	g++ -c Dorc.cpp

Borc.o: Borc.o Pirate.o
	g++ -c Borc.cpp

Porc.o: Porc.o Pirate.o
	g++ -c Porc.cpp

clean:
	rm -f Main a3main.o Brig.o 

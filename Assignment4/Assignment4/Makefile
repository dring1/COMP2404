run: Main.o Warrior.o Timmy.o Harold.o King.o Pirate.o random.o 
	g++ -o run Main.o Warrior.o Timmy.o Harold.o King.o Pirate.o random.o

Main.o: Main.cpp DList.h Node.h Warrior.cpp Timmy.cpp Harold.cpp King.cpp Pirate.cpp
	g++ -c Main.cpp

Warrior.o: Warrior.cpp random.h
	g++ -c Warrior.cpp

Timmy.o: Timmy.cpp random.h
	g++ -c Timmy.cpp

Harold.o: Harold.cpp random.h
	g++ -c Harold.cpp

King.o: King.cpp
	g++ -c King.cpp

Pirate.o: Pirate.cpp random.h
	g++ -c Pirate.cpp

Clean:
	rm -f run Main.o Warrior.o Timmy.o Harold.o King.o Pirate.o
run: Main.o Controller.o Warrior.o Timmy.o Harold.o King.o Pirate.o Soldier.o random.o 
	g++ -o run Main.o Controller.o Warrior.o Timmy.o Harold.o King.o Pirate.o Soldier.o random.o

Main.o: Main.cpp DList.h Node.h Warrior.cpp Timmy.cpp Harold.cpp King.cpp Pirate.cpp Soldier.cpp
	g++ -c Main.cpp

Controller.o: Controller.cpp DList.h Node.h Warrior.cpp Timmy.cpp Harold.cpp King.cpp Pirate.cpp Soldier.cpp random.h
	g++ -c Controller.cpp

Warrior.o: Warrior.cpp random.h
	g++ -c Warrior.cpp

Timmy.o: Timmy.cpp Warrior.cpp random.h
	g++ -c Timmy.cpp

Harold.o: Harold.cpp Warrior.cpp random.h
	g++ -c Harold.cpp

King.o: King.cpp Warrior.cpp
	g++ -c King.cpp

Pirate.o: Pirate.cpp Warrior.cpp random.h
	g++ -c Pirate.cpp

Soldier.o: Soldier.cpp Warrior.cpp
	g++ -c Soldier.cpp

Clean:
	rm -f run Main.o Warrior.o Timmy.o Harold.o King.o Pirate.o Soldier.o
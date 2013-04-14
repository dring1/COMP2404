#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Warrior.h"
#include "Timmy.h"
#include "Harold.h"
#include "King.h"
#include "Pirate.h"
#include "Soldier.h"
#include "random.h"
#include "DList.h"
#include <string>
using namespace std;



class Controller
{
public:
	Controller();
	~Controller();

	DList<Warrior>* getList();
	Timmy* getTim();
	Harold* getHar();
	King* getKing();

	void game();
	bool alive();
	void move();
	void generate();

	void update();
	void collisions(Warrior*);
	void bounds();

	void initialLoc();

	void winner();




private:
	Timmy *timmy;
	Harold *harold;
	King *king;
	DList<Warrior> *WarriorList;
	string champion;
};
#endif
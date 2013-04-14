#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Warrior.h"
#include "Timmy.h"
#include "Harold.h"
#include "King.h"
#include "Pirate.h"
#include "random.h"
#include "DList.h"



class Controller
{
public:
	Controller();
	~Controller();

	DList<Warrior>* getList();

	void game();
	bool alive();
	void move();
	void generate();




private:
	Timmy *timmy;
	Harold *harold;
	King *king;
	DList<Warrior> *WarriorList;
};
#endif
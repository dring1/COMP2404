#include "Controller.h"


Controller::Controller()
{
	WarriorList = new DList<Warrior>();
	WarriorList->push(timmy);
	WarriorList->push(harold);
	WarriorList->push(king);
}

DList<Warrior>* Controller::getList()
{
	return WarriorList;
}

void Controller::game()
{
	while(alive())
	{
		generate();
		move();
	}
}


bool Controller::alive()
{
	if(timmy->getHealth()==0&&harold->getHealth()==0) return false;
	return true;
}

void Controller::move()
{
	
}

void Controller::generate()
{
	int random_number  = randomInt(1,100);
	int random_number2 = randomInt(1,3);
	if(random_number<51)
	{
		Pirate *p = new Pirate();
		WarriorList->push(p);
		if(random_number2)
	}
}
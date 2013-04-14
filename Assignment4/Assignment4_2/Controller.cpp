#include "Controller.h"


Controller::Controller()
{
	WarriorList = new DList<Warrior>();
	initialLoc();
	WarriorList->push(timmy);
	WarriorList->push(harold);
	WarriorList->push(king);
}

DList<Warrior>* Controller::getList()
{
	return WarriorList;
}

Timmy* Controller::getTim()
{
	return timmy;
}

Harold* Controller::getHar()
{
	return harold;
}

King* Controller::getKing()
{
	return king;
}

void Controller::game()
{
	while(alive())
	{
		generate();
		move();
		update();
	}
}


bool Controller::alive()
{
	if(timmy->getHealth()==0&&harold->getHealth()==0) return false;
	else {return true;}
}

void Controller::move()
{
	if(WarriorList->getSize()>0)
	{
		Node<Warrior> *temp = WarriorList->getFront();
		do{
			
		}while(temp->getNext()!=0);

	}
}

void Controller::generate()
{
	int random_number  = randomInt(1,100);
	if(random_number<51&&WarriorList->getSize()<25)
	{
		Pirate *p = new Pirate();
		p->setX(0);
		p->setY(randomInt(1,6));
		WarriorList->push(p);
		
	}
	if(random_number>34&&WarriorList->getSize()<25)
	{
		Soldier *s = new Soldier();
		s->setY(randomInt(2,4));
		s->setX(24);

		WarriorList->push(s);
	}
}

void Controller::update()
{
	//collisions();
}

void Controller::initialLoc()
{
	timmy->setX(0);
	timmy->setY(randomInt(0,5));
	harold->setX(0);
	harold->setY(randomInt(0,5));
	king->setX(24);
	king->setY(2);
}
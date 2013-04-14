#ifndef HAROLD_H
#define HAROLD_H

#include "Warrior.h"
//class definition
class Harold: public Warrior//set inheritance to public : base class Warrior
{
public://function prototypes
	Harold();
	//virtual functions
	virtual void move();
	virtual void collide(Warrior*);
	virtual void bounds();
};//class definition
#endif
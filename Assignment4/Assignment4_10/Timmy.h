#ifndef TIMMY_H
#define TIMMY_H

#include "Warrior.h"
//class definition
class Timmy: public Warrior//set inheritance to public : Warrior
{
public://function prototypes
	Timmy();
	//virtual functions
	virtual void move();
	virtual void collide(Warrior*);
	virtual void bounds();

};//end class def
#endif
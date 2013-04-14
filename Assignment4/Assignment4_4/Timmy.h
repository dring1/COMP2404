#ifndef TIMMY_H
#define TIMMY_H

#include "Warrior.h"

class Timmy: public Warrior
{
public:
	Timmy();
	virtual void move();
	virtual void collide(Warrior*);
	virtual void bounds();

};
#endif
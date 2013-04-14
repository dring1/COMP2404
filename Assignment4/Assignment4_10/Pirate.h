#ifndef PIRATE_H
#define PIRATE_H

#include <iostream>
#include "Warrior.h"
#include "random.h"
using namespace std;
//class definition
class Pirate: public Warrior//set public inheritance to base class 
{
public://function prototypes
	Pirate();
	//virtual functions
	//enable polymorphism
	virtual void move();
	virtual void collide(Warrior*);
	virtual void bounds();

};//end class definition
#endif
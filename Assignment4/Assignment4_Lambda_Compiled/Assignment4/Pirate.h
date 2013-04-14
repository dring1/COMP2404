#ifndef PIRATE_H
#define PIRATE_H

#include <iostream>
#include "Warrior.h"
#include "random.h"
#include <string>
using namespace std;
//class definition
class Pirate: public Warrior//set public inheritance to base class 
{
public://function prototypes
	Pirate();
	void genType();
	char getType();
	//virtual functions
	//enable polymorphism
	virtual void move();
	virtual void collide(Warrior*);
	virtual void bounds();
private:
	char type;

};//end class definition
#endif
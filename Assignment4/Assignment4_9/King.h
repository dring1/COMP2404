#ifndef KING_H
#define KING_H

#include "Warrior.h"
//class definition
class King: public Warrior//set public inheritance to base class Warrior
{
public://finction prototypes
	King();
	//virtual functions
	//polymorphism enabled
	virtual void move();
	virtual void collide(Warrior*);
	virtual void bounds();
private://private data members
	bool moveDown;
};//end class def
#endif
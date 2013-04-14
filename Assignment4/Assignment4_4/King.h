#ifndef KING_H
#define KING_H

#include "Warrior.h"

class King: public Warrior
{
public:
	King();
	virtual void move();
	virtual void collide(Warrior*);
	virtual void bounds();
private:
	bool moveDown;
};
#endif
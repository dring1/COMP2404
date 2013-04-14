#ifndef PORC_H
#define PORC_H

#include "Pirate.h"

class Porc : public Pirate//public inheritance
{

	friend ostream& operator<<(ostream&,const Pirate&);//friend function
public:
	Porc();//constructor
};
#endif
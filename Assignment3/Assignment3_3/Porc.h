#ifndef PORC_H
#define PORC_H

#include "Pirate.h"

class Porc : public Pirate
{

	friend ostream& operator<<(ostream&,const Pirate&);
public:
	Porc();
};
#endif
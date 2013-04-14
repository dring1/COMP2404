#ifndef DORC_H
#define DORC_H

#include "Pirate.h"

class Dorc : public Pirate
{
	friend ostream& operator<<(ostream&,const Pirate&);
public:
	Dorc();
};
#endif
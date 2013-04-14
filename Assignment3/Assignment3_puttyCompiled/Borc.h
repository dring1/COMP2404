#ifndef BORC_H
#define BORC_H

#include "Pirate.h"



class Borc : public Pirate
{

	friend ostream& operator<<(ostream&,const Pirate&);
public:
	


	Borc();
};
#endif
#ifndef DORC_H
#define DORC_H

#include "Pirate.h"
#include <iostream>
using namespace std;

class Dorc : public Pirate
{
	friend ostream &operator<<(ostream&, const Dorc&);

public:
	Dorc();
};
#endif
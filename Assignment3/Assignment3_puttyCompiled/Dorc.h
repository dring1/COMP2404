#ifndef DORC_H
#define DORC_H

#include "Pirate.h"
#include <iostream>
using namespace std;

class Dorc : public Pirate//opublic inheritance with pirate base class
{
	friend ostream &operator<<(ostream&, const Dorc&);//friend

public:
	Dorc();//constructor
};
#endif
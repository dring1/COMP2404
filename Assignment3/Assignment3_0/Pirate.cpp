#include "Pirate.h"


Pirate::Pirate():cell_num(0)
{
	
}

Pirate::Pirate(int i):cell_num(0),space(i)
{
	
}

void Pirate::setCell(int c)
{
	cell_num = c;
}

int Pirate::getCellNum()
{
	return cell_num;
}

void Pirate::setID(int id)
{
	prisoner_ID = id;
}

int Pirate::getID()
{
	return prisoner_ID;
}

void Pirate::setSpace(int s)
{
	spaceReq = s; 
}

int Pirate::getSpace()
{
	return spaceReq;
}

void Pirate::setType(string t)
{
	tpye = t;
}

string  Pirate::getType()
{
	return type;
}
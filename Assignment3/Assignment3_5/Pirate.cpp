#include "Pirate.h"


ostream &operator<<(ostream& out, const Pirate& p)
{
	out << "----"<< p.getType() <<" id:" << p.getID() << " space:"<< p.getCellNum(); 

	return out;
}


Pirate::Pirate():cell_num(0)
{
	//cout<<"DEF CALLED"<<endl;	
}

Pirate::Pirate(int i,string s):cell_num(0),spaceReq(i),type(s)
{
	//cout<<"ADV CALLED"<<endl;
}

void Pirate::setCell(int c)
{
	cell_num = c;
}

int Pirate::getCellNum() const
{
	return cell_num;
}

void Pirate::setID(int id)
{
	prisoner_ID = id;
}

int Pirate::getID() const
{
	return prisoner_ID;
}

void Pirate::setSpace(int s)
{
	spaceReq = s; 
}

int Pirate::getSpace() const
{
	return spaceReq;
}

void Pirate::setType(string t)
{
	type = t;
}

string  Pirate::getType() const
{
	return type;
}
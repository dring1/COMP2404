#include "Pirate.h"
#include "Brig.h"

// BASE PIRATE CLASS
//overloaded stream insertion
// output pirates in required format
ostream &operator<<(ostream& out, const Pirate& p)
{
	out << "----"<< p.getType() <<" id:" << p.getID() << " space:"<< p.getSpace(); 

	return out;
}


Pirate::Pirate():cell_num(0)
{
	//cout<<"DEF CALLED"<<endl;	
}

Pirate::Pirate(int i,string s):cell_num(0),spaceReq(i),type(s)
{
	//Brig::next_id_num++;
	//cout<<"ADV CALLED"<<endl;
}

void Pirate::setCell(int c)//set pirates cell
{
	cell_num = c;
}

int Pirate::getCellNum() const//return cell #
{
	return cell_num;
}

void Pirate::setID(int id)//set Pirates unique ID
{
	prisoner_ID = id;
}

int Pirate::getID() const //get ID
{
	return prisoner_ID;
}

void Pirate::setSpace(int s)//set space the pirate requires
{
	spaceReq = s; 
}

int Pirate::getSpace() const
{
	return spaceReq;
}

void Pirate::setType(string t) // set pirates type
{
	type = t;
}

string  Pirate::getType() const
{
	return type;
}
#ifndef PIRATE_H
#define PIRATE_H

#include <iostream>
#include <string>//including string lib to allow use of stings
#include <iomanip>
using namespace std;


class Pirate
{

friend ostream& operator<<(ostream&, const Pirate&);//friend function/global

public: //function prototypes
	Pirate();//constructors
	Pirate(int,string);
	
	void setCell(int);//getters / setters
	int getCellNum() const;

	void setID(int);
	int	 getID() const;

	void setSpace(int);
	int  getSpace() const;

	void setType(string);
	string getType() const;

private://private data members
	int cell_num;
	int prisoner_ID;
	int spaceReq;
	string type;

};
#endif
#include<iostream>
using namespace std;
#include "Snack.h"

	Snack::Snack()
	{
		ate = false;
	}
	bool Snack::getState()
	{
		return ate;
	}
	void Snack::setState(bool s)
	{
		ate =s;
	}
	int Snack::getX()
	{
		return x;
	}
	int Snack::getY()
	{
		return y;
	}
	void Snack::setLoc(int xx,int yy)
	{
	 x = xx;
	 y = yy;
	}

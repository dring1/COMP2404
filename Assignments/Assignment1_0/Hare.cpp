#include<iostream>
#include "random.h"
using namespace std;
#include "Hare.h"

	Hare::Hare()
	{
	}
	Hare::Hare(int s_x, int s_y)
	{
		turn = true;
		energy = 20;
		MoveUp = 0;
		MoveSide = 0;
		//restrictions_X = r_x;//pass in size of gameboard to ensure the animals dont go out of bounds
		//restrictions_Y = r_y;
		x = s_x;
		y = s_y;	
	}

	int Hare::horizMove()
	{
		int randNum = randomInt(1,100);
		if(randNum>=1&&randNum<=33) MoveSide =0;
		else if(randNum>=34&&randNum<=66) MoveSide = 1;
		else if(randNum>=67&&randNum<=100)MoveSide = -1;
		return MoveSide;
	}

	
	int Hare::move()
	{
		if(turn==false)
		{
			turn = true;
			return 0;
		}
		
		int P = randomInt(1,100);
		if(P>=1&&P<=20)
		{
                        MoveUp =0;
		}
		else if(P>=21&&P<=40)
		{
                        MoveUp =9;
		}
		else if(P>=41&&P<=50)
                {
                        MoveUp =-12;
                }
		else if(P>=51&&P<=80)
                {
                        MoveUp =1;
                }
		else if(P>=81&&P<=100)
                {
                        MoveUp =-2;
                }
		
		return MoveUp;
	}
	
	void Hare::adjustE(int a)
	{
		if(a==0)
		{
			energy +=0;
		}
		else if(a==9)
		{
			energy -= 3;
		}
		else if(a==-12)
		{
			energy += 0;
		}
		else if(a==1)
		{
			energy -=1;
		}
		else if(a==-2)
		{
			energy -=0;
		}
	}
	
	void Hare::update()
	{
		x += MoveUp;
		y += MoveSide;
		MoveUp = 0;
		MoveSide = 0;
		if(energy<0) energy =0;
		else if(energy>20) energy = 20;
	}
	
	int Hare::getEnergy()
	{
		return energy;
	}
	void Hare::setEnergy(int t)
	{ 
		energy = t;
	}
	
	void Hare::setTurn(bool t)
	{
		turn = t;
	}
	
	bool Hare::getTurn()
	{
		return turn;
	}
	
	int Hare::getX()
	{
		return x;	
	}
	
	int Hare::getY()
	{
		return y;
	}
	void Hare::setX(int xx)
	{	
		x = xx;
	}
	
	void Hare::setY(int yy)
	{
		y=yy;
	}

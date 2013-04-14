#include<iostream>
#include "random.h"
using namespace std;
#include "Hare.h"

	Hare::Hare()//default constructor
	{
	}
	Hare::Hare(int s_x, int s_y)//constructor with parameters
	{
		turn = true;//default values for construct to allow gameplay
		energy = 20;
		MoveUp = 0;
		MoveSide = 0;
		x = s_x;
		y = s_y;	
	}

	int Hare::horizMove()//randomly generate the value for y
	{
		int randNum = randomInt(1,100);
		if(randNum>=1&&randNum<=33) MoveSide =0;
		else if(randNum>=34&&randNum<=66) MoveSide = 1;
		else if(randNum>=67&&randNum<=100)MoveSide = -1;
		return MoveSide;
	}

	
	int Hare::move()//check if Hare can move up
	{
		if(turn==false)
		{
			turn = true;
			return 0;
		}
		
		int P = randomInt(1,100);//move x based on random function
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
	
	void Hare::adjustE(int a)//adjust energy according to type of move made 
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
	void Hare::setSlip(bool s)//set slip
	{
		slip = s;
	}
		
	bool Hare::getSlip()//return slip
	{
		return slip;
	}
	
	void Hare::update()//update hare
	{
		x += MoveUp;//adjust x val
		if( slip == true) y += MoveSide;//adjust y if appropriate
		MoveUp = 0;//reset temp vals
		MoveSide = 0;
		slip = true; 
		if(energy<0) energy =0;//adjust energy bounds
		else if(energy>20) energy = 20;
	}
	
	int Hare::getEnergy()//getters and setters for local variables
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

#include<iostream>
#include "random.h"
using namespace std;
#include "Tortoise.h"

	Tortoise::Tortoise()//default contructor
	{
	}	
	Tortoise::Tortoise(int s_x, int s_y)//contructor with parameters
	{
		turn = true;//default values to allow gameplay
		energy = 20;
		MoveUp = 0;
		MoveSide = 0;
		x = s_x;
		y = s_y;	
	}

	int Tortoise::horizMove()//randomly generate approprate horizontal movement based on probability
	{
		int randNum = randomInt(1,100);
		if(randNum>=1&&randNum<=33) MoveSide =0;
		else if(randNum>=34&&randNum<=66) MoveSide = 1;
		else if(randNum>=67&&randNum<=100)MoveSide = -1;
		return MoveSide;
	}

	
	int Tortoise::move()//returns the x values, the climb based on table given 
	{
		if(turn==false)//can only move if turn is available
		{
			turn = true;
			return 0; 
		}
	
		int P = randomInt(1,100);	
		if(P>=1&&P<=50)
		{
                        MoveUp =3;
		}
		else if(P>=51&&P<=70)
		{
                        MoveUp =-6;
		}
		else if(P>=71&&P<=100)
                {
                        MoveUp =1;
                }
		return MoveUp;
	}
	
        void Tortoise::adjustE(int a)//adjust energy according to type of move
        {
                if(a==3)
                {
                        energy -=2;
                }
                else if(a==-6)
                {
                        energy -= 0;
                }
                else if(a==1)
                {
                        energy -= 1;
                }
        }
	
	void Tortoise::setSlip(bool s)
	{
		slip = s;//enforce slippage
	}
	
	bool Tortoise::getSlip()
	{
		return slip;//return slip
	}
	
	void Tortoise::update()//update tortoise
	{
		x += MoveUp;//adjust x val
		if(slip==true) y += MoveSide;//adjust y if appropriate
		MoveUp = 0;//reset values
		MoveSide = 0;
		slip = true;
		if(energy<0) energy =0;//adjust energy it out of bounds
		else if(energy>20) energy = 20;
	}
	
	int Tortoise::getEnergy() //getters and setters for local variables
	{
		return energy;
	}
	void Tortoise::setEnergy(int t)
	{ 
		energy = t;
	}
	
	void Tortoise::setTurn(bool t)
	{
		turn = t;
	}
	
	bool Tortoise::getTurn()
	{
		return turn;
	}
	
	int Tortoise::getX()
	{
		return x;	
	}
	
	int Tortoise::getY()
	{
		return y;
	}
	void Tortoise::setX(int xx)
	{
		x = xx;
	}
	void Tortoise::setY(int yy)
	{
		y = yy;
	}

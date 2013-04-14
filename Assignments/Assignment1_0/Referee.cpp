#include<iostream>

using namespace std;
#include "Hare.h"
#include "Tortoise.h"
#include "Snack.h"
#include "random.h"
// controller
//checks for collisions
class Referee
{
public:
	Referee(int r_x,int r_y,int s_x,int s_y)
	{
		Hare h(s_x,s_y);
		H = h;
		Tortoise t(s_x,++s_y);
		T = t;
		x = r_x;
		y = r_y;
		hWins = false;
		tWins = false;
	//	Snack Arr[(int)((r_x-2)*(r_y-2)*0.15)];
	//	snackArr = Arr;
	}
	void update()
	{
		//will get location
	}
	void Snack_Generation( int xx,int yy)
	{
		int rx;// = randomInt(1,--xx);
		int ry;// = randomInt(1,--yy);
		for(int i = 0; i<sizeof(Arr); i++)
		{
			rx = randomInt(1,xx-1);
			ry = randomInt(1,yy-1);
			Arr[i].setLoc(rx,ry);
		}	
		//generate 20 unique snack locations
	}
	
	Snack* getArr()
	{
		return Arr;
	}

	bool winner()
	{	
		if(H.getX()>=r_x)
		{
			return hWins = true;
		}
		else if(T.getX()>=r_x)
		{
			return tWins = true;
		}
		else{
			return false;
		}
	}
	
	bool collision_H()
	{
		for(int i = 0;i<sizeof(Arr);i++)
                {
                        if(Arr[i].getX()==H.getX()&&Arr[i].getY()==H.getY()&&Arr[i].getState()==false)
                        {
                                H.setEnergy(20);
                                Arr[i].setState(true);
                                return true;
                        }
                }
			return false;
	}

	bool collision_T()
	{
		for(int i = 0;i<sizeof(Arr);i++)
		{
			if(Arr[i].getX()==T.getX()&&Arr[i].getY()==T.getY()&&Arr[i].getState()==false)
			{
				T.setEnergy(20);
				Arr[i].setState(true);
				return true;
			}
		}		
		return false;
	}

	bool crash()
	{
		if(H.getX() == T.getX() && H.getY()==T.getY())
		{
			int n = H.getEnergy();
			n -=3;
			if(n<0) n = 0;
			H.setEnergy(n);
			return true;
		}
		return false;
	}

	void collisions()
	{
		collision_H();
		collision_T();
		crash();
	}
	
	void printO()
	{
		cout<< sizeof(Arr) << endl;
	}
	
	
		
	void gamePlay()
	{
		while(winner()==false)
		{
			move();		
	
		}
	}
	
	void move()
	{
		int temp1,temp2;
		temp1 = T.getX();
		temp2 = H.getX();
		bool t1 = true;
		bool t2 = true;
		moveX();
		if(temp1>T.getX())//implies a slip, no horiz movement
		{
			t1 = false;
		}
		if(temp2>H.getX())
		{
			t2 = false;
		}
		moveY(t1,t2);
		collisions();
	}
		
	void moveX()
	{
		int temp = T.move();
		int x_T = temp + T.getX();
		while((x_T+temp)<1)
		{
			temp = T.move();
		}
		T.adjustE(temp);
	
		temp = H.move();
		int x_H = temp + H.getX();
		while((x_H+temp)<1)
                {
                        temp = H.move();
                }
		H.adjustE(temp);

	}
	
	void moveY(bool tt,bool hh)
	{
		if(tt==true)// did not slip, gets to perform horiz movement
		{
			int temp = 
		}
	}
		
private:
	Hare H;
	Tortoise T;
	int x;
	int y;
	bool hWins;
	bool tWins;
	Snack Arr[(int)((18*98)*0.15)];
};


#include<iostream>

using namespace std;
#include "Referee.h"	
#include "Hare.h"
#include "Tortoise.h"
#include "Snack.h"
#include "random.h"
	
	Referee::Referee(int r_x,int r_y,int s_x,int s_y)
	{
		Hare h(s_x,s_y);
		H = h;
		Tortoise t(s_x,++s_y);
		T = t;
		x = r_x;
		y = r_y;
		hWins = false;
		tWins = false;
		//printO();
		Snack_Generation(x,y);
	}
	void Referee::Snack_Generation( int xx,int yy)
	{
		int rx;
		int ry;
		for(int i = 0; i<265; i++)
		{
			rx = randomInt(1,xx-1);
			ry = randomInt(1,yy-1);
			Arr[i].setLoc(rx,ry);
		}	
	//generate 20 unique snack locations
	}
	
/*	Snack* getSnack(int xx,int yy)
	{
		
	}*/
	
	Snack* Referee::getArr()
	{
		return Arr;
	}

	bool Referee::winner()
	{	
		if(H.getX()>=x&&T.getX()>=x)
		{
			hWins = true;			
			tWins = true;
			return true;
		}
		else if(H.getX()>=x)
		{
			return hWins = true;
		}
		else if(T.getX()>=x)
		{
			return tWins = true;
		}
		
			return false;
	}
	
	int Referee::getWinner()
	{
		if(hWins&&tWins) return 0;
		else if(hWins)return 1;
		else if(tWins) return 2;
		else{
			return 3;
		}
	}
	bool Referee::collision_H()
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

	void Referee::collision_T()
	{
		for(int i = 0;i<265;i++)
		{
			if(((Arr[i].getX()==T.getX())&&(Arr[i].getY()==T.getY()))&&Arr[i].getState()==false)
			{
				T.setEnergy(20);
				Arr[i].setState(true);
				break;
			}
		}		
		
	}

	bool Referee::crash()
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

	void Referee::collisions()
	{
//		collision_H();
		collision_T();
	//	crash();
	}
	
	void Referee::printO()
	{
		cout<< sizeof(Arr) << endl;
	}
	
	
		
	void Referee::gamePlay()
	{
		while(winner()==false)
		{
			turns();
			move();
			collisions();
			update();
		}
	}
	void Referee::play()
	{
	//	turns();
                move();
               collisions();
                update();
		//winner();
	}
	void Referee::update()
	{
		T.update();
		H.update();
		if(T.getX()>x)T.setX(x);
		if(H.getX()>x)H.setX(x);
	}
	
	void Referee::move()
	{
		int temp1 = T.getX();
		int temp2 = H.getX();
		bool t1 = true;
		bool t2 = true;
		moveX();
		if(temp1>T.getX())//implies a slip, no horiz movement or 0 energy
		{
			t1 = false;
		}
		if(temp2>H.getX())
		{
			t2 = false;
		}
		moveY(t1,t2);
		//collisions();
	}
		
	void Referee::moveX()
	{
		if(T.getTurn()==true)
		{
			int temp = T.move();
			int x_T = T.getX();
			while((x_T+temp)<1)
			{		
				temp = T.move();
			}
		
			T.adjustE(temp);
		}
		if(H.getTurn()==true)
		{
			int temp = H.move();
			int x_H =  H.getX();
			while((x_H+temp)<1)
	                {
        	                temp = H.move();
               		}
			H.adjustE(temp);
		}
		if(T.getTurn()==false)
		{
			if(T.getEnergy()==0) T.setEnergy(10);
			T.setTurn(true);
		}
		if(H.getTurn()==false)
		{
                        if(H.getEnergy()==0) H.setEnergy(10);
                        H.setTurn(true);
		}
	}
	
	void Referee::moveY(bool tt,bool hh)
	{
		if(tt==true)// did not slip, gets to perform horiz movement
		{
			int temp = T.horizMove();
			int y_T =  T.getY();
			while((y_T+temp)<1||(y_T+temp)>18)
			{
				temp = T.horizMove();
			}
		}
		if(hh==true)// did not slip, gets to perform horiz movement
                {
                        int temp = H.horizMove();
                        int y_H =  H.getY();
                        while((y_H+temp)<1||(y_H+temp)>18)
                        {
                                temp = H.horizMove();
                        }
                }

	}
	
	void Referee::turns()
	{
		if(T.getEnergy()==0)
		{
			T.setTurn(false);
		}
		if(H.getEnergy()==0)
		{
			H.setTurn(false);
		}
	}
	
	Tortoise Referee::getTort()
	{
		//Tortoise *t_PTR = T;
		return T;
	}
	Hare Referee::getHare()
	{
		//Hare *h_PTR = H;
		return H;
	}

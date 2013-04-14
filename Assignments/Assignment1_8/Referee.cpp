#include<iostream>

using namespace std;
#include "Referee.h"//ensure that the controller has access to the proper class specific functions	
#include "Hare.h"
#include "Tortoise.h"
#include "Snack.h"
#include "random.h"
	
	Referee::Referee(int r_x,int r_y,int s_x,int s_y)//Constructor including 4 parameters, start locations and board restrictions, allows for more dynamic gameplay if the boar size is to be changed
	{
		Hare h(s_x,s_y);//creating hare model
		H = h;//assigning
		Tortoise t(s_x,++s_y);//creating Tort model
		T = t;//assigning
		x = r_x;//assigning restriction values to controller to ensure restrictions on model
		y = r_y;
		hWins = false;//bool vals to see who wins
		tWins = false;
		Snack_Generation(x,y);//create snacks when controller is created
	}
	void Referee::Snack_Generation( int xx,int yy)//tales board restrictions as parameters to build snacks at proper locations
	{
		int rx;
		int ry;
		for(int i = 0; i<265; i++)
		{
			rx = randomInt(1,xx-1);
			ry = randomInt(1,yy-1);
			Arr[i].setLoc(rx,ry);//build in Snack array
		}	
	}
	
	
	Snack* Referee::getArr()
	{
		return Arr;//return pointer to snack array
	}

	bool Referee::winner()//who wins?
	{	
		if(H.getX()>=x&&T.getX()>=x)//checks the x values to see who has crossed the finish line
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
	
	int Referee::getWinner()//Allows display to know which screen to show
	{
		if(hWins==true&&tWins==true) return 0;
		else if(hWins==true)return 1;
		else if(tWins==true) return 2;
		else{
			return 3;
		}
	}
	void Referee::collision_H()// checks for when Hare lands on a snack and adjust appropriately
	{
		for(int i = 0;i<265;i++)
                {
                        if(Arr[i].getX()==H.getX()&&Arr[i].getY()==H.getY()&&Arr[i].getState()==false)// search through snack array to check if x&y cords match
                        {
				H.setEnergy(20);
                                Arr[i].setState(true);
                                break;
                        }
                }
	}

	void Referee::collision_T()//checks for when Tort lands on a snack and adjust
	{
		for(int i = 0;i<265;i++)
		{
			if((Arr[i].getX()==T.getX()&&(Arr[i].getY()==T.getY()))&&Arr[i].getState()==false)//search through snack array to check for x&y coords
			{
				T.setEnergy(20);
				Arr[i].setState(true);
				break;
			}
		}		
		
	}

	bool Referee::crash()//check if the x&y vals of Tort/Hare match and adjust as required
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

	void Referee::collisions()//simplicity of methods, not to cluster all the collision related functions
	{
		collision_H();
		collision_T();
		crash();
	}
	
	void Referee::printO()//testing code
	{
		cout<< sizeof(Arr) << endl;
	}
	
	
		
	void Referee::play()//core of the game. Calls appropriate functions in order for game to play properly
	{
		turns();//check if H or T have a valid turn
                move();//move accordingly
                collisions();//check for collisions
                update();//update
		winner();//did someone win?>
	}
	void Referee::update()//calls H&T upates and adjust more x if overextended
	{
		T.update();
		H.update();
		if(T.getX()>x)T.setX(x);
		if(H.getX()>x)H.setX(x);
	}
	
	void Referee::move()//move function of program
	{
		int temp1 = T.getX();//temp vals to check if there is a slip
		int temp2 = H.getX();
		bool t1 = true;//if there is a slip, hold in this bool
		bool t2 = true;
		moveX();//call x val movement
		if(T.getX()<temp1)//implies a slip, no horiz movement or 0 energy for T
		{
			t1 = false;
			T.setSlip(t1);
		}
		if(temp2>H.getX())// implies a slip
		{
			t2 = false;
			H.setSlip(t2);
		}
		moveY();
		//collisions();
	}
		
	void Referee::moveX()
	{
		if(T.getTurn()==true)//only works if a turn is possible
		{
			int temp = T.move();//temp x
			int x_T = T.getX();//hold current position
			while((x_T+temp)<1)//search for a move so long as it is within the restrictions
			{		
				temp = T.move();//continiously recalculate til condition is met
			}
		
			T.adjustE(temp);//change energy accordingly
		}
		else if(T.getTurn()==false)//otherwise, miss turn adjust energy
                {
                        if(T.getEnergy()==0) T.setEnergy(10);
                        T.setTurn(true);
                }
		if(H.getTurn()==true)//temp x
		{
			int temp = H.move();//same as Tortoise move/just above
			int x_H =  H.getX();
			while((x_H+temp)<1)
	                {
        	                temp = H.move();
               		}
			H.adjustE(temp);
		}
		else if(H.getTurn()==false)
		{
                        if(H.getEnergy()==0) H.setEnergy(10);
                        H.setTurn(true);
		}
	}
	
	void Referee::moveY()
	{
		if(T.getSlip()==true)// did not slip, gets to perform horiz movement
		{
			int temp = T.horizMove();
			int y_T =  T.getY();
			while((y_T+temp)<1||(y_T+temp)>18)//ensure that the move is within the restrictions
			{
				temp = T.horizMove();
			}
		}
		if(H.getSlip()==true)// did not slip, gets to perform horiz movement
                {
                        int temp = H.horizMove();
                        int y_H =  H.getY();
                        while((y_H+temp)<1||(y_H+temp)>18)//ensure that the move is within the restrictions
                        {
                                temp = H.horizMove();
                        }
                }

	}
	
	void Referee::turns()// checks energy and sets turns accordingly
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
	
	int Referee::getTX()//getters & setters to communicate with view and main
	{
		return T.getX();
	}
	int Referee::getTY()
	{
		return T.getY();
	}
	int Referee::getHX()
	{
		return H.getX();
	}
	int Referee::getHY()
	{
		return H.getY();
	}
	int Referee::getTE()
	{
		return T.getEnergy();
	}
	int Referee::getHE()
	{
		return H.getEnergy();
	}
	/*Tortoise Referee::getTort()
	{
		//Tortoise *t_PTR = T;
		return T;
	}
	Hare Referee::getHare()
	{
		//Hare *h_PTR = H;
		return H;
	}*/

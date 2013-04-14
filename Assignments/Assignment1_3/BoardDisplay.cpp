#include<iostream>
#include<ncurses.h>
#include<stdlib.h>
using namespace std;

#include "BoardDisplay.h"


	BoardDisplay::BoardDisplay()
	{
		cout<<"Default Contrustor"<<endl;
	}

	void BoardDisplay::Start_Screen()
	{	
		initscr();
		move(11,20);
	        addstr("||===========================================||");
	        move(12,20);
	        addstr("||                                           ||");
	        move(13,20);
	        addstr("||           THE TORTOISE CHRONICLES         ||");
	        move(14,20);
	        addstr("||            Tortoise VS The Hare           ||");
	        move(15,20);
	        addstr("||                                           ||");
	        move(16,20);
	        addstr("||===========================================||");
        	move(19,20);
	        addstr("     HARE = '%'             TORTOISE = '@'");
		move(23,20);
		refresh();
		clear();
		sleep(2);
        	refresh();
	
	}
	
	void BoardDisplay::Board_Screen()
	{
		move(0,0);
		addstr("////////////////////////////////////////////////////////////////////////////////////////////////////");
		move(1,0);
		addstr("/	       											   /");
		move(2,0);
		addstr("/											           /");
		move(3,0);
		addstr("/												   /");
		move(4,0);
		addstr("/												   /");
		move(5,0);
		addstr("/												   /");
		move(6,0);
		addstr("/												   /");
		move(7,0);
		addstr("/												   /");
		move(8,0);
		addstr("/												   /");
		move(9,0);
		addstr("/												   /");
		move(10,0);
		addstr("/												   /");
		move(11,0);
		addstr("/												   /");
		move(12,0);
		addstr("/												   /");
		move(13,0);
		addstr("/												   /");
		move(14,0);
		addstr("/												   /");
		move(15,0);
		addstr("/												   /");
		move(16,0);
		addstr("/												   /");
		move(17,0);
		addstr("/												   /");
		move(18,0);
		addstr("/												   /");
		move(19,0);
		addstr("////////////////////////////////////////////////////////////////////////////////////////////////////");
		move(20,0);
		addstr("	        	HARE ENERGY			 TORTOISE ENERGY             		    "); 
		refresh();
	}
	
	void BoardDisplay:: Winner_Screen_T()
	{
		clear();
		refresh();
		sleep(2);
		move(10,0);
		addstr("							WE HAVE A WINNER");
		move(11,0);
		addstr("			        !!!!!!!!!!!!!!!!!!!!TORTOISE HAS WON THE RACE!!!!!!!!!!!!!!!");
	}

	void BoardDisplay::Winner_Screen_H()
        {
                clear();
                refresh();
                sleep(2);
                move(10,0);
                addstr("                                                        WE HAVE A WINNER");
                move(11,0);
                addstr("                                   !!!!!!!!!!!!!!!!!!!HARE HAS WON THE RACE!!!!!!!!!!!!!!!");
        }

	void BoardDisplay::hareStart(int x, int y)
	{
		move(x,y);
		addstr("%");
		refresh();
	}

	void BoardDisplay::tortStart(int x, int y)
	{
		move(x,y);
		addstr("@");
		refresh();
	}
	
	void BoardDisplay::buildSnack(int x, int y)
	{
		move(x,y);
                addstr("$");
                refresh();
	}
	//WINNER SCREEN
	
	
	
/*	void set_T_Loc(int x,int y)
	{
		x_T = x;
		y_T = y;
	}
	void set_H_Loc(int x,int y)
	{
		x_H = x;
		y_H = y;
	}
	void set_T_x(int x)
	{
		

	}
	int x_T,y_T;
	int x_H,y_H;*/


#include<iostream>
#include<ncurses.h>
#include<stdlib.h>
using namespace std;

#include "BoardDisplay.h"
#include "Referee.h"

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
		addstr("          HARE ENERGY :               TORTOISE ENERGY :                              "); 
		refresh();
	}
	
	void BoardDisplay:: Winner_Screen_T()
	{
		clear();
		//refresh();
		sleep(2);
		move(10,0);
		addstr("							WE HAVE A WINNER");
		move(11,0);
		addstr("			        !!!!!!!!!!!!!!!!!!!!TORTOISE HAS WON THE RACE!!!!!!!!!!!!!!!");
		refresh();
	}

	void BoardDisplay::Winner_Screen_H()
        {
                clear();
                //refresh();
                sleep(2);
                move(10,0);
                addstr("                                                        WE HAVE A WINNER");
                move(11,0);
                addstr("                                   !!!!!!!!!!!!!!!!!!!HARE HAS WON THE RACE!!!!!!!!!!!!!!!");
		refresh();
        }

	void BoardDisplay::Tie_Screen()
	{
		clear();
		refresh();
		sleep(1);
		move(10,0);
		addstr("                                                        !WE HAVE A TIE!");
		move(11,0);
		addstr("                                                    To play again press 's'");
		refresh();
	}

	
	void BoardDisplay::hareStart(int x, int y)
	{
		move(x,y);
		x_H = x;
		y_H = y;
		addstr("%");
		refresh();
	}

	void BoardDisplay::tortStart(int x, int y)
	{
		move(x,y);
		x_T = x;
		y_T = y;
		addstr("@");
		refresh();
	}
	
	void BoardDisplay::buildSnack(int x, int y)
	{
		move(x,y);
		x_H = x;
		y_H = y;
                addstr("$");
                refresh();
	}

	void BoardDisplay::snacks(Referee ref)
	{
		for(int i  = 0; i < 265; i++)
        	{
                	buildSnack((ref.getArr()+i)->getY(),(ref.getArr()+i)->getX());
        	} 
	}
		
	void BoardDisplay::update(Referee ref)
	{
		updateH(ref);
		updateT(ref);
		refresh();
	}
	
	void BoardDisplay::updateH(Referee ref)
	{
		move(x_H,y_H);
		addstr(" ");
		x_H = ref.getHY();
		y_H = ref.getHX();
		move(x_H,y_H);
		addstr("%");
		int e = ref.getHE();
		move(20,27);
		printw("  ");
		move(20,27);
		printw("%d",e);	
	}

	void BoardDisplay::updateT(Referee ref)
	{
		move(x_T,y_T);
                addstr(" ");
                x_T = ref.getTY();
                y_T = ref.getTX();
                move(x_T,y_T);
                addstr("@");
		int e = ref.getTE();
		move(20,59);
		printw("  ");
		move(20,59);
		printw("%d",e);
	}
	
	int BoardDisplay::replay()
	{
		//clear();
		//refresh();
		move(13,0);
		addstr("                                               Would you like to play again?");
		move(14,0);
		addstr("                                 !!!Please enter s to play against or any other key to quit!!!");
		char i = getch();
		
		/*while(i!='q'||i!='Q'||i!='s'||i!='S')
		{
			i = getch();
		}*/
		if(i=='s'||i=='S') return 0;
		return 1;
	}
	
	void BoardDisplay::restart()
	{
		clear();
	//	refresh();
		Start_Screen();
		Board_Screen();
		refresh();
	}

#include<iostream>//test
#include<ncurses.h>//display
#include<stdlib.h>//used for test purposes
using namespace std;

#include "BoardDisplay.h"
#include "Referee.h"

	BoardDisplay::BoardDisplay()//constructor
	{
		cout<<"Default Contrustor"<<endl;
	}

	void BoardDisplay::Start_Screen()//Start screen for the game!
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
	
	void BoardDisplay::Board_Screen()//creating the board for the game
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
	
	void BoardDisplay:: Winner_Screen_T()//displays if a char is to win!
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

	void BoardDisplay::Winner_Screen_H()//display if a char is to win!
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

	void BoardDisplay::Tie_Screen()//display if a char is to win!
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

	
	void BoardDisplay::hareStart(int x, int y)//starting locations for racers
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
	
	void BoardDisplay::buildSnack(int x, int y)//create a snack on the board from the array in the controller
	{
		move(x,y);
		x_H = x;
		y_H = y;
                addstr("$");
                refresh();
	}

	void BoardDisplay::snacks(Referee ref)// create 15% of the board in snacks
	{
		for(int i  = 0; i < 265; i++)
        	{
                	buildSnack((ref.getArr()+i)->getY(),(ref.getArr()+i)->getX());
        	} 
	}
		
	void BoardDisplay::update(Referee ref)//update method to ensure things move and appear when appropriate
	{
		updateH(ref);
		updateT(ref);
		refresh();
	}
	
	void BoardDisplay::updateH(Referee ref)
	{
		move(x_H,y_H);
		addstr(" ");
		x_H = ref.getHY();//coordinate ncurses move function
		y_H = ref.getHX();
		move(x_H,y_H);
		addstr("%");//display the char
		int e = ref.getHE(); // display the char's energy
		move(20,27);
		printw("  ");
		move(20,27);
		printw("%d",e);	// numerical representation
	}

	void BoardDisplay::updateT(Referee ref)//same as Hare update
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
	
	int BoardDisplay::replay()//Screen will appear at the end of game asking if user would like to replay
	{
		//clear();
		//refresh();
		move(13,0);
		addstr("                                               Would you like to play again?");
		move(14,0);
		addstr("                                 !!!Please enter s to play against or any other key to quit!!!");
		char i = getch();//check users decision
		
		if(i=='s'||i=='S') return 0;
		return 1;
	}
	
	void BoardDisplay::restart()//restart the board
	{
		clear();
	//	refresh();
		Start_Screen();
		Board_Screen();
		refresh();
	}

	void BoardDisplay::waitingGame()//delay start until user has entered a char
	{
		move(28,0);
		addstr("                                                Hit any key to start the game!");
		getch();
		refresh();
	}

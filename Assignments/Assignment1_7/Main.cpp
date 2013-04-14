#include<iostream>
#include"ncurses.h"
using namespace std;

#include "BoardDisplay.h"
#include "Referee.h"


int main()
{
	BoardDisplay Display;
	Display.Start_Screen();
	Display.Board_Screen();
	bool value = true;
	

	Referee ref(100,19,1,9);
	do{
	Display.snacks(ref);
	Display.hareStart(ref.getHare().getY(),ref.getHare().getX());
	Display.tortStart(ref.getTort().getY(),ref.getTort().getX());
	
	while(ref.winner()==false)
	{
		ref.play();
		Display.update(ref);
	//	sleep(1);
	}
	
	sleep(2);
	
	int w = ref.getWinner();
	if(w==0)
	{
		Display.Tie_Screen();
	}
	else if(w==1)
	{
		Display.Winner_Screen_H();
	}
	else if(w==2)
	{
		Display.Winner_Screen_T();
	}
	sleep(2);	
	if(Display.replay()==0)
	{
		Display.restart();	
	}
	else
	{
		value = false;
		break;
	}
	}while(value=true);
	endwin();
	
return 0;
}

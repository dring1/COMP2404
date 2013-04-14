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
	
	Referee ref(100,19,1,9);
	Display.hareStart(ref.getHare().getY(),ref.getHare().getX());
	Display.tortStart(ref.getTort().getY(),ref.getTort().getX());
	/*while(ref.winner()==false)
	{
		ref.play();
	}*/
	sleep(2);
	
	for(int i  = 0; i < 265; i++)
	{
		Display.buildSnack((ref.getArr()+i)->getY(),(ref.getArr()+i)->getX());
	}
	sleep(9);
	endwin();
return 0;
}

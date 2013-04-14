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
	Display.snacks(ref);
	Display.hareStart(ref.getHare().getY(),ref.getHare().getX());
	Display.tortStart(ref.getTort().getY(),ref.getTort().getX());
	//	int derp = 0;
//	while(ref.getHare().getX()<19||ref.getTort().getX()<19)
//	{
		ref.play();
		Display.update(ref);
		//sleep(1);
//	}
	sleep(9);
	endwin();
	
return 0;
}

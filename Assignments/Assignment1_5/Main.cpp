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
	while(ref.winner()==false)
	{
		ref.play();
		Display.update(ref);
		sleep(1);
	}	//sleep(1);
//	
	/*int xx = ref.getWinner();
	if(xx==0) cout<< "DERP" << endl;
	else if(xx==1) cout<< "ERP" << endl;
	else if(xx==2) cout<< "RP" << endl;
	else if(xx==3) cout<< "P" << endl;
	sleep(2);*/
	sleep(2);
	int w = ref.getWinner();
	if(w==0)
	
	
	if(Display.replay()==0)
	{	
	}
	else if(Display.replay()==1)
	{
	}
	endwin();
	
return 0;
}

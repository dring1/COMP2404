#include<iostream>//Allowing output to the screen, used for testing purposes
#include"ncurses.h"//Use of curses library
using namespace std;

#include "BoardDisplay.h"//attaching the view to the main program
#include "Referee.h"//attaching controller


int main()// main function
{
	BoardDisplay Display;//Creating View
	Display.Start_Screen();//View
	Display.Board_Screen();//View
	bool value = true;//bool to allow replayability
	

	Referee ref(100,19,1,9);//creating controller 
	do{//start the game off in a loop if user desires to replay
	Display.waitingGame();//displays
	Display.snacks(ref);
	Display.hareStart(ref.getHY(),ref.getHX());//placing tort and hare
	Display.tortStart(ref.getTY(),ref.getTX());
	
	while(ref.winner()==false)//until a character meets the winning condition
	{// continue to move them around the board, updating the display
		ref.play();//movement of the characters
		Display.update(ref);//hooking up the controller to the display
		sleep(1);//Delay in the move to make the race watchable
	}
	
	sleep(1);
	
	int w = ref.getWinner();//now to find out who the winner is
	if(w==0)
	{
		Display.Tie_Screen();//a tie btween the racers!
	}
	else if(w==1)
	{
		Display.Winner_Screen_H();//Hare wins
	}
	else if(w==2)
	{
		Display.Winner_Screen_T();//Tort wins
	}
	sleep(2);	
	if(Display.replay()==0)//User can choose to play again
	{
		Display.restart(); //if so , start the loop from again
	}
	else
	{
		value = false;//if not. break out of the loop and exit the program
		break;
	}
	}while(value=true);
	endwin();//close ncurses
	
return 0;
}

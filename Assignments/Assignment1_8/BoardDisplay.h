#ifndef BOARDDISPLAY_H
#define BOARDDISPLAY_H

#include "Referee.h"

class BoardDisplay//creating class for the view
{	
public:	
	BoardDisplay();
	void Start_Screen();//function prototypes explained in source file in more detail
	void Board_Screen();//mountain display
	void Winner_Screen_T();//winner
	void Winner_Screen_H();
	void Tie_Screen();//tie
	void hareStart(int,int);//char representation for racers
	void tortStart(int,int);
	void buildSnack(int,int);//build snacks on board
	void snacks(Referee);
	void update(Referee);//update display
	void updateH(Referee);
	void updateT(Referee);
	int replay();
	void restart();
	void waitingGame();
private:
	int x_T,y_T;//holds the x val & y val for Tortoise to ensure proper location changes in view
	int x_H,y_H;//holes the x val & y val for Hare to ensure proper locations changes
};
#endif

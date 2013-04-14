#ifndef BOARDDISPLAY_H
#define BOARDDISPLAY_H

#include "Referee.h"

class BoardDisplay
{	
public:	
	BoardDisplay();
	void Start_Screen();
	void Board_Screen();
	void Winner_Screen_T();
	void Winner_Screen_H();
	void hareStart(int,int);
	void tortStart(int,int);
	void buildSnack(int,int);
	void snacks(Referee);
	void update(Referee);
	void updateH(Referee);
	void updateT(Referee);
private:
	int x_T,y_T;
	int x_H,y_H;
};
#endif

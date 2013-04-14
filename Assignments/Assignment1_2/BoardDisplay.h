#ifndef BOARDDISPLAY_H
#define BOARDDISPLAY_H


class BoardDisplay
{	
public:	
	BoardDisplay();
	void Start_Screen();
	void Board_Screen();
	void Winner_Screen_T();
	void Winner_Screen_H();
private:
	int x_T,y_T;
	int x_H,y_H;
};
#endif

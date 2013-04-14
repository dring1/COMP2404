#ifndef HARE_H
#define HARE_H

class Hare//class definition
{
public://function prototypes
	Hare();//def contructor
	Hare(int , int);// para construc
	int horizMove();//movement functions
	int  move();
	void adjustE(int);//bounds checking
	void setSlip(bool);//getters/setters
	bool getSlip();
	void update();//update
	int getEnergy();
	void setEnergy(int );
	void setTurn(bool );
	bool getTurn();
	int getX();
	int getY();
	void setX(int);
	void setY(int);
private:	
	int x,y;//location on mountain
	int MoveUp;//temp x val
	int MoveSide;//temp y val
	int energy;//hold Hare energy
	bool turn;//Hare turn?
	bool slip;//did the hare slip?
	
};
#endif

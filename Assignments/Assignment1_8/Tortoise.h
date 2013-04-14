#ifndef TORTOISE_H
#define TORTOISE_H

class Tortoise //class definition
{
public://function prototypes
	Tortoise();//def constructor
	Tortoise(int , int);// para construc
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
	int MoveUp;//temp x value
	int MoveSide;//temp y value
	int energy;//enery for Tort
	bool turn;// Tort's Turn
	bool slip;//did the tort slip?
};
#endif

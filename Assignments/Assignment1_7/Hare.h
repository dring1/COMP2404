#ifndef HARE_H
#define HARE_H

class Hare
{
public:
	Hare();
	Hare(int , int);
	int horizMove();
	int  move();
	void adjustE(int);
	void setSlip();
	void update();
	int getEnergy();
	void setEnergy(int );
	void setTurn(bool );
	bool getTurn();
	int getX();
	int getY();
	void setX(int);
	void setY(int);
private:	
	int x,y;
	int MoveUp;
	int MoveSide;
	int energy;
	bool turn;
	bool slip;
	
};
#endif

#ifndef SNACK_H
#define SNACK_H



class Snack
{
public:
	Snack();
	bool getState();
	void setState(bool s);
	int getX();
	int getY();
	void setLoc(int ,int );
private:
	bool ate;
	int x;
	int y;
};
#endif

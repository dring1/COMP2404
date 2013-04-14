#ifndef WARRIOR_H
#define WARRIOR_H

//class definition
class Warrior
{
public://function prototypes
	Warrior();
	Warrior(int,int,int);

	void setHealth(int);
	void setArmor(int);
	void setStrength(int);


	int getHealth();
	int getArmor();
	int getStrength();

	void damage(int);

	void setX(int);
	void setY(int);

	int getX();
	int getY();
	//virtual functions
	/*polymorphism enabled*/
	virtual void move();
	virtual void collide(Warrior*);
	virtual void bounds();


private://private data members
	int health;
	int armor;
	int strength;
	int x;
	int y;

};
#endif
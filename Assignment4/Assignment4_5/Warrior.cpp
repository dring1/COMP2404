#include "Warrior.h"
#include "random.h"
#include <iostream>
using namespace std;

Warrior::Warrior()
{
	x = 0;
	y = 0;	
}

Warrior::Warrior(int h,int a, int s):health(h),armor(a),strength(s)
{
	x = 0;
	y = 0;

}

void Warrior::setHealth(int h)
{
	health = h;
}
void Warrior::setArmor(int a)
{
	armor= a;
}
void Warrior::setStrength(int s)
{
	strength=s;
}


int Warrior::getHealth()
{
	return health;
}
int Warrior::getArmor()
{
	return armor;
}
int Warrior::getStrength()
{
	return strength;
}

void Warrior::damage(int d)
{
	if((d-armor)>=0)
		health = health - (d - armor);
	else health = health - (armor-d);
	if(health < 0 ) health = 0;
}

void Warrior::setX(int x_loc)
{
	x = x_loc;
}
void Warrior::setY(int y_loc)
{
	y = y_loc;
}

int Warrior::getX()
{
	return x;
}
int Warrior::getY()
{
	return y;
}

void Warrior::move()
{
	
}

void Warrior::collide(Warrior *war)
{
	
}

void Warrior::bounds()
{
	
}
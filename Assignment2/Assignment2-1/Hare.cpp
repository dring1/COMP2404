#include "random.h"
#include "Hare.h"

Hare::Hare(): x(0),health(30),strength(8),armor(5)
{
	
}
Hare::Hare(int xx,int h,int str ,int a)//x,y,health,strength,armor
{
	x = xx;	
	health = h;
	strength = str;
	armor = a;
}
/*Hare::Hare(const Hare &) //Copy constructor
{
	
}
*/
void Hare::swordPlay(bool s_)
{
	sword = s_;
	if(sword == true)
		strength+=3;
}
void Hare::setHealth(int h_)
{
	health = h_;
}
void Hare::setStrength(int s_)
{
	strength=s_;
}
void Hare::setArmor(int a_)
{
	armor=a_;
}
void Hare::setX(int x_)
{
	x = x_;
}
void Hare::update()
{
	
}
bool Hare::getSword()
{
	return sword;
}
int  Hare::getX()
{
	return x;
}
int	 Hare::getHealth()
{
	return health;
}
int  Hare::getStrength()
{
	return strength;
}
int  Hare::getArmor()
{
	return armor;
}
void Hare::damage(int d)
{
	if(d>0) health = health - d;
	if(health<0) health = 0;
}
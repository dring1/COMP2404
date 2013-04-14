#include "random.h"
#include "Pirate.h"


Pirate::Pirate()//default constructor
{
	health = 20;
	armor = randomInt(2,4);
	strength = randomInt(4,7);
}
void Pirate::setX(int x_)//getters and setter for private data members
{
	x = x_;
}
void Pirate::setHealth(int h_)
{
		health = h_;
}
void Pirate::setStrength(int s_)
{
	strength = randomInt(4,7);
}
void Pirate::setArmor(int a_)
{
	armor = randomInt(2,4);
}
void Pirate::update()
{
	
}
int  Pirate::getX()//getters and setter for private data members
{
	return x;
}
int  Pirate::getHealth()
{
	return health;
}
int	 Pirate::getStrength()
{
	return strength;
}
int Pirate::getArmor()
{
	return armor;
}
int Pirate::attack()
{
	return randomInt(strength,(2*strength));
}
void Pirate::damage(int d)
{
	if(d>0) health = health - d;//ignore damage in negative
	if(health<0) health = 0;//adjust health 
}
#include "Pirate.h"

Pirate::Pirate():Warrior(20,randomInt(2,4),randomInt(4,7))
{
	genType();
}

void Pirate::genType()
{
	int t = randomInt(1,100);
	if( t<34 ) type = "dorc";
	else if(t>=34&&t<66) type = "porc";
	else type = "borc";
}
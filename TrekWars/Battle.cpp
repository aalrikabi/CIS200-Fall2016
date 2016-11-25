#include "stdafx.h"
#include "Battle.h"
#include "Ship.h"
#include <iostream>
#include<string>
using namespace std;

Battle::Battle(string shipname, int xlocation, int ylocation, Alignment shipalign)
	:Ship(" ", xlocation, ylocation, shipalign,0,0,0)
{
	//Ship::setRanage(10); //range is 10, maxHealth =100 ,attack = 10
	//	Ship::setmaxHealth(100);
	//	Ship::setAttack(10);
	Ship::range=10;
	Ship::maxHealth=100;
	Ship::attackPower=10;
	torpedoes=10;
	Ship::name=shipname;
	//Ship::xLoc=xlocation;
	//Ship::yLoc=ylocation;
	//Ship::align= shipalign;
	Ship::currHealth=maxHealth;
}

Battle::~Battle()
{
}

// always moves along the vector (-1, -1)
void Battle::move()
{
	Ship::setXloc(Ship::getX()-1);
	Ship::setYLoc(Ship::getY()-1);
}
//attacks and fires torpedo >0 and does additional 10 damage, 1 less torpedo
void Battle::attack( Ship *target)
{
	if (target->getAlign()== getAlign())
	{
	}
	else if (torpedoes > 0 && target->getCurrentHealth() > 0)  // make sure we have torpedoes to attack
	{
		if ( (target->getY() < (getY()+10)) && (target->getY() > (getY()-10)) )  //make sure the ship in in range of Y
		{
			//target->setCurrentHealth(target->getCurrentHealth() -10);
			target->accessDamage(10);
			torpedoes--;
		}
		else if ( (target->getX() < (getX()+10)) && (target->getX() > (getX()-10)))// make sure the ship in range of X
		{
			//target->setCurrentHealth(target->getCurrentHealth() -10);
			target->accessDamage(10);
			torpedoes--;
		}
	}
}
// also indicates number of torpedos
string Battle::status()
{
	string statusstring =" ";
	statusstring= "\n name: " + name +"\n type: Battle Ship" + "\n Torpedoes: "
		+ to_string(torpedoes) + "\n Health: " + to_string(currHealth)
		+ "\n Location: " + "(" + to_string(getX()) + "," + to_string(getY()) + ")\n";
	return statusstring;
}
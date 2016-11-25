#pragma once
#include "stdafx.h"
#include "Battle.h"
#include "Ship.h"
#include <iostream>
#include<string>
#include<math.h>
using namespace std;
class Battle :
	public Ship
{
public:

	Battle::Battle(string shipname, int xlocation, int ylocation, Alignment shipalign)
		:Ship(shipname, xlocation, ylocation, shipalign,100,10,0)
	{
		torpedoes=10;
		Ship::name=shipname;
	};

	Battle::~Battle()
	{
	};

	// always moves along the vector (-1, -1)
	void Battle::move()
	{
		if (Ship::getCurrentHealth() >0)  //make sure the ship is not dead
		{
			Ship::setXloc(Ship::getX()-1);
			Ship::setYLoc(Ship::getY()-1);

			//if(Ship::getCurrentHealth() < Ship::maxHealth)  // allow the increment of 1 health until reaching the max.
			Ship::setCurrentHealth(Ship::getCurrentHealth() +1);
		}
	};
	//attacks and fires torpedo >0 and does additional 10 damage, 1 less torpedo
	void Battle::attack( Ship *target)
	{
		///double hypotenuse= sqrt( pow( abs(target->getX())-getX(), 2) + pow( abs(target->getY()) -getY() ,2) );
		hypotenuse= Ship::calculateHypotenuse(getX(), getY(), target->getX(), target->getY());
		if ( (target->getAlign() == getAlign())
			&& (target->getAlign() != chaotic)
			&& ( getAlign() != chaotic) )
		{
			//cannot attacke friend
		}
		else if ( target->getCurrentHealth() > 0 && hypotenuse<= 10 )  // make sure the enemy is not dead
		{
			if (torpedoes >0)
			{
				cout<<"inrange Battle"<<endl;
				target->accessDamage(20);
				torpedoes--;
			}
			else
			{
				target->accessDamage(10);
			}
			//}
		}
	};
	// also indicates number of torpedos
	string Battle::status()
	{
		string statusstring =" ";
		statusstring= "\n name: " + getName() +
			"\n type: Battle Ship" +
			"\n Torpedoes: "+ to_string(getTotalTorpedos()) +
			"\n Health: " + to_string(getCurrentHealth())
			+ "\n Location: " + "(" + to_string(getX()) + "," + to_string(getY()) + ")\n";
		return statusstring;
	};

	//return the total torpedos
	int Battle::getTotalTorpedos(){ return torpedoes;	};
	double Battle::gethypotenuse(){ return hypotenuse; };
private:
	int torpedoes;
	double hypotenuse;
};

//Repair (derived from Cruiser class) range is 25, maxHealth = 20
//method
//attack(target: Ship *) : void //its attack repairs a ship of own kind to max health

#pragma once

#include "Cruiser.h"
class Repair :
	public Cruiser
{
public:
	Repair(string shipname, int xlocation, int ylocation, Alignment shipalign)
		:Cruiser(shipname, xlocation, ylocation, shipalign,25,20)
	{ };

	~Repair(void);

	void Repair::attack( Ship *target)
	{
		int rangeValue=50;
		int attackValue=5;

		double hypotenuse= Ship::calculateHypotenuse(getX(), getY(), target->getX(), target->getY());

		if ( (target->getAlign() != getAlign())
			|| (target->getAlign() == chaotic)
			|| ( getAlign() == chaotic) )
		{
			int xx=0;
		}
		else if ( target->getCurrentHealth() > 0 && hypotenuse<= rangeValue )  // make sure the enemy is not dead
		{
			target->setCurrentHealth(target->getmaxHealth());
			cout<<"inrange Repair"<<endl;
		}
	};
};

//
//Corvette (derived from Ship class) range is 25, maxHealth =20
//		method
//		// always moves along the vector (5, 5)
//		move()
//		attack(target: *Ship) : void// Everyone loves corvettes so their attack
//		// flips ships in range to its state
//		// (if self is us, turns them to us,
//		// if self is them, turns us to them)

#pragma once
#include "ship.h"
class Corvette :
	public Ship
{
public:
	Corvette(string shipname, int xlocation, int ylocation, Alignment shipalign)
		:Ship(shipname, xlocation, ylocation, shipalign,20,25,0){};
	~Corvette(void);

	//attacks and fires torpedo >0 and does additional 10 damage, 1 less torpedo
	void Corvette::attack( Ship *target)
	{
		double hypotenuse= Ship::calculateHypotenuse(getX(), getY(), target->getX(), target->getY());

		if ( (target->getAlign() == getAlign())
			|| (target->getAlign() == chaotic)
			|| ( getAlign() == chaotic) )
		{
			//cannot attacke friend
			int notavailable=0;
		}
		else if ( target->getCurrentHealth() > 0 && hypotenuse<= 25)  // make sure the enemy is not dead
		{
			/// triangle hypotenuse range
			target->changeAlign();
			cout<<"inrange Corvette"<<endl;
		}
	};
	// always moves along the vector (5, 5)
	void Corvette::move()
	{
		if (Ship::getCurrentHealth() >0)  //make sure the ship is not dead
		{
			Ship::setXloc(Ship::getX()+5);
			Ship::setYLoc(Ship::getY()+5);

			//if(Ship::getCurrentHealth() < Ship::maxHealth)  // allow the increment of 1 health until reaching the max.
			Ship::setCurrentHealth(Ship::getCurrentHealth() +1);
		}
	};
};

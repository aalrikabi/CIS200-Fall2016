//
//Corvette (derived from Ship class) range is 25, maxHealth =20
//		method
//		// always moves along the vector (5, 5)
//		move()
//		attack(target: *Ship) : void// Everyone loves corvettes so their attack
//		// flips ships in range to its state
//		// (if self is us, turns them to us,
//		// if self is them, turns us to them)

#include "stdafx.h"
#include "Corvette.h"

Corvette::Corvette(string shipname, int xlocation, int ylocation, Alignment shipalign)
	:Ship("",0,0,us,20,25,0)
{
}

Corvette::~Corvette(void)
{
}

void Corvette::attack( Ship *target)
{
	if ( (target->getY() < (getY()+range)) && (target->getY() > (getY()-range)) )  //make sure the ship in in range of Y
	{
		target->changeAlign();
	}
	else if ( (target->getX() < (getX()+range)) && (target->getX() > (getX()-range)))// make sure the ship in range of X
	{
		target->changeAlign();
	}
}

void Corvette::move()
{
	Ship::setXloc(Ship::getX()+5);
	Ship::setYLoc(Ship::getY()+5);
}
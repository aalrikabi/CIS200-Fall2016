//Cruiser (derived from Ship class) range is 50, maxHealth =50
//method
//// always moves along the vector (1, 2)
//move()
//attack(target: Ship *) : void//attacks 5

#pragma once
#include "Ship.h"
#include<iostream>
class Cruiser :
	public Ship
{
public:
	Cruiser(string shipname, int xlocation,int ylocation,Alignment shipalign)
		:Ship(shipname,xlocation,ylocation,shipalign,50,50,5)
	{
	};
	Cruiser(string shipname, int xlocation,int ylocation,Alignment shipalign,int repairmaxrange, int repairmaxhealth)
		:Ship(shipname,xlocation,ylocation,shipalign,repairmaxhealth,repairmaxrange,0)
	{
	};
	~Cruiser(void);

	// always moves along the vector (1, 2)
	void Cruiser::move()
	{
		if (Ship::getCurrentHealth() >0)  //make sure the ship is not dead
		{
			Ship::setXloc(Ship::getX()+1);
			Ship::setYLoc(Ship::getY()+2);

			Ship::setCurrentHealth(Ship::getCurrentHealth() +1);
		}
	};
	//attacks is 5
	void Cruiser::attack( Ship *target)
	{
		int rangeValue=50;
		int attackValue=5;

		//double hypotenuse= Ship::calculateHypotenuse(getX(), getY(), target->getX(), target->getY());
		hypotenuse= Ship::calculateHypotenuse(getX(), getY(), target->getX(), target->getY());
		if ( (target->getAlign() == getAlign())
			&& (target->getAlign() != chaotic)
			&& ( getAlign() != chaotic) )
		{
			int xx=0;
		}
		else if ( target->getCurrentHealth() > 0 && hypotenuse <= rangeValue)  // make sure the enemy is not dead
		{
			target->accessDamage(attackValue);
			cout<<"inrange Cruiser"<<endl;
		}
	};

	double Cruiser::gethypotenuse(){ return hypotenuse; };
private:

	double hypotenuse;
};

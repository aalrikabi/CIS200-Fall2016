#include "stdafx.h"
#include "Ship.h"
#include<string>
using namespace std;

Ship::~Ship(void)
{
}

Ship::Ship(string nameofship, int locationX, int locationY, Alignment align, int maxhealth,int shiprange, int attackPwr  ) 	// currHealth is set to maximum
	:name(" "), xLoc(0), yLoc(0), range(0), currHealth(0), attackPower(0), maxHealth(0)
{
}
void Ship::attack(Ship *target)
{
}
string Ship::getType()  //’’Battleship’’, ’’Cruiser’’, ’’Corvette’’, ’’Repairship’’
{
	return "ship";
}
int Ship::getX()// returns the x coordinate
{
	return xLoc;
}
void Ship::setXloc(int x)
{
	xLoc=x;
}
int Ship::getY()// returns the y coordinate
{
	return yLoc;
}
void Ship::setYLoc( int Y)
{
	yLoc=Y;
}

Alignment Ship::getAlign()  // returns the alignment
{
	return align;
}

void Ship::setAlign(Alignment setalignment)
{
	align=setalignment;
}

string Ship::status() // see format below
{
	return "status" ;
}

void Ship::move()// changes position by the amount of that type of ship,increases health by 1 (until max reached)
{
}

// changes the alignment.
//		flips ships in range to its state
//		 (if self is us, turns them to us,
//		 if self is them, turns us to them)
void Ship::changeAlign()
{
	if (getAlign()==us)
	{
		setAlign(them);
	}else if (getAlign()==them)
	{
		setAlign(us);
	}
}

void Ship::accessDamage(int amt) // changes the health by amt, (keeping it within bounds [0,maxHealth])
{
	if ((currHealth-amt)>0)
	{
		currHealth=currHealth-amt;
	}
	else
	{
		currHealth=0;
	}
}

int Ship::getCurrentHealth()
{
	return currHealth;
}
void Ship::setCurrentHealth(int currentHealth)
{
	if (currentHealth > 0)
	{
		currHealth=currentHealth;
	}
	else
	{
		currHealth=0;  //ship destroyed
	}
}
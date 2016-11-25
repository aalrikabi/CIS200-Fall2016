//Ali alrikabi;
//Description;
//This program used base class ship and derived classes: battle, cruiser, corvette, repair.
//Some of the functions in the base class is virtual functions to allow the derived classes to use there own functions. Repair class is derived from cruiser.
//Pre:
//Battle ship health is between zero and 100. Attack only within range of 10 radius. Attack will not attack dead ship. Attacking power is 20 with torpedo and damage of 10 when torpedoes are zero. Only attack non same alignment. Move along vector of -1,-1.
//Cruiser: health is between zero and 50. Attack only within range of 50 radius. Attack will not attack dead ship. Attacking power is 5. Only attack non same alignment. Move along vector of 1,2.
//Corvette: health is between zero and 20. Attack only within range of 25 radius. Attack will change alignment to it’s own alignment except for chaotic. Moves along the vector of 5,5.
//Repair: health is between zero and 20, attack only within range  of 25 radius. Attack will repair ship in it’s own alignment to max health. It will not repair dead ship. Moves along vector 1,2.
//
//Pos:
//If battle ship is health is more then 0  and it’s within range of opposite alignment ship, it will decrease the health of the opposite ship by 20 when it have torpedoes. And it will decrease the health of 10 without torpedoes.
//If cruiser health is more then zero and opposite alignment ship is within range, it will decrease the health of the opposite ship by 5.
//If corvette ship is within range of opposite ship and it’s health is more then zero, it will flip the alignment of the ship to it’s own alignment.
//Repair ship will repair ship if it’s health is more than zero and it’s within range and same alignment. The repair ship will increase the health to the max health of that type of ship.
//

#pragma once
#include<string>
using namespace std;
enum Alignment{us, them, chaotic};//us, them, chaotic
class Ship
{
public:

	Ship::~Ship(void)
	{
	}

	Ship::Ship(string nameofship, int locationX, int locationY, Alignment alignship, int maxhealth,int shiprange, int attackPwr  ) 	// currHealth is set to maximum
		:name(nameofship), xLoc(locationX), yLoc(locationY), align(alignship), range(shiprange), currHealth(maxhealth), attackPower(attackPwr), maxHealth(maxhealth)
	{
	};
	void virtual Ship::attack(Ship *target)
	{
	};
	string virtual Ship::getType()  //’’Battleship’’, ’’Cruiser’’, ’’Corvette’’, ’’Repairship’’
	{
		return "ship";
	};
	int Ship::getX()// returns the x coordinate
	{
		return xLoc;
	};
	void Ship::setXloc(int x)
	{
		xLoc=x;
	};
	int Ship::getY()// returns the y coordinate
	{
		return yLoc;
	};
	string Ship::getName()
	{
		return name;
	}
	void Ship::setYLoc( int Y)
	{
		yLoc=Y;
	};

	Alignment Ship::getAlign()  // returns the alignment
	{
		return align;
	};

	void Ship::setAlign(Alignment setalignment)
	{
		align=setalignment;
	};

	string virtual Ship::status() // see format below
	{
		string statusstring =" ";
		statusstring= "\n name: " + getName() +
			"\n type: Battle Ship" +
			"\n Health: " + to_string(getCurrentHealth())
			+ "\n Location: " + "(" + to_string(getX()) + "," + to_string(getY()) + ")\n";
		return statusstring;
	};

	void virtual Ship::move()// changes position by the amount of that type of ship,increases health by 1 (until max reached)
	{
	};

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
	};

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
	};

	int Ship::getCurrentHealth()
	{
		return currHealth;
	};
	int Ship::getmaxHealth(){return maxHealth;};
	void Ship::setCurrentHealth(int currentHealth)
	{
		if (currentHealth >= 0 && currentHealth <= maxHealth) //make sure its' not destroied and not more than maxhealth
		{
			currHealth=currentHealth;
		}
		else if( currentHealth < 0)
		{
			currHealth=0;  //ship destroyed
		}
		else if(currentHealth > maxHealth)
		{
			currHealth=maxHealth;
		}
	};

	double Ship::calculateHypotenuse(int ship1x, int ship1y, int ship2x, int ship2y)
	{
		return hypot( abs(ship1x - ship2x), abs(ship1y - ship2y));
	}

protected:
	string name; // name of ship
	Alignment align; //us, them, chaotic
	int xLoc; //location x
	int yLoc;// location y
	int range; // range value
	int currHealth; // current helth of the ship
	int attackPower; // attack value
	int maxHealth;// max health value
};

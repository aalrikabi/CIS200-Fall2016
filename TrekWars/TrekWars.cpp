// TrekWars.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"Ship.h"
#include"Cruiser.h"
#include"Battle.h"
#include"Repair.h"
#include"Corvette.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	Ship *health[10];
	int ships = 10;
	Ship **inABottle;
	inABottle = new Ship*[ships];
	inABottle[0] = new Battle("usBattle", 20, 20, us);
	Ship *watchme = inABottle[0];
	inABottle[1] = new Battle("themBattle", 50, 50, them);
	inABottle[2] = new Cruiser("usCruiser", 10, 10, us);
	inABottle[3] = new Cruiser("themCruiser", 25, 25, them);
	inABottle[4] = new Corvette("usCorvette", 0, 0, us);
	inABottle[5] = new Corvette("themCorvette", 40, 40, them);
	inABottle[6] = new Repair("usRepair", 15, 15, us);
	inABottle[7] = new Repair("themRepair", 30, 30, them);
	inABottle[8] = new Battle("chaoticBattle", 20, 20, chaotic);
	inABottle[9] = new Cruiser("chaoticCruiser", 0, 0, chaotic);
	health[0]=  inABottle[0];
	health[1]=  inABottle[1];
	health[2]=  inABottle[2];
	health[3]=  inABottle[3];
	health[4]=  inABottle[4];
	health[5]=  inABottle[5];
	health[6]=  inABottle[6];
	health[7]=  inABottle[7];
	health[8]=  inABottle[8];
	health[9]=  inABottle[9];
	for (int turn = 1; turn <= 1; turn++)
	{
		for (int attackerIndex = 0; attackerIndex < ships; attackerIndex++)
		{
			for (int targetIndex = 0; targetIndex < ships; targetIndex++)
			{
				inABottle[attackerIndex]->attack(inABottle[targetIndex]);
				cout<<"ship: "<<attackerIndex <<" attacks ship: "<<targetIndex <<endl;
				cout<<"health "<<inABottle[attackerIndex]->getCurrentHealth()
					<<"  " <<inABottle[targetIndex]->getCurrentHealth()<<endl;
			}
			inABottle[attackerIndex]->move();
		}
	}
	//Assert::AreEqual(0, inABottle[0]->getCurrentHealth());
	//Assert::AreEqual(16, inABottle[0]->getX());
	//Assert::AreEqual(16, inABottle[0]->getY());
	//Assert::AreEqual(int(us), int(inABottle[0]->getAlign()));

	/*	Assert::AreEqual(82, inABottle[1]->getCurrentHealth());
	Assert::AreEqual(40, inABottle[1]->getX());
	Assert::AreEqual(40, inABottle[1]->getY());
	Assert::AreEqual(int(them), int(inABottle[1]->getAlign()));*/

	system("pause");
}
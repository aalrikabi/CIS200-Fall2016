#include "stdafx.h"
#include "CppUnitTest.h"
#include "../../Battle.h"
#include "../../Ship.h"
#include "../../Cruiser.h"
#include "../../Corvette.h"
#include "../../Repair.h"
#include <string>
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Ship** fleet;
			int numShip; //cout<<"How many ships do you want ?";
			//cin>> numShip;
			numShip = 5;
			fleet= new Ship *[numShip];
			fleet[0] = new Ship("ship1",0,0,us,0,0,0);
		}

		TEST_METHOD(TestBattleship_alignment_us)
		{
			Ship** fleet;
			int numShip; //cout<<"How many ships do you want ?";
			//cin>> numShip;
			numShip = 5;
			fleet= new Ship *[numShip];
			fleet[0] = new Battle("ship1",20,0,us);
			Assert::AreEqual(0, fleet[0]->getX());
			int alignemtvalue= fleet[0]->getAlign();
			int expectednumue=us;
			Assert::AreEqual(expectednumue,alignemtvalue);
		}
		TEST_METHOD(TestBattleship_alignemt_them)
		{
			Ship** fleet;
			int numShip;
			numShip = 5;
			fleet= new Ship *[numShip];
			fleet[0] = new Battle("ship1",20,33,them);
			Assert::AreEqual(0, fleet[0]->getX());
			int alignemtvalue= fleet[0]->getAlign();
			int valuealign=them;
			Assert::AreEqual(valuealign,alignemtvalue);

			Assert::AreEqual(int (them),int( fleet[0]->getAlign()));
		}
		TEST_METHOD(TestBattleshipalignemtcheotic)
		{
			Ship** fleet;
			int numShip; //cout<<"How many ships do you want ?";
			//cin>> numShip;
			numShip = 5;
			fleet= new Ship *[numShip];
			fleet[0] = new Battle("ship1",33,0,chaotic);
			Assert::AreEqual(0, fleet[0]->getX());
			int valuess= fleet[0]->getAlign();
			int expectednum=chaotic;
			Assert::AreEqual(expectednum,valuess);
		}

		TEST_METHOD(TestCruiserlocationxy)
		{	// always moves along the vector (-1, -1)
			Ship** fleet;
			int numShip;
			numShip = 5;
			fleet= new Ship *[numShip];
			fleet[0] = new Cruiser("ship1",-32,-3,them);

			Assert::AreEqual(-32,fleet[0]->getX());

			Assert::AreEqual(-3,fleet[0]->getY());
		}
		TEST_METHOD(TestCruiser_move_location)
		{	// always moves along the vector (-1, -1)
			Ship** fleet;
			int numShip;
			numShip = 5;
			fleet= new Ship *[numShip];
			fleet[0] = new Cruiser("ship1",-5,-3,them);
			fleet[0]->move();

			Assert::AreEqual(-4,fleet[0]->getX());

			Assert::AreEqual(-1,fleet[0]->getY());
		}
		TEST_METHOD(TestCruiser_move_location_twomoves)
		{
			Ship** fleet;
			int numShip;
			numShip = 5;
			fleet= new Ship *[numShip];
			fleet[0] = new Cruiser("ship1",-5,-3,them);
			fleet[0]->move();
			fleet[0]->move();

			Assert::AreEqual(-3,fleet[0]->getX());

			Assert::AreEqual(1,fleet[0]->getY());
		}
		TEST_METHOD(TestCorvette_locationx_y)
		{
			Ship** fleet;
			int numShip;
			numShip = 5;
			fleet= new Ship *[numShip];
			fleet[0] = new Corvette("ship1",-5,-3,them);

			Assert::AreEqual(-5,fleet[0]->getX());

			Assert::AreEqual(-3,fleet[0]->getY());
		}

		TEST_METHOD(TestCorvette_move_location)
		{	// always moves along the vector (5, 5)
			int output=0;
			int expectednum= 0;
			Ship** fleet;
			int numShip;
			numShip = 5;
			fleet= new Ship *[numShip];
			fleet[0] = new Corvette("ship1",-55,-3,them);
			fleet[0]->move();
			output=fleet[0]->getX();
			expectednum= 50;
			Assert::AreEqual(expectednum,output);
			output=fleet[0]->getY();
			expectednum= 2;
			Assert::AreEqual(expectednum,output);
		}
		TEST_METHOD(TestCorvette_attack_inrange)
		{
			Alignment output;
			Alignment expectednum;
			Ship** fleet;
			int numShip;
			numShip = 5;
			fleet= new Ship *[numShip];
			fleet[0] = new Corvette("ship1",-7,-3,them);
			fleet[1] = new Corvette("man",7,12,us);
			fleet[0]->attack(fleet[1]);

			output=fleet[0]->getAlign();
			expectednum= them;
			Assert::AreEqual(int (them),int(output));

			output=fleet[1]->getAlign();
			expectednum= them;
			Assert::AreEqual(int(expectednum),int ( output));
		}

		TEST_METHOD(TestCorvette_attack_inrange_chaotic)
		{
			Alignment output;
			Alignment expectednum;
			Ship** fleet;
			int numShip;
			numShip = 5;
			fleet= new Ship *[numShip];
			fleet[0] = new Corvette("ship1",-5,-3,them);
			fleet[1] = new Corvette("ship3",7,12,chaotic);
			fleet[0]->attack(fleet[1]);

			output=fleet[0]->getAlign();
			expectednum= them;
			Assert::AreEqual(int (them),int(output));

			output=fleet[1]->getAlign();
			expectednum= chaotic;
			Assert::AreEqual(int(expectednum),int ( output));
		}

		TEST_METHOD(TestRepair_attack_inrange_deadship)
		{
			int output;
			int expectednum;
			Ship** fleet;
			int numShip;
			numShip = 5;
			fleet= new Ship *[numShip];
			fleet[0] = new Battle("ship1",5,6,them);
			fleet[1] = new Repair("ship2",11,12,them);
			fleet[0]->setCurrentHealth(0);
			fleet[1]->attack(fleet[0]);

			output=fleet[0]->getCurrentHealth();
			expectednum= 0;
			Assert::AreEqual(expectednum,output);

			output=fleet[1]->getCurrentHealth();
			expectednum= 20;
			Assert::AreEqual(expectednum,output);
		}
		TEST_METHOD(TestRepair_attack_inrange_chaotic)
		{
			int output;
			int expectednum;
			Ship** fleet;
			int numShip;
			numShip = 5;
			fleet= new Ship *[numShip];
			fleet[0] = new Battle("ship1",5,2,chaotic);
			fleet[1] = new Repair("ship2",14,12,them);
			fleet[0]->setCurrentHealth(22);
			fleet[1]->attack(fleet[0]);

			output=fleet[0]->getCurrentHealth();
			expectednum= 22;
			Assert::AreEqual(expectednum,output);

			output=fleet[1]->getCurrentHealth();
			expectednum= 20;
			Assert::AreEqual(expectednum,output);
		}
		TEST_METHOD(TestRepair_attack_inrange_chaotic2)
		{
			int output;
			int expectednum;
			Ship** fleet;
			int numShip;
			numShip = 5;
			fleet= new Ship *[numShip];
			fleet[0] = new Battle("ship1",15,12,chaotic);
			fleet[1] = new Repair("ship2",10,12,chaotic);
			fleet[0]->setCurrentHealth(22);
			fleet[1]->attack(fleet[0]);

			output=fleet[0]->getCurrentHealth();
			expectednum= 22;
			Assert::AreEqual(expectednum,output);

			output=fleet[1]->getCurrentHealth();
			expectednum= 20;
			Assert::AreEqual(expectednum,output);
		}

		TEST_METHOD(Battle_ShipTesting)
		{
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

			for (int turn = 1; turn <= 10; turn++)
			{
				for (int attackerIndex = 0; attackerIndex < ships; attackerIndex++)
				{
					for (int targetIndex = 0; targetIndex < ships; targetIndex++)
					{
						inABottle[attackerIndex]->attack(inABottle[targetIndex]);
					}
					inABottle[attackerIndex]->move();
				}
			}
			//Assert::AreEqual(0, inABottle[0]->getCurrentHealth());
			//Assert::AreEqual(16, inABottle[0]->getX());
			//Assert::AreEqual(16, inABottle[0]->getY());
			//Assert::AreEqual(int(us), int(inABottle[0]->getAlign()));

			Assert::AreEqual(82, inABottle[1]->getCurrentHealth());
			Assert::AreEqual(40, inABottle[1]->getX());
			Assert::AreEqual(40, inABottle[1]->getY());
			/*Assert::AreEqual(int(them), int(inABottle[1]->getAlign()));

			Assert::AreEqual(0, inABottle[2]->getCurrentHealth());
			Assert::AreEqual(13, inABottle[2]->getX());
			Assert::AreEqual(16, inABottle[2]->getY());
			Assert::AreEqual(int(us), int(inABottle[2]->getAlign()));

			Assert::AreEqual(8, inABottle[3]->getCurrentHealth());
			Assert::AreEqual(35, inABottle[3]->getX());
			Assert::AreEqual(45, inABottle[3]->getY());
			Assert::AreEqual(int(them), int(inABottle[3]->getAlign()));

			Assert::AreEqual(0, inABottle[4]->getCurrentHealth());
			Assert::AreEqual(15, inABottle[4]->getX());
			Assert::AreEqual(15, inABottle[4]->getY());
			Assert::AreEqual(int(us), int(inABottle[4]->getAlign()));

			Assert::AreEqual(20, inABottle[5]->getCurrentHealth());
			Assert::AreEqual(90, inABottle[5]->getX());
			Assert::AreEqual(90, inABottle[5]->getY());
			Assert::AreEqual(int(them), int(inABottle[5]->getAlign()));

			Assert::AreEqual(0, inABottle[6]->getCurrentHealth());
			Assert::AreEqual(16, inABottle[6]->getX());
			Assert::AreEqual(17, inABottle[6]->getY());
			Assert::AreEqual(int(us), int(inABottle[6]->getAlign()));

			Assert::AreEqual(0, inABottle[7]->getCurrentHealth());
			Assert::AreEqual(32, inABottle[7]->getX());
			Assert::AreEqual(34, inABottle[7]->getY());
			Assert::AreEqual(int(them), int(inABottle[7]->getAlign()));

			Assert::AreEqual(59, inABottle[8]->getCurrentHealth());
			Assert::AreEqual(10, inABottle[8]->getX());
			Assert::AreEqual(10, inABottle[8]->getY());
			Assert::AreEqual(int(chaotic), int(inABottle[8]->getAlign()));

			Assert::AreEqual(4, inABottle[9]->getCurrentHealth());
			Assert::AreEqual(10, inABottle[9]->getX());
			Assert::AreEqual(20, inABottle[9]->getY());
			Assert::AreEqual(int(chaotic), int(inABottle[9]->getAlign()));*/
		}
	};
}
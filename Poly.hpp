//Ali Alrikabi
//CIS 200
//Project 2
//Polynomials:
//
//this program allow the user to add, multiply, differentiate, and integrate polynomials.
//there are many function that will help the user to construct, destructor the class.
//also user can print the private poly list.
//to add two polynomials, use the + between the object of class
//to multiply two polynomials, use the * between the object of class;
//
//pre:
//	-only one polynomial per class constructor
//	-if there is only constant, add zero to exponent
//pos:
//	- differentiation exponent of 0 will delete the constant.
//	- integration will add variable to constant.
//	-overload operator<< will print the polynomial linked list.

// Unit Test
// testing Adding Polynomials:  poly7=poly2+poly6 expected 2x^3 +5  and the output: 2.00x^3 + 5.00
//
//testing integration polynomials: poly6=poly7.integr() expected 2/4x^4 and the output: 0.50x^4 + 5.00x^1
//
//testing differentiation on polynomials: poly6 = poly7.differ() expected 12x^3+18x^2 and the output: 12.00x^3 + 18.00x^2
//
// testing adding polynomials: Poly1=Poly2+Poly3 expected 2x^3+3x^4 and the output: 3.00x^4 + 2.00x^3
//
//testing multiplying polynomials: Poly1=Poly2*poly3 expected 6x^7 and the output: 6.00x^7
//

#ifndef PolyType_H
#define PolyType_H
#include <iostream>
using namespace std;
struct TermNode
{
	int exp; // exponent
	double coef; // coefficient
	TermNode * next;
};
class PolyType
{
public:
	PolyType(); // default constructor
	PolyType(int r, int c);          // constructor makes a 1 node polynomial
	PolyType(const PolyType & other); // copy constructor
	~PolyType(); // destructor
	PolyType& operator=(const PolyType & other); // equals operator
	PolyType operator+ (const PolyType & other) const; // returns sum of the parameter + self
	PolyType   operator* (const PolyType & other ) const;
	PolyType   differ();// differentiation
	PolyType   integr();// integration (with 0 as the constant)
	friend ostream &   operator<< (ostream & out, const PolyType & rhs);  // coefficients printed to 2 decimal places
private:
	TermNode *polyPtr;
	void PolyType::nodelistloop(TermNode *newNode);
};
#endif

#include<iostream>
#include<iomanip>
using namespace std;

// Function: Default constructor for class PolyType
PolyType::PolyType()
{
	polyPtr = NULL;  // set private data to null
}

// Function: constructor makes a 1 node polynomial, and sets it to represent coefficients and exponents; r for coefficient and c for exponents
PolyType::PolyType(int r, int c)
{
	polyPtr = new TermNode;  // new node created
	polyPtr->coef = r;
	polyPtr->exp = c;
	polyPtr->next = NULL;// set it to Null
}

// Function: destructor
PolyType::~PolyType()
{
	TermNode* polyPtrTemp;
	while (polyPtr != NULL) // loop on polyPtr list
	{
		polyPtrTemp = polyPtr->next; // keep temp of the next polyptr
		delete polyPtr; // delete polyPtr
		polyPtr = polyPtrTemp; // then assign the temp to polyPtr
	}
}

// Function: Deep copy constructor
PolyType::PolyType(const PolyType & other)
{
	TermNode* otherPolyTemp = other.polyPtr;
	TermNode* newNode;
	polyPtr = NULL;  // make sure polyPtr is null before we start the loop
	while (otherPolyTemp != NULL) // Loop through the link list
	{
		newNode = new TermNode; //creat new Node
		newNode->next = NULL;
		newNode->coef = otherPolyTemp->coef; // assign coefficient to newNode
		newNode->exp = otherPolyTemp->exp;    // assign exponent to newNode
		nodelistloop(newNode); // send to the function
		otherPolyTemp = otherPolyTemp->next;  // loop
	}
}

//Function: used to assign value to polyPtr and loop through it to place the newNode to the end of the list
void PolyType::nodelistloop(TermNode *newNode)
{
	if (polyPtr == NULL)  // If polyPtr equals null then assign polyPtr newNode value
		polyPtr = newNode;
	else  //creat the Next in polyPtr
	{
		TermNode* TempPolyPtr = polyPtr;
		while (TempPolyPtr->next != NULL)  //loop until the end of the list to add the newNode to polyptr
			TempPolyPtr = TempPolyPtr->next;
		TempPolyPtr->next = newNode;  // add the newNode to polyptr
	}
}
// Funciton: operator =
PolyType& PolyType:: operator = (const PolyType & other)
{
	TermNode* otherPolyTemp = other.polyPtr;
	TermNode* newNode; // New TermNode
	polyPtr = NULL; // assign  null

	while (otherPolyTemp != NULL)
	{
		newNode = new TermNode;
		newNode->next = NULL;
		newNode->coef = otherPolyTemp->coef;
		newNode->exp = otherPolyTemp->exp;
		nodelistloop(newNode);
		otherPolyTemp = otherPolyTemp->next;
	}
	return *this;
}

// Function: operator +
PolyType PolyType:: operator + (const PolyType & other) const
{
	PolyType newPoly;
	TermNode* myPolyPtr = polyPtr;
	TermNode* otherPolyTemp = other.polyPtr;
	TermNode* newNode;

	while (myPolyPtr != NULL && otherPolyTemp != NULL) // if both are not Null
	{
		newNode = new TermNode;
		newNode->next = NULL;

		//sord the poly, high exp is first  if equal exponent, add coeff
		if (myPolyPtr->exp > otherPolyTemp->exp)
		{
			newNode->coef = myPolyPtr->coef;
			newNode->exp = myPolyPtr->exp;
			myPolyPtr = myPolyPtr->next;
		}
		else if (myPolyPtr->exp < otherPolyTemp->exp)
		{
			newNode->coef = otherPolyTemp->coef;
			newNode->exp = otherPolyTemp->exp;
			otherPolyTemp = otherPolyTemp->next;
		}
		else if (myPolyPtr->exp == otherPolyTemp->exp)
		{
			newNode->coef = myPolyPtr->coef + otherPolyTemp->coef;
			newNode->exp = myPolyPtr->exp;
			myPolyPtr = myPolyPtr->next;
			otherPolyTemp = otherPolyTemp->next;
		}

		//assign newNode to Polyptr
		if (newPoly.polyPtr == NULL) //loop to the end of polyptr
			newPoly.polyPtr = newNode;
		else
		{
			TermNode* TempPolyPtr = newPoly.polyPtr;
			while (TempPolyPtr->next != NULL)
			{
				TempPolyPtr = TempPolyPtr->next;
			}
			TempPolyPtr->next = newNode;
		}
	}

	while (otherPolyTemp != NULL)  // add the any other poly nodes to the end of the polyptr
	{
		newNode = new TermNode;
		newNode->next = NULL;
		newNode->coef = otherPolyTemp->coef;
		newNode->exp = otherPolyTemp->exp;
		TermNode* TempPolyPtr = newPoly.polyPtr;
		while (TempPolyPtr->next != NULL)
		{	TempPolyPtr = TempPolyPtr->next;}
		TempPolyPtr->next = newNode;
		otherPolyTemp = otherPolyTemp->next;
	}
	while (myPolyPtr != NULL)  //add any other poly from mypolyptr list to the end of polyptr
	{
		newNode = new TermNode;
		newNode->next = NULL;
		newNode->coef = myPolyPtr->coef;
		newNode->exp = myPolyPtr->exp;
		TermNode* TempPolyPtr = newPoly.polyPtr;
		while (TempPolyPtr->next != NULL)
		{	TempPolyPtr = TempPolyPtr->next;}
		TempPolyPtr->next = newNode;
		myPolyPtr = myPolyPtr->next;
	}
	return newPoly;
}

// Function: multiply
PolyType PolyType:: operator * (const PolyType & other) const
{
	PolyType newPoly;
	TermNode* myPolyPtr = polyPtr;
	TermNode* otherPolyTemp = other.polyPtr;
	TermNode* newNode;

	TermNode* tempmyPolyPtr =myPolyPtr;
	TermNode* tempotherPolyTemp=otherPolyTemp;
	while(tempmyPolyPtr != NULL) //loop on tempmypolyptr
	{
		while (tempotherPolyTemp !=NULL)//loop on other
		{
			newNode=new TermNode;
			newNode->next=NULL;
			newNode->coef=tempmyPolyPtr->coef * tempotherPolyTemp->coef;
			newNode->exp=tempmyPolyPtr->exp + tempotherPolyTemp->exp;

			if (newPoly.polyPtr == NULL)   // add to the end of polyptr
				newPoly.polyPtr = newNode; //other
			else
			{
				TermNode* TempPolyPtr = newPoly.polyPtr;
				while (TempPolyPtr->next != NULL)
					TempPolyPtr = TempPolyPtr->next;
				TempPolyPtr->next = newNode;
			}
			tempotherPolyTemp= tempotherPolyTemp->next;
		}
		tempmyPolyPtr= tempmyPolyPtr->next;
		tempotherPolyTemp=otherPolyTemp; //reset tempotherpolytemp so we can use it again in the loop
	}

	return newPoly;
}

std::ostream &   operator<< (std::ostream &out, const PolyType &rhs)
{
	//out << rhs.polyPtr->coef;

	cout<<setprecision(2)<<fixed;
	TermNode* tempNode = rhs.polyPtr;
	while (tempNode != NULL) // polyPtr head of list, need temp to keep track
	{
		if (tempNode->exp >0)  // only print x^ when there is exponent
			out << tempNode->coef << "x^" << tempNode->exp;
		else
			out << tempNode->coef;

		if (tempNode->next != NULL) // If next node not null then prints out plus sign
			out << " + ";
		tempNode = tempNode->next;
	}
	out<<endl;

	return out;
}

// Function: differential
PolyType   PolyType::differ()
{
	PolyType newPoly;
	TermNode* myPolyPtr = polyPtr;
	TermNode* newNode;

	TermNode* tempmyPolyPtr =myPolyPtr;
	while(tempmyPolyPtr != NULL)
	{
		newNode=new TermNode;
		newNode->next=NULL;
		newNode->coef=tempmyPolyPtr->coef * tempmyPolyPtr->exp;
		newNode->exp=tempmyPolyPtr->exp -1;
		if (tempmyPolyPtr->exp !=0)
		{
			if (newPoly.polyPtr == NULL)
				newPoly.polyPtr = newNode; //other
			else
			{
				TermNode* TempPolyPtr = newPoly.polyPtr;
				while (TempPolyPtr->next != NULL)
				{
					TempPolyPtr = TempPolyPtr->next;
				}
				TempPolyPtr->next = newNode;
			}
		}
		tempmyPolyPtr= tempmyPolyPtr->next;
	}
	return newPoly;
}

// Function: integral
PolyType   PolyType::integr()
{
	PolyType newPoly;
	TermNode* myPolyPtr = polyPtr;
	TermNode* newNode;
	TermNode* tempmyPolyPtr =myPolyPtr;
	while(tempmyPolyPtr != NULL)
	{
		newNode=new TermNode;
		newNode->next=NULL;
		newNode->coef=tempmyPolyPtr->coef /(tempmyPolyPtr->exp + 1);
		newNode->exp=tempmyPolyPtr->exp +1;

		if (newNode->exp !=0)
		{
			if (newPoly.polyPtr == NULL)
				newPoly.polyPtr = newNode; //other
			else
			{
				TermNode* TempPolyPtr = newPoly.polyPtr;
				while (TempPolyPtr->next != NULL)
				{
					TempPolyPtr = TempPolyPtr->next;
				}
				TempPolyPtr->next = newNode;
			}
		}
		tempmyPolyPtr= tempmyPolyPtr->next;
	}

	return newPoly;
}
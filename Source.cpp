#include<iostream>
#include "Poly.hpp"
using namespace std;

int main()
{
	PolyType poly1;  //creates a null polynomial
	PolyType poly2(2, 3);  //creates 2x^3 polynomial
	PolyType poly3(3, 4);  //creates 3x^4 polynomial
	PolyType poly4(7,5);
	PolyType poly5(4,3);
	PolyType poly6(5,0);
	PolyType poly7(7,0);

	cout<<"	poly7=poly2+poly6 expected 2x^3 +5  and the output: ";
	poly7=poly2+poly6;
	cout<<poly7;
	cout<<endl;

	cout<<"	poly6=poly7.integr() expected 2/4x^4 and the output: ";
	poly6=poly7.integr();
	cout<<poly6;
	cout<<endl;

	poly7=poly2+poly3+poly5;
	cout<<"	poly6 = poly7.differ() expected 12x^3+18x^2 and the output: ";// make sure we add same exponent
	poly6 = poly7.differ();
	cout<<poly6;
	cout<<endl;

	poly1=poly2+poly3;
	cout<<" Poly1=Poly2+Poly3 expected 2x^3+3x^4 and the output: ";
	cout<<poly1;

	poly1=poly2*poly3;
	cout<<"Poly1=Poly2*poly3 expected 6x^7 and the output: ";
	cout<<poly1;

	cout<<"poly2"<<endl;
	cout<<poly2;
	cout<<endl;

	cout<<"	poly7=poly2.differ();"<<endl;
	poly7=poly2.differ();
	cout<<poly7;
	cout<<endl;

	cout <<poly2;

	poly1 = poly2 + poly3;   //makes poly1 = 3x^4 + 2x^3
	cout<<"poly1= poly2 + poly3"<<endl;
	cout<<"poly1 ";
	cout<<poly1;
	cout<<endl;
	cout<<"poly3 ";
	cout<<poly3;
	cout<<endl;
	cout<<poly4;
	cout<<endl;

	cout<<"poly1=poly1*poly3 "<<endl;
	poly1=poly1*poly3;
	cout<<poly1;
	cout<<endl;

	cout<<"poly1 *poly 6 = ";
	cout<<poly1;
	cout<<"  ";
	cout<<poly6;
	cout<<" = ";
	poly7=poly1*poly6;
	cout<<" poly7=poly1*poly6 "<<endl;
	cout<<poly7;
	cout<<endl;

	cout<<"poly1=poly1*poly3 *poly4"<<endl;
	poly1=poly1*poly3 *poly4;

	cout<<poly1;   //prints out 3x^4 + 2x^3
	cout<<endl;
	cout<<" poly1=poly2+poly3+poly4+poly5"<<endl;
	poly1=poly2+poly3+poly4+poly5;
	cout<<poly1;     //prints out 3x^4 + 2x^3
	cout<<endl;

	system("pause");
	return 0;
}
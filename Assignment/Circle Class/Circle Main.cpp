#include <iostream>
#include "Circle.h"
using namespace std;

//*****************************************************
// Function main                                      *
//*****************************************************

int main()
{
	Circle round;
	double circRadius;
	
	cout << "This program will calculate the area of cirlce\n";
	cout << "Enter radius: "; 
	cin >> circRadius; 
	round.setRadius(circRadius);
	
	cout << "\nHere is the Answer for the Question above\n";
	cout << "Radius: " << round.getRadius() << endl; 
	cout << "Area: " << round.getArea() << endl; 
	
	return 0; 
}

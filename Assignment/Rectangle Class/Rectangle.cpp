#include "Rectangle.h"
#include <iostream>
using namespace std;

//**************************************************
// DEFINE MEMBER FUNCTION 		            	   *
//**************************************************

void Rectangle::setWidth(double w)
{
    width = w;
}

void Rectangle::setLength(double len)
{
    length = len;
}

/*Rectangle::Rectangle()
{
    cout << "Constructor" << endl;
	width = 1; length = 1;
	cout << width << " " << length; 
}*/
 
//Parameterized Constructor
Rectangle::Rectangle(double w,double len)
{
    cout << endl << "Parameterized Consturcter called";
    width = w;
    length = len;
}

//Copy Constructor
Rectangle::Rectangle(Rectangle &obj)
{
	cout << endl << "Copy Constructor called" << endl;
	width = obj.width;
	length = obj.length;
}



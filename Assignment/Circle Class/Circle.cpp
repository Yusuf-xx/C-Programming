#include <iostream>
#define PI  3.14159 
using namespace std; 

class Circle 
{
	private: double radius;
	public:  double r;
	         Circle();
			 Circle(double);
	         void set_radius(double); 
			 double get_radius() const;
			 double get_Area() const;  
};

    void Circle::set_radius(double r)
	{
		radius = r; 
	}
	
	double Circle::get_radius() const 
	{
		return radius;
	}
	
	double Circle::get_Area() const
	{
		return PI * radius * radius; 
	}
	
	Circle::Circle()    
	{
		radius = 0.0;  
	}
	
	Circle::Circle(double r)
	{
		radius = r;   
	}

int main()
{
	Circle c;
	double c_radius;
	 
	cout << "Enter radius: "; 
	cin >> c_radius; 
	c.set_radius(c_radius); 
	
	cout << "Radius: " << c.get_radius() << endl; 
	cout << "Area: " << c.get_Area() << endl; 
	
	return 0; 
}

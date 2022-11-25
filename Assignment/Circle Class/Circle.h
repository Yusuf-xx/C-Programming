#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
	private: double radius;
	public:  double r;
	         Circle();
			 Circle(double);
	         void setRadius(double); 
			 double getRadius() const;
			 double getArea() const;  
};

#endif

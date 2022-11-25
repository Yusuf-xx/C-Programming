//Specification file or Header File
#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
	private:
		double width;
		double length;
	public:
		void setWidth(double);
		void setLength(double);
		double getWidth() const
		    {
		    	return width;           //Incline Member Function
			}
		double getLength() const
		    {
		    	return length;          //Incline Member Function
			}
		double getArea() const
		    {
		    	return width * length;  //Incline Member Function
			}
			
		Rectangle();
};

#endif

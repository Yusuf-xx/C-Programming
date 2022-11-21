#include <iostream>
#include <cctype>
using namespace std;

int main()
{
	int code, linoleum;
	float width_L, width_R, length_L, length_R;
	float area_L, area_R, cost, price;
	
	cout << "Please enter linoleum code: ";
	cin >> code;
	
	cout << "Linoleum size: " << width_L << " Feet * " << length_L << " Feet" <<endl;
	cout << "Linoleum price: RM" << price <<endl<<endl;
	
	cout << "Enter the width and length of the room: ";
	cin >> width_R >> length_R;
	
	area_R = width_R * length_R;
	
	cout << "Size of room: " << area_R << " sqft" <<endl;
	
	area_L = width_L * length_L;
	linoleum = area_R / area_L;
	
	cout << "Number of linoleum: " << linoleum <<" pieces"<<endl;
	
	cost = linoleum * 1.50;
	cout << "Cost: RM" << cost;
	
	return 0;
}

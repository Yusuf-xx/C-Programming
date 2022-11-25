/*-----------------------------------------------------------------------------------
-  |  |  |  |  |  Md Yusuf Bin Forkan // 201909M10266 // A19MJ0178   |  |  |  |  |  -
-  |  |  |  |  |  Ruhul Quddus Tamim  // 201807M10023 // A19MJ0182   |  |  |  |  |  -
-  |  |  |  |  |  Shafi Ahmed         // 201909M10257 // A19MJ0184   |  |  |  |  |  -
------------------------------------------------------------------------------------*/
#include<iostream>
#include<string>
#include<fstream>

using namespace std;


class Location{
	string street;
	string town;

	
	public:
		Location (string s=" ", string t="")
		{
			street=s;
			town=t;
		}
		string getStreet()
		{
			return street;
		}
		string getTown()
		{
			return town;
		}
		string getFullLocation()
		{
			return street + ", " + town;
		}
};

  class House{
  	private:
  		int noRoom;
  		Location *l;
  	protected:
  		double rentRate;
  		
  	public:
  		House();
  	 House(Location* lt, int a, double b)
	    { 
		l=lt; 
		noRoom = a; 
		rentRate = b; 
		}
  		string getLocation(){
  			if (l)
  			return l->getFullLocation();
  			else 
  		    return " ";
		  }
		int getRoom()
		{
			return noRoom;
		}
		double getRate()
		{
			return rentRate;
		}
		virtual double getDeposit() = 0;
	
		virtual void display()
		 {
  	cout<<l->getFullLocation() << " with " << noRoom << " bedrooms";
  }
  };

 
  class Bungalow: public House{
  	int land;
  	public:
  		Bungalow();
  	    Bungalow(Location *ln, int a, double b, int c) : House (ln,a,b)
            { 
			land = c; 
			}
		  int getLand()
		  {
		  	return land;
		  }
		  double getDeposit()
		  {
		  	return rentRate*6;
		  }
		  void display()
		  {
		   cout << "We have a bungalow located at ";
        House::display();
        cout <<endl<< "Land size: " << land << " sqft." << endl;
        cout << "Monthly rental rate: RM" << getRate() << endl;
        cout << "Deposit : RM" << getDeposit() << endl << endl;
		  }
  };
  
  
  class Apartment:public House{
  	int level;
  	public:
  		 Apartment();
  	     Apartment(Location *ln, int a, double b, int c) : House(ln, a, b)
             {
			  level = c;
			 }
  		  int getFlevel()
  	    	{
  			return level;
		  }
		  double getDeposit()
		  {
		  	return rentRate*3;
		  }
		  void display()
		  {
		  	cout << "We have an apartment located at ";
        House::display();
        cout << endl<<"at level " << level << "." << endl;
        cout << "Monthly rental rate: RM" << getRate() << endl;
        cout << "Deposit : RM" << getDeposit() << endl << endl;
    
		  }
  };
  
  int main()
  {
  	
  	Location* bungalow = new Location("Taman University", "Johor Bahru");
    Bungalow a(bungalow, 6, 2000.00, 300);
  	
  	Location *apartment1= new Location("Pulai Spring Resort", "Pulai");
  	Apartment b(apartment1, 3, 800.00, 5);
  	
  	Location *apartment2= new Location("Scholars Inn", "Universiti Teknologi Malaysia");
  	Apartment c(apartment2, 2, 700.00, 12);
  	
  	cout << "*** HOUSE FOR RENT ***"<<endl<<endl;

  	a.display();
  	b.display();
  	c.display();
  	
  	return 0;
  	
  }

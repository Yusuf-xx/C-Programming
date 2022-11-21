/*-----------------------------------------------------------------------------------
-  |  |  |  |  |  Md Yusuf Bin Forkan // 201909M10266 // A19MJ0178   |  |  |  |  |  -
-  |  |  |  |  |  Ruhul Quddus Tamim  // 201807M10023 // A19MJ0182   |  |  |  |  |  -
-  |  |  |  |  |  Shafi Ahmed         // 201909M10257 // A19MJ0184   |  |  |  |  |  -
------------------------------------------------------------------------------------*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

float getBMI ( float , float , float & );

float dispStatus ( float );

int main()
{
	int num; int count = 1;
	char name [50];
	float weight, height, BMI, sumWeight = 0, sumHeight = 0, overallWEIGHT, overallHEIGHT, overallBMI;
	
	cout << "Enter number of persons to calculate => ";
	cin >> num;
	cout <<endl;
	
	while ( count <= num )
	{
		cout << "Enter name => ";
        cin >> name;
	    cout << "Enter weight (kg) and height (m) => ";
        cin >> weight >> height ;
        
        cout << "\n";
	    cout << "Name   : " << name <<endl;
	    cout << "Weight : " << weight << " kilograms\n" << fixed << setprecision(2);
	    cout << "Height : " << height << " meters\n" << fixed << setprecision(2);
	    getBMI ( weight, height, BMI );
	    dispStatus ( BMI );
	    
	    sumWeight = sumWeight + weight; 
	    sumHeight = sumHeight + height;
        count++;
	}


	
	cout << endl << endl;
    overallWEIGHT = sumWeight / num;
	overallHEIGHT = sumHeight / num;
	overallBMI = overallWEIGHT / pow ( overallHEIGHT, 2 );
	cout << "Overall BMI   : " << overallBMI << fixed << setprecision(2) << endl;
	cout << "Overall";
	dispStatus ( overallBMI );
	
	return 0;
}

float getBMI( float weight, float height, float &BMI )
{
	BMI = weight / pow ( height, 2 );
	cout << "BMI    : "<< BMI << fixed << setprecision(2) << endl;
}

float dispStatus( float BMI )
{
	if ( BMI >= 18.5 && BMI <= 25 )
	{
		cout << "Status : Normal\n"<<endl;
	}
	else if( BMI < 18.5 )
	{
		cout << "Status : Underweight\n"<<endl;
	}
	else if( BMI > 25 && BMI <= 30)
	{
		cout << "Status : Overweight\n"<<endl;
	}
	else 
	{
		cout << "Status : Obese\n"<<endl;
	}
}

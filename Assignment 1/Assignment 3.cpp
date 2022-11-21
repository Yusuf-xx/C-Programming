/*-----------------------------------------------------------------------------------
-  |  |  |  |  |  Md Yusuf Bin Forkan // 201909M10266 // A19MJ0178   |  |  |  |  |  -
-  |  |  |  |  |  Ruhul Quddus Tamim  // 201807M10023 // A19MJ0182   |  |  |  |  |  -
-  |  |  |  |  |  Shafi Ahmed         // 201909M10257 // A19MJ0184   |  |  |  |  |  -
------------------------------------------------------------------------------------*/
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

void getProblem();

void getRateDropFactor();

void getKgRateConc();

float figDropsMin ( float, float );

float byWeight ( float, float, float );

int main()
{
	getProblem();

    cout << "\n";
    system ("pause");
    return 0;
}

void getProblem()
{
    float rate, drops, drop_min;
    float weight, concentration, ml_min;
    int choice;
    
	do
	{
		cout << "\t INTRAVENOUS RATE ASSISTANT" <<endl <<endl;
	    cout << "\t Enter the number of the problem you wish to solve." <<endl;
	    cout << "\t GIVEN A MEDICAL ORDER IN \t \t \t CALCULATE RATE IN" <<endl;
	    cout << "\t (1) ml/hr & tubing drop factor \t \t drops/min" <<endl;
        cout << "\t (2) mg/kg/hr & concentration in mg/ml \t \t ml/hr" <<endl;
        cout << "\t (3) QUIT" <<endl <<endl;
	
        cout << "\t Problem => ";
        cin >> choice;

        switch(choice)
        {
        	case 1: getRateDropFactor();
  	            break; 
		    case 2: getKgRateConc();
		        break;
	       	case 3: cout << "\t You have chosen to quit the program.\n\t Thanks for using our system.";
		        exit(0); 
		    default: cout << "\t Please run the system again and choose a problem number between 1 and 3."; 	
	    
		}
    } while ( choice >= 1 && choice <= 3 );
}
	

void getRateDropFactor()
{
	float choice, rate, drops;
	float drop_min;
	
    cout << "\t Enter rate in ml/hr => ";
    cin >> rate;
    cout << "\t Enter tubing's drop factor(drops/ml) => ";
    cin >> drops;
    figDropsMin(rate, drops);
}

void getKgRateConc()
{
	float rate, weight, concentration;
	
    cout << "\t Enter rate in mg/hr => ";
    cin >> rate;
    cout << "\t Enter patient weight in kg => ";
    cin >> weight;
    cout << "\t Enter concentration in mg/ml => ";
    cin >> concentration;
    byWeight( rate, weight, concentration);
}

float figDropsMin( float rate, float drops )
{
    float drop_min;

    drop_min = ceil (rate * (drops / 60));
    cout << "\t The drop rate per minute is " << drop_min << "." <<endl<<endl;
}

float byWeight( float rate, float weight, float concentration)
{
    float ml_min;

    ml_min = ceil ((rate / concentration) * weight);
    cout << "\t The rate in millilitres per hour is " << ml_min << "." <<endl <<endl;
}

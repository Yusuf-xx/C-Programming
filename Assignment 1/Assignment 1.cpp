/*-----------------------------------------------------------------------------------
-  |  |  |  |  |  Md Yusuf Bin Forkan // 201909M10266 // A19MJ0178   |  |  |  |  |  -
-  |  |  |  |  |  Ruhul Quddus Tamim  // 201807M10023 // A19MJ0182   |  |  |  |  |  -
-  |  |  |  |  |  Shafi Ahmed         // 201909M10257 // A19MJ0184   |  |  |  |  |  -
------------------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

 int price = 120;

 int getCoin();

 void calculateCoin ( int &, int  );

 int calculateBalance ( int ); 
 
 int main()
 {
     int total = 0;
 	 int coins;
  
  do {
  	
    coins =	getCoin();
    calculateCoin (  total ,  coins ); 

   } while ( total < price );
   
    cout << "Total amount entered: " << total <<endl;
    cout << endl;
    calculateBalance ( total ); 
    return 0;
 }
 
 int getCoin()
 {
 	 int value;
 	 cout << "Enter value of coin: ";
 	 cin  >> value;
 	 return value;
 }
 
 void calculateCoin ( int &totalCoin, int coin )
 {
 	totalCoin = totalCoin + coin; 
 }
 
 
 int calculateBalance ( int total )
 {
 	int balance = total - price; 
 	
 	if ( balance > 0 )	
 	  cout << "Please collect your balance : " << balance <<endl; 
 	else cout << "TERIMA KASIH" <<endl;
 }

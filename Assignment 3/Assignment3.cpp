/*-----------------------------------------------------------------------------------
-  |  |  |  |  |  Md Yusuf Bin Forkan // 201909M10266 // A19MJ0178   |  |  |  |  |  -
-  |  |  |  |  |  Ruhul Quddus Tamim  // 201807M10023 // A19MJ0182   |  |  |  |  |  -
-  |  |  |  |  |  Shafi Ahmed         // 201909M10257 // A19MJ0184   |  |  |  |  |  -
------------------------------------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <iomanip>
#define NUM_STATE 14
#define NUM_YEAR 10

using namespace std;

 ofstream out; 
 
 struct dataAcc 
 { 
    int numAcc[10];
    string state;
    float avg; 
 }; 
 
 void displayLine() 
 { 
   for ( int i = 0; i < 111; i++ )  
      out << "-"; 
	  out << endl;
 } 
 
  float cal_Avg( int row[] )
 {
 	float total = 0; 
	for ( int x = 0; x < NUM_YEAR; x++ )
		total += row[x];
	return (total / NUM_YEAR);
 }
 
 void find_HighLow( dataAcc S[] )
 {
 	int y; int i;
 	bool status;
 	
 	int highest = 0;
 	
 	for ( i = 0; i < NUM_STATE; i++ )
 	{
 	  for ( y = 0; y < NUM_YEAR; y++ )
 	  {
 	  	if ( highest < S[i].numAcc[y] ) 
 	  	highest = S[i].numAcc[y]; 
	  }
    }
    
    for ( i = 0; i < NUM_STATE; i++ )
 	{
 	  for ( y = 0; y < NUM_YEAR; y++ )
 	    if ( highest == S[i].numAcc[y] )
 	       status = true; 
      if (status)
       break; 
    }
      out << highest;
      
      switch (i)
      {
      	case 0: out << " at PERLIS"; 
      	        break;
      	case 1: out << " at KEDAH";
      	      	break;
      	case 2: out << " at PULAU PINANG";
      	        break;
      	case 3: out << " at PERAK"; 
      	      	break;
      	case 4: out << " at SELANGOR";
      	      	break;
      	case 5: out << " at KUALA LUMPUR";
      	      	break;
      	case 6: out << " at NEGERI SEMBILAN";
      	      	break;
      	case 7: out << " at MELAKA";
      	      	break;
      	case 8: out << " at JOHOR";
      	      	break;
      	case 9: out << " at PAHANG";
      	      	break;
      	case 10: out << " at KELANTAN";
      	      	break;
      	case 11: out << " at TERENGGANU";
      	      	break;
      	case 12: out << " at SABAH";
      	      	break;
      	case 13: out << " at SARAWAK";
      	      	break;
	  }
	  
	   switch (y)
      {
      	case 1: out << " on 2006"; 
      	        break;
      	case 2: out << " on 2007";
      	      	break;
      	case 3: out << " on 2008";
      	        break;
      	case 4: out << " on 2009"; 
      	      	break;
      	case 5: out << " on 2010";
      	      	break;
      	case 6: out << " on 2011";
      	      	break;
      	case 7: out << " on 2012";
      	      	break;
      	case 8: out << " on 2013";
      	      	break;
      	case 9: out << " on 2014";
      	      	break;
      	case 10: out << " on 2015";
      	      	break;
	  }
   }

 int main()
 {
   float total = 0;
   
   ifstream inp; 
   inp.open("input1.txt"); 
   out.open("output.txt");
   
   if ( !inp ) cout << "File doesn't exist";
   
   displayLine();
   out << endl;
   out<<setw(10)<<"State"<<setw(17) << "2006" << setw(8)  << "2007" 
	                    << setw(8)  << "2008" << setw(8)  << "2009" 
	                    << setw(8)  << "2010" << setw(8)  << "2011" 
	                    << setw(8)  << "2012" << setw(8)  << "2013" 
	                    << setw(8)  << "2014" << setw(8)  << "2015" 
    << setw(11) << "AVERAGE";
   out << endl << endl; 
   displayLine();
   out << endl; 
   
   dataAcc state[NUM_STATE];
   
   for ( int i = 0; i < NUM_STATE; i++ )
   {
   	 for ( int y = 0; y < NUM_YEAR; y++ )
   	    inp >> state[i].numAcc[y];	
	    getline ( inp, state[i].state );
   }
   
   for ( int i = 0; i < NUM_STATE; i++ )
    {
   	    out << left << setw(16) << state[i].state;
   	 for ( int y = 0; y < NUM_YEAR; y++ )
   	    out << "\t" << right << setw(7) << state[i].numAcc[y];
   	    
	state[i].avg = cal_Avg(state[i].numAcc);
	out << setw(11) << fixed << setprecision(1) << state[i].avg;
	   
	    out << endl << endl;
    }
        displayLine();
        out << endl; 
        out << "The highest number of road accidents = ";
        find_HighLow( state );
        out << endl << endl; 
        displayLine(); 
      
   inp.close();
   out.close(); 
   return 0; 
}


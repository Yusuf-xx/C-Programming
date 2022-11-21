/*-----------------------------------------------------------------------------------
-  |  |  |  |  |  Md Yusuf Bin Forkan // 201909M10266 // A19MJ0178   |  |  |  |  |  -
-  |  |  |  |  |  Ruhul Quddus Tamim  // 201807M10023 // A19MJ0182   |  |  |  |  |  -
-  |  |  |  |  |  Shafi Ahmed         // 201909M10257 // A19MJ0184   |  |  |  |  |  -
------------------------------------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std; 

ofstream outfile;

 void Displayline()
 { 
 	for ( int i = 0; i < 52; i++ )
 	  outfile << "-";
 	  outfile << endl; 
 }
 
 int findIndWinner( int winner[] )
 {
 	int arr_position;
 	int max = winner[0]; 
 	
 	for ( int i = 0; i < 12; i++ )
 	    if ( winner[i] > max )
 	    {
		   max = winner[i];
		   arr_position = i;
	    }
    return arr_position; 	
 }
 
 int findTeamWinner( int T1, int T2, int T3 )
 {
 	int max;
 	max = T1;
 	if ( max < T2)
 	 max = T2;
 	else max = T3;
 	return max; 
 }
 
 int main()
 {
 	int marks[12][7];
 	int column_total[12];
 	int total_column = 0; int x = 0;
    int total_T1 = 0; int total_T2 = 0; int total_T3 = 0; 
 	int winner; 
 	int team_winner; 
 	ifstream inpfile; 
 	
 	inpfile.open("input2.txt");
 	outfile.open("output2.txt");  
 	
 	if ( !inpfile ) cout << "Sorry, input file does not exist!\nPress any key to continue . . .";
 	Displayline();
	
    outfile << "Id"; 
	outfile << setw(7) << "E1"; 
	outfile << setw(7) << "E2";
    outfile << setw(7) << "E3"; 
	outfile << setw(7) << "E4"; 
	outfile << setw(7) << "E5";
	outfile << setw(12) << "Total";
	outfile << endl;
	Displayline();
	
	for ( int i = 0; i < 12; i++ )
	 {
	 	for ( int j = 0; j < 7; j++ )
	 	{
	 	   inpfile >> marks[i][j];
		}
	 }
	 outfile << "TEAM 1";
	 outfile << endl;
	 for ( int i = 0; i < 4; i++ )
	 { 
	    for ( int j = 1; j < 7; j++ )
		{
		   outfile << left << setw(7) << marks[i][j]; 
		   if ( j == 6) break; else total_column += marks[i][j+1];
	    }
	       column_total[x] = total_column; 
		   total_T1 += column_total[x];
	       outfile << right << setw(4) << column_total[x]; 
	       outfile << endl; 
	       total_column = 0;
	       x++;
	  }     
	    outfile << "TOTAL" << right << setw(42) << total_T1; 
	    outfile << endl;
	    Displayline();
	      
		outfile << "TEAM 2";
	    outfile << endl;
	 for ( int i = 4; i < 8; i++ )
	 {
	 	 	for ( int j = 1; j < 7; j++ )
	 	{
	 		 outfile << left << setw(7) << marks[i][j];
	 		 if ( j == 6) break; else total_column += marks[i][j+1]; 
		}
		     column_total[x] = total_column;
			 total_T2 +=  column_total[x];   
	         outfile << right << setw(4) << column_total[x];
	         outfile << endl;
	         total_column = 0;
	         x++; 
	} 
	    outfile << "TOTAL" << right << setw(42) << total_T2; 
	    outfile << endl;
	    Displayline();
	    
		outfile << "TEAM 3";
	    outfile << endl;
	 for ( int i = 8; i < 12; i++ )
	 {
	 	 	for ( int j = 1; j < 7; j++ )
	 	{
	 		outfile << left << setw(7) << marks[i][j];
	 		if ( j == 6) break; else total_column += marks[i][j+1]; 
		}
		     column_total[x] = total_column;
			 total_T3 += column_total[x];    
	         outfile << right << setw(4) << column_total[x];
	         outfile << endl;
	         total_column = 0;
	         x++;
	}
	    outfile << "TOTAL" << right << setw(42) << total_T3;
	    outfile << endl;
	    Displayline();
	    outfile << endl;
		 
	    winner = findIndWinner(column_total); 
	    team_winner = findTeamWinner(total_T1, total_T2, total_T3); 
	    
	    outfile << "Winner for Individual Category: " << marks[winner][1] << " (TEAM " << marks[winner][0] << ")" << endl; 
	    if ( team_winner == total_T1 ) outfile << "Winner for Group Category: " << "TEAM " << marks[0][0] << "" << " (Score = " << team_winner << ")";
	    else if ( team_winner == total_T2 ) outfile << "Winner for Group Category: " << "TEAM " << marks[4][0] << "" << " (Score = " << team_winner << ")";
	    else outfile << "Winner for Group Category: " << "TEAM " << marks[8][0] << " " << " (Score = " << team_winner << ")"; 
	 
	 
    inpfile.close();
    outfile.close();
    return 0;
 } 
 
 

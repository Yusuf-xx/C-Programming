/*-----------------------------------------------------------------------------------
-  |  |  |  |  |  Md Yusuf Bin Forkan // 201909M10266 // A19MJ0178   |  |  |  |  |  -
-  |  |  |  |  |  Ruhul Quddus Tamim  // 201807M10023 // A19MJ0182   |  |  |  |  |  -
-  |  |  |  |  |  Shafi Ahmed         // 201909M10257 // A19MJ0184   |  |  |  |  |  -
------------------------------------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#define ROW 30
using namespace std;

ofstream outFile;

void getInput(char name[][10], int intake[], int enrol[], int output[], int &n)
{
	ifstream inpFile; 
	ifstream inp;
	
	inp.open("input1.txt");
	n = 0;
	
	if (inp.fail())
	{
		cout << "Error! File not exist" << endl;
		exit(1);
	}

	while (inp >> name[n])
	{
		inp >> intake[n];		
		inp >> enrol[n];	
		inp >> output[n];
			
		n++;
	}	
		
	inp.close();

}

int calTotal(int rec[], int n)
{
	int total;
	
	total = 0;
	
	for (int i = 0; i < n; i++)
	
		total = total + rec[i];
		
	return total;

}

int getLowest(int rec[], int n)
{
	int min; 
	int ind;
	
	min = rec[0];
	ind = 0;
	for (int i = 0; i < n; i++)
	{
	   if (rec[i] < min)
	    {
	    	min = rec[i];
	        ind = i;
        }
	}
	return ind;
}

int getHighest(int rec[], int n)
{
	int max; 
	int ind;
	
	max = -1;
	
	for (int i = 1; i < n; i++)
	{
		if (rec[i] > max)
		{
			max = rec[i];
			ind = i;
		}
	}
	
	return ind;
}

void viewLine()
{
	for (int i = 0; i < 68; i++)
	{
		outFile << "-";
	}
		
	outFile << endl;
}

int main()
{
	char name[ROW][10];
	int intake[ROW], enrol[ROW], output[ROW]; 
	int totIntake, totEnrol, totOutput;
	int num;
	int i;
	float aveInt, aveEnr, aveOut;

	getInput(name, intake, enrol, output, num);
	totIntake = calTotal(intake, num);
	totEnrol = calTotal(enrol, num);
	totOutput= calTotal(output, num);	
	aveInt = totIntake/num;
	aveEnr = totEnrol/num;
	aveOut = totOutput/num;

	int Intake = getLowest(intake, num);
	int Enrol = getLowest(enrol, num);
	int Output = getLowest(output, num);
	
	int _Int = getHighest(intake, num);
	int _Enr = getHighest(enrol, num);
	int _Out = getHighest(output, num);


	ofstream out;
	
	outFile.open("output1.txt");
	
	outFile << "\tNUMBER OF STUDENTS' INTAKE, ENROLMENT AND OUTPUT" << endl;
	outFile << " \t\tIN PUBLIC UNIVERSITIES (2015)" << endl;
	
	viewLine();
	outFile << "UNIVERSITY\t       INTAKE\t           ENROLMENT           OUTPUT " << endl;
	viewLine();
	
	for (int i = 0; i < num; i++)
	
	outFile << left << setw (20) << name[i]
			<< setw (20) << intake[i]
			<< setw (20) << enrol[i]
			<< setw (20) << output[i] << endl;
			
	viewLine();
	outFile << left 
	<< setw (20)<< "TOTAL" << setw(20) << totIntake << setw(20) << totEnrol
			<< setw(20)<< totOutput << endl;
	outFile << setw(20)<< "AVERAGE" << setw(20) << aveInt << setw(20) << aveEnr << setw(20)
			<<aveOut << endl;
	viewLine();

	outFile << "\nTHE LOWEST NUMBER OF STUDENTS' INTAKE    = " << intake[Intake] << "(" << name[Intake] << ")" << endl;
	outFile << "THE LOWEST NUMBER OF STUDENTS' ENROLMENT = " << enrol[Enrol] << "(" << name[Enrol] << ")" << endl;
	outFile << "THE LOWEST NUMBER OF STUDENTS' OUTPUT    = " << output[Output] << "(" << name[Output] << ")" <<endl;
		
	outFile << "\nTHE HIGHEST NUMBER OF STUDENTS' INTAKE    = " << intake[_Int] << "(" << name[_Int] << ")" << endl;
	outFile << "THE HIGHEST NUMBER OF STUDENTS' ENROLMENT = " << enrol[_Enr] << "(" << name[_Enr] << ")" << endl;
	outFile << "THE HIGHEST NUMBER OF STUDENTS' OUTPUT    = " << output[_Out] << "(" << name[_Out] << ")" << endl;
	
	outFile << "\nTHE RANGE OF NUMBER OF STUDENTS' INTAKE    = " << intake[getHighest(intake, num)] - intake[getLowest(intake, num)] << endl;
	outFile << "THE RANGE OF NUMBER OF STUDENTS' ENROLMENT = " << enrol[getHighest(enrol, num)] - enrol[getLowest(enrol, num)] << endl;
	outFile << "THE RANGE OF NUMBER OF STUDENTS' OUTPUT    = " << output[getHighest(output, num)] - output[getLowest(output, num)] << endl << endl;
	viewLine();
	
	outFile.close();
	
	return 0;
}

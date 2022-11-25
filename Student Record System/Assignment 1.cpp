/*-----------------------------------------------------------------------------------
-  |  |  |  |  |  Md Yusuf Bin Forkan // 201909M10266 // A19MJ0178   |  |  |  |  |  -
-  |  |  |  |  |  Ruhul Quddus Tamim  // 201807M10023 // A19MJ0182   |  |  |  |  |  -
-  |  |  |  |  |  Shafi Ahmed         // 201909M10257 // A19MJ0184   |  |  |  |  |  -
------------------------------------------------------------------------------------*/
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

class Advisor
{
	private:
		string adName;
	public: 
		Advisor(string a=" ")
		{
			setadvisor(a);
		}
		void setadvisor(string a)
		{
			adName=a;
		}
		string getadvisor()
		{
			return adName;
		}
	
};

class Project
{
	private:
		string supName;
		string research;
	public: 
		Project(string a=" ",string b=" ")
		{
			setProject(a,b);
		}
		void setProject(string a,string b)
		{
			supName=a;
			research=b;
		}
		string getSupNm()
		{
			return supName;
		}
		string getRsrch()
		{
			return research;
		}
	
};

class Student
{
	private:
		string name;
		string program;
		Advisor advisor;
		Project project;
	public: 
		Student(string a=" ", string b=" ",string c=" ",string d=" ",string e=" "):project(d,e)
		{
			set(a,b,c);
		}
		void set(string a,string b,string c)
		{
			name=a;
			program=b;
			advisor=c;
		}
		string getName()
		{
			return name;
		}
		string getSupName()
		{
			return project.getSupNm();
		}
		string getResearch()
		{
			return project.getRsrch();
		}

		
	
};





int main()
{
	ifstream in("pgstudents.txt");

	string * arr;
	arr=new string[119];
	for(int i=0;i<119;i++)
	{
		getline(in,arr[i]); 
	}
	Student student[20];
	int j=0;
	for(int i=0;i<20;i++)
	{
		
		student[i]=Student(arr[0+j],arr[1+j],arr[2+j],arr[3+j],arr[4+j]);
		j=j+6;
	}

	ofstream out("pgstudents_outfile.txt");
	
	
	out<<"The list of Postgraduate Students"<<endl;
	out<<left<<"NO"<<'\t'<<"NAME"<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<setw(50)<<"SUPERVISOR"<<setw(50)<<"PROJECT"<<endl;
	for(int i=0;i<20;i++)
	{
		out<<left<<1+i<<'\t'<<student[i].getName()<<'\t'<<'\t'<<'\t'<<'\t'<<setw(50)
		<<student[i].getSupName()<<setw(50)<<student[i].getResearch()<<endl;
	}
	


	delete [] arr;

	in.close();
	out.close();


	
	return 0;
}

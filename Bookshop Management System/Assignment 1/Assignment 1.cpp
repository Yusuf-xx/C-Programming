#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include <algorithm>

using namespace std;

//Book class with class constructor
class book {

private:
	int bookCode;
	string author;
	string title;
	double price;
	string publisher;
	int stock;

public:

	book() {};
    //class constructor with auguments
	book(int _bookCode, string _author, string _title, double _price, string _publisher, int _stock)
	{
		bookCode = _bookCode;
		author = _author;
		title = _title;
		price = _price;
		publisher = _publisher;
		stock = _stock;
	}
	//Function that will show all the details of each book
	void showDetail()
	{
		cout << "Book Code: " << bookCode << endl;
		cout << "Author: " << author << endl;
		cout << "Title: " << title << endl;
		cout << "Publisher: " << publisher << endl;
		cout << "Price: " << price << endl;
		cout << "Availabe Stocks: " << stock << endl;
		cout << endl << endl;
	}
	//Sorts book price
	void priceSort(int bCount, int counter1, int ch3)
	{
		int sortBookCode[2000];
		string temp2;
		string temp3;
		double sortPrice[2000];
		string temp4;
		int temp5;
		int count = 0;
		string comma_string;

		ifstream classFile;
		classFile.open("list.txt");
		//Reading books data from file
		while (classFile) {

			classFile >> sortBookCode[count];//Getting bookcode value from file
			getline(classFile, comma_string, ',');
			getline(classFile, temp2, ',');
			getline(classFile, temp3, ',');
			classFile >> sortPrice[count];//Getting price value from file
			getline(classFile, comma_string, ',');
			getline(classFile, temp4, ',');
			classFile >> temp5;
			getline(classFile, comma_string, '\n');

			count++;
		}
		count--;

		pair<double, int> AB[2000];//Pairing two arrays

		//Getting value of price and bookcode to the paired array
		for (int i = 0; i < bCount + 1; i++)
		{
			AB[i].first = sortPrice[i];
			AB[i].second = sortBookCode[i];
		}
		
		sort(AB, AB + (bCount + 1));//Sorting from low to high

		if (ch3 == 2)
			reverse(AB, AB + (bCount + 1));//After sorting price reversed from high to low

		//Getting value of price and bookcode from the paired array after sorting
		for (int i = 0; i < bCount + 1; i++)
		{
			sortPrice[i] = AB[i].first;
			sortBookCode[i] = AB[i].second;
		}

		//Comparing price and bookcode together to show book details after sorting
		if (sortPrice[counter1] == price && sortBookCode[counter1] == bookCode)
		{
			cout << "Book Code: " << bookCode << endl;
			cout << "Author: " << author << endl;
			cout << "Title: " << title << endl;
			cout << "Publisher: " << publisher << endl;
			cout << "Price: " << price << endl;
			cout << "Availabe Stocks: " << stock << endl;
			cout << endl << endl;
		}
	}
	//Remove books from file
};

book b[1000];//Book Array
//Customer Function
void customer(int bCount)//Takes one parameter
{
	int x;
	int check;
	int test1, test2;
	int counter2 = 0;
	while (1) {
		cout << " =====================\n|\t Menu         |\n =====================\n\n1. Search Books and Purchase\n2. Books Price\n3. Back" << endl;
		
		//Getting the input from user and checks if it is valid or not
		do {
			cout << "\nInput: ";
			cin >> x;

		} while (x != 1 && x != 2 && x != 3 && cout << "Invalid Input!\n" << endl);

		test1 = bCount;
		test2 = bCount;
		
		if (x == 2)
		{
			int ch2;

			cout << "Sorting Option: \n" << endl;
			cout << "1. Low to High Price Books" << endl;
			cout << "2. High to Low Price Books\n" << endl;

			//Getting the input from user and checks if it is valid or not
			do {
				cout << "Input: ";
				cin >> ch2;

			} while (x != 1 && x != 2 && x != 3 && cout << "Invalid Input!\n" << endl);

			cout << endl;
			//To show low to high price books
			if (ch2 == 1) {

				for (int t = test1 + 1; t > 0; t--) {
					for (int t = 0; t <= test2; t++)
						b[t].priceSort(bCount, counter2, ch2);
					counter2++;
				}
			}
			//To show high to low price books
			else if (ch2 == 2) {

				for (int t = test1 + 1; t > 0; t--) {
					for (int t = 0; t <= test2; t++)
						b[t].priceSort(bCount, counter2, ch2);

					counter2++;
				}
			}
		}
		else if (x == 3) {
			system("cls");
			return;
		}
		counter2 = 0;
		//To show the menu option when get a valid input
		do {
			cout << "Press 1 To Show Menu Option Again: ";
			cin >> x;

			if (x == 1)
				system("cls");
			else
				cout << "Invalid Input!\n" << endl;
		} while (x != 1);
	}
}
//The main function
int main()
{
	int choice;
	int bookCode;
	string author;
	string title;
	double price;
	string publisher;
	int stock;
	int count = 0;
	string comma_string;

	ifstream classFile;
	classFile.open("list.txt");

	//Reading books data from file
	while (classFile) {

		classFile >> bookCode;
		getline(classFile, comma_string, ',');
		getline(classFile, author, ',');
		getline(classFile, title, ',');
		classFile >> price;
		getline(classFile, comma_string, ',');
		getline(classFile, publisher, ',');
		classFile >> stock;
		getline(classFile, comma_string, '\n');

		b[count] = book(bookCode, author, title, price, publisher, stock);

		count++;
	}
	count--;

	do {
		cin.clear();
		cout << "\n\tWelcome To RJ Bookshop Management System" << endl;
		cout << "\n******** Please Login *********" << endl;
		cout << "\n\n\tPlease Select An Option From The Menu Below\n\n";
		cout << "\t\t1. Customer Login \n\n\t\t0. Exit";

		do {
			cout << "\n\n\tPlease Enter Your Choice : ";
			cin >> choice;
		} while (choice != 1 && choice != 0 && cout << "\tInvalid Input!");
		
		switch (choice)
		{

		case 1:
		{
			system("cls");
			customer(count);
			choice = 100;
		}
		break;

		case 0:
		{
			cout << "\nApplication Successfully Closed!\n" << endl;
			system("pause");
		}
	  }
	} while (choice != 0 && choice != 1 && choice != 2 && choice != 3);
}

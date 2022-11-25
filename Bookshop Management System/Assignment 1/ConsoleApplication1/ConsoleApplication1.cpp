#include "stdafx.h"

#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include <algorithm>

using namespace std;

int error;

int Login(string& admin, string& password);
int staff(string& user, string& pass1);

int failure = 0;
int success = 0;

//To Define the number of successful transaction
void Transaction(int a)
{
	if (a == 0)
		failure++;
	else
		success++;
}

//Book class with class constructor
class book {

private:
	int bookCode;
	string author;
	string title;
	double price;
	string publisher;
	int stock;

	//Function To Update the existing book price
	void priceUpdate()
	{
		cout << "\nEnter The New Price: ";
		cin >> price;
		cout << "Price Successfully Updated!\n" << endl;
	}

	//Function to update the existing book stock
	void stockUpdate()
	{
		cout << "\nEnter The New Stock: ";
		cin >> stock;
		cout << "Stock Successfully Updated!\n" << endl;
	}

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

	//class constructor used for searching books
	book(string nAuthor, string nPublisher) {
		author = nAuthor;
		publisher = nPublisher;
	}

	//class constructor used for searching bookcode
	book(int nBookCode) {
		bookCode = nBookCode;
	}

	//Search Book Function
	int search(book b)
	{
		transform(author.begin(), author.end(), author.begin(), ::toupper);
		transform(b.author.begin(), b.author.end(), b.author.begin(), ::toupper);
		transform(publisher.begin(), publisher.end(), publisher.begin(), ::toupper);
		transform(b.publisher.begin(), b.publisher.end(), b.publisher.begin(), ::toupper);

		if (author == b.author && publisher == b.publisher)
			return 1;
		else
			return 0;
	}

	//To search bookcode
	int searchCode(book b)
	{
		if (bookCode == b.bookCode)
			return 1;
		else
			return 0;
	}

	//Number of books the customer want
	void noOfCopies()
	{
		int n;
		cout << "\nBook Details:\n" << endl;
		showDetail();
		cout << "Enter Required Number Of Copies: ";
		cin >> n;

		if (n > stock)
		{
			cout << "Required Copies Is Not In Stock, Sorry!\n" << endl;
			Transaction(0);
		}

		else
		{
			cout << "Total Cost of The Books: " << (n*price) << endl;//for the total price calculation
			stock = stock - n;
			cout << endl;
			cout << "Remaining Stock: " << stock << endl;//Define the remaining stock
			Transaction(1);
			cout << endl;
		}
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

	//Update existing books price and stock
	void update()
	{
		int x;
		cout << "\nSelect What To Update\n\n1. Price\n2. Stock\n" << endl;
		cout << "Input: ";
		cin >> x;

		if (x == 1)
			priceUpdate();
		else
			stockUpdate();
	}

	//Update file after changing book price and stock
	void fileUdate(int t)
	{
		ofstream newFile;

		if (t == 0) {
			newFile.open("list.txt");
			newFile << bookCode << "," << author << "," << title << "," << price << ".00" << "," << publisher << "," << stock;
		}

		if (t > 0) {
			newFile.open("list.txt", fstream::app);
			newFile << endl << bookCode << "," << author << "," << title << "," << price << ".00" << "," << publisher << "," << stock;
		}
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
	void bookRemove()
	{
		book b2[1000];
		int rBookCode;
		string rAuthor;
		string rTitle;
		double rPrice;
		string rPublisher;
		int rStock;

		int rCount = 0;
		string rComma_string;

		ifstream classFile;
		classFile.open("list.txt");

		//Reading books data from file
		while (classFile) {

			classFile >> rBookCode;
			getline(classFile, rComma_string, ',');
			getline(classFile, rAuthor, ',');
			getline(classFile, rTitle, ',');
			classFile >> rPrice;
			getline(classFile, rComma_string, ',');
			getline(classFile, rPublisher, ',');
			classFile >> rStock;
			getline(classFile, rComma_string, '\n');

			b2[rCount] = book(rBookCode, rAuthor, rTitle, rPrice, rPublisher, rStock);
			rCount++;
		}
		rCount--;

		for (int x = 0; x <= rCount; x++) {

			//When finds a bookcode value is zero then it removes the book by replacing book data values with removed book data
			if (b2[x].bookCode == 0) {

				b2[x].bookCode = b2[x + 1].bookCode - 1;
				b2[x + 1].bookCode = 0;
				b2[x].author = b2[x + 1].author;
				b2[x].title = b2[x + 1].title;
				b2[x].price = b2[x + 1].price;
				b2[x].publisher = b2[x + 1].publisher;
				b2[x].stock = b2[x + 1].stock;
			}
		}

		//Updating file data after removing	a book
		ofstream newFile2;
		newFile2.open("list.txt", fstream::ate);

		for (int n = 0; n < rCount; n++) {

			newFile2 << b2[n].bookCode << "," << b2[n].author << "," << b2[n].title << "," << b2[n].price << ".00" << "," << b2[n].publisher << "," << b2[n].stock;
			
			if (n < (rCount - 1))
				newFile2 << endl;
		}
	}
};

book b[1000];//Book Array

//Seller Function
void seller(int c, int bCount)//Takes two parameters
{
	int a, n;
	int check;

	int nBookCode;
	string nAuthor;
	string nTitle;
	double nPrice;
	string nPublisher;
	int nStock;
	string rComma_string;

	int cBookCode;

	while (1) {

		//When a admin logged in
		if (c == 1) {
			cout << " =====================\n|\t Menu         |\n =====================\n\n1. Show Books\n2. Update\n3. Transaction\n4. Back" << endl;
			
			//Getting the input from user and checks if it is valid or not
			do {
				cout << "\nInput: ";
				cin >> a;

			} while (a != 1 && a != 2 && a != 3 && a != 4 && cout << "Invalid Input!" << endl);
		}

		//When a staff logged in
		else if (c == 2) {
			cout << " =====================\n|\t Menu         |\n =====================\n\n1. Show Books\n2. Update\n3. Back" << endl;

			//Getting the input from user and checks if it is valid or not
			do {
				cout << "\nInput: ";
				cin >> a;

			} while (a != 1 && a != 2 && a != 3 && cout << "Invalid Input!" << endl);
		}

		if (a == 1) {
			system("cls");
			cout << " =============================\n|\t  Book Details        |\n =============================\n" << endl;
			
			for (int x = 0; x <= bCount; x++)
				b[x].showDetail();//Show all book details
		}

		else if (a == 2) {
			int ch;
			system("cls");

			cout << " ===========================\n|\t Book Update        |\n ===========================\n" << endl;
			cout << "1. Existing Book Update" << endl;
			cout << "2. Add New Book" << endl;
			cout << "3. Remove Book" << endl;

			//Getting the input from user and checks if it is valid or not
			do {
				cout << "\nInput: ";
				cin >> ch;

			} while (ch != 1 && ch != 2 && ch != 3 && cout << "Invalid Input!" << endl);

			if (ch == 1) {
				cout << "\nEnter The Book Code You Want To Update: ";
				cin >> n;//Getting bookcode from the user
				book bCode(n);
				check = 0;
				
				for (int x = 0; x <= bCount; x++) {

					//Search for bookcode if it exists or not
					if (bCode.searchCode(b[x]) == 1) {
						b[x].update();//Update book price or stock
						check = 1;
					}
				}

				//When bookcode doesn't exist
				if (check == 0)
					cout << "Bookcode not exists!" << endl;

				//Update book data to file after changing any price or stock of book 
				for (int x = 0; x <= bCount; x++)
					b[x].fileUdate(x);
			}

			else if (ch == 2) {
				cout << "\nFill up the following details\n" << endl;

				//New book details input by the user
				cin.ignore();
				cout << "Author: ";
				getline(cin, nAuthor);
				cout << "Title: ";
				getline(cin, nTitle);
				cout << "Price: ";
				cin >> nPrice;
				cin.ignore();
				cout << "Publisher: ";
				getline(cin, nPublisher);
				cout << "Total Stocks: ";
				cin >> nStock;
				cin.ignore();
				cout << endl;

				bCount++;
				nBookCode = bCount + 111;//Creates bookcode for new book
				b[bCount] = book(nBookCode, nAuthor, nTitle, nPrice, nPublisher, nStock);

				cout << "New Book Added Successfully!\n" << endl;

				//Update book data to file after adding a book
				for (int x = 0; x <= bCount; x++)
					b[x].fileUdate(x);
			}

			else if (ch == 3) {

				cout << "\nEnter The Book Code To Remove: ";
				cin >> cBookCode;//Getting bookcode from user
				book bCode2(cBookCode);
				check = 0;

				//Go through all the book to see if the bookcode exists or not
				for (int x = 0; x <= bCount; x++) {

					//If bookcode exists set the following value to that bookcoode to remove
					if (bCode2.searchCode(b[x]) == 1) {
						b[x] = book(0, "null", "null", 0, "null", 0);
						check = 1;
					}
				}

				//When bookcode doesn't exist
				if (check == 0)
					cout << "Bookcode not exists!\n" << endl;

				else if (check == 1) {

					int rCount = 0;

					ifstream classFile;
					classFile.open("list.txt");

					////Update book data to file with removed book details
					for (int x = 0; x <= bCount; x++)
						b[x].fileUdate(x);

					//Remove books from file
					b[0].bookRemove();
					
					//Reading book data with correct formation after removing a book
					while (classFile) {

						classFile >> nBookCode;
						getline(classFile, rComma_string, ',');
						getline(classFile, nAuthor, ',');
						getline(classFile, nTitle, ',');
						classFile >> nPrice;
						getline(classFile, rComma_string, ',');
						getline(classFile, nPublisher, ',');
						classFile >> nStock;
						getline(classFile, rComma_string, '\n');

						b[rCount] = book(nBookCode, nAuthor, nTitle, nPrice, nPublisher, nStock);
						rCount++;
					}
					rCount--;

					bCount = rCount;
					cout << "Bookcode " << cBookCode << " Successfully Removed!\n" << endl;
				}
			}

			else if (ch == 4) {

				system("cls");
				return;
			}
		}

		//When a admin logged in
		if (c == 1) {

			if (a == 3) {

				cout << "\nTotal Falied Transaction: " << failure << endl;
				cout << "Total Successful Transaction: " << success << endl;
				cout << endl;
			}
			else if (a == 4) {

				system("cls");
				return;
			}
		}

		//When a staff logged in
		else if (c == 2) {

			if (a == 3) {
				system("cls");
				return;
			}
		}
		else
			cout << "\nInvalid Input!" << endl;

		//To show the menu option when get a valid input
		do {
			cout << "Press 1 To Show Menu Option Again: ";
			cin >> a;

			if (a == 1)
				system("cls");

			else
				cout << "Invalid Input!\n" << endl;

		} while (a != 1);
	}
}

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

		if (x == 1)
		{
			string a;
			string p;

			system("cls");

			cin.ignore();
			cout << "\n Searching Books. . . . .\n==========================\n" << endl;
			cout << "Enter The Author Name: ";
			getline(cin, a);
			cout << endl;
			cout << "Enter The Publisher Name: ";

			getline(cin, p);

			book bSearch(a, p);

			for (int x = 0; x <= bCount; x++) {
				check = 0;

				if (bSearch.search(b[x]) == 1) {
					b[x].noOfCopies();
				}

				if (bSearch.search(b[x]) == 1) {
					check = 1;
					break;
				}
			}

			if (check == 0) {
				cout << "\nThe Book is not available. Sorry!\n" << endl;
				Transaction(0);
			}

			for (int x = 0; x <= bCount; x++)
				b[x].fileUdate(x);
		}

		else if (x == 2)
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
	string User;
	string password;

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
		cout << "\n******************** Please Login ***********************" << endl;
		cout << "\n\n\tPlease Select An Option From The Menu Below\n\n";
		cout << "\t\t1. Admin Login \n\n\t\t2. Staff Login \n\n\t\t3. Customer Login \n\n\t\t0. Exit";

		do {
			cout << "\n\n\tPlease Enter Your Choice : ";
			cin >> choice;
		} while (choice != 1 && choice != 2 && choice != 3 && choice != 0 && cout << "\tInvalid Input!");
		
		switch (choice)
		{
		case 1:
		{
			do {				
				cout << "\n\tPlease Enter The Admin Username : ";
				cin >> User;
				cout << "\tPlease Enter The Password : ";
				cin >> password;

			} while (Login(User, password) == 0);

			if (Login(User, password) == 1) {

				system("cls");
				seller(choice, count);
				choice = 100;
			}
		}
		break;

		case 2:
		{
			do {
				cout << "\n\tPlease Enter The Staff Username : ";
				cin >> User;
				cout << "\tPlease Enter The Password : ";
				cin >> password;

			} while (staff(User, password) == 0);

			if (staff(User, password) == 1) {
				system("cls");
				seller(choice, count);
				choice = 100;
			}
		}
		break;

		case 3:
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

//Admin login function
int Login(string& admin, string& password)
{
	string Users[200];
	string Pass[200];
	bool valid = false;

	int x = 0;

	ifstream UsFile;
	UsFile.open("admins.txt");

	UsFile >> Users[x] >> Pass[x];

	while (UsFile)
	{
		x++;
		if (x >= 200)
			break;

		UsFile >> Users[x] >> Pass[x];
	}

	for (int a = 0; a < x; a++)
	{
		if (admin == Users[a] && password == Pass[a])//Match the username and password with the file named admins
		{
			valid = true;
			return 1;
			break;
		}
	}

	if (!valid)
	{
		cout << "\n\tInvalid Username & Password!\t\t\n";
		return 0;
	}
}

//Staff login function
int staff(string& user, string& pass1)
{
	string Users[200];
	string Pass[200];
	bool valid = false;

	int x = 0;

	ifstream UsFile;
	UsFile.open("users.txt");

	UsFile >> Users[x] >> Pass[x];

	while (UsFile)
	{
		x++;

		if (x >= 200)
			break;

		UsFile >> Users[x] >> Pass[x];
	}

	for (int a = 0; a < x; a++)
	{
		if (user == Users[a] && pass1 == Pass[a])//Match the username and password with the file named users

		{
			valid = true;
			return 1;
			break;
		}
	}

	if (!valid)
	{
		cout << "\n\tInvalid Username & Password!\n";
		return 0;
	}
}

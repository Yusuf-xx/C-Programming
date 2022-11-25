#include "stdafx.h"

#include <iostream>//Header Files
#include <string>
#include <fstream>
using namespace std;

int error;

//Global Login Function
int Login(string& admin, string& password);
int staff(string& user, string& pass1);


struct book
{
	string title;
	string author;
	string publisher;
	int pubYear;
	string isbn;
	book* next;
	book(string, string, string, int, string, book*);
};
//Constructor
book::book(string _title, string _author, string _publisher, int _pubYear, string _isbn, book* _next)
	:title(_title), author(_author), publisher(_publisher), pubYear(_pubYear), isbn(_isbn), next(_next)
{}

typedef book* bookPtr;
//Function To get The whole line
void getline(istream &stream, string &str, char delimiter)
{
	char temp[500];

	stream.get(temp, 500, delimiter);
	stream.ignore(500, delimiter);
	str = temp;
}
//Function To get The whole line
void getline(istream &stream, int &num, char delimiter)
{
	int temp;

	stream >> temp;
	stream.ignore(500, delimiter);
	num = temp;
} 

//Functions
void readFromFile(bookPtr &head);
void insertNewBook(bookPtr &head);
void deleteByTitle(bookPtr &head);
bookPtr locateByNode(bookPtr temp, string tit);
void deleteByIsbn(bookPtr &head);
bookPtr locateNodeByIsbn(bookPtr temp, string isb);
void searchByTitle(bookPtr temp);
void printBookList(bookPtr temp);
void printListByAuthor(bookPtr temp);
void saveIntoFile(bookPtr temp);
int countNodes(bookPtr temp);

//Bookmanagement Function
void bookManagement(int input)
{
	int choice, x;
	bookPtr head = NULL;
	readFromFile(head);//To read the data from file

	while (1) {

		if (input == 1) {
			//Options for admins
			cout << "Select your option\n\n";
			cout << "1. Add a new book to the list\n";
			cout << "2. Delete a book based on Title\n";
			cout << "3. Delete a book based on ISBN\n";
			cout << "4. Search for a book by Title\n";
			cout << "5. List all books\n";
			cout << "6. List all books by an Author\n";
			cout << "7. Back\n\n";

			do {
				cout << "Enter your choice => ";

				cin >> choice;

			} while ((choice < 1 || choice > 7) && cout << "Invalid Input!\n");

			switch (choice)
			{
			case 1:
				system("cls");
				insertNewBook(head);
				break;
			case 2:
				system("cls");
				deleteByTitle(head);
				break;
			case 3:
				system("cls");
				deleteByIsbn(head);
				break;
			case 4:
				system("cls");
				searchByTitle(head);
				break;
			case 5:
				system("cls");
				printBookList(head);
				break;
			case 6:
				system("cls");
				printListByAuthor(head);
				break;
			case 7:
				return;
			}

		}

		else if (input == 2) {
			//Options for staffs
			cout << "Select your option\n\n";
			cout << "1. Add a new book to the list\n";
			cout << "2. Delete a book based on Title\n";
			cout << "3. Delete a book based on ISBN\n";
			cout << "4. Back\n\n";
			do {
				cout << "Enter your choice => ";

				cin >> choice;

			} while ((choice < 1 || choice > 4) && cout << "Invalid Input!\n");


			switch (choice)
			{
			case 1:
				system("cls");
				insertNewBook(head);
				break;
			case 2:
				system("cls");
				deleteByTitle(head);
				break;
			case 3:
				system("cls");
				deleteByIsbn(head);
				break;
			case 4:
				return;
			}
		}

		else if (input == 3) {
			//Options for customers
			cout << "Select your option\n\n";
			cout << "1. Search for a book by Title\n";
			cout << "2. List all books\n";
			cout << "3. List all books by an Author\n";
			cout << "4. Back\n\n";
			do {
				cout << "Enter your choice => ";

				cin >> choice;

			} while ((choice < 1 || choice > 4) && cout << "Invalid Input!\n");


			switch (choice)
			{
			case 1:
				system("cls");
				searchByTitle(head);
				break;
			case 2:
				system("cls");
				printBookList(head);
				break;
			case 3:
				system("cls");
				printListByAuthor(head);
				break;
			case 4:
				return;
			}
		}
		saveIntoFile(head);//Save data to the file

		do {
			cout << "Press 1 To Show Menu Option Again: ";//For going back again
			cin >> x;

			if (x == 1)
				system("cls");

			else
				cout << "Invalid Input!\n" << endl;

		} while (x != 1);
	}
}
//Function for reading the data
void readFromFile(bookPtr &head)
{
	int numBooks, yer;
	string tit, autr, publs, isb;
	ifstream infile("books.txt", ios::in);
	infile >> numBooks;
	infile.ignore(500, '\n');
	for (int count = 0; count < numBooks; count++)
	{
		getline(infile, tit, '\n');
		getline(infile, autr, '\n');
		getline(infile, publs, '\n');
		getline(infile, yer, '\n');
		getline(infile, isb, '\n');

		head = new book(tit, autr, publs, yer, isb, head);
	}
}
//Function for adding a new book
void insertNewBook(bookPtr &head)
{
	string tit, autr, publs, isb;
	int yer;

	cout << "Title: ";
	cin.ignore(500, '\n');
	getline(cin, tit, '\n');
	cout << "Author: ";
	getline(cin, autr, '\n');
	cout << "Publisher: ";
	getline(cin, publs, '\n');
	cout << "Year: ";
	getline(cin, yer, '\n');
	cout << "ISBN: ";
	getline(cin, isb, '\n');

	head = new book(tit, autr, publs, yer, isb, head);
}
//Function For deleting a Book Based on title
void deleteByTitle(bookPtr &head)
{
	string tit;

	cout << "Insert Book Title: ";
	cin.ignore(500, '\n');
	getline(cin, tit, '\n');

	bookPtr p = locateByNode(head, tit);

	if (p == NULL)
		cout << "\nDeletion cannot be done.\n\n";
	else if (head == p)
		head = p->next;
	else
	{
		bookPtr q = head;
		while (q->next != p)
			q = q->next;
		q->next = p->next;
	}
	delete p;
}
//Function For loacting a node by title
bookPtr locateByNode(bookPtr temp, string tit)
{
	while (temp != NULL)
	{
		if (temp->title == tit)
		{
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}
//Function for deleting a book by ISBN
void deleteByIsbn(bookPtr &head)
{
	string isb;

	cout << "Insert Book ISBN: ";
	cin.ignore(500, '\n');
	getline(cin, isb, '\n');

	bookPtr p = locateNodeByIsbn(head, isb);

	if (p == NULL)
		cout << "\nDeletion cannot be done.\n\n";
	else if (head == p)
		head = p->next;
	else
	{
		bookPtr q = head;
		while (q->next != p)
			q = q->next;
		q->next = p->next;
	}
	delete p;
}
//Function For loacting a node by ISBN
bookPtr locateNodeByIsbn(bookPtr temp, string isb)
{
	while (temp != NULL)
	{
		if (temp->isbn == isb)
		{
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}
//Function for searching a book by title
void searchByTitle(bookPtr temp)
{
	string tit;

	cout << "Enter Book Title: ";
	cin.ignore(500, '\n');
	getline(cin, tit, '\n');

	while (temp != NULL)
	{
		if (tit == temp->title)
		{
			cout << temp->title << "\n";
			cout << temp->author << "\n";
			cout << temp->publisher << "\n";
			cout << temp->pubYear << "\n";
			cout << temp->isbn << "\n\n";
		}
		temp = temp->next;
	}
	cout << "\n";
}
//Function for Printing book details
void printBookList(bookPtr temp)
{
	while (temp != NULL)
	{
		cout << temp->title << "\n";
		cout << temp->author << "\n";
		cout << temp->publisher << "\n";
		cout << temp->pubYear << "\n";
		cout << temp->isbn << "\n\n";
		temp = temp->next;
	}
	//cout << "\n";
}
//Function for printing details by author
void printListByAuthor(bookPtr temp)
{
	string autr;

	cout << "Enter Author Name: ";
	cin.ignore(500, '\n');
	getline(cin, autr, '\n');

	while (temp != NULL)
	{
		if (temp->author == autr)
		{
			cout << temp->title << "\n";
			cout << temp->author << "\n";
			cout << temp->publisher << "\n";
			cout << temp->pubYear << "\n";
			cout << temp->isbn << "\n\n";
		}
		temp = temp->next;
	}
	cout << "\n";
}
//Function for saving the data into file
void saveIntoFile(bookPtr temp)
{
	int count = countNodes(temp);
	ofstream outFile("books.txt", ios::out);

	outFile << count << "\n";
	while (temp != NULL)
	{
		outFile << temp->title << "\n";
		outFile << temp->author << "\n";
		outFile << temp->publisher << "\n";
		outFile << temp->pubYear << "\n";
		outFile << temp->isbn << "\n";
		temp = temp->next;
	}
	cout << "\n";
}
//Function to count the total number of books
int countNodes(bookPtr temp)
{
	int countB = 0;
	while (temp != NULL)
	{
		countB++;
		temp = temp->next;
	}
	return countB;
}

//The main function
int main()
{
	int choice;
	string User;
	string password;

	do {

		system("cls");
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
				bookManagement(choice);
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
				bookManagement(choice);
				choice = 100;
			}
		}
		break;

		case 3:
		{
			system("cls");
			bookManagement(choice);
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

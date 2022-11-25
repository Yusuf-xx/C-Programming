#include <iostream>//Header Files
#include <string>
#include <stdlib.h>
#include <fstream>
using namespace std;

int Login(string& admin, string& password);
int staff(string& user, string& pass1);


// node declaration
class Node {
public:
	int ID;
	string name;
	string publisherName;
	double price;	// data
	Node*	next;

	Node(int _ID, string _name, string _publisherName, double _price) {

		_ID = ID;
		_name = name;
		_publisherName = publisherName;
		_price = price;
	}	// pointer to next node
};

//Class Queue
class queue {
public:
	Node *backPtr = NULL, *frontPtr = NULL;

	void enQueue(int _ID, string _name, string _publisherName, double _price);
	void deQueue();
	void DisplayList();
	void searchByTitle();
	void printListByAuthor();
	void printBookList();
	void bookManagement(int input);
};

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


//EnQueue Function
void queue::enQueue(int _ID, string _name, string _publisherName, double _price) {

	Node *newPtr = new	Node(_ID, _name, _publisherName, _price);
	newPtr->ID = _ID;
	newPtr->name = _name;
	newPtr->price = _price;
	newPtr->publisherName = _publisherName;

	if (frontPtr == NULL) {

		newPtr->next = NULL;
		frontPtr = backPtr = newPtr;
	}

	else {

		newPtr->next = NULL;
		backPtr->next = newPtr;
		backPtr = newPtr;
	}
}


//DeQueue Function
void queue::deQueue() {
	if (frontPtr == NULL) cout << "Queue is empty";
	else {
		Node *temp = frontPtr;
		frontPtr = frontPtr->next;
		temp->next = NULL;
		delete temp;
	}

}

//Display Function
void queue::DisplayList() {

	if (frontPtr == NULL)
		cout << "Queue is Empty" << endl;
	else
	{
			//cout<<"Book ID\t\t"<<"Book Name \t\t\t"<<"Author Name\t\t"<<"Price"<<endl;
		Node *temp = frontPtr;
		while (temp->next != NULL) {
			
			cout <<"Book Code: "<< temp->ID<<endl<<"Book Title: "<<temp->name<<endl<<"Author's Name: "<< temp->publisherName<<endl<<"Book Price: "<<temp->price<<endl<<endl;

			temp = temp->next;
		}
			
						cout <<"Book Code: "<< temp->ID<<endl<<"Book Title: "<<temp->name<<endl<<"Author's Name: "<< temp->publisherName<<endl<<"Book Price: "<<temp->price<<endl<<endl;
	}
}

//Function for searching by title
void queue::searchByTitle() {
	string _title;

	cout << "Enter the title: ";
	cin.ignore(500, '\n');
	getline(cin,_title);
	Node *currNode = frontPtr;
	while (currNode) {
		

		if (_title == currNode->name) {
		
					cout <<"Book Code: "<< currNode->ID<<endl<<"Book Title: "<<currNode->name<<endl<<"Author's Name: "<< currNode->publisherName<<endl<<"Book Price: "<<currNode->price<<endl<<endl;
			
		}
		currNode = currNode->next;
		
	}
	
}


//Bookmanagement Function
void queue::bookManagement(int input)
{
	int choice, x;
	int _id;
	string _name;
	string _publisherName;
	double _price;
	int _id2;
	string _name2;
	string _publisherName2;
	double _price2;
				
				

	while (1) {

		if (input == 1) {
			//Options for admins
			cout << "Select your option\n\n";
			cout << "1. Add a new book to the list\n";
			cout << "2. De-Queue a book from the list\n";
			cout << "3. Search for a book by Title\n";
			cout << "4. List all books\n";
		
			cout << "5. Back\n\n";

			do {
				cout << "Enter your choice => ";

				cin >> choice;

			} while ((choice < 1 || choice > 5) && cout << "Invalid Input!\n");

			switch (choice)
			{
			case 1:
				system("cls");
				cout<<"Book Code: ";
				cin>>_id;
				cout<<"Book Title: ";
				cin.ignore(500, '\n');
				getline(cin,_name);
				cout<<"Author's Name: ";
				getline(cin,_publisherName);
				cout<<"Book Price: ";
				cin>>_price;
				
				enQueue(_id,_name,_publisherName,_price);
				break;
			case 2:
				system("cls");
				deQueue();
				break;
			case 3:
				system("cls");
				searchByTitle();
				break;
			
			case 4:
				system("cls");
				DisplayList();
				break;
			
			case 5:
				return;
			}

		}

		else if (input == 2) {
			//Options for staffs
			cout << "Select your option\n\n";
			cout << "1. Add a new book to the list\n";
			cout << "2. DeQueue a book \n";
			cout << "3. Back\n\n";
			do {
				cout << "Enter your choice => ";

				cin >> choice;

			} while ((choice < 1 || choice > 3) && cout << "Invalid Input!\n");


			switch (choice)
			{
			case 1:
				system("cls");
				system("cls");
				cout<<"Book Code: ";
				cin>>_id2;
				cout<<"Book Title: ";
				cin.ignore(500, '\n');
				getline(cin,_name2);
				cout<<"Author's Name: ";
				getline(cin,_publisherName2);
				cout<<"Book Price: ";
				cin>>_price2;
				
				enQueue(_id2,_name2,_publisherName2,_price2);
				break;
			case 2:
				system("cls");
				deQueue();
				break;
		
			case 3:
				return;
			}
		}

		else if (input == 3) {
			//Options for customers
			cout << "Select your option\n\n";
			cout << "1. Search for a book by Title\n";
			cout << "2. List all books\n";
			cout << "3. Back\n\n";
			do {
				cout << "Enter your choice => ";

				cin >> choice;

			} while ((choice < 1 || choice > 3) && cout << "Invalid Input!\n");


			switch (choice)
			{
			case 1:
				system("cls");
				searchByTitle();
				break;
			case 2:
				system("cls");
				DisplayList();
				break;
			case 3:
				return;
			}
		}
		

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

int main()
{	

    queue myQueue ;
	myQueue.enQueue(101,"Data Structure","Dr Nor Bahiah", 26.00);
	myQueue.enQueue(102,"Computer Organization"," Dr Abd Samad ", 36.00);
	myQueue.enQueue(103,"HumanComputerInteraction","Dr Sarina", 32.00);
	myQueue.enQueue(104,"Database","Dr wani Zakaria", 20.00);
	myQueue.enQueue(105,"Discrete Structure"," Dr Eyla Yusuf", 26.00);
	
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
				myQueue.bookManagement(choice);
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
				myQueue.bookManagement(choice);
				choice = 100;
			}
		}
		break;

		case 3:
		{
			system("cls");
			myQueue.bookManagement(choice);
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



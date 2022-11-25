#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

ofstream coutt;

class MemberRegister{
	private:
		string name;
		double income;
	public:
		MemberRegister(string _name="", double inc=0)
		{
			string name = _name;
			income = inc;
		}
		void setName(string _name)
		{
			name = _name;
		}
		string getName()
		{
			return name;
		}
		void setCategory(double money)
		{
			income = money;
		}
		double getCategory()
		{
			return income;
		}
		
		virtual void print()
		{
			cout << "NAME OF CUSTOMER : " << getName() << endl;
			cout << "CUSTOMER'S INCOME: RM " << getCategory() << endl; 
		}
};
class Discount{
	private:
		double percent;
	public:
		void setRate(double p)
		{
			percent = p;
		}
		
};

class ItemsLimitation
{
	private:
		int amount;
		string item;
		double price;
		string name;
		
	public:
		ItemsLimitation(string _item="")
		{
			item = _item;
			 
		}
		void read(int quan=0, string i="", double p=0, string nameI="") 
		{
			amount = quan;
			item = i;
			price = p;
			name = nameI;
		}
		string getName()
		{
			return item;
		}

		int getAmount()
		{
			return amount;
		}

		double getPrice()
		{
			return price;
		}
		friend ostream &operator<<( ostream &out, const ItemsLimitation &obj) 
		{ 
         out<< left<<setw(20)<< obj.item<< setw(20) << obj.name << setw(20) << obj.price << setw(20) << obj.amount<< setw(20) << obj.price*obj.amount << setw(20);
         return out;            
     	}
};
class Person{
	private:
		string namee;
	public:
		Person(string n)
		{
			namee=n;
		}
		void setPerson(string n="")
		{
			namee = n;
		}
		string getPerson()
		{
			return namee;
		}
		virtual void displayName(){}
};

class Customer : public Person
{
	protected:
		string name;
		ItemsLimitation item;
		MemberRegister *_register;
		
	public:
		Customer(string n=""):Person(n)
		{
			name = n;
		}
		string getName()
		{
			return name;
		}
		void setName(string _name)
		{
			name = _name;
		}
		
		void regMember(MemberRegister *mem)
		{
			_register = mem;
		}
		void displayName()
		{
			coutt<<"Customer's name: "<<name<<endl;
		}
		virtual double getRate(){}
		virtual void setRate(double x){}
};

class NormalMember : public Customer 
{
	protected:
		Discount rate;
		double ratePrice;
	public:
		NormalMember(){}
		NormalMember(string n): Customer(n)
		{}
		void setRate(double percentage)
		{
			rate.setRate(percentage);
			ratePrice = percentage;
		}
		
		double getRate()
		{
			return ratePrice;
		}
};

class SpecialMember : public Customer
{
	protected:
		Discount rate;
		double ratePrice;
	public:
		SpecialMember() {}
		SpecialMember(string n): Customer(n)
		{}
		void setRate(double percentage)
		{
			rate.setRate(percentage);
			ratePrice = percentage;
		}
		
		double getRate()
		{
			return ratePrice;
		}
};

int main()
{
	ItemsLimitation items[50];
	Customer cus;
	SpecialMember type1;
	NormalMember type2;
	Customer *p;
	Person *n;
	coutt.open("Receipt.txt");
	string name, id, nameItem;
	int menu, quantity, count=0, MAX=1;
	char input , type, regis, choice, reask , reaskk , add ;
	double price, income, sum, totalP=0;
	
	b:
	cout << "*  SUPERMARKET MANAGEMENT SYSTEM  *" << endl;
	cout << "============================================" << endl << endl;
	
	cout << "Enter customer's name: ";
	getline(cin,name);
	cus.setName(name);
	
	s:
	cout << "\n\n~Member verification~" << endl << endl;
	x:
	cout << "Are you a" << endl << endl;
	cout << "	~Non-member     (O) " << endl;
	cout << "	~Normal member  (N) " << endl;
	cout << "	~Special member (S) " << endl;
	cout << "==> " ;
	cin >> choice;
	cin.ignore();
	if (choice == 'N' || choice == 'S' || choice == 'n' || choice == 's')
	{
		
		if (choice=='S' || choice == 's')
		{
			SpecialMember(name);
			p=&type1;
			p->setRate(0.5);
		}
		else if(choice == 'N' || choice == 'n')
		{
			NormalMember(name);
			p=&type2;
			p->setRate(0.25);	
		}
		else
		{
			cout << "Error: " << endl; 
			cout << "Incorrect input! Please try again." << endl << endl;
			goto x;
		}
		
		goto d;
	}
	
	else if (choice == 'O' || choice == 'o')
	{
		y:
		cout << "\nYou are not a member yet." << endl;
		cout << "Don't miss the chance to get huge deals while shopping!" << endl;
		cout << "Do you want to apply for our membership? (Y | N)" << endl;
		cout << "==> ";
		cin >> type;
		
		if(type == 'Y' || type == 'y')
		{
			z:
			cout << "\nDo you wish to apply for a " << endl << endl;
			cout << "	~Normal membership  (N) " << endl;
			cout << "	~Special membership (S) " << endl;
			cout << "==> "; 
			cin >> regis;

				if(regis=='S' || regis == 's')
				{
				cout << "\n******" << endl;
				cout << "       SPECIAL MEMBER REGISTRATION      " << endl;
				cout << "******" << endl << endl;
				cout << "Monthly household income: RM ";
				cin >> income;
								
				if(income > 3500)
				{
					cout << "\nSorry. You are not applicable for this membership." << endl;
					cout << "Do you still want to register as a normal member? ( Y | N )" << endl; ;
					cout << "==> " ;
					cin >> reask;
					if(reask=='Y' || reask == 'y')
					{
						goto m;
					}
					
					if(reask=='N' || reask == 'n')
					{
						cout << "\n--Registration unsuccessful--" << endl;
						goto d;
					}
				}
				p:
				MemberRegister *mem = new MemberRegister(name, income);
				cus.regMember(mem);
				p=&type1;
				p->setRate(0.5);
				//cout <<" type 1: " << p->getRate();
				cout<<"\n\n-- You have been registered as one of our special members! --\n\n";
				}
			
				else if(regis=='n'||regis=='N')
				{
				cout << "\n******" << endl;
				cout << "       NORMAL MEMBER REGISTRATION       " << endl;
				cout << "******" << endl << endl;
				cout << "Monthly household income: RM ";
				cin >> income;
				
				if(income < 3500)
				{
					cout << "\nYou are applicable to become a special member." << endl;
					cout << "Do you want to register as a special member instead? ( Y | N )" << endl;
					cout << "==> " ;
					cin >> reaskk;
					if(reaskk=='Y' || reaskk == 'y')
					{
						goto p;
					}
				}
				m:
				MemberRegister *mem = new MemberRegister(name, income);
				cus.regMember(mem);
				p=&type2;
				p->setRate(0.25);
				//cout <<" type 2: " << p->getRate();
				cout<<"\n\n-- You have been registered as one of our normal members! --\n\n";
				}
			
				else
				{
					cout << "\nError: " << endl; 
					cout << "Incorrect input! Please try again." << endl << endl;
					goto z;
				}
			}
		
			else if(type=='N' || type=='n')
			cus.setName(name);
			
			else
			{
				cout << "\nError: " << endl; 
				cout << "Incorrect input! Please try again." << endl << endl;
				goto y;
			}
		goto d;	
	
	}
	
	else
	{
		cout << "\nError: " << endl; 
		cout << "Incorrect input! Please try again." << endl << endl;
	}
	goto x;
	
	d://menu

	cout << "\nMENU" << endl;
	cout << "	1) Place order" << endl;
	cout << "	2) Receipt" << endl;
	cout << "	3) Exit" << endl<<endl;
	cout << "Please enter the required option: ";
	cin >> menu;
	
	switch(menu)
	{
		case 1:
			cout << "\n~Checking out items~" << endl;
			
			for(int i =0; i<MAX+i; i++)
			{
				
				cout << "\n#" << count + 1 << endl;
				cout << "Enter product's id       : ";
				cin.ignore();				
				getline(cin ,id);

				cout << "Enter product's name     : ";
				getline(cin, nameItem);
	
				cout << "Enter product's price    : RM ";
				cin >> price;

				cout << "Enter quantity in number : " ;
				cin >> quantity;
				try 
				{
					if(quantity>3)
						throw "\n--Sorry. Maximum 3 only per item--";
				}
				catch(const char *msg)
				{
					cout << msg << endl;
					quantity = 3;
				}
				
				items[i].read(quantity,id,price,nameItem);
				
				count++;
				
				cout << "\nDo you want to add another product? (Y/N)" << endl;
				cout << "==> ";
				cin >> input;
				if(input=='N'||input=='n')
				{
					goto d;
				}
			}
				
			break;
			
		case 2: 
			cout<< "\n~~ Printing receipt onto output file ~~"<<endl;
			cout << endl << endl;
			coutt << "\n** RECEIPT ** " << endl << endl;
			n=&cus;
			n->displayName();
			coutt << endl;
			coutt << fixed << setprecision(2);
			coutt << left<<setw(20)<<"ITEM'S ID"<<setw(20)<< "ITEM'S NAME"
				 <<setw(20) << "PRICE(RM)" <<setw(20)<< "QUANTITY" <<setw(20)
				 << "TOTAL PRICE(RM)" <<setw(20)<< "TOTAL PRICE AFTER DISCOUNT(RM)" << endl;
			for(int i=0; i< count; i++)
			{
				coutt<<items[i];
				double total = items[i].getPrice()*items[i].getAmount();
				
				if	(choice == 'S'||choice == 's' || choice == 'N'|| choice =='n'|| reaskk=='Y'|| reaskk == 'y' || reaskk == 'N'|| reaskk =='n'|| type != 'N' && type != 'n' && reask != 'N' && reask != 'n') 
				{
					sum = (total)-(total*p->getRate());
					coutt << sum << endl;
					totalP += sum;
				}					
				else 
				{
					totalP += total;
					coutt << total << endl;
				}
				
			}
				
			coutt << endl << endl;
			count = 0;
			coutt<<" * Your Total Bill= RM "<< totalP <<" *"<<endl<<endl;
			for(int i=0;i<130;i++)
			coutt<<"+";
			coutt<<endl;
			cout<<"Add customer? (Y | N) : ";
			cin>> add;
			cin.ignore();
			if (add=='Y'|| add=='y')
			{			
			totalP = 0;
			sum = 0;
			system("pause");
			system("CLS");
			goto b;
			}
			else
			goto d;

			break;
			
		case 3:
			cout << "\nThank you and stay safe!" << endl << endl;
			exit(1);
			
			break;
		
		default:
				cout << "Incorrect input!" << endl << endl;
				goto d;
	}
	coutt.close();
	return 0;
}

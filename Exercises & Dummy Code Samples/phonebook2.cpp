#include <iostream>
#include <vector>
#include <stdio.h>
#include <windows.h>

using namespace std;

class Contact
	{
		//Members:
		private: string Name;
		private: unsigned int Age;
		private: unsigned int phonenumber;
		private: unsigned int index;

		//Constructor 1
		public: Contact (string newname, unsigned int phnumber, unsigned int newindex, unsigned int newage)
		{
			Name = newname;
			Age = newage;
			phonenumber = phnumber;
			index = newindex;
		}
		//Constructor 2
		public: Contact (string newname, unsigned int phnumber, unsigned int newindex)
		{
			Name = newname;
			phonenumber = phnumber;
			index = newindex;
			Age=0;
		}
		//Function:
		public: void PrintContact()
		{
			cout <<endl << index << " .Name: " << Name << "	Phone Number: " << phonenumber ;
			if(Age == 0)
			{
				cout << "   Age: uninitialized\n" << endl;
			}
			else
			{
				cout << "   Age: " << Age << endl << endl;
			}
		}
		//Getters:
		public: unsigned int GetIndex()
		{
			return index;
		}
		public: string GetName()
		{
			return Name;
		}
		public: unsigned int GetPhoneNumber()
		{
			return phonenumber;
		}
		public: unsigned int GetAge()
		{
			return Age;
		}
		//Setters:
		public: void SetName(string newname)
		{
			Name=newname;
		}
		public: void SetPhoneNumber(unsigned int newPhoneNumber)
		{
			phonenumber = newPhoneNumber;
		}
		public: void SetAge(unsigned int newAge)
		{
			Age = newAge;
		}
	};

void CreateContact();
void DisplayAllContacts();
unsigned int GetContactEditIndex ();
void ModifyContact (unsigned int index);
vector <Contact> phonebook;
int main(int args, char** argv)
{
			unsigned int menuChoice;
			char answear = 'Y';

			phonebook.push_back( Contact ("Adam", 82223412, phonebook.size()));
			while(answear=='Y' || answear=='y')
			{
			    system("CLS");
				cout<<"\nMENU: \n\n1.Add New Contact\n2.Edit Existing Contact\n3.Display Phonebook\n4.Quit" << endl;
				cin >> menuChoice;
				while(menuChoice<1 && menuChoice>4)
				{
					cout  << "Wrong Option! Please answear again: ";
					cin >> menuChoice;
				}
				if (menuChoice==1)
				{
					CreateContact();
					cout << "\nThe new phonebook looks like this: " << endl;
					DisplayAllContacts();
				}
				else if (menuChoice==2)
				{
					ModifyContact(GetContactEditIndex());
				}
				else if(menuChoice==3)
				{
					DisplayAllContacts();
				}
				cout << "Do you wish to do something else? Press Y for yes! Press anything else to quit!" << endl;
				cin >> answear;
			}
			cout << "Press any key to continue . . . " << endl;
			int a;
			cin >> a;
    }
void CreateContact()
		{
			cout<<"\nEnter the contact details: \n"<< endl;
			string local_name;
			unsigned int local_phoneNumber;
			char answear = 'c';
			cout<<"Name: ";
			cin >>local_name;
			cout<< endl <<"Phone Number: ";
			cin>>local_phoneNumber;
			cout<< endl <<"Do you wish to add an Age to your contact?"<<endl;
			while(answear!='Y' && answear!='N' && answear!='y' && answear!='n')
			{
				cout<<"\nAnswear with Y/N:";
				cin>>answear;
				if(answear=='Y' || answear=='y')
				{
					unsigned int local_age;
					cout<<"\nEnter the Age: ";
					cin>>local_age;
					phonebook.push_back(Contact(local_name, local_phoneNumber, phonebook.size(), local_age));
				}
				else if(answear=='N'|| answear=='n')
				{
					phonebook.push_back(Contact(local_name, local_phoneNumber, phonebook.size()));
				}
			}
		}
void DisplayAllContacts()
		{
			for (int i=0;i<phonebook.size();i++)
			{
				phonebook[i].PrintContact();
			}
		}
unsigned int GetContactEditIndex ()
		{
			unsigned int index;
			cout<<"\nEnter the index of the element you would like to Modify: ";
			cin>>index;
			if(index<0 || index>phonebook.size()-1)
			{
				cout<<"Invalid index! There is no such element in the Phonebook!"<<endl;
				while(index<0 || index>phonebook.size()-1) // phonebook.size()-1 because the index starts from zero, and the number of elements
					//starts from 1.
				{
					cout << "Enter a valid index!" << endl;
					cin >> index;
				}

			}
			return index;
		}
void ModifyContact (unsigned int index)
		{
			for(int i=0; i<phonebook.size(); i++)
			{
				if(phonebook[i].GetIndex() == index)
				{
					char answear;
					cout<<"\nContact name is: " << phonebook[i].GetName() << endl;
					cout<<"Do you wish to change it? Press Y for yes! Anything else to skip!"<<endl;
					cin>>answear;
					if(answear == 'Y' || answear == 'y')
					{
						string name;
						cout<<"\nEnter the new name: ";
						cin>>name;
						phonebook[i].SetName(name);
					}
					cout<<"\nContact number is: " << phonebook[i].GetPhoneNumber() <<endl;
					cout<<"Do you wish to change it? Press Y for yes! Anything else to skip!"<<endl;
					cin>>answear;
					if(answear == 'Y' || answear == 'y')
					{
						unsigned int newPhoneNumber;
						cout<<"\nEnter the new phone number: ";
						cin>>newPhoneNumber;
						phonebook[i].SetPhoneNumber(newPhoneNumber);
					}
					cout <<"\nContact age is: " << phonebook[i].GetAge() << endl;
					cout << "Do you wish to change it? Press Y for yes! Anything else to skip!" << endl;
					cin >> answear ;
					if(answear == 'Y' || answear == 'y')
					{
						unsigned int newAge;
						cout <<  "\nEnter the new age: ";
						cin >> newAge;
						phonebook[i].SetAge(newAge);
					}

				}


			}
        }

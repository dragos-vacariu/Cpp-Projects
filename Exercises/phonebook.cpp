#include <iostream>
#include <vector>
#include <stdio.h>
#include <windows.h>
#include <fstream>

#define FILE "phonebook.dat"

using namespace std;

class Contact
{
    //Members:
    private: string Name;
    private: unsigned int Age;
    private: string phonenumber;
    private: unsigned int index;

    //Constructor 1
    public: Contact (string newname, string phnumber, unsigned int newindex, unsigned int newage)
    {
        Name = newname;
        Age = newage;
        phonenumber = phnumber;
        index = newindex;
    }
    //Constructor 2
    public: Contact (string newname, string phnumber, unsigned int newindex)
    {
        Name = newname;
        phonenumber = phnumber;
        index = newindex;
        Age = 0;
    }
    public: Contact ()
    {
    }
    //Functions / Methods:
    public: void PrintContact()
    {
        cout << endl << "Crt.\tName:\t\tPhone Number:\t\tAge:" << endl ;
        cout << endl << index << ". \t" << this->Name << "\t\t" << this->phonenumber << "\t\t" << this->Age << endl;
        //in C++ 'this' is a pointer and has to be accessed via -> operator
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
    public: string GetPhoneNumber()
    {
        return phonenumber;
    }
    public: unsigned int GetAge()
    {
        return Age;
    }
    //Setters :
    public: void SetName(string newname)
    {
        Name = newname;
    }
    public: void SetPhoneNumber(string newPhoneNumber)
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
int saveVectorToBinaryFile(vector <Contact> phBook);
int readVectorFromBinaryFile(vector <Contact> phBook);

vector <Contact> phonebook;

/*
vector is a generic class - so the data type to be used has to be mentioned between <.>
*/

int main(int args, char** argv) // Parameters : int args, char** argv are used in case we want to pass arguments from Console CMD to this program
{
    unsigned int menuChoice;
    char answear = 'Y';
    while(answear=='Y' || answear=='y')
    {
        system("CLS"); // this clears the console
        cout << "\nMENU: \n\n1.Add New Contact\n2.Edit Existing Contact\n3.Display Phonebook\n4.Quit" << endl;
        cin >> menuChoice;
        while(menuChoice<1 && menuChoice>4)
        {
            cout  << "Wrong Option! Please answer again: ";
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
    return 0;
}

void CreateContact()
{
    cout << "\nEnter the contact details: \n"<< endl;
    string local_name;
    string local_phoneNumber;
    unsigned int local_age;

    cout << "Name: ";
    cin.clear();
    fflush(stdin);
    getline(cin, local_name);

    cout << endl << "Phone Number: ";
    cin.clear();
    fflush(stdin);
    getline(cin, local_phoneNumber);

    cout << endl << "Age: ";
    cin.clear();
    fflush(stdin);
    cin >> local_age;

    phonebook.push_back(Contact(local_name, local_phoneNumber, phonebook.size(), local_age));
}
void DisplayAllContacts()
{
    for (int i=0 ; i<phonebook.size(); i++)
    {
        phonebook[i].PrintContact();
    }
}
unsigned int GetContactEditIndex ()
{
    unsigned int index;
    DisplayAllContacts();
    cout << "\n\nEnter the index of the element you would like to Modify: ";
    cin >> index;
    if(index<0 || index>phonebook.size()-1)
    {
        cout << "Invalid index!" << endl;
        while(index<0 || index>phonebook.size()-1) // phonebook.size()-1 because the index starts from zero, and the number of elements
            //starts from 1.
        {
            cout << "Enter a valid index: " << endl;
            cin.clear();
            fflush(stdin);
            cin >> index;
        }

    }
    return index;
}
void ModifyContact (unsigned int index)
{
    char answer;
    cout << "1. Modify Name" <<  endl;
    cout << "2. Modify PhoneNumber" <<  endl;
    cout << "3. Modify Age" <<  endl;

    while(answer < '1' || answer > '3')
    {
        cout << "\nInput: " << endl;
        cin.clear();
        fflush(stdin);
        cin >> answer;
        if(answer == '1')
        {
            string name;
            cout << "\nEnter the new name: ";
            cin.clear();
            fflush(stdin);
            getline(cin, name);
            phonebook.at(index).SetName(name);
        }
        else if(answer == '2')
        {
            string newPhoneNumber;
            cout << "\nEnter the new phone number: ";
            cin.clear();
            fflush(stdin);
            getline(cin, newPhoneNumber);
            phonebook.at(index).SetPhoneNumber(newPhoneNumber);
        }
        else if(answer == '3')
        {
            unsigned int newAge;
            cout <<  "\nEnter the new age: ";
            cin.clear();
            fflush(stdin);
            cin >> newAge;
            phonebook.at(index).SetAge(newAge);
        }
        else
        {
            cout << "Option not available. " << endl;
        }
    }
}

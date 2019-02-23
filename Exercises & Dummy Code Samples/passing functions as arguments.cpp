#include <iostream>
#include <conio.h>

using namespace std;

void getUserName(string&); //string passed by reference
//reference is usually used when modifying a value for a certain variable;
void printResults(string, int);
int getUserScore(); //returns an integer;
//to pass a function as argument, the function must return  a value;

int main()
{
    string name;
    getUserName(name);
    printResults(name, getUserScore()); //passing function as argument

    getch();
    return 0;
}

void getUserName(string& username)
{
    cout << "Enter your name: ";
    cin >> username;
}
void printResults(string username, int score)
{
    if (score>70)
    {
        cout << username << " is in good mood!" << endl;
    }
    else if(score>100)
    {
        cout << "You have entered a wrong value, " << username << endl;
    }
    else
    {
        cout << username << ", this is your score: " << score << endl;
    }
}
int getUserScore()
{
    int Score;
    cout << "Enter your score: ";
    cin >> Score;
    return Score;
}

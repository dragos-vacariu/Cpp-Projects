#include <iostream>
#include <conio.h>

using namespace std;

void incrementationPassedByValue (int);
void incrementationPassedByReference (int&); //only for c++

int main()
{
    auto num1=1; //using auto to create integers;
    cout << "Enter the value for the number 1: ";
    cin >> num1;
    incrementationPassedByValue(num1);
    cout << "By value: " << num1 << endl;
    incrementationPassedByReference(num1);
    cout << "By reference: " << num1 << endl;

    getch();
    return 0;
}

void incrementationPassedByValue(int x)
{
    x+=5;
}
void incrementationPassedByReference(int& x) //only for c++;
{
    x+=5;
}

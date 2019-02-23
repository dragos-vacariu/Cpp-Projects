#include <iostream>
#include <conio.h>

using namespace std;

void printStuff(int number);

/*
A recursion can cause stack overflow, which will crash the program. The fact is the a recursive function returns only when,
each call of the same function ends, if they are too many the stack memory which is a few megabytes, will fill until succeeds
its size, so the stack will overflow.

NOTE: recursion is significantly slower than a simple loop.

Recursion is very useful in creating AI (artificial intelligence), for example recursion could be used in a chess game
to make the CPU look few moves ahead to see how the board could look like.
*/

int main()
{
    int n;
    cout << "Enter a value for recursion: " << endl;
    if(!(cin >> n))
    {
        cout << "You entered a bad integer value: " << endl;
        cin.ignore(999, '\n'); //ignore 999 character until the new line;
        cin.clear(); //clear the buffer of the cin function;
    }
    printStuff(n);
    getch();
    return 0;
}
void printStuff(int number)
{
    if(number==0) //this is one base condition for recursion;
        return; //this is how to return from void
    cout << "stuff" << number << endl;
    printStuff(number-1); //this is the recursion, the act of calling a function inside the same function.
}

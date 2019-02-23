#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    int a;
    while(true) //this loop will handle the cin fail, if a letter is stored into an integer variable.
    {
        cout << "Enter a letter: " << endl; //entering a letter will make this program crash, because cin can't handle
        //inputting a letter into an int.

       // cin >> a; //input can be either done here or in the if statement.

        if(!(cin >> a)) //if the input is done above, this cin is just for checking, otherwise the input will be here.
        {
            cerr << "Bad input for the integer data type: " << endl; //print this error message.
            cin.clear(); //clear the buffer.
            cin.ignore(9999, '\n'); //ignore all the characters until the newline
            //9999 - is a abstract value refering to the number of character of a line.
        }

    }

    getch();
    return 0;
}

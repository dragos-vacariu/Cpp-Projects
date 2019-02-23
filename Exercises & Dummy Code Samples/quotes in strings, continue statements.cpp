#include <iostream>
#include <conio.h>

using namespace std;
int main()
{
    /*to post quotation mark inside a string a backslash must be used in front of it.
    the backslash used in front of a letter specifies that the letter it will be
    used as a character. */
    string quotstring ="The weatherman says: \"It will be raining tonight.\"";
    cout << quotstring << endl;

    //Continue statement;
    cout << "\n\nContinue Statement.\n\n";
    for (int i=0; i<5; i++)
    {
        cout << i << " Before the continue statement!" << endl; //this is executed each iteration;
        if(i>1&&i<4)
        {
            continue; //the continue statement will skip to the next iteration,
            //ignoring the rest of the statements in the loop;
        }
        cout << i <<" After continue statement!" << endl; //this is executed only
        //when the if is not true, so the continue statement won't run.
    }

    getch();
    return 0;
}

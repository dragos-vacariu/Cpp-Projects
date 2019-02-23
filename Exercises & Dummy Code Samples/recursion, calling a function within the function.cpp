#include <iostream>
#include <conio.h>

using namespace std;

/*Recursion is the act of calling a function within the same function. Recursion is a way of solving a problem
by splitting it into smaller problems.
Recursion is dangerous because it creates a whole bunch of variables which will not be ended until the program or task, is
ended.
If recursion is not made correctly it can cause application crashes.

Recursion is like a tree: function_call_1 -> function_call_2 -> function_call_3 -> function_call_4 , so the task will
be completed after the last function return a value (or ends if it void function), so when function_call_4 ends, the software
will resume back to function_call_3 then to function_call_2 and then to function_call_1 etc.

Recursion is mainly used when it's necessary to create a stack (with values or variables). Otherwise a loop could be more
efficient.
*/
void recursiveFunc (int);
void reverseRecursiveFunc (int);
void BADrecursiveFunc(int); //function that exemplifies how recursion can cause crashes (mistakes in recursion).

int main()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;
    recursiveFunc(number); //calling the recursive function;
    cout << endl << "Returned to main function: " << endl;
    reverseRecursiveFunc(number);
    getch();
    return 0;
}

void recursiveFunc (int numbPass)
{
    if(numbPass>=1)
    {
        cout << "Number is: " << numbPass << endl;
        recursiveFunc(numbPass-1); //calling the function inside the function;
    }
    cout << "Note that this is printed after the last function call does its job." << endl;
}

void BADrecursiveFunc(int badNumbPass)
{
    if(badNumbPass>=1)
    {
        cout << "Number is: " << badNumbPass << endl;
        BADrecursiveFunc(badNumbPass);
        /*this will crash the software with 2 big errors
            1. The task will never be ended (because it will never be completed, infinite loop).
            2. Recursion created a whole stack of variables, that will not die until the function ends (in our case
                this is never).
        */
    }
}
void reverseRecursiveFunc(int numbPass)
{
    if(numbPass>=1)
    {
        //See how changing these 2 statements between each other, change the order in which the numbers are printed
        reverseRecursiveFunc(numbPass-1); //calling the function inside the function;
        cout << "Number is: " << numbPass << endl; // printing the number;
    }
}

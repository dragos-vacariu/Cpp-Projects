#include <iostream>
#include <conio.h>

using namespace std;
//GLOBALS
int cat =10; //Global variables are always stored on the heap...

void PrintCat();

int main()
{
    //Between these brackets the int Local variable has it's own scope, and it's scope it ONLY inside the brackets;
    {
        int Local=-1;
    }
    /*Right here the scope of int Local ends, and the variable dies.
    cout << Local << endl; //Local is not declared to be used outside the brackets.

    By default the scope is set for the closest variable. That's why when we try to print cat below, it will be printed
    the variable cat, from int main.

    To set the scope to a certain global variable the :: operator (also called unary scope resolution operator) can be used
    such us:
    ::cat=5;

    */

    int cat;
    cat=5; //this will make the variable cat from int main be equal to 5.
    ::cat=50; //this will make the global variable cat be equal to 50.

    cout << cat << endl; //this will print the local variable cat, declared in int main(), because it's scope it's local, and
    //overwrites the global one.
    PrintCat(); //this will print the global variable, because there is no other variable with a scope in the PrintCat function.

    {
        int cat = -2; //Note that now we have 3 variables with the same name, but totally different scopes;
        cout << cat << endl; //cat is only available inside these brackets.

        /*Similar in loops, if statements and switch statements a variable can be declared... and will have just the
        same effect, it will immediately die before the loop, or if, or switch etc. */
    }

    getch();
    return 0;
}

void PrintCat()
{
    cout << cat << endl;
}

#include <iostream>
#include <conio.h>

using namespace std;

int* BadPointer()
{
    int a=100; //local variables should not have a pointer.
    return &a; //this is the way of returning a pointer;
}
void Example(string message)
{
    cout << message << endl;
}
int* GoodPointer();

int main()
{
    int *p;
    cout << "THIS IS THE BAD WAY: " << endl;
    p=BadPointer(); //at this pointer the function has ended and the variable this pointer if pointing to, has died.
    //so we could now print on the screen, some weird stuff.
    cout << *p << endl; //no that it is not a weird value, it's exact the same value, but that's because even if the
    //variable has died, its value has not been changed.
    Example("The stack memory for the function above is new reused by this function.");
    //Note that: the value the pointer is pointing to, is no longer 100. That's because now the dead variable's memory
    //from the stack has been reused to call the Example() function;
    cout << *p << endl;
    //this is the way that a pointer should never be used. This is an often mistake, and it's usually called
    //POINTER FALL or PITFALL.

    //THIS IS THE GOOD WAY:
    cout << endl << "THIS IS THE GOOD WAY: " << endl;
    p=GoodPointer(); //getting a pointer that points to a integer value stored on the heap;
    cout << *p << endl;
    Example("Even now the value will not change either."); //this will not change the value of the pointer;
    cout << *p << endl; //the pointer still has the same value as it did before calling Example();
    //the pointer will never change;
    getch();
    return 0;
}
int* GoodPointer()
{
    int *p = new int; //this is allocated on the heap.
    *p=200;
    return p;
}

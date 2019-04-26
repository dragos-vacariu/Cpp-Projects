#include <iostream>
#include <memory> //library for shared_ptr;

//Forward declaration of a function;
void keepScreenOpened();

using namespace std;
int main()
{
    //Creating a smart shared pointer;
    shared_ptr<int> smartSharedPointer = make_shared<int>(); //equivalent to int *smartSharedPointer = new int;
    /*
    A smart pointer is a pointer that automatically deletes the memory allocated for a variable in heap, once that
    the variable is no longer used. This prevent having memory leaks;
    A memory leak is when a space that has been allocated on the heap for a certain variable, has it address connected to a
    pointer, once that pointer is gone, (set to nullptr), there is no way to delete the allocated space memory. So the
    memory gets useless until the whole program ends.
    A smart pointer is 8 times slower that a normal pointer. So it is not recommended to have many smart pointer in a program
    because it will slow it down, comparing to the classic pointers.
    */
    *smartSharedPointer=2;
    //Printing the value of the pointer;
    cout << *smartSharedPointer << endl;
    *smartSharedPointer=64;
    //Printing casted to char, the new value of the pointer;
    cout << char(*smartSharedPointer) << endl;

    //Creating smart unique pointers;
    unique_ptr<char*> uniqueSmartPointer(new char*()); //pointer to a char of pointers (just like a string);
    *uniqueSmartPointer = "Hello World!";
    unique_ptr<char> uniqueSmartPointer2(new char('C')); //pointer to a character initialized on the same row.
    //*uniqueSmartPointer2 = 'C'; //initialization on the second row.

    /*
    An unique pointer is a pointer that does not allow another pointer to point to the same address as it.
    An unique pointer is faster that a shared pointer, and dispite the thing above, it works just the same way
    as a shared pointer, preventing memory leaks, automatically deleting the allocated memory on the heap, once
    the variable is not longer used.
    */

    //Printing the pointers;
    cout << *uniqueSmartPointer << endl;
    cout << *uniqueSmartPointer2 << endl;

    //Call of a function;
    keepScreenOpened(); //using this instead of getch();

    return 0;
}
void keepScreenOpened()
{
    int PressAnyKey;
    cout << "Press any key to end!" << endl;
    cin >> PressAnyKey;
}

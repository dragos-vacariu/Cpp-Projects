#include <iostream>
#include <conio.h>
#include <vector>
#include <stdio.h>

using namespace std;

int main()
{
    vector <int> myVec;
    myVec.push_back(5);

    int *pointer=&(myVec[0]);
    for (int i = 0; i<10; i++)
    {
        cout << *pointer << endl;
        myVec.push_back(600);
        getch();
    }
    /*
    Note that when calling iterating the second time, and a new element is added to the vector, the actually memory address
    to which the pointer is pointing to, the element 0 of the vector, is freed, because, each time the vector is resized
    it's actually deleted from the heap and reallocated somewhere else still on the heap, so it can't be traced with a
    pointer.
    */

    //PRINT HEXADECIMAL NUMBERS;
    cout << hex << *pointer << endl;
    printf("%x", *pointer);

    getch();
    return 0;
}

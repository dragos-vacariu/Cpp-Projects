#include <iostream>
#include <conio.h>

using namespace std;
int main()
{
    int sizeOfArray;
    cout << "What is the size of the array?" << endl;
    cin >> sizeOfArray; //get the size.

    int *ptr;
    ptr= new int[sizeOfArray]; //creating an array of exact size specified.

    for(int i = 0; i<sizeOfArray; i++)
    {
        cout << "Value of ptr[" << i << "] = " << ptr[i] <<
            "\tThe memory address: " << (int) &ptr[i] << endl; //getting the value through which the pointer is pointing to.
        /*Note that: when the pointer is used to get to an array, there is no need of the dereference operator *, because
        the [] square brackets does the dereferentiation, in this case.

                cout << *pointer; //the way that dereferenciation works for a single integer variable.
        */
    }

    getch();
    return 0;
}

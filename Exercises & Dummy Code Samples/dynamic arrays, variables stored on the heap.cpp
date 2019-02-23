#include <iostream>
#include <conio.h>

using namespace std;
const int CAPACITY = 10;

int main()
{
    //In this way any variable can be stored on the heap
    int* dArray; //creating a pointer;
    dArray = new int [CAPACITY]; //the pointer will store the value of a dynamic array of integers with the size of CAPACITY
    //for a regular integer the sintax is: <pointer name> = new int;
    //Initializing a few elements of the array;
    dArray[0]=5;
    dArray[1]=12;
    dArray[2]=3;
    dArray[3]=14;

    cout << "The elements of the dynamic array: " << endl;
    for(int i=0; i<4; i++)
    {
        cout << dArray[i] << " "; //printing the elements of the array.
    }
    cout << endl;
    delete [] dArray; //the array is deleted, and the dynamic space is now  freed (memory deallocation).
    //for a regular integer the sintax is: delete <pointer name>;

    cout << "The elements of the dynamic array after deallocated from memory: " << endl;
    for (int i=0; i<4; i++)
    {
        cout << dArray[i] << " "; //printing all the elements of the array after deallocation.
    }
    cout << endl;

    dArray = nullptr; //good programming practice to set the array back to NULL;

    /*
    //this will crash the application because dArray no longer exists (is NULL);
    cout << "After the pointer is set to 'nullptr'!" << endl << "dArray[0]= " << dArray[0] << endl; //if dArray is NULL,
    //there is nothing to print on the screen, so the application it will crash;
    */

    getch();
    return 0;
}

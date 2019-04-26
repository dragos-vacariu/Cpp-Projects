#include <iostream>
#include <conio.h>

//Forward declaration of the function;
void fillarray(int arrayel[], int sizeArray);

using namespace std;

int main()
{
    const int arraysize = 5; //this variable holds the size of the array;
    int Elements[arraysize];
    fillarray(Elements, arraysize); //to pass an array as argument, you also need to pass its size.
    //Arrays are passed to function arguments by reference from default;
    cout << "Printing the array: " << endl << "[";
    for (int i=0;i<arraysize;i++)
    {
        cout << " " << Elements[i] << " ";
    }
    cout << "]" << endl;

    getch();
    return 0;
}
//Function implementation;
void fillarray(int arrayel[], int sizeArray)
{
    for (int i=0;i<sizeArray;i++)
    {
        cout << "element[" << i << "] = ";
        cin >> arrayel[i];
    }
}

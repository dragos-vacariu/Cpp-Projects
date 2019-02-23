#include <iostream>
#include <conio.h>

using namespace std;

void fillArray(int[], int&);
//an array is passed by reference by default, so the & sign isn't necessary.

//simple integers are not passed as reference by default, so the & is needed.

int main()
{
    int values[8];
    int numElements=0;
    fillArray(values, numElements);
    for(int i=0;i<numElements; i++)
    {
        cout << "value[" <<i << "] = "<< values[i] << endl;
    }
    getch();
    return 0;
}

void fillArray(int elements[], int& numElements)
{
    int i=0; //counter;
    int score;
    cout << "Enter the elements (or -1 to exit): " << endl;
    cin >> score; //temporary variable to store the data.
    while((score!=-1) && (i<8))
    {
        numElements++;
        elements[i]=score; //this modifies the main array that was passed to the function.
        cin >> score;
        i++;
    }
}


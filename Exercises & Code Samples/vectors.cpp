#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;

void reverseorder (vector <int>& infunction)
{
    cout << "Vector reversed: " << endl;
    for(unsigned int i=(infunction.size()-1); i>0; i--)
    {
        cout << infunction.at(i) << "  ";
    }
    cout << infunction.front() << endl;
}

int main()
{
    vector <int> myvector; //vector of size 0;
    /*
        Initializing a vector:
        vector <int> myvector(5, 0);
        -where 5 is the initial size of the vector;
        -and 0 is the initial value for all the integer elements of the vector;

        A vector of size 0 (without not elements) looks like this:
        vector <int> myvector;
    */
    myvector.push_back(3); //THIS IS ASSIGNMENT;

    cout << "Vector: " << endl;
    for (unsigned int i=0; i<5; i++)
    {
        myvector.push_back(i*5); //assignment;
    }

    for(unsigned int i=0;i<myvector.size(); i++) //vector loop;
    {
        cout << myvector.at(i) << "  "; //display the elements;
    }
    cout << endl;
    myvector.insert(myvector.begin()+3, 50); //insert a value BEFORE the specified index
    //takes 2 arguments, first is the index, second is the values;
    //vector.begin() -> return the index of the first element of the vector; (element [0]);
    //vector.erase() -> removes element at specified index;

    for(unsigned int i=0;i<myvector.size(); i++) //vector loop;
    {
        cout << myvector.at(i) << "  "; //display the elements;
    }
    cout << endl;
    myvector.erase(myvector.begin()+3); //removes the element at index [3], which is 50.

     for(unsigned int i=0;i<myvector.size(); i++) //vector loop;
    {
        cout << myvector.at(i) << "  "; //display the elements;
    }
    //Other vector function:
    //vector.clear() -> removes all the elements of the vector;
    //vector.empty() -> returns a boolean value if the vector was cleared;

    //OBS: vectors should always be passed by reference (&) as arguments to functions, because otherwise, a copy of the
    //vector would be created, so space will be allocated etc...
    cout << endl;
    reverseorder(myvector);

    getch();
    return 0;
}

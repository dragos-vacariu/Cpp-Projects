#include <iostream>
#include <conio.h>

using namespace std;

//Creating a structure;
struct Block {
    double data;
    int value;
    int func(int data)
    {
        data+=5;
        return data;
    }
};
/*
    A structure is just a block of data, and it's very similar to a class, even in accessibility.

    Difference between struct and class;
    A structure is made by default to be public, but can also be set as private. While a class is set by default to be
    private and can also be set to public or protected.

    A structure can be accessed in the same way as a class. A structure usually does not contain functions, just variables
    but it could contain both functions and variables, there are no restrictions just right in a class.

    A structure can be initialized as follows: Block DataStruct= {0, 0}; , this initialized the all two elements to 0;

    A structure can have a Constructor or Destructor which will act just like in a class.
*/

//Other way to create a struct;
typedef struct Books{
    string x;
    string y;
} book;

int main()
{
    Block DataStruct={10, 10}; //creating an object of the structure, and initializing all elements of it to 10.

    cout << DataStruct.data << endl;
    cout << DataStruct.value << endl;
    cout << DataStruct.func(50)<< endl; //calling a function from inside the struct.

    //Creating the object for the second struct.
    book bookobj ={"Deady", "Online"}; // initializing the struct.
    cout << bookobj.x << " " << bookobj.y << endl; //printing the variables.

    getch();
    return 0;
}

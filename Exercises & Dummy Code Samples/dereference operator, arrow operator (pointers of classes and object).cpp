#include <iostream>
#include <conio.h>

using namespace std;

class myclass{
public:
    string texting;
    string* mytext;
    void init()
    {
        texting="I was here";
        mytext=&texting;
    }

};

int main()
{
    //Creating an object of the class;
    myclass object;
    //Creating a pointer of the object of the class;
    myclass *pointerToClass = &object;
    //Calling the funciton;
    object.init();
    //Printing information using the object;
    cout << *(object.mytext) << endl;
    cout << object.texting << endl;
    //Printing information using the pointer;
    cout << pointerToClass->texting << endl;
    getch();
    return 0;
}

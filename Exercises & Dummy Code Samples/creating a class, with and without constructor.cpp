#include <stdio.h>

/*
The main purpose of C++ programming is to add object orientation to the C programming language and classes are the
central feature of C++ that supports object-oriented programming and are often called user-defined types.
*/

class MyClass{
private:
protected:
public:
    MyClass(int a) {}
    MyClass(){}
    void PrintMessage()
    {
        printf("Message from class member.\n");
    }
};

int main()
{
    //Creating object of the class.
    MyClass object(11); //making an instance of the class using the constructor that takes in one  argument
    MyClass obj; //making an instance of the class using the constructor that takes no arguments.
    /*Myclass object3() -> this declaration using the constructor without parameters gives an compilation error when
    calling a function related to the class. If there was no function called using that object, the program will
    compile fine.
    */
    obj.PrintMessage();
    object.PrintMessage();
    scanf("%d");
    return 0;
}

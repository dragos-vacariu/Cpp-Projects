#include <iostream>
#include <conio.h>

/*
A static class is a class that has only static member functions or variables.
NOTE: a static variable in a class, need to be declared in the header file of the class as follows:
static <type> <variable name>; Example: static int calculus, static string file, etc.

And after that needs also to be forward declared in the cpp file of the class, the place where it can be even initialized.
*/

using namespace std;
class MyClass{
    public: MyClass()
    {
    }
    static void PrintHello() //Static member functions in a class make possible the call of the function without creating
    //an object or an instance of the class. In int main there is the example.
    {
        cout << "Hello World!" << endl;
        cout << "Calling a function from inside the class without creating an object or an instance of it! " << endl;
    }
};
//For a static class isn't necessary to create an object or instance, but although those can be created just like in
//every class, but it doesn't make sense, because usually a static class contain only static functions and/or variables
//which can be accessed anywhere, where the class is included, by using the scope resolution just like in int main()l
int main()
{
    //Calling a function from inside the class without creating an object or instance for the class
    MyClass::PrintHello(); //using the scope resolution;
    getch();
    return 0;
}

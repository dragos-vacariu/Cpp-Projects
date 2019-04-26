#include <iostream>

using namespace std;

class MyClass{
    public: MyClass()
            {
                cout << "The constructor has been called!" << endl;
            }
            ~MyClass()
            {
                cout << "Destructor has been called!" << endl;
            }
};

int main()
{
    int temp;
    MyClass object;
    /*
    The constructor is called right immediately after creating the object of the class.
    The destructor is called right after the main function ends, when the object is destroyed.
    The destructor it's used to delete/destroy all the variables within the class and to free the resources.
    */
    cout << "Press any key to end!" << endl;
    cin >> temp;
    return 0;
}

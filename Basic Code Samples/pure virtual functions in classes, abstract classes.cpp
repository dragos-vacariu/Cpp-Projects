#include <iostream>
#include <conio.h>
#include <vector>
#include <string>

using namespace std;

class ParentClass{ //this is an abstract class;
public:
    ParentClass()
    {
        name="NONAME";
    }
    ParentClass(string NewName)
    {
        name=NewName;
    }
    virtual void myname()=0; //THIS IS A PURE VIRTUAL FUNCTION;
protected:
    string name;
};
class DerivedClass: public ParentClass
{
public:
    DerivedClass(string NewName)
    {
        name=NewName;
    }
    void myname()
    {
        cout << name << " is my name!" << endl;
    }
};
int main()
{
    /*
    Pure virtual function sintax: virtual <function name> (<arguments>) =0;
    A virtual function should be declared only in the parent class.
    A pure virtual function is a function that is set to 0 meaning that all the children derived from that class
    who have a same name function are obliged to overwrite the definition of it, in their ways.
    A pure virtual function in the main/parent class makes the class be abstract. An abstract class is a class
    to which an object/instance cannot be created, the only purpose of a abstract class is to connect its children.
    An object of is also called instance.
    */

    DerivedClass objectchild("DerivedClass");

    objectchild.myname();

    getch();
    return 0;
}

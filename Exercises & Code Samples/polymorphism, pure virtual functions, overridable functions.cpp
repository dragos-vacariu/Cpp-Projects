#include <iostream>
/*
The word polymorphism means having many forms. Typically, polymorphism occurs when there is a hierarchy of classes
and they are related by inheritance.

C++ polymorphism means that a call to a member function will cause a different function to be executed depending on
the type of object that invokes the function. Example if a parent class function is set to be override-able, then a
parent class pointer can have functionality of the a child class object.

A pure virtual function is a function that is declared in the parent class and it really needs to be defined in
each one of the child classes.
Syntax: virtual void DisplayFunction () = 0;
*/
using namespace std;

class Shape{
    //By default a member without access-specifier is set to private.
protected:
    int length;
    int height;
public:
    virtual void DisplayInfo()
    {
        cout << "This is the parent class." << endl;
    }
};
class Square: public Shape{
private:
    int area;
    void CalcArea()
    {
        area=length*height;
    }

public:
    Square (int len, int hg)
    {
        length=len;
        height=hg;
        CalcArea();
    };
    void DisplayArea()
    {
        cout << "Area: " << area << endl;
    }
    //This function overrides the parent class function
    void DisplayInfo()
    {
        cout << "This is the child class." << endl;
    }
};
class Circle: public Shape
{
private:
    int radius;
public:
    Circle(int len)
    {
        radius=len/2;
    }
    void DisplayRadius()
    {
        cout << "Radius: " << radius << endl;
    }
};

int main()
{
    Shape *p;
    Circle circle_object(22);
    Square square_object(4,3);
    /*
    The pointer of type Shape can reference any of the Shape class children, but having only the functionality of Shape
    Class.
    */
    p=&circle_object;
    p->DisplayInfo();
    p=&square_object;
    p->DisplayInfo();
    int a;
    cin >> a;
    return 0;
}

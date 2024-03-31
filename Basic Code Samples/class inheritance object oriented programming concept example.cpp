#include <iostream>
#include <conio.h>

using namespace std;

//BASE CLASS
class Shape{

    protected: //these variables are visible into this class and the other classes that are inherited to this.
        string name;
    public:
        Shape(string newname)
        {
            name=newname;
        }
        string getName() const
        {
            return name;
        }
};
//CHILD CLASS ONE
class Circle : public Shape //making Circle class derive from the Shape class (setting the inheritance).
{
    //inheritance is a way to make 2 classes share the same variables between each other

    double radius; //this variable can be private, or protected or public (anything).

    public:
        Circle(string inheritedName, double newradius) : Shape (inheritedName)//this will call the Shape constructor
        //which will set a value into it's string variable called 'name', in this way, a variable will be used in 2 classes.
        {
            radius=newradius;
        }
        double getCircleRadius() const
        {
            return radius;
        }

};
//CHILD CLASS TWO
class Rectangle : public Shape // making the Rectangle class derive from Shape Class, let the Rectangle Class, use the
//protected variables of the Shape Class.
{
    double length, width;

    public:
        Rectangle (string inheritedName2, double newlength, double newwidth): Shape (inheritedName2)
        {
            length=newlength;
            width=newwidth;
        }
        double getRectangleLength() const
        {
            return length;
        }
        double getRectangleWidth () const
        {
            return width;
        }
};

int main()
{
    Shape object("Shape Class String"); //create object
    cout << object.getName() << endl; //calling a function from the class

    cout << endl << "CHILD ONE CLASS: " << endl;
    Circle objectchild ("Circle (stored in Shape Class String)", 3.0); //create object
    cout << objectchild.getName() << endl; //calling a function from Shape Class using the object from Circle Class.
    cout << objectchild.getCircleRadius() << endl;

    cout << endl << "CHILD TWO CLASS: " << endl;
    Rectangle objectchild2("Rectangle (stored in Shape Class String)", 20.0, 65.0); //create object
    cout << objectchild2.getName() << endl; //calling a function from Shape Class using the object from Rectangle Class.
    cout << objectchild2.getRectangleLength() << endl;
    cout << objectchild2.getRectangleWidth() << endl;

    getch();
    return 0;
}

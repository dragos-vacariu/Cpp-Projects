#include "classes_and_objects.h"

classes_and_objects::classes_and_objects() //the default constructor
{
    // the default constructor is used to initialize the variable of the class;
    //strings in C++ are automatically initialized to null;
    newheight=0;
    newweight=0;
}

classes_and_objects::classes_and_objects(string name, int height, double weight)
//this is my self constructed constructor.
{
    //constructors can have the same names, only differing by arguments. This is called
    //overloading the constructor.
    newname=name;
    newheight=height;
    newweight=weight;
}

classes_and_objects::~classes_and_objects()
{
}

string classes_and_objects::getName() const
{
    return newname;
}
int classes_and_objects::getHeight() const
{
    return newheight;
}
double classes_and_objects::getWeight() const
{
    return newweight;
}

void classes_and_objects::setName(string name)
{
    newname=name;
}
void classes_and_objects::setHeight(int height)
{
    newheight=height;
}
void classes_and_objects::setWeight(double weight)
{
    newweight=weight;
}

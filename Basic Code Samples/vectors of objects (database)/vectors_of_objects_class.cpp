#include "vectors_of_objects_class.h"

vectors_of_objects_class::vectors_of_objects_class() //default constructor
{
    //ctor
}

vectors_of_objects_class::vectors_of_objects_class(string name, int age) //self made constructor
{
    //initializing the variables;
    newage=0;
}

vectors_of_objects_class::~vectors_of_objects_class()
{
    //dtor
}

string vectors_of_objects_class::getName() const //access the private variable of the class
{
    return newname;
}
int vectors_of_objects_class::getAge() const //access the private variables of the class
{
    return newage;
}
void vectors_of_objects_class::setName(string name) //set the private variables of the class
{
    newname=name;
}
void vectors_of_objects_class::setAge(int age) //set the private variables of the class
{
    newage=age;
}

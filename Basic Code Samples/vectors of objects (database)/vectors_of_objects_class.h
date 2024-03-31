#ifndef VECTORS_OF_OBJECTS_CLASS_H
#define VECTORS_OF_OBJECTS_CLASS_H

#include <iostream>
#include <vector>

using namespace std;

class vectors_of_objects_class
{
    public:
        vectors_of_objects_class(); //default constructor
        vectors_of_objects_class(string, int); //self made constructor

        //Accessor functions:
        string getName () const;
        int getAge () const;

        //Mutator functions;
        void setName(string);
        void setAge(int);

        virtual ~vectors_of_objects_class();

    protected:

    private: //private variables;
        string newname; 
        int newage;
};

#endif // VECTORS_OF_OBJECTS_CLASS_H

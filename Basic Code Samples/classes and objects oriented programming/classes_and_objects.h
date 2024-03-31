#ifndef CLASSES_AND_OBJECTS_H
#define CLASSES_AND_OBJECTS_H

#include <iostream>
#include <string>

using namespace std;
class classes_and_objects
{
    public: //these are visible everywhere
        classes_and_objects(); //the default constructor;
        classes_and_objects(string, int, double); //self made constructor (overloaded)

        //Accessor Functions
        //these functions are used to access the private variables, outside the class;
        string getName() const; //const because it won't modify the information
        int getHeight() const;
        double getWeight() const;

        //Mutor Functions
        //these functions are used to set the values for the variables, after calling
        //the default constructor;
        void setName (string);
        void setHeight (int);
        void setWeight (double);

        virtual ~classes_and_objects();

    protected: //these are visible in every class that's inherted.
    //protected variables, are visible in classes made through inheritance
    //inheritance is when a class or object depends on another.


    private: //these are visible only inside the class
        string newname;
        int newheight;
        double newweight;
};

#endif // CLASSES_AND_OBJECTS_H

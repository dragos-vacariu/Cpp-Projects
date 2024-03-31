#include "classes_and_objects.h"

using namespace std;
int main()
{
    string name;
    int height;
    int weight;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your height: ";
    cin >> height;
    cout << "Enter your weight: ";
    cin >> weight;
    cout << endl;

    classes_and_objects object(name,height,weight); //creating an object, from the class
    //setting it to use my self made constructor instead of the default one, by mentioning
    //the arguments.
    cout << "Patient1 Name: " << object.getName() << endl <<
            "Height: " << object.getHeight() << endl <<
            "Weight: " << object.getWeight() << endl;

    cout << endl;

    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your height: ";
    cin >> height;
    cout << "Enter your weight: ";
    cin >> weight;
    cout << endl;

    //Setting the object number 2.
    classes_and_objects object2; //using the default constructor;

    object2.setName(name);
    object2.setHeight(height);
    object2.setWeight(weight);

    cout << "Patient2 Name: " << object2.getName() << endl <<
        "Height: " << object2.getHeight() << endl <<
        "Weight: " << object2.getWeight() << endl;

    //see here how the first object still stores the information, previously set
    //even if the variable has been changed.
   cout << endl <<"Patient1 Name: " << object.getName() << endl;
   //best part of object oriented programming is that every object hold to their
   //information, no matter that you go further to using another object.

    return 0;
}

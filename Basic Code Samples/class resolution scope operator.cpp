#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

class Ninja{
public:
    Ninja(int health, string name) //constructor without scope resolution
    {
        name = name; /*this is expected to set the private variable name be equal to the local variable name, but it does
        not do that because the scope resolution is not present, so the compiler does not know how to interpret the variables
        which is which, of course this is only because they have the same name. */

        health = health; // same problem here.
    }
    /*The arguments are inverted just because I need to have different arguments to create a new constructor, of course
    another solution would be to bring a new argument, or give other names to arguments, but I want to be able to use
    the same format as above, to exemplify the scope resolution operator in a class.
    */
    Ninja(string name, int health) //constructor with scope resolution
    {
        //the scope resolution for a class has this synthax: <classname>::
        Ninja::name=name;
        Ninja::health=health;
    }
    //GETTERS
    string getName()
    {
        return name;
    }
    int getHealth()
    {
        return health;
    }

private:
    string name;
    int health;
};

int main()
{
    //Using the constructor 1 (without scope);
    Ninja object(100, "Adam");
    //Using the constructor 2 (with scope);
    Ninja object2 ("Adam", 100);
    //Object
    cout << "Unscoped Constructor: " <<object.getHealth() << " " << object.getName() << endl; //this does not work
    //Object2
    cout << "Scoped Constructor: " << object2.getHealth() << " " << object2.getName() << endl; //this works

    getch();
    return 0;
}

#include <iostream>
#include <conio.h>
#include <string>
#include <list>

using namespace std;
class Monster{
public:
    Monster()//the default constructor, is required for inheritance of the class below
    {
        name="NONAME"; //just initialization;
    }
    //If the body of the constructor misses, there will occur a weird compilation error.
    Monster(string newname){
        name=newname;
    }
    void moving(){
        cout << name << " is moving!" << endl;
    }
    virtual void update() //A virtual function is a function that can be overwritten by the children classes (inheritance).
    {
        moving();
    }
protected: //set the variables that can be accessed by the inherited classes
    string name;

};

class Spider: public Monster //making the class Spider derive from the class Monster;
{
public: Spider(string newname) {
        name=newname;
    }
    void attack()
    {
        cout << name << " is attacking!" << endl;
    }
    void update() //Note that this update function is not the same as the Monster::update function, that's why is necessary
    //to put a virtual keyword in front of that function, because Monster is the parent class.
    {
        moving();
        attack();
    }
protected:

};

int main()
{
    /*
        Polymorphism is a way of attaching two different objects to the same data type as a list or vector.
        Note that: This only works in the case of inheritance. When classes gets connected between each other.

        In other words with polymorphism we can have two different data types into the same vector, list, or array, and
        we can iterate between them.
    */
    list <Monster*> monsters; //creating a list of monster object pointers.
    list <Monster*>::iterator it; //creating an iterator for the list.
 /*
    THIS IS WRONG;
    monsters.push_back(Monster);
    monsters.push_back(Spider);
    */
    Monster objectMonster("Mikey"); //setting the object for the Monster class (which is the parent class)
    Spider objectSpider("Mathew"); //setting the object for the Spider class (which is the children class)
    monsters.push_back(&objectMonster); //push back the objects to the list.
    monsters.push_back(&objectSpider);
    for(it=monsters.begin(); it!=monsters.end(); it++) //iterate between the object, and call a function.
    {
        (*it)->moving();
    }
    /*Now in order to can call the function update() for each class we have to define on parent class(which is Monster)
    the update function to be virtual. A virtual function is a function that can be overloaded/overwritten by the children
    classes. Without making the update function from Monster to be virtual, the iterator will call the same function two times
    which will not be right, because our update function differs from a class to another.
    */
    cout << endl << "With virtual keyword: \n" << endl;
    for(it=monsters.begin(); it!=monsters.end(); it++) //iterate between the objects, and call a function
    {
        (*it)->update();
    }
    getch();
    return 0;
}

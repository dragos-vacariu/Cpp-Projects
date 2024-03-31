#include <iostream>
#include <conio.h>
#include <string>

using namespace std;
class Monster{
public:
    Monster()//the default constructor, is required for inheritance of the class below
    {
        name="NONAME";
    }
    //If the body of the constructor misses, there will occur a weird compilation error.
    Monster(string newname){
        name=newname;
    }
    void moving(){
        cout << name << " is moving!" << endl;
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
protected:

};

int main()
{
    Monster objectMonster("Mikey");
    Spider objectSpider("Mathew");
    objectMonster.moving();
    objectSpider.moving();
    objectSpider.attack();
    getch();
    return 0;
}

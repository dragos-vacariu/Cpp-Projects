#include <iostream>

/*
    The purpose of an abstract class (often referred to as an ABC) is to provide an appropriate base class from
    which other classes can inherit.
    Abstract classes cannot be used to instantiate objects and serves only as an interface.Attempting to instantiate
    an object of an abstract class causes a compilation error.

    Classes that can be used to instantiate objects are called concrete classes.

    An interface describes the behavior or capabilities of a C++ class without committing to a particular implementation
    of that class. A class is an interface only if it has a virtual field in it's definition such that it becomes
    an ABTRACT CLASS.

    Any class type (whether declared with class-key class or struct) may be declared as derived from one or more base
    classes.

    A base class is specified virtual, to make the derived classes contains only one member/field of that base-class,
    even if the base-class appears many times in the inheritance hierarchy (as long as it is inherited virtual every time).
    Example: class B:A; class C:A and class D:B,C, so the last class D should have twice the elements of class A, because
    it inherits from B and C which inherits from A. To avoid that the class A will be marked as virtual base class.
*/





using namespace std;

//THIS IS AN ABSTRACT CLASS OR AN INTERFACE.
class AbstractClass {
        //This is a virtual function that asks for its definition inside each children of this class.
    virtual void PrintMessage() = 0; //virtual functions/variables are used to make a class be ABSTRACT.

    //These variables(fields or members) are shared (or can be called) with the children of this class.
    protected:
        string Message;
        void DisplayInfo()
        {
            cout << "AbstractClass can also have implemented functions." << endl;
        }

    //These members are public, can be called from anywhere
    public:
        //THIS METHOD CANNOT BE CALLED ANYWHERE, BECAUSE THE CLASS ITS ABSTRACT AND IT CANNOT BE INSTANTIATED.
        void setMessage2(string msg)
        {
            Message = msg;
            //this. keyword cannot be used inside an abstract class.
        }

        //This function can be called using the syntax: AbstractClass::DisplayMessage because its a static function.
        static void DisplayMessage()
        {
            cout << "This is a STATIC FUNCTION inside an ABSTRACT CLASS." << endl;
        }
    //These fields/members are private, can be used only inside the class.
    private:
};

class SecondBaseClass{
    /* virtual string Name = 0; // virtual keyword is used to create abstract classes, creating abstract functions in
    in those classes, and can also be used to make a method/function override-able, to the child classes. Also this keyword
    can make a base-class become virtual base-class to avoid a field be inherited twice because of inheritance hierarchy.
    */
    public: virtual void FunctionReplace() //creating a virtual function will  oblige all the children of this class
    //provide their own implementation of this function. NOTE: this is not an ABSTRACT function, and this is not an
    //ABSTRACT CLASS.
    {
        cout << "This function can be replaced." << endl;
    }
};

class MyClass: AbstractClass, SecondBaseClass{
    public:
        void PrintMessage()
        {
            cout << Message << endl;
        }
        void setMessage(string msg)
        {
            Message=msg;
        }
        void ParentFunction()
        {
            DisplayInfo();
        }
        void FunctionReplace()
        {
            cout << "This function has been replaced by a new definition." << endl;
        }
};

int main()
{
    /*AbstractClass object; - abstract classes cannot be instantiated.*/
    MyClass object;
    object.setMessage("This is a message.");
    AbstractClass::DisplayMessage();
    object.PrintMessage();
    object.ParentFunction();
    object.FunctionReplace();
    SecondBaseClass obj;
    obj.FunctionReplace();
    int a;
    cin >> a;
    return 0;
}


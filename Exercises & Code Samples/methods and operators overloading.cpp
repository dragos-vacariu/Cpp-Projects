#include <iostream>

/*
C++ allows you to specify more than one definition for a function name or an operator in the same scope, which is
called function overloading and operator overloading respectively.

An overloaded declaration is a declaration that had been declared with the same name as a previously declared
declaration in the same scope, except that both declarations have different arguments and obviously different
definition (implementation).

When you call an overloaded function or operator, the compiler determines the most appropriate definition to
use by comparing the argument types you used to call the function or operator with the parameter types specified
in the definitions. The process of selecting the most appropriate overloaded function or operator is called overload
resolution.

You can have multiple definitions for the same function name in the same scope. The definition of the function must
differ from each other by the types and/or the number of arguments in the argument list. You can not overload function
declarations that differ only by return type.

Operator overloading syntax: A operator+ (const A& x, const A& y) { ... } where A is a class.
*/

using namespace std;

class MyClass{
public:
    string Message;
public:
    MyClass(string msg)
    {
        Message=msg;
    }
    void Print(string message)
    {
        cout << "String Argument: " << message << endl;
    }
    void Print(int a)
    {
        cout << "Int Argument: " << a << endl;
    }
    void Print(float b)
    {
        cout << "Float Argument" << b << endl;
    }
    void PrintMessage()
    {
        cout << Message << endl;
    }
};

//THIS CLASS IS USED FOR OPERATOR OVERLOADING EXAMPLE:
class A
{
public:
	int x;
	int y;
	A(int a, int b)
	{
        x=a;
        y=b;
	}

};
//OVERLOADING OPERATORS:
A operator+ (const A& x, const A& y)
{
	A retObj(0,0);
	retObj.x = x.x + y.x;
	retObj.y = x.y + y.y;
	return retObj;
}

int main()
{
    MyClass obj ("Simple Message");
    obj.Print("I was here");
    obj.Print(22);
    obj.Print(1.2334f);
    //OPERATOR OVELOADING EXAMPLE:
    A a(22,33);
    A b(1, 5);
    a=a+b;
    cout << "Using operator overloading: x= " << a.x << " y= " << a.y << endl;
    int ab;
    cin >> ab;
    return 0;
}

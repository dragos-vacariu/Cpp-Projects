#include <iostream>
#include <string>

/*
Templates are the foundation of generic programming. Generic programming is a style of programming in which the data type
are specified latter, the benefit of this is that, a function can be written such that it will work for all of the
data types.

A template is a blueprint or formula for creating a generic class or a function. You can think of a template such as a
pair of shoes that can match everyone feet, so everyone can wear them.

Syntax:
template <typename generic_type> return-type function-name(parameter list)
{
   // body of function
}
generic_type can be any type, so it will be given a simple name which will get to be replaced by the compiler, at
the compilation time.
*/

using namespace std;

//Creating a template:
template <typename T> T Max (T const& a, T const& b)
{
    //This syntax is called ternary operator (also called the short if statement).
   return a < b ? b:a;
}

int main () {

   int i = 39;
   int j = 20;
   //Calling the template function for int:
   cout << "Max(i, j): " << Max(i, j) << endl;

   double f1 = 13.5;
   double f2 = 20.7;
   //Calling the template function for float:
   cout << "Max(f1, f2): " << Max(f1, f2) << endl;

   string s1 = "Hello";
   string s2 = "World";
   //Calling the template function for string:
   cout << "Max(s1, s2): " << Max(s1, s2) << endl;

   cin >> j;
   return 0;
}

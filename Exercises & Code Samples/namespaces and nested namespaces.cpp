#include <iostream>
/*
Consider a situation, when we have two persons with the same name, Zara, in the same class. Whenever we need to
differentiate them definitely we would have to use some additional information along with their name, like either
the area if they live in different area or their mother or father name, etc.

Same situation can arise in your C++ applications. For example, you might be writing some code that has a function
called xyz() and there is another library available which is also having same function xyz(). Now the compiler has
no way of knowing which version of xyz() function you are referring to within your code.

A namespace is designed to overcome this difficulty and is used as additional information to differentiate similar
functions, classes, variables etc. with the same name available in different libraries.

There can exist nasted namespaces (a namespace inside another).
A namespace can be spread in multiple files.
You can also avoid prepending of namespaces with the using namespace directive. Just like in "using namespace std;"
*/


using namespace std;

// Creating the first name space
namespace first_space{
   void func(){
      cout << "Inside first_space" << endl;
   }
}

// Creating the second name space
namespace second_space{
   void func(){
      cout << "Inside second_space" << endl;
   }
}

int main () {

   // Calling the function from first namespace.
   first_space::func();

   // Calling the function from second name space.
   second_space::func();
   int a;
   cin >> a;
   return 0;
}

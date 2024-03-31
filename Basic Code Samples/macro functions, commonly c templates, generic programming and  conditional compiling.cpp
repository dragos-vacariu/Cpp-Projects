#include <iostream>
#define DEBUG
/*
The preprocessors are the directives, which give instruction to the compiler to preprocess the information before
actual compilation starts.

One important advantage of macro-based implementation is that it is not tied to any concrete parameter type.
A function-like macro in C acts, in many respects, as a template function in C++
*/

using namespace std;

#define MIN(a,b) (((a)<(b)) ? a : b) //a and b can be anything, can have any type, this is somehow similar to a template.

int main () {
   int i, j;
   i = 100;
   j = 30;

   cout <<"The minimum is " << MIN(i, j) << endl;
    #ifdef DEBUG
      cout << "This is conditional compiling." << endl;
    #endif
    cin >> i;
   return 0;
}

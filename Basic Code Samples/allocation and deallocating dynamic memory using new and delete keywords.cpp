#include <iostream>

/*
The keyword "new" its used to allocate dynamic memory on the heap for a certain object or element, this is very
similar to the malloc function in c language.
The keyword "delete" its used to deallocate the memory required by an object, and this is very similar to the free()
method in c language.
*/


using namespace std;

class Box {
   public:
      Box() {
         cout << "The constructor is called when the object is created!" << endl;
      }
      ~Box() {
         cout << "The destructor is called when the object is deleted.!" << endl;
      }
      void PrintMessage()
      {
          cout << "This is a function message." << endl;
      }
};


int main ()
{
   double* pvalue  = NULL; // Pointer initialized with null
   pvalue  = new double;   // Request memory for the variable

   *pvalue = 29494.99;     // Store value at allocated address
   cout << "Value of pvalue : " << *pvalue << endl;

   delete pvalue; // free up the memory.

   //Allocating dynamic memory for an object of a class.
   Box* mybox = new Box();
   //TO dereference a class or structure the -> arrow operator must be used.
   mybox->PrintMessage();
   delete mybox;

   int a;
   cin >> a;
   return 0;
}

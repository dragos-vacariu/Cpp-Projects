#include <iostream>
/*
Exceptions provide a way to react to exceptional circumstances (like runtime errors) in programs by transferring
control to special functions called handlers.

To catch exceptions, a portion of code is placed under exception inspection. This is done by enclosing that portion
of code in a try-block. When an exceptional circumstance arises within that block, an exception is thrown that
transfers the control to the exception handler. If no exception is thrown, the code continues normally and all
handlers are ignored.
*/
using namespace std;
//Creating an exception:
class myexception: public exception
{
  virtual const char* what() const throw()
  {
    return "My exception happened";
  }
} myex;


int main () {
  //Throwing a particular exception.
  try
  {
    throw 20;
  }
  catch (int e)
  {
    cout << "An exception occurred. Exception Nr. " << e << '\n';
  }
  //Throwing an exception;
  try{
    throw;
  }
  catch(exception& e)
  {
      cout << "Exception has been thrown." << endl;
  }
//Throwing my exception;
  try{
    throw myex;
  }
  catch(exception& e)
  {
      cout << e.what() << '\n';
  }

  int a;
  cin >> a;
  return 0;
}

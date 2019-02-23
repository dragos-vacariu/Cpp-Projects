#include <iostream>
#include <csignal> //used for signals;
#include <stdlib.h> //used for exit function;
#include <windows.h> //used for Sleep() function;
using namespace std;

/*
Signals are the interrupts delivered to a process by the operating system which can terminate a program prematurely.
You can generate interrupts by pressing Ctrl+C on a UNIX, LINUX, Mac OS X or Windows system.

There are signals which can not be caught by the program but there is a following list of signals which you can catch
in your program and can take appropriate actions based on the signal. These signals are defined in C++ header file
<csignal>.

SIGABRT 	Abnormal termination of the program, such as a call to abort
SIGFPE 	An erroneous arithmetic operation, such as a divide by zero or an operation resulting in overflow.
SIGILL 	Detection of an illegal instruction
SIGINT 	Receipt of an interactive attention signal.
SIGSEGV 	An invalid access to storage.
SIGTERM

C++ signal-handling library provides function signal to trap unexpected events. Following is the syntax
of the signal() function:
Syntax: void (*signal (int sig, void (*func)(int)))(int);

You can generate signals by function raise(), which takes an integer signal number as an argument and has
the following syntax.
Syntax:int raise (signal sig);
Here, sig is the signal number to send any of the signals: SIGINT, SIGABRT, SIGFPE, SIGILL, SIGSEGV, SIGTERM, SIGHUP
*/


void signalHandler( int signum ) {
   cout << "Interrupt signal (" << signum << ") received.\n";

   // cleanup and close up stuff here
   // terminate program
   int i;
   cin >> i;
   exit (signum);

}

int main () {
   int i = 0;
   // register signal SIGINT and signal handler
   signal(SIGINT, signalHandler);

   while(++i){
      cout << "Going to sleep...." << endl;

      if( i == 3 ){
          //The program will terminate once it reaches this point because of the signal handler.
         raise( SIGINT);
      }

      Sleep(1);
   }
   cin >> i;
   return 0;
}

#include <iostream>
#include <cstdlib>
#include <pthread.h> //used for multi-threading

/*
Multithreading is a specialized form of multitasking and a multitasking is the feature that allows your computer
to run two or more programs concurrently. In general, there are two types of multitasking: process-based and
thread-based.

Process-based multitasking handles the concurrent execution of programs. Thread-based multitasking deals
with the concurrent execution of pieces of the same program.

A multithreaded program contains two or more parts that can run concurrently. Each part of such a program is
called a thread, and each thread defines a separate path of execution.

C++ does not contain any built-in support for multithreaded applications. Instead, it relies entirely upon the operating
system to provide this feature.
Creating a thread syntax: pthread_create (thread, attr, start_routine, arg);
pthread_create creates a new thread and makes it executable.

Where:
thread - An opaque, unique identifier for the new thread returned by the subroutine.
attr - An opaque attribute object that may be used to set thread attributes. You can specify a thread attributes object,
or NULL for the default values.
start_routine - The C++ routine that the thread will execute once it eis created.
arg - A single argument that may be passed to start_routine. It must be passed by reference as a pointer cast of
type void. NULL may be used if no argument is to be passed.

Terminating a thread syntax: pthread_exit (status);
pthread_exit is used to explicitly exit a thread. Typically, the pthread_exit() routine is called after a thread has
completed its work and is no longer required to exist.
*/

using namespace std;

#define NUM_THREADS 5

void *PrintHello(void *threadid) {
   long tid;
   tid = (long)threadid;
   cout << "Hello World! Thread ID, " << tid << endl;
   pthread_exit(NULL);
}

int main () {
   //Creating a thread array;
   pthread_t threads[NUM_THREADS];
   int rc;
   int i;
    //Initializing the thread array:
   for( i=0; i < NUM_THREADS; i++ ){
      cout << "main() : creating thread, " << i << endl;
      rc = pthread_create(&threads[i], NULL, PrintHello, (void *)i);

      if (rc){
         cout << "Error:unable to create thread," << rc << endl;
         exit(-1);
      }
   }

   pthread_exit(NULL);
   cin >> i;
   return 0;
}

#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;

int main()
{
    //C string;
    char mystring[] = "BlackC";

    //C++ string
    string mystr = "BlackCPP";

    //printing the strings with iostream;
    cout << mystring << endl;
    cout << mystr << endl;

    //printing the string with printf;
    printf("%s", mystring); cout << endl;
   // printf("%s", mystr); //this gives an error, because printf cannot work with C++ strings.
   printf("%s \n", mystr.c_str()); //mystr.c_str() -> is a function that converts a C++ string into a C string, it actually
   //a function that returns a C string with the same content as mentioned in C++ string.

   //Bad C string initialization;
   char secondstring[4] = {'A', 'd', 'a', 'm'};
   printf("%s\n", secondstring); //this will print a creepy message because the string initialized above does not contain
   //the \0, with is the string terminator.

   /* Correct C string declarations:
   char secondstring[] = "Adam";
   char secondstring[5] "Adam";
   char secondstring [5] {'A', 'd', 'a', 'm'};
   char secondstring [] {'A', 'd' , 'a', 'm');
   */

    getch();
    return 0;
}

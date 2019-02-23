#include <iostream>
#include <conio.h>

using namespace std;
int main()
{
    int i=5;
    int j=6;

    cout << "Integer Division: \n\n";
    cout << "Normal result: (i/j) = " << i/j << endl; //this will print zero because the division of two integers cannot be represented withing a float.
    cout << "Casted result: (float) (i/j) = " << (float) (i/j) << endl; //this will also print zero, because it will cast only the result above
    //which was zero, to the floating point.
    cout << "Casted i result: (float) (i) /j = " << (float) (i) /j << endl; // this will print the right answer;
    cout << "Casted j result: i/ (float) (j) = " << i/ (float) (j) << endl; //this will also print the right answer;

    //Casting/Data type conversion;
    char ch = 'D'; //when the compiler runs through the code it will replace 'D' to a number that represent the letter
    //specified in the quotes to a its associated number in ASCI Table Code.

    int nr = 44;
    float fl = 5.5;

    cout << endl << "Cast Conversion: " << endl << endl;

    //Converting a Char to an Int:
    cout << "Char 'D' casted to integer: " << (int) ch << endl;
    //Converting an Int to a Char:
    cout << "Int 44 casted to char: " << (char) nr << endl;
    //Converting a Float to a Char:
    cout << "Float 5.5 casted to char: " << (char) fl << endl; //this will print a strange symbol, because there is
    //no associated symbol to 5.5 in ASCI Table.
    ch='F';
    //Converting a Char to a Float:
    cout << "Char 'F' casted to float: " << (float) ch << endl;

    getch();
    return 0;
}

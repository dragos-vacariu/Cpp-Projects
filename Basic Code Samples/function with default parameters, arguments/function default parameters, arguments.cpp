#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

//Forward Declaration with default parameters:
int DefaultFunction(int a, bool printOnScreen=true, bool printOnFile=true); //printOnScreen, and printOnFile are default
//parameters.

/*
    Default Arguments must be set in the forward declaration of the function, just right above.

    To add default parameters/arguments in a function, you have to start from right to left, and add an initializer which
    will be the default value to the desired parameters.
    Warning: all the arguments must be initialized in order, there cannot be normal arguments (that are not default),
    between default arguments, because in this case the compiler won't know the value you introduce for a certain argument
    to which should be assigned.

    Good Example DefaultFunction(int a, bool printOnScreen=true, bool printOnFile=true);

    Bad Example: Function (int a, bool par1=true, bool par2, bool par3=true), in this case it won't work because
    all the arguments/parameters must be initialized to a default value from the desires argument/parameter until the end.
    In other words there cannot be a NORMAL ARGUMENT between DEFAULT ARGUMENTS.
*/

int main()
{
    int number;
    cout << "Enter a value: ";
    cin >> number;
    DefaultFunction(number); //calling the function;
    getch();
    return 0;
}
//Function implementation;
int DefaultFunction(int a, bool printOnScreen, bool printOnFile) //note that default parameters are not here.
//if the default parameters would be declared here... compilation errors would occur.
{
    a+=5;
    if(printOnScreen)
    {
        cout << "The value of parameter: " << a << endl;
    }
    if(printOnFile)
    {
        ofstream OutputInFile;
        OutputInFile.open("PrintLog.txt");
        if(OutputInFile.fail()) //nasted if;
        {
            perror("PrintLog.txt"); //print an error message;
            return 0;
        }
        OutputInFile << a; //print the value of a inside the file;
    }
}

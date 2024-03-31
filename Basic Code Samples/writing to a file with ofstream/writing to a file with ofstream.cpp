#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>

using namespace std;
int main()
{
    ofstream OutputToFile; //creating an object of the ofstream class from library fstream;
    OutputToFile.open("output.txt"); //if this file is not found, it will be created.
    OutputToFile << "This is my string." << endl; // using cout operator '<<';
    OutputToFile.close();
    getch();
    return 0;
}

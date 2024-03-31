#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

int main()
{
    string checkEndLine; //string just to check;
    ifstream gettingValues; // creating an object of class ifstream from fstream library;
    gettingValues.open("numbers.txt"); // open this specific file;
    if(gettingValues.fail()) //if the fails to open, because it's not found or it's corrupted;
    {
        cerr << "Error opening the file!" << endl;
        exit(1); //function from stdlib library.
    }
    else if (gettingValues.good()) // the order is important
    {
        int x,y;
        gettingValues >> x >> y; //reading from file operator '>>' ;
        cout << "Number 1: " << x << endl << "Number 2: " << y << endl; // print the numbers;
    }
    gettingValues.close();
    getch();
    return 0;
}

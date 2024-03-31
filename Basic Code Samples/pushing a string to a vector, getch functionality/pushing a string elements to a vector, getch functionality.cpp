#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <vector>
#include <windows.h>

using namespace std;

int main()
{
    //A vector of string is like a 2D array of characters;
    vector <string> myvector;
    ifstream input;
    string holdinfo;
    input.open("stringfile.txt");
    //File check;
    if(input.fail()) //if file.open() fails.
    {
        perror("stringfile.txt"); //print an helpful/explicit error message
        return 1; //return 1, meaning there was an error.
    }
    //Pushing the string into the vector;
    while(getline(input, holdinfo))
    {
        myvector.push_back(holdinfo); //add a string to a vector;
    }
    //Printing the string;
    for(int i=0; i<myvector.size(); i++)
    {
        cout << myvector[i] << endl; //print out the full vector;
    }
    input.close(); //when using ifstream, the file closes automatically, but it's
    //still a  good measure to do this manually.

    //Getch() function;
    cout << endl << "Getch() functionality: " << endl;
    while(true)
    {
        char c=getch();
        cout << "You pressed: " << c << endl;
    }

    system("PAUSE"); //function in windows.h that keeps the console opened
    return 0;
}

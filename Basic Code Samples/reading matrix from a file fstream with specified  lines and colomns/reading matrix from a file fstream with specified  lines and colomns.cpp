#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

int main()
{
    int l,c,nl,nc;
    ifstream f("data.txt"); //open the file.
//Reading the number of lines and columns.
    f>>nl>>nc;
//Creating the matrix with specified number of lines and columns
    int a[nl][nc];
//Reading the elements of the matrix
    for(l=1;l<=nl;l++)
    {
        for(c=1;c<=nc;c++)
        {
            f>>a[l][c];
        }
    }
//Printing the matrix on the screen
    for(l=1;l<=nl;l++)
    {
        for(c=1;c<=nc;c++)
        {
            cout<<a[l][c]<<" ";
        }
        cout<<endl;
    }
    getch();
    return 0;
}

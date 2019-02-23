#include <iostream>
#include <conio.h>

using namespace std;
int main()
{
    double fvariable = 4.1345;
    cout.setf(ios::fixed); //fixed decimals in memory;
    cout.setf(ios::showpoint); //decimals that can be shown;
    cout.precision(3); //decimals set to be shown.
    cout << fvariable << endl;

    getch();
    return 0;
}

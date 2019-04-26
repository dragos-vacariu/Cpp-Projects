#include <iostream>
#include <conio.h>
#include <ctime>
#include <stdlib.h>

using namespace std;
int main()
{
    srand(time(0));
    unsigned int output = rand() %10 + 1;
    for (int i=0;i<10;i++)
    {
        cout << output << " ";
        output=rand() %10 + 1;
    }
    getch();
    return 0;
}

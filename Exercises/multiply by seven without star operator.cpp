#include <iostream>
#include <conio.h>

using namespace std;
int main(int args, char** argv)
{
    int number;
    int result=0;
    cout << "Enter a number!\n";
    cin >> number;
    for(int i=0;i<7;i++)
    {
        result+=number;
    }

    cout << "The result is: " << result << endl;

    getch();
    return 0;
}

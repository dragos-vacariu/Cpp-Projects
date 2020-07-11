
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    cout << "You have entered " << argc
         << " arguments:" << "\n\n";

    for (int i = 0; i < argc; ++i) //there is always gonna be at least one argument in argv. On index 0, is the name of the .cpp file.
        cout << argv[i] << "\n";


    cout << "\nThe filepath above is always the first argument.\n";
    char a;
    cin >> a;
    return 0;
}

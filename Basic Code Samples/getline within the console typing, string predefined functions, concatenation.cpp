#include <iostream>
#include <conio.h>

//string type can be written without string.h library;
//getline () can be used with iostream library only included.
using namespace std;
int main()
{
    string input;
    cout << "Enter your name: ";
    getline (cin, input);
    cout << "Hello " << input << ", welcome!" << endl;

    /*String predefined functions:
    input.length() -> returns the length of the string (with spaces included)
    input.size() -> returns the size of the string, same as length.
    input.at(int) -> returns the character of a specified index in the string.
    input.append(string) -> concatenate/adds two strings together, first is input, second is (string specified)
    input.insert(index, string, starting position, length) -> insert a string within another
    */
    input.insert(input.size(), " Black", 0, 6);
    cout << input << endl;
    cout << "The length is: " << input.length() << endl;
    cout << "The size is: " << input.size() << endl;
    cout << "The character at position 4 is: " <<input.at(4) << endl;
    cout << "Appended string with DS: " <<input.append(" DS");

    getch();
    return 0;
}

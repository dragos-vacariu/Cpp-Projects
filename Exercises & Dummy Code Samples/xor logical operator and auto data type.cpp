#include <iostream>
#include <conio.h>

using namespace std;
int main()
{
    /*auto detects automatically what data type should be used for your variable, but
    it always needs to be initialized right where it is declared, so it can detect
    what data type to use. */
    auto score = 0;
    cout << "Enter the score from your test: " << endl;
    cin >> score;
    if (score>=0 ^ score<=10) //only one of them can be true;
        //XOR operator (^) -> only one condition can be true, EXCLUSIVE OR.
        //if both are true then the if statement is skipped.
    {
        cout << "Score within the range. Value = " << score << endl;
    }
    else
    {
        cout << "Condition unfulfilled!" << endl;
    }
    cout << "The data type of score has: " << sizeof(score) << " bytes" << endl;

    getch();
    return 0;
}

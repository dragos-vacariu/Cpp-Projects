#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

bool isStringAPositiveNumber(string value);
unsigned int convertStringToNumber(string value);
int* addValueToArray (unsigned int value, int* source);
void printArray(int * arr);

int main(void)
{
    cout << "Enter Value: ";
    string inputVar = "";

        cin >> inputVar;
        if(isStringAPositiveNumber(inputVar))
        {
            unsigned int temp_value = convertStringToNumber(inputVar);
            cout << "Converted numeric value: " << temp_value << endl;
        }
    return 0;
}

bool isStringAPositiveNumber(string value)
{
    for(unsigned int i = 0; i < value.length(); i++)
    {
        if(value[i] < '0' || value[i] > '9')
        {
            cout << value[i] << endl;
            return false;
        }
    }
    return true;
}

unsigned int convertStringToNumber(string value)
{
    unsigned int numeric_value = 0;
    for(unsigned int i = 0; i < value.length(); i++)
    {
        numeric_value += (value[i] - 48);
        // in ASCII table 0 is 48

        if(i < value.length()-1)
        {
            numeric_value *= 10;
        }
    }
    return numeric_value;
}

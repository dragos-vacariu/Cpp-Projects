#include <iostream>
#include <conio.h>
#include <cstdint> // for int64_t, uint64_t which is equivalent to long long

using namespace std;
int main()
{
    unsigned long long ULongLongMax = 	18446744073709551615;
    long long LongLongMax = 9223372036854775807;
    long LongMax = LONG_MAX;
    unsigned long ULongMax = ULONG_MAX;
    int64_t int64Max = 9223372036854775807;
    int intMax = INT_MAX;
    unsigned int UintMax = UINT_MAX;
    short shortIntMax = SHRT_MAX;
    unsigned short UshortIntMax = USHRT_MAX;

    cout << "The maximum storage values for each data type: \n" << endl;

    cout << "Maximum value of unsigned long long: " << ULongLongMax << endl;
    cout << "Maximum value of long long: " << LongLongMax << endl;
    cout << "Maximum value of int64: " << int64Max << endl;
    cout << "Maximum value of unsigned long: " << ULongMax << endl;
    cout << "Maximum value of long: " << LongMax << endl;
    cout << "Maximum value of unsigned int: " << UintMax << endl;
    cout << "Maximum value of int: " << intMax << endl;
    cout << "Maximum value of unsigned short: " << UshortIntMax << endl;
    cout << "Maximum value of short: " << shortIntMax << endl;

    cout << "\nThe size for each data type: \n" << endl;
    cout << "Size of long long: " << sizeof(long long) << " bytes" << endl;
    cout << "Size of int64: " << sizeof(int64_t) << " bytes" << endl;
    cout << "Size of int32: " << sizeof(int32_t) << " bytes" << endl;
    cout << "Size of int16: " << sizeof(int16_t) << " bytes" << endl;
    cout << "Size of int8: " << sizeof(int8_t) << " bytes" << endl;
    cout << "Size of long: " << sizeof(long) << " bytes" << endl;
    cout << "Size of int: " << sizeof(int) << " bytes" << endl;
    cout << "Size of short: " << sizeof(short) << " bytes" << endl;
    cout << "Size of char: " << sizeof(char) << " bytes" << endl;
    getch();
    return 0;
}

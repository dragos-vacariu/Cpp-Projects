/*
Jewelry shop [Adobe]

Hacker have two strings, one is the types of stones that
are jewels and another one is the stones you have. You
want to know how many of the stones you have are also
jewels.

Let suppose J representing the types of stones that are
jewels, and S representing the stones you have.

The letters in J are guaranteed distinct, and all
characters in J and S are letters. Letters are case
sensitive, so "a" is considered a different type of stone
from "A".

Input format > The first line contains J and S, J is
denoting the types of stones that are jewels and S is
denoting the stones.

Output format > Print how many of the stones you have
are also jewels.

Constraints 1 <= S,J <= 50

Sample input: aA aAAbbb
Sample output: 3

Explanation

The J is "aA" -- a is present one time in S and A is present two
times in S.

Answer is 3.
*/

#include <iostream>

using namespace std;


string processStones (string value);
string countGetJewelries(string types, string value);

int main(void)
{
    string userInput;
    string type_of_stones_jewelry = "";
    string stones_owned = "";

    cout << "JEWELRY SHOP [ADOBE INTERVIEW]\nTwo strings (separated by SPACE) will be entered as input.\n\n"
           "FIRST STRING will be the types of stones considered jewelries.\n"
           "SECOND STRING will be the stones owned\n"
           "Output calculate the number of jewelries owned." << endl << endl;
    cout << "Enter the input: ";
    getline(cin, userInput);

    //Split input on SPACE and filter out non-letters
    for (unsigned int i=0; i<userInput.length(); i++)
    {
        if ( (tolower(userInput[i]) >= 'a' && tolower(userInput[i]) <= 'z') )
        {
            stones_owned += tolower(userInput[i]);
        }
        else if(userInput[i] == ' ')
        {
            type_of_stones_jewelry = stones_owned;
            stones_owned="";
        }
    }
    //Make sure Type of stones is built of Unique Chars
    type_of_stones_jewelry = processStones(type_of_stones_jewelry);

    //Printing the results:
    cout << "Type of stones: " << type_of_stones_jewelry << endl;
    cout << "Stones owned: " << stones_owned << endl;
    string jewelries = countGetJewelries(type_of_stones_jewelry, stones_owned);
    cout << endl << "You have: " << jewelries.length() << " of jewelries." << endl;
    cout << "Jewelries: " << jewelries << endl;

    cout << endl << "Press key to exit." << endl;
    cin >> userInput;
    return 0;
}

string processStones (string value)
{
    string temp = "";
    for(unsigned int i = 0 ; i<value.length(); i++)
    {
        bool isCharUnique = true;
        for(unsigned int j = 0; j<temp.length(); j++)
        {
            if( value[i] == temp[j] )
            {
                isCharUnique = false;
                break;
            }
        }
        if(isCharUnique)
        {
            temp += value[i];
        }
    }
    return temp;
}

string countGetJewelries(string types, string value)
{
    string no_of_jewelries = "";
    for(unsigned int i = 0; i < value.length(); i++)
    {
        for(unsigned int j = 0; j<types.length(); j++)
        {
            if( value[i] == types[j] )
            {
                no_of_jewelries+=value[i];
                break;
            }
        }
    }
    return no_of_jewelries;
}

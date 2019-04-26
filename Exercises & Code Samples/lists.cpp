#include <iostream>
#include <list>
#include <string>
#include <conio.h>

/*
A list is a data type that is similar to a vector, having dynamic size. Unlike the vectors, lists are slower to access, and
iterate through, and the elements of the list are indexed through a pointer, that connects each and every element of the
list.
*/

using namespace std;
int main()
{
    list <string> mylist;
    mylist.push_back("FirstElement"); //put an element at the end of the list
    mylist.push_front("SecondElement"); //put an element at the front/beginning of the list;
    mylist.push_back("ThirdElement");
    mylist.push_back("ThirdElement");
    mylist.push_back("FourthElement");
    mylist.push_back("FourthElement");

    //Creating an iterator to loop through the list:
    list <string>::iterator it;

    for(it=mylist.begin(); it!=mylist.end(); it++)
    {
        cout << *it << endl; //printing the elements of the list to the screen.
    }

    cout << endl << endl;

    //This will remove all appearances of "ThirdElement" in  the list.
    mylist.remove("ThirdElement"); //function that removes an element/value by appearance (if the element/value is appearing
    //twice in the list, it will be deleted both).

    for(it=mylist.begin(); it!=mylist.end(); it++)
    {
       if(*it=="FourthElement")
       {
           it=mylist.erase(it); //using the erase function;
           /*
           .erase() function is similar to .remove(), but erase can only delete one appearance at a time, while remove
           can delete all of them.
           */
            break;
       }
    }

    //Printing the results;
    for(it=mylist.begin(); it!=mylist.end(); it++)
    {
        cout << *it << endl; //printing the elements of the list to the screen.
    }

    getch();
    return 0;
}

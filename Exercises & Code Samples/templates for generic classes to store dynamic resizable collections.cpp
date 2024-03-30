#include <iostream>

using namespace std;

//class with generic members
template <class generic_type>
class Collection
{
    unsigned int current_Size;
    generic_type* data;

    public: Collection()
    {
        // this keyword is not allowed when using templates / generic types
        current_Size = 0;
    }
    public: void Add(generic_type element)
    {

        generic_type* data_new = new generic_type[current_Size+1];
        for (unsigned i=0; i<current_Size; i++)
        {
            data_new[i] = data[i];
        }
        current_Size++;
        data_new[current_Size-1] = element;
        delete data;
        data = data_new;
    }
    public: void printAll()
    {
        for (unsigned int i = 0 ; i < current_Size; i++)
        {
            cout << data[i] << endl;
        }
    }
    public: unsigned int length()
    {
        return current_Size;
    }

};

int main(void)
{
        int userInput;
        Collection<int> numeric_Collection;
        for(unsigned i=0; i<5; i++)
        {
            cout << "element[" << i << "] = ";
            cin >> userInput;
            numeric_Collection.Add(userInput);

        }
        cout << "Length: " << numeric_Collection.length() << endl;
        numeric_Collection.printAll();
        return 0;
}

#include "vectors_of_objects_class.h"

void createObjects(vector <vectors_of_objects_class>&); //declaring the function
void printObjectsInfo(const vector<vectors_of_objects_class>&); //declaring the function

int main()
{
    vector <vectors_of_objects_class> ObjectVector; //creating a vector of objects;
    createObjects(ObjectVector); //calling the function;
    printObjectsInfo(ObjectVector); //calling the function;
    return 0;
}

void createObjects(vector<vectors_of_objects_class>& newObjVec) //defining the function
{
    int age;
    string name;
    cout << "How many people do you wish to add? ";
    int people;
    cin >> people;
    for(int i=0;i<people;i++)
    {
        cout << "People_" << i << " Name: ";
        cin >> name; //get the name from the keyboard
        cout << "People_" << i << " Age: ";
        cin >> age; //get the age from the keyboard
        vectors_of_objects_class ObjectInVector(name, age); //creating the object with self made constructor
        ObjectInVector.setAge(age); //calling the class function
        ObjectInVector.setName(name); //calling the class function
        newObjVec.push_back(ObjectInVector); //put the object into the vector;
    }
    cout << endl;
}
void printObjectsInfo(const vector<vectors_of_objects_class>& newObjVec) //defining the function
{
    unsigned int sizeOfVector=newObjVec.size();
    for(int i=0;i<sizeOfVector; i++)
    {
        cout << "People_" << i << " Name: " << newObjVec[i].getName() << endl;
        cout << "People_" << i << " Age: " <<newObjVec[i].getAge() << endl;
    }
}

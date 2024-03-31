#include <fstream>
#include <iostream>
#include <conio.h>

using namespace std;

int AppendToFile(string text);
int RefreshFile();
int main()
{
    string message;
    cout << "Enter your text (press Q to end or write in \"command\" to refresh the file): " << endl;
    while(1)
    {
        getline(cin, message);
        if(message=="Q" || message=="q")
        {
            break;
        }
        if(message=="\n") //if only the Enter key has been pressed
        {
            continue; //skip the current iteration, ignoring the statements below;
        }
        if(message=="command")
        {
            RefreshFile();
        }
        else
        {
            AppendToFile(message);
        }
    }
    getch();
    return 0;
}

int AppendToFile(string text)
{
    ofstream file("WriteToFile.txt", ios_base::app);
    if(file.fail())
    {
        perror("WriteToFile.txt");
        return -1;
    }
    file << text << "\n";
    file.close();
}
int RefreshFile()
{
    ofstream file("WriteToFile.txt");
    if(file.fail())
    {
        perror("WriteToFile.txt");
        return -1;
    }
    file.close();
}

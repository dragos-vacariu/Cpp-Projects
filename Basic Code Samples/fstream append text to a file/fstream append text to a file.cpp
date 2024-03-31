#include <iostream>
#include <fstream>
#include <conio.h>

int appendToFile(std::string filename);

int main()
{
    std::string message;
    getline(std::cin, message);
    appendToFile(message);
    getch();
    return 0;
}

int appendToFile(std::string text)
{
    std::ofstream file("appendToFile.txt", std::ios_base::app);
    if(file.fail())
    {
        perror("appendToFile.txt");
        return 0;
    }
    file << text << "\n";
}

#include <iostream>
#include <conio.h>

using namespace std;
int main(int args, char** argv)
{
    int n, m;
    cout << "Enter the number of rows you want for the matrix: ";
    cin >> n;
    cout << "Enter the number of columns you want for the matrix: ";
    cin >> m;
    int matrix[n+1][m]={0}; //matrix initialized to 0;
    //Reading the matrix from the keyboard and calculates the sum;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cout << "Enter the value of matrix[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
            matrix[n][j]+=matrix[i][j]; // n is the row reserver for the sum of all the elements from the same columns above
            //even if matrix has the dimension n+1, its rows goes actually until n because the starting point is at 0;
        }
    }
    //Printing the matrix to the screen;
    for (int i=0;i<n+1;i++)
    {
        cout << "[";
        for (int j=0;j<m;j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "]" << endl;
    }
    getch();
    return 0;
}

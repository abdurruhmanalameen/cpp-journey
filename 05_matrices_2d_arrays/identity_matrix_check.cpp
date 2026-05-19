#include <iostream>
#include <cstdio>
#include "include/myLibrary.h"
using namespace std;

void printMatrix(int matrix[3][3], int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%0*d\t", 2, matrix[i][j]);
        }
        cout << "\n";
    }
    cout << "\n";
}
bool isIdentity(int arr[3][3], int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (i == j)
            {
                if (arr[i][j] != 1)
                {
                    return false;
                }
            }
            else
            {
                if (arr[i][j] != 0)
                {
                    return false;
                }
            }
        }
    }
    return true;
}
void printIdentityOrNot(bool identity)
{
    if (identity)
    {
        cout << "\nThe array is identity!\n";
    }
    else
    {
        cout << "\nThe array is not identity!\n";
    }
}
int main()
{
    int arr[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}};

    printMatrix(arr, 3, 3);

    printIdentityOrNot(isIdentity(arr, 3, 3));

    return 0;
}
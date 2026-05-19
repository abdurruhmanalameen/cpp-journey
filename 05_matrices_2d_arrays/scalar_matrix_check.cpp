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
bool isScalar(int arr[3][3], int rows, int columns)
{
    int index = arr[0][0];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (i == j)
            {
                if (arr[i][j] != index)
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
void printScalarOrNot(bool isScalar)
{
    if (isScalar)
    {
        cout << "\nThe array is scalar!\n";
    }
    else
    {
        cout << "\nThe array is not scalar!\n";
    }
}
int main()
{
    int arr[3][3] =
        {
            {9, 0, 0},
            {0, 9, 0},
            {0, 0, 9}};

    printMatrix(arr, 3, 3);

    printScalarOrNot(isScalar(arr, 3, 3));

    return 0;
}
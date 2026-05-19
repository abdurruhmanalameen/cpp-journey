#include <iostream>
#include <cstdio>
#include "include/myLibrary.h"
using namespace std;

void fillMatrixWithRandomNums(int matrix[3][3], int rows, int columns)
{

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            matrix[i][j] = randomNumber(1, 10);
        }
    }
}
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

bool isTypicalMatrixes(int arr1[3][3], int arr2[3][3], int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (arr1[i][j] != arr2[i][j])
            {
                return false;
            }
        }
    }
    return true;
}
void printTypicalOrNot(bool typicalOrNot)
{
    if (typicalOrNot)
    {
        cout << "\nThe arrays are typical!\n";
    }
    else
    {
        cout << "\nThe arrays aren't typical!\n";
    }
}
int main()
{
    int arr1[3][3];
    int arr2[3][3];

    srand(time(unsigned(NULL)));

    fillMatrixWithRandomNums(arr1, 3, 3);
    cout << "Array[1]:\n";
    printMatrix(arr1, 3, 3);

    fillMatrixWithRandomNums(arr2, 3, 3);
    cout << "Array[2]:\n";
    printMatrix(arr2, 3, 3);

    printTypicalOrNot(isTypicalMatrixes(arr1, arr2, 3, 3));
    return 0;
}
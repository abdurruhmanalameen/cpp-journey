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
int sumOfMatrix(int arr[3][3], int rows, int columns)
{
    int sum = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            sum += arr[i][j];
        }
    }

    return sum;
}
void checkEqualityMatrixes(int arr1[3][3], int arr2[3][3], int rows, int columns)
{
    if (sumOfMatrix(arr1, rows, columns) == sumOfMatrix(arr2, rows, columns))
    {
        cout << "The arrays are equal!\n";
    }
    else
    {
        cout << "The arrays are not equal!\n";
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

    checkEqualityMatrixes(arr1, arr2, 3, 3);
    return 0;
}
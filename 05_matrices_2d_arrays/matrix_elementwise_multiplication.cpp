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
void multiplyTwoArr(int arr1[3][3], int arr2[3][3], int multipliedArr[3][3], int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            multipliedArr[i][j] = arr1[i][j] * arr2[i][j];
        }
    }
}

int main()
{
    int arr1[3][3];
    int arr2[3][3];
    int multipliedArr[3][3];

    srand(time(unsigned(NULL)));

    fillMatrixWithRandomNums(arr1, 3, 3);
    cout << "Array[1]:\n";
    printMatrix(arr1, 3, 3);

    fillMatrixWithRandomNums(arr2, 3, 3);
    cout << "\nArray[2]:\n";
    printMatrix(arr2, 3, 3);

    multiplyTwoArr(arr1, arr2, multipliedArr, 3, 3);
    cout << "\nThe multiplied array:\n";
    printMatrix(multipliedArr, 3, 3);

    return 0;
}
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

void printMiddleRow(int matrix[3][3], int rows, int columns)
{
    int middle = rows / 2;
    for (int i = 0; i < columns; i++)
    {
        printf("%0*d\t", 2, matrix[middle][i]);
    }
    cout << "\n";
}
void printMiddleColumn(int matrix[3][3], int rows, int columns)
{
    int middle = columns / 2;
    for (int i = 0; i < rows; i++)
    {
        printf("%0*d\t", 2, matrix[i][middle]);
    }
    cout << "\n";
}

int main()
{
    int arr[3][3];

    srand(time(unsigned(NULL)));

    fillMatrixWithRandomNums(arr, 3, 3);
    cout << "Array:\n";
    printMatrix(arr, 3, 3);

    cout << "Middle row of matrix is:\n";
    printMiddleRow(arr, 3, 3);

    cout << "Middle column of matrix is:\n";
    printMiddleColumn(arr, 3, 3);

    return 0;
}